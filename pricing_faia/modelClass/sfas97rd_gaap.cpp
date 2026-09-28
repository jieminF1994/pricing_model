
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
#include "ModelClass\sfas97rd_gaap_udf.h"
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
#include "ModelClass\fiaafund_liab.h"
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

deptaskinput sop031_valn_input;
deptaskinput sfas97rd_valn_input;
sowfoutput sfas97rd_state_of_world_financial_output;
sowfinput sfas97rd_state_of_world_financial_input;
sowfmap sfas97rd_state_of_world_financial_input_pos;
sowfmapiter sfas97rd_state_of_world_financial_input_pos_iter;
const int ASSESS_SOP = 0;
const int DB_BEN_SOP = 1;
const int SG_BEN_SOP = 2;
const int DTH_CLAIM_COST = 3;
const int SOP_SIZE = 4;
const int EGP = 0;
const int INT_RATE = 1;
const int SOP031_PBR_FV = 2;
const int SOP031_PBR = 3;
const int DAC_ACQ_EXP = 4;
const int DAC_COMM = 5;
const int DAC_PREM_BONUS = 6;
const int DAC_REINS_YRT_ASSET = 7;
const int EMBED_DERIV_VAL = 8;
const int K_CAPZD_ACQ_EXP = 9;
const int K_CAPZD_COMM = 10;
const int K_CAPZD_PREM_BONUS = 11;
const int K_REINS_YRT_COST = 12;
const int K_SOP031_GMDB_BEN_BR = 13;
const int K_SOP031_PBR = 14;
const int K_SOP031_ULSG_BEN_BR = 15;
const int K_SOP031_UNEARN_REV_LIAB = 16;
const int K_UNEARN_REV_LIAB = 17;
const int SOP031_GMDB_BR = 18;
const int SOP031_PBR_LIAB = 19;
const int SOP031_ULSG_BR = 20;
const int UNEARN_REV_LIAB = 21;
const int POLICIES_INF = 22;
const int GAAP_SCHEDULE_SIZE = 23;

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

if (model_name == SFAS97RD)
	return sum_over_gaap("acq_exp", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return ul->acq_exp(t);
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return vul->acq_exp(t);
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return iul->acq_exp(t);
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return va->acq_exp(t);
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fa->acq_exp(t);
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fia->acq_exp(t);
	
	//Acquisition expenses are not reinsured.
	return 0.0;	
	}
#endif
}
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
if (t <= start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;
	
return max(0.0, egp_gain_exp(t)
	            + egp_gain_inv(t)
	            + egp_gain_mort(t)
	            + egp_gain_surr(t)
	            + egp_gain_persist_bon_ref(t)
                - hedge_cost(t)
	            - mrb_liab_incr(t)
				- sfas133_liab_incr(t)
	            - sop031_addl_liab_incr(t));

}

//@@ END

//@@ START - agp_history
// Cohort History Actual Gross Profits                                                                                             
// Column:AGP_HISTORY
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_agp_history(int t) {
//^^^



//^^^

#line 1 "agp_history.SFAS97RD_GAAP.for"
if (t > start_period)
	return NO_AVG;

cohort_id = cohort_id;

return cohort_history_agp;

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
	return rebase_value(5,"cal_mth",t);
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
	return rebase_value(6,"cal_yr",t);
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
	return rebase_value(7,"cal_yr_relative",t);
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

if (model_name == SFAS97RD)
	{
	if (!reins_flag)
		{
		if (fabs(seg_element->gaap_liab_net(t - 1)) < aggregate_amount_threshold)
			return NO_AVG;

		return (seg_element->gaap_cap_gain_res(t)
				+ seg_element->gaap_cap_gain_cap(t))
				* liab_net(t - 1) / seg_element->gaap_liab_net(t - 1);
		}
	else if (reins_flag)
		{
		if (fabs(seg_element->reins_gaap_liab_net(t - 1)) < aggregate_amount_threshold)
			return NO_AVG;

		return seg_element->reins_gaap_cap_gain_res(t)
			   * liab_net(t - 1) / seg_element->reins_gaap_liab_net(t - 1);
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

if (model_name == SFAS97RD)
	return sum_over_gaap("cap_gain_fund", t);

{	
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
			   * (pow(1.0 + ul->seg_element->eff_cap_gains_rate(t), 1.0 / 12.0) - 1.0);
		}
	else 
		return NO_AVG;
	}	
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
			   * (pow(1.0 + vul->seg_element->eff_cap_gains_rate(t), 1.0 / 12.0) - 1.0);
		}
	else 
		return NO_AVG;
	}	
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
			   * (pow(1.0 + iul->seg_element->eff_cap_gains_rate(t), 1.0 / 12.0) - 1.0);
		}
	else 
		return NO_AVG;
	}	
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (alm_flag)
		{
		double reins_pct = 0.0;
		
		if (!reins_flag) //Gross
			reins_pct = 1.0;
		else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance
			reins_pct = va->reins_pct;
			
		double av_b = va->sum_over_funds("av_b", t, GENERAL)
		              + va->sum_over_funds("av_b", t, DCA);

		return max(0.0, av_b)
			   * reins_pct
			   * (pow(1.0 + va->seg_element->eff_cap_gains_rate(t), 1.0 / 12.0) - 1.0);
		}		
	else 
		return NO_AVG;
	}				
#endif
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
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
			   * (pow(1.0 + fa->seg_element->eff_cap_gains_rate(t), 1.0 / 12.0) - 1.0);
		}		
	else 
		return NO_AVG;
	}				
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
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
			   * (pow(1.0 + fia->seg_element->eff_cap_gains_rate(t), 1.0 / 12.0) - 1.0);
		}		
	else 
		return NO_AVG;
	}				
#endif
}
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

if (model_name == SFAS97RD)
	{
	//force call for reports
	acq_exp(t);

	// No deferrals after stated amortizaton period
	if (!valn_flag && t > amortzn_period)
		return 0.0;
	
	return sum_over_gaap("capzd_acq_exp", t);
	}

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
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
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
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
}
return NO_AVG;

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

if (model_name == SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (!valn_flag && t > amortzn_period)
		return 0.0;

	return sum_over_gaap("capzd_comm_bom", t);
	}
	
{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (ul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_excess_bom(t);
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (vul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_excess_bom(t);
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (iul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_excess_bom(t);
	}
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (va->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_excess_bom(t);
	}
#endif	
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (fa->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_excess_bom(t);
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (fia->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_excess_bom(t);
	}
#endif
}
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

if (model_name == SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (!valn_flag && t > amortzn_period)
		return 0.0;

	return sum_over_gaap("capzd_comm_chargeback", t);
	}

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (ul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_chargeback(t);
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (vul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_chargeback(t);
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (iul->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_chargeback(t);
	}
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (va->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_chargeback(t);
	}
#endif
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (fa->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_chargeback(t);
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (fia->isMainModel && !valn_flag && t > amortzn_period)
		return 0.0;

	return comm_chargeback(t);
	}
#endif
}
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

if (model_name == SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (!valn_flag && t > amortzn_period)
		return 0.0;
	
	return sum_over_gaap("capzd_prem_bonus", t);
	}

{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
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
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
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
}
return NO_AVG;

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
if (t <= start_period || t > final_period)
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

if (model_name == SFAS97RD)
	return sum_over_gaap("cash_flow_bom", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{		
	if (!reins_flag) //Gross
		return fa->direct_cash_flow_bom(t);
	else if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance
		return fa->reins_cash_flow_bom(t);
	
	return 0.0;
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{		
	if (!reins_flag) //Gross
		return fia->direct_cash_flow_bom(t);
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance
		return fia->reins_cash_flow_bom(t);
	
	return 0.0;
	}

#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{		
	if (!reins_flag) //Gross
		return va->direct_cash_flow_bom(t);
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance
		return va->reins_cash_flow_bom(t);
	
	return 0.0;
	}

#endif
}
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

if (model_name == SFAS97RD)
	return cash_flow_bom(t)
	       * seg_element->cash_flow_rate_mthly(t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	return cash_flow_bom(t)
	       * (pow(1.0 + ul->asset_yld(t), 1.0 / 12.0) - 1.0);	
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	return cash_flow_bom(t)
	       * (pow(1.0 + iul->asset_yld(t), 1.0 / 12.0) - 1.0);	
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	return cash_flow_bom(t)
	       * (pow(1.0 + vul->asset_yld(t), 1.0 / 12.0) - 1.0);	
#endif
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	return cash_flow_bom(t)
	       * (pow(1.0 + fa->asset_yld(t), 1.0 / 12.0) - 1.0);	
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	return cash_flow_bom(t)
	       * (pow(1.0 + fia->asset_yld(t), 1.0 / 12.0) - 1.0);	
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	return cash_flow_bom(t)
	       * (pow(1.0 + va->asset_yld(t), 1.0 / 12.0) - 1.0);	
#endif
}

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

if (model_name == SFAS97RD)
	return sum_over_gaap("charges", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
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
}
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

if (model_name == SFAS97RD)
	return sum_over_gaap("comm_chargeback", t);

{	
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return ul->comm_chargeback(t);

    if (reins_flag && ul->reins_flag && ul->coins_flag) //Commission of modco is equal to reinsurance expense allowance.
		return ul->sum_over_reinsurance("ea_chargeback", t, COINSURANCE)
			   + ul->sum_over_reinsurance("ea_chargeback", t, MODIFIED_COINSURANCE);

	return NO_AVG;
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return vul->comm_chargeback(t);

    if (reins_flag && vul->reins_flag && vul->coins_flag) //Commission of modco is equal to reinsurance expense allowance.
		return vul->sum_over_reinsurance("ea_chargeback", t, COINSURANCE)
			   + vul->sum_over_reinsurance("ea_chargeback", t, MODIFIED_COINSURANCE);

	return NO_AVG;
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return iul->comm_chargeback(t);

    if (reins_flag && iul->reins_flag && iul->coins_flag) //Commission of modco is equal to reinsurance expense allowance.
		return iul->sum_over_reinsurance("ea_chargeback", t, COINSURANCE)
			   + iul->sum_over_reinsurance("ea_chargeback", t, MODIFIED_COINSURANCE);

	return NO_AVG;
	}
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return va->comm_chargeback(t);

	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return va->comm_chargeback(t) * va->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fa->comm_chargeback(t);

	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fa->comm_chargeback(t) * fa->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fia->comm_chargeback(t);

	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fia->comm_chargeback(t) * fia->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	
}
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

if (model_name == SFAS97RD)
	return sum_over_gaap("comm_excess_bom", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
    {
    if (!reins_flag) //Gross
    	return max(0.0, fa->comm_bom(t) - comm_trail_bom(t));

    if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance
    	return max(0.0, fa->comm_bom(t) * fa->reins_pct - comm_trail_bom(t));

    //Ceded and MP Not Reinsured via Coinsurance
    return 0.0;
    }
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
    {
    if (!reins_flag) //Gross
    	return max(0.0, fia->comm_bom(t) - comm_trail_bom(t));

    if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance
        return max(0.0, fia->comm_bom(t) * fia->reins_pct - comm_trail_bom(t));

    //Ceded and MP Not Reinsured via Coinsurance
    return 0.0;
    }
#endif
}
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

if (model_name == SFAS97RD)
	return sum_over_gaap("comm_trail_bom", t);

{	
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	double gross_comm_bom_trail = 0.0;
	
	if (va->pol_yr(t) > va->prem_term)
		{
		va->comm_py_lookup = va->pol_yr(comm_pct_fund_ult_index);
		double comm_pct_fund_local = va->comm_pct_fund;
		gross_comm_bom_trail
		= va->fund_val(t - 1)
		  * comm_pct_fund_local
		  / 12.0;
		}
	else
		{
		va->comm_py_lookup = va->pol_yr(prem_term_period);
		double comm_pct_prem_local = va->comm_pct_prem;
		va->comm_py_lookup = va->pol_yr(comm_pct_fund_ult_index);
		double comm_pct_fund_local = va->comm_pct_fund;

		gross_comm_bom_trail
		= va->prem_paid(t) 
	      * comm_pct_prem_local
		  + va->fund_val(t - 1)
		    * comm_pct_fund_local
			/ 12.0;	
		}

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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	double gross_comm_bom_trail = 0.0;
	fa->pol_yr_lookup = fa->pol_yr(comm_pct_fund_ult_index);
	double comm_pct_fund_local = fa->comm_pct_fund;
	fa->pol_yr_lookup = fa->pol_yr(prem_term_period);
	double comm_pct_prem_local = fa->comm_pct_prem;

	if (fa->pol_yr(t) > fa->prem_term)
		gross_comm_bom_trail
		= fa->fund_val_fixed(t - 1)
		  * comm_pct_fund_local
		  / 12.0;
	else
		gross_comm_bom_trail
		= fa->prem_paid(t) 
	      * comm_pct_prem_local
		  + fa->fund_val_fixed(t - 1)
		    * comm_pct_fund_local
			/ 12.0;	
	
	if (!reins_flag) //Gross
		return gross_comm_bom_trail;
	
	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance
		return gross_comm_bom_trail * fa->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	comm_py_lookup = fia->pol_yr(comm_pct_fund_ult_index);
	double gross_comm_bom_trail	//for single premium product, no trail commission from commission as percent of premium
	= fia->fund_val_fixed(t - 1)
	  * fia->comm_pct_fund
	  / 12.0;
		
	if (!reins_flag) //Gross
		return gross_comm_bom_trail;
	
	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance
		return gross_comm_bom_trail * fia->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
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
	return rebase_value(24,"credited_int",t);
}



//^^^

#line 1 "credited_int.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (model_name == SFAS97RD)
	return sum_over_gaap("credited_int", t);

{	
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return max(0.0, ul->credited_int(t));
	else if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured
		return max(0.0, ul->credited_int(t) * ul->reins_pct);
	else //Ceded and MP Not Reinsured
		return 0.0;
	}	
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return max(0.0, vul->credited_int_ga(t));
	else if (reins_flag && vul->reins_flag && vul->coins_flag) //Ceded and MP Reinsured
		return max(0.0, vul->credited_int_ga(t) * vul->reins_pct);
	else //Ceded and MP Not Reinsured
		return 0.0;
	}	
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return max(0.0, iul->credited_int(t));
	else if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured
		return max(0.0, iul->credited_int(t) * iul->reins_pct);
	else //Ceded and MP Not Reinsured
		return 0.0;
	}	
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return va->credited_int_ga(t);
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->credited_int_ga(t) * va->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fa->credited_int(t);
	else if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured
		return fa->credited_int(t) * fa->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fia->credited_int(t);
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
		return fia->credited_int(t) * fia->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif
}
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
		if (valn_period == 0)
			{
			if (model_name == SFAS97RD)
				{
				cohort_id = cohort_id;
				return cohort_history_dac_acq_exp;
				}

			return 0.0;//  No History for cell pricing at issue period
			}

		return init_dac_acq_exp;		
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
			- dac_acq_exp_amortzn(t);
	
return dac_acq_exp(t - 1)
		+ capzd_acq_exp(t)
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

return k_capzd_acq_exp(t) * policies_inf(t);

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

//@@ START - dac_acq_exp_sch
// DAC Acquisition Expense Schedule                                                                                             
// Column:DAC_ACQ_EXP_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_sch(int t) {
//^^^



//^^^

#line 1 "dac_acq_exp_sch.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (valn_flag)
	return NO_AVG;

return gaap_schedule[DAC_ACQ_EXP][t];

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
		if (valn_period == 0)
			{
			if (model_name == SFAS97RD)
				{
				cohort_id = cohort_id;
				return cohort_history_dac_comm;
				}

			return 0.0;//  No History for cell pricing at issue period
			}

		return init_dac_comm;		
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
		   - dac_comm_amortzn(t);
	
return dac_comm(t - 1)
	   + capzd_comm_bom(t)
	   + capzd_comm_eom(t)	
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

return k_capzd_comm(t) * policies_inf(t);

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

//@@ START - dac_comm_sch
// DAC Commission Schedule                                                                                             
// Column:DAC_COMM_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_sch(int t) {
//^^^



//^^^

#line 1 "dac_comm_sch.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (valn_flag)
	return NO_AVG;

return gaap_schedule[DAC_COMM][t];

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
		if (valn_period == 0)
			{
			if (model_name == SFAS97RD)
				{
				cohort_id = cohort_id;
				return cohort_history_dac_prem_bonus;
				}

			return 0.0;//  No History for cell pricing at issue period
			}

		return init_dac_prem_bonus;		
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
  		   - dac_prem_bonus_amortzn(t);
	
return dac_prem_bonus(t - 1)
	   + capzd_prem_bonus(t)
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

return k_capzd_prem_bonus(t) * policies_inf(t);

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

//@@ START - dac_prem_bonus_sch
// DAC Premium Bonus Schedule                                                                                             
// Column:DAC_PREM_BONUS_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_sch(int t) {
//^^^



//^^^

#line 1 "dac_prem_bonus_sch.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (valn_flag)
	return NO_AVG;

return gaap_schedule[DAC_PREM_BONUS][t];

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
		{
		if (valn_period == 0)
			{
			if (model_name == SFAS97RD)
				{
				cohort_id = cohort_id;
				return cohort_history_dac_reins_yrt_asset;
				}

			return 0.0;//  No History for cell pricing at issue period
			}

		return init_dac_reins_yrt_asset;		
		}

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
		   - dac_reins_yrt_asset_amortzn(t);
	
