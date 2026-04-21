
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
#include "ModelClass\mtg_cf_asset_udf.h"
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

extern int PVCounter;
extern ofstream& PVCFile;
extern ostringstream PVCText;
extern int PVCLen;
extern int PVCSigDig;
extern xstring PVC_FilNam;
extern SmartArray <double>& spot_rate_tbl;
extern SmartArray <double>& shifted_spot_rate_tbl;
extern bool is_asset_initialize;

// present value calculation variables
#define YM_UPDATE 0 // 1 for log_screen output, 0 for no output
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

#if defined(__INTEX_ASSET_H_)
extern bool intex_detail_wanted;
#endif

#include <sstream> // for ostringstream

// This macro evaluates the number of decimals in the 'xxx' value that corresponds
// to 'sig_digits' significant digits. This macro is used to set solving_flag tolerance
// factors. For example, NUMBER_OF_DECIMALS(50000,11) evaluates to 6.
#define NUMBER_OF_DECIMALS(xxx,sig_digits) (fabs(xxx) < 0.000000001 ? (sig_digits-1) : (min((sig_digits-1), (int)((sig_digits) - log10(fabs(xxx))))))
#define SIGNIFICANT_DIGITS 11

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
#ifndef mtg_cf_asset_TableDefs
#define mtg_cf_asset_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection MTG_CF_ASSET::TTHC;
void MTG_CF_ASSET::removeSMPointers(ModelClass* modelToRemove){

	if(modelToRemove == sm_mtg_is)
		sm_mtg_is = 0;

	if(modelToRemove == sm_mtg_pv)
		sm_mtg_pv = 0;

	if(modelToRemove == sm_mtg_ym)
		sm_mtg_ym = 0;

}		

//@@ START - accr_int
// Accrued Interest                                                                                             
// Column:ACCR_INT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_accr_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"accr_int",t);
}



//^^^

#line 1 "accr_int.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t >= mtg->maturity_period)
	return NO_AVG;

if (pv_defn != CASH_FLOWS)
	return accr_int_bef_sale(t);

return accr_int_bef_sale(t)
       * (1.0 - mtg->sold_pct(t));

}


//@@ END

//@@ START - accr_int_aft_dflt
// Accrued Interest After Defaults                                                                                             
// Column:ACCR_INT_AFT_DFLT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_accr_int_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"accr_int_aft_dflt",t);
}



//^^^

#line 1 "accr_int_aft_dflt.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (intex_proj_flag)
	return (accr_int(t - 1)
			+ mtg->intex_accr_int_adj(t - 1))
		   * remaining_pct_aft_dflt(t);

if (this == mtg_cf)
	return accr_int(t - 1)
		   * remaining_pct_aft_dflt(t);

if (t == rebase_period + 1)
	{
	if (pv_timing == END_OF_MONTH)
		return accr_int_bef_sale(t - 1);

	if (pv_timing == BEFORE_PREPAYMENTS)
		{
		if (t == mtg->commencement_period + 1)
			return accr_int_bef_sale(t - 1)
				   * remaining_pct_aft_dflt(t);

		if (mtg->mths_to_next_pmt(t - 2) == 1)
			return 0;

		return accr_int_bef_prepmt(t - 1);
		}

	if (pv_timing == AFTER_PREPAYMENTS)
		{
		if (mtg->mths_to_next_pmt(t - 2) == 1)
			return 0;

		return accr_int_aft_prepmt(t - 1);
		}
	}

return accr_int(t - 1);

}


//@@ END

//@@ START - accr_int_aft_prepmt
// Accrued Interest After Prepayments                                                                                             
// Column:ACCR_INT_AFT_PREPMT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_accr_int_aft_prepmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(3,"accr_int_aft_prepmt",t);
}



//^^^

#line 1 "accr_int_aft_prepmt.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (intex_proj_flag)
	return accr_int_bef_prepmt(t);

if (t == 0 && mtg->existing_asset_indicator)
	return par_val_bef_sale(t)
		   * (pow(1.0 + pmt_rate(t) / mtg->pmt_freq,
				  (mtg->yrs_since_last_pmt)
				  * mtg->pmt_freq) - 1.0);

if (mtg->pmt_mode == MONTHLY
	|| mtg->mths_to_next_pmt(t - 1) == 1)
	return NO_AVG;

if (prepmt_appl == NO)
	return accr_int_bef_prepmt(t);

return accr_int_bef_prepmt(t)
	   * (1.0 - prepmt_pct_mthly(t));

}


//@@ END

//@@ START - accr_int_bef_prepmt
// Accrued Interest Before Prepayments                                                                                             
// Column:ACCR_INT_BEF_PREPMT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_accr_int_bef_prepmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(4,"accr_int_bef_prepmt",t);
}



//^^^

#line 1 "accr_int_bef_prepmt.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

#if defined( __INTEX_ASSET_H_)
if (intex_proj_flag)
	{
	if (intex)
		{
		if (intex_pmt_processed(t))
			{
			if (fabs(par_val_aft_sched_pmt(t))
				< model_point_amount_threshold)
				return NO_AVG;	
	
			return max(intex->get_tranche_accr_int_bef_prepmt(t)
					   * tranche_portion_aft_dflt(t)
					   - int_pmt(t), 0.0);
			}
		}
	}
#endif

if (mtg->pmt_mode == MONTHLY
	|| mtg->mths_to_next_pmt(t - 1) == 1)
	return NO_AVG;

double par_val_aft_sched_pmt = this->par_val_aft_sched_pmt(t);

if (par_val_aft_sched_pmt <= 0.0)
	return NO_AVG;

if (mtg->existing_asset_indicator)
	return accr_int_direct(t, par_val_aft_sched_pmt, pmt_rate(t - 1));

return accr_int_direct(t, par_val_aft_sched_pmt,
						  pmt_rate(t - 1) 
						  * since_foreclosure_prin_pmt_mult(t)
						  * since_restructure_prin_pmt_mult(t));

}


//@@ END

//@@ START - accr_int_bef_sale
// Accrued Interest Before Sales                                                                                             
// Column:ACCR_INT_BEF_SALE
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_accr_int_bef_sale(int t) {
//^^^



//^^^

#line 1 "accr_int_bef_sale.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t >= mtg->maturity_period)
	return NO_AVG;

#if defined(__INTEX_ASSET_H_)
if (intex_proj_flag)
	{
	if (intex)
		{
		if (intex_pmt_processed(t))
			{
			if (fabs(par_val_bef_sale(t)) < model_point_amount_threshold)
				return NO_AVG;
	
			return intex->get_tranche_accr_int(t)
				   * tranche_portion_bef_sale(t);
			}
		}
	}
#endif

if (t == 0 && mtg->existing_asset_indicator)
	return par_val_bef_sale(t)
		   * (pow(1.0 + pmt_rate(t) / mtg->pmt_freq,
				  mtg->yrs_since_last_pmt * mtg->pmt_freq) - 1);

if (t == mtg->commencement_period && !mtg->existing_asset_indicator)
	return mtg->accr_int_per_par_unit
		   * par_val_bef_sale(t);

if (mtg->pmt_mode == MONTHLY
	|| mtg->mths_to_next_pmt(t - 1) == 1)
	return NO_AVG;

double accr_int_aft_prepmt = 0;

if (dflt_appl == NO)
	{
	if (this != mtg_cf
		&& t > rebase_period + 1)
		accr_int_aft_prepmt = this->accr_int_aft_prepmt(t);
	else
		accr_int_aft_prepmt = this->accr_int_aft_prepmt(t);
	}
else
	accr_int_aft_prepmt = this->accr_int_aft_prepmt(t);

return accr_int_aft_prepmt;

}


//@@ END

//@@ START - adco_prepmt_forecast
// ADCo Prepayment Forecast                                                                                             
// Column:ADCO_PREPMT_FORECAST
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_adco_prepmt_forecast(int t) {
//^^^



//^^^

#line 1 "adco_prepmt_forecast.MTG_CF_ASSET.for"
if (!mtg->use_andrew_davidson)
	return NO_AVG;

if (intex_proj_flag)
	return NO_AVG;

if (prepmt_appl == NO)
	return NO_AVG;

if (mtg->prepmt_model_defn == SPLINE)
	return NO_AVG;

if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if ((t == 0 && mtg->existing_asset_indicator)
	|| (t == mtg->commencement_period && !mtg->existing_asset_indicator)
	|| (pv_defn != CASH_FLOWS && t == rebase_period))
	{
	setup_adco_submodel_parameters(t);

	return 1;
	}

return adco_prepmt_forecast(t - 1);

}


//@@ END

//@@ START - balloon_pmt
// Balloon Payment                                                                                             
// Column:BALLOON_PMT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_balloon_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(7,"balloon_pmt",t);
}



//^^^

#line 1 "balloon_pmt.MTG_CF_ASSET.for"
if (mtg->balloon_pmt_flag == NO)
	return NO_AVG;

if (mtg->balloon_defn == YES_ON_SINGLE_PERIOD 
	&& t != mtg->balloon_pmt_period)
	return NO_AVG;

if (mtg->balloon_defn == YES_PER_SCHEDULE)
	{
	if (mtg->balloon_sch_base(t - 1) < rate_ratio_threshold)
		return NO_AVG;

	if (mtg->balloon_sch[t - mtg->start_period] < rate_ratio_threshold)
		return 0.0;
	}

// beg - forced calls to reduced sliding windows sizes
double local_par_val_for_balloon_pmt_aft_dflt_bom
= par_val_for_balloon_pmt_aft_dflt(t);
// end forced calls to reduced sliding windows sizes

double local_par_val_aft_dflt_bom = 0;

if (this == mtg_cf || t <= rebase_period + 1)
	{
	local_par_val_aft_dflt_bom = par_val_aft_dflt(t);

	double base_mortgage_interest_payment = 0;
	double local_par_val_aft_pmt = 0;

	if (mtg->pmt_mode == MONTHLY
		|| mtg->mths_to_next_pmt(t - 1) == 1)
		{
		base_mortgage_interest_payment
		= local_par_val_aft_dflt_bom
		  * (pmt_rate(t - 1) + mtg->servicing_fee)
		  / mtg->pmt_freq;

		local_par_val_aft_pmt
		= local_par_val_aft_dflt_bom
		  - (pmt_amt_aft_dflt(t)
			 - base_mortgage_interest_payment);
		}
	else
		local_par_val_aft_pmt = local_par_val_aft_dflt_bom;

	if (mtg->balloon_defn == YES_PER_SCHEDULE)
		{
		double pmt_pct = 0.0;
		double pmt_amt = 0.0;

		pmt_pct = min(1.0, mtg->balloon_sch[t - mtg->start_period]
						   / mtg->balloon_sch_base(t - 1));

		pmt_amt = local_par_val_for_balloon_pmt_aft_dflt_bom * pmt_pct;

		return min(pmt_amt, local_par_val_aft_pmt);
		}

	//else balloon_defn == YES_ON_SINGLE_PERIOD
	return min(local_par_val_for_balloon_pmt_aft_dflt_bom,
				local_par_val_aft_pmt);
	}

if (prepmt_appl == NO)
	local_par_val_aft_dflt_bom = par_val_aft_sched_pmt(t - 1);
else
	local_par_val_aft_dflt_bom = par_val_aft_prepmt(t - 1);

double base_mortgage_interest_payment
= local_par_val_aft_dflt_bom
  * (pmt_rate(t - 1) + mtg->servicing_fee)
  / mtg->pmt_freq;

double local_par_val_aft_pmt = 0;

if (mtg->pmt_mode == MONTHLY
	|| mtg->mths_to_next_pmt(t - 1) == 1)
	{
	if (prepmt_appl == NO)
		local_par_val_aft_pmt
		= local_par_val_aft_dflt_bom
		  - (pmt_amt_aft_sched_payment(t - 1)
			 - base_mortgage_interest_payment);
	else
		local_par_val_aft_pmt
		= local_par_val_aft_dflt_bom
		  - (pmt_amt_aft_sched_payment(t - 1) * (1 - prepmt_pct_mthly(t - 1))
			 - base_mortgage_interest_payment);
	}
else
	local_par_val_aft_pmt = local_par_val_aft_dflt_bom;

if (mtg->balloon_defn == YES_PER_SCHEDULE)
	{
	double pmt_pct = 0.0;
	double pmt_amt = 0.0;

	pmt_pct = min(1.0, mtg->balloon_sch[t - mtg->start_period]
						/ mtg->balloon_sch_base(t - 1));

	pmt_amt = local_par_val_for_balloon_pmt_aft_dflt_bom * pmt_pct;

	return min(pmt_amt, local_par_val_aft_pmt);
	}

//else balloon_defn == YES_ON_SINGLE_PERIOD
return min(local_par_val_for_balloon_pmt_aft_dflt_bom,
		   local_par_val_aft_pmt);

}


//@@ END

//@@ START - balloon_pmt_inc
// Balloon Payment Income                                                                                             
// Column:BALLOON_PMT_INC
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_balloon_pmt_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(8,"balloon_pmt_inc",t);
}



//^^^

#line 1 "balloon_pmt_inc.MTG_CF_ASSET.for"
if (mtg->balloon_pmt_flag == NO)
	return NO_AVG;

if (mtg->balloon_defn == YES_ON_SINGLE_PERIOD && t < mtg->balloon_pmt_period)
	return NO_AVG;

if (mtg->balloon_defn == YES_PER_SCHEDULE)
	{
	if (mtg->balloon_sch_base(t - 1) < rate_ratio_threshold)
		return NO_AVG;

	if (mtg->balloon_sch[t - mtg->start_period] < rate_ratio_threshold)
		return 0.0;
	}

if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (mtg->pmt_mode == MONTHLY
	|| mtg->mths_to_next_pmt(t - 1) == 1)
	return NO_AVG;

double local_balloon_pmt = balloon_pmt(t);

if (local_balloon_pmt == 0.0)
	return NO_AVG;

return accr_int_direct(t, local_balloon_pmt, pmt_rate(t - 1));

}


//@@ END

//@@ START - int_pmt
// Interest Payment                                                                                             
// Column:INT_PMT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_int_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(9,"int_pmt",t);
}



//^^^

#line 1 "int_pmt.MTG_CF_ASSET.for"

if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

#if defined(__INTEX_ASSET_H_)
if (intex_proj_flag)
	{
	if (intex)
		{
		if (intex_pmt_processed(t))
			return intex->get_tranche_int_pmt(t)
		           * tranche_portion_aft_dflt(t);
		}
	}
#endif

if (mtg->pmt_mode != MONTHLY
	&& mtg->mths_to_next_pmt(t - 1) > 1)
	return NO_AVG;

double local_par_val_aft_dflt_bom = 0;
double base_interest_payment = 0;

if (this == mtg_cf
	|| t <= rebase_period + 1)
	local_par_val_aft_dflt_bom = par_val_aft_dflt(t);
else
	local_par_val_aft_dflt_bom = par_val_aft_prepmt(t - 1);

if (this == mtg_is)
	base_interest_payment
	= local_par_val_aft_dflt_bom
	  * (pmt_rate(t - 1) + mtg->servicing_fee)
	  / mtg->pmt_freq;	
else
	base_interest_payment
	= local_par_val_aft_dflt_bom
	  * pmt_rate(t - 1)
	  / mtg->pmt_freq;

if (mtg->purch_defn == FORECLOSURE)
	return base_interest_payment
		   * since_foreclosure_int_mult(t);

if (mtg->purch_defn == RESTRUCTURE)
	return base_interest_payment
		   * since_restructure_int_mult(t);

return base_interest_payment;

}


//@@ END

//@@ START - int_savings_pv_aft_prepmt
// Interest Savings Present Value After Prepayments                                                                                             
// Column:INT_SAVINGS_PV_AFT_PREPMT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_int_savings_pv_aft_prepmt(int t) {
//^^^



//^^^

#line 1 "int_savings_pv_aft_prepmt.MTG_CF_ASSET.for"
if (this == mtg_cf)
	return NO_AVG;

if (mtg->prepmt_first_period >= mtg->maturity_period - 1)
	return NO_AVG;

if (intex_proj_flag)
	return mtg_cf->int_savings_pv_bef_prepmt(t);

int valuation_period = max(rebase_period, mtg->commencement_period);

if (pv_defn == MARKET_VALUE
	|| pv_defn == MARKET_VALUE_SHIFTED)
	{
	if (prepmt_appl == NO)
		return NO_AVG;

	if (t > valuation_period)
		{
		if (pv_tbl_defn == USE_TABLES)
			return pv_interest_savings_after_prepayments[t - valuation_period];

		return mtg_pv->int_savings_pv_bef_prepmt(t)
			   * (1.0 - prepmt_pct_mthly(t));
		}

	if (t == valuation_period)
		{
		if (pv_defn == MARKET_VALUE_SHIFTED)
			return pv_int_savings_pv_for_mkt_val_calc;

		if (mtg->use_eom_scen_rates == YES
			&& t > mtg->commencement_period)
			{
			if (pv_tbl_defn == USE_TABLES)
				return pv_interest_savings_after_prepayments[0];
	
			return mtg_cf->int_savings_pv_bef_prepmt(t)
				   * (1.0 - prepmt_pct_mthly(t));
			}
		}
	}

else if (pv_defn == NET_YIELD
	&& t > valuation_period)
	{
	if (prepmt_appl == NO)
		return NO_AVG;

	if (pv_tbl_defn == USE_TABLES)
		return pv_interest_savings_after_prepayments[t - valuation_period];

	return mtg_pv->int_savings_pv_bef_prepmt(t)
		   * (1.0 - prepmt_pct_mthly(t));
	}

if (t == valuation_period)
	{
	int scenario_month = 0;
	double ispv = 0;
	double temp1 = 0;
	double temp2 = 0;
	double discount_rate = 0;

   	if (mtg->asset_detail_pv_flag(t))
		{
		PVCounter++;
		PVCText << PVCounter
				<< "-->Begin Interest Savings Present Value After Prepayments"
				<< " for " << mtg->asset_id
				<< " (" << mtg->pmt_rate_defn_string << ")"
				<< " t=" << t
				<< " CalYr=" << xint(mtg->cal_yr(t)) 
				<< " CalMth=" << xint(mtg->cal_mth(t));
		mtg->asset_detail_pv_output();
		}

	mtg->rebase_cash_flow(t,
				INTEREST_SAVINGS,
				"mtg_cf->int_savings_pv_aft_prepmt",
				modelName);

	if (pv_timing == END_OF_MONTH
		|| mtg->use_eom_scen_rates == YES)
		scenario_month = xint(mtg->cal_mth(t));
	else
		scenario_month = xint(mtg->cal_mth(t)) - 1;

	discount_rate
	= mtg->category_refinancing_rate(t,
				xint(mtg->cal_yr_relative(t)),
				scenario_month,
				mtg->maturity_period - t,
				NOMINAL_SEMIANNUAL,
				shift_defn,
				0);

	// save current pv parameters
	pv_calc_parameters(t, SAVE);

	if ((mtg_pv->pv_defn == MARKET_VALUE
		 || mtg_pv->pv_defn == MARKET_VALUE_SHIFTED)
		&& mtg->mkt_val_defn == TO_NEXT_RATE_RESET)
		mtg_is->pv_calc_parameters(t,
					INTEREST_SAVINGS_AFTER_PREPAYMENTS,
					mtg->mths_to_next_reset(t));
	else // TO_MATURITY
		mtg_is->pv_calc_parameters(t,
					INTEREST_SAVINGS_AFTER_PREPAYMENTS,
					xint(mtg->maturity_period - t));

	ispv
	= mtg_is->pv_calc(t,
				discount_rate,
				temp1, // calculated_derivative
				temp2  // calculated_modified_duration
				);

	// restore pv parameters
	pv_calc_parameters(t, RESTORE);

	if (mtg->asset_detail_pv_flag(t))
		{
		PVCText << PVCounter
				<< "<--End Interest Savings Present Value After Prepayments ("
				<< write_string(ispv,PVCLen,PVCSigDig)
				<< ") for " << mtg->asset_id
				<< " (" << mtg->pmt_rate_defn_string << ")"
				<< " t=" << t
				<< " CalYr=" << xint(mtg->cal_yr(t)) 
				<< " CalMth=" << xint(mtg->cal_mth(t));
		mtg->asset_detail_pv_output();
		PVCounter--;
		}

	return ispv;
	}

return NO_AVG;

}


//@@ END

//@@ START - int_savings_pv_bef_prepmt
// Interest Savings Present Value Before Prepayments                                                                                             
// Column:INT_SAVINGS_PV_BEF_PREPMT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_int_savings_pv_bef_prepmt(int t) {
//^^^



//^^^

#line 1 "int_savings_pv_bef_prepmt.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t >= mtg->maturity_period)
	return NO_AVG;

if (intex_proj_flag)
	return NO_AVG;

double ispv = 0;

if (pv_defn != CASH_FLOWS)
	{
	int valuation_period = max(rebase_period, mtg->commencement_period);

	if (t > valuation_period)
		{
		if (t == valuation_period + 1
			&& pv_defn != MARKET_VALUE_SHIFTED)
			{
			pv_interest_savings_monthly_refinancing_rate
			= convert_rate_basis(refinancing_rate(valuation_period),
						NOMINAL_SEMIANNUAL,
						12) / 12.0;
			}

		if (mtg->pmt_mode == MONTHLY)
			{
			ispv = int_savings_pv_aft_prepmt(t - 1);

			return ispv * (1.0 + pv_interest_savings_monthly_refinancing_rate)
				   - sched_prin_pmt(t)
				   - int_pmt(t);
			}

		ispv = int_savings_pv_aft_prepmt(t - 1)
			   + accr_int_aft_prepmt(t - 1);

		return ispv * (1.0 + pv_interest_savings_monthly_refinancing_rate)
			   - sched_prin_pmt(t)
			   - int_pmt(t)
			   - accr_int_bef_prepmt(t);
		}
	}

int scenario_month = 0;
double temp1 = 0;
double temp2 = 0;
double discount_rate = 0;

if (mtg->asset_detail_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Interest Savings Present Value Before Prepayments"
			<< " for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(mtg->cal_yr(t)) 
			<< " CalMth=" << xint(mtg->cal_mth(t));
	mtg->asset_detail_pv_output();
	}

mtg->rebase_cash_flow(t,
		INTEREST_SAVINGS,
		"mtg_cf->int_savings_pv_bef_prepmt",
		modelName);

if (pv_timing == END_OF_MONTH
	|| mtg->use_eom_scen_rates == YES)
	scenario_month = xint(mtg->cal_mth(t));
else
	scenario_month = xint(mtg->cal_mth(t)) - 1;

discount_rate
= mtg->category_refinancing_rate(t,
			xint(mtg->cal_yr_relative(t)),
			scenario_month,
			mtg->maturity_period - t,
			NOMINAL_SEMIANNUAL,
			shift_defn,
			0);

// set global values for temporary tables
pv_calc_parameters(t, SAVE);
mtg_is->pv_calc_parameters(t,
			INTEREST_SAVINGS_BEFORE_PREPAYMENTS,
			xint(mtg->maturity_period - t));

ispv = mtg_is->pv_calc(t,
			discount_rate,
			temp1, // calculated_derivative
			temp2  // calculated_modified_duration
			);

// reset global values for temporary tables
pv_calc_parameters(t, RESTORE);

if (mtg->asset_detail_pv_flag(t))
	{
	PVCText << PVCounter
			<< "<--End Interest Savings Present Value Before Prepayments ("
			<< write_string(ispv,PVCLen,PVCSigDig)
			<< ") for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(mtg->cal_yr(t)) 
			<< " CalMth=" << xint(mtg->cal_mth(t));
	mtg->asset_detail_pv_output();
	PVCounter--;
	}

return ispv;

}


//@@ END

