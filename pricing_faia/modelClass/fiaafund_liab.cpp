
//MODELCLASS BEGIN
//MODELCLASS aa_comp_comp
//MODELCLASS adco_asset
//MODELCLASS ann_pba_pba
//MODELCLASS asset_asset
//MODELCLASS a_subport_asset
//MODELCLASS bond_asset
//MODELCLASS bond_cf_asset
//MODELCLASS eio_asset
//MODELCLASS epa_asset
//MODELCLASS epl_liab
//MODELCLASS fiaafund_liab
//MODELCLASS fiacarvm_liab
//MODELCLASS fia_liab
//MODELCLASS hdg_grp_comp
//MODELCLASS invstrat_asset
//MODELCLASS liab_liab
//MODELCLASS mrb_gaap
//MODELCLASS mtg_asset
//MODELCLASS mtg_cf_asset
//MODELCLASS rates_economy
//MODELCLASS seg_comp
//MODELCLASS sfas97rd_gaap
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
#include "ModelClass\aa_comp_comp.h"
#include "ModelClass\adco_asset.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\asset_asset.h"
#include "ModelClass\a_subport_asset.h"
#include "ModelClass\bond_asset.h"
#include "ModelClass\bond_cf_asset.h"
#include "ModelClass\eio_asset.h"
#include "ModelClass\epa_asset.h"
#include "ModelClass\epl_liab.h"
#include "ModelClass\fiacarvm_liab.h"
#include "ModelClass\fia_liab.h"
#include "ModelClass\hdg_grp_comp.h"
#include "ModelClass\invstrat_asset.h"
#include "ModelClass\liab_liab.h"
#include "ModelClass\mrb_gaap.h"
#include "ModelClass\mtg_asset.h"
#include "ModelClass\mtg_cf_asset.h"
#include "ModelClass\rates_economy.h"
#include "ModelClass\seg_comp.h"
#include "ModelClass\sfas97rd_gaap.h"
#pragma optimize( "gs", on )

#include "generatedCppHeader.h"

#line 1 "All Model Classes.extern"
#ifndef __UTILITIES_H_
#define __UTILITIES_H_
//Redundant includes only for snip test:
//iomanip included for "setprecision()"
#include <iomanip>
#include <strstream>
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
const int pv = 0;
const int is = 1;
const int ym = 2;
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
const double MINIMUM_MONTHLY_YIELD_RATIO = -0.9; // annual yield = (1.0-0.9)^12 = 1.0e-12
const double MAXIMUM_MONTHLY_YIELD_RATIO	 = 999999999.0; // annual yield = (1.0+999999999.0)^12 = 1.0e+120
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
const int CALL_CODE = 1;
const int PUT_CODE = 2;
const int CONTINUOUS_PAYOUT_CODE = 3;
const int FUTURES_CODE = 4;
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
extern bool pricing_flag;
extern bool factors_flag;
extern bool nb_flag;
extern bool alm_flag;
extern bool tcm_flag;
extern bool pba_disc_rate_flag;
extern int pba_segment_size;
extern bool avr_flag;
extern bool imr_flag;
extern bool gaap_flag;
extern bool tgt_cap_flag;
extern bool stoch_flag;
extern bool valn_flag;
extern bool time_step_flag;
extern bool mrb_valn_flag;
extern bool sop031_valn_flag;
extern bool sfas97rd_valn_flag;
extern bool sfas91_valn_flag;
extern bool gaap_ldti_valn_flag;
extern bool sfas120_nlp_valn_flag;
extern bool loc_gpr_valn_flag;
extern bool pba_valn_flag;
extern bool pba_scen_amt_valn_flag;
extern bool rbc_scen_amt_valn_flag;
extern bool res_scen_amt_valn_flag;
extern bool res_det_res_valn_flag;
extern bool res_ag38_8d_valn_flag;
extern bool std_scen_valn_flag;
extern bool std_scen_prescribed_assump_flag;
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
extern double round_result(int rounding, int negative, double x, int n);
extern double factorial(int n);
extern int n_choose_k(int n, int k);
extern xstring check_date_format(const xstring &date);
extern int month_from_day_number(int nSerialDate);
extern int year_from_day_number(int nSerialDate);
extern int day_from_day_number(int nSerialDate);
extern int month_number_from_date(int year, int month); 
extern int day_number_from_date(int nYear, int nMonth, int nDay);
extern int get_mth_from_date(const xstring &date);
extern int get_yr_from_date(const xstring &date);
extern int get_day_from_date(const xstring &date);
extern int get_end_of_mth_day(int yr, int mth);
extern xstring add_mths_to_date(const xstring &date, int mths);
extern int get_mth_from_adj_date(const xstring &date, int mths);
extern double convert_rate_basis(double orig_rate, double orig_rate_basis, double new_rate_basis);
extern double convert_decrem_rate_basis(double orig_rate, double orig_rate_basis, double new_rate_basis);
extern xstring get_file_name(const xstring &source_file);
extern xstring get_file_path(const xstring &source_file);
extern xstring get_base_group_name(const xstring &tag, bool split_flag = false);
extern xstring get_string_of_date(double date);
extern xstring get_string_of_enum_val(StrEnum::EnumValue type);
extern int date_diff(xstring first_date, xstring second_date);
extern int number_of_decimals(double xxx,int digits);
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
extern double cumul_normal_distribn(double x);

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
if (t <= commencement_period || t > maturity_period)
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

//@@ START - credited_int
// Credited Interest                                                                                             
// Column:CREDITED_INT
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_credited_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"credited_int",t);
}



//^^^

#line 1 "credited_int.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return fund_val_b(t) * crediting_rate(t);

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
//20250430 Replaced USL code with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (crediting_rate_defn == FIXED_RATE)
    return NO_AVG;

if (crediting_dyn_lever != DYNAMIC_CAP)
	return payout_index_max;	

if (t + elapsed_mths <= crediting_rate_guar_mths) 
	return fia->nb_cap_rate_crbg;

if (t == 0 && valn_period != 0)
	return init_fia_cap;

if (mod(t + elapsed_mths, crediting_mths) == 1)
{
	double rf_rate, long_call_opt_cost, short_call_opt_cost, solved_cap;
	double option_budget = opt_budget(t);

	if (valn_flag)
	{
		double vol_param, dividend_yld; 
		fia->index_id_lookup = crediting_eqt_index;
		vol_param = fia->bs_fwd_vol_crbg;

		fia->index_id_lookup = crediting_eqt_index;
		dividend_yld = fia->bs_dividend_crbg;

		rf_rate	= rates->get_int_rate(t - 1, "Govt", GET_SPOT_RATE, crediting_mths / 12., 0.0, NOMINAL_SEMIANNUAL, NO_SHIFT);
		long_call_opt_cost = bs_opt_val(1 + crediting_floor, crediting_mths / 12., 1, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
		short_call_opt_cost	= long_call_opt_cost - option_budget + crediting_floor / (1 + rf_rate);
		solved_cap = get_bs_opt_strike_crbg(rf_rate, vol_param, dividend_yld, short_call_opt_cost, crediting_mths) - 1.;
	}
	else
	{
		rf_rate = rates_ptr->get_int_rate(t - 1, "Swap", GET_YIELD_RATE, crediting_mths / 12., 0, EFFECTIVE_ANNUAL, NO_SHIFT);
		long_call_opt_cost	= get_option_price_crbg(t - 1, 1 + crediting_floor, CALL, crediting_mths);
		short_call_opt_cost	= long_call_opt_cost - option_budget + crediting_floor / (1 + rf_rate);
		solved_cap = get_option_strike_crbg(t - 1, short_call_opt_cost, CALL, crediting_mths) - 1.;
	}
	
	solved_cap = max(min(crediting_cap_max, solved_cap), crediting_cap_min);

	double prior_cap_rate = crediting_cap_rate(t - 1);

	if (abs(solved_cap - prior_cap_rate) < rate_chg_threshold_crbg)
	{
		return prior_cap_rate;
	}
	else
	{
		return solved_cap;
	}
}

return crediting_cap_rate(t - 1);

}

//@@ END

//@@ START - crediting_part_rate
// Crediting Part Rate (Solved from Call Spread)                                                                                             
// Column:CREDITING_PART_RATE
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_part_rate(int t) {
//^^^



//^^^

#line 1 "crediting_part_rate.FIAAFUND_LIAB.for"
//20250430 Replaced USL code with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (crediting_rate_defn == FIXED_RATE)
    return NO_AVG;

if (crediting_dyn_lever == DYNAMIC_SPRD)
	return 1.;

if (crediting_dyn_lever != DYNAMIC_PART && crediting_dyn_lever != DYNAMIC_PART_EPRS && crediting_dyn_lever != DYNAMIC_PART_SPRD) 
	return NO_AVG;

if (t + elapsed_mths <= crediting_rate_guar_mths) 
	return fia->nb_part_rate_crbg;

if (t == 0 && valn_period != 0)
	return init_part_rate;

if (mod(t + elapsed_mths, crediting_mths) == 1)
{
	double option_budget = opt_budget(t);
	double long_call_opt_cost, benchmark_cost, strike_max_par, vol_param, dividend_yld, rf_rate;

	if (valn_flag)
	{
		fia->index_id_lookup = crediting_eqt_index;
		vol_param = fia->bs_fwd_vol_crbg;

		fia->index_id_lookup = crediting_eqt_index;
		dividend_yld = fia->bs_dividend_crbg;

		rf_rate = rates_ptr->get_int_rate(t - 1, "Govt", GET_SPOT_RATE, crediting_mths / 12., 0.0, NOMINAL_SEMIANNUAL, NO_SHIFT);
		long_call_opt_cost = bs_opt_val(1., crediting_mths / 12., 1, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	}
	else
	{
		long_call_opt_cost = get_option_price_crbg(t - 1, 1, CALL, crediting_mths);
	}

	double solved_part_rt = 0;
	if(crediting_dyn_lever == DYNAMIC_PART || crediting_dyn_lever == DYNAMIC_PART_EPRS)
	{
		if (long_call_opt_cost > SMALL_DOUBLE)
			solved_part_rt = opt_budget(t) / long_call_opt_cost;
	}
	else //DYNAMIC_PART_SPRD
	{
		if (valn_flag)
		{
			benchmark_cost = crediting_part_min * bs_opt_val(1. + fia->nb_sprd_rate_crbg / crediting_part_min, crediting_mths / 12., 1, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			strike_max_par = crediting_part_max * (get_bs_opt_strike_crbg(rf_rate, vol_param, dividend_yld, option_budget / crediting_part_max, crediting_mths) - 1.);
		}
		else
		{
			benchmark_cost = crediting_part_min * get_option_price_crbg(t - 1, 1. + fia->nb_sprd_rate_crbg / crediting_part_min, CALL, crediting_mths);
			strike_max_par = crediting_part_max * (get_option_strike_crbg(t - 1, option_budget / crediting_part_max, CALL, crediting_mths) - 1);
		}

		if (option_budget > benchmark_cost)
		{
			if (fia->nb_sprd_rate_crbg < SMALL_DOUBLE)
			{
				if (valn_flag)
					solved_part_rt = option_budget / bs_opt_val(1., crediting_mths / 12., 1, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
				else
					solved_part_rt = option_budget / get_option_price_crbg(t - 1, 1., CALL, crediting_mths);
			}
			else if (option_budget >= strike_max_par)
			{
				solved_part_rt = crediting_part_max;
			}
			else
			{
				solved_part_rt = part_rate_solver_crbg(t, option_budget, crediting_part_min, crediting_part_max);
			}
		}
		else
		{
			solved_part_rt = crediting_part_min;
		}
	}

	solved_part_rt = max(min(crediting_part_max, solved_part_rt), crediting_part_min);

	double prior_part_rate = crediting_part_rate(t - 1);

	if (abs(solved_part_rt - prior_part_rate) < rate_chg_threshold_crbg)
	{
		return prior_part_rate;
	}
	else
	{
		return solved_part_rt;
	}
}

return crediting_part_rate(t - 1);

}

//@@ END

//@@ START - crediting_rate
// Monthly Crediting Rate                                                                                             
// Column:CREDITING_RATE
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(5,"crediting_rate",t);
}



//^^^

#line 1 "crediting_rate.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (sfas97rd_valn_flag)
	return convert_rate_basis(fia->gaap_int_rate, EFFECTIVE_ANNUAL, - 12);

// Do not credit interest unless EOP except for fixed rate
if (crediting_rate_defn != FIXED_RATE && mod(t + elapsed_mths, crediting_mths) != 0) 
	return 0.0;

//Replaced with CRBG logic	
if (crediting_rate_defn == POINT_TO_POINT) 
{
	double growth_rate = strategy_return_crbg(t);

	return growth_rate;	
}
	
 //crediting_rate_defn == Fixed_Rate
 return pow(1.0 + crediting_rate_fix(t), 1.0 / 12.0) - 1.0;

}

//@@ END

//@@ START - crediting_rate_cumul_crbg
// Crediting Rate Cumul Crbg                                                                                             
// Column:CREDITING_RATE_CUMUL_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_cumul_crbg(int t) {
//^^^



//^^^

#line 1 "crediting_rate_cumul_crbg.FIAAFUND_LIAB.for"
//20250506 Customized new column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if ((mod(t + elapsed_mths, crediting_mths) == 0))
{
	if (crediting_rate_defn == FIXED_RATE)
	{
		return crediting_rate_fix(t);
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
	return rebase_value(7,"crediting_rate_fix",t);
}



//^^^

#line 1 "crediting_rate_fix.FIAAFUND_LIAB.for"
//20250430 Replaced USL code with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (fia->annuity_type_crbg == "FA")
	return fa_crediting_rate_crbg(t);

if (crediting_rate_defn != FIXED_RATE)
    return NO_AVG;

if (t + elapsed_mths <= crediting_rate_guar_mths) 
	return fia->nb_fixed_rate_crbg;

if (t == 0 && valn_period != 0)
	return fia->crediting_rate_fixed;

if (mod(t + elapsed_mths, crediting_mths) == 1)
{
	double fixed_rate = max(crediting_floor, opt_budget(t));

	double prior_fixed_rate = crediting_rate_fix(t - 1);

	if (abs(fixed_rate - prior_fixed_rate) < rate_chg_threshold_crbg)
	{
		return prior_fixed_rate;
	}
	else
	{
		return fixed_rate;
	}
}

return crediting_rate_fix(t - 1);

}

//@@ END

//@@ START - crediting_sprd_rate_crbg
// Crediting Spread Rate                                                                                             
// Column:CREDITING_SPRD_RATE_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_sprd_rate_crbg(int t) {
//^^^



//^^^

#line 1 "crediting_sprd_rate_crbg.FIAAFUND_LIAB.for"
//20250624 Customized new column
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (crediting_rate_defn == FIXED_RATE)
    return NO_AVG;

if (crediting_dyn_lever != DYNAMIC_SPRD && crediting_dyn_lever != DYNAMIC_PART_SPRD)
    return NO_AVG;

if (t + elapsed_mths <= crediting_rate_guar_mths) 
	return fia->nb_sprd_rate_crbg;

if (t == 0 && valn_period != 0)
	return init_sprd_rate;

if (mod(t + elapsed_mths, crediting_mths) == 1)
{	
	double option_budget = opt_budget(t);
	double calc_sprd_rate, benchmark_cost, vol_param, dividend_yld, rf_rate;

	if (valn_flag)
	{
		fia->index_id_lookup = crediting_eqt_index;
		vol_param = fia->bs_fwd_vol_crbg;

		fia->index_id_lookup = crediting_eqt_index;
		dividend_yld = fia->bs_dividend_crbg;

		rf_rate = rates_ptr->get_int_rate(t - 1, "Govt", GET_SPOT_RATE, crediting_mths / 12., 0.0, NOMINAL_SEMIANNUAL, NO_SHIFT);
	}
	
	if (crediting_dyn_lever == DYNAMIC_SPRD)
	{
		if (valn_flag)
			calc_sprd_rate = get_bs_opt_strike_crbg(rf_rate, vol_param, dividend_yld, option_budget, crediting_mths) - 1.;
		else
			calc_sprd_rate = get_option_strike_crbg(t - 1, option_budget, CALL, crediting_mths) - 1.; 	
	}
	else //DYNAMIC_PART_SPRD
	{
		if (valn_flag)
			benchmark_cost = bs_opt_val(1. + fia->nb_sprd_rate_crbg / crediting_part_min, crediting_mths / 12., 1, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
		else
			benchmark_cost = get_option_price_crbg(t - 1, 1. + fia->nb_sprd_rate_crbg / crediting_part_min, CALL, crediting_mths);

		benchmark_cost *= crediting_part_min;

		if (option_budget > benchmark_cost)
		{
			calc_sprd_rate = fia->nb_sprd_rate_crbg;
		}
		else if (option_budget > 0)
		{
			if (valn_flag)
				calc_sprd_rate = get_bs_opt_strike_crbg(rf_rate, vol_param, dividend_yld, option_budget / crediting_part_min, crediting_mths) - 1.;
			else
				calc_sprd_rate = get_option_strike_crbg(t - 1, option_budget / crediting_part_min, CALL, crediting_mths) - 1.;
		
			calc_sprd_rate *= crediting_part_min;
		}
		else
		{
			calc_sprd_rate = crediting_sprd_max;
		}
	}

	calc_sprd_rate = max(min(crediting_sprd_max, calc_sprd_rate), crediting_sprd_min);

	double prior_sprd_rate = crediting_sprd_rate_crbg(t - 1);

	if (abs(calc_sprd_rate - prior_sprd_rate) < rate_chg_threshold_crbg)
	{
		return prior_sprd_rate;
	}
	else
	{
		return calc_sprd_rate;
	}
}

return crediting_sprd_rate_crbg(t - 1);

}

//@@ END

//@@ START - crediting_trigger_rate_crbg
// Crediting Trigger Rate Crbg                                                                                             
// Column:CREDITING_TRIGGER_RATE_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_trigger_rate_crbg(int t) {
//^^^



//^^^

#line 1 "crediting_trigger_rate_crbg.FIAAFUND_LIAB.for"
//20250624 Customized new column
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (crediting_rate_defn == FIXED_RATE || crediting_dyn_lever != DYNAMIC_TRIGGER)
    return NO_AVG;

if (t + elapsed_mths <= crediting_rate_guar_mths) 
	return fia->nb_trigger_rate_crbg;

if (t == 0 && valn_period != 0)
	return init_trigger_rate;

if (mod(t + elapsed_mths, crediting_mths) == 1)
{	
	double option_cost_one_percent;

	if (valn_flag)
	{
		double vol_param, dividend_yld; 
		fia->index_id_lookup = crediting_eqt_index;
		vol_param = fia->bs_fwd_vol_crbg;

		fia->index_id_lookup = crediting_eqt_index;
		dividend_yld = fia->bs_dividend_crbg;

		double pos_sprd = 0.;
		double neg_sprd = 0.01;

		double rf_rate	= rates->get_int_rate(t - 1, "Govt", GET_SPOT_RATE, crediting_mths / 12., 0.0, NOMINAL_SEMIANNUAL, NO_SHIFT);
		double call_k_pos = bs_opt_val(1 + pos_sprd, crediting_mths / 12., 1, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
		double call_k_neg = bs_opt_val(1 - neg_sprd, crediting_mths / 12., 1, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);

		option_cost_one_percent = (call_k_neg - call_k_pos) / (pos_sprd + neg_sprd);
	}
	else
	{
		xstring rate_lookup = "BINY_" + crediting_eqt_index + "_D" + xstring(crediting_mths) + "_K100";
		option_cost_one_percent = rates_ptr->get_misc_rate(t - 1, rate_lookup, EFFECTIVE_ANNUAL);
	}

	double calc_trigger_rate = opt_budget(t) / option_cost_one_percent; 	

	calc_trigger_rate = max(min(crediting_trigger_max, calc_trigger_rate), crediting_trigger_min);

	double prior_trigger_rate = crediting_trigger_rate_crbg(t - 1);

	if (abs(calc_trigger_rate - prior_trigger_rate) < rate_chg_threshold_crbg)
	{
		return prior_trigger_rate;
	}
	else
	{
		return calc_trigger_rate;
	}
}

return crediting_trigger_rate_crbg(t - 1);

}

//@@ END

//@@ START - enhanced_part_rate_crbg
// Crediting Part Rate Enhanced                                                                                             
// Column:ENHANCED_PART_RATE_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_enhanced_part_rate_crbg(int t) {
//^^^



//^^^

#line 1 "enhanced_part_rate_crbg.FIAAFUND_LIAB.for"
//20250624 Customized new column
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (crediting_dyn_lever != DYNAMIC_PART_EPRS) 
	return NO_AVG;

if (t == 0 && valn_period != 0)
	return fia->init_eprs_part_rate;

double enhanced_rate;

if (t + elapsed_mths <= crediting_rate_guar_mths) 
{
	enhanced_rate = crediting_part_rate(t) + fia->nb_eprs_add_par_crbg;
	return min(enhanced_rate, crediting_part_eprs_max);
}

if (mod(t + elapsed_mths, crediting_mths) == 1)
{
	double solved_add_par_rate = opt_budget_eprs_crbg(t) / opt_cost_atm_crbg(t);

	// threshold for additional par rate
	double prior_add_part_rate = enhanced_part_rate_crbg(t - 1) - crediting_part_rate(t - 1);
	if (abs(solved_add_par_rate - prior_add_part_rate) < eprs_add_par_threshold)
	{
		solved_add_par_rate = prior_add_part_rate;
	}

	// rounding
	solved_add_par_rate = round(solved_add_par_rate / eprs_rounding_mult, 0) * eprs_rounding_mult;

	// min for add par rate	
	solved_add_par_rate = max(solved_add_par_rate, eprs_add_part_min);

	//total rate
	enhanced_rate = crediting_part_rate(t) + solved_add_par_rate;
	enhanced_rate = max(min(crediting_part_eprs_max, enhanced_rate), crediting_part_eprs_min);

	return enhanced_rate;
}

return enhanced_part_rate_crbg(t - 1);

}