return dac_reins_yrt_asset(t - 1)
	   + capzd_reins_yrt_cost(t)
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

return  k_reins_yrt_cost(t) * policies_inf(t);

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

//@@ START - dac_reins_yrt_asset_sch
// DAC YRT Reinsurance Asset Schedule                                                                                             
// Column:DAC_REINS_YRT_ASSET_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset_sch(int t) {
//^^^



//^^^

#line 1 "dac_reins_yrt_asset_sch.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (valn_flag)
	return NO_AVG;

if (!cohort_reins_yrt_indicator)
	return NO_AVG;
	
return gaap_schedule[DAC_REINS_YRT_ASSET][t];

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

return day_number_from_date(year, month, day);


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

if (model_name == SFAS97RD)
	{
	// No deferrals after stated amortizaton period
	if (!valn_flag && t > amortzn_period)
		return 0.0;

	return sum_over_gaap("deferred_loads" , t);
	}

{	
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}

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
		if (model_name == SFAS97RD)
			{
			double def_loads_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				double def_loads = deferred_loads_history(tt);
				
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

//@@ START - deferred_loads_history
// Cohort History Deferred Load                                                                                             
// Column:DEFERRED_LOADS_HISTORY
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_deferred_loads_history(int t) {
//^^^



//^^^

#line 1 "deferred_loads_history.SFAS97RD_GAAP.for"
if (t > start_period)
	return NO_AVG;

cohort_id = cohort_id;

return cohort_history_deferred_load;

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

if (model_name == SFAS97RD)
	return sum_over_gaap("dth_claim_cost", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
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
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
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
}
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
		if (model_name == SFAS97RD)
			{
			double egp_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				double egp = agp_history(tt);
				
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

if (model_name == SFAS97RD)
	{
	//force call for reports
	charges(t);
	
	{
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
	}
	{
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
	}
	{
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
	}
	{
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
	}
	{
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
	}
	{
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
	}

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
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
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
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
}
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

if (model_name == SFAS97RD)
	{
	//force call for reports
	credited_int(t);

	return sum_over_gaap("egp_gain_inv", t);
	}

{	
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	double int_earned = inv_inc_fund(t) + cap_gain_fund(t);			
	double int_credited = credited_int(t);
	
	return int_earned - int_credited;		
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	double int_earned = inv_inc_fund(t) + cap_gain_fund(t);			
	double int_credited = credited_int(t);
	
	return int_earned - int_credited;		
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	double int_earned = inv_inc_fund(t) + cap_gain_fund(t);			
	double int_credited = credited_int(t);
	
	return int_earned - int_credited;		
	}
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	double int_earned = inv_inc_fund(t) + cap_gain_fund(t);			
	double int_credited = credited_int(t);
	
	return int_earned - int_credited;		
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	double int_earned = inv_inc_fund(t) + cap_gain_fund(t);			
	double int_credited = credited_int(t);
						 
	return int_earned - int_credited;   			
	}
#endif
}	
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

if (model_name == SFAS97RD)
	{
	// use average SOP 03-1 benefits if running SFAS97RD valn.
	if (sfas97rd_valn_flag) 
		{
		charges = this->charges(t);

		{
		#if defined(__UL_LIAB_H_)
		if (sop031_flag)
			claim_cost = sop031_array[DTH_CLAIM_COST][t];
		#endif
		}
		{
		#if defined(__VUL_LIAB_H_)
		if (sop031_flag)
			claim_cost = sop031_array[DTH_CLAIM_COST][t];
		#endif
		}
		{
		#if defined(__IUL_LIAB_H_)
		if (sop031_flag)
			claim_cost = sop031_array[DTH_CLAIM_COST][t];
		#endif
		}

		if (sop031_flag)
			return charges - claim_cost;
		}

	return sum_over_gaap("egp_gain_mort", t);
	}
	
{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	return - dth_claim_cost(t);
#endif
}

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
	return rebase_value(53,"egp_gain_persist_bon_ref",t);
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

if (model_name == SFAS97RD)
	return sum_over_gaap("egp_gain_surr", t);

{	
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fa->surr_chg(t);
	
	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured
		return fa->surr_chg(t) * fa->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
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
}	
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

if (model_name == SFAS97RD)
	return sum_over_gaap("embed_deriv_cash_flow", t);

{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}

{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
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
}
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

double spot_rate = rates_ptr->get_int_rate(t, "Govt", GET_SPOT_RATE, SHORT_TERM_RATE_TERM, 0, EFFECTIVE_ANNUAL, NO_SHIFT);

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

if (model_name == SFAS97RD)
	{
	double fund_val_current = 0.0;
	double fund_val_previous1 = model_point_amount_threshold;
	double fund_val_previous2 = model_point_amount_threshold;
	int mp = 0;
	map <int, long, less <int> >::iterator mp_map_iter;
	{
	#if defined(__FIA_LIAB_H_) && defined(__AA_COMP_COMP_H_)
	if (fia_mp_map.size())
		{
		for (mp_map_iter = fia_mp_map.begin(); 
		     mp_map_iter !=fia_mp_map.end(); 
		     mp_map_iter++)
			{
			mp = mp_map_iter->first;
			
			if (t < liab->sm_fia[mp]->commencement_period
				|| t > liab->sm_fia[mp]->maturity_period)
				continue;
	
			// Skip new issue commencement period
			if (liab->sm_fia[mp]->elapsed_mths <= 0
				&& t == liab->sm_fia[mp]->commencement_period)
				continue;
	
			if (t != liab->sm_fia[mp]->commencement_period
				&& fabs(liab->sm_fia[mp]->policies_b(t)) < rate_ratio_threshold)
				continue;
	
			if ((t - 1) >= start_period)
				{
				fund_val_previous1 += liab->sm_fia[mp]->Column("fund_val_b_bef").Value(t);
				fund_val_previous2 += liab->sm_fia[mp]->Column("fund_val_fixed").Value(t - 1);
				}
	
			fund_val_current += liab->sm_fia[mp]->Column("fund_val_fixed").Value(t);
			}
		}
	#endif
	}
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
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	if (pricing_flag && t == start_period
			&& valn_period == 0)
		return NO_AVG;
	
	if (fia->fund_val_b_bef(t) <= model_point_amount_threshold)
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
}
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

if (model_name == SFAS97RD)
	return sum_over_gaap("fund_val_bef_int", t);
	
{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	if (!reins_flag) //Gross
		return va->fund_val_b(t);
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->fund_val_b(t) 
				* va->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
#endif
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	if (!reins_flag) //Gross
		return fa->fund_val_b(t);
	else if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured
		return fa->fund_val_b(t) 
				* fa->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	if (!reins_flag) //Gross
		return fia->fund_val_b(t);
	else if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
		return fia->fund_val_b(t) 
				* fia->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
#endif
}
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

if (model_name == SFAS97RD)
	return sum_over_gaap("fund_val_fixed", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return max(0.0, ul->fund_val_fixed(t));
	else if (reins_flag && ul->reins_flag && ul->coins_flag) //Ceded and MP Reinsured	
		return max(0.0, ul->fund_val_fixed(t)) * ul->reins_pct;		
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}	
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
// Use SFAS97 treatment until MRB methodology is implemented
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return max(0.0, iul->fund_val_fixed(t));
	else if (reins_flag && iul->reins_flag && iul->coins_flag) //Ceded and MP Reinsured	
		return max(0.0, iul->fund_val_fixed(t)) * iul->reins_pct;		
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}	
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return va->fund_val_fixed(t);
	else if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->fund_val_fixed(t) * va->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fa->fund_val_fixed(t);
	else if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured
		return fa->fund_val_fixed(t) * fa->reins_pct;
	else //Ceded and MP Not Reinsured
		return 0.0;	
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	return 0.0;	
#endif
}
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

if (model_name == SFAS97RD)
	return sum_over_gaap("fund_val_sa", t);

{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
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

if (model_name == SFAS97RD)
	return sum_over_gaap("gmab_ben", t);
	
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return va->maturity_claims_gmab(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->reins_maturity_claims_gmab(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}

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

if (model_name == SFAS97RD)
	return sum_over_gaap("gmdb_ben", t);

{	
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return va->dth_claims_gmdb(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->reins_dth_ben_gmdb(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}

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

if (model_name == SFAS97RD)
	return sum_over_gaap("gmib_ben", t);
	
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return va->ann_claims_gmib(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->reins_ann_claims_gmib(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}	
#endif
}

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

if (model_name == SFAS97RD)
	return sum_over_gaap("gmwb_ben", t);
	
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return va->ann_claims_gmwb(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->reins_ann_claims_gmwb(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}

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
if (t <= start_period || t > final_period)
	return NO_AVG;	

if (valn_flag)
	return NO_AVG;	

if (model_name == SFAS97RD)
	{
	{
	#if defined(__FIA_LIAB_H_) || defined(__IUL_LIAB_H_)
	return sum_over_gaap("hedge_cash_flow", t);
	#endif
	}
	if (reins_flag)
		return (seg_element->hedge_gross_array[HEDGE_CASH_FLOW][t]
		        - seg_element->hedge_net_array[HEDGE_CASH_FLOW][t])
		        * hedge_alloc_factor;
		
	return seg_element->hedge_gross_array[HEDGE_CASH_FLOW][t]
	       * hedge_alloc_factor;
	}

{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	// Need to allocate hedge cash flows from hedge group into model point like FIA

	return NO_AVG;
	}
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (reins_flag)
		return (va->hedge_gross_array[HEDGE_CASH_FLOW][t]
		        - va->hedge_net_array[HEDGE_CASH_FLOW][t])
		        * hedge_alloc_factor;
		
	return va->hedge_gross_array[HEDGE_CASH_FLOW][t]
	       * hedge_alloc_factor;
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD && !fia->isMainModel)
	{
	double hedge_grp_fund_val = 0.0;
	double fia_mp_hedge_amt = 0.0;
	
	for (int hedge_group = 0; hedge_group < fia->seg_element->hedge_grps.size(); hedge_group++)
		{
		xstring hedge_grp_name = fia->seg_element->hedge_grps[hedge_group];
		double fia_mp_fund_val = 0.0;
		
		for (int account = 0; account < fia->sm_fia_account.size(); account++)
			{
			if (fia->sm_fia_account[account]->hedge_grp_code == hedge_grp_name)
				fia_mp_fund_val += fia->sm_fia_account[account]->fund_val_e(t);
			}
		
		hedge_grp_fund_val = fia->seg_element->sm_hedge_grp[hedge_group][0]->fund_val_fixed(t);
		
		if (hedge_grp_fund_val > model_point_amount_threshold)
			fia_mp_hedge_amt += fia->seg_element->sm_hedge_grp[hedge_group][0]->hedge_cash_flow(t)
						   	    * fia_mp_fund_val / hedge_grp_fund_val;
		else 
			fia_mp_hedge_amt = 0.0;
		}
		
	if (reins_flag)
		return fia_mp_hedge_amt * fia->reins_pct;
		
	return fia_mp_hedge_amt;
	}
#endif
}
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
if (t <= start_period || t > final_period)
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
if (t < start_period || t > final_period)
	return NO_AVG;

if (valn_flag)
	return NO_AVG;

if (model_name == SFAS97RD)
	{
	{
	#if defined(__FIA_LIAB_H_) || defined(__IUL_LIAB_H_)
	return sum_over_gaap("hedge_mkt_val", t);
	#endif
	}
	if (reins_flag)
		return (seg_element->hedge_gross_array[HEDGE_MKT_VAL][t]
		        - seg_element->hedge_net_array[HEDGE_MKT_VAL][t])
		        * hedge_alloc_factor;
		
	return seg_element->hedge_gross_array[HEDGE_MKT_VAL][t]
	       * hedge_alloc_factor;
	}

{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD && !iul->isMainModel)
	{
	// Need to allocate hedge market value to model point like FIA

	return NO_AVG;
	}
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (reins_flag)
		return (va->hedge_gross_array[HEDGE_MKT_VAL][t]
		        - va->hedge_net_array[HEDGE_MKT_VAL][t])
		        * hedge_alloc_factor;
		
	return va->hedge_gross_array[HEDGE_MKT_VAL][t]
	       * hedge_alloc_factor;
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD && !fia->isMainModel)
	{
	double hedge_grp_fund_val = 0.0;
	double fia_mp_hedge_amt = 0.0;
	
	for (int hedge_group = 0; hedge_group < fia->seg_element->hedge_grps.size(); hedge_group++)
		{
		xstring hedge_grp_name = fia->seg_element->hedge_grps[hedge_group];
		double fia_mp_fund_val = 0.0;
		
		for (int account = 0; account < fia->sm_fia_account.size(); account++)
			{
			if (fia->sm_fia_account[account]->hedge_grp_code == hedge_grp_name)
				fia_mp_fund_val += fia->sm_fia_account[account]->fund_val_e(t);
			}
		
		hedge_grp_fund_val = fia->seg_element->sm_hedge_grp[hedge_group][0]->fund_val_fixed(t);
		
		if (hedge_grp_fund_val > model_point_amount_threshold)
			fia_mp_hedge_amt += fia->seg_element->sm_hedge_grp[hedge_group][0]->hedge_mkt_val(t)
						  	    * fia_mp_fund_val / hedge_grp_fund_val;
		else 
			fia_mp_hedge_amt = 0.0;
		}
		
	if (reins_flag)
		return fia_mp_hedge_amt * fia->reins_pct;
		
	return fia_mp_hedge_amt;
	}
#endif
}
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
if (t <= start_period || t > final_period)
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

if (model_name == SFAS97RD)
	return sum_over_gaap("host_contract_cred_int", t);
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	return host_contract_val(t - 1) 
		   * (pow(1.0 + host_accrual_rate , 1.0 / 12.0) - 1.0);
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	return host_contract_val(t - 1) 
		   * (pow(1.0 + host_accrual_rate , 1.0 / 12.0) - 1.0);
	}
#endif
}
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

if (model_name == SFAS97RD)
	return sum_over_gaap("host_contract_val", t);

{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
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
}

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

if (model_name == SFAS97RD)
	return sum_over_gaap("host_contract_val_bef", t);
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
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
}
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
if (t != 0)
	return NO_AVG;

if (model_name != SFAS97RD)
	{
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
	
		if (valn_period > 0 && ul->mp_id != "mp_time_step")
			read_state_of_world_financial();
		}
	#endif
	}
	{
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
	
		if (valn_period > 0 && vul->mp_id != "mp_time_step")
			read_state_of_world_financial();
		}
	#endif
	}
	{
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
	
		if (valn_period > 0 && iul->mp_id != "mp_time_step")
			read_state_of_world_financial();
		}
	#endif
	}
	{
	#if defined(__VA_LIAB_H_)
	if (va->isMainModel)
		{
		if (!valn_flag)
			get_gaap_schedule_items();
	
		if (valn_period > 0 && va->mp_id != "mp_time_step")
			read_state_of_world_financial();
		}
	#endif
	}
	{
	#if defined(__FA_LIAB_H_)
	if (fa->isMainModel)
		{
		if (!valn_flag)
			get_gaap_schedule_items();
	
		if (valn_period > 0 && fa->mp_id != "mp_time_step")
			read_state_of_world_financial();
		}
	#endif
	}
	{
	#if defined(__FIA_LIAB_H_)
	if (fia->isMainModel)
		{
		if (!valn_flag)
			get_gaap_schedule_items();
	
		if (valn_period > 0 && fia->mp_id != "mp_time_step")
			read_state_of_world_financial();
		}
	#endif
	}
	return 1.0;
	}			
//else (model_name == SFAS97RD)
int cohort_mp_count = 0;

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

int mp = 0;
map <int, long, less <int> >::iterator mp_map_iter;

// initialize cohort_first_issue_period, cohort_last_issue_period and cohort_max_maturity_period
if (reins_flag)
	{
	cohort_first_issue_period 
	= seg_element->sm_sfas97rd[getElementNumber(0)][0]->cohort_first_issue_period;

	cohort_last_issue_period 
	= seg_element->sm_sfas97rd[getElementNumber(0)][0]->cohort_last_issue_period;

	cohort_max_maturity_period 
	= seg_element->sm_sfas97rd[getElementNumber(0)][0]->cohort_max_maturity_period;
	}