//@@ START - intex_pmt_processed
// Intex Payment Processed                                                                                             
// Column:INTEX_PMT_PROCESSED
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_intex_pmt_processed(int t) {
//^^^



//^^^

#line 1 "intex_pmt_processed.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (!intex_proj_flag)
	return NO_AVG;

#if defined(__INTEX_ASSET_H_)
if (!intex)
	return 0;

if (t == 0)
	// check: initialize only once to prevent problems with balloon extensions
	{
	static xstring prior_asset_id = "";
	static int prior_t = -999;
	static int prior_iter = -999;
	static StrEnum::EnumValue prior_pv_defn = UNDEFINED;

	if (mtg->asset_id != prior_asset_id
		|| proj_task_loop_num != prior_iter)
		{
		prior_asset_id = mtg->asset_id;
		prior_t = -999;
		prior_iter = -999;
		prior_pv_defn = UNDEFINED;
		}

	if (t == prior_t
		&& pv_defn == prior_pv_defn)
		return 1;

	if (pv_defn == MARKET_VALUE_SHIFTED)
		{
		if (prior_pv_defn != MARKET_VALUE) 
			throw FatalError("Trying to do a market value shifted calculation "
							 "for Intex mortgage " + xstring(mtg->asset_id) + " "
							 + "when market value initializations are not current.");

		return 1;
		}

	prior_t = t;
	prior_iter = proj_task_loop_num;
	prior_pv_defn = pv_defn;
	}

if (pv_defn == CASH_FLOWS)
	{
	// Just need to project the ISPV cash flows at time = 0
	if (t == 0)
		intex->int_savings_pv_cash_flow_setup(t);

	if (t > 0)
		{
		// Reset and parameterize the intex submodel
		intex->resetValues();
		intex->shift_defn = shift_defn;

		intex->proj_defn = EXPERIENCE;
	
		intex->cash_flow_proj(t);
		}

	return 1;
	}	

if (pv_defn == NET_YIELD
	&& t == rebase_period)
	{
	// ensure mtg_cf intex cash flows have been run
	mtg_cf->intex_pmt_processed(t);
	
	// Reset and parameterize the intex submodel
	intex->resetValues();
	intex->shift_defn = shift_defn;

	intex->proj_defn = NET_YIELD;

	intex->net_yld_cash_flow_proj(t);

	// check that the mtg->t_high is large enough to project the Intex asset
	// memory requirements may vary by time period and iteration
	if (!mtg->isMainModel && intex->proj_period_last > mtg->maturity_period)
		{
		if (is_first_proj_task_loop)
			asset->valid_t_low_t_high(0, intex->proj_period_last);
		else
			{
			if (intex->proj_period_last > maximum_t_high_value)
				maximum_t_high_value = intex->proj_period_last;
			}
		}

	return 1;
	}

if (pv_defn == MARKET_VALUE_SHIFTED)
	return 1;

if (pv_defn == MARKET_VALUE
	&& t == rebase_period)
	{
	// ensure mtg_cf intex cash flows have been run
	mtg_cf->intex_pmt_processed(t);

	// Reset and parameterize the intex submodel
	intex->resetValues();
	intex->shift_defn = shift_defn;

	intex->proj_defn = MARKET_VALUE;

	if (mtg->mths_to_next_mkt_val_calc(t) == 0
		|| intex->balance[t] == 0)
		{
		intex->mkt_val_cash_flow_proj(t, "Actual", par_val(t) / tranche_portion_bef_sale(t));

		// check that the sec->t_high is large enough to project the Intex asset
		// memory requirements may vary by iteration
		if (!mtg->isMainModel && intex->proj_period_last > mtg->maturity_period)
			{
			if (is_first_proj_task_loop)
				asset->valid_t_low_t_high(0, intex->proj_period_last);
			else
				{
				if (intex->proj_period_last > maximum_t_high_value)
					maximum_t_high_value = intex->proj_period_last;
				}
			}
		}
	else
		intex->mkt_val_cash_flow_proj(t, "Approximate", par_val(t) / tranche_portion_bef_sale(t));

	return 1;
	}

return intex_pmt_processed(t - 1);	
#else
return 0;
#endif

}


//@@ END

//@@ START - mths_since_issue
// Months Since Issue                                                                                             
// Column:MTHS_SINCE_ISSUE
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_mths_since_issue(int t) {
//^^^



//^^^

#line 1 "mths_since_issue.MTG_CF_ASSET.for"
return mtg->mths_since_issue(t);

}


//@@ END

//@@ START - par_val
// Par Value                                                                                             
// Column:PAR_VAL
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_par_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(14,"par_val",t);
}



//^^^

#line 1 "par_val.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t >= mtg->maturity_period)
  return NO_AVG;

if (this == mtg_cf)
	return par_val_bef_sale(t)
		   * (1.0 - mtg->sold_pct(t));

return par_val_bef_sale(t);

}


//@@ END

//@@ START - par_val_aft_dflt
// Par Value After Defaults                                                                                             
// Column:PAR_VAL_AFT_DFLT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_par_val_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(15,"par_val_aft_dflt",t);
}



//^^^

#line 1 "par_val_aft_dflt.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (this == mtg_cf)
	return par_val_bef_sale(t - 1)
		   * (1.0 - mtg->sold_pct(t - 1))
		   * remaining_pct_aft_dflt(t);

if (t == rebase_period + 1)
	{
	if (pv_timing == END_OF_MONTH)
		return pv_initial_par_value;

	if (pv_timing == BEFORE_PREPAYMENTS)
		{
		if (rebase_period == mtg->commencement_period)
			{
			if (this == mtg_is && !mtg->existing_asset_indicator)
				// for interest savings present value calculation
				// within the market value per unit of par calculation
				return mtg_pv->par_val_bef_sale(t - 1);

			return pv_initial_par_value;
			}

		return par_val_aft_sched_pmt(t - 1);
		}

	if (pv_timing == AFTER_PREPAYMENTS)
		{
		return pv_initial_par_value;
		
		if (this == mtg_is && !mtg->existing_asset_indicator)
			// for interest savings present value calculation
			// within the market value per unit of par calculation
			return mtg_pv->par_val_bef_sale(t - 1);

		return par_val_bef_sale(t - 1);
		}
	}

return par_val_aft_prepmt(t - 1);

}


//@@ END

//@@ START - par_val_aft_prepmt
// Par Value After Prepayments                                                                                             
// Column:PAR_VAL_AFT_PREPMT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_par_val_aft_prepmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(16,"par_val_aft_prepmt",t);
}



//^^^

#line 1 "par_val_aft_prepmt.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

#if defined(__INTEX_ASSET_H_)
if (intex_proj_flag)
	{
	if (intex)
		{
		if (intex_pmt_processed(t))
			return intex->get_tranche_bal(t)
				   * tranche_portion_aft_dflt(t);
		}
	}
#endif

double par_val_aft_sched_pmt = this->par_val_aft_sched_pmt(t);

if (par_val_aft_sched_pmt == 0)
	return NO_AVG;

if (prepmt_appl == NO)
	return par_val_aft_sched_pmt;

return par_val_aft_sched_pmt
	   * (1.0 - prepmt_pct_mthly(t));

}


//@@ END

//@@ START - par_val_aft_sched_pmt
// Par Value After Scheduled Payments                                                                                             
// Column:PAR_VAL_AFT_SCHED_PMT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_par_val_aft_sched_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(17,"par_val_aft_sched_pmt",t);
}



//^^^

#line 1 "par_val_aft_sched_pmt.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (intex_proj_flag)
	return par_val_aft_prepmt(t)
		   + prepmt_amt(t);

if (t == mtg->maturity_period)
	return NO_AVG;

if (this == mtg_cf)
	{
	double par_val_aft_dflt
	= par_val_bef_sale(t - 1)
	  * (1.0 - mtg->sold_pct(t - 1))
	  * remaining_pct_aft_dflt(t);

	double par_val_aft_pmt = 0;

	if (mtg->mths_to_next_pmt(t - 1) != 1)
		par_val_aft_pmt = par_val_aft_dflt;
	else
		{
		double int_pmt
		= par_val_aft_dflt
		  * (pmt_rate(t - 1) + mtg->servicing_fee)
		  / mtg->pmt_freq;

		par_val_aft_pmt
		= par_val_aft_dflt
		  - pmt_amt_aft_dflt(t)
		  + int_pmt;
		}

	if (mtg->balloon_pmt_flag == YES)
		{
		double par_val_aft_sched_pmt
		= par_val_aft_pmt - balloon_pmt(t);

		if (par_val_aft_sched_pmt < model_point_amount_threshold)
			return NO_AVG;

		return par_val_aft_sched_pmt;
		}

	if (par_val_aft_pmt < model_point_amount_threshold)
		return NO_AVG;

	return par_val_aft_pmt;
	}

if (t <= rebase_period + 1)
	{
	double par_val_aft_dflt = 0;

	if (pv_timing == END_OF_MONTH)
		par_val_aft_dflt = pv_initial_par_value;

	else if (pv_timing == BEFORE_PREPAYMENTS)
		{
		if (rebase_period == mtg->commencement_period)
			{
			if (this == mtg_is && !mtg->existing_asset_indicator)
				// for interest savings present value calculation
				// within the market value per unit of par calculation
				par_val_aft_dflt = mtg_pv->par_val_bef_sale(t - 1);
			else
				par_val_aft_dflt = pv_initial_par_value;
			}
		else
			par_val_aft_dflt = par_val_aft_sched_pmt(t - 1);
		}

	else if (pv_timing == AFTER_PREPAYMENTS)
		{
		par_val_aft_dflt = pv_initial_par_value;
		}

	double par_val_aft_pmt = 0;

	if (mtg->mths_to_next_pmt(t - 1) != 1)
		par_val_aft_pmt = par_val_aft_dflt;
	else
		{
		double int_pmt
		= par_val_aft_dflt
		  * (pmt_rate(t - 1) + mtg->servicing_fee)
		  / mtg->pmt_freq;

		par_val_aft_pmt
		= par_val_aft_dflt
		  - pmt_amt_aft_dflt(t)
		  + int_pmt;
		}

	if (mtg->balloon_pmt_flag == YES)
		{
		double par_val_aft_sched_pmt
		= par_val_aft_pmt - balloon_pmt(t);

		if (par_val_aft_sched_pmt < model_point_amount_threshold)
			return NO_AVG;

		return par_val_aft_sched_pmt;
		}

	if (par_val_aft_pmt < model_point_amount_threshold)
		return NO_AVG;

	return par_val_aft_pmt;
	}

double par_val_aft_pmt = 0;

if (mtg->mths_to_next_pmt(t - 1) != 1)
	{
	par_val_aft_pmt = par_val_aft_prepmt(t - 1);
	}
else
	{
	double par_val_aft_dflt = par_val_aft_prepmt(t - 1);

	double int_pmt
	= par_val_aft_dflt
	  * (pmt_rate(t - 1) + mtg->servicing_fee)
	  / mtg->pmt_freq;

	double pmt_amt_aft_dflt = 0;

	if (prepmt_appl == YES)
		pmt_amt_aft_dflt
		= pmt_amt_aft_sched_payment(t - 1)
		  * (1.0 - prepmt_pct_mthly(t - 1));
	else
		pmt_amt_aft_dflt
		= pmt_amt_aft_sched_payment(t - 1);

	par_val_aft_pmt
	= par_val_aft_dflt
	  - pmt_amt_aft_dflt
	  + int_pmt;
	}

if (mtg->balloon_pmt_flag == YES)
	{
	double par_val_aft_sched_pmt
	= par_val_aft_pmt - balloon_pmt(t);

	if (par_val_aft_sched_pmt < model_point_amount_threshold)
		return NO_AVG;

	return par_val_aft_sched_pmt;
	}

if (par_val_aft_pmt < model_point_amount_threshold)
	return NO_AVG;

return par_val_aft_pmt;

}


//@@ END

//@@ START - par_val_bef_sale
// Par Value Before Sales                                                                                             
// Column:PAR_VAL_BEF_SALE
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_par_val_bef_sale(int t) {
//^^^



//^^^

#line 1 "par_val_bef_sale.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (t == 0 && mtg->existing_asset_indicator)
	return mtg->init_par_val
		   * mtg->neg_asset_flag;

if(t == mtg->commencement_period && !mtg->existing_asset_indicator)
	{
	if (pv_par_val_per_unit_of_par_calculation)
		return max(ONE_MILLION, fabs(mtg->purch_amt));

	if (mtg->purch_defn == INVESTMENT
		&& mtg->mkt_val_per_unit_par != 0.0)
		return mtg->purch_amt 
			   * mtg->neg_asset_flag
			   / (mtg->mkt_val_per_unit_par
				  + mtg->accr_int_per_par_unit);

	if (mtg->purch_defn == FORECLOSURE
		|| mtg->purch_defn == RESTRUCTURE
		|| mtg->purch_defn == REFINANCE)
		return mtg->purch_amt
			   * mtg->neg_asset_flag;
	}

if (this == mtg_cf)
	return par_val_aft_prepmt(t);

if (rebase_period == t)
	return mtg_cf->par_val_bef_sale(t);

return par_val_aft_prepmt(t);

}


//@@ END

//@@ START - par_val_for_balloon_pmt_aft_dflt
// Par Value for Balloon Payment After Defaults                                                                                             
// Column:PAR_VAL_FOR_BALLOON_PMT_AFT_DFLT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_par_val_for_balloon_pmt_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(19,"par_val_for_balloon_pmt_aft_dflt",t);
}



//^^^

#line 1 "par_val_for_balloon_pmt_aft_dflt.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (this == mtg_cf)
	return par_val_for_balloon_pmt_bef_sale(t - 1)
		   * (1.0 - mtg->sold_pct(t - 1))
		   * remaining_pct_aft_dflt(t);

if (t == rebase_period + 1)
	{
	if (pv_timing == END_OF_MONTH)
		return par_val_for_balloon_pmt_bef_sale(t - 1);

	if (pv_timing == BEFORE_PREPAYMENTS)
		{
		if (t == mtg->commencement_period + 1)
  		    return par_val_for_balloon_pmt_bef_sale(t - 1);

		return par_val_for_balloon_pmt_aft_dflt(t - 1);
		}

	if (pv_timing == AFTER_PREPAYMENTS)
		{
		return par_val_for_balloon_pmt_bef_sale(t - 1);
		}
	}

if (prepmt_appl == YES)
	return par_val_for_balloon_pmt_aft_dflt(t - 1)
		   * (1.0 - prepmt_pct_mthly(t - 1));

return par_val_for_balloon_pmt_aft_dflt(t - 1);

}


//@@ END

//@@ START - par_val_for_balloon_pmt_bef_sale
// Par Value for Balloon Payment Before Sales                                                                                             
// Column:PAR_VAL_FOR_BALLOON_PMT_BEF_SALE
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_par_val_for_balloon_pmt_bef_sale(int t) {
//^^^



//^^^

#line 1 "par_val_for_balloon_pmt_bef_sale.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (t == 0 && mtg->existing_asset_indicator)
	return mtg->par_val_at_issue;

if (t == mtg->commencement_period && !mtg->existing_asset_indicator)
	{
	if (this == mtg_cf)
		return mtg->par_val_at_issue;

	if (pv_par_val_per_unit_of_par_calculation)
		return max(ONE_MILLION, fabs(mtg->purch_amt));

	return par_val_bef_sale(t);
	}

double prepmt_pct = 0;

if (prepmt_appl == YES)
	prepmt_pct = prepmt_pct_mthly(t);

return par_val_for_balloon_pmt_aft_dflt(t)
	   * (1.0 - prepmt_pct);

}


//@@ END

//@@ START - pmt_amt_aft_dflt
// Payment Amount After Defaults                                                                                             
// Column:PMT_AMT_AFT_DFLT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_pmt_amt_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(21,"pmt_amt_aft_dflt",t);
}



//^^^

#line 1 "pmt_amt_aft_dflt.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (this == mtg_cf)
	return pmt_amt_bef_sale(t - 1)
		   * (1.0 - mtg->sold_pct(t - 1))
		   * remaining_pct_aft_dflt(t);

if (t == rebase_period + 1)
	{
	if (pv_timing == END_OF_MONTH)
		return pmt_amt_bef_sale(t - 1);

	if (pv_timing == BEFORE_PREPAYMENTS)
		{
		if (rebase_period == mtg->commencement_period)
			{
			if (this == mtg_is && !mtg->existing_asset_indicator)
				// for interest savings present value calculation
				// within the market value per unit of par calculation
				return mtg->pmt_amt(t - 1,
								max(ONE_MILLION, fabs(mtg->purch_amt)),
								mtg->maturity_period - t + 1,
								mtg->pmt_freq,
								pmt_rate(t - 1) + mtg->servicing_fee,
								mtg->amortzn_period);

			return pmt_amt_bef_sale(t - 1);
			}

		return pmt_amt_aft_sched_payment(t - 1);
		}

	if (pv_timing == AFTER_PREPAYMENTS)
		{
		if (pv_par_val_per_unit_of_par_calculation)
			return mtg->pmt_amt(t,
						max(ONE_MILLION, fabs(mtg->purch_amt)),
						mtg->maturity_period - t + 1,
						mtg->pmt_freq,
						pmt_rate(t - 1) + mtg->servicing_fee,
						mtg->amortzn_period);

		if (this == mtg_is
				|| t == max(0, mtg->commencement_period))
			return pmt_amt_bef_sale(t - 1);

		return mtg_cf->pmt_amt_aft_sched_payment(t - 1)
						* (1.0 - mtg_cf->prepmt_pct_mthly(t - 1));
		}
	}

return pmt_amt_bef_sale(t - 1);

}


//@@ END

//@@ START - pmt_amt_aft_sched_payment
// Payment Amount After Scheduled Payments Amount                                                                                             
// Column:PMT_AMT_AFT_SCHED_PAYMENT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_pmt_amt_aft_sched_payment(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(22,"pmt_amt_aft_sched_payment",t);
}



//^^^

#line 1 "pmt_amt_aft_sched_payment.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t >= mtg->maturity_period)
	return NO_AVG;

if (mtg->amortzn_period == t
	|| (mtg->pmt_rate_defn == FLOATING_RATE
		&& mtg->mths_to_next_reset(t - 1) == 1))
	return mtg->pmt_amt(t,
					par_val_aft_sched_pmt(t),
					mtg->maturity_period - t,
					mtg->pmt_freq,
					pmt_rate(t) + mtg->servicing_fee,
					mtg->amortzn_period);

if (intex_proj_flag)
	{
	if (par_val_aft_dflt(t) > 0.0)
		{
		if (mtg->balloon_pmt_flag == YES)
			return pmt_amt_aft_dflt(t)
				   * (1.0 - balloon_pmt(t) / par_val_aft_dflt(t));

		return pmt_amt_aft_dflt(t);
		}

	return NO_AVG;
	}

double par_val_aft_pmt = 0;

if (this == mtg_cf
	|| t == rebase_period + 1)
	{
	if (mtg->mths_to_next_pmt(t - 1) != 1)
		par_val_aft_pmt = par_val_aft_dflt(t);
	else
		{
		double par_val_aft_dflt = this->par_val_aft_dflt(t);

		double int_pmt
		= par_val_aft_dflt
		  * (pmt_rate(t - 1) + mtg->servicing_fee)
		  / mtg->pmt_freq;

		par_val_aft_pmt
		= par_val_aft_dflt
		  - pmt_amt_aft_dflt(t)
		  + int_pmt;
		}

	if (par_val_aft_pmt > 0.0)
		{
		if (mtg->balloon_pmt_flag == YES)
			return pmt_amt_aft_dflt(t)
					* (1.0 - balloon_pmt(t) / par_val_aft_pmt);

		return pmt_amt_aft_dflt(t);
		}

	return NO_AVG;
	}

// else if (t > rebase_period + 1)

double pmt_amt_aft_dflt = 0;

if (prepmt_appl == YES)
	pmt_amt_aft_dflt
	= pmt_amt_aft_sched_payment(t - 1)
	  * (1.0 - prepmt_pct_mthly(t - 1));
else
	pmt_amt_aft_dflt
	= pmt_amt_aft_sched_payment(t - 1);

if (mtg->mths_to_next_pmt(t - 1) != 1)
	par_val_aft_pmt = par_val_aft_prepmt(t - 1);
else
	{
	double par_val_aft_dflt = par_val_aft_prepmt(t - 1);

	double int_pmt
	= par_val_aft_dflt
	  * (pmt_rate(t - 1) + mtg->servicing_fee)
	  / mtg->pmt_freq;

	par_val_aft_pmt
	= par_val_aft_dflt
	  - pmt_amt_aft_dflt
	  + int_pmt;
	}

if (par_val_aft_pmt > 0.0)
	{
	if (mtg->balloon_pmt_flag == YES)
		return pmt_amt_aft_dflt
			   * (1.0 - balloon_pmt(t) / par_val_aft_pmt);

	return pmt_amt_aft_dflt;
	}

return NO_AVG;

}


//@@ END

//@@ START - pmt_amt_bef_sale
// Payment Amount Before Sales                                                                                             
// Column:PMT_AMT_BEF_SALE
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_pmt_amt_bef_sale(int t) {
//^^^



//^^^

#line 1 "pmt_amt_bef_sale.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (t == 0 && mtg->existing_asset_indicator)
	return mtg->pmt_amt(t, 
					par_val_bef_sale(t),
					mtg->maturity_period - t,
					mtg->pmt_freq,
					pmt_rate(t) + mtg->servicing_fee,
					mtg->amortzn_period);

if (t == mtg->commencement_period && !mtg->existing_asset_indicator)
	{
	if (this == mtg_cf)
		return mtg->pmt_amt(t, 
						max(ONE_MILLION, fabs(mtg->purch_amt)),
						mtg->maturity_period - t,
						mtg->pmt_freq,
						pmt_rate(t) + mtg->servicing_fee,
						mtg->amortzn_period)
			   * par_val_bef_sale(t)
			   / max(ONE_MILLION, fabs(mtg->purch_amt));

	return mtg->pmt_amt(t,
				par_val_bef_sale(t),
				mtg->maturity_period - t,
				mtg->pmt_freq,
				pmt_rate(t) + mtg->servicing_fee,
				mtg->amortzn_period);
	}

if (this != mtg_cf
		&& rebase_period == t)
	return mtg_cf->pmt_amt_bef_sale(t);

double monthly_prepayment_factor_local = 0;
double asset_decrement_percentage_after_prepayments_local = 0;

if (prepmt_appl == YES)
	monthly_prepayment_factor_local
	= prepmt_pct_mthly(t);

return pmt_amt_aft_sched_payment(t)
	   * (1.0 - monthly_prepayment_factor_local);

}


//@@ END

//@@ START - pmt_rate
// Payment Rate                                                                                             
// Column:PMT_RATE
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_pmt_rate(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(24,"pmt_rate",t);
}



//^^^

#line 1 "pmt_rate.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

double local_mortgage_interest_rate;

