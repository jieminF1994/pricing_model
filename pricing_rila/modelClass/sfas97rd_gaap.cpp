
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
#include "ModelClass\sfas97rd_gaap_udf.h"
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
#include "ModelClass\mtg_asset.h"
#include "ModelClass\mtg_cf_asset.h"
#include "ModelClass\rates_economy.h"
#include "ModelClass\seg_comp.h"
#include "ModelClass\sfas133_gaap.h"
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

deptaskinput sop031_valn_input;
deptaskcols sop031_valn_input_cols;
deptaskmap sop031_valn_input_pos;
deptaskmapiter sop031_valn_input_pos_iter;
deptaskinput sfas97rd_valn_input;
deptaskcols sfas97rd_valn_input_cols;
deptaskmap sfas97rd_valn_input_pos;
deptaskmapiter sfas97rd_valn_input_pos_iter;
sowfoutput sfas97rd_state_of_world_financial_output;
sowfinput sfas97rd_state_of_world_financial_input;
sowfcols sfas97rd_state_of_world_financial_cols;
sowfmap sfas97rd_state_of_world_financial_input_pos;
sowfmapiter sfas97rd_state_of_world_financial_input_pos_iter;
const int ASSESS_SOP = 0;
const int DB_BEN_SOP = 1;
const int IB_BEN_SOP = 2;
const int WB_BEN_SOP = 3;
const int SG_BEN_SOP = 4;
const int DTH_CLAIM_COST = 5;
const int SOP_SIZE = 6;
const int EGP = 0;
const int INT_RATE = 1;
const int SOP031_PBR_FV = 2;
const int SOP031_PBR = 3;
const int DAC_ACQ_EXP = 4;
const int DAC_ACQ_EXP_LOSS_REC = 5;
const int DAC_COMM = 6;
const int DAC_COMM_LOSS_REC = 7;
const int DAC_PREM_BONUS = 8;
const int DAC_PREM_BONUS_LOSS_REC = 9;
const int DAC_REINS_YRT_ASSET = 10;
const int EMBED_DERIV_VAL = 11;
const int K_CAPZD_ACQ_EXP = 12;
const int K_CAPZD_COMM = 13;
const int K_CAPZD_PREM_BONUS = 14;
const int K_REINS_YRT_COST = 15;
const int K_SOP031_GMDB_BEN_BR = 16;
const int K_SOP031_PBR = 17;
const int K_SOP031_ULSG_BEN_BR = 18;
const int K_SOP031_UNEARN_REV_LIAB = 19;
const int K_UNEARN_REV_LIAB = 20;
const int SOP031_GMDB_BR = 21;
const int SOP031_GMIB_BR = 22;
const int SOP031_GMWB_BR = 23;
const int SOP031_PBR_LIAB = 24;
const int SOP031_ULSG_BR = 25;
const int UNEARN_REV_LIAB = 26;
const int GAAP_SCHEDULE_SIZE = 27;

#if defined(__VA_LIAB_H_)
// integers from VA_POL submodel
extern int AV_B_GA;
extern int AV_B_DCA;
#endif//WTW - Gen2 - cannot have IF/ELSE in EXTERN section

/*#else //WTW - Gen2 - Move outside of EXTERNS
// integers from VA_POL submodel
int AV_B_DCA = 0;
int AV_B_GA = 1;
#endif*/


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
#ifndef sfas97rd_gaap_TableDefs
#define sfas97rd_gaap_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection SFAS97RD_GAAP::TTHC;
void SFAS97RD_GAAP::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - acq_exp
// Acquisition Expenses                                                                                             
// Column:ACQ_EXP
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_acq_exp(int t) {
//^^^



//^^^

#line 1 "acq_exp.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("acq_exp", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return ul->acq_exp(t);
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return vul->acq_exp(t);
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return iul->acq_exp(t);
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->acq_exp(t);
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fa->acq_exp(t);
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fia->acq_exp(t);
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - agp
// Actual Gross Profits                                                                                             
// Column:AGP
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_agp(int t) {
//^^^



//^^^

#line 1 "agp.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t <= start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

return max(0.0, egp_gain_exp(t)
	            + egp_gain_inv(t)
	            + egp_gain_mort(t)
	            + egp_gain_surr(t)
	            + egp_gain_persist_bon_ref(t)
                - hedge_cost(t)
	            - sfas133_liab_incr(t)
	            - sop031_addl_liab_incr(t));

}


//@@ END

//@@ START - amortzn_int_rate
// Amortization Interest Rate                                                                                             
// Column:AMORTZN_INT_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_amortzn_int_rate(int t) {
//^^^



//^^^

#line 1 "amortzn_int_rate.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (loss_recognition_flag)
	return loss_rec_amortzn_int_rate(t);

return gaap_amortzn_int_rate(t);

}


//@@ END

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_cal_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(4,"cal_mth",t);
}



//^^^

#line 1 "cal_mth.SFAS97RD_GAAP.for"
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
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_cal_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(5,"cal_yr",t);
}



//^^^

#line 1 "cal_yr.SFAS97RD_GAAP.for"
if (t == start_period)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}


//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_cal_yr_relative(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(6,"cal_yr_relative",t);
}



//^^^

#line 1 "cal_yr_relative.SFAS97RD_GAAP.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - cap_gain
// Capital Gain                                                                                             
// Column:CAP_GAIN
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_cap_gain(int t) {
//^^^



//^^^

#line 1 "cap_gain.SFAS97RD_GAAP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	{
	if (!reins_flag)
		{
		if (fabs(seg->gaap_liab_net(t - 1)) < aggregate_amount_threshold)
			return NO_AVG;

		return (seg->gaap_cap_gain_res(t)
				+ seg->gaap_cap_gain_cap(t))
				* liab_net(t - 1) / seg->gaap_liab_net(t - 1);
		}
	else if (reins_flag)
		{
		if (fabs(seg->reins_gaap_liab_net(t - 1)) < aggregate_amount_threshold)
			return NO_AVG;

		return seg->reins_gaap_cap_gain_res(t)
			   * liab_net(t - 1) / seg->reins_gaap_liab_net(t - 1);
		}
	}

return NO_AVG;

}


//@@ END

//@@ START - cap_gain_fund
// Capital Gain on Fund                                                                                             
// Column:CAP_GAIN_FUND
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_cap_gain_fund(int t) {
//^^^



//^^^

#line 1 "cap_gain_fund.SFAS97RD_GAAP.for"
if (!alm_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("cap_gain_fund", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (alm_flag)
		{
		double reins_pct = 0.0;
		double fund_val_bef_int = 0.0;
		
		if (!reins_flag) //Gross
			reins_pct = 1.0;
		else if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured via Coinsurance
			reins_pct = ul->reins_pct;
		
		fund_val_bef_int = max(0.0, ul->sm_ul_ifund_curr->fund_val_bef_int(t));
		
		return fund_val_bef_int
	       	   * ul->units_inf(t - 1)
			   * reins_pct
			   * (pow(1.0 + ul->seg->eff_cap_gains_rate(t), 1.0 / 12.0) - 1.0);
		}
	else 
		return NO_AVG;
	}	
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (alm_flag)
		{
		double reins_pct = 0.0;
		double fund_val_bef_int = 0.0;
		
		if (!reins_flag) //Gross
			reins_pct = 1.0;
		else if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured via Coinsurance
			reins_pct = vul->reins_pct;

		fund_val_bef_int = max(0.0, vul->sum_over_funds("av_bef_int", t, GENERAL)
		                            + vul->sum_over_funds("av_bef_int", t, DCA));
		
		return fund_val_bef_int
	       	   * vul->units_inf(t - 1)
			   * reins_pct
			   * (pow(1.0 + vul->seg->eff_cap_gains_rate(t), 1.0 / 12.0) - 1.0);
		}
	else 
		return NO_AVG;
	}	
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (alm_flag)
		{
		double reins_pct = 0.0;
		double fund_val_bef_int = 0.0;
		
		if (!reins_flag) //Gross
			reins_pct = 1.0;
		else if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured via Coinsurance
			reins_pct = iul->reins_pct;
		
		fund_val_bef_int = max(0.0, iul->sm_iul_ifund_curr->fund_val_bef_int(t));
		
		return fund_val_bef_int
	       	   * iul->units_inf(t - 1)
			   * reins_pct
			   * (pow(1.0 + iul->seg->eff_cap_gains_rate(t), 1.0 / 12.0) - 1.0);
		}
	else 
		return NO_AVG;
	}	
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (alm_flag)
		{
		double reins_pct = 0.0;
		
		if (!reins_flag) //Gross
			reins_pct = 1.0;
		else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance
			reins_pct = va->reins_pct;
			
		// ensure order of processing by calling mp_processed
		va->mp_processed(t);

		double av_b = (va->sm_va_pol->av_b_ga(t)
		               + va->sm_va_pol->av_b_dca(t))
					   * va->policies_b(t);

		return max(0.0, av_b)
			   * reins_pct
			   * (pow(1.0 + va->seg->eff_cap_gains_rate(t), 1.0 / 12.0) - 1.0);
		}		
	else 
		return NO_AVG;
	}				
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (alm_flag)
		{
		double reins_pct = 0.0;
		
		if (!reins_flag) //Gross
			reins_pct = 1.0;
		else if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance
			reins_pct = fa->reins_pct;
			
		return max(0.0, fa->fund_val_b(t))
			   * reins_pct
			   * (pow(1.0 + fa->seg->eff_cap_gains_rate(t), 1.0 / 12.0) - 1.0);
		}		
	else 
		return NO_AVG;
	}				
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (alm_flag)
		{
		double reins_pct = 0.0;
		
		if (!reins_flag) //Gross
			reins_pct = 1.0;
		else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance
			reins_pct = fia->reins_pct;
			
		return max(0.0, fia->fund_val_b(t))
			   * reins_pct
			   * (pow(1.0 + fia->seg->eff_cap_gains_rate(t), 1.0 / 12.0) - 1.0);
		}		
	else 
		return NO_AVG;
	}				
#endif

return NO_AVG;

}


//@@ END

//@@ START - capzd_acq_exp
// Capitalized Acquisition Expenses                                                                                             
// Column:CAPZD_ACQ_EXP
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "capzd_acq_exp.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	{
	//force call for reports
	acq_exp(t);

	// No deferrals after stated amortizaton period
	if (!valn_flag && t > amortzn_period)
		return 0.0;
	
	return sum_over_gaap("capzd_acq_exp", t);
	}

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (t != ul->commencement_period + 1)
		return NO_AVG;
		
	double capzd_acq_exp = 0.0;
	double adj_mult = ul->exp_adj_mult;
	double units_issued = ul->units_issued(t);
	double acq_exp_per_pol = 0.0;
	double acq_exp_per_unit = 0.0;
	double acq_exp_pct_tgt_prem = 0.0;
	double acq_exp_pct_annualzd_prem_fy = 0.0;

	acq_exp_per_pol
	= ul->acq_exp_per_pol
  	* ul->infl_cumul(t - 1)
  	* ul->policies_issued(t)
  	* adj_mult;

	acq_exp_per_unit
	= ul->acq_exp_per_unit
	* ul->infl_cumul(t - 1)
	* units_issued
	* adj_mult;

	acq_exp_pct_tgt_prem
	= min(ul->sm_ul_py->gross_prem(1), ul->sm_ul_py->tgt_prem(1))
	* ul->acq_exp_pct_tgt_prem
	* units_issued
	* adj_mult;

	acq_exp_pct_annualzd_prem_fy
	= (ul->sm_ul_py->gross_prem(1) + ul->single_prem_at_issue_per_unit)
  	* ul->acq_exp_pct_annualzd_prem_fy
  	* units_issued
  	* adj_mult;	

	capzd_acq_exp 
	= acq_exp_per_pol * ul->capzd_acq_exp_pct_per_pol
	  + acq_exp_per_unit * ul->capzd_acq_exp_pct_per_unit
	  + (acq_exp_pct_tgt_prem + acq_exp_pct_annualzd_prem_fy)
		* ul->capzd_acq_exp_pct_pct_prem;		

	if (!reins_flag) //Gross
		return capzd_acq_exp;
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (t != vul->commencement_period + 1)
		return NO_AVG;
		
	double capzd_acq_exp = 0.0;
	double adj_mult = vul->exp_adj_mult;
	double units_issued = vul->units_issued(t);
	double acq_exp_per_pol = 0.0;
	double acq_exp_per_unit = 0.0;
	double acq_exp_pct_tgt_prem = 0.0;
	double acq_exp_pct_annualzd_prem_fy = 0.0;

	acq_exp_per_pol
	= vul->acq_exp_per_pol
  	* vul->infl_cumul(t - 1)
  	* vul->policies_issued(t)
  	* adj_mult;

	acq_exp_per_unit
	= vul->acq_exp_per_unit
	* vul->infl_cumul(t - 1)
	* units_issued
	* adj_mult;

	acq_exp_pct_tgt_prem
	= min(vul->sm_vul_py->gross_prem(1), vul->sm_vul_py->tgt_prem(1))
	* vul->acq_exp_pct_tgt_prem
	* units_issued
	* adj_mult;

	acq_exp_pct_annualzd_prem_fy
	= (vul->sm_vul_py->gross_prem(1) + vul->single_prem_at_issue_per_unit)
  	* vul->acq_exp_pct_annualzd_prem_fy
  	* units_issued
  	* adj_mult;	

	capzd_acq_exp 
	= acq_exp_per_pol * vul->capzd_acq_exp_pct_per_pol
	  + acq_exp_per_unit * vul->capzd_acq_exp_pct_per_unit
	  + (acq_exp_pct_tgt_prem + acq_exp_pct_annualzd_prem_fy)
		* vul->capzd_acq_exp_pct_pct_prem;		

	if (!reins_flag) //Gross
		return capzd_acq_exp;
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (t != iul->commencement_period + 1)
		return NO_AVG;
		
	double capzd_acq_exp = 0.0;
	double adj_mult = iul->exp_adj_mult;
	double units_issued = iul->units_issued(t);
	double acq_exp_per_pol = 0.0;
	double acq_exp_per_unit = 0.0;
	double acq_exp_pct_tgt_prem = 0.0;
	double acq_exp_pct_annualzd_prem_fy = 0.0;

	acq_exp_per_pol
	= iul->acq_exp_per_pol
  	* iul->infl_cumul(t - 1)
  	* iul->policies_issued(t)
  	* adj_mult;

	acq_exp_per_unit
	= iul->acq_exp_per_unit
	* iul->infl_cumul(t - 1)
	* units_issued
	* adj_mult;

	acq_exp_pct_tgt_prem
	= min(iul->sm_iul_py->gross_prem(1), iul->sm_iul_py->tgt_prem(1))
	* iul->acq_exp_pct_tgt_prem
	* units_issued
	* adj_mult;

	acq_exp_pct_annualzd_prem_fy
	= (iul->sm_iul_py->gross_prem(1) + iul->single_prem_at_issue_per_unit)
  	* iul->acq_exp_pct_annualzd_prem_fy
  	* units_issued
  	* adj_mult;	

	capzd_acq_exp 
	= acq_exp_per_pol * iul->capzd_acq_exp_pct_per_pol
	  + acq_exp_per_unit * iul->capzd_acq_exp_pct_per_unit
	  + (acq_exp_pct_tgt_prem + acq_exp_pct_annualzd_prem_fy)
		* iul->capzd_acq_exp_pct_pct_prem;		

	if (!reins_flag) //Gross
		return capzd_acq_exp;
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif
	
#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{	
	if (xint(va->pol_yr(t)) > 1)
		return NO_AVG;
	
	double capzd_acq_exp = 0.0;
	double adj_mult = va->exp_adj_mult;
	double acq_exp_per_pol = 0.0;
	double acq_exp_pct_prem = 0.0;
			
	if (va->elapsed_mths <= 0 && t == va->commencement_period + 1)
		acq_exp_per_pol
		= va->acq_exp_per_pol 
	  	* va->infl_cumul(t - 1)
	  	* va->policies_b(t)
	  	* adj_mult;

	acq_exp_pct_prem
    = va->acq_exp_pct_prem
      * va->prem_paid(t)
      * adj_mult;
		
	capzd_acq_exp 
	= acq_exp_per_pol 
	  * va->capzd_acq_exp_pct_per_pol
	  + acq_exp_pct_prem 
	    * va->capzd_acq_exp_pct_pct_prem;

	if (!reins_flag) //Gross
		return capzd_acq_exp;
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (fa->elapsed_mths > 0)
		return NO_AVG;
	
	double capzd_acq_exp = 0.0;
	
	if (t == fa->commencement_period + 1)
		{
		double single_prem = fa->single_prem;
		double adj_mult = fa->exp_adj_mult;
		double acq_exp_per_pol = 0.0;
		double acq_exp_pct_prem = 0.0;

		if (fa->prem_term_mp == 1 && fa->prem_mode == ANNUAL)
			single_prem
			+= fa->init_annualzd_prem / fa->init_policies;

		acq_exp_per_pol
		= fa->acq_exp_per_pol 
	  	* fa->infl_cumul(t - 1)
	  	* fa->policies_b(t)
	  	* adj_mult;

		acq_exp_pct_prem
    	= fa->acq_exp_pct_prem
      	* (fa->gross_prem_annualzd_b(t) + single_prem)
      	* adj_mult;

		capzd_acq_exp 
		= acq_exp_per_pol 
		  * fa->capzd_acq_exp_pct_per_pol
		  + acq_exp_pct_prem 
		    * fa->capzd_acq_exp_pct_pct_prem;
		}

	if (!reins_flag) //Gross
		return capzd_acq_exp;
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (fia->elapsed_mths > 0)
		return NO_AVG;
	
	double capzd_acq_exp = 0.0;
	
	if (t == fia->commencement_period + 1)
		{
		double adj_mult = fia->exp_adj_mult;
		double acq_exp_per_pol = 0.0;
		double acq_exp_pct_prem = 0.0;

		acq_exp_per_pol
		= fia->acq_exp_per_pol 
	  	* fia->infl_cumul(t - 1)
	  	* fia->policies_b(t)
	  	* adj_mult;

		acq_exp_pct_prem
    	= fia->acq_exp_pct_prem
      	* fia->single_prem
      	* adj_mult;

		capzd_acq_exp 
		= acq_exp_per_pol 
		  * fia->capzd_acq_exp_pct_per_pol
		  + acq_exp_pct_prem 
		    * fia->capzd_acq_exp_pct_pct_prem;
		}

	if (!reins_flag) //Gross
		return capzd_acq_exp;
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - capzd_acq_exp_accum
// Capitalized Acquisition Expenses Accumulation                                                                                             
// Column:CAPZD_ACQ_EXP_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_acq_exp_accum(int t) {
//^^^



//^^^

#line 1 "capzd_acq_exp_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double def_acq_exp_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double def_acq_exp = cohort_history_capzd_acq_exp/*.AtTime(tt)*/;
				
				def_acq_exp_accum 
				= (def_acq_exp_accum + def_acq_exp) * (1.0 + gaap_int_rate_mthly);
				}

			return def_acq_exp_accum; 
			}
		else //  No History for cell pricing at issue period
			return 0.0;	
		}
	else //valn_period != 0
		return init_capzd_acq_exp_accum;
	}

return (capzd_acq_exp_accum(t - 1)
	     + capzd_acq_exp(t))
	   * (1.0 + gaap_amortzn_int_rate(t));

}


//@@ END

//@@ START - capzd_acq_exp_accum_loss_rec_int_rate
// Capitalized Acquisition Expenses Accumulation At Loss Recognition Interest Rate                                                                                             
// Column:CAPZD_ACQ_EXP_ACCUM_LOSS_REC_INT_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_acq_exp_accum_loss_rec_int_rate(int t) {
//^^^



//^^^

#line 1 "capzd_acq_exp_accum_loss_rec_int_rate.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double def_acq_exp_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double def_acq_exp = cohort_history_capzd_acq_exp/*.AtTime(tt)*/;
				
				def_acq_exp_accum 
				= (def_acq_exp_accum + def_acq_exp) * (1.0 + loss_rec_int_rate_mthly);
				}

			return def_acq_exp_accum; 
			}
		else //  No History for cell pricing at issue period
			return 0.0;	
		}
	else //valn_period != 0
		return init_capzd_acq_exp_accum_loss_rec_int_rate;
	}

return (capzd_acq_exp_accum_loss_rec_int_rate(t - 1)
	     + capzd_acq_exp(t))
	   * (1.0 + loss_rec_amortzn_int_rate(t));

}


//@@ END

//@@ START - capzd_acq_exp_pv
// Capitalized Acquisition Expenses Present Value                                                                                             
// Column:CAPZD_ACQ_EXP_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_acq_exp_pv(int t) {
//^^^



//^^^

#line 1 "capzd_acq_exp_pv.SFAS97RD_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

return capzd_acq_exp(t + 1)
	   + (capzd_acq_exp_pv(t + 1)
		  / (1.0 + gaap_amortzn_int_rate(t + 1)));

}


//@@ END

//@@ START - capzd_acq_exp_pv_loss_rec_int_rate
// Capitalized Acquisition Expenses Present Value At Loss Recognition Interest Rate                                                                                             
// Column:CAPZD_ACQ_EXP_PV_LOSS_REC_INT_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_acq_exp_pv_loss_rec_int_rate(int t) {
//^^^



//^^^

#line 1 "capzd_acq_exp_pv_loss_rec_int_rate.SFAS97RD_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

return capzd_acq_exp(t + 1)
	   + (capzd_acq_exp_pv_loss_rec_int_rate(t + 1)
		  / (1.0 + loss_rec_amortzn_int_rate(t + 1)));

}


//@@ END

//@@ START - capzd_comm_accum
// Capitalized Commissions Accumulation                                                                                             
// Column:CAPZD_COMM_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_accum(int t) {
//^^^



//^^^

#line 1 "capzd_comm_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double def_comm_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double def_comm_bom = cohort_history_capzd_comm_bom/*.AtTime(tt)*/;
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double def_comm_eom = cohort_history_capzd_comm_eom/*.AtTime(tt)*/;								
				
				def_comm_accum 
				= (def_comm_accum + def_comm_bom)
				  * (1.0 + gaap_int_rate_mthly) 
				  + def_comm_eom;
				}
							
			return def_comm_accum; 
			}
		else //  No History for cell pricing at issue period
			return 0.0;
		}		
	else //valn_period != 0
		return init_capzd_comm_accum;	
	}
	
return (capzd_comm_accum(t - 1) 
        + capzd_comm_bom(t))
	   * (1.0 + gaap_amortzn_int_rate(t))
	   + capzd_comm_eom(t);

}


//@@ END

//@@ START - capzd_comm_accum_loss_rec_int_rate
// Capitalized Commissions Accumulation At Loss Recognition Interest Rate                                                                                             
// Column:CAPZD_COMM_ACCUM_LOSS_REC_INT_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_accum_loss_rec_int_rate(int t) {
//^^^



//^^^

#line 1 "capzd_comm_accum_loss_rec_int_rate.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double def_comm_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double def_comm_bom = cohort_history_capzd_comm_bom/*.AtTime(tt)*/;
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double def_comm_eom = cohort_history_capzd_comm_eom/*.AtTime(tt)*/;								
				
				def_comm_accum 
				= (def_comm_accum + def_comm_bom)
				  * (1.0 + loss_rec_int_rate_mthly) 
				  + def_comm_eom;
				}
							
			return def_comm_accum; 
			}
		else //  No History for cell pricing at issue period
			return 0.0;
		}		
	else //valn_period != 0
		return init_capzd_comm_accum_loss_rec_int_rate;	
	}
	
return (capzd_comm_accum(t - 1) 
        + capzd_comm_bom(t))
	   * (1.0 + loss_rec_amortzn_int_rate(t))
	   + capzd_comm_eom(t);

}


//@@ END

//@@ START - capzd_comm_bom
// Capitalized Commissions BOM                                                                                             
// Column:CAPZD_COMM_BOM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_bom(int t) {
//^^^



//^^^

#line 1 "capzd_comm_bom.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (!valn_flag && t > amortzn_period)
		return 0.0;

	return sum_over_gaap("capzd_comm_bom", t);
	}
		
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (ul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_excess_bom(t);
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (vul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_excess_bom(t);
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (iul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_excess_bom(t);
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (va->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_excess_bom(t);
	}
#endif	
	
#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (fa->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_excess_bom(t);
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (fia->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_excess_bom(t);
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - capzd_comm_chargeback
// Capitalized Commissions Chargeback                                                                                             
// Column:CAPZD_COMM_CHARGEBACK
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "capzd_comm_chargeback.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (!valn_flag && t > amortzn_period)
		return 0.0;

	return sum_over_gaap("capzd_comm_chargeback", t);
	}

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (ul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_chargeback(t);
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (vul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_chargeback(t);
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (iul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_chargeback(t);
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (va->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_chargeback(t);
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (fa->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_chargeback(t);
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (fia->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_chargeback(t);
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - capzd_comm_eom
// Capitalized Commissions EOM                                                                                             
// Column:CAPZD_COMM_EOM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_eom(int t) {
//^^^



//^^^

#line 1 "capzd_comm_eom.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return -capzd_comm_chargeback(t);

}


//@@ END

//@@ START - capzd_comm_pv
// Capitalized Commissions Present Value                                                                                             
// Column:CAPZD_COMM_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_pv(int t) {
//^^^



//^^^

#line 1 "capzd_comm_pv.SFAS97RD_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

return capzd_comm_bom(t + 1)
	   + ((capzd_comm_pv(t + 1) + capzd_comm_eom(t + 1))
	      / (1.0 + gaap_amortzn_int_rate(t + 1)));

}


//@@ END

//@@ START - capzd_comm_pv_loss_rec_int_rate
// Capitalized Commissions Present Value At Loss Recognition Interest Rate                                                                                             
// Column:CAPZD_COMM_PV_LOSS_REC_INT_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_pv_loss_rec_int_rate(int t) {
//^^^



//^^^

#line 1 "capzd_comm_pv_loss_rec_int_rate.SFAS97RD_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

return capzd_comm_bom(t + 1)
	   + ((capzd_comm_pv_loss_rec_int_rate(t + 1) + capzd_comm_eom(t + 1))
	      / (1.0 + loss_rec_amortzn_int_rate(t + 1)));

}


//@@ END

//@@ START - capzd_prem_bonus
// Capitalized Premium Bonus                                                                                             
// Column:CAPZD_PREM_BONUS
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_prem_bonus(int t) {
//^^^



//^^^

#line 1 "capzd_prem_bonus.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (!valn_flag && t > amortzn_period)
		return 0.0;
	
	return sum_over_gaap("capzd_prem_bonus", t);
	}

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (va->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	if (!reins_flag) //Gross
		return va->capzd_prem_bonus_pct * va->prem_bonus(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return va->capzd_prem_bonus_pct * va->prem_bonus(t) * va->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (fa->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	if (!reins_flag) //Gross
		return fa->capzd_prem_bonus_pct * fa->prem_bonus(t);
	
	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fa->capzd_prem_bonus_pct * fa->prem_bonus(t) * fa->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (fia->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	if (!reins_flag) //Gross
		return fia->capzd_prem_bonus_pct * fia->prem_bonus(t);
	
	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fia->capzd_prem_bonus_pct * fia->prem_bonus(t) * fia->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - capzd_prem_bonus_accum
// Capitalized Premium Bonus Accumulation                                                                                             
// Column:CAPZD_PREM_BONUS_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_prem_bonus_accum(int t) {
//^^^



//^^^

#line 1 "capzd_prem_bonus_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double def_p_bon_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double def_p_bon = cohort_history_capzd_prem_bonus/*.AtTime(tt)*/;
				
				def_p_bon_accum 
				= def_p_bon_accum * (1.0 + gaap_int_rate_mthly) + def_p_bon;
				}			
			return def_p_bon_accum; 
			}
		else //  No History for cell pricing at issue period
			return 0.0;	
		}
	else //valn_period != 0
		return init_capzd_prem_bonus_accum;
	}

return (capzd_prem_bonus_accum(t - 1)
	     + capzd_prem_bonus(t))
	   * (1.0 + gaap_amortzn_int_rate(t));

}


//@@ END

//@@ START - capzd_prem_bonus_accum_loss_rec_int_rate
// Capitalized Premium Bonus Accumulation At Loss Recognition Interest Rate                                                                                             
// Column:CAPZD_PREM_BONUS_ACCUM_LOSS_REC_INT_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_prem_bonus_accum_loss_rec_int_rate(int t) {
//^^^



//^^^

#line 1 "capzd_prem_bonus_accum_loss_rec_int_rate.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double def_p_bon_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double def_p_bon = cohort_history_capzd_prem_bonus/*.AtTime(tt)*/;
				
				def_p_bon_accum 
				= def_p_bon_accum * (1.0 + loss_rec_int_rate_mthly) + def_p_bon;
				}			
			return def_p_bon_accum; 
			}
		else //  No History for cell pricing at issue period
			return 0.0;	
		}
	else //valn_period != 0
		return init_capzd_prem_bonus_accum_loss_rec_int_rate;
	}

return (capzd_prem_bonus_accum(t - 1)
	     + capzd_prem_bonus(t))
	   * (1.0 + loss_rec_amortzn_int_rate(t));

}


//@@ END

//@@ START - capzd_prem_bonus_pv
// Capitalized Premium Bonus Present Value                                                                                             
// Column:CAPZD_PREM_BONUS_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_prem_bonus_pv(int t) {
//^^^



//^^^

#line 1 "capzd_prem_bonus_pv.SFAS97RD_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

return capzd_prem_bonus(t + 1)
	   + (capzd_prem_bonus_pv(t + 1)
		  / (1.0 + gaap_amortzn_int_rate(t + 1)));

}


//@@ END

//@@ START - capzd_prem_bonus_pv_loss_rec_int_rate
// Capitalized Premium Bonus Present Value At Loss Recognition Interest Rate                                                                                             
// Column:CAPZD_PREM_BONUS_PV_LOSS_REC_INT_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_prem_bonus_pv_loss_rec_int_rate(int t) {
//^^^



//^^^

#line 1 "capzd_prem_bonus_pv_loss_rec_int_rate.SFAS97RD_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

return capzd_prem_bonus(t + 1)
	   + (capzd_prem_bonus_pv_loss_rec_int_rate(t + 1)
		  / (1.0 + loss_rec_amortzn_int_rate(t + 1)));

}


//@@ END

//@@ START - capzd_reins_yrt_cost
// Capitalized YRT Reinsurance Cost                                                                                             
// Column:CAPZD_REINS_YRT_COST
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_reins_yrt_cost(int t) {
//^^^



//^^^

#line 1 "capzd_reins_yrt_cost.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*reins_flag || */t <= start_period || t > final_period)
	return NO_AVG;
	
if (reins_flag)
	return NO_AVG;

// No deferrals after stated amortizaton period
if (!valn_flag && t > amortzn_period)
	return 0.0;

return reins_yrt_cost(t);

}


//@@ END

//@@ START - cash_flow_bom
// Cash Flow Beginning of Month                                                                                             
// Column:CASH_FLOW_BOM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "cash_flow_bom.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("cash_flow_bom", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag) // Gross
		return ul->direct_cash_flow_bom(t);
	else if (reins_flag && ul->reins_flag && ul->coins_flag)
		return ul->sum_over_reinsurance("prem", t, COINSURANCE)
		       + ul->sum_over_reinsurance("prem", t, MODIFIED_COINSURANCE)
		       - prem_tax(t)
		       - comm_trail_bom(t)
		       - comm_excess_bom(t)
		       - maint_exp_bom(t);
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag) // Gross
		return iul->direct_cash_flow_bom(t);
	else if (reins_flag && iul->reins_flag && iul->coins_flag)
		return iul->sum_over_reinsurance("prem", t, COINSURANCE)
		       + iul->sum_over_reinsurance("prem", t, MODIFIED_COINSURANCE)
		       - prem_tax(t)
		       - comm_trail_bom(t)
		       - comm_excess_bom(t)
		       - maint_exp_bom(t);
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) // Gross
		return vul->direct_cash_flow_bom(t);
	else if (reins_flag && vul->reins_flag && vul->coins_flag)
		return vul->sum_over_reinsurance("prem", t, COINSURANCE)
		       + vul->sum_over_reinsurance("prem", t, MODIFIED_COINSURANCE)
		       - prem_tax(t)
		       - comm_trail_bom(t)
		       - comm_excess_bom(t)
		       - maint_exp_bom(t);
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{		
	if (!reins_flag) //Gross
		return fa->direct_cash_flow_bom(t);
	else if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance
		return fa->reins_cash_flow_bom(t);
	
	return 0.0;
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{		
	if (!reins_flag) //Gross
		return fia->direct_cash_flow_bom(t);
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance
		return fia->reins_cash_flow_bom(t);
	
	return 0.0;
	}

#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{		
	if (!reins_flag) //Gross
		return va->direct_cash_flow_bom(t);
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance
		return va->reins_cash_flow_bom(t);
	
	return 0.0;
	}

#endif

return 0.0;

}


//@@ END

//@@ START - cash_flow_int
// Cash Flow Interest                                                                                             
// Column:CASH_FLOW_INT
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_cash_flow_int(int t) {
//^^^



//^^^

#line 1 "cash_flow_int.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return cash_flow_bom(t)
	       * seg->cash_flow_rate_mthly(t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	return cash_flow_bom(t)
	       * (pow(1.0 + ul->asset_yld(t), 1.0 / 12.0) - 1.0);	
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	return cash_flow_bom(t)
	       * (pow(1.0 + iul->asset_yld(t), 1.0 / 12.0) - 1.0);	
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	return cash_flow_bom(t)
	       * (pow(1.0 + vul->asset_yld(t), 1.0 / 12.0) - 1.0);	
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	return cash_flow_bom(t)
	       * (pow(1.0 + fa->asset_yld(t), 1.0 / 12.0) - 1.0);	
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	return cash_flow_bom(t)
	       * (pow(1.0 + fia->asset_yld(t), 1.0 / 12.0) - 1.0);	
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	return cash_flow_bom(t)
	       * (pow(1.0 + va->asset_yld(t), 1.0 / 12.0) - 1.0);	
#endif

return 0.0;

}


//@@ END

//@@ START - charges
// Charges                                                                                             
// Column:CHARGES
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_charges(int t) {
//^^^



//^^^

#line 1 "charges.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("charges", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	double base_charges = 0.0;
	double addl_charges = 0.0;

	if (!reins_flag) //Gross
		{
		base_charges = max(0.0, min(ul->coi_chg(t),
		                            ul->fund_val_fixed(t - 1) + ul->prem_paid(t)
									- ul->rider_chg(t) - ul->loads(t)));

		if (t > ul->commencement_period + 1 && ul->fund_val_fixed(t - 1) < model_point_amount_threshold)
			{			
			addl_charges = ul->prem_paid(t)
							- rider_charges(t)
				            - loads(t)
							- base_charges
							+ credited_int(t)
							- max(0.0, ul->fund_released_dth(t))
							- max(0.0, ul->fund_released_surr(t))
							- max(0.0, ul->fund_released_withdrl(t))
							- max(0.0, ul->fund_released_maturity(t))
							- max(0.0, ul->fund_val_fixed(t))
							+ persist_bon_ref(t);
			}
		else if (ul->fund_val_fixed(t) > model_point_amount_threshold
			     && ul->credited_int(t) < model_point_amount_threshold)
			addl_charges = - ul->credited_int(t);

		return base_charges
		       + addl_charges;
		}

	// else coinsurance or modified coinsurance
	base_charges = max(0.0, min(ul->coi_chg(t),
		                        ul->fund_val_fixed(t - 1) + ul->prem_paid(t)
								- ul->rider_chg(t) - ul->loads(t)))
				   * ul->reins_pct;

	if (t > ul->commencement_period  + 1 && ul->fund_val_fixed(t - 1) < model_point_amount_threshold)
		{			
		addl_charges = ul->prem_paid(t) * ul->reins_pct
				       - rider_charges(t)
					   - loads(t)
					   - base_charges
					   + credited_int(t)
					   - max(0.0, ul->fund_released_dth(t) * ul->reins_pct) 
					   - max(0.0, ul->fund_released_surr(t) * ul->reins_pct)
					   - max(0.0, ul->fund_released_withdrl(t) * ul->reins_pct)
					   - max(0.0, ul->fund_released_maturity(t) * ul->reins_pct)
 					   - max(0.0, ul->fund_val_fixed(t) * ul->reins_pct)
					   + persist_bon_ref(t);
		}
	else if (ul->fund_val_fixed(t) > model_point_amount_threshold
			    && ul->credited_int(t) < model_point_amount_threshold)
		addl_charges = - ul->credited_int(t) * ul->reins_pct;

	return base_charges
		    + addl_charges;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return max(0.0, min(vul->coi_chg(t),
		                    vul->fund_val(t - 1) + vul->prem_paid(t)
							- vul->rider_chg(t) - vul->loads(t) - vul->sub_adv_fees(t)))
		       + vul->inv_fee_ref(t);

	// else modified coinsurance
	return max(0.0, min(vul->coi_chg(t),
	 	                vul->fund_val(t - 1) + vul->prem_paid(t) 
						- vul->rider_chg(t) - vul->loads(t) - vul->sub_adv_fees(t)))
		   * vul->reins_pct;

	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	double base_charges = 0.0;
	double addl_charges = 0.0;

	if (!reins_flag) //Gross
		{
		base_charges
		= max(0.0, min(iul->coi_chg(t),
		               iul->fund_val_fixed(t - 1) + iul->prem_paid(t) 
					   - iul->rider_chg(t) - iul->loads(t)));

		if (t > iul->commencement_period + 1 && iul->fund_val_fixed(t - 1) < model_point_amount_threshold)
			{			
			addl_charges = iul->prem_paid(t)
							- rider_charges(t)
				            - loads(t)
							- base_charges
							+ credited_int(t)
						    - max(0.0, iul->fund_released_dth(t))
						    - max(0.0, iul->fund_released_surr(t))
						    - max(0.0, iul->fund_released_withdrl(t))
						    - max(0.0, iul->fund_released_maturity(t))
							- max(0.0, iul->fund_val_fixed(t));
			}
		else if (iul->fund_val_fixed(t) > model_point_amount_threshold
			     && iul->credited_int(t) < model_point_amount_threshold)
			addl_charges = - iul->credited_int(t);

		else if (iul->sm_iul_ifund_curr->fund_val_bef_int(t) < model_point_amount_threshold
				 && iul->credited_int(t) > model_point_amount_threshold)
			addl_charges = iul->credited_int(t);

		return base_charges
		       + addl_charges;
		}

	// else coinsurance or modified coinsurance
	base_charges = max(0.0, min(iul->coi_chg(t),
		                        iul->fund_val_fixed(t - 1) + iul->prem_paid(t)
								- iul->rider_chg(t) - iul->loads(t)))
					* iul->reins_pct;

	if (t > iul->commencement_period + 1 && iul->fund_val_fixed(t - 1) < model_point_amount_threshold)
		{			
		addl_charges = iul->prem_paid(t) * iul->reins_pct
				        - rider_charges(t)
						- loads(t)
						- base_charges
						+ credited_int(t)
						- max(0.0, iul->fund_released_dth(t) * iul->reins_pct) 
						- max(0.0, iul->fund_released_surr(t) * iul->reins_pct)
						- max(0.0, iul->fund_released_withdrl(t) * iul->reins_pct)
						- max(0.0, iul->fund_released_maturity(t) * iul->reins_pct)
						- max(0.0, iul->fund_val_fixed(t) * iul->reins_pct);
		}
	else if (iul->fund_val_fixed(t) > model_point_amount_threshold
			    && iul->credited_int(t) < model_point_amount_threshold)
		addl_charges = - iul->credited_int(t) * iul->reins_pct;

		else if (iul->sm_iul_ifund_curr->fund_val_bef_int(t) < model_point_amount_threshold
				 && iul->credited_int(t) > model_point_amount_threshold)
			addl_charges = iul->credited_int(t) * iul->reins_pct;

	return base_charges
		    + addl_charges;
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->gmdb_chg(t)
			   + va->eeb_chg(t)
			   + va->gmab_chg(t)
			   + va->gmib_chg(t)
			   + va->gmwb_chg(t)
			   + va->inv_fee_ref(t);
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance
		{
		return va->reins_prem_gmdb(t)
			   + va->reins_prem_eeb(t)
			   + va->reins_prem_gmab(t)
			   + va->reins_prem_gmib(t)
			   + va->reins_prem_gmwb(t)
			   + va->reins_inv_fee_ref(t);
		}
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fia->gmwb_chg(t);
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance
		{
		return  fia->reins_prem_gmwb(t);
		}
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - comm_chargeback
// Commission Chargeback                                                                                             
// Column:COMM_CHARGEBACK
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_chargeback(int t) {
//^^^



//^^^

#line 1 "comm_chargeback.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("comm_chargeback", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return ul->comm_chargeback(t);

    if (reins_flag && ul->reins_flag && ul->coins_flag) //Commission of modco is equal to reinsurance expense allowance.
		return ul->sum_over_reinsurance("ea_chargeback", t, COINSURANCE)
			   + ul->sum_over_reinsurance("ea_chargeback", t, MODIFIED_COINSURANCE);

	return NO_AVG;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return vul->comm_chargeback(t);

    if (reins_flag && vul->reins_flag && vul->coins_flag) //Commission of modco is equal to reinsurance expense allowance.
		return vul->sum_over_reinsurance("ea_chargeback", t, COINSURANCE)
			   + vul->sum_over_reinsurance("ea_chargeback", t, MODIFIED_COINSURANCE);

	return NO_AVG;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return iul->comm_chargeback(t);

    if (reins_flag && iul->reins_flag && iul->coins_flag) //Commission of modco is equal to reinsurance expense allowance.
		return iul->sum_over_reinsurance("ea_chargeback", t, COINSURANCE)
			   + iul->sum_over_reinsurance("ea_chargeback", t, MODIFIED_COINSURANCE);

	return NO_AVG;
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->comm_chargeback(t);

	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return va->comm_chargeback(t) * va->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	
	
#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fa->comm_chargeback(t);

	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fa->comm_chargeback(t) * fa->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fia->comm_chargeback(t);

	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fia->comm_chargeback(t) * fia->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	

return NO_AVG;

}


//@@ END

//@@ START - comm_excess_bom
// Commissions Excess BOM                                                                                             
// Column:COMM_EXCESS_BOM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_excess_bom(int t) {
//^^^



//^^^

#line 1 "comm_excess_bom.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("comm_excess_bom", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
    if (!reins_flag) //Gross
    	return max(0.0, ul->comm_bom(t) - comm_trail_bom(t));

    if (reins_flag && ul->reins_flag && ul->coins_flag) //Commission is equal to reinsurance expense allowance.
		return ul->sum_over_reinsurance("ea_excess", t, COINSURANCE)
			   + ul->sum_over_reinsurance("ea_excess", t, MODIFIED_COINSURANCE);

    //Ceded and MP Not Reinsured
    return 0.0;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
    if (!reins_flag) //Gross
    	return max(0.0, vul->comm_bom(t) - comm_trail_bom(t));

    if (reins_flag && vul->reins_flag && vul->coins_flag) //Commission is equal to reinsurance expense allowance.
		return vul->sum_over_reinsurance("ea_excess", t, COINSURANCE)
			   + vul->sum_over_reinsurance("ea_excess", t, MODIFIED_COINSURANCE);

   //Ceded and MP Not Reinsured
    return 0.0;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
    if (!reins_flag) //Gross
    	return max(0.0, iul->comm_bom(t) - comm_trail_bom(t));

    if (reins_flag && iul->reins_flag && iul->coins_flag) //Commission is equal to reinsurance expense allowance.
		return iul->sum_over_reinsurance("ea_excess", t, COINSURANCE)
			   + iul->sum_over_reinsurance("ea_excess", t, MODIFIED_COINSURANCE);

    //Ceded and MP Not Reinsured
    return 0.0;
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
    {
    if (!reins_flag) //Gross
        return max(0.0, va->comm_bom(t) - comm_trail_bom(t));

    if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance
    	{
        if (va->reins_coverage_defn == RIDER_ONLY)
        	return NO_AVG;

        return max(0.0, va->comm_bom(t) * va->reins_pct - comm_trail_bom(t));
        }
    
	//Ceded and MP Not Reinsured via Coinsurance
    return 0.0;
    }
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
    {
    if (!reins_flag) //Gross
    	return max(0.0, fa->comm_bom(t) - comm_trail_bom(t));

    if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance
    	return max(0.0, fa->comm_bom(t) * fa->reins_pct - comm_trail_bom(t));

    //Ceded and MP Not Reinsured via Coinsurance
    return 0.0;
    }
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
    {
    if (!reins_flag) //Gross
    	return max(0.0, fia->comm_bom(t) - comm_trail_bom(t));

    if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance
        return max(0.0, fia->comm_bom(t) * fia->reins_pct - comm_trail_bom(t));

    //Ceded and MP Not Reinsured via Coinsurance
    return 0.0;
    }
#endif

return NO_AVG;

}


//@@ END

//@@ START - comm_excess_eom
// Commissions Excess EOM                                                                                             
// Column:COMM_EXCESS_EOM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_excess_eom(int t) {
//^^^



//^^^

#line 1 "comm_excess_eom.SFAS97RD_GAAP.for"
return NO_AVG;

}


//@@ END

//@@ START - comm_trail_bom
// Commissions Trail BOM                                                                                             
// Column:COMM_TRAIL_BOM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_trail_bom(int t) {
//^^^



//^^^

#line 1 "comm_trail_bom.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("comm_trail_bom", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag) //Gross
		{
		double comm_trail_pct_prem = 0.0;
		double comm_trail_pct_fund = 0.0;

		if (ul->pol_yr(t) <= ul->prem_term)			
			comm_trail_pct_prem = ul->comm_trail_pct_prem(t);			

		comm_trail_pct_fund 
		= (max(0.0, ul->fund_val_fixed(t - 1) - ul->pol_loan(t - 1)))	
		  * ul->comm_pct_fund.AtTime(comm_pct_fund_ult_index) / 12.0;	

		return comm_trail_pct_prem
		       + comm_trail_pct_fund;
		}
	
	if (reins_flag && ul->reins_flag && ul->coins_flag) //Commission is equal to reinsurance expense allowance.
		return ul->sum_over_reinsurance("ea_trail", t, COINSURANCE)
	   		   + ul->sum_over_reinsurance("ea_trail", t, MODIFIED_COINSURANCE);

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) //Gross
		{
		double comm_trail_pct_prem = 0.0;
		double comm_trail_pct_fund = 0.0;

		if (vul->pol_yr(t) <= vul->prem_term)			
			comm_trail_pct_prem = vul->comm_trail_pct_prem(t);			

		comm_trail_pct_fund 
		= (max(0.0, vul->fund_val(t - 1) - vul->pol_loan(t - 1)))	
		  * vul->comm_pct_fund.AtTime(comm_pct_fund_ult_index) / 12.0;	

		return comm_trail_pct_prem
		       + comm_trail_pct_fund;
		}
	
	if (reins_flag && vul->reins_flag && vul->coins_flag) //Commission is equal to reinsurance expense allowance.
		return vul->sum_over_reinsurance("ea_trail", t, COINSURANCE)
	   		   + vul->sum_over_reinsurance("ea_trail", t, MODIFIED_COINSURANCE);

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	
	
#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag) //Gross
		{
		double comm_trail_pct_prem = 0.0;
		double comm_trail_pct_fund = 0.0;

		if (iul->pol_yr(t) <= iul->prem_term)			
			comm_trail_pct_prem = iul->comm_trail_pct_prem(t);			

		comm_trail_pct_fund 
		= (max(0.0, iul->fund_val_fixed(t - 1) - iul->pol_loan(t - 1)))	
		  * iul->comm_pct_fund.AtTime(comm_pct_fund_ult_index) / 12.0;	

		return comm_trail_pct_prem
		       + comm_trail_pct_fund;
		}
	
	if (reins_flag && iul->reins_flag && iul->coins_flag) //Commission is equal to reinsurance expense allowance.
		return iul->sum_over_reinsurance("ea_trail", t, COINSURANCE)
	   		    + iul->sum_over_reinsurance("ea_trail", t, MODIFIED_COINSURANCE);

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	double gross_comm_bom_trail = 0.0;
	
	if (va->pol_yr(t) > va->prem_term)
		gross_comm_bom_trail
		= va->fund_val(t - 1)
		  * va->comm_pct_fund.AtTime(comm_pct_fund_ult_index)
		  / 12.0;
	else
		gross_comm_bom_trail
		= va->prem_paid(t) 
	      * va->comm_pct_prem.AtTime(prem_term_period)
		  + va->fund_val(t - 1)
		    * va->comm_pct_fund.AtTime(comm_pct_fund_ult_index)
			/ 12.0;	

	if (!reins_flag) //Gross
		return gross_comm_bom_trail;
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance
		{
		if (va->reins_coverage_defn == RIDER_ONLY)
			return NO_AVG;
		
		return gross_comm_bom_trail * va->reins_pct;
		}

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	
	
#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	double gross_comm_bom_trail = 0.0;
	
	if (fa->pol_yr(t) > fa->prem_term)
		gross_comm_bom_trail
		= fa->fund_val_fixed(t - 1)
		  * fa->comm_pct_fund.AtTime(comm_pct_fund_ult_index)
		  / 12.0;
	else
		gross_comm_bom_trail
		= fa->prem_paid(t) 
	      * fa->comm_pct_prem.AtTime(prem_term_period)
		  + fa->fund_val_fixed(t - 1)
		    * fa->comm_pct_fund.AtTime(comm_pct_fund_ult_index)
			/ 12.0;	
	
	if (!reins_flag) //Gross
		return gross_comm_bom_trail;
	
	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance
		return gross_comm_bom_trail * fa->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	double gross_comm_bom_trail	//for single premium product, no trail commission from commission as percent of premium
	= fia->fund_val_fixed(t - 1)
	  * fia->comm_pct_fund.AtTime(comm_pct_fund_ult_index)
	  / 12.0;
		
	if (!reins_flag) //Gross
		return gross_comm_bom_trail;
	
	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance
		return gross_comm_bom_trail * fia->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - comm_trail_eom
// Commissions Trail EOM                                                                                             
// Column:COMM_TRAIL_EOM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_trail_eom(int t) {
//^^^



//^^^

#line 1 "comm_trail_eom.SFAS97RD_GAAP.for"
return NO_AVG;

}


//@@ END

//@@ START - credited_int
// Credited Interest                                                                                             
// Column:CREDITED_INT
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_credited_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(35,"credited_int",t);
}



//^^^

#line 1 "credited_int.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("credited_int", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return max(0.0, ul->credited_int(t));
	else if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured
		return max(0.0, ul->credited_int(t) * ul->reins_pct);
	else //Ceded and MP Not Reinsured
		return 0.0;
	}	
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return max(0.0, vul->credited_int_ga(t));
	else if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured
		return max(0.0, vul->credited_int_ga(t) * vul->reins_pct);
	else //Ceded and MP Not Reinsured
		return 0.0;
	}	
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return max(0.0, iul->credited_int(t));
	else if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured
		return max(0.0, iul->credited_int(t) * iul->reins_pct);
	else //Ceded and MP Not Reinsured
		return 0.0;
	}	
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->credited_int_ga(t);
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->credited_int_ga(t) * va->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fa->credited_int(t);
	else if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured
		return fa->credited_int(t) * fa->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fia->credited_int(t);
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
		return fia->credited_int(t) * fia->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - dac_acq_exp
// DAC Acquisition Expense                                                                                             
// Column:DAC_ACQ_EXP
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp(int t) {
//^^^



//^^^

#line 1 "dac_acq_exp.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag) 
		{
		if (loss_recognition_flag)
			return k_capzd_acq_exp(t) * egp_pv_loss_rec_int_rate(t)
			       - capzd_acq_exp_pv_loss_rec_int_rate(t);

		return k_capzd_acq_exp(t) * egp_pv(t)
				- capzd_acq_exp_pv(t);
		}

	// (valn_period >= 0 && !valn_flag)
	if (valn_period == 0 )
		return dac_acq_exp_sch(t);
	else 
		return init_dac_acq_exp;	
	}
	
if ((!sfas97rd_valn_flag && !valn_flag)
	&& t == start_period + 1 && valn_period > 0) 
	return dac_acq_exp_sch(t - 1)
			+ capzd_acq_exp(t)
			+ dac_acq_exp_int(t)
			- dac_acq_exp_amortzn(t);
	
return dac_acq_exp(t - 1)
		+ capzd_acq_exp(t)
		+ dac_acq_exp_int(t)
		- dac_acq_exp_amortzn(t);

}


//@@ END

//@@ START - dac_acq_exp_amortzn
// DAC Acquisition Expense Amortization                                                                                             
// Column:DAC_ACQ_EXP_AMORTZN
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_amortzn(int t) {
//^^^



//^^^

#line 1 "dac_acq_exp_amortzn.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return egp(t) * k_capzd_acq_exp(t - 1);

}


//@@ END

//@@ START - dac_acq_exp_incr
// DAC Acquisition Expense Increase                                                                                             
// Column:DAC_ACQ_EXP_INCR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_incr(int t) {
//^^^



//^^^

#line 1 "dac_acq_exp_incr.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return dac_acq_exp(t)
       - dac_acq_exp(t - 1);

}


//@@ END

//@@ START - dac_acq_exp_int
// DAC Acquisition Expense Interest                                                                                             
// Column:DAC_ACQ_EXP_INT
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_int(int t) {
//^^^



//^^^

#line 1 "dac_acq_exp_int.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

double dac_acq_exp_prev_local = 0.0;

if ((!sfas97rd_valn_flag && !valn_flag)
	&& t == start_period + 1 && valn_period > 0) 
	dac_acq_exp_prev_local = dac_acq_exp_sch(t - 1);
else 
	dac_acq_exp_prev_local = dac_acq_exp(t - 1);

return (dac_acq_exp_prev_local + capzd_acq_exp(t))
		* amortzn_int_rate(t);

}


//@@ END

//@@ START - dac_acq_exp_loss_rec
// DAC Acquisition Expense Loss Recognition                                                                                             
// Column:DAC_ACQ_EXP_LOSS_REC
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_loss_rec(int t) {
//^^^



//^^^

#line 1 "dac_acq_exp_loss_rec.SFAS97RD_GAAP.for"
if (loss_recognition_defn == NO)
	return NO_AVG;	

if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		double def_acq_exp_total = capzd_acq_exp_accum_loss_rec_int_rate(t) + capzd_acq_exp_pv_loss_rec_int_rate(t);
		double def_comm_total = capzd_comm_accum_loss_rec_int_rate(t) + capzd_comm_pv_loss_rec_int_rate(t);
		double def_comm_loss_rec_accum = dac_comm_loss_rec_accum(t);
		double egp_total_avail = (egp_accum_loss_rec_int_rate(t) + egp_pv_loss_rec_int_rate(t) - (def_comm_total - def_comm_loss_rec_accum));
		double loss_rec_prev = 0.0;

		if (valn_period == 0)
			{			
			if (this == sfas97rd)
				loss_rec_prev = dac_acq_exp_loss_rec_hist_accum(t);

			else//  No History for cell pricing at issue period
				loss_rec_prev = 0.0;	
			}
		else//valn_period != 0
			loss_rec_prev = dac_acq_exp_loss_rec_hist_accum(t);
		
		return max(0.0, def_acq_exp_total - loss_rec_prev - egp_total_avail);
		}

	// (valn_period >= 0 && !valn_flag)
	return gaap_schedule[DAC_ACQ_EXP_LOSS_REC][0];	
	}

return 0.0;

}


//@@ END

//@@ START - dac_acq_exp_loss_rec_accum
// DAC Acquisition Expense Loss Recognition Accumulation                                                                                             
// Column:DAC_ACQ_EXP_LOSS_REC_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_loss_rec_accum(int t) {
//^^^



//^^^

#line 1 "dac_acq_exp_loss_rec_accum.SFAS97RD_GAAP.for"
if (loss_recognition_defn == NO)
	return NO_AVG;

if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;
	
if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			return dac_acq_exp_loss_rec_hist_accum(t) + dac_acq_exp_loss_rec(t); 

		//  No History for cell pricing at issue period
		return 0.0;	
		}	

	//valn_period != 0
	return dac_acq_exp_loss_rec_hist_accum(t) + dac_acq_exp_loss_rec(t);
	}	

return dac_acq_exp_loss_rec_accum(t - 1) 
       * (1.0 + loss_rec_amortzn_int_rate(t))
	   + dac_acq_exp_loss_rec(t);

}


//@@ END

//@@ START - dac_acq_exp_loss_rec_hist_accum
// DAC Acquisition Expense Loss Recognition History Accumulation                                                                                             
// Column:DAC_ACQ_EXP_LOSS_REC_HIST_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_loss_rec_hist_accum(int t) {
//^^^



//^^^

#line 1 "dac_acq_exp_loss_rec_hist_accum.SFAS97RD_GAAP.for"
if (loss_recognition_defn == NO)
	return NO_AVG;

if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;
	
if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double def_acq_exp_loss_rec_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double def_acq_exp_loss_rec = cohort_history_dac_acq_exp_loss/*.AtTime(tt)*/;
				
				def_acq_exp_loss_rec_accum 
				= def_acq_exp_loss_rec_accum 
				  * (1.0 + loss_rec_int_rate_mthly) 
				  + def_acq_exp_loss_rec;
				}			

			return def_acq_exp_loss_rec_accum; 
			}
		//  No History for cell pricing at issue period
		return 0.0;	
		}	

	//valn_period != 0
	return init_dac_acq_exp_loss_rec_accum;
	}	

return NO_AVG;

}


//@@ END

//@@ START - dac_acq_exp_sch
// DAC Acquisition Expense Schedule                                                                                             
// Column:DAC_ACQ_EXP_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_sch(int t) {
//^^^



//^^^

#line 1 "dac_acq_exp_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

return gaap_schedule[DAC_ACQ_EXP][0];

}


//@@ END

//@@ START - dac_comm
// DAC Commission                                                                                             
// Column:DAC_COMM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm(int t) {
//^^^



//^^^

#line 1 "dac_comm.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		if (loss_recognition_flag)
			return k_capzd_comm(t) * egp_pv_loss_rec_int_rate(t)
				   - capzd_comm_pv_loss_rec_int_rate(t);

		return k_capzd_comm(t) * egp_pv(t)
			   - capzd_comm_pv(t);
		}
	// !valn_flag
	if (valn_period == 0)
		return dac_comm_sch(t);
	else // valn_period > 0
		return init_dac_comm;	
	}

if ((!sfas97rd_valn_flag && !valn_flag)
	&& t == start_period + 1 && valn_period > 0) 
	return dac_comm_sch(t - 1)
		   + capzd_comm_bom(t)
		   + capzd_comm_eom(t)		
		   + dac_comm_int(t)
		   - dac_comm_amortzn(t);
	
return dac_comm(t - 1)
	   + capzd_comm_bom(t)
	   + capzd_comm_eom(t)	
	   + dac_comm_int(t)
	   - dac_comm_amortzn(t);

}


//@@ END

//@@ START - dac_comm_amortzn
// DAC Commission Amortization                                                                                             
// Column:DAC_COMM_AMORTZN
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_amortzn(int t) {
//^^^



//^^^

#line 1 "dac_comm_amortzn.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return egp(t) * k_capzd_comm(t - 1);

}


//@@ END

//@@ START - dac_comm_incr
// DAC Commission Increase                                                                                             
// Column:DAC_COMM_INCR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_incr(int t) {
//^^^



//^^^

#line 1 "dac_comm_incr.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return dac_comm(t)
       - dac_comm(t - 1);

}


//@@ END

//@@ START - dac_comm_int
// DAC Commission Interest                                                                                             
// Column:DAC_COMM_INT
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_int(int t) {
//^^^



//^^^

#line 1 "dac_comm_int.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

double dac_com_prev_local = 0.0;

if ((!sfas97rd_valn_flag && !valn_flag)
	&& t == start_period + 1 && valn_period > 0) 
	dac_com_prev_local = dac_comm_sch(t - 1);
else 
	dac_com_prev_local = dac_comm(t - 1);

return (dac_com_prev_local + capzd_comm_bom(t))
		* amortzn_int_rate(t);

}


//@@ END

//@@ START - dac_comm_loss_rec
// DAC Commission Loss Recognition                                                                                             
// Column:DAC_COMM_LOSS_REC
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_loss_rec(int t) {
//^^^



//^^^

#line 1 "dac_comm_loss_rec.SFAS97RD_GAAP.for"
if (loss_recognition_defn == NO)
	return NO_AVG;

if (t < start_period || t > final_period)
	return NO_AVG;
	
if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		double def_comm_total = capzd_comm_accum_loss_rec_int_rate(t) + capzd_comm_pv_loss_rec_int_rate(t);
		double egp_total_avail = egp_accum_loss_rec_int_rate(t) + egp_pv_loss_rec_int_rate(t);
		double loss_rec_prev = 0.0;
		
		if (valn_period == 0)
			{			
			if (this == sfas97rd)
				loss_rec_prev = dac_comm_loss_rec_hist_accum(t);

			else//  No History for cell pricing at issue period
				loss_rec_prev = 0.0;	
			}
		else//valn_period != 0
			loss_rec_prev = dac_comm_loss_rec_hist_accum(t);
		
		return max(0.0, def_comm_total - loss_rec_prev - egp_total_avail);
		}

	// (valn_period >= 0 && !valn_flag)
	return gaap_schedule[DAC_COMM_LOSS_REC][0];	
	}

return NO_AVG;

}


//@@ END

//@@ START - dac_comm_loss_rec_accum
// DAC Commission Loss Recognition Accumulation                                                                                             
// Column:DAC_COMM_LOSS_REC_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_loss_rec_accum(int t) {
//^^^



//^^^

#line 1 "dac_comm_loss_rec_accum.SFAS97RD_GAAP.for"
if (loss_recognition_defn == NO)
	return NO_AVG;

if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

if (t == start_period)
	{
	if (valn_period == 0)
		{			
		if (this == sfas97rd)
			return dac_comm_loss_rec_hist_accum(t) + dac_comm_loss_rec(t); 

		//  No History for cell pricing at issue period
		return 0.0;	
		}						

	//valn_period != 0
	return dac_comm_loss_rec_hist_accum(t) + dac_comm_loss_rec(t);
	}	
		
return dac_comm_loss_rec_accum(t - 1) 
       * (1.0 + loss_rec_amortzn_int_rate(t))
	   + dac_comm_loss_rec(t);

}


//@@ END

//@@ START - dac_comm_loss_rec_hist_accum
// DAC Commission Loss Recognition History Accumulation                                                                                             
// Column:DAC_COMM_LOSS_REC_HIST_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_loss_rec_hist_accum(int t) {
//^^^



//^^^

#line 1 "dac_comm_loss_rec_hist_accum.SFAS97RD_GAAP.for"
if (loss_recognition_defn == NO)
	return NO_AVG;

if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

if (t == start_period)
	{
	if (valn_period == 0)
		{			
		if (this == sfas97rd)
			{
			double def_dac_comm_loss_rec_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double def_dac_comm_loss_rec = cohort_history_dac_comm_loss/*.AtTime(tt)*/;
				
				def_dac_comm_loss_rec_accum 
				= def_dac_comm_loss_rec_accum 
				  * (1.0 + loss_rec_int_rate_mthly) 
				  + def_dac_comm_loss_rec;
				}			

			return def_dac_comm_loss_rec_accum; 
			}
		//  No History for cell pricing at issue period
		return 0.0;	
		}						

	//valn_period != 0
	return init_dac_comm_loss_rec_accum;
	}	
		
return NO_AVG;

}


//@@ END

//@@ START - dac_comm_sch
// DAC Commission Schedule                                                                                             
// Column:DAC_COMM_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_sch(int t) {
//^^^



//^^^

#line 1 "dac_comm_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

return gaap_schedule[DAC_COMM][0];

}


//@@ END

//@@ START - dac_incr
// DAC Increase                                                                                             
// Column:DAC_INCR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_incr(int t) {
//^^^



//^^^

#line 1 "dac_incr.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return dac_acq_exp_incr(t)
       + dac_comm_incr(t)
       + dac_prem_bonus_incr(t)
       + dac_reins_yrt_asset_incr(t);

}


//@@ END

//@@ START - dac_prem_bonus
// DAC Premium Bonus                                                                                             
// Column:DAC_PREM_BONUS
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus(int t) {
//^^^



//^^^

#line 1 "dac_prem_bonus.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		if (loss_recognition_flag)
			return k_capzd_prem_bonus(t) * egp_pv_loss_rec_int_rate(t)
				   - capzd_prem_bonus_pv_loss_rec_int_rate(t);

		return k_capzd_prem_bonus(t) * egp_pv(t)
			   - capzd_prem_bonus_pv(t);
		}
		// (!valn_flag)
	if (valn_period == 0 )
		return dac_prem_bonus_sch(t);
	else // valn_period > 0
		return init_dac_prem_bonus;	
	}

if ((!sfas97rd_valn_flag && !valn_flag)
	&& t == start_period + 1 && valn_period > 0) 
	return dac_prem_bonus_sch(t - 1)
		   + capzd_prem_bonus(t)
  		   + dac_prem_bonus_int(t)
  		   - dac_prem_bonus_amortzn(t);
	
return dac_prem_bonus(t - 1)
	   + capzd_prem_bonus(t)
	   + dac_prem_bonus_int(t)
	   - dac_prem_bonus_amortzn(t);

}


//@@ END

//@@ START - dac_prem_bonus_amortzn
// DAC Premium Bonus Amortization                                                                                             
// Column:DAC_PREM_BONUS_AMORTZN
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_amortzn(int t) {
//^^^



//^^^

#line 1 "dac_prem_bonus_amortzn.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return egp(t) * k_capzd_prem_bonus(t - 1);

}


//@@ END

//@@ START - dac_prem_bonus_incr
// DAC Premium Bonus Increase                                                                                             
// Column:DAC_PREM_BONUS_INCR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_incr(int t) {
//^^^



//^^^

#line 1 "dac_prem_bonus_incr.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return dac_prem_bonus(t)
       - dac_prem_bonus(t - 1);

}


//@@ END

//@@ START - dac_prem_bonus_int
// DAC Premium Bonus Interest                                                                                             
// Column:DAC_PREM_BONUS_INT
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_int(int t) {
//^^^



//^^^

#line 1 "dac_prem_bonus_int.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

double dac_prem_bonus_prev_local = 0.0;

if ((!sfas97rd_valn_flag && !valn_flag)
	&& t == start_period + 1 && valn_period > 0) 
	dac_prem_bonus_prev_local = dac_prem_bonus_sch(t - 1);
else 
	dac_prem_bonus_prev_local = dac_prem_bonus(t - 1);
	
return (dac_prem_bonus_prev_local + capzd_prem_bonus(t))
		* amortzn_int_rate(t);

}


//@@ END

//@@ START - dac_prem_bonus_loss_rec
// DAC Premium Bonus Loss Recognition                                                                                             
// Column:DAC_PREM_BONUS_LOSS_REC
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_loss_rec(int t) {
//^^^



//^^^

#line 1 "dac_prem_bonus_loss_rec.SFAS97RD_GAAP.for"
if (loss_recognition_defn == NO)
	return NO_AVG;	

if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		double def_acq_exp_total = capzd_acq_exp_accum_loss_rec_int_rate(t) + capzd_acq_exp_pv_loss_rec_int_rate(t);
		double def_comm_total = capzd_comm_accum_loss_rec_int_rate(t) + capzd_comm_pv_loss_rec_int_rate(t);
		double def_prem_bon_total = capzd_prem_bonus_accum_loss_rec_int_rate(t) + capzd_prem_bonus_pv_loss_rec_int_rate(t);
		double def_comm_loss_rec_accum = dac_comm_loss_rec_accum(t);
		double def_acq_exp_loss_rec_accum = dac_acq_exp_loss_rec_accum(t);
		double egp_total_avail = (egp_accum_loss_rec_int_rate(t) + egp_pv_loss_rec_int_rate(t) - (def_comm_total - def_comm_loss_rec_accum) 
		                          - (def_acq_exp_total - def_acq_exp_loss_rec_accum));
		double loss_rec_prev = 0.0;

		if (valn_period == 0)
			{
			if (this == sfas97rd)
				loss_rec_prev = dac_prem_bonus_loss_rec_hist_accum(t); 

			else //  No History for cell pricing at issue period
				loss_rec_prev = 0.0;	
			}	
		else //valn_period != 0
			loss_rec_prev = dac_prem_bonus_loss_rec_hist_accum(t);
		
		return max(0.0, def_prem_bon_total - loss_rec_prev - egp_total_avail);
		}

	// (valn_period >= 0 && !valn_flag)
	return gaap_schedule[DAC_PREM_BONUS_LOSS_REC][0];	
	}

return 0.0;

}


//@@ END

//@@ START - dac_prem_bonus_loss_rec_accum
// DAC Premium Bonus Loss Recognition Accumulation                                                                                             
// Column:DAC_PREM_BONUS_LOSS_REC_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_loss_rec_accum(int t) {
//^^^



//^^^

#line 1 "dac_prem_bonus_loss_rec_accum.SFAS97RD_GAAP.for"
if (loss_recognition_defn == NO)
	return NO_AVG;

if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;
	
if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			return dac_prem_bonus_loss_rec_hist_accum(t) + dac_prem_bonus_loss_rec(t); 

		//  No History for cell pricing at issue period
		return 0.0;	
		}	

	//valn_period != 0
	return dac_prem_bonus_loss_rec_hist_accum(t) + dac_prem_bonus_loss_rec(t);
	}	

return dac_prem_bonus_loss_rec_accum(t - 1) 
       * (1.0 + loss_rec_amortzn_int_rate(t))
	   + dac_prem_bonus_loss_rec(t);

}


//@@ END

//@@ START - dac_prem_bonus_loss_rec_hist_accum
// DAC Premium Bonus Loss Recognition History Accumulation                                                                                             
// Column:DAC_PREM_BONUS_LOSS_REC_HIST_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_loss_rec_hist_accum(int t) {
//^^^



//^^^

#line 1 "dac_prem_bonus_loss_rec_hist_accum.SFAS97RD_GAAP.for"
if (loss_recognition_defn == NO)
	return NO_AVG;

if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;
	
if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double def_prem_bonus_loss_rec_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double def_prem_bonus_loss_rec = cohort_history_dac_prem_bonus_loss/*.AtTime(tt)*/;
				
				def_prem_bonus_loss_rec_accum 
				= def_prem_bonus_loss_rec_accum 
				  * (1.0 + loss_rec_int_rate_mthly) 
				  + def_prem_bonus_loss_rec;
				}			

			return def_prem_bonus_loss_rec_accum; 
			}
		//  No History for cell pricing at issue period
		return 0.0;	
		}	

	//valn_period != 0
	return init_dac_prem_bonus_loss_rec_accum;
	}	

return NO_AVG;

}


//@@ END

//@@ START - dac_prem_bonus_sch
// DAC Premium Bonus Schedule                                                                                             
// Column:DAC_PREM_BONUS_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_sch(int t) {
//^^^



//^^^

#line 1 "dac_prem_bonus_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

return gaap_schedule[DAC_PREM_BONUS][0];

}


//@@ END

//@@ START - dac_reins_yrt_asset
// DAC YRT Reinsurance Asset                                                                                             
// Column:DAC_REINS_YRT_ASSET
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset(int t) {
//^^^



//^^^

#line 1 "dac_reins_yrt_asset.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!cohort_reins_yrt_indicator)
	return NO_AVG;
	
if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		return k_reins_yrt_cost(t) * egp_pv(t)
				- reins_yrt_cost_pv(t);

	// (!valn_flag)
	if (valn_period == 0)
		return dac_reins_yrt_asset_sch(t);
	else // valn_period > 0
		return init_dac_reins_yrt_asset;		
	}
	
if ((!sfas97rd_valn_flag && !valn_flag)
	&& t == start_period + 1 && valn_period > 0) 
	return dac_reins_yrt_asset_sch(t - 1)
		   + capzd_reins_yrt_cost(t)
		   + dac_reins_yrt_asset_int(t)
		   - dac_reins_yrt_asset_amortzn(t);
	
return dac_reins_yrt_asset(t - 1)
	   + capzd_reins_yrt_cost(t)
	   + dac_reins_yrt_asset_int(t)
       - dac_reins_yrt_asset_amortzn(t);

}


//@@ END

//@@ START - dac_reins_yrt_asset_amortzn
// DAC YRT Reinsurance Asset Amortization                                                                                             
// Column:DAC_REINS_YRT_ASSET_AMORTZN
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset_amortzn(int t) {
//^^^



//^^^

#line 1 "dac_reins_yrt_asset_amortzn.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!cohort_reins_yrt_indicator)
	return NO_AVG;

return egp(t) * k_reins_yrt_cost(t - 1);

}


//@@ END

//@@ START - dac_reins_yrt_asset_incr
// DAC YRT Reinsurance Asset Increase                                                                                             
// Column:DAC_REINS_YRT_ASSET_INCR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset_incr(int t) {
//^^^



//^^^

#line 1 "dac_reins_yrt_asset_incr.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return dac_reins_yrt_asset(t)
       - dac_reins_yrt_asset(t - 1);

}


//@@ END

//@@ START - dac_reins_yrt_asset_int
// DAC YRT Reinsurance Asset Interest                                                                                             
// Column:DAC_REINS_YRT_ASSET_INT
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset_int(int t) {
//^^^



//^^^

#line 1 "dac_reins_yrt_asset_int.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!cohort_reins_yrt_indicator)
	return NO_AVG;

double dac_reins_yrt_asset_prev_local = 0.0;

if ((!sfas97rd_valn_flag && !valn_flag)
	&& t == start_period + 1 && valn_period > 0) 
	dac_reins_yrt_asset_prev_local = dac_reins_yrt_asset_sch(t - 1);
else 
	dac_reins_yrt_asset_prev_local = dac_reins_yrt_asset(t - 1);

return dac_reins_yrt_asset_prev_local
	   * gaap_amortzn_int_rate(t);

}


//@@ END

//@@ START - dac_reins_yrt_asset_sch
// DAC YRT Reinsurance Asset Schedule                                                                                             
// Column:DAC_REINS_YRT_ASSET_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset_sch(int t) {
//^^^



//^^^

#line 1 "dac_reins_yrt_asset_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

if (!cohort_reins_yrt_indicator)
	return NO_AVG;
	
return gaap_schedule[DAC_REINS_YRT_ASSET][0];

}


//@@ END

//@@ START - date
// Date                                                                                             
// Column:DATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_date(int t) {
//^^^



//^^^

#line 1 "date.SFAS97RD_GAAP.for"
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

//@@ START - deferred_loads
// Deferred Loads                                                                                             
// Column:DEFERRED_LOADS
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_deferred_loads(int t) {
//^^^



//^^^

#line 1 "deferred_loads.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (!valn_flag && t > amortzn_period)
		return 0.0;

	return sum_over_gaap("deferred_loads" , t);
	}
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (ul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	double load_curr_less_ult = 0.0;
	
	//Calculate load_total_bom_ult, Begin
	double load_total_bom_ult = 0.0; 
	double load_pct_prem = 0.0;
	double load_per_unit = 0.0;
	double load_per_pol = 0.0;
	double load_pct_fund = 0.0;
	double pol_fee_chg = 0.0;
	
	double tgt_prem_rate = ul->sm_ul_ifund_curr->load_pct_tgt_prem.AtTime(ul->maturity_period_gmp);
	double excess_prem_rate = ul->sm_ul_ifund_curr->load_pct_excess_prem.AtTime(ul->maturity_period_gmp);
	double unit_rate = ul->sm_ul_ifund_curr->load_per_unit.AtTime(ul->maturity_period_gmp);
	double pol_rate = ul->sm_ul_ifund_curr->load_per_pol.AtTime(ul->maturity_period_gmp);
	double fund_rate = ul->sm_ul_ifund_curr->load_pct_fund_input.AtTime(ul->maturity_period_gmp);

	// load_pct_prem
	if (ul->sm_ul_ifund_curr->prem_due_flag(t))
		{
		if (tgt_prem_rate > rate_ratio_threshold)
			load_pct_prem = ul->sm_ul_ifund_curr->tgt_prem_paid(t) 
							* tgt_prem_rate;
			
		if (excess_prem_rate > rate_ratio_threshold)
			load_pct_prem += ul->sm_ul_ifund_curr->excess_prem_paid(t) 
							 * excess_prem_rate;
		}
	
	// load_per_unit
	if (unit_rate > rate_ratio_threshold)
		{
		double load_per_unit_freq = 12.0;
		load_per_unit = unit_rate / load_per_unit_freq;
		}
	
	// load_per_pol
	if (pol_rate > rate_ratio_threshold)
		{
		double load_per_pol_freq = 12.0;
		load_per_pol = pol_rate / load_per_pol_freq / ul->units_per_pol;
		}
	 
	// load_pct_fund
	if (fund_rate > rate_ratio_threshold)
		{
		double load_pct_fund_freq = 12.0;
		load_pct_fund = ul->sm_ul_ifund_curr->fund_val_aft_withdrl(t - 1) 
						* fund_rate 
						/ load_pct_fund_freq;
		}
	
	// pol_fee_chg
	if (ul->pol_fee_chg_mode == MODALLY 
	    && ul->sm_ul_ifund_curr->prem_due_flag(t) == 1)
		{
		if( ul->sm_ul_py->paid_up(ul->pol_yr(t)) == 1 
			&& t == ul->commencement_period + 1) // Single premium model point
			pol_fee_chg = ul->sm_ul_py->pol_fee;
		else
			pol_fee_chg = ul->sm_ul_py->pol_fee / ul->prem_freq;
		}
	
	load_total_bom_ult = load_pct_prem
						 + load_per_unit
						 + load_per_pol
						 + load_pct_fund
						 + pol_fee_chg;

//Calculate load_total_bom_ult, End
	
	load_curr_less_ult 
		= max(0.0 , ul->sm_ul_ifund_curr->load_total_bom(t)
		            -  load_total_bom_ult);
		
	double reins_pct = 0.0;
	
	if (!reins_flag) //Gross
		reins_pct = 1.0;
	
	else if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		reins_pct = ul->reins_pct;
	
	else //Ceded and MP Not Reinsured
		reins_pct = 0.0;
	
	return max(0.0, min(load_curr_less_ult * ul->units_inf(t - 1),
	                    ul->fund_val_fixed(t - 1) + ul->prem_paid(t) - ul->rider_chg(t)))
		   * reins_pct;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (vul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	double load_curr_less_ult = 0.0;
	
	//Calculate load_total_bom_ult, Begin
	double load_total_bom_ult = 0.0; 
	double load_pct_prem = 0.0;
	double load_per_unit = 0.0;
	double load_per_pol = 0.0;
	double load_pct_fund = 0.0;
	double pol_fee_chg = 0.0;

	double tgt_prem_rate = vul->sm_vul_ifund_curr->load_pct_tgt_prem.AtTime(vul->maturity_period_gmp);
	double excess_prem_rate = vul->sm_vul_ifund_curr->load_pct_excess_prem.AtTime(vul->maturity_period_gmp);
	double unit_rate = vul->sm_vul_ifund_curr->load_per_unit.AtTime(vul->maturity_period_gmp);
	double pol_rate = vul->sm_vul_ifund_curr->load_per_pol.AtTime(vul->maturity_period_gmp);
	double fund_rate = vul->sm_vul_ifund_curr->load_pct_fund_input.AtTime(vul->maturity_period_gmp);

	// load_pct_prem
	if (vul->sm_vul_ifund_curr->prem_due_flag(t))
		{
		if (tgt_prem_rate > rate_ratio_threshold)
			load_pct_prem = vul->sm_vul_ifund_curr->tgt_prem_paid(t) 
							* tgt_prem_rate;
			
		if (excess_prem_rate > rate_ratio_threshold)
			load_pct_prem += vul->sm_vul_ifund_curr->excess_prem_paid(t) 
							 * excess_prem_rate;
		}
	
	// load_per_unit
	if (unit_rate > rate_ratio_threshold)
		{
		double load_per_unit_freq = 12.0;
		load_per_unit = unit_rate / load_per_unit_freq;
		}
	
	// load_per_pol
	if (pol_rate > rate_ratio_threshold)
		{
		double load_per_pol_freq = 12.0;
		load_per_pol = pol_rate / load_per_pol_freq / vul->units_per_pol;
		}
	 
	// load_pct_fund
	if (fund_rate > rate_ratio_threshold)
		{
		double load_pct_fund_freq = 12.0;
		load_pct_fund = vul->sm_vul_ifund_curr->fund_val_aft_withdrl(t - 1) 
						* fund_rate 
						/ load_pct_fund_freq;
		}
	
	// pol_fee_chg
	if (vul->pol_fee_chg_mode == MODALLY 
	    && vul->sm_vul_ifund_curr->prem_due_flag(t) == 1)
		{
		if( vul->sm_vul_py->paid_up(vul->pol_yr(t)) == 1 
			&& t == vul->commencement_period + 1) // Single premium model point
			pol_fee_chg = vul->sm_vul_py->pol_fee;
		else
			pol_fee_chg = vul->sm_vul_py->pol_fee / vul->prem_freq;
		}
	
	load_total_bom_ult = load_pct_prem
						 + load_per_unit
						 + load_per_pol
						 + load_pct_fund
						 + pol_fee_chg;

	//Calculate load_total_bom_ult, End

	load_curr_less_ult 
		= max(0.0 , vul->sm_vul_ifund_curr->load_total_bom(t)
		            -  load_total_bom_ult);
		
	double reins_pct = 0.0;
	
	if (!reins_flag) //Gross
		reins_pct = 1.0;
	
	else if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		reins_pct = vul->reins_pct;

	else //Ceded and MP Not Reinsured
		reins_pct = 0.0;

	return max(0.0, min(load_curr_less_ult * vul->units_inf(t - 1),
	                vul->fund_val(t - 1) + vul->prem_paid(t) - vul->rider_chg(t)))
		    * reins_pct;	
			
	//Ceded and MP Not Reinsured
	return 0.0;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	// No deferrals after stated amortizaton period
	if (iul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	double load_curr_less_ult = 0.0;
	
	//Calculate load_total_bom_ult, Begin
	double load_total_bom_ult = 0.0; 
	double load_pct_prem = 0.0;
	double load_per_unit = 0.0;
	double load_per_pol = 0.0;
	double load_pct_fund = 0.0;
	double pol_fee_chg = 0.0;
	
	double tgt_prem_rate = iul->sm_iul_ifund_curr->load_pct_tgt_prem.AtTime(iul->maturity_period_gmp);
	double excess_prem_rate = iul->sm_iul_ifund_curr->load_pct_excess_prem.AtTime(iul->maturity_period_gmp);
	double unit_rate = iul->sm_iul_ifund_curr->load_per_unit.AtTime(iul->maturity_period_gmp);
	double pol_rate = iul->sm_iul_ifund_curr->load_per_pol.AtTime(iul->maturity_period_gmp);
	double fund_rate = iul->sm_iul_ifund_curr->load_pct_fund_input.AtTime(iul->maturity_period_gmp);

	// load_pct_prem
	if (iul->sm_iul_ifund_curr->prem_due_flag(t))
		{
		if (tgt_prem_rate > rate_ratio_threshold)
			load_pct_prem = iul->sm_iul_ifund_curr->tgt_prem_paid(t) 
							* tgt_prem_rate;
			
		if (excess_prem_rate > rate_ratio_threshold)
			load_pct_prem += iul->sm_iul_ifund_curr->excess_prem_paid(t) 
							 * excess_prem_rate;
		}
	
	// load_per_unit
	if (unit_rate > rate_ratio_threshold)
		{
		double load_per_unit_freq = 12.0;
		load_per_unit = unit_rate / load_per_unit_freq;
		}
	
	// load_per_pol
	if (pol_rate > rate_ratio_threshold)
		{
		double load_per_pol_freq = 12.0;
		load_per_pol = pol_rate / load_per_pol_freq / iul->units_per_pol;
		}
	 
	// load_pct_fund
	if (fund_rate > rate_ratio_threshold)
		{
		double load_pct_fund_freq = 12.0;
		load_pct_fund = iul->sm_iul_ifund_curr->fund_val_aft_withdrl(t - 1) 
						* fund_rate 
						/ load_pct_fund_freq;
		}
	
	// pol_fee_chg
	if (iul->pol_fee_chg_mode == MODALLY 
	    && iul->sm_iul_ifund_curr->prem_due_flag(t) == 1)
		{
		if (iul->sm_iul_py->paid_up(iul->pol_yr(t)) == 1 
			&& t == iul->commencement_period + 1) // Single premium model point
			pol_fee_chg = iul->sm_iul_py->pol_fee;
		else
			pol_fee_chg = iul->sm_iul_py->pol_fee / iul->prem_freq;
		}
	
	load_total_bom_ult = load_pct_prem
						 + load_per_unit
						 + load_per_pol
						 + load_pct_fund
						 + pol_fee_chg;

	//Calculate load_total_bom_ult, End
	load_curr_less_ult 
		= max(0.0 , iul->sm_iul_ifund_curr->load_total_bom(t)
		            - load_total_bom_ult);
		
	double reins_pct = 0.0;
	
	if (!reins_flag) //Gross
		reins_pct = 1.0;
	
	else if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		reins_pct = iul->reins_pct;
	
	else //Ceded and MP Not Reinsured
		reins_pct = 0.0;
	
	return max(0.0, min(load_curr_less_ult * iul->units_inf(t - 1),
	                    iul->fund_val_fixed(t - 1) + iul->prem_paid(t) - iul->rider_chg(t)))
		   * reins_pct;
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - deferred_loads_accum
// Deferred Loads Accumulation                                                                                             
// Column:DEFERRED_LOADS_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_deferred_loads_accum(int t) {
//^^^



//^^^

#line 1 "deferred_loads_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;
	
if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;
	
if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double def_loads_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double def_loads = cohort_history_deferred_load/*.AtTime(tt)*/;
				
				def_loads_accum 
				= (def_loads_accum + def_loads) * (1.0 + gaap_int_rate_mthly);
				}			

			return def_loads_accum; 
			}
		//  No History for cell pricing at issue period
		return 0.0;	
		}		

	//valn_period != 0
	return init_deferred_loads_accum;
	}
		
return (deferred_loads_accum(t - 1)
         + deferred_loads(t))
 	  * (1.0 + gaap_amortzn_int_rate(t));

}


//@@ END

//@@ START - deferred_loads_pv
// Deferred Loads Present Value                                                                                             
// Column:DEFERRED_LOADS_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_deferred_loads_pv(int t) {
//^^^



//^^^

#line 1 "deferred_loads_pv.SFAS97RD_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

return deferred_loads(t + 1)
		+ (deferred_loads_pv(t + 1)
			/ (1.0 + gaap_amortzn_int_rate(t + 1)));

}


//@@ END

//@@ START - dth_claim_cost
// Death Claim Cost                                                                                             
// Column:DTH_CLAIM_COST
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dth_claim_cost(int t) {
//^^^



//^^^

#line 1 "dth_claim_cost.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("dth_claim_cost", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	double claim_cost = 0.0;
	
	if (!reins_flag) //Gross
		return ul->dth_benefits(t) 
		       - max(0.0, ul->fund_released_dth(t));		

	if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		return (ul->sum_over_reinsurance("coverage_per_model_basis", t, COINSURANCE)
		        + ul->sum_over_reinsurance("coverage_per_model_basis", t, MODIFIED_COINSURANCE))
				* ul->dths_units(t)
		        - max(0.0, ul->fund_released_dth(t) * ul->reins_pct);

	return NO_AVG;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	double claim_cost = 0.0;
	
	if (!reins_flag) //Gross
		return vul->dth_benefits(t) 
		       - max(0.0, vul->fund_released_dth(t));		

	if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		return (vul->sum_over_reinsurance("coverage_per_model_basis", t, COINSURANCE)
		        + vul->sum_over_reinsurance("coverage_per_model_basis", t, MODIFIED_COINSURANCE))
				* vul->dths_units(t)
		        - max(0.0, vul->fund_released_dth(t) * vul->reins_pct);

	return NO_AVG;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	double claim_cost = 0.0;
	
	if (!reins_flag) //Gross
		return iul->dth_benefits(t) 
		       - max(0.0, iul->fund_released_dth(t));		

	if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		return (iul->sum_over_reinsurance("coverage_per_model_basis", t, COINSURANCE)
		        + iul->sum_over_reinsurance("coverage_per_model_basis", t, MODIFIED_COINSURANCE))
				* iul->dths_units(t)
		        - max(0.0, iul->fund_released_dth(t) * iul->reins_pct);

	return NO_AVG;
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag)
		return va->dth_benefits(t)
		       - va->fund_released_dth(t);

	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->reins_dth_benefits(t)
               - va->fund_released_dth(t)
                 * va->reins_pct; 

	return NO_AVG;
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (!reins_flag)
		return fa->dth_benefits(t)
		       - fa->fund_released_dth(t);

	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured
		return fa->reins_dth_benefits(t)
               - fa->fund_released_dth(t)
                 * fa->reins_pct; 

	return NO_AVG;
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (!reins_flag)
		return fia->dth_benefits(t)
		       - fia->fund_released_dth(t);

	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
		return fia->reins_dth_benefits(t)
               - fia->fund_released_dth(t)
                 * fia->reins_pct; 

	return NO_AVG;
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - egp
// Estimated Gross Profit                                                                                             
// Column:EGP
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp(int t) {
//^^^



//^^^

#line 1 "egp.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;
	
if (sfas97rd_valn_flag)
	{
	if (t == start_period)
		return 0.0;
	
	double egp_bef_sop = egp_gain_exp(t)
						 + egp_gain_inv(t)
						 + egp_gain_mort(t)
						 + egp_gain_surr(t)
						 + egp_gain_persist_bon_ref(t);
	
	return max(0.0, egp_bef_sop - egp_sop031_res_incr(t));
	}
	
return gaap_schedule[EGP][t];

}


//@@ END

//@@ START - egp_accum
// EGP Accumulation                                                                                             
// Column:EGP_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_accum(int t) {
//^^^



//^^^

#line 1 "egp_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;
	
if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;
	
if (t == start_period)
	{
	if (valn_period == 0)
		{					
		if (this == sfas97rd)
			{
			double egp_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double egp = cohort_history_agp/*.AtTime(tt)*/;
				
				egp_accum = egp_accum * (1.0 + gaap_int_rate_mthly) + egp;
				}

			return egp_accum; 
			}

		//  No History for cell pricing at issue period
		return 0.0;	
		}		

	//valn_period != 0
	return init_egp_accum;
	}
	
return egp_accum(t - 1) 
       * (1.0 + gaap_amortzn_int_rate(t))
       + agp(t);

}


//@@ END

//@@ START - egp_accum_loss_rec_int_rate
// EGP Accumulation At Loss Recognition Interest Rate                                                                                             
// Column:EGP_ACCUM_LOSS_REC_INT_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_accum_loss_rec_int_rate(int t) {
//^^^



//^^^

#line 1 "egp_accum_loss_rec_int_rate.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;
	
if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;
	
if (t == start_period)
	{
	if (valn_period == 0)
		{					
		if (this == sfas97rd)
			{
			double egp_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double egp = cohort_history_agp/*.AtTime(tt)*/;
				
				egp_accum = egp_accum * (1.0 + loss_rec_int_rate_mthly) + egp;
				}

			return egp_accum; 
			}

		//  No History for cell pricing at issue period
		return 0.0;	
		}		

	//valn_period != 0
	return init_egp_accum_loss_rec_int_rate;
	}
	
return egp_accum_loss_rec_int_rate(t - 1) 
       * (1.0 + loss_rec_amortzn_int_rate(t))
       + agp(t);

}


//@@ END

//@@ START - egp_gain_exp
// EGP Expense Gain                                                                                             
// Column:EGP_GAIN_EXP
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_exp(int t) {
//^^^



//^^^

#line 1 "egp_gain_exp.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	{
	//force call for reports
	charges(t);
	
	#if defined(__UL_LIAB_H_)
	double product_loads = loads(t);
	double def_loads = deferred_loads(t);
	double non_def_exp = maint_exp_bom(t)
						 + maint_exp_eom(t)
					     + prem_tax(t)
						 + comm_trail_bom(t)
						 + comm_excess_bom(t)
					     + comm_trail_eom(t)
						 + comm_excess_eom(t)
					     - comm_chargeback(t)
					     - capzd_comm_bom(t)					
					     - capzd_comm_eom(t);
		
	return product_loads - def_loads - non_def_exp;
	#endif

	#if defined(__VUL_LIAB_H_)
	double product_loads = loads(t);
	double def_loads = deferred_loads(t);
	double non_def_exp = maint_exp_bom(t)
						 + maint_exp_eom(t)
					     + prem_tax(t)
						 + comm_trail_bom(t)
						 + comm_excess_bom(t)
					     + comm_trail_eom(t)
						 + comm_excess_eom(t)
					     - comm_chargeback(t)
					     - capzd_comm_bom(t)					
					     - capzd_comm_eom(t);
		
	return product_loads - def_loads - non_def_exp;
	#endif

	#if defined(__IUL_LIAB_H_)
	double product_loads = loads(t);
	double def_loads = deferred_loads(t);
	double non_def_exp = maint_exp_bom(t)
						 + maint_exp_eom(t)
					     + prem_tax(t)
						 + comm_trail_bom(t)
						 + comm_excess_bom(t)
					     + comm_trail_eom(t)
						 + comm_excess_eom(t)
					     - comm_chargeback(t)
					     - capzd_comm_bom(t)					
					     - capzd_comm_eom(t);
		
	return product_loads - def_loads - non_def_exp;
	#endif

	#if defined(__VA_LIAB_H_)
	double fees_and_charges = loads(t);
	double non_def_exp = maint_exp_bom(t)
		                 + maint_exp_eom(t)
						 + prem_tax(t)
						 + comm_trail_bom(t)
						 + comm_excess_bom(t)
					     + comm_trail_eom(t)
						 + comm_excess_eom(t)
						 - comm_chargeback(t)
					     - capzd_comm_bom(t)					
					     - capzd_comm_eom(t);
	
	return fees_and_charges - non_def_exp;
	#endif

	#if defined(__FA_LIAB_H_)
	double fa_loads = loads(t);
	double non_defer_exp = maint_exp_bom(t)
		                 + maint_exp_eom(t)
						 + prem_tax(t)
						 + comm_trail_bom(t)
						 + comm_excess_bom(t)
					     + comm_trail_eom(t)
						 + comm_excess_eom(t)
						 - comm_chargeback(t)
					     - capzd_comm_bom(t)					
					     - capzd_comm_eom(t);
	
	return fa_loads - non_defer_exp;
	#endif
	
	#if defined(__FIA_LIAB_H_)
	double fia_loads = loads(t);
	double non_defer_exp = maint_exp_bom(t)
		                 + maint_exp_eom(t)
						 + prem_tax(t)
						 + comm_trail_bom(t)
						 + comm_excess_bom(t)
					     + comm_trail_eom(t)
						 + comm_excess_eom(t)
						 - comm_chargeback(t)
					     - capzd_comm_bom(t)					
					     - capzd_comm_eom(t);
	
	return fia_loads - non_defer_exp;
	#endif
	}

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	double product_loads = 0.0;
	double def_loads = 0.0;
	double non_def_exp = 0.0;
	
	if (!reins_flag) //Gross
		{
		product_loads = loads(t);
		def_loads = deferred_loads(t);
	
		non_def_exp = maint_exp_bom(t) 
		            + maint_exp_eom(t)
				    + prem_tax(t)
					+ comm_trail_bom(t)
					+ comm_excess_bom(t)
					+ comm_trail_eom(t)
					+ comm_excess_eom(t)
				    - comm_chargeback(t)
					- capzd_comm_bom(t)					
					- capzd_comm_eom(t);
		}
	else if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		{
		product_loads = loads(t);
		def_loads = deferred_loads(t);
		
		non_def_exp = (maint_exp_bom(t) 
		               + maint_exp_eom(t))
					  + ul->reins_ea(t) 
					  - capzd_comm_bom(t)					
					  - capzd_comm_eom(t);
		}
	// else return 0.0 //Ceded and MP Not Reinsured
	
	return product_loads - def_loads - non_def_exp;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	double product_loads = 0.0;
	double def_loads = 0.0;
	double non_def_exp = 0.0;
	
	product_loads = loads(t);
	def_loads = deferred_loads(t);
	
	non_def_exp = maint_exp_bom(t) 
		        + maint_exp_eom(t)
				+ prem_tax(t)
				+ comm_trail_bom(t)
				+ comm_excess_bom(t)
				+ comm_trail_eom(t)
				+ comm_excess_eom(t)
				- comm_chargeback(t)
				- capzd_comm_bom(t)					
				- capzd_comm_eom(t);

	return product_loads - def_loads - non_def_exp;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	double product_loads = 0.0;
	double def_loads = 0.0;
	double non_def_exp = 0.0;
	
	product_loads = loads(t);
	def_loads = deferred_loads(t);
	
	non_def_exp = maint_exp_bom(t) 
		        + maint_exp_eom(t)
				+ prem_tax(t)
				+ comm_trail_bom(t)
				+ comm_excess_bom(t)
				+ comm_trail_eom(t)
				+ comm_excess_eom(t)
				- comm_chargeback(t)
				- capzd_comm_bom(t)					
				- capzd_comm_eom(t);

	return product_loads - def_loads - non_def_exp;
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	double fees_and_charges = 0.0;			
	double non_def_exp = 0.0;
	
	if (!reins_flag) //Gross
		{
		fees_and_charges = loads(t);
									
		non_def_exp = maint_exp_bom(t)
		            + maint_exp_eom(t)
					+ prem_tax(t)
					+ comm_trail_bom(t)
					+ comm_excess_bom(t)
					+ comm_trail_eom(t)
					+ comm_excess_eom(t)
					- comm_chargeback(t)
					- capzd_comm_bom(t)					
					- capzd_comm_eom(t);
		}
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		{
		fees_and_charges = loads(t);
									
		non_def_exp = maint_exp_bom(t)
		            + maint_exp_eom(t)
					+ prem_tax(t)
					+ comm_trail_bom(t)
					+ comm_excess_bom(t)
					+ comm_trail_eom(t)
					+ comm_excess_eom(t)
					- comm_chargeback(t)
					- capzd_comm_bom(t)					
					- capzd_comm_eom(t);
		}
	// else return 0.0 //Ceded and MP Not Reinsured
	
	return fees_and_charges - non_def_exp;
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	double fees_and_charges = 0.0;			
	double non_def_exp = 0.0;
	
	if (!reins_flag) //Gross
		{
		fees_and_charges = loads(t);
									
		non_def_exp = maint_exp_bom(t)
		            + maint_exp_eom(t)
					+ prem_tax(t)
					+ comm_trail_bom(t)
					+ comm_excess_bom(t)
					+ comm_trail_eom(t)
					+ comm_excess_eom(t)
					- comm_chargeback(t)
					- capzd_comm_bom(t)					
					- capzd_comm_eom(t);
		}
	else if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured
		{
		fees_and_charges = loads(t);
									
		non_def_exp = maint_exp_bom(t)
		            + maint_exp_eom(t)
					+ prem_tax(t)
					+ comm_trail_bom(t)
					+ comm_excess_bom(t)
					+ comm_trail_eom(t)
					+ comm_excess_eom(t)
					- comm_chargeback(t)
					- capzd_comm_bom(t)					
					- capzd_comm_eom(t);
		}
	// else return 0.0 //Ceded and MP Not Reinsured
	
	return fees_and_charges - non_def_exp;
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	double fees_and_charges = 0.0;			
	double non_def_exp = 0.0;
	
	if (!reins_flag) //Gross
		{
		fees_and_charges = loads(t);
									
		non_def_exp = maint_exp_bom(t)
		            + maint_exp_eom(t)
					+ prem_tax(t)
					+ comm_trail_bom(t)
					+ comm_excess_bom(t)
					+ comm_trail_eom(t)
					+ comm_excess_eom(t)
					- comm_chargeback(t)
					- capzd_comm_bom(t)					
					- capzd_comm_eom(t);
		}
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
		{
		fees_and_charges = loads(t);
									
		non_def_exp = maint_exp_bom(t)
		            + maint_exp_eom(t)
					+ prem_tax(t)
					+ comm_trail_bom(t)
					+ comm_excess_bom(t)
					+ comm_trail_eom(t)
					+ comm_excess_eom(t)
					- comm_chargeback(t)
					- capzd_comm_bom(t)					
					- capzd_comm_eom(t);
		}
	// else return 0.0 //Ceded and MP Not Reinsured
	
	return fees_and_charges - non_def_exp;
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - egp_gain_inv
// EGP Investment Gain                                                                                             
// Column:EGP_GAIN_INV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_inv(int t) {
//^^^



//^^^

#line 1 "egp_gain_inv.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	{
	//force call for reports
	credited_int(t);

	return sum_over_gaap("egp_gain_inv", t);
	}
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	double int_earned = inv_inc_fund(t) + cap_gain_fund(t);			
	double int_credited = credited_int(t);
	
	return int_earned - int_credited;		
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	double int_earned = inv_inc_fund(t) + cap_gain_fund(t);			
	double int_credited = credited_int(t);
	
	return int_earned - int_credited;		
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	double int_earned = inv_inc_fund(t) + cap_gain_fund(t);			
	double int_credited = credited_int(t);
	
	return int_earned - int_credited;		
	}
#endif
	
#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->fixed_spread(t)
			   + cap_gain_fund(t);
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->reins_fixed_spread(t)
			   + cap_gain_fund(t);		  
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	double int_earned = inv_inc_fund(t) + cap_gain_fund(t);			
	double int_credited = credited_int(t);
	
	return int_earned - int_credited;		
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	double int_earned = inv_inc_fund(t) + cap_gain_fund(t);			
	double int_credited = credited_int(t);
						 
	return int_earned - int_credited;   			
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - egp_gain_mort
// EGP Mortality Gain                                                                                             
// Column:EGP_GAIN_MORT
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_mort(int t) {
//^^^



//^^^

#line 1 "egp_gain_mort.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

double charges = 0.0;
double claim_cost = 0.0;

if (this == sfas97rd)
	{
	// use average SOP 03-1 benefits if running SFAS97RD valn.
	if (sfas97rd_valn_flag) 
		{
		charges = this->charges(t);

		#if defined(__UL_LIAB_H_)
		if (sop031_flag)
			claim_cost = sop031_array[DTH_CLAIM_COST][t];
		#endif
				
		#if defined(__VUL_LIAB_H_)
		if (sop031_flag)
			claim_cost = sop031_array[DTH_CLAIM_COST][t];
		#endif

		#if defined(__IUL_LIAB_H_)
		if (sop031_flag)
			claim_cost = sop031_array[DTH_CLAIM_COST][t];
		#endif

		#if defined(__VA_LIAB_H_)
		claim_cost = sop031_array[DB_BEN_SOP][t]
			         + sop031_array[IB_BEN_SOP][t]
					 + sop031_array[WB_BEN_SOP][t];
		#endif									

		if (sop031_flag)
			return charges - claim_cost;
		}

	return sum_over_gaap("egp_gain_mort", t);
	}
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	charges = this->charges(t);

	if (pricing_flag && sfas97rd_valn_flag) 
		{
		if (sop031_flag)
			claim_cost = sop031_array[DTH_CLAIM_COST][t];
		else
			claim_cost = dth_claim_cost(t);
		}
	else
		claim_cost = dth_claim_cost(t);	

	return charges - claim_cost;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	charges = this->charges(t);

	if (pricing_flag && sfas97rd_valn_flag) 
		{
		if (sop031_flag)
			claim_cost = sop031_array[DTH_CLAIM_COST][t];
		else
			claim_cost = dth_claim_cost(t);
		}
	else
		claim_cost = dth_claim_cost(t);	

	return charges - claim_cost;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	charges = this->charges(t);

	if (pricing_flag && sfas97rd_valn_flag) 
		{
		if (sop031_flag)
			claim_cost = sop031_array[DTH_CLAIM_COST][t];
		else
			claim_cost = dth_claim_cost(t);
		}
	else
		claim_cost = dth_claim_cost(t);	

	return charges - claim_cost;
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	// use average SOP 03-1 benefits if running SFAS97RD valn.
	if (pricing_flag && sfas97rd_valn_flag)
		{
		claim_cost = sop031_array[DB_BEN_SOP][t]
				 	+ sop031_array[IB_BEN_SOP][t]
				 	+ sop031_array[WB_BEN_SOP][t];
		}
	
	if (!reins_flag)
		{ //Gross
		charges = va->gmab_chg(t) 
				   + va->gmib_chg(t) 
				   + va->gmwb_chg(t) 
				   + va->gmdb_chg(t)
				   + va->eeb_chg(t);

		// capture actual single experience results if running GAAP financial projection				
		if (!sfas97rd_valn_flag && !valn_flag) 
			{
			claim_cost = va->maturity_claims_gmab(t) 
						+ gmdb_ben(t) 
						+ gmib_ben(t)
						+ gmwb_ben(t)
						+ va->dth_claims_eeb(t);
			}						
		}
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		{
		charges = va->reins_prem_gmab(t) 
				   + va->reins_prem_gmib(t) 
				   + va->reins_prem_gmwb(t) 
				   + va->reins_prem_gmdb(t)
				   + va->reins_prem_eeb(t);

		// capture actual single experience results if running GAAP financial projection				
		if (!sfas97rd_valn_flag && !valn_flag) 
			{
			claim_cost = va->reins_maturity_claims_gmab(t) 
						+ gmdb_ben(t) 
						+ gmib_ben(t)
						+ gmwb_ben(t)
						+ va->reins_dth_ben_eeb(t) ; // these columns should return the ceded claims portion
			}				
		}
	//else return 0.0 //Ceded and MP Not Reinsured
	return charges - claim_cost;	
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	return - dth_claim_cost(t);
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	double egp_excess_claims = 0.0;

	if (!reins_flag)
		{ //Gross
		double base = fia->dth_ben_inf_bef(t) - host_contract_val_bef(t);
		
		double dth_claims = base * fia->dth_claim_rate_mthly(t);

		egp_excess_claims = dth_claims;																
		}
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
		{
		double base = fia->dth_ben_inf_bef(t) - host_contract_val_bef(t);
		
		double dth_claims = base * fia->dth_claim_rate_mthly(t);
		egp_excess_claims = dth_claims * fia->reins_pct;
		}
	//else return 0.0 //Ceded and MP Not Reinsured
	return - egp_excess_claims;	
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - egp_gain_persist_bon_ref
// EGP Persistency Bonus/Refund Gain                                                                                             
// Column:EGP_GAIN_PERSIST_BON_REF
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_persist_bon_ref(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(77,"egp_gain_persist_bon_ref",t);
}



//^^^

#line 1 "egp_gain_persist_bon_ref.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
return - persist_bon_ref(t);

}


//@@ END

//@@ START - egp_gain_surr
// EGP Surrender Gain                                                                                             
// Column:EGP_GAIN_SURR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_surr(int t) {
//^^^



//^^^

#line 1 "egp_gain_surr.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("egp_gain_surr", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	double released_surr = max(0.0, ul->fund_released_surr(t));			
	double released_withdrl = max(0.0, ul->fund_released_withdrl(t));
	double released_maturities = max(0.0, ul->fund_released_maturity(t));
	double surr_gain = 0.0;
	double withdrl_gain = 0.0;
	double maturities_gain = 0.0;
	
	if (!reins_flag) //Gross
		{
		surr_gain = released_surr - ul->surr_benefits(t);
		withdrl_gain = released_withdrl - ul->withdrl_benefits(t);
		maturities_gain = released_maturities - ul->maturity_benefits(t);
		}							
	else if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		{		
		surr_gain = (released_surr - ul->surr_benefits(t)) * ul->reins_pct;
		withdrl_gain = (released_withdrl - ul->withdrl_benefits(t)) * ul->reins_pct;
		maturities_gain = (released_maturities - ul->maturity_benefits(t)) * ul->reins_pct;
		}
	// else return 0.0 //Ceded and MP Not Reinsured
	
	return surr_gain + withdrl_gain + maturities_gain;	
	}
#endif
	
#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	double released_surr = max(0.0, vul->fund_released_surr(t));			
	double released_withdrl = max(0.0, vul->fund_released_withdrl(t));
	double released_maturities = max(0.0, vul->fund_released_maturity(t));
	double surr_gain = 0.0;
	double withdrl_gain = 0.0;
	double maturities_gain = 0.0;
	
	if (!reins_flag) //Gross
		{
		surr_gain = released_surr - vul->surr_benefits(t);
		withdrl_gain = released_withdrl - vul->withdrl_benefits(t);
		maturities_gain = released_maturities - vul->maturity_benefits(t);
		}							
	else if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		{		
		surr_gain = (released_surr - vul->surr_benefits(t)) * vul->reins_pct;    
		withdrl_gain = (released_withdrl - vul->withdrl_benefits(t)) * vul->reins_pct;
		maturities_gain = (released_maturities - vul->maturity_benefits(t)) * vul->reins_pct;
		}
	// else return 0.0 //Ceded and MP Not Reinsured
	
	return surr_gain + withdrl_gain + maturities_gain;	
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	double released_surr = max(0.0, iul->fund_released_surr(t));			
	double released_withdrl = max(0.0, iul->fund_released_withdrl(t));
	double released_maturities = max(0.0, iul->fund_released_maturity(t));
	double surr_gain = 0.0;
	double withdrl_gain = 0.0;
	double maturities_gain = 0.0;
	
	if (!reins_flag) //Gross
		{
		surr_gain = released_surr - iul->surr_benefits(t);
		withdrl_gain = released_withdrl - iul->withdrl_benefits(t);
		maturities_gain = released_maturities - iul->maturity_benefits(t);
		}							
	else if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		{		
		surr_gain = (released_surr - iul->surr_benefits(t)) * iul->reins_pct;
		withdrl_gain = (released_withdrl - iul->withdrl_benefits(t)) * iul->reins_pct;
		maturities_gain = (released_maturities - iul->maturity_benefits(t)) * iul->reins_pct;
		}
	// else return 0.0 //Ceded and MP Not Reinsured
	
	return surr_gain + withdrl_gain + maturities_gain;	
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->surr_chg(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		{
		if (va->reins_coverage_defn == RIDER_ONLY)
			return 0.0;

		return va->surr_chg(t) * va->reins_pct;
		}	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fa->surr_chg(t);
	
	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured
		return fa->surr_chg(t) * fa->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	double egp_excess_claims = 0.0;
	double egp_excess_claims_lapse = 0.0;
	double egp_excess_claims_withdrl = 0.0;
	
	double base = fia->dth_ben_inf_bef(t) - host_contract_val_bef(t);
	
	egp_excess_claims_lapse = base * (1 - fia->dth_claim_rate_mthly(t))
							  * (fia->lapse_rate_mthly(t)
						         + fia->annuitzn_rate_mthly(t));
						
	egp_excess_claims_withdrl = (base * (1 - fia->dth_claim_rate_mthly(t))
									 - egp_excess_claims_lapse)
									* fia->pfwd_rate_mthly_fund_val(t);
						
	egp_excess_claims = egp_excess_claims_lapse + egp_excess_claims_withdrl;
	
	if (!reins_flag)
		{ //Gross
		return - egp_excess_claims;																
		}
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
		{
		return - egp_excess_claims * fia->reins_pct;				
		}
	//else return 0.0 //Ceded and MP Not Reinsured
	return 0.0;		
	}
#endif	
	
return NO_AVG;

}


//@@ END

//@@ START - egp_pv
// EGP Present Value                                                                                             
// Column:EGP_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_pv(int t) {
//^^^



//^^^

#line 1 "egp_pv.SFAS97RD_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;
	
return (egp(t + 1) + egp_pv(t + 1))
	   / (1.0 + gaap_amortzn_int_rate(t + 1));

}


//@@ END

//@@ START - egp_pv_loss_rec_int_rate
// EGP Present Value At Loss Recognition Interest Rate                                                                                             
// Column:EGP_PV_LOSS_REC_INT_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_pv_loss_rec_int_rate(int t) {
//^^^



//^^^

#line 1 "egp_pv_loss_rec_int_rate.SFAS97RD_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;
	
return (egp(t + 1) + egp_pv_loss_rec_int_rate(t + 1))
	   / (1.0 + loss_rec_amortzn_int_rate(t + 1));

}


//@@ END

//@@ START - egp_sop031_assess_accum
// EGP SOP 03-1 Assessments Accumulation                                                                                             
// Column:EGP_SOP031_ASSESS_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_assess_accum(int t) {
//^^^



//^^^

#line 1 "egp_sop031_assess_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period || !sop031_flag)
	return NO_AVG;

if (t == start_period) 
	return sop031_assess_accum(t); 

#if defined(__UL_LIAB_H_) // assessments for UL are net of the approximate change in URL
return sop031_array[ASSESS_SOP][t] 
       - sop031_unearn_rev_liab_incr(t)
   	+ egp_sop031_assess_accum(t - 1) 
   	 * (1.0 + gaap_amortzn_int_rate(t));
#endif

#if defined(__VUL_LIAB_H_) // assessments for VUL are net of the approximate change in URL
return sop031_array[ASSESS_SOP][t] 
       - sop031_unearn_rev_liab_incr(t)
   	+ egp_sop031_assess_accum(t - 1) 
   	 * (1.0 + gaap_amortzn_int_rate(t));
#endif

#if defined(__IUL_LIAB_H_) // assessments for IUL are net of the approximate change in URL
return sop031_array[ASSESS_SOP][t] 
       - sop031_unearn_rev_liab_incr(t)
   	+ egp_sop031_assess_accum(t - 1) 
   	 * (1.0 + gaap_amortzn_int_rate(t));
#endif

#if defined(__VA_LIAB_H_)
return sop031_array[ASSESS_SOP][t] 
   	+ egp_sop031_assess_accum(t - 1) 
   	 * (1.0 + gaap_amortzn_int_rate(t));
#endif

return NO_AVG;

}


//@@ END

//@@ START - egp_sop031_gmdb_ben_accum
// EGP SOP 03-1 GMDB Benefits Accumulation                                                                                             
// Column:EGP_SOP031_GMDB_BEN_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmdb_ben_accum(int t) {
//^^^



//^^^

#line 1 "egp_sop031_gmdb_ben_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	return sop031_gmdb_ben_accum(t);

return sop031_array[DB_BEN_SOP][t] 
	   + egp_sop031_gmdb_ben_accum(t - 1) 
	     * (1.0 + gaap_amortzn_int_rate(t));

}


//@@ END

//@@ START - egp_sop031_gmdb_liab
// EGP SOP 03-1 GMDB Liability                                                                                             
// Column:EGP_SOP031_GMDB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmdb_liab(int t) {
//^^^



//^^^

#line 1 "egp_sop031_gmdb_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return max(0.0 , egp_sop031_assess_accum(t) * sop031_gmdb_br(0) 
				 - egp_sop031_gmdb_ben_accum(t));

}


//@@ END

//@@ START - egp_sop031_gmib_ben_accum
// EGP SOP 03-1 GMIB Benefits Accumulation                                                                                             
// Column:EGP_SOP031_GMIB_BEN_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmib_ben_accum(int t) {
//^^^



//^^^

#line 1 "egp_sop031_gmib_ben_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	return sop031_gmib_ben_accum(t);

return sop031_array[IB_BEN_SOP][t]
		+ egp_sop031_gmib_ben_accum(t - 1)
		  * (1.0 + gaap_amortzn_int_rate(t));

}


//@@ END

//@@ START - egp_sop031_gmib_liab
// EGP SOP 03-1 GMIB Liability                                                                                             
// Column:EGP_SOP031_GMIB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmib_liab(int t) {
//^^^



//^^^

#line 1 "egp_sop031_gmib_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return max(0.0 , egp_sop031_assess_accum(t) * sop031_gmib_br(0) 
				 - egp_sop031_gmib_ben_accum(t));

}


//@@ END

//@@ START - egp_sop031_gmwb_ben_accum
// EGP SOP 03-1 GMWB Benefit Accumulation                                                                                             
// Column:EGP_SOP031_GMWB_BEN_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmwb_ben_accum(int t) {
//^^^



//^^^

#line 1 "egp_sop031_gmwb_ben_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	return sop031_gmwb_ben_accum(t);

return sop031_array[WB_BEN_SOP][t]
		+ egp_sop031_gmwb_ben_accum(t - 1)
		  * (1.0 + gaap_amortzn_int_rate(t));

}


//@@ END

//@@ START - egp_sop031_gmwb_liab
// EGP SOP 03-1 GMWB Liability                                                                                             
// Column:EGP_SOP031_GMWB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmwb_liab(int t) {
//^^^



//^^^

#line 1 "egp_sop031_gmwb_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return max(0.0 , egp_sop031_assess_accum(t) * sop031_gmwb_br(0) 
				 - egp_sop031_gmwb_ben_accum(t));

}


//@@ END

//@@ START - egp_sop031_res_incr
// EGP SOP 03-1 Reserve Increase                                                                                             
// Column:EGP_SOP031_RES_INCR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_res_incr(int t) {
//^^^



//^^^

#line 1 "egp_sop031_res_incr.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (sfas97rd_valn_flag && valn_flag)
	{
	if (t == start_period)
		return 0.0;
 
	double egp_sop031_res_incr_initial = 0.0;
 
	#if defined(__UL_LIAB_H_)
	egp_sop031_res_incr_initial 
	= (egp_sop031_ulsg_liab(t) - egp_sop031_ulsg_liab(t - 1))
	   + (sop031_pbr_liab(t) - sop031_pbr_liab(t - 1));
	#endif
 
	#if defined(__VUL_LIAB_H_)
	egp_sop031_res_incr_initial 
	= (egp_sop031_gmdb_liab(t) - egp_sop031_gmdb_liab(t - 1))
	   + (sop031_pbr_liab(t) - sop031_pbr_liab(t - 1));
	#endif

	#if defined(__IUL_LIAB_H_)
	egp_sop031_res_incr_initial 
	= (egp_sop031_ulsg_liab(t) - egp_sop031_ulsg_liab(t - 1));
	#endif

	#if defined(__VA_LIAB_H_)
	egp_sop031_res_incr_initial
	= (egp_sop031_gmdb_liab(t) - egp_sop031_gmdb_liab(t - 1))
	   + (egp_sop031_gmib_liab(t) - egp_sop031_gmib_liab(t - 1))
	   + (egp_sop031_gmwb_liab(t) - egp_sop031_gmwb_liab(t - 1));
	#endif

	return egp_sop031_res_incr_initial;
	}

return NO_AVG;

}


//@@ END

//@@ START - egp_sop031_ulsg_ben_accum
// EGP SOP 03-1 ULSG Benefits Accumulation                                                                                             
// Column:EGP_SOP031_ULSG_BEN_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_ulsg_ben_accum(int t) {
//^^^



//^^^

#line 1 "egp_sop031_ulsg_ben_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period || sop031_ul_vul_iul_defn == NO)
	return NO_AVG;

if (t == start_period)
	return sop031_ulsg_ben_accum(t);

return sop031_array[SG_BEN_SOP][t]
		+ egp_sop031_ulsg_ben_accum(t - 1)
		  * (1.0 + gaap_amortzn_int_rate(t));

}


//@@ END

//@@ START - egp_sop031_ulsg_liab
// EGP SOP 03-1 ULSG Benefits Liability                                                                                             
// Column:EGP_SOP031_ULSG_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_ulsg_liab(int t) {
//^^^



//^^^

#line 1 "egp_sop031_ulsg_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return max(0.0, egp_sop031_assess_accum(t) * sop031_ulsg_br(0) 
                - egp_sop031_ulsg_ben_accum(t));

}


//@@ END

//@@ START - embed_deriv_cash_flow
// Embedded derivative cash flow                                                                                             
// Column:EMBED_DERIV_CASH_FLOW
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_embed_deriv_cash_flow(int t) {
//^^^



//^^^

#line 1 "embed_deriv_cash_flow.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("embed_deriv_cash_flow", t);

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return iul->dth_benefits(t)
		       + iul->surr_benefits(t)
			   + iul->maturity_benefits(t)
			   + iul->withdrl_benefits(t);
	
	else if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured
		return iul->reins_dth_benefits(t)
		       + iul->reins_surr_benefits(t)
			   + iul->reins_maturity_benefits(t)
			   + iul->reins_withdrl_benefits(t);
	
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif





#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	double cf_base = max(0, fia->fund_val_fixed(t) - fia->min_contract_val(t));
	
	if (!reins_flag) //Gross
		return cf_base * (1.0 - fia->surv_period(t));
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
		return cf_base * (1.0 - fia->surv_period(t)) * fia->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - embed_deriv_cash_flow_pv
// Present value embedded derivative cash flow                                                                                             
// Column:EMBED_DERIV_CASH_FLOW_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_embed_deriv_cash_flow_pv(int t) {
//^^^



//^^^

#line 1 "embed_deriv_cash_flow_pv.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

double spot_rate = rates->get_int_rate(t, "Govt", GET_SPOT_RATE, SHORT_TERM_RATE_TERM, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

double disc_factor = 1.0 / pow(1.0 + spot_rate, t / 12.0);

return embed_deriv_cash_flow_pv(t + 1) 
       + embed_deriv_cash_flow(t) * disc_factor;

}


//@@ END

//@@ START - embed_deriv_val
// Embedded derivative value                                                                                             
// Column:EMBED_DERIV_VAL
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_embed_deriv_val(int t) {
//^^^



//^^^

#line 1 "embed_deriv_val.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	{
	double fund_val_current = 0.0;
	double fund_val_previous1 = model_point_amount_threshold;
	double fund_val_previous2 = model_point_amount_threshold;
	int mp = 0;
	map <int, long, less <int> > ::iterator mp_map_iter;//Gen2 - 9/6/2024 - replace mpmap with full definition
	
	#if defined(__FIA_LIAB_H_)
	if (fia_mp_map.size())
		{
		FIA_LIAB *current_fia_element;

		for (mp_map_iter = fia_mp_map.begin(); 
		     mp_map_iter !=fia_mp_map.end(); 
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
	
			if ((t - 1) >= start_period)
				{
				fund_val_previous1 += current_fia_element->Column("fund_val_b_bef").Value(t);
				fund_val_previous2 += current_fia_element->Column("fund_val_fixed").Value(t - 1);
				}
	
			fund_val_current += current_fia_element->Column("fund_val_fixed").Value(t);
			}
		}
	#endif

	if (fund_val_previous1 <= model_point_amount_threshold)
		return 0.0;
			
	if (t == start_period
		|| (nb_flag && t == start_period + 1
			&& valn_period == 0))
		{	
		if (sfas97rd_valn_flag)
			return embed_deriv_cash_flow_pv(t);
		
		if (nb_flag 
			&& t == start_period + 1
			&& valn_period == 0
			&& fund_val_current > model_point_amount_threshold)
			return embed_deriv_cash_flow_pv(0)
   			    / fund_val_previous1
                   * fund_val_current;

		if (valn_period == 0)
			return gaap_schedule[EMBED_DERIV_VAL][0];	
			
		return init_embed_deriv_val;
		}

	if (sfas97rd_valn_flag)
		return NO_AVG;
	
	if (fabs(fund_val_current) < model_point_amount_threshold)
		return NO_AVG;

	if (t == start_period + 1 && valn_period > 0)
		return gaap_schedule[EMBED_DERIV_VAL][0]
   			   / fund_val_previous2
               * fund_val_current;

	return embed_deriv_val(t - 1) 
		   / fund_val_previous2
		   * fund_val_current;
	}

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (pricing_flag && t == start_period
			&& valn_period == 0)
		return NO_AVG;
	
	if (fia->fia->fund_val_b_bef(t) <= model_point_amount_threshold)
			return 0.0;
	
	if (t == start_period
		|| (pricing_flag && t == start_period + 1
			&& valn_period == 0))
		{
		if (sfas97rd_valn_flag )
			return embed_deriv_cash_flow_pv(t);
			
		if (pricing_flag && t == start_period + 1
			&& valn_period == 0)
			return embed_deriv_cash_flow_pv(0)
   			   	 / fia->fund_val_b_bef(t)
                   	* fia->fund_val_fixed(t);	
		
		if (valn_period == 0)
			return gaap_schedule[EMBED_DERIV_VAL][0];	
			
		return init_embed_deriv_val;	
		}
	
	
	if (sfas97rd_valn_flag)
		return NO_AVG;
	
	if (t == start_period + 1 && valn_period > 0)
		return gaap_schedule[EMBED_DERIV_VAL][0]
   			    / fia->fund_val_fixed(t - 1)
                   * fia->fund_val_fixed(t);
	
	return embed_deriv_val(t - 1) 
			/ fia->fund_val_fixed(t - 1)
			* fia->fund_val_fixed(t);
	
    }
#endif

return NO_AVG;

}


//@@ END

//@@ START - finalize
// Finalize                                                                                             
// Column:FINALIZE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.SFAS97RD_GAAP.for"
if (time_step_flag && !valn_flag)
	write_state_of_world_financial();

return 1.0;

}


//@@ END

//@@ START - fund_val
// Fund Value Total                                                                                             
// Column:FUND_VAL
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_fund_val(int t) {
//^^^



//^^^

#line 1 "fund_val.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return fund_val_fixed(t)
       + fund_val_sa(t);

}


//@@ END

//@@ START - fund_val_bef_int
// Fund Value Before Interest                                                                                             
// Column:FUND_VAL_BEF_INT
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_fund_val_bef_int(int t) {
//^^^



//^^^

#line 1 "fund_val_bef_int.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("fund_val_bef_int", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag) //Gross
		{
		if (ul->neg_fund_crediting_defn == NO
			|| t > ul->emo_period)
			return max(0.0, ul->sm_ul_ifund_curr->fund_val_bef_int(t))
		       * ul->units_inf(t - 1);
		
		// else if (ul->neg_fund_crediting_defn == YES)
		return ul->sm_ul_ifund_curr->fund_val_bef_int(t) 
		       * ul->units_inf(t - 1);
		}
	else if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured
		{
		if (ul->neg_fund_crediting_defn == NO
			|| t > ul->emo_period)
			return max(0.0, ul->sm_ul_ifund_curr->fund_val_bef_int(t))
			       * ul->units_inf(t - 1)
			       * ul->reins_pct;
		
		// else if (ul->neg_fund_crediting_defn == YES)
		return ul->sm_ul_ifund_curr->fund_val_bef_int(t) 
		       * ul->units_inf(t - 1)
		       * ul->reins_pct;
		}
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) //Gross
		{
		if (vul->neg_fund_crediting_defn == NO
			|| t > vul->emo_period)
			{
			// consider negative unloaned fund only
			return (vul->pol_loan_per_unit(t - 1) 
			        + max(0.0, vul->sm_vul_ifund_curr->fund_val_bef_int(t)
			                   - vul->pol_loan_per_unit(t - 1)))
		           * vul->units_inf(t - 1);
			}
		// else if (vul->neg_fund_crediting_defn == YES)
		return vul->sm_vul_ifund_curr->fund_val_bef_int(t) 
		       * vul->units_inf(t - 1);
		}
		
	else if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured
		{
		if (vul->neg_fund_crediting_defn == NO
			|| t > vul->emo_period)
			{
			// consider negative unloaned fund only			
			return (vul->pol_loan_per_unit(t - 1)
			        + max(0.0, vul->sm_vul_ifund_curr->fund_val_bef_int(t)
						       - vul->pol_loan_per_unit(t - 1)))
			       * vul->units_inf(t - 1)
			       * vul->reins_pct;
			}
		// else if (vul->neg_fund_crediting_defn == YES)
		return vul->sm_vul_ifund_curr->fund_val_bef_int(t) 
		       * vul->units_inf(t - 1)
		       * vul->reins_pct;
		}
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag) //Gross
		{
		if (iul->neg_fund_crediting_defn == NO
			|| t > iul->emo_period)
			return max(0.0, iul->sm_iul_ifund_curr->fund_val_bef_int(t))
		           * iul->units_inf(t - 1);
		
		// else if (iul->neg_fund_crediting_defn == YES)
		return iul->sm_iul_ifund_curr->fund_val_bef_int(t) 
		       * iul->units_inf(t - 1);
		}
	else if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured
		{
		if (iul->neg_fund_crediting_defn == NO
			|| t > iul->emo_period)
			return max(0.0, iul->sm_iul_ifund_curr->fund_val_bef_int(t))
			       * iul->units_inf(t - 1)
			       * iul->reins_pct;
		
		// else if (iul->neg_fund_crediting_defn == YES)
		return iul->sm_iul_ifund_curr->fund_val_bef_int(t) 
		       * iul->units_inf(t - 1)
		       * iul->reins_pct;
		}
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	if (!reins_flag) //Gross
		return va->fund_val_b(t);
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->fund_val_b(t) 
				* va->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	if (!reins_flag) //Gross
		return fa->fund_val_b(t);
	else if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured
		return fa->fund_val_b(t) 
				* fa->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	if (!reins_flag) //Gross
		return fia->fund_val_b(t);
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
		return fia->fund_val_b(t) 
				* fia->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
#endif

return NO_AVG;

}


//@@ END

//@@ START - fund_val_fixed
// Fund Value Fixed                                                                                             
// Column:FUND_VAL_FIXED
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_fund_val_fixed(int t) {
//^^^



//^^^

#line 1 "fund_val_fixed.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

// force call fund_val_sa for reporting
fund_val_sa(t);

if (this == sfas97rd)
	return sum_over_gaap("fund_val_fixed", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return max(0.0, ul->fund_val_fixed(t));
	else if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured	
		return max(0.0, ul->fund_val_fixed(t)) * ul->reins_pct;		
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}	
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return vul->pol_loan(t) 
		       + max(0.0, vul->fund_val_fixed(t) - vul->pol_loan(t));
	else if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured	
		return (vul->pol_loan(t) 
		        + max(0.0, vul->fund_val_fixed(t) - vul->pol_loan(t)))
		       * vul->reins_pct;		
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}	
#endif

// Use SFAS97 treatment until SFAS133 methodology is implemented
#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return max(0.0, iul->fund_val_fixed(t));
	else if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured	
		return max(0.0, iul->fund_val_fixed(t)) * iul->reins_pct;		
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}	
#endif
	
#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->fund_val_fixed(t);
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->fund_val_fixed(t) * va->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fa->fund_val_fixed(t);
	else if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured
		return fa->fund_val_fixed(t) * fa->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	return 0.0;	
#endif

return NO_AVG;

}


//@@ END

//@@ START - fund_val_sa
// Fund Value Separate Account                                                                                             
// Column:FUND_VAL_SA
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_fund_val_sa(int t) {
//^^^



//^^^

#line 1 "fund_val_sa.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("fund_val_sa", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	return NO_AVG;
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return vul->fund_val_sa(t);
	else if (reins_flag && vul->reins_flag) //Ceded and MP Reinsured
		return vul->fund_val_sa(t)
				* vul->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif
	
#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->fund_val_sa(t);
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->fund_val_sa(t)
				* va->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - gaap_amortzn_int_rate
// GAAP Amortization Interest Rate                                                                                             
// Column:GAAP_AMORTZN_INT_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_gaap_amortzn_int_rate(int t) {
//^^^



//^^^

#line 1 "gaap_amortzn_int_rate.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return gaap_int_rate_mthly;

}


//@@ END

//@@ START - gmab_ben
// GMAB Benefits                                                                                             
// Column:GMAB_BEN
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmab_ben(int t) {
//^^^



//^^^

#line 1 "gmab_ben.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("gmab_ben", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	return NO_AVG;
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->maturity_claims_gmab(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->reins_maturity_claims_gmab(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - gmdb_ben
// GMDB Benefits                                                                                             
// Column:GMDB_BEN
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmdb_ben(int t) {
//^^^



//^^^

#line 1 "gmdb_ben.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("gmdb_ben", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	return NO_AVG;
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (vul->gmdb_defn == NOT_APPLICABLE
		|| t > vul->gmdb_ben_term_period + 1
		|| vul->gmdb_mths_in_grace_period(t - 1) >= vul->gmdb_grace_period_mths)
	
	if ((vul->fund_val(t) < model_point_amount_threshold
		|| vul->fund_val(t) < vul->dth_benefits_base_plan(t))
		&& vul->dth_ben_per_unit(t) > model_point_amount_threshold)
		{
		if (!reins_flag) //Gross 
			return vul->dth_benefits_base_plan(t) 
			       - (vul->pol_loan(t)                  // consider negative unloaned fund only
			          + max(0.0, vul->fund_val(t) - vul->pol_loan(t)));
		else if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured via Coinsurance
			return (vul->dth_benefits_base_plan(t) 
			        - (vul->pol_loan(t)                 // consider negative unloaned fund only
			           + max(0.0, vul->fund_val(t) - vul->pol_loan(t))))
			        * vul->reins_pct;

		 //Ceded and MP Not Reinsured
		return 0.0;	
		}
	return 0.0;	
	}	
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->dth_claims_gmdb(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->reins_dth_ben_gmdb(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - gmib_ben
// GMIB Benefits                                                                                             
// Column:GMIB_BEN
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmib_ben(int t) {
//^^^



//^^^

#line 1 "gmib_ben.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("gmib_ben", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	return NO_AVG;
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->ann_claims_gmib(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->reins_ann_claims_gmib(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}	
#endif

return NO_AVG;

}


//@@ END

//@@ START - gmwb_ben
// GMWB Benefits                                                                                             
// Column:GMWB_BEN
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmwb_ben(int t) {
//^^^



//^^^

#line 1 "gmwb_ben.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("gmwb_ben", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	return NO_AVG;
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->ann_claims_gmwb(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->reins_ann_claims_gmwb(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - hedge_cash_flow
// Hedge Cash Flow                                                                                             
// Column:HEDGE_CASH_FLOW
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_cash_flow(int t) {
//^^^



//^^^

#line 1 "hedge_cash_flow.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t <= start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

if (this == sfas97rd)
	{
	#if defined(__FIA_LIAB_H_) || defined(__IUL_LIAB_H_)
	return sum_over_gaap("hedge_cash_flow", t);
	#endif
	
	if (reins_flag)
		return (seg->hedge_gross_array[HEDGE_CASH_FLOW][t]
		        - seg->hedge_net_array[HEDGE_CASH_FLOW][t])
		        * hedge_alloc_factor;
		
	return seg->hedge_gross_array[HEDGE_CASH_FLOW][t]
	       * hedge_alloc_factor;
	}

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	return NO_AVG;
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	// Need to allocate hedge cash flows from hedge group into model point like FIA

	return NO_AVG;
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (reins_flag)
		return (va->hedge_gross_array[HEDGE_CASH_FLOW][t]
		        - va->hedge_net_array[HEDGE_CASH_FLOW][t])
		        * hedge_alloc_factor;
		
	return va->hedge_gross_array[HEDGE_CASH_FLOW][t]
	       * hedge_alloc_factor;
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd && !fia->isMainModel)
	{
	double hedge_grp_fund_val = 0.0;
	double fia_mp_hedge_amt = 0.0;
	
	for (int hedge_group = 0; hedge_group < fia->seg->hedge_grps.size(); hedge_group++)
		{
		xstring hedge_grp_name = fia->seg->hedge_grps[hedge_group];
		double fia_mp_fund_val = 0.0;
		
		for (int account = 0; account < fia->sm_fia_account.size(); account++)
			{
			if (fia->sm_fia_account[account]->hedge_grp_code == hedge_grp_name)
				fia_mp_fund_val += fia->sm_fia_account[account]->fund_val_e(t);
			}
		
		hedge_grp_fund_val = fia->seg->sm_hedge_grp[hedge_group]->fund_val_fixed(t);
		
		if (hedge_grp_fund_val > model_point_amount_threshold)
			fia_mp_hedge_amt += fia->seg->sm_hedge_grp[hedge_group]->hedge_cash_flow(t) 
						   	    * fia_mp_fund_val / hedge_grp_fund_val;
		else 
			fia_mp_hedge_amt = 0.0;
		}
		
	if (reins_flag)
		return fia_mp_hedge_amt * fia->reins_pct;
		
	return fia_mp_hedge_amt;
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - hedge_cost
// Hedge Cost                                                                                             
// Column:HEDGE_COST
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_cost(int t) {
//^^^



//^^^

#line 1 "hedge_cost.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*!alm_flag || valn_flag || */t <= start_period || t > final_period)
	return NO_AVG;
	
if (!alm_flag || valn_flag)
	return NO_AVG;

return - (hedge_cash_flow(t)
          + hedge_mkt_val_incr(t));

}


//@@ END

//@@ START - hedge_mkt_val
// Hedge Market Value                                                                                             
// Column:HEDGE_MKT_VAL
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

if (this == sfas97rd)
	{
	#if defined(__FIA_LIAB_H_) || defined(__IUL_LIAB_H_)
	return sum_over_gaap("hedge_mkt_val", t);
	#endif
	
	if (reins_flag)
		return (seg->hedge_gross_array[HEDGE_MKT_VAL][t]
		        - seg->hedge_net_array[HEDGE_MKT_VAL][t])
		        * hedge_alloc_factor;
		
	return seg->hedge_gross_array[HEDGE_MKT_VAL][t]
	       * hedge_alloc_factor;
	}

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	return NO_AVG;
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	return NO_AVG;
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd && !iul->isMainModel)
	{
	// Need to allocate hedge market value to model point like FIA

	return NO_AVG;
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (reins_flag)
		return (va->hedge_gross_array[HEDGE_MKT_VAL][t]
		        - va->hedge_net_array[HEDGE_MKT_VAL][t])
		        * hedge_alloc_factor;
		
	return va->hedge_gross_array[HEDGE_MKT_VAL][t]
	       * hedge_alloc_factor;
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd && !fia->isMainModel)
	{
	double hedge_grp_fund_val = 0.0;
	double fia_mp_hedge_amt = 0.0;
	
	for (int hedge_group = 0; hedge_group < fia->seg->hedge_grps.size(); hedge_group++)
		{
		xstring hedge_grp_name = fia->seg->hedge_grps[hedge_group];
		double fia_mp_fund_val = 0.0;
		
		for (int account = 0; account < fia->sm_fia_account.size(); account++)
			{
			if (fia->sm_fia_account[account]->hedge_grp_code == hedge_grp_name)
				fia_mp_fund_val += fia->sm_fia_account[account]->fund_val_e(t);
			}
		
		hedge_grp_fund_val = fia->seg->sm_hedge_grp[hedge_group]->fund_val_fixed(t);
		
		if (hedge_grp_fund_val > model_point_amount_threshold)
			fia_mp_hedge_amt += fia->seg->sm_hedge_grp[hedge_group]->hedge_mkt_val(t) 
						  	    * fia_mp_fund_val / hedge_grp_fund_val;
		else 
			fia_mp_hedge_amt = 0.0;
		}
		
	if (reins_flag)
		return fia_mp_hedge_amt * fia->reins_pct;
		
	return fia_mp_hedge_amt;
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - hedge_mkt_val_incr
// Hedge Market Value Increase                                                                                             
// Column:HEDGE_MKT_VAL_INCR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_mkt_val_incr(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val_incr.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t <= start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;
	
return hedge_mkt_val(t)
       - hedge_mkt_val(t - 1);

}


//@@ END

//@@ START - host_contract_cred_int
// Host Contract Credited Interest                                                                                             
// Column:HOST_CONTRACT_CRED_INT
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_host_contract_cred_int(int t) {
//^^^



//^^^

#line 1 "host_contract_cred_int.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("host_contract_cred_int", t);

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	return host_contract_val(t - 1) 
		   * (pow(1.0 + host_accrual_rate , 1.0 / 12.0) - 1.0);
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	return host_contract_val(t - 1) 
		   * (pow(1.0 + host_accrual_rate , 1.0 / 12.0) - 1.0);
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - host_contract_val
// Host Contract Value                                                                                             
// Column:HOST_CONTRACT_VAL
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_host_contract_val(int t) {
//^^^



//^^^

#line 1 "host_contract_val.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("host_contract_val", t);

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	double dth_claims = host_contract_val_bef(t) * fia->dth_claim_rate_mthly(t);
	
	double lapse_claims 
	= (host_contract_val_bef(t)- dth_claims)
  	* (fia->annuitzn_rate_mthly(t)  
     	+ fia->lapse_rate_mthly(t));
	
	double withdrl_claims = 0.0;
	
	if (!reins_flag) //Gross
		{
		withdrl_claims = fia->withdrl_benefits(t);
		
		return host_contract_val_bef(t) - dth_claims - lapse_claims - withdrl_claims;
		}
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
		{
		withdrl_claims = fia->withdrl_benefits(t) * fia->reins_pct;
		
		return host_contract_val_bef(t) - dth_claims - lapse_claims - withdrl_claims;
		}
	else //Ceded and MP Not Reinsured
		return 0.0;
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - host_contract_val_bef
// Host Contract Value - Before Decrements                                                                                             
// Column:HOST_CONTRACT_VAL_BEF
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_host_contract_val_bef(int t) {
//^^^



//^^^

#line 1 "host_contract_val_bef.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("host_contract_val_bef", t);

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	double host_value_bef = 0.0;
	
	if (t == fia->commencement_period)
		{
		if (fia->elapsed_mths > 0)
			{
			host_value_bef = fia->init_host_val;
			}
		else // if (elapsed_mths <= 0)
			host_value_bef = 0.0;
		
		if (!reins_flag) //Gross
			return host_value_bef;
		else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
			return host_value_bef * fia->reins_pct;
		else //Ceded and MP Not Reinsured
			return 0.0;		
		}
	
	if (fia->elapsed_mths <= 0 && t == fia->commencement_period + 1) 
		{
		if (!reins_flag) //Gross
			{
			host_value_bef = fia->prem_paid(t) - embed_deriv_val(t);
			return host_value_bef;
			}
		else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
			{
			host_value_bef = fia->prem_paid(t) * fia->reins_pct - embed_deriv_val(t);
			return host_value_bef;
			}
		else //Ceded and MP Not Reinsured
			return 0.0;
		}

	return host_contract_val(t - 1) 
		   * pow(1.0 + host_accrual_rate, 1.0 /12.0);
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.SFAS97RD_GAAP.for"
if (this != sfas97rd)
	{
	#if defined(__UL_LIAB_H_)
	if (ul->isMainModel)
		{
		if (!reins_flag)
			{
			if (ul->coins_flag) 
				cohort_reins_indicator = 1;
			else 
				cohort_reins_yrt_indicator = 1;							
			}	

		if (!valn_flag)
			get_gaap_schedule_items();
	
		if (valn_period > 0)
			read_state_of_world_financial();
		}
	#endif

	#if defined(__VUL_LIAB_H_)
	if (vul->isMainModel)
		{
		if (!reins_flag)
			{
			if (vul->coins_flag) 
				cohort_reins_indicator = 1;
			else 
				cohort_reins_yrt_indicator = 1;							
			}	

		if (!valn_flag)
			get_gaap_schedule_items();
	
		if (valn_period > 0)
			read_state_of_world_financial();
		}
	#endif

	#if defined(__IUL_LIAB_H_)
	if (iul->isMainModel)
		{
		if (!reins_flag)
			{
			if (iul->coins_flag) 
				cohort_reins_indicator = 1;
			else 
				cohort_reins_yrt_indicator = 1;							
			}	

		if (!valn_flag)
			get_gaap_schedule_items();
	
		if (valn_period > 0)
			read_state_of_world_financial();
		}
	#endif

	#if defined(__VA_LIAB_H_)
	if (va->isMainModel)
		{
		if (!valn_flag)
			get_gaap_schedule_items();
	
		if (valn_period > 0)
			read_state_of_world_financial();
		}
	#endif

	#if defined(__FA_LIAB_H_)
	if (fa->isMainModel)
		{
		if (!valn_flag)
			get_gaap_schedule_items();
	
		if (valn_period > 0)
			read_state_of_world_financial();
		}
	#endif

	#if defined(__FIA_LIAB_H_)
	if (fia->isMainModel)
		{
		if (!valn_flag)
			get_gaap_schedule_items();
	
		if (valn_period > 0)
			read_state_of_world_financial();
		}
	#endif

	return 1.0;
	}	

// else (this == sfas97rd)

// clear elements from maps
ul_mp_map.clear();
vul_mp_map.clear();
iul_mp_map.clear();
va_mp_map.clear();
fa_mp_map.clear();
fia_mp_map.clear();
epl_mp_map.clear();

// dimension 0 - getElementNumber(0) refers to cohort group
// dimension 1 - getElementNumber(1) refers to reinsurance definition
int cohort_col = getElementNumber(0); 
int cohort_mp_count = 0;
int mp = 0;
map <int, long, less <int> > ::iterator mp_map_iter;//Gen2 - 9/6/2024 - replace mpmap with full definition

// initialize cohort_first_issue_period, cohort_last_issue_period and cohort_max_maturity_period
if (reins_flag)
	{
	cohort_first_issue_period 
	= seg->sm_sfas97rd[getElementNumber(0)][0]->cohort_first_issue_period;

	cohort_last_issue_period 
	= seg->sm_sfas97rd[getElementNumber(0)][0]->cohort_last_issue_period;

	cohort_max_maturity_period 
	= seg->sm_sfas97rd[getElementNumber(0)][0]->cohort_max_maturity_period;
	}

// Set GAAP History Table for Gross or Ceded Business
#if defined(__UL_LIAB_H_)
for (mp_map_iter = seg->ul_mp_map.begin();
	 mp_map_iter != seg->ul_mp_map.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	xstring mp_cohort_gross = liab->sm_ul[mp]->sfas97rd_cohort_id_gross;
	xstring mp_cohort_ceded = liab->sm_ul[mp]->sfas97rd_cohort_id_ceded;
	xstring mp_cohort_map_id;
	if (reins_flag)
		mp_cohort_map_id = mp_cohort_ceded;
	else 	
		mp_cohort_map_id = mp_cohort_gross;
		
	if (setup_cohorts(liab->sm_ul[mp]->issue_yr, liab->sm_ul[mp]->plan_code, 
					  mp_cohort_map_id, cohort_id))
		{
		if (reins_flag)
			liab->sm_ul[mp]->sfas97rd_cohort_id_ceded = cohort_id;
		else	
			{
			liab->sm_ul[mp]->sfas97rd_cohort_id_gross = cohort_id;
			// MP is reinsured on a coinsurance basis
			if (liab->sm_ul[mp]->reins_flag && liab->sm_ul[mp]->coins_flag) 
				cohort_reins_indicator = 1;
			else if (liab->sm_ul[mp]->reins_flag && !liab->sm_ul[mp]->coins_flag) 
				cohort_reins_yrt_indicator = 1;							
			}		

		cohort_first_issue_period = min(cohort_first_issue_period, liab->sm_ul[mp]->commencement_period);
		cohort_last_issue_period = max(cohort_last_issue_period, liab->sm_ul[mp]->commencement_period);
		cohort_max_maturity_period = max(cohort_max_maturity_period, liab->sm_ul[mp]->maturity_period);
		cohort_mp_count += 1;
		ul_mp_map[mp] = mp;			
		}

	}
#endif

#if defined(__VUL_LIAB_H_)
for (mp_map_iter = seg->vul_mp_map.begin();
	 mp_map_iter != seg->vul_mp_map.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	xstring mp_cohort_gross = liab->sm_vul[mp]->sfas97rd_cohort_id_gross;
	xstring mp_cohort_ceded = liab->sm_vul[mp]->sfas97rd_cohort_id_ceded;
	xstring mp_cohort_map_id;
	if (reins_flag)
		mp_cohort_map_id = mp_cohort_ceded;
	else 	
		mp_cohort_map_id = mp_cohort_gross;
		
	if (setup_cohorts(liab->sm_vul[mp]->issue_yr, liab->sm_vul[mp]->plan_code, 
					  mp_cohort_map_id, cohort_id))
		{
		if (reins_flag)
			liab->sm_vul[mp]->sfas97rd_cohort_id_ceded = cohort_id;
		else	
			{
			liab->sm_vul[mp]->sfas97rd_cohort_id_gross = cohort_id;
			// MP is reinsured on a coinsurance basis
			if (liab->sm_vul[mp]->reins_flag && liab->sm_vul[mp]->coins_flag) 
				cohort_reins_indicator = 1;
			else if (liab->sm_vul[mp]->reins_flag && !liab->sm_vul[mp]->coins_flag) 
				cohort_reins_yrt_indicator = 1;							
			}		

		cohort_first_issue_period = min(cohort_first_issue_period, liab->sm_vul[mp]->commencement_period);
		cohort_last_issue_period = max(cohort_last_issue_period, liab->sm_vul[mp]->commencement_period);
		cohort_max_maturity_period = max(cohort_max_maturity_period, liab->sm_vul[mp]->maturity_period);
		cohort_mp_count += 1;
		vul_mp_map[mp] = mp;			
		}
	}
#endif

#if defined(__IUL_LIAB_H_)
for (mp_map_iter = seg->iul_mp_map.begin();
	 mp_map_iter != seg->iul_mp_map.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	xstring mp_cohort_gross = liab->sm_iul[mp]->sfas97rd_cohort_id_gross;
	xstring mp_cohort_ceded = liab->sm_iul[mp]->sfas97rd_cohort_id_ceded;
	xstring mp_cohort_map_id;
	if (reins_flag)
		mp_cohort_map_id = mp_cohort_ceded;
	else 	
		mp_cohort_map_id = mp_cohort_gross;
		
	if (setup_cohorts(liab->sm_iul[mp]->issue_yr, liab->sm_iul[mp]->plan_code, 
					  mp_cohort_map_id, cohort_id))
		{
		if (reins_flag)
			liab->sm_iul[mp]->sfas97rd_cohort_id_ceded = cohort_id;
		else	
			{
			liab->sm_iul[mp]->sfas97rd_cohort_id_gross = cohort_id;
			// MP is reinsured on a coinsurance basis
			if (liab->sm_iul[mp]->reins_flag && liab->sm_iul[mp]->coins_flag) 
				cohort_reins_indicator = 1;
			else if (liab->sm_iul[mp]->reins_flag && !liab->sm_iul[mp]->coins_flag) 
				cohort_reins_yrt_indicator = 1;							
			}		

		cohort_first_issue_period = min(cohort_first_issue_period, liab->sm_iul[mp]->commencement_period);
		cohort_last_issue_period = max(cohort_last_issue_period, liab->sm_iul[mp]->commencement_period);
		cohort_max_maturity_period = max(cohort_max_maturity_period, liab->sm_iul[mp]->maturity_period);
		cohort_mp_count += 1;
		iul_mp_map[mp] = mp;			
		}
	}
#endif

#if defined(__VA_LIAB_H_)
for (mp_map_iter = seg->va_mp_map.begin();
	 mp_map_iter != seg->va_mp_map.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	xstring mp_cohort_gross = liab->sm_va[mp]->sfas97rd_cohort_id_gross;
	xstring mp_cohort_ceded = liab->sm_va[mp]->sfas97rd_cohort_id_ceded;
	xstring mp_cohort_map_id;
	if (reins_flag)
		mp_cohort_map_id = mp_cohort_ceded;
	else 	
		mp_cohort_map_id = mp_cohort_gross;
		
	if (setup_cohorts(liab->sm_va[mp]->issue_yr, liab->sm_va[mp]->plan_code, 
					  mp_cohort_map_id, cohort_id))
		{
		if (reins_flag)
			liab->sm_va[mp]->sfas97rd_cohort_id_ceded = cohort_id;
		else	
			{
			liab->sm_va[mp]->sfas97rd_cohort_id_gross = cohort_id;
			if (liab->sm_va[mp]->reins_flag)
				cohort_reins_indicator = 1;
			}

		cohort_first_issue_period = min(cohort_first_issue_period, -liab->sm_va[mp]->elapsed_mths);
		cohort_last_issue_period = max(cohort_last_issue_period, -liab->sm_va[mp]->elapsed_mths);
		cohort_max_maturity_period = max(cohort_max_maturity_period, liab->sm_va[mp]->maturity_period);
		cohort_mp_count += 1;
		va_mp_map[mp] = mp;			
		}
	}
#endif

#if defined(__FA_LIAB_H_)
for (mp_map_iter = seg->fa_mp_map.begin();
	 mp_map_iter != seg->fa_mp_map.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	xstring mp_cohort_gross = liab->sm_fa[mp]->sfas97rd_cohort_id_gross;
	xstring mp_cohort_ceded = liab->sm_fa[mp]->sfas97rd_cohort_id_ceded;
	xstring mp_cohort_map_id;
	if (reins_flag)
		mp_cohort_map_id = mp_cohort_ceded;
	else 	
		mp_cohort_map_id = mp_cohort_gross;
		
	if (setup_cohorts(liab->sm_fa[mp]->issue_yr, liab->sm_fa[mp]->plan_code, 
					  mp_cohort_map_id, cohort_id))
		{
		if (reins_flag)
			liab->sm_fa[mp]->sfas97rd_cohort_id_ceded = cohort_id;
		else	
			{
			liab->sm_fa[mp]->sfas97rd_cohort_id_gross = cohort_id;
			if (liab->sm_fa[mp]->reins_flag)
				cohort_reins_indicator = 1;
			}

		cohort_first_issue_period = min(cohort_first_issue_period, -liab->sm_fa[mp]->elapsed_mths);
		cohort_last_issue_period = max(cohort_last_issue_period, -liab->sm_fa[mp]->elapsed_mths);
		cohort_max_maturity_period = max(cohort_max_maturity_period, liab->sm_fa[mp]->maturity_period);
		cohort_mp_count += 1;
		fa_mp_map[mp] = mp;			
		}
	}
#endif

#if defined(__FIA_LIAB_H_)
for (mp_map_iter = seg->fia_mp_map.begin();
	 mp_map_iter != seg->fia_mp_map.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	xstring mp_cohort_gross = liab->sm_fia[mp]->sfas97rd_cohort_id_gross;
	xstring mp_cohort_ceded = liab->sm_fia[mp]->sfas97rd_cohort_id_ceded;
	xstring mp_cohort_map_id;
	if (reins_flag)
		mp_cohort_map_id = mp_cohort_ceded;
	else 	
		mp_cohort_map_id = mp_cohort_gross;
		
	if (setup_cohorts(liab->sm_fia[mp]->issue_yr, liab->sm_fia[mp]->plan_code, 
					  mp_cohort_map_id, cohort_id))
		{
		if (reins_flag)
			liab->sm_fia[mp]->sfas97rd_cohort_id_ceded = cohort_id;
		else	
			{
			liab->sm_fia[mp]->sfas97rd_cohort_id_gross = cohort_id;
			if (liab->sm_fia[mp]->reins_flag)
				cohort_reins_indicator = 1;
			}
		liab->sm_fia[mp]->gaap_int_rate = fia_gaap_int_rate;
		cohort_first_issue_period = min(cohort_first_issue_period, -liab->sm_fia[mp]->elapsed_mths);
		cohort_last_issue_period = max(cohort_last_issue_period, -liab->sm_fia[mp]->elapsed_mths);
		cohort_max_maturity_period = max(cohort_max_maturity_period, liab->sm_fia[mp]->maturity_period);
		cohort_mp_count += 1;
		fia_mp_map[mp] = mp;			
		}
	}
#endif

#if defined(__EPL_LIAB_H_)
if (seg->epl_mp_map.size())
	{
	// Determine cohort_first_issue_period
	// Find earliest cohort issue period from cohort data
	int cohort_first_issue_yr = 9999;
	vector<string> issue_yrs;
	split_string_usl(cohort_issue_yrs.c_str(), issue_yrs, ",");//WTW - Gen2 - split_tring internal RAFM function

	// Use t_low as first_issue_period if all issue years are included in the cohort
	if (xstring(issue_yrs[0]) == "ALL")
		cohort_first_issue_period = min(t_low, cohort_first_issue_period);
	else
		{
		// Find earliest issue year
		for (int yrs_count = 0; yrs_count < issue_yrs.size(); yrs_count++)
			cohort_first_issue_yr = min(cohort_first_issue_yr, atoi(issue_yrs[yrs_count].c_str()));

		cohort_yr = cohort_first_issue_yr;

		cohort_first_issue_period 
		= min(cohort_first_issue_period,
			  MonthNumberFromDate(cohort_first_issue_yr, 1)
			  - MonthNumberFromDate(proj_start_yr, proj_start_mth));
		}
	}

for (mp_map_iter = seg->epl_mp_map.begin();
	 mp_map_iter != seg->epl_mp_map.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	xstring mp_cohort_group_id = liab->sm_epl[mp]->gaap_cohort;
		
	if (eq(mp_cohort_group_id, cohort_id))
		{
		if (!reins_flag && liab->sm_epl[mp]->reins_flag)
			{			
			cohort_reins_indicator = 1;
			cohort_reins_yrt_indicator = 1;	
			}

		cohort_max_maturity_period = max(cohort_max_maturity_period, liab->sm_epl[mp]->maturity_period);
		cohort_last_issue_period = max(cohort_last_issue_period, cohort_max_maturity_period - amortzn_mths);                        	
		cohort_mp_count += 1;
		epl_mp_map[mp] = mp;			
		}
	}
#endif

// Set cohort id as group name, crucial as this will be used as the key id to retrive values from the output files
if (cohort_mp_count > 0 
    || (seg->sfas97rd_seriatim_cohort_used.size() > cohort_col 
        && seg->sfas97rd_seriatim_cohort_used[cohort_col]))
	{
	if (reins_flag)
		reins_defn = "Ceded";
	else
		reins_defn = "Gross";
			
	xstring cohort_group = cohort_id + "|" + reins_defn;
	//this->setGroup(cohort_group);	WTW - Gen2 - this submodel is not used and this is line is only for ALM runs

	if (!valn_flag)
		get_gaap_schedule_items();

	if (valn_period > 0)
		read_state_of_world_financial();
	}
	
return cohort_mp_count;

}


//@@ END

//@@ START - inv_inc
// Investment Income                                                                                             
// Column:INV_INC
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_inv_inc(int t) {
//^^^



//^^^

#line 1 "inv_inc.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	{
	if (!reins_flag)
		{
		if (fabs(seg->gaap_liab_net(t - 1) - seg->pol_loan(t - 1)) < aggregate_amount_threshold)
			return NO_AVG;

		return (seg->gaap_inv_inc_res(t)
				+ seg->gaap_inv_inc_cap(t))
				* (liab_net(t - 1) - pol_loan(t - 1))
				  / (seg->gaap_liab_net(t - 1) - seg->pol_loan(t - 1))
				+ pol_loan_inc(t);
		}
	else if (reins_flag)
		{
		if (fabs(seg->reins_gaap_liab_net(t - 1)) < aggregate_amount_threshold)
			return NO_AVG;

		return seg->reins_gaap_inv_inc_res(t)
			   * liab_net(t - 1) / seg->reins_gaap_liab_net(t - 1);
		}
	}

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag)
		return ul->gaap_inv_inc_res(t)
		       + ul->gaap_inv_inc_cap(t);
	else if (ul->coins_flag)
		return ul->reins_gaap_inv_inc_res(t);
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag)
		return iul->gaap_inv_inc_res(t)
		       + iul->gaap_inv_inc_cap(t);
	else if (iul->coins_flag)
		return iul->reins_gaap_inv_inc_res(t);
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag)
		return vul->gaap_inv_inc_res(t)
		       + vul->gaap_inv_inc_cap(t);
	else if (vul->coins_flag)
		return vul->reins_gaap_inv_inc_res(t);
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (!reins_flag)
		return fa->gaap_inv_inc_res(t)
		       + fa->gaap_inv_inc_cap(t);
	else if (fa->reins_flag)
		return fa->reins_gaap_inv_inc_res(t);
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (!reins_flag)
		return fa->gaap_inv_inc_res(t)
		       + fa->gaap_inv_inc_cap(t);
	else if (fa->reins_flag)
		return fa->reins_gaap_inv_inc_res(t);
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag)
		return va->gaap_inv_inc_res(t)
		       + va->gaap_inv_inc_cap(t);
	else if (va->reins_flag)
		return va->reins_gaap_inv_inc_res(t);
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (!reins_flag)
		return fia->gaap_inv_inc_res(t)
		       + fia->gaap_inv_inc_cap(t);
	else if (fia->reins_flag)
		return fia->reins_gaap_inv_inc_res(t);
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - inv_inc_fund
// Investment Income on Fund                                                                                             
// Column:INV_INC_FUND
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_inv_inc_fund(int t) {
//^^^



//^^^

#line 1 "inv_inc_fund.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("inv_inc_fund", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	double reins_pct = 0.0;
		
	if (!reins_flag) //Gross
		reins_pct = 1.0;
	
	else if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		reins_pct = ul->reins_pct;

	return max(0.0, ul->sm_ul_ifund_curr->fund_val_bef_int(t))
	       * ul->units_inf(t - 1)
		   * (pow(1.0 + ul->asset_yld(t), 1.0 / 12.0) - 1.0)
		   * reins_pct;
	}	
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	double reins_pct = 0.0;
		
	if (!reins_flag) //Gross
		reins_pct = 1.0;
	
	else if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		reins_pct = vul->reins_pct;

	return max(0.0, vul->sum_over_funds("av_bef_int", t, GENERAL)
		            + vul->sum_over_funds("av_bef_int", t, DCA))
		   * vul->units_inf(t - 1)
		   * (pow(1.0 + vul->asset_yld(t), 1.0 / 12.0) - 1.0)
		   * reins_pct;
	}	
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	double reins_pct = 0.0;
		
	if (!reins_flag) //Gross
		reins_pct = 1.0;
	
	else if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		reins_pct = iul->reins_pct;

	return max(0.0, iul->sm_iul_ifund_curr->fund_val_bef_int(t))
	       * iul->units_inf(t - 1)
		   * (pow(1.0 + iul->asset_yld_inv(t), 1.0 / 12.0) - 1.0)
		   * reins_pct;
	}	
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	return NO_AVG;
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	double reins_pct = 0.0;
	
	if (!reins_flag) //Gross
		reins_pct = 1.0;
	else if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance
		reins_pct = fa->reins_pct;
		
	return max(0.0, fa->fund_val_b(t))
		   * (pow(1.0 + fa->asset_yld(t), 1.0 / 12.0) - 1.0)
		   * reins_pct;
	}		
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	double reins_pct = 0.0;
	
	if (!reins_flag) //Gross
		reins_pct = 1.0;
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance
		reins_pct = fia->reins_pct;
		
	return max(0.0, fia->fund_val_b(t))
		   * (pow(1.0 + fia->asset_yld(t), 1.0 / 12.0) - 1.0)
		   * reins_pct;
	}				
#endif

return NO_AVG;

}


//@@ END

//@@ START - k_capzd_acq_exp
// K Capitalized Acquisition Expenses                                                                                             
// Column:K_CAPZD_ACQ_EXP
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_acq_exp(int t) {
//^^^



//^^^

#line 1 "k_capzd_acq_exp.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		double capzd_acq_exp_total = 0.0;
		double egp_total = 0.0;

		if (loss_recognition_flag)
			{
			capzd_acq_exp_total = capzd_acq_exp_accum_loss_rec_int_rate(t) + capzd_acq_exp_pv_loss_rec_int_rate(t);
			egp_total = egp_accum_loss_rec_int_rate(t) + egp_pv_loss_rec_int_rate(t);
			}
		else
			{	 
			capzd_acq_exp_total = capzd_acq_exp_accum(t) + capzd_acq_exp_pv(t);
			egp_total = egp_accum(t) + egp_pv(t);
			}

		if (egp_total <= model_point_amount_threshold)
			return 0.0;
			
		return (capzd_acq_exp_total - dac_acq_exp_loss_rec_accum(t))
				/ egp_total;		
		}

	// (valn_period >= 0 && !valn_flag)
	return k_capzd_acq_exp_sch(t);
	}

return k_capzd_acq_exp(t - 1);

}


//@@ END

//@@ START - k_capzd_acq_exp_sch
// K Capitalized Acquisition Expenses Schedule                                                                                             
// Column:K_CAPZD_ACQ_EXP_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_acq_exp_sch(int t) {
//^^^



//^^^

#line 1 "k_capzd_acq_exp_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

return gaap_schedule[K_CAPZD_ACQ_EXP][0];

}


//@@ END

//@@ START - k_capzd_comm
// K Capitalized Commissions                                                                                             
// Column:K_CAPZD_COMM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_comm(int t) {
//^^^



//^^^

#line 1 "k_capzd_comm.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		double capzd_comm_total = 0.0;
		double egp_total = 0.0;

		if (loss_recognition_flag)
			{
			capzd_comm_total = capzd_comm_accum_loss_rec_int_rate(t) + capzd_comm_pv_loss_rec_int_rate(t);
			egp_total = egp_accum_loss_rec_int_rate(t) + egp_pv_loss_rec_int_rate(t);
			}
		else
			{	 
			capzd_comm_total = capzd_comm_accum(t) + capzd_comm_pv(t);
			egp_total = egp_accum(t) + egp_pv(t);
			}

		if (egp_total <= model_point_amount_threshold)
			return 0.0;
		
		return (capzd_comm_total - dac_comm_loss_rec_accum(t))
				/ egp_total;								
		}

	// (valn_period >= 0 && !valn_flag)
	return k_capzd_comm_sch(t);
	}

return k_capzd_comm(t - 1);

}


//@@ END

//@@ START - k_capzd_comm_sch
// K Capitalized Commissions Schedule                                                                                             
// Column:K_CAPZD_COMM_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_comm_sch(int t) {
//^^^



//^^^

#line 1 "k_capzd_comm_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

return gaap_schedule[K_CAPZD_COMM][0];

}


//@@ END

//@@ START - k_capzd_prem_bonus
// K Capitalized Premium Bonus                                                                                             
// Column:K_CAPZD_PREM_BONUS
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_prem_bonus(int t) {
//^^^



//^^^

#line 1 "k_capzd_prem_bonus.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		double capzd_prem_bonus_total = 0.0;
		double egp_total = 0.0;

		if (loss_recognition_flag)
			{
			capzd_prem_bonus_total = capzd_prem_bonus_accum_loss_rec_int_rate(t) + capzd_prem_bonus_pv_loss_rec_int_rate(t);
			egp_total = egp_accum_loss_rec_int_rate(t) + egp_pv_loss_rec_int_rate(t);
			}
		else
			{	 
			capzd_prem_bonus_total = capzd_prem_bonus_accum(t) + capzd_prem_bonus_pv(t);
			egp_total = egp_accum(t) + egp_pv(t);
			}

		if (egp_total <= model_point_amount_threshold)
			return 0.0;
			
		return (capzd_prem_bonus_total - dac_prem_bonus_loss_rec_accum(t))
				/ egp_total;		
		}

	// (valn_period >= 0 && !valn_flag)
	return k_capzd_prem_bonus_sch(t);
	}

return k_capzd_prem_bonus(t - 1);

}


//@@ END

//@@ START - k_capzd_prem_bonus_sch
// K Capitalized Premium Bonus Schedule                                                                                             
// Column:K_CAPZD_PREM_BONUS_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_prem_bonus_sch(int t) {
//^^^



//^^^

#line 1 "k_capzd_prem_bonus_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

return gaap_schedule[K_CAPZD_PREM_BONUS][0];

}


//@@ END

//@@ START - k_reins_yrt_cost
// K YRT Reinsurance Cost                                                                                             
// Column:K_REINS_YRT_COST
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_reins_yrt_cost(int t) {
//^^^



//^^^

#line 1 "k_reins_yrt_cost.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!cohort_reins_yrt_indicator)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		if ((egp_accum(t) + egp_pv(t)) <= model_point_amount_threshold)
			return 0.0;
		
		return (reins_yrt_cost_accum(t) + reins_yrt_cost_pv(t))
				/ (egp_accum(t) + egp_pv(t));		
		}

	// (valn_period >= 0 && !valn_flag)
	return k_reins_yrt_cost_sch(t);
	}

return k_reins_yrt_cost(t - 1);

}


//@@ END

//@@ START - k_reins_yrt_cost_sch
// K YRT Reinsurance Cost Schedule                                                                                             
// Column:K_REINS_YRT_COST_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_reins_yrt_cost_sch(int t) {
//^^^



//^^^

#line 1 "k_reins_yrt_cost_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

if (!cohort_reins_yrt_indicator)
	return NO_AVG;

return gaap_schedule[K_REINS_YRT_COST][0];

}


//@@ END

//@@ START - k_sop031_gmdb_ben_br
// K SOP 03-1 GMDB Benefit Ratio                                                                                             
// Column:K_SOP031_GMDB_BEN_BR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_gmdb_ben_br(int t) {
//^^^



//^^^

#line 1 "k_sop031_gmdb_ben_br.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		if ((sop031_egp_accum(t) + sop031_egp_pv(t)) <= model_point_amount_threshold)
			return 0.0;

		// values are - if accum, TO point in time , - if pv, AT point in time
		return (sop031_gmdb_ben_accum(t) + sop031_gmdb_ben_pv(t)) 
			    / (sop031_egp_accum(t) + sop031_egp_pv(t));
		}

	// (valn_period >= 0 && !valn_flag)
	return k_sop031_gmdb_ben_br_sch(t);
	}		

return k_sop031_gmdb_ben_br(t - 1);

}


//@@ END

//@@ START - k_sop031_gmdb_ben_br_sch
// K SOP 03-1 GMDB Benefit Ratio Schedule                                                                                             
// Column:K_SOP031_GMDB_BEN_BR_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_gmdb_ben_br_sch(int t) {
//^^^



//^^^

#line 1 "k_sop031_gmdb_ben_br_sch.SFAS97RD_GAAP.for"
if (valn_flag || t < start_period || t > final_period)
	return NO_AVG;

return gaap_schedule[K_SOP031_GMDB_BEN_BR][0];

}


//@@ END

//@@ START - k_sop031_pbr
// K SOP 03-1 Persistency Bonus/Refunds                                                                                             
// Column:K_SOP031_PBR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_pbr(int t) {
//^^^



//^^^

#line 1 "k_sop031_pbr.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;
	
if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		if ((sop031_pbr_fund_val_accum(t) + sop031_pbr_fund_val_pv(t)) <= model_point_amount_threshold)
			return 0.0;
		
		return (sop031_pbr_accum(t) + sop031_pbr_pv(t))
				/ (sop031_pbr_fund_val_accum(t) + sop031_pbr_fund_val_pv(t));
		}

	// (valn_period >= 0 && !valn_flag)
	return k_sop031_pbr_sch(t);
	}

return k_sop031_pbr(t - 1);

}


//@@ END

//@@ START - k_sop031_pbr_sch
// K SOP 03-1 Persistency Bonus/Refunds Schedule                                                                                             
// Column:K_SOP031_PBR_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_pbr_sch(int t) {
//^^^



//^^^

#line 1 "k_sop031_pbr_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;
	
return gaap_schedule[K_SOP031_PBR][0];

}


//@@ END

//@@ START - k_sop031_ulsg_ben_br
// K SOP 03-1 ULSG Benefit Ratio                                                                                             
// Column:K_SOP031_ULSG_BEN_BR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_ulsg_ben_br(int t) {
//^^^



//^^^

#line 1 "k_sop031_ulsg_ben_br.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		if ((sop031_egp_accum(t) + sop031_egp_pv(t)) <= model_point_amount_threshold)
			return 0.0;

		// values are - if accum, TO point in time , - if pv, AT point in time
		return (sop031_ulsg_ben_accum(t) + sop031_ulsg_ben_pv(t)) 
			    / (sop031_egp_accum(t) + sop031_egp_pv(t));
		}

	// (valn_period >= 0 && !valn_flag)
	return k_sop031_ulsg_ben_br_sch(t);
	}		

return k_sop031_ulsg_ben_br(t - 1);

}


//@@ END

//@@ START - k_sop031_ulsg_ben_br_sch
// K SOP 03-1 ULSG Benefit Ratio Schedule                                                                                             
// Column:K_SOP031_ULSG_BEN_BR_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_ulsg_ben_br_sch(int t) {
//^^^



//^^^

#line 1 "k_sop031_ulsg_ben_br_sch.SFAS97RD_GAAP.for"
if (valn_flag || t < start_period || t > final_period)
	return NO_AVG;

return gaap_schedule[K_SOP031_ULSG_BEN_BR][0];

}


//@@ END

//@@ START - k_sop031_unearn_rev_liab
// K SOP 03-1 Unearned Revenue Liability                                                                                             
// Column:K_SOP031_UNEARN_REV_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_unearn_rev_liab(int t) {
//^^^



//^^^

#line 1 "k_sop031_unearn_rev_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		double k_factor = 0.0;

		if ((sop031_egp_accum(t) + sop031_egp_pv(t)) <= model_point_amount_threshold)
			return 0.0;
			
		return (deferred_loads_accum(t) + deferred_loads_pv(t))
				/ (sop031_egp_accum(t) + sop031_egp_pv(t));								
		}

	// (valn_period >= 0 && !valn_flag)
	return k_sop031_unearn_rev_liab_sch(t);
	}

return k_sop031_unearn_rev_liab(t - 1);

}


//@@ END

//@@ START - k_sop031_unearn_rev_liab_sch
// K SOP 03-1 Unearned Revenue Liability Schedule                                                                                             
// Column:K_SOP031_UNEARN_REV_LIAB_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_unearn_rev_liab_sch(int t) {
//^^^



//^^^

#line 1 "k_sop031_unearn_rev_liab_sch.SFAS97RD_GAAP.for"
if (valn_flag || t < start_period || t > final_period)
	return NO_AVG;

return gaap_schedule[K_SOP031_UNEARN_REV_LIAB][0];

}


//@@ END

//@@ START - k_unearn_rev_liab
// K Unearned Revenue Liability                                                                                             
// Column:K_UNEARN_REV_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_unearn_rev_liab(int t) {
//^^^



//^^^

#line 1 "k_unearn_rev_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		if ((egp_accum(t) + egp_pv(t)) <= model_point_amount_threshold)
			return 0.0;
			
		return (deferred_loads_accum(t) + deferred_loads_pv(t))
				/ (egp_accum(t) + egp_pv(t));								
		}

	// (valn_period >= 0 && !valn_flag)
	return k_unearn_rev_liab_sch(t);
	}

return k_unearn_rev_liab(t - 1);

}


//@@ END

//@@ START - k_unearn_rev_liab_sch
// K Unearned Revenue Liability Schedule                                                                                             
// Column:K_UNEARN_REV_LIAB_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_unearn_rev_liab_sch(int t) {
//^^^



//^^^

#line 1 "k_unearn_rev_liab_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

return gaap_schedule[K_UNEARN_REV_LIAB][0];

}


//@@ END

//@@ START - liab_net
// Liability Net of DAC                                                                                             
// Column:LIAB_NET
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_liab_net(int t) {
//^^^



//^^^

#line 1 "liab_net.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return fund_val_fixed(t)
	   + unearn_rev_liab(t)
	   + sfas133_liab(t)
       + sop031_addl_liab(t)
	   - dac_acq_exp(t)
	   - dac_comm(t)
	   - dac_prem_bonus(t)
	   - dac_reins_yrt_asset(t);

}


//@@ END

//@@ START - loads
// Loads                                                                                             
// Column:LOADS
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_loads(int t) {
//^^^



//^^^

#line 1 "loads.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("loads", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag)
		return max(0.0, min(ul->loads(t),
		                    ul->fund_val_fixed(t - 1) + ul->prem_paid(t) - ul->rider_chg(t)));
		
	if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured via Coinsurance	
		return max(0.0, min(ul->loads(t),
		                    ul->fund_val_fixed(t - 1) + ul->prem_paid(t) - ul->rider_chg(t)))
		       * ul->reins_pct;

	return NO_AVG;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag)
		return max(0.0, min(vul->loads(t) + vul->sub_adv_fees(t),
		                    vul->fund_val(t - 1) + vul->prem_paid(t) - vul->rider_chg(t)));
		
	if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured via Coinsurance	
		return max(0.0, min(vul->loads(t) + vul->sub_adv_fees(t),
		                    vul->fund_val(t - 1) + vul->prem_paid(t) - vul->rider_chg(t)))
		       * vul->reins_pct;

	return NO_AVG;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag)
		return max(0.0, min(iul->loads(t),
		                    iul->fund_val_fixed(t - 1) + iul->prem_paid(t) - iul->rider_chg(t)));
		
	if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured via Coinsurance	
		return max(0.0, min(iul->loads(t),
		                    iul->fund_val_fixed(t - 1) + iul->prem_paid(t) - iul->rider_chg(t)))
		       * iul->reins_pct;

	return NO_AVG;
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag)
		return va->admin_fee(t)
			   + va->m_and_e_fee(t)
			   + va->sub_adv_fees(t);
	
	if (reins_flag && va->reins_flag)
		{
		if (va->reins_coverage_defn == RIDER_ONLY)
			return 0.0;

		return (va->admin_fee(t)
			    + va->m_and_e_fee(t)
			    + va->sub_adv_fees(t))
			   * va->reins_pct;
		}

	return NO_AVG;
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (!reins_flag)
		return fa->admin_fee(t) + fa->load_prem(t);
	
	if (reins_flag && fa->reins_flag)
		return (fa->admin_fee(t) + fa->load_prem(t)) * fa->reins_pct;

	return NO_AVG;
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (!reins_flag)
		return fia->admin_fee(t);
	
	if (reins_flag && fia->reins_flag)
		return fia->admin_fee(t) * fia->reins_pct;

	return NO_AVG;
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - loc_cost
// Letter of Credit Cost                                                                                             
// Column:LOC_COST
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_loc_cost(int t) {
//^^^



//^^^

#line 1 "loc_cost.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("loc_cost", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag)
		return ul->loc_cost(t);

	return 0.0;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag)
		return iul->loc_cost(t);

	return 0.0;
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - loss_rec_amortzn_int_rate
// Loss Recognition Amortization Interest Rate                                                                                             
// Column:LOSS_REC_AMORTZN_INT_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_loss_rec_amortzn_int_rate(int t) {
//^^^



//^^^

#line 1 "loss_rec_amortzn_int_rate.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return loss_rec_int_rate_mthly;

}


//@@ END

//@@ START - maint_exp_bom
// Maintenance Expenses Beginning of Month                                                                                             
// Column:MAINT_EXP_BOM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(136,"maint_exp_bom",t);
}



//^^^

#line 1 "maint_exp_bom.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("maint_exp_bom", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return ul->maint_exp_bom(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return vul->maint_exp_bom(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return iul->maint_exp_bom(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->maint_exp_bom(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance
		{
		if (va->reins_coverage_defn == RIDER_ONLY)
			return NO_AVG;
			
		return va->maint_exp_bom(t) * va->reins_pct;
		}
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fa->maint_exp_bom(t);
	
	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fa->maint_exp_bom(t) * fa->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fia->maint_exp_bom(t);
	
	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fia->maint_exp_bom(t) * fia->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - maint_exp_eom
// Maintenance Expenses End of Month                                                                                             
// Column:MAINT_EXP_EOM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_maint_exp_eom(int t) {
//^^^



//^^^

#line 1 "maint_exp_eom.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("maint_exp_eom", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return ul->maint_exp_eom(t);
	
	if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		return - (ul->sum_over_reinsurance("expense", t, COINSURANCE) 
			      + ul->sum_over_reinsurance("expense", t, MODIFIED_COINSURANCE));
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return vul->maint_exp_eom(t);
	
	if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		return - (vul->sum_over_reinsurance("expense", t, COINSURANCE) 
			      + vul->sum_over_reinsurance("expense", t, MODIFIED_COINSURANCE));

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return iul->maint_exp_eom(t);

	if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		return - (iul->sum_over_reinsurance("expense", t, COINSURANCE) 
			      + iul->sum_over_reinsurance("expense", t, MODIFIED_COINSURANCE));

	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->maint_exp_eom(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance
		{
		if (va->reins_coverage_defn == RIDER_ONLY)
			return NO_AVG;
			
		return va->maint_exp_eom(t) * va->reins_pct
		       - va->reins_exp(t);
		}

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fa->maint_exp_eom(t);
	
	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fa->maint_exp_eom(t) * fa->reins_pct
		       - fa->reins_exp(t);

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fia->maint_exp_eom(t);
	
	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fia->maint_exp_eom(t) * fia->reins_pct
		       - fia->reins_exp(t);

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - modco_liab
// Modco Liability                                                                                             
// Column:MODCO_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_modco_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(138,"modco_liab",t);
}



//^^^

#line 1 "modco_liab.SFAS97RD_GAAP.for"
if (!reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("modco_liab", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	return ul->sum_over_reinsurance("stat_res_mp_prelim", t, MODIFIED_COINSURANCE)
		   + ul->sum_over_reinsurance("stat_unearn_prem_res", t, MODIFIED_COINSURANCE);
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	return vul->sum_over_reinsurance("stat_res_mp_prelim", t, MODIFIED_COINSURANCE)
		   + vul->sum_over_reinsurance("stat_unearn_prem_res", t, MODIFIED_COINSURANCE);
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	return iul->sum_over_reinsurance("stat_res_mp_prelim", t, MODIFIED_COINSURANCE)
		   + iul->sum_over_reinsurance("stat_unearn_prem_res", t, MODIFIED_COINSURANCE);
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (va->reins_flag)
		return va->reins_stat_res(t);
	
	return NO_AVG;
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - modco_liab_incr
// Modco Liability Increase                                                                                             
// Column:MODCO_LIAB_INCR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_modco_liab_incr(int t) {
//^^^



//^^^

#line 1 "modco_liab_incr.SFAS97RD_GAAP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

return modco_liab(t) - modco_liab(t - 1);

}


//@@ END

//@@ START - modco_res_adj
// Modco Reserve Adjustment                                                                                             
// Column:MODCO_RES_ADJ
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_modco_res_adj(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(140,"modco_res_adj",t);
}



//^^^

#line 1 "modco_res_adj.SFAS97RD_GAAP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("modco_res_adj", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (ul->modco_flag)
		return ul->reins_modco_res_adj(t);
		
	return NO_AVG;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (vul->modco_flag)
		return vul->reins_modco_res_adj(t);
		
	return NO_AVG;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (iul->modco_flag)
		return iul->reins_modco_res_adj(t);
		
	return NO_AVG;
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (va->reins_flag)
		return va->reins_modco_res_adj(t);
	
	return NO_AVG;
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - persist_bon_ref
// Persistency Bonus/Refunds                                                                                             
// Column:PERSIST_BON_REF
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_persist_bon_ref(int t) {
//^^^



//^^^

#line 1 "persist_bon_ref.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
if (this == sfas97rd)
	return sum_over_gaap("persist_bon_ref", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag) //Gross
		{
		if (ul->fund_val_fixed(t) > model_point_amount_threshold)
			return ul->persist_bon(t) 
				   + ul->persist_ref(t);
		}	

	if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		{
		if (ul->fund_val_fixed(t) > model_point_amount_threshold)
			return (ul->persist_bon(t) 
					+ ul->persist_ref(t))
					* ul->reins_pct;
		}
	//Ceded and MP Not Reinsured
	return 0.0;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) //Gross
		{
		if (vul->fund_val_fixed(t) > model_point_amount_threshold)
			return (vul->sum_over_funds("persist_bon", t, GENERAL)
			        + vul->sum_over_funds("persist_bon", t, DCA))
					* vul->units_inf(t - 1);
		}
	
	if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured via Coinsurance
		{
		if (vul->fund_val_fixed(t) > model_point_amount_threshold)
			return (vul->sum_over_funds("persist_bon", t, GENERAL)
			        + vul->sum_over_funds("persist_bon", t, DCA))
				   * vul->units_inf(t - 1) 
   				   * vul->reins_pct;
		}

	//Ceded and MP Not Reinsured
	return 0.0;
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - pol_loan
// Policy Loans                                                                                             
// Column:POL_LOAN
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_pol_loan(int t) {
//^^^



//^^^

#line 1 "pol_loan.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("pol_loan", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag)
		return ul->pol_loan(t);

	// policy loans are not reinsured
	return 0.0; 
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag)
		return iul->pol_loan(t);

	// policy loans are not reinsured
	return 0.0; 
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag)
		return vul->pol_loan(t);

	// policy loans are not reinsured
	return 0.0; 
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - pol_loan_inc
// Policy Loan Income                                                                                             
// Column:POL_LOAN_INC
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_pol_loan_inc(int t) {
//^^^



//^^^

#line 1 "pol_loan_inc.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("pol_loan_inc", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag)
		return ul->pol_loan_inc(t);	

	return NO_AVG;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag)
		return iul->pol_loan_inc(t);	

	return NO_AVG;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag)
		return vul->pol_loan_inc(t);	

	return NO_AVG;
	}
#endif

return 0.0;

}


//@@ END

//@@ START - policies_b
// Policies In Force Beginning of Month                                                                                             
// Column:POLICIES_B
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_policies_b(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(144,"policies_b",t);
}



//^^^

#line 1 "policies_b.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("policies_b", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (t == ul->commencement_period + 1)
		return ul->policies_issued(t);

	return ul->policies_inf(t - 1);
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (t == vul->commencement_period + 1)
		return vul->policies_issued(t);

	return vul->policies_inf(t - 1);
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (t == iul->commencement_period + 1)
		return iul->policies_issued(t);

	return iul->policies_inf(t - 1);
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	return va->policies_b(t);
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	return fa->policies_b(t);
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	return fia->policies_b(t);
#endif

return NO_AVG;

}


//@@ END

//@@ START - prem_bonus
// Premium Bonus                                                                                             
// Column:PREM_BONUS
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_prem_bonus(int t) {
//^^^



//^^^

#line 1 "prem_bonus.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("prem_bonus", t);

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->prem_bonus(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return va->prem_bonus(t) * va->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fa->prem_bonus(t);
	
	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fa->prem_bonus(t) * fa->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fia->prem_bonus(t);
	
	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fia->prem_bonus(t) * fia->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - prem_tax
// Premium Tax                                                                                             
// Column:PREM_TAX
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_prem_tax(int t) {
//^^^



//^^^

#line 1 "prem_tax.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("prem_tax", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return ul->prem_tax(t);

    if (reins_flag && ul->reins_flag && ul->coins_flag) 
		return ul->sum_over_reinsurance("prem_tax", t, COINSURANCE)
			   + ul->sum_over_reinsurance("prem_tax", t, MODIFIED_COINSURANCE);

	return 0.0;	
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return vul->prem_tax(t);

    if (reins_flag && vul->reins_flag && vul->coins_flag) 
		return vul->sum_over_reinsurance("prem_tax", t, COINSURANCE)
			   + vul->sum_over_reinsurance("prem_tax", t, MODIFIED_COINSURANCE);

	return 0.0;	
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return iul->prem_tax(t);

    if (reins_flag && iul->reins_flag && iul->coins_flag) 
		return iul->sum_over_reinsurance("prem_tax", t, COINSURANCE)
			   + iul->sum_over_reinsurance("prem_tax", t, MODIFIED_COINSURANCE);

	return 0.0;	
	}
#endif


#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!reins_flag) //Gross
		return va->prem_tax(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance
		{
		if (va->reins_coverage_defn == RIDER_ONLY)
			return NO_AVG;
			
		return va->prem_tax(t) * va->reins_pct;
		}
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
	
#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fa->prem_tax(t);
	
	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fa->prem_tax(t) * fa->reins_pct;
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (!reins_flag) //Gross
		return fia->prem_tax(t);
	
	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fia->prem_tax(t) * fia->reins_pct;
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	
	
return NO_AVG;

}


//@@ END

//@@ START - refund
// Reinsurance Refund                                                                                             
// Column:REFUND
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_refund(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(147,"refund",t);
}



//^^^

#line 1 "refund.SFAS97RD_GAAP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("refund", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (ul->reins_flag)
		return ul->sum_over_reinsurance("ref", t, COINSURANCE)
		       + ul->sum_over_reinsurance("ref", t, MODIFIED_COINSURANCE)
			   + ul->sum_over_reinsurance("prem_unearned_ref", t, COINSURANCE)
			   + ul->sum_over_reinsurance("prem_unearned_ref", t, MODIFIED_COINSURANCE);
		
	return NO_AVG;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (vul->reins_flag)
		return  vul->sum_over_reinsurance("ref", t, MODIFIED_COINSURANCE)
			   + vul->sum_over_reinsurance("prem_unearned_ref", t, MODIFIED_COINSURANCE);
		
	return NO_AVG;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (iul->reins_flag)
		return iul->sum_over_reinsurance("ref", t, COINSURANCE)
		       + iul->sum_over_reinsurance("ref", t, MODIFIED_COINSURANCE)
			   + iul->sum_over_reinsurance("prem_unearned_ref", t, COINSURANCE)
			   + iul->sum_over_reinsurance("prem_unearned_ref", t, MODIFIED_COINSURANCE);
		
	return NO_AVG;
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (va->reins_flag)
		return va->reins_ref(t);
	
	return NO_AVG;
	}
#endif
	
return NO_AVG;

}


//@@ END

//@@ START - reins_yrt_cost
// YRT Reinsurance Cost                                                                                             
// Column:REINS_YRT_COST
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_reins_yrt_cost(int t) {
//^^^



//^^^

#line 1 "reins_yrt_cost.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*reins_flag || */t <= start_period || t > final_period)
	return NO_AVG;
	
if (reins_flag)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("reins_yrt_cost", t);
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (ul->reins_flag) 
		{
		double reins_prem = ul->sum_over_reinsurance("prem", t, YRT);
		double cash_flow_rate_mthly = pow(1.0 + ul->asset_yld(t), 1.0 / 12.0) - 1.0;	
		double dth_benefits = ul->sum_over_reinsurance("coverage_per_model_basis", t, YRT)
							  * ul->dths_units(t);
		double reins_exp = ul->sum_over_reinsurance("expense", t, YRT);
		double reins_ref = ul->sum_over_reinsurance("ref", t, YRT)
						   + ul->sum_over_reinsurance("prem_unearned_ref", t, YRT);
		double reins_ea = ul->sum_over_reinsurance("ea", t, YRT);
		double reins_ea_chargeback = ul->sum_over_reinsurance("ea_chargeback", t, YRT);

		return (reins_prem - reins_ea) * (1.0 + cash_flow_rate_mthly)
			   + reins_ea_chargeback
			   - dth_benefits
			   - reins_ref
			   + reins_exp;
		}
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (vul->reins_flag)
		{
		double reins_prem = vul->sum_over_reinsurance("prem", t, YRT);
		double cash_flow_rate_mthly = pow(1.0 + vul->asset_yld(t), 1.0 / 12.0) - 1.0;	
		double dth_benefits = vul->sum_over_reinsurance("coverage_per_model_basis", t, YRT)
							  * vul->dths_units(t);
		double reins_exp = vul->sum_over_reinsurance("expense", t, YRT);
		double reins_ref = vul->sum_over_reinsurance("ref", t, YRT)
						   + vul->sum_over_reinsurance("prem_unearned_ref", t, YRT);
		double reins_ea = vul->sum_over_reinsurance("ea", t, YRT);
		double reins_ea_chargeback = vul->sum_over_reinsurance("ea_chargeback", t, YRT);

		return (reins_prem - reins_ea) * (1.0 + cash_flow_rate_mthly)
			   + reins_ea_chargeback
			   - dth_benefits
			   - reins_ref
			   + reins_exp;
		}
	}
#endif
	
#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (iul->reins_flag)
		{
		double reins_prem = iul->sum_over_reinsurance("prem", t, YRT);
		double cash_flow_rate_mthly = pow(1.0 + iul->asset_yld_inv(t), 1.0 / 12.0) - 1.0;	
		double dth_benefits = iul->sum_over_reinsurance("coverage_per_model_basis", t, YRT)
							  * iul->dths_units(t);
		double reins_exp = iul->sum_over_reinsurance("expense", t, YRT);
		double reins_ref = iul->sum_over_reinsurance("ref", t, YRT)
						   + iul->sum_over_reinsurance("prem_unearned_ref", t, YRT);
		double reins_ea = iul->sum_over_reinsurance("ea", t, YRT);
		double reins_ea_chargeback = iul->sum_over_reinsurance("ea_chargeback", t, YRT);

		return (reins_prem - reins_ea) * (1.0 + cash_flow_rate_mthly)
			   + reins_ea_chargeback
			   - dth_benefits
			   - reins_ref
			   + reins_exp;
		}
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - reins_yrt_cost_accum
// YRT Reinsurance Cost Accumulation                                                                                             
// Column:REINS_YRT_COST_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_reins_yrt_cost_accum(int t) {
//^^^



//^^^

#line 1 "reins_yrt_cost_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;
	
if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;
	
if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double def_reins_yrt_cost_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double def_reins_yrt_cost = cohort_history_reins_yrt_cost/*.AtTime(tt)*/;
				
				def_reins_yrt_cost_accum 
				= def_reins_yrt_cost_accum * (1.0 + gaap_int_rate_mthly) + def_reins_yrt_cost;
				}			
			
			return def_reins_yrt_cost_accum; 
			}
		//  No History for cell pricing at issue period
		return 0.0;	
		}	

	//valn_period != 0
	return init_reins_yrt_cost_accum;
	}
	
return reins_yrt_cost_accum(t - 1) 
       * (1.0 + gaap_amortzn_int_rate(t))
	   + capzd_reins_yrt_cost(t);

}


//@@ END

//@@ START - reins_yrt_cost_pv
// YRT Reinsurance Cost Present Value                                                                                             
// Column:REINS_YRT_COST_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_reins_yrt_cost_pv(int t) {
//^^^



//^^^

#line 1 "reins_yrt_cost_pv.SFAS97RD_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

return (capzd_reins_yrt_cost(t + 1)
		+ reins_yrt_cost_pv(t + 1))
	   / (1.0 + gaap_amortzn_int_rate(t + 1));

}


//@@ END

//@@ START - rider_charges
// Rider Charges                                                                                             
// Column:RIDER_CHARGES
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_rider_charges(int t) {
//^^^



//^^^

#line 1 "rider_charges.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("rider_charges", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag)
		return max(0.0, min(ul->rider_chg(t),
		                    ul->fund_val_fixed(t - 1) + ul->prem_paid(t)));
		
	// else coinsurance or modified coinsurance
	return max(0.0, min(ul->rider_chg(t),
	                    ul->fund_val_fixed(t - 1) + ul->prem_paid(t)))
		   * ul->reins_pct;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag)
		return max(0.0, min(vul->rider_chg(t),
		                    vul->fund_val(t - 1) + vul->prem_paid(t)));
		
	// else coinsurance or modified coinsurance
	return max(0.0, min(vul->rider_chg(t),
	                    vul->fund_val_fixed(t - 1) + vul->prem_paid(t)))
		   * vul->reins_pct;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag)
		return max(0.0, min(iul->rider_chg(t),
		                    iul->fund_val_fixed(t - 1) + iul->prem_paid(t)));
		
	// else coinsurance or modified coinsurance
	return max(0.0, min(iul->rider_chg(t),
	                    iul->fund_val_fixed(t - 1) + iul->prem_paid(t)))
		   * iul->reins_pct;
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - sfas133_fia_iul_liab
// SFAS 133 FIA and IUL Liability                                                                                             
// Column:SFAS133_FIA_IUL_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_fia_iul_liab(int t) {
//^^^



//^^^

#line 1 "sfas133_fia_iul_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return embed_deriv_val(t)
       + host_contract_val(t);

}


//@@ END

//@@ START - sfas133_gmab_liab
// SFAS 133 GMAB Liability                                                                                             
// Column:SFAS133_GMAB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_gmab_liab(int t) {
//^^^



//^^^

#line 1 "sfas133_gmab_liab.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

if (t == start_period && valn_period != 0)
	return init_sfas133_gmab_liab;

if (this == sfas97rd)
	return sum_over_gaap("sfas133_gmab_liab", t);

#if defined(__SFAS133_GAAP_H_)
#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!va->sm_va_sfas133.size())
		return NO_AVG;

	return va->sm_va_sfas133[getElementNumber()]->gmab_liab(t);
	}	
#endif
#endif
return NO_AVG;

}


//@@ END

//@@ START - sfas133_gmib_liab
// SFAS 133 GMIB Liability                                                                                             
// Column:SFAS133_GMIB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_gmib_liab(int t) {
//^^^



//^^^

#line 1 "sfas133_gmib_liab.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

if (t == start_period && valn_period != 0)
	return init_sfas133_gmib_liab;

if (this == sfas97rd)
	return sum_over_gaap("sfas133_gmib_liab", t);

#if defined(__SFAS133_GAAP_H_)
#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!va->sm_va_sfas133.size())
		return NO_AVG;

	return va->sm_va_sfas133[getElementNumber()]->gmib_liab(t);
	}
#endif
#endif

return NO_AVG;

}


//@@ END

//@@ START - sfas133_gmwb_liab
// SFAS 133 GMWB Liability                                                                                             
// Column:SFAS133_GMWB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_gmwb_liab(int t) {
//^^^



//^^^

#line 1 "sfas133_gmwb_liab.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

if (t == start_period && valn_period != 0)
	return init_sfas133_gmwb_liab;

if (this == sfas97rd)
	return sum_over_gaap("sfas133_gmwb_liab", t);

#if defined(__SFAS133_GAAP_H_)
#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (!va->sm_va_sfas133.size())
		return NO_AVG;

	return va->sm_va_sfas133[getElementNumber()]->gmwb_liab(t);
	}
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (!fia->sm_fia_sfas133.size())
		return NO_AVG;

	return fia->sm_fia_sfas133[getElementNumber()]->gmwb_liab(t);
	}
#endif
#endif

return NO_AVG;

}


//@@ END

//@@ START - sfas133_liab
// SFAS 133 Liability                                                                                             
// Column:SFAS133_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_liab(int t) {
//^^^



//^^^

#line 1 "sfas133_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return sfas133_gmab_liab(t)
       + sfas133_gmib_liab(t)
       + sfas133_gmwb_liab(t)
       + sfas133_fia_iul_liab(t);

}


//@@ END

//@@ START - sfas133_liab_incr
// SFAS 133 Liability Increase                                                                                             
// Column:SFAS133_LIAB_INCR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_liab_incr(int t) {
//^^^



//^^^

#line 1 "sfas133_liab_incr.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sfas133_liab(t)
       - sfas133_liab(t - 1);

}


//@@ END

//@@ START - sop031_addl_liab
// SOP 03-1 Additional Liability                                                                                             
// Column:SOP031_ADDL_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_addl_liab(int t) {
//^^^



//^^^

#line 1 "sop031_addl_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;
	
#if defined(__UL_LIAB_H_)
return sop031_ulsg_liab(t)
       + sop031_pbr_liab(t)
	   + stat_res_rider(t);
#endif

#if defined(__VUL_LIAB_H_)
return sop031_gmdb_liab(t)
       + sop031_pbr_liab(t)
	   + stat_res_rider(t);
#endif

#if defined(__IUL_LIAB_H_)
return sop031_ulsg_liab(t)
	   + stat_res_rider(t);
#endif

#if defined(__VA_LIAB_H_)
return sop031_gmdb_liab(t)
       + sop031_gmib_liab(t)
       + sop031_gmwb_liab(t);
#endif

return NO_AVG;

}


//@@ END

//@@ START - sop031_addl_liab_incr
// SOP 03-1 Additional Liability Increase                                                                                             
// Column:SOP031_ADDL_LIAB_INCR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_addl_liab_incr(int t) {
//^^^



//^^^

#line 1 "sop031_addl_liab_incr.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return sop031_addl_liab(t)
       - sop031_addl_liab(t - 1);

}


//@@ END

//@@ START - sop031_assess
// SOP 03-1 Assessments                                                                                             
// Column:SOP031_ASSESS
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_assess(int t) {
//^^^



//^^^

#line 1 "sop031_assess.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("sop031_assess", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{// these are assessment components without URL
	double int_gain = 0.0;
	double surr_gain = 0.0;
	double product_loads = 0.0;
	double def_loads = 0.0;
	double coi_charges = 0.0;

	if (!reins_flag //Gross
		|| (reins_flag && ul->reins_flag && ul->coins_flag)) //Ceded and MP Reinsured via Coinsurance
		{
		int_gain = egp_gain_inv(t);
		surr_gain = egp_gain_surr(t);
		product_loads = loads(t);
		def_loads = deferred_loads(t);
		coi_charges = charges(t);
		}

	return int_gain
	       + product_loads 
	       - def_loads
		   + coi_charges
		   + surr_gain;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{// these are assessment components without URL
	double int_gain = 0.0;
	double surr_gain = 0.0;
	double product_loads = 0.0;
	double def_loads = 0.0;
	double coi_charges = 0.0;

	if (!reins_flag //Gross
		|| (reins_flag && vul->reins_flag && vul->coins_flag)) //Ceded and MP Reinsured via Coinsurance
		{
		int_gain = egp_gain_inv(t);
		surr_gain = egp_gain_surr(t);
		product_loads = loads(t);
		def_loads = deferred_loads(t);
		coi_charges = charges(t);
		}

	return int_gain
	       + product_loads 
	       - def_loads
		   + coi_charges
		   + surr_gain;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{// these are assessment components without URL
	double int_gain = 0.0;
	double surr_gain = 0.0;
	double product_loads = 0.0;
	double def_loads = 0.0;
	double coi_charges = 0.0;

	if (!reins_flag //Gross
		|| (reins_flag && iul->reins_flag && iul->coins_flag)) //Ceded and MP Reinsured via Coinsurance
		{
		int_gain = egp_gain_inv(t);
		surr_gain = egp_gain_surr(t);
		product_loads = loads(t);
		def_loads = deferred_loads(t);
		coi_charges = charges(t);
		}

	return int_gain
	       + product_loads 
	       - def_loads
		   + coi_charges
		   + surr_gain;
	}
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	double exp_rev = 0.0;
	double guar_ben_rev = 0.0;
	double int_rev = 0.0;
	double reins_pct = va->reins_pct;
	
	if (!reins_flag) //Gross
		{	
		exp_rev = va->admin_fee(t)
				+ va->m_and_e_fee(t)	
				+ va->sub_adv_fees(t)
				+ va->surr_chg(t);
		
		guar_ben_rev 
		        = va->gmab_chg(t) 
		        + va->gmdb_chg(t)
		        + va->eeb_chg(t) 
				+ va->gmib_chg(t) 
				+ va->gmwb_chg(t);
		
		int_rev = egp_gain_inv(t);
		}
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		{
		if (va->reins_coverage_defn == RIDER_ONLY)
			exp_rev = 0.0;
		else	
			exp_rev = (va->admin_fee(t)
					   + va->m_and_e_fee(t)
					   + va->sub_adv_fees(t)
					   + va->surr_chg(t))
					   * va->reins_pct;
		
		guar_ben_rev
				= va->reins_prem_gmab(t)
				+ va->reins_prem_gmdb(t)
				+ va->reins_prem_gmib(t)
				+ va->reins_prem_gmwb(t)
				+ va->reins_prem_eeb(t);
		
		int_rev = egp_gain_inv(t);		
		}

	//else Ceded and MP Not Reinsured 
	return exp_rev + guar_ben_rev + int_rev;
	}
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	return NO_AVG;
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	return NO_AVG;
#endif

return NO_AVG;

}


//@@ END

//@@ START - sop031_assess_accum
// SOP 03-1 Assessments Accumulation                                                                                             
// Column:SOP031_ASSESS_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_assess_accum(int t) {
//^^^



//^^^

#line 1 "sop031_assess_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;
	
if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double assess_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double assess = cohort_history_sop031_assess/*.AtTime(tt)*/;

				assess_accum 
				= assess_accum * (1.0 + gaap_int_rate_mthly) + assess;
				}			
			return assess_accum; 
			}

		//  No History for cell pricing at issue period
		return 0.0;	
		}

	//valn_period != 0
	return init_sop031_assess_accum;
	}
	
double url_amortzn = 0.0;

#if defined(__UL_LIAB_H_) || defined(__VUL_LIAB_H_) || defined(__IUL_LIAB_H_)
url_amortzn = sop031_unearn_rev_liab_incr(t);
#endif

return sop031_assess_accum(t - 1) 
       * (1.0 + gaap_amortzn_int_rate(t))
       + sop031_assess(t) - url_amortzn;

}


//@@ END

//@@ START - sop031_assess_pv
// SOP 03-1 Assessments Present Value                                                                                             
// Column:SOP031_ASSESS_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_assess_pv(int t) {
//^^^



//^^^

#line 1 "sop031_assess_pv.SFAS97RD_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;	

#if defined(__UL_LIAB_H_) || defined(__VUL_LIAB_H_) || defined(__IUL_LIAB_H_)
return (sop031_array[ASSESS_SOP][t + 1] - sop031_unearn_rev_liab_incr(t + 1)
		+ sop031_assess_pv(t + 1)) 
		/ (1.0 + gaap_amortzn_int_rate(t + 1));
#endif

#if defined(__VA_LIAB_H_)
return (sop031_array[ASSESS_SOP][t + 1]
		+ sop031_assess_pv(t + 1)) 
		/ (1.0 + gaap_amortzn_int_rate(t + 1));
#endif

return NO_AVG;

}


//@@ END

//@@ START - sop031_egp
// SOP 03-1 EGP                                                                                             
// Column:SOP031_EGP
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_egp(int t) {
//^^^



//^^^

#line 1 "sop031_egp.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
// EGP without SOP 03-1 adjustments		
return max(0.0, egp_gain_inv(t)
	            + egp_gain_mort(t)
	            + egp_gain_surr(t)
				+ egp_gain_persist_bon_ref(t)
	            + egp_gain_exp(t));

}


//@@ END

//@@ START - sop031_egp_accum
// SOP 03-1 EGP Accumulation                                                                                             
// Column:SOP031_EGP_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_egp_accum(int t) {
//^^^



//^^^

#line 1 "sop031_egp_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;
	
if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;
		
if (t == start_period)
	{
	if (valn_period == 0)
		{					
		if (this == sfas97rd)
			{
			double egp_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double egp = cohort_history_agp/*.AtTime(tt)*/;
				
				egp_accum 
				= egp_accum * (1.0 + gaap_int_rate_mthly) + egp;
			
				}			
			return egp_accum; 
			}

		//  No History for cell pricing at issue period
		return 0.0;	
		}		

	//valn_period != 0
	return init_egp_accum;
	}
	
return sop031_egp_accum(t - 1) 
       * (1.0 + gaap_amortzn_int_rate(t))
       + sop031_egp(t);

}


//@@ END

//@@ START - sop031_egp_pv
// SOP 03-1 EGP Present Value                                                                                             
// Column:SOP031_EGP_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_egp_pv(int t) {
//^^^



//^^^

#line 1 "sop031_egp_pv.SFAS97RD_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;
	
return (sop031_egp(t + 1) + sop031_egp_pv(t + 1))
	   / (1.0 + gaap_amortzn_int_rate(t + 1));

}


//@@ END

//@@ START - sop031_gmdb_ben_accum
// SOP 03-1 GMDB Benefit Accumulation                                                                                             
// Column:SOP031_GMDB_BEN_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_ben_accum(int t) {
//^^^



//^^^

#line 1 "sop031_gmdb_ben_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;
	
if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;	
	
if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double db_ben_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double db_ben = cohort_history_sop031_gmdb_benefits/*.AtTime(tt)*/;
				
				db_ben_accum 
				= db_ben_accum * (1.0 + gaap_int_rate_mthly) + db_ben;
				}			

			return db_ben_accum; 
			}
		//  No History for cell pricing at issue period
		return 0.0;	
		}	

	//valn_period != 0
	return init_sop031_gmdb_ben_accum;
	}
		
return sop031_gmdb_ben_accum(t - 1) 
       * (1.0 + gaap_amortzn_int_rate(t))
       + gmdb_ben(t);

}


//@@ END

//@@ START - sop031_gmdb_ben_pv
// SOP 03-1 GMDB Benefit Present Value                                                                                             
// Column:SOP031_GMDB_BEN_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_ben_pv(int t) {
//^^^



//^^^

#line 1 "sop031_gmdb_ben_pv.SFAS97RD_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

return (sop031_array[DB_BEN_SOP][t + 1]
		+ sop031_gmdb_ben_pv(t + 1)) 
		/ (1.0 + gaap_amortzn_int_rate(t + 1));

}


//@@ END

//@@ START - sop031_gmdb_br
// SOP 03-1 GMDB Benefit Ratio                                                                                             
// Column:SOP031_GMDB_BR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_br(int t) {
//^^^



//^^^

#line 1 "sop031_gmdb_br.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

double db_br = 0.0;	

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		if (sop031_assess_accum(t) + sop031_assess_pv(t) > model_point_amount_threshold)
			{ // values are - if accum, TO point in time , - if pv, AT point in time
			db_br = (sop031_gmdb_ben_accum(t) + sop031_gmdb_ben_pv(t)) 
					/ (sop031_assess_accum(t) + sop031_assess_pv(t));
			
			return db_br;
			}
		else
			return 0.0;	
		}

	if (valn_period == 0)
		return sop031_gmdb_br_sch(t);
	else
		return init_sop031_gmdb_br;		
	}
else
	{
	if (t == start_period + 1 && !valn_flag)
		return sop031_gmdb_br_sch(t - 1); 
	}

return sop031_gmdb_br(t - 1);

}


//@@ END

//@@ START - sop031_gmdb_br_sch
// SOP 03-1 GMDB Benefit Ratio Schedule                                                                                             
// Column:SOP031_GMDB_BR_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_br_sch(int t) {
//^^^



//^^^

#line 1 "sop031_gmdb_br_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

return gaap_schedule[SOP031_GMDB_BR][0];

}


//@@ END

//@@ START - sop031_gmdb_liab
// SOP 03-1 GMDB Liability                                                                                             
// Column:SOP031_GMDB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_liab(int t) {
//^^^



//^^^

#line 1 "sop031_gmdb_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return max(0.0 , sop031_assess_accum(t) * sop031_gmdb_br(t)
				 - sop031_gmdb_ben_accum(t));

}


//@@ END

//@@ START - sop031_gmib_ben_accum
// SOP 03-1 GMIB Benefit Accumulation                                                                                             
// Column:SOP031_GMIB_BEN_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmib_ben_accum(int t) {
//^^^



//^^^

#line 1 "sop031_gmib_ben_accum.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*!gmib_sop031_flag ||*/ t < start_period || t > final_period)
	return NO_AVG;

if (!gmib_sop031_flag)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;	

if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double ib_ben_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double ib_ben = cohort_history_sop031_gmib_benefits/*.AtTime(tt)*/;
				
				ib_ben_accum 
				= ib_ben_accum * (1.0 + gaap_int_rate_mthly) + ib_ben;
				}			
			return ib_ben_accum; 
			}

		//  No History for cell pricing at issue period
		return 0.0;	
		}	

	//valn_period != 0
	return init_sop031_gmib_ben_accum;
	}
		
return sop031_gmib_ben_accum(t - 1) 
       * (1.0 + gaap_amortzn_int_rate(t))
       + gmib_ben(t);

}


//@@ END

//@@ START - sop031_gmib_ben_pv
// SOP 03-1 GMIB Benefit Present Value                                                                                             
// Column:SOP031_GMIB_BEN_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmib_ben_pv(int t) {
//^^^



//^^^

#line 1 "sop031_gmib_ben_pv.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*!gmib_sop031_flag ||*/ t < start_period || t >= final_period)
	return NO_AVG;

if (!gmib_sop031_flag)
	return NO_AVG;

return (sop031_array[IB_BEN_SOP][t + 1]
		+ sop031_gmib_ben_pv(t + 1)) 
		/ (1.0 + gaap_amortzn_int_rate(t + 1));

}


//@@ END

//@@ START - sop031_gmib_br
// SOP 03-1 GMIB Benefit Ratio                                                                                             
// Column:SOP031_GMIB_BR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmib_br(int t) {
//^^^



//^^^

#line 1 "sop031_gmib_br.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*!gmib_sop031_flag ||*/ t < start_period || t > final_period)
	return NO_AVG;

if (!gmib_sop031_flag)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		if ((sop031_assess_accum(t) + sop031_assess_pv(t)) <= model_point_amount_threshold)
			return 0.0;

		// values are - if accum, TO point in time , - if pv, AT point in time
		return (sop031_gmib_ben_accum(t) + sop031_gmib_ben_pv(t)) 
			   / (sop031_assess_accum(t) + sop031_assess_pv(t));
		}	

	if (valn_period == 0)
		return sop031_gmib_br_sch(t);
	else
		return init_sop031_gmib_br;	
	}
else
	{
	if (t == start_period + 1 && !valn_flag)
		return sop031_gmib_br_sch(t - 1);
	}

return sop031_gmib_br(t - 1);

}


//@@ END

//@@ START - sop031_gmib_br_sch
// SOP 03-1 GMIB Benefit Ratio Schedule                                                                                             
// Column:SOP031_GMIB_BR_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmib_br_sch(int t) {
//^^^



//^^^

#line 1 "sop031_gmib_br_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*!gmib_sop031_flag || valn_flag ||*/ t < start_period || t > final_period)
	return NO_AVG;

if (!gmib_sop031_flag || valn_flag)
	return NO_AVG;
return gaap_schedule[SOP031_GMIB_BR][0];

}


//@@ END

//@@ START - sop031_gmib_liab
// SOP 03-1 GMIB Liability                                                                                             
// Column:SOP031_GMIB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmib_liab(int t) {
//^^^



//^^^

#line 1 "sop031_gmib_liab.SFAS97RD_GAAP.for"
if (!gmib_sop031_flag || t < start_period || t > final_period)
	return NO_AVG;

return max(0.0 , sop031_assess_accum(t) * sop031_gmib_br(t)
				 - sop031_gmib_ben_accum(t));

}


//@@ END

//@@ START - sop031_gmwb_ben_accum
// SOP 03-1 GMWB Benefit Accumulation                                                                                             
// Column:SOP031_GMWB_BEN_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmwb_ben_accum(int t) {
//^^^



//^^^

#line 1 "sop031_gmwb_ben_accum.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*!gmwb_sop031_flag ||*/ t < start_period || t > final_period)
	return NO_AVG;

if (!gmwb_sop031_flag)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;	

if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double wb_ben_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double wb_ben = cohort_history_sop031_gmwb_benefits/*.AtTime(tt)*/;
				
				wb_ben_accum 
				= wb_ben_accum * (1.0 + gaap_int_rate_mthly) + wb_ben;
				}			
			return wb_ben_accum; 
			}

		//  No History for cell pricing at issue period
		return 0.0;	
		}	

	//valn_period != 0
	return init_sop031_gmwb_ben_accum;
	}
		
return sop031_gmwb_ben_accum(t - 1) 
       * (1.0 + gaap_amortzn_int_rate(t))
       + gmwb_ben(t);

}


//@@ END

//@@ START - sop031_gmwb_ben_pv
// SOP 03-1 GMWB Benefit Present Value                                                                                             
// Column:SOP031_GMWB_BEN_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmwb_ben_pv(int t) {
//^^^



//^^^

#line 1 "sop031_gmwb_ben_pv.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*!gmwb_sop031_flag ||*/ t < start_period || t >= final_period)
	return NO_AVG;

if (!gmwb_sop031_flag)
	return NO_AVG;

return (sop031_array[WB_BEN_SOP][t + 1]
		+ sop031_gmwb_ben_pv(t + 1))
		/ (1.0 + gaap_amortzn_int_rate(t + 1));

}


//@@ END

//@@ START - sop031_gmwb_br
// SOP 03-1 GMWB Benefit Ratio                                                                                             
// Column:SOP031_GMWB_BR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmwb_br(int t) {
//^^^



//^^^

#line 1 "sop031_gmwb_br.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*!gmwb_sop031_flag ||*/ t < start_period || t > final_period)
	return NO_AVG;

if (!gmwb_sop031_flag)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		if ((sop031_assess_accum(t) + sop031_assess_pv(t)) <= model_point_amount_threshold)
			return 0.0;

		// values are - if accum, TO point in time , - if pv, AT point in time
		return (sop031_gmwb_ben_accum(t) + sop031_gmwb_ben_pv(t)) 
			   / (sop031_assess_accum(t) + sop031_assess_pv(t));
		}

	if (valn_period == 0)
		return sop031_gmwb_br_sch(t);
	else
		return init_sop031_gmwb_br;
	}
else
	{
	if (t == start_period + 1 && !valn_flag)
		return sop031_gmwb_br_sch(t - 1);
	}

return sop031_gmwb_br(t - 1);

}


//@@ END

//@@ START - sop031_gmwb_br_sch
// SOP 03-1 GMWB Benefit Ratio Schedule                                                                                             
// Column:SOP031_GMWB_BR_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmwb_br_sch(int t) {
//^^^



//^^^

#line 1 "sop031_gmwb_br_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*!gmwb_sop031_flag || valn_flag ||*/ t < start_period || t > final_period)
	return NO_AVG;

if (!gmwb_sop031_flag || valn_flag)
	return NO_AVG;

return gaap_schedule[SOP031_GMWB_BR][0];

}


//@@ END

//@@ START - sop031_gmwb_liab
// SOP 03-1 GMWB Liability                                                                                             
// Column:SOP031_GMWB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmwb_liab(int t) {
//^^^



//^^^

#line 1 "sop031_gmwb_liab.SFAS97RD_GAAP.for"
if (!gmwb_sop031_flag || t < start_period || t > final_period)
	return NO_AVG;

return max(0.0, sop031_assess_accum(t) * sop031_gmwb_br(t) 
                - sop031_gmwb_ben_accum(t));

}


//@@ END

//@@ START - sop031_pbr
// SOP 03-1 Persistency Bonus/Refunds                                                                                             
// Column:SOP031_PBR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr(int t) {
//^^^



//^^^

#line 1 "sop031_pbr.SFAS97RD_GAAP.for"
if (t <= start_period || t > pbr_final_period)
	return NO_AVG;

if (sfas97rd_valn_flag)
	{
	if (this == sfas97rd)
		return sum_over_gaap("sop031_pbr", t);
		
	#if defined(__UL_LIAB_H_)
	if (this == ul_sfas97rd)
		{
		if (!reins_flag) //Gross
			return (ul->sm_ul_ifund_curr->persist_bon(t) 
				    + ul->sm_ul_ifund_curr->persist_ref(t))
				   * sop031_pbr_units_inf(t - 1);
		
		if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured via Coinsurance
			return (ul->sm_ul_ifund_curr->persist_bon(t) 
				    + ul->sm_ul_ifund_curr->persist_ref(t))
				   * ul->reins_pct
				   * sop031_pbr_units_inf(t - 1);
	
		//Ceded and MP Not Reinsured
		return 0.0;
		}
	#endif

	#if defined(__VUL_LIAB_H_)
	if (this == vul_sfas97rd)
		{
		if (!reins_flag) //Gross
			return (vul->sm_vul_ifund_curr->persist_bon(t)) 
				   * sop031_pbr_units_inf(t - 1);
		
		if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured via Coinsurance
			return (vul->sm_vul_ifund_curr->persist_bon(t)) 
	 			   * vul->reins_pct
	 			   * sop031_pbr_units_inf(t - 1);
	
		//Ceded and MP Not Reinsured
		return 0.0;
		}
	#endif
	
	return NO_AVG;
	}

return gaap_schedule[SOP031_PBR][t];

}


//@@ END

//@@ START - sop031_pbr_accum
// SOP 03-1 Persistency Bonus/Refund Accumulation                                                                                             
// Column:SOP031_PBR_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_accum(int t) {
//^^^



//^^^

#line 1 "sop031_pbr_accum.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*sop031_ul_vul_iul_defn == NO || */t < start_period || t > pbr_final_period)
	return NO_AVG;

if (sop031_ul_vul_iul_defn == NO)
	return NO_AVG;
	
if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;
	
if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double pbr_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double pbr = cohort_history_sop031_pbr_benefits/*.AtTime(tt)*/;
				pbr_accum = pbr_accum * (1.0 + gaap_int_rate_mthly) + pbr;
				}
			return pbr_accum;
			}
		//No History for cell pricing at issue period
		return 0.0;
		}
	//valn_period != 0
	return init_sop031_pbr_accum;
	}
	
return sop031_pbr_accum(t - 1) 
	   * (1.0 + gaap_amortzn_int_rate(t))
	   + persist_bon_ref(t);

}


//@@ END

//@@ START - sop031_pbr_fund_val
// SOP 03-1 Persistency Bonus/Refund Fund Value                                                                                             
// Column:SOP031_PBR_FUND_VAL
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_fund_val(int t) {
//^^^



//^^^

#line 1 "sop031_pbr_fund_val.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*sop031_ul_vul_iul_defn == NO || */t < start_period || t > pbr_final_period)
	return NO_AVG;

if (sop031_ul_vul_iul_defn == NO)
	return NO_AVG;
	
if (sfas97rd_valn_flag)
	{
	if (this == sfas97rd)
		return max(0.0, sum_over_gaap("sop031_pbr_fund_val", t));

	#if defined(__UL_LIAB_H_)
	if (this == ul_sfas97rd)
		{
		double sop031_pbr_fund_val
		= ul->fund_val_aft_withdrl_per_unit(t)
	      * sop031_pbr_units_inf(t);
	
		if (!reins_flag) //Gross
			{
			if (pricing_flag)
				return max(0.0, sop031_pbr_fund_val);
	
			return sop031_pbr_fund_val;
			}
		else if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured	
			{
			if (pricing_flag)
				return max(0.0, sop031_pbr_fund_val * ul->reins_pct);
	
			return sop031_pbr_fund_val * ul->reins_pct;		
			}
		else //Ceded and MP Not Reinsured
			return 0.0;	
		}
	#endif

	#if defined(__VUL_LIAB_H_)
	if (this == vul_sfas97rd)
		{
		double sop031_pbr_fund_val
		= vul->fund_val_aft_withdrl_per_unit(t)   
	      * sop031_pbr_units_inf(t);
	
		double sop031_pbr_pol_loan		// consider negative unloaned fund only
		= vul->pol_loan_per_unit(t) * sop031_pbr_units_inf(t);
	
		if (!reins_flag) //Gross
			{
			if (pricing_flag)
				return sop031_pbr_pol_loan 
				       + max(0.0, sop031_pbr_fund_val - sop031_pbr_pol_loan);
	
			return sop031_pbr_fund_val;
			}
			
		else if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured	
			{
			if (pricing_flag)
				return (sop031_pbr_pol_loan 
				        + max(0.0, sop031_pbr_fund_val - sop031_pbr_pol_loan))
				       * vul->reins_pct;
	
			return sop031_pbr_fund_val * vul->reins_pct;		
			}
		else //Ceded and MP Not Reinsured
			return 0.0;	
		}
	#endif
	return NO_AVG;
	}

return gaap_schedule[SOP031_PBR_FV][t];

}


//@@ END

//@@ START - sop031_pbr_fund_val_accum
// SOP 03-1 Persistency Bonus/Refund Fund Value Accumulation                                                                                             
// Column:SOP031_PBR_FUND_VAL_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_fund_val_accum(int t) {
//^^^



//^^^

#line 1 "sop031_pbr_fund_val_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > pbr_final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;
	
if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double fvf_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double fvf = cohort_history_sop031_pbr_fund_val/*.AtTime(tt)*/;
				
				fvf_accum
				= fvf_accum * (1.0 + gaap_int_rate_mthly) + fvf;
				
				}
			return fvf_accum;
			}
			
		//No History for cell pricing at issue period
		return 0.0;
		}
		
	//valn_period != 0
	return init_sop031_pbr_fund_val_accum;
	}
	
return sop031_pbr_fund_val_accum(t - 1)
       * (1.0 + gaap_amortzn_int_rate(t))
       + fund_val(t);

}


//@@ END

//@@ START - sop031_pbr_fund_val_pv
// SOP 03-1 Persistency Bonus/Refund Fund Value Present Value                                                                                             
// Column:SOP031_PBR_FUND_VAL_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_fund_val_pv(int t) {
//^^^



//^^^

#line 1 "sop031_pbr_fund_val_pv.SFAS97RD_GAAP.for"
if (t < start_period || t > pbr_final_period)
	return NO_AVG;
	
return (sop031_pbr_fund_val(t + 1) + sop031_pbr_fund_val_pv(t + 1))
		/ (1.0 + gaap_amortzn_int_rate(t + 1));

}


//@@ END

//@@ START - sop031_pbr_liab
// SOP 03-1 Persistency Bonus/Refund Liability                                                                                             
// Column:SOP031_PBR_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_liab(int t) {
//^^^



//^^^

#line 1 "sop031_pbr_liab.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*sop031_ul_vul_iul_defn == NO || */t < start_period || t > pbr_final_period)
	return NO_AVG;

if (sop031_ul_vul_iul_defn == NO)
	return NO_AVG;

if (sfas97rd_valn_flag)
	return max(0.0, sop031_pbr_pv(t) - k_sop031_pbr(t) * sop031_pbr_fund_val_pv(t));

// retrieve starting sop031 pbr liability
if (t == start_period)
	{
	if (valn_period == 0 )
		return sop031_pbr_liab_sch(t);
	else 
		return init_sop031_pbr_liab;
	}
	
if ((!sfas97rd_valn_flag && !valn_flag)
	&& t == start_period + 1 && valn_period > 0) 
	return max(0.0, sop031_pbr_liab_sch(t - 1)
					+ sop031_pbr_liab_int(t)
		   		    - sop031_pbr(t)
		   		    + sop031_pbr_liab_amortzn(t));
	
return max(0.0, sop031_pbr_liab(t - 1) 
	   		    + sop031_pbr_liab_int(t)
	   		    - sop031_pbr(t)
	   		    + sop031_pbr_liab_amortzn(t));

}


//@@ END

//@@ START - sop031_pbr_liab_amortzn
// SOP 03-1 Persistency Bonus/Refund Liability Amortization                                                                                             
// Column:SOP031_PBR_LIAB_AMORTZN
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_liab_amortzn(int t) {
//^^^



//^^^

#line 1 "sop031_pbr_liab_amortzn.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

return sop031_pbr_fund_val(t) * k_sop031_pbr(t - 1);

}


//@@ END

//@@ START - sop031_pbr_liab_int
// SOP 03-1 Persistency Bonus/Refund Liability Interest                                                                                             
// Column:SOP031_PBR_LIAB_INT
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_liab_int(int t) {
//^^^



//^^^

#line 1 "sop031_pbr_liab_int.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

double sop031_pbr_liab_prev_local = 0.0;

if ((!sfas97rd_valn_flag && !valn_flag)
	&& t == start_period + 1 && valn_period > 0) 
	sop031_pbr_liab_prev_local = sop031_pbr_liab_sch(t - 1);
else 
	sop031_pbr_liab_prev_local = sop031_pbr_liab(t - 1);
	
return sop031_pbr_liab_prev_local
   	   * gaap_amortzn_int_rate(t);

}


//@@ END

//@@ START - sop031_pbr_liab_sch
// SOP 03-1 Persistency Bonus/Refund Liability Schedule                                                                                             
// Column:SOP031_PBR_LIAB_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_liab_sch(int t) {
//^^^



//^^^

#line 1 "sop031_pbr_liab_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*sop031_ul_vul_iul_defn == NO || valn_flag || */t < start_period || t > pbr_final_period)
	return NO_AVG;

if (sop031_ul_vul_iul_defn == NO || valn_flag)
	return NO_AVG;

return gaap_schedule[SOP031_PBR_LIAB][0];

}


//@@ END

//@@ START - sop031_pbr_pv
// SOP 03-1 Persistency Bonus/Refund Present Value                                                                                             
// Column:SOP031_PBR_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_pv(int t) {
//^^^



//^^^

#line 1 "sop031_pbr_pv.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*sop031_ul_vul_iul_defn == NO || */t < start_period || t >= pbr_final_period)
	return NO_AVG;

if (sop031_ul_vul_iul_defn == NO)
	return NO_AVG;
	
return (sop031_pbr(t + 1)
		+ sop031_pbr_pv(t + 1))
		/ (1.0 + gaap_amortzn_int_rate(t + 1));

}


//@@ END

//@@ START - sop031_pbr_units_inf
// SOP 03-1 Persistency Bonus/Refund Units Inforce                                                                                             
// Column:SOP031_PBR_UNITS_INF
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_units_inf(int t) {
//^^^



//^^^

#line 1 "sop031_pbr_units_inf.SFAS97RD_GAAP.for"
if (sop031_ul_vul_iul_defn == NO || t < start_period || t > pbr_final_period)
	return NO_AVG;
	
if (this == sfas97rd)
	return NO_AVG;
	
#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (t == start_period)
		return ul->units_inf(t);

	double sop031_pbr_dths_units = 0.0;
	double sop031_pbr_maturities_units = 0.0;

	sop031_pbr_dths_units 
	= sop031_pbr_units_inf(t - 1)
	  * ul->dth_claim_rate_mthly(t);

	if (t == ul->maturity_period)
		sop031_pbr_maturities_units 
		= sop031_pbr_units_inf(t - 1)
		  - sop031_pbr_dths_units;

	return sop031_pbr_units_inf(t - 1)
	       - sop031_pbr_dths_units
	       - sop031_pbr_maturities_units;  
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (t == start_period)
		return vul->units_inf(t);

	double sop031_pbr_dths_units = 0.0;
	double sop031_pbr_maturities_units = 0.0;

	sop031_pbr_dths_units 
	= sop031_pbr_units_inf(t - 1)
	  * vul->dth_claim_rate_mthly(t);

	if (t == vul->maturity_period)
		sop031_pbr_maturities_units 
		= sop031_pbr_units_inf(t - 1)
		  - sop031_pbr_dths_units;

	return sop031_pbr_units_inf(t - 1)
	       - sop031_pbr_dths_units
	       - sop031_pbr_maturities_units;  
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - sop031_ulsg_ben_accum
// SOP 03-1 ULSG Benefits Accumulation                                                                                             
// Column:SOP031_ULSG_BEN_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_ben_accum(int t) {
//^^^



//^^^

#line 1 "sop031_ulsg_ben_accum.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*sop031_ul_vul_iul_defn == NO || */t < start_period || t > final_period)
	return NO_AVG;

if (sop031_ul_vul_iul_defn == NO)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double sg_ben_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double sg_ben = cohort_history_sop031_sg_benefits/*.AtTime(tt)*/;
				
				sg_ben_accum 
				= sg_ben_accum * (1.0 + gaap_int_rate_mthly) + sg_ben;
				}			
			return sg_ben_accum; 
			}

		//  No History for cell pricing at issue period
		return 0.0;	
		}	

	//valn_period != 0
	return init_sop031_ulsg_ben_accum;
	}
	
return sop031_ulsg_ben_accum(t - 1) 
       * (1.0 + gaap_amortzn_int_rate(t))
       + ulsg_ben(t);

}


//@@ END

//@@ START - sop031_ulsg_ben_pv
// SOP 03-1 ULSG Benefit Present Value                                                                                             
// Column:SOP031_ULSG_BEN_PV
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_ben_pv(int t) {
//^^^



//^^^

#line 1 "sop031_ulsg_ben_pv.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*sop031_ul_vul_iul_defn == NO || */t < start_period || t >= final_period)
	return NO_AVG;

if (sop031_ul_vul_iul_defn == NO)
	return NO_AVG;

return (sop031_array[SG_BEN_SOP][t + 1]
		+ sop031_ulsg_ben_pv(t + 1))
		/ (1.0 + gaap_amortzn_int_rate(t + 1));

}


//@@ END

//@@ START - sop031_ulsg_br
// SOP 03-1 ULSG Benefit Ratio                                                                                             
// Column:SOP031_ULSG_BR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_br(int t) {
//^^^



//^^^

#line 1 "sop031_ulsg_br.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*sop031_ul_vul_iul_defn == NO || */t < start_period || t > final_period)
	return NO_AVG;

if (sop031_ul_vul_iul_defn == NO)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		{
		if ((sop031_assess_accum(t) + sop031_assess_pv(t)) <= model_point_amount_threshold)
			return 0.0;
		
		// Values are - if accum, TO point in time , - if pv, AT point in time
		return (sop031_ulsg_ben_accum(t) + sop031_ulsg_ben_pv(t)) 
			   / (sop031_assess_accum(t) + sop031_assess_pv(t));
		}	

	if (valn_period == 0)
		return sop031_ulsg_br_sch(t);
	else
		return init_sop031_ulsg_br;
	}
else
	{
	if (t == start_period + 1 && !valn_flag)
		return sop031_ulsg_br_sch(t - 1); 
	}

return sop031_ulsg_br(t - 1);

}


//@@ END

//@@ START - sop031_ulsg_br_sch
// SOP 03-1 ULSG Benefit Ratio Schedule                                                                                             
// Column:SOP031_ULSG_BR_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_br_sch(int t) {
//^^^



//^^^

#line 1 "sop031_ulsg_br_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*sop031_ul_vul_iul_defn == NO || valn_flag || */t < start_period || t > final_period)
	return NO_AVG;

if (sop031_ul_vul_iul_defn == NO || valn_flag)
	return NO_AVG;

return gaap_schedule[SOP031_ULSG_BR][0];

}


//@@ END

//@@ START - sop031_ulsg_liab
// SOP 03-1 ULSG Liability                                                                                             
// Column:SOP031_ULSG_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_liab(int t) {
//^^^



//^^^

#line 1 "sop031_ulsg_liab.SFAS97RD_GAAP.for"
if (sop031_ul_vul_iul_defn == NO || t < start_period || t > final_period)
	return NO_AVG;

return max(0.0, sop031_assess_accum(t) * sop031_ulsg_br(t) 
                - sop031_ulsg_ben_accum(t));

}


//@@ END

//@@ START - sop031_unearn_rev_liab_incr
// SOP 03-1 Approximation URL Increase                                                                                             
// Column:SOP031_UNEARN_REV_LIAB_INCR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_unearn_rev_liab_incr(int t) {
//^^^



//^^^

#line 1 "sop031_unearn_rev_liab_incr.SFAS97RD_GAAP.for"
if (sop031_ul_vul_iul_defn == NO || t <= start_period || t > final_period)
	return NO_AVG;
	
#if defined(__VUL_LIAB_H_)
return k_sop031_unearn_rev_liab(t)
	   * (sop031_egp(t) + gmdb_ben(t))
   	/ (1.0 + k_sop031_unearn_rev_liab(t) + k_sop031_gmdb_ben_br(t));
#endif	
	
return k_sop031_unearn_rev_liab(t)
	   * (sop031_egp(t) + ulsg_ben(t))
	   / (1.0 + k_sop031_unearn_rev_liab(t) + k_sop031_ulsg_ben_br(t));

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double SFAS97RD_GAAP_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.SFAS97RD_GAAP.for"
#if 0 // START_EXTERNS
deptaskinput sop031_valn_input;
deptaskcols sop031_valn_input_cols;
deptaskmap sop031_valn_input_pos;
deptaskmapiter sop031_valn_input_pos_iter;
deptaskinput sfas97rd_valn_input;
deptaskcols sfas97rd_valn_input_cols;
deptaskmap sfas97rd_valn_input_pos;
deptaskmapiter sfas97rd_valn_input_pos_iter;
sowfoutput sfas97rd_state_of_world_financial_output;
sowfinput sfas97rd_state_of_world_financial_input;
sowfcols sfas97rd_state_of_world_financial_cols;
sowfmap sfas97rd_state_of_world_financial_input_pos;
sowfmapiter sfas97rd_state_of_world_financial_input_pos_iter;
const int ASSESS_SOP = 0;
const int DB_BEN_SOP = 1;
const int IB_BEN_SOP = 2;
const int WB_BEN_SOP = 3;
const int SG_BEN_SOP = 4;
const int DTH_CLAIM_COST = 5;
const int SOP_SIZE = 6;
const int EGP = 0;
const int INT_RATE = 1;
const int SOP031_PBR_FV = 2;
const int SOP031_PBR = 3;
const int DAC_ACQ_EXP = 4;
const int DAC_ACQ_EXP_LOSS_REC = 5;
const int DAC_COMM = 6;
const int DAC_COMM_LOSS_REC = 7;
const int DAC_PREM_BONUS = 8;
const int DAC_PREM_BONUS_LOSS_REC = 9;
const int DAC_REINS_YRT_ASSET = 10;
const int EMBED_DERIV_VAL = 11;
const int K_CAPZD_ACQ_EXP = 12;
const int K_CAPZD_COMM = 13;
const int K_CAPZD_PREM_BONUS = 14;
const int K_REINS_YRT_COST = 15;
const int K_SOP031_GMDB_BEN_BR = 16;
const int K_SOP031_PBR = 17;
const int K_SOP031_ULSG_BEN_BR = 18;
const int K_SOP031_UNEARN_REV_LIAB = 19;
const int K_UNEARN_REV_LIAB = 20;
const int SOP031_GMDB_BR = 21;
const int SOP031_GMIB_BR = 22;
const int SOP031_GMWB_BR = 23;
const int SOP031_PBR_LIAB = 24;
const int SOP031_ULSG_BR = 25;
const int UNEARN_REV_LIAB = 26;
const int GAAP_SCHEDULE_SIZE = 27;

#if defined(__VA_LIAB_H_)
// integers from VA_POL submodel
extern int AV_B_GA;
extern int AV_B_DCA;
#endif//WTW - Gen2 - cannot have IF/ELSE in EXTERN section

/*#else //WTW - Gen2 - Move outside of EXTERNS
// integers from VA_POL submodel
int AV_B_DCA = 0;
int AV_B_GA = 1;
#endif*/

#endif // END_EXTERNS

#if 0 // START_CLASS
#if !defined(__VA_LIAB_H_) //WTW - Gen2 - Move outside of EXTERNS
// integers from VA_POL submodel
int AV_B_DCA = 0;
int AV_B_GA = 1;
#endif

//typedef map <int, long, less <int> > mpmap;//Gen2 - 9/6/2024 - comment out typedef
map <int, long, less <int> > ul_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
map <int, long, less <int> > vul_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
map <int, long, less <int> > iul_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
map <int, long, less <int> > va_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
map <int, long, less <int> > fa_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
map <int, long, less <int> > fia_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
map <int, long, less <int> > epl_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
xstring reins_defn;
int cohort_reins_indicator;
int cohort_reins_yrt_indicator;
int cohort_first_issue_period;
int cohort_last_issue_period;
int cohort_max_maturity_period;
SmartArray <SmartArray <double> > sop031_array;
SmartArray <SmartArray <double> > gaap_schedule;
double init_dac_acq_exp;
double init_dac_acq_exp_loss_rec;
double init_capzd_acq_exp_accum;
double init_capzd_acq_exp_accum_loss_rec_int_rate;
double init_dac_acq_exp_loss_rec_accum;
double init_dac_comm;
double init_dac_comm_loss_rec;
double init_capzd_comm_accum;
double init_capzd_comm_accum_loss_rec_int_rate;
double init_dac_comm_loss_rec_accum;
double init_dac_prem_bonus;
double init_dac_prem_bonus_loss_rec;
double init_capzd_prem_bonus_accum;
double init_capzd_prem_bonus_accum_loss_rec_int_rate;
double init_dac_prem_bonus_loss_rec_accum;
double init_egp_accum;
double init_egp_accum_loss_rec_int_rate;
double init_sop031_assess_accum;
double init_sop031_gmdb_ben_accum;
double init_sop031_gmib_ben_accum;
double init_sop031_gmwb_ben_accum;
double init_sop031_pbr_accum;
double init_deferred_loads_accum;
double init_unearn_rev_liab;
double init_dac_reins_yrt_asset;
double init_reins_yrt_cost_accum;
double init_sop031_pbr_fund_val_accum;
double init_embed_deriv_val;
double init_sfas133_gmab_liab;
double init_sfas133_gmib_liab;
double init_sfas133_gmwb_liab;
double init_sop031_ulsg_ben_accum;
double init_sop031_gmdb_br;
double init_sop031_gmib_br;
double init_sop031_gmwb_br;
double init_sop031_pbr_liab;
double init_sop031_ulsg_br;
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
cohort_reins_indicator = 0;
cohort_reins_yrt_indicator = 0;
cohort_first_issue_period = 0;
cohort_last_issue_period = -9999;
cohort_max_maturity_period = -9999;
init_dac_acq_exp = 0.0;
init_dac_acq_exp_loss_rec = 0.0;
init_capzd_acq_exp_accum = 0.0;
init_capzd_acq_exp_accum_loss_rec_int_rate = 0.0;
init_dac_acq_exp_loss_rec_accum = 0.0;
init_dac_comm = 0.0;
init_dac_comm_loss_rec = 0.0;
init_capzd_comm_accum = 0.0;
init_capzd_comm_accum_loss_rec_int_rate = 0.0;
init_dac_comm_loss_rec_accum = 0.0;
init_dac_prem_bonus = 0.0;
init_dac_prem_bonus_loss_rec = 0.0;
init_capzd_prem_bonus_accum = 0.0;
init_capzd_prem_bonus_accum_loss_rec_int_rate = 0.0;
init_dac_prem_bonus_loss_rec_accum = 0.0;
init_egp_accum = 0.0;
init_egp_accum_loss_rec_int_rate = 0.0;
init_sop031_assess_accum = 0.0;
init_sop031_gmdb_ben_accum = 0.0;
init_sop031_gmib_ben_accum = 0.0;
init_sop031_gmwb_ben_accum = 0.0;
init_sop031_pbr_accum = 0.0;
init_deferred_loads_accum = 0.0;
init_unearn_rev_liab = 0.0;
init_dac_reins_yrt_asset = 0.0;
init_reins_yrt_cost_accum = 0.0;
init_sop031_pbr_fund_val_accum = 0.0;
init_embed_deriv_val = 0.0;
init_sfas133_gmab_liab = 0.0;
init_sfas133_gmib_liab = 0.0;
init_sfas133_gmwb_liab = 0.0;
init_sop031_ulsg_ben_accum = 0.0;
init_sop031_gmdb_br = 0.0;
init_sop031_gmib_br = 0.0;
init_sop031_gmwb_br = 0.0;
init_sop031_pbr_liab = 0.0;
init_sop031_ulsg_br = 0.0;
#endif // END_CONSTRUCTOR

#if 0 // START_TERMINATOR
sfas97rd_state_of_world_financial_output.close();
#endif // END_TERMINATOR

if (getElementNumber() == 0)
	cohort_reins_defn = GROSS;
else
	cohort_reins_defn = CEDED;

#if defined (__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (pricing_flag)
		{
		cohort_first_issue_period = ul->commencement_period;
		cohort_last_issue_period = ul->commencement_period;
		}
	else // when running cohort, just set mp's value to zero
		{
		cohort_first_issue_period = 0;
		cohort_last_issue_period = 0;
		}
		
	cohort_max_maturity_period = ul->maturity_period;
	}
#endif

#if defined (__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (pricing_flag)
		{
		cohort_first_issue_period = vul->commencement_period;
		cohort_last_issue_period = vul->commencement_period;
		}
	else // when running cohort, just set mp's value to zero
		{
		cohort_first_issue_period = 0;
		cohort_last_issue_period = 0;
		}
		
	cohort_max_maturity_period = vul->maturity_period;
	}
#endif

#if defined (__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (pricing_flag)
		{
		cohort_first_issue_period = iul->commencement_period;
		cohort_last_issue_period = iul->commencement_period;
		}
	else // when running cohort, just set mp's value to zero
		{
		cohort_first_issue_period = 0;
		cohort_last_issue_period = 0;
		}
		
	cohort_max_maturity_period = iul->maturity_period;
	}
#endif

#if defined (__VA_LIAB_H_)
if (this == va_sfas97rd)
	{
	if (pricing_flag)
		{
		cohort_first_issue_period = -va->elapsed_mths;
		cohort_last_issue_period = -va->elapsed_mths;
		}
	else // when running cohort, just set mp's value to zero
		{
		cohort_first_issue_period = 0;
		cohort_last_issue_period = 0;
		}
		
	cohort_max_maturity_period = va->maturity_period;
	}
#endif

#if defined (__FA_LIAB_H_)
if (this == fa_sfas97rd)
	{
	if (pricing_flag)
		{
		cohort_first_issue_period = -fa->elapsed_mths;
		cohort_last_issue_period = -fa->elapsed_mths;
		}
	else // when running cohort, just set mp's value to zero
		{
		cohort_first_issue_period = 0;
		cohort_last_issue_period = 0;
		}
		
	cohort_max_maturity_period = fa->maturity_period;
	}
#endif

#if defined (__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	{
	if (pricing_flag)
		{
		cohort_first_issue_period = -fia->elapsed_mths;
		cohort_last_issue_period = -fia->elapsed_mths;
		}
	else // when running cohort, just set mp's value to zero
		{
		cohort_first_issue_period = 0;
		cohort_last_issue_period = 0;
		}
		
	cohort_max_maturity_period = fia->maturity_period;
	}
#endif

return 1.0;

}


//@@ END

//@@ START - stat_res_rider
// Statutory Reserve Rider                                                                                             
// Column:STAT_RES_RIDER
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_stat_res_rider(int t) {
//^^^



//^^^

#line 1 "stat_res_rider.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("stat_res_rider", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return ul->stat_res_rider_mp(t) + ul->stat_unearn_prem_res_rider(t);

	return 0.0;
	}
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return iul->stat_res_rider_mp(t) + iul->stat_unearn_prem_res_rider(t);

	return 0.0;
	}
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	{
	if (!reins_flag) //Gross
		return vul->stat_res_rider_mp(t) + vul->stat_unearn_prem_res_rider(t);

	return 0.0;
	}
#endif

return NO_AVG;

}


//@@ END

//@@ START - ulsg_ben
// ULSG Benefits                                                                                             
// Column:ULSG_BEN
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_ulsg_ben(int t) {
//^^^



//^^^

#line 1 "ulsg_ben.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*sop031_ul_vul_iul_defn == NO || */t <= start_period || t > final_period)
	return NO_AVG;

if (sop031_ul_vul_iul_defn == NO)
	return NO_AVG;

if (this == sfas97rd)
	return sum_over_gaap("ulsg_ben", t);

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	{
	if (!ul->sg_indicator (t - 1))
		return NO_AVG;
		
	if ((ul->fund_val_fixed(t) < model_point_amount_threshold
		|| ul->fund_val_fixed(t) < ul->dth_benefits_base_plan(t))
		&& ul->dth_ben_per_unit(t) > model_point_amount_threshold)
		{
		if (!reins_flag) //Gross
			return ul->dth_benefits_base_plan(t) - max(0.0, ul->fund_val_fixed(t));

		else if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured via Coinsurance
			return (ul->dth_benefits_base_plan(t) - max(0.0, ul->fund_val_fixed(t))) 
			       * ul->reins_pct;

		 //Ceded and MP Not Reinsured
		return 0.0;	
		}
	return 0.0;	
	}	
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	{
	if (!iul->sg_indicator (t - 1))
		return NO_AVG;
		
	if ((iul->fund_val_fixed(t) < model_point_amount_threshold
		|| iul->fund_val_fixed(t) < iul->dth_benefits_base_plan(t))
		&& iul->dth_ben_per_unit(t) > model_point_amount_threshold)
		{
		if (!reins_flag) //Gross
			return iul->dth_benefits_base_plan(t) - max(0.0, iul->fund_val_fixed(t));

		else if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured via Coinsurance
			return (iul->dth_benefits_base_plan(t) - max(0.0, iul->fund_val_fixed(t))) 
			       * iul->reins_pct;

		 //Ceded and MP Not Reinsured
		return 0.0;	
		}
	return 0.0;	
	}	
#endif

return NO_AVG;

}


//@@ END

//@@ START - unearn_rev_liab
// Unearned Revenue Liability                                                                                             
// Column:UNEARN_REV_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab(int t) {
//^^^



//^^^

#line 1 "unearn_rev_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (sfas97rd_valn_flag)
		return egp_pv(t) * k_unearn_rev_liab(t) - deferred_loads_pv(t);
	
	// !valn_flag
	if (valn_period == 0)
		return unearn_rev_liab_sch(t);
	else // valn_period > 0
		return init_unearn_rev_liab;
	}
	
if ((!sfas97rd_valn_flag && !valn_flag)
	&& t == start_period + 1 && valn_period > 0) 
	return unearn_rev_liab_sch(t - 1)
		   + deferred_loads(t)
	 	   + unearn_rev_liab_int(t)
	 	   - unearn_rev_liab_amortzn(t);

return unearn_rev_liab(t - 1) 
	   + deferred_loads(t)
	   + unearn_rev_liab_int(t)
	   - unearn_rev_liab_amortzn(t);

}


//@@ END

//@@ START - unearn_rev_liab_accum
// Unearned Revenue Liability Accumulation                                                                                             
// Column:UNEARN_REV_LIAB_ACCUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_accum(int t) {
//^^^



//^^^

#line 1 "unearn_rev_liab_accum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;	

if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (this == sfas97rd)
			{
			double url_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				date_lookup_gen2 = date(tt); //WTW - Gen2 - AtTime() not supported
				double url = cohort_history_unearn_rev_liab/*.AtTime(tt)*/;
				
				url_accum 
				= url_accum * (1.0 + gaap_int_rate_mthly) + url;
				}			
			return url_accum; 
			}
		else //  No History for cell pricing at issue period
			return 0.0;	
		}	
	else //valn_period != 0
		return init_unearn_rev_liab;
	}
		
return unearn_rev_liab_accum(t - 1) * (1.0 + gaap_amortzn_int_rate(t))
         + unearn_rev_liab(t);

}


//@@ END

//@@ START - unearn_rev_liab_amortzn
// Unearned Revenue Liability Amortization                                                                                             
// Column:UNEARN_REV_LIAB_AMORTZN
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_amortzn(int t) {
//^^^



//^^^

#line 1 "unearn_rev_liab_amortzn.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return egp(t) * k_unearn_rev_liab(t - 1);

}


//@@ END

//@@ START - unearn_rev_liab_incr
// Unearned Revenue Liability Increase                                                                                             
// Column:UNEARN_REV_LIAB_INCR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_incr(int t) {
//^^^



//^^^

#line 1 "unearn_rev_liab_incr.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return unearn_rev_liab(t)
       - unearn_rev_liab(t - 1);

}


//@@ END

//@@ START - unearn_rev_liab_int
// Unearned Revenue Liability Interest                                                                                             
// Column:UNEARN_REV_LIAB_INT
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_int(int t) {
//^^^



//^^^

#line 1 "unearn_rev_liab_int.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

double unearn_rev_liab_prev_local = 0.0;

if ((!sfas97rd_valn_flag && !valn_flag)
	&& t == start_period + 1 && valn_period > 0) 
	unearn_rev_liab_prev_local = unearn_rev_liab_sch(t - 1);
else 
	unearn_rev_liab_prev_local = unearn_rev_liab(t - 1);
	
return (unearn_rev_liab_prev_local + deferred_loads(t))
		* gaap_amortzn_int_rate(t);

}


//@@ END

//@@ START - unearn_rev_liab_released
// Unearned Revenue Liability Released                                                                                             
// Column:UNEARN_REV_LIAB_RELEASED
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_released(int t) {
//^^^



//^^^

#line 1 "unearn_rev_liab_released.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return deferred_loads(t)
       - unearn_rev_liab_incr(t);

}


//@@ END

//@@ START - unearn_rev_liab_sch
// Unearned Revenue Liability Schedule                                                                                             
// Column:UNEARN_REV_LIAB_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_sch(int t) {
//^^^



//^^^

#line 1 "unearn_rev_liab_sch.SFAS97RD_GAAP.for"
//WTW - Gen2 - split non time guard items
if (/*valn_flag || */t < start_period || t > final_period)
	return NO_AVG;

if (valn_flag)
	return NO_AVG;

return gaap_schedule[UNEARN_REV_LIAB][0];

}


//@@ END

//@@ START - amortzn_period
// Amortization Period                                                                                             
// Calculated Variable:AMORTZN_PERIOD
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_amortzn_period() {
//^^^


#line 1 "amortzn_period.SFAS97RD_GAAP.for"
if (amortzn_mths == 0)
	return cohort_max_maturity_period;

// remaining amortization period is input plus the cohort last issue period (which is a negative t value)
return amortzn_mths + cohort_last_issue_period;

}


//@@ END

//@@ START - comm_pct_fund_ult_index
// Commission Percent Fund Value Ultimate Index                                                                                             
// Calculated Variable:COMM_PCT_FUND_ULT_INDEX
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_pct_fund_ult_index() {
//^^^


#line 1 "comm_pct_fund_ult_index.SFAS97RD_GAAP.for"
#if defined(__UL_LIAB_H_)
return ul->maturity_period_gmp;
#endif	

#if defined(__VUL_LIAB_H_)
return vul->maturity_period_gmp;
#endif

#if defined(__IUL_LIAB_H_)
return iul->maturity_period_gmp;
#endif

#if defined(__VA_LIAB_H_)
return va->maturity_period;
#endif	

#if defined(__FA_LIAB_H_)
return fa->maturity_period;
#endif	

#if defined(__FIA_LIAB_H_)
return fia->maturity_period;
#endif

return 0;

}


//@@ END

//@@ START - final_period
// Final Period                                                                                             
// Calculated Variable:FINAL_PERIOD
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_final_period() {
//^^^


#line 1 "final_period.SFAS97RD_GAAP.for"
if (!valn_flag)
	return last_proj_period;

return amortzn_period;

}


//@@ END

//@@ START - gaap_int_rate
// GAAP Interest Rate                                                                                             
// Calculated Variable:GAAP_INT_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_gaap_int_rate() {
//^^^


#line 1 "gaap_int_rate.SFAS97RD_GAAP.for"
if (cohort_reins_defn == GROSS)
	return cohort_gaap_int_rate_gross;

return cohort_gaap_int_rate_ceded;

}


//@@ END

//@@ START - gaap_int_rate_mthly
// GAAP Interest Rate Monthly                                                                                             
// Calculated Variable:GAAP_INT_RATE_MTHLY
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_gaap_int_rate_mthly() {
//^^^


#line 1 "gaap_int_rate_mthly.SFAS97RD_GAAP.for"
return pow(1.0 + gaap_int_rate, 1.0 / 12.0) - 1.0;

}


//@@ END

//@@ START - gmib_defn
// GMIB Definition                                                                                             
// Calculated Variable:GMIB_DEFN
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmib_defn() {
//^^^


#line 1 "gmib_defn.SFAS97RD_GAAP.for"
if (reins_flag)
	return gmib_ceded_defn;

return gmib_gross_defn;

}


//@@ END

//@@ START - gmib_sop031_flag
// GMIB SOP 03-1 Flag                                                                                             
// Calculated Variable:GMIB_SOP031_FLAG
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmib_sop031_flag() {
//^^^


#line 1 "gmib_sop031_flag.SFAS97RD_GAAP.for"
if (gmib_defn == SOP031)
	return 1;

return 0;

}


//@@ END

//@@ START - gmwb_defn
// GMWB Definition                                                                                             
// Calculated Variable:GMWB_DEFN
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmwb_defn() {
//^^^


#line 1 "gmwb_defn.SFAS97RD_GAAP.for"
if (reins_flag)
	return gmwb_ceded_defn;

return gmwb_gross_defn;

}


//@@ END

//@@ START - gmwb_sop031_flag
// GMWB SOP 03-1 Flag                                                                                             
// Calculated Variable:GMWB_SOP031_FLAG
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmwb_sop031_flag() {
//^^^


#line 1 "gmwb_sop031_flag.SFAS97RD_GAAP.for"
if (gmwb_defn == SOP031)
	return 1;

return 0;

}


//@@ END

//@@ START - hedge_alloc_factor
// Hedge Allocation Factor                                                                                             
// Calculated Variable:HEDGE_ALLOC_FACTOR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_alloc_factor() {
//^^^


#line 1 "hedge_alloc_factor.SFAS97RD_GAAP.for"
#if defined(__SFAS133_GAAP_H_) && defined(__VA_LIAB_H_)
if (this == sfas97rd)
	{
	double pv_claims_total = 0.0;
	double pv_claims_cohort = 0.0;
	StrEnum::EnumValue sum_over_type = GROSS;

// RD Need to fix this for sfas133 redesign
//	if (!seg->sm_sfas133.size())
//		return 0.0;

	if (reins_flag)
		sum_over_type = CEDED;	

	pv_claims_total = 1.0;
//	= seg->sum_over_sfas133("pv_gmab_claim", 0, sum_over_type)
//	  + seg->sum_over_sfas133("pv_gmib_claim", 0, sum_over_type)
//	  + seg->sum_over_sfas133("pv_gmwb_claim", 0, sum_over_type);

	if (fabs(pv_claims_total) < model_point_amount_threshold)
		return 0.0;

	pv_claims_cohort = 0.0;
//	= seg->sm_sfas133[getElementNumber(0)][getElementNumber(1)]->pv_gmab_claim(0)
//	  + seg->sm_sfas133[getElementNumber(0)][getElementNumber(1)]->pv_gmib_claim(0)
//	  + seg->sm_sfas133[getElementNumber(0)][getElementNumber(1)]->pv_gmwb_claim(0);

	return pv_claims_cohort / pv_claims_total;
	}

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	return 0.0;
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	return 0.0;
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	return 1.0;
#endif
#endif

return 0.0;

}


//@@ END

//@@ START - host_accrual_rate
// Host Accrual Rate For New Issues                                                                                             
// Calculated Variable:HOST_ACCRUAL_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_host_accrual_rate() {
//^^^


#line 1 "host_accrual_rate.SFAS97RD_GAAP.for"
#if defined(__FIA_LIAB_H_)
if (fia->elapsed_mths <= 0) 
	{
	double host_value = 0.0;
	double ult_guar_fv = 0.0;
	
	int num_yrs = amortzn_mths / 12; 
	
	// Determine host accrual rate
	// Calculate ultimate guarantee fund value
	if (!reins_flag) //Gross
		{
		host_value = fia->prem_paid(fia->commencement_period + 1) 
					 - embed_deriv_val(fia->commencement_period + 1);
		
		ult_guar_fv = fia->contract_val_net_consideration_pct
			 		 * fia->prem_paid(fia->commencement_period + 1)
			 		 * pow(1.0 + fia->crediting_rate_gtd , num_yrs);
					 
		return pow((ult_guar_fv / host_value), 1.0 / num_yrs) - 1.0;	 
		}
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
		{
		host_value = fia->prem_paid(fia->commencement_period + 1) * fia->reins_pct 
					 - embed_deriv_val(fia->commencement_period + 1);
		
		ult_guar_fv = fia->contract_val_net_consideration_pct
			 		 * fia->prem_paid(fia->commencement_period + 1) * fia->reins_pct
			 		 * pow(1.0 + fia->crediting_rate_gtd, num_yrs);
					 
		return pow((ult_guar_fv / host_value), 1.0 / num_yrs) - 1.0;	
		}
	else //Ceded and MP Not Reinsured
		return 0.0;
	}

return fia->host_accrual_rate;
#endif

return 0;

}


//@@ END

//@@ START - loss_rec_int_rate
// Loss Recognition Interest Rate                                                                                             
// Calculated Variable:LOSS_REC_INT_RATE
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_loss_rec_int_rate() {
//^^^


#line 1 "loss_rec_int_rate.SFAS97RD_GAAP.for"
if (cohort_reins_defn == GROSS)
	return cohort_loss_recognition_int_rate_gross;

return cohort_loss_recognition_int_rate_ceded;

}


//@@ END

//@@ START - loss_rec_int_rate_mthly
// Loss Recognition Interest Rate Monthly                                                                                             
// Calculated Variable:LOSS_REC_INT_RATE_MTHLY
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_loss_rec_int_rate_mthly() {
//^^^


#line 1 "loss_rec_int_rate_mthly.SFAS97RD_GAAP.for"
return pow(1.0 + loss_rec_int_rate, 1.0 / 12.0) - 1.0;

}


//@@ END

//@@ START - loss_recognition_flag
// Loss Recognition Flag                                                                                             
// Calculated Variable:LOSS_RECOGNITION_FLAG
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_loss_recognition_flag() {
//^^^


#line 1 "loss_recognition_flag.SFAS97RD_GAAP.for"
if (loss_recognition_defn == NO)
	return 0;

if ((dac_acq_exp_loss_rec_accum(0)
     + dac_comm_loss_rec_accum(0)
	 + dac_prem_bonus_loss_rec_accum(0))
	> 0.0)
	return 1;

return 0;

}


//@@ END

//@@ START - pbr_final_period
// PBR Final Period                                                                                             
// Calculated Variable:PBR_FINAL_PERIOD
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_pbr_final_period() {
//^^^


#line 1 "pbr_final_period.SFAS97RD_GAAP.for"
if (this == sfas97rd)
	{	
	map <int, long, less <int> >::iterator mp_map_iter;//Gen2 - 9/6/2024 - replace mpmap with full definition

	#if defined(__UL_LIAB_H_)
	if (ul_mp_map.size())
		{
		UL_LIAB *current_ul_element;
		int pbr_final_period = 0;
		
		for (mp_map_iter = ul_mp_map.begin(); 
		     mp_map_iter != ul_mp_map.end(); 
		     mp_map_iter++)
			{
			int mp = mp_map_iter->first;		
			current_ul_element = liab->sm_ul[mp];

			int current_ul_element_pbr_final_period 
			= current_ul_element->sm_ul_ifund_curr->persist_bon_ref_last_period;

			pbr_final_period 
			= max(pbr_final_period, current_ul_element_pbr_final_period);
			}
		return pbr_final_period;		
		}
	#endif

	#if defined(__VUL_LIAB_H_)
	if (vul_mp_map.size())
		{
		VUL_LIAB *current_vul_element;
		int pbr_final_period = 0;
		
		for (mp_map_iter = vul_mp_map.begin(); 
		     mp_map_iter != vul_mp_map.end(); 
			 mp_map_iter++)
			{
			int mp = mp_map_iter->first;		
			current_vul_element = liab->sm_vul[mp];

			int current_vul_element_pbr_final_period 
			= current_vul_element->sm_vul_ifund_curr->persist_bon_last_period;

			pbr_final_period 
			= max(pbr_final_period, current_vul_element_pbr_final_period);
			}
		return pbr_final_period;		
		}
	#endif

	#if defined(__IUL_LIAB_H_)
	return 0;
	#endif
	}

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	return ul->sm_ul_ifund_curr->persist_bon_ref_last_period;
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	return vul->sm_vul_ifund_curr->persist_bon_last_period;
#endif

#if defined(__IUL_LIAB_H_)
return 0;
#endif

#if defined(__EPL_LIAB_H_)
return 0;
#endif
	
return 0;

}


//@@ END

//@@ START - prem_term_period
// Premium Term Period                                                                                             
// Calculated Variable:PREM_TERM_PERIOD
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_prem_term_period() {
//^^^


#line 1 "prem_term_period.SFAS97RD_GAAP.for"
#if defined(__UL_LIAB_H_)
return ul->commencement_period + ul->prem_term * 12;
#endif

#if defined(__VUL_LIAB_H_)
return vul->commencement_period + vul->prem_term * 12;
#endif

#if defined(__IUL_LIAB_H_)
return iul->commencement_period + iul->prem_term * 12;
#endif

#if defined(__VA_LIAB_H_)
return -va->elapsed_mths + va->prem_term * 12;
#endif

#if defined(__FA_LIAB_H_)
return -fa->elapsed_mths + fa->prem_term * 12;
#endif

#if defined(__FIA_LIAB_H_)
return -fia->elapsed_mths; // single premium
#endif

return 9999;

}


//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring SFAS97RD_GAAP_UDF::sfas97rd_gaap_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.SFAS97RD_GAAP.for"
return add_mths_to_date(proj_date, valn_period);

}


//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_proj_start_date() {
//^^^


#line 1 "proj_start_date.SFAS97RD_GAAP.for"
return MonthNumberFromDate(proj_start_yr, proj_start_mth);

}


//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.SFAS97RD_GAAP.for"
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
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.SFAS97RD_GAAP.for"
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
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_reins_flag() {
//^^^


#line 1 "reins_flag.SFAS97RD_GAAP.for"
// Last dimension for sfas97rd determines the reinsurance definition
// 	   Element 0 = Gross
//		Element 1 = Ceded

return getElementNumber();

}


//@@ END

//@@ START - sop031_flag
// SOP 03-1 Flag                                                                                             
// Calculated Variable:SOP031_FLAG
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_flag() {
//^^^


#line 1 "sop031_flag.SFAS97RD_GAAP.for"
#if defined(__UL_LIAB_H_)
if (sop031_ul_vul_iul_defn == NO)
	return 0;
#endif

#if defined(__VUL_LIAB_H_)
if (sop031_ul_vul_iul_defn == NO)
	return 0;
#endif

#if defined(__IUL_LIAB_H_)
if (sop031_ul_vul_iul_defn == NO)
	return 0;
#endif

if (sfas97rd_valn_flag && sop031_results == "NONE")
	return 0;	
	
return 1;

}


//@@ END

//@@ START - start_period
// Start Period                                                                                             
// Calculated Variable:START_PERIOD
//========================================================
int SFAS97RD_GAAP_UDF::sfas97rd_gaap_start_period() {
//^^^


#line 1 "start_period.SFAS97RD_GAAP.for"
// Will be 0 for already in force cohorts, positive value for yet to be active cohorts
if (this == sfas97rd)
	return 0;

#if defined(__UL_LIAB_H_)
if (this == ul_sfas97rd)
	return ul->start_period;
#endif

#if defined(__VUL_LIAB_H_)
if (this == vul_sfas97rd)
	return vul->start_period;
#endif

#if defined(__IUL_LIAB_H_)
if (this == iul_sfas97rd)
	return iul->start_period;
#endif

#if defined(__VA_LIAB_H_)
if (this == va_sfas97rd)
	return va->start_period;
#endif

#if defined(__FA_LIAB_H_)
if (this == fa_sfas97rd)
	return fa->start_period;
#endif

#if defined(__FIA_LIAB_H_)
if (this == fia_sfas97rd)
	return fia->start_period;
#endif

return 0;

}


//@@ END

//@@ START - state_of_world_financial_file_path
// State of World Financial File Path                                                                                             
// Calculated Variable:STATE_OF_WORLD_FINANCIAL_FILE_PATH
//========================================================
xstring SFAS97RD_GAAP_UDF::sfas97rd_gaap_state_of_world_financial_file_path() {
//^^^


#line 1 "state_of_world_financial_file_path.SFAS97RD_GAAP.for"
return "<*grid_output_data*>";

}


//@@ END


#line 1 "get_gaap_schedule_items.SFAS97RD_GAAP.for"                                                                                   
void SFAS97RD_GAAP::get_gaap_schedule_items(void)
{
if (!sfas97rd_valn_flag && !valn_flag)
	{
	xstring file_name = xstring(replaceWildcards(sfas97rd_results));

	if (gaap_schedule.size() < GAAP_SCHEDULE_SIZE)
		gaap_schedule.resize(GAAP_SCHEDULE_SIZE);
	
	for (int i = 0; i < GAAP_SCHEDULE_SIZE; i++)
		{
		if (gaap_schedule[i].size() < last_proj_period + 1)	
			gaap_schedule[i].resize(last_proj_period + 1);

		for (int j = 0; j <= last_proj_period; j++)
			gaap_schedule[i][j] = 0.0;		
		}	

	// Important: Must initialize arrays even if no valuation results are included
	if (sfas97rd_results == "NONE")
		return;

	static bool first_time = true;

	if (first_time)
		{
		first_time = false;

		//string database_name = working_directory() + "sfas97rd_get_gaap_schedule_items.db";
		xstring database_name = working_directory() + "sfas97rd_get_gaap_schedule_items.db";
		openDatabase(database_name.getStdStr());//WTW - Gen2 - add ".getStdStr()"
		string table_name = readCsvFile(file_name.getStdStr());

		// Retrieve valuation results
		xstring report_columns = xstring("_egp, _gaap_amortzn_int_rate, _sop031_pbr_fund_val, _sop031_pbr, ") 
								 + xstring("_dac_acq_exp, _dac_acq_exp_loss_rec, _dac_comm, _dac_comm_loss_rec, _dac_prem_bonus, _dac_prem_bonus_loss_rec, _dac_reins_yrt_asset, _embed_deriv_val, ")
								 + xstring("_k_capzd_acq_exp, _k_capzd_comm, _k_capzd_prem_bonus, _k_reins_yrt_cost, _k_sop031_gmdb_ben_br, _k_sop031_pbr, _k_sop031_ulsg_ben_br, _k_sop031_unearn_rev_liab, ")
								 + xstring("_k_unearn_rev_liab, _sop031_gmdb_br, _sop031_gmib_br, _sop031_gmwb_br, _sop031_pbr_liab, _sop031_ulsg_br, _unearn_rev_liab");

		xstring sql = "SELECT TRIM(_group) AS vgroup, "
					  +(xstring)"CAST(_period AS INTEGER) AS vperiod, "
					  +(xstring)"_time, "
					  + report_columns
					  + (xstring)" FROM '"
					  + table_name 
					  + (xstring)"' WHERE (vperiod <= "
					  + xstring(last_proj_period)
					  + (xstring)") AND _time NOT LIKE 'PV%' AND _time NOT LIKE 'IRR%'";

		executeQuery(sql.getStdStr(), sfas97rd_valn_input_cols, sfas97rd_valn_input);
		closeDatabase();
		remove(database_name.c_str());

		if (!sfas97rd_valn_input_cols.size())
			{
			throw FatalError("Could not read SFAS97RD valuation file: " 
							  + file_name + " "
							  + "Please check your data.");
			}

		// Create map of group start positions, group is column 0 of query results
		// Strip any leading "|" character
		xstring output_group_name;
		output_group_name = xstring(sfas97rd_valn_input[0][0]);

		if (output_group_name(0, 1) == "|")
			output_group_name = output_group_name(1, output_group_name.length()-1);   

		sfas97rd_valn_input_pos[output_group_name] = 0;

		for (int row = 1; row < sfas97rd_valn_input.size(); row++)
			{
			if (!eq(sfas97rd_valn_input[row][0], sfas97rd_valn_input[row - 1][0]))
				{
				output_group_name = xstring(sfas97rd_valn_input[row][0]);

				if (output_group_name(0, 1) == "|")
					output_group_name = output_group_name(1, output_group_name.length()-1);   

				sfas97rd_valn_input_pos[output_group_name] = row;
				}
			}
		}

	xstring group_name;

	if (this != sfas97rd)// Used for cell pricing
		{
		#if defined(__UL_LIAB_H_)
			group_name = get_base_group_name(ul->group, true);//WTW - Gen2 - Move Extern definitions to rates header
			group_name += "|" + group;
		#endif
	
		#if defined(__VUL_LIAB_H_)
			group_name = get_base_group_name(vul->group, true);//WTW - Gen2 - Move Extern definitions to rates header
			group_name += "|" + group;
		#endif

		#if defined(__IUL_LIAB_H_)
			group_name = get_base_group_name(iul->group, true);//WTW - Gen2 - Move Extern definitions to rates header
			group_name += "|" + group;
		#endif

		#if defined(__VA_LIAB_H_)
			group_name = get_base_group_name(va->group, true);//WTW - Gen2 - Move Extern definitions to rates header
			group_name += "|" + group;
		#endif

		#if defined(__FA_LIAB_H_)
			group_name = get_base_group_name(fa->group, true);//WTW - Gen2 - Move Extern definitions to rates header
			group_name += "|" + group;
		#endif

		#if defined(__FIA_LIAB_H_)
			group_name = get_base_group_name(fia->group, true);//WTW - Gen2 - Move Extern definitions to rates header
			group_name += "|" + group;
		#endif
		}
	else // Used for cohorts
		group_name = seg_id + "|" + group;

	// Find group start position
	int sfas97rd_valn_input_row = 0;
	if ((sfas97rd_valn_input_pos_iter 
		 = sfas97rd_valn_input_pos.find(group_name)) != sfas97rd_valn_input_pos.end())
		{
		sfas97rd_valn_input_row = sfas97rd_valn_input_pos_iter->second;

		int start_row = sfas97rd_valn_input_row;
		int end_row = start_row + last_proj_period + 1;
		int period = 0;

		for (int row = start_row; row < end_row; row++)
            {
            gaap_schedule[EGP][period] = atof(sfas97rd_valn_input[row][3].c_str());
            gaap_schedule[INT_RATE][period] = atof(sfas97rd_valn_input[row][4].c_str());
            gaap_schedule[SOP031_PBR_FV][period] = atof(sfas97rd_valn_input[row][5].c_str());
            gaap_schedule[SOP031_PBR][period] = atof(sfas97rd_valn_input[row][6].c_str());

            // these schedule values are always from the start_row
            gaap_schedule[DAC_ACQ_EXP][period] = atof(sfas97rd_valn_input[start_row][7].c_str());
            gaap_schedule[DAC_ACQ_EXP_LOSS_REC][period] = atof(sfas97rd_valn_input[start_row][8].c_str());
            gaap_schedule[DAC_COMM][period] = atof(sfas97rd_valn_input[start_row][9].c_str());
            gaap_schedule[DAC_COMM_LOSS_REC][period] = atof(sfas97rd_valn_input[start_row][10].c_str());
            gaap_schedule[DAC_PREM_BONUS][period] = atof(sfas97rd_valn_input[start_row][11].c_str());
            gaap_schedule[DAC_PREM_BONUS_LOSS_REC][period] = atof(sfas97rd_valn_input[start_row][12].c_str());
            gaap_schedule[DAC_REINS_YRT_ASSET][period] = atof(sfas97rd_valn_input[start_row][13].c_str());
            gaap_schedule[EMBED_DERIV_VAL][period] = atof(sfas97rd_valn_input[start_row][14].c_str());
            gaap_schedule[K_CAPZD_ACQ_EXP][period] = atof(sfas97rd_valn_input[start_row][15].c_str());
            gaap_schedule[K_CAPZD_COMM][period] = atof(sfas97rd_valn_input[start_row][16].c_str());
            gaap_schedule[K_CAPZD_PREM_BONUS][period] = atof(sfas97rd_valn_input[start_row][17].c_str());
            gaap_schedule[K_REINS_YRT_COST][period] = atof(sfas97rd_valn_input[start_row][18].c_str());
            gaap_schedule[K_SOP031_GMDB_BEN_BR][period] = atof(sfas97rd_valn_input[start_row][19].c_str());
            gaap_schedule[K_SOP031_PBR][period] = atof(sfas97rd_valn_input[start_row][20].c_str());
            gaap_schedule[K_SOP031_ULSG_BEN_BR][period] = atof(sfas97rd_valn_input[start_row][21].c_str());
            gaap_schedule[K_SOP031_UNEARN_REV_LIAB][period] = atof(sfas97rd_valn_input[start_row][22].c_str());
            gaap_schedule[K_UNEARN_REV_LIAB][period] = atof(sfas97rd_valn_input[start_row][23].c_str());
            gaap_schedule[SOP031_GMDB_BR][period] = atof(sfas97rd_valn_input[start_row][24].c_str());
            gaap_schedule[SOP031_GMIB_BR][period] = atof(sfas97rd_valn_input[start_row][25].c_str());
            gaap_schedule[SOP031_GMWB_BR][period] = atof(sfas97rd_valn_input[start_row][26].c_str());
            gaap_schedule[SOP031_PBR_LIAB][period] = atof(sfas97rd_valn_input[start_row][27].c_str());
            gaap_schedule[SOP031_ULSG_BR][period] = atof(sfas97rd_valn_input[start_row][28].c_str());
            gaap_schedule[UNEARN_REV_LIAB][period] = atof(sfas97rd_valn_input[start_row][29].c_str());

            period++;
            }
		}
	}
}



#line 1 "get_sop031_valn_results.SFAS97RD_GAAP.for"                                                                                   
void SFAS97RD_GAAP::get_sop031_valn_results(void)
{
xstring file_name = xstring(replaceWildcards(sop031_results));

int periods = 1440; // Must get all results from the output file since cohorts can have different remaining periods
int cohort_periods = max(1, final_period + 1);

if (sop031_array.size() < SOP_SIZE)
	sop031_array.resize(SOP_SIZE);

for (int i = 0; i < SOP_SIZE; i++)
	{
	if (sop031_array[i].size() < cohort_periods)
		sop031_array[i].resize(cohort_periods);

	for (int j = 0; j < cohort_periods; j++)
		sop031_array[i][j] = 0.0;		
	}	

// Important: Must initialize arrays even if no valuation results are included
if (sop031_results == "NONE")
	return;

static bool first_time = true;

if (first_time)
	{
	first_time = false;

	//string database_name = working_directory() + "sfas97rd_get_sop031_valn_results.db";
	xstring database_name = working_directory() + "sfas97rd_get_sop031_valn_results.db";
	openDatabase(database_name.getStdStr());//WTW - Gen2 - add ".getStdStr()"
	string table_name = readCsvFile(file_name.getStdStr());

	// Retrieve valuation results
	xstring report_columns = "";
	report_columns = xstring("_sop031_assess, _gmdb_ben, _gmib_ben, _gmwb_ben, _ulsg_ben, _dth_claim_cost");

	xstring sql = (xstring)"SELECT TRIM(_group) AS vgroup, "
			      + (xstring)"CAST(_period AS INTEGER) AS vperiod, _time, "
				  + report_columns
				  + (xstring)" FROM '"
		          + table_name 
		   		  + (xstring)"' WHERE (vperiod < "
		   		  + xstring(periods)
		   		  + (xstring)") AND _time NOT LIKE 'PV%' AND _time NOT LIKE 'IRR%'"
				  + (xstring)" ORDER BY vgroup";

	executeQuery(sql.getStdStr(), sop031_valn_input_cols, sop031_valn_input);
	closeDatabase();
	remove(database_name.c_str());

	if (!sop031_valn_input_cols.size())
		{
		throw FatalError("Could not read SOP03-1 valuation file: " 
			              + file_name + ". "
			              + "Please check your data.");
		}

	// Create map of group start positions, group is column 0 of query results
	// Strip any leading "|" character
	xstring output_group_name;
	output_group_name = xstring(sop031_valn_input[0][0]);

    if (output_group_name(0, 1) == "|")
		output_group_name = output_group_name(1, output_group_name.length()-1);   

	sop031_valn_input_pos[output_group_name] = 0;

	for (int row = 1; row < sop031_valn_input.size(); row++)
		{
		if (!eq(sop031_valn_input[row][0], sop031_valn_input[row - 1][0]))
			{      
			output_group_name = xstring(sop031_valn_input[row][0]);

			if (output_group_name(0, 1) == "|")
				output_group_name = output_group_name(1, output_group_name.length() - 1);   

			sop031_valn_input_pos[output_group_name] = row;
			}
		}
	}

xstring group_name;

if (this != sfas97rd)// Cell pricing
	{
	#if defined(__UL_LIAB_H_)
	group_name = get_base_group_name(ul->group, true);
	group_name += "|" + group;
	#endif
	
	#if defined(__VUL_LIAB_H_)
	group_name = get_base_group_name(vul->group, true);
	group_name += "|" + group;
	#endif

	#if defined(__IUL_LIAB_H_)
	group_name = get_base_group_name(iul->group, true);
	group_name += "|" + group;
	#endif

	#if defined(__VA_LIAB_H_)
	group_name = get_base_group_name(va->group, true);
	group_name += "|" + group;
	#endif
	}
else // Portfolio cohorts
	group_name = seg_id + "|" + group;

// Find group start position
int sop031_valn_input_row = 0;
int sop031_valn_next_input_row = sop031_valn_input.size();
if ((sop031_valn_input_pos_iter 
     = sop031_valn_input_pos.find(group_name)) != sop031_valn_input_pos.end())
	{
	sop031_valn_input_row = sop031_valn_input_pos_iter->second;

	// Determine the number of rows for the group
	deptaskmapiter temp_iter;
	for (temp_iter = sop031_valn_input_pos.begin();
		 temp_iter != sop031_valn_input_pos.end();
		 temp_iter++) 
		{
		if (temp_iter->second > sop031_valn_input_row)
			sop031_valn_next_input_row = min(sop031_valn_next_input_row, temp_iter->second);
		}

	int start_row = sop031_valn_input_row;
	int end_row = sop031_valn_next_input_row;

	int period = 0;
	int task_loop_counter = 0;

	for (int row = start_row; row < end_row; row++)
		{
		period = atoi(sop031_valn_input[row][1].c_str());

		if (period == 0)
			task_loop_counter +=1;

		if (period < cohort_periods)
			{
			sop031_array[ASSESS_SOP][period] += atof(sop031_valn_input[row][3].c_str());
			sop031_array[DB_BEN_SOP][period] += atof(sop031_valn_input[row][4].c_str());
			sop031_array[IB_BEN_SOP][period] += atof(sop031_valn_input[row][5].c_str());
			sop031_array[WB_BEN_SOP][period] += atof(sop031_valn_input[row][6].c_str());
			sop031_array[SG_BEN_SOP][period] += atof(sop031_valn_input[row][7].c_str());
			sop031_array[DTH_CLAIM_COST][period] += atof(sop031_valn_input[row][8].c_str());
			}
		}

//	int proj_task_loops = max(1, (end_row - start_row) / cohort_periods);
	int proj_task_loops = task_loop_counter;

	for (period = 0; period < cohort_periods; period++)
		{
		sop031_array[ASSESS_SOP][period] /= proj_task_loops;
		sop031_array[DB_BEN_SOP][period] /= proj_task_loops;
		sop031_array[IB_BEN_SOP][period] /= proj_task_loops;
		sop031_array[WB_BEN_SOP][period] /= proj_task_loops;
		sop031_array[SG_BEN_SOP][period] /= proj_task_loops;
		sop031_array[DTH_CLAIM_COST][period] /= proj_task_loops;		
		}			

	// Validate data
	double assess_chk = 0.0;
	double db_chk = 0.0;
	double ib_chk = 0.0;
	double wb_chk = 0.0;
	double sg_chk = 0.0;
	double dcc_chk = 0.0;

	for (period = 0; period < cohort_periods; period++)
		{
		assess_chk += sop031_array[ASSESS_SOP][period];
		db_chk += sop031_array[DB_BEN_SOP][period];
		ib_chk += sop031_array[IB_BEN_SOP][period];
		wb_chk += sop031_array[WB_BEN_SOP][period];
		sg_chk += sop031_array[SG_BEN_SOP][period];
		dcc_chk += sop031_array[DTH_CLAIM_COST][period];
		}

	if (final_period > 0
		&& (assess_chk + db_chk + ib_chk + wb_chk + sg_chk + dcc_chk) == 0.0)
		log_screen << "Warning: Cohort " << group_name << " does not have any SOP 03-1 cash flow items assigned to it. "
		           << "Please check SOP 03-1 valuation file: " << file_name << "." << MSG_USER;		
	}
}



#line 1 "read_state_of_world_financial.SFAS97RD_GAAP.for"                                                                                   
void SFAS97RD_GAAP::read_state_of_world_financial(void)
{
static bool first_time = true;

if (first_time)
	{
	first_time = false;

	// Create file_name
	xstring state_of_world_financial_file
	= replaceWildcards(state_of_world_financial_file_path
	  + "sfas97rd_state_of_world_financial_" + xstring(proj_set_loop_num)
	  + "_" + xstring(proj_set_sub_loop_num) + ".csv");

	//string database_name = working_directory() + "sfas97rd_read_state_of_world_financial.db";
	xstring database_name = working_directory() + "sfas97rd_read_state_of_world_financial.db";
	openDatabase(database_name.getStdStr());//WTW - Gen2 - add ".getStdStr()"
	string table_name = readCsvFile(state_of_world_financial_file.getStdStr());

	xstring sql = (xstring)"SELECT * FROM " + table_name;

	executeQuery(sql.getStdStr(), sfas97rd_state_of_world_financial_cols, sfas97rd_state_of_world_financial_input);
	closeDatabase();
	remove(database_name.c_str());

	if (!sfas97rd_state_of_world_financial_cols.size())
		{
		throw FatalError("Could not read SFAS97RD State of World Financial File: " 
			              + state_of_world_financial_file + " "
			              + "Please check your data.");
		}
	
	// Create map of group start positions
	sfas97rd_state_of_world_financial_input_pos[xstring(sfas97rd_state_of_world_financial_input[0][0])] = 0;

	for (int row = 1; row < sfas97rd_state_of_world_financial_input.size(); row++)
		{
		if (!eq(sfas97rd_state_of_world_financial_input[row][0], sfas97rd_state_of_world_financial_input[row - 1][0]))
			sfas97rd_state_of_world_financial_input_pos[sfas97rd_state_of_world_financial_input[row][0]] = row;
		}
	}

int sfas97rd_state_of_world_financial_row = 0;
if ((sfas97rd_state_of_world_financial_input_pos_iter 
     = sfas97rd_state_of_world_financial_input_pos.find(group)) != sfas97rd_state_of_world_financial_input_pos.end())
	sfas97rd_state_of_world_financial_row = sfas97rd_state_of_world_financial_input_pos_iter->second;

init_dac_acq_exp = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][1].c_str());
init_dac_acq_exp_loss_rec = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][2].c_str());
init_capzd_acq_exp_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][3].c_str());
init_capzd_acq_exp_accum_loss_rec_int_rate = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][4].c_str());
init_dac_acq_exp_loss_rec_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][5].c_str());
init_dac_comm = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][6].c_str());
init_dac_comm_loss_rec = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][7].c_str());
init_capzd_comm_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][8].c_str());
init_capzd_comm_accum_loss_rec_int_rate = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][9].c_str());
init_dac_comm_loss_rec_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][10].c_str());
init_dac_prem_bonus = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][11].c_str());
init_dac_prem_bonus_loss_rec = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][12].c_str());
init_capzd_prem_bonus_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][13].c_str());
init_capzd_prem_bonus_accum_loss_rec_int_rate = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][14].c_str());
init_dac_prem_bonus_loss_rec_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][15].c_str());
init_egp_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][16].c_str());
init_egp_accum_loss_rec_int_rate = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][17].c_str());
init_sop031_assess_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][18].c_str());
init_sop031_gmdb_ben_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][19].c_str());
init_sop031_gmib_ben_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][20].c_str());
init_sop031_gmwb_ben_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][21].c_str());
init_sop031_pbr_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][22].c_str());
init_deferred_loads_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][23].c_str());
init_unearn_rev_liab = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][24].c_str());
init_dac_reins_yrt_asset = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][25].c_str());
init_reins_yrt_cost_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][26].c_str());
init_sop031_pbr_fund_val_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][27].c_str());
init_embed_deriv_val = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][28].c_str());
init_sfas133_gmab_liab = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][29].c_str());
init_sfas133_gmib_liab = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][30].c_str());
init_sfas133_gmwb_liab = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][31].c_str());
init_sop031_ulsg_ben_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][32].c_str());
init_sop031_gmdb_br = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][33].c_str());
init_sop031_gmib_br = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][34].c_str());
init_sop031_gmwb_br = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][35].c_str());
init_sop031_pbr_liab = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][36].c_str());
init_sop031_ulsg_br = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][37].c_str());

return;
}



#line 1 "setup_cohorts.SFAS97RD_GAAP.for"                                                                                   
bool SFAS97RD_GAAP::setup_cohorts(int mp_iss_yr_int, xstring mp_plan_code, xstring mp_cohort_map_id, xstring cohort)
{
vector<string> issue_yrs;
vector<string> plan_codes;

xstring mp_iss_yr = xstring(mp_iss_yr_int);

// Parse and stores multiple issue yrs and plan code into vectors
// Set lookup key
cohort_id = cohort;

split_string_usl(cohort_issue_yrs.c_str(), issue_yrs, ",");//WTW - Gen2 - split_tring internal RAFM function
split_string_usl(cohort_plan_codes.c_str(), plan_codes, ",");//WTW - Gen2 - split_tring internal RAFM function

// Sets sfas97rd cohort's variable assumptions
if (issue_yrs.size() > 0)
	{
	for (int yrs_count = 1; yrs_count < issue_yrs.size(); yrs_count++)
		{
		xstring yr0 = xstring(issue_yrs[yrs_count - 1]);
		xstring yr1 = xstring(issue_yrs[yrs_count]);
		
		if (atoi(yr0) > atoi(yr1))
			{
			throw FatalError("Cohort years must be inserted in an ascending order");
			}
		}	
	}
	
if (xstring(issue_yrs[0]) == "ALL")
	cohort_yr = 1900;
else
	{
	xstring c_yr = xstring(issue_yrs[0]);
	cohort_yr = atoi(c_yr);
	}

// Mapping process starts	
for (int yrs_count = 0; yrs_count < issue_yrs.size(); yrs_count++)
	{
	for (int plan_count = 0; plan_count < plan_codes.size(); plan_count++)
		{
		if ((xstring(issue_yrs[yrs_count]) == "ALL" 
		     && xstring(plan_codes[plan_count]) == "ALL" 
		     && mp_cohort_map_id == "Unassigned")
		    || (xstring(issue_yrs[yrs_count]) == "ALL" 
		        && eq(mp_plan_code, xstring(plan_codes[plan_count])) // case insensitive 
		        && mp_cohort_map_id == "Unassigned")
		    || (mp_iss_yr == xstring(issue_yrs[yrs_count]) 
		        && xstring(plan_codes[plan_count]) == "ALL" 
		        && mp_cohort_map_id == "Unassigned")  
		    || (mp_iss_yr == xstring(issue_yrs[yrs_count]) 
		        && eq(mp_plan_code, xstring(plan_codes[plan_count])) // case insensitive 
		        && mp_cohort_map_id == "Unassigned"))
			{
			return true;
			}
		}	
	}	
return false;
}



#line 1 "sum_over_gaap.SFAS97RD_GAAP.for"                                                                                   
double SFAS97RD_GAAP::sum_over_gaap(const xstring &colname, int t)
{
double total = 0.0;
int mp = 0;
int colnum = 0;
map <int, long, less <int> >::iterator mp_map_iter;//Gen2 - 9/6/2024 - replace mpmap with full definition

#if defined(__UL_LIAB_H_)
if (ul_mp_map.size())
	{
	UL_LIAB *current_ul_element;
	colnum = liab->sm_ul[0]->sm_ul_sfas97rd[0]->Column(colname).Number();	

	if (colnum < 0)
		throw FatalError("Column not included in application. Please check column names passed into 'sum_over_gaap' "
		                 "function of SFAS97RD/GAAP model class.");
	
	if (colnum >= 0)
		{		
		for (mp_map_iter = ul_mp_map.begin(); 
		     mp_map_iter != ul_mp_map.end(); 
			 mp_map_iter++)
			{
			mp = mp_map_iter->first;		
			current_ul_element = liab->sm_ul[mp];
			
			if (t < current_ul_element->commencement_period
				|| t > current_ul_element->maturity_period)
				continue;

			// Skip new issues commencement period
			if (current_ul_element->commencement_period >= 0
				&& t == current_ul_element->commencement_period)
				continue;

			if (t > current_ul_element->start_period
				&& fabs(current_ul_element->units_inf(t - 1)) < rate_ratio_threshold)
				continue;

			if (!reins_flag) //Gross Run
				total += current_ul_element->sm_ul_sfas97rd[0]->Column(colnum).Value(t);

			else if (reins_flag && current_ul_element->reins_flag && current_ul_element->coins_flag) //Ceded Run && MP Reinsured
				total += current_ul_element->sm_ul_sfas97rd[1]->Column(colnum).Value(t);

			// no sum for ceded Run && MP Not Reinsured
			}		
		}
	}		
#endif

#if defined(__VUL_LIAB_H_)
if (vul_mp_map.size())
	{
	VUL_LIAB *current_vul_element;
	colnum = liab->sm_vul[0]->sm_vul_sfas97rd[0]->Column(colname).Number();	

	if (colnum < 0)
		throw FatalError("Column not included in application. Please check column names passed into 'sum_over_gaap' "
		                 "function of SFAS97RD/GAAP model class.");
	
	if (colnum >= 0)
		{		
		for (mp_map_iter = vul_mp_map.begin(); 
		     mp_map_iter != vul_mp_map.end(); 
		     mp_map_iter++)
			{
			mp = mp_map_iter->first;		
			current_vul_element = liab->sm_vul[mp];
			
			if (t < current_vul_element->commencement_period
				|| t > current_vul_element->maturity_period)
				continue;

			// Skip new issues commencement period
			if (current_vul_element->commencement_period >= 0
				&& t == current_vul_element->commencement_period)
				continue;

			if (t > current_vul_element->start_period
				&& fabs(current_vul_element->units_inf(t - 1)) < rate_ratio_threshold)
				continue;

			if (!reins_flag) //Gross Run
				total += current_vul_element->sm_vul_sfas97rd[0]->Column(colnum).Value(t);

			else if (reins_flag && current_vul_element->reins_flag && current_vul_element->coins_flag) //Ceded Run && MP Reinsured
				total += current_vul_element->sm_vul_sfas97rd[1]->Column(colnum).Value(t);

			// no sum for ceded Run && MP Not Reinsured
			}		
		}
	}		
#endif

#if defined(__IUL_LIAB_H_)
if (iul_mp_map.size())
	{
	IUL_LIAB *current_iul_element;
	colnum = liab->sm_iul[0]->sm_iul_sfas97rd[0]->Column(colname).Number();	

	if (colnum < 0)
		throw FatalError("Column not included in application. Please check column names passed into 'sum_over_gaap' "
		                 "function of SFAS97RD/GAAP model class.");
	
	if (colnum >= 0)
		{		
		for (mp_map_iter = iul_mp_map.begin(); 
		     mp_map_iter != iul_mp_map.end(); 
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

			if (!reins_flag) //Gross Run
				total += current_iul_element->sm_iul_sfas97rd[0]->Column(colnum).Value(t);

			else if (reins_flag && current_iul_element->reins_flag && current_iul_element->coins_flag) //Ceded Run && MP Reinsured
				total += current_iul_element->sm_iul_sfas97rd[1]->Column(colnum).Value(t);

			// no sum for ceded Run && MP Not Reinsured
			}		
		}
	}		
#endif

#if defined(__VA_LIAB_H_)
if (va_mp_map.size())
	{
	VA_LIAB *current_va_element;
	colnum = liab->sm_va[0]->sm_va_sfas97rd[0]->Column(colname).Number();	

	if (colnum < 0)
		throw FatalError("Column not included in application. Please check column names passed into 'sum_over_gaap' "
		                 "function of SFAS97RD/GAAP model class.");

	if (colnum >= 0)
		{		
		for (mp_map_iter = va_mp_map.begin(); 
		     mp_map_iter != va_mp_map.end(); 
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

			if (!reins_flag) //Gross Run
				total += current_va_element->sm_va_sfas97rd[0]->Column(colnum).Value(t);

			else if (reins_flag && current_va_element->reins_flag) //Ceded Run && MP Reinsured
				total += current_va_element->sm_va_sfas97rd[1]->Column(colnum).Value(t);

			// no sum for ceded Run && MP Not Reinsured
			}	
		}
	}		
#endif

#if defined(__FA_LIAB_H_)
if (fa_mp_map.size())
	{
	FA_LIAB *current_fa_element;
	colnum = liab->sm_fa[0]->sm_fa_sfas97rd[0]->Column(colname).Number();	

	if (colnum < 0)
		throw FatalError("Column not included in application. Please check column names passed into 'sum_over_gaap' "
		                 "function of SFAS97RD/GAAP model class.");

	if (colnum >= 0)
		{		
		for (mp_map_iter = fa_mp_map.begin(); 
		     mp_map_iter != fa_mp_map.end(); 
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

			if (!reins_flag) //Gross Run
				total += current_fa_element->sm_fa_sfas97rd[0]->Column(colnum).Value(t);

			else if (reins_flag && current_fa_element->reins_flag) //Ceded Run && MP Reinsured
				total += current_fa_element->sm_fa_sfas97rd[1]->Column(colnum).Value(t);

			// no sum for ceded Run && MP Not Reinsured
			}	
		}
	}		
#endif

#if defined(__FIA_LIAB_H_)
if (fia_mp_map.size())
	{
	FIA_LIAB *current_fia_element;
	colnum = liab->sm_fia[0]->sm_fia_sfas97rd[0]->Column(colname).Number();	

	if (colnum < 0)
		throw FatalError("Column not included in application. Please check column names passed into 'sum_over_gaap' "
		                 "function of SFAS97RD/GAAP model class.");

	if (colnum >= 0)
		{		
		for (mp_map_iter = fia_mp_map.begin(); 
		     mp_map_iter != fia_mp_map.end(); 
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

			if (!reins_flag) //Gross Run
				total += current_fia_element->sm_fia_sfas97rd[0]->Column(colnum).Value(t);

			else if (reins_flag && current_fia_element->reins_flag) //Ceded Run && MP Reinsured
				total += current_fia_element->sm_fia_sfas97rd[1]->Column(colnum).Value(t);

			// no sum for ceded Run && MP Not Reinsured
			}	
		}
	}		
#endif

//for EPL file
#if defined(__EPL_LIAB_H_)
if (epl_mp_map.size())
	{
	EPL_LIAB *current_epl_element;

	// In epl/liab, "sfas97rd_gross_" and "sfas97rd_ceded_" have been added to the column names
	if (!reins_flag) 
		colnum = liab->sm_epl[0]->Column("sfas97rd_gross_" + colname).Number();				
	else 
		colnum = liab->sm_epl[0]->Column("sfas97rd_ceded_" + colname).Number();		

	if (colnum < 0)
		throw FatalError("Column not included in application. Please check column names passed into 'sum_over_gaap' "
		                 "function of SFAS97RD/GAAP model class.");
	
	if (colnum >= 0)
		{		
		for (mp_map_iter = epl_mp_map.begin(); 
		     mp_map_iter != epl_mp_map.end(); 
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

// include results from independent model points
if (seg->seriatim_totals.size() > 0)
	{
	int cohort_col = getElementNumber(0); 
	pair<xstring,seriatim_type> name_pair = make_pair(colname, prod_sfas97rd);
	seriatim_map::iterator totals_it = seg->seriatim_totals.find(name_pair);

	if(totals_it != seg->seriatim_totals.end())
		total += totals_it->second[cohort_col][reins_flag][t];
	}
return total;
}



#line 1 "write_state_of_world_financial.SFAS97RD_GAAP.for"                                                                                   
void SFAS97RD_GAAP::write_state_of_world_financial(void)
{
if (proj_set_sub_loop_num == valn_periods.size())
	return;

// create state_of_world_file_name
xstring state_of_world_financial_file
= replaceWildcards(state_of_world_financial_file_path
  + "sfas97rd_state_of_world_financial_"  + xstring(proj_set_loop_num)
  + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv");

// remove any old file that is hanging around
static bool first_time = true;
if (first_time)
	{
	first_time = false;

	struct stat buffer;
	int stat_val;
	stat_val = stat(state_of_world_financial_file.c_str(), &buffer);

	// if file exists, delete, as we want to create fresh
	if (stat_val == 0)
		remove(state_of_world_financial_file.c_str());
	}

// Open state of world file and write header
if (!sfas97rd_state_of_world_financial_output.is_open())
	{
	sfas97rd_state_of_world_financial_output.open(state_of_world_financial_file);

	sfas97rd_state_of_world_financial_output.setf(ios::fixed);
	sfas97rd_state_of_world_financial_output.precision(12);

	// Write header
	sfas97rd_state_of_world_financial_output // 37 columns
	<< "group" << ","           
	<< "dac_acq_exp" << ","     
	<< "dac_acq_exp_loss_rec" << "," 
	<< "capzd_acq_exp_accum" << "," 
	<< "capzd_acq_exp_accum_loss_rec_int_rate" << "," 
	<< "dac_acq_exp_loss_rec_accum" << "," 
	<< "dac_comm" << ","        
	<< "dac_comm_loss_rec" << ","   
	<< "capzd_comm_accum" << ","    
	<< "capzd_comm_accum_loss_rec_int_rate" << ","    
	<< "dac_comm_loss_rec_accum" << "," 
	<< "dac_prem_bonus" << ","       
	<< "dac_prem_bonus_loss_rec" << ","  
	<< "capzd_prem_bonus_accum" << ","   
	<< "capzd_prem_bonus_accum_loss_rec_int_rate" << ","   
	<< "dac_prem_bonus_loss_rec_accum" << "," 
	<< "egp_accum" << ","         
	<< "egp_accum_loss_rec_int_rate" << ","         
	<< "sop031_assess_accum" << ","    
	<< "sop031_gmdb_ben_accum" << ","    
	<< "sop031_gmib_ben_accum" << ","    
	<< "sop031_gmwb_ben_accum" << ","    
	<< "sop031_pbr_accum" << ","       
	<< "deferred_loads_accum" << ","   
	<< "unearn_rev_liab" << ","        
	<< "dac_reins_yrt_asset" << ","    
	<< "reins_yrt_cost_accum" << ","   
	<< "sop031_pbr_fund_val_accum" << ","  
	<< "embed_deriv_val" << ","      
	<< "sfas133_gmab_liab" << ","    
	<< "sfas133_gmib_liab" << ","    
	<< "sfas133_gmwb_liab" << ","    
	<< "sop031_ulsg_ben_accum" << ","  
	<< "sop031_gmdb_br" << ","       
	<< "sop031_gmib_br" << ","       
	<< "sop031_gmwb_br" << ","       
	<< "sop031_pbr_liab" << ","      
	<< "sop031_ulsg_br" << endl;      
	}

double dac_acq_exp = this->dac_acq_exp(last_proj_period);
double dac_acq_exp_loss_rec = this->dac_acq_exp_loss_rec(last_proj_period);
double capzd_acq_exp_accum = this->capzd_acq_exp_accum(last_proj_period);
double capzd_acq_exp_accum_loss_rec_int_rate = this->capzd_acq_exp_accum_loss_rec_int_rate(last_proj_period);
double dac_acq_exp_loss_rec_accum = this->dac_acq_exp_loss_rec_accum(last_proj_period);
double dac_comm = this->dac_comm(last_proj_period);
double dac_comm_loss_rec = this->dac_comm_loss_rec(last_proj_period);
double capzd_comm_accum = this->capzd_comm_accum(last_proj_period);
double capzd_comm_accum_loss_rec_int_rate = this->capzd_comm_accum_loss_rec_int_rate(last_proj_period);
double dac_comm_loss_rec_accum = this->dac_comm_loss_rec_accum(last_proj_period);
double dac_prem_bonus = this->dac_prem_bonus(last_proj_period);
double dac_prem_bonus_loss_res = this->dac_prem_bonus_loss_rec(last_proj_period);
double capzd_prem_bonus_accum = this->capzd_prem_bonus_accum(last_proj_period);
double capzd_prem_bonus_accum_loss_rec_int_rate = this->capzd_prem_bonus_accum_loss_rec_int_rate(last_proj_period);
double dac_prem_bonus_loss_rec_accum = this->dac_prem_bonus_loss_rec_accum(last_proj_period);
double egp_accum = this->egp_accum(last_proj_period);
double egp_accum_loss_rec_int_rate = this->egp_accum_loss_rec_int_rate(last_proj_period);
double sop031_assess_accum = this->sop031_assess_accum(last_proj_period);
double sop031_gmdb_ben_accum = this->sop031_gmdb_ben_accum(last_proj_period);
double sop031_gmib_ben_accum = this->sop031_gmib_ben_accum(last_proj_period);
double sop031_gmwb_ben_accum = this->sop031_gmwb_ben_accum(last_proj_period);
double sop031_pbr_accum = this->sop031_pbr_accum(last_proj_period);
double deferred_loads_accum = this->deferred_loads_accum(last_proj_period);
double unearn_rev_liab = this->unearn_rev_liab(last_proj_period);
double dac_reins_yrt_asset = this->dac_reins_yrt_asset(last_proj_period);
double reins_yrt_cost_accum = this->reins_yrt_cost_accum(last_proj_period);
double sop031_pbr_fund_val_accum = this->sop031_pbr_fund_val_accum(last_proj_period);
double embed_deriv_val = this->embed_deriv_val(last_proj_period);
double sfas133_gmab_liab = this->sfas133_gmab_liab(last_proj_period); 
double sfas133_gmib_liab = this->sfas133_gmib_liab(last_proj_period); 
double sfas133_gmwb_liab = this->sfas133_gmwb_liab(last_proj_period); 
double sop031_ulsg_ben_accum = this->sop031_ulsg_ben_accum(last_proj_period);
double sop031_gmdb_br = this->sop031_gmdb_br(last_proj_period); 
double sop031_gmib_br = this->sop031_gmib_br(last_proj_period); 
double sop031_gmwb_br = this->sop031_gmwb_br(last_proj_period); 
double sop031_pbr_liab = this->sop031_pbr_liab(last_proj_period); 
double sop031_ulsg_br = this->sop031_ulsg_br(last_proj_period); 

sfas97rd_state_of_world_financial_output
<< group << ","
<< dac_acq_exp << ","
<< dac_acq_exp_loss_rec << ","
<< capzd_acq_exp_accum << ","
<< capzd_acq_exp_accum_loss_rec_int_rate << ","
<< dac_acq_exp_loss_rec_accum << ","
<< dac_comm << ","
<< dac_comm_loss_rec << ","
<< capzd_comm_accum << ","
<< capzd_comm_accum_loss_rec_int_rate << ","
<< dac_comm_loss_rec_accum << ","
<< dac_prem_bonus << ","
<< dac_prem_bonus_loss_res << ","
<< capzd_prem_bonus_accum << ","
<< capzd_prem_bonus_accum_loss_rec_int_rate << ","
<< dac_prem_bonus_loss_rec_accum << ","
<< egp_accum << ","
<< egp_accum_loss_rec_int_rate << ","
<< sop031_assess_accum << ","
<< sop031_gmdb_ben_accum << ","
<< sop031_gmib_ben_accum << ","
<< sop031_gmwb_ben_accum << ","
<< sop031_pbr_accum << ","
<< deferred_loads_accum << ","
<< unearn_rev_liab << ","
<< dac_reins_yrt_asset << ","
<< reins_yrt_cost_accum << ","
<< sop031_pbr_fund_val_accum << ","
<< embed_deriv_val << ","
<< sfas133_gmab_liab << ","
<< sfas133_gmib_liab << ","
<< sfas133_gmwb_liab << ","
<< sop031_ulsg_ben_accum << ","
<< sop031_gmdb_br << ","
<< sop031_gmib_br << ","
<< sop031_gmwb_br << ","
<< sop031_pbr_liab << ","
<< sop031_ulsg_br << endl;

return;
}



void SFAS97RD_GAAP::Terminator()
{

sfas97rd_state_of_world_financial_output.close();

}

FunctionPtr SFAS97RD_GAAP::RegisterTerminatorOnce = []() {
    ::PushTerminator(Terminator);
    RegisterTerminatorOnce = NoOp;
};

	static SFAS97RD_GAAP_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (SFAS97RD_GAAP_UDF::*dPXi) (int);
typedef double (SFAS97RD_GAAP_UDF::*dPXid) (int, double);
typedef double (SFAS97RD_GAAP_UDF::*dPF) ();
typedef double (SFAS97RD_GAAP_UDF::*dPFd) (double);
typedef int (SFAS97RD_GAAP_UDF::*iPF) ();
typedef int (SFAS97RD_GAAP_UDF::*iPFi) (int);
typedef xstring (SFAS97RD_GAAP_UDF::*sPF) ();
typedef xstring (SFAS97RD_GAAP_UDF::*sPFs) (xstring);

const CashFlowCommonData SFAS97RD_GAAP::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "acq_exp", "sfas97rd_gaap_acq_exp",  "acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->acq_exp),
	CashFlowCommonData(2, "agp", "sfas97rd_gaap_agp",  "agp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_agp, 'E','N', '3', 'P', (size_t)&modelOffset->agp),
	CashFlowCommonData(3, "amortzn_int_rate", "sfas97rd_gaap_amortzn_int_rate",  "amortzn_int_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_amortzn_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->amortzn_int_rate),
	CashFlowCommonData(4, "cal_mth", "sfas97rd_gaap_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(5, "cal_yr", "sfas97rd_gaap_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(6, "cal_yr_relative", "sfas97rd_gaap_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(7, "cap_gain", "sfas97rd_gaap_cap_gain",  "cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cap_gain, 'E','Y', '3', 'P', (size_t)&modelOffset->cap_gain),
	CashFlowCommonData(8, "cap_gain_fund", "sfas97rd_gaap_cap_gain_fund",  "cap_gain_fund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cap_gain_fund, 'E','N', '3', 'P', (size_t)&modelOffset->cap_gain_fund),
	CashFlowCommonData(9, "capzd_acq_exp", "sfas97rd_gaap_capzd_acq_exp",  "capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->capzd_acq_exp),
	CashFlowCommonData(10, "capzd_acq_exp_accum", "sfas97rd_gaap_capzd_acq_exp_accum",  "capzd_acq_exp_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_acq_exp_accum, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_acq_exp_accum),
	CashFlowCommonData(11, "capzd_acq_exp_accum_loss_rec_int_rate", "sfas97rd_gaap_capzd_acq_exp_accum_loss_rec_int_rate",  "capzd_acq_exp_accum_loss_rec_int_rate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_acq_exp_accum_loss_rec_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_acq_exp_accum_loss_rec_int_rate),
	CashFlowCommonData(12, "capzd_acq_exp_pv", "sfas97rd_gaap_capzd_acq_exp_pv",  "capzd_acq_exp_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_acq_exp_pv, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_acq_exp_pv),
	CashFlowCommonData(13, "capzd_acq_exp_pv_loss_rec_int_rate", "sfas97rd_gaap_capzd_acq_exp_pv_loss_rec_int_rate",  "capzd_acq_exp_pv_loss_rec_int_rate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_acq_exp_pv_loss_rec_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_acq_exp_pv_loss_rec_int_rate),
	CashFlowCommonData(14, "capzd_comm_accum", "sfas97rd_gaap_capzd_comm_accum",  "capzd_comm_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_accum, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_comm_accum),
	CashFlowCommonData(15, "capzd_comm_accum_loss_rec_int_rate", "sfas97rd_gaap_capzd_comm_accum_loss_rec_int_rate",  "capzd_comm_accum_loss_rec_int_rate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_accum_loss_rec_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_comm_accum_loss_rec_int_rate),
	CashFlowCommonData(16, "capzd_comm_bom", "sfas97rd_gaap_capzd_comm_bom",  "capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->capzd_comm_bom),
	CashFlowCommonData(17, "capzd_comm_chargeback", "sfas97rd_gaap_capzd_comm_chargeback",  "capzd_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_chargeback, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_comm_chargeback),
	CashFlowCommonData(18, "capzd_comm_eom", "sfas97rd_gaap_capzd_comm_eom",  "capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->capzd_comm_eom),
	CashFlowCommonData(19, "capzd_comm_pv", "sfas97rd_gaap_capzd_comm_pv",  "capzd_comm_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_pv, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_comm_pv),
	CashFlowCommonData(20, "capzd_comm_pv_loss_rec_int_rate", "sfas97rd_gaap_capzd_comm_pv_loss_rec_int_rate",  "capzd_comm_pv_loss_rec_int_rate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_pv_loss_rec_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_comm_pv_loss_rec_int_rate),
	CashFlowCommonData(21, "capzd_prem_bonus", "sfas97rd_gaap_capzd_prem_bonus",  "capzd_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_prem_bonus, 'B','Y', '3', 'P', (size_t)&modelOffset->capzd_prem_bonus),
	CashFlowCommonData(22, "capzd_prem_bonus_accum", "sfas97rd_gaap_capzd_prem_bonus_accum",  "capzd_prem_bonus_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_prem_bonus_accum, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_prem_bonus_accum),
	CashFlowCommonData(23, "capzd_prem_bonus_accum_loss_rec_int_rate", "sfas97rd_gaap_capzd_prem_bonus_accum_loss_rec_int_rate",  "capzd_prem_bonus_accum_loss_rec_int_rate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_prem_bonus_accum_loss_rec_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_prem_bonus_accum_loss_rec_int_rate),
	CashFlowCommonData(24, "capzd_prem_bonus_pv", "sfas97rd_gaap_capzd_prem_bonus_pv",  "capzd_prem_bonus_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_prem_bonus_pv, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_prem_bonus_pv),
	CashFlowCommonData(25, "capzd_prem_bonus_pv_loss_rec_int_rate", "sfas97rd_gaap_capzd_prem_bonus_pv_loss_rec_int_rate",  "capzd_prem_bonus_pv_loss_rec_int_rate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_prem_bonus_pv_loss_rec_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_prem_bonus_pv_loss_rec_int_rate),
	CashFlowCommonData(26, "capzd_reins_yrt_cost", "sfas97rd_gaap_capzd_reins_yrt_cost",  "capzd_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_reins_yrt_cost),
	CashFlowCommonData(27, "cash_flow_bom", "sfas97rd_gaap_cash_flow_bom",  "cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->cash_flow_bom),
	CashFlowCommonData(28, "cash_flow_int", "sfas97rd_gaap_cash_flow_int",  "cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cash_flow_int, 'B','Y', '3', 'P', (size_t)&modelOffset->cash_flow_int),
	CashFlowCommonData(29, "charges", "sfas97rd_gaap_charges",  "charges",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_charges, 'B','Y', '3', 'P', (size_t)&modelOffset->charges),
	CashFlowCommonData(30, "comm_chargeback", "sfas97rd_gaap_comm_chargeback",  "comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->comm_chargeback),
	CashFlowCommonData(31, "comm_excess_bom", "sfas97rd_gaap_comm_excess_bom",  "comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_excess_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->comm_excess_bom),
	CashFlowCommonData(32, "comm_excess_eom", "sfas97rd_gaap_comm_excess_eom",  "comm_excess_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_excess_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->comm_excess_eom),
	CashFlowCommonData(33, "comm_trail_bom", "sfas97rd_gaap_comm_trail_bom",  "comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_trail_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->comm_trail_bom),
	CashFlowCommonData(34, "comm_trail_eom", "sfas97rd_gaap_comm_trail_eom",  "comm_trail_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_trail_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->comm_trail_eom),
	CashFlowCommonData(35, "credited_int", "sfas97rd_gaap_credited_int",  "credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_credited_int, 'E','Y', '3', 'C', (size_t)&modelOffset->credited_int),
	CashFlowCommonData(36, "dac_acq_exp", "sfas97rd_gaap_dac_acq_exp",  "dac_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp, 'E','N', '3', 'P', (size_t)&modelOffset->dac_acq_exp),
	CashFlowCommonData(37, "dac_acq_exp_amortzn", "sfas97rd_gaap_dac_acq_exp_amortzn",  "dac_acq_exp_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_amortzn, 'E','N', '3', 'P', (size_t)&modelOffset->dac_acq_exp_amortzn),
	CashFlowCommonData(38, "dac_acq_exp_incr", "sfas97rd_gaap_dac_acq_exp_incr",  "dac_acq_exp_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->dac_acq_exp_incr),
	CashFlowCommonData(39, "dac_acq_exp_int", "sfas97rd_gaap_dac_acq_exp_int",  "dac_acq_exp_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_int, 'E','N', '3', 'P', (size_t)&modelOffset->dac_acq_exp_int),
	CashFlowCommonData(40, "dac_acq_exp_loss_rec", "sfas97rd_gaap_dac_acq_exp_loss_rec",  "dac_acq_exp_loss_rec",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_loss_rec, 'E','Y', '3', 'P', (size_t)&modelOffset->dac_acq_exp_loss_rec),
	CashFlowCommonData(41, "dac_acq_exp_loss_rec_accum", "sfas97rd_gaap_dac_acq_exp_loss_rec_accum",  "dac_acq_exp_loss_rec_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_loss_rec_accum, 'E','N', '3', 'P', (size_t)&modelOffset->dac_acq_exp_loss_rec_accum),
	CashFlowCommonData(42, "dac_acq_exp_loss_rec_hist_accum", "sfas97rd_gaap_dac_acq_exp_loss_rec_hist_accum",  "dac_acq_exp_loss_rec_hist_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_loss_rec_hist_accum, 'E','N', '3', 'P', (size_t)&modelOffset->dac_acq_exp_loss_rec_hist_accum),
	CashFlowCommonData(43, "dac_acq_exp_sch", "sfas97rd_gaap_dac_acq_exp_sch",  "dac_acq_exp_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_sch, 'E','N', '3', 'P', (size_t)&modelOffset->dac_acq_exp_sch),
	CashFlowCommonData(44, "dac_comm", "sfas97rd_gaap_dac_comm",  "dac_comm",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm, 'E','N', '3', 'P', (size_t)&modelOffset->dac_comm),
	CashFlowCommonData(45, "dac_comm_amortzn", "sfas97rd_gaap_dac_comm_amortzn",  "dac_comm_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_amortzn, 'E','N', '3', 'P', (size_t)&modelOffset->dac_comm_amortzn),
	CashFlowCommonData(46, "dac_comm_incr", "sfas97rd_gaap_dac_comm_incr",  "dac_comm_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->dac_comm_incr),
	CashFlowCommonData(47, "dac_comm_int", "sfas97rd_gaap_dac_comm_int",  "dac_comm_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_int, 'E','N', '3', 'P', (size_t)&modelOffset->dac_comm_int),
	CashFlowCommonData(48, "dac_comm_loss_rec", "sfas97rd_gaap_dac_comm_loss_rec",  "dac_comm_loss_rec",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_loss_rec, 'E','Y', '3', 'P', (size_t)&modelOffset->dac_comm_loss_rec),
	CashFlowCommonData(49, "dac_comm_loss_rec_accum", "sfas97rd_gaap_dac_comm_loss_rec_accum",  "dac_comm_loss_rec_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_loss_rec_accum, 'E','N', '3', 'P', (size_t)&modelOffset->dac_comm_loss_rec_accum),
	CashFlowCommonData(50, "dac_comm_loss_rec_hist_accum", "sfas97rd_gaap_dac_comm_loss_rec_hist_accum",  "dac_comm_loss_rec_hist_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_loss_rec_hist_accum, 'E','N', '3', 'P', (size_t)&modelOffset->dac_comm_loss_rec_hist_accum),
	CashFlowCommonData(51, "dac_comm_sch", "sfas97rd_gaap_dac_comm_sch",  "dac_comm_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_sch, 'E','N', '3', 'P', (size_t)&modelOffset->dac_comm_sch),
	CashFlowCommonData(52, "dac_incr", "sfas97rd_gaap_dac_incr",  "dac_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->dac_incr),
	CashFlowCommonData(53, "dac_prem_bonus", "sfas97rd_gaap_dac_prem_bonus",  "dac_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus, 'E','N', '3', 'P', (size_t)&modelOffset->dac_prem_bonus),
	CashFlowCommonData(54, "dac_prem_bonus_amortzn", "sfas97rd_gaap_dac_prem_bonus_amortzn",  "dac_prem_bonus_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_amortzn, 'E','N', '3', 'P', (size_t)&modelOffset->dac_prem_bonus_amortzn),
	CashFlowCommonData(55, "dac_prem_bonus_incr", "sfas97rd_gaap_dac_prem_bonus_incr",  "dac_prem_bonus_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->dac_prem_bonus_incr),
	CashFlowCommonData(56, "dac_prem_bonus_int", "sfas97rd_gaap_dac_prem_bonus_int",  "dac_prem_bonus_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_int, 'E','N', '3', 'P', (size_t)&modelOffset->dac_prem_bonus_int),
	CashFlowCommonData(57, "dac_prem_bonus_loss_rec", "sfas97rd_gaap_dac_prem_bonus_loss_rec",  "dac_prem_bonus_loss_rec",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_loss_rec, 'E','Y', '3', 'P', (size_t)&modelOffset->dac_prem_bonus_loss_rec),
	CashFlowCommonData(58, "dac_prem_bonus_loss_rec_accum", "sfas97rd_gaap_dac_prem_bonus_loss_rec_accum",  "dac_prem_bonus_loss_rec_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_loss_rec_accum, 'E','N', '3', 'P', (size_t)&modelOffset->dac_prem_bonus_loss_rec_accum),
	CashFlowCommonData(59, "dac_prem_bonus_loss_rec_hist_accum", "sfas97rd_gaap_dac_prem_bonus_loss_rec_hist_accum",  "dac_prem_bonus_loss_rec_hist_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_loss_rec_hist_accum, 'E','N', '3', 'P', (size_t)&modelOffset->dac_prem_bonus_loss_rec_hist_accum),
	CashFlowCommonData(60, "dac_prem_bonus_sch", "sfas97rd_gaap_dac_prem_bonus_sch",  "dac_prem_bonus_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_sch, 'E','N', '3', 'P', (size_t)&modelOffset->dac_prem_bonus_sch),
	CashFlowCommonData(61, "dac_reins_yrt_asset", "sfas97rd_gaap_dac_reins_yrt_asset",  "dac_reins_yrt_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset, 'E','N', '3', 'P', (size_t)&modelOffset->dac_reins_yrt_asset),
	CashFlowCommonData(62, "dac_reins_yrt_asset_amortzn", "sfas97rd_gaap_dac_reins_yrt_asset_amortzn",  "dac_reins_yrt_asset_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset_amortzn, 'E','N', '3', 'P', (size_t)&modelOffset->dac_reins_yrt_asset_amortzn),
	CashFlowCommonData(63, "dac_reins_yrt_asset_incr", "sfas97rd_gaap_dac_reins_yrt_asset_incr",  "dac_reins_yrt_asset_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->dac_reins_yrt_asset_incr),
	CashFlowCommonData(64, "dac_reins_yrt_asset_int", "sfas97rd_gaap_dac_reins_yrt_asset_int",  "dac_reins_yrt_asset_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset_int, 'E','N', '3', 'P', (size_t)&modelOffset->dac_reins_yrt_asset_int),
	CashFlowCommonData(65, "dac_reins_yrt_asset_sch", "sfas97rd_gaap_dac_reins_yrt_asset_sch",  "dac_reins_yrt_asset_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset_sch, 'E','N', '3', 'P', (size_t)&modelOffset->dac_reins_yrt_asset_sch),
	CashFlowCommonData(66, "date", "sfas97rd_gaap_date",  "date",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(67, "deferred_loads", "sfas97rd_gaap_deferred_loads",  "deferred_loads",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_deferred_loads, 'E','N', '3', 'P', (size_t)&modelOffset->deferred_loads),
	CashFlowCommonData(68, "deferred_loads_accum", "sfas97rd_gaap_deferred_loads_accum",  "deferred_loads_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_deferred_loads_accum, 'E','N', '3', 'P', (size_t)&modelOffset->deferred_loads_accum),
	CashFlowCommonData(69, "deferred_loads_pv", "sfas97rd_gaap_deferred_loads_pv",  "deferred_loads_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_deferred_loads_pv, 'E','N', '3', 'P', (size_t)&modelOffset->deferred_loads_pv),
	CashFlowCommonData(70, "dth_claim_cost", "sfas97rd_gaap_dth_claim_cost",  "dth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dth_claim_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->dth_claim_cost),
	CashFlowCommonData(71, "egp", "sfas97rd_gaap_egp",  "egp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp, 'E','N', '3', 'P', (size_t)&modelOffset->egp),
	CashFlowCommonData(72, "egp_accum", "sfas97rd_gaap_egp_accum",  "egp_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_accum, 'E','N', '3', 'P', (size_t)&modelOffset->egp_accum),
	CashFlowCommonData(73, "egp_accum_loss_rec_int_rate", "sfas97rd_gaap_egp_accum_loss_rec_int_rate",  "egp_accum_loss_rec_int_rate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_accum_loss_rec_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->egp_accum_loss_rec_int_rate),
	CashFlowCommonData(74, "egp_gain_exp", "sfas97rd_gaap_egp_gain_exp",  "egp_gain_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_exp, 'E','N', '3', 'P', (size_t)&modelOffset->egp_gain_exp),
	CashFlowCommonData(75, "egp_gain_inv", "sfas97rd_gaap_egp_gain_inv",  "egp_gain_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_inv, 'E','N', '3', 'P', (size_t)&modelOffset->egp_gain_inv),
	CashFlowCommonData(76, "egp_gain_mort", "sfas97rd_gaap_egp_gain_mort",  "egp_gain_mort",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_mort, 'E','N', '3', 'P', (size_t)&modelOffset->egp_gain_mort),
	CashFlowCommonData(77, "egp_gain_persist_bon_ref", "sfas97rd_gaap_egp_gain_persist_bon_ref",  "egp_gain_persist_bon_ref",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_persist_bon_ref, 'E','Y', '3', 'C', (size_t)&modelOffset->egp_gain_persist_bon_ref),
	CashFlowCommonData(78, "egp_gain_surr", "sfas97rd_gaap_egp_gain_surr",  "egp_gain_surr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_surr, 'E','N', '3', 'P', (size_t)&modelOffset->egp_gain_surr),
	CashFlowCommonData(79, "egp_pv", "sfas97rd_gaap_egp_pv",  "egp_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_pv, 'E','N', '3', 'P', (size_t)&modelOffset->egp_pv),
	CashFlowCommonData(80, "egp_pv_loss_rec_int_rate", "sfas97rd_gaap_egp_pv_loss_rec_int_rate",  "egp_pv_loss_rec_int_rate",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_pv_loss_rec_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->egp_pv_loss_rec_int_rate),
	CashFlowCommonData(81, "egp_sop031_assess_accum", "sfas97rd_gaap_egp_sop031_assess_accum",  "egp_sop031_assess_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_assess_accum, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_assess_accum),
	CashFlowCommonData(82, "egp_sop031_gmdb_ben_accum", "sfas97rd_gaap_egp_sop031_gmdb_ben_accum",  "egp_sop031_gmdb_ben_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmdb_ben_accum, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_gmdb_ben_accum),
	CashFlowCommonData(83, "egp_sop031_gmdb_liab", "sfas97rd_gaap_egp_sop031_gmdb_liab",  "egp_sop031_gmdb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmdb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_gmdb_liab),
	CashFlowCommonData(84, "egp_sop031_gmib_ben_accum", "sfas97rd_gaap_egp_sop031_gmib_ben_accum",  "egp_sop031_gmib_ben_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmib_ben_accum, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_gmib_ben_accum),
	CashFlowCommonData(85, "egp_sop031_gmib_liab", "sfas97rd_gaap_egp_sop031_gmib_liab",  "egp_sop031_gmib_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmib_liab, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_gmib_liab),
	CashFlowCommonData(86, "egp_sop031_gmwb_ben_accum", "sfas97rd_gaap_egp_sop031_gmwb_ben_accum",  "egp_sop031_gmwb_ben_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmwb_ben_accum, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_gmwb_ben_accum),
	CashFlowCommonData(87, "egp_sop031_gmwb_liab", "sfas97rd_gaap_egp_sop031_gmwb_liab",  "egp_sop031_gmwb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmwb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_gmwb_liab),
	CashFlowCommonData(88, "egp_sop031_res_incr", "sfas97rd_gaap_egp_sop031_res_incr",  "egp_sop031_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_res_incr, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_res_incr),
	CashFlowCommonData(89, "egp_sop031_ulsg_ben_accum", "sfas97rd_gaap_egp_sop031_ulsg_ben_accum",  "egp_sop031_ulsg_ben_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_ulsg_ben_accum, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_ulsg_ben_accum),
	CashFlowCommonData(90, "egp_sop031_ulsg_liab", "sfas97rd_gaap_egp_sop031_ulsg_liab",  "egp_sop031_ulsg_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_ulsg_liab, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_ulsg_liab),
	CashFlowCommonData(91, "embed_deriv_cash_flow", "sfas97rd_gaap_embed_deriv_cash_flow",  "embed_deriv_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_embed_deriv_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->embed_deriv_cash_flow),
	CashFlowCommonData(92, "embed_deriv_cash_flow_pv", "sfas97rd_gaap_embed_deriv_cash_flow_pv",  "embed_deriv_cash_flow_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_embed_deriv_cash_flow_pv, 'E','Y', '3', 'P', (size_t)&modelOffset->embed_deriv_cash_flow_pv),
	CashFlowCommonData(93, "embed_deriv_val", "sfas97rd_gaap_embed_deriv_val",  "embed_deriv_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_embed_deriv_val, 'E','Y', '3', 'P', (size_t)&modelOffset->embed_deriv_val),
	CashFlowCommonData(94, "finalize", "sfas97rd_gaap_finalize",  "finalize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_finalize, 'E','N', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(95, "fund_val", "sfas97rd_gaap_fund_val",  "fund_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_fund_val, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val),
	CashFlowCommonData(96, "fund_val_bef_int", "sfas97rd_gaap_fund_val_bef_int",  "fund_val_bef_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_fund_val_bef_int, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val_bef_int),
	CashFlowCommonData(97, "fund_val_fixed", "sfas97rd_gaap_fund_val_fixed",  "fund_val_fixed",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_fund_val_fixed, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val_fixed),
	CashFlowCommonData(98, "fund_val_sa", "sfas97rd_gaap_fund_val_sa",  "fund_val_sa",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_fund_val_sa, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val_sa),
	CashFlowCommonData(99, "gaap_amortzn_int_rate", "sfas97rd_gaap_gaap_amortzn_int_rate",  "gaap_amortzn_int_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gaap_amortzn_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->gaap_amortzn_int_rate),
	CashFlowCommonData(100, "gmab_ben", "sfas97rd_gaap_gmab_ben",  "gmab_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmab_ben, 'E','N', '3', 'P', (size_t)&modelOffset->gmab_ben),
	CashFlowCommonData(101, "gmdb_ben", "sfas97rd_gaap_gmdb_ben",  "gmdb_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmdb_ben, 'E','N', '3', 'P', (size_t)&modelOffset->gmdb_ben),
	CashFlowCommonData(102, "gmib_ben", "sfas97rd_gaap_gmib_ben",  "gmib_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmib_ben, 'E','N', '3', 'P', (size_t)&modelOffset->gmib_ben),
	CashFlowCommonData(103, "gmwb_ben", "sfas97rd_gaap_gmwb_ben",  "gmwb_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmwb_ben, 'E','N', '3', 'P', (size_t)&modelOffset->gmwb_ben),
	CashFlowCommonData(104, "hedge_cash_flow", "sfas97rd_gaap_hedge_cash_flow",  "hedge_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cash_flow),
	CashFlowCommonData(105, "hedge_cost", "sfas97rd_gaap_hedge_cost",  "hedge_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cost),
	CashFlowCommonData(106, "hedge_mkt_val", "sfas97rd_gaap_hedge_mkt_val",  "hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->hedge_mkt_val),
	CashFlowCommonData(107, "hedge_mkt_val_incr", "sfas97rd_gaap_hedge_mkt_val_incr",  "hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_mkt_val_incr),
	CashFlowCommonData(108, "host_contract_cred_int", "sfas97rd_gaap_host_contract_cred_int",  "host_contract_cred_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_host_contract_cred_int, 'E','Y', '3', 'P', (size_t)&modelOffset->host_contract_cred_int),
	CashFlowCommonData(109, "host_contract_val", "sfas97rd_gaap_host_contract_val",  "host_contract_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_host_contract_val, 'E','Y', '3', 'P', (size_t)&modelOffset->host_contract_val),
	CashFlowCommonData(110, "host_contract_val_bef", "sfas97rd_gaap_host_contract_val_bef",  "host_contract_val_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_host_contract_val_bef, 'E','Y', '3', 'P', (size_t)&modelOffset->host_contract_val_bef),
	CashFlowCommonData(111, "initialize", "sfas97rd_gaap_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(112, "inv_inc", "sfas97rd_gaap_inv_inc",  "inv_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_inv_inc, 'E','Y', '3', 'P', (size_t)&modelOffset->inv_inc),
	CashFlowCommonData(113, "inv_inc_fund", "sfas97rd_gaap_inv_inc_fund",  "inv_inc_fund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_inv_inc_fund, 'E','N', '3', 'P', (size_t)&modelOffset->inv_inc_fund),
	CashFlowCommonData(114, "k_capzd_acq_exp", "sfas97rd_gaap_k_capzd_acq_exp",  "k_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_acq_exp, 'E','N', '3', 'P', (size_t)&modelOffset->k_capzd_acq_exp),
	CashFlowCommonData(115, "k_capzd_acq_exp_sch", "sfas97rd_gaap_k_capzd_acq_exp_sch",  "k_capzd_acq_exp_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_acq_exp_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_capzd_acq_exp_sch),
	CashFlowCommonData(116, "k_capzd_comm", "sfas97rd_gaap_k_capzd_comm",  "k_capzd_comm",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_comm, 'E','N', '3', 'P', (size_t)&modelOffset->k_capzd_comm),
	CashFlowCommonData(117, "k_capzd_comm_sch", "sfas97rd_gaap_k_capzd_comm_sch",  "k_capzd_comm_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_comm_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_capzd_comm_sch),
	CashFlowCommonData(118, "k_capzd_prem_bonus", "sfas97rd_gaap_k_capzd_prem_bonus",  "k_capzd_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_prem_bonus, 'E','N', '3', 'P', (size_t)&modelOffset->k_capzd_prem_bonus),
	CashFlowCommonData(119, "k_capzd_prem_bonus_sch", "sfas97rd_gaap_k_capzd_prem_bonus_sch",  "k_capzd_prem_bonus_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_prem_bonus_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_capzd_prem_bonus_sch),
	CashFlowCommonData(120, "k_reins_yrt_cost", "sfas97rd_gaap_k_reins_yrt_cost",  "k_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->k_reins_yrt_cost),
	CashFlowCommonData(121, "k_reins_yrt_cost_sch", "sfas97rd_gaap_k_reins_yrt_cost_sch",  "k_reins_yrt_cost_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_reins_yrt_cost_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_reins_yrt_cost_sch),
	CashFlowCommonData(122, "k_sop031_gmdb_ben_br", "sfas97rd_gaap_k_sop031_gmdb_ben_br",  "k_sop031_gmdb_ben_br",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_gmdb_ben_br, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_gmdb_ben_br),
	CashFlowCommonData(123, "k_sop031_gmdb_ben_br_sch", "sfas97rd_gaap_k_sop031_gmdb_ben_br_sch",  "k_sop031_gmdb_ben_br_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_gmdb_ben_br_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_gmdb_ben_br_sch),
	CashFlowCommonData(124, "k_sop031_pbr", "sfas97rd_gaap_k_sop031_pbr",  "k_sop031_pbr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_pbr, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_pbr),
	CashFlowCommonData(125, "k_sop031_pbr_sch", "sfas97rd_gaap_k_sop031_pbr_sch",  "k_sop031_pbr_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_pbr_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_pbr_sch),
	CashFlowCommonData(126, "k_sop031_ulsg_ben_br", "sfas97rd_gaap_k_sop031_ulsg_ben_br",  "k_sop031_ulsg_ben_br",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_ulsg_ben_br, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_ulsg_ben_br),
	CashFlowCommonData(127, "k_sop031_ulsg_ben_br_sch", "sfas97rd_gaap_k_sop031_ulsg_ben_br_sch",  "k_sop031_ulsg_ben_br_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_ulsg_ben_br_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_ulsg_ben_br_sch),
	CashFlowCommonData(128, "k_sop031_unearn_rev_liab", "sfas97rd_gaap_k_sop031_unearn_rev_liab",  "k_sop031_unearn_rev_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_unearn_rev_liab, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_unearn_rev_liab),
	CashFlowCommonData(129, "k_sop031_unearn_rev_liab_sch", "sfas97rd_gaap_k_sop031_unearn_rev_liab_sch",  "k_sop031_unearn_rev_liab_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_unearn_rev_liab_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_unearn_rev_liab_sch),
	CashFlowCommonData(130, "k_unearn_rev_liab", "sfas97rd_gaap_k_unearn_rev_liab",  "k_unearn_rev_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_unearn_rev_liab, 'E','N', '3', 'P', (size_t)&modelOffset->k_unearn_rev_liab),
	CashFlowCommonData(131, "k_unearn_rev_liab_sch", "sfas97rd_gaap_k_unearn_rev_liab_sch",  "k_unearn_rev_liab_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_unearn_rev_liab_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_unearn_rev_liab_sch),
	CashFlowCommonData(132, "liab_net", "sfas97rd_gaap_liab_net",  "liab_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_liab_net, 'E','Y', '3', 'P', (size_t)&modelOffset->liab_net),
	CashFlowCommonData(133, "loads", "sfas97rd_gaap_loads",  "loads",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_loads, 'B','Y', '3', 'P', (size_t)&modelOffset->loads),
	CashFlowCommonData(134, "loc_cost", "sfas97rd_gaap_loc_cost",  "loc_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_loc_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->loc_cost),
	CashFlowCommonData(135, "loss_rec_amortzn_int_rate", "sfas97rd_gaap_loss_rec_amortzn_int_rate",  "loss_rec_amortzn_int_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_loss_rec_amortzn_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->loss_rec_amortzn_int_rate),
	CashFlowCommonData(136, "maint_exp_bom", "sfas97rd_gaap_maint_exp_bom",  "maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->maint_exp_bom),
	CashFlowCommonData(137, "maint_exp_eom", "sfas97rd_gaap_maint_exp_eom",  "maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_maint_exp_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->maint_exp_eom),
	CashFlowCommonData(138, "modco_liab", "sfas97rd_gaap_modco_liab",  "modco_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_modco_liab, 'E','N', '3', 'C', (size_t)&modelOffset->modco_liab),
	CashFlowCommonData(139, "modco_liab_incr", "sfas97rd_gaap_modco_liab_incr",  "modco_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_modco_liab_incr, 'E','N', '3', 'P', (size_t)&modelOffset->modco_liab_incr),
	CashFlowCommonData(140, "modco_res_adj", "sfas97rd_gaap_modco_res_adj",  "modco_res_adj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_modco_res_adj, 'E','Y', '3', 'C', (size_t)&modelOffset->modco_res_adj),
	CashFlowCommonData(141, "persist_bon_ref", "sfas97rd_gaap_persist_bon_ref",  "persist_bon_ref",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_persist_bon_ref, 'E','N', '3', 'P', (size_t)&modelOffset->persist_bon_ref),
	CashFlowCommonData(142, "pol_loan", "sfas97rd_gaap_pol_loan",  "pol_loan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_pol_loan, 'E','Y', '3', 'P', (size_t)&modelOffset->pol_loan),
	CashFlowCommonData(143, "pol_loan_inc", "sfas97rd_gaap_pol_loan_inc",  "pol_loan_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_pol_loan_inc, 'E','Y', '3', 'P', (size_t)&modelOffset->pol_loan_inc),
	CashFlowCommonData(144, "policies_b", "sfas97rd_gaap_policies_b",  "policies_b",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_policies_b, 'B','N', '3', 'C', (size_t)&modelOffset->policies_b),
	CashFlowCommonData(145, "prem_bonus", "sfas97rd_gaap_prem_bonus",  "prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_prem_bonus, 'B','Y', '3', 'P', (size_t)&modelOffset->prem_bonus),
	CashFlowCommonData(146, "prem_tax", "sfas97rd_gaap_prem_tax",  "prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_prem_tax, 'B','Y', '3', 'P', (size_t)&modelOffset->prem_tax),
	CashFlowCommonData(147, "refund", "sfas97rd_gaap_refund",  "refund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_refund, 'E','Y', '3', 'C', (size_t)&modelOffset->refund),
	CashFlowCommonData(148, "reins_yrt_cost", "sfas97rd_gaap_reins_yrt_cost",  "reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->reins_yrt_cost),
	CashFlowCommonData(149, "reins_yrt_cost_accum", "sfas97rd_gaap_reins_yrt_cost_accum",  "reins_yrt_cost_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_reins_yrt_cost_accum, 'E','N', '3', 'P', (size_t)&modelOffset->reins_yrt_cost_accum),
	CashFlowCommonData(150, "reins_yrt_cost_pv", "sfas97rd_gaap_reins_yrt_cost_pv",  "reins_yrt_cost_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_reins_yrt_cost_pv, 'E','N', '3', 'P', (size_t)&modelOffset->reins_yrt_cost_pv),
	CashFlowCommonData(151, "rider_charges", "sfas97rd_gaap_rider_charges",  "rider_charges",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_rider_charges, 'B','Y', '3', 'P', (size_t)&modelOffset->rider_charges),
	CashFlowCommonData(152, "sfas133_fia_iul_liab", "sfas97rd_gaap_sfas133_fia_iul_liab",  "sfas133_fia_iul_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_fia_iul_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas133_fia_iul_liab),
	CashFlowCommonData(153, "sfas133_gmab_liab", "sfas97rd_gaap_sfas133_gmab_liab",  "sfas133_gmab_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_gmab_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas133_gmab_liab),
	CashFlowCommonData(154, "sfas133_gmib_liab", "sfas97rd_gaap_sfas133_gmib_liab",  "sfas133_gmib_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_gmib_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas133_gmib_liab),
	CashFlowCommonData(155, "sfas133_gmwb_liab", "sfas97rd_gaap_sfas133_gmwb_liab",  "sfas133_gmwb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_gmwb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas133_gmwb_liab),
	CashFlowCommonData(156, "sfas133_liab", "sfas97rd_gaap_sfas133_liab",  "sfas133_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas133_liab),
	CashFlowCommonData(157, "sfas133_liab_incr", "sfas97rd_gaap_sfas133_liab_incr",  "sfas133_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_liab_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas133_liab_incr),
	CashFlowCommonData(158, "sop031_addl_liab", "sfas97rd_gaap_sop031_addl_liab",  "sop031_addl_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_addl_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_addl_liab),
	CashFlowCommonData(159, "sop031_addl_liab_incr", "sfas97rd_gaap_sop031_addl_liab_incr",  "sop031_addl_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_addl_liab_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->sop031_addl_liab_incr),
	CashFlowCommonData(160, "sop031_assess", "sfas97rd_gaap_sop031_assess",  "sop031_assess",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_assess, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_assess),
	CashFlowCommonData(161, "sop031_assess_accum", "sfas97rd_gaap_sop031_assess_accum",  "sop031_assess_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_assess_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_assess_accum),
	CashFlowCommonData(162, "sop031_assess_pv", "sfas97rd_gaap_sop031_assess_pv",  "sop031_assess_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_assess_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_assess_pv),
	CashFlowCommonData(163, "sop031_egp", "sfas97rd_gaap_sop031_egp",  "sop031_egp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_egp, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_egp),
	CashFlowCommonData(164, "sop031_egp_accum", "sfas97rd_gaap_sop031_egp_accum",  "sop031_egp_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_egp_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_egp_accum),
	CashFlowCommonData(165, "sop031_egp_pv", "sfas97rd_gaap_sop031_egp_pv",  "sop031_egp_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_egp_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_egp_pv),
	CashFlowCommonData(166, "sop031_gmdb_ben_accum", "sfas97rd_gaap_sop031_gmdb_ben_accum",  "sop031_gmdb_ben_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_ben_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmdb_ben_accum),
	CashFlowCommonData(167, "sop031_gmdb_ben_pv", "sfas97rd_gaap_sop031_gmdb_ben_pv",  "sop031_gmdb_ben_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_ben_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmdb_ben_pv),
	CashFlowCommonData(168, "sop031_gmdb_br", "sfas97rd_gaap_sop031_gmdb_br",  "sop031_gmdb_br",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_br, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmdb_br),
	CashFlowCommonData(169, "sop031_gmdb_br_sch", "sfas97rd_gaap_sop031_gmdb_br_sch",  "sop031_gmdb_br_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_br_sch, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmdb_br_sch),
	CashFlowCommonData(170, "sop031_gmdb_liab", "sfas97rd_gaap_sop031_gmdb_liab",  "sop031_gmdb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmdb_liab),
	CashFlowCommonData(171, "sop031_gmib_ben_accum", "sfas97rd_gaap_sop031_gmib_ben_accum",  "sop031_gmib_ben_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmib_ben_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmib_ben_accum),
	CashFlowCommonData(172, "sop031_gmib_ben_pv", "sfas97rd_gaap_sop031_gmib_ben_pv",  "sop031_gmib_ben_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmib_ben_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmib_ben_pv),
	CashFlowCommonData(173, "sop031_gmib_br", "sfas97rd_gaap_sop031_gmib_br",  "sop031_gmib_br",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmib_br, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmib_br),
	CashFlowCommonData(174, "sop031_gmib_br_sch", "sfas97rd_gaap_sop031_gmib_br_sch",  "sop031_gmib_br_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmib_br_sch, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmib_br_sch),
	CashFlowCommonData(175, "sop031_gmib_liab", "sfas97rd_gaap_sop031_gmib_liab",  "sop031_gmib_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmib_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmib_liab),
	CashFlowCommonData(176, "sop031_gmwb_ben_accum", "sfas97rd_gaap_sop031_gmwb_ben_accum",  "sop031_gmwb_ben_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmwb_ben_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmwb_ben_accum),
	CashFlowCommonData(177, "sop031_gmwb_ben_pv", "sfas97rd_gaap_sop031_gmwb_ben_pv",  "sop031_gmwb_ben_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmwb_ben_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmwb_ben_pv),
	CashFlowCommonData(178, "sop031_gmwb_br", "sfas97rd_gaap_sop031_gmwb_br",  "sop031_gmwb_br",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmwb_br, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmwb_br),
	CashFlowCommonData(179, "sop031_gmwb_br_sch", "sfas97rd_gaap_sop031_gmwb_br_sch",  "sop031_gmwb_br_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmwb_br_sch, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmwb_br_sch),
	CashFlowCommonData(180, "sop031_gmwb_liab", "sfas97rd_gaap_sop031_gmwb_liab",  "sop031_gmwb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmwb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmwb_liab),
	CashFlowCommonData(181, "sop031_pbr", "sfas97rd_gaap_sop031_pbr",  "sop031_pbr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr),
	CashFlowCommonData(182, "sop031_pbr_accum", "sfas97rd_gaap_sop031_pbr_accum",  "sop031_pbr_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_accum),
	CashFlowCommonData(183, "sop031_pbr_fund_val", "sfas97rd_gaap_sop031_pbr_fund_val",  "sop031_pbr_fund_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_fund_val, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_fund_val),
	CashFlowCommonData(184, "sop031_pbr_fund_val_accum", "sfas97rd_gaap_sop031_pbr_fund_val_accum",  "sop031_pbr_fund_val_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_fund_val_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_fund_val_accum),
	CashFlowCommonData(185, "sop031_pbr_fund_val_pv", "sfas97rd_gaap_sop031_pbr_fund_val_pv",  "sop031_pbr_fund_val_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_fund_val_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_fund_val_pv),
	CashFlowCommonData(186, "sop031_pbr_liab", "sfas97rd_gaap_sop031_pbr_liab",  "sop031_pbr_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_liab),
	CashFlowCommonData(187, "sop031_pbr_liab_amortzn", "sfas97rd_gaap_sop031_pbr_liab_amortzn",  "sop031_pbr_liab_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_liab_amortzn, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_liab_amortzn),
	CashFlowCommonData(188, "sop031_pbr_liab_int", "sfas97rd_gaap_sop031_pbr_liab_int",  "sop031_pbr_liab_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_liab_int, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_liab_int),
	CashFlowCommonData(189, "sop031_pbr_liab_sch", "sfas97rd_gaap_sop031_pbr_liab_sch",  "sop031_pbr_liab_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_liab_sch, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_liab_sch),
	CashFlowCommonData(190, "sop031_pbr_pv", "sfas97rd_gaap_sop031_pbr_pv",  "sop031_pbr_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_pv),
	CashFlowCommonData(191, "sop031_pbr_units_inf", "sfas97rd_gaap_sop031_pbr_units_inf",  "sop031_pbr_units_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_units_inf, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_units_inf),
	CashFlowCommonData(192, "sop031_ulsg_ben_accum", "sfas97rd_gaap_sop031_ulsg_ben_accum",  "sop031_ulsg_ben_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_ben_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_ulsg_ben_accum),
	CashFlowCommonData(193, "sop031_ulsg_ben_pv", "sfas97rd_gaap_sop031_ulsg_ben_pv",  "sop031_ulsg_ben_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_ben_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_ulsg_ben_pv),
	CashFlowCommonData(194, "sop031_ulsg_br", "sfas97rd_gaap_sop031_ulsg_br",  "sop031_ulsg_br",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_br, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_ulsg_br),
	CashFlowCommonData(195, "sop031_ulsg_br_sch", "sfas97rd_gaap_sop031_ulsg_br_sch",  "sop031_ulsg_br_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_br_sch, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_ulsg_br_sch),
	CashFlowCommonData(196, "sop031_ulsg_liab", "sfas97rd_gaap_sop031_ulsg_liab",  "sop031_ulsg_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_ulsg_liab),
	CashFlowCommonData(197, "sop031_unearn_rev_liab_incr", "sfas97rd_gaap_sop031_unearn_rev_liab_incr",  "sop031_unearn_rev_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_unearn_rev_liab_incr, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_unearn_rev_liab_incr),
	CashFlowCommonData(198, "startup", "sfas97rd_gaap_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(199, "stat_res_rider", "sfas97rd_gaap_stat_res_rider",  "stat_res_rider",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_stat_res_rider, 'E','N', '3', 'P', (size_t)&modelOffset->stat_res_rider),
	CashFlowCommonData(200, "ulsg_ben", "sfas97rd_gaap_ulsg_ben",  "ulsg_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_ulsg_ben, 'E','N', '3', 'P', (size_t)&modelOffset->ulsg_ben),
	CashFlowCommonData(201, "unearn_rev_liab", "sfas97rd_gaap_unearn_rev_liab",  "unearn_rev_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab, 'E','N', '3', 'P', (size_t)&modelOffset->unearn_rev_liab),
	CashFlowCommonData(202, "unearn_rev_liab_accum", "sfas97rd_gaap_unearn_rev_liab_accum",  "unearn_rev_liab_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_accum, 'E','N', '3', 'P', (size_t)&modelOffset->unearn_rev_liab_accum),
	CashFlowCommonData(203, "unearn_rev_liab_amortzn", "sfas97rd_gaap_unearn_rev_liab_amortzn",  "unearn_rev_liab_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_amortzn, 'E','N', '3', 'P', (size_t)&modelOffset->unearn_rev_liab_amortzn),
	CashFlowCommonData(204, "unearn_rev_liab_incr", "sfas97rd_gaap_unearn_rev_liab_incr",  "unearn_rev_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->unearn_rev_liab_incr),
	CashFlowCommonData(205, "unearn_rev_liab_int", "sfas97rd_gaap_unearn_rev_liab_int",  "unearn_rev_liab_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_int, 'E','N', '3', 'P', (size_t)&modelOffset->unearn_rev_liab_int),
	CashFlowCommonData(206, "unearn_rev_liab_released", "sfas97rd_gaap_unearn_rev_liab_released",  "unearn_rev_liab_released",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_released, 'E','Y', '3', 'P', (size_t)&modelOffset->unearn_rev_liab_released),
	CashFlowCommonData(207, "unearn_rev_liab_sch", "sfas97rd_gaap_unearn_rev_liab_sch",  "unearn_rev_liab_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_sch, 'E','N', '3', 'P', (size_t)&modelOffset->unearn_rev_liab_sch)
};
const CashFlowCommonData* SFAS97RD_GAAP::mCFStaticData[] = {
	&SFAS97RD_GAAP::mCFStaticData_0[0],
	&SFAS97RD_GAAP::mCFStaticData_0[1],
	&SFAS97RD_GAAP::mCFStaticData_0[2],
	&SFAS97RD_GAAP::mCFStaticData_0[3],
	&SFAS97RD_GAAP::mCFStaticData_0[4],
	&SFAS97RD_GAAP::mCFStaticData_0[5],
	&SFAS97RD_GAAP::mCFStaticData_0[6],
	&SFAS97RD_GAAP::mCFStaticData_0[7],
	&SFAS97RD_GAAP::mCFStaticData_0[8],
	&SFAS97RD_GAAP::mCFStaticData_0[9],
	&SFAS97RD_GAAP::mCFStaticData_0[10],
	&SFAS97RD_GAAP::mCFStaticData_0[11],
	&SFAS97RD_GAAP::mCFStaticData_0[12],
	&SFAS97RD_GAAP::mCFStaticData_0[13],
	&SFAS97RD_GAAP::mCFStaticData_0[14],
	&SFAS97RD_GAAP::mCFStaticData_0[15],
	&SFAS97RD_GAAP::mCFStaticData_0[16],
	&SFAS97RD_GAAP::mCFStaticData_0[17],
	&SFAS97RD_GAAP::mCFStaticData_0[18],
	&SFAS97RD_GAAP::mCFStaticData_0[19],
	&SFAS97RD_GAAP::mCFStaticData_0[20],
	&SFAS97RD_GAAP::mCFStaticData_0[21],
	&SFAS97RD_GAAP::mCFStaticData_0[22],
	&SFAS97RD_GAAP::mCFStaticData_0[23],
	&SFAS97RD_GAAP::mCFStaticData_0[24],
	&SFAS97RD_GAAP::mCFStaticData_0[25],
	&SFAS97RD_GAAP::mCFStaticData_0[26],
	&SFAS97RD_GAAP::mCFStaticData_0[27],
	&SFAS97RD_GAAP::mCFStaticData_0[28],
	&SFAS97RD_GAAP::mCFStaticData_0[29],
	&SFAS97RD_GAAP::mCFStaticData_0[30],
	&SFAS97RD_GAAP::mCFStaticData_0[31],
	&SFAS97RD_GAAP::mCFStaticData_0[32],
	&SFAS97RD_GAAP::mCFStaticData_0[33],
	&SFAS97RD_GAAP::mCFStaticData_0[34],
	&SFAS97RD_GAAP::mCFStaticData_0[35],
	&SFAS97RD_GAAP::mCFStaticData_0[36],
	&SFAS97RD_GAAP::mCFStaticData_0[37],
	&SFAS97RD_GAAP::mCFStaticData_0[38],
	&SFAS97RD_GAAP::mCFStaticData_0[39],
	&SFAS97RD_GAAP::mCFStaticData_0[40],
	&SFAS97RD_GAAP::mCFStaticData_0[41],
	&SFAS97RD_GAAP::mCFStaticData_0[42],
	&SFAS97RD_GAAP::mCFStaticData_0[43],
	&SFAS97RD_GAAP::mCFStaticData_0[44],
	&SFAS97RD_GAAP::mCFStaticData_0[45],
	&SFAS97RD_GAAP::mCFStaticData_0[46],
	&SFAS97RD_GAAP::mCFStaticData_0[47],
	&SFAS97RD_GAAP::mCFStaticData_0[48],
	&SFAS97RD_GAAP::mCFStaticData_0[49],
	&SFAS97RD_GAAP::mCFStaticData_0[50],
	&SFAS97RD_GAAP::mCFStaticData_0[51],
	&SFAS97RD_GAAP::mCFStaticData_0[52],
	&SFAS97RD_GAAP::mCFStaticData_0[53],
	&SFAS97RD_GAAP::mCFStaticData_0[54],
	&SFAS97RD_GAAP::mCFStaticData_0[55],
	&SFAS97RD_GAAP::mCFStaticData_0[56],
	&SFAS97RD_GAAP::mCFStaticData_0[57],
	&SFAS97RD_GAAP::mCFStaticData_0[58],
	&SFAS97RD_GAAP::mCFStaticData_0[59],
	&SFAS97RD_GAAP::mCFStaticData_0[60],
	&SFAS97RD_GAAP::mCFStaticData_0[61],
	&SFAS97RD_GAAP::mCFStaticData_0[62],
	&SFAS97RD_GAAP::mCFStaticData_0[63],
	&SFAS97RD_GAAP::mCFStaticData_0[64],
	&SFAS97RD_GAAP::mCFStaticData_0[65],
	&SFAS97RD_GAAP::mCFStaticData_0[66],
	&SFAS97RD_GAAP::mCFStaticData_0[67],
	&SFAS97RD_GAAP::mCFStaticData_0[68],
	&SFAS97RD_GAAP::mCFStaticData_0[69],
	&SFAS97RD_GAAP::mCFStaticData_0[70],
	&SFAS97RD_GAAP::mCFStaticData_0[71],
	&SFAS97RD_GAAP::mCFStaticData_0[72],
	&SFAS97RD_GAAP::mCFStaticData_0[73],
	&SFAS97RD_GAAP::mCFStaticData_0[74],
	&SFAS97RD_GAAP::mCFStaticData_0[75],
	&SFAS97RD_GAAP::mCFStaticData_0[76],
	&SFAS97RD_GAAP::mCFStaticData_0[77],
	&SFAS97RD_GAAP::mCFStaticData_0[78],
	&SFAS97RD_GAAP::mCFStaticData_0[79],
	&SFAS97RD_GAAP::mCFStaticData_0[80],
	&SFAS97RD_GAAP::mCFStaticData_0[81],
	&SFAS97RD_GAAP::mCFStaticData_0[82],
	&SFAS97RD_GAAP::mCFStaticData_0[83],
	&SFAS97RD_GAAP::mCFStaticData_0[84],
	&SFAS97RD_GAAP::mCFStaticData_0[85],
	&SFAS97RD_GAAP::mCFStaticData_0[86],
	&SFAS97RD_GAAP::mCFStaticData_0[87],
	&SFAS97RD_GAAP::mCFStaticData_0[88],
	&SFAS97RD_GAAP::mCFStaticData_0[89],
	&SFAS97RD_GAAP::mCFStaticData_0[90],
	&SFAS97RD_GAAP::mCFStaticData_0[91],
	&SFAS97RD_GAAP::mCFStaticData_0[92],
	&SFAS97RD_GAAP::mCFStaticData_0[93],
	&SFAS97RD_GAAP::mCFStaticData_0[94],
	&SFAS97RD_GAAP::mCFStaticData_0[95],
	&SFAS97RD_GAAP::mCFStaticData_0[96],
	&SFAS97RD_GAAP::mCFStaticData_0[97],
	&SFAS97RD_GAAP::mCFStaticData_0[98],
	&SFAS97RD_GAAP::mCFStaticData_0[99],
	&SFAS97RD_GAAP::mCFStaticData_0[100],
	&SFAS97RD_GAAP::mCFStaticData_0[101],
	&SFAS97RD_GAAP::mCFStaticData_0[102],
	&SFAS97RD_GAAP::mCFStaticData_0[103],
	&SFAS97RD_GAAP::mCFStaticData_0[104],
	&SFAS97RD_GAAP::mCFStaticData_0[105],
	&SFAS97RD_GAAP::mCFStaticData_0[106],
	&SFAS97RD_GAAP::mCFStaticData_0[107],
	&SFAS97RD_GAAP::mCFStaticData_0[108],
	&SFAS97RD_GAAP::mCFStaticData_0[109],
	&SFAS97RD_GAAP::mCFStaticData_0[110],
	&SFAS97RD_GAAP::mCFStaticData_0[111],
	&SFAS97RD_GAAP::mCFStaticData_0[112],
	&SFAS97RD_GAAP::mCFStaticData_0[113],
	&SFAS97RD_GAAP::mCFStaticData_0[114],
	&SFAS97RD_GAAP::mCFStaticData_0[115],
	&SFAS97RD_GAAP::mCFStaticData_0[116],
	&SFAS97RD_GAAP::mCFStaticData_0[117],
	&SFAS97RD_GAAP::mCFStaticData_0[118],
	&SFAS97RD_GAAP::mCFStaticData_0[119],
	&SFAS97RD_GAAP::mCFStaticData_0[120],
	&SFAS97RD_GAAP::mCFStaticData_0[121],
	&SFAS97RD_GAAP::mCFStaticData_0[122],
	&SFAS97RD_GAAP::mCFStaticData_0[123],
	&SFAS97RD_GAAP::mCFStaticData_0[124],
	&SFAS97RD_GAAP::mCFStaticData_0[125],
	&SFAS97RD_GAAP::mCFStaticData_0[126],
	&SFAS97RD_GAAP::mCFStaticData_0[127],
	&SFAS97RD_GAAP::mCFStaticData_0[128],
	&SFAS97RD_GAAP::mCFStaticData_0[129],
	&SFAS97RD_GAAP::mCFStaticData_0[130],
	&SFAS97RD_GAAP::mCFStaticData_0[131],
	&SFAS97RD_GAAP::mCFStaticData_0[132],
	&SFAS97RD_GAAP::mCFStaticData_0[133],
	&SFAS97RD_GAAP::mCFStaticData_0[134],
	&SFAS97RD_GAAP::mCFStaticData_0[135],
	&SFAS97RD_GAAP::mCFStaticData_0[136],
	&SFAS97RD_GAAP::mCFStaticData_0[137],
	&SFAS97RD_GAAP::mCFStaticData_0[138],
	&SFAS97RD_GAAP::mCFStaticData_0[139],
	&SFAS97RD_GAAP::mCFStaticData_0[140],
	&SFAS97RD_GAAP::mCFStaticData_0[141],
	&SFAS97RD_GAAP::mCFStaticData_0[142],
	&SFAS97RD_GAAP::mCFStaticData_0[143],
	&SFAS97RD_GAAP::mCFStaticData_0[144],
	&SFAS97RD_GAAP::mCFStaticData_0[145],
	&SFAS97RD_GAAP::mCFStaticData_0[146],
	&SFAS97RD_GAAP::mCFStaticData_0[147],
	&SFAS97RD_GAAP::mCFStaticData_0[148],
	&SFAS97RD_GAAP::mCFStaticData_0[149],
	&SFAS97RD_GAAP::mCFStaticData_0[150],
	&SFAS97RD_GAAP::mCFStaticData_0[151],
	&SFAS97RD_GAAP::mCFStaticData_0[152],
	&SFAS97RD_GAAP::mCFStaticData_0[153],
	&SFAS97RD_GAAP::mCFStaticData_0[154],
	&SFAS97RD_GAAP::mCFStaticData_0[155],
	&SFAS97RD_GAAP::mCFStaticData_0[156],
	&SFAS97RD_GAAP::mCFStaticData_0[157],
	&SFAS97RD_GAAP::mCFStaticData_0[158],
	&SFAS97RD_GAAP::mCFStaticData_0[159],
	&SFAS97RD_GAAP::mCFStaticData_0[160],
	&SFAS97RD_GAAP::mCFStaticData_0[161],
	&SFAS97RD_GAAP::mCFStaticData_0[162],
	&SFAS97RD_GAAP::mCFStaticData_0[163],
	&SFAS97RD_GAAP::mCFStaticData_0[164],
	&SFAS97RD_GAAP::mCFStaticData_0[165],
	&SFAS97RD_GAAP::mCFStaticData_0[166],
	&SFAS97RD_GAAP::mCFStaticData_0[167],
	&SFAS97RD_GAAP::mCFStaticData_0[168],
	&SFAS97RD_GAAP::mCFStaticData_0[169],
	&SFAS97RD_GAAP::mCFStaticData_0[170],
	&SFAS97RD_GAAP::mCFStaticData_0[171],
	&SFAS97RD_GAAP::mCFStaticData_0[172],
	&SFAS97RD_GAAP::mCFStaticData_0[173],
	&SFAS97RD_GAAP::mCFStaticData_0[174],
	&SFAS97RD_GAAP::mCFStaticData_0[175],
	&SFAS97RD_GAAP::mCFStaticData_0[176],
	&SFAS97RD_GAAP::mCFStaticData_0[177],
	&SFAS97RD_GAAP::mCFStaticData_0[178],
	&SFAS97RD_GAAP::mCFStaticData_0[179],
	&SFAS97RD_GAAP::mCFStaticData_0[180],
	&SFAS97RD_GAAP::mCFStaticData_0[181],
	&SFAS97RD_GAAP::mCFStaticData_0[182],
	&SFAS97RD_GAAP::mCFStaticData_0[183],
	&SFAS97RD_GAAP::mCFStaticData_0[184],
	&SFAS97RD_GAAP::mCFStaticData_0[185],
	&SFAS97RD_GAAP::mCFStaticData_0[186],
	&SFAS97RD_GAAP::mCFStaticData_0[187],
	&SFAS97RD_GAAP::mCFStaticData_0[188],
	&SFAS97RD_GAAP::mCFStaticData_0[189],
	&SFAS97RD_GAAP::mCFStaticData_0[190],
	&SFAS97RD_GAAP::mCFStaticData_0[191],
	&SFAS97RD_GAAP::mCFStaticData_0[192],
	&SFAS97RD_GAAP::mCFStaticData_0[193],
	&SFAS97RD_GAAP::mCFStaticData_0[194],
	&SFAS97RD_GAAP::mCFStaticData_0[195],
	&SFAS97RD_GAAP::mCFStaticData_0[196],
	&SFAS97RD_GAAP::mCFStaticData_0[197],
	&SFAS97RD_GAAP::mCFStaticData_0[198],
	&SFAS97RD_GAAP::mCFStaticData_0[199],
	&SFAS97RD_GAAP::mCFStaticData_0[200],
	&SFAS97RD_GAAP::mCFStaticData_0[201],
	&SFAS97RD_GAAP::mCFStaticData_0[202],
	&SFAS97RD_GAAP::mCFStaticData_0[203],
	&SFAS97RD_GAAP::mCFStaticData_0[204],
	&SFAS97RD_GAAP::mCFStaticData_0[205],
	&SFAS97RD_GAAP::mCFStaticData_0[206],
	&SFAS97RD_GAAP::mCFStaticData_0[207],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for cohort_reins_defn                                                                                       
	const ChoicePair cohort_reins_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::GROSS, "Gross")
		,ChoicePair(StrEnum::CEDED, "Ceded")
	};
	const EnumList cohort_reins_defnEnumList(2, cohort_reins_defnChoicePairs);

	// EnumList for gmib_ceded_defn                                                                                       
	const ChoicePair gmib_ceded_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SOP031, "SOP031")
		,ChoicePair(StrEnum::SFAS133, "SFAS133")
	};
	const EnumList gmib_ceded_defnEnumList(2, gmib_ceded_defnChoicePairs);

	// EnumList for gmib_gross_defn                                                                                       
	const ChoicePair gmib_gross_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SOP031, "SOP031")
		,ChoicePair(StrEnum::SFAS133, "SFAS133")
	};
	const EnumList gmib_gross_defnEnumList(2, gmib_gross_defnChoicePairs);

	// EnumList for gmwb_ceded_defn                                                                                       
	const ChoicePair gmwb_ceded_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SOP031, "SOP031")
		,ChoicePair(StrEnum::SFAS133, "SFAS133")
	};
	const EnumList gmwb_ceded_defnEnumList(2, gmwb_ceded_defnChoicePairs);

	// EnumList for gmwb_gross_defn                                                                                       
	const ChoicePair gmwb_gross_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SOP031, "SOP031")
		,ChoicePair(StrEnum::SFAS133, "SFAS133")
	};
	const EnumList gmwb_gross_defnEnumList(2, gmwb_gross_defnChoicePairs);

	// EnumList for loss_recognition_defn                                                                                       
	const ChoicePair loss_recognition_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList loss_recognition_defnEnumList(2, loss_recognition_defnChoicePairs);

	// EnumList for sop031_ul_vul_iul_defn                                                                                       
	const ChoicePair sop031_ul_vul_iul_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList sop031_ul_vul_iul_defnEnumList(2, sop031_ul_vul_iul_defnChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace SFAS97RD_GAAP_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(SFAS97RD_GAAP::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(SFAS97RD_GAAP::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace SFAS97RD_GAAP_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void SFAS97RD_GAAP::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> SFAS97RD_GAAP::mgr_;

	Attribute::Descriptor SFAS97RD_GAAP::descriptor_0[] = {
	Descriptor(0, Attribute::INT,	"amortzn_mths", -1, (size_t)&modelOffset->amortzn_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::DOUBLE,	"cohort_gaap_int_rate_ceded", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_gaap_int_rate_ceded,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::DOUBLE,	"cohort_gaap_int_rate_gross", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_gaap_int_rate_gross,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::DOUBLE,	"cohort_history_agp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_agp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::DOUBLE,	"cohort_history_capzd_acq_exp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_capzd_acq_exp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::DOUBLE,	"cohort_history_capzd_comm_bom", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_capzd_comm_bom,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::DOUBLE,	"cohort_history_capzd_comm_eom", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_capzd_comm_eom,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::DOUBLE,	"cohort_history_capzd_prem_bonus", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_capzd_prem_bonus,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::DOUBLE,	"cohort_history_dac_acq_exp_loss", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_dac_acq_exp_loss,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::DOUBLE,	"cohort_history_dac_comm_loss", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_dac_comm_loss,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::DOUBLE,	"cohort_history_dac_prem_bonus_loss", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_dac_prem_bonus_loss,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::DOUBLE,	"cohort_history_deferred_load", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_deferred_load,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::DOUBLE,	"cohort_history_reins_yrt_cost", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_reins_yrt_cost,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::DOUBLE,	"cohort_history_sop031_assess", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_sop031_assess,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::DOUBLE,	"cohort_history_sop031_gmdb_benefits", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_sop031_gmdb_benefits,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::DOUBLE,	"cohort_history_sop031_gmib_benefits", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_sop031_gmib_benefits,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::DOUBLE,	"cohort_history_sop031_gmwb_benefits", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_sop031_gmwb_benefits,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::DOUBLE,	"cohort_history_sop031_pbr_benefits", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_sop031_pbr_benefits,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::DOUBLE,	"cohort_history_sop031_pbr_fund_val", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_sop031_pbr_fund_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::DOUBLE,	"cohort_history_sop031_sg_benefits", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_sop031_sg_benefits,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::DOUBLE,	"cohort_history_unearn_rev_liab", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_unearn_rev_liab,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::STRING,	"cohort_id", -1, (size_t)&modelOffset->cohort_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::STRING,	"cohort_issue_yrs", -1, (size_t)&modelOffset->cohort_issue_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(23, Attribute::DOUBLE,	"cohort_loss_recognition_int_rate_ceded", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_loss_recognition_int_rate_ceded,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::DOUBLE,	"cohort_loss_recognition_int_rate_gross", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_loss_recognition_int_rate_gross,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(25, Attribute::STRING,	"cohort_plan_codes", -1, (size_t)&modelOffset->cohort_plan_codes,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::STR_ENUM,	"cohort_reins_defn", -1, (size_t)&modelOffset->cohort_reins_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &cohort_reins_defnEnumList, Feature(true)),
	Descriptor(27, Attribute::INT,	"cohort_yr", -1, (size_t)&modelOffset->cohort_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(28, Attribute::INT,	"date_lookup_gen2", -1, (size_t)&modelOffset->date_lookup_gen2,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(29, Attribute::DOUBLE,	"fia_gaap_int_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fia_gaap_int_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(30, Attribute::STR_ENUM,	"gmib_ceded_defn", -1, (size_t)&modelOffset->gmib_ceded_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmib_ceded_defnEnumList, Feature(true)),
	Descriptor(31, Attribute::STR_ENUM,	"gmib_gross_defn", -1, (size_t)&modelOffset->gmib_gross_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmib_gross_defnEnumList, Feature(true)),
	Descriptor(32, Attribute::STR_ENUM,	"gmwb_ceded_defn", -1, (size_t)&modelOffset->gmwb_ceded_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_ceded_defnEnumList, Feature(true)),
	Descriptor(33, Attribute::STR_ENUM,	"gmwb_gross_defn", -1, (size_t)&modelOffset->gmwb_gross_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_gross_defnEnumList, Feature(true)),
	Descriptor(34, Attribute::STR_ENUM,	"loss_recognition_defn", -1, (size_t)&modelOffset->loss_recognition_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &loss_recognition_defnEnumList, Feature(true)),
	Descriptor(35, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(36, Attribute::STRING,	"seg_id", -1, (size_t)&modelOffset->seg_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(37, Attribute::STRING,	"sfas97rd_results", -1, (size_t)&modelOffset->sfas97rd_results,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(38, Attribute::STRING,	"sop031_results", -1, (size_t)&modelOffset->sop031_results,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(39, Attribute::STR_ENUM,	"sop031_ul_vul_iul_defn", -1, (size_t)&modelOffset->sop031_ul_vul_iul_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &sop031_ul_vul_iul_defnEnumList, Feature(true)),
	Descriptor(40, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(41, Attribute::SCALAR_INT,	"amortzn_period", -1, (size_t)&modelOffset->amortzn_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_amortzn_period)),
	Descriptor(42, Attribute::SCALAR_INT,	"comm_pct_fund_ult_index", -1, (size_t)&modelOffset->comm_pct_fund_ult_index,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_pct_fund_ult_index)),
	Descriptor(43, Attribute::SCALAR_INT,	"final_period", -1, (size_t)&modelOffset->final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_final_period)),
	Descriptor(44, Attribute::SCALAR_DOUBLE,	"gaap_int_rate", -1, (size_t)&modelOffset->gaap_int_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gaap_int_rate)),
	Descriptor(45, Attribute::SCALAR_DOUBLE,	"gaap_int_rate_mthly", -1, (size_t)&modelOffset->gaap_int_rate_mthly,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gaap_int_rate_mthly)),
	Descriptor(46, Attribute::SCALAR_INT,	"gmib_defn", -1, (size_t)&modelOffset->gmib_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmib_defn)),
	Descriptor(47, Attribute::SCALAR_INT,	"gmib_sop031_flag", -1, (size_t)&modelOffset->gmib_sop031_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmib_sop031_flag)),
	Descriptor(48, Attribute::SCALAR_INT,	"gmwb_defn", -1, (size_t)&modelOffset->gmwb_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmwb_defn)),
	Descriptor(49, Attribute::SCALAR_INT,	"gmwb_sop031_flag", -1, (size_t)&modelOffset->gmwb_sop031_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmwb_sop031_flag)),
	Descriptor(50, Attribute::SCALAR_DOUBLE,	"hedge_alloc_factor", -1, (size_t)&modelOffset->hedge_alloc_factor,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_alloc_factor)),
	Descriptor(51, Attribute::SCALAR_DOUBLE,	"host_accrual_rate", -1, (size_t)&modelOffset->host_accrual_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_host_accrual_rate)),
	Descriptor(52, Attribute::SCALAR_DOUBLE,	"loss_rec_int_rate", -1, (size_t)&modelOffset->loss_rec_int_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_loss_rec_int_rate)),
	Descriptor(53, Attribute::SCALAR_DOUBLE,	"loss_rec_int_rate_mthly", -1, (size_t)&modelOffset->loss_rec_int_rate_mthly,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_loss_rec_int_rate_mthly)),
	Descriptor(54, Attribute::SCALAR_INT,	"loss_recognition_flag", -1, (size_t)&modelOffset->loss_recognition_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_loss_recognition_flag)),
	Descriptor(55, Attribute::SCALAR_INT,	"pbr_final_period", -1, (size_t)&modelOffset->pbr_final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_pbr_final_period)),
	Descriptor(56, Attribute::SCALAR_INT,	"prem_term_period", -1, (size_t)&modelOffset->prem_term_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_prem_term_period)),
	Descriptor(57, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_proj_date_adj)),
	Descriptor(58, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_proj_start_date)),
	Descriptor(59, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_proj_start_mth)),
	Descriptor(60, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_proj_start_yr)),
	Descriptor(61, Attribute::SCALAR_INT,	"reins_flag", -1, (size_t)&modelOffset->reins_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_reins_flag)),
	Descriptor(62, Attribute::SCALAR_INT,	"sop031_flag", -1, (size_t)&modelOffset->sop031_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_flag)),
	Descriptor(63, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_start_period)),
	Descriptor(64, Attribute::SCALAR_STRING,	"state_of_world_financial_file_path", -1, (size_t)&modelOffset->state_of_world_financial_file_path,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_state_of_world_financial_file_path)),
	};

	Attribute::Descriptor* SFAS97RD_GAAP::descriptorTable[] = {
	&SFAS97RD_GAAP::descriptor_0[0],
	&SFAS97RD_GAAP::descriptor_0[1],
	&SFAS97RD_GAAP::descriptor_0[2],
	&SFAS97RD_GAAP::descriptor_0[3],
	&SFAS97RD_GAAP::descriptor_0[4],
	&SFAS97RD_GAAP::descriptor_0[5],
	&SFAS97RD_GAAP::descriptor_0[6],
	&SFAS97RD_GAAP::descriptor_0[7],
	&SFAS97RD_GAAP::descriptor_0[8],
	&SFAS97RD_GAAP::descriptor_0[9],
	&SFAS97RD_GAAP::descriptor_0[10],
	&SFAS97RD_GAAP::descriptor_0[11],
	&SFAS97RD_GAAP::descriptor_0[12],
	&SFAS97RD_GAAP::descriptor_0[13],
	&SFAS97RD_GAAP::descriptor_0[14],
	&SFAS97RD_GAAP::descriptor_0[15],
	&SFAS97RD_GAAP::descriptor_0[16],
	&SFAS97RD_GAAP::descriptor_0[17],
	&SFAS97RD_GAAP::descriptor_0[18],
	&SFAS97RD_GAAP::descriptor_0[19],
	&SFAS97RD_GAAP::descriptor_0[20],
	&SFAS97RD_GAAP::descriptor_0[21],
	&SFAS97RD_GAAP::descriptor_0[22],
	&SFAS97RD_GAAP::descriptor_0[23],
	&SFAS97RD_GAAP::descriptor_0[24],
	&SFAS97RD_GAAP::descriptor_0[25],
	&SFAS97RD_GAAP::descriptor_0[26],
	&SFAS97RD_GAAP::descriptor_0[27],
	&SFAS97RD_GAAP::descriptor_0[28],
	&SFAS97RD_GAAP::descriptor_0[29],
	&SFAS97RD_GAAP::descriptor_0[30],
	&SFAS97RD_GAAP::descriptor_0[31],
	&SFAS97RD_GAAP::descriptor_0[32],
	&SFAS97RD_GAAP::descriptor_0[33],
	&SFAS97RD_GAAP::descriptor_0[34],
	&SFAS97RD_GAAP::descriptor_0[35],
	&SFAS97RD_GAAP::descriptor_0[36],
	&SFAS97RD_GAAP::descriptor_0[37],
	&SFAS97RD_GAAP::descriptor_0[38],
	&SFAS97RD_GAAP::descriptor_0[39],
	&SFAS97RD_GAAP::descriptor_0[40],
	&SFAS97RD_GAAP::descriptor_0[41],
	&SFAS97RD_GAAP::descriptor_0[42],
	&SFAS97RD_GAAP::descriptor_0[43],
	&SFAS97RD_GAAP::descriptor_0[44],
	&SFAS97RD_GAAP::descriptor_0[45],
	&SFAS97RD_GAAP::descriptor_0[46],
	&SFAS97RD_GAAP::descriptor_0[47],
	&SFAS97RD_GAAP::descriptor_0[48],
	&SFAS97RD_GAAP::descriptor_0[49],
	&SFAS97RD_GAAP::descriptor_0[50],
	&SFAS97RD_GAAP::descriptor_0[51],
	&SFAS97RD_GAAP::descriptor_0[52],
	&SFAS97RD_GAAP::descriptor_0[53],
	&SFAS97RD_GAAP::descriptor_0[54],
	&SFAS97RD_GAAP::descriptor_0[55],
	&SFAS97RD_GAAP::descriptor_0[56],
	&SFAS97RD_GAAP::descriptor_0[57],
	&SFAS97RD_GAAP::descriptor_0[58],
	&SFAS97RD_GAAP::descriptor_0[59],
	&SFAS97RD_GAAP::descriptor_0[60],
	&SFAS97RD_GAAP::descriptor_0[61],
	&SFAS97RD_GAAP::descriptor_0[62],
	&SFAS97RD_GAAP::descriptor_0[63],
	&SFAS97RD_GAAP::descriptor_0[64],
	nullptr};
	const size_t SFAS97RD_GAAP::sDescriptorCount = 65;

//factory
SFAS97RD_GAAP* SFAS97RD_GAAP::makeThis(int isSubmodel, ModelClass* owner, SFAS97RD_GAAP* peer, 
						int mainRebase, const xstring &name, SFAS97RD_GAAP_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("SFAS97RD_GAAP::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor SFAS97RD_GAAP");
#endif
	SFAS97RD_GAAP* newP = (SFAS97RD_GAAP*)new SFAS97RD_GAAP_UDF
   	  ("sfas97rd_gaap", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
SFAS97RD_GAAP_persistent_object* SFAS97RD_GAAP_persistent_object::makeThis(int isSubmodel, ModelClass* owner, SFAS97RD_GAAP* peer, 
							int mainRebase, const xstring &name, SFAS97RD_GAAP_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("SFAS97RD_GAAP_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor SFAS97RD_GAAP_persistent_object");
#endif
	SFAS97RD_GAAP_persistent_object* newP = (SFAS97RD_GAAP_persistent_object*)new SFAS97RD_GAAP_persistent_object
   	  ("sfas97rd_gaap", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			SFAS97RD_GAAP_persistent_object* pd = dynamic_cast<SFAS97RD_GAAP_persistent_object*>(product);
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

typedef double (SFAS97RD_GAAP_UDF::*dPF) ();
typedef double (SFAS97RD_GAAP_UDF::*dPFd) (double);
typedef int (SFAS97RD_GAAP_UDF::*iPF) ();
typedef int (SFAS97RD_GAAP_UDF::*iPFi) (int);
typedef xstring (SFAS97RD_GAAP_UDF::*sPF) ();
typedef xstring (SFAS97RD_GAAP_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
SFAS97RD_GAAP::SFAS97RD_GAAP(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, fia(company_liab_fia)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_bond_portfolio_aig(company_liab_fia_fia_bond_portfolio_aig)
	, fia_rates(company_liab_fia_fia_rates)
	, fia_sfas97rd(company_liab_fia_fia_sfas97rd)
	, liab(company_liab)
	, rates(company_rates)
	, seg(company_seg)
	, sfas97rd(company_seg_sfas97rd)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	RegisterTerminatorOnce();
	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (SFAS97RD_GAAP_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
SFAS97RD_GAAP::SFAS97RD_GAAP(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(207, SFAS97RD_GAAP::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, fia(company_liab_fia)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_bond_portfolio_aig(company_liab_fia_fia_bond_portfolio_aig)
	, fia_rates(company_liab_fia_fia_rates)
	, fia_sfas97rd(company_liab_fia_fia_sfas97rd)
	, liab(company_liab)
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
#ifdef __CREATE_LIAB_LIAB_CLASS_
       company_liab = 0;
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
       company_liab_fia = 0;
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
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
       company_liab_fia_fia_sfas97rd = 0;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
       company_rates = 0;
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
       company_seg = 0;
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

	for (int cf_no = 1; cf_no <= 207; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (SFAS97RD_GAAP_UDF::*dPXi2) (int, int);
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


 void SFAS97RD_GAAP::copy_names() {

#ifdef __CREATE_COMP_COMP_CLASS_
		company = (COMP_COMP*)(findUnique("company"));
#endif
#ifdef __CREATE_LIAB_LIAB_CLASS_
		company_liab = (LIAB_LIAB*)(findUnique("company|liab"));
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
		company_liab_fia = (FIA_LIAB*)(findUnique("company|liab|fia"));
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
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
		company_liab_fia_fia_sfas97rd = (SFAS97RD_GAAP*)(findUnique("company|liab|fia|fia_sfas97rd"));
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_rates = (RATES_ECONOMY*)(findUnique("company|rates"));
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
		company_seg = (SEG_COMP*)(findUnique("company|seg"));
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
		company_seg_sfas97rd = (SFAS97RD_GAAP*)(findUnique("company|seg|sfas97rd"));
#endif
 }
//copy_names END@2


 void SFAS97RD_GAAP::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int SFAS97RD_GAAP_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& SFAS97RD_GAAP_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double SFAS97RD_GAAP_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int SFAS97RD_GAAP_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double SFAS97RD_GAAP_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double SFAS97RD_GAAP_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void SFAS97RD_GAAP_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void SFAS97RD_GAAP_persistent_object::write(long include_submodels) {
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

	void SFAS97RD_GAAP_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void SFAS97RD_GAAP_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void SFAS97RD_GAAP_persistent_object::write(const xstring& key, long include_submodels) {
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




	SFAS97RD_GAAP_persistent_object::~SFAS97RD_GAAP_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool SFAS97RD_GAAP_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void SFAS97RD_GAAP_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void SFAS97RD_GAAP_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void SFAS97RD_GAAP_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void SFAS97RD_GAAP_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void SFAS97RD_GAAP_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* SFAS97RD_GAAP_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* SFAS97RD_GAAP_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* SFAS97RD_GAAP_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char SFAS97RD_GAAP_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void SFAS97RD_GAAP_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
SFAS97RD_GAAP_persistent_object::SFAS97RD_GAAP_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			SFAS97RD_GAAP(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(SFAS97RD_GAAP::sm_bond_is)
	, sm_bond_pv(SFAS97RD_GAAP::sm_bond_pv)
	, sm_bond_ym(SFAS97RD_GAAP::sm_bond_ym)
	, sm_mtg_is(SFAS97RD_GAAP::sm_mtg_is)
	, sm_mtg_pv(SFAS97RD_GAAP::sm_mtg_pv)
	, sm_mtg_ym(SFAS97RD_GAAP::sm_mtg_ym)

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
SFAS97RD_GAAP::~SFAS97RD_GAAP() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void SFAS97RD_GAAP::findTargetColumns() {

}
//findTargetColumns END@2
void SFAS97RD_GAAP::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void SFAS97RD_GAAP::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void SFAS97RD_GAAP::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void SFAS97RD_GAAP::start_of_projection() {
}
//start_of_projection END@2

void SFAS97RD_GAAP::end_of_projection() {
}
//end_of_projection END@2

void SFAS97RD_GAAP::start_of_layer() {
}


void SFAS97RD_GAAP::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void SFAS97RD_GAAP::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void SFAS97RD_GAAP::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void SFAS97RD_GAAP::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> SFAS97RD_GAAP::ddfVector;
BitArray SFAS97RD_GAAP::dataVariables(65);
bool SFAS97RD_GAAP::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool SFAS97RD_GAAP::writeClassInfo = true;

void SFAS97RD_GAAP::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, SFAS97RD_GAAP::descriptor_0>::dT = SFAS97RD_GAAP::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, SFAS97RD_GAAP::descriptor_0>::dT = SFAS97RD_GAAP::descriptor_0;

