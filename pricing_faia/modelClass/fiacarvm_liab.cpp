
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
#include "ModelClass\fiacarvm_liab_udf.h"
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

extern SmartArray <SmartArray <double> > fia_cost_array(0);

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
#ifndef fiacarvm_liab_TableDefs
#define fiacarvm_liab_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection FIACARVM_LIAB::TTHC;
void FIACARVM_LIAB::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - admin_fee
// Administration Fee                                                                                             
// Column:ADMIN_FEE
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_admin_fee(int t) {
//^^^



//^^^

#line 1 "admin_fee.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)
	return NO_AVG;

if (t == 1 && fabs(12.0 - mths_in_first_period) > model_point_amount_threshold)
	return NO_AVG;

return min(fund_val_aft_pfwd(t - 1), fia->admin_fee_per_pol * fia->policies_inf(res_period));

}

//@@ END

//@@ START - age_last
// Age Last Birthday at Policy Anniversary                                                                                             
// Column:AGE_LAST
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_age_last(int t) {
//^^^



//^^^

#line 1 "age_last.FIACARVM_LIAB.for"
if (t < 0)
	return NO_AVG;
     
if (t == 0)
	return fia->age_last(res_period);

if (t == 1)
	{
	if (fabs(12.0 - mths_in_first_period) < model_point_amount_threshold)
		return age_last(t - 1) + 1.0;

	return age_last(t - 1);
	}

return age_last(t - 1) + 1.0;

}

//@@ END

//@@ START - ann_benefits
// Annuity Benefits                                                                                             
// Column:ANN_BENEFITS
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_ann_benefits(int t) {
//^^^



//^^^

#line 1 "ann_benefits.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

if (carvm_calc_annuitzn_defn == NOT_APPLICABLE)
	return NO_AVG;

double ann_benefits_curr_basis = 0.0;
double ann_benefits_guar_basis = 0.0;

if (t == 0 && carvm_calc_annuitzn_defn == CURRENT_AND_GUARANTEED_BENEFITS)
	{
	if (fabs(ann_purch_factor_curr(t)) > rate_ratio_threshold)
		ann_benefits_curr_basis
		= (fund_val_aft_pfwd(t) * (1.0 - fia->purch_rate_curr_load)
		   - fia->purch_rate_curr_pol_fee * fia->policies_inf(res_period))
		   / ann_purch_factor_curr(t);
	}

if (fabs(ann_purch_factor_guar(t)) > rate_ratio_threshold)
	ann_benefits_guar_basis
	= fund_val_aft_pfwd(t) / ann_purch_factor_guar(t);

return max(ann_benefits_curr_basis, ann_benefits_guar_basis);

}

//@@ END

//@@ START - ann_benefits_pv
// PV of Annuitization Benefits                                                                                             
// Column:ANN_BENEFITS_PV
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_ann_benefits_pv(int t) {
//^^^



//^^^

#line 1 "ann_benefits_pv.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

if (carvm_calc_annuitzn_defn == NOT_APPLICABLE)
	return NO_AVG;

return ann_benefits(t) * ann_valn_factor(t) * carvm_disc_factor_elect_annuitzn(t) * surv(t);



}

//@@ END

//@@ START - ann_purch_factor_curr
// Annuity Factor Current Basis                                                                                             
// Column:ANN_PURCH_FACTOR_CURR
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_ann_purch_factor_curr(int t) {
//^^^



//^^^

#line 1 "ann_purch_factor_curr.FIACARVM_LIAB.for"
if (t != 0)
	return NO_AVG;

if (carvm_calc_annuitzn_defn == GUARANTEED_BENEFITS || carvm_calc_annuitzn_defn == NOT_APPLICABLE)
	return NO_AVG;

double ann_rate = 0.0;
double ann_factor_certain = 0.0;
double ann_factor_endow = 0.0;
double ann_factor_deferred_life = 0.0;
double ann_factor = 0.0;

// Calculate certain factor 
if (fia->purch_rate_curr_defn == FIXED_RATE)
	{
	ann_rate = fia->purch_rate_curr_fixed;
	ann_factor_certain = a_angle_n(ann_rate, carvm_annuitzn_certain_yrs);
	}
else // Run loop since current rate can change during benefit period based on spread
	{
	double disc_factor = 1.0;
	for (int yr = 1; yr <= carvm_annuitzn_certain_yrs; yr++)
		{
		ann_rate = fia->get_comp_rate(fia->purch_rate_curr_comp_rate_id, res_period) - purch_rate_curr_sprd(yr);
		disc_factor /= (1.0 + ann_rate);
		ann_factor_certain += disc_factor; 
		}
	}
 
 // Calculate endowment factor and deferred life factor, if required
if (carvm_annuitzn_ann_type == CERTAIN_AND_LIFE_ANNUITY)
	{
	int yr_counter = 0.0;
	double surv_period = 0.0;
	double surv = 1.0;
	double disc_factor = 1.0;
	double disc_amt = 0.0;

	while (fabs(surv) > rate_ratio_threshold)
		{
		yr_counter += 1;
		 
		// Determine annuity discount rate
		if (fia->purch_rate_curr_defn == FIXED_RATE)
			ann_rate = fia->purch_rate_curr_fixed;
		else
			{
			// Set lookup key
			ann_rate = fia->get_comp_rate(fia->purch_rate_curr_comp_rate_id, res_period) - purch_rate_curr_sprd(yr_counter);
			}

		if (fabs(12.0 - mths_in_first_period) > model_point_amount_threshold)
			surv_period = (1.0 - mort_rate_ann_purch_curr(t + yr_counter));
		else	
			surv_period = (1.0 - mort_rate_ann_purch_curr(t + yr_counter - 1));
		
		surv *= surv_period;

		disc_factor /= (1.0 + ann_rate);

		if (yr_counter == carvm_annuitzn_certain_yrs)
			{
			ann_factor_endow = disc_factor * surv;

			// Reset disc_rate and surv for deferred annuity calculation
			disc_factor = 1.0;
			surv = 1.0;	
			}

		if (yr_counter > carvm_annuitzn_certain_yrs)
			{
			disc_amt = disc_factor * surv;
			ann_factor_deferred_life += disc_amt;
			}	
		}
	}

ann_factor = ann_factor_certain + ann_factor_endow * ann_factor_deferred_life;

return ann_factor;

}

//@@ END

//@@ START - ann_purch_factor_guar
// Annuity Factor Guaranteed Basis                                                                                             
// Column:ANN_PURCH_FACTOR_GUAR
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_ann_purch_factor_guar(int t) {
//^^^



//^^^

#line 1 "ann_purch_factor_guar.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

if (carvm_calc_annuitzn_defn == NOT_APPLICABLE)
	return NO_AVG;

static int attained_age_saved = 0;
static double ann_factor_certain_prev = 0.0;
static double ann_factor_endow_prev = 0.0;
static double ann_factor_deferred_life_prev = 0.0;
double ann_rate = 0.0;
double ann_factor_certain = 0.0;
double ann_factor_endow = 0.0;
double ann_factor_deferred_life = 0.0;
double ann_factor = 0.0;

// Guaranteed purchase rate is always a fixed rate
ann_rate = fia->purch_rate_guar_fixed;

// Perform full calculation at t == 0
if (t == 0)
	{
	// Calculate certain factor
	ann_factor_certain = a_angle_n(ann_rate, carvm_annuitzn_certain_yrs); 

	// Calculate endowment factor and deferred life factor
	if (carvm_annuitzn_ann_type == CERTAIN_AND_LIFE_ANNUITY)
		{
		int yr_counter = 0.0;
		double surv_period = 0.0;
		double surv = 1.0;
		double disc_factor = 1.0;
		double disc_amt = 0.0;
		ann_factor_deferred_life = 0.0;

		while (fabs(surv) > rate_ratio_threshold)
			{
			yr_counter += 1;
		 
			 // Determine mortality rate for life 1 and life2
			if (fabs(12.0 - mths_in_first_period) > model_point_amount_threshold)
				surv_period = (1.0 - mort_rate_ann_purch_guar(t + yr_counter));
			else	
				surv_period = (1.0 - mort_rate_ann_purch_guar(t + yr_counter - 1));

			surv *= surv_period;

			disc_factor /= (1.0 + ann_rate);

			if (yr_counter == carvm_annuitzn_certain_yrs)
				{
				ann_factor_endow = disc_factor * surv;

				// reset disc_rate and surv for deferred annuity calculation
				disc_factor = 1.0;
				surv = 1.0;	
				}

			if (yr_counter > carvm_annuitzn_certain_yrs)
				{
				disc_amt = disc_factor * surv;
				ann_factor_deferred_life += disc_amt;
				}
			}
		}

	ann_factor = ann_factor_certain + ann_factor_endow * ann_factor_deferred_life;
	}
else // use recursive calculation
	{
	if (fabs(attained_age(t) - attained_age_saved) < model_point_amount_threshold)
		{
		ann_factor_certain = ann_factor_certain_prev;
		ann_factor_endow = ann_factor_endow_prev;
		ann_factor_deferred_life = ann_factor_deferred_life_prev;
		}
	else
	    {
		// Calculate certain factor
		ann_factor_certain = ann_factor_certain_prev;

		// Calculate endowment factor and deferred life factor, if required
		if (carvm_annuitzn_ann_type == CERTAIN_AND_LIFE_ANNUITY)
			{
			double mort_rate_life1 = 0.0;
			double mort_rate_life2 = 0.0;
			double mort_rate = 0.0;
			double surv_period_attained_age = 0.0;
			double surv_period_deferred_age = 0.0;
			double disc_factor = 1.0 / (1.0 + ann_rate);
	 
			// run two loops, one to get surv_period_attained_age and one to get surv_period_deferred_age
			for (int loop = 0; loop < 2; loop++) 
				{
			
				// Set adjusted lookup keys
				if (loop == 1)
					surv_period_deferred_age = (1.0 - mort_rate_ann_purch_guar(t + carvm_annuitzn_certain_yrs - 1));

               if (loop == 0 )
					surv_period_attained_age = (1.0 - mort_rate_ann_purch_guar(t - 1));
				}								
	
			if (fabs(surv_period_attained_age) > rate_ratio_threshold)
				ann_factor_endow = ann_factor_endow_prev / surv_period_attained_age * surv_period_deferred_age;
			else
				ann_factor_endow = 0.0;

			if (fabs(surv_period_deferred_age) > rate_ratio_threshold)
				ann_factor_deferred_life = ann_factor_deferred_life_prev / (disc_factor * surv_period_deferred_age) - 1.0;
			else
				ann_factor_deferred_life = 0.0;
			}
		}
	}

// save values for recursive guaranteed calculations
attained_age_saved = attained_age(t);
ann_factor_certain_prev = ann_factor_certain;
ann_factor_endow_prev = ann_factor_endow;
ann_factor_deferred_life_prev = ann_factor_deferred_life;

ann_factor = ann_factor_certain + ann_factor_endow * ann_factor_deferred_life;

return ann_factor;

}

//@@ END

//@@ START - ann_valn_factor
// Annuity Valuation Factor                                                                                             
// Column:ANN_VALN_FACTOR
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_ann_valn_factor(int t) {
//^^^



//^^^

#line 1 "ann_valn_factor.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

if (carvm_calc_annuitzn_defn == NOT_APPLICABLE)
	return NO_AVG;

static int attained_age_saved = 0;
static double ann_rate_saved = 0.0;
static double ann_factor_certain_prev = 0.0;
static double ann_factor_endow_prev = 0.0;
static double ann_factor_deferred_life_prev = 0.0;
double ann_rate = 0.0;
double ann_factor_certain = 0.0;
double ann_factor_endow = 0.0;
double ann_factor_deferred_life = 0.0;
double ann_factor = 0.0;

// Set hidden lookup keys for carvm_int_rate
valn_guar_dur = pol_yr(t);
valn_plan_type = valn_rate_plan_type_elective_annuitzn;
ann_rate = carvm_int_rate;

// Set mortality table lookup keys
// Set life1 lookup keys - special lookup keys are required for mortality variables
mort_gender = xstring(gender);
mort_issue_age = issue_age;
mort_attained_age = attained_age(t);
mort_pol_yr = pol_yr(t);

// Perform full calculation at t == 0 and when valuation rate changes
if (t == 0 || fabs(ann_rate - ann_rate_saved) > rate_ratio_threshold) 
	{
	// Calculate certain factor
	ann_factor_certain = a_angle_n(ann_rate, carvm_annuitzn_certain_yrs); 

	// Calculate endowment factor and deferred life factor, if required
	if (carvm_annuitzn_ann_type == CERTAIN_AND_LIFE_ANNUITY)
		{
		int yr_counter = 0.0;
		double surv_period = 0.0;
		double surv = 1.0;
		double disc_factor = 1.0;
		double disc_amt = 0.0;

		while (fabs(surv) > rate_ratio_threshold)
			{
			//double mort_rate_life1 = 0.0;
			//double mort_rate_life2 = 0.0;
			//double mort_improve_mult = 1.0;
			//double mort_improve_mult_life2 = 1.0;  
			//double mort_rate = 0.0;
			yr_counter += 1;
			
			// Mortality improvement lookup keys are mort_attained_age and cal_yr(t) column
			/*for (int year = carvm_annuitzn_mort_improve_base_yr + 1; year <= cal_yr(t); year++)
				mort_improve_mult *= (1.0 - carvm_annuitzn_mort_improve_pct.AtTime(t + xint(year - cal_yr(t))));
			
			// determine mortality rate for life 1
			if (fia->gender_mp == BLENDED) 
	            mort_gender = MALE;

			mort_rate_life1 = max(0.0, min(1.0, carvm_annuitzn_mort_base 
												* mort_improve_mult
												* carvm_annuitzn_mort_mult));

			// determine mortality rate for life 2, if necessary
			if (fia->gender_mp == BLENDED)
				{
				mort_gender = FEMALE;	

				// Mortality improvement lookup keys are mort_attained_age and cal_yr(t) column
				for (int year = carvm_annuitzn_mort_improve_base_yr + 1; year <= cal_yr(t); year++)
					mort_improve_mult_life2 *= (1.0 - carvm_annuitzn_mort_improve_pct.AtTime(t + xint(year - cal_yr(t))));
						 
				mort_rate_life2 = max(0.0, min(1.0, carvm_annuitzn_mort_base 
													* mort_improve_mult_life2
													* carvm_annuitzn_mort_mult));
				
			    mort_rate = max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
										  + (1.0 - fia->male_sex_pct) * mort_rate_life2));
                }
			else
			    mort_rate = mort_rate_life1;

 			surv_period = (1.0 - mort_rate);*/

			if (t == 0 && fabs(12.0 - mths_in_first_period) > model_point_amount_threshold)
				surv_period = (1.0 - mort_rate_carvm_annuitzn(t + yr_counter));
			else	
				surv_period = (1.0 - mort_rate_carvm_annuitzn(t + yr_counter - 1));

			surv *= surv_period;

			disc_factor /= (1.0 + ann_rate);
			
			if (yr_counter == carvm_annuitzn_certain_yrs)
				{
				ann_factor_endow = disc_factor * surv;

				// reset disc_rate and surv for deferred annuity calculation
				disc_factor = 1.0;
				surv = 1.0;	
				}

			if (yr_counter > carvm_annuitzn_certain_yrs)
				{
				disc_amt = disc_factor * surv;
				ann_factor_deferred_life += disc_amt;
				}
			}
		}
	}
else // use recursive calculation
	{
	if (fabs(attained_age(t) - attained_age_saved) < model_point_amount_threshold)
		{
		ann_factor_certain = ann_factor_certain_prev;
		ann_factor_endow = ann_factor_endow_prev;
		ann_factor_deferred_life = ann_factor_deferred_life_prev;
		}
	else
	    {
		// Calculate certain factor
		ann_factor_certain = ann_factor_certain_prev;

		// Calculate endowment factor and deferred life factor, if required
		if (carvm_annuitzn_ann_type == CERTAIN_AND_LIFE_ANNUITY)
			{
			double mort_rate_life1 = 0.0;
			double mort_rate_life2 = 0.0;
			double mort_improve_mult = 1.0; 
			double mort_improve_mult_life2 = 1.0; 
			double mort_rate = 0.0;
			double surv_period_attained_age = 0.0;
			double surv_period_deferred_age = 0.0;
			double disc_factor = 1.0 / (1.0 + ann_rate);
	 
			// run two loops, one to get surv_period_attained_age and one to get surv_period_deferred_age
			for (int loop = 0; loop < 2; loop++) 
				{
				// Set adjusted lookup keys
				if (loop == 1)
					surv_period_deferred_age = (1.0 - mort_rate_carvm_annuitzn(t + carvm_annuitzn_certain_yrs - 1));
					/*{
					mort_attained_age += carvm_annuitzn_certain_yrs ;
					mort_pol_yr += carvm_annuitzn_certain_yrs - 1; 
					}*/
            
				if (loop == 0 )
					surv_period_attained_age = (1.0 - mort_rate_carvm_annuitzn(t - 1));
					//mort_attained_age += - 1;  
            
				// determine mortality rate for life 1
		/*		if (fia->gender_mp == BLENDED) 
	                mort_gender = MALE;

				// Mortality improvement lookup keys are mort_attained_age and cal_yr(t) column
				for (int year = carvm_annuitzn_mort_improve_base_yr + 1; year <= cal_yr(t); year++)
					mort_improve_mult *= (1.0 - carvm_annuitzn_mort_improve_pct.AtTime(t + xint(year - cal_yr(t))));

				mort_rate_life1 = max(0.0, min(1.0, carvm_annuitzn_mort_base 
													* mort_improve_mult
													* carvm_annuitzn_mort_mult));

				// determine mortality rate for life 2, if necessary
				if (fia->gender_mp == BLENDED)
					{
					mort_gender = FEMALE;	
					
					// Mortality improvement lookup keys are mort_attained_age and cal_yr(t) column
					for (int year = carvm_annuitzn_mort_improve_base_yr + 1; year <= cal_yr(t); year++)
						mort_improve_mult_life2 *= (1.0 - carvm_annuitzn_mort_improve_pct.AtTime(t + xint(year - cal_yr(t))));
							 
					mort_rate_life2 = max(0.0, min(1.0, carvm_annuitzn_mort_base 
														* mort_improve_mult_life2
														* carvm_annuitzn_mort_mult));
				
					mort_rate = max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
											  + (1.0 - fia->male_sex_pct) * mort_rate_life2));
					}
				else
					mort_rate = mort_rate_life1;

				if (loop == 0)
					surv_period_attained_age = (1.0 - mort_rate);
				else
					surv_period_deferred_age = (1.0 - mort_rate);*/
				}								
	
			if (fabs(surv_period_attained_age) > rate_ratio_threshold)
				ann_factor_endow = ann_factor_endow_prev / surv_period_attained_age * surv_period_deferred_age;
			else
				ann_factor_endow = 0.0;

			if (fabs(surv_period_deferred_age) > rate_ratio_threshold)
				ann_factor_deferred_life = ann_factor_deferred_life_prev / (disc_factor * surv_period_deferred_age) - 1.0;
			else
				ann_factor_deferred_life = 0.0;
			}
		}
	}
// save values for recursive calculations
attained_age_saved = attained_age(t);
ann_rate_saved = ann_rate;
ann_factor_certain_prev = ann_factor_certain;
ann_factor_endow_prev = ann_factor_endow;
ann_factor_deferred_life_prev = ann_factor_deferred_life;

ann_factor = ann_factor_certain + ann_factor_endow * ann_factor_deferred_life;

return ann_factor;

}

