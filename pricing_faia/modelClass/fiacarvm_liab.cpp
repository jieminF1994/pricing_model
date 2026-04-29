
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
#include "ModelClass\fiacarvm_liab_udf.h"
#include "ModelClass\adco_asset.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\asset_asset.h"
#include "ModelClass\automation.h"
#include "ModelClass\a_subport_asset.h"
#include "ModelClass\bond_asset.h"
#include "ModelClass\bond_cf_asset.h"
#include "ModelClass\comp_comp.h"
#include "ModelClass\eio_asset.h"
#include "ModelClass\epa_asset.h"
#include "ModelClass\epl_liab.h"
#include "ModelClass\fiaafund_liab.h"
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

extern MY_DLL2 int use_overlay_code;
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
if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (t == 1 && fabs(12.0 - mths_in_first_year) > model_point_amount_threshold)
	return NO_AVG;

return min(fund_val_e_aig(t - 1), fia->admin_fee_per_pol * fia->policies_inf(fia->res_period));//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula

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
// 20180920 MTC - Removed cap on age_last
/*
if (t > max_calc_period)
	return NO_AVG;
*/
if (t < 0 || t > t_high)//WTW - Gen2 - time guards
	return NO_AVG;
	
if (t == 0)
	return fia->age_last(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula

if (t == 1)
	{
	if (fabs(12.0 - mths_in_first_year) < model_point_amount_threshold)
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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (carvm_calc_annuitzn_defn == NOT_APPLICABLE)
	return NO_AVG;

double ann_benefits_curr_basis = 0.0;
double ann_benefits_guar_basis = 0.0;

if (t == 0 && carvm_calc_annuitzn_defn == CURRENT_AND_GUARANTEED_BENEFITS)
	{
	if (fabs(ann_purch_factor_curr(t)) > rate_ratio_threshold)
		ann_benefits_curr_basis
		= ( ( max(0, fund_val_e_aig(t) - prem_bonus_recapture_aig(t)) ) * (1.0 - fia->purch_rate_curr_load)   // DTL 20181105 : adding consideration for premium bonus recapture
		   - fia->purch_rate_curr_pol_fee * fia->policies_inf(fia->res_period))//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
		   / ann_purch_factor_curr(t);
	}

if (fabs(ann_purch_factor_guar(t)) > rate_ratio_threshold)
	ann_benefits_guar_basis
	= ( max(0, fund_val_e_aig(t) - prem_bonus_recapture_aig(t)) ) / ann_purch_factor_guar(t);    // DTL 20181105 : adding consideration for premium bonus recapture

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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (carvm_calc_annuitzn_defn == NOT_APPLICABLE)
	return NO_AVG;

if (t != 0 || carvm_calc_annuitzn_defn == GUARANTEED_BENEFITS)
	return NO_AVG;

double ann_rate = 0.0;
double ann_factor_certain = 0.0;
double ann_factor_endow = 0.0;
double ann_factor_deferred_life = 0.0;
double ann_factor = 0.0;
double mort_base_local = 0.0;//WTW - Gen2 - Mutating Lookup Term

// Set mortality table lookup keys
// Set life1 lookup keys - special lookup keys are required for mortality variables
//fia->mort_gender = xstring(gender);
fia->mort_gender = gender;//WTW - Gen2 - remove xstring cast
fia->mort_issue_age = issue_age_aig;  // 20201003 DTL
fia->mort_attained_age = attained_age(t);
fia->mort_pol_yr = pol_yr(t);
double purch_rate_curr_sprd_local = 0.0; //WTW - Gen2 - Mutating lookup term used in expression

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
		// Set lookup key
		fia->ann_ben_yr = yr;		
		purch_rate_curr_sprd_local = fia->purch_rate_curr_sprd;//WTW - Gen2 - Mutating lookup term used in expression
		ann_rate = fia->get_comp_rate(fia->purch_rate_curr_comp_rate_id, fia->res_period) - purch_rate_curr_sprd_local;//WTW - Gen2 - Mutating lookup term used in expression//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
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

	fia->ann_ben_yr = 0;

	while (fabs(surv) > rate_ratio_threshold)
		{
		double mort_rate_life1 = 0.0;
		double mort_rate_life2 = 0.0;
		double mort_rate = 0.0;
		yr_counter += 1;
		 
		// Determine annuity discount rate
		if (fia->purch_rate_curr_defn == FIXED_RATE)
			ann_rate = fia->purch_rate_curr_fixed;
		else
			{
			// Set lookup key
			fia->ann_ben_yr += 1;
			purch_rate_curr_sprd_local = fia->purch_rate_curr_sprd;//WTW - Gen2 - Mutating lookup term used in expression
			ann_rate = fia->get_comp_rate(fia->purch_rate_curr_comp_rate_id, fia->res_period) - purch_rate_curr_sprd_local;//WTW - Gen2 - Mutating lookup term used in expression//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
			}

		//WTW - Gen2 - Mutating Lookup Term - moved code around so that working variable lookup is right before call of mortality
		// Determine mortality rate for life 1
		/*if (fia->gender_mp == BLENDED) 
	        fia->mort_gender = MALE;

		mort_rate_life1 = max(0.0, min(1.0, fia->mort_base_curr * fia->mort_mult_curr));*/

		// Determine mortality rate for life 2, if necessary
		if (fia->gender_mp == BLENDED)
			{
			fia->mort_attained_age = attained_age(t) + yr_counter - 1;//WTW - Gen2 - Mutating Lookup Term
			fia->mort_gender = MALE;//WTW - Gen2 - Mutating Lookup Term
			mort_base_local = fia->mort_base_curr;

			fia->mort_pol_yr = pol_yr(t) + yr_counter - 1;	//WTW - Gen2 - Mutating Lookup Term		
			fia->mort_gender = MALE;//WTW - Gen2 - Mutating Lookup Term
			fia->mort_issue_age = issue_age_aig;//WTW - Gen2 - Mutating Lookup Term
			mort_rate_life1 = max(0.0, min(1.0, mort_base_local/*fia->mort_base_curr*/ * fia->mort_mult_curr));//WTW - Gen2 - Mutating Lookup Term
			
			fia->mort_attained_age = attained_age(t) + yr_counter - 1;//WTW - Gen2 - Mutating Lookup Term
			fia->mort_gender = FEMALE;
			mort_base_local = fia->mort_base_curr;
			
			fia->mort_pol_yr = pol_yr(t) + yr_counter - 1;	//WTW - Gen2 - Mutating Lookup Term		
			fia->mort_gender = FEMALE;//WTW - Gen2 - Mutating Lookup Term
			fia->mort_issue_age = issue_age_aig;//WTW - Gen2 - Mutating Lookup Term
			mort_rate_life2 = max(0.0, min(1.0, mort_base_local/*fia->mort_base_curr*/ * fia->mort_mult_curr));//WTW - Gen2 - Mutating Lookup Term
			
		    mort_rate = max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
										+ (1.0 - fia->male_sex_pct) * mort_rate_life2));
             }
		else
			{
			fia->mort_attained_age = attained_age(t) + yr_counter - 1;//WTW - Gen2 - Mutating Lookup Term
			fia->mort_gender = gender;
			mort_base_local = fia->mort_base_curr;
			
			fia->mort_pol_yr = pol_yr(t) + yr_counter - 1;	//WTW - Gen2 - Mutating Lookup Term		
			fia->mort_gender = gender;//WTW - Gen2 - Mutating Lookup Term
			fia->mort_issue_age = issue_age_aig;//WTW - Gen2 - Mutating Lookup Term
			mort_rate = max(0.0, min(1.0, mort_base_local/*fia->mort_base_curr*/ * fia->mort_mult_curr));
			//mort_rate = mort_rate_life1;
			}

		surv_period = (1.0 - mort_rate);
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

		// Update lookup keys	
		//WTW - Gen2 - Mutating Lookup Term
		//fia->mort_attained_age += 1;
		//fia->mort_pol_yr += 1;
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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
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
double mort_base_local = 0.0;//WTW - Gen2 - Mutating Lookup Term

// Guaranteed purchase rate is always a fixed rate
ann_rate = fia->purch_rate_guar_fixed;

// Set mortality table lookup keys
// Set life1 lookup keys - special lookup keys are required for mortality variables
//fia->mort_gender = xstring(gender);
fia->mort_gender = gender;//WTW - Gen2 - remove xstring cast
fia->mort_issue_age = issue_age_aig;  // 20201030 DTL
fia->mort_attained_age = attained_age(t);
fia->mort_pol_yr = pol_yr(t);

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
			double mort_rate_life1 = 0.0;
			double mort_rate_life2 = 0.0;
			double mort_rate = 0.0;
			yr_counter += 1;
		 
			//WTW - Gen2 - Mutating Lookup Term - moved code around so that working variable lookup is right before call of mortality
			// determine mortality rate for life 1
			/*if (fia->gender_mp == BLENDED) 
	            fia->mort_gender = MALE;

			mort_rate_life1 = max(0.0, min(1.0, fia->mort_base_guar * fia->mort_mult_guar));*/

			// determine mortality rate for life 2, if necessary
			if (fia->gender_mp == BLENDED)
				{
				fia->mort_attained_age = attained_age(t) + yr_counter - 1;//WTW - Gen2 - Mutating Lookup Term
				fia->mort_gender = MALE;//WTW - Gen2 - Mutating Lookup Term
				mort_base_local = fia->mort_base_guar;

				fia->mort_pol_yr = pol_yr(t) + yr_counter - 1;	//WTW - Gen2 - Mutating Lookup Term		
				fia->mort_gender = MALE;//WTW - Gen2 - Mutating Lookup Term
				fia->mort_issue_age = issue_age_aig;//WTW - Gen2 - Mutating Lookup Term
				mort_rate_life1 = max(0.0, min(1.0, mort_base_local/*fia->mort_base_guar*/ * fia->mort_mult_guar));//WTW - Gen2 - Mutating Lookup Term
				
				fia->mort_attained_age = attained_age(t) + yr_counter - 1;//WTW - Gen2 - Mutating Lookup Term
				fia->mort_gender = FEMALE;
				mort_base_local = fia->mort_base_guar;
			
				fia->mort_pol_yr = pol_yr(t) + yr_counter - 1;	//WTW - Gen2 - Mutating Lookup Term		
				fia->mort_gender = FEMALE;//WTW - Gen2 - Mutating Lookup Term
				fia->mort_issue_age = issue_age_aig;//WTW - Gen2 - Mutating Lookup Term
				mort_rate_life2 = max(0.0, min(1.0, mort_base_local/*fia->mort_base_guar*/ * fia->mort_mult_guar));//WTW - Gen2 - Mutating Lookup Term
				
			    mort_rate = max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
											+ (1.0 - fia->male_sex_pct) * mort_rate_life2));
			    }
			else
				{
				fia->mort_attained_age = attained_age(t) + yr_counter - 1;//WTW - Gen2 - Mutating Lookup Term
				fia->mort_gender = gender;
				mort_base_local = fia->mort_base_guar;
			
				fia->mort_pol_yr = pol_yr(t) + yr_counter - 1;	//WTW - Gen2 - Mutating Lookup Term		
				fia->mort_gender = gender;//WTW - Gen2 - Mutating Lookup Term
				fia->mort_issue_age = issue_age_aig;//WTW - Gen2 - Mutating Lookup Term

				//mort_rate = mort_rate_life1;
				mort_rate = max(0.0, min(1.0, mort_base_local/*fia->mort_base_guar*/ * fia->mort_mult_guar));		//WTW - Gen2 - Mutating Lookup Term	    
				}

			surv_period = (1.0 - mort_rate);
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

			// update lookup keys
			//WTW - Gen2 - Mutating Lookup Term
			//fia->mort_attained_age += 1;
			//fia->mort_pol_yr += 1;
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
				//WTW - Gen2 - Mutating Lookup Term - moved code around so that working variable lookup is right before call of mortality
				// Set adjusted lookup keys
				/*if (loop == 1)
					{
					fia->mort_attained_age += carvm_annuitzn_certain_yrs;
					fia->mort_pol_yr += carvm_annuitzn_certain_yrs;
					}

               if (loop == 0 )
					fia ->mort_attained_age += - 1; 

				// determine mortality rate for life 1
				if (fia->gender_mp == BLENDED) 
	                fia->mort_gender = MALE;

				mort_rate_life1 = max(0.0, min(1.0, fia->mort_base_guar * fia->mort_mult_guar));

				// determine mortality rate for life 2, if necessary
				if (fia->gender_mp == BLENDED)
					{
					fia->mort_gender = FEMALE;			 
					mort_rate_life2 = max(0.0, min(1.0, fia->mort_base_guar * fia->mort_mult_guar));
				
					mort_rate = max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
											  + (1.0 - fia->male_sex_pct) * mort_rate_life2));
					}
				else
					mort_rate = mort_rate_life1;

				if (loop == 0)
					surv_period_attained_age = (1.0 - mort_rate);
				else
					surv_period_deferred_age = (1.0 - mort_rate);
					*/
				
				if (loop == 1)
					{
					if (fia->gender_mp == BLENDED) 
						{
						// determine mortality rate for life 1
						fia->mort_attained_age = attained_age(t) + carvm_annuitzn_certain_yrs - 1;
						fia->mort_gender = MALE;
						mort_base_local = fia->mort_base_guar;

						fia->mort_pol_yr = pol_yr(t) + carvm_annuitzn_certain_yrs;						
						fia->mort_gender = MALE;
						fia->mort_issue_age = issue_age_aig;
						mort_rate_life1 = max(0.0, min(1.0, mort_base_local/*fia->mort_base_guar*/ * fia->mort_mult_guar));
						
						fia->mort_attained_age = attained_age(t) + carvm_annuitzn_certain_yrs - 1;
						fia->mort_gender = FEMALE;
						mort_base_local = fia->mort_base_guar;

						fia->mort_pol_yr = pol_yr(t) + carvm_annuitzn_certain_yrs;						
						fia->mort_gender = FEMALE;
						fia->mort_issue_age = issue_age_aig;
						mort_rate_life2 = max(0.0, min(1.0, mort_base_local/*fia->mort_base_guar*/ * fia->mort_mult_guar));
				
						mort_rate = max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
											  + (1.0 - fia->male_sex_pct) * mort_rate_life2));
						}
					else
						{
						fia->mort_attained_age = attained_age(t) + carvm_annuitzn_certain_yrs - 1;
						fia->mort_gender = gender;
						mort_base_local = fia->mort_base_guar;
			
						fia->mort_pol_yr = pol_yr(t) + carvm_annuitzn_certain_yrs;			
						fia->mort_gender = gender;
						fia->mort_issue_age = issue_age_aig;

						//mort_rate = mort_rate_life1;
						mort_rate = max(0.0, min(1.0, mort_base_local/*fia->mort_base_guar*/ * fia->mort_mult_guar));		//WTW - Gen2 - Mutating Lookup Term	    
						}
					}

               if (loop == 0 )
					{
					if (fia->gender_mp == BLENDED) 
						{
						// determine mortality rate for life 1
						fia->mort_attained_age = attained_age(t) - 1;
						fia->mort_gender = MALE;
						mort_base_local = fia->mort_base_guar;

						fia->mort_pol_yr = pol_yr(t);						
						fia->mort_gender = MALE;
						fia->mort_issue_age = issue_age_aig;
						mort_rate_life1 = max(0.0, min(1.0, mort_base_local/*fia->mort_base_guar*/ * fia->mort_mult_guar));
						
						fia->mort_attained_age = attained_age(t) - 1;
						fia->mort_gender = FEMALE;
						mort_base_local = fia->mort_base_guar;

						fia->mort_pol_yr = pol_yr(t);						
						fia->mort_gender = FEMALE;
						fia->mort_issue_age = issue_age_aig;
						mort_rate_life2 = max(0.0, min(1.0, mort_base_local/*fia->mort_base_guar*/ * fia->mort_mult_guar));
				
						mort_rate = max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
											  + (1.0 - fia->male_sex_pct) * mort_rate_life2));
						}
					else
						{
						fia->mort_attained_age = attained_age(t) - 1;
						fia->mort_gender = gender;
						mort_base_local = fia->mort_base_guar;
			
						fia->mort_pol_yr = pol_yr(t);			
						fia->mort_gender = gender;
						fia->mort_issue_age = issue_age_aig;

						//mort_rate = mort_rate_life1;
						mort_rate = max(0.0, min(1.0, mort_base_local/*fia->mort_base_guar*/ * fia->mort_mult_guar));		//WTW - Gen2 - Mutating Lookup Term	    
						}
					}

				if (loop == 0)
					surv_period_attained_age = (1.0 - mort_rate);
				else
					surv_period_deferred_age = (1.0 - mort_rate);
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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
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
double mort_base_local = 0.0;//WTW - Gen2 - Mutating Lookup Term

// Set hidden lookup keys for carvm_int_rate
if (model_name_gen2 == "STAT"/*this == fia_carvm_stat*/)//WTW - Gen2 - comparison of distinct pointers error
	{
	valn_carvm_defn = fia->stat_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn = fia->valn_rate_int_guar_defn;
	valn_guar_dur = pol_yr(t);
	valn_plan_type = fia->valn_rate_plan_type_elective_annuitzn;
	valn_issue_yr = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	ann_rate = carvm_int_rate;
	}
else
	{
	valn_carvm_defn = fia->tax_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn = fia->valn_rate_int_guar_defn;
	valn_guar_dur = pol_yr(t);
	valn_plan_type = fia->valn_rate_plan_type_elective_annuitzn;
	valn_issue_yr = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	ann_rate = carvm_int_rate;
	}

//WTW - Gen2 - Mutating Lookup Term - move lookups under stat/tax conditional above
/*valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
valn_int_guar_defn = fia->valn_rate_int_guar_defn;
valn_guar_dur = pol_yr(t);
valn_plan_type = fia->valn_rate_plan_type_elective_annuitzn;
ann_rate = carvm_int_rate;*/

// Set mortality table lookup keys
// Set life1 lookup keys - special lookup keys are required for mortality variables
//mort_gender = xstring(gender);
mort_gender = gender;//WTW - Gen2 - remove xstring cast
mort_issue_age = issue_age_aig;   // 20201030 DTL
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
			double mort_rate_life1 = 0.0;
			double mort_rate_life2 = 0.0;
			double mort_rate = 0.0;
			yr_counter += 1;

			//WTW - Gen2 - Mutating Lookup Term - moved code around so that working variable lookup is right before call of mortality		 
			// determine mortality rate for life 1
			/*if (fia->gender_mp == BLENDED) 
	            mort_gender = MALE;

			mort_rate_life1 = max(0.0, min(1.0, carvm_annuitzn_mort_base * carvm_annuitzn_mort_mult));*/

			// determine mortality rate for life 2, if necessary
			if (fia->gender_mp == BLENDED)
				{
				mort_attained_age = attained_age(t) + yr_counter - 1;//WTW - Gen2 - Mutating Lookup Term
				mort_gender = MALE;//WTW - Gen2 - Mutating Lookup Term
				mort_base_local = carvm_annuitzn_mort_base;

				mort_pol_yr = pol_yr(t) + yr_counter - 1;	//WTW - Gen2 - Mutating Lookup Term		
				mort_gender = MALE;//WTW - Gen2 - Mutating Lookup Term
				mort_issue_age = issue_age_aig;//WTW - Gen2 - Mutating Lookup Term
				mort_rate_life1 = max(0.0, min(1.0, mort_base_local/*carvm_annuitzn_mort_base*/ * carvm_annuitzn_mort_mult));

				mort_attained_age = attained_age(t) + yr_counter - 1;//WTW - Gen2 - Mutating Lookup Term
				mort_gender = FEMALE;//WTW - Gen2 - Mutating Lookup Term
				mort_base_local = carvm_annuitzn_mort_base;

				mort_pol_yr = pol_yr(t) + yr_counter - 1;	//WTW - Gen2 - Mutating Lookup Term		
				mort_gender = FEMALE;//WTW - Gen2 - Mutating Lookup Term
				mort_issue_age = issue_age_aig;//WTW - Gen2 - Mutating Lookup Term
			 
				mort_rate_life2 = max(0.0, min(1.0, mort_base_local/*carvm_annuitzn_mort_base*/ * carvm_annuitzn_mort_mult));
				
			    mort_rate = max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
										  + (1.0 - fia->male_sex_pct) * mort_rate_life2));
                }
			else
				{
				mort_attained_age = attained_age(t) + yr_counter - 1;//WTW - Gen2 - Mutating Lookup Term
				mort_gender = gender;
				mort_base_local = carvm_annuitzn_mort_base;
			
				mort_pol_yr = pol_yr(t) + yr_counter - 1;	//WTW - Gen2 - Mutating Lookup Term		
				mort_gender = gender;//WTW - Gen2 - Mutating Lookup Term
				mort_issue_age = issue_age_aig;//WTW - Gen2 - Mutating Lookup Term

				//mort_rate = mort_rate_life1;
				mort_rate = max(0.0, min(1.0, mort_base_local/*carvm_annuitzn_mort_base*/ * carvm_annuitzn_mort_mult));		//WTW - Gen2 - Mutating Lookup Term	    
				}

 			surv_period = (1.0 - mort_rate);
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

			// update lookup keys
			//WTW - Gen2 - Mutating Lookup Term
			//mort_attained_age += 1;
			//mort_pol_yr += 1;
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
			double mort_rate = 0.0;
			double surv_period_attained_age = 0.0;
			double surv_period_deferred_age = 0.0;
			double disc_factor = 1.0 / (1.0 + ann_rate);
	 
			// run two loops, one to get surv_period_attained_age and one to get surv_period_deferred_age
			for (int loop = 0; loop < 2; loop++) 
				{
				//WTW - Gen2 - Mutating Lookup Term - moved code around so that working variable lookup is right before call of mortality
				// Set adjusted lookup keys
				/*if (loop == 1)
					{
					mort_attained_age += carvm_annuitzn_certain_yrs ;
					mort_pol_yr += carvm_annuitzn_certain_yrs - 1; 
					}
            
				if (loop == 0 )
					mort_attained_age += - 1;  
            
				// determine mortality rate for life 1
				if (fia->gender_mp == BLENDED) 
	                mort_gender = MALE;

				mort_rate_life1 = max(0.0, min(1.0, carvm_annuitzn_mort_base * carvm_annuitzn_mort_mult));

				// determine mortality rate for life 2, if necessary
				if (fia->gender_mp == BLENDED)
					{
					mort_gender = FEMALE;			 
					mort_rate_life2 = max(0.0, min(1.0, carvm_annuitzn_mort_base * carvm_annuitzn_mort_mult));
				
					mort_rate = max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
											  + (1.0 - fia->male_sex_pct) * mort_rate_life2));
					}
				else
					mort_rate = mort_rate_life1;

				if (loop == 0)
					surv_period_attained_age = (1.0 - mort_rate);
				else
					surv_period_deferred_age = (1.0 - mort_rate);
					*/
				if (loop == 1)
					{
					if (fia->gender_mp == BLENDED) 
						{
						// determine mortality rate for life 1
						mort_attained_age = attained_age(t) + carvm_annuitzn_certain_yrs - 1;
						mort_gender = MALE;
						mort_base_local = carvm_annuitzn_mort_base;

						mort_pol_yr = pol_yr(t) + carvm_annuitzn_certain_yrs - 1;						
						mort_gender = MALE;
						mort_issue_age = issue_age_aig;
						mort_rate_life1 = max(0.0, min(1.0, mort_base_local/*carvm_annuitzn_mort_base*/ * carvm_annuitzn_mort_mult));
						
						mort_attained_age = attained_age(t) + carvm_annuitzn_certain_yrs - 1;
						mort_gender = FEMALE;
						mort_base_local = carvm_annuitzn_mort_base;

						mort_pol_yr = pol_yr(t) + carvm_annuitzn_certain_yrs - 1;						
						mort_gender = FEMALE;
						mort_issue_age = issue_age_aig;
						mort_rate_life2 = max(0.0, min(1.0, mort_base_local/*carvm_annuitzn_mort_base*/ * carvm_annuitzn_mort_mult));
				
						mort_rate = max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
											  + (1.0 - fia->male_sex_pct) * mort_rate_life2));
						}
					else
						{
						mort_attained_age = attained_age(t) + carvm_annuitzn_certain_yrs - 1;
						mort_gender = gender;
						mort_base_local = carvm_annuitzn_mort_base;
			
						mort_pol_yr = pol_yr(t) + carvm_annuitzn_certain_yrs - 1;			
						mort_gender = gender;
						mort_issue_age = issue_age_aig;

						//mort_rate = mort_rate_life1;
						mort_rate = max(0.0, min(1.0, mort_base_local/*carvm_annuitzn_mort_base*/ * carvm_annuitzn_mort_mult));		//WTW - Gen2 - Mutating Lookup Term	    
						}
					}

               if (loop == 0 )
					{
					if (fia->gender_mp == BLENDED) 
						{
						// determine mortality rate for life 1
						mort_attained_age = attained_age(t) - 1;
						mort_gender = MALE;
						mort_base_local = carvm_annuitzn_mort_base;

						mort_pol_yr = pol_yr(t);						
						mort_gender = MALE;
						mort_issue_age = issue_age_aig;
						mort_rate_life1 = max(0.0, min(1.0, mort_base_local/*carvm_annuitzn_mort_base*/ * carvm_annuitzn_mort_mult));
						
						mort_attained_age = attained_age(t) - 1;
						mort_gender = FEMALE;
						mort_base_local = carvm_annuitzn_mort_base;

						mort_pol_yr = pol_yr(t);						
						mort_gender = FEMALE;
						mort_issue_age = issue_age_aig;
						mort_rate_life2 = max(0.0, min(1.0, mort_base_local/*carvm_annuitzn_mort_base*/ * carvm_annuitzn_mort_mult));
				
						mort_rate = max(0.0, min(1.0, fia->male_sex_pct * mort_rate_life1
											  + (1.0 - fia->male_sex_pct) * mort_rate_life2));
						}
					else
						{
						mort_attained_age = attained_age(t) - 1;
						mort_gender = gender;
						mort_base_local = carvm_annuitzn_mort_base;
			
						mort_pol_yr = pol_yr(t);			
						mort_gender = gender;
						mort_issue_age = issue_age_aig;

						//mort_rate = mort_rate_life1;
						mort_rate = max(0.0, min(1.0, mort_base_local/*carvm_annuitzn_mort_base*/ * carvm_annuitzn_mort_mult));		//WTW - Gen2 - Mutating Lookup Term	    
						}
					}

				if (loop == 0)
					surv_period_attained_age = (1.0 - mort_rate);
				else
					surv_period_deferred_age = (1.0 - mort_rate);
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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (t == 0)
	return fia->attained_age(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
		
if (t == 1 && fabs(12.0 - mths_in_first_year) > model_point_amount_threshold)
	return attained_age(t - 1);

return attained_age(t - 1) + 1.0;

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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (carvm_calc_annuitzn_defn == NOT_APPLICABLE)
     return NO_AVG;

if (t == 0)
	return 1.0;

//WTW - Gen2 - Mutating Lookup Term - move lookup keys under each stat/tax conditional
double int_rate = 0.0;
// Set hidden lookup keys for carvm_int_rate
if (model_name_gen2 == "STAT"/*this == fia_carvm_stat*/)//WTW - Gen2 - comparison of distinct pointers error
	{
	valn_carvm_defn = fia->stat_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn = fia->valn_rate_int_guar_defn;
	valn_guar_dur = pol_yr(t);
	valn_plan_type = fia->valn_rate_plan_type_elective_annuitzn;
	valn_issue_yr = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	int_rate = carvm_int_rate;
	}
else
	{
	valn_carvm_defn = fia->tax_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn = fia->valn_rate_int_guar_defn;
	valn_guar_dur = pol_yr(t);
	valn_plan_type = fia->valn_rate_plan_type_elective_annuitzn;
	valn_issue_yr = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	int_rate = carvm_int_rate;
	}

/*valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
valn_int_guar_defn = fia->valn_rate_int_guar_defn;
valn_guar_dur = pol_yr(t);
valn_plan_type = fia->valn_rate_plan_type_elective_annuitzn;*/

//double int_rate = carvm_int_rate;
double disc_fac_per = 1.0 / (1.0 + int_rate);

return pow(disc_fac_per, t + mths_in_first_year / 12.0 - 1);

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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (t == 0)
	return 1.0;

//WTW - Gen2 - Mutating Lookup Term - move lookup keys under each stat/tax conditional
double int_rate = 0.0;
// Set hidden lookup keys for carvm_int_rate
if (model_name_gen2 == "STAT"/*this == fia_carvm_stat*/)//WTW - Gen2 - comparison of distinct pointers error
	{
	valn_carvm_defn = fia->stat_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn = fia->valn_rate_int_guar_defn;
	valn_guar_dur = fia->pol_yr(fia->res_period) + t - 1; //WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
	valn_plan_type = fia->valn_rate_plan_type_elective_annuitzn;
	valn_issue_yr = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	int_rate = carvm_int_rate;
	}
else
	{
	valn_carvm_defn = fia->tax_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn = fia->valn_rate_int_guar_defn;
	valn_guar_dur = fia->pol_yr(fia->res_period) + t - 1; //WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
	valn_plan_type = fia->valn_rate_plan_type_elective_annuitzn;
	valn_issue_yr = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	int_rate = carvm_int_rate;
	}

/*valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
valn_int_guar_defn = fia->valn_rate_int_guar_defn;
valn_guar_dur = fia->pol_yr(res_period) + t - 1; 
valn_plan_type = fia->valn_rate_plan_type_elective_annuitzn;*/

//double int_rate = carvm_int_rate;

if (t == 1)
	return 1.0 / pow(1.0 + int_rate, mths_in_first_year / 12.0);

return 1.0 / pow(1.0 + int_rate, mths_in_first_year / 12.0 + t - 1);

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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

//if (t <= 0) // DTL 20200707: NYIA 
if (t == 0)//WTW - Gen2 - cannot merge time guards
	return 1.0;

//WTW - Gen2 - Mutating Lookup Term - move lookup keys under each stat/tax conditional
double int_rate = 0.0;
// Set hidden lookup keys for carvm_int_rate
if (model_name_gen2 == "STAT"/*this == fia_carvm_stat*/)//WTW - Gen2 - comparison of distinct pointers error
	{
	valn_carvm_defn = fia->stat_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn = fia->valn_rate_int_guar_defn;
	valn_guar_dur = int_guar_dur;
	valn_plan_type = fia->valn_rate_plan_type_elective_cash_val;
	valn_issue_yr = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	int_rate = carvm_int_rate;
	}
else
	{
	valn_carvm_defn = fia->tax_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn = fia->valn_rate_int_guar_defn;
	valn_guar_dur = int_guar_dur;
	valn_plan_type = fia->valn_rate_plan_type_elective_cash_val;
	valn_issue_yr = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	int_rate = carvm_int_rate;
	}

/*valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
valn_int_guar_defn = fia->valn_rate_int_guar_defn;
valn_guar_dur = int_guar_dur;
valn_plan_type = fia->valn_rate_plan_type_elective_cash_val;*/

//double int_rate = carvm_int_rate;
double disc_fac_per = 1.0 / (1.0 + int_rate);

if (t == 1)
	disc_fac_per = pow(disc_fac_per, mths_in_first_year / 12.0);

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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (t == 0)
	return 1.0;

//WTW - Gen2 - Mutating Lookup Term - move lookup keys under each stat/tax conditional
double int_rate = 0.0;
if (model_name_gen2 == "STAT"/*this == fia_carvm_stat*/)//WTW - Gen2 - comparison of distinct pointers error
	{
	valn_carvm_defn = fia->stat_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn = fia->valn_rate_int_guar_defn;
	valn_guar_dur = int_guar_dur;
	valn_plan_type = fia->valn_rate_plan_type_non_elective;
	valn_issue_yr = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	int_rate = carvm_int_rate;
	}
else
	{
	valn_carvm_defn = fia->tax_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn = fia->valn_rate_int_guar_defn;
	valn_guar_dur = int_guar_dur;
	valn_plan_type = fia->valn_rate_plan_type_non_elective;
	valn_issue_yr = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	int_rate = carvm_int_rate;
	}

/*valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
valn_int_guar_defn = fia->valn_rate_int_guar_defn;
valn_guar_dur = int_guar_dur;
valn_plan_type = fia->valn_rate_plan_type_non_elective;*/

//double int_rate = carvm_int_rate;
double disc_fac_per = 1.0 / (1.0 + int_rate);

if (t == 1)
	disc_fac_per = pow(disc_fac_per, mths_in_first_year / 12.0);

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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (t == 0)
	return 1.0;

//WTW - Gen2 - Mutating Lookup Term - move lookup keys under each stat/tax conditional
double int_rate = 0.0;
// Set hidden lookup keys for carvm_int_rate
if (model_name_gen2 == "STAT"/*this == fia_carvm_stat*/)//WTW - Gen2 - comparison of distinct pointers error
	{
	valn_carvm_defn = fia->stat_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn = fia->valn_rate_int_guar_defn;
	valn_guar_dur = fia->pol_yr(fia->res_period) + t - 1; //WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
	valn_plan_type = fia->valn_rate_plan_type_non_elective_gmwb_before_exhaust_aig;
	valn_issue_yr = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	int_rate = carvm_int_rate;
	}
else
	{
	valn_carvm_defn = fia->tax_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn = fia->valn_rate_int_guar_defn;
	valn_guar_dur = fia->pol_yr(fia->res_period) + t - 1; //WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
	valn_plan_type = fia->valn_rate_plan_type_non_elective_gmwb_before_exhaust_aig;
	valn_issue_yr = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	int_rate = carvm_int_rate;
	}

/*valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
valn_int_guar_defn = fia->valn_rate_int_guar_defn;
valn_guar_dur = fia->pol_yr(res_period) + t - 1; 

// DTL 20200121 (START): TFS 86514
//valn_plan_type = fia->valn_rate_plan_type_non_elective;
valn_plan_type = fia->valn_rate_plan_type_non_elective_gmwb_before_exhaust_aig;*/
// DTL 20200121 (END): TFS 86514

//double int_rate = carvm_int_rate;

if (t == 1)
	return 1.0 / pow(1.0 + int_rate, mths_in_first_year / 12.0);

return 1.0 / pow(1.0 + int_rate, mths_in_first_year / 12.0 + t - 1);

}


//@@ END

//@@ START - cash_val_b_aig
// Cash value:                                                                                             
// Column:CASH_VAL_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_cash_val_b_aig(int t) {
//^^^



//^^^

#line 1 "cash_val_b_aig.FIACARVM_LIAB.for"
// DTL 20200707
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double fund_val_b_cv	 = fund_val_b_aig(t);
double surr_chg_b_cv	 = surr_chg_b_aig(t);
double csv;

// DTL 20200707: NYIA (START)
if (fia->cash_surrender_value_defn_aig == NYIA_CASH_VALUE)
{
	double mav_b_cv					 = min_accum_val_b_aig(t);
	double max_mav_and_fund_val_b_cv = max(fund_val_b_cv, mav_b_cv);

	csv								 = max(0, max_mav_and_fund_val_b_cv - surr_chg_b_cv);
}
// DTL 20200707: NYIA (END)

else
{
	double prem_bonus_recapture_cv = prem_bonus_recapture_aig(t);
	double min_wdl_val_b_cv	       = min_wdl_val_final_b_aig(t);		//20210608 STW: fix for alternative min wdl value

	csv = max(fund_val_b_cv - surr_chg_b_cv - prem_bonus_recapture_cv, 0.0);
	csv	= max(csv, min_wdl_val_b_cv);

	//20250218 MQ GROP for GMAB.
	if (fia->gmab_ind_aig == 1 && fia->gmab_type_crbg == AICO //AICO only
		&& pol_yr(t) > fia->gmab_csv_grop_yr_aig && fund_val_b_cv > SMALL_DOUBLE)
	{
		csv = max(csv, prem_cumul_prop_wdl_aig(t - 1));
	}
}

return csv;

}


//@@ END

//@@ START - cash_val_b_bef_aig
// Cash value:                                                                                             
// Column:CASH_VAL_B_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_cash_val_b_bef_aig(int t) {
//^^^



//^^^

#line 1 "cash_val_b_bef_aig.FIACARVM_LIAB.for"
// DTL 20200707
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double fund_val_b_bef_cv	 = fund_val_b_bef_aig(t);
double surr_chg_b_bef_cv	 = surr_chg_b_bef_aig(t);
double csv;