//@@ END

//@@ START - eprs_sfc_ben_crbg
// Eprs Sfc Ben                                                                                             
// Column:EPRS_SFC_BEN_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_eprs_sfc_ben_crbg(int t) {
//^^^



//^^^

#line 1 "eprs_sfc_ben_crbg.FIAAFUND_LIAB.for"
//20250715 Customized new column: Strategy fee credit for EPS
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (crediting_dyn_lever != DYNAMIC_PART_EPRS || fia->eprs_sfc_defn == NO) 
	return NO_AVG;

if (t + elapsed_mths == fia->surr_chg_period_crbg * 12 + 1)
{
	double fund_val = fund_val_b_bef(t) - gmwb_chg(t) - eprs_strat_fee_crbg(t);
	return max(0, eprs_sfc_ben_gross_crbg(t) - fund_val);
}

return 0.;

}

//@@ END

//@@ START - eprs_sfc_ben_gross_crbg
// Eprs Sfc Ben Gross Crbg                                                                                             
// Column:EPRS_SFC_BEN_GROSS_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_eprs_sfc_ben_gross_crbg(int t) {
//^^^



//^^^

#line 1 "eprs_sfc_ben_gross_crbg.FIAAFUND_LIAB.for"
//20250715 Customized new column: Strategy fee credit for EPS
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (crediting_dyn_lever != DYNAMIC_PART_EPRS || fia->eprs_sfc_defn == NO) 
	return NO_AVG;

if (t + elapsed_mths == 1)
	return fia->prem_paid(t) * fund_val_split_prop;

return max(0, eprs_sfc_ben_gross_crbg(t - 1) * fia->surv_period(t - 1) - fund_released_withdrl(t - 1) - gmwb_chg(t));

}

//@@ END

//@@ START - eprs_strat_fee_crbg
// Eprs Strat Fee Crbg                                                                                             
// Column:EPRS_STRAT_FEE_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_eprs_strat_fee_crbg(int t) {
//^^^



//^^^

#line 1 "eprs_strat_fee_crbg.FIAAFUND_LIAB.for"
//20250624 Customized new column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (crediting_dyn_lever != DYNAMIC_PART_EPRS) 
	return NO_AVG;

if (mod(t + elapsed_mths, crediting_mths) == 1 
		&& fia->pol_yr(t) > 1 
		&& fund_val_b_bef(t) - gmwb_chg(t) > SMALL_DOUBLE) 
{
	double fee_rate = eprs_strat_fee_pct_crbg;
	double fee_base = fund_val_beg_term_e_crbg(t - 1);
	double eprs_fee = fee_rate * fee_base * (crediting_mths / 12.);

	return min(fund_val_b_bef(t) - gmwb_chg(t), eprs_fee);
}

return 0.;

}

//@@ END

//@@ START - eprs_strat_fee_partial_bef_crbg
// Eprs Strat Fee Crbg partial                                                                                             
// Column:EPRS_STRAT_FEE_PARTIAL_BEF_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_eprs_strat_fee_partial_bef_crbg(int t) {
//^^^



//^^^

#line 1 "eprs_strat_fee_partial_bef_crbg.FIAAFUND_LIAB.for"
//20250624 Customized new column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (crediting_dyn_lever != DYNAMIC_PART_EPRS) 
	return NO_AVG;

// Why?
if(t + elapsed_mths == fia->surr_chg_period_crbg * 12 + 1)
{
	return 0;
}

double fund_val = fund_val_e_bef(t) - gmwb_chg_partial_bef_crbg(t);
if (fund_val > SMALL_DOUBLE) 
{
	double fee_rate = eprs_strat_fee_pct_crbg;
	double fee_base = fund_val_beg_term_crbg(t);

	double eprs_fee = fee_rate * fee_base * index_term_elapsed_pct_crbg(t);

	return min(fund_val, eprs_fee);
}

return 0.;

}

//@@ END

//@@ START - eprs_strat_fee_partial_e_crbg
// Eprs Strat Fee Crbg partial                                                                                             
// Column:EPRS_STRAT_FEE_PARTIAL_E_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_eprs_strat_fee_partial_e_crbg(int t) {
//^^^



//^^^

#line 1 "eprs_strat_fee_partial_e_crbg.FIAAFUND_LIAB.for"
//20250624 Customized new column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (crediting_dyn_lever != DYNAMIC_PART_EPRS) 
	return NO_AVG;

// Why?
if(t + elapsed_mths == fia->surr_chg_period_crbg * 12 + 1)
{
	return 0;
}

double fund_val = fund_val_e(t) - gmwb_chg_partial_e_crbg(t);
if (fund_val > SMALL_DOUBLE) 
{
	double fee_rate = eprs_strat_fee_pct_crbg;
	double fee_base = fund_val_beg_term_e_crbg(t);

	double eprs_fee = fee_rate * fee_base * index_term_elapsed_pct_crbg(t);

	return min(fund_val, eprs_fee);
}

return 0.;

}

//@@ END

//@@ START - fa_crediting_rate_crbg
// Fa Crediting Rate Crbg                                                                                             
// Column:FA_CREDITING_RATE_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fa_crediting_rate_crbg(int t) {
//^^^



//^^^

#line 1 "fa_crediting_rate_crbg.FIAAFUND_LIAB.for"
//20251216 Customized new column
if (t <= commencement_period || t > maturity_period || fia->annuity_type_crbg != "FA")
{
	return NO_AVG;	
}

if (fia->pol_yr(t) <= fia->myga_init_term_crbg)
{
	return fa_pricing_rate_crbg(t);
}

if (fia->myga_term_mth_elapsed_eom_crbg(t) != 1)
{
	return fa_crediting_rate_crbg(t - 1);
}

double new_money_rate = fia->nmr_7yr_govt_plus_sprd_crbg(t - 1);

//MYGA renewable term
if (fia->myga_renew_ind_crbg == YES && fia->myga_current_term_crbg(t) > 1)
{
	return new_money_rate;
}

//final rate
double prior_rate = fa_crediting_rate_crbg(t - 1);
double ref_rate = fa_reference_rate_crbg(t);
double min_rate = fia->fa_guar_rate_crbg;
double dynamic_beta;
double rate_ren_max = fia->fa_renew_rate_max_crbg;

if (fabs(new_money_rate - prior_rate) < SMALL_DOUBLE)
{
	dynamic_beta = fia->fa_credit_dyn_beta_a_crbg;
}
else if (fabs(new_money_rate - prior_rate) <= 0.02)
{
	dynamic_beta = fia->fa_credit_dyn_beta_b_crbg;
}
else
{
	dynamic_beta = fia->fa_credit_dyn_beta_c_crbg;
}

double final_rate = min(prior_rate + rate_ren_max, 
						prior_rate + dynamic_beta * (ref_rate - prior_rate));

if ( fabs(final_rate - prior_rate) > rate_chg_threshold_crbg )
{
	return max(final_rate, min_rate);
}
else
{
	return prior_rate;
}


}

//@@ END

//@@ START - fa_pricing_rate_crbg
// Fa Pricing Rate Crbg                                                                                             
// Column:FA_PRICING_RATE_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fa_pricing_rate_crbg(int t) {
//^^^



//^^^

#line 1 "fa_pricing_rate_crbg.FIAAFUND_LIAB.for"
//20251216 Customized new column
if (t < commencement_period || t > maturity_period || fia->annuity_type_crbg != "FA")
{
	return NO_AVG;	
}

if (t == 0 && valn_period != 0)
	return fia->fa_pricing_rate;

double ner_init		= fia->crediting_ner_crbg;
double init_sprd	= fia->fa_init_pri_sprd_crbg;
double init_bonus	= fia->fa_init_bonus_crbg;
double tgt_sprd		= fia->pri_sprd_tgt_crbg;
double min_rate		= fia->fa_guar_rate_crbg;

double init_rate = max(ner_init - init_sprd + init_bonus, min_rate);

if (fia->pol_yr(t) <= fia->myga_init_term_crbg)
	return init_rate;

if (fia->myga_term_mth_elapsed_eom_crbg(t) != 1)
	return fa_pricing_rate_crbg(t - 1);

double ner_cv		= fia->avg_coupon_rt_crbg(t - 1); 
double ner_cv_prev	= fia->asset_yld_fa_rate_setting_crbg(t - 1); 

if (fia->ner_correction_crbg == NO && !alm_flag) //To match back to old model
	ner_cv = fia->avg_coupon_rt_crbg(t - 2);

if (!isMainModel && alm_flag)
	ner_cv = fia->asset_yld_inv_adj_crbg(t - 1);

double beta = 0.0;
if (ner_cv > ner_cv_prev)
	beta = fia->renewal_beta_up_crbg; 
else
	beta = fia->renewal_beta_down_crbg; 

double pricing_rate; 
double alpha = fia->tgt_budget_alpha_crbg;
double liquidity_sprd = fia->tgt_budget_reduction_crbg;

if (fia->pol_yr(t) <= fia->fa_rate_migration_yr_crbg)
{
	pricing_rate = ner_cv - (init_sprd + liquidity_sprd * fia->pol_yr(t) / fia->fa_rate_migration_yr_crbg);
}
else
{
	double prior_rate = fa_pricing_rate_crbg(t - 1);
	double prior_sprd = ner_cv_prev - prior_rate;

	pricing_rate = prior_rate + beta * (ner_cv - ner_cv_prev) - alpha * (tgt_sprd + liquidity_sprd - prior_sprd);
}

pricing_rate = max(pricing_rate, min_rate);

return pricing_rate;



}

//@@ END

//@@ START - fa_reference_rate_crbg
// Fa Reference Rate Crbg                                                                                             
// Column:FA_REFERENCE_RATE_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fa_reference_rate_crbg(int t) {
//^^^



//^^^

#line 1 "fa_reference_rate_crbg.FIAAFUND_LIAB.for"
//20251216 Customized new column
if (t <= commencement_period || t > maturity_period || fia->annuity_type_crbg != "FA")
{
	return NO_AVG;	
}