//@@ END

//@@ START - attained_age
// Attained Age                                                                                             
// Column:ATTAINED_AGE
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_attained_age(int t) {
//^^^



//^^^

#line 1 "attained_age.FIACARVM_LIAB.for"
if (t < 0)
	return NO_AVG;
     
if (t == 0)
	return fia->attained_age(res_period);
		
if (t == 1 && fabs(12.0 - mths_in_first_period) > model_point_amount_threshold)
	return attained_age(t - 1);

return attained_age(t - 1) + 1.0;

}

//@@ END

//@@ START - cal_yr
// Calendar Year                                                                                             
// Column:CAL_YR
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_cal_yr(int t) {
//^^^



//^^^

#line 1 "cal_yr.FIACARVM_LIAB.for"
if (t < 0)
	return NO_AVG;
     
if (t == 0)
	return fia->cal_yr(res_period);
	
if (t == 1 && fabs(12.0 - mths_in_first_period) > model_point_amount_threshold)
	return cal_yr(t - 1);

return cal_yr(t - 1) + 1.0;

}

//@@ END

//@@ START - carvm_ann_disc_factor
// Discount Factor for CARVM Annuitization Benefit Reserves:                                                                                             
// Column:CARVM_ANN_DISC_FACTOR
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_ann_disc_factor(int t) {
//^^^



//^^^

#line 1 "carvm_ann_disc_factor.FIACARVM_LIAB.for"
// Remove this column
if (t < 0 || t > max_calc_period)
     return NO_AVG;

if (carvm_calc_annuitzn_defn == NOT_APPLICABLE)
     return NO_AVG;

if (t == 0)
	return 1.0;

// Set hidden lookup keys for carvm_int_rate
valn_guar_dur = pol_yr(t);
valn_plan_type = valn_rate_plan_type_elective_annuitzn;

double int_rate = carvm_int_rate;
double disc_fac_per = 1.0 / (1.0 + int_rate);

return pow(disc_fac_per, t + mths_in_first_period / 12.0 - 1);

}

//@@ END

//@@ START - carvm_disc_factor_elect_annuitzn
// Discount Factor for CARVM Annuitization Elective Benefit Reserves                                                                                             
// Column:CARVM_DISC_FACTOR_ELECT_ANNUITZN
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_disc_factor_elect_annuitzn(int t) {
//^^^



//^^^

#line 1 "carvm_disc_factor_elect_annuitzn.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
     return NO_AVG;

if (t == 0)
	return 1.0;

// Set hidden lookup keys for carvm_int_rate
valn_guar_dur = fia->pol_yr(res_period) + t - 1; 
valn_plan_type = valn_rate_plan_type_elective_annuitzn;

double int_rate = carvm_int_rate;

if (t == 1)
	return 1.0 / pow(1.0 + int_rate, mths_in_first_period / 12.0);

return 1.0 / pow(1.0 + int_rate, mths_in_first_period / 12.0 + t - 1);

}

//@@ END

//@@ START - carvm_disc_factor_elect_cash_val
// Discount Factor for CARVM Elective Benefits                                                                                             
// Column:CARVM_DISC_FACTOR_ELECT_CASH_VAL
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_disc_factor_elect_cash_val(int t) {
//^^^



//^^^

#line 1 "carvm_disc_factor_elect_cash_val.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
     return NO_AVG;

if (t == 0)
	return 1.0;

// Set hidden lookup keys for carvm_int_rate
valn_guar_dur = int_guar_dur;
valn_plan_type = valn_rate_plan_type_elective_cash_val;
double int_rate = carvm_int_rate;
double disc_fac_per = 1.0 / (1.0 + int_rate);

if (t == 1)
	disc_fac_per = pow(disc_fac_per, mths_in_first_period / 12.0);

return carvm_disc_factor_elect_cash_val(t - 1) * disc_fac_per;

}

//@@ END

//@@ START - carvm_disc_factor_non_elect
// Discount Factor for CARVM Non-Elective Benefits                                                                                             
// Column:CARVM_DISC_FACTOR_NON_ELECT
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_disc_factor_non_elect(int t) {
//^^^



//^^^

#line 1 "carvm_disc_factor_non_elect.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
     return NO_AVG;

if (t == 0)
	return 1.0;

valn_guar_dur = int_guar_dur;
valn_plan_type = valn_rate_plan_type_non_elective;
double int_rate = carvm_int_rate;
double disc_fac_per = 1.0 / (1.0 + int_rate);

if (t == 1)
	disc_fac_per = pow(disc_fac_per, mths_in_first_period / 12.0);

return carvm_disc_factor_non_elect(t - 1) * disc_fac_per;

}

//@@ END

//@@ START - carvm_disc_factor_non_elect_gmwb
// Discount Factor for CARVM Non Elective GMWB Benefits                                                                                             
// Column:CARVM_DISC_FACTOR_NON_ELECT_GMWB
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_disc_factor_non_elect_gmwb(int t) {
//^^^



//^^^

#line 1 "carvm_disc_factor_non_elect_gmwb.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
     return NO_AVG;

if (t == 0)
	return 1.0;

// Set hidden lookup keys for carvm_int_rate
valn_guar_dur = fia->pol_yr(res_period) + t - 1; 
valn_plan_type = valn_rate_plan_type_non_elective;

double int_rate = carvm_int_rate;

if (t == 1)
	return 1.0 / pow(1.0 + int_rate, mths_in_first_period / 12.0);

return 1.0 / pow(1.0 + int_rate, mths_in_first_period / 12.0 + t - 1);

}

//@@ END

//@@ START - cash_val
// Cash Surrender Value                                                                                             
// Column:CASH_VAL
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_cash_val(int t) {
//^^^



//^^^

#line 1 "cash_val.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
    return NO_AVG;

double csv = max(fund_val_aft_pfwd(t) - surr_chg(t), 0.0);

return max(guar_min_contract_val(t), csv);

}

//@@ END

//@@ START - cash_val_pv
// Present Value of Cash Surrender Value                                                                                             
// Column:CASH_VAL_PV
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_cash_val_pv(int t) {
//^^^



//^^^

#line 1 "cash_val_pv.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)
    return NO_AVG;
	
return cash_val(t) * surv(t) * carvm_disc_factor_elect_cash_val(t); 

}

//@@ END

//@@ START - contract_val_bef_pfwd
// Contract Value Before Penalty Free Withdrawal                                                                                             
// Column:CONTRACT_VAL_BEF_PFWD
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_contract_val_bef_pfwd(int t) {
//^^^



//^^^

#line 1 "contract_val_bef_pfwd.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
    return NO_AVG;
	
if (t == 0)
	return fia->contract_val(res_period);

double gmir = fia->crediting_rate_gtd;

if (t == 1) 
	return (contract_val_bef_surr(t - 1) - gmwb_chg(t) - gmwb_max_wdl_amt(t)) 
		   * pow(1.0 + gmir, mths_in_first_period / 12.0);

return max(0.0, contract_val_bef_surr(t - 1) - gmwb_chg(t) - gmwb_max_wdl_amt(t)) * (1.0 + gmir);

}

//@@ END

//@@ START - contract_val_bef_surr
// Contract Value Before Surrender Charge                                                                                             
// Column:CONTRACT_VAL_BEF_SURR
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_contract_val_bef_surr(int t) {
//^^^



//^^^

#line 1 "contract_val_bef_surr.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
    return NO_AVG;
	
return max(0.0, contract_val_bef_pfwd(t) - pfwd_surr(t));

}

//@@ END

//@@ START - credited_int
// Credited Interest                                                                                             
// Column:CREDITED_INT
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_credited_int(int t) {
//^^^



//^^^

#line 1 "credited_int.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)
    return NO_AVG;

if (fund_val_b(t) < model_point_amount_threshold)
	return 0.0;

double mths_in_period = (t == 1.0) ? mths_in_first_period : 12.0;
double max_crediting_rate = crediting_rate(t);
double mths_to_closest_eocy_or_eopy = 0.0;
double mths_to_eopy = mths_in_period;

if (model_name == "TAX" && fia->issue_yr > 1987) // Intersted guaranteed at a rate higher than valuation rate can only be applied to the end of taxable year
	{ 	
	//Specify the lookup keys
	valn_guar_dur = int_guar_dur;
	valn_plan_type = valn_rate_plan_type_non_elective;
	max_crediting_rate = carvm_int_rate;
	
	double valn_mth = fia->cal_mth(res_period);

	if (t == 1)	
		{
		if (valn_mth < fia->issue_mth && mths_in_first_period != 12.0) 
		    mths_to_closest_eocy_or_eopy = mths_in_first_period;			
		else
			mths_to_closest_eocy_or_eopy = 12.0 - valn_mth;
		}				
	else if (t == 2.0 && valn_mth < fia->issue_mth && mths_in_first_period != 12.0 ) 
		mths_to_closest_eocy_or_eopy = 12.0 - valn_mth - mths_in_first_period;		 
	else                                 
		mths_to_closest_eocy_or_eopy  = 0.0;				
		
	mths_to_eopy = mths_in_period  - mths_to_closest_eocy_or_eopy ;
    }

return max(0.0, fund_val_b(t) 
				* (pow(1.0 + crediting_rate(t), mths_to_closest_eocy_or_eopy / 12.0)
				   * pow(1.0 + min(crediting_rate(t), max_crediting_rate), mths_to_eopy / 12.0) - 1.0));

}

//@@ END

//@@ START - crediting_rate
// Crediting Rate                                                                                             
// Column:CREDITING_RATE
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_crediting_rate(int t) {
//^^^



//^^^

#line 1 "crediting_rate.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)
    return NO_AVG;

if (t > 0 && fabs(fund_val_aft_pfwd(t - 1)) < model_point_amount_threshold)
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

for (int i = 0; i < fia->sm_fia_account.size(); i++)
	{
	K = fia->sm_fia_account[i]->strike(t, res_period, xint(mths_in_first_period));
	K_cap = fia->sm_fia_account[i]->strike_cap(t, res_period, xint(mths_in_first_period));
	S = fia->sm_fia_account[i]->underlying_price(t, res_period);
	q = dividend_yield(t, fia->sm_fia_account[i]->crediting_eqt_index);
	tte = time_to_expiry(t, fia->sm_fia_account[i]->crediting_mths);
	sigma = volatility(t, fia->sm_fia_account[i]->crediting_eqt_index, K / S, tte);
	sigma_cap = volatility(t, fia->sm_fia_account[i]->crediting_eqt_index, K_cap / S, tte);
	rf = risk_free_rate(t, tte);
	cost_of_call_option_pct = 0.0;
	cost_of_call_option_cap_pct = 0.0;
	
	if (fia->sm_fia_account[i]->crediting_rate_defn == POINT_TO_POINT)
		{
		cost_of_call_option_pct = bs_opt_val(K, tte, S, sigma, rf, q, CALL_CODE, CONTINUOUS_PAYOUT_CODE) / K; 
		cost_of_call_option_cap_pct = bs_opt_val(K_cap, tte, S, sigma_cap, rf, q, CALL_CODE, CONTINUOUS_PAYOUT_CODE) / K;
		}
	else if (fia->sm_fia_account[i]->crediting_rate_defn == MOVING_AVERAGE)
		{
		if (mod (res_period, fia->sm_fia_account[i]->crediting_mths) == 0.0)
			month = fia->sm_fia_account[i]->crediting_mths;
		else 
			month = mod (res_period, fia->sm_fia_account[i]->crediting_mths);
			
		Average = fia->sm_fia_account[i]->index_val_avg_calc(res_period, month);
		cost_of_call_option_pct = bs_opt_val_levy_asian(K, tte, S, Average,sigma, rf, q) / K; 
		cost_of_call_option_cap_pct = bs_opt_val_levy_asian(K_cap, tte, S, Average,sigma_cap, rf, q) / K;
		}
	else if (fia->sm_fia_account[i]->crediting_rate_defn == MONTHLY_SUM_CAP)
		{
		double cap = fia->sm_fia_account[i]->crediting_cap_rate(res_period);
		
		if (mod (res_period, fia->sm_fia_account[i]->crediting_mths) == 0.0)
			month = fia->sm_fia_account[i]->crediting_mths;
		else 
			month = mod (res_period, fia->sm_fia_account[i]->crediting_mths);

		double index_curr = 0;
		double index_prev = 0;
		double index_change_sum = 0;
		for (int j = 0; j < month; j++)
			{
			index_curr = fia->sm_fia_account[i]->index_val_calc(res_period - j);
			index_prev = fia->sm_fia_account[i]->index_val_calc(res_period - j - 1);
		
			if (index_prev > 0) //need to set index_prev first			
				index_change_sum += min(cap, (index_curr / index_prev) - 1.0);
			}	

		cost_of_call_option_pct 
		= bs_opt_val_mthly_sum_cap(fia->sm_fia_account[i]->crediting_mths,
		                            month,
									index_change_sum,
									cap,
									tte,
									rf,
									q,
									sigma,
									NOMINAL_SEMIANNUAL,
									EFFECTIVE_ANNUAL);
		}
	else if (fia->sm_fia_account[i]->crediting_rate_defn == FIXED_RATE)
		{
    	fixed_rate = crediting_rate_fund_value_fixed(t);
		fixed_rate_num += fixed_rate * fia->sm_fia_account[i]->fund_val_e(res_period);
		}

	else throw NonFatalError("AG35 - Only Point to Point, Moving Average, Monthly Sum Cap and Fixed Rate crediting methods supported");

	double part_rate;

	if (t == 1)
		part_rate = fia->sm_fia_account[i]->crediting_part_rate(res_period);
	else
		part_rate = fia->sm_fia_account[i]->crediting_part_min;	

	if (fia->sm_fia_account[i]->crediting_dyn_lever == DYNAMIC_CAP)
		net_opt_value = (cost_of_call_option_pct - cost_of_call_option_cap_pct);
	else if (fia->sm_fia_account[i]->crediting_dyn_lever == DYNAMIC_PART)				
		net_opt_value = cost_of_call_option_pct * part_rate;
	else //Both cap and participation
		net_opt_value = (cost_of_call_option_pct - cost_of_call_option_cap_pct)
						* part_rate;
	
	option_rate_num += net_opt_value * fia->sm_fia_account[i]->fund_val_e(res_period);
	}		

if (t == 1)
   {
   accum_option_pct = fixed_rate_num / fia->fund_val_fixed(res_period) 
					  * mths_in_first_period / 12.0
					  + option_rate_num / fia->fund_val_fixed(res_period)
						* pow(1.0 + rf, mths_in_first_period / 12.0);
	
	// adjust accum_opt_pct to be effective annual
	accum_option_pct = pow(1.0 + accum_option_pct, 12.0 / mths_in_first_period) - 1.0;
	}
else
    accum_option_pct = fixed_rate_num / fia->fund_val_fixed(res_period) 
					   + option_rate_num / fia->fund_val_fixed(res_period) * (1.0 + rf);

return accum_option_pct;

}