// Set GAAP History Table for Gross or Ceded Business
{
#if defined(__UL_LIAB_H_) && defined(__AA_COMP_COMP_H_)
for (mp_map_iter = seg_element->ul_mp_map.begin();
		mp_map_iter != seg_element->ul_mp_map.end();
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
}
{
#if defined(__VUL_LIAB_H_) && defined(__AA_COMP_COMP_H_)
for (mp_map_iter = seg_element->vul_mp_map.begin();
		mp_map_iter != seg_element->vul_mp_map.end();
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
}
{
#if defined(__IUL_LIAB_H_) && defined(__AA_COMP_COMP_H_)
for (mp_map_iter = seg_element->iul_mp_map.begin();
		mp_map_iter != seg_element->iul_mp_map.end();
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
}
{
#if defined(__VA_LIAB_H_) && defined(__AA_COMP_COMP_H_)
for (mp_map_iter = seg_element->va_mp_map.begin();
		mp_map_iter != seg_element->va_mp_map.end();
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
}
{
#if defined(__FA_LIAB_H_) && defined(__AA_COMP_COMP_H_)
for (mp_map_iter = seg_element->fa_mp_map.begin();
		mp_map_iter != seg_element->fa_mp_map.end();
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
}
{
#if defined(__FIA_LIAB_H_) && defined(__AA_COMP_COMP_H_)
for (mp_map_iter = seg_element->fia_mp_map.begin();
		mp_map_iter != seg_element->fia_mp_map.end();
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
		cohort_id = cohort_id;
		liab->sm_fia[mp]->gaap_int_rate = fia_gaap_int_rate;
		cohort_first_issue_period = min(cohort_first_issue_period, -liab->sm_fia[mp]->elapsed_mths);
		cohort_last_issue_period = max(cohort_last_issue_period, -liab->sm_fia[mp]->elapsed_mths);
		cohort_max_maturity_period = max(cohort_max_maturity_period, liab->sm_fia[mp]->maturity_period);
		cohort_mp_count += 1;
		fia_mp_map[mp] = mp;			
		}
	}
#endif
}
{
#if defined(__EPL_LIAB_H_) && defined(__AA_COMP_COMP_H_)
if (seg_element->epl_mp_map.size())
	{
	// Determine cohort_first_issue_period
	// Find earliest cohort issue period from cohort data
	int cohort_first_issue_yr = 9999;
	vector<string> issue_yrs;
	cohort_id = cohort_id;
	split_string_usl(cohort_issue_yrs.c_str(), issue_yrs, ",");

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
				month_number_from_date(cohort_first_issue_yr, 1)
				- month_number_from_date(proj_start_yr, proj_start_mth));
		}
	}

for (mp_map_iter = seg_element->epl_mp_map.begin();
		mp_map_iter != seg_element->epl_mp_map.end();
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
}
// Set cohort id as group name, crucial as this will be used as the key id to retrive values from the output files
if (cohort_mp_count > 0 
	|| (seg_element->sfas97rd_seriatim_cohort_used.size() > cohort_col 
		&& seg_element->sfas97rd_seriatim_cohort_used[cohort_col]))
	{	
	if (reins_flag)
		reins_defn = "Ceded";
	else
		reins_defn = "Gross";
			
	xstring cohort_group = cohort_id + "|" + reins_defn;
	this->setGroup(cohort_group);

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

if (model_name == SFAS97RD)
	{
	if (!reins_flag)
		{
		if (fabs(seg_element->gaap_liab_net(t - 1) - seg_element->pol_loan(t - 1)) < aggregate_amount_threshold)
			return NO_AVG;

		return (seg_element->gaap_inv_inc_res(t)
				+ seg_element->gaap_inv_inc_cap(t))
				* (liab_net(t - 1) - pol_loan(t - 1))
				  / (seg_element->gaap_liab_net(t - 1) - seg_element->pol_loan(t - 1))
				+ pol_loan_inc(t);
		}
	else if (reins_flag)
		{
		if (fabs(seg_element->reins_gaap_liab_net(t - 1)) < aggregate_amount_threshold)
			return NO_AVG;

		return seg_element->reins_gaap_inv_inc_res(t)
			   * liab_net(t - 1) / seg_element->reins_gaap_liab_net(t - 1);
		}
	}

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	if (!reins_flag)
		return ul->gaap_inv_inc_res(t)
		       + ul->gaap_inv_inc_cap(t);
	else if (ul->coins_flag)
		return ul->reins_gaap_inv_inc_res(t);
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	if (!reins_flag)
		return iul->gaap_inv_inc_res(t)
		       + iul->gaap_inv_inc_cap(t);
	else if (iul->coins_flag)
		return iul->reins_gaap_inv_inc_res(t);
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	if (!reins_flag)
		return vul->gaap_inv_inc_res(t)
		       + vul->gaap_inv_inc_cap(t);
	else if (vul->coins_flag)
		return vul->reins_gaap_inv_inc_res(t);
	}
#endif
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	if (!reins_flag)
		return fa->gaap_inv_inc_res(t)
		       + fa->gaap_inv_inc_cap(t);
	else if (fa->reins_flag)
		return fa->reins_gaap_inv_inc_res(t);
	}
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!reins_flag)
		return va->gaap_inv_inc_res(t)
		       + va->gaap_inv_inc_cap(t);
	else if (va->reins_flag)
		return va->reins_gaap_inv_inc_res(t);
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	if (!reins_flag)
		return fia->gaap_inv_inc_res(t)
		       + fia->gaap_inv_inc_cap(t);
	else if (fia->reins_flag)
		return fia->reins_gaap_inv_inc_res(t);
	}
#endif
}

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

if (model_name == SFAS97RD)
	return sum_over_gaap("inv_inc_fund", t);

{	
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
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
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
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
}
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

if (sfas97rd_valn_flag)
	{
	if (policies_inf_sum(t) < rate_ratio_threshold)//DAC is capitalized and amortized as incurred, so k_dac can change in between valuation dates
		return NO_AVG;

	double dac_prev = dac_acq_exp(t - 1)
					  + capzd_acq_exp(t);

	return dac_prev / policies_inf_sum(t);
	}

// (valn_period >= 0 && !valn_flag)
return k_capzd_acq_exp_sch(t);


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
if (t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

return gaap_schedule[K_CAPZD_ACQ_EXP][t];

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

if (sfas97rd_valn_flag)
	{
	if (policies_inf_sum(t) < rate_ratio_threshold)//DAC is capitalized and amortized as incurred, so k_dac can change in between valuation dates
		return NO_AVG;

	double dac_prev = dac_comm(t - 1)
						+ capzd_comm_bom(t)
						+ capzd_comm_eom(t);

	return dac_prev / policies_inf_sum(t);
	}

// (valn_period >= 0 && !valn_flag)
return k_capzd_comm_sch(t);

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
if (t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

return gaap_schedule[K_CAPZD_COMM][t];

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

if (sfas97rd_valn_flag)
	{
	if (policies_inf_sum(t) < rate_ratio_threshold)//DAC is capitalized and amortized as incurred, so k_dac can change in between valuation dates
		return NO_AVG;

	double dac_prev = dac_prem_bonus(t - 1)
					  + capzd_prem_bonus(t);

	return dac_prev / policies_inf_sum(t);
	}

// (valn_period >= 0 && !valn_flag)
return k_capzd_prem_bonus_sch(t);

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
if (t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

return gaap_schedule[K_CAPZD_PREM_BONUS][t];

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

if (sfas97rd_valn_flag)
	{
	if (policies_inf_sum(t) < rate_ratio_threshold)//DAC is capitalized and amortized as incurred, so k_dac can change in between valuation dates
		return NO_AVG;

	double dac_prev = dac_reins_yrt_asset(t - 1)
						+ capzd_reins_yrt_cost(t);

	return dac_prev / policies_inf_sum(t);
	}

// (valn_period >= 0 && !valn_flag)
return k_reins_yrt_cost_sch(t);

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
if (t < start_period || t > final_period)
	return NO_AVG;
	
if (valn_flag)
	return NO_AVG;

if (!cohort_reins_yrt_indicator)
	return NO_AVG;

return gaap_schedule[K_REINS_YRT_COST][t];

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
if (t < start_period || t > final_period)
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

if (sfas97rd_valn_flag)
	{
	if (policies_inf_sum(t) < rate_ratio_threshold)//DAC is capitalized and amortized as incurred, so k_dac can change in between valuation dates
		return NO_AVG;

	double dac_prev = unearn_rev_liab(t - 1)
						+ deferred_loads(t);

	return dac_prev / policies_inf_sum(t);
	}

// (valn_period >= 0 && !valn_flag)
return k_unearn_rev_liab_sch(t);

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
if (t < start_period || t > final_period)
	return NO_AVG;

if (valn_flag)
	return NO_AVG;

return gaap_schedule[K_UNEARN_REV_LIAB][t];

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
	   + mrb_liab(t)
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

if (model_name == SFAS97RD)
	return sum_over_gaap("loads", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	if (!reins_flag)
		return fa->admin_fee(t) + fa->load_prem(t);
	
	if (reins_flag && fa->reins_flag)
		return (fa->admin_fee(t) + fa->load_prem(t)) * fa->reins_pct;

	return NO_AVG;
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	if (!reins_flag)
		return fia->admin_fee(t);
	
	if (reins_flag && fia->reins_flag)
		return fia->admin_fee(t) * fia->reins_pct;

	return NO_AVG;
	}
#endif
}
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

if (model_name == SFAS97RD)
	return sum_over_gaap("loc_cost", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	if (!reins_flag)
		return ul->loc_cost(t);

	return 0.0;
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	if (!reins_flag)
		return iul->loc_cost(t);

	return 0.0;
	}
#endif
}

return NO_AVG;

}

//@@ END

//@@ START - maint_exp_bom
// Maintenance Expenses Beginning of Month                                                                                             
// Column:MAINT_EXP_BOM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(106,"maint_exp_bom",t);
}



//^^^

#line 1 "maint_exp_bom.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (model_name == SFAS97RD)
	return sum_over_gaap("maint_exp_bom", t);

{	
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return ul->maint_exp_bom(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return vul->maint_exp_bom(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return iul->maint_exp_bom(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fa->maint_exp_bom(t);
	
	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fa->maint_exp_bom(t) * fa->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fia->maint_exp_bom(t);
	
	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fia->maint_exp_bom(t) * fia->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
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

if (model_name == SFAS97RD)
	return sum_over_gaap("maint_exp_eom", t);
	
{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
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
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
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
}	
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
	return rebase_value(108,"modco_liab",t);
}



//^^^

#line 1 "modco_liab.SFAS97RD_GAAP.for"
if (!reins_flag || t < start_period || t > final_period)
	return NO_AVG;

if (model_name == SFAS97RD)
	return sum_over_gaap("modco_liab", t);

{	
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	return ul->sum_over_reinsurance("stat_res_mp_prelim", t, MODIFIED_COINSURANCE)
		   + ul->sum_over_reinsurance("stat_unearn_prem_res", t, MODIFIED_COINSURANCE);
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	return vul->sum_over_reinsurance("stat_res_mp_prelim", t, MODIFIED_COINSURANCE)
		   + vul->sum_over_reinsurance("stat_unearn_prem_res", t, MODIFIED_COINSURANCE);
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	return iul->sum_over_reinsurance("stat_res_mp_prelim", t, MODIFIED_COINSURANCE)
		   + iul->sum_over_reinsurance("stat_unearn_prem_res", t, MODIFIED_COINSURANCE);
	}
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (va->reins_flag)
		return va->reins_stat_res(t);
	
	return NO_AVG;
	}
#endif
}

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
	return rebase_value(110,"modco_res_adj",t);
}



//^^^

#line 1 "modco_res_adj.SFAS97RD_GAAP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (model_name == SFAS97RD)
	return sum_over_gaap("modco_res_adj", t);
	
{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	if (ul->modco_flag)
		return ul->reins_modco_res_adj(t);
		
	return NO_AVG;
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	if (vul->modco_flag)
		return vul->reins_modco_res_adj(t);
		
	return NO_AVG;
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	if (iul->modco_flag)
		return iul->reins_modco_res_adj(t);
		
	return NO_AVG;
	}
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (va->reins_flag)
		return va->reins_modco_res_adj(t);
	
	return NO_AVG;
	}
#endif
}

return NO_AVG;

}

//@@ END

//@@ START - mrb_gmab_liab
// MRB GMAB Liability                                                                                             
// Column:MRB_GMAB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_mrb_gmab_liab(int t) {
//^^^



//^^^

#line 1 "mrb_gmab_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (valn_flag) // No MRB guaranteed benefit value included in SFAS97RD valuations
	return NO_AVG;

if (t == start_period && valn_period != 0)
	return init_mrb_gmab_liab;

if (model_name == SFAS97RD)
	return sum_over_gaap("mrb_gmab_liab", t);

{
#if defined(__MRB_GAAP_H_)
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!va->sm_va_mrb.size())
		return NO_AVG;

	return va->sm_va_mrb[getElementNumber()]->gmab_liab(t);
	}	
#endif
}
#endif
}

return NO_AVG;

}

//@@ END

//@@ START - mrb_gmdb_liab
// MRB GMDB Liability                                                                                             
// Column:MRB_GMDB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_mrb_gmdb_liab(int t) {
//^^^



//^^^

#line 1 "mrb_gmdb_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period) // No MRB guaranteed benefit value included in SFAS97RD valuations
	return NO_AVG;

if (valn_flag)
	return NO_AVG;

if (t == start_period && valn_period != 0)
	return init_mrb_gmdb_liab;

if (model_name == SFAS97RD)
	return sum_over_gaap("mrb_gmdb_liab", t);

{
#if defined(__MRB_GAAP_H_)
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!va->sm_va_mrb.size())
		return NO_AVG;

	return va->sm_va_mrb[getElementNumber()]->gmdb_liab(t);
	}
#endif
}
#endif
}

return NO_AVG;

}

//@@ END

//@@ START - mrb_gmib_liab
// MRB GMIB Liability                                                                                             
// Column:MRB_GMIB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_mrb_gmib_liab(int t) {
//^^^



//^^^

#line 1 "mrb_gmib_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (valn_flag) // No MRB guaranteed benefit value included in SFAS97RD valuations
	return NO_AVG;

if (t == start_period && valn_period != 0)
	return init_mrb_gmib_liab;

if (model_name == SFAS97RD)
	return sum_over_gaap("mrb_gmib_liab", t);

{
#if defined(__MRB_GAAP_H_)
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!va->sm_va_mrb.size())
		return NO_AVG;

	return va->sm_va_mrb[getElementNumber()]->gmib_liab(t);
	}
#endif
}
#endif
}

return NO_AVG;

}

//@@ END

//@@ START - mrb_gmwb_liab
// MRB GMWB Liability                                                                                             
// Column:MRB_GMWB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_mrb_gmwb_liab(int t) {
//^^^



//^^^

#line 1 "mrb_gmwb_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (valn_flag) // No MRB guaranteed benefit value included in SFAS97RD valuations
	return NO_AVG;

if (t == start_period && valn_period != 0)
	return init_mrb_gmwb_liab;

if (model_name == SFAS97RD)
	return sum_over_gaap("mrb_gmwb_liab", t);

{
#if defined(__MRB_GAAP_H_)
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!va->sm_va_mrb.size())
		return NO_AVG;

	return va->sm_va_mrb[getElementNumber()]->gmwb_liab(t);
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	if (!fia->sm_fia_mrb.size())
		return NO_AVG;

	return fia->sm_fia_mrb[getElementNumber()]->gmwb_liab(t);
	}
#endif
}
#endif
}

return NO_AVG;

}

//@@ END

//@@ START - mrb_liab
// Market Risk Benefits Liability                                                                                             
// Column:MRB_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_mrb_liab(int t) {
//^^^



//^^^

#line 1 "mrb_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return mrb_gmab_liab(t)
       + mrb_gmib_liab(t)
       + mrb_gmwb_liab(t)
	   + mrb_gmdb_liab(t);

}

//@@ END

//@@ START - mrb_liab_incr
// Market Risk Benefits Liability Increase                                                                                             
// Column:MRB_LIAB_INCR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_mrb_liab_incr(int t) {
//^^^



//^^^

#line 1 "mrb_liab_incr.SFAS97RD_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return mrb_liab(t)
       - mrb_liab(t - 1);

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
	
if (model_name == SFAS97RD)
	return sum_over_gaap("persist_bon_ref", t);
	
{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}

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

if (model_name == SFAS97RD)
	return sum_over_gaap("pol_loan", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	if (!reins_flag)
		return ul->pol_loan(t);

	// policy loans are not reinsured
	return 0.0; 
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	if (!reins_flag)
		return iul->pol_loan(t);

	// policy loans are not reinsured
	return 0.0; 
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	if (!reins_flag)
		return vul->pol_loan(t);

	// policy loans are not reinsured
	return 0.0; 
	}
#endif
}

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

if (model_name == SFAS97RD)
	return sum_over_gaap("pol_loan_inc", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	if (!reins_flag)
		return ul->pol_loan_inc(t);	

	return NO_AVG;
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	if (!reins_flag)
		return iul->pol_loan_inc(t);	

	return NO_AVG;
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	if (!reins_flag)
		return vul->pol_loan_inc(t);	

	return NO_AVG;
	}
#endif
}

return 0.0;

}

//@@ END

//@@ START - policies_inf
// Policies In Force End of Month                                                                                             
// Column:POLICIES_INF
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_policies_inf(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(120,"policies_inf",t);
}



//^^^

#line 1 "policies_inf.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (model_name == SFAS97RD)
	return sum_over_gaap("policies_inf", t);

{	
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	return ul->policies_inf(t);
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	return vul->policies_inf(t);
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	return iul->policies_inf(t);
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	return va->policies_inf(t);
#endif
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	return fa->policies_inf(t);
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	return fia->policies_inf(t);
#endif
}
return NO_AVG;

}

//@@ END

//@@ START - policies_inf_sch
// Policies In Force Schedule                                                                                             
// Column:POLICIES_INF_SCH
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_policies_inf_sch(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(121,"policies_inf_sch",t);
}



//^^^

#line 1 "policies_inf_sch.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (valn_flag)
	return NO_AVG;

return gaap_schedule[POLICIES_INF][t];

}

//@@ END

//@@ START - policies_inf_sum
// Policies In Force total value over the life of cohort                                                                                             
// Column:POLICIES_INF_SUM
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_policies_inf_sum(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(122,"policies_inf_sum",t);
}



//^^^

#line 1 "policies_inf_sum.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

policies_inf_sch(t);//Force call for DAC Adjustment calculation

return policies_inf(t)
	   + policies_inf_sum(t + 1);

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

if (model_name == SFAS97RD)
	return sum_over_gaap("prem_bonus", t);