// DTL 20200707: NYIA (START)
if (fia->cash_surrender_value_defn_aig == NYIA_CASH_VALUE)
{
	double mav_b_bef_cv					 = min_accum_val_b_bef_aig(t);
	double max_mav_and_fund_val_b_bef_cv = max(fund_val_b_bef_cv, mav_b_bef_cv);

	csv									 = max(0, max_mav_and_fund_val_b_bef_cv - surr_chg_b_bef_cv);
}
// DTL 20200707: NYIA (END)

else
{
	double prem_bonus_recapture_cv = prem_bonus_recapture_aig(t);
	double min_wdl_val_b_bef_cv	   = min_wdl_val_b_bef_aig(t);

	csv = max(fund_val_b_bef_cv - surr_chg_b_bef_cv - prem_bonus_recapture_cv, 0.0);  // DTL 20200317: GLB refactor
	csv	= max(csv, min_wdl_val_b_bef_cv);

	//20250218 MQ GROP for GMAB.
	if (fia->gmab_ind_aig == 1 && fia->gmab_type_crbg == AICO //AICO only
	&& pol_yr(t) > fia->gmab_csv_grop_yr_aig && fund_val_b_bef_cv > SMALL_DOUBLE)
	{
		csv = max(csv, prem_cumul_prop_wdl_aig(t - 1));
	}
}

return csv;

}


//@@ END

//@@ START - cash_val_e_aig
// Cash Surrender Value                                                                                             
// Column:CASH_VAL_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_cash_val_e_aig(int t) {
//^^^



//^^^

#line 1 "cash_val_e_aig.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double csv;

// DTL 20200707: NYIA (START)
if (fia->cash_surrender_value_defn_aig == NYIA_CASH_VALUE)
{
	double fund_val_e_cv			 = fund_val_e_aig(t);
	double mav_e_cv					 = min_accum_val_e_aig(t);
	double max_mav_and_fund_val_e_cv = max(fund_val_e_cv, mav_e_cv);
	double surr_chg_inf_e_cv         = surr_chg_e_aig(t);

	csv                              = max(0, max_mav_and_fund_val_e_cv - surr_chg_inf_e_cv);
}
// DTL 20200707: NYIA (END)
else
{
	csv = max(fund_val_e_aig(t) - surr_chg_e_aig(t) - prem_bonus_recapture_aig(t), 0.0);  // DTL 20200317: GLB refactor
	//csv = max(csv, min_wdl_val_e_aig(t));
	//STW 20210517: use new column for min wdl val e bef, the new column aggregate results from standard and alternative min wdl val calculation
	csv = max(csv, min_wdl_val_final_e_aig(t));

	//20250218 MQ GROP for GMAB.
	if (fia->gmab_ind_aig == 1 && fia->gmab_type_crbg == AICO //AICO only
		&& pol_yr(t) >= fia->gmab_csv_grop_yr_aig && fund_val_e_aig(t) > SMALL_DOUBLE)
	{
		csv = max(csv, prem_cumul_prop_wdl_aig(t));
	}
}

return csv;

}


//@@ END

//@@ START - cash_val_e_bef_aig
// Cash value:                                                                                             
// Column:CASH_VAL_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_cash_val_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "cash_val_e_bef_aig.FIACARVM_LIAB.for"
// DTL 20200707
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double fund_val_e_bef_cv	 = fund_val_e_bef_aig(t);
double surr_chg_e_bef_cv	 = surr_chg_e_bef_aig(t);
double csv;

// DTL 20200707: NYIA (START)
if (fia->cash_surrender_value_defn_aig == NYIA_CASH_VALUE)
{
	double mav_e_bef_cv					 = min_accum_val_e_bef_aig(t);
	double max_mav_and_fund_val_e_bef_cv = max(fund_val_e_bef_cv, mav_e_bef_cv);

	csv									 = max(0, max_mav_and_fund_val_e_bef_cv - surr_chg_e_bef_cv);
}
// DTL 20200707: NYIA (END)

else
{
	double prem_bonus_recapture_cv = prem_bonus_recapture_aig(t);
	//double min_wdl_val_e_bef_cv	   = min_wdl_val_e_bef_aig(t);
	// STW 20210517: use new column for min wdl val e bef, the new column aggregate results from standard and alternative min wdl val calculation
	double min_wdl_val_e_bef_cv	   = min_wdl_val_final_e_bef_aig(t); 

	csv = max(fund_val_e_bef_cv - surr_chg_e_bef_cv - prem_bonus_recapture_cv, 0.0);
	csv	= max(csv, min_wdl_val_e_bef_cv);
}

return csv;

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
if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

/*
DTL 2020624:
	MQ provided this discount rate averaging algorithm.
*/

double weight_cv        = cash_val_weight_aig;

if (carvm_cont_defn == YES)  // DTL 20200707
{
	// Should we just leave this to the value in the assumptions XLS?
	weight_cv = 1.0;
}

double cash_val_b_cv	= cash_val_b_aig(t);
double cash_val_e_cv	= cash_val_e_aig(t);
double cash_val_cv      = weight_cv * cash_val_b_cv + (1.0 - weight_cv) * cash_val_e_cv;

double disc_fct_prev = carvm_disc_factor_elect_cash_val(t - 1);
double disc_fct_cv   = carvm_disc_factor_elect_cash_val(t);
double disc_fct_avg  = weight_cv * disc_fct_prev + (1.0 - weight_cv) * disc_fct_cv;

double surv_prev = surv(t - 1);
double surv_cv   = surv(t);
double surv_avg  = weight_cv * surv_prev + (1.0 - weight_cv) * surv_cv;

double cash_val_pv  = cash_val_cv * surv_avg * disc_fct_avg;

return cash_val_pv; 


}


//@@ END

//@@ START - contract_val_b_aig
// Contract value at beginning of year after discrete cashflows:                                                                                             
// Column:CONTRACT_VAL_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_contract_val_b_aig(int t) {
//^^^



//^^^

#line 1 "contract_val_b_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double contract_val_b_cv;
double contract_val_b_bef_cv = contract_val_b_bef_aig(t);
double withdrawals_cv = pfwd_surr_aig(t);	

contract_val_b_cv = max(0, contract_val_b_bef_cv - withdrawals_cv);

return contract_val_b_cv;

}


//@@ END

//@@ START - contract_val_b_bef_aig
// Contract value at beginning of year:                                                                                             
// Column:CONTRACT_VAL_B_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_contract_val_b_bef_aig(int t) {
//^^^



//^^^

#line 1 "contract_val_b_bef_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double contract_val_b_bef_cv;
if (t == 0)
{
	contract_val_b_bef_cv = fia->contract_val(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else
{
	contract_val_b_bef_cv = contract_val_e_aig(t - 1);
}

return contract_val_b_bef_cv;

}


//@@ END

//@@ START - contract_val_e_aig
// Contract Value Before Surrender Charge                                                                                             
// Column:CONTRACT_VAL_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_contract_val_e_aig(int t) {
//^^^



//^^^

#line 1 "contract_val_e_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double contract_val_e_bef_cv = contract_val_e_bef_aig(t);
double glb_chg_cv = gmwb_chg(t);
double contract_val_e_cv = max(0, contract_val_e_bef_cv - glb_chg_cv);

return contract_val_e_cv;

}


//@@ END

//@@ START - contract_val_e_bef_aig
// Contract Value Before Penalty Free Withdrawal                                                                                             
// Column:CONTRACT_VAL_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_contract_val_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "contract_val_e_bef_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double contract_val_e_bef_cv;
double contract_val_b_cv = contract_val_b_aig(t);
double gmir = fia->crediting_rate_gtd;

double interest_credit_factor;
if (t == 1)
{
	interest_credit_factor = pow(1.0 + gmir, mths_in_first_year / 12.0);
}
else
{
	interest_credit_factor = 1.0 + gmir;
}

contract_val_e_bef_cv = contract_val_b_cv * interest_credit_factor;

return contract_val_e_bef_cv;

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
if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (fund_val_b_aig(t) < model_point_amount_threshold)
	return 0.0;

//20240514 MQ Simplified logic for fixed annuity
if (fia->fixed_annuity_ind_aig == YES)
{
	return fund_val_b_aig(t) * crediting_rate(t);
}

double mths_in_period = (t == 1.0) ? mths_in_first_year : 12.0;
double max_crediting_rate = crediting_rate(t);
double mths_to_closest_eocy_or_eopy = 0.0;
double mths_to_eopy = (t == 1.0) ? mths_in_first_year : 0.0;

// 20221011 SJ: Multi-year strategy change. Crediting rate happens at end of each index term.
int index_term_yrs_cv = (int)fia->sm_fia_account[0]->index_term_aig(fia->res_period);
int index_term_mths_cv		= (int)fia->sm_fia_account[0]->index_term_mths_aig(fia->res_period);
int index_term_elapsed_mth	= mod(fia->res_period, index_term_mths_cv);

double mths_to_eoit; //20221011 SJ: eoit (end of index term).
if (t <= index_term_yrs_cv && index_term_elapsed_mth!= 0)
{
	mths_to_eoit = index_term_mths_cv - index_term_elapsed_mth;
}
else
{
	mths_to_eoit = 0;
}
// 20221011 SJ END


//WTW - Gen2 - comparison of distinct pointers error
if (model_name_gen2 == "TAX"/*this == fia_carvm_tax*/ && fia->issue_yr > 1987) // Intersted guaranteed at a rate higher than valuation rate can only be applied to the end of taxable year
	{ 	
	//Specify the lookup keys
	valn_carvm_defn = fia->tax_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn = fia->valn_rate_int_guar_defn;
	valn_guar_dur = int_guar_dur;
	valn_plan_type = fia->valn_rate_plan_type_non_elective;
	valn_issue_yr = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	max_crediting_rate = carvm_int_rate;
	
	double valn_mth = fia->cal_mth(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula

	if (t == 1)	
		{
		if (valn_mth < fia->issue_mth && mths_in_first_year != 12.0) 
		    mths_to_closest_eocy_or_eopy = mths_in_first_year;			
		else
			mths_to_closest_eocy_or_eopy = 12.0 - valn_mth;
		}				
	else if (t == 2.0 && valn_mth < fia->issue_mth && mths_in_first_year != 12.0 ) 
		mths_to_closest_eocy_or_eopy = 12.0 - valn_mth - mths_in_first_year;		 
	else                                 
		mths_to_closest_eocy_or_eopy  = 0.0;				
		
	mths_to_eopy = mths_in_period  - mths_to_closest_eocy_or_eopy ;
    }

// 20220407 STW: IA STAT change requested by model owner
return max(0.0, fund_val_b_aig(t) 
				* crediting_rate(t) * pow(1.0 + min(crediting_rate(t), max_crediting_rate), mths_to_eoit / (12.0 * index_term_yrs_cv)));



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
// DTL 20200229: new column to split BS vs. table-driven crediting rate logic
if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

//20240514 MQ Simplified logic for fixed annuity 
if (fia->fixed_annuity_ind_aig == YES)
{
	double current_rate = fia->sm_fia_account[0]->crediting_rate_fix(fia->res_period);

	double remaining_mth_current_term = fia->myga_current_term_aig(fia->res_period) * 12 - fia->myga_term_mth_elapsed_eom_aig(fia->res_period);
	int remaining_yr_current_term = ceil(remaining_mth_current_term / 12.);

	if(t == 1 && mths_in_first_year < 12) //first year in inner loop
	{
		double first_yr_crediting_rate = pow(1. + current_rate, mths_in_first_year / 12.) - 1.;

		return first_yr_crediting_rate;
	}
	else if(t <= remaining_yr_current_term) //current rate will be applied til the end of current myga term
	{
		return current_rate;
	}
	else
	{
		fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
		return fia->fa_guarantee_rate;
	}
}

double crediting_rate_cv;
if ( fia->use_option_cost_tables_defn_aig == NO )
{
	throw FatalError("fiacarvm_liab->crediting_rate: Black-Scholes must be updated before use!");
	crediting_rate_cv = crediting_rate_black_scholes_aig(t);
}
else if (fia->secure_cap_ind_crbg == 1 && pol_yr(t) <= fia->surr_chg_period_aig)
{
	crediting_rate_cv = crediting_rate_secure_cap_crbg(t); //20260325 Secure cap
}
else
{
	crediting_rate_cv = crediting_rate_index0_aig(t); //20230105 SJ: The crediting rate column is refactored for model efficiency.
}

return crediting_rate_cv;

}


//@@ END

//@@ START - crediting_rate_black_scholes_aig
// Crediting Rate (Black Scholes):                                                                                             
// Column:CREDITING_RATE_BLACK_SCHOLES_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_crediting_rate_black_scholes_aig(int t) {
//^^^



//^^^

#line 1 "crediting_rate_black_scholes_aig.FIACARVM_LIAB.for"
// DTL 20200229: split this column off from other crediting_rate logic to segregate

if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double cost_of_long_option_pct  = 0.0;
double cost_of_short_option_pct = 0.0;
double net_opt_value			= 0.0;
double accum_option_pct			= 0.0;
double cred_factor				= 0.0;
double fixed_rate				= 0.0;
double tte						= 0.0;
double k_long					= 0.0;
double k_short					= 0.0;
double S						= 0.0;
double rf						= 0.0;
double q						= 0.0;
double sigma_long				= 0.0;
double sigma_short				= 0.0;
double month					= 0.0;
double Average					= 0.0;
double fixed_rate_num			= 0.0;
double option_rate_num			= 0.0;
double mths_remaining_in_period;

for (int i = 0; i < fia->sm_fia_account.size(); i++)
{
	k_long  = fia->sm_fia_account[i]->strike(t, fia->res_period, xint(mths_in_first_year));//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
	k_short = fia->sm_fia_account[i]->strike_cap(t, fia->res_period, xint(mths_in_first_year));//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula

	cost_of_long_option_pct = 0.0;		// DTL 20180914 : Zero out value for multi-index scenarios
	cost_of_short_option_pct = 0.0;	// DTL 20180914 : Zero out value for multi-index scenarios

	rf = risk_free_rate(t, tte); // 20180930 MTC - Fixed assignment scope

	if (fia->sm_fia_account[i]->use_option_cost_tables_defn_aig == NO)  // DTL 20180822 -- Added switch to choose: (1) Black-Scholes or (2) table read-in
	{
		throw FatalError("fiacarvm_liab->crediting_rate: Black-Scholes must be updated before use!");

		/*
		S = fia->sm_fia_account[i]->underlying_price(t, res_period);
		q = dividend_yield(t, fia->sm_fia_account[i]->crediting_eqt_index);
		tte = time_to_expiry(t, fia->sm_fia_account[i]->crediting_mths);
		sigma_long = volatility(t, fia->sm_fia_account[i]->crediting_eqt_index, k_long / S, tte);
		sigma_short = volatility(t, fia->sm_fia_account[i]->crediting_eqt_index, k_short / S, tte);
		rf = risk_free_rate(t, tte); // 20180930 MTC - Fixed assignment scope
	
		if (fia->sm_fia_account[i]->crediting_rate_defn == POINT_TO_POINT)
		{
			cost_of_long_option_pct = bs_opt_val(k_long, tte, S, sigma_long, rf, q, CALL_CODE, CONTINUOUS_PAYOUT_CODE) / k_long; 
			cost_of_short_option_pct = bs_opt_val(k_short, tte, S, sigma_short, rf, q, CALL_CODE, CONTINUOUS_PAYOUT_CODE) / k_long;
		}
		else if (fia->sm_fia_account[i]->crediting_rate_defn == MOVING_AVERAGE)
		{
			if (mod (res_period, fia->sm_fia_account[i]->crediting_mths) == 0.0)
				month = fia->sm_fia_account[i]->crediting_mths;
			else 
				month = mod (res_period, fia->sm_fia_account[i]->crediting_mths);
			
			Average = fia->sm_fia_account[i]->index_val_avg_calc(res_period, month);
			cost_of_long_option_pct = bs_opt_val_levy_asian(k_long, tte, S, Average, sigma_long, rf, q) / k_long; 
			cost_of_short_option_pct = bs_opt_val_levy_asian(k_short, tte, S, Average, sigma_short, rf, q) / k_long;
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

			cost_of_long_option_pct 
			= bs_opt_val_mthly_sum_cap(fia->sm_fia_account[i]->crediting_mths,
										month,
										index_change_sum,
										cap,
										tte,
										rf,
										q,
										sigma_long,
										NOMINAL_SEMIANNUAL,
										EFFECTIVE_ANNUAL);
		}
		else if (fia->sm_fia_account[i]->crediting_rate_defn == FIXED_RATE)
		{
    		fixed_rate = crediting_rate_fund_value_fixed(t);
			fixed_rate_num += fixed_rate * fia->sm_fia_account[i]->fund_val_e(res_period);
		}
		else
		{
			throw NonFatalError("AG35 - Only Point to Point, Moving Average, Monthly Sum Cap and Fixed Rate crediting methods supported");
		}
		*/

	}

	double part_rate;

	if (t == 1)
	{
		part_rate = fia->sm_fia_account[i]->crediting_part_rate(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
	}
	else
	{
		part_rate = fia->sm_fia_account[i]->crediting_part_min;
	}

	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); //WTW - Gen2 - add working variable for lookups that vary by time for character input
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;//WTW - Gen2 - Mutating Lookup Term 

	if (fia->sm_fia_account[i]->crediting_dyn_lever == DYNAMIC_CAP)//WTW - Gen2 - character input that varies by time
	{
		net_opt_value = (cost_of_long_option_pct - cost_of_short_option_pct);
	}
	else if (fia->sm_fia_account[i]->crediting_dyn_lever == DYNAMIC_PARTICIPATION)//WTW - Gen2 - character input that varies by time
	{				
		net_opt_value = cost_of_long_option_pct * part_rate;
	}
	else //Both cap and participation
	{
		net_opt_value = (cost_of_long_option_pct - cost_of_short_option_pct)
						* part_rate;
	}
	
	option_rate_num += net_opt_value * fia->sm_fia_account[i]->fund_val_e(fia->res_period);
}		

if (t == 1)
{
   accum_option_pct =   //fixed_rate_num / fia->fund_val_fixed(res_period) 
						fixed_rate_num / fia->fund_val_b(fia->res_period + 1) //WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
					  * mths_in_first_year / 12.0

					  //+ option_rate_num / fia->fund_val_fixed(res_period)
					  + option_rate_num / fia->fund_val_b(fia->res_period + 1)//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
					  * pow(1.0 + rf, mths_in_first_year / 12.0);
	
	// adjust accum_opt_pct to be effective annual
	accum_option_pct = pow(1.0 + accum_option_pct, 12.0 / mths_in_first_year) - 1.0;
}
else
{
    accum_option_pct =   //fixed_rate_num / fia->fund_val_fixed(res_period) 
						 fixed_rate_num / fia->fund_val_b(fia->res_period + 1) //WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula

					   //+ option_rate_num / fia->fund_val_fixed(res_period) * (1.0 + rf);
					   + option_rate_num / fia->fund_val_b(fia->res_period + 1) * (1.0 + rf);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}

return accum_option_pct;

}


//@@ END

//@@ START - crediting_rate_index0_aig
// Crediting Rate Index0 Aig                                                                                             
// Column:CREDITING_RATE_INDEX0_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_crediting_rate_index0_aig(int t) {
//^^^



//^^^

#line 1 "crediting_rate_index0_aig.FIACARVM_LIAB.for"
/*20230105 SJ: The crediting rate column is refactored. The change in is to minimize the times where get_option_price aig gets called. 
			   During the first year (t=1), it is not needed as outer loop option cost will be used. In subsequent years, option price for guaranteed rate will need to be calculated. 
			   However, guaranteed rate doesn't change very often. Therefore, the codes are changed such that when guaranteed rate is the same as prior year, crediting rate will equal to rate from last year.
*/
if (t < 0 || t > max_calc_period)
	return NO_AVG;

//20221011 SJ: Multi-year strategy change. Crediting rate happens at end of each index term.
int index_term_yrs_cv = (int)fia->sm_fia_account[0]->index_term_aig(fia->res_period);
if (mod(pol_yr(t), index_term_yrs_cv) != 0)
	return 0;
//20221011 SJ END

double current_opt_value, fixed_rate, net_opt_value, accum_option_pct, option_rate_num;
double rf, fund_val_cv, k_long, k_short, cost_of_long_option_pct, cost_of_short_option_pct;

double fixed_rate_num = 0.;

int index_term_mths_cv				= (int)fia->sm_fia_account[0]->index_term_mths_aig(fia->res_period);
int init_index_term_elapsed_mths	= mod(fia->res_period, index_term_mths_cv);
int opt_cost_lookup_month_cv		= max(fia->res_period - init_index_term_elapsed_mths, 0);
double mths_in_first_index_term		= index_term_mths_cv - init_index_term_elapsed_mths;

fund_val_cv			= fia->sm_fia_account[0]->fund_val_b(fia->res_period + 1);
current_opt_value	= fund_val_cv * fia->sm_fia_account[0]->hedge_mkt_val_per_unit_notional(fia->res_period);
						// / index_term_yrs_cv; //20221011 SJ: Remove index term for Multi-year strategy change
	
if (fia->gen2_defn == YES)
	rf = fia_rates->get_misc_rate(opt_cost_lookup_month_cv, "RiskFree", EFFECTIVE_ANNUAL); 
else
	rf = rates->get_misc_rate(opt_cost_lookup_month_cv, "RiskFree", EFFECTIVE_ANNUAL); 

if((fia->res_period >= fia->sm_fia_account[0]->strategy_term_aig(fia->res_period - 1) * 12 + 1) 
	&& (fia->crediting_type_dyn_2nd_strat_aig != "NA")
	&& (fia->crediting_type_dyn_defn_aig == DYNAMIC_SWITCHING_ON))
{
	fia->crediting_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
}
else
{
	fia->crediting_type_dyn_aig = fia->crediting_type_aig;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
StrEnum::EnumValue crediting_rate_defn_local = fia->sm_fia_account[0]->crediting_rate_defn;

if (crediting_rate_defn_local == FIXED_RATE)  //Fixed Strategy
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	fixed_rate = fia->crediting_rate_min;

	fixed_rate_num = fixed_rate * fia->sm_fia_account[0]->fund_val_b(fia->res_period+1);//JYL 20230721: fixing small inconsistency per MQIN's request
	net_opt_value = 0.0;
}

//20221011 SJ: Multi-year strategy change. Crediting rate happens at end of each index term.
if (t <= index_term_yrs_cv && init_index_term_elapsed_mths!= 0) //return outerloop option cost for first index term
{
	if (fabs(fia->fund_val_b(fia->res_period + 1)) < model_point_amount_threshold)
		accum_option_pct = 0.0;
	else
	{
		accum_option_pct =  fixed_rate_num / fia->fund_val_b(fia->res_period + 1) 
						   * mths_in_first_year / 12.0
						   + current_opt_value / fia->fund_val_b(fia->res_period + 1)	
						   * pow(1.0 + rf, mths_in_first_index_term / 12);
		
		// adjust accum_opt_pct to be effective annual
		//accum_option_pct = pow(1.0 + accum_option_pct, index_term_mths_cv / mths_in_first_index_term) - 1.0;
		//JYL 20230721: MQIN requested the above line commented out due to inappropriate conversion, especially for multi-year strategy
	}
	return accum_option_pct;
}
//20221011 SJ END

fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
StrEnum::EnumValue crediting_dyn_lever_local = fia->sm_fia_account[0]->crediting_dyn_lever;

int yrs_to_eoit; //eoit (end of index term).
if (mod(pol_yr(1), index_term_yrs_cv) != 0)
	yrs_to_eoit = index_term_yrs_cv - mod(pol_yr(1), index_term_yrs_cv);
else
	yrs_to_eoit = 0;

int yrs_to_next_eoit = yrs_to_eoit + index_term_yrs_cv + 1;

fia->pol_yr_lookup_gen2 = fia->pol_yr(t);
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
if (crediting_rate_defn_local == POINT_TO_POINT && crediting_dyn_lever_local == DYNAMIC_CAP) //Cap strategy
{
	k_long = 1.0;
	k_short = 1 + index_term_cap_rate_min_aig(t);

	if(t > yrs_to_next_eoit && index_term_cap_rate_min_aig(t) == index_term_cap_rate_min_aig(t - index_term_yrs_cv)) //No need to recalc if guar not changing
		return crediting_rate_index0_aig(t - index_term_yrs_cv);

	cost_of_long_option_pct 
		=   fia->sm_fia_account[0]->get_option_price_aig( opt_cost_lookup_month_cv, k_long, CALL, index_term_mths_cv, index_term_mths_cv );
				// / index_term_yrs_cv; //20221011 SJ: Remove index term for Multi-year strategy change

	cost_of_short_option_pct 
		=   fia->sm_fia_account[0]->get_option_price_aig( opt_cost_lookup_month_cv, k_short, CALL, index_term_mths_cv, index_term_mths_cv );
				// / index_term_yrs_cv; //20221011 SJ: Remove index term for Multi-year strategy change

	net_opt_value = cost_of_long_option_pct - cost_of_short_option_pct;
}
else 
{
	fia->pol_yr_lookup_gen2 = fia->pol_yr(t);
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	if ( crediting_rate_defn_local == POINT_TO_POINT_SPREAD &&  //Spread Strategy
				 (crediting_dyn_lever_local == DYNAMIC_CAP || crediting_dyn_lever_local == DYNAMIC_SPREAD ))
	{
		k_long = 1 + index_term_sprd_rate_max_aig(t);

		if(t > yrs_to_next_eoit && index_term_sprd_rate_max_aig(t) == index_term_sprd_rate_max_aig(t - index_term_yrs_cv)) //No need to recalc if guar not changing
			return crediting_rate_index0_aig(t - index_term_yrs_cv);

		cost_of_long_option_pct 
				=   fia->sm_fia_account[0]->get_option_price_aig( opt_cost_lookup_month_cv, k_long, CALL, index_term_mths_cv, index_term_mths_cv );
				  // / index_term_yrs_cv; //20221011 SJ: Remove index term for Multi-year strategy change

		net_opt_value = cost_of_long_option_pct;
	}
	else
	{
		fia->pol_yr_lookup_gen2 = fia->pol_yr(t);
		fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
		if ( crediting_rate_defn_local == POINT_TO_POINT_SPREAD && 
				  crediting_dyn_lever_local == DYNAMIC_PARTICIPATION) //Dynamic par strategy
		{
			double fixed_spread_rate_cv = fia->sm_fia_account[0]->crediting_spread_rate_aig(fia->res_period);
			double part_rate_cv = index_term_par_rate_min_aig(t);

			if(t > yrs_to_next_eoit && index_term_par_rate_min_aig(t) == index_term_par_rate_min_aig(t - index_term_yrs_cv)) //No need to recalc if guar not changing
				return crediting_rate_index0_aig(t - index_term_yrs_cv);

			if ( part_rate_cv < SMALL_DOUBLE )
			{
				string err_msg = "fiacarvm_liab->crediting_rate_index0_aig(t): division by zero.";
				throw FatalError(xstring(err_msg));
			}

			k_long = 1.0 + fixed_spread_rate_cv / part_rate_cv;

			cost_of_long_option_pct 
					=   fia->sm_fia_account[0]->get_option_price_aig( opt_cost_lookup_month_cv, k_long, CALL, index_term_mths_cv, index_term_mths_cv )
					  // / index_term_yrs_cv //20221011 SJ: Remove index term for Multi-year strategy change
					  * part_rate_cv;
			net_opt_value = cost_of_long_option_pct;
		}
		else
		{				
			fia->pol_yr_lookup_gen2 = fia->pol_yr(t);
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			if ( crediting_dyn_lever_local == DYNAMIC_PARTICIPATION_AND_SPREAD) //Par and Spread
			{
				double sprd_rate_cv = index_term_sprd_rate_max_aig(t);
				double part_rate_cv = index_term_par_rate_min_aig(t);

				if(t > yrs_to_next_eoit && index_term_sprd_rate_max_aig(t) == index_term_sprd_rate_max_aig(t - index_term_yrs_cv)
					&& index_term_par_rate_min_aig(t) == index_term_par_rate_min_aig(t - index_term_yrs_cv)) //No need to recalc if guar not changing
					return crediting_rate_index0_aig(t - index_term_yrs_cv);

				if ( part_rate_cv < SMALL_DOUBLE )
				{
					string err_msg = "fiacarvm_liab->crediting_rate_index0_aig(t): division by zero.";
					throw FatalError(xstring(err_msg));
				}
				
				cost_of_long_option_pct = 
						fia->sm_fia_account[0]->get_option_price_aig(opt_cost_lookup_month_cv, 1 + sprd_rate_cv / part_rate_cv, CALL, index_term_mths_cv, index_term_mths_cv);
						cost_of_long_option_pct *= part_rate_cv;

				net_opt_value = cost_of_long_option_pct;
			}
			//20230118 SJ: add crediting rate for trigger fund.
			else 
			{
				fia->pol_yr_lookup_gen2 = fia->pol_yr(t);
				fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
				if (crediting_dyn_lever_local == DYNAMIC_TRIGGER)
				{
					double trigger_rate_cv = index_term_trigger_rate_min_aig(t);

					if(t > yrs_to_next_eoit && index_term_trigger_rate_min_aig(t) == index_term_trigger_rate_min_aig(t - index_term_yrs_cv))
						return crediting_rate_index0_aig(t - index_term_yrs_cv);

					fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
					string index_id_regex_str = fia->sm_fia_account[0]->cast_xstring_to_string_aig(fia->sm_fia_account[0]->crediting_eqt_index);
					string option_duration_str = "D" + to_string(int(index_term_mths_cv));
				
					string rate_lookup 
						= "BINY_" + index_id_regex_str + "_" + option_duration_str + "_K100";
				
					double option_cost_one_percent = 0.0;
					if (fia->gen2_defn == YES)
						option_cost_one_percent = fia_rates->get_misc_rate(opt_cost_lookup_month_cv, xstring(rate_lookup), EFFECTIVE_ANNUAL);
					else
						option_cost_one_percent = rates->get_misc_rate(opt_cost_lookup_month_cv, xstring(rate_lookup), EFFECTIVE_ANNUAL);
					
					net_opt_value = trigger_rate_cv * option_cost_one_percent; //20231204 ZL: remove 0.01 due to the new format of scenario file
				}
			//20230118 SJ END
				else
				{
					net_opt_value = 0.0;

					fia->pol_yr_lookup_gen2 = fia->pol_yr(t); 
					fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
					if (fia->res_period == 1 && crediting_rate_defn_local != FIXED_RATE)
					{
						string warning_msg = "fiacarvm_liab->crediting_rate_index0_aig(t): You're running a crediting rate strategy that has not yet been coded into the CARVM submodel.";
						log_screen << warning_msg << MSG_ERROR;
					}
				}
			}
		}
	}
}

option_rate_num = net_opt_value * fund_val_cv;

//20221011 SJ: Multi-year strategy change. Crediting rate happens at end of each index term.
if (fabs(fia->fund_val_b(fia->res_period + 1)) < model_point_amount_threshold)
	accum_option_pct = 0.0;
else
	accum_option_pct = fixed_rate_num / fia->fund_val_b(fia->res_period + 1)
						+ option_rate_num / fia->fund_val_b(fia->res_period + 1) * pow(1.0 + rf, index_term_yrs_cv);
//20221011 SJ END

return accum_option_pct;

}


//@@ END

//@@ START - crediting_rate_secure_cap_crbg
// Crediting Rate Secure Cap Crbg                                                                                             
// Column:CREDITING_RATE_SECURE_CAP_CRBG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_crediting_rate_secure_cap_crbg(int t) {
//^^^



//^^^

#line 1 "crediting_rate_secure_cap_crbg.FIACARVM_LIAB.for"
//20260326 New column for secure cap crediting rate
if (t <= 0 || t > max_calc_period)
	return NO_AVG;

if (fia->secure_cap_ind_crbg == 1 && pol_yr(t) <= fia->surr_chg_period_aig)
{
	int index_term = (int)fia->sm_fia_account[0]->index_term_aig(fia->res_period);
	if (mod(pol_yr(t), index_term) != 0)
		return 0;

	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
	double cap_rate = fia->secure_cap_rate_crbg;

	double index_term_mths = index_term * 12;
	int index_term_elapsed_mths	= mod(fia->res_period, index_term_mths);
	int opt_lookup_month = max(fia->res_period - index_term_elapsed_mths, 0);

	double rf;
	if (fia->gen2_defn == YES)
		rf = fia_rates->get_misc_rate(opt_lookup_month, "RiskFree", EFFECTIVE_ANNUAL); 
	else
		rf = rates->get_misc_rate(opt_lookup_month, "RiskFree", EFFECTIVE_ANNUAL); 

	double long_option_cost 
		=  fia->sm_fia_account[0]->get_option_price_aig(opt_lookup_month, 1.0, CALL, index_term_mths, index_term_mths);
				
	double short_option_cost
		=  fia->sm_fia_account[0]->get_option_price_aig(opt_lookup_month, 1. + cap_rate, CALL, index_term_mths, index_term_mths);

	double net_opt_value = long_option_cost - short_option_cost;

	if (fabs(fia->fund_val_b(fia->res_period + 1)) < model_point_amount_threshold)
		return 0.0;
	else
		return net_opt_value * pow(1.0 + rf, index_term);
}

return 0.;



}


//@@ END

//@@ START - dth_benefits_b_bef_aig
// Death benefits:                                                                                             
// Column:DTH_BENEFITS_B_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_dth_benefits_b_bef_aig(int t) {
//^^^



//^^^

#line 1 "dth_benefits_b_bef_aig.FIACARVM_LIAB.for"
// DTL 20200707

if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (t == 1 && carvm_cont_defn == YES)
{
	return 0.0;
}

double dth_ben_base_cv = 0.0;

double fund_val_b_bef_cv		= fund_val_b_bef_aig(t);
double mav_b_bef_cv				= min_accum_val_b_bef_aig(t);
double cash_val_b_bef_cv		= cash_val_b_bef_aig(t);
double mwv_b_bef_cv				= min_wdl_val_b_bef_aig(t);
double prem_bonus_recapture_cv	= prem_bonus_recapture_aig(t);
double contract_val_b_bef_cv	= contract_val_b_bef_aig(t);

if (fia->dth_ben_defn == FUND_VALUE) {
	dth_ben_base_cv = max(fund_val_b_bef_cv, contract_val_b_bef_cv);
}
else if (fia->dth_ben_defn == CASH_VALUE) {
	dth_ben_base_cv = cash_val_b_bef_cv;
}
else if (fia->dth_ben_defn == MAX_FUND_AND_CASH_VALUES) {
	dth_ben_base_cv = max(fund_val_b_bef_cv, cash_val_b_bef_cv);
}
else if (fia->dth_ben_defn == MAX_FUND_VALUE_AND_MWV) {
	dth_ben_base_cv = max(max( 0 , fund_val_b_bef_cv - prem_bonus_recapture_cv ), mwv_b_bef_cv);
}
// DTL 20200707L: NYIA
else if (fia->dth_ben_defn == NYIA_DEATH_BENEFIT)
{
	dth_ben_base_cv = max(mav_b_bef_cv, fund_val_b_bef_cv);
}
// DTL 20200707: NYIA
else {
	throw FatalError("Unhandled fia->dth_ben_def requested in fia_carvm_stat->dth_benefits!");
}

//20250218 MQ GROP for GMAB.
if (fia->gmab_ind_aig == 1 && fia->gmab_type_crbg == AICO //AICO only
	&& pol_yr(t) > fia->gmab_csv_grop_yr_aig && fund_val_b_bef_cv > SMALL_DOUBLE)
{
	dth_ben_base_cv = max(dth_ben_base_cv, prem_cumul_prop_wdl_aig(t - 1));
}

double deaths_cv;
if (carvm_cont_defn == YES)
{
	deaths_cv = surv(t - 2) * dth_claim_rate_experience_aig(t - 1);
}
else
{
	deaths_cv = surv(t - 1) * dth_claim_rate_experience_aig(t);
}

double dth_benefits_cv  = dth_ben_base_cv * deaths_cv;
return dth_benefits_cv;

}


//@@ END

//@@ START - dth_benefits_e_aig
// Death Benefit                                                                                             
// Column:DTH_BENEFITS_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_dth_benefits_e_aig(int t) {
//^^^