//@@ END

//@@ START - crediting_rate_fund_value_fixed
// Fixed Crediting Rate for Fund Value                                                                                             
// Column:CREDITING_RATE_FUND_VALUE_FIXED
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_crediting_rate_fund_value_fixed(int t) {
//^^^



//^^^

#line 1 "crediting_rate_fund_value_fixed.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return 0.0;

if (t == 0)	  		 
	return fia->crediting_rate_fix(res_period);	

if (pol_yr(t) <= xint(fia->sm_fia_account[0]->crediting_rate_guar_mths / 12.0)) //20250430 MQ temp fix
    return crediting_rate_fund_value_fixed (t - 1);		

return fia->crediting_rate_min;

}

//@@ END

//@@ START - dth_benefits
// Death Benefit                                                                                             
// Column:DTH_BENEFITS
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_dth_benefits(int t) {
//^^^



//^^^

#line 1 "dth_benefits.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)
	return NO_AVG;

double deaths = surv(t - 1) * mort_rate_carvm(t);

return max(fund_val_bef_pfwd(t), contract_val_bef_pfwd(t)) * deaths;

}

//@@ END

//@@ START - dth_benefits_pv
// Present Value of Death Benefits                                                                                             
// Column:DTH_BENEFITS_PV
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_dth_benefits_pv(int t) {
//^^^



//^^^

#line 1 "dth_benefits_pv.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)
	return NO_AVG;

return dth_benefits_pv(t - 1) + dth_benefits(t) * carvm_disc_factor_non_elect(t);

}

//@@ END

//@@ START - fund_val_aft_pfwd
// Fund Value After PFWD                                                                                             
// Column:FUND_VAL_AFT_PFWD
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_aft_pfwd(int t) {
//^^^



//^^^

#line 1 "fund_val_aft_pfwd.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;
	
if (t == 0)
	return fia->fund_val_fixed(res_period);

if (fund_val_bef_pfwd(t) < model_point_amount_threshold)
	return 0.0;

return fund_val_bef_pfwd(t) - pfwd_surr(t);

}

//@@ END

//@@ START - fund_val_b
// Fund Value Beginning of Period                                                                                             
// Column:FUND_VAL_B
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_b(int t) {
//^^^



//^^^

#line 1 "fund_val_b.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)
	return NO_AVG;

if (fund_val_aft_pfwd(t - 1) < model_point_amount_threshold)
	return 0.0;

return max(0.0, fund_val_aft_pfwd(t - 1) - admin_fee(t) - gmwb_chg(t));

}

//@@ END

//@@ START - fund_val_bef_pfwd
// Fund Value Before PFWD                                                                                             
// Column:FUND_VAL_BEF_PFWD
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_bef_pfwd(int t) {
//^^^



//^^^

#line 1 "fund_val_bef_pfwd.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)
	return NO_AVG;

if (fund_val_b(t) < model_point_amount_threshold)
	return 0.0;

return fund_val_b(t) + credited_int(t);

}

//@@ END

//@@ START - gmwb_ann_benefits
// GMWB Annuitization Benefits                                                                                             
// Column:GMWB_ANN_BENEFITS
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_ann_benefits(int t) {
//^^^



//^^^

#line 1 "gmwb_ann_benefits.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

if (!fia->gmwb_flag)
     return NO_AVG;

if (gmwb_max_wdl_amt(t) <= model_point_amount_threshold)
	return NO_AVG;

if (fund_val_bef_pfwd(t) - gmwb_max_wdl_amt(t) > model_point_amount_threshold)
	return NO_AVG;

double init_pmt = gmwb_max_wdl_amt(t);
double recur_pmt = gmwb_max_wdl_amt(t);
double ann_rate = 0.0;
double pv_gmwb_withdrls = 0.0;

if (fund_val_bef_pfwd(t) - gmwb_max_wdl_amt(t) <= model_point_amount_threshold
	&& fund_val_bef_pfwd(t) > model_point_amount_threshold)
	init_pmt = gmwb_max_wdl_amt(t) - pfwd_surr(t);

// Set hidden lookup keys for carvm_int_rate
valn_guar_dur = pol_yr(t);
valn_plan_type = valn_rate_plan_type_non_elective;
ann_rate = carvm_int_rate;

// Create GMWB annuity present value
if (fia->gmwb_defn == FINITE)
	{
	pv_gmwb_withdrls = init_pmt;
	double remaining_gmwb_base = gmwb_inf_bef(t) - pfwd_surr(t) - init_pmt;
	double disc_factor = 1.0 / (1.0 + ann_rate);

	while (remaining_gmwb_base > 0)
		{
		double gmwb_pmt = min(remaining_gmwb_base, recur_pmt);
		pv_gmwb_withdrls += gmwb_pmt * disc_factor;
		disc_factor *= 1.0 / (1.0 + ann_rate);
		remaining_gmwb_base -= gmwb_pmt;
		}
	}
else // fia->gmwb_defn == LIFE
	{
	pv_gmwb_withdrls = init_pmt;
	int pol_yr = this->pol_yr(t);
	int duration = 1;
	double mort_rate = 0.0;
	double disc_factor = 1.0;
	double surv_period = 1.0;
	double surv = 1.0;
	double gmdb_pmt = recur_pmt;

	while (surv > rate_ratio_threshold)
		{
		pol_yr += 1;
		mort_rate = mort_rate_carvm_gmwb(t + duration);
		surv_period = 1.0 - mort_rate;
		surv *= surv_period;
		disc_factor *= 1.0 / (1.0 + ann_rate);

		pv_gmwb_withdrls += gmdb_pmt * disc_factor * surv;		

		duration += 1;
		}
	}

return pv_gmwb_withdrls;

}

//@@ END

//@@ START - gmwb_ann_benefits_pv
// PV of GMWB Annuitization Benefits                                                                                             
// Column:GMWB_ANN_BENEFITS_PV
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_ann_benefits_pv(int t) {
//^^^



//^^^

#line 1 "gmwb_ann_benefits_pv.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

if (!fia->gmwb_flag)
     return NO_AVG;

if (t > 0 && fabs(fund_val_aft_pfwd(t - 1)) < model_point_amount_threshold)
	return NO_AVG; 

return gmwb_ann_benefits(t) * carvm_disc_factor_non_elect_gmwb(t) * surv(t);

}

//@@ END

//@@ START - gmwb_chg
// GMWB Rider Charge                                                                                             
// Column:GMWB_CHG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_chg(int t) {
//^^^



//^^^

#line 1 "gmwb_chg.FIACARVM_LIAB.for"
if (t <= 0 ||t > max_calc_period)
	return NO_AVG;

if (!fia->gmwb_flag)
	return NO_AVG;

if (fabs(fund_val_aft_pfwd(t - 1)) < model_point_amount_threshold)
	return 0.0;

double gmwb_chg_base_amt = 0.0;
double gmwb_chg_factor = 1.0;

if (fia->gmwb_chg_base == FUND_VALUE)
    gmwb_chg_base_amt = fund_val_aft_pfwd(t - 1) - admin_fee(t);
else if (fia->gmwb_chg_base == GMWB_BASE)
    gmwb_chg_base_amt = gmwb_inf_bef(t - 1);
else //Max Amount
    gmwb_chg_base_amt = max(fund_val_aft_pfwd(t - 1) - admin_fee(t), gmwb_inf_bef(t - 1));

if (t == 1)
	{
	if (fia->pol_yr(res_period) == 1 && fia->pol_mth(res_period) == 1)
		gmwb_chg_factor = 11.0 / 12.0;
	
	else if (mths_in_first_period < 12)
		gmwb_chg_factor = mths_in_first_period / 12.0;
	}
	
return min(fund_val_aft_pfwd(t - 1) - admin_fee(t), 
           gmwb_chg_base_amt * fia->gmwb_chg_pct * gmwb_chg_factor);

}

//@@ END

//@@ START - gmwb_fund_val_aft_pfwd
// GMWB Fund Value End of Period after FPWs                                                                                             
// Column:GMWB_FUND_VAL_AFT_PFWD
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_fund_val_aft_pfwd(int t) {
//^^^



//^^^

#line 1 "gmwb_fund_val_aft_pfwd.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;
	
if (!fia->gmwb_flag || fia->gmwb_fund_val_defn == NOT_APPLICABLE)
	return NO_AVG;
	
if (t == 0)
	return fia->gmwb_fund_val_inf(res_period);
	
if (fabs(fund_val_bef_pfwd(t)) < model_point_amount_threshold)
	return gmwb_fund_val_bef_pfwd(t);

if (fia->gmwb_wdl_reduce_ben_base == YES)
	return gmwb_fund_val_bef_pfwd(t) - pfwd_surr(t);

return gmwb_fund_val_bef_pfwd(t);

}

//@@ END

//@@ START - gmwb_fund_val_bef_pfwd
// GMWB Fund Value End of Period before FPWs                                                                                             
// Column:GMWB_FUND_VAL_BEF_PFWD
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_fund_val_bef_pfwd(int t) {
//^^^



//^^^

#line 1 "gmwb_fund_val_bef_pfwd.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;
	
if (!fia->gmwb_flag || fia->gmwb_fund_val_defn == NOT_APPLICABLE)
	return NO_AVG;
	
if (t == 0)
	return fia->gmwb_fund_val_inf(res_period);
	
// Sets the GMWB after reaching the maximum age
if (xint(age_last(t)) >= fia->gmwb_max_age)
	return gmwb_fund_val_aft_pfwd(t - 1);

if (t == 1)
	{
	if (fabs(12.0 - mths_in_first_period) < model_point_amount_threshold 
	    && mod(xint(pol_yr(t)) - 1, fia->gmwb_fund_val_period) == 0)
		return max(gmwb_fund_val_aft_pfwd(t - 1), fund_val_aft_pfwd(t - 1));
	
	return gmwb_fund_val_aft_pfwd(t - 1);
	}
	
if (mod(xint(pol_yr(t)) -1, fia->gmwb_fund_val_period) == 0)
	return max(gmwb_fund_val_aft_pfwd(t - 1), 
	           fund_val_aft_pfwd(t - 1));

return gmwb_fund_val_aft_pfwd(t - 1);

}

//@@ END

//@@ START - gmwb_inf_bef
// GMWB In Force End of Month Before Claims                                                                                             
// Column:GMWB_INF_BEF
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_inf_bef(int t) {
//^^^



//^^^

#line 1 "gmwb_inf_bef.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;
	
if (!fia->gmwb_flag)
	return NO_AVG;
	
double gmwb_premium_bef = gmwb_prem_bef_pfwd(t);

if (fia->gmwb_prem_defn == ROLLUP)
	gmwb_premium_bef = min(gmwb_prem_bef_pfwd(t), gmwb_rollup_cap_bef_pfwd(t));

return max(gmwb_fund_val_bef_pfwd(t), gmwb_premium_bef);

}

//@@ END

//@@ START - gmwb_max_wdl_amt
// GMWB Maximum Withdrawal Amount                                                                                             
// Column:GMWB_MAX_WDL_AMT
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_max_wdl_amt(int t) {
//^^^



//^^^

#line 1 "gmwb_max_wdl_amt.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)
	return NO_AVG;

if (!fia->gmwb_flag)
	return NO_AVG;

if (pol_yr(t) <= fia->gmwb_req_yrs_wait + gmwb_exercise_point
	&& fabs(fund_val_bef_pfwd(t)) > model_point_amount_threshold)
	return 0.0;

// Set lookup key 
fia->gmwb_withdrl_age = fia->issue_age_mp + fia->gmwb_req_yrs_wait + gmwb_exercise_point;
double mawp_local = fia->gmwb_max_annual_wdl_pct;

if (fia->pfwd_surr_curr_pol_yr(res_period) > model_point_amount_threshold)
	{
	if (t == 1)
		{
		if (fia->gmwb_max_wdl_amt_base_defn == PREMIUM || fia->gmwb_max_wdl_amt_base_defn == GMWB_BASE)
			return fia->gmwb_max_wdl_amt(res_period);

		//else "GMWB BASE ADJUSTABLE"
		return max(fia->gmwb_max_wdl_amt(res_period), gmwb_inf_bef(t) * mawp_local);
		}	
  
	return gmwb_max_wdl_amt(t - 1);
	} 

if (fia->gmwb_max_wdl_amt_base_defn == PREMIUM)
	{
	if (pol_yr(t) == fia->gmwb_req_yrs_wait + gmwb_exercise_point + 1
		|| (pol_yr(t) < fia->gmwb_req_yrs_wait + gmwb_exercise_point + 1
			&& fabs(fund_val_bef_pfwd(t)) <= model_point_amount_threshold))
		return gmwb_prem_bef_pfwd(t) * mawp_local;   

	return gmwb_max_wdl_amt(t - 1);
	}

if (pol_yr(t) == fia->gmwb_req_yrs_wait + gmwb_exercise_point + 1
	|| (pol_yr(t) < fia->gmwb_req_yrs_wait + gmwb_exercise_point + 1
		&& fabs(fund_val_bef_pfwd(t)) <= model_point_amount_threshold))
	return gmwb_inf_bef(t) * mawp_local;   

return gmwb_max_wdl_amt(t - 1);

}

//@@ END

//@@ START - gmwb_prem_aft_pfwd
// GMWB Premium End of Period after FPWs                                                                                             
// Column:GMWB_PREM_AFT_PFWD
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_prem_aft_pfwd(int t) {
//^^^



//^^^

#line 1 "gmwb_prem_aft_pfwd.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;
	
if (!fia->gmwb_flag || fia->gmwb_prem_defn == NOT_APPLICABLE)
	return NO_AVG;
	
if (fabs(fund_val_bef_pfwd(t)) < model_point_amount_threshold)
	return gmwb_prem_bef_pfwd(t);

if (fia->gmwb_wdl_reduce_ben_base == YES
	|| (fabs(gmwb_max_wdl_amt(t)) < model_point_amount_threshold && pfwd_model == "FULL"))
    return max(0.0, gmwb_prem_bef_pfwd(t) - pfwd_surr(t));

return max(0.0, gmwb_prem_bef_pfwd(t));

}

//@@ END