{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return va->prem_bonus(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return va->prem_bonus(t) * va->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fa->prem_bonus(t);
	
	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fa->prem_bonus(t) * fa->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fia->prem_bonus(t);
	
	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fia->prem_bonus(t) * fia->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}	
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

if (model_name == SFAS97RD)
	return sum_over_gaap("prem_tax", t);
	
{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return ul->prem_tax(t);

    if (reins_flag && ul->reins_flag && ul->coins_flag) 
		return ul->sum_over_reinsurance("prem_tax", t, COINSURANCE)
			   + ul->sum_over_reinsurance("prem_tax", t, MODIFIED_COINSURANCE);

	return 0.0;	
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return vul->prem_tax(t);

    if (reins_flag && vul->reins_flag && vul->coins_flag) 
		return vul->sum_over_reinsurance("prem_tax", t, COINSURANCE)
			   + vul->sum_over_reinsurance("prem_tax", t, MODIFIED_COINSURANCE);

	return 0.0;	
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return iul->prem_tax(t);

    if (reins_flag && iul->reins_flag && iul->coins_flag) 
		return iul->sum_over_reinsurance("prem_tax", t, COINSURANCE)
			   + iul->sum_over_reinsurance("prem_tax", t, MODIFIED_COINSURANCE);

	return 0.0;	
	}
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fa->prem_tax(t);
	
	if (reins_flag && fa->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fa->prem_tax(t) * fa->reins_pct;
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return fia->prem_tax(t);
	
	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured via Coinsurance	
		return fia->prem_tax(t) * fia->reins_pct;
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif	
}	
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
	return rebase_value(125,"refund",t);
}



//^^^

#line 1 "refund.SFAS97RD_GAAP.for"
if (!reins_flag || t <= start_period || t > final_period)
	return NO_AVG;

if (model_name == SFAS97RD)
	return sum_over_gaap("refund", t);
	
{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	if (ul->reins_flag)
		return ul->sum_over_reinsurance("ref", t, COINSURANCE)
		       + ul->sum_over_reinsurance("ref", t, MODIFIED_COINSURANCE)
			   + ul->sum_over_reinsurance("prem_unearned_ref", t, COINSURANCE)
			   + ul->sum_over_reinsurance("prem_unearned_ref", t, MODIFIED_COINSURANCE);
		
	return NO_AVG;
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	if (vul->reins_flag)
		return  vul->sum_over_reinsurance("ref", t, MODIFIED_COINSURANCE)
			   + vul->sum_over_reinsurance("prem_unearned_ref", t, MODIFIED_COINSURANCE);
		
	return NO_AVG;
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	if (iul->reins_flag)
		return iul->sum_over_reinsurance("ref", t, COINSURANCE)
		       + iul->sum_over_reinsurance("ref", t, MODIFIED_COINSURANCE)
			   + iul->sum_over_reinsurance("prem_unearned_ref", t, COINSURANCE)
			   + iul->sum_over_reinsurance("prem_unearned_ref", t, MODIFIED_COINSURANCE);
		
	return NO_AVG;
	}
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	{
	if (va->reins_flag)
		return va->reins_ref(t);
	
	return NO_AVG;
	}
#endif
}

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
if (t <= start_period || t > final_period)
	return NO_AVG;

if (reins_flag)
	return NO_AVG;

if (model_name == SFAS97RD)
	return sum_over_gaap("reins_yrt_cost", t);

{	
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}

return NO_AVG;

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

if (model_name == SFAS97RD)
	return sum_over_gaap("rider_charges", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}

return NO_AVG;

}

//@@ END

//@@ START - sfas133_liab
// SFAS 133 Liability (FIA and IUL)                                                                                             
// Column:SFAS133_LIAB
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_liab(int t) {
//^^^



//^^^

#line 1 "sfas133_liab.SFAS97RD_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return embed_deriv_val(t)
       + host_contract_val(t);

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

if (model_name == SFAS97RD)
	return sum_over_gaap("sop031_assess", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}

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

{
#if defined(__UL_LIAB_H_) || defined(__VUL_LIAB_H_) || defined(__IUL_LIAB_H_)	
if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (model_name == SFAS97RD)
			{
			double assess_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				double assess = sop031_assess_history(tt);

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
	
double url_amortzn = sop031_unearn_rev_liab_incr(t);

return sop031_assess_accum(t - 1) 
       * (1.0 + gaap_amortzn_int_rate(t))
       + sop031_assess(t) - url_amortzn;
#endif
}

return NO_AVG;

}

//@@ END

//@@ START - sop031_assess_history
// Cohort History SOP 03-1 Assessments                                                                                             
// Column:SOP031_ASSESS_HISTORY
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_assess_history(int t) {
//^^^



//^^^

#line 1 "sop031_assess_history.SFAS97RD_GAAP.for"
if (t > start_period)
	return NO_AVG;

cohort_id = cohort_id;

return cohort_history_sop031_assess;

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
		if (model_name == SFAS97RD)
			{
			double egp_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				double egp = agp_history(tt);
				
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

{	
#if defined(__VUL_LIAB_H_)	
if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (model_name == SFAS97RD)
			{
			double db_ben_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				double db_ben = sop031_gmdb_benefits_history(tt);
				
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

#endif
}

return NO_AVG;

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

//@@ START - sop031_gmdb_benefits_history
// Cohort History SOP03-1 GMDB Benefits                                                                                             
// Column:SOP031_GMDB_BENEFITS_HISTORY
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_benefits_history(int t) {
//^^^



//^^^

#line 1 "sop031_gmdb_benefits_history.SFAS97RD_GAAP.for"
if (t > start_period)
	return NO_AVG;

cohort_id = cohort_id;

return cohort_history_sop031_gmdb_benefits;

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
if (t < start_period || t > final_period)
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
	if (model_name == SFAS97RD)
		return sum_over_gaap("sop031_pbr", t);
	
	{
	#if defined(__UL_LIAB_H_)
	if (model_name == UL_SFAS97RD)
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
	}
	{
	#if defined(__VUL_LIAB_H_)
	if (model_name == VUL_SFAS97RD)
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
	}

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
if (t < start_period || t > pbr_final_period)
	return NO_AVG;
	
if (sop031_ul_vul_iul_defn == NO)
	return NO_AVG;
	
if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;
	
if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (model_name == SFAS97RD)
			{
			double pbr_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				double pbr = sop031_pbr_benefits_history(tt);
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

//@@ START - sop031_pbr_benefits_history
// Cohort History SOP 03-1 Persistency Bonus/Refund Benefits                                                                                             
// Column:SOP031_PBR_BENEFITS_HISTORY
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_benefits_history(int t) {
//^^^



//^^^

#line 1 "sop031_pbr_benefits_history.SFAS97RD_GAAP.for"
if (t > start_period)
	return NO_AVG;

cohort_id = cohort_id;

return cohort_history_sop031_pbr_benefits;

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
if (t < start_period || t > pbr_final_period)
	return NO_AVG;
	
if (sop031_ul_vul_iul_defn == NO)
	return NO_AVG;

if (sfas97rd_valn_flag)
	{
	if (model_name == SFAS97RD)
		return max(0.0, sum_over_gaap("sop031_pbr_fund_val", t));

	{
	#if defined(__UL_LIAB_H_)
	if (model_name == UL_SFAS97RD)
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
	}
	{
	#if defined(__VUL_LIAB_H_)
	if (model_name == VUL_SFAS97RD)
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
	}

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
		if (model_name == SFAS97RD)
			{
			double fvf_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				double fvf = sop031_pbr_fund_val_history(tt);
				
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

//@@ START - sop031_pbr_fund_val_history
// Cohort History SOP 03-1 Persistency Bonus/Refund Fund Value                                                                                             
// Column:SOP031_PBR_FUND_VAL_HISTORY
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_fund_val_history(int t) {
//^^^



//^^^

#line 1 "sop031_pbr_fund_val_history.SFAS97RD_GAAP.for"
if (t > start_period)
	return NO_AVG;

cohort_id = cohort_id;

return cohort_history_sop031_pbr_fund_val;

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
if (t < start_period || t > pbr_final_period)
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
if (t < start_period || t > pbr_final_period)
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
if (t < start_period || t >= pbr_final_period)
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
	
if (model_name == SFAS97RD)
	return NO_AVG;

{	
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
return NO_AVG;

}

//@@ END

//@@ START - sop031_sg_benefits_history
// Cohort History SOP 03-1 ULSG Benefits                                                                                             
// Column:SOP031_SG_BENEFITS_HISTORY
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_sg_benefits_history(int t) {
//^^^



//^^^

#line 1 "sop031_sg_benefits_history.SFAS97RD_GAAP.for"
if (t > start_period)
	return NO_AVG;

cohort_id = cohort_id;

return cohort_history_sop031_sg_benefits;

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
if (t < start_period || t > final_period)
	return NO_AVG;

if (sop031_ul_vul_iul_defn == NO)
	return NO_AVG;

if (xint(cal_yr(t)) < cohort_yr)
	return NO_AVG;

if (t == start_period)
	{
	if (valn_period == 0)
		{
		if (model_name == SFAS97RD)
			{
			double sg_ben_accum = 0.0;
			
			for (int tt = cohort_first_issue_period + 1; tt <= 0; tt++)
				{
				double sg_ben = sop031_sg_benefits_history(tt);
				
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
if (t < start_period || t >= final_period)
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
if (t < start_period || t > final_period)
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
if (t < start_period || t > final_period)
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
#if 0 // START_HEADER
#define __SFAS97RD_GAAP_H_
#endif // END_HEADER

#if 0 // START_EXTERNS
deptaskinput sop031_valn_input;
deptaskinput sfas97rd_valn_input;
sowfoutput sfas97rd_state_of_world_financial_output;
sowfinput sfas97rd_state_of_world_financial_input;
sowfmap sfas97rd_state_of_world_financial_input_pos;
sowfmapiter sfas97rd_state_of_world_financial_input_pos_iter;
const int ASSESS_SOP = 0;
const int DB_BEN_SOP = 1;
const int SG_BEN_SOP = 2;
const int DTH_CLAIM_COST = 3;
const int SOP_SIZE = 4;
const int EGP = 0;
const int INT_RATE = 1;
const int SOP031_PBR_FV = 2;
const int SOP031_PBR = 3;
const int DAC_ACQ_EXP = 4;
const int DAC_COMM = 5;
const int DAC_PREM_BONUS = 6;
const int DAC_REINS_YRT_ASSET = 7;
const int EMBED_DERIV_VAL = 8;
const int K_CAPZD_ACQ_EXP = 9;
const int K_CAPZD_COMM = 10;
const int K_CAPZD_PREM_BONUS = 11;
const int K_REINS_YRT_COST = 12;
const int K_SOP031_GMDB_BEN_BR = 13;
const int K_SOP031_PBR = 14;
const int K_SOP031_ULSG_BEN_BR = 15;
const int K_SOP031_UNEARN_REV_LIAB = 16;
const int K_UNEARN_REV_LIAB = 17;
const int SOP031_GMDB_BR = 18;
const int SOP031_PBR_LIAB = 19;
const int SOP031_ULSG_BR = 20;
const int UNEARN_REV_LIAB = 21;
const int POLICIES_INF = 22;
const int GAAP_SCHEDULE_SIZE = 23;
#endif // END_EXTERNS

#if 0 // START_CLASS
map <int, long, less <int> > ul_mp_map;
map <int, long, less <int> > vul_mp_map;
map <int, long, less <int> > iul_mp_map;
map <int, long, less <int> > va_mp_map;
map <int, long, less <int> > fa_mp_map;
map <int, long, less <int> > fia_mp_map;
map <int, long, less <int> > epl_mp_map;
xstring reins_defn;
int cohort_reins_indicator;
int cohort_reins_yrt_indicator;
int cohort_first_issue_period;
int cohort_last_issue_period;
int cohort_max_maturity_period;
SmartArray <SmartArray <double> > sop031_array;
SmartArray <SmartArray <double> > gaap_schedule;
double init_dac_acq_exp;
double init_dac_acq_exp_sch;
double init_dac_comm;
double init_dac_comm_sch;
double init_dac_prem_bonus;
double init_dac_prem_bonus_sch;
double init_egp_accum;
double init_sop031_assess_accum;
double init_sop031_gmdb_ben_accum;
double init_sop031_pbr_accum;
double init_deferred_loads_accum;
double init_unearn_rev_liab;
double init_unearn_rev_liab_sch;
double init_dac_reins_yrt_asset;
double init_dac_reins_yrt_asset_sch;
double init_sop031_pbr_fund_val_accum;
double init_embed_deriv_val;
double init_mrb_gmab_liab;
double init_mrb_gmib_liab;
double init_mrb_gmwb_liab;
double init_mrb_gmdb_liab;
double init_sop031_ulsg_ben_accum;
double init_sop031_gmdb_br;
double init_sop031_pbr_liab;
double init_sop031_ulsg_br;
double init_policies_inf_sch;

#if defined(__AA_COMP_COMP_H_)
RATES_ECONOMY /*modelobject_name: RATES*/ *rates_ptr;
#else
RATES_ECONOMY /*modelobject_name: FIA_RATES*/ *rates_ptr;
#endif

SEG_COMP * seg_element;

#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
cohort_reins_indicator = 0;
cohort_reins_yrt_indicator = 0;
cohort_first_issue_period = 0;
cohort_last_issue_period = -9999;
cohort_max_maturity_period = -9999;
init_dac_acq_exp = 0.0;
init_dac_acq_exp_sch = 0.0;
init_dac_comm = 0.0;
init_dac_comm_sch = 0.0;
init_dac_prem_bonus = 0.0;
init_dac_prem_bonus_sch = 0.0;
init_egp_accum = 0.0;
init_sop031_assess_accum = 0.0;
init_sop031_gmdb_ben_accum = 0.0;
init_sop031_pbr_accum = 0.0;
init_deferred_loads_accum = 0.0;
init_unearn_rev_liab = 0.0;
init_unearn_rev_liab_sch = 0.0;
init_dac_reins_yrt_asset = 0.0;
init_dac_reins_yrt_asset_sch = 0.0;
init_sop031_pbr_fund_val_accum = 0.0;
init_embed_deriv_val = 0.0;
init_mrb_gmab_liab = 0.0;
init_mrb_gmib_liab = 0.0;
init_mrb_gmwb_liab = 0.0;
init_mrb_gmdb_liab = 0.0;
init_sop031_ulsg_ben_accum = 0.0;
init_sop031_gmdb_br = 0.0;
init_sop031_pbr_liab = 0.0;
init_sop031_ulsg_br = 0.0;
init_policies_inf_sch = 0.0;
#endif // END_CONSTRUCTOR

#if 0 // START_TERMINATOR
sfas97rd_state_of_world_financial_output.close();
#endif // END_TERMINATOR

if (getElementNumber() == 0)
	cohort_reins_defn = GROSS;
else
	cohort_reins_defn = CEDED;

{
#if defined (__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined (__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
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
}
{
#if defined (__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
{
#if defined (__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
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
}
{
#if defined (__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
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
}
{
#if defined (__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
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
}
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

if (model_name == SFAS97RD)
	return sum_over_gaap("stat_res_rider", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return ul->stat_res_rider_mp(t) + ul->stat_unearn_prem_res_rider(t);

	return 0.0;
	}
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return iul->stat_res_rider_mp(t) + iul->stat_unearn_prem_res_rider(t);

	return 0.0;
	}
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	{
	if (!reins_flag) //Gross
		return vul->stat_res_rider_mp(t) + vul->stat_unearn_prem_res_rider(t);

	return 0.0;
	}
#endif
}

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
if (t <= start_period || t > final_period)
	return NO_AVG;

if (sop031_ul_vul_iul_defn == NO)
	return NO_AVG;

if (model_name == SFAS97RD)
	return sum_over_gaap("ulsg_ben", t);

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
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
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
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
}
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
		{
		if (valn_period == 0)
			{
			if (model_name == SFAS97RD)
				{
				cohort_id = cohort_id;
				return cohort_history_unearn_rev_liab;
				}

			return 0.0;//  No History for cell pricing at issue period
			}

		return init_unearn_rev_liab;
		}	
	
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
	 	   - unearn_rev_liab_amortzn(t);

return unearn_rev_liab(t - 1) 
	   + deferred_loads(t)
	   - unearn_rev_liab_amortzn(t);

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

return  k_unearn_rev_liab(t) * policies_inf(t);

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
if (t < start_period || t > final_period)
	return NO_AVG;

if (valn_flag)
	return NO_AVG;

return gaap_schedule[UNEARN_REV_LIAB][t];

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
{
#if defined(__UL_LIAB_H_)
if (model_name == SFAS97RD || model_name == UL_SFAS97RD)
	return ul->maturity_period_gmp;
#endif	
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == SFAS97RD || model_name == VUL_SFAS97RD)
	return vul->maturity_period_gmp;
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == SFAS97RD || model_name == IUL_SFAS97RD)
	return iul->maturity_period_gmp;
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == SFAS97RD || model_name == VA_SFAS97RD)
	return va->maturity_period;
#endif	
}
{
#if defined(__FA_LIAB_H_)
if (model_name == SFAS97RD || model_name == FA_SFAS97RD)
	return fa->maturity_period;
#endif	
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == SFAS97RD || model_name == FIA_SFAS97RD)
	return fia->maturity_period;
#endif
}

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
	{
	cohort_id = cohort_id;

	return cohort_gaap_int_rate_gross;
	}

cohort_id = cohort_id;

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

//@@ START - hedge_alloc_factor
// Hedge Allocation Factor                                                                                             
// Calculated Variable:HEDGE_ALLOC_FACTOR
//========================================================
double SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_alloc_factor() {
//^^^


#line 1 "hedge_alloc_factor.SFAS97RD_GAAP.for"
{
#if defined(__MRB_GAAP_H_) && defined(__VA_LIAB_H_)
if (model_name == SFAS97RD)
	{
	double pv_claims_total = 0.0;
	double pv_claims_cohort = 0.0;
	StrEnum::EnumValue sum_over_type = GROSS;

// RD Need to fix this for mrb redesign
//	if (!seg->sm_mrb.size())
//		return 0.0;

	if (reins_flag)
		sum_over_type = CEDED;	

	pv_claims_total = 1.0;
//	= seg->sum_over_mrb("pv_gmab_claim", 0, sum_over_type)
//	  + seg->sum_over_mrb("pv_gmib_claim", 0, sum_over_type)
//	  + seg->sum_over_mrb("pv_gmwb_claim", 0, sum_over_type);

	if (fabs(pv_claims_total) < model_point_amount_threshold)
		return 0.0;

	pv_claims_cohort = 0.0;
//	= seg->sm_mrb[getElementNumber(0)][getElementNumber(1)]->pv_gmab_claim(0)
//	  + seg->sm_mrb[getElementNumber(0)][getElementNumber(1)]->pv_gmib_claim(0)
//	  + seg->sm_mrb[getElementNumber(0)][getElementNumber(1)]->pv_gmwb_claim(0);

	return pv_claims_cohort / pv_claims_total;
	}

{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	return 1.0;
#endif
}
#endif
}

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
{
#if defined(__FIA_LIAB_H_)
if (model_name == SFAS97RD || model_name == FIA_SFAS97RD)
	{
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
	}
#endif
}
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
if (model_name == SFAS97RD)
	{	
	map <int, long, less <int> >::iterator mp_map_iter;

	{
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
	}
	{
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
	}
	{
	#if defined(__IUL_LIAB_H_)
	return 0;
	#endif
	}
	}

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	return ul->sm_ul_ifund_curr->persist_bon_ref_last_period;
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	return vul->sm_vul_ifund_curr->persist_bon_last_period;
#endif
}
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
{
#if defined(__UL_LIAB_H_)
if (model_name == SFAS97RD || model_name == UL_SFAS97RD)
	return ul->commencement_period + ul->prem_term * 12;
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == SFAS97RD || model_name == VUL_SFAS97RD)
	return vul->commencement_period + vul->prem_term * 12;
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == SFAS97RD || model_name == IUL_SFAS97RD)
	return iul->commencement_period + iul->prem_term * 12;
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == SFAS97RD || model_name == VA_SFAS97RD)
	return -va->elapsed_mths + va->prem_term * 12;
#endif
}
{
#if defined(__FA_LIAB_H_)
if (model_name == SFAS97RD || model_name == FA_SFAS97RD)
	return -fa->elapsed_mths + fa->prem_term * 12;
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == SFAS97RD || model_name == FIA_SFAS97RD)
	return -fia->elapsed_mths; // single premium
#endif
}

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
return day_number_from_date(proj_start_yr, proj_start_mth, 1);

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
if (model_name == SFAS97RD)
	return 0;

{
#if defined(__UL_LIAB_H_)
if (model_name == UL_SFAS97RD)
	return ul->start_period;
#endif
}
{
#if defined(__VUL_LIAB_H_)
if (model_name == VUL_SFAS97RD)
	return vul->start_period;
#endif
}
{
#if defined(__IUL_LIAB_H_)
if (model_name == IUL_SFAS97RD)
	return iul->start_period;
#endif
}
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_SFAS97RD)
	return va->start_period;
#endif
}
{
#if defined(__FA_LIAB_H_)
if (model_name == FA_SFAS97RD)
	return fa->start_period;
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_SFAS97RD)
	return fia->start_period;
#endif
}
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
return "<*data*>";

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
		
		OutputFileReader ofr;
		sfas97rd_valn_input = ofr.readFile(file_name.getStdStr(), 
										  {"task_loop", "group", "period", "egp" , "gaap_amortzn_int_rate" , "sop031_pbr_fund_val", "sop031_pbr",
										   "dac_acq_exp", "dac_comm", "dac_prem_bonus", "dac_reins_yrt_asset", "embed_deriv_val",
										   "k_capzd_acq_exp", "k_capzd_comm", "k_capzd_prem_bonus", "k_reins_yrt_cost", "k_sop031_gmdb_ben_br", "k_sop031_pbr", "k_sop031_ulsg_ben_br", "k_sop031_unearn_rev_liab",
										   "k_unearn_rev_liab", "sop031_gmdb_br", "sop031_pbr_liab", "sop031_ulsg_br", "unearn_rev_liab", "policies_inf"});

		if (!sfas97rd_valn_input.size())
			{
			throw FatalError("Could not read SFAS97RD valuation file: " 
							  + file_name + " "
							  + "Please check your data.");
			}

		}

	xstring group_name = get_base_group_name(group, true);

	int period = 0;
	int start_row = 0;

	for (int row = 0; row < sfas97rd_valn_input.size(); row++)
        {
		if (!eq(sfas97rd_valn_input[row][1], group_name))
			continue;
		
		if (eq(sfas97rd_valn_input[row][2], ""))//blank period signifies a PV or IRR column
			continue;

		period = atoi(sfas97rd_valn_input[row][2].c_str());
	
		if (period == 0)
			start_row = row;

		if (period < last_proj_period + 1)
			{
			gaap_schedule[EGP][period] = atof(sfas97rd_valn_input[row][3].c_str());
			gaap_schedule[INT_RATE][period] = atof(sfas97rd_valn_input[row][4].c_str());
			gaap_schedule[SOP031_PBR_FV][period] = atof(sfas97rd_valn_input[row][5].c_str());
			gaap_schedule[SOP031_PBR][period] = atof(sfas97rd_valn_input[row][6].c_str());

			gaap_schedule[DAC_ACQ_EXP][period] = atof(sfas97rd_valn_input[row][7].c_str());
			gaap_schedule[DAC_COMM][period] = atof(sfas97rd_valn_input[row][8].c_str());
			gaap_schedule[DAC_PREM_BONUS][period] = atof(sfas97rd_valn_input[row][9].c_str());
			gaap_schedule[DAC_REINS_YRT_ASSET][period] = atof(sfas97rd_valn_input[row][10].c_str());
			gaap_schedule[EMBED_DERIV_VAL][period] = atof(sfas97rd_valn_input[start_row][11].c_str());
			gaap_schedule[K_CAPZD_ACQ_EXP][period] = atof(sfas97rd_valn_input[row][12].c_str());
			gaap_schedule[K_CAPZD_COMM][period] = atof(sfas97rd_valn_input[row][13].c_str());
			gaap_schedule[K_CAPZD_PREM_BONUS][period] = atof(sfas97rd_valn_input[row][14].c_str());
			gaap_schedule[K_REINS_YRT_COST][period] = atof(sfas97rd_valn_input[row][15].c_str());
			gaap_schedule[K_SOP031_GMDB_BEN_BR][period] = atof(sfas97rd_valn_input[start_row][16].c_str());
			gaap_schedule[K_SOP031_PBR][period] = atof(sfas97rd_valn_input[start_row][17].c_str());
			gaap_schedule[K_SOP031_ULSG_BEN_BR][period] = atof(sfas97rd_valn_input[start_row][18].c_str());
			gaap_schedule[K_SOP031_UNEARN_REV_LIAB][period] = atof(sfas97rd_valn_input[start_row][19].c_str());
			gaap_schedule[K_UNEARN_REV_LIAB][period] = atof(sfas97rd_valn_input[row][20].c_str());
			gaap_schedule[SOP031_GMDB_BR][period] = atof(sfas97rd_valn_input[start_row][21].c_str());
			gaap_schedule[SOP031_PBR_LIAB][period] = atof(sfas97rd_valn_input[start_row][22].c_str());
			gaap_schedule[SOP031_ULSG_BR][period] = atof(sfas97rd_valn_input[start_row][23].c_str());
			gaap_schedule[UNEARN_REV_LIAB][period] = atof(sfas97rd_valn_input[row][24].c_str());
			gaap_schedule[POLICIES_INF][period] = atof(sfas97rd_valn_input[row][25].c_str());
			}

        }
	}
}