//Reference rate
double ref_rate;
double ner_cv = fia->avg_coupon_rt_crbg(t - 1); 
double new_money_rate = fia->nmr_7yr_govt_plus_sprd_crbg(t - 1);
double ner_cap_sprd = fia->fa_ner_cap_sprd_crbg;

if (fia->ner_correction_crbg == NO && !alm_flag) //To match back to old model
{
	ner_cv = fia->avg_coupon_rt_crbg(t - 2);
}

if (!isMainModel && alm_flag)
{
	ner_cv = fia->asset_yld_inv_adj_crbg(t - 1);
}

if (new_money_rate > ner_cv) 
{
	ref_rate = ner_cv - ner_cap_sprd;
}
else if (new_money_rate < ner_cv - 0.015) 
{
	ref_rate = fa_pricing_rate_crbg(t);
}
else
{
	double weight_cr = (ner_cv - new_money_rate) / 0.015; 
	ref_rate = weight_cr * fa_pricing_rate_crbg(t) + (1 - weight_cr) * (ner_cv - ner_cap_sprd);
}

double min_rate = fia->fa_guar_rate_crbg;

ref_rate = max(ref_rate, min_rate);

return ref_rate;


}

//@@ END

//@@ START - fund_released_ann
// Fund Released on Annuitization                                                                                             
// Column:FUND_RELEASED_ANN
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_ann(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(19,"fund_released_ann",t);
}



//^^^

#line 1 "fund_released_ann.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
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
	return rebase_value(20,"fund_released_dth",t);
}



//^^^

#line 1 "fund_released_dth.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

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
	return rebase_value(21,"fund_released_maturity",t);
}



//^^^

#line 1 "fund_released_maturity.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (t!= maturity_period)
	return 0.0;

return fund_val_e_bef(t)
   	- fund_released_dth(t)
   	- fund_released_surr(t)
   	- fund_released_ann(t)
	   - fund_released_withdrl(t);

}

//@@ END

//@@ START - fund_released_surr
// Fund Released on Surrender                                                                                             
// Column:FUND_RELEASED_SURR
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_surr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(22,"fund_released_surr",t);
}



//^^^

#line 1 "fund_released_surr.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

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
	return rebase_value(23,"fund_released_withdrl",t);
}



//^^^

#line 1 "fund_released_withdrl.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
if (fia->fund_val_b_bef(t) < model_point_amount_threshold)
	return 0.0;	

//20250502 Replaced with CRBG logic. Avoid going through pfwd_surr... columns.
double wdl_benefit = fia->withdrl_benefits_gross_crbg(t) * fund_val_split_prop;

if (fia->min_accum_val_e_bef_crbg(t) > fia->fund_val_e_bef(t))
{
	wdl_benefit *= fia->fund_val_e_bef(t) / fia->min_accum_val_e_bef_crbg(t);
}

return wdl_benefit;

}

//@@ END

//@@ START - fund_val_b
// Fund Value After Outflow - BOM                                                                                             
// Column:FUND_VAL_B
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_b(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(24,"fund_val_b",t);
}



//^^^

#line 1 "fund_val_b.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return fund_val_b_bef(t)
       - admin_fee(t)
	   - gmwb_chg(t)
	   - eprs_strat_fee_crbg(t)
	   + eprs_sfc_ben_crbg(t);

}

//@@ END

//@@ START - fund_val_b_bef
// Fund Value Before Outflow BOM                                                                                             
// Column:FUND_VAL_B_BEF
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_b_bef(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(25,"fund_val_b_bef",t);
}



//^^^

#line 1 "fund_val_b_bef.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double fund_val_b_bef = fund_val_e(t - 1) + fund_val_rebal(t) + prem_alloc(t);

//20250625 Add MAV logic for NYIA						
if (fia->pol_yr(t) > fia->surr_chg_period_crbg && fia->pol_mth(t) == 1 && fia->nyia_ind_crbg == YES)
{
	fund_val_b_bef = max(fund_val_b_bef, fia->min_accum_val_e_crbg(t - 1) * fund_val_split_prop);
}

return fund_val_b_bef;					

}

//@@ END

//@@ START - fund_val_beg_term_crbg
// fund val Beg Term Crbg                                                                                             
// Column:FUND_VAL_BEG_TERM_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_beg_term_crbg(int t) {
//^^^



//^^^

#line 1 "fund_val_beg_term_crbg.FIAAFUND_LIAB.for"
//20250521 Customized new column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;	

if (mod(t + elapsed_mths, crediting_mths) == 1)
	return fund_val_b(t);

else
	return fund_val_beg_term_e_crbg(t - 1);

}

//@@ END

//@@ START - fund_val_beg_term_e_crbg
// fund val Beg Term Crbg                                                                                             
// Column:FUND_VAL_BEG_TERM_E_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_beg_term_e_crbg(int t) {
//^^^



//^^^

#line 1 "fund_val_beg_term_e_crbg.FIAAFUND_LIAB.for"
//20250521 Customized new column
if (t < commencement_period || t > maturity_period)
	return NO_AVG;	

if (t == 0 && valn_period != 0)
	return fia->fund_val_beg_term;

return fund_val_beg_term_crbg(t) * fia->surv_period(t);

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
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return (fund_released_dth(t)
	    + fund_released_surr(t)
	    + fund_released_ann(t)
	    + fund_released_withdrl(t)
	    + fund_released_maturity(t)
	    + admin_fee(t)
	    + gmwb_chg(t))
	   * pct_to_hedge;

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
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

// Set Fund Value at start of projection to amount specified in data file.
if (t == commencement_period)
	{
	if (elapsed_mths > 0)
		return init_fund_val;

	return 0.0;
	}

//opt_value_net_numer(t);//force calling 20250429 MQ commented out

double claims_av = 0.0;

claims_av = fund_released_dth(t)
			+ fund_released_surr(t)
			+ fund_released_ann(t)
			+ fund_released_withdrl(t)
			+ fund_released_maturity(t);

if (fund_val_e_bef(t) - claims_av < model_point_amount_threshold)
	return 0.0;

return (fund_val_e_bef(t) - claims_av);

}

//@@ END

//@@ START - fund_val_e_bef
// Fund Value Before Outflow EOM                                                                                             
// Column:FUND_VAL_E_BEF
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_e_bef(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(30,"fund_val_e_bef",t);
}



//^^^

#line 1 "fund_val_e_bef.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double fund_val = max(0., fund_val_b(t) + credited_int(t) - gmab_chg_crbg(t));

//GMAB logic
if (fia->gmab_ind_crbg == 1 && t + elapsed_mths == fia->surr_chg_period_crbg * 12) 
{
	double prem_less_withdrl = fia->prem_cumul_prop_wdl_bef_crbg(t) * fund_val_split_prop;
	double gmab_cap = prem_less_withdrl * fia->gmab_av_cap_rt_crbg;

	fund_val = max(fund_val, min(gmab_av_e_bef_crbg(t), gmab_cap));
	fund_val = max(prem_less_withdrl, fund_val);
}

return fund_val;  

}

//@@ END

//@@ START - fund_val_rebal
// Rebalancing Transfer to Account                                                                                             
// Column:FUND_VAL_REBAL
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_rebal(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(31,"fund_val_rebal",t);
}



//^^^

#line 1 "fund_val_rebal.FIAAFUND_LIAB.for"
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

//@@ START - gmab_av_b_crbg
// Gmab Av B Crbg                                                                                             
// Column:GMAB_AV_B_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_av_b_crbg(int t) {
//^^^



//^^^

#line 1 "gmab_av_b_crbg.FIAAFUND_LIAB.for"
//20251211 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period || fia->gmab_ind_crbg == 0)
	return NO_AVG;

if (t + elapsed_mths == 1)
	return prem_alloc(t);

if (t + elapsed_mths > fia->surr_chg_period_crbg * 12)
{
	return 0.0;
}

return gmab_av_e_crbg(t - 1);  

}

//@@ END

//@@ START - gmab_av_e_bef_crbg
// Gmab Av E Bef Crbg                                                                                             
// Column:GMAB_AV_E_BEF_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_av_e_bef_crbg(int t) {
//^^^



//^^^

#line 1 "gmab_av_e_bef_crbg.FIAAFUND_LIAB.for"
//20251211 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period || fia->gmab_ind_crbg == 0)
	return NO_AVG;

if (t + elapsed_mths > fia->surr_chg_period_crbg * 12)
{
	return 0.0;
}

double gmab_av = gmab_av_b_crbg(t) * ( 1 + crediting_rate(t) * fia->gmab_credit_rt_mult_crbg);  

return gmab_av;  

}

//@@ END

//@@ START - gmab_av_e_crbg
// Gmab Av E Crbg                                                                                             
// Column:GMAB_AV_E_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_av_e_crbg(int t) {
//^^^



//^^^

#line 1 "gmab_av_e_crbg.FIAAFUND_LIAB.for"
//20251211 New columns with CRBG logic
if (t < commencement_period || t > maturity_period || fia->gmab_ind_crbg == 0)
	return NO_AVG;

if (t + elapsed_mths > fia->surr_chg_period_crbg * 12)
{
	return 0.0;
}

if (t == 0 && valn_period > 0)
{
	return fia->init_gmab_av;
}

double gmab_amt = gmab_av_e_bef_crbg(t) * fia->surv_period(t);  

double av_bef_withdrl = fund_val_e_bef(t) * fia->surv_period(t);
double av_aft_withdrl = av_bef_withdrl - fund_released_withdrl(t);

double reduction_fct = 0.;

if (av_bef_withdrl > SMALL_DOUBLE)
{
	reduction_fct = av_aft_withdrl / av_bef_withdrl;
}

gmab_amt = gmab_amt * reduction_fct;

return gmab_amt;  

}

//@@ END

//@@ START - gmab_chg_crbg
// Gmab Chg Crbg                                                                                             
// Column:GMAB_CHG_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_chg_crbg(int t) {
//^^^



//^^^

#line 1 "gmab_chg_crbg.FIAAFUND_LIAB.for"
//20251211 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period || fia->gmab_ind_crbg == 0 || fia->gmwb_flag)
	return NO_AVG;

double gmab_chg = 0.;

if (fia->pol_mth(t) == 12 && fia->pol_yr(t) <= fia->surr_chg_period_crbg) 
{
	double fund_val = fia->fund_val_boy_b_crbg(t) * fund_val_split_prop;
	
	gmab_chg = fund_val * fia->gmab_chg_pct_crbg;
}	

return gmab_chg;

}

//@@ END

//@@ START - gmab_chg_partial_e_bef_crbg
// Gmab Chg Partial E Bef Crbg                                                                                             
// Column:GMAB_CHG_PARTIAL_E_BEF_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_chg_partial_e_bef_crbg(int t) {
//^^^



//^^^

#line 1 "gmab_chg_partial_e_bef_crbg.FIAAFUND_LIAB.for"
//20251211 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period || fia->gmab_ind_crbg == 0 || fia->gmwb_flag)
	return NO_AVG;

if (fia->pol_yr(t) > fia->surr_chg_period_crbg || fia->pol_mth(t) == 12)
{
	return 0.;
}

double fund_val_boy = fia->fund_val_boy_b_crbg(t) * fund_val_split_prop;
double fund_val = fund_val_e_bef(t);
	
double gmab_chg_partial = fund_val_boy * fia->gmab_chg_pct_crbg * fia->pol_mth(t) / 12.;

gmab_chg_partial = min(fund_val, gmab_chg_partial);
	
return gmab_chg_partial;

}

//@@ END

//@@ START - gmab_chg_partial_e_crbg
// Gmab Chg Partial E Crbg                                                                                             
// Column:GMAB_CHG_PARTIAL_E_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_chg_partial_e_crbg(int t) {
//^^^



//^^^

#line 1 "gmab_chg_partial_e_crbg.FIAAFUND_LIAB.for"
//20251211 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period || fia->gmab_ind_crbg == 0 || fia->gmwb_flag)
	return NO_AVG;

if (fia->pol_yr(t) > fia->surr_chg_period_crbg || fia->pol_mth(t) == 12) 
{
	return 0.;
}

double fund_val_boy = fia->fund_val_boy_b_crbg(t) * fund_val_split_prop * fia->surv_period(t);
double fund_val = fund_val_e(t);
	
double gmab_chg_partial = fund_val_boy * fia->gmab_chg_pct_crbg * fia->pol_mth(t) / 12.;

gmab_chg_partial = min(fund_val, gmab_chg_partial);
	
return gmab_chg_partial;

}

//@@ END

//@@ START - gmab_global_payoff_crbg
// Gmab Global Payoff Crbg                                                                                             
// Column:GMAB_GLOBAL_PAYOFF_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_global_payoff_crbg(int t) {
//^^^



//^^^

#line 1 "gmab_global_payoff_crbg.FIAAFUND_LIAB.for"
//20251211 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period || fia->gmab_ind_crbg == 0)
	return NO_AVG;

if (t + elapsed_mths == fia->surr_chg_period_crbg * 12) 
{
	double fund_val_e_bef = max(0., fund_val_b(t) + credited_int(t) - gmab_chg_crbg(t));
	double prem_less_withdrl = fia->prem_cumul_prop_wdl_bef_crbg(t) * fund_val_split_prop;
	double gmab_cap = prem_less_withdrl * fia->gmab_av_cap_rt_crbg;

	double global_payoff = max(0., min(gmab_cap, gmab_av_e_bef_crbg(t)) - fund_val_e_bef);

	return global_payoff;
}

return 0.0;

}

//@@ END

//@@ START - gmab_payoff_crbg
// Gmab Payoff Crbg                                                                                             
// Column:GMAB_PAYOFF_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_payoff_crbg(int t) {
//^^^



//^^^

#line 1 "gmab_payoff_crbg.FIAAFUND_LIAB.for"
//20251211 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period || fia->gmab_ind_crbg == 0)
	return NO_AVG;

if (t + elapsed_mths == fia->surr_chg_period_crbg * 12) 
{
	double fund_val_e_bef = max(0., fund_val_b(t) + credited_int(t) - gmab_chg_crbg(t));

	double gmab_payoff = max(0., gmab_av_e_bef_crbg(t) - fund_val_e_bef);

	return gmab_payoff;
}

return 0.0;

}

//@@ END

//@@ START - gmwb_chg
// GMWB Charge                                                                                             
// Column:GMWB_CHG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_chg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(40,"gmwb_chg",t);
}



//^^^

#line 1 "gmwb_chg.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!fia->gmwb_flag)
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
	= fia->gmwb_income_base_b_crbg(t) / fia->fund_val_b_bef(t);

else //"MAX"
	chg_base_mult = max(1.0, fia->gmwb_income_base_b_crbg(t) / fia->fund_val_b_bef(t));

double av_b_bef_gmwb_chg
= fund_val_b_bef(t) - admin_fee(t);

double gmwb_chg = min(max(av_b_bef_gmwb_chg, 0.0),
           fia->gmwb_chg_pct * av_b_bef_gmwb_chg * chg_base_mult);

if (fia->pol_mth(t) == 1) //CRBG Change to annual deduction
{
	return gmwb_chg;           			
}
else
	return 0.;

}

//@@ END

//@@ START - gmwb_chg_partial_bef_crbg
// GMWB Charge Partial                                                                                             
// Column:GMWB_CHG_PARTIAL_BEF_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_chg_partial_bef_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(41,"gmwb_chg_partial_bef_crbg",t);
}



//^^^

#line 1 "gmwb_chg_partial_bef_crbg.FIAAFUND_LIAB.for"
//20250512 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!fia->gmwb_flag || fia->gmwb_chg_at_surr_crbg == NO)
	return NO_AVG;

if (fia->fund_val_e_bef(t) < model_point_amount_threshold)
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
else //"MAX"
	chg_base_mult = max(1.0, fia->gmwb_inf_bef(t) / fia->fund_val_e_bef(t));

double av_e_bef = fund_val_e_bef(t);