//@@ START - gmwb_prem_bef_pfwd
// GMWB Premium Base nd of Period before FPWs                                                                                             
// Column:GMWB_PREM_BEF_PFWD
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_prem_bef_pfwd(int t) {
//^^^



//^^^

#line 1 "gmwb_prem_bef_pfwd.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

if (!fia->gmwb_flag || fia->gmwb_prem_defn == NOT_APPLICABLE)
	return NO_AVG;

if (t == 0)
   return fia->gmwb_income_base_e_bef_crbg(res_period + 1);
	
// Sets the GMWB after reaching the maximum age
if (xint(age_last(t)) >= fia->gmwb_max_age || pol_yr(t) > fia->gmwb_req_yrs_wait + gmwb_exercise_point)
	return gmwb_prem_aft_pfwd(t - 1);
	
gmwb_prem_bef_pfwd(0);	

double rollup_credit_base = 0.0;
double rollup_credit = 0.0;

if (fia->gmwb_rollup_rate_type == COMPOUND)
    rollup_credit_base = gmwb_prem_aft_pfwd(t - 1);

if (fia->gmwb_rollup_rate_type == SIMPLE)
    rollup_credit_base = prem_cumul;

rollup_credit = rollup_credit_base * fia->gmwb_rollup_rate;

if (fia->gmwb_prem_defn == ROLLUP 
	&& pol_yr(t)<= fia->gmwb_max_rollup_duration)
	return gmwb_prem_aft_pfwd(t - 1) 
		   + rollup_credit;

if (fia->gmwb_prem_defn == STEPUP 
	&& pol_yr(t)== fia->gmwb_req_yrs_wait + 1) 
	return gmwb_prem_aft_pfwd(t - 1)  
	       * (1.0 + fia->gmwb_step_up_rate);

return gmwb_prem_aft_pfwd(t - 1);

}

//@@ END

//@@ START - gmwb_rollup_cap_aft_pfwd
// GMWB Roll-Up Cap End of Month after pfw                                                                                             
// Column:GMWB_ROLLUP_CAP_AFT_PFWD
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_rollup_cap_aft_pfwd(int t) {
//^^^



//^^^

#line 1 "gmwb_rollup_cap_aft_pfwd.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;
	
if (!fia->gmwb_flag || fia->gmwb_prem_defn != ROLLUP)
	return NO_AVG;
	
if (fabs(fund_val_bef_pfwd(t)) < model_point_amount_threshold)
	return gmwb_rollup_cap_bef_pfwd(t);
	
return gmwb_rollup_cap_bef_pfwd(t) * fund_val_aft_pfwd(t) / fund_val_bef_pfwd(t);

}

//@@ END

//@@ START - gmwb_rollup_cap_bef_pfwd
// GMWB Roll-Up Cap End of Month Before pfw                                                                                             
// Column:GMWB_ROLLUP_CAP_BEF_PFWD
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_rollup_cap_bef_pfwd(int t) {
//^^^



//^^^

#line 1 "gmwb_rollup_cap_bef_pfwd.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

if (!fia->gmwb_flag || fia->gmwb_prem_defn != ROLLUP)
	return NO_AVG;

if (t == 0)  
	return fia->gmwb_rollup_cap_inf(res_period);	
		
return gmwb_rollup_cap_aft_pfwd(t - 1);

}

//@@ END

//@@ START - guar_min_contract_val
// Guaranteed Minimum Contract Value                                                                                             
// Column:GUAR_MIN_CONTRACT_VAL
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_guar_min_contract_val(int t) {
//^^^



//^^^

#line 1 "guar_min_contract_val.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;
	
if (t == 0)
	return fia->min_contract_val(res_period);

// Non forfeiture value is adjusted (when applicable) by surrender charge unadjusted for MVA
if (fia->contract_val_sc_defn == YES)
	return max(0.0, contract_val_bef_surr(t) - surr_chg(t));

return contract_val_bef_surr(t);

}

//@@ END

//@@ START - mort_rate_ann_purch_curr
// Mort Rate Current Purchase Rate                                                                                             
// Column:MORT_RATE_ANN_PURCH_CURR
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_mort_rate_ann_purch_curr(int t) {
//^^^



//^^^

#line 1 "mort_rate_ann_purch_curr.FIACARVM_LIAB.for"
if (t < 0)
	return NO_AVG;

if (t != 0)
	{
	if (fabs(mort_rate_ann_purch_curr(t - 1) - 1.0) < model_point_amount_threshold)
		return NO_AVG;
	}

double mort_rate_life1 = 0.0;
double mort_rate_life2 = 0.0;
double mort_rate = 0.0;
double mort_base_curr = 0.0;
double mort_mult_curr = 1.0;

// Determine mortality rate for life 1 and life2
if (fia->gender_mp == BLENDED)
{
	fia->mort_gender = MALE;
	mort_base_curr = this->mort_base_curr;
	fia->mort_gender = MALE;
	mort_mult_curr = this->mort_mult_curr;

	mort_rate_life1 = max(0.0, min(1.0, mort_base_curr * mort_mult_curr));
	
	fia->mort_gender = FEMALE;
	mort_base_curr = this->mort_base_curr;
	fia->mort_gender = FEMALE;
	mort_mult_curr = this->mort_mult_curr;

	mort_rate_life2 = max(0.0, min(1.0, mort_base_curr * mort_mult_curr));

	return max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
								+ (1.0 - fia->male_sex_pct) * mort_rate_life2));
}
else
{
	fia->mort_gender = fia->gender_mp;
	mort_base_curr = this->mort_base_curr;
	fia->mort_gender = fia->gender_mp;
	mort_mult_curr = this->mort_mult_curr;

	return max(0.0, min(1.0, mort_base_curr * mort_mult_curr));
}

}

//@@ END

//@@ START - mort_rate_ann_purch_guar
// Mort Rate Guaranteed Purchase Rate                                                                                             
// Column:MORT_RATE_ANN_PURCH_GUAR
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_mort_rate_ann_purch_guar(int t) {
//^^^



//^^^

#line 1 "mort_rate_ann_purch_guar.FIACARVM_LIAB.for"
if (t < 0)
	return NO_AVG;

if (t != 0)
	{
	if (fabs(mort_rate_ann_purch_guar(t - 1) - 1.0) < model_point_amount_threshold)
		return NO_AVG;
	}

double mort_rate_life1 = 0.0;
double mort_rate_life2 = 0.0;
double mort_rate = 0.0;
double mort_base_guar = 0.0;
double mort_mult_guar = 1.0;

// Determine mortality rate for life 1 and life2
if (fia->gender_mp == BLENDED)
{
	fia->mort_gender = MALE;
	mort_base_guar = this->mort_base_guar;
	fia->mort_gender = MALE;
	mort_mult_guar = this->mort_mult_guar;

	mort_rate_life1 = max(0.0, min(1.0, mort_base_guar * mort_mult_guar));
	
	fia->mort_gender = FEMALE;
	mort_base_guar = this->mort_base_guar;
	fia->mort_gender = FEMALE;
	mort_mult_guar = this->mort_mult_guar;

	mort_rate_life2 = max(0.0, min(1.0, mort_base_guar * mort_mult_guar));

	return max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
								+ (1.0 - fia->male_sex_pct) * mort_rate_life2));
}
else
{
	fia->mort_gender = fia->gender_mp;
	mort_base_guar = this->mort_base_guar;
	fia->mort_gender = fia->gender_mp;
	mort_mult_guar = this->mort_mult_guar;

	return max(0.0, min(1.0, mort_base_guar * mort_mult_guar));
}

}

//@@ END

//@@ START - mort_rate_carvm
// Mortality rates for CARVM calculations.                                                                                             
// Column:MORT_RATE_CARVM
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_mort_rate_carvm(int t) {
//^^^



//^^^

#line 1 "mort_rate_carvm.FIACARVM_LIAB.for"
if (t <= 0)
	return NO_AVG;

if (fabs(mort_rate_carvm(t - 1) - 1.0) < model_point_amount_threshold)
	return NO_AVG;

double mort_rate_life1 = 0.0;
double mort_rate_life2 = 0.0;
double mort_improve_mult = 1.0;
double mort_improve_mult_life2 = 1.0;  
double mort_rate = 0.0;
double carvm_mort_base = 0.0;
double carvm_mort_mult = 1.0;

// determine mortality rate for life 1
if (fia->gender_mp == BLENDED)
	{	
	mort_gender = MALE;
	carvm_mort_base = this->carvm_mort_base;
	mort_gender = MALE;
	carvm_mort_mult = this->carvm_mort_mult;

	for (int year = carvm_mort_improve_base_yr + 1; year <= cal_yr(t); year++)
		{
		mort_gender = MALE;
		mort_cal_yr = year;
		mort_improve_mult *= (1.0 - carvm_mort_improve_pct);
		}
	
	mort_rate_life1 = max(0.0, min(1.0, carvm_mort_base 
										* mort_improve_mult
										* carvm_mort_mult));

	mort_gender = FEMALE;
	carvm_mort_base = this->carvm_mort_base;
	mort_gender = FEMALE;
	carvm_mort_mult = this->carvm_mort_mult;
	for (int year = carvm_mort_improve_base_yr + 1; year <= cal_yr(t); year++)
		{
		mort_gender = FEMALE;
		mort_cal_yr = year;
		mort_improve_mult_life2 *= (1.0 - carvm_mort_improve_pct);
		}

	mort_rate_life2 = max(0.0, min(1.0, carvm_mort_base 
										* mort_improve_mult_life2
										* carvm_mort_mult));
				
	mort_rate = max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
								+ (1.0 - fia->male_sex_pct) * mort_rate_life2));
	}
else
	{
	mort_gender = fia->gender_mp;
	carvm_mort_base = this->carvm_mort_base;
	mort_gender = fia->gender_mp;
	carvm_mort_mult = this->carvm_mort_mult;

	for (int year = carvm_mort_improve_base_yr + 1; year <= cal_yr(t); year++)
		{
		mort_gender = fia->gender_mp;
		mort_cal_yr = year;
		mort_improve_mult *= (1.0 - carvm_mort_improve_pct);
		}

	mort_rate =  max(0.0, min(1.0, carvm_mort_base 
								   * mort_improve_mult
								   * carvm_mort_mult));
	}

if (t == 1)
	return 1.0 - pow(1.0 - mort_rate, mths_in_first_period / 12.0);

return mort_rate;

}

//@@ END

//@@ START - mort_rate_carvm_annuitzn
// Mortality rate for annuity benefit CARVM valuations.                                                                                             
// Column:MORT_RATE_CARVM_ANNUITZN
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_mort_rate_carvm_annuitzn(int t) {
//^^^



//^^^

#line 1 "mort_rate_carvm_annuitzn.FIACARVM_LIAB.for"
if (t < 0)
	return NO_AVG;

if (t != 0)
	{
	if (fabs(mort_rate_carvm_annuitzn(t - 1) - 1.0) < model_point_amount_threshold)
		return NO_AVG;
	}

double mort_rate_life1 = 0.0;
double mort_rate_life2 = 0.0;
double mort_improve_mult = 1.0;
double mort_improve_mult_life2 = 1.0;  
double mort_rate = 0.0;
double carvm_annuitzn_mort_base = 0.0;
double carvm_annuitzn_mort_mult = 1.0;
		
// determine mortality rate for life 1
if (fia->gender_mp == BLENDED)
	{	
	mort_gender = MALE;
	carvm_annuitzn_mort_base = this->carvm_annuitzn_mort_base;
	mort_gender = MALE;
	carvm_annuitzn_mort_mult = this->carvm_annuitzn_mort_mult;

	for (int year = carvm_annuitzn_mort_improve_base_yr + 1; year <= cal_yr(t); year++)
		{
		mort_gender = MALE;
		mort_cal_yr = year;
		mort_improve_mult *= (1.0 - carvm_annuitzn_mort_improve_pct);
		}
	
	mort_rate_life1 = max(0.0, min(1.0, carvm_annuitzn_mort_base 
										* mort_improve_mult
										* carvm_annuitzn_mort_mult));

	mort_gender = FEMALE;
	carvm_annuitzn_mort_base = this->carvm_annuitzn_mort_base;
	mort_gender = FEMALE;
	carvm_annuitzn_mort_mult = this->carvm_annuitzn_mort_mult;

	for (int year = carvm_annuitzn_mort_improve_base_yr + 1; year <= cal_yr(t); year++)
		{
		mort_gender = FEMALE;
		mort_cal_yr = year;
		mort_improve_mult_life2 *= (1.0 - carvm_annuitzn_mort_improve_pct);
		}

	mort_rate_life2 = max(0.0, min(1.0, carvm_annuitzn_mort_base 
										* mort_improve_mult_life2
										* carvm_annuitzn_mort_mult));
				
	return max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
								+ (1.0 - fia->male_sex_pct) * mort_rate_life2));
	}
else
	{
	mort_gender = fia->gender_mp;
	carvm_annuitzn_mort_base = this->carvm_annuitzn_mort_base;
	mort_gender = fia->gender_mp;
	carvm_annuitzn_mort_mult = this->carvm_annuitzn_mort_mult;

	for (int year = carvm_annuitzn_mort_improve_base_yr + 1; year <= cal_yr(t); year++)
		{
		mort_gender = fia->gender_mp;
		mort_cal_yr = year;
		mort_improve_mult *= (1.0 - carvm_annuitzn_mort_improve_pct);
		}

	return max(0.0, min(1.0, carvm_annuitzn_mort_base 
							 * mort_improve_mult
				 			 * carvm_annuitzn_mort_mult));
	}



}

//@@ END

//@@ START - mort_rate_carvm_gmwb
// Mortality rates for CARVM GMWB calculations                                                                                             
// Column:MORT_RATE_CARVM_GMWB
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_mort_rate_carvm_gmwb(int t) {
//^^^



//^^^

#line 1 "mort_rate_carvm_gmwb.FIACARVM_LIAB.for"
if (t <= 0)
	return NO_AVG;

if (fabs(mort_rate_carvm_gmwb(t - 1) - 1.0) < model_point_amount_threshold)
	return NO_AVG;

double mort_rate_life1 = 0.0;
double mort_rate_life2 = 0.0;
double mort_improve_mult = 1.0;
double mort_improve_mult_life2 = 1.0;  
double mort_rate = 0.0;
double carvm_gmwb_mort_base = 0.0;
double carvm_gmwb_mort_mult = 1.0;
		
// determine mortality rate for life 1
if (fia->gender_mp == BLENDED)
	{	

	for (int year = carvm_gmwb_mort_improve_base_yr + 1; year <= cal_yr(t); year++)
		{
		mort_gender = MALE;
		mort_cal_yr = year;
		mort_improve_mult *= (1.0 - carvm_gmwb_mort_improve_pct);
		}
	
	mort_gender = MALE;
	carvm_gmwb_mort_base = this->carvm_gmwb_mort_base;
	mort_gender = MALE;
	carvm_gmwb_mort_mult = this->carvm_gmwb_mort_mult;
	mort_rate_life1 = max(0.0, min(1.0, carvm_gmwb_mort_base 
										* mort_improve_mult
										* carvm_gmwb_mort_mult));

	for (int year = carvm_gmwb_mort_improve_base_yr + 1; year <= cal_yr(t); year++)
		{
		mort_gender = FEMALE;
		mort_cal_yr = year;
		mort_improve_mult_life2 *= (1.0 - carvm_gmwb_mort_improve_pct);
		}

	mort_gender = FEMALE;
	carvm_gmwb_mort_base = this->carvm_gmwb_mort_base;
	mort_gender = FEMALE;
	carvm_gmwb_mort_mult = this->carvm_gmwb_mort_mult;
	mort_rate_life2 = max(0.0, min(1.0, carvm_gmwb_mort_base 
										* mort_improve_mult_life2
										* carvm_gmwb_mort_mult));
				
	mort_rate = max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
								+ (1.0 - fia->male_sex_pct) * mort_rate_life2));
	}
else
	{

	for (int year = carvm_gmwb_mort_improve_base_yr + 1; year <= cal_yr(t); year++)
		{
		mort_gender = fia->gender_mp;
		mort_cal_yr = year;
		mort_improve_mult *= (1.0 - carvm_gmwb_mort_improve_pct);
		}

	mort_gender = fia->gender_mp;
	carvm_gmwb_mort_base = this->carvm_gmwb_mort_base;
	mort_gender = fia->gender_mp;
	carvm_gmwb_mort_mult = this->carvm_gmwb_mort_mult;

	mort_rate =  max(0.0, min(1.0, carvm_gmwb_mort_base 
								   * mort_improve_mult
								   * carvm_gmwb_mort_mult));
	}

if (t == 1)
	return 1.0 - pow(1.0 - mort_rate, mths_in_first_period / 12.0);

return mort_rate;

}

//@@ END

//@@ START - mort_rate_carvm_omega
// Mortality base rate used for CARVM in order to calculate omega age.                                                                                             
// Column:MORT_RATE_CARVM_OMEGA
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_mort_rate_carvm_omega(int t) {
//^^^



//^^^

#line 1 "mort_rate_carvm_omega.FIACARVM_LIAB.for"
if (t <= 0)
	return NO_AVG;

if (fabs(mort_rate_carvm_omega(t - 1) - 1.0) < model_point_amount_threshold)
	return NO_AVG;

double mort_rate = 0.0;
double carvm_mort_base = 0.0;

mort_gender = MALE;
carvm_mort_base = this->carvm_mort_base;

return max(0.0, min(1.0, carvm_mort_base));

}