#line 1 "get_sop031_valn_results.SFAS97RD_GAAP.for"                                                                                   
void SFAS97RD_GAAP::get_sop031_valn_results(void)
{
xstring file_name = xstring(replaceWildcards(sop031_results));

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

	OutputFileReader ofr;
	sop031_valn_input = ofr.readFile(file_name.getStdStr(), {"task_loop", "group", "period", "sop031_assess", "gmdb_ben", "ulsg_ben", "dth_claim_cost"});
											
	if (!sop031_valn_input.size())
		{
		throw FatalError("Could not read SOP03-1 valuation file: " 
			              + file_name + ". "
			              + "Please check your data.");
		}
	}

xstring group_name = get_base_group_name(group, true);

int period = 0;
int task_loop_counter = 0;

for (int row = 0; row < sop031_valn_input.size(); row++)
	{
	if (!eq(sop031_valn_input[row][1], group_name))
		continue;
	
	if (eq(sop031_valn_input[row][2], ""))//blank period signifies a PV or IRR column
		continue;

	period = atoi(sop031_valn_input[row][2].c_str());

	if (period == 0)
		task_loop_counter += 1;

	if (period < cohort_periods)
		{
		sop031_array[ASSESS_SOP][period] += atof(sop031_valn_input[row][3].c_str());
		sop031_array[DB_BEN_SOP][period] += atof(sop031_valn_input[row][4].c_str());
		sop031_array[SG_BEN_SOP][period] += atof(sop031_valn_input[row][5].c_str());
		sop031_array[DTH_CLAIM_COST][period] += atof(sop031_valn_input[row][6].c_str());
		}
	}

int proj_task_loops = task_loop_counter;

for (period = 0; period < cohort_periods; period++)
	{
	sop031_array[ASSESS_SOP][period] /= proj_task_loops;
	sop031_array[DB_BEN_SOP][period] /= proj_task_loops;
	sop031_array[SG_BEN_SOP][period] /= proj_task_loops;
	sop031_array[DTH_CLAIM_COST][period] /= proj_task_loops;		
	}			

// Validate data
double assess_chk = 0.0;
double db_chk = 0.0;
double sg_chk = 0.0;
double dcc_chk = 0.0;

for (period = 0; period < cohort_periods; period++)
	{
	assess_chk += sop031_array[ASSESS_SOP][period];
	db_chk += sop031_array[DB_BEN_SOP][period];
	sg_chk += sop031_array[SG_BEN_SOP][period];
	dcc_chk += sop031_array[DTH_CLAIM_COST][period];
	}

if (final_period > 0
	&& (assess_chk + db_chk + sg_chk + dcc_chk) == 0.0)
	log_screen << "Warning: Cohort " << group_name << " does not have any SOP 03-1 cash flow items assigned to it. "
		        << "Please check SOP 03-1 valuation file: " << file_name << "." << MSG_USER;		
	
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

	OutputFileReader ofr;
	sfas97rd_state_of_world_financial_input = ofr.readFile(state_of_world_financial_file.getStdStr(), 
											  {"group","dac_acq_exp","dac_acq_exp_sch","dac_comm","dac_comm_sch",
											   "dac_prem_bonus","dac_prem_bonus_sch","egp_accum","sop031_assess_accum",
											   "sop031_gmdb_ben_accum","sop031_pbr_accum","deferred_loads_accum",
											   "unearn_rev_liab","unearn_rev_liab_sch","dac_reins_yrt_asset",
											   "dac_reins_yrt_asset_sch","sop031_pbr_fund_val_accum","embed_deriv_val",
											   "mrb_gmab_liab","mrb_gmib_liab","mrb_gmwb_liab","mrb_gmdb_liab",
											   "sop031_ulsg_ben_accum","sop031_gmdb_br","sop031_pbr_liab","sop031_ulsg_br",
											   "policies_inf_sch"});

	if (!sfas97rd_state_of_world_financial_input.size())
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
xstring group_name = get_base_group_name(group, true);
if ((sfas97rd_state_of_world_financial_input_pos_iter 
     = sfas97rd_state_of_world_financial_input_pos.find(group_name)) != sfas97rd_state_of_world_financial_input_pos.end())
	sfas97rd_state_of_world_financial_row = sfas97rd_state_of_world_financial_input_pos_iter->second;

init_dac_acq_exp = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][1].c_str());
init_dac_acq_exp_sch = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][2].c_str());
init_dac_comm = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][3].c_str());
init_dac_comm_sch = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][4].c_str());
init_dac_prem_bonus = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][5].c_str());
init_dac_prem_bonus_sch = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][6].c_str());
init_egp_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][7].c_str());
init_sop031_assess_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][8].c_str());
init_sop031_gmdb_ben_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][9].c_str());
init_sop031_pbr_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][10].c_str());
init_deferred_loads_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][11].c_str());
init_unearn_rev_liab = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][12].c_str());
init_unearn_rev_liab_sch = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][13].c_str());
init_dac_reins_yrt_asset = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][14].c_str());
init_dac_reins_yrt_asset_sch = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][15].c_str());
init_sop031_pbr_fund_val_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][16].c_str());
init_embed_deriv_val = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][17].c_str());
init_mrb_gmab_liab = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][18].c_str());
init_mrb_gmib_liab = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][19].c_str());
init_mrb_gmwb_liab = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][20].c_str());
init_mrb_gmdb_liab = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][21].c_str());
init_sop031_ulsg_ben_accum = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][22].c_str());
init_sop031_gmdb_br = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][23].c_str());
init_sop031_pbr_liab = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][24].c_str());
init_sop031_ulsg_br = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][25].c_str());
init_policies_inf_sch = atof(sfas97rd_state_of_world_financial_input[sfas97rd_state_of_world_financial_row][26].c_str());

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
split_string_usl(cohort_issue_yrs.c_str(), issue_yrs, ",");

cohort_id = cohort;
split_string_usl(cohort_plan_codes.c_str(), plan_codes, ",");

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
double SFAS97RD_GAAP::sum_over_gaap(const xstring &/* CiProxyFormula */colname, const int /* CiProxyTime */ t)
{
double total = 0.0;
int mp = 0;
int colnum = 0;
xstring colname_epl = "";

map <int, long, less <int> >::iterator mp_map_iter;

{
#if defined(__UL_LIAB_H_) && defined(__AA_COMP_COMP_H_)
if (ul_mp_map.size())
	{
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
			
			if (t < liab->sm_ul[mp]->commencement_period
				|| t > liab->sm_ul[mp]->maturity_period)
				continue;

			// Skip new issues commencement period
			if (liab->sm_ul[mp]->commencement_period >= 0
				&& t == liab->sm_ul[mp]->commencement_period)
				continue;

			if (t > liab->sm_ul[mp]->start_period
				&& fabs(liab->sm_ul[mp]->units_inf(t - 1)) < rate_ratio_threshold)
				continue;

			if (!reins_flag) //Gross Run
				total += liab->sm_ul[mp]->sm_ul_sfas97rd[0]->Column(colnum).Value(t);

			else if (reins_flag && liab->sm_ul[mp]->reins_flag && liab->sm_ul[mp]->coins_flag) //Ceded Run && MP Reinsured
				total += liab->sm_ul[mp]->sm_ul_sfas97rd[1]->Column(colnum).Value(t);

			// no sum for ceded Run && MP Not Reinsured
			}		
		}
	}		
#endif
}
{
#if defined(__VUL_LIAB_H_) && defined(__AA_COMP_COMP_H_)
if (vul_mp_map.size())
	{
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
			
			if (t < liab->sm_vul[mp]->commencement_period
				|| t > liab->sm_vul[mp]->maturity_period)
				continue;

			// Skip new issues commencement period
			if (liab->sm_vul[mp]->commencement_period >= 0
				&& t == liab->sm_vul[mp]->commencement_period)
				continue;

			if (t > liab->sm_vul[mp]->start_period
				&& fabs(liab->sm_vul[mp]->units_inf(t - 1)) < rate_ratio_threshold)
				continue;

			if (!reins_flag) //Gross Run
				total += liab->sm_vul[mp]->sm_vul_sfas97rd[0]->Column(colnum).Value(t);

			else if (reins_flag && liab->sm_vul[mp]->reins_flag && liab->sm_vul[mp]->coins_flag) //Ceded Run && MP Reinsured
				total += liab->sm_vul[mp]->sm_vul_sfas97rd[1]->Column(colnum).Value(t);

			// no sum for ceded Run && MP Not Reinsured
			}		
		}
	}		
#endif
}
{
#if defined(__IUL_LIAB_H_) && defined(__AA_COMP_COMP_H_)
if (iul_mp_map.size())
	{
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
			
			if (t < liab->sm_iul[mp]->commencement_period
				|| t > liab->sm_iul[mp]->maturity_period)
				continue;

			// Skip new issues commencement period
			if (liab->sm_iul[mp]->commencement_period >= 0
				&& t == liab->sm_iul[mp]->commencement_period)
				continue;

			if (t > liab->sm_iul[mp]->start_period
				&& fabs(liab->sm_iul[mp]->units_inf(t - 1)) < rate_ratio_threshold)
				continue;

			if (!reins_flag) //Gross Run
				total += liab->sm_iul[mp]->sm_iul_sfas97rd[0]->Column(colnum).Value(t);

			else if (reins_flag && liab->sm_iul[mp]->reins_flag && liab->sm_iul[mp]->coins_flag) //Ceded Run && MP Reinsured
				total += liab->sm_iul[mp]->sm_iul_sfas97rd[1]->Column(colnum).Value(t);

			// no sum for ceded Run && MP Not Reinsured
			}		
		}
	}		