return min(
		  max(av_e_bef, 0.0),
          fia->gmwb_chg_pct * av_e_bef * chg_base_mult * fia->pol_mth(t) / 12
		  );

}

//@@ END

//@@ START - gmwb_chg_partial_e_crbg
// GMWB Charge Partial                                                                                             
// Column:GMWB_CHG_PARTIAL_E_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_chg_partial_e_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(42,"gmwb_chg_partial_e_crbg",t);
}



//^^^

#line 1 "gmwb_chg_partial_e_crbg.FIAAFUND_LIAB.for"
//20250512 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!fia->gmwb_flag || fia->gmwb_chg_at_surr_crbg == NO)
	return NO_AVG;

if (fia->fund_val_fixed(t) < model_point_amount_threshold)
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
else //"MAX"
	chg_base_mult = max(1.0, fia->gmwb_inf(t) / fia->fund_val_fixed(t));

double av_e = fund_val_e(t);

return min(
		  max(av_e, 0.0),
          fia->gmwb_chg_pct * av_e * chg_base_mult * fia->pol_mth(t) / 12
		  );

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
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (hedge_defn == NO)
	return NO_AVG;

double hedge_inv = hedge_inv_amt_bom(t);
double hedge_payoff = opt_payoff(t);
double hedge_sales = hedge_sale_amt_bom(t)
                     + hedge_sale_amt_eom(t);

return - hedge_inv
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
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (hedge_defn == NO)
	return NO_AVG;

if (mod(t + elapsed_mths, crediting_mths) != 1)
	return NO_AVG;

//Replaced with CRBG logic
double mkt_val_per_unit = opt_cost_beg_term_crbg(t);
double notional_to_purch = notional_to_hedge_net(t);

double inv_amt = notional_to_purch * mkt_val_per_unit;

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
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (hedge_defn == NO)
	return NO_AVG;

if (mod(t + elapsed_mths, crediting_mths) == 0)
	return 0.0;

return notional_amt_required(t)
       * hedge_mkt_val_per_unit_notional(t);

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
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (hedge_defn == NO)
	return NO_AVG;

if (mod(t + elapsed_mths, crediting_mths) == 1)
	return hedge_mkt_val_per_unit_notional(t)
	       * notional_to_hedge_net(t)
		   - hedge_inv_amt_bom(t);

if (mod(t + elapsed_mths, crediting_mths) == 0)
	return opt_payoff(t)
	       - hedge_mkt_val(t - 1);

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
//20250521 Replaced with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (hedge_defn == NO)
	return NO_AVG;

if (t == 0 && valn_period != 0)
	return fia->init_hedge_mkt_val_per_unit;

if (valn_flag)
	return opt_cost_bs_eom_crbg(t);

double option_cost = opt_cost_beg_term_crbg(t);
double intrinsic_value = strategy_return_crbg(t);

//apply adam's formula
double time_to_maturity = 0.;

if (mod(t + elapsed_mths, crediting_mths) != 0)
{
	time_to_maturity = crediting_mths - mod(t + elapsed_mths, crediting_mths);
}

double alpha = 0.5; //hedge_option_val_alpha;

double mkt_val_opt = intrinsic_value + option_cost * pow(time_to_maturity / crediting_mths, alpha);

return mkt_val_opt;



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
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (hedge_defn == NO)
	return NO_AVG;

if (mod(t + elapsed_mths, crediting_mths) == 1)
	return 0.0;

return (admin_fee(t)
        + gmwb_chg(t))
	   * pct_to_hedge
	   //* crediting_part_rate(t)
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
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (hedge_defn == NO)
	return NO_AVG;

if (mod(t + elapsed_mths, crediting_mths) == 0)
	return 0.0;

return (fund_released_dth(t)
	    + fund_released_surr(t)
	    + fund_released_ann(t)
	    + fund_released_withdrl(t)
	    + fund_released_maturity(t))
       * pct_to_hedge
	  // * crediting_part_rate(t)
       * hedge_mkt_val_per_unit_notional(t);

}

//@@ END

//@@ START - index_term_elapsed_pct_crbg
// Index Term Elapsed Pct Crbg                                                                                             
// Column:INDEX_TERM_ELAPSED_PCT_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_elapsed_pct_crbg(int t) {
//^^^



//^^^

#line 1 "index_term_elapsed_pct_crbg.FIAAFUND_LIAB.for"
//20250624 Customized new column
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

double index_term_elapsed_pct;
double index_term_mths_elapsed = mod(t + elapsed_mths, crediting_mths);

if (index_term_mths_elapsed > 0)
	index_term_elapsed_pct = index_term_mths_elapsed / crediting_mths;
else
	index_term_elapsed_pct = 1.;

return index_term_elapsed_pct;

}

//@@ END

//@@ START - index_term_return_crbg
// Index Term Return Crbg                                                                                             
// Column:INDEX_TERM_RETURN_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_return_crbg(int t) {
//^^^



//^^^

#line 1 "index_term_return_crbg.FIAAFUND_LIAB.for"
//20250521 Customized new column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;	

double index_start_value = index_val_beg_term_crbg(t);

if (index_start_value < SMALL_DOUBLE)
	return 999999.0;

return index_val(t) / index_start_value - 1;

}

//@@ END

//@@ START - index_val
// Index Value                                                                                             
// Column:INDEX_VAL
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(52,"index_val",t);
}



//^^^

#line 1 "index_val.FIAAFUND_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (crediting_rate_defn == FIXED_RATE)
	return 0.;

if (t == commencement_period && valn_period == 0)
	return 1.;

if (t == commencement_period)
	return fia->init_index_val;

double growth_rate, growth_rate_mthly; 

if (crediting_eqt_index != "US" && pba_valn_flag) //Apply regression formula for non-US index return
{
	double random_num = fia->rand_num_non_us_return_crbg(t);
	double err_term_stdnorm = inv_cumul_normal_crbg(random_num);
	double growth_rate_us = rates_ptr->get_index_rate(t, "US", GET_GROWTH_RATE, EFFECTIVE_ANNUAL);						
	growth_rate_us = pow(1. + growth_rate_us, 1. / 12.) - 1.;

	fia->index_id_lookup = crediting_eqt_index;
	double beta = fia->non_us_return_beta_crbg;
	fia->index_id_lookup = crediting_eqt_index;
	double sigma = fia->non_us_return_sigma_crbg;

	growth_rate_mthly = growth_rate_us * beta + err_term_stdnorm * sigma;
}
else
{
	growth_rate = rates_ptr->get_index_rate(t, crediting_eqt_index, GET_GROWTH_RATE, EFFECTIVE_ANNUAL);
																	
	growth_rate_mthly = pow(1. + growth_rate, 1. / 12.) - 1.;
}


//Return from Academy generator is total return, need to subtract dividend yield to get growth rate
if (pba_valn_flag)
{			
	//Checking edge case: growth rate based on the regression formula might go out of bound
	if (1 + growth_rate_mthly < SMALL_DOUBLE) 
		return index_val_bom(t) * 0.000001;

	//Convert to continuous rate, apply dividend which is continuous, then convert back to annual effctive
	double continuous_growth_rate = log(1 + growth_rate_mthly) * 12.; 
	
	fia->index_id_lookup = crediting_eqt_index;
	double dividend_yld = fia->bs_dividend_crbg;

	growth_rate = exp(continuous_growth_rate - dividend_yld) - 1.0; 

	//checking again as growth rate is further reduced
	if (1 + growth_rate < SMALL_DOUBLE)
		return index_val_bom(t) * 0.000001;
}

return index_val_bom(t) * pow(1.0 + growth_rate * index_scen_mult + index_scen_sprd_addn, 1.0 / 12.0);

}

//@@ END

//@@ START - index_val_beg_term_crbg
// Index Val Beg Term Crbg                                                                                             
// Column:INDEX_VAL_BEG_TERM_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_index_val_beg_term_crbg(int t) {
//^^^



//^^^

#line 1 "index_val_beg_term_crbg.FIAAFUND_LIAB.for"
//20250521 Customized new column
if (t < commencement_period || t > maturity_period)
	return NO_AVG;	

if (t == 0 && valn_period != 0)
	return fia->index_val_beg_term;

if (mod(t + elapsed_mths, crediting_mths) == 1)
	return index_val_bom(t);
else
	return index_val_beg_term_crbg(t - 1);

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
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return index_val(t - 1);

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
if (t != 0)
	return NO_AVG;

xstring group_name = fund_id;
setGroup(group_name);

get_strike_list_crbg(strike_list_crbg);

return 1.0;

}

//@@ END

//@@ START - lapse_dyn_crediting_rt_crbg
// Lapse Dyn Crediting Rt                                                                                             
// Column:LAPSE_DYN_CREDITING_RT_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_lapse_dyn_crediting_rt_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_dyn_crediting_rt_crbg.FIAAFUND_LIAB.for"
//20250502 Customized new column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;	

double crediting_rate;

if (crediting_rate_defn == FIXED_RATE)
{
	crediting_rate = crediting_rate_fix(t);
}
else
{
	if (valn_flag)
		crediting_rate = opt_cost_bs_bom_crbg(t);
	else
		crediting_rate = opt_cost_by_grid_bom_crbg(t);
}

int index_term = crediting_mths / 12;

crediting_rate /= index_term;

if (crediting_dyn_lever == DYNAMIC_PART_EPRS)
{
	crediting_rate = max(0 , crediting_rate - eprs_strat_fee_pct_crbg);
}

return crediting_rate;

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
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (hedge_defn == NO)
	return NO_AVG;

if (t == commencement_period)
	return notional_to_hedge_net(t);

if (mod(t + elapsed_mths, crediting_mths) == 1)
	return notional_to_hedge_net(t) 
	       - (fund_released_dth(t)
		      + fund_released_surr(t)
			  + fund_released_ann(t)
		      + fund_released_maturity(t)
		      + fund_released_withdrl(t))
			 * pct_to_hedge;
			// * crediting_part_rate(t); // admin_fee and gmwb_chg already deducted in notional_to_hedge_net

return notional_amt_required(t - 1) 
       - fund_val_decrem(t);
	    // * crediting_part_rate(t);

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
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (hedge_defn == NO)
	return NO_AVG;

if (t == commencement_period)
	return notional_to_hedge_net(t);

if (mod(t + elapsed_mths, crediting_mths) == 1)
	return notional_to_hedge_net(t);

return notional_amt_required(t - 1)
       - (admin_fee(t)
	      + gmwb_chg(t))
	     * pct_to_hedge;
		// * crediting_part_rate(t);

}

//@@ END

//@@ START - notional_to_hedge
// Notional  Amount to Hedge                                                                                             
// Column:NOTIONAL_TO_HEDGE
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(59,"notional_to_hedge",t);
}



//^^^

#line 1 "notional_to_hedge.FIAAFUND_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (hedge_defn == NO)
	return NO_AVG;

// Needed for option budget ratio calculation
if (t == commencement_period)
	return init_fund_val * pct_to_hedge;

if (mod(t + elapsed_mths, crediting_mths) == 1)
	return fund_val_b(t) * pct_to_hedge;

return 0.0;

}

//@@ END

//@@ START - notional_to_hedge_cap
// Notional Amount to Hedge Cap                                                                                             
// Column:NOTIONAL_TO_HEDGE_CAP
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(60,"notional_to_hedge_cap",t);
}



//^^^

#line 1 "notional_to_hedge_cap.FIAAFUND_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (fabs(crediting_part_rate(t)) < rate_ratio_threshold)
	return 0.0;

return notional_to_hedge(t)
       * (1.0 + crediting_cap_rate(t) / crediting_part_rate(t));

}

//@@ END

//@@ START - notional_to_hedge_index
// Notional Amount to Hedge Index                                                                                             
// Column:NOTIONAL_TO_HEDGE_INDEX
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_index(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(61,"notional_to_hedge_index",t);
}



//^^^

#line 1 "notional_to_hedge_index.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
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
	return rebase_value(62,"notional_to_hedge_long_strike",t);
}



//^^^

#line 1 "notional_to_hedge_long_strike.FIAAFUND_LIAB.for"
if (t < commencement_period || t > maturity_period)
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
	return rebase_value(63,"notional_to_hedge_net",t);
}



//^^^

#line 1 "notional_to_hedge_net.FIAAFUND_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

return notional_to_hedge(t);
      // * crediting_part_rate(t);

}

//@@ END

//@@ START - opt_budget
// Available Option Budget                                                                                             
// Column:OPT_BUDGET
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(64,"opt_budget",t);
}



//^^^

#line 1 "opt_budget.FIAAFUND_LIAB.for"
//20250430 Replaced USL code with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (fia->annuity_type_crbg == "FA")
	return fa_crediting_rate_crbg(t);
	
double init_budget; //Option budget at inception
if(valn_period != 0 || valn_flag)
	init_budget = fia->nb_opt_budget_input_crbg; //read in
else
	init_budget = nb_opt_budget_calc_crbg; //scalar

if (fia->pol_yr(t) <= fia->opt_budget_const_yr_crbg) 
{
	return init_budget;
}

int index_term = crediting_mths / 12;

if (mod(t + elapsed_mths, crediting_mths) != 1 )
{
	if (t == 1)
		return fia->init_hedge_budget; //Initial value for future timestep
	else
		return opt_budget(t - 1);
}

double tgt_alpha = fia->tgt_budget_alpha_crbg; 
double tgt_budget = opt_budget_tgt_calc_crbg(init_budget, index_term, tgt_alpha);
double ner_init	= fia->crediting_ner_crbg;
double ner_cv	= fia->avg_coupon_rt_crbg(t - 1); 

if(!isMainModel && alm_flag)
{
	ner_cv = fia->asset_yld_inv_adj_crbg(t - 1);
}

if (fia->ner_correction_crbg == NO) //To match back to old model
{
	if (!alm_flag)
		ner_cv = fia->avg_coupon_rt_crbg(t - 2);

	ner_cv  = ner_cv / (1 + ner_cv);
	ner_init = ner_init / (1 + ner_init);
}

init_budget /= index_term;

double option_budget = opt_budget_renew_calc_crbg(t, init_budget, tgt_budget, ner_init, ner_cv);

option_budget *= index_term;

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
	return rebase_value(65,"opt_budget_amt",t);
}



//^^^

#line 1 "opt_budget_amt.FIAAFUND_LIAB.for"
if (t < commencement_period || t > maturity_period)
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

//@@ START - opt_budget_eprs_crbg
// Opt Budget Eprs Crbg                                                                                             
// Column:OPT_BUDGET_EPRS_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_eprs_crbg(int t) {
//^^^



//^^^

#line 1 "opt_budget_eprs_crbg.FIAAFUND_LIAB.for"
//20250624 Customized new column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (crediting_dyn_lever != DYNAMIC_PART_EPRS) 
	return NO_AVG;

double opt_budget;

if (t + elapsed_mths == commencement_period + 1)
{
	opt_budget = get_option_price_crbg(0, 1, CALL, crediting_mths) * fia->nb_eprs_add_par_crbg;
	//TODO pba valn run
}

else
{
	opt_budget = opt_budget_eprs_crbg(t - 1);

	/*if(t + elapsed_mths == fia->surr_chg_period_aig * 12 + 1)
	{
		option_budget += fia->sfc_annual_hedge_cost_crbg;
	}*/
}

return opt_budget;

}

//@@ END

//@@ START - opt_cost_atm_crbg
// Opt Cost Atm Crbg                                                                                             
// Column:OPT_COST_ATM_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_cost_atm_crbg(int t) {
//^^^



//^^^

#line 1 "opt_cost_atm_crbg.FIAAFUND_LIAB.for"
//20250624 Customized new column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (crediting_rate_defn == FIXED_RATE)
	return NO_AVG;

double option_cost;