//^^^

#line 1 "dth_benefits_e_aig.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double dth_ben_base_cv = 0.0;

double fund_val_e_cv           = fund_val_e_aig(t);
double mav_e_cv                = min_accum_val_e_aig(t);
double cash_val_e_cv           = cash_val_e_aig(t);
//double mwv_e_cv                = min_wdl_val_e_aig(t);
//STW 20210517: use new column for min wdl val e bef, the new column aggregate results from standard and alternative min wdl val calculation
double mwv_e_cv                = min_wdl_val_final_e_aig(t);
double prem_bonus_recapture_cv = prem_bonus_recapture_aig(t);
double contract_val_e_cv       = contract_val_e_aig(t);

if (fia->dth_ben_defn == FUND_VALUE) {
	dth_ben_base_cv = max(fund_val_e_cv, contract_val_e_cv);
}
else if (fia->dth_ben_defn == CASH_VALUE) {
	dth_ben_base_cv = cash_val_e_cv;
}
else if (fia->dth_ben_defn == MAX_FUND_AND_CASH_VALUES) {
	dth_ben_base_cv = max(fund_val_e_cv, cash_val_e_cv);
}
else if (fia->dth_ben_defn == MAX_FUND_VALUE_AND_MWV) {
	dth_ben_base_cv = max(max( 0 , fund_val_e_cv - prem_bonus_recapture_cv ), mwv_e_cv);
}
// 20200603 DTL: NYIA
else if (fia->dth_ben_defn == NYIA_DEATH_BENEFIT)
{
	dth_ben_base_cv = max(mav_e_cv, fund_val_e_cv);
}
// 20200603 DTL: NYIA
else {
	throw FatalError("Unhandled fia->dth_ben_def requested in fia_carvm_stat->dth_benefits!");
}

//AICO GMDB
if (fia->gmab_ind_aig == 1 && fia->gmab_type_crbg == AICO 
	&& pol_yr(t) >= fia->gmab_csv_grop_yr_aig && fund_val_e_cv > SMALL_DOUBLE)
{
	dth_ben_base_cv = max(dth_ben_base_cv, prem_cumul_prop_wdl_aig(t));
}

double deaths_cv       = surv(t - 1) * dth_claim_rate_experience_aig(t);
double dth_benefits_cv = dth_ben_base_cv * deaths_cv;

return dth_benefits_cv;

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
if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

// 20200624 DTL
double weight_cv     = dth_benefits_weight_aig;

if (carvm_cont_defn == YES) // DTL 20200707
{
	// Should we just leave this to the value in the assumptions XLS?
	weight_cv = 1.0;
}

/*
DTL 20200624:
	MQ provided this discount rate averaging algorithm.
*/

double disc_fct_prev = carvm_disc_factor_non_elect(t - 1);
double disc_fct_cv   = carvm_disc_factor_non_elect(t);
double disc_fct_avg  = weight_cv * disc_fct_prev + (1.0 - weight_cv) * disc_fct_cv;
// 20200624 DTL

double dth_benefits_pv_prev = dth_benefits_pv(t - 1);

double dth_benefits_b_bef_cv = dth_benefits_b_bef_aig(t);
double dth_benefits_e_cv	 = dth_benefits_e_aig(t);
double dth_benefits_avg		 = weight_cv * dth_benefits_b_bef_cv + (1.0 - weight_cv) * dth_benefits_e_cv;
double dth_benefits_pv_cv    = dth_benefits_pv_prev + dth_benefits_avg * disc_fct_avg;

return dth_benefits_pv_cv;

}


//@@ END

//@@ START - dth_claim_rate_blended_experience_aig
// Death Claim Rate Blended on Experience Basis:                                                                                             
// Column:DTH_CLAIM_RATE_BLENDED_EXPERIENCE_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_dth_claim_rate_blended_experience_aig(int t) {
//^^^



//^^^

#line 1 "dth_claim_rate_blended_experience_aig.FIACARVM_LIAB.for"
/*******************************************************************
 *  DTL 20200121: TFS 86514
 *
 *  Created new column to copy over some logic from fia_liab to
 *  here.
 *******************************************************************/

if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return 0.0;

int policy_year = (int)pol_yr(t);
double mort_rate = dth_claim_ann_rate_calc_aig(t, policy_year, EXPERIENCE, BLENDED);

return mort_rate;

}


//@@ END

//@@ START - dth_claim_rate_experience_aig
// Death Claim Rate under Experience Basis for the Policy:                                                                                             
// Column:DTH_CLAIM_RATE_EXPERIENCE_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_dth_claim_rate_experience_aig(int t) {
//^^^



//^^^

#line 1 "dth_claim_rate_experience_aig.FIACARVM_LIAB.for"
/*******************************************************************
 *  DTL 20200121: TFS 86514
 *
 *  Created new column to copy over some logic from fia_liab to
 *  here.
 *******************************************************************/
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double mort_rate;

if (gender == BLENDED)
{
	mort_rate = dth_claim_rate_blended_experience_aig(t);
}
else if (gender == MALE)
{
	mort_rate = dth_claim_rate_male_experience_aig(t);
}
else if (gender == FEMALE)
{
	mort_rate = dth_claim_rate_female_experience_aig(t);
}
else if (gender == JOINT)
{
	mort_rate = dth_claim_rate_last_survivor_experience_aig(t);
}
else
{
	throw FatalError("Unhandled `fiacarvm_liab->gender` in `fiacarvm_liab->dth_claim_rate_experience_aig`!");
}

return mort_rate;

}


//@@ END

//@@ START - dth_claim_rate_female_experience_aig
// Death Claim Rate Female on Experience Basis:                                                                                             
// Column:DTH_CLAIM_RATE_FEMALE_EXPERIENCE_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_dth_claim_rate_female_experience_aig(int t) {
//^^^



//^^^

#line 1 "dth_claim_rate_female_experience_aig.FIACARVM_LIAB.for"
/*******************************************************************
 *  DTL 20200121: TFS 86514
 *
 *  Created new column to copy over some logic from fia_liab to
 *  here.
 *******************************************************************/
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return 1.0;//NO_AVG;//WTW - Gen2 - cannot merge time guards

if (t > fia->term_to_omega_age * 12)
{
	return 1.0;
}

int policy_year = (int)pol_yr(t);
double qx = dth_claim_ann_rate_calc_aig(t, policy_year, EXPERIENCE, FEMALE);

return qx;

}


//@@ END

//@@ START - dth_claim_rate_last_survivor_experience_aig
// Death Claim Rate Monthly Joint on Experience Basis:                                                                                             
// Column:DTH_CLAIM_RATE_LAST_SURVIVOR_EXPERIENCE_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_dth_claim_rate_last_survivor_experience_aig(int t) {
//^^^



//^^^

#line 1 "dth_claim_rate_last_survivor_experience_aig.FIACARVM_LIAB.for"
/*******************************************************************
 *  DTL 20200121: TFS 86514
 *
 *  Created new column to copy over some logic from fia_liab to
 *  here.
 *******************************************************************/

if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return 0.0;

double policies_last_survivor_bom = policies_last_survivor_experience_aig(t - 1);
double policies_last_survivor_eom = policies_last_survivor_experience_aig(t);

double qxy_bar;

if (policies_last_survivor_bom > SMALL_DOUBLE)
{
	qxy_bar = 1.0 - ( policies_last_survivor_eom / policies_last_survivor_bom );
}
else
{
	qxy_bar = 1.0;
}

return qxy_bar;

}


//@@ END

//@@ START - dth_claim_rate_male_experience_aig
// Death Claim Rate Male on Experience Basis:                                                                                             
// Column:DTH_CLAIM_RATE_MALE_EXPERIENCE_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_dth_claim_rate_male_experience_aig(int t) {
//^^^



//^^^

#line 1 "dth_claim_rate_male_experience_aig.FIACARVM_LIAB.for"
/*******************************************************************
 *  DTL 20200121: TFS 86514
 *
 *  Created new column to copy over some logic from fia_liab to
 *  here.
 *******************************************************************/
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return 1.0;//NO_AVG;//WTW - Gen2 - cannot merge time guards

if (t > fia->term_to_omega_age * 12)
{
	return 1.0;
}

int policy_year = (int)pol_yr(t);
double qx = dth_claim_ann_rate_calc_aig(t, policy_year, EXPERIENCE, MALE);

return qx;

}


//@@ END

//@@ START - fund_val_b_aig
// Fund value at beginning of period after administration fee and withdrawal:                                                                                             
// Column:FUND_VAL_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_b_aig(int t) {
//^^^



//^^^

#line 1 "fund_val_b_aig.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
{
	return NO_AVG;
}

double fund_val_b_cv;
double fund_val_b_bef_cv = fund_val_b_bef_aig(t);

if (fund_val_b_bef_cv < model_point_amount_threshold)
{
	fund_val_b_cv = 0.0;
}
else
{
	double admin_fee_cv  = admin_fee(t);
	double pfwd_surr_cv  = pfwd_surr_aig(t);

	// DTL 20200707: NYIA (START)
	if (fia->fund_val_defn_aig == EIV)
	{
		double mav_b_bef_cv            = min_accum_val_b_bef_aig(t);
		double max_mav_and_fund_val_cv = max(mav_b_bef_cv, fund_val_b_bef_cv);
		double reduction_fct_cv;

		if (max_mav_and_fund_val_cv < SMALL_DOUBLE)
		{
			reduction_fct_cv		   = 0.0;
		}
		else
		{
			reduction_fct_cv           = 1.0 - pfwd_surr_cv / max_mav_and_fund_val_cv;
		}
		
		fund_val_b_cv                  = fund_val_b_bef_cv * reduction_fct_cv;
		fund_val_b_cv                  = max(0.0, fund_val_b_cv - admin_fee_cv);
	}
	// DTL 20200707: NYIA (END)
	else
	{
		fund_val_b_cv = max(0.0, fund_val_b_bef_cv - admin_fee_cv - pfwd_surr_cv);  // DTL 20200317: removed GLB charge and inserted withdrawal
	}
}

return fund_val_b_cv;

}


//@@ END

//@@ START - fund_val_b_bef_aig
// Fund value at beginning of year:                                                                                             
// Column:FUND_VAL_B_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_b_bef_aig(int t) {
//^^^



//^^^

#line 1 "fund_val_b_bef_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor

if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
{
	return NO_AVG;
}

double fund_val_b_bef_cv;
if (fund_val_e_aig(t - 1) < model_point_amount_threshold)
{
	fund_val_b_bef_cv = 0.0;
}
else
{
	double fund_val_prev = fund_val_e_aig(t - 1);
	fund_val_b_bef_cv    = fund_val_prev;

	// DTL 20200707: NYIA (START)
	if (fia->fund_val_defn_aig == EIV)
	{
		double pol_yr_cv = pol_yr(t);
		int pol_mth_cv   = int(pol_mth_aig(t));
		bool is_eoy      = mod(pol_mth_cv, 12) == 0;

		if (pol_yr_cv > fia->min_accum_val_activation_period_yrs_ny_aig && is_eoy)
		{
			double mav_prev = min_accum_val_e_aig(t - 1);

			if (mav_prev > fund_val_prev)
			{
				fund_val_b_bef_cv = mav_prev;
			}
		}
	}
	// DTL 20200707: NYIA (END)
}

return fund_val_b_bef_cv;

}


//@@ END

//@@ START - fund_val_e_aig
// Fund value after GLB charge:                                                                                             
// Column:FUND_VAL_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_e_aig(int t) {
//^^^



//^^^

#line 1 "fund_val_e_aig.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
{
	return NO_AVG;
}
	
double fund_val_cv;
if (t == 0)
{
	//fund_val_cv = fia->fund_val_fixed(res_period);
	fund_val_cv = fia->fund_val_b(fia->res_period + 1);  // 20200414 DTL//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else
{
	if (fund_val_e_bef_aig(t) < model_point_amount_threshold)
	{
		fund_val_cv = 0.0;
	}
	else
	{
		double glb_chg_cv = gmwb_chg(t);
		double fund_val_prev = fund_val_e_bef_aig(t);
		fund_val_cv = max(0, fund_val_prev - glb_chg_cv);
	}
	
}

return fund_val_cv;

}


//@@ END

//@@ START - fund_val_e_bef_aig
// Fund value after interest credit:                                                                                             
// Column:FUND_VAL_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "fund_val_e_bef_aig.FIACARVM_LIAB.for"
if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
{
	return NO_AVG;
}

double fund_val_cv;
if (fund_val_b_aig(t) < model_point_amount_threshold)
{
	fund_val_cv = 0.0;
}
else
{
	double credited_int_cv = credited_int(t);
	double fund_val_prev = fund_val_b_aig(t);

	double gmab_chg_cv = 0.;
	if (fia->gmab_ind_aig == 1 && pol_yr(t) <= fia->surr_chg_period_aig)
	{
		gmab_chg_cv = fund_val_b_aig(t) * fia->gmab_chg_pct_aig;
	}

	fund_val_cv = max(0, fund_val_prev + credited_int_cv - gmab_chg_cv);

	//20241205 MQ GMAB logic
	if (fia->gmab_ind_aig == 1 && pol_yr(t) == fia->surr_chg_period_aig) 
	{
		double gmab_av = gmab_av_e_aig(t);
		if (fia->gmab_type_crbg == AICO) 
		{
			double gmab_cap = prem_cumul_prop_wdl_aig(t) * fia->gmab_av_cap_rt_aig;	
			fund_val_cv = max(fund_val_cv, min(gmab_av, gmab_cap)); 
			fund_val_cv = max(fund_val_cv, prem_cumul_prop_wdl_aig(t));
		}
		else //20260323 MQ Standard GMAB
		{
			fund_val_cv = max(fund_val_cv, gmab_av); 
		}
	}
}

return fund_val_cv;

}


//@@ END

//@@ START - gmab_av_b_aig
// GMAB BOY                                                                                             
// Column:GMAB_AV_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmab_av_b_aig(int t) {
//^^^



//^^^

#line 1 "gmab_av_b_aig.FIACARVM_LIAB.for"
//20241205 MQ new column for GMAB
if (t <= 0 || t > max_calc_period || fia->gmab_ind_aig == 0)
{
	return NO_AVG;
}

if (pol_yr(t) > fia->surr_chg_period_aig)
{
	return 0.;
}

if (fia->gmab_type_crbg == STANDARD) //20260323 MQ STANDARD GMAB
{
	return max(0.0, gmab_av_e_aig(t - 1) - pfwd_surr_aig(t));
}

//AICO
double reduction_factor = 0.;

if (fund_val_b_bef_aig(t) > SMALL_DOUBLE)
{
	reduction_factor = fund_val_b_aig(t) / fund_val_b_bef_aig(t);
}

double gmab_av_cv = gmab_av_e_aig(t - 1) * reduction_factor;

return gmab_av_cv;

}


//@@ END

//@@ START - gmab_av_e_aig
// GMAB EOY                                                                                             
// Column:GMAB_AV_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmab_av_e_aig(int t) {
//^^^



//^^^

#line 1 "gmab_av_e_aig.FIACARVM_LIAB.for"
//20241205 MQ new column for GMAB
if (t < 0 || t > max_calc_period || fia->gmab_ind_aig == 0)
{
	return NO_AVG;
}

if (pol_yr(t) > fia->surr_chg_period_aig)
{
	return 0.;
}

double gmab_av_cv;

if (t == 0)
{
	gmab_av_cv = fia->sm_fia_account[0]->gmab_av_e_aig(fia->res_period); //Need to get GMAB from next time step after fee deduction 
}
else
{
	//20260323 MQ STANDARD GMAB
	if (fia->gmab_type_crbg == STANDARD)
	{
		if (pol_yr(t) == fia->surr_chg_period_aig)
		{
			fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_aig;
			double gmab_rate = fia->gmab_rate_crbg;

			gmab_av_cv = gmab_av_b_aig(t) * ( 1 + fia->surr_chg_period_aig * gmab_rate);
		}
		else
		{
			gmab_av_cv = gmab_av_b_aig(t);
		}
	}
	else //AICO
	{
		gmab_av_cv = gmab_av_b_aig(t) * ( 1 + crediting_rate(t) * fia->gmab_credit_rt_mult_aig);
	}
}

return gmab_av_cv;

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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (!fia->gmwb_flag || calc_base_res_only_aig == "Yes") //20230127 SJ: For XOL deal, calculate base stat res only when switch is on.
{
     return NO_AVG;
}

if (gmwb_max_wdl_amt_aig(t) <= model_point_amount_threshold)
{
	return NO_AVG;
}

if (fund_val_e_aig(t) > model_point_amount_threshold)  //MQ 20200427
{
	return NO_AVG;
}

double init_pmt         = gmwb_max_wdl_amt_aig(t);
double ann_rate         = 0.0;
double pv_gmwb_withdrls = 0.0;

if ( fund_val_e_aig(t)     <= model_point_amount_threshold    && 
	 fund_val_b_bef_aig(t) >  model_point_amount_threshold       )  //MQ 20200427
{
	init_pmt = gmwb_max_wdl_amt_aig(t) - pfwd_surr_aig(t);
}

// Set hidden lookup keys for carvm_int_rate
//WTW - Gen2 - Mutating Lookup Term - move lookup keys under each stat/tax conditional
if (model_name_gen2 == "STAT"/*this == fia_carvm_stat*/)//WTW - Gen2 - comparison of distinct pointers error
{
	valn_carvm_defn		  = fia->stat_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn    = fia->valn_rate_int_guar_defn;
	valn_guar_dur         = pol_yr(t);
	valn_plan_type        = fia->valn_rate_plan_type_non_elective_gmwb_after_exhaust_aig;
	valn_issue_yr			  = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	ann_rate              = carvm_int_rate;
}
else
{
	valn_carvm_defn		  = fia->tax_carvm_defn;
	valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn    = fia->valn_rate_int_guar_defn;
	valn_guar_dur         = pol_yr(t);
	valn_plan_type        = fia->valn_rate_plan_type_non_elective_gmwb_after_exhaust_aig;
	valn_issue_yr			  = fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
	ann_rate              = carvm_int_rate;
}

/*valn_cash_settle_defn = fia->valn_rate_cash_settle_defn;
valn_int_guar_defn    = fia->valn_rate_int_guar_defn;
valn_guar_dur         = pol_yr(t);
valn_plan_type        = fia->valn_rate_plan_type_non_elective_gmwb_after_exhaust_aig;
ann_rate              = carvm_int_rate;*/

if ( fia->gmwb_defn == LIFE )
{
	pv_gmwb_withdrls     = init_pmt;

	if (carvm_cont_defn == YES && surv(t) > SMALL_DOUBLE)
    {
		pv_gmwb_withdrls = init_pmt * surv(t - 1) * carvm_disc_factor_non_elect_gmwb(t - 1)
                                                / (surv(t) * carvm_disc_factor_non_elect_gmwb(t));
    }

	int pol_yr           = this->pol_yr(t);
	int duration         = 1;
	double mort_rate     = 0.0;
	double disc_fct_prev = 1.0;  // 20200624 DTL
	double disc_fct_cv   = 1.0;  // 20200624 DTL
	//double disc_factor = 1.0;
	double surv_period   = 1.0;
	double surv          = 1.0;

	// DTL 20200121 (START): TFS 87039
	double lx, ly, lxy, lxy_bar, lxy_bar_prev;  // 20200624 DTL

	if (gender == MALE || gender == BLENDED)
	{
		lxy = 0.0;
		lx  = 1.0;
		ly  = 0.0;
	}	
	else if (gender == FEMALE)
	{
		lxy = 0.0;
		lx  = 0.0;
		ly  = 1.0;
	}
	else if (gender == JOINT)
	{
		double total_lives = policies_last_survivor_experience_aig(t);

		if ( total_lives > SMALL_DOUBLE )
		{
			lxy = policies_joint_experience_aig(t)  / total_lives;
			lx  = policies_male_experience_aig(t)   / total_lives;
			ly  = policies_female_experience_aig(t) / total_lives;
		}
		else
		{
			lxy = 0.0;
			lx  = 0.0;
			ly  = 0.0;
		}
	}
	else
	{
		throw FatalError("`fiacarvm_liab->gmwb_ann_benefits`: unhandled `fiacarvm_liab->gender` value.");
	}

	lxy_bar = lx + ly + lxy;  // Should be equal to 1.0!

	/************************************************************************************************
	std::map<std::string, double> output_dictionary;
	bool on_switch = pfwd_model == "FULL" && res_period == 1;
	if ( on_switch )
	{
		log_strm << "res_period,t,duration,t+duration,surv_prev,surv_cv,disc_prev,disc_cv,premium,cummulative_pv\n";

		output_dictionary["res_period"]			= res_period;
		output_dictionary["t"]					= t;
		output_dictionary["duration"]			= 0;
		output_dictionary["t+duration"]			= t;
		output_dictionary["premium"]			= init_pmt;
		output_dictionary["surv_prev"]  		= 1.0;
		output_dictionary["surv_cv"]            = 1.0;
		output_dictionary["disc_prev"]	        = 1.0;
		output_dictionary["disc_cv"]            = 1.0;
		output_dictionary["cummulative_pv"]		= init_pmt;

		log_strm << output_dictionary["res_period"]			<< ",";
		log_strm << output_dictionary["t"]					<< ",";
		log_strm << output_dictionary["duration"]			<< ",";
		log_strm << output_dictionary["t+duration"]			<< ",";
		log_strm << output_dictionary["surv_prev"]          << ",";
		log_strm << output_dictionary["surv_cv"]            << ",";
		log_strm << output_dictionary["disc_prev"]          << ",";
		log_strm << output_dictionary["disc_cv"]            << ",";
		log_strm << output_dictionary["premium"]			<< ",";
		log_strm << output_dictionary["cummulative_pv"]		<< "\n";
	}
	/************************************************************************************************/

	while (lxy_bar > rate_ratio_threshold)
	{
		/************************************************************************************************
		if ( on_switch )
		{
			output_dictionary["duration"]   = duration;
			output_dictionary["t+duration"] = t + duration;
		}
		/************************************************************************************************/

		pol_yr             = this->pol_yr(min(t_high, t + duration));//WTW - Gen2 - time guards
		double weight_cv   = gmwb_ann_benefits_weight_aig;
		lxy_bar_prev       = lxy_bar;  // 20200624 DTL

		gmwb_ann_benefits_mort_rate_calc_aig(t + duration, pol_yr, EXPERIENCE, lxy, lx, ly, lxy_bar);
		double lxy_bar_avg = weight_cv * lxy_bar_prev + (1.0 - weight_cv) * lxy_bar;  // 20200624

		// 20200624 DTL
		disc_fct_prev        = disc_fct_cv; 
		disc_fct_cv         *= 1.0 / (1.0 + ann_rate);
		//disc_factor       *= 1.0 / (1.0 + ann_rate);
		double disc_fct_avg  = weight_cv * disc_fct_prev + (1.0 - weight_cv) * disc_fct_cv;
		// 20200624 DTL

		pv_gmwb_withdrls += gmwb_max_wdl_amt_aig(min(t_high, t + duration)) * disc_fct_avg * lxy_bar_avg; // 20200624 DTL//WTW - Gen2 - time guards
		duration         += 1;

		/************************************************************************************************
		if ( on_switch )
		{
			output_dictionary["premium"]        = gmwb_max_wdl_amt_aig(t + duration);
			output_dictionary["surv_prev"]      = lxy_bar_prev;
			output_dictionary["surv_cv"]        = lxy_bar;
			output_dictionary["disc_prev"]      = disc_fct_prev;
			output_dictionary["disc_cv"]        = disc_fct_cv;
			output_dictionary["cummulative_pv"] = pv_gmwb_withdrls;

			log_strm << output_dictionary["res_period"]			<< ",";
			log_strm << output_dictionary["t"]					<< ",";
			log_strm << output_dictionary["duration"]			<< ",";
			log_strm << output_dictionary["t+duration"]			<< ",";
			log_strm << output_dictionary["surv_prev"]	    	<< ",";
			log_strm << output_dictionary["surv_cv"]            << ",";
			log_strm << output_dictionary["disc_prev"]      	<< ",";
			log_strm << output_dictionary["disc_cv"]            << ",";
			log_strm << output_dictionary["premium"]			<< ",";
			log_strm << output_dictionary["cummulative_pv"]		<< "\n";
		}
		/************************************************************************************************/
	}
}
else
{
	throw FatalError("`fiacarvm_liab->gmwb_ann_benefits`: unhandled `fia->gmwb_defn` value.");
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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (!fia->gmwb_flag)
     return NO_AVG;

// if (t > 0 && fabs(fund_val_e_aig(t - 1)) < model_point_amount_threshold && ( fund_val_b_aig(t - 1) <= model_point_amount_threshold ))  // DTL 20200317
if (t > 0 && fabs(fund_val_e_aig(t - 1)) < model_point_amount_threshold )  //MQ 20200427
{
	return NO_AVG; 
}

// DTL 20200121 (START): TFS 86514
double gmwb_ann_benefits_cv    = gmwb_ann_benefits(t);

/*
DTL 2020624:
	MQ provided this averaging algorithm.
*/
double weight_cv = gmwb_ann_benefits_weight_aig;

if (carvm_cont_defn == YES)  // DTL 20200707
{
	weight_cv = 0.0;
}

double disc_factor_prev = carvm_disc_factor_non_elect_gmwb(t - 1);
double disc_factor_cv   = carvm_disc_factor_non_elect_gmwb(t);
double disc_factor_avg  = weight_cv * disc_factor_prev + (1.0 - weight_cv) * disc_factor_cv;

double survivorship_prev = surv(t - 1);
double survivorship_cv   = surv(t);
double survivorship_avg  = weight_cv * survivorship_prev + (1.0 - weight_cv) * survivorship_cv;

double gmwb_ann_benefits_pv_cv = gmwb_ann_benefits_cv * disc_factor_avg * survivorship_avg;

return gmwb_ann_benefits_pv_cv;
// DTL 20200121 (END): TFS 86514

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
//WTW - Gen2 - split non time guard items
if (/*!fia->gmwb_flag || */t <= 0 ||t > max_calc_period)
{
	return NO_AVG;
}

if (!fia->gmwb_flag)// 20230511 JYL: prior condition deleted since gmwb fee should be included in XOL deal base res
	return NO_AVG;

if (fund_val_b_aig(t) < model_point_amount_threshold)
{
	return 0.0;
}

double gmwb_chg_cv;
double gmwb_chg_base_amt = 0.0;
double gmwb_chg_factor = 1.0;
double fund_val_cv = fund_val_e_bef_aig(t);

if (fia->gmwb_chg_base == FUND_VALUE)
{
    gmwb_chg_base_amt = fund_val_cv;
}
else if (fia->gmwb_chg_base == GMWB_BASE)
{
    //gmwb_chg_base_amt = gmwb_income_base_e_bef_aig(t);
	gmwb_chg_base_amt = gmwb_inf_e_bef_aig(t);  // DTL 20200707: NYIA 
}
else //Max Amount
{
	//double gmwb_income_base_cv = gmwb_income_base_e_bef_aig(t);
	double gmwb_income_base_cv = gmwb_inf_e_bef_aig(t);  // DTL 20200707: NYIA 
    gmwb_chg_base_amt = max(fund_val_cv, gmwb_income_base_cv);
}

if (t == 1)
{
	if (fia->pol_yr(fia->res_period) == 1 && fia->pol_mth(fia->res_period) == 1)//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
	{
		gmwb_chg_factor = 11.0 / 12.0;
	}
	else if (mths_in_first_year < 12)
	{
		gmwb_chg_factor = mths_in_first_year / 12.0;
	}
}
	
gmwb_chg_cv = min(fund_val_cv, gmwb_chg_base_amt * fia->gmwb_chg_pct * gmwb_chg_factor);

return gmwb_chg_cv;

}


//@@ END

//@@ START - gmwb_flex_mawp_adj_aig
// GLB flex factor                                                                                             
// Column:GMWB_FLEX_MAWP_ADJ_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_flex_mawp_adj_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_flex_mawp_adj_aig.FIACARVM_LIAB.for"
// 20221110 SJ Move GLB felx factor calculation in separate column
if (t < 0 || t > max_calc_period)
	return NO_AVG;

int pol_mth_cv			= int(pol_mth_aig(t)) + 1;
int mawp_lookup_mth		= gmwb_wait_period_aig * 12 + 1;
double mawp_cv			= fia->calc_base_mawp_pct_aig(mawp_lookup_mth, NO_EXERCISE, gender);

//20230120 SJ: The GLB flex annuity factor function is changed to calculate single and joint annuity factor in one loop. Update the code to call function properly.
double flex_mawp_adj = 1.0;
if (gmwb_flex_defn_aig == YES && glb_withdrls_have_begun_aig == "No")  
{
	vector<double> annuity_factor;
	if (gmwb_flex_mawp_adj_method_aig == ANNUAL_LIFE_ANNUITY_FACTORS)
	{
		annuity_factor  = glb_flex_ann_annuity_factor_aig(t, EXPERIENCE, fia->issue_age_male_aig, fia->issue_age_female_aig);
	}
	else
	{
		annuity_factor = glb_flex_mthly_annuity_factor_aig(pol_mth_cv, EXPERIENCE, fia->issue_age_male_aig, fia->issue_age_female_aig);
	}
	
	if (gender == MALE || gender == FEMALE || gender == BLENDED)
	{
		double single_annuity_factor, joint_annuity_factor;

		if (gender == MALE || gender == BLENDED)
		{
			single_annuity_factor = annuity_factor[0];
		}
		else
		{
			single_annuity_factor = annuity_factor[1];
		}

		joint_annuity_factor = annuity_factor[2];

		double single_mawp				= mawp_cv;
		double denominator				= single_annuity_factor * single_mawp;
		double joint_mawp				= fia->calc_base_mawp_pct_aig(mawp_lookup_mth, NO_EXERCISE, JOINT);
		double numerator				= joint_annuity_factor * joint_mawp;

		if (fabs(denominator) < SMALL_DOUBLE)
		{
			string err_msg = "fiacarvm_liab->gmwb_max_annual_wdl_pct_aig(t): division by zero!";
			throw FatalError(xstring(err_msg));
		}

		flex_mawp_adj					= max(1, numerator / denominator);
	}
	else
	{
		double female_annuity_factor, male_annuity_factor, joint_annuity_factor;

		male_annuity_factor = annuity_factor[0];
		female_annuity_factor = annuity_factor[1];
		joint_annuity_factor = annuity_factor[2];

		double female_mawp				= fia->calc_base_mawp_pct_aig(mawp_lookup_mth, NO_EXERCISE, FEMALE);
		double female_numerator			= female_annuity_factor * female_mawp;
		double male_mawp				= fia->calc_base_mawp_pct_aig(mawp_lookup_mth, NO_EXERCISE, MALE);
		double male_numerator			= male_annuity_factor * male_mawp;
		double joint_mawp				= fia->calc_base_mawp_pct_aig(mawp_lookup_mth, NO_EXERCISE, JOINT);
		double denominator				= joint_annuity_factor * joint_mawp;

		if (fabs(denominator) < SMALL_DOUBLE)
		{
			string err_msg = "fiacarvm_liab->gmwb_max_annual_wdl_pct_aig(t): division by zero!";
			throw FatalError(xstring(err_msg));
		}

		flex_mawp_adj					= max(female_numerator, male_numerator ) / denominator;
		flex_mawp_adj					= max(1, flex_mawp_adj);
	}
}

return flex_mawp_adj;

}


//@@ END

//@@ START - gmwb_income_base_b_aig
// GLB base at beginning of year, after discrete charges/credits:                                                                                             
// Column:GMWB_INCOME_BASE_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_b_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_base_b_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

StrEnum::EnumValue income_phase_lookup_original = fia->income_phase_lookup_aig;
set_income_phase_lookup_b_aig(t);

double gmwb_income_base_b_bef_cv = gmwb_income_base_b_bef_aig(t);
double gmwb_income_base_b_cv;

fia->temp_key_inc_phase_aig = fia->income_phase_lookup_aig;//WTW - Gen2 - Mutating Lookup Term
if (fia->gmwb_income_prem_base_reduction_method_aig == DOLLARS)
{
	gmwb_income_base_b_cv = max(0.0, gmwb_income_base_b_bef_cv - pfwd_surr_aig(t));
}
else if (fia->gmwb_income_prem_base_reduction_method_aig == CONTRACT_PCT)
{
	double fund_val_before_wdls, fund_val_after_wdls, reduction_pct, withdrl;
	
	fund_val_before_wdls = fund_val_b_bef_aig(t);

	withdrl = pfwd_surr_aig(t);
	fund_val_after_wdls = fund_val_before_wdls - withdrl;

	if ( fund_val_before_wdls < SMALL_DOUBLE )
	{
		reduction_pct = 0.0;
	}
	else
	{
		reduction_pct = fund_val_after_wdls / fund_val_before_wdls;
	}

	gmwb_income_base_b_cv =  gmwb_income_base_b_bef_cv * reduction_pct;
}
else if (fia->gmwb_income_prem_base_reduction_method_aig == NO_REDUCTION)
{
	gmwb_income_base_b_cv = gmwb_income_base_b_bef_cv;
}
else
{
	throw FatalError("Unhandled gmwb_income_prem_base_reduction_method_aig requested in fiacarvm_liab->gmwb_income_base_b_aig!");
}


fia->income_phase_lookup_aig = income_phase_lookup_original;
return gmwb_income_base_b_cv;

}


//@@ END

//@@ START - gmwb_income_base_b_bef_aig
// GLB base at beginning of year:                                                                                             
// Column:GMWB_INCOME_BASE_B_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_b_bef_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_base_b_bef_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_base_b_bef_cv = gmwb_income_base_e_aig(t - 1);
return gmwb_income_base_b_bef_cv;

}


//@@ END

//@@ START - gmwb_income_base_e_aig
// GMWB income base at end of year:                                                                                             
// Column:GMWB_INCOME_BASE_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_e_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_base_e_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_base_e_cv = gmwb_income_base_e_bef_aig(t);
return gmwb_income_base_e_cv;


}


//@@ END

//@@ START - gmwb_income_base_e_bef_aig
// GLB income base at end of year, before deaths, surrenders, and withdrawals but after interest:                                                                                             
// Column:GMWB_INCOME_BASE_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_base_e_bef_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_base_e_bef_cv;

if (t == 0)
{
	/*
	DTL 20200317: 

	MQ wants to continue to do what the old model did and look forward one month.
	Else it might be better to to initialize GLB base values as of the current
	outer loop end of month.
	*/
	gmwb_income_base_e_bef_cv = fia->gmwb_income_base_e_bef_aig(fia->res_period + 1);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else
{
	double gmwb_income_base_b_cv = gmwb_income_base_b_aig(t);

	// 1. income credit
	double gmwb_income_credit_e_bef_cv = gmwb_income_credit_e_bef_aig(t);
	gmwb_income_base_e_bef_cv = gmwb_income_base_b_cv + gmwb_income_credit_e_bef_cv;

	// 2. HAV
	double fund_val_e_bef_cv = fund_val_e_bef_aig(t);
	gmwb_income_base_e_bef_cv = max(gmwb_income_base_e_bef_cv, fund_val_e_bef_cv);

	// 3. MIB
	double gmwb_min_income_base_e_bef_cv = gmwb_min_income_base_e_bef_aig(t);
	gmwb_income_base_e_bef_cv = max(gmwb_income_base_e_bef_cv, gmwb_min_income_base_e_bef_cv);
}

return gmwb_income_base_e_bef_cv;


}


//@@ END

//@@ START - gmwb_income_base_ny_b_aig
// NYIA GLB base:                                                                                             
// Column:GMWB_INCOME_BASE_NY_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_ny_b_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_base_ny_b_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_base_ny_b_cv;

if (t == 0)
{
	gmwb_income_base_ny_b_cv = gmwb_income_base_ny_b_bef_aig(t);
}
else
{
	/*
	double pfwd_cumul_cv			= pfwd_surr_cumul_aig(t);
	if (pfwd_cumul_cv > 0.0)
	{
		gmwb_income_base_ny_b_cv	= gmwb_income_base_ny_b_bef_aig(t);
	}
	*/

	double pol_yr_cv = pol_yr(t);
	if (pol_yr_cv > gmwb_wait_period_aig)
	{
		gmwb_income_base_ny_b_cv	= gmwb_income_base_ny_b_bef_aig(t);
	}
	else
	{
		double fund_val_b_cv		= fund_val_b_aig(t);
		double mav_b_cv				= min_accum_val_b_aig(t);
		gmwb_income_base_ny_b_cv	= max(fund_val_b_cv, mav_b_cv);
	}
}