#endif
}
{
#if defined(__VA_LIAB_H_) && defined(__AA_COMP_COMP_H_)
if (va_mp_map.size())
	{
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

			if (t < liab->sm_va[mp]->commencement_period
				|| t > liab->sm_va[mp]->maturity_period)
				continue;

			// Skip new issue commencement period
			if (liab->sm_va[mp]->elapsed_mths <= 0
				&& t == liab->sm_va[mp]->commencement_period)
				continue;

			if (t != liab->sm_va[mp]->commencement_period
				&& fabs(liab->sm_va[mp]->policies_b(t)) < rate_ratio_threshold)
				continue;

			if (!reins_flag) //Gross Run
				total += liab->sm_va[mp]->sm_va_sfas97rd[0]->Column(colnum).Value(t);

			else if (reins_flag && liab->sm_va[mp]->reins_flag) //Ceded Run && MP Reinsured
				total += liab->sm_va[mp]->sm_va_sfas97rd[1]->Column(colnum).Value(t);

			// no sum for ceded Run && MP Not Reinsured
			}	
		}
	}		
#endif
}
{
#if defined(__FA_LIAB_H_) && defined(__AA_COMP_COMP_H_)
if (fa_mp_map.size())
	{
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

			if (t < liab->sm_fa[mp]->commencement_period
				|| t > liab->sm_fa[mp]->maturity_period)
				continue;

			// Skip new issue commencement period
			if (liab->sm_fa[mp]->elapsed_mths <= 0
				&& t == liab->sm_fa[mp]->commencement_period)
				continue;

			if (t != liab->sm_fa[mp]->commencement_period
				&& fabs(liab->sm_fa[mp]->policies_b(t)) < rate_ratio_threshold)
				continue;

			if (!reins_flag) //Gross Run
				total += liab->sm_fa[mp]->sm_fa_sfas97rd[0]->Column(colnum).Value(t);

			else if (reins_flag && liab->sm_fa[mp]->reins_flag) //Ceded Run && MP Reinsured
				total += liab->sm_fa[mp]->sm_fa_sfas97rd[1]->Column(colnum).Value(t);

			// no sum for ceded Run && MP Not Reinsured
			}	
		}
	}		
#endif
}
{
#if defined(__FIA_LIAB_H_) && defined(__AA_COMP_COMP_H_)
if (fia_mp_map.size())
	{
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

			if (t < liab->sm_fia[mp]->commencement_period
				|| t > liab->sm_fia[mp]->maturity_period)
				continue;

			// Skip new issue commencement period
			if (liab->sm_fia[mp]->elapsed_mths <= 0
				&& t == liab->sm_fia[mp]->commencement_period)
				continue;

			if (t != liab->sm_fia[mp]->commencement_period
				&& fabs(liab->sm_fia[mp]->policies_b(t)) < rate_ratio_threshold)
				continue;

			if (!reins_flag) //Gross Run
				total += liab->sm_fia[mp]->sm_fia_sfas97rd[0]->Column(colnum).Value(t);

			else if (reins_flag && liab->sm_fia[mp]->reins_flag) //Ceded Run && MP Reinsured
				total += liab->sm_fia[mp]->sm_fia_sfas97rd[1]->Column(colnum).Value(t);

			// no sum for ceded Run && MP Not Reinsured
			}	
		}
	}		
#endif
}
{
//for EPL file
#if defined(__EPL_LIAB_H_) && defined(__AA_COMP_COMP_H_)
if (epl_mp_map.size())
	{
	// In epl/liab, "sfas97rd_gross_" and "sfas97rd_ceded_" have been added to the column names
	if (!reins_flag) 
		colname_epl = "sfas97rd_gross_" + colname;		
	else 
		colname_epl = "sfas97rd_ceded_" + colname;			
	
	total += sum_over_gaap_epl(colname_epl, t);
	}		
#endif
}

// include results from independent model points
if (seg_element->seriatim_totals.size() > 0)
	{
	int cohort_col = getElementNumber(0); 
	pair<xstring,seriatim_type> name_pair = make_pair(colname, prod_sfas97rd);
	map <pair<xstring,seriatim_type>, SmartArray< SmartArray< SmartArray<double> > > >::iterator totals_it = seg_element->seriatim_totals.find(name_pair);

	if(totals_it != seg_element->seriatim_totals.end())
		total += totals_it->second[cohort_col][reins_flag][t];
	}
return total;
}



#line 1 "sum_over_gaap_epl.SFAS97RD_GAAP.for"                                                                                   
double SFAS97RD_GAAP::sum_over_gaap_epl(const xstring & colname, const int t)
{
double total = 0.0;
int mp = 0;
int colnum = 0;
map <int, long, less <int> >::iterator mp_map_iter;

{
//for EPL file
#if defined(__EPL_LIAB_H_) && defined(__AA_COMP_COMP_H_)
if (epl_mp_map.size())
	{
	colnum = liab->sm_epl[0]->Column(colname).Number();				

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
			
			if (t < liab->sm_epl[mp]->commencement_period
				|| t > liab->sm_epl[mp]->maturity_period)
				continue;

			total += liab->sm_epl[mp]->Column(colnum).Value(t);
			}		
		}
	}		
#endif
}

// include results from independent model points
if (seg_element->seriatim_totals.size() > 0)
	{
	int cohort_col = getElementNumber(0); 
	pair<xstring,seriatim_type> name_pair = make_pair(colname, prod_sfas97rd);
	map <pair<xstring,seriatim_type>, SmartArray< SmartArray< SmartArray<double> > > >::iterator totals_it = seg_element->seriatim_totals.find(name_pair);

	if(totals_it != seg_element->seriatim_totals.end())
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
	<< "dac_acq_exp_sch" << ","  
	<< "dac_comm" << ","     
	<< "dac_comm_sch" << ","   
	<< "dac_prem_bonus" << ","     
	<< "dac_prem_bonus_sch" << ","    
	<< "egp_accum" << ","         
	<< "sop031_assess_accum" << ","    
	<< "sop031_gmdb_ben_accum" << ","    
	<< "sop031_pbr_accum" << ","       
	<< "deferred_loads_accum" << ","   
	<< "unearn_rev_liab" << ","   
	<< "unearn_rev_liab_sch" << ","       
	<< "dac_reins_yrt_asset" << ","  
	<< "dac_reins_yrt_asset_sch" << ","   
	<< "sop031_pbr_fund_val_accum" << ","  
	<< "embed_deriv_val" << ","      
	<< "mrb_gmab_liab" << ","    
	<< "mrb_gmib_liab" << ","    
	<< "mrb_gmwb_liab" << ","   
	<< "mrb_gmdb_liab" << ","   
	<< "sop031_ulsg_ben_accum" << ","  
	<< "sop031_gmdb_br" << ","             
	<< "sop031_pbr_liab" << ","      
	<< "sop031_ulsg_br" << ","  
	<< "policies_inf_sch" << endl;    
	}

xstring group_name = get_base_group_name(group, true);
double dac_acq_exp = this->dac_acq_exp(last_proj_period);
double dac_acq_exp_sch = this->dac_acq_exp_sch(last_proj_period);
double dac_comm = this->dac_comm(last_proj_period);
double dac_comm_sch = this->dac_comm_sch(last_proj_period);
double dac_prem_bonus = this->dac_prem_bonus(last_proj_period);
double dac_prem_bonus_sch = this->dac_prem_bonus_sch(last_proj_period);
double egp_accum = this->egp_accum(last_proj_period);
double sop031_assess_accum = this->sop031_assess_accum(last_proj_period);
double sop031_gmdb_ben_accum = this->sop031_gmdb_ben_accum(last_proj_period);
double sop031_pbr_accum = this->sop031_pbr_accum(last_proj_period);
double deferred_loads_accum = this->deferred_loads_accum(last_proj_period);
double unearn_rev_liab = this->unearn_rev_liab(last_proj_period);
double unearn_rev_liab_sch = this->unearn_rev_liab_sch(last_proj_period);
double dac_reins_yrt_asset = this->dac_reins_yrt_asset(last_proj_period);
double dac_reins_yrt_asset_sch = this->dac_reins_yrt_asset_sch(last_proj_period);
double sop031_pbr_fund_val_accum = this->sop031_pbr_fund_val_accum(last_proj_period);
double embed_deriv_val = this->embed_deriv_val(last_proj_period);
double mrb_gmab_liab = this->mrb_gmab_liab(last_proj_period); 
double mrb_gmib_liab = this->mrb_gmib_liab(last_proj_period); 
double mrb_gmwb_liab = this->mrb_gmwb_liab(last_proj_period); 
double mrb_gmdb_liab = this->mrb_gmdb_liab(last_proj_period); 
double sop031_ulsg_ben_accum = this->sop031_ulsg_ben_accum(last_proj_period);
double sop031_gmdb_br = this->sop031_gmdb_br(last_proj_period); 
double sop031_pbr_liab = this->sop031_pbr_liab(last_proj_period); 
double sop031_ulsg_br = this->sop031_ulsg_br(last_proj_period); 
double policies_inf_sch = this->policies_inf_sch(last_proj_period); 