if (valn_flag)
{
	double vol_param, dividend_yld, rf_rate; 
	fia->index_id_lookup = crediting_eqt_index;
	vol_param = fia->bs_fwd_vol_crbg;

	fia->index_id_lookup = crediting_eqt_index;
	dividend_yld = fia->bs_dividend_crbg;

	rf_rate = rates_ptr->get_int_rate(t - 1, "Govt", GET_SPOT_RATE, crediting_mths / 12., 0.0, NOMINAL_SEMIANNUAL, NO_SHIFT);
	option_cost = bs_opt_val(1., crediting_mths / 12., 1, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
}
else
{
	option_cost = get_option_price_crbg(t - 1, 1, CALL, crediting_mths); 
}

return option_cost;

}

//@@ END

//@@ START - opt_cost_beg_term_crbg
// Beg term option cost                                                                                             
// Column:OPT_COST_BEG_TERM_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_cost_beg_term_crbg(int t) {
//^^^



//^^^

#line 1 "opt_cost_beg_term_crbg.FIAAFUND_LIAB.for"
//20250430 Customized new column
if (t < commencement_period || t > maturity_period)
	return NO_AVG;	

if (t == commencement_period)
	return fia->init_opt_cost_beg_term;

opt_budget(t);

if (mod(t + elapsed_mths, crediting_mths) == 1)
{
	double opt_cost_bom;
	if (valn_flag)
		opt_cost_bom = opt_cost_bs_bom_crbg(t);
	else
		opt_cost_bom = opt_cost_by_grid_bom_crbg(t);
	
	return opt_cost_bom;
}

return opt_cost_beg_term_crbg(t - 1);
	

}

//@@ END

//@@ START - opt_cost_bs_bom_crbg
// Opt Cost Bs Bom Crbg                                                                                             
// Column:OPT_COST_BS_BOM_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_cost_bs_bom_crbg(int t) {
//^^^



//^^^

#line 1 "opt_cost_bs_bom_crbg.FIAAFUND_LIAB.for"
//20260130 Customized new column
if (t <= commencement_period || t > maturity_period || !valn_flag)
	return NO_AVG;	

double long_call_opt_cost, short_call_opt_cost, option_cost;

double vol_param, dividend_yld; 
fia->index_id_lookup = crediting_eqt_index;
vol_param = fia->bs_fwd_vol_crbg;

fia->index_id_lookup = crediting_eqt_index;
dividend_yld = fia->bs_dividend_crbg;

double rf_rate = rates_ptr->get_int_rate(t - 1, "Govt", GET_SPOT_RATE, crediting_mths / 12., 0.0, NOMINAL_SEMIANNUAL, NO_SHIFT);
double spot_price, time_to_maturity;

if (mod(t + elapsed_mths, crediting_mths) == 1)
{
	spot_price = 1.;
	time_to_maturity = 1.;
}
else
{
	spot_price = index_val(t - 1) / index_val_beg_term_crbg(t); 
	time_to_maturity = 1 - index_term_elapsed_pct_crbg(t - 1);
}