return gmwb_income_base_ny_b_cv;

}


//@@ END

//@@ START - gmwb_income_base_ny_b_bef_aig
// NYIA GLB base:                                                                                             
// Column:GMWB_INCOME_BASE_NY_B_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_ny_b_bef_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_base_ny_b_bef_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_base_ny_b_bef_cv;

if (t == 0)
{
	gmwb_income_base_ny_b_bef_cv = fia->gmwb_income_base_ny_b_bef_aig(fia->res_period + 1);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else
{
	/*
	double pfwd_cumul_cv				 = pfwd_surr_cumul_aig(t - 1);
	if (pfwd_cumul_cv > 0.0)
	{
		gmwb_income_base_ny_b_bef_cv	 = gmwb_income_base_ny_b_bef_aig(t - 1);
	}
	*/

	double pol_yr_cv					 = pol_yr(t);
	if (glb_withdrls_have_begun_aig == "Yes")
	{
		gmwb_income_base_ny_b_bef_cv	 = gmwb_income_base_ny_b_bef_aig(t - 1);
	}
	else if (pol_yr_cv > 1.0 + gmwb_wait_period_aig)
	{
		gmwb_income_base_ny_b_bef_cv	 = gmwb_income_base_ny_b_bef_aig(t - 1);
	}
	else
	{
		double fund_val_b_bef_cv		 = fund_val_b_bef_aig(t);
		double mav_b_bef_cv				 = min_accum_val_b_bef_aig(t);
		gmwb_income_base_ny_b_bef_cv	 = max(fund_val_b_bef_cv, mav_b_bef_cv);
	}
}

return gmwb_income_base_ny_b_bef_cv;

}


//@@ END

//@@ START - gmwb_income_base_ny_e_aig
// NYIA GLB base:                                                                                             
// Column:GMWB_INCOME_BASE_NY_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_ny_e_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_base_ny_e_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_base_ny_e_cv;

if (t == 0)
{
	gmwb_income_base_ny_e_bef_aig(t);
}
else
{
	/*
	double pfwd_cumul_cv			= pfwd_surr_cumul_aig(t);
	if (pfwd_cumul_cv > 0.0)
	{
		gmwb_income_base_ny_e_cv	= gmwb_income_base_ny_e_aig(t);
	}
	*/

	double pol_yr_cv = pol_yr(t);
	if (pol_yr_cv > gmwb_wait_period_aig)
	{
		//gmwb_income_base_ny_e_cv	= gmwb_income_base_ny_e_aig(t); 
		gmwb_income_base_ny_e_cv	= gmwb_income_base_ny_e_aig(t - 1); //WTW - Gen2 - Cannot self reference at same t. Changed to reference prior t. AIG to review logic
	}
	else
	{
		double fund_val_e_cv		= fund_val_e_aig(t);
		double mav_e_cv				= min_accum_val_e_aig(t);
		gmwb_income_base_ny_e_cv	= max(fund_val_e_cv, mav_e_cv);
	}
}

return gmwb_income_base_ny_e_cv;

}


//@@ END

//@@ START - gmwb_income_base_ny_e_bef_aig
// NYIA GLB base:                                                                                             
// Column:GMWB_INCOME_BASE_NY_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_ny_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_base_ny_e_bef_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_base_ny_e_bef_cv;

if (t == 0)
{
	//gmwb_income_base_ny_e_bef_aig(t);
	return NO_AVG; //WTW - Gen2 - Cannot self reference at same t. Changed to retunr NO_AVG. AIG to review logic
}
else
{
	/*
	double pfwd_cumul_cv				= pfwd_surr_cumul_aig(t);
	if (pfwd_cumul_cv > 0.0)
	{
		gmwb_income_base_ny_e_bef_cv	= gmwb_income_base_ny_b_aig(t);
	}
	*/

	double pol_yr_cv = pol_yr(t);
	if (pol_yr_cv > gmwb_wait_period_aig)
	{
		gmwb_income_base_ny_e_bef_cv	= gmwb_income_base_ny_b_aig(t);
	}
	else
	{
		double fund_val_e_bef_cv		= fund_val_e_bef_aig(t);
		double mav_e_bef_cv				= min_accum_val_e_bef_aig(t);
		gmwb_income_base_ny_e_bef_cv	= max(fund_val_e_bef_cv, mav_e_bef_cv);
	}
}

return gmwb_income_base_ny_e_bef_cv;

}


//@@ END

//@@ START - gmwb_income_credit_base_b_aig
// GLB income credit base at beginning of year after discrete charges/credits:                                                                                             
// Column:GMWB_INCOME_CREDIT_BASE_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_credit_base_b_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_credit_base_b_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

StrEnum::EnumValue income_phase_lookup_original = fia->income_phase_lookup_aig;
set_income_phase_lookup_b_aig(t);

double gmwb_income_credit_base_b_cv;
double gmwb_income_credit_base_b_bef_cv = gmwb_income_credit_base_b_bef_aig(t);
double withdrawals_cv = pfwd_surr_aig(t);

fia->temp_key_inc_phase_aig = fia->income_phase_lookup_aig; //WTW - Gen2 - Mutating Lookup Term
if ( fia->gmwb_income_prem_base_reduction_method_aig == DOLLARS )
{
	gmwb_income_credit_base_b_cv = max(0.0, gmwb_income_credit_base_b_bef_cv - withdrawals_cv);
}
else if ( fia->gmwb_income_prem_base_reduction_method_aig == CONTRACT_PCT )
{
	double fund_val_before_wdls, fund_val_after_wdls, reduction_pct;
	
	fund_val_before_wdls = fund_val_b_bef_aig(t);
	fund_val_after_wdls = fund_val_before_wdls - withdrawals_cv;

	if ( fund_val_before_wdls < SMALL_DOUBLE )
	{
		reduction_pct = 0.0;
	}
	else
	{
		reduction_pct = fund_val_after_wdls / fund_val_before_wdls;
	}

	gmwb_income_credit_base_b_cv = gmwb_income_credit_base_b_bef_cv * reduction_pct;
}
else if ( fia->gmwb_income_prem_base_reduction_method_aig == NO_REDUCTION )
{
	// No reduction
	gmwb_income_credit_base_b_cv = gmwb_income_credit_base_b_bef_cv;
}
else
{
	throw FatalError("Unhandled `fia->gmwb_income_prem_base_reduction_method_aig` requested in `fiacarvm->gmwb_income_credit_base_b_aig(t)`!");
}

fia->income_phase_lookup_aig = income_phase_lookup_original;

return gmwb_income_credit_base_b_cv;



}


//@@ END

//@@ START - gmwb_income_credit_base_b_bef_aig
// GLB income credit base at beginning of year:                                                                                             
// Column:GMWB_INCOME_CREDIT_BASE_B_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_credit_base_b_bef_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_credit_base_b_bef_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_credit_base_b_bef_cv = gmwb_income_credit_base_e_aig(t - 1);
return gmwb_income_credit_base_b_bef_cv;

}


//@@ END

//@@ START - gmwb_income_credit_base_e_aig
// GLB income credit base at end of year:                                                                                             
// Column:GMWB_INCOME_CREDIT_BASE_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_credit_base_e_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_credit_base_e_aig.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_credit_base_e_cv = gmwb_income_credit_base_e_bef_aig(t);

if (fia->income_phase_lookup_aig == NO_INCOME || fia->income_phase_lookup_aig == PRE_INCOME)
{	
	double fund_val_cv = fund_val_e_bef_aig(t);
	double gmwb_income_base_e_bef_cv = gmwb_income_base_e_bef_aig(t);

	if ( fund_val_cv - gmwb_income_base_e_bef_cv  > SMALL_DOUBLE )
	{
		gmwb_income_credit_base_e_cv = max(gmwb_income_credit_base_e_cv, fund_val_cv);
	}
}

return gmwb_income_credit_base_e_cv;

}


//@@ END

//@@ START - gmwb_income_credit_base_e_bef_aig
// GLB income credit base after interest and before deaths, surrenders, and withdrawals:                                                                                             
// Column:GMWB_INCOME_CREDIT_BASE_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_credit_base_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_credit_base_e_bef_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

StrEnum::EnumValue income_phase_lookup_original = fia->income_phase_lookup_aig;
set_income_phase_lookup_e_bef_aig(t);

double gmwb_income_credit_base_e_bef_cv = 0.0;

if (t == 0)
{
	/*
	DTL 20200317: 

	MQ wants to continue to do what the old model did and look forward one month.
	Else it might be better to to initialize GLB base values as of the current
	outer loop end of month.
	*/
	gmwb_income_credit_base_e_bef_cv = fia->gmwb_income_credit_base_e_bef_aig(fia->res_period + 1);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else
{
	fia->temp_key_inc_phase_aig = fia->income_phase_lookup_aig; //WTW - Gen2 - Mutating Lookup Term
	if ( fia->gmwb_rollup_rate_type_aig == COMPOUND )
	{
		gmwb_income_credit_base_e_bef_cv = gmwb_income_base_b_aig(t);
	}
	else if ( fia->gmwb_rollup_rate_type_aig == SIMPLE )
	{
		gmwb_income_credit_base_e_bef_cv = gmwb_income_credit_base_b_aig(t);
	}
	else
	{
		throw FatalError("Unhandled gmwb_rollup_rate_type_aig requested in fiacarvm_liab->gmwb_income_credit_base_e_bef_aig!");
	}

	/* // DTL 20200707: (START)
	if ( fia->gmwb_income_credit_base_hav_defn_aig == YES )
	{	
		double fund_val_cv = fund_val_e_bef_aig(t);
		double gmwb_income_base_b_cv = gmwb_income_base_b_aig(t);

		if ( fund_val_cv - gmwb_income_base_e_cv  > SMALL_DOUBLE )
		{
			gmwb_income_credit_base_e_bef_cv = max(gmwb_income_credit_base_e_bef_cv, fund_val_cv);
		}
	}
	*/ // DTL 20200707: (END)
}

fia->income_phase_lookup_aig = income_phase_lookup_original;

return gmwb_income_credit_base_e_bef_cv;

}


//@@ END

//@@ START - gmwb_income_credit_e_bef_aig
// GLB income credit at end of year before deaths, surrenders, and withdrawals:                                                                                             
// Column:GMWB_INCOME_CREDIT_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_credit_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_income_credit_e_bef_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_credit_e_bef_cv;

StrEnum::EnumValue income_phase_lookup_original = fia->income_phase_lookup_aig;
set_income_phase_lookup_e_bef_aig(t);

fia->temp_key_inc_phase_aig = fia->income_phase_lookup_aig; //WTW - Gen2 - Mutating Lookup Term
StrEnum::EnumValue gmwb_net_credit_aig_local = fia->gmwb_net_credit_aig;//WTW - Gen2 - Mutating Lookup Term used in expression

if ( 
	pol_yr(t) <= fia->gmwb_max_rollup_duration &&
	gmwb_net_credit_aig_local != ZERO//WTW - Gen2 - Mutating Lookup Term used in expression
   )
{
	double gmwb_income_credit_base_cv = gmwb_income_credit_base_e_bef_aig(t);
	double gmwb_income_credit_rate_cv;

	if ( fia->gmwb_prem_rollup_credit_type_aig == CONSTANT_RATE )
	{
		gmwb_income_credit_rate_cv = fia->gmwb_rollup_rate;
	}
	else if ( fia->gmwb_prem_rollup_credit_type_aig == INDEX_GROWTH )
	{
		gmwb_income_credit_rate_cv = crediting_rate(t);
	}
	else
	{
		throw FatalError("Unhandled `fia->gmwb_prem_rollup_credit_type_aig` requested in `fiacarvm_liab->gmwb_income_credit_e_bef_aig`!");
	}

	fia->temp_key_inc_phase_aig = fia->income_phase_lookup_aig; //WTW - Gen2 - Mutating Lookup Term
	gmwb_income_credit_rate_cv *= fia->gmwb_credit_mult_aig;

	fia->temp_key_inc_phase_aig = fia->income_phase_lookup_aig; //WTW - Gen2 - Mutating Lookup Term
	if ( fia->gmwb_net_credit_aig == NET )
	{
		/*
		DTL:
		fia->gmwb_net_credit_aig == NET probably should never be run before GLB withdrawals begin, but
		within the model it is technically possible.  In that case it isn't clear that the logic here 
		is correct.
		However, this appears to be set-up present at the fia_liab level more or less.
		*/

		//20221110 SJ: update the gmwb max annual withdrawal pct for confinement adjustment.
		if (enhanced_income_defn_aig == YES) 
		{
			gmwb_income_credit_rate_cv -= gmwb_max_annual_wdl_pct_aig(t);
		}
		else
		{
			gmwb_income_credit_rate_cv -= gmwb_max_annual_wdl_pct_aig(gmwb_wdl_proj_yr_aig);// DTL 20200915
		}
		//20221110 SJ END

		gmwb_income_credit_rate_cv  = max(gmwb_income_credit_rate_cv, 0.0);
	}

	gmwb_income_credit_e_bef_cv = gmwb_income_credit_base_cv * gmwb_income_credit_rate_cv;
}
else
{
	gmwb_income_credit_e_bef_cv = 0.0;
}

// Reset lookup key
fia->income_phase_lookup_aig = income_phase_lookup_original;

return gmwb_income_credit_e_bef_cv;

}


//@@ END

//@@ START - gmwb_inf_b_aig
// GLB base:                                                                                             
// Column:GMWB_INF_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_inf_b_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_inf_b_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_base_cv;
if (fia->gmwb_income_base_defn == NYIA_GLB_BASE)
{
	gmwb_income_base_cv = gmwb_income_base_ny_b_aig(t);
}
else
{
	gmwb_income_base_cv = gmwb_income_base_b_aig(t);
}
// 20200603 DTL: NYIA

return gmwb_income_base_cv;

}


//@@ END

//@@ START - gmwb_inf_b_bef_aig
// GLB base:                                                                                             
// Column:GMWB_INF_B_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_inf_b_bef_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_inf_b_bef_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_base_cv;
if (fia->gmwb_income_base_defn == NYIA_GLB_BASE)
{
	gmwb_income_base_cv = gmwb_income_base_ny_b_bef_aig(t);
}
else
{
	gmwb_income_base_cv = gmwb_income_base_b_bef_aig(t);
}
// 20200603 DTL: NYIA

return gmwb_income_base_cv;

}


//@@ END

//@@ START - gmwb_inf_e_aig
// GLB base:                                                                                             
// Column:GMWB_INF_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_inf_e_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_inf_e_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_base_cv;
if (fia->gmwb_income_base_defn == NYIA_GLB_BASE)
{
	gmwb_income_base_cv = gmwb_income_base_ny_e_aig(t);
}
else
{
	gmwb_income_base_cv = gmwb_income_base_e_aig(t);
}
// 20200603 DTL: NYIA

return gmwb_income_base_cv;

}


//@@ END

//@@ START - gmwb_inf_e_bef_aig
// GLB base:                                                                                             
// Column:GMWB_INF_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_inf_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_inf_e_bef_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_income_base_cv;
if (fia->gmwb_income_base_defn == NYIA_GLB_BASE)
{
	gmwb_income_base_cv = gmwb_income_base_ny_e_bef_aig(t);
}
else
{
	gmwb_income_base_cv = gmwb_income_base_e_bef_aig(t);
}
// 20200603 DTL: NYIA

return gmwb_income_base_cv;

}


//@@ END

//@@ START - gmwb_max_annual_wdl_pct_aig
// MAWP:                                                                                             
// Column:GMWB_MAX_ANNUAL_WDL_PCT_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_max_annual_wdl_pct_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_max_annual_wdl_pct_aig.FIACARVM_LIAB.for"
// 20200915 DTL
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

int mawp_lookup_mth		= gmwb_wait_period_aig * 12 + 1;
double mawp_cv			= fia->calc_base_mawp_pct_aig(mawp_lookup_mth, NO_EXERCISE, gender);

//20221110 SJ: add confinement adjustment in the gmwb max annual withdrawal pct. Move GLB flex factor calculation in the separate Column.
double confinement_mawp_adj = 1;
if (enhanced_income_defn_aig == YES && fund_val_b_bef_aig(t) > 0)
{
	int withdrawal_yr = gmwb_wait_period_aig + 1;
	int enhanced_income_benefit_cumul_yrs = fia->enhanced_income_benefit_cumul_yrs_aig(fia->res_period);
	int remaining_yrs = fia->enhanced_income_max_cumul_benefit_yrs_aig - enhanced_income_benefit_cumul_yrs;
	StrEnum::EnumValue gender_cv = gender;

	confinement_mawp_adj = gmwb_confinement_mawp_adj_aig(withdrawal_yr, pol_yr(t), remaining_yrs, gender_cv);
}

double flex_mawp_adj = gmwb_flex_mawp_adj_aig(gmwb_wdl_proj_yr_aig);

mawp_cv *= flex_mawp_adj * confinement_mawp_adj;
//20221110 SJ END

return mawp_cv;

}


//@@ END

//@@ START - gmwb_max_wdl_amt_aig
// MAWA at beginning of the year:                                                                                             
// Column:GMWB_MAX_WDL_AMT_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_max_wdl_amt_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_max_wdl_amt_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor
if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (!fia->gmwb_flag)											   
{
	return NO_AVG;
}

double gmwb_max_wdl_amt_cv = 0.0;

if ( pol_yr(t) <= gmwb_wait_period_aig && 
     fund_val_b_bef_aig(t) > model_point_amount_threshold )
{ 
	return 0.0;
}

if (gmwb_wdl_proj_yr_aig == -1)  // DTL 20200915
{
	gmwb_wdl_proj_yr_aig = t;
}

// 20221011 SJ: add mawp/pipp split
double mawp_cv = 0;

//20221110 SJ: update the gmwb max annual withdrawal pct for confinement adjustment.
if (fund_val_b_bef_aig(t) > 0 || fia->gmwb_mawp_pipp_split_aig == NO)
{
	if (enhanced_income_defn_aig == YES)
	{
		mawp_cv				= gmwb_max_annual_wdl_pct_aig(t);
	}
	else
	{
		mawp_cv				= gmwb_max_annual_wdl_pct_aig(gmwb_wdl_proj_yr_aig);
	}
}
else if (fia->gmwb_mawp_pipp_split_aig == YES)
{
	mawp_cv				= gmwb_pip_annual_wdl_pct_aig(gmwb_wdl_proj_yr_aig);
}
else
{
	throw FatalError("gmwb_mawp_pipp_split_aig has improper setting, Please check the assumptions.");
}
// 20221011 SJ END
// 20221110 SJ END

double gmwb_inf_b_bef_cv	= gmwb_inf_b_bef_aig(t); 

if ( fia->pfwd_surr_curr_pol_yr(fia->res_period) > model_point_amount_threshold )//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
{
	gmwb_max_wdl_amt_cv = gmwb_inf_b_bef_cv * mawp_cv;  // DTL 20200707: NYIA

	return gmwb_max_wdl_amt_cv;
} 

if ( fia->gmwb_max_wdl_amt_base_defn == PREMIUM )
{
	if (  pol_yr(t) == gmwb_wait_period_aig + 1  ||
		 (
		   pol_yr(t) < gmwb_wait_period_aig + 1  && 
		   fund_val_b_bef_aig(t) <= model_point_amount_threshold
		 )
	   )
	{
		gmwb_max_wdl_amt_cv = gmwb_inf_b_bef_cv * mawp_cv;  // DTL 20200707: NYIA
		return gmwb_max_wdl_amt_cv;  
	}
	
	gmwb_max_wdl_amt_cv = gmwb_max_wdl_amt_aig(t - 1);
	return gmwb_max_wdl_amt_cv;
}

if (  pol_yr(t) == gmwb_wait_period_aig + 1 ||
	 (
	   pol_yr(t) < gmwb_wait_period_aig + 1 && 
	   fund_val_b_bef_aig(t) <= model_point_amount_threshold
	 )
   )
{
	gmwb_max_wdl_amt_cv = gmwb_inf_b_bef_cv * mawp_cv;  // DTL 20200707: NYIA
	return gmwb_max_wdl_amt_cv;
}

gmwb_max_wdl_amt_cv = gmwb_inf_b_bef_cv * mawp_cv;  // DTL 20200707: NYIA
return gmwb_max_wdl_amt_cv;

}


//@@ END

//@@ START - gmwb_min_income_base_e_bef_aig
// Minimum income base at end of year:                                                                                             
// Column:GMWB_MIN_INCOME_BASE_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_min_income_base_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_min_income_base_e_bef_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double gmwb_min_income_base_e_bef_cv = 0.0;

if (
	fia->gmwb_doubling_year_aig != 0 &&
	pol_yr(t) == fia->gmwb_doubling_year_aig  &&
	pfwd_surr_cumul_aig(t) < SMALL_DOUBLE &&      // 20200506 DTL
	fund_val_e_bef_aig(t) > SMALL_DOUBLE  // 20200506 DTL
   )
{
	double prem_cumul_cv = prem_cumul;
	gmwb_min_income_base_e_bef_cv = prem_cumul_cv * 2.0;
}

return gmwb_min_income_base_e_bef_cv;

}


//@@ END

//@@ START - gmwb_pip_annual_wdl_pct_aig
// GMWB PIP Annual Wdl Pct                                                                                             
// Column:GMWB_PIP_ANNUAL_WDL_PCT_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_pip_annual_wdl_pct_aig(int t) {
//^^^



//^^^

#line 1 "gmwb_pip_annual_wdl_pct_aig.FIACARVM_LIAB.for"
// 20221011 SJ add new for pipp for mawp/pipp split change
if (t < 0 || t > max_calc_period)
	return NO_AVG;

int pol_mth_cv			= int(pol_mth_aig(t)) + 1;
int pipp_lookup_mth		= gmwb_wait_period_aig * 12 + 1;
double pipp_cv			= fia->calc_pipp_pct_aig(t, pipp_lookup_mth, gender);

//20230120 SJ: The GLB flex annuity factor function is changed to calculate single and joint annuity factor in one loop. Update the code to call function properly.
double flex_mawp_adj = 1.0;
if (gmwb_flex_defn_aig == YES && glb_withdrls_have_begun_aig == "No") 
{
	vector<double> annuity_factor;
	if (gmwb_flex_mawp_adj_method_aig == ANNUAL_LIFE_ANNUITY_FACTORS)
	{
		annuity_factor  = glb_flex_ann_annuity_factor_aig(t, EXPERIENCE, fia->issue_age_male_aig, fia->issue_age_female_aig);
	}
	else
	{
		annuity_factor = glb_flex_mthly_annuity_factor_aig(pol_mth_cv, EXPERIENCE, fia->issue_age_male_aig, fia->issue_age_female_aig);
	}
	
	if (gender == MALE || gender == FEMALE || gender == BLENDED)
	{
		double single_annuity_factor, joint_annuity_factor;

		if (gender == MALE || gender == BLENDED)
		{
			single_annuity_factor = annuity_factor[0];
		}
		else
		{
			single_annuity_factor = annuity_factor[1];
		}

		joint_annuity_factor = annuity_factor[2];

		double single_pipp				= pipp_cv;
		double denominator				= single_annuity_factor * single_pipp;
		double joint_pipp				= fia->calc_pipp_pct_aig(t, pipp_lookup_mth, JOINT);
		double numerator				= joint_annuity_factor * joint_pipp;

		if (fabs(denominator) < SMALL_DOUBLE)
		{
			string err_msg = "fiacarvm_liab->gmwb_max_annual_wdl_pct_aig(t): division by zero!";
			throw FatalError(xstring(err_msg));
		}

		flex_mawp_adj					= max(1, numerator / denominator);
	}
	else
	{
		double female_annuity_factor, male_annuity_factor, joint_annuity_factor;

		male_annuity_factor = annuity_factor[0];
		female_annuity_factor = annuity_factor[1];
		joint_annuity_factor = annuity_factor[2];

		double female_pipp				= fia->calc_pipp_pct_aig(t, pipp_lookup_mth, FEMALE);
		double female_numerator			= female_annuity_factor * female_pipp;
		double male_pipp				= fia->calc_pipp_pct_aig(t, pipp_lookup_mth, MALE);
		double male_numerator			= male_annuity_factor * male_pipp;
		double joint_pipp				= fia->calc_pipp_pct_aig(t, pipp_lookup_mth, JOINT);
		double denominator				= joint_annuity_factor * joint_pipp;

		if (fabs(denominator) < SMALL_DOUBLE)
		{
			string err_msg = "fiacarvm_liab->gmwb_max_annual_wdl_pct_aig(t): division by zero!";
			throw FatalError(xstring(err_msg));
		}

		flex_mawp_adj					= max(female_numerator, male_numerator ) / denominator;
		flex_mawp_adj					= max(1, flex_mawp_adj);
	}
}
//20230120 SJ END

pipp_cv *= flex_mawp_adj;

return pipp_cv;

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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;
	
if (t == 0)
	return fia->min_contract_val(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula

// Non forfeiture value is adjusted (when applicable) by surrender charge unadjusted for MVA
if (fia->contract_val_sc_defn == YES)
	return max(0.0, contract_val_e_aig(t) - surr_chg_e_bef_aig(t));

return contract_val_e_aig(t);

}


//@@ END

//@@ START - index_term_cap_rate_min_aig
// Index Term Cap Rate Min Aig                                                                                             
// Column:INDEX_TERM_CAP_RATE_MIN_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_index_term_cap_rate_min_aig(int t) {
//^^^



//^^^

#line 1 "index_term_cap_rate_min_aig.FIACARVM_LIAB.for"
//20230105 SJ: add new column to track minimum cap rate for crediting rate refactor. 
if (t < 0 || t > max_calc_period)
	return NO_AVG;

double index_term_cap_rate_min_cv;

if (fia->crediting_type_dyn_defn_aig == DYNAMIC_SWITCHING_ON && fia->crediting_type_dyn_2nd_strat_aig != "NA"
		&& fia->res_period >= fia->sm_fia_account[0]->strategy_term_aig(fia->res_period - 1) * 12 + 1 )
{
	fia->pol_yr_lookup_gen2 = pol_yr(t);   //20260324 bug fix
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_dyn_2nd_strat_aig;
	index_term_cap_rate_min_cv = fia->sm_fia_account[0]->index_term_cap_rate_min_aig;
}			
else
{
	fia->pol_yr_lookup_gen2 = pol_yr(t);  //20260324 bug fix
	fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
	index_term_cap_rate_min_cv = fia->sm_fia_account[0]->index_term_cap_rate_min_aig;
}

return index_term_cap_rate_min_cv;

}


//@@ END

//@@ START - index_term_par_rate_min_aig
// index_term_par_rate_min_aig                                                                                             
// Column:INDEX_TERM_PAR_RATE_MIN_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_index_term_par_rate_min_aig(int t) {
//^^^



//^^^

#line 1 "index_term_par_rate_min_aig.FIACARVM_LIAB.for"
//20230105 SJ: add new column to track minimum par rate for crediting rate refactor. 
if (t < 0 || t > max_calc_period)
	return NO_AVG;

double index_term_par_rate_min_cv;

fia->pol_yr_lookup_gen2 = pol_yr(t);  //20260324 bug fix
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
index_term_par_rate_min_cv = fia->sm_fia_account[0]->index_term_part_rate_min_aig;

return index_term_par_rate_min_cv;

}


//@@ END

//@@ START - index_term_sprd_rate_max_aig
// index_term_sprd_rate_max_aig                                                                                             
// Column:INDEX_TERM_SPRD_RATE_MAX_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_index_term_sprd_rate_max_aig(int t) {
//^^^



//^^^

#line 1 "index_term_sprd_rate_max_aig.FIACARVM_LIAB.for"
//20230105 SJ: add new column to track max spread rate for crediting rate refactor. 
if (t < 0 || t > max_calc_period)
	return NO_AVG;

double index_term_sprd_rate_max_cv;

fia->pol_yr_lookup_gen2 = pol_yr(t);  //20260324 bug fix
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
index_term_sprd_rate_max_cv = fia->sm_fia_account[0]->index_term_sprd_rate_max_aig;

return index_term_sprd_rate_max_cv;

}


//@@ END

//@@ START - index_term_trigger_rate_min_aig
// Index Term Trigger Rate Min Aig                                                                                             
// Column:INDEX_TERM_TRIGGER_RATE_MIN_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_index_term_trigger_rate_min_aig(int t) {
//^^^



//^^^

#line 1 "index_term_trigger_rate_min_aig.FIACARVM_LIAB.for"
//20230118 SJ: add new column to trace min trigger rate for trigger fund change.
if (t < 0 || t > max_calc_period)
	return NO_AVG;

double index_term_trigger_rate_min_cv;

fia->pol_yr_lookup_gen2 = pol_yr(t);   //20260324 bug fix
fia->temp_key_cred_type_dyn_aig = fia->crediting_type_aig;
index_term_trigger_rate_min_cv = fia->sm_fia_account[0]->index_term_trigger_rate_min_aig;

return index_term_trigger_rate_min_cv;

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.FIACARVM_LIAB.for"
if (t != 0)//WTW - Gen2 - time guards
	return NO_AVG;

set_hidden_variables(0); // DTL 20200121: TFS 87109

return 0.0;

}


//@@ END

//@@ START - min_accum_val_b_aig
// Minimum accumulation value:                                                                                             
// Column:MIN_ACCUM_VAL_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_accum_val_b_aig(int t) {
//^^^



//^^^

#line 1 "min_accum_val_b_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA

if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double mav_b_cv;

double mav_b_bef_cv            = min_accum_val_b_bef_aig(t);
double fund_val_b_bef_cv       = fund_val_b_bef_aig(t);
double max_mav_and_fund_val_cv = max(mav_b_bef_cv, fund_val_b_bef_cv);

if (max_mav_and_fund_val_cv < SMALL_DOUBLE)
{
	return 0.0;
}

double wdl_cv                  = pfwd_surr_aig(t);
double reduction_fct_cv        = 1.0 - wdl_cv / max_mav_and_fund_val_cv;

mav_b_cv                       =  mav_b_bef_cv * reduction_fct_cv;

return mav_b_cv;

}


//@@ END

//@@ START - min_accum_val_b_bef_aig
// NYIA Minimum accumulation value:                                                                                             
// Column:MIN_ACCUM_VAL_B_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_accum_val_b_bef_aig(int t) {
//^^^



//^^^

#line 1 "min_accum_val_b_bef_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA

if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double mav_b_bef_cv;

double mav_prev      = min_accum_val_e_aig(t - 1);
mav_b_bef_cv         = mav_prev;

double pol_yr_cv     = pol_yr(t);
int pol_mth_cv       = int(pol_mth_aig(t));
bool is_eoy          = mod(pol_mth_cv, 12) == 0;

if (pol_yr_cv > fia->min_accum_val_activation_period_yrs_ny_aig && is_eoy)
{
	double fund_val_prev = fund_val_e_aig(t - 1);

	if (fund_val_prev > mav_prev)
	{
		mav_b_bef_cv = fund_val_prev;
	}
}

return mav_b_bef_cv;

}


//@@ END

//@@ START - min_accum_val_e_aig
// Minimum accumulation value:                                                                                             
// Column:MIN_ACCUM_VAL_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_accum_val_e_aig(int t) {
//^^^



//^^^

#line 1 "min_accum_val_e_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double mav_e_cv;

if (t <= 0)
{
	mav_e_cv = fia->min_accum_val_b_aig(fia->res_period + 1);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else
{
	mav_e_cv = min_accum_val_e_bef_aig(t);
}

return mav_e_cv;

}


//@@ END

//@@ START - min_accum_val_e_bef_aig
// Minimum accumulation value:                                                                                             
// Column:MIN_ACCUM_VAL_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_accum_val_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "min_accum_val_e_bef_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA

if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double mav_e_bef_cv;

double growth_factor_cv;
if (t == 1 && fabs(mths_in_first_year - 12.0) > 0.0)
{
	growth_factor_cv = pow(1 + fia->min_accum_val_annualized_growth_rate_ny_aig, mths_in_first_year / 12.0);
}
else
{
	growth_factor_cv = 1 + fia->min_accum_val_annualized_growth_rate_ny_aig;
}

double mav_b_cv = min_accum_val_b_aig(t);
mav_e_bef_cv	= mav_b_cv * growth_factor_cv;

return mav_e_bef_cv;

}


//@@ END

//@@ START - min_wdl_val_alt_b_aig
// Minimum Withdrawal Value Base at BOM                                                                                             
// Column:MIN_WDL_VAL_ALT_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_alt_b_aig(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_alt_b_aig.FIACARVM_LIAB.for"
// STW 20210608: add column
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;
else
{
	if ( fund_val_b_aig(t) > SMALL_DOUBLE ) 
	{
		double minimum_withdrawal_value = min_wdl_val_alt_base_b_aig(t);
		double current_wdl_charges = surr_chg_b_aig(t);
		return max( minimum_withdrawal_value - current_wdl_charges, 0 );
	}
	else 
	{
		return 0.0;
	}
}

}


//@@ END

//@@ START - min_wdl_val_alt_base_b_aig
// Minimum Withdrawal Value Base at BOM before Charges:                                                                                             
// Column:MIN_WDL_VAL_ALT_BASE_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_alt_base_b_aig(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_alt_base_b_aig.FIACARVM_LIAB.for"
// STW 20210517: add column
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (t == 0) 
{
	return fia->min_wdl_val_alt_base_e_aig(fia->res_period);		//20210608 STW: fix for alternative min wdl value//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else
{
	if ( fund_val_b_aig(t) > SMALL_DOUBLE ) 
	{
		double minimum_withdrawal_value = min_wdl_val_alt_base_e_aig(t - 1) - pfwd_surr_aig(t);

		return max( minimum_withdrawal_value, 0 );
	}
	else 
	{
		return 0.0;
	}
}

}


//@@ END

//@@ START - min_wdl_val_alt_base_e_aig
// Alternate Minimum Withdrawal Value Base at EOM After Decrements:                                                                                             
// Column:MIN_WDL_VAL_ALT_BASE_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_alt_base_e_aig(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_alt_base_e_aig.FIACARVM_LIAB.for"
// STW 20210517: add column
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;


if (t == 0) 
{
	return  fia->min_wdl_val_alt_base_e_aig(fia->res_period);		//20210608 STW: fix for alternative min wdl value//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}else
{
	if ( fund_val_e_aig(t) > SMALL_DOUBLE ) 
	{
		double minimum_withdrawal_value = min_wdl_val_alt_base_e_bef_aig(t) - gmwb_chg(t);

		return max( minimum_withdrawal_value, 0 );
	}
	else 
	{
		return 0.0;
	}
}



}


//@@ END

//@@ START - min_wdl_val_alt_base_e_bef_aig
// Alternate Minimum Withdrawal Value Base at EOM Before Decrements:                                                                                             
// Column:MIN_WDL_VAL_ALT_BASE_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_alt_base_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_alt_base_e_bef_aig.FIACARVM_LIAB.for"
// STW 20210517: add column
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (t == 0) 
{
	return fia->min_wdl_val_alt_base_e_aig(fia->res_period);		//20210608 STW: fix for alternative min wdl value//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else
{
	if ( fund_val_b_aig(t) > SMALL_DOUBLE ) 
	{
		double monthly_minimum_withdrawal_value_growth_rate = pow(1.0 + min_wdl_val_growth_pct_aig, 1.0 / 12.0) - 1.0;
		double minimum_withdrawal_value = min_wdl_val_alt_base_b_aig(t) * (1.0 + monthly_minimum_withdrawal_value_growth_rate);

		return max( minimum_withdrawal_value, 0 );
	}
	else 
	{
		return 0.0;
	}
}

}


//@@ END