sfas97rd_state_of_world_financial_output
<< group_name << ","
<< dac_acq_exp << ","
<< dac_acq_exp_sch << ","
<< dac_comm << ","
<< dac_comm_sch << ","
<< dac_prem_bonus << ","
<< dac_prem_bonus_sch << ","
<< egp_accum << ","
<< sop031_assess_accum << ","
<< sop031_gmdb_ben_accum << ","
<< sop031_pbr_accum << ","
<< deferred_loads_accum << ","
<< unearn_rev_liab << ","
<< unearn_rev_liab_sch << ","
<< dac_reins_yrt_asset << ","
<< dac_reins_yrt_asset_sch << ","
<< sop031_pbr_fund_val_accum << ","
<< embed_deriv_val << ","
<< mrb_gmab_liab << ","
<< mrb_gmib_liab << ","
<< mrb_gmwb_liab << ","
<< mrb_gmdb_liab << ","
<< sop031_ulsg_ben_accum << ","
<< sop031_gmdb_br << ","
<< sop031_pbr_liab << ","
<< sop031_ulsg_br << ","
<< policies_inf_sch << endl;

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
	CashFlowCommonData(3, "agp_history", "sfas97rd_gaap_agp_history",  "agp_history",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_agp_history, 'E','N', '3', 'P', (size_t)&modelOffset->agp_history),
	CashFlowCommonData(4, "amortzn_int_rate", "sfas97rd_gaap_amortzn_int_rate",  "amortzn_int_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_amortzn_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->amortzn_int_rate),
	CashFlowCommonData(5, "cal_mth", "sfas97rd_gaap_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(6, "cal_yr", "sfas97rd_gaap_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(7, "cal_yr_relative", "sfas97rd_gaap_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(8, "cap_gain", "sfas97rd_gaap_cap_gain",  "cap_gain",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cap_gain, 'E','Y', '3', 'P', (size_t)&modelOffset->cap_gain),
	CashFlowCommonData(9, "cap_gain_fund", "sfas97rd_gaap_cap_gain_fund",  "cap_gain_fund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cap_gain_fund, 'E','N', '3', 'P', (size_t)&modelOffset->cap_gain_fund),
	CashFlowCommonData(10, "capzd_acq_exp", "sfas97rd_gaap_capzd_acq_exp",  "capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_acq_exp, 'B','Y', '3', 'P', (size_t)&modelOffset->capzd_acq_exp),
	CashFlowCommonData(11, "capzd_comm_bom", "sfas97rd_gaap_capzd_comm_bom",  "capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->capzd_comm_bom),
	CashFlowCommonData(12, "capzd_comm_chargeback", "sfas97rd_gaap_capzd_comm_chargeback",  "capzd_comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_chargeback, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_comm_chargeback),
	CashFlowCommonData(13, "capzd_comm_eom", "sfas97rd_gaap_capzd_comm_eom",  "capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_comm_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->capzd_comm_eom),
	CashFlowCommonData(14, "capzd_prem_bonus", "sfas97rd_gaap_capzd_prem_bonus",  "capzd_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_prem_bonus, 'B','Y', '3', 'P', (size_t)&modelOffset->capzd_prem_bonus),
	CashFlowCommonData(15, "capzd_reins_yrt_cost", "sfas97rd_gaap_capzd_reins_yrt_cost",  "capzd_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_capzd_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->capzd_reins_yrt_cost),
	CashFlowCommonData(16, "cash_flow_bom", "sfas97rd_gaap_cash_flow_bom",  "cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->cash_flow_bom),
	CashFlowCommonData(17, "cash_flow_int", "sfas97rd_gaap_cash_flow_int",  "cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_cash_flow_int, 'B','Y', '3', 'P', (size_t)&modelOffset->cash_flow_int),
	CashFlowCommonData(18, "charges", "sfas97rd_gaap_charges",  "charges",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_charges, 'B','Y', '3', 'P', (size_t)&modelOffset->charges),
	CashFlowCommonData(19, "comm_chargeback", "sfas97rd_gaap_comm_chargeback",  "comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_chargeback, 'E','Y', '3', 'P', (size_t)&modelOffset->comm_chargeback),
	CashFlowCommonData(20, "comm_excess_bom", "sfas97rd_gaap_comm_excess_bom",  "comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_excess_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->comm_excess_bom),
	CashFlowCommonData(21, "comm_excess_eom", "sfas97rd_gaap_comm_excess_eom",  "comm_excess_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_excess_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->comm_excess_eom),
	CashFlowCommonData(22, "comm_trail_bom", "sfas97rd_gaap_comm_trail_bom",  "comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_trail_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->comm_trail_bom),
	CashFlowCommonData(23, "comm_trail_eom", "sfas97rd_gaap_comm_trail_eom",  "comm_trail_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_trail_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->comm_trail_eom),
	CashFlowCommonData(24, "credited_int", "sfas97rd_gaap_credited_int",  "credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_credited_int, 'E','Y', '3', 'C', (size_t)&modelOffset->credited_int),
	CashFlowCommonData(25, "dac_acq_exp", "sfas97rd_gaap_dac_acq_exp",  "dac_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp, 'E','N', '3', 'P', (size_t)&modelOffset->dac_acq_exp),
	CashFlowCommonData(26, "dac_acq_exp_amortzn", "sfas97rd_gaap_dac_acq_exp_amortzn",  "dac_acq_exp_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_amortzn, 'E','N', '3', 'P', (size_t)&modelOffset->dac_acq_exp_amortzn),
	CashFlowCommonData(27, "dac_acq_exp_incr", "sfas97rd_gaap_dac_acq_exp_incr",  "dac_acq_exp_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->dac_acq_exp_incr),
	CashFlowCommonData(28, "dac_acq_exp_sch", "sfas97rd_gaap_dac_acq_exp_sch",  "dac_acq_exp_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_acq_exp_sch, 'E','N', '3', 'P', (size_t)&modelOffset->dac_acq_exp_sch),
	CashFlowCommonData(29, "dac_comm", "sfas97rd_gaap_dac_comm",  "dac_comm",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm, 'E','N', '3', 'P', (size_t)&modelOffset->dac_comm),
	CashFlowCommonData(30, "dac_comm_amortzn", "sfas97rd_gaap_dac_comm_amortzn",  "dac_comm_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_amortzn, 'E','N', '3', 'P', (size_t)&modelOffset->dac_comm_amortzn),
	CashFlowCommonData(31, "dac_comm_incr", "sfas97rd_gaap_dac_comm_incr",  "dac_comm_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->dac_comm_incr),
	CashFlowCommonData(32, "dac_comm_sch", "sfas97rd_gaap_dac_comm_sch",  "dac_comm_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_comm_sch, 'E','N', '3', 'P', (size_t)&modelOffset->dac_comm_sch),
	CashFlowCommonData(33, "dac_incr", "sfas97rd_gaap_dac_incr",  "dac_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->dac_incr),
	CashFlowCommonData(34, "dac_prem_bonus", "sfas97rd_gaap_dac_prem_bonus",  "dac_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus, 'E','N', '3', 'P', (size_t)&modelOffset->dac_prem_bonus),
	CashFlowCommonData(35, "dac_prem_bonus_amortzn", "sfas97rd_gaap_dac_prem_bonus_amortzn",  "dac_prem_bonus_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_amortzn, 'E','N', '3', 'P', (size_t)&modelOffset->dac_prem_bonus_amortzn),
	CashFlowCommonData(36, "dac_prem_bonus_incr", "sfas97rd_gaap_dac_prem_bonus_incr",  "dac_prem_bonus_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->dac_prem_bonus_incr),
	CashFlowCommonData(37, "dac_prem_bonus_sch", "sfas97rd_gaap_dac_prem_bonus_sch",  "dac_prem_bonus_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_prem_bonus_sch, 'E','N', '3', 'P', (size_t)&modelOffset->dac_prem_bonus_sch),
	CashFlowCommonData(38, "dac_reins_yrt_asset", "sfas97rd_gaap_dac_reins_yrt_asset",  "dac_reins_yrt_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset, 'E','N', '3', 'P', (size_t)&modelOffset->dac_reins_yrt_asset),
	CashFlowCommonData(39, "dac_reins_yrt_asset_amortzn", "sfas97rd_gaap_dac_reins_yrt_asset_amortzn",  "dac_reins_yrt_asset_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset_amortzn, 'E','N', '3', 'P', (size_t)&modelOffset->dac_reins_yrt_asset_amortzn),
	CashFlowCommonData(40, "dac_reins_yrt_asset_incr", "sfas97rd_gaap_dac_reins_yrt_asset_incr",  "dac_reins_yrt_asset_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->dac_reins_yrt_asset_incr),
	CashFlowCommonData(41, "dac_reins_yrt_asset_sch", "sfas97rd_gaap_dac_reins_yrt_asset_sch",  "dac_reins_yrt_asset_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dac_reins_yrt_asset_sch, 'E','N', '3', 'P', (size_t)&modelOffset->dac_reins_yrt_asset_sch),
	CashFlowCommonData(42, "date", "sfas97rd_gaap_date",  "date",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(43, "deferred_loads", "sfas97rd_gaap_deferred_loads",  "deferred_loads",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_deferred_loads, 'E','N', '3', 'P', (size_t)&modelOffset->deferred_loads),
	CashFlowCommonData(44, "deferred_loads_accum", "sfas97rd_gaap_deferred_loads_accum",  "deferred_loads_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_deferred_loads_accum, 'E','N', '3', 'P', (size_t)&modelOffset->deferred_loads_accum),
	CashFlowCommonData(45, "deferred_loads_history", "sfas97rd_gaap_deferred_loads_history",  "deferred_loads_history",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_deferred_loads_history, 'E','N', '3', 'P', (size_t)&modelOffset->deferred_loads_history),
	CashFlowCommonData(46, "deferred_loads_pv", "sfas97rd_gaap_deferred_loads_pv",  "deferred_loads_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_deferred_loads_pv, 'E','N', '3', 'P', (size_t)&modelOffset->deferred_loads_pv),
	CashFlowCommonData(47, "dth_claim_cost", "sfas97rd_gaap_dth_claim_cost",  "dth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_dth_claim_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->dth_claim_cost),
	CashFlowCommonData(48, "egp", "sfas97rd_gaap_egp",  "egp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp, 'E','N', '3', 'P', (size_t)&modelOffset->egp),
	CashFlowCommonData(49, "egp_accum", "sfas97rd_gaap_egp_accum",  "egp_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_accum, 'E','N', '3', 'P', (size_t)&modelOffset->egp_accum),
	CashFlowCommonData(50, "egp_gain_exp", "sfas97rd_gaap_egp_gain_exp",  "egp_gain_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_exp, 'E','N', '3', 'P', (size_t)&modelOffset->egp_gain_exp),
	CashFlowCommonData(51, "egp_gain_inv", "sfas97rd_gaap_egp_gain_inv",  "egp_gain_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_inv, 'E','N', '3', 'P', (size_t)&modelOffset->egp_gain_inv),
	CashFlowCommonData(52, "egp_gain_mort", "sfas97rd_gaap_egp_gain_mort",  "egp_gain_mort",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_mort, 'E','N', '3', 'P', (size_t)&modelOffset->egp_gain_mort),
	CashFlowCommonData(53, "egp_gain_persist_bon_ref", "sfas97rd_gaap_egp_gain_persist_bon_ref",  "egp_gain_persist_bon_ref",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_persist_bon_ref, 'E','Y', '3', 'C', (size_t)&modelOffset->egp_gain_persist_bon_ref),
	CashFlowCommonData(54, "egp_gain_surr", "sfas97rd_gaap_egp_gain_surr",  "egp_gain_surr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_gain_surr, 'E','N', '3', 'P', (size_t)&modelOffset->egp_gain_surr),
	CashFlowCommonData(55, "egp_pv", "sfas97rd_gaap_egp_pv",  "egp_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_pv, 'E','N', '3', 'P', (size_t)&modelOffset->egp_pv),
	CashFlowCommonData(56, "egp_sop031_assess_accum", "sfas97rd_gaap_egp_sop031_assess_accum",  "egp_sop031_assess_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_assess_accum, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_assess_accum),
	CashFlowCommonData(57, "egp_sop031_gmdb_ben_accum", "sfas97rd_gaap_egp_sop031_gmdb_ben_accum",  "egp_sop031_gmdb_ben_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmdb_ben_accum, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_gmdb_ben_accum),
	CashFlowCommonData(58, "egp_sop031_gmdb_liab", "sfas97rd_gaap_egp_sop031_gmdb_liab",  "egp_sop031_gmdb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_gmdb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_gmdb_liab),
	CashFlowCommonData(59, "egp_sop031_res_incr", "sfas97rd_gaap_egp_sop031_res_incr",  "egp_sop031_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_res_incr, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_res_incr),
	CashFlowCommonData(60, "egp_sop031_ulsg_ben_accum", "sfas97rd_gaap_egp_sop031_ulsg_ben_accum",  "egp_sop031_ulsg_ben_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_ulsg_ben_accum, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_ulsg_ben_accum),
	CashFlowCommonData(61, "egp_sop031_ulsg_liab", "sfas97rd_gaap_egp_sop031_ulsg_liab",  "egp_sop031_ulsg_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_egp_sop031_ulsg_liab, 'E','N', '3', 'P', (size_t)&modelOffset->egp_sop031_ulsg_liab),
	CashFlowCommonData(62, "embed_deriv_cash_flow", "sfas97rd_gaap_embed_deriv_cash_flow",  "embed_deriv_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_embed_deriv_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->embed_deriv_cash_flow),
	CashFlowCommonData(63, "embed_deriv_cash_flow_pv", "sfas97rd_gaap_embed_deriv_cash_flow_pv",  "embed_deriv_cash_flow_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_embed_deriv_cash_flow_pv, 'E','Y', '3', 'P', (size_t)&modelOffset->embed_deriv_cash_flow_pv),
	CashFlowCommonData(64, "embed_deriv_val", "sfas97rd_gaap_embed_deriv_val",  "embed_deriv_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_embed_deriv_val, 'E','Y', '3', 'P', (size_t)&modelOffset->embed_deriv_val),
	CashFlowCommonData(65, "finalize", "sfas97rd_gaap_finalize",  "finalize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_finalize, 'E','N', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(66, "fund_val", "sfas97rd_gaap_fund_val",  "fund_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_fund_val, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val),
	CashFlowCommonData(67, "fund_val_bef_int", "sfas97rd_gaap_fund_val_bef_int",  "fund_val_bef_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_fund_val_bef_int, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val_bef_int),
	CashFlowCommonData(68, "fund_val_fixed", "sfas97rd_gaap_fund_val_fixed",  "fund_val_fixed",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_fund_val_fixed, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val_fixed),
	CashFlowCommonData(69, "fund_val_sa", "sfas97rd_gaap_fund_val_sa",  "fund_val_sa",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_fund_val_sa, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val_sa),
	CashFlowCommonData(70, "gaap_amortzn_int_rate", "sfas97rd_gaap_gaap_amortzn_int_rate",  "gaap_amortzn_int_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gaap_amortzn_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->gaap_amortzn_int_rate),
	CashFlowCommonData(71, "gmab_ben", "sfas97rd_gaap_gmab_ben",  "gmab_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmab_ben, 'E','N', '3', 'P', (size_t)&modelOffset->gmab_ben),
	CashFlowCommonData(72, "gmdb_ben", "sfas97rd_gaap_gmdb_ben",  "gmdb_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmdb_ben, 'E','N', '3', 'P', (size_t)&modelOffset->gmdb_ben),
	CashFlowCommonData(73, "gmib_ben", "sfas97rd_gaap_gmib_ben",  "gmib_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmib_ben, 'E','N', '3', 'P', (size_t)&modelOffset->gmib_ben),
	CashFlowCommonData(74, "gmwb_ben", "sfas97rd_gaap_gmwb_ben",  "gmwb_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gmwb_ben, 'E','N', '3', 'P', (size_t)&modelOffset->gmwb_ben),
	CashFlowCommonData(75, "hedge_cash_flow", "sfas97rd_gaap_hedge_cash_flow",  "hedge_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cash_flow),
	CashFlowCommonData(76, "hedge_cost", "sfas97rd_gaap_hedge_cost",  "hedge_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cost),
	CashFlowCommonData(77, "hedge_mkt_val", "sfas97rd_gaap_hedge_mkt_val",  "hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->hedge_mkt_val),
	CashFlowCommonData(78, "hedge_mkt_val_incr", "sfas97rd_gaap_hedge_mkt_val_incr",  "hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_mkt_val_incr),
	CashFlowCommonData(79, "host_contract_cred_int", "sfas97rd_gaap_host_contract_cred_int",  "host_contract_cred_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_host_contract_cred_int, 'E','Y', '3', 'P', (size_t)&modelOffset->host_contract_cred_int),
	CashFlowCommonData(80, "host_contract_val", "sfas97rd_gaap_host_contract_val",  "host_contract_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_host_contract_val, 'E','Y', '3', 'P', (size_t)&modelOffset->host_contract_val),
	CashFlowCommonData(81, "host_contract_val_bef", "sfas97rd_gaap_host_contract_val_bef",  "host_contract_val_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_host_contract_val_bef, 'E','Y', '3', 'P', (size_t)&modelOffset->host_contract_val_bef),
	CashFlowCommonData(82, "initialize", "sfas97rd_gaap_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(83, "inv_inc", "sfas97rd_gaap_inv_inc",  "inv_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_inv_inc, 'E','Y', '3', 'P', (size_t)&modelOffset->inv_inc),
	CashFlowCommonData(84, "inv_inc_fund", "sfas97rd_gaap_inv_inc_fund",  "inv_inc_fund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_inv_inc_fund, 'E','N', '3', 'P', (size_t)&modelOffset->inv_inc_fund),
	CashFlowCommonData(85, "k_capzd_acq_exp", "sfas97rd_gaap_k_capzd_acq_exp",  "k_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_acq_exp, 'E','N', '3', 'P', (size_t)&modelOffset->k_capzd_acq_exp),
	CashFlowCommonData(86, "k_capzd_acq_exp_sch", "sfas97rd_gaap_k_capzd_acq_exp_sch",  "k_capzd_acq_exp_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_acq_exp_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_capzd_acq_exp_sch),
	CashFlowCommonData(87, "k_capzd_comm", "sfas97rd_gaap_k_capzd_comm",  "k_capzd_comm",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_comm, 'E','N', '3', 'P', (size_t)&modelOffset->k_capzd_comm),
	CashFlowCommonData(88, "k_capzd_comm_sch", "sfas97rd_gaap_k_capzd_comm_sch",  "k_capzd_comm_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_comm_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_capzd_comm_sch),
	CashFlowCommonData(89, "k_capzd_prem_bonus", "sfas97rd_gaap_k_capzd_prem_bonus",  "k_capzd_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_prem_bonus, 'E','N', '3', 'P', (size_t)&modelOffset->k_capzd_prem_bonus),
	CashFlowCommonData(90, "k_capzd_prem_bonus_sch", "sfas97rd_gaap_k_capzd_prem_bonus_sch",  "k_capzd_prem_bonus_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_capzd_prem_bonus_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_capzd_prem_bonus_sch),
	CashFlowCommonData(91, "k_reins_yrt_cost", "sfas97rd_gaap_k_reins_yrt_cost",  "k_reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->k_reins_yrt_cost),
	CashFlowCommonData(92, "k_reins_yrt_cost_sch", "sfas97rd_gaap_k_reins_yrt_cost_sch",  "k_reins_yrt_cost_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_reins_yrt_cost_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_reins_yrt_cost_sch),
	CashFlowCommonData(93, "k_sop031_gmdb_ben_br", "sfas97rd_gaap_k_sop031_gmdb_ben_br",  "k_sop031_gmdb_ben_br",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_gmdb_ben_br, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_gmdb_ben_br),
	CashFlowCommonData(94, "k_sop031_gmdb_ben_br_sch", "sfas97rd_gaap_k_sop031_gmdb_ben_br_sch",  "k_sop031_gmdb_ben_br_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_gmdb_ben_br_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_gmdb_ben_br_sch),
	CashFlowCommonData(95, "k_sop031_pbr", "sfas97rd_gaap_k_sop031_pbr",  "k_sop031_pbr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_pbr, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_pbr),
	CashFlowCommonData(96, "k_sop031_pbr_sch", "sfas97rd_gaap_k_sop031_pbr_sch",  "k_sop031_pbr_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_pbr_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_pbr_sch),
	CashFlowCommonData(97, "k_sop031_ulsg_ben_br", "sfas97rd_gaap_k_sop031_ulsg_ben_br",  "k_sop031_ulsg_ben_br",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_ulsg_ben_br, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_ulsg_ben_br),
	CashFlowCommonData(98, "k_sop031_ulsg_ben_br_sch", "sfas97rd_gaap_k_sop031_ulsg_ben_br_sch",  "k_sop031_ulsg_ben_br_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_ulsg_ben_br_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_ulsg_ben_br_sch),
	CashFlowCommonData(99, "k_sop031_unearn_rev_liab", "sfas97rd_gaap_k_sop031_unearn_rev_liab",  "k_sop031_unearn_rev_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_unearn_rev_liab, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_unearn_rev_liab),
	CashFlowCommonData(100, "k_sop031_unearn_rev_liab_sch", "sfas97rd_gaap_k_sop031_unearn_rev_liab_sch",  "k_sop031_unearn_rev_liab_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_sop031_unearn_rev_liab_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_sop031_unearn_rev_liab_sch),
	CashFlowCommonData(101, "k_unearn_rev_liab", "sfas97rd_gaap_k_unearn_rev_liab",  "k_unearn_rev_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_unearn_rev_liab, 'E','N', '3', 'P', (size_t)&modelOffset->k_unearn_rev_liab),
	CashFlowCommonData(102, "k_unearn_rev_liab_sch", "sfas97rd_gaap_k_unearn_rev_liab_sch",  "k_unearn_rev_liab_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_k_unearn_rev_liab_sch, 'E','N', '3', 'P', (size_t)&modelOffset->k_unearn_rev_liab_sch),
	CashFlowCommonData(103, "liab_net", "sfas97rd_gaap_liab_net",  "liab_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_liab_net, 'E','Y', '3', 'P', (size_t)&modelOffset->liab_net),
	CashFlowCommonData(104, "loads", "sfas97rd_gaap_loads",  "loads",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_loads, 'B','Y', '3', 'P', (size_t)&modelOffset->loads),
	CashFlowCommonData(105, "loc_cost", "sfas97rd_gaap_loc_cost",  "loc_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_loc_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->loc_cost),
	CashFlowCommonData(106, "maint_exp_bom", "sfas97rd_gaap_maint_exp_bom",  "maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->maint_exp_bom),
	CashFlowCommonData(107, "maint_exp_eom", "sfas97rd_gaap_maint_exp_eom",  "maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_maint_exp_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->maint_exp_eom),
	CashFlowCommonData(108, "modco_liab", "sfas97rd_gaap_modco_liab",  "modco_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_modco_liab, 'E','N', '3', 'C', (size_t)&modelOffset->modco_liab),
	CashFlowCommonData(109, "modco_liab_incr", "sfas97rd_gaap_modco_liab_incr",  "modco_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_modco_liab_incr, 'E','N', '3', 'P', (size_t)&modelOffset->modco_liab_incr),
	CashFlowCommonData(110, "modco_res_adj", "sfas97rd_gaap_modco_res_adj",  "modco_res_adj",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_modco_res_adj, 'E','Y', '3', 'C', (size_t)&modelOffset->modco_res_adj),
	CashFlowCommonData(111, "mrb_gmab_liab", "sfas97rd_gaap_mrb_gmab_liab",  "mrb_gmab_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_mrb_gmab_liab, 'E','N', '3', 'P', (size_t)&modelOffset->mrb_gmab_liab),
	CashFlowCommonData(112, "mrb_gmdb_liab", "sfas97rd_gaap_mrb_gmdb_liab",  "mrb_gmdb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_mrb_gmdb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->mrb_gmdb_liab),
	CashFlowCommonData(113, "mrb_gmib_liab", "sfas97rd_gaap_mrb_gmib_liab",  "mrb_gmib_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_mrb_gmib_liab, 'E','N', '3', 'P', (size_t)&modelOffset->mrb_gmib_liab),
	CashFlowCommonData(114, "mrb_gmwb_liab", "sfas97rd_gaap_mrb_gmwb_liab",  "mrb_gmwb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_mrb_gmwb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->mrb_gmwb_liab),
	CashFlowCommonData(115, "mrb_liab", "sfas97rd_gaap_mrb_liab",  "mrb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_mrb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->mrb_liab),
	CashFlowCommonData(116, "mrb_liab_incr", "sfas97rd_gaap_mrb_liab_incr",  "mrb_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_mrb_liab_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->mrb_liab_incr),
	CashFlowCommonData(117, "persist_bon_ref", "sfas97rd_gaap_persist_bon_ref",  "persist_bon_ref",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_persist_bon_ref, 'E','N', '3', 'P', (size_t)&modelOffset->persist_bon_ref),
	CashFlowCommonData(118, "pol_loan", "sfas97rd_gaap_pol_loan",  "pol_loan",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_pol_loan, 'E','Y', '3', 'P', (size_t)&modelOffset->pol_loan),
	CashFlowCommonData(119, "pol_loan_inc", "sfas97rd_gaap_pol_loan_inc",  "pol_loan_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_pol_loan_inc, 'E','Y', '3', 'P', (size_t)&modelOffset->pol_loan_inc),
	CashFlowCommonData(120, "policies_inf", "sfas97rd_gaap_policies_inf",  "policies_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_policies_inf, 'B','N', '3', 'C', (size_t)&modelOffset->policies_inf),
	CashFlowCommonData(121, "policies_inf_sch", "sfas97rd_gaap_policies_inf_sch",  "policies_inf_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_policies_inf_sch, 'B','N', '3', 'C', (size_t)&modelOffset->policies_inf_sch),
	CashFlowCommonData(122, "policies_inf_sum", "sfas97rd_gaap_policies_inf_sum",  "policies_inf_sum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_policies_inf_sum, 'B','N', '3', 'C', (size_t)&modelOffset->policies_inf_sum),
	CashFlowCommonData(123, "prem_bonus", "sfas97rd_gaap_prem_bonus",  "prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_prem_bonus, 'B','Y', '3', 'P', (size_t)&modelOffset->prem_bonus),
	CashFlowCommonData(124, "prem_tax", "sfas97rd_gaap_prem_tax",  "prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_prem_tax, 'B','Y', '3', 'P', (size_t)&modelOffset->prem_tax),
	CashFlowCommonData(125, "refund", "sfas97rd_gaap_refund",  "refund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_refund, 'E','Y', '3', 'C', (size_t)&modelOffset->refund),
	CashFlowCommonData(126, "reins_yrt_cost", "sfas97rd_gaap_reins_yrt_cost",  "reins_yrt_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_reins_yrt_cost, 'E','N', '3', 'P', (size_t)&modelOffset->reins_yrt_cost),
	CashFlowCommonData(127, "rider_charges", "sfas97rd_gaap_rider_charges",  "rider_charges",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_rider_charges, 'B','Y', '3', 'P', (size_t)&modelOffset->rider_charges),
	CashFlowCommonData(128, "sfas133_liab", "sfas97rd_gaap_sfas133_liab",  "sfas133_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sfas133_liab),
	CashFlowCommonData(129, "sfas133_liab_incr", "sfas97rd_gaap_sfas133_liab_incr",  "sfas133_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sfas133_liab_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->sfas133_liab_incr),
	CashFlowCommonData(130, "sop031_addl_liab", "sfas97rd_gaap_sop031_addl_liab",  "sop031_addl_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_addl_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_addl_liab),
	CashFlowCommonData(131, "sop031_addl_liab_incr", "sfas97rd_gaap_sop031_addl_liab_incr",  "sop031_addl_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_addl_liab_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->sop031_addl_liab_incr),
	CashFlowCommonData(132, "sop031_assess", "sfas97rd_gaap_sop031_assess",  "sop031_assess",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_assess, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_assess),
	CashFlowCommonData(133, "sop031_assess_accum", "sfas97rd_gaap_sop031_assess_accum",  "sop031_assess_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_assess_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_assess_accum),
	CashFlowCommonData(134, "sop031_assess_history", "sfas97rd_gaap_sop031_assess_history",  "sop031_assess_history",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_assess_history, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_assess_history),
	CashFlowCommonData(135, "sop031_assess_pv", "sfas97rd_gaap_sop031_assess_pv",  "sop031_assess_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_assess_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_assess_pv),
	CashFlowCommonData(136, "sop031_egp", "sfas97rd_gaap_sop031_egp",  "sop031_egp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_egp, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_egp),
	CashFlowCommonData(137, "sop031_egp_accum", "sfas97rd_gaap_sop031_egp_accum",  "sop031_egp_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_egp_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_egp_accum),
	CashFlowCommonData(138, "sop031_egp_pv", "sfas97rd_gaap_sop031_egp_pv",  "sop031_egp_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_egp_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_egp_pv),
	CashFlowCommonData(139, "sop031_gmdb_ben_accum", "sfas97rd_gaap_sop031_gmdb_ben_accum",  "sop031_gmdb_ben_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_ben_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmdb_ben_accum),
	CashFlowCommonData(140, "sop031_gmdb_ben_pv", "sfas97rd_gaap_sop031_gmdb_ben_pv",  "sop031_gmdb_ben_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_ben_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmdb_ben_pv),
	CashFlowCommonData(141, "sop031_gmdb_benefits_history", "sfas97rd_gaap_sop031_gmdb_benefits_history",  "sop031_gmdb_benefits_history",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_benefits_history, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmdb_benefits_history),
	CashFlowCommonData(142, "sop031_gmdb_br", "sfas97rd_gaap_sop031_gmdb_br",  "sop031_gmdb_br",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_br, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmdb_br),
	CashFlowCommonData(143, "sop031_gmdb_br_sch", "sfas97rd_gaap_sop031_gmdb_br_sch",  "sop031_gmdb_br_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_br_sch, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmdb_br_sch),
	CashFlowCommonData(144, "sop031_gmdb_liab", "sfas97rd_gaap_sop031_gmdb_liab",  "sop031_gmdb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_gmdb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_gmdb_liab),
	CashFlowCommonData(145, "sop031_pbr", "sfas97rd_gaap_sop031_pbr",  "sop031_pbr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr),
	CashFlowCommonData(146, "sop031_pbr_accum", "sfas97rd_gaap_sop031_pbr_accum",  "sop031_pbr_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_accum),
	CashFlowCommonData(147, "sop031_pbr_benefits_history", "sfas97rd_gaap_sop031_pbr_benefits_history",  "sop031_pbr_benefits_history",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_benefits_history, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_benefits_history),
	CashFlowCommonData(148, "sop031_pbr_fund_val", "sfas97rd_gaap_sop031_pbr_fund_val",  "sop031_pbr_fund_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_fund_val, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_fund_val),
	CashFlowCommonData(149, "sop031_pbr_fund_val_accum", "sfas97rd_gaap_sop031_pbr_fund_val_accum",  "sop031_pbr_fund_val_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_fund_val_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_fund_val_accum),
	CashFlowCommonData(150, "sop031_pbr_fund_val_history", "sfas97rd_gaap_sop031_pbr_fund_val_history",  "sop031_pbr_fund_val_history",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_fund_val_history, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_fund_val_history),
	CashFlowCommonData(151, "sop031_pbr_fund_val_pv", "sfas97rd_gaap_sop031_pbr_fund_val_pv",  "sop031_pbr_fund_val_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_fund_val_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_fund_val_pv),
	CashFlowCommonData(152, "sop031_pbr_liab", "sfas97rd_gaap_sop031_pbr_liab",  "sop031_pbr_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_liab),
	CashFlowCommonData(153, "sop031_pbr_liab_amortzn", "sfas97rd_gaap_sop031_pbr_liab_amortzn",  "sop031_pbr_liab_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_liab_amortzn, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_liab_amortzn),
	CashFlowCommonData(154, "sop031_pbr_liab_int", "sfas97rd_gaap_sop031_pbr_liab_int",  "sop031_pbr_liab_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_liab_int, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_liab_int),
	CashFlowCommonData(155, "sop031_pbr_liab_sch", "sfas97rd_gaap_sop031_pbr_liab_sch",  "sop031_pbr_liab_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_liab_sch, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_liab_sch),
	CashFlowCommonData(156, "sop031_pbr_pv", "sfas97rd_gaap_sop031_pbr_pv",  "sop031_pbr_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_pv),
	CashFlowCommonData(157, "sop031_pbr_units_inf", "sfas97rd_gaap_sop031_pbr_units_inf",  "sop031_pbr_units_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_pbr_units_inf, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_pbr_units_inf),
	CashFlowCommonData(158, "sop031_sg_benefits_history", "sfas97rd_gaap_sop031_sg_benefits_history",  "sop031_sg_benefits_history",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_sg_benefits_history, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_sg_benefits_history),
	CashFlowCommonData(159, "sop031_ulsg_ben_accum", "sfas97rd_gaap_sop031_ulsg_ben_accum",  "sop031_ulsg_ben_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_ben_accum, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_ulsg_ben_accum),
	CashFlowCommonData(160, "sop031_ulsg_ben_pv", "sfas97rd_gaap_sop031_ulsg_ben_pv",  "sop031_ulsg_ben_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_ben_pv, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_ulsg_ben_pv),
	CashFlowCommonData(161, "sop031_ulsg_br", "sfas97rd_gaap_sop031_ulsg_br",  "sop031_ulsg_br",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_br, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_ulsg_br),
	CashFlowCommonData(162, "sop031_ulsg_br_sch", "sfas97rd_gaap_sop031_ulsg_br_sch",  "sop031_ulsg_br_sch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_br_sch, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_ulsg_br_sch),
	CashFlowCommonData(163, "sop031_ulsg_liab", "sfas97rd_gaap_sop031_ulsg_liab",  "sop031_ulsg_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_ulsg_liab, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_ulsg_liab),
	CashFlowCommonData(164, "sop031_unearn_rev_liab_incr", "sfas97rd_gaap_sop031_unearn_rev_liab_incr",  "sop031_unearn_rev_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_unearn_rev_liab_incr, 'E','N', '3', 'P', (size_t)&modelOffset->sop031_unearn_rev_liab_incr),
	CashFlowCommonData(165, "startup", "sfas97rd_gaap_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(166, "stat_res_rider", "sfas97rd_gaap_stat_res_rider",  "stat_res_rider",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_stat_res_rider, 'E','N', '3', 'P', (size_t)&modelOffset->stat_res_rider),
	CashFlowCommonData(167, "ulsg_ben", "sfas97rd_gaap_ulsg_ben",  "ulsg_ben",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_ulsg_ben, 'E','N', '3', 'P', (size_t)&modelOffset->ulsg_ben),
	CashFlowCommonData(168, "unearn_rev_liab", "sfas97rd_gaap_unearn_rev_liab",  "unearn_rev_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab, 'E','N', '3', 'P', (size_t)&modelOffset->unearn_rev_liab),
	CashFlowCommonData(169, "unearn_rev_liab_amortzn", "sfas97rd_gaap_unearn_rev_liab_amortzn",  "unearn_rev_liab_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_amortzn, 'E','N', '3', 'P', (size_t)&modelOffset->unearn_rev_liab_amortzn),
	CashFlowCommonData(170, "unearn_rev_liab_incr", "sfas97rd_gaap_unearn_rev_liab_incr",  "unearn_rev_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->unearn_rev_liab_incr),
	CashFlowCommonData(171, "unearn_rev_liab_released", "sfas97rd_gaap_unearn_rev_liab_released",  "unearn_rev_liab_released",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_unearn_rev_liab_released, 'E','Y', '3', 'P', (size_t)&modelOffset->unearn_rev_liab_released),
	CashFlowCommonData(172, "unearn_rev_liab_sch", "sfas97rd_gaap_unearn_rev_liab_sch",  "unearn_rev_liab_sch",  CashFlowCommonData::SUM,
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

	// EnumList for model_name                                                                                       
	const ChoicePair model_nameChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SFAS97RD, "sfas97rd")
		,ChoicePair(StrEnum::FIA_SFAS97RD, "fia_sfas97rd")
	};
	const EnumList model_nameEnumList(2, model_nameChoicePairs);

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
	Descriptor(4, Attribute::DOUBLE,	"cohort_history_dac_acq_exp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_dac_acq_exp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::DOUBLE,	"cohort_history_dac_comm", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_dac_comm,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::DOUBLE,	"cohort_history_dac_prem_bonus", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_dac_prem_bonus,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::DOUBLE,	"cohort_history_dac_reins_yrt_asset", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_dac_reins_yrt_asset,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::DOUBLE,	"cohort_history_deferred_load", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_deferred_load,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::DOUBLE,	"cohort_history_sop031_assess", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_sop031_assess,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::DOUBLE,	"cohort_history_sop031_gmdb_benefits", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_sop031_gmdb_benefits,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::DOUBLE,	"cohort_history_sop031_pbr_benefits", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_sop031_pbr_benefits,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::DOUBLE,	"cohort_history_sop031_pbr_fund_val", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_sop031_pbr_fund_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::DOUBLE,	"cohort_history_sop031_sg_benefits", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_sop031_sg_benefits,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::DOUBLE,	"cohort_history_unearn_rev_liab", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cohort_history_unearn_rev_liab,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::STRING,	"cohort_id", -1, (size_t)&modelOffset->cohort_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::STRING,	"cohort_issue_yrs", -1, (size_t)&modelOffset->cohort_issue_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::STRING,	"cohort_plan_codes", -1, (size_t)&modelOffset->cohort_plan_codes,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::STR_ENUM,	"cohort_reins_defn", -1, (size_t)&modelOffset->cohort_reins_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &cohort_reins_defnEnumList, Feature(true)),
	Descriptor(19, Attribute::INT,	"cohort_yr", -1, (size_t)&modelOffset->cohort_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::INT,	"comm_py_lookup", -1, (size_t)&modelOffset->comm_py_lookup,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::DOUBLE,	"fia_gaap_int_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fia_gaap_int_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::STR_ENUM,	"model_name", -1, (size_t)&modelOffset->model_name,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &model_nameEnumList, Feature(true)),
	Descriptor(23, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::STRING,	"seg_id", -1, (size_t)&modelOffset->seg_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(25, Attribute::STRING,	"sfas97rd_results", -1, (size_t)&modelOffset->sfas97rd_results,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::STRING,	"sop031_results", -1, (size_t)&modelOffset->sop031_results,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::STR_ENUM,	"sop031_ul_vul_iul_defn", -1, (size_t)&modelOffset->sop031_ul_vul_iul_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &sop031_ul_vul_iul_defnEnumList, Feature(true)),
	Descriptor(28, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(29, Attribute::SCALAR_INT,	"amortzn_period", -1, (size_t)&modelOffset->amortzn_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_amortzn_period)),
	Descriptor(30, Attribute::SCALAR_INT,	"comm_pct_fund_ult_index", -1, (size_t)&modelOffset->comm_pct_fund_ult_index,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_comm_pct_fund_ult_index)),
	Descriptor(31, Attribute::SCALAR_INT,	"final_period", -1, (size_t)&modelOffset->final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_final_period)),
	Descriptor(32, Attribute::SCALAR_DOUBLE,	"gaap_int_rate", -1, (size_t)&modelOffset->gaap_int_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gaap_int_rate)),
	Descriptor(33, Attribute::SCALAR_DOUBLE,	"gaap_int_rate_mthly", -1, (size_t)&modelOffset->gaap_int_rate_mthly,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_gaap_int_rate_mthly)),
	Descriptor(34, Attribute::SCALAR_DOUBLE,	"hedge_alloc_factor", -1, (size_t)&modelOffset->hedge_alloc_factor,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_hedge_alloc_factor)),
	Descriptor(35, Attribute::SCALAR_DOUBLE,	"host_accrual_rate", -1, (size_t)&modelOffset->host_accrual_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_host_accrual_rate)),
	Descriptor(36, Attribute::SCALAR_INT,	"pbr_final_period", -1, (size_t)&modelOffset->pbr_final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_pbr_final_period)),
	Descriptor(37, Attribute::SCALAR_INT,	"prem_term_period", -1, (size_t)&modelOffset->prem_term_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_prem_term_period)),
	Descriptor(38, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_proj_date_adj)),
	Descriptor(39, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_proj_start_date)),
	Descriptor(40, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_proj_start_mth)),
	Descriptor(41, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_proj_start_yr)),
	Descriptor(42, Attribute::SCALAR_INT,	"reins_flag", -1, (size_t)&modelOffset->reins_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_reins_flag)),
	Descriptor(43, Attribute::SCALAR_INT,	"sop031_flag", -1, (size_t)&modelOffset->sop031_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_sop031_flag)),
	Descriptor(44, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&SFAS97RD_GAAP_UDF::sfas97rd_gaap_start_period)),
	Descriptor(45, Attribute::SCALAR_STRING,	"state_of_world_financial_file_path", -1, (size_t)&modelOffset->state_of_world_financial_file_path,
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
	nullptr};
	const size_t SFAS97RD_GAAP::sDescriptorCount = 46;

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

	, adco(company_asset_adco)
	, asset(company_asset)
	, fia(company_liab_fia)
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
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(172, SFAS97RD_GAAP::descriptorTable, arrayPersistentObj), Variable(*this)

	, adco(company_asset_adco)
	, asset(company_asset)
	, fia(company_liab_fia)
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

#ifdef __CREATE_AA_COMP_COMP_CLASS_
       company = 0;
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
       company_asset = 0;
#endif
#ifdef __CREATE_ADCO_ASSET_CLASS_
       company_asset_adco = 0;
#endif
#ifdef __CREATE_LIAB_LIAB_CLASS_
       company_liab = 0;
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
       company_liab_fia = 0;
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

	for (int cf_no = 1; cf_no <= 172; cf_no++)
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

#ifdef __CREATE_AA_COMP_COMP_CLASS_
		company = (AA_COMP_COMP*)(findUnique("company"));
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
		company_asset = (ASSET_ASSET*)(findUnique("company|asset"));
#endif
#ifdef __CREATE_ADCO_ASSET_CLASS_
		company_asset_adco = (ADCO_ASSET*)(findUnique("company|asset|adco"));
#endif
#ifdef __CREATE_LIAB_LIAB_CLASS_
		company_liab = (LIAB_LIAB*)(findUnique("company|liab"));
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
		company_liab_fia = (FIA_LIAB*)(findUnique("company|liab|fia"));
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
BitArray SFAS97RD_GAAP::dataVariables(46);
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