//@@ END

//@@ START - mva_ratio
// Market Value Adjustment Ratio                                                                                             
// Column:MVA_RATIO
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_mva_ratio(int t) {
//^^^



//^^^

#line 1 "mva_ratio.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

if (t == 0)
	return 1.0;

if (fia->mva_defn == NOT_APPLICABLE 
	|| (fia->stat_res_mva_defn == EXCLUDED && fia->tax_res_mva_defn == EXCLUDED))
	return 1.0;
	
if ((max(fund_val_bef_pfwd(t), contract_val_bef_pfwd(t)) - pfwd_entitlement(t)) < model_point_amount_threshold)
	return 1.0;
	
double mva_guar_yrs_remaining = 0;
double mva_ratio_prelim = 0.0;
double mva_comp_rate = fia->get_comp_rate(fia->mva_comp_rate_id, res_period);

mva_guar_yrs_remaining 
= fia->mva_guar_yrs_remaining((t - 1) * 12
							 + mths_in_first_period
							 + res_period);

if (fia->mva_defn == LINEAR)
	mva_ratio_prelim = 1.0 + (mva_comp_rate_issue - mva_comp_rate)
				             * fia->mva_adj_ratio_mult
				             * mva_guar_yrs_remaining;
else // if (fia->mva_defn == EXPONENTIAL)
	mva_ratio_prelim = pow((1.0 + mva_comp_rate_issue) / (1.0 + mva_comp_rate),
		                   mva_guar_yrs_remaining);
		
if (fia->mva_constraint_defn == NO)
	return mva_ratio_prelim;

// else mva_constraint_defn == YES
double return_of_principle = contract_val_bef_pfwd(t);
double surr_chg = 0.0;
double cash_val_min = 0.0;
double cash_val = 0.0;

if ((t - 1) * 12 + mths_in_first_period + res_period + fia->elapsed_mths 
	<= fia->min_cash_val_mths)
	cash_val_min = return_of_principle;

else if (fia->surr_chg_defn == FUND_VALUE)
	{
	if (fia->surr_chg_timing_defn == BEFORE_MARKET_VALUE_ADJUSTMENT)	
		surr_chg = (max(fund_val_bef_pfwd(t), contract_val_bef_pfwd(t)) 
					- pfwd_entitlement(t))
					* surr_chg_pct(t);
	else
		surr_chg = (max(fund_val_bef_pfwd(t), contract_val_bef_pfwd(t)) 
					- pfwd_entitlement(t))
					* mva_ratio_prelim * surr_chg_pct(t);
	}
else // if (fia->surr_chg_defn == PREMIUM)
	surr_chg = prem_cumul * surr_chg_pct(t);

cash_val = max((max(fund_val_bef_pfwd(t), contract_val_bef_pfwd(t)) 
				- pfwd_entitlement(t))
				* mva_ratio_prelim 
				+ pfwd_entitlement(t)
				- surr_chg, cash_val_min);

if (fabs(max(fund_val_bef_pfwd(t), contract_val_bef_pfwd(t)) - pfwd_entitlement(t)) > model_point_amount_threshold)
	return min(1.0, (max(cash_val, return_of_principle) + surr_chg - pfwd_entitlement(t))
	                / (max(fund_val_bef_pfwd(t), contract_val_bef_pfwd(t)) - pfwd_entitlement(t)));
	
return 1.0;

}

//@@ END

//@@ START - nh_benefits_pv
// PV Nursing Home Benefits                                                                                             
// Column:NH_BENEFITS_PV
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_nh_benefits_pv(int t) {
//^^^



//^^^

#line 1 "nh_benefits_pv.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)
	return NO_AVG;

if (include_nh_defn == NO)
	return NO_AVG;

if (nh_incid_rate(t) <= model_point_amount_threshold)
	return nh_benefits_pv(t - 1);

return nh_benefits_pv(t - 1) 
       + fund_val_bef_pfwd(t) //NH Benefits Base = Fund Value before PFWD
         * surv(t - 1)
		 * (1.0 - mort_rate_carvm(t))
         * nh_incid_rate(t)
         * carvm_disc_factor_non_elect(t); //Non-elective disc factor

}

//@@ END

//@@ START - nh_incid_rate
// Nursing Home Incidence Rate                                                                                             
// Column:NH_INCID_RATE
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_nh_incid_rate(int t) {
//^^^



//^^^

#line 1 "nh_incid_rate.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)
	return NO_AVG;

if (include_nh_defn == NO)
	return NO_AVG;

if (surr_chg_pct(t) <= model_point_amount_threshold || cash_val(t) <= model_point_amount_threshold) //AG33:  Non-Elective Benefit Incidence Rates don't apply immediately after the cash value is depleted or after the surrender charge period
	return 0.0; 

double nh_incid_rate_final = 0.0;

if (fia->gender_mp == BLENDED)
	{
	mort_gender = MALE;
	double nh_incid_rate_1 = max(0.0, min(1.0, nh_incid_base));
	mort_gender = FEMALE; 
	double nh_incid_rate_2 = max(0.0, min(1.0, nh_incid_base));
	
	nh_incid_rate_final = fia->male_sex_pct * nh_incid_rate_1
						+ (1.0 - fia->male_sex_pct) * nh_incid_rate_2;
	}

else // if (gender != BLENDED)
	{
	mort_gender = fia->gender_mp;
	nh_incid_rate_final =  max(0.0, min(1.0, nh_incid_base));
	}

if (t == 1)
	return 1.0 - pow(1.0 - nh_incid_rate_final, mths_in_first_period / 12.0);
else
	return nh_incid_rate_final;

}

//@@ END

//@@ START - pfwd_entitlement
// Penalty Free Withdrawal Entitlement                                                                                             
// Column:PFWD_ENTITLEMENT
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_entitlement(int t) {
//^^^



//^^^

#line 1 "pfwd_entitlement.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

//Once GMWB starts, there is no longer any PFWD entitlement
if (gmwb_max_wdl_amt(t) > 0.0)
	return 0.0;

double pfwd_entitlement = 0.0;
double cv_base = 0.0;	
double av_base = 0.0;
double fpw_pol_yr_valn = fia->pfwd_surr_curr_pol_yr(res_period);

if (fia->pfwd_amt_avail_defn == FUND_VALUE)
	{	
	cv_base = pfwd_pct * contract_val_bef_pfwd(t);
	av_base = pfwd_pct * fund_val_bef_pfwd(t);
	pfwd_entitlement = max(cv_base, av_base);
	}

// Adjust the maximum FPW amount for any previously taken FPWs.
if (t == 0 || (t == 1 && fabs(12.0 - mths_in_first_period) > model_point_amount_threshold))
	return max(0.0, pfwd_entitlement - fpw_pol_yr_valn);

return pfwd_entitlement;

}

//@@ END

//@@ START - pfwd_surr
// Penalty Free Withdrawal                                                                                             
// Column:PFWD_SURR
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_surr(int t) {
//^^^



//^^^

#line 1 "pfwd_surr.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)
	return NO_AVG;

if (fia->gmwb_flag)
	{
	//If GMWB hasn't been taken, assume Full PFW
	if (pfwd_model == "FULL" 
		&& fabs(gmwb_max_wdl_amt(t)) < model_point_amount_threshold)
		return min(pfwd_entitlement(t), fund_val_bef_pfwd(t));

	double pfwd_surr_curr_pol_yr = 0.0;
	if (t == 1 && mths_in_first_period < 12)
		pfwd_surr_curr_pol_yr = fia->pfwd_surr_curr_pol_yr(res_period);

	if (fund_val_bef_pfwd(t) - (gmwb_max_wdl_amt(t) - pfwd_surr_curr_pol_yr) <= model_point_amount_threshold)
		return max(0.0, fund_val_bef_pfwd(t));

	return max(0.0, gmwb_max_wdl_amt(t) - pfwd_surr_curr_pol_yr);
	}

if (pfwd_model == "NONE")
	return 0.0;

return min(pfwd_entitlement(t), fund_val_bef_pfwd(t));

}

//@@ END

//@@ START - pfwd_surr_cumul
// Cumulative Penalty Free Withdrawal                                                                                             
// Column:PFWD_SURR_CUMUL
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_surr_cumul(int t) {
//^^^



//^^^

#line 1 "pfwd_surr_cumul.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

if (t == 0)
	return fia->pfwd_surr_cumul(res_period);
	
return pfwd_surr_cumul(t - 1) + pfwd_surr(t);

}

//@@ END

//@@ START - pfwd_surr_pv
// Present Value of Penalty Free Withdrawals                                                                                             
// Column:PFWD_SURR_PV
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_surr_pv(int t) {
//^^^



//^^^

#line 1 "pfwd_surr_pv.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

if (t == 0)
	return pfwd_surr(t) * surv(t) * carvm_disc_factor_elect_cash_val(t);
	
return pfwd_surr_pv(t - 1)
	   + pfwd_surr(t) * surv(t) * carvm_disc_factor_elect_cash_val(t);

}

//@@ END

//@@ START - pol_yr
// Policy Year                                                                                             
// Column:POL_YR
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_pol_yr(int t) {
//^^^



//^^^

#line 1 "pol_yr.FIACARVM_LIAB.for"
if (t < 0)
	return NO_AVG;

if (t == 0)
	return fia->pol_yr(res_period);
	
if (t == 1 && fabs(12.0 - mths_in_first_period) > model_point_amount_threshold)
	return pol_yr(t - 1);

return pol_yr(t - 1) + 1.0;

}

//@@ END

//@@ START - purch_rate_curr_sprd
// Purchase Rate Current Spread                                                                                             
// Column:PURCH_RATE_CURR_SPRD
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_purch_rate_curr_sprd(int t) {
//^^^



//^^^

#line 1 "purch_rate_curr_sprd.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;
	
return fia->purch_rate_curr_sprd;

}

//@@ END

//@@ START - res_integrated
// Integrated Reserve                                                                                             
// Column:RES_INTEGRATED
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_res_integrated(int t) {
//^^^



//^^^

#line 1 "res_integrated.FIACARVM_LIAB.for"
if (t != 0)
	return NO_AVG;

if (t > max_calc_period)
	return NO_AVG;

// Stop calculations when fund value is exhausted
if (t > 0 && fabs(fund_val_aft_pfwd(t - 1)) < model_point_amount_threshold)
	return NO_AVG;

return max(res_integrated_cash_val(t), res_integrated_annuitzn(t));

}

//@@ END

//@@ START - res_integrated_annuitzn
// Integrated annuitization benefit reserve                                                                                             
// Column:RES_INTEGRATED_ANNUITZN
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_res_integrated_annuitzn(int t) {
//^^^



//^^^

#line 1 "res_integrated_annuitzn.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;
		
if (carvm_calc_annuitzn_defn == NOT_APPLICABLE)
	return NO_AVG;
		
// Stop calculations when fund value is exhausted
if (t > 0 && fabs(fund_val_aft_pfwd(t - 1)) < model_point_amount_threshold)
	return NO_AVG;

double current_pv_ann = dth_benefits_pv(t) 
					    + nh_benefits_pv(t)
					    + pfwd_surr_pv(t) 
					    + ann_benefits_pv(t)
						+ gmwb_ann_benefits_pv(t);
if (t == 0)
    return max(max(res_integrated_annuitzn(t + 1), current_pv_ann),
			fia->fund_val_b(0) * carvm_annuitzn_min_fund_val_pct);
    												  
return max(res_integrated_annuitzn(t + 1), current_pv_ann);

}

//@@ END

//@@ START - res_integrated_cash_val
// Integrated cash value reserve                                                                                             
// Column:RES_INTEGRATED_CASH_VAL
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_res_integrated_cash_val(int t) {
//^^^



//^^^

#line 1 "res_integrated_cash_val.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

// Stop calculations when fund value is exhausted
if (t > 0 && fabs(fund_val_aft_pfwd(t - 1)) < model_point_amount_threshold)
	return NO_AVG;

double current_pv_cash = dth_benefits_pv(t)
				         + nh_benefits_pv(t)
				         + pfwd_surr_pv(t) 
				         + cash_val_pv(t)
						 + gmwb_ann_benefits_pv(t);

if (current_pv_cash > res_integrated_cash_val(t + 1))
	pv_max_period = t;

return max(res_integrated_cash_val(t + 1), current_pv_cash);


}

//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double FIACARVM_LIAB_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.FIACARVM_LIAB.for"
#if 0 // START_EXTERNS
extern SmartArray <SmartArray <double> > fia_cost_array(0);
#endif // END_EXTERNS

#if 0 // START_CLASS
#if defined(__AA_COMP_COMP_H_)
RATES_ECONOMY /*modelobject_name: RATES*/ *rates_ptr;
#else
RATES_ECONOMY /*modelobject_name: FIA_RATES*/ *rates_ptr;
#endif
#endif // END_CLASS

set_hidden_variables(); 
	
return 1.0;

}

//@@ END

//@@ START - surr_chg
// Surrender Charge                                                                                             
// Column:SURR_CHG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg(int t) {
//^^^



//^^^

#line 1 "surr_chg.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

double surr_chg_base = 0.0;
double surr_chg_value = 0.0;
 
if (fia->surr_chg_defn == FUND_VALUE)
	{
	surr_chg_base = max(fund_val_bef_pfwd(t), contract_val_bef_surr(t)) 
		                - pfwd_entitlement(t);		
	}
else if (fia->surr_chg_defn == PREMIUM)
	surr_chg_base = prem_cumul;

surr_chg_value = max(0.0, surr_chg_base * surr_chg_pct(t));

return surr_chg_value;

}

//@@ END

//@@ START - surr_chg_pct
// Surrender Charge Percent                                                                                             
// Column:SURR_CHG_PCT
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg_pct(int t) {
//^^^



//^^^

#line 1 "surr_chg_pct.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period + 1)
	return NO_AVG;

// If continuous CARVM, use surrender charge percentage for the next policy year.
if (carvm_cont_defn == YES)
	return surr_chg_pct_col(t + 1);

return surr_chg_pct_col(t);

}

//@@ END

//@@ START - surr_chg_pct_col
// Surrender Charge Perent Column for Lookup                                                                                             
// Column:SURR_CHG_PCT_COL
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg_pct_col(int t) {
//^^^



//^^^

#line 1 "surr_chg_pct_col.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period + 1)
	return NO_AVG;

return surr_chg_pct_carvm;

}

//@@ END

//@@ START - surv
// Survivors                                                                                             
// Column:SURV
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_surv(int t) {
//^^^



//^^^

#line 1 "surv.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)
	return NO_AVG;

if (t == 0) 
	return 1.0;

if (include_nh_defn == YES)
	return surv(t - 1) * (1.0 - mort_rate_carvm(t)) * (1.0 - nh_incid_rate(t));

return surv(t - 1) * (1.0 - mort_rate_carvm(t));

}

//@@ END

//@@ START - carvm_annuitzn_test_num
// CARVM annuitization stream test number                                                                                             
// Calculated Variable:CARVM_ANNUITZN_TEST_NUM
//========================================================
int FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_annuitzn_test_num() {
//^^^


#line 1 "carvm_annuitzn_test_num.FIACARVM_LIAB.for"
if (model_name == "STAT"
	|| (model_name == "TAX"
		&& fia->tax_res_defn != TAX_EQUALS_STAT
		&& fia->tax_res_defn != _2017_TAX_REFORM))
   {
   if (carvm_calc_annuitzn_defn != NOT_APPLICABLE)
	   return fia->carvm_annuitzn_tests_number;
   }

return 0;

}

//@@ END

//@@ START - gender
// Gender                                                                                             
// Calculated Variable:GENDER
//========================================================
xstring FIACARVM_LIAB_UDF::fiacarvm_liab_gender() {
//^^^


#line 1 "gender.FIACARVM_LIAB.for"
return fia->gender_mp;

}

//@@ END

//@@ START - int_guar_dur
// Interest Guarantee Duration:                                                                                             
// Calculated Variable:INT_GUAR_DUR
//========================================================
int FIACARVM_LIAB_UDF::fiacarvm_liab_int_guar_dur() {
//^^^


#line 1 "int_guar_dur.FIACARVM_LIAB.for"
// Set lookup key and retrieve life valuation rate
valn_guar_dur = 21;

double life_int_rate = carvm_life_int_rate; 

int guar_dur = 0;
for (guar_dur = 0; guar_dur <= 21; guar_dur++)
	{
	if (fia->crediting_rate_gtd <= life_int_rate)
		break;
	}

return guar_dur;

}