if (t == 0 && mtg->existing_asset_indicator)
	{
	int months_to_input_reset_date
	= min(get_yr_from_date(mtg->adj_next_reset_date) - mtg->proj_start_yr,
   		  MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12
   	  + get_mth_from_date(mtg->adj_next_reset_date) 
   	  - mtg->proj_start_mth + 1;

	if (mtg->init_pmt_rate > rate_ratio_threshold
			|| (months_to_input_reset_date
						> xint(mtg->mths_to_next_reset(t) - get_mth_from_date(mtg->adj_next_reset_date)))
			|| (xint(mtg->mths_to_next_reset(t) - mtg->adj_reset_mths) > 0))
		return mtg->init_pmt_rate;

	local_mortgage_interest_rate
	= min(max(renewal_rate(t), mtg->adj_min_rate),
				mtg->adj_max_rate);

	log_screen.setf(ios::fixed, ios::floatfield);
	log_screen << "Payment rate for existing adjustable rate mortgage " << mtg->asset_id
			 << " is zero."
			 << " Payment rate at model start date has been set to " << local_mortgage_interest_rate
			 << " Per-reset adjustments have been ignored."
			 << MSG_ERROR;
	log_screen.unsetf(ios::fixed);

	return local_mortgage_interest_rate
			   - mtg->servicing_fee;
	}

if (t == mtg->commencement_period && !mtg->existing_asset_indicator)
	return mtg->pmt_rate_at_issue;

if (mtg->pmt_rate_defn == FLOATING_RATE && mtg->mths_to_next_reset(t - 1) == 1)
	{
	local_mortgage_interest_rate
	= pmt_rate(t - 1) + mtg->servicing_fee;

	return min(min(max(max(renewal_rate(t),
						   local_mortgage_interest_rate
						   - mtg->adj_max_decr_per_reset),
					   mtg->adj_min_rate),
				   local_mortgage_interest_rate
				   + mtg->adj_max_incr_per_reset),
			   mtg->adj_max_rate)
		   - mtg->servicing_fee;
	}

return pmt_rate(t - 1);

}


//@@ END

//@@ START - prepmt_amt
// Prepayment Amount                                                                                             
// Column:PREPMT_AMT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_prepmt_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(25,"prepmt_amt",t);
}



//^^^

#line 1 "prepmt_amt.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

#if defined(__INTEX_ASSET_H_)
if (intex_proj_flag)
	{
	if (intex)
		{
		if (intex_pmt_processed(t))
			return intex->get_collateral_prepmt(t)
	 			   * tranche_portion_aft_dflt(t);
		}
	}
#endif	

if (prepmt_appl == NO
	|| t < mtg->prepmt_first_period)
	return NO_AVG;

if (this == mtg_cf)
	{
	if (par_val_aft_sched_pmt(t) < rate_ratio_threshold)
		return NO_AVG;

	if (prepmt_pct_mthly(t) < rate_ratio_threshold)
		return 0.0;
	
	if (mtg->prepmt_first_period < mtg->maturity_period)
		return par_val_aft_sched_pmt(t)
			   * (1.0 + prepmt_penalty(t))
			   * prepmt_pct_mthly(t);

	return NO_AVG;
	}

if (mtg->prepmt_first_period < mtg->maturity_period)
	return par_val_aft_sched_pmt(t)
		   * (1.0 + prepmt_penalty(t))
		   * prepmt_pct_mthly(t);

return NO_AVG;

}


//@@ END

//@@ START - prepmt_inc
// Prepayment Income                                                                                             
// Column:PREPMT_INC
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_prepmt_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(26,"prepmt_inc",t);
}



//^^^

#line 1 "prepmt_inc.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (intex_proj_flag
	|| prepmt_appl == NO
	|| t < mtg->prepmt_first_period)
	return NO_AVG;
	
if (mtg->pmt_mode == MONTHLY
	|| mtg->mths_to_next_pmt(t - 1) == 1)
	return NO_AVG;

return accr_int_bef_prepmt(t)
	   * prepmt_pct_mthly(t);

}


//@@ END

//@@ START - prepmt_pct
// Prepayment Percent                                                                                             
// Column:PREPMT_PCT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_prepmt_pct(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(27,"prepmt_pct",t);
}



//^^^

#line 1 "prepmt_pct.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

double local_par_val_aft_sched_pmt = par_val_aft_sched_pmt(t);
if (local_par_val_aft_sched_pmt == 0.0)
	return NO_AVG;

double psa_factor = 0.0;
if (mtg->prepmt_defn == PERCENT_OF_PSA)
	psa_factor = mtg->psa_base_rate[min(30, mtg->mths_since_issue(t))];
else
	psa_factor = 1.0;

double nonfinancial_factor = mtg->prepmt_nonfinancial_pct * psa_factor;

double int_rate_diff = 0.0;
double local_pmt_rate = 0.0;
if (mtg->prepmt_int_diff_defn == NET_YIELD)
	local_pmt_rate = mtg->net_yld(t - 1);
else
	local_pmt_rate = pmt_rate(t);

if (mtg->prepmt_int_diff_defn == GROSS_INTEREST_RATE)
	int_rate_diff
	= convert_rate_basis(local_pmt_rate + mtg->servicing_fee,
			  mtg->pmt_freq,
			  NOMINAL_SEMIANNUAL);
else if (mtg->prepmt_int_diff_defn == INTEREST_RATE)
	int_rate_diff
	= convert_rate_basis(local_pmt_rate,
			  mtg->pmt_freq,
			  NOMINAL_SEMIANNUAL);
else if (mtg->prepmt_int_diff_defn == NET_YIELD)
	int_rate_diff
	= convert_rate_basis(local_pmt_rate, 12,
			  NOMINAL_SEMIANNUAL);

// Set lookup key for prepmt_exercise_pct variable
mtg->int_rate_diff = int_rate_diff - refinancing_rate(t);

double diff_factor = mtg->prepmt_exercise_pct_input * psa_factor;

double financial_prepayment_factor = 0.0;

if (diff_factor > rate_ratio_threshold)
	{
	double prepayment_cost = 0;
	
	if (mtg->prepmt_first_period < mtg->maturity_period)
		prepayment_cost
		= local_par_val_aft_sched_pmt
		  * (prepmt_penalty(t) + mtg->refinancing_cost_pct);
	else
		prepayment_cost	= local_par_val_aft_sched_pmt * mtg->refinancing_cost_pct;
	
	double interest_savings	= int_savings_pv_bef_prepmt(t) - local_par_val_aft_sched_pmt;

	if (interest_savings > prepayment_cost)
		financial_prepayment_factor	= diff_factor;
	}

double mortgage_seasonality_adjustment_factor = mtg->prepmt_nonfinancial_seasonality_addn;

double nonfinancial_interest_diff = 0.0;

if (mtg->prepmt_int_diff_defn == GROSS_INTEREST_RATE)
	nonfinancial_interest_diff
	= refinancing_rate(t)
	  - convert_rate_basis(local_pmt_rate + mtg->servicing_fee,
				mtg->pmt_freq,
				NOMINAL_SEMIANNUAL);

else if (mtg->prepmt_int_diff_defn == INTEREST_RATE)
	nonfinancial_interest_diff
	= refinancing_rate(t)
	  - convert_rate_basis(local_pmt_rate,
				mtg->pmt_freq,
				NOMINAL_SEMIANNUAL);

else if (mtg->prepmt_int_diff_defn == NET_YIELD)
	nonfinancial_interest_diff
	= refinancing_rate(t)
	  - convert_rate_basis(local_pmt_rate, 12,
				NOMINAL_SEMIANNUAL);

// Set lookup key for prepmt_nonfinancial_adj variable
mtg->nonfinancial_int_rate_diff = nonfinancial_interest_diff;

double mortgage_nonfinancial_adjustment_factor = mtg->prepmt_nonfinancial_adj * psa_factor;

double mortgage_seasoning_adjustment_factor = mtg->prepmt_seasoning_since_issue_mult;

return max(0.0,
		   min((nonfinancial_factor
				+ mortgage_seasonality_adjustment_factor
				- mortgage_nonfinancial_adjustment_factor
				+ financial_prepayment_factor)
			   * mortgage_seasoning_adjustment_factor, 1.0));

}


//@@ END

//@@ START - prepmt_pct_mthly
// Prepayment Percent Monthly                                                                                             
// Column:PREPMT_PCT_MTHLY
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_prepmt_pct_mthly(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(28,"prepmt_pct_mthly",t);
}



//^^^

#line 1 "prepmt_pct_mthly.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (intex_proj_flag)
	{
	if (par_val_aft_sched_pmt(t) > 0.0)
		return prepmt_amt(t) / par_val_aft_sched_pmt(t);

	return NO_AVG;
	}

if (prepmt_appl == NO
	|| t < mtg->prepmt_first_period
	|| par_val_aft_sched_pmt(t) <= 0)
	return NO_AVG;

if (mtg->prepmt_model_defn == SPLINE)
	return 1.0 - pow(1.0 - prepmt_pct(t), 1.0 / 12.0);

if (mtg->prepmt_model_defn == ANDREW_DAVIDSON
	&& adco_prepmt_forecast(t))
	{
	int schedule_index;

	if (mtg->existing_asset_indicator)
		schedule_index = t;
	else
		schedule_index = t - mtg->commencement_period;

	return prepmt_rate[schedule_index];
	}

return NO_AVG;

}


//@@ END

//@@ START - prepmt_penalty
// Prepayment Penalty                                                                                             
// Column:PREPMT_PENALTY
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_prepmt_penalty(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(29,"prepmt_penalty",t);
}



//^^^

#line 1 "prepmt_penalty.MTG_CF_ASSET.for"
if (mtg->prepmt_penalty_defn == NOT_APPLICABLE
	|| t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

int schedule_index = 0;
	
if (mtg->existing_asset_indicator)
	schedule_index = t;
else
	schedule_index = t - mtg->commencement_period;

if (mtg->prepmt_penalty_defn == PENALTY_PERCENT)
	return mtg->prepmt_penalty_sch[schedule_index];

if (mtg->prepmt_penalty_defn == YIELD_MAINTENANCE
	|| mtg->prepmt_penalty_defn == CASH_FLOW_MAINTENANCE)
	return yld_maint_cost_pct(t) - 1.0;

if (mtg->prepmt_penalty_defn == RELATED_TO_PAYMENT_RATE
	&& mtg->prepmt_par_first_period - t > 0)
	return mtg->prepmt_penalty_related_to_pmt_rate 
		   * (mtg->prepmt_par_first_period - t)
		   / mtg->prepmt_penalty_grading_mths;

return NO_AVG;

}


//@@ END

//@@ START - refinancing_rate
// Refinancing Rate                                                                                             
// Column:REFINANCING_RATE
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_refinancing_rate(int t) {
//^^^



//^^^

#line 1 "refinancing_rate.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

int scenario_month;
int valuation_period;

if (pv_defn != CASH_FLOWS && t > rebase_period)
	{
	valuation_period = max(rebase_period, mtg->commencement_period);

	if (pv_timing == END_OF_MONTH
		|| mtg->use_eom_scen_rates == YES)
		scenario_month = xint(mtg->cal_mth(valuation_period));
	else
		scenario_month = xint(mtg->cal_mth(valuation_period)) - 1;

	return mtg->category_refinancing_rate(valuation_period,
					xint(mtg->cal_yr_relative(valuation_period)),
					scenario_month,
					mtg->maturity_period - t,
					NOMINAL_SEMIANNUAL,
					shift_defn,
					0);
	}

if (pv_timing == END_OF_MONTH
	|| mtg->use_eom_scen_rates == YES)
		scenario_month = xint(mtg->cal_mth(t));
	else
		scenario_month = xint(mtg->cal_mth(t)) - 1;

return mtg->category_refinancing_rate(t,
				xint(mtg->cal_yr_relative(t)),
				scenario_month,
				mtg->maturity_period - t,
				NOMINAL_SEMIANNUAL,
				shift_defn,
				0);

}


//@@ END

//@@ START - remaining_pct_aft_dflt
// Remaining Percent After Defaults                                                                                             
// Column:REMAINING_PCT_AFT_DFLT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_remaining_pct_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(31,"remaining_pct_aft_dflt",t);
}



//^^^

#line 1 "remaining_pct_aft_dflt.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (dflt_appl == NO)
	return 1.0;

return (1.0 - mtg->decr_pct(t));

}


//@@ END

//@@ START - remaining_pct_aft_sched_pmt
// Remaining Percent After Scheduled Payments                                                                                             
// Column:REMAINING_PCT_AFT_SCHED_PMT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_remaining_pct_aft_sched_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(32,"remaining_pct_aft_sched_pmt",t);
}



//^^^

#line 1 "remaining_pct_aft_sched_pmt.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

double local_par_val_aft_pmt = par_val_aft_sched_pmt(t);

if (mtg->balloon_pmt_flag == YES)
	local_par_val_aft_pmt = local_par_val_aft_pmt - balloon_pmt(t);

if (local_par_val_aft_pmt <= 0.0)
	return NO_AVG;

double remaining_pct_aft_dflt = 1.0;

if (this == mtg_cf)
	remaining_pct_aft_dflt = this->remaining_pct_aft_dflt(t);

if (t < mtg->maturity_period)
	{
	if (mtg->balloon_pmt_flag == YES)
		return remaining_pct_aft_dflt
			   * (1.0 - balloon_pmt(t)
						/ (local_par_val_aft_pmt - balloon_pmt(t)));

	return remaining_pct_aft_dflt;
	}

if (intex_proj_flag)
	return remaining_pct_aft_dflt;

return NO_AVG;

}


//@@ END

//@@ START - renewal_rate
// Renewal Rate                                                                                             
// Column:RENEWAL_RATE
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_renewal_rate(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(33,"renewal_rate",t);
}



//^^^

#line 1 "renewal_rate.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (mtg->pmt_rate_defn == FIXED_RATE)
	return NO_AVG;

int scenario_month;
double base_index_rate;

// Set the initial renewal rate for adjustable rate mortgages
// Used to set initial payment rate.
if (this == mtg_cf)
	{
	if (mtg->use_eom_scen_rates == YES)
		scenario_month = 0;
	else
		scenario_month = - 1;

	if (t == 0 && mtg->existing_asset_indicator)
		base_index_rate 
		= rates->get_int_rate(t + scenario_month
						      + (mtg->mths_to_next_reset(t)
						      - mtg->adj_reset_mths),
						mtg->adj_reset_category_id,
						GET_YIELD_RATE,
						mtg->adj_reset_scen_yr,
						0.0, 
						mtg->pmt_freq,
						shift_defn,mtg->portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	else
		base_index_rate
		= rates->get_int_rate(t + scenario_month,
		                mtg->adj_reset_category_id,
						GET_YIELD_RATE,
						mtg->adj_reset_scen_yr,
						0.0,
						mtg->pmt_freq, 
						shift_defn,mtg->portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	return base_index_rate
		   * mtg->adj_reset_scen_mult
		   + mtg->adj_reset_renewal_addn;
	}

int valuation_period
= max(rebase_period, mtg->commencement_period);

// For net yield calculations for mortgages, hold coupon rate constant.
// This method is described on pages 1154-1157 of Fabozzi's "Handbook of
// Mortgage-Backed Securities", 3rd edition, 1992, Probus Publishing Co.,
// in the "Accounting for Adjustable-Rate Securities" section (second method).
if (pv_defn == NET_YIELD)
	return renewal_rate(valuation_period);

// For all other present value methods, the renewal rate is based
// on the forward rates curve as of the rebase period.
if (pv_defn == MARKET_VALUE
	|| pv_defn == MARKET_VALUE_SHIFTED
	|| this == mtg_is
	|| this == mtg_ym)
	{
	if (pv_timing == END_OF_MONTH
		|| mtg->use_eom_scen_rates == YES)
		scenario_month = 0;
	else
		scenario_month = - 1;

	base_index_rate
	= convert_rate_basis(rates->get_int_rate(valuation_period + scenario_month,
							mtg->adj_reset_category_id,
							GET_FORWARD_RATE,
							(t - valuation_period) / 12.0,
							mtg->adj_reset_scen_yr,
							NOMINAL_SEMIANNUAL,
							shift_defn,mtg->portfolio_sprd_adj_aig),//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			   NOMINAL_SEMIANNUAL,
			   mtg->pmt_freq);

	return base_index_rate
		   * mtg->adj_reset_scen_mult
		   + mtg->adj_reset_renewal_addn;
	}

return NO_AVG;

}


//@@ END

//@@ START - sched_prin_pmt
// Scheduled Principal Payment                                                                                             
// Column:SCHED_PRIN_PMT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_sched_prin_pmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(34,"sched_prin_pmt",t);
}



//^^^

#line 1 "sched_prin_pmt.MTG_CF_ASSET.for"
if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

double local_prin_pmt = 0;

#if defined(__INTEX_ASSET_H_)
if (intex_proj_flag)
	{
	if (intex)
		{
		if (intex_pmt_processed(t))
			local_prin_pmt
			= intex->get_tranche_prin_pmt(t)
			  * tranche_portion_aft_dflt(t);
		}

	if (t < mtg->maturity_period)
		{
		if (mtg->balloon_pmt_period < mtg->maturity_period)
			return local_prin_pmt + balloon_pmt(t);
		}

	return local_prin_pmt;
	}
#endif

if (mtg->mths_to_next_pmt(t - 1) != 1
	|| t < mtg->amortzn_period)
	{
	if (t < mtg->maturity_period)
		return balloon_pmt(t);

	if (this == mtg_cf
		|| t <= rebase_period + 1)
		return par_val_aft_dflt(t);

	return par_val_aft_prepmt(t - 1);
	}

double base_principal_payment = 0;
double local_par_val_aft_dflt_bom = 0;

if (this == mtg_cf
	|| t <= rebase_period + 1)
	{
	local_par_val_aft_dflt_bom = par_val_aft_dflt(t);

	if (t == mtg->maturity_period)
		base_principal_payment = local_par_val_aft_dflt_bom;
	else
		{
		double base_mortgage_interest_payment
		= local_par_val_aft_dflt_bom
		  * (pmt_rate(t - 1) + mtg->servicing_fee)
		  / mtg->pmt_freq;
	
		base_principal_payment
		= pmt_amt_aft_dflt(t)
		  - base_mortgage_interest_payment;
		}
	}
else
	{
	local_par_val_aft_dflt_bom = par_val_aft_prepmt(t - 1);

	if (t == mtg->maturity_period)
		base_principal_payment = local_par_val_aft_dflt_bom;
	else
		{
		double base_mortgage_interest_payment
		= local_par_val_aft_dflt_bom
		  * (pmt_rate(t - 1) + mtg->servicing_fee)
		  / mtg->pmt_freq;
	
		base_principal_payment
		= pmt_amt_aft_sched_payment(t - 1)
			* (1 - prepmt_pct_mthly(t - 1))
			- base_mortgage_interest_payment;
		}
	}

if (mtg->purch_defn == FORECLOSURE)
	local_prin_pmt
	= base_principal_payment
	  * since_foreclosure_prin_pmt_mult(t);

else if (mtg->purch_defn == RESTRUCTURE)
	local_prin_pmt
	= base_principal_payment
	  * since_restructure_prin_pmt_mult(t);

else
	local_prin_pmt = base_principal_payment;

if (t < mtg->maturity_period)
	return local_prin_pmt + balloon_pmt(t);

return local_prin_pmt;

}


//@@ END

//@@ START - since_foreclosure_int_mult
// Since Foreclosure Interest Multiple                                                                                             
// Column:SINCE_FORECLOSURE_INT_MULT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_since_foreclosure_int_mult(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(35,"since_foreclosure_int_mult",t);
}



//^^^

#line 1 "since_foreclosure_int_mult.MTG_CF_ASSET.for"
if (mtg->purch_defn != FORECLOSURE)
	return 1.0;

if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (pv_defn == NET_YIELD)
	return 1.0;

// Lookup key is mths_since_issue(t)
int period = 1 - mtg->init_mths_since_issue; // mths_since_issue(period) = 1

if (pv_defn == CASH_FLOWS)
	{
	if (mths_since_issue(t) >= 1)
		return company->sm_inv_strategy[mtg->seg_num]->foreclosure_int_pmt_mult;

	// mths_since_issue(t) < 1
	return company->sm_inv_strategy[mtg->seg_num]->foreclosure_int_pmt_mult.AtTime(period);
	}

// pv_defn != CASH_FLOWS
int valuation_period = max(rebase_period, mtg->commencement_period);

if (mths_since_issue(valuation_period + 1) >= 1)
	return company->sm_inv_strategy[mtg->seg_num]->foreclosure_int_pmt_mult.AtTime(valuation_period + 1);

// mths_since_issue(valuation_period + 1) < 1
return company->sm_inv_strategy[mtg->seg_num]->foreclosure_int_pmt_mult.AtTime(period);

}


//@@ END

//@@ START - since_foreclosure_prin_pmt_mult
// Since Foreclosure Principal Payment Multiple                                                                                             
// Column:SINCE_FORECLOSURE_PRIN_PMT_MULT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_since_foreclosure_prin_pmt_mult(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(36,"since_foreclosure_prin_pmt_mult",t);
}



//^^^

#line 1 "since_foreclosure_prin_pmt_mult.MTG_CF_ASSET.for"
if (mtg->purch_defn != FORECLOSURE)
	return 1.0;

if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (pv_defn == NET_YIELD)
	return 1.0;

// Lookup key is mths_since_issue(t)
int period = 1 - mtg->init_mths_since_issue; // mths_since_issue(period) = 1

if (pv_defn == CASH_FLOWS)
	{
	if (mths_since_issue(t) >= 1)
		return company->sm_inv_strategy[mtg->seg_num]->foreclosure_prin_pmt_mult;

	// mths_since_issue(t) < 1
	return company->sm_inv_strategy[mtg->seg_num]->foreclosure_prin_pmt_mult.AtTime(period);
	}

// pv_defn != CASH_FLOWS
int valuation_period = max(rebase_period, mtg->commencement_period);

if (mths_since_issue(valuation_period + 1) >= 1)
	return company->sm_inv_strategy[mtg->seg_num]->foreclosure_prin_pmt_mult.AtTime(valuation_period + 1);

// mths_since_issue(valuation_period + 1) < 1
return company->sm_inv_strategy[mtg->seg_num]->foreclosure_prin_pmt_mult.AtTime(period);

}


//@@ END

//@@ START - since_restructure_int_mult
// Since Restructure Interest Multiple                                                                                             
// Column:SINCE_RESTRUCTURE_INT_MULT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_since_restructure_int_mult(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(37,"since_restructure_int_mult",t);
}



//^^^

#line 1 "since_restructure_int_mult.MTG_CF_ASSET.for"
if (mtg->purch_defn != RESTRUCTURE)
	return 1.0;

if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (pv_defn == NET_YIELD)
	return 1.0;

// Lookup key is mths_since_issue(t)
int period = 1 - mtg->init_mths_since_issue; // mths_since_issue(period) = 1

if (pv_defn == CASH_FLOWS)
	{
	if (mths_since_issue(t) >= 1)
		return company->sm_inv_strategy[mtg->seg_num]->restructure_int_pmt_mult;

	// mths_since_issue(t) < 1
	return company->sm_inv_strategy[mtg->seg_num]->restructure_int_pmt_mult.AtTime(period);
	}

// pv_defn != CASH_FLOWS
int valuation_period = max(rebase_period, mtg->commencement_period);

if (mths_since_issue(valuation_period + 1) >= 1)
	return company->sm_inv_strategy[mtg->seg_num]->restructure_int_pmt_mult.AtTime(valuation_period + 1);

// mths_since_issue(valuation_period + 1) < 1
return company->sm_inv_strategy[mtg->seg_num]->restructure_int_pmt_mult.AtTime(period);

}


//@@ END

//@@ START - since_restructure_prin_pmt_mult
// Since Restructure Principal Payment Multiple                                                                                             
// Column:SINCE_RESTRUCTURE_PRIN_PMT_MULT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_since_restructure_prin_pmt_mult(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(38,"since_restructure_prin_pmt_mult",t);
}



//^^^

#line 1 "since_restructure_prin_pmt_mult.MTG_CF_ASSET.for"
if (mtg->purch_defn != RESTRUCTURE)
	return 1.0;