if (crediting_dyn_lever == DYNAMIC_CAP)
{
	double cap_rate	= crediting_cap_rate(t);	

	long_call_opt_cost	= bs_opt_val(1 + crediting_floor, time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	short_call_opt_cost	= bs_opt_val(1 + cap_rate, time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	option_cost			= long_call_opt_cost - short_call_opt_cost + crediting_floor / (1 + rf_rate);
}
else if (crediting_dyn_lever == DYNAMIC_PART)
{
	long_call_opt_cost	= bs_opt_val(1., time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	option_cost			= long_call_opt_cost * crediting_part_rate(t);
}
else if (crediting_dyn_lever == DYNAMIC_PART_EPRS)
{
	long_call_opt_cost	= bs_opt_val(1., time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	option_cost			= long_call_opt_cost * enhanced_part_rate_crbg(t);
}
else if (crediting_dyn_lever == DYNAMIC_SPRD || crediting_dyn_lever == DYNAMIC_PART_SPRD)
{
	double strike = 1 + crediting_sprd_rate_crbg(t) / crediting_part_rate(t);

	long_call_opt_cost	= bs_opt_val(strike, time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	option_cost			= long_call_opt_cost * crediting_part_rate(t);
}
else if (crediting_dyn_lever == DYNAMIC_TRIGGER)
{
	double pos_sprd = 0.;
	double neg_sprd = 0.01;

	double call_k_pos	= bs_opt_val(1 + pos_sprd, time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	double call_k_neg	= bs_opt_val(1 - neg_sprd, time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	option_cost			= crediting_trigger_rate_crbg(t) * (call_k_neg - call_k_pos) / (pos_sprd + neg_sprd); 
}

return option_cost;

}

//@@ END

//@@ START - opt_cost_bs_eom_crbg
// Opt Cost Bs Eom Crbg                                                                                             
// Column:OPT_COST_BS_EOM_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_cost_bs_eom_crbg(int t) {
//^^^



//^^^

#line 1 "opt_cost_bs_eom_crbg.FIAAFUND_LIAB.for"
//20260130 Customized new column
if (t <= commencement_period || t > maturity_period || !valn_flag)
	return NO_AVG;	

double long_call_opt_cost, short_call_opt_cost, option_cost;

double vol_param, dividend_yld; 
fia->index_id_lookup = crediting_eqt_index;
vol_param = fia->bs_fwd_vol_crbg;

fia->index_id_lookup = crediting_eqt_index;
dividend_yld = fia->bs_dividend_crbg;

double rf_rate = rates_ptr->get_int_rate(t, "Govt", GET_SPOT_RATE, crediting_mths / 12., 0.0, NOMINAL_SEMIANNUAL, NO_SHIFT);
double spot_price = index_val(t) / index_val_beg_term_crbg(t);  
double time_to_maturity = 1 - index_term_elapsed_pct_crbg(t);

if (crediting_dyn_lever == DYNAMIC_CAP)
{
	double cap_rate	= crediting_cap_rate(t);	

	long_call_opt_cost	= bs_opt_val(1 + crediting_floor, time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	short_call_opt_cost	= bs_opt_val(1 + cap_rate, time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	option_cost			= long_call_opt_cost - short_call_opt_cost + crediting_floor / (1 + rf_rate);
}
else if (crediting_dyn_lever == DYNAMIC_PART)
{
	long_call_opt_cost	= bs_opt_val(1., time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	option_cost			= long_call_opt_cost * crediting_part_rate(t);
}
else if (crediting_dyn_lever == DYNAMIC_PART_EPRS)
{
	long_call_opt_cost	= bs_opt_val(1., time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	option_cost			= long_call_opt_cost * enhanced_part_rate_crbg(t);
}
else if (crediting_dyn_lever == DYNAMIC_SPRD || crediting_dyn_lever == DYNAMIC_PART_SPRD)
{
	double strike = 1 + crediting_sprd_rate_crbg(t) / crediting_part_rate(t);

	long_call_opt_cost	= bs_opt_val(strike, time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	option_cost			= long_call_opt_cost * crediting_part_rate(t);
}
else if (crediting_dyn_lever == DYNAMIC_TRIGGER)
{
	double pos_sprd = 0.;
	double neg_sprd = 0.01;

	double call_k_pos	= bs_opt_val(1 + pos_sprd, time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	double call_k_neg	= bs_opt_val(1 - neg_sprd, time_to_maturity, spot_price, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
	option_cost			= crediting_trigger_rate_crbg(t) * (call_k_neg - call_k_pos) / (pos_sprd + neg_sprd); 
}

return option_cost;

}

//@@ END

//@@ START - opt_cost_by_grid_bom_crbg
// Current option cost  BOM                                                                                             
// Column:OPT_COST_BY_GRID_BOM_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_opt_cost_by_grid_bom_crbg(int t) {
//^^^



//^^^

#line 1 "opt_cost_by_grid_bom_crbg.FIAAFUND_LIAB.for"
//20250430 Customized new column
if (t <= commencement_period || t > maturity_period || valn_flag)
	return NO_AVG;	

double long_call_opt_cost, short_call_opt_cost, option_cost;

if (crediting_dyn_lever == DYNAMIC_CAP)
{
	double cap_rate	= crediting_cap_rate(t);
	double rf_rate = rates_ptr->get_int_rate(t - 1, "Swap", GET_YIELD_RATE, crediting_mths / 12., 0, EFFECTIVE_ANNUAL, NO_SHIFT);

	long_call_opt_cost	= get_option_price_crbg(t - 1, 1 + crediting_floor, CALL, crediting_mths);
	short_call_opt_cost	= get_option_price_crbg(t - 1, 1 + cap_rate, CALL, crediting_mths);
	option_cost			= long_call_opt_cost - short_call_opt_cost + crediting_floor / (1 + rf_rate);
}
else if (crediting_dyn_lever == DYNAMIC_PART)
{
	long_call_opt_cost	= get_option_price_crbg(t - 1, 1, CALL, crediting_mths);
	option_cost			= long_call_opt_cost * crediting_part_rate(t);
}
else if (crediting_dyn_lever == DYNAMIC_PART_EPRS)
{
	long_call_opt_cost	= get_option_price_crbg(t - 1, 1, CALL, crediting_mths);
	option_cost			= long_call_opt_cost * enhanced_part_rate_crbg(t);
}
else if (crediting_dyn_lever == DYNAMIC_SPRD || crediting_dyn_lever == DYNAMIC_PART_SPRD)
{
	long_call_opt_cost	= get_option_price_crbg(t - 1, 1 + crediting_sprd_rate_crbg(t) / crediting_part_rate(t), CALL, crediting_mths);
	option_cost			= long_call_opt_cost * crediting_part_rate(t);
}
else if (crediting_dyn_lever == DYNAMIC_TRIGGER)
{
	xstring rate_lookup = "BINY_" + crediting_eqt_index + "_D" + xstring(crediting_mths) + "_K100";
	double option_cost_one_percent = rates_ptr->get_misc_rate(t - 1, rate_lookup, EFFECTIVE_ANNUAL);

	option_cost = crediting_trigger_rate_crbg(t) * option_cost_one_percent; 
}

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
	return rebase_value(72,"opt_payoff",t);
}



//^^^

#line 1 "opt_payoff.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period || t > fia->final_period)
	return NO_AVG;

if (hedge_defn == NO)
	return NO_AVG;

if (mod(t + elapsed_mths, crediting_mths) != 0)
	return NO_AVG;

//Replaced with CRBG logic	
double payoff = notional_amt_required_bef(t) * strategy_return_crbg(t);

return payoff;

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
if (t <= commencement_period || t > maturity_period)
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
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (fia->fund_val_b_bef(t) < model_point_amount_threshold)
    return NO_AVG;

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
double part_rate = crediting_part_rate(t);

K = opt_strike_price(t);
K_cap = K * (max(crediting_cap_rate(t), crediting_cap_min) + 1.0);
S = index_val(t);
tte = double (crediting_mths - xint(mod(elapsed_mths + t, crediting_mths))) / double(crediting_mths);

q = rates_ptr->get_index_rate(t, 
			crediting_eqt_index,
			GET_DIVIDEND_YIELD,
			EFFECTIVE_ANNUAL)
	* div_yld_scen_mult + div_yld_sprd;

sigma = rates_ptr->get_index_vol(t, 
								crediting_eqt_index,
								K / S,
								tte,
								EFFECTIVE_ANNUAL,
								NO_SHIFT);
sigma_cap = rates_ptr->get_index_vol(t, 
								crediting_eqt_index,
								K_cap / S,
								tte,
								EFFECTIVE_ANNUAL,
								NO_SHIFT);
rf = rates_ptr->get_int_rate(t,
							"Govt",
							GET_SPOT_RATE,
							tte,
							0.0,
							NOMINAL_SEMIANNUAL,
							NO_SHIFT);

cost_of_call_option_pct = 0.0;
cost_of_call_option_cap_pct = 0.0;
	
if (crediting_rate_defn == POINT_TO_POINT)
	{
	cost_of_call_option_pct = bs_opt_val(K, tte, S, sigma, rf, q, CALL_CODE, CONTINUOUS_PAYOUT_CODE) / K; 
	cost_of_call_option_cap_pct = bs_opt_val(K_cap, tte, S, sigma_cap, rf, q, CALL_CODE, CONTINUOUS_PAYOUT_CODE) / K;
		
	if (crediting_dyn_lever == DYNAMIC_CAP)
		net_opt_value = (cost_of_call_option_pct - cost_of_call_option_cap_pct);
	else if (crediting_dyn_lever == DYNAMIC_PART)				
		net_opt_value = cost_of_call_option_pct * part_rate;
	else //Both cap and participation
		net_opt_value = (cost_of_call_option_pct - cost_of_call_option_cap_pct)
						* part_rate;
		
	option_rate_num = net_opt_value * fund_val_b_bef(t);
	}
else if (crediting_rate_defn == MOVING_AVERAGE)
	{
	if (mod (t + elapsed_mths, crediting_mths) == 0.0)
		month = crediting_mths;
	else 
		month = mod (t + elapsed_mths, crediting_mths);
			
	Average = index_val_avg_calc(t, month);
	cost_of_call_option_pct = bs_opt_val_levy_asian(K, tte, S, Average,sigma, rf, q) / K; 
	cost_of_call_option_cap_pct = bs_opt_val_levy_asian(K_cap, tte, S, Average,sigma_cap, rf, q) / K;
		
	if (crediting_dyn_lever == DYNAMIC_CAP)
		net_opt_value = (cost_of_call_option_pct - cost_of_call_option_cap_pct);
	else if (crediting_dyn_lever == DYNAMIC_PART)				
		net_opt_value = cost_of_call_option_pct * part_rate;
	else //Both cap and participation
		net_opt_value = (cost_of_call_option_pct - cost_of_call_option_cap_pct)
						* part_rate;
		
	option_rate_num = net_opt_value * fund_val_b_bef(t);
	}
else if (crediting_rate_defn == MONTHLY_SUM_CAP)
	{
	double cap = crediting_cap_rate(t);
		
	if (mod(t + elapsed_mths, crediting_mths) == 0.0)
		month = crediting_mths;
	else 
		month = mod(t + elapsed_mths, crediting_mths);

	double index_curr = 0;
	double index_prev = 0;
	double index_change_sum = 0;
	for (int i = 0; i < month; i++)
		{
		index_curr = index_val_calc(t - i);
		index_prev = index_val_calc(t - i - 1);
		
		if (index_prev > 0) //need to set index_prev first			
			index_change_sum += min(cap, (index_curr / index_prev) - 1.0);
		}	

	cost_of_call_option_pct 
	= bs_opt_val_mthly_sum_cap(crediting_mths,
		                       month,
							   index_change_sum,
							   cap,
							   tte,
							   rf,
							   q,
							   sigma,
							   NOMINAL_SEMIANNUAL,
							   EFFECTIVE_ANNUAL);

	if (crediting_dyn_lever == DYNAMIC_CAP)
		net_opt_value = cost_of_call_option_pct;
	else if (crediting_dyn_lever == DYNAMIC_PART)				
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
	return rebase_value(75,"pfwd_surr_fund_val",t);
}



//^^^

#line 1 "pfwd_surr_fund_val.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double fund_val_base = fund_val_e_bef(t) * fia->surv_period(t);

return max(0.0, min(fund_val_base * fia->pfwd_rate_mthly_fund_val(t), 
                    fund_val_base));

}

//@@ END

//@@ START - prem_alloc
// Premium Allocated to Account (incl. Premium Bonus)                                                                                             
// Column:PREM_ALLOC
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_prem_alloc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(76,"prem_alloc",t);
}



//^^^

#line 1 "prem_alloc.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
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
	return rebase_value(77,"prem_bonus",t);
}



//^^^

#line 1 "prem_bonus.FIAAFUND_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return fia->prem_paid(t) 
	   * fund_val_split_prop
	   * fia->prem_credit;

}

//@@ END

//@@ START - prorated_strategy_return_crbg
// Prorated Strategy Return Crbg                                                                                             
// Column:PRORATED_STRATEGY_RETURN_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_prorated_strategy_return_crbg(int t) {
//^^^



//^^^

#line 1 "prorated_strategy_return_crbg.FIAAFUND_LIAB.for"
//20250529 Customized new column.
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;	

if (crediting_rate_defn == FIXED_RATE)
{
	return crediting_rate(t);
}

return strategy_return_crbg(t) * index_term_elapsed_pct_crbg(t);


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

#if defined(__AA_COMP_COMP_H_)
RATES_ECONOMY /*modelobject_name: RATES*/ *rates_ptr;
#else
RATES_ECONOMY /*modelobject_name: FIA_RATES*/ *rates_ptr;
#endif

vector<int> strike_list_crbg;

#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
// dynamic Lever variables
lookback_yrs = 0;
div_yld_scen_mult = 1.0;
div_yld_sprd = 0.0;
index_scen_mult = 1.0;
index_scen_sprd_addn = 0.0;
payout_index_max = 999.99;
#endif // END_CONSTRUCTOR

//set up variables value
if (crediting_dyn_lever == DYNAMIC_PART && crediting_rate_defn == MONTHLY_SUM_CAP)
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

strike_list_crbg.clear();

return 1.0;

}

//@@ END

//@@ START - strategy_return_crbg
// Strategy return, or intrinsic value                                                                                             
// Column:STRATEGY_RETURN_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_crbg(int t) {
//^^^



//^^^

#line 1 "strategy_return_crbg.FIAAFUND_LIAB.for"
//20250521 Customized new column: same as strategy return in prior IA model
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;	

if (crediting_rate_defn == FIXED_RATE)
    return NO_AVG;

double index_return = 0.;

if (crediting_dyn_lever == DYNAMIC_CAP)
{
	index_return = min(index_term_return_crbg(t), crediting_cap_rate(t));
}
else if (crediting_dyn_lever == DYNAMIC_PART)
{
	index_return = crediting_part_rate(t) * index_term_return_crbg(t);
}
else if (crediting_dyn_lever == DYNAMIC_PART_EPRS)
{
	index_return = enhanced_part_rate_crbg(t) * index_term_return_crbg(t);
}
else if (crediting_dyn_lever == DYNAMIC_SPRD || crediting_dyn_lever == DYNAMIC_PART_SPRD)
{
	index_return = crediting_part_rate(t) * index_term_return_crbg(t) - crediting_sprd_rate_crbg(t);
}
else if (crediting_dyn_lever == DYNAMIC_TRIGGER)
{
	if (index_term_return_crbg(t) > 0)
		index_return = crediting_trigger_rate_crbg(t);
	else
		index_return = 0;
}

if (mod(t + elapsed_mths, crediting_mths) == 0)
	return max(crediting_floor, index_return);
else
	return max(0., index_return);

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

//@@ START - lookback_mths
// Lookback Months                                                                                             
// Calculated Variable:LOOKBACK_MTHS
//========================================================
int FIAAFUND_LIAB_UDF::fiaafund_liab_lookback_mths() {
//^^^


#line 1 "lookback_mths.FIAAFUND_LIAB.for"
if (crediting_rate_defn == MOVING_AVERAGE)
	return crediting_mths
		   - (crediting_mths % lookback_sampling_mths);

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
int FIAAFUND_LIAB_UDF::fiaafund_liab_maturity_period() {
//^^^


#line 1 "maturity_period.FIAAFUND_LIAB.for"
return fia->maturity_period;

}

//@@ END

//@@ START - nb_opt_budget_calc_crbg
// Initial Opt Budget - New Business                                                                                             
// Calculated Variable:NB_OPT_BUDGET_CALC_CRBG
//========================================================
double FIAAFUND_LIAB_UDF::fiaafund_liab_nb_opt_budget_calc_crbg() {
//^^^


#line 1 "nb_opt_budget_calc_crbg.FIAAFUND_LIAB.for"
double long_call_opt_cost, short_call_opt_cost, option_cost;

if (crediting_rate_defn == FIXED_RATE)
{
	return fia->nb_fixed_rate_crbg;
}

if (crediting_dyn_lever == DYNAMIC_CAP)
{
	double rf_rate = rates_ptr->get_int_rate(0, "Swap", GET_YIELD_RATE, crediting_mths / 12., 0, EFFECTIVE_ANNUAL, NO_SHIFT);

	long_call_opt_cost	= get_option_price_crbg(0, 1 + crediting_floor_init, CALL, crediting_mths); //crediting fl is 0 if not NYIA
	short_call_opt_cost	= get_option_price_crbg(0, 1 + fia->nb_cap_rate_crbg, CALL, crediting_mths);
	option_cost			= long_call_opt_cost - short_call_opt_cost + crediting_floor_init / (1 + rf_rate);
}
else if (crediting_dyn_lever == DYNAMIC_PART || crediting_dyn_lever == DYNAMIC_PART_EPRS)
{
	long_call_opt_cost	= get_option_price_crbg(0, 1, CALL, crediting_mths);
	option_cost			= long_call_opt_cost * fia->nb_part_rate_crbg;
}
else if (crediting_dyn_lever == DYNAMIC_SPRD)
{
	long_call_opt_cost	= get_option_price_crbg(0, 1 + fia->nb_sprd_rate_crbg, CALL, crediting_mths);
	option_cost			= long_call_opt_cost;
}
else if (crediting_dyn_lever == DYNAMIC_PART_SPRD)
{
	long_call_opt_cost	= get_option_price_crbg(0, 1 + fia->nb_sprd_rate_crbg / fia->nb_part_rate_crbg, CALL, crediting_mths);
	option_cost			= long_call_opt_cost * fia->nb_part_rate_crbg;
}
else if (crediting_dyn_lever == DYNAMIC_TRIGGER)
{
	xstring rate_lookup = "BINY_" + crediting_eqt_index + "_D" + xstring(crediting_mths) + "_K100";
	double option_cost_one_percent = rates_ptr->get_misc_rate(0, rate_lookup, EFFECTIVE_ANNUAL);

	option_cost = fia->nb_trigger_rate_crbg * option_cost_one_percent; 
}

return option_cost;

}

//@@ END


#line 1 "get_bs_opt_strike_crbg.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::get_bs_opt_strike_crbg(double rf_rate, double vol_param, double dividend_yld, double cost, int opt_mths)
{
	double final_strike = 0.0;
	double step = 0.0;
	double guess_a = 1.0;
	double guess_b = 1.0;
	int stop = 0;
	int first_time = 0;
	double option_cost_a = 0.0;
	double option_cost_b = 0.0;

	double atm_cost = bs_opt_val(1., opt_mths / 12., 1, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);

	if(cost > atm_cost) //This solver does not handle strike level less than 1.
		return 1.;

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
				option_cost_a = bs_opt_val(1 * guess_a, opt_mths / 12., 1, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
				option_cost_b = bs_opt_val(1 * guess_b, opt_mths / 12., 1, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			}
			else
			{
				option_cost_a = option_cost_b;
				option_cost_b = bs_opt_val(1 * guess_b, opt_mths / 12., 1, vol_param, rf_rate, dividend_yld, CALL_CODE, CONTINUOUS_PAYOUT_CODE);
			}

			first_time = 0;

			//Check to see if the option cost is between a and b strikes
			if ( ( (option_cost_a - cost) <= 0 && (option_cost_b - cost) >= 0 ) || ( (option_cost_a - cost) >= 0 && (option_cost_b - cost) <= 0 ) || j > 1000)
			{
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



#line 1 "get_option_price_crbg.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::get_option_price_crbg(
	int projection_month, double strike, StrEnum::EnumValue opt_defn, int index_term_mth)
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
	
	string index_id_str = crediting_eqt_index.getStdStr();
	string index_term_str = "D" + to_string(index_term_mth);  
	
	vector<int> table_strikes;	

	table_strikes = strike_list_crbg;

	if (table_strikes.size() == 0)
	{
		string projection_month_str = to_string(projection_month);
		//xstring error_msg = "'fia_account->get_option_price_aig(...)': cannot locate option costs in scenario file! Field search: '" 
		//+ option_type_string + "_" + index_id_str + "_" + index_term_mth + "_K*' at t=" + projection_month_str + " for group='" + group + "'";
		//throw FatalError(error_msg);
	}

	sort(table_strikes.begin(), table_strikes.end());

	int number_of_strikes = table_strikes.size();
	table_strikes.erase(unique(table_strikes.begin(), table_strikes.end() ), table_strikes.end());
	if (number_of_strikes != table_strikes.size())
	{
		throw FatalError("'fia_account->get_option_price_crbg(...)': duplicate strike data found in scenario file!");
	}

	double interpolated_option_cost;
	const int FIRST_INDEX = 0;
	const int LAST_INDEX = table_strikes.size() - 1;

	strike *= 100;

	for (vector<int>::size_type i = 0; i != table_strikes.size(); i++)
	{
		double table_strike = table_strikes.at(i);
		string table_lookup 
			= option_type_string + "_" + index_id_str + "_" + index_term_str + "_K" + to_string((int)table_strike); 
		
		double table_option_cost = 0.0;
		table_option_cost = rates_ptr->get_misc_rate(projection_month, table_lookup, EFFECTIVE_ANNUAL);

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
			double lower_strike = table_strikes.at(i - 1);
			double higher_strike = table_strike;
			double lower_strike_weight = (higher_strike - strike)/(higher_strike - lower_strike);
			double higher_strike_weight = (strike - lower_strike)/(higher_strike - lower_strike);

			string lower_strike_table_lookup 
				= option_type_string + "_" + index_id_str + "_" + index_term_str + "_K" + to_string((int)lower_strike); 
			double price_below = 0.0;

			price_below = rates_ptr->get_misc_rate(projection_month, lower_strike_table_lookup, EFFECTIVE_ANNUAL);
			
			double price_above = table_option_cost;

			interpolated_option_cost = lower_strike_weight * price_below + higher_strike_weight * price_above;
			break;
		}
	}

	return interpolated_option_cost;
}



#line 1 "get_option_strike_crbg.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::get_option_strike_crbg(
	int projection_month, double cost, StrEnum::EnumValue opt_defn, int index_term_mth)
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
	
	string index_id_str = crediting_eqt_index.getStdStr();
	string index_term_str = "D" + to_string(index_term_mth);  
	
	vector<int> table_strikes;	

	table_strikes = strike_list_crbg;

	if (table_strikes.size() == 0)
	{
		string projection_month_str = to_string(projection_month);
		//xstring error_msg = "'fia_account->get_option_strike_aig(...)': cannot locate option costs in scenario file! Field search: '" 
		//+ option_type_string + "_" + index_id_str + "_" + index_term_mth + "_K*' at t=" + projection_month_str + " for group='" + group + "'";
		//throw FatalError(error_msg);
	}

	sort(table_strikes.begin(), table_strikes.end());

	if (opt_defn == CALL)  
	{
		reverse(table_strikes.begin(), table_strikes.end());
	}

	int number_of_strikes = table_strikes.size();
	table_strikes.erase(unique(table_strikes.begin(), table_strikes.end() ), table_strikes.end());
	if (number_of_strikes != table_strikes.size())
	{
		throw FatalError("'fia_account->get_option_strike_crbg(...)': duplicate strike data found in scenario file!");
	}

	double interpolated_option_strike = 0;
	const int FIRST_INDEX = 0;
	const int LAST_INDEX = table_strikes.size() - 1;

	for (vector<int>::size_type i = 0; i != table_strikes.size(); i++)
	{
		int table_strike = table_strikes.at(i);
		string table_lookup 
			= option_type_string + "_" + index_id_str + "_" + index_term_str + "_K" + to_string(table_strike); 
		double table_option_cost = 0.0;

		table_option_cost = rates_ptr->get_misc_rate(projection_month, xstring(table_lookup), EFFECTIVE_ANNUAL);

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
			int prior_strike = table_strikes.at(i - 1);
			string lower_option_price_lookup 
				= option_type_string + "_" + index_id_str + "_" + index_term_str + "_K" + to_string((int)prior_strike); 

			transform(lower_option_price_lookup.begin(), lower_option_price_lookup.end(), lower_option_price_lookup.begin(), ::toupper);

			double lower_option_price = 0.0;

			lower_option_price = rates_ptr->get_misc_rate(projection_month, lower_option_price_lookup, EFFECTIVE_ANNUAL);
			
			double higher_option_price = table_option_cost;
			double lower_option_price_weight = (higher_option_price - cost)/(higher_option_price - lower_option_price);
			double higher_option_price_weight = (cost - lower_option_price)/(higher_option_price - lower_option_price);

			double strike_below = table_strikes.at(i - 1);
			double strike_above = table_strike;

			interpolated_option_strike = lower_option_price_weight * strike_below + higher_option_price_weight * strike_above;
			break;
		}
	}

	
	return interpolated_option_strike / 100.;
}



#line 1 "get_strike_list_crbg.FIAAFUND_LIAB.for"                                                                                   
void FIAAFUND_LIAB::get_strike_list_crbg(vector<int>& strike_list)
{
	vector <xstring> misc_id_list;

	misc_id_list = rates_ptr->misc_list;

	int opt_mths = crediting_mths;

	string index_id_str = crediting_eqt_index.getStdStr();
	string option_duration_str = "D" + std::to_string(opt_mths);  

	string complete_key = "CALL_" + index_id_str + "_" + option_duration_str + "_K";

	for (auto misc_id: misc_id_list) 
	{
		misc_id.to_upper();
		const int NOT_FOUND_CODE = -1;
		if (misc_id.find(complete_key) != NOT_FOUND_CODE) 
		{			
			string misc_id_string = misc_id.getStdStr();

			int K = atoi(misc_id_string.substr(complete_key.length()).c_str());
			strike_list.push_back(K);			
		}
	}	
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
	
if (time_step_flag && valn_period != 0)
	{
	for (int i = 1; i <= valn_period; i++)
		{		
		rate = pow(1.0 + rates_ptr->get_index_rate(i - valn_period,
						crediting_eqt_index,
						GET_GROWTH_RATE,
						EFFECTIVE_ANNUAL)
						* index_scen_mult + index_scen_sprd_addn,
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
		rate = pow(1.0 + rates_ptr->get_index_rate(i,
						crediting_eqt_index,
						GET_GROWTH_RATE,
						EFFECTIVE_ANNUAL)
						* index_scen_mult + index_scen_sprd_addn,
						(1.0 / 12.0));
		index_val *= rate;			
		}
	}
	
// else if t < 0, must base calculation on prior value
for (int i = -1; i >= t; i--)
	{
	rate = pow(1.0 + rates_ptr->get_index_rate(i + 1,
					crediting_eqt_index,
					GET_GROWTH_RATE,
					EFFECTIVE_ANNUAL)
					* index_scen_mult + index_scen_sprd_addn,
					(1.0 / 12.0));
	index_val /= rate;
	}

return index_val;		
}



#line 1 "inv_cumul_normal_crbg.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::inv_cumul_normal_crbg(double p)
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
		
	init_div_yld
	= rates_ptr->get_index_rate(t, 
				crediting_eqt_index,
				GET_DIVIDEND_YIELD,
				EFFECTIVE_ANNUAL)
		* div_yld_scen_mult + div_yld_sprd;
	
	index_vol_atm
	= rates_ptr->get_index_vol(t, 
				crediting_eqt_index,
				1.0,/*moneyness */
				term_to_expiry,
				EFFECTIVE_ANNUAL,
				NO_SHIFT) 
		+ extra_vol_spread;
	
	index_vol_otm
	= rates_ptr->get_index_vol(t, 
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
	= rates_ptr->get_int_rate(t,
				category_id,
				GET_SPOT_RATE,
				term_to_expiry,
				0.0,
				NOMINAL_SEMIANNUAL,
				shift_defn)
		+ extra_spot_spread;

	} 

if (crediting_rate_defn == POINT_TO_POINT
	|| crediting_rate_defn == MOVING_AVERAGE)
	{		
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
					index_val_avg_calc(t, xint(mod(t + elapsed_mths, crediting_mths))),
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
					index_val_avg_calc(t, xint(mod(t + elapsed_mths, crediting_mths))),
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
		for (int i = 0; i < crediting_mths; i++)
			{
			index_curr = index_val_calc(t - i);
			index_prev = index_val_calc(t - i - 1);
		
			if (index_prev > 0) //need to set index_prev first			
				sum_capped_amts += min(mthly_cap_rate, (index_curr / index_prev) - 1.0);
			}	

		return index_units_owned
		       * max(0.0, sum_capped_amts);
		}

	for (int i = 0; i < xint(mod(t + elapsed_mths, crediting_mths)); i++)
		{
		index_curr = index_val_calc(t - i);
		index_prev = index_val_calc(t - i - 1);
		
		if (index_prev > 0) //need to set index_prev first			
			sum_capped_amts += min(mthly_cap_rate, (index_curr / index_prev) - 1.0);
		}	

	calculated_market_value
	= index_units_owned
	  * bs_opt_val_mthly_sum_cap(crediting_mths,
	                   xint(mod(t + elapsed_mths, crediting_mths)),
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



#line 1 "opt_budget_renew_calc_crbg.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::opt_budget_renew_calc_crbg(int t, double init_opt_cost, double opt_budget_tgt, double ner_init, double ner_cv)
{

	double beta;
	if (ner_cv > ner_init)
	{
		beta = fia->renewal_beta_up_crbg; 
	}
	else
	{
		beta = fia->renewal_beta_down_crbg; 
	}

	double grading_factor, option_budget;
	double grading_period = fia->max_mva_sc_period_crbg + fia->renewal_sc_yr_offest_crbg + 1; 

	if (t + elapsed_mths <= (grading_period - 1) * 12 + 1)
	{
		int pol_yr = ((t + elapsed_mths - 1) / 12.0 + 1);

		double grading_numerator	= pol_yr - fia->opt_budget_const_yr_crbg; 
		double grading_denominator	= grading_period - fia->opt_budget_const_yr_crbg; 

		grading_factor = grading_numerator / grading_denominator;		

		option_budget = init_opt_cost + (opt_budget_tgt - init_opt_cost) * grading_factor + beta * (ner_cv - ner_init);
	}
	else
	{
		option_budget = opt_budget_tgt + beta * (ner_cv - ner_init);
	}

	return option_budget;
}



#line 1 "opt_budget_tgt_calc_crbg.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::opt_budget_tgt_calc_crbg(double init_opt_cost, double index_term, double tgt_alpha)
{
	double init_ner = fia->crediting_ner_crbg / (1.0 + fia->crediting_ner_crbg); //5.34base, 4.96LIP
	//double init_ner = fia->crediting_ner_crbg; TODO: change to this after model reconciliation

	double init_pri_sprd = init_ner - init_opt_cost / index_term;
	double baseline_budget = init_ner - fia->pri_sprd_tgt_crbg; 

	double	opt_budget_reduction = fia->tgt_budget_reduction_crbg;

	double opt_budget_tgt = baseline_budget - opt_budget_reduction + 
						tgt_alpha * (fia->pri_sprd_tgt_crbg - init_pri_sprd);	

	return opt_budget_tgt;
}



#line 1 "part_rate_solver_crbg.FIAAFUND_LIAB.for"                                                                                   
double FIAAFUND_LIAB::part_rate_solver_crbg(int t, double option_budget, double guess_low_bound, double guess_high_bound)
{
	int solve_iteration = 1;
	double solve_tolerance = 0.0000001; 
	double guess_part_rate, solved_part_rate, part_rate_adj_option_budget, long_strike, current_guess_diff;

	// Main solve loop
	while (true)
	{
		guess_part_rate = (guess_low_bound + guess_high_bound) * 0.5;

		// Get participation-rate-adjusted option budget
		if (guess_part_rate > SMALL_DOUBLE)
			part_rate_adj_option_budget = option_budget / guess_part_rate;
		else
			return guess_low_bound;

		// Get strike from participation-rate-adjusted option budget
		if (valn_flag)
		{
			//higher tolerance as get_bs_opt_strike_crbg has lower precision
			solve_tolerance = 0.0005; 

			double vol_param, dividend_yld; 
			fia->index_id_lookup = crediting_eqt_index;
			vol_param = fia->bs_fwd_vol_crbg;

			fia->index_id_lookup = crediting_eqt_index;
			dividend_yld = fia->bs_dividend_crbg;

			double rf_rate = rates_ptr->get_int_rate(t - 1, "Govt", GET_SPOT_RATE, crediting_mths / 12., 0.0, NOMINAL_SEMIANNUAL, NO_SHIFT);
			long_strike = get_bs_opt_strike_crbg(rf_rate, vol_param, dividend_yld, part_rate_adj_option_budget, crediting_mths) - 1.;
		}
		else
		{
			long_strike = get_option_strike_crbg(t - 1, part_rate_adj_option_budget, CALL,crediting_mths) - 1.0;		
		}

		if (long_strike > SMALL_DOUBLE)
			solved_part_rate =  fia->nb_sprd_rate_crbg / long_strike;
		else
			solved_part_rate =  guess_high_bound;

		current_guess_diff = solved_part_rate - guess_part_rate;
		if (fabs(current_guess_diff) <= solve_tolerance)
		{
			return solved_part_rate;
		}

		// Set next guess if not acceptable solution - simple bisection
		if (solved_part_rate > guess_part_rate)
		{
			guess_low_bound = guess_part_rate;
		}
		else
		{
			guess_high_bound = guess_part_rate;
		}

		// Increase solve iteration counter
		solve_iteration++;

		if (solve_iteration > 1000 || guess_low_bound == guess_high_bound)
		{
			xstring t_str = xstring(t);
			throw FatalError("Unable to achieve solved participation rate at t = "
							+ t_str + " for account " + fund_id + " ! Please check!");
		}
	}  
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
	int per = reserve_period - (crediting_mths - mths_in_first_period);
	
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
if (t == 1)	  		 
	return strike(t, reserve_period, mths_in_first_period) 
		   * (max(crediting_cap_rate(reserve_period), /*crediting_cap_min*/ 0.01) + 1.0);	
	
rate = 1.0 + /*crediting_cap_min*/ 0.01;  
		
return 1.0 * rate;
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
	CashFlowCommonData(2, "credited_int", "fiaafund_liab_credited_int",  "credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_credited_int, 'E','Y', '3', 'C', (size_t)&modelOffset->credited_int),
	CashFlowCommonData(3, "crediting_cap_rate", "fiaafund_liab_crediting_cap_rate",  "crediting_cap_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_cap_rate, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_cap_rate),
	CashFlowCommonData(4, "crediting_part_rate", "fiaafund_liab_crediting_part_rate",  "crediting_part_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_part_rate, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_part_rate),
	CashFlowCommonData(5, "crediting_rate", "fiaafund_liab_crediting_rate",  "crediting_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate, 'E','N', '3', 'C', (size_t)&modelOffset->crediting_rate),
	CashFlowCommonData(6, "crediting_rate_cumul_crbg", "fiaafund_liab_crediting_rate_cumul_crbg",  "crediting_rate_cumul_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_cumul_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_rate_cumul_crbg),
	CashFlowCommonData(7, "crediting_rate_fix", "fiaafund_liab_crediting_rate_fix",  "crediting_rate_fix",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_rate_fix, 'E','N', '3', 'C', (size_t)&modelOffset->crediting_rate_fix),
	CashFlowCommonData(8, "crediting_sprd_rate_crbg", "fiaafund_liab_crediting_sprd_rate_crbg",  "crediting_sprd_rate_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_sprd_rate_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_sprd_rate_crbg),
	CashFlowCommonData(9, "crediting_trigger_rate_crbg", "fiaafund_liab_crediting_trigger_rate_crbg",  "crediting_trigger_rate_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_crediting_trigger_rate_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_trigger_rate_crbg),
	CashFlowCommonData(10, "enhanced_part_rate_crbg", "fiaafund_liab_enhanced_part_rate_crbg",  "enhanced_part_rate_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_enhanced_part_rate_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->enhanced_part_rate_crbg),
	CashFlowCommonData(11, "eprs_sfc_ben_crbg", "fiaafund_liab_eprs_sfc_ben_crbg",  "eprs_sfc_ben_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_eprs_sfc_ben_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->eprs_sfc_ben_crbg),
	CashFlowCommonData(12, "eprs_sfc_ben_gross_crbg", "fiaafund_liab_eprs_sfc_ben_gross_crbg",  "eprs_sfc_ben_gross_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_eprs_sfc_ben_gross_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->eprs_sfc_ben_gross_crbg),
	CashFlowCommonData(13, "eprs_strat_fee_crbg", "fiaafund_liab_eprs_strat_fee_crbg",  "eprs_strat_fee_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_eprs_strat_fee_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->eprs_strat_fee_crbg),
	CashFlowCommonData(14, "eprs_strat_fee_partial_bef_crbg", "fiaafund_liab_eprs_strat_fee_partial_bef_crbg",  "eprs_strat_fee_partial_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_eprs_strat_fee_partial_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->eprs_strat_fee_partial_bef_crbg),
	CashFlowCommonData(15, "eprs_strat_fee_partial_e_crbg", "fiaafund_liab_eprs_strat_fee_partial_e_crbg",  "eprs_strat_fee_partial_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_eprs_strat_fee_partial_e_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->eprs_strat_fee_partial_e_crbg),
	CashFlowCommonData(16, "fa_crediting_rate_crbg", "fiaafund_liab_fa_crediting_rate_crbg",  "fa_crediting_rate_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fa_crediting_rate_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->fa_crediting_rate_crbg),
	CashFlowCommonData(17, "fa_pricing_rate_crbg", "fiaafund_liab_fa_pricing_rate_crbg",  "fa_pricing_rate_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fa_pricing_rate_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->fa_pricing_rate_crbg),
	CashFlowCommonData(18, "fa_reference_rate_crbg", "fiaafund_liab_fa_reference_rate_crbg",  "fa_reference_rate_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fa_reference_rate_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->fa_reference_rate_crbg),
	CashFlowCommonData(19, "fund_released_ann", "fiaafund_liab_fund_released_ann",  "fund_released_ann",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_ann, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_ann),
	CashFlowCommonData(20, "fund_released_dth", "fiaafund_liab_fund_released_dth",  "fund_released_dth",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_dth, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_dth),
	CashFlowCommonData(21, "fund_released_maturity", "fiaafund_liab_fund_released_maturity",  "fund_released_maturity",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_maturity, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_maturity),
	CashFlowCommonData(22, "fund_released_surr", "fiaafund_liab_fund_released_surr",  "fund_released_surr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_surr, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_surr),
	CashFlowCommonData(23, "fund_released_withdrl", "fiaafund_liab_fund_released_withdrl",  "fund_released_withdrl",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_released_withdrl, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_withdrl),
	CashFlowCommonData(24, "fund_val_b", "fiaafund_liab_fund_val_b",  "fund_val_b",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_b, 'B','N', '3', 'C', (size_t)&modelOffset->fund_val_b),
	CashFlowCommonData(25, "fund_val_b_bef", "fiaafund_liab_fund_val_b_bef",  "fund_val_b_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_b_bef, 'B','N', '3', 'C', (size_t)&modelOffset->fund_val_b_bef),
	CashFlowCommonData(26, "fund_val_beg_term_crbg", "fiaafund_liab_fund_val_beg_term_crbg",  "fund_val_beg_term_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_beg_term_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->fund_val_beg_term_crbg),
	CashFlowCommonData(27, "fund_val_beg_term_e_crbg", "fiaafund_liab_fund_val_beg_term_e_crbg",  "fund_val_beg_term_e_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_beg_term_e_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->fund_val_beg_term_e_crbg),
	CashFlowCommonData(28, "fund_val_decrem", "fiaafund_liab_fund_val_decrem",  "fund_val_decrem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_decrem, 'E','Y', '3', 'P', (size_t)&modelOffset->fund_val_decrem),
	CashFlowCommonData(29, "fund_val_e", "fiaafund_liab_fund_val_e",  "fund_val_e",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_e, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val_e),
	CashFlowCommonData(30, "fund_val_e_bef", "fiaafund_liab_fund_val_e_bef",  "fund_val_e_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_e_bef, 'E','N', '3', 'C', (size_t)&modelOffset->fund_val_e_bef),
	CashFlowCommonData(31, "fund_val_rebal", "fiaafund_liab_fund_val_rebal",  "fund_val_rebal",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_fund_val_rebal, 'B','Y', '3', 'C', (size_t)&modelOffset->fund_val_rebal),
	CashFlowCommonData(32, "gmab_av_b_crbg", "fiaafund_liab_gmab_av_b_crbg",  "gmab_av_b_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_av_b_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_av_b_crbg),
	CashFlowCommonData(33, "gmab_av_e_bef_crbg", "fiaafund_liab_gmab_av_e_bef_crbg",  "gmab_av_e_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_av_e_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_av_e_bef_crbg),
	CashFlowCommonData(34, "gmab_av_e_crbg", "fiaafund_liab_gmab_av_e_crbg",  "gmab_av_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_av_e_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_av_e_crbg),
	CashFlowCommonData(35, "gmab_chg_crbg", "fiaafund_liab_gmab_chg_crbg",  "gmab_chg_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_chg_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_chg_crbg),
	CashFlowCommonData(36, "gmab_chg_partial_e_bef_crbg", "fiaafund_liab_gmab_chg_partial_e_bef_crbg",  "gmab_chg_partial_e_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_chg_partial_e_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_chg_partial_e_bef_crbg),
	CashFlowCommonData(37, "gmab_chg_partial_e_crbg", "fiaafund_liab_gmab_chg_partial_e_crbg",  "gmab_chg_partial_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_chg_partial_e_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_chg_partial_e_crbg),
	CashFlowCommonData(38, "gmab_global_payoff_crbg", "fiaafund_liab_gmab_global_payoff_crbg",  "gmab_global_payoff_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_global_payoff_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_global_payoff_crbg),
	CashFlowCommonData(39, "gmab_payoff_crbg", "fiaafund_liab_gmab_payoff_crbg",  "gmab_payoff_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmab_payoff_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_payoff_crbg),
	CashFlowCommonData(40, "gmwb_chg", "fiaafund_liab_gmwb_chg",  "gmwb_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_chg, 'B','Y', '3', 'C', (size_t)&modelOffset->gmwb_chg),
	CashFlowCommonData(41, "gmwb_chg_partial_bef_crbg", "fiaafund_liab_gmwb_chg_partial_bef_crbg",  "gmwb_chg_partial_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_chg_partial_bef_crbg, 'B','Y', '3', 'C', (size_t)&modelOffset->gmwb_chg_partial_bef_crbg),
	CashFlowCommonData(42, "gmwb_chg_partial_e_crbg", "fiaafund_liab_gmwb_chg_partial_e_crbg",  "gmwb_chg_partial_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_gmwb_chg_partial_e_crbg, 'B','Y', '3', 'C', (size_t)&modelOffset->gmwb_chg_partial_e_crbg),
	CashFlowCommonData(43, "hedge_cash_flow", "fiaafund_liab_hedge_cash_flow",  "hedge_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cash_flow),
	CashFlowCommonData(44, "hedge_inv_amt_bom", "fiaafund_liab_hedge_inv_amt_bom",  "hedge_inv_amt_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_inv_amt_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->hedge_inv_amt_bom),
	CashFlowCommonData(45, "hedge_mkt_val", "fiaafund_liab_hedge_mkt_val",  "hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->hedge_mkt_val),
	CashFlowCommonData(46, "hedge_mkt_val_growth", "fiaafund_liab_hedge_mkt_val_growth",  "hedge_mkt_val_growth",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_mkt_val_growth, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_mkt_val_growth),
	CashFlowCommonData(47, "hedge_mkt_val_per_unit_notional", "fiaafund_liab_hedge_mkt_val_per_unit_notional",  "hedge_mkt_val_per_unit_notional",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_mkt_val_per_unit_notional, 'E','N', '3', 'P', (size_t)&modelOffset->hedge_mkt_val_per_unit_notional),
	CashFlowCommonData(48, "hedge_sale_amt_bom", "fiaafund_liab_hedge_sale_amt_bom",  "hedge_sale_amt_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_sale_amt_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->hedge_sale_amt_bom),
	CashFlowCommonData(49, "hedge_sale_amt_eom", "fiaafund_liab_hedge_sale_amt_eom",  "hedge_sale_amt_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_hedge_sale_amt_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_sale_amt_eom),
	CashFlowCommonData(50, "index_term_elapsed_pct_crbg", "fiaafund_liab_index_term_elapsed_pct_crbg",  "index_term_elapsed_pct_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_elapsed_pct_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_elapsed_pct_crbg),
	CashFlowCommonData(51, "index_term_return_crbg", "fiaafund_liab_index_term_return_crbg",  "index_term_return_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_term_return_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_return_crbg),
	CashFlowCommonData(52, "index_val", "fiaafund_liab_index_val",  "index_val",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_val, 'E','Y', '3', 'C', (size_t)&modelOffset->index_val),
	CashFlowCommonData(53, "index_val_beg_term_crbg", "fiaafund_liab_index_val_beg_term_crbg",  "index_val_beg_term_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_val_beg_term_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->index_val_beg_term_crbg),
	CashFlowCommonData(54, "index_val_bom", "fiaafund_liab_index_val_bom",  "index_val_bom",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_index_val_bom, 'E','Y', '3', 'P', (size_t)&modelOffset->index_val_bom),
	CashFlowCommonData(55, "initialize", "fiaafund_liab_initialize",  "initialize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(56, "lapse_dyn_crediting_rt_crbg", "fiaafund_liab_lapse_dyn_crediting_rt_crbg",  "lapse_dyn_crediting_rt_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_lapse_dyn_crediting_rt_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_dyn_crediting_rt_crbg),
	CashFlowCommonData(57, "notional_amt_required", "fiaafund_liab_notional_amt_required",  "notional_amt_required",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_amt_required, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_required),
	CashFlowCommonData(58, "notional_amt_required_bef", "fiaafund_liab_notional_amt_required_bef",  "notional_amt_required_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_amt_required_bef, 'E','N', '3', 'P', (size_t)&modelOffset->notional_amt_required_bef),
	CashFlowCommonData(59, "notional_to_hedge", "fiaafund_liab_notional_to_hedge",  "notional_to_hedge",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge, 'E','N', '3', 'C', (size_t)&modelOffset->notional_to_hedge),
	CashFlowCommonData(60, "notional_to_hedge_cap", "fiaafund_liab_notional_to_hedge_cap",  "notional_to_hedge_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_cap, 'E','N', '3', 'C', (size_t)&modelOffset->notional_to_hedge_cap),
	CashFlowCommonData(61, "notional_to_hedge_index", "fiaafund_liab_notional_to_hedge_index",  "notional_to_hedge_index",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_index, 'E','N', '3', 'C', (size_t)&modelOffset->notional_to_hedge_index),
	CashFlowCommonData(62, "notional_to_hedge_long_strike", "fiaafund_liab_notional_to_hedge_long_strike",  "notional_to_hedge_long_strike",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_long_strike, 'E','N', '3', 'C', (size_t)&modelOffset->notional_to_hedge_long_strike),
	CashFlowCommonData(63, "notional_to_hedge_net", "fiaafund_liab_notional_to_hedge_net",  "notional_to_hedge_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_notional_to_hedge_net, 'E','N', '3', 'C', (size_t)&modelOffset->notional_to_hedge_net),
	CashFlowCommonData(64, "opt_budget", "fiaafund_liab_opt_budget",  "opt_budget",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget, 'E','N', '3', 'C', (size_t)&modelOffset->opt_budget),
	CashFlowCommonData(65, "opt_budget_amt", "fiaafund_liab_opt_budget_amt",  "opt_budget_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_amt, 'E','N', '3', 'C', (size_t)&modelOffset->opt_budget_amt),
	CashFlowCommonData(66, "opt_budget_eprs_crbg", "fiaafund_liab_opt_budget_eprs_crbg",  "opt_budget_eprs_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_budget_eprs_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_budget_eprs_crbg),
	CashFlowCommonData(67, "opt_cost_atm_crbg", "fiaafund_liab_opt_cost_atm_crbg",  "opt_cost_atm_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_cost_atm_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_cost_atm_crbg),
	CashFlowCommonData(68, "opt_cost_beg_term_crbg", "fiaafund_liab_opt_cost_beg_term_crbg",  "opt_cost_beg_term_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_cost_beg_term_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_cost_beg_term_crbg),
	CashFlowCommonData(69, "opt_cost_bs_bom_crbg", "fiaafund_liab_opt_cost_bs_bom_crbg",  "opt_cost_bs_bom_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_cost_bs_bom_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_cost_bs_bom_crbg),
	CashFlowCommonData(70, "opt_cost_bs_eom_crbg", "fiaafund_liab_opt_cost_bs_eom_crbg",  "opt_cost_bs_eom_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_cost_bs_eom_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_cost_bs_eom_crbg),
	CashFlowCommonData(71, "opt_cost_by_grid_bom_crbg", "fiaafund_liab_opt_cost_by_grid_bom_crbg",  "opt_cost_by_grid_bom_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_cost_by_grid_bom_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_cost_by_grid_bom_crbg),
	CashFlowCommonData(72, "opt_payoff", "fiaafund_liab_opt_payoff",  "opt_payoff",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_payoff, 'E','Y', '3', 'C', (size_t)&modelOffset->opt_payoff),
	CashFlowCommonData(73, "opt_strike_price", "fiaafund_liab_opt_strike_price",  "opt_strike_price",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_strike_price, 'E','N', '3', 'P', (size_t)&modelOffset->opt_strike_price),
	CashFlowCommonData(74, "opt_value_net_numer", "fiaafund_liab_opt_value_net_numer",  "opt_value_net_numer",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_opt_value_net_numer, 'E','Y', '3', 'P', (size_t)&modelOffset->opt_value_net_numer),
	CashFlowCommonData(75, "pfwd_surr_fund_val", "fiaafund_liab_pfwd_surr_fund_val",  "pfwd_surr_fund_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_pfwd_surr_fund_val, 'E','Y', '3', 'C', (size_t)&modelOffset->pfwd_surr_fund_val),
	CashFlowCommonData(76, "prem_alloc", "fiaafund_liab_prem_alloc",  "prem_alloc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_prem_alloc, 'B','Y', '3', 'C', (size_t)&modelOffset->prem_alloc),
	CashFlowCommonData(77, "prem_bonus", "fiaafund_liab_prem_bonus",  "prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_prem_bonus, 'B','Y', '3', 'C', (size_t)&modelOffset->prem_bonus),
	CashFlowCommonData(78, "prorated_strategy_return_crbg", "fiaafund_liab_prorated_strategy_return_crbg",  "prorated_strategy_return_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_prorated_strategy_return_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->prorated_strategy_return_crbg),
	CashFlowCommonData(79, "startup", "fiaafund_liab_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::virtual_startup, 'E','Y', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(80, "strategy_return_crbg", "fiaafund_liab_strategy_return_crbg",  "strategy_return_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIAAFUND_LIAB_UDF::fiaafund_liab_strategy_return_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->strategy_return_crbg)
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
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for crediting_dyn_lever                                                                                       
	const ChoicePair crediting_dyn_leverChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::DYNAMIC_CAP, "Dynamic Cap")
		,ChoicePair(StrEnum::DYNAMIC_PART, "Dynamic Part")
		,ChoicePair(StrEnum::DYNAMIC_TRIGGER, "Dynamic Trigger")
		,ChoicePair(StrEnum::DYNAMIC_PART_EPRS, "Dynamic Part Eprs")
		,ChoicePair(StrEnum::DYNAMIC_SPRD, "Dynamic Sprd")
		,ChoicePair(StrEnum::DYNAMIC_PART_SPRD, "Dynamic Part Sprd")
	};
	const EnumList crediting_dyn_leverEnumList(6, crediting_dyn_leverChoicePairs);

	// EnumList for crediting_rate_defn                                                                                       
	const ChoicePair crediting_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::POINT_TO_POINT, "Point to Point")
		,ChoicePair(StrEnum::MOVING_AVERAGE, "Moving Average")
		,ChoicePair(StrEnum::MONTHLY_SUM_CAP, "Monthly Sum Cap")
		,ChoicePair(StrEnum::FIXED_RATE, "Fixed Rate")
	};
	const EnumList crediting_rate_defnEnumList(4, crediting_rate_defnChoicePairs);

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
	Descriptor(0, Attribute::DOUBLE,	"crediting_cap_max", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_cap_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::DOUBLE,	"crediting_cap_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_cap_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::STR_ENUM,	"crediting_dyn_lever", -1, (size_t)&modelOffset->crediting_dyn_lever,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &crediting_dyn_leverEnumList, Feature(true)),
	Descriptor(3, Attribute::STRING,	"crediting_eqt_index", -1, (size_t)&modelOffset->crediting_eqt_index,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::DOUBLE,	"crediting_floor", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_floor,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::DOUBLE,	"crediting_floor_init", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_floor_init,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::INT,	"crediting_mths", -1, (size_t)&modelOffset->crediting_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::DOUBLE,	"crediting_part_eprs_max", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_part_eprs_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::DOUBLE,	"crediting_part_eprs_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_part_eprs_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::DOUBLE,	"crediting_part_max", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_part_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::DOUBLE,	"crediting_part_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_part_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::STR_ENUM,	"crediting_rate_defn", -1, (size_t)&modelOffset->crediting_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &crediting_rate_defnEnumList, Feature(true)),
	Descriptor(12, Attribute::INT,	"crediting_rate_guar_mths", -1, (size_t)&modelOffset->crediting_rate_guar_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::DOUBLE,	"crediting_sprd_max", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_sprd_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::DOUBLE,	"crediting_sprd_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_sprd_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::DOUBLE,	"crediting_trigger_max", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_trigger_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::DOUBLE,	"crediting_trigger_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_trigger_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::STR_ENUM,	"display_solver_warnings_defn", -1, (size_t)&modelOffset->display_solver_warnings_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &display_solver_warnings_defnEnumList, Feature(false)),
	Descriptor(18, Attribute::DOUBLE,	"eprs_add_par_threshold", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eprs_add_par_threshold,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::DOUBLE,	"eprs_add_part_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eprs_add_part_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::DOUBLE,	"eprs_rounding_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eprs_rounding_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::DOUBLE,	"eprs_strat_fee_pct_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->eprs_strat_fee_pct_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::STRING,	"fund_id", -1, (size_t)&modelOffset->fund_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(23, Attribute::STR_ENUM,	"fund_type", -1, (size_t)&modelOffset->fund_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &fund_typeEnumList, Feature(true)),
	Descriptor(24, Attribute::DOUBLE,	"fund_val_split_prop", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fund_val_split_prop,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(25, Attribute::DOUBLE,	"gwl_ceding_exp_allow_level_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gwl_ceding_exp_allow_level_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::STR_ENUM,	"hedge_defn", -1, (size_t)&modelOffset->hedge_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &hedge_defnEnumList, Feature(true)),
	Descriptor(27, Attribute::STRING,	"hedge_grp_code", -1, (size_t)&modelOffset->hedge_grp_code,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(28, Attribute::DOUBLE,	"init_fia_cap", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_fia_cap,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(29, Attribute::DOUBLE,	"init_fund_val", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_fund_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(30, Attribute::DOUBLE,	"init_part_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_part_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(31, Attribute::DOUBLE,	"init_sprd_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_sprd_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(32, Attribute::DOUBLE,	"init_trigger_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_trigger_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(33, Attribute::STR_ENUM,	"lookback_defn", -1, (size_t)&modelOffset->lookback_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &lookback_defnEnumList, Feature(true)),
	Descriptor(34, Attribute::STR_ENUM,	"lookback_sampling_interval", -1, (size_t)&modelOffset->lookback_sampling_interval,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &lookback_sampling_intervalEnumList, Feature(true)),
	Descriptor(35, Attribute::DOUBLE,	"pct_to_hedge", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pct_to_hedge,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(36, Attribute::DOUBLE,	"rate_chg_threshold_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rate_chg_threshold_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(37, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(38, Attribute::SCALAR_INT,	"commencement_period", -1, (size_t)&modelOffset->commencement_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIAAFUND_LIAB_UDF::fiaafund_liab_commencement_period)),
	Descriptor(39, Attribute::SCALAR_INT,	"elapsed_mths", -1, (size_t)&modelOffset->elapsed_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIAAFUND_LIAB_UDF::fiaafund_liab_elapsed_mths)),
	Descriptor(40, Attribute::SCALAR_INT,	"lookback_mths", -1, (size_t)&modelOffset->lookback_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIAAFUND_LIAB_UDF::fiaafund_liab_lookback_mths)),
	Descriptor(41, Attribute::SCALAR_INT,	"lookback_sampling_mths", -1, (size_t)&modelOffset->lookback_sampling_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIAAFUND_LIAB_UDF::fiaafund_liab_lookback_sampling_mths)),
	Descriptor(42, Attribute::SCALAR_INT,	"maturity_period", -1, (size_t)&modelOffset->maturity_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIAAFUND_LIAB_UDF::fiaafund_liab_maturity_period)),
	Descriptor(43, Attribute::SCALAR_DOUBLE,	"nb_opt_budget_calc_crbg", -1, (size_t)&modelOffset->nb_opt_budget_calc_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&FIAAFUND_LIAB_UDF::fiaafund_liab_nb_opt_budget_calc_crbg)),
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
	nullptr};
	const size_t FIAAFUND_LIAB::sDescriptorCount = 44;

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

	, adco(company_asset_adco)
	, asset(company_asset)
	, asset_sub_port(company_asset_asset_sub_port)
	, bond(company_asset_bond)
	, bond_cf(company_asset_bond_bond_cf)
	, eio(company_asset_eio)
	, epa(company_asset_epa)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_rates(company_liab_fia_fia_rates)
	, liab(company_liab)
	, mtg(company_asset_mtg)
	, mtg_cf(company_asset_mtg_mtg_cf)
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
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(80, FIAAFUND_LIAB::descriptorTable, arrayPersistentObj), Variable(*this)

	, adco(company_asset_adco)
	, asset(company_asset)
	, asset_sub_port(company_asset_asset_sub_port)
	, bond(company_asset_bond)
	, bond_cf(company_asset_bond_bond_cf)
	, eio(company_asset_eio)
	, epa(company_asset_epa)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_rates(company_liab_fia_fia_rates)
	, liab(company_liab)
	, mtg(company_asset_mtg)
	, mtg_cf(company_asset_mtg_mtg_cf)
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

#ifdef __CREATE_AA_COMP_COMP_CLASS_
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
#ifdef __CREATE_EIO_ASSET_CLASS_
       company_asset_eio = 0;
#endif
#ifdef __CREATE_EPA_ASSET_CLASS_
       company_asset_epa = 0;
#endif
#ifdef __CREATE_MTG_ASSET_CLASS_
       company_asset_mtg = 0;
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
       company_asset_mtg_mtg_cf = 0;
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

	for (int cf_no = 1; cf_no <= 80; cf_no++)
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

#ifdef __CREATE_AA_COMP_COMP_CLASS_
		company = (AA_COMP_COMP*)(findUnique("company"));
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
#ifdef __CREATE_EIO_ASSET_CLASS_
		company_asset_eio = (EIO_ASSET*)(findUnique("company|asset|eio"));
#endif
#ifdef __CREATE_EPA_ASSET_CLASS_
		company_asset_epa = (EPA_ASSET*)(findUnique("company|asset|epa"));
#endif
#ifdef __CREATE_MTG_ASSET_CLASS_
		company_asset_mtg = (MTG_ASSET*)(findUnique("company|asset|mtg"));
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
		company_asset_mtg_mtg_cf = (MTG_CF_ASSET*)(findUnique("company|asset|mtg|mtg_cf"));
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
BitArray FIAAFUND_LIAB::dataVariables(44);
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

