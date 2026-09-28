
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
#include "ModelClass\fia_liab_udf.h"
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

extern sowmpoutput fia_state_of_world_mp_output;
sowfcols fia_state_of_world_financial_columns;
sowfinput fia_state_of_world_financial_input;
sowfoutput fia_state_of_world_financial_output;
sowfmap fia_state_of_world_financial_input_pos;
sowfmapiter fia_state_of_world_financial_input_pos_iter;

extern ofstream& StatAuditFile;
ofstream& StatAuditFile = * new ofstream;

extern ofstream& TaxAuditFile;
ofstream& TaxAuditFile = * new ofstream;

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
#ifndef fia_liab_TableDefs
#define fia_liab_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection FIA_LIAB::TTHC;
void FIA_LIAB::removeSMPointers(ModelClass* modelToRemove){

	if(modelToRemove == sm_fia_rates)
		sm_fia_rates = 0;

}		

//@@ START - acq_exp
// Acquisition Expenses                                                                                             
// Column:ACQ_EXP
//========================================================
double FIA_LIAB_UDF::fia_liab_acq_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"acq_exp",t);
}



//^^^

#line 1 "acq_exp.FIA_LIAB.for"
if (t <= 0 || t > maturity_period)
	return NO_AVG;
	
if ((t + elapsed_mths) != 1)
	return NO_AVG;
	
double adj_mult = exp_adj_mult;
double acq_exp_per_pol = 0.0;
double acq_exp_pct_prem = 0.0;

acq_exp_per_pol
= this->acq_exp_per_pol 
  * infl_cumul(t - 1) 
  * policies_b(t)
  * adj_mult;

acq_exp_pct_prem
= this->acq_exp_pct_prem
  * single_prem
  * adj_mult;

double acq_exp_cv = acq_exp_per_pol + acq_exp_pct_prem;

if ( gsia_reins_defn_crbg == REINSURER ) 
{
	acq_exp_pct_prem *= quota_share_reinsured_crbg;
	acq_exp_cv = acq_exp_per_pol + acq_exp_pct_prem;

	acq_exp_cv += gwl_acq_exp_allow_crbg(t); 
}
else if ( gsia_reins_defn_crbg == CEDANT )
{
	acq_exp_cv -= gwl_acq_exp_allow_crbg(t);
}

return acq_exp_cv;

}

//@@ END

//@@ START - admin_fee
// Administration Fee                                                                                             
// Column:ADMIN_FEE
//========================================================
double FIA_LIAB_UDF::fia_liab_admin_fee(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"admin_fee",t);
}



//^^^

#line 1 "admin_fee.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (pol_mth(t) != 1) 
	return 0.0;
	
double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->admin_fee(t);	
		
return total;

}

//@@ END

//@@ START - age_last
// Age Last Birthday at Previous Policy Anniversary                                                                                             
// Column:AGE_LAST
//========================================================
double FIA_LIAB_UDF::fia_liab_age_last(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(3,"age_last",t);
}



//^^^

#line 1 "age_last.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period + 1 && elapsed_mths <= 0)
	return issue_age_mp;

return xint(issue_age_mp) + pol_yr(t) - 1.0;

}

//@@ END

//@@ START - ann_benefits_eom
// Annuity Benefits                                                                                             
// Column:ANN_BENEFITS_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_ann_benefits_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(4,"ann_benefits_eom",t);
}



//^^^

#line 1 "ann_benefits_eom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return  NO_AVG;

double fund_val = fund_val_e_bef(t);

if (ann_ben_partial_credit_ind_crbg == YES)
{
	fund_val *= ( 1.0 + crediting_rate_partial_crbg(t) );
}
	
double ann_benefits_base = max(min_accum_val_e_bef_crbg(t), fund_val);

// if ann_benefits_min_wdl_val_defn_aig = Yes
//floor by min_wdl_val_e_bef_aig(t)

double gmwb_claim = max(ann_claims_gmwb(t) - maturity_benefits(t), 0);

return ann_benefits_base * (1.0 - dth_claim_rate_mthly(t)) * annuitzn_rate_mthly(t)
	   + gmwb_claim;

}

//@@ END

//@@ START - ann_claims_gmwb
// Annuity Claims - GMWB                                                                                             
// Column:ANN_CLAIMS_GMWB
//========================================================
double FIA_LIAB_UDF::fia_liab_ann_claims_gmwb(int t) {
//^^^



//^^^

#line 1 "ann_claims_gmwb.FIA_LIAB.for"
//20250508 Revised with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag || gmwb_wdl_amt_excess_bef_crbg(t) > SMALL_DOUBLE)
	return 0.0;

if (gmwb_inf_bef(t) < model_point_amount_threshold
	|| gmwb_max_wdl_amt(t) < model_point_amount_threshold 
	|| policies_b(t) < model_point_amount_threshold) 
	return 0.0;

//Calc PV only at maturity
if (calc_pv_gmwb_av_exhaustion_crbg == NO)
{
	if(t < maturity_period && fund_val_fixed(t) < model_point_amount_threshold)
		return ann_gmwb_cash_flow_crbg(t);

	else if(t != maturity_period)
		return 0.;
}

//Calc PV if reaching maturity, or fund val is depleted
if (calc_pv_gmwb_av_exhaustion_crbg == YES && 
	t != maturity_period && fund_val_fixed(t) > model_point_amount_threshold) 
	return 0.0;

double period_wdl	= gmwb_inf_bef(t) * pv_gmwb_mawp_crbg(t) * surv_period(t) / 12.0; //mawa
double pip			= gmwb_inf_bef(t) * pv_gmwb_pip_pct_crbg(t) * surv_period(t) / 12.0;

//true up if util rate of the year is < 100%
double proj_yr_wdls_remaining	= 12 - pol_mth(t) + 1;
double period_wdl_first_yr		= gmwb_entitlement_remaining_b_crbg(t) * surv_period(t) / proj_yr_wdls_remaining; 
double disc_wdls	= period_wdl_first_yr - withdrl_benefits(t);

if (calc_pv_gmwb_av_exhaustion_crbg == NO && ann_gmwb_cash_flow_crbg(t - 1) > SMALL_DOUBLE)  //triggered by maturity, no true up
{
	period_wdl_first_yr = period_wdl;
	disc_wdls = period_wdl_first_yr;
}

double fund_val		= fund_released_maturity(t);
if (ann_ben_partial_credit_ind_crbg == YES)
{
	fund_val *= (1.0 + crediting_rate_partial_crbg(t));
}

bool pip_started = false;

double cumm_discount = 1.0;
double period_disc = 1.0;
if(alm_flag) //After tax asset yield
{
   period_disc = pow(1.0 + asset_yld_less_dflt_inv(t - 1) * (1.0 - tax_rate), 1.0 / 12.0);
}

double cumm_surv = 1.0;
double surv_perc = 1.0;
double joint_cumm_surv  = 1.0;	
double male_cumm_surv   = 1.0;
double female_cumm_surv = 1.0;
double last_surv_cumm_surv = 1.0;

StrEnum::EnumValue gender_cv = gender_mp;
if (gender_mp != gender_aft_inc && t + elapsed_mths > gmwb_exercise_yrs * 12)
{
	gender_cv = gender_aft_inc;
}

int projection_year = int((t + elapsed_mths - 1) / 12.0 + 1); 
int max_period = (term_to_omega_age * 12) - elapsed_mths;	

for (int i = t + 1; i <= max_period; i = i + 1)
{
	int pol_yr = int((i + elapsed_mths - 1) / 12.0 + 1);
	int pol_mth = int(i + elapsed_mths - 1) % 12 + 1;

	if (pol_yr == projection_year)
	{
		period_wdl = period_wdl_first_yr; 
	}

	if (!pip_started && fund_val < SMALL_DOUBLE && pol_mth == 1) //mawa will be paid until the end of the year
	{
		pip_started = true;
		period_wdl = pip;
	}
	
	double mort_rate_m = dth_rate_mthly_male_crbg(i);
	double mort_rate_f = dth_rate_mthly_female_crbg(i);

	if (gender_cv == MALE)
	{
		cumm_surv = cumm_surv * (1 - mort_rate_m);
	}
	if (gender_cv == FEMALE)
	{
		cumm_surv = cumm_surv * (1 - mort_rate_f);
	}
	else //Joint life, last survivor. 
	{
		joint_cumm_surv  *= (1 - mort_rate_m) * (1 - mort_rate_f);
		male_cumm_surv   *= (1 - mort_rate_m);
		female_cumm_surv *= (1 - mort_rate_f);
		last_surv_cumm_surv = male_cumm_surv + female_cumm_surv - joint_cumm_surv; 
		cumm_surv = (male_cumm_surv * policies_male_inf_crbg(t)
						+ female_cumm_surv * policies_female_inf_crbg(t)
						+ last_surv_cumm_surv * policies_joint_inf_crbg(t)) / policies_last_survivor_inf_crbg(t);
	}

	if (t == maturity_period && fund_val > SMALL_DOUBLE) //LAD 2022, period certain
	{
		cumm_surv = 1.;
	}

	if(!alm_flag)
	{
		period_disc = 1.0 + disc_rate_rf_sprd_uel_crbg(i); 
	}

	cumm_discount /= period_disc; 

	disc_wdls += period_wdl * cumm_surv * cumm_discount;

	fund_val = max(0.0, fund_val - period_wdl); //Period certain approach: ignores mortality

	/*log_screen<<"t= "<<t
	<<" i= "<<i	<<" pol_yr= "<<pol_yr
	<<" pol_mth= "<<pol_mth	<<" projection_year= "<<projection_year
	<<" pip_started= "<<pip_started	<<" period_wdl_first_yr= "<<period_wdl_first_yr
	<<" period_wdl= "<<period_wdl	<<" cumm_surv= "<<cumm_surv
	<<" disc_wdls= "<<disc_wdls	<<" fund_val= "<<fund_val	<<MSG_USER;*/
}

return disc_wdls;

}

//@@ END

//@@ START - ann_gmwb_cash_flow_crbg
// Gmwb Claim Cash Flow Crbg                                                                                             
// Column:ANN_GMWB_CASH_FLOW_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_ann_gmwb_cash_flow_crbg(int t) {
//^^^



//^^^

#line 1 "ann_gmwb_cash_flow_crbg.FIA_LIAB.for"
//20260206 New column with CRBG logic
if (t <= commencement_period || t > maturity_period || calc_pv_gmwb_av_exhaustion_crbg == YES)
	return NO_AVG;

if (!gmwb_flag || gmwb_wdl_amt_excess_bef_crbg(t) > SMALL_DOUBLE)
	return 0.0;

if (fund_val_fixed(t) > SMALL_DOUBLE) 
	return 0.0;

double monthly_pip = gmwb_inf_bef(t) * ann_gmwb_pip_pct_crbg(t) * surv_period(t) / 12.0; 

double monthly_wdl = monthly_pip;

if (pol_yr(t) == ann_gmwb_claim_yr_crbg(t)) //mawp pipp transition
{
	monthly_wdl = ann_gmwb_wdl_grossed_up_crbg(t) - withdrl_benefits(t);
}

return monthly_wdl;


}

//@@ END

//@@ START - ann_gmwb_claim_yr_crbg
// year when gmwb claim begins                                                                                             
// Column:ANN_GMWB_CLAIM_YR_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_ann_gmwb_claim_yr_crbg(int t) {
//^^^



//^^^

#line 1 "ann_gmwb_claim_yr_crbg.FIA_LIAB.for"
//20260206 New column with CRBG logic
if (t < commencement_period || t > maturity_period || calc_pv_gmwb_av_exhaustion_crbg == YES)
	return NO_AVG;

if (t == 0 && elapsed_mths > 0)
	return ann_gmwb_claim_yr;

if (!gmwb_flag)
	return 0.0;

if (fund_val_fixed(t) > model_point_amount_threshold) 
	return 0.0;

if (ann_gmwb_claim_yr_crbg(t - 1) > 0)
	return ann_gmwb_claim_yr_crbg(t - 1);
else
	return int((t + elapsed_mths - 1) / 12.0 + 1);




}

//@@ END

//@@ START - ann_gmwb_pip_pct_crbg
// pip pct for gmwb claim                                                                                             
// Column:ANN_GMWB_PIP_PCT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_ann_gmwb_pip_pct_crbg(int t) {
//^^^



//^^^

#line 1 "ann_gmwb_pip_pct_crbg.FIA_LIAB.for"
//20250626 New column for CRBG logic
if (t < commencement_period || t > maturity_period || !gmwb_flag)
	return NO_AVG;

if (fund_val_fixed(t) > model_point_amount_threshold) 
	return 0.0;

if (mawp_lookup_type_crbg == ISSUE_AGE)
{
	return pv_gmwb_mawp_crbg(t); //This will force trigger withdrl
}

int gmwb_withdrl_yr = min(pol_yr(t), gmwb_exercise_yrs_crbg(t) + 1);
							
gmwb_withdrl_age = issue_age_col_crbg(t) + gmwb_withdrl_yr - 1;
double pipp = gmwb_pipp_crbg;

if (gmwb_pipp_stepup_ind_crbg(t) == 1)
{
	gmwb_withdrl_age = issue_age_col_crbg(t) + gmwb_withdrl_yr - 1;
	pipp = gmwb_pipp_stepup_crbg;
}

return pipp;

}

//@@ END

//@@ START - ann_gmwb_wdl_grossed_up_crbg
// ann_gmwb_wdl_grossed_up_crbg                                                                                             
// Column:ANN_GMWB_WDL_GROSSED_UP_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_ann_gmwb_wdl_grossed_up_crbg(int t) {
//^^^



//^^^

#line 1 "ann_gmwb_wdl_grossed_up_crbg.FIA_LIAB.for"
//20260206 New column with CRBG logic
if (t <= commencement_period || t > maturity_period || calc_pv_gmwb_av_exhaustion_crbg == YES)
	return NO_AVG;

if (!gmwb_flag || gmwb_wdl_amt_excess_bef_crbg(t) > SMALL_DOUBLE)
	return 0.0;

if (fund_val_fixed(t) > model_point_amount_threshold) 
	return 0.0;

if (ann_gmwb_wdl_grossed_up_crbg(t - 1) > SMALL_DOUBLE && pol_yr(t) == ann_gmwb_claim_yr_crbg(t))
	return ann_gmwb_wdl_grossed_up_crbg(t - 1);

//true up if util rate of the year is < 100%
double proj_yr_wdls_remaining	= 12 - pol_mth(t) + 1;
double period_wdl_grossed_up	= gmwb_entitlement_remaining_b_crbg(t) * surv_period(t) / proj_yr_wdls_remaining;

return period_wdl_grossed_up;



}

//@@ END

//@@ START - annuitzn_rate
// Annuitization Rate                                                                                             
// Column:ANNUITZN_RATE
//========================================================
double FIA_LIAB_UDF::fia_liab_annuitzn_rate(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(10,"annuitzn_rate",t);
}



//^^^

#line 1 "annuitzn_rate.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
				
if (decrements_defn == NO || gmwb_flag) //20250625 no annuitization for GMWB
	return NO_AVG;

if (annuity_type_crbg == "FA") //No annuitization for FA
	return 0.;
				
double annuitzn_rate = min(1.0, annuitzn_base);

return min(annuitzn_rate, 1.0 - lapse_rate(t));

}

//@@ END

//@@ START - annuitzn_rate_mthly
// Annuitization Rate Monthly                                                                                             
// Column:ANNUITZN_RATE_MTHLY
//========================================================
double FIA_LIAB_UDF::fia_liab_annuitzn_rate_mthly(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(11,"annuitzn_rate_mthly",t);
}



//^^^

#line 1 "annuitzn_rate_mthly.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (decrements_defn == NO)
	return NO_AVG;

return convert_decrem_rate_basis(annuitzn_rate(t), EFFECTIVE_ANNUAL, -12);

}

//@@ END

//@@ START - asset_yld
// Asset Yield                                                                                             
// Column:ASSET_YLD
//========================================================
double FIA_LIAB_UDF::fia_liab_asset_yld(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(12,"asset_yld",t);
}



//^^^

#line 1 "asset_yld.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG; 

double hedge_asset_yld_adj = 0.0;

if (t == start_period)
	{
	// estimate initial adjustment using next period growth
	if (fabs(hedge_mkt_val(t)) < model_point_amount_threshold)
		hedge_asset_yld_adj = 0.0;
	else
		hedge_asset_yld_adj = hedge_mkt_val_growth(t + 1) / hedge_mkt_val(t);
	}
else
	{
	if (fabs(hedge_mkt_val(t - 1)) < model_point_amount_threshold)
		hedge_asset_yld_adj = 0.0;
	else
		hedge_asset_yld_adj = hedge_mkt_val_growth(t) / hedge_mkt_val(t - 1);
	}

// Convert into effective annual rate
hedge_asset_yld_adj = pow(1.0 + hedge_asset_yld_adj, 12.0) - 1.0;

if (!isMainModel)
	return seg_element->asset_yld(t);

if (asset_yld_defn == DETERMINISTIC)
	return asset_yld_deterministic + hedge_asset_yld_adj;

// else asset_yld_defn == STOCHASTIC
return get_comp_rate(asset_yld_comp_rate_id, t) + hedge_asset_yld_adj;

}

//@@ END

//@@ START - asset_yld_fa_rate_setting_crbg
// Asset Yld Fa Rate Setting Crbg                                                                                             
// Column:ASSET_YLD_FA_RATE_SETTING_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_asset_yld_fa_rate_setting_crbg(int t) {
//^^^



//^^^

#line 1 "asset_yld_fa_rate_setting_crbg.FIA_LIAB.for"
//20251216 Customized new column
if (t < commencement_period || t > maturity_period || annuity_type_crbg != "FA")
{
	return NO_AVG;	
}

if (t == 0 && valn_period != 0)
	return asset_yld_for_rate_setting;

if (t + elapsed_mths == 1)
{
	return fia->crediting_ner_crbg;
}

else if (myga_term_mth_elapsed_eom_crbg(t) == 1)
{	
	double ner_cv = avg_coupon_rt_crbg(t - 1); 

	if (ner_correction_crbg == NO && !alm_flag) //To match back to old model
	{
		ner_cv = fia->avg_coupon_rt_crbg(t - 2);
	}

	if (!isMainModel && alm_flag)
	{
		ner_cv = asset_yld_inv_adj_crbg(t - 1);
	}

	return ner_cv;
}

else
{
	return asset_yld_fa_rate_setting_crbg(t - 1);
}

}

//@@ END

//@@ START - asset_yld_inv
// Asset Yield for Investment Assets                                                                                             
// Column:ASSET_YLD_INV
//========================================================
double FIA_LIAB_UDF::fia_liab_asset_yld_inv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(14,"asset_yld_inv",t);
}



//^^^

#line 1 "asset_yld_inv.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (!isMainModel)
	return seg_element->asset_yld_inv(t);

if (asset_yld_defn == DETERMINISTIC)
	return asset_yld_deterministic;

// else asset_yld_defn == STOCHASTIC
return get_comp_rate(asset_yld_comp_rate_id, t);

}

//@@ END

//@@ START - asset_yld_inv_adj_crbg
// Asset Yield for Investment Assets                                                                                             
// Column:ASSET_YLD_INV_ADJ_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_asset_yld_inv_adj_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(15,"asset_yld_inv_adj_crbg",t);
}



//^^^

#line 1 "asset_yld_inv_adj_crbg.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (!isMainModel)
	return seg_element->asset_yld_inv_adj_crbg(t);
else 
	return NO_AVG;	

}

//@@ END

//@@ START - asset_yld_less_dflt
// Asset Yield Less Default                                                                                             
// Column:ASSET_YLD_LESS_DFLT
//========================================================
double FIA_LIAB_UDF::fia_liab_asset_yld_less_dflt(int t) {
//^^^



//^^^

#line 1 "asset_yld_less_dflt.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (!isMainModel)
	return seg_element->asset_yld_less_dflt(t);
	
return asset_yld(t);

}

//@@ END

//@@ START - asset_yld_less_dflt_inv
// Asset Yield Less Default for Investment Assets                                                                                             
// Column:ASSET_YLD_LESS_DFLT_INV
//========================================================
double FIA_LIAB_UDF::fia_liab_asset_yld_less_dflt_inv(int t) {
//^^^



//^^^

#line 1 "asset_yld_less_dflt_inv.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (!isMainModel)
	return seg_element->asset_yld_less_dflt_inv(t);
	
return asset_yld_inv(t);

}

//@@ END

//@@ START - attained_age
// Attained Age                                                                                             
// Column:ATTAINED_AGE
//========================================================
double FIA_LIAB_UDF::fia_liab_attained_age(int t) {
//^^^



//^^^

#line 1 "attained_age.FIA_LIAB.for"
if (t <= (- elapsed_mths) || t > maturity_period)
	return NO_AVG;

return issue_age_mp + pol_yr(t) - 1.0;

}

//@@ END

//@@ START - avg_coupon_rt_crbg
// Avg Coupon Rt Crbg                                                                                             
// Column:AVG_COUPON_RT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_avg_coupon_rt_crbg(int t) {
//^^^



//^^^

#line 1 "avg_coupon_rt_crbg.FIA_LIAB.for"
//20250429 Customized new column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!isMainModel && alm_flag)
	return NO_AVG;

if (t + elapsed_mths == commencement_period + 1)
{
	return new_money_rate_crbg(t);
}

double cash_flow_pct;

if (annuity_type_crbg == "FA")
	cash_flow_pct = cash_flow_pct_by_prod_crbg / 12.;
else
	cash_flow_pct = cash_flow_pct_vector_crbg / 12.;

double prior_avg_coupon_rt = avg_coupon_rt_crbg(t - 1);

double avg_coupon_rt = new_money_rate_crbg(t) * cash_flow_pct + prior_avg_coupon_rt * (1.0 - cash_flow_pct);

return avg_coupon_rt;

}

//@@ END

//@@ START - bef_tax_yld
// Before Tax Yield                                                                                             
// Column:BEF_TAX_YLD
//========================================================
double FIA_LIAB_UDF::fia_liab_bef_tax_yld(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(20,"bef_tax_yld",t);
}



//^^^

#line 1 "bef_tax_yld.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return asset_yld(t);

}

//@@ END

//@@ START - bk_prof_aft_tax
// Book Profit After Tax                                                                                             
// Column:BK_PROF_AFT_TAX
//========================================================
double FIA_LIAB_UDF::fia_liab_bk_prof_aft_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(21,"bk_prof_aft_tax",t);
}



//^^^

#line 1 "bk_prof_aft_tax.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return bk_prof_bef_tax(t)
       - tax_bk_prof(t);

}

//@@ END

//@@ START - bk_prof_aft_tax_for_pv
// Book Profit After Tax for Present Values                                                                                             
// Column:BK_PROF_AFT_TAX_FOR_PV
//========================================================
double FIA_LIAB_UDF::fia_liab_bk_prof_aft_tax_for_pv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(22,"bk_prof_aft_tax_for_pv",t);
}



//^^^

#line 1 "bk_prof_aft_tax_for_pv.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (prof_distribn_mode == MONTHLY)
	return bk_prof_aft_tax(t);

if (prof_distribn_mode == QUARTERLY
	&& (xint(cal_mth(t)) % 3 == 0
		|| t == final_period))
	return bk_prof_aft_tax_qtd(t);	

if (prof_distribn_mode == ANNUAL
	&& (xint(cal_mth(t)) == 12
		|| t == final_period))
	return bk_prof_aft_tax_ytd(t);

return 0.0;

}

//@@ END

//@@ START - bk_prof_aft_tax_irr
// Book Profit After Tax for IRR                                                                                             
// Column:BK_PROF_AFT_TAX_IRR
//========================================================
double FIA_LIAB_UDF::fia_liab_bk_prof_aft_tax_irr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(23,"bk_prof_aft_tax_irr",t);
}



//^^^

#line 1 "bk_prof_aft_tax_irr.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!pricing_flag)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_bk_prof_aft_tax_irr;

	return NO_AVG;
	}
	
if (bk_prof_aft_tax_irr(t - 1) >= 0)
	return bk_prof_aft_tax_irr(t - 1)
		   * pow((1.0 + max(port_yld_aft_tax(t), -.99)), (1.0 / 12.0))
		   + bk_prof_aft_tax_for_pv(t);	

return bk_prof_aft_tax_irr(t - 1);

}

//@@ END

//@@ START - bk_prof_aft_tax_qtd
// Book Profit After Tax Calendar Quarter to Date                                                                                             
// Column:BK_PROF_AFT_TAX_QTD
//========================================================
double FIA_LIAB_UDF::fia_liab_bk_prof_aft_tax_qtd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(24,"bk_prof_aft_tax_qtd",t);
}



//^^^

#line 1 "bk_prof_aft_tax_qtd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_bk_prof_aft_tax_qtd;
		
	return NO_AVG;	
	}
	
if (xint(cal_mth(t)) % 3 == 1)
	return bk_prof_aft_tax(t);
	
return bk_prof_aft_tax_qtd(t - 1)
	   + bk_prof_aft_tax(t);

}

//@@ END

//@@ START - bk_prof_aft_tax_ytd
// Book Profit After Tax Calendar Year to Date                                                                                             
// Column:BK_PROF_AFT_TAX_YTD
//========================================================
double FIA_LIAB_UDF::fia_liab_bk_prof_aft_tax_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(25,"bk_prof_aft_tax_ytd",t);
}



//^^^

#line 1 "bk_prof_aft_tax_ytd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_bk_prof_aft_tax_ytd;
		
	return NO_AVG;	
	}
	
if (xint(cal_mth(t)) == 1)
	return bk_prof_aft_tax(t);
	
return bk_prof_aft_tax_ytd(t - 1)
       + bk_prof_aft_tax(t);

}

//@@ END

//@@ START - bk_prof_bef_tax
// Book Profit Before Tax                                                                                             
// Column:BK_PROF_BEF_TAX
//========================================================
double FIA_LIAB_UDF::fia_liab_bk_prof_bef_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(26,"bk_prof_bef_tax",t);
}



//^^^

#line 1 "bk_prof_bef_tax.FIA_LIAB.for"
if (t == 0)
	return NO_AVG;

// force call for profits by source report
bk_prof_by_source_bef_tax(t);

return prem_paid(t)
	   + inv_inc_bk_prof(t)
	   - dth_benefits(t)
	   - ann_benefits_eom(t)
	   - maturity_benefits(t)
	   - surr_benefits(t)
	   - withdrl_benefits(t)	
       - stat_res_incr(t)
       - comm_bom(t)
	   - comm_eom(t)
	   + comm_chargeback(t)
	   - acq_exp(t)
	   - maint_exp_bom(t)
	   - maint_exp_eom(t)
	   - prem_tax(t)
	   - reins_stat_cost(t)
	   - hedge_cost(t);

}

//@@ END

//@@ START - bk_prof_bef_tax_for_pv
// Book Profit Before Tax for Present Values                                                                                             
// Column:BK_PROF_BEF_TAX_FOR_PV
//========================================================
double FIA_LIAB_UDF::fia_liab_bk_prof_bef_tax_for_pv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(27,"bk_prof_bef_tax_for_pv",t);
}



//^^^

#line 1 "bk_prof_bef_tax_for_pv.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (prof_distribn_mode == MONTHLY)
	return bk_prof_bef_tax(t);

if (prof_distribn_mode == QUARTERLY
	&& (xint(cal_mth(t)) % 3 == 0
		|| t == final_period))
	return bk_prof_bef_tax_qtd(t);	

if (prof_distribn_mode == ANNUAL
	&& (xint(cal_mth(t)) == 12
		|| t == final_period))
	return bk_prof_bef_tax_ytd(t);

return 0.0;

}

//@@ END

//@@ START - bk_prof_bef_tax_qtd
// Book Profit Before Tax Calendar Quarter to Date                                                                                             
// Column:BK_PROF_BEF_TAX_QTD
//========================================================
double FIA_LIAB_UDF::fia_liab_bk_prof_bef_tax_qtd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(28,"bk_prof_bef_tax_qtd",t);
}



//^^^

#line 1 "bk_prof_bef_tax_qtd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_bk_prof_bef_tax_qtd;
		
	return NO_AVG;	
	}
	
if (xint(cal_mth(t)) % 3 == 1)
	return bk_prof_bef_tax(t);
	
return bk_prof_bef_tax_qtd(t - 1)
	   + bk_prof_bef_tax(t);

}

//@@ END

//@@ START - bk_prof_bef_tax_ytd
// Book Profit Before Tax Calendar Year to Date                                                                                             
// Column:BK_PROF_BEF_TAX_YTD
//========================================================
double FIA_LIAB_UDF::fia_liab_bk_prof_bef_tax_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(29,"bk_prof_bef_tax_ytd",t);
}



//^^^

#line 1 "bk_prof_bef_tax_ytd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_bk_prof_bef_tax_ytd;
		
	return NO_AVG;	
	}
	
if (xint(cal_mth(t)) == 1)
	return bk_prof_bef_tax(t);
	
return bk_prof_bef_tax_ytd(t - 1)
       + bk_prof_bef_tax(t);

}

//@@ END

//@@ START - bk_prof_by_source_bef_tax
// Book Profit By Source Before Tax                                                                                             
// Column:BK_PROF_BY_SOURCE_BEF_TAX
//========================================================
double FIA_LIAB_UDF::fia_liab_bk_prof_by_source_bef_tax(int t) {
//^^^



//^^^

#line 1 "bk_prof_by_source_bef_tax.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

// force call columns required for source of profits report
direct_cash_flow_int(t);
inv_inc_fund(t);
stat_res_mp(t);
fund_val_fixed(t);
credited_int(t);
gmwb_chg(t);

fund_released_dth(t);
fund_released_withdrl(t);
fund_released_surr(t);
fund_released_maturity(t);
fund_released_ann(t);
	
admin_fee(t);

	
reins_cash_flow_int(t);

return 1.0;

}

//@@ END

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double FIA_LIAB_UDF::fia_liab_cal_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(31,"cal_mth",t);
}



//^^^

#line 1 "cal_mth.FIA_LIAB.for"
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
double FIA_LIAB_UDF::fia_liab_cal_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(32,"cal_yr",t);
}



//^^^

#line 1 "cal_yr.FIA_LIAB.for"
if (t == 0)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}

//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double FIA_LIAB_UDF::fia_liab_cal_yr_relative(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(33,"cal_yr_relative",t);
}



//^^^

#line 1 "cal_yr_relative.FIA_LIAB.for"
//cal_yr(t);

return 1 + floor((proj_start_mth + t - 2) / 12.0);

}

//@@ END

//@@ START - cash_val
// Cash Value                                                                                             
// Column:CASH_VAL
//========================================================
double FIA_LIAB_UDF::fia_liab_cash_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(34,"cash_val",t);
}



//^^^

#line 1 "cash_val.FIA_LIAB.for"
//20250501 Replaced with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if(t == 0 && elapsed_mths > 0)
	return init_cash_val;

if (nyia_ind_crbg == YES)
{
	double csv_fund_val = fund_val_fixed(t) - surr_chg_pct * (fund_val_fixed(t) - pfwd_entitlement_remaining_e(t));
	double csv_mav = min_accum_val_e_crbg(t) - surr_chg_pct * (min_accum_val_e_crbg(t) - pfwd_entitlement_remaining_e(t));

	return max(csv_fund_val, csv_mav);
}

double cash_value = max(0., fund_val_fixed(t) - surr_chg_inf(t) - mva_amt_crbg(t) - gmwb_chg_partial_e_crbg(t)
			- prem_bonus_recap_e_crbg(t) - eprs_strat_fee_partial_e_crbg(t)); 

cash_value = max(cash_value, min_wdl_val_e_crbg(t));

if (gmab_ind_crbg == 1 && t + elapsed_mths >= gmab_csv_grop_yr_crbg * 12 && fund_val_fixed(t) > SMALL_DOUBLE) 
{
	cash_value = max(cash_value, prem_cumul_prop_wdl_crbg(t));
}

if (grop_ind_crbg == 1 && fund_val_fixed(t) > SMALL_DOUBLE)
{
	cash_value = max(cash_value, prem_cumul_net_wdl_crbg(t));
}

return cash_value;

}

//@@ END

//@@ START - cash_val_bef
// Cash Value End of Month Before Claims                                                                                             
// Column:CASH_VAL_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_cash_val_bef(int t) {
//^^^



//^^^

#line 1 "cash_val_bef.FIA_LIAB.for"
//20250501 Replaced with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (nyia_ind_crbg == YES)
{
	double csv_fund_val = fund_val_e_bef(t) - surr_chg_pct * (fund_val_e_bef(t) - pfwd_entitlement_remaining_bom(t));
	double csv_mav = min_accum_val_e_bef_crbg(t) - surr_chg_pct * (min_accum_val_e_bef_crbg(t) - pfwd_entitlement_remaining_bom(t));

	return max(csv_fund_val, csv_mav);
}

double cash_value = max(0.,fund_val_e_bef(t) - surr_chg_inf_bef(t) - mva_amt_bef_crbg(t) - gmwb_chg_partial_bef_crbg(t) 
				- prem_bonus_recap_e_bef_crbg(t)- eprs_strat_fee_partial_bef_crbg(t));  

cash_value = max(cash_value, min_wdl_val_e_bef_crbg(t));

if (gmab_ind_crbg == 1 && t + elapsed_mths >= gmab_csv_grop_yr_crbg * 12 && fund_val_e_bef(t) > SMALL_DOUBLE) 
{
	cash_value = max(cash_value, prem_cumul_prop_wdl_bef_crbg(t));
}

if (grop_ind_crbg == 1 && fund_val_e_bef(t) > SMALL_DOUBLE)
{
	cash_value = max(cash_value, prem_cumul_net_wdl_bef_crbg(t));
}

return cash_value;

}

//@@ END

//@@ START - cash_val_wo_mva
// Cash Value Without MVA                                                                                             
// Column:CASH_VAL_WO_MVA
//========================================================
double FIA_LIAB_UDF::fia_liab_cash_val_wo_mva(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(36,"cash_val_wo_mva",t);
}



//^^^

#line 1 "cash_val_wo_mva.FIA_LIAB.for"
//20250501 Replaced with CRBG logic. This is used for reserve calculation
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if(t == 0 && elapsed_mths > 0)
	return init_cash_val_no_mva;

if (nyia_ind_crbg == YES)
{
	double csv_fund_val = fund_val_fixed(t) - surr_chg_pct * (fund_val_fixed(t) - pfwd_entitlement_remaining_e(t));
	double csv_mav = min_accum_val_e_crbg(t) - surr_chg_pct * (min_accum_val_e_crbg(t) - pfwd_entitlement_remaining_e(t));

	return max(csv_fund_val, csv_mav);
}

double cash_value = max(0., fund_val_fixed(t) - surr_chg_inf(t) - gmwb_chg_partial_e_crbg(t)
				- prem_bonus_recap_e_crbg(t) - eprs_strat_fee_partial_e_crbg(t));

cash_value = max(cash_value, min_wdl_val_e_crbg(t));

if (gmab_ind_crbg == 1 && t + elapsed_mths >= gmab_csv_grop_yr_crbg * 12 && fund_val_fixed(t) > SMALL_DOUBLE) 
{
	cash_value = max(cash_value, prem_cumul_prop_wdl_crbg(t));
}

if (grop_ind_crbg == 1 && fund_val_fixed(t) > SMALL_DOUBLE)
{
	cash_value = max(cash_value, prem_cumul_net_wdl_crbg(t));
}

return cash_value;

}

//@@ END

//@@ START - comm_bom
// Commissions Beginning of Month                                                                                             
// Column:COMM_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_comm_bom(int t) {
//^^^



//^^^

#line 1 "comm_bom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return comm_prem_based(t) 
	   + comm_fund_based(t);

}

//@@ END

//@@ START - comm_chargeback
// Commission Chargeback                                                                                             
// Column:COMM_CHARGEBACK
//========================================================
double FIA_LIAB_UDF::fia_liab_comm_chargeback(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(38,"comm_chargeback",t);
}



//^^^

#line 1 "comm_chargeback.FIA_LIAB.for"
if (t <= start_period || t > maturity_period)
	return NO_AVG;	

//20251216 Revised with CRBG logic
double comm_chargeback;

if (annuity_type_crbg == "FA")	  
{
	pol_mth_lookup = t + elapsed_mths;
	double comm_chgback_pct_dth_cv = comm_chgback_pct_dth_crbg;
	pol_mth_lookup = t + elapsed_mths;
	double comm_chgback_pct_surr_cv = comm_chgback_pct_surr_crbg;	

	comm_chargeback = comm_subject_to_chargeback(t) * comm_chgback_pct_dth_cv * dth_claim_rate_mthly(t)
		+ comm_subject_to_chargeback(t) * comm_chgback_pct_surr_cv * (1.0 - dth_claim_rate_mthly(t)) * lapse_rate_mthly(t);
}
else
{
	pol_mth_lookup = t + elapsed_mths;
	double comm_chgback_pct_cv = comm_chargeback_pct;

	comm_chargeback = comm_subject_to_chargeback(t) * comm_chgback_pct_cv * (1 - surv_period(t)); 		   
}

return comm_chargeback;

}

//@@ END

//@@ START - comm_eom
// Commission End of Month                                                                                             
// Column:COMM_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_comm_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(39,"comm_eom",t);
}



//^^^

#line 1 "comm_eom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return NO_AVG;

}

//@@ END

//@@ START - comm_fund_based
// Commission Fund Based                                                                                             
// Column:COMM_FUND_BASED
//========================================================
double FIA_LIAB_UDF::fia_liab_comm_fund_based(int t) {
//^^^



//^^^

#line 1 "comm_fund_based.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

//20250520 Charged Quarterly
if ( xint(pol_mth(t)) % 3 == 1 )
{
	double trail_comm = fund_val_fixed(t - 1) * comm_pct_fund / 4.0;
		   
	if(pba_scen_amt_valn_flag)
	{
		trail_comm *= pba_trail_comm_mult_crbg;
	}

	return trail_comm;		   
}

return 0.;

}

//@@ END

//@@ START - comm_prem_based
// Commission Premium Based                                                                                             
// Column:COMM_PREM_BASED
//========================================================
double FIA_LIAB_UDF::fia_liab_comm_prem_based(int t) {
//^^^



//^^^

#line 1 "comm_prem_based.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return prem_paid(t) 
       * comm_pct_prem;

}

//@@ END

//@@ START - comm_subject_to_chargeback
// Commission Subject to Chargeback                                                                                             
// Column:COMM_SUBJECT_TO_CHARGEBACK
//========================================================
double FIA_LIAB_UDF::fia_liab_comm_subject_to_chargeback(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(42,"comm_subject_to_chargeback",t);
}



//^^^

#line 1 "comm_subject_to_chargeback.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (t + elapsed_mths > 12)
	return NO_AVG;

double comm_subject_to_chargeback = comm_subject_to_chargeback_e(t - 1) + comm_prem_based(t);

return comm_subject_to_chargeback;

}

//@@ END

//@@ START - comm_subject_to_chargeback_e
// Commission Subject to Chargeback End of Month                                                                                             
// Column:COMM_SUBJECT_TO_CHARGEBACK_E
//========================================================
double FIA_LIAB_UDF::fia_liab_comm_subject_to_chargeback_e(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(43,"comm_subject_to_chargeback_e",t);
}



//^^^

#line 1 "comm_subject_to_chargeback_e.FIA_LIAB.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (valn_period > 0 && t == commencement_period)
{
	return init_comm_subject_to_chargeback;
}
else
{
	return comm_subject_to_chargeback(t) * surv_period(t);
}

}

//@@ END

//@@ START - contract_val
// Contract Value at End of Period                                                                                             
// Column:CONTRACT_VAL
//========================================================
double FIA_LIAB_UDF::fia_liab_contract_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(44,"contract_val",t);
}



//^^^

#line 1 "contract_val.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (t == commencement_period) 
	{
	if (elapsed_mths > 0)
		return init_contract_val;

	return 0.0;
	}

return contract_val_bef(t) * surv_period(t) - fund_released_withdrl(t);

}

//@@ END

//@@ START - contract_val_bef
// Contract Value at End of Period Before Claims                                                                                             
// Column:CONTRACT_VAL_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_contract_val_bef(int t) {
//^^^



//^^^

#line 1 "contract_val_bef.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return (contract_val(t - 1) + prem_paid(t) * contract_val_net_consideration_pct - gmwb_chg(t))
		* (pow(1.0 + crediting_rate_gtd , 1.0 / 12.0));

}

//@@ END

//@@ START - covered_person_status_crbg
// Covered Person Status Crbg                                                                                             
// Column:COVERED_PERSON_STATUS_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_covered_person_status_crbg(int t) {
//^^^



//^^^

#line 1 "covered_person_status_crbg.FIA_LIAB.for"
//20250502 New column for CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (gender_mp == JOINT && t + elapsed_mths <= gmwb_exercise_yrs_crbg(t) * 12 + 1)
	return 1.;
else if (gender_aft_inc == JOINT && t + elapsed_mths > gmwb_exercise_yrs_crbg(t) * 12 + 1)
	return 1.;
else
	return 0.;

}

//@@ END

//@@ START - credited_int
// Credited Interest                                                                                             
// Column:CREDITED_INT
//========================================================
double FIA_LIAB_UDF::fia_liab_credited_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(47,"credited_int",t);
}



//^^^

#line 1 "credited_int.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->credited_int(t);	
		
return total;

}

//@@ END

//@@ START - credited_int_comp_numer
// Competitor Credited Interest Numerator                                                                                             
// Column:CREDITED_INT_COMP_NUMER
//========================================================
double FIA_LIAB_UDF::fia_liab_credited_int_comp_numer(int t) {
//^^^



//^^^

#line 1 "credited_int_comp_numer.FIA_LIAB.for"
return NO_AVG;

}

//@@ END

//@@ START - crediting_rate
// Crediting Rate                                                                                             
// Column:CREDITING_RATE
//========================================================
double FIA_LIAB_UDF::fia_liab_crediting_rate(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(49,"crediting_rate",t);
}



//^^^

#line 1 "crediting_rate.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (fabs(fund_val_b(t))< aggregate_amount_threshold)
	return 0.0;

return credited_int(t) / fund_val_b(t);

}

//@@ END

//@@ START - crediting_rate_cumul_crbg
// Crediting Rate Cumul Crbg                                                                                             
// Column:CREDITING_RATE_CUMUL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_crediting_rate_cumul_crbg(int t) {
//^^^



//^^^

#line 1 "crediting_rate_cumul_crbg.FIA_LIAB.for"
//20250502 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == 0 && valn_period > 0) 
	return init_crediting_rate_cumul;

double total = 0.0;

for (size_t i = 0; i < sm_fia_account.size(); i++)
{
	if (fund_val_e_bef(t) > SMALL_DOUBLE)
	{
		// Weigh by current allocation
		total += sm_fia_account[i]->crediting_rate_cumul_crbg(t) * (sm_fia_account[i]->fund_val_e_bef(t) / fund_val_e_bef(t));
	}
	else
	{
		// Weigh by initial allocation
		total += sm_fia_account[i]->crediting_rate_cumul_crbg(t) * (sm_fia_account[i]->fund_val_split_prop);
	}
}
		
return total;

}

//@@ END

//@@ START - crediting_rate_fix
// Fixed Crediting Rate For Fund Value                                                                                             
// Column:CREDITING_RATE_FIX
//========================================================
double FIA_LIAB_UDF::fia_liab_crediting_rate_fix(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(51,"crediting_rate_fix",t);
}



//^^^

#line 1 "crediting_rate_fix.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
if (has_fixed == 1)
	return sm_fia_account[0]->crediting_rate_fix(t);

return NO_AVG;

}

//@@ END

//@@ START - crediting_rate_partial_crbg
// Crediting Rate Partial Crbg                                                                                             
// Column:CREDITING_RATE_PARTIAL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_crediting_rate_partial_crbg(int t) {
//^^^



//^^^

#line 1 "crediting_rate_partial_crbg.FIA_LIAB.for"
//20250529 Customized new column.
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;	

if (fund_val_e_bef(t) < SMALL_DOUBLE)
	return 0.;

double total_prorated_return = 0.0;
double total_crediting_rate = 0.0;

for (size_t i = 0; i < sm_fia_account.size(); i++)
{		
	total_prorated_return += sm_fia_account[i]->prorated_strategy_return_crbg(t) * (sm_fia_account[i]->fund_val_e_bef(t) / fund_val_e_bef(t));
	total_crediting_rate += sm_fia_account[i]->crediting_rate(t) * (sm_fia_account[i]->fund_val_e_bef(t) / fund_val_e_bef(t));
}

double partial_crediting_rate = (1.0 + total_prorated_return) / (1.0 + total_crediting_rate) - 1.0;

return partial_crediting_rate;

}

//@@ END

//@@ START - date
// Date                                                                                             
// Column:DATE
//========================================================
double FIA_LIAB_UDF::fia_liab_date(int t) {
//^^^



//^^^

#line 1 "date.FIA_LIAB.for"
// This column is a lookup key for external sources varying by date
// The definition matches Excel = number of days since 1899
// The value is for the first day of the current month
	
int year = cal_yr(t);
int month = cal_mth(t);
int day = 1;
	
return day_number_from_date(year, month, day);


}

//@@ END

//@@ START - direct_cash_flow_bom
// Direct Cash Flow Beginning of Month                                                                                             
// Column:DIRECT_CASH_FLOW_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_direct_cash_flow_bom(int t) {
//^^^



//^^^

#line 1 "direct_cash_flow_bom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return prem_paid(t)
       - acq_exp(t)
       - maint_exp_bom(t)
	   - comm_bom(t)
       - prem_tax(t);

}

//@@ END

//@@ START - direct_cash_flow_eom
// Direct Cash Flow End of Month                                                                                             
// Column:DIRECT_CASH_FLOW_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_direct_cash_flow_eom(int t) {
//^^^



//^^^

#line 1 "direct_cash_flow_eom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return - ann_benefits_eom(t)
	   - dth_benefits(t)
	   - maturity_benefits(t)
	   - surr_benefits(t)
	   - withdrl_benefits(t)
       - maint_exp_eom(t)
       - comm_eom(t)
	   + comm_chargeback(t);

}

//@@ END

//@@ START - direct_cash_flow_int
// Direct Cash Flow Interest                                                                                             
// Column:DIRECT_CASH_FLOW_INT
//========================================================
double FIA_LIAB_UDF::fia_liab_direct_cash_flow_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(56,"direct_cash_flow_int",t);
}



//^^^

#line 1 "direct_cash_flow_int.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

double cash_flow_rate_mthly = 0.0;

if (alm_flag)
	cash_flow_rate_mthly
	= seg_element->cash_flow_rate_mthly(t);
else
	cash_flow_rate_mthly
	= pow(1.0 + asset_yld_inv(t), 1.0 / 12.0) - 1.0;
	
return direct_cash_flow_bom(t) 
       * cash_flow_rate_mthly;

}

//@@ END

//@@ START - disc_rate_1
// Discount Rate 1                                                                                             
// Column:DISC_RATE_1
//========================================================
double FIA_LIAB_UDF::fia_liab_disc_rate_1(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(57,"disc_rate_1",t);
}



//^^^

#line 1 "disc_rate_1.FIA_LIAB.for"
// This column is calculated by Rio when column discount rates are requested
if (t < commencement_period || disc_rates.size() < 1
	|| commencement_period >= final_period)
	return NO_AVG;

if (replaceWildcards("<*execution_engine*>") == "Gen2")
	return NO_AVG;

// Set lookup key 
disc_rate_id = xstring(disc_rates[0]);
static double scen_yr = disc_rate_scen_yr; // 1 lookup key - disc_rate_id;
disc_rate_id = xstring(disc_rates[0]);
static double mult = disc_rate_mult; // 1 lookup key - disc_rate_id;
disc_rate_id = xstring(disc_rates[0]);
static double addn = disc_rate_addn; // 1 lookup key - disc_rate_id;

if (fabs(mult) < rate_ratio_threshold
	|| fabs(scen_yr) < rate_ratio_threshold)
	return pow(1.0 + addn, (1.0 / 12.0)) - 1.0;

return pow((1.0 + rates_ptr->get_int_rate(t, "Govt", GET_YIELD_RATE, scen_yr, 0, EFFECTIVE_ANNUAL, NO_SHIFT)
                  * mult + addn), (1.0 / 12.0)) - 1.0;

}

//@@ END

//@@ START - disc_rate_2
// Discount Rate 2                                                                                             
// Column:DISC_RATE_2
//========================================================
double FIA_LIAB_UDF::fia_liab_disc_rate_2(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(58,"disc_rate_2",t);
}



//^^^

#line 1 "disc_rate_2.FIA_LIAB.for"
// This column is calculated by Rio when column discount rates are requested
if (t < commencement_period || disc_rates.size() < 2
	|| commencement_period >= final_period)
	return NO_AVG;	

if (replaceWildcards("<*execution_engine*>") == "Gen2")
	return NO_AVG;
	
// Set lookup key 
disc_rate_id = xstring(disc_rates[1]);
static double scen_yr = disc_rate_scen_yr; // 1 lookup key - disc_rate_id;
disc_rate_id = xstring(disc_rates[1]);
static double mult = disc_rate_mult; // 1 lookup key - disc_rate_id;
disc_rate_id = xstring(disc_rates[1]);
static double addn = disc_rate_addn; // 1 lookup key - disc_rate_id;

if (fabs(mult) < rate_ratio_threshold
	|| fabs(scen_yr) < rate_ratio_threshold)
	return pow(1.0 + addn, (1.0 / 12.0)) - 1.0;

return pow((1.0 + rates_ptr->get_int_rate(t, "Govt", GET_YIELD_RATE, scen_yr, 0, EFFECTIVE_ANNUAL, NO_SHIFT)
                 * mult + addn), (1.0 / 12.0)) - 1.0;

}

//@@ END

//@@ START - disc_rate_3
// Discount Rate 3                                                                                             
// Column:DISC_RATE_3
//========================================================
double FIA_LIAB_UDF::fia_liab_disc_rate_3(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(59,"disc_rate_3",t);
}



//^^^

#line 1 "disc_rate_3.FIA_LIAB.for"
// This column is calculated by Rio when column discount rates are requested
if (t < commencement_period || disc_rates.size() < 3
	|| commencement_period >= final_period)
	return NO_AVG;

if (replaceWildcards("<*execution_engine*>") == "Gen2")
	return NO_AVG;

// Set lookup key 
disc_rate_id = xstring(disc_rates[2]);
static double scen_yr = disc_rate_scen_yr; // 1 lookup key - disc_rate_id;
disc_rate_id = xstring(disc_rates[2]);
static double mult = disc_rate_mult; // 1 lookup key - disc_rate_id;
disc_rate_id = xstring(disc_rates[2]);
static double addn = disc_rate_addn; // 1 lookup key - disc_rate_id;

if (fabs(mult) < rate_ratio_threshold
	|| fabs(scen_yr) < rate_ratio_threshold)
	return pow(1.0 + addn, (1.0 / 12.0)) - 1.0;

return pow((1.0 + rates_ptr->get_int_rate(t, "Govt", GET_YIELD_RATE, scen_yr, 0, EFFECTIVE_ANNUAL, NO_SHIFT)
                 * mult + addn), (1.0 / 12.0)) - 1.0;

}

//@@ END

//@@ START - disc_rate_port_yld
// Discount Rate Portfolio Yield                                                                                             
// Column:DISC_RATE_PORT_YLD
//========================================================
double FIA_LIAB_UDF::fia_liab_disc_rate_port_yld(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(60,"disc_rate_port_yld",t);
}



//^^^

#line 1 "disc_rate_port_yld.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG; 

if (disc_rate_port_yld_defn == BEFORE_TAX)
	return pow(1.0 + max(bef_tax_yld(t), -.99), (1.0 / 12.0)) - 1.0;

if (disc_rate_port_yld_defn == AFTER_TAX)
	return pow(1.0 + max(port_yld_aft_tax(t), -.99), (1.0 / 12.0)) - 1.0;

return 0.0;

}

//@@ END

//@@ START - disc_rate_port_yld_defn_val
// Discount Rate Portfolio Ylield Definition Value                                                                                             
// Column:DISC_RATE_PORT_YLD_DEFN_VAL
//========================================================
double FIA_LIAB_UDF::fia_liab_disc_rate_port_yld_defn_val(int t) {
//^^^



//^^^

#line 1 "disc_rate_port_yld_defn_val.FIA_LIAB.for"
// This column is required to send the value of disc_rate_port_yld_defn to the reporting tool
if (t != start_period + 1 || valn_period > 0)
	return NO_AVG;	

if (disc_rate_port_yld_defn == BEFORE_TAX)
	return 1;
	
// if (disc_rate_port_yld_defn == AFTER_TAX)	
return 2;

}

//@@ END

//@@ START - disc_rate_rf_crbg
// Discount Rate risk free                                                                                             
// Column:DISC_RATE_RF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_disc_rate_rf_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(62,"disc_rate_rf_crbg",t);
}



//^^^

#line 1 "disc_rate_rf_crbg.FIA_LIAB.for"
if (t <= start_period || t > t_high)
	return NO_AVG; 

double rf_rate = rates_ptr->get_misc_rate(t, "RiskFree", ACTUAL_MONTHLY);

return rf_rate;

}

//@@ END

//@@ START - disc_rate_rf_sprd_ic_uel_crbg
// Discount Rate risk free IC UEL sprd                                                                                             
// Column:DISC_RATE_RF_SPRD_IC_UEL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_disc_rate_rf_sprd_ic_uel_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(63,"disc_rate_rf_sprd_ic_uel_crbg",t);
}



//^^^

#line 1 "disc_rate_rf_sprd_ic_uel_crbg.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG; 

double mthly_continuous_rf_rate = log(1 + disc_rate_rf_crbg(t));

double mthly_continuous_sprd = disc_rate_sprd_ic_uel_crbg / 12.0;

double rf_rt_with_sprd = exp(mthly_continuous_rf_rate + mthly_continuous_sprd) - 1.0;

return rf_rt_with_sprd;

}

//@@ END

//@@ START - disc_rate_rf_sprd_no_uel_crbg
// Discount Rate risk free no UEL sprd                                                                                             
// Column:DISC_RATE_RF_SPRD_NO_UEL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_disc_rate_rf_sprd_no_uel_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(64,"disc_rate_rf_sprd_no_uel_crbg",t);
}



//^^^

#line 1 "disc_rate_rf_sprd_no_uel_crbg.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG; 

double mthly_continuous_rf_rate = log(1 + disc_rate_rf_crbg(t));

double mthly_continuous_sprd = disc_rate_sprd_no_uel_crbg / 12.0;

double rf_rt_with_sprd = exp(mthly_continuous_rf_rate + mthly_continuous_sprd) - 1.0;

return rf_rt_with_sprd;

}

//@@ END

//@@ START - disc_rate_rf_sprd_uel_crbg
// Discount Rate risk free UEL sprd                                                                                             
// Column:DISC_RATE_RF_SPRD_UEL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_disc_rate_rf_sprd_uel_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(65,"disc_rate_rf_sprd_uel_crbg",t);
}



//^^^

#line 1 "disc_rate_rf_sprd_uel_crbg.FIA_LIAB.for"
if (t <= start_period || t > t_high)
	return NO_AVG; 

double mthly_continuous_rf_rate = log(1 + disc_rate_rf_crbg(t));

double mthly_continuous_sprd = disc_rate_sprd_uel_crbg / 12.0;

double rf_rt_with_sprd = exp(mthly_continuous_rf_rate + mthly_continuous_sprd) - 1.0;

return rf_rt_with_sprd;

}

//@@ END

//@@ START - distrib_earnings
// Distributable Earnings                                                                                             
// Column:DISTRIB_EARNINGS
//========================================================
double FIA_LIAB_UDF::fia_liab_distrib_earnings(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(66,"distrib_earnings",t);
}



//^^^

#line 1 "distrib_earnings.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

// these items must be calculated each period in order to determine 
// correct present values of profit measures
bk_prof_bef_tax_for_pv(t);
bk_prof_aft_tax_for_pv(t);

//force call cumulative earnings for reporting
earnings_accum(t);

double distrib_earnings
= undistrib_earnings(t - 1)
  + bk_prof_aft_tax(t)
  + tgt_cap_effect(t);
	       
if (cal_mth(t) == 12 || t == last_period_indicator(t)
	|| (prof_distribn_mode == QUARTERLY 
         && (xint(cal_mth(t)) % 3 == 0))
	|| prof_distribn_mode == MONTHLY)
	return distrib_earnings;

return NO_AVG;

}

//@@ END

//@@ START - distrib_earnings_irr
// Distributable Earnings for IRR                                                                                             
// Column:DISTRIB_EARNINGS_IRR
//========================================================
double FIA_LIAB_UDF::fia_liab_distrib_earnings_irr(int t) {
//^^^



//^^^

#line 1 "distrib_earnings_irr.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!pricing_flag)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_distrib_earnings_irr;

	return NO_AVG;
	}
	
if (distrib_earnings_irr(t - 1) >= 0)
	return distrib_earnings_irr(t - 1)
		   * pow((1.0 + max(port_yld_aft_tax(t), -.99)), (1.0 / 12.0))
		   + distrib_earnings(t);	

return distrib_earnings_irr(t - 1);

}

//@@ END

//@@ START - dth_ben_inf
// Death Benefit In Force                                                                                             
// Column:DTH_BEN_INF
//========================================================
double FIA_LIAB_UDF::fia_liab_dth_ben_inf(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(68,"dth_ben_inf",t);
}



//^^^

#line 1 "dth_ben_inf.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double fund_val = fund_val_e_bef(t) * (1 + crediting_rate_partial_crbg(t));

if (nyia_ind_crbg == YES)
{
	return max(fund_val, min_accum_val_e_crbg(t));
}

if (dth_ben_defn == FUND_VALUE)
{
	//return max(fund_val_fixed(t), contract_val(t));
	double dth_ben = max(max(0 , fund_val - prem_bonus_recap_e_crbg(t)), min_wdl_val_e_crbg(t));

	if (gmab_ind_crbg == 1 && t + elapsed_mths >= gmab_csv_grop_yr_crbg * 12 && fund_val_fixed(t) > SMALL_DOUBLE) 
	{
		dth_ben = max(dth_ben, prem_cumul_prop_wdl_crbg(t));
	}

	return dth_ben;
}

// else dth_ben_defn == CASH_VALUE	
return cash_val(t);

}

//@@ END

//@@ START - dth_ben_inf_bef
// Death Benefit In Force Before Decrements                                                                                             
// Column:DTH_BEN_INF_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_dth_ben_inf_bef(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(69,"dth_ben_inf_bef",t);
}



//^^^

#line 1 "dth_ben_inf_bef.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

double fund_val = fund_val_e_bef(t) * (1 + crediting_rate_partial_crbg(t));

if (nyia_ind_crbg == YES)
{
	return max(fund_val, min_accum_val_e_bef_crbg(t));
}

if (dth_ben_defn == FUND_VALUE)
{
	//return max(fund_val_e_bef(t), contract_val_bef(t));
	double dth_ben = max(max(0, fund_val - prem_bonus_recap_e_bef_crbg(t)), min_wdl_val_e_bef_crbg(t));

	if (gmab_ind_crbg == 1 && t + elapsed_mths >= gmab_csv_grop_yr_crbg * 12 && fund_val_e_bef(t) > SMALL_DOUBLE) 
	{
		dth_ben = max(dth_ben, prem_cumul_prop_wdl_bef_crbg(t));
	}

	return dth_ben;
 }
 
// else dth_ben_defn == CASH_VALUE	
return cash_val_bef(t);

}

//@@ END

//@@ START - dth_benefits
// Death Benefits                                                                                             
// Column:DTH_BENEFITS
//========================================================
double FIA_LIAB_UDF::fia_liab_dth_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(70,"dth_benefits",t);
}



//^^^

#line 1 "dth_benefits.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return dth_ben_inf_bef(t) * dth_claim_rate_mthly(t);

}

//@@ END

//@@ START - dth_claim_rate_mthly
// Death Claim Rate Monthly                                                                                             
// Column:DTH_CLAIM_RATE_MTHLY
//========================================================
double FIA_LIAB_UDF::fia_liab_dth_claim_rate_mthly(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(71,"dth_claim_rate_mthly",t);
}



//^^^

#line 1 "dth_claim_rate_mthly.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (decrements_defn == NO)
	return NO_AVG;

if (fabs(policies_b(t)) < model_point_amount_threshold)
	return NO_AVG;
	
if (t + elapsed_mths > term_to_omega_age * 12)
	return 1.0;

return dth_rate_mthly_crbg(t);

/*if (xint(pol_mth(t)) == 1 || t == commencement_period + 1)
	{
	return mort_rate_exp(t);
	}

// rate only calculated once per policy year 
return dth_claim_rate_mthly(t - 1);*/

}

//@@ END

//@@ START - dth_rate_female_crbg
// Dth Rate Female Crbg                                                                                             
// Column:DTH_RATE_FEMALE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_dth_rate_female_crbg(int t) {
//^^^



//^^^

#line 1 "dth_rate_female_crbg.FIA_LIAB.for"
//20250430 Customized column 
if (t < start_period || t > t_high)
	return NO_AVG;

int pol_yr = int((t + elapsed_mths - 1) / 12.0 + 1);

if (enhanced_income_ind_crbg == YES)
{
	int confined_status = enh_inc_confined_status_female_crbg(t);
	int confined_mth    = enh_inc_confined_mth_female_crbg(t);
	int confined_yr = int((t - confined_mth + 1) / 12.0 + 1);
	int confined_age = issue_age_female_crbg + confined_yr - 1;

	return dth_rate_confinement_calc_crbg(t, pol_yr, FEMALE, confined_status, confined_age, confined_mth);
}

return dth_rate_calc_crbg(t, pol_yr, FEMALE);

}

//@@ END

//@@ START - dth_rate_male_crbg
// Dth Rate Male Crbg                                                                                             
// Column:DTH_RATE_MALE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_dth_rate_male_crbg(int t) {
//^^^



//^^^

#line 1 "dth_rate_male_crbg.FIA_LIAB.for"
//20250430 Customized column 
if (t < start_period || t > t_high)
	return NO_AVG;

int pol_yr = int((t + elapsed_mths - 1) / 12.0 + 1);

if (enhanced_income_ind_crbg == YES)
{
	int confined_status = enh_inc_confined_status_male_crbg(t);
	int confined_mth    = enh_inc_confined_mth_male_crbg(t);
	int confined_yr = int((t - confined_mth + 1) / 12.0 + 1);
	int confined_age = issue_age_male_crbg + confined_yr - 1;

	return dth_rate_confinement_calc_crbg(t, pol_yr, MALE, confined_status, confined_age, confined_mth);
}

return dth_rate_calc_crbg(t, pol_yr, MALE);

}

//@@ END

//@@ START - dth_rate_mthly_blended_crbg
// Dth Rate Blended Crbg                                                                                             
// Column:DTH_RATE_MTHLY_BLENDED_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_dth_rate_mthly_blended_crbg(int t) {
//^^^



//^^^

#line 1 "dth_rate_mthly_blended_crbg.FIA_LIAB.for"
//20250430 Customized column 
if (t < start_period || t > maturity_period)
	return NO_AVG;

double mort_rate = male_sex_pct * dth_rate_calc_crbg(t, pol_yr(t), MALE)
				+ (1.0 - male_sex_pct) * dth_rate_calc_crbg(t, pol_yr(t), FEMALE);

mort_rate = max(0.0, min(1.0, mort_rate * mort_adj_mult));			
		
mort_rate = convert_decrem_rate_basis(mort_rate, EFFECTIVE_ANNUAL, -12);

return mort_rate;

}

//@@ END

//@@ START - dth_rate_mthly_crbg
// Dth Claim Rate Mthly Crbg                                                                                             
// Column:DTH_RATE_MTHLY_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_dth_rate_mthly_crbg(int t) {
//^^^



//^^^

#line 1 "dth_rate_mthly_crbg.FIA_LIAB.for"
//20250430 Customized column copied from prior IA model
if (t < start_period || t > maturity_period)
	return NO_AVG;

double mort_rate;

if (gender_mp == BLENDED)
{
	return dth_rate_mthly_blended_crbg(t);
}

StrEnum::EnumValue gender_cv;

if (gender_mp == gender_aft_inc || pol_yr(t) <= gmwb_exercise_yrs_crbg(t))
	gender_cv = gender_mp;
else
	gender_cv = gender_aft_inc;

if (gender_cv == MALE)
{
	mort_rate = dth_rate_mthly_male_crbg(t);
}
else if (gender_cv == FEMALE)
{
	mort_rate = dth_rate_mthly_female_crbg(t);
}
else if (gender_cv == JOINT)
{
	mort_rate = dth_rate_mthly_last_survivor_crbg(t);
}

return mort_rate;

}

//@@ END

//@@ START - dth_rate_mthly_female_crbg
// Dth Rate Female mthly                                                                                             
// Column:DTH_RATE_MTHLY_FEMALE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_dth_rate_mthly_female_crbg(int t) {
//^^^



//^^^

#line 1 "dth_rate_mthly_female_crbg.FIA_LIAB.for"
//20250430 Customized column 
if (t < start_period || t > t_high)
	return NO_AVG;

double mort_rate = dth_rate_female_crbg(t);

mort_rate = max(0.0, min(1.0, mort_rate * mort_adj_mult));			
		
mort_rate = convert_decrem_rate_basis(mort_rate, EFFECTIVE_ANNUAL, -12);

return mort_rate;

}

//@@ END

//@@ START - dth_rate_mthly_last_survivor_crbg
// Dth Rate Mthly Last Survivor Crbg                                                                                             
// Column:DTH_RATE_MTHLY_LAST_SURVIVOR_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_dth_rate_mthly_last_survivor_crbg(int t) {
//^^^



//^^^

#line 1 "dth_rate_mthly_last_survivor_crbg.FIA_LIAB.for"
//20250501 CRBG customized column
if (t < start_period || t > maturity_period)
	return NO_AVG;

if ( t + elapsed_mths == 0 )
{
	return 0.0;
}

double policies_joint_bom = policies_last_survivor_inf_crbg(t - 1);
double policies_joint_eom = policies_last_survivor_inf_crbg(t);

double qxy;

if (policies_joint_bom > SMALL_DOUBLE)
{
	qxy = 1.0 - ( policies_joint_eom / policies_joint_bom );
}
else
{
	qxy = 1.0;
}

return qxy;

}

//@@ END

//@@ START - dth_rate_mthly_male_crbg
// Dth Rate Male mthly                                                                                             
// Column:DTH_RATE_MTHLY_MALE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_dth_rate_mthly_male_crbg(int t) {
//^^^



//^^^

#line 1 "dth_rate_mthly_male_crbg.FIA_LIAB.for"
//20250430 Customized column 
if (t < start_period || t > t_high)
	return NO_AVG;

double mort_rate = dth_rate_male_crbg(t);

mort_rate = max(0.0, min(1.0, mort_rate * mort_adj_mult));			
		
mort_rate = convert_decrem_rate_basis(mort_rate, EFFECTIVE_ANNUAL, -12);

return mort_rate;

}

//@@ END

//@@ START - earnings_accum
// Accumulated Earnings                                                                                             
// Column:EARNINGS_ACCUM
//========================================================
double FIA_LIAB_UDF::fia_liab_earnings_accum(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(79,"earnings_accum",t);
}



//^^^

#line 1 "earnings_accum.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!pricing_flag)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_earnings_accum;

	return NO_AVG;
	}

double distrib_earnings = 0.0;

if (cal_mth(t) == 12 || last_period_indicator(t)
	|| (prof_distribn_mode == QUARTERLY 
         && (xint(cal_mth(t)) % 3 == 0))
	|| prof_distribn_mode == MONTHLY)
	distrib_earnings = undistrib_earnings(t - 1)
					   + bk_prof_aft_tax(t)
					   + tgt_cap_effect(t);

return earnings_accum(t - 1)
	   + distrib_earnings
	   + inv_inc_earnings_accum(t)
	   - tax_earnings_accum(t);

}

//@@ END

//@@ START - enh_inc_confined_mth_female_crbg
// Enh Inc Confined Mth Female Crbg                                                                                             
// Column:ENH_INC_CONFINED_MTH_FEMALE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_enh_inc_confined_mth_female_crbg(int t) {
//^^^



//^^^

#line 1 "enh_inc_confined_mth_female_crbg.FIA_LIAB.for"
//20250630 Customized column: EOM calculation
if (t < start_period || t > final_period)
	return NO_AVG;

if (enhanced_income_ind_crbg == NO || !(gender_mp == FEMALE || gender_mp == JOINT))
	return NO_AVG;

int confined_status = enh_inc_confined_status_female_crbg(t);

if (confined_status == 0)
{
	return 0;
}
else
{
	return enh_inc_confined_mth_female_crbg(t - 1) + 1;
}

}

//@@ END

//@@ START - enh_inc_confined_mth_male_crbg
// Enh Inc Confined Mth Male Crbg                                                                                             
// Column:ENH_INC_CONFINED_MTH_MALE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_enh_inc_confined_mth_male_crbg(int t) {
//^^^



//^^^

#line 1 "enh_inc_confined_mth_male_crbg.FIA_LIAB.for"
//20250630 Customized column: EOM calculation
if (t < start_period || t > final_period)
	return NO_AVG;

if (enhanced_income_ind_crbg == NO || !(gender_mp == MALE || gender_mp == JOINT))
	return NO_AVG;

int confined_status = enh_inc_confined_status_male_crbg(t);

if (confined_status == 0)
{
	return 0;
}
else
{
	return enh_inc_confined_mth_male_crbg(t - 1) + 1;
}

}

//@@ END

//@@ START - enh_inc_confined_status_aggr_crbg
// Enh Inc Confined Status AGGr Crbg                                                                                             
// Column:ENH_INC_CONFINED_STATUS_AGGR_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_enh_inc_confined_status_aggr_crbg(int t) {
//^^^



//^^^

#line 1 "enh_inc_confined_status_aggr_crbg.FIA_LIAB.for"
//20250630 Customized column: This is BOM calculaton
if (t < start_period || t > final_period)
	return NO_AVG;

if (enhanced_income_ind_crbg == NO)
	return NO_AVG;

int confinement_flag;

if (xint(enh_inc_confined_status_male_crbg(t)) || xint(enh_inc_confined_status_female_crbg(t)))
{
	confinement_flag = 1;
}
else
{
	confinement_flag = 0;
}

return confinement_flag;



}

//@@ END

//@@ START - enh_inc_confined_status_female_crbg
// Enh Inc Confined Status Female Crbg                                                                                             
// Column:ENH_INC_CONFINED_STATUS_FEMALE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_enh_inc_confined_status_female_crbg(int t) {
//^^^



//^^^

#line 1 "enh_inc_confined_status_female_crbg.FIA_LIAB.for"
//20250630 Customized column: This is BOM calculaton
if (t < start_period || t > final_period)
	return NO_AVG;

if (enhanced_income_ind_crbg == NO || !(gender_mp == FEMALE || gender_mp == JOINT))
	return NO_AVG;

int confinement_flag;

if (xint(pol_mth(t)) == 1)
{
	double random_draw = enh_inc_rand_female_crbg(t);

	int confined_status = enh_inc_confined_status_female_crbg(t - 1);

	if (confined_status == 1)
	{
		int confinement_mths = enh_inc_confined_mth_female_crbg(t - 1);
		confinement_yrs_crbg = int((t - confinement_mths) / 12.0 + 1);
		confinement_age_crbg = issue_age_female_crbg + confinement_yrs_crbg - 1;
		mort_gender = FEMALE;
		double recovery_rate = confinement_recovery_crbg;
		recovery_rate = min(1.0, recovery_rate * confinement_recovery_mult_aig);

		if (random_draw <= recovery_rate)
			confinement_flag = 0;
		else
			confinement_flag = 1;
	}
	else //(confined_status == 0)
	{
		mort_issue_age = issue_age_female_crbg;
		mort_gender = FEMALE;
		mort_pol_yr = pol_yr(t);
		double incidence_rate = confinement_incidence_crbg;

		if (random_draw <= incidence_rate)
			confinement_flag = 1;
		else
			confinement_flag = 0;
	}

	return confinement_flag;
}

return enh_inc_confined_status_female_crbg(t - 1);

}

//@@ END

//@@ START - enh_inc_confined_status_male_crbg
// Enh Inc Confined Status Male Crbg                                                                                             
// Column:ENH_INC_CONFINED_STATUS_MALE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_enh_inc_confined_status_male_crbg(int t) {
//^^^



//^^^

#line 1 "enh_inc_confined_status_male_crbg.FIA_LIAB.for"
//20250630 Customized column: This is BOM calculaton
if (t < start_period || t > final_period)
	return NO_AVG;

if (enhanced_income_ind_crbg == NO || !(gender_mp == MALE || gender_mp == JOINT))
	return NO_AVG;

int confinement_flag;

if (xint(pol_mth(t)) == 1)
{
	double random_draw = enh_inc_rand_male_crbg(t);

	int confined_status = enh_inc_confined_status_male_crbg(t - 1);

	if (confined_status == 1)
	{
		int confinement_mths = enh_inc_confined_mth_male_crbg(t - 1);
		confinement_yrs_crbg = int((t - confinement_mths) / 12.0 + 1);
		confinement_age_crbg = issue_age_male_crbg + confinement_yrs_crbg - 1;
		mort_gender = MALE;
		double recovery_rate = confinement_recovery_crbg;
		recovery_rate = min(1.0, recovery_rate * confinement_recovery_mult_aig);

		if (random_draw <= recovery_rate)
			confinement_flag = 0;
		else
			confinement_flag = 1;
	}
	else //(confined_status == 0)
	{
		mort_issue_age = issue_age_male_crbg;
		mort_gender = MALE;
		mort_pol_yr = pol_yr(t);
		double incidence_rate = confinement_incidence_crbg;

		if (random_draw <= incidence_rate)
			confinement_flag = 1;
		else
			confinement_flag = 0;
	}

	return confinement_flag;
}

return enh_inc_confined_status_male_crbg(t - 1);

}

//@@ END

//@@ START - enh_inc_eligibility_flag_crbg
// Enh Inc eligibility flag                                                                                             
// Column:ENH_INC_ELIGIBILITY_FLAG_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_enh_inc_eligibility_flag_crbg(int t) {
//^^^



//^^^

#line 1 "enh_inc_eligibility_flag_crbg.FIA_LIAB.for"
//20250701 Customized column: This is BOM calculaton
if (t < start_period || t > maturity_period)
	return NO_AVG;

if (enhanced_income_ind_crbg == NO)
	return NO_AVG;

if (t + elapsed_mths == 0)
	return 0.;

if (pol_yr(t) > enh_inc_wait_period &&
	xint(enh_inc_confined_status_aggr_crbg(t)) == 1 &&
	enh_inc_exercise_cumul_yrs_crbg(t) < enh_inc_max_cumul_yrs &&
	fund_val_b_bef(t) > SMALL_DOUBLE)
{
	return 1.;
}

return 0.;

}

//@@ END

//@@ START - enh_inc_exercise_cumul_yrs_crbg
// Enh Inc Exercise Cumul Yrs Crbg                                                                                             
// Column:ENH_INC_EXERCISE_CUMUL_YRS_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_enh_inc_exercise_cumul_yrs_crbg(int t) {
//^^^



//^^^

#line 1 "enh_inc_exercise_cumul_yrs_crbg.FIA_LIAB.for"
//20250701 Customized column: This is BOM calculaton
if (t < start_period || t > maturity_period)
	return NO_AVG;

if (enhanced_income_ind_crbg == NO)
	return NO_AVG;

if (t + elapsed_mths == 0)
	return 0.;

int cumul_benefit_yrs;

if (xint(pol_mth(t)) == 1)
{
	int enh_inc_exercise = enh_inc_exercise_flag_crbg(t - 1);
	int enh_inc_indirect_exercise = enh_inc_indirect_exercise_crbg(t - 1);

	if (enh_inc_exercise == 1 || enh_inc_indirect_exercise == 1)
	{
		cumul_benefit_yrs = enh_inc_exercise_cumul_yrs_crbg(t - 1) + 1;
	}
	else if (enh_inc_exercise == 0)
	{
		cumul_benefit_yrs = enh_inc_exercise_cumul_yrs_crbg(t - 1);
	}
	else
	{
		throw FatalError("Unhandled enhanced_income_benefit requested in enh_inc_exercise_cumul_yrs_crbg!");
	}
}
else
{
	cumul_benefit_yrs = enh_inc_exercise_cumul_yrs_crbg(t - 1);
}

return cumul_benefit_yrs;


}

//@@ END

//@@ START - enh_inc_exercise_flag_crbg
// Enh Inc exercise Flag                                                                                             
// Column:ENH_INC_EXERCISE_FLAG_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_enh_inc_exercise_flag_crbg(int t) {
//^^^



//^^^

#line 1 "enh_inc_exercise_flag_crbg.FIA_LIAB.for"
//20250701 Customized column: This is BOM calculaton
if (t < start_period || t > maturity_period)
	return NO_AVG;

if (enhanced_income_ind_crbg == NO)
	return NO_AVG;

if (t + elapsed_mths == 0)
	return 0.;

if ((pol_yr(t) <= gmwb_exercise_yrs && gmwb_wdl_trig_by_confinement == NO) || 
		gmwb_exercise_yrs >= 200 || //Do not exercise for non-withdrl cohort
		fund_val_b_bef(t) < SMALL_DOUBLE)
	return 0.;

int exercise_flag;

if (xint(pol_mth(t)) == 1)
{
	if (xint(enh_inc_eligibility_flag_crbg(t)) == 1 &&
		 ( (gmwb_wdl_util_type_crbg == RANDOM_UTIL && enh_inc_rand_exercise_crbg(t) < enh_inc_utilization_pct) ||
			gmwb_wdl_util_type_crbg == AVERAGE_UTIL) )
	{
		exercise_flag = 1;	
	}
	else 
	{
		exercise_flag = 0;
	}			
}
else
{
	exercise_flag = enh_inc_exercise_flag_crbg(t - 1);
}

return exercise_flag;


}

//@@ END

//@@ START - enh_inc_indirect_exercise_crbg
// Enh Inc Indirect Exercise Crbg                                                                                             
// Column:ENH_INC_INDIRECT_EXERCISE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_enh_inc_indirect_exercise_crbg(int t) {
//^^^



//^^^

#line 1 "enh_inc_indirect_exercise_crbg.FIA_LIAB.for"
//20250701 Customized column: This is BOM calculaton
if (t <= start_period || t > maturity_period)
	return NO_AVG;

if (enhanced_income_ind_crbg == NO)
	return NO_AVG;

if (xint(pol_mth(t)) == 1)
{
	return 0.;
}

if (enh_inc_confined_status_aggr_crbg(t) > SMALL_DOUBLE && gmwb_wdl_excess_ind_e_crbg(t - 1) > 0) //Accidentally trigger the benefit due to excess withdrawal
{
	return 1.;
}

return enh_inc_indirect_exercise_crbg(t - 1);

}

//@@ END

//@@ START - enh_inc_rand_exercise_crbg
// Enh Inc Rand exercise                                                                                             
// Column:ENH_INC_RAND_EXERCISE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_enh_inc_rand_exercise_crbg(int t) {
//^^^



//^^^

#line 1 "enh_inc_rand_exercise_crbg.FIA_LIAB.for"
//20250630 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (enhanced_income_ind_crbg == YES)
{
	double uniform_rv = uniform_rands_arr_crbg[3][t - 1];

	return uniform_rv;
}
else
	return NO_AVG;

}

//@@ END

//@@ START - enh_inc_rand_female_crbg
// Enh Inc Rand Female                                                                                             
// Column:ENH_INC_RAND_FEMALE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_enh_inc_rand_female_crbg(int t) {
//^^^



//^^^

#line 1 "enh_inc_rand_female_crbg.FIA_LIAB.for"
//20250630 New column with CRBG logic
if (t < start_period || t > final_period)
	return NO_AVG;

if (enhanced_income_ind_crbg == YES)
{
	double uniform_rv = uniform_rands_arr_crbg[1][t - 1];

	return uniform_rv;
}
else
	return NO_AVG;

}

//@@ END

//@@ START - enh_inc_rand_male_crbg
// Enh Inc Rand Male                                                                                             
// Column:ENH_INC_RAND_MALE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_enh_inc_rand_male_crbg(int t) {
//^^^



//^^^

#line 1 "enh_inc_rand_male_crbg.FIA_LIAB.for"
//20250630 New column with CRBG logic
if (t < start_period || t > final_period)
	return NO_AVG;

if (enhanced_income_ind_crbg == YES)
{
	double uniform_rv = uniform_rands_arr_crbg[0][t - 1];

	return uniform_rv;
}
else
	return NO_AVG;

}

//@@ END

//@@ START - eprs_sfc_ben_crbg
// EPRS SFC ben                                                                                             
// Column:EPRS_SFC_BEN_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_eprs_sfc_ben_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(92,"eprs_sfc_ben_crbg",t);
}



//^^^

#line 1 "eprs_sfc_ben_crbg.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->eprs_sfc_ben_crbg(t);	
		
return total;

}

//@@ END

//@@ START - eprs_sfc_ben_gross_crbg
// EPRS SFC gross ben                                                                                             
// Column:EPRS_SFC_BEN_GROSS_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_eprs_sfc_ben_gross_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(93,"eprs_sfc_ben_gross_crbg",t);
}



//^^^

#line 1 "eprs_sfc_ben_gross_crbg.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->eprs_sfc_ben_gross_crbg(t);	
		
return total;

}

//@@ END

//@@ START - eprs_strat_fee_partial_bef_crbg
// EPRS Charge partial                                                                                             
// Column:EPRS_STRAT_FEE_PARTIAL_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_eprs_strat_fee_partial_bef_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(94,"eprs_strat_fee_partial_bef_crbg",t);
}



//^^^

#line 1 "eprs_strat_fee_partial_bef_crbg.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->eprs_strat_fee_partial_bef_crbg(t);	
		
return total;

}

//@@ END

//@@ START - eprs_strat_fee_partial_e_crbg
// EPRS Charge partial                                                                                             
// Column:EPRS_STRAT_FEE_PARTIAL_E_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_eprs_strat_fee_partial_e_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(95,"eprs_strat_fee_partial_e_crbg",t);
}



//^^^

#line 1 "eprs_strat_fee_partial_e_crbg.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->eprs_strat_fee_partial_e_crbg(t);	
		
return total;

}

//@@ END

//@@ START - finalize
// Finalize                                                                                             
// Column:FINALIZE
//========================================================
double FIA_LIAB_UDF::fia_liab_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.FIA_LIAB.for"
if (time_step_flag && !valn_flag
	&& proj_set_sub_loop_num < valn_periods.size())	
	{
	write_state_of_world_mp();
	
	if (isMainModel && !valn_flag)
		{
		write_state_of_world_financial();
		
		for (int el = 0; el < sm_fia_sfas97rd.size(); el ++)
			sm_fia_sfas97rd[el]->finalize(t);
		}
	}		

return 1.0;

}

//@@ END

//@@ START - fund_released_ann
// Fund Released on Annuitization                                                                                             
// Column:FUND_RELEASED_ANN
//========================================================
double FIA_LIAB_UDF::fia_liab_fund_released_ann(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(97,"fund_released_ann",t);
}



//^^^

#line 1 "fund_released_ann.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->fund_released_ann(t);	
		
return total;

}

//@@ END

//@@ START - fund_released_dth
// Fund Released on Death                                                                                             
// Column:FUND_RELEASED_DTH
//========================================================
double FIA_LIAB_UDF::fia_liab_fund_released_dth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(98,"fund_released_dth",t);
}



//^^^

#line 1 "fund_released_dth.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->fund_released_dth(t);	
		
return total;

}

//@@ END

//@@ START - fund_released_maturity
// Fund Released on Maturity                                                                                             
// Column:FUND_RELEASED_MATURITY
//========================================================
double FIA_LIAB_UDF::fia_liab_fund_released_maturity(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(99,"fund_released_maturity",t);
}



//^^^

#line 1 "fund_released_maturity.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->fund_released_maturity(t);	
		
return total;

}

//@@ END

//@@ START - fund_released_surr
// Fund Released on Surrender                                                                                             
// Column:FUND_RELEASED_SURR
//========================================================
double FIA_LIAB_UDF::fia_liab_fund_released_surr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(100,"fund_released_surr",t);
}



//^^^

#line 1 "fund_released_surr.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->fund_released_surr(t);	
		
return total;

}

//@@ END

//@@ START - fund_released_withdrl
// Fund Released on Withdrawal                                                                                             
// Column:FUND_RELEASED_WITHDRL
//========================================================
double FIA_LIAB_UDF::fia_liab_fund_released_withdrl(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(101,"fund_released_withdrl",t);
}



//^^^

#line 1 "fund_released_withdrl.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->fund_released_withdrl(t);	
		
return total;

}

//@@ END

//@@ START - fund_val_b
// Fund Value After Outflow - BOM                                                                                             
// Column:FUND_VAL_B
//========================================================
double FIA_LIAB_UDF::fia_liab_fund_val_b(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(102,"fund_val_b",t);
}



//^^^

#line 1 "fund_val_b.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

//force_call
crediting_rate(t - 1); 

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->fund_val_b(t);	
		
return total;

}

//@@ END

//@@ START - fund_val_b_bef
// Fund Value Before Outflow BOM                                                                                             
// Column:FUND_VAL_B_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_fund_val_b_bef(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(103,"fund_val_b_bef",t);
}



//^^^

#line 1 "fund_val_b_bef.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->fund_val_b_bef(t);	
		
return total;

}

//@@ END

//@@ START - fund_val_boy_b_crbg
// fund_val_boy_b_crbg                                                                                             
// Column:FUND_VAL_BOY_B_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_fund_val_boy_b_crbg(int t) {
//^^^



//^^^

#line 1 "fund_val_boy_b_crbg.FIA_LIAB.for"
//20250502 New column with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double fund_val_cv;

if (xint(pol_mth(t)) == 1)
{
	fund_val_cv = fund_val_b(t);
}
else
{
	fund_val_cv = fund_val_boy_e_crbg(t - 1);
}

return fund_val_cv;

}

//@@ END

//@@ START - fund_val_boy_e_crbg
// Fund Val Boy E Crbg                                                                                             
// Column:FUND_VAL_BOY_E_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_fund_val_boy_e_crbg(int t) {
//^^^



//^^^

#line 1 "fund_val_boy_e_crbg.FIA_LIAB.for"
//20250502 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == 0 && valn_period > 0)
{
	return init_fund_val_boy;
}

double fund_val_cv = fund_val_boy_b_crbg(t) * surv_period(t);

return fund_val_cv;

}

//@@ END

//@@ START - fund_val_decrem
// Fund Value Decrement Amount                                                                                             
// Column:FUND_VAL_DECREM
//========================================================
double FIA_LIAB_UDF::fia_liab_fund_val_decrem(int t) {
//^^^



//^^^

#line 1 "fund_val_decrem.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->fund_val_decrem(t);	
		
return total;

}

//@@ END

//@@ START - fund_val_e_bef
// Fund Value Before Outflow EOM                                                                                             
// Column:FUND_VAL_E_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_fund_val_e_bef(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(107,"fund_val_e_bef",t);
}



//^^^

#line 1 "fund_val_e_bef.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->fund_val_e_bef(t);	
		
return total;

}

//@@ END

//@@ START - fund_val_fixed
// Fund Value End of Month                                                                                             
// Column:FUND_VAL_FIXED
//========================================================
double FIA_LIAB_UDF::fia_liab_fund_val_fixed(int t) {
//^^^



//^^^

#line 1 "fund_val_fixed.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->fund_val_e(t);	
		
return total;

}

//@@ END

//@@ START - gaap_acq_exp
// GAAP Acquisition Expenses                                                                                             
// Column:GAAP_ACQ_EXP
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_acq_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(109,"gaap_acq_exp",t);
}



//^^^

#line 1 "gaap_acq_exp.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->acq_exp(t);

}

//@@ END

//@@ START - gaap_ben_res
// GAAP Benefit Reserve                                                                                             
// Column:GAAP_BEN_RES
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_ben_res(int t) {
//^^^



//^^^

#line 1 "gaap_ben_res.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return 0.0;	

}

//@@ END

//@@ START - gaap_capzd_acq_exp
// GAAP Capitalized Acquisition Expenses                                                                                             
// Column:GAAP_CAPZD_ACQ_EXP
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_capzd_acq_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(111,"gaap_capzd_acq_exp",t);
}



//^^^

#line 1 "gaap_capzd_acq_exp.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->capzd_acq_exp(t);

}

//@@ END

//@@ START - gaap_capzd_comm_bom
// GAAP Capitalized Commissions BOM                                                                                             
// Column:GAAP_CAPZD_COMM_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_capzd_comm_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(112,"gaap_capzd_comm_bom",t);
}



//^^^

#line 1 "gaap_capzd_comm_bom.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->capzd_comm_bom(t);

}

//@@ END

//@@ START - gaap_capzd_comm_eom
// GAAP Capitalized Commissions EOM                                                                                             
// Column:GAAP_CAPZD_COMM_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_capzd_comm_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(113,"gaap_capzd_comm_eom",t);
}



//^^^

#line 1 "gaap_capzd_comm_eom.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->capzd_comm_eom(t);

}

//@@ END

//@@ START - gaap_capzd_prem_bonus
// GAAP Capitalized Premium Bonus                                                                                             
// Column:GAAP_CAPZD_PREM_BONUS
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_capzd_prem_bonus(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(114,"gaap_capzd_prem_bonus",t);
}



//^^^

#line 1 "gaap_capzd_prem_bonus.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->capzd_prem_bonus(t);

}

//@@ END

//@@ START - gaap_cash_flow_int
// GAAP Cash Flow Interest                                                                                             
// Column:GAAP_CASH_FLOW_INT
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_cash_flow_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(115,"gaap_cash_flow_int",t);
}



//^^^

#line 1 "gaap_cash_flow_int.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->cash_flow_int(t);

}

//@@ END

//@@ START - gaap_chg_inc
// GAAP Charges Income                                                                                             
// Column:GAAP_CHG_INC
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_chg_inc(int t) {
//^^^



//^^^

#line 1 "gaap_chg_inc.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->charges(t);

}

//@@ END

//@@ START - gaap_comm_excess_bom
// GAAP Commissions Excess BOM                                                                                             
// Column:GAAP_COMM_EXCESS_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_comm_excess_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(117,"gaap_comm_excess_bom",t);
}



//^^^

#line 1 "gaap_comm_excess_bom.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->comm_excess_bom(t);

}

//@@ END

//@@ START - gaap_comm_excess_eom
// GAAP Commissions Excess EOM                                                                                             
// Column:GAAP_COMM_EXCESS_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_comm_excess_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(118,"gaap_comm_excess_eom",t);
}



//^^^

#line 1 "gaap_comm_excess_eom.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->comm_excess_eom(t)
	   - sm_fia_sfas97rd[0]->comm_chargeback(t);

}

//@@ END

//@@ START - gaap_comm_trail_bom
// GAAP Commissions Trail BOM                                                                                             
// Column:GAAP_COMM_TRAIL_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_comm_trail_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(119,"gaap_comm_trail_bom",t);
}



//^^^

#line 1 "gaap_comm_trail_bom.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->comm_trail_bom(t);

}

//@@ END

//@@ START - gaap_comm_trail_eom
// GAAP Commissions Trail EOM                                                                                             
// Column:GAAP_COMM_TRAIL_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_comm_trail_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(120,"gaap_comm_trail_eom",t);
}



//^^^

#line 1 "gaap_comm_trail_eom.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->comm_trail_eom(t);

}

//@@ END

//@@ START - gaap_credited_int
// GAAP Credited Interest                                                                                             
// Column:GAAP_CREDITED_INT
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_credited_int(int t) {
//^^^



//^^^

#line 1 "gaap_credited_int.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->credited_int(t);

}

//@@ END

//@@ START - gaap_dac
// GAAP DAC                                                                                             
// Column:GAAP_DAC
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_dac(int t) {
//^^^



//^^^

#line 1 "gaap_dac.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return sm_fia_sfas97rd[0]->dac_acq_exp(t)
       + sm_fia_sfas97rd[0]->dac_comm(t)
       + sm_fia_sfas97rd[0]->dac_prem_bonus(t);

}

//@@ END

//@@ START - gaap_dac_incr
// GAAP DAC Increase                                                                                             
// Column:GAAP_DAC_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_dac_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(123,"gaap_dac_incr",t);
}



//^^^

#line 1 "gaap_dac_incr.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->dac_incr(t);

}

//@@ END

//@@ START - gaap_deferred_tax_liab
// GAAP Deferred Tax Liability                                                                                             
// Column:GAAP_DEFERRED_TAX_LIAB
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_deferred_tax_liab(int t) {
//^^^



//^^^

#line 1 "gaap_deferred_tax_liab.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	
	
double tax_rate = this->tax_rate;

return tax_rate
       * ((tax_res(t)
	        - reins_tax_res(t))
          - tax_capzd_prem_unamortzd(t)
          - (gaap_liab_net(t)
             - reins_gaap_liab_net(t)));

}

//@@ END

//@@ START - gaap_deferred_tax_liab_incr
// GAAP Deferred Tax Liability Increase                                                                                             
// Column:GAAP_DEFERRED_TAX_LIAB_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_deferred_tax_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(125,"gaap_deferred_tax_liab_incr",t);
}



//^^^

#line 1 "gaap_deferred_tax_liab_incr.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return gaap_deferred_tax_liab(t)
       - gaap_deferred_tax_liab(t - 1);

}

//@@ END

//@@ START - gaap_dth_claim_cost
// GAAP Death Claim Cost                                                                                             
// Column:GAAP_DTH_CLAIM_COST
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_dth_claim_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(126,"gaap_dth_claim_cost",t);
}



//^^^

#line 1 "gaap_dth_claim_cost.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->dth_claim_cost(t);

}

//@@ END

//@@ START - gaap_inc_aft_tax
// GAAP Income After Tax                                                                                             
// Column:GAAP_INC_AFT_TAX
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_inc_aft_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(127,"gaap_inc_aft_tax",t);
}



//^^^

#line 1 "gaap_inc_aft_tax.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

// Must call distrib_earnings for GAAP calculations
distrib_earnings(t);

return gaap_inc_bef_tax(t)
	   - (tax_bk_prof(t) + tax_tgt_cap(t))
       - gaap_deferred_tax_liab_incr(t);

}

//@@ END

//@@ START - gaap_inc_aft_tax_qtd
// GAAP Income After Tax Calendar Quarter to Date                                                                                             
// Column:GAAP_INC_AFT_TAX_QTD
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_inc_aft_tax_qtd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(128,"gaap_inc_aft_tax_qtd",t);
}



//^^^

#line 1 "gaap_inc_aft_tax_qtd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_gaap_inc_aft_tax_qtd;
		
	return NO_AVG;	
	}
		
if (xint(cal_mth(t)) % 3 == 1)
	return gaap_inc_aft_tax(t);

return gaap_inc_aft_tax_qtd(t - 1)
       + gaap_inc_aft_tax(t);

}

//@@ END

//@@ START - gaap_inc_aft_tax_ytd
// GAAP Income After Tax Calendar Year to Date                                                                                             
// Column:GAAP_INC_AFT_TAX_YTD
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_inc_aft_tax_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(129,"gaap_inc_aft_tax_ytd",t);
}



//^^^

#line 1 "gaap_inc_aft_tax_ytd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_gaap_inc_aft_tax_ytd;
		
	return NO_AVG;	
	}
	
if (cal_mth(t) == 1)
	return gaap_inc_aft_tax(t);

return gaap_inc_aft_tax_ytd(t - 1)
       + gaap_inc_aft_tax(t);

}

//@@ END

//@@ START - gaap_inc_bef_tax
// GAAP Income Before Tax                                                                                             
// Column:GAAP_INC_BEF_TAX
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_inc_bef_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(130,"gaap_inc_bef_tax",t);
}



//^^^

#line 1 "gaap_inc_bef_tax.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

//force calls for reporting
gaap_capzd_acq_exp(t);
gaap_capzd_comm_bom(t);
gaap_capzd_comm_eom(t);
gaap_capzd_prem_bonus(t);
double inv_inc = sm_fia_sfas97rd[0]->inv_inc(t);
	
return gaap_loads_deducted(t)
       + gaap_chg_inc(t)
       + gaap_surr_inc(t)
	   + gaap_cash_flow_int(t)
	   + gaap_inv_inc_res(t)
	   + gaap_inv_inc_cap(t)
	   - gaap_credited_int(t)
       - gaap_dth_claim_cost(t)
	   - gaap_mrb_liab_incr(t)
	   - gaap_sfas133_liab_incr(t)
	   - gaap_acq_exp(t)
	   - gaap_prem_bonus(t)
	   - gaap_comm_excess_bom(t)
	   - gaap_comm_excess_eom(t)
	   - gaap_comm_trail_bom(t)
	   - gaap_comm_trail_eom(t)
	   - gaap_maint_exp_bom(t)
	   - gaap_maint_exp_eom(t)
	   - gaap_prem_tax(t)
	   + gaap_dac_incr(t)
	   - reins_gaap_cost(t);

}

//@@ END

//@@ START - gaap_inc_bef_tax_qtd
// GAAP Income Before Tax Calendar Quarter to Date                                                                                             
// Column:GAAP_INC_BEF_TAX_QTD
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_inc_bef_tax_qtd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(131,"gaap_inc_bef_tax_qtd",t);
}



//^^^

#line 1 "gaap_inc_bef_tax_qtd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_gaap_inc_bef_tax_qtd;
		
	return NO_AVG;	
	}
	
if (xint(cal_mth(t)) % 3 == 1)
	return gaap_inc_bef_tax(t);

return gaap_inc_bef_tax_qtd(t - 1)
       + gaap_inc_bef_tax(t);

}

//@@ END

//@@ START - gaap_inc_bef_tax_ytd
// GAAP Income Before Tax Calendar Year to Date                                                                                             
// Column:GAAP_INC_BEF_TAX_YTD
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_inc_bef_tax_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(132,"gaap_inc_bef_tax_ytd",t);
}



//^^^

#line 1 "gaap_inc_bef_tax_ytd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_gaap_inc_bef_tax_ytd;
		
	return NO_AVG;	
	}
	
if (cal_mth(t) == 1)
	return gaap_inc_bef_tax(t);

return gaap_inc_bef_tax_ytd(t - 1)
       + gaap_inc_bef_tax(t);

}

//@@ END

//@@ START - gaap_inv_asset
// GAAP Invested Assets                                                                                             
// Column:GAAP_INV_ASSET
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_inv_asset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(133,"gaap_inv_asset",t);
}



//^^^

#line 1 "gaap_inv_asset.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return inv_asset(t);

}

//@@ END

//@@ START - gaap_inv_inc_cap
// GAAP Investment Income on Capital                                                                                             
// Column:GAAP_INV_INC_CAP
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_inv_inc_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(134,"gaap_inv_inc_cap",t);
}



//^^^

#line 1 "gaap_inv_inc_cap.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

gaap_surp_incr(t);

return inv_inc_res(t) 
       + inv_inc_undistrib_earnings(t) 
       - reins_inv_inc_res(t)
	   + inv_inc_tgt_cap(t)
       - gaap_inv_inc_res(t)
       + reins_gaap_inv_inc_res(t) ;

}

//@@ END

//@@ START - gaap_inv_inc_res
// GAAP Investment Income on Reserves                                                                                             
// Column:GAAP_INV_INC_RES
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_inv_inc_res(int t) {
//^^^



//^^^

#line 1 "gaap_inv_inc_res.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return gaap_liab_net(t - 1)
       * (pow((1.0 + asset_yld(t)), (1.0 / 12.0)) - 1.0);

}

//@@ END

//@@ START - gaap_liab_net
// GAAP Liability Net of DAC                                                                                             
// Column:GAAP_LIAB_NET
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_liab_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(136,"gaap_liab_net",t);
}



//^^^

#line 1 "gaap_liab_net.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

// force call gaap_inv_asset for reporting
gaap_inv_asset(t);

return gaap_ben_res(t)
	   + gaap_mrb_liab(t)
	   + gaap_sfas133_liab(t)
	   - gaap_dac(t);

}

//@@ END

//@@ START - gaap_loads_deducted
// GAAP Loads Deducted                                                                                             
// Column:GAAP_LOADS_DEDUCTED
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_loads_deducted(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(137,"gaap_loads_deducted",t);
}



//^^^

#line 1 "gaap_loads_deducted.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->loads(t);

}

//@@ END

//@@ START - gaap_maint_exp_bom
// GAAP Maintenance Expenses BOM                                                                                             
// Column:GAAP_MAINT_EXP_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(138,"gaap_maint_exp_bom",t);
}



//^^^

#line 1 "gaap_maint_exp_bom.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->maint_exp_bom(t);

}

//@@ END

//@@ START - gaap_maint_exp_eom
// GAAP Maintenance Expenses EOM                                                                                             
// Column:GAAP_MAINT_EXP_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_maint_exp_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(139,"gaap_maint_exp_eom",t);
}



//^^^

#line 1 "gaap_maint_exp_eom.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->maint_exp_eom(t);

}

//@@ END

//@@ START - gaap_mrb_liab
// GAAP Market Risk Benefits Liability                                                                                             
// Column:GAAP_MRB_LIAB
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_mrb_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(140,"gaap_mrb_liab",t);
}



//^^^

#line 1 "gaap_mrb_liab.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return sm_fia_sfas97rd[0]->mrb_liab(t);

}

//@@ END

//@@ START - gaap_mrb_liab_incr
// GAAP Market Risk Benefits Liability Increase                                                                                             
// Column:GAAP_MRB_LIAB_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_mrb_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(141,"gaap_mrb_liab_incr",t);
}



//^^^

#line 1 "gaap_mrb_liab_incr.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->mrb_liab_incr(t);

}

//@@ END

//@@ START - gaap_prem_bonus
// GAAP Premium Bonus                                                                                             
// Column:GAAP_PREM_BONUS
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_prem_bonus(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(142,"gaap_prem_bonus",t);
}



//^^^

#line 1 "gaap_prem_bonus.FIA_LIAB.for"
if (t <= start_period || t > maturity_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->prem_bonus(t);

}

//@@ END

//@@ START - gaap_prem_tax
// GAAP Premium Taxes                                                                                             
// Column:GAAP_PREM_TAX
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(143,"gaap_prem_tax",t);
}



//^^^

#line 1 "gaap_prem_tax.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->prem_tax(t);

}

//@@ END

//@@ START - gaap_prof_aft_tax_for_pv
// GAAP Profit After Tax for Present Values                                                                                             
// Column:GAAP_PROF_AFT_TAX_FOR_PV
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_prof_aft_tax_for_pv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(144,"gaap_prof_aft_tax_for_pv",t);
}



//^^^

#line 1 "gaap_prof_aft_tax_for_pv.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (prof_distribn_mode == MONTHLY)
	return gaap_inc_aft_tax(t);
	
if (prof_distribn_mode == QUARTERLY
	&& (xint(cal_mth(t)) % 3 == 0
		|| t == final_period))
	return gaap_inc_aft_tax_qtd(t);
	
if (prof_distribn_mode == ANNUAL
	&& (cal_mth(t) == 12
		|| t == final_period))
	return gaap_inc_aft_tax_ytd(t);				

return 0.0;

}

//@@ END

//@@ START - gaap_prof_bef_tax_for_pv
// GAAP Profit Before Tax for Present Values                                                                                             
// Column:GAAP_PROF_BEF_TAX_FOR_PV
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_prof_bef_tax_for_pv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(145,"gaap_prof_bef_tax_for_pv",t);
}



//^^^

#line 1 "gaap_prof_bef_tax_for_pv.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (prof_distribn_mode == MONTHLY)
	return gaap_inc_bef_tax(t);
	
if (prof_distribn_mode == QUARTERLY
	&& (xint(cal_mth(t)) % 3 == 0
		|| t == final_period))
	return gaap_inc_bef_tax_qtd(t);
	
if (prof_distribn_mode == ANNUAL
	&& (cal_mth(t) == 12
		|| t == final_period))
	return gaap_inc_bef_tax_ytd(t);				

return 0.0;

}

//@@ END

//@@ START - gaap_req_cap
// GAAP Required Capital                                                                                             
// Column:GAAP_REQ_CAP
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_req_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(146,"gaap_req_cap",t);
}



//^^^

#line 1 "gaap_req_cap.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (t == start_period)
	{
	return gaap_inv_asset(t)
           - (gaap_liab_net(t)
              - reins_gaap_liab_net(t))
           - gaap_deferred_tax_liab(t);
	}

return gaap_req_cap(t - 1)
	   + gaap_surp_incr(t);

}

//@@ END

//@@ START - gaap_sfas133_liab
// GAAP SFAS 133 Liability                                                                                             
// Column:GAAP_SFAS133_LIAB
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_sfas133_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(147,"gaap_sfas133_liab",t);
}



//^^^

#line 1 "gaap_sfas133_liab.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return sm_fia_sfas97rd[0]->sfas133_liab(t);

}

//@@ END

//@@ START - gaap_sfas133_liab_incr
// GAAP SFAS 133 Liability Increase                                                                                             
// Column:GAAP_SFAS133_LIAB_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_sfas133_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(148,"gaap_sfas133_liab_incr",t);
}



//^^^

#line 1 "gaap_sfas133_liab_incr.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->sfas133_liab_incr(t);

}

//@@ END

//@@ START - gaap_surp_incr
// GAAP Surplus Increase                                                                                             
// Column:GAAP_SURP_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_surp_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(149,"gaap_surp_incr",t);
}



//^^^

#line 1 "gaap_surp_incr.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return (gaap_inv_asset(t)
        - (gaap_liab_net(t)
           - reins_gaap_liab_net(t))
        - gaap_deferred_tax_liab(t))
        - gaap_req_cap(t - 1);

}

//@@ END

//@@ START - gaap_surr_inc
// GAAP Surrender Income                                                                                             
// Column:GAAP_SURR_INC
//========================================================
double FIA_LIAB_UDF::fia_liab_gaap_surr_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(150,"gaap_surr_inc",t);
}



//^^^

#line 1 "gaap_surr_inc.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

return sm_fia_sfas97rd[0]->egp_gain_surr(t);

}

//@@ END

//@@ START - gmab_chg_crbg
// Gmab Chg Crbg                                                                                             
// Column:GMAB_CHG_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmab_chg_crbg(int t) {
//^^^



//^^^

#line 1 "gmab_chg_crbg.FIA_LIAB.for"
//20251211 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->gmab_chg_crbg(t);	
		
return total;

}

//@@ END

//@@ START - gmab_chg_partial_e_bef_crbg
// Gmab Chg Crbg                                                                                             
// Column:GMAB_CHG_PARTIAL_E_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmab_chg_partial_e_bef_crbg(int t) {
//^^^



//^^^

#line 1 "gmab_chg_partial_e_bef_crbg.FIA_LIAB.for"
//20251211 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->gmab_chg_partial_e_bef_crbg(t);	
		
return total;

}

//@@ END

//@@ START - gmab_chg_partial_e_crbg
// Gmab Chg Crbg                                                                                             
// Column:GMAB_CHG_PARTIAL_E_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmab_chg_partial_e_crbg(int t) {
//^^^



//^^^

#line 1 "gmab_chg_partial_e_crbg.FIA_LIAB.for"
//20251211 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->gmab_chg_partial_e_bef_crbg(t);	
		
return total;

}

//@@ END

//@@ START - gmab_global_payoff_crbg
// Gmab Global Payoff Crbg                                                                                             
// Column:GMAB_GLOBAL_PAYOFF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmab_global_payoff_crbg(int t) {
//^^^



//^^^

#line 1 "gmab_global_payoff_crbg.FIA_LIAB.for"
//20251211 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->gmab_global_payoff_crbg(t);	
		
return total;

}

//@@ END

//@@ START - gmab_payoff_crbg
// Gmab Payoff Crbg                                                                                             
// Column:GMAB_PAYOFF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmab_payoff_crbg(int t) {
//^^^



//^^^

#line 1 "gmab_payoff_crbg.FIA_LIAB.for"
//20251211 New columns with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->gmab_payoff_crbg(t);	
		
return total;

}

//@@ END

//@@ START - gmwb_chg
// GMWB Charge                                                                                             
// Column:GMWB_CHG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_chg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(156,"gmwb_chg",t);
}



//^^^

#line 1 "gmwb_chg.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->gmwb_chg(t);	
		
return total;

}

//@@ END

//@@ START - gmwb_chg_partial_bef_crbg
// GMWB Charge partial                                                                                             
// Column:GMWB_CHG_PARTIAL_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_chg_partial_bef_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(157,"gmwb_chg_partial_bef_crbg",t);
}



//^^^

#line 1 "gmwb_chg_partial_bef_crbg.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->gmwb_chg_partial_bef_crbg(t);	
		
return total;

}

//@@ END

//@@ START - gmwb_chg_partial_e_crbg
// GMWB Charge partial                                                                                             
// Column:GMWB_CHG_PARTIAL_E_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_chg_partial_e_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(158,"gmwb_chg_partial_e_crbg",t);
}



//^^^

#line 1 "gmwb_chg_partial_e_crbg.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->gmwb_chg_partial_e_crbg(t);	
		
return total;

}

//@@ END

//@@ START - gmwb_entitlement_remaining_b_crbg
// Gmwb Entitlement Remaining BOM                                                                                             
// Column:GMWB_ENTITLEMENT_REMAINING_B_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_entitlement_remaining_b_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_entitlement_remaining_b_crbg.FIA_LIAB.for"
//20250505 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag)
	return NO_AVG;

double entitlement_cv = 0.0;

if (pol_mth(t) == 1)
{
	entitlement_cv			= gmwb_max_wdl_amt(t);

	/*double mawa_floor_cv	= gmwb_mawa_floor_e_bef_aig(t);
	entitlement_cv			= max(mawa_floor_cv, entitlement_cv);*/
}
else
{
	entitlement_cv = gmwb_entitlement_remaining_e_crbg(t - 1);
}

return entitlement_cv;

}

//@@ END

//@@ START - gmwb_entitlement_remaining_e_crbg
// Gmwb Entitlement Remaining E                                                                                             
// Column:GMWB_ENTITLEMENT_REMAINING_E_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_entitlement_remaining_e_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_entitlement_remaining_e_crbg.FIA_LIAB.for"
//20250505 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag)
	return NO_AVG;

if (t == 0 && valn_period != 0) 
	return init_gmwb_entitlement_remaining;

double wld_amt = gmwb_wdl_amt_e_bef_crbg(t);

double entitlement_cv = max(0, (gmwb_entitlement_remaining_b_crbg(t) - wld_amt) * surv_period(t));

return entitlement_cv;

}

//@@ END

//@@ START - gmwb_exercise_yrs_crbg
// Gmwb Exercise Yrs Crbg                                                                                             
// Column:GMWB_EXERCISE_YRS_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_exercise_yrs_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_exercise_yrs_crbg.FIA_LIAB.for"
//20250630 New column for CRBG logic
//This column takes into consideration the case of starting enhanced income when confined.
//It's ok to use gmwb_exercise_yrs when one of the following conditions is met: 
//(GLB flex is on, no withdrl cohort, not modeling confinement, or do not start income at confinement)

if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

if (gender_mp != gender_aft_inc || gmwb_exercise_yrs >= 200 
	|| enhanced_income_ind_crbg == NO || gmwb_wdl_trig_by_confinement == NO)
{
	return gmwb_exercise_yrs;
}

if (xint(pol_mth(t)) == 1)
{
	if (enh_inc_exercise_flag_crbg(t) == 1)
	{
		return min(pol_yr(t) - 1, gmwb_exercise_yrs_crbg(t - 1));
	}
	else
	{
		return gmwb_exercise_yrs_crbg(t - 1);
	}
}

return gmwb_exercise_yrs_crbg(t - 1);


}

//@@ END

//@@ START - gmwb_fund_val_inf
// GMWB Fund Value Base End of Month                                                                                             
// Column:GMWB_FUND_VAL_INF
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_fund_val_inf(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(162,"gmwb_fund_val_inf",t);
}



//^^^

#line 1 "gmwb_fund_val_inf.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag || gmwb_fund_val_defn == NOT_APPLICABLE)
	return NO_AVG;
	
if (t == commencement_period)
	{
	if (elapsed_mths > 0) 
		return init_gmwb_fund_val;
	
	// New Business
	return 0.0;
	}

if (gmwb_wdl_reduce_ben_base == YES)
    return max(0.0, gmwb_fund_val_inf_bef(t) * surv_period(t) - withdrl_benefits(t));

return max(0.0, gmwb_fund_val_inf_bef(t) * surv_period(t));

}

//@@ END

//@@ START - gmwb_fund_val_inf_bef
// GMWB Fund Value Base End of Month Before Claims                                                                                             
// Column:GMWB_FUND_VAL_INF_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_fund_val_inf_bef(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(163,"gmwb_fund_val_inf_bef",t);
}



//^^^

#line 1 "gmwb_fund_val_inf_bef.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag || gmwb_fund_val_defn == NOT_APPLICABLE)
	return NO_AVG;
	
// Sets the GMWB after reaching the maximum age
if (age_last(t) >= gmwb_max_age)
	return gmwb_fund_val_inf(t - 1);

if (ann_claims_gmwb(t - 1) > 0.0)
	return 0.0;

if (mod(t + elapsed_mths - 1, 12.0 * gmwb_fund_val_period) == 0)
	return max(gmwb_fund_val_inf(t - 1), 
	           fund_val_fixed(t - 1)) 
	       + prem_paid(t);

return gmwb_fund_val_inf(t - 1) 
       + prem_paid(t);

}

//@@ END

//@@ START - gmwb_income_base_b_bef_crbg
// GMWB Income Base Beg of Month                                                                                             
// Column:GMWB_INCOME_BASE_B_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_income_base_b_bef_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(164,"gmwb_income_base_b_bef_crbg",t);
}



//^^^

#line 1 "gmwb_income_base_b_bef_crbg.FIA_LIAB.for"
//20250502 Replaced with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag)
	return NO_AVG;

double gmwb_income_base = 0.0;

if (t + elapsed_mths > commencement_period + 1)
{	
	if (ny_glb_ind_crbg == YES)		
		gmwb_income_base = gmwb_income_base_e_crbg(t - 1);		
	else
		gmwb_income_base = gmwb_income_base_e_crbg(t - 1) + gmwb_income_credit_b_crbg(t);
}

return gmwb_income_base;

}

//@@ END

//@@ START - gmwb_income_base_b_crbg
// GMWB Income Base BOM after income credit                                                                                             
// Column:GMWB_INCOME_BASE_B_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_income_base_b_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(165,"gmwb_income_base_b_crbg",t);
}



//^^^

#line 1 "gmwb_income_base_b_crbg.FIA_LIAB.for"
//20250502 Replaced with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

double gmwb_income_base = gmwb_income_base_b_bef_crbg(t);

if (ny_glb_ind_crbg == YES)
{
	return gmwb_income_base;
}

// max of fund val
if (xint(pol_mth(t)) == 1 && gmwb_fund_val_defn != NOT_APPLICABLE)
{
	double fund_val = fund_val_fixed(t - 1);
	gmwb_income_base = max(gmwb_income_base, fund_val);	
}

//doubling
double gmwb_minimum_income_base = gmwb_min_income_base_bef_crbg(t);
gmwb_income_base = max(gmwb_income_base, gmwb_minimum_income_base);

return gmwb_income_base;

}

//@@ END

//@@ START - gmwb_income_base_e_bef_crbg
// GMWB Income Base End of Month Before Claims                                                                                             
// Column:GMWB_INCOME_BASE_E_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_income_base_e_bef_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(166,"gmwb_income_base_e_bef_crbg",t);
}



//^^^

#line 1 "gmwb_income_base_e_bef_crbg.FIA_LIAB.for"
//20250502 Replaced with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

if (ny_glb_ind_crbg == YES)
{
	if (t + elapsed_mths <= gmwb_exercise_yrs_crbg(t) * 12 + 1)
		return max(fund_val_e_bef(t), min_accum_val_e_bef_crbg(t)) ;
	else
		return gmwb_income_base_b_crbg(t);
}

if (t + elapsed_mths == 1)
{
	return prem_paid(t) * (1.0 + prem_credit);
}

return gmwb_income_base_b_crbg(t);

}

//@@ END

//@@ START - gmwb_income_base_e_crbg
// GMWB Income Base End of Month                                                                                             
// Column:GMWB_INCOME_BASE_E_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_income_base_e_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(167,"gmwb_income_base_e_crbg",t);
}



//^^^

#line 1 "gmwb_income_base_e_crbg.FIA_LIAB.for"
//20250502 Replaced with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag)
	return NO_AVG;
	
if (t == commencement_period)
	{
	if (elapsed_mths > 0) 
		return init_gmwb_prem;
	
	// New Business
	return 0.0;
	}

if (ny_glb_ind_crbg == YES && pol_yr(t) <= gmwb_exercise_yrs_crbg(t))
{
	return max(fund_val_fixed(t), min_accum_val_e_crbg(t));
}

double gmwb_income_base = gmwb_income_base_e_bef_crbg(t) * surv_period(t);

gmwb_income_base *= gmwb_income_base_reduction_fct_crbg(t); //reduced for excess withdrawal

return gmwb_income_base;


}

//@@ END

//@@ START - gmwb_income_base_reduction_fct_crbg
// Gmwb Income Base Reduction Fct Crbg                                                                                             
// Column:GMWB_INCOME_BASE_REDUCTION_FCT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_income_base_reduction_fct_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_income_base_reduction_fct_crbg.FIA_LIAB.for"
//20250506 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag)
	return NO_AVG;

double excess_wdl = gmwb_wdl_amt_excess_bef_crbg(t);

if (abs(excess_wdl) < SMALL_DOUBLE)
{
	return 1.0;
}

double max_mav_fund_val = max(fund_val_e_bef(t), min_accum_val_e_bef_crbg(t));
double mawa_remaining_e_bef_cv = gmwb_entitlement_remaining_b_crbg(t);
double base = max(0, max_mav_fund_val - mawa_remaining_e_bef_cv);

if (abs(base) < SMALL_DOUBLE)
{
	return 0.0;
}

double reduction_fct = max(0, 1 - excess_wdl / base);

return reduction_fct;

}

//@@ END

//@@ START - gmwb_income_credit_b_crbg
// GMWB Income Credit                                                                                             
// Column:GMWB_INCOME_CREDIT_B_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_income_credit_b_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(169,"gmwb_income_credit_b_crbg",t);
}



//^^^

#line 1 "gmwb_income_credit_b_crbg.FIA_LIAB.for"
//20250502 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag)
	return NO_AVG;

if (gmwb_wdl_excess_ind_e_crbg(t - 1) > SMALL_DOUBLE)
{
	return 0.0;
}

if (gmwb_credit_aft_income_crbg == ZERO && pol_yr(t) > gmwb_exercise_yrs_crbg(t) + 1)
{
	return 0.0;
}

double rollup_credit = 0.;

if (xint(pol_mth(t)) == 1 && pol_yr(t) <= gmwb_max_rollup_duration + 1 && fund_val_fixed(t - 1) > SMALL_DOUBLE)
{
	
	double gmwb_income_credit_base = gmwb_income_credit_base_e_crbg(t - 1);

	double gmwb_income_credit_rate = 0.;
	if (gmwb_rollup_credit_type_crbg == "Constant")
	{
		gmwb_income_credit_rate = gmwb_rollup_rate;
	}
	else //if (gmwb_rollup_credit_type_crbg == INDEX_GROWTH)
	{
		gmwb_income_credit_rate = crediting_rate_cumul_crbg(t - 1);
	}
		
	double gmwb_credit_mult = 1.;
	if (income_phase_bef_crbg(t) == 0)
		gmwb_credit_mult = gmwb_credit_mult_bef_inc_crbg;
	else
		gmwb_credit_mult = gmwb_credit_mult_aft_inc_crbg;

	if (gmwb_credit_aft_income_crbg == NET && pol_yr(t) > gmwb_exercise_yrs_crbg(t))
	{
		double mawp_rate = gmwb_max_ann_wdl_pct_crbg(t - 1);
		double utilization_rate = gmwb_wdl_util_pct_crbg(t - 1);

		gmwb_income_credit_rate -= mawp_rate * utilization_rate;

		gmwb_income_credit_rate = max(gmwb_income_credit_rate, 0.0);
	}

	rollup_credit = gmwb_income_credit_base * gmwb_income_credit_rate * gmwb_credit_mult; //rollup rate may vary before and after
}

return rollup_credit;

}

//@@ END

//@@ START - gmwb_income_credit_base_e_bef_crbg
// Gmwb Income Credit Base E Bef Crbg                                                                                             
// Column:GMWB_INCOME_CREDIT_BASE_E_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_income_credit_base_e_bef_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_income_credit_base_e_bef_crbg.FIA_LIAB.for"
//20250506 New column with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag)
	return NO_AVG;

if (t + elapsed_mths == 1)
{
	return prem_paid(t) * (1.0 + prem_credit);
}

double inc_credit_base = 0.0;
	
if (gmwb_rollup_rate_type == COMPOUND || 
	(gmwb_rollup_rate_type == SIMPLE_THEN_COMPOUND && income_phase_bef_crbg(t) == 1))
{
    inc_credit_base = gmwb_income_base_b_bef_crbg(t);
}
else // SIMPLE
{
    inc_credit_base = gmwb_income_credit_base_e_crbg(t - 1);
}


if (xint(pol_mth(t)) == 1 && income_phase_bef_crbg(t) == 0 && gmwb_fund_val_defn != NOT_APPLICABLE) //Highest anniversary value
{
	double fund_val = fund_val_fixed(t - 1);
	
	if (fund_val > gmwb_income_base_b_bef_crbg(t))
	{
		inc_credit_base = max(inc_credit_base, fund_val);
	}
}

return inc_credit_base;


}

//@@ END

//@@ START - gmwb_income_credit_base_e_crbg
// Gmwb Income Credit Base E Crbg                                                                                             
// Column:GMWB_INCOME_CREDIT_BASE_E_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_income_credit_base_e_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_income_credit_base_e_crbg.FIA_LIAB.for"
//20250506 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag)
	return NO_AVG;

if (t == 0 && valn_period > 0)
	return init_gmwb_income_credit_base;

double inc_credit_base = gmwb_income_credit_base_e_bef_crbg(t);

inc_credit_base *= gmwb_income_base_reduction_fct_crbg(t);

inc_credit_base *= surv_period(t);

return inc_credit_base;


}

//@@ END

//@@ START - gmwb_inf
// GMWB In Force End of Month                                                                                             
// Column:GMWB_INF
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_inf(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(172,"gmwb_inf",t);
}



//^^^

#line 1 "gmwb_inf.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

/*double gmwb_premium = gmwb_income_base_e_crbg(t);

if (gmwb_prem_defn == ROLLUP)
	gmwb_premium = min(gmwb_income_base_e_crbg(t), gmwb_rollup_cap_inf(t));

return max(gmwb_fund_val_inf(t), gmwb_premium);*/

double gmwb_inf = gmwb_income_base_e_crbg(t);

/*if (gmwb_inc_base_cap_crbg)
{
	double income_base_cap = prem_cumul(t) * gmwb_ib_cap_prem_pct_crbg;
	gmwb_inf = min(gmwb_inf_bef, income_base_cap);
}*/

return gmwb_inf;

}

//@@ END

//@@ START - gmwb_inf_bef
// GMWB In Force End of Month Before Claims                                                                                             
// Column:GMWB_INF_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_inf_bef(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(173,"gmwb_inf_bef",t);
}



//^^^

#line 1 "gmwb_inf_bef.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag)
	return NO_AVG;
	
/*if (gmwb_prem_defn == ROLLUP)
	gmwb_premium_bef = min(gmwb_income_base_e_bef_crbg(t), gmwb_rollup_cap_inf_bef(t));

return max(gmwb_fund_val_inf_bef(t), gmwb_premium_bef);*/

double gmwb_inf_bef = gmwb_income_base_e_bef_crbg(t);

/*if (gmwb_inc_base_cap_crbg)
{
	double income_base_cap = prem_cumul_bef(t) * gmwb_ib_cap_prem_pct_crbg;
	gmwb_inf_bef = min(gmwb_inf_bef, income_base_cap);
}*/

return gmwb_inf_bef;

}

//@@ END

//@@ START - gmwb_itm
// GMWB In The Money                                                                                             
// Column:GMWB_ITM
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_itm(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(174,"gmwb_itm",t);
}



//^^^

#line 1 "gmwb_itm.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

if (itm_defn == FUND_VALUE)
	{	
	if (fund_val_e_bef(t) > model_point_amount_threshold)	
		return gmwb_inf_bef(t) / fund_val_e_bef(t) - 1.0;

	return NO_AVG;	
	}
else //itm_type == ANNUITY_BENEFIT
	{
	if (fund_val_e_bef(t) < model_point_amount_threshold)
		return 1.0;

	if (itm_denom_defn_crbg == FUND_VAL)
		return pv_gmwb_ben_itm_current_crbg(t) / fund_val_e_bef(t) - 1.0;

	else // if ITM denominator is cash val
		return pv_gmwb_ben_itm_current_crbg(t) / cash_val_bef(t) - 1.0;
	}

}

//@@ END

//@@ START - gmwb_max_ann_wdl_pct_crbg
// Gmwb Max Annual Wdl Pct Crbg                                                                                             
// Column:GMWB_MAX_ANN_WDL_PCT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_max_ann_wdl_pct_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_max_ann_wdl_pct_crbg.FIA_LIAB.for"
//20250502 New column for CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

if (t == 0 && valn_period > 0)
	return init_gmwb_max_ann_wdl_pct;

double mawp = 0.;

int gmwb_withdrl_yr = gmwb_exercise_yrs_crbg(t) + 1;

if (mawp_lookup_type_crbg == WITHDRL_AGE)
{
	gmwb_withdrl_age = issue_age_col_crbg(t) + gmwb_withdrl_yr - 1;
	mawp = gmwb_max_annual_wdl_pct;
}

else if (mawp_lookup_type_crbg == ISSUE_AGE)
{
	gmwb_withdrl_age = issue_age_col_crbg(t);
	mawp = gmwb_max_annual_wdl_pct;

	gmwb_withdrl_yr_lookup = gmwb_withdrl_yr;
	mawp += gmwb_mawp_addn_crbg;

	//NY Reg47 logic
	int issue_age = issue_age_col_crbg(t);
	int withdrl_age = issue_age_col_crbg(t) + gmwb_withdrl_yr - 1;
	if (gmwb_reg47_crbg == YES && issue_age >= 55 && withdrl_age >= 65)
	{
		int age_diff_on_limit = min(issue_age - 55, withdrl_age - 65);
		int look_back_5yr_factor;

		if (age_diff_on_limit % 5 == 0 || age_diff_on_limit < 5)
			look_back_5yr_factor = ceil(age_diff_on_limit / 5.0) + 1;
		else
			look_back_5yr_factor = ceil(age_diff_on_limit / 5.0);

		int fisrt_lookup_age = withdrl_age - look_back_5yr_factor * 5; 
		for (int current_age = fisrt_lookup_age; current_age <= withdrl_age; current_age = current_age + 5)
		{
			int current_issue_age = current_age - gmwb_withdrl_yr + 1;		
			if (current_age < 65 || current_issue_age < 55)
			{
				gmwb_withdrl_age = current_issue_age;
				mawp = gmwb_max_annual_wdl_pct;

				gmwb_withdrl_yr_lookup = gmwb_withdrl_yr;
				mawp += gmwb_mawp_addn_crbg;
			}
			else
			{			
				gmwb_withdrl_age = current_age;
				double slope = gmwb_reg47_slope_crbg;	
				
				if (gmwb_withdrl_yr == 1)
					mawp = xround(ceil(xround((mawp * (1 + slope) * 2000), 5)) / 2000, 4); 
				else
					mawp = xround(ceil(xround((mawp * (1 + slope) * 10000), 5)) / 10000, 4);
			}
		} //End of the for loop
	}
}

if (xint(enh_inc_exercise_flag_crbg(t)) == 1)
{
	mawp *= enh_inc_mawp_mult;
}

return mawp;

}

//@@ END

//@@ START - gmwb_max_wdl_amt
// GMWB Guaranteed Maximum Withdrawal Amount                                                                                             
// Column:GMWB_MAX_WDL_AMT
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_max_wdl_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(176,"gmwb_max_wdl_amt",t);
}



//^^^

#line 1 "gmwb_max_wdl_amt.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

if (t == commencement_period && elapsed_mths > 0
	&& pol_yr(t) > gmwb_exercise_yrs_crbg(t))
	return init_gmwb_max_wdl_amt;

double curr_max_amt = 0.0;

if (gmwb_max_wdl_amt_base_defn == PREMIUM)
	{
	if (pol_yr(t) <= gmwb_exercise_yrs_crbg(t))
		curr_max_amt = 0.0;
	else if (pol_yr(t) == gmwb_exercise_yrs_crbg(t) + 1 
			 && pol_mth(t) == 1)
		curr_max_amt = gmwb_income_base_e_bef_crbg(t) * gmwb_max_ann_wdl_pct_crbg(t);
	else
		{
		if (t == commencement_period + 1 && elapsed_mths > 0)
			curr_max_amt = init_gmwb_max_wdl_amt
						   + prem_paid(t) * gmwb_max_ann_wdl_pct_crbg(t);

		else
			curr_max_amt = gmwb_max_wdl_amt(max(commencement_period, t - 1)) 
		   				   * surv_period(max(commencement_period, t - 1)) 
						   + prem_paid(t) * gmwb_max_ann_wdl_pct_crbg(t);
		}
	}
else if (gmwb_max_wdl_amt_base_defn == GMWB_BASE) 
	{
	if (pol_yr(t) <= gmwb_exercise_yrs_crbg(t))
		curr_max_amt = 0.0;
	else if (pol_yr(t) == gmwb_exercise_yrs_crbg(t) + 1 
			 && pol_mth(t) == 1)
		curr_max_amt = gmwb_inf_bef(t) * gmwb_max_ann_wdl_pct_crbg(t);
	else
		{
		if (t == commencement_period + 1 && elapsed_mths > 0)
			curr_max_amt = init_gmwb_max_wdl_amt;
		
		else
			curr_max_amt = gmwb_max_wdl_amt(t - 1) 
						   * surv_period(t - 1);
		}
	}

if (gmwb_max_wdl_amt_base_defn == GMWB_BASE_ADJUSTABLE && pol_yr(t) > gmwb_exercise_yrs_crbg(t))
	{
	//Reset max amount only if it would be greater based on the current gmwb base
	curr_max_amt = gmwb_inf_bef(t) * gmwb_max_ann_wdl_pct_crbg(t);
	}

return curr_max_amt;

}

//@@ END

//@@ START - gmwb_min_income_base_bef_crbg
// Gmwb Min Income Base Bef Crbg                                                                                             
// Column:GMWB_MIN_INCOME_BASE_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_min_income_base_bef_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_min_income_base_bef_crbg.FIA_LIAB.for"
//20250502 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

double gmwb_minimum_income_base = 0.0;

if (
	gmwb_doubling_year_crbg != 0 &&
	pol_yr(t) == (gmwb_doubling_year_crbg + 1) &&
	xint(pol_mth(t)) == 1 &&
	pfwd_surr_cumul_bom(t) < SMALL_DOUBLE &&
	abs(fund_val_b_bef(t)) > SMALL_DOUBLE
   )
{
	double cumulative_premium = prem_cumul_bef(t);
	gmwb_minimum_income_base = cumulative_premium * 2.0;
}

return gmwb_minimum_income_base;

}

//@@ END

//@@ START - gmwb_pipp_stepup_ind_crbg
// Gmwb Pipp Stepup Ind Crbg                                                                                             
// Column:GMWB_PIPP_STEPUP_IND_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_pipp_stepup_ind_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_pipp_stepup_ind_crbg.FIA_LIAB.for"
//20250502 New column for CRBG logic.
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

if (t + elapsed_mths == 1)
	return 0.;

if(xint(pol_mth(t)) == 1
	&& gmwb_fund_val_defn != NOT_APPLICABLE
	&& age_last(t) >= pipp_stepup_age_crbg 
	&& fund_val_fixed(t - 1) > gmwb_income_base_b_bef_crbg(t))
{
	return 1.;
}

return gmwb_pipp_stepup_ind_crbg(t - 1);

}

//@@ END

//@@ START - gmwb_rollup_cap_inf
// GMWB Roll-Up Cap End of Month                                                                                             
// Column:GMWB_ROLLUP_CAP_INF
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_rollup_cap_inf(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(179,"gmwb_rollup_cap_inf",t);
}



//^^^

#line 1 "gmwb_rollup_cap_inf.FIA_LIAB.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;
	
if (!gmwb_flag || gmwb_prem_defn != ROLLUP)
	return NO_AVG;
	
if (t == commencement_period)
	{
	if (elapsed_mths > 0)
		{
		if (gmwb_wdl_reduce_ben_base == YES)
			return gmwb_rollup_cap * (single_prem - init_withdrl_cumul);

		return gmwb_rollup_cap * single_prem;
		}

	// New Business
	return 0.0;
	}

if (gmwb_wdl_reduce_ben_base == YES)
    return max(0.0, gmwb_rollup_cap_inf_bef(t) * surv_period(t) 
					- gmwb_rollup_cap * withdrl_benefits(t));

return max(0.0, gmwb_rollup_cap_inf_bef(t) * surv_period(t));

}

//@@ END

//@@ START - gmwb_rollup_cap_inf_bef
// GMWB Roll-Up Cap End of Month Before Claims                                                                                             
// Column:GMWB_ROLLUP_CAP_INF_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_rollup_cap_inf_bef(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(180,"gmwb_rollup_cap_inf_bef",t);
}



//^^^

#line 1 "gmwb_rollup_cap_inf_bef.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag || gmwb_prem_defn != ROLLUP)
	return NO_AVG;

// Sets the GMWB after reaching the maximum age
if (age_last(t) >= gmwb_max_age)
	return gmwb_rollup_cap_inf(t - 1);
	
return gmwb_rollup_cap_inf(t - 1) 
       + gmwb_rollup_cap * prem_paid(t);

}

//@@ END

//@@ START - gmwb_wdl_amt_e_bef_crbg
// Gmwb Wdl Amt Taken                                                                                             
// Column:GMWB_WDL_AMT_E_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_wdl_amt_e_bef_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_wdl_amt_e_bef_crbg.FIA_LIAB.for"
//20250505 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag || pol_yr(t) <= gmwb_exercise_yrs_crbg(t))
	return NO_AVG;

double max_wdl_amt = gmwb_max_wdl_amt(t);

double wdl_util = gmwb_wdl_util_pct_crbg(t);

return max_wdl_amt * wdl_util / 12.;

}

//@@ END

//@@ START - gmwb_wdl_amt_excess_bef_crbg
// Gmwb Wdl Amt that's excess withdrl                                                                                             
// Column:GMWB_WDL_AMT_EXCESS_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_wdl_amt_excess_bef_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_wdl_amt_excess_bef_crbg.FIA_LIAB.for"
//20250505 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag)
	return NO_AVG;

double excess_withdrl = gmwb_wdl_amt_e_bef_crbg(t) - gmwb_entitlement_remaining_b_crbg(t);

if (excess_withdrl > model_point_amount_threshold)
{
	return excess_withdrl;
}

return 0.;

}

//@@ END

//@@ START - gmwb_wdl_excess_ind_e_crbg
// Gmwb Wdl Excess Ind E Crbg                                                                                             
// Column:GMWB_WDL_EXCESS_IND_E_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_wdl_excess_ind_e_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_wdl_excess_ind_e_crbg.FIA_LIAB.for"
//20250506 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag)
	return NO_AVG;

if (t == 0 && valn_period > 0)
	return init_gmwb_wdl_excess_ind;

if (xint(pol_mth(t)) == 1)
{
	return 0.;
}

if (gmwb_wdl_amt_excess_bef_crbg(t) > SMALL_DOUBLE)
{
	return 1.0;
}

return gmwb_wdl_excess_ind_e_crbg(t - 1);

}

//@@ END

//@@ START - gmwb_wdl_uti_level_crbg
// Gmwb Wdl Uti Level Crbg                                                                                             
// Column:GMWB_WDL_UTI_LEVEL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_wdl_uti_level_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_wdl_uti_level_crbg.FIA_LIAB.for"
//20250505 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag)
	return NO_AVG;

if (t == 0 && valn_period != 0)
	return init_gmwb_wdl_util_level;

double util_code;
//0: No wdl
//1: Below MAWA
//2: MAWA
//3: Above MAWA

if (pol_yr(t) <= gmwb_exercise_yrs_crbg(t))		
{
	util_code = 0.0;
}
else
{
	double util_level_prev = gmwb_wdl_uti_level_crbg(t - 1);

	if (pol_mth(t) != 1)
	{
		util_code = util_level_prev;
	}
	else
	{
		double unif_rv_cv			= gmwb_wdl_util_rand_num_crbg(t);
		double fund_val_e_bef_cv	= fund_val_e_bef(t);
		double gmwb_inf_e_bef_cv	= gmwb_inf_bef(t);

		double new_util_level_cv = 
			calc_gmwb_wdl_util_level_crbg(t, unif_rv_cv, util_level_prev, fund_val_e_bef_cv, gmwb_inf_e_bef_cv);

		util_code = new_util_level_cv;
	}
}

return util_code;

}

//@@ END

//@@ START - gmwb_wdl_util_pct_crbg
// Gmwb Wdl Util Pct Crbg                                                                                             
// Column:GMWB_WDL_UTIL_PCT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_wdl_util_pct_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_wdl_util_pct_crbg.FIA_LIAB.for"
//20250505 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!gmwb_flag)
	return NO_AVG;

if (t == 0 && valn_period != 0)
	return init_gmwb_wdl_util_pct;

double gmwb_wdl_util_pct;

if (pol_mth(t) != 1)
{
	return gmwb_wdl_util_pct_crbg(t - 1);
}

if (gmwb_wdl_util_type_crbg == AVERAGE_UTIL)
{
	if (pol_yr(t) <= gmwb_exercise_yrs_crbg(t))
		gmwb_wdl_util_pct = 0.;
	else
		gmwb_wdl_util_pct = gmwb_wdl_avg_util_pct_crbg;
}
else if (gmwb_wdl_util_type_crbg == RANDOM_UTIL)
{
	double new_util_lvl = gmwb_wdl_uti_level_crbg(t);

	gmwb_wdl_util_level_crbg = new_util_lvl;
	gmwb_wdl_util_pct = gmwb_wdl_random_util_rate_crbg;
}

if (enhanced_income_ind_crbg == YES)
{
	if (gmwb_wdl_util_type_crbg == AVERAGE_UTIL)
	{
		if (xint(enh_inc_exercise_flag_crbg(t)) == 1)
		{
			gmwb_wdl_util_pct = (enh_inc_utilization_pct * enh_inc_mawp_mult + (1 - enh_inc_utilization_pct) * gmwb_wdl_util_pct) / enh_inc_mawp_mult;
		}
	}
	else if (gmwb_wdl_util_type_crbg == RANDOM_UTIL)
	{
		if (xint(enh_inc_eligibility_flag_crbg(t)) == 1)
		{
			if (xint(enh_inc_exercise_flag_crbg(t)) == 1)
				gmwb_wdl_util_pct = 1.;
			else
				gmwb_wdl_util_pct = gmwb_wdl_util_pct / enh_inc_mawp_mult;
		}
	}

}


return gmwb_wdl_util_pct;

}

//@@ END

//@@ START - gmwb_wdl_util_rand_num_crbg
// Uniform Rands Gmwb Util Crbg                                                                                             
// Column:GMWB_WDL_UTIL_RAND_NUM_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gmwb_wdl_util_rand_num_crbg(int t) {
//^^^



//^^^

#line 1 "gmwb_wdl_util_rand_num_crbg.FIA_LIAB.for"
//20250505 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (gmwb_ind && gmwb_wdl_util_type_crbg == RANDOM_UTIL)
{
	double uniform_rv;
	
	if (!valn_flag)
	{
		uniform_rv = uniform_rands_arr_crbg[2][t + elapsed_mths - 1];
	}	
	else
	{
		uniform_rv = uniform_rands_arr_crbg[2][t - 1];
	}

	return uniform_rv;
}
else
	return NO_AVG;

	


}

//@@ END

//@@ START - gross_prem_annualzd
// Gross Premium Annualized                                                                                             
// Column:GROSS_PREM_ANNUALZD
//========================================================
double FIA_LIAB_UDF::fia_liab_gross_prem_annualzd(int t) {
//^^^



//^^^

#line 1 "gross_prem_annualzd.FIA_LIAB.for"
if (t < start_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period && valn_period == 0)
	return NO_AVG;	
	
double prem_per_pol = single_prem / init_policies;

if (pol_yr(t) != 1)
	return 0.0;

return prem_per_pol * policies_inf(t);

}

//@@ END

//@@ START - gwl_acq_exp_allow_crbg
// Gwl Acq Exp Allow Crbg                                                                                             
// Column:GWL_ACQ_EXP_ALLOW_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gwl_acq_exp_allow_crbg(int t) {
//^^^



//^^^

#line 1 "gwl_acq_exp_allow_crbg.FIA_LIAB.for"
//20250723 Customized CRBG column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double acq_exp_allow_cv =  prem_issued(t) * gwl_acq_exp_allow_level_crbg;

if ( gsia_reins_defn_crbg == CEDANT )
{
	acq_exp_allow_cv *= quota_share_reinsured_crbg / (1 - quota_share_reinsured_crbg);
}

return acq_exp_allow_cv;

}

//@@ END

//@@ START - gwl_ceding_exp_allow_crbg
// Gwl Ceding Exp Allow Crbg                                                                                             
// Column:GWL_CEDING_EXP_ALLOW_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gwl_ceding_exp_allow_crbg(int t) {
//^^^



//^^^

#line 1 "gwl_ceding_exp_allow_crbg.FIA_LIAB.for"
//20250723 Customized CRBG column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double ceding_exp_allow_cv = fund_val_b(t) * sm_fia_account[0]->gwl_ceding_exp_allow_level_crbg;

if ( gsia_reins_defn_crbg == CEDANT )
{
	ceding_exp_allow_cv *= quota_share_reinsured_crbg / (1 - quota_share_reinsured_crbg);
}

return ceding_exp_allow_cv;

}

//@@ END

//@@ START - gwl_maint_exp_allow_crbg
// Gwl Maint Exp Allow Crbg                                                                                             
// Column:GWL_MAINT_EXP_ALLOW_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_gwl_maint_exp_allow_crbg(int t) {
//^^^



//^^^

#line 1 "gwl_maint_exp_allow_crbg.FIA_LIAB.for"
//20250723 Customized CRBG column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double maint_exp_allow_cv =  fund_val_b(t) * gwl_maint_exp_allow_level_crbg;

if ( gsia_reins_defn_crbg == CEDANT )
{
	maint_exp_allow_cv *= quota_share_reinsured_crbg / (1 - quota_share_reinsured_crbg);
}

return maint_exp_allow_cv;

}

//@@ END

//@@ START - hedge_cash_flow
// Hedge Cash Flows                                                                                             
// Column:HEDGE_CASH_FLOW
//========================================================
double FIA_LIAB_UDF::fia_liab_hedge_cash_flow(int t) {
//^^^



//^^^

#line 1 "hedge_cash_flow.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

// force call opt_payoff
opt_payoff(t);

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->hedge_cash_flow(t);	

return total;

}

//@@ END

//@@ START - hedge_cost
// Hedge Cost                                                                                             
// Column:HEDGE_COST
//========================================================
double FIA_LIAB_UDF::fia_liab_hedge_cost(int t) {
//^^^



//^^^

#line 1 "hedge_cost.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return - (hedge_cash_flow(t) + hedge_mkt_val_incr(t));

}

//@@ END

//@@ START - hedge_inv_amt_bom
// Hedge Inv Amt Bom                                                                                             
// Column:HEDGE_INV_AMT_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_hedge_inv_amt_bom(int t) {
//^^^



//^^^

#line 1 "hedge_inv_amt_bom.FIA_LIAB.for"
if (t < start_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->hedge_inv_amt_bom(t);

return total;

}

//@@ END

//@@ START - hedge_mkt_val
// Market Value of Hedges                                                                                             
// Column:HEDGE_MKT_VAL
//========================================================
double FIA_LIAB_UDF::fia_liab_hedge_mkt_val(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->hedge_mkt_val(t);	

return total;

}

//@@ END

//@@ START - hedge_mkt_val_growth
// Hedge Market Value Growth                                                                                             
// Column:HEDGE_MKT_VAL_GROWTH
//========================================================
double FIA_LIAB_UDF::fia_liab_hedge_mkt_val_growth(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val_growth.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total += sm_fia_account[i]->hedge_mkt_val_growth(t);	

return total;

}

//@@ END

//@@ START - hedge_mkt_val_incr
// Increase in Market Value of Hedges                                                                                             
// Column:HEDGE_MKT_VAL_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_hedge_mkt_val_incr(int t) {
//^^^



//^^^

#line 1 "hedge_mkt_val_incr.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return hedge_mkt_val(t) - hedge_mkt_val(t - 1);

}

//@@ END

//@@ START - hedge_sale_amt
// Hedge Sale Amt                                                                                             
// Column:HEDGE_SALE_AMT
//========================================================
double FIA_LIAB_UDF::fia_liab_hedge_sale_amt(int t) {
//^^^



//^^^

#line 1 "hedge_sale_amt.FIA_LIAB.for"
if (t < start_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	total = total 
			+ sm_fia_account[i]->hedge_sale_amt_bom(t) 
			+ sm_fia_account[i]->hedge_sale_amt_eom(t);

return total;

}

//@@ END

//@@ START - income_phase_bef_crbg
// Income Phase Crbg                                                                                             
// Column:INCOME_PHASE_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_income_phase_bef_crbg(int t) {
//^^^



//^^^

#line 1 "income_phase_bef_crbg.FIA_LIAB.for"
//20250502 New column with CRBG logic
if (t <start_period ||t > final_period || !gmwb_flag)
	return NO_AVG;

if (t + elapsed_mths <= gmwb_exercise_yrs_crbg(t) * 12 + 1)
{
	return 0.; 
}
else 
{
	return 1.;
}


}

//@@ END

//@@ START - infl_cumul
// Inflation Cumulative                                                                                             
// Column:INFL_CUMUL
//========================================================
double FIA_LIAB_UDF::fia_liab_infl_cumul(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(199,"infl_cumul",t);
}



//^^^

#line 1 "infl_cumul.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if ((pricing_flag || nb_flag) && t == start_period
	&& valn_period == 0)
	return 1.0;

if (t <= infl_start_period)
	return 1.0;

if (t == start_period && infl_start_period < start_period)
		{
		double init_infl_cumul = 1.0;

		for (int i = infl_start_period + 1; i <= 0; i++)
			{
			double infl_rate;

			//20250520 Added CRBG logic
			if (infl_rate_defn_crbg == CONSTANT)
			{
				infl_rate = infl_rate_const_crbg;
			}
			else  if (infl_rate_defn_crbg == STOCHASTIC)
			{
				double govt_rate = rates_ptr->get_int_rate(i, "Govt", GET_YIELD_RATE, 10., 0, EFFECTIVE_ANNUAL, NO_SHIFT, 0);
				infl_rate = infl_mult_crbg * govt_rate - infl_deduction_crbg;
			}
			else //USL default logic
				infl_rate = rates_ptr->get_infl_rate(i, EFFECTIVE_ANNUAL); 

			init_infl_cumul *= pow((1.0 + infl_rate), (1.0 / 12.0));
			}

		return init_infl_cumul;
		}

double infl_rate;

//20250520 Added CRBG logic
if (infl_rate_defn_crbg == CONSTANT)
{
	infl_rate = infl_rate_const_crbg;
}
else  if (infl_rate_defn_crbg == STOCHASTIC)
{
	double govt_rate = rates_ptr->get_int_rate(t, "Govt", GET_YIELD_RATE, 10., 0, EFFECTIVE_ANNUAL, NO_SHIFT, 0);

	infl_rate = infl_mult_crbg * govt_rate - infl_deduction_crbg;

	if (gsia_reins_defn_crbg == CEDANT)
	{
		govt_rate = rates_ptr->get_int_rate(t, "Govt", GET_YIELD_RATE, 1, 0, EFFECTIVE_ANNUAL, NO_SHIFT, 0);

		double prev_infl_rate_mthly = infl_cumul(t - 1) / infl_cumul(t - 2) - 1;
		double prev_infl_rate = pow(1. + prev_infl_rate_mthly, 12.) - 1.;

		infl_rate = gwl_infl_mult1_crbg * govt_rate + gwl_infl_mult2_crbg * prev_infl_rate + gwl_infl_addn_crbg;
	}
}
else
	infl_rate = rates_ptr->get_infl_rate(t, EFFECTIVE_ANNUAL);

if(pba_scen_amt_valn_flag) 
{	
	double treasury_rate = rates_ptr->get_int_rate(t, "Govt", GET_YIELD_RATE, 2., 0, EFFECTIVE_ANNUAL, NO_SHIFT, 0);
	infl_rate = max(0.02, pba_infl_slope_crbg * treasury_rate + pba_infl_intercept_crbg);
}

return infl_cumul(t - 1)
       * pow((1.0 + infl_rate), (1.0 / 12.0));

}

//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double FIA_LIAB_UDF::fia_liab_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.FIA_LIAB.for"
if (t != 0)
	return NO_AVG;

if (use_mp == NO)
	return 1.0;

static int loaded_iteration = -999;

if (isMainModel)
	{
	if (loaded_iteration != proj_task_loop_num)
		{
		comp_rates_map.clear();

		rates_ptr->initialize(t);
	
		loaded_iteration = proj_task_loop_num;
		}
	
	if (time_step_flag && valn_period > 0 && !mrb_valn_flag)
		read_state_of_world_financial();	
	}

// Data Validation
if (data_validation_defn == YES)
	validate_data();

for (int i = 0; i < sm_fia_account.size(); i++)
	sm_fia_account[i]->initialize(t);

if (gaap_flag)
    {
    for (int i = 0; i < sm_fia_mrb.size(); i++)
        {
        if (i == 0)
            sm_fia_mrb[i]->reins_defn = "Gross";
        else
            sm_fia_mrb[i]->reins_defn = "Ceded";
              
        sm_fia_mrb[i]->initialize(t);
        }

	for (int i = 0; i < sm_fia_sfas97rd.size(); i++)
        {
        if (i == 0)
            sm_fia_sfas97rd[i]->reins_defn = "Gross";
        else
            sm_fia_sfas97rd[i]->reins_defn = "Ceded";
              
        sm_fia_sfas97rd[i]->initialize(t);
        }
    }

return 1.0;

}

//@@ END

//@@ START - inv_asset
// Invested Assets                                                                                             
// Column:INV_ASSET
//========================================================
double FIA_LIAB_UDF::fia_liab_inv_asset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(201,"inv_asset",t);
}



//^^^

#line 1 "inv_asset.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return liab_and_surp(t) - hedge_mkt_val(t);

}

//@@ END

//@@ START - inv_inc
// Investment Income                                                                                             
// Column:INV_INC
//========================================================
double FIA_LIAB_UDF::fia_liab_inv_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(202,"inv_inc",t);
}



//^^^

#line 1 "inv_inc.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return inv_inc_on_invested_assets(t);

}

//@@ END

//@@ START - inv_inc_bk_prof
// Investment Income For Book Profit                                                                                             
// Column:INV_INC_BK_PROF
//========================================================
double FIA_LIAB_UDF::fia_liab_inv_inc_bk_prof(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(203,"inv_inc_bk_prof",t);
}



//^^^

#line 1 "inv_inc_bk_prof.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	       
return direct_cash_flow_int(t)
       + inv_inc_res(t)
       + inv_inc_undistrib_earnings(t);

}

//@@ END

//@@ START - inv_inc_earnings_accum
// Investment Income on Accumulated Earnings                                                                                             
// Column:INV_INC_EARNINGS_ACCUM
//========================================================
double FIA_LIAB_UDF::fia_liab_inv_inc_earnings_accum(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(204,"inv_inc_earnings_accum",t);
}



//^^^

#line 1 "inv_inc_earnings_accum.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return earnings_accum(t - 1)
       * (pow(1.0 + asset_yld_inv(t), 1.0 / 12.0) - 1.0);

}

//@@ END

//@@ START - inv_inc_fund
// Investment Income on Fund                                                                                             
// Column:INV_INC_FUND
//========================================================
double FIA_LIAB_UDF::fia_liab_inv_inc_fund(int t) {
//^^^



//^^^

#line 1 "inv_inc_fund.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return fund_val_fixed(t - 1)
       * (pow(1.0 + asset_yld_inv(t), 1.0 / 12.0) - 1.0);

}

//@@ END

//@@ START - inv_inc_on_invested_assets
// Investment Income on Invested Assets                                                                                             
// Column:INV_INC_ON_INVESTED_ASSETS
//========================================================
double FIA_LIAB_UDF::fia_liab_inv_inc_on_invested_assets(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(206,"inv_inc_on_invested_assets",t);
}



//^^^

#line 1 "inv_inc_on_invested_assets.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return inv_asset(t - 1)
       * (pow(1.0 + asset_yld_inv(t), 1.0 / 12.0) - 1.0);
       

}

//@@ END

//@@ START - inv_inc_res
// Investment Income on Reserves                                                                                             
// Column:INV_INC_RES
//========================================================
double FIA_LIAB_UDF::fia_liab_inv_inc_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(207,"inv_inc_res",t);
}



//^^^

#line 1 "inv_inc_res.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

// force call inv_inc_fund and credited_int
inv_inc_fund(t);
credited_int(t);

// This is investment income on gross reserves
return inv_inc_on_invested_assets(t)
	   - inv_inc_tgt_cap(t)
	   - inv_inc_undistrib_earnings(t)
	   + reins_inv_inc_res(t);

}

//@@ END

//@@ START - inv_inc_tgt_cap
// Investment Income on Target Capital                                                                                             
// Column:INV_INC_TGT_CAP
//========================================================
double FIA_LIAB_UDF::fia_liab_inv_inc_tgt_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(208,"inv_inc_tgt_cap",t);
}



//^^^

#line 1 "inv_inc_tgt_cap.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tgt_cap(t - 1)
	   * (pow(1.0 + max(asset_yld_inv(t), -0.99), 1.0 / 12.0) - 1);

}

//@@ END

//@@ START - inv_inc_undistrib_earnings
// Investment Income on Undistributed Earnings                                                                                             
// Column:INV_INC_UNDISTRIB_EARNINGS
//========================================================
double FIA_LIAB_UDF::fia_liab_inv_inc_undistrib_earnings(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(209,"inv_inc_undistrib_earnings",t);
}



//^^^

#line 1 "inv_inc_undistrib_earnings.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
  
if (fabs(inv_asset(t - 1) - tgt_cap(t - 1))
          < aggregate_amount_threshold)
	return NO_AVG;

double inv_inc_wo_surp
	   = inv_inc_on_invested_assets(t)
         - inv_inc_tgt_cap(t);

return inv_inc_wo_surp
       * undistrib_earnings(t - 1)
       / (inv_asset(t - 1) - tgt_cap(t - 1));

}

//@@ END

//@@ START - irr
// Internal Rate of Return                                                                                             
// Column:IRR
//========================================================
double FIA_LIAB_UDF::fia_liab_irr(int t) {
//^^^



//^^^

#line 1 "irr.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!pricing_flag)
	return NO_AVG;

disc_rate_port_yld(t);

// The reporting tool calculates Adjusted IRR for scenario time-step projections
if (time_step_flag && t > start_period)
	{
	bk_prof_aft_tax_irr(t);
	
	distrib_earnings_irr(t);
	distrib_earnings(t);
	
	}

if (time_step_flag || t > start_period)
	return NO_AVG;

// Force call so this target column produces all IRR results
irr_wo_tgt_cap(t);
	
return irr_calc(t, "With Target Capital");

}

//@@ END

//@@ START - irr_wo_tgt_cap
// IRR Without Target Capital                                                                                             
// Column:IRR_WO_TGT_CAP
//========================================================
double FIA_LIAB_UDF::fia_liab_irr_wo_tgt_cap(int t) {
//^^^



//^^^

#line 1 "irr_wo_tgt_cap.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!pricing_flag)
	return NO_AVG;

// The reporting tool calculates Adjusted IRR for scenario time-step projections
if (time_step_flag && t > start_period)
	{
	bk_prof_aft_tax_irr(t);
	
	distrib_earnings_irr(t);
	distrib_earnings(t);
	}

if (time_step_flag || t > start_period)
	return NO_AVG;

return irr_calc(t, "Without Target Capital");

}

//@@ END

//@@ START - issue_age_col_crbg
// Issue Age Crbg                                                                                             
// Column:ISSUE_AGE_COL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_issue_age_col_crbg(int t) {
//^^^



//^^^

#line 1 "issue_age_col_crbg.FIA_LIAB.for"
//20250507 Customized CRBG Logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (gender_mp == BLENDED)
{			
	return issue_age_calc_crbg(gender_mp);
}	

double issue_age;

if (gender_mp == gender_aft_inc)
	issue_age = issue_age_calc_crbg(gender_mp);
else if (pol_yr(t) <= gmwb_exercise_yrs_crbg(t))
	issue_age = issue_age_calc_crbg(gender_mp);
else
	issue_age = issue_age_calc_crbg(gender_aft_inc);

return issue_age;

}

//@@ END

//@@ START - itm_is_positive_crbg
// Itm Positive Indicator                                                                                             
// Column:ITM_IS_POSITIVE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_itm_is_positive_crbg(int t) {
//^^^



//^^^

#line 1 "itm_is_positive_crbg.FIA_LIAB.for"
//20250502 New column with CRBG logic
if (t <start_period ||t > final_period || !gmwb_flag)
	return NO_AVG;

if (gmwb_itm(t) > SMALL_DOUBLE)
{
	return 1.; 
}
else 
{
	return 0.;
}

}

//@@ END

//@@ START - lapse_dyn_add_myga_crbg
// Lapse Dyn Add Myga Crbg                                                                                             
// Column:LAPSE_DYN_ADD_MYGA_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_dyn_add_myga_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_dyn_add_myga_crbg.FIA_LIAB.for"
//20251216 Customized new column
if (t <= commencement_period || t > maturity_period || annuity_type_crbg != "FA")
	return NO_AVG;

if (myga_renew_ind_crbg == NO || myga_current_term_crbg(t) == 1)
{
	return 0.;
}

double crediting_rate = lapse_dyn_crediting_rt_crbg(t);
double new_money_rate = nmr_7yr_govt_plus_sprd_crbg(t);
double mva_final_factor = mva_factor_bef_crbg(t);
double m = 1.;
double e = lapse_dyn_exp_param_crbg;
double mva_dyn_lapse_mult = lapse_dyn_mva_mult_crbg;
double lapse_addition = 0.0;

double remaining_term = max((mva_current_term_crbg(t) * 12 - myga_term_mth_elapsed_eom_crbg(t)) / 12, 0.0);
	
if (crediting_rate > new_money_rate)
{
	m = lapse_dyn_base_prod_mult2_crbg;
	lapse_addition = m * pow(new_money_rate - crediting_rate, e) - mva_dyn_lapse_mult * mva_final_factor;
}
else
{
	m = lapse_dyn_base_prod_mult1_crbg;
	lapse_addition = max(0.0, max(remaining_term, m) * pow(new_money_rate - crediting_rate, e) - mva_dyn_lapse_mult * mva_final_factor);									
}

// Check against threshold
if (fabs(new_money_rate - crediting_rate) <= lapse_dyn_base_prod_threshold_crbg)
{
	lapse_addition = 0.0;
}

return lapse_addition;

}

//@@ END

//@@ START - lapse_dyn_addn_crbg
// Lapse Dyn Addn Crbg                                                                                             
// Column:LAPSE_DYN_ADDN_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_dyn_addn_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_dyn_addn_crbg.FIA_LIAB.for"
//20250502 Customized CRBG column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (decrements_defn == NO)
	return NO_AVG;

double lapse_addition = 0.0;

if (!gmwb_flag)
{
	if (annuity_type_crbg == "FA")
		lapse_addition = lapse_dyn_add_myga_crbg(t);
	else
		lapse_addition = lapse_dyn_base_prod_crbg(t);
}

if (lapse_dyn_isl_defn_crbg == YES && gmwb_flag)
{
	lapse_addition = lapse_dyn_isl_crbg(t);
}

if (eprs_sfc_defn == YES && pol_yr(t) == surr_chg_period_crbg + 1 && !gmwb_flag 
	&& sm_fia_account[index0_element]->crediting_dyn_lever == DYNAMIC_PART_EPRS)
{
	if (eprs_sfc_ben_gross_crbg(surr_chg_period_crbg * 12 + 1) > SMALL_DOUBLE)
	{
		lapse_addition += eprs_sfc_ben_crbg(surr_chg_period_crbg * 12 + 1) / eprs_sfc_ben_gross_crbg(surr_chg_period_crbg * 12 + 1);
	}
}

return lapse_addition;

}

//@@ END

//@@ START - lapse_dyn_arctan_mult_crbg
// Lapse Dyn Arctan Mult Crbg                                                                                             
// Column:LAPSE_DYN_ARCTAN_MULT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_dyn_arctan_mult_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_dyn_arctan_mult_crbg.FIA_LIAB.for"
//20250507 Customized CRBG column: This corresponds to Arctan 2019 in prior IA model
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (decrements_defn == NO || !gmwb_flag)
	return NO_AVG;

double lapse_multiple = 1.0;

gmwb_itm(t);

if (shock_lapse_phase_crbg(t) >= 1) //or ==0 but want to turn on
{
	double itmness = gmwb_itm(t);

	double arctan_param1 = arctan_param1_crbg;
	double arctan_param2 = arctan_param2_crbg;

	lapse_multiple = max(0.0, 1.0 - arctan_param1 * atan(arctan_param2 * itmness));

	//Dynamic Lapse Sensitivity Test, lapse_sens_test_mult

	//Not really going to kick in as gmwb_max_rollup_duration is 999
	int rollup_shock_yr = max(gmwb_max_rollup_duration, gmwb_doubling_year_crbg) + 1;
	if (pol_yr(t) > rollup_shock_yr  && pol_yr(t) <= gmwb_exercise_yrs_crbg(t))
	  
	{
		lapse_multiple += (1.0 - lapse_multiple) / 2.0;
	}
}

lapse_multiple = max(lapse_multiple, lapse_dyn_mult_floor_crbg);

return lapse_multiple;

}

//@@ END

//@@ START - lapse_dyn_base_prod_crbg
// Lapse Dyn Base Prod Crbg                                                                                             
// Column:LAPSE_DYN_BASE_PROD_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_dyn_base_prod_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_dyn_base_prod_crbg.FIA_LIAB.for"
//20250502 Customized CRBG column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (
	( lapse_dyn_base_prod_defn_crbg == AFTER_SC && pol_yr(t) < lapse_shock_year_crbg ) || 
	( lapse_dyn_base_prod_defn_crbg == NO )
   )
{
	return 0.;
}

double competitor_rate = nmr_7yr_govt_plus_sprd_crbg(t);
double crediting_rate = lapse_dyn_crediting_rt_crbg(t);
double mva_factor = mva_factor_bef_crbg(t); 

double lapse_addition = 0.0;

if (competitor_rate >= crediting_rate)
{
	double remaining_term	= max(0.0, (surr_chg_period_crbg * 12 - t - elapsed_mths) / 12);
	double multiple			= lapse_dyn_base_prod_mult1_crbg;

	lapse_addition	= max(0.0, max(remaining_term, multiple) * (competitor_rate - crediting_rate) - surr_chg_pct - mva_factor);
}
else
{
	double multiple	= lapse_dyn_base_prod_mult2_crbg;

	lapse_addition	= multiple * (competitor_rate - crediting_rate) - mva_factor;
}

if (fabs(competitor_rate - crediting_rate) <= lapse_dyn_base_prod_threshold_crbg)
{
	lapse_addition = 0.0;
}

return lapse_addition;

}

//@@ END

//@@ START - lapse_dyn_crediting_rt_crbg
// Lapse Dyn Crediting Rt                                                                                             
// Column:LAPSE_DYN_CREDITING_RT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_dyn_crediting_rt_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_dyn_crediting_rt_crbg.FIA_LIAB.for"
//20250502 Customized CRBG column
if (t <= commencement_period || t > maturity_period)
{
	return NO_AVG;	
}

double total = 0.0;

for (size_t i = 0; i < sm_fia_account.size(); i++)
{
	if (fund_val_e_bef(t) > SMALL_DOUBLE)
	{
		// Weigh by current allocation
		total += sm_fia_account[i]->lapse_dyn_crediting_rt_crbg(t) * (sm_fia_account[i]->fund_val_e_bef(t) / fund_val_e_bef(t));
	}
	else
	{
		// Weigh by initial allocation
		total += sm_fia_account[i]->lapse_dyn_crediting_rt_crbg(t) * (sm_fia_account[i]->fund_val_split_prop);
	}
}
		
return total;

}

//@@ END

//@@ START - lapse_dyn_fa_mult_crbg
// Lapse Dyn Fa Mult Crbg                                                                                             
// Column:LAPSE_DYN_FA_MULT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_dyn_fa_mult_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_dyn_fa_mult_crbg.FIA_LIAB.for"
//20251216 Customized new column
if (t <= commencement_period || t > maturity_period || annuity_type_crbg != "FA")
	return NO_AVG;

if (policies_b(t) < SMALL_DOUBLE)
	return 0.0;

double dyn_lapse_multiple = 1.0;
double av_size_multiple = 1.0;
double sprd_multiple = 1.0;

//The logic only applies to non-MYGA and 1-year renewable MYGA 
if((myga_renew_ind_crbg == NO) || (myga_renew_ind_crbg == YES && myga_current_term_crbg(t) == 1))
{
	double sc_or_mva_period = lapse_shock_year_crbg - 1.; 
	double remaining_term = max((sc_or_mva_period * 12 - t - elapsed_mths) / 12, 0.0);

	//set up lookup parameters
	xstring pos_sprd_ind;
	double dyn_sprd, alpha, beta;

	if (shock_lapse_phase_crbg(t) == 0 && lapse_dyn_preshock_sprd_crbg == YES) // PRE_SHOCK;
	{
		dyn_sprd = lapse_dyn_crediting_rt_crbg(t) - nmr_7yr_govt_plus_sprd_crbg(t)
						+ (surr_chg_pct + mva_factor_bef_crbg(t)) 
						/ max(1, remaining_term);
	}
	else //SHOCK and POST_SHOCK
	{
		dyn_sprd = lapse_dyn_crediting_rt_crbg(t) - nmr_7yr_govt_plus_sprd_crbg(t);
	}

	if (dyn_sprd < SMALL_DOUBLE)
	{
		pos_sprd_ind = "No";
	}
	else
	{
		pos_sprd_ind = "Yes";
	}

	pos_sprd_ind_crbg = pos_sprd_ind;
	alpha = fa_dyn_lapse_mult_alpha_crbg;

	pos_sprd_ind_crbg = pos_sprd_ind;
	beta = fa_dyn_lapse_mult_beta_crbg;

	dyn_lapse_multiple = 1 - alpha * atan( beta * dyn_sprd);

	dyn_lapse_multiple = max(lapse_dyn_mult_floor_crbg, dyn_lapse_multiple);

	if (lapse_dyn_shock_yr_defn_crbg == YES && shock_lapse_yr_ind_crbg(t) == 1)
	{
		av_size_crbg = fund_val_e_bef(t) / policies_b(t);
		av_size_multiple = fa_dyn_lapse_av_size_mult_crbg;

		dyn_sprd_crbg = dyn_sprd;
		sprd_multiple = fa_dyn_lapse_dyn_sprd_mult_crbg;
	}
}

return dyn_lapse_multiple * av_size_multiple * sprd_multiple;

}

//@@ END

//@@ START - lapse_dyn_isl_crbg
// Lapse Dyn Isl Crbg                                                                                             
// Column:LAPSE_DYN_ISL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_dyn_isl_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_dyn_isl_crbg.FIA_LIAB.for"
//20250627 Customized CRBG column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (decrements_defn == NO || !gmwb_flag || lapse_dyn_isl_defn_crbg == NO)
	return NO_AVG;

double pv_at_issue = pv_gmwb_ben_itm_init_rate_crbg(t);
double pv_current  = pv_gmwb_ben_itm_current_crbg(t);

double cash_val_e_bef = cash_val_bef(t);
double gmwb_inf_e_bef = gmwb_inf_bef(t);
double gmwb_itm_denom = min(cash_val_e_bef, gmwb_inf_e_bef);

double lapse_addition = 0.0;

if (gmwb_itm_denom < SMALL_DOUBLE || pv_at_issue < SMALL_DOUBLE)
	return 0.0;

if (surr_chg_pct + 0.000001 < isl_surr_chg_threshold)
{
	double itm_at_issue = pv_at_issue / gmwb_inf_e_bef;	
	double itm_current  = pv_current / gmwb_itm_denom;

	double x = (isl_alpha_crbg - (itm_current / itm_at_issue)) / isl_beta_crbg;
	double tanh_x = tanh(x);

	lapse_addition = isl_coefficient_crbg * (1.0 + tanh_x) / isl_divisor_crbg - mva_factor_bef_crbg(t); 					
}

return lapse_addition;

}

//@@ END

//@@ START - lapse_dyn_mult_crbg
// Lapse Dyn Mult Crbg                                                                                             
// Column:LAPSE_DYN_MULT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_dyn_mult_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_dyn_mult_crbg.FIA_LIAB.for"
//20250502 Customized CRBG column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (decrements_defn == NO)
	return NO_AVG;

double lapse_multiple = 1.0;

if (fund_val_b(t) < SMALL_DOUBLE) //Changed from fund_val_b_bef. 
{
	return 0.0;
}

if (annuity_type_crbg == "FA" && !gmwb_flag)
{
	return lapse_dyn_fa_mult_crbg(t);
}

if (gmwb_flag)
{
	if (gmwb_exercise_yrs >= 200) //Non withdrl cohort
	{
		return 1.;
	}

	lapse_multiple = lapse_dyn_arctan_mult_crbg(t);
}

if (eprs_sfc_defn == YES && pol_yr(t) <= surr_chg_period_crbg && !gmwb_flag
	&& sm_fia_account[index0_element]->crediting_dyn_lever == DYNAMIC_PART_EPRS)
{
	lapse_multiple = lapse_dyn_sfc_mult_crbg(t);
}

return lapse_multiple;

}

//@@ END

//@@ START - lapse_dyn_sfc_mult_crbg
// Lapse Dyn Sfc Mult Crbg                                                                                             
// Column:LAPSE_DYN_SFC_MULT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_dyn_sfc_mult_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_dyn_sfc_mult_crbg.FIA_LIAB.for"
//20250715 Customized CRBG column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (eprs_sfc_defn == YES && pol_yr(t) <= surr_chg_period_crbg && !gmwb_flag
	&& sm_fia_account[index0_element]->crediting_dyn_lever == DYNAMIC_PART_EPRS)
{

	double itm;
	if (cash_val_bef(t) > SMALL_DOUBLE)
	{
		itm = max(pv_sfc_ben_itm_crbg(t) / cash_val_bef(t) - 1.0, 0.0);
	}
	else
	{
		return 0.;
	}
	double alpha = sfc_atan_alpha_crbg;
	double beta  = sfc_atan_beta_crbg;
	double gamma = sfc_atan_gamma_crbg;

	double remaining_sfc_yr = (surr_chg_period_crbg * 12 + 1 - t - elapsed_mths) / 12.;
	double sfc_dyn_lapse_mult = max(sfc_atan_mult_floor_crbg, 
										1 - alpha * atan(beta * pow(remaining_sfc_yr, gamma) * itm));
	
	return sfc_dyn_lapse_mult;
}

return 1.;

}

//@@ END

//@@ START - lapse_rate
// Lapse Rate                                                                                             
// Column:LAPSE_RATE
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_rate(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(223,"lapse_rate",t);
}



//^^^

#line 1 "lapse_rate.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (decrements_defn == NO)
	return NO_AVG;

double rate = lapse_rate_base_adj_crbg(t); //base lapse after adjustment

if(annuity_type_crbg == "FA" && pol_yr(t) > myga_init_term_crbg && myga_current_term_crbg(t) > 1) //base lapse skew for renewable myga
{
	if(myga_term_mth_elapsed_eom_crbg(t) == 1) //free look period
	{
		rate *= lapse_skew_fct1_crbg;
	}
	else if(myga_term_mth_elapsed_eom_crbg(t) <= 12)
	{
		rate *= lapse_skew_fct2_crbg;
	}
}

//20250502 Replaced with CRBG logic
if (lapse_is_dynamic == YES)
{
	rate *= lapse_dyn_mult_crbg(t);  // <-- GLB dynamic lapse adjustment 
  
	rate += lapse_dyn_addn_crbg(t); // <-- Base product or ISL dynamic lapse adjustment
}

if (annuity_type_crbg != "FA" && !gmwb_flag && lapse_dyn_base_prod_defn_crbg != NO)
{
	return max(min(rate, lapse_dyn_base_prod_max_crbg), lapse_dyn_base_prod_min_crbg);
}

if (!gmwb_flag && shock_lapse_yr_ind_crbg(t) == 1) 
{
	return max(min(rate, lapse_shock_yr_max_crbg), lapse_shock_yr_min_crbg);
}

return max(min(rate, lapse_rate_max), lapse_rate_min);


}

//@@ END

//@@ START - lapse_rate_base
// Base Lapse Rate                                                                                             
// Column:LAPSE_RATE_BASE
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_rate_base(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(224,"lapse_rate_base",t);
}



//^^^

#line 1 "lapse_rate_base.FIA_LIAB.for"
if (decrements_defn == NO)
	return NO_AVG;
	
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double base_lapse;

if (annuity_type_crbg == "FA")
{
	pol_yr_lookup = pol_yr(t);
	base_lapse = fa_base_lapse_crbg;
	pol_yr_lookup = pol_yr(t);
	base_lapse *= fa_lapse_factor_crbg;
}
else
{
	pol_yr_lookup = pol_yr(t);
	base_lapse = lapse_rate_input;
}

return base_lapse;

}

//@@ END

//@@ START - lapse_rate_base_adj_crbg
// Lapse Rate Base adj Crbg                                                                                             
// Column:LAPSE_RATE_BASE_ADJ_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_rate_base_adj_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_rate_base_adj_crbg.FIA_LIAB.for"
//CBRG new column, base lapse adjustment 	
if (t <= commencement_period || t > maturity_period || decrements_defn == NO)
	return NO_AVG;

double base_lapse = lapse_rate_base(t);

double base_lapse_mult = 1.0;

if (gmwb_flag)
{
	if (gender_mp != gender_aft_inc && t + elapsed_mths <= gmwb_exercise_yrs * 12 && gmwb_exercise_yrs < 200)  
	{
		base_lapse *= gmwb_flex_base_lapse_mult_crbg;
	}	
	
	//Arctan 2019
	if (income_phase_bef_crbg(t) == 1)
	{
		base_lapse_mult *= arctan_base_inc_mult_crbg;
	}
	else //not applicable if gmwb_max_rollup_duration is 999
	{
		int rollup_shock_yr = max(gmwb_max_rollup_duration, gmwb_doubling_year_crbg) + 1;

		if (pol_yr(t) > rollup_shock_yr)
		{
			base_lapse_mult *= arctan_base_aft_shock_mult_crbg;
		}
		else if (pol_yr(t) == rollup_shock_yr)
		{
			double base_lapse_shock_yr;

			if (annuity_type_crbg == "FA")
			{
				pol_yr_lookup = lapse_shock_year_crbg;
				base_lapse_shock_yr = fa_base_lapse_crbg;
				pol_yr_lookup = lapse_shock_year_crbg;
				base_lapse_shock_yr *= fa_lapse_factor_crbg;
			}
			else
			{
				pol_yr_lookup = lapse_shock_year_crbg;
				base_lapse_shock_yr = lapse_rate_input;
			}

			base_lapse = base_lapse_shock_yr;
			
			base_lapse_mult *= arctan_base_shock_mult_crbg;

			if (shock_lapse_phase_crbg(t) == 1)
			{
				base_lapse_mult += 1.0;
			}
		}
	}
}

if (pba_scen_amt_valn_flag) 
{
	base_lapse_mult *= pba_base_lapse_mult_crbg;
}

return base_lapse * base_lapse_mult * lapse_adj_mult;

}

//@@ END

//@@ START - lapse_rate_mthly
// Lapse Rate Monthly                                                                                             
// Column:LAPSE_RATE_MTHLY
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_rate_mthly(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(226,"lapse_rate_mthly",t);
}



//^^^

#line 1 "lapse_rate_mthly.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (decrements_defn == NO)
	return NO_AVG;

if (fund_val_b_bef(t) > SMALL_DOUBLE)
{
	// Unlocking 2025 lapse skew
	if (lapse_skew_method_crbg == UNLOCKING2025 && !gmwb_flag && shock_lapse_yr_ind_crbg(t) == 1) 
	{
		return lapse_rate_mthly_skew2025_crbg(t);
	}

	double annual_lapse_rate = lapse_rate(t);

	double monthly_lapse_rate = convert_decrem_rate_basis(annual_lapse_rate, EFFECTIVE_ANNUAL, -12);

	//FA lapse skew, Prophet method
	if (annuity_type_crbg == "FA" && lapse_skew_method_crbg == FA_PROPHET)
	{
		double skew_weight = lapse_skew_fct_fa_crbg(t) / lapse_skew_cumul_fct_fa_crbg(t);	
		
		 monthly_lapse_rate = 1 - pow(1 - annual_lapse_rate, skew_weight);
	}

	return monthly_lapse_rate;
}
else
{
	return 0.0;
}


}

//@@ END

//@@ START - lapse_rate_mthly_skew2025_crbg
// Lapse Rate Mthly Skew2025 Crbg                                                                                             
// Column:LAPSE_RATE_MTHLY_SKEW2025_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_rate_mthly_skew2025_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_rate_mthly_skew2025_crbg.FIA_LIAB.for"
//20251216 Customized new column
if (t <= commencement_period || t > maturity_period || lapse_skew_method_crbg != UNLOCKING2025)
	return NO_AVG;

if (decrements_defn == NO || gmwb_flag || shock_lapse_yr_ind_crbg(t) == 0)
	return NO_AVG;

pol_mth_lookup = xint(pol_mth(t));
double curr_skew_fct = lapse_skew_split_crbg;

double cumul_skew_fct = 0.;
double ith_skew_fct;

for (int i = 1; i < pol_mth(t); i++)
{
	pol_mth_lookup = i;
	ith_skew_fct = lapse_skew_split_crbg;

	cumul_skew_fct += ith_skew_fct;
}

double annual_lapse_rate = lapse_rate(t); 
double monthly_lapse_rate = annual_lapse_rate * curr_skew_fct / (1 - annual_lapse_rate * cumul_skew_fct);

return monthly_lapse_rate;

}

//@@ END

//@@ START - lapse_rate_planned_numer
// Lapse Rate Planned Numerator                                                                                             
// Column:LAPSE_RATE_PLANNED_NUMER
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_rate_planned_numer(int t) {
//^^^



//^^^

#line 1 "lapse_rate_planned_numer.FIA_LIAB.for"
return NO_AVG;

}

//@@ END

//@@ START - lapse_skew_cumul_fct_fa_crbg
// Lapse Skew Cumul Fct Fa Crbg                                                                                             
// Column:LAPSE_SKEW_CUMUL_FCT_FA_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_skew_cumul_fct_fa_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_skew_cumul_fct_fa_crbg.FIA_LIAB.for"
//20251216 Customized new column
if (t <= commencement_period || t > final_period || lapse_skew_method_crbg != FA_PROPHET)
	return NO_AVG;

if (decrements_defn == NO)
	return NO_AVG;

double cumul_factor_total = 0.;

if (shock_lapse_yr_ind_crbg(t) == 1)
{
	double skew_factor, base_lapse;
	
	base_lapse = lapse_rate_base(t);

	for (int i = 1; i <= 12; i++)
	{	
		if (i <= shock_skew_mth_crbg)
		{
			skew_factor = 1 / shock_skew_mth_crbg * log(1 - shock_skew_pct_crbg * base_lapse) / log(1 - base_lapse);
		}
		else
		{
			skew_factor = (1 / (12 - shock_skew_mth_crbg)) * log( (1 - base_lapse) / (1 - shock_skew_pct_crbg * base_lapse))
						/ log(1 - base_lapse);
		}

		cumul_factor_total += skew_factor;
	}
}
else
{
	cumul_factor_total = 1.0;
}

return cumul_factor_total;

}

//@@ END

//@@ START - lapse_skew_fct_fa_crbg
// Lapse Skew Fct Fa Crbg                                                                                             
// Column:LAPSE_SKEW_FCT_FA_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_lapse_skew_fct_fa_crbg(int t) {
//^^^



//^^^

#line 1 "lapse_skew_fct_fa_crbg.FIA_LIAB.for"
//20251216 Customized new column
if (t <= commencement_period || t > final_period || lapse_skew_method_crbg != FA_PROPHET)
	return NO_AVG;

if (decrements_defn == NO)
	return NO_AVG;

double skew_factor = 1/12.;

if (shock_lapse_yr_ind_crbg(t) == 1)
{	
	double base_lapse = lapse_rate_base(t);

	if(pol_mth(t) <= shock_skew_mth_crbg)
	{
		skew_factor = 1 / shock_skew_mth_crbg * log(1 - shock_skew_pct_crbg * base_lapse) / log(1 - base_lapse);
	}
	else
	{
		skew_factor = (1 / (12 - shock_skew_mth_crbg)) * log( (1 - base_lapse) / (1 - shock_skew_pct_crbg * base_lapse))
					/ log(1 - base_lapse);
	}

}

return skew_factor;


}

//@@ END

//@@ START - last_period_indicator
// Last Period Indicator                                                                                             
// Column:LAST_PERIOD_INDICATOR
//========================================================
double FIA_LIAB_UDF::fia_liab_last_period_indicator(int t) {
//^^^



//^^^

#line 1 "last_period_indicator.FIA_LIAB.for"
if (!time_step_flag && t == last_proj_period)
	return 1;

if (time_step_flag && proj_set_sub_loop_num == (valn_periods.size() - 1)
	&& t == last_proj_period)
	return 1;

return 0;

}

//@@ END

//@@ START - liab_and_surp
// Liabilities and Surplus Net of Reinsurance                                                                                             
// Column:LIAB_AND_SURP
//========================================================
double FIA_LIAB_UDF::fia_liab_liab_and_surp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(232,"liab_and_surp",t);
}



//^^^

#line 1 "liab_and_surp.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

// force call for reporting
stat_res_mp(t);
stat_res_net(t);
stat_res_net_mp(t);

return stat_res(t)
       - reins_stat_res(t)
       + tgt_cap(t)
       + undistrib_earnings(t);

}

//@@ END

//@@ START - maint_exp_bom
// Maintenance Expenses Beginning of Month                                                                                             
// Column:MAINT_EXP_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_maint_exp_bom(int t) {
//^^^



//^^^

#line 1 "maint_exp_bom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

// included to allow for customization
return NO_AVG;

}

//@@ END

//@@ START - maint_exp_eom
// Maintenance Expenses End of Month                                                                                             
// Column:MAINT_EXP_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_maint_exp_eom(int t) {
//^^^



//^^^

#line 1 "maint_exp_eom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double adj_mult = exp_adj_mult;
			
double maint_exp_per_pol = 0.;

if( fund_val_fixed(t) > model_point_amount_threshold)
{
	maint_exp_per_pol = (this->maint_exp_per_pol / 12.0) 
	  * infl_cumul(t)
	  * policies_b(t)
	  * adj_mult;
 }

//20250520 CRBG logic: Get different types of fund val based fee/expense
xstring index_id;
if (crediting_strategy_crbg(0, 2) == "FX") //Fixed acct same fee as SP
	index_id = "SP";
else
	index_id = crediting_strategy_crbg(0, 2);

index_id_lookup = index_id;
double licensing_fee_pct = licensing_fee_pct_crbg;

double glb_flex_cost = 0.; //TODO: GLB flex cost
double other_cost = this->maint_exp_pct_fund;

double maint_exp_pct_fund
= (licensing_fee_pct + glb_flex_cost + other_cost) / 12.0
   * fund_val_b_bef(t) //fund_val_fixed(t - 1)
   * adj_mult;

double maint_exp_eom_cv = maint_exp_per_pol + maint_exp_pct_fund;

if(pba_scen_amt_valn_flag) 
{
	maint_exp_eom_cv *= pba_maint_exp_mult_crbg;
}

if (gsia_reins_defn_crbg == CEDANT)
{
	maint_exp_pct_fund /= (1 - quota_share_reinsured_crbg); 
	
	maint_exp_eom_cv = maint_exp_per_pol 
					+ maint_exp_pct_fund
					- gwl_maint_exp_allow_crbg(t)
					- gwl_ceding_exp_allow_crbg(t);

}
else if (gsia_reins_defn_crbg == REINSURER)
{
	maint_exp_eom_cv += gwl_maint_exp_allow_crbg(t) + gwl_ceding_exp_allow_crbg(t);
}

return maint_exp_eom_cv;

}

//@@ END

//@@ START - maturity_benefits
// Maturity Benefits                                                                                             
// Column:MATURITY_BENEFITS
//========================================================
double FIA_LIAB_UDF::fia_liab_maturity_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(235,"maturity_benefits",t);
}



//^^^

#line 1 "maturity_benefits.FIA_LIAB.for"
if (t != maturity_period)
	return NO_AVG;

double fund_released = fund_released_dth(t) + fund_released_surr(t) + fund_released_ann(t) + fund_released_withdrl(t);

double fund_val_at_maturity = max(0., fund_val_e_bef(t) - fund_released);

if (ann_ben_partial_credit_ind_crbg == YES)
{
	fund_val_at_maturity *= ( 1.0 + crediting_rate_partial_crbg(t));
}

if (nyia_ind_crbg == YES)
{
	double mav_at_maturity = max(0., min_accum_val_e_bef_crbg(t) - fund_released);

	double mav_cv = min_accum_val_e_bef_crbg(t) * fia->surv_period(t);

	if (mav_cv > SMALL_DOUBLE)
	{
		double mav_reduction_fct = 1. - withdrl_benefits_gross_crbg(t) / mav_cv;

		mav_at_maturity *= mav_reduction_fct;
	}

	mav_at_maturity = max(0., mav_at_maturity);

	return max(fund_val_at_maturity, mav_at_maturity);
}

double mwv_at_maturity = 0.;

if (fund_val_at_maturity > SMALL_DOUBLE)
{
	mwv_at_maturity = max(min_wdl_val_e_bef_crbg(t) * surv_period(t) - withdrl_benefits(t) - mva_amt_excess_withdrl_crbg(t), 0.0);
}

double surr_chg_base = fund_val_at_maturity - prem_bonus_recap_e_crbg(t) - pfwd_entitlement_remaining_e(t);

double surr_chg	= surr_chg_pct_crbg(t) * max(0, surr_chg_base);

return max(fund_val_at_maturity - surr_chg, mwv_at_maturity);

}

//@@ END

//@@ START - min_accum_val_b_bef_crbg
// Min Accum Val B bef Crbg                                                                                             
// Column:MIN_ACCUM_VAL_B_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_min_accum_val_b_bef_crbg(int t) {
//^^^



//^^^

#line 1 "min_accum_val_b_bef_crbg.FIA_LIAB.for"
//20250625 Customized new column
if (t < commencement_period || t > maturity_period || nyia_ind_crbg == NO)
	return NO_AVG;

if (t + elapsed_mths == 1)
{
	return prem_paid(t); //no bonus
}
else
{
	if (pol_yr(t) > surr_chg_period_crbg && pol_mth(t) == 1 )
	{
		double mav_b_bef = max(fund_val_fixed(t - 1),  min_accum_val_e_crbg(t - 1));
		
		return mav_b_bef;
	}

	return min_accum_val_e_crbg(t - 1);
}


}

//@@ END

//@@ START - min_accum_val_e_bef_crbg
// Min Accum Val E bef Crbg                                                                                             
// Column:MIN_ACCUM_VAL_E_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_min_accum_val_e_bef_crbg(int t) {
//^^^



//^^^

#line 1 "min_accum_val_e_bef_crbg.FIA_LIAB.for"
//20250625 Customized new column
if (t < commencement_period || t > maturity_period || nyia_ind_crbg == NO)
	return NO_AVG;

double mav_e_bef = min_accum_val_b_bef_crbg(t) * 
					pow(1.0 + mav_growth_rate_crbg, 1. / 12.);

return mav_e_bef;

}

//@@ END

//@@ START - min_accum_val_e_crbg
// Min Accum Val E Crbg                                                                                             
// Column:MIN_ACCUM_VAL_E_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_min_accum_val_e_crbg(int t) {
//^^^



//^^^

#line 1 "min_accum_val_e_crbg.FIA_LIAB.for"
//20250625 Customized new column
if (t < commencement_period || t > maturity_period || nyia_ind_crbg == NO)
	return NO_AVG;

if(t == 0 && elapsed_mths > 0)
	return init_min_accum_val;

double mav_e_cv = min_accum_val_e_bef_crbg(t) * fia->surv_period(t);

double max_mav_fund_val = max(fund_val_e_bef(t), min_accum_val_e_bef_crbg(t)) * surv_period(t);

if (max_mav_fund_val > SMALL_DOUBLE)
{
	double mav_reduction_fct = 1. - withdrl_benefits_gross_crbg(t) / max_mav_fund_val;

	mav_e_cv *= mav_reduction_fct;
}

return mav_e_cv;

}

//@@ END

//@@ START - min_contract_val
// Minimum Contract Value at EOP                                                                                             
// Column:MIN_CONTRACT_VAL
//========================================================
double FIA_LIAB_UDF::fia_liab_min_contract_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(239,"min_contract_val",t);
}



//^^^

#line 1 "min_contract_val.FIA_LIAB.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

double cash_val_min = 0.0;
double min_guar_surr_value = 0.0;

if (t + elapsed_mths <= min_cash_val_mths)
	cash_val_min = prem_cumul(t) - pfwd_surr_cumul(t);

if(contract_val_sc_defn == YES)
	min_guar_surr_value = contract_val(t) - surr_chg_inf(t);
else
	min_guar_surr_value = contract_val(t);

return max(cash_val_min, min_guar_surr_value);

}

//@@ END

//@@ START - min_contract_val_bef
// Minimum Contract Value Before Claims                                                                                             
// Column:MIN_CONTRACT_VAL_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_min_contract_val_bef(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(240,"min_contract_val_bef",t);
}



//^^^

#line 1 "min_contract_val_bef.FIA_LIAB.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

double cash_val_min = 0.0;
double min_guar_surr_value = 0.0;

if (t + elapsed_mths <= min_cash_val_mths)
	cash_val_min = prem_cumul_bef(t) - pfwd_surr_cumul_bom(t);

if(contract_val_sc_defn == YES)
	min_guar_surr_value = contract_val_bef(t) - surr_chg_inf_bef(t);
else
	min_guar_surr_value = contract_val_bef(t);

return max(cash_val_min, min_guar_surr_value);

}

//@@ END

//@@ START - min_wdl_val_b_crbg
// Min Wdl Val                                                                                             
// Column:MIN_WDL_VAL_B_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_min_wdl_val_b_crbg(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_b_crbg.FIA_LIAB.for"
//20250501 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;  

if (t + elapsed_mths == commencement_period + 1) 
{	
	return prem_issued(t) * mwv_prem_pct_crbg;
}

double min_wdl_val; 

if (fund_val_b(t) > SMALL_DOUBLE) 
{
	min_wdl_val = min_wdl_val_e_crbg(t - 1);

	/*if (state_var_rider_fee_chg_aig == ALLOW_DEDUCT)		
	{
		minimum_withdrawal_value = max(0, minimum_withdrawal_value - gmwb_chg(t));
	}*/
}
else 
{
	min_wdl_val = 0.0;
}

return min_wdl_val;

}

//@@ END

//@@ START - min_wdl_val_e_bef_crbg
// Min Wdl Val E Bef Crbg                                                                                             
// Column:MIN_WDL_VAL_E_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_min_wdl_val_e_bef_crbg(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_e_bef_crbg.FIA_LIAB.for"
//20250501 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

double min_wdl_val;   

if (fund_val_e_bef(t) > SMALL_DOUBLE) 
{
	double monthly_mwv_growth_rate = pow(1.0 + mwv_growth_pct_crbg, 1.0 / 12.0) - 1.0;

	min_wdl_val = min_wdl_val_b_crbg(t) * (1.0 + monthly_mwv_growth_rate);
}
else 
{
	min_wdl_val = 0.0;
}

return min_wdl_val;

}

//@@ END

//@@ START - min_wdl_val_e_crbg
// Min Wdl Val                                                                                             
// Column:MIN_WDL_VAL_E_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_min_wdl_val_e_crbg(int t) {
//^^^



//^^^

#line 1 "min_wdl_val_e_crbg.FIA_LIAB.for"
//20250501 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
{
	return NO_AVG;
}

if (t == commencement_period) 
{
	if (elapsed_mths > 0)
		return init_min_wdl_val;
	
	return 0.0;
}

double min_wdl_val;

if (fund_val_fixed(t) > SMALL_DOUBLE) 
{
	double net_wld_cv = withdrl_benefits(t);

	min_wdl_val = max(min_wdl_val_e_bef_crbg(t) * surv_period(t) - net_wld_cv, 0.0);
}
else 
{
	min_wdl_val = 0.0;
}

return min_wdl_val;

}

//@@ END

//@@ START - mort_rate_exp
// Mort Rate Experience                                                                                             
// Column:MORT_RATE_EXP
//========================================================
double FIA_LIAB_UDF::fia_liab_mort_rate_exp(int t) {
//^^^



//^^^

#line 1 "mort_rate_exp.FIA_LIAB.for"
//if (t < commencement_period || t > maturity_period)
	return NO_AVG;
/*
if (t + elapsed_mths > term_to_omega_age * 12)
	return 1.0;

double mort_rate_life1 = 0.0;
double mort_rate_life2 = 0.0;
double mort_improve_mult = 1.0;
double mort_improve_mult_life2 = 1.0;
double mort_rate = 0.0;
double mort_base = 0.0;
double mort_mult = 1.0;
double mort_addn = 0.0;

if (gender_mp == BLENDED)
	{
	mort_gender = MALE;
	mort_base = this->mort_base;
	mort_gender = MALE;
	mort_mult = this->mort_mult;
	mort_gender = MALE;
	mort_addn = this->mort_addn;

	for (int year = mort_improve_base_yr + 1; year <= cal_yr(t); year++)
		{
		mort_gender = MALE;
		mort_cal_yr = year;
		mort_improve_mult *= (1.0 - mort_improve_pct);
		}

	mort_rate_life1
	= max(0.0, min(1.0, (mort_base * mort_improve_mult)
							* mort_mult           
							+ mort_addn));
			
	// Set life2 lookup keys
	mort_gender = FEMALE;
	mort_base = this->mort_base;
	mort_gender = FEMALE;
	mort_mult = this->mort_mult;
	mort_gender = FEMALE;
	mort_addn = this->mort_addn;

	// Mortality improvement lookup keys are mort_attained_age and cal_yr(t) column
	for (int year = mort_improve_base_yr + 1; year <= cal_yr(t); year++)
		{
		mort_gender = FEMALE;
		mort_cal_yr = year;
		mort_improve_mult_life2 *= (1.0 - mort_improve_pct);
		}
			
	mort_rate_life2
	= max(0.0, min(1.0, (mort_base * mort_improve_mult_life2)
		                    * mort_mult           
				            + mort_addn));

	mort_rate = male_sex_pct * mort_rate_life1
		        + (1.0 - male_sex_pct) * mort_rate_life2;
	}			

else
	{
	mort_gender = (StrEnum::EnumValue) gender_mp;
	mort_base = this->mort_base;
	mort_gender = (StrEnum::EnumValue) gender_mp;
	mort_mult = this->mort_mult;
	mort_gender = (StrEnum::EnumValue) gender_mp;
	mort_addn = this->mort_addn;

	for (int year = mort_improve_base_yr + 1; year <= cal_yr(t); year++)
		{
		mort_gender = (StrEnum::EnumValue) gender_mp;
		mort_cal_yr = year;
		mort_improve_mult *= (1.0 - mort_improve_pct);
		}

	mort_rate
	= max(0.0, min(1.0, (mort_base * mort_improve_mult)
							* mort_mult           
							+ mort_addn));
	}

//apply the calendar month adjustment multiple
mort_rate = max(0.0, min(1.0, mort_rate * mort_adj_mult));			
				
return convert_decrem_rate_basis(mort_rate, EFFECTIVE_ANNUAL, -12);*/

}

//@@ END

//@@ START - mort_rate_gmwb
// Mort Rate GMWB                                                                                             
// Column:MORT_RATE_GMWB
//========================================================
double FIA_LIAB_UDF::fia_liab_mort_rate_gmwb(int t) {
//^^^



//^^^

#line 1 "mort_rate_gmwb.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t + elapsed_mths > term_to_omega_age * 12)
	return 1.0;

double mort_rate_life1 = 0.0;
double mort_rate_life2 = 0.0;
double mort_improve_mult = 1.0;
double mort_improve_mult_life2 = 1.0;
double mort_rate = 0.0;
double gmwb_mort_base;

if (gender_mp == BLENDED)
	{
	// Set life2 lookup keys
	// Life2 age is the same as for life1 for blended mortality
	mort_gender = MALE;
	gmwb_mort_base = this->gmwb_mort_base;
	mort_rate_life1 = max(0.0, min(1.0, gmwb_mort_base));
	
	mort_gender = FEMALE;		
	gmwb_mort_base = this->gmwb_mort_base;
	mort_rate_life2 = max(0.0, min(1.0, gmwb_mort_base));
	
	mort_rate = male_sex_pct * mort_rate_life1
		        + (1.0 - male_sex_pct) * mort_rate_life2;
   	}

else
	{
	mort_gender = (StrEnum::EnumValue) gender_mp;
	gmwb_mort_base = this->gmwb_mort_base;
	mort_rate = max(0.0, min(1.0, gmwb_mort_base));
	}

//apply the calendar month adjustment multiple
mort_rate = max(0.0, min(1.0, mort_rate * mort_adj_mult));			
				
return convert_decrem_rate_basis(mort_rate, EFFECTIVE_ANNUAL, -12);

}

//@@ END

//@@ START - mths_since_issue
// Months Since Issue                                                                                             
// Column:MTHS_SINCE_ISSUE
//========================================================
double FIA_LIAB_UDF::fia_liab_mths_since_issue(int t) {
//^^^



//^^^

#line 1 "mths_since_issue.FIA_LIAB.for"
if (t <= (- elapsed_mths) || t > maturity_period)
	return NO_AVG;

return t + elapsed_mths;

}

//@@ END

//@@ START - mtt_call_gen2classic_cols
// MTT Call Gen2classic Cols                                                                                             
// Column:MTT_CALL_GEN2CLASSIC_COLS
//========================================================
double FIA_LIAB_UDF::fia_liab_mtt_call_gen2classic_cols(int t) {
//^^^



//^^^

#line 1 "mtt_call_gen2classic_cols.FIA_LIAB.for"
//fia columns that can't be vectorized
// column has retained value = Gen2Classic - but comparable time when set to Yes for Seriatim projection.
acq_exp(t);
admin_fee(t);
age_last(t);
ann_benefits_eom(t);
ann_claims_gmwb(t);
annuitzn_rate(t);
annuitzn_rate_mthly(t);
asset_yld(t);
asset_yld_inv(t);
asset_yld_less_dflt_inv(t);
attained_age(t);


bef_tax_yld(t);
bk_prof_aft_tax(t);
bk_prof_aft_tax_for_pv(t);
bk_prof_aft_tax_irr(t);
bk_prof_aft_tax_qtd(t);
bk_prof_aft_tax_ytd(t);
bk_prof_bef_tax(t);
bk_prof_bef_tax_for_pv(t);
bk_prof_bef_tax_qtd(t);
bk_prof_bef_tax_ytd(t);
bk_prof_by_source_bef_tax(t);

cal_mth(t);
cal_yr(t);
cal_yr_relative(t);
cash_val(t);
cash_val_bef(t);
cash_val_wo_mva(t);
zz_cash_val_wo_mva_bef(t);
comm_bom(t);
comm_chargeback(t);
comm_eom(t);
comm_fund_based(t);
comm_prem_based(t);
comm_subject_to_chargeback(t);
comm_subject_to_chargeback_e(t);
contract_val(t);
contract_val_bef(t);
credited_int(t);
crediting_rate(t);
crediting_rate_fix(t);

date(t);
direct_cash_flow_bom(t);
direct_cash_flow_eom(t);
direct_cash_flow_int(t);
distrib_earnings(t);
distrib_earnings_irr(t);
dth_ben_inf(t);
dth_ben_inf_bef(t);
dth_benefits(t);
dth_claim_rate_mthly(t);
earnings_accum(t);

fund_released_ann(t);
fund_released_dth(t);
fund_released_maturity(t);
fund_released_surr(t);
fund_released_withdrl(t);
fund_val_b(t);
fund_val_b_bef(t);
fund_val_e_bef(t);
fund_val_fixed(t);

gaap_acq_exp(t);
gaap_ben_res(t);
gaap_capzd_acq_exp(t);
gaap_capzd_comm_bom(t);
gaap_capzd_comm_eom(t);
gaap_capzd_prem_bonus(t);
gaap_cash_flow_int(t);
gaap_chg_inc(t);
gaap_comm_excess_bom(t);
gaap_comm_excess_eom(t);
gaap_comm_trail_bom(t);
gaap_comm_trail_eom(t);
gaap_credited_int(t);
gaap_dac(t);
gaap_dac_incr(t);
gaap_deferred_tax_liab(t);
gaap_deferred_tax_liab_incr(t);
gaap_dth_claim_cost(t);
gaap_inc_aft_tax(t);
gaap_inc_aft_tax_qtd(t);
gaap_inc_aft_tax_ytd(t);
gaap_inc_bef_tax(t);
gaap_inc_bef_tax_qtd(t);
gaap_inc_bef_tax_ytd(t);
gaap_inv_asset(t);
gaap_inv_inc_cap(t);
gaap_inv_inc_res(t);
gaap_liab_net(t);

gaap_loads_deducted(t);
gaap_maint_exp_bom(t);
gaap_maint_exp_eom(t);
gaap_mrb_liab(t);
gaap_mrb_liab_incr(t);
gaap_prem_bonus(t);
gaap_prem_tax(t);
gaap_req_cap(t);
gaap_sfas133_liab(t);
gaap_sfas133_liab_incr(t);
gaap_surp_incr(t);
gaap_surr_inc(t);
gmwb_chg(t);
gmwb_fund_val_inf(t);
gmwb_fund_val_inf_bef(t);
gmwb_inf(t);
gmwb_inf_bef(t);
gmwb_itm(t);
gmwb_max_wdl_amt(t);
gmwb_income_base_e_crbg(t);
gmwb_income_base_e_bef_crbg(t);
gmwb_rollup_cap_inf(t);
gmwb_rollup_cap_inf_bef(t);

hedge_cash_flow(t);
hedge_cost(t);
hedge_mkt_val(t);
hedge_mkt_val_growth(t);
hedge_mkt_val_incr(t);

infl_cumul(t);
inv_asset(t);
inv_inc_bk_prof(t);
inv_inc_earnings_accum(t);
inv_inc_fund(t);
inv_inc_on_invested_assets(t);
inv_inc_res(t);
inv_inc_tgt_cap(t);
inv_inc_undistrib_earnings(t);
lapse_rate(t);
lapse_rate_base(t);
lapse_rate_mthly(t);
last_period_indicator(t);
liab_and_surp(t);

maint_exp_bom(t);
maint_exp_eom(t);
maturity_benefits(t);
min_contract_val(t);
min_contract_val_bef(t);
mort_rate_exp(t);
mort_rate_gmwb(t);
mva_comp_rate(t);
mva_guar_yrs_remaining(t);
mva_ratio(t);
mva_ratio_bef(t);

opt_budget(t);
opt_payoff(t);
pba_rollforward_base(t);
pba_rollforward_base_issued(t);
pba_rollforward_factor(t);
pfwd_entitlement(t);
pfwd_entitlement_remaining_bom(t);
pfwd_entitlement_remaining_e(t);
pfwd_rate_dynamic(t);
pfwd_rate_mthly_fund_val(t);
pfwd_surr_contract_val(t);
pfwd_surr_cumul(t);
pfwd_surr_cumul_bom(t);
pfwd_surr_curr_pol_yr(t);
pol_mth(t);
pol_yr(t);
policies_b(t);
policies_inf(t);
policies_issued(t);
port_yld_aft_tax(t);
prem_bonus(t);
prem_cumul(t);
prem_cumul_bef(t);
prem_issued(t);
prem_paid(t);
prem_tax(t);
pv_gmwb_benefit_itm(t);
rbc(t);
rbc_c1(t);
rbc_c2(t);
rbc_c2_nar(t);
rbc_c3(t);
rbc_c3_base_ann_high_risk(t);
rbc_c3_base_ann_low_risk(t);
rbc_c3_base_ann_medium_risk(t);
rbc_c3_mp(t);
rbc_c3_stoch_amt(t);
rbc_c3_stoch_amt_unhedged(t);
rbc_c3_unhedged(t);
rbc_c4(t);
reins_ann_benefits_eom(t);
reins_ann_claims_gmwb(t);
reins_cash_flow_bom(t);
reins_cash_flow_eom(t);
reins_cash_flow_int(t);
reins_cash_val(t);
reins_comm_chargeback_reimb(t);
reins_comm_reimb(t);
reins_comm_reimb_bom(t);
reins_comm_reimb_eom(t);
reins_dth_ben_inf(t);
reins_dth_benefits(t);
reins_exp(t);
reins_exp_reimb(t);
reins_exp_reimb_bom(t);
reins_exp_reimb_eom(t);
reins_gaap_ben_res(t);
reins_gaap_capzd_comm_bom(t);
reins_gaap_capzd_comm_eom(t);
reins_gaap_capzd_prem_bonus(t);
reins_gaap_cash_flow_int(t);
reins_gaap_chg_inc(t);
reins_gaap_comm_excess_bom(t);
reins_gaap_comm_excess_eom(t);
reins_gaap_comm_trail_bom(t);
reins_gaap_comm_trail_eom(t);
reins_gaap_cost(t);
reins_gaap_credited_int(t);
reins_gaap_dac(t);
reins_gaap_dac_incr(t);
reins_gaap_inv_inc_res(t);
reins_gaap_liab_net(t);
reins_gaap_loads_deducted(t);
reins_gaap_maint_exp_bom(t);
reins_gaap_maint_exp_eom(t);
reins_gaap_mrb_liab(t);
reins_gaap_mrb_liab_incr(t);
reins_gaap_prem_bonus(t);
reins_gaap_prem_tax(t);
reins_gaap_recoveries(t);
reins_gaap_sfas133_liab(t);
reins_gaap_sfas133_liab_incr(t);
reins_gaap_surr_inc(t);
reins_inv_inc_res(t);
reins_maturity_benefits(t);
reins_prem(t);
reins_prem_base(t);
reins_prem_gmwb(t);
reins_prem_tax(t);
reins_stat_cost(t);
reins_stat_res(t);
reins_stat_res_incr(t);
reins_stat_res_mp(t);
reins_stat_res_unhedged(t);
reins_surr_benefits(t);
reins_tax_res(t);
reins_tax_res_incr(t);
reins_tax_res_mp(t);
reins_withdrl_benefits(t);

stat_res(t);
stat_res_carvm(t);
stat_res_carvm_net(t);
stat_res_excess(t);
stat_res_excess_unhedged(t);
stat_res_incr(t);
stat_res_mp(t);
stat_res_mp_unhedged(t);
stat_res_net(t);
stat_res_net_excess(t);
stat_res_net_excess_unhedged(t);
stat_res_net_mp(t);
stat_res_net_mp_unhedged(t);
stat_res_net_npr(t);
stat_res_net_npr_unhedged(t);
stat_res_net_stoch_res(t);
stat_res_net_stoch_res_unhedged(t);
stat_res_net_unhedged(t);
stat_res_npr(t);
stat_res_npr_unhedged(t);
stat_res_stoch_res(t);
stat_res_stoch_res_unhedged(t);
stat_res_unhedged(t);
surr_benefits(t);
surr_chg_inf(t);
surr_chg_inf_bef(t);
surr_chg_inf_wo_mva(t);
surr_chg_inf_wo_mva_bef(t);
surv_period(t);
tax_bk_prof(t);
tax_bk_prof_ytd(t);
tax_capzd_prem(t);
tax_capzd_prem_amortzn(t);
tax_capzd_prem_unamortzd(t);
tax_earnings_accum(t);
tax_earnings_accum_ytd(t);
tax_res(t);
tax_res_carvm(t);
tax_res_carvm_net(t);
tax_res_incr(t);
tax_res_mp(t);
tax_tgt_cap(t);
tax_tgt_cap_ytd(t);
taxable_inc_bk_prof(t);
taxable_inc_bk_prof_ytd(t);
taxable_inc_carryfwd_addn_ytd(t);
taxable_inc_carryfwd_applied_ytd(t);
taxable_inc_carryfwd_avail(t);
taxable_inc_earnings_accum(t);
taxable_inc_earnings_accum_ytd(t);
taxable_inc_tgt_cap(t);
taxable_inc_tgt_cap_ytd(t);
tgt_cap(t);
tgt_cap_effect(t);
tgt_cap_incr(t);
undistrib_earnings(t);
valn_tgt_gaap_mrb(t);
withdrl_benefits(t);


return 0.0;

}

//@@ END

//@@ START - mtt_call_mbvnb_crbg
// Call columns for MBVNB                                                                                             
// Column:MTT_CALL_MBVNB_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_mtt_call_mbvnb_crbg(int t) {
//^^^



//^^^

#line 1 "mtt_call_mbvnb_crbg.FIA_LIAB.for"
//20250429 Customized new column

surr_chg(t);
surv(t);
pfwd_surr_fund_val(t);

opt_budget(t);

dth_ben_inf(t);
cash_val(t);
fund_val_fixed(t);
credited_int(t);
crediting_rate(t);

//pv_gmwb_ben_itm_current_crbg(t);

dth_benefits(t);
withdrl_benefits(t);
surr_benefits(t);
maturity_benefits(t);
ann_benefits_eom(t);

hedge_cost(t);

pv_bom_cf_disc_uel_crbg(t);
pv_eom_cf_disc_uel_crbg(t);
pv_ann_ben_disc_uel_crbg(t);

return 0.0;

}

//@@ END

//@@ START - mtt_call_vectorized_cols
// MTT Call Vectorized Cols                                                                                             
// Column:MTT_CALL_VECTORIZED_COLS
//========================================================
double FIA_LIAB_UDF::fia_liab_mtt_call_vectorized_cols(int t) {
//^^^



//^^^

#line 1 "mtt_call_vectorized_cols.FIA_LIAB.for"
// column to calculate all the columns and scalars that can be executed vectorized
// make pre-phase by calling a column at non-t, i.e. 0
// ended up leaving as t, and as a consequence all go to Gen2 Classic except disc_rate_port_yld_defn_val.  
// This ended up being more performant compared to making the first 5 columns vectorized - so in theory all other columns could be moved to mtt_cal_gen2classic_cols except disc_rate_port_yld_defn_val.
surr_chg(t);
surv(t);
inv_inc(t);
pfwd_surr_fund_val(t);
asset_yld_less_dflt(t);
disc_rate_1(t);
disc_rate_2(t);
disc_rate_3(t);
disc_rate_port_yld(t); 
disc_rate_port_yld_defn_val(t);//this one goes to Vectorized due to call from liab.irr_calc at start_period + 1
irr_wo_tgt_cap(t);
irr(t);
gaap_prof_aft_tax_for_pv(t);
gaap_prof_bef_tax_for_pv(t);
valn_tgt_gaap_sfas97rd(t);
prem_paid_net(t);
fund_val_decrem(t);
valn_tgt_pba_scen_amt(t);
credited_int_comp_numer(t);
lapse_rate_planned_numer(t);
notional_to_hedge(t);
notional_to_hedge_net(t);
opt_budget_amt(t);
mths_since_issue(t);
gross_prem_annualzd(t);
reins_stat_res_npr(t);
valn_tgt_stat_tax(t);
mva_comp_num(t);
sm_fia_account->notional_to_hedge_cap(t);
sm_fia_account->notional_to_hedge_index(t);
sm_fia_account->notional_to_hedge_long_strike(t);
notional_to_hedge_cap(t);
notional_to_hedge_index(t);
notional_to_hedge_long_strike(t);

return 0.0;

}

//@@ END

//@@ START - mtt_irr
// MTT IRR                                                                                             
// Column:MTT_IRR
//========================================================
double FIA_LIAB_UDF::fia_liab_mtt_irr(int t) {
//^^^



//^^^

#line 1 "mtt_irr.FIA_LIAB.for"
if (t < projection_period_from || t > projection_period_to)
	return 0.0;

irr(t);

return 0.0;

}

//@@ END

//@@ START - mtt_target_all
// Target All                                                                                             
// Column:MTT_TARGET_ALL
//========================================================
double FIA_LIAB_UDF::fia_liab_mtt_target_all(int t) {
//^^^



//^^^

#line 1 "mtt_target_all.FIA_LIAB.for"
if (t < projection_period_from || t > projection_period_to)
	return 0.0;

mtt_call_vectorized_cols(t);
mtt_call_gen2classic_cols(t);

return 0.0;

}

//@@ END

//@@ START - mtt_tgt_distrib_earnings
// March Through Time Target Column                                                                                             
// Column:MTT_TGT_DISTRIB_EARNINGS
//========================================================
double FIA_LIAB_UDF::fia_liab_mtt_tgt_distrib_earnings(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(252,"mtt_tgt_distrib_earnings",t);
}



//^^^

#line 1 "mtt_tgt_distrib_earnings.FIA_LIAB.for"
if (t < projection_period_from || t > projection_period_to)
	return NO_AVG;

distrib_earnings(t);

return NO_AVG;

}

//@@ END

//@@ START - mtt_tgt_gaap_inc_aft_tax
// March Through Time Target Column                                                                                             
// Column:MTT_TGT_GAAP_INC_AFT_TAX
//========================================================
double FIA_LIAB_UDF::fia_liab_mtt_tgt_gaap_inc_aft_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(253,"mtt_tgt_gaap_inc_aft_tax",t);
}



//^^^

#line 1 "mtt_tgt_gaap_inc_aft_tax.FIA_LIAB.for"
if (t < projection_period_from || t > projection_period_to)
	return NO_AVG;

gaap_inc_aft_tax(t);

return NO_AVG;

}

//@@ END

//@@ START - mtt_valn_tgt_gaap_mrb
// March Through Time Target Column                                                                                             
// Column:MTT_VALN_TGT_GAAP_MRB
//========================================================
double FIA_LIAB_UDF::fia_liab_mtt_valn_tgt_gaap_mrb(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(254,"mtt_valn_tgt_gaap_mrb",t);
}



//^^^

#line 1 "mtt_valn_tgt_gaap_mrb.FIA_LIAB.for"
if (t < projection_period_from || t > projection_period_to)
	return NO_AVG;

valn_tgt_gaap_mrb(t);

return NO_AVG;

}

//@@ END

//@@ START - mtt_valn_tgt_gaap_sfas97rd
// March Through Time Target Column - Valuation SFAS97RD                                                                                             
// Column:MTT_VALN_TGT_GAAP_SFAS97RD
//========================================================
double FIA_LIAB_UDF::fia_liab_mtt_valn_tgt_gaap_sfas97rd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(255,"mtt_valn_tgt_gaap_sfas97rd",t);
}



//^^^

#line 1 "mtt_valn_tgt_gaap_sfas97rd.FIA_LIAB.for"
if (t < projection_period_from || t > projection_period_to)
	return NO_AVG;

valn_tgt_gaap_sfas97rd(t);

return NO_AVG;

}

//@@ END

//@@ START - mtt_valn_tgt_pba_scen_amt
// March Through Time Target Column - Valuation PBA Scenario Amount                                                                                             
// Column:MTT_VALN_TGT_PBA_SCEN_AMT
//========================================================
double FIA_LIAB_UDF::fia_liab_mtt_valn_tgt_pba_scen_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(256,"mtt_valn_tgt_pba_scen_amt",t);
}



//^^^

#line 1 "mtt_valn_tgt_pba_scen_amt.FIA_LIAB.for"
if (t < projection_period_from || t > projection_period_to)
	return NO_AVG;

valn_tgt_pba_scen_amt(t);

return NO_AVG;

}

//@@ END

//@@ START - mtt_valn_tgt_stat_tax
// MTT Valuation Stat/Tax                                                                                             
// Column:MTT_VALN_TGT_STAT_TAX
//========================================================
double FIA_LIAB_UDF::fia_liab_mtt_valn_tgt_stat_tax(int t) {
//^^^



//^^^

#line 1 "mtt_valn_tgt_stat_tax.FIA_LIAB.for"
if (t < projection_period_from || t > projection_period_to)
	return 0.0;

valn_tgt_stat_tax(t);

return 0.0;

}

//@@ END

//@@ START - mva_amt_bef_crbg
// Mva Amt Crbg                                                                                             
// Column:MVA_AMT_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_mva_amt_bef_crbg(int t) {
//^^^



//^^^

#line 1 "mva_amt_bef_crbg.FIA_LIAB.for"
//20250501 New column with CRBG logic
if (t < commencement_period || t > maturity_period || mva_defn != CRBG)
	return NO_AVG;

double mva_base = fund_val_e_bef(t); 
double fpw_amount = pfwd_entitlement_remaining_bom(t); 
double premium_enhancement_recapture = prem_bonus_recap_e_bef_crbg(t);

double mva_amount = max(0, mva_base - fpw_amount - premium_enhancement_recapture) * mva_factor_bef_crbg(t);

return mva_amount;

}

//@@ END

//@@ START - mva_amt_crbg
// Mva Amt Crbg                                                                                             
// Column:MVA_AMT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_mva_amt_crbg(int t) {
//^^^



//^^^

#line 1 "mva_amt_crbg.FIA_LIAB.for"
//20250501 New column with CRBG logic
if (t < commencement_period || t > maturity_period || mva_defn != CRBG)
	return NO_AVG;

double mva_base = fund_val_fixed(t); 
double fpw_amount = pfwd_entitlement_remaining_e(t); 
double premium_enhancement_recapture = prem_bonus_recap_e_crbg(t);

double mva_amount = max(0, mva_base - fpw_amount - premium_enhancement_recapture) * mva_factor_crbg(t);

return mva_amount;

}

//@@ END

//@@ START - mva_amt_excess_withdrl_crbg
// Mva Amt due to excess withdrawal                                                                                             
// Column:MVA_AMT_EXCESS_WITHDRL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_mva_amt_excess_withdrl_crbg(int t) {
//^^^



//^^^

#line 1 "mva_amt_excess_withdrl_crbg.FIA_LIAB.for"
//20250506 New column with CRBG logic
//After surr&dth, before withdrl
if (t < commencement_period || t > maturity_period || mva_defn != CRBG)
	return NO_AVG;

double mva_base = gmwb_wdl_amt_e_bef_crbg(t) * surv_period(t);
double fpw_amount = pfwd_entitlement_remaining_bom(t) * surv_period(t);  //pfwd_entitlement already includes GMWB entitled wdl
double premium_enhancement_recapture = prem_bonus_recap_e_bef_crbg(t) * surv_period(t);

double mva_amount = max(0, mva_base - fpw_amount - premium_enhancement_recapture) * mva_factor_bef_crbg(t);

return mva_amount;

}

//@@ END

//@@ START - mva_comp_num
// Competitor MVA Rate Numerator                                                                                             
// Column:MVA_COMP_NUM
//========================================================
double FIA_LIAB_UDF::fia_liab_mva_comp_num(int t) {
//^^^



//^^^

#line 1 "mva_comp_num.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period
	|| fabs(policies_b(t)) < model_point_amount_threshold)
	return NO_AVG;

double fund_val_per_pol = fund_val_b(t) / policies_b(t);
double mva_per_pol_comp = 0.0;	
	
mva_per_pol_comp
= fund_val_per_pol
  * (pow(1.0 + mva_comp_rate(t), 1.0 / 12.0) - 1.0);
		
return mva_per_pol_comp * policies_b(t);

}

//@@ END

//@@ START - mva_comp_rate
// Competitor MVA Rate                                                                                             
// Column:MVA_COMP_RATE
//========================================================
double FIA_LIAB_UDF::fia_liab_mva_comp_rate(int t) {
//^^^



//^^^

#line 1 "mva_comp_rate.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
    return NO_AVG;

if (mva_defn == NOT_APPLICABLE)
    return NO_AVG;

return this->get_comp_rate(mva_comp_rate_id, t);

}

//@@ END

//@@ START - mva_current_term_crbg
// Mva Current Term Crbg                                                                                             
// Column:MVA_CURRENT_TERM_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_mva_current_term_crbg(int t) {
//^^^



//^^^

#line 1 "mva_current_term_crbg.FIA_LIAB.for"
//20251216 Customized new column
if (t <= commencement_period || t > maturity_period || mva_defn != CRBG)
	return NO_AVG;

if (pol_yr(t) <= mva_init_term)
{
	return mva_init_term;
}
else if (pol_yr(t) > myga_init_term_crbg && myga_current_term_crbg(t) > 1)
{
	return mva_renewal_term_crbg;
}

return 0.;

}

//@@ END

//@@ START - mva_factor_bef_crbg
// Mva Factor Crbg                                                                                             
// Column:MVA_FACTOR_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_mva_factor_bef_crbg(int t) {
//^^^



//^^^

#line 1 "mva_factor_bef_crbg.FIA_LIAB.for"
//20250501 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (mva_defn != CRBG || valn_flag)
	return 0.0;

double fund_value = fund_val_e_bef(t); 
double mva_final_factor = 0.0;

if (fund_value > SMALL_DOUBLE && mva_current_term_crbg(t) > 0) 
{
	int N = mva_init_term * 12 - t - elapsed_mths;  
	int mva_init_mth = - valn_period;

	if(myga_renew_ind_crbg == YES)
	{
		N = mva_current_term_crbg(t) * 12 - myga_term_mth_elapsed_eom_crbg(t); 
		mva_init_mth = t - myga_term_mth_elapsed_eom_crbg(t);
	}

	double I = 0.0;
	double J = 0.0;

	I = rates_ptr->get_index_rate(mva_init_mth,"MVA", GET_GROWTH_RATE, EFFECTIVE_ANNUAL); 
							
	J = rates_ptr->get_index_rate(t,"MVA", GET_GROWTH_RATE, EFFECTIVE_ANNUAL);

	double minimum_withdrawal_value = min_wdl_val_e_bef_crbg(t); 
	double prem_bonus_recapture = prem_bonus_recap_e_bef_crbg(t); 
	double pfwd_entitlement = pfwd_entitlement_remaining_bom(t);

	double surr_chg_base = max(fund_value - prem_bonus_recapture - pfwd_entitlement, 0.0);
	double withdrawal_charge = surr_chg_pct * surr_chg_base; 
	
	double mva_factor = (J - I) * (N / 12.0);
	double mva_cap_percent = 1.0 - minimum_withdrawal_value / 
								   (fund_value - withdrawal_charge - prem_bonus_recapture);

	if (mva_cap_defn_crbg == AFTER_2025)
	{
		mva_cap_percent = max(0., (fund_value - withdrawal_charge - minimum_withdrawal_value)/ 
								   (fund_value - pfwd_entitlement));
	}

	double mva_floor_percent = -mva_cap_percent;

	mva_final_factor = max(min(mva_factor, mva_cap_percent), mva_floor_percent);

	/*if(mva_has_cap_floor_aig == NO) //RILA only
	{
		mva_final_factor = mva_factor;
	}*/

}

return mva_final_factor;

}

//@@ END

//@@ START - mva_factor_crbg
// Mva Factor Crbg                                                                                             
// Column:MVA_FACTOR_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_mva_factor_crbg(int t) {
//^^^



//^^^

#line 1 "mva_factor_crbg.FIA_LIAB.for"
//20250501 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (mva_defn != CRBG || valn_flag)
	return 0.0;

double fund_value = fund_val_fixed(t); 
double mva_final_factor = 0.0;

if (fund_value > SMALL_DOUBLE && mva_current_term_crbg(t) > 0) 
{
	int N = mva_init_term * 12 - t - elapsed_mths;  
	int mva_init_mth = - valn_period;

	if(myga_renew_ind_crbg == YES)
	{
		N = mva_current_term_crbg(t) * 12 - myga_term_mth_elapsed_eom_crbg(t); 
		mva_init_mth = t - myga_term_mth_elapsed_eom_crbg(t);
	}

	double I = 0.0;
	double J = 0.0;

	I = rates_ptr->get_index_rate(mva_init_mth,"MVA", GET_GROWTH_RATE, EFFECTIVE_ANNUAL); 
							
	J = rates_ptr->get_index_rate(t,"MVA", GET_GROWTH_RATE, EFFECTIVE_ANNUAL);

	double minimum_withdrawal_value = min_wdl_val_e_crbg(t);
	double prem_bonus_recapture = prem_bonus_recap_e_crbg(t);
	double pfwd_entitlement = pfwd_entitlement_remaining_e(t);
	
	double surr_chg_base = max(fund_value - prem_bonus_recapture - pfwd_entitlement, 0.0);
	double withdrawal_charge = surr_chg_pct * surr_chg_base; 

	double mva_factor = (J - I) * (N / 12.0);
	double mva_cap_percent = 1.0 - minimum_withdrawal_value / 
								   (fund_value - withdrawal_charge - prem_bonus_recapture);

	if (mva_cap_defn_crbg == AFTER_2025)
	{
		mva_cap_percent = max(0., (fund_value - withdrawal_charge - minimum_withdrawal_value)/ 
								   (fund_value - pfwd_entitlement));
	}

	double mva_floor_percent = -mva_cap_percent;

	mva_final_factor = max(min(mva_factor, mva_cap_percent), mva_floor_percent);

	/*if(mva_has_cap_floor_aig == NO) //RILA only
	{
		mva_final_factor = mva_factor;
	}*/

}

return mva_final_factor;

}

//@@ END

//@@ START - mva_guar_yrs_remaining
// MVA Guarantee Years Remaining                                                                                             
// Column:MVA_GUAR_YRS_REMAINING
//========================================================
double FIA_LIAB_UDF::fia_liab_mva_guar_yrs_remaining(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(266,"mva_guar_yrs_remaining",t);
}



//^^^

#line 1 "mva_guar_yrs_remaining.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period && elapsed_mths <= 0)
	return NO_AVG;

if (mva_defn == NOT_APPLICABLE)
	return NO_AVG;

int pol_yr = xint(this->pol_yr(t));
int pol_mth = xint(this->pol_mth(t));

if (mva_init_term > 0)
	{
	if (mva_guar_yrs_renewal == 0
		|| (mva_guar_yrs_renewal > 0 && pol_yr <= mva_init_term))
		return max(mva_init_term - pol_yr 
				   + (12 - pol_mth) / 12.0, 0.0);

	if (mva_guar_yrs_renewal > 0 && pol_yr > mva_init_term)
		return max(mva_guar_yrs_renewal 
				   - ((pol_yr - mva_init_term - 1)
					  % mva_guar_yrs_renewal) 
				   - 1 + (12 - pol_mth) / 12.0, 0.0);
	}

return NO_AVG;

}

//@@ END

//@@ START - mva_ratio
// Market Value Adjustment Ratio End of Month                                                                                             
// Column:MVA_RATIO
//========================================================
double FIA_LIAB_UDF::fia_liab_mva_ratio(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(267,"mva_ratio",t);
}



//^^^

#line 1 "mva_ratio.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return 1.0;

if (mva_defn == NOT_APPLICABLE)
	return 1.0;

if (fabs(mva_guar_yrs_remaining(t)) < model_point_amount_threshold)
	return 1.0;

double mva_ratio_prelim = 0.0;

if (mva_defn == LINEAR)
	mva_ratio_prelim = 1.0 + (mva_comp_rate_issue - mva_comp_rate(t))
				             * mva_adj_ratio_mult
				             * mva_guar_yrs_remaining(t);
else // if (mva_defn == EXPONENTIAL)
	mva_ratio_prelim = pow((1.0 + mva_comp_rate_issue) / (1.0 + mva_comp_rate(t)),
		                   mva_guar_yrs_remaining(t));
		
if (mva_constraint_defn == NO)
	return mva_ratio_prelim;

// else mva_constraint_defn == YES
double return_of_principle = prem_cumul(t) - pfwd_surr_cumul(t);
double surr_chg = 0.0;
double cash_val = 0.0;

if (surr_chg_defn == FUND_VALUE)
	{
	if (surr_chg_timing_defn == BEFORE_MARKET_VALUE_ADJUSTMENT)	
		surr_chg = (fund_val_fixed(t) - pfwd_entitlement_remaining_e(t))
				   * surr_chg_pct;
	else
		surr_chg = (fund_val_fixed(t) - pfwd_entitlement_remaining_e(t))
				   * mva_ratio_prelim * surr_chg_pct;
	}
else // if (surr_chg_defn == PREMIUM)
	surr_chg = prem_cumul(t) * surr_chg_pct;

cash_val = max((fund_val_fixed(t) - pfwd_entitlement_remaining_e(t))
               * mva_ratio_prelim + pfwd_entitlement_remaining_e(t)
               - surr_chg, min_contract_val(t));

if (fabs(fund_val_fixed(t) - pfwd_entitlement_remaining_e(t)) > model_point_amount_threshold)
	return min(1.0, (max(cash_val, return_of_principle) + surr_chg - pfwd_entitlement_remaining_e(t))
	                / (fund_val_fixed(t) - pfwd_entitlement_remaining_e(t)));
	
return 1.0;

}

//@@ END

//@@ START - mva_ratio_bef
// Market Value Adjustment Ratio Before Claims                                                                                             
// Column:MVA_RATIO_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_mva_ratio_bef(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(268,"mva_ratio_bef",t);
}



//^^^

#line 1 "mva_ratio_bef.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return 1.0;

if (mva_defn == NOT_APPLICABLE)
	return 1.0;

if (fabs(mva_guar_yrs_remaining(t)) < model_point_amount_threshold)
	return 1.0;

double mva_ratio_prelim = 0.0;

if (mva_defn == LINEAR)
	mva_ratio_prelim = 1.0 + (mva_comp_rate_issue - mva_comp_rate(t))
				             * mva_adj_ratio_mult
				             * mva_guar_yrs_remaining(t);
else // if (mva_defn == EXPONENTIAL)
	mva_ratio_prelim = pow((1.0 + mva_comp_rate_issue) / (1.0 + mva_comp_rate(t)),
		                   mva_guar_yrs_remaining(t));
		
if (mva_constraint_defn == NO)
	return mva_ratio_prelim;
	
// else mva_constraint_defn == YES
double return_of_principle = prem_cumul_bef(t) - pfwd_surr_cumul_bom(t);
double surr_chg = 0.0;
double cash_val = 0.0;

if (surr_chg_defn == FUND_VALUE)
	{
	if (surr_chg_timing_defn == BEFORE_MARKET_VALUE_ADJUSTMENT)	
		surr_chg = (fund_val_e_bef(t) - pfwd_entitlement_remaining_bom(t))
				   * surr_chg_pct;
	else
		surr_chg = (fund_val_e_bef(t) - pfwd_entitlement_remaining_bom(t))
				   * mva_ratio_prelim * surr_chg_pct;
	}
else // if (surr_chg_defn == PREMIUM)
	surr_chg = prem_cumul_bef(t) * surr_chg_pct;

cash_val = max((fund_val_e_bef(t) - pfwd_entitlement_remaining_bom(t))
               * mva_ratio_prelim + pfwd_entitlement_remaining_bom(t)
               - surr_chg, min_contract_val_bef(t));

if (fabs(fund_val_e_bef(t) - pfwd_entitlement_remaining_bom(t)) > model_point_amount_threshold)
	return min(1.0, (max(cash_val, return_of_principle) + surr_chg - pfwd_entitlement_remaining_bom(t))
	                / (fund_val_e_bef(t) - pfwd_entitlement_remaining_bom(t)));
	
return 1.0;

}

//@@ END

//@@ START - myga_current_term_crbg
// Myga Current Term Crbg                                                                                             
// Column:MYGA_CURRENT_TERM_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_myga_current_term_crbg(int t) {
//^^^



//^^^

#line 1 "myga_current_term_crbg.FIA_LIAB.for"
//20251216 Customized new column
if (t < commencement_period || t > maturity_period || annuity_type_crbg != "FA")
{
	return NO_AVG;	
}

if (t == 0 && valn_period != 0)
	return myga_current_term;

if (pol_yr(t) <= myga_init_term_crbg)
{
	return myga_init_term_crbg;
}

if (mod(myga_term_mth_elapsed_eom_crbg(t - 1), myga_current_term_crbg(t - 1) * 12 ) != 0)
{
	return myga_current_term_crbg(t - 1);
}

if (myga_renew_ind_crbg == NO || attained_age(t) + myga_renew_term_crbg > maturity_age)
{
	return 1.;
}
else
{
	return myga_renew_term_crbg;
}


}

//@@ END

//@@ START - myga_term_mth_elapsed_eom_crbg
// Myga Term Mth Elapsed Eom                                                                                             
// Column:MYGA_TERM_MTH_ELAPSED_EOM_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_myga_term_mth_elapsed_eom_crbg(int t) {
//^^^



//^^^

#line 1 "myga_term_mth_elapsed_eom_crbg.FIA_LIAB.for"
//20251216 Customized new column
if (t < commencement_period || t > maturity_period || annuity_type_crbg != "FA")
{
	return NO_AVG;	
}
else
{
	if (t == 0 && valn_period == 0)
		return 0.;

	if (t == 0 && valn_period > 1)
		return myga_term_mth_elapsed_eom;

	if ( t + elapsed_mths == 1 ) 
	{
		return 1.;
	}
	else
	{
		if ( mod(myga_term_mth_elapsed_eom_crbg(t - 1), myga_current_term_crbg(t - 1) * 12 ) == 0 )
		{
			return 1.;
		}
		else
		{
			return myga_term_mth_elapsed_eom_crbg(t - 1) + 1.;
		}
	}
}

}

//@@ END

//@@ START - new_money_rate_crbg
// mrm ga yield plus matrix spread                                                                                             
// Column:NEW_MONEY_RATE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_new_money_rate_crbg(int t) {
//^^^



//^^^

#line 1 "new_money_rate_crbg.FIA_LIAB.for"
//20250429 Customized new column
if (t <= commencement_period || t > final_period)
	return NO_AVG;

double init_ga_yield = rates_ptr->get_misc_rate(- elapsed_mths, "MRMGAYield", EFFECTIVE_ANNUAL);
double curr_ga_yield = rates_ptr->get_misc_rate(t, "MRMGAYield", EFFECTIVE_ANNUAL);

double matrix_spread = crediting_ner_crbg - init_ga_yield;

double new_money_rate = curr_ga_yield + matrix_spread;

return new_money_rate;

}

//@@ END

//@@ START - nmr_7yr_govt_plus_sprd_crbg
// Nmr 7Yr Govt Plus Sprd                                                                                             
// Column:NMR_7YR_GOVT_PLUS_SPRD_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_nmr_7yr_govt_plus_sprd_crbg(int t) {
//^^^



//^^^

#line 1 "nmr_7yr_govt_plus_sprd_crbg.FIA_LIAB.for"
//20250502 Customized CRBG column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double new_money_rate = rates_ptr->get_int_rate(t, "Govt", GET_YIELD_RATE, 7., 0.0, EFFECTIVE_ANNUAL, NO_SHIFT) 
						+ nmr_spread_crbg;

return new_money_rate;

}

//@@ END

//@@ START - notional_to_hedge
// Notinal Amount to Hedge                                                                                             
// Column:NOTIONAL_TO_HEDGE
//========================================================
double FIA_LIAB_UDF::fia_liab_notional_to_hedge(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(273,"notional_to_hedge",t);
}



//^^^

#line 1 "notional_to_hedge.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	{
	if (static_cast<int>(sm_fia_account[i]->fund_type) == INDEXED)
		total += sm_fia_account[i]->notional_to_hedge(t);	
	}

return total;

}

//@@ END

//@@ START - notional_to_hedge_cap
// Notional Amount to Hedge Cap                                                                                             
// Column:NOTIONAL_TO_HEDGE_CAP
//========================================================
double FIA_LIAB_UDF::fia_liab_notional_to_hedge_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(274,"notional_to_hedge_cap",t);
}



//^^^

#line 1 "notional_to_hedge_cap.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	{
	if (static_cast<int>(sm_fia_account[i]->fund_type) == INDEXED)
		total += sm_fia_account[i]->notional_to_hedge_cap(t);	
	}

return total;

}

//@@ END

//@@ START - notional_to_hedge_index
// Notional Amount to Hedge Index                                                                                             
// Column:NOTIONAL_TO_HEDGE_INDEX
//========================================================
double FIA_LIAB_UDF::fia_liab_notional_to_hedge_index(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(275,"notional_to_hedge_index",t);
}



//^^^

#line 1 "notional_to_hedge_index.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	{
	if (static_cast<int>(sm_fia_account[i]->fund_type) == INDEXED)
		total += sm_fia_account[i]->notional_to_hedge_index(t);	
	}

return total;

}

//@@ END

//@@ START - notional_to_hedge_long_strike
// Notional Amount to Hedge Long Strike                                                                                             
// Column:NOTIONAL_TO_HEDGE_LONG_STRIKE
//========================================================
double FIA_LIAB_UDF::fia_liab_notional_to_hedge_long_strike(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(276,"notional_to_hedge_long_strike",t);
}



//^^^

#line 1 "notional_to_hedge_long_strike.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	{
	if (static_cast<int>(sm_fia_account[i]->fund_type) == INDEXED)
		total += sm_fia_account[i]->notional_to_hedge_long_strike(t);	
	}

return total;

}

//@@ END

//@@ START - notional_to_hedge_net
// Notional Amount to Hedge Net                                                                                             
// Column:NOTIONAL_TO_HEDGE_NET
//========================================================
double FIA_LIAB_UDF::fia_liab_notional_to_hedge_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(277,"notional_to_hedge_net",t);
}



//^^^

#line 1 "notional_to_hedge_net.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	{
	if (static_cast<int>(sm_fia_account[i]->fund_type) == INDEXED)
		total += sm_fia_account[i]->notional_to_hedge_net(t);	
	}

return total;

}

//@@ END

//@@ START - opt_budget
// Available Option Budget                                                                                             
// Column:OPT_BUDGET
//========================================================
double FIA_LIAB_UDF::fia_liab_opt_budget(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(278,"opt_budget",t);
}



//^^^

#line 1 "opt_budget.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (size_t i = 0; i < sm_fia_account.size(); i++)
{
	if (fund_val_b_bef(t) > SMALL_DOUBLE)
	{
		// Weigh by current allocation
		total += sm_fia_account[i]->opt_budget(t) * (sm_fia_account[i]->fund_val_b_bef(t) / fund_val_b_bef(t));
	}
	else
	{
		// Weigh by initial allocation
		total += sm_fia_account[i]->opt_budget(t) * (sm_fia_account[i]->fund_val_split_prop);
	}
}
		
return total;

}

//@@ END

//@@ START - opt_budget_amt
// Option Budget Amount                                                                                             
// Column:OPT_BUDGET_AMT
//========================================================
double FIA_LIAB_UDF::fia_liab_opt_budget_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(279,"opt_budget_amt",t);
}



//^^^

#line 1 "opt_budget_amt.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	{
	if (static_cast<int>(sm_fia_account[i]->fund_type) == INDEXED)
		total += sm_fia_account[i]->opt_budget_amt(t);	
	}

return total;

}

//@@ END

//@@ START - opt_payoff
// Option Payoff                                                                                             
// Column:OPT_PAYOFF
//========================================================
double FIA_LIAB_UDF::fia_liab_opt_payoff(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(280,"opt_payoff",t);
}



//^^^

#line 1 "opt_payoff.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
double total = 0.0;

for (int i = 0; i < sm_fia_account.size(); i++)
	{
	if (static_cast<int>(sm_fia_account[i]->fund_type) == INDEXED)
		total += sm_fia_account[i]->opt_payoff(t);	
	}

return total;

}

//@@ END

//@@ START - pba_rollforward_base
// PBA Rollforward Base                                                                                             
// Column:PBA_ROLLFORWARD_BASE
//========================================================
double FIA_LIAB_UDF::fia_liab_pba_rollforward_base(int t) {
//^^^



//^^^

#line 1 "pba_rollforward_base.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if ((pricing_flag || nb_flag) && t == start_period
	&& valn_period == 0)
	return pba_rollforward_base_issued(1);	

return policies_inf(t);

}

//@@ END

//@@ START - pba_rollforward_base_issued
// PBA Rollforward Base At Issue                                                                                             
// Column:PBA_ROLLFORWARD_BASE_ISSUED
//========================================================
double FIA_LIAB_UDF::fia_liab_pba_rollforward_base_issued(int t) {
//^^^



//^^^

#line 1 "pba_rollforward_base_issued.FIA_LIAB.for"
if (t!= commencement_period + 1
	|| !(pricing_flag || nb_flag)
	|| valn_period != 0)
	return NO_AVG;

return policies_issued(t);

}

//@@ END

//@@ START - pba_rollforward_factor
// PBA Rollforward Factor                                                                                             
// Column:PBA_ROLLFORWARD_FACTOR
//========================================================
double FIA_LIAB_UDF::fia_liab_pba_rollforward_factor(int t) {
//^^^



//^^^

#line 1 "pba_rollforward_factor.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	return 1.0;
	
if (pba_rollforward_base(t - 1) < rate_ratio_threshold)
	return 0.0;

return pba_rollforward_base(t) / pba_rollforward_base(t - 1);

}

//@@ END

//@@ START - pfwd_entitlement
// Penalty Free Withdrawal Entitlement                                                                                             
// Column:PFWD_ENTITLEMENT
//========================================================
double FIA_LIAB_UDF::fia_liab_pfwd_entitlement(int t) {
//^^^



//^^^

#line 1 "pfwd_entitlement.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period && valn_period > 0) 
{
	return init_fund_val_boy * pfwd_pct;
}

if (xint(pol_mth(t)) == 1)
	return pfwd_entitlement_remaining_bom(t)
	       * surv_period(t);

return pfwd_entitlement(t - 1)
       * surv_period(t);

}

//@@ END

//@@ START - pfwd_entitlement_remaining_bom
// Penalty Free Withdrawal Entitlement Remaining Beginning of Month                                                                                             
// Column:PFWD_ENTITLEMENT_REMAINING_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_pfwd_entitlement_remaining_bom(int t) {
//^^^



//^^^

#line 1 "pfwd_entitlement_remaining_bom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (xint(pol_mth(t)) == 1)
{
	double pfwd_base = 0.0;
	double pfwd_pct_local = pfwd_pct;

	if(pba_scen_amt_valn_flag) 
	{
		pfwd_pct_local *= pba_pfwd_pct_mult_crbg;
	}

	//20250502 Replaced with CRBG logic: BOY fund val reduced by withdrawal
	if (pfwd_amt_avail_defn == FUND_VALUE)
	{
		double pfwd_entitlement = max(fund_val_boy_b_crbg(t) * pfwd_pct_local, 0.0);

		if (gmwb_flag)
		{
			pfwd_entitlement = max(pfwd_entitlement, gmwb_entitlement_remaining_b_crbg(t));
		}

		return pfwd_entitlement;
	}
		
	else //pfwd_amt_avail_defn == CUMULATIVE_PREMIUM_LESS_WITHDRAWALS)
	{
		pfwd_base = prem_cumul_bef(t) - pfwd_surr_cumul_bom(t);

		return max(0.0, pfwd_base * pfwd_pct_local);
	}
			
}

return pfwd_entitlement_remaining_e(t - 1);

}

//@@ END

//@@ START - pfwd_entitlement_remaining_e
// Penalty Free Withdrawal Entitlement Remaining End of Month                                                                                             
// Column:PFWD_ENTITLEMENT_REMAINING_E
//========================================================
double FIA_LIAB_UDF::fia_liab_pfwd_entitlement_remaining_e(int t) {
//^^^



//^^^

#line 1 "pfwd_entitlement_remaining_e.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;
	
if (t == commencement_period) 
	{
	if (elapsed_mths > 0)
		return init_pfwd_entitlement;
	
	return 0.0;
	}

//20250506 Replaced withdrl benefit with gross withdrl
double gross_withdrl = withdrl_benefits_gross_crbg(t);

return max(0.0, pfwd_entitlement_remaining_bom(t) * surv_period(t) - gross_withdrl);

}

//@@ END

//@@ START - pfwd_rate_dynamic
// Penalty Free Withdrawal Rate Dynamic                                                                                             
// Column:PFWD_RATE_DYNAMIC
//========================================================
double FIA_LIAB_UDF::fia_liab_pfwd_rate_dynamic(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(287,"pfwd_rate_dynamic",t);
}



//^^^

#line 1 "pfwd_rate_dynamic.FIA_LIAB.for"
if (!gmwb_flag || gmwb_pfwd_dyn_defn == NO)
	return 1.0;

if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double gmwb_dynamic_pfwd = 0.0;

if (gmwb_inf_bef(t) < model_point_amount_threshold
	&& t > commencement_period)
	gmwb_dynamic_pfwd = 1.0;

else if ((xint(pol_mth(t)) != 1 && t != 1 ))
	gmwb_dynamic_pfwd = pfwd_rate_dynamic(t - 1);

else
	gmwb_dynamic_pfwd = min(1.0, gmwb_pfwd_dyn_mult * max(0.0, gmwb_itm(t)));

return gmwb_dynamic_pfwd;

}

//@@ END

//@@ START - pfwd_rate_mthly_fund_val
// Penalty Free Withdrawal Rate Monthly Percent Fund Value                                                                                             
// Column:PFWD_RATE_MTHLY_FUND_VAL
//========================================================
double FIA_LIAB_UDF::fia_liab_pfwd_rate_mthly_fund_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(288,"pfwd_rate_mthly_fund_val",t);
}



//^^^

#line 1 "pfwd_rate_mthly_fund_val.FIA_LIAB.for"
//MQ: This column is not used by CRBG.
if (t <= commencement_period || t > maturity_period) 
	return NO_AVG;
	
double wdl_period = 1.0;

if (pfwd_freq == MONTHLY)
   wdl_period = 1.0;
else if (pfwd_freq == QUARTERLY)
   wdl_period = 3.0;
else // Annual withdrawal
   wdl_period = 12.0;

if (gmwb_flag) 
	{
	if (fabs(fund_val_e_bef(t)) < model_point_amount_threshold) 
		return 0.0;  

	if (pfwd_surr_cumul_bom(t) < model_point_amount_threshold 
		&& (pol_yr(t) <= gmwb_req_yrs_wait + gmwb_exercise_yrs 
		    || fund_val_e_bef(t) < model_point_amount_threshold))
		return 0.0;

	if (mod(pol_mth(t) - 1, wdl_period) == 0.0)
		{
		if (gmwb_cohort_utilz_defn == YES) 
			return min(1.0, gmwb_max_wdl_amt(t) / 12.0 * wdl_period
	              			* gmwb_cohort_utilz_rate / fund_val_e_bef(t)); 

		return min(1.0, gmwb_max_wdl_amt(t) / 12.0 * wdl_period
	              		* pfwd_rate_dynamic(t) / fund_val_e_bef(t));
		}

	return 0.0;
	}

double fund_val_base = fund_val_e_bef(t) * surv_period(t);

// No pfwd if surrender charge or fund value is zero 
if (fabs(fund_val_base) < model_point_amount_threshold) 
	return 0.0;  

if (mod(pol_mth(t) - 1, wdl_period) == 0.0) 
    return min(1.0, pfwd_entitlement(t) * pfwd_use
		   * wdl_period / 12.0
      	 / fund_val_base);

return 0.0;

}

//@@ END

//@@ START - pfwd_surr_contract_val
// Penalty Free Withdrawal Contract Value                                                                                             
// Column:PFWD_SURR_CONTRACT_VAL
//========================================================
double FIA_LIAB_UDF::fia_liab_pfwd_surr_contract_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(289,"pfwd_surr_contract_val",t);
}



//^^^

#line 1 "pfwd_surr_contract_val.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double contract_val_base = contract_val_bef(t) * surv_period(t);

return max(0.0, min(contract_val_base * pfwd_rate_mthly_fund_val(t), 
                    contract_val_base));

}

//@@ END

//@@ START - pfwd_surr_cumul
// Penalty Free Withdrawal Cumulative                                                                                             
// Column:PFWD_SURR_CUMUL
//========================================================
double FIA_LIAB_UDF::fia_liab_pfwd_surr_cumul(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(290,"pfwd_surr_cumul",t);
}



//^^^

#line 1 "pfwd_surr_cumul.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period) 
{
	if (elapsed_mths > 0)
		return init_withdrl_cumul;

	return 0.0;
	}

//20250506 Replaced withdrl benefit with gross withdrl
double gross_withdrl = withdrl_benefits_gross_crbg(t);

return pfwd_surr_cumul_bom(t) * surv_period(t)
       + gross_withdrl;

}

//@@ END

//@@ START - pfwd_surr_cumul_bom
// Penalty Free Withdrawal Cumulative Beginning of Month                                                                                             
// Column:PFWD_SURR_CUMUL_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_pfwd_surr_cumul_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(291,"pfwd_surr_cumul_bom",t);
}



//^^^

#line 1 "pfwd_surr_cumul_bom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return pfwd_surr_cumul(t - 1);

}

//@@ END

//@@ START - pfwd_surr_curr_pol_yr
// Penalty Free Withdrawal Current Policy Year                                                                                             
// Column:PFWD_SURR_CURR_POL_YR
//========================================================
double FIA_LIAB_UDF::fia_liab_pfwd_surr_curr_pol_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(292,"pfwd_surr_curr_pol_yr",t);
}



//^^^

#line 1 "pfwd_surr_curr_pol_yr.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period) 
	{
	if (elapsed_mths > 0)
		return init_pfwd_curr_pol_yr;

	return 0.0;
	}

if (xint(pol_mth(t)) == 1)
	return withdrl_benefits_gross_crbg(t);
	
return pfwd_surr_curr_pol_yr(t - 1) * surv_period(t) + withdrl_benefits_gross_crbg(t);

}

//@@ END

//@@ START - pfwd_surr_fund_val
// Penalty Free Withdrawal Fund Value                                                                                             
// Column:PFWD_SURR_FUND_VAL
//========================================================
double FIA_LIAB_UDF::fia_liab_pfwd_surr_fund_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(293,"pfwd_surr_fund_val",t);
}



//^^^

#line 1 "pfwd_surr_fund_val.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double fund_val_base = fund_val_e_bef(t) * surv_period(t);

return max(0.0, min(fund_val_base * pfwd_rate_mthly_fund_val(t), 
                    fund_val_base));

}

//@@ END

//@@ START - pfwd_use_crbg
// Pfwd Use Crbg                                                                                             
// Column:PFWD_USE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_pfwd_use_crbg(int t) {
//^^^



//^^^

#line 1 "pfwd_use_crbg.FIA_LIAB.for"
//20250502 New column with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double pfwd_use = 0.0;

double pfwd_use_q = pfwd_use_q_crbg;
double pfwd_use_nq = pfwd_use_nq_crbg;

double pfwd_pct_local = pfwd_pct;

if(pba_scen_amt_valn_flag) 
{
	pfwd_pct_local *= pba_pfwd_pct_mult_crbg;
}

//to udpate the Qualified component of the partial WD rate in case attained age is greater than or equal to RMD attained age.
if (pfwd_pct_local > SMALL_DOUBLE)
{
	if (attained_age(t) >= rmd_age_crbg)
	{
		pfwd_use_q = pfwd_rate_calc_fct1_crbg * exp( pfwd_rate_calc_fct2_crbg * (attained_age(t) - rmd_age_crbg + 1)) / pfwd_pct_local;
	}
	//Calculate the total partial withdrawal amount
	pfwd_use = pfwd_use_q * pfwd_use_qual_pct_crbg + pfwd_use_nq * ( 1 - pfwd_use_qual_pct_crbg);
} 

//apply an additional w/d rate in shock year
if(pol_yr(t) == lapse_shock_year_crbg)  
{
	pfwd_use += pfwd_use_addl_shock_yr_crbg; 
}

else if (myga_renew_ind_crbg == YES && pol_yr(t) > myga_init_term_crbg && myga_current_term_crbg(t) > 1)
{
	//Case 1: MVA term is the same as MYGA term, then first year after renewal is shock year
	//Case 2: MVA term is shorter than MYGA term, then first year after MVA is shock year
	//Assumes SC period is equal to MVA or 0	
	if ( (myga_renew_term_crbg == mva_renewal_term_crbg && myga_term_mth_elapsed_eom_crbg(t) <= 12) ||
		(myga_term_mth_elapsed_eom_crbg(t) > mva_renewal_term_crbg * 12 && myga_term_mth_elapsed_eom_crbg(t) <= mva_renewal_term_crbg * 12 + 12))
	{
		pfwd_use += pfwd_use_addl_shock_yr_crbg;
	}
}

return pfwd_use;

}

//@@ END

//@@ START - pol_mth
// Policy Month                                                                                             
// Column:POL_MTH
//========================================================
double FIA_LIAB_UDF::fia_liab_pol_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(295,"pol_mth",t);
}



//^^^

#line 1 "pol_mth.FIA_LIAB.for"
if (t < commencement_period || t > t_high)
	return NO_AVG;

return int(t + elapsed_mths - 1) % 12 + 1;

}

//@@ END

//@@ START - pol_yr
// Policy Year                                                                                             
// Column:POL_YR
//========================================================
double FIA_LIAB_UDF::fia_liab_pol_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(296,"pol_yr",t);
}



//^^^

#line 1 "pol_yr.FIA_LIAB.for"
if (t < commencement_period || t > t_high)
	return NO_AVG;
	
cal_yr_relative(t);
cal_mth(t);

if (t == commencement_period) 
	{
	if (elapsed_mths <= 0)
		return NO_AVG;
	else
		return xint((elapsed_mths - 1) / 12.0) + 1.0;
	}
 
if (xint(pol_mth(t)) == 1)
	return pol_yr(t - 1) + 1.0;
	
return pol_yr(t - 1);

}

//@@ END

//@@ START - policies_b
// Policies In Force Beginning of Month                                                                                             
// Column:POLICIES_B
//========================================================
double FIA_LIAB_UDF::fia_liab_policies_b(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(297,"policies_b",t);
}



//^^^

#line 1 "policies_b.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period + 1)
	return init_policies;

if ((surv_period(t - 1) < model_point_amount_threshold)
	|| (ann_claims_gmwb(t - 1) > model_point_amount_threshold && calc_pv_gmwb_av_exhaustion_crbg == YES))
	return 0.0;

return policies_b(t - 1) 
       * surv_period(t - 1);

}

//@@ END

//@@ START - policies_female_inf_crbg
// Policies Female                                                                                             
// Column:POLICIES_FEMALE_INF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_policies_female_inf_crbg(int t) {
//^^^



//^^^

#line 1 "policies_female_inf_crbg.FIA_LIAB.for"
//20250501 CRBG customized column
if (t < commencement_period || t > maturity_period) 
	return NO_AVG;

if (gender_mp != JOINT)
{
	return NO_AVG;		
}

double policies_female;
					
if (t == 0 && elapsed_mths == 0)
{
	policies_female = 0.; 
} 	
else if (t == 0 && elapsed_mths > 0)
{
	policies_female = init_policies_female_crbg;
} 					
else
{
	double policies_female_bom = policies_female_inf_crbg(t - 1);
	double policies_joint_bom = policies_joint_inf_crbg(t - 1);
	double spousal_cont_elect_rate;
	double fund_val_b_cv = fund_val_b(t);

	if (gender_mp != gender_aft_inc && t + elapsed_mths == gmwb_exercise_yrs * 12 + 1)
	{
		if (gender_aft_inc == JOINT)
		{
			policies_joint_bom = policies_joint_inf_crbg(t - 1) + policies_male_inf_crbg(t - 1) +
										policies_female_inf_crbg(t - 1);
			policies_female_bom = 0;
		}
		else if (gender_aft_inc == FEMALE)
		{
			policies_female_bom = policies_joint_inf_crbg(t - 1) + policies_male_inf_crbg(t - 1) +
									policies_female_inf_crbg(t - 1);
			policies_joint_bom = 0;
		}
		else if (gender_aft_inc == MALE)
		{
			policies_female_bom = 0;
			policies_joint_bom = 0;
		}
	}

	if (fund_val_b_cv > SMALL_DOUBLE)  
	{
		spousal_cont_elect_rate = spousal_cont_elect_rate_crbg;
	}
	else
	{
		spousal_cont_elect_rate = 1.0;
	}

	double dth_rate_mthly_male = dth_rate_mthly_male_crbg(t);						
	double dth_rate_mthly_female = dth_rate_mthly_female_crbg(t);				
				
	policies_female = policies_joint_bom * dth_rate_mthly_male * (1.0 - dth_rate_mthly_female) * spousal_cont_elect_rate
						+ policies_female_bom * (1.0 - dth_rate_mthly_female);
}							

return policies_female;

}

//@@ END

//@@ START - policies_inf
// Policies In Force                                                                                             
// Column:POLICIES_INF
//========================================================
double FIA_LIAB_UDF::fia_liab_policies_inf(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(299,"policies_inf",t);
}



//^^^

#line 1 "policies_inf.FIA_LIAB.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (t == commencement_period)
	{
	if (elapsed_mths > 0)
		return init_policies;
	else
		return NO_AVG;
	}	

if (surv_period(t) < model_point_amount_threshold
	|| (ann_claims_gmwb(t) > model_point_amount_threshold && calc_pv_gmwb_av_exhaustion_crbg == YES))
	return 0.0;
	
return policies_b(t + 1);

}

//@@ END

//@@ START - policies_issued
// Policies Issued                                                                                             
// Column:POLICIES_ISSUED
//========================================================
double FIA_LIAB_UDF::fia_liab_policies_issued(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(300,"policies_issued",t);
}



//^^^

#line 1 "policies_issued.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period + 1.)
	return init_policies;

return NO_AVG;

}

//@@ END

//@@ START - policies_joint_inf_crbg
// Policies: Joint                                                                                             
// Column:POLICIES_JOINT_INF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_policies_joint_inf_crbg(int t) {
//^^^



//^^^

#line 1 "policies_joint_inf_crbg.FIA_LIAB.for"
//20250501 CRBG customized column
if (t < commencement_period || t > maturity_period) 
	return NO_AVG;

if (gender_mp != JOINT)
{
	return NO_AVG;		
}

double policies_joint;
					
if (t == 0 && elapsed_mths == 0)
{
	policies_joint = init_policies; 
} 	
else if (t == 0 && elapsed_mths > 0)
{
	policies_joint = init_policies_joint_crbg;
} 					
else
{
	double policies_joint_bom = policies_joint_inf_crbg(t - 1);

	double dth_rate_mthly_male = dth_rate_mthly_male_crbg(t);						
	double dth_rate_mthly_female = dth_rate_mthly_female_crbg(t);				

	if (gender_mp != gender_aft_inc && t + elapsed_mths == gmwb_exercise_yrs * 12 + 1)
	{
		if (gender_aft_inc == JOINT)
		{
			policies_joint_bom = policies_joint_inf_crbg(t - 1) + policies_male_inf_crbg(t - 1) +
										policies_female_inf_crbg(t - 1);
		}
		else if (gender_aft_inc == FEMALE || gender_aft_inc == MALE)
		{
			policies_joint_bom = 0;
		}
	}
	
	policies_joint = policies_joint_bom * (1.0 - dth_rate_mthly_male) * (1.0 - dth_rate_mthly_female);
}							

return policies_joint;

}

//@@ END

//@@ START - policies_last_survivor_inf_crbg
// Policies: Last Survivor                                                                                             
// Column:POLICIES_LAST_SURVIVOR_INF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_policies_last_survivor_inf_crbg(int t) {
//^^^



//^^^

#line 1 "policies_last_survivor_inf_crbg.FIA_LIAB.for"
//20250501 CRBG customized column
if (t < commencement_period || t > maturity_period) 
	return NO_AVG;

if (gender_mp != JOINT)// && spousal_continuation_defn_aig == NONE) 
{	
	return NO_AVG;
}	
	
double policies_last_survivor = policies_joint_inf_crbg(t) + policies_male_inf_crbg(t) + policies_female_inf_crbg(t);	
	
return policies_last_survivor;	


}

//@@ END

//@@ START - policies_male_inf_crbg
// Policies Male                                                                                             
// Column:POLICIES_MALE_INF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_policies_male_inf_crbg(int t) {
//^^^



//^^^

#line 1 "policies_male_inf_crbg.FIA_LIAB.for"
//20250501 CRBG customized column
if (t < commencement_period || t > maturity_period) 
	return NO_AVG;

if (gender_mp != JOINT)
{
	return NO_AVG;		
}

double policies_male;
					
if (t == 0 && elapsed_mths == 0)
{
	policies_male = 0.; 
} 	
else if (t == 0 && elapsed_mths > 0)
{
	policies_male = init_policies_male_crbg;
} 
else
{
	double policies_male_bom = policies_male_inf_crbg(t - 1);
	double policies_joint_bom = policies_joint_inf_crbg(t - 1);
	double spousal_cont_elect_rate;
	double fund_val_b_cv = fund_val_b(t);

	if (gender_mp != gender_aft_inc && t + elapsed_mths == gmwb_exercise_yrs * 12 + 1)
	{
		if (gender_aft_inc == JOINT)
		{
			policies_joint_bom = policies_joint_inf_crbg(t - 1) + policies_male_inf_crbg(t - 1) +
										policies_female_inf_crbg(t - 1);
			policies_male_bom = 0;
		}
		else if (gender_aft_inc == MALE)
		{
			policies_male_bom = policies_joint_inf_crbg(t - 1) + policies_male_inf_crbg(t - 1) +
									policies_female_inf_crbg(t - 1);
			policies_joint_bom = 0;
		}
		else if (gender_aft_inc == FEMALE)
		{
			policies_male_bom = 0;
			policies_joint_bom = 0;
		}
	}

	if (fund_val_b_cv > SMALL_DOUBLE)  
	{
		spousal_cont_elect_rate = spousal_cont_elect_rate_crbg;
	}
	else
	{
		spousal_cont_elect_rate = 1.0;
	}

	double dth_rate_mthly_male = dth_rate_mthly_male_crbg(t);						
	double dth_rate_mthly_female = dth_rate_mthly_female_crbg(t);				
				
	policies_male = policies_joint_bom * dth_rate_mthly_female * (1.0 - dth_rate_mthly_male) * spousal_cont_elect_rate
						+ policies_male_bom * (1.0 - dth_rate_mthly_male);
}							

return policies_male;

}

//@@ END

//@@ START - port_yld_aft_tax
// Portfolio Yield After Tax                                                                                             
// Column:PORT_YLD_AFT_TAX
//========================================================
double FIA_LIAB_UDF::fia_liab_port_yld_aft_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(304,"port_yld_aft_tax",t);
}



//^^^

#line 1 "port_yld_aft_tax.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return bef_tax_yld(t)
      * (1.0 - tax_rate);

}

//@@ END

//@@ START - prem_bonus
// Premium Bonus                                                                                             
// Column:PREM_BONUS
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_bonus(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(305,"prem_bonus",t);
}



//^^^

#line 1 "prem_bonus.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return prem_paid(t) * (prem_credit);

}

//@@ END

//@@ START - prem_bonus_base_e_bef_crbg
// Prem Bonus Base E Bef Crbg                                                                                             
// Column:PREM_BONUS_BASE_E_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_bonus_base_e_bef_crbg(int t) {
//^^^



//^^^

#line 1 "prem_bonus_base_e_bef_crbg.FIA_LIAB.for"
//20250520 New Column with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double prem_bonuses_base_prev	= prem_bonus_base_e_crbg(t - 1);
double bonus_cv					= prem_bonus(t);

return prem_bonuses_base_prev + bonus_cv;

}

//@@ END

//@@ START - prem_bonus_base_e_crbg
// Prem Bonus Base E Crbg                                                                                             
// Column:PREM_BONUS_BASE_E_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_bonus_base_e_crbg(int t) {
//^^^



//^^^

#line 1 "prem_bonus_base_e_crbg.FIA_LIAB.for"
//20250520 New Column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period && elapsed_mths > 0)
	return init_prem_bonus_base;

double prem_bonus_base = prem_bonus_base_e_bef_crbg(t) * surv_period(t);

prem_bonus_base = max(0, prem_bonus_base * (1 - prem_bonus_base_reduction_fct_crbg(t)));

return prem_bonus_base;

}

//@@ END

//@@ START - prem_bonus_base_reduction_fct_crbg
// Prem Bonus Base Reduction Fct Crbg                                                                                             
// Column:PREM_BONUS_BASE_REDUCTION_FCT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_bonus_base_reduction_fct_crbg(int t) {
//^^^



//^^^

#line 1 "prem_bonus_base_reduction_fct_crbg.FIA_LIAB.for"
//20250520 New Column with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double fund_val_cv = fund_val_e_bef(t) * surv_period(t);
if (fund_val_cv < SMALL_DOUBLE)
{
	return 0.0;
}


double pfwd_entitlement_cv	= pfwd_entitlement_remaining_bom(t) * surv_period(t);
double gross_withdrl_cv		= withdrl_benefits_gross_crbg(t);
double penalty_withdrl_cv	= max(0, gross_withdrl_cv - pfwd_entitlement_cv);

if (fund_val_cv - pfwd_entitlement_cv < SMALL_DOUBLE) 
{
	return 0.0;
}

double reduction_fct = penalty_withdrl_cv / (fund_val_cv - pfwd_entitlement_cv); 

return reduction_fct;

}

//@@ END

//@@ START - prem_bonus_recap_e_bef_crbg
// Prem Bonus Recap E Bef Crbg                                                                                             
// Column:PREM_BONUS_RECAP_E_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_bonus_recap_e_bef_crbg(int t) {
//^^^



//^^^

#line 1 "prem_bonus_recap_e_bef_crbg.FIA_LIAB.for"
//20250520 New Column with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double recapture_bonus_cv = prem_bonus_base_e_bef_crbg(t) * prem_bonus_recap_pct_crbg;

return recapture_bonus_cv;

}

//@@ END

//@@ START - prem_bonus_recap_e_crbg
// Prem Bonus Recap E Crbg                                                                                             
// Column:PREM_BONUS_RECAP_E_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_bonus_recap_e_crbg(int t) {
//^^^



//^^^

#line 1 "prem_bonus_recap_e_crbg.FIA_LIAB.for"
//20250520 New Column with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double recapture_bonus = prem_bonus_base_e_crbg(t) * prem_bonus_recap_pct_crbg;

return recapture_bonus;

}

//@@ END

//@@ START - prem_cumul
// Premium Cumulative End of Month                                                                                             
// Column:PREM_CUMUL
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_cumul(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(311,"prem_cumul",t);
}



//^^^

#line 1 "prem_cumul.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period) 
	{
	if (elapsed_mths > 0)
		return single_prem;
	
	return 0.0;
	}

return prem_cumul_bef(t) * surv_period(t);

}

//@@ END

//@@ START - prem_cumul_bef
// Premium Cumulative End of Month Before Claims                                                                                             
// Column:PREM_CUMUL_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_cumul_bef(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(312,"prem_cumul_bef",t);
}



//^^^

#line 1 "prem_cumul_bef.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return prem_cumul(t - 1) + prem_paid(t);

}

//@@ END

//@@ START - prem_cumul_net_wdl_bef_crbg
// Prem Cumul Net Wdl Bef Crbg                                                                                             
// Column:PREM_CUMUL_NET_WDL_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_cumul_net_wdl_bef_crbg(int t) {
//^^^



//^^^

#line 1 "prem_cumul_net_wdl_bef_crbg.FIA_LIAB.for"
//20251022 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
{
	return NO_AVG;
}

double prem_cumul_net_wdl_bef = prem_cumul_net_wdl_crbg(t - 1) + prem_paid(t);

return prem_cumul_net_wdl_bef;

}

//@@ END

//@@ START - prem_cumul_net_wdl_crbg
// Prem Cumul Net Wdl Crbg                                                                                             
// Column:PREM_CUMUL_NET_WDL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_cumul_net_wdl_crbg(int t) {
//^^^



//^^^

#line 1 "prem_cumul_net_wdl_crbg.FIA_LIAB.for"
//20251022 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
{
	return NO_AVG;
}

if (t == commencement_period) 
{
	if (elapsed_mths > 0)
		return init_prem_net_wdl;
	
	return 0.0;
}

double prem_cumul_net_wdl = max(prem_cumul_net_wdl_bef_crbg(t) * surv_period(t) - withdrl_benefits_gross_crbg(t), 0.0);												

return prem_cumul_net_wdl;

}

//@@ END

//@@ START - prem_cumul_prop_wdl_bef_crbg
// Prem Cumul Prop Wdl Bef Crbg                                                                                             
// Column:PREM_CUMUL_PROP_WDL_BEF_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_cumul_prop_wdl_bef_crbg(int t) {
//^^^



//^^^

#line 1 "prem_cumul_prop_wdl_bef_crbg.FIA_LIAB.for"
//20251211 New columns with CRBG logic
if (t < commencement_period || t > maturity_period)
{
	return NO_AVG;
}

return prem_cumul_prop_wdl_crbg(t - 1) + prem_paid(t);


}

//@@ END

//@@ START - prem_cumul_prop_wdl_crbg
// Prem Cumul Prop Wdl Crbg                                                                                             
// Column:PREM_CUMUL_PROP_WDL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_cumul_prop_wdl_crbg(int t) {
//^^^



//^^^

#line 1 "prem_cumul_prop_wdl_crbg.FIA_LIAB.for"
//20251211 New columns with CRBG logic
if (t < commencement_period || t > maturity_period)
{
	return NO_AVG;
}

if (t == commencement_period) 
{
	if (elapsed_mths > 0)
		return init_prem_prop_wdl;
	
	return 0.0;
}

double av_bef_withdrl = max(fund_val_e_bef(t) * surv_period(t), 0.0);
double av_aft_withdrl = max(av_bef_withdrl - fund_released_withdrl(t), 0.0);
double reduction_factor = 1.0;
	
if (av_bef_withdrl > SMALL_DOUBLE)
{
	reduction_factor = av_aft_withdrl / av_bef_withdrl;
}

double prem_cumul_net_wdl_cv = max(prem_cumul_prop_wdl_bef_crbg(t) * surv_period(t) * reduction_factor, 0.0);

return prem_cumul_net_wdl_cv;

}

//@@ END

//@@ START - prem_issued
// Premium Issued                                                                                             
// Column:PREM_ISSUED
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_issued(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(317,"prem_issued",t);
}



//^^^

#line 1 "prem_issued.FIA_LIAB.for"
if (elapsed_mths > 0 || t != commencement_period + 1)
	return NO_AVG;

double single_prem_cv = single_prem;

if (gsia_reins_defn_crbg == REINSURER)
{
	single_prem_cv *= quota_share_reinsured_crbg; 
}
else if (gsia_reins_defn_crbg == CEDANT)
{
	single_prem_cv *= (1 - quota_share_reinsured_crbg);
}

return single_prem_cv;

}

//@@ END

//@@ START - prem_paid
// Premium Paid                                                                                             
// Column:PREM_PAID
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_paid(int t) {
//^^^



//^^^

#line 1 "prem_paid.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (pol_yr(t) > 1 || pol_mth(t) > 1)
	return 0.0;

//called for reporting purpose
prem_issued(t);

double prem_paid_cv = single_prem;

if (gsia_reins_defn_crbg == REINSURER)
{
	prem_paid_cv *= quota_share_reinsured_crbg; 
}
else if (gsia_reins_defn_crbg == CEDANT)
{
	prem_paid_cv *= (1 - quota_share_reinsured_crbg);
}

return prem_paid_cv;

}

//@@ END

//@@ START - prem_paid_net
// Premium Paid Net                                                                                             
// Column:PREM_PAID_NET
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_paid_net(int t) {
//^^^



//^^^

#line 1 "prem_paid_net.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return prem_paid(t) 
	   - reins_prem(t)
	   + reins_prem_tax(t);

}

//@@ END

//@@ START - prem_tax
// Premium Tax                                                                                             
// Column:PREM_TAX
//========================================================
double FIA_LIAB_UDF::fia_liab_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(320,"prem_tax",t);
}



//^^^

#line 1 "prem_tax.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return prem_paid(t) * prem_tax_pct;

}

//@@ END

//@@ START - pv_ann_ben_disc_uel_crbg
// Pv Eom Cf Disc Rf Crbg                                                                                             
// Column:PV_ANN_BEN_DISC_UEL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_pv_ann_ben_disc_uel_crbg(int t) {
//^^^



//^^^

#line 1 "pv_ann_ben_disc_uel_crbg.FIA_LIAB.for"
//202502 New Column: PV BOM cash flows
if (t < commencement_period || t > final_period || alm_flag)
	return NO_AVG;

double eom_cf = ann_benefits_eom(t + 1);
						
return (eom_cf + pv_ann_ben_disc_uel_crbg(t + 1)) / (1.0 + disc_rate_rf_sprd_uel_crbg(t + 1));

}

//@@ END

//@@ START - pv_bom_cf_disc_uel_crbg
// Pv Bom Cf Disc Rf Crbg                                                                                             
// Column:PV_BOM_CF_DISC_UEL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_pv_bom_cf_disc_uel_crbg(int t) {
//^^^



//^^^

#line 1 "pv_bom_cf_disc_uel_crbg.FIA_LIAB.for"
//202502 New Column: PV BOM cash flows
if (t < commencement_period || t > final_period || alm_flag)
	return NO_AVG;

double bom_cf = comm_bom(t + 1) + acq_exp (t + 1) ; 

return bom_cf + pv_bom_cf_disc_uel_crbg(t + 1) / (1.0 + disc_rate_rf_sprd_uel_crbg(t + 1));

}

//@@ END

//@@ START - pv_eom_cf_disc_uel_crbg
// Pv Eom Cf Disc Rf Crbg                                                                                             
// Column:PV_EOM_CF_DISC_UEL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_pv_eom_cf_disc_uel_crbg(int t) {
//^^^



//^^^

#line 1 "pv_eom_cf_disc_uel_crbg.FIA_LIAB.for"
//202502 New Column: PV EOM cash flows
if (t < commencement_period || t > final_period || alm_flag)
	return NO_AVG;

double eom_cf = dth_benefits(t + 1) + surr_benefits(t + 1) + withdrl_benefits(t + 1) + maturity_benefits(t + 1) + ann_benefits_eom(t + 1)
						- comm_chargeback(t + 1) + maint_exp_eom(t + 1);

return (eom_cf + pv_eom_cf_disc_uel_crbg(t + 1)) / (1.0 + disc_rate_rf_sprd_uel_crbg(t + 1));

}

//@@ END

//@@ START - pv_gmwb_ben_itm_current_crbg
// Pv Gmwb Benefit using current swap rate                                                                                             
// Column:PV_GMWB_BEN_ITM_CURRENT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_pv_gmwb_ben_itm_current_crbg(int t) {
//^^^



//^^^

#line 1 "pv_gmwb_ben_itm_current_crbg.FIA_LIAB.for"
//20250507 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag || gmwb_inf_bef(t) < SMALL_DOUBLE)
	return NO_AVG;

StrEnum::EnumValue gender_cv = gender_mp;
if (gender_mp != gender_aft_inc && t + elapsed_mths > gmwb_exercise_yrs * 12 + 1)
{
	gender_cv = gender_aft_inc;
}

double gmwb_income_base = gmwb_inf_bef(t);
double mawp = pv_gmwb_mawp_crbg(t);
double pipp = pv_gmwb_pip_pct_crbg(t);
double period_wdl = gmwb_income_base * mawp / 12.;
double enhanced_wdl = period_wdl * enh_inc_mawp_mult;
double disc_wdls = period_wdl;

double cumm_surv = 1.0;
double joint_cumm_surv  = 1.0;	
double male_cumm_surv   = 1.0;
double female_cumm_surv = 1.0;
double last_surv_cumm_surv = 1.0;

double disc_rt, period_disc;

if (!valn_flag)
	disc_rt = rates_ptr->get_int_rate(t, itm_disc_curve_crbg, GET_YIELD_RATE, 10., 0, EFFECTIVE_ANNUAL, NO_SHIFT); //10-yr swap rate
else
	disc_rt = rates_ptr->get_int_rate(t, "Govt", GET_YIELD_RATE, 10., 0, EFFECTIVE_ANNUAL, NO_SHIFT);

bool claim_stage = false;

int enh_inc_cumul_mths = 0;
if (xint(enh_inc_exercise_flag_crbg(t)) == 1)
{
	disc_wdls = enhanced_wdl;
	enh_inc_cumul_mths = max(0, enh_inc_exercise_cumul_yrs_crbg(t) - 1) * 12 + pol_mth(t);
}

double fund_val	= fund_val_e_bef(t) - disc_wdls;

int max_life = (term_to_omega_age * 12.0) - elapsed_mths;
for (int i = t + 1; i <= max_life; i = i + 1)
{
	int pol_yr = int((i + elapsed_mths - 1) / 12.0 + 1);
	int pol_mth = int(i + elapsed_mths - 1) % 12 + 1;

	if (xint(enh_inc_exercise_flag_crbg(t)) == 1 && enh_inc_cumul_mths <= enh_inc_max_cumul_yrs * 12)
	{
		period_wdl = enhanced_wdl;
		enh_inc_cumul_mths += 1;
	}

	if (!claim_stage && fund_val < SMALL_DOUBLE && pol_mth == 1)
	{
		claim_stage = true;
	}

	if (claim_stage)
	{
		period_wdl = gmwb_income_base * pipp / 12.;
	}

	double mort_rate_m, mort_rate_f;
	if (enhanced_income_ind_crbg == YES)
	{
		int confined_status_m	= enh_inc_confined_status_male_crbg(t);
		int confined_mth_m		= enh_inc_confined_mth_male_crbg(t) + i - t;
		int confined_yr_m		= int((i - confined_mth_m + 1) / 12.0 + 1);
		int confined_age_m		= issue_age_male_crbg + confined_yr_m - 1;
		mort_rate_m = dth_rate_confinement_calc_crbg(i, pol_yr, MALE, confined_status_m, confined_age_m, confined_mth_m);
		mort_rate_m = convert_decrem_rate_basis(mort_rate_m, EFFECTIVE_ANNUAL, -12);

		int confined_status_f	= enh_inc_confined_status_female_crbg(t);
		int confined_mth_f		= enh_inc_confined_mth_female_crbg(t) + i - t;
		int confined_yr_f		= int((i - confined_mth_f + 1) / 12.0 + 1);
		int confined_age_f		= issue_age_female_crbg + confined_yr_f - 1;
		mort_rate_f = dth_rate_confinement_calc_crbg(i, pol_yr, FEMALE, confined_status_f, confined_age_f, confined_mth_f);
		mort_rate_f = convert_decrem_rate_basis(mort_rate_f, EFFECTIVE_ANNUAL, -12);
	}
	else
	{
		mort_rate_m = dth_rate_mthly_male_crbg(i);
		mort_rate_f = dth_rate_mthly_female_crbg(i);
	}

	if (gender_cv == MALE)
	{
		cumm_surv = cumm_surv * (1 - mort_rate_m);
	}
	if (gender_cv == FEMALE)
	{
		cumm_surv = cumm_surv * (1 - mort_rate_f);
	}
	else if (gender_cv == JOINT)
	{
		joint_cumm_surv  *= (1 - mort_rate_m) * (1 - mort_rate_f);
		male_cumm_surv   *= (1 - mort_rate_m);
		female_cumm_surv *= (1 - mort_rate_f);
		last_surv_cumm_surv = male_cumm_surv + female_cumm_surv - joint_cumm_surv; 
		cumm_surv = (male_cumm_surv * policies_male_inf_crbg(t)
						+ female_cumm_surv * policies_female_inf_crbg(t)
						+ last_surv_cumm_surv * policies_joint_inf_crbg(t)) / policies_last_survivor_inf_crbg(t);
	}
	else
	{
		throw FatalError("Gender cannot be blended for GMWB run!");
	}

	//disc_rt = rates_ptr->get_int_rate(t, itm_disc_curve_crbg, GET_YIELD_RATE, 10, i - t, EFFECTIVE_ANNUAL, NO_SHIFT); //entire swap curve

	period_disc = pow(1 + disc_rt, 1./12.) - 1;
	
	disc_wdls += period_wdl * cumm_surv * pow(1.0 / (1.0 + period_disc), i - t);

	fund_val = max(fund_val - period_wdl, 0.0); 

	/*if(t==1)
	log_screen<<"curr_i= "<<i<<" claim_stage= "<<claim_stage	<<" fund_val= "<<fund_val
	<<" pol_mth= "<<pol_mth	<<" period_wdl= "<<period_wdl
	//<<" mort_rate_m= "<<mort_rate_m	<<" mort_rate_f= "<<mort_rate_f
	<<" cumm_surv= "<<cumm_surv	<<" disc_rt= "<<disc_rt
	<<" disc_wdls= "<<disc_wdls	<<MSG_USER;*/
}

return disc_wdls;

}

//@@ END

//@@ START - pv_gmwb_ben_itm_init_rate_crbg
// Pv Gmwb Benefit using initial swap rate                                                                                             
// Column:PV_GMWB_BEN_ITM_INIT_RATE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_pv_gmwb_ben_itm_init_rate_crbg(int t) {
//^^^



//^^^

#line 1 "pv_gmwb_ben_itm_init_rate_crbg.FIA_LIAB.for"
//20250507 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag || gmwb_inf_bef(t) < SMALL_DOUBLE)
	return NO_AVG;

StrEnum::EnumValue gender_cv = gender_mp;
if (gender_mp != gender_aft_inc && t + elapsed_mths > gmwb_exercise_yrs * 12 + 1)
{
	gender_cv = gender_aft_inc;
}

double fund_val	= fund_val_e_bef(t);
double gmwb_income_base = gmwb_inf_bef(t);
double mawp = pv_gmwb_mawp_crbg(t);
double pipp = pv_gmwb_pip_pct_crbg(t);
double period_wdl = gmwb_income_base * mawp / 12.;
double enhanced_wdl = period_wdl * enh_inc_mawp_mult;
double disc_wdls = period_wdl;

double cumm_surv = 1.0;
double joint_cumm_surv  = 1.0;	
double male_cumm_surv   = 1.0;
double female_cumm_surv = 1.0;
double last_surv_cumm_surv = 1.0;

double disc_rt, period_disc;

if (!valn_flag)
	disc_rt = rates_ptr->get_int_rate(-elapsed_mths, itm_disc_curve_crbg, GET_YIELD_RATE, 10., 0, EFFECTIVE_ANNUAL, NO_SHIFT); //TIME 0 swap rate
else
	disc_rt = rates_ptr->get_int_rate(-elapsed_mths, "Govt", GET_YIELD_RATE, 10., 0, EFFECTIVE_ANNUAL, NO_SHIFT); 

bool claim_stage = false;

int enh_inc_cumul_mths = 0;
if (xint(enh_inc_exercise_flag_crbg(t)) == 1)
{
	disc_wdls = enhanced_wdl;
	enh_inc_cumul_mths = max(0, enh_inc_exercise_cumul_yrs_crbg(t) - 1) * 12 + pol_mth(t);
}

int max_life = (term_to_omega_age * 12.0) - elapsed_mths;
for (int i = t + 1; i <= max_life; i = i + 1)
{
	int pol_yr = int((i + elapsed_mths - 1) / 12.0 + 1);
	int pol_mth = int(i + elapsed_mths - 1) % 12 + 1;

	if (xint(enh_inc_exercise_flag_crbg(t)) == 1 && enh_inc_cumul_mths <= enh_inc_max_cumul_yrs * 12)
	{
		period_wdl = enhanced_wdl;
		enh_inc_cumul_mths += 1;
	}

	if (!claim_stage && fund_val < SMALL_DOUBLE && pol_mth == 1)
	{
		claim_stage = true;
	}

	if (claim_stage)
	{
		period_wdl = gmwb_income_base * pipp / 12.;
	}

	double mort_rate_m, mort_rate_f;
	if (enhanced_income_ind_crbg == YES)
	{
		int confined_status_m	= enh_inc_confined_status_male_crbg(t);
		int confined_mth_m		= enh_inc_confined_mth_male_crbg(t) + i - t;
		int confined_yr_m		= int((i - confined_mth_m + 1) / 12.0 + 1);
		int confined_age_m		= issue_age_male_crbg + confined_yr_m - 1;
		mort_rate_m = dth_rate_confinement_calc_crbg(i, pol_yr, MALE, confined_status_m, confined_age_m, confined_mth_m);
		mort_rate_m = convert_decrem_rate_basis(mort_rate_m, EFFECTIVE_ANNUAL, -12);

		int confined_status_f	= enh_inc_confined_status_female_crbg(t);
		int confined_mth_f		= enh_inc_confined_mth_female_crbg(t) + i - t;
		int confined_yr_f		= int((i - confined_mth_f + 1) / 12.0 + 1);
		int confined_age_f		= issue_age_female_crbg + confined_yr_f - 1;
		mort_rate_f = dth_rate_confinement_calc_crbg(i, pol_yr, FEMALE, confined_status_f, confined_age_f, confined_mth_f);
		mort_rate_f = convert_decrem_rate_basis(mort_rate_f, EFFECTIVE_ANNUAL, -12);
	}
	else
	{
		mort_rate_m = dth_rate_mthly_male_crbg(i);
		mort_rate_f = dth_rate_mthly_female_crbg(i);
	}

	if (gender_cv == MALE)
	{
		cumm_surv = cumm_surv * (1 - mort_rate_m);
	}
	if (gender_cv == FEMALE)
	{
		cumm_surv = cumm_surv * (1 - mort_rate_f);
	}
	else //Joint life, last survivor. 
	{
		joint_cumm_surv  *= (1 - mort_rate_m) * (1 - mort_rate_f);
		male_cumm_surv   *= (1 - mort_rate_m);
		female_cumm_surv *= (1 - mort_rate_f);
		last_surv_cumm_surv = male_cumm_surv + female_cumm_surv - joint_cumm_surv; 
		cumm_surv = (male_cumm_surv * policies_male_inf_crbg(t)
						+ female_cumm_surv * policies_female_inf_crbg(t)
						+ last_surv_cumm_surv * policies_joint_inf_crbg(t)) / policies_last_survivor_inf_crbg(t);

	}

	//disc_rt = rates_ptr->get_int_rate(t, itm_disc_curve_crbg, GET_YIELD_RATE, 10, i - t, EFFECTIVE_ANNUAL, NO_SHIFT); //entire swap curve

	period_disc = pow(1 + disc_rt, 1./12.) - 1;
	
	disc_wdls += period_wdl * cumm_surv * pow(1.0 / (1.0 + period_disc), i - t);

	fund_val = max(fund_val - period_wdl, 0.0); 

	/*if(t==1)
	log_screen<<"ini_i= "<<i<<" claim_stage= "<<claim_stage	<<" fund_val= "<<fund_val
	<<" pol_mth= "<<pol_mth	<<" period_wdl= "<<period_wdl
	<<" mort_rate_m= "<<mort_rate_m	<<" mort_rate_f= "<<mort_rate_f
	<<" cumm_surv= "<<cumm_surv	<<" disc_rt= "<<disc_rt
	<<" disc_wdls= "<<disc_wdls	<<MSG_USER;*/
}

return disc_wdls;

}

//@@ END

//@@ START - pv_gmwb_benefit_itm
// PV of GMWB Benefit for ITM                                                                                             
// Column:PV_GMWB_BENEFIT_ITM
//========================================================
double FIA_LIAB_UDF::fia_liab_pv_gmwb_benefit_itm(int t) {
//^^^



//^^^

#line 1 "pv_gmwb_benefit_itm.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

double gmwb_max_wdl_amt_bef = 0.0;

if (t == commencement_period && elapsed_mths > 0)
	gmwb_max_wdl_amt_bef = init_gmwb_max_wdl_amt;
else
	gmwb_max_wdl_amt_bef = gmwb_max_wdl_amt(t); //This is before Decrements

double disc_rate = 0.0;

disc_rate = itm_period_disc_rate;

if (t == commencement_period)
	return pv_gmwb_benefit_itm_calc(t, pol_yr(t), pol_mth(t), 
									disc_rate, 
									gmwb_inf_bef(t), 
									gmwb_max_wdl_amt_bef, 
									0.0);

return pv_gmwb_benefit_itm_calc(t, pol_yr(t), pol_mth(t), 
								disc_rate, 
								gmwb_inf_bef(t), 
								gmwb_max_wdl_amt_bef, 
								pfwd_surr_cumul(t - 1));

}

//@@ END

//@@ START - pv_gmwb_mawp_crbg
// mawp for PV calc                                                                                             
// Column:PV_GMWB_MAWP_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_pv_gmwb_mawp_crbg(int t) {
//^^^



//^^^

#line 1 "pv_gmwb_mawp_crbg.FIA_LIAB.for"
//20250626 New column for CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

double mawp = 0.;

int gmwb_withdrl_yr = min(pol_yr(t), gmwb_exercise_yrs_crbg(t) + 1);	

if (mawp_lookup_type_crbg == WITHDRL_AGE)
{
	gmwb_withdrl_age = issue_age_col_crbg(t) + gmwb_withdrl_yr - 1;
	mawp = gmwb_max_annual_wdl_pct;
}

else if (mawp_lookup_type_crbg == ISSUE_AGE)
{
	gmwb_withdrl_age = issue_age_col_crbg(t);
	mawp = gmwb_max_annual_wdl_pct;

	gmwb_withdrl_yr_lookup = gmwb_withdrl_yr;
	mawp += gmwb_mawp_addn_crbg;

	//NY Reg47 logic
	int issue_age = issue_age_col_crbg(t);
	int withdrl_age = issue_age_col_crbg(t) + gmwb_withdrl_yr - 1;
	if (gmwb_reg47_crbg == YES && issue_age >= 55 && withdrl_age >= 65)
	{
		int age_diff_on_limit = min(issue_age - 55, withdrl_age - 65);
		int look_back_5yr_factor;

		if (age_diff_on_limit % 5 == 0 || age_diff_on_limit < 5)
			look_back_5yr_factor = ceil(age_diff_on_limit / 5.0) + 1;
		else
			look_back_5yr_factor = ceil(age_diff_on_limit / 5.0);

		int fisrt_lookup_age = withdrl_age - look_back_5yr_factor * 5; 
		for (int current_age = fisrt_lookup_age; current_age <= withdrl_age; current_age = current_age + 5)
		{
			int current_issue_age = current_age - gmwb_withdrl_yr + 1;		
			if (current_age < 65 || current_issue_age < 55)
			{
				gmwb_withdrl_age = current_issue_age;
				mawp = gmwb_max_annual_wdl_pct;

				gmwb_withdrl_yr_lookup = gmwb_withdrl_yr;
				mawp += gmwb_mawp_addn_crbg;
			}
			else
			{			
				gmwb_withdrl_age = current_age;
				double slope = gmwb_reg47_slope_crbg;	
				
				if (gmwb_withdrl_yr == 1)
					mawp = xround(ceil(xround((mawp * (1 + slope) * 2000), 5)) / 2000, 4); 
				else
					mawp = xround(ceil(xround((mawp * (1 + slope) * 10000), 5)) / 10000, 4);
			}
		} //End of the for loop
	}
}

//Intentionally not apply mawp multipler for confinement here.

return mawp;

}

//@@ END

//@@ START - pv_gmwb_pip_pct_crbg
// pip pct for PV calc                                                                                             
// Column:PV_GMWB_PIP_PCT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_pv_gmwb_pip_pct_crbg(int t) {
//^^^



//^^^

#line 1 "pv_gmwb_pip_pct_crbg.FIA_LIAB.for"
//20250626 New column for CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!gmwb_flag)
	return NO_AVG;

if (mawp_lookup_type_crbg == ISSUE_AGE)
{
	return pv_gmwb_mawp_crbg(t);
}

int gmwb_withdrl_yr = min(pol_yr(t), gmwb_exercise_yrs_crbg(t) + 1);

gmwb_withdrl_age = issue_age_col_crbg(t) + gmwb_withdrl_yr - 1;
double pipp = gmwb_pipp_crbg;

if (gmwb_pipp_stepup_ind_crbg(t) == 1)
{
	gmwb_withdrl_age = issue_age_col_crbg(t) + gmwb_withdrl_yr - 1;
	pipp = gmwb_pipp_stepup_crbg;
}

return pipp;

}

//@@ END

//@@ START - pv_sfc_ben_itm_crbg
// Pv Sfc Ben Itm Crbg                                                                                             
// Column:PV_SFC_BEN_ITM_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_pv_sfc_ben_itm_crbg(int t) {
//^^^



//^^^

#line 1 "pv_sfc_ben_itm_crbg.FIA_LIAB.for"
//20250715 Customized CRBG column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (eprs_sfc_defn == YES && pol_yr(t) <= surr_chg_period_crbg && !gmwb_flag
	&& sm_fia_account[index0_element]->crediting_dyn_lever == DYNAMIC_PART_EPRS)
{
	double cumm_surv = 1.0;
	double joint_cumm_surv  = 1.0;	
	double male_cumm_surv   = 1.0;
	double female_cumm_surv = 1.0;
	double last_surv_cumm_surv = 1.0;
	double asset_cumulative_growth = 1.0;

	// convert annual strategy fee to monthly
	double strategy_fee_rate = sm_fia_account[index0_element]->eprs_strat_fee_pct_crbg;
	strategy_fee_rate = 1 - pow(1 - strategy_fee_rate, 1./12.);

	// inner loop to calculate future mortality and growth rates
	for (int i = t + 1; i <= surr_chg_period_crbg * 12 - elapsed_mths; i++)		
	{
		double mort_rate_m = dth_rate_mthly_male_crbg(i);
		double mort_rate_f = dth_rate_mthly_female_crbg(i);
		double mort_rate_blended = dth_rate_mthly_blended_crbg(i);

		if (gender_mp == MALE)
		{
			cumm_surv = cumm_surv * (1 - mort_rate_m);
		}
		if (gender_mp == FEMALE)
		{
			cumm_surv = cumm_surv * (1 - mort_rate_f);
		}
		if (gender_mp == BLENDED)
		{
			cumm_surv = cumm_surv * (1 - mort_rate_blended);
		}
		else //Last survivor. 
		{
			joint_cumm_surv  *= (1 - mort_rate_m) * (1 - mort_rate_f);
			male_cumm_surv   *= (1 - mort_rate_m);
			female_cumm_surv *= (1 - mort_rate_f);
			last_surv_cumm_surv = male_cumm_surv + female_cumm_surv - joint_cumm_surv; 
			cumm_surv = (male_cumm_surv * policies_male_inf_crbg(t)
							+ female_cumm_surv * policies_female_inf_crbg(t)
							+ last_surv_cumm_surv * policies_joint_inf_crbg(t)) / policies_last_survivor_inf_crbg(t);
		}

		double one_yr_forward_rate;
		
		if (!valn_flag)
			one_yr_forward_rate = rates_ptr->calc_fwrd_rate_crbg(t, (i - t) / 12., 1., itm_disc_curve_crbg); //forward term is 1yr
		else
			one_yr_forward_rate = rates_ptr->calc_fwrd_rate_crbg(t, (i - t) / 12., 1., "Govt"); 

		one_yr_forward_rate = pow(1 + one_yr_forward_rate, 1./12.) - 1; //convert to monthly

		double asset_growth = 1 + one_yr_forward_rate - strategy_fee_rate;

		asset_cumulative_growth *= asset_growth;

	}

	// calculate future benefit
	double fund_val_future = fund_val_e_bef(t) * asset_cumulative_growth;					 

	double sfc_payout = max(0, eprs_sfc_ben_gross_crbg(t) - fund_val_future);

	sfc_payout *= cumm_surv;

	return sfc_payout;
}

return 0.;

}

//@@ END

//@@ START - rand_num_non_us_return_crbg
// Rand Num Non Us Return                                                                                             
// Column:RAND_NUM_NON_US_RETURN_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_rand_num_non_us_return_crbg(int t) {
//^^^



//^^^

#line 1 "rand_num_non_us_return_crbg.FIA_LIAB.for"
//20260303 New column with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (valn_flag)
{
	return uniform_rands_arr_crbg[4][t - 1];
}

return NO_AVG;

}

//@@ END

//@@ START - rbc
// RBC                                                                                             
// Column:RBC
//========================================================
double FIA_LIAB_UDF::fia_liab_rbc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(331,"rbc",t);
}



//^^^

#line 1 "rbc.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

double rbc_c1 = this->rbc_c1(t);
double rbc_c2 = this->rbc_c2(t);
double rbc_c3 = this->rbc_c3(t);
double rbc_c4 = this->rbc_c4(t);

return pow((rbc_c1 + rbc_c3) * (rbc_c1 + rbc_c3)
           + (rbc_c2 * rbc_c2), 0.5)
       + rbc_c4;

}

//@@ END

//@@ START - rbc_c1
// RBC C1                                                                                             
// Column:RBC_C1
//========================================================
double FIA_LIAB_UDF::fia_liab_rbc_c1(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(332,"rbc_c1",t);
}



//^^^

#line 1 "rbc_c1.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (t == start_period && valn_period != 0)
	return init_rbc_c1;

return (stat_res(t)
        - reins_stat_res(t))
        * rbc_c1_liab_only_stat_res_pct;

}

//@@ END

//@@ START - rbc_c2
// RBC C2                                                                                             
// Column:RBC_C2
//========================================================
double FIA_LIAB_UDF::fia_liab_rbc_c2(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(333,"rbc_c2",t);
}



//^^^

#line 1 "rbc_c2.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return rbc_c2_nar(t) * rbc_c2_mort_pct;

}

//@@ END

//@@ START - rbc_c2_nar
// RBC C2 Net Amount at Risk                                                                                             
// Column:RBC_C2_NAR
//========================================================
double FIA_LIAB_UDF::fia_liab_rbc_c2_nar(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(334,"rbc_c2_nar",t);
}



//^^^

#line 1 "rbc_c2_nar.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return max(dth_ben_inf(t)
		   - reins_dth_ben_inf(t)
		   - (stat_res(t)
		      - reins_stat_res(t)), 0.0);

}

//@@ END

//@@ START - rbc_c3
// RBC C3                                                                                             
// Column:RBC_C3
//========================================================
double FIA_LIAB_UDF::fia_liab_rbc_c3(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(335,"rbc_c3",t);
}



//^^^

#line 1 "rbc_c3.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == RESERVES)
	return rbc_c3_mp(t);

// force call for reporting
rbc_c3_unhedged(t);

return max(rbc_c3_stoch_amt(t) - stat_res_net(t), 0.0);

}

//@@ END

//@@ START - rbc_c3_base_ann_high_risk
// RBC C3 Base Annuity High Risk                                                                                             
// Column:RBC_C3_BASE_ANN_HIGH_RISK
//========================================================
double FIA_LIAB_UDF::fia_liab_rbc_c3_base_ann_high_risk(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(336,"rbc_c3_base_ann_high_risk",t);
}



//^^^

#line 1 "rbc_c3_base_ann_high_risk.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if ((pricing_flag || nb_flag) && t == start_period
 && valn_period == 0)
 return NO_AVG; 

//if (rbc_c3_ann_risk_defn == HIGH) Lookup by pol_yr is only possible for numbers
if (rbc_c3_ann_risk_defn == 3)
	return max(cash_val(t) - reins_cash_val(t),
			   stat_res_carvm_net(t));
                           
return 0.0;


}

//@@ END

//@@ START - rbc_c3_base_ann_low_risk
// RBC C3 Base Annuity Low Risk                                                                                             
// Column:RBC_C3_BASE_ANN_LOW_RISK
//========================================================
double FIA_LIAB_UDF::fia_liab_rbc_c3_base_ann_low_risk(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(337,"rbc_c3_base_ann_low_risk",t);
}



//^^^

#line 1 "rbc_c3_base_ann_low_risk.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if ((pricing_flag || nb_flag) && t == start_period
 && valn_period == 0)
 return NO_AVG; 

//if (rbc_c3_ann_risk_defn == LOW)Lookup by pol_yr is only possible for numbers
if (rbc_c3_ann_risk_defn == 1)
	return max(cash_val(t) - reins_cash_val(t),
			   stat_res_carvm_net(t));
                           
return 0.0;

}

//@@ END

//@@ START - rbc_c3_base_ann_medium_risk
// RBC C3 Base Annuity Medium Risk                                                                                             
// Column:RBC_C3_BASE_ANN_MEDIUM_RISK
//========================================================
double FIA_LIAB_UDF::fia_liab_rbc_c3_base_ann_medium_risk(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(338,"rbc_c3_base_ann_medium_risk",t);
}



//^^^

#line 1 "rbc_c3_base_ann_medium_risk.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if ((pricing_flag || nb_flag) && t == start_period
 && valn_period == 0)
 return NO_AVG; 

//if (rbc_c3_ann_risk_defn == MEDIUM)
if (rbc_c3_ann_risk_defn == 2)
	return max(cash_val(t) - reins_cash_val(t),
			   stat_res_carvm_net(t));

return 0.0;

}

//@@ END

//@@ START - rbc_c3_mp
// RBC C3 Policy Amount                                                                                             
// Column:RBC_C3_MP
//========================================================
double FIA_LIAB_UDF::fia_liab_rbc_c3_mp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(339,"rbc_c3_mp",t);
}



//^^^

#line 1 "rbc_c3_mp.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if ((pricing_flag || nb_flag) && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return rbc_c3_ann_low_risk_pct * rbc_c3_base_ann_low_risk(t)
       + rbc_c3_ann_medium_risk_pct * rbc_c3_base_ann_medium_risk(t)
       + rbc_c3_ann_high_risk_pct * rbc_c3_base_ann_high_risk(t);


}

//@@ END

//@@ START - rbc_c3_stoch_amt
// RBC C3 Stochastic Amount                                                                                             
// Column:RBC_C3_STOCH_AMT
//========================================================
double FIA_LIAB_UDF::fia_liab_rbc_c3_stoch_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(340,"rbc_c3_stoch_amt",t);
}



//^^^

#line 1 "rbc_c3_stoch_amt.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == RESERVES)
	return NO_AVG;

if (t == start_period && valn_period != 0)
	return init_rbc_c3_stoch_amt;

if (t == start_period && valn_period == 0
	|| (t == start_period + 1 && valn_period > 0)
	|| (pricing_flag && t == start_period + 1 && valn_period == 0))
	{
	if (sm_fia_ann_pba[0]->hedging_defn == UNHEDGED)
		return rbc_c3_stoch_amt_unhedged(t);

	StrEnum::EnumValue pba_calc_defn_stoch_amt = sm_fia_ann_pba[0]->res_cap_calc_defn;
	StrEnum::EnumValue pba_reins_defn_stoch_amt = sm_fia_ann_pba[0]->reins_defn;
	StrEnum::EnumValue pba_hedging_defn_stoch_amt = sm_fia_ann_pba[0]->hedging_defn;

	// Determine stochastic amount adjusted as unhedged stochastic amount
	// customize this code to change this treatment
	double stoch_amt_adjusted = 0.0;

	sm_fia_ann_pba[0]->pba_code = STOCH_CAP;
	sm_fia_ann_pba[0]->res_cap_calc_defn = CAPITAL;
	sm_fia_ann_pba[0]->reins_defn = NET;
	sm_fia_ann_pba[0]->hedging_defn = UNHEDGED;
	
	stoch_amt_adjusted = sm_fia_ann_pba[0]->stoch_amt(0);
	
	sm_fia_ann_pba[0]->rebaseModel(0);

	double stoch_amt_best_estimate = 0.0;

	// determine best estimate stochastic amount
	sm_fia_ann_pba[0]->pba_code = STOCH_CAP;
	sm_fia_ann_pba[0]->res_cap_calc_defn = CAPITAL;
	sm_fia_ann_pba[0]->reins_defn = NET;
	sm_fia_ann_pba[0]->hedging_defn = HEDGED;
	sm_fia_ann_pba[0]->hedging_cash_flow_defn = BEST_ESTIMATE;
	
	// if not hedged, use adjusted amount
	if (!sm_fia_ann_pba[0]->hedging_flag)
		stoch_amt_best_estimate = stoch_amt_adjusted;
	else
		{
		stoch_amt_best_estimate = sm_fia_ann_pba[0]->stoch_amt(0);
		
		sm_fia_ann_pba[0]->rebaseModel(0);
		}

	double stoch_amt 
	= stoch_amt_best_estimate
	  + sm_fia_ann_pba[0]->hedging_e_factor(t)
	    * max(0.0, stoch_amt_adjusted - stoch_amt_best_estimate);
	
	// restore pba definitions
	sm_fia_ann_pba[0]->res_cap_calc_defn = pba_calc_defn_stoch_amt;
	sm_fia_ann_pba[0]->reins_defn = pba_reins_defn_stoch_amt;
	sm_fia_ann_pba[0]->hedging_defn = pba_hedging_defn_stoch_amt;
		
	return stoch_amt
		   * pba_rollforward_factor(t);
	}

return rbc_c3_stoch_amt(t - 1) 
	   * pba_rollforward_factor(t);

}

//@@ END

//@@ START - rbc_c3_stoch_amt_unhedged
// RBC C3 Stochastic Amount Unhedged                                                                                             
// Column:RBC_C3_STOCH_AMT_UNHEDGED
//========================================================
double FIA_LIAB_UDF::fia_liab_rbc_c3_stoch_amt_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(341,"rbc_c3_stoch_amt_unhedged",t);
}



//^^^

#line 1 "rbc_c3_stoch_amt_unhedged.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE 
    || sm_fia_ann_pba[0]->res_cap_calc_defn == RESERVES)
	return NO_AVG;

if (t == start_period && valn_period != 0)
	return init_rbc_c3_stoch_amt_unhedged;

if (t == start_period && valn_period == 0
	|| (t == start_period + 1 && valn_period > 0)
	|| (pricing_flag && t == start_period + 1 && valn_period == 0))
	{
	StrEnum::EnumValue pba_calc_defn_stoch_amt = sm_fia_ann_pba[0]->res_cap_calc_defn;
	StrEnum::EnumValue pba_reins_defn_stoch_amt = sm_fia_ann_pba[0]->reins_defn;
	StrEnum::EnumValue pba_hedging_defn_stoch_amt = sm_fia_ann_pba[0]->hedging_defn;

	sm_fia_ann_pba[0]->pba_code = STOCH_CAP;
	sm_fia_ann_pba[0]->res_cap_calc_defn = CAPITAL;
	sm_fia_ann_pba[0]->reins_defn = NET;
	sm_fia_ann_pba[0]->hedging_defn = UNHEDGED;
	
	double stoch_amt = sm_fia_ann_pba[0]->stoch_amt(0);
	
	sm_fia_ann_pba[0]->rebaseModel(0);
	
	// restore pba definitions
	sm_fia_ann_pba[0]->res_cap_calc_defn = pba_calc_defn_stoch_amt;
	sm_fia_ann_pba[0]->reins_defn = pba_reins_defn_stoch_amt;
	sm_fia_ann_pba[0]->hedging_defn = pba_hedging_defn_stoch_amt;

	return stoch_amt
		   * pba_rollforward_factor(t);
	}

return rbc_c3_stoch_amt_unhedged(t - 1)
	   * pba_rollforward_factor(t);

}

//@@ END

//@@ START - rbc_c3_unhedged
// RBC C3 Unhedged                                                                                             
// Column:RBC_C3_UNHEDGED
//========================================================
double FIA_LIAB_UDF::fia_liab_rbc_c3_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(342,"rbc_c3_unhedged",t);
}



//^^^

#line 1 "rbc_c3_unhedged.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
    || sm_fia_ann_pba[0]->res_cap_calc_defn == RESERVES)
	return rbc_c3_mp(t);

return max(rbc_c3_stoch_amt_unhedged(t) - stat_res_net_unhedged(t), 0.0);

}

//@@ END

//@@ START - rbc_c4
// RBC C4                                                                                             
// Column:RBC_C4
//========================================================
double FIA_LIAB_UDF::fia_liab_rbc_c4(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(343,"rbc_c4",t);
}



//^^^

#line 1 "rbc_c4.FIA_LIAB.for"
if (t < start_period || t > maturity_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if ((pricing_flag || nb_flag) && t == start_period
	&& valn_period == 0)
	return NO_AVG;	
	
double prem_per_pol = single_prem / init_policies;

if (t + elapsed_mths <= 12) 
    return rbc_c4_prem_pct * prem_per_pol * policies_inf(t);

return 0.0;

}

//@@ END

//@@ START - reins_ann_benefits_eom
// Reinsurance Annuity Benefits EOM                                                                                             
// Column:REINS_ANN_BENEFITS_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_ann_benefits_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(344,"reins_ann_benefits_eom",t);
}



//^^^

#line 1 "reins_ann_benefits_eom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

return max(fund_val_e_bef(t), contract_val_bef(t))
       * (1.0 - dth_claim_rate_mthly(t))
       * annuitzn_rate_mthly(t)
	   * reins_pct
	   + reins_ann_claims_gmwb(t);

}

//@@ END

//@@ START - reins_ann_claims_gmwb
// Reinsurance Annuity Claims - GMWB                                                                                             
// Column:REINS_ANN_CLAIMS_GMWB
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_ann_claims_gmwb(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(345,"reins_ann_claims_gmwb",t);
}



//^^^

#line 1 "reins_ann_claims_gmwb.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (reins_coverage_defn == BASE_ONLY)
	return NO_AVG;

return ann_claims_gmwb(t) * reins_pct;

}

//@@ END

//@@ START - reins_cash_flow_bom
// Reinsurance Cash Flow Beginning of Month                                                                                             
// Column:REINS_CASH_FLOW_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_cash_flow_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(346,"reins_cash_flow_bom",t);
}



//^^^

#line 1 "reins_cash_flow_bom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

return reins_prem(t)
	   - reins_prem_tax(t)
       - reins_comm_reimb_bom(t)
       - reins_exp_reimb_bom(t);

}

//@@ END

//@@ START - reins_cash_flow_eom
// Reinsurance Cash Flow End of Month                                                                                             
// Column:REINS_CASH_FLOW_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_cash_flow_eom(int t) {
//^^^



//^^^

#line 1 "reins_cash_flow_eom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

return - reins_dth_benefits(t)
	   - reins_ann_benefits_eom(t)
	   - reins_maturity_benefits(t)
	   - reins_surr_benefits(t)
	   - reins_withdrl_benefits(t)
	   - reins_comm_reimb_eom(t)
	   + reins_comm_chargeback_reimb(t)
	   + reins_exp(t)
	   - reins_exp_reimb_eom(t);

}

//@@ END

//@@ START - reins_cash_flow_int
// Reinsurance Cash Flow Interest                                                                                             
// Column:REINS_CASH_FLOW_INT
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_cash_flow_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(348,"reins_cash_flow_int",t);
}



//^^^

#line 1 "reins_cash_flow_int.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

double cash_flow_rate_mthly = 0.0;

if (alm_flag)
	cash_flow_rate_mthly
	= seg_element->cash_flow_rate_mthly(t);
else
	cash_flow_rate_mthly
	= pow(1.0 + asset_yld_inv(t), 1.0 / 12.0) - 1.0;	

return reins_cash_flow_bom(t)
	   * cash_flow_rate_mthly;

}

//@@ END

//@@ START - reins_cash_val
// Reinsurance Cash Value                                                                                             
// Column:REINS_CASH_VAL
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_cash_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(349,"reins_cash_val",t);
}



//^^^

#line 1 "reins_cash_val.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (pricing_flag && t == commencement_period
	&& valn_period == 0)
	return NO_AVG;	

return cash_val(t) * reins_pct;

}

//@@ END

//@@ START - reins_comm_chargeback_reimb
// Reinsurance Commission Chargeback Reimbursed                                                                                             
// Column:REINS_COMM_CHARGEBACK_REIMB
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_comm_chargeback_reimb(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(350,"reins_comm_chargeback_reimb",t);
}



//^^^

#line 1 "reins_comm_chargeback_reimb.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (reins_coverage_defn == RIDER_ONLY)
	return NO_AVG;

return comm_chargeback(t) * reins_pct;

}

//@@ END

//@@ START - reins_comm_reimb
// Reinsurance Commission Reimbursed                                                                                             
// Column:REINS_COMM_REIMB
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_comm_reimb(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(351,"reins_comm_reimb",t);
}



//^^^

#line 1 "reins_comm_reimb.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

return reins_comm_reimb_bom(t)
       + reins_comm_reimb_eom(t)
       - reins_comm_chargeback_reimb(t);

}

//@@ END

//@@ START - reins_comm_reimb_bom
// Reinsurance Commission Reimbursement Beginning of Month                                                                                             
// Column:REINS_COMM_REIMB_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_comm_reimb_bom(int t) {
//^^^



//^^^

#line 1 "reins_comm_reimb_bom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (reins_coverage_defn == RIDER_ONLY)
	return NO_AVG;

return comm_bom(t) * reins_pct;

}

//@@ END

//@@ START - reins_comm_reimb_eom
// Reinsurance Commission Reimbursement End of Month                                                                                             
// Column:REINS_COMM_REIMB_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_comm_reimb_eom(int t) {
//^^^



//^^^

#line 1 "reins_comm_reimb_eom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (reins_coverage_defn == RIDER_ONLY)
	return NO_AVG;

return comm_eom(t) * reins_pct;

}

//@@ END

//@@ START - reins_dth_ben_inf
// Reinsurance Death Benefit In Force                                                                                             
// Column:REINS_DTH_BEN_INF
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_dth_ben_inf(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(354,"reins_dth_ben_inf",t);
}



//^^^

#line 1 "reins_dth_ben_inf.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

return dth_ben_inf(t) * reins_pct;

}

//@@ END

//@@ START - reins_dth_benefits
// Reinsurance Death Benefits                                                                                             
// Column:REINS_DTH_BENEFITS
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_dth_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(355,"reins_dth_benefits",t);
}



//^^^

#line 1 "reins_dth_benefits.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag || reins_coverage_defn == RIDER_ONLY)
	return NO_AVG;

return fund_released_dth(t) * reins_pct;

}

//@@ END

//@@ START - reins_exp
// Reinsurance Administration Expense                                                                                             
// Column:REINS_EXP
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_exp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(356,"reins_exp",t);
}



//^^^

#line 1 "reins_exp.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

return reins_exp_per_pol / 12.0
	   * policies_b(t)
	   * infl_cumul(t)
	   * exp_adj_mult;

}

//@@ END

//@@ START - reins_exp_reimb
// Reinsurance Expense Reimbursed                                                                                             
// Column:REINS_EXP_REIMB
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_exp_reimb(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(357,"reins_exp_reimb",t);
}



//^^^

#line 1 "reins_exp_reimb.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (reins_coverage_defn == RIDER_ONLY)
	return NO_AVG;

return reins_exp_reimb_bom(t)
       + reins_exp_reimb_eom(t);

}

//@@ END

//@@ START - reins_exp_reimb_bom
// Reinsurance Expense Reimbursed Beginning of Month                                                                                             
// Column:REINS_EXP_REIMB_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_exp_reimb_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(358,"reins_exp_reimb_bom",t);
}



//^^^

#line 1 "reins_exp_reimb_bom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (reins_coverage_defn == RIDER_ONLY)
	return NO_AVG;

return maint_exp_bom(t)
       * reins_pct;

}

//@@ END

//@@ START - reins_exp_reimb_eom
// Reinsurance Expense Reimbursed End of Month                                                                                             
// Column:REINS_EXP_REIMB_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_exp_reimb_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(359,"reins_exp_reimb_eom",t);
}



//^^^

#line 1 "reins_exp_reimb_eom.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (reins_coverage_defn == RIDER_ONLY)
	return NO_AVG;

return maint_exp_eom(t)
       * reins_pct;

}

//@@ END

//@@ START - reins_gaap_ben_res
// Reinsurance GAAP Benefit Reserve                                                                                             
// Column:REINS_GAAP_BEN_RES
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_ben_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(360,"reins_gaap_ben_res",t);
}



//^^^

#line 1 "reins_gaap_ben_res.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return sm_fia_sfas97rd[1]->fund_val(t);

}

//@@ END

//@@ START - reins_gaap_capzd_comm_bom
// Reinsurance GAAP Capitalized Commissions BOM                                                                                             
// Column:REINS_GAAP_CAPZD_COMM_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_capzd_comm_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(361,"reins_gaap_capzd_comm_bom",t);
}



//^^^

#line 1 "reins_gaap_capzd_comm_bom.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->capzd_comm_bom(t);

}

//@@ END

//@@ START - reins_gaap_capzd_comm_eom
// Reinsurance GAAP Capitalized Commissions EOM                                                                                             
// Column:REINS_GAAP_CAPZD_COMM_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_capzd_comm_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(362,"reins_gaap_capzd_comm_eom",t);
}



//^^^

#line 1 "reins_gaap_capzd_comm_eom.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->capzd_comm_eom(t);

}

//@@ END

//@@ START - reins_gaap_capzd_prem_bonus
// Reinsurance GAAP Capitalized Premium Bonus                                                                                             
// Column:REINS_GAAP_CAPZD_PREM_BONUS
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_capzd_prem_bonus(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(363,"reins_gaap_capzd_prem_bonus",t);
}



//^^^

#line 1 "reins_gaap_capzd_prem_bonus.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->capzd_prem_bonus(t);

}

//@@ END

//@@ START - reins_gaap_cash_flow_int
// Reinsurance GAAP Cash Flow Interest                                                                                             
// Column:REINS_GAAP_CASH_FLOW_INT
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_cash_flow_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(364,"reins_gaap_cash_flow_int",t);
}



//^^^

#line 1 "reins_gaap_cash_flow_int.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->cash_flow_int(t);

}

//@@ END

//@@ START - reins_gaap_chg_inc
// Reinsurance GAAP Charges Income                                                                                             
// Column:REINS_GAAP_CHG_INC
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_chg_inc(int t) {
//^^^



//^^^

#line 1 "reins_gaap_chg_inc.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->charges(t);

}

//@@ END

//@@ START - reins_gaap_comm_excess_bom
// Reinsurance GAAP Commissions Excess BOM                                                                                             
// Column:REINS_GAAP_COMM_EXCESS_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_comm_excess_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(366,"reins_gaap_comm_excess_bom",t);
}



//^^^

#line 1 "reins_gaap_comm_excess_bom.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->comm_excess_bom(t);

}

//@@ END

//@@ START - reins_gaap_comm_excess_eom
// Reinsurance GAAP Commissions Excess EOM                                                                                             
// Column:REINS_GAAP_COMM_EXCESS_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_comm_excess_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(367,"reins_gaap_comm_excess_eom",t);
}



//^^^

#line 1 "reins_gaap_comm_excess_eom.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->comm_excess_eom(t)
	   - sm_fia_sfas97rd[1]->comm_chargeback(t);

}

//@@ END

//@@ START - reins_gaap_comm_trail_bom
// Reinsurance GAAP Commissions Trail BOM                                                                                             
// Column:REINS_GAAP_COMM_TRAIL_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_comm_trail_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(368,"reins_gaap_comm_trail_bom",t);
}



//^^^

#line 1 "reins_gaap_comm_trail_bom.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->comm_trail_bom(t);

}

//@@ END

//@@ START - reins_gaap_comm_trail_eom
// Reinsurance GAAP Commissions Trail EOM                                                                                             
// Column:REINS_GAAP_COMM_TRAIL_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_comm_trail_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(369,"reins_gaap_comm_trail_eom",t);
}



//^^^

#line 1 "reins_gaap_comm_trail_eom.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->comm_trail_eom(t);

}

//@@ END

//@@ START - reins_gaap_cost
// Reinsurance GAAP Cost                                                                                             
// Column:REINS_GAAP_COST
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(370,"reins_gaap_cost",t);
}



//^^^

#line 1 "reins_gaap_cost.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

// force call actual gross profits
double agp = sm_fia_sfas97rd[1]->agp(t);

//force calls for reporting
reins_gaap_capzd_comm_bom(t);
reins_gaap_capzd_comm_eom(t);
reins_gaap_capzd_prem_bonus(t);
double inv_inc = sm_fia_sfas97rd[1]->inv_inc(t);

return reins_gaap_loads_deducted(t)
       + reins_gaap_chg_inc(t)
       + reins_gaap_surr_inc(t)
	   + reins_gaap_cash_flow_int(t)
	   + reins_gaap_inv_inc_res(t)
       - reins_gaap_recoveries(t)
       - reins_gaap_credited_int(t)
	   - reins_gaap_mrb_liab_incr(t)
	   - reins_gaap_sfas133_liab_incr(t)
       - reins_gaap_prem_bonus(t)
	   - reins_gaap_comm_trail_bom(t)
	   - reins_gaap_comm_trail_eom(t)
	   - reins_gaap_comm_excess_bom(t)
	   - reins_gaap_comm_excess_eom(t)
       - reins_gaap_maint_exp_bom(t)
       - reins_gaap_maint_exp_eom(t) 
       - reins_gaap_prem_tax(t)
       + reins_gaap_dac_incr(t);

}

//@@ END

//@@ START - reins_gaap_credited_int
// Reinsurance GAAP Credited Interest                                                                                             
// Column:REINS_GAAP_CREDITED_INT
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_credited_int(int t) {
//^^^



//^^^

#line 1 "reins_gaap_credited_int.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->credited_int(t);

}

//@@ END

//@@ START - reins_gaap_dac
// Reinsurance GAAP DAC                                                                                             
// Column:REINS_GAAP_DAC
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_dac(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(372,"reins_gaap_dac",t);
}



//^^^

#line 1 "reins_gaap_dac.FIA_LIAB.for"
if (t < start_period || t > maturity_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return sm_fia_sfas97rd[1]->dac_acq_exp(t)
       + sm_fia_sfas97rd[1]->dac_comm(t)
       + sm_fia_sfas97rd[1]->dac_prem_bonus(t);

}

//@@ END

//@@ START - reins_gaap_dac_incr
// Reinsurance GAAP DAC Increase                                                                                             
// Column:REINS_GAAP_DAC_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_dac_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(373,"reins_gaap_dac_incr",t);
}



//^^^

#line 1 "reins_gaap_dac_incr.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->dac_incr(t);

}

//@@ END

//@@ START - reins_gaap_inv_inc_res
// Reinsurance GAAP Investment Income on Reserves                                                                                             
// Column:REINS_GAAP_INV_INC_RES
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_inv_inc_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(374,"reins_gaap_inv_inc_res",t);
}



//^^^

#line 1 "reins_gaap_inv_inc_res.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return reins_gaap_liab_net(t - 1)
       * (pow((1.0 + asset_yld(t)), (1.0 / 12.0)) - 1.0);

}

//@@ END

//@@ START - reins_gaap_liab_net
// Reinsurance GAAP Recoverables Net of DAC                                                                                             
// Column:REINS_GAAP_LIAB_NET
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_liab_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(375,"reins_gaap_liab_net",t);
}



//^^^

#line 1 "reins_gaap_liab_net.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	
	
return reins_gaap_ben_res(t)
	   + reins_gaap_mrb_liab(t)
       + reins_gaap_sfas133_liab(t)
       - reins_gaap_dac(t);

}

//@@ END

//@@ START - reins_gaap_loads_deducted
// Reinsurance GAAP Loads Deducted                                                                                             
// Column:REINS_GAAP_LOADS_DEDUCTED
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_loads_deducted(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(376,"reins_gaap_loads_deducted",t);
}



//^^^

#line 1 "reins_gaap_loads_deducted.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->loads(t);

}

//@@ END

//@@ START - reins_gaap_maint_exp_bom
// Reinsurance GAAP Maintenance Expenses BOM                                                                                             
// Column:REINS_GAAP_MAINT_EXP_BOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_maint_exp_bom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(377,"reins_gaap_maint_exp_bom",t);
}



//^^^

#line 1 "reins_gaap_maint_exp_bom.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->maint_exp_bom(t);

}

//@@ END

//@@ START - reins_gaap_maint_exp_eom
// Reinsurance GAAP Maintenance Expenses EOM                                                                                             
// Column:REINS_GAAP_MAINT_EXP_EOM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_maint_exp_eom(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(378,"reins_gaap_maint_exp_eom",t);
}



//^^^

#line 1 "reins_gaap_maint_exp_eom.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->maint_exp_eom(t);

}

//@@ END

//@@ START - reins_gaap_mrb_liab
// Reinsurance GAAP Market Risk Benefits Liability                                                                                             
// Column:REINS_GAAP_MRB_LIAB
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_mrb_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(379,"reins_gaap_mrb_liab",t);
}



//^^^

#line 1 "reins_gaap_mrb_liab.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	
	
return sm_fia_sfas97rd[1]->mrb_liab(t);

}

//@@ END

//@@ START - reins_gaap_mrb_liab_incr
// Reinsurance GAAP Market Risk Benefits Liability Increase                                                                                             
// Column:REINS_GAAP_MRB_LIAB_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_mrb_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(380,"reins_gaap_mrb_liab_incr",t);
}



//^^^

#line 1 "reins_gaap_mrb_liab_incr.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->mrb_liab_incr(t);

}

//@@ END

//@@ START - reins_gaap_prem_bonus
// Reinsurance GAAP Premium Bonus                                                                                             
// Column:REINS_GAAP_PREM_BONUS
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_prem_bonus(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(381,"reins_gaap_prem_bonus",t);
}



//^^^

#line 1 "reins_gaap_prem_bonus.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->prem_bonus(t);

}

//@@ END

//@@ START - reins_gaap_prem_tax
// Reinsurance GAAP Premium Taxes                                                                                             
// Column:REINS_GAAP_PREM_TAX
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(382,"reins_gaap_prem_tax",t);
}



//^^^

#line 1 "reins_gaap_prem_tax.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->prem_tax(t);

}

//@@ END

//@@ START - reins_gaap_recoveries
// Reinsurance GAAP Recoveries                                                                                             
// Column:REINS_GAAP_RECOVERIES
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_recoveries(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(383,"reins_gaap_recoveries",t);
}



//^^^

#line 1 "reins_gaap_recoveries.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->dth_claim_cost(t);

}

//@@ END

//@@ START - reins_gaap_sfas133_liab
// Reinsurance GAAP SFAS133 Liability                                                                                             
// Column:REINS_GAAP_SFAS133_LIAB
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_sfas133_liab(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(384,"reins_gaap_sfas133_liab",t);
}



//^^^

#line 1 "reins_gaap_sfas133_liab.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	
	

return sm_fia_sfas97rd[1]->sfas133_liab(t);

}

//@@ END

//@@ START - reins_gaap_sfas133_liab_incr
// Reinsurance GAAP SFAS 133 Liability Increase                                                                                             
// Column:REINS_GAAP_SFAS133_LIAB_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_sfas133_liab_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(385,"reins_gaap_sfas133_liab_incr",t);
}



//^^^

#line 1 "reins_gaap_sfas133_liab_incr.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->sfas133_liab_incr(t);

}

//@@ END

//@@ START - reins_gaap_surr_inc
// Reinsurance GAAP Surrender Income                                                                                             
// Column:REINS_GAAP_SURR_INC
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_gaap_surr_inc(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(386,"reins_gaap_surr_inc",t);
}



//^^^

#line 1 "reins_gaap_surr_inc.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!gaap_flag || !reins_flag)
	return NO_AVG;

return sm_fia_sfas97rd[1]->egp_gain_surr(t);

}

//@@ END

//@@ START - reins_inv_inc_res
// Reinsurance Investment Income Reserve                                                                                             
// Column:REINS_INV_INC_RES
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_inv_inc_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(387,"reins_inv_inc_res",t);
}



//^^^

#line 1 "reins_inv_inc_res.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

return reins_stat_res(t - 1)
       * (pow((1.0 + asset_yld_inv(t)), (1.0 / 12.0)) - 1.0);

}

//@@ END

//@@ START - reins_maturity_benefits
// Reinsurance Maturity Benefits                                                                                             
// Column:REINS_MATURITY_BENEFITS
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_maturity_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(388,"reins_maturity_benefits",t);
}



//^^^

#line 1 "reins_maturity_benefits.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
if (!reins_flag || reins_coverage_defn == RIDER_ONLY)
	return NO_AVG;
	
return maturity_benefits(t) * reins_pct;

}

//@@ END

//@@ START - reins_prem
// Reinsurance Premium                                                                                             
// Column:REINS_PREM
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(389,"reins_prem",t);
}



//^^^

#line 1 "reins_prem.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

return reins_prem_base(t)
	   + reins_prem_gmwb(t);

}

//@@ END

//@@ START - reins_prem_base
// Reinsurance Premium - Base                                                                                             
// Column:REINS_PREM_BASE
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_prem_base(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(390,"reins_prem_base",t);
}



//^^^

#line 1 "reins_prem_base.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (reins_coverage_defn == RIDER_ONLY)
	return NO_AVG;

return prem_paid(t) * reins_pct;

}

//@@ END

//@@ START - reins_prem_gmwb
// Reinsurance Premium - GMWB                                                                                             
// Column:REINS_PREM_GMWB
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_prem_gmwb(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(391,"reins_prem_gmwb",t);
}



//^^^

#line 1 "reins_prem_gmwb.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (reins_coverage_defn == BASE_ONLY)
	return NO_AVG;

if (!gmwb_flag
	|| t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (fund_val_b_bef(t) < model_point_amount_threshold)
	return 0.0;

double chg_base_mult = 0.0;

if (gmwb_chg_base == FUND_VALUE)
	chg_base_mult = 1.0;

else if (gmwb_chg_base == GMWB_BASE)
	chg_base_mult 
	= gmwb_inf_bef(t) / fund_val_b_bef(t);

else //"MAX"
	chg_base_mult = max(1.0, gmwb_inf_bef(t) / fund_val_b_bef(t));

return min(fund_val_b_bef(t), 
           (reins_gmwb_chg / 12.0) 
           * (fund_val_b_bef(t) - admin_fee(t)) 
       	* chg_base_mult)
       * reins_pct;

}

//@@ END

//@@ START - reins_prem_tax
// Reinsurance Premium Tax                                                                                             
// Column:REINS_PREM_TAX
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_prem_tax(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(392,"reins_prem_tax",t);
}



//^^^

#line 1 "reins_prem_tax.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (reins_coverage_defn == RIDER_ONLY)
	return NO_AVG;

return prem_tax(t) * reins_pct;

}

//@@ END

//@@ START - reins_stat_cost
// Reinsurance Statutory Cost                                                                                             
// Column:REINS_STAT_COST
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_stat_cost(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(393,"reins_stat_cost",t);
}



//^^^

#line 1 "reins_stat_cost.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
if (!reins_flag)
	return NO_AVG;
	
return reins_prem(t)
       + reins_cash_flow_int(t)
       + reins_inv_inc_res(t)
       - reins_dth_benefits(t)
	   - reins_ann_benefits_eom(t)
	   - reins_maturity_benefits(t)
	   - reins_surr_benefits(t)
	   - reins_withdrl_benefits(t)
       - reins_comm_reimb(t)
       - reins_exp_reimb(t)
       + reins_exp(t)
	   - reins_prem_tax(t)
       - reins_stat_res_incr(t);

}

//@@ END

//@@ START - reins_stat_res
// Reinsurance Statutory Reserve                                                                                             
// Column:REINS_STAT_RES
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_stat_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(394,"reins_stat_res",t);
}



//^^^

#line 1 "reins_stat_res.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

// force call for reporting
reins_stat_res_mp(t);
reins_stat_res_unhedged(t);

return stat_res(t) - stat_res_net(t);

}

//@@ END

//@@ START - reins_stat_res_incr
// Reinsurance Statutory Reserve Increase                                                                                             
// Column:REINS_STAT_RES_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_stat_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(395,"reins_stat_res_incr",t);
}



//^^^

#line 1 "reins_stat_res_incr.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
if (!reins_flag)
	return NO_AVG;
	
return reins_stat_res(t)
	   - reins_stat_res(t - 1);

}

//@@ END

//@@ START - reins_stat_res_mp
// Reinsurance Statutory Policy Reserve                                                                                             
// Column:REINS_STAT_RES_MP
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_stat_res_mp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(396,"reins_stat_res_mp",t);
}



//^^^

#line 1 "reins_stat_res_mp.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return stat_res_mp(t) - stat_res_net_mp(t);

}

//@@ END

//@@ START - reins_stat_res_npr
// Reinsurance Statutory Net Premium Reserve                                                                                             
// Column:REINS_STAT_RES_NPR
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_stat_res_npr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(397,"reins_stat_res_npr",t);
}



//^^^

#line 1 "reins_stat_res_npr.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return NO_AVG;

return stat_res_npr(t) - stat_res_net_npr(t);

}

//@@ END

//@@ START - reins_stat_res_unhedged
// Reinsurance Statutory Reserve Unhedged                                                                                             
// Column:REINS_STAT_RES_UNHEDGED
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_stat_res_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(398,"reins_stat_res_unhedged",t);
}



//^^^

#line 1 "reins_stat_res_unhedged.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

return stat_res_unhedged(t) - stat_res_net_unhedged(t);

}

//@@ END

//@@ START - reins_surr_benefits
// Reinsurance Surrender Benefits                                                                                             
// Column:REINS_SURR_BENEFITS
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_surr_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(399,"reins_surr_benefits",t);
}



//^^^

#line 1 "reins_surr_benefits.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag || reins_coverage_defn == RIDER_ONLY)
	return NO_AVG;

return surr_benefits(t) * reins_pct;

}

//@@ END

//@@ START - reins_tax_res
// Reinsurance Tax Reserve                                                                                             
// Column:REINS_TAX_RES
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_tax_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(400,"reins_tax_res",t);
}



//^^^

#line 1 "reins_tax_res.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return reins_tax_res_mp(t);

}

//@@ END

//@@ START - reins_tax_res_incr
// Reinsurance Tax Reserve Increase                                                                                             
// Column:REINS_TAX_RES_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_tax_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(401,"reins_tax_res_incr",t);
}



//^^^

#line 1 "reins_tax_res_incr.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

return reins_tax_res(t)
	   - reins_tax_res(t - 1);

}

//@@ END

//@@ START - reins_tax_res_mp
// Reinsurance Tax Policy Reserve                                                                                             
// Column:REINS_TAX_RES_MP
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_tax_res_mp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(402,"reins_tax_res_mp",t);
}



//^^^

#line 1 "reins_tax_res_mp.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag)
	return NO_AVG;

if (reins_coverage_defn == RIDER_ONLY)
	return NO_AVG;

if ((pricing_flag || nb_flag) && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (tax_res_defn == TAX_EQUALS_STAT)
	return reins_stat_res_mp(t);

double tax_res_net_mp = 0.0;

// Use statutory formula reserve for tax comparison
double stat_res_net_mp 
= max(cash_val(t) - reins_cash_val(t),
	  stat_res_carvm_net(t));

tax_res_net_mp
= min(max(cash_val(t) - reins_cash_val(t), 
          tax_res_carvm_net(t)),
      stat_res_net_mp);

return tax_res_mp(t) - tax_res_net_mp;

}

//@@ END

//@@ START - reins_withdrl_benefits
// Reinsurance Withdrawal Benefits                                                                                             
// Column:REINS_WITHDRL_BENEFITS
//========================================================
double FIA_LIAB_UDF::fia_liab_reins_withdrl_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(403,"reins_withdrl_benefits",t);
}



//^^^

#line 1 "reins_withdrl_benefits.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (!reins_flag || reins_coverage_defn == RIDER_ONLY)
	return NO_AVG;

return fund_released_withdrl(t) * reins_pct;

}

//@@ END

//@@ START - shock_lapse_phase_crbg
// Shock Lapse Phase Crbg                                                                                             
// Column:SHOCK_LAPSE_PHASE_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_shock_lapse_phase_crbg(int t) {
//^^^



//^^^

#line 1 "shock_lapse_phase_crbg.FIA_LIAB.for"
//20250502 New column with CRBG logic
if (t <start_period ||t > final_period)
	return NO_AVG;

if (pol_yr(t) < lapse_shock_year_crbg)
{
	return 0;// PRE_SHOCK;
}
else if (pol_yr(t) == lapse_shock_year_crbg)
{
	return 1;// SHOCK;
}
else
{
	return 2;// POST_SHOCK;
}

}

//@@ END

//@@ START - shock_lapse_yr_ind_crbg
// Shock Lapse Yr Ind Crbg                                                                                             
// Column:SHOCK_LAPSE_YR_IND_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_shock_lapse_yr_ind_crbg(int t) {
//^^^



//^^^

#line 1 "shock_lapse_yr_ind_crbg.FIA_LIAB.for"
//20251216 Customized new column
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (decrements_defn == NO)
	return NO_AVG;

if (pol_yr(t) == lapse_shock_year_crbg || (myga_renew_ind_crbg == YES && pol_yr(t) > myga_init_term_crbg && myga_term_mth_elapsed_eom_crbg(t) <= 12))
{
	return 1.;
}

return 0.;

}

//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double FIA_LIAB_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.FIA_LIAB.for"
#if 0 // START_HEADER
#define __FIA_LIAB_H_
#endif // END_HEADER

#if 0 // START_EXTERNS
extern sowmpoutput fia_state_of_world_mp_output;
sowfcols fia_state_of_world_financial_columns;
sowfinput fia_state_of_world_financial_input;
sowfoutput fia_state_of_world_financial_output;
sowfmap fia_state_of_world_financial_input_pos;
sowfmapiter fia_state_of_world_financial_input_pos_iter;

extern ofstream& StatAuditFile;
ofstream& StatAuditFile = * new ofstream;

extern ofstream& TaxAuditFile;
ofstream& TaxAuditFile = * new ofstream;
#endif // END_EXTERNS

#if 0 // START_CLASS
int has_fixed;
int has_index0;
int has_index1;
int has_index2;
int has_index3;
int has_index4;
int fixed_element;
int index0_element;		
int index1_element;
int index2_element;
int index3_element;
int index4_element;
// competitor rate map
map <xstring, double, less<xstring> > comp_rates_map;
// discount rate vector
vector<string> disc_rates;
vector<string> gaap_cohorts_sfas97rd;
SmartArray <double> init_tax_capzd_prem_amortzn_sched;
double init_tax_bk_prof_ytd;
double init_tax_tgt_cap_ytd;
double init_taxable_inc_bk_prof_ytd;
double init_taxable_inc_tgt_cap_ytd;
double init_taxable_inc_carryfwd_avail;
double init_rbc_c1;
double init_rbc_c3_stoch_amt;
double init_rbc_c3_stoch_amt_unhedged;
double init_stat_res_net_stoch_res;
double init_stat_res_net_stoch_res_unhedged;
double init_stat_res_stoch_res;
double init_stat_res_stoch_res_unhedged;
double init_bk_prof_bef_tax_qtd;
double init_bk_prof_bef_tax_ytd;
double init_bk_prof_aft_tax_qtd;
double init_bk_prof_aft_tax_ytd;
double init_bk_prof_aft_tax_irr;
double init_distrib_earnings_irr;
double init_earnings_accum;
double init_tax_earnings_accum_ytd;
double init_taxable_inc_earnings_accum_ytd;
double init_undistrib_earnings;
double init_gaap_inc_bef_tax_qtd;
double init_gaap_inc_bef_tax_ytd;
double init_gaap_inc_aft_tax_qtd;
double init_gaap_inc_aft_tax_ytd;
double init_gaap_req_cap;
int carvm_annuitzn_tests_number;
int gmwb_exercise_point;
int gmwb_exercise_point_test_cnt;
vector<string> gmwb_exercise_points_input;
xstring stat_audit_detail_rpt_id;
xstring tax_audit_detail_rpt_id;

vector< vector <double>> uniform_rands_arr_crbg;

SEG_COMP *seg_element;
#if defined(__AA_COMP_COMP_H_)
RATES_ECONOMY /*modelobject_name: RATES*/ *rates_ptr;
#else
RATES_ECONOMY /*modelobject_name: FIA_RATES*/ *rates_ptr;
#endif

vector <string> carvm_stat_annuitzn_tests_input;
vector <string> carvm_tax_annuitzn_tests_input;

#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
has_fixed = 0;
has_index0 = 0;
has_index1 = 0;
has_index2 = 0;
has_index3 = 0;
has_index4 = 0;
fixed_element = -1;
index0_element = -1;		
index1_element = -1;
index2_element = -1;
index3_element = -1;
index4_element = -1;
init_tax_bk_prof_ytd = 0.0;
init_tax_tgt_cap_ytd = 0.0;
init_taxable_inc_bk_prof_ytd = 0.0;
init_taxable_inc_tgt_cap_ytd = 0.0;
init_taxable_inc_carryfwd_avail = 0.0;
init_rbc_c1 = 0.0;
init_rbc_c3_stoch_amt = 0.0;
init_rbc_c3_stoch_amt_unhedged = 0.0;
init_stat_res_net_stoch_res = 0.0;
init_stat_res_net_stoch_res_unhedged = 0.0;
init_stat_res_stoch_res = 0.0;
init_stat_res_stoch_res_unhedged = 0.0;
init_bk_prof_bef_tax_qtd = 0.0;
init_bk_prof_bef_tax_ytd = 0.0;
init_bk_prof_aft_tax_qtd = 0.0;
init_bk_prof_aft_tax_ytd = 0.0;
init_bk_prof_aft_tax_irr = 0.0;
init_distrib_earnings_irr = 0.0;
init_earnings_accum = 0.0;
init_tax_earnings_accum_ytd = 0.0;
init_taxable_inc_earnings_accum_ytd = 0.0;
init_undistrib_earnings = 0.0;
init_gaap_inc_bef_tax_qtd = 0.0;
init_gaap_inc_bef_tax_ytd = 0.0;
init_gaap_inc_aft_tax_qtd = 0.0;
init_gaap_inc_aft_tax_ytd = 0.0;
init_gaap_req_cap = 0.0;
carvm_annuitzn_tests_number = 0;
gmwb_exercise_point = 0;
gmwb_exercise_point_test_cnt = 0;
stat_audit_detail_rpt_id = "";
tax_audit_detail_rpt_id = "";
#endif // END_CONSTRUCTOR

#if 0 // START_TERMINATOR
fia_state_of_world_mp_output.close();
fia_state_of_world_financial_output.close(); 
#endif // END_TERMINATOR

gen2_declarations;

if (use_mp == NO)
	{
	throw NonFatalError("Model Point Use Definition is set to No for mp_id: " + xstring(mp_id));//Better to omit these MPs from the data file. NonFatal Errors are a drag on runtime
	}

if (isMainModel)
	{
	if (restore_variables_ind != 1)
		throw FatalError("The 'Assump Set Restore' property must be set equal to 'Yes' for FIA top model projections.");

	log_strm.setf(ios::fixed);
	log_strm.precision(12);

	log_screen.setf(ios::fixed);
	log_screen.precision(12);

	// Reinitialize string vectors for the case where restore_variables_ind == 1
	valn_periods.resize(0);
	gaap_cohorts_sfas97rd.resize(0);
	
	if (overall_num_of_proj_set_sub_loops > 0
		&& proj_set_sub_loop_num > 0)
		time_step_flag = true;
	
	// initialize global calculation flags
	if (target_column.find("valn_tgt") < string::npos)
		{
		valn_flag = true;
		last_proj_period = valn_yrs * 12;
		}
	else
		last_proj_period = projection_period_to;

	if (pricing_defn == YES)
		pricing_flag = true;

	if (tgt_cap_defn == YES)
		tgt_cap_flag = true;
	
	// Initializing GAAP flags
if (gaap_defn == YES
    || target_column.find("valn_tgt_gaap") < string::npos)
	{
	gaap_flag = true;

	if (gaap_cohorts_selected_sfas97rd != "NONE")
		split_string_usl(gaap_cohorts_selected_sfas97rd.c_str(), gaap_cohorts_sfas97rd, ",");

	if (target_column.find("valn_tgt_gaap_mrb") < string::npos)
		mrb_valn_flag = true;
	else if (target_column.find("valn_tgt_gaap_sfas97rd") < string::npos)
		sfas97rd_valn_flag = true;
	else if (target_column.find("valn_tgt_gaap_sop031") < string::npos)
		sop031_valn_flag = true;
	}

	if (sfas97rd_valn_flag && num_of_proj_task_loops > 1)
			throw FatalError("SFAS97RD valuations are a single iteration process. Please correct your projection properties.");

	stoch_flag = true;

	#if !defined(GEN2_ALM_RUN)
	rates_ptr = sm_fia_rates;
	#endif

	// Set valn_period and update last_proj_period
	if (time_step_flag)
		{
		// Create inner loop valuation periods vector
		split_string_usl(valn_periods_selected.c_str(), valn_periods, ",", "-");
		
		if (valn_periods.size() < overall_num_of_proj_set_sub_loops)
			throw FatalError("Inner loop valuation period must be defined for each projection set sub loop.");
		
		valn_period = atoi(xstring(valn_periods[proj_set_sub_loop_num - 1]));
	
		if (!valn_flag)
			{
			// Run 1 period to ensure proj date balance sheet is produced
			if (proj_set_sub_loop_num == valn_periods.size())
				last_proj_period = 1;
			else
				last_proj_period = atoi(xstring(valn_periods[proj_set_sub_loop_num])) - valn_period;

			// throw error message if 'Proj Period To' setting is not long enough
			if (projection_period_to < last_proj_period)
				{	
				xstring message = xstring("'Proj Period To' projection task property must be set to be greater than ")
				                  + xstring(" or equal to ") + xstring(last_proj_period) + xstring(". Please correct your data.");		

				throw FatalError(message);
				}
			}
		}
	
	xstring force_scalar_calc_date = proj_date_adj;
	
	has_fixed = 0;
	has_index0 = 0;
	has_index1 = 0;
	has_index2 = 0;
	has_index3 = 0;
	has_index4 = 0;
	fixed_element = -1;
	index0_element = -1;		
	index1_element = -1;
	index2_element = -1;
	index3_element = -1;
	index4_element = -1;
	
	// All pricing cells must be issued immediately after the initial projection date.
	if (pricing_flag)
		{
		// Always skip future issues
		if (elapsed_mths < 0)
			{			
			log_screen << "Warning: Issue date is after cell pricing projection date for FIA model point " 
			         << mp_id << ". Please check your data." << MSG_USER;

			throw NonFatalError("");//Error message above
			}

		else if (elapsed_mths > 0
				 && valn_period == 0)
			{			
			log_screen << "Warning: Issue date is before cell pricing projection date for FIA model point " 
				     << mp_id << ". Please check your data." << MSG_USER;

			throw NonFatalError("");//Error message above
			}
		}
		
	if (mp_id != "mp_time_step" && valn_flag && !pricing_flag && !mrb_valn_flag
		&& elapsed_mths <= 0)
		{			
		log_screen << "Warning: Issue date is after valuation projection date for FIA model point " 
		         << mp_id << ". Please check your data." << MSG_USER;
		
		throw NonFatalError("");//Error message above
		}

	// DAC tax temporary table
		int size = max(12, t_high);
	
	if (tax_capzd_prem_amortzn_sched.cols() <= 1
		&& tax_capzd_prem_amortzn_sched.rows() <= 1)
		{
		if ((size + proj_start_mth - 1) % 12 == 0)
			tax_capzd_prem_amortzn_sched.resize(size + 1,
				(size + proj_start_mth) / 12 + tax_capzd_prem_amortzn_yrs + 1);
		else 
			tax_capzd_prem_amortzn_sched.resize(size + 1,
				ceil(size / 12.0) + tax_capzd_prem_amortzn_yrs + 2);
		}	

	static bool first_time = true;
	if (first_time)
		{
		first_time = false;

		// Create the discount rates vector
		if (disc_rates_selected != "NONE")
			split_string_usl(disc_rates_selected.c_str(), disc_rates, ",");

		// Competitor rate map
		comp_rates_map.clear();
		}
	}

else //if (!isMainModel)
	{
	rates_ptr = rates;	

	if (nb_flag)
		{
		if (elapsed_mths - valn_period > 0) // In force at original proj date
			{
			log_screen << "Warning: Issue date is before new business projection date for FA model point " << mp_id 
				       << ". This model point will be ignored." << MSG_USER;

			throw NonFatalError("");
			}

		if (valn_flag // skip new issues when performing inner loop projection
			&& ((valn_period == 0 && elapsed_mths < 0)
				|| (valn_period > 0 && elapsed_mths <= 0)))
			{
			//throw NonFatalError("");
			return 1.0;
			}
		}	
	else if (valn_flag) // point in time valuation, or valuation in liability or alm projection
		{
		if (mp_id != "mp_time_step" && elapsed_mths <= 0)
			{
			log_screen << "Warning: Issue date is after valuation projection date for FIA model point " 
		         << mp_id << ". Please check your data." << MSG_USER;

			throw NonFatalError("");
			}
		}

	// Set t_low and t_high
	// If running in seriatim mode and independent model point 
	t_low = commencement_period;
	//t_high = maturity_period;

	}

if (stat_res_defn == CARVM)
	{
	// FULL PFWD element and NO PFWD element
	sm_carvm_stat.resize(2);
	}
	
	
if (tax_res_defn != TAX_EQUALS_STAT
	&& tax_res_defn != _2017_TAX_REFORM
	&& tax_res_defn == CARVM) 
	{
	// FULL PFWD element and NO PFWD element
	sm_carvm_tax.resize(2);		
	}
	

static int data_file_rec_num = -1;

if (isMainModel)
	data_file_rec_num = data_rec_num();

if (gaap_flag)
	{
	xstring cohort_id = "Unassigned";

	sm_fia_sfas97rd.resize(1);
	sm_fia_sfas97rd[0]->setGroup(mp_id + "|Gross");
	sm_fia_sfas97rd[0]->cohort_yr = issue_yr;
	sm_fia_sfas97rd[0]->rates_ptr = rates_ptr;

	// Assign GAAP cohort for pricing projections
	if (isMainModel)
		{
		bool cohort_assigned = false;
		for (int cohort = 0; cohort < gaap_cohorts_sfas97rd.size(); cohort++)
			{
			cohort_id = gaap_cohorts_sfas97rd[cohort];
			xstring mp_cohort_id = sfas97rd_cohort_id_gross;

			if (sm_fia_sfas97rd[0]->setup_cohorts(issue_yr, plan_code, mp_cohort_id, cohort_id))
				{									
				cohort_assigned = true;
				break;
				}
			}

		if (!cohort_assigned && mp_id != "mp_time_step")
			throw NonFatalError("Cannot assign cohort for GAAP cell pricing projection for FIA model point " + xstring(mp_id) + ". Please correct your data.");

		sfas97rd_cohort_id_gross = cohort_id;
		sm_fia_sfas97rd[0]->cohort_id = cohort_id;
		}

	sm_fia_mrb.resize(1);
	sm_fia_mrb[0]->setGroup(mp_id + "|Gross");

	if (reins_flag)
		{
		sm_fia_sfas97rd.resize(2); 
		sm_fia_sfas97rd[1]->setGroup(mp_id + "|Ceded");
		sm_fia_sfas97rd[1]->cohort_yr = issue_yr;
		sm_fia_sfas97rd[0]->rates_ptr = rates_ptr;

		if (isMainModel)
			{
			sfas97rd_cohort_id_ceded = cohort_id;
			sm_fia_sfas97rd[1]->cohort_id = cohort_id;
			}

		sm_fia_mrb.resize(2);
		sm_fia_mrb[0]->setGroup(mp_id + "|Gross");
		sm_fia_mrb[1]->setGroup(mp_id + "|Ceded");
		}
	
	for (int reins_el = 0; reins_el < sm_fia_mrb.size(); reins_el ++)
		sm_fia_mrb[reins_el]->rates_ptr = rates_ptr;

	}

if (sm_fia_ann_pba.size())
	sm_fia_ann_pba.resize(0);

// add PBA element
sm_fia_ann_pba.resize(1);

// set fia_ann_pba submodel rates and proj_date_adj
for (int i = 0; i < sm_fia_ann_pba.size(); i++)
	{
	sm_fia_ann_pba[i]->rates_ptr = rates_ptr;
	}

// Setup fia_accounts 
int count = 0;
bool resize_array = false;

if (isMainModel && (data_file_rec_num != data_rec_num())
	|| (is_first_proj_task_loop || num_of_proj_task_loops == 0)
	|| restore_variables_ind)
	{
	resize_array = true;

	// remove existing elements
	if (sm_fia_account.size())
		sm_fia_account.resize(0);
	}

// Add fia account elements
if (resize_array || restore_variables_ind)
	{
	if (init_fund_val_fixed > 0.0 
		 || (fund_val_rebal_defn == REBALANCE
		 	&& fund_val_rebal_prop_defn == SPECIFIED_ALLOCATION
		 	&& init_rebal_pct_fixed != 0))
		{
		count += 1;
		has_fixed = 1;
		fixed_element = count - 1;
		
		if (resize_array)
			sm_fia_account.resize(count);
		
		sm_fia_account[count - 1]->fund_id = "Fixed";
		}
	
	if (init_fund_val_index0 > 0.0
		 || (fund_val_rebal_defn == REBALANCE
		 	&& fund_val_rebal_prop_defn == SPECIFIED_ALLOCATION
		 	&& init_rebal_pct_index0 != 0))
		{
		count += 1;
		has_index0 = 1;
		index0_element = count - 1;
		
		if (resize_array)
			sm_fia_account.resize(count);
		
		sm_fia_account[count - 1]->fund_id = "Index0";
		}
		
	if (init_fund_val_index1 > 0.0 
		 || (fund_val_rebal_defn == REBALANCE
		 	&& fund_val_rebal_prop_defn == SPECIFIED_ALLOCATION
		 	&& init_rebal_pct_index1 != 0))
		{
		count += 1;
		has_index1 = 1;
		index1_element = count - 1;
	
		if (resize_array)
			sm_fia_account.resize(count);
		
		sm_fia_account[count - 1]->fund_id = "Index1";
		}	
	
	if (init_fund_val_index2 > 0.0 
   	  || (fund_val_rebal_defn == REBALANCE
   	  	&& fund_val_rebal_prop_defn == SPECIFIED_ALLOCATION
   	  	&& init_rebal_pct_index2 != 0))
		{
		count += 1;
		has_index2 = 1;
		index2_element = count - 1;
	
		if (resize_array)
			sm_fia_account.resize(count);

		sm_fia_account[count - 1]->fund_id = "Index2";
		}
			
	if (init_fund_val_index3 > 0.0 
		 || (fund_val_rebal_defn == REBALANCE
		 	&& fund_val_rebal_prop_defn == SPECIFIED_ALLOCATION
		 	&& init_rebal_pct_index3 != 0))
		{
		count += 1;
		has_index3 = 1;
		index3_element = count - 1;
	
		if (resize_array)
			sm_fia_account.resize(count);
		
		sm_fia_account[count - 1]->fund_id = "Index3";
		}
	
	if (init_fund_val_index4 > 0.0 
		 || (fund_val_rebal_defn == REBALANCE
		 	&& fund_val_rebal_prop_defn == SPECIFIED_ALLOCATION
		 	&& init_rebal_pct_index4 != 0))
		{
		count += 1;
		has_index4 = 1;
		index4_element = count - 1;
	
		if (resize_array)
			sm_fia_account.resize(count);

		sm_fia_account[count - 1]->fund_id = "Index4";
		}
	
	set_fia_account_vars();
	}

//20250505 CRBG RNG logic
if (valn_flag || (gmwb_ind && (gmwb_wdl_util_type_crbg == RANDOM_UTIL || enhanced_income_ind_crbg == YES)))
{
	uniform_rands_arr_crbg.clear();

	gen_uniform_rands_crbg(uniform_rands_arr_crbg);
}

issue_age_mp = issue_age_calc_crbg(gender_mp);	

return 1.0;

}

//@@ END

//@@ START - stat_res
// Statutory Reserve                                                                                             
// Column:STAT_RES
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(407,"stat_res",t);
}



//^^^

#line 1 "stat_res.FIA_LIAB.for"
if (t < commencement_period || t >= maturity_period)
     return NO_AVG;

// force call for reporting
double stat_res_unhedged = this->stat_res_unhedged(t);

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return stat_res_mp(t);

return max(stat_res_stoch_res(t), stat_res_npr(t));

}

//@@ END

//@@ START - stat_res_carvm
// Statutory CARVM Reserve                                                                                             
// Column:STAT_RES_CARVM
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_carvm(int t) {
//^^^



//^^^

#line 1 "stat_res_carvm.FIA_LIAB.for"
if (t < commencement_period || t > final_period)
     return NO_AVG;

if (pricing_flag && t == start_period
    && valn_period == 0)
    return NO_AVG;

if (stat_res_defn == PERCENT_FUND_VALUE)
	{
	if (stat_res_mva_defn == EXCLUDED)
		return max(fund_val_fixed(t), contract_val(t))  
				* stat_res_pct;

	return ((max(fund_val_fixed(t), contract_val(t)) - pfwd_entitlement_remaining_e(t))
		    * mva_ratio(t)
		    + pfwd_entitlement_remaining_e(t))
		   * stat_res_pct;
	}

if (stat_res_defn == PERCENT_CASH_VALUE)
	{
	if (stat_res_mva_defn == EXCLUDED)
		return cash_val_wo_mva(t) * stat_res_pct;

	return cash_val(t) * stat_res_pct;
	}

if (t == 0 && valn_period != 0)
	return init_stat_res_carvm;

if (t == 1)
	stat_res_carvm(t - 1); //force call for calculation order

// Determine if model point uses monthly sum cap crediting and use that in check for full CARVM calculation
// Will calculating CARVM monthly for monthly sum cap cases since index crediting is based on cumulative changes in the index
bool mthly_sum_cap_model_point = false;

for (int i = 0; i < sm_fia_account.size(); i++)
	{
	if (sm_fia_account[i]->crediting_rate_defn == MONTHLY_SUM_CAP)
		{
		mthly_sum_cap_model_point = true;
		break;
		}
	}

if ((t == 0 && valn_period == 0) || t + elapsed_mths == 1 || pol_mth(t) == 6 || pol_mth(t) == 12 || cal_mth(t) == 12
	|| mthly_sum_cap_model_point)  
	{

	if (t + elapsed_mths <= 0)
		return NO_AVG;

	double stat_res_carvm = 0.0;
	
	if (stat_carvm_calc_annuitzn_defn != NOT_APPLICABLE && carvm_stat_annuitzn_tests_input.size() == 0)
		{
		split_string_usl(carvm_stat_annuitzn_tests.c_str(), carvm_stat_annuitzn_tests_input, ",");
		carvm_stat_annuitzn_tests_cnt = carvm_stat_annuitzn_tests_input.size();
		}
    
	gmwb_exercise_point_test_cnt = 1;
	// If GMWB is already exercised, we only project CARVM with 1 exercise point equal to 0
	// Else run tests specified plus one test of no GMWB exercise
	if (gmwb_flag && pol_yr(t) <= gmwb_exercise_yrs_crbg(t))
		{
		gmwb_exercise_points_input.clear();
		gmwb_exercise_point_test_cnt = 1;

		//Pull in testing points for GWMB based off of Issue Date
		split_string_usl(carvm_stat_gmwb_exercise_points_issue.c_str(), gmwb_exercise_points_input, ",");
		gmwb_exercise_point_test_cnt = gmwb_exercise_points_input.size();	

		//*********************** Test Valuation Period Exercise Points from input variable carvm_gmwb_exercise_points_valn_prd ***********************
		//Pull in testing points for GWMB based off of Valuation Period 
		vector <string> gmwb_exercise_points_input_valn_prd;
		split_string_usl(carvm_stat_gmwb_exercise_points_valn_prd.c_str(), gmwb_exercise_points_input_valn_prd, ",");
		
		//Test Valuation Period exercise points to see if any overlap with Issue Date
		for (int i_valn_prd = 0; i_valn_prd < gmwb_exercise_points_input_valn_prd.size(); i_valn_prd++)
			{
			if (gmwb_exercise_points_input_valn_prd.size() == 1 && atoi(xstring(gmwb_exercise_points_input_valn_prd[0])) == 0)
				break;
	
			int testing_exercise_point_valn_period = atoi(xstring(gmwb_exercise_points_input_valn_prd[i_valn_prd])) + pol_yr(t) - 1;
			int testing_count = 0;

			for (int i_issue = 0; i_issue < gmwb_exercise_points_input.size(); i_issue++)
				{
				int testing_exercise_point_issue = atoi(xstring(gmwb_exercise_points_input[i_issue]));
				
				if (testing_exercise_point_valn_period == testing_exercise_point_issue)
					testing_count ++;
				}
			
			//Add new exercise point if testing point doesn't overlap	
			if (testing_count == 0)
				gmwb_exercise_points_input.insert(gmwb_exercise_points_input.end(), to_string(testing_exercise_point_valn_period));
			}

		//*********************** Test Attained Age Exercise Points from input variable carvm_gmwb_exercise_points_attained_age ***********************
		//Pull in testing points for GWMB based off of Attained Age 
		vector <string> gmwb_exercise_points_input_attained_age;
		split_string_usl(carvm_stat_gmwb_exercise_points_attained_age.c_str(), gmwb_exercise_points_input_attained_age, ",");

		//Test Attained Age exercise points to see if any overlap with Issue Date
		for (int i_attained_age = 0; i_attained_age < gmwb_exercise_points_input_attained_age.size(); i_attained_age++)
			{
			if (gmwb_exercise_points_input_attained_age.size() == 1 && atoi(xstring(gmwb_exercise_points_input_attained_age[0])) == 0)
				break;

			int testing_exercise_point_attained_age = atoi(xstring(gmwb_exercise_points_input_attained_age[i_attained_age])) - issue_age_mp - gmwb_req_yrs_wait;
			int testing_count = 0;

			if (testing_exercise_point_attained_age < 0)
				testing_exercise_point_attained_age = 0;
		
			for (int i_issue = 0; i_issue < gmwb_exercise_points_input.size(); i_issue++)
				{
				int testing_exercise_point_issue = atoi(xstring(gmwb_exercise_points_input[i_issue]));
				
				if (testing_exercise_point_attained_age == testing_exercise_point_issue)
					testing_count ++;
				}
			
			//Add new exercise point if testing point doesn't overlap	
			if (testing_count == 0)
				gmwb_exercise_points_input.insert(gmwb_exercise_points_input.end(), to_string(testing_exercise_point_attained_age));
			}
		
		//Sort the vector
		vector <int> gmwb_exercise_points_input_temp;
		for (int i_order = 0; i_order < gmwb_exercise_points_input.size(); i_order++)
			gmwb_exercise_points_input_temp.insert(gmwb_exercise_points_input_temp.end(), atoi(xstring(gmwb_exercise_points_input[i_order])));
		
		sort(gmwb_exercise_points_input_temp.begin(), gmwb_exercise_points_input_temp.end());
		gmwb_exercise_points_input.clear();

		for (int i_order = 0; i_order < gmwb_exercise_points_input_temp.size(); i_order++)
			gmwb_exercise_points_input.insert(gmwb_exercise_points_input.end(), to_string(gmwb_exercise_points_input_temp[i_order]));
		
		gmwb_exercise_point_test_cnt = gmwb_exercise_points_input.size() + 1;	
		}

	for (int i = 0; i < carvm_stat_annuitzn_tests_cnt; i++)
		{
		if (stat_carvm_calc_annuitzn_defn != NOT_APPLICABLE)
			carvm_annuitzn_tests_number = atoi(xstring(carvm_stat_annuitzn_tests_input[i]));

		for (int j = 0; j < gmwb_exercise_point_test_cnt; j++)
			{
			if (gmwb_flag && pol_yr(t) <= gmwb_exercise_yrs_crbg(t))
				{
				if (j < gmwb_exercise_point_test_cnt - 1)
					gmwb_exercise_point = atoi(xstring(gmwb_exercise_points_input[j]));
				else // Test with no exercise of GMWB
					gmwb_exercise_point = 9999; // No exercise of GMWB
				}
			else
				gmwb_exercise_point = 0;

			for (int k = 0; k < sm_carvm_stat.size() ; k++)
				{				
				sm_carvm_stat[k].resize(1); //recalc
				sm_carvm_stat[k][0]->res_period = t;
				sm_carvm_stat[k][0]->rates_ptr = rates_ptr;
				sm_carvm_stat[k][0]->set_hidden_variables();

				if (sm_carvm_stat[k][0]->res_integrated(0) > stat_res_carvm)
					stat_res_carvm = sm_carvm_stat[k][0]->res_integrated(0);
				
				sm_carvm_stat[k].resize(0);
				}	

			if (carvm_stat_detail_rpt_defn == YES)
				{
				write_reserves(t, "STAT", carvm_annuitzn_tests_number, gmwb_exercise_point);
				}
			}
		}
	
	return stat_res_carvm;
	}

if (fabs(fund_val_fixed(t - 1)) < model_point_amount_threshold)
	return 0.0;

return stat_res_carvm(t - 1)
	   * (fund_val_fixed(t) / fund_val_fixed(t - 1));

}

//@@ END

//@@ START - stat_res_carvm_net
// Statutory CARVM Reserve Net                                                                                             
// Column:STAT_RES_CARVM_NET
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_carvm_net(int t) {
//^^^



//^^^

#line 1 "stat_res_carvm_net.FIA_LIAB.for"
if (t < commencement_period || t > final_period)
     return NO_AVG;

if (!reins_flag)
	return stat_res_carvm(t);

return stat_res_carvm(t) * (1.0 - reins_pct);

}

//@@ END

//@@ START - stat_res_excess
// Statutory Reserve Excess                                                                                             
// Column:STAT_RES_EXCESS
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_excess(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(410,"stat_res_excess",t);
}



//^^^

#line 1 "stat_res_excess.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return NO_AVG;

if (!isMainModel)
	{
	if (fabs(seg_element->stat_res_npr(t)) > model_point_amount_threshold)
		return seg_element->stat_res_excess(t)
		       * stat_res_npr(t)
			   / seg_element->stat_res_npr(t);

	return 0.0;
	}

return max(0.0, stat_res(t) - stat_res_npr(t));

}

//@@ END

//@@ START - stat_res_excess_unhedged
// Statutory Reserve Excess Unhedged                                                                                             
// Column:STAT_RES_EXCESS_UNHEDGED
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_excess_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(411,"stat_res_excess_unhedged",t);
}



//^^^

#line 1 "stat_res_excess_unhedged.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return NO_AVG;

if (!isMainModel)
	{
	if (fabs(seg_element->stat_res_npr_unhedged(t)) > model_point_amount_threshold)
		return seg_element->stat_res_excess_unhedged(t)
		       * stat_res_npr_unhedged(t)
			   / seg_element->stat_res_npr_unhedged(t);

	return 0.0;
	}

return max(0.0, stat_res_unhedged(t) - stat_res_npr_unhedged(t));

}

//@@ END

//@@ START - stat_res_incr
// Statutory Reserve Increase                                                                                             
// Column:STAT_RES_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(412,"stat_res_incr",t);
}



//^^^

#line 1 "stat_res_incr.FIA_LIAB.for"
if (t <= 0)
	return NO_AVG;
	
return stat_res(t) - stat_res(t - 1);

}

//@@ END

//@@ START - stat_res_mp
// Statutory Policy Reserve                                                                                             
// Column:STAT_RES_MP
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_mp(int t) {
//^^^



//^^^

#line 1 "stat_res_mp.FIA_LIAB.for"
if (t < commencement_period || t >= maturity_period)
     return NO_AVG;

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return max(cash_val(t), stat_res_carvm(t));

return stat_res_npr(t) + stat_res_excess(t);

}

//@@ END

//@@ START - stat_res_mp_unhedged
// Statutory Policy Reserve Unhedged                                                                                             
// Column:STAT_RES_MP_UNHEDGED
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_mp_unhedged(int t) {
//^^^



//^^^

#line 1 "stat_res_mp_unhedged.FIA_LIAB.for"
if (t < commencement_period || t >= maturity_period)
     return NO_AVG;

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return max(cash_val(t), stat_res_carvm(t));

return stat_res_npr_unhedged(t) + stat_res_excess_unhedged(t);

}

//@@ END

//@@ START - stat_res_net
// Net Statutory Reserve                                                                                             
// Column:STAT_RES_NET
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(415,"stat_res_net",t);
}



//^^^

#line 1 "stat_res_net.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

// Force call for reporting
double stat_res_net_unhedged = this->stat_res_net_unhedged(t);

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return stat_res_net_mp(t);

return max(stat_res_net_stoch_res(t), stat_res_net_npr(t));

}

//@@ END

//@@ START - stat_res_net_excess
// Statutory Net Reserve Excess                                                                                             
// Column:STAT_RES_NET_EXCESS
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_net_excess(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(416,"stat_res_net_excess",t);
}



//^^^

#line 1 "stat_res_net_excess.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return NO_AVG;

if (!reins_flag)
	return stat_res_excess(t);

if (!isMainModel)
	{
	if (fabs(seg_element->stat_res_net_npr(t)) > model_point_amount_threshold)
		return seg_element->stat_res_net_excess(t)
		       * stat_res_net_npr(t)
			   / seg_element->stat_res_net_npr(t);

	return 0.0;
	}

return max(0.0, stat_res_net(t) - stat_res_net_npr(t));

}

//@@ END

//@@ START - stat_res_net_excess_unhedged
// Statutory Net Reserve Excess Unhedged                                                                                             
// Column:STAT_RES_NET_EXCESS_UNHEDGED
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_net_excess_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(417,"stat_res_net_excess_unhedged",t);
}



//^^^

#line 1 "stat_res_net_excess_unhedged.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return NO_AVG;

if (!reins_flag)
	return stat_res_excess(t);

if (!isMainModel)
	{
	if (fabs(seg_element->stat_res_net_npr_unhedged(t)) > model_point_amount_threshold)
		return seg_element->stat_res_net_excess_unhedged(t)
		       * stat_res_net_npr_unhedged(t)
			   / seg_element->stat_res_net_npr_unhedged(t);

	return 0.0;
	}

return max(0.0, stat_res_net_unhedged(t) - stat_res_net_npr_unhedged(t));

}

//@@ END

//@@ START - stat_res_net_mp
// Net Statutory Policy Reserve                                                                                             
// Column:STAT_RES_NET_MP
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_net_mp(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(418,"stat_res_net_mp",t);
}



//^^^

#line 1 "stat_res_net_mp.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if ((pricing_flag || nb_flag) && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return max(cash_val(t) - reins_cash_val(t),
			   stat_res_carvm_net(t));

return stat_res_net_npr(t) + stat_res_net_excess(t);

}

//@@ END

//@@ START - stat_res_net_mp_unhedged
// Net Statutory Policy Reserve Unhedged                                                                                             
// Column:STAT_RES_NET_MP_UNHEDGED
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_net_mp_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(419,"stat_res_net_mp_unhedged",t);
}



//^^^

#line 1 "stat_res_net_mp_unhedged.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if ((pricing_flag || nb_flag) && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return max(cash_val(t) - reins_cash_val(t),
			   stat_res_carvm_net(t));

return stat_res_net_npr_unhedged(t) + stat_res_net_excess_unhedged(t);

}

//@@ END

//@@ START - stat_res_net_npr
// Net Statutory Net Premium Reserve                                                                                             
// Column:STAT_RES_NET_NPR
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_net_npr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(420,"stat_res_net_npr",t);
}



//^^^

#line 1 "stat_res_net_npr.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if ((pricing_flag || nb_flag) && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return NO_AVG;

if (!reins_flag)
	return stat_res_npr(t);

return cash_val(t) - reins_cash_val(t);

}

//@@ END

//@@ START - stat_res_net_npr_unhedged
// Net Statutory Net Premium Reserve Unhedged                                                                                             
// Column:STAT_RES_NET_NPR_UNHEDGED
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_net_npr_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(421,"stat_res_net_npr_unhedged",t);
}



//^^^

#line 1 "stat_res_net_npr_unhedged.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if ((pricing_flag || nb_flag) && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return NO_AVG;

if (!reins_flag)
	return stat_res_npr_unhedged(t);

return cash_val(t) - reins_cash_val(t);

}

//@@ END

//@@ START - stat_res_net_stoch_res
// Net Statutory Reserve Stochastic Reserve                                                                                             
// Column:STAT_RES_NET_STOCH_RES
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_net_stoch_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(422,"stat_res_net_stoch_res",t);
}



//^^^

#line 1 "stat_res_net_stoch_res.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (!reins_flag)
	return stat_res_stoch_res(t);

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return NO_AVG;

if (t == start_period && valn_period != 0)
	return init_stat_res_net_stoch_res;

if (t == start_period && valn_period == 0
	|| (t == start_period + 1 && valn_period > 0)
	|| (pricing_flag && t == start_period + 1 && valn_period == 0))
	{
	if (sm_fia_ann_pba[0]->hedging_defn == UNHEDGED)
		return stat_res_net_stoch_res_unhedged(t);

	StrEnum::EnumValue pba_calc_defn = sm_fia_ann_pba[0]->res_cap_calc_defn;
	StrEnum::EnumValue pba_reins_defn = sm_fia_ann_pba[0]->reins_defn;
	StrEnum::EnumValue pba_hedging_defn = sm_fia_ann_pba[0]->hedging_defn;

	// Determine stochastic amount adjusted as stochastic amount with existing hedges
	double stoch_amt_adjusted = 0.0;

	sm_fia_ann_pba[0]->pba_code = STOCH_RES;
	sm_fia_ann_pba[0]->res_cap_calc_defn = RESERVES;
	sm_fia_ann_pba[0]->reins_defn = NET;
	sm_fia_ann_pba[0]->hedging_defn = HEDGED;
	sm_fia_ann_pba[0]->hedging_cash_flow_defn = EXISTING;

	// if not hedged, adjusted amount equals unhedged result
	if (!sm_fia_ann_pba[0]->hedging_flag)
		{
		stoch_amt_adjusted = stat_res_net_stoch_res_unhedged(t);

		// if required, need to back out policies adjustment
		if (pricing_flag && t == start_period + 1
			&& valn_period == 0)
			{
			if (fabs(fund_val_fixed(t)) > rate_ratio_threshold)
				stoch_amt_adjusted *= fund_val_b_bef(t) / fund_val_fixed(t);
			}		
		}			
	else
		{	
		stoch_amt_adjusted = sm_fia_ann_pba[0]->stoch_amt(0);
	
		sm_fia_ann_pba[0]->rebaseModel(0);
		}

	// Determine stochastic amount best estimate
	double stoch_amt_best_estimate = 0.0;

	sm_fia_ann_pba[0]->pba_code = STOCH_RES;
	sm_fia_ann_pba[0]->res_cap_calc_defn = RESERVES;
	sm_fia_ann_pba[0]->reins_defn = NET;
	sm_fia_ann_pba[0]->hedging_defn = HEDGED;
	sm_fia_ann_pba[0]->hedging_cash_flow_defn = BEST_ESTIMATE;

	// if not hedged, best estimate amount equals unhedged result
	if (!sm_fia_ann_pba[0]->hedging_flag)
		{
		stoch_amt_best_estimate = stat_res_net_stoch_res_unhedged(t);

		// if required, need to back out policies adjustment
		if (pricing_flag && t == start_period + 1
			&& valn_period == 0)
			{
			if (fabs(fund_val_fixed(t)) > rate_ratio_threshold)
				stoch_amt_best_estimate *= fund_val_b_bef(t) / fund_val_fixed(t);
			}		
		}			
	else
		{	
		stoch_amt_best_estimate = sm_fia_ann_pba[0]->stoch_amt(0);
	
		sm_fia_ann_pba[0]->rebaseModel(0);
		}
	
	double stoch_amt 
	= sm_fia_ann_pba[0]->hedging_e_factor(t)
	  * stoch_amt_best_estimate
	  + (1.0 - sm_fia_ann_pba[0]->hedging_e_factor(t))
	     * stoch_amt_adjusted;

	// restore pba definitions
	sm_fia_ann_pba[0]->res_cap_calc_defn = pba_calc_defn;
	sm_fia_ann_pba[0]->reins_defn = pba_reins_defn;
	sm_fia_ann_pba[0]->hedging_defn = pba_hedging_defn;

	return stoch_amt
		   * pba_rollforward_factor(t);
	}
	
return stat_res_net_stoch_res(t - 1) 
	   * pba_rollforward_factor(t);

}

//@@ END

//@@ START - stat_res_net_stoch_res_unhedged
// Net Statutory Reserve Stochastic Reserve Unhedged                                                                                             
// Column:STAT_RES_NET_STOCH_RES_UNHEDGED
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_net_stoch_res_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(423,"stat_res_net_stoch_res_unhedged",t);
}



//^^^

#line 1 "stat_res_net_stoch_res_unhedged.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (!reins_flag)
	return stat_res_stoch_res_unhedged(t);

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return NO_AVG;

if (t == start_period && valn_period != 0)
	return init_stat_res_net_stoch_res_unhedged;

if (t == start_period && valn_period == 0
	|| (t == start_period + 1 && valn_period > 0)
	|| (pricing_flag && t == start_period + 1 && valn_period == 0))
	{
	StrEnum::EnumValue pba_calc_defn = sm_fia_ann_pba[0]->res_cap_calc_defn;
	StrEnum::EnumValue pba_reins_defn = sm_fia_ann_pba[0]->reins_defn;
	StrEnum::EnumValue pba_hedging_defn = sm_fia_ann_pba[0]->hedging_defn;

	sm_fia_ann_pba[0]->pba_code = STOCH_RES;
	sm_fia_ann_pba[0]->res_cap_calc_defn = RESERVES;
	sm_fia_ann_pba[0]->reins_defn = NET;
	sm_fia_ann_pba[0]->hedging_defn = UNHEDGED;

	double stoch_amt = sm_fia_ann_pba[0]->stoch_amt(0);

	sm_fia_ann_pba[0]->rebaseModel(0);

	// restore pba definitions
	sm_fia_ann_pba[0]->res_cap_calc_defn = pba_calc_defn;
	sm_fia_ann_pba[0]->reins_defn = pba_reins_defn;
	sm_fia_ann_pba[0]->hedging_defn = pba_hedging_defn;

	return stoch_amt
		   * pba_rollforward_factor(t);
	}

return stat_res_net_stoch_res_unhedged(t - 1) 
	   * pba_rollforward_factor(t);

}

//@@ END

//@@ START - stat_res_net_unhedged
// Net Statutory Reserve Unhedged                                                                                             
// Column:STAT_RES_NET_UNHEDGED
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_net_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(424,"stat_res_net_unhedged",t);
}



//^^^

#line 1 "stat_res_net_unhedged.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return stat_res_net_mp_unhedged(t);

return max(stat_res_net_stoch_res_unhedged(t), stat_res_net_npr_unhedged(t));

}

//@@ END

//@@ START - stat_res_npr
// Statutory Net Premium Reserve                                                                                             
// Column:STAT_RES_NPR
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_npr(int t) {
//^^^



//^^^

#line 1 "stat_res_npr.FIA_LIAB.for"
if (t < commencement_period || t >= maturity_period)
     return NO_AVG;

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return NO_AVG;
     
return cash_val(t);

}

//@@ END

//@@ START - stat_res_npr_unhedged
// Statutory Net Premium Reserve Unhedged                                                                                             
// Column:STAT_RES_NPR_UNHEDGED
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_npr_unhedged(int t) {
//^^^



//^^^

#line 1 "stat_res_npr_unhedged.FIA_LIAB.for"
if (t < commencement_period || t >= maturity_period)
     return NO_AVG;

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return NO_AVG;
     
return cash_val(t);

}

//@@ END

//@@ START - stat_res_stoch_res
// Statutory Reserve Stochastic Reserve                                                                                             
// Column:STAT_RES_STOCH_RES
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_stoch_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(427,"stat_res_stoch_res",t);
}



//^^^

#line 1 "stat_res_stoch_res.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return NO_AVG;

if (t == start_period && valn_period != 0)
	return init_stat_res_stoch_res;

if (t == start_period && valn_period == 0
	|| (t == start_period + 1 && valn_period > 0)
	|| (pricing_flag && t == start_period + 1 && valn_period == 0))
	{
	if (sm_fia_ann_pba[0]->hedging_defn == UNHEDGED)
		return stat_res_stoch_res_unhedged(t);

	StrEnum::EnumValue pba_calc_defn = sm_fia_ann_pba[0]->res_cap_calc_defn;
	StrEnum::EnumValue pba_reins_defn = sm_fia_ann_pba[0]->reins_defn;
	StrEnum::EnumValue pba_hedging_defn = sm_fia_ann_pba[0]->hedging_defn;

	// Determine stochastic amount adjusted as stochastic amount with existing hedges
	double stoch_amt_adjusted = 0.0;

	sm_fia_ann_pba[0]->pba_code = STOCH_RES;
	sm_fia_ann_pba[0]->res_cap_calc_defn = RESERVES;
	sm_fia_ann_pba[0]->reins_defn = GROSS;
	sm_fia_ann_pba[0]->hedging_defn = HEDGED;
	sm_fia_ann_pba[0]->hedging_cash_flow_defn = EXISTING;

	// if not hedged, adjusted amount equals unhedged result
	if (!sm_fia_ann_pba[0]->hedging_flag)
		{
		stoch_amt_adjusted = stat_res_stoch_res_unhedged(t);

		// if required, need to back out policies adjustment
		if (pricing_flag && t == start_period + 1
				&& valn_period == 0)
			{
			if (fabs(fund_val_fixed(t)) > rate_ratio_threshold)
				stoch_amt_adjusted *= fund_val_b_bef(t) / fund_val_fixed(t);
			}		
		}			
	else
		{	
		stoch_amt_adjusted = sm_fia_ann_pba[0]->stoch_amt(0);
	
		sm_fia_ann_pba[0]->rebaseModel(0);
		}

	// Determine stochastic amount best estimate
	double stoch_amt_best_estimate = 0.0;

	sm_fia_ann_pba[0]->pba_code = STOCH_RES;
	sm_fia_ann_pba[0]->res_cap_calc_defn = RESERVES;
	sm_fia_ann_pba[0]->reins_defn = GROSS;
	sm_fia_ann_pba[0]->hedging_defn = HEDGED;
	sm_fia_ann_pba[0]->hedging_cash_flow_defn = BEST_ESTIMATE;

	// if not hedged, best estimate amount equals unhedged result
	if (!sm_fia_ann_pba[0]->hedging_flag)
		{
		stoch_amt_best_estimate = stat_res_stoch_res_unhedged(t);

		// if required, need to back out policies adjustment
		if (pricing_flag && t == start_period + 1
				&& valn_period == 0)
			{
			if (fabs(fund_val_fixed(t)) > rate_ratio_threshold)
				stoch_amt_best_estimate *= fund_val_b_bef(t) / fund_val_fixed(t);
			}		
		}			
	else
		{	
		stoch_amt_best_estimate = sm_fia_ann_pba[0]->stoch_amt(0);
	
		sm_fia_ann_pba[0]->rebaseModel(0);
		}
	
	double stoch_amt 
	= sm_fia_ann_pba[0]->hedging_e_factor(t)
	  * stoch_amt_best_estimate
	  + (1.0 - sm_fia_ann_pba[0]->hedging_e_factor(t))
	     * stoch_amt_adjusted;

	// restore pba definitions
	sm_fia_ann_pba[0]->res_cap_calc_defn = pba_calc_defn;
	sm_fia_ann_pba[0]->reins_defn = pba_reins_defn;
	sm_fia_ann_pba[0]->hedging_defn = pba_hedging_defn;

	return stoch_amt
		   * pba_rollforward_factor(t);
	}

return stat_res_stoch_res(t - 1) 
	   * pba_rollforward_factor(t);

}

//@@ END

//@@ START - stat_res_stoch_res_unhedged
// Statutory Reserve Stochastic Reserve Unhedged                                                                                             
// Column:STAT_RES_STOCH_RES_UNHEDGED
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_stoch_res_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(428,"stat_res_stoch_res_unhedged",t);
}



//^^^

#line 1 "stat_res_stoch_res_unhedged.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return NO_AVG;

if (t == start_period && valn_period != 0)
	return init_stat_res_stoch_res_unhedged;
	
if (t == start_period && valn_period == 0
	|| (t == start_period + 1 && valn_period > 0)
	|| (pricing_flag && t == start_period + 1 && valn_period == 0))
	{
	StrEnum::EnumValue pba_calc_defn = sm_fia_ann_pba[0]->res_cap_calc_defn;
	StrEnum::EnumValue pba_reins_defn = sm_fia_ann_pba[0]->reins_defn;
	StrEnum::EnumValue pba_hedging_defn = sm_fia_ann_pba[0]->hedging_defn;

	sm_fia_ann_pba[0]->pba_code = STOCH_RES;
	sm_fia_ann_pba[0]->res_cap_calc_defn = RESERVES;
	sm_fia_ann_pba[0]->reins_defn = GROSS;
	sm_fia_ann_pba[0]->hedging_defn = UNHEDGED;

	double stoch_amt = sm_fia_ann_pba[0]->stoch_amt(0);

	sm_fia_ann_pba[0]->rebaseModel(0);

	// restore pba definitions
	sm_fia_ann_pba[0]->res_cap_calc_defn = pba_calc_defn;
	sm_fia_ann_pba[0]->reins_defn = pba_reins_defn;
	sm_fia_ann_pba[0]->hedging_defn = pba_hedging_defn;

	return stoch_amt
		   * pba_rollforward_factor(t);
	}

return stat_res_stoch_res_unhedged(t - 1) 
	   * pba_rollforward_factor(t);

}

//@@ END

//@@ START - stat_res_unhedged
// Statutory Reserve Unhedged                                                                                             
// Column:STAT_RES_UNHEDGED
//========================================================
double FIA_LIAB_UDF::fia_liab_stat_res_unhedged(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(429,"stat_res_unhedged",t);
}



//^^^

#line 1 "stat_res_unhedged.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;

if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE
	|| sm_fia_ann_pba[0]->res_cap_calc_defn == CAPITAL)
	return stat_res_mp_unhedged(t);

return max(stat_res_stoch_res_unhedged(t), stat_res_npr_unhedged(t));

}

//@@ END

//@@ START - surr_benefits
// Surrender Benefits                                                                                             
// Column:SURR_BENEFITS
//========================================================
double FIA_LIAB_UDF::fia_liab_surr_benefits(int t) {
//^^^



//^^^

#line 1 "surr_benefits.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

return cash_val_bef(t)
	   * (1.0 - dth_claim_rate_mthly(t))
       * lapse_rate_mthly(t);

}

//@@ END

//@@ START - surr_chg
// Surrender Charge                                                                                             
// Column:SURR_CHG
//========================================================
double FIA_LIAB_UDF::fia_liab_surr_chg(int t) {
//^^^



//^^^

#line 1 "surr_chg.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
return fund_released_surr(t) - surr_benefits(t);

}

//@@ END

//@@ START - surr_chg_excess_withdrl_crbg
// Surr chg due to excess withdrawal                                                                                             
// Column:SURR_CHG_EXCESS_WITHDRL_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_surr_chg_excess_withdrl_crbg(int t) {
//^^^



//^^^

#line 1 "surr_chg_excess_withdrl_crbg.FIA_LIAB.for"
//20250506 New column with CRBG logic
//After surr&dth, before withdrl
if (t < commencement_period || t > maturity_period || mva_defn != CRBG)
	return NO_AVG;

double pfwd_entitlement = pfwd_entitlement_remaining_bom(t) * surv_period(t);
double gross_withdrl = gmwb_wdl_amt_e_bef_crbg(t) * surv_period(t);
double chg_base	= max(0, gross_withdrl - pfwd_entitlement);
		
double wdl_chg = fia->surr_chg_pct * chg_base;

return wdl_chg;

}

//@@ END

//@@ START - surr_chg_inf
// Surrender Charge Inforce End of Month                                                                                             
// Column:SURR_CHG_INF
//========================================================
double FIA_LIAB_UDF::fia_liab_surr_chg_inf(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(433,"surr_chg_inf",t);
}



//^^^

#line 1 "surr_chg_inf.FIA_LIAB.for"
//20250501 Replaced with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period && elapsed_mths <= 0)
	return NO_AVG;

double fund_value = max(fund_val_fixed(t), min_accum_val_e_crbg(t));;
double prem_bonus_recapture = prem_bonus_recap_e_crbg(t);
double pfwd_entitlement = pfwd_entitlement_remaining_e(t);

double surr_chg_base = fund_value - prem_bonus_recapture - pfwd_entitlement;

if (gmwb_chg_surr_timing_crbg == BEFORE_SC)
{
	surr_chg_base -= gmwb_chg_partial_e_crbg(t);
}

double surr_chg	= surr_chg_pct_crbg(t) * max(0, surr_chg_base);
	
return surr_chg;

}

//@@ END

//@@ START - surr_chg_inf_bef
// Surrender Charge Inforce End of Month Before Claims                                                                                             
// Column:SURR_CHG_INF_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_surr_chg_inf_bef(int t) {
//^^^



//^^^

#line 1 "surr_chg_inf_bef.FIA_LIAB.for"
//20250501 Replaced with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double fund_value = max(fund_val_e_bef(t), min_accum_val_e_bef_crbg(t));
double prem_bonus_recapture = prem_bonus_recap_e_bef_crbg(t);
double pfwd_entitlement = pfwd_entitlement_remaining_bom(t);

double surr_chg_base = fund_value - prem_bonus_recapture - pfwd_entitlement;

if (gmwb_chg_surr_timing_crbg == BEFORE_SC)
{
	surr_chg_base -= gmwb_chg_partial_bef_crbg(t);
}

double surr_chg	= surr_chg_pct * max(0, surr_chg_base);

if(myga_renew_ind_crbg == YES && pol_yr(t) > myga_init_term_crbg && myga_current_term_crbg(t) > 1)
{
	int shifted_pol_yr = mod(pol_yr(t) - myga_init_term_crbg, myga_renew_term_crbg);

	if (shifted_pol_yr < SMALL_DOUBLE)
	{
		shifted_pol_yr = myga_renew_term_crbg;
	}

	pol_yr_lookup = shifted_pol_yr;
	double surr_chg_renewal = surr_chg_pct_renewal_crbg;

	surr_chg = surr_chg_renewal * surr_chg_base;
}

return surr_chg;

}

//@@ END

//@@ START - surr_chg_inf_wo_mva
// Surrender Charge Without MVA Inforce End of Month                                                                                             
// Column:SURR_CHG_INF_WO_MVA
//========================================================
double FIA_LIAB_UDF::fia_liab_surr_chg_inf_wo_mva(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(435,"surr_chg_inf_wo_mva",t);
}



//^^^

#line 1 "surr_chg_inf_wo_mva.FIA_LIAB.for"
//MQ: This column is not used.
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if (t == commencement_period && elapsed_mths <= 0)
	return NO_AVG;

// Calculate the surrender charge amount
double surr_chg_base = 0.0;

if (surr_chg_defn == FUND_VALUE) 
	surr_chg_base = max(fund_val_fixed(t), contract_val(t)) - pfwd_entitlement_remaining_e(t);

if (surr_chg_defn == PREMIUM) 
	surr_chg_base = prem_cumul(t);

double surr_charge = surr_chg_pct * surr_chg_base;

// Ensure surrender charge is not greater than fund value and is not negative.
return max(0.0, min(surr_charge, max(fund_val_fixed(t), contract_val(t))));

}

//@@ END

//@@ START - surr_chg_inf_wo_mva_bef
// Surrender Charge Without MVA Inforce End of Month Before Claims                                                                                             
// Column:SURR_CHG_INF_WO_MVA_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_surr_chg_inf_wo_mva_bef(int t) {
//^^^



//^^^

#line 1 "surr_chg_inf_wo_mva_bef.FIA_LIAB.for"
//MQ: This column is not being used
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

// Calculate the surrender charge amount
double surr_chg_base = 0.0;

if (surr_chg_defn == FUND_VALUE) 
	surr_chg_base = max(fund_val_e_bef(t), contract_val_bef(t))- pfwd_entitlement_remaining_bom(t);

if (surr_chg_defn == PREMIUM) 
	surr_chg_base = prem_cumul_bef(t);

double surr_charge = surr_chg_pct * surr_chg_base;

// Ensure surrender charge is not greater than fund value and is not negative.
return max(0.0, min(surr_charge, max(fund_val_e_bef(t), contract_val_bef(t))));

}

//@@ END

//@@ START - surr_chg_pct_crbg
// Surr Chg Pct Crbg                                                                                             
// Column:SURR_CHG_PCT_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_surr_chg_pct_crbg(int t) {
//^^^



//^^^

#line 1 "surr_chg_pct_crbg.FIA_LIAB.for"
//20250501 New columns with CRBG logic
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

double surr_chg_pct_local = surr_chg_pct;

if(myga_renew_ind_crbg == YES && pol_yr(t) > myga_init_term_crbg && myga_current_term_crbg(t) > 1)
{
	int shifted_pol_yr = mod(pol_yr(t) - myga_init_term_crbg, myga_renew_term_crbg);

	if (shifted_pol_yr < SMALL_DOUBLE)
	{
		shifted_pol_yr = myga_renew_term_crbg;
	}

	pol_yr_lookup = shifted_pol_yr;
	double surr_chg_renewal = surr_chg_pct_renewal_crbg;

	surr_chg_pct_local = surr_chg_renewal;
}

return surr_chg_pct_local;


}

//@@ END

//@@ START - surv
// Proportion of Initial Life In Force                                                                                             
// Column:SURV
//========================================================
double FIA_LIAB_UDF::fia_liab_surv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(438,"surv",t);
}



//^^^

#line 1 "surv.FIA_LIAB.for"
if (t < commencement_period || t > t_high)
	return NO_AVG;

if (decrements_defn == NO)
	return 1.0;
	
if (t == commencement_period)
	return 1.0;

if (surv(t - 1) < model_point_amount_threshold)
	return 0.0;

return surv(t - 1) * surv_period(t);

}

//@@ END

//@@ START - surv_period
// Probability of Survival for the Period                                                                                             
// Column:SURV_PERIOD
//========================================================
double FIA_LIAB_UDF::fia_liab_surv_period(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(439,"surv_period",t);
}



//^^^

#line 1 "surv_period.FIA_LIAB.for"
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;
	
if (decrements_defn == NO || t == commencement_period)
	return 1.0;
	
//if (t == t_high)
//	return 0.0;

return (1.0 - dth_claim_rate_mthly(t))
	   * (1.0 - lapse_rate_mthly(t) - annuitzn_rate_mthly(t));

}

//@@ END

//@@ START - tax_bk_prof
// Tax on Book Profit                                                                                             
// Column:TAX_BK_PROF
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_bk_prof(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(440,"tax_bk_prof",t);
}



//^^^

#line 1 "tax_bk_prof.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (cal_mth(t) == 1)
	return tax_bk_prof_ytd(t);

return tax_bk_prof_ytd(t)
       - tax_bk_prof_ytd(t - 1);

}

//@@ END

//@@ START - tax_bk_prof_ytd
// Tax on Book Profit Calendar Year to Date                                                                                             
// Column:TAX_BK_PROF_YTD
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_bk_prof_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(441,"tax_bk_prof_ytd",t);
}



//^^^

#line 1 "tax_bk_prof_ytd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_tax_bk_prof_ytd;
		
	return NO_AVG;	
	}

if (!pricing_flag || tax_loss_treatment == IMMEDIATE_LOSS_RECOGNITION)
	return taxable_inc_bk_prof_ytd(t)
	       * tax_rate; 

if (tax_loss_treatment == ZERO_TAX)
	return (taxable_inc_bk_prof_ytd(t) 
	        - min(taxable_inc_bk_prof_ytd(t) + taxable_inc_tgt_cap_ytd(t), 0.0))
		   * tax_rate; 	

// tax_loss_treatment == TAX_LOSS_CARRYFORWARD	
return (taxable_inc_bk_prof_ytd(t) 
	    + taxable_inc_carryfwd_addn_ytd(t)
	    - taxable_inc_carryfwd_applied_ytd(t))
       * tax_rate;

}

//@@ END

//@@ START - tax_capzd_prem
// Tax Capitalized Premium                                                                                             
// Column:TAX_CAPZD_PREM
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_capzd_prem(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(442,"tax_capzd_prem",t);
}



//^^^

#line 1 "tax_capzd_prem.FIA_LIAB.for"
if (t <= start_period || t > maturity_period)
	return NO_AVG;
	
return (prem_paid(t) 
        - reins_prem(t)
		+ reins_prem_tax(t)
	    + reins_dth_benefits(t)
		+ reins_ann_benefits_eom(t)
	    + reins_maturity_benefits(t)
	    + reins_surr_benefits(t)
	    + reins_withdrl_benefits(t))
	   * tax_capzd_prem_pct_qualify
	   * tax_capzd_prem_pct;

}

//@@ END

//@@ START - tax_capzd_prem_amortzn
// Tax Capitalized Premium Amortization                                                                                             
// Column:TAX_CAPZD_PREM_AMORTZN
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_capzd_prem_amortzn(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(443,"tax_capzd_prem_amortzn",t);
}



//^^^

#line 1 "tax_capzd_prem_amortzn.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

// Each successive time step uses the relative calendar year from the original projection date
int proj_mth_adj = get_mth_from_date(proj_date);
int proj_start_mth_adj = proj_mth_adj == 12 ? 1: proj_mth_adj + 1;
int cal_yr_relative_adj = 1 + floor((proj_start_mth_adj + (t + valn_period) - 2) / 12.0);

double from_current_capzd = 0.0;
double from_capzd_aft_proj_date = 0.0;
double from_capzd_bef_proj_date = 0.0;

// First year amortization occurs in the month of capitalization
if (tax_capzd_prem_amortzn_yrs > 0)
	from_current_capzd = tax_capzd_prem(t) 
	                     / (2.0 * tax_capzd_prem_amortzn_yrs);

// Amounts capitalized during the projection are amortized using the temporary table schedule
from_capzd_aft_proj_date = tax_capzd_prem_amortzn_sched(t, cal_yr_relative_adj) / 12.0;

// Input variable for prior capitalization applies only for portfolio projections.
// This feature is not practical for seriatim projections.

return from_current_capzd
       + from_capzd_aft_proj_date
       + from_capzd_bef_proj_date;

}

//@@ END

//@@ START - tax_capzd_prem_unamortzd
// Tax Capitalized Premium Unamortized                                                                                             
// Column:TAX_CAPZD_PREM_UNAMORTZD
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_capzd_prem_unamortzd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(444,"tax_capzd_prem_unamortzd",t);
}



//^^^

#line 1 "tax_capzd_prem_unamortzd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	double amortzn_prev_time_step = 0.0;
	
	// Sum temporary table schedule from previous time step
	if (time_step_flag && valn_period > 0 && tax_capzd_prem_amortzn_yrs > 0)
		{
		double total_amortzn = 0.0;
		
		// Each successive time step uses the relative calendar year from the original projection date
		int proj_mth_adj = get_mth_from_date(proj_date);
		int proj_start_mth_adj = proj_mth_adj == 12 ? 1: proj_mth_adj + 1;
		int cal_yr_relative_adj = 1 + floor((proj_start_mth_adj + (t + valn_period) - 2) / 12.0);
		
		amortzn_prev_time_step = ((12 - cal_mth(t)) / 12.0)
		                         * tax_capzd_prem_amortzn_sched(t, cal_yr_relative_adj);
		
		for (int k = 1; k <= tax_capzd_prem_amortzn_yrs; k++)
			amortzn_prev_time_step += tax_capzd_prem_amortzn_sched(t, cal_yr_relative_adj + k);
		}
	
	return amortzn_prev_time_step;
	}	

return tax_capzd_prem_unamortzd(t - 1)
       + tax_capzd_prem(t)
       - tax_capzd_prem_amortzn(t);

}

//@@ END

//@@ START - tax_earnings_accum
// Tax on Accumulated Earnings                                                                                             
// Column:TAX_EARNINGS_ACCUM
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_earnings_accum(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(445,"tax_earnings_accum",t);
}



//^^^

#line 1 "tax_earnings_accum.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

if (cal_mth(t) == 1)
	return tax_earnings_accum_ytd(t);

return tax_earnings_accum_ytd(t)
       - tax_earnings_accum_ytd(t - 1);

}

//@@ END

//@@ START - tax_earnings_accum_ytd
// Tax on Accumulated Earnings Calendar Year to Date                                                                                             
// Column:TAX_EARNINGS_ACCUM_YTD
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_earnings_accum_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(446,"tax_earnings_accum_ytd",t);
}



//^^^

#line 1 "tax_earnings_accum_ytd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_tax_earnings_accum_ytd;
		
	return NO_AVG;	
	}

return taxable_inc_earnings_accum_ytd(t) 
       * tax_rate;

}

//@@ END

//@@ START - tax_res
// Tax Reserve                                                                                             
// Column:TAX_RES
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_res(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(447,"tax_res",t);
}



//^^^

#line 1 "tax_res.FIA_LIAB.for"
if (t < commencement_period || t >= maturity_period)
     return NO_AVG;

return tax_res_mp(t);

}

//@@ END

//@@ START - tax_res_carvm
// Tax CARVM Reserve                                                                                             
// Column:TAX_RES_CARVM
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_res_carvm(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(448,"tax_res_carvm",t);
}



//^^^

#line 1 "tax_res_carvm.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
     return NO_AVG;

if (elapsed_mths <= 0 && t == commencement_period)
	return 0.0;

if (tax_res_defn == TAX_EQUALS_STAT)
	return stat_res_carvm(t);

if (tax_res_defn == _2017_TAX_REFORM)
	return tax_res_pct_stat * stat_res_carvm(t);

if (tax_res_defn == PERCENT_FUND_VALUE)
	{
	if (tax_res_mva_defn == EXCLUDED)
		return max(fund_val_fixed(t), contract_val(t)) * tax_res_pct;

	return ((max(fund_val_fixed(t), contract_val(t)) - pfwd_entitlement_remaining_e(t))
		    * mva_ratio(t)
		    + pfwd_entitlement_remaining_e(t))
		   * tax_res_pct;
	}

if (tax_res_defn == PERCENT_CASH_VALUE)
	{
	if (tax_res_mva_defn == EXCLUDED)
		return cash_val_wo_mva(t) * tax_res_pct;

	return cash_val(t) * tax_res_pct;
	}

if (t == 0 && valn_period != 0)
	return init_tax_res_carvm;

if (t == 1)
	tax_res_carvm(t - 1); //force call for calculation order

// Determine if model point uses monthly sum cap crediting and use that in check for full CARVM calculation
// Will calculating CARVM monthly for monthly sum cap cases since index crediting is based on cumulative changes in the index
bool mthly_sum_cap_model_point = false;
for (int i = 0; i < sm_fia_account.size(); i++)
	{
	if (sm_fia_account[i]->crediting_rate_defn == MONTHLY_SUM_CAP)
		{
		mthly_sum_cap_model_point = true;
		break;
		}
	}

if ((t == 0 && valn_period == 0) || t + elapsed_mths == 1 || pol_mth(t) == 6 || pol_mth(t) == 12 || cal_mth(t) == 12
	|| mthly_sum_cap_model_point)  
	{
	if (t + elapsed_mths <= 0)
		return NO_AVG;
	
	double tax_res_carvm = 0.0;

	if (tax_carvm_calc_annuitzn_defn != NOT_APPLICABLE && carvm_tax_annuitzn_tests_input.size() == 0)
		{
		split_string_usl(carvm_tax_annuitzn_tests.c_str(), carvm_tax_annuitzn_tests_input, ",");
		carvm_tax_annuitzn_tests_cnt = carvm_tax_annuitzn_tests_input.size();
		}
	
	gmwb_exercise_point_test_cnt = 1;
	// If GMWB is already exercised, we only project CARVM with 1 exercise point equal to 0
	// Else run tests specified plus one test of no GMWB exercise
	if (gmwb_flag && pol_yr(t) <= gmwb_exercise_yrs_crbg(t))
		{
		gmwb_exercise_points_input.clear();
		gmwb_exercise_point_test_cnt = 1;

		//Pull in testing points for GWMB based off of Issue Date
		split_string_usl(carvm_tax_gmwb_exercise_points_issue.c_str(), gmwb_exercise_points_input, ",");
		gmwb_exercise_point_test_cnt = gmwb_exercise_points_input.size();	

		//*********************** Test Valuation Period Exercise Points from input variable carvm_gmwb_exercise_points_valn_prd ***********************
		//Pull in testing points for GWMB based off of Valuation Period 
		vector <string> gmwb_exercise_points_input_valn_prd;
		split_string_usl(carvm_tax_gmwb_exercise_points_valn_prd.c_str(), gmwb_exercise_points_input_valn_prd, ",");
		
		//Test Valuation Period exercise points to see if any overlap with Issue Date
		for (int i_valn_prd = 0; i_valn_prd < gmwb_exercise_points_input_valn_prd.size(); i_valn_prd++)
			{
			if (gmwb_exercise_points_input_valn_prd.size() == 1 && atoi(xstring(gmwb_exercise_points_input_valn_prd[0])) == 0)
				break;
	
			int testing_exercise_point_valn_period = atoi(xstring(gmwb_exercise_points_input_valn_prd[i_valn_prd])) + pol_yr(t) - 1;
			int testing_count = 0;

			for (int i_issue = 0; i_issue < gmwb_exercise_points_input.size(); i_issue++)
				{
				int testing_exercise_point_issue = atoi(xstring(gmwb_exercise_points_input[i_issue]));
				
				if (testing_exercise_point_valn_period == testing_exercise_point_issue)
					testing_count ++;
				}
			
			//Add new exercise point if testing point doesn't overlap	
			if (testing_count == 0)
				gmwb_exercise_points_input.insert(gmwb_exercise_points_input.end(), to_string(testing_exercise_point_valn_period));
			}

		//*********************** Test Attained Age Exercise Points from input variable carvm_gmwb_exercise_points_attained_age ***********************
		//Pull in testing points for GWMB based off of Attained Age 
		vector <string> gmwb_exercise_points_input_attained_age;
		split_string_usl(carvm_tax_gmwb_exercise_points_attained_age.c_str(), gmwb_exercise_points_input_attained_age, ",");
		
		//Test Attained Age exercise points to see if any overlap with Issue Date
		for (int i_attained_age = 0; i_attained_age < gmwb_exercise_points_input_attained_age.size(); i_attained_age++)
			{
			if (gmwb_exercise_points_input_attained_age.size() == 1 && atoi(xstring(gmwb_exercise_points_input_attained_age[0])) == 0)
				break;

			int testing_exercise_point_attained_age = atoi(xstring(gmwb_exercise_points_input_attained_age[i_attained_age])) - issue_age_mp - gmwb_req_yrs_wait;
			int testing_count = 0;

			if (testing_exercise_point_attained_age < 0)
				testing_exercise_point_attained_age = 0;
		
			for (int i_issue = 0; i_issue < gmwb_exercise_points_input.size(); i_issue++)
				{
				int testing_exercise_point_issue = atoi(xstring(gmwb_exercise_points_input[i_issue]));
				
				if (testing_exercise_point_attained_age == testing_exercise_point_issue)
					testing_count ++;
				}
			
			//Add new exercise point if testing point doesn't overlap	
			if (testing_count == 0)
				gmwb_exercise_points_input.insert(gmwb_exercise_points_input.end(), to_string(testing_exercise_point_attained_age));
			}
		
		//Sort the vector
		vector <int> gmwb_exercise_points_input_temp;
		for (int i_order = 0; i_order < gmwb_exercise_points_input.size(); i_order++)
			gmwb_exercise_points_input_temp.insert(gmwb_exercise_points_input_temp.end(), atoi(xstring(gmwb_exercise_points_input[i_order])));
		
		sort(gmwb_exercise_points_input_temp.begin(), gmwb_exercise_points_input_temp.end());
		gmwb_exercise_points_input.clear();

		for (int i_order = 0; i_order < gmwb_exercise_points_input_temp.size(); i_order++)
			gmwb_exercise_points_input.insert(gmwb_exercise_points_input.end(), to_string(gmwb_exercise_points_input_temp[i_order]));
		
		gmwb_exercise_point_test_cnt = gmwb_exercise_points_input.size() + 1;	
		}

	for (int i = 0; i < carvm_tax_annuitzn_tests_cnt; i++)
		{
		if (tax_carvm_calc_annuitzn_defn != NOT_APPLICABLE)
			carvm_annuitzn_tests_number = atoi(xstring(carvm_tax_annuitzn_tests_input[i]));

		for (int j = 0; j < gmwb_exercise_point_test_cnt; j++)
			{
			if (gmwb_flag && pol_yr(t) <= gmwb_exercise_yrs_crbg(t))
				{
				if (j < gmwb_exercise_point_test_cnt - 1)
					gmwb_exercise_point = atoi(xstring(gmwb_exercise_points_input[j]));
				else // Test with no exercise of GMWB
					gmwb_exercise_point = 9999; // No exercise of GMWB
				}
			else
				gmwb_exercise_point = 0;

			for (int k = 0; k < sm_carvm_tax.size() ; k++)
				{
				sm_carvm_tax[k].resize(1);
				sm_carvm_tax[k][0]->res_period = t;
				sm_carvm_tax[k][0]->rates_ptr = rates_ptr;
				sm_carvm_tax[k][0]->set_hidden_variables();

				if (sm_carvm_tax[k][0]->res_integrated(0) > tax_res_carvm)
					tax_res_carvm = sm_carvm_tax[k][0]->res_integrated(0);
				
				sm_carvm_tax[k].resize(0);
				}	

			if (carvm_tax_detail_rpt_defn == YES)
				{
				write_reserves(t, "TAX", carvm_annuitzn_tests_number, gmwb_exercise_point);
				}
			}
		}
	
	return tax_res_carvm;
	}

if (fabs(fund_val_fixed(t - 1)) < model_point_amount_threshold)
	return 0.0;

return tax_res_carvm(t - 1)
	   * (fund_val_fixed(t) / fund_val_fixed(t - 1));	

}

//@@ END

//@@ START - tax_res_carvm_net
// Tax CARVM Reserve Net                                                                                             
// Column:TAX_RES_CARVM_NET
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_res_carvm_net(int t) {
//^^^



//^^^

#line 1 "tax_res_carvm_net.FIA_LIAB.for"
if (t < commencement_period || t >= maturity_period)
	return NO_AVG;

if (tax_res_defn == TAX_EQUALS_STAT)
	return stat_res_carvm_net(t);

if (!reins_flag)
	return tax_res_carvm(t);

return tax_res_carvm(t) * (1.0 - reins_pct);

}

//@@ END

//@@ START - tax_res_incr
// Tax Reserve Increase                                                                                             
// Column:TAX_RES_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_res_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(450,"tax_res_incr",t);
}



//^^^

#line 1 "tax_res_incr.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tax_res(t)
	   - tax_res(t - 1);

}

//@@ END

//@@ START - tax_res_mp
// Tax Policy Reserve                                                                                             
// Column:TAX_RES_MP
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_res_mp(int t) {
//^^^



//^^^

#line 1 "tax_res_mp.FIA_LIAB.for"
if (t < commencement_period || t > maturity_period)
	return NO_AVG;

if ((pricing_flag || nb_flag) && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (elapsed_mths <= 0 && t == commencement_period)
	return 0.0;

if (tax_res_defn == TAX_EQUALS_STAT)
	return stat_res_mp(t);

// Use statutory formulaic reserve for tax comparison
/*double stat_res_mp 
= max(cash_val(t), stat_res_carvm(t));

return min(max(cash_val(t), tax_res_carvm(t)),
           stat_res_mp);*/

//20250527 CRBG logic
 double tax_res =  min(stat_res(t), max(0.9281 * stat_res(t), cash_val_wo_mva(t)));

 return tax_res;

}

//@@ END

//@@ START - tax_tgt_cap
// Tax on Target Capital Income                                                                                             
// Column:TAX_TGT_CAP
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_tgt_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(452,"tax_tgt_cap",t);
}



//^^^

#line 1 "tax_tgt_cap.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
if (cal_mth(t) == 1)
	return tax_tgt_cap_ytd(t);

return tax_tgt_cap_ytd(t)
       - tax_tgt_cap_ytd(t - 1);

}

//@@ END

//@@ START - tax_tgt_cap_ytd
// Tax on Target Capital Income Calendar Year to Date                                                                                             
// Column:TAX_TGT_CAP_YTD
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_tgt_cap_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(453,"tax_tgt_cap_ytd",t);
}



//^^^

#line 1 "tax_tgt_cap_ytd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_tax_tgt_cap_ytd;
		
	return NO_AVG;	
	}
	
return taxable_inc_tgt_cap_ytd(t) 
       * tax_rate;

}

//@@ END

//@@ START - taxable_inc_bk_prof
// Taxable Income Book Profit                                                                                             
// Column:TAXABLE_INC_BK_PROF
//========================================================
double FIA_LIAB_UDF::fia_liab_taxable_inc_bk_prof(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(454,"taxable_inc_bk_prof",t);
}



//^^^

#line 1 "taxable_inc_bk_prof.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return prem_paid(t)
	   - reins_prem(t)
	   + reins_prem_tax(t)
	   + tax_capzd_prem(t) // This result is net of reinsurance
	   - tax_capzd_prem_amortzn(t) // This result is net of reinsurance
	   + direct_cash_flow_int(t)
       - reins_cash_flow_int(t)
       + inv_inc_res(t)
       - reins_inv_inc_res(t)
       + inv_inc_undistrib_earnings(t)
	   - dth_benefits(t)
	   - ann_benefits_eom(t)
	   - maturity_benefits(t)
	   - surr_benefits(t)	
       - withdrl_benefits(t)
       + reins_dth_benefits(t)
	   + reins_ann_benefits_eom(t)
	   + reins_maturity_benefits(t)
	   + reins_surr_benefits(t)
	   + reins_withdrl_benefits(t)
	   + reins_comm_reimb(t)
       - tax_res_incr(t)
       + reins_tax_res_incr(t)
       - comm_bom(t)
	   - comm_eom(t)
	   + comm_chargeback(t)
	   - acq_exp(t)
	   - maint_exp_bom(t)
	   - maint_exp_eom(t)
	   - prem_tax(t)
	   - reins_exp(t)
       + reins_exp_reimb(t)
	   - hedge_cost(t);

}

//@@ END

//@@ START - taxable_inc_bk_prof_ytd
// Taxable Income Book Profit Calendar Year to Date                                                                                             
// Column:TAXABLE_INC_BK_PROF_YTD
//========================================================
double FIA_LIAB_UDF::fia_liab_taxable_inc_bk_prof_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(455,"taxable_inc_bk_prof_ytd",t);
}



//^^^

#line 1 "taxable_inc_bk_prof_ytd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_taxable_inc_bk_prof_ytd;
		
	return NO_AVG;	
	}
	
if (cal_mth(t) == 1)
	return taxable_inc_bk_prof(t);
  
return taxable_inc_bk_prof_ytd(t - 1) 
	   + taxable_inc_bk_prof(t);

}

//@@ END

//@@ START - taxable_inc_carryfwd_addn_ytd
// Taxable Income Carry Forward Addition Calendar Year to Date                                                                                             
// Column:TAXABLE_INC_CARRYFWD_ADDN_YTD
//========================================================
double FIA_LIAB_UDF::fia_liab_taxable_inc_carryfwd_addn_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(456,"taxable_inc_carryfwd_addn_ytd",t);
}



//^^^

#line 1 "taxable_inc_carryfwd_addn_ytd.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
if (!pricing_flag || tax_loss_treatment != TAX_LOSS_CARRYFORWARD )
	return NO_AVG;
	
return max(- taxable_inc_bk_prof_ytd(t) - taxable_inc_tgt_cap_ytd(t), 0.0);

}

//@@ END

//@@ START - taxable_inc_carryfwd_applied_ytd
// Taxable Income Carry Forward Applied Calendar Year to Date                                                                                             
// Column:TAXABLE_INC_CARRYFWD_APPLIED_YTD
//========================================================
double FIA_LIAB_UDF::fia_liab_taxable_inc_carryfwd_applied_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(457,"taxable_inc_carryfwd_applied_ytd",t);
}



//^^^

#line 1 "taxable_inc_carryfwd_applied_ytd.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;
	
if (!pricing_flag || tax_loss_treatment != TAX_LOSS_CARRYFORWARD )
	return NO_AVG;
	
return min(taxable_inc_carryfwd_avail(t - 1),
	       max(taxable_inc_bk_prof_ytd(t), 0.0));

}

//@@ END

//@@ START - taxable_inc_carryfwd_avail
// Taxable Income Carry Forward Available                                                                                             
// Column:TAXABLE_INC_CARRYFWD_AVAIL
//========================================================
double FIA_LIAB_UDF::fia_liab_taxable_inc_carryfwd_avail(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(458,"taxable_inc_carryfwd_avail",t);
}



//^^^

#line 1 "taxable_inc_carryfwd_avail.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!pricing_flag || tax_loss_treatment != TAX_LOSS_CARRYFORWARD )
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_taxable_inc_carryfwd_avail;
		
	return NO_AVG;	
	}
	
if (cal_mth(t) == 12)
	return taxable_inc_carryfwd_avail(t - 1)
	       - taxable_inc_carryfwd_applied_ytd(t)
	       + taxable_inc_carryfwd_addn_ytd(t);
  
return taxable_inc_carryfwd_avail(t - 1);

}

//@@ END

//@@ START - taxable_inc_earnings_accum
// Taxable Income Accumulated Earnings                                                                                             
// Column:TAXABLE_INC_EARNINGS_ACCUM
//========================================================
double FIA_LIAB_UDF::fia_liab_taxable_inc_earnings_accum(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(459,"taxable_inc_earnings_accum",t);
}



//^^^

#line 1 "taxable_inc_earnings_accum.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return inv_inc_earnings_accum(t);

}

//@@ END

//@@ START - taxable_inc_earnings_accum_ytd
// Taxable Income Accumulated Earnings Calendar Year to Date                                                                                             
// Column:TAXABLE_INC_EARNINGS_ACCUM_YTD
//========================================================
double FIA_LIAB_UDF::fia_liab_taxable_inc_earnings_accum_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(460,"taxable_inc_earnings_accum_ytd",t);
}



//^^^

#line 1 "taxable_inc_earnings_accum_ytd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_taxable_inc_earnings_accum_ytd;
		
	return NO_AVG;	
	}

if (cal_mth(t) == 1)
	return taxable_inc_earnings_accum(t);
  
return taxable_inc_earnings_accum_ytd(t - 1) 
	   + taxable_inc_earnings_accum(t);

}

//@@ END

//@@ START - taxable_inc_tgt_cap
// Taxable Income Target Capital                                                                                             
// Column:TAXABLE_INC_TGT_CAP
//========================================================
double FIA_LIAB_UDF::fia_liab_taxable_inc_tgt_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(461,"taxable_inc_tgt_cap",t);
}



//^^^

#line 1 "taxable_inc_tgt_cap.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return inv_inc_tgt_cap(t);

}

//@@ END

//@@ START - taxable_inc_tgt_cap_ytd
// Taxable Income Target Capital Calendar Year to Date                                                                                             
// Column:TAXABLE_INC_TGT_CAP_YTD
//========================================================
double FIA_LIAB_UDF::fia_liab_taxable_inc_tgt_cap_ytd(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(462,"taxable_inc_tgt_cap_ytd",t);
}



//^^^

#line 1 "taxable_inc_tgt_cap_ytd.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_taxable_inc_tgt_cap_ytd;
		
	return NO_AVG;	
	}
	
if (cal_mth(t) == 1)
	return taxable_inc_tgt_cap(t);
  
return taxable_inc_tgt_cap_ytd(t - 1) 
	   + taxable_inc_tgt_cap(t);

}

//@@ END

//@@ START - tgt_cap
// Target Capital                                                                                             
// Column:TGT_CAP
//========================================================
double FIA_LIAB_UDF::fia_liab_tgt_cap(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(463,"tgt_cap",t);
}



//^^^

#line 1 "tgt_cap.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (!tgt_cap_flag)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

return rbc(t) * tgt_cap_rbc_mult;

}

//@@ END

//@@ START - tgt_cap_effect
// Target Capital Effect                                                                                             
// Column:TGT_CAP_EFFECT
//========================================================
double FIA_LIAB_UDF::fia_liab_tgt_cap_effect(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(464,"tgt_cap_effect",t);
}



//^^^

#line 1 "tgt_cap_effect.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return - tgt_cap_incr(t)
	   + inv_inc_tgt_cap(t)
	   - tax_tgt_cap(t);

}

//@@ END

//@@ START - tgt_cap_incr
// Target Capital Increase                                                                                             
// Column:TGT_CAP_INCR
//========================================================
double FIA_LIAB_UDF::fia_liab_tgt_cap_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(465,"tgt_cap_incr",t);
}



//^^^

#line 1 "tgt_cap_incr.FIA_LIAB.for"
if (t <= start_period || t > final_period)
	return NO_AVG;

return tgt_cap(t) - tgt_cap(t - 1);

}

//@@ END

//@@ START - undistrib_earnings
// Undistributed Earnings                                                                                             
// Column:UNDISTRIB_EARNINGS
//========================================================
double FIA_LIAB_UDF::fia_liab_undistrib_earnings(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(466,"undistrib_earnings",t);
}



//^^^

#line 1 "undistrib_earnings.FIA_LIAB.for"
if (t < start_period || t > final_period)
	return NO_AVG;

if (pricing_flag && t == start_period
	&& valn_period == 0)
	return NO_AVG;	

if (t == start_period)
	{
	if (time_step_flag && valn_period > 0)
		return init_undistrib_earnings;
		
	return NO_AVG;	
	}
	
if (cal_mth(t) == 12 || last_period_indicator(t)
	|| (prof_distribn_mode == QUARTERLY
        && xint(cal_mth(t)) % 3 == 0)
	|| prof_distribn_mode == MONTHLY)
	return NO_AVG;

return undistrib_earnings(t - 1)
	   + bk_prof_aft_tax(t)
	   - tgt_cap_incr(t)
	   + inv_inc_tgt_cap(t)
	   - tax_tgt_cap(t);

}

//@@ END

//@@ START - valn_tgt_gaap_mrb
// Valuation Target - GAAP Market Risk Benefits                                                                                             
// Column:VALN_TGT_GAAP_MRB
//========================================================
double FIA_LIAB_UDF::fia_liab_valn_tgt_gaap_mrb(int t) {
//^^^



//^^^

#line 1 "valn_tgt_gaap_mrb.FIA_LIAB.for"
if (t > commencement_period)
	return NO_AVG;

if (!gaap_flag || !valn_flag)
	return NO_AVG;

for (int el = 0; el < sm_fia_mrb.size(); el ++)
	{
	for (int tt = start_period; tt <= final_period; tt++)
		{
		if (gmwb_flag)
			{
			sm_fia_mrb[el]->pv_gmwb_claim(tt);
			sm_fia_mrb[el]->pv_gmwb_chg(tt);
			}

		sm_fia_mrb[el]->fund_val(tt);
		sm_fia_mrb[el]->policies_inf(tt);
		}
	}

return 1.0;

}

//@@ END

//@@ START - valn_tgt_gaap_sfas97rd
// Valuation Target - GAAP SFAS 97 Retrospective Deposit                                                                                             
// Column:VALN_TGT_GAAP_SFAS97RD
//========================================================
double FIA_LIAB_UDF::fia_liab_valn_tgt_gaap_sfas97rd(int t) {
//^^^



//^^^

#line 1 "valn_tgt_gaap_sfas97rd.FIA_LIAB.for"
if (t > commencement_period)
	return NO_AVG;

if (!gaap_flag && !valn_flag)
	return NO_AVG;

for (int el = 0; el < sm_fia_sfas97rd.size(); el ++)
	{
	for (int tt = 0; tt <= sm_fia_sfas97rd[el]->final_period; tt++)
		{
		sm_fia_sfas97rd[el]->dac_acq_exp(tt);
		sm_fia_sfas97rd[el]->dac_comm(tt);
		sm_fia_sfas97rd[el]->dac_prem_bonus(tt);	
		sm_fia_sfas97rd[el]->sfas133_liab(tt);
		}
	}
return 1.0;

}

//@@ END

//@@ START - valn_tgt_pba_scen_amt
// Valuation Target - PBA Scenario Amount                                                                                             
// Column:VALN_TGT_PBA_SCEN_AMT
//========================================================
double FIA_LIAB_UDF::fia_liab_valn_tgt_pba_scen_amt(int t) {
//^^^



//^^^

#line 1 "valn_tgt_pba_scen_amt.FIA_LIAB.for"
if (!valn_flag || (isMainModel && !pricing_flag))
	return NO_AVG;

if (t != 0)
	return NO_AVG;

#if defined(__ANN_PBA_PBA_H_)
if (sm_fia_ann_pba[0]->res_cap_calc_defn == NOT_APPLICABLE)
	return NO_AVG;

int pba_loops = 10;
StrEnum::EnumValue pba_calc_defn = sm_fia_ann_pba[0]->res_cap_calc_defn;
StrEnum::EnumValue pba_reins_defn = sm_fia_ann_pba[0]->reins_defn;
StrEnum::EnumValue pba_hedging_defn = sm_fia_ann_pba[0]->hedging_defn;

pba_valn_flag = true;
pba_scen_amt_valn_flag = true;

for (int loop = 1; loop <= pba_loops; loop++)
	{
	rbc_scen_amt_valn_flag = false;
	res_scen_amt_valn_flag = false;

	if (loop == 1) // Reserves Net Hedged Best Estimate
		{
		if (pba_calc_defn == CAPITAL)
			continue;

		if (pba_reins_defn == GROSS)
			continue;
			
		if (!reins_flag)
			continue;			

		if (pba_hedging_defn == UNHEDGED)
			continue;

		res_scen_amt_valn_flag = true;
	    sm_fia_ann_pba[0]->pba_code = STOCH_RES;
		sm_fia_ann_pba[0]->res_cap_calc_defn = RESERVES;
		sm_fia_ann_pba[0]->reins_defn = NET;
		sm_fia_ann_pba[0]->hedging_defn = HEDGED;
		sm_fia_ann_pba[0]->hedging_cash_flow_defn = BEST_ESTIMATE;

		if (!sm_fia_ann_pba[0]->hedging_flag)
			continue;
		}
	else if (loop == 2) // Reserves Net Hedged Existing
		{
		if (pba_calc_defn == CAPITAL)
			continue;
		
		if (pba_reins_defn == GROSS)
			continue;
			
		if (!reins_flag)
			continue;			

		if (pba_hedging_defn == UNHEDGED)
			continue;

		res_scen_amt_valn_flag = true;
	    sm_fia_ann_pba[0]->pba_code = STOCH_RES;
		sm_fia_ann_pba[0]->res_cap_calc_defn = RESERVES;
		sm_fia_ann_pba[0]->reins_defn = NET;
		sm_fia_ann_pba[0]->hedging_defn = HEDGED;
		sm_fia_ann_pba[0]->hedging_cash_flow_defn = EXISTING;

		if (!sm_fia_ann_pba[0]->hedging_flag)
			continue;
		}
	else if (loop == 3) // Capital Net Hedged Best Estimate
		{
		if (pba_calc_defn == RESERVES)
			continue;

		if (!time_step_flag
			&& pba_reins_defn == GROSS)
			continue;

		if (pba_hedging_defn == UNHEDGED)
			continue;

		rbc_scen_amt_valn_flag = true;
	    sm_fia_ann_pba[0]->pba_code = STOCH_CAP;
		sm_fia_ann_pba[0]->res_cap_calc_defn = CAPITAL;
		sm_fia_ann_pba[0]->reins_defn = NET;
		sm_fia_ann_pba[0]->hedging_defn = HEDGED;
		sm_fia_ann_pba[0]->hedging_cash_flow_defn = BEST_ESTIMATE;
		
		if (!sm_fia_ann_pba[0]->hedging_flag)
			continue;
		}
	else if (loop == 4) // Reserves Net Unhedged
		{
		if (pba_calc_defn == CAPITAL)
			continue;
			
		if (pba_reins_defn == GROSS)
			continue;
			
		if (!reins_flag)
			continue;			

		if (pba_hedging_defn == HEDGED)
			continue;

		res_scen_amt_valn_flag = true;
	    sm_fia_ann_pba[0]->pba_code = STOCH_RES;
		sm_fia_ann_pba[0]->res_cap_calc_defn = RESERVES;
		sm_fia_ann_pba[0]->reins_defn = NET;
		sm_fia_ann_pba[0]->hedging_defn = UNHEDGED;
		}
	else if (loop == 5) // Reserves Gross Hedged Best Estimate
		{
		if (pba_calc_defn == CAPITAL)
			continue;
			
		if (pba_reins_defn == NET)
			continue;

		if (pba_hedging_defn == UNHEDGED)
			continue;

		res_scen_amt_valn_flag = true;
	    sm_fia_ann_pba[0]->pba_code = STOCH_RES;
		sm_fia_ann_pba[0]->res_cap_calc_defn = RESERVES;
		sm_fia_ann_pba[0]->reins_defn = GROSS;
		sm_fia_ann_pba[0]->hedging_defn = UNHEDGED;
		sm_fia_ann_pba[0]->hedging_cash_flow_defn = BEST_ESTIMATE;

		if (!sm_fia_ann_pba[0]->hedging_flag)
			continue;
		}
	else if (loop == 6) // Reserves Gross Hedged Existing
		{
		if (pba_calc_defn == CAPITAL)
			continue;

		if (pba_reins_defn == NET)
			continue;

		if (pba_hedging_defn == UNHEDGED)
			continue;

		res_scen_amt_valn_flag = true;
	    sm_fia_ann_pba[0]->pba_code = STOCH_RES;
		sm_fia_ann_pba[0]->res_cap_calc_defn = RESERVES;
		sm_fia_ann_pba[0]->reins_defn = GROSS;
		sm_fia_ann_pba[0]->hedging_defn = UNHEDGED;
		sm_fia_ann_pba[0]->hedging_cash_flow_defn = EXISTING;

		if (!sm_fia_ann_pba[0]->hedging_flag)
			continue;
		}
	else if (loop == 7) // Reserves Gross Unhedged
		{
		if (pba_calc_defn == CAPITAL)
			continue;

		if (pba_reins_defn == NET)
			continue;

		if (pba_hedging_defn == HEDGED)
			continue;

		res_scen_amt_valn_flag = true;
	    sm_fia_ann_pba[0]->pba_code = STOCH_RES;
		sm_fia_ann_pba[0]->res_cap_calc_defn = RESERVES;
		sm_fia_ann_pba[0]->reins_defn = GROSS;
		sm_fia_ann_pba[0]->hedging_defn = UNHEDGED;
		}
	else if (loop == 8) // Capital Net Unhedged
		{
		if (pba_calc_defn == RESERVES)
			continue;

		if (!time_step_flag
			&& pba_reins_defn == GROSS)
			continue;

		rbc_scen_amt_valn_flag = true;
	    sm_fia_ann_pba[0]->pba_code = STOCH_CAP;
		sm_fia_ann_pba[0]->res_cap_calc_defn = CAPITAL;
		sm_fia_ann_pba[0]->reins_defn = NET;
		sm_fia_ann_pba[0]->hedging_defn = UNHEDGED;
		}
	else if (loop == 9) // Capital Gross Hedged Best Estimate
		{
		// Capital gross is never required in scenario time-step projection
		if (time_step_flag)
			continue;

		if (pba_calc_defn == RESERVES)
			continue;

		if (pba_reins_defn == NET)
			continue;

		if (pba_hedging_defn == UNHEDGED)
			continue;

		rbc_scen_amt_valn_flag = true;
	    sm_fia_ann_pba[0]->pba_code = STOCH_CAP;
		sm_fia_ann_pba[0]->res_cap_calc_defn = CAPITAL;
		sm_fia_ann_pba[0]->reins_defn = GROSS;
		sm_fia_ann_pba[0]->hedging_defn = HEDGED;
		sm_fia_ann_pba[0]->hedging_cash_flow_defn = BEST_ESTIMATE;

		if (!sm_fia_ann_pba[0]->hedging_flag)
			continue;
		}
	else if (loop == 10) // Capital Gross Unhedged
		{
		// Capital gross is never required in time-step projection
		if (time_step_flag)
			continue;

		if (pba_calc_defn == RESERVES)
			continue;

		if (pba_reins_defn == NET)
			continue;

		rbc_scen_amt_valn_flag = true;
	    sm_fia_ann_pba[0]->pba_code = STOCH_CAP;
		sm_fia_ann_pba[0]->res_cap_calc_defn = CAPITAL;
		sm_fia_ann_pba[0]->reins_defn = GROSS;
		sm_fia_ann_pba[0]->hedging_defn = UNHEDGED;

		}

	xstring group_name = mp_id
		                 + "|"
				    	 + sm_fia_ann_pba[0]->res_cap_calc_defn
		                 + "|" 
		                 + sm_fia_ann_pba[0]->reins_defn
		                 + "|"
		                 + sm_fia_ann_pba[0]->hedging_defn;

	if (sm_fia_ann_pba[0]->hedging_defn == HEDGED)
		group_name = group_name + "|" + sm_fia_ann_pba[0]->hedging_cash_flow_defn;

	sm_fia_ann_pba[0]->write_valuation_output(group_name);
	sm_fia_ann_pba[0]->rebaseModel(0);
	}

// restore pba definitions
sm_fia_ann_pba[0]->res_cap_calc_defn = pba_calc_defn;
sm_fia_ann_pba[0]->reins_defn = pba_reins_defn;
sm_fia_ann_pba[0]->hedging_defn = pba_hedging_defn;

rbc_scen_amt_valn_flag = false;
res_scen_amt_valn_flag = false;
pba_scen_amt_valn_flag = false;
pba_valn_flag = false;

return 1.0;
#else
return 0.0;
#endif

}

//@@ END

//@@ START - valn_tgt_stat_tax
// Valuation Target - Stat and Tax Reserves                                                                                             
// Column:VALN_TGT_STAT_TAX
//========================================================
double FIA_LIAB_UDF::fia_liab_valn_tgt_stat_tax(int t) {
//^^^



//^^^

#line 1 "valn_tgt_stat_tax.FIA_LIAB.for"
if (!valn_flag)
	return NO_AVG;

if (t != 0)
	return NO_AVG;

stat_res(t);
tax_res(t);

if (audit_detail_flag)
	{
	xstring output_name = "";
	xstring output_file_name = replaceWildcards(output_location());
	output_file_name = xstring(output_file_name(0 , output_file_name.find_first_of("~")));

	stat_audit_detail_rpt_id
	= output_file_name
	  + "_StatAuditDetail_" + mp_id + ".csv";

	StatAuditFile.open((xstring)stat_audit_detail_rpt_id);
	StatAuditFile.setf(ios::fixed, ios::floatfield);
	StatAuditFile.precision(12);

	if (!StatAuditFile)
		throw ("Cannot open audit detail report file = " + stat_audit_detail_rpt_id
				+ ". Check that the directory has been created and that you have permission to write it.");
	else
		StatAuditFile << "Statutory Audit Report for Fixed Index Annuity Policy Number " << mp_id << ": "
				<< output_location() << endl;

	StatAuditFile << endl
			<< "Valuation date," << proj_date << endl
			<< "Policy data" << endl
			<< "Policy number," << mp_id << endl
			<< "Plan code," << plan_code << endl
			<< "Issue date," << issue_date << endl
			<< "Policy year," << pol_yr(0) << endl
			<< "Policy month," << pol_mth(0) << endl
			<< "Issue age," << issue_age_mp << endl
			<< "Gender," << gender_mp << endl
			<< "Valn code," << stat_valn_code << endl
			<< "Base res defn," << stat_res_defn << endl
			<< "Maturity age," << maturity_age << endl;

	if (stat_res_defn == CARVM)
		{
		StatAuditFile 
			//<< "Months in first period," << sm_carvm_stat[0]->mths_in_first_period << endl
			<< "Male sex pct," << male_sex_pct << endl
			<< "Fund value," << fund_val_fixed(0) <<endl
			<< "PFW entitlement," << pfwd_entitlement(0) <<endl
			<< "PFW amount defn," << pfwd_amt_avail_defn << endl;	
		}


	output_name = "";
	output_file_name = replaceWildcards(output_location());
	output_file_name = xstring(output_file_name(0 , output_file_name.find_first_of("~")));

	tax_audit_detail_rpt_id
	= output_file_name
	  + "_TaxAuditDetail_" + mp_id + ".csv";

	TaxAuditFile.open((xstring)tax_audit_detail_rpt_id);
	TaxAuditFile.setf(ios::fixed, ios::floatfield);
	TaxAuditFile.precision(12);

	if (!TaxAuditFile)
		throw ("Cannot open audit detail report file = " + tax_audit_detail_rpt_id
				+ ". Check that the directory has been created and that you have permission to write it.");
	else
		TaxAuditFile << "Tax Audit Report for Fixed Annuity Policy Number " << mp_id << ": "
				<< output_location() << endl;

	if (tax_res_defn == TAX_EQUALS_STAT || tax_res_defn == _2017_TAX_REFORM)
		TaxAuditFile << endl << "Please refer to Statutory Audit Report" << endl;
	else
		{
		TaxAuditFile << endl
			<< "Valuation date," << proj_date << endl
			<< "Policy data" << endl
			<< "Policy number," << mp_id << endl
			<< "Plan code," << plan_code << endl
			<< "Issue date," << issue_date << endl
			<< "Policy year," << pol_yr(0) << endl
			<< "Policy month," << pol_mth(0) << endl
			<< "Issue age," << issue_age_mp << endl
			<< "Gender," << gender_mp << endl
			<< "Valn code," << tax_valn_code << endl
			<< "Base res defn," << tax_res_defn << endl
			<< "Maturity age," << maturity_age << endl;

		if (tax_res_defn == CARVM)	
			TaxAuditFile
				//<< "Months in first period," << sm_carvm_tax[0]->mths_in_first_period << endl
				<< "Male sex pct," << male_sex_pct << endl
				<< "Fund value," << fund_val_fixed(0) <<endl
				<< "PFW entitlement," << pfwd_entitlement(0) <<endl
				<< "PFW amount defn," << pfwd_amt_avail_defn << endl;
		}
	}

/*
if (audit_detail_flag)
	{
	if (stat_res_defn == PERCENT_FUND_VALUE)
		StatAuditFile << endl << "BASIC RESERVE," << endl
				<< "Fund value," << fund_val_fixed(0) << endl
				<< "Stat res pct," << stat_res_pct << endl
				<< "Stat res carvm," << stat_res_carvm_base(0) << endl;

	if (stat_res_defn == PERCENT_CASH_VALUE)
		StatAuditFile << endl << "BASIC RESERVE," << endl
				<< "Cash value," << cash_val(0) << endl
				<< "Stat res pct," << stat_res_pct << endl
				<< "Stat res carvm," << stat_res_carvm_base(0) << endl;
	
	double carvm_int_rate_elect;
	double carvm_int_rate_non_elect;

	if (stat_res_defn == "CARVM")
		{
		StatAuditFile << endl << "Life data" << endl
				<< "Period,Attained age,Carvm mort base life 1,Carvm mort mult life 1,Gmwb mort base life 1,Carvm NH incid base life 1,"
				<< "Carvm mort base life 2,Carvm mort mult life 2,Gmwb mort base life 2,Carvm NH incid base life 2,"
				<< "Sex pct,Carvm mort rate final,Gmwb mort rate final,NH incid rate final" << endl;

		for (int time = 1; time <= sm_carvm_stat[0]->max_calc_period; time++)
			{
			sm_carvm_stat[0]->mort_issue_age = sm_carvm_stat[0]->issue_age;
			sm_carvm_stat[0]->mort_attained_age = sm_carvm_stat[0]->attained_age(time);
			sm_carvm_stat[0]->mort_pol_yr = sm_carvm_stat[0]->pol_yr(time);
			sm_carvm_stat[0]->mort_gender = xstring(sm_carvm_stat[0]->gender);

			StatAuditFile << time << "," //placeholder for intermediate mortality inputs
				<< sm_carvm_stat[0]->attained_age(time) << ",";

			if (gender_mp == "Blended")
				sm_carvm_stat[0]->mort_gender = MALE;

			StatAuditFile << sm_carvm_stat[0]->carvm_mort_base << ","				
				<< sm_carvm_stat[0]->carvm_mort_mult << ","
				<< sm_carvm_stat[0]->gmwb_mort_base << ",";

			if (sm_carvm_stat[0]->include_nh_defn == YES && sm_carvm_stat[0]->surr_chg_pct(time) > model_point_amount_threshold && sm_carvm_stat[0]->csv_e(time) > model_point_amount_threshold)
				StatAuditFile << sm_carvm_stat[0]->nh_incid_base << ",";
			else
				StatAuditFile << 0 << ",";

			if (gender_mp == "Blended")
				sm_carvm_stat[0]->mort_gender = FEMALE;

			StatAuditFile << sm_carvm_stat[0]->carvm_mort_base << ","
				<< sm_carvm_stat[0]->carvm_mort_mult << ","
				<< sm_carvm_stat[0]->gmwb_mort_base << ",";

			if (sm_carvm_stat[0]->include_nh_defn == YES && sm_carvm_stat[0]->surr_chg_pct(time) > model_point_amount_threshold && sm_carvm_stat[0]->csv_e(time) > model_point_amount_threshold)
				StatAuditFile << sm_carvm_stat[0]->nh_incid_base << ",";
			else
				StatAuditFile << 0 << ",";

			StatAuditFile << male_sex_pct << ","
				<< sm_carvm_stat[0]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE) << ","
				<< sm_carvm_stat[0]->dth_claim_rate_calc(time,pol_yr(time),GMWB) << ","
				<< sm_carvm_stat[0]->nh_incid_rate(time) << endl;
			}

		StatAuditFile << endl << "--------------------------------------------------------NO FPW CARVM RESERVE"
				<< "--------------------------------------------------------" << endl
				<< "Period,Fund val BOP,GMWB Withdrawals,Accum option pct,GMWB charge,"
				<< "Fund val bef PFWD,Contract val bef PFWD,PFWD pct,PFWD entitlement,PFWD surrender,"
				<< "Fund val aft PFWD,Surrender chg pct,Surrender chg,Guaranteed min contract val,"
				<< "Cash val" << endl;

		for (int time = 0; time <= sm_carvm_stat[0]->max_calc_period; time++)
			{
			if (time == 0)
				StatAuditFile << time << endl;
			else
				{
				StatAuditFile << time << ","
					<< sm_carvm_stat[0]->fund_val_aft_pfwd(time - 1) << ","
					<< sm_carvm_stat[0]->gmwb_wd(time) << ",";

				if (sm_carvm_stat[0]->fund_val_aft_pfwd(time - 1) < model_point_amount_threshold)
					StatAuditFile << 0 << ",";
				else
					StatAuditFile << (sm_carvm_stat[0]->fund_val_bef_pfwd(time) + sm_carvm_stat[0]->gmwb_chg(time))
								   / (sm_carvm_stat[0]->fund_val_aft_pfwd(time - 1) - sm_carvm_stat[0]->gmwb_wd(time)) << ",";
				
				StatAuditFile << sm_carvm_stat[0]->gmwb_chg(time) << ","
					<< sm_carvm_stat[0]->fund_val_bef_pfwd(time) << ","					
					<< sm_carvm_stat[0]->contract_val_bef_pfwd(time) << ","
					<< pfwd_pct << ","
					<< sm_carvm_stat[0]->pfwd_entitlement(time) << ","
					<< sm_carvm_stat[0]->pfwd_surr(time) << ","
					<< sm_carvm_stat[0]->fund_val_aft_pfwd(time) << ","
					<< sm_carvm_stat[0]->surr_chg_pct(time) << ","
					<< sm_carvm_stat[0]->surr_chg(time) << ","					
					<< sm_carvm_stat[0]->guar_min_contract_val(time) << ","
					<< sm_carvm_stat[0]->csv_e(time) << endl;
				}			
			}

		StatAuditFile << endl 
				<< "Period,Res integrated,GMWB reserve,Res other,PV dth benefit,PV NH benefit,PV PFWD surrender,PV cash val,"
				<< "Fund val bef PFWD,Contract val bef PFWD,Dth claim rate,Surv factor,Carvm int rate non-elect,Carvm dth ben disc factor,Dth ben current period,PV dth benefit,"
				<< "NH ben inf bef PFWD,NH incidence rate,NH ben current period,PV NH benefit,"
				<< "PFWD surrender,Surv factor,Carvm int rate elect,Carvm disc factor,PFWD current,PV PFWD surrender,"
				<< "Cash val,Surv factor,Carvm int rate elect,Carvm disc factor,PV cash val," 
				<< "Fund val bef PFWD,Dth claim rate GMWB,Surv GMWB,Carvm int rate non-elect,Carvm dth ben disc factor,Dth ben GMWB,PV GMWB death ben,"
				<< "Fund val bef PFWD,GMWB wdls,Surv GMWB,Carvm int rate non-elect,Carvm ann ben disc factor,Withdrawal non elect,PV withdrawal non elective,"
				<< "Carvm int rate elect,Carvm wdl disc factor,Withdrawal elect,PV withdrawal elective,GMWB reserve"<<endl;

		for (int time = 0; time <= sm_carvm_stat[0]->max_calc_period; time++)
			{
			
			sm_carvm_stat[0]->valn_carvm_defn = stat_carvm_defn;
            sm_carvm_stat[0]->valn_cash_settle_defn = valn_rate_cash_settle_defn;
			sm_carvm_stat[0]->valn_int_guar_defn = valn_rate_int_guar_defn;
            sm_carvm_stat[0]->valn_guar_dur = sm_carvm_stat[0]->int_guar_dur;
		    sm_carvm_stat[0]->valn_plan_type = valn_rate_plan_type_elective_cash_val;

			carvm_int_rate_elect = sm_carvm_stat[0]->carvm_int_rate;


			sm_carvm_stat[0]->valn_carvm_defn = stat_carvm_defn;
            sm_carvm_stat[0]->valn_cash_settle_defn = valn_rate_cash_settle_defn;
			sm_carvm_stat[0]->valn_int_guar_defn = valn_rate_int_guar_defn;
            sm_carvm_stat[0]->valn_guar_dur = sm_carvm_stat[0]->int_guar_dur;
			sm_carvm_stat[0]->valn_plan_type = valn_rate_plan_type_non_elective;
			carvm_int_rate_non_elect = sm_carvm_stat[0]->carvm_int_rate;

		
			if (time == 0)
				StatAuditFile << time << ","
					<< sm_carvm_stat[0]->res_integrated(0) << ","
					<< sm_carvm_stat[0]->res_gmwb(0) << ","
					<< sm_carvm_stat[0]->res_other(0)<< ",,,,"
					<< sm_carvm_stat[0]->csv_e_pv(0) << ",,,,"
					<< sm_carvm_stat[0]->surv(0) << ",,,,,,,,,,"
					<< sm_carvm_stat[0]->surv(0) << ",,,,,"
					<< sm_carvm_stat[0]->csv_e(0) << ","
					<< sm_carvm_stat[0]->surv(0) << ",,"
					<< sm_carvm_stat[0]->carvm_disc_factor_elect_cash_val(0) << "," 
					<< sm_carvm_stat[0]->csv_e_pv(0) << ",,,"
					<< sm_carvm_stat[0]->gmwb_surv(0) << ",,,,,,,"
					<< sm_carvm_stat[0]->gmwb_surv(0) << ",,"
					<< sm_carvm_stat[0]->carvm_disc_factor_non_elect(0) << ",,,,"
					<< sm_carvm_stat[0]->carvm_disc_factor_elect_cash_val(0) << endl; 
			else
				{
				StatAuditFile << time << ","
					<< sm_carvm_stat[0]->res_integrated(time) << ","
					<< sm_carvm_stat[0]->res_gmwb(0) << ","
					<< sm_carvm_stat[0]->res_other(time) << ","
					<< sm_carvm_stat[0]->dth_benefits_pv(time) << ","
					<< sm_carvm_stat[0]->nh_benefits_pv(time) << ","
					<< sm_carvm_stat[0]->pfwd_surr_pv(time) << ","
					<< sm_carvm_stat[0]->csv_e_pv(time) << ","
					<< sm_carvm_stat[0]->fund_val_bef_pfwd(time) << ","
					<< sm_carvm_stat[0]->contract_val_bef_pfwd(time) << ","
					<< sm_carvm_stat[0]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE) << ","
					<< sm_carvm_stat[0]->surv(time) << ","
					<< carvm_int_rate_non_elect << ","					
					<< sm_carvm_stat[0]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_stat[0]->dth_benefits(time) * sm_carvm_stat[0]->carvm_disc_factor_non_elect(time) <<","
					<< sm_carvm_stat[0]->dth_benefits_pv(time) << ",";

				if (sm_carvm_stat[0]->include_nh_defn == YES && sm_carvm_stat[0]->surr_chg_pct(time) > model_point_amount_threshold && sm_carvm_stat[0]->csv_e(time) > model_point_amount_threshold)
					StatAuditFile << sm_carvm_stat[0]->fund_val_bef_pfwd(time) << ",";
				else
					StatAuditFile << 0 << ",";

				StatAuditFile << sm_carvm_stat[0]->nh_incid_rate(time) << ","
					<< sm_carvm_stat[0]->fund_val_bef_pfwd(time) 
							* sm_carvm_stat[0]->nh_incid_rate(time)
							* (1.0 - sm_carvm_stat[0]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE))
							* sm_carvm_stat[0]->surv(time - 1) 
							* sm_carvm_stat[0]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_stat[0]->nh_benefits_pv(time) << ","
					<< sm_carvm_stat[0]->pfwd_surr(time) << ","	
					<< sm_carvm_stat[0]->surv(time) << ","
					<< carvm_int_rate_elect << ","
					<< sm_carvm_stat[0]->carvm_disc_factor_elect_cash_val(time) << "," 
					<< sm_carvm_stat[0]->pfwd_surr(time) 
							* sm_carvm_stat[0]->surv(time) 
							* sm_carvm_stat[0]->carvm_disc_factor_elect_cash_val(time) <<","
					<< sm_carvm_stat[0]->pfwd_surr_pv(time) << ","
					<< sm_carvm_stat[0]->csv_e(time) << ","
					<< sm_carvm_stat[0]->surv(time) << ","
					<< carvm_int_rate_elect << ","
					<< sm_carvm_stat[0]->carvm_disc_factor_elect_cash_val(time) << "," 
					<< sm_carvm_stat[0]->csv_e_pv(time) << ","
					<< sm_carvm_stat[0]->fund_val_bef_pfwd(time) << ","
					<< sm_carvm_stat[0]->dth_claim_rate_calc(time,pol_yr(time),GMWB) << ","
					<< sm_carvm_stat[0]->gmwb_surv(time) << ","
					<< carvm_int_rate_non_elect << ","
					<< sm_carvm_stat[0]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_stat[0]->gmwb_dth_benefits(time) << ","
					<< sm_carvm_stat[0]->gmwb_dth_benefits_pv(time) << ","
					<< sm_carvm_stat[0]->fund_val_bef_pfwd(time) << ","
					<< sm_carvm_stat[0]->gmwb_wd(time) << ","
					<< sm_carvm_stat[0]->gmwb_surv(time) << ","
					<< carvm_int_rate_non_elect << ","
					<< sm_carvm_stat[0]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_stat[0]->withdrl_non_elective(time) << ","
					<< sm_carvm_stat[0]->withdrl_non_elective_pv(time) << ","
					<< carvm_int_rate_elect << ","
					<< sm_carvm_stat[0]->carvm_disc_factor_elect_cash_val(time) << ","
					<< sm_carvm_stat[0]->withdrl_elective(time) << ","
					<< sm_carvm_stat[0]->withdrl_elective_pv(time) << ","
					<< sm_carvm_stat[0]->res_gmwb(time) << endl;
				}
			}
	
		StatAuditFile << endl << "--------------------------------------------------------FULL FPW CARVM RESERVE"
					<< "--------------------------------------------------------" << endl
					<< "Period,Fund val BOP,GMWB Withdrawals,Accum option pct,GMWB charge,"
					<< "Fund val bef PFWD,Contract val bef PFWD,PFWD pct,PFWD entitlement,PFWD surrender,"
					<< "Fund val aft PFWD,Surrender chg pct,Surrender chg,Guaranteed min contract val,"
					<< "Cash val" << endl;

		for (int time = 0; time <= sm_carvm_stat[1]->max_calc_period; time++)
				{
				if (time == 0)
					StatAuditFile << time << endl;
				else
					{
					StatAuditFile << time << ","
						<< sm_carvm_stat[1]->fund_val_aft_pfwd(time - 1) << ","
						<< sm_carvm_stat[1]->gmwb_wd(time) << ",";

					if (sm_carvm_stat[1]->fund_val_aft_pfwd(time - 1) < model_point_amount_threshold)
						StatAuditFile << 0 << ",";
					else
						StatAuditFile << (sm_carvm_stat[1]->fund_val_bef_pfwd(time) + sm_carvm_stat[1]->gmwb_chg(time))
									   / (sm_carvm_stat[1]->fund_val_aft_pfwd(time - 1) - sm_carvm_stat[1]->gmwb_wd(time)) << ",";
				
					StatAuditFile << sm_carvm_stat[1]->gmwb_chg(time) << ","
						<< sm_carvm_stat[1]->fund_val_bef_pfwd(time) << ","					
						<< sm_carvm_stat[1]->contract_val_bef_pfwd(time) << ","
						<< pfwd_pct << ","
						<< sm_carvm_stat[1]->pfwd_entitlement(time) << ","
						<< sm_carvm_stat[1]->pfwd_surr(time) << ","
						<< sm_carvm_stat[1]->fund_val_aft_pfwd(time) << ","
						<< sm_carvm_stat[1]->surr_chg_pct(time) << ","
						<< sm_carvm_stat[1]->surr_chg(time) << ","					
						<< sm_carvm_stat[1]->guar_min_contract_val(time) << ","
						<< sm_carvm_stat[1]->csv_e(time) << endl;
					}				
				}
		
		StatAuditFile << endl 
				<< "Period,Res integrated,GMWB reserve,Res other,PV dth benefit,PV NH benefit,PV PFWD surrender,PV cash val,"
				<< "Fund val bef PFWD,Contract val bef PFWD,Dth claim rate,Surv factor,Carvm int rate non-elect,Carvm dth ben disc factor,Dth ben current period,PV dth benefit,"
				<< "NH ben inf bef PFWD,NH incidence rate,NH ben current period,PV NH benefit,"
				<< "PFWD surrender,Surv factor,Carvm int rate elect,Carvm disc factor,PFWD current,PV PFWD surrender,"
				<< "Cash val,Surv factor,Carvm int rate elect,Carvm disc factor,PV cash val," 
				<< "Fund val bef PFWD,Dth claim rate GMWB,Surv GMWB,Carvm int rate non-elect,Carvm dth ben disc factor,Dth ben GMWB,PV GMWB death ben,"
				<< "Fund val bef PFWD,GMWB wdls,Surv GMWB,Carvm int rate non-elect,Carvm ann ben disc factor,Withdrawal non elect,PV withdrawal non elective,"
				<< "Carvm int rate elect,Carvm wdl disc factor,Withdrawal elect,PV withdrawal elective,GMWB reserve"<<endl;

		for (int time = 0; time <= sm_carvm_stat[1]->max_calc_period; time++)
			{
			
			sm_carvm_stat[1]->valn_carvm_defn = stat_carvm_defn;
            sm_carvm_stat[1]->valn_cash_settle_defn = valn_rate_cash_settle_defn;
            sm_carvm_stat[1]->valn_int_guar_defn = valn_rate_int_guar_defn;
            sm_carvm_stat[1]->valn_guar_dur = sm_carvm_stat[1]->int_guar_dur;			
			sm_carvm_stat[1]->valn_plan_type = valn_rate_plan_type_elective_cash_val;

			carvm_int_rate_elect = sm_carvm_stat[1]->carvm_int_rate;

			sm_carvm_stat[1]->valn_carvm_defn = stat_carvm_defn;
            sm_carvm_stat[1]->valn_cash_settle_defn = valn_rate_cash_settle_defn;
            sm_carvm_stat[1]->valn_int_guar_defn = valn_rate_int_guar_defn;
            sm_carvm_stat[1]->valn_guar_dur = sm_carvm_stat[1]->int_guar_dur;
			sm_carvm_stat[1]->valn_plan_type = valn_rate_plan_type_non_elective;

			carvm_int_rate_non_elect = sm_carvm_stat[1]->carvm_int_rate;

			if (time == 0)
				StatAuditFile << time << ","
					<< sm_carvm_stat[1]->res_integrated(0) << ","
					<< sm_carvm_stat[1]->res_gmwb(0) << ","
					<< sm_carvm_stat[1]->res_other(0) << ",,,,"
					<< sm_carvm_stat[1]->csv_e_pv(0) << ",,,,"
					<< sm_carvm_stat[1]->surv(0) << ",,,,,,,,,,"
					<< sm_carvm_stat[1]->surv(0) << ",,,,,"
					<< sm_carvm_stat[1]->csv_e(0) << ","
					<< sm_carvm_stat[1]->surv(0) << ",,"
					<< sm_carvm_stat[1]->carvm_disc_factor_elect_cash_val(0) << ","
					<< sm_carvm_stat[1]->csv_e_pv(0) << ",,,"
					<< sm_carvm_stat[1]->gmwb_surv(0) << ",,,,,,,"
					<< sm_carvm_stat[1]->gmwb_surv(0) << ",,"
					<< sm_carvm_stat[1]->carvm_disc_factor_non_elect(0) << ",,,,"
					<< sm_carvm_stat[1]->carvm_disc_factor_elect_cash_val(0) << endl;
			else
				{
				StatAuditFile << time << ","
					<< sm_carvm_stat[1]->res_integrated(time) << ","
					<< sm_carvm_stat[1]->res_gmwb(0) << ","
					<< sm_carvm_stat[1]->res_other(time) << ","
					<< sm_carvm_stat[1]->dth_benefits_pv(time) << ","
					<< sm_carvm_stat[1]->nh_benefits_pv(time) << ","
					<< sm_carvm_stat[1]->pfwd_surr_pv(time) << ","
					<< sm_carvm_stat[1]->csv_e_pv(time) << ","
					<< sm_carvm_stat[1]->fund_val_bef_pfwd(time) << ","
					<< sm_carvm_stat[1]->contract_val_bef_pfwd(time) << ","
					<< sm_carvm_stat[1]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE) << ","
					<< sm_carvm_stat[1]->surv(time) << ","
					<< carvm_int_rate_non_elect << ","					
					<< sm_carvm_stat[1]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_stat[1]->dth_benefits(time) * sm_carvm_stat[1]->carvm_disc_factor_non_elect(time) <<","
					<< sm_carvm_stat[1]->dth_benefits_pv(time) << ",";

				if (sm_carvm_stat[1]->include_nh_defn == YES && sm_carvm_stat[1]->surr_chg_pct(time) > model_point_amount_threshold && sm_carvm_stat[1]->csv_e(time) > model_point_amount_threshold)
					StatAuditFile << sm_carvm_stat[1]->fund_val_bef_pfwd(time) << ",";
				else
					StatAuditFile << 0 << ",";

				StatAuditFile << sm_carvm_stat[1]->nh_incid_rate(time) << ","
					<< sm_carvm_stat[1]->fund_val_bef_pfwd(time) 
							* sm_carvm_stat[1]->nh_incid_rate(time)
							* (1.0 - sm_carvm_stat[1]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE))
							* sm_carvm_stat[1]->surv(time - 1) 
							* sm_carvm_stat[1]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_stat[1]->nh_benefits_pv(time) << ","
					<< sm_carvm_stat[1]->pfwd_surr(time) << ","	
					<< sm_carvm_stat[1]->surv(time) << ","
					<< carvm_int_rate_elect << ","
					<< sm_carvm_stat[1]->carvm_disc_factor_elect_cash_val(time) << ","
					<< sm_carvm_stat[1]->pfwd_surr(time) 
							* sm_carvm_stat[1]->surv(time) 
							* sm_carvm_stat[1]->carvm_disc_factor_elect_cash_val(time) <<","
					<< sm_carvm_stat[1]->pfwd_surr_pv(time) << ","
					<< sm_carvm_stat[1]->csv_e(time) << ","
					<< sm_carvm_stat[1]->surv(time) << ","
					<< carvm_int_rate_elect << ","
					<< sm_carvm_stat[1]->carvm_disc_factor_elect_cash_val(time) << ","
					<< sm_carvm_stat[1]->csv_e_pv(time) << ","
					<< sm_carvm_stat[1]->fund_val_bef_pfwd(time) << ","
					<< sm_carvm_stat[1]->dth_claim_rate_calc(time,pol_yr(time),GMWB) << ","
					<< sm_carvm_stat[1]->gmwb_surv(time) << ","
					<< carvm_int_rate_non_elect << ","
					<< sm_carvm_stat[1]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_stat[1]->gmwb_dth_benefits(time) << ","
					<< sm_carvm_stat[1]->gmwb_dth_benefits_pv(time) << ","
					<< sm_carvm_stat[1]->fund_val_bef_pfwd(time) << ","
					<< sm_carvm_stat[1]->gmwb_wd(time) << ","
					<< sm_carvm_stat[1]->gmwb_surv(time) << ","
					<< carvm_int_rate_non_elect << ","
					<< sm_carvm_stat[1]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_stat[1]->withdrl_non_elective(time) << ","
					<< sm_carvm_stat[1]->withdrl_non_elective_pv(time) << ","
					<< carvm_int_rate_elect << ","
					<< sm_carvm_stat[1]->carvm_disc_factor_elect_cash_val(time) << ","
					<< sm_carvm_stat[1]->withdrl_elective(time) << ","
					<< sm_carvm_stat[1]->withdrl_elective_pv(time) << ","
					<< sm_carvm_stat[1]->res_gmwb(time) << endl;
				}
			}

		for (int count = 2; count <sm_carvm_stat.size(); count++)
			{
			StatAuditFile << endl << "--------------------------------------------------------GMWB CARVM RESERVE Exercise Point"
					<< sm_carvm_stat[count]->gmwb_exercise_point
					<< "--------------------------------------------------------" << endl
					<< "Period,Fund val BOP,GMWB Withdrawals,Accum option pct,GMWB charge,"
					<< "Fund val bef PFWD,Contract val bef PFWD,PFWD pct,PFWD entitlement,PFWD surrender,"
					<< "Fund val aft PFWD,Surrender chg pct,Surrender chg,Guaranteed min contract val,"
					<< "Cash val" << endl;

			for (int time = 0; time <= sm_carvm_stat[count]->max_calc_period; time++)
				{
				if (time == 0)
					StatAuditFile << time << endl;
				else
					{
					StatAuditFile << time << ","
						<< sm_carvm_stat[count]->fund_val_aft_pfwd(time - 1) << ","
						<< sm_carvm_stat[count]->gmwb_wd(time) << ",";

					if (sm_carvm_stat[count]->fund_val_aft_pfwd(time - 1) < model_point_amount_threshold)
						StatAuditFile << 0 << ",";
					else
						StatAuditFile << (sm_carvm_stat[count]->fund_val_bef_pfwd(time) + sm_carvm_stat[count]->gmwb_chg(time))
									   / (sm_carvm_stat[count]->fund_val_aft_pfwd(time - 1) - sm_carvm_stat[count]->gmwb_wd(time)) << ",";
				
					StatAuditFile << sm_carvm_stat[count]->gmwb_chg(time) << ","
						<< sm_carvm_stat[count]->fund_val_bef_pfwd(time) << ","					
						<< sm_carvm_stat[count]->contract_val_bef_pfwd(time) << ","
						<< pfwd_pct << ","
						<< sm_carvm_stat[count]->pfwd_entitlement(time) << ","
						<< sm_carvm_stat[count]->pfwd_surr(time) << ","
						<< sm_carvm_stat[count]->fund_val_aft_pfwd(time) << ","
						<< sm_carvm_stat[count]->surr_chg_pct(time) << ","
						<< sm_carvm_stat[count]->surr_chg(time) << ","					
						<< sm_carvm_stat[count]->guar_min_contract_val(time) << ","
						<< sm_carvm_stat[count]->csv_e(time) << endl;
					}					
				}
		
				StatAuditFile << endl 
					<< "Period,Res integrated,GMWB reserve,Res other,PV dth benefit,PV NH benefit,PV PFWD surrender,PV cash val,"
					<< "Fund val bef PFWD,Contract val bef PFWD,Dth claim rate,Surv factor,Carvm int rate non-elect,Carvm dth ben disc factor,Dth ben current period,PV dth benefit,"
					<< "NH ben inf bef PFWD,NH incidence rate,NH ben current period,PV NH benefit,"
					<< "PFWD surrender,Surv factor,Carvm int rate elect,Carvm disc factor,PFWD current,PV PFWD surrender,"
					<< "Cash val,Surv factor,Carvm int rate elect,Carvm disc factor,PV cash val," 
					<< "Fund val bef PFWD,Dth claim rate GMWB,Surv GMWB,Carvm int rate non-elect,Carvm dth ben disc factor,Dth ben GMWB,PV GMWB death ben,"
					<< "Fund val bef PFWD,GMWB wdls,Surv GMWB,Carvm int rate non-elect,Carvm ann ben disc factor,Withdrawal non elect,PV withdrawal non elective,"
					<< "Carvm int rate elect,Carvm wdl disc factor,Withdrawal elect,PV withdrawal elective,GMWB reserve"<<endl;

				for (int time = 0; time <= sm_carvm_stat[count]->max_calc_period; time++)
					{

					sm_carvm_stat[count]->valn_carvm_defn = stat_carvm_defn;
                    sm_carvm_stat[count]->valn_cash_settle_defn = valn_rate_cash_settle_defn;
                    sm_carvm_stat[count]->valn_int_guar_defn = valn_rate_int_guar_defn;
                    sm_carvm_stat[count]->valn_guar_dur = sm_carvm_stat[count]->int_guar_dur;	
					sm_carvm_stat[count]->valn_plan_type = valn_rate_plan_type_elective_cash_val;

					carvm_int_rate_elect = sm_carvm_stat[count]->carvm_int_rate;

					sm_carvm_stat[count]->valn_carvm_defn = stat_carvm_defn;
                    sm_carvm_stat[count]->valn_cash_settle_defn = valn_rate_cash_settle_defn;
                    sm_carvm_stat[count]->valn_int_guar_defn = valn_rate_int_guar_defn;
                    sm_carvm_stat[count]->valn_guar_dur = sm_carvm_stat[count]->int_guar_dur;
					sm_carvm_stat[count]->valn_plan_type = valn_rate_plan_type_non_elective;

					carvm_int_rate_non_elect = sm_carvm_stat[count]->carvm_int_rate;

					if (time == 0)
						StatAuditFile << time << ","
							<< sm_carvm_stat[count]->res_integrated(0) << ","
							<< sm_carvm_stat[count]->res_gmwb(0) << ","
							<< sm_carvm_stat[count]->res_other(0) << ",,,,"
							<< sm_carvm_stat[count]->csv_e_pv(0) << ",,,,"
							<< sm_carvm_stat[count]->surv(0) << ",,,,,,,,,,"
							<< sm_carvm_stat[count]->surv(0) << ",,,,,"
							<< sm_carvm_stat[count]->csv_e(0) << ","
							<< sm_carvm_stat[count]->surv(0) << ",,"
							<< sm_carvm_stat[count]->carvm_disc_factor_elect_cash_val(0) << ","
							<< sm_carvm_stat[count]->csv_e_pv(0) << ",,,"
							<< sm_carvm_stat[count]->gmwb_surv(0) << ",,,,,,,"
							<< sm_carvm_stat[count]->gmwb_surv(0) << ",,"
							<< sm_carvm_stat[count]->carvm_disc_factor_non_elect(0) << ",,,,"
							<< sm_carvm_stat[count]->carvm_disc_factor_elect_cash_val(0) << endl;
					else
						{
						StatAuditFile << time << ","
							<< sm_carvm_stat[count]->res_integrated(time) << ","
							<< sm_carvm_stat[count]->res_gmwb(0) << ","
							<< sm_carvm_stat[count]->res_other(time) << ","
							<< sm_carvm_stat[count]->dth_benefits_pv(time) << ","
							<< sm_carvm_stat[count]->nh_benefits_pv(time) << ","
							<< sm_carvm_stat[count]->pfwd_surr_pv(time) << ","
							<< sm_carvm_stat[count]->csv_e_pv(time) << ","
							<< sm_carvm_stat[count]->fund_val_bef_pfwd(time) << ","
							<< sm_carvm_stat[count]->contract_val_bef_pfwd(time) << ","
							<< sm_carvm_stat[count]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE) << ","
							<< sm_carvm_stat[count]->surv(time) << ","
							<< carvm_int_rate_non_elect << ","					
							<< sm_carvm_stat[count]->carvm_disc_factor_non_elect(time) << ","
							<< sm_carvm_stat[count]->dth_benefits(time) * sm_carvm_stat[count]->carvm_disc_factor_non_elect(time) <<","
							<< sm_carvm_stat[count]->dth_benefits_pv(time) << ",";

						if (sm_carvm_stat[count]->include_nh_defn == YES && sm_carvm_stat[count]->surr_chg_pct(time) > model_point_amount_threshold && sm_carvm_stat[count]->csv_e(time) > model_point_amount_threshold)
							StatAuditFile << sm_carvm_stat[count]->fund_val_bef_pfwd(time) << ",";
						else
							StatAuditFile << 0 << ",";

						StatAuditFile << sm_carvm_stat[count]->nh_incid_rate(time) << ","
							<< sm_carvm_stat[count]->fund_val_bef_pfwd(time) 
									* sm_carvm_stat[count]->nh_incid_rate(time)
									* (1.0 - sm_carvm_stat[count]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE))
									* sm_carvm_stat[count]->surv(time - 1) 
									* sm_carvm_stat[count]->carvm_disc_factor_non_elect(time) << ","
							<< sm_carvm_stat[count]->nh_benefits_pv(time) << ","
							<< sm_carvm_stat[count]->pfwd_surr(time) << ","	
							<< sm_carvm_stat[count]->surv(time) << ","
							<< carvm_int_rate_elect << ","
							<< sm_carvm_stat[count]->carvm_disc_factor_elect_cash_val(time) << ","
							<< sm_carvm_stat[count]->pfwd_surr(time) 
									* sm_carvm_stat[count]->surv(time) 
									* sm_carvm_stat[count]->carvm_disc_factor_elect_cash_val(time) <<","
							<< sm_carvm_stat[count]->pfwd_surr_pv(time) << ","
							<< sm_carvm_stat[count]->csv_e(time) << ","
							<< sm_carvm_stat[count]->surv(time) << ","
							<< carvm_int_rate_elect << ","
							<< sm_carvm_stat[count]->carvm_disc_factor_elect_cash_val(time) << ","
							<< sm_carvm_stat[count]->csv_e_pv(time) << ","
							<< sm_carvm_stat[count]->fund_val_bef_pfwd(time) << ","
							<< sm_carvm_stat[count]->dth_claim_rate_calc(time,pol_yr(time),GMWB) << ","
							<< sm_carvm_stat[count]->gmwb_surv(time) << ","
							<< carvm_int_rate_non_elect << ","
							<< sm_carvm_stat[count]->carvm_disc_factor_non_elect(time) << ","
							<< sm_carvm_stat[count]->gmwb_dth_benefits(time) << ","
							<< sm_carvm_stat[count]->gmwb_dth_benefits_pv(time) << ","
							<< sm_carvm_stat[count]->fund_val_bef_pfwd(time) << ","
							<< sm_carvm_stat[count]->gmwb_wd(time) << ","
							<< sm_carvm_stat[count]->gmwb_surv(time) << ","
							<< carvm_int_rate_non_elect << ","
							<< sm_carvm_stat[count]->carvm_disc_factor_non_elect(time) << ","
							<< sm_carvm_stat[count]->withdrl_non_elective(time) << ","
							<< sm_carvm_stat[count]->withdrl_non_elective_pv(time) << ","
							<< carvm_int_rate_elect << ","
							<< sm_carvm_stat[count]->carvm_disc_factor_elect_cash_val(time) << ","
							<< sm_carvm_stat[count]->withdrl_elective(time) << ","
							<< sm_carvm_stat[count]->withdrl_elective_pv(time) << ","
							<< sm_carvm_stat[count]->res_gmwb(time) << endl;
						}
					}
				}
	
		StatAuditFile << endl << "--------------------------------------------------------TOTAL RESERVE"
				<< "--------------------------------------------------------" << endl
				<< "Policy duration,"<< sm_carvm_stat[0]->pol_yr(0) << endl
				<< "NO FPW CARVM RESERVE,"<< endl
				<< "Maximum duration,"<< sm_carvm_stat[0]->pv_max_period << endl
				<< "PV of death benefits,"<< sm_carvm_stat[0]->dth_benefits_pv(sm_carvm_stat[0]->pv_max_period) << endl
				<< "PV of NH benefits,"<< sm_carvm_stat[0]->nh_benefits_pv(sm_carvm_stat[0]->pv_max_period) << endl
				<< "PV of withdrawals,"<< sm_carvm_stat[0]->pfwd_surr_pv(sm_carvm_stat[0]->pv_max_period) << endl
				<< "PV of cash value,"<< sm_carvm_stat[0]->csv_e_pv(sm_carvm_stat[0]->pv_max_period) << endl			
				<< "Greatest PV,"<< sm_carvm_stat[0]->res_other(0) << endl
				<< "," << endl
				<< "FULL FPW CARVM RESERVE,"<< endl
				<< "Maximum duration,"<< sm_carvm_stat[1]->pv_max_period << endl
				<< "PV of death benefits,"<< sm_carvm_stat[1]->dth_benefits_pv(sm_carvm_stat[1]->pv_max_period) << endl
				<< "PV of NH benefits,"<< sm_carvm_stat[1]->nh_benefits_pv(sm_carvm_stat[1]->pv_max_period) << endl
				<< "PV of withdrawals,"<< sm_carvm_stat[1]->pfwd_surr_pv(sm_carvm_stat[1]->pv_max_period) << endl
				<< "PV of cash value,"<< sm_carvm_stat[1]->csv_e_pv(sm_carvm_stat[1]->pv_max_period) << endl								
				<< "Greatest PV,"<< sm_carvm_stat[1]->res_other(0) << endl
				<< "," << endl
				<< "GMWB RESERVE,"<< endl;
				if (!gmwb_flag)
					StatAuditFile << "There is no GMWB reserve " << endl;
				else if (pol_yr(t) > gmwb_req_yrs_wait + gmwb_exercise_yrs)
					{
					StatAuditFile<< "PV of death benefits,"<< sm_carvm_stat[2]->gmwb_dth_benefits_pv(sm_carvm_stat[2]->max_calc_period) << endl
						<< "PV of non elective withdrawals,,"<< sm_carvm_stat[2]->withdrl_non_elective_pv(sm_carvm_stat[2]->max_calc_period) << endl
						<< "PV of elective withdrawals,"<< sm_carvm_stat[2]->withdrl_elective_pv(sm_carvm_stat[2]->max_calc_period)  << endl								
						<< "Greatest PV,"<< sm_carvm_stat[2]->res_gmwb(0) << endl;
					}
				else 
					{
					StatAuditFile << "GMWB maximum excecution point," << sm_carvm_stat[gmwb_max_exec_point]->gmwb_exercise_point <<endl
						<< "PV of death benefits,"<< sm_carvm_stat[gmwb_max_exec_point]->gmwb_dth_benefits_pv(sm_carvm_stat[gmwb_max_exec_point]->max_calc_period) << endl
						<< "PV of non elective withdrawals,"<< sm_carvm_stat[gmwb_max_exec_point]->withdrl_non_elective_pv(sm_carvm_stat[gmwb_max_exec_point]->max_calc_period) << endl
						<< "PV of elective withdrawals,"<< sm_carvm_stat[gmwb_max_exec_point]->withdrl_elective_pv(sm_carvm_stat[gmwb_max_exec_point]->max_calc_period)  << endl								
						<< "Greatest PV,"<< sm_carvm_stat[gmwb_max_exec_point]->res_gmwb(0) << endl;
					}
		}
	
	StatAuditFile << "," << endl
			<< "FINAL RESERVE,"<< endl
			<< "Basic res,"<< stat_res_carvm_base(0) << endl
			<< "GMWB res,"<< stat_res_carvm_gmwb(0) << endl				
			<< "Cash value,"<< cash_val(0) << endl
			<< "Total res,"<< stat_res_mp(0) << endl;

	//Begin Tax Audit Report
	if (tax_res_defn == PERCENT_FUND_VALUE)
		TaxAuditFile << endl << "BASIC RESERVE," << endl
				<< "Fund value," << fund_val_fixed(0) << endl
				<< "Tax res pct," << tax_res_pct << endl
				<< "Tax res carvm," << tax_res_carvm_base(0) << endl;

	if (tax_res_defn == PERCENT_CASH_VALUE)
		TaxAuditFile << endl << "BASIC RESERVE," << endl
				<< "Cash value," << cash_val(0) << endl
				<< "Tax res pct," << tax_res_pct << endl
				<< "Tax res carvm," << tax_res_carvm_base(0) << endl;
	
	if (tax_res_defn == "CARVM")
		{
		TaxAuditFile << endl << "Life data" << endl
				<< "Period,Attained age,Carvm mort base life 1,Carvm mort mult life 1,Gmwb mort base life 1,Carvm NH incid base life 1,"
				<< "Carvm mort base life 2,Carvm mort mult life 2,Gmwb mort base life 2,Carvm NH incid base life 2,"
				<< "Sex pct,Carvm mort rate final,Gmwb mort rate final,NH incid rate final" << endl;

		for (int time = 1; time <= sm_carvm_tax[0]->max_calc_period; time++)
			{
			sm_carvm_tax[0]->mort_issue_age = sm_carvm_tax[0]->issue_age;
			sm_carvm_tax[0]->mort_attained_age = sm_carvm_tax[0]->attained_age(time);
			sm_carvm_tax[0]->mort_pol_yr = sm_carvm_tax[0]->pol_yr(time);
			sm_carvm_tax[0]->mort_gender = xstring(sm_carvm_tax[0]->gender);

			TaxAuditFile << time << "," //placeholder for intermediate mortality inputs
				<< sm_carvm_tax[0]->attained_age(time) << ",";

			if (gender_mp == "Blended")
				sm_carvm_tax[0]->mort_gender = MALE;

			TaxAuditFile << sm_carvm_tax[0]->carvm_mort_base << ","				
				<< sm_carvm_tax[0]->carvm_mort_mult << ","
				<< sm_carvm_tax[0]->gmwb_mort_base << ",";

			if (sm_carvm_tax[0]->include_nh_defn == YES && sm_carvm_tax[0]->surr_chg_pct(time) > model_point_amount_threshold && sm_carvm_tax[0]->csv_e(time) > model_point_amount_threshold)
				TaxAuditFile << sm_carvm_tax[0]->nh_incid_base << ",";
			else
				TaxAuditFile << 0 << ",";

			if (gender_mp == "Blended")
				sm_carvm_tax[0]->mort_gender = FEMALE;

			TaxAuditFile << sm_carvm_tax[0]->carvm_mort_base << ","
				<< sm_carvm_tax[0]->carvm_mort_mult << ","
				<< sm_carvm_tax[0]->gmwb_mort_base << ",";

			if (sm_carvm_tax[0]->include_nh_defn == YES && sm_carvm_tax[0]->surr_chg_pct(time) > model_point_amount_threshold && sm_carvm_tax[0]->csv_e(time) > model_point_amount_threshold)
				TaxAuditFile << sm_carvm_tax[0]->nh_incid_base << ",";
			else
				TaxAuditFile << 0 << ",";

			TaxAuditFile << male_sex_pct << ","
				<< sm_carvm_tax[0]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE) << ","
				<< sm_carvm_tax[0]->dth_claim_rate_calc(time,pol_yr(time),GMWB) << ","
				<< sm_carvm_tax[0]->nh_incid_rate(time) << endl;
			}

		TaxAuditFile << endl << "--------------------------------------------------------NO FPW CARVM RESERVE"
				<< "--------------------------------------------------------" << endl
				<< "Period,Fund val BOP,GMWB Withdrawals,Accum option pct,GMWB charge,"
				<< "Fund val bef PFWD,Contract val bef PFWD,PFWD pct,PFWD entitlement,PFWD surrender,"
				<< "Fund val aft PFWD,Surrender chg pct,Surrender chg,Guaranteed min contract val,"
				<< "Cash val" << endl;

		for (int time = 0; time <= sm_carvm_tax[1]->max_calc_period; time++)
			{
			if (time == 0)
				TaxAuditFile << time << endl;
			else
				{
				TaxAuditFile << time << ","
					<< sm_carvm_tax[0]->fund_val_aft_pfwd(time - 1) << ","
					<< sm_carvm_tax[0]->gmwb_wd(time) << ",";

				if (sm_carvm_tax[0]->fund_val_aft_pfwd(time - 1) < model_point_amount_threshold)
					TaxAuditFile << 0 << ",";
				else
					TaxAuditFile << (sm_carvm_tax[0]->fund_val_bef_pfwd(time) + sm_carvm_tax[0]->gmwb_chg(time))
								   / (sm_carvm_tax[0]->fund_val_aft_pfwd(time - 1) - sm_carvm_tax[0]->gmwb_wd(time)) << ",";
				
				TaxAuditFile << sm_carvm_tax[0]->gmwb_chg(time) << ","
					<< sm_carvm_tax[0]->fund_val_bef_pfwd(time) << ","					
					<< sm_carvm_tax[0]->contract_val_bef_pfwd(time) << ","
					<< pfwd_pct << ","
					<< sm_carvm_tax[0]->pfwd_entitlement(time) << ","
					<< sm_carvm_tax[0]->pfwd_surr(time) << ","
					<< sm_carvm_tax[0]->fund_val_aft_pfwd(time) << ","
					<< sm_carvm_tax[0]->surr_chg_pct(time) << ","
					<< sm_carvm_tax[0]->surr_chg(time) << ","					
					<< sm_carvm_tax[0]->guar_min_contract_val(time) << ","
					<< sm_carvm_tax[0]->csv_e(time) << endl;
				}					
			}
		
		TaxAuditFile << endl 
				<< "Period,Res integrated,GMWB reserve,Res other,PV dth benefit,PV NH benefit,PV PFWD surrender,PV cash val,"
				<< "Fund val bef PFWD,Contract val bef PFWD,Dth claim rate,Surv factor,Carvm int rate non-elect,Carvm dth ben disc factor,Dth ben current period,PV dth benefit,"
				<< "NH ben inf bef PFWD,NH incidence rate,NH ben current period,PV NH benefit,"
				<< "PFWD surrender,Surv factor,Carvm int rate elect,Carvm disc factor,PFWD current,PV PFWD surrender,"
				<< "Cash val,Surv factor,Carvm int rate elect,Carvm disc factor,PV cash val," 
				<< "Fund val bef PFWD,Dth claim rate GMWB,Surv GMWB,Carvm int rate non-elect,Carvm dth ben disc factor,Dth ben GMWB,PV GMWB death ben,"
				<< "Fund val bef PFWD,GMWB wdls,Surv GMWB,Carvm int rate non-elect,Carvm ann ben disc factor,Withdrawal non elect,PV withdrawal non elective,"
				<< "Carvm int rate elect,Carvm wdl disc factor,Withdrawal elect,PV withdrawal elective,GMWB reserve"<<endl;

		for (int time = 0; time <= sm_carvm_tax[0]->max_calc_period; time++)
			{
			sm_carvm_tax[0]->valn_carvm_defn = tax_carvm_defn;
            sm_carvm_tax[0]->valn_cash_settle_defn = valn_rate_cash_settle_defn;
            sm_carvm_tax[0]->valn_int_guar_defn = valn_rate_int_guar_defn;
            sm_carvm_tax[0]->valn_guar_dur = sm_carvm_tax[0]->int_guar_dur;
			sm_carvm_tax[0]->valn_plan_type = valn_rate_plan_type_elective_cash_val;

			carvm_int_rate_elect = sm_carvm_tax[0]->carvm_int_rate;

			sm_carvm_tax[0]->valn_carvm_defn = tax_carvm_defn;
            sm_carvm_tax[0]->valn_cash_settle_defn = valn_rate_cash_settle_defn;
            sm_carvm_tax[0]->valn_int_guar_defn = valn_rate_int_guar_defn;
            sm_carvm_tax[0]->valn_guar_dur = sm_carvm_tax[0]->int_guar_dur;
			sm_carvm_tax[0]->valn_plan_type = valn_rate_plan_type_non_elective;

			carvm_int_rate_non_elect = sm_carvm_tax[0]->carvm_int_rate;

			if (time == 0)
				TaxAuditFile << time << ","
					<< sm_carvm_tax[0]->res_integrated(0) << ","
					<< sm_carvm_tax[0]->res_gmwb(0) << ","
					<< sm_carvm_tax[0]->res_other(0) << ",,,,"
					<< sm_carvm_tax[0]->csv_e_pv(0) << ",,,,"
					<< sm_carvm_tax[0]->surv(0) << ",,,,,,,,,,"
					<< sm_carvm_tax[0]->surv(0) << ",,,,,"
					<< sm_carvm_tax[0]->csv_e(0) << ","
					<< sm_carvm_tax[0]->surv(0) << ",,"
					<< sm_carvm_tax[0]->carvm_disc_factor_elect_cash_val(0) << ","
					<< sm_carvm_tax[0]->csv_e_pv(0) << ",,,"
					<< sm_carvm_tax[0]->gmwb_surv(0) << ",,,,,,,"
					<< sm_carvm_tax[0]->gmwb_surv(0) << ",,"
					<< sm_carvm_tax[0]->carvm_disc_factor_non_elect(0) << ",,,,"
					<< sm_carvm_tax[0]->carvm_disc_factor_elect_cash_val(0) << endl;
			else
				{
				TaxAuditFile << time << ","
					<< sm_carvm_tax[0]->res_integrated(time) << ","
					<< sm_carvm_tax[0]->res_gmwb(0) << ","
					<< sm_carvm_tax[0]->res_other(time) << ","
					<< sm_carvm_tax[0]->dth_benefits_pv(time) << ","
					<< sm_carvm_tax[0]->nh_benefits_pv(time) << ","
					<< sm_carvm_tax[0]->pfwd_surr_pv(time) << ","
					<< sm_carvm_tax[0]->csv_e_pv(time) << ","
					<< sm_carvm_tax[0]->fund_val_bef_pfwd(time) << ","
					<< sm_carvm_tax[0]->contract_val_bef_pfwd(time) << ","
					<< sm_carvm_tax[0]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE) << ","
					<< sm_carvm_tax[0]->surv(time) << ","
					<< carvm_int_rate_non_elect << ","					
					<< sm_carvm_tax[0]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_tax[0]->dth_benefits(time) * sm_carvm_tax[0]->carvm_disc_factor_non_elect(time) <<","
					<< sm_carvm_tax[0]->dth_benefits_pv(time) << ",";

				if (sm_carvm_tax[0]->include_nh_defn == YES && sm_carvm_tax[0]->surr_chg_pct(time) > model_point_amount_threshold && sm_carvm_tax[0]->csv_e(time) > model_point_amount_threshold)
					TaxAuditFile << sm_carvm_tax[0]->fund_val_bef_pfwd(time) << ",";
				else
					TaxAuditFile << 0 << ",";

				TaxAuditFile << sm_carvm_tax[0]->nh_incid_rate(time) << ","
					<< sm_carvm_tax[0]->fund_val_bef_pfwd(time) 
							* sm_carvm_tax[0]->nh_incid_rate(time)
							* (1.0 - sm_carvm_tax[0]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE))
							* sm_carvm_tax[0]->surv(time - 1) 
							* sm_carvm_tax[0]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_tax[0]->nh_benefits_pv(time) << ","
					<< sm_carvm_tax[0]->pfwd_surr(time) << ","	
					<< sm_carvm_tax[0]->surv(time) << ","
					<< carvm_int_rate_elect << ","
					<< sm_carvm_tax[0]->carvm_disc_factor_elect_cash_val(time) << ","
					<< sm_carvm_tax[0]->pfwd_surr(time) 
							* sm_carvm_tax[0]->surv(time) 
							* sm_carvm_tax[0]->carvm_disc_factor_elect_cash_val(time) <<","
					<< sm_carvm_tax[0]->pfwd_surr_pv(time) << ","
					<< sm_carvm_tax[0]->csv_e(time) << ","
					<< sm_carvm_tax[0]->surv(time) << ","
					<< carvm_int_rate_elect << ","
					<< sm_carvm_tax[0]->carvm_disc_factor_elect_cash_val(time) << ","
					<< sm_carvm_tax[0]->csv_e_pv(time) << ","
					<< sm_carvm_tax[0]->fund_val_bef_pfwd(time) << ","
					<< sm_carvm_tax[0]->dth_claim_rate_calc(time,pol_yr(time),GMWB) << ","
					<< sm_carvm_tax[0]->gmwb_surv(time) << ","
					<< carvm_int_rate_non_elect << ","
					<< sm_carvm_tax[0]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_tax[0]->gmwb_dth_benefits(time) << ","
					<< sm_carvm_tax[0]->gmwb_dth_benefits_pv(time) << ","
					<< sm_carvm_tax[0]->fund_val_bef_pfwd(time) << ","
					<< sm_carvm_tax[0]->gmwb_wd(time) << ","
					<< sm_carvm_tax[0]->gmwb_surv(time) << ","
					<< carvm_int_rate_non_elect << ","
					<< sm_carvm_tax[0]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_tax[0]->withdrl_non_elective(time) << ","
					<< sm_carvm_tax[0]->withdrl_non_elective_pv(time) << ","
					<< carvm_int_rate_elect << ","
					<< sm_carvm_tax[0]->carvm_disc_factor_elect_cash_val(time) << ","
					<< sm_carvm_tax[0]->withdrl_elective(time) << ","
					<< sm_carvm_tax[0]->withdrl_elective_pv(time) << ","
					<< sm_carvm_tax[0]->res_gmwb(time) << endl;
				}
			}

		TaxAuditFile << endl << "--------------------------------------------------------FULL FPW CARVM RESERVE"
				<< "--------------------------------------------------------" << endl
				<< "Period,Fund val BOP,GMWB Withdrawals,Accum option pct,GMWB charge,"
				<< "Fund val bef PFWD,Contract val bef PFWD,PFWD pct,PFWD entitlement,PFWD surrender,"
				<< "Fund val aft PFWD,Surrender chg pct,Surrender chg,Guaranteed min contract val,"
				<< "Cash val" << endl;

		for (int time = 0; time <= sm_carvm_tax[1]->max_calc_period; time++)
			{
			if (time == 0)
				TaxAuditFile << time << endl;
			else
				{
				TaxAuditFile << time << ","
					<< sm_carvm_tax[1]->fund_val_aft_pfwd(time - 1) << ","
					<< sm_carvm_tax[1]->gmwb_wd(time) << ",";

				if (sm_carvm_tax[1]->fund_val_aft_pfwd(time - 1) < model_point_amount_threshold)
					TaxAuditFile << 0 << ",";
				else
					TaxAuditFile << (sm_carvm_tax[1]->fund_val_bef_pfwd(time) + sm_carvm_tax[1]->gmwb_chg(time))
								   / (sm_carvm_tax[1]->fund_val_aft_pfwd(time - 1) - sm_carvm_tax[1]->gmwb_wd(time)) << ",";
				
				TaxAuditFile << sm_carvm_tax[1]->gmwb_chg(time) << ","
					<< sm_carvm_tax[1]->fund_val_bef_pfwd(time) << ","					
					<< sm_carvm_tax[1]->contract_val_bef_pfwd(time) << ","
					<< pfwd_pct << ","
					<< sm_carvm_tax[1]->pfwd_entitlement(time) << ","
					<< sm_carvm_tax[1]->pfwd_surr(time) << ","
					<< sm_carvm_tax[1]->fund_val_aft_pfwd(time) << ","
					<< sm_carvm_tax[1]->surr_chg_pct(time) << ","
					<< sm_carvm_tax[1]->surr_chg(time) << ","					
					<< sm_carvm_tax[1]->guar_min_contract_val(time) << ","
					<< sm_carvm_tax[1]->csv_e(time) << endl;
				}					
			}
		
		TaxAuditFile << endl 
				<< "Period,Res integrated,GMWB reserve,Res other,PV dth benefit,PV NH benefit,PV PFWD surrender,PV cash val,"
				<< "Fund val bef PFWD,Contract val bef PFWD,Dth claim rate,Surv factor,Carvm int rate non-elect,Carvm dth ben disc factor,Dth ben current period,PV dth benefit,"
				<< "NH ben inf bef PFWD,NH incidence rate,NH ben current period,PV NH benefit,"
				<< "PFWD surrender,Surv factor,Carvm int rate elect,Carvm disc factor,PFWD current,PV PFWD surrender,"
				<< "Cash val,Surv factor,Carvm int rate elect,Carvm disc factor,PV cash val," 
				<< "Fund val bef PFWD,Dth claim rate GMWB,Surv GMWB,Carvm int rate non-elect,Carvm dth ben disc factor,Dth ben GMWB,PV GMWB death ben,"
				<< "Fund val bef PFWD,GMWB wdls,Surv GMWB,Carvm int rate non-elect,Carvm ann ben disc factor,Withdrawal non elect,PV withdrawal non elective,"
				<< "Carvm int rate elect,Carvm wdl disc factor,Withdrawal elect,PV withdrawal elective,GMWB reserve"<<endl;

		for (int time = 0; time <= sm_carvm_tax[1]->max_calc_period; time++)
			{
			
		    sm_carvm_tax[1]->valn_carvm_defn = tax_carvm_defn;
            sm_carvm_tax[1]->valn_cash_settle_defn = valn_rate_cash_settle_defn;
            sm_carvm_tax[1]->valn_int_guar_defn = valn_rate_int_guar_defn;
            sm_carvm_tax[1]->valn_guar_dur = sm_carvm_tax[1]->int_guar_dur;
			sm_carvm_tax[1]->valn_plan_type = valn_rate_plan_type_elective_cash_val;

			carvm_int_rate_elect = sm_carvm_tax[1]->carvm_int_rate;

			sm_carvm_tax[1]->valn_carvm_defn = tax_carvm_defn;
            sm_carvm_tax[1]->valn_cash_settle_defn = valn_rate_cash_settle_defn;
            sm_carvm_tax[1]->valn_int_guar_defn = valn_rate_int_guar_defn;
            sm_carvm_tax[1]->valn_guar_dur = sm_carvm_tax[1]->int_guar_dur;
			sm_carvm_tax[1]->valn_plan_type = valn_rate_plan_type_non_elective;

			carvm_int_rate_non_elect = sm_carvm_tax[1]->carvm_int_rate;

			if (time == 0)
				TaxAuditFile << time << ","
					<< sm_carvm_tax[1]->res_integrated(0) << ","
					<< sm_carvm_tax[1]->res_gmwb(0) << ","
					<< sm_carvm_tax[1]->res_other(0) << ",,,,"
					<< sm_carvm_tax[1]->csv_e_pv(0) << ",,,,"
					<< sm_carvm_tax[1]->surv(0) << ",,,,,,,,,,"
					<< sm_carvm_tax[1]->surv(0) << ",,,,,"
					<< sm_carvm_tax[1]->csv_e(0) << ","
					<< sm_carvm_tax[1]->surv(0) << ",,"
					<< sm_carvm_tax[1]->carvm_disc_factor_elect_cash_val(0) << ","
					<< sm_carvm_tax[1]->csv_e_pv(0) << ",,,"
					<< sm_carvm_tax[1]->gmwb_surv(0) << ",,,,,,,"
					<< sm_carvm_tax[1]->gmwb_surv(0) << ",,"
					<< sm_carvm_tax[1]->carvm_disc_factor_non_elect(0) << ",,,,"
					<< sm_carvm_tax[1]->carvm_disc_factor_elect_cash_val(0) << endl;
			else
				{
				TaxAuditFile << time << ","
					<< sm_carvm_tax[1]->res_integrated(time) << ","
					<< sm_carvm_tax[1]->res_gmwb(0) << ","
					<< sm_carvm_tax[1]->res_other(time) << ","
					<< sm_carvm_tax[1]->dth_benefits_pv(time) << ","
					<< sm_carvm_tax[1]->nh_benefits_pv(time) << ","
					<< sm_carvm_tax[1]->pfwd_surr_pv(time) << ","
					<< sm_carvm_tax[1]->csv_e_pv(time) << ","
					<< sm_carvm_tax[1]->fund_val_bef_pfwd(time) << ","
					<< sm_carvm_tax[1]->contract_val_bef_pfwd(time) << ","
					<< sm_carvm_tax[1]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE) << ","
					<< sm_carvm_tax[1]->surv(time) << ","
					<< carvm_int_rate_non_elect << ","					
					<< sm_carvm_tax[1]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_tax[1]->dth_benefits(time) * sm_carvm_tax[1]->carvm_disc_factor_non_elect(time) <<","
					<< sm_carvm_tax[1]->dth_benefits_pv(time) << ",";

				if (sm_carvm_tax[1]->include_nh_defn == YES && sm_carvm_tax[1]->surr_chg_pct(time) > model_point_amount_threshold && sm_carvm_tax[1]->csv_e(time) > model_point_amount_threshold)
					TaxAuditFile << sm_carvm_tax[1]->fund_val_bef_pfwd(time) << ",";
				else
					TaxAuditFile << 0 << ",";

				TaxAuditFile << sm_carvm_tax[1]->nh_incid_rate(time) << ","
					<< sm_carvm_tax[1]->fund_val_bef_pfwd(time) 
							* sm_carvm_tax[1]->nh_incid_rate(time)
							* (1.0 - sm_carvm_tax[1]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE))
							* sm_carvm_tax[1]->surv(time - 1) 
							* sm_carvm_tax[1]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_tax[1]->nh_benefits_pv(time) << ","
					<< sm_carvm_tax[1]->pfwd_surr(time) << ","	
					<< sm_carvm_tax[1]->surv(time) << ","
					<< carvm_int_rate_elect << ","
					<< sm_carvm_tax[1]->carvm_disc_factor_elect_cash_val(time) << ","
					<< sm_carvm_tax[1]->pfwd_surr(time) 
							* sm_carvm_tax[1]->surv(time) 
							* sm_carvm_tax[1]->carvm_disc_factor_elect_cash_val(time) <<","
					<< sm_carvm_tax[1]->pfwd_surr_pv(time) << ","
					<< sm_carvm_tax[1]->csv_e(time) << ","
					<< sm_carvm_tax[1]->surv(time) << ","
					<< carvm_int_rate_elect << ","
					<< sm_carvm_tax[1]->carvm_disc_factor_elect_cash_val(time) << ","
					<< sm_carvm_tax[1]->csv_e_pv(time) << ","
					<< sm_carvm_tax[1]->fund_val_bef_pfwd(time) << ","
					<< sm_carvm_tax[1]->dth_claim_rate_calc(time,pol_yr(time),GMWB) << ","
					<< sm_carvm_tax[1]->gmwb_surv(time) << ","
					<< carvm_int_rate_non_elect << ","
					<< sm_carvm_tax[1]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_tax[1]->gmwb_dth_benefits(time) << ","
					<< sm_carvm_tax[1]->gmwb_dth_benefits_pv(time) << ","
					<< sm_carvm_tax[1]->fund_val_bef_pfwd(time) << ","
					<< sm_carvm_tax[1]->gmwb_wd(time) << ","
					<< sm_carvm_tax[1]->gmwb_surv(time) << ","
					<< carvm_int_rate_non_elect << ","
					<< sm_carvm_tax[1]->carvm_disc_factor_non_elect(time) << ","
					<< sm_carvm_tax[1]->withdrl_non_elective(time) << ","
					<< sm_carvm_tax[1]->withdrl_non_elective_pv(time) << ","
					<< carvm_int_rate_elect << ","
					<< sm_carvm_tax[1]->carvm_disc_factor_elect_cash_val(time) << ","
					<< sm_carvm_tax[1]->withdrl_elective(time) << ","
					<< sm_carvm_tax[1]->withdrl_elective_pv(time) << ","
					<< sm_carvm_tax[1]->res_gmwb(time) << endl;
				}
			}
		
		for (int count = 2; count <sm_carvm_tax.size(); count++)
			{
			TaxAuditFile << endl << "--------------------------------------------------------GMWB CARVM RESERVE Exercise Point"
					<< sm_carvm_tax[count]->gmwb_exercise_point
					<< "--------------------------------------------------------" << endl
					<< "Period,Fund val BOP,GMWB Withdrawals,Accum option pct,GMWB charge,"
					<< "Fund val bef PFWD,Contract val bef PFWD,PFWD pct,PFWD entitlement,PFWD surrender,"
					<< "Fund val aft PFWD,Surrender chg pct,Surrender chg,Guaranteed min contract val,"
					<< "Cash val" << endl;

			for (int time = 0; time <= sm_carvm_tax[count]->max_calc_period; time++)
				{
				if (time == 0)
					TaxAuditFile << time << endl;
				else
					{
					TaxAuditFile << time << ","
						<< sm_carvm_tax[count]->fund_val_aft_pfwd(time - 1) << ","
						<< sm_carvm_tax[count]->gmwb_wd(time) << ",";

					if (sm_carvm_tax[count]->fund_val_aft_pfwd(time - 1) < model_point_amount_threshold)
						TaxAuditFile << 0 << ",";
					else
						TaxAuditFile << (sm_carvm_tax[count]->fund_val_bef_pfwd(time) + sm_carvm_tax[count]->gmwb_chg(time))
									   / (sm_carvm_tax[count]->fund_val_aft_pfwd(time - 1) - sm_carvm_tax[count]->gmwb_wd(time)) << ",";
				
					TaxAuditFile << sm_carvm_tax[count]->gmwb_chg(time) << ","
						<< sm_carvm_tax[count]->fund_val_bef_pfwd(time) << ","					
						<< sm_carvm_tax[count]->contract_val_bef_pfwd(time) << ","
						<< pfwd_pct << ","
						<< sm_carvm_tax[count]->pfwd_entitlement(time) << ","
						<< sm_carvm_tax[count]->pfwd_surr(time) << ","
						<< sm_carvm_tax[count]->fund_val_aft_pfwd(time) << ","
						<< sm_carvm_tax[count]->surr_chg_pct(time) << ","
						<< sm_carvm_tax[count]->surr_chg(time) << ","					
						<< sm_carvm_tax[count]->guar_min_contract_val(time) << ","
						<< sm_carvm_tax[count]->csv_e(time) << endl;
					}					
				}
		
				TaxAuditFile << endl 
					<< "Period,Res integrated,GMWB reserve,Res other,PV dth benefit,PV NH benefit,PV PFWD surrender,PV cash val,"
					<< "Fund val bef PFWD,Contract val bef PFWD,Dth claim rate,Surv factor,Carvm int rate non-elect,Carvm dth ben disc factor,Dth ben current period,PV dth benefit,"
					<< "NH ben inf bef PFWD,NH incidence rate,NH ben current period,PV NH benefit,"
					<< "PFWD surrender,Surv factor,Carvm int rate elect,Carvm disc factor,PFWD current,PV PFWD surrender,"
					<< "Cash val,Surv factor,Carvm int rate elect,Carvm disc factor,PV cash val," 
					<< "Fund val bef PFWD,Dth claim rate GMWB,Surv GMWB,Carvm int rate non-elect,Carvm dth ben disc factor,Dth ben GMWB,PV GMWB death ben,"
					<< "Fund val bef PFWD,GMWB wdls,Surv GMWB,Carvm int rate non-elect,Carvm ann ben disc factor,Withdrawal non elect,PV withdrawal non elective,"
					<< "Carvm int rate elect,Carvm wdl disc factor,Withdrawal elect,PV withdrawal elective,GMWB reserve"<<endl;

				for (int time = 0; time <= sm_carvm_tax[count]->max_calc_period; time++)
					{
					 sm_carvm_tax[count]->valn_carvm_defn = tax_carvm_defn;
                     sm_carvm_tax[count]->valn_cash_settle_defn = valn_rate_cash_settle_defn;
                     sm_carvm_tax[count]->valn_int_guar_defn = valn_rate_int_guar_defn;
                     sm_carvm_tax[count]->valn_guar_dur = sm_carvm_tax[count]->int_guar_dur;
					 sm_carvm_tax[count]->valn_plan_type = valn_rate_plan_type_elective_cash_val;

					 carvm_int_rate_elect = sm_carvm_tax[count]->carvm_int_rate;

					 sm_carvm_tax[count]->valn_carvm_defn = tax_carvm_defn;
                     sm_carvm_tax[count]->valn_cash_settle_defn = valn_rate_cash_settle_defn;
                     sm_carvm_tax[count]->valn_int_guar_defn = valn_rate_int_guar_defn;
                     sm_carvm_tax[count]->valn_guar_dur = sm_carvm_tax[count]->int_guar_dur;
					 sm_carvm_tax[count]->valn_plan_type = valn_rate_plan_type_non_elective;

					 carvm_int_rate_non_elect = sm_carvm_tax[count]->carvm_int_rate;

					if (time == 0)
						TaxAuditFile << time << ","
							<< sm_carvm_tax[count]->res_integrated(0) << ","
							<< sm_carvm_tax[count]->res_gmwb(0) << ","
							<< sm_carvm_tax[count]->res_other(0) << ",,,,"
							<< sm_carvm_tax[count]->csv_e_pv(0) << ",,,,"
							<< sm_carvm_tax[count]->surv(0) << ",,,,,,,,,,"
							<< sm_carvm_tax[count]->surv(0) << ",,,,,"
							<< sm_carvm_tax[count]->csv_e(0) << ","
							<< sm_carvm_tax[count]->surv(0) << ",,"
							<< sm_carvm_tax[count]->carvm_disc_factor_elect_cash_val(0) << ","
							<< sm_carvm_tax[count]->csv_e_pv(0) << ",,,"
							<< sm_carvm_tax[count]->gmwb_surv(0) << ",,,,,,,"
							<< sm_carvm_tax[count]->gmwb_surv(0) << ",,"
							<< sm_carvm_tax[count]->carvm_disc_factor_non_elect(0) << ",,,,"
							<< sm_carvm_tax[count]->carvm_disc_factor_elect_cash_val(0) << endl;
					else
						{
						TaxAuditFile << time << ","
							<< sm_carvm_tax[count]->res_integrated(time) << ","
							<< sm_carvm_tax[count]->res_gmwb(0) << ","
							<< sm_carvm_tax[count]->res_other(time) << ","
							<< sm_carvm_tax[count]->dth_benefits_pv(time) << ","
							<< sm_carvm_tax[count]->nh_benefits_pv(time) << ","
							<< sm_carvm_tax[count]->pfwd_surr_pv(time) << ","
							<< sm_carvm_tax[count]->csv_e_pv(time) << ","
							<< sm_carvm_tax[count]->fund_val_bef_pfwd(time) << ","
							<< sm_carvm_tax[count]->contract_val_bef_pfwd(time) << ","
							<< sm_carvm_tax[count]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE) << ","
							<< sm_carvm_tax[count]->surv(time) << ","
							<< carvm_int_rate_non_elect << ","					
							<< sm_carvm_tax[count]->carvm_disc_factor_non_elect(time) << ","
							<< sm_carvm_tax[count]->dth_benefits(time) * sm_carvm_tax[count]->carvm_disc_factor_non_elect(time) <<","
							<< sm_carvm_tax[count]->dth_benefits_pv(time) << ",";

						if (sm_carvm_tax[count]->include_nh_defn == YES && sm_carvm_tax[count]->surr_chg_pct(time) > model_point_amount_threshold && sm_carvm_tax[count]->csv_e(time) > model_point_amount_threshold)
							TaxAuditFile << sm_carvm_tax[count]->fund_val_bef_pfwd(time) << ",";
						else
							TaxAuditFile << 0 << ",";

						TaxAuditFile << sm_carvm_tax[count]->nh_incid_rate(time) << ","
							<< sm_carvm_tax[count]->fund_val_bef_pfwd(time) 
									* sm_carvm_tax[count]->nh_incid_rate(time)
									* (1.0 - sm_carvm_tax[count]->dth_claim_rate_calc(time,pol_yr(time),EXPERIENCE))
									* sm_carvm_tax[count]->surv(time - 1) 
									* sm_carvm_tax[count]->carvm_disc_factor_non_elect(time) << ","
							<< sm_carvm_tax[count]->nh_benefits_pv(time) << ","
							<< sm_carvm_tax[count]->pfwd_surr(time) << ","	
							<< sm_carvm_tax[count]->surv(time) << ","
							<< carvm_int_rate_elect << ","
							<< sm_carvm_tax[count]->carvm_disc_factor_elect_cash_val(time) << ","
							<< sm_carvm_tax[count]->pfwd_surr(time) 
									* sm_carvm_tax[count]->surv(time) 
									* sm_carvm_tax[count]->carvm_disc_factor_elect_cash_val(time) <<","
							<< sm_carvm_tax[count]->pfwd_surr_pv(time) << ","
							<< sm_carvm_tax[count]->csv_e(time) << ","
							<< sm_carvm_tax[count]->surv(time) << ","
							<< carvm_int_rate_elect << ","
							<< sm_carvm_tax[count]->carvm_disc_factor_elect_cash_val(time) << ","
							<< sm_carvm_tax[count]->csv_e_pv(time) << ","
							<< sm_carvm_tax[count]->fund_val_bef_pfwd(time) << ","
							<< sm_carvm_tax[count]->dth_claim_rate_calc(time,pol_yr(time),GMWB) << ","
							<< sm_carvm_tax[count]->gmwb_surv(time) << ","
							<< carvm_int_rate_non_elect << ","
							<< sm_carvm_tax[count]->carvm_disc_factor_non_elect(time) << ","
							<< sm_carvm_tax[count]->gmwb_dth_benefits(time) << ","
							<< sm_carvm_tax[count]->gmwb_dth_benefits_pv(time) << ","
							<< sm_carvm_tax[count]->fund_val_bef_pfwd(time) << ","
							<< sm_carvm_tax[count]->gmwb_wd(time) << ","
							<< sm_carvm_tax[count]->gmwb_surv(time) << ","
							<< carvm_int_rate_non_elect << ","
							<< sm_carvm_tax[count]->carvm_disc_factor_non_elect(time) << ","
							<< sm_carvm_tax[count]->withdrl_non_elective(time) << ","
							<< sm_carvm_tax[count]->withdrl_non_elective_pv(time) << ","
							<< carvm_int_rate_elect << ","
							<< sm_carvm_tax[count]->carvm_disc_factor_elect_cash_val(time) << ","
							<< sm_carvm_tax[count]->withdrl_elective(time) << ","
							<< sm_carvm_tax[count]->withdrl_elective_pv(time) << ","
							<< sm_carvm_tax[count]->res_gmwb(time) << endl;
						}
					}
				}
		
		TaxAuditFile << endl << "--------------------------------------------------------TOTAL RESERVE"
			<< "--------------------------------------------------------" << endl
			<< "Policy duration,"<< sm_carvm_tax[0]->pol_yr(0) << endl
			<< "NO FPW CARVM RESERVE,"<< endl
			<< "Maximum duration,"<< sm_carvm_tax[0]->pv_max_period << endl
			<< "PV of death benefits,"<< sm_carvm_tax[0]->dth_benefits_pv(sm_carvm_tax[0]->pv_max_period) << endl
			<< "PV of NH benefits,"<< sm_carvm_tax[0]->nh_benefits_pv(sm_carvm_tax[0]->pv_max_period) << endl
			<< "PV of withdrawals,"<< sm_carvm_tax[0]->pfwd_surr_pv(sm_carvm_tax[0]->pv_max_period) << endl
			<< "PV of cash value,"<< sm_carvm_tax[0]->csv_e_pv(sm_carvm_tax[0]->pv_max_period) << endl			
			<< "Greatest PV,"<< sm_carvm_tax[0]->res_other(0) << endl
			<< "," << endl
			<< "FULL FPW CARVM RESERVE,"<< endl
			<< "Maximum duration,"<< sm_carvm_tax[1]->pv_max_period << endl
			<< "PV of death benefits,"<< sm_carvm_tax[1]->dth_benefits_pv(sm_carvm_tax[1]->pv_max_period) << endl
			<< "PV of NH benefits,"<< sm_carvm_tax[1]->nh_benefits_pv(sm_carvm_tax[1]->pv_max_period) << endl
			<< "PV of withdrawals,"<< sm_carvm_tax[1]->pfwd_surr_pv(sm_carvm_tax[1]->pv_max_period) << endl
			<< "PV of cash value,"<< sm_carvm_tax[1]->csv_e_pv(sm_carvm_tax[1]->pv_max_period) << endl								
			<< "Greatest PV,"<< sm_carvm_tax[1]->res_other(0) << endl
			<< "," << endl
			<< "GMWB RESERVE,"<< endl;
			if (!gmwb_flag)
				TaxAuditFile << "There is no GMWB reserve " << endl;
			else if (pol_yr(t) > gmwb_req_yrs_wait + gmwb_exercise_yrs)
				{
				TaxAuditFile<< "PV of death benefits,"<< sm_carvm_tax[2]->gmwb_dth_benefits_pv(sm_carvm_tax[2]->max_calc_period) << endl
				<< "PV of non elective withdrawals,,"<< sm_carvm_tax[2]->withdrl_non_elective_pv(sm_carvm_tax[2]->max_calc_period) << endl
				<< "PV of elective withdrawals,"<< sm_carvm_tax[2]->withdrl_elective_pv(sm_carvm_tax[2]->max_calc_period)  << endl								
				<< "Greatest PV,"<< sm_carvm_tax[2]->res_gmwb(0) << endl;
				}
			else 
				{
				TaxAuditFile<< "GMWB maximum excecution point," << sm_carvm_tax[gmwb_max_exec_point]->gmwb_exercise_point <<endl
				<< "PV of death benefits,"<< sm_carvm_tax[gmwb_max_exec_point]->gmwb_dth_benefits_pv(sm_carvm_tax[gmwb_max_exec_point]->max_calc_period) << endl
				<< "PV of non elective withdrawals,"<< sm_carvm_tax[gmwb_max_exec_point]->withdrl_non_elective_pv(sm_carvm_tax[gmwb_max_exec_point]->max_calc_period) << endl
				<< "PV of elective withdrawals,"<< sm_carvm_tax[gmwb_max_exec_point]->withdrl_elective_pv(sm_carvm_tax[gmwb_max_exec_point]->max_calc_period)  << endl								
				<< "Greatest PV,"<< sm_carvm_tax[gmwb_max_exec_point]->res_gmwb(0) << endl;
				}
		}
		
	TaxAuditFile<< "," << endl
			<< "FINAL RESERVE,"<< endl
			<< "Basic res,"<< tax_res_carvm_base(0) << endl
			<< "GMWB res,"<< tax_res_carvm_gmwb(0) << endl				
			<< "Cash value,"<< cash_val(0) << endl
			<< "Stat res value,"<< stat_res_mp(0) << endl
			<< "Total res,"<< tax_res_mp(0) << endl;
	}

if (StatAuditFile != NULL)
	StatAuditFile.close();

if (TaxAuditFile != NULL)
	TaxAuditFile.close();
*/
return 1.0;

}

//@@ END

//@@ START - withdrl_benefits
// Partial Withdrawal Benefit                                                                                             
// Column:WITHDRL_BENEFITS
//========================================================
double FIA_LIAB_UDF::fia_liab_withdrl_benefits(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(471,"withdrl_benefits",t);
}



//^^^

#line 1 "withdrl_benefits.FIA_LIAB.for"
//20250502 Replaced with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double withdrl_amt = 0.;

if (!gmwb_flag) //Assume no excess withdrl on base product
{
	withdrl_amt = withdrl_benefits_gross_crbg(t);
}

if (gmwb_flag && pol_yr(t) > gmwb_exercise_yrs_crbg(t)) 
{
	//net withdrawal amount
	withdrl_amt = withdrl_benefits_gross_crbg(t)
					- mva_amt_excess_withdrl_crbg(t) - surr_chg_excess_withdrl_crbg(t); 
}

return max(withdrl_amt, 0.);

}

//@@ END

//@@ START - withdrl_benefits_gross_crbg
// Gross withdrl                                                                                             
// Column:WITHDRL_BENEFITS_GROSS_CRBG
//========================================================
double FIA_LIAB_UDF::fia_liab_withdrl_benefits_gross_crbg(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(472,"withdrl_benefits_gross_crbg",t);
}



//^^^

#line 1 "withdrl_benefits_gross_crbg.FIA_LIAB.for"
//20250502 New column with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

double withdrl_amt = 0.;
double wdl_period = 1.0;

if (!gmwb_flag)
{
	if (pfwd_freq == MONTHLY)
		wdl_period = 1.0;
	else if (pfwd_freq == QUARTERLY)
		wdl_period = 3.0;
	else // Annual 
		wdl_period = 12.0;
	
	if (mod(pol_mth(t) - 1, wdl_period) == 0.0) 
	{
		withdrl_amt = pfwd_entitlement(t) * pfwd_use_crbg(t)  * wdl_period / 12.0; 
	}
}

if (gmwb_flag && pol_yr(t) > gmwb_exercise_yrs_crbg(t))
{
	withdrl_amt = gmwb_wdl_amt_e_bef_crbg(t) * surv_period(t); 
}

double fund_val = fund_val_e_bef(t) * surv_period(t);

if (min_accum_val_e_bef_crbg(t) > fund_val_e_bef(t))
{
	fund_val = min_accum_val_e_bef_crbg(t) * surv_period(t);
}

return min(withdrl_amt, fund_val);

}

//@@ END

//@@ START - zz_cash_val_wo_mva_bef
// Cash Value Without MVA Before Claims                                                                                             
// Column:ZZ_CASH_VAL_WO_MVA_BEF
//========================================================
double FIA_LIAB_UDF::fia_liab_zz_cash_val_wo_mva_bef(int t) {
//^^^



//^^^

#line 1 "zz_cash_val_wo_mva_bef.FIA_LIAB.for"
//MQ: This column is not needed and no longer maintained.
//20250501 Replaced with CRBG logic
if (t <= commencement_period || t > maturity_period)
	return NO_AVG;

if (nyia_ind_crbg == YES)
{
	double csv_fund_val = fund_val_e_bef(t) - surr_chg_pct * (fund_val_e_bef(t) - pfwd_entitlement_remaining_bom(t));
	double csv_mav = min_accum_val_e_bef_crbg(t) - surr_chg_pct * (min_accum_val_e_bef_crbg(t) - pfwd_entitlement_remaining_bom(t));

	return max(csv_fund_val, csv_mav);
}

double cash_value = fund_val_e_bef(t) - surr_chg_inf_bef(t) - gmwb_chg_partial_bef_crbg(t) 
					- prem_bonus_recap_e_bef_crbg(t) - eprs_strat_fee_partial_bef_crbg(t); 

cash_value = max(cash_value, min_wdl_val_e_bef_crbg(t));

return cash_value;

}

//@@ END

//@@ START - tax_capzd_prem_amortzn_sched
// Tax Capitalized Premium Amortization Schedule                                                                                             
// Temporary Table:TAX_CAPZD_PREM_AMORTZN_SCHED
//========================================================
double FIA_LIAB_UDF::fia_liab_tax_capzd_prem_amortzn_sched
//^^^
(int x, int t) {
int  &r = x;
int  &c = t;
int  rows=ptr_tt_tax_capzd_prem_amortzn_sched->rows();
int  cols=ptr_tt_tax_capzd_prem_amortzn_sched->cols();

//^^^

	MonTableExtended *tempMonTable_ = (MonTableExtended *)ptr_tt_tax_capzd_prem_amortzn_sched;
	MonTableExtended *ptr_tt_tax_capzd_prem_amortzn_sched = tempMonTable_;


#line 1 "tax_capzd_prem_amortzn_sched.FIA_LIAB.for"
// Rows are the projection periods 't'
// Columns are the relative calendar years
double new_amortzn = 0.0;

// Each successive time step uses the relative calendar year from the original projection date
int proj_mth_adj = get_mth_from_date(proj_date);
int proj_start_mth_adj = proj_mth_adj == 12 ? 1: proj_mth_adj + 1;
int cal_yr_relative_adj = 1 + floor((proj_start_mth_adj + (r + valn_period) - 2) / 12.0);

for (int col = 0; col < tax_capzd_prem_amortzn_sched.cols(); col++)
	{
	// Column 0 is never used
	// Column 1 is not used because first year amortization occurs at capitalization
	if (col <= 1)
		tax_capzd_prem_amortzn_sched.setCell(r, col, 0.0);

	else if (r == 0) // At the projection date
		{
		// Start with values from the end of the previous time step, stored in array as part of financial_state_of_world
		if (time_step_flag && valn_period > 0)
			new_amortzn = init_tax_capzd_prem_amortzn_sched[min(long(init_tax_capzd_prem_amortzn_sched.size()) - 1, col)];
		else
			new_amortzn = 0.0;

		tax_capzd_prem_amortzn_sched.setCell(r, col, new_amortzn);
		}
	else // After the projection date
		{	
		if (tax_capzd_prem_amortzn_yrs > 0)
			{
			// First year amortization is excluded from this schedule; it occurs at capitalization.
			// Normal amortization years:
			if (col <= tax_capzd_prem_amortzn_yrs + cal_yr_relative_adj - 1)
				new_amortzn = tax_capzd_prem(r)
				              / tax_capzd_prem_amortzn_yrs;	
			else // Final year amortization is at half rate, like the first year.
				new_amortzn = tax_capzd_prem(r)
				              / (2 * tax_capzd_prem_amortzn_yrs);	
			}

		// For the current year, amortization is only from capitalizations in prior years.
		// Note this schedule is not called for columns before the current year.
		if (col <= cal_yr_relative_adj)
			tax_capzd_prem_amortzn_sched.setCell(r, col, 
				tax_capzd_prem_amortzn_sched(r - 1, col));
		// Amortization (excluding first year) of current capitalization is added for future periods.
		else if (col <= tax_capzd_prem_amortzn_yrs + cal_yr_relative_adj)
			tax_capzd_prem_amortzn_sched.setCell(r, col, 
				tax_capzd_prem_amortzn_sched(r - 1, col) + new_amortzn);
		else // Values are zero after the amortization of the current capitalization.
		    tax_capzd_prem_amortzn_sched.setCell(r, col, 0.0);		
	  	}
	}

return 0.0;

}

//@@ END

//@@ START - audit_detail_flag
// Audit detail flag                                                                                             
// Calculated Variable:AUDIT_DETAIL_FLAG
//========================================================
int FIA_LIAB_UDF::fia_liab_audit_detail_flag() {
//^^^


#line 1 "audit_detail_flag.FIA_LIAB.for"
if (target_column.find("valn_tgt_stat_tax") < string::npos
	&& audit_rpt_defn != "NONE")
	{
	if (audit_rpt_defn.find(mp_id) != string::npos)
		return 1;
	}

return 0;

}

//@@ END

//@@ START - commencement_period
// Period t in which Policy Commences                                                                                             
// Calculated Variable:COMMENCEMENT_PERIOD
//========================================================
int FIA_LIAB_UDF::fia_liab_commencement_period() {
//^^^


#line 1 "commencement_period.FIA_LIAB.for"
return max(0, -elapsed_mths);

}

//@@ END

//@@ START - data_file_name
// Data File Name                                                                                             
// Calculated Variable:DATA_FILE_NAME
//========================================================
xstring FIA_LIAB_UDF::fia_liab_data_file_name() {
//^^^


#line 1 "data_file_name.FIA_LIAB.for"
return replaceWildcards("<*data*>" + data_file_name_input + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv");

}

//@@ END

//@@ START - elapsed_mths
// Months Since Issue At Projection Date                                                                                             
// Calculated Variable:ELAPSED_MTHS
//========================================================
int FIA_LIAB_UDF::fia_liab_elapsed_mths() {
//^^^


#line 1 "elapsed_mths.FIA_LIAB.for"
int issue_yr = get_yr_from_date(issue_date_mp);
int issue_mth = get_mth_from_date(issue_date_mp);

int proj_yr = get_yr_from_date(proj_date_adj);
int proj_mth = get_mth_from_date(proj_date_adj);

return xint(proj_yr - issue_yr) * 12 + (proj_mth - issue_mth + 1);

}

//@@ END

//@@ START - final_period
// Final Period                                                                                             
// Calculated Variable:FINAL_PERIOD
//========================================================
int FIA_LIAB_UDF::fia_liab_final_period() {
//^^^


#line 1 "final_period.FIA_LIAB.for"
return last_proj_period;

}

//@@ END

//@@ START - gmwb_flag
// GMWB Flag                                                                                             
// Calculated Variable:GMWB_FLAG
//========================================================
int FIA_LIAB_UDF::fia_liab_gmwb_flag() {
//^^^


#line 1 "gmwb_flag.FIA_LIAB.for"
if (gmwb_ind != 0)
	return 1;

return 0;

}

//@@ END

//@@ START - gmwb_req_yrs_wait
// GMWB Required Years to Wait                                                                                             
// Calculated Variable:GMWB_REQ_YRS_WAIT
//========================================================
int FIA_LIAB_UDF::fia_liab_gmwb_req_yrs_wait() {
//^^^


#line 1 "gmwb_req_yrs_wait.FIA_LIAB.for"
if (!gmwb_flag)
	return 0;

return max(0, max(max(gmwb_min_age - issue_age_mp, 0), gmwb_wait_period));

}

//@@ END

//@@ START - infl_start_mth
// Inflation start mth                                                                                             
// Calculated Variable:INFL_START_MTH
//========================================================
int FIA_LIAB_UDF::fia_liab_infl_start_mth() {
//^^^


#line 1 "infl_start_mth.FIA_LIAB.for"
int infl_mth = get_mth_from_date(infl_start_date);

if (infl_mth == 12)
	return 1;
	
return infl_mth + 1;

}

//@@ END

//@@ START - infl_start_period
// Inflation start period                                                                                             
// Calculated Variable:INFL_START_PERIOD
//========================================================
int FIA_LIAB_UDF::fia_liab_infl_start_period() {
//^^^


#line 1 "infl_start_period.FIA_LIAB.for"
return max(month_number_from_date(infl_start_yr, infl_start_mth)
           - month_number_from_date(proj_start_yr, proj_start_mth),
           - valn_period);

}

//@@ END

//@@ START - infl_start_yr
// Inflation start year                                                                                             
// Calculated Variable:INFL_START_YR
//========================================================
int FIA_LIAB_UDF::fia_liab_infl_start_yr() {
//^^^


#line 1 "infl_start_yr.FIA_LIAB.for"
int infl_mth = get_mth_from_date(infl_start_date);

if (infl_mth == 12)
	return get_yr_from_date(infl_start_date) + 1;
	
return get_yr_from_date(infl_start_date);

}

//@@ END

//@@ START - issue_age
// Issue Age                                                                                             
// Calculated Variable:ISSUE_AGE
//========================================================
int FIA_LIAB_UDF::fia_liab_issue_age() {
//^^^


#line 1 "issue_age.FIA_LIAB.for"
//20250507 Revised with CRBG Logic
return issue_age_calc_crbg(gender_mp);

}

//@@ END

//@@ START - issue_date
// Issue Date                                                                                             
// Calculated Variable:ISSUE_DATE
//========================================================
int FIA_LIAB_UDF::fia_liab_issue_date() {
//^^^


#line 1 "issue_date.FIA_LIAB.for"
// This scalar is a lookup key for external sources varying by issue date
// The definition matches Excel = number of days since 1899
// The value is for the first day of the issue month

int year = issue_yr;
int month = issue_mth;
int day = issue_day;

return day_number_from_date(year, month, day);

}

//@@ END

//@@ START - issue_day
// Issue Day                                                                                             
// Calculated Variable:ISSUE_DAY
//========================================================
double FIA_LIAB_UDF::fia_liab_issue_day() {
//^^^


#line 1 "issue_day.FIA_LIAB.for"
return get_day_from_date(issue_date_mp);

}

//@@ END

//@@ START - issue_mth
// Issue Mth                                                                                             
// Calculated Variable:ISSUE_MTH
//========================================================
double FIA_LIAB_UDF::fia_liab_issue_mth() {
//^^^


#line 1 "issue_mth.FIA_LIAB.for"
return get_mth_from_date(issue_date_mp);

}

//@@ END

//@@ START - issue_yr
// Issue Year for Model Point                                                                                             
// Calculated Variable:ISSUE_YR
//========================================================
int FIA_LIAB_UDF::fia_liab_issue_yr() {
//^^^


#line 1 "issue_yr.FIA_LIAB.for"
int data_issue_yr = get_yr_from_date(issue_date_mp);

int proj_yr = get_yr_from_date(proj_date_adj);
int proj_mth = get_mth_from_date(proj_date_adj);

int calc_issue_yr = xint((proj_yr * 12 + proj_mth - elapsed_mths) / 12.0);

if (data_issue_yr != calc_issue_yr)
	{
	log_screen << "Warning: Entered Issue Date is inconsistent with elapsed months. "
	           << "for FIA model point: " << data_rec_num() << ". "
	           << "Calculated issue year will be used. " << MSG_ERROR;
	}

return calc_issue_yr;

}

//@@ END

//@@ START - itm_period_disc_rate
// ITM Period Discount Rate                                                                                             
// Calculated Variable:ITM_PERIOD_DISC_RATE
//========================================================
double FIA_LIAB_UDF::fia_liab_itm_period_disc_rate() {
//^^^


#line 1 "itm_period_disc_rate.FIA_LIAB.for"
return convert_rate_basis(glb_itm_disc_rate, EFFECTIVE_ANNUAL, - 12);

}

//@@ END

//@@ START - lapse_shock_year_crbg
// Lapse Shock Year Crbg                                                                                             
// Calculated Variable:LAPSE_SHOCK_YEAR_CRBG
//========================================================
int FIA_LIAB_UDF::fia_liab_lapse_shock_year_crbg() {
//^^^


#line 1 "lapse_shock_year_crbg.FIA_LIAB.for"
//20250502 Customized CRBG Logic
int shock_year = 0;

if(surr_chg_period_crbg < SMALL_DOUBLE || (mva_defn == CRBG && surr_chg_period_crbg > mva_init_term)) 
{
	shock_year = mva_init_term + 1.;
}
else // surr_chg_period > 0 and surr_chg_period <= mva_period
{
	shock_year = surr_chg_period_crbg + 1.;
}

return shock_year;


}

//@@ END

//@@ START - lipm_ind_crbg
// Lipm Ind                                                                                             
// Calculated Variable:LIPM_IND_CRBG
//========================================================
int FIA_LIAB_UDF::fia_liab_lipm_ind_crbg() {
//^^^


#line 1 "lipm_ind_crbg.FIA_LIAB.for"
if (gmwb_rollup_credit_type_crbg == INDEX_GROWTH)
	return 1;
else
	return 0;

}

//@@ END

//@@ START - maturity_age
// Maturity Age                                                                                             
// Calculated Variable:MATURITY_AGE
//========================================================
int FIA_LIAB_UDF::fia_liab_maturity_age() {
//^^^


#line 1 "maturity_age.FIA_LIAB.for"
if (maturity_age_input == 0)
	return issue_age_mp + term_to_omega_age;

return maturity_age_input;

}

//@@ END

//@@ START - maturity_period
// Period t in which Policy Matures                                                                                             
// Calculated Variable:MATURITY_PERIOD
//========================================================
int FIA_LIAB_UDF::fia_liab_maturity_period() {
//^^^


#line 1 "maturity_period.FIA_LIAB.for"
//20250430 MQ change
int issue_age_maturity;

StrEnum::EnumValue gender_cv = gender_mp;

if (gender_mp != gender_aft_inc)
{
	gender_cv = gender_aft_inc;
}

if (gender_cv == JOINT)
{
	issue_age_maturity = max(issue_age_male_crbg, issue_age_male_crbg);
}
else
{
	issue_age_maturity = issue_age_mp;
}

//return min(last_proj_period, (maturity_age - issue_age_maturity) * 12 - elapsed_mths);

double last_proj_period_cv = last_proj_period;

if (time_step_flag) //Change for nested runs
{
	last_proj_period_cv = valn_yrs * 12.0;

	if(!valn_flag)
	{
		last_proj_period_cv -= elapsed_mths;
	}
}

return min(last_proj_period_cv, (maturity_age - issue_age_maturity) * 12 - elapsed_mths);


}

//@@ END

//@@ START - max_mva_sc_period_crbg
// max of mva and sc period                                                                                             
// Calculated Variable:MAX_MVA_SC_PERIOD_CRBG
//========================================================
int FIA_LIAB_UDF::fia_liab_max_mva_sc_period_crbg() {
//^^^


#line 1 "max_mva_sc_period_crbg.FIA_LIAB.for"
//20250502 Customized CRBG Logic
int max_surr_chg_mva_period_cv = max(surr_chg_period_crbg, mva_init_term);

return max_surr_chg_mva_period_cv;


}

//@@ END

//@@ START - mort_impr_time_elapsed
// Mort Impr Time Elapsed                                                                                             
// Calculated Variable:MORT_IMPR_TIME_ELAPSED
//========================================================
double FIA_LIAB_UDF::fia_liab_mort_impr_time_elapsed() {
//^^^


#line 1 "mort_impr_time_elapsed.FIA_LIAB.for"
xstring start_date = mort_impr_base_date_crbg;
xstring end_date = issue_date_mp;

return time_between_dates_calc_crbg(start_date, end_date);

}

//@@ END

//@@ START - mva_comp_rate_issue
// Mva Comp Rate Issue                                                                                             
// Calculated Variable:MVA_COMP_RATE_ISSUE
//========================================================
double FIA_LIAB_UDF::fia_liab_mva_comp_rate_issue() {
//^^^


#line 1 "mva_comp_rate_issue.FIA_LIAB.for"
return this->get_comp_rate(mva_comp_rate_id, - elapsed_mths + 1);

}

//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring FIA_LIAB_UDF::fia_liab_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.FIA_LIAB.for"
return add_mths_to_date(proj_date, valn_period);

}

//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int FIA_LIAB_UDF::fia_liab_proj_start_date() {
//^^^


#line 1 "proj_start_date.FIA_LIAB.for"
return day_number_from_date(proj_start_yr, proj_start_mth, 1);

}

//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int FIA_LIAB_UDF::fia_liab_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.FIA_LIAB.for"
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
int FIA_LIAB_UDF::fia_liab_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.FIA_LIAB.for"
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
int FIA_LIAB_UDF::fia_liab_reins_flag() {
//^^^


#line 1 "reins_flag.FIA_LIAB.for"
if (reins_defn == NOT_APPLICABLE)
	return 0;

return 1;

}

//@@ END

//@@ START - start_period
// Projection start period                                                                                             
// Calculated Variable:START_PERIOD
//========================================================
int FIA_LIAB_UDF::fia_liab_start_period() {
//^^^


#line 1 "start_period.FIA_LIAB.for"
return max(0, commencement_period);

}

//@@ END

//@@ START - state_of_world_financial_file_path
// State of World Financial File Path                                                                                             
// Calculated Variable:STATE_OF_WORLD_FINANCIAL_FILE_PATH
//========================================================
xstring FIA_LIAB_UDF::fia_liab_state_of_world_financial_file_path() {
//^^^


#line 1 "state_of_world_financial_file_path.FIA_LIAB.for"
return "<*data*>";

}

//@@ END

//@@ START - tax_capzd_prem_amortzn_yrs
// Tax Capitalized Premium Amortization Years                                                                                             
// Calculated Variable:TAX_CAPZD_PREM_AMORTZN_YRS
//========================================================
int FIA_LIAB_UDF::fia_liab_tax_capzd_prem_amortzn_yrs() {
//^^^


#line 1 "tax_capzd_prem_amortzn_yrs.FIA_LIAB.for"
return 15.00;

}

//@@ END

//@@ START - term_to_omega_age
// Term (in Years) at Inception to Omega Age for Mortality Rates                                                                                             
// Calculated Variable:TERM_TO_OMEGA_AGE
//========================================================
int FIA_LIAB_UDF::fia_liab_term_to_omega_age() {
//^^^


#line 1 "term_to_omega_age.FIA_LIAB.for"
//20250513 Changed with CRBG logic
int omega_age = 999;

if (gender_mp == JOINT || gender_mp == BLENDED || gender_aft_inc == JOINT)
{
	omega_age = max(term_to_omega_age_m_crbg, term_to_omega_age_f_crbg);
}
else if (gender_mp == MALE)
{
	omega_age = term_to_omega_age_m_crbg;
}
else if (gender_mp == FEMALE)
{
	omega_age = term_to_omega_age_f_crbg;
}
else
{
	throw FatalError("Unhandled gender_mp reqested in term_to_omega_age!");
}

return omega_age;

}

//@@ END

//@@ START - term_to_omega_age_f_crbg
// Term (in Years) at Inception to Omega Age for Mortality Rates                                                                                             
// Calculated Variable:TERM_TO_OMEGA_AGE_F_CRBG
//========================================================
int FIA_LIAB_UDF::fia_liab_term_to_omega_age_f_crbg() {
//^^^


#line 1 "term_to_omega_age_f_crbg.FIA_LIAB.for"
double mort_base_rate = 0.0;
int test_t_end = commencement_period + (121 * 12);
// Binary search to find Omega Age
int imax = test_t_end;
int imin = commencement_period + 1;
int omega_age = 999;

while (imax >= imin)
	{
	int imid = (imin + imax) / 2;
	mort_issue_age = issue_age_female_crbg;
	mort_pol_yr = int((imid + elapsed_mths - 1) / 12 + 1);
	mort_attained_age = mort_issue_age + mort_pol_yr - 1;
	mort_gender = FEMALE;
	mort_base_rate = mort_base_omega; // 1 lookup key - attained_age

	if (enhanced_income_ind_crbg == YES)
	{
		mort_pol_yr = int((imid + elapsed_mths - 1) / 12 + 1);
		mort_gender = FEMALE;
		mort_issue_age = issue_age_female_crbg;
		mort_base_rate = max(0.0, min(1.0, mort_base_non_confined_crbg));
	}
	else
	{
		mort_gender = FEMALE;
		mort_attained_age = mort_issue_age + mort_pol_yr - 1;				
		double mort_mult_temp = mort_mult;

		mort_base_rate = (mort_base_rate * mort_improve_mult_crbg(mort_attained_age, mort_gender, imid))
									* mort_mult_temp;
	}

	if (mort_base_rate >= 1.0)
		{
	    if (imin == imax)
			{
			omega_age = mort_pol_yr - 1;//omega_age = mort_attained_age - mort_issue_age;
			break;
			}
		  else
			imax = imid;
		}
	else
		{
		if (imin == imax)
	 		break;
		else
			imin = imid + 1;
		}
	} // End of while loop 

if (omega_age == 999)
	{
	omega_age = 121;

	// Unable to find Omega, produce an error msg and return 121
	xstring message;

	message = "Unable to calculate Term at inception to Omega Age. ";
	message += "Mortality rates must ascend to 1. ";
	message += "Plan Code: " + xstring(plan_code);
	message += ", Issue Age: " + xstring(issue_age_male_crbg); //20250501 MQ change
								
	log_screen << message << MSG_ERROR;	
	}
return omega_age;


}

//@@ END

//@@ START - term_to_omega_age_m_crbg
// Term (in Years) at Inception to Omega Age for Mortality Rates                                                                                             
// Calculated Variable:TERM_TO_OMEGA_AGE_M_CRBG
//========================================================
int FIA_LIAB_UDF::fia_liab_term_to_omega_age_m_crbg() {
//^^^


#line 1 "term_to_omega_age_m_crbg.FIA_LIAB.for"
double mort_base_rate = 0.0;
int test_t_end = commencement_period + (121 * 12);
// Binary search to find Omega Age
int imax = test_t_end;
int imin = commencement_period + 1;
int omega_age = 999;

while (imax >= imin)
	{
	int imid = (imin + imax) / 2;
	mort_issue_age = issue_age_male_crbg;
	mort_pol_yr = int((imid + elapsed_mths - 1) / 12 + 1);
	mort_attained_age = mort_issue_age + mort_pol_yr - 1;
	mort_gender = MALE;
	mort_base_rate = mort_base_omega; // 1 lookup key - attained_age

	if (enhanced_income_ind_crbg == YES)
	{
		mort_pol_yr = int((imid + elapsed_mths - 1) / 12 + 1);
		mort_gender = MALE;
		mort_issue_age = issue_age_male_crbg;
		mort_base_rate = max(0.0, min(1.0, mort_base_non_confined_crbg));
	}
	else
	{
		mort_gender = MALE;
		mort_attained_age = mort_issue_age + mort_pol_yr - 1;				
		double mort_mult_temp = mort_mult;

		mort_base_rate = (mort_base_rate * mort_improve_mult_crbg(mort_attained_age, mort_gender, imid))
									* mort_mult_temp;
	}

	if (mort_base_rate >= 1.0)
		{
	    if (imin == imax)
			{
			omega_age = mort_attained_age - mort_issue_age;
			break;
			}
		  else
			imax = imid;
		}
	else
		{
		if (imin == imax)
	 		break;
		else
			imin = imid + 1;
		}
	} // End of while loop 

if (omega_age == 999)
	{
	omega_age = 121;

	// Unable to find Omega, produce an error msg and return 121
	xstring message;

	message = "Unable to calculate Term at inception to Omega Age. ";
	message += "Mortality rates must ascend to 1. ";
	message += "Plan Code: " + xstring(plan_code);
	message += ", Issue Age: " + xstring(issue_age_male_crbg); //20250501 MQ change
								
	log_screen << message << MSG_ERROR;	
	}
return omega_age;


}

//@@ END


#line 1 "calc_gmwb_wdl_util_level_crbg.FIA_LIAB.for"                                                                                   
double FIA_LIAB::calc_gmwb_wdl_util_level_crbg(
	int t, double unif_rv_cv, double util_level_cv, double fund_val_e_bef_cv , double gmwb_inf_e_bef_cv )
{
	double new_util_level_cv;

	if (gmwb_inf_e_bef_cv < SMALL_DOUBLE)
	{
		new_util_level_cv = 0.;
	}
	else if (util_level_cv == 0.)
	{
		new_util_level_cv = get_gmwb_wdl_init_util_level_crbg(unif_rv_cv);
	}
	else
	{
		int transition_tbl_type;

		double threshold = 0.2; //gmwb_wdl_utilization_transition_matrix_threshold_aig;

		if (fund_val_e_bef_cv > threshold * gmwb_inf_e_bef_cv)
		{
				transition_tbl_type = 1; 
		}
		else
		{
			transition_tbl_type = 2;
		}

		new_util_level_cv = get_gmwb_wdl_util_level_crbg(util_level_cv, transition_tbl_type, unif_rv_cv);
	}

	return new_util_level_cv;
}



#line 1 "dth_rate_calc_crbg.FIA_LIAB.for"                                                                                   
double FIA_LIAB::dth_rate_calc_crbg(int t, int pol_yr, StrEnum::EnumValue mort_gender_cv)
{
	double mort_rate_life = 0.0;
	double mort_rate = 0.0;
	double mort_base_temp = 0.0;
	double mort_mult_temp = 0.0;
	double mort_addn_temp = 0.0;

	if (mort_gender_cv == MALE)
	{
		mort_issue_age = issue_age_male_crbg;	

		mort_gender = MALE;
		mort_attained_age = mort_issue_age + pol_yr - 1;			
		mort_base_temp = mort_base;
		
		mort_gender = MALE;
		mort_attained_age = mort_issue_age + pol_yr - 1;				
		mort_mult_temp = mort_mult;

		mort_gender = MALE;
		mort_issue_age = mort_issue_age + pol_yr - 1;	
		mort_pol_yr = pol_yr;
		mort_addn_temp = mort_addn;
	}
	else
	{
		mort_issue_age = issue_age_female_crbg;	

		mort_gender = FEMALE;
		mort_attained_age = mort_issue_age + pol_yr - 1;			
		mort_base_temp = mort_base;
		
		mort_gender = FEMALE;
		mort_attained_age = mort_issue_age + pol_yr - 1;				
		mort_mult_temp = mort_mult;		

		mort_gender = FEMALE;
		mort_issue_age = mort_issue_age + pol_yr - 1;	
		mort_pol_yr = pol_yr;
		mort_addn_temp = mort_addn;
	}

	if(pba_scen_amt_valn_flag && !gmwb_flag)
	{
		mort_mult_temp *= pba_mort_mult_no_gmwb_crbg;
	}
		
	double mort_base_local = (mort_base_temp * mort_improve_mult_crbg(mort_attained_age, mort_gender, t))
									* mort_mult_temp;


	mort_rate_life = max(0.0, min(1.0, mort_base_local + mort_addn_temp));
		
	mort_rate = mort_rate_life;	

	return mort_rate;
}



#line 1 "dth_rate_confinement_calc_crbg.FIA_LIAB.for"                                                                                   
double FIA_LIAB::dth_rate_confinement_calc_crbg(int t, int pol_yr, StrEnum::EnumValue mort_gender_cv,
		int confinement_status, int confinement_age , int confinement_mths )
{
	double mort_rate_life = 0.0;
	int mort_iss_age_local;

	if (mort_gender_cv == MALE)
	{			
		mort_iss_age_local = issue_age_male_crbg;		
	}
	else if (mort_gender_cv == FEMALE)
	{			
		mort_iss_age_local = issue_age_female_crbg;		
	}

	if (confinement_status == 1) //Confined
	{
		confinement_age_crbg = confinement_age;
		confinement_mth_crbg = confinement_mths;

		mort_gender = mort_gender_cv;
		mort_rate_life = mort_base_confined_crbg;
		if (mort_rate_life < 1)
			mort_rate_life	= max(0.0, min(1.0, mort_rate_life * mort_mult_confined_crbg));

		mort_rate_life = convert_decrem_rate_basis(mort_rate_life, ACTUAL_MONTHLY, EFFECTIVE_ANNUAL); //convert from monthly to annual rate
	}
	else// if (confinement_status == 0)
	{
		mort_pol_yr = pol_yr;
		mort_gender = mort_gender_cv;
		mort_issue_age = mort_iss_age_local;
		mort_rate_life = max(0.0, min(1.0, mort_base_non_confined_crbg));
	}

	return mort_rate_life;
}



#line 1 "gen_uniform_rands_crbg.FIA_LIAB.for"                                                                                   
void FIA_LIAB::gen_uniform_rands_crbg(vector< vector <double>>& uniform_rands_arr)
{
	int seed_value;
	
	if (time_step_flag && !valn_flag)
		seed_value = proj_set_loop_num;
	else
		seed_value = proj_task_loop_num;

	for (int i = 1; i <= mp_id.length(); i++)
	{
		seed_value += int(mp_id[i - 1]) * (i + 128);
	}

	seed_value *= 1350000011;

	Uniform::RandomGenerator(HIGH_RES);
	Uniform::GeneratorSeed(HIGH_RES, seed_value);
	Uniform linear_congruential_uniform(0., 1.);

	double random_number;
	for (size_t stream = 0; stream < 5; stream++) // currently 5 sets of random number
	{
		vector <double> uniform_rands;

		for (size_t i = 0; i < t_high; i++)
		{
			random_number = linear_congruential_uniform.next();
			uniform_rands.push_back(random_number);
		}

		uniform_rands_arr.push_back(uniform_rands);
	}

}



#line 1 "get_comp_rate.FIA_LIAB.for"                                                                                   
double FIA_LIAB::get_comp_rate(xstring cr_id, int t)
{
if (cr_id == "NONE" || t > final_period)
	return 0.0;

// Get competitor rate from company level for portfolio projections
if (!isMainModel)
	return company->get_comp_rate(cr_id, t);

// Search for competitor rate and time in the map, if found, return
std::string map_index = cr_id.c_str();
map_index += '_';
map_index += std::to_string(t);

if (comp_rates_map.find(map_index) != comp_rates_map.end())
	return comp_rates_map[map_index];

// else must develop competitor rate and store in the map

int counter = 0;
double comp_rate = 0.0;

// Set lookup key 
comp_rate_id = cr_id;
double comp_rate_type = this->comp_rate_type;
comp_rate_id = cr_id;
double comp_rate_single_scen_yr = this->comp_rate_single_scen_yr;
comp_rate_id = cr_id;
double comp_rate_single_mult = this->comp_rate_single_mult;
comp_rate_id = cr_id;
double comp_rate_single_addn = this->comp_rate_single_addn;
comp_rate_id = cr_id;
double comp_rate_single_avg_mths = this->comp_rate_single_avg_mths;

if (comp_rate_type == SINGLE)
	{
	// Lookup key is comp_rate_id, set by get_comp_rate function
	if (fabs(comp_rate_single_mult) < rate_ratio_threshold)
		comp_rate = comp_rate_single_addn;

	else if (comp_rate_single_scen_yr < rate_ratio_threshold)
		comp_rate = comp_rate_single_addn;

	if (!stoch_flag)
		{
		log_screen << "Warning. Competitor rate " << comp_rate_id
				   << " is linked to scenario rates which are not loaded for this deterministic projection;"
				   << " it has been set to zero." << MSG_ERROR;

		return 0.0;
		}
		
	if (comp_rate_single_avg_mths <= 1)
		comp_rate = rates_ptr->get_int_rate(t, "Govt", GET_YIELD_RATE, 
                                        comp_rate_single_scen_yr,
                                        0, EFFECTIVE_ANNUAL, NO_SHIFT)
					* comp_rate_single_mult
					+ comp_rate_single_addn;
	else // if (comp_rate_single_avg_mths > 1)
		{
		comp_rate = 1.0;
			
		for (int counter = 0; counter < comp_rate_single_avg_mths; counter ++)
			{
			comp_rate *= (1.0 + rates_ptr->get_int_rate(t - counter, "Govt", GET_YIELD_RATE, 
			                                        comp_rate_single_scen_yr,
			                                        0, EFFECTIVE_ANNUAL, NO_SHIFT)
								* comp_rate_single_mult
								+ comp_rate_single_addn);
			}

		comp_rate = pow(comp_rate, 1.0 / comp_rate_single_avg_mths) - 1.0;
		}	
	}
else if (comp_rate_type == WEIGHTED)
	{
	// Must read all variables before comp_rate_id is overwritten by get_comp_rate
	comp_rate_id = cr_id;
	double weight_1 = comp_rate_weighted_rate1_weight;
	comp_rate_id = cr_id;
	double weight_2 = comp_rate_weighted_rate2_weight;
	comp_rate_id = cr_id;
	double weight_3 = comp_rate_weighted_rate3_weight;
	comp_rate_id = cr_id;
	xstring comp_rate_1_id = comp_rate_weighted_rate1_id;
	comp_rate_id = cr_id;
	xstring comp_rate_2_id = comp_rate_weighted_rate2_id;
	comp_rate_id = cr_id;
	xstring comp_rate_3_id = comp_rate_weighted_rate3_id;
	
	if (fabs(weight_1) > rate_ratio_threshold)
		comp_rate += get_comp_rate(comp_rate_1_id, t) * weight_1;
	
	if (fabs(weight_2) > rate_ratio_threshold)
		comp_rate += get_comp_rate(comp_rate_2_id, t) * weight_2;
	
	if (fabs(weight_3) > rate_ratio_threshold)
		comp_rate += get_comp_rate(comp_rate_3_id, t) * weight_3;
	}
else if (comp_rate_type == COMPARED)
	{
	// Must read all variables before comp_rate_id is overwritten by get_comp_rate
	comp_rate_id = cr_id;
	StrEnum::EnumValue comparison_defn = comp_rate_compared_defn;
	comp_rate_id = cr_id;
	xstring comp_rate_1_id = comp_rate_compared_rate1_id;
	comp_rate_id = cr_id;
	xstring comp_rate_2_id = comp_rate_compared_rate2_id;
	comp_rate_id = cr_id;
	xstring comp_rate_3_id = comp_rate_compared_rate3_id;

	if (comparison_defn == MAXIMUM_RATE)
		comp_rate = max(max(get_comp_rate(comp_rate_1_id, t), 
		                    get_comp_rate(comp_rate_2_id, t)),
                        get_comp_rate(comp_rate_3_id, t)); 			

	else // if (comparison_defn == MINIMUM_RATE)
		comp_rate = min(min(get_comp_rate(comp_rate_1_id, t),
		                    get_comp_rate(comp_rate_2_id, t)),
                        get_comp_rate(comp_rate_3_id, t));
	}
else // return an error code value
	return -999;

// store competitor rate and time in the map
comp_rates_map[map_index] = comp_rate;

return comp_rate;
}



#line 1 "get_gmwb_wdl_init_util_level_crbg.FIA_LIAB.for"                                                                                   
double FIA_LIAB::get_gmwb_wdl_init_util_level_crbg(double random_uniform_draw)
{
	gmwb_wdl_util_level_crbg = 3; //ABOVE_MAWA;
	double above_mawa_util_pct = gmwb_wdl_util_init_crbg;

	gmwb_wdl_util_level_crbg = 2; //MAWA;
	double level_mawa_util_pct = gmwb_wdl_util_init_crbg;

	gmwb_wdl_util_level_crbg = 1; //BELOW_MAWA;
	double below_mawa_util_pct = gmwb_wdl_util_init_crbg;

	if (random_uniform_draw <= below_mawa_util_pct)
	{
		return 1;
	}
	else if (random_uniform_draw <= below_mawa_util_pct + level_mawa_util_pct)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}



#line 1 "get_gmwb_wdl_util_level_crbg.FIA_LIAB.for"                                                                                   
double FIA_LIAB::get_gmwb_wdl_util_level_crbg(double current_level, int transition_tbl_id,	double random_uniform_draw)
{
	double to_below_util = get_gmwb_wdl_util_prob_crbg(current_level, 1., transition_tbl_id);
	double to_level_util = get_gmwb_wdl_util_prob_crbg(current_level, 2., transition_tbl_id);
	double to_above_util = get_gmwb_wdl_util_prob_crbg(current_level, 3., transition_tbl_id);

	if (random_uniform_draw <= to_below_util)
	{
		return 1; //BELOW_MAWA;
	}
	else if (random_uniform_draw <= to_below_util + to_level_util)
	{
		return 2; //MAWA;
	}
	else
	{
		return 3; //ABOVE_MAWA;
	}
}



#line 1 "get_gmwb_wdl_util_prob_crbg.FIA_LIAB.for"                                                                                   
double FIA_LIAB::get_gmwb_wdl_util_prob_crbg(
	double current_level, double tgt_level, int transition_tbl_id)
{
	double gmwb_wdl_next_util_prob;

	if (transition_tbl_id == 1)
	{
		gmwb_wdl_util_level_crbg		= current_level;
		gmwb_wdl_util_tgt_level_crbg	= tgt_level;
		gmwb_wdl_next_util_prob  = gmwb_wdl_next_util_prob_1_crbg;
	}
	else
	{
		gmwb_wdl_util_level_crbg		= current_level;
		gmwb_wdl_util_tgt_level_crbg	= tgt_level;
		gmwb_wdl_next_util_prob  = gmwb_wdl_next_util_prob_2_crbg;
	}

	return gmwb_wdl_next_util_prob;
}



#line 1 "get_rate.FIA_LIAB.for"                                                                                   
double FIA_LIAB::get_rate(StrEnum::EnumValue rate_defn, int t, const xstring &id_input, int rate_type, double rate_term_input, double fwd_or_moneyness, int return_rate_basis, int shift_type)
{
switch (rate_defn)
	{
	case INTEREST_RATE:
		if (isMainModel)
			return rates_ptr->get_int_rate(t, id_input, rate_type, rate_term_input, fwd_or_moneyness, return_rate_basis, shift_type);
		else //Portfolio
			return rates_ptr->get_int_rate(t, id_input, rate_type, rate_term_input, fwd_or_moneyness, return_rate_basis, shift_type);

	case INFLATION_RATE:
		if (isMainModel)
			return rates_ptr->get_infl_rate(t, return_rate_basis);
		else //Portfolio
			return rates_ptr->get_infl_rate(t, return_rate_basis);
	
	case INDEX_RATE:
		if (isMainModel)
			return rates_ptr->get_index_rate(t, 
						id_input,
						rate_type,
						return_rate_basis);
		else //Portfolio
			return rates_ptr->get_index_rate(t, 
						id_input,
						rate_type,
						return_rate_basis);

	case INDEX_VOL:
		if (isMainModel)
			return rates_ptr->get_index_vol(t, 
					id_input,
					fwd_or_moneyness,
					rate_term_input,
					return_rate_basis,
					shift_type);
		else //Portfolio
			return rates_ptr->get_index_vol(t, 
					id_input,
					fwd_or_moneyness,
					rate_term_input,
					return_rate_basis,
					shift_type);
	
	default:
		return 0.0;
	}
}



#line 1 "irr_calc.FIA_LIAB.for"                                                                                   
double FIA_LIAB::irr_calc(int t, const xstring &roi_type)
{
int period = 0;
int adj_begin = 1;
int ind_chk = 0;
double adj_pv_prof_1 = 0;
double adj_pv_prof_2 = 0;
double prof = 0;
double pv_prof = 0;
double pv_factor = 0;
double yld_factor = 0;
double roi_guess = 0.1;
double low_pv = 0;
double high_pv = 0;
double tgt_cap = 0.0;
double* bk_prof_aft_tax_for_pv = NULL;
double* bk_prof_aft_tax_irr = NULL;
double* distrib_earnings = NULL;
double* distrib_earnings_irr  = NULL;
double* bef_tax_yld = NULL;
double* port_yld_aft_tax = NULL;
double min_rate_mthly = -.318708; // Annual rate = -.99
double max_rate_mthly = .042086; // Annual rate = .64

bk_prof_aft_tax_for_pv = new double[final_period + 1];
bk_prof_aft_tax_irr = new double[final_period + 1];
distrib_earnings = new double[final_period + 1];
distrib_earnings_irr  = new double[final_period + 1];
bef_tax_yld = new double[final_period + 1];
port_yld_aft_tax = new double[final_period + 1];

// force call disc_rate_port_yld_defn_val
disc_rate_port_yld_defn_val(start_period + 1);

// initialize arrays
for (int i = 0; i < final_period; i++)
	{
	bk_prof_aft_tax_for_pv[i] = 0.0;
	bk_prof_aft_tax_irr[i] = 0.0;
	distrib_earnings[i] = 0.0;
	distrib_earnings_irr [i] = 0.0;
	bef_tax_yld[i] = 0.0;
	port_yld_aft_tax[i] = 0.0;
	}

// drive the calculations forward
tgt_cap = this->tgt_cap(0);

for (int tt = 1; tt <= final_period; tt++)
	{
	bk_prof_aft_tax_for_pv[tt] = this->bk_prof_aft_tax_for_pv(tt);
	bk_prof_aft_tax_irr[tt] = this->bk_prof_aft_tax_irr(tt);
	distrib_earnings[tt] = this->distrib_earnings(tt);
	distrib_earnings_irr [tt] = this->distrib_earnings_irr (tt);
	bef_tax_yld[tt] = this->bef_tax_yld(tt);
	port_yld_aft_tax[tt] = this->port_yld_aft_tax(tt);

	if (roi_type == "Without Target Capital")
		{
		if (bk_prof_aft_tax_irr[tt] >= 0.0
		    && tt < last_proj_period)	
			adj_begin++;
		}
	else
		{	
		if (distrib_earnings_irr [tt] >= 0.0
		    && tt < last_proj_period)	
			adj_begin++;
		}
	}

if (adj_begin == final_period)
	return 0.0;

double low_roi = min_rate_mthly;
double high_roi = min_rate_mthly;
double last_roi_guess = min_rate_mthly;

for (period = final_period; period > 0; period--)
	{
	if (roi_type == "Without Target Capital")
		{
		if (period > adj_begin)
			prof = bk_prof_aft_tax_for_pv[period];
	
		else if (period == adj_begin)
			prof = bk_prof_aft_tax_irr[period]; 
	
		else
			prof = 0.0;
		}
	else 
		{
		if (period > adj_begin)
			prof = distrib_earnings[period];
	
		else if (period == adj_begin)
			prof = distrib_earnings_irr [period]; 
	
		else
			prof = 0.0;
		}

	if (adj_pv_prof_1 + prof >= 0
		&& disc_rate_port_yld_defn == BEFORE_TAX)
		yld_factor
		= 1.0 / pow(1.0 + max(bef_tax_yld[period], -.99),
		           (1.0 / 12.0));

	else
		yld_factor
		= 1.0 / pow(1.0 + max(port_yld_aft_tax[period], -.99),
		           (1.0 / 12.0));

	if (adj_pv_prof_2 + prof >= 0)
		pv_factor 
		= 1.0 / (1.0 + roi_guess);

	else
		pv_factor
		= 1.0 / pow(1.0 + max(port_yld_aft_tax[period], -.99),
		           (1.0 / 12.0));
		
	adj_pv_prof_1
	= (adj_pv_prof_1 + prof)
	  * yld_factor;			

	adj_pv_prof_2
	= (adj_pv_prof_2 + prof)
	  * pv_factor;
	  
	if (adj_pv_prof_2 > 0)
		ind_chk = 1;
		  
	} 
			
adj_pv_prof_2
-= max(tgt_cap, 0.0);			

if (adj_pv_prof_2 >= 0)
	{
	low_roi = roi_guess;
	low_pv = adj_pv_prof_2;
	}
else
	{			
	high_roi = roi_guess;
	high_pv = adj_pv_prof_2;
	}

last_roi_guess = roi_guess;
		
if (!ind_chk)
	roi_guess = last_roi_guess;

else if (ind_chk && low_roi > min_rate_mthly
		 && high_roi > min_rate_mthly)
	roi_guess = max(min_rate_mthly,
	                high_roi 
	                - high_pv
	                  * (high_roi - low_roi)
	                  / (high_pv - low_pv)); 				

else if (ind_chk && low_roi == min_rate_mthly)
	roi_guess = (low_roi + high_roi) / 2.0;

else if (ind_chk && high_roi == min_rate_mthly)
	roi_guess = low_roi + max(max_rate_mthly, low_roi);			
						
while (fabs(roi_guess - last_roi_guess) > .00001
		&& (low_pv - high_pv) > .0000001)
	{		
	pv_prof = 0.0;

	for (period = final_period; period >= adj_begin; period--)
		{
		if (roi_type == "Without Target Capital")
			{
			if (period > adj_begin)
				prof = bk_prof_aft_tax_for_pv[period];
		
			else if (period == adj_begin)
				prof = bk_prof_aft_tax_irr[period]; 
		
			else
				prof = 0.0;
			}
		else 
			{
			if (period > adj_begin)
				prof = distrib_earnings[period];
		
			else if (period == adj_begin)
				prof = distrib_earnings_irr [period]; 
		
			else
				prof = 0.0;
			}

		if (pv_prof + prof >= 0)
			pv_factor
			= 1.0 / (1.0 + roi_guess);

		else
			pv_factor
			= 1.0 / pow(1.0 + max(port_yld_aft_tax[period], -.99), (1.0 / 12.0));			

		pv_prof
		= (pv_prof + prof) * pv_factor;		

		} 
	pv_prof
	-= max(tgt_cap, 0.0);

	if (1000000 * pv_prof > 0)
		{
		low_roi = roi_guess;
		low_pv = pv_prof;
		}
	else
		{	
		high_roi = roi_guess;
		high_pv = pv_prof;
		}

	last_roi_guess = roi_guess;
	
	if (low_roi > min_rate_mthly
	    && high_roi > min_rate_mthly
		&& (pow(1.0 + high_roi, 12.0) - pow(1.0 + low_roi, 12.0) < (0.1)))	
		roi_guess = max(min_rate_mthly,
		                high_roi 
		                - high_pv
		                  * (high_roi - low_roi)
		                  / (high_pv - low_pv)); 				

	else if (low_roi == min_rate_mthly
	         || (pow(1.0 + high_roi, 12.0) - pow(1.0 + low_roi, 12.0) > (0.1)))
		roi_guess = (low_roi + high_roi) / 2.0;

	else if (high_roi == min_rate_mthly)
		roi_guess = low_roi + max(max_rate_mthly, low_roi);			
	}

// delete arrays
delete [] bk_prof_aft_tax_for_pv;
delete [] bk_prof_aft_tax_irr;
delete [] distrib_earnings;
delete [] distrib_earnings_irr ;
delete [] bef_tax_yld;
delete [] port_yld_aft_tax;

bk_prof_aft_tax_for_pv = NULL;
bk_prof_aft_tax_irr = NULL;
distrib_earnings = NULL;
distrib_earnings_irr  = NULL;
bef_tax_yld = NULL;
port_yld_aft_tax = NULL;

if (ind_chk)
	return min(max(pow(1.0 + roi_guess, 12.0) - 1.0, -.9999), 99.9999);

return -.9999;
}



#line 1 "issue_age_calc_crbg.FIA_LIAB.for"                                                                                   
int FIA_LIAB::issue_age_calc_crbg(StrEnum::EnumValue gender_cv)		
{		
	int return_value;	
		
	if (gender_cv == JOINT) {	
		return_value = min(issue_age_male_crbg, issue_age_female_crbg);
	} else if (gender_cv == MALE) {	
		return_value = issue_age_male_crbg;
	} else if (gender_cv == FEMALE) {	
		return_value = issue_age_female_crbg;
	} else if (gender_cv == BLENDED) {	
		return_value = issue_age_male_crbg;
	} else {	
		throw FatalError("Unhandled gender encountered during issue age set!");
	}	
		
	return return_value;	
}	



#line 1 "lapse_rate_dyn.FIA_LIAB.for"                                                                                   
double FIA_LIAB::lapse_rate_dyn(int t) 
{
double threshold = 0.0;
double sc_ratio = 0.0;
double base = 0.0;
double exponent = 0.0;
double prev_cred = 0.0;
double non_equity_component = 0.0;
double equity_component = 0.0;

/**********************************
Fixed Component
**********************************/
int pol_yr = xint(this->pol_yr(t));
double mkt_rate = get_comp_rate(asset_yld_comp_rate_id, t);

threshold = lapse_dyn_thresh;

if (fabs(fund_val_e_bef(t)) <= model_point_amount_threshold)
	sc_ratio = 0.0;
else
	sc_ratio = 1.0 - cash_val_bef(t) / fund_val_e_bef(t);

base =  mkt_rate - opt_budget(t) - threshold;

if (base <= 0.0)
	return 0.0;

exponent = lapse_dyn_exp;

non_equity_component = (lapse_dyn_mult)
						* pow(base, exponent) 
						* (1.0- sc_ratio * lapse_dyn_scmult);

/**********************************
Equity Component
**********************************/
if (t - pol_mth(t) - commencement_period <= 0)
	equity_component = 0.0;
else
	{	
	prev_cred = credited_int(t - pol_mth(t)) / fund_val_b(t - pol_mth(t));
				
	equity_component = lapse_dyn_mult
						* (mkt_rate - prev_cred);
	}
	
return (non_equity_component + equity_component) / 100.0;	
}



#line 1 "mort_improve_mult_crbg.FIA_LIAB.for"                                                                                   
double FIA_LIAB::mort_improve_mult_crbg(int att_age, StrEnum::EnumValue gender_local, int t)
{
	double n;
	double cumul_mort_improve;
 
	n = mort_impr_time_elapsed + (elapsed_mths + t) / 12.;

	// Mortality improvement lookup keys are mort_attained_age and cal_yr_table_index
	mort_attained_age = att_age;  
	mort_gender = gender_local; 
	cumul_mort_improve = pow ((1 - mort_improve_pct), n);

	return cumul_mort_improve;
}



#line 1 "pv_gmwb_benefit_itm_calc.FIA_LIAB.for"                                                                                   
double FIA_LIAB::pv_gmwb_benefit_itm_calc(int t, int pol_yr, int pol_mth, double disc_rate, double gmwb_if_bef_eom, double gmwb_max_wthdrl_amt_bef, double pfwd_cumul)
{
double period_disc = disc_rate;
double v = 1.0 / (1.0 + period_disc);
double pv_disc = 1.0;
StrEnum::EnumValue mort_basis = EXPERIENCE;

if (pfwd_cumul < model_point_amount_threshold 
	|| gmwb_max_wthdrl_amt_bef < model_point_amount_threshold) //No withdrawals taken so far 
	{
	double gmwb_av_if_bef_eom = gmwb_fund_val_inf_bef(t);
	double gmwb_prem_if_bef_eom = gmwb_income_base_e_bef_crbg(t);
	double gmwb_rollup_cap_if_bef_eom = gmwb_rollup_cap_inf_bef(t);
	double gmwb_if_eom = 0.0;

	//assume all initial values before decrements
	double surv_period = (1.0 - dth_rate_mthly_crbg(t)); //20250501 MQ change
	//double surv_period = (1.0 - mort_rate_exp(t));

	double gmwb_av_if_eom = gmwb_av_if_bef_eom * surv_period;
	double gmwb_prem_if_eom = gmwb_prem_if_bef_eom * surv_period;
	double gmwb_rollup_cap_if_eom = gmwb_rollup_cap_if_bef_eom * surv_period;
	double gmwb_max_wthdrl_amt = gmwb_max_wthdrl_amt_bef * surv_period;

	while (pol_yr <= gmwb_req_yrs_wait + gmwb_exercise_yrs 
		   || (pol_yr == gmwb_req_yrs_wait + gmwb_exercise_yrs + 1 
		       && (pol_mth == 1)))
		{
		t += 1;
		pv_disc *= v;
		pol_yr = int((t + elapsed_mths - 1) / 12.0 + 1);
		pol_mth = int(t + elapsed_mths - 1) % 12 + 1;
		gmwb_withdrl_age = xint(issue_age_mp) + pol_yr - 1.0;
		double mawp_local = gmwb_max_ann_wdl_pct_crbg(t);
		//double surv_period = (1.0 - mort_rate_exp(t));
		double surv_period = (1.0 - dth_rate_mthly_crbg(t));

		//Calculate gmwb_prem_if_bef
		if (gmwb_prem_defn != NOT_APPLICABLE)
			{
			if (gmwb_withdrl_age >= gmwb_max_age)
				gmwb_prem_if_bef_eom = gmwb_prem_if_eom;
			else if (gmwb_prem_defn == ROLLUP && pol_yr <= gmwb_max_rollup_duration)
				{
				if (gmwb_rollup_freq_defn == ANNIVERSARY)
					{
					if (pol_mth == 1)
						gmwb_prem_if_bef_eom = gmwb_prem_if_eom 
							                   * (1.0 + gmwb_rollup_rate);
					else
						gmwb_prem_if_bef_eom = gmwb_prem_if_eom;
					}
				else
					gmwb_prem_if_bef_eom 
					= gmwb_prem_if_eom
					  * (1.0 + convert_rate_basis(gmwb_rollup_rate, EFFECTIVE_ANNUAL, - 12.0));
				}
			else if (gmwb_prem_defn == STEPUP 
				     && pol_yr == gmwb_req_yrs_wait + gmwb_exercise_yrs + 1 
				     && (pol_mth == 1))
				gmwb_prem_if_bef_eom 
				= gmwb_prem_if_eom * (1.0 + gmwb_step_up_rate);
			else
				gmwb_prem_if_bef_eom = gmwb_prem_if_eom;
			}

		//calculate gmwb_rollup_cap_if_bef
		if (gmwb_prem_defn == ROLLUP)
			gmwb_rollup_cap_if_bef_eom = gmwb_rollup_cap_if_eom;

		//calculate gmwb_av_if_bef
		if (gmwb_fund_val_defn != NOT_APPLICABLE)
			gmwb_av_if_bef_eom = gmwb_av_if_eom;
		
		//Calculate gmwb_if_bef_eom
		if (gmwb_prem_defn == ROLLUP)
			gmwb_if_bef_eom = max(gmwb_av_if_bef_eom, min(gmwb_prem_if_bef_eom, gmwb_rollup_cap_if_bef_eom));
		else
			gmwb_if_bef_eom = max(gmwb_av_if_bef_eom, gmwb_prem_if_bef_eom);
		
		//Calculate gmwb_max_wdl_amt
		if (gmwb_max_wdl_amt_base_defn == PREMIUM)
			{
			if (pol_yr <= gmwb_req_yrs_wait + gmwb_exercise_yrs)
				gmwb_max_wthdrl_amt_bef = 0.0;
			else // if (pol_yr == gmwb_req_yrs_wait + gmwb_exercise_yrs + 1 && (pol_mth == 1))
				gmwb_max_wthdrl_amt_bef = gmwb_prem_if_eom * mawp_local;   
			}
		else //"GMWB BASE" or "GMWB BASE ADJUSTABLE"
			{
			if (pol_yr <= gmwb_req_yrs_wait + gmwb_exercise_yrs)
				gmwb_max_wthdrl_amt_bef = 0.0;
			else // if (pol_yr == gmwb_req_yrs_wait + gmwb_exercise_yrs + 1 && (pol_mth == 1))
				gmwb_max_wthdrl_amt_bef = gmwb_if_bef_eom * mawp_local;   
			}

		if (pol_yr == gmwb_req_yrs_wait + gmwb_exercise_yrs + 1 
			&& (pol_mth == 1))
			break;
		
		//Calculate gmwb_prem_if
		if (gmwb_prem_defn != NOT_APPLICABLE)
			gmwb_prem_if_eom = gmwb_prem_if_bef_eom * surv_period;
		
		//Calculate gmwb_rollup_cap_if
		if (gmwb_prem_defn == ROLLUP)
			gmwb_rollup_cap_if_eom = gmwb_rollup_cap_if_bef_eom * surv_period;
		
		//Calculate gmwb_av_if
		if (gmwb_fund_val_defn != NOT_APPLICABLE)
			gmwb_av_if_eom = gmwb_av_if_bef_eom * surv_period;

		//Calculate gmwb_if
		if (gmwb_prem_defn == ROLLUP)
			gmwb_if_eom = max(gmwb_av_if_eom, min(gmwb_prem_if_eom, gmwb_rollup_cap_if_eom));
		else
			gmwb_if_eom = max(gmwb_av_if_eom, gmwb_prem_if_eom);
		
		//Decrement Withdrawal Amount
		gmwb_max_wthdrl_amt = gmwb_max_wthdrl_amt_bef * surv_period;
		}	
	}

double period_wdl = gmwb_max_wthdrl_amt_bef / 12.0;
double disc_wdls = min(gmwb_if_bef_eom, period_wdl); 

if (period_wdl <= model_point_amount_threshold)
	return 0.0;

if (gmwb_defn == FINITE)
	{
	double rem_gmwb_base = gmwb_if_bef_eom - disc_wdls;
	double rem_periods = floor(rem_gmwb_base / period_wdl);
	double rem_partial_wdl = rem_gmwb_base - rem_periods * period_wdl;

	//Calculate the Finite portion
	disc_wdls += period_wdl * (1.0 - pow(v, rem_periods)) / period_disc;
	disc_wdls += rem_partial_wdl * pow(v, rem_periods + 1);
	}
else //gmwb_wdl_period == LIFE
	{
	int max_life = (term_to_omega_age * 12.0) - elapsed_mths;
	double cumm_surv = 1.0;
	double surv_period = 1.0;
	disc_wdls = period_wdl; //For Life comparison to GMWB Base is not needed
	
	for (int i = t + 1; i <= max_life; i = i + 1)
		{
		surv_period = 1.0 - mort_rate_gmwb(i);
		cumm_surv = cumm_surv * surv_period;
		disc_wdls += period_wdl * cumm_surv * pow(1.0 / (1.0 + period_disc), i - t);
		}
	}

return pv_disc * disc_wdls;
}



#line 1 "read_state_of_world_financial.FIA_LIAB.for"                                                                                   
void FIA_LIAB::read_state_of_world_financial(void)
{
static bool first_time = true;

if (mp_id == "mp_time_step")
	{
	init_tax_capzd_prem_amortzn_sched.resize(1);

	return;
	}

if (first_time)
	{
	first_time = false;

	// Create file_name
	xstring state_of_world_financial_file
	= replaceWildcards(state_of_world_financial_file_path
	  + "fia_state_of_world_financial_" + xstring(proj_set_loop_num)
	  + "_" + xstring(proj_set_sub_loop_num) + ".csv");

	OutputFileReader ofr;
	fia_state_of_world_financial_input = ofr.readFile(state_of_world_financial_file.getStdStr(), 
													  {"mp_id",	"init_assets","init_asset_pct",	"stat_res_net_stoch_res","stat_res_net_stoch_res_unhedged",	
													   "stat_res_stoch_res", "stat_res_stoch_res_unhedged",	"rbc_c1", "rbc_c3_stoch_amt", "rbc_c3_stoch_amt_unhedged",
													   "undistrib_earnings", "tax_capzd_prem_amortzn_sched", "tax_bk_prof_ytd",	"tax_tgt_cap_ytd", 
													   "taxable_inc_bk_prof_ytd", "taxable_inc_tgt_cap_ytd", "taxable_inc_carryfwd_avail", "bk_prof_bef_tax_qtd",	
													   "bk_prof_bef_tax_ytd", "bk_prof_aft_tax_qtd", "bk_prof_aft_tax_ytd",	"bk_prof_aft_tax_irr", 
													   "distrib_earnings_irr", "earnings_accum", "tax_earnings_accum_ytd", "taxable_inc_earnings_accum_ytd",
													   "gaap_inc_bef_tax_qtd", "gaap_inc_bef_tax_ytd",	"gaap_inc_aft_tax_qtd",	"gaap_inc_aft_tax_ytd",	"gaap_req_cap"});

	if (!fia_state_of_world_financial_input.size())
		{
		throw FatalError("Could not read FIA State of World Financial File: " 
			                + state_of_world_financial_file + " "
			                + "Please check your data.");
		}
	
	// Create map of segment start positions
	fia_state_of_world_financial_input_pos[xstring(fia_state_of_world_financial_input[0][0])] = 0;

	for (int row = 1; row < fia_state_of_world_financial_input.size(); row++)
		{
		if (!eq(fia_state_of_world_financial_input[row][0], fia_state_of_world_financial_input[row - 1][0]))
			fia_state_of_world_financial_input_pos[fia_state_of_world_financial_input[row][0]] = row;
		}
	}

int fia_state_of_world_financial_row = -1;
if ((fia_state_of_world_financial_input_pos_iter 
     = fia_state_of_world_financial_input_pos.find(mp_id)) != fia_state_of_world_financial_input_pos.end())
	fia_state_of_world_financial_row = fia_state_of_world_financial_input_pos_iter->second;

// Check for model point id in financial file and exit if not found. 
if (fia_state_of_world_financial_row == -1) 
	{
	init_tax_capzd_prem_amortzn_sched.resize(1);
	
	return;
	}

xstring temp_string;

// Initial assets for PBA
if (valn_flag)
	{
	sm_fia_ann_pba[0]->init_assets = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][1].c_str());
	sm_fia_ann_pba[0]->init_asset_pct = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][2].c_str());
	}

// Approximate reserves
if (!valn_flag)
	{
	init_stat_res_net_stoch_res = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][3].c_str());
	init_stat_res_net_stoch_res_unhedged = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][4].c_str());
	init_stat_res_stoch_res = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][5].c_str());
	init_stat_res_stoch_res_unhedged = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][6].c_str());
	}

// Approximate capital
if (!valn_flag)
	{
	init_rbc_c1 = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][7].c_str());
	init_rbc_c3_stoch_amt = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][8].c_str());
	init_rbc_c3_stoch_amt_unhedged = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][9].c_str());
	}

// Undistributed Earnings
if (!valn_flag)
	init_undistrib_earnings = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][10].c_str());

// Future calendar year capitalized premium tax amortization
if (init_tax_capzd_prem_amortzn_sched.size())
	init_tax_capzd_prem_amortzn_sched.resize(0);

temp_string = fia_state_of_world_financial_input[fia_state_of_world_financial_row][11].c_str();
read_from_string(temp_string, init_tax_capzd_prem_amortzn_sched);

// Year to date tax payments
if (!valn_flag)
	{
	init_tax_bk_prof_ytd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][12].c_str());
	init_tax_tgt_cap_ytd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][13].c_str());
	init_taxable_inc_bk_prof_ytd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][14].c_str());
	init_taxable_inc_tgt_cap_ytd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][15].c_str());
	
	if (pricing_flag && tax_loss_treatment == TAX_LOSS_CARRYFORWARD)
		init_taxable_inc_carryfwd_avail = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][16].c_str());
	}
	
// Cumulative Statutory Book Profits
if (!valn_flag)
	{
	init_bk_prof_bef_tax_qtd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][17].c_str());
	init_bk_prof_bef_tax_ytd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][18].c_str());
	init_bk_prof_aft_tax_qtd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][19].c_str());
	init_bk_prof_aft_tax_ytd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][20].c_str());
	init_bk_prof_aft_tax_irr = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][21].c_str());
	init_distrib_earnings_irr = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][22].c_str());
	init_earnings_accum = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][23].c_str());
	init_tax_earnings_accum_ytd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][24].c_str());
	init_taxable_inc_earnings_accum_ytd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][25].c_str());
	}

	// Cumulative GAAP Income items
if (gaap_flag && !valn_flag)
	{
	init_gaap_inc_bef_tax_qtd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][26].c_str());
	init_gaap_inc_bef_tax_ytd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][27].c_str());
	init_gaap_inc_aft_tax_qtd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][28].c_str());
	init_gaap_inc_aft_tax_ytd = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][29].c_str());
	init_gaap_req_cap = atof(fia_state_of_world_financial_input[fia_state_of_world_financial_row][30].c_str());
	}

return;
}



#line 1 "set_fia_account_vars.FIA_LIAB.for"                                                                                   
void FIA_LIAB::set_fia_account_vars(void)
{	
for (int i = 0; i < sm_fia_account.size(); i++)
	sm_fia_account[i]->rates_ptr = rates_ptr;

// Set initial account value for each fund
if (elapsed_mths > 0)
	{
	if (has_fixed)
		sm_fia_account[fixed_element]->init_fund_val = init_fund_val_fixed;
		
	if (has_index0)
		sm_fia_account[index0_element]->init_fund_val = init_fund_val_index0;
			
	if (has_index1)
		sm_fia_account[index1_element]->init_fund_val = init_fund_val_index1;
	
	if (has_index2)
		sm_fia_account[index2_element]->init_fund_val = init_fund_val_index2;
	
	if (has_index3)
		sm_fia_account[index3_element]->init_fund_val = init_fund_val_index3;							
	
	if (has_index4)
		sm_fia_account[index4_element]->init_fund_val = init_fund_val_index4;	
	}

// ***** Calculate total proportion of premium/fund value
if (elapsed_mths > 0)
	{
	if (fund_val_rebal_prop_defn == INITIAL_ACCOUNT_VALUE_ALLOCATION
		&& valn_period == 0)
		{
		// set fv_split_prop based on initial av allocations.
		double total_fv = sm_fia_account[SUM]->init_fund_val;
	
		if (total_fv > 0.0) 
			{	
			for (int i = 0; i < sm_fia_account.size(); i++)
				{
				sm_fia_account[i]->fund_val_split_prop 
				= sm_fia_account[i]->init_fund_val / total_fv;
				}
			}
		}
	else
		{
		// normalize percentages
		double total_rebal_split 
		= init_rebal_pct_fixed
		  + init_rebal_pct_index0
		  + init_rebal_pct_index1
		  + init_rebal_pct_index2
		  + init_rebal_pct_index3
		  + init_rebal_pct_index4;

		if (has_fixed)
			sm_fia_account[fixed_element]->fund_val_split_prop
			= init_rebal_pct_fixed / total_rebal_split;
			
		if (has_index0)
			sm_fia_account[index0_element]->fund_val_split_prop 
			= init_rebal_pct_index0 / total_rebal_split;
				
		if (has_index1)	
			sm_fia_account[index1_element]->fund_val_split_prop
			= init_rebal_pct_index1 / total_rebal_split;
				
		if (has_index2)	
			sm_fia_account[index2_element]->fund_val_split_prop 
			= init_rebal_pct_index2 / total_rebal_split;
				
		if (has_index3)
			sm_fia_account[index3_element]->fund_val_split_prop 
			= init_rebal_pct_index3 / total_rebal_split;
		
		if (has_index4)
			sm_fia_account[index4_element]->fund_val_split_prop 
			= init_rebal_pct_index4 / total_rebal_split;
		}
	}
else // new business, use model point settings
	{
	if (fund_val_rebal_prop_defn == INITIAL_ACCOUNT_VALUE_ALLOCATION
		&& valn_period == 0)
		{
		// normalize if not equal to 1.0
		double total_fv_split 
		= init_fund_val_fixed
		  + init_fund_val_index0
		  + init_fund_val_index1
		  + init_fund_val_index2
		  + init_fund_val_index3
		  + init_fund_val_index4;
	
		if (total_fv_split == 0)
			throw NonFatalError("Total allocation to accounts is zero for model point " + mp_id + ".");
	
		if (has_fixed)
			sm_fia_account[fixed_element]->fund_val_split_prop = init_fund_val_fixed / total_fv_split;
						
		if (has_index0)
			sm_fia_account[index0_element]->fund_val_split_prop = init_fund_val_index0 / total_fv_split;
				
		if (has_index1)	
			sm_fia_account[index1_element]->fund_val_split_prop = init_fund_val_index1 / total_fv_split;
				
		if (has_index2)	
			sm_fia_account[index2_element]->fund_val_split_prop = init_fund_val_index2 / total_fv_split;
				
		if (has_index3)
			sm_fia_account[index3_element]->fund_val_split_prop = init_fund_val_index3 / total_fv_split;
		
		if (has_index4)
			sm_fia_account[index4_element]->fund_val_split_prop = init_fund_val_index4 / total_fv_split;
		}
	else
		{
		// normalize percentages
		double total_rebal_split 
		= init_rebal_pct_fixed
		  + init_rebal_pct_index0
		  + init_rebal_pct_index1
		  + init_rebal_pct_index2
		  + init_rebal_pct_index3
		  + init_rebal_pct_index4;

		if (has_fixed)
			sm_fia_account[fixed_element]->fund_val_split_prop
			= init_rebal_pct_fixed / total_rebal_split;
			
		if (has_index0)
			sm_fia_account[index0_element]->fund_val_split_prop 
			= init_rebal_pct_index0 / total_rebal_split;
				
		if (has_index1)	
			sm_fia_account[index1_element]->fund_val_split_prop
			= init_rebal_pct_index1 / total_rebal_split;
				
		if (has_index2)	
			sm_fia_account[index2_element]->fund_val_split_prop 
			= init_rebal_pct_index2 / total_rebal_split;
				
		if (has_index3)
			sm_fia_account[index3_element]->fund_val_split_prop 
			= init_rebal_pct_index3 / total_rebal_split;
		
		if (has_index4)
			sm_fia_account[index4_element]->fund_val_split_prop 
			= init_rebal_pct_index4 / total_rebal_split;
		}
	}

//Set up fund type and cap and participation rate
if (has_fixed)
	{
	sm_fia_account[fixed_element]->fund_type = "Fixed";
	//sm_fia_account[fixed_element]->crediting_rate_guar_mths = crediting_rate_guar_mths_fixed;
	}
	
if (has_index0)
	{
	sm_fia_account[index0_element]->fund_type = "Indexed";
	sm_fia_account[index0_element]->init_fia_cap = init_cap_rate_index0;
	sm_fia_account[index0_element]->init_part_rate = init_part_rate_index0;
	sm_fia_account[index0_element]->init_sprd_rate = init_sprd_rate_index0;
	sm_fia_account[index0_element]->init_trigger_rate = init_trigger_rate_index0;
	//sm_fia_account[index0_element]->crediting_cap_min = crediting_cap_min_index0;
	//sm_fia_account[index0_element]->crediting_cap_max = crediting_cap_max_index0;
	//sm_fia_account[index0_element]->crediting_rate_guar_mths = crediting_rate_guar_mths_index0;
	}

if (has_index1)
	{
	sm_fia_account[index1_element]->fund_type = "Indexed";
	//sm_fia_account[index1_element]->init_fia_cap = init_cap_rate_index1;
	//sm_fia_account[index1_element]->init_part_rate = init_part_rate_index1;
	//sm_fia_account[index1_element]->crediting_cap_min = crediting_cap_min_index1;
	//sm_fia_account[index1_element]->crediting_cap_max = crediting_cap_max_index1;
	//sm_fia_account[index1_element]->crediting_rate_guar_mths = crediting_rate_guar_mths_index1;
	} 

if (has_index2)
	{
	sm_fia_account[index2_element]->fund_type = "Indexed";
	//sm_fia_account[index2_element]->init_fia_cap = init_cap_rate_index2;
	//sm_fia_account[index2_element]->init_part_rate = init_part_rate_index2;
	//sm_fia_account[index2_element]->crediting_cap_min = crediting_cap_min_index2;
	//sm_fia_account[index2_element]->crediting_cap_max = crediting_cap_max_index2;
	//sm_fia_account[index2_element]->crediting_rate_guar_mths = crediting_rate_guar_mths_index2;
	}

if (has_index3)
	{
	sm_fia_account[index3_element]->fund_type = "Indexed";
	//sm_fia_account[index3_element]->init_fia_cap = init_cap_rate_index3;
	//sm_fia_account[index3_element]->init_part_rate = init_part_rate_index3;
	//sm_fia_account[index3_element]->crediting_cap_min = crediting_cap_min_index3;
	//sm_fia_account[index3_element]->crediting_cap_max = crediting_cap_max_index3;
	//sm_fia_account[index3_element]->crediting_rate_guar_mths = crediting_rate_guar_mths_index3;
	}

if (has_index4)
	{
	sm_fia_account[index4_element]->fund_type = "Indexed";
	//sm_fia_account[index4_element]->init_fia_cap = init_cap_rate_index4;
	//sm_fia_account[index4_element]->init_part_rate = init_part_rate_index4;
	//sm_fia_account[index4_element]->crediting_cap_min = crediting_cap_min_index4;
	//sm_fia_account[index4_element]->crediting_cap_max = crediting_cap_max_index4;
	//sm_fia_account[index4_element]->crediting_rate_guar_mths = crediting_rate_guar_mths_index4;
	}
}



#line 1 "time_between_dates_calc_crbg.FIA_LIAB.for"                                                                                   
double FIA_LIAB::time_between_dates_calc_crbg(xstring start_date, xstring end_date)
{
	int start_date_days;
	int end_date_days;
	double time_difference;

	//Convert the start date into number of days.
	start_date_days = get_yr_from_date(start_date)*360 + get_mth_from_date(start_date)*30 + min(30, get_day_from_date(start_date));

	//Convert the end date into number of days.
	end_date_days = get_yr_from_date(end_date)*360 + get_mth_from_date(end_date)*30 + min(30, get_day_from_date(end_date));

	//Take the difference between the two dates.
	time_difference = end_date_days - start_date_days;

	if (time_difference <= 0)
	{
		throw FatalError("Requested start_date is greater than end_date in time_between_dates_calc_aig.");
	}

	//Convert the time difference between dates into years. (can be partial years)
	time_difference = time_difference/360.;

	return time_difference;
}



#line 1 "validate_data.FIA_LIAB.for"                                                                                   
void FIA_LIAB::validate_data(void) 
{
return;
}



#line 1 "write_reserves.FIA_LIAB.for"                                                                                   
void FIA_LIAB::write_reserves(int time, xstring res_basis, int ann_stream_test, int gmwb_exercise_point) 
{
//Gen2 - writeModel() not supported in Gen2. Future planned update to modify this to produce time step output for both Gen1 and Gen2
/*
xstring group_id = "";
xstring group_id_no = "";
xstring group_id_full = "";

group_id = xstring(fia->mp_id);

if (res_basis == "STAT")
	{
	if (stat_carvm_calc_annuitzn_defn != NOT_APPLICABLE)
		group_id += "_AnnTest_" + xstring(ann_stream_test);

	if (gmwb_flag)
		group_id += "_GMWBExPnt_" + xstring(gmwb_exercise_point);
	}
else if (res_basis == "TAX")
	{
	if (tax_carvm_calc_annuitzn_defn != NOT_APPLICABLE)
		group_id += "_AnnTest_" + xstring(ann_stream_test);

	if (gmwb_flag)
		group_id += "_GMWBExPnt_" + xstring(gmwb_exercise_point);
	}

group_id_no = group_id + "_NoPFWD";
group_id_full = group_id + "_FullPFWD";

group_id_no += "_AtTime_" + xstring(time);
group_id_full += "_AtTime_" + xstring(time);

if (res_basis == "STAT") 
	{
	sm_carvm_stat[0]->writeModel(group_id_no);

	if (sm_carvm_stat.size() > 1)
		sm_carvm_stat[1]->writeModel(group_id_full);
	}
else if (res_basis == "TAX") 
	{
	sm_carvm_tax[0]->writeModel(group_id_no);

	if (sm_carvm_tax.size() > 1)
		sm_carvm_tax[1]->writeModel(group_id_full);
	}
else
	throw FatalError("FIA - write_reserves(): Invalid Reserve Basis " + res_basis);

*/

return;
} 



#line 1 "write_state_of_world_financial.FIA_LIAB.for"                                                                                   
void FIA_LIAB::write_state_of_world_financial(void)
{
if (proj_set_sub_loop_num == valn_periods.size())
	return;

// Create file_name
xstring financial_state_of_world_file
= replaceWildcards(state_of_world_financial_file_path
  + "fia_state_of_world_financial_" + xstring(proj_set_loop_num)
  + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv");

static bool first_time = true;

if (first_time)
	{
	first_time = false;
	struct stat buffer;
	int stat_val;
	stat_val = stat(financial_state_of_world_file.c_str(), &buffer);

	// Delete existing file, to create fresh
	if (stat_val == 0)
		{
		xstring file_name 
		= state_of_world_financial_file_path
	  	+ "fia_state_of_world_financial_" + xstring(proj_set_loop_num)
		  + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

		remove(file_name);
		}
	}

// Do not write financial state of world for model point record used to
//   ensure run through all time steps
if (mp_id == "mp_time_step")
	return;
// Create state of world database
if (!fia_state_of_world_financial_output.is_open())
	{
	fia_state_of_world_financial_output.setf(ios::fixed);
	fia_state_of_world_financial_output.precision(12);

	fia_state_of_world_financial_output.open(financial_state_of_world_file);

	fia_state_of_world_financial_output

	<< "mp_id" << ","       
	<< "init_assets" << "," 
	<< "init_asset_pct" << ","
	<< "stat_res_net_stoch_res" << ","
	<< "stat_res_net_stoch_res_unhedged" << "," 
	<< "stat_res_stoch_res" << ","          
	<< "stat_res_stoch_res_unhedged" << "," 
	<< "rbc_c1" << ","
	<< "rbc_c3_stoch_amt" << ","           
	<< "rbc_c3_stoch_amt_unhedged" << ","  
	<< "undistrib_earnings" << ","         
	<< "tax_capzd_prem_amortzn_sched" << ","
	<< "tax_bk_prof_ytd" << ","           
	<< "tax_tgt_cap_ytd" << ","           
	<< "taxable_inc_bk_prof_ytd" << ","   
	<< "taxable_inc_tgt_cap_ytd" << ","   
	<< "taxable_inc_carryfwd_avail" << ","
	<< "bk_prof_bef_tax_qtd" << ","       
	<< "bk_prof_bef_tax_ytd" << ","       
	<< "bk_prof_aft_tax_qtd" << ","       
	<< "bk_prof_aft_tax_ytd" << ","       
	<< "bk_prof_aft_tax_irr" << ","      
	<< "distrib_earnings_irr" << ","
	<< "earnings_accum" << ","
	<< "tax_earnings_accum_ytd" << ","
	<< "taxable_inc_earnings_accum_ytd" << ","      
	<< "gaap_inc_bef_tax_qtd" << ","      
	<< "gaap_inc_bef_tax_ytd" << ","      
	<< "gaap_inc_aft_tax_qtd" << ","      
	<< "gaap_inc_aft_tax_ytd" << ","      
	<< "gaap_req_cap" << endl;           
	}

SmartArray <double> temp_array;
double init_assets = 0.0;
double init_asset_pct = 0.0;
double stat_res_net_stoch_res = 0.0;
double stat_res_net_stoch_res_unhedged = 0.0;
double stat_res_stoch_res = 0.0;
double stat_res_stoch_res_unhedged = 0.0;
double rbc_c1 = 0.0;
double rbc_c3_stoch_amt = 0.0;
double rbc_c3_stoch_amt_unhedged = 0.0;
double undistrib_earnings = 0.0;
xstring cpt_amz_string = "";
double tax_bk_prof_ytd = 0.0;
double tax_tgt_cap_ytd = 0.0;
double taxable_inc_bk_prof_ytd = 0.0;
double taxable_inc_tgt_cap_ytd = 0.0;
double taxable_inc_carryfwd_avail = 0.0;
double bk_prof_bef_tax_qtd = 0.0;
double bk_prof_bef_tax_ytd = 0.0;
double bk_prof_aft_tax_qtd = 0.0;
double bk_prof_aft_tax_ytd = 0.0;
double bk_prof_aft_tax_irr = 0.0;
double distrib_earnings_irr = 0.0;
double tax_earnings_accum_ytd = 0.0;
double taxable_inc_earnings_accum_ytd = 0.0;
double gaap_inc_bef_tax_qtd = 0.0;
double gaap_inc_bef_tax_ytd = 0.0;
double gaap_inc_aft_tax_qtd = 0.0;
double gaap_inc_aft_tax_ytd = 0.0;
double gaap_req_cap = 0.0;

// Capture values for sched_tax_capzd_prem_amortzn
int size = max(12, t_high);
int array_size = 0;

if ((size + proj_start_mth - 1) % 12 == 0)
	array_size = ((size + proj_start_mth - 1) / 12) + 1;
else
	array_size = ((size + proj_start_mth - 1) / 12) + 2;

init_assets = liab_and_surp(final_period);
	
if (valn_period == 1)
	init_asset_pct = sm_fia_ann_pba[0]->init_asset_pct;

else if (fabs(inv_asset(final_period)) > aggregate_amount_threshold)
	init_asset_pct
	= (stat_res(final_period) - reins_stat_res(final_period)) 
 	/ (inv_asset(final_period));
else
	init_asset_pct = 0.0;

stat_res_net_stoch_res = this->stat_res_net_stoch_res(final_period);
stat_res_net_stoch_res_unhedged = this->stat_res_net_stoch_res_unhedged(final_period);
stat_res_stoch_res = this->stat_res_stoch_res(final_period);
stat_res_stoch_res_unhedged = this->stat_res_stoch_res_unhedged(final_period);

if (tgt_cap_flag)
	{
	rbc_c1 = this->rbc_c1(final_period);
	rbc_c3_stoch_amt = this->rbc_c3_stoch_amt(final_period);
	rbc_c3_stoch_amt_unhedged = this->rbc_c3_stoch_amt_unhedged(final_period);
	}

if (prof_distribn_mode == QUARTERLY
	&& (xint(cal_mth(final_period)) % 3 != 0))

if ((prof_distribn_mode == QUARTERLY
	 && (xint(cal_mth(final_period)) % 3 != 0))
	|| ((prof_distribn_mode == ANNUAL
	     && (cal_mth(final_period) != 12))))
	undistrib_earnings = this->undistrib_earnings(final_period);

temp_array.resize(array_size);
for (int i = 0; i < array_size; i++)
	temp_array[i] = tax_capzd_prem_amortzn_sched(final_period, i);
		
cpt_amz_string = write_array_to_string(temp_array, 0, array_size - 1);

for (int i = 0; i < array_size; i++)
	temp_array[i] = 0.0;

//if (cal_mth(final_period) != 12)
//	{
	tax_bk_prof_ytd = this->tax_bk_prof_ytd(final_period);
	tax_tgt_cap_ytd = this->tax_tgt_cap_ytd(final_period);
	taxable_inc_bk_prof_ytd = this->taxable_inc_bk_prof_ytd(final_period);
	taxable_inc_tgt_cap_ytd = this->taxable_inc_tgt_cap_ytd(final_period);
	tax_earnings_accum_ytd = this->tax_earnings_accum_ytd(final_period);
	taxable_inc_earnings_accum_ytd = this->taxable_inc_earnings_accum_ytd(final_period);
//	}	

if (pricing_flag && tax_loss_treatment == TAX_LOSS_CARRYFORWARD)
	taxable_inc_carryfwd_avail = this->taxable_inc_carryfwd_avail(final_period);

if (prof_distribn_mode == QUARTERLY
	&& (xint(cal_mth(final_period)) % 3 != 0))
	{
	bk_prof_bef_tax_qtd = this->bk_prof_bef_tax_qtd(final_period);
	bk_prof_aft_tax_qtd = this->bk_prof_aft_tax_qtd(final_period);
	
	if (gaap_flag)
		{
		gaap_inc_bef_tax_qtd = this->gaap_inc_bef_tax_qtd(final_period);
		gaap_inc_aft_tax_qtd = this->gaap_inc_aft_tax_qtd(final_period);
		}
	}	

if (prof_distribn_mode == ANNUAL
	&& (cal_mth(final_period) != 12))
	{
	bk_prof_bef_tax_ytd = this->bk_prof_bef_tax_ytd(final_period);
	bk_prof_aft_tax_ytd = this->bk_prof_aft_tax_ytd(final_period);
	
	if (gaap_flag)
		{
		gaap_inc_bef_tax_ytd = this->gaap_inc_bef_tax_ytd(final_period);
		gaap_inc_aft_tax_ytd = this->gaap_inc_aft_tax_ytd(final_period);
		}
	}

if (pricing_flag)
	{
	bk_prof_aft_tax_irr = this->bk_prof_aft_tax_irr(final_period);
	distrib_earnings_irr = this->distrib_earnings_irr(final_period);
	}

if (gaap_flag)
	gaap_req_cap = this->gaap_req_cap(final_period);

fia_state_of_world_financial_output
<< mp_id << ","
<< init_assets << ","
<< init_asset_pct << ","
<< stat_res_net_stoch_res << ","
<< stat_res_net_stoch_res_unhedged << ","
<< stat_res_stoch_res << ","
<< stat_res_stoch_res_unhedged << ","
<< rbc_c1 << ","
<< rbc_c3_stoch_amt << ","
<< rbc_c3_stoch_amt_unhedged << ","
<< undistrib_earnings << "," 
<< cpt_amz_string << ","
<< tax_bk_prof_ytd << ","
<< tax_tgt_cap_ytd << ","
<< taxable_inc_bk_prof_ytd << ","
<< taxable_inc_tgt_cap_ytd << ","
<< taxable_inc_carryfwd_avail << ","
<< bk_prof_bef_tax_qtd << ","
<< bk_prof_bef_tax_ytd << ","
<< bk_prof_aft_tax_qtd << ","
<< bk_prof_aft_tax_ytd << ","
<< bk_prof_aft_tax_irr << ","
<< distrib_earnings_irr << ","
<< earnings_accum(final_period) << ","
<< tax_earnings_accum_ytd << ","
<< taxable_inc_earnings_accum_ytd << ","
<< gaap_inc_bef_tax_qtd << ","
<< gaap_inc_bef_tax_ytd << ","
<< gaap_inc_aft_tax_qtd << ","
<< gaap_inc_aft_tax_ytd << ","
<< gaap_req_cap << endl;  

return;
}



#line 1 "write_state_of_world_mp.FIA_LIAB.for"                                                                                   
void FIA_LIAB::write_state_of_world_mp(void)
{
static bool first_time = true;

// Must always write at least one record when this function is called
if (commencement_period < final_period
    && policies_inf(final_period) < model_point_amount_threshold
    && mp_id != "mp_time_step")
    return;

xstring data_file_name_local = replaceWildcards(data_file_name);
int num_loops = 1;

xstring fia_state_of_world_file
= xstring(data_file_name_local(0 , data_file_name_local.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

// Remove any old file
if (first_time)
	{
	first_time = false;

	if (valn_period == 0 || (isMainModel && pricing_flag))
		num_loops = 2;

	struct stat buffer;
	int stat_val;
	stat_val = stat(fia_state_of_world_file.c_str(), &buffer);

	// Delete existing file, so a new file can be created
	if (stat_val == 0)
		{
		xstring file_name
		= xstring(data_file_name_local(0 , data_file_name_local.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
		  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

		remove(file_name);
		}
	}

if (!fia_state_of_world_mp_output.is_open())
	{
   	fia_state_of_world_mp_output.setf(ios::fixed);
	fia_state_of_world_mp_output.precision(12);

	fia_state_of_world_mp_output.open(fia_state_of_world_file);

	// Write header
	fia_state_of_world_mp_output                 // Values from inforce mp
	<< "group" << ","           // col 1 = group
	<< "seg_id" << ","           // col 2 = seg_id
	<< "mp_id" << ","           // col 3 = mp_id
	<< "use_mp" << ","           // col 4 = use_mp
	//<< "issue_date" << ","           // col 5 = issue_date
	<< "plan_code" << ","           // col 6 = plan_code	
	<< "broker_crbg" << ","
	<< "prem_band" << ","
	<< "gmwb_code" << ","
	<< "crediting_strategy_crbg" << ","
	//<< "stat_valn_code" << ","      // col 7 = stat_valn_code
	//<< "tax_valn_code" << ","       // col 8 = tax_valn_code
	<< "issue_age_male_crbg" << ","           
	<< "issue_age_female_crbg" << "," 
	<< "gender_mp" << ","           
	<< "gender_aft_inc" << "," 
	<< "male_sex_pct" << ","          
	<< "single_prem" << ","           
	//<< "reins_pct" << ","           
	<< "init_policies" << ","           // col 14 = init_policies
	//<< "init_contract_val" << ","           // col 15 = init_contract_val	
	//<< "host_accrual_rate" << ","           // col 18 = host_accrual_rate
	//<< "init_host_val" << ","           // col 19 = init_host_val	
	<< "grop_ind_crbg" << ","
	<< "gmab_ind_crbg" << ","
	<< "gmwb_ind" << ","          
	<< "gmwb_exercise_yrs" << ","           
	<< "init_fund_val_index0" << "," 
	<< "init_rebal_pct_index0" << "," 
	<< "init_policies_male_crbg" << ","
	<< "init_policies_female_crbg" << ","
	<< "init_policies_joint_crbg" << ","
	<< "init_cash_val" << "," 
	<< "init_cash_val_no_mva" << "," 
	<< "init_fund_val_boy" << "," 
	<< "init_min_wdl_val" << "," 
	<< "init_prem_net_wdl" << "," 
	<< "init_prem_prop_wdl" << "," 
	<< "init_gmab_av" << "," 
	<< "init_crediting_rate_cumul" << "," 	         
	//<< "init_gmwb_fund_val" << ","           // col 23 = init_gmwb_fund_val
	<< "init_gmwb_prem" << ","           
	<< "init_gmwb_max_wdl_amt" << ","    
	<< "init_gmwb_max_ann_wdl_pct" << ","  
	<< "init_gmwb_entitlement_remaining" << ","  
	<< "init_gmwb_income_credit_base" << ","  
	<< "init_gmwb_wdl_excess_ind" << ","  
	<< "init_gmwb_wdl_util_level" << ","  
	<< "init_gmwb_wdl_util_pct" << ","  
	<< "ann_gmwb_claim_yr" << ","  
   //<< "gmwb_mrb_req_prof_chg" << ","    // col 26 = gmwb_mrb_req_prof_chg 
	<< "init_withdrl_cumul" << ","          
	<< "init_pfwd_curr_pol_yr" << ","           
	<< "init_pfwd_entitlement" << ","           
	<< "init_hedge_budget" << ","  	
	<< "init_index_val" << ","  
	<< "index_val_beg_term" << ","  
	<< "init_opt_cost_beg_term" << ","  
	<< "init_hedge_mkt_val_per_unit" << ","  
	<< "crediting_rate_fixed" << ","           
	<< "init_part_rate_index0" << ","           
	<< "init_cap_rate_index0" << ","           
	<< "init_sprd_rate_index0" << ","
	<< "init_trigger_rate_index0" << "," 
	<< "init_eprs_part_rate" << "," 
	<< "fa_pricing_rate" << "," 
	<< "asset_yld_for_rate_setting" << "," 
	<< "myga_term_mth_elapsed_eom" << "," 
	<< "myga_current_term"<< ","
	<< "init_prem_bonus_base"<< "," 
	<< "init_min_accum_val"<< "," 
	<< "fund_val_beg_term"<< "," 
	<< "init_comm_subject_to_chargeback" << endl;   
	//<< "init_stat_res_carvm" << ","                // col 69 = init_stat_res_carvm
	//<< "init_tax_res_carvm"					//col 70 = init_tax_res_carvm
				   
	}

// write information
static int counter = 1;
xstring group_mp;
xstring rec_id_mp;
xstring include_mp;
xstring issue_date_mp;
double policies_inf = 0.0;
double fund_val_fixed = 0.0;
double fund_val_idx0 = 0.0;
double fund_val_idx1 = 0.0;
double fund_val_idx2 = 0.0;
double fund_val_idx3 = 0.0;
double fund_val_idx4 = 0.0;
double fund_val_split_prop_fixed = 0.0;
double fund_val_split_prop_idx0 = 0.0;
double fund_val_split_prop_idx1 = 0.0;
double fund_val_split_prop_idx2 = 0.0;
double fund_val_split_prop_idx3 = 0.0;
double fund_val_split_prop_idx4 = 0.0;
double single_prem_mp = 0.0;
double reins_pct_mp = 0.0;
double contract_val = 0.0;
double crediting_part_rate_index0 = 0.0;
double crediting_part_rate_index1 = 0.0;
double crediting_part_rate_index2 = 0.0;
double crediting_part_rate_index3 = 0.0;
double crediting_part_rate_index4 = 0.0;
double crediting_cap_rate_index0 = 0.0;
double crediting_cap_rate_index1 = 0.0;
double crediting_cap_rate_index2 = 0.0;
double crediting_cap_rate_index3 = 0.0;
double crediting_cap_rate_index4 = 0.0;
double crediting_sprd_rate_index0 = 0.0;
double init_eprs_part_rate = 0.0;
double crediting_trigger_rate_index0 = 0.0;
double host_accrual_rate = 0.0;
double host_contract_val = 0.0;
double option_budget = 0.0;
double prem_cumul = 0.0;
double pfwd_surr_cumul = 0.0;
double pfwd_surr_curr_pol_yr = 0.0;
double pfwd_entitlement_remaining_e = 0.0;
double comm_subject_to_chargeback_e = 0.0;
double stat_carvm_res = 0.0;
double tax_carvm_res = 0.0;
double gmwb_fund_val_inf = 0.0;
double gmwb_prem_inf = 0.0;
double gmwb_max_wdl_amt = 0.0;
double gmwb_mrb_req_prof_chg = 0.0;
double init_policies_male = 0.0;
double init_policies_female = 0.0;
double init_policies_joint = 0.0;
double myga_current_term = 0.0;
double fa_pricing_rate = 0.0;
double asset_yld_for_rate_setting = 0.0;
double init_cash_val = 0.0;
double init_cash_val_no_mva = 0.0;
double myga_term_mth_elapsed_eom = 0.0;
double init_fund_val_boy = 0.0;
double init_min_wdl_val = 0.0;
double init_prem_net_wdl = 0.0;
double init_prem_prop_wdl = 0.0;
double init_gmab_av = 0.0;
double init_crediting_rate_cumul = 0.0;
double init_gmwb_max_ann_wdl_pct = 0.0;
double init_gmwb_entitlement_remaining = 0.0;
double init_gmwb_income_credit_base = 0.0;
double init_gmwb_wdl_excess_ind = 0.0;
double init_gmwb_wdl_util_level = 0.0;
double init_gmwb_wdl_util_pct = 0.0;
double ann_gmwb_claim_yr = 0.0;
double init_hedge_budget = 0.0;
double index_val_beg_term = 0.0;
double init_index_val = 0.0;
double init_opt_cost_beg_term = 0.0;
double init_hedge_mkt_val_per_unit = 0.0;
double init_prem_bonus_base = 0.0;
double init_min_accum_val = 0.0;
double fund_val_beg_term = 0.0;

for (int loop = 1; loop <= 2; loop++)
	{
	// Create dummy model point for scenario time step processing during loop 1
	// Create real model points during loop 2
	if (loop == 1 && num_loops == 1)
		continue;
	
	if (loop == 1)
		{
		group_mp = "mp_time_step";
		rec_id_mp = "mp_time_step";
		include_mp = "Yes";
		
		if (isMainModel && pricing_flag)
			issue_date_mp = add_mths_to_date(proj_date_adj, 1 - elapsed_mths);
		else // The issue date is the period after the maximum valuation period
			issue_date_mp = add_mths_to_date(proj_date_adj, atoi(xstring(valn_periods[valn_periods.size() - 1])) + 2);

		single_prem_mp = .000001;
		policies_inf = .000001;
		fund_val_fixed = .000001;
		fund_val_split_prop_fixed = 1.0;
		}
	else
		{
		if (isMainModel && pricing_flag && mp_id == "mp_time_step")
			continue;

		group_mp = get_base_group_name(group, true);
		rec_id_mp = mp_id;
		include_mp = use_mp;
		issue_date_mp = this->issue_date_mp;
		reins_pct_mp = reins_pct;
		fund_val_fixed = 0.0;
		fund_val_split_prop_fixed = 0.0;
		
		if (gmwb_flag)
			{
			gmwb_max_wdl_amt = this->gmwb_max_wdl_amt(final_period) * surv_period(final_period);  
			gmwb_prem_inf = this->gmwb_income_base_e_crbg(final_period);
			init_gmwb_max_ann_wdl_pct = this->gmwb_max_ann_wdl_pct_crbg(final_period);
			init_gmwb_entitlement_remaining = this->gmwb_entitlement_remaining_e_crbg(final_period);
			init_gmwb_income_credit_base = this->gmwb_income_credit_base_e_crbg(final_period);
			init_gmwb_wdl_excess_ind = this->gmwb_wdl_excess_ind_e_crbg(final_period);
			init_gmwb_wdl_util_level = this->gmwb_wdl_uti_level_crbg(final_period);
			init_gmwb_wdl_util_pct = this->gmwb_wdl_util_pct_crbg(final_period);
			ann_gmwb_claim_yr = this->ann_gmwb_claim_yr_crbg(final_period);
			}

		if (elapsed_mths + final_period > 0)
			{
			//MO gross_prem_annualzd = this->gross_prem_annualzd(final_period);
			policies_inf = this->policies_inf(final_period);
			contract_val = this->contract_val(final_period);
			option_budget = this->opt_budget(final_period);	
			single_prem_mp = this->prem_cumul(final_period);
			pfwd_surr_cumul = this->pfwd_surr_cumul(final_period);
			pfwd_surr_curr_pol_yr = this->pfwd_surr_curr_pol_yr(final_period);
			pfwd_entitlement_remaining_e = this->pfwd_entitlement_remaining_e(final_period);
			comm_subject_to_chargeback_e = this->comm_subject_to_chargeback_e(final_period);
			stat_carvm_res = this->stat_res_carvm(final_period);
			tax_carvm_res = this->tax_res_carvm(final_period);
			init_policies_male = this->policies_male_inf_crbg(final_period);
			init_policies_female = this->policies_female_inf_crbg(final_period);
			init_policies_joint = this->policies_joint_inf_crbg(final_period);
			myga_current_term = this->myga_current_term_crbg(final_period);
			myga_term_mth_elapsed_eom = this->myga_term_mth_elapsed_eom_crbg(final_period);
			asset_yld_for_rate_setting = this->asset_yld_fa_rate_setting_crbg(final_period);
			init_cash_val = this->cash_val(final_period);
			init_cash_val_no_mva = this->cash_val_wo_mva(final_period);
			init_fund_val_boy = this->fund_val_boy_e_crbg(final_period);
			init_min_wdl_val = this->min_wdl_val_e_crbg(final_period);
			init_prem_net_wdl = this->prem_cumul_net_wdl_crbg(final_period);
			init_prem_prop_wdl = this->prem_cumul_prop_wdl_crbg(final_period);
			init_crediting_rate_cumul = this->crediting_rate_cumul_crbg(final_period);
			init_prem_bonus_base = this->prem_bonus_base_e_crbg(final_period);
			init_min_accum_val = this->min_accum_val_e_crbg(final_period);

			if (gaap_flag)
				{
				host_accrual_rate = sm_fia_sfas97rd[0]->host_accrual_rate;
				host_contract_val = sm_fia_sfas97rd[0]->host_contract_val(final_period);
				}

			// Update mrb required profit charge amounts 
			if (gaap_flag && elapsed_mths <= 0)
				{
				gmwb_mrb_req_prof_chg = sm_fia_mrb[0]->gmwb_req_prof_chg(final_period);
				}				
			}
		else // Not issued yet
			{
			policies_inf = init_policies;
			}
		
		if (has_fixed)
			{
			if (elapsed_mths + final_period > 0)
				fund_val_fixed = sm_fia_account[fixed_element]->fund_val_e(final_period);	
			else
				fund_val_fixed = init_fund_val_fixed;
	
			fund_val_split_prop_fixed = sm_fia_account[fixed_element]->fund_val_split_prop;
			fa_pricing_rate = sm_fia_account[fixed_element]->fa_pricing_rate_crbg(final_period);
			init_gmab_av = sm_fia_account[fixed_element]->gmab_av_e_crbg(final_period);
			init_hedge_budget = sm_fia_account[fixed_element]->opt_budget(final_period);
			}
		
		if (has_index0)
			{
			if (elapsed_mths + final_period > 0)
				fund_val_idx0 = sm_fia_account[index0_element]->fund_val_e(final_period);
			else
				fund_val_idx0 = init_fund_val_index0;

			fund_val_split_prop_idx0 = sm_fia_account[index0_element]->fund_val_split_prop;
			crediting_part_rate_index0 = sm_fia_account[index0_element]->crediting_part_rate(final_period);
			crediting_cap_rate_index0 = sm_fia_account[index0_element]->crediting_cap_rate(final_period);
			crediting_sprd_rate_index0 = sm_fia_account[index0_element]->crediting_sprd_rate_crbg(final_period);
			crediting_trigger_rate_index0 = sm_fia_account[index0_element]->crediting_trigger_rate_crbg(final_period);
			init_eprs_part_rate = sm_fia_account[index0_element]->enhanced_part_rate_crbg(final_period);
			fa_pricing_rate = sm_fia_account[index0_element]->fa_pricing_rate_crbg(final_period);
			init_hedge_budget = sm_fia_account[index0_element]->opt_budget(final_period);
			index_val_beg_term = sm_fia_account[index0_element]->index_val_beg_term_crbg(final_period);
			init_hedge_mkt_val_per_unit = sm_fia_account[index0_element]->hedge_mkt_val_per_unit_notional(final_period);
			init_gmab_av = sm_fia_account[index0_element]->gmab_av_e_crbg(final_period);
			init_index_val = sm_fia_account[index0_element]->index_val(final_period);
			init_opt_cost_beg_term = sm_fia_account[index0_element]->opt_cost_beg_term_crbg(final_period);
			fund_val_beg_term = sm_fia_account[index0_element]->fund_val_beg_term_e_crbg(final_period);
			}
		
		if (has_index1)
			{
			if (elapsed_mths + final_period > 0)
				fund_val_idx1 = sm_fia_account[index1_element]->fund_val_e(final_period);
			else
				fund_val_idx1 = init_fund_val_index1;

			fund_val_split_prop_idx1 = sm_fia_account[index1_element]->fund_val_split_prop;
			crediting_part_rate_index1 = sm_fia_account[index1_element]->crediting_part_rate(final_period);
			crediting_cap_rate_index1 = sm_fia_account[index1_element]->crediting_cap_rate(final_period);
			}
		
		if (has_index2)
			{
			if (elapsed_mths + final_period > 0)
				fund_val_idx2 = sm_fia_account[index2_element]->fund_val_e(final_period);
			else
				fund_val_idx2 = init_fund_val_index2;

			fund_val_split_prop_idx2 = sm_fia_account[index2_element]->fund_val_split_prop;
			crediting_part_rate_index2 = sm_fia_account[index2_element]->crediting_part_rate(final_period);
			crediting_cap_rate_index2 = sm_fia_account[index2_element]->crediting_cap_rate(final_period);
			}
		
		if (has_index3)
			{
			if (elapsed_mths + final_period > 0)
				fund_val_idx3 = sm_fia_account[index3_element]->fund_val_e(final_period);
			else
				fund_val_idx3 = init_fund_val_index3;

			fund_val_split_prop_idx3 = sm_fia_account[index3_element]->fund_val_split_prop;
			crediting_part_rate_index3 = sm_fia_account[index3_element]->crediting_part_rate(final_period);
			crediting_cap_rate_index3 = sm_fia_account[index3_element]->crediting_cap_rate(final_period);
			}
		
		if (has_index4)
			{
			if (elapsed_mths + final_period > 0)
				fund_val_idx4 = sm_fia_account[index4_element]->fund_val_e(final_period);
			else
				fund_val_idx4 = init_fund_val_index4;

			fund_val_split_prop_idx4 = sm_fia_account[index4_element]->fund_val_split_prop;
			crediting_part_rate_index4 = sm_fia_account[index4_element]->crediting_part_rate(final_period);
			crediting_cap_rate_index4 = sm_fia_account[index4_element]->crediting_cap_rate(final_period);
			}

		gmwb_mrb_req_prof_chg = this->gmwb_mrb_req_prof_chg;

		// Update mrb required profit charge amounts 
		if (gaap_flag && elapsed_mths <= 0
			&& elapsed_mths + final_period > 0)
			{
			gmwb_mrb_req_prof_chg = sm_fia_mrb[0]->gmwb_req_prof_chg(final_period);
			}
		}
		
	fia_state_of_world_mp_output
	<< group_mp << ","           
	<< seg_id << ","           
	<< rec_id_mp << ","           
	<< include_mp << ","           
	//<< issue_date_mp << ","           
	<< plan_code << ","   
	<< broker_crbg << ","
	<< prem_band << ","
	<< gmwb_code << ","  
	<< crediting_strategy_crbg << ","        
	<< issue_age_male_crbg << ","  
	<< issue_age_female_crbg << "," 
	<< gender_mp << ","    
	<< gender_aft_inc << ","  
	<< male_sex_pct << ","           
	<< single_prem_mp << ","                
	<< policies_inf << ","           
	<< grop_ind_crbg << ","   
	<< gmab_ind_crbg << ","   
	<< gmwb_ind << ","           
	<< gmwb_exercise_yrs << ","  
	<< fund_val_idx0 << ","
	<< fund_val_split_prop_idx0 << "," 
	<< init_policies_male << ","
	<< init_policies_female << ","
	<< init_policies_joint << ","
	<< init_cash_val << ","
	<< init_cash_val_no_mva << ","
	<< init_fund_val_boy << ","    
	<< init_min_wdl_val << ","
	<< init_prem_net_wdl << ","
	<< init_prem_prop_wdl << ","
	<< init_gmab_av << ","
	<< init_crediting_rate_cumul << ","	
	<< gmwb_prem_inf << ","           
	<< gmwb_max_wdl_amt << ","
	<< init_gmwb_max_ann_wdl_pct << ","
	<< init_gmwb_entitlement_remaining << ","
	<< init_gmwb_income_credit_base << ","
	<< init_gmwb_wdl_excess_ind << ","
	<< init_gmwb_wdl_util_level << ","
	<< init_gmwb_wdl_util_pct << ","
	<< ann_gmwb_claim_yr << ","
	<< pfwd_surr_cumul << ","      
	<< pfwd_surr_curr_pol_yr << ","   
	<< pfwd_entitlement_remaining_e << ","      
	<< init_hedge_budget << "," 	   	
	<< init_index_val << "," 
	<< index_val_beg_term << "," 
	<< init_opt_cost_beg_term << ","
	<< init_hedge_mkt_val_per_unit << "," 
	<< crediting_rate_fixed << "," 
	<< crediting_part_rate_index0 << ","                    
	<< crediting_cap_rate_index0 << ","    
	<< crediting_sprd_rate_index0 << ","
	<< crediting_trigger_rate_index0 << "," 
	<< init_eprs_part_rate << "," 
	<< fa_pricing_rate << "," 
	<< asset_yld_for_rate_setting << "," 
	<< myga_term_mth_elapsed_eom << "," 
	<< myga_current_term << "," 
	<< init_prem_bonus_base << "," 
	<< init_min_accum_val << "," 
	<< fund_val_beg_term << "," 
	<< comm_subject_to_chargeback_e << endl;  

	counter++;
	}

return;
}



void FIA_LIAB::Terminator()
{

fia_state_of_world_mp_output.close();
fia_state_of_world_financial_output.close(); 

}

FunctionPtr FIA_LIAB::RegisterTerminatorOnce = []() {
    ::PushTerminator(Terminator);
    RegisterTerminatorOnce = NoOp;
};

	static FIA_LIAB_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (FIA_LIAB_UDF::*dPXi) (int);
typedef double (FIA_LIAB_UDF::*dPXid) (int, double);
typedef double (FIA_LIAB_UDF::*dPF) ();
typedef double (FIA_LIAB_UDF::*dPFd) (double);
typedef int (FIA_LIAB_UDF::*iPF) ();
typedef int (FIA_LIAB_UDF::*iPFi) (int);
typedef xstring (FIA_LIAB_UDF::*sPF) ();
typedef xstring (FIA_LIAB_UDF::*sPFs) (xstring);

const CashFlowCommonData FIA_LIAB::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "acq_exp", "fia_liab_acq_exp",  "acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_acq_exp, 'B','Y', '3', 'C', (size_t)&modelOffset->acq_exp),
	CashFlowCommonData(2, "admin_fee", "fia_liab_admin_fee",  "admin_fee",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_admin_fee, 'B','Y', '3', 'C', (size_t)&modelOffset->admin_fee),
	CashFlowCommonData(3, "age_last", "fia_liab_age_last",  "age_last",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_age_last, 'B','N', '3', 'C', (size_t)&modelOffset->age_last),
	CashFlowCommonData(4, "ann_benefits_eom", "fia_liab_ann_benefits_eom",  "ann_benefits_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_ann_benefits_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->ann_benefits_eom),
	CashFlowCommonData(5, "ann_claims_gmwb", "fia_liab_ann_claims_gmwb",  "ann_claims_gmwb",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_ann_claims_gmwb, 'E','Y', '3', 'P', (size_t)&modelOffset->ann_claims_gmwb),
	CashFlowCommonData(6, "ann_gmwb_cash_flow_crbg", "fia_liab_ann_gmwb_cash_flow_crbg",  "ann_gmwb_cash_flow_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_ann_gmwb_cash_flow_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->ann_gmwb_cash_flow_crbg),
	CashFlowCommonData(7, "ann_gmwb_claim_yr_crbg", "fia_liab_ann_gmwb_claim_yr_crbg",  "ann_gmwb_claim_yr_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_ann_gmwb_claim_yr_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->ann_gmwb_claim_yr_crbg),
	CashFlowCommonData(8, "ann_gmwb_pip_pct_crbg", "fia_liab_ann_gmwb_pip_pct_crbg",  "ann_gmwb_pip_pct_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_ann_gmwb_pip_pct_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->ann_gmwb_pip_pct_crbg),
	CashFlowCommonData(9, "ann_gmwb_wdl_grossed_up_crbg", "fia_liab_ann_gmwb_wdl_grossed_up_crbg",  "ann_gmwb_wdl_grossed_up_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_ann_gmwb_wdl_grossed_up_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->ann_gmwb_wdl_grossed_up_crbg),
	CashFlowCommonData(10, "annuitzn_rate", "fia_liab_annuitzn_rate",  "annuitzn_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_annuitzn_rate, 'E','N', '3', 'C', (size_t)&modelOffset->annuitzn_rate),
	CashFlowCommonData(11, "annuitzn_rate_mthly", "fia_liab_annuitzn_rate_mthly",  "annuitzn_rate_mthly",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_annuitzn_rate_mthly, 'E','N', '3', 'C', (size_t)&modelOffset->annuitzn_rate_mthly),
	CashFlowCommonData(12, "asset_yld", "fia_liab_asset_yld",  "asset_yld",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_asset_yld, 'E','N', '3', 'C', (size_t)&modelOffset->asset_yld),
	CashFlowCommonData(13, "asset_yld_fa_rate_setting_crbg", "fia_liab_asset_yld_fa_rate_setting_crbg",  "asset_yld_fa_rate_setting_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_asset_yld_fa_rate_setting_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->asset_yld_fa_rate_setting_crbg),
	CashFlowCommonData(14, "asset_yld_inv", "fia_liab_asset_yld_inv",  "asset_yld_inv",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_asset_yld_inv, 'E','N', '3', 'C', (size_t)&modelOffset->asset_yld_inv),
	CashFlowCommonData(15, "asset_yld_inv_adj_crbg", "fia_liab_asset_yld_inv_adj_crbg",  "asset_yld_inv_adj_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_asset_yld_inv_adj_crbg, 'E','N', '3', 'C', (size_t)&modelOffset->asset_yld_inv_adj_crbg),
	CashFlowCommonData(16, "asset_yld_less_dflt", "fia_liab_asset_yld_less_dflt",  "asset_yld_less_dflt",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_asset_yld_less_dflt, 'E','N', '3', 'P', (size_t)&modelOffset->asset_yld_less_dflt),
	CashFlowCommonData(17, "asset_yld_less_dflt_inv", "fia_liab_asset_yld_less_dflt_inv",  "asset_yld_less_dflt_inv",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_asset_yld_less_dflt_inv, 'E','N', '3', 'P', (size_t)&modelOffset->asset_yld_less_dflt_inv),
	CashFlowCommonData(18, "attained_age", "fia_liab_attained_age",  "attained_age",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_attained_age, 'E','N', '3', 'P', (size_t)&modelOffset->attained_age),
	CashFlowCommonData(19, "avg_coupon_rt_crbg", "fia_liab_avg_coupon_rt_crbg",  "avg_coupon_rt_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_avg_coupon_rt_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->avg_coupon_rt_crbg),
	CashFlowCommonData(20, "bef_tax_yld", "fia_liab_bef_tax_yld",  "bef_tax_yld",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_bef_tax_yld, 'E','N', '3', 'C', (size_t)&modelOffset->bef_tax_yld),
	CashFlowCommonData(21, "bk_prof_aft_tax", "fia_liab_bk_prof_aft_tax",  "bk_prof_aft_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_bk_prof_aft_tax, 'E','Y', '3', 'C', (size_t)&modelOffset->bk_prof_aft_tax),
	CashFlowCommonData(22, "bk_prof_aft_tax_for_pv", "fia_liab_bk_prof_aft_tax_for_pv",  "bk_prof_aft_tax_for_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_bk_prof_aft_tax_for_pv, 'E','Y', '3', 'C', (size_t)&modelOffset->bk_prof_aft_tax_for_pv),
	CashFlowCommonData(23, "bk_prof_aft_tax_irr", "fia_liab_bk_prof_aft_tax_irr",  "bk_prof_aft_tax_irr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_bk_prof_aft_tax_irr, 'E','Y', '3', 'C', (size_t)&modelOffset->bk_prof_aft_tax_irr),
	CashFlowCommonData(24, "bk_prof_aft_tax_qtd", "fia_liab_bk_prof_aft_tax_qtd",  "bk_prof_aft_tax_qtd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_bk_prof_aft_tax_qtd, 'E','N', '3', 'C', (size_t)&modelOffset->bk_prof_aft_tax_qtd),
	CashFlowCommonData(25, "bk_prof_aft_tax_ytd", "fia_liab_bk_prof_aft_tax_ytd",  "bk_prof_aft_tax_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_bk_prof_aft_tax_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->bk_prof_aft_tax_ytd),
	CashFlowCommonData(26, "bk_prof_bef_tax", "fia_liab_bk_prof_bef_tax",  "bk_prof_bef_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_bk_prof_bef_tax, 'E','Y', '3', 'C', (size_t)&modelOffset->bk_prof_bef_tax),
	CashFlowCommonData(27, "bk_prof_bef_tax_for_pv", "fia_liab_bk_prof_bef_tax_for_pv",  "bk_prof_bef_tax_for_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_bk_prof_bef_tax_for_pv, 'E','Y', '3', 'C', (size_t)&modelOffset->bk_prof_bef_tax_for_pv),
	CashFlowCommonData(28, "bk_prof_bef_tax_qtd", "fia_liab_bk_prof_bef_tax_qtd",  "bk_prof_bef_tax_qtd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_bk_prof_bef_tax_qtd, 'E','N', '3', 'C', (size_t)&modelOffset->bk_prof_bef_tax_qtd),
	CashFlowCommonData(29, "bk_prof_bef_tax_ytd", "fia_liab_bk_prof_bef_tax_ytd",  "bk_prof_bef_tax_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_bk_prof_bef_tax_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->bk_prof_bef_tax_ytd),
	CashFlowCommonData(30, "bk_prof_by_source_bef_tax", "fia_liab_bk_prof_by_source_bef_tax",  "bk_prof_by_source_bef_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_bk_prof_by_source_bef_tax, 'E','N', '3', 'P', (size_t)&modelOffset->bk_prof_by_source_bef_tax),
	CashFlowCommonData(31, "cal_mth", "fia_liab_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(32, "cal_yr", "fia_liab_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(33, "cal_yr_relative", "fia_liab_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(34, "cash_val", "fia_liab_cash_val",  "cash_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_cash_val, 'E','N', '3', 'C', (size_t)&modelOffset->cash_val),
	CashFlowCommonData(35, "cash_val_bef", "fia_liab_cash_val_bef",  "cash_val_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_cash_val_bef, 'E','N', '3', 'P', (size_t)&modelOffset->cash_val_bef),
	CashFlowCommonData(36, "cash_val_wo_mva", "fia_liab_cash_val_wo_mva",  "cash_val2_wo_mva",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_cash_val_wo_mva, 'E','N', '3', 'C', (size_t)&modelOffset->cash_val_wo_mva),
	CashFlowCommonData(37, "comm_bom", "fia_liab_comm_bom",  "comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_comm_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->comm_bom),
	CashFlowCommonData(38, "comm_chargeback", "fia_liab_comm_chargeback",  "comm_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_comm_chargeback, 'E','Y', '3', 'C', (size_t)&modelOffset->comm_chargeback),
	CashFlowCommonData(39, "comm_eom", "fia_liab_comm_eom",  "comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_comm_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->comm_eom),
	CashFlowCommonData(40, "comm_fund_based", "fia_liab_comm_fund_based",  "comm_fund_based",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_comm_fund_based, 'B','Y', '3', 'P', (size_t)&modelOffset->comm_fund_based),
	CashFlowCommonData(41, "comm_prem_based", "fia_liab_comm_prem_based",  "comm_prem_based",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_comm_prem_based, 'B','Y', '3', 'P', (size_t)&modelOffset->comm_prem_based),
	CashFlowCommonData(42, "comm_subject_to_chargeback", "fia_liab_comm_subject_to_chargeback",  "comm_subject_to_chargeback",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_comm_subject_to_chargeback, 'E','Y', '3', 'C', (size_t)&modelOffset->comm_subject_to_chargeback),
	CashFlowCommonData(43, "comm_subject_to_chargeback_e", "fia_liab_comm_subject_to_chargeback_e",  "comm_subject_to_chargeback_e",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_comm_subject_to_chargeback_e, 'E','Y', '3', 'C', (size_t)&modelOffset->comm_subject_to_chargeback_e),
	CashFlowCommonData(44, "contract_val", "fia_liab_contract_val",  "contract_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_contract_val, 'E','N', '3', 'C', (size_t)&modelOffset->contract_val),
	CashFlowCommonData(45, "contract_val_bef", "fia_liab_contract_val_bef",  "contract_val_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_contract_val_bef, 'E','N', '3', 'P', (size_t)&modelOffset->contract_val_bef),
	CashFlowCommonData(46, "covered_person_status_crbg", "fia_liab_covered_person_status_crbg",  "covered_person_status_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_covered_person_status_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->covered_person_status_crbg),
	CashFlowCommonData(47, "credited_int", "fia_liab_credited_int",  "credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_credited_int, 'E','Y', '3', 'C', (size_t)&modelOffset->credited_int),
	CashFlowCommonData(48, "credited_int_comp_numer", "fia_liab_credited_int_comp_numer",  "credited_int_comp_numer",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_credited_int_comp_numer, 'E','N', '3', 'P', (size_t)&modelOffset->credited_int_comp_numer),
	CashFlowCommonData(49, "crediting_rate", "fia_liab_crediting_rate",  "crediting_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_crediting_rate, 'E','N', '3', 'C', (size_t)&modelOffset->crediting_rate),
	CashFlowCommonData(50, "crediting_rate_cumul_crbg", "fia_liab_crediting_rate_cumul_crbg",  "crediting_rate_cumul_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_crediting_rate_cumul_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_rate_cumul_crbg),
	CashFlowCommonData(51, "crediting_rate_fix", "fia_liab_crediting_rate_fix",  "crediting_rate_fix",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_crediting_rate_fix, 'E','N', '3', 'C', (size_t)&modelOffset->crediting_rate_fix),
	CashFlowCommonData(52, "crediting_rate_partial_crbg", "fia_liab_crediting_rate_partial_crbg",  "crediting_rate_partial_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_crediting_rate_partial_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->crediting_rate_partial_crbg),
	CashFlowCommonData(53, "date", "fia_liab_date",  "date",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(54, "direct_cash_flow_bom", "fia_liab_direct_cash_flow_bom",  "direct_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_direct_cash_flow_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->direct_cash_flow_bom),
	CashFlowCommonData(55, "direct_cash_flow_eom", "fia_liab_direct_cash_flow_eom",  "direct_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_direct_cash_flow_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->direct_cash_flow_eom),
	CashFlowCommonData(56, "direct_cash_flow_int", "fia_liab_direct_cash_flow_int",  "direct_cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_direct_cash_flow_int, 'E','Y', '3', 'C', (size_t)&modelOffset->direct_cash_flow_int),
	CashFlowCommonData(57, "disc_rate_1", "fia_liab_disc_rate_1",  "disc_rate_1",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_disc_rate_1, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_1),
	CashFlowCommonData(58, "disc_rate_2", "fia_liab_disc_rate_2",  "disc_rate_2",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_disc_rate_2, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_2),
	CashFlowCommonData(59, "disc_rate_3", "fia_liab_disc_rate_3",  "disc_rate_3",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_disc_rate_3, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_3),
	CashFlowCommonData(60, "disc_rate_port_yld", "fia_liab_disc_rate_port_yld",  "disc_rate_port_yld",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_disc_rate_port_yld, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_port_yld),
	CashFlowCommonData(61, "disc_rate_port_yld_defn_val", "fia_liab_disc_rate_port_yld_defn_val",  "disc_rate_port_yld_defn_val",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_disc_rate_port_yld_defn_val, 'E','N', '3', 'P', (size_t)&modelOffset->disc_rate_port_yld_defn_val),
	CashFlowCommonData(62, "disc_rate_rf_crbg", "fia_liab_disc_rate_rf_crbg",  "disc_rate_rf_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_disc_rate_rf_crbg, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_rf_crbg),
	CashFlowCommonData(63, "disc_rate_rf_sprd_ic_uel_crbg", "fia_liab_disc_rate_rf_sprd_ic_uel_crbg",  "disc_rate_rf_sprd_ic_uel_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_disc_rate_rf_sprd_ic_uel_crbg, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_rf_sprd_ic_uel_crbg),
	CashFlowCommonData(64, "disc_rate_rf_sprd_no_uel_crbg", "fia_liab_disc_rate_rf_sprd_no_uel_crbg",  "disc_rate_rf_sprd_no_uel_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_disc_rate_rf_sprd_no_uel_crbg, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_rf_sprd_no_uel_crbg),
	CashFlowCommonData(65, "disc_rate_rf_sprd_uel_crbg", "fia_liab_disc_rate_rf_sprd_uel_crbg",  "disc_rate_rf_sprd_uel_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_disc_rate_rf_sprd_uel_crbg, 'E','T', '3', 'C', (size_t)&modelOffset->disc_rate_rf_sprd_uel_crbg),
	CashFlowCommonData(66, "distrib_earnings", "fia_liab_distrib_earnings",  "distrib_earnings",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_distrib_earnings, 'E','Y', '3', 'C', (size_t)&modelOffset->distrib_earnings),
	CashFlowCommonData(67, "distrib_earnings_irr", "fia_liab_distrib_earnings_irr",  "distrib_earnings_irr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_distrib_earnings_irr, 'E','Y', '3', 'P', (size_t)&modelOffset->distrib_earnings_irr),
	CashFlowCommonData(68, "dth_ben_inf", "fia_liab_dth_ben_inf",  "dth_ben_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_dth_ben_inf, 'E','N', '3', 'C', (size_t)&modelOffset->dth_ben_inf),
	CashFlowCommonData(69, "dth_ben_inf_bef", "fia_liab_dth_ben_inf_bef",  "dth_ben_inf_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_dth_ben_inf_bef, 'E','N', '3', 'C', (size_t)&modelOffset->dth_ben_inf_bef),
	CashFlowCommonData(70, "dth_benefits", "fia_liab_dth_benefits",  "dth_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_dth_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->dth_benefits),
	CashFlowCommonData(71, "dth_claim_rate_mthly", "fia_liab_dth_claim_rate_mthly",  "dth_claim_rate_mthly",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_dth_claim_rate_mthly, 'M','N', '3', 'C', (size_t)&modelOffset->dth_claim_rate_mthly),
	CashFlowCommonData(72, "dth_rate_female_crbg", "fia_liab_dth_rate_female_crbg",  "dth_rate_female_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_dth_rate_female_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->dth_rate_female_crbg),
	CashFlowCommonData(73, "dth_rate_male_crbg", "fia_liab_dth_rate_male_crbg",  "dth_rate_male_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_dth_rate_male_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->dth_rate_male_crbg),
	CashFlowCommonData(74, "dth_rate_mthly_blended_crbg", "fia_liab_dth_rate_mthly_blended_crbg",  "dth_rate_mthly_blended_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_dth_rate_mthly_blended_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->dth_rate_mthly_blended_crbg),
	CashFlowCommonData(75, "dth_rate_mthly_crbg", "fia_liab_dth_rate_mthly_crbg",  "dth_rate_mthly_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_dth_rate_mthly_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->dth_rate_mthly_crbg),
	CashFlowCommonData(76, "dth_rate_mthly_female_crbg", "fia_liab_dth_rate_mthly_female_crbg",  "dth_rate_mthly_female_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_dth_rate_mthly_female_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->dth_rate_mthly_female_crbg),
	CashFlowCommonData(77, "dth_rate_mthly_last_survivor_crbg", "fia_liab_dth_rate_mthly_last_survivor_crbg",  "dth_rate_mthly_last_survivor_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_dth_rate_mthly_last_survivor_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->dth_rate_mthly_last_survivor_crbg),
	CashFlowCommonData(78, "dth_rate_mthly_male_crbg", "fia_liab_dth_rate_mthly_male_crbg",  "dth_rate_mthly_male_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_dth_rate_mthly_male_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->dth_rate_mthly_male_crbg),
	CashFlowCommonData(79, "earnings_accum", "fia_liab_earnings_accum",  "earnings_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_earnings_accum, 'E','Y', '3', 'C', (size_t)&modelOffset->earnings_accum),
	CashFlowCommonData(80, "enh_inc_confined_mth_female_crbg", "fia_liab_enh_inc_confined_mth_female_crbg",  "enh_inc_confined_mth_female_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_enh_inc_confined_mth_female_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->enh_inc_confined_mth_female_crbg),
	CashFlowCommonData(81, "enh_inc_confined_mth_male_crbg", "fia_liab_enh_inc_confined_mth_male_crbg",  "enh_inc_confined_mth_male_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_enh_inc_confined_mth_male_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->enh_inc_confined_mth_male_crbg),
	CashFlowCommonData(82, "enh_inc_confined_status_aggr_crbg", "fia_liab_enh_inc_confined_status_aggr_crbg",  "enh_inc_confined_status_aggr_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_enh_inc_confined_status_aggr_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->enh_inc_confined_status_aggr_crbg),
	CashFlowCommonData(83, "enh_inc_confined_status_female_crbg", "fia_liab_enh_inc_confined_status_female_crbg",  "enh_inc_confined_status_female_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_enh_inc_confined_status_female_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->enh_inc_confined_status_female_crbg),
	CashFlowCommonData(84, "enh_inc_confined_status_male_crbg", "fia_liab_enh_inc_confined_status_male_crbg",  "enh_inc_confined_status_male_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_enh_inc_confined_status_male_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->enh_inc_confined_status_male_crbg),
	CashFlowCommonData(85, "enh_inc_eligibility_flag_crbg", "fia_liab_enh_inc_eligibility_flag_crbg",  "enh_inc_eligibility_flag_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_enh_inc_eligibility_flag_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->enh_inc_eligibility_flag_crbg),
	CashFlowCommonData(86, "enh_inc_exercise_cumul_yrs_crbg", "fia_liab_enh_inc_exercise_cumul_yrs_crbg",  "enh_inc_exercise_cumul_yrs_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_enh_inc_exercise_cumul_yrs_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->enh_inc_exercise_cumul_yrs_crbg),
	CashFlowCommonData(87, "enh_inc_exercise_flag_crbg", "fia_liab_enh_inc_exercise_flag_crbg",  "enh_inc_exercise_flag_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_enh_inc_exercise_flag_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->enh_inc_exercise_flag_crbg),
	CashFlowCommonData(88, "enh_inc_indirect_exercise_crbg", "fia_liab_enh_inc_indirect_exercise_crbg",  "enh_inc_indirect_exercise_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_enh_inc_indirect_exercise_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->enh_inc_indirect_exercise_crbg),
	CashFlowCommonData(89, "enh_inc_rand_exercise_crbg", "fia_liab_enh_inc_rand_exercise_crbg",  "enh_inc_rand_exercise_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_enh_inc_rand_exercise_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->enh_inc_rand_exercise_crbg),
	CashFlowCommonData(90, "enh_inc_rand_female_crbg", "fia_liab_enh_inc_rand_female_crbg",  "enh_inc_rand_female_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_enh_inc_rand_female_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->enh_inc_rand_female_crbg),
	CashFlowCommonData(91, "enh_inc_rand_male_crbg", "fia_liab_enh_inc_rand_male_crbg",  "enh_inc_rand_male_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_enh_inc_rand_male_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->enh_inc_rand_male_crbg),
	CashFlowCommonData(92, "eprs_sfc_ben_crbg", "fia_liab_eprs_sfc_ben_crbg",  "eprs_sfc_ben_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_eprs_sfc_ben_crbg, 'B','Y', '3', 'C', (size_t)&modelOffset->eprs_sfc_ben_crbg),
	CashFlowCommonData(93, "eprs_sfc_ben_gross_crbg", "fia_liab_eprs_sfc_ben_gross_crbg",  "eprs_sfc_ben_gross_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_eprs_sfc_ben_gross_crbg, 'B','Y', '3', 'C', (size_t)&modelOffset->eprs_sfc_ben_gross_crbg),
	CashFlowCommonData(94, "eprs_strat_fee_partial_bef_crbg", "fia_liab_eprs_strat_fee_partial_bef_crbg",  "eprs_strat_fee_partial_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_eprs_strat_fee_partial_bef_crbg, 'B','Y', '3', 'C', (size_t)&modelOffset->eprs_strat_fee_partial_bef_crbg),
	CashFlowCommonData(95, "eprs_strat_fee_partial_e_crbg", "fia_liab_eprs_strat_fee_partial_e_crbg",  "eprs_strat_fee_partial_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_eprs_strat_fee_partial_e_crbg, 'B','Y', '3', 'C', (size_t)&modelOffset->eprs_strat_fee_partial_e_crbg),
	CashFlowCommonData(96, "finalize", "fia_liab_finalize",  "finalize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_finalize, 'E','Y', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(97, "fund_released_ann", "fia_liab_fund_released_ann",  "fund_released_ann",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_fund_released_ann, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_ann),
	CashFlowCommonData(98, "fund_released_dth", "fia_liab_fund_released_dth",  "fund_released_dth",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_fund_released_dth, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_dth),
	CashFlowCommonData(99, "fund_released_maturity", "fia_liab_fund_released_maturity",  "fund_released_maturity",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_fund_released_maturity, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_maturity),
	CashFlowCommonData(100, "fund_released_surr", "fia_liab_fund_released_surr",  "fund_released_surr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_fund_released_surr, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_surr),
	CashFlowCommonData(101, "fund_released_withdrl", "fia_liab_fund_released_withdrl",  "fund_released_withdrl",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_fund_released_withdrl, 'E','Y', '3', 'C', (size_t)&modelOffset->fund_released_withdrl),
	CashFlowCommonData(102, "fund_val_b", "fia_liab_fund_val_b",  "fund_val_b",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_fund_val_b, 'B','N', '3', 'C', (size_t)&modelOffset->fund_val_b),
	CashFlowCommonData(103, "fund_val_b_bef", "fia_liab_fund_val_b_bef",  "fund_val_b_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_fund_val_b_bef, 'B','N', '3', 'C', (size_t)&modelOffset->fund_val_b_bef),
	CashFlowCommonData(104, "fund_val_boy_b_crbg", "fia_liab_fund_val_boy_b_crbg",  "fund_val_boy_b_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_fund_val_boy_b_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->fund_val_boy_b_crbg),
	CashFlowCommonData(105, "fund_val_boy_e_crbg", "fia_liab_fund_val_boy_e_crbg",  "fund_val_boy_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_fund_val_boy_e_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->fund_val_boy_e_crbg),
	CashFlowCommonData(106, "fund_val_decrem", "fia_liab_fund_val_decrem",  "fund_val_decrem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_fund_val_decrem, 'E','Y', '3', 'P', (size_t)&modelOffset->fund_val_decrem),
	CashFlowCommonData(107, "fund_val_e_bef", "fia_liab_fund_val_e_bef",  "fund_val_e_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_fund_val_e_bef, 'E','N', '3', 'C', (size_t)&modelOffset->fund_val_e_bef),
	CashFlowCommonData(108, "fund_val_fixed", "fia_liab_fund_val_fixed",  "fund_val_fixed",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_fund_val_fixed, 'E','N', '3', 'P', (size_t)&modelOffset->fund_val_fixed),
	CashFlowCommonData(109, "gaap_acq_exp", "fia_liab_gaap_acq_exp",  "gaap_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_acq_exp, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_acq_exp),
	CashFlowCommonData(110, "gaap_ben_res", "fia_liab_gaap_ben_res",  "gaap_ben_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_ben_res, 'E','N', '3', 'P', (size_t)&modelOffset->gaap_ben_res),
	CashFlowCommonData(111, "gaap_capzd_acq_exp", "fia_liab_gaap_capzd_acq_exp",  "gaap_capzd_acq_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_capzd_acq_exp, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_capzd_acq_exp),
	CashFlowCommonData(112, "gaap_capzd_comm_bom", "fia_liab_gaap_capzd_comm_bom",  "gaap_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_capzd_comm_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_capzd_comm_bom),
	CashFlowCommonData(113, "gaap_capzd_comm_eom", "fia_liab_gaap_capzd_comm_eom",  "gaap_capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_capzd_comm_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_capzd_comm_eom),
	CashFlowCommonData(114, "gaap_capzd_prem_bonus", "fia_liab_gaap_capzd_prem_bonus",  "gaap_capzd_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_capzd_prem_bonus, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_capzd_prem_bonus),
	CashFlowCommonData(115, "gaap_cash_flow_int", "fia_liab_gaap_cash_flow_int",  "gaap_cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_cash_flow_int, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_cash_flow_int),
	CashFlowCommonData(116, "gaap_chg_inc", "fia_liab_gaap_chg_inc",  "gaap_chg_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_chg_inc, 'B','Y', '3', 'P', (size_t)&modelOffset->gaap_chg_inc),
	CashFlowCommonData(117, "gaap_comm_excess_bom", "fia_liab_gaap_comm_excess_bom",  "gaap_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_comm_excess_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_comm_excess_bom),
	CashFlowCommonData(118, "gaap_comm_excess_eom", "fia_liab_gaap_comm_excess_eom",  "gaap_comm_excess_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_comm_excess_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_comm_excess_eom),
	CashFlowCommonData(119, "gaap_comm_trail_bom", "fia_liab_gaap_comm_trail_bom",  "gaap_comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_comm_trail_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_comm_trail_bom),
	CashFlowCommonData(120, "gaap_comm_trail_eom", "fia_liab_gaap_comm_trail_eom",  "gaap_comm_trail_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_comm_trail_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_comm_trail_eom),
	CashFlowCommonData(121, "gaap_credited_int", "fia_liab_gaap_credited_int",  "gaap_credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_credited_int, 'E','Y', '3', 'P', (size_t)&modelOffset->gaap_credited_int),
	CashFlowCommonData(122, "gaap_dac", "fia_liab_gaap_dac",  "gaap_dac",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_dac, 'E','N', '3', 'P', (size_t)&modelOffset->gaap_dac),
	CashFlowCommonData(123, "gaap_dac_incr", "fia_liab_gaap_dac_incr",  "gaap_dac_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_dac_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_dac_incr),
	CashFlowCommonData(124, "gaap_deferred_tax_liab", "fia_liab_gaap_deferred_tax_liab",  "gaap_deferred_tax_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_deferred_tax_liab, 'E','N', '3', 'P', (size_t)&modelOffset->gaap_deferred_tax_liab),
	CashFlowCommonData(125, "gaap_deferred_tax_liab_incr", "fia_liab_gaap_deferred_tax_liab_incr",  "gaap_deferred_tax_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_deferred_tax_liab_incr, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_deferred_tax_liab_incr),
	CashFlowCommonData(126, "gaap_dth_claim_cost", "fia_liab_gaap_dth_claim_cost",  "gaap_dth_claim_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_dth_claim_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_dth_claim_cost),
	CashFlowCommonData(127, "gaap_inc_aft_tax", "fia_liab_gaap_inc_aft_tax",  "gaap_inc_aft_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_inc_aft_tax, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_inc_aft_tax),
	CashFlowCommonData(128, "gaap_inc_aft_tax_qtd", "fia_liab_gaap_inc_aft_tax_qtd",  "gaap_inc_aft_tax_qtd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_inc_aft_tax_qtd, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_aft_tax_qtd),
	CashFlowCommonData(129, "gaap_inc_aft_tax_ytd", "fia_liab_gaap_inc_aft_tax_ytd",  "gaap_inc_aft_tax_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_inc_aft_tax_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_aft_tax_ytd),
	CashFlowCommonData(130, "gaap_inc_bef_tax", "fia_liab_gaap_inc_bef_tax",  "gaap_inc_bef_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_inc_bef_tax, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_inc_bef_tax),
	CashFlowCommonData(131, "gaap_inc_bef_tax_qtd", "fia_liab_gaap_inc_bef_tax_qtd",  "gaap_inc_bef_tax_qtd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_inc_bef_tax_qtd, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_bef_tax_qtd),
	CashFlowCommonData(132, "gaap_inc_bef_tax_ytd", "fia_liab_gaap_inc_bef_tax_ytd",  "gaap_inc_bef_tax_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_inc_bef_tax_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inc_bef_tax_ytd),
	CashFlowCommonData(133, "gaap_inv_asset", "fia_liab_gaap_inv_asset",  "gaap_inv_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_inv_asset, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_inv_asset),
	CashFlowCommonData(134, "gaap_inv_inc_cap", "fia_liab_gaap_inv_inc_cap",  "gaap_inv_inc_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_inv_inc_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_inv_inc_cap),
	CashFlowCommonData(135, "gaap_inv_inc_res", "fia_liab_gaap_inv_inc_res",  "gaap_inv_inc_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_inv_inc_res, 'E','Y', '3', 'P', (size_t)&modelOffset->gaap_inv_inc_res),
	CashFlowCommonData(136, "gaap_liab_net", "fia_liab_gaap_liab_net",  "gaap_liab_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_liab_net, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_liab_net),
	CashFlowCommonData(137, "gaap_loads_deducted", "fia_liab_gaap_loads_deducted",  "gaap_loads_deducted",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_loads_deducted, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_loads_deducted),
	CashFlowCommonData(138, "gaap_maint_exp_bom", "fia_liab_gaap_maint_exp_bom",  "gaap_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_maint_exp_bom),
	CashFlowCommonData(139, "gaap_maint_exp_eom", "fia_liab_gaap_maint_exp_eom",  "gaap_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_maint_exp_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_maint_exp_eom),
	CashFlowCommonData(140, "gaap_mrb_liab", "fia_liab_gaap_mrb_liab",  "gaap_mrb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_mrb_liab, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_mrb_liab),
	CashFlowCommonData(141, "gaap_mrb_liab_incr", "fia_liab_gaap_mrb_liab_incr",  "gaap_mrb_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_mrb_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_mrb_liab_incr),
	CashFlowCommonData(142, "gaap_prem_bonus", "fia_liab_gaap_prem_bonus",  "gaap_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_prem_bonus, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_prem_bonus),
	CashFlowCommonData(143, "gaap_prem_tax", "fia_liab_gaap_prem_tax",  "gaap_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_prem_tax, 'B','Y', '3', 'C', (size_t)&modelOffset->gaap_prem_tax),
	CashFlowCommonData(144, "gaap_prof_aft_tax_for_pv", "fia_liab_gaap_prof_aft_tax_for_pv",  "gaap_prof_aft_tax_for_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_prof_aft_tax_for_pv, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_prof_aft_tax_for_pv),
	CashFlowCommonData(145, "gaap_prof_bef_tax_for_pv", "fia_liab_gaap_prof_bef_tax_for_pv",  "gaap_prof_bef_tax_for_pv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_prof_bef_tax_for_pv, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_prof_bef_tax_for_pv),
	CashFlowCommonData(146, "gaap_req_cap", "fia_liab_gaap_req_cap",  "gaap_req_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_req_cap, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_req_cap),
	CashFlowCommonData(147, "gaap_sfas133_liab", "fia_liab_gaap_sfas133_liab",  "gaap_sfas133_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_sfas133_liab, 'E','N', '3', 'C', (size_t)&modelOffset->gaap_sfas133_liab),
	CashFlowCommonData(148, "gaap_sfas133_liab_incr", "fia_liab_gaap_sfas133_liab_incr",  "gaap_sfas133_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_sfas133_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_sfas133_liab_incr),
	CashFlowCommonData(149, "gaap_surp_incr", "fia_liab_gaap_surp_incr",  "gaap_surp_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_surp_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_surp_incr),
	CashFlowCommonData(150, "gaap_surr_inc", "fia_liab_gaap_surr_inc",  "gaap_surr_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gaap_surr_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->gaap_surr_inc),
	CashFlowCommonData(151, "gmab_chg_crbg", "fia_liab_gmab_chg_crbg",  "gmab_chg_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmab_chg_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_chg_crbg),
	CashFlowCommonData(152, "gmab_chg_partial_e_bef_crbg", "fia_liab_gmab_chg_partial_e_bef_crbg",  "gmab_chg_partial_e_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmab_chg_partial_e_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_chg_partial_e_bef_crbg),
	CashFlowCommonData(153, "gmab_chg_partial_e_crbg", "fia_liab_gmab_chg_partial_e_crbg",  "gmab_chg_partial_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmab_chg_partial_e_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_chg_partial_e_crbg),
	CashFlowCommonData(154, "gmab_global_payoff_crbg", "fia_liab_gmab_global_payoff_crbg",  "gmab_global_payoff_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmab_global_payoff_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_global_payoff_crbg),
	CashFlowCommonData(155, "gmab_payoff_crbg", "fia_liab_gmab_payoff_crbg",  "gmab_payoff_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmab_payoff_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmab_payoff_crbg),
	CashFlowCommonData(156, "gmwb_chg", "fia_liab_gmwb_chg",  "gmwb_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_chg, 'B','Y', '3', 'C', (size_t)&modelOffset->gmwb_chg),
	CashFlowCommonData(157, "gmwb_chg_partial_bef_crbg", "fia_liab_gmwb_chg_partial_bef_crbg",  "gmwb_chg_partial_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_chg_partial_bef_crbg, 'B','Y', '3', 'C', (size_t)&modelOffset->gmwb_chg_partial_bef_crbg),
	CashFlowCommonData(158, "gmwb_chg_partial_e_crbg", "fia_liab_gmwb_chg_partial_e_crbg",  "gmwb_chg_partial_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_chg_partial_e_crbg, 'B','Y', '3', 'C', (size_t)&modelOffset->gmwb_chg_partial_e_crbg),
	CashFlowCommonData(159, "gmwb_entitlement_remaining_b_crbg", "fia_liab_gmwb_entitlement_remaining_b_crbg",  "gmwb_entitlement_remaining_b_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_entitlement_remaining_b_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_entitlement_remaining_b_crbg),
	CashFlowCommonData(160, "gmwb_entitlement_remaining_e_crbg", "fia_liab_gmwb_entitlement_remaining_e_crbg",  "gmwb_entitlement_remaining_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_entitlement_remaining_e_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_entitlement_remaining_e_crbg),
	CashFlowCommonData(161, "gmwb_exercise_yrs_crbg", "fia_liab_gmwb_exercise_yrs_crbg",  "gmwb_exercise_yrs_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_exercise_yrs_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_exercise_yrs_crbg),
	CashFlowCommonData(162, "gmwb_fund_val_inf", "fia_liab_gmwb_fund_val_inf",  "gmwb_fund_val_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_fund_val_inf, 'E','N', '3', 'C', (size_t)&modelOffset->gmwb_fund_val_inf),
	CashFlowCommonData(163, "gmwb_fund_val_inf_bef", "fia_liab_gmwb_fund_val_inf_bef",  "gmwb_fund_val_inf_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_fund_val_inf_bef, 'E','N', '3', 'C', (size_t)&modelOffset->gmwb_fund_val_inf_bef),
	CashFlowCommonData(164, "gmwb_income_base_b_bef_crbg", "fia_liab_gmwb_income_base_b_bef_crbg",  "gmwb_income_base_b_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_income_base_b_bef_crbg, 'B','N', '3', 'C', (size_t)&modelOffset->gmwb_income_base_b_bef_crbg),
	CashFlowCommonData(165, "gmwb_income_base_b_crbg", "fia_liab_gmwb_income_base_b_crbg",  "gmwb_income_base_b_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_income_base_b_crbg, 'E','N', '3', 'C', (size_t)&modelOffset->gmwb_income_base_b_crbg),
	CashFlowCommonData(166, "gmwb_income_base_e_bef_crbg", "fia_liab_gmwb_income_base_e_bef_crbg",  "gmwb_income_base_e_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_income_base_e_bef_crbg, 'E','N', '3', 'C', (size_t)&modelOffset->gmwb_income_base_e_bef_crbg),
	CashFlowCommonData(167, "gmwb_income_base_e_crbg", "fia_liab_gmwb_income_base_e_crbg",  "gmwb_income_base_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_income_base_e_crbg, 'E','N', '3', 'C', (size_t)&modelOffset->gmwb_income_base_e_crbg),
	CashFlowCommonData(168, "gmwb_income_base_reduction_fct_crbg", "fia_liab_gmwb_income_base_reduction_fct_crbg",  "gmwb_income_base_reduction_fct_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_income_base_reduction_fct_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_income_base_reduction_fct_crbg),
	CashFlowCommonData(169, "gmwb_income_credit_b_crbg", "fia_liab_gmwb_income_credit_b_crbg",  "gmwb_income_credit_b_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_income_credit_b_crbg, 'E','N', '3', 'C', (size_t)&modelOffset->gmwb_income_credit_b_crbg),
	CashFlowCommonData(170, "gmwb_income_credit_base_e_bef_crbg", "fia_liab_gmwb_income_credit_base_e_bef_crbg",  "gmwb_income_credit_base_e_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_income_credit_base_e_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_income_credit_base_e_bef_crbg),
	CashFlowCommonData(171, "gmwb_income_credit_base_e_crbg", "fia_liab_gmwb_income_credit_base_e_crbg",  "gmwb_income_credit_base_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_income_credit_base_e_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_income_credit_base_e_crbg),
	CashFlowCommonData(172, "gmwb_inf", "fia_liab_gmwb_inf",  "gmwb_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_inf, 'E','N', '3', 'C', (size_t)&modelOffset->gmwb_inf),
	CashFlowCommonData(173, "gmwb_inf_bef", "fia_liab_gmwb_inf_bef",  "gmwb_inf_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_inf_bef, 'E','N', '3', 'C', (size_t)&modelOffset->gmwb_inf_bef),
	CashFlowCommonData(174, "gmwb_itm", "fia_liab_gmwb_itm",  "gmwb_itm",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_itm, 'E','N', '3', 'C', (size_t)&modelOffset->gmwb_itm),
	CashFlowCommonData(175, "gmwb_max_ann_wdl_pct_crbg", "fia_liab_gmwb_max_ann_wdl_pct_crbg",  "gmwb_max_ann_wdl_pct_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_max_ann_wdl_pct_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_max_ann_wdl_pct_crbg),
	CashFlowCommonData(176, "gmwb_max_wdl_amt", "fia_liab_gmwb_max_wdl_amt",  "gmwb_max_wdl_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_max_wdl_amt, 'E','N', '3', 'C', (size_t)&modelOffset->gmwb_max_wdl_amt),
	CashFlowCommonData(177, "gmwb_min_income_base_bef_crbg", "fia_liab_gmwb_min_income_base_bef_crbg",  "gmwb_min_income_base_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_min_income_base_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_min_income_base_bef_crbg),
	CashFlowCommonData(178, "gmwb_pipp_stepup_ind_crbg", "fia_liab_gmwb_pipp_stepup_ind_crbg",  "gmwb_pipp_stepup_ind_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_pipp_stepup_ind_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_pipp_stepup_ind_crbg),
	CashFlowCommonData(179, "gmwb_rollup_cap_inf", "fia_liab_gmwb_rollup_cap_inf",  "gmwb_rollup_cap_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_rollup_cap_inf, 'E','N', '3', 'C', (size_t)&modelOffset->gmwb_rollup_cap_inf),
	CashFlowCommonData(180, "gmwb_rollup_cap_inf_bef", "fia_liab_gmwb_rollup_cap_inf_bef",  "gmwb_rollup_cap_inf_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_rollup_cap_inf_bef, 'E','N', '3', 'C', (size_t)&modelOffset->gmwb_rollup_cap_inf_bef),
	CashFlowCommonData(181, "gmwb_wdl_amt_e_bef_crbg", "fia_liab_gmwb_wdl_amt_e_bef_crbg",  "gmwb_wdl_amt_e_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_wdl_amt_e_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_wdl_amt_e_bef_crbg),
	CashFlowCommonData(182, "gmwb_wdl_amt_excess_bef_crbg", "fia_liab_gmwb_wdl_amt_excess_bef_crbg",  "gmwb_wdl_amt_excess_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_wdl_amt_excess_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_wdl_amt_excess_bef_crbg),
	CashFlowCommonData(183, "gmwb_wdl_excess_ind_e_crbg", "fia_liab_gmwb_wdl_excess_ind_e_crbg",  "gmwb_wdl_excess_ind_e_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_wdl_excess_ind_e_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_wdl_excess_ind_e_crbg),
	CashFlowCommonData(184, "gmwb_wdl_uti_level_crbg", "fia_liab_gmwb_wdl_uti_level_crbg",  "gmwb_wdl_uti_level_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_wdl_uti_level_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_wdl_uti_level_crbg),
	CashFlowCommonData(185, "gmwb_wdl_util_pct_crbg", "fia_liab_gmwb_wdl_util_pct_crbg",  "gmwb_wdl_util_pct_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_wdl_util_pct_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_wdl_util_pct_crbg),
	CashFlowCommonData(186, "gmwb_wdl_util_rand_num_crbg", "fia_liab_gmwb_wdl_util_rand_num_crbg",  "gmwb_wdl_util_rand_num_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gmwb_wdl_util_rand_num_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gmwb_wdl_util_rand_num_crbg),
	CashFlowCommonData(187, "gross_prem_annualzd", "fia_liab_gross_prem_annualzd",  "gross_prem_annualzd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gross_prem_annualzd, 'E','Y', '3', 'P', (size_t)&modelOffset->gross_prem_annualzd),
	CashFlowCommonData(188, "gwl_acq_exp_allow_crbg", "fia_liab_gwl_acq_exp_allow_crbg",  "gwl_acq_exp_allow_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gwl_acq_exp_allow_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gwl_acq_exp_allow_crbg),
	CashFlowCommonData(189, "gwl_ceding_exp_allow_crbg", "fia_liab_gwl_ceding_exp_allow_crbg",  "gwl_ceding_exp_allow_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gwl_ceding_exp_allow_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gwl_ceding_exp_allow_crbg),
	CashFlowCommonData(190, "gwl_maint_exp_allow_crbg", "fia_liab_gwl_maint_exp_allow_crbg",  "gwl_maint_exp_allow_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_gwl_maint_exp_allow_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->gwl_maint_exp_allow_crbg),
	CashFlowCommonData(191, "hedge_cash_flow", "fia_liab_hedge_cash_flow",  "hedge_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_hedge_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cash_flow),
	CashFlowCommonData(192, "hedge_cost", "fia_liab_hedge_cost",  "hedge_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_hedge_cost, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_cost),
	CashFlowCommonData(193, "hedge_inv_amt_bom", "fia_liab_hedge_inv_amt_bom",  "hedge_inv_amt_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_hedge_inv_amt_bom, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_inv_amt_bom),
	CashFlowCommonData(194, "hedge_mkt_val", "fia_liab_hedge_mkt_val",  "hedge_mkt_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_hedge_mkt_val, 'E','N', '3', 'P', (size_t)&modelOffset->hedge_mkt_val),
	CashFlowCommonData(195, "hedge_mkt_val_growth", "fia_liab_hedge_mkt_val_growth",  "hedge_mkt_val_growth",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_hedge_mkt_val_growth, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_mkt_val_growth),
	CashFlowCommonData(196, "hedge_mkt_val_incr", "fia_liab_hedge_mkt_val_incr",  "hedge_mkt_val_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_hedge_mkt_val_incr, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_mkt_val_incr),
	CashFlowCommonData(197, "hedge_sale_amt", "fia_liab_hedge_sale_amt",  "hedge_sale_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_hedge_sale_amt, 'E','Y', '3', 'P', (size_t)&modelOffset->hedge_sale_amt),
	CashFlowCommonData(198, "income_phase_bef_crbg", "fia_liab_income_phase_bef_crbg",  "income_phase_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_income_phase_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->income_phase_bef_crbg),
	CashFlowCommonData(199, "infl_cumul", "fia_liab_infl_cumul",  "infl_cumul",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_infl_cumul, 'E','N', '3', 'C', (size_t)&modelOffset->infl_cumul),
	CashFlowCommonData(200, "initialize", "fia_liab_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(201, "inv_asset", "fia_liab_inv_asset",  "inv_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_inv_asset, 'E','N', '3', 'C', (size_t)&modelOffset->inv_asset),
	CashFlowCommonData(202, "inv_inc", "fia_liab_inv_inc",  "inv_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_inv_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc),
	CashFlowCommonData(203, "inv_inc_bk_prof", "fia_liab_inv_inc_bk_prof",  "inv_inc_bk_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_inv_inc_bk_prof, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_bk_prof),
	CashFlowCommonData(204, "inv_inc_earnings_accum", "fia_liab_inv_inc_earnings_accum",  "inv_inc_earnings_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_inv_inc_earnings_accum, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_earnings_accum),
	CashFlowCommonData(205, "inv_inc_fund", "fia_liab_inv_inc_fund",  "inv_inc_fund",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_inv_inc_fund, 'E','Y', '3', 'P', (size_t)&modelOffset->inv_inc_fund),
	CashFlowCommonData(206, "inv_inc_on_invested_assets", "fia_liab_inv_inc_on_invested_assets",  "inv_inc_on_invested_assets",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_inv_inc_on_invested_assets, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_on_invested_assets),
	CashFlowCommonData(207, "inv_inc_res", "fia_liab_inv_inc_res",  "inv_inc_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_inv_inc_res, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_res),
	CashFlowCommonData(208, "inv_inc_tgt_cap", "fia_liab_inv_inc_tgt_cap",  "inv_inc_tgt_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_inv_inc_tgt_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_tgt_cap),
	CashFlowCommonData(209, "inv_inc_undistrib_earnings", "fia_liab_inv_inc_undistrib_earnings",  "inv_inc_undistrib_earnings",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_inv_inc_undistrib_earnings, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_inc_undistrib_earnings),
	CashFlowCommonData(210, "irr", "fia_liab_irr",  "irr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_irr, 'E','N', '3', 'P', (size_t)&modelOffset->irr),
	CashFlowCommonData(211, "irr_wo_tgt_cap", "fia_liab_irr_wo_tgt_cap",  "irr_wo_tgt_cap",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_irr_wo_tgt_cap, 'E','N', '3', 'P', (size_t)&modelOffset->irr_wo_tgt_cap),
	CashFlowCommonData(212, "issue_age_col_crbg", "fia_liab_issue_age_col_crbg",  "issue_age_col_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_issue_age_col_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->issue_age_col_crbg),
	CashFlowCommonData(213, "itm_is_positive_crbg", "fia_liab_itm_is_positive_crbg",  "itm_is_positive_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_itm_is_positive_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->itm_is_positive_crbg),
	CashFlowCommonData(214, "lapse_dyn_add_myga_crbg", "fia_liab_lapse_dyn_add_myga_crbg",  "lapse_dyn_add_myga_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_dyn_add_myga_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_dyn_add_myga_crbg),
	CashFlowCommonData(215, "lapse_dyn_addn_crbg", "fia_liab_lapse_dyn_addn_crbg",  "lapse_dyn_addn_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_dyn_addn_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_dyn_addn_crbg),
	CashFlowCommonData(216, "lapse_dyn_arctan_mult_crbg", "fia_liab_lapse_dyn_arctan_mult_crbg",  "lapse_dyn_arctan_mult_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_dyn_arctan_mult_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_dyn_arctan_mult_crbg),
	CashFlowCommonData(217, "lapse_dyn_base_prod_crbg", "fia_liab_lapse_dyn_base_prod_crbg",  "lapse_dyn_base_prod_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_dyn_base_prod_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_dyn_base_prod_crbg),
	CashFlowCommonData(218, "lapse_dyn_crediting_rt_crbg", "fia_liab_lapse_dyn_crediting_rt_crbg",  "lapse_dyn_crediting_rt_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_dyn_crediting_rt_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_dyn_crediting_rt_crbg),
	CashFlowCommonData(219, "lapse_dyn_fa_mult_crbg", "fia_liab_lapse_dyn_fa_mult_crbg",  "lapse_dyn_fa_mult_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_dyn_fa_mult_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_dyn_fa_mult_crbg),
	CashFlowCommonData(220, "lapse_dyn_isl_crbg", "fia_liab_lapse_dyn_isl_crbg",  "lapse_dyn_isl_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_dyn_isl_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_dyn_isl_crbg),
	CashFlowCommonData(221, "lapse_dyn_mult_crbg", "fia_liab_lapse_dyn_mult_crbg",  "lapse_dyn_mult_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_dyn_mult_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_dyn_mult_crbg),
	CashFlowCommonData(222, "lapse_dyn_sfc_mult_crbg", "fia_liab_lapse_dyn_sfc_mult_crbg",  "lapse_dyn_sfc_mult_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_dyn_sfc_mult_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_dyn_sfc_mult_crbg),
	CashFlowCommonData(223, "lapse_rate", "fia_liab_lapse_rate",  "lapse_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_rate, 'M','N', '3', 'C', (size_t)&modelOffset->lapse_rate),
	CashFlowCommonData(224, "lapse_rate_base", "fia_liab_lapse_rate_base",  "lapse_rate_base",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_rate_base, 'M','N', '3', 'C', (size_t)&modelOffset->lapse_rate_base),
	CashFlowCommonData(225, "lapse_rate_base_adj_crbg", "fia_liab_lapse_rate_base_adj_crbg",  "lapse_rate_base_adj_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_rate_base_adj_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_rate_base_adj_crbg),
	CashFlowCommonData(226, "lapse_rate_mthly", "fia_liab_lapse_rate_mthly",  "lapse_rate_mthly",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_rate_mthly, 'M','N', '3', 'C', (size_t)&modelOffset->lapse_rate_mthly),
	CashFlowCommonData(227, "lapse_rate_mthly_skew2025_crbg", "fia_liab_lapse_rate_mthly_skew2025_crbg",  "lapse_rate_mthly_skew2025_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_rate_mthly_skew2025_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_rate_mthly_skew2025_crbg),
	CashFlowCommonData(228, "lapse_rate_planned_numer", "fia_liab_lapse_rate_planned_numer",  "lapse_rate_planned_numer",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_rate_planned_numer, 'E','N', '3', 'P', (size_t)&modelOffset->lapse_rate_planned_numer),
	CashFlowCommonData(229, "lapse_skew_cumul_fct_fa_crbg", "fia_liab_lapse_skew_cumul_fct_fa_crbg",  "lapse_skew_cumul_fct_fa_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_skew_cumul_fct_fa_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_skew_cumul_fct_fa_crbg),
	CashFlowCommonData(230, "lapse_skew_fct_fa_crbg", "fia_liab_lapse_skew_fct_fa_crbg",  "lapse_skew_fct_fa_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_lapse_skew_fct_fa_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->lapse_skew_fct_fa_crbg),
	CashFlowCommonData(231, "last_period_indicator", "fia_liab_last_period_indicator",  "last_period_indicator",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_last_period_indicator, 'E','Y', '3', 'P', (size_t)&modelOffset->last_period_indicator),
	CashFlowCommonData(232, "liab_and_surp", "fia_liab_liab_and_surp",  "liab_and_surp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_liab_and_surp, 'E','N', '3', 'C', (size_t)&modelOffset->liab_and_surp),
	CashFlowCommonData(233, "maint_exp_bom", "fia_liab_maint_exp_bom",  "maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_maint_exp_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->maint_exp_bom),
	CashFlowCommonData(234, "maint_exp_eom", "fia_liab_maint_exp_eom",  "maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_maint_exp_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->maint_exp_eom),
	CashFlowCommonData(235, "maturity_benefits", "fia_liab_maturity_benefits",  "maturity_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_maturity_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->maturity_benefits),
	CashFlowCommonData(236, "min_accum_val_b_bef_crbg", "fia_liab_min_accum_val_b_bef_crbg",  "min_accum_val_b_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_min_accum_val_b_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->min_accum_val_b_bef_crbg),
	CashFlowCommonData(237, "min_accum_val_e_bef_crbg", "fia_liab_min_accum_val_e_bef_crbg",  "min_accum_val_e_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_min_accum_val_e_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->min_accum_val_e_bef_crbg),
	CashFlowCommonData(238, "min_accum_val_e_crbg", "fia_liab_min_accum_val_e_crbg",  "min_accum_val_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_min_accum_val_e_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->min_accum_val_e_crbg),
	CashFlowCommonData(239, "min_contract_val", "fia_liab_min_contract_val",  "min_contract_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_min_contract_val, 'E','N', '3', 'C', (size_t)&modelOffset->min_contract_val),
	CashFlowCommonData(240, "min_contract_val_bef", "fia_liab_min_contract_val_bef",  "min_contract_val_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_min_contract_val_bef, 'E','N', '3', 'C', (size_t)&modelOffset->min_contract_val_bef),
	CashFlowCommonData(241, "min_wdl_val_b_crbg", "fia_liab_min_wdl_val_b_crbg",  "min_wdl_val_b_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_min_wdl_val_b_crbg, 'B','Y', '3', 'P', (size_t)&modelOffset->min_wdl_val_b_crbg),
	CashFlowCommonData(242, "min_wdl_val_e_bef_crbg", "fia_liab_min_wdl_val_e_bef_crbg",  "min_wdl_val_e_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_min_wdl_val_e_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->min_wdl_val_e_bef_crbg),
	CashFlowCommonData(243, "min_wdl_val_e_crbg", "fia_liab_min_wdl_val_e_crbg",  "min_wdl_val_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_min_wdl_val_e_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->min_wdl_val_e_crbg),
	CashFlowCommonData(244, "mort_rate_exp", "fia_liab_mort_rate_exp",  "mort_rate_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mort_rate_exp, 'E','Y', '3', 'P', (size_t)&modelOffset->mort_rate_exp),
	CashFlowCommonData(245, "mort_rate_gmwb", "fia_liab_mort_rate_gmwb",  "mort_rate_gmwb",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mort_rate_gmwb, 'E','Y', '3', 'P', (size_t)&modelOffset->mort_rate_gmwb),
	CashFlowCommonData(246, "mths_since_issue", "fia_liab_mths_since_issue",  "mths_since_issue",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mths_since_issue, 'E','N', '3', 'P', (size_t)&modelOffset->mths_since_issue),
	CashFlowCommonData(247, "mtt_call_gen2classic_cols", "fia_liab_mtt_call_gen2classic_cols",  "mtt_call_gen2classic_cols",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mtt_call_gen2classic_cols, 'E','Y', '3', 'P', (size_t)&modelOffset->mtt_call_gen2classic_cols),
	CashFlowCommonData(248, "mtt_call_mbvnb_crbg", "fia_liab_mtt_call_mbvnb_crbg",  "mtt_call_mbvnb_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mtt_call_mbvnb_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->mtt_call_mbvnb_crbg),
	CashFlowCommonData(249, "mtt_call_vectorized_cols", "fia_liab_mtt_call_vectorized_cols",  "mtt_call_vectorized_cols",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mtt_call_vectorized_cols, 'E','Y', '3', 'P', (size_t)&modelOffset->mtt_call_vectorized_cols),
	CashFlowCommonData(250, "mtt_irr", "fia_liab_mtt_irr",  "mtt_irr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mtt_irr, 'E','Y', '3', 'P', (size_t)&modelOffset->mtt_irr),
	CashFlowCommonData(251, "mtt_target_all", "fia_liab_mtt_target_all",  "mtt_target_all",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mtt_target_all, 'E','Y', '3', 'P', (size_t)&modelOffset->mtt_target_all),
	CashFlowCommonData(252, "mtt_tgt_distrib_earnings", "fia_liab_mtt_tgt_distrib_earnings",  "mtt_tgt_distrib_earnings",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mtt_tgt_distrib_earnings, 'E','Y', '3', 'C', (size_t)&modelOffset->mtt_tgt_distrib_earnings),
	CashFlowCommonData(253, "mtt_tgt_gaap_inc_aft_tax", "fia_liab_mtt_tgt_gaap_inc_aft_tax",  "mtt_tgt_gaap_inc_aft_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mtt_tgt_gaap_inc_aft_tax, 'E','Y', '3', 'C', (size_t)&modelOffset->mtt_tgt_gaap_inc_aft_tax),
	CashFlowCommonData(254, "mtt_valn_tgt_gaap_mrb", "fia_liab_mtt_valn_tgt_gaap_mrb",  "mtt_valn_tgt_gaap_mrb",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mtt_valn_tgt_gaap_mrb, 'E','Y', '3', 'C', (size_t)&modelOffset->mtt_valn_tgt_gaap_mrb),
	CashFlowCommonData(255, "mtt_valn_tgt_gaap_sfas97rd", "fia_liab_mtt_valn_tgt_gaap_sfas97rd",  "mtt_valn_tgt_gaap_sfas97rd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mtt_valn_tgt_gaap_sfas97rd, 'E','Y', '3', 'C', (size_t)&modelOffset->mtt_valn_tgt_gaap_sfas97rd)
};

const CashFlowCommonData FIA_LIAB::mCFStaticData_256[] = 
{
	CashFlowCommonData(256, "mtt_valn_tgt_pba_scen_amt", "fia_liab_mtt_valn_tgt_pba_scen_amt",  "mtt_valn_tgt_pba_scen_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mtt_valn_tgt_pba_scen_amt, 'E','Y', '3', 'C', (size_t)&modelOffset->mtt_valn_tgt_pba_scen_amt),
	CashFlowCommonData(257, "mtt_valn_tgt_stat_tax", "fia_liab_mtt_valn_tgt_stat_tax",  "mtt_valn_tgt_stat_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mtt_valn_tgt_stat_tax, 'E','Y', '3', 'P', (size_t)&modelOffset->mtt_valn_tgt_stat_tax),
	CashFlowCommonData(258, "mva_amt_bef_crbg", "fia_liab_mva_amt_bef_crbg",  "mva_amt_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mva_amt_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->mva_amt_bef_crbg),
	CashFlowCommonData(259, "mva_amt_crbg", "fia_liab_mva_amt_crbg",  "mva_amt_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mva_amt_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->mva_amt_crbg),
	CashFlowCommonData(260, "mva_amt_excess_withdrl_crbg", "fia_liab_mva_amt_excess_withdrl_crbg",  "mva_amt_excess_withdrl_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mva_amt_excess_withdrl_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->mva_amt_excess_withdrl_crbg),
	CashFlowCommonData(261, "mva_comp_num", "fia_liab_mva_comp_num",  "mva_comp_num",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mva_comp_num, 'E','N', '3', 'P', (size_t)&modelOffset->mva_comp_num),
	CashFlowCommonData(262, "mva_comp_rate", "fia_liab_mva_comp_rate",  "mva_comp_rate",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mva_comp_rate, 'E','N', '3', 'P', (size_t)&modelOffset->mva_comp_rate),
	CashFlowCommonData(263, "mva_current_term_crbg", "fia_liab_mva_current_term_crbg",  "mva_current_term_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mva_current_term_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->mva_current_term_crbg),
	CashFlowCommonData(264, "mva_factor_bef_crbg", "fia_liab_mva_factor_bef_crbg",  "mva_factor_bef_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mva_factor_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->mva_factor_bef_crbg),
	CashFlowCommonData(265, "mva_factor_crbg", "fia_liab_mva_factor_crbg",  "mva_factor_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mva_factor_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->mva_factor_crbg),
	CashFlowCommonData(266, "mva_guar_yrs_remaining", "fia_liab_mva_guar_yrs_remaining",  "mva_guar_yrs_remaining",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mva_guar_yrs_remaining, 'E','N', '3', 'C', (size_t)&modelOffset->mva_guar_yrs_remaining),
	CashFlowCommonData(267, "mva_ratio", "fia_liab_mva_ratio",  "mva_ratio",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mva_ratio, 'E','N', '3', 'C', (size_t)&modelOffset->mva_ratio),
	CashFlowCommonData(268, "mva_ratio_bef", "fia_liab_mva_ratio_bef",  "mva_ratio_bef",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_mva_ratio_bef, 'E','N', '3', 'C', (size_t)&modelOffset->mva_ratio_bef),
	CashFlowCommonData(269, "myga_current_term_crbg", "fia_liab_myga_current_term_crbg",  "myga_current_term_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_myga_current_term_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->myga_current_term_crbg),
	CashFlowCommonData(270, "myga_term_mth_elapsed_eom_crbg", "fia_liab_myga_term_mth_elapsed_eom_crbg",  "myga_term_mth_elapsed_eom_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_myga_term_mth_elapsed_eom_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->myga_term_mth_elapsed_eom_crbg),
	CashFlowCommonData(271, "new_money_rate_crbg", "fia_liab_new_money_rate_crbg",  "new_money_rate_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_new_money_rate_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->new_money_rate_crbg),
	CashFlowCommonData(272, "nmr_7yr_govt_plus_sprd_crbg", "fia_liab_nmr_7yr_govt_plus_sprd_crbg",  "nmr_7yr_govt_plus_sprd_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_nmr_7yr_govt_plus_sprd_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->nmr_7yr_govt_plus_sprd_crbg),
	CashFlowCommonData(273, "notional_to_hedge", "fia_liab_notional_to_hedge",  "notional_to_hedge",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_notional_to_hedge, 'E','Y', '3', 'C', (size_t)&modelOffset->notional_to_hedge),
	CashFlowCommonData(274, "notional_to_hedge_cap", "fia_liab_notional_to_hedge_cap",  "notional_to_hedge_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_notional_to_hedge_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->notional_to_hedge_cap),
	CashFlowCommonData(275, "notional_to_hedge_index", "fia_liab_notional_to_hedge_index",  "notional_to_hedge_index",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_notional_to_hedge_index, 'E','Y', '3', 'C', (size_t)&modelOffset->notional_to_hedge_index),
	CashFlowCommonData(276, "notional_to_hedge_long_strike", "fia_liab_notional_to_hedge_long_strike",  "notional_to_hedge_long_strike",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_notional_to_hedge_long_strike, 'E','Y', '3', 'C', (size_t)&modelOffset->notional_to_hedge_long_strike),
	CashFlowCommonData(277, "notional_to_hedge_net", "fia_liab_notional_to_hedge_net",  "notional_to_hedge_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_notional_to_hedge_net, 'E','Y', '3', 'C', (size_t)&modelOffset->notional_to_hedge_net),
	CashFlowCommonData(278, "opt_budget", "fia_liab_opt_budget",  "opt_budget",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_opt_budget, 'E','N', '3', 'C', (size_t)&modelOffset->opt_budget),
	CashFlowCommonData(279, "opt_budget_amt", "fia_liab_opt_budget_amt",  "opt_budget_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_opt_budget_amt, 'E','N', '3', 'C', (size_t)&modelOffset->opt_budget_amt),
	CashFlowCommonData(280, "opt_payoff", "fia_liab_opt_payoff",  "opt_payoff",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_opt_payoff, 'E','Y', '3', 'C', (size_t)&modelOffset->opt_payoff),
	CashFlowCommonData(281, "pba_rollforward_base", "fia_liab_pba_rollforward_base",  "pba_rollforward_base",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pba_rollforward_base, 'E','Y', '3', 'P', (size_t)&modelOffset->pba_rollforward_base),
	CashFlowCommonData(282, "pba_rollforward_base_issued", "fia_liab_pba_rollforward_base_issued",  "pba_rollforward_base_issued",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pba_rollforward_base_issued, 'E','Y', '3', 'P', (size_t)&modelOffset->pba_rollforward_base_issued),
	CashFlowCommonData(283, "pba_rollforward_factor", "fia_liab_pba_rollforward_factor",  "pba_rollforward_factor",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pba_rollforward_factor, 'E','N', '3', 'P', (size_t)&modelOffset->pba_rollforward_factor),
	CashFlowCommonData(284, "pfwd_entitlement", "fia_liab_pfwd_entitlement",  "pfwd_entitlement",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pfwd_entitlement, 'E','Y', '3', 'P', (size_t)&modelOffset->pfwd_entitlement),
	CashFlowCommonData(285, "pfwd_entitlement_remaining_bom", "fia_liab_pfwd_entitlement_remaining_bom",  "pfwd_entitlement_remaining_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pfwd_entitlement_remaining_bom, 'E','Y', '3', 'P', (size_t)&modelOffset->pfwd_entitlement_remaining_bom),
	CashFlowCommonData(286, "pfwd_entitlement_remaining_e", "fia_liab_pfwd_entitlement_remaining_e",  "pfwd_entitlement_remaining_e",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pfwd_entitlement_remaining_e, 'E','Y', '3', 'P', (size_t)&modelOffset->pfwd_entitlement_remaining_e),
	CashFlowCommonData(287, "pfwd_rate_dynamic", "fia_liab_pfwd_rate_dynamic",  "pfwd_rate_dynamic",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pfwd_rate_dynamic, 'E','N', '3', 'C', (size_t)&modelOffset->pfwd_rate_dynamic),
	CashFlowCommonData(288, "pfwd_rate_mthly_fund_val", "fia_liab_pfwd_rate_mthly_fund_val",  "pfwd_rate_mthly_fund_val",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pfwd_rate_mthly_fund_val, 'E','N', '3', 'C', (size_t)&modelOffset->pfwd_rate_mthly_fund_val),
	CashFlowCommonData(289, "pfwd_surr_contract_val", "fia_liab_pfwd_surr_contract_val",  "pfwd_surr_contract_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pfwd_surr_contract_val, 'E','Y', '3', 'C', (size_t)&modelOffset->pfwd_surr_contract_val),
	CashFlowCommonData(290, "pfwd_surr_cumul", "fia_liab_pfwd_surr_cumul",  "pfwd_surr_cumul",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pfwd_surr_cumul, 'E','Y', '3', 'C', (size_t)&modelOffset->pfwd_surr_cumul),
	CashFlowCommonData(291, "pfwd_surr_cumul_bom", "fia_liab_pfwd_surr_cumul_bom",  "pfwd_surr_cumul_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pfwd_surr_cumul_bom, 'E','Y', '3', 'C', (size_t)&modelOffset->pfwd_surr_cumul_bom),
	CashFlowCommonData(292, "pfwd_surr_curr_pol_yr", "fia_liab_pfwd_surr_curr_pol_yr",  "pfwd_surr_curr_pol_yr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pfwd_surr_curr_pol_yr, 'E','Y', '3', 'C', (size_t)&modelOffset->pfwd_surr_curr_pol_yr),
	CashFlowCommonData(293, "pfwd_surr_fund_val", "fia_liab_pfwd_surr_fund_val",  "pfwd_surr_fund_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pfwd_surr_fund_val, 'E','Y', '3', 'C', (size_t)&modelOffset->pfwd_surr_fund_val),
	CashFlowCommonData(294, "pfwd_use_crbg", "fia_liab_pfwd_use_crbg",  "pfwd_use_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pfwd_use_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->pfwd_use_crbg),
	CashFlowCommonData(295, "pol_mth", "fia_liab_pol_mth",  "pol_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pol_mth, 'B','N', '3', 'C', (size_t)&modelOffset->pol_mth),
	CashFlowCommonData(296, "pol_yr", "fia_liab_pol_yr",  "pol_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pol_yr, 'B','N', '3', 'C', (size_t)&modelOffset->pol_yr),
	CashFlowCommonData(297, "policies_b", "fia_liab_policies_b",  "policies_b",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_policies_b, 'B','N', '3', 'C', (size_t)&modelOffset->policies_b),
	CashFlowCommonData(298, "policies_female_inf_crbg", "fia_liab_policies_female_inf_crbg",  "policies_female_inf_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_policies_female_inf_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->policies_female_inf_crbg),
	CashFlowCommonData(299, "policies_inf", "fia_liab_policies_inf",  "policies_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_policies_inf, 'E','N', '3', 'C', (size_t)&modelOffset->policies_inf),
	CashFlowCommonData(300, "policies_issued", "fia_liab_policies_issued",  "policies_issued",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_policies_issued, 'B','N', '3', 'C', (size_t)&modelOffset->policies_issued),
	CashFlowCommonData(301, "policies_joint_inf_crbg", "fia_liab_policies_joint_inf_crbg",  "policies_joint_inf_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_policies_joint_inf_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->policies_joint_inf_crbg),
	CashFlowCommonData(302, "policies_last_survivor_inf_crbg", "fia_liab_policies_last_survivor_inf_crbg",  "policies_last_survivor_inf_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_policies_last_survivor_inf_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->policies_last_survivor_inf_crbg),
	CashFlowCommonData(303, "policies_male_inf_crbg", "fia_liab_policies_male_inf_crbg",  "policies_male_inf_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_policies_male_inf_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->policies_male_inf_crbg),
	CashFlowCommonData(304, "port_yld_aft_tax", "fia_liab_port_yld_aft_tax",  "port_yld_aft_tax",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_port_yld_aft_tax, 'E','N', '3', 'C', (size_t)&modelOffset->port_yld_aft_tax),
	CashFlowCommonData(305, "prem_bonus", "fia_liab_prem_bonus",  "prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_bonus, 'B','Y', '3', 'C', (size_t)&modelOffset->prem_bonus),
	CashFlowCommonData(306, "prem_bonus_base_e_bef_crbg", "fia_liab_prem_bonus_base_e_bef_crbg",  "prem_bonus_base_e_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_bonus_base_e_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->prem_bonus_base_e_bef_crbg),
	CashFlowCommonData(307, "prem_bonus_base_e_crbg", "fia_liab_prem_bonus_base_e_crbg",  "prem_bonus_base_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_bonus_base_e_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->prem_bonus_base_e_crbg),
	CashFlowCommonData(308, "prem_bonus_base_reduction_fct_crbg", "fia_liab_prem_bonus_base_reduction_fct_crbg",  "prem_bonus_base_reduction_fct_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_bonus_base_reduction_fct_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->prem_bonus_base_reduction_fct_crbg),
	CashFlowCommonData(309, "prem_bonus_recap_e_bef_crbg", "fia_liab_prem_bonus_recap_e_bef_crbg",  "prem_bonus_recap_e_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_bonus_recap_e_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->prem_bonus_recap_e_bef_crbg),
	CashFlowCommonData(310, "prem_bonus_recap_e_crbg", "fia_liab_prem_bonus_recap_e_crbg",  "prem_bonus_recap_e_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_bonus_recap_e_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->prem_bonus_recap_e_crbg),
	CashFlowCommonData(311, "prem_cumul", "fia_liab_prem_cumul",  "prem_cumul",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_cumul, 'E','N', '3', 'C', (size_t)&modelOffset->prem_cumul),
	CashFlowCommonData(312, "prem_cumul_bef", "fia_liab_prem_cumul_bef",  "prem_cumul_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_cumul_bef, 'E','N', '3', 'C', (size_t)&modelOffset->prem_cumul_bef),
	CashFlowCommonData(313, "prem_cumul_net_wdl_bef_crbg", "fia_liab_prem_cumul_net_wdl_bef_crbg",  "prem_cumul_net_wdl_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_cumul_net_wdl_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->prem_cumul_net_wdl_bef_crbg),
	CashFlowCommonData(314, "prem_cumul_net_wdl_crbg", "fia_liab_prem_cumul_net_wdl_crbg",  "prem_cumul_net_wdl_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_cumul_net_wdl_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->prem_cumul_net_wdl_crbg),
	CashFlowCommonData(315, "prem_cumul_prop_wdl_bef_crbg", "fia_liab_prem_cumul_prop_wdl_bef_crbg",  "prem_cumul_prop_wdl_bef_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_cumul_prop_wdl_bef_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->prem_cumul_prop_wdl_bef_crbg),
	CashFlowCommonData(316, "prem_cumul_prop_wdl_crbg", "fia_liab_prem_cumul_prop_wdl_crbg",  "prem_cumul_prop_wdl_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_cumul_prop_wdl_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->prem_cumul_prop_wdl_crbg),
	CashFlowCommonData(317, "prem_issued", "fia_liab_prem_issued",  "prem_issued",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_issued, 'B','N', '3', 'C', (size_t)&modelOffset->prem_issued),
	CashFlowCommonData(318, "prem_paid", "fia_liab_prem_paid",  "prem_paid",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_paid, 'B','Y', '3', 'P', (size_t)&modelOffset->prem_paid),
	CashFlowCommonData(319, "prem_paid_net", "fia_liab_prem_paid_net",  "prem_paid_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_paid_net, 'B','Y', '3', 'P', (size_t)&modelOffset->prem_paid_net),
	CashFlowCommonData(320, "prem_tax", "fia_liab_prem_tax",  "prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_prem_tax, 'B','Y', '3', 'C', (size_t)&modelOffset->prem_tax),
	CashFlowCommonData(321, "pv_ann_ben_disc_uel_crbg", "fia_liab_pv_ann_ben_disc_uel_crbg",  "pv_ann_ben_disc_uel_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pv_ann_ben_disc_uel_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->pv_ann_ben_disc_uel_crbg),
	CashFlowCommonData(322, "pv_bom_cf_disc_uel_crbg", "fia_liab_pv_bom_cf_disc_uel_crbg",  "pv_bom_cf_disc_uel_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pv_bom_cf_disc_uel_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->pv_bom_cf_disc_uel_crbg),
	CashFlowCommonData(323, "pv_eom_cf_disc_uel_crbg", "fia_liab_pv_eom_cf_disc_uel_crbg",  "pv_eom_cf_disc_uel_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pv_eom_cf_disc_uel_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->pv_eom_cf_disc_uel_crbg),
	CashFlowCommonData(324, "pv_gmwb_ben_itm_current_crbg", "fia_liab_pv_gmwb_ben_itm_current_crbg",  "pv_gmwb_ben_itm_current_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pv_gmwb_ben_itm_current_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->pv_gmwb_ben_itm_current_crbg),
	CashFlowCommonData(325, "pv_gmwb_ben_itm_init_rate_crbg", "fia_liab_pv_gmwb_ben_itm_init_rate_crbg",  "pv_gmwb_ben_itm_init_rate_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pv_gmwb_ben_itm_init_rate_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->pv_gmwb_ben_itm_init_rate_crbg),
	CashFlowCommonData(326, "pv_gmwb_benefit_itm", "fia_liab_pv_gmwb_benefit_itm",  "pv_gmwb_benefit_itm",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pv_gmwb_benefit_itm, 'E','N', '3', 'P', (size_t)&modelOffset->pv_gmwb_benefit_itm),
	CashFlowCommonData(327, "pv_gmwb_mawp_crbg", "fia_liab_pv_gmwb_mawp_crbg",  "pv_gmwb_mawp_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pv_gmwb_mawp_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->pv_gmwb_mawp_crbg),
	CashFlowCommonData(328, "pv_gmwb_pip_pct_crbg", "fia_liab_pv_gmwb_pip_pct_crbg",  "pv_gmwb_pip_pct_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pv_gmwb_pip_pct_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->pv_gmwb_pip_pct_crbg),
	CashFlowCommonData(329, "pv_sfc_ben_itm_crbg", "fia_liab_pv_sfc_ben_itm_crbg",  "pv_sfc_ben_itm_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_pv_sfc_ben_itm_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->pv_sfc_ben_itm_crbg),
	CashFlowCommonData(330, "rand_num_non_us_return_crbg", "fia_liab_rand_num_non_us_return_crbg",  "rand_num_non_us_return_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rand_num_non_us_return_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->rand_num_non_us_return_crbg),
	CashFlowCommonData(331, "rbc", "fia_liab_rbc",  "rbc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rbc, 'E','N', '3', 'C', (size_t)&modelOffset->rbc),
	CashFlowCommonData(332, "rbc_c1", "fia_liab_rbc_c1",  "rbc_c1",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rbc_c1, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c1),
	CashFlowCommonData(333, "rbc_c2", "fia_liab_rbc_c2",  "rbc_c2",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rbc_c2, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c2),
	CashFlowCommonData(334, "rbc_c2_nar", "fia_liab_rbc_c2_nar",  "rbc_c2_nar",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rbc_c2_nar, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c2_nar),
	CashFlowCommonData(335, "rbc_c3", "fia_liab_rbc_c3",  "rbc_c3",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rbc_c3, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3),
	CashFlowCommonData(336, "rbc_c3_base_ann_high_risk", "fia_liab_rbc_c3_base_ann_high_risk",  "rbc_c3_base_ann_high_risk",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rbc_c3_base_ann_high_risk, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3_base_ann_high_risk),
	CashFlowCommonData(337, "rbc_c3_base_ann_low_risk", "fia_liab_rbc_c3_base_ann_low_risk",  "rbc_c3_base_ann_low_risk",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rbc_c3_base_ann_low_risk, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3_base_ann_low_risk),
	CashFlowCommonData(338, "rbc_c3_base_ann_medium_risk", "fia_liab_rbc_c3_base_ann_medium_risk",  "rbc_c3_base_ann_medium_risk",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rbc_c3_base_ann_medium_risk, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3_base_ann_medium_risk),
	CashFlowCommonData(339, "rbc_c3_mp", "fia_liab_rbc_c3_mp",  "rbc_c3_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rbc_c3_mp, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3_mp),
	CashFlowCommonData(340, "rbc_c3_stoch_amt", "fia_liab_rbc_c3_stoch_amt",  "rbc_c3_stoch_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rbc_c3_stoch_amt, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3_stoch_amt),
	CashFlowCommonData(341, "rbc_c3_stoch_amt_unhedged", "fia_liab_rbc_c3_stoch_amt_unhedged",  "rbc_c3_stoch_amt_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rbc_c3_stoch_amt_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3_stoch_amt_unhedged),
	CashFlowCommonData(342, "rbc_c3_unhedged", "fia_liab_rbc_c3_unhedged",  "rbc_c3_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rbc_c3_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c3_unhedged),
	CashFlowCommonData(343, "rbc_c4", "fia_liab_rbc_c4",  "rbc_c4",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_rbc_c4, 'E','N', '3', 'C', (size_t)&modelOffset->rbc_c4),
	CashFlowCommonData(344, "reins_ann_benefits_eom", "fia_liab_reins_ann_benefits_eom",  "reins_ann_benefits_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_ann_benefits_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_ann_benefits_eom),
	CashFlowCommonData(345, "reins_ann_claims_gmwb", "fia_liab_reins_ann_claims_gmwb",  "reins_ann_claims_gmwb",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_ann_claims_gmwb, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_ann_claims_gmwb),
	CashFlowCommonData(346, "reins_cash_flow_bom", "fia_liab_reins_cash_flow_bom",  "reins_cash_flow_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_cash_flow_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_cash_flow_bom),
	CashFlowCommonData(347, "reins_cash_flow_eom", "fia_liab_reins_cash_flow_eom",  "reins_cash_flow_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_cash_flow_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->reins_cash_flow_eom),
	CashFlowCommonData(348, "reins_cash_flow_int", "fia_liab_reins_cash_flow_int",  "reins_cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_cash_flow_int, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_cash_flow_int),
	CashFlowCommonData(349, "reins_cash_val", "fia_liab_reins_cash_val",  "reins_cash_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_cash_val, 'E','N', '3', 'C', (size_t)&modelOffset->reins_cash_val),
	CashFlowCommonData(350, "reins_comm_chargeback_reimb", "fia_liab_reins_comm_chargeback_reimb",  "reins_comm_chargeback_reimb",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_comm_chargeback_reimb, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_comm_chargeback_reimb),
	CashFlowCommonData(351, "reins_comm_reimb", "fia_liab_reins_comm_reimb",  "reins_comm_reimb",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_comm_reimb, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_comm_reimb),
	CashFlowCommonData(352, "reins_comm_reimb_bom", "fia_liab_reins_comm_reimb_bom",  "reins_comm_reimb_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_comm_reimb_bom, 'B','Y', '3', 'P', (size_t)&modelOffset->reins_comm_reimb_bom),
	CashFlowCommonData(353, "reins_comm_reimb_eom", "fia_liab_reins_comm_reimb_eom",  "reins_comm_reimb_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_comm_reimb_eom, 'E','Y', '3', 'P', (size_t)&modelOffset->reins_comm_reimb_eom),
	CashFlowCommonData(354, "reins_dth_ben_inf", "fia_liab_reins_dth_ben_inf",  "reins_dth_ben_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_dth_ben_inf, 'E','N', '3', 'C', (size_t)&modelOffset->reins_dth_ben_inf),
	CashFlowCommonData(355, "reins_dth_benefits", "fia_liab_reins_dth_benefits",  "reins_dth_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_dth_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_dth_benefits),
	CashFlowCommonData(356, "reins_exp", "fia_liab_reins_exp",  "reins_exp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_exp, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_exp),
	CashFlowCommonData(357, "reins_exp_reimb", "fia_liab_reins_exp_reimb",  "reins_exp_reimb",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_exp_reimb, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_exp_reimb),
	CashFlowCommonData(358, "reins_exp_reimb_bom", "fia_liab_reins_exp_reimb_bom",  "reins_exp_reimb_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_exp_reimb_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_exp_reimb_bom),
	CashFlowCommonData(359, "reins_exp_reimb_eom", "fia_liab_reins_exp_reimb_eom",  "reins_exp_reimb_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_exp_reimb_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_exp_reimb_eom),
	CashFlowCommonData(360, "reins_gaap_ben_res", "fia_liab_reins_gaap_ben_res",  "reins_gaap_ben_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_ben_res, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_ben_res),
	CashFlowCommonData(361, "reins_gaap_capzd_comm_bom", "fia_liab_reins_gaap_capzd_comm_bom",  "reins_gaap_capzd_comm_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_capzd_comm_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_capzd_comm_bom),
	CashFlowCommonData(362, "reins_gaap_capzd_comm_eom", "fia_liab_reins_gaap_capzd_comm_eom",  "reins_gaap_capzd_comm_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_capzd_comm_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_capzd_comm_eom),
	CashFlowCommonData(363, "reins_gaap_capzd_prem_bonus", "fia_liab_reins_gaap_capzd_prem_bonus",  "reins_gaap_capzd_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_capzd_prem_bonus, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_capzd_prem_bonus),
	CashFlowCommonData(364, "reins_gaap_cash_flow_int", "fia_liab_reins_gaap_cash_flow_int",  "reins_gaap_cash_flow_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_cash_flow_int, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_cash_flow_int),
	CashFlowCommonData(365, "reins_gaap_chg_inc", "fia_liab_reins_gaap_chg_inc",  "reins_gaap_chg_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_chg_inc, 'B','Y', '3', 'P', (size_t)&modelOffset->reins_gaap_chg_inc),
	CashFlowCommonData(366, "reins_gaap_comm_excess_bom", "fia_liab_reins_gaap_comm_excess_bom",  "reins_gaap_comm_excess_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_comm_excess_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_comm_excess_bom),
	CashFlowCommonData(367, "reins_gaap_comm_excess_eom", "fia_liab_reins_gaap_comm_excess_eom",  "reins_gaap_comm_excess_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_comm_excess_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_comm_excess_eom),
	CashFlowCommonData(368, "reins_gaap_comm_trail_bom", "fia_liab_reins_gaap_comm_trail_bom",  "reins_gaap_comm_trail_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_comm_trail_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_comm_trail_bom),
	CashFlowCommonData(369, "reins_gaap_comm_trail_eom", "fia_liab_reins_gaap_comm_trail_eom",  "reins_gaap_comm_trail_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_comm_trail_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_comm_trail_eom),
	CashFlowCommonData(370, "reins_gaap_cost", "fia_liab_reins_gaap_cost",  "reins_gaap_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_cost, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_cost),
	CashFlowCommonData(371, "reins_gaap_credited_int", "fia_liab_reins_gaap_credited_int",  "reins_gaap_credited_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_credited_int, 'E','Y', '3', 'P', (size_t)&modelOffset->reins_gaap_credited_int),
	CashFlowCommonData(372, "reins_gaap_dac", "fia_liab_reins_gaap_dac",  "reins_gaap_dac",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_dac, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_dac),
	CashFlowCommonData(373, "reins_gaap_dac_incr", "fia_liab_reins_gaap_dac_incr",  "reins_gaap_dac_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_dac_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_dac_incr),
	CashFlowCommonData(374, "reins_gaap_inv_inc_res", "fia_liab_reins_gaap_inv_inc_res",  "reins_gaap_inv_inc_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_inv_inc_res, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_inv_inc_res),
	CashFlowCommonData(375, "reins_gaap_liab_net", "fia_liab_reins_gaap_liab_net",  "reins_gaap_liab_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_liab_net, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_liab_net),
	CashFlowCommonData(376, "reins_gaap_loads_deducted", "fia_liab_reins_gaap_loads_deducted",  "reins_gaap_loads_deducted",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_loads_deducted, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_loads_deducted),
	CashFlowCommonData(377, "reins_gaap_maint_exp_bom", "fia_liab_reins_gaap_maint_exp_bom",  "reins_gaap_maint_exp_bom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_maint_exp_bom, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_maint_exp_bom),
	CashFlowCommonData(378, "reins_gaap_maint_exp_eom", "fia_liab_reins_gaap_maint_exp_eom",  "reins_gaap_maint_exp_eom",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_maint_exp_eom, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_maint_exp_eom),
	CashFlowCommonData(379, "reins_gaap_mrb_liab", "fia_liab_reins_gaap_mrb_liab",  "reins_gaap_mrb_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_mrb_liab, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_mrb_liab),
	CashFlowCommonData(380, "reins_gaap_mrb_liab_incr", "fia_liab_reins_gaap_mrb_liab_incr",  "reins_gaap_mrb_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_mrb_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_mrb_liab_incr),
	CashFlowCommonData(381, "reins_gaap_prem_bonus", "fia_liab_reins_gaap_prem_bonus",  "reins_gaap_prem_bonus",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_prem_bonus, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_prem_bonus),
	CashFlowCommonData(382, "reins_gaap_prem_tax", "fia_liab_reins_gaap_prem_tax",  "reins_gaap_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_prem_tax, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_prem_tax),
	CashFlowCommonData(383, "reins_gaap_recoveries", "fia_liab_reins_gaap_recoveries",  "reins_gaap_recoveries",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_recoveries, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_recoveries),
	CashFlowCommonData(384, "reins_gaap_sfas133_liab", "fia_liab_reins_gaap_sfas133_liab",  "reins_gaap_sfas133_liab",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_sfas133_liab, 'E','N', '3', 'C', (size_t)&modelOffset->reins_gaap_sfas133_liab),
	CashFlowCommonData(385, "reins_gaap_sfas133_liab_incr", "fia_liab_reins_gaap_sfas133_liab_incr",  "reins_gaap_sfas133_liab_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_sfas133_liab_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_sfas133_liab_incr),
	CashFlowCommonData(386, "reins_gaap_surr_inc", "fia_liab_reins_gaap_surr_inc",  "reins_gaap_surr_inc",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_gaap_surr_inc, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_gaap_surr_inc),
	CashFlowCommonData(387, "reins_inv_inc_res", "fia_liab_reins_inv_inc_res",  "reins_inv_inc_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_inv_inc_res, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_inv_inc_res),
	CashFlowCommonData(388, "reins_maturity_benefits", "fia_liab_reins_maturity_benefits",  "reins_maturity_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_maturity_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_maturity_benefits),
	CashFlowCommonData(389, "reins_prem", "fia_liab_reins_prem",  "reins_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_prem, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_prem),
	CashFlowCommonData(390, "reins_prem_base", "fia_liab_reins_prem_base",  "reins_prem_base",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_prem_base, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_prem_base),
	CashFlowCommonData(391, "reins_prem_gmwb", "fia_liab_reins_prem_gmwb",  "reins_prem_gmwb",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_prem_gmwb, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_prem_gmwb),
	CashFlowCommonData(392, "reins_prem_tax", "fia_liab_reins_prem_tax",  "reins_prem_tax",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_prem_tax, 'B','Y', '3', 'C', (size_t)&modelOffset->reins_prem_tax),
	CashFlowCommonData(393, "reins_stat_cost", "fia_liab_reins_stat_cost",  "reins_stat_cost",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_stat_cost, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_stat_cost),
	CashFlowCommonData(394, "reins_stat_res", "fia_liab_reins_stat_res",  "reins_stat_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_stat_res, 'E','N', '3', 'C', (size_t)&modelOffset->reins_stat_res),
	CashFlowCommonData(395, "reins_stat_res_incr", "fia_liab_reins_stat_res_incr",  "reins_stat_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_stat_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_stat_res_incr),
	CashFlowCommonData(396, "reins_stat_res_mp", "fia_liab_reins_stat_res_mp",  "reins_stat_res_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_stat_res_mp, 'E','N', '3', 'C', (size_t)&modelOffset->reins_stat_res_mp),
	CashFlowCommonData(397, "reins_stat_res_npr", "fia_liab_reins_stat_res_npr",  "reins_stat_res_npr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_stat_res_npr, 'E','N', '3', 'C', (size_t)&modelOffset->reins_stat_res_npr),
	CashFlowCommonData(398, "reins_stat_res_unhedged", "fia_liab_reins_stat_res_unhedged",  "reins_stat_res_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_stat_res_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->reins_stat_res_unhedged),
	CashFlowCommonData(399, "reins_surr_benefits", "fia_liab_reins_surr_benefits",  "reins_surr_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_surr_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_surr_benefits),
	CashFlowCommonData(400, "reins_tax_res", "fia_liab_reins_tax_res",  "reins_tax_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_tax_res, 'E','N', '3', 'C', (size_t)&modelOffset->reins_tax_res),
	CashFlowCommonData(401, "reins_tax_res_incr", "fia_liab_reins_tax_res_incr",  "reins_tax_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_tax_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_tax_res_incr),
	CashFlowCommonData(402, "reins_tax_res_mp", "fia_liab_reins_tax_res_mp",  "reins_tax_res_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_tax_res_mp, 'E','N', '3', 'C', (size_t)&modelOffset->reins_tax_res_mp),
	CashFlowCommonData(403, "reins_withdrl_benefits", "fia_liab_reins_withdrl_benefits",  "reins_withdrl_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_reins_withdrl_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->reins_withdrl_benefits),
	CashFlowCommonData(404, "shock_lapse_phase_crbg", "fia_liab_shock_lapse_phase_crbg",  "shock_lapse_phase_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_shock_lapse_phase_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->shock_lapse_phase_crbg),
	CashFlowCommonData(405, "shock_lapse_yr_ind_crbg", "fia_liab_shock_lapse_yr_ind_crbg",  "shock_lapse_yr_ind_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_shock_lapse_yr_ind_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->shock_lapse_yr_ind_crbg),
	CashFlowCommonData(406, "startup", "fia_liab_startup",  "startup",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(407, "stat_res", "fia_liab_stat_res",  "stat_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_res),
	CashFlowCommonData(408, "stat_res_carvm", "fia_liab_stat_res_carvm",  "stat_res_carvm",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_carvm, 'E','N', '3', 'P', (size_t)&modelOffset->stat_res_carvm),
	CashFlowCommonData(409, "stat_res_carvm_net", "fia_liab_stat_res_carvm_net",  "stat_res_carvm_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_carvm_net, 'E','N', '3', 'P', (size_t)&modelOffset->stat_res_carvm_net),
	CashFlowCommonData(410, "stat_res_excess", "fia_liab_stat_res_excess",  "stat_res_excess",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_excess, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_res_excess),
	CashFlowCommonData(411, "stat_res_excess_unhedged", "fia_liab_stat_res_excess_unhedged",  "stat_res_excess_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_excess_unhedged, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_res_excess_unhedged),
	CashFlowCommonData(412, "stat_res_incr", "fia_liab_stat_res_incr",  "stat_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->stat_res_incr),
	CashFlowCommonData(413, "stat_res_mp", "fia_liab_stat_res_mp",  "stat_res_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_mp, 'E','N', '3', 'P', (size_t)&modelOffset->stat_res_mp),
	CashFlowCommonData(414, "stat_res_mp_unhedged", "fia_liab_stat_res_mp_unhedged",  "stat_res_mp_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_mp_unhedged, 'E','N', '3', 'P', (size_t)&modelOffset->stat_res_mp_unhedged),
	CashFlowCommonData(415, "stat_res_net", "fia_liab_stat_res_net",  "stat_res_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_net, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net),
	CashFlowCommonData(416, "stat_res_net_excess", "fia_liab_stat_res_net_excess",  "stat_res_net_excess",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_net_excess, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_excess),
	CashFlowCommonData(417, "stat_res_net_excess_unhedged", "fia_liab_stat_res_net_excess_unhedged",  "stat_res_net_excess_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_net_excess_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_excess_unhedged),
	CashFlowCommonData(418, "stat_res_net_mp", "fia_liab_stat_res_net_mp",  "stat_res_net_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_net_mp, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_mp),
	CashFlowCommonData(419, "stat_res_net_mp_unhedged", "fia_liab_stat_res_net_mp_unhedged",  "stat_res_net_mp_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_net_mp_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_mp_unhedged),
	CashFlowCommonData(420, "stat_res_net_npr", "fia_liab_stat_res_net_npr",  "stat_res_net_npr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_net_npr, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_npr),
	CashFlowCommonData(421, "stat_res_net_npr_unhedged", "fia_liab_stat_res_net_npr_unhedged",  "stat_res_net_npr_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_net_npr_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_npr_unhedged),
	CashFlowCommonData(422, "stat_res_net_stoch_res", "fia_liab_stat_res_net_stoch_res",  "stat_res_net_stoch_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_net_stoch_res, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_stoch_res),
	CashFlowCommonData(423, "stat_res_net_stoch_res_unhedged", "fia_liab_stat_res_net_stoch_res_unhedged",  "stat_res_net_stoch_res_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_net_stoch_res_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_stoch_res_unhedged),
	CashFlowCommonData(424, "stat_res_net_unhedged", "fia_liab_stat_res_net_unhedged",  "stat_res_net_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_net_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_net_unhedged),
	CashFlowCommonData(425, "stat_res_npr", "fia_liab_stat_res_npr",  "stat_res_npr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_npr, 'E','N', '3', 'P', (size_t)&modelOffset->stat_res_npr),
	CashFlowCommonData(426, "stat_res_npr_unhedged", "fia_liab_stat_res_npr_unhedged",  "stat_res_npr_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_npr_unhedged, 'E','N', '3', 'P', (size_t)&modelOffset->stat_res_npr_unhedged),
	CashFlowCommonData(427, "stat_res_stoch_res", "fia_liab_stat_res_stoch_res",  "stat_res_stoch_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_stoch_res, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_stoch_res),
	CashFlowCommonData(428, "stat_res_stoch_res_unhedged", "fia_liab_stat_res_stoch_res_unhedged",  "stat_res_stoch_res_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_stoch_res_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_stoch_res_unhedged),
	CashFlowCommonData(429, "stat_res_unhedged", "fia_liab_stat_res_unhedged",  "stat_res_unhedged",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_stat_res_unhedged, 'E','N', '3', 'C', (size_t)&modelOffset->stat_res_unhedged),
	CashFlowCommonData(430, "surr_benefits", "fia_liab_surr_benefits",  "surr_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_surr_benefits, 'E','Y', '3', 'P', (size_t)&modelOffset->surr_benefits),
	CashFlowCommonData(431, "surr_chg", "fia_liab_surr_chg",  "surr_chg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_surr_chg, 'E','Y', '3', 'P', (size_t)&modelOffset->surr_chg),
	CashFlowCommonData(432, "surr_chg_excess_withdrl_crbg", "fia_liab_surr_chg_excess_withdrl_crbg",  "surr_chg_excess_withdrl_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_surr_chg_excess_withdrl_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->surr_chg_excess_withdrl_crbg),
	CashFlowCommonData(433, "surr_chg_inf", "fia_liab_surr_chg_inf",  "surr_chg_inf",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_surr_chg_inf, 'E','N', '3', 'C', (size_t)&modelOffset->surr_chg_inf),
	CashFlowCommonData(434, "surr_chg_inf_bef", "fia_liab_surr_chg_inf_bef",  "surr_chg_inf_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_surr_chg_inf_bef, 'M','N', '3', 'P', (size_t)&modelOffset->surr_chg_inf_bef),
	CashFlowCommonData(435, "surr_chg_inf_wo_mva", "fia_liab_surr_chg_inf_wo_mva",  "surr_chg_inf_wo_mva",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_surr_chg_inf_wo_mva, 'E','N', '3', 'C', (size_t)&modelOffset->surr_chg_inf_wo_mva),
	CashFlowCommonData(436, "surr_chg_inf_wo_mva_bef", "fia_liab_surr_chg_inf_wo_mva_bef",  "surr_chg_inf_wo_mva_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_surr_chg_inf_wo_mva_bef, 'M','N', '3', 'P', (size_t)&modelOffset->surr_chg_inf_wo_mva_bef),
	CashFlowCommonData(437, "surr_chg_pct_crbg", "fia_liab_surr_chg_pct_crbg",  "surr_chg_pct_crbg",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_surr_chg_pct_crbg, 'E','Y', '3', 'P', (size_t)&modelOffset->surr_chg_pct_crbg),
	CashFlowCommonData(438, "surv", "fia_liab_surv",  "surv",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_surv, 'E','N', '3', 'C', (size_t)&modelOffset->surv),
	CashFlowCommonData(439, "surv_period", "fia_liab_surv_period",  "surv_period",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_surv_period, 'E','N', '3', 'C', (size_t)&modelOffset->surv_period),
	CashFlowCommonData(440, "tax_bk_prof", "fia_liab_tax_bk_prof",  "tax_bk_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_bk_prof, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_bk_prof),
	CashFlowCommonData(441, "tax_bk_prof_ytd", "fia_liab_tax_bk_prof_ytd",  "tax_bk_prof_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_bk_prof_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->tax_bk_prof_ytd),
	CashFlowCommonData(442, "tax_capzd_prem", "fia_liab_tax_capzd_prem",  "tax_capzd_prem",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_capzd_prem, 'B','Y', '3', 'C', (size_t)&modelOffset->tax_capzd_prem),
	CashFlowCommonData(443, "tax_capzd_prem_amortzn", "fia_liab_tax_capzd_prem_amortzn",  "tax_capzd_prem_amortzn",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_capzd_prem_amortzn, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_capzd_prem_amortzn),
	CashFlowCommonData(444, "tax_capzd_prem_unamortzd", "fia_liab_tax_capzd_prem_unamortzd",  "tax_capzd_prem_unamortzd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_capzd_prem_unamortzd, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_capzd_prem_unamortzd),
	CashFlowCommonData(445, "tax_earnings_accum", "fia_liab_tax_earnings_accum",  "tax_earnings_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_earnings_accum, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_earnings_accum),
	CashFlowCommonData(446, "tax_earnings_accum_ytd", "fia_liab_tax_earnings_accum_ytd",  "tax_earnings_accum_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_earnings_accum_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->tax_earnings_accum_ytd),
	CashFlowCommonData(447, "tax_res", "fia_liab_tax_res",  "tax_res",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_res, 'E','N', '3', 'C', (size_t)&modelOffset->tax_res),
	CashFlowCommonData(448, "tax_res_carvm", "fia_liab_tax_res_carvm",  "tax_res_carvm",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_res_carvm, 'E','N', '3', 'C', (size_t)&modelOffset->tax_res_carvm),
	CashFlowCommonData(449, "tax_res_carvm_net", "fia_liab_tax_res_carvm_net",  "tax_res_carvm_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_res_carvm_net, 'E','N', '3', 'P', (size_t)&modelOffset->tax_res_carvm_net),
	CashFlowCommonData(450, "tax_res_incr", "fia_liab_tax_res_incr",  "tax_res_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_res_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_res_incr),
	CashFlowCommonData(451, "tax_res_mp", "fia_liab_tax_res_mp",  "tax_res_mp",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_res_mp, 'E','N', '3', 'P', (size_t)&modelOffset->tax_res_mp),
	CashFlowCommonData(452, "tax_tgt_cap", "fia_liab_tax_tgt_cap",  "tax_tgt_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_tgt_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->tax_tgt_cap),
	CashFlowCommonData(453, "tax_tgt_cap_ytd", "fia_liab_tax_tgt_cap_ytd",  "tax_tgt_cap_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tax_tgt_cap_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->tax_tgt_cap_ytd),
	CashFlowCommonData(454, "taxable_inc_bk_prof", "fia_liab_taxable_inc_bk_prof",  "taxable_inc_bk_prof",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_taxable_inc_bk_prof, 'E','Y', '3', 'C', (size_t)&modelOffset->taxable_inc_bk_prof),
	CashFlowCommonData(455, "taxable_inc_bk_prof_ytd", "fia_liab_taxable_inc_bk_prof_ytd",  "taxable_inc_bk_prof_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_taxable_inc_bk_prof_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_bk_prof_ytd),
	CashFlowCommonData(456, "taxable_inc_carryfwd_addn_ytd", "fia_liab_taxable_inc_carryfwd_addn_ytd",  "taxable_inc_carryfwd_addn_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_taxable_inc_carryfwd_addn_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_carryfwd_addn_ytd),
	CashFlowCommonData(457, "taxable_inc_carryfwd_applied_ytd", "fia_liab_taxable_inc_carryfwd_applied_ytd",  "taxable_inc_carryfwd_applied_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_taxable_inc_carryfwd_applied_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_carryfwd_applied_ytd),
	CashFlowCommonData(458, "taxable_inc_carryfwd_avail", "fia_liab_taxable_inc_carryfwd_avail",  "taxable_inc_carryfwd_avail",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_taxable_inc_carryfwd_avail, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_carryfwd_avail),
	CashFlowCommonData(459, "taxable_inc_earnings_accum", "fia_liab_taxable_inc_earnings_accum",  "taxable_inc_earnings_accum",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_taxable_inc_earnings_accum, 'E','Y', '3', 'C', (size_t)&modelOffset->taxable_inc_earnings_accum),
	CashFlowCommonData(460, "taxable_inc_earnings_accum_ytd", "fia_liab_taxable_inc_earnings_accum_ytd",  "taxable_inc_earnings_accum_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_taxable_inc_earnings_accum_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_earnings_accum_ytd),
	CashFlowCommonData(461, "taxable_inc_tgt_cap", "fia_liab_taxable_inc_tgt_cap",  "taxable_inc_tgt_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_taxable_inc_tgt_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->taxable_inc_tgt_cap),
	CashFlowCommonData(462, "taxable_inc_tgt_cap_ytd", "fia_liab_taxable_inc_tgt_cap_ytd",  "taxable_inc_tgt_cap_ytd",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_taxable_inc_tgt_cap_ytd, 'E','N', '3', 'C', (size_t)&modelOffset->taxable_inc_tgt_cap_ytd),
	CashFlowCommonData(463, "tgt_cap", "fia_liab_tgt_cap",  "tgt_cap",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tgt_cap, 'E','Y', '3', 'C', (size_t)&modelOffset->tgt_cap),
	CashFlowCommonData(464, "tgt_cap_effect", "fia_liab_tgt_cap_effect",  "tgt_cap_effect",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tgt_cap_effect, 'E','Y', '3', 'C', (size_t)&modelOffset->tgt_cap_effect),
	CashFlowCommonData(465, "tgt_cap_incr", "fia_liab_tgt_cap_incr",  "tgt_cap_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_tgt_cap_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->tgt_cap_incr),
	CashFlowCommonData(466, "undistrib_earnings", "fia_liab_undistrib_earnings",  "undistrib_earnings",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_undistrib_earnings, 'E','N', '3', 'C', (size_t)&modelOffset->undistrib_earnings),
	CashFlowCommonData(467, "valn_tgt_gaap_mrb", "fia_liab_valn_tgt_gaap_mrb",  "valn_tgt_gaap_mrb",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_valn_tgt_gaap_mrb, 'E','N', '3', 'P', (size_t)&modelOffset->valn_tgt_gaap_mrb),
	CashFlowCommonData(468, "valn_tgt_gaap_sfas97rd", "fia_liab_valn_tgt_gaap_sfas97rd",  "valn_tgt_gaap_sfas97rd",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_valn_tgt_gaap_sfas97rd, 'E','N', '3', 'P', (size_t)&modelOffset->valn_tgt_gaap_sfas97rd),
	CashFlowCommonData(469, "valn_tgt_pba_scen_amt", "fia_liab_valn_tgt_pba_scen_amt",  "valn_tgt_pba_scen_amt",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_valn_tgt_pba_scen_amt, 'E','N', '3', 'P', (size_t)&modelOffset->valn_tgt_pba_scen_amt),
	CashFlowCommonData(470, "valn_tgt_stat_tax", "fia_liab_valn_tgt_stat_tax",  "valn_tgt_stat_tax",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_valn_tgt_stat_tax, 'E','N', '3', 'P', (size_t)&modelOffset->valn_tgt_stat_tax),
	CashFlowCommonData(471, "withdrl_benefits", "fia_liab_withdrl_benefits",  "withdrl_benefits",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_withdrl_benefits, 'E','Y', '3', 'C', (size_t)&modelOffset->withdrl_benefits),
	CashFlowCommonData(472, "withdrl_benefits_gross_crbg", "fia_liab_withdrl_benefits_gross_crbg",  "withdrl_benefits_gross_crbg",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_withdrl_benefits_gross_crbg, 'E','Y', '3', 'C', (size_t)&modelOffset->withdrl_benefits_gross_crbg),
	CashFlowCommonData(473, "zz_cash_val_wo_mva_bef", "fia_liab_zz_cash_val_wo_mva_bef",  "cash_val_wo_mva_bef",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&FIA_LIAB_UDF::fia_liab_zz_cash_val_wo_mva_bef, 'E','N', '3', 'P', (size_t)&modelOffset->zz_cash_val_wo_mva_bef)
};
const CashFlowCommonData* FIA_LIAB::mCFStaticData[] = {
	&FIA_LIAB::mCFStaticData_0[0],
	&FIA_LIAB::mCFStaticData_0[1],
	&FIA_LIAB::mCFStaticData_0[2],
	&FIA_LIAB::mCFStaticData_0[3],
	&FIA_LIAB::mCFStaticData_0[4],
	&FIA_LIAB::mCFStaticData_0[5],
	&FIA_LIAB::mCFStaticData_0[6],
	&FIA_LIAB::mCFStaticData_0[7],
	&FIA_LIAB::mCFStaticData_0[8],
	&FIA_LIAB::mCFStaticData_0[9],
	&FIA_LIAB::mCFStaticData_0[10],
	&FIA_LIAB::mCFStaticData_0[11],
	&FIA_LIAB::mCFStaticData_0[12],
	&FIA_LIAB::mCFStaticData_0[13],
	&FIA_LIAB::mCFStaticData_0[14],
	&FIA_LIAB::mCFStaticData_0[15],
	&FIA_LIAB::mCFStaticData_0[16],
	&FIA_LIAB::mCFStaticData_0[17],
	&FIA_LIAB::mCFStaticData_0[18],
	&FIA_LIAB::mCFStaticData_0[19],
	&FIA_LIAB::mCFStaticData_0[20],
	&FIA_LIAB::mCFStaticData_0[21],
	&FIA_LIAB::mCFStaticData_0[22],
	&FIA_LIAB::mCFStaticData_0[23],
	&FIA_LIAB::mCFStaticData_0[24],
	&FIA_LIAB::mCFStaticData_0[25],
	&FIA_LIAB::mCFStaticData_0[26],
	&FIA_LIAB::mCFStaticData_0[27],
	&FIA_LIAB::mCFStaticData_0[28],
	&FIA_LIAB::mCFStaticData_0[29],
	&FIA_LIAB::mCFStaticData_0[30],
	&FIA_LIAB::mCFStaticData_0[31],
	&FIA_LIAB::mCFStaticData_0[32],
	&FIA_LIAB::mCFStaticData_0[33],
	&FIA_LIAB::mCFStaticData_0[34],
	&FIA_LIAB::mCFStaticData_0[35],
	&FIA_LIAB::mCFStaticData_0[36],
	&FIA_LIAB::mCFStaticData_0[37],
	&FIA_LIAB::mCFStaticData_0[38],
	&FIA_LIAB::mCFStaticData_0[39],
	&FIA_LIAB::mCFStaticData_0[40],
	&FIA_LIAB::mCFStaticData_0[41],
	&FIA_LIAB::mCFStaticData_0[42],
	&FIA_LIAB::mCFStaticData_0[43],
	&FIA_LIAB::mCFStaticData_0[44],
	&FIA_LIAB::mCFStaticData_0[45],
	&FIA_LIAB::mCFStaticData_0[46],
	&FIA_LIAB::mCFStaticData_0[47],
	&FIA_LIAB::mCFStaticData_0[48],
	&FIA_LIAB::mCFStaticData_0[49],
	&FIA_LIAB::mCFStaticData_0[50],
	&FIA_LIAB::mCFStaticData_0[51],
	&FIA_LIAB::mCFStaticData_0[52],
	&FIA_LIAB::mCFStaticData_0[53],
	&FIA_LIAB::mCFStaticData_0[54],
	&FIA_LIAB::mCFStaticData_0[55],
	&FIA_LIAB::mCFStaticData_0[56],
	&FIA_LIAB::mCFStaticData_0[57],
	&FIA_LIAB::mCFStaticData_0[58],
	&FIA_LIAB::mCFStaticData_0[59],
	&FIA_LIAB::mCFStaticData_0[60],
	&FIA_LIAB::mCFStaticData_0[61],
	&FIA_LIAB::mCFStaticData_0[62],
	&FIA_LIAB::mCFStaticData_0[63],
	&FIA_LIAB::mCFStaticData_0[64],
	&FIA_LIAB::mCFStaticData_0[65],
	&FIA_LIAB::mCFStaticData_0[66],
	&FIA_LIAB::mCFStaticData_0[67],
	&FIA_LIAB::mCFStaticData_0[68],
	&FIA_LIAB::mCFStaticData_0[69],
	&FIA_LIAB::mCFStaticData_0[70],
	&FIA_LIAB::mCFStaticData_0[71],
	&FIA_LIAB::mCFStaticData_0[72],
	&FIA_LIAB::mCFStaticData_0[73],
	&FIA_LIAB::mCFStaticData_0[74],
	&FIA_LIAB::mCFStaticData_0[75],
	&FIA_LIAB::mCFStaticData_0[76],
	&FIA_LIAB::mCFStaticData_0[77],
	&FIA_LIAB::mCFStaticData_0[78],
	&FIA_LIAB::mCFStaticData_0[79],
	&FIA_LIAB::mCFStaticData_0[80],
	&FIA_LIAB::mCFStaticData_0[81],
	&FIA_LIAB::mCFStaticData_0[82],
	&FIA_LIAB::mCFStaticData_0[83],
	&FIA_LIAB::mCFStaticData_0[84],
	&FIA_LIAB::mCFStaticData_0[85],
	&FIA_LIAB::mCFStaticData_0[86],
	&FIA_LIAB::mCFStaticData_0[87],
	&FIA_LIAB::mCFStaticData_0[88],
	&FIA_LIAB::mCFStaticData_0[89],
	&FIA_LIAB::mCFStaticData_0[90],
	&FIA_LIAB::mCFStaticData_0[91],
	&FIA_LIAB::mCFStaticData_0[92],
	&FIA_LIAB::mCFStaticData_0[93],
	&FIA_LIAB::mCFStaticData_0[94],
	&FIA_LIAB::mCFStaticData_0[95],
	&FIA_LIAB::mCFStaticData_0[96],
	&FIA_LIAB::mCFStaticData_0[97],
	&FIA_LIAB::mCFStaticData_0[98],
	&FIA_LIAB::mCFStaticData_0[99],
	&FIA_LIAB::mCFStaticData_0[100],
	&FIA_LIAB::mCFStaticData_0[101],
	&FIA_LIAB::mCFStaticData_0[102],
	&FIA_LIAB::mCFStaticData_0[103],
	&FIA_LIAB::mCFStaticData_0[104],
	&FIA_LIAB::mCFStaticData_0[105],
	&FIA_LIAB::mCFStaticData_0[106],
	&FIA_LIAB::mCFStaticData_0[107],
	&FIA_LIAB::mCFStaticData_0[108],
	&FIA_LIAB::mCFStaticData_0[109],
	&FIA_LIAB::mCFStaticData_0[110],
	&FIA_LIAB::mCFStaticData_0[111],
	&FIA_LIAB::mCFStaticData_0[112],
	&FIA_LIAB::mCFStaticData_0[113],
	&FIA_LIAB::mCFStaticData_0[114],
	&FIA_LIAB::mCFStaticData_0[115],
	&FIA_LIAB::mCFStaticData_0[116],
	&FIA_LIAB::mCFStaticData_0[117],
	&FIA_LIAB::mCFStaticData_0[118],
	&FIA_LIAB::mCFStaticData_0[119],
	&FIA_LIAB::mCFStaticData_0[120],
	&FIA_LIAB::mCFStaticData_0[121],
	&FIA_LIAB::mCFStaticData_0[122],
	&FIA_LIAB::mCFStaticData_0[123],
	&FIA_LIAB::mCFStaticData_0[124],
	&FIA_LIAB::mCFStaticData_0[125],
	&FIA_LIAB::mCFStaticData_0[126],
	&FIA_LIAB::mCFStaticData_0[127],
	&FIA_LIAB::mCFStaticData_0[128],
	&FIA_LIAB::mCFStaticData_0[129],
	&FIA_LIAB::mCFStaticData_0[130],
	&FIA_LIAB::mCFStaticData_0[131],
	&FIA_LIAB::mCFStaticData_0[132],
	&FIA_LIAB::mCFStaticData_0[133],
	&FIA_LIAB::mCFStaticData_0[134],
	&FIA_LIAB::mCFStaticData_0[135],
	&FIA_LIAB::mCFStaticData_0[136],
	&FIA_LIAB::mCFStaticData_0[137],
	&FIA_LIAB::mCFStaticData_0[138],
	&FIA_LIAB::mCFStaticData_0[139],
	&FIA_LIAB::mCFStaticData_0[140],
	&FIA_LIAB::mCFStaticData_0[141],
	&FIA_LIAB::mCFStaticData_0[142],
	&FIA_LIAB::mCFStaticData_0[143],
	&FIA_LIAB::mCFStaticData_0[144],
	&FIA_LIAB::mCFStaticData_0[145],
	&FIA_LIAB::mCFStaticData_0[146],
	&FIA_LIAB::mCFStaticData_0[147],
	&FIA_LIAB::mCFStaticData_0[148],
	&FIA_LIAB::mCFStaticData_0[149],
	&FIA_LIAB::mCFStaticData_0[150],
	&FIA_LIAB::mCFStaticData_0[151],
	&FIA_LIAB::mCFStaticData_0[152],
	&FIA_LIAB::mCFStaticData_0[153],
	&FIA_LIAB::mCFStaticData_0[154],
	&FIA_LIAB::mCFStaticData_0[155],
	&FIA_LIAB::mCFStaticData_0[156],
	&FIA_LIAB::mCFStaticData_0[157],
	&FIA_LIAB::mCFStaticData_0[158],
	&FIA_LIAB::mCFStaticData_0[159],
	&FIA_LIAB::mCFStaticData_0[160],
	&FIA_LIAB::mCFStaticData_0[161],
	&FIA_LIAB::mCFStaticData_0[162],
	&FIA_LIAB::mCFStaticData_0[163],
	&FIA_LIAB::mCFStaticData_0[164],
	&FIA_LIAB::mCFStaticData_0[165],
	&FIA_LIAB::mCFStaticData_0[166],
	&FIA_LIAB::mCFStaticData_0[167],
	&FIA_LIAB::mCFStaticData_0[168],
	&FIA_LIAB::mCFStaticData_0[169],
	&FIA_LIAB::mCFStaticData_0[170],
	&FIA_LIAB::mCFStaticData_0[171],
	&FIA_LIAB::mCFStaticData_0[172],
	&FIA_LIAB::mCFStaticData_0[173],
	&FIA_LIAB::mCFStaticData_0[174],
	&FIA_LIAB::mCFStaticData_0[175],
	&FIA_LIAB::mCFStaticData_0[176],
	&FIA_LIAB::mCFStaticData_0[177],
	&FIA_LIAB::mCFStaticData_0[178],
	&FIA_LIAB::mCFStaticData_0[179],
	&FIA_LIAB::mCFStaticData_0[180],
	&FIA_LIAB::mCFStaticData_0[181],
	&FIA_LIAB::mCFStaticData_0[182],
	&FIA_LIAB::mCFStaticData_0[183],
	&FIA_LIAB::mCFStaticData_0[184],
	&FIA_LIAB::mCFStaticData_0[185],
	&FIA_LIAB::mCFStaticData_0[186],
	&FIA_LIAB::mCFStaticData_0[187],
	&FIA_LIAB::mCFStaticData_0[188],
	&FIA_LIAB::mCFStaticData_0[189],
	&FIA_LIAB::mCFStaticData_0[190],
	&FIA_LIAB::mCFStaticData_0[191],
	&FIA_LIAB::mCFStaticData_0[192],
	&FIA_LIAB::mCFStaticData_0[193],
	&FIA_LIAB::mCFStaticData_0[194],
	&FIA_LIAB::mCFStaticData_0[195],
	&FIA_LIAB::mCFStaticData_0[196],
	&FIA_LIAB::mCFStaticData_0[197],
	&FIA_LIAB::mCFStaticData_0[198],
	&FIA_LIAB::mCFStaticData_0[199],
	&FIA_LIAB::mCFStaticData_0[200],
	&FIA_LIAB::mCFStaticData_0[201],
	&FIA_LIAB::mCFStaticData_0[202],
	&FIA_LIAB::mCFStaticData_0[203],
	&FIA_LIAB::mCFStaticData_0[204],
	&FIA_LIAB::mCFStaticData_0[205],
	&FIA_LIAB::mCFStaticData_0[206],
	&FIA_LIAB::mCFStaticData_0[207],
	&FIA_LIAB::mCFStaticData_0[208],
	&FIA_LIAB::mCFStaticData_0[209],
	&FIA_LIAB::mCFStaticData_0[210],
	&FIA_LIAB::mCFStaticData_0[211],
	&FIA_LIAB::mCFStaticData_0[212],
	&FIA_LIAB::mCFStaticData_0[213],
	&FIA_LIAB::mCFStaticData_0[214],
	&FIA_LIAB::mCFStaticData_0[215],
	&FIA_LIAB::mCFStaticData_0[216],
	&FIA_LIAB::mCFStaticData_0[217],
	&FIA_LIAB::mCFStaticData_0[218],
	&FIA_LIAB::mCFStaticData_0[219],
	&FIA_LIAB::mCFStaticData_0[220],
	&FIA_LIAB::mCFStaticData_0[221],
	&FIA_LIAB::mCFStaticData_0[222],
	&FIA_LIAB::mCFStaticData_0[223],
	&FIA_LIAB::mCFStaticData_0[224],
	&FIA_LIAB::mCFStaticData_0[225],
	&FIA_LIAB::mCFStaticData_0[226],
	&FIA_LIAB::mCFStaticData_0[227],
	&FIA_LIAB::mCFStaticData_0[228],
	&FIA_LIAB::mCFStaticData_0[229],
	&FIA_LIAB::mCFStaticData_0[230],
	&FIA_LIAB::mCFStaticData_0[231],
	&FIA_LIAB::mCFStaticData_0[232],
	&FIA_LIAB::mCFStaticData_0[233],
	&FIA_LIAB::mCFStaticData_0[234],
	&FIA_LIAB::mCFStaticData_0[235],
	&FIA_LIAB::mCFStaticData_0[236],
	&FIA_LIAB::mCFStaticData_0[237],
	&FIA_LIAB::mCFStaticData_0[238],
	&FIA_LIAB::mCFStaticData_0[239],
	&FIA_LIAB::mCFStaticData_0[240],
	&FIA_LIAB::mCFStaticData_0[241],
	&FIA_LIAB::mCFStaticData_0[242],
	&FIA_LIAB::mCFStaticData_0[243],
	&FIA_LIAB::mCFStaticData_0[244],
	&FIA_LIAB::mCFStaticData_0[245],
	&FIA_LIAB::mCFStaticData_0[246],
	&FIA_LIAB::mCFStaticData_0[247],
	&FIA_LIAB::mCFStaticData_0[248],
	&FIA_LIAB::mCFStaticData_0[249],
	&FIA_LIAB::mCFStaticData_0[250],
	&FIA_LIAB::mCFStaticData_0[251],
	&FIA_LIAB::mCFStaticData_0[252],
	&FIA_LIAB::mCFStaticData_0[253],
	&FIA_LIAB::mCFStaticData_0[254],
	&FIA_LIAB::mCFStaticData_0[255],
	&FIA_LIAB::mCFStaticData_256[0],
	&FIA_LIAB::mCFStaticData_256[1],
	&FIA_LIAB::mCFStaticData_256[2],
	&FIA_LIAB::mCFStaticData_256[3],
	&FIA_LIAB::mCFStaticData_256[4],
	&FIA_LIAB::mCFStaticData_256[5],
	&FIA_LIAB::mCFStaticData_256[6],
	&FIA_LIAB::mCFStaticData_256[7],
	&FIA_LIAB::mCFStaticData_256[8],
	&FIA_LIAB::mCFStaticData_256[9],
	&FIA_LIAB::mCFStaticData_256[10],
	&FIA_LIAB::mCFStaticData_256[11],
	&FIA_LIAB::mCFStaticData_256[12],
	&FIA_LIAB::mCFStaticData_256[13],
	&FIA_LIAB::mCFStaticData_256[14],
	&FIA_LIAB::mCFStaticData_256[15],
	&FIA_LIAB::mCFStaticData_256[16],
	&FIA_LIAB::mCFStaticData_256[17],
	&FIA_LIAB::mCFStaticData_256[18],
	&FIA_LIAB::mCFStaticData_256[19],
	&FIA_LIAB::mCFStaticData_256[20],
	&FIA_LIAB::mCFStaticData_256[21],
	&FIA_LIAB::mCFStaticData_256[22],
	&FIA_LIAB::mCFStaticData_256[23],
	&FIA_LIAB::mCFStaticData_256[24],
	&FIA_LIAB::mCFStaticData_256[25],
	&FIA_LIAB::mCFStaticData_256[26],
	&FIA_LIAB::mCFStaticData_256[27],
	&FIA_LIAB::mCFStaticData_256[28],
	&FIA_LIAB::mCFStaticData_256[29],
	&FIA_LIAB::mCFStaticData_256[30],
	&FIA_LIAB::mCFStaticData_256[31],
	&FIA_LIAB::mCFStaticData_256[32],
	&FIA_LIAB::mCFStaticData_256[33],
	&FIA_LIAB::mCFStaticData_256[34],
	&FIA_LIAB::mCFStaticData_256[35],
	&FIA_LIAB::mCFStaticData_256[36],
	&FIA_LIAB::mCFStaticData_256[37],
	&FIA_LIAB::mCFStaticData_256[38],
	&FIA_LIAB::mCFStaticData_256[39],
	&FIA_LIAB::mCFStaticData_256[40],
	&FIA_LIAB::mCFStaticData_256[41],
	&FIA_LIAB::mCFStaticData_256[42],
	&FIA_LIAB::mCFStaticData_256[43],
	&FIA_LIAB::mCFStaticData_256[44],
	&FIA_LIAB::mCFStaticData_256[45],
	&FIA_LIAB::mCFStaticData_256[46],
	&FIA_LIAB::mCFStaticData_256[47],
	&FIA_LIAB::mCFStaticData_256[48],
	&FIA_LIAB::mCFStaticData_256[49],
	&FIA_LIAB::mCFStaticData_256[50],
	&FIA_LIAB::mCFStaticData_256[51],
	&FIA_LIAB::mCFStaticData_256[52],
	&FIA_LIAB::mCFStaticData_256[53],
	&FIA_LIAB::mCFStaticData_256[54],
	&FIA_LIAB::mCFStaticData_256[55],
	&FIA_LIAB::mCFStaticData_256[56],
	&FIA_LIAB::mCFStaticData_256[57],
	&FIA_LIAB::mCFStaticData_256[58],
	&FIA_LIAB::mCFStaticData_256[59],
	&FIA_LIAB::mCFStaticData_256[60],
	&FIA_LIAB::mCFStaticData_256[61],
	&FIA_LIAB::mCFStaticData_256[62],
	&FIA_LIAB::mCFStaticData_256[63],
	&FIA_LIAB::mCFStaticData_256[64],
	&FIA_LIAB::mCFStaticData_256[65],
	&FIA_LIAB::mCFStaticData_256[66],
	&FIA_LIAB::mCFStaticData_256[67],
	&FIA_LIAB::mCFStaticData_256[68],
	&FIA_LIAB::mCFStaticData_256[69],
	&FIA_LIAB::mCFStaticData_256[70],
	&FIA_LIAB::mCFStaticData_256[71],
	&FIA_LIAB::mCFStaticData_256[72],
	&FIA_LIAB::mCFStaticData_256[73],
	&FIA_LIAB::mCFStaticData_256[74],
	&FIA_LIAB::mCFStaticData_256[75],
	&FIA_LIAB::mCFStaticData_256[76],
	&FIA_LIAB::mCFStaticData_256[77],
	&FIA_LIAB::mCFStaticData_256[78],
	&FIA_LIAB::mCFStaticData_256[79],
	&FIA_LIAB::mCFStaticData_256[80],
	&FIA_LIAB::mCFStaticData_256[81],
	&FIA_LIAB::mCFStaticData_256[82],
	&FIA_LIAB::mCFStaticData_256[83],
	&FIA_LIAB::mCFStaticData_256[84],
	&FIA_LIAB::mCFStaticData_256[85],
	&FIA_LIAB::mCFStaticData_256[86],
	&FIA_LIAB::mCFStaticData_256[87],
	&FIA_LIAB::mCFStaticData_256[88],
	&FIA_LIAB::mCFStaticData_256[89],
	&FIA_LIAB::mCFStaticData_256[90],
	&FIA_LIAB::mCFStaticData_256[91],
	&FIA_LIAB::mCFStaticData_256[92],
	&FIA_LIAB::mCFStaticData_256[93],
	&FIA_LIAB::mCFStaticData_256[94],
	&FIA_LIAB::mCFStaticData_256[95],
	&FIA_LIAB::mCFStaticData_256[96],
	&FIA_LIAB::mCFStaticData_256[97],
	&FIA_LIAB::mCFStaticData_256[98],
	&FIA_LIAB::mCFStaticData_256[99],
	&FIA_LIAB::mCFStaticData_256[100],
	&FIA_LIAB::mCFStaticData_256[101],
	&FIA_LIAB::mCFStaticData_256[102],
	&FIA_LIAB::mCFStaticData_256[103],
	&FIA_LIAB::mCFStaticData_256[104],
	&FIA_LIAB::mCFStaticData_256[105],
	&FIA_LIAB::mCFStaticData_256[106],
	&FIA_LIAB::mCFStaticData_256[107],
	&FIA_LIAB::mCFStaticData_256[108],
	&FIA_LIAB::mCFStaticData_256[109],
	&FIA_LIAB::mCFStaticData_256[110],
	&FIA_LIAB::mCFStaticData_256[111],
	&FIA_LIAB::mCFStaticData_256[112],
	&FIA_LIAB::mCFStaticData_256[113],
	&FIA_LIAB::mCFStaticData_256[114],
	&FIA_LIAB::mCFStaticData_256[115],
	&FIA_LIAB::mCFStaticData_256[116],
	&FIA_LIAB::mCFStaticData_256[117],
	&FIA_LIAB::mCFStaticData_256[118],
	&FIA_LIAB::mCFStaticData_256[119],
	&FIA_LIAB::mCFStaticData_256[120],
	&FIA_LIAB::mCFStaticData_256[121],
	&FIA_LIAB::mCFStaticData_256[122],
	&FIA_LIAB::mCFStaticData_256[123],
	&FIA_LIAB::mCFStaticData_256[124],
	&FIA_LIAB::mCFStaticData_256[125],
	&FIA_LIAB::mCFStaticData_256[126],
	&FIA_LIAB::mCFStaticData_256[127],
	&FIA_LIAB::mCFStaticData_256[128],
	&FIA_LIAB::mCFStaticData_256[129],
	&FIA_LIAB::mCFStaticData_256[130],
	&FIA_LIAB::mCFStaticData_256[131],
	&FIA_LIAB::mCFStaticData_256[132],
	&FIA_LIAB::mCFStaticData_256[133],
	&FIA_LIAB::mCFStaticData_256[134],
	&FIA_LIAB::mCFStaticData_256[135],
	&FIA_LIAB::mCFStaticData_256[136],
	&FIA_LIAB::mCFStaticData_256[137],
	&FIA_LIAB::mCFStaticData_256[138],
	&FIA_LIAB::mCFStaticData_256[139],
	&FIA_LIAB::mCFStaticData_256[140],
	&FIA_LIAB::mCFStaticData_256[141],
	&FIA_LIAB::mCFStaticData_256[142],
	&FIA_LIAB::mCFStaticData_256[143],
	&FIA_LIAB::mCFStaticData_256[144],
	&FIA_LIAB::mCFStaticData_256[145],
	&FIA_LIAB::mCFStaticData_256[146],
	&FIA_LIAB::mCFStaticData_256[147],
	&FIA_LIAB::mCFStaticData_256[148],
	&FIA_LIAB::mCFStaticData_256[149],
	&FIA_LIAB::mCFStaticData_256[150],
	&FIA_LIAB::mCFStaticData_256[151],
	&FIA_LIAB::mCFStaticData_256[152],
	&FIA_LIAB::mCFStaticData_256[153],
	&FIA_LIAB::mCFStaticData_256[154],
	&FIA_LIAB::mCFStaticData_256[155],
	&FIA_LIAB::mCFStaticData_256[156],
	&FIA_LIAB::mCFStaticData_256[157],
	&FIA_LIAB::mCFStaticData_256[158],
	&FIA_LIAB::mCFStaticData_256[159],
	&FIA_LIAB::mCFStaticData_256[160],
	&FIA_LIAB::mCFStaticData_256[161],
	&FIA_LIAB::mCFStaticData_256[162],
	&FIA_LIAB::mCFStaticData_256[163],
	&FIA_LIAB::mCFStaticData_256[164],
	&FIA_LIAB::mCFStaticData_256[165],
	&FIA_LIAB::mCFStaticData_256[166],
	&FIA_LIAB::mCFStaticData_256[167],
	&FIA_LIAB::mCFStaticData_256[168],
	&FIA_LIAB::mCFStaticData_256[169],
	&FIA_LIAB::mCFStaticData_256[170],
	&FIA_LIAB::mCFStaticData_256[171],
	&FIA_LIAB::mCFStaticData_256[172],
	&FIA_LIAB::mCFStaticData_256[173],
	&FIA_LIAB::mCFStaticData_256[174],
	&FIA_LIAB::mCFStaticData_256[175],
	&FIA_LIAB::mCFStaticData_256[176],
	&FIA_LIAB::mCFStaticData_256[177],
	&FIA_LIAB::mCFStaticData_256[178],
	&FIA_LIAB::mCFStaticData_256[179],
	&FIA_LIAB::mCFStaticData_256[180],
	&FIA_LIAB::mCFStaticData_256[181],
	&FIA_LIAB::mCFStaticData_256[182],
	&FIA_LIAB::mCFStaticData_256[183],
	&FIA_LIAB::mCFStaticData_256[184],
	&FIA_LIAB::mCFStaticData_256[185],
	&FIA_LIAB::mCFStaticData_256[186],
	&FIA_LIAB::mCFStaticData_256[187],
	&FIA_LIAB::mCFStaticData_256[188],
	&FIA_LIAB::mCFStaticData_256[189],
	&FIA_LIAB::mCFStaticData_256[190],
	&FIA_LIAB::mCFStaticData_256[191],
	&FIA_LIAB::mCFStaticData_256[192],
	&FIA_LIAB::mCFStaticData_256[193],
	&FIA_LIAB::mCFStaticData_256[194],
	&FIA_LIAB::mCFStaticData_256[195],
	&FIA_LIAB::mCFStaticData_256[196],
	&FIA_LIAB::mCFStaticData_256[197],
	&FIA_LIAB::mCFStaticData_256[198],
	&FIA_LIAB::mCFStaticData_256[199],
	&FIA_LIAB::mCFStaticData_256[200],
	&FIA_LIAB::mCFStaticData_256[201],
	&FIA_LIAB::mCFStaticData_256[202],
	&FIA_LIAB::mCFStaticData_256[203],
	&FIA_LIAB::mCFStaticData_256[204],
	&FIA_LIAB::mCFStaticData_256[205],
	&FIA_LIAB::mCFStaticData_256[206],
	&FIA_LIAB::mCFStaticData_256[207],
	&FIA_LIAB::mCFStaticData_256[208],
	&FIA_LIAB::mCFStaticData_256[209],
	&FIA_LIAB::mCFStaticData_256[210],
	&FIA_LIAB::mCFStaticData_256[211],
	&FIA_LIAB::mCFStaticData_256[212],
	&FIA_LIAB::mCFStaticData_256[213],
	&FIA_LIAB::mCFStaticData_256[214],
	&FIA_LIAB::mCFStaticData_256[215],
	&FIA_LIAB::mCFStaticData_256[216],
	&FIA_LIAB::mCFStaticData_256[217],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for ann_ben_partial_credit_ind_crbg                                                                                       
	const ChoicePair ann_ben_partial_credit_ind_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList ann_ben_partial_credit_ind_crbgEnumList(2, ann_ben_partial_credit_ind_crbgChoicePairs);

	// EnumList for asset_yld_defn                                                                                       
	const ChoicePair asset_yld_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::STOCHASTIC, "Stochastic")
		,ChoicePair(StrEnum::DETERMINISTIC, "Deterministic")
	};
	const EnumList asset_yld_defnEnumList(2, asset_yld_defnChoicePairs);

	// EnumList for calc_pv_gmwb_av_exhaustion_crbg                                                                                       
	const ChoicePair calc_pv_gmwb_av_exhaustion_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList calc_pv_gmwb_av_exhaustion_crbgEnumList(2, calc_pv_gmwb_av_exhaustion_crbgChoicePairs);

	// EnumList for carvm_stat_detail_rpt_defn                                                                                       
	const ChoicePair carvm_stat_detail_rpt_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList carvm_stat_detail_rpt_defnEnumList(2, carvm_stat_detail_rpt_defnChoicePairs);

	// EnumList for carvm_tax_detail_rpt_defn                                                                                       
	const ChoicePair carvm_tax_detail_rpt_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList carvm_tax_detail_rpt_defnEnumList(2, carvm_tax_detail_rpt_defnChoicePairs);

	// EnumList for comp_rate_compared_defn                                                                                       
	const ChoicePair comp_rate_compared_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MAXIMUM_RATE, "Maximum Rate")
		,ChoicePair(StrEnum::MINIMUM_RATE, "Minimum Rate")
	};
	const EnumList comp_rate_compared_defnEnumList(2, comp_rate_compared_defnChoicePairs);

	// EnumList for comp_rate_type                                                                                       
	const ChoicePair comp_rate_typeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SINGLE, "Single")
		,ChoicePair(StrEnum::WEIGHTED, "Weighted")
		,ChoicePair(StrEnum::COMPARED, "Compared")
	};
	const EnumList comp_rate_typeEnumList(3, comp_rate_typeChoicePairs);

	// EnumList for contract_val_sc_defn                                                                                       
	const ChoicePair contract_val_sc_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList contract_val_sc_defnEnumList(2, contract_val_sc_defnChoicePairs);

	// EnumList for crediting_nb_defn                                                                                       
	const ChoicePair crediting_nb_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INPUT, "Input")
		,ChoicePair(StrEnum::PROXY_YIELD, "Proxy Yield")
		,ChoicePair(StrEnum::USER_INPUT, "User Input")
	};
	const EnumList crediting_nb_defnEnumList(3, crediting_nb_defnChoicePairs);

	// EnumList for data_validation_defn                                                                                       
	const ChoicePair data_validation_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList data_validation_defnEnumList(2, data_validation_defnChoicePairs);

	// EnumList for decrements_defn                                                                                       
	const ChoicePair decrements_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList decrements_defnEnumList(2, decrements_defnChoicePairs);

	// EnumList for disc_rate_port_yld_defn                                                                                       
	const ChoicePair disc_rate_port_yld_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BEFORE_TAX, "Before Tax")
		,ChoicePair(StrEnum::AFTER_TAX, "After Tax")
	};
	const EnumList disc_rate_port_yld_defnEnumList(2, disc_rate_port_yld_defnChoicePairs);

	// EnumList for dth_ben_defn                                                                                       
	const ChoicePair dth_ben_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FUND_VALUE, "Fund Value")
		,ChoicePair(StrEnum::CASH_VALUE, "Cash Value")
	};
	const EnumList dth_ben_defnEnumList(2, dth_ben_defnChoicePairs);

	// EnumList for enhanced_income_ind_crbg                                                                                       
	const ChoicePair enhanced_income_ind_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList enhanced_income_ind_crbgEnumList(2, enhanced_income_ind_crbgChoicePairs);

	// EnumList for eprs_sfc_defn                                                                                       
	const ChoicePair eprs_sfc_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList eprs_sfc_defnEnumList(2, eprs_sfc_defnChoicePairs);

	// EnumList for fund_val_rebal_defn                                                                                       
	const ChoicePair fund_val_rebal_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::DRIFT, "Drift")
		,ChoicePair(StrEnum::REBALANCE, "Rebalance")
	};
	const EnumList fund_val_rebal_defnEnumList(2, fund_val_rebal_defnChoicePairs);

	// EnumList for fund_val_rebal_freq_defn                                                                                       
	const ChoicePair fund_val_rebal_freq_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ANNUAL, "Annual")
		,ChoicePair(StrEnum::SEMI_ANNUAL, "Semi_Annual")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
	};
	const EnumList fund_val_rebal_freq_defnEnumList(4, fund_val_rebal_freq_defnChoicePairs);

	// EnumList for fund_val_rebal_prop_defn                                                                                       
	const ChoicePair fund_val_rebal_prop_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INITIAL_ACCOUNT_VALUE_ALLOCATION, "Initial Account Value Allocation")
		,ChoicePair(StrEnum::SPECIFIED_ALLOCATION, "Specified Allocation")
	};
	const EnumList fund_val_rebal_prop_defnEnumList(2, fund_val_rebal_prop_defnChoicePairs);

	// EnumList for gaap_defn                                                                                       
	const ChoicePair gaap_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList gaap_defnEnumList(2, gaap_defnChoicePairs);

	// EnumList for gen2_declarations                                                                                       
	const ChoicePair gen2_declarationsChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CALL, "Call")
		,ChoicePair(StrEnum::PUT, "Put")
		,ChoicePair(StrEnum::NO_SHIFT, "No Shift")
		,ChoicePair(StrEnum::EXPERIENCE, "Experience")
		,ChoicePair(StrEnum::GET_SPOT_RATE, "Get Spot Rate")
		,ChoicePair(StrEnum::GET_FORWARD_RATE, "Get Forward Rate")
		,ChoicePair(StrEnum::GET_GROWTH_RATE, "Get Growth Rate")
		,ChoicePair(StrEnum::GET_DIVIDEND_YIELD, "Get Dividend Yield")
		,ChoicePair(StrEnum::GET_YIELD_RATE, "Get Yield Rate")
		,ChoicePair(StrEnum::GET_TOTAL_RETURN, "Get Total Return")
		,ChoicePair(StrEnum::GET_INCOME_RETURN, "Get Income Return")
		,ChoicePair(StrEnum::GET_SPOT_SPREAD, "Get Spot Spread")
		,ChoicePair(StrEnum::SPOT_SHIFT, "Spot Shift")
		,ChoicePair(StrEnum::GET_YIELD_SPREAD, "Get Yield Spread")
		,ChoicePair(StrEnum::YIELD_SHIFT, "Yield Shift")
		,ChoicePair(StrEnum::VOL_SHIFT, "Vol Shift")
		,ChoicePair(StrEnum::INDEX_RATE, "Index Rate")
		,ChoicePair(StrEnum::INTEREST_RATE, "Interest Rate")
		,ChoicePair(StrEnum::INDEX_VOL, "Index Vol")
		,ChoicePair(StrEnum::INFLATION_RATE, "Inflation Rate")
		,ChoicePair(StrEnum::USE_WORKING_RESERVE, "Use Working Reserve")
	};
	const EnumList gen2_declarationsEnumList(21, gen2_declarationsChoicePairs);

	// EnumList for gender_aft_inc                                                                                       
	const ChoicePair gender_aft_incChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MALE, "Male")
		,ChoicePair(StrEnum::FEMALE, "Female")
		,ChoicePair(StrEnum::BLENDED, "Blended")
		,ChoicePair(StrEnum::JOINT, "Joint")
	};
	const EnumList gender_aft_incEnumList(4, gender_aft_incChoicePairs);

	// EnumList for gender_mp                                                                                       
	const ChoicePair gender_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MALE, "Male")
		,ChoicePair(StrEnum::FEMALE, "Female")
		,ChoicePair(StrEnum::BLENDED, "Blended")
		,ChoicePair(StrEnum::JOINT, "Joint")
	};
	const EnumList gender_mpEnumList(4, gender_mpChoicePairs);

	// EnumList for gmwb_chg_at_surr_crbg                                                                                       
	const ChoicePair gmwb_chg_at_surr_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList gmwb_chg_at_surr_crbgEnumList(2, gmwb_chg_at_surr_crbgChoicePairs);

	// EnumList for gmwb_chg_base                                                                                       
	const ChoicePair gmwb_chg_baseChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FUND_VALUE, "Fund Value")
		,ChoicePair(StrEnum::GMWB_BASE, "GMWB Base")
		,ChoicePair(StrEnum::MAX_AMOUNT, "Max Amount")
	};
	const EnumList gmwb_chg_baseEnumList(3, gmwb_chg_baseChoicePairs);

	// EnumList for gmwb_chg_surr_timing_crbg                                                                                       
	const ChoicePair gmwb_chg_surr_timing_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BEFORE_SC, "Before_SC")
		,ChoicePair(StrEnum::AFTER_SC, "After_SC")
	};
	const EnumList gmwb_chg_surr_timing_crbgEnumList(2, gmwb_chg_surr_timing_crbgChoicePairs);

	// EnumList for gmwb_claim_disc_rate_defn                                                                                       
	const ChoicePair gmwb_claim_disc_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FIXED_INPUT, "Fixed Input")
		,ChoicePair(StrEnum::ASSET_YIELD, "Asset Yield")
	};
	const EnumList gmwb_claim_disc_rate_defnEnumList(2, gmwb_claim_disc_rate_defnChoicePairs);

	// EnumList for gmwb_cohort_utilz_defn                                                                                       
	const ChoicePair gmwb_cohort_utilz_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList gmwb_cohort_utilz_defnEnumList(2, gmwb_cohort_utilz_defnChoicePairs);

	// EnumList for gmwb_credit_aft_income_crbg                                                                                       
	const ChoicePair gmwb_credit_aft_income_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ZERO, "Zero")
		,ChoicePair(StrEnum::NET, "Net")
		,ChoicePair(StrEnum::FULL, "Full")
	};
	const EnumList gmwb_credit_aft_income_crbgEnumList(3, gmwb_credit_aft_income_crbgChoicePairs);

	// EnumList for gmwb_defn                                                                                       
	const ChoicePair gmwb_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FINITE, "Finite")
		,ChoicePair(StrEnum::LIFE, "Life")
	};
	const EnumList gmwb_defnEnumList(2, gmwb_defnChoicePairs);

	// EnumList for gmwb_fund_val_defn                                                                                       
	const ChoicePair gmwb_fund_val_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::RATCHET, "Ratchet")
	};
	const EnumList gmwb_fund_val_defnEnumList(2, gmwb_fund_val_defnChoicePairs);

	// EnumList for gmwb_max_wdl_amt_base_defn                                                                                       
	const ChoicePair gmwb_max_wdl_amt_base_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PREMIUM, "Premium")
		,ChoicePair(StrEnum::GMWB_BASE, "GMWB Base")
		,ChoicePair(StrEnum::GMWB_BASE_ADJUSTABLE, "GMWB Base Adjustable")
	};
	const EnumList gmwb_max_wdl_amt_base_defnEnumList(3, gmwb_max_wdl_amt_base_defnChoicePairs);

	// EnumList for gmwb_pfwd_dyn_defn                                                                                       
	const ChoicePair gmwb_pfwd_dyn_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList gmwb_pfwd_dyn_defnEnumList(2, gmwb_pfwd_dyn_defnChoicePairs);

	// EnumList for gmwb_prem_defn                                                                                       
	const ChoicePair gmwb_prem_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::RETURN, "Return")
		,ChoicePair(StrEnum::ROLLUP, "Rollup")
		,ChoicePair(StrEnum::STEPUP, "Stepup")
	};
	const EnumList gmwb_prem_defnEnumList(4, gmwb_prem_defnChoicePairs);

	// EnumList for gmwb_reg47_crbg                                                                                       
	const ChoicePair gmwb_reg47_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList gmwb_reg47_crbgEnumList(2, gmwb_reg47_crbgChoicePairs);

	// EnumList for gmwb_rollup_credit_type_crbg                                                                                       
	const ChoicePair gmwb_rollup_credit_type_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CONSTANT, "Constant")
		,ChoicePair(StrEnum::INDEX_GROWTH, "Index_growth")
	};
	const EnumList gmwb_rollup_credit_type_crbgEnumList(2, gmwb_rollup_credit_type_crbgChoicePairs);

	// EnumList for gmwb_rollup_freq_defn                                                                                       
	const ChoicePair gmwb_rollup_freq_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ANNIVERSARY, "Anniversary")
		,ChoicePair(StrEnum::CONTINUOUS, "Continuous")
	};
	const EnumList gmwb_rollup_freq_defnEnumList(2, gmwb_rollup_freq_defnChoicePairs);

	// EnumList for gmwb_rollup_rate_type                                                                                       
	const ChoicePair gmwb_rollup_rate_typeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SIMPLE, "Simple")
		,ChoicePair(StrEnum::COMPOUND, "Compound")
		,ChoicePair(StrEnum::SIMPLE_THEN_COMPOUND, "Simple then Compound")
	};
	const EnumList gmwb_rollup_rate_typeEnumList(3, gmwb_rollup_rate_typeChoicePairs);

	// EnumList for gmwb_wdl_reduce_ben_base                                                                                       
	const ChoicePair gmwb_wdl_reduce_ben_baseChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList gmwb_wdl_reduce_ben_baseEnumList(2, gmwb_wdl_reduce_ben_baseChoicePairs);

	// EnumList for gmwb_wdl_trig_by_confinement                                                                                       
	const ChoicePair gmwb_wdl_trig_by_confinementChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList gmwb_wdl_trig_by_confinementEnumList(2, gmwb_wdl_trig_by_confinementChoicePairs);

	// EnumList for gmwb_wdl_util_type_crbg                                                                                       
	const ChoicePair gmwb_wdl_util_type_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::AVERAGE_UTIL, "Average Util")
		,ChoicePair(StrEnum::RANDOM_UTIL, "Random Util")
	};
	const EnumList gmwb_wdl_util_type_crbgEnumList(2, gmwb_wdl_util_type_crbgChoicePairs);

	// EnumList for gsia_reins_defn_crbg                                                                                       
	const ChoicePair gsia_reins_defn_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NA, "NA")
		,ChoicePair(StrEnum::CEDANT, "Cedant")
		,ChoicePair(StrEnum::REINSURER, "Reinsurer")
	};
	const EnumList gsia_reins_defn_crbgEnumList(3, gsia_reins_defn_crbgChoicePairs);

	// EnumList for infl_rate_defn_crbg                                                                                       
	const ChoicePair infl_rate_defn_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CONSTANT, "Constant")
		,ChoicePair(StrEnum::STOCHASTIC, "Stochastic")
	};
	const EnumList infl_rate_defn_crbgEnumList(2, infl_rate_defn_crbgChoicePairs);

	// EnumList for itm_defn                                                                                       
	const ChoicePair itm_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FUND_VALUE, "Fund Value")
		,ChoicePair(StrEnum::ANNUITY_BENEFIT, "Annuity Benefit")
	};
	const EnumList itm_defnEnumList(2, itm_defnChoicePairs);

	// EnumList for itm_denom_defn_crbg                                                                                       
	const ChoicePair itm_denom_defn_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FUND_VAL, "Fund val")
		,ChoicePair(StrEnum::CASH_VAL, "Cash val")
	};
	const EnumList itm_denom_defn_crbgEnumList(2, itm_denom_defn_crbgChoicePairs);

	// EnumList for lapse_dyn_base_prod_defn_crbg                                                                                       
	const ChoicePair lapse_dyn_base_prod_defn_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::AFTER_SC, "After_Sc")
		,ChoicePair(StrEnum::ALL_YR, "All_Yr")
	};
	const EnumList lapse_dyn_base_prod_defn_crbgEnumList(3, lapse_dyn_base_prod_defn_crbgChoicePairs);

	// EnumList for lapse_dyn_isl_defn_crbg                                                                                       
	const ChoicePair lapse_dyn_isl_defn_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList lapse_dyn_isl_defn_crbgEnumList(2, lapse_dyn_isl_defn_crbgChoicePairs);

	// EnumList for lapse_dyn_preshock_sprd_crbg                                                                                       
	const ChoicePair lapse_dyn_preshock_sprd_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList lapse_dyn_preshock_sprd_crbgEnumList(2, lapse_dyn_preshock_sprd_crbgChoicePairs);

	// EnumList for lapse_dyn_shock_yr_defn_crbg                                                                                       
	const ChoicePair lapse_dyn_shock_yr_defn_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList lapse_dyn_shock_yr_defn_crbgEnumList(2, lapse_dyn_shock_yr_defn_crbgChoicePairs);

	// EnumList for lapse_is_dynamic                                                                                       
	const ChoicePair lapse_is_dynamicChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList lapse_is_dynamicEnumList(2, lapse_is_dynamicChoicePairs);

	// EnumList for lapse_skew_method_crbg                                                                                       
	const ChoicePair lapse_skew_method_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::UNLOCKING2025, "Unlocking2025")
		,ChoicePair(StrEnum::NA, "NA")
		,ChoicePair(StrEnum::FA_PROPHET, "FA_Prophet")
	};
	const EnumList lapse_skew_method_crbgEnumList(3, lapse_skew_method_crbgChoicePairs);

	// EnumList for mawp_lookup_type_crbg                                                                                       
	const ChoicePair mawp_lookup_type_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::WITHDRL_AGE, "Withdrl age")
		,ChoicePair(StrEnum::ISSUE_AGE, "Issue age")
	};
	const EnumList mawp_lookup_type_crbgEnumList(2, mawp_lookup_type_crbgChoicePairs);

	// EnumList for mort_calc_basis                                                                                       
	const ChoicePair mort_calc_basisChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::EXPERIENCE, "Experience")
		,ChoicePair(StrEnum::STANDARD_SCENARIO, "Standard Scenario")
		,ChoicePair(StrEnum::GMWB, "GMWB")
	};
	const EnumList mort_calc_basisEnumList(3, mort_calc_basisChoicePairs);

	// EnumList for mort_gender                                                                                       
	const ChoicePair mort_genderChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MALE, "Male")
		,ChoicePair(StrEnum::FEMALE, "Female")
		,ChoicePair(StrEnum::BLENDED, "Blended")
	};
	const EnumList mort_genderEnumList(3, mort_genderChoicePairs);

	// EnumList for mva_cap_defn_crbg                                                                                       
	const ChoicePair mva_cap_defn_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BEFORE_2025, "Before_2025")
		,ChoicePair(StrEnum::AFTER_2025, "After_2025")
	};
	const EnumList mva_cap_defn_crbgEnumList(2, mva_cap_defn_crbgChoicePairs);

	// EnumList for mva_constraint_defn                                                                                       
	const ChoicePair mva_constraint_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList mva_constraint_defnEnumList(2, mva_constraint_defnChoicePairs);

	// EnumList for mva_defn                                                                                       
	const ChoicePair mva_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::LINEAR, "Linear")
		,ChoicePair(StrEnum::EXPONENTIAL, "Exponential")
		,ChoicePair(StrEnum::CRBG, "CRBG")
	};
	const EnumList mva_defnEnumList(4, mva_defnChoicePairs);

	// EnumList for myga_renew_ind_crbg                                                                                       
	const ChoicePair myga_renew_ind_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList myga_renew_ind_crbgEnumList(2, myga_renew_ind_crbgChoicePairs);

	// EnumList for ner_correction_crbg                                                                                       
	const ChoicePair ner_correction_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList ner_correction_crbgEnumList(2, ner_correction_crbgChoicePairs);

	// EnumList for ny_glb_ind_crbg                                                                                       
	const ChoicePair ny_glb_ind_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList ny_glb_ind_crbgEnumList(2, ny_glb_ind_crbgChoicePairs);

	// EnumList for nyia_ind_crbg                                                                                       
	const ChoicePair nyia_ind_crbgChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList nyia_ind_crbgEnumList(2, nyia_ind_crbgChoicePairs);

	// EnumList for opt_defn                                                                                       
	const ChoicePair opt_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CALL, "Call")
		,ChoicePair(StrEnum::PUT, "Put")
	};
	const EnumList opt_defnEnumList(2, opt_defnChoicePairs);

	// EnumList for pfwd_amt_avail_defn                                                                                       
	const ChoicePair pfwd_amt_avail_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FUND_VALUE, "Fund Value")
		,ChoicePair(StrEnum::CUMULATIVE_PREMIUM_LESS_WITHDRAWALS, "Cumulative Premium Less Withdrawals")
	};
	const EnumList pfwd_amt_avail_defnEnumList(2, pfwd_amt_avail_defnChoicePairs);

	// EnumList for pfwd_freq                                                                                       
	const ChoicePair pfwd_freqChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
	};
	const EnumList pfwd_freqEnumList(3, pfwd_freqChoicePairs);

	// EnumList for prem_band                                                                                       
	const ChoicePair prem_bandChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::H, "H")
		,ChoicePair(StrEnum::L, "L")
		,ChoicePair(StrEnum::C, "C")
		,ChoicePair(StrEnum::J, "J")
	};
	const EnumList prem_bandEnumList(4, prem_bandChoicePairs);

	// EnumList for pricing_defn                                                                                       
	const ChoicePair pricing_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList pricing_defnEnumList(2, pricing_defnChoicePairs);

	// EnumList for prof_distribn_mode                                                                                       
	const ChoicePair prof_distribn_modeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
	};
	const EnumList prof_distribn_modeEnumList(3, prof_distribn_modeChoicePairs);

	// EnumList for purch_rate_curr_defn                                                                                       
	const ChoicePair purch_rate_curr_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FIXED_RATE, "Fixed Rate")
		,ChoicePair(StrEnum::COMPETITOR_RATE_LESS_SPRD, "Competitor Rate Less Sprd")
	};
	const EnumList purch_rate_curr_defnEnumList(2, purch_rate_curr_defnChoicePairs);

	// EnumList for reins_coverage_defn                                                                                       
	const ChoicePair reins_coverage_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BASE_ONLY, "Base Only")
		,ChoicePair(StrEnum::RIDER_ONLY, "Rider Only")
		,ChoicePair(StrEnum::BASE_RIDER, "Base Rider")
	};
	const EnumList reins_coverage_defnEnumList(3, reins_coverage_defnChoicePairs);

	// EnumList for reins_defn                                                                                       
	const ChoicePair reins_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::COINSURANCE, "Coinsurance")
	};
	const EnumList reins_defnEnumList(2, reins_defnChoicePairs);

	// EnumList for stat_carvm_calc_annuitzn_defn                                                                                       
	const ChoicePair stat_carvm_calc_annuitzn_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::CURRENT_AND_GUARANTEED_BENEFITS, "Current And Guaranteed Benefits")
		,ChoicePair(StrEnum::GUARANTEED_BENEFITS, "Guaranteed Benefits")
	};
	const EnumList stat_carvm_calc_annuitzn_defnEnumList(3, stat_carvm_calc_annuitzn_defnChoicePairs);

	// EnumList for stat_res_defn                                                                                       
	const ChoicePair stat_res_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PERCENT_FUND_VALUE, "Percent Fund Value")
		,ChoicePair(StrEnum::PERCENT_CASH_VALUE, "Percent Cash Value")
		,ChoicePair(StrEnum::CARVM, "CARVM")
	};
	const EnumList stat_res_defnEnumList(3, stat_res_defnChoicePairs);

	// EnumList for stat_res_mva_defn                                                                                       
	const ChoicePair stat_res_mva_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::EXCLUDED, "Excluded")
		,ChoicePair(StrEnum::INCLUDED, "Included")
	};
	const EnumList stat_res_mva_defnEnumList(2, stat_res_mva_defnChoicePairs);

	// EnumList for surr_chg_defn                                                                                       
	const ChoicePair surr_chg_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FUND_VALUE, "Fund Value")
		,ChoicePair(StrEnum::PREMIUM, "Premium")
	};
	const EnumList surr_chg_defnEnumList(2, surr_chg_defnChoicePairs);

	// EnumList for surr_chg_timing_defn                                                                                       
	const ChoicePair surr_chg_timing_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::AFTER_MARKET_VALUE_ADJUSTMENT, "After Market Value Adjustment")
		,ChoicePair(StrEnum::BEFORE_MARKET_VALUE_ADJUSTMENT, "Before Market Value Adjustment")
	};
	const EnumList surr_chg_timing_defnEnumList(2, surr_chg_timing_defnChoicePairs);

	// EnumList for tax_carvm_calc_annuitzn_defn                                                                                       
	const ChoicePair tax_carvm_calc_annuitzn_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::CURRENT_AND_GUARANTEED_BENEFITS, "Current And Guaranteed Benefits")
		,ChoicePair(StrEnum::GUARANTEED_BENEFITS, "Guaranteed Benefits")
	};
	const EnumList tax_carvm_calc_annuitzn_defnEnumList(3, tax_carvm_calc_annuitzn_defnChoicePairs);

	// EnumList for tax_carvm_defn                                                                                       
	const ChoicePair tax_carvm_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ISSUE_YEAR, "Issue Year")
		,ChoicePair(StrEnum::CHANGE_IN_FUND, "Change in Fund")
	};
	const EnumList tax_carvm_defnEnumList(2, tax_carvm_defnChoicePairs);

	// EnumList for tax_loss_treatment                                                                                       
	const ChoicePair tax_loss_treatmentChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::IMMEDIATE_LOSS_RECOGNITION, "Immediate Loss Recognition")
		,ChoicePair(StrEnum::TAX_LOSS_CARRYFORWARD, "Tax Loss Carryforward")
		,ChoicePair(StrEnum::ZERO_TAX, "Zero Tax")
	};
	const EnumList tax_loss_treatmentEnumList(3, tax_loss_treatmentChoicePairs);

	// EnumList for tax_res_defn                                                                                       
	const ChoicePair tax_res_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PERCENT_FUND_VALUE, "Percent Fund Value")
		,ChoicePair(StrEnum::PERCENT_CASH_VALUE, "Percent Cash Value")
		,ChoicePair(StrEnum::CARVM, "CARVM")
		,ChoicePair(StrEnum::TAX_EQUALS_STAT, "Tax Equals Stat")
		,ChoicePair(StrEnum::_2017_TAX_REFORM, "2017 Tax Reform")
	};
	const EnumList tax_res_defnEnumList(5, tax_res_defnChoicePairs);

	// EnumList for tax_res_mva_defn                                                                                       
	const ChoicePair tax_res_mva_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::EXCLUDED, "Excluded")
		,ChoicePair(StrEnum::INCLUDED, "Included")
	};
	const EnumList tax_res_mva_defnEnumList(2, tax_res_mva_defnChoicePairs);

	// EnumList for tgt_cap_defn                                                                                       
	const ChoicePair tgt_cap_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList tgt_cap_defnEnumList(2, tgt_cap_defnChoicePairs);

	// EnumList for use_mp                                                                                       
	const ChoicePair use_mpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList use_mpEnumList(2, use_mpChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace FIA_LIAB_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(FIA_LIAB::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(FIA_LIAB::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace FIA_LIAB_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void FIA_LIAB::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> FIA_LIAB::mgr_;

	Attribute::Descriptor FIA_LIAB::descriptor_0[] = {
	Descriptor(0, Attribute::DOUBLE,	"acq_exp_pct_prem", Descriptor::NOT_INDEXED, (size_t)&modelOffset->acq_exp_pct_prem,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::DOUBLE,	"acq_exp_per_pol", Descriptor::NOT_INDEXED, (size_t)&modelOffset->acq_exp_per_pol,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::DOUBLE,	"admin_fee_per_pol", Descriptor::NOT_INDEXED, (size_t)&modelOffset->admin_fee_per_pol,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::STR_ENUM,	"ann_ben_partial_credit_ind_crbg", -1, (size_t)&modelOffset->ann_ben_partial_credit_ind_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &ann_ben_partial_credit_ind_crbgEnumList, Feature(true)),
	Descriptor(4, Attribute::DOUBLE,	"ann_gmwb_claim_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->ann_gmwb_claim_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::STRING,	"annuity_type_crbg", -1, (size_t)&modelOffset->annuity_type_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::DOUBLE,	"annuitzn_base", Descriptor::NOT_INDEXED, (size_t)&modelOffset->annuitzn_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::DOUBLE,	"arctan_base_aft_shock_mult_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->arctan_base_aft_shock_mult_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::DOUBLE,	"arctan_base_inc_mult_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->arctan_base_inc_mult_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::DOUBLE,	"arctan_base_shock_mult_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->arctan_base_shock_mult_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::DOUBLE,	"arctan_param1_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->arctan_param1_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::DOUBLE,	"arctan_param2_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->arctan_param2_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::STRING,	"asset_yld_comp_rate_id", -1, (size_t)&modelOffset->asset_yld_comp_rate_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::STR_ENUM,	"asset_yld_defn", -1, (size_t)&modelOffset->asset_yld_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_yld_defnEnumList, Feature(true)),
	Descriptor(14, Attribute::DOUBLE,	"asset_yld_deterministic", Descriptor::NOT_INDEXED, (size_t)&modelOffset->asset_yld_deterministic,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::DOUBLE,	"asset_yld_for_rate_setting", Descriptor::NOT_INDEXED, (size_t)&modelOffset->asset_yld_for_rate_setting,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(16, Attribute::STRING,	"audit_rpt_defn", -1, (size_t)&modelOffset->audit_rpt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::DOUBLE,	"av_size_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->av_size_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::STRING,	"broker_crbg", -1, (size_t)&modelOffset->broker_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::DOUBLE,	"bs_dividend_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->bs_dividend_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::DOUBLE,	"bs_fwd_vol_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->bs_fwd_vol_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(21, Attribute::STR_ENUM,	"calc_pv_gmwb_av_exhaustion_crbg", -1, (size_t)&modelOffset->calc_pv_gmwb_av_exhaustion_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &calc_pv_gmwb_av_exhaustion_crbgEnumList, Feature(true)),
	Descriptor(22, Attribute::DOUBLE,	"capzd_acq_exp_pct_pct_prem", Descriptor::NOT_INDEXED, (size_t)&modelOffset->capzd_acq_exp_pct_pct_prem,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(23, Attribute::DOUBLE,	"capzd_acq_exp_pct_per_pol", Descriptor::NOT_INDEXED, (size_t)&modelOffset->capzd_acq_exp_pct_per_pol,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::DOUBLE,	"capzd_prem_bonus_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->capzd_prem_bonus_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(25, Attribute::STRING,	"carvm_stat_annuitzn_tests", -1, (size_t)&modelOffset->carvm_stat_annuitzn_tests,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::INT,	"carvm_stat_annuitzn_tests_cnt", -1, (size_t)&modelOffset->carvm_stat_annuitzn_tests_cnt,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::STR_ENUM,	"carvm_stat_detail_rpt_defn", -1, (size_t)&modelOffset->carvm_stat_detail_rpt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &carvm_stat_detail_rpt_defnEnumList, Feature(true)),
	Descriptor(28, Attribute::STRING,	"carvm_stat_gmwb_exercise_points_attained_age", -1, (size_t)&modelOffset->carvm_stat_gmwb_exercise_points_attained_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(29, Attribute::STRING,	"carvm_stat_gmwb_exercise_points_issue", -1, (size_t)&modelOffset->carvm_stat_gmwb_exercise_points_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(30, Attribute::STRING,	"carvm_stat_gmwb_exercise_points_valn_prd", -1, (size_t)&modelOffset->carvm_stat_gmwb_exercise_points_valn_prd,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(31, Attribute::STRING,	"carvm_tax_annuitzn_tests", -1, (size_t)&modelOffset->carvm_tax_annuitzn_tests,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(32, Attribute::INT,	"carvm_tax_annuitzn_tests_cnt", -1, (size_t)&modelOffset->carvm_tax_annuitzn_tests_cnt,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(33, Attribute::STR_ENUM,	"carvm_tax_detail_rpt_defn", -1, (size_t)&modelOffset->carvm_tax_detail_rpt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &carvm_tax_detail_rpt_defnEnumList, Feature(true)),
	Descriptor(34, Attribute::STRING,	"carvm_tax_gmwb_exercise_points_attained_age", -1, (size_t)&modelOffset->carvm_tax_gmwb_exercise_points_attained_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(35, Attribute::STRING,	"carvm_tax_gmwb_exercise_points_issue", -1, (size_t)&modelOffset->carvm_tax_gmwb_exercise_points_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(36, Attribute::STRING,	"carvm_tax_gmwb_exercise_points_valn_prd", -1, (size_t)&modelOffset->carvm_tax_gmwb_exercise_points_valn_prd,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(37, Attribute::DOUBLE,	"cash_flow_pct_by_prod_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cash_flow_pct_by_prod_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(38, Attribute::DOUBLE,	"cash_flow_pct_vector_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cash_flow_pct_vector_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(39, Attribute::DOUBLE,	"comm_chargeback_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comm_chargeback_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(40, Attribute::DOUBLE,	"comm_chgback_pct_dth_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comm_chgback_pct_dth_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(41, Attribute::DOUBLE,	"comm_chgback_pct_surr_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comm_chgback_pct_surr_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(42, Attribute::DOUBLE,	"comm_pct_fund", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comm_pct_fund,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(43, Attribute::DOUBLE,	"comm_pct_prem", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comm_pct_prem,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(44, Attribute::STR_ENUM,	"comp_rate_compared_defn", -1, (size_t)&modelOffset->comp_rate_compared_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &comp_rate_compared_defnEnumList, Feature(true)),
	Descriptor(45, Attribute::STRING,	"comp_rate_compared_rate1_id", -1, (size_t)&modelOffset->comp_rate_compared_rate1_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(46, Attribute::STRING,	"comp_rate_compared_rate2_id", -1, (size_t)&modelOffset->comp_rate_compared_rate2_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(47, Attribute::STRING,	"comp_rate_compared_rate3_id", -1, (size_t)&modelOffset->comp_rate_compared_rate3_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(48, Attribute::STRING,	"comp_rate_id", -1, (size_t)&modelOffset->comp_rate_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(49, Attribute::DOUBLE,	"comp_rate_single_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comp_rate_single_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(50, Attribute::INT,	"comp_rate_single_avg_mths", -1, (size_t)&modelOffset->comp_rate_single_avg_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(51, Attribute::DOUBLE,	"comp_rate_single_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comp_rate_single_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(52, Attribute::DOUBLE,	"comp_rate_single_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comp_rate_single_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(53, Attribute::STR_ENUM,	"comp_rate_type", -1, (size_t)&modelOffset->comp_rate_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &comp_rate_typeEnumList, Feature(true)),
	Descriptor(54, Attribute::STRING,	"comp_rate_weighted_rate1_id", -1, (size_t)&modelOffset->comp_rate_weighted_rate1_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(55, Attribute::DOUBLE,	"comp_rate_weighted_rate1_weight", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comp_rate_weighted_rate1_weight,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(56, Attribute::STRING,	"comp_rate_weighted_rate2_id", -1, (size_t)&modelOffset->comp_rate_weighted_rate2_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(57, Attribute::DOUBLE,	"comp_rate_weighted_rate2_weight", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comp_rate_weighted_rate2_weight,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(58, Attribute::STRING,	"comp_rate_weighted_rate3_id", -1, (size_t)&modelOffset->comp_rate_weighted_rate3_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(59, Attribute::DOUBLE,	"comp_rate_weighted_rate3_weight", Descriptor::NOT_INDEXED, (size_t)&modelOffset->comp_rate_weighted_rate3_weight,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(60, Attribute::INT,	"confinement_age_crbg", -1, (size_t)&modelOffset->confinement_age_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(61, Attribute::DOUBLE,	"confinement_incidence_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->confinement_incidence_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(62, Attribute::INT,	"confinement_mth_crbg", -1, (size_t)&modelOffset->confinement_mth_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(63, Attribute::DOUBLE,	"confinement_recovery_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->confinement_recovery_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(64, Attribute::DOUBLE,	"confinement_recovery_mult_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->confinement_recovery_mult_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(65, Attribute::INT,	"confinement_yrs_crbg", -1, (size_t)&modelOffset->confinement_yrs_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(66, Attribute::DOUBLE,	"contract_val_net_consideration_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->contract_val_net_consideration_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(67, Attribute::STR_ENUM,	"contract_val_sc_defn", -1, (size_t)&modelOffset->contract_val_sc_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &contract_val_sc_defnEnumList, Feature(true)),
	Descriptor(68, Attribute::DOUBLE,	"crediting_asset_yld_sprd", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_asset_yld_sprd,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(69, Attribute::STR_ENUM,	"crediting_nb_defn", -1, (size_t)&modelOffset->crediting_nb_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &crediting_nb_defnEnumList, Feature(true)),
	Descriptor(70, Attribute::DOUBLE,	"crediting_nb_yld_maturity", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_nb_yld_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(71, Attribute::STRING,	"crediting_nb_yld_rating", -1, (size_t)&modelOffset->crediting_nb_yld_rating,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(72, Attribute::DOUBLE,	"crediting_ner_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_ner_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(73, Attribute::DOUBLE,	"crediting_rate_fixed", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_rate_fixed,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(74, Attribute::DOUBLE,	"crediting_rate_gtd", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_rate_gtd,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(75, Attribute::DOUBLE,	"crediting_rate_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->crediting_rate_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(76, Attribute::STRING,	"crediting_strategy_crbg", -1, (size_t)&modelOffset->crediting_strategy_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(77, Attribute::STRING,	"data_file_name_input", -1, (size_t)&modelOffset->data_file_name_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(78, Attribute::STR_ENUM,	"data_validation_defn", -1, (size_t)&modelOffset->data_validation_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &data_validation_defnEnumList, Feature(true)),
	Descriptor(79, Attribute::STR_ENUM,	"decrements_defn", -1, (size_t)&modelOffset->decrements_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &decrements_defnEnumList, Feature(true)),
	Descriptor(80, Attribute::DOUBLE,	"disc_rate_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->disc_rate_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(81, Attribute::STRING,	"disc_rate_id", -1, (size_t)&modelOffset->disc_rate_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(82, Attribute::DOUBLE,	"disc_rate_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->disc_rate_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(83, Attribute::STR_ENUM,	"disc_rate_port_yld_defn", -1, (size_t)&modelOffset->disc_rate_port_yld_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &disc_rate_port_yld_defnEnumList, Feature(true)),
	Descriptor(84, Attribute::DOUBLE,	"disc_rate_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->disc_rate_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(85, Attribute::DOUBLE,	"disc_rate_sprd_ic_uel_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->disc_rate_sprd_ic_uel_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(86, Attribute::DOUBLE,	"disc_rate_sprd_no_uel_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->disc_rate_sprd_no_uel_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(87, Attribute::DOUBLE,	"disc_rate_sprd_uel_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->disc_rate_sprd_uel_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(88, Attribute::STRING,	"disc_rates_selected", -1, (size_t)&modelOffset->disc_rates_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(89, Attribute::STR_ENUM,	"dth_ben_defn", -1, (size_t)&modelOffset->dth_ben_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &dth_ben_defnEnumList, Feature(true)),
	Descriptor(90, Attribute::DOUBLE,	"dyn_sprd_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->dyn_sprd_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(91, Attribute::DOUBLE,	"dynamic_lapse_gmwb_itm_threshold", Descriptor::NOT_INDEXED, (size_t)&modelOffset->dynamic_lapse_gmwb_itm_threshold,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(92, Attribute::DOUBLE,	"enh_inc_mawp_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->enh_inc_mawp_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(93, Attribute::INT,	"enh_inc_max_cumul_yrs", -1, (size_t)&modelOffset->enh_inc_max_cumul_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(94, Attribute::DOUBLE,	"enh_inc_utilization_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->enh_inc_utilization_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(95, Attribute::INT,	"enh_inc_wait_period", -1, (size_t)&modelOffset->enh_inc_wait_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(96, Attribute::STR_ENUM,	"enhanced_income_ind_crbg", -1, (size_t)&modelOffset->enhanced_income_ind_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &enhanced_income_ind_crbgEnumList, Feature(true)),
	Descriptor(97, Attribute::STR_ENUM,	"eprs_sfc_defn", -1, (size_t)&modelOffset->eprs_sfc_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &eprs_sfc_defnEnumList, Feature(true)),
	Descriptor(98, Attribute::DOUBLE,	"exp_adj_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->exp_adj_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(99, Attribute::DOUBLE,	"fa_base_lapse_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_base_lapse_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(100, Attribute::DOUBLE,	"fa_credit_dyn_beta_a_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_credit_dyn_beta_a_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(101, Attribute::DOUBLE,	"fa_credit_dyn_beta_b_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_credit_dyn_beta_b_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(102, Attribute::DOUBLE,	"fa_credit_dyn_beta_c_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_credit_dyn_beta_c_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(103, Attribute::DOUBLE,	"fa_dyn_lapse_av_size_mult_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_dyn_lapse_av_size_mult_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(104, Attribute::DOUBLE,	"fa_dyn_lapse_dyn_sprd_mult_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_dyn_lapse_dyn_sprd_mult_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(105, Attribute::DOUBLE,	"fa_dyn_lapse_mult_alpha_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_dyn_lapse_mult_alpha_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(106, Attribute::DOUBLE,	"fa_dyn_lapse_mult_beta_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_dyn_lapse_mult_beta_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(107, Attribute::DOUBLE,	"fa_guar_rate_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_guar_rate_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(108, Attribute::DOUBLE,	"fa_init_bonus_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_init_bonus_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(109, Attribute::DOUBLE,	"fa_init_pri_sprd_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_init_pri_sprd_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(110, Attribute::DOUBLE,	"fa_lapse_factor_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_lapse_factor_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(111, Attribute::DOUBLE,	"fa_ner_cap_sprd_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_ner_cap_sprd_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(112, Attribute::DOUBLE,	"fa_pricing_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_pricing_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(113, Attribute::INT,	"fa_rate_migration_yr_crbg", -1, (size_t)&modelOffset->fa_rate_migration_yr_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(114, Attribute::DOUBLE,	"fa_renew_rate_max_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fa_renew_rate_max_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(115, Attribute::DOUBLE,	"fund_val_beg_term", Descriptor::NOT_INDEXED, (size_t)&modelOffset->fund_val_beg_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(116, Attribute::STR_ENUM,	"fund_val_rebal_defn", -1, (size_t)&modelOffset->fund_val_rebal_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &fund_val_rebal_defnEnumList, Feature(true)),
	Descriptor(117, Attribute::STR_ENUM,	"fund_val_rebal_freq_defn", -1, (size_t)&modelOffset->fund_val_rebal_freq_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &fund_val_rebal_freq_defnEnumList, Feature(true)),
	Descriptor(118, Attribute::STR_ENUM,	"fund_val_rebal_prop_defn", -1, (size_t)&modelOffset->fund_val_rebal_prop_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &fund_val_rebal_prop_defnEnumList, Feature(true)),
	Descriptor(119, Attribute::STRING,	"gaap_cohorts_selected_sfas97rd", -1, (size_t)&modelOffset->gaap_cohorts_selected_sfas97rd,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(120, Attribute::STR_ENUM,	"gaap_defn", -1, (size_t)&modelOffset->gaap_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gaap_defnEnumList, Feature(true)),
	Descriptor(121, Attribute::DOUBLE,	"gaap_int_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gaap_int_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(122, Attribute::DOUBLE,	"gaap_int_rate_input", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gaap_int_rate_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(123, Attribute::STR_ENUM,	"gen2_declarations", -1, (size_t)&modelOffset->gen2_declarations,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen2_declarationsEnumList, Feature(true)),
	Descriptor(124, Attribute::STR_ENUM,	"gender_aft_inc", -1, (size_t)&modelOffset->gender_aft_inc,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gender_aft_incEnumList, Feature(true)),
	Descriptor(125, Attribute::STR_ENUM,	"gender_mp", -1, (size_t)&modelOffset->gender_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gender_mpEnumList, Feature(true)),
	Descriptor(126, Attribute::DOUBLE,	"glb_itm_disc_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->glb_itm_disc_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(127, Attribute::DOUBLE,	"gmab_av_cap_rt_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmab_av_cap_rt_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(128, Attribute::DOUBLE,	"gmab_chg_pct_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmab_chg_pct_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(129, Attribute::DOUBLE,	"gmab_credit_rt_mult_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmab_credit_rt_mult_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(130, Attribute::INT,	"gmab_csv_grop_yr_crbg", -1, (size_t)&modelOffset->gmab_csv_grop_yr_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(131, Attribute::INT,	"gmab_ind_crbg", -1, (size_t)&modelOffset->gmab_ind_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(132, Attribute::STR_ENUM,	"gmwb_chg_at_surr_crbg", -1, (size_t)&modelOffset->gmwb_chg_at_surr_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_chg_at_surr_crbgEnumList, Feature(true)),
	Descriptor(133, Attribute::STR_ENUM,	"gmwb_chg_base", -1, (size_t)&modelOffset->gmwb_chg_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_chg_baseEnumList, Feature(true)),
	Descriptor(134, Attribute::DOUBLE,	"gmwb_chg_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_chg_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(135, Attribute::STR_ENUM,	"gmwb_chg_surr_timing_crbg", -1, (size_t)&modelOffset->gmwb_chg_surr_timing_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_chg_surr_timing_crbgEnumList, Feature(true)),
	Descriptor(136, Attribute::DOUBLE,	"gmwb_claim_disc_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_claim_disc_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(137, Attribute::STR_ENUM,	"gmwb_claim_disc_rate_defn", -1, (size_t)&modelOffset->gmwb_claim_disc_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_claim_disc_rate_defnEnumList, Feature(true)),
	Descriptor(138, Attribute::STRING,	"gmwb_code", -1, (size_t)&modelOffset->gmwb_code,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(139, Attribute::INT,	"gmwb_cohort_id", -1, (size_t)&modelOffset->gmwb_cohort_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(140, Attribute::STR_ENUM,	"gmwb_cohort_utilz_defn", -1, (size_t)&modelOffset->gmwb_cohort_utilz_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_cohort_utilz_defnEnumList, Feature(true)),
	Descriptor(141, Attribute::DOUBLE,	"gmwb_cohort_utilz_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_cohort_utilz_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(142, Attribute::STR_ENUM,	"gmwb_credit_aft_income_crbg", -1, (size_t)&modelOffset->gmwb_credit_aft_income_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_credit_aft_income_crbgEnumList, Feature(true)),
	Descriptor(143, Attribute::DOUBLE,	"gmwb_credit_mult_aft_inc_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_credit_mult_aft_inc_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(144, Attribute::DOUBLE,	"gmwb_credit_mult_bef_inc_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_credit_mult_bef_inc_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(145, Attribute::STR_ENUM,	"gmwb_defn", -1, (size_t)&modelOffset->gmwb_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_defnEnumList, Feature(true)),
	Descriptor(146, Attribute::INT,	"gmwb_doubling_year_crbg", -1, (size_t)&modelOffset->gmwb_doubling_year_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(147, Attribute::DOUBLE,	"gmwb_exercise_yrs", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_exercise_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(148, Attribute::DOUBLE,	"gmwb_flex_base_lapse_mult_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_flex_base_lapse_mult_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(149, Attribute::STR_ENUM,	"gmwb_fund_val_defn", -1, (size_t)&modelOffset->gmwb_fund_val_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_fund_val_defnEnumList, Feature(true)),
	Descriptor(150, Attribute::DOUBLE,	"gmwb_fund_val_period", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_fund_val_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(151, Attribute::INT,	"gmwb_ind", -1, (size_t)&modelOffset->gmwb_ind,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(152, Attribute::DOUBLE,	"gmwb_mawp_addn_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_mawp_addn_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(153, Attribute::INT,	"gmwb_max_age", -1, (size_t)&modelOffset->gmwb_max_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(154, Attribute::DOUBLE,	"gmwb_max_annual_wdl_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_max_annual_wdl_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(155, Attribute::INT,	"gmwb_max_exec_point", -1, (size_t)&modelOffset->gmwb_max_exec_point,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(156, Attribute::INT,	"gmwb_max_rollup_duration", -1, (size_t)&modelOffset->gmwb_max_rollup_duration,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(157, Attribute::STR_ENUM,	"gmwb_max_wdl_amt_base_defn", -1, (size_t)&modelOffset->gmwb_max_wdl_amt_base_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_max_wdl_amt_base_defnEnumList, Feature(true)),
	Descriptor(158, Attribute::INT,	"gmwb_min_age", -1, (size_t)&modelOffset->gmwb_min_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(159, Attribute::DOUBLE,	"gmwb_mort_base", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_mort_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(160, Attribute::STRING,	"gmwb_mort_base_tbl_id", -1, (size_t)&modelOffset->gmwb_mort_base_tbl_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(161, Attribute::STRING,	"gmwb_mort_base_tbl_style", -1, (size_t)&modelOffset->gmwb_mort_base_tbl_style,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(162, Attribute::DOUBLE,	"gmwb_mrb_req_prof_chg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_mrb_req_prof_chg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(163, Attribute::STR_ENUM,	"gmwb_pfwd_dyn_defn", -1, (size_t)&modelOffset->gmwb_pfwd_dyn_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_pfwd_dyn_defnEnumList, Feature(true)),
	Descriptor(164, Attribute::DOUBLE,	"gmwb_pfwd_dyn_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_pfwd_dyn_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(165, Attribute::DOUBLE,	"gmwb_pipp_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_pipp_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(166, Attribute::DOUBLE,	"gmwb_pipp_stepup_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_pipp_stepup_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(167, Attribute::STR_ENUM,	"gmwb_prem_defn", -1, (size_t)&modelOffset->gmwb_prem_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_prem_defnEnumList, Feature(true)),
	Descriptor(168, Attribute::STR_ENUM,	"gmwb_reg47_crbg", -1, (size_t)&modelOffset->gmwb_reg47_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_reg47_crbgEnumList, Feature(true)),
	Descriptor(169, Attribute::DOUBLE,	"gmwb_reg47_slope_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_reg47_slope_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(170, Attribute::DOUBLE,	"gmwb_rollup_cap", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_rollup_cap,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(171, Attribute::STR_ENUM,	"gmwb_rollup_credit_type_crbg", -1, (size_t)&modelOffset->gmwb_rollup_credit_type_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_rollup_credit_type_crbgEnumList, Feature(true)),
	Descriptor(172, Attribute::STR_ENUM,	"gmwb_rollup_freq_defn", -1, (size_t)&modelOffset->gmwb_rollup_freq_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_rollup_freq_defnEnumList, Feature(true)),
	Descriptor(173, Attribute::DOUBLE,	"gmwb_rollup_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_rollup_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(174, Attribute::STR_ENUM,	"gmwb_rollup_rate_type", -1, (size_t)&modelOffset->gmwb_rollup_rate_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_rollup_rate_typeEnumList, Feature(true)),
	Descriptor(175, Attribute::DOUBLE,	"gmwb_step_up_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_step_up_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(176, Attribute::STRING,	"gmwb_type_crbg", -1, (size_t)&modelOffset->gmwb_type_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(177, Attribute::STRING,	"gmwb_util_broker_type_crbg", -1, (size_t)&modelOffset->gmwb_util_broker_type_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(178, Attribute::DOUBLE,	"gmwb_wait_period", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_wait_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(179, Attribute::DOUBLE,	"gmwb_wdl_avg_util_pct_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_wdl_avg_util_pct_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(180, Attribute::DOUBLE,	"gmwb_wdl_next_util_prob_1_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_wdl_next_util_prob_1_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(181, Attribute::DOUBLE,	"gmwb_wdl_next_util_prob_2_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_wdl_next_util_prob_2_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(182, Attribute::DOUBLE,	"gmwb_wdl_random_util_rate_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_wdl_random_util_rate_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(183, Attribute::STR_ENUM,	"gmwb_wdl_reduce_ben_base", -1, (size_t)&modelOffset->gmwb_wdl_reduce_ben_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_wdl_reduce_ben_baseEnumList, Feature(true)),
	Descriptor(184, Attribute::STR_ENUM,	"gmwb_wdl_trig_by_confinement", -1, (size_t)&modelOffset->gmwb_wdl_trig_by_confinement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_wdl_trig_by_confinementEnumList, Feature(true)),
	Descriptor(185, Attribute::DOUBLE,	"gmwb_wdl_util_init_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gmwb_wdl_util_init_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(186, Attribute::INT,	"gmwb_wdl_util_level_crbg", -1, (size_t)&modelOffset->gmwb_wdl_util_level_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(187, Attribute::INT,	"gmwb_wdl_util_tgt_level_crbg", -1, (size_t)&modelOffset->gmwb_wdl_util_tgt_level_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(188, Attribute::STR_ENUM,	"gmwb_wdl_util_type_crbg", -1, (size_t)&modelOffset->gmwb_wdl_util_type_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gmwb_wdl_util_type_crbgEnumList, Feature(true)),
	Descriptor(189, Attribute::INT,	"gmwb_withdrl_age", -1, (size_t)&modelOffset->gmwb_withdrl_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(190, Attribute::INT,	"gmwb_withdrl_yr_lookup", -1, (size_t)&modelOffset->gmwb_withdrl_yr_lookup,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(191, Attribute::INT,	"grop_ind_crbg", -1, (size_t)&modelOffset->grop_ind_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(192, Attribute::STR_ENUM,	"gsia_reins_defn_crbg", -1, (size_t)&modelOffset->gsia_reins_defn_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gsia_reins_defn_crbgEnumList, Feature(true)),
	Descriptor(193, Attribute::DOUBLE,	"gwl_acq_exp_allow_level_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gwl_acq_exp_allow_level_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(194, Attribute::DOUBLE,	"gwl_infl_addn_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gwl_infl_addn_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(195, Attribute::DOUBLE,	"gwl_infl_mult1_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gwl_infl_mult1_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(196, Attribute::DOUBLE,	"gwl_infl_mult2_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gwl_infl_mult2_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(197, Attribute::DOUBLE,	"gwl_maint_exp_allow_level_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->gwl_maint_exp_allow_level_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(198, Attribute::DOUBLE,	"host_accrual_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->host_accrual_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(199, Attribute::STRING,	"index_id_lookup", -1, (size_t)&modelOffset->index_id_lookup,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(200, Attribute::DOUBLE,	"index_val_beg_term", Descriptor::NOT_INDEXED, (size_t)&modelOffset->index_val_beg_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(201, Attribute::DOUBLE,	"infl_deduction_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->infl_deduction_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(202, Attribute::DOUBLE,	"infl_mult_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->infl_mult_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(203, Attribute::DOUBLE,	"infl_rate_const_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->infl_rate_const_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(204, Attribute::STR_ENUM,	"infl_rate_defn_crbg", -1, (size_t)&modelOffset->infl_rate_defn_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &infl_rate_defn_crbgEnumList, Feature(true)),
	Descriptor(205, Attribute::STRING,	"infl_start_date", -1, (size_t)&modelOffset->infl_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(206, Attribute::DOUBLE,	"init_cap_rate_index0", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_cap_rate_index0,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(207, Attribute::DOUBLE,	"init_cap_rate_index1", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_cap_rate_index1,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(208, Attribute::DOUBLE,	"init_cap_rate_index2", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_cap_rate_index2,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(209, Attribute::DOUBLE,	"init_cap_rate_index3", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_cap_rate_index3,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(210, Attribute::DOUBLE,	"init_cap_rate_index4", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_cap_rate_index4,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(211, Attribute::DOUBLE,	"init_cash_val", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_cash_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(212, Attribute::DOUBLE,	"init_cash_val_no_mva", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_cash_val_no_mva,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(213, Attribute::DOUBLE,	"init_comm_subject_to_chargeback", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_comm_subject_to_chargeback,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(214, Attribute::DOUBLE,	"init_contract_val", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_contract_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(215, Attribute::DOUBLE,	"init_crediting_rate_cumul", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_crediting_rate_cumul,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(216, Attribute::DOUBLE,	"init_eprs_part_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_eprs_part_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(217, Attribute::DOUBLE,	"init_fund_val_boy", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_fund_val_boy,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(218, Attribute::DOUBLE,	"init_fund_val_fixed", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_fund_val_fixed,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(219, Attribute::DOUBLE,	"init_fund_val_index0", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_fund_val_index0,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(220, Attribute::DOUBLE,	"init_fund_val_index1", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_fund_val_index1,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(221, Attribute::DOUBLE,	"init_fund_val_index2", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_fund_val_index2,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(222, Attribute::DOUBLE,	"init_fund_val_index3", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_fund_val_index3,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(223, Attribute::DOUBLE,	"init_fund_val_index4", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_fund_val_index4,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(224, Attribute::DOUBLE,	"init_gmab_av", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_gmab_av,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(225, Attribute::DOUBLE,	"init_gmwb_entitlement_remaining", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_gmwb_entitlement_remaining,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(226, Attribute::DOUBLE,	"init_gmwb_fund_val", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_gmwb_fund_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(227, Attribute::DOUBLE,	"init_gmwb_income_credit_base", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_gmwb_income_credit_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(228, Attribute::DOUBLE,	"init_gmwb_max_ann_wdl_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_gmwb_max_ann_wdl_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(229, Attribute::DOUBLE,	"init_gmwb_max_wdl_amt", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_gmwb_max_wdl_amt,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(230, Attribute::DOUBLE,	"init_gmwb_prem", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_gmwb_prem,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(231, Attribute::DOUBLE,	"init_gmwb_wdl_excess_ind", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_gmwb_wdl_excess_ind,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(232, Attribute::DOUBLE,	"init_gmwb_wdl_util_level", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_gmwb_wdl_util_level,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(233, Attribute::DOUBLE,	"init_gmwb_wdl_util_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_gmwb_wdl_util_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(234, Attribute::DOUBLE,	"init_hedge_budget", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_hedge_budget,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(235, Attribute::DOUBLE,	"init_hedge_mkt_val_per_unit", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_hedge_mkt_val_per_unit,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(236, Attribute::DOUBLE,	"init_host_val", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_host_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(237, Attribute::DOUBLE,	"init_index_val", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_index_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(238, Attribute::DOUBLE,	"init_min_accum_val", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_min_accum_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(239, Attribute::DOUBLE,	"init_min_wdl_val", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_min_wdl_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(240, Attribute::DOUBLE,	"init_opt_cost_beg_term", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_opt_cost_beg_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(241, Attribute::DOUBLE,	"init_part_rate_index0", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_part_rate_index0,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(242, Attribute::DOUBLE,	"init_part_rate_index1", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_part_rate_index1,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(243, Attribute::DOUBLE,	"init_part_rate_index2", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_part_rate_index2,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(244, Attribute::DOUBLE,	"init_part_rate_index3", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_part_rate_index3,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(245, Attribute::DOUBLE,	"init_part_rate_index4", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_part_rate_index4,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(246, Attribute::DOUBLE,	"init_pfwd_curr_pol_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_pfwd_curr_pol_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(247, Attribute::DOUBLE,	"init_pfwd_entitlement", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_pfwd_entitlement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(248, Attribute::DOUBLE,	"init_policies", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_policies,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(249, Attribute::DOUBLE,	"init_policies_female_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_policies_female_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(250, Attribute::DOUBLE,	"init_policies_joint_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_policies_joint_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(251, Attribute::DOUBLE,	"init_policies_male_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_policies_male_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(252, Attribute::DOUBLE,	"init_prem_bonus_base", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_prem_bonus_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(253, Attribute::DOUBLE,	"init_prem_net_wdl", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_prem_net_wdl,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(254, Attribute::DOUBLE,	"init_prem_prop_wdl", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_prem_prop_wdl,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(255, Attribute::DOUBLE,	"init_rebal_pct_fixed", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_rebal_pct_fixed,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	};
	Attribute::Descriptor FIA_LIAB::descriptor_256[] = {
	Descriptor(256, Attribute::DOUBLE,	"init_rebal_pct_index0", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_rebal_pct_index0,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(257, Attribute::DOUBLE,	"init_rebal_pct_index1", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_rebal_pct_index1,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(258, Attribute::DOUBLE,	"init_rebal_pct_index2", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_rebal_pct_index2,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(259, Attribute::DOUBLE,	"init_rebal_pct_index3", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_rebal_pct_index3,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(260, Attribute::DOUBLE,	"init_rebal_pct_index4", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_rebal_pct_index4,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(261, Attribute::DOUBLE,	"init_sprd_rate_index0", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_sprd_rate_index0,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(262, Attribute::DOUBLE,	"init_stat_res_carvm", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_stat_res_carvm,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(263, Attribute::DOUBLE,	"init_tax_res_carvm", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_tax_res_carvm,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(264, Attribute::DOUBLE,	"init_trigger_rate_index0", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_trigger_rate_index0,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(265, Attribute::DOUBLE,	"init_withdrl_cumul", Descriptor::NOT_INDEXED, (size_t)&modelOffset->init_withdrl_cumul,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(266, Attribute::DOUBLE,	"isl_alpha_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->isl_alpha_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(267, Attribute::DOUBLE,	"isl_beta_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->isl_beta_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(268, Attribute::DOUBLE,	"isl_coefficient_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->isl_coefficient_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(269, Attribute::DOUBLE,	"isl_divisor_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->isl_divisor_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(270, Attribute::DOUBLE,	"isl_surr_chg_threshold", Descriptor::NOT_INDEXED, (size_t)&modelOffset->isl_surr_chg_threshold,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(271, Attribute::INT,	"issue_age_female_crbg", -1, (size_t)&modelOffset->issue_age_female_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(272, Attribute::INT,	"issue_age_male_crbg", -1, (size_t)&modelOffset->issue_age_male_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(273, Attribute::INT,	"issue_age_mp", -1, (size_t)&modelOffset->issue_age_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(274, Attribute::STRING,	"issue_date_mp", -1, (size_t)&modelOffset->issue_date_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(275, Attribute::STR_ENUM,	"itm_defn", -1, (size_t)&modelOffset->itm_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &itm_defnEnumList, Feature(true)),
	Descriptor(276, Attribute::STR_ENUM,	"itm_denom_defn_crbg", -1, (size_t)&modelOffset->itm_denom_defn_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &itm_denom_defn_crbgEnumList, Feature(true)),
	Descriptor(277, Attribute::STRING,	"itm_disc_curve_crbg", -1, (size_t)&modelOffset->itm_disc_curve_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(278, Attribute::DOUBLE,	"lapse_adj_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_adj_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(279, Attribute::STR_ENUM,	"lapse_dyn_base_prod_defn_crbg", -1, (size_t)&modelOffset->lapse_dyn_base_prod_defn_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &lapse_dyn_base_prod_defn_crbgEnumList, Feature(true)),
	Descriptor(280, Attribute::DOUBLE,	"lapse_dyn_base_prod_max_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_dyn_base_prod_max_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(281, Attribute::DOUBLE,	"lapse_dyn_base_prod_min_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_dyn_base_prod_min_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(282, Attribute::DOUBLE,	"lapse_dyn_base_prod_mult1_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_dyn_base_prod_mult1_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(283, Attribute::DOUBLE,	"lapse_dyn_base_prod_mult2_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_dyn_base_prod_mult2_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(284, Attribute::DOUBLE,	"lapse_dyn_base_prod_threshold_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_dyn_base_prod_threshold_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(285, Attribute::DOUBLE,	"lapse_dyn_exp", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_dyn_exp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(286, Attribute::DOUBLE,	"lapse_dyn_exp_param_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_dyn_exp_param_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(287, Attribute::STR_ENUM,	"lapse_dyn_isl_defn_crbg", -1, (size_t)&modelOffset->lapse_dyn_isl_defn_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &lapse_dyn_isl_defn_crbgEnumList, Feature(true)),
	Descriptor(288, Attribute::DOUBLE,	"lapse_dyn_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_dyn_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(289, Attribute::DOUBLE,	"lapse_dyn_mult_floor_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_dyn_mult_floor_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(290, Attribute::DOUBLE,	"lapse_dyn_mva_mult_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_dyn_mva_mult_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(291, Attribute::STR_ENUM,	"lapse_dyn_preshock_sprd_crbg", -1, (size_t)&modelOffset->lapse_dyn_preshock_sprd_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &lapse_dyn_preshock_sprd_crbgEnumList, Feature(true)),
	Descriptor(292, Attribute::DOUBLE,	"lapse_dyn_scmult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_dyn_scmult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(293, Attribute::STR_ENUM,	"lapse_dyn_shock_yr_defn_crbg", -1, (size_t)&modelOffset->lapse_dyn_shock_yr_defn_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &lapse_dyn_shock_yr_defn_crbgEnumList, Feature(true)),
	Descriptor(294, Attribute::DOUBLE,	"lapse_dyn_thresh", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_dyn_thresh,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(295, Attribute::STR_ENUM,	"lapse_is_dynamic", -1, (size_t)&modelOffset->lapse_is_dynamic,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &lapse_is_dynamicEnumList, Feature(true)),
	Descriptor(296, Attribute::DOUBLE,	"lapse_rate_input", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_rate_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(297, Attribute::DOUBLE,	"lapse_rate_max", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_rate_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(298, Attribute::DOUBLE,	"lapse_rate_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_rate_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(299, Attribute::DOUBLE,	"lapse_shock_yr_max_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_shock_yr_max_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(300, Attribute::DOUBLE,	"lapse_shock_yr_min_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_shock_yr_min_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(301, Attribute::DOUBLE,	"lapse_skew_fct1_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_skew_fct1_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(302, Attribute::DOUBLE,	"lapse_skew_fct2_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_skew_fct2_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(303, Attribute::STR_ENUM,	"lapse_skew_method_crbg", -1, (size_t)&modelOffset->lapse_skew_method_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &lapse_skew_method_crbgEnumList, Feature(true)),
	Descriptor(304, Attribute::DOUBLE,	"lapse_skew_split_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->lapse_skew_split_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(305, Attribute::DOUBLE,	"licensing_fee_pct_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->licensing_fee_pct_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(306, Attribute::DOUBLE,	"maint_exp_pct_fund", Descriptor::NOT_INDEXED, (size_t)&modelOffset->maint_exp_pct_fund,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(307, Attribute::DOUBLE,	"maint_exp_per_pol", Descriptor::NOT_INDEXED, (size_t)&modelOffset->maint_exp_per_pol,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(308, Attribute::DOUBLE,	"male_sex_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->male_sex_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(309, Attribute::INT,	"maturity_age_input", -1, (size_t)&modelOffset->maturity_age_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(310, Attribute::DOUBLE,	"mav_growth_rate_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mav_growth_rate_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(311, Attribute::STR_ENUM,	"mawp_lookup_type_crbg", -1, (size_t)&modelOffset->mawp_lookup_type_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mawp_lookup_type_crbgEnumList, Feature(true)),
	Descriptor(312, Attribute::INT,	"min_cash_val_mths", -1, (size_t)&modelOffset->min_cash_val_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(313, Attribute::DOUBLE,	"mort_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mort_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(314, Attribute::DOUBLE,	"mort_adj_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mort_adj_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(315, Attribute::INT,	"mort_attained_age", -1, (size_t)&modelOffset->mort_attained_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(316, Attribute::DOUBLE,	"mort_base", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mort_base,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(317, Attribute::DOUBLE,	"mort_base_confined_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mort_base_confined_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(318, Attribute::STRING,	"mort_base_curr_tbl_id", -1, (size_t)&modelOffset->mort_base_curr_tbl_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(319, Attribute::STRING,	"mort_base_curr_tbl_style", -1, (size_t)&modelOffset->mort_base_curr_tbl_style,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(320, Attribute::STRING,	"mort_base_guar_tbl_id", -1, (size_t)&modelOffset->mort_base_guar_tbl_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(321, Attribute::STRING,	"mort_base_guar_tbl_style", -1, (size_t)&modelOffset->mort_base_guar_tbl_style,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(322, Attribute::DOUBLE,	"mort_base_non_confined_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mort_base_non_confined_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(323, Attribute::DOUBLE,	"mort_base_omega", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mort_base_omega,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(324, Attribute::STRING,	"mort_base_tbl_id", -1, (size_t)&modelOffset->mort_base_tbl_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(325, Attribute::STRING,	"mort_base_tbl_style", -1, (size_t)&modelOffset->mort_base_tbl_style,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(326, Attribute::INT,	"mort_cal_yr", -1, (size_t)&modelOffset->mort_cal_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(327, Attribute::STR_ENUM,	"mort_calc_basis", -1, (size_t)&modelOffset->mort_calc_basis,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mort_calc_basisEnumList, Feature(true)),
	Descriptor(328, Attribute::STR_ENUM,	"mort_gender", -1, (size_t)&modelOffset->mort_gender,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mort_genderEnumList, Feature(true)),
	Descriptor(329, Attribute::STRING,	"mort_impr_base_date_crbg", -1, (size_t)&modelOffset->mort_impr_base_date_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(330, Attribute::STRING,	"mort_impr_tbl_id", -1, (size_t)&modelOffset->mort_impr_tbl_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(331, Attribute::INT,	"mort_improve_base_yr", -1, (size_t)&modelOffset->mort_improve_base_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(332, Attribute::DOUBLE,	"mort_improve_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mort_improve_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(333, Attribute::INT,	"mort_issue_age", -1, (size_t)&modelOffset->mort_issue_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(334, Attribute::DOUBLE,	"mort_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mort_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(335, Attribute::DOUBLE,	"mort_mult_confined_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mort_mult_confined_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(336, Attribute::INT,	"mort_pol_yr", -1, (size_t)&modelOffset->mort_pol_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(337, Attribute::STRING,	"mp_id", -1, (size_t)&modelOffset->mp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(338, Attribute::DOUBLE,	"mva_adj_ratio_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mva_adj_ratio_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(339, Attribute::STR_ENUM,	"mva_cap_defn_crbg", -1, (size_t)&modelOffset->mva_cap_defn_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mva_cap_defn_crbgEnumList, Feature(true)),
	Descriptor(340, Attribute::STRING,	"mva_comp_rate_id", -1, (size_t)&modelOffset->mva_comp_rate_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(341, Attribute::STR_ENUM,	"mva_constraint_defn", -1, (size_t)&modelOffset->mva_constraint_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mva_constraint_defnEnumList, Feature(true)),
	Descriptor(342, Attribute::STR_ENUM,	"mva_defn", -1, (size_t)&modelOffset->mva_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &mva_defnEnumList, Feature(true)),
	Descriptor(343, Attribute::INT,	"mva_guar_yrs_renewal", -1, (size_t)&modelOffset->mva_guar_yrs_renewal,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(344, Attribute::INT,	"mva_init_term", -1, (size_t)&modelOffset->mva_init_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(345, Attribute::INT,	"mva_renewal_term_crbg", -1, (size_t)&modelOffset->mva_renewal_term_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(346, Attribute::DOUBLE,	"mwv_growth_pct_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mwv_growth_pct_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(347, Attribute::DOUBLE,	"mwv_prem_pct_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->mwv_prem_pct_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(348, Attribute::DOUBLE,	"myga_current_term", Descriptor::NOT_INDEXED, (size_t)&modelOffset->myga_current_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(349, Attribute::INT,	"myga_init_term_crbg", -1, (size_t)&modelOffset->myga_init_term_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(350, Attribute::STR_ENUM,	"myga_renew_ind_crbg", -1, (size_t)&modelOffset->myga_renew_ind_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &myga_renew_ind_crbgEnumList, Feature(true)),
	Descriptor(351, Attribute::INT,	"myga_renew_term_crbg", -1, (size_t)&modelOffset->myga_renew_term_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(352, Attribute::DOUBLE,	"myga_term_mth_elapsed_eom", Descriptor::NOT_INDEXED, (size_t)&modelOffset->myga_term_mth_elapsed_eom,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(353, Attribute::DOUBLE,	"nb_cap_rate_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->nb_cap_rate_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(354, Attribute::DOUBLE,	"nb_eprs_add_par_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->nb_eprs_add_par_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(355, Attribute::DOUBLE,	"nb_fixed_rate_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->nb_fixed_rate_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(356, Attribute::DOUBLE,	"nb_opt_budget_input_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->nb_opt_budget_input_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(357, Attribute::DOUBLE,	"nb_part_rate_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->nb_part_rate_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(358, Attribute::DOUBLE,	"nb_sprd_rate_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->nb_sprd_rate_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(359, Attribute::DOUBLE,	"nb_trigger_rate_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->nb_trigger_rate_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(360, Attribute::STR_ENUM,	"ner_correction_crbg", -1, (size_t)&modelOffset->ner_correction_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &ner_correction_crbgEnumList, Feature(true)),
	Descriptor(361, Attribute::DOUBLE,	"nmr_spread_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->nmr_spread_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(362, Attribute::DOUBLE,	"non_us_return_beta_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->non_us_return_beta_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(363, Attribute::DOUBLE,	"non_us_return_sigma_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->non_us_return_sigma_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(364, Attribute::STR_ENUM,	"ny_glb_ind_crbg", -1, (size_t)&modelOffset->ny_glb_ind_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &ny_glb_ind_crbgEnumList, Feature(true)),
	Descriptor(365, Attribute::STR_ENUM,	"nyia_ind_crbg", -1, (size_t)&modelOffset->nyia_ind_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &nyia_ind_crbgEnumList, Feature(true)),
	Descriptor(366, Attribute::INT,	"opt_budget_const_yr_crbg", -1, (size_t)&modelOffset->opt_budget_const_yr_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(367, Attribute::STR_ENUM,	"opt_defn", -1, (size_t)&modelOffset->opt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &opt_defnEnumList, Feature(true)),
	Descriptor(368, Attribute::DOUBLE,	"pba_base_lapse_mult_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pba_base_lapse_mult_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(369, Attribute::DOUBLE,	"pba_infl_intercept_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pba_infl_intercept_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(370, Attribute::DOUBLE,	"pba_infl_slope_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pba_infl_slope_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(371, Attribute::DOUBLE,	"pba_maint_exp_mult_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pba_maint_exp_mult_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(372, Attribute::DOUBLE,	"pba_mort_mult_no_gmwb_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pba_mort_mult_no_gmwb_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(373, Attribute::DOUBLE,	"pba_pfwd_pct_mult_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pba_pfwd_pct_mult_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(374, Attribute::DOUBLE,	"pba_trail_comm_mult_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pba_trail_comm_mult_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(375, Attribute::STR_ENUM,	"pfwd_amt_avail_defn", -1, (size_t)&modelOffset->pfwd_amt_avail_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &pfwd_amt_avail_defnEnumList, Feature(true)),
	Descriptor(376, Attribute::STR_ENUM,	"pfwd_freq", -1, (size_t)&modelOffset->pfwd_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &pfwd_freqEnumList, Feature(true)),
	Descriptor(377, Attribute::DOUBLE,	"pfwd_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pfwd_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(378, Attribute::DOUBLE,	"pfwd_rate_calc_fct1_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pfwd_rate_calc_fct1_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(379, Attribute::DOUBLE,	"pfwd_rate_calc_fct2_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pfwd_rate_calc_fct2_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(380, Attribute::DOUBLE,	"pfwd_use", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pfwd_use,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(381, Attribute::DOUBLE,	"pfwd_use_addl_shock_yr_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pfwd_use_addl_shock_yr_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(382, Attribute::DOUBLE,	"pfwd_use_nq_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pfwd_use_nq_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(383, Attribute::DOUBLE,	"pfwd_use_q_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pfwd_use_q_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(384, Attribute::DOUBLE,	"pfwd_use_qual_pct_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pfwd_use_qual_pct_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(385, Attribute::INT,	"pipp_stepup_age_crbg", -1, (size_t)&modelOffset->pipp_stepup_age_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(386, Attribute::STRING,	"plan_code", -1, (size_t)&modelOffset->plan_code,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(387, Attribute::INT,	"pol_mth_lookup", -1, (size_t)&modelOffset->pol_mth_lookup,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(388, Attribute::INT,	"pol_yr_lookup", -1, (size_t)&modelOffset->pol_yr_lookup,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(389, Attribute::STRING,	"pos_sprd_ind_crbg", -1, (size_t)&modelOffset->pos_sprd_ind_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(390, Attribute::STR_ENUM,	"prem_band", -1, (size_t)&modelOffset->prem_band,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &prem_bandEnumList, Feature(true)),
	Descriptor(391, Attribute::DOUBLE,	"prem_bonus_recap_pct_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->prem_bonus_recap_pct_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(392, Attribute::DOUBLE,	"prem_credit", Descriptor::NOT_INDEXED, (size_t)&modelOffset->prem_credit,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(393, Attribute::DOUBLE,	"prem_tax_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->prem_tax_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(394, Attribute::DOUBLE,	"pri_sprd_tgt_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->pri_sprd_tgt_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(395, Attribute::STR_ENUM,	"pricing_defn", -1, (size_t)&modelOffset->pricing_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &pricing_defnEnumList, Feature(true)),
	Descriptor(396, Attribute::STR_ENUM,	"prof_distribn_mode", -1, (size_t)&modelOffset->prof_distribn_mode,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &prof_distribn_modeEnumList, Feature(true)),
	Descriptor(397, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(398, Attribute::STRING,	"purch_rate_curr_comp_rate_id", -1, (size_t)&modelOffset->purch_rate_curr_comp_rate_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(399, Attribute::STR_ENUM,	"purch_rate_curr_defn", -1, (size_t)&modelOffset->purch_rate_curr_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_rate_curr_defnEnumList, Feature(true)),
	Descriptor(400, Attribute::DOUBLE,	"purch_rate_curr_fixed", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_rate_curr_fixed,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(401, Attribute::DOUBLE,	"purch_rate_curr_load", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_rate_curr_load,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(402, Attribute::DOUBLE,	"purch_rate_curr_pol_fee", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_rate_curr_pol_fee,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(403, Attribute::DOUBLE,	"purch_rate_curr_sprd", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_rate_curr_sprd,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(404, Attribute::DOUBLE,	"purch_rate_guar_fixed", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_rate_guar_fixed,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(405, Attribute::DOUBLE,	"quota_share_reinsured_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->quota_share_reinsured_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(406, Attribute::DOUBLE,	"rbc_c1_liab_only_stat_res_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c1_liab_only_stat_res_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(407, Attribute::DOUBLE,	"rbc_c2_mort_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c2_mort_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(408, Attribute::DOUBLE,	"rbc_c3_ann_high_risk_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c3_ann_high_risk_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(409, Attribute::DOUBLE,	"rbc_c3_ann_low_risk_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c3_ann_low_risk_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(410, Attribute::DOUBLE,	"rbc_c3_ann_medium_risk_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c3_ann_medium_risk_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(411, Attribute::INT,	"rbc_c3_ann_risk_defn", -1, (size_t)&modelOffset->rbc_c3_ann_risk_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(412, Attribute::DOUBLE,	"rbc_c4_prem_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->rbc_c4_prem_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(413, Attribute::STR_ENUM,	"reins_coverage_defn", -1, (size_t)&modelOffset->reins_coverage_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &reins_coverage_defnEnumList, Feature(true)),
	Descriptor(414, Attribute::STR_ENUM,	"reins_defn", -1, (size_t)&modelOffset->reins_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &reins_defnEnumList, Feature(true)),
	Descriptor(415, Attribute::DOUBLE,	"reins_exp_per_pol", Descriptor::NOT_INDEXED, (size_t)&modelOffset->reins_exp_per_pol,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(416, Attribute::DOUBLE,	"reins_gmwb_chg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->reins_gmwb_chg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(417, Attribute::DOUBLE,	"reins_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->reins_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(418, Attribute::DOUBLE,	"renewal_beta_down_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->renewal_beta_down_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(419, Attribute::DOUBLE,	"renewal_beta_up_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->renewal_beta_up_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(420, Attribute::INT,	"renewal_sc_yr_offest_crbg", -1, (size_t)&modelOffset->renewal_sc_yr_offest_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(421, Attribute::INT,	"rmd_age_crbg", -1, (size_t)&modelOffset->rmd_age_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(422, Attribute::STRING,	"seg_id", -1, (size_t)&modelOffset->seg_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(423, Attribute::STRING,	"sfas97rd_cohort_id_ceded", -1, (size_t)&modelOffset->sfas97rd_cohort_id_ceded,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(424, Attribute::STRING,	"sfas97rd_cohort_id_gross", -1, (size_t)&modelOffset->sfas97rd_cohort_id_gross,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(425, Attribute::DOUBLE,	"sfc_atan_alpha_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->sfc_atan_alpha_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(426, Attribute::DOUBLE,	"sfc_atan_beta_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->sfc_atan_beta_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(427, Attribute::DOUBLE,	"sfc_atan_gamma_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->sfc_atan_gamma_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(428, Attribute::DOUBLE,	"sfc_atan_mult_floor_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->sfc_atan_mult_floor_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(429, Attribute::INT,	"shock_skew_mth_crbg", -1, (size_t)&modelOffset->shock_skew_mth_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(430, Attribute::DOUBLE,	"shock_skew_pct_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->shock_skew_pct_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(431, Attribute::DOUBLE,	"single_prem", Descriptor::NOT_INDEXED, (size_t)&modelOffset->single_prem,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(432, Attribute::DOUBLE,	"spousal_cont_elect_rate_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->spousal_cont_elect_rate_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(433, Attribute::STR_ENUM,	"stat_carvm_calc_annuitzn_defn", -1, (size_t)&modelOffset->stat_carvm_calc_annuitzn_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &stat_carvm_calc_annuitzn_defnEnumList, Feature(true)),
	Descriptor(434, Attribute::STR_ENUM,	"stat_res_defn", -1, (size_t)&modelOffset->stat_res_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &stat_res_defnEnumList, Feature(true)),
	Descriptor(435, Attribute::STR_ENUM,	"stat_res_mva_defn", -1, (size_t)&modelOffset->stat_res_mva_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &stat_res_mva_defnEnumList, Feature(true)),
	Descriptor(436, Attribute::DOUBLE,	"stat_res_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->stat_res_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(437, Attribute::STRING,	"stat_valn_code", -1, (size_t)&modelOffset->stat_valn_code,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(438, Attribute::STR_ENUM,	"surr_chg_defn", -1, (size_t)&modelOffset->surr_chg_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &surr_chg_defnEnumList, Feature(true)),
	Descriptor(439, Attribute::DOUBLE,	"surr_chg_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->surr_chg_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(440, Attribute::DOUBLE,	"surr_chg_pct_renewal_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->surr_chg_pct_renewal_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(441, Attribute::INT,	"surr_chg_period_crbg", -1, (size_t)&modelOffset->surr_chg_period_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(442, Attribute::STR_ENUM,	"surr_chg_timing_defn", -1, (size_t)&modelOffset->surr_chg_timing_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &surr_chg_timing_defnEnumList, Feature(true)),
	Descriptor(443, Attribute::DOUBLE,	"tax_capzd_prem_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->tax_capzd_prem_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(444, Attribute::DOUBLE,	"tax_capzd_prem_pct_qualify", Descriptor::NOT_INDEXED, (size_t)&modelOffset->tax_capzd_prem_pct_qualify,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(445, Attribute::STR_ENUM,	"tax_carvm_calc_annuitzn_defn", -1, (size_t)&modelOffset->tax_carvm_calc_annuitzn_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &tax_carvm_calc_annuitzn_defnEnumList, Feature(true)),
	Descriptor(446, Attribute::STR_ENUM,	"tax_carvm_defn", -1, (size_t)&modelOffset->tax_carvm_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &tax_carvm_defnEnumList, Feature(true)),
	Descriptor(447, Attribute::STR_ENUM,	"tax_loss_treatment", -1, (size_t)&modelOffset->tax_loss_treatment,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &tax_loss_treatmentEnumList, Feature(true)),
	Descriptor(448, Attribute::DOUBLE,	"tax_rate", Descriptor::NOT_INDEXED, (size_t)&modelOffset->tax_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(449, Attribute::STR_ENUM,	"tax_res_defn", -1, (size_t)&modelOffset->tax_res_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &tax_res_defnEnumList, Feature(true)),
	Descriptor(450, Attribute::STR_ENUM,	"tax_res_mva_defn", -1, (size_t)&modelOffset->tax_res_mva_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &tax_res_mva_defnEnumList, Feature(true)),
	Descriptor(451, Attribute::DOUBLE,	"tax_res_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->tax_res_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(452, Attribute::DOUBLE,	"tax_res_pct_stat", Descriptor::NOT_INDEXED, (size_t)&modelOffset->tax_res_pct_stat,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(453, Attribute::STRING,	"tax_valn_code", -1, (size_t)&modelOffset->tax_valn_code,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(454, Attribute::DOUBLE,	"tgt_budget_alpha_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->tgt_budget_alpha_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(455, Attribute::DOUBLE,	"tgt_budget_reduction_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->tgt_budget_reduction_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(456, Attribute::STR_ENUM,	"tgt_cap_defn", -1, (size_t)&modelOffset->tgt_cap_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &tgt_cap_defnEnumList, Feature(true)),
	Descriptor(457, Attribute::DOUBLE,	"tgt_cap_rbc_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->tgt_cap_rbc_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(458, Attribute::STR_ENUM,	"use_mp", -1, (size_t)&modelOffset->use_mp,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &use_mpEnumList, Feature(true)),
	Descriptor(459, Attribute::STRING,	"valn_periods_selected", -1, (size_t)&modelOffset->valn_periods_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(460, Attribute::INT,	"valn_yrs", -1, (size_t)&modelOffset->valn_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(461, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(462, Attribute::SCALAR_INT,	"audit_detail_flag", -1, (size_t)&modelOffset->audit_detail_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_audit_detail_flag)),
	Descriptor(463, Attribute::SCALAR_INT,	"commencement_period", -1, (size_t)&modelOffset->commencement_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_commencement_period)),
	Descriptor(464, Attribute::SCALAR_STRING,	"data_file_name", -1, (size_t)&modelOffset->data_file_name,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&FIA_LIAB_UDF::fia_liab_data_file_name)),
	Descriptor(465, Attribute::SCALAR_INT,	"elapsed_mths", -1, (size_t)&modelOffset->elapsed_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_elapsed_mths)),
	Descriptor(466, Attribute::SCALAR_INT,	"final_period", -1, (size_t)&modelOffset->final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_final_period)),
	Descriptor(467, Attribute::SCALAR_INT,	"gmwb_flag", -1, (size_t)&modelOffset->gmwb_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_gmwb_flag)),
	Descriptor(468, Attribute::SCALAR_INT,	"gmwb_req_yrs_wait", -1, (size_t)&modelOffset->gmwb_req_yrs_wait,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_gmwb_req_yrs_wait)),
	Descriptor(469, Attribute::SCALAR_INT,	"infl_start_mth", -1, (size_t)&modelOffset->infl_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_infl_start_mth)),
	Descriptor(470, Attribute::SCALAR_INT,	"infl_start_period", -1, (size_t)&modelOffset->infl_start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_infl_start_period)),
	Descriptor(471, Attribute::SCALAR_INT,	"infl_start_yr", -1, (size_t)&modelOffset->infl_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_infl_start_yr)),
	Descriptor(472, Attribute::SCALAR_INT,	"issue_age", -1, (size_t)&modelOffset->issue_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_issue_age)),
	Descriptor(473, Attribute::SCALAR_INT,	"issue_date", -1, (size_t)&modelOffset->issue_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_issue_date)),
	Descriptor(474, Attribute::SCALAR_DOUBLE,	"issue_day", -1, (size_t)&modelOffset->issue_day,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&FIA_LIAB_UDF::fia_liab_issue_day)),
	Descriptor(475, Attribute::SCALAR_DOUBLE,	"issue_mth", -1, (size_t)&modelOffset->issue_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&FIA_LIAB_UDF::fia_liab_issue_mth)),
	Descriptor(476, Attribute::SCALAR_INT,	"issue_yr", -1, (size_t)&modelOffset->issue_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_issue_yr)),
	Descriptor(477, Attribute::SCALAR_DOUBLE,	"itm_period_disc_rate", -1, (size_t)&modelOffset->itm_period_disc_rate,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&FIA_LIAB_UDF::fia_liab_itm_period_disc_rate)),
	Descriptor(478, Attribute::SCALAR_INT,	"lapse_shock_year_crbg", -1, (size_t)&modelOffset->lapse_shock_year_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_lapse_shock_year_crbg)),
	Descriptor(479, Attribute::SCALAR_INT,	"lipm_ind_crbg", -1, (size_t)&modelOffset->lipm_ind_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_lipm_ind_crbg)),
	Descriptor(480, Attribute::SCALAR_INT,	"maturity_age", -1, (size_t)&modelOffset->maturity_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_maturity_age)),
	Descriptor(481, Attribute::SCALAR_INT,	"maturity_period", -1, (size_t)&modelOffset->maturity_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_maturity_period)),
	Descriptor(482, Attribute::SCALAR_INT,	"max_mva_sc_period_crbg", -1, (size_t)&modelOffset->max_mva_sc_period_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_max_mva_sc_period_crbg)),
	Descriptor(483, Attribute::SCALAR_DOUBLE,	"mort_impr_time_elapsed", -1, (size_t)&modelOffset->mort_impr_time_elapsed,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&FIA_LIAB_UDF::fia_liab_mort_impr_time_elapsed)),
	Descriptor(484, Attribute::SCALAR_DOUBLE,	"mva_comp_rate_issue", -1, (size_t)&modelOffset->mva_comp_rate_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((dF)&FIA_LIAB_UDF::fia_liab_mva_comp_rate_issue)),
	Descriptor(485, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&FIA_LIAB_UDF::fia_liab_proj_date_adj)),
	Descriptor(486, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_proj_start_date)),
	Descriptor(487, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_proj_start_mth)),
	Descriptor(488, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_proj_start_yr)),
	Descriptor(489, Attribute::SCALAR_INT,	"reins_flag", -1, (size_t)&modelOffset->reins_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_reins_flag)),
	Descriptor(490, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_start_period)),
	Descriptor(491, Attribute::SCALAR_STRING,	"state_of_world_financial_file_path", -1, (size_t)&modelOffset->state_of_world_financial_file_path,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&FIA_LIAB_UDF::fia_liab_state_of_world_financial_file_path)),
	Descriptor(492, Attribute::SCALAR_INT,	"tax_capzd_prem_amortzn_yrs", -1, (size_t)&modelOffset->tax_capzd_prem_amortzn_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_tax_capzd_prem_amortzn_yrs)),
	Descriptor(493, Attribute::SCALAR_INT,	"term_to_omega_age", -1, (size_t)&modelOffset->term_to_omega_age,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_term_to_omega_age)),
	Descriptor(494, Attribute::SCALAR_INT,	"term_to_omega_age_f_crbg", -1, (size_t)&modelOffset->term_to_omega_age_f_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_term_to_omega_age_f_crbg)),
	Descriptor(495, Attribute::SCALAR_INT,	"term_to_omega_age_m_crbg", -1, (size_t)&modelOffset->term_to_omega_age_m_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&FIA_LIAB_UDF::fia_liab_term_to_omega_age_m_crbg)),
	};

	Attribute::Descriptor* FIA_LIAB::descriptorTable[] = {
	&FIA_LIAB::descriptor_0[0],
	&FIA_LIAB::descriptor_0[1],
	&FIA_LIAB::descriptor_0[2],
	&FIA_LIAB::descriptor_0[3],
	&FIA_LIAB::descriptor_0[4],
	&FIA_LIAB::descriptor_0[5],
	&FIA_LIAB::descriptor_0[6],
	&FIA_LIAB::descriptor_0[7],
	&FIA_LIAB::descriptor_0[8],
	&FIA_LIAB::descriptor_0[9],
	&FIA_LIAB::descriptor_0[10],
	&FIA_LIAB::descriptor_0[11],
	&FIA_LIAB::descriptor_0[12],
	&FIA_LIAB::descriptor_0[13],
	&FIA_LIAB::descriptor_0[14],
	&FIA_LIAB::descriptor_0[15],
	&FIA_LIAB::descriptor_0[16],
	&FIA_LIAB::descriptor_0[17],
	&FIA_LIAB::descriptor_0[18],
	&FIA_LIAB::descriptor_0[19],
	&FIA_LIAB::descriptor_0[20],
	&FIA_LIAB::descriptor_0[21],
	&FIA_LIAB::descriptor_0[22],
	&FIA_LIAB::descriptor_0[23],
	&FIA_LIAB::descriptor_0[24],
	&FIA_LIAB::descriptor_0[25],
	&FIA_LIAB::descriptor_0[26],
	&FIA_LIAB::descriptor_0[27],
	&FIA_LIAB::descriptor_0[28],
	&FIA_LIAB::descriptor_0[29],
	&FIA_LIAB::descriptor_0[30],
	&FIA_LIAB::descriptor_0[31],
	&FIA_LIAB::descriptor_0[32],
	&FIA_LIAB::descriptor_0[33],
	&FIA_LIAB::descriptor_0[34],
	&FIA_LIAB::descriptor_0[35],
	&FIA_LIAB::descriptor_0[36],
	&FIA_LIAB::descriptor_0[37],
	&FIA_LIAB::descriptor_0[38],
	&FIA_LIAB::descriptor_0[39],
	&FIA_LIAB::descriptor_0[40],
	&FIA_LIAB::descriptor_0[41],
	&FIA_LIAB::descriptor_0[42],
	&FIA_LIAB::descriptor_0[43],
	&FIA_LIAB::descriptor_0[44],
	&FIA_LIAB::descriptor_0[45],
	&FIA_LIAB::descriptor_0[46],
	&FIA_LIAB::descriptor_0[47],
	&FIA_LIAB::descriptor_0[48],
	&FIA_LIAB::descriptor_0[49],
	&FIA_LIAB::descriptor_0[50],
	&FIA_LIAB::descriptor_0[51],
	&FIA_LIAB::descriptor_0[52],
	&FIA_LIAB::descriptor_0[53],
	&FIA_LIAB::descriptor_0[54],
	&FIA_LIAB::descriptor_0[55],
	&FIA_LIAB::descriptor_0[56],
	&FIA_LIAB::descriptor_0[57],
	&FIA_LIAB::descriptor_0[58],
	&FIA_LIAB::descriptor_0[59],
	&FIA_LIAB::descriptor_0[60],
	&FIA_LIAB::descriptor_0[61],
	&FIA_LIAB::descriptor_0[62],
	&FIA_LIAB::descriptor_0[63],
	&FIA_LIAB::descriptor_0[64],
	&FIA_LIAB::descriptor_0[65],
	&FIA_LIAB::descriptor_0[66],
	&FIA_LIAB::descriptor_0[67],
	&FIA_LIAB::descriptor_0[68],
	&FIA_LIAB::descriptor_0[69],
	&FIA_LIAB::descriptor_0[70],
	&FIA_LIAB::descriptor_0[71],
	&FIA_LIAB::descriptor_0[72],
	&FIA_LIAB::descriptor_0[73],
	&FIA_LIAB::descriptor_0[74],
	&FIA_LIAB::descriptor_0[75],
	&FIA_LIAB::descriptor_0[76],
	&FIA_LIAB::descriptor_0[77],
	&FIA_LIAB::descriptor_0[78],
	&FIA_LIAB::descriptor_0[79],
	&FIA_LIAB::descriptor_0[80],
	&FIA_LIAB::descriptor_0[81],
	&FIA_LIAB::descriptor_0[82],
	&FIA_LIAB::descriptor_0[83],
	&FIA_LIAB::descriptor_0[84],
	&FIA_LIAB::descriptor_0[85],
	&FIA_LIAB::descriptor_0[86],
	&FIA_LIAB::descriptor_0[87],
	&FIA_LIAB::descriptor_0[88],
	&FIA_LIAB::descriptor_0[89],
	&FIA_LIAB::descriptor_0[90],
	&FIA_LIAB::descriptor_0[91],
	&FIA_LIAB::descriptor_0[92],
	&FIA_LIAB::descriptor_0[93],
	&FIA_LIAB::descriptor_0[94],
	&FIA_LIAB::descriptor_0[95],
	&FIA_LIAB::descriptor_0[96],
	&FIA_LIAB::descriptor_0[97],
	&FIA_LIAB::descriptor_0[98],
	&FIA_LIAB::descriptor_0[99],
	&FIA_LIAB::descriptor_0[100],
	&FIA_LIAB::descriptor_0[101],
	&FIA_LIAB::descriptor_0[102],
	&FIA_LIAB::descriptor_0[103],
	&FIA_LIAB::descriptor_0[104],
	&FIA_LIAB::descriptor_0[105],
	&FIA_LIAB::descriptor_0[106],
	&FIA_LIAB::descriptor_0[107],
	&FIA_LIAB::descriptor_0[108],
	&FIA_LIAB::descriptor_0[109],
	&FIA_LIAB::descriptor_0[110],
	&FIA_LIAB::descriptor_0[111],
	&FIA_LIAB::descriptor_0[112],
	&FIA_LIAB::descriptor_0[113],
	&FIA_LIAB::descriptor_0[114],
	&FIA_LIAB::descriptor_0[115],
	&FIA_LIAB::descriptor_0[116],
	&FIA_LIAB::descriptor_0[117],
	&FIA_LIAB::descriptor_0[118],
	&FIA_LIAB::descriptor_0[119],
	&FIA_LIAB::descriptor_0[120],
	&FIA_LIAB::descriptor_0[121],
	&FIA_LIAB::descriptor_0[122],
	&FIA_LIAB::descriptor_0[123],
	&FIA_LIAB::descriptor_0[124],
	&FIA_LIAB::descriptor_0[125],
	&FIA_LIAB::descriptor_0[126],
	&FIA_LIAB::descriptor_0[127],
	&FIA_LIAB::descriptor_0[128],
	&FIA_LIAB::descriptor_0[129],
	&FIA_LIAB::descriptor_0[130],
	&FIA_LIAB::descriptor_0[131],
	&FIA_LIAB::descriptor_0[132],
	&FIA_LIAB::descriptor_0[133],
	&FIA_LIAB::descriptor_0[134],
	&FIA_LIAB::descriptor_0[135],
	&FIA_LIAB::descriptor_0[136],
	&FIA_LIAB::descriptor_0[137],
	&FIA_LIAB::descriptor_0[138],
	&FIA_LIAB::descriptor_0[139],
	&FIA_LIAB::descriptor_0[140],
	&FIA_LIAB::descriptor_0[141],
	&FIA_LIAB::descriptor_0[142],
	&FIA_LIAB::descriptor_0[143],
	&FIA_LIAB::descriptor_0[144],
	&FIA_LIAB::descriptor_0[145],
	&FIA_LIAB::descriptor_0[146],
	&FIA_LIAB::descriptor_0[147],
	&FIA_LIAB::descriptor_0[148],
	&FIA_LIAB::descriptor_0[149],
	&FIA_LIAB::descriptor_0[150],
	&FIA_LIAB::descriptor_0[151],
	&FIA_LIAB::descriptor_0[152],
	&FIA_LIAB::descriptor_0[153],
	&FIA_LIAB::descriptor_0[154],
	&FIA_LIAB::descriptor_0[155],
	&FIA_LIAB::descriptor_0[156],
	&FIA_LIAB::descriptor_0[157],
	&FIA_LIAB::descriptor_0[158],
	&FIA_LIAB::descriptor_0[159],
	&FIA_LIAB::descriptor_0[160],
	&FIA_LIAB::descriptor_0[161],
	&FIA_LIAB::descriptor_0[162],
	&FIA_LIAB::descriptor_0[163],
	&FIA_LIAB::descriptor_0[164],
	&FIA_LIAB::descriptor_0[165],
	&FIA_LIAB::descriptor_0[166],
	&FIA_LIAB::descriptor_0[167],
	&FIA_LIAB::descriptor_0[168],
	&FIA_LIAB::descriptor_0[169],
	&FIA_LIAB::descriptor_0[170],
	&FIA_LIAB::descriptor_0[171],
	&FIA_LIAB::descriptor_0[172],
	&FIA_LIAB::descriptor_0[173],
	&FIA_LIAB::descriptor_0[174],
	&FIA_LIAB::descriptor_0[175],
	&FIA_LIAB::descriptor_0[176],
	&FIA_LIAB::descriptor_0[177],
	&FIA_LIAB::descriptor_0[178],
	&FIA_LIAB::descriptor_0[179],
	&FIA_LIAB::descriptor_0[180],
	&FIA_LIAB::descriptor_0[181],
	&FIA_LIAB::descriptor_0[182],
	&FIA_LIAB::descriptor_0[183],
	&FIA_LIAB::descriptor_0[184],
	&FIA_LIAB::descriptor_0[185],
	&FIA_LIAB::descriptor_0[186],
	&FIA_LIAB::descriptor_0[187],
	&FIA_LIAB::descriptor_0[188],
	&FIA_LIAB::descriptor_0[189],
	&FIA_LIAB::descriptor_0[190],
	&FIA_LIAB::descriptor_0[191],
	&FIA_LIAB::descriptor_0[192],
	&FIA_LIAB::descriptor_0[193],
	&FIA_LIAB::descriptor_0[194],
	&FIA_LIAB::descriptor_0[195],
	&FIA_LIAB::descriptor_0[196],
	&FIA_LIAB::descriptor_0[197],
	&FIA_LIAB::descriptor_0[198],
	&FIA_LIAB::descriptor_0[199],
	&FIA_LIAB::descriptor_0[200],
	&FIA_LIAB::descriptor_0[201],
	&FIA_LIAB::descriptor_0[202],
	&FIA_LIAB::descriptor_0[203],
	&FIA_LIAB::descriptor_0[204],
	&FIA_LIAB::descriptor_0[205],
	&FIA_LIAB::descriptor_0[206],
	&FIA_LIAB::descriptor_0[207],
	&FIA_LIAB::descriptor_0[208],
	&FIA_LIAB::descriptor_0[209],
	&FIA_LIAB::descriptor_0[210],
	&FIA_LIAB::descriptor_0[211],
	&FIA_LIAB::descriptor_0[212],
	&FIA_LIAB::descriptor_0[213],
	&FIA_LIAB::descriptor_0[214],
	&FIA_LIAB::descriptor_0[215],
	&FIA_LIAB::descriptor_0[216],
	&FIA_LIAB::descriptor_0[217],
	&FIA_LIAB::descriptor_0[218],
	&FIA_LIAB::descriptor_0[219],
	&FIA_LIAB::descriptor_0[220],
	&FIA_LIAB::descriptor_0[221],
	&FIA_LIAB::descriptor_0[222],
	&FIA_LIAB::descriptor_0[223],
	&FIA_LIAB::descriptor_0[224],
	&FIA_LIAB::descriptor_0[225],
	&FIA_LIAB::descriptor_0[226],
	&FIA_LIAB::descriptor_0[227],
	&FIA_LIAB::descriptor_0[228],
	&FIA_LIAB::descriptor_0[229],
	&FIA_LIAB::descriptor_0[230],
	&FIA_LIAB::descriptor_0[231],
	&FIA_LIAB::descriptor_0[232],
	&FIA_LIAB::descriptor_0[233],
	&FIA_LIAB::descriptor_0[234],
	&FIA_LIAB::descriptor_0[235],
	&FIA_LIAB::descriptor_0[236],
	&FIA_LIAB::descriptor_0[237],
	&FIA_LIAB::descriptor_0[238],
	&FIA_LIAB::descriptor_0[239],
	&FIA_LIAB::descriptor_0[240],
	&FIA_LIAB::descriptor_0[241],
	&FIA_LIAB::descriptor_0[242],
	&FIA_LIAB::descriptor_0[243],
	&FIA_LIAB::descriptor_0[244],
	&FIA_LIAB::descriptor_0[245],
	&FIA_LIAB::descriptor_0[246],
	&FIA_LIAB::descriptor_0[247],
	&FIA_LIAB::descriptor_0[248],
	&FIA_LIAB::descriptor_0[249],
	&FIA_LIAB::descriptor_0[250],
	&FIA_LIAB::descriptor_0[251],
	&FIA_LIAB::descriptor_0[252],
	&FIA_LIAB::descriptor_0[253],
	&FIA_LIAB::descriptor_0[254],
	&FIA_LIAB::descriptor_0[255],
	&FIA_LIAB::descriptor_256[0],
	&FIA_LIAB::descriptor_256[1],
	&FIA_LIAB::descriptor_256[2],
	&FIA_LIAB::descriptor_256[3],
	&FIA_LIAB::descriptor_256[4],
	&FIA_LIAB::descriptor_256[5],
	&FIA_LIAB::descriptor_256[6],
	&FIA_LIAB::descriptor_256[7],
	&FIA_LIAB::descriptor_256[8],
	&FIA_LIAB::descriptor_256[9],
	&FIA_LIAB::descriptor_256[10],
	&FIA_LIAB::descriptor_256[11],
	&FIA_LIAB::descriptor_256[12],
	&FIA_LIAB::descriptor_256[13],
	&FIA_LIAB::descriptor_256[14],
	&FIA_LIAB::descriptor_256[15],
	&FIA_LIAB::descriptor_256[16],
	&FIA_LIAB::descriptor_256[17],
	&FIA_LIAB::descriptor_256[18],
	&FIA_LIAB::descriptor_256[19],
	&FIA_LIAB::descriptor_256[20],
	&FIA_LIAB::descriptor_256[21],
	&FIA_LIAB::descriptor_256[22],
	&FIA_LIAB::descriptor_256[23],
	&FIA_LIAB::descriptor_256[24],
	&FIA_LIAB::descriptor_256[25],
	&FIA_LIAB::descriptor_256[26],
	&FIA_LIAB::descriptor_256[27],
	&FIA_LIAB::descriptor_256[28],
	&FIA_LIAB::descriptor_256[29],
	&FIA_LIAB::descriptor_256[30],
	&FIA_LIAB::descriptor_256[31],
	&FIA_LIAB::descriptor_256[32],
	&FIA_LIAB::descriptor_256[33],
	&FIA_LIAB::descriptor_256[34],
	&FIA_LIAB::descriptor_256[35],
	&FIA_LIAB::descriptor_256[36],
	&FIA_LIAB::descriptor_256[37],
	&FIA_LIAB::descriptor_256[38],
	&FIA_LIAB::descriptor_256[39],
	&FIA_LIAB::descriptor_256[40],
	&FIA_LIAB::descriptor_256[41],
	&FIA_LIAB::descriptor_256[42],
	&FIA_LIAB::descriptor_256[43],
	&FIA_LIAB::descriptor_256[44],
	&FIA_LIAB::descriptor_256[45],
	&FIA_LIAB::descriptor_256[46],
	&FIA_LIAB::descriptor_256[47],
	&FIA_LIAB::descriptor_256[48],
	&FIA_LIAB::descriptor_256[49],
	&FIA_LIAB::descriptor_256[50],
	&FIA_LIAB::descriptor_256[51],
	&FIA_LIAB::descriptor_256[52],
	&FIA_LIAB::descriptor_256[53],
	&FIA_LIAB::descriptor_256[54],
	&FIA_LIAB::descriptor_256[55],
	&FIA_LIAB::descriptor_256[56],
	&FIA_LIAB::descriptor_256[57],
	&FIA_LIAB::descriptor_256[58],
	&FIA_LIAB::descriptor_256[59],
	&FIA_LIAB::descriptor_256[60],
	&FIA_LIAB::descriptor_256[61],
	&FIA_LIAB::descriptor_256[62],
	&FIA_LIAB::descriptor_256[63],
	&FIA_LIAB::descriptor_256[64],
	&FIA_LIAB::descriptor_256[65],
	&FIA_LIAB::descriptor_256[66],
	&FIA_LIAB::descriptor_256[67],
	&FIA_LIAB::descriptor_256[68],
	&FIA_LIAB::descriptor_256[69],
	&FIA_LIAB::descriptor_256[70],
	&FIA_LIAB::descriptor_256[71],
	&FIA_LIAB::descriptor_256[72],
	&FIA_LIAB::descriptor_256[73],
	&FIA_LIAB::descriptor_256[74],
	&FIA_LIAB::descriptor_256[75],
	&FIA_LIAB::descriptor_256[76],
	&FIA_LIAB::descriptor_256[77],
	&FIA_LIAB::descriptor_256[78],
	&FIA_LIAB::descriptor_256[79],
	&FIA_LIAB::descriptor_256[80],
	&FIA_LIAB::descriptor_256[81],
	&FIA_LIAB::descriptor_256[82],
	&FIA_LIAB::descriptor_256[83],
	&FIA_LIAB::descriptor_256[84],
	&FIA_LIAB::descriptor_256[85],
	&FIA_LIAB::descriptor_256[86],
	&FIA_LIAB::descriptor_256[87],
	&FIA_LIAB::descriptor_256[88],
	&FIA_LIAB::descriptor_256[89],
	&FIA_LIAB::descriptor_256[90],
	&FIA_LIAB::descriptor_256[91],
	&FIA_LIAB::descriptor_256[92],
	&FIA_LIAB::descriptor_256[93],
	&FIA_LIAB::descriptor_256[94],
	&FIA_LIAB::descriptor_256[95],
	&FIA_LIAB::descriptor_256[96],
	&FIA_LIAB::descriptor_256[97],
	&FIA_LIAB::descriptor_256[98],
	&FIA_LIAB::descriptor_256[99],
	&FIA_LIAB::descriptor_256[100],
	&FIA_LIAB::descriptor_256[101],
	&FIA_LIAB::descriptor_256[102],
	&FIA_LIAB::descriptor_256[103],
	&FIA_LIAB::descriptor_256[104],
	&FIA_LIAB::descriptor_256[105],
	&FIA_LIAB::descriptor_256[106],
	&FIA_LIAB::descriptor_256[107],
	&FIA_LIAB::descriptor_256[108],
	&FIA_LIAB::descriptor_256[109],
	&FIA_LIAB::descriptor_256[110],
	&FIA_LIAB::descriptor_256[111],
	&FIA_LIAB::descriptor_256[112],
	&FIA_LIAB::descriptor_256[113],
	&FIA_LIAB::descriptor_256[114],
	&FIA_LIAB::descriptor_256[115],
	&FIA_LIAB::descriptor_256[116],
	&FIA_LIAB::descriptor_256[117],
	&FIA_LIAB::descriptor_256[118],
	&FIA_LIAB::descriptor_256[119],
	&FIA_LIAB::descriptor_256[120],
	&FIA_LIAB::descriptor_256[121],
	&FIA_LIAB::descriptor_256[122],
	&FIA_LIAB::descriptor_256[123],
	&FIA_LIAB::descriptor_256[124],
	&FIA_LIAB::descriptor_256[125],
	&FIA_LIAB::descriptor_256[126],
	&FIA_LIAB::descriptor_256[127],
	&FIA_LIAB::descriptor_256[128],
	&FIA_LIAB::descriptor_256[129],
	&FIA_LIAB::descriptor_256[130],
	&FIA_LIAB::descriptor_256[131],
	&FIA_LIAB::descriptor_256[132],
	&FIA_LIAB::descriptor_256[133],
	&FIA_LIAB::descriptor_256[134],
	&FIA_LIAB::descriptor_256[135],
	&FIA_LIAB::descriptor_256[136],
	&FIA_LIAB::descriptor_256[137],
	&FIA_LIAB::descriptor_256[138],
	&FIA_LIAB::descriptor_256[139],
	&FIA_LIAB::descriptor_256[140],
	&FIA_LIAB::descriptor_256[141],
	&FIA_LIAB::descriptor_256[142],
	&FIA_LIAB::descriptor_256[143],
	&FIA_LIAB::descriptor_256[144],
	&FIA_LIAB::descriptor_256[145],
	&FIA_LIAB::descriptor_256[146],
	&FIA_LIAB::descriptor_256[147],
	&FIA_LIAB::descriptor_256[148],
	&FIA_LIAB::descriptor_256[149],
	&FIA_LIAB::descriptor_256[150],
	&FIA_LIAB::descriptor_256[151],
	&FIA_LIAB::descriptor_256[152],
	&FIA_LIAB::descriptor_256[153],
	&FIA_LIAB::descriptor_256[154],
	&FIA_LIAB::descriptor_256[155],
	&FIA_LIAB::descriptor_256[156],
	&FIA_LIAB::descriptor_256[157],
	&FIA_LIAB::descriptor_256[158],
	&FIA_LIAB::descriptor_256[159],
	&FIA_LIAB::descriptor_256[160],
	&FIA_LIAB::descriptor_256[161],
	&FIA_LIAB::descriptor_256[162],
	&FIA_LIAB::descriptor_256[163],
	&FIA_LIAB::descriptor_256[164],
	&FIA_LIAB::descriptor_256[165],
	&FIA_LIAB::descriptor_256[166],
	&FIA_LIAB::descriptor_256[167],
	&FIA_LIAB::descriptor_256[168],
	&FIA_LIAB::descriptor_256[169],
	&FIA_LIAB::descriptor_256[170],
	&FIA_LIAB::descriptor_256[171],
	&FIA_LIAB::descriptor_256[172],
	&FIA_LIAB::descriptor_256[173],
	&FIA_LIAB::descriptor_256[174],
	&FIA_LIAB::descriptor_256[175],
	&FIA_LIAB::descriptor_256[176],
	&FIA_LIAB::descriptor_256[177],
	&FIA_LIAB::descriptor_256[178],
	&FIA_LIAB::descriptor_256[179],
	&FIA_LIAB::descriptor_256[180],
	&FIA_LIAB::descriptor_256[181],
	&FIA_LIAB::descriptor_256[182],
	&FIA_LIAB::descriptor_256[183],
	&FIA_LIAB::descriptor_256[184],
	&FIA_LIAB::descriptor_256[185],
	&FIA_LIAB::descriptor_256[186],
	&FIA_LIAB::descriptor_256[187],
	&FIA_LIAB::descriptor_256[188],
	&FIA_LIAB::descriptor_256[189],
	&FIA_LIAB::descriptor_256[190],
	&FIA_LIAB::descriptor_256[191],
	&FIA_LIAB::descriptor_256[192],
	&FIA_LIAB::descriptor_256[193],
	&FIA_LIAB::descriptor_256[194],
	&FIA_LIAB::descriptor_256[195],
	&FIA_LIAB::descriptor_256[196],
	&FIA_LIAB::descriptor_256[197],
	&FIA_LIAB::descriptor_256[198],
	&FIA_LIAB::descriptor_256[199],
	&FIA_LIAB::descriptor_256[200],
	&FIA_LIAB::descriptor_256[201],
	&FIA_LIAB::descriptor_256[202],
	&FIA_LIAB::descriptor_256[203],
	&FIA_LIAB::descriptor_256[204],
	&FIA_LIAB::descriptor_256[205],
	&FIA_LIAB::descriptor_256[206],
	&FIA_LIAB::descriptor_256[207],
	&FIA_LIAB::descriptor_256[208],
	&FIA_LIAB::descriptor_256[209],
	&FIA_LIAB::descriptor_256[210],
	&FIA_LIAB::descriptor_256[211],
	&FIA_LIAB::descriptor_256[212],
	&FIA_LIAB::descriptor_256[213],
	&FIA_LIAB::descriptor_256[214],
	&FIA_LIAB::descriptor_256[215],
	&FIA_LIAB::descriptor_256[216],
	&FIA_LIAB::descriptor_256[217],
	&FIA_LIAB::descriptor_256[218],
	&FIA_LIAB::descriptor_256[219],
	&FIA_LIAB::descriptor_256[220],
	&FIA_LIAB::descriptor_256[221],
	&FIA_LIAB::descriptor_256[222],
	&FIA_LIAB::descriptor_256[223],
	&FIA_LIAB::descriptor_256[224],
	&FIA_LIAB::descriptor_256[225],
	&FIA_LIAB::descriptor_256[226],
	&FIA_LIAB::descriptor_256[227],
	&FIA_LIAB::descriptor_256[228],
	&FIA_LIAB::descriptor_256[229],
	&FIA_LIAB::descriptor_256[230],
	&FIA_LIAB::descriptor_256[231],
	&FIA_LIAB::descriptor_256[232],
	&FIA_LIAB::descriptor_256[233],
	&FIA_LIAB::descriptor_256[234],
	&FIA_LIAB::descriptor_256[235],
	&FIA_LIAB::descriptor_256[236],
	&FIA_LIAB::descriptor_256[237],
	&FIA_LIAB::descriptor_256[238],
	&FIA_LIAB::descriptor_256[239],
	nullptr};
	const size_t FIA_LIAB::sDescriptorCount = 496;

//factory
FIA_LIAB* FIA_LIAB::makeThis(int isSubmodel, ModelClass* owner, FIA_LIAB* peer, 
						int mainRebase, const xstring &name, FIA_LIAB_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("FIA_LIAB::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor FIA_LIAB");
#endif
	FIA_LIAB* newP = (FIA_LIAB*)new FIA_LIAB_UDF
   	  ("fia_liab", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
	newP->sm_fia_mrb.setPersistentObject(MRB_GAAP_persistent_object::makeThis(1, newP, (MRB_GAAP*)(peer?peer->sm_fia_mrb.getPersistentObject():0), mainRebase, name + "|fia_mrb", arrayTemplate?arrayTemplate->sm_fia_mrb.getPersistentObject():0, false));

	newP->sm_fia_account.setPersistentObject(FIAAFUND_LIAB_persistent_object::makeThis(1, newP, (FIAAFUND_LIAB*)(peer?peer->sm_fia_account.getPersistentObject():0), mainRebase, name + "|fia_account", arrayTemplate?arrayTemplate->sm_fia_account.getPersistentObject():0, false));

	newP->sm_carvm_stat.setPersistentObject(FIACARVM_LIAB_persistent_object::makeThis(1, newP, (FIACARVM_LIAB*)(peer?peer->sm_carvm_stat.getPersistentObject():0), mainRebase, name + "|carvm_stat", arrayTemplate?arrayTemplate->sm_carvm_stat.getPersistentObject():0, false));

	newP->sm_carvm_tax.setPersistentObject(FIACARVM_LIAB_persistent_object::makeThis(1, newP, (FIACARVM_LIAB*)(peer?peer->sm_carvm_tax.getPersistentObject():0), mainRebase, name + "|carvm_tax", arrayTemplate?arrayTemplate->sm_carvm_tax.getPersistentObject():0, false));

	newP->sm_fia_ann_pba.setPersistentObject(ANN_PBA_PBA_persistent_object::makeThis(1, newP, (ANN_PBA_PBA*)(peer?peer->sm_fia_ann_pba.getPersistentObject():0), mainRebase, name + "|fia_ann_pba", arrayTemplate?arrayTemplate->sm_fia_ann_pba.getPersistentObject():0, false));

	newP->sm_fia_sfas97rd.setPersistentObject(SFAS97RD_GAAP_persistent_object::makeThis(1, newP, (SFAS97RD_GAAP*)(peer?peer->sm_fia_sfas97rd.getPersistentObject():0), mainRebase, name + "|fia_sfas97rd", arrayTemplate?arrayTemplate->sm_fia_sfas97rd.getPersistentObject():0, false));

	if (find(unusedModels.begin(), unusedModels.end(), name + "|fia_rates") == unusedModels.end()) {
	newP->sm_fia_rates = RATES_ECONOMY::makeThis(1, newP, peer?peer->sm_fia_rates:0, mainRebase, name + "|fia_rates", (RATES_ECONOMY_persistent_object*)(arrayTemplate?arrayTemplate->sm_fia_rates:0));
	newP->adopt(newP->sm_fia_rates);
	}


	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	return newP;
}

//factory
FIA_LIAB_persistent_object* FIA_LIAB_persistent_object::makeThis(int isSubmodel, ModelClass* owner, FIA_LIAB* peer, 
							int mainRebase, const xstring &name, FIA_LIAB_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("FIA_LIAB_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor FIA_LIAB_persistent_object");
#endif
	FIA_LIAB_persistent_object* newP = (FIA_LIAB_persistent_object*)new FIA_LIAB_persistent_object
   	  ("fia_liab", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			FIA_LIAB_persistent_object* pd = dynamic_cast<FIA_LIAB_persistent_object*>(product);
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
	newP->sm_fia_mrb.setPersistentObject(MRB_GAAP_persistent_object::makeThis(1, newP, (MRB_GAAP*)(peer?peer->sm_fia_mrb.getPersistentObject():0), mainRebase, name + "|fia_mrb", arrayTemplate?arrayTemplate->sm_fia_mrb.getPersistentObject():0, false));

	newP->sm_fia_account.setPersistentObject(FIAAFUND_LIAB_persistent_object::makeThis(1, newP, (FIAAFUND_LIAB*)(peer?peer->sm_fia_account.getPersistentObject():0), mainRebase, name + "|fia_account", arrayTemplate?arrayTemplate->sm_fia_account.getPersistentObject():0, false));

	newP->sm_carvm_stat.setPersistentObject(FIACARVM_LIAB_persistent_object::makeThis(1, newP, (FIACARVM_LIAB*)(peer?peer->sm_carvm_stat.getPersistentObject():0), mainRebase, name + "|carvm_stat", arrayTemplate?arrayTemplate->sm_carvm_stat.getPersistentObject():0, false));

	newP->sm_carvm_tax.setPersistentObject(FIACARVM_LIAB_persistent_object::makeThis(1, newP, (FIACARVM_LIAB*)(peer?peer->sm_carvm_tax.getPersistentObject():0), mainRebase, name + "|carvm_tax", arrayTemplate?arrayTemplate->sm_carvm_tax.getPersistentObject():0, false));

	newP->sm_fia_ann_pba.setPersistentObject(ANN_PBA_PBA_persistent_object::makeThis(1, newP, (ANN_PBA_PBA*)(peer?peer->sm_fia_ann_pba.getPersistentObject():0), mainRebase, name + "|fia_ann_pba", arrayTemplate?arrayTemplate->sm_fia_ann_pba.getPersistentObject():0, false));

	newP->sm_fia_sfas97rd.setPersistentObject(SFAS97RD_GAAP_persistent_object::makeThis(1, newP, (SFAS97RD_GAAP*)(peer?peer->sm_fia_sfas97rd.getPersistentObject():0), mainRebase, name + "|fia_sfas97rd", arrayTemplate?arrayTemplate->sm_fia_sfas97rd.getPersistentObject():0, false));

	if (find(unusedModels.begin(), unusedModels.end(), name + "|fia_rates") == unusedModels.end()) {
	newP->sm_fia_rates = (RATES_ECONOMY*)RATES_ECONOMY_persistent_object::makeThis(1, newP, peer?peer->sm_fia_rates:0, mainRebase, name + "|fia_rates", (RATES_ECONOMY_persistent_object*)(arrayTemplate?arrayTemplate->sm_fia_rates:0), fixedArray);
	newP->adopt(newP->sm_fia_rates);
	}

	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	newP->msnumelement.setValue(0);
	return newP;
}

typedef double (FIA_LIAB_UDF::*dPF) ();
typedef double (FIA_LIAB_UDF::*dPFd) (double);
typedef int (FIA_LIAB_UDF::*iPF) ();
typedef int (FIA_LIAB_UDF::*iPFi) (int);
typedef xstring (FIA_LIAB_UDF::*sPF) ();
typedef xstring (FIA_LIAB_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
FIA_LIAB::FIA_LIAB(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
	, tax_capzd_prem_amortzn_sched(this, ptr_tt_tax_capzd_prem_amortzn_sched)

  , sm_carvm_stat(0, 0, 0)
  , sm_carvm_tax(0, 0, 0)
  , sm_fia_account(0, 0, 0)
  , sm_fia_ann_pba(0, 0, 0)
  , sm_fia_mrb(0, 0, 0)
  , sm_fia_rates(0)
  , sm_fia_sfas97rd(0, 0, 0)
	, adco(company_asset_adco)
	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_ann_pba(company_liab_fia_fia_ann_pba)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_mrb(company_liab_fia_fia_mrb)
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
	typedef double (FIA_LIAB_UDF::*dPXi2) (int, int);
	dPXi2 temp2;
#ifdef USEMEMCOUNT
	gMem.setNewKey("FIA_LIAB TTHC");
#endif
	temp2 = &FIA_LIAB_UDF::fia_liab_tax_capzd_prem_amortzn_sched;
   if (TTHC.dictionary.size() <= 1 || TTHC.dictionary[1] == 0)
		TTHC.add(1, new TempTableHolder(50, 1, 1,"tax_capzd_prem_amortzn_sched","fia_liab_tax_capzd_prem_amortzn_sched",(dPFi2)temp2,1));  
	MT->add(1, 0);
#ifdef USEMEMCOUNT
	gMem.clearKey();
#endif

}

//constructor begincolumn
FIA_LIAB::FIA_LIAB(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(473, FIA_LIAB::descriptorTable, arrayPersistentObj), Variable(*this)
	, tax_capzd_prem_amortzn_sched(this, ptr_tt_tax_capzd_prem_amortzn_sched)

  , sm_carvm_stat(0, 0, 0)
  , sm_carvm_tax(0, 0, 0)
  , sm_fia_account(0, 0, 0)
  , sm_fia_ann_pba(0, 0, 0)
  , sm_fia_mrb(0, 0, 0)
  , sm_fia_rates(0)
  , sm_fia_sfas97rd(0, 0, 0)
	, adco(company_asset_adco)
	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_ann_pba(company_liab_fia_fia_ann_pba)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_mrb(company_liab_fia_fia_mrb)
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

		adopt(&sm_carvm_stat);
		adopt(&sm_carvm_tax);
		adopt(&sm_fia_account);
		adopt(&sm_fia_ann_pba);
		adopt(&sm_fia_mrb);
		adopt(&sm_fia_sfas97rd);

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
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
       company_liab_fia_carvm_stat = 0;
#endif
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
       company_liab_fia_carvm_tax = 0;
#endif
#ifdef __CREATE_FIAAFUND_LIAB_CLASS_
       company_liab_fia_fia_account = 0;
#endif
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
       company_liab_fia_fia_ann_pba = 0;
#endif
#ifdef __CREATE_MRB_GAAP_CLASS_
       company_liab_fia_fia_mrb = 0;
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
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
       company_seg_ann_pba = 0;
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

	for (int cf_no = 1; cf_no <= 473; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (FIA_LIAB_UDF::*dPXi2) (int, int);
	dPXi2 temp2;
#ifdef USEMEMCOUNT
	gMem.setNewKey("FIA_LIAB TTHC");
#endif
	temp2 = &FIA_LIAB_UDF::fia_liab_tax_capzd_prem_amortzn_sched;
   if (TTHC.dictionary.size() <= 1 || TTHC.dictionary[1] == 0)
		TTHC.add(1, new TempTableHolder(50, 1, 1,"tax_capzd_prem_amortzn_sched","fia_liab_tax_capzd_prem_amortzn_sched",(dPFi2)temp2,1));  
	MT->add(1, 0);
#ifdef USEMEMCOUNT
	gMem.clearKey();
#endif

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


 void FIA_LIAB::copy_names() {

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
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
		company_liab_fia_carvm_stat = (FIACARVM_LIAB*)(findUnique("company|liab|fia|carvm_stat"));
#endif
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
		company_liab_fia_carvm_tax = (FIACARVM_LIAB*)(findUnique("company|liab|fia|carvm_tax"));
#endif
#ifdef __CREATE_FIAAFUND_LIAB_CLASS_
		company_liab_fia_fia_account = (FIAAFUND_LIAB*)(findUnique("company|liab|fia|fia_account"));
#endif
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
		company_liab_fia_fia_ann_pba = (ANN_PBA_PBA*)(findUnique("company|liab|fia|fia_ann_pba"));
#endif
#ifdef __CREATE_MRB_GAAP_CLASS_
		company_liab_fia_fia_mrb = (MRB_GAAP*)(findUnique("company|liab|fia|fia_mrb"));
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
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
		company_seg_ann_pba = (ANN_PBA_PBA*)(findUnique("company|seg|ann_pba"));
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
		company_seg_sfas97rd = (SFAS97RD_GAAP*)(findUnique("company|seg|sfas97rd"));
#endif
 }
//copy_names END@2


 void FIA_LIAB::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int FIA_LIAB_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& FIA_LIAB_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double FIA_LIAB_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int FIA_LIAB_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double FIA_LIAB_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double FIA_LIAB_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void FIA_LIAB_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void FIA_LIAB_persistent_object::write(long include_submodels) {
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

	void FIA_LIAB_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void FIA_LIAB_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void FIA_LIAB_persistent_object::write(const xstring& key, long include_submodels) {
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




	FIA_LIAB_persistent_object::~FIA_LIAB_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool FIA_LIAB_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void FIA_LIAB_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void FIA_LIAB_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void FIA_LIAB_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void FIA_LIAB_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void FIA_LIAB_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* FIA_LIAB_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* FIA_LIAB_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* FIA_LIAB_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char FIA_LIAB_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void FIA_LIAB_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
FIA_LIAB_persistent_object::FIA_LIAB_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			FIA_LIAB(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)

	, sm_carvm_stat(FIA_LIAB::sm_carvm_stat)
	, sm_carvm_tax(FIA_LIAB::sm_carvm_tax)
	, sm_fia_account(FIA_LIAB::sm_fia_account)
	, sm_fia_ann_pba(FIA_LIAB::sm_fia_ann_pba)
	, sm_fia_mrb(FIA_LIAB::sm_fia_mrb)
	, sm_fia_rates(FIA_LIAB::sm_fia_rates)
	, sm_fia_sfas97rd(FIA_LIAB::sm_fia_sfas97rd)
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
FIA_LIAB::~FIA_LIAB() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
//	ModelClass* carvm_stat_persObj = sm_carvm_stat.getPersistentObject();
//	doAdopt(carvm_stat_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_carvm_stat.IsValidSubModelOfBaseModelClass()){
		sm_carvm_stat.resize(0);
		delete sm_carvm_stat.getPersistentObject();
		sm_carvm_stat.mPersistentObj = 0;
	}

//	ModelClass* carvm_tax_persObj = sm_carvm_tax.getPersistentObject();
//	doAdopt(carvm_tax_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_carvm_tax.IsValidSubModelOfBaseModelClass()){
		sm_carvm_tax.resize(0);
		delete sm_carvm_tax.getPersistentObject();
		sm_carvm_tax.mPersistentObj = 0;
	}

//	ModelClass* fia_account_persObj = sm_fia_account.getPersistentObject();
//	doAdopt(fia_account_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_fia_account.IsValidSubModelOfBaseModelClass()){
		sm_fia_account.resize(0);
		delete sm_fia_account.getPersistentObject();
		sm_fia_account.mPersistentObj = 0;
	}

//	ModelClass* fia_ann_pba_persObj = sm_fia_ann_pba.getPersistentObject();
//	doAdopt(fia_ann_pba_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_fia_ann_pba.IsValidSubModelOfBaseModelClass()){
		sm_fia_ann_pba.resize(0);
		delete sm_fia_ann_pba.getPersistentObject();
		sm_fia_ann_pba.mPersistentObj = 0;
	}

//	ModelClass* fia_mrb_persObj = sm_fia_mrb.getPersistentObject();
//	doAdopt(fia_mrb_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_fia_mrb.IsValidSubModelOfBaseModelClass()){
		sm_fia_mrb.resize(0);
		delete sm_fia_mrb.getPersistentObject();
		sm_fia_mrb.mPersistentObj = 0;
	}

//	ModelClass* fia_sfas97rd_persObj = sm_fia_sfas97rd.getPersistentObject();
//	doAdopt(fia_sfas97rd_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_fia_sfas97rd.IsValidSubModelOfBaseModelClass()){
		sm_fia_sfas97rd.resize(0);
		delete sm_fia_sfas97rd.getPersistentObject();
		sm_fia_sfas97rd.mPersistentObj = 0;
	}

}
//destructor END@2
void FIA_LIAB::findTargetColumns() {

}
//findTargetColumns END@2
void FIA_LIAB::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void FIA_LIAB::temporary_tables() { 
	char buf[20];
	//Table tax_capzd_prem_amortzn_sched reset criteria
	tempTableKey= "(";
	tempTableKey=tempTableKey+")";
	findTempTable(1);
 	ptr_tt_tax_capzd_prem_amortzn_sched = MT->dictionary[1];

}
//temporary_tables END@2
void FIA_LIAB::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void FIA_LIAB::start_of_projection() {
}
//start_of_projection END@2

void FIA_LIAB::end_of_projection() {
}
//end_of_projection END@2

void FIA_LIAB::start_of_layer() {
}


void FIA_LIAB::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void FIA_LIAB::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ptr_tt_tax_capzd_prem_amortzn_sched->reset();  // reset temporary table
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void FIA_LIAB::after_startup(int decrement) {
// Call startup for submodels
	   sm_fia_mrb.doBeforeStartupProcessing(decrement);

	   sm_fia_account.doBeforeStartupProcessing(decrement);

	   sm_carvm_stat.doBeforeStartupProcessing(decrement);

	   sm_carvm_tax.doBeforeStartupProcessing(decrement);

	   sm_fia_ann_pba.doBeforeStartupProcessing(decrement);

	   sm_fia_sfas97rd.doBeforeStartupProcessing(decrement);

  if(sm_fia_rates)
   sm_fia_rates->doBeforeStartupProcessing(decrement);

}
//after_startup END@2


 void FIA_LIAB::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> FIA_LIAB::ddfVector;
BitArray FIA_LIAB::dataVariables(496);
bool FIA_LIAB::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool FIA_LIAB::writeClassInfo = true;

void FIA_LIAB::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, FIA_LIAB::descriptor_0>::dT = FIA_LIAB::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, FIA_LIAB::descriptor_0>::dT = FIA_LIAB::descriptor_0;
Descriptor* Attribute::Proxy<StrEnum::StringEnum, FIA_LIAB::descriptor_256>::dT = FIA_LIAB::descriptor_256;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, FIA_LIAB::descriptor_256>::dT = FIA_LIAB::descriptor_256;