//@@ START - min_wdl_val_alt_e_aig
// Alternate Minimum Withdrawal Value at EOM After Decrements:                                                                                             
// Column:MIN_WDL_VAL_ALT_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_alt_e_aig(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_alt_e_aig.FIACARVM_LIAB.for"
// STW 20210517: add column
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;
else
{
	if ( fund_val_e_aig(t) > SMALL_DOUBLE ) 
	{
		double minimum_withdrawal_value  = min_wdl_val_alt_base_e_aig(t);
		double current_wdl_charges		 = surr_chg_e_aig(t);
		//double current_bonus_recapture	 = prem_bonus_recapture_inf_e_aig(t);
		//minimum_withdrawal_value		-= ( current_gmwb_charges + current_wdl_charges + current_bonus_recapture );
		minimum_withdrawal_value		-= current_wdl_charges;

		return max( minimum_withdrawal_value , 0 );
	}
	else 
	{
		return 0.0;
	}
}

}


//@@ END

//@@ START - min_wdl_val_alt_e_bef_aig
// Alternate Minimum Withdrawal Value at EOM Before Decrements:                                                                                             
// Column:MIN_WDL_VAL_ALT_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_alt_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_alt_e_bef_aig.FIACARVM_LIAB.for"
// STW 20210517: add column
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;
else
{
	if ( fund_val_e_bef_aig(t) > SMALL_DOUBLE ) 
	{
		double minimum_withdrawal_value = min_wdl_val_alt_base_e_bef_aig(t);
		double current_wdl_charges = surr_chg_e_bef_aig(t);
		//double current_bonus_recapture = prem_bonus_recapture_inf_e_bef_aig(t);
		//return max( minimum_withdrawal_value - current_gmwb_charges - current_wdl_charges - current_bonus_recapture, 0 );
		return max( minimum_withdrawal_value - current_wdl_charges, 0 );
	}
	else 
	{
		return 0.0;
	}
}

}


//@@ END

//@@ START - min_wdl_val_b_aig
// Minimum withdrawal value:                                                                                             
// Column:MIN_WDL_VAL_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_b_aig(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_b_aig.FIACARVM_LIAB.for"
// DTL 20200707

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double min_wdl_val_b_cv;

if (t == 0) 
{
	min_wdl_val_b_cv = fia->min_wdl_val_e_aig(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else 
{
	double fund_val_b_cv = fund_val_b_aig(t);
	double pfwd_surr_cv  = pfwd_surr_aig(t);

	if (fund_val_b_cv > SMALL_DOUBLE) 
	{
		min_wdl_val_b_cv  = min_wdl_val_b_bef_aig(t);
		min_wdl_val_b_cv -= pfwd_surr_cv;
	}
	else 
	{
		min_wdl_val_b_cv = 0.0;
	}
}

return min_wdl_val_b_cv;

}


//@@ END

//@@ START - min_wdl_val_b_bef_aig
// Minimum withdrawal value:                                                                                             
// Column:MIN_WDL_VAL_B_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_b_bef_aig(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_b_bef_aig.FIACARVM_LIAB.for"
// DTL 20200707

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double min_wdl_val_b_bef_cv;

if (t == 0) 
{
	min_wdl_val_b_bef_cv = fia->min_wdl_val_e_aig(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else 
{
	double fund_val_b_bef_cv = fund_val_b_bef_aig(t);

	if (fund_val_b_bef_cv > SMALL_DOUBLE) 
	{
		min_wdl_val_b_bef_cv = min_wdl_val_e_aig(t - 1);
	}
	else 
	{
		min_wdl_val_b_bef_cv = 0.0;
	}
}

return min_wdl_val_b_bef_cv;

}


//@@ END

//@@ START - min_wdl_val_e_aig
// Minimum Withdrawal Value After PFWD                                                                                             
// Column:MIN_WDL_VAL_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_e_aig(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_e_aig.FIACARVM_LIAB.for"
// 20180822 MTC - MWV
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double min_wdl_val_e_bef_cv;
if (t == 0) {
	min_wdl_val_e_bef_cv = fia->min_wdl_val_e_aig(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else {
	if (fund_val_e_aig(t) > SMALL_DOUBLE) {
		min_wdl_val_e_bef_cv = min_wdl_val_e_bef_aig(t);
	}
	else {
		min_wdl_val_e_bef_cv = 0.0;
	}
}

return min_wdl_val_e_bef_cv;

}


//@@ END

//@@ START - min_wdl_val_e_bef_aig
// Minimum Withdrawal Value Before PFWD                                                                                             
// Column:MIN_WDL_VAL_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_e_bef_aig.FIACARVM_LIAB.for"
// 20180822 MTC - MWV
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double min_wdl_val_e_bef_cv;
double fund_val_e_bef_cv = fund_val_e_bef_aig(t);
if (fund_val_e_bef_cv > SMALL_DOUBLE) 
{
	double minimum_withdrawal_value_growth_rate = 0.0;

	if (t == 1) {
		minimum_withdrawal_value_growth_rate = pow(1.0 + fia->min_wdl_val_growth_pct_aig, mths_in_first_year / 12.0) - 1.0;
	}
	else {
		minimum_withdrawal_value_growth_rate = fia->min_wdl_val_growth_pct_aig;
	}

	// DTL 20200707 (START)
	double min_wdl_val_b_cv = min_wdl_val_b_aig(t);
	min_wdl_val_e_bef_cv    = min_wdl_val_b_cv * (1.0 + minimum_withdrawal_value_growth_rate);
	// DTL 20200707 (END)
}
else {
	min_wdl_val_e_bef_cv = 0.0;
}

return min_wdl_val_e_bef_cv;

}


//@@ END

//@@ START - min_wdl_val_final_b_aig
// Minimum Withdrawal Value at the beginning of the month                                                                                             
// Column:MIN_WDL_VAL_FINAL_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_final_b_aig(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_final_b_aig.FIACARVM_LIAB.for"
// STW 20210608: add column
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;
else
{
	double final_mwv = min_wdl_val_b_aig(t);
	if ( fia->min_wdl_val_method_aig == ALTERNATE_MWV )
	{
		double alternate_mwv = min_wdl_val_alt_b_aig(t);
		final_mwv = max( alternate_mwv, final_mwv );
	}

	return final_mwv;
}

}


//@@ END

//@@ START - min_wdl_val_final_e_aig
// Minimum Withdrawal Value at the end of the month                                                                                             
// Column:MIN_WDL_VAL_FINAL_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_final_e_aig(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_final_e_aig.FIACARVM_LIAB.for"
// STW 20210517: add column
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;
else
{
	double final_mwv = min_wdl_val_e_aig(t);
	if ( fia->min_wdl_val_method_aig == ALTERNATE_MWV )
	{
		double alternate_mwv = min_wdl_val_alt_e_aig(t);
		final_mwv = max( alternate_mwv, final_mwv );
	}

	return final_mwv;
}

}


//@@ END

//@@ START - min_wdl_val_final_e_bef_aig
// Minimum Withdrawal Value at the end of the month, before claims (and survivorship)                                                                                             
// Column:MIN_WDL_VAL_FINAL_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_final_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_final_e_bef_aig.FIACARVM_LIAB.for"
// STW 20210517: add column
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;
else
{
	double final_mwv = min_wdl_val_e_bef_aig(t);
	if ( fia->min_wdl_val_method_aig == ALTERNATE_MWV )
	{
		double alternate_mwv = min_wdl_val_alt_e_bef_aig(t);
		final_mwv = max( alternate_mwv, final_mwv );
	}

	return final_mwv;
}


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
if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (include_nh_defn == NO)
{
	return NO_AVG;
}

double nh_incidence_rate_cv;
if (carvm_cont_defn == YES)
{
	nh_incidence_rate_cv = nh_incid_rate(t - 1);
}
else
{
	nh_incidence_rate_cv = nh_incid_rate(t);
}

if (nh_incidence_rate_cv <= model_point_amount_threshold)
{
	return nh_benefits_pv(t - 1);
}

/*
DTL 20200624:
	MQ provided the rate averaging algorithm.
*/

double nh_benefits_pv_cv;

if (carvm_cont_defn == YES)  // DTL 20200707
{
	nh_benefits_pv_cv= 0.0;

	if (t == 1)
	{
		nh_benefits_pv_cv = 0.0;
	}
	else
	{
		double claims_cv     = surv(t - 2) * (1.0 - dth_claim_rate_experience_aig(t - 1)) * nh_incid_rate(t - 1);
		double disc_fct_cv   = carvm_disc_factor_non_elect(t - 1);
		double nh_benefit_cv = fund_val_b_bef_aig(t);

		nh_benefits_pv_cv = nh_benefits_pv(t - 1) + nh_benefit_cv * claims_cv * disc_fct_cv; 		
	}

	return nh_benefits_pv_cv;
}

// 20200624 DTL
double weight_cv            = nh_benefits_weight_aig;

double nh_benefits_pv_prev  = nh_benefits_pv(t - 1);
double surv_b_bef_cv        = surv(t - 1);

double fund_val_e_cv		= fund_val_e_aig(t);  // DTL 20200707
double fund_val_b_bef_cv    = fund_val_b_bef_aig(t);
double fund_val_avg         = weight_cv * fund_val_b_bef_cv + (1.0 - weight_cv) * fund_val_e_cv; // DTL 20200707

double surv_period_b_bef_cv = 1.0;
double surv_period_e_bef_cv = 1.0 - dth_claim_rate_experience_aig(t);
double surv_period_avg      = weight_cv * surv_period_b_bef_cv + (1.0 - weight_cv) * surv_period_e_bef_cv;

//nh_incidence_rate_cv		= nh_incid_rate(t);

double disc_fct_b_bef_cv    = carvm_disc_factor_non_elect(t - 1);
double disc_fct_e_bef_cv    = carvm_disc_factor_non_elect(t);
double disc_fct_avg         = weight_cv * disc_fct_b_bef_cv + (1.0 - weight_cv) * disc_fct_e_bef_cv;

nh_benefits_pv_cv = nh_benefits_pv_prev + 
	fund_val_avg * surv_b_bef_cv * surv_period_avg * nh_incidence_rate_cv * disc_fct_avg;
// 20200624 DTL

return nh_benefits_pv_cv;

/*
return nh_benefits_pv(t - 1) 
       + fund_val_e_bef_aig(t) //NH Benefits Base = Fund Value before PFWD
         * surv(t - 1)
		 * (1.0 - dth_claim_rate_experience_aig(t))  // DTL 20200121: TFS 86514
         * nh_incid_rate(t)
         * carvm_disc_factor_non_elect(t); //Non-elective disc factor
*/

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
if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (include_nh_defn == NO)
 return NO_AVG;

if (surr_chg_pct(t) <= model_point_amount_threshold || cash_val_e_aig(t) <= model_point_amount_threshold) //AG33:  Non-Elective Benefit Incidence Rates don't apply immediately after the cash value is depleted or after the surrender charge period
	return 0.0; 

// Set life1 lookup keys - special lookup keys are required for mortality variables
mort_attained_age = attained_age(t);
//mort_gender = xstring(gender);
mort_gender = gender;//WTW - Gen2 - remove xtstring casting

double nh_incid_rate_final = 0.0;
double nh_incid_rate_1 = 0.0;

//WTW - Gen2 - Mutating Lookup Term - shuffle conditional syntax in order to set lookup terms
/*if (gender == "Blended" || gender == "Joint")  // DTL 20200707: assume primary gender is MALE for JOINT model points.
{
	mort_gender = MALE;
}

nh_incid_rate_1 = max(0.0, min(1.0, nh_incid_base));

if (gender == "Blended" || gender == "Joint") // DTL 20200707
	{
	// Set life2 lookup keys
	// Life2 age is the same as for life1 for blended mortality
	mort_gender = FEMALE;
  
	double nh_incid_rate_2 = max(0.0, min(1.0, nh_incid_base));
  
	nh_incid_rate_final = fia->male_sex_pct * nh_incid_rate_1
						+ (1.0 - fia->male_sex_pct) * nh_incid_rate_2;
	}
else // if (gender != BLENDED)
	nh_incid_rate_final =  nh_incid_rate_1;

if (t == 1)
	return 1.0 - pow(1.0 - nh_incid_rate_final, mths_in_first_year / 12.0);
else
	return nh_incid_rate_final;*/

if (gender == "Blended" || gender == "Joint")  // DTL 20200707: assume primary gender is MALE for JOINT model points.
{
	mort_attained_age = attained_age(t);
	mort_gender = MALE;
	nh_incid_rate_1 = max(0.0, min(1.0, nh_incid_base));

	mort_attained_age = attained_age(t);
	mort_gender = FEMALE; 
	double nh_incid_rate_2 = max(0.0, min(1.0, nh_incid_base));
	
	nh_incid_rate_final = fia->male_sex_pct * nh_incid_rate_1
						+ (1.0 - fia->male_sex_pct) * nh_incid_rate_2;
}

else // if (gender != BLENDED)
	{
	mort_attained_age = attained_age(t);
	mort_gender = gender;
	nh_incid_rate_final =  max(0.0, min(1.0, nh_incid_base));
	}

if (t == 1)
	return 1.0 - pow(1.0 - nh_incid_rate_final, mths_in_first_year / 12.0);
else
	return nh_incid_rate_final;

}


//@@ END

//@@ START - pfwd_entitlement_b_aig
// FPW entitlement at beginning of year after discrete cashflows:                                                                                             
// Column:PFWD_ENTITLEMENT_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_entitlement_b_aig(int t) {
//^^^



//^^^

#line 1 "pfwd_entitlement_b_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

// DTL 20200229 (START)
// WTW Added for AIG
//if (gmwb_max_wdl_amt(t) > 0.0)
//{
//	return 0.0;
//}
// DTL 20200229 (END)

double pfwd_entitlement_b_bef_cv = pfwd_entitlement_b_bef_aig(t);
double pfwd_cv = pfwd_surr_aig(t);
double pfwd_entitlement_cv = max(0, pfwd_entitlement_b_bef_cv - pfwd_cv);

return pfwd_entitlement_cv;

}


//@@ END

//@@ START - pfwd_entitlement_b_bef_aig
// FPW available at beginning of year:                                                                                             
// Column:PFWD_ENTITLEMENT_B_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_entitlement_b_bef_aig(int t) {
//^^^



//^^^

#line 1 "pfwd_entitlement_b_bef_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double pfwd_entitlement_cv = 0.0;

if ( fia->pfwd_amt_avail_defn == FUND_VALUE )
{	
	double pfwd_pct_cv	= pfwd_pct_aig(t);  // DTL 20200707: NYIA
	double fund_val_cv	= fund_val_b_bef_aig(t);
	pfwd_entitlement_cv = pfwd_pct_cv * fund_val_cv;
}

// DTL 20200707: NYIA (START)
double pfwd_surr_curr_pol_yr_cv = 0.0;
if (t == 1 && fabs(12.0 - mths_in_first_year) > model_point_amount_threshold)
{
	pfwd_surr_curr_pol_yr_cv = fia->pfwd_surr_curr_pol_yr(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
// DTL 20200707: NYIA (END)

pfwd_entitlement_cv	= max(0.0, pfwd_entitlement_cv - pfwd_surr_curr_pol_yr_cv);  // DTL 20200707
return pfwd_entitlement_cv;

}


//@@ END

//@@ START - pfwd_entitlement_e_aig
// Partial Free Withdrawal Entitlement After Withdrawals:                                                                                             
// Column:PFWD_ENTITLEMENT_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_entitlement_e_aig(int t) {
//^^^



//^^^

#line 1 "pfwd_entitlement_e_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double pfwd_entitlement_e_cv = pfwd_entitlement_e_bef_aig(t);
return pfwd_entitlement_e_cv;

}


//@@ END

//@@ START - pfwd_entitlement_e_bef_aig
// Penalty Free Withdrawal Entitlement                                                                                             
// Column:PFWD_ENTITLEMENT_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_entitlement_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "pfwd_entitlement_e_bef_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double pfwd_entitlement_e_bef_cv = pfwd_entitlement_b_aig(t);
return pfwd_entitlement_e_bef_cv;

}


//@@ END

//@@ START - pfwd_pct_aig
// Free partial withdrawal percentage:                                                                                             
// Column:PFWD_PCT_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_pct_aig(int t) {
//^^^



//^^^

#line 1 "pfwd_pct_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA

if (t < 0 || t > max_calc_period + 1)//WTW - Gen2 - time guards
	return NO_AVG;

const int MTHS_PER_YR	= 12.0;
int iloop_pol_yr_cv		= pol_yr(t);
int oloop_pol_yr_cv     = fia->pol_yr(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula

int lookup_mth;
if (t == 0)
{
	lookup_mth = fia->res_period;//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else 
{
	lookup_mth = fia->res_period + (iloop_pol_yr_cv - oloop_pol_yr_cv) * MTHS_PER_YR;//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}

/*
if (carvm_cont_defn == YES)
{
	lookup_mth		   += 12.0;
}
*/

fia->pol_yr_lookup_gen2 = fia->pol_yr(lookup_mth); //WTW - Gen2 - AtTime() not allowed
double pfwd_pct_cv		= fia->pfwd_pct/*.AtTime(lookup_mth)*/;

return pfwd_pct_cv;

}


//@@ END

//@@ START - pfwd_surr_aig
// Withdrawal amount at beginning of year:                                                                                             
// Column:PFWD_SURR_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_surr_aig(int t) {
//^^^



//^^^

#line 1 "pfwd_surr_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor

if (t <= 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double fund_val_b_bef_cv		 = fund_val_b_bef_aig(t);
double pfwd_entitlement_b_bef_cv = pfwd_entitlement_b_bef_aig(t);

double pfwd_surr_cv;

//20230127 SJ: For XOL deal, calculate base stat res only when calc base reserve switch is on. Both full and no pfwd are considered while calculating base reserve.
if (calc_base_res_only_aig == "Yes" && pfwd_model == "FULL")
	return min(pfwd_entitlement_b_bef_cv, fund_val_b_bef_cv);

if (calc_base_res_only_aig == "Yes" && pfwd_model == "NONE")
	return 0.0;
//20230127 SJ END

if (fia->gmwb_flag)
{
	double gmwb_max_wdl_amt_cv		 = gmwb_max_wdl_amt_aig(t);

	if ( pfwd_model == "FULL"									  &&
	     gmwb_max_wdl_amt_cv < model_point_amount_threshold    )
	{
		pfwd_surr_cv = min(pfwd_entitlement_b_bef_cv, fund_val_b_bef_cv);
		return pfwd_surr_cv;
	}

	double pfwd_surr_curr_pol_yr = 0.0;
	if (t == 1 && fabs(12.0 - mths_in_first_year) > model_point_amount_threshold)  // DTL 20200707
	{
		pfwd_surr_curr_pol_yr = fia->pfwd_surr_curr_pol_yr(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
	}

	double admin_fee_cv = admin_fee(t);
	if (fund_val_b_bef_cv - admin_fee_cv - (gmwb_max_wdl_amt_cv - pfwd_surr_curr_pol_yr) <= model_point_amount_threshold)
	{
		pfwd_surr_cv = max(0.0, fund_val_b_bef_cv - admin_fee_cv);
		return pfwd_surr_cv;
	}

	pfwd_surr_cv = max(gmwb_max_wdl_amt_cv - pfwd_surr_curr_pol_yr, 0.0);
	return pfwd_surr_cv;
}

if (pfwd_model == "NONE")
{
	return 0.0;
}

pfwd_surr_cv = min(pfwd_entitlement_b_bef_cv, fund_val_b_bef_cv);
return pfwd_surr_cv;

}


//@@ END

//@@ START - pfwd_surr_cumul_aig
// Cumulative FPWs taken:                                                                                             
// Column:PFWD_SURR_CUMUL_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_surr_cumul_aig(int t) {
//^^^



//^^^

#line 1 "pfwd_surr_cumul_aig.FIACARVM_LIAB.for"
// DTL 20200317: GLB refactor

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (t == 0)
{
	return fia->pfwd_surr_cumul(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
	
return pfwd_surr_cumul_aig(t - 1) + pfwd_surr_aig(t);

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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double pfwd_surr_pv_cv;
if (t == 0)
{
	pfwd_surr_pv_cv = pfwd_surr_aig(t) * surv(t) * carvm_disc_factor_elect_cash_val(t);
}
else
{
	/*
	DTL 2020624:
		MQ provided this averaging algorithm.
	*/

	double weight_cv = pfwd_surr_weight_aig;

	if (carvm_cont_defn == YES)  // DTL 20200707
	{
		// Should we just leave this to the value in the assumptions XLS?
		weight_cv = 1.0;
	}

	double surv_prev = surv(t - 1);
	double surv_cv   = surv(t);
	double surv_avg  = weight_cv * surv_prev + (1.0 - weight_cv) * surv_cv;

	double disc_factor_prev = carvm_disc_factor_elect_cash_val(t - 1);
	double disc_factor_cv   = carvm_disc_factor_elect_cash_val(t);
	double disc_factor_avg  = weight_cv * disc_factor_prev + (1.0 - weight_cv) * disc_factor_cv;

	double pfwd_surr_pv_prev = pfwd_surr_pv(t - 1);
	double pfwd_surr_cv      = pfwd_surr_aig(t);

	pfwd_surr_pv_cv = pfwd_surr_pv_prev + pfwd_surr_cv * surv_avg * disc_factor_avg;
}

	
return pfwd_surr_pv_cv;

}


//@@ END

//@@ START - pol_mth_aig
// Policy Month (relative to issue):                                                                                             
// Column:POL_MTH_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_pol_mth_aig(int t) {
//^^^



//^^^

#line 1 "pol_mth_aig.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double policy_month;
if (t <= 0)
{
	policy_month = 0.0;
}
else if (t == 1)
{
	policy_month = fia->res_period;//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else
{
	const double MONTH_PER_YEAR = 12.0;
	policy_month = (pol_yr(t) - 1.0) * MONTH_PER_YEAR;
}

return policy_month;

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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - Time guards
	return NO_AVG;

if (t == 0)
	return fia->pol_yr(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
	
if (t == 1 && fabs(12.0 - mths_in_first_year) > model_point_amount_threshold)
	return pol_yr(t - 1);

return pol_yr(t - 1) + 1.0;

}


//@@ END

//@@ START - policies_female_experience_aig
// End-Of-Month Policies In Force With Only Female Alive, Experience Mortality                                                                                             
// Column:POLICIES_FEMALE_EXPERIENCE_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_policies_female_experience_aig(int t) {
//^^^



//^^^

#line 1 "policies_female_experience_aig.FIACARVM_LIAB.for"
/*!Female Population							
   =================							
   @author Michael Ching							
   @date 20180514							
							
   Referencing the <a href="http://library.soa.org/library/actuary/1967-79/ACT7803.pdf">Frasier Method</a>, we track the							
   population of female alive, male dead status policyholders by using the below algorithm:							
							
   \f[							
   female\,policies_{t} = joint\,policies_{t-1} * probability\,male\,dies\,and\,female\,survives_{t} + female\,policies_{t-1} * probability\,female\,survives_{t}							
   \f]							
							
   Written another way,							
							
   \f[							
   female\,policies_{t} = joint\,policies_{t-1} * (1 - female\,monthly\,death\,rate_{t}) * male\,monthly\,death\,rate_{t} + female\,policies_{t-1} * (1 - female\,monthly\,death\,rate_{t})							
   \f]							
							
   Male and female death rates are calculated externally in dth_claim_rate_calc().							
							
   @note This is a recursive function.							
							
   @note This is only used for Joint gender policies.							
							
   Related Inputs:							
   ---------------							
   -# **MP** `gender` - This column will only produce values if `gender` is Joint.							
   .							
							
   @return Number of policies with female status (female alive, male dead) at the end of month t.							
*/							
							
// 20180504 MTC - Joint logic							
// 20180910 MTC - Ported from outer loop Joint logic
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (gender != JOINT)
{							
	return NO_AVG;						
}							
							
if (t == 0)
{							
	return fia->policies_female_experience_aig(fia->res_period);	//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula					
} 							
else
{							
	// Initialize											
	double dth_claim_rate_male;						
	double dth_claim_rate_female;						
							
	// Get mortality rates						
	dth_claim_rate_male   = dth_claim_rate_male_experience_aig(t);	  // DTL 20200121 (START): TFS 86514		
	dth_claim_rate_female = dth_claim_rate_female_experience_aig(t);  // DTL 20200121 (START): TFS 86514
													
	double policies_female = policies_joint_experience_aig(t - 1) * dth_claim_rate_male * (1.0 - dth_claim_rate_female)						
							 + policies_female_experience_aig(t - 1) * (1.0 - dth_claim_rate_female);
							
	return policies_female;						
}							


}


//@@ END

//@@ START - policies_joint_experience_aig
// End-Of-Month Policies In Force With Joint Status, Experience Mortality                                                                                             
// Column:POLICIES_JOINT_EXPERIENCE_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_policies_joint_experience_aig(int t) {
//^^^



//^^^

#line 1 "policies_joint_experience_aig.FIACARVM_LIAB.for"
/*!Joint Status Population			
   =======================			
   @author Michael Ching			
   @date 20180514			
			
   Referencing the <a href="http://library.soa.org/library/actuary/1967-79/ACT7803.pdf">Frasier Method</a>, we track the			
   population of joint status policyholders by using the below algorithm:			
			
   \f[			
   joint\,policies_{t} = joint\,policies_{t-1} * (1 - joint\,status\,monthly\,death\,rate_{t})			
   \f]			
			
   \f$joint\,status\,monthly\,death\,rate_{t}\f$ is calculated externally in dth_claim_rate_calc().			
			
   @note This is a recursive function.			
			
   @note This is only used for Joint gender policies.			
			
   Related Inputs:			
   ---------------			
   -# **MP** `gender` - This column will only produce values if `gender` is Joint.			
   .			
			
   @return Number of policies with joint survivorship status (both alive) at the end of month t.			
*/			
			
// 20180504 MTC - Joint logic			
// 20180910 MTC - Ported from outer loop Joint logic
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (gender != JOINT)
{			
	return NO_AVG;		
}			
			
if (t == 0)
{			
	return fia->policies_joint_experience_aig(fia->res_period);	//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula	
} 			
else
{			
	// DTL 20200121 (START): TFS 86514
	double dth_claim_rate_mthly_male   = dth_claim_rate_male_experience_aig(t);						
	double dth_claim_rate_mthly_female = dth_claim_rate_female_experience_aig(t);
			
	double joint_status_lives = policies_joint_experience_aig(t - 1) * (1.0 - dth_claim_rate_mthly_male) * (1.0 - dth_claim_rate_mthly_female);	
			
	return joint_status_lives;
	// DTL 20200121 (END): TFS 86514	
}			


}


//@@ END

//@@ START - policies_last_survivor_experience_aig
// End-Of-Month Policies With Last Survivor Status, Experience Mortality                                                                                             
// Column:POLICIES_LAST_SURVIVOR_EXPERIENCE_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_policies_last_survivor_experience_aig(int t) {
//^^^



//^^^

#line 1 "policies_last_survivor_experience_aig.FIACARVM_LIAB.for"
/*!Last Survivor Population	
   ========================	
   @author Michael Ching	
   @date 20180514	
	
   Referencing the <a href="http://library.soa.org/library/actuary/1967-79/ACT7803.pdf">Frasier Method</a>, we track the	
   population of last survivor status policyholders by using the below algorithm:	
	
   \f[	
   last\,survivor\,policies_{t} = joint\,policies_{t} + male\,policies_{t} + female\,policies_{t}	
   \f]	
	
   Where:	
	
   -# \f$joint\,policies_{t}\f$ is calculated from the column va_liab_policies_joint_aig().	
   -# \f$male\,policies_{t}\f$ is calculated from the column va_liab_policies_male_aig().	
   -# \f$female\,policies_{t}\f$ is calculated from the column va_liab_policies_female_aig().	
	
   @note This is a recursive function.	
	
   @note This is only used for Joint gender policies.	
	
   Related Inputs:	
   ---------------	
   -# **MP** `gender` - This column will only produce values if `gender` is Joint.	
   .	
	
   @return Number of policies with last survivor status (at least one alive) at the end of month t.	
*/	
	
// 20180504 MTC - Joint logic	
// 20180910 MTC - Ported from outer loop Joint logic
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (gender != JOINT)
{	
	return NO_AVG;
}	
	
double policies_last_survivor = policies_joint_experience_aig(t) + policies_male_experience_aig(t) + policies_female_experience_aig(t);	
	
return policies_last_survivor;	


}


//@@ END

//@@ START - policies_male_experience_aig
// End-Of-Month Policies In Force With Only Male Alive, Experience Mortality                                                                                             
// Column:POLICIES_MALE_EXPERIENCE_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_policies_male_experience_aig(int t) {
//^^^



//^^^

#line 1 "policies_male_experience_aig.FIACARVM_LIAB.for"
/*!Male Population					
   ===============					
   @author Michael Ching					
   @date 20180514					
					
   Referencing the <a href="http://library.soa.org/library/actuary/1967-79/ACT7803.pdf">Frasier Method</a>, we track the					
   population of male alive, female dead status policyholders by using the below algorithm:					
					
   \f[					
   male\,policies_{t} = joint\,policies_{t-1} * probability\,female\,dies\,and\,male\,survives_{t} + male\,policies_{t-1} * probability\,male\,survives_{t}					
   \f]					
					
   Written another way,					
					
   \f[					
   male\,policies_{t} = joint\,policies_{t-1} * (1 - male\,monthly\,death\,rate_{t}) * female\,monthly\,death\,rate_{t} + male\,policies_{t-1} * (1 - male\,monthly\,death\,rate_{t})					
   \f]					
					
   Male and female death rates are calculated externally in dth_claim_rate_calc().					
					
   @note This is a recursive function.					
					
   @note This is only used for Joint gender policies.					
					
   Related Inputs:					
   ---------------					
   -# **MP** `gender` - This column will only produce values if `gender` is Joint.					
   .					
					
   @return Number of policies with male status (male alive, female dead) at the end of month t.					
*/					
					
// 20180504 MTC - Joint logic					
// 20180910 MTC - Ported from outer loop Joint logic
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (gender != JOINT)
{					
	return NO_AVG;				
}					
					
if (t == 0)
{					
	return fia->policies_male_experience_aig(fia->res_period);			//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula	
} 					
else
{					
	// Initialize						
	double dth_claim_rate_male;				
	double dth_claim_rate_female;				
					
	// Get mortality rates				
	dth_claim_rate_male   = dth_claim_rate_male_experience_aig(t);	 // DTL 20200121: TFS 86514
	dth_claim_rate_female = dth_claim_rate_female_experience_aig(t); // DTL 20200121: TFS 86514
				
					
	double policies_male = policies_joint_experience_aig(t - 1) * dth_claim_rate_female * (1.0 - dth_claim_rate_male)					
						   + policies_male_experience_aig(t - 1) * (1.0 - dth_claim_rate_male);
								
	return policies_male;				
}					


}


//@@ END

//@@ START - prem_bonus_recapture_aig
// Premium Bonus Recapture:                                                                                             
// Column:PREM_BONUS_RECAPTURE_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_prem_bonus_recapture_aig(int t) {
//^^^



//^^^

#line 1 "prem_bonus_recapture_aig.FIACARVM_LIAB.for"
// DTL 20181105 : adding column
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;
else
{
	double bonus_recapture;
	bonus_recapture = fia->prem_bonus_base_e_aig(fia->res_period) * prem_bonus_recapture_pct_carvm_aig;//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula

	return bonus_recapture;
}

}


//@@ END

//@@ START - prem_cumul_prop_wdl_aig
// prem reduced proportionally by wdl                                                                                             
// Column:PREM_CUMUL_PROP_WDL_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_prem_cumul_prop_wdl_aig(int t) {
//^^^



//^^^

#line 1 "prem_cumul_prop_wdl_aig.FIACARVM_LIAB.for"
//20241205 MQ new column
if (t < 0 || t > max_calc_period)
{
	return NO_AVG;
}
	
double prem_cumul_less_wdl;

if (t == 0)
{
	prem_cumul_less_wdl = fia->prem_cumul_proportional_wdl_aig(fia->res_period); 
}
else
{
	if (fund_val_b_aig(t) < SMALL_DOUBLE)
	{
		return 0.;
	}
	
	double reduction_factor = 0.;

	if (fund_val_b_bef_aig(t) > SMALL_DOUBLE)
	{
		reduction_factor = fund_val_b_aig(t) / fund_val_b_bef_aig(t);
	}
	
	prem_cumul_less_wdl = prem_cumul_prop_wdl_aig(t - 1) * reduction_factor;  
}

return prem_cumul_less_wdl;

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
//if (t < 0 || t > max_calc_period)
//	return NO_AVG;

if (t != 0)//WTW - Gen2 - time guards
	return NO_AVG;

// Stop calculations when fund value is exhausted
if (t > 0 && fabs(fund_val_e_aig(t - 1)) < model_point_amount_threshold)
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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (carvm_calc_annuitzn_defn == NOT_APPLICABLE)
	return NO_AVG;
		
// Stop calculations when fund value is exhausted
if (t > 0 && fabs(fund_val_e_aig(t - 1)) < model_point_amount_threshold)
	return NO_AVG;

if (gender != JOINT) // 20180910 MTC - Halt on unsupported gender for annuitization tests
{
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
else
{
	throw FatalError("JOINT gender not supported in CARVM annuitization tests.  Fraiser mechanics have not been implemented.");
}

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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double current_pv_cash;

// Stop calculations when fund value is exhausted
if (t > 0 && fabs(fund_val_e_aig(t - 1)) < model_point_amount_threshold)   // DTL 20200317
{
	if ( fund_val_b_aig(t - 1) > model_point_amount_threshold )  // DTL 20200317
	{
		current_pv_cash = gmwb_ann_benefits_pv(t);
	}
	else
	{
		return NO_AVG;
	}
}
else
{
	current_pv_cash = dth_benefits_pv(t)
				         + nh_benefits_pv(t)
				         + pfwd_surr_pv(t) 
				         + cash_val_pv(t)
						 + gmwb_ann_benefits_pv(t);
}

if (current_pv_cash > res_integrated_cash_val(t + 1))
	pv_max_period = t;


double res_cash_val_cv = max(res_integrated_cash_val(t + 1), current_pv_cash);

return res_cash_val_cv;


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

//if (this == fia_carvm_tax)//WTW - Gen2 - workaround for illegal pointer comparison
//	model_name = "TAX";

//WTW - Gen2 - move this external formula to initialize() cannot call columns from startup()
//set_hidden_variables(0); // DTL 20200121: TFS 87109

return 1.0;

}


//@@ END

//@@ START - surr_chg_b_aig
// Surrender charge:                                                                                             
// Column:SURR_CHG_B_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg_b_aig(int t) {
//^^^



//^^^

#line 1 "surr_chg_b_aig.FIACARVM_LIAB.for"
// DTL 20200707

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double surr_chg_base  = 0.0;
double surr_chg_value = 0.0;

double fund_val_b_cv		 = fund_val_b_aig(t);
double pfwd_entitlement_b_cv = pfwd_entitlement_b_aig(t);

if (fia->surr_chg_defn == FUND_VALUE)
{
	double prem_bonus_recapture_cv   = prem_bonus_recapture_aig(t);
	double contract_val_b_cv		 = contract_val_b_aig(t);

	surr_chg_base = max(fund_val_b_cv - prem_bonus_recapture_cv, contract_val_b_cv)
		                - pfwd_entitlement_b_cv;	
}

// DTL 20200707: NYIA (START)
else if (fia->surr_chg_defn == NYIA_CASH_VALUE)
{
	double mav_b_cv                  = min_accum_val_b_aig(t);
	double max_mav_and_fund_val_b_cv = max(mav_b_cv, fund_val_b_cv);
	
	surr_chg_base                    = max(0, max_mav_and_fund_val_b_cv - pfwd_entitlement_b_cv);
}
// DTL 20200707: NYIA (END)

else if (fia->surr_chg_defn == PREMIUM)
{
	surr_chg_base = prem_cumul;
}

double surr_chg_pct_cv = surr_chg_pct(t);
surr_chg_value		   = max(0.0, surr_chg_base * surr_chg_pct_cv);

return surr_chg_value;

}


//@@ END

//@@ START - surr_chg_b_bef_aig
// Surrender charge:                                                                                             
// Column:SURR_CHG_B_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg_b_bef_aig(int t) {
//^^^



//^^^

#line 1 "surr_chg_b_bef_aig.FIACARVM_LIAB.for"
// DTL 20200707

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double surr_chg_base  = 0.0;
double surr_chg_value = 0.0;

double fund_val_b_bef_cv		 = fund_val_b_bef_aig(t);
double pfwd_entitlement_b_bef_cv = pfwd_entitlement_b_bef_aig(t);

