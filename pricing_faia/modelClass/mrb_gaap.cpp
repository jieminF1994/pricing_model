
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
#include "ModelClass\mrb_gaap_udf.h"
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

deptaskinput mrb_valn_input;
int MRB_PV_AB_CHG = 0;
int MRB_PV_IB_CHG = 1;
int MRB_PV_WB_CHG = 2;
int MRB_PV_DB_CHG = 3;
int MRB_PV_AB_CLAIM = 4;
int MRB_PV_IB_CLAIM = 5;
int MRB_PV_WB_CLAIM = 6;
int MRB_PV_DB_CLAIM = 7;
int MRB_FUND_VAL = 8;
int MRB_POLICIES_INF = 9;
int MRB_ARRAY_SIZE = 10;

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
#ifndef mrb_gaap_TableDefs
#define mrb_gaap_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection MRB_GAAP::TTHC;
void MRB_GAAP::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double MRB_GAAP_UDF::mrb_gaap_cal_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"cal_mth",t);
}



//^^^

#line 1 "cal_mth.MRB_GAAP.for"
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
double MRB_GAAP_UDF::mrb_gaap_cal_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"cal_yr",t);
}



//^^^

#line 1 "cal_yr.MRB_GAAP.for"
if (t == start_period)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}

//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double MRB_GAAP_UDF::mrb_gaap_cal_yr_relative(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(3,"cal_yr_relative",t);
}



//^^^

#line 1 "cal_yr_relative.MRB_GAAP.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}

//@@ END

//@@ START - credit_risk_col
// Credit Risk Column Calulation                                                                                             
// Column:CREDIT_RISK_COL
//========================================================
double MRB_GAAP_UDF::mrb_gaap_credit_risk_col(int t) {
//^^^



//^^^

#line 1 "credit_risk_col.MRB_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

return credit_risk;


}

//@@ END

//@@ START - date
// Date                                                                                             
// Column:DATE
//========================================================
double MRB_GAAP_UDF::mrb_gaap_date(int t) {
//^^^



//^^^

#line 1 "date.MRB_GAAP.for"
// This column is a lookup key for external sources varying by date
// The definition matches Excel = number of days since 1899
// The value is for the first day of the current month

int year = cal_yr(t);
int month = cal_mth(t);
int day = 1;

return day_number_from_date(year, month, day);


}

//@@ END