//@@ END

//@@ START - issue_age
// Issue Age                                                                                             
// Calculated Variable:ISSUE_AGE
//========================================================
int FIACARVM_LIAB_UDF::fiacarvm_liab_issue_age() {
//^^^


#line 1 "issue_age.FIACARVM_LIAB.for"
return fia->issue_age_mp;

}

//@@ END

//@@ START - issue_date
// Issue Date:                                                                                             
// Calculated Variable:ISSUE_DATE
//========================================================
int FIACARVM_LIAB_UDF::fiacarvm_liab_issue_date() {
//^^^


#line 1 "issue_date.FIACARVM_LIAB.for"
return fia->issue_date;

}

//@@ END

//@@ START - issue_yr
// Issue Year                                                                                             
// Calculated Variable:ISSUE_YR
//========================================================
int FIACARVM_LIAB_UDF::fiacarvm_liab_issue_yr() {
//^^^


#line 1 "issue_yr.FIACARVM_LIAB.for"
return fia->issue_yr;

}

//@@ END

//@@ START - max_calc_period
// Maximum Period to Calc Reserves                                                                                             
// Calculated Variable:MAX_CALC_PERIOD
//========================================================
int FIACARVM_LIAB_UDF::fiacarvm_liab_max_calc_period() {
//^^^


#line 1 "max_calc_period.FIACARVM_LIAB.for"
int fnd = 0;
//int term_to_omega_age;
//int test_age_end = fia->commencement_period + (150 * 12);
//int test_age;
int mat_period = 0;

/*for (test_age = fia->commencement_period + 1; test_age < test_age_end; test_age += 12)
	{
	// Set lookup key
		mort_issue_age = fia->issue_age_mp;
		mort_pol_yr = int((test_age + fia->elapsed_mths - 1) / 12 + 1);
		mort_attained_age = mort_issue_age + mort_pol_yr - 1;
		mort_gender = MALE;


	carvm_mort_base_rate = carvm_mort_base; // 1 lookup key - attained_age

	if (carvm_mort_base_rate >= 1.0)
		{	
		fnd = 1;
		term_to_omega_age = mort_attained_age - mort_issue_age;

		break;
		}
	}*/

for (int i = 1; i <= 121; i++)
	{	
	if (mort_rate_carvm_omega(i) >= 1.0)
		{
		fnd = 1;
		mat_period = i;
		break;
		}
	}

if (!fnd)
	{
	xstring message;

	message = "Unable to calculate Omega for Calc Reserves. ";
	message += "Mortality rates must ascend to 1. ";
	message += "Plan Code: " + xstring(fia->plan_code);
	message += ", Issue Age: " + xstring(issue_age);
								
	log_screen << message << MSG_ERROR;	
	mat_period = 121 - xint((fia->elapsed_mths + res_period) / 12.0) + 1;
	}

// For GMWB model points, need to project beyond carvm_max_dur to handle exercise points
if (fia->gmwb_flag)
	{
	return min(min(fia->maturity_period / 12, mat_period), 
		       t_high / 12);

	}

return min(min(fia->maturity_period / 12, mat_period), 
		   min(t_high / 12, carvm_max_dur));

}

//@@ END

//@@ START - mths_in_first_period
// Months in the First Projection Period                                                                                             
// Calculated Variable:MTHS_IN_FIRST_PERIOD
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_mths_in_first_period() {
//^^^


#line 1 "mths_in_first_period.FIACARVM_LIAB.for"
int val_month = get_mth_from_date(add_mths_to_date(fia->proj_date_adj, res_period));
int issue_month = fia->issue_mth;
double exact_mths;

if (val_month >= issue_month)
      exact_mths = 12.0 + issue_month - val_month - 1.0;
else
      exact_mths = issue_month - val_month - 1.0;

exact_mths += (min(30.0, fia->issue_day) - 1) / 30.0;

if (exact_mths == 0.0)
	return 12.0;
else 
	return exact_mths;

}

//@@ END

//@@ START - mva_comp_rate_issue
// Mva Comp Rate Issue                                                                                             
// Calculated Variable:MVA_COMP_RATE_ISSUE
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_mva_comp_rate_issue() {
//^^^


#line 1 "mva_comp_rate_issue.FIACARVM_LIAB.for"
return fia->mva_comp_rate_issue;

}

//@@ END

//@@ START - pfwd_model
// Penalty Free Withdrawal Model Definition:                                                                                             
// Calculated Variable:PFWD_MODEL
//========================================================
xstring FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_model() {
//^^^


#line 1 "pfwd_model.FIACARVM_LIAB.for"
if (getElementNumber(0) == 1)
	return "FULL";

// if (getElementNumber() other situation)
return "NONE";

}

//@@ END

//@@ START - prem_cumul
// Cumulative Premium                                                                                             
// Calculated Variable:PREM_CUMUL
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_prem_cumul() {
//^^^


#line 1 "prem_cumul.FIACARVM_LIAB.for"
return fia->prem_cumul(res_period);

}

//@@ END


#line 1 "dividend_yield.FIACARVM_LIAB.for"                                                                                   
double FIACARVM_LIAB::dividend_yield(int t, const xstring &eqt_index)
{
if (t < 0 || t > max_calc_period)
	return 0.;

return rates_ptr->get_index_rate(res_period + t * 12, 
				eqt_index,
				GET_DIVIDEND_YIELD,
				EFFECTIVE_ANNUAL);
}



#line 1 "risk_free_rate.FIACARVM_LIAB.for"                                                                                   
double FIACARVM_LIAB::risk_free_rate(int t, double tte)
{
if (t < 0 || t > max_calc_period)
	return 0.0;

int fwd_term = xint((12 - mths_in_first_period) / 12.0);

if (t == 0) 
	{
	return rates_ptr->get_int_rate(res_period,
					"Govt",
					GET_FORWARD_RATE,
					tte,
					fwd_term,
					NOMINAL_SEMIANNUAL,
					NO_SHIFT); //shift_defn
	}

return rates_ptr->get_int_rate(res_period,
				"Govt",
				GET_FORWARD_RATE,
				tte,
				1.0, // foward term
				NOMINAL_SEMIANNUAL,
				NO_SHIFT); //shift_defn
}



#line 1 "set_hidden_variables.FIACARVM_LIAB.for"                                                                                   
void FIACARVM_LIAB::set_hidden_variables(void)
{
if (fia->gmwb_flag)
	gmwb_exercise_point = fia->gmwb_exercise_point;
else 
	gmwb_exercise_point = 0;

return; 
}



#line 1 "time_to_expiry.FIACARVM_LIAB.for"                                                                                   
double FIACARVM_LIAB::time_to_expiry(int t, int fia_mths)
{
if (t < 0 || t > max_calc_period)
	return 0.0;

//time to expiry is in years	
if (t == 1)
	{
	//if crediting period > one year, then add this portion onto number of months left in policy year
	double mths_in_first_crediting_period = (double(fia_mths) - 12.0) 
											+ double(mths_in_first_period);
	double exact_mths = (min(30.0, fia->issue_day) - 1) / 30.0;
	
	//if crediting period < one year AND policy month is beyond the crediting period, reset to equal crediting 
	if (mths_in_first_crediting_period <= 0.0) 
		mths_in_first_crediting_period = double(fia_mths) - exact_mths;

	return mths_in_first_crediting_period / 12.0;
	}

return double(fia_mths) / 12.0;
}



#line 1 "volatility.FIACARVM_LIAB.for"                                                                                   
double FIACARVM_LIAB::volatility(int t, const xstring &eqt_index, double moneyness, double time_to_expiry)
{
if (t < 0 || t > max_calc_period)
	return 0.0;

return rates_ptr->get_index_vol(res_period, 
			eqt_index,
			moneyness,
			time_to_expiry,
			EFFECTIVE_ANNUAL,
			NO_SHIFT);
}



	static FIACARVM_LIAB_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (FIACARVM_LIAB_UDF::*dPXi) (int);
typedef double (FIACARVM_LIAB_UDF::*dPXid) (int, double);
typedef double (FIACARVM_LIAB_UDF::*dPF) ();
typedef double (FIACARVM_LIAB_UDF::*dPFd) (double);
typedef int (FIACARVM_LIAB_UDF::*iPF) ();
typedef int (FIACARVM_LIAB_UDF::*iPFi) (int);
typedef xstring (FIACARVM_LIAB_UDF::*sPF) ();
typedef xstring (FIACARVM_LIAB_UDF::*sPFs) (xstring);