if (fia->surr_chg_defn == FUND_VALUE)
{
	double prem_bonus_recapture_cv   = prem_bonus_recapture_aig(t);
	double contract_val_b_bef_cv	 = contract_val_b_bef_aig(t);

	surr_chg_base = max(fund_val_b_bef_cv - prem_bonus_recapture_cv, contract_val_b_bef_cv)
		                - pfwd_entitlement_b_bef_cv;	
}

// DTL 20200707: NYIA (START)
else if (fia->surr_chg_defn == NYIA_CASH_VALUE)
{
	double mav_b_bef_cv                  = min_accum_val_b_bef_aig(t);
	double max_mav_and_fund_val_b_bef_cv = max(mav_b_bef_cv, fund_val_b_bef_cv);
	
	surr_chg_base						 = max(0, max_mav_and_fund_val_b_bef_cv - pfwd_entitlement_b_bef_cv);
}
// DTL 20200707: NYIA (END)

else if (fia->surr_chg_defn == PREMIUM)
{
	surr_chg_base = prem_cumul;
}

double surr_chg_pct_cv = surr_chg_pct(t);
surr_chg_value		   = max(0.0, surr_chg_base * surr_chg_pct_cv);

return surr_chg_value;

}


//@@ END

//@@ START - surr_chg_e_aig
// Surrender Charge After Withdrawals:                                                                                             
// Column:SURR_CHG_E_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg_e_aig(int t) {
//^^^



//^^^

#line 1 "surr_chg_e_aig.FIACARVM_LIAB.for"
// DTL 20200229: added new column to track surrender charge after withdrawals

if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double surr_chg_base  = 0.0;
double surr_chg_value = 0.0;
 
if (fia->surr_chg_defn == FUND_VALUE)
{
	double fund_val_aft_pfwd_cv     = fund_val_e_aig(t);
	double prem_bonus_recapture_cv  = prem_bonus_recapture_aig(t);
	double contract_val_bef_surr_cv = contract_val_e_aig(t);
	double pfwd_entitlement_cv      = pfwd_entitlement_e_aig(t);

	surr_chg_base = max( fund_val_aft_pfwd_cv - prem_bonus_recapture_cv, contract_val_bef_surr_cv )   // DTL 20181105 : adding consideration for premium bonus recapture
		                - pfwd_entitlement_cv;		
}
// DTL 20200707: NYIA (START)
else if (fia->surr_chg_defn == NYIA_CASH_VALUE)
{
	double fund_val_e_cv             = fund_val_e_aig(t);
	double mav_e_cv                  = min_accum_val_e_aig(t);
	double max_mav_and_fund_val_e_cv = max(mav_e_cv, fund_val_e_cv);
	double pfwd_entitlement_e_cv     = pfwd_entitlement_e_aig(t);
	
	surr_chg_base                    = max(0, max_mav_and_fund_val_e_cv - pfwd_entitlement_e_cv);
}
// DTL 20200707: NYIA (END)
else if (fia->surr_chg_defn == PREMIUM)
{
	surr_chg_base = prem_cumul;
}

double surr_chg_pct_cv = surr_chg_pct(t);
surr_chg_value = max(0.0, surr_chg_base * surr_chg_pct_cv);

return surr_chg_value;

}


//@@ END

//@@ START - surr_chg_e_bef_aig
// Surrender Charge                                                                                             
// Column:SURR_CHG_E_BEF_AIG
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg_e_bef_aig(int t) {
//^^^



//^^^

#line 1 "surr_chg_e_bef_aig.FIACARVM_LIAB.for"
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

double surr_chg_base = 0.0;
double surr_chg_value = 0.0;
 
if (fia->surr_chg_defn == FUND_VALUE)
{
	// DTL 20200229 (START)
	double fund_val_bef_pfwd_cv     = fund_val_e_bef_aig(t);
	double prem_bonus_recapture_cv  = prem_bonus_recapture_aig(t);
	double contract_val_bef_pfwd_cv = contract_val_e_bef_aig(t);
	double pfwd_entitlement_bef_cv  = pfwd_entitlement_e_bef_aig(t);

	surr_chg_base = max( fund_val_bef_pfwd_cv - prem_bonus_recapture_cv, contract_val_bef_pfwd_cv )   // DTL 20181105 : adding consideration for premium bonus recapture
		                - pfwd_entitlement_bef_cv;	
	// DTL 20200229 (END)	
}
// DTL 20200707: NYIA (START)
else if (fia->surr_chg_defn == NYIA_CASH_VALUE)
{
	double fund_val_e_bef_cv             = fund_val_e_bef_aig(t);
	double mav_e_bef_cv                  = min_accum_val_e_bef_aig(t);
	double max_mav_and_fund_val_e_bef_cv = max(mav_e_bef_cv, fund_val_e_bef_cv);
	double pfwd_entitlement_e_bef_cv     = pfwd_entitlement_e_bef_aig(t);
	
	surr_chg_base                        = max(0, max_mav_and_fund_val_e_bef_cv - pfwd_entitlement_e_bef_cv);
}
// DTL 20200707: NYIA (END)
else if (fia->surr_chg_defn == PREMIUM)
{
	surr_chg_base = prem_cumul;
}

double surr_chg_pct_cv = surr_chg_pct(t);
surr_chg_value = max(0.0, surr_chg_base * surr_chg_pct_cv);

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
if (t < 0 || t > max_calc_period + 1)//WTW - Gen2 - time guards
	return NO_AVG;

// 20180909 MTC - [ID: TK00074973] Surrender charge percent lookup fix
int surr_chg_pol_period = 0;

if (t == 0)
{
	surr_chg_pol_period = fia->res_period;//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}
else 
{
	surr_chg_pol_period = fia->res_period 
						  + (pol_yr(t) - fia->pol_yr(fia->res_period)) * 12;//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
}

//02032025 MQ chg for renewable MYGA
if (fia->myga_renewable_ind == YES && pol_yr(t) > fia->myga_init_term)
{
	int shifted_pol_yr = mod(pol_yr(t) - fia->myga_init_term, fia->myga_renew_term);

	if (shifted_pol_yr < SMALL_DOUBLE)
	{
		shifted_pol_yr = fia->myga_renew_term;
	}

	fia->pol_yr_lookup_gen2	= shifted_pol_yr;
	return fia->surr_chg_pct_renewal_aig;
}

fia->pol_yr_lookup_gen2 = fia->pol_yr(surr_chg_pol_period);//WTW - Gen2 - surr_chg_pct cannot use time based lookup in an external formula - need to update all instances to use this working variable
return fia->surr_chg_pct/*.AtTime(surr_chg_pol_period)*/;//WTW - Gen2 - AtTime() not supported
// 20180909 MTC END

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
if (t < 0 || t > max_calc_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (t == 0)//WTW - Gen2 - cannot merge time guards
	return 1.0;

//if (t <= 0) 
//	return 1.0;

if (include_nh_defn == YES)
	return surv(t - 1) * (1.0 - dth_claim_rate_experience_aig(t)) * (1.0 - nh_incid_rate(t)); // DTL 20200121: TFS 86514

return surv(t - 1) * (1.0 - dth_claim_rate_experience_aig(t)); // DTL 20200121: TFS 86514

}


//@@ END

//@@ START - carvm_annuitzn_test_num
// Carvm Annuitzn Test Number                                                                                             
// Calculated Variable:CARVM_ANNUITZN_TEST_NUM
//========================================================
int FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_annuitzn_test_num() {
//^^^


#line 1 "carvm_annuitzn_test_num.FIACARVM_LIAB.for"
//WTW - Gen2 - Move the code from set_hidden_variables()
if (model_name_gen2 == "STAT"/*this == fia_carvm_stat*/ || (model_name_gen2 == "TAX"/*this == fia_carvm_tax*/ && !fia->tax_res_equals_stat_flag))//WTW - Gen2 - comparison of distinct pointers error
	{
	if (carvm_calc_annuitzn_defn != NOT_APPLICABLE)
		return fia->carvm_annuitzn_tests_number;
	else
		return 0;
	} 
else
	return 0;

}


//@@ END

//@@ START - carvm_cont_defn_aig
// Lookup key: not sure why `carvm_cont_defn` input variable doesn't work:                                                                                             
// Calculated Variable:CARVM_CONT_DEFN_AIG
//========================================================
xstring FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_cont_defn_aig() {
//^^^


#line 1 "carvm_cont_defn_aig.FIACARVM_LIAB.for"
// 20200624 DTL
/*
	I tried using the input variables `stat_carvm_cont_defn`/`tax_carvm_cont_defn` as lookup keys 
	in the Input Manager and somehow this didn't work, so here we are -- I've created this scalar only as a
	lookup key to be used in the Input Manager.

	(I think the issue is probably that `carvm_cont_defn` the code variable is an enumerated value, whereas
	we need a string for the lookup.)
*/

if (carvm_cont_defn == YES)
{
	return "continuous";
}
else
{
	return "curtate";
}

}


//@@ END

//@@ START - glb_withdrls_have_begun_aig
// Have GLB withdrawals begun in the outer loop?                                                                                             
// Calculated Variable:GLB_WITHDRLS_HAVE_BEGUN_AIG
//========================================================
xstring FIACARVM_LIAB_UDF::fiacarvm_liab_glb_withdrls_have_begun_aig() {
//^^^


#line 1 "glb_withdrls_have_begun_aig.FIACARVM_LIAB.for"
// DTL 20200707: NYIA

double pol_yr_cv			= fia->pol_yr(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
double gmwb_exercise_yrs_cv = fia->gmwb_exercise_yrs_aig(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula

if (pol_yr_cv > fia->gmwb_req_yrs_wait + gmwb_exercise_yrs_cv)
{
	return "Yes";
}
else
{
	return "No";
}

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
valn_issue_yr = fia->issue_yr;

double life_int_rate = carvm_life_int_rate; 

int guar_dur = 0;
for (guar_dur = 0; guar_dur <= 21; guar_dur++)
	{
	if (fia->crediting_rate_gtd <= life_int_rate/*carvm_life_int_rate*/)//WTW - Gen2 - Mutating Lookup Term
		break;
	}

return guar_dur;

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

//@@ START - max_calc_period
// Maximum Period to Calc Reserves                                                                                             
// Calculated Variable:MAX_CALC_PERIOD
//========================================================
int FIACARVM_LIAB_UDF::fiacarvm_liab_max_calc_period() {
//^^^


#line 1 "max_calc_period.FIACARVM_LIAB.for"
int fnd = 0;
int term_to_omega_age;
int test_age_end = fia->commencement_period + (150 * 12);
double carvm_mort_base_rate = 0.0;
int test_age;

for (test_age = fia->commencement_period + 1; test_age < test_age_end; test_age += 12)
	{
	// Set lookup key
		mort_issue_age = issue_age_aig;  // 20201030 DTL
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
	}
	
if (!fnd)
	{
	xstring message;

	message = "Unable to calculate Omega for Calc Reserves. ";
	message += "Mortality rates must ascend to 1. ";
	message += "Plan Code: " + xstring(fia->plan_code);
	message += ", Issue Age: " + xstring(issue_age_aig);  // 20201030 DTL
								
	log_screen << message << MSG_ERROR;

	if (fia->gen2_defn == NO)
		makeRunLogYellow();	  //WTW - Gen2 - makeRunLogYellow() not supported

	term_to_omega_age = 121;
	}

int mat_period 
    = term_to_omega_age
      - xint((fia->elapsed_mths + fia->res_period) / 12.0) + 1;//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula

// For GMWB model points, need to project beyond carvm_max_dur to handle exercise points
if (fia->gmwb_flag && calc_base_res_only_aig == "No") //20230127 SJ: For XOL deal, calculate base stat res only when switch is on.
	{
	return min(min(fia->maturity_period / 12, mat_period), 
		       t_high / 12);

	}

return min(min(fia->maturity_period / 12, mat_period), 
		   min(t_high / 12, carvm_max_dur));

}


//@@ END

//@@ START - mths_in_first_year
// Months in the First Projection Period                                                                                             
// Calculated Variable:MTHS_IN_FIRST_YEAR
//========================================================
double FIACARVM_LIAB_UDF::fiacarvm_liab_mths_in_first_year() {
//^^^


#line 1 "mths_in_first_year.FIACARVM_LIAB.for"
int elpsd_mths = fia->elapsed_mths; // 20200624 DTL

// ***** Calculate number of months in first projection period *****
return 12 - xint(mod(elpsd_mths + fia->res_period, 12));  // 20200624 DTL//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula

/* 20200624 DTL
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
*/

}


//@@ END

//@@ START - pfwd_model
// Penalty Free Withdrawal Model Definition:                                                                                             
// Calculated Variable:PFWD_MODEL
//========================================================
xstring FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_model() {
//^^^


#line 1 "pfwd_model.FIACARVM_LIAB.for"
//20230127 SJ: For XOL deal, calculate base stat res only when calc base reserve switch is on. Both full and no pfwd are considered while calculating base reserve.
if (calc_base_res_only_aig == "Yes") 
{
	if (pfwd_model_switch_aig == "FULL")
		return "FULL";
	else
		return "NONE";
}

if (getElementNumber() == 1)
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
return fia->prem_cumul(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula

}


//@@ END


#line 1 "dividend_yield.FIACARVM_LIAB.for"                                                                                   
double FIACARVM_LIAB::dividend_yield(int t, const xstring &eqt_index)
{
if (t < 0 || t > max_calc_period)
	return 0.;

if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
	return fia_rates->get_index_rate(fia->res_period + t * 12, //WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
					eqt_index,
					GET_DIVIDEND_YIELD,
					EFFECTIVE_ANNUAL);

return rates->get_index_rate(fia->res_period + t * 12, //WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
				eqt_index,
				GET_DIVIDEND_YIELD,
				EFFECTIVE_ANNUAL);
}



#line 1 "dth_claim_ann_rate_calc_aig.FIACARVM_LIAB.for"                                                                                   
double FIACARVM_LIAB::dth_claim_ann_rate_calc_aig(
	int t, int pol_yr, StrEnum::EnumValue mort_basis, StrEnum::EnumValue mort_gender_cv, int mort_issue_age_cv , int flex_flag ) //20210630 STW add parameter to indicate call from flex column
{

	/*******************************************************************
	 *  DTL 20200121: TFS 86514
	 *
	 *  Created new external to mimic previous outer loop refactor.
	 *******************************************************************/

	double mort_rate_life1 = 0.0;
	double mort_rate_life2 = 0.0;
	double mort_rate = 0.0;
	double mort_improvement = 1.0;

	//WTW - Gen2 - Mutating Lookup Term - This whole column need to be re-organized for mutating lookup keys to work
	// Set life1 lookup keys - special lookup keys are required for mortality variables
	/*mort_pol_yr = pol_yr;

	// 20190913 MTC - Made gender a required arg
	mort_gender = mort_gender_cv;	
	
	if (mort_issue_age_cv != -1)
	{
		mort_issue_age = mort_issue_age_cv;
	}
	else
	{
		if (mort_gender == MALE)
		{			
			mort_issue_age = fia->issue_age_male_aig;		
		}
		else if (mort_gender == FEMALE)
		{			
			mort_issue_age = fia->issue_age_female_aig;		
		}
		else if (mort_gender == BLENDED)
		{			
			mort_issue_age = fia->issue_age_mp;
		}
		else if (mort_gender == JOINT)
		{
			throw FatalError("`fiacarvm_liab->dth_claim_rate_calc_aig` was called with JOINT mort_gender_cv.  For Joint mortality rates, please use the dth_claim_rate_joint_*_aig columns.");
		}
		else
		{			
			throw FatalError("`fiacarvm_liab->dth_claim_rate_calc_aig`: mort_gender_cv must be MALE, FEMALE, or BLENDED.  Please check your call stack to fiacarvm_liab->dth_claim_rate_calc_aig.");		
		}	
	}	

	//change the mort_attained_age to locate mortality base, multiple and improvement percent
	mort_attained_age = mort_issue_age + pol_yr - 1;

	if (mort_gender == BLENDED)
	{
		mort_gender = MALE;
	}
		
	if (mort_basis == GMWB)
	{
		mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);
		mort_rate_life1 = max(0.0, min(1.0, gmwb_mort_base * mort_improvement));
	
		if (gender == BLENDED)
		{
			// Set life2 lookup keys
			// Life2 age is the same as for life1 for blended mortality
			mort_gender = FEMALE;
			mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);
		
			mort_rate_life2 = max(0.0, min(1.0, gmwb_mort_base * mort_improvement));
		}
	}
	else // mort_basis == EXPERIENCE
	{
		mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);
		mort_rate_life1
		= max(0.0, min(1.0, carvm_mort_base * mort_improvement * carvm_mort_mult ));

		if (gender == BLENDED)
		{
			// Set life2 lookup keys
			// Life2 age is the same as for life1 for blended mortality
			mort_gender = FEMALE;
			mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);

			mort_rate_life2
			= max(0.0, min(1.0, carvm_mort_base * mort_improvement * carvm_mort_mult));
		}			
	}

	if (gender == BLENDED)
	{
		mort_rate = fia->male_sex_pct * mort_rate_life1
				+ (1.0 - fia->male_sex_pct) * mort_rate_life2;
	}
	else
	{
		mort_rate = mort_rate_life1;
	}

	if (t == 1)
	{
		mort_rate = 1.0 - pow(1.0 - mort_rate, mths_in_first_year / 12.0);
	}

	return mort_rate;*/
	
	// Set life1 lookup keys - special lookup keys are required for mortality variables
	mort_pol_yr = pol_yr;
	
	mort_gender = mort_gender_cv;	
	
	if (mort_issue_age_cv != -1)
	{
		mort_issue_age = mort_issue_age_cv;
	}
	else
	{
		if (mort_gender == MALE)
		{			
			mort_issue_age = fia->issue_age_male_aig;		
		}
		else if (mort_gender == FEMALE)
		{			
			mort_issue_age = fia->issue_age_female_aig;		
		}
		else if (mort_gender == BLENDED)
		{			
			mort_issue_age = fia->issue_age_mp;
		}
		else if (mort_gender == JOINT)
		{
			throw FatalError("`fiacarvm_liab->dth_claim_rate_calc_aig` was called with JOINT mort_gender_cv.  For Joint mortality rates, please use the dth_claim_rate_joint_*_aig columns.");
		}
		else
		{			
			throw FatalError("`fiacarvm_liab->dth_claim_rate_calc_aig`: mort_gender_cv must be MALE, FEMALE, or BLENDED.  Please check your call stack to fiacarvm_liab->dth_claim_rate_calc_aig.");		
		}	
	}	

	//change the mort_attained_age to locate mortality base, multiple and improvement percent
	mort_attained_age = mort_issue_age + pol_yr - 1;

	if (mort_gender == BLENDED)
	{
		mort_gender = MALE;
	}
	
	double mort_base_local = 0.0;
	double mort_mult_local = 0.0;

	if (mort_basis == GMWB)
	{
		if (mort_issue_age_cv != -1)
		{
			if (gender == BLENDED)
			{
			mort_issue_age = mort_issue_age_cv;
			mort_pol_yr = pol_yr;
			mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);
			mort_gender = MALE;	
			mort_attained_age = mort_issue_age + pol_yr - 1;
			mort_rate_life1 = max(0.0, min(1.0, gmwb_mort_base * mort_improvement));
			
			mort_issue_age = mort_issue_age_cv;
			mort_pol_yr = pol_yr;
			mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);
			mort_gender = FEMALE;	
			mort_attained_age = mort_issue_age + pol_yr - 1;
			mort_rate_life2 = max(0.0, min(1.0, gmwb_mort_base * mort_improvement));
			}
			else
			{			
			mort_issue_age = mort_issue_age_cv;
			mort_pol_yr = pol_yr;
			mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);
			mort_gender = mort_gender_cv;	
			mort_attained_age = mort_issue_age + pol_yr - 1;
			mort_rate_life1 = max(0.0, min(1.0, gmwb_mort_base * mort_improvement));
			}

		}
		else
		{
			if (mort_gender_cv == MALE)
			{			
				mort_issue_age = fia->issue_age_male_aig;
				mort_pol_yr = pol_yr;
				mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);
				mort_gender = MALE;	
				mort_attained_age = mort_issue_age + pol_yr - 1;
				mort_rate_life1 = max(0.0, min(1.0, gmwb_mort_base * mort_improvement));		
			}
			else if (mort_gender_cv == FEMALE)
			{			
				mort_issue_age = fia->issue_age_female_aig;	
				mort_pol_yr = pol_yr;
				mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);
				mort_gender = FEMALE;	
				mort_attained_age = mort_issue_age + pol_yr - 1;
				mort_rate_life1 = max(0.0, min(1.0, gmwb_mort_base * mort_improvement));
				
			}
			else if (mort_gender_cv == BLENDED)
			{			
				mort_issue_age = fia->issue_age_mp;
				mort_pol_yr = pol_yr;
				mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);
				mort_gender = MALE;	
				mort_attained_age = mort_issue_age + pol_yr - 1;
				mort_rate_life1 = max(0.0, min(1.0, gmwb_mort_base * mort_improvement));
			
				mort_issue_age = fia->issue_age_mp;
				mort_pol_yr = pol_yr;
				mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);
				mort_gender = FEMALE;	
				mort_attained_age = mort_issue_age + pol_yr - 1;
				mort_rate_life2 = max(0.0, min(1.0, gmwb_mort_base * mort_improvement));
			}
			else if (mort_gender_cv == JOINT)
			{
				throw FatalError("`fiacarvm_liab->dth_claim_rate_calc_aig` was called with JOINT mort_gender_cv.  For Joint mortality rates, please use the dth_claim_rate_joint_*_aig columns.");
			}
			else
			{			
				throw FatalError("`fiacarvm_liab->dth_claim_rate_calc_aig`: mort_gender_cv must be MALE, FEMALE, or BLENDED.  Please check your call stack to fiacarvm_liab->dth_claim_rate_calc_aig.");		
			}	
		}	

	}
	else // mort_basis == EXPERIENCE
	{
		if (mort_issue_age_cv != -1)
		{
			if (mort_gender == BLENDED)
			{
			mort_issue_age = mort_issue_age_cv;
			mort_pol_yr = pol_yr;
			mort_gender = MALE;	
			mort_attained_age = mort_issue_age + pol_yr - 1;
			mort_base_local = carvm_mort_base;

			mort_issue_age = mort_issue_age_cv;
			mort_gender = MALE;	
			mort_pol_yr = pol_yr;
			mort_mult_local = carvm_mort_mult;
			mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);

			mort_rate_life1 = max(0.0, min(1.0, mort_base_local * mort_improvement * mort_mult_local));
			
			mort_issue_age = mort_issue_age_cv;
			mort_pol_yr = pol_yr;
			mort_gender = FEMALE;	
			mort_attained_age = mort_issue_age + pol_yr - 1;
			mort_base_local = carvm_mort_base;

			mort_issue_age = mort_issue_age_cv;
			mort_gender = FEMALE;	
			mort_pol_yr = pol_yr;
			mort_mult_local = carvm_mort_mult;
			mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);
			
			mort_rate_life2 = max(0.0, min(1.0, mort_base_local * mort_improvement * mort_mult_local));
			}
			else
			{			
			mort_issue_age = mort_issue_age_cv;
			mort_pol_yr = pol_yr;
			mort_gender = mort_gender_cv;	
			mort_attained_age = mort_issue_age + pol_yr - 1;
			mort_base_local = carvm_mort_base;

			mort_issue_age = mort_issue_age_cv;
			mort_gender = mort_gender_cv;	
			mort_pol_yr = pol_yr;
			mort_mult_local = carvm_mort_mult;
			mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);

			mort_rate_life1 = max(0.0, min(1.0, mort_base_local * mort_improvement * mort_mult_local));
			}

		}
		else
		{
			if (mort_gender_cv == MALE)
			{			
				mort_issue_age = fia->issue_age_male_aig;
				mort_pol_yr = pol_yr;
				mort_gender = MALE;	
				mort_attained_age = mort_issue_age + pol_yr - 1;
				mort_base_local = carvm_mort_base;
				
				mort_issue_age = fia->issue_age_male_aig;
				mort_gender = MALE;	
				mort_pol_yr = pol_yr;
				mort_mult_local = carvm_mort_mult;
				mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);

				mort_rate_life1 = max(0.0, min(1.0, mort_base_local * mort_improvement * mort_mult_local));		
			}
			else if (mort_gender_cv == FEMALE)
			{			
				mort_issue_age = fia->issue_age_female_aig;	
				mort_pol_yr = pol_yr;
				mort_gender = FEMALE;	
				mort_attained_age = mort_issue_age + pol_yr - 1;
				mort_base_local = carvm_mort_base;
				
				mort_issue_age = fia->issue_age_female_aig;
				mort_gender = FEMALE;	
				mort_pol_yr = pol_yr;
				mort_mult_local = carvm_mort_mult;
				mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);

				mort_rate_life1 = max(0.0, min(1.0, mort_base_local * mort_improvement * mort_mult_local));			
			}
			else if (mort_gender_cv == BLENDED)
			{			
				mort_issue_age = fia->issue_age_mp;
				mort_pol_yr = pol_yr;
				mort_gender = MALE;	
				mort_attained_age = mort_issue_age + pol_yr - 1;
				mort_base_local = carvm_mort_base;
				
				mort_issue_age = fia->issue_age_mp;
				mort_gender = MALE;	
				mort_pol_yr = pol_yr;
				mort_mult_local = carvm_mort_mult;
				mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);

				mort_rate_life1 = max(0.0, min(1.0, mort_base_local * mort_improvement * mort_mult_local));
			
				mort_issue_age = fia->issue_age_mp;
				mort_pol_yr = pol_yr;
				mort_gender = FEMALE;	
				mort_attained_age = mort_issue_age + pol_yr - 1;
				mort_base_local = carvm_mort_base;
				
				mort_issue_age = fia->issue_age_mp;
				mort_gender = FEMALE;	
				mort_pol_yr = pol_yr;
				mort_mult_local = carvm_mort_mult;
				mort_improvement = mort_improve_mult_aig(mort_attained_age, mort_gender, pol_yr, GMWB, flex_flag);

				mort_rate_life2 = max(0.0, min(1.0, mort_base_local * mort_improvement * mort_mult_local));
			}
			else if (mort_gender_cv == JOINT)
			{
				throw FatalError("`fiacarvm_liab->dth_claim_rate_calc_aig` was called with JOINT mort_gender_cv.  For Joint mortality rates, please use the dth_claim_rate_joint_*_aig columns.");
			}
			else
			{			
				throw FatalError("`fiacarvm_liab->dth_claim_rate_calc_aig`: mort_gender_cv must be MALE, FEMALE, or BLENDED.  Please check your call stack to fiacarvm_liab->dth_claim_rate_calc_aig.");		
			}	
		}	
	}

	if (gender == BLENDED)
	{
		mort_rate = fia->male_sex_pct * mort_rate_life1
				+ (1.0 - fia->male_sex_pct) * mort_rate_life2;
	}
	else
	{
		mort_rate = mort_rate_life1;
	}

	if (t == 1)
	{
		mort_rate = 1.0 - pow(1.0 - mort_rate, mths_in_first_year / 12.0);
	}
	
	return mort_rate;
}



#line 1 "dth_claim_mthly_rate_calc_aig.FIACARVM_LIAB.for"                                                                                   
double FIACARVM_LIAB::dth_claim_mthly_rate_calc_aig(
	int pol_mth, StrEnum::EnumValue mort_basis, StrEnum::EnumValue mort_gender_cv, int mort_issue_age_cv )
{
	double mort_rate_life1	= 0.0;
	double mort_rate_life2	= 0.0;
	double mort_rate		= 0.0;

	//WTW - Gen2 - Mutating Lookup Term - This whole column need to be re-organized for mutating lookup keys to work
	/*mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
	mort_gender = mort_gender_cv;	
	
	if (mort_issue_age_cv != -1)
	{
		mort_issue_age = mort_issue_age_cv;
	}
	else
	{
		if (mort_gender == MALE)
		{			
			mort_issue_age = fia->issue_age_male_aig;		
		}
		else if (mort_gender == FEMALE)
		{			
			mort_issue_age = fia->issue_age_female_aig;		
		}
		else if (mort_gender == BLENDED)
		{			
			mort_issue_age = fia->issue_age_mp;
		}
		else if (mort_gender == JOINT)
		{
			throw FatalError("`fiacarvm_liab->dth_claim_mthly_rate_calc_aig` was called with JOINT mort_gender_cv.  For Joint mortality rates, please use the dth_claim_rate_joint_*_aig columns.");
		}
		else
		{			
			throw FatalError("`fiacarvm_liab->dth_claim_mthly_rate_calc_aig`: mort_gender_cv must be MALE, FEMALE, or BLENDED.  Please check your call stack to fiacarvm_liab->dth_claim_mthly_rate_calc_aig.");		
		}	
	}	

	mort_attained_age = mort_issue_age + mort_pol_yr - 1;

	if (mort_gender == BLENDED)
	{
		mort_gender = MALE;
	}
		
	if (mort_basis == GMWB)
	{
		mort_rate_life1 = max(0.0, min(1.0, gmwb_mort_base));
		mort_rate_life1 = 1.0 - pow(1.0 - mort_rate_life1, 1.0/12.0);
	
		if (gender == BLENDED)
		{
			mort_gender = FEMALE;
			mort_rate_life2 = max(0.0, min(1.0, gmwb_mort_base));
			mort_rate_life2 = 1.0 - pow(1.0 - mort_rate_life2, 1.0/12.0);
		}
	}
	else // mort_basis == EXPERIENCE
	{
		mort_rate_life1 = max(0.0, min(1.0, carvm_mort_base * carvm_mort_mult ));
		mort_rate_life1 = 1.0 - pow(1.0 - mort_rate_life1, 1.0/12.0);

		if (gender == BLENDED)
		{
			mort_gender = FEMALE;
			mort_rate_life2 = max(0.0, min(1.0, carvm_mort_base * carvm_mort_mult));
			mort_rate_life2 = 1.0 - pow(1.0 - mort_rate_life2, 1.0/12.0);
		}			
	}

	if (gender == BLENDED)
	{
		mort_rate = fia->male_sex_pct * mort_rate_life1 + (1.0 - fia->male_sex_pct) * mort_rate_life2;
	}
	else
	{
		mort_rate = mort_rate_life1;
	}

	return mort_rate;*/

	mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
	mort_gender = mort_gender_cv;	
	mort_attained_age = mort_issue_age + mort_pol_yr - 1;
	double mort_base_local = 0.0;
	
	if (mort_basis == GMWB)
	{
		if (mort_issue_age_cv != -1)
		{
			mort_issue_age = mort_issue_age_cv;
			mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
			mort_gender = mort_gender_cv;	
			mort_attained_age = mort_issue_age + mort_pol_yr - 1;
			mort_rate_life1 = max(0.0, min(1.0, gmwb_mort_base));
			mort_rate_life1 = 1.0 - pow(1.0 - mort_rate_life1, 1.0/12.0);
	
			if (gender == BLENDED)
			{
				mort_issue_age = mort_issue_age_cv;
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = MALE;	
				mort_attained_age = mort_issue_age + mort_pol_yr - 1;
				mort_rate_life1 = max(0.0, min(1.0, gmwb_mort_base));
				mort_rate_life1 = 1.0 - pow(1.0 - mort_rate_life1, 1.0/12.0);

				mort_issue_age = mort_issue_age_cv;
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = FEMALE;	
				mort_attained_age = mort_issue_age + mort_pol_yr - 1;
				mort_rate_life2 = max(0.0, min(1.0, gmwb_mort_base));
				mort_rate_life2 = 1.0 - pow(1.0 - mort_rate_life2, 1.0/12.0);
			}
		}
		else
		{
			if (mort_gender == MALE)
			{			
				mort_issue_age = fia->issue_age_male_aig;	
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = MALE;	
				mort_attained_age = mort_issue_age + mort_pol_yr - 1;
				mort_rate_life1 = max(0.0, min(1.0, gmwb_mort_base));
				mort_rate_life1 = 1.0 - pow(1.0 - mort_rate_life1, 1.0/12.0);
			}
			else if (mort_gender == FEMALE)
			{			
				mort_issue_age = fia->issue_age_female_aig;		
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = FEMALE;	
				mort_attained_age = mort_issue_age + mort_pol_yr - 1;
				mort_rate_life1 = max(0.0, min(1.0, gmwb_mort_base));
				mort_rate_life1 = 1.0 - pow(1.0 - mort_rate_life1, 1.0/12.0);
			}
			else if (mort_gender == BLENDED)
			{			
				mort_issue_age = fia->issue_age_mp;
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = MALE;	
				mort_attained_age = mort_issue_age + mort_pol_yr - 1;
				mort_rate_life1 = max(0.0, min(1.0, gmwb_mort_base));
				mort_rate_life1 = 1.0 - pow(1.0 - mort_rate_life1, 1.0/12.0);

				mort_issue_age = fia->issue_age_mp;
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = FEMALE;	
				mort_attained_age = mort_issue_age + mort_pol_yr - 1;
				mort_rate_life2 = max(0.0, min(1.0, gmwb_mort_base));
				mort_rate_life2 = 1.0 - pow(1.0 - mort_rate_life2, 1.0/12.0);
			}
			else if (mort_gender == JOINT)
			{
				throw FatalError("`fiacarvm_liab->dth_claim_mthly_rate_calc_aig` was called with JOINT mort_gender_cv.  For Joint mortality rates, please use the dth_claim_rate_joint_*_aig columns.");
			}
			else
			{			
				throw FatalError("`fiacarvm_liab->dth_claim_mthly_rate_calc_aig`: mort_gender_cv must be MALE, FEMALE, or BLENDED.  Please check your call stack to fiacarvm_liab->dth_claim_mthly_rate_calc_aig.");		
			}	
		}	
	}
	else // mort_basis == EXPERIENCE
	{
		if (mort_issue_age_cv != -1)
		{
			mort_issue_age = mort_issue_age_cv;
			mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
			mort_gender = mort_gender_cv;	
			mort_attained_age = mort_issue_age + mort_pol_yr - 1;
			mort_base_local = carvm_mort_base;

			mort_issue_age = mort_issue_age_cv;
			mort_gender = mort_gender_cv;	
			mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
			mort_rate_life1 = max(0.0, min(1.0, mort_base_local * carvm_mort_mult));
			mort_rate_life1 = 1.0 - pow(1.0 - mort_rate_life1, 1.0/12.0);
	
			if (gender == BLENDED)
			{
				mort_issue_age = mort_issue_age_cv;
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = MALE;	
				mort_attained_age = mort_issue_age + mort_pol_yr - 1;
				mort_base_local = carvm_mort_base;

				mort_issue_age = mort_issue_age_cv;
				mort_gender = MALE;	
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_rate_life1 = max(0.0, min(1.0, mort_base_local * carvm_mort_mult));
				mort_rate_life1 = 1.0 - pow(1.0 - mort_rate_life1, 1.0/12.0);

				mort_issue_age = mort_issue_age_cv;
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = FEMALE;	
				mort_attained_age = mort_issue_age + mort_pol_yr - 1;
				mort_base_local = carvm_mort_base;

				mort_issue_age = mort_issue_age_cv;
				mort_gender = FEMALE;	
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_rate_life2 = max(0.0, min(1.0, mort_base_local * carvm_mort_mult));
				mort_rate_life2 = 1.0 - pow(1.0 - mort_rate_life2, 1.0/12.0);
			}
		}
		else
		{
			if (mort_gender == MALE)
			{			
				mort_issue_age = fia->issue_age_male_aig;	
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = MALE;	
				mort_attained_age = mort_issue_age + mort_pol_yr - 1;
				mort_base_local = carvm_mort_base;

				mort_issue_age = fia->issue_age_male_aig;	
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = MALE;	
				mort_rate_life1 = max(0.0, min(1.0, mort_base_local * carvm_mort_mult));
				mort_rate_life1 = 1.0 - pow(1.0 - mort_rate_life1, 1.0/12.0);
			}
			else if (mort_gender == FEMALE)
			{			
				mort_issue_age = fia->issue_age_female_aig;		
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = FEMALE;	
				mort_attained_age = mort_issue_age + mort_pol_yr - 1;
				mort_base_local = carvm_mort_base;

				mort_issue_age = fia->issue_age_female_aig;		
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = FEMALE;	
				mort_rate_life1 = max(0.0, min(1.0, mort_base_local * carvm_mort_mult));
				mort_rate_life1 = 1.0 - pow(1.0 - mort_rate_life1, 1.0/12.0);
			}
			else if (mort_gender == BLENDED)
			{			
				mort_issue_age = fia->issue_age_mp;
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = MALE;	
				mort_attained_age = mort_issue_age + mort_pol_yr - 1;
				mort_base_local = carvm_mort_base;

				mort_issue_age = fia->issue_age_mp;
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = MALE;	
				mort_rate_life1 = max(0.0, min(1.0, mort_base_local * carvm_mort_mult));
				mort_rate_life1 = 1.0 - pow(1.0 - mort_rate_life1, 1.0/12.0);

				mort_issue_age = fia->issue_age_mp;
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = FEMALE;	
				mort_attained_age = mort_issue_age + mort_pol_yr - 1;
				mort_base_local = carvm_mort_base;

				mort_issue_age = fia->issue_age_mp;
				mort_pol_yr = int((double(pol_mth) - 1.0) / 12.0) + 1;
				mort_gender = FEMALE;	
				mort_rate_life2 = max(0.0, min(1.0, mort_base_local * carvm_mort_mult));
				mort_rate_life2 = 1.0 - pow(1.0 - mort_rate_life2, 1.0/12.0);
			}
			else if (mort_gender == JOINT)
			{
				throw FatalError("`fiacarvm_liab->dth_claim_mthly_rate_calc_aig` was called with JOINT mort_gender_cv.  For Joint mortality rates, please use the dth_claim_rate_joint_*_aig columns.");
			}
			else
			{			
				throw FatalError("`fiacarvm_liab->dth_claim_mthly_rate_calc_aig`: mort_gender_cv must be MALE, FEMALE, or BLENDED.  Please check your call stack to fiacarvm_liab->dth_claim_mthly_rate_calc_aig.");		
			}	
		}	
	}

	if (gender == BLENDED)
	{
		mort_rate = fia->male_sex_pct * mort_rate_life1 + (1.0 - fia->male_sex_pct) * mort_rate_life2;
	}
	else
	{
		mort_rate = mort_rate_life1;
	}

	return mort_rate;

}