//@@ START - fund_val
// Fund Value                                                                                             
// Column:FUND_VAL
//========================================================
double MRB_GAAP_UDF::mrb_gaap_fund_val(int t) {
//^^^



//^^^

#line 1 "fund_val.MRB_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

{
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
	{
	if (!reins_flag) //Gross
		return va->fund_val(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured	
		return va->fund_val(t) * va->reins_pct;
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_MRB)
	{
	if (!reins_flag) //Gross
		return fia->fund_val_fixed(t);
	
	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured	
		return fia->fund_val_fixed(t) * fia->reins_pct;

	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
return NO_AVG;

}

//@@ END

//@@ START - gaap_int_rate
// GAAP Interest Rate                                                                                             
// Column:GAAP_INT_RATE
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gaap_int_rate(int t) {
//^^^



//^^^

#line 1 "gaap_int_rate.MRB_GAAP.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return pow(1.0 + rates_ptr->get_int_rate(t, "Govt", GET_SPOT_RATE, SHORT_TERM_RATE_TERM, 0, EFFECTIVE_ANNUAL, NO_SHIFT),
				(1.0 / 12.0)) - 1.0;

}

//@@ END

//@@ START - gmab_chg
// GMAB Charge                                                                                             
// Column:GMAB_CHG
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmab_chg(int t) {
//^^^



//^^^

#line 1 "gmab_chg.MRB_GAAP.for"
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
	{
	if (!reins_flag) //Gross
		return va->gmab_chg(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured	
		return va->reins_prem_gmab(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}

return NO_AVG;

}

//@@ END

//@@ START - gmab_claim
// GMAB Econ Claim                                                                                             
// Column:GMAB_CLAIM
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmab_claim(int t) {
//^^^



//^^^

#line 1 "gmab_claim.MRB_GAAP.for"
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
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

//@@ START - gmab_liab
// GMAB Liability                                                                                             
// Column:GMAB_LIAB
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmab_liab(int t) {
//^^^



//^^^

#line 1 "gmab_liab.MRB_GAAP.for"
if (valn_flag || t < start_period || t > final_period)
	return NO_AVG;

double fund_val_adj = 1.0;
double policies_inf_adj = 1.0;

if (fabs(fund_val(t)) < model_point_amount_threshold
	|| fabs(policies_inf(t)) < model_point_amount_threshold)
	return 0.0;

if (fabs(mrb_array[MRB_POLICIES_INF][t]) < model_point_amount_threshold)
	return 0.0;

fund_val_adj = mrb_array[MRB_FUND_VAL][t] / fund_val(t);
policies_inf_adj = policies_inf(t) / mrb_array[MRB_POLICIES_INF][t];

double gmab_liab = mrb_array[MRB_PV_AB_CLAIM][t]
                   - mrb_array[MRB_PV_AB_CHG][t]
				     * (1.0 - gmab_req_prof_chg(t));

return gmab_liab 
       * policies_inf_adj
	   * fund_val_adj;

}

//@@ END

//@@ START - gmab_req_prof_chg
// GMAB Required Profit Charge                                                                                             
// Column:GMAB_REQ_PROF_CHG
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmab_req_prof_chg(int t) {
//^^^



//^^^

#line 1 "gmab_req_prof_chg.MRB_GAAP.for"
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
	{
	if (t == start_period && va->elapsed_mths > 0)
		return va->gmab_mrb_req_prof_chg;

	// calculate for new issue
	if (t == start_period)
		{
		if (fabs(mrb_array[MRB_PV_AB_CHG][t]) < model_point_amount_threshold)
			return 0.0;

		return 1.0 - (mrb_array[MRB_PV_AB_CLAIM][t]
                      / mrb_array[MRB_PV_AB_CHG][t]);
		}
	}
#endif

return gmab_req_prof_chg(t - 1);

}

//@@ END

//@@ START - gmdb_chg
// GMDB Charge                                                                                             
// Column:GMDB_CHG
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmdb_chg(int t) {
//^^^



//^^^

#line 1 "gmdb_chg.MRB_GAAP.for"
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
	{
	if (!reins_flag) //Gross
		return va->gmdb_chg(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured	
		return va->reins_prem_gmdb(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}

return NO_AVG;

}

//@@ END

//@@ START - gmdb_claim
// GMDB Claim                                                                                             
// Column:GMDB_CLAIM
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmdb_claim(int t) {
//^^^



//^^^

#line 1 "gmdb_claim.MRB_GAAP.for"
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
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

//@@ START - gmdb_liab
// GMDB Liability                                                                                             
// Column:GMDB_LIAB
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmdb_liab(int t) {
//^^^



//^^^

#line 1 "gmdb_liab.MRB_GAAP.for"
if (valn_flag || t < start_period || t > final_period)
	return NO_AVG;

double fund_val_adj = 1.0;
double policies_inf_adj = 1.0;

if (fabs(fund_val(t)) < model_point_amount_threshold
	|| fabs(policies_inf(t)) < model_point_amount_threshold)
	return 0.0;

if (fabs(mrb_array[MRB_POLICIES_INF][t]) < model_point_amount_threshold)
	return 0.0;

fund_val_adj = mrb_array[MRB_FUND_VAL][t] / fund_val(t);
policies_inf_adj = policies_inf(t) / mrb_array[MRB_POLICIES_INF][t];

double gmdb_liab = mrb_array[MRB_PV_DB_CLAIM][t]
                   - mrb_array[MRB_PV_DB_CHG][t]
				     * (1.0 - gmdb_req_prof_chg(t));

return gmdb_liab 
       * policies_inf_adj
	   * fund_val_adj;

}

//@@ END

//@@ START - gmdb_req_prof_chg
// GMDB Required Profit Charge                                                                                             
// Column:GMDB_REQ_PROF_CHG
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmdb_req_prof_chg(int t) {
//^^^



//^^^

#line 1 "gmdb_req_prof_chg.MRB_GAAP.for"
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
	{
	if (t == start_period && va->elapsed_mths > 0)
		return va->gmdb_mrb_req_prof_chg;

	// calculate for new issue
	if (t == start_period)
		{
		if (fabs(mrb_array[MRB_PV_DB_CHG][t]) < model_point_amount_threshold)
			return 0.0;

		return 1.0 - (mrb_array[MRB_PV_DB_CLAIM][t]
                      / mrb_array[MRB_PV_DB_CHG][t]);
		}
	}
#endif

return gmdb_req_prof_chg(t - 1);

}

//@@ END

//@@ START - gmib_chg
// GMIB Charge                                                                                             
// Column:GMIB_CHG
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmib_chg(int t) {
//^^^



//^^^

#line 1 "gmib_chg.MRB_GAAP.for"
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
	{
	if (!reins_flag) //Gross
		return va->gmib_chg(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured	
		return va->reins_prem_gmib(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}

return NO_AVG;

}

//@@ END

//@@ START - gmib_claim
// GMIB Econ Claim                                                                                             
// Column:GMIB_CLAIM
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmib_claim(int t) {
//^^^



//^^^

#line 1 "gmib_claim.MRB_GAAP.for"
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
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

//@@ START - gmib_liab
// GMIB Liability                                                                                             
// Column:GMIB_LIAB
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmib_liab(int t) {
//^^^



//^^^

#line 1 "gmib_liab.MRB_GAAP.for"
if (valn_flag || t < start_period || t > final_period)
	return NO_AVG;

double fund_val_adj = 1.0;
double policies_inf_adj = 1.0;

if (fabs(fund_val(t)) < model_point_amount_threshold
	|| fabs(policies_inf(t)) < model_point_amount_threshold)
	return 0.0;

if (fabs(mrb_array[MRB_POLICIES_INF][t]) < model_point_amount_threshold)
	return 0.0;

fund_val_adj = mrb_array[MRB_FUND_VAL][t] / fund_val(t);
policies_inf_adj = policies_inf(t) / mrb_array[MRB_POLICIES_INF][t];

double gmib_liab = mrb_array[MRB_PV_IB_CLAIM][t]
                   - mrb_array[MRB_PV_IB_CHG][t]
				     * (1.0 - gmib_req_prof_chg(t));

return gmib_liab
       * policies_inf_adj
	   * fund_val_adj;

}

//@@ END

//@@ START - gmib_req_prof_chg
// GMIB Required Profit Charge                                                                                             
// Column:GMIB_REQ_PROF_CHG
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmib_req_prof_chg(int t) {
//^^^



//^^^

#line 1 "gmib_req_prof_chg.MRB_GAAP.for"
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
	{
	if (t == start_period && va->elapsed_mths > 0)
		return va->gmib_mrb_req_prof_chg;

	// calculate for new issue
	if (t == start_period)
		{
		if (fabs(mrb_array[MRB_PV_IB_CHG][t]) < model_point_amount_threshold)
			return 0.0;

		return 1.0 - (mrb_array[MRB_PV_IB_CLAIM][t]
                      / mrb_array[MRB_PV_IB_CHG][t]);
		}
	}
#endif

return gmib_req_prof_chg(t - 1);

}

//@@ END

//@@ START - gmwb_chg
// GMWB Charge                                                                                             
// Column:GMWB_CHG
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmwb_chg(int t) {
//^^^



//^^^

#line 1 "gmwb_chg.MRB_GAAP.for"
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
	{
	if (!reins_flag) //Gross
		return va->gmwb_chg(t);
	
	if (reins_flag && va->reins_flag) //Ceded and MP Reinsured
		return va->reins_prem_gmwb(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_MRB)
	{
	if (!reins_flag) //Gross
		return fia->gmwb_chg(t);
	
	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
		return fia->reins_prem_gmwb(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
return NO_AVG;

}

//@@ END

//@@ START - gmwb_claim
// GMWB Econ Claim                                                                                             
// Column:GMWB_CLAIM
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmwb_claim(int t) {
//^^^



//^^^

#line 1 "gmwb_claim.MRB_GAAP.for"
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
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
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_MRB)
	{
	if (!reins_flag) //Gross
		return fia->ann_claims_gmwb(t);
	
	if (reins_flag && fia->reins_flag) //Ceded and MP Reinsured
		return fia->reins_ann_claims_gmwb(t);
	
	//Ceded and MP Not Reinsured
	return 0.0;	
	}
#endif
}
return NO_AVG;

}

//@@ END

//@@ START - gmwb_liab
// GMWB Liability                                                                                             
// Column:GMWB_LIAB
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmwb_liab(int t) {
//^^^



//^^^

#line 1 "gmwb_liab.MRB_GAAP.for"
if (valn_flag || t < start_period || t > final_period)
	return NO_AVG;

double fund_val_adj = 1.0;
double policies_inf_adj = 1.0;

if (fabs(fund_val(t)) < model_point_amount_threshold
	|| fabs(policies_inf(t)) < model_point_amount_threshold)
	return 0.0;

if (fabs(mrb_array[MRB_POLICIES_INF][t]) < model_point_amount_threshold)
	return 0.0;

fund_val_adj = mrb_array[MRB_FUND_VAL][t] / fund_val(t);
policies_inf_adj = policies_inf(t) / mrb_array[MRB_POLICIES_INF][t];

double gmwb_liab = mrb_array[MRB_PV_WB_CLAIM][t]
                   - mrb_array[MRB_PV_WB_CHG][t]
				     * (1.0 - gmwb_req_prof_chg(t));

return gmwb_liab 
       * policies_inf_adj
	   * fund_val_adj;

}

//@@ END

//@@ START - gmwb_req_prof_chg
// GMWB Required Profit Charge                                                                                             
// Column:GMWB_REQ_PROF_CHG
//========================================================
double MRB_GAAP_UDF::mrb_gaap_gmwb_req_prof_chg(int t) {
//^^^



//^^^

#line 1 "gmwb_req_prof_chg.MRB_GAAP.for"
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
	{
	if (t == start_period && va->elapsed_mths > 0)
		return va->gmwb_mrb_req_prof_chg;

	// calculate for new issue
	if (t == start_period)
		{
		if (fabs(mrb_array[MRB_PV_WB_CHG][t]) < model_point_amount_threshold)
			return 0.0;

		return 1.0 - (mrb_array[MRB_PV_WB_CLAIM][t]
                      / mrb_array[MRB_PV_WB_CHG][t]);
		}
	}
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_MRB)
	{
	if (t == start_period && fia->elapsed_mths > 0)
		return fia->gmwb_mrb_req_prof_chg;

	// calculate for new issue
	if (t == start_period)
		{
		if (fabs(mrb_array[MRB_PV_WB_CHG][t]) < model_point_amount_threshold)
			return 0.0;

		return 1.0 - (mrb_array[MRB_PV_WB_CLAIM][t]
                      / mrb_array[MRB_PV_WB_CHG][t]);
		}
	}
#endif
}
return gmwb_req_prof_chg(t - 1);

}

//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double MRB_GAAP_UDF::mrb_gaap_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.MRB_GAAP.for"
if (t != 0)
	return NO_AVG;

if (!valn_flag)
	get_mrb_valn_results();

return 1.0;

}

//@@ END

//@@ START - policies_inf
// Policies In Force                                                                                             
// Column:POLICIES_INF
//========================================================
double MRB_GAAP_UDF::mrb_gaap_policies_inf(int t) {
//^^^



//^^^

#line 1 "policies_inf.MRB_GAAP.for"
if (t < start_period || t > final_period)
	return NO_AVG;

{
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
	return va->policies_inf(t);
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_MRB)
	return fia->policies_inf(t);
#endif
}
return NO_AVG;

}

//@@ END

//@@ START - pv_gmab_chg
// PV of GMAB Charges                                                                                             
// Column:PV_GMAB_CHG
//========================================================
double MRB_GAAP_UDF::mrb_gaap_pv_gmab_chg(int t) {
//^^^



//^^^

#line 1 "pv_gmab_chg.MRB_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

return (gmab_chg(t + 1)
		+ pv_gmab_chg(t + 1))
		/ (1.0 + gaap_int_rate(t + 1));

}

//@@ END

//@@ START - pv_gmab_claim
// PV of GMAB Claim                                                                                             
// Column:PV_GMAB_CLAIM
//========================================================
double MRB_GAAP_UDF::mrb_gaap_pv_gmab_claim(int t) {
//^^^



//^^^

#line 1 "pv_gmab_claim.MRB_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

if (!valn_flag)
	return mrb_array[MRB_PV_AB_CLAIM][t];

return (gmab_claim(t + 1)
		+ pv_gmab_claim(t + 1))
		/ (1.0 + gaap_int_rate(t + 1) + credit_risk_col(t + 1));

}

//@@ END

//@@ START - pv_gmdb_chg
// PV of GMDB Charges                                                                                             
// Column:PV_GMDB_CHG
//========================================================
double MRB_GAAP_UDF::mrb_gaap_pv_gmdb_chg(int t) {
//^^^



//^^^

#line 1 "pv_gmdb_chg.MRB_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

return (gmdb_chg(t + 1)
		+ pv_gmdb_chg(t + 1))
		/ (1.0 + gaap_int_rate(t + 1));

}

//@@ END

//@@ START - pv_gmdb_claim
// PV of GMDB Claim                                                                                             
// Column:PV_GMDB_CLAIM
//========================================================
double MRB_GAAP_UDF::mrb_gaap_pv_gmdb_claim(int t) {
//^^^



//^^^

#line 1 "pv_gmdb_claim.MRB_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

if (!valn_flag)
	return mrb_array[MRB_PV_DB_CLAIM][t];

return (gmdb_claim(t + 1)
		+ pv_gmdb_claim(t + 1))
		/ (1.0 + gaap_int_rate(t + 1) + credit_risk_col(t + 1));

}

//@@ END

//@@ START - pv_gmib_chg
// PV of GMIB Charges                                                                                             
// Column:PV_GMIB_CHG
//========================================================
double MRB_GAAP_UDF::mrb_gaap_pv_gmib_chg(int t) {
//^^^



//^^^

#line 1 "pv_gmib_chg.MRB_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

return (gmib_chg(t + 1)
		+ pv_gmib_chg(t + 1))
		/ (1.0 + gaap_int_rate(t + 1));

}

//@@ END

//@@ START - pv_gmib_claim
// PV of GMIB Claim                                                                                             
// Column:PV_GMIB_CLAIM
//========================================================
double MRB_GAAP_UDF::mrb_gaap_pv_gmib_claim(int t) {
//^^^



//^^^

#line 1 "pv_gmib_claim.MRB_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

if (!valn_flag)
	return mrb_array[MRB_PV_IB_CLAIM][t];

// sliding windows optimization
for (int i = t + 1; i < final_period; i++)
	gmib_claim(i);

return (gmib_claim(t + 1)
		+ pv_gmib_claim(t + 1))
		/ (1.0 + gaap_int_rate(t + 1) + credit_risk_col(t + 1));

}

//@@ END

//@@ START - pv_gmwb_chg
// PV of GMWB Charges                                                                                             
// Column:PV_GMWB_CHG
//========================================================
double MRB_GAAP_UDF::mrb_gaap_pv_gmwb_chg(int t) {
//^^^



//^^^

#line 1 "pv_gmwb_chg.MRB_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

return (gmwb_chg(t + 1)
		+ pv_gmwb_chg(t + 1))
		/ (1.0 + gaap_int_rate(t + 1));

}

//@@ END

//@@ START - pv_gmwb_claim
// PV of GMWB Claim                                                                                             
// Column:PV_GMWB_CLAIM
//========================================================
double MRB_GAAP_UDF::mrb_gaap_pv_gmwb_claim(int t) {
//^^^



//^^^

#line 1 "pv_gmwb_claim.MRB_GAAP.for"
if (t < start_period || t >= final_period)
	return NO_AVG;

if (!valn_flag)
	return mrb_array[MRB_PV_WB_CLAIM][t];

return (gmwb_claim(t + 1)
		+ pv_gmwb_claim(t + 1))
		/ (1.0 + gaap_int_rate(t + 1) + credit_risk_col(t + 1));

}

//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double MRB_GAAP_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.MRB_GAAP.for"
#if 0 // START_HEADER
#define __MRB_GAAP_H_
#endif // END_HEADER

#if 0 // START_EXTERNS
deptaskinput mrb_valn_input;
int MRB_PV_AB_CHG = 0;
int MRB_PV_IB_CHG = 1;
int MRB_PV_WB_CHG = 2;
int MRB_PV_DB_CHG = 3;
int MRB_PV_AB_CLAIM = 4;
int MRB_PV_IB_CLAIM = 5;
int MRB_PV_WB_CLAIM = 6;
int MRB_PV_DB_CLAIM = 7;
int MRB_FUND_VAL = 8;
int MRB_POLICIES_INF = 9;
int MRB_ARRAY_SIZE = 10;
#endif // END_EXTERNS

#if 0 // START_CLASS
xstring reins_defn;
SmartArray < SmartArray<double>> mrb_array;
bool first_time;

#if defined(__AA_COMP_COMP_H_)
RATES_ECONOMY /*modelobject_name: RATES*/ *rates_ptr;
#else
RATES_ECONOMY /*modelobject_name: FIA_RATES*/ *rates_ptr;
#endif
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
first_time = true;
#endif // END_CONSTRUCTOR

return 1.0;

}

//@@ END

//@@ START - final_period
// Final Period                                                                                             
// Calculated Variable:FINAL_PERIOD
//========================================================
int MRB_GAAP_UDF::mrb_gaap_final_period() {
//^^^


#line 1 "final_period.MRB_GAAP.for"
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
return va->maturity_period;
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_MRB)
	return fia->maturity_period;
#endif
}

return 0;

}

//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring MRB_GAAP_UDF::mrb_gaap_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.MRB_GAAP.for"
return add_mths_to_date(proj_date, valn_period);

}

//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int MRB_GAAP_UDF::mrb_gaap_proj_start_date() {
//^^^


#line 1 "proj_start_date.MRB_GAAP.for"
return day_number_from_date(proj_start_yr, proj_start_mth, 1);

}

//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int MRB_GAAP_UDF::mrb_gaap_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.MRB_GAAP.for"
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
int MRB_GAAP_UDF::mrb_gaap_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.MRB_GAAP.for"
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
int MRB_GAAP_UDF::mrb_gaap_reins_flag() {
//^^^


#line 1 "reins_flag.MRB_GAAP.for"
// First dimension of mrb determines the reinsurance definition
// 	   Element 0 = Gross
//		Element 1 = Ceded

return getElementNumber();

}

//@@ END

//@@ START - start_period
// Start Period                                                                                             
// Calculated Variable:START_PERIOD
//========================================================
int MRB_GAAP_UDF::mrb_gaap_start_period() {
//^^^


#line 1 "start_period.MRB_GAAP.for"
{
#if defined(__VA_LIAB_H_)
if (model_name == VA_MRB)
return va->start_period;
#endif
}
{
#if defined(__FIA_LIAB_H_)
if (model_name == FIA_MRB)
	return fia->start_period;
#endif
}

return 0;

}

//@@ END


#line 1 "get_mrb_valn_results.MRB_GAAP.for"                                                                                   
void MRB_GAAP::get_mrb_valn_results(void)
{
xstring file_name = xstring(replaceWildcards(mrb_results));
static bool first_time = true;

if (mrb_array.size() < MRB_ARRAY_SIZE)
	{
	mrb_array.resize(MRB_ARRAY_SIZE);

	for (int i = 0; i < MRB_ARRAY_SIZE; i++)
		mrb_array[i].resize(last_proj_period + 1);
	}

for (int i = 0; i < MRB_ARRAY_SIZE; i++)
	{
	for (int j = 0; j < last_proj_period + 1; j++)
		mrb_array[i][j] = 0.0;		
	}

// Important: Must initialize arrays even if no valuation results are included
if (mrb_results == "NONE")
	return;

if (first_time)
	{
	first_time = false;

	OutputFileReader ofr;
	mrb_valn_input = ofr.readFile(file_name.getStdStr(), 
								  {"task_loop", "group", "period", "pv_gmab_chg", "pv_gmib_chg", "pv_gmwb_chg", "pv_gmdb_chg",
								   "pv_gmab_claim", "pv_gmib_claim", "pv_gmwb_claim", "pv_gmdb_claim", "fund_val", "policies_inf"});

	if (!mrb_valn_input.size())
		{
		throw FatalError("Could not read MRB valuation file: " 
			              + file_name + " "
			              + "Please check your data.");
		}
	}

xstring group_name = get_base_group_name(group, true);

int period = 0;
int task_loop_counter = 0;

for (int row = 0; row < mrb_valn_input.size(); row++)
	{
	if (!eq(mrb_valn_input[row][1], group_name))
		continue;
	
	if (eq(mrb_valn_input[row][2], ""))//blank period signifies a PV or IRR column
		continue;

	period = atoi(mrb_valn_input[row][2].c_str());

	if (period == 0)
		task_loop_counter += 1;

	if (period < last_proj_period + 1)
		{
		mrb_array[MRB_PV_AB_CHG][period] += atof(mrb_valn_input[row][3].c_str());
		mrb_array[MRB_PV_IB_CHG][period] += atof(mrb_valn_input[row][4].c_str());
		mrb_array[MRB_PV_WB_CHG][period] += atof(mrb_valn_input[row][5].c_str());
		mrb_array[MRB_PV_DB_CHG][period] += atof(mrb_valn_input[row][6].c_str());
		mrb_array[MRB_PV_AB_CLAIM][period] += atof(mrb_valn_input[row][7].c_str());
		mrb_array[MRB_PV_IB_CLAIM][period] += atof(mrb_valn_input[row][8].c_str());
		mrb_array[MRB_PV_WB_CLAIM][period] += atof(mrb_valn_input[row][9].c_str());
		mrb_array[MRB_PV_DB_CLAIM][period] += atof(mrb_valn_input[row][10].c_str());
		mrb_array[MRB_FUND_VAL][period] += atof(mrb_valn_input[row][11].c_str());
		mrb_array[MRB_POLICIES_INF][period] += atof(mrb_valn_input[row][12].c_str());
		}
	}

int proj_task_loops = task_loop_counter;

if (proj_task_loops > 0)
	{
	for (period = 0; period < last_proj_period + 1; period++)
		{
		mrb_array[MRB_PV_AB_CHG][period] /= proj_task_loops;
		mrb_array[MRB_PV_IB_CHG][period] /= proj_task_loops;
		mrb_array[MRB_PV_WB_CHG][period] /= proj_task_loops;
		mrb_array[MRB_PV_DB_CHG][period] /= proj_task_loops;
		mrb_array[MRB_PV_AB_CLAIM][period] /= proj_task_loops;
		mrb_array[MRB_PV_IB_CLAIM][period] /= proj_task_loops;
		mrb_array[MRB_PV_WB_CLAIM][period] /= proj_task_loops;
		mrb_array[MRB_PV_DB_CLAIM][period] /= proj_task_loops;
		mrb_array[MRB_FUND_VAL][period] /= proj_task_loops;
		mrb_array[MRB_POLICIES_INF][period] /= proj_task_loops;
		}
	}	
}



	static MRB_GAAP_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (MRB_GAAP_UDF::*dPXi) (int);
typedef double (MRB_GAAP_UDF::*dPXid) (int, double);
typedef double (MRB_GAAP_UDF::*dPF) ();
typedef double (MRB_GAAP_UDF::*dPFd) (double);
typedef int (MRB_GAAP_UDF::*iPF) ();
typedef int (MRB_GAAP_UDF::*iPFi) (int);
typedef xstring (MRB_GAAP_UDF::*sPF) ();
typedef xstring (MRB_GAAP_UDF::*sPFs) (xstring);

const CashFlowCommonData MRB_GAAP::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "cal_mth", "mrb_gaap_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(2, "cal_yr", "mrb_gaap_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(3, "cal_yr_relative", "mrb_gaap_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(4, "credit_risk_col", "mrb_gaap_credit_risk_col",  "credit_risk_col",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_credit_risk_col, 'E','N', '3', 'P', (size_t)&modelOffset->credit_risk_col),
	CashFlowCommonData(5, "date", "mrb_gaap_date",  "date",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(6, "fund_val", "mrb_gaap_fund_val",  "fund_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_fund_val, 'E','Y', '3', 'P', (size_t)&modelOffset->fund_val),
	CashFlowCommonData(7, "gaap_int_rate", "mrb_gaap_gaap_int_rate",  "gaap_int_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gaap_int_rate, 'E','N', '3', 'P', (size_t)&modelOffset->gaap_int_rate),
	CashFlowCommonData(8, "gmab_chg", "mrb_gaap_gmab_chg",  "gmab_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmab_chg, 'E','N', '3', 'P', (size_t)&modelOffset->gmab_chg),
	CashFlowCommonData(9, "gmab_claim", "mrb_gaap_gmab_claim",  "gmab_claim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmab_claim, 'E','N', '3', 'P', (size_t)&modelOffset->gmab_claim),
	CashFlowCommonData(10, "gmab_liab", "mrb_gaap_gmab_liab",  "gmab_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmab_liab, 'E','N', '3', 'P', (size_t)&modelOffset->gmab_liab),
	CashFlowCommonData(11, "gmab_req_prof_chg", "mrb_gaap_gmab_req_prof_chg",  "gmab_req_prof_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmab_req_prof_chg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_req_prof_chg),
	CashFlowCommonData(12, "gmdb_chg", "mrb_gaap_gmdb_chg",  "gmdb_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmdb_chg, 'E','N', '3', 'P', (size_t)&modelOffset->gmdb_chg),
	CashFlowCommonData(13, "gmdb_claim", "mrb_gaap_gmdb_claim",  "gmdb_claim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmdb_claim, 'E','N', '3', 'P', (size_t)&modelOffset->gmdb_claim),
	CashFlowCommonData(14, "gmdb_liab", "mrb_gaap_gmdb_liab",  "gmdb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmdb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->gmdb_liab),
	CashFlowCommonData(15, "gmdb_req_prof_chg", "mrb_gaap_gmdb_req_prof_chg",  "gmdb_req_prof_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmdb_req_prof_chg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmdb_req_prof_chg),
	CashFlowCommonData(16, "gmib_chg", "mrb_gaap_gmib_chg",  "gmib_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmib_chg, 'E','N', '3', 'P', (size_t)&modelOffset->gmib_chg),
	CashFlowCommonData(17, "gmib_claim", "mrb_gaap_gmib_claim",  "gmib_claim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmib_claim, 'E','N', '3', 'P', (size_t)&modelOffset->gmib_claim),
	CashFlowCommonData(18, "gmib_liab", "mrb_gaap_gmib_liab",  "gmib_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmib_liab, 'E','N', '3', 'P', (size_t)&modelOffset->gmib_liab),
	CashFlowCommonData(19, "gmib_req_prof_chg", "mrb_gaap_gmib_req_prof_chg",  "gmib_req_prof_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmib_req_prof_chg, 'E','N', '3', 'P', (size_t)&modelOffset->gmib_req_prof_chg),
	CashFlowCommonData(20, "gmwb_chg", "mrb_gaap_gmwb_chg",  "gmwb_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmwb_chg, 'E','N', '3', 'P', (size_t)&modelOffset->gmwb_chg),
	CashFlowCommonData(21, "gmwb_claim", "mrb_gaap_gmwb_claim",  "gmwb_claim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmwb_claim, 'E','N', '3', 'P', (size_t)&modelOffset->gmwb_claim),
	CashFlowCommonData(22, "gmwb_liab", "mrb_gaap_gmwb_liab",  "gmwb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmwb_liab, 'E','N', '3', 'P', (size_t)&modelOffset->gmwb_liab),
	CashFlowCommonData(23, "gmwb_req_prof_chg", "mrb_gaap_gmwb_req_prof_chg",  "gmwb_req_prof_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_gmwb_req_prof_chg, 'E','N', '3', 'P', (size_t)&modelOffset->gmwb_req_prof_chg),
	CashFlowCommonData(24, "initialize", "mrb_gaap_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(25, "policies_inf", "mrb_gaap_policies_inf",  "policies_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_policies_inf, 'E','Y', '3', 'P', (size_t)&modelOffset->policies_inf),
	CashFlowCommonData(26, "pv_gmab_chg", "mrb_gaap_pv_gmab_chg",  "pv_gmab_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_pv_gmab_chg, 'E','N', '3', 'P', (size_t)&modelOffset->pv_gmab_chg),
	CashFlowCommonData(27, "pv_gmab_claim", "mrb_gaap_pv_gmab_claim",  "pv_gmab_claim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_pv_gmab_claim, 'E','N', '3', 'P', (size_t)&modelOffset->pv_gmab_claim),
	CashFlowCommonData(28, "pv_gmdb_chg", "mrb_gaap_pv_gmdb_chg",  "pv_gmdb_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_pv_gmdb_chg, 'E','N', '3', 'P', (size_t)&modelOffset->pv_gmdb_chg),
	CashFlowCommonData(29, "pv_gmdb_claim", "mrb_gaap_pv_gmdb_claim",  "pv_gmdb_claim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_pv_gmdb_claim, 'E','N', '3', 'P', (size_t)&modelOffset->pv_gmdb_claim),
	CashFlowCommonData(30, "pv_gmib_chg", "mrb_gaap_pv_gmib_chg",  "pv_gmib_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_pv_gmib_chg, 'E','N', '3', 'P', (size_t)&modelOffset->pv_gmib_chg),
	CashFlowCommonData(31, "pv_gmib_claim", "mrb_gaap_pv_gmib_claim",  "pv_gmib_claim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_pv_gmib_claim, 'E','N', '3', 'P', (size_t)&modelOffset->pv_gmib_claim),
	CashFlowCommonData(32, "pv_gmwb_chg", "mrb_gaap_pv_gmwb_chg",  "pv_gmwb_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_pv_gmwb_chg, 'E','N', '3', 'P', (size_t)&modelOffset->pv_gmwb_chg),
	CashFlowCommonData(33, "pv_gmwb_claim", "mrb_gaap_pv_gmwb_claim",  "pv_gmwb_claim",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::mrb_gaap_pv_gmwb_claim, 'E','N', '3', 'P', (size_t)&modelOffset->pv_gmwb_claim),
	CashFlowCommonData(34, "startup", "mrb_gaap_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&MRB_GAAP_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup)
};
const CashFlowCommonData* MRB_GAAP::mCFStaticData[] = {
	&MRB_GAAP::mCFStaticData_0[0],
	&MRB_GAAP::mCFStaticData_0[1],
	&MRB_GAAP::mCFStaticData_0[2],
	&MRB_GAAP::mCFStaticData_0[3],
	&MRB_GAAP::mCFStaticData_0[4],
	&MRB_GAAP::mCFStaticData_0[5],
	&MRB_GAAP::mCFStaticData_0[6],
	&MRB_GAAP::mCFStaticData_0[7],
	&MRB_GAAP::mCFStaticData_0[8],
	&MRB_GAAP::mCFStaticData_0[9],
	&MRB_GAAP::mCFStaticData_0[10],
	&MRB_GAAP::mCFStaticData_0[11],
	&MRB_GAAP::mCFStaticData_0[12],
	&MRB_GAAP::mCFStaticData_0[13],
	&MRB_GAAP::mCFStaticData_0[14],
	&MRB_GAAP::mCFStaticData_0[15],
	&MRB_GAAP::mCFStaticData_0[16],
	&MRB_GAAP::mCFStaticData_0[17],
	&MRB_GAAP::mCFStaticData_0[18],
	&MRB_GAAP::mCFStaticData_0[19],
	&MRB_GAAP::mCFStaticData_0[20],
	&MRB_GAAP::mCFStaticData_0[21],
	&MRB_GAAP::mCFStaticData_0[22],
	&MRB_GAAP::mCFStaticData_0[23],
	&MRB_GAAP::mCFStaticData_0[24],
	&MRB_GAAP::mCFStaticData_0[25],
	&MRB_GAAP::mCFStaticData_0[26],
	&MRB_GAAP::mCFStaticData_0[27],
	&MRB_GAAP::mCFStaticData_0[28],
	&MRB_GAAP::mCFStaticData_0[29],
	&MRB_GAAP::mCFStaticData_0[30],
	&MRB_GAAP::mCFStaticData_0[31],
	&MRB_GAAP::mCFStaticData_0[32],
	&MRB_GAAP::mCFStaticData_0[33],
	&MRB_GAAP::mCFStaticData_0[34],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for model_name                                                                                       
	const ChoicePair model_nameChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FIA_MRB, "fia_mrb")
		,ChoicePair(StrEnum::VA_MRB, "va_mrb")
	};
	const EnumList model_nameEnumList(2, model_nameChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace MRB_GAAP_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(MRB_GAAP::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(MRB_GAAP::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace MRB_GAAP_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void MRB_GAAP::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> MRB_GAAP::mgr_;

	Attribute::Descriptor MRB_GAAP::descriptor_0[] = {
	Descriptor(0, Attribute::DOUBLE,	"credit_risk", Descriptor::NOT_INDEXED, (size_t)&modelOffset->credit_risk,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::STR_ENUM,	"model_name", -1, (size_t)&modelOffset->model_name,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &model_nameEnumList, Feature(true)),
	Descriptor(2, Attribute::STRING,	"mrb_results", -1, (size_t)&modelOffset->mrb_results,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::SCALAR_INT,	"final_period", -1, (size_t)&modelOffset->final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MRB_GAAP_UDF::mrb_gaap_final_period)),
	Descriptor(6, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&MRB_GAAP_UDF::mrb_gaap_proj_date_adj)),
	Descriptor(7, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MRB_GAAP_UDF::mrb_gaap_proj_start_date)),
	Descriptor(8, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MRB_GAAP_UDF::mrb_gaap_proj_start_mth)),
	Descriptor(9, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MRB_GAAP_UDF::mrb_gaap_proj_start_yr)),
	Descriptor(10, Attribute::SCALAR_INT,	"reins_flag", -1, (size_t)&modelOffset->reins_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MRB_GAAP_UDF::mrb_gaap_reins_flag)),
	Descriptor(11, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&MRB_GAAP_UDF::mrb_gaap_start_period)),
	};

	Attribute::Descriptor* MRB_GAAP::descriptorTable[] = {
	&MRB_GAAP::descriptor_0[0],
	&MRB_GAAP::descriptor_0[1],
	&MRB_GAAP::descriptor_0[2],
	&MRB_GAAP::descriptor_0[3],
	&MRB_GAAP::descriptor_0[4],
	&MRB_GAAP::descriptor_0[5],
	&MRB_GAAP::descriptor_0[6],
	&MRB_GAAP::descriptor_0[7],
	&MRB_GAAP::descriptor_0[8],
	&MRB_GAAP::descriptor_0[9],
	&MRB_GAAP::descriptor_0[10],
	&MRB_GAAP::descriptor_0[11],
	nullptr};
	const size_t MRB_GAAP::sDescriptorCount = 12;

//factory
MRB_GAAP* MRB_GAAP::makeThis(int isSubmodel, ModelClass* owner, MRB_GAAP* peer, 
						int mainRebase, const xstring &name, MRB_GAAP_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("MRB_GAAP::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor MRB_GAAP");
#endif
	MRB_GAAP* newP = (MRB_GAAP*)new MRB_GAAP_UDF
   	  ("mrb_gaap", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
MRB_GAAP_persistent_object* MRB_GAAP_persistent_object::makeThis(int isSubmodel, ModelClass* owner, MRB_GAAP* peer, 
							int mainRebase, const xstring &name, MRB_GAAP_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("MRB_GAAP_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor MRB_GAAP_persistent_object");
#endif
	MRB_GAAP_persistent_object* newP = (MRB_GAAP_persistent_object*)new MRB_GAAP_persistent_object
   	  ("mrb_gaap", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			MRB_GAAP_persistent_object* pd = dynamic_cast<MRB_GAAP_persistent_object*>(product);
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

typedef double (MRB_GAAP_UDF::*dPF) ();
typedef double (MRB_GAAP_UDF::*dPFd) (double);
typedef int (MRB_GAAP_UDF::*iPF) ();
typedef int (MRB_GAAP_UDF::*iPFi) (int);
typedef xstring (MRB_GAAP_UDF::*sPF) ();
typedef xstring (MRB_GAAP_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
MRB_GAAP::MRB_GAAP(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)

	, adco(company_asset_adco)
	, asset(company_asset)
	, fia(company_liab_fia)
	, fia_mrb(company_liab_fia_fia_mrb)
	, fia_rates(company_liab_fia_fia_rates)
	, liab(company_liab)
	, rates(company_rates)
	, seg(company_seg)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (MRB_GAAP_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
MRB_GAAP::MRB_GAAP(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(34, MRB_GAAP::descriptorTable, arrayPersistentObj), Variable(*this)

	, adco(company_asset_adco)
	, asset(company_asset)
	, fia(company_liab_fia)
	, fia_mrb(company_liab_fia_fia_mrb)
	, fia_rates(company_liab_fia_fia_rates)
	, liab(company_liab)
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
#ifdef __CREATE_LIAB_LIAB_CLASS_
       company_liab = 0;
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
       company_liab_fia = 0;
#endif
#ifdef __CREATE_MRB_GAAP_CLASS_
       company_liab_fia_fia_mrb = 0;
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

	for (int cf_no = 1; cf_no <= 34; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (MRB_GAAP_UDF::*dPXi2) (int, int);
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


 void MRB_GAAP::copy_names() {

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
#ifdef __CREATE_MRB_GAAP_CLASS_
		company_liab_fia_fia_mrb = (MRB_GAAP*)(findUnique("company|liab|fia|fia_mrb"));
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


 void MRB_GAAP::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int MRB_GAAP_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& MRB_GAAP_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double MRB_GAAP_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int MRB_GAAP_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double MRB_GAAP_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double MRB_GAAP_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void MRB_GAAP_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void MRB_GAAP_persistent_object::write(long include_submodels) {
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

	void MRB_GAAP_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void MRB_GAAP_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void MRB_GAAP_persistent_object::write(const xstring& key, long include_submodels) {
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




	MRB_GAAP_persistent_object::~MRB_GAAP_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool MRB_GAAP_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void MRB_GAAP_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void MRB_GAAP_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void MRB_GAAP_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void MRB_GAAP_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void MRB_GAAP_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* MRB_GAAP_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* MRB_GAAP_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* MRB_GAAP_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char MRB_GAAP_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void MRB_GAAP_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
MRB_GAAP_persistent_object::MRB_GAAP_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			MRB_GAAP(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
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
MRB_GAAP::~MRB_GAAP() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void MRB_GAAP::findTargetColumns() {

}
//findTargetColumns END@2
void MRB_GAAP::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void MRB_GAAP::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void MRB_GAAP::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void MRB_GAAP::start_of_projection() {
}
//start_of_projection END@2

void MRB_GAAP::end_of_projection() {
}
//end_of_projection END@2

void MRB_GAAP::start_of_layer() {
}


void MRB_GAAP::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void MRB_GAAP::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void MRB_GAAP::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void MRB_GAAP::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> MRB_GAAP::ddfVector;
BitArray MRB_GAAP::dataVariables(12);
bool MRB_GAAP::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool MRB_GAAP::writeClassInfo = true;

void MRB_GAAP::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, MRB_GAAP::descriptor_0>::dT = MRB_GAAP::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, MRB_GAAP::descriptor_0>::dT = MRB_GAAP::descriptor_0;