if (t <= mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (pv_defn == NET_YIELD)
	return 1.0;	

// Lookup key is mths_since_issue(t)
int period = 1 - mtg->init_mths_since_issue; // mths_since_issue(period) = 1

if (pv_defn == CASH_FLOWS)
	{
	if (mths_since_issue(t) >= 1)
		return company->sm_inv_strategy[mtg->seg_num]->restructure_prin_pmt_mult;

	// mths_since_issue(t) < 1
	return company->sm_inv_strategy[mtg->seg_num]->restructure_prin_pmt_mult.AtTime(period);
	}

// pv_defn != CASH_FLOWS
int valuation_period = max(rebase_period, mtg->commencement_period);

if (mths_since_issue(valuation_period + 1) >= 1)
	return company->sm_inv_strategy[mtg->seg_num]->restructure_prin_pmt_mult.AtTime(valuation_period + 1);

// mths_since_issue(valuation_period + 1) < 1
return company->sm_inv_strategy[mtg->seg_num]->restructure_prin_pmt_mult.AtTime(period);

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double MTG_CF_ASSET_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.MTG_CF_ASSET.for"
#if 0 // START_EXTERNS
extern int PVCounter;
extern ofstream& PVCFile;
extern ostringstream PVCText;
extern int PVCLen;
extern int PVCSigDig;
extern xstring PVC_FilNam;
extern SmartArray <double>& spot_rate_tbl;
extern SmartArray <double>& shifted_spot_rate_tbl;
extern bool is_asset_initialize;

// present value calculation variables
#define YM_UPDATE 0 // 1 for log_screen output, 0 for no output
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

#if defined(__INTEX_ASSET_H_)
extern bool intex_detail_wanted;
#endif

#include <sstream> // for ostringstream

// This macro evaluates the number of decimals in the 'xxx' value that corresponds
// to 'sig_digits' significant digits. This macro is used to set solving_flag tolerance
// factors. For example, NUMBER_OF_DECIMALS(50000,11) evaluates to 6.
#define NUMBER_OF_DECIMALS(xxx,sig_digits) (fabs(xxx) < 0.000000001 ? (sig_digits-1) : (min((sig_digits-1), (int)((sig_digits) - log10(fabs(xxx))))))
#define SIGNIFICANT_DIGITS 11

extern int maximum_t_high_value;
extern int minimum_t_low_value;
#endif // END_EXTERNS

#if 0 // START_CLASS
int adco_arm_mths_to_reset;
double adco_arm_pay_rate;
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
adco_arm_mths_to_reset = 0;
adco_arm_pay_rate = 0;
#endif // END_CONSTRUCTOR

rebase_period = minimum_t_low_value - 1;

t_low = mtg->calculated_t_low;
t_high = mtg->calculated_t_high;

//parameterize the cash flow models.
if (this == mtg_cf)
	{
	dflt_appl = "Yes";
	prepmt_appl = "Yes";
	pv_tbl_defn = "No Tables";
	pv_timing = "Before Prepayments";
	pv_defn = "Cash Flows";
	shift_defn = "No Shift";
	use_spot_rates = "No";
	}

else if (this == mtg_pv)
	{
	dflt_appl = "No";
	prepmt_appl = "Yes";
	pv_tbl_defn = "No Tables";
	pv_timing = "End of Month";
	pv_defn = "Market Value";
	shift_defn = "No Shift";
	use_spot_rates = "Yes";
	}

else if (this == mtg_ym)
	{
	dflt_appl = "No";
	prepmt_appl = "No";
	pv_tbl_defn = "No Tables";
	pv_timing = "Before Prepayments";
	pv_defn = "Yield Maintenance";
	shift_defn = "No Shift";
	use_spot_rates = "No";
	}

// Setup experience rates pointer
if (!isRebaseClone)
	{
	mtg_pv->rates = rates;
	mtg_is->rates = rates;
	mtg_ym->rates = rates;

	#if defined(__INTEX_ASSET_H_)
	if (mtg->intex)
		{
		mtg_pv->intex = intex;
		mtg_is->intex = intex;
		mtg_ym->intex = intex;
		}
	#endif
	
	#if defined(__ADCO_ASSET_H_)
	if (mtg->adco)
		{
		mtg_pv->adco = adco;
		mtg_is->adco = adco;
		mtg_ym->adco = adco;
		}
	#endif
	}

return 1.0;

}


//@@ END

//@@ START - tranche_portion
// Tranche Portion                                                                                             
// Column:TRANCHE_PORTION
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_tranche_portion(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(40,"tranche_portion",t);
}



//^^^

#line 1 "tranche_portion.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

return tranche_portion_bef_sale(t)
	   * (1.0 - mtg->sold_pct(t));

}


//@@ END

//@@ START - tranche_portion_aft_dflt
// Tranche Portion After Defaults                                                                                             
// Column:TRANCHE_PORTION_AFT_DFLT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_tranche_portion_aft_dflt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(41,"tranche_portion_aft_dflt",t);
}



//^^^

#line 1 "tranche_portion_aft_dflt.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

return tranche_portion(t - 1)
	   * remaining_pct_aft_dflt(t);

}


//@@ END

//@@ START - tranche_portion_bef_sale
// Tranche Portion Before Sales                                                                                             
// Column:TRANCHE_PORTION_BEF_SALE
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_tranche_portion_bef_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(42,"tranche_portion_bef_sale",t);
}



//^^^

#line 1 "tranche_portion_bef_sale.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;
		
#if defined(__INTEX_ASSET_H_)
if (t == 0 && intex_proj_flag)
	{
	if (intex)
		{
		if (intex->get_tranche_bal(t) > model_point_amount_threshold)
			return par_val_bef_sale(t) / intex->get_tranche_bal(t);
		}

	return 0;
	}
#endif

return tranche_portion_aft_dflt(t);

}


//@@ END

//@@ START - yld_maint_cash_flow_pct_bef_prepmt
// Yield Maintenance Cash Flow Percent Before Prepayments                                                                                             
// Column:YLD_MAINT_CASH_FLOW_PCT_BEF_PREPMT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_yld_maint_cash_flow_pct_bef_prepmt(int t) {
//^^^



//^^^

#line 1 "yld_maint_cash_flow_pct_bef_prepmt.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

if (mtg->prepmt_penalty_defn != CASH_FLOW_MAINTENANCE
	|| this == mtg_cf
	|| pv_defn == NET_YIELD
	|| this == mtg_ym)
	return 1.0;

double yield_maintenance_cash_flow_factor = 0;

if (t == rebase_period + 1)
	yield_maintenance_cash_flow_factor = 1.0;
else
	{
	if (prepmt_appl == NO)
		yield_maintenance_cash_flow_factor
		= yld_maint_cash_flow_pct_bef_prepmt(t - 1);
	else
		yield_maintenance_cash_flow_factor
		= yld_maint_cash_flow_pct_bef_prepmt(t - 1)
		  * (1.0 - prepmt_pct_mthly(t - 1));
	}
	
return yield_maintenance_cash_flow_factor
	   * remaining_pct_aft_sched_pmt(t);

}


//@@ END

//@@ START - yld_maint_cost_pct
// Yield Maintenance Cost Percent                                                                                             
// Column:YLD_MAINT_COST_PCT
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_yld_maint_cost_pct(int t) {
//^^^



//^^^

#line 1 "yld_maint_cost_pct.MTG_CF_ASSET.for"
int months_remaining = mtg->maturity_period - t;

if (months_remaining == 0)
	return 1.0;

double bond_equivalent_payment_rate = 0;
double cost_factor = 0;
double maturity_amount = 0;
double yield_maintenance_present_value = 0;
double yield_plus_addn = max(0.0, yld_maint_rate(t) + mtg->yld_maint_addn);

if (pv_defn != CASH_FLOWS)
	bond_equivalent_payment_rate
	= convert_rate_basis(pmt_rate(t) + mtg->servicing_fee,
			  mtg->pmt_freq,
			  NOMINAL_SEMIANNUAL);

else
	{
	double int_rate_diff = 0;

	if (mtg->prepmt_int_diff_defn == GROSS_INTEREST_RATE)
		int_rate_diff
		= convert_rate_basis(pmt_rate(t) + mtg->servicing_fee, 
				  mtg->pmt_freq,
				  NOMINAL_SEMIANNUAL);
	else if (mtg->prepmt_int_diff_defn == INTEREST_RATE)
		int_rate_diff
		= convert_rate_basis(pmt_rate(t),
				  mtg->pmt_freq,
				  NOMINAL_SEMIANNUAL);
	else if (mtg->prepmt_int_diff_defn == NET_YIELD)
		int_rate_diff
		= convert_rate_basis(mtg->net_yld(t - 1), 12,
				  NOMINAL_SEMIANNUAL);

	bond_equivalent_payment_rate = int_rate_diff;
	}

if (mtg->prepmt_penalty_defn == YIELD_MAINTENANCE)
	{
	if (yield_plus_addn >= bond_equivalent_payment_rate)
		cost_factor = 1.0;
	else
		{
		int bond_equivalent_periods_to_maturity = 0;
		int local_months_per_payment_period = 0;
		int months_to_first_payment = 0;
		double adjustment_factor = 0;
		double discount_factor = 0;
		double growth_factor = 0;
		double monthly_discount_factor = 0;

		local_months_per_payment_period
		= 12 / NOMINAL_SEMIANNUAL;

		bond_equivalent_periods_to_maturity
		= (months_remaining + local_months_per_payment_period - 1)
		  / local_months_per_payment_period;

		months_to_first_payment
		= bond_equivalent_periods_to_maturity 
		  * local_months_per_payment_period
		  - months_remaining;

		discount_factor
		= pow(1.0 + bond_equivalent_payment_rate
					/ NOMINAL_SEMIANNUAL,
			  - bond_equivalent_periods_to_maturity);

		growth_factor
		= pow(1.0 + bond_equivalent_payment_rate
					/ NOMINAL_SEMIANNUAL,
			  (double) months_to_first_payment / local_months_per_payment_period);

		adjustment_factor
		= ((yield_plus_addn / bond_equivalent_payment_rate)
		   * (1.0 - discount_factor)
		   + discount_factor)
		  * growth_factor
		  - (pow(1.0 + yield_plus_addn / NOMINAL_SEMIANNUAL,
				 (double) months_to_first_payment / local_months_per_payment_period)
			 - 1.0);

		cost_factor = 1.0 / adjustment_factor;
		}
	}
else
	{
	if (mtg->prepmt_penalty_defn == CASH_FLOW_MAINTENANCE)
		{
		bool no_pv_tables = (pv_tbl_defn == NO_TABLES);
		bool initialize_yield_maintenance_pv_tables
			= !no_pv_tables && pv_initialize_yield_maintenance_table;
		bool dont_use_yield_maintenance_pv_tables
			= no_pv_tables || initialize_yield_maintenance_pv_tables;

		int adjusted_rebase_period = 0;
		int simple_pv_calculation = 0;
		double cost_factor_denominator = 0;
		double accr_int = 0;
		double par_val = 0;
		double temp = 0;
		int pv_detail_period
		= (this == mtg_cf ? t : max((int)mtg->commencement_period,(int)rebase_period));

#define YM_UPDATE 0 // 1 for output, 0 for none

#if YM_UPDATE
bool output_wanted = false;
if (t >= 12 && t <=14)
	output_wanted = true;

if (output_wanted)
	{
	PVCText.setf(ios::fixed);
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Yield Maintenance Cost Percent"
			<< " for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(mtg->cal_yr(t)) 
			<< " CalMth=" << xint(mtg->cal_mth(t));
	mtg->asset_detail_pv_output();
	}
#endif

		if (this == mtg_cf)
			adjusted_rebase_period = t;
		else if (this == mtg_pv)
			adjusted_rebase_period = mtg_pv->rebase_period;
		else
			{
			if (this == mtg_is)
				throw FatalError("this is mtg_is in mtg_cf->yld_maint_cost_pct");
			else if (this == mtg_ym)
				throw FatalError("this is mtg_ym in mtg_cf->yld_maint_cost_pct");
			else
				throw FatalError("this is unknown in mtg_cf->yld_maint_cost_pct");
			}

		bool has_been_rebased = false;

		if (mtg_ym->isShrunk)
			{
			mtg->rebase_cash_flow(adjusted_rebase_period,
						YIELD_MAINTENANCE,
						"mtg_cf->yld_maint_cost_pct", modelName);

			mtg_ym->pv_calc_parameters(t, YIELD_MAINTENANCE);

			has_been_rebased = true;
			}
		else if (mtg_ym->rebase_period < adjusted_rebase_period)
			{
			mtg->rebase_cash_flow(adjusted_rebase_period,
						YIELD_MAINTENANCE,
						"mtg_cf->yld_maint_cost_pct", modelName);

			mtg_ym->pv_calc_parameters(t, YIELD_MAINTENANCE);
			
			has_been_rebased = true;
			}

		if (!has_been_rebased && yield_plus_addn >= bond_equivalent_payment_rate)
			return 1.0;

		//          |<-                   ->|<- months_remaining ->|
		//          |-----------------------|----------------------|
		// adjusted_rebase_period			t				maturity_period (or reset period)
		adjusted_rebase_period
		= max(this->rebase_period, max((int)t_low, mtg->commencement_period));

		if (pv_defn == MARKET_VALUE_SHIFTED)
			mtg_ym->shift_defn = "Spot Shift";
		else
			mtg_ym->shift_defn = "No Shift";

		if (mtg->mths_to_next_reset(t) < mtg->maturity_period - t
			|| mtg->maturity_period > mtg->balloon_pmt_period
			|| mtg->servicing_fee != 0.0
			|| (t < mtg->amortzn_period
				&& mtg->amortzn_period < mtg->maturity_period)) 
			simple_pv_calculation = 0;
		else
			simple_pv_calculation = 1;    

		if (simple_pv_calculation)
			{
			accr_int = accr_int_bef_prepmt(t);
			par_val = par_val_aft_sched_pmt(t);
			cost_factor_denominator = par_val + accr_int;

			if (t >= mtg->amortzn_period)
				maturity_amount = 0.0;
			else if (mtg->amortzn_period >= mtg->maturity_period)
				maturity_amount = par_val;

			yield_maintenance_present_value
			= mtg_ym->pv_calc_simple(t,
					convert_rate_basis(yield_plus_addn,
							NOMINAL_SEMIANNUAL,
							mtg->pmt_freq),
					months_remaining,
					maturity_amount,
					pmt_amt_aft_sched_payment(t),
					mtg->pmt_freq, 
					0.0, temp, temp);
			}
		else
			{
			int adjustment_months = 0;

			if (pv_defn == MARKET_VALUE
				|| pv_defn == MARKET_VALUE_SHIFTED)
				{
				static double local_accrued_interest_before_sales = 0;
				static double local_par_value_before_sales = 0;

				if (t == adjusted_rebase_period)
					{
					local_par_value_before_sales
					= par_val_bef_sale(adjusted_rebase_period);

					local_accrued_interest_before_sales
					= accr_int_direct(adjusted_rebase_period,
								local_par_value_before_sales,
								pmt_rate(adjusted_rebase_period) + mtg->servicing_fee);
					}

				accr_int = local_accrued_interest_before_sales;
				par_val = local_par_value_before_sales;
				}
			else
				{
				par_val = par_val_aft_sched_pmt(t);
				accr_int = accr_int_direct(t, par_val, pmt_rate(t) + mtg->servicing_fee);
				}

			if (pv_defn != CASH_FLOWS)
				adjustment_months = t - adjusted_rebase_period;

			if (adjustment_months == 0)
				{
				if (dont_use_yield_maintenance_pv_tables)
					{
					cost_factor_denominator
					= par_val + accr_int;

					if (initialize_yield_maintenance_pv_tables)
						pv_yield_maintenance_par_plus_accrued[0]
						= cost_factor_denominator;
					}
				else
					cost_factor_denominator
					= pv_yield_maintenance_par_plus_accrued[0];
				}
			else
				{
				if (dont_use_yield_maintenance_pv_tables)
					{
					cost_factor_denominator
					= (mtg_ym->par_val_aft_sched_pmt(t)
					   + accr_int_direct(t, mtg_ym->par_val_aft_sched_pmt(t),
					   				mtg_ym->pmt_rate(t) + mtg->servicing_fee))
					  * yld_maint_cash_flow_pct_bef_prepmt(t);
					}
				else
					{
					cost_factor_denominator
					= pv_yield_maintenance_par_plus_accrued[t-adjusted_rebase_period-1]
					  * yld_maint_cash_flow_pct_bef_prepmt(t);
					}
				}

			if (cost_factor_denominator > 0.0)
				{
				// Discount at yield rate less spread.
				int month = 0;
				double servicing_amount = 0.0;
				double monthly_discount_factor = 0;
				double discounted_cash_flow = 0;

				double discount_factor = 1.0;

				monthly_discount_factor
				= 1.0 / (1.0 + convert_rate_basis(yield_plus_addn,
									   NOMINAL_SEMIANNUAL,
									   12) / 12.0);

#if YM_UPDATE
if (output_wanted)
	{
	PVCText << endl;
	PVCText << "YM-> t=," << t << endl
			<< "Adj_rebase_period," << adjusted_rebase_period << endl
			<< "Initialize_yield_maintenance_pv_tables," << initialize_yield_maintenance_pv_tables << endl
			<< "Dont_use_yield_maintenance_pv_tables," << dont_use_yield_maintenance_pv_tables << endl;
			<< endl;
	PVCText << "Pv_yield_maintenance_par_plus_accrued[m=0],"
			<< setw(18) << setprecision(7) << pv_yield_maintenance_par_plus_accrued[0]
			<< endl;
	PVCText << "Yld_maint_cash_flow_pct_bef_prepmt(t),"
			<< setw(10) << setprecision(7) << yld_maint_cash_flow_pct_bef_prepmt(t)
			<< endl;
	PVCText << "Period,Mth,PvYldMaintCF,PVYldMaintParPlusAccrued,DiscountedCF,DiscFactor" << endl;
	}
#endif

				if (dont_use_yield_maintenance_pv_tables)
					{
					if (initialize_yield_maintenance_pv_tables)
						{
						pv_yield_maintenance_par_plus_accrued[0]
						= mtg_ym->par_val_aft_sched_pmt(t)
						  + accr_int_direct(t, mtg_ym->par_val_aft_sched_pmt(t),
										mtg_ym->pmt_rate(t) + mtg->servicing_fee);
						}

					for (month = 1; month <= months_remaining; month++)
						{
						discount_factor *= monthly_discount_factor;

						if (mtg->mths_to_next_pmt(t + month - 1) == 1)
							servicing_amount
							= mtg_ym->par_val_aft_dflt(t + month) 
							   * mtg->servicing_fee 
							   / mtg->pmt_freq;
						else
							servicing_amount = 0.0;

						discounted_cash_flow
						= (mtg_ym->cash_flow(t + month) + servicing_amount)
						  * yld_maint_cash_flow_pct_bef_prepmt(t)
						  * discount_factor;

						yield_maintenance_present_value
						+= discounted_cash_flow;

						if (initialize_yield_maintenance_pv_tables)
							{
							pv_yield_maintenance_cash_flows[month-1]
							= mtg_ym->cash_flow(t + month) + servicing_amount;

							pv_yield_maintenance_par_plus_accrued[month]
							= mtg_ym->par_val_aft_sched_pmt(t + month)
							  + accr_int_direct(t + month, mtg_ym->par_val_aft_sched_pmt(t + month),
					   						mtg_ym->pmt_rate(t + month) + mtg->servicing_fee);

#if YM_UPDATE
if (output_wanted)
	{
//	if (month < 30 || month > months_remaining - 30)
		PVCText << t + month << ","
				<< setw(3) << month << ","
				<< setw(18) << setprecision(7) << pv_yield_maintenance_cash_flows[month - 1] << ","
				<< setw(18) << setprecision(7) << pv_yield_maintenance_par_plus_accrued[month] << ","
				<< setw(18) << setprecision(7) << discounted_cash_flow << ","
				<< setw(10) << setprecision(7) << discount_factor << ","
				<< endl;
	}
#endif

							}

						if (mtg_ym->par_val_aft_sched_pmt(t + month) == 0)
							break;
						}

					pv_initialize_yield_maintenance_table = false;
					}
				else // use yield maintenance tables
					{
					int offset = t - adjusted_rebase_period - 2;

					for (month = 1; month <= months_remaining; month++)
						{
						discount_factor *= monthly_discount_factor;

						discounted_cash_flow
						= pv_yield_maintenance_cash_flows[month + offset]
						  * yld_maint_cash_flow_pct_bef_prepmt(t)
						  * discount_factor;

						yield_maintenance_present_value
						+= discounted_cash_flow;

#if YM_UPDATE
if (output_wanted)
	{
//	if (month < 30 || month > months_remaining - 30)
		PVCText << setw(3) << t + month << ","
				<< setw(3) << month << ","
				<< setw(18) << setprecision(7) << pv_yield_maintenance_cash_flows[month + offset] << ","
				<< setw(18) << setprecision(7) << pv_yield_maintenance_par_plus_accrued[month + offset + 1] << ","
				<< setw(18) << setprecision(7) << discounted_cash_flow << ","
				<< setw(10) << setprecision(7) << discount_factor << ","
				<< endl;
	}
#endif

						if (pv_yield_maintenance_par_plus_accrued[month + offset + 1] == 0)
							break;
						}
					}
				}
			}

		if (cost_factor_denominator > 0.0)
			cost_factor
			= max(1.0, yield_maintenance_present_value
					   / cost_factor_denominator);
		else
			cost_factor = 1.0;

#if YM_UPDATE
if (output_wanted)
	{
	PVCText << " ... ympv=" << setw(18) << setprecision(7) << yield_maintenance_present_value
			<< " cst_fct_denom=" << setw(18) << setprecision(7) << cost_factor_denominator
			<< endl;
	PVCText << PVCounter
			<< "--> End Yield Maintenance Cost Percent ("
			<< write_string(cost_factor,PVCLen,PVCSigDig)
			<< ") for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(mtg->cal_yr(t)) 
			<< " CalMth=" << xint(mtg->cal_mth(t));
	mtg->asset_detail_pv_output();
	PVCounter--;
	}
#endif
		}
	}

return cost_factor;

}


//@@ END