#line 1 "glb_flex_ann_annuity_factor_aig.FIACARVM_LIAB.for"                                                                                   
vector<double> FIACARVM_LIAB::glb_flex_ann_annuity_factor_aig(
	int t, StrEnum::EnumValue mort_basis, int issue_age_male_cv, int issue_age_female_cv)
{
	double qx_m, px_m, qy_m, py_m;
	double qx_f, px_f, qy_f, py_f;
	double lx_m, lx_f;
	double lx_j, ly_j, lxy_j, lxy_bar_j;

	lx_m  = 1.0;
	lx_f  = 1.0;

	lxy_j = 1.0;
	lx_j  = 0.0;
	ly_j  = 0.0;

	lxy_bar_j = lx_j + ly_j + lxy_j;

	//WTW - Gen2 - Mutating Lookup Term - move lookup keys under each stat/tax conditional
	double int_rate = 0.0;
	if (model_name_gen2 == "STAT"/*this == fia_carvm_stat*/)//WTW - Gen2 - comparison of distinct pointers error
	{
		valn_carvm_defn			= fia->stat_carvm_defn;
		valn_cash_settle_defn	= fia->valn_rate_cash_settle_defn;
		valn_int_guar_defn		= fia->valn_rate_int_guar_defn;
		valn_guar_dur			= int_guar_dur;
		valn_plan_type			= fia->valn_rate_plan_type_elective_cash_val;	
		valn_issue_yr				= fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
		int_rate				= carvm_int_rate;	//WTW - Gen2 - Mutating Lookup Term
	}
	else
	{
		valn_carvm_defn			= fia->tax_carvm_defn;
		valn_cash_settle_defn	= fia->valn_rate_cash_settle_defn;
		valn_int_guar_defn		= fia->valn_rate_int_guar_defn;
		valn_guar_dur			= int_guar_dur;
		valn_plan_type			= fia->valn_rate_plan_type_elective_cash_val;	
		valn_issue_yr				= fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
		int_rate				= carvm_int_rate;	//WTW - Gen2 - Mutating Lookup Term
	}

	/*valn_cash_settle_defn	= fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn		= fia->valn_rate_int_guar_defn;
	valn_guar_dur			= int_guar_dur;
	valn_plan_type			= fia->valn_rate_plan_type_elective_cash_val;*/

	int duration			= 0;
	double discount_factor	= 1.0;
	double annuity_factor_m  = 1.0;
	double annuity_factor_f  = 1.0;
	double annuity_factor_j  = 1.0;
	while (lxy_bar_j > SMALL_DOUBLE)
	{
		int pol_yr_cv			= pol_yr(t + duration);

		//double int_rate			= carvm_int_rate;//WTW - Gen2 - Mutating Lookup Term
		double disc_fac_per		= 1.0 / (1.0 + int_rate);

		if (t + duration == 1)
		{
			disc_fac_per = pow(disc_fac_per, mths_in_first_year / 12.0);
		}

		discount_factor *= disc_fac_per;

		qx_m = dth_claim_ann_rate_calc_aig(t + duration, pol_yr_cv, mort_basis, MALE, issue_age_male_cv, 1);

		px_m = 1.0 - qx_m;

		qx_f = dth_claim_ann_rate_calc_aig(t + duration, pol_yr_cv, mort_basis, FEMALE, issue_age_female_cv, 1);

		px_f = 1.0 - qx_f;

		lx_m       = lx_m * px_m;
		lx_f       = lx_f * px_f;

		lx_j       = lx_j * px_m + lxy_j * px_m * qx_f;
		ly_j       = ly_j * px_f + lxy_j * px_f * qx_m;
		lxy_j     *= px_m * px_f;
		lxy_bar_j  = lxy_j + lx_j + ly_j;

		annuity_factor_m += lx_m * discount_factor;
		annuity_factor_f += lx_f * discount_factor;
		annuity_factor_j += lxy_bar_j * discount_factor;

		duration++;
	}

	vector<double> annuity_factor_list;

	annuity_factor_list.push_back(annuity_factor_m);
	annuity_factor_list.push_back(annuity_factor_f);
	annuity_factor_list.push_back(annuity_factor_j);

	return annuity_factor_list;
}



#line 1 "glb_flex_mthly_annuity_factor_aig.FIACARVM_LIAB.for"                                                                                   
vector<double> FIACARVM_LIAB::glb_flex_mthly_annuity_factor_aig(
	int pol_mth, StrEnum::EnumValue mort_basis, int issue_age_male_cv, int issue_age_female_cv)
{
	double qx_m, px_m, qy_m, py_m;
	double qx_f, px_f, qy_f, py_f;
	double lx_m, lx_f;
	double lx_j, ly_j, lxy_j, lxy_bar_j;

	lx_m  = 1.0;
	lx_f  = 1.0;

	lxy_j = 1.0;
	lx_j  = 0.0;
	ly_j  = 0.0;

	lxy_bar_j = lx_j + ly_j + lxy_j;

	//WTW - Gen2 - Mutating Lookup Term - move lookup keys under each stat/tax conditional
	double int_rate = 0.0;
	if (model_name_gen2 == "STAT"/*this == fia_carvm_stat*/)//WTW - Gen2 - comparison of distinct pointers error
	{
		valn_carvm_defn			= fia->stat_carvm_defn;
		valn_cash_settle_defn	= fia->valn_rate_cash_settle_defn;
		valn_int_guar_defn		= fia->valn_rate_int_guar_defn;
		valn_guar_dur			= int_guar_dur;
		valn_plan_type			= fia->valn_rate_plan_type_elective_cash_val;	
		valn_issue_yr				= fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
		int_rate				= carvm_int_rate;	//WTW - Gen2 - Mutating Lookup Term
	}
	else
	{
		valn_carvm_defn			= fia->tax_carvm_defn;
		valn_cash_settle_defn	= fia->valn_rate_cash_settle_defn;
		valn_int_guar_defn		= fia->valn_rate_int_guar_defn;
		valn_guar_dur			= int_guar_dur;
		valn_plan_type			= fia->valn_rate_plan_type_elective_cash_val;	
		valn_issue_yr				= fia->issue_yr;//WTW - Gen2 - Mutating Lookup Term
		int_rate				= carvm_int_rate;	//WTW - Gen2 - Mutating Lookup Term
	}

	/*valn_cash_settle_defn	= fia->valn_rate_cash_settle_defn;
	valn_int_guar_defn		= fia->valn_rate_int_guar_defn;
	valn_guar_dur			= int_guar_dur;
	valn_plan_type			= fia->valn_rate_plan_type_elective_cash_val;*/

	int duration			= 0;
	double discount_factor	= 1.0;
	double cashflow			= 1.0/12.0;
	double annuity_factor_m  = cashflow;
	double annuity_factor_f  = cashflow;
	double annuity_factor_j  = cashflow;
	while (lxy_bar_j > SMALL_DOUBLE)
	{
		//double int_rate			= carvm_int_rate; //WTW - Gen2 - Mutating Lookup Term
		double disc_fac_per		= 1.0 / pow(1.0 + int_rate, 1.0/12.0);

		discount_factor *= disc_fac_per;

		qx_m = dth_claim_mthly_rate_calc_aig(pol_mth + duration, mort_basis, MALE, issue_age_male_cv);

		px_m = 1.0 - qx_m;

		qx_f = dth_claim_mthly_rate_calc_aig(pol_mth + duration, mort_basis, FEMALE, issue_age_female_cv);

		px_f = 1.0 - qx_f;

		lx_m       = lx_m * px_m;
		lx_f       = lx_f * px_f;

		lx_j       = lx_j * px_m + lxy_j * px_m * qx_f;
		ly_j       = ly_j * px_f + lxy_j * px_f * qx_m;
		lxy_j     *= px_m * px_f;
		lxy_bar_j  = lxy_j + lx_j + ly_j;

		annuity_factor_m += cashflow * lx_m * discount_factor;
		annuity_factor_f += cashflow * lx_f * discount_factor;
		annuity_factor_j += cashflow * lxy_bar_j * discount_factor;

		duration++;
	}

	vector<double> annuity_factor_list;

	annuity_factor_list.push_back(annuity_factor_m);
	annuity_factor_list.push_back(annuity_factor_f);
	annuity_factor_list.push_back(annuity_factor_j);

	return annuity_factor_list;
}



#line 1 "gmwb_ann_benefits_mort_rate_calc_aig.FIACARVM_LIAB.for"                                                                                   
void FIACARVM_LIAB::gmwb_ann_benefits_mort_rate_calc_aig(
	const int& t, const int& current_year, StrEnum::EnumValue mort_basis,
	double& lxy, double& lx, double& ly, double& lxy_bar)
{
	/*******************************************************************
	 *  DTL 20200121: TFS 86514
	 *
	 *  Created new column to copy over some logic from fia_liab to
	 *  here.
	 *******************************************************************/

	double qx, px, qy, py;
	double lxy_bar_bef = lxy_bar;

	qx = dth_claim_ann_rate_calc_aig(t, current_year, mort_basis, MALE);
	px = 1.0 - qx;
	qy = dth_claim_ann_rate_calc_aig(t, current_year, mort_basis, FEMALE);
	py = 1.0 - qy;

	lx       = lx * px + lxy * px * qy;
	ly       = ly * py + lxy * py * qx;
	lxy     *= px * py;
	lxy_bar  = lxy + lx + ly;

	double dxy_bar = lxy_bar_bef - lxy_bar;
}



#line 1 "gmwb_confinement_mawp_adj_aig.FIACARVM_LIAB.for"                                                                                   
double FIACARVM_LIAB::gmwb_confinement_mawp_adj_aig(int withdrawal_yr, int pol_yr, int remaining_yrs, StrEnum::EnumValue gender_cv)
{
	/*******************************************************************
	 *  SJ 20221110:
	 *
	 *  Created new function to calculate confinement adjusted MAWP factor
	 *******************************************************************/

	if (enhanced_income_defn_aig == NO)
	{
		return 1.0;
	}

	double prob_confined = 0;
	double prob_total_confined = 0;
	double prob_not_confined = 1;
	double prob_enhanced_income = 0;

	for (int current_yr = withdrawal_yr; current_yr <= pol_yr; current_yr++)
	{
		double incidence_rate;

		if (gender_cv == FEMALE || gender_cv == MALE)
		{
			fia->enhanced_income_incidence_gender_aig			= gender_cv;
			fia->enhanced_income_incidence_issue_age_aig		= issue_age_aig;
			fia->enhanced_income_incidence_pol_yr_aig			= current_yr;
			incidence_rate										= fia->enhanced_income_incidence_base_aig;
		}
		else
		{
			fia->enhanced_income_incidence_gender_aig			= MALE;
			fia->enhanced_income_incidence_issue_age_aig		= fia->issue_age_male_aig;
			fia->enhanced_income_incidence_pol_yr_aig			= current_yr;
			double incidence_rate_male							= fia->enhanced_income_incidence_base_aig;

			fia->enhanced_income_incidence_gender_aig			= FEMALE;
			fia->enhanced_income_incidence_issue_age_aig		= fia->issue_age_female_aig;
			fia->enhanced_income_incidence_pol_yr_aig			= current_yr;
			double incidence_rate_female						= fia->enhanced_income_incidence_base_aig;

			incidence_rate										= max (incidence_rate_male, incidence_rate_female);
		}
		
		prob_confined = prob_not_confined * incidence_rate;
		prob_total_confined += prob_confined;
		prob_not_confined = 1 - prob_total_confined;

		if (current_yr > max(0, pol_yr - remaining_yrs))
		{
			prob_enhanced_income += prob_confined;
		}
	}
	
	fia->temp_key_cov_person_status	= fia->covered_person_status_aig;//Gen2: Mutating Lookup
	double enhanced_income_mawp_mult = fia->enhanced_income_mawp_mult_aig;
	double mawp_adj = prob_enhanced_income * enhanced_income_mawp_mult + (1 - prob_enhanced_income);

	return mawp_adj;
}



#line 1 "mort_improve_mult_aig.FIACARVM_LIAB.for"                                                                                   
double FIACARVM_LIAB::mort_improve_mult_aig(int att_age, StrEnum::EnumValue gender_local, int projection_year, StrEnum::EnumValue mort_basis_cv, int flex_flag)
{
	/*******************************************************************
	 *  DTL 20200121: TFS 86514
	 *
	 *  New external that copies outer loop logic more or less.
	 *******************************************************************/

	if(flex_flag)		//20210630 STW: does not apply mortality improvement factor in flex calculation
	{
		return 1.0;
	}

	double  mths_elapsed_in_yr;
	double  n;
	double  cumul_mort_improve;
	xstring start_date;
	xstring end_date;

	/*
	mths_elapsed_in_yr = 0.0;
	if (projection_year == 1)
	{
		mths_elapsed_in_yr = 12.0 - mths_in_first_year;
	}


	DTL 20200311 (START): MQ has directed the following:
		(1) Hold `mths_elapsed_in_yr` constant in inner loop and do nothing special for inner loop year 1
		(2) Set `mths_elapsed_in_yr` to 1 for `res_period`=1, else set it to 12

		CAUTION: commented this out again on 20200626 DTL per MQ's instructions

	mths_elapsed_in_yr = 12.0;
	if (res_period == 1)
	{
		mths_elapsed_in_yr = 12.0 - mths_in_first_year;
	}
	*/
	// DTL 20200311 (END):

	double mort_improve_pct_cv;
	if ( mort_basis_cv == GMWB )
	{
		mort_attained_age = att_age;//WTW - Gen2 - Mutating Lookup Term
		mort_gender = gender_local;//WTW - Gen2 - Mutating Lookup Term
		mort_improve_pct_cv = gmwb_mort_improve_pct_aig;
	}
	else
	{
		mort_attained_age = att_age;//WTW - Gen2 - Mutating Lookup Term
		mort_gender = gender_local;//WTW - Gen2 - Mutating Lookup Term
		mort_improve_pct_cv = carvm_mort_improve_pct_aig;
	}

	//start_date = fia->mort_improve_base_date_aig;
	start_date = this->mort_improve_base_date_aig;
	end_date   = fia->issue_date_mp;
	n          = fia->time_between_dates_calc_aig(start_date, end_date) + (projection_year - 1.0); // + mths_elapsed_in_yr / 12.0;

	cumul_mort_improve = pow ((1 - mort_improve_pct_cv), n);

	return cumul_mort_improve;
}