const CashFlowCommonData FIACARVM_LIAB::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "admin_fee", "fiacarvm_liab_admin_fee",  "admin_fee",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_admin_fee, 'E','N', '3', 'N', (size_t)&modelOffset->admin_fee),
	CashFlowCommonData(2, "age_last", "fiacarvm_liab_age_last",  "age_last",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_age_last, 'M','N', '3', 'N', (size_t)&modelOffset->age_last),
	CashFlowCommonData(3, "ann_benefits", "fiacarvm_liab_ann_benefits",  "ann_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_ann_benefits, 'E','Y', '3', 'N', (size_t)&modelOffset->ann_benefits),
	CashFlowCommonData(4, "ann_benefits_pv", "fiacarvm_liab_ann_benefits_pv",  "ann_benefits_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_ann_benefits_pv, 'E','Y', '3', 'N', (size_t)&modelOffset->ann_benefits_pv),
	CashFlowCommonData(5, "ann_purch_factor_curr", "fiacarvm_liab_ann_purch_factor_curr",  "ann_purch_factor_curr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_ann_purch_factor_curr, 'E','Y', '3', 'N', (size_t)&modelOffset->ann_purch_factor_curr),
	CashFlowCommonData(6, "ann_purch_factor_guar", "fiacarvm_liab_ann_purch_factor_guar",  "ann_purch_factor_guar",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_ann_purch_factor_guar, 'E','Y', '3', 'N', (size_t)&modelOffset->ann_purch_factor_guar),
	CashFlowCommonData(7, "ann_valn_factor", "fiacarvm_liab_ann_valn_factor",  "ann_valn_factor",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_ann_valn_factor, 'E','Y', '3', 'N', (size_t)&modelOffset->ann_valn_factor),
	CashFlowCommonData(8, "attained_age", "fiacarvm_liab_attained_age",  "attained_age",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_attained_age, 'E','N', '3', 'N', (size_t)&modelOffset->attained_age),
	CashFlowCommonData(9, "cal_yr", "fiacarvm_liab_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_cal_yr, 'B','N', '3', 'N', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(10, "carvm_ann_disc_factor", "fiacarvm_liab_carvm_ann_disc_factor",  "carvm_ann_disc_factor",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_ann_disc_factor, 'E','Y', '3', 'N', (size_t)&modelOffset->carvm_ann_disc_factor),
	CashFlowCommonData(11, "carvm_disc_factor_elect_annuitzn", "fiacarvm_liab_carvm_disc_factor_elect_annuitzn",  "carvm_disc_factor_elect_annuitzn",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_disc_factor_elect_annuitzn, 'E','N', '3', 'N', (size_t)&modelOffset->carvm_disc_factor_elect_annuitzn),
	CashFlowCommonData(12, "carvm_disc_factor_elect_cash_val", "fiacarvm_liab_carvm_disc_factor_elect_cash_val",  "carvm_disc_factor_elect_cash_val",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_disc_factor_elect_cash_val, 'E','N', '3', 'N', (size_t)&modelOffset->carvm_disc_factor_elect_cash_val),
	CashFlowCommonData(13, "carvm_disc_factor_non_elect", "fiacarvm_liab_carvm_disc_factor_non_elect",  "carvm_disc_factor_non_elect",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_disc_factor_non_elect, 'E','N', '3', 'N', (size_t)&modelOffset->carvm_disc_factor_non_elect),
	CashFlowCommonData(14, "carvm_disc_factor_non_elect_gmwb", "fiacarvm_liab_carvm_disc_factor_non_elect_gmwb",  "carvm_disc_factor_non_elect_gmwb",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_disc_factor_non_elect_gmwb, 'E','N', '3', 'N', (size_t)&modelOffset->carvm_disc_factor_non_elect_gmwb),
	CashFlowCommonData(15, "cash_val", "fiacarvm_liab_cash_val",  "cash_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_cash_val, 'E','N', '3', 'N', (size_t)&modelOffset->cash_val),
	CashFlowCommonData(16, "cash_val_pv", "fiacarvm_liab_cash_val_pv",  "cash_val_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_cash_val_pv, 'E','N', '3', 'N', (size_t)&modelOffset->cash_val_pv),
	CashFlowCommonData(17, "contract_val_bef_pfwd", "fiacarvm_liab_contract_val_bef_pfwd",  "contract_val_bef_pfwd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_contract_val_bef_pfwd, 'E','N', '3', 'N', (size_t)&modelOffset->contract_val_bef_pfwd),
	CashFlowCommonData(18, "contract_val_bef_surr", "fiacarvm_liab_contract_val_bef_surr",  "contract_val_bef_surr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_contract_val_bef_surr, 'E','N', '3', 'N', (size_t)&modelOffset->contract_val_bef_surr),
	CashFlowCommonData(19, "credited_int", "fiacarvm_liab_credited_int",  "credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_credited_int, 'E','N', '3', 'N', (size_t)&modelOffset->credited_int),
	CashFlowCommonData(20, "crediting_rate", "fiacarvm_liab_crediting_rate",  "crediting_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_crediting_rate, 'E','N', '3', 'N', (size_t)&modelOffset->crediting_rate),
	CashFlowCommonData(21, "crediting_rate_fund_value_fixed", "fiacarvm_liab_crediting_rate_fund_value_fixed",  "crediting_rate_fund_value_fixed",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_crediting_rate_fund_value_fixed, 'E','N', '3', 'N', (size_t)&modelOffset->crediting_rate_fund_value_fixed),
	CashFlowCommonData(22, "dth_benefits", "fiacarvm_liab_dth_benefits",  "dth_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_dth_benefits, 'E','N', '3', 'N', (size_t)&modelOffset->dth_benefits),
	CashFlowCommonData(23, "dth_benefits_pv", "fiacarvm_liab_dth_benefits_pv",  "dth_benefits_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_dth_benefits_pv, 'E','N', '3', 'N', (size_t)&modelOffset->dth_benefits_pv),
	CashFlowCommonData(24, "fund_val_aft_pfwd", "fiacarvm_liab_fund_val_aft_pfwd",  "fund_val_aft_pfwd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_aft_pfwd, 'E','N', '3', 'N', (size_t)&modelOffset->fund_val_aft_pfwd),
	CashFlowCommonData(25, "fund_val_b", "fiacarvm_liab_fund_val_b",  "fund_val_b",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_b, 'E','N', '3', 'N', (size_t)&modelOffset->fund_val_b),
	CashFlowCommonData(26, "fund_val_bef_pfwd", "fiacarvm_liab_fund_val_bef_pfwd",  "fund_val_bef_pfwd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_bef_pfwd, 'E','N', '3', 'N', (size_t)&modelOffset->fund_val_bef_pfwd),
	CashFlowCommonData(27, "gmwb_ann_benefits", "fiacarvm_liab_gmwb_ann_benefits",  "gmwb_ann_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_ann_benefits, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_ann_benefits),
	CashFlowCommonData(28, "gmwb_ann_benefits_pv", "fiacarvm_liab_gmwb_ann_benefits_pv",  "gmwb_ann_benefits_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_ann_benefits_pv, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_ann_benefits_pv),
	CashFlowCommonData(29, "gmwb_chg", "fiacarvm_liab_gmwb_chg",  "gmwb_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_chg, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_chg),
	CashFlowCommonData(30, "gmwb_fund_val_aft_pfwd", "fiacarvm_liab_gmwb_fund_val_aft_pfwd",  "gmwb_fund_val_aft_pfwd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_fund_val_aft_pfwd, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_fund_val_aft_pfwd),
	CashFlowCommonData(31, "gmwb_fund_val_bef_pfwd", "fiacarvm_liab_gmwb_fund_val_bef_pfwd",  "gmwb_fund_val_bef_pfwd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_fund_val_bef_pfwd, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_fund_val_bef_pfwd),
	CashFlowCommonData(32, "gmwb_inf_bef", "fiacarvm_liab_gmwb_inf_bef",  "gmwb_inf_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_inf_bef, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_inf_bef),
	CashFlowCommonData(33, "gmwb_max_wdl_amt", "fiacarvm_liab_gmwb_max_wdl_amt",  "gmwb_max_wdl_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_max_wdl_amt, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_max_wdl_amt),
	CashFlowCommonData(34, "gmwb_prem_aft_pfwd", "fiacarvm_liab_gmwb_prem_aft_pfwd",  "gmwb_prem_aft_pfwd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_prem_aft_pfwd, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_prem_aft_pfwd),
	CashFlowCommonData(35, "gmwb_prem_bef_pfwd", "fiacarvm_liab_gmwb_prem_bef_pfwd",  "gmwb_prem_bef_pfwd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_prem_bef_pfwd, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_prem_bef_pfwd),
	CashFlowCommonData(36, "gmwb_rollup_cap_aft_pfwd", "fiacarvm_liab_gmwb_rollup_cap_aft_pfwd",  "gmwb_rollup_cap_aft_pfwd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_rollup_cap_aft_pfwd, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_rollup_cap_aft_pfwd),
	CashFlowCommonData(37, "gmwb_rollup_cap_bef_pfwd", "fiacarvm_liab_gmwb_rollup_cap_bef_pfwd",  "gmwb_rollup_cap_bef_pfwd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_rollup_cap_bef_pfwd, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_rollup_cap_bef_pfwd),
	CashFlowCommonData(38, "guar_min_contract_val", "fiacarvm_liab_guar_min_contract_val",  "guar_min_contract_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_guar_min_contract_val, 'E','N', '3', 'N', (size_t)&modelOffset->guar_min_contract_val),
	CashFlowCommonData(39, "mort_rate_ann_purch_curr", "fiacarvm_liab_mort_rate_ann_purch_curr",  "mort_rate_ann_purch_curr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_mort_rate_ann_purch_curr, 'E','Y', '3', 'N', (size_t)&modelOffset->mort_rate_ann_purch_curr),
	CashFlowCommonData(40, "mort_rate_ann_purch_guar", "fiacarvm_liab_mort_rate_ann_purch_guar",  "mort_rate_ann_purch_guar",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_mort_rate_ann_purch_guar, 'E','Y', '3', 'N', (size_t)&modelOffset->mort_rate_ann_purch_guar),
	CashFlowCommonData(41, "mort_rate_carvm", "fiacarvm_liab_mort_rate_carvm",  "mort_rate_carvm",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_mort_rate_carvm, 'E','Y', '3', 'N', (size_t)&modelOffset->mort_rate_carvm),
	CashFlowCommonData(42, "mort_rate_carvm_annuitzn", "fiacarvm_liab_mort_rate_carvm_annuitzn",  "mort_rate_carvm_annuitzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_mort_rate_carvm_annuitzn, 'E','Y', '3', 'N', (size_t)&modelOffset->mort_rate_carvm_annuitzn),
	CashFlowCommonData(43, "mort_rate_carvm_gmwb", "fiacarvm_liab_mort_rate_carvm_gmwb",  "mort_rate_carvm_gmwb",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_mort_rate_carvm_gmwb, 'E','Y', '3', 'N', (size_t)&modelOffset->mort_rate_carvm_gmwb),
	CashFlowCommonData(44, "mort_rate_carvm_omega", "fiacarvm_liab_mort_rate_carvm_omega",  "mort_rate_carvm_omega",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_mort_rate_carvm_omega, 'E','Y', '3', 'N', (size_t)&modelOffset->mort_rate_carvm_omega),
	CashFlowCommonData(45, "mva_ratio", "fiacarvm_liab_mva_ratio",  "mva_ratio",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_mva_ratio, 'E','N', '3', 'N', (size_t)&modelOffset->mva_ratio),
	CashFlowCommonData(46, "nh_benefits_pv", "fiacarvm_liab_nh_benefits_pv",  "nh_benefits_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_nh_benefits_pv, 'E','N', '3', 'N', (size_t)&modelOffset->nh_benefits_pv),
	CashFlowCommonData(47, "nh_incid_rate", "fiacarvm_liab_nh_incid_rate",  "nh_incid_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_nh_incid_rate, 'E','Y', '3', 'N', (size_t)&modelOffset->nh_incid_rate),
	CashFlowCommonData(48, "pfwd_entitlement", "fiacarvm_liab_pfwd_entitlement",  "pfwd_entitlement",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_entitlement, 'E','N', '3', 'N', (size_t)&modelOffset->pfwd_entitlement),
	CashFlowCommonData(49, "pfwd_surr", "fiacarvm_liab_pfwd_surr",  "pfwd_surr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_surr, 'E','N', '3', 'N', (size_t)&modelOffset->pfwd_surr),
	CashFlowCommonData(50, "pfwd_surr_cumul", "fiacarvm_liab_pfwd_surr_cumul",  "pfwd_surr_cumul",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_surr_cumul, 'E','N', '3', 'N', (size_t)&modelOffset->pfwd_surr_cumul),
	CashFlowCommonData(51, "pfwd_surr_pv", "fiacarvm_liab_pfwd_surr_pv",  "pfwd_surr_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_surr_pv, 'E','N', '3', 'N', (size_t)&modelOffset->pfwd_surr_pv),
	CashFlowCommonData(52, "pol_yr", "fiacarvm_liab_pol_yr",  "pol_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pol_yr, 'B','N', '3', 'N', (size_t)&modelOffset->pol_yr),
	CashFlowCommonData(53, "purch_rate_curr_sprd", "fiacarvm_liab_purch_rate_curr_sprd",  "purch_rate_curr_sprd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_purch_rate_curr_sprd, 'E','Y', '3', 'N', (size_t)&modelOffset->purch_rate_curr_sprd),
	CashFlowCommonData(54, "res_integrated", "fiacarvm_liab_res_integrated",  "res_integrated",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_res_integrated, 'E','N', '3', 'N', (size_t)&modelOffset->res_integrated),
	CashFlowCommonData(55, "res_integrated_annuitzn", "fiacarvm_liab_res_integrated_annuitzn",  "res_integrated_annuitzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_res_integrated_annuitzn, 'E','N', '3', 'N', (size_t)&modelOffset->res_integrated_annuitzn),
	CashFlowCommonData(56, "res_integrated_cash_val", "fiacarvm_liab_res_integrated_cash_val",  "res_integrated_cash_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_res_integrated_cash_val, 'E','N', '3', 'N', (size_t)&modelOffset->res_integrated_cash_val),
	CashFlowCommonData(57, "startup", "fiacarvm_liab_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(58, "surr_chg", "fiacarvm_liab_surr_chg",  "surr_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg, 'E','N', '3', 'N', (size_t)&modelOffset->surr_chg),
	CashFlowCommonData(59, "surr_chg_pct", "fiacarvm_liab_surr_chg_pct",  "surr_chg_pct",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg_pct, 'E','N', '3', 'N', (size_t)&modelOffset->surr_chg_pct),
	CashFlowCommonData(60, "surr_chg_pct_col", "fiacarvm_liab_surr_chg_pct_col",  "surr_chg_pct_col",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg_pct_col, 'M','N', '3', 'P', (size_t)&modelOffset->surr_chg_pct_col),
	CashFlowCommonData(61, "surv", "fiacarvm_liab_surv",  "surv",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_surv, 'E','N', '3', 'N', (size_t)&modelOffset->surv)
};
const CashFlowCommonData* FIACARVM_LIAB::mCFStaticData[] = {
	&FIACARVM_LIAB::mCFStaticData_0[0],
	&FIACARVM_LIAB::mCFStaticData_0[1],
	&FIACARVM_LIAB::mCFStaticData_0[2],
	&FIACARVM_LIAB::mCFStaticData_0[3],
	&FIACARVM_LIAB::mCFStaticData_0[4],
	&FIACARVM_LIAB::mCFStaticData_0[5],
	&FIACARVM_LIAB::mCFStaticData_0[6],
	&FIACARVM_LIAB::mCFStaticData_0[7],
	&FIACARVM_LIAB::mCFStaticData_0[8],
	&FIACARVM_LIAB::mCFStaticData_0[9],
	&FIACARVM_LIAB::mCFStaticData_0[10],
	&FIACARVM_LIAB::mCFStaticData_0[11],
	&FIACARVM_LIAB::mCFStaticData_0[12],
	&FIACARVM_LIAB::mCFStaticData_0[13],
	&FIACARVM_LIAB::mCFStaticData_0[14],
	&FIACARVM_LIAB::mCFStaticData_0[15],
	&FIACARVM_LIAB::mCFStaticData_0[16],
	&FIACARVM_LIAB::mCFStaticData_0[17],
	&FIACARVM_LIAB::mCFStaticData_0[18],
	&FIACARVM_LIAB::mCFStaticData_0[19],
	&FIACARVM_LIAB::mCFStaticData_0[20],
	&FIACARVM_LIAB::mCFStaticData_0[21],
	&FIACARVM_LIAB::mCFStaticData_0[22],
	&FIACARVM_LIAB::mCFStaticData_0[23],
	&FIACARVM_LIAB::mCFStaticData_0[24],
	&FIACARVM_LIAB::mCFStaticData_0[25],
	&FIACARVM_LIAB::mCFStaticData_0[26],
	&FIACARVM_LIAB::mCFStaticData_0[27],
	&FIACARVM_LIAB::mCFStaticData_0[28],
	&FIACARVM_LIAB::mCFStaticData_0[29],
	&FIACARVM_LIAB::mCFStaticData_0[30],
	&FIACARVM_LIAB::mCFStaticData_0[31],
	&FIACARVM_LIAB::mCFStaticData_0[32],
	&FIACARVM_LIAB::mCFStaticData_0[33],
	&FIACARVM_LIAB::mCFStaticData_0[34],
	&FIACARVM_LIAB::mCFStaticData_0[35],
	&FIACARVM_LIAB::mCFStaticData_0[36],
	&FIACARVM_LIAB::mCFStaticData_0[37],
	&FIACARVM_LIAB::mCFStaticData_0[38],
	&FIACARVM_LIAB::mCFStaticData_0[39],
	&FIACARVM_LIAB::mCFStaticData_0[40],
	&FIACARVM_LIAB::mCFStaticData_0[41],
	&FIACARVM_LIAB::mCFStaticData_0[42],
	&FIACARVM_LIAB::mCFStaticData_0[43],
	&FIACARVM_LIAB::mCFStaticData_0[44],
	&FIACARVM_LIAB::mCFStaticData_0[45],
	&FIACARVM_LIAB::mCFStaticData_0[46],
	&FIACARVM_LIAB::mCFStaticData_0[47],
	&FIACARVM_LIAB::mCFStaticData_0[48],
	&FIACARVM_LIAB::mCFStaticData_0[49],
	&FIACARVM_LIAB::mCFStaticData_0[50],
	&FIACARVM_LIAB::mCFStaticData_0[51],
	&FIACARVM_LIAB::mCFStaticData_0[52],
	&FIACARVM_LIAB::mCFStaticData_0[53],
	&FIACARVM_LIAB::mCFStaticData_0[54],
	&FIACARVM_LIAB::mCFStaticData_0[55],
	&FIACARVM_LIAB::mCFStaticData_0[56],
	&FIACARVM_LIAB::mCFStaticData_0[57],
	&FIACARVM_LIAB::mCFStaticData_0[58],
	&FIACARVM_LIAB::mCFStaticData_0[59],
	&FIACARVM_LIAB::mCFStaticData_0[60],
	&FIACARVM_LIAB::mCFStaticData_0[61],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for carvm_annuitzn_ann_type                                                                                       
	const ChoicePair carvm_annuitzn_ann_typeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CERTAIN_ONLY_ANNUITY, "Certain Only Annuity")
		,ChoicePair(StrEnum::CERTAIN_AND_LIFE_ANNUITY, "Certain And Life Annuity")
	};
	const EnumList carvm_annuitzn_ann_typeEnumList(2, carvm_annuitzn_ann_typeChoicePairs);

	// EnumList for carvm_calc_annuitzn_defn                                                                                       
	const ChoicePair carvm_calc_annuitzn_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::CURRENT_AND_GUARANTEED_BENEFITS, "Current And Guaranteed Benefits")
		,ChoicePair(StrEnum::GUARANTEED_BENEFITS, "Guaranteed Benefits")
	};
	const EnumList carvm_calc_annuitzn_defnEnumList(3, carvm_calc_annuitzn_defnChoicePairs);

	// EnumList for carvm_cont_defn                                                                                       
	const ChoicePair carvm_cont_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList carvm_cont_defnEnumList(2, carvm_cont_defnChoicePairs);

	// EnumList for include_nh_defn                                                                                       
	const ChoicePair include_nh_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList include_nh_defnEnumList(2, include_nh_defnChoicePairs);

	// EnumList for mort_gender                                                                                       
	const ChoicePair mort_genderChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MALE, "Male")
		,ChoicePair(StrEnum::FEMALE, "Female")
		,ChoicePair(StrEnum::BLENDED, "Blended")
	};
	const EnumList mort_genderEnumList(3, mort_genderChoicePairs);

	// EnumList for valn_plan_type                                                                                       
	const ChoicePair valn_plan_typeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PLAN_A, "Plan A")
		,ChoicePair(StrEnum::PLAN_B, "Plan B")
		,ChoicePair(StrEnum::PLAN_C, "Plan C")
	};
	const EnumList valn_plan_typeEnumList(3, valn_plan_typeChoicePairs);

	// EnumList for valn_rate_plan_type_elective_annuitzn                                                                                       
	const ChoicePair valn_rate_plan_type_elective_annuitznChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PLAN_A, "Plan A")
		,ChoicePair(StrEnum::PLAN_B, "Plan B")
		,ChoicePair(StrEnum::PLAN_C, "Plan C")
	};
	const EnumList valn_rate_plan_type_elective_annuitznEnumList(3, valn_rate_plan_type_elective_annuitznChoicePairs);

	// EnumList for valn_rate_plan_type_elective_cash_val                                                                                       
	const ChoicePair valn_rate_plan_type_elective_cash_valChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PLAN_A, "Plan A")
		,ChoicePair(StrEnum::PLAN_B, "Plan B")
		,ChoicePair(StrEnum::PLAN_C, "Plan C")
	};
	const EnumList valn_rate_plan_type_elective_cash_valEnumList(3, valn_rate_plan_type_elective_cash_valChoicePairs);

	// EnumList for valn_rate_plan_type_non_elective                                                                                       
	const ChoicePair valn_rate_plan_type_non_electiveChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PLAN_A, "Plan A")
		,ChoicePair(StrEnum::PLAN_B, "Plan B")
		,ChoicePair(StrEnum::PLAN_C, "Plan C")
	};
	const EnumList valn_rate_plan_type_non_electiveEnumList(3, valn_rate_plan_type_non_electiveChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace FIACARVM_LIAB_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(FIACARVM_LIAB::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(FIACARVM_LIAB::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace FIACARVM_LIAB_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void FIACARVM_LIAB::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> FIACARVM_LIAB::mgr_;

	Attribute::Descriptor FIACARVM_LIAB::descriptor_0[] = {
	Descriptor(0, Attribute::STR_ENUM,	"carvm_annuitzn_ann_type", -1, (size_t)&modelOffset->carvm_annuitzn_ann_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &carvm_annuitzn_ann_typeEnumList, Feature(true)),
	Descriptor(1, Attribute::INT,	"carvm_annuitzn_certain_yrs", -1, (size_t)&modelOffset->carvm_annuitzn_certain_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::DOUBLE,	"carvm_annuitzn_min_fund_val_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_annuitzn_min_fund_val_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::DOUBLE,	"carvm_annuitzn_mort_base", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_annuitzn_mort_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::STRING,	"carvm_annuitzn_mort_base_tbl_id", -1, (size_t)&modelOffset->carvm_annuitzn_mort_base_tbl_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::STRING,	"carvm_annuitzn_mort_base_tbl_style", -1, (size_t)&modelOffset->carvm_annuitzn_mort_base_tbl_style,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::INT,	"carvm_annuitzn_mort_improve_base_yr", -1, (size_t)&modelOffset->carvm_annuitzn_mort_improve_base_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::DOUBLE,	"carvm_annuitzn_mort_improve_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_annuitzn_mort_improve_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::DOUBLE,	"carvm_annuitzn_mort_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_annuitzn_mort_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::STRING,	"carvm_annuitzn_tests", -1, (size_t)&modelOffset->carvm_annuitzn_tests,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::STR_ENUM,	"carvm_calc_annuitzn_defn", -1, (size_t)&modelOffset->carvm_calc_annuitzn_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &carvm_calc_annuitzn_defnEnumList, Feature(true)),
	Descriptor(11, Attribute::STR_ENUM,	"carvm_cont_defn", -1, (size_t)&modelOffset->carvm_cont_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &carvm_cont_defnEnumList, Feature(true)),
	Descriptor(12, Attribute::STRING,	"carvm_defn", -1, (size_t)&modelOffset->carvm_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::DOUBLE,	"carvm_gmwb_mort_base", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_gmwb_mort_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::STRING,	"carvm_gmwb_mort_base_tbl_id", -1, (size_t)&modelOffset->carvm_gmwb_mort_base_tbl_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::STRING,	"carvm_gmwb_mort_base_tbl_style", -1, (size_t)&modelOffset->carvm_gmwb_mort_base_tbl_style,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::INT,	"carvm_gmwb_mort_improve_base_yr", -1, (size_t)&modelOffset->carvm_gmwb_mort_improve_base_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::DOUBLE,	"carvm_gmwb_mort_improve_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_gmwb_mort_improve_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::DOUBLE,	"carvm_gmwb_mort_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_gmwb_mort_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::DOUBLE,	"carvm_int_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_int_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::DOUBLE,	"carvm_life_int_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_life_int_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::INT,	"carvm_max_dur", -1, (size_t)&modelOffset->carvm_max_dur,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::DOUBLE,	"carvm_mort_base", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_mort_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(23, Attribute::STRING,	"carvm_mort_base_tbl_id", -1, (size_t)&modelOffset->carvm_mort_base_tbl_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::STRING,	"carvm_mort_base_tbl_style", -1, (size_t)&modelOffset->carvm_mort_base_tbl_style,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(25, Attribute::INT,	"carvm_mort_improve_base_yr", -1, (size_t)&modelOffset->carvm_mort_improve_base_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::DOUBLE,	"carvm_mort_improve_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_mort_improve_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::DOUBLE,	"carvm_mort_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_mort_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(28, Attribute::INT,	"gmwb_exercise_point", -1, (size_t)&modelOffset->gmwb_exercise_point,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(29, Attribute::STR_ENUM,	"include_nh_defn", -1, (size_t)&modelOffset->include_nh_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &include_nh_defnEnumList, Feature(true)),
	Descriptor(30, Attribute::STRING,	"model_name", -1, (size_t)&modelOffset->model_name,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(31, Attribute::INT,	"mort_attained_age", -1, (size_t)&modelOffset->mort_attained_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(32, Attribute::DOUBLE,	"mort_base_curr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mort_base_curr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(33, Attribute::DOUBLE,	"mort_base_guar", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mort_base_guar,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(34, Attribute::INT,	"mort_cal_yr", -1, (size_t)&modelOffset->mort_cal_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(35, Attribute::STR_ENUM,	"mort_gender", -1, (size_t)&modelOffset->mort_gender,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mort_genderEnumList, Feature(true)),
	Descriptor(36, Attribute::INT,	"mort_issue_age", -1, (size_t)&modelOffset->mort_issue_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(37, Attribute::DOUBLE,	"mort_mult_curr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mort_mult_curr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(38, Attribute::DOUBLE,	"mort_mult_guar", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mort_mult_guar,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(39, Attribute::INT,	"mort_pol_yr", -1, (size_t)&modelOffset->mort_pol_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(40, Attribute::DOUBLE,	"nh_incid_base", Descriptor::NOT_INDEXED, (size_t)&modelOffset->nh_incid_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(41, Attribute::DOUBLE,	"pfwd_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pfwd_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(42, Attribute::INT,	"pv_max_period", -1, (size_t)&modelOffset->pv_max_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(43, Attribute::INT,	"res_period", -1, (size_t)&modelOffset->res_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(44, Attribute::DOUBLE,	"surr_chg_pct_carvm", Descriptor::NOT_INDEXED, (size_t)&modelOffset->surr_chg_pct_carvm,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(45, Attribute::INT,	"valn_guar_dur", -1, (size_t)&modelOffset->valn_guar_dur,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(46, Attribute::STR_ENUM,	"valn_plan_type", -1, (size_t)&modelOffset->valn_plan_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &valn_plan_typeEnumList, Feature(true)),
	Descriptor(47, Attribute::STRING,	"valn_rate_cash_settle_defn", -1, (size_t)&modelOffset->valn_rate_cash_settle_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(48, Attribute::STRING,	"valn_rate_int_guar_defn", -1, (size_t)&modelOffset->valn_rate_int_guar_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(49, Attribute::STR_ENUM,	"valn_rate_plan_type_elective_annuitzn", -1, (size_t)&modelOffset->valn_rate_plan_type_elective_annuitzn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &valn_rate_plan_type_elective_annuitznEnumList, Feature(true)),
	Descriptor(50, Attribute::STR_ENUM,	"valn_rate_plan_type_elective_cash_val", -1, (size_t)&modelOffset->valn_rate_plan_type_elective_cash_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &valn_rate_plan_type_elective_cash_valEnumList, Feature(true)),
	Descriptor(51, Attribute::STR_ENUM,	"valn_rate_plan_type_non_elective", -1, (size_t)&modelOffset->valn_rate_plan_type_non_elective,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &valn_rate_plan_type_non_electiveEnumList, Feature(true)),
	Descriptor(52, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(53, Attribute::SCALAR_INT,	"carvm_annuitzn_test_num", -1, (size_t)&modelOffset->carvm_annuitzn_test_num,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_annuitzn_test_num)),
	Descriptor(54, Attribute::SCALAR_STRING,	"gender", -1, (size_t)&modelOffset->gender,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&FIACARVM_LIAB_UDF::fiacarvm_liab_gender)),
	Descriptor(55, Attribute::SCALAR_INT,	"int_guar_dur", -1, (size_t)&modelOffset->int_guar_dur,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIACARVM_LIAB_UDF::fiacarvm_liab_int_guar_dur)),
	Descriptor(56, Attribute::SCALAR_INT,	"issue_age", -1, (size_t)&modelOffset->issue_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIACARVM_LIAB_UDF::fiacarvm_liab_issue_age)),
	Descriptor(57, Attribute::SCALAR_INT,	"issue_date", -1, (size_t)&modelOffset->issue_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIACARVM_LIAB_UDF::fiacarvm_liab_issue_date)),
	Descriptor(58, Attribute::SCALAR_INT,	"issue_yr", -1, (size_t)&modelOffset->issue_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIACARVM_LIAB_UDF::fiacarvm_liab_issue_yr)),
	Descriptor(59, Attribute::SCALAR_INT,	"max_calc_period", -1, (size_t)&modelOffset->max_calc_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIACARVM_LIAB_UDF::fiacarvm_liab_max_calc_period)),
	Descriptor(60, Attribute::SCALAR_DOUBLE,	"mths_in_first_period", -1, (size_t)&modelOffset->mths_in_first_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&FIACARVM_LIAB_UDF::fiacarvm_liab_mths_in_first_period)),
	Descriptor(61, Attribute::SCALAR_DOUBLE,	"mva_comp_rate_issue", -1, (size_t)&modelOffset->mva_comp_rate_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&FIACARVM_LIAB_UDF::fiacarvm_liab_mva_comp_rate_issue)),
	Descriptor(62, Attribute::SCALAR_STRING,	"pfwd_model", -1, (size_t)&modelOffset->pfwd_model,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_model)),
	Descriptor(63, Attribute::SCALAR_DOUBLE,	"prem_cumul", -1, (size_t)&modelOffset->prem_cumul,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&FIACARVM_LIAB_UDF::fiacarvm_liab_prem_cumul)),
	};

	Attribute::Descriptor* FIACARVM_LIAB::descriptorTable[] = {
	&FIACARVM_LIAB::descriptor_0[0],
	&FIACARVM_LIAB::descriptor_0[1],
	&FIACARVM_LIAB::descriptor_0[2],
	&FIACARVM_LIAB::descriptor_0[3],
	&FIACARVM_LIAB::descriptor_0[4],
	&FIACARVM_LIAB::descriptor_0[5],
	&FIACARVM_LIAB::descriptor_0[6],
	&FIACARVM_LIAB::descriptor_0[7],
	&FIACARVM_LIAB::descriptor_0[8],
	&FIACARVM_LIAB::descriptor_0[9],
	&FIACARVM_LIAB::descriptor_0[10],
	&FIACARVM_LIAB::descriptor_0[11],
	&FIACARVM_LIAB::descriptor_0[12],
	&FIACARVM_LIAB::descriptor_0[13],
	&FIACARVM_LIAB::descriptor_0[14],
	&FIACARVM_LIAB::descriptor_0[15],
	&FIACARVM_LIAB::descriptor_0[16],
	&FIACARVM_LIAB::descriptor_0[17],
	&FIACARVM_LIAB::descriptor_0[18],
	&FIACARVM_LIAB::descriptor_0[19],
	&FIACARVM_LIAB::descriptor_0[20],
	&FIACARVM_LIAB::descriptor_0[21],
	&FIACARVM_LIAB::descriptor_0[22],
	&FIACARVM_LIAB::descriptor_0[23],
	&FIACARVM_LIAB::descriptor_0[24],
	&FIACARVM_LIAB::descriptor_0[25],
	&FIACARVM_LIAB::descriptor_0[26],
	&FIACARVM_LIAB::descriptor_0[27],
	&FIACARVM_LIAB::descriptor_0[28],
	&FIACARVM_LIAB::descriptor_0[29],
	&FIACARVM_LIAB::descriptor_0[30],
	&FIACARVM_LIAB::descriptor_0[31],
	&FIACARVM_LIAB::descriptor_0[32],
	&FIACARVM_LIAB::descriptor_0[33],
	&FIACARVM_LIAB::descriptor_0[34],
	&FIACARVM_LIAB::descriptor_0[35],
	&FIACARVM_LIAB::descriptor_0[36],
	&FIACARVM_LIAB::descriptor_0[37],
	&FIACARVM_LIAB::descriptor_0[38],
	&FIACARVM_LIAB::descriptor_0[39],
	&FIACARVM_LIAB::descriptor_0[40],
	&FIACARVM_LIAB::descriptor_0[41],
	&FIACARVM_LIAB::descriptor_0[42],
	&FIACARVM_LIAB::descriptor_0[43],
	&FIACARVM_LIAB::descriptor_0[44],
	&FIACARVM_LIAB::descriptor_0[45],
	&FIACARVM_LIAB::descriptor_0[46],
	&FIACARVM_LIAB::descriptor_0[47],
	&FIACARVM_LIAB::descriptor_0[48],
	&FIACARVM_LIAB::descriptor_0[49],
	&FIACARVM_LIAB::descriptor_0[50],
	&FIACARVM_LIAB::descriptor_0[51],
	&FIACARVM_LIAB::descriptor_0[52],
	&FIACARVM_LIAB::descriptor_0[53],
	&FIACARVM_LIAB::descriptor_0[54],
	&FIACARVM_LIAB::descriptor_0[55],
	&FIACARVM_LIAB::descriptor_0[56],
	&FIACARVM_LIAB::descriptor_0[57],
	&FIACARVM_LIAB::descriptor_0[58],
	&FIACARVM_LIAB::descriptor_0[59],
	&FIACARVM_LIAB::descriptor_0[60],
	&FIACARVM_LIAB::descriptor_0[61],
	&FIACARVM_LIAB::descriptor_0[62],
	&FIACARVM_LIAB::descriptor_0[63],
	nullptr};
	const size_t FIACARVM_LIAB::sDescriptorCount = 64;

//factory
FIACARVM_LIAB* FIACARVM_LIAB::makeThis(int isSubmodel, ModelClass* owner, FIACARVM_LIAB* peer, 
						int mainRebase, const xstring &name, FIACARVM_LIAB_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("FIACARVM_LIAB::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor FIACARVM_LIAB");
#endif
	FIACARVM_LIAB* newP = (FIACARVM_LIAB*)new FIACARVM_LIAB_UDF
   	  ("fiacarvm_liab", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
FIACARVM_LIAB_persistent_object* FIACARVM_LIAB_persistent_object::makeThis(int isSubmodel, ModelClass* owner, FIACARVM_LIAB* peer, 
							int mainRebase, const xstring &name, FIACARVM_LIAB_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("FIACARVM_LIAB_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor FIACARVM_LIAB_persistent_object");
#endif
	FIACARVM_LIAB_persistent_object* newP = (FIACARVM_LIAB_persistent_object*)new FIACARVM_LIAB_persistent_object
   	  ("fiacarvm_liab", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			FIACARVM_LIAB_persistent_object* pd = dynamic_cast<FIACARVM_LIAB_persistent_object*>(product);
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

typedef double (FIACARVM_LIAB_UDF::*dPF) ();
typedef double (FIACARVM_LIAB_UDF::*dPFd) (double);
typedef int (FIACARVM_LIAB_UDF::*iPF) ();
typedef int (FIACARVM_LIAB_UDF::*iPFi) (int);
typedef xstring (FIACARVM_LIAB_UDF::*sPF) ();
typedef xstring (FIACARVM_LIAB_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
FIACARVM_LIAB::FIACARVM_LIAB(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)

	, adco(company_asset_adco)
	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_rates(company_liab_fia_fia_rates)
	, liab(company_liab)
	, rates(company_rates)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (FIACARVM_LIAB_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
FIACARVM_LIAB::FIACARVM_LIAB(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(61, FIACARVM_LIAB::descriptorTable, arrayPersistentObj), Variable(*this)

	, adco(company_asset_adco)
	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_rates(company_liab_fia_fia_rates)
	, liab(company_liab)
	, rates(company_rates)
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
#ifdef __CREATE_EPL_LIAB_CLASS_
       company_liab_epl = 0;
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
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
       company_seg_ann_pba = 0;
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

	for (int cf_no = 1; cf_no <= 61; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (FIACARVM_LIAB_UDF::*dPXi2) (int, int);
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


 void FIACARVM_LIAB::copy_names() {

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
#ifdef __CREATE_EPL_LIAB_CLASS_
		company_liab_epl = (EPL_LIAB*)(findUnique("company|liab|epl"));
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
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
		company_seg_ann_pba = (ANN_PBA_PBA*)(findUnique("company|seg|ann_pba"));
#endif
 }
//copy_names END@2


 void FIACARVM_LIAB::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int FIACARVM_LIAB_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& FIACARVM_LIAB_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double FIACARVM_LIAB_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int FIACARVM_LIAB_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double FIACARVM_LIAB_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double FIACARVM_LIAB_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void FIACARVM_LIAB_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void FIACARVM_LIAB_persistent_object::write(long include_submodels) {
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

	void FIACARVM_LIAB_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void FIACARVM_LIAB_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void FIACARVM_LIAB_persistent_object::write(const xstring& key, long include_submodels) {
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




	FIACARVM_LIAB_persistent_object::~FIACARVM_LIAB_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool FIACARVM_LIAB_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void FIACARVM_LIAB_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void FIACARVM_LIAB_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void FIACARVM_LIAB_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void FIACARVM_LIAB_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void FIACARVM_LIAB_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* FIACARVM_LIAB_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* FIACARVM_LIAB_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* FIACARVM_LIAB_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char FIACARVM_LIAB_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void FIACARVM_LIAB_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
FIACARVM_LIAB_persistent_object::FIACARVM_LIAB_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			FIACARVM_LIAB(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
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
FIACARVM_LIAB::~FIACARVM_LIAB() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void FIACARVM_LIAB::findTargetColumns() {

}
//findTargetColumns END@2
void FIACARVM_LIAB::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void FIACARVM_LIAB::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void FIACARVM_LIAB::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void FIACARVM_LIAB::start_of_projection() {
}
//start_of_projection END@2

void FIACARVM_LIAB::end_of_projection() {
}
//end_of_projection END@2

void FIACARVM_LIAB::start_of_layer() {
}


void FIACARVM_LIAB::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void FIACARVM_LIAB::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void FIACARVM_LIAB::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void FIACARVM_LIAB::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> FIACARVM_LIAB::ddfVector;
BitArray FIACARVM_LIAB::dataVariables(64);
bool FIACARVM_LIAB::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool FIACARVM_LIAB::writeClassInfo = true;

void FIACARVM_LIAB::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, FIACARVM_LIAB::descriptor_0>::dT = FIACARVM_LIAB::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, FIACARVM_LIAB::descriptor_0>::dT = FIACARVM_LIAB::descriptor_0;