//@@ START - yld_maint_rate
// Yield Maintenance Rate                                                                                             
// Column:YLD_MAINT_RATE
//========================================================
double MTG_CF_ASSET_UDF::mtg_cf_asset_yld_maint_rate(int t) {
//^^^



//^^^

#line 1 "yld_maint_rate.MTG_CF_ASSET.for"
if (t < mtg->commencement_period || t > mtg->maturity_period)
	return NO_AVG;

int scenario_month;
int valuation_period;

if (this == mtg_cf)
	valuation_period = t;
else
	valuation_period = max(rebase_period, mtg->commencement_period);

if (mtg->use_eom_scen_rates == YES
	|| (pv_defn != CASH_FLOWS
		&& pv_timing == END_OF_MONTH))
	scenario_month = 0;
else
	scenario_month = - 1;

if (this == mtg_cf)
	return rates->get_int_rate(t + scenario_month,
	                "Govt",
					GET_YIELD_RATE,
					(mtg->maturity_period - t) / 12.0,
					0.0,
					NOMINAL_SEMIANNUAL,
					NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

if (pv_defn == MARKET_VALUE_SHIFTED)
	return rates->get_int_rate(valuation_period + scenario_month,
	                "Govt",
	                GET_FORWARD_RATE,
					(t - valuation_period) / 12.0,
					(mtg->maturity_period - t) / 12.0,
					NOMINAL_SEMIANNUAL,
					SPOT_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

return rates->get_int_rate(valuation_period + scenario_month,
                "Govt",
                GET_FORWARD_RATE,
				(t - valuation_period) / 12.0,
				(mtg->maturity_period - t) / 12.0,
				NOMINAL_SEMIANNUAL,
				NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

}


//@@ END


#line 1 "accr_int_direct.MTG_CF_ASSET.for"                                                                                   
double MTG_CF_ASSET::accr_int_direct(int t, double par_val, double pmt_rate)
{
int local_pmt_mths = mtg->pmt_mths;

if (local_pmt_mths == 1)
	return 0;

int mths_since_last_pmt
= local_pmt_mths - (1 + ((mtg->maturity_period - t - 1) % local_pmt_mths));

if (mths_since_last_pmt == 0)
	return 0;

return par_val * (pow(1 + pmt_rate / mtg->pmt_freq,
					  (double)mths_since_last_pmt / (double)local_pmt_mths) - 1);
}



#line 1 "cash_flow.MTG_CF_ASSET.for"                                                                                   
double MTG_CF_ASSET::cash_flow(int t)
{
if (intex_proj_flag)
	return sched_prin_pmt(t)
	       + int_pmt(t)
	       + prepmt_amt(t);

if (prepmt_pct_mthly(t) == 0)
	return sched_prin_pmt(t)
		   + int_pmt(t)
		   + balloon_pmt_inc(t);

double local_prepmt_plus_balloon_inc = 0;

if (mtg->pmt_mode != MONTHLY
	&& mtg->mths_to_next_pmt(t - 1) > 1)
	local_prepmt_plus_balloon_inc
	= balloon_pmt_inc(t) + prepmt_inc(t);

return sched_prin_pmt(t)
	   + int_pmt(t)
	   + prepmt_amt(t)
	   + local_prepmt_plus_balloon_inc;
}



#line 1 "forecast_adco_adj_wac_rate.MTG_CF_ASSET.for"                                                                                   
void MTG_CF_ASSET::forecast_adco_adj_wac_rate(int t)
{
#if defined(__ADCO_ASSET_H_)
if (!adco)
	return;

int cal_yr = xint(mtg->cal_yr(t));
int cal_mth = xint(mtg->cal_mth(t));
int scn_mth = 0;
int idx = 0;
int histyr = 0;
int histmth = 0;
int issmth = 0;
int issyr = 0;
int purch_proj_mth = 0;
int offset = 0;

if (pv_timing == END_OF_MONTH
	|| mtg->use_eom_scen_rates == YES)
	scn_mth = 0;
else
	scn_mth = - 1;

if (mtg->existing_asset_indicator)
	offset = t;
else // Purchase asset
	{	
	purch_proj_mth = mtg->commencement_period + 1; 
	offset = t + 1 - purch_proj_mth;
	}

if (mtg->existing_asset_indicator && t == offset)
	{
	if (!is_asset_initialize)
		{	
		adco_arm_mths_to_reset = mtg->initial_values->mths_to_next_reset;
		adco_arm_pay_rate = mtg->initial_values->pmt_rate;
		}
	else
		{
		adco_arm_mths_to_reset = mtg->mths_to_next_reset(0);
		adco_arm_pay_rate = pmt_rate(0);
		}
	}
else if (!mtg->existing_asset_indicator && t == mtg->commencement_period + offset)
	{
	adco_arm_mths_to_reset = mtg->mths_to_next_reset(mtg->commencement_period);
	adco_arm_pay_rate = mtg->pmt_rate_at_issue;
	}

int mths_to_reset = adco_arm_mths_to_reset;
int reset = 0;
double priorrate = 0.0;
double renrate = 0.0;

// Start at 0 since wac[0] is rate at first forecast month
for (int month = 1; month <= 600; month++)
	{
	if (month == 1)
		priorrate = adco_arm_pay_rate;

	if (mths_to_reset == 1)
		reset = 1;
	else
		reset = 0;

	if (reset == 1)
		mths_to_reset = mtg->adj_reset_mths;
	else
		mths_to_reset -=1;

	adco->arm_wac_rates[month - 1] = (priorrate + mtg->servicing_fee) * 100.0;

 	if (pv_defn != CASH_FLOWS)
		{
		if (pv_defn == NET_YIELD)
			{
			if (month <= offset) // use past actual renewal rates
				renrate
				= rates->get_int_rate(t + scn_mth - offset + month,
				            mtg->adj_reset_category_id,
							GET_YIELD_RATE,
							mtg->adj_reset_scen_yr,
							0.0,
							mtg->pmt_freq,
							shift_defn,mtg->portfolio_sprd_adj_aig)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
				  * mtg->adj_reset_scen_mult
				  + mtg->adj_reset_renewal_addn;
            else // use current renewal rate
				renrate
				= rates->get_int_rate(t + scn_mth,
				            mtg->adj_reset_category_id,
							GET_YIELD_RATE,
							mtg->adj_reset_scen_yr,
							0.0,
							mtg->pmt_freq,
							shift_defn,mtg->portfolio_sprd_adj_aig)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
				  * mtg->adj_reset_scen_mult
				  + mtg->adj_reset_renewal_addn;
			}
		else // MV calculation
			{
			if (month <= offset) // use past actual renewal rates
				renrate
				= rates->get_int_rate(t + scn_mth - offset + month,
				            mtg->adj_reset_category_id,
							GET_YIELD_RATE,
							mtg->adj_reset_scen_yr,
							0.0,
							mtg->pmt_freq,
							NO_SHIFT,mtg->portfolio_sprd_adj_aig)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
				* mtg->adj_reset_scen_mult
				+ mtg->adj_reset_renewal_addn;
			else // use forward renewal rates
				{
				renrate
				= convert_rate_basis(rates->get_int_rate(t + scn_mth,
				                            mtg->adj_reset_category_id,
				                            GET_FORWARD_RATE,
											(month-offset) * (1.0 / 12.0),
											mtg->adj_reset_scen_yr,
											NOMINAL_SEMIANNUAL,
											shift_defn,mtg->portfolio_sprd_adj_aig),//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
						NOMINAL_SEMIANNUAL,
						mtg->pmt_freq)
				  * mtg->adj_reset_scen_mult
				  + mtg->adj_reset_renewal_addn;
				}
			}
		}
	else // Initial setup - use actual renewal rates
		renrate
		= rates->get_int_rate(t + scn_mth - offset + month,
		            mtg->adj_reset_category_id,
					GET_YIELD_RATE,
					mtg->adj_reset_scen_yr,
					0.0,
					mtg->pmt_freq,
					shift_defn,mtg->portfolio_sprd_adj_aig)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
		  * mtg->adj_reset_scen_mult
		  + mtg->adj_reset_renewal_addn;

	if (reset)
		renrate
		= min(min(max(max(renrate, priorrate
                                   - mtg->adj_max_decr_per_reset)
                          , mtg->adj_min_rate)
                      , priorrate
                        + mtg->adj_max_incr_per_reset)
                   , mtg->adj_max_rate);
	else
		renrate = priorrate;

	priorrate = renrate;
	}
#endif
}



#line 1 "pv_calc.MTG_CF_ASSET.for"                                                                                   
double MTG_CF_ASSET::pv_calc(int t, double spread_to_spot, double &calculated_derivative, double &calculated_modified_duration)
{
int scen_frequency = NOMINAL_SEMIANNUAL;
bool capture_pv_detail = (mtg->asset_detail_pv_flag(t)
						&& mtg->asset_detail_rpt_pv_defn == YES);
double calculated_present_value = 0.0;

//initialize "passed by reference" parameters
calculated_derivative = 0;
calculated_modified_duration = 0;

//Setup variables
bool use_pv_tables = (pv_tbl_defn == USE_TABLES);
bool initialize_pv_tables = (pv_tbl_defn == INITIALIZE_TABLES);
bool pv_simple_calculation = pv_simple_flag(t);

if (!use_pv_tables)
	pv_calc_init_val(t);

double local_years_from_payment_to_end_of_payment_month
= - pv_initial_years_to_payment;

if (mtg->asset_detail_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Present Value Calculation (" << pv_tbl_defn
			<< ") for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(mtg->cal_yr(t)) 
			<< " CalMth=" << xint(mtg->cal_mth(t));
	mtg->asset_detail_pv_output();

	if (capture_pv_detail)
		{
		PVCFile << "SimplePVCalculation," << (pv_simple_calculation ? "Yes" : "No") << endl
				<< "PVTiming," << pv_timing	<< endl
				<< "ShiftDefn," << shift_defn << endl
				<< "UseSpotRates," << use_spot_rates << endl
				<< "SpreadtoSpot," << write_string(spread_to_spot,PVCLen,PVCSigDig) << endl
				<< "PVMonths," << pv_months << endl
				<< "ParValue,"	<< write_string(pv_initial_par_value,PVCLen,PVCSigDig) << endl
				<< "AccruedInterest," << write_string(pv_initial_accrued_interest,PVCLen,PVCSigDig) << endl
				<< "YrsFromPmtToEOM," << write_string(-pv_initial_years_to_payment,PVCLen,PVCSigDig) << endl
				<< "TablesOption," << pv_tbl_defn << endl;
		}
	}

if (use_spot_rates == NO && pv_simple_calculation)
	{
	double local_periodic_payment_amount
	= mtg->pmt_amt(t,
				pv_initial_par_value,
				xint(mtg->maturity_period - t),
				mtg->pmt_freq,
				mtg_cf->pmt_rate(t),
				mtg->amortzn_period);

	double local_maturity_amount = 0;

	if (t < mtg->amortzn_period)
		local_maturity_amount = pv_initial_par_value;

	calculated_present_value
	= pv_calc_simple(t,
			convert_rate_basis(spread_to_spot,
					scen_frequency,
					mtg->pmt_freq),
			mtg->maturity_period - t,
			local_maturity_amount,
			local_periodic_payment_amount,
			mtg->pmt_freq,
			pv_initial_accrued_interest,
			calculated_derivative,
			calculated_modified_duration);
	}
else
	{
	if (capture_pv_detail)
		{
		if (prepmt_appl == YES)
			adco_prepmt_forecast(t);

		PVCFile << "Present Value Detail" << endl;
		if (use_pv_tables)
			PVCFile << "Mth,YrsToPmt,DiscRate,DiscFact,CashFlow,DiscCF,TimeWgthdDiscCF,CalcPV,CalcDer" << endl;
		else
			PVCFile << "Mth,YrsToPmt,DiscRate,DiscFact,CashFlow,DiscCF,TimeWghtdDiscCF,CalcPV,CalcDer,IntRat,IntPmt,ScPrinPmt,OtherPmts" << endl;
		}

	int month = t;
	bool done = false;
	double spot_rate = 0.0;
	double local_discount_rate = 0.0;
	double local_discount_factor = 0.0;
	double local_cash_flow = 0.0;
	double local_discounted_cash_flow = 0.0;
	double local_time_weighted_discounted_cash_flow = 0.0;
	double payoff_amount = 0.0;
	double monthly_discount_factor = 0.0;
	double years_to_payment = pv_initial_years_to_payment;

	if (use_spot_rates == NO)
		{
		monthly_discount_factor
		= pow(1.0 + spread_to_spot / scen_frequency, 
		      - (1.0 / 12.0) * scen_frequency); 

		local_discount_factor 
		= pow(1.0 + spread_to_spot / scen_frequency, 
		      - years_to_payment * scen_frequency);
		}

	if (this->isShrunk)
		{
		log_screen << "Error. t=" << t
				<< " " << (this==mtg_cf ? "mtg_cf"
							: (this==mtg_pv ? "mtg_pv"
							: (this==mtg_is ? "mtg_is"
							: (this==mtg_ym ? "mtg_ym" : "???"))))
				<< " is shrunk in pv_calc |" << modelName
				<< MSG_ERROR;
		throw FatalError("");
		}

	// discount cash flows
	if (!use_pv_tables)
		{
		bool final_month = false;

		while (month < t + pv_months && !done)
			{
			month ++;

			if (use_spot_rates == NO)
				local_discount_rate = spread_to_spot;
			else
				{
				spot_rate
				= rates->get_int_rate(t, 
				              mtg->category_id, 
				              GET_SPOT_RATE,
				              (month - t) / 12.0,
				              0.0,
				              NOMINAL_SEMIANNUAL,
				              shift_defn,mtg->portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

				local_discount_rate
				= spot_rate + spread_to_spot;
				}

			years_to_payment += 1.0/12.0;

			if (use_spot_rates == NO)
				local_discount_factor
				*= monthly_discount_factor;
			else
				local_discount_factor
				= pow(1.0 + local_discount_rate / scen_frequency,
						  - years_to_payment * scen_frequency);

			final_month = (month == t + pv_months);

			if (final_month
				&& month < mtg->maturity_period)
				{
				if (intex_proj_flag)
					payoff_amount
					= par_val_aft_prepmt(month);
				else
					payoff_amount
					= par_val_aft_sched_pmt(month);
				}

			local_cash_flow = cash_flow(month);

			local_discounted_cash_flow
			= (local_cash_flow + payoff_amount)
			  * local_discount_factor;

			if (initialize_pv_tables)
				{
				pv_cash_flows[month - t - 1]
				= local_cash_flow + payoff_amount;

				if (pv_initialize_interest_savings_table
					&& !final_month)
					pv_interest_savings_after_prepayments[month-t]
					= int_savings_pv_aft_prepmt(month);

				if (par_val_aft_prepmt(month) <= 0.0
					|| final_month)
					{
					pv_last_cash_flow_month = month;
					done = true;
					}
				}
			else if (par_val_aft_prepmt(month) <= 0.0)
				done = true;

			local_time_weighted_discounted_cash_flow
			= years_to_payment * local_discounted_cash_flow;

			calculated_derivative
			-= local_time_weighted_discounted_cash_flow
			   / (1.0 + local_discount_rate
						/ NOMINAL_SEMIANNUAL);

			calculated_present_value
			+= local_discounted_cash_flow;

			if (capture_pv_detail)
				PVCFile << month - t << ","
						<< years_to_payment << ","
						<< local_discount_rate << ","
						<< local_discount_factor << ","
						<< local_cash_flow + payoff_amount << ","
						<< local_discounted_cash_flow << ","
						<< local_time_weighted_discounted_cash_flow << ","
						<< calculated_present_value << ","
						<< calculated_derivative << ","
						<< pmt_rate(month) << ","
						<< int_pmt(month) << ","
						<< sched_prin_pmt(month) << ","
						<< prepmt_amt(month) + balloon_pmt_inc(month) + prepmt_inc(month) << endl;
			}

		if (initialize_pv_tables)
			pv_tbl_defn = "Use Tables";
		}

	// discount cash flows
	else // if (use_pv_tables)
		{
		while (month < t + pv_months && !done)
			{
			month ++;
	
			if (use_spot_rates == NO)
				local_discount_rate = spread_to_spot;
			else
				{
				spot_rate
				= rates->get_int_rate(t, 
				              mtg->category_id, 
				              GET_SPOT_RATE,
				              (month - t) / 12.0,
				              0.0,
				              NOMINAL_SEMIANNUAL,
				              shift_defn,mtg->portfolio_sprd_adj_aig);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
				
				local_discount_rate
				= spot_rate + spread_to_spot;
				}

			years_to_payment += 1.0/12.0;

			if (use_spot_rates == NO)
				local_discount_factor
				*= monthly_discount_factor;
			else
				local_discount_factor
				= pow(1.0 + local_discount_rate / scen_frequency,
						  - years_to_payment * scen_frequency);

			local_discounted_cash_flow
			= pv_cash_flows[month - t - 1]
			  * local_discount_factor;

			if (pv_last_cash_flow_month == month)
				done = true;

			local_time_weighted_discounted_cash_flow
			= years_to_payment * local_discounted_cash_flow;

			calculated_derivative
			-= local_time_weighted_discounted_cash_flow
			   / (1.0 + local_discount_rate
						/ NOMINAL_SEMIANNUAL);
	
			calculated_present_value
			+= local_discounted_cash_flow;

			if (capture_pv_detail)
				PVCFile << month - t << ","
						<< years_to_payment << ","
						<< local_discount_rate << ","
						<< local_discount_factor << ","
						<< pv_cash_flows[month-t-1] << ","
						<< local_discounted_cash_flow << ","
						<< local_time_weighted_discounted_cash_flow << ","
						<< calculated_present_value << ","
						<< calculated_derivative << endl;
			}
		}

	calculated_modified_duration
	= -calculated_derivative
	   / calculated_present_value;

	//adjust for accrued interest
	calculated_present_value
	-= pv_initial_accrued_interest;
	}

if (mtg->asset_detail_pv_flag(t))
	{
	if (capture_pv_detail)
		PVCFile << "NetPresentValue," << write_string(calculated_present_value,PVCLen,PVCSigDig) << endl
				<< "Derivative," << write_string(calculated_derivative,PVCLen,PVCSigDig) << endl
				<< "ModifiedDuration," << write_string(calculated_modified_duration,PVCLen,PVCSigDig) << endl;

	int cal_year = mtg->cal_yr_relative(t);
	int cal_month = mtg->cal_mth(t);

	PVCText << PVCounter
			<< "<--End Present Value Calculation ("
			<< write_string(calculated_present_value,PVCLen,PVCSigDig)
			<< ") for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(mtg->cal_yr(t)) 
			<< " CalMth=" << xint(mtg->cal_mth(t));
	mtg->asset_detail_pv_output();
	PVCounter--;
	}

return calculated_present_value;
}



#line 1 "pv_calc_init_val.MTG_CF_ASSET.for"                                                                                   
void MTG_CF_ASSET::pv_calc_init_val(int t)
// DO NOT combine with other formulas.
{
if (pv_timing == END_OF_MONTH)
	{
	pv_initial_years_to_payment = 0;

	if (pv_defn == NET_YIELD
		&& intex_proj_flag)
		pv_initial_accrued_interest = 0;
	else
		pv_initial_accrued_interest = accr_int_bef_sale(t);

	pv_initial_par_value = par_val_bef_sale(t);
	}

else if (pv_timing == BEFORE_PREPAYMENTS)
	{
	pv_initial_years_to_payment = 0;
	pv_initial_accrued_interest = mtg_cf->accr_int_bef_prepmt(t);
	pv_initial_par_value = mtg_cf->par_val_aft_sched_pmt(t);
	}

else if (pv_timing == AFTER_PREPAYMENTS)
	{
	pv_initial_years_to_payment = 0;
	pv_initial_accrued_interest = mtg_cf->accr_int_aft_prepmt(t);

	if (mtg->existing_asset_indicator
		|| (!mtg->existing_asset_indicator && t > mtg->commencement_period))
		pv_initial_par_value = mtg_cf->par_val_bef_sale(t);
	else
		pv_initial_par_value = mtg_pv->par_val_bef_sale(t);
	}

else
	throw FatalError("Invalid PV timing passed into pv_calc function.");

return;
}



#line 1 "pv_calc_parameters.MTG_CF_ASSET.for"                                                                                   
void MTG_CF_ASSET::pv_calc_parameters(int t, StrEnum::EnumValue command, int present_value_term )
// --------------------------------------
// Valid command values are:
//	"Cash Flows"
//	"Market Value"
//	"Market Value Shifted"
//	"Net Yield"
//	"Interest Savings Before Prepayments"
//	"Interest Savings After Prepayments"
//	"Yield Maintenance"
//	"Save"
//	"Restore"
// --------------------------------------
{
if (command == CASH_FLOWS)
	{
	dflt_appl = "Yes";
	prepmt_appl = "Yes";
	pv_tbl_defn = "No Tables";
	pv_timing = "Before Prepayments";
	pv_defn = "Cash Flows";
	shift_defn = "No Shift";
	use_spot_rates = "No";

	pv_initialize_interest_savings_table = false;
	pv_months = present_value_term;

	return;
	}

if (command == MARKET_VALUE)
	{
	dflt_appl = "No";

	if (mtg->prepmt_first_period < mtg->maturity_period)
		{
		prepmt_appl = "Yes";
		pv_initialize_interest_savings_table = true;
		}
	else
		{
		prepmt_appl = "No";
		pv_initialize_interest_savings_table = false;
		}

	if (present_value_term > 0)
		{
		pv_tbl_defn = "Initialize Tables";
		// resize pv tables, if necessary
		if (pv_cash_flows.size() < present_value_term)
			{
			pv_cash_flows.resize(present_value_term);
			pv_interest_savings_after_prepayments.resize(present_value_term);
			}
		if (pv_yield_maintenance_cash_flows.size() < present_value_term)
			{
			pv_yield_maintenance_cash_flows.resize(present_value_term);
			pv_yield_maintenance_par_plus_accrued.resize(present_value_term);
			}
		}
	else
		pv_tbl_defn = "No Tables";

	pv_timing = "End of Month";	
	pv_defn = "Market Value";
	shift_defn = "No Shift";
	use_spot_rates = "Yes";

	pv_months = present_value_term;

	return;
	}

if (command == MARKET_VALUE_SHIFTED)
	{
	dflt_appl = "No";

	if (mtg->prepmt_first_period < mtg->maturity_period)
		prepmt_appl = "Yes";
	else
		prepmt_appl = "No";

	pv_tbl_defn = "Initialize Tables";
	pv_timing = "End of Month";
	pv_defn = "Market Value Shifted";
	shift_defn = "Spot Shift";
	use_spot_rates = "Yes";

	pv_initialize_interest_savings_table = false;
	pv_months = present_value_term;

	return;
	}

if (command == NET_YIELD)
	{
	dflt_appl = "No";
	prepmt_appl = "No";

	if (present_value_term > 0)
		{
		pv_tbl_defn = "Initialize Tables";
		// resize pv tables, if necessary
		if (pv_cash_flows.size() < present_value_term)
			{
			pv_cash_flows.resize(present_value_term);
			pv_interest_savings_after_prepayments.resize(present_value_term);
			}
		if (pv_yield_maintenance_cash_flows.size() < present_value_term)
			{
			pv_yield_maintenance_cash_flows.resize(present_value_term);
			pv_yield_maintenance_par_plus_accrued.resize(present_value_term);
			}
		}
	else
		pv_tbl_defn = "No Tables";

	pv_timing = "After Prepayments";
	pv_defn = "Net Yield";
	shift_defn = "No Shift";
	use_spot_rates = "No";

	pv_initialize_interest_savings_table = false;
	pv_months = present_value_term;

	return;
	}

if (command == INTEREST_SAVINGS_BEFORE_PREPAYMENTS)
	{
	dflt_appl = "No";
	prepmt_appl = "No";
	pv_tbl_defn = "No Tables";
	pv_timing = "Before Prepayments";
	pv_defn = "Interest Savings Before Prepayments";
	shift_defn = "No Shift";
	use_spot_rates = "No";

	pv_initialize_interest_savings_table = false;
	pv_months = present_value_term;

	return;
	}

if (command == INTEREST_SAVINGS_AFTER_PREPAYMENTS)
	{
	dflt_appl = "No";
	prepmt_appl = "No";
	pv_tbl_defn = "No Tables";
	pv_timing = "After Prepayments";
	pv_defn = "Interest Savings After Prepayments";
	shift_defn = "No Shift";
	use_spot_rates = "No";

	pv_initialize_interest_savings_table = false;
	pv_months = present_value_term;

	return;
	}

if (command == YIELD_MAINTENANCE)
	{
	dflt_appl = "No";
	prepmt_appl = "No";
	pv_tbl_defn = "No Tables";
	pv_timing = "Before Prepayments";
	pv_defn = "Yield Maintenance";
	shift_defn = "No Shift";
	use_spot_rates = "No";

	return;
	}

static xstring include_defaults_saved = "";
static xstring include_prepayments_saved = "";
static xstring pv_timing_saved = "";
static xstring shift_defn_saved = "";
static xstring use_spot_rates_saved = "";
static xstring pv_table_option_saved = "";
static double pv_months_saved = 0;
static xstring pv_type_saved = "";
static bool pv_initialize_interest_savings_table_saved = false;
static double pv_initial_years_to_payment_saved = 0;
static double pv_initial_accrued_interest_saved = 0;
static double pv_initial_par_value_saved = 0;

if (command == SAVE)
	{
	include_defaults_saved = dflt_appl;
	include_prepayments_saved = prepmt_appl;
	pv_table_option_saved = pv_tbl_defn;
	pv_timing_saved = pv_timing;
	pv_type_saved = pv_defn;
	shift_defn_saved = shift_defn;
	use_spot_rates_saved = use_spot_rates;

	pv_initialize_interest_savings_table_saved = pv_initialize_interest_savings_table;
	pv_months_saved = pv_months;

	pv_initial_years_to_payment_saved = pv_initial_years_to_payment;
	pv_initial_accrued_interest_saved = pv_initial_accrued_interest;
	pv_initial_par_value_saved = pv_initial_par_value;

	return;
	}

if (command == RESTORE)
	{
	dflt_appl = include_defaults_saved;
	prepmt_appl = include_prepayments_saved;
	pv_tbl_defn = pv_table_option_saved;
	pv_timing = pv_timing_saved;
	shift_defn = shift_defn_saved;
	pv_defn = pv_type_saved;
	use_spot_rates = use_spot_rates_saved;

	pv_initialize_interest_savings_table = pv_initialize_interest_savings_table_saved;
	pv_months = pv_months_saved;

	pv_initial_years_to_payment = pv_initial_years_to_payment_saved;
	pv_initial_accrued_interest = pv_initial_accrued_interest_saved;
	pv_initial_par_value = pv_initial_par_value_saved;

	return;
	}

throw FatalError("Unrecognized command code '" + (xstring)command
				+ "' in mtg_cf->pv_calc_parameters");

return;
}



#line 1 "pv_calc_simple.MTG_CF_ASSET.for"                                                                                   
double MTG_CF_ASSET::pv_calc_simple(int t, double nominal_yield, int months_to_maturity, double maturity_amount, double periodic_payment_amount, int pmt_freq, double accr_int, double &calculated_derivative, double &calculated_modified_duration)
{
// Local Variables
double sum_of_discount_factors = 0;
double sum_of_discount_factors_times_periods_to_cash_flow = 0;

int pmt_mths = 12 / pmt_freq;

int months_to_next_payment_local
= 1 + (months_to_maturity - 1)
	  % pmt_mths;

int months_since_last_payment_date
= pmt_mths - months_to_next_payment_local;

int payments_remaining
= 1 + (months_to_maturity - months_to_next_payment_local)
	  / pmt_mths;

double periodic_discount = 1.0 / (1.0 + nominal_yield / pmt_freq);

double duration_adjustment
= (months_since_last_payment_date / 12.0)
  * pmt_freq;

double appreciation_factor
= pow(1.0 + nominal_yield / pmt_freq, duration_adjustment);

double discount_factor_to_maturity 
= pow(periodic_discount, payments_remaining);

if (periodic_discount != 1.0)
	sum_of_discount_factors
	= periodic_discount * (1.0 - discount_factor_to_maturity)
						/ (1.0 - periodic_discount);
else
	sum_of_discount_factors = payments_remaining;

double pv_of_periodic_payments 
= appreciation_factor * periodic_payment_amount * sum_of_discount_factors;

double pv_of_maturity_amount
= appreciation_factor * maturity_amount * discount_factor_to_maturity;

double calculated_present_value 
= pv_of_periodic_payments 
  + pv_of_maturity_amount
  - accr_int;

if (periodic_discount != 1.0)
	sum_of_discount_factors_times_periods_to_cash_flow
	= (sum_of_discount_factors
	   - payments_remaining 
		 * periodic_discount
		 * discount_factor_to_maturity)
	  / (1.0 - periodic_discount);
else
	sum_of_discount_factors_times_periods_to_cash_flow
	= payments_remaining * (payments_remaining + 1.0) / 2.0;

calculated_derivative
= -appreciation_factor
   * (periodic_payment_amount
	  * (sum_of_discount_factors_times_periods_to_cash_flow
		 - duration_adjustment * sum_of_discount_factors)
	  + maturity_amount 
		* (payments_remaining - duration_adjustment)
		* discount_factor_to_maturity)
	 / ((1.0 + convert_rate_basis(nominal_yield, pmt_freq,
					   NOMINAL_SEMIANNUAL)
			   / NOMINAL_SEMIANNUAL)
		* pmt_freq);

calculated_modified_duration
= -calculated_derivative
   / (pv_of_periodic_payments + pv_of_maturity_amount)
   * pow(periodic_discount, pmt_freq - 1);

// use rebase_period to reduce sliding windows size
if (mtg->asset_detail_pv_flag(rebase_period))
   	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Present Value Calculation Simple"
			<< " for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(mtg->cal_yr(t)) 
			<< " CalMth=" << xint(mtg->cal_mth(t));
	mtg->asset_detail_pv_output();

	if (mtg->asset_detail_rpt_pv_defn == YES)
		{
		PVCFile << "AccInt," << accr_int << endl
				<< "MthsToMat," << months_to_maturity << endl
				<< "MatAmt," << maturity_amount << endl
				<< "PmtAmt," << periodic_payment_amount << endl
				<< "PmtFreq," << pmt_freq << endl
				<< "Yld," << convert_rate_basis(nominal_yield, pmt_freq, NOMINAL_SEMIANNUAL) << endl
				<< "YrsToEndOfPmtMth," << 0 << endl
				<< "MonthsPerPaymentPeriod," << pmt_mths  << endl
				<< "MonthsToNextPayment," << months_to_next_payment_local << endl
				<< "MonthsSinceLastPaymentDate," << months_since_last_payment_date << endl
				<< "PaymentsRemaining," << payments_remaining << endl
				<< "PeriodicDiscount," << periodic_discount << endl
				<< "DurationAdjustment," << duration_adjustment << endl
				<< "AppreciationFactor," << appreciation_factor << endl
				<< "DiscountFactorToMaturity," << discount_factor_to_maturity << endl
				<< "SumOfDiscountFactors," << sum_of_discount_factors << endl
				<< "PVofPeriodicPayments," << pv_of_periodic_payments << endl
			    << "PVofMaturityAmount," << pv_of_maturity_amount << endl
				<< "SumOfDiscountFactorsTimesPeriodsToCashFlow," << sum_of_discount_factors_times_periods_to_cash_flow << endl;
		}

	PVCText << PVCounter
			<< "<--End Present Value Calculation Simple ("
			<< write_string(calculated_present_value,PVCLen,PVCSigDig)
			<< ") for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(mtg->cal_yr(t)) 
			<< " CalMth=" << xint(mtg->cal_mth(t));
	mtg->asset_detail_pv_output();
	PVCounter--;
	}

return calculated_present_value;
}



#line 1 "pv_simple_flag.MTG_CF_ASSET.for"                                                                                   
bool MTG_CF_ASSET::pv_simple_flag(int t)
// DO NOT combine with other formulas.
{
if (intex_proj_flag
	|| (prepmt_appl == YES
		|| mtg->mths_to_next_reset(t) < mtg->maturity_period - t
		|| mtg->balloon_pmt_flag == YES
		|| mtg->servicing_fee != 0.0
		|| (t < mtg->amortzn_period
			&& mtg->amortzn_period < mtg->maturity_period)
		|| mtg->prepmt_penalty_defn == CASH_FLOW_MAINTENANCE))
	return false;

return true;
}



#line 1 "setup_adco_submodel_parameters.MTG_CF_ASSET.for"                                                                                   
void MTG_CF_ASSET::setup_adco_submodel_parameters(int t)
{
#if defined(__ADCO_ASSET_H_)
if (!adco)
	return;

if (prepmt_rate.size() < 601)
	prepmt_rate.resize(601);

for(int i = 0; i <= 600; i++)
	prepmt_rate[i] = 0.0;

StrEnum::EnumValue forecast_type = UNDEFINED;

if (this == mtg_cf)
	forecast_type = EXPERIENCE;
else if (pv_defn == NET_YIELD)
	forecast_type = NET_YIELD;
else if (pv_defn == MARKET_VALUE
		 || pv_defn == MARKET_VALUE_SHIFTED)
	forecast_type = MARKET_VALUE;

// Only setup ADCO parameters if required
if (mtg->asset_id != adco->asset_id
	|| mtg->commencement_period != adco->commencement_period
	|| forecast_type != adco->prepmt_forecast_defn
	|| shift_defn != adco->shift_defn
	|| pv_timing != adco->pv_timing
	|| t != adco->valuation_period
    || (t == 0 && this == mtg_cf)) // force recaculation after anticipated yield calculation
	{
	adco->resetValues();
  
	// Projection parameters
	adco->prepmt_model_defn = "MBS";
	adco->asset_proj_defn = "USLIB";
	adco->prepmt_forecast_defn = forecast_type;
	adco->valuation_period = t;
    adco->valn_date_offset_mths = 0;
	adco->use_eom_scen_rates = get_string_of_enum_val(mtg->use_eom_scen_rates);
	adco->shift_defn = shift_defn;
	adco->pv_timing = xstring(pv_timing);

	// Asset parameters
	adco->asset_id = mtg->asset_id;
	adco->category_id = mtg->adco_category_id;
	adco->mbs_collateral_defn = xstring(mtg->adco_collateral_defn);
	adco->adjustable_rate_defn = xstring(mtg->adco_adj_rate_defn);
	adco->subprime_defn = xstring(mtg->adco_subprime_defn);
	adco->existing_asset_indicator = mtg->existing_asset_indicator;
	adco->commencement_period = mtg->commencement_period;
    adco->coupon = (pmt_rate(t) + mtg->servicing_fee) * 100.0;
	adco->ms_rereadGrid();
	
	adco->interest_only_mths = max(0, (mtg->amortzn_start_cy 
	                                   - get_yr_from_date(mtg->issue_date)) * 12);
	
	adco->servicing_fee = mtg->servicing_fee * 100.0;
	
	if (mtg->existing_asset_indicator)
		{
		int init_mths_since_issue = mtg->init_mths_since_issue;
		
		adco->age = init_mths_since_issue;
		adco->original_face = mtg->par_val_at_issue;
		adco->current_face = par_val_bef_sale(t);
		adco->original_term = mtg->maturity_period + init_mths_since_issue;
		adco->remaining_term = mtg->maturity_period;

		// Determine number of months from origination the loan has a prepay penalty
		if (mtg->prepmt_penalty_defn == NOT_APPLICABLE)
			adco->prepmt_penalty_mths = 0;
		else if (mtg->prepmt_penalty_defn == PENALTY_PERCENT)
			{
			// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
			int month;
			for (month = 1; month <= mtg->maturity_period; month++)
	   			{
		   		if (fabs(mtg->prepmt_penalty_sch[month]) < model_point_amount_threshold)
	    	   		break;
		   		}
		
			adco->prepmt_penalty_mths = month + init_mths_since_issue;
			}
		else
			adco->prepmt_penalty_mths = init_mths_since_issue + mtg->maturity_period;

		if (mtg->balloon_pmt_period < mtg->maturity_period)
            adco->balloon_term = mtg->balloon_pmt_period + init_mths_since_issue;
		else
			adco->balloon_term = 0;	
		}
	else // purchase asset
		{
		adco->age = 0;
		
		if (forecast_type == MARKET_VALUE // for new purchase we need to determine the face amt by 
			&& t == mtg->commencement_period)// calculating MKT val, so we give ADCO an arbitrary face of one million
			adco->original_face = max(ONE_MILLION, fabs(mtg->purch_amt));
			
		adco->current_face = adco->original_face;
		adco->original_term = mtg->maturity_period - mtg->commencement_period;
		adco->remaining_term = mtg->maturity_period - mtg->commencement_period;
		
        // Set number of months from origination the loan has a prepay penalty
		adco->prepmt_penalty_mths = mtg->prepmt_par_first_period - mtg->commencement_period;

		if (mtg->balloon_pmt_period < mtg->maturity_period)
            adco->balloon_term = mtg->balloon_pmt_period - mtg->commencement_period;
		else
			adco->balloon_term = 0;	
		} 
        
	if (mtg->pmt_rate_defn == FLOATING_RATE /* ARM collateral type */)
		{
		adco->mbs_prepmt_defn = "ARM";
		adco->arm_flag = YES;
	    adco->arm_reset_scen_yr = mtg->adj_reset_scen_yr;
		adco->arm_reset_mths = mtg->adj_reset_mths;
        adco->arm_min_rate = mtg->adj_min_rate * 100.0;
        adco->arm_max_rate = mtg->adj_max_rate * 100.0;

		adco->arm_max_reset_period_rate 
		= ((pmt_rate(t) + mtg->servicing_fee)
           + mtg->adj_max_incr_per_reset
           - mtg->servicing_fee) * 100.0;

		adco->arm_min_reset_period_rate 
		= max(0.0, ((pmt_rate(t) + mtg->servicing_fee)
                   - mtg->adj_max_decr_per_reset)
                   - mtg->servicing_fee) * 100.0;
        	
		if (mtg->existing_asset_indicator 
			&& mtg->pmt_reset_first_period < mtg->maturity_period)
			{
			int first_reset_mth = get_mth_from_date(mtg->adj_next_reset_date);
			int first_reset_yr = get_yr_from_date(mtg->adj_next_reset_date);
			int issue_yr = get_yr_from_date(mtg->issue_date);
			int issue_mth = get_mth_from_date(mtg->issue_date);

			adco->arm_first_reset_age 
			= max(0, MonthNumberFromDate(first_reset_yr, first_reset_mth)
			         - MonthNumberFromDate(issue_yr, issue_mth));                         
			}
		else
            adco->arm_first_reset_age = mtg->adj_reset_mths;

        adco->arm_reset_period = adco->arm_first_reset_age;

		forecast_adco_adj_wac_rate(t);
		}
	else  // Fixed rate collateral type
		adco->mbs_prepmt_defn = "Fixed Rate";

	adco->setup_prepmt_rates(t); 
	}

// Copy the adco prepayment rates nums to prepmt_rate array
for (int idx = 1; idx <= 600; idx++)
	prepmt_rate[idx] = adco->get_prepmt_rate(idx);

#endif
}



#line 1 "solve_for_sprd_inverse_interp.MTG_CF_ASSET.for"                                                                                   
double MTG_CF_ASSET::solve_for_sprd_inverse_interp(int t, double guess_spread_low, double guess_value_high, double guess_spread_high, double guess_value_low, double target_value, double months_to_maturity, int solve_timing)
{
// Local Variables
int maximum_iterations = 0;
double tolerance = 0;
double guess_spread = 0;
double guess_value = 0;
double adjustment_factor = 0;
double low_spread = 0;
int loop = 0;
double high_spread = 0;
double low_value = 0;
double high_value = 0;
int done = 0;
double value_factor = 0;
int temploop = 0;
double spread_factor = 0;
double tolerance_adjustment_factor = 0;
double accr_int = 0;
double years_to_payment = 0;
double temp = 0;
double solve_for_spread_present_values[SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS + 3];
double solve_for_spread_spreads[SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS + 3];
double solve_for_spread_differences[2][2+SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS];

int cal_yr = xint(mtg->cal_yr(t));
int cal_mth = xint(mtg->cal_mth(t));

maximum_iterations = SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS;

tolerance = 0.5 / pow(10, NUMBER_OF_DECIMALS(target_value,SIGNIFICANT_DIGITS));

if (guess_spread_low == SOLVE_FOR_SPREAD_HIGHEST_SPREAD)
	{	
	// Locate high value, low spread.
    guess_spread = guess_spread_high;
    guess_value = guess_value_low;
    adjustment_factor = 0.9;

    for (loop = 0; 
    	loop < maximum_iterations && guess_value < target_value;
        loop++)
		{
	    high_spread = guess_spread;
	    low_value = guess_value;
        guess_spread
        	= high_spread
            - (1.0 - pow(adjustment_factor, loop + 1))
            * (NOMINAL_SEMIANNUAL + high_spread);

	        guess_value
 	      	= pv_calc(t,
		       	          guess_spread,
				          temp,  // calculated_derivative
				          temp   // calculated_modified_duration
						  );
		}
	
	if (guess_value < target_value)
		{
		log_screen.setf(ios::fixed, ios::floatfield);
		log_screen << "Error. Cannot solve for spread/yield for " << mtg->asset_id
		           << " Using guess spread/yield of " << convert_rate_basis(guess_spread, NOMINAL_SEMIANNUAL, 1)
		           << " Target value " << target_value << " is greater than guess value " << guess_value
		           << " Please check your input." << MSG_ERROR;		
		log_screen.unsetf(ios::fixed);
		throw FatalError("");
		}
	high_value = guess_value;
    low_spread = guess_spread;
    }
else
    {
    high_value = guess_value_high;
    low_spread = guess_spread_low;
    }

if (guess_spread_high == SOLVE_FOR_SPREAD_LOWEST_SPREAD)
	{
	// Locate low value, high spread.
    guess_spread = guess_spread_low;
    guess_value = guess_value_high;
    adjustment_factor = 0.9;
    
    for (loop = 0; 
    	loop < maximum_iterations && guess_value > target_value;
        loop++)
		{
	    low_spread = guess_spread;
	    high_value = guess_value;
        guess_spread = (adjustment_factor + low_spread) / adjustment_factor;

        guess_value
 	      	= pv_calc(t,
		       	          guess_spread,
				          temp,  // calculated_derivative 
				          temp   // calculated_modified_duration
						  );
	  	}
	
	if (guess_value > target_value)
		{
		log_screen.setf(ios::fixed);
		log_screen << "Error. Cannot solve for spread /yield. "
				<< "Target Value (" << target_value
				<< ") is less than Guess Value (" << guess_value
				<< ") at (" << convert_rate_basis(guess_spread, NOMINAL_SEMIANNUAL, 1)
				<< "). Id = " << mtg->asset_id
				<< " Year = " << cal_yr
				<< " Month = " << cal_mth
				<< " Projection Task Loop = " << proj_task_loop_num
				<< endl;		
		log_screen.unsetf(ios::fixed);
		throw FatalError("");
		}

	high_spread = guess_spread;
    low_value = guess_value;
    }
else
	{
    low_value = guess_value_low;
    high_spread = guess_spread_high;
    }

done = 0;

// Solve for spread.
while (!done)
	{
	// initialize Solve_For_Spread_Spreads and Solve_For_Spread_Present_Values 
    solve_for_spread_present_values[0] = low_value;
    solve_for_spread_spreads[0] = high_spread;
    solve_for_spread_present_values[1] = high_value;
    solve_for_spread_spreads[1] = low_spread;
    solve_for_spread_differences[0][0] = solve_for_spread_spreads[0];
    
    for (loop = 2; loop < 2 + maximum_iterations; loop++)
		{
	    if (loop > 2)
            for (temploop = 0; temploop < loop - 1; temploop++)
		    	solve_for_spread_differences[0][temploop]
		           	= solve_for_spread_differences[1][temploop];

	    solve_for_spread_differences[1][0]
	       	= solve_for_spread_spreads[loop - 1];

        for (temploop = 1; temploop < loop; temploop++)
            solve_for_spread_differences[1][temploop]
               	= (solve_for_spread_differences[1][temploop - 1]
                - solve_for_spread_differences[0][temploop - 1])
                / (solve_for_spread_present_values[loop - 1]
                - solve_for_spread_present_values[loop - temploop - 1]);

	    if (loop > 2)
            spread_factor = solve_for_spread_differences[1][0];
	    else
            spread_factor = solve_for_spread_spreads[0];

       	if (loop == 2)
            value_factor
              	= target_value - solve_for_spread_present_values[loop - 2];
        else
          	value_factor
	          	*= (target_value - solve_for_spread_present_values[loop - 2]);

	    // Get new spread.
        guess_spread
		= spread_factor
		  + value_factor * solve_for_spread_differences[1][loop - 1];
       	
       	// Start over, if we are not getting closer.
      	if (guess_spread > high_spread || guess_spread < low_spread)
        	loop = 2 + maximum_iterations;
        else
   		  	{
	        guess_value
 	      	= pv_calc(t,
		       	          guess_spread,
				          temp,  // calculated_derivative
				          temp   // calculated_modified_duration
						  );

			if (mtg->asset_detail_pv_flag(t))
				{
				PVCText << "Interpolation Loop: " << loop - 2   
						<< " for " << mtg->asset_id 
						<< " (" << mtg->pmt_rate_defn_string << ")"
						<< " t=" << t
						<< " CalYr=" << cal_yr 
						<< " CalMth=" << cal_mth;
				if (mtg->asset_detail_rpt_pv_defn == YES)
					PVCText << endl;
				else
					mtg->asset_detail_pv_output();

				PVCText	<< "GsSpread,"	<< write_string(guess_spread,PVCLen,PVCSigDig) << endl 
						<< "GsValue," << write_string(guess_value,PVCLen,PVCSigDig) << endl
						<< "Low_Spread," << write_string(low_spread,PVCLen,PVCSigDig) << endl 
						<< "High_Value," << write_string(high_value,PVCLen,PVCSigDig) << endl 
						<< "High_Spread," << write_string(high_spread,PVCLen,PVCSigDig) << endl 
						<< "Low_value," << write_string(low_value,PVCLen,PVCSigDig);
				mtg->asset_detail_pv_output();
				}

			if (fabs(guess_value - target_value) < tolerance)
		        return guess_spread;
	       	
	       	if (guess_value < target_value)
				{
		        low_value = guess_value;
                high_spread = guess_spread;
				}
		    else
			 	{
	            high_value = guess_value;
                low_spread = guess_spread;
				}
		       
		    solve_for_spread_present_values[loop] = guess_value;
            solve_for_spread_spreads[loop] = guess_spread;
		    }
		}
	
	// If not done, reduce interval by factor of 4 and start over.
 	if (!done)
		{
	    for (loop = 0; loop < 2; loop++)
	   		{
            guess_spread = (low_spread + high_spread) / 2.0;

	        guess_value
	 	      	= pv_calc(t,
		       	          guess_spread,
				          temp,  // calculated_derivative
				          temp   // calculated_modified_duration
						  );

			if (mtg->asset_detail_pv_flag(t))
				{
				PVCText << "Bisection Loop: " << loop 
						<< " for " << mtg->asset_id 
						<< " (" << mtg->pmt_rate_defn_string << ")"
						<< " t=" << t
						<< " CalYr=" << cal_yr 
						<< " CalMth=" << cal_mth;
				if (mtg->asset_detail_rpt_pv_defn == YES)
					PVCText << endl;
				else
					mtg->asset_detail_pv_output();

				PVCText	<< "GsSpread,"	<< write_string(guess_spread,PVCLen,PVCSigDig) << endl 
						<< "GsValue," << write_string(guess_value,PVCLen,PVCSigDig) << endl 
						<< "Low_Spread," << write_string(low_spread,PVCLen,PVCSigDig) << endl 
						<< "High_Value," << write_string(high_value,PVCLen,PVCSigDig) << endl 
						<< "High_Spread," << write_string(high_spread,PVCLen,PVCSigDig) << endl 
						<< "Low_value," << write_string(low_value,PVCLen,PVCSigDig);
				mtg->asset_detail_pv_output();
				}

		    if (fabs(guess_value - target_value) < tolerance)
	           	return guess_spread;

		    if (guess_value < target_value)
				{
		        low_value = guess_value;
                high_spread = guess_spread;
				}
		    else
				{
		        high_value = guess_value;
                low_spread = guess_spread;
				}
		    }	
	  	}
	}
return guess_spread;
}



#line 1 "solve_for_sprd_newton_raphson.MTG_CF_ASSET.for"                                                                                   
double MTG_CF_ASSET::solve_for_sprd_newton_raphson(int t, double guess_spread, double target_value)
{
// Local Variables
int cal_yr = xint(mtg->cal_yr(t));
int cal_mth = xint(mtg->cal_mth(t));
int maximum_iterations = 0;
int get_monthly_cash_flows = 0;
int spread_equals_payment_rate = 0;
int loopcounter = 0;
double tolerance = 0;
double low_spread = 0;
double high_spread = 0;
double calculated_spread = 0;
double value_to_check = 0;
double guess_value = 0;
double guess_derivative = 0;
double temp = 0;
double high_value = 0;
double low_value = 0;
double previous_guess_spread = 0;
double tolerance_adjustment_factor = 0;
xstring pv_timing_saved;
bool capture_pv_detail = (mtg->asset_detail_pv_flag(t)
						&& mtg->asset_detail_rpt_pv_defn == YES);

maximum_iterations = SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS;
low_spread = SOLVE_FOR_SPREAD_HIGHEST_SPREAD;
high_spread = SOLVE_FOR_SPREAD_LOWEST_SPREAD;
pv_timing_saved = pv_timing;

if (pv_defn == NET_YIELD
    && ((t == 0 && mtg->existing_asset_indicator)
        || (t == mtg->commencement_period && !mtg->existing_asset_indicator)))
	pv_timing = "End of Month";

tolerance = 0.5 / pow(10, NUMBER_OF_DECIMALS(target_value,SIGNIFICANT_DIGITS));

if (mtg->asset_detail_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Solve For Spread Newton Raphson"
			<< " for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << cal_yr
			<< " CalMth=" << cal_mth;
	mtg->asset_detail_pv_output();

	if (capture_pv_detail)
		{
		PVCFile << "SolveTiming," << pv_timing << endl
				<< "UseSpotRates," << use_spot_rates << endl
				<< "ParVal," << par_val_bef_sale(t) << endl
				<< "TargetVal," << target_value << endl
				<< "PVMths," << pv_months << endl
				<< "GuessSprd," << guess_spread	<< endl;
		}
	}

if (target_value == 0.0 && par_val_bef_sale(t) != 0.0) // sliding window problem if target_value == 0.0
	{
	log_screen.setf(ios::fixed, ios::floatfield);
	log_screen << "Error. Unable to calculate spread to amortize Target Value to"
			   << " Par Value because Target Value is zero and Par Value "
    		   << par_val_bef_sale(t) << " is not zero." // <-dan slw problem
    		   << MSG_ERROR;
	log_screen.unsetf(ios::fixed);
    log_screen << "ID = " << mtg->asset_id
    		   << " |" << modelName
    		   << " Year = " << xint(mtg->cal_yr(t))
    		   << " Month = "<< xint(mtg->cal_mth(t))
    		   << " Projection Task Loop = " << proj_task_loop_num
    		   << MSG_ERROR;
	throw FatalError("");
	}

value_to_check = target_value;

// Check that Guess_Spread is reasonable; otherwise, set to zero.
if (guess_spread <= SOLVE_FOR_SPREAD_LOWEST_SPREAD
	|| guess_spread >= SOLVE_FOR_SPREAD_HIGHEST_SPREAD)
    guess_spread = 0.0;

for (loopcounter = 1; loopcounter <= maximum_iterations; loopcounter++)
	{
	guess_value
	= pv_calc(t,
				guess_spread,
				guess_derivative,
				temp   // calculated_modified_duration
				);

	if (mtg->asset_detail_pv_flag(t))
		{
		PVCText << "Solve Loop: " << loopcounter 
				<< " for " << mtg->asset_id 
				<< " (" << mtg->pmt_rate_defn_string << ")"
				<< " t=" << t 
				<< " CalYr=" << cal_yr 
				<< " CalMth=" << cal_mth;
		if (mtg->asset_detail_rpt_pv_defn == YES)
			PVCText << endl;
		else
			mtg->asset_detail_pv_output();

		PVCText	<< "GsSprd,"	<< write_string(guess_spread,PVCLen,PVCSigDig) << endl
				<< "GsVal," << write_string(guess_value,PVCLen,PVCSigDig) << endl
				<< "GsDerivative,"	<< write_string(guess_derivative,PVCLen,PVCSigDig) << endl
				<< "LowYield," << write_string(low_spread,PVCLen,PVCSigDig) << endl
				<< "HighBook," << write_string(high_value,PVCLen,PVCSigDig) << endl
				<< "HighYield," << write_string(high_spread,PVCLen,PVCSigDig) << endl
				<< "LowBook,"	<< write_string(low_value,PVCLen,PVCSigDig);
		mtg->asset_detail_pv_output();
		}

	if (fabs(guess_value - value_to_check) < tolerance)
		break;

	if (guess_value > value_to_check
		&& (guess_spread > low_spread
			|| low_spread == SOLVE_FOR_SPREAD_HIGHEST_SPREAD))
		{
		low_spread = guess_spread;
		high_value = guess_value;
		}
	else
		{
		if (guess_value < value_to_check
			&& (guess_spread < high_spread
				|| high_spread == SOLVE_FOR_SPREAD_LOWEST_SPREAD))
			{
			high_spread = guess_spread;
			low_value = guess_value;
			}
		}

	previous_guess_spread = guess_spread;

	if (fabs(guess_derivative) > model_point_amount_threshold)
		{
		guess_spread
		= previous_guess_spread
		  - ((guess_value - target_value) / guess_derivative);

		if (guess_spread < previous_guess_spread)
			// Check low spread.
			if (guess_spread < SOLVE_FOR_SPREAD_LOWEST_SPREAD
				|| (guess_spread < low_spread
					&& low_spread < SOLVE_FOR_SPREAD_HIGHEST_SPREAD))
				loopcounter = maximum_iterations;
                // stop Newton-Raphson
		else
			// Check high spread.
			if (guess_spread > SOLVE_FOR_SPREAD_HIGHEST_SPREAD
				|| (guess_spread > high_spread
					&& high_spread > SOLVE_FOR_SPREAD_LOWEST_SPREAD))
				loopcounter = maximum_iterations;
				// stop Newton-Raphson
		}
	else
		loopcounter = maximum_iterations;
		// stop Newton-Raphson

	if (loopcounter == maximum_iterations)
		{
		guess_spread
		= solve_for_sprd_inverse_interp(t,
				low_spread, high_value,
				high_spread,
				low_value,
				value_to_check,
				pv_months,
				pv_timing);
		}
	}

calculated_spread = guess_spread;

if (mtg->asset_detail_pv_flag(t))
	{
	if (capture_pv_detail)
		{
		PVCFile << "Final Spread" << endl 
				<< "Monthly," << convert_rate_basis(calculated_spread, NOMINAL_SEMIANNUAL, 12) << endl 
				<< "Semi-Annual," << convert_rate_basis(calculated_spread, NOMINAL_SEMIANNUAL, 2) << endl 
				<< "Annual," << convert_rate_basis(calculated_spread, NOMINAL_SEMIANNUAL, 1) << endl;
		}

	PVCText << PVCounter
			<< "<--End Solve For Spread Newton Raphson ("
			<< write_string(calculated_spread,PVCLen,PVCSigDig)
			<< ") for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << cal_yr
			<< " CalMth=" << cal_mth;
	mtg->asset_detail_pv_output();
	PVCounter--;
	}	// endif

pv_timing = pv_timing_saved;

return calculated_spread;
}



#line 1 "weighted_avg_life_calc.MTG_CF_ASSET.for"                                                                                   
double MTG_CF_ASSET::weighted_avg_life_calc(int t)
{
#if defined(__INTEX_ASSET_H_)
if (intex_proj_flag)
	{
	if (mtg->mths_to_next_mkt_val_calc(t) == 0)
		return intex->get_tranche_wal(t, "Actual",
						par_val_bef_sale(t), accr_int_bef_sale(t));

	return intex->get_tranche_wal(t, "Approximate",
					par_val_bef_sale(t), accr_int_bef_sale(t));
	}
#endif	

int simple_wal = 0;
bool capture_pv_detail = (mtg->asset_detail_pv_flag(t)
						&& mtg->asset_detail_rpt_pv_defn == YES);
double wal_adjustment = 0;
double unadjusted_wal = 0;
double calculated_weighted_average_life = 0;

if (mtg->asset_detail_pv_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Weighted Average Life Calculation (" << pv_tbl_defn
			<< ") for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(mtg->cal_yr(t))
			<< " CalMth=" << xint(mtg->cal_mth (t));
	mtg->asset_detail_pv_output();
	}

bool initialize_pv_tables = (pv_tbl_defn == INITIALIZE_TABLES);
bool pv_simple_calculation = pv_simple_flag(t);
bool use_pv_tables = (pv_tbl_defn == USE_TABLES);

if (!use_pv_tables)
	pv_calc_init_val(t);

if (pv_simple_calculation)
	{
	if (t < mtg->amortzn_period && !initialize_pv_tables)
		simple_wal = 1;
	}

if (pv_timing == END_OF_MONTH)
	wal_adjustment = 0;

if (simple_wal)
	unadjusted_wal = (mtg->maturity_period - t) / 12.0;
else
	{
	if (pv_simple_calculation)
		{
		// calculate wal on 'simple' amortizing mortgage
		weighted_avg_life_simple(t, unadjusted_wal, wal_adjustment);
		}
	else
		{
		int month = t;
		bool done = false;
		bool present_value_includes_prepayments = (prepmt_appl == YES);
		double wal_principal_payments = 0;
		double wal_numerator = 0;
		double wal_denominator = 0;
		double payoff_amount = 0;
		bool final_month = false;

		if (capture_pv_detail)
			{
			if (present_value_includes_prepayments)
				adco_prepmt_forecast(t);
			}

		if (initialize_pv_tables
			&& pv_defn != MARKET_VALUE_SHIFTED)
			pv_initialize_yield_maintenance_table = true;

		if (this->isShrunk)
			{
			log_screen << "Error. t=" << t
					<< " " << (this==mtg_cf ? "mtg_cf"
								: (this==mtg_pv ? "mtg_pv"
								: (this==mtg_is ? "mtg_is"
								: (this==mtg_ym ? "mtg_ym" : "???"))))
					<< " rebase_period=" << rebase_period
					<< " pv_defn=" << pv_defn
					<< " pv_tbl_defn=" << pv_tbl_defn
					<< " pv_timing=" << pv_timing
					<< " is shrunk in weighted_avg_life_calc |" << modelName
					<< MSG_ERROR;
			throw FatalError("");
			}

		while (month < t + pv_months && !done) 
			{
			month++;

			wal_principal_payments
			= sched_prin_pmt(month)
			  + prepmt_amt(month);

			final_month = (month == t + pv_months);

			if (final_month
				&& month < mtg->maturity_period)
				{
				if (intex_proj_flag)
					payoff_amount
					= par_val_aft_prepmt(month);
				else
					payoff_amount
					= par_val_aft_sched_pmt(month);

				wal_principal_payments
				= wal_principal_payments + payoff_amount;
				}

			wal_numerator
			+= wal_principal_payments * (month - t);

			wal_denominator
			+= wal_principal_payments;

			if (initialize_pv_tables) // new code
				{
				if (!final_month
					&& pv_initialize_interest_savings_table)
					{
					pv_interest_savings_after_prepayments[month - t]
					= int_savings_pv_aft_prepmt(month);
					}

				// forced calls to reduce sliding windows sizes
				if (prepmt_appl == YES)
					{
					if (pv_defn == MARKET_VALUE_SHIFTED)
						int_savings_pv_aft_prepmt(month);

					if (mtg->prepmt_penalty_defn == CASH_FLOW_MAINTENANCE)
						{
						if (month == t + 1)
							yld_maint_cost_pct(month);

						yld_maint_cash_flow_pct_bef_prepmt(month);
						}
					}
				// end forced calls to reduce sliding windows sizes

				pv_cash_flows[month - t - 1]
				= cash_flow(month) + payoff_amount;

				if (par_val_aft_prepmt(month) <= 0.0
					|| month == mtg->maturity_period)
					{
					pv_last_cash_flow_month = month;
					done = true;
					}
				}
			else if (par_val_aft_prepmt(month) <= 0.0)
				done = true;

			if (capture_pv_detail)
				{
				if (month == t + 1)
					{
					PVCFile << endl;
					PVCFile << " WAL Cash Flow Summary for " << mtg->asset_id << " Category=" << mtg->category_id << endl;
					if (present_value_includes_prepayments
						&& initialize_pv_tables)
						PVCFile << "InitialInterestSavingPV,"
								<< write_string(pv_interest_savings_after_prepayments[0],PVCLen,PVCSigDig);
					PVCFile << endl;

					PVCFile << "Yr,Mo,Period,ParValue,SchedPmt,PrepayAmt,PmtRate,";
			
					if (present_value_includes_prepayments)
						PVCFile << "RefinRate,ISavPVBef,IntSav,PrePayCst,MthlyRRat";
			
					PVCFile << endl;
					}

				PVCFile << xint(mtg->cal_yr(month)) << ","
						<< xint(mtg->cal_mth(month)) << ","
						<< month - t << ","
						<< par_val_aft_prepmt(month) << ","
						<< sched_prin_pmt(month) + payoff_amount << ","
						<< prepmt_amt(month) << ","
						<< pmt_rate(month) << ",";

				if (present_value_includes_prepayments)
					PVCFile << refinancing_rate(month) << ","
							<< int_savings_pv_bef_prepmt(month) << ","
							<< int_savings_pv_bef_prepmt(month) - par_val_aft_sched_pmt(month) << ","
							<< par_val_aft_sched_pmt(month)	* (prepmt_penalty(month) + mtg->refinancing_cost_pct) << ",";
				
				if (month == t + 1)
					PVCFile << pv_interest_savings_monthly_refinancing_rate;

				PVCFile << endl;
				}
			}

		unadjusted_wal = wal_numerator / wal_denominator / 12.0;

		if (initialize_pv_tables)
			pv_tbl_defn = "Use Tables";
		}
	}

if (capture_pv_detail)
	PVCFile << endl
			<< "UnAdjWAL," << write_string(unadjusted_wal,PVCLen,PVCSigDig) << endl
			<< "WALAdj," << write_string(wal_adjustment,PVCLen,PVCSigDig) << endl;

calculated_weighted_average_life = unadjusted_wal - wal_adjustment;

if (mtg->asset_detail_pv_flag(t))
	{
	PVCText << PVCounter
			<< "<--End Weighted Average Life Calculation ("
			<< write_string(calculated_weighted_average_life,PVCLen,PVCSigDig)
			<< ") for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(mtg->cal_yr(t))
			<< " CalMth=" << xint(mtg->cal_mth(t));
	mtg->asset_detail_pv_output();
	PVCounter--;
	}

return calculated_weighted_average_life;
}



#line 1 "weighted_avg_life_simple.MTG_CF_ASSET.for"                                                                                   
void MTG_CF_ASSET::weighted_avg_life_simple(int t, double &unadjusted_wal, double &wal_adjustment)
{
double sum_of_periodic_par_payments = 0;
double sum_of_periodic_par_payments_times_periods_to_cash_flow = 0;
double wal_numerator = 0;
double wal_denominator = 0;
double calculated_weighted_average_life = 0;
double maturity_amount = 0;
double temp = 0;
double periodic_payment_amount = pmt_amt_bef_sale(t);
double accr_int = accr_int_bef_sale(t);

if (t < mtg->amortzn_period)
	maturity_amount
	= pv_calc_simple(t,
				pmt_rate(t) + mtg->servicing_fee, 
				mtg->maturity_period - t, 
				0.0, 
				periodic_payment_amount, 
				mtg->pmt_freq, 
				accr_int, 
				temp, // calculated_derivative
				temp  // calculated_modified_duration
				);		

int pmt_mths 
= 12 / mtg->pmt_freq;

int months_to_next_payment_local 
= 1 + (mtg->maturity_period - t - 1) % pmt_mths;

int months_since_last_payment_date 
= pmt_mths - months_to_next_payment_local;

int payments_remaining
= 1 + (mtg->maturity_period - t - months_to_next_payment_local)
	  / pmt_mths;

double par_discount
= 1.0 / (1.0 + pmt_rate(t) / mtg->pmt_freq);

double duration_adjustment
= months_since_last_payment_date * (1.0 / 12.0);

double next_par_payment
= pow(par_discount, payments_remaining);

if (par_discount != 1.0)
	sum_of_periodic_par_payments
 	= par_discount * (1.0 - next_par_payment) / (1.0 - par_discount);
else
	sum_of_periodic_par_payments = payments_remaining;

if (par_discount != 1.0)
	sum_of_periodic_par_payments_times_periods_to_cash_flow	
	= (payments_remaining - sum_of_periodic_par_payments) 
	  * mtg->pmt_freq / pmt_rate(t);
else
	sum_of_periodic_par_payments_times_periods_to_cash_flow
	= payments_remaining * (payments_remaining + 1.0) / 2.0;

wal_numerator
= pmt_mths 
  * (1.0 / 12.0)
  * (periodic_payment_amount 
	 * sum_of_periodic_par_payments_times_periods_to_cash_flow 
	 + maturity_amount 
	   * payments_remaining);

wal_denominator
= periodic_payment_amount 
  * sum_of_periodic_par_payments 
  + maturity_amount;

unadjusted_wal
= wal_numerator
  / wal_denominator;
  
wal_adjustment
= duration_adjustment;  

if (mtg->asset_detail_pv_flag(t))
   	{
	PVCounter++;
	PVCText << PVCounter
			<< "-->Begin Weighted Average Life Calculation Simple"
			<< " for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(mtg->cal_yr(t))
			<< " CalMth=" << xint(mtg->cal_mth(t));
	mtg->asset_detail_pv_output();

	if (mtg->asset_detail_rpt_pv_defn == YES)
		{
		PVCFile << "AccInt," << accr_int << endl
				<< "MthsToMat," << mtg->maturity_period - t << endl
				<< "MatAmt," << maturity_amount << endl
				<< "PmtAmt," << periodic_payment_amount << endl
				<< "PmtFreq," << mtg->pmt_freq << endl
				<< "YrsToEndOfPmtMth," << 0 << endl
				<< "MonthsPerPaymentPeriod," << pmt_mths << endl
				<< "MonthsToNextPayment," << months_to_next_payment_local << endl
				<< "MonthsSinceLastPaymentDate," << months_since_last_payment_date << endl
				<< "PaymentsRemaining," << payments_remaining << endl
				<< "ParDiscount," << par_discount << endl
				<< "DurationAdjustment, " << duration_adjustment << endl
				<< "NextParPayment," << next_par_payment << endl
				<< "SumOfPeriodicParPayments, " << sum_of_periodic_par_payments << endl
				<< "SumOfPeriodicParPaymentsTimesPeriodsToCF, " << sum_of_periodic_par_payments_times_periods_to_cash_flow << endl
				<< "WALNumerator," << wal_numerator << endl
				<< "WALDenominator," << wal_denominator << endl
				<< "UnAdjWAL," << unadjusted_wal << endl
				<< "WALAdj," << wal_adjustment	<< endl;
		}

	PVCText << PVCounter
			<< "<--End Weighted Average Life Calculation Simple ("
			<< ") for " << mtg->asset_id
			<< " (" << mtg->pmt_rate_defn_string << ")"
			<< " t=" << t
			<< " CalYr=" << xint(mtg->cal_yr(t))
			<< " CalMth=" << xint(mtg->cal_mth(t));
	mtg->asset_detail_pv_output();
	PVCounter--;
	}

return;
}



	static MTG_CF_ASSET_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (MTG_CF_ASSET_UDF::*dPXi) (int);
typedef double (MTG_CF_ASSET_UDF::*dPXid) (int, double);
typedef double (MTG_CF_ASSET_UDF::*dPF) ();
typedef double (MTG_CF_ASSET_UDF::*dPFd) (double);
typedef int (MTG_CF_ASSET_UDF::*iPF) ();
typedef int (MTG_CF_ASSET_UDF::*iPFi) (int);
typedef xstring (MTG_CF_ASSET_UDF::*sPF) ();
typedef xstring (MTG_CF_ASSET_UDF::*sPFs) (xstring);

const CashFlowCommonData MTG_CF_ASSET::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "accr_int", "mtg_cf_asset_accr_int",  "accr_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_accr_int, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int),
	CashFlowCommonData(2, "accr_int_aft_dflt", "mtg_cf_asset_accr_int_aft_dflt",  "accr_int_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_accr_int_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_aft_dflt),
	CashFlowCommonData(3, "accr_int_aft_prepmt", "mtg_cf_asset_accr_int_aft_prepmt",  "accr_int_aft_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_accr_int_aft_prepmt, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_aft_prepmt),
	CashFlowCommonData(4, "accr_int_bef_prepmt", "mtg_cf_asset_accr_int_bef_prepmt",  "accr_int_bef_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_accr_int_bef_prepmt, 'E','N', '3', 'C', (size_t)&modelOffset->accr_int_bef_prepmt),
	CashFlowCommonData(5, "accr_int_bef_sale", "mtg_cf_asset_accr_int_bef_sale",  "accr_int_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_accr_int_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->accr_int_bef_sale),
	CashFlowCommonData(6, "adco_prepmt_forecast", "mtg_cf_asset_adco_prepmt_forecast",  "adco_prepmt_forecast",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_adco_prepmt_forecast, 'E','N', '3', 'P', (size_t)&modelOffset->adco_prepmt_forecast),
	CashFlowCommonData(7, "balloon_pmt", "mtg_cf_asset_balloon_pmt",  "balloon_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_balloon_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->balloon_pmt),
	CashFlowCommonData(8, "balloon_pmt_inc", "mtg_cf_asset_balloon_pmt_inc",  "balloon_pmt_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_balloon_pmt_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->balloon_pmt_inc),
	CashFlowCommonData(9, "int_pmt", "mtg_cf_asset_int_pmt",  "int_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_int_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->int_pmt),
	CashFlowCommonData(10, "int_savings_pv_aft_prepmt", "mtg_cf_asset_int_savings_pv_aft_prepmt",  "int_savings_pv_aft_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_int_savings_pv_aft_prepmt, 'E','N', '3', 'P', (size_t)&modelOffset->int_savings_pv_aft_prepmt),
	CashFlowCommonData(11, "int_savings_pv_bef_prepmt", "mtg_cf_asset_int_savings_pv_bef_prepmt",  "int_savings_pv_bef_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_int_savings_pv_bef_prepmt, 'E','N', '3', 'P', (size_t)&modelOffset->int_savings_pv_bef_prepmt),
	CashFlowCommonData(12, "intex_pmt_processed", "mtg_cf_asset_intex_pmt_processed",  "intex_pmt_processed",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_intex_pmt_processed, 'E','N', '3', 'N', (size_t)&modelOffset->intex_pmt_processed),
	CashFlowCommonData(13, "mths_since_issue", "mtg_cf_asset_mths_since_issue",  "mths_since_issue",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_mths_since_issue, 'E','N', '3', 'P', (size_t)&modelOffset->mths_since_issue),
	CashFlowCommonData(14, "par_val", "mtg_cf_asset_par_val",  "par_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_par_val, 'E','N', '3', 'C', (size_t)&modelOffset->par_val),
	CashFlowCommonData(15, "par_val_aft_dflt", "mtg_cf_asset_par_val_aft_dflt",  "par_val_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_par_val_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->par_val_aft_dflt),
	CashFlowCommonData(16, "par_val_aft_prepmt", "mtg_cf_asset_par_val_aft_prepmt",  "par_val_aft_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_par_val_aft_prepmt, 'E','N', '3', 'C', (size_t)&modelOffset->par_val_aft_prepmt),
	CashFlowCommonData(17, "par_val_aft_sched_pmt", "mtg_cf_asset_par_val_aft_sched_pmt",  "par_val_aft_sched_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_par_val_aft_sched_pmt, 'E','N', '3', 'C', (size_t)&modelOffset->par_val_aft_sched_pmt),
	CashFlowCommonData(18, "par_val_bef_sale", "mtg_cf_asset_par_val_bef_sale",  "par_val_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_par_val_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->par_val_bef_sale),
	CashFlowCommonData(19, "par_val_for_balloon_pmt_aft_dflt", "mtg_cf_asset_par_val_for_balloon_pmt_aft_dflt",  "par_val_for_balloon_pmt_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_par_val_for_balloon_pmt_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->par_val_for_balloon_pmt_aft_dflt),
	CashFlowCommonData(20, "par_val_for_balloon_pmt_bef_sale", "mtg_cf_asset_par_val_for_balloon_pmt_bef_sale",  "par_val_for_balloon_pmt_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_par_val_for_balloon_pmt_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->par_val_for_balloon_pmt_bef_sale),
	CashFlowCommonData(21, "pmt_amt_aft_dflt", "mtg_cf_asset_pmt_amt_aft_dflt",  "pmt_amt_aft_dflt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_pmt_amt_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->pmt_amt_aft_dflt),
	CashFlowCommonData(22, "pmt_amt_aft_sched_payment", "mtg_cf_asset_pmt_amt_aft_sched_payment",  "pmt_amt_aft_sched_payment",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_pmt_amt_aft_sched_payment, 'E','N', '3', 'C', (size_t)&modelOffset->pmt_amt_aft_sched_payment),
	CashFlowCommonData(23, "pmt_amt_bef_sale", "mtg_cf_asset_pmt_amt_bef_sale",  "pmt_amt_bef_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_pmt_amt_bef_sale, 'E','N', '3', 'P', (size_t)&modelOffset->pmt_amt_bef_sale),
	CashFlowCommonData(24, "pmt_rate", "mtg_cf_asset_pmt_rate",  "pmt_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_pmt_rate, 'E','N', '3', 'C', (size_t)&modelOffset->pmt_rate),
	CashFlowCommonData(25, "prepmt_amt", "mtg_cf_asset_prepmt_amt",  "prepmt_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_prepmt_amt, 'E','Y', '3', 'C', (size_t)&modelOffset->prepmt_amt),
	CashFlowCommonData(26, "prepmt_inc", "mtg_cf_asset_prepmt_inc",  "prepmt_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_prepmt_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->prepmt_inc),
	CashFlowCommonData(27, "prepmt_pct", "mtg_cf_asset_prepmt_pct",  "prepmt_pct",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_prepmt_pct, 'E','N', '3', 'C', (size_t)&modelOffset->prepmt_pct),
	CashFlowCommonData(28, "prepmt_pct_mthly", "mtg_cf_asset_prepmt_pct_mthly",  "prepmt_pct_mthly",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_prepmt_pct_mthly, 'E','N', '3', 'C', (size_t)&modelOffset->prepmt_pct_mthly),
	CashFlowCommonData(29, "prepmt_penalty", "mtg_cf_asset_prepmt_penalty",  "prepmt_penalty",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_prepmt_penalty, 'E','Y', '3', 'C', (size_t)&modelOffset->prepmt_penalty),
	CashFlowCommonData(30, "refinancing_rate", "mtg_cf_asset_refinancing_rate",  "refinancing_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_refinancing_rate, 'E','N', '3', 'P', (size_t)&modelOffset->refinancing_rate),
	CashFlowCommonData(31, "remaining_pct_aft_dflt", "mtg_cf_asset_remaining_pct_aft_dflt",  "remaining_pct_aft_dflt",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_remaining_pct_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->remaining_pct_aft_dflt),
	CashFlowCommonData(32, "remaining_pct_aft_sched_pmt", "mtg_cf_asset_remaining_pct_aft_sched_pmt",  "remaining_pct_aft_sched_pmt",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_remaining_pct_aft_sched_pmt, 'E','N', '3', 'C', (size_t)&modelOffset->remaining_pct_aft_sched_pmt),
	CashFlowCommonData(33, "renewal_rate", "mtg_cf_asset_renewal_rate",  "renewal_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_renewal_rate, 'E','N', '3', 'C', (size_t)&modelOffset->renewal_rate),
	CashFlowCommonData(34, "sched_prin_pmt", "mtg_cf_asset_sched_prin_pmt",  "sched_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_sched_prin_pmt, 'E','Y', '3', 'C', (size_t)&modelOffset->sched_prin_pmt),
	CashFlowCommonData(35, "since_foreclosure_int_mult", "mtg_cf_asset_since_foreclosure_int_mult",  "since_foreclosure_int_mult",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_since_foreclosure_int_mult, 'E','N', '3', 'C', (size_t)&modelOffset->since_foreclosure_int_mult),
	CashFlowCommonData(36, "since_foreclosure_prin_pmt_mult", "mtg_cf_asset_since_foreclosure_prin_pmt_mult",  "since_foreclosure_prin_pmt_mult",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_since_foreclosure_prin_pmt_mult, 'E','N', '3', 'C', (size_t)&modelOffset->since_foreclosure_prin_pmt_mult),
	CashFlowCommonData(37, "since_restructure_int_mult", "mtg_cf_asset_since_restructure_int_mult",  "since_restructure_int_mult",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_since_restructure_int_mult, 'E','N', '3', 'C', (size_t)&modelOffset->since_restructure_int_mult),
	CashFlowCommonData(38, "since_restructure_prin_pmt_mult", "mtg_cf_asset_since_restructure_prin_pmt_mult",  "since_restructure_prin_pmt_mult",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_since_restructure_prin_pmt_mult, 'E','N', '3', 'C', (size_t)&modelOffset->since_restructure_prin_pmt_mult),
	CashFlowCommonData(39, "startup", "mtg_cf_asset_startup",  "startup",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(40, "tranche_portion", "mtg_cf_asset_tranche_portion",  "tranche_portion",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_tranche_portion, 'E','N', '3', 'C', (size_t)&modelOffset->tranche_portion),
	CashFlowCommonData(41, "tranche_portion_aft_dflt", "mtg_cf_asset_tranche_portion_aft_dflt",  "tranche_portion_aft_dflt",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_tranche_portion_aft_dflt, 'E','N', '3', 'C', (size_t)&modelOffset->tranche_portion_aft_dflt),
	CashFlowCommonData(42, "tranche_portion_bef_sale", "mtg_cf_asset_tranche_portion_bef_sale",  "tranche_portion_bef_sale",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_tranche_portion_bef_sale, 'E','N', '3', 'C', (size_t)&modelOffset->tranche_portion_bef_sale),
	CashFlowCommonData(43, "yld_maint_cash_flow_pct_bef_prepmt", "mtg_cf_asset_yld_maint_cash_flow_pct_bef_prepmt",  "yld_maint_cash_flow_pct_bef_prepmt",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_yld_maint_cash_flow_pct_bef_prepmt, 'E','N', '3', 'P', (size_t)&modelOffset->yld_maint_cash_flow_pct_bef_prepmt),
	CashFlowCommonData(44, "yld_maint_cost_pct", "mtg_cf_asset_yld_maint_cost_pct",  "yld_maint_cost_pct",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_yld_maint_cost_pct, 'E','N', '3', 'P', (size_t)&modelOffset->yld_maint_cost_pct),
	CashFlowCommonData(45, "yld_maint_rate", "mtg_cf_asset_yld_maint_rate",  "yld_maint_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MTG_CF_ASSET_UDF::mtg_cf_asset_yld_maint_rate, 'E','N', '3', 'P', (size_t)&modelOffset->yld_maint_rate)
};
const CashFlowCommonData* MTG_CF_ASSET::mCFStaticData[] = {
	&MTG_CF_ASSET::mCFStaticData_0[0],
	&MTG_CF_ASSET::mCFStaticData_0[1],
	&MTG_CF_ASSET::mCFStaticData_0[2],
	&MTG_CF_ASSET::mCFStaticData_0[3],
	&MTG_CF_ASSET::mCFStaticData_0[4],
	&MTG_CF_ASSET::mCFStaticData_0[5],
	&MTG_CF_ASSET::mCFStaticData_0[6],
	&MTG_CF_ASSET::mCFStaticData_0[7],
	&MTG_CF_ASSET::mCFStaticData_0[8],
	&MTG_CF_ASSET::mCFStaticData_0[9],
	&MTG_CF_ASSET::mCFStaticData_0[10],
	&MTG_CF_ASSET::mCFStaticData_0[11],
	&MTG_CF_ASSET::mCFStaticData_0[12],
	&MTG_CF_ASSET::mCFStaticData_0[13],
	&MTG_CF_ASSET::mCFStaticData_0[14],
	&MTG_CF_ASSET::mCFStaticData_0[15],
	&MTG_CF_ASSET::mCFStaticData_0[16],
	&MTG_CF_ASSET::mCFStaticData_0[17],
	&MTG_CF_ASSET::mCFStaticData_0[18],
	&MTG_CF_ASSET::mCFStaticData_0[19],
	&MTG_CF_ASSET::mCFStaticData_0[20],
	&MTG_CF_ASSET::mCFStaticData_0[21],
	&MTG_CF_ASSET::mCFStaticData_0[22],
	&MTG_CF_ASSET::mCFStaticData_0[23],
	&MTG_CF_ASSET::mCFStaticData_0[24],
	&MTG_CF_ASSET::mCFStaticData_0[25],
	&MTG_CF_ASSET::mCFStaticData_0[26],
	&MTG_CF_ASSET::mCFStaticData_0[27],
	&MTG_CF_ASSET::mCFStaticData_0[28],
	&MTG_CF_ASSET::mCFStaticData_0[29],
	&MTG_CF_ASSET::mCFStaticData_0[30],
	&MTG_CF_ASSET::mCFStaticData_0[31],
	&MTG_CF_ASSET::mCFStaticData_0[32],
	&MTG_CF_ASSET::mCFStaticData_0[33],
	&MTG_CF_ASSET::mCFStaticData_0[34],
	&MTG_CF_ASSET::mCFStaticData_0[35],
	&MTG_CF_ASSET::mCFStaticData_0[36],
	&MTG_CF_ASSET::mCFStaticData_0[37],
	&MTG_CF_ASSET::mCFStaticData_0[38],
	&MTG_CF_ASSET::mCFStaticData_0[39],
	&MTG_CF_ASSET::mCFStaticData_0[40],
	&MTG_CF_ASSET::mCFStaticData_0[41],
	&MTG_CF_ASSET::mCFStaticData_0[42],
	&MTG_CF_ASSET::mCFStaticData_0[43],
	&MTG_CF_ASSET::mCFStaticData_0[44],
	&MTG_CF_ASSET::mCFStaticData_0[45],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for dflt_appl                                                                                       
	const ChoicePair dflt_applChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList dflt_applEnumList(2, dflt_applChoicePairs);

	// EnumList for prepmt_appl                                                                                       
	const ChoicePair prepmt_applChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList prepmt_applEnumList(2, prepmt_applChoicePairs);

	// EnumList for pv_defn                                                                                       
	const ChoicePair pv_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CASH_FLOWS, "Cash Flows")
		,ChoicePair(StrEnum::MARKET_VALUE, "Market Value")
		,ChoicePair(StrEnum::MARKET_VALUE_SHIFTED, "Market Value Shifted")
		,ChoicePair(StrEnum::NET_YIELD, "Net Yield")
		,ChoicePair(StrEnum::INTEREST_SAVINGS_BEFORE_PREPAYMENTS, "Interest Savings Before Prepayments")
		,ChoicePair(StrEnum::INTEREST_SAVINGS_AFTER_PREPAYMENTS, "Interest Savings After Prepayments")
		,ChoicePair(StrEnum::YIELD_MAINTENANCE, "Yield Maintenance")
		,ChoicePair(StrEnum::SAVE, "Save")
		,ChoicePair(StrEnum::RESTORE, "Restore")
	};
	const EnumList pv_defnEnumList(9, pv_defnChoicePairs);

	// EnumList for pv_tbl_defn                                                                                       
	const ChoicePair pv_tbl_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO_TABLES, "No Tables")
		,ChoicePair(StrEnum::INITIALIZE_TABLES, "Initialize Tables")
		,ChoicePair(StrEnum::USE_TABLES, "Use Tables")
	};
	const EnumList pv_tbl_defnEnumList(3, pv_tbl_defnChoicePairs);

	// EnumList for pv_timing                                                                                       
	const ChoicePair pv_timingChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BEFORE_PREPAYMENTS, "Before Prepayments")
		,ChoicePair(StrEnum::AFTER_PREPAYMENTS, "After Prepayments")
		,ChoicePair(StrEnum::END_OF_MONTH, "End of Month")
	};
	const EnumList pv_timingEnumList(3, pv_timingChoicePairs);

	// EnumList for shift_defn                                                                                       
	const ChoicePair shift_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO_SHIFT, "No Shift")
		,ChoicePair(StrEnum::SPOT_SHIFT, "Spot Shift")
		,ChoicePair(StrEnum::YIELD_SHIFT, "Yield Shift")
	};
	const EnumList shift_defnEnumList(3, shift_defnChoicePairs);

	// EnumList for use_spot_rates                                                                                       
	const ChoicePair use_spot_ratesChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList use_spot_ratesEnumList(2, use_spot_ratesChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace MTG_CF_ASSET_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(MTG_CF_ASSET::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(MTG_CF_ASSET::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace MTG_CF_ASSET_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void MTG_CF_ASSET::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> MTG_CF_ASSET::mgr_;

	Attribute::Descriptor MTG_CF_ASSET::descriptor_0[] = {
	Descriptor(0, Attribute::STR_ENUM,	"dflt_appl", -1, (size_t)&modelOffset->dflt_appl,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &dflt_applEnumList, Feature(true)),
	Descriptor(1, Attribute::STR_ENUM,	"prepmt_appl", -1, (size_t)&modelOffset->prepmt_appl,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &prepmt_applEnumList, Feature(true)),
	Descriptor(2, Attribute::ARRAY_DOUBLE,	"prepmt_rate", -1, (size_t)&modelOffset->prepmt_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature(1)),
	Descriptor(3, Attribute::STR_ENUM,	"pv_defn", -1, (size_t)&modelOffset->pv_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &pv_defnEnumList, Feature(true)),
	Descriptor(4, Attribute::DOUBLE,	"pv_int_savings_pv_for_mkt_val_calc", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pv_int_savings_pv_for_mkt_val_calc,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::STR_ENUM,	"pv_tbl_defn", -1, (size_t)&modelOffset->pv_tbl_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &pv_tbl_defnEnumList, Feature(true)),
	Descriptor(6, Attribute::STR_ENUM,	"pv_timing", -1, (size_t)&modelOffset->pv_timing,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &pv_timingEnumList, Feature(true)),
	Descriptor(7, Attribute::STR_ENUM,	"shift_defn", -1, (size_t)&modelOffset->shift_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &shift_defnEnumList, Feature(true)),
	Descriptor(8, Attribute::STR_ENUM,	"use_spot_rates", -1, (size_t)&modelOffset->use_spot_rates,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &use_spot_ratesEnumList, Feature(true)),
	Descriptor(9, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	};

	Attribute::Descriptor* MTG_CF_ASSET::descriptorTable[] = {
	&MTG_CF_ASSET::descriptor_0[0],
	&MTG_CF_ASSET::descriptor_0[1],
	&MTG_CF_ASSET::descriptor_0[2],
	&MTG_CF_ASSET::descriptor_0[3],
	&MTG_CF_ASSET::descriptor_0[4],
	&MTG_CF_ASSET::descriptor_0[5],
	&MTG_CF_ASSET::descriptor_0[6],
	&MTG_CF_ASSET::descriptor_0[7],
	&MTG_CF_ASSET::descriptor_0[8],
	&MTG_CF_ASSET::descriptor_0[9],
	nullptr};
	const size_t MTG_CF_ASSET::sDescriptorCount = 10;

//factory
MTG_CF_ASSET* MTG_CF_ASSET::makeThis(int isSubmodel, ModelClass* owner, MTG_CF_ASSET* peer, 
						int mainRebase, const xstring &name, MTG_CF_ASSET_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("MTG_CF_ASSET::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor MTG_CF_ASSET");
#endif
	MTG_CF_ASSET* newP = (MTG_CF_ASSET*)new MTG_CF_ASSET_UDF
   	  ("mtg_cf_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
	if (rebasing_wanted && (!peer || peer != newP->sm_calling_model)) {
	if (find(unusedModels.begin(), unusedModels.end(), name + "|mtg_pv") == unusedModels.end()) {
	newP->sm_mtg_pv = MTG_CF_ASSET::makeThis(1, newP, newP, 0, name + "|mtg_pv", (MTG_CF_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_mtg_pv:0));
	newP->adopt(newP->sm_mtg_pv);
	}
	}

	if (rebasing_wanted && (!peer || peer != newP->sm_calling_model)) {
	if (find(unusedModels.begin(), unusedModels.end(), name + "|mtg_is") == unusedModels.end()) {
	newP->sm_mtg_is = MTG_CF_ASSET::makeThis(1, newP, newP, 0, name + "|mtg_is", (MTG_CF_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_mtg_is:0));
	newP->adopt(newP->sm_mtg_is);
	}
	}

	if (rebasing_wanted && (!peer || peer != newP->sm_calling_model)) {
	if (find(unusedModels.begin(), unusedModels.end(), name + "|mtg_ym") == unusedModels.end()) {
	newP->sm_mtg_ym = MTG_CF_ASSET::makeThis(1, newP, newP, 0, name + "|mtg_ym", (MTG_CF_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_mtg_ym:0));
	newP->adopt(newP->sm_mtg_ym);
	}
	}


	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	return newP;
}

//factory
MTG_CF_ASSET_persistent_object* MTG_CF_ASSET_persistent_object::makeThis(int isSubmodel, ModelClass* owner, MTG_CF_ASSET* peer, 
							int mainRebase, const xstring &name, MTG_CF_ASSET_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("MTG_CF_ASSET_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor MTG_CF_ASSET_persistent_object");
#endif
	MTG_CF_ASSET_persistent_object* newP = (MTG_CF_ASSET_persistent_object*)new MTG_CF_ASSET_persistent_object
   	  ("mtg_cf_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			MTG_CF_ASSET_persistent_object* pd = dynamic_cast<MTG_CF_ASSET_persistent_object*>(product);
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
	if (rebasing_wanted && (!peer || peer != newP->sm_calling_model)) {
	if (find(unusedModels.begin(), unusedModels.end(), name + "|mtg_pv") == unusedModels.end()) {
	newP->sm_mtg_pv = (MTG_CF_ASSET*)MTG_CF_ASSET_persistent_object::makeThis(1, newP, newP, 0, name + "|mtg_pv", (MTG_CF_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_mtg_pv:0), fixedArray);
	newP->adopt(newP->sm_mtg_pv);
	}
	}

	if (rebasing_wanted && (!peer || peer != newP->sm_calling_model)) {
	if (find(unusedModels.begin(), unusedModels.end(), name + "|mtg_is") == unusedModels.end()) {
	newP->sm_mtg_is = (MTG_CF_ASSET*)MTG_CF_ASSET_persistent_object::makeThis(1, newP, newP, 0, name + "|mtg_is", (MTG_CF_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_mtg_is:0), fixedArray);
	newP->adopt(newP->sm_mtg_is);
	}
	}

	if (rebasing_wanted && (!peer || peer != newP->sm_calling_model)) {
	if (find(unusedModels.begin(), unusedModels.end(), name + "|mtg_ym") == unusedModels.end()) {
	newP->sm_mtg_ym = (MTG_CF_ASSET*)MTG_CF_ASSET_persistent_object::makeThis(1, newP, newP, 0, name + "|mtg_ym", (MTG_CF_ASSET_persistent_object*)(arrayTemplate?arrayTemplate->sm_mtg_ym:0), fixedArray);
	newP->adopt(newP->sm_mtg_ym);
	}
	}

	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	newP->msnumelement.setValue(0);
	return newP;
}

typedef double (MTG_CF_ASSET_UDF::*dPF) ();
typedef double (MTG_CF_ASSET_UDF::*dPFd) (double);
typedef int (MTG_CF_ASSET_UDF::*iPF) ();
typedef int (MTG_CF_ASSET_UDF::*iPFi) (int);
typedef xstring (MTG_CF_ASSET_UDF::*sPF) ();
typedef xstring (MTG_CF_ASSET_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
MTG_CF_ASSET::MTG_CF_ASSET(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)

  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)
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

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (MTG_CF_ASSET_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
MTG_CF_ASSET::MTG_CF_ASSET(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(45, MTG_CF_ASSET::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)

  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)
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

	for (int cf_no = 1; cf_no <= 45; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (MTG_CF_ASSET_UDF::*dPXi2) (int, int);
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

	  void MTG_CF_ASSET::Set_prepmt_rate(const long index, const double &value) { prepmt_rate[index] = value; } // set Lapse rates for prepmt_rate

 void MTG_CF_ASSET::copy_names() {

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


 void MTG_CF_ASSET::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int MTG_CF_ASSET_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& MTG_CF_ASSET_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double MTG_CF_ASSET_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int MTG_CF_ASSET_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double MTG_CF_ASSET_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double MTG_CF_ASSET_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void MTG_CF_ASSET_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void MTG_CF_ASSET_persistent_object::write(long include_submodels) {
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

	void MTG_CF_ASSET_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void MTG_CF_ASSET_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void MTG_CF_ASSET_persistent_object::write(const xstring& key, long include_submodels) {
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




	MTG_CF_ASSET_persistent_object::~MTG_CF_ASSET_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool MTG_CF_ASSET_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void MTG_CF_ASSET_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void MTG_CF_ASSET_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void MTG_CF_ASSET_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void MTG_CF_ASSET_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void MTG_CF_ASSET_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* MTG_CF_ASSET_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* MTG_CF_ASSET_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* MTG_CF_ASSET_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char MTG_CF_ASSET_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void MTG_CF_ASSET_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
MTG_CF_ASSET_persistent_object::MTG_CF_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			MTG_CF_ASSET(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(MTG_CF_ASSET::sm_bond_is)
	, sm_bond_pv(MTG_CF_ASSET::sm_bond_pv)
	, sm_bond_ym(MTG_CF_ASSET::sm_bond_ym)

	, sm_mtg_is(MTG_CF_ASSET::sm_mtg_is)
	, sm_mtg_pv(MTG_CF_ASSET::sm_mtg_pv)
	, sm_mtg_ym(MTG_CF_ASSET::sm_mtg_ym)
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
MTG_CF_ASSET::~MTG_CF_ASSET() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void MTG_CF_ASSET::findTargetColumns() {

}
//findTargetColumns END@2
void MTG_CF_ASSET::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void MTG_CF_ASSET::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void MTG_CF_ASSET::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void MTG_CF_ASSET::start_of_projection() {
}
//start_of_projection END@2

void MTG_CF_ASSET::end_of_projection() {
}
//end_of_projection END@2

void MTG_CF_ASSET::start_of_layer() {
}


void MTG_CF_ASSET::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void MTG_CF_ASSET::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void MTG_CF_ASSET::after_startup(int decrement) {
// Call startup for submodels
  if (indexOfChild(sm_mtg_pv) >= 0 && ! sm_mtg_pv->isShrunk) { // generated for clones only
  if(sm_mtg_pv)
   sm_mtg_pv->doBeforeStartupProcessing(decrement);
  }

  if (indexOfChild(sm_mtg_is) >= 0 && ! sm_mtg_is->isShrunk) { // generated for clones only
  if(sm_mtg_is)
   sm_mtg_is->doBeforeStartupProcessing(decrement);
  }

  if (indexOfChild(sm_mtg_ym) >= 0 && ! sm_mtg_ym->isShrunk) { // generated for clones only
  if(sm_mtg_ym)
   sm_mtg_ym->doBeforeStartupProcessing(decrement);
  }

}
//after_startup END@2


 void MTG_CF_ASSET::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> MTG_CF_ASSET::ddfVector;
BitArray MTG_CF_ASSET::dataVariables(10);
bool MTG_CF_ASSET::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool MTG_CF_ASSET::writeClassInfo = true;

void MTG_CF_ASSET::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, MTG_CF_ASSET::descriptor_0>::dT = MTG_CF_ASSET::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, MTG_CF_ASSET::descriptor_0>::dT = MTG_CF_ASSET::descriptor_0;