#line 1 "risk_free_rate.FIACARVM_LIAB.for"                                                                                   
double FIACARVM_LIAB::risk_free_rate(int t, double tte)
{
if (t < 0 || t > max_calc_period)
	return 0.0;//NO_AVG;//WTW - Gen2 - IncorrectUsage of NoAvg

int fwd_term = xint((12 - mths_in_first_year) / 12.0);

if (t == 0) 
	{
	if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
		return fia_rates->get_int_rate(fia->res_period,//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
						"Govt",
						GET_FORWARD_RATE,
						tte,
						fwd_term,
						NOMINAL_SEMIANNUAL,
						NO_SHIFT,0); //shift_defn //AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	
	return rates->get_int_rate(fia->res_period,//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
					"Govt",
					GET_FORWARD_RATE,
					tte,
					fwd_term,
					NOMINAL_SEMIANNUAL,
					NO_SHIFT,0); //shift_defn //AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	}

if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
	return fia_rates->get_int_rate(fia->res_period,//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
					"Govt",
					GET_FORWARD_RATE,
					tte,
					1.0, // foward term
					NOMINAL_SEMIANNUAL,
					NO_SHIFT,0); //shift_defn //AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

return rates->get_int_rate(fia->res_period,//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
				"Govt",
				GET_FORWARD_RATE,
				tte,
				1.0, // foward term
				NOMINAL_SEMIANNUAL,
				NO_SHIFT,0); //shift_defn //AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
}



#line 1 "set_hidden_variables.FIACARVM_LIAB.for"                                                                                   
void FIACARVM_LIAB::set_hidden_variables(int policy_month)
{
	plan_code			= fia->plan_code;

	double gender_code	= fia->gender_col_e_bef_aig(policy_month);
	gender				= fia->gender_get_enum_value_aig(gender_code);
	issue_age_aig		= fia->issue_age_col_e_bef_aig(policy_month);
	valn_issue_yr			= fia->issue_yr;

	//20230127 SJ: Add a swith to only calculate base stat res for FIA XOL Deal. Turn off GMWB path, and no GMWB fee assessed.
	calc_base_res_only_aig = fia->calc_base_res_only_aig;  
	pfwd_model_switch_aig = fia->pfwd_model_carvm_aig;
	//20230127 SJ END

	gmwb_wdl_proj_yr_aig = -1;

	if (fia->gmwb_flag)
	{
		gmwb_exercise_point = fia->gmwb_exercise_point;

		if (fia->pol_yr(policy_month + 1) <= fia->gmwb_req_yrs_wait + fia->gmwb_exercise_yrs_aig(policy_month)) //20221110 SJ: change gmwb_exercise_yrs to column for confinement dynamic exercise
		{
			int remaining_required_wait =
				max(0, fia->gmwb_req_yrs_wait - fia->pol_yr(policy_month + 1) + 1.0 - gmwb_exercise_point);

			gmwb_wait_period_aig = fia->pol_yr(policy_month + 1) - 1.0
				+ gmwb_exercise_point + remaining_required_wait;
		}
		else
		{
			gmwb_wait_period_aig = fia->gmwb_req_yrs_wait + fia->gmwb_exercise_yrs_aig(policy_month); //20221110 SJ: change gmwb_exercise_yrs to column for confinement dynamic exercise
		}
	}
	else 
	{
		gmwb_exercise_point = 0;
	}

	//WTW - Gen2 - Move the code below to a new scalar 'carvm_annuitzn_test_num'.
	/*if (this == fia_carvm_stat || (this == fia_carvm_tax && !fia->tax_res_equals_stat_flag))
	{
		if (carvm_calc_annuitzn_defn != NOT_APPLICABLE)
		{
			carvm_annuitzn_test_num = fia->carvm_annuitzn_tests_number;
		}
	} */
}



#line 1 "set_income_phase_lookup_aig.FIACARVM_LIAB.for"                                                                                   
void FIACARVM_LIAB::set_income_phase_lookup_aig(int t, double cumulative_wdls, double account_value)
{
	// 20180822 MTC - Set income_phase_lookup_aig as lookup for fia->gmwb_credit_mult_aig
	
	double cumulative_withrawals_to_date_cv = cumulative_wdls; //pfwd_surr_cumul(t);
	if (cumulative_withrawals_to_date_cv > SMALL_DOUBLE)
	{
		if (fia->gmwb_flag)
		{
			if (pol_yr(t) <= gmwb_wait_period_aig)
			{
				fia->income_phase_lookup_aig = PRE_INCOME;
			}
			else
			{
				// DTL 20200229 (START): redid this logic a bit while fixing an income phase lookup issue
				// DTL 20200121	(START): TFS 87035
				if (account_value < model_point_amount_threshold)
				{
					fia->income_phase_lookup_aig = GMWB_CLAIM;
				}
				// DTL 20200121	(END): TFS 87035
				else
				{
					fia->income_phase_lookup_aig = GMWB_INCOME;
				}
				// DTL 20200229 (END): redid this logic a bit while fixing an income phase lookup issue
			}
		}
		else
		{
			fia->income_phase_lookup_aig = PRE_INCOME;
		}
	}
	else
	{
		fia->income_phase_lookup_aig = NO_INCOME;
	}	
}



#line 1 "set_income_phase_lookup_b_aig.FIACARVM_LIAB.for"                                                                                   
void FIACARVM_LIAB::set_income_phase_lookup_b_aig(int t)
{
	double account_value;
	double cumulative_wdls;
	if (t == 0)
	{
		//account_value = fia->fund_val_fixed(res_period);
		account_value = fia->fund_val_b(fia->res_period + 1); // 20200414 DTL//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
		cumulative_wdls = fia->pfwd_surr_cumul(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
	}
	else
	{
		account_value = fund_val_b_bef_aig(t);
		cumulative_wdls = pfwd_surr_cumul_aig(t - 1);
	}

	cumulative_wdls += pfwd_surr_aig(t);
	set_income_phase_lookup_aig(t, cumulative_wdls, account_value);
}



#line 1 "set_income_phase_lookup_b_bef_aig.FIACARVM_LIAB.for"                                                                                   
void FIACARVM_LIAB::set_income_phase_lookup_b_bef_aig(int t)
{
	double account_value;
	double cumulative_wdls;
	if (t == 0)
	{
		//account_value = fia->fund_val_fixed(res_period);
		account_value = fia->fund_val_b(fia->res_period + 1); // 20200414 DTL//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
		cumulative_wdls = fia->pfwd_surr_cumul(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
	}
	else
	{
		account_value = fund_val_e_aig(t - 1);
		cumulative_wdls = pfwd_surr_cumul_aig(t - 1);
	}

	set_income_phase_lookup_aig(t - 1, cumulative_wdls, account_value);
}



#line 1 "set_income_phase_lookup_e_aig.FIACARVM_LIAB.for"                                                                                   
void FIACARVM_LIAB::set_income_phase_lookup_e_aig(int t)
{
	double account_value;
	double cumulative_wdls;
	if (t == 0)
	{
		//account_value = fia->fund_val_fixed(res_period);
		account_value = fia->fund_val_b(fia->res_period + 1); // 20200414 DTL//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
		cumulative_wdls = fia->pfwd_surr_cumul(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
	}
	else
	{
		account_value = fund_val_e_bef_aig(t);
		cumulative_wdls = pfwd_surr_cumul_aig(t - 1);
	}

	cumulative_wdls += pfwd_surr_aig(t);
	set_income_phase_lookup_aig(t, cumulative_wdls, account_value);
}



#line 1 "set_income_phase_lookup_e_bef_aig.FIACARVM_LIAB.for"                                                                                   
void FIACARVM_LIAB::set_income_phase_lookup_e_bef_aig(int t)
{
	double account_value;
	double cumulative_wdls;
	if (t == 0)
	{
		//account_value = fia->fund_val_fixed(res_period);
		account_value = fia->fund_val_b(fia->res_period + 1); // 20200414 DTL//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
		cumulative_wdls = fia->pfwd_surr_cumul(fia->res_period);//WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
	}
	else
	{
		account_value = fund_val_b_aig(t);
		cumulative_wdls = pfwd_surr_cumul_aig(t - 1);
	}

	cumulative_wdls += pfwd_surr_aig(t);
	set_income_phase_lookup_aig(t, cumulative_wdls, account_value);
}



#line 1 "time_to_expiry.FIACARVM_LIAB.for"                                                                                   
double FIACARVM_LIAB::time_to_expiry(int t, int fia_mths)
{
if (t < 0 || t > max_calc_period)
	return NO_AVG;

//time to expiry is in years	
//equal to one after first partial year of calcs since CARVM is calculated on a policy year basis 
if (t == 1) 
	return double (mths_in_first_year) / double(fia_mths);

return 1.0;
}



#line 1 "volatility.FIACARVM_LIAB.for"                                                                                   
double FIACARVM_LIAB::volatility(int t, const xstring &eqt_index, double moneyness, double time_to_expiry)
{
if (t < 0 || t > max_calc_period)
	return NO_AVG;

if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
	return fia_rates->get_index_vol(fia->res_period, //WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
				eqt_index,
				moneyness,
				time_to_expiry,
				EFFECTIVE_ANNUAL,
				NO_SHIFT);

return rates->get_index_vol(fia->res_period, //WTW - Gen2 - RebasedModelObjectCanOnlyBeCalledFromARebasingFormula
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
	CashFlowCommonData(9, "carvm_ann_disc_factor", "fiacarvm_liab_carvm_ann_disc_factor",  "carvm_ann_disc_factor",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_ann_disc_factor, 'E','Y', '3', 'N', (size_t)&modelOffset->carvm_ann_disc_factor),
	CashFlowCommonData(10, "carvm_disc_factor_elect_annuitzn", "fiacarvm_liab_carvm_disc_factor_elect_annuitzn",  "carvm_disc_factor_elect_annuitzn",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_disc_factor_elect_annuitzn, 'E','N', '3', 'N', (size_t)&modelOffset->carvm_disc_factor_elect_annuitzn),
	CashFlowCommonData(11, "carvm_disc_factor_elect_cash_val", "fiacarvm_liab_carvm_disc_factor_elect_cash_val",  "carvm_disc_factor_elect_cash_val",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_disc_factor_elect_cash_val, 'E','N', '3', 'N', (size_t)&modelOffset->carvm_disc_factor_elect_cash_val),
	CashFlowCommonData(12, "carvm_disc_factor_non_elect", "fiacarvm_liab_carvm_disc_factor_non_elect",  "carvm_disc_factor_non_elect",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_disc_factor_non_elect, 'E','N', '3', 'N', (size_t)&modelOffset->carvm_disc_factor_non_elect),
	CashFlowCommonData(13, "carvm_disc_factor_non_elect_gmwb", "fiacarvm_liab_carvm_disc_factor_non_elect_gmwb",  "carvm_disc_factor_non_elect_gmwb",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_disc_factor_non_elect_gmwb, 'E','N', '3', 'N', (size_t)&modelOffset->carvm_disc_factor_non_elect_gmwb),
	CashFlowCommonData(14, "cash_val_b_aig", "fiacarvm_liab_cash_val_b_aig",  "cash_val_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_cash_val_b_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->cash_val_b_aig),
	CashFlowCommonData(15, "cash_val_b_bef_aig", "fiacarvm_liab_cash_val_b_bef_aig",  "cash_val_b_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_cash_val_b_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->cash_val_b_bef_aig),
	CashFlowCommonData(16, "cash_val_e_aig", "fiacarvm_liab_cash_val_e_aig",  "cash_val_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_cash_val_e_aig, 'E','N', '3', 'N', (size_t)&modelOffset->cash_val_e_aig),
	CashFlowCommonData(17, "cash_val_e_bef_aig", "fiacarvm_liab_cash_val_e_bef_aig",  "cash_val_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_cash_val_e_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->cash_val_e_bef_aig),
	CashFlowCommonData(18, "cash_val_pv", "fiacarvm_liab_cash_val_pv",  "cash_val_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_cash_val_pv, 'E','N', '3', 'N', (size_t)&modelOffset->cash_val_pv),
	CashFlowCommonData(19, "contract_val_b_aig", "fiacarvm_liab_contract_val_b_aig",  "contract_val_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_contract_val_b_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->contract_val_b_aig),
	CashFlowCommonData(20, "contract_val_b_bef_aig", "fiacarvm_liab_contract_val_b_bef_aig",  "contract_val_b_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_contract_val_b_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->contract_val_b_bef_aig),
	CashFlowCommonData(21, "contract_val_e_aig", "fiacarvm_liab_contract_val_e_aig",  "contract_val_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_contract_val_e_aig, 'E','N', '3', 'N', (size_t)&modelOffset->contract_val_e_aig),
	CashFlowCommonData(22, "contract_val_e_bef_aig", "fiacarvm_liab_contract_val_e_bef_aig",  "contract_val_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_contract_val_e_bef_aig, 'E','N', '3', 'N', (size_t)&modelOffset->contract_val_e_bef_aig),
	CashFlowCommonData(23, "credited_int", "fiacarvm_liab_credited_int",  "credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_credited_int, 'E','N', '3', 'N', (size_t)&modelOffset->credited_int),
	CashFlowCommonData(24, "crediting_rate", "fiacarvm_liab_crediting_rate",  "crediting_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_crediting_rate, 'E','N', '3', 'N', (size_t)&modelOffset->crediting_rate),
	CashFlowCommonData(25, "crediting_rate_black_scholes_aig", "fiacarvm_liab_crediting_rate_black_scholes_aig",  "crediting_rate_black_scholes_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_crediting_rate_black_scholes_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->crediting_rate_black_scholes_aig),
	CashFlowCommonData(26, "crediting_rate_index0_aig", "fiacarvm_liab_crediting_rate_index0_aig",  "crediting_rate_index0_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_crediting_rate_index0_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_rate_index0_aig),
	CashFlowCommonData(27, "crediting_rate_secure_cap_crbg", "fiacarvm_liab_crediting_rate_secure_cap_crbg",  "crediting_rate_secure_cap_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_crediting_rate_secure_cap_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_rate_secure_cap_crbg),
	CashFlowCommonData(28, "dth_benefits_b_bef_aig", "fiacarvm_liab_dth_benefits_b_bef_aig",  "dth_benefits_b_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_dth_benefits_b_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->dth_benefits_b_bef_aig),
	CashFlowCommonData(29, "dth_benefits_e_aig", "fiacarvm_liab_dth_benefits_e_aig",  "dth_benefits_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_dth_benefits_e_aig, 'E','N', '3', 'N', (size_t)&modelOffset->dth_benefits_e_aig),
	CashFlowCommonData(30, "dth_benefits_pv", "fiacarvm_liab_dth_benefits_pv",  "dth_benefits_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_dth_benefits_pv, 'E','N', '3', 'N', (size_t)&modelOffset->dth_benefits_pv),
	CashFlowCommonData(31, "dth_claim_rate_blended_experience_aig", "fiacarvm_liab_dth_claim_rate_blended_experience_aig",  "dth_claim_rate_blended_experience_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_dth_claim_rate_blended_experience_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->dth_claim_rate_blended_experience_aig),
	CashFlowCommonData(32, "dth_claim_rate_experience_aig", "fiacarvm_liab_dth_claim_rate_experience_aig",  "dth_claim_rate_experience_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_dth_claim_rate_experience_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->dth_claim_rate_experience_aig),
	CashFlowCommonData(33, "dth_claim_rate_female_experience_aig", "fiacarvm_liab_dth_claim_rate_female_experience_aig",  "dth_claim_rate_female_experience_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_dth_claim_rate_female_experience_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->dth_claim_rate_female_experience_aig),
	CashFlowCommonData(34, "dth_claim_rate_last_survivor_experience_aig", "fiacarvm_liab_dth_claim_rate_last_survivor_experience_aig",  "dth_claim_rate_last_survivor_experience_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_dth_claim_rate_last_survivor_experience_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->dth_claim_rate_last_survivor_experience_aig),
	CashFlowCommonData(35, "dth_claim_rate_male_experience_aig", "fiacarvm_liab_dth_claim_rate_male_experience_aig",  "dth_claim_rate_male_experience_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_dth_claim_rate_male_experience_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->dth_claim_rate_male_experience_aig),
	CashFlowCommonData(36, "fund_val_b_aig", "fiacarvm_liab_fund_val_b_aig",  "fund_val_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_b_aig, 'E','N', '3', 'N', (size_t)&modelOffset->fund_val_b_aig),
	CashFlowCommonData(37, "fund_val_b_bef_aig", "fiacarvm_liab_fund_val_b_bef_aig",  "fund_val_b_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_b_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->fund_val_b_bef_aig),
	CashFlowCommonData(38, "fund_val_e_aig", "fiacarvm_liab_fund_val_e_aig",  "fund_val_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_e_aig, 'E','N', '3', 'N', (size_t)&modelOffset->fund_val_e_aig),
	CashFlowCommonData(39, "fund_val_e_bef_aig", "fiacarvm_liab_fund_val_e_bef_aig",  "fund_val_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_fund_val_e_bef_aig, 'E','N', '3', 'N', (size_t)&modelOffset->fund_val_e_bef_aig),
	CashFlowCommonData(40, "gmab_av_b_aig", "fiacarvm_liab_gmab_av_b_aig",  "gmab_av_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmab_av_b_aig, 'E','N', '3', 'N', (size_t)&modelOffset->gmab_av_b_aig),
	CashFlowCommonData(41, "gmab_av_e_aig", "fiacarvm_liab_gmab_av_e_aig",  "gmab_av_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmab_av_e_aig, 'E','N', '3', 'N', (size_t)&modelOffset->gmab_av_e_aig),
	CashFlowCommonData(42, "gmwb_ann_benefits", "fiacarvm_liab_gmwb_ann_benefits",  "gmwb_ann_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_ann_benefits, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_ann_benefits),
	CashFlowCommonData(43, "gmwb_ann_benefits_pv", "fiacarvm_liab_gmwb_ann_benefits_pv",  "gmwb_ann_benefits_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_ann_benefits_pv, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_ann_benefits_pv),
	CashFlowCommonData(44, "gmwb_chg", "fiacarvm_liab_gmwb_chg",  "gmwb_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_chg, 'E','N', '3', 'N', (size_t)&modelOffset->gmwb_chg),
	CashFlowCommonData(45, "gmwb_flex_mawp_adj_aig", "fiacarvm_liab_gmwb_flex_mawp_adj_aig",  "gmwb_flex_mawp_adj_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_flex_mawp_adj_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_flex_mawp_adj_aig),
	CashFlowCommonData(46, "gmwb_income_base_b_aig", "fiacarvm_liab_gmwb_income_base_b_aig",  "gmwb_income_base_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_b_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_income_base_b_aig),
	CashFlowCommonData(47, "gmwb_income_base_b_bef_aig", "fiacarvm_liab_gmwb_income_base_b_bef_aig",  "gmwb_income_base_b_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_b_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_income_base_b_bef_aig),
	CashFlowCommonData(48, "gmwb_income_base_e_aig", "fiacarvm_liab_gmwb_income_base_e_aig",  "gmwb_income_base_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_e_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_income_base_e_aig),
	CashFlowCommonData(49, "gmwb_income_base_e_bef_aig", "fiacarvm_liab_gmwb_income_base_e_bef_aig",  "gmwb_income_base_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_e_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_income_base_e_bef_aig),
	CashFlowCommonData(50, "gmwb_income_base_ny_b_aig", "fiacarvm_liab_gmwb_income_base_ny_b_aig",  "gmwb_income_base_ny_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_ny_b_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_income_base_ny_b_aig),
	CashFlowCommonData(51, "gmwb_income_base_ny_b_bef_aig", "fiacarvm_liab_gmwb_income_base_ny_b_bef_aig",  "gmwb_income_base_ny_b_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_ny_b_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_income_base_ny_b_bef_aig),
	CashFlowCommonData(52, "gmwb_income_base_ny_e_aig", "fiacarvm_liab_gmwb_income_base_ny_e_aig",  "gmwb_income_base_ny_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_ny_e_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_income_base_ny_e_aig),
	CashFlowCommonData(53, "gmwb_income_base_ny_e_bef_aig", "fiacarvm_liab_gmwb_income_base_ny_e_bef_aig",  "gmwb_income_base_ny_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_base_ny_e_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_income_base_ny_e_bef_aig),
	CashFlowCommonData(54, "gmwb_income_credit_base_b_aig", "fiacarvm_liab_gmwb_income_credit_base_b_aig",  "gmwb_income_credit_base_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_credit_base_b_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_income_credit_base_b_aig),
	CashFlowCommonData(55, "gmwb_income_credit_base_b_bef_aig", "fiacarvm_liab_gmwb_income_credit_base_b_bef_aig",  "gmwb_income_credit_base_b_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_credit_base_b_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_income_credit_base_b_bef_aig),
	CashFlowCommonData(56, "gmwb_income_credit_base_e_aig", "fiacarvm_liab_gmwb_income_credit_base_e_aig",  "gmwb_income_credit_base_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_credit_base_e_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_income_credit_base_e_aig),
	CashFlowCommonData(57, "gmwb_income_credit_base_e_bef_aig", "fiacarvm_liab_gmwb_income_credit_base_e_bef_aig",  "gmwb_income_credit_base_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_credit_base_e_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_income_credit_base_e_bef_aig),
	CashFlowCommonData(58, "gmwb_income_credit_e_bef_aig", "fiacarvm_liab_gmwb_income_credit_e_bef_aig",  "gmwb_income_credit_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_income_credit_e_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_income_credit_e_bef_aig),
	CashFlowCommonData(59, "gmwb_inf_b_aig", "fiacarvm_liab_gmwb_inf_b_aig",  "gmwb_inf_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_inf_b_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_inf_b_aig),
	CashFlowCommonData(60, "gmwb_inf_b_bef_aig", "fiacarvm_liab_gmwb_inf_b_bef_aig",  "gmwb_inf_b_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_inf_b_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_inf_b_bef_aig),
	CashFlowCommonData(61, "gmwb_inf_e_aig", "fiacarvm_liab_gmwb_inf_e_aig",  "gmwb_inf_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_inf_e_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_inf_e_aig),
	CashFlowCommonData(62, "gmwb_inf_e_bef_aig", "fiacarvm_liab_gmwb_inf_e_bef_aig",  "gmwb_inf_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_inf_e_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_inf_e_bef_aig),
	CashFlowCommonData(63, "gmwb_max_annual_wdl_pct_aig", "fiacarvm_liab_gmwb_max_annual_wdl_pct_aig",  "gmwb_max_annual_wdl_pct_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_max_annual_wdl_pct_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_max_annual_wdl_pct_aig),
	CashFlowCommonData(64, "gmwb_max_wdl_amt_aig", "fiacarvm_liab_gmwb_max_wdl_amt_aig",  "gmwb_max_wdl_amt_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_max_wdl_amt_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_max_wdl_amt_aig),
	CashFlowCommonData(65, "gmwb_min_income_base_e_bef_aig", "fiacarvm_liab_gmwb_min_income_base_e_bef_aig",  "gmwb_min_income_base_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_min_income_base_e_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_min_income_base_e_bef_aig),
	CashFlowCommonData(66, "gmwb_pip_annual_wdl_pct_aig", "fiacarvm_liab_gmwb_pip_annual_wdl_pct_aig",  "gmwb_pip_annual_wdl_pct_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_gmwb_pip_annual_wdl_pct_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->gmwb_pip_annual_wdl_pct_aig),
	CashFlowCommonData(67, "guar_min_contract_val", "fiacarvm_liab_guar_min_contract_val",  "guar_min_contract_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_guar_min_contract_val, 'E','N', '3', 'N', (size_t)&modelOffset->guar_min_contract_val),
	CashFlowCommonData(68, "index_term_cap_rate_min_aig", "fiacarvm_liab_index_term_cap_rate_min_aig",  "index_term_cap_rate_min_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_index_term_cap_rate_min_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_cap_rate_min_aig),
	CashFlowCommonData(69, "index_term_par_rate_min_aig", "fiacarvm_liab_index_term_par_rate_min_aig",  "index_term_par_rate_min_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_index_term_par_rate_min_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_par_rate_min_aig),
	CashFlowCommonData(70, "index_term_sprd_rate_max_aig", "fiacarvm_liab_index_term_sprd_rate_max_aig",  "index_term_sprd_rate_max_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_index_term_sprd_rate_max_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_sprd_rate_max_aig),
	CashFlowCommonData(71, "index_term_trigger_rate_min_aig", "fiacarvm_liab_index_term_trigger_rate_min_aig",  "index_term_trigger_rate_min_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_index_term_trigger_rate_min_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->index_term_trigger_rate_min_aig),
	CashFlowCommonData(72, "initialize", "fiacarvm_liab_initialize",  "initialize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(73, "min_accum_val_b_aig", "fiacarvm_liab_min_accum_val_b_aig",  "min_accum_val_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_accum_val_b_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_accum_val_b_aig),
	CashFlowCommonData(74, "min_accum_val_b_bef_aig", "fiacarvm_liab_min_accum_val_b_bef_aig",  "min_accum_val_b_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_accum_val_b_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_accum_val_b_bef_aig),
	CashFlowCommonData(75, "min_accum_val_e_aig", "fiacarvm_liab_min_accum_val_e_aig",  "min_accum_val_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_accum_val_e_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_accum_val_e_aig),
	CashFlowCommonData(76, "min_accum_val_e_bef_aig", "fiacarvm_liab_min_accum_val_e_bef_aig",  "min_accum_val_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_accum_val_e_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_accum_val_e_bef_aig),
	CashFlowCommonData(77, "min_wdl_val_alt_b_aig", "fiacarvm_liab_min_wdl_val_alt_b_aig",  "min_wdl_val_alt_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_alt_b_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_wdl_val_alt_b_aig),
	CashFlowCommonData(78, "min_wdl_val_alt_base_b_aig", "fiacarvm_liab_min_wdl_val_alt_base_b_aig",  "min_wdl_val_alt_base_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_alt_base_b_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_wdl_val_alt_base_b_aig),
	CashFlowCommonData(79, "min_wdl_val_alt_base_e_aig", "fiacarvm_liab_min_wdl_val_alt_base_e_aig",  "min_wdl_val_alt_base_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_alt_base_e_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_wdl_val_alt_base_e_aig),
	CashFlowCommonData(80, "min_wdl_val_alt_base_e_bef_aig", "fiacarvm_liab_min_wdl_val_alt_base_e_bef_aig",  "min_wdl_val_alt_base_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_alt_base_e_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_wdl_val_alt_base_e_bef_aig),
	CashFlowCommonData(81, "min_wdl_val_alt_e_aig", "fiacarvm_liab_min_wdl_val_alt_e_aig",  "min_wdl_val_alt_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_alt_e_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_wdl_val_alt_e_aig),
	CashFlowCommonData(82, "min_wdl_val_alt_e_bef_aig", "fiacarvm_liab_min_wdl_val_alt_e_bef_aig",  "min_wdl_val_alt_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_alt_e_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_wdl_val_alt_e_bef_aig),
	CashFlowCommonData(83, "min_wdl_val_b_aig", "fiacarvm_liab_min_wdl_val_b_aig",  "min_wdl_val_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_b_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_wdl_val_b_aig),
	CashFlowCommonData(84, "min_wdl_val_b_bef_aig", "fiacarvm_liab_min_wdl_val_b_bef_aig",  "min_wdl_val_b_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_b_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_wdl_val_b_bef_aig),
	CashFlowCommonData(85, "min_wdl_val_e_aig", "fiacarvm_liab_min_wdl_val_e_aig",  "min_wdl_val_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_e_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_wdl_val_e_aig),
	CashFlowCommonData(86, "min_wdl_val_e_bef_aig", "fiacarvm_liab_min_wdl_val_e_bef_aig",  "min_wdl_val_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_e_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_wdl_val_e_bef_aig),
	CashFlowCommonData(87, "min_wdl_val_final_b_aig", "fiacarvm_liab_min_wdl_val_final_b_aig",  "min_wdl_val_final_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_final_b_aig, 'B','Y', '3', 'N', (size_t)&modelOffset->min_wdl_val_final_b_aig),
	CashFlowCommonData(88, "min_wdl_val_final_e_aig", "fiacarvm_liab_min_wdl_val_final_e_aig",  "min_wdl_val_final_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_final_e_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_wdl_val_final_e_aig),
	CashFlowCommonData(89, "min_wdl_val_final_e_bef_aig", "fiacarvm_liab_min_wdl_val_final_e_bef_aig",  "min_wdl_val_final_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_min_wdl_val_final_e_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->min_wdl_val_final_e_bef_aig),
	CashFlowCommonData(90, "nh_benefits_pv", "fiacarvm_liab_nh_benefits_pv",  "nh_benefits_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_nh_benefits_pv, 'E','N', '3', 'N', (size_t)&modelOffset->nh_benefits_pv),
	CashFlowCommonData(91, "nh_incid_rate", "fiacarvm_liab_nh_incid_rate",  "nh_incid_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_nh_incid_rate, 'E','Y', '3', 'N', (size_t)&modelOffset->nh_incid_rate),
	CashFlowCommonData(92, "pfwd_entitlement_b_aig", "fiacarvm_liab_pfwd_entitlement_b_aig",  "pfwd_entitlement_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_entitlement_b_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->pfwd_entitlement_b_aig),
	CashFlowCommonData(93, "pfwd_entitlement_b_bef_aig", "fiacarvm_liab_pfwd_entitlement_b_bef_aig",  "pfwd_entitlement_b_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_entitlement_b_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->pfwd_entitlement_b_bef_aig),
	CashFlowCommonData(94, "pfwd_entitlement_e_aig", "fiacarvm_liab_pfwd_entitlement_e_aig",  "pfwd_entitlement_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_entitlement_e_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->pfwd_entitlement_e_aig),
	CashFlowCommonData(95, "pfwd_entitlement_e_bef_aig", "fiacarvm_liab_pfwd_entitlement_e_bef_aig",  "pfwd_entitlement_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_entitlement_e_bef_aig, 'E','N', '3', 'N', (size_t)&modelOffset->pfwd_entitlement_e_bef_aig),
	CashFlowCommonData(96, "pfwd_pct_aig", "fiacarvm_liab_pfwd_pct_aig",  "pfwd_pct_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_pct_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->pfwd_pct_aig),
	CashFlowCommonData(97, "pfwd_surr_aig", "fiacarvm_liab_pfwd_surr_aig",  "pfwd_surr_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_surr_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->pfwd_surr_aig),
	CashFlowCommonData(98, "pfwd_surr_cumul_aig", "fiacarvm_liab_pfwd_surr_cumul_aig",  "pfwd_surr_cumul_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_surr_cumul_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->pfwd_surr_cumul_aig),
	CashFlowCommonData(99, "pfwd_surr_pv", "fiacarvm_liab_pfwd_surr_pv",  "pfwd_surr_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_surr_pv, 'E','N', '3', 'N', (size_t)&modelOffset->pfwd_surr_pv),
	CashFlowCommonData(100, "pol_mth_aig", "fiacarvm_liab_pol_mth_aig",  "pol_mth_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pol_mth_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->pol_mth_aig),
	CashFlowCommonData(101, "pol_yr", "fiacarvm_liab_pol_yr",  "pol_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_pol_yr, 'B','N', '3', 'N', (size_t)&modelOffset->pol_yr),
	CashFlowCommonData(102, "policies_female_experience_aig", "fiacarvm_liab_policies_female_experience_aig",  "policies_female_experience_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_policies_female_experience_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->policies_female_experience_aig),
	CashFlowCommonData(103, "policies_joint_experience_aig", "fiacarvm_liab_policies_joint_experience_aig",  "policies_joint_experience_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_policies_joint_experience_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->policies_joint_experience_aig),
	CashFlowCommonData(104, "policies_last_survivor_experience_aig", "fiacarvm_liab_policies_last_survivor_experience_aig",  "policies_last_survivor_experience_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_policies_last_survivor_experience_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->policies_last_survivor_experience_aig),
	CashFlowCommonData(105, "policies_male_experience_aig", "fiacarvm_liab_policies_male_experience_aig",  "policies_male_experience_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_policies_male_experience_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->policies_male_experience_aig),
	CashFlowCommonData(106, "prem_bonus_recapture_aig", "fiacarvm_liab_prem_bonus_recapture_aig",  "prem_bonus_recapture_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_prem_bonus_recapture_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->prem_bonus_recapture_aig),
	CashFlowCommonData(107, "prem_cumul_prop_wdl_aig", "fiacarvm_liab_prem_cumul_prop_wdl_aig",  "prem_cumul_prop_wdl_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_prem_cumul_prop_wdl_aig, 'E','N', '3', 'N', (size_t)&modelOffset->prem_cumul_prop_wdl_aig),
	CashFlowCommonData(108, "res_integrated", "fiacarvm_liab_res_integrated",  "res_integrated",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_res_integrated, 'E','N', '3', 'N', (size_t)&modelOffset->res_integrated),
	CashFlowCommonData(109, "res_integrated_annuitzn", "fiacarvm_liab_res_integrated_annuitzn",  "res_integrated_annuitzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_res_integrated_annuitzn, 'E','N', '3', 'N', (size_t)&modelOffset->res_integrated_annuitzn),
	CashFlowCommonData(110, "res_integrated_cash_val", "fiacarvm_liab_res_integrated_cash_val",  "res_integrated_cash_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_res_integrated_cash_val, 'E','N', '3', 'N', (size_t)&modelOffset->res_integrated_cash_val),
	CashFlowCommonData(111, "startup", "fiacarvm_liab_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(112, "surr_chg_b_aig", "fiacarvm_liab_surr_chg_b_aig",  "surr_chg_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg_b_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->surr_chg_b_aig),
	CashFlowCommonData(113, "surr_chg_b_bef_aig", "fiacarvm_liab_surr_chg_b_bef_aig",  "surr_chg_b_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg_b_bef_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->surr_chg_b_bef_aig),
	CashFlowCommonData(114, "surr_chg_e_aig", "fiacarvm_liab_surr_chg_e_aig",  "surr_chg_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg_e_aig, 'E','Y', '3', 'N', (size_t)&modelOffset->surr_chg_e_aig),
	CashFlowCommonData(115, "surr_chg_e_bef_aig", "fiacarvm_liab_surr_chg_e_bef_aig",  "surr_chg_e_bef_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg_e_bef_aig, 'E','N', '3', 'N', (size_t)&modelOffset->surr_chg_e_bef_aig),
	CashFlowCommonData(116, "surr_chg_pct", "fiacarvm_liab_surr_chg_pct",  "surr_chg_pct",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIACARVM_LIAB_UDF::fiacarvm_liab_surr_chg_pct, 'E','N', '3', 'N', (size_t)&modelOffset->surr_chg_pct),
	CashFlowCommonData(117, "surv", "fiacarvm_liab_surv",  "surv",  CashFlowCommonData::AVG,
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
	&FIACARVM_LIAB::mCFStaticData_0[62],
	&FIACARVM_LIAB::mCFStaticData_0[63],
	&FIACARVM_LIAB::mCFStaticData_0[64],
	&FIACARVM_LIAB::mCFStaticData_0[65],
	&FIACARVM_LIAB::mCFStaticData_0[66],
	&FIACARVM_LIAB::mCFStaticData_0[67],
	&FIACARVM_LIAB::mCFStaticData_0[68],
	&FIACARVM_LIAB::mCFStaticData_0[69],
	&FIACARVM_LIAB::mCFStaticData_0[70],
	&FIACARVM_LIAB::mCFStaticData_0[71],
	&FIACARVM_LIAB::mCFStaticData_0[72],
	&FIACARVM_LIAB::mCFStaticData_0[73],
	&FIACARVM_LIAB::mCFStaticData_0[74],
	&FIACARVM_LIAB::mCFStaticData_0[75],
	&FIACARVM_LIAB::mCFStaticData_0[76],
	&FIACARVM_LIAB::mCFStaticData_0[77],
	&FIACARVM_LIAB::mCFStaticData_0[78],
	&FIACARVM_LIAB::mCFStaticData_0[79],
	&FIACARVM_LIAB::mCFStaticData_0[80],
	&FIACARVM_LIAB::mCFStaticData_0[81],
	&FIACARVM_LIAB::mCFStaticData_0[82],
	&FIACARVM_LIAB::mCFStaticData_0[83],
	&FIACARVM_LIAB::mCFStaticData_0[84],
	&FIACARVM_LIAB::mCFStaticData_0[85],
	&FIACARVM_LIAB::mCFStaticData_0[86],
	&FIACARVM_LIAB::mCFStaticData_0[87],
	&FIACARVM_LIAB::mCFStaticData_0[88],
	&FIACARVM_LIAB::mCFStaticData_0[89],
	&FIACARVM_LIAB::mCFStaticData_0[90],
	&FIACARVM_LIAB::mCFStaticData_0[91],
	&FIACARVM_LIAB::mCFStaticData_0[92],
	&FIACARVM_LIAB::mCFStaticData_0[93],
	&FIACARVM_LIAB::mCFStaticData_0[94],
	&FIACARVM_LIAB::mCFStaticData_0[95],
	&FIACARVM_LIAB::mCFStaticData_0[96],
	&FIACARVM_LIAB::mCFStaticData_0[97],
	&FIACARVM_LIAB::mCFStaticData_0[98],
	&FIACARVM_LIAB::mCFStaticData_0[99],
	&FIACARVM_LIAB::mCFStaticData_0[100],
	&FIACARVM_LIAB::mCFStaticData_0[101],
	&FIACARVM_LIAB::mCFStaticData_0[102],
	&FIACARVM_LIAB::mCFStaticData_0[103],
	&FIACARVM_LIAB::mCFStaticData_0[104],
	&FIACARVM_LIAB::mCFStaticData_0[105],
	&FIACARVM_LIAB::mCFStaticData_0[106],
	&FIACARVM_LIAB::mCFStaticData_0[107],
	&FIACARVM_LIAB::mCFStaticData_0[108],
	&FIACARVM_LIAB::mCFStaticData_0[109],
	&FIACARVM_LIAB::mCFStaticData_0[110],
	&FIACARVM_LIAB::mCFStaticData_0[111],
	&FIACARVM_LIAB::mCFStaticData_0[112],
	&FIACARVM_LIAB::mCFStaticData_0[113],
	&FIACARVM_LIAB::mCFStaticData_0[114],
	&FIACARVM_LIAB::mCFStaticData_0[115],
	&FIACARVM_LIAB::mCFStaticData_0[116],
	&FIACARVM_LIAB::mCFStaticData_0[117],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for calc_base_res_only_aig                                                                                       
	const ChoicePair calc_base_res_only_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList calc_base_res_only_aigEnumList(2, calc_base_res_only_aigChoicePairs);

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

	// EnumList for current_opt_defn_aig                                                                                       
	const ChoicePair current_opt_defn_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CALL, "CALL")
		,ChoicePair(StrEnum::PUT, "PUT")
		,ChoicePair(StrEnum::RATCHET_PART, "RATCHET_PART")
		,ChoicePair(StrEnum::RATCHET_SPRD, "RATCHET_SPRD")
		,ChoicePair(StrEnum::NONE, "NONE")
	};
	const EnumList current_opt_defn_aigEnumList(5, current_opt_defn_aigChoicePairs);

	// EnumList for enhanced_income_defn_aig                                                                                       
	const ChoicePair enhanced_income_defn_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList enhanced_income_defn_aigEnumList(2, enhanced_income_defn_aigChoicePairs);

	// EnumList for gender                                                                                       
	const ChoicePair genderChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MALE, "Male")
		,ChoicePair(StrEnum::FEMALE, "Female")
		,ChoicePair(StrEnum::BLENDED, "Blended")
		,ChoicePair(StrEnum::JOINT, "Joint")
		,ChoicePair(StrEnum::NONE, "None")
	};
	const EnumList genderEnumList(5, genderChoicePairs);

	// EnumList for gmwb_flex_defn_aig                                                                                       
	const ChoicePair gmwb_flex_defn_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList gmwb_flex_defn_aigEnumList(2, gmwb_flex_defn_aigChoicePairs);

	// EnumList for gmwb_flex_mawp_adj_method_aig                                                                                       
	const ChoicePair gmwb_flex_mawp_adj_method_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ANNUAL_LIFE_ANNUITY_FACTORS, "Annual Life Annuity Factors")
		,ChoicePair(StrEnum::MONTHLY_LIFE_ANNUITY_FACTORS, "Monthly Life Annuity Factors")
	};
	const EnumList gmwb_flex_mawp_adj_method_aigEnumList(2, gmwb_flex_mawp_adj_method_aigChoicePairs);

	// EnumList for include_nh_defn                                                                                       
	const ChoicePair include_nh_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList include_nh_defnEnumList(2, include_nh_defnChoicePairs);

	// EnumList for mort_calc_basis_joint_aig                                                                                       
	const ChoicePair mort_calc_basis_joint_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::JOINT_STATUS, "Joint Status")
		,ChoicePair(StrEnum::LAST_SURVIVOR, "Last Survivor")
	};
	const EnumList mort_calc_basis_joint_aigEnumList(2, mort_calc_basis_joint_aigChoicePairs);

	// EnumList for mort_gender                                                                                       
	const ChoicePair mort_genderChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MALE, "Male")
		,ChoicePair(StrEnum::FEMALE, "Female")
		,ChoicePair(StrEnum::BLENDED, "Blended")
		,ChoicePair(StrEnum::JOINT, "Joint")
		,ChoicePair(StrEnum::NONE, "None")
	};
	const EnumList mort_genderEnumList(5, mort_genderChoicePairs);

	// EnumList for mva_defn_aig                                                                                       
	const ChoicePair mva_defn_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList mva_defn_aigEnumList(2, mva_defn_aigChoicePairs);

	// EnumList for pfwd_model_switch_aig                                                                                       
	const ChoicePair pfwd_model_switch_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FULL, "FULL")
		,ChoicePair(StrEnum::NONE, "NONE")
	};
	const EnumList pfwd_model_switch_aigEnumList(2, pfwd_model_switch_aigChoicePairs);

	// EnumList for valn_carvm_defn                                                                                       
	const ChoicePair valn_carvm_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ISSUE_YEAR, "Issue Year")
		,ChoicePair(StrEnum::CHANGE_IN_FUND, "Change in Fund")
	};
	const EnumList valn_carvm_defnEnumList(2, valn_carvm_defnChoicePairs);

	// EnumList for valn_cash_settle_defn                                                                                       
	const ChoicePair valn_cash_settle_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::WITH_CASH_SETTLEMENTS, "With Cash Settlements")
		,ChoicePair(StrEnum::WITHOUT_CASH_SETTLEMENTS, "Without Cash Settlements")
	};
	const EnumList valn_cash_settle_defnEnumList(2, valn_cash_settle_defnChoicePairs);

	// EnumList for valn_int_guar_defn                                                                                       
	const ChoicePair valn_int_guar_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::WITHOUT_GUARANTEES, "Without Guarantees")
		,ChoicePair(StrEnum::WITH_GUARANTEES, "With Guarantees")
		,ChoicePair(StrEnum::WITH_OR_WITHOUT_GUARANTEES, "With or Without Guarantees")
	};
	const EnumList valn_int_guar_defnEnumList(3, valn_int_guar_defnChoicePairs);

	// EnumList for valn_plan_type                                                                                       
	const ChoicePair valn_plan_typeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PLAN_A, "Plan A")
		,ChoicePair(StrEnum::PLAN_B, "Plan B")
		,ChoicePair(StrEnum::PLAN_C, "Plan C")
	};
	const EnumList valn_plan_typeEnumList(3, valn_plan_typeChoicePairs);

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
	Descriptor(0, Attribute::STR_ENUM,	"calc_base_res_only_aig", -1, (size_t)&modelOffset->calc_base_res_only_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &calc_base_res_only_aigEnumList, Feature(true)),
	Descriptor(1, Attribute::STR_ENUM,	"carvm_annuitzn_ann_type", -1, (size_t)&modelOffset->carvm_annuitzn_ann_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &carvm_annuitzn_ann_typeEnumList, Feature(true)),
	Descriptor(2, Attribute::INT,	"carvm_annuitzn_certain_yrs", -1, (size_t)&modelOffset->carvm_annuitzn_certain_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::DOUBLE,	"carvm_annuitzn_min_fund_val_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_annuitzn_min_fund_val_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::DOUBLE,	"carvm_annuitzn_mort_base", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_annuitzn_mort_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::STRING,	"carvm_annuitzn_mort_base_tbl_id", -1, (size_t)&modelOffset->carvm_annuitzn_mort_base_tbl_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::STRING,	"carvm_annuitzn_mort_base_tbl_style", -1, (size_t)&modelOffset->carvm_annuitzn_mort_base_tbl_style,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::DOUBLE,	"carvm_annuitzn_mort_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_annuitzn_mort_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::INT,	"carvm_annuitzn_test_num_old", -1, (size_t)&modelOffset->carvm_annuitzn_test_num_old,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::STRING,	"carvm_annuitzn_tests", -1, (size_t)&modelOffset->carvm_annuitzn_tests,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::STR_ENUM,	"carvm_calc_annuitzn_defn", -1, (size_t)&modelOffset->carvm_calc_annuitzn_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &carvm_calc_annuitzn_defnEnumList, Feature(true)),
	Descriptor(11, Attribute::STR_ENUM,	"carvm_cont_defn", -1, (size_t)&modelOffset->carvm_cont_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &carvm_cont_defnEnumList, Feature(false)),
	Descriptor(12, Attribute::STRING,	"carvm_gmwb_exercise_points", -1, (size_t)&modelOffset->carvm_gmwb_exercise_points,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::DOUBLE,	"carvm_int_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_int_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(14, Attribute::DOUBLE,	"carvm_life_int_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_life_int_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::INT,	"carvm_max_dur", -1, (size_t)&modelOffset->carvm_max_dur,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::DOUBLE,	"carvm_mort_base", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_mort_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::STRING,	"carvm_mort_base_tbl_id", -1, (size_t)&modelOffset->carvm_mort_base_tbl_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::STRING,	"carvm_mort_base_tbl_style", -1, (size_t)&modelOffset->carvm_mort_base_tbl_style,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::DOUBLE,	"carvm_mort_improve_pct_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_mort_improve_pct_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::DOUBLE,	"carvm_mort_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->carvm_mort_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::DOUBLE,	"cash_val_weight_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cash_val_weight_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::STR_ENUM,	"current_opt_defn_aig", -1, (size_t)&modelOffset->current_opt_defn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &current_opt_defn_aigEnumList, Feature(true)),
	Descriptor(23, Attribute::DOUBLE,	"dth_benefits_weight_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->dth_benefits_weight_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::STR_ENUM,	"enhanced_income_defn_aig", -1, (size_t)&modelOffset->enhanced_income_defn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &enhanced_income_defn_aigEnumList, Feature(true)),
	Descriptor(25, Attribute::STR_ENUM,	"gender", -1, (size_t)&modelOffset->gender,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &genderEnumList, Feature(true)),
	Descriptor(26, Attribute::DOUBLE,	"gmwb_ann_benefits_weight_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_ann_benefits_weight_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::INT,	"gmwb_exercise_point", -1, (size_t)&modelOffset->gmwb_exercise_point,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(28, Attribute::STR_ENUM,	"gmwb_flex_defn_aig", -1, (size_t)&modelOffset->gmwb_flex_defn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_flex_defn_aigEnumList, Feature(true)),
	Descriptor(29, Attribute::STR_ENUM,	"gmwb_flex_mawp_adj_method_aig", -1, (size_t)&modelOffset->gmwb_flex_mawp_adj_method_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_flex_mawp_adj_method_aigEnumList, Feature(true)),
	Descriptor(30, Attribute::DOUBLE,	"gmwb_mort_base", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_mort_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(31, Attribute::STRING,	"gmwb_mort_base_tbl_id", -1, (size_t)&modelOffset->gmwb_mort_base_tbl_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(32, Attribute::STRING,	"gmwb_mort_base_tbl_style", -1, (size_t)&modelOffset->gmwb_mort_base_tbl_style,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(33, Attribute::DOUBLE,	"gmwb_mort_improve_pct_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_mort_improve_pct_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(34, Attribute::INT,	"gmwb_wait_period_aig", -1, (size_t)&modelOffset->gmwb_wait_period_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(35, Attribute::INT,	"gmwb_wdl_proj_yr_aig", -1, (size_t)&modelOffset->gmwb_wdl_proj_yr_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(36, Attribute::STR_ENUM,	"include_nh_defn", -1, (size_t)&modelOffset->include_nh_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &include_nh_defnEnumList, Feature(true)),
	Descriptor(37, Attribute::INT,	"issue_age_aig", -1, (size_t)&modelOffset->issue_age_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(38, Attribute::DOUBLE,	"min_wdl_val_growth_pct_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->min_wdl_val_growth_pct_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(39, Attribute::STRING,	"model_name_gen2", -1, (size_t)&modelOffset->model_name_gen2,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(40, Attribute::INT,	"mort_attained_age", -1, (size_t)&modelOffset->mort_attained_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(41, Attribute::STR_ENUM,	"mort_calc_basis_joint_aig", -1, (size_t)&modelOffset->mort_calc_basis_joint_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mort_calc_basis_joint_aigEnumList, Feature(true)),
	Descriptor(42, Attribute::STR_ENUM,	"mort_gender", -1, (size_t)&modelOffset->mort_gender,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mort_genderEnumList, Feature(true)),
	Descriptor(43, Attribute::STRING,	"mort_improve_base_date_aig", -1, (size_t)&modelOffset->mort_improve_base_date_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(44, Attribute::INT,	"mort_issue_age", -1, (size_t)&modelOffset->mort_issue_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(45, Attribute::INT,	"mort_pol_yr", -1, (size_t)&modelOffset->mort_pol_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(46, Attribute::STR_ENUM,	"mva_defn_aig", -1, (size_t)&modelOffset->mva_defn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mva_defn_aigEnumList, Feature(true)),
	Descriptor(47, Attribute::DOUBLE,	"nh_benefits_weight_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->nh_benefits_weight_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(48, Attribute::DOUBLE,	"nh_incid_base", Descriptor::NOT_INDEXED, (size_t)&modelOffset->nh_incid_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(49, Attribute::STRING,	"nh_incid_base_tbl_id_aig", -1, (size_t)&modelOffset->nh_incid_base_tbl_id_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(50, Attribute::STR_ENUM,	"pfwd_model_switch_aig", -1, (size_t)&modelOffset->pfwd_model_switch_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &pfwd_model_switch_aigEnumList, Feature(true)),
	Descriptor(51, Attribute::DOUBLE,	"pfwd_surr_weight_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pfwd_surr_weight_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(52, Attribute::STRING,	"plan_code", -1, (size_t)&modelOffset->plan_code,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(53, Attribute::DOUBLE,	"prem_bonus_recapture_pct_carvm_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->prem_bonus_recapture_pct_carvm_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(54, Attribute::INT,	"pv_max_period", -1, (size_t)&modelOffset->pv_max_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(55, Attribute::STR_ENUM,	"valn_carvm_defn", -1, (size_t)&modelOffset->valn_carvm_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &valn_carvm_defnEnumList, Feature(true)),
	Descriptor(56, Attribute::STR_ENUM,	"valn_cash_settle_defn", -1, (size_t)&modelOffset->valn_cash_settle_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &valn_cash_settle_defnEnumList, Feature(true)),
	Descriptor(57, Attribute::INT,	"valn_guar_dur", -1, (size_t)&modelOffset->valn_guar_dur,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(58, Attribute::STR_ENUM,	"valn_int_guar_defn", -1, (size_t)&modelOffset->valn_int_guar_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &valn_int_guar_defnEnumList, Feature(true)),
	Descriptor(59, Attribute::INT,	"valn_issue_yr", -1, (size_t)&modelOffset->valn_issue_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(60, Attribute::STR_ENUM,	"valn_plan_type", -1, (size_t)&modelOffset->valn_plan_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &valn_plan_typeEnumList, Feature(true)),
	Descriptor(61, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(62, Attribute::SCALAR_INT,	"carvm_annuitzn_test_num", -1, (size_t)&modelOffset->carvm_annuitzn_test_num,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_annuitzn_test_num)),
	Descriptor(63, Attribute::SCALAR_STRING,	"carvm_cont_defn_aig", -1, (size_t)&modelOffset->carvm_cont_defn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&FIACARVM_LIAB_UDF::fiacarvm_liab_carvm_cont_defn_aig)),
	Descriptor(64, Attribute::SCALAR_STRING,	"glb_withdrls_have_begun_aig", -1, (size_t)&modelOffset->glb_withdrls_have_begun_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&FIACARVM_LIAB_UDF::fiacarvm_liab_glb_withdrls_have_begun_aig)),
	Descriptor(65, Attribute::SCALAR_INT,	"int_guar_dur", -1, (size_t)&modelOffset->int_guar_dur,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIACARVM_LIAB_UDF::fiacarvm_liab_int_guar_dur)),
	Descriptor(66, Attribute::SCALAR_INT,	"issue_date", -1, (size_t)&modelOffset->issue_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIACARVM_LIAB_UDF::fiacarvm_liab_issue_date)),
	Descriptor(67, Attribute::SCALAR_INT,	"max_calc_period", -1, (size_t)&modelOffset->max_calc_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIACARVM_LIAB_UDF::fiacarvm_liab_max_calc_period)),
	Descriptor(68, Attribute::SCALAR_DOUBLE,	"mths_in_first_year", -1, (size_t)&modelOffset->mths_in_first_year,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&FIACARVM_LIAB_UDF::fiacarvm_liab_mths_in_first_year)),
	Descriptor(69, Attribute::SCALAR_STRING,	"pfwd_model", -1, (size_t)&modelOffset->pfwd_model,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&FIACARVM_LIAB_UDF::fiacarvm_liab_pfwd_model)),
	Descriptor(70, Attribute::SCALAR_DOUBLE,	"prem_cumul", -1, (size_t)&modelOffset->prem_cumul,
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
	&FIACARVM_LIAB::descriptor_0[64],
	&FIACARVM_LIAB::descriptor_0[65],
	&FIACARVM_LIAB::descriptor_0[66],
	&FIACARVM_LIAB::descriptor_0[67],
	&FIACARVM_LIAB::descriptor_0[68],
	&FIACARVM_LIAB::descriptor_0[69],
	&FIACARVM_LIAB::descriptor_0[70],
	nullptr};
	const size_t FIACARVM_LIAB::sDescriptorCount = 71;

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
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, adco(company_asset_adco)
	, ann_pba(company_seg_ann_pba)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_rates(company_liab_fia_fia_rates)
	, intex(company_asset_intex)
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
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(117, FIACARVM_LIAB::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, adco(company_asset_adco)
	, ann_pba(company_seg_ann_pba)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_rates(company_liab_fia_fia_rates)
	, intex(company_asset_intex)
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

#ifdef __CREATE_ADCO_ASSET_CLASS_
       company_asset_adco = 0;
#endif
#ifdef __CREATE_INTEX_ASSET_CLASS_
       company_asset_intex = 0;
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
#ifdef __CREATE_AUTOMATION_CLASS_
       company_liab_fia_fia_automation = 0;
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

	for (int cf_no = 1; cf_no <= 117; cf_no++)
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

#ifdef __CREATE_ADCO_ASSET_CLASS_
		company_asset_adco = (ADCO_ASSET*)(findUnique("company|asset|adco"));
#endif
#ifdef __CREATE_INTEX_ASSET_CLASS_
		company_asset_intex = (INTEX_ASSET*)(findUnique("company|asset|intex"));
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
#ifdef __CREATE_AUTOMATION_CLASS_
		company_liab_fia_fia_automation = (AUTOMATION*)(findUnique("company|liab|fia|fia_automation"));
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
	, sm_bond_is(FIACARVM_LIAB::sm_bond_is)
	, sm_bond_pv(FIACARVM_LIAB::sm_bond_pv)
	, sm_bond_ym(FIACARVM_LIAB::sm_bond_ym)
	, sm_mtg_is(FIACARVM_LIAB::sm_mtg_is)
	, sm_mtg_pv(FIACARVM_LIAB::sm_mtg_pv)
	, sm_mtg_ym(FIACARVM_LIAB::sm_mtg_ym)

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
BitArray FIACARVM_LIAB::dataVariables(71);
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

