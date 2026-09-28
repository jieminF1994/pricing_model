
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
#include "ModelClass\invstrat_asset_udf.h"
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

extern ofstream& PVCFile;
extern ostringstream PVCText;
extern int pv_asset_defn;
extern int pv_model_point;
extern int PVCounter;

// yield maintenance detail file
extern ofstream& YMFile; 

#if defined(__SEC_ASSET_H_)
extern int pv_cp_asset_defn;
extern int pv_cp_model_point;
#endif

sowmpoutput bond_state_of_world_header_mp_output;
sowmpoutput mtg_state_of_world_header_mp_output;
sowmpoutput sec_state_of_world_header_mp_output;
sowmpoutput ird_state_of_world_header_mp_output;
sowmpoutput re_state_of_world_header_mp_output;
sowmpoutput eqt_state_of_world_header_mp_output;
sowmpoutput eio_state_of_world_header_mp_output;
sowmpoutput epa_state_of_world_header_mp_output;

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
#ifndef invstrat_asset_TableDefs
#define invstrat_asset_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection INVSTRAT_ASSET::TTHC;
void INVSTRAT_ASSET::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_cal_mth(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"cal_mth",t);
}



//^^^

#line 1 "cal_mth.INVSTRAT_ASSET.for"
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
double INVSTRAT_ASSET_UDF::invstrat_asset_cal_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(2,"cal_yr",t);
}



//^^^

#line 1 "cal_yr.INVSTRAT_ASSET.for"
if (t == 0)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}

//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_cal_yr_relative(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(3,"cal_yr_relative",t);
}



//^^^

#line 1 "cal_yr_relative.INVSTRAT_ASSET.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}

//@@ END

//@@ START - cash
// Cash                                                                                             
// Column:CASH
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_cash(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(4,"cash",t);
}



//^^^

#line 1 "cash.INVSTRAT_ASSET.for"
if (t < 0)
	return NO_AVG;

if (t == 0)
	return (seg_element->init_cash + seg_element->init_cash_addn)
		   * seg_element->initial_asset_pct_to_use_time_step
		   + seg_element->hedge_sale_amt(t)
		   - seg_element->hedge_inv_amt_eom(t)
		   - seg_element->hedge_exp(t);

// Cash flow for investment final
double cash_flow_for_inv_final = seg_element->cash_flow_for_inv(t);

// Ensure negative cash flow strategy for period is selected
neg_cash_flow_strat_set(t);

double cash = 0.0;
if (cash_flow_for_asset_purch(t) >= 0
	|| neg_cash_flow_strat == BORROW
	|| neg_cash_flow_strat == NEGATIVE_ASSETS)
	cash = this->cash(t - 1) 
		   + interim_cash(t - 1)
		   + cash_flow_for_inv_final
		   - inv_amt(t)
		   - interim_cash(t);
else if (cash_flow_for_asset_purch(t) < 0
		 && neg_cash_flow_strat == SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE)
	cash = this->cash(t - 1)
		   + interim_cash(t - 1)
		   + cash_flow_for_inv_final
		   - inv_amt(t)
		   - interim_cash(t);

return cash;

}

//@@ END

//@@ START - cash_flow_for_asset_purch
// Cash Flow for Asset Purchases                                                                                             
// Column:CASH_FLOW_FOR_ASSET_PURCH
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_cash_flow_for_asset_purch(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(5,"cash_flow_for_asset_purch",t);
}



//^^^

#line 1 "cash_flow_for_asset_purch.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

double cash_avail_for_inv = cash_flow_for_inv(t) - cash_incr(t);

seg_id = seg_id;
double inv_amt_min_local = inv_amt_min;
double cash_for_investment_eom = 0.0;

if (inv_eom_flag(t))
	cash_for_investment_eom	= cash_avail_for_inv;

if (cash_for_investment_eom >= inv_amt_min_local
	&& cash_for_investment_eom > 0.0
	&& !use_dur_match_strat(t))
	{
	bool warnings = false;
	inv_strat_select(t, CURRENT, DO_NOT_ISSUE_WARNINGS, warnings);
	}

if (asset->asset_detail_rpt_inv_strat_flag(t))
	seg_element->SALFile << endl
				 << "EOM Cash For Asset Purchases" << endl
				 << "SelectedStrat," << inv_strat_id << endl
				 << "CashTgtPct," << cash_tgt_pct << endl
				 << "StratDistribnMethod," << get_string_of_enum_val(asset_sub_port_distribn_defn) << endl
				 << "CashFlowForInv," << cash_flow_for_inv(t) << endl
				 << "(-) CashIncr," << cash_incr(t) << endl
				 << "CashAvailForAssetPurch," << cash_avail_for_inv << endl
				 << "CashForAssetPurchEOM," << cash_for_investment_eom << endl;

return cash_for_investment_eom;

}

//@@ END

//@@ START - cash_flow_for_inv
// Cash Flow for Investment                                                                                             
// Column:CASH_FLOW_FOR_INV
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_cash_flow_for_inv(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(6,"cash_flow_for_inv",t);
}



//^^^

#line 1 "cash_flow_for_inv.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

double local_cash_flow_for_inv_eom
= cash_flow_for_inv_bef_rebal(t)
  + cash_flow_rebal(t);

bool warnings = false;

// Ensure negative cash flow strategy for period is selected
neg_cash_flow_strat_set(t);

if (local_cash_flow_for_inv_eom < 0.0
	&& neg_cash_flow_strat == NEGATIVE_ASSETS)
	inv_strat_select(t, NEGATIVE, DO_NOT_ISSUE_WARNINGS, warnings);

else if (!use_dur_match_strat(t))
	inv_strat_select(t, CURRENT, DO_NOT_ISSUE_WARNINGS, warnings);

if (asset->asset_detail_rpt_inv_strat_flag(t))
	seg_element->SALFile << endl
				 << "EOM Cash Flow For Investment" << endl 
				 << "CashFlowForInvBefRebal," << cash_flow_for_inv_bef_rebal(t) << endl 
				 << "(+) RebalNetCashFlow," << cash_flow_rebal(t) << endl
				 << "CashFlowForInv," << local_cash_flow_for_inv_eom << endl;	

return local_cash_flow_for_inv_eom;

}

//@@ END

//@@ START - cash_flow_for_inv_bef_rebal
// Cash Flow for Investment Before Rebalancing                                                                                             
// Column:CASH_FLOW_FOR_INV_BEF_REBAL
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_cash_flow_for_inv_bef_rebal(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(7,"cash_flow_for_inv_bef_rebal",t);
}



//^^^

#line 1 "cash_flow_for_inv_bef_rebal.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

double cash_flow_for_inv_bef_rebal = 0.0;

double liab_cash_flow = seg_element->liab_cash_flow(t);
double asset_cash_flow_bef_sale = seg_element->asset_cash_flow_bef_sale(t);
double interim_cash = this->interim_cash(t - 1);
double plan_sale_cash_flow = cash_flow_planned_sale(t);
double hedge_sale_cash_flow = cash_flow_hedge_sale(t);
double hedge_inv_cash_flow_eom = seg_element->hedge_inv_amt_eom(t);
double hedge_exp_eom = seg_element->hedge_exp(t);

double tax_cash_flow = 0.0;
double distribn_cash_flow = 0.0;
double contribn_from_business_seg = 0.0;

if (sale_possible_imr_avr_flag(t))
	{
	tax_cash_flow = seg_element->tax_bef_sale(t);
	distribn_cash_flow = seg_element->distribn_bef_sale(t);
	contribn_from_business_seg = seg_element->contribn_from_business_seg_bef_sale(t);
	}	
else 
	{
	tax_cash_flow = seg_element->tax(t);
	distribn_cash_flow = seg_element->distribn(t);
	contribn_from_business_seg = seg_element->contribn_from_business_seg(t);
	}

cash_flow_for_inv_bef_rebal
= liab_cash_flow
  + asset_cash_flow_bef_sale
  + interim_cash
  - tax_cash_flow
  + contribn_from_business_seg
  - distribn_cash_flow
  + plan_sale_cash_flow
  + hedge_sale_cash_flow
  - hedge_inv_cash_flow_eom
  - hedge_exp_eom;

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	seg_element->SALFile << endl;
	seg_element->SALFile << "EOM Cash Flow For Investment Before Rebalancing" 
				 << " (Period=" << t << " "
				 << " Year=" << xint(cal_yr(t))
				 << " Month=" << xint(cal_mth(t))
				 << ")"
				 << endl;
	seg_element->SALFile << "LiabilityCashFlow," << liab_cash_flow << endl
				 << "(+) InterimCash," << interim_cash << endl
				 << "(+) AssetCashFlowBefSales," << asset_cash_flow_bef_sale << endl;

	if (sale_possible_imr_avr_flag(t))
		seg_element->SALFile << "(-) MthlyTaxableIncTaxBefSale," << tax_cash_flow << endl
					 << "(-) DistribnBefSale," << distribn_cash_flow << endl;
	else
		seg_element->SALFile << "(-) MthlyTaxableIncTax," << tax_cash_flow << endl
					 << "(-) Distribn," << distribn_cash_flow << endl
 					 << "(+) ContribFromBusSeg," << contribn_from_business_seg << endl;

	seg_element->SALFile << "(+) PlannedSalesNetCashFlow," << plan_sale_cash_flow << endl
				 << "(+) HedgeSalesCashFlow," << hedge_sale_cash_flow << endl
				 << "(-) HedgeInvCashFlow," << hedge_inv_cash_flow_eom << endl
				 << "(-) HedgeExpenses," << hedge_exp_eom << endl
				 << "CashFlowForInvBefRebalancing," << cash_flow_for_inv_bef_rebal << endl;
	}

return cash_flow_for_inv_bef_rebal;

}

//@@ END

//@@ START - cash_flow_hedge_sale
// Cash Flow Hedge Sales                                                                                             
// Column:CASH_FLOW_HEDGE_SALE
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_cash_flow_hedge_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(8,"cash_flow_hedge_sale",t);
}



//^^^

#line 1 "cash_flow_hedge_sale.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

double cash_flow_hedge_sale = 0.0;

if (seg_element->business_seg_flag)
	cash_flow_hedge_sale = seg_element->hedge_sale_amt(t);

return cash_flow_hedge_sale;

}

//@@ END

//@@ START - cash_flow_planned_sale
// Cash Flow Planned Sales                                                                                             
// Column:CASH_FLOW_PLANNED_SALE
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_cash_flow_planned_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(9,"cash_flow_planned_sale",t);
}



//^^^

#line 1 "cash_flow_planned_sale.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

// Process mortgage decrement investments before planned or minimum size sales
restructure_cost_basis_net_write_down(t);
foreclosure_cost_basis_net_write_down(t);
refinance_cost_basis(t);

if (!sale_planned_or_min_size_flag(t))
	return NO_AVG;

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	seg_element->SALFile << endl;
	seg_element->SALFile << "Planned and Minimum Asset Sales"
			     << " Period=" << t
			     << " Year=" << xint(cal_yr(t))
			     << " Month=" << xint(cal_mth(t))
			     << endl;

	asset_detail_rpt_individual_sale(t, HEADER);
	}

return sell_assets_control(t,
                           YES, // sell_assets
                           PLANNED_SALES_OR_MINIMUM_SIZE_ASSETS,
                           NOT_APPLICABLE, // selection_defn
                           0.0); // required_amount

}

//@@ END

//@@ START - cash_flow_rebal
// Cash Flow Rebalancing                                                                                             
// Column:CASH_FLOW_REBAL
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_cash_flow_rebal(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(10,"cash_flow_rebal",t);
}



//^^^

#line 1 "cash_flow_rebal.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

seg_id = seg_id;
StrEnum::EnumValue rebal_freq_local = rebal_freq;
seg_id = seg_id;
StrEnum::EnumValue rebal_dur_match_defn_local = rebal_dur_match_defn;

if (rebal_freq_local == NOT_APPLICABLE)
	return NO_AVG;

bool tmpFalseBool = false;

if (rebal_dur_match_defn_local == NO)
	inv_strat_select(t, CURRENT, DO_NOT_ISSUE_WARNINGS, tmpFalseBool);
else if (!use_dur_match_strat(t))
	inv_strat_select(t, CURRENT, DO_NOT_ISSUE_WARNINGS, tmpFalseBool);

if (asset_sub_port_distribn_defn == CASH
	|| mths_to_rebal(t) > 0
	|| !inv_eom_flag(t))
	return NO_AVG;

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	seg_element->SALFile << endl;
	seg_element->SALFile << "EOM Rebalancing Sales" 
				 << " (Period=" << t << " "
				 << " Year=" << xint(cal_yr(t))
				 << " Month=" << xint(cal_mth(t))
				 << ")"
				 << endl;

	// Only display header once
	display_rebal_sales_header = YES;
	}

clear_expected_sale_vars(t);

double net_cash_flow_local
= cash_investment_sale_net(t);

clear_expected_sale_vars(t);

return net_cash_flow_local;

}

//@@ END

//@@ START - cash_flow_rebal_estimate
// Cash Flow Rebalancing Estimate                                                                                             
// Column:CASH_FLOW_REBAL_ESTIMATE
//========================================================
#undef NO_AVG
#define NO_AVG 0
double INVSTRAT_ASSET_UDF::invstrat_asset_cash_flow_rebal_estimate(int t) {
//^^^



//^^^

#line 1 "cash_flow_rebal_estimate.INVSTRAT_ASSET.for"
if (t <= 0)
	return 0.0;

if (mths_to_rebal(t) > 0)
	return 0.0;

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	seg_element->SALFile << endl
	 			 << "EOM Expected Rebalancing Sales:"
				 << " Period=" << t
				 << " Year=" << xint(cal_yr(t))
				 << " Month=" << xint(cal_mth(t))
				 << endl;
	// Only display header once
	display_rebal_sales_header = YES;
	}

clear_expected_sale_vars(t);

return cash_investment_sale_net_prelim(t);

}

#undef NO_AVG
#define NO_AVG The_Real_NO_AVG
//@@ END

//@@ START - cash_incr
// Cash Increase                                                                                             
// Column:CASH_INCR
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_cash_incr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(11,"cash_incr",t);
}



//^^^

#line 1 "cash_incr.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

// Previous investable assets
double investable_assets = 0.0;

double bk_val
= seg_element->sum_over_assets("bk_val_bef_neg_cash_flow_sale", t, SUM_OVER_ALL, 
		SUM_OVER_ALL, SUM_OVER_ALL, BEFORE_NCF_SALE);
double accr_int
= seg_element->sum_over_assets("accr_int_bef_neg_cash_flow_sale", t, SUM_OVER_ALL, 
		SUM_OVER_ALL, SUM_OVER_ALL, BEFORE_NCF_SALE);
double accr_rent
= seg_element->sum_over_assets("accr_rent_bef_neg_cash_flow_sale", t, SUM_OVER_ALL, 
		SUM_OVER_ALL, SUM_OVER_ALL, BEFORE_NCF_SALE);

investable_assets = bk_val
                    + accr_int
                    + accr_rent
                    + cash(t - 1)
                    + cash_flow_for_inv(t);

// Ensure negative cash flow stratey for current period is selected
neg_cash_flow_strat_set(t);

// Cash threshold
double cash_balance_base = investable_assets;
double cash_threshold = 0.0;

if (neg_cash_flow_strat == BORROW)
	cash_threshold = -USLIB_MAX_DOUBLE;
else if (neg_cash_flow_cash_bal_defn == REDUCE_CASH_BALANCE_TO_THRESHOLD)
	cash_threshold = min(cash_balance_base
				         * neg_cash_flow_cash_thresh_pct
				         + neg_cash_flow_cash_thresh_addn,
				         investable_assets
				           * cash_tgt_pct);
else if (neg_cash_flow_cash_bal_defn == BORROW_TO_THRESHOLD)
	cash_threshold = - cash_balance_base
			           * neg_cash_flow_cash_thresh_pct
		             - neg_cash_flow_cash_thresh_addn;
else if (neg_cash_flow_cash_bal_defn == TARGETED_CASH_BALANCE)
	cash_threshold = investable_assets
		             * cash_tgt_pct;

//20250527 CRBG logic
double c4_adj = seg_element->rbc_c4(t) * company->tgt_cap_rbc_mult * seg_element->tgt_cap_pct_inv_in_seg;

// Cash increase
double cash_incr = 0.0;

if (neg_cash_flow_strat != NEGATIVE_ASSETS
	&& investable_assets_bef_rebal(t) < 0.0)
	// Borrow only when the model has gone bust and is not investing in negative assets. 
	cash_incr
	= investable_assets_bef_rebal(t) - cash(t - 1);
else if (cash_flow_for_inv(t) >= 0.0
	     || (cash_flow_for_inv(t) < 0.0
		     && (neg_cash_flow_strat == BORROW
			     || (asset->mths_to_asset_sale(t) > 0
				     && neg_cash_flow_strat == SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE))))
	cash_incr
	= min(cash_flow_for_inv(t),
		  investable_assets * cash_tgt_pct
		  + seg_element->opt_payoff_crbg(t) + c4_adj
		  - cash(t - 1));
else if (cash_flow_for_inv(t) < 0.0
		 && neg_cash_flow_cash_bal_defn == TARGETED_CASH_BALANCE
		 && (neg_cash_flow_strat == NEGATIVE_ASSETS
			|| (asset->mths_to_asset_sale(t) == 0
			    && neg_cash_flow_strat == SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE)))
	cash_incr
	= min(0.0,
	      investable_assets
		  * cash_tgt_pct
		  + c4_adj
		  - cash(t - 1));
else if (cash_flow_for_inv(t) < 0
		 && (neg_cash_flow_cash_bal_defn == REDUCE_CASH_BALANCE_TO_THRESHOLD 
			 || neg_cash_flow_cash_bal_defn == BORROW_TO_THRESHOLD)
		 && (neg_cash_flow_strat == NEGATIVE_ASSETS
			 || (asset->mths_to_asset_sale(t) == 0
				 && neg_cash_flow_strat == SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE)))
	cash_incr
	= min(max(cash_flow_for_inv(t),
			  cash_threshold
			  - cash(t - 1)),
		  max(investable_assets * cash_tgt_pct + c4_adj,
			  cash_threshold)
			  - cash(t - 1));

return cash_incr;

}

//@@ END

//@@ START - cash_investment_sale_net
// Cash from Investemnt Asset Sales Net                                                                                             
// Column:CASH_INVESTMENT_SALE_NET
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_cash_investment_sale_net(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(12,"cash_investment_sale_net",t);
}



//^^^

#line 1 "cash_investment_sale_net.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

seg_id = seg_id;
StrEnum::EnumValue rebal_freq_local = rebal_freq;

if (!inv_eom_flag(t)
	|| rebal_freq_local == NOT_APPLICABLE
	|| mths_to_rebal(t) > 0)
	return NO_AVG;

bool warnings = false;
seg_id = seg_id;
StrEnum::EnumValue rebal_dur_match_defn_local = rebal_dur_match_defn;
	
if (rebal_dur_match_defn_local == NO)
	inv_strat_select(t, CURRENT, DO_NOT_ISSUE_WARNINGS, warnings);

else if (!use_dur_match_strat(t))
	inv_strat_select(t, CURRENT, DO_NOT_ISSUE_WARNINGS, warnings);

return rebal_sale(t, YES); // Sell assets

}

//@@ END

//@@ START - cash_investment_sale_net_prelim
// Cash from INvestment Asset Sales Net Preliminary                                                                                             
// Column:CASH_INVESTMENT_SALE_NET_PRELIM
//========================================================
#undef NO_AVG
#define NO_AVG 0
double INVSTRAT_ASSET_UDF::invstrat_asset_cash_investment_sale_net_prelim(int t) {
//^^^



//^^^

#line 1 "cash_investment_sale_net_prelim.INVSTRAT_ASSET.for"
if (t <= 0)
	return 0.0;

seg_id = seg_id;
StrEnum::EnumValue rebal_freq_local = rebal_freq;

if (!inv_eom_flag(t)
	|| rebal_freq_local == NOT_APPLICABLE
	|| mths_to_rebal(t) > 0)
	return 0.0;

bool warnings = false;
seg_id = seg_id;
StrEnum::EnumValue rebal_dur_match_defn_local = rebal_dur_match_defn;
	
if (rebal_dur_match_defn_local == NO)
	inv_strat_select(t, CURRENT, DO_NOT_ISSUE_WARNINGS, warnings);

return rebal_sale(t, NO); // Not selling assets

}

#undef NO_AVG
#define NO_AVG The_Real_NO_AVG
//@@ END

//@@ START - cash_net_neg_cash_flow_sale
// Cash Net Negative Cash Flow Sales                                                                                             
// Column:CASH_NET_NEG_CASH_FLOW_SALE
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_cash_net_neg_cash_flow_sale(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(13,"cash_net_neg_cash_flow_sale",t);
}



//^^^

#line 1 "cash_net_neg_cash_flow_sale.INVSTRAT_ASSET.for"
if (t <= 0
	|| asset->mths_to_asset_sale(t) != 0
	|| !inv_eom_flag(t))
	return NO_AVG;

// Ensure negative cash flow strategy for current period is selected
neg_cash_flow_strat_set(t);
if (neg_cash_flow_strat != SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE)
	return NO_AVG;

if (inv_deficit(t) <= 0)
	return NO_AVG;

double local_book_value_before_negative_cash_flow_sales = 0;
double net_cash_from_sale_of_assets = 0;
double net_cash_from_sales = 0;
double remaining_cash_required  = 0;
double sales_priority_level_book_value = 0;
int asset_sub_port = 0;
int class_priority_level = 0;
int done_selling_assets = 0;
int negative_cash_flow_sales_priority_level = 0;
int sale_class = 0;
int sales_priority_level = 0;

initialize_sale_and_inv_vars_eom(t);

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	seg_element->SALFile << endl;
	seg_element->SALFile << "Negative Cash Flow Sales"
				 << " Period=" << t
				 << " Year=" << xint(cal_yr(t))
				 << " Month=" << xint(cal_mth(t))
				 << endl;
	seg_element->SALFile << " ... Negative Cash Flow Strategy = " << inv_strat_id
				 << endl;
	asset_detail_rpt_individual_sale(t, HEADER);
	}

for (int fund_index = 0; fund_index < MAXIMUM_NUMBER_OF_ASSET_FUNDS; fund_index++)
	asset_fund_to_sell_flag[fund_index] = 1;

remaining_cash_required = inv_deficit(t);

for (class_priority_level = 1;
	 class_priority_level <= neg_cash_flow_sales_priority_class_max;
	 class_priority_level = class_priority_level + 1)
	{
	sales_priority_level = 0;
	done_selling_assets = 0;

	while (remaining_cash_required > aggregate_amount_threshold
		   && !done_selling_assets)
		{
		negative_cash_flow_sales_priority_level = 0;

		for (sales_priority_level = sales_priority_level + 1;
			 sales_priority_level <= sales_priority_sub_port_max;
			 sales_priority_level++)
			{
			sales_priority_level_book_value = 0.0;

			for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
				{
				asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->sub_ports_to_sell = 0;

				if (asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->sale_priority == sales_priority_level)
					asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->sub_ports_to_sell = 1;

				for (sale_class = 1; sale_class <= MAXIMUM_NUMBER_OF_SALES_CLASSES; sale_class++)
					{
					if (neg_cash_flow_sale_class_priority[sale_class] == class_priority_level)
						asset_class_to_sell_flag[sale_class] = 1;
					else
						asset_class_to_sell_flag[sale_class] = 0;

					if (asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->sub_ports_to_sell == 1
						&& asset_class_to_sell_flag[sale_class] == 1)
						{
						sales_priority_level_book_value
						+= sub_port_class_fund_initial_book_value[asset_sub_port][sale_class][INVESTMENT_FUND_INDEX]
						   - sub_port_class_fund_book_value_sold[asset_sub_port][sale_class][INVESTMENT_FUND_INDEX];
						}
					} //end_for sale_class
				}   // end_for asset_sub_port

			if (negative_cash_flow_sales_priority_level == 0
				&& sales_priority_level_book_value > 0.0)
				negative_cash_flow_sales_priority_level
				= sales_priority_level;

			if (negative_cash_flow_sales_priority_level > 0)
				break;

			}   // end_for sales_priority_level

		if (negative_cash_flow_sales_priority_level > 0)
			{
			net_cash_from_sale_of_assets
			= sell_assets_control(t,
			                      YES, // Sell_assets
			                      NEGATIVE_CASH_FLOW_SALES,
			                      neg_cash_flow_sale_selection_defn,
			                      remaining_cash_required);

			net_cash_from_sales	+= net_cash_from_sale_of_assets;

			remaining_cash_required	-= net_cash_from_sale_of_assets;
			}
		else
			done_selling_assets = 1;

		} // end_while
	}   // end_for class_priority_level

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	seg_element->SALFile << " ... " << setw(14) << setprecision(2) << net_cash_from_sales
				 << "  Net Cash From Negative Cash Flow Sales"
				 << endl;
	}

return net_cash_from_sales;

}

//@@ END

//@@ START - date
// Date                                                                                             
// Column:DATE
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_date(int t) {
//^^^



//^^^

#line 1 "date.INVSTRAT_ASSET.for"
// This column is a lookup key for external sources varying by date
// The definition matches Excel = number of days since 1899
// The value is for the first day of the current month

int year = cal_yr(t);
int month = cal_mth(t);
int day = 1;

return day_number_from_date(year, month, day);

}

//@@ END

//@@ START - dur_bef_match
// Duration Before Match                                                                                             
// Column:DUR_BEF_MATCH
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_dur_bef_match(int t) {
//^^^



//^^^

#line 1 "dur_bef_match.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

if (fabs(mkt_val_for_dur_bef_dur_match(t)) > model_point_amount_threshold)
	return mkt_val_times_dur_bef_dur_match(t)
		   / mkt_val_for_dur_bef_dur_match(t);

return NO_AVG;

}

//@@ END

//@@ START - dur_final_port
// Duration Final Portfolio                                                                                             
// Column:DUR_FINAL_PORT
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_dur_final_port(int t) {
//^^^



//^^^

#line 1 "dur_final_port.INVSTRAT_ASSET.for"
if (t <= 0 || company->calc_eff_dur_crbg == NO)
	return NO_AVG;

// forced calls for reporting
mkt_val_sale_for_dur_match(t);
mkt_val_purch_for_dur_match(t);

double duration_numerator
= seg_element->sum_over_assets("mkt_val_times_eff_dur", t, SUM_OVER_ALL, 
					   SUM_OVER_ALL, INVESTMENT_FUND_INDEX, END_OF_PERIOD);

double duration_denominator
= seg_element->sum_over_assets("mkt_val_for_eff_dur", t, SUM_OVER_ALL, 
					   SUM_OVER_ALL, INVESTMENT_FUND_INDEX, END_OF_PERIOD);

if (fabs(duration_denominator) < model_point_amount_threshold)
	return NO_AVG;

return duration_numerator / duration_denominator;

}

//@@ END

//@@ START - dur_match_flag
// Duration Matching Flag                                                                                             
// Column:DUR_MATCH_FLAG
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_dur_match_flag(int t) {
//^^^



//^^^

#line 1 "dur_match_flag.INVSTRAT_ASSET.for"
if (t <= 0 || company->calc_eff_dur_crbg == NO)
	return NO_AVG;

// Initialize strategy set (if necessary)
inv_strat_set(t);

// Check for duration matching strategies
if (asset->mths_to_next_mkt_val_calc(t) == 0
	&& (inv_strat_shorter != inv_strat_current
		|| inv_strat_longer != inv_strat_current))
	return 1;

return 0;

}

//@@ END

//@@ START - dur_match_tgt
// Duration Matching Target                                                                                             
// Column:DUR_MATCH_TGT
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_dur_match_tgt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(18,"dur_match_tgt",t);
}



//^^^

#line 1 "dur_match_tgt.INVSTRAT_ASSET.for"
if (t <= 0 || asset->mths_to_next_mkt_val_calc(t) > 0)
	return NO_AVG;

// Select investment strategy set, which determines dur_match_tgt_incr input variable.
inv_strat_set(t);

date_lookup = date(t);
double dur_match_tgt_local = dur_match_tgt_input;

double target = dur_match_tgt_local + dur_match_tgt_incr;

if (data_validation_defn == YES	&& target < 0.0)
	{		
	log_screen << "Warning: Duration matching target is negative for t = " << t
	           << ", and has been set to zero."
			   << MSG_USER;
	}

return max(0.0, target);

}

//@@ END

//@@ START - dur_match_tolerance
// Duration Matching Tolerance                                                                                             
// Column:DUR_MATCH_TOLERANCE
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_dur_match_tolerance(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(19,"dur_match_tolerance",t);
}



//^^^

#line 1 "dur_match_tolerance.INVSTRAT_ASSET.for"
if (t <= 0 || asset->mths_to_next_mkt_val_calc(t) > 0)
	return NO_AVG;

// Select investment strategy set, which determines dur_match_tolerance_incr input variable.
inv_strat_set(t);

date_lookup = date(t);
double dur_match_tolerance_local = dur_match_tolerance_input;

double tolerance = dur_match_tolerance_local + dur_match_tolerance_incr;

if (data_validation_defn == YES && tolerance < 0.0)
	{		
	log_screen << "Warning: Duration matching tolerance is negative for t = " << t
	           << ", and has been set to zero."
			   << MSG_USER;
	}

return max(0.0, tolerance);

}

//@@ END

//@@ START - finalize
// Finalize                                                                                             
// Column:FINALIZE
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.INVSTRAT_ASSET.for"
#if defined (__BOND_ASSET_H_) || defined (__MTG_ASSET_H_) || defined (__SEC_ASSET_H_)
pv_asset_defn = -1;
pv_model_point = -1;

#if defined(__SEC_ASSET_H_)
pv_cp_asset_defn = -1;
pv_cp_model_point = -1;
#endif

#endif

// Call finalize for individual assets
int mp = 0;
map <int, long, less <int> >::iterator mp_map_iter;

#if defined(__BOND_ASSET_H_)
if (asset->sm_bond.size())
	{
    if (time_step_flag && !valn_flag
            && proj_set_sub_loop_num < valn_periods.size())
            write_bond_state_of_world_header_mp();

	for (mp_map_iter = seg_element->bond_mp_map_active.begin();
		 mp_map_iter != seg_element->bond_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		asset->sm_bond[mp][0]->finalize(t);
		}
	}
#endif

#if defined(__MTG_ASSET_H_)
if (asset->sm_mtg.size())
	{
    if (time_step_flag && !valn_flag
            && proj_set_sub_loop_num < valn_periods.size())
            write_mtg_state_of_world_header_mp();
	
	for (mp_map_iter = seg_element->mtg_mp_map_active.begin();
		 mp_map_iter != seg_element->mtg_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		asset->sm_mtg[mp][0]->finalize(t);
		}
	}
#endif

#if defined(__SEC_ASSET_H_)
if (asset->sm_sec.size())
	{
    if (time_step_flag && !valn_flag
            && proj_set_sub_loop_num < valn_periods.size())
            write_sec_state_of_world_header_mp();
				
	for (mp_map_iter = seg_element->sec_mp_map_active.begin();
		 mp_map_iter != seg_element->sec_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		asset->sm_sec[mp]->finalize(t);	
		}
	}
#endif

#if defined(__IRD_ASSET_H_)
if (asset->sm_ird.size())
	{
    if (time_step_flag && !valn_flag
            && proj_set_sub_loop_num < valn_periods.size())
            write_ird_state_of_world_header_mp();
	
	for (mp_map_iter = seg_element->ird_mp_map_active.begin();
		 mp_map_iter != seg_element->ird_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		asset->sm_ird[mp][0]->finalize(t);	
		}
	}
#endif

#if defined(__RE_ASSET_H_)
if (asset->sm_re.size())
	{
    if (time_step_flag && !valn_flag
            && proj_set_sub_loop_num < valn_periods.size())
            write_re_state_of_world_header_mp();
	
	for (mp_map_iter = seg_element->re_mp_map_active.begin();
		 mp_map_iter != seg_element->re_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		asset->sm_re[mp]->finalize(t);
		}
	}
#endif

#if defined(__EQT_ASSET_H_)
if (asset->sm_eqt.size())
	{
    if (time_step_flag && !valn_flag
            && proj_set_sub_loop_num < valn_periods.size())
            write_eqt_state_of_world_header_mp();
	
	for (mp_map_iter = seg_element->eqt_mp_map_active.begin();
		 mp_map_iter != seg_element->eqt_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		asset->sm_eqt[mp]->finalize(t);	
		}
	}
#endif

#if defined(__EIO_ASSET_H_)
if (asset->sm_eio.size())
	{
    if (time_step_flag && !valn_flag
            && proj_set_sub_loop_num < valn_periods.size())
            write_eio_state_of_world_header_mp();
				
	for (mp_map_iter = seg_element->eio_mp_map_active.begin();
		 mp_map_iter != seg_element->eio_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		asset->sm_eio[mp][0]->finalize(t);	
		}
	}
#endif

#if defined(__EPA_ASSET_H_)
if (asset->sm_epa.size())
	{
    if (time_step_flag && !valn_flag
            && proj_set_sub_loop_num < valn_periods.size())
            write_epa_state_of_world_header_mp();
	
	for (mp_map_iter = seg_element->epa_mp_map_active.begin();
		 mp_map_iter != seg_element->epa_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;
		asset->sm_epa[mp]->finalize(t);	
		}
	}
#endif

seg_element->SALFile.close();
PVCFile.close();
YMFile.close();

return 1;

}

//@@ END

//@@ START - foreclosure_bk_val_net_write_down
// Foreclosure Book Value Net Write Down                                                                                             
// Column:FORECLOSURE_BK_VAL_NET_WRITE_DOWN
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_bk_val_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(21,"foreclosure_bk_val_net_write_down",t);
}



//^^^

#line 1 "foreclosure_bk_val_net_write_down.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("foreclosure_bk_val_net_write_down", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - foreclosure_bk_val_net_write_down_neg_asset
// Foreclosure Book Value Net Write Down Negative Asset                                                                                             
// Column:FORECLOSURE_BK_VAL_NET_WRITE_DOWN_NEG_ASSET
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_bk_val_net_write_down_neg_asset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(22,"foreclosure_bk_val_net_write_down_neg_asset",t);
}



//^^^

#line 1 "foreclosure_bk_val_net_write_down_neg_asset.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("foreclosure_bk_val_net_write_down_neg_asset", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - foreclosure_cost_basis_net_write_down
// Foreclosure Cost Basis Net Write Down                                                                                             
// Column:FORECLOSURE_COST_BASIS_NET_WRITE_DOWN
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_cost_basis_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(23,"foreclosure_cost_basis_net_write_down",t);
}



//^^^

#line 1 "foreclosure_cost_basis_net_write_down.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int asset_id = foreclosure_asset_id;

// return if there are no foreclosure assets
if (asset_id < 0)
	return NO_AVG;

double aggregate_cost_basis_net_of_write_down
= seg_element->sum_over_assets("foreclosure_cost_basis_net_write_down", t, SUM_OVER_ALL, 
					   SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

if (fabs(aggregate_cost_basis_net_of_write_down) < model_point_amount_threshold)
	return NO_AVG;

refinance_foreclosure_restructure_cost_basis 
= aggregate_cost_basis_net_of_write_down;

refinance_foreclosure_restructure_bk_val 
= foreclosure_bk_val_net_write_down(t);

refinance_foreclosure_restructure_par 
= foreclosure_prin_net_write_down(t);

if (asset->asset_detail_rpt_pv_defn == YES
	&& inlist(purch_assets_id[asset_id], asset->asset_detail_rpt_cusip_id)
	&& asset->asset_detail_rpt_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "--> Purchasing Foreclosure Assets"
			<< " ID=" << purch_assets_id[asset_id]
			<< " cost basis=" << refinance_foreclosure_restructure_cost_basis
			<< " book value=" << refinance_foreclosure_restructure_bk_val
			<< " principal=" << refinance_foreclosure_restructure_par;
	asset->asset_detail_rpt_pv_output();
	}

if (asset->asset_detail_rpt_inv_strat_defn == YES
	&& asset->asset_detail_rpt_flag(t))
	{
	seg_element->SALFile << endl;
	seg_element->SALFile << "Purchasing Foreclosure Assets"
				 << " period=" << t
				 << endl;
	asset_detail_rpt_buy_purch_asset(t, HEADER);
	}

if ((refinance_foreclosure_restructure_cost_basis >= 0.0
	 && refinance_foreclosure_restructure_bk_val >= 0.0
	 && refinance_foreclosure_restructure_par >= 0.0)
	||
	(refinance_foreclosure_restructure_cost_basis <= 0.0
	 && refinance_foreclosure_restructure_bk_val <= 0.0
	 && refinance_foreclosure_restructure_par <= 0.0))
	{
	buy_purch_asset_inv(t,
	                    YES, // save_assets
	                    FORECLOSURE,
	                    asset_id, // panum
	                    refinance_foreclosure_restructure_par);
	}
else
	{
	// purchase negative asset
	refinance_foreclosure_restructure_cost_basis 
	= foreclosure_cost_basis_net_write_down_neg_asset(t);
	
	refinance_foreclosure_restructure_bk_val 
	= foreclosure_bk_val_net_write_down_neg_asset(t);
	
	refinance_foreclosure_restructure_par 
	= foreclosure_prin_net_write_down_neg_asset(t);

	buy_purch_asset_inv(t,
	                    YES, // save_assets
	                    FORECLOSURE,
	                    asset_id, // panum
	                    refinance_foreclosure_restructure_par);

	// purchase positive asset
	refinance_foreclosure_restructure_cost_basis
	= aggregate_cost_basis_net_of_write_down
	  - foreclosure_cost_basis_net_write_down_neg_asset(t);

	refinance_foreclosure_restructure_bk_val
	= foreclosure_bk_val_net_write_down(t)
	  - foreclosure_bk_val_net_write_down_neg_asset(t);

	refinance_foreclosure_restructure_par
	= foreclosure_prin_net_write_down(t)
	  - foreclosure_prin_net_write_down_neg_asset(t);

	buy_purch_asset_inv(t,
	                    YES, // save_assets
	                    FORECLOSURE,
	                    asset_id, // panum
	                    refinance_foreclosure_restructure_par);
	}

if (asset->asset_detail_rpt_pv_defn == YES
	&& inlist(purch_assets_id[asset_id], asset->asset_detail_rpt_cusip_id)
	&& asset->asset_detail_rpt_flag(t))
	{
	PVCText << PVCounter
			<< "<--End,Purchase of Foreclosure Assets"
			<< " ID=" << purch_assets_id[asset_id];
	asset->asset_detail_rpt_pv_output();
	PVCounter--;
	}

return aggregate_cost_basis_net_of_write_down;

}

//@@ END

//@@ START - foreclosure_cost_basis_net_write_down_neg_asset
// Foreclosure Cost Basis Net Write Down Negative Asset                                                                                             
// Column:FORECLOSURE_COST_BASIS_NET_WRITE_DOWN_NEG_ASSET
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_cost_basis_net_write_down_neg_asset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(24,"foreclosure_cost_basis_net_write_down_neg_asset",t);
}



//^^^

#line 1 "foreclosure_cost_basis_net_write_down_neg_asset.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("foreclosure_cost_basis_net_write_down_neg_asset", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - foreclosure_prin_net_write_down
// Foreclosure Principal Net Write Down                                                                                             
// Column:FORECLOSURE_PRIN_NET_WRITE_DOWN
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_prin_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(25,"foreclosure_prin_net_write_down",t);
}



//^^^

#line 1 "foreclosure_prin_net_write_down.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("foreclosure_prin_net_write_down", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - foreclosure_prin_net_write_down_neg_asset
// Foreclosure Principal Net Write Down Negative Asset                                                                                             
// Column:FORECLOSURE_PRIN_NET_WRITE_DOWN_NEG_ASSET
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_prin_net_write_down_neg_asset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(26,"foreclosure_prin_net_write_down_neg_asset",t);
}



//^^^

#line 1 "foreclosure_prin_net_write_down_neg_asset.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("foreclosure_prin_net_write_down_neg_asset", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.INVSTRAT_ASSET.for"
map <xstring, int, less<xstring> >::iterator stratmap_iter;
map <xstring, int, less<xstring> >::iterator purchmap_iter;

// set investment strategy group
this->setGroup(seg_id);

// Do not change sale_class_priority to a zero based table.
if (neg_cash_flow_sale_class_priority.size() < 5)
	neg_cash_flow_sale_class_priority.resize(5);

if (rebal_sale_class_priority.size() < 5)
	rebal_sale_class_priority.resize(5);

seg_id = seg_id;
rebal_sale_class_priority[1] = rebal_sale_priority_not_assigned;
seg_id = seg_id;
rebal_sale_class_priority[2] = rebal_sale_priority_avail_for_sale;
seg_id = seg_id;
rebal_sale_class_priority[3] = rebal_sale_priority_trading;
seg_id = seg_id;
rebal_sale_class_priority[4] = rebal_sale_priority_held_to_maturity;

if (asset_fund_to_sell_flag.size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
	asset_fund_to_sell_flag.resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);

if (asset_class_to_sell_flag.size() < MAXIMUM_NUMBER_OF_SALES_CLASSES + 1)
	asset_class_to_sell_flag.resize(MAXIMUM_NUMBER_OF_SALES_CLASSES + 1);

// Allocate space for sales, investment, and expected book plus accrued arrays
int a_sub_port_size = asset->sm_asset_sub_port[seg_num].size();

if (a_sub_port_size > 0)
	{
	if (sub_port_fund_initial_book_plus_accrued.size() < a_sub_port_size)
		sub_port_fund_initial_book_plus_accrued.resize(a_sub_port_size);
	if (sub_port_class_fund_assets_present.size() < a_sub_port_size)
		sub_port_class_fund_assets_present.resize(a_sub_port_size);
	if (sub_port_class_fund_initial_accrued_interest.size() < a_sub_port_size)
		sub_port_class_fund_initial_accrued_interest.resize(a_sub_port_size);
	if (sub_port_class_fund_initial_book_value.size() < a_sub_port_size)
		sub_port_class_fund_initial_book_value.resize(a_sub_port_size);
	if (sub_port_class_fund_initial_market_value.size() < a_sub_port_size)
		sub_port_class_fund_initial_market_value.resize(a_sub_port_size);
	if (sub_port_class_fund_initial_unrealized_capital_gains.size() < a_sub_port_size)
		sub_port_class_fund_initial_unrealized_capital_gains.resize(a_sub_port_size);

	if (sub_port_fund_book_plus_accrued_sold.size() < a_sub_port_size)
		sub_port_fund_book_plus_accrued_sold.resize(a_sub_port_size);
	if (sub_port_class_fund_accrued_interest_sold.size() < a_sub_port_size)
		sub_port_class_fund_accrued_interest_sold.resize(a_sub_port_size);
	if (sub_port_class_fund_book_value_sold.size() < a_sub_port_size)
		sub_port_class_fund_book_value_sold.resize(a_sub_port_size);
	if (sub_port_class_fund_market_value_sold.size() < a_sub_port_size)
		sub_port_class_fund_market_value_sold.resize(a_sub_port_size);
	if (sub_port_class_fund_unrealized_capital_gains_released.size() < a_sub_port_size)
		sub_port_class_fund_unrealized_capital_gains_released.resize(a_sub_port_size);

	if (sub_port_fund_book_plus_accrued_purchases.size() < a_sub_port_size)
		sub_port_fund_book_plus_accrued_purchases.resize(a_sub_port_size);
	if (sub_port_class_fund_accrued_interest_purchases.size() < a_sub_port_size)
		sub_port_class_fund_accrued_interest_purchases.resize(a_sub_port_size);
	if (sub_port_class_fund_book_value_purchases.size() < a_sub_port_size)
		sub_port_class_fund_book_value_purchases.resize(a_sub_port_size);

	if (sub_port_fund_expected_book_plus_accrued_sold.size() < a_sub_port_size)
		sub_port_fund_expected_book_plus_accrued_sold.resize(a_sub_port_size);

	for(int asset_sub_port_num = 0; asset_sub_port_num < a_sub_port_size; asset_sub_port_num++)
		{
		if (sub_port_fund_initial_book_plus_accrued[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
			sub_port_fund_initial_book_plus_accrued[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);
		if (sub_port_class_fund_assets_present[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_SALES_CLASSES + 1)
			sub_port_class_fund_assets_present[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_SALES_CLASSES + 1);
		if (sub_port_class_fund_initial_accrued_interest[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_SALES_CLASSES + 1)
			sub_port_class_fund_initial_accrued_interest[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_SALES_CLASSES + 1);
		if (sub_port_class_fund_initial_book_value[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_SALES_CLASSES + 1)
			sub_port_class_fund_initial_book_value[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_SALES_CLASSES + 1);
		if (sub_port_class_fund_initial_market_value[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_SALES_CLASSES + 1)
			sub_port_class_fund_initial_market_value[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_SALES_CLASSES + 1);
		if (sub_port_class_fund_initial_unrealized_capital_gains[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_SALES_CLASSES + 1)
			sub_port_class_fund_initial_unrealized_capital_gains[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_SALES_CLASSES + 1);

		if (sub_port_fund_book_plus_accrued_sold[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
			sub_port_fund_book_plus_accrued_sold[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);
		if (sub_port_class_fund_accrued_interest_sold[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_SALES_CLASSES + 1)
			sub_port_class_fund_accrued_interest_sold[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_SALES_CLASSES + 1);
		if (sub_port_class_fund_book_value_sold[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_SALES_CLASSES + 1)
			sub_port_class_fund_book_value_sold[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_SALES_CLASSES + 1);
		if (sub_port_class_fund_market_value_sold[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_SALES_CLASSES + 1)
			sub_port_class_fund_market_value_sold[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_SALES_CLASSES + 1);
		if (sub_port_class_fund_unrealized_capital_gains_released[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_SALES_CLASSES + 1)
			sub_port_class_fund_unrealized_capital_gains_released[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_SALES_CLASSES + 1);

		if (sub_port_fund_book_plus_accrued_purchases[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
			sub_port_fund_book_plus_accrued_purchases[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);
		if (sub_port_class_fund_accrued_interest_purchases[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_SALES_CLASSES + 1)
			sub_port_class_fund_accrued_interest_purchases[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_SALES_CLASSES + 1);
		if (sub_port_class_fund_book_value_purchases[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_SALES_CLASSES + 1)
			sub_port_class_fund_book_value_purchases[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_SALES_CLASSES + 1);

		if (sub_port_fund_expected_book_plus_accrued_sold[asset_sub_port_num].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
			sub_port_fund_expected_book_plus_accrued_sold[asset_sub_port_num].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);

		for (int sale_class = 1; sale_class <= MAXIMUM_NUMBER_OF_SALES_CLASSES; sale_class++)
			{
			if (sub_port_class_fund_assets_present[asset_sub_port_num][sale_class].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
				sub_port_class_fund_assets_present[asset_sub_port_num][sale_class].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);
			if (sub_port_class_fund_initial_accrued_interest[asset_sub_port_num][sale_class].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
				sub_port_class_fund_initial_accrued_interest[asset_sub_port_num][sale_class].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);
			if (sub_port_class_fund_initial_book_value[asset_sub_port_num][sale_class].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
				sub_port_class_fund_initial_book_value[asset_sub_port_num][sale_class].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);
			if (sub_port_class_fund_initial_market_value[asset_sub_port_num][sale_class].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
				sub_port_class_fund_initial_market_value[asset_sub_port_num][sale_class].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);
			if (sub_port_class_fund_initial_unrealized_capital_gains[asset_sub_port_num][sale_class].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
				sub_port_class_fund_initial_unrealized_capital_gains[asset_sub_port_num][sale_class].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);

			if (sub_port_class_fund_accrued_interest_sold[asset_sub_port_num][sale_class].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
				sub_port_class_fund_accrued_interest_sold[asset_sub_port_num][sale_class].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);
			if (sub_port_class_fund_book_value_sold[asset_sub_port_num][sale_class].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
				sub_port_class_fund_book_value_sold[asset_sub_port_num][sale_class].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);
			if (sub_port_class_fund_market_value_sold[asset_sub_port_num][sale_class].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
				sub_port_class_fund_market_value_sold[asset_sub_port_num][sale_class].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);
			if (sub_port_class_fund_unrealized_capital_gains_released[asset_sub_port_num][sale_class].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
				sub_port_class_fund_unrealized_capital_gains_released[asset_sub_port_num][sale_class].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);

			if (sub_port_class_fund_accrued_interest_purchases[asset_sub_port_num][sale_class].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
				sub_port_class_fund_accrued_interest_purchases[asset_sub_port_num][sale_class].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);
			if (sub_port_class_fund_book_value_purchases[asset_sub_port_num][sale_class].size() < MAXIMUM_NUMBER_OF_ASSET_FUNDS)
				sub_port_class_fund_book_value_purchases[asset_sub_port_num][sale_class].resize(MAXIMUM_NUMBER_OF_ASSET_FUNDS);
			}
		}
	}

set_purch_asset_maps();

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	int counter = 0;
	seg_element->SALFile << endl 
				 << "Calendar Period Strategy Application" << endl 
				 << "Period,Date,PlannedStrategy,ShorterStrategy,ShortestStrategy,LongerStrategy,LongestStrategy,DurMatchTgt,DurMatchTolerance" << endl;

	xstring inv_strat_planned_prior = "NONE";
	xstring inv_strat_planned_shorter_prior = "NONE";
	xstring inv_strat_planned_shortest_prior = "NONE";
	xstring inv_strat_planned_longer_prior = "NONE";
	xstring inv_strat_planned_longest_prior = "NONE";
	double dur_match_tgt_input_prior = 0.0;
	double dur_match_tolerance_input_prior = 999.0;

	for (int mth = 1; mth <= final_period; mth++)
		{
		date_lookup = date(mth);
		xstring inv_strat_planned_local = inv_strat_planned;

		date_lookup = date(mth);
		xstring inv_strat_planned_shorter_local = inv_strat_planned_shorter;

		date_lookup = date(mth);
		xstring inv_strat_planned_shortest_local = inv_strat_planned_shortest;

		date_lookup = date(mth);
		xstring inv_strat_planned_longer_local = inv_strat_planned_longer;

		date_lookup = date(mth);
		xstring inv_strat_planned_longest_local = inv_strat_planned_longest;
		
		date_lookup = date(mth);
		double dur_match_tgt_local = dur_match_tgt_input;

		date_lookup = date(mth);
		double dur_match_tolerance_local = dur_match_tolerance_input;

		if (mth == 1 
			|| inv_strat_planned_local != inv_strat_planned_prior
			|| inv_strat_planned_shorter_local != inv_strat_planned_shorter_prior
			|| inv_strat_planned_shortest_local != inv_strat_planned_shortest_prior
			|| inv_strat_planned_longer_local != inv_strat_planned_longer_prior
			|| inv_strat_planned_longest_local != inv_strat_planned_longest_prior
			|| abs(dur_match_tgt_local - dur_match_tgt_input_prior) > rate_ratio_threshold
			|| abs(dur_match_tolerance_local - dur_match_tolerance_input_prior) > rate_ratio_threshold)
			{
			date_lookup = date(mth);
			seg_element->SALFile << mth << ","
						 << get_string_of_date(date(mth)) << ","
						 << inv_strat_planned_local << ","
						 << inv_strat_planned_shorter_local << ","
						 << inv_strat_planned_shortest_local << ","
						 << inv_strat_planned_longer_local << ","
						 << inv_strat_planned_longest_local << ","	
						 << dur_match_tgt_local << ","
						 << dur_match_tolerance_local << endl;		

			date_lookup = date(mth);
			inv_strat_planned_prior = inv_strat_planned_local;
			inv_strat_planned_shorter_prior = inv_strat_planned_shorter_local;
			inv_strat_planned_shortest_prior = inv_strat_planned_shortest_local;
			inv_strat_planned_longer_prior = inv_strat_planned_longer_local;
			inv_strat_planned_longest_prior = inv_strat_planned_longest_local;
			dur_match_tgt_input_prior = dur_match_tgt_local;
			dur_match_tolerance_input_prior = dur_match_tolerance_local;

			if ((stratmap_iter = stratmap_inv.find(inv_strat_planned_prior)) == stratmap_inv.end())
				{
				stratmap_inv[inv_strat_planned_prior] = counter;
				counter++;
				}

			if ((stratmap_iter = stratmap_inv.find(inv_strat_planned_shorter_prior)) == stratmap_inv.end())
				{
				stratmap_inv[inv_strat_planned_shorter_prior] = counter;
				counter++;
				}

			if ((stratmap_iter = stratmap_inv.find(inv_strat_planned_shortest_prior)) == stratmap_inv.end())
				{
				stratmap_inv[inv_strat_planned_shortest_prior] = counter;
				counter++;
				}

			if ((stratmap_iter = stratmap_inv.find(inv_strat_planned_longer_prior)) == stratmap_inv.end())
				{
				stratmap_inv[inv_strat_planned_longer_prior] = counter;
				counter++;
				}

			if ((stratmap_iter = stratmap_inv.find(inv_strat_planned_longest_prior)) == stratmap_inv.end())
				{
				stratmap_inv[inv_strat_planned_longest_prior] = counter;
				counter++;
				}
			}
		}
		
	seg_id = seg_id;
	int inv_strat_economic_tests_local = inv_strat_economic_tests;

	if (inv_strat_economic_tests_local)
		{
		seg_element->SALFile << endl 
					 << "Economic Strategy Application" << endl 
					 << "TestNum,TestDefn,Mths,TestCalcDefn,Rate1Term,Rate2Term,LagMths,CompareDefn,FixedTestVal,PlannedStrategy,"
					 << "DurMatchTgtIncr,DurMatchToleranceIncr,ShorterStrategy,ShortestStrategy,LongerStrategy,LongestStrategy" << endl;

		for (inv_strat_economic_test_num = 1; inv_strat_economic_test_num <= inv_strat_economic_tests_local; inv_strat_economic_test_num++)
			{
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			StrEnum::EnumValue inv_strat_economic_test_defn_local = inv_strat_economic_test_defn;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			int inv_strat_economic_mths_local = inv_strat_economic_mths;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			StrEnum::EnumValue inv_strat_economic_test_calc_defn_local = inv_strat_economic_test_calc_defn;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			double inv_strat_economic_rate_1_term_local = inv_strat_economic_rate_1_term;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			double inv_strat_economic_rate_2_term_local = inv_strat_economic_rate_2_term;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			int inv_strat_economic_lag_mths_local = inv_strat_economic_lag_mths;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			StrEnum::EnumValue inv_strat_economic_compare_defn_local = inv_strat_economic_compare_defn;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			double inv_strat_economic_fixed_test_val_local = inv_strat_economic_fixed_test_val;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			xstring inv_strat_economic_planned_local = inv_strat_economic_planned;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			double inv_strat_economic_dur_match_tgt_incr_local = inv_strat_economic_dur_match_tgt_incr;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			double inv_strat_economic_dur_match_tolerance_incr_local = inv_strat_economic_dur_match_tolerance_incr;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			xstring inv_strat_economic_shorter_local = inv_strat_economic_shorter;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			xstring inv_strat_economic_shortest_local = inv_strat_economic_shortest;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			xstring inv_strat_economic_longer_local = inv_strat_economic_longer;
			inv_strat_economic_test_num = inv_strat_economic_test_num;
			xstring inv_strat_economic_longest_local = inv_strat_economic_longest;

			seg_element->SALFile << inv_strat_economic_test_num << ","
						 << inv_strat_economic_test_defn_local << ","
						 << inv_strat_economic_mths_local << ","
						 << inv_strat_economic_test_calc_defn_local << ","
						 << inv_strat_economic_rate_1_term_local << ","
						 << inv_strat_economic_rate_2_term_local << ","
						 << inv_strat_economic_lag_mths_local << ","
						 << inv_strat_economic_compare_defn_local << ","
						 << inv_strat_economic_fixed_test_val_local << ","
						 << inv_strat_economic_planned_local << ","
						 << inv_strat_economic_dur_match_tgt_incr_local << ","
						 << inv_strat_economic_dur_match_tolerance_incr_local << ","
						 << inv_strat_economic_shorter_local << ","
						 << inv_strat_economic_shortest_local << ","
						 << inv_strat_economic_longer_local << ","
						 << inv_strat_economic_longest_local << endl;

			if ((stratmap_iter = stratmap_inv.find(inv_strat_economic_planned_local)) == stratmap_inv.end())
				{
				stratmap_inv[inv_strat_economic_planned_local] = counter;
				counter++;
				}

			if ((stratmap_iter = stratmap_inv.find(inv_strat_economic_shorter_local)) == stratmap_inv.end())
				{
				stratmap_inv[inv_strat_economic_shorter_local] = counter;
				counter++;
				}

			if ((stratmap_iter = stratmap_inv.find(inv_strat_economic_shortest_local)) == stratmap_inv.end())
				{
				stratmap_inv[inv_strat_economic_shortest_local] = counter;
				counter++;
				}

			if ((stratmap_iter = stratmap_inv.find(inv_strat_economic_longer_local)) == stratmap_inv.end())
				{
				stratmap_inv[inv_strat_economic_longer_local] = counter;
				counter++;
				}

			if ((stratmap_iter = stratmap_inv.find(inv_strat_economic_longest_local)) == stratmap_inv.end())
				{
				stratmap_inv[inv_strat_economic_longest_local] = counter;
				counter++;
				}
			}
		}

	seg_element->SALFile << endl 
				 << "Negative Cash Flow Calendar Period Strategy Application" << endl 
				 << "Period,Date,StrategyDefn,CashBalDefn,CashThreshPct,CashThreshAddn,NegAssetStrat,SaleSelectionDefn,SalePriorityAvailForSale,SalePriorityTrading,SalePriorityHeldToMat,SalePriorityNotAssigned" << endl;

	xstring neg_cash_flow_strat_planned_prior = "Borrow";
	xstring neg_cash_flow_strat_planned_cash_bal_defn_prior = "Reduce Cash Balance To Threshold";
	double neg_cash_flow_strat_planned_cash_thresh_pct_prior = 0.0;
	double neg_cash_flow_strat_planned_cash_thresh_addn_prior = 0.0;
	xstring neg_cash_flow_strat_planned_neg_assets_prior = "NONE";
	xstring neg_cash_flow_strat_planned_sale_selection_defn_prior = "Pro Rata";
	double neg_cash_flow_strat_planned_sale_priority_avail_for_sale_prior = 0.0;
	double neg_cash_flow_strat_planned_sale_priority_trading_prior = 0.0;
	double neg_cash_flow_strat_planned_sale_priority_held_to_maturity_prior = 0.0;
	double neg_cash_flow_strat_planned_sale_priority_not_assigned_prior = 0.0;

	for (int mth = 1; mth <= final_period; mth++)
		{
		date_lookup = date(mth);
		xstring neg_cash_flow_strat_planned_local = neg_cash_flow_strat_planned;

		date_lookup = date(mth);
		xstring neg_cash_flow_strat_planned_cash_bal_defn_local = neg_cash_flow_strat_planned_cash_bal_defn;

		date_lookup = date(mth);
		double neg_cash_flow_strat_planned_cash_thresh_pct_local = neg_cash_flow_strat_planned_cash_thresh_pct;
		
		date_lookup = date(mth);
		double neg_cash_flow_strat_planned_cash_thresh_addn_local = neg_cash_flow_strat_planned_cash_thresh_addn;

		date_lookup = date(mth);
		xstring neg_cash_flow_strat_planned_neg_assets_local = neg_cash_flow_strat_planned_neg_assets;

		date_lookup = date(mth);
		xstring neg_cash_flow_strat_planned_sale_selection_defn_local = neg_cash_flow_strat_planned_sale_selection_defn;

		date_lookup = date(mth);
		int neg_cash_flow_strat_planned_sale_priority_avail_for_sale_local = neg_cash_flow_strat_planned_sale_priority_avail_for_sale;

		date_lookup = date(mth);
		int neg_cash_flow_strat_planned_sale_priority_trading_local = neg_cash_flow_strat_planned_sale_priority_trading;

		date_lookup = date(mth);
		int neg_cash_flow_strat_planned_sale_priority_held_to_maturity_local = neg_cash_flow_strat_planned_sale_priority_held_to_maturity;

		date_lookup = date(mth);
		int neg_cash_flow_strat_planned_sale_priority_not_assigned_local = neg_cash_flow_strat_planned_sale_priority_not_assigned;

		if (mth == 1 
			|| neg_cash_flow_strat_planned_local != neg_cash_flow_strat_planned_prior
			|| neg_cash_flow_strat_planned_cash_bal_defn_local != neg_cash_flow_strat_planned_cash_bal_defn_prior
			|| abs(neg_cash_flow_strat_planned_cash_thresh_pct_local - neg_cash_flow_strat_planned_cash_thresh_pct_prior) > rate_ratio_threshold
			|| abs(neg_cash_flow_strat_planned_cash_thresh_addn_local - neg_cash_flow_strat_planned_cash_thresh_addn_prior) > rate_ratio_threshold
			|| neg_cash_flow_strat_planned_neg_assets_local != neg_cash_flow_strat_planned_neg_assets_prior
			|| neg_cash_flow_strat_planned_sale_selection_defn_local != neg_cash_flow_strat_planned_sale_selection_defn_prior
			|| abs(neg_cash_flow_strat_planned_sale_priority_avail_for_sale_local - neg_cash_flow_strat_planned_sale_priority_avail_for_sale_prior) > rate_ratio_threshold
			|| abs(neg_cash_flow_strat_planned_sale_priority_trading_local - neg_cash_flow_strat_planned_sale_priority_trading_prior) > rate_ratio_threshold
			|| abs(neg_cash_flow_strat_planned_sale_priority_held_to_maturity_local - neg_cash_flow_strat_planned_sale_priority_held_to_maturity_prior) > rate_ratio_threshold
			|| abs(neg_cash_flow_strat_planned_sale_priority_not_assigned_local - neg_cash_flow_strat_planned_sale_priority_not_assigned_prior) > rate_ratio_threshold)
			{
			seg_element->SALFile << mth << ","
						 << get_string_of_date(date(mth)) << ","
						 << neg_cash_flow_strat_planned_local << ","
						 << neg_cash_flow_strat_planned_cash_bal_defn_local << ","
						 << neg_cash_flow_strat_planned_cash_thresh_pct_local << ","
						 << neg_cash_flow_strat_planned_cash_thresh_addn_local << ","
						 << neg_cash_flow_strat_planned_neg_assets_local << ","
						 << neg_cash_flow_strat_planned_sale_selection_defn_local << ","
						 << neg_cash_flow_strat_planned_sale_priority_avail_for_sale_local << ","
						 << neg_cash_flow_strat_planned_sale_priority_trading_local << ","
						 << neg_cash_flow_strat_planned_sale_priority_held_to_maturity_local << ","
						 << neg_cash_flow_strat_planned_sale_priority_not_assigned_local << "," << endl;		

			neg_cash_flow_strat_planned_prior = neg_cash_flow_strat_planned_local;
			neg_cash_flow_strat_planned_cash_bal_defn_prior = neg_cash_flow_strat_planned_cash_bal_defn_local;
			neg_cash_flow_strat_planned_cash_thresh_pct_prior = neg_cash_flow_strat_planned_cash_thresh_pct_local;
			neg_cash_flow_strat_planned_cash_thresh_addn_prior = neg_cash_flow_strat_planned_cash_thresh_addn_local;
			neg_cash_flow_strat_planned_neg_assets_prior = neg_cash_flow_strat_planned_neg_assets_local;
			neg_cash_flow_strat_planned_sale_selection_defn_prior = neg_cash_flow_strat_planned_sale_selection_defn_local;
			neg_cash_flow_strat_planned_sale_priority_avail_for_sale_prior = neg_cash_flow_strat_planned_sale_priority_avail_for_sale_local;
			neg_cash_flow_strat_planned_sale_priority_trading_prior = neg_cash_flow_strat_planned_sale_priority_trading_local;
			neg_cash_flow_strat_planned_sale_priority_held_to_maturity_prior = neg_cash_flow_strat_planned_sale_priority_held_to_maturity_local;
			neg_cash_flow_strat_planned_sale_priority_not_assigned_prior = neg_cash_flow_strat_planned_sale_priority_not_assigned_local;

			if (neg_cash_flow_strat_planned_neg_assets_prior != "NONE")
				{
				if ((stratmap_iter = stratmap_inv.find(neg_cash_flow_strat_planned_neg_assets_prior)) == stratmap_inv.end())
					{
					stratmap_inv[neg_cash_flow_strat_planned_neg_assets_prior] = counter;
					counter++;
					}
				}
			}
		}

	seg_id = seg_id;
	int neg_cash_flow_strat_economic_tests_local = neg_cash_flow_strat_economic_tests;

	if (neg_cash_flow_strat_economic_tests_local)
		{
		seg_element->SALFile << endl 
					 << "Economic Strategy Application" << endl 
					 << "TestNum,TestDefn,Mths,TestCalcDefn,Rate1Term,Rate2Term,LagMths,CompareDefn,FixedTestVal,"
					 << "StrategyDefn,,CashBalDefn,CashThreshPct,CashThreshAddn,NegAssetStrat,"
					 << "SaleSelectionDefn,SalePriorityAvailForSale,SalePriorityTrading,SalePriorityHeldToMat,SalePriorityNotAssigned" << endl;

		for (neg_cash_flow_strat_economic_test_num = 1; neg_cash_flow_strat_economic_test_num <= neg_cash_flow_strat_economic_tests_local; neg_cash_flow_strat_economic_test_num++)
			{
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			StrEnum::EnumValue neg_cash_flow_strat_economic_test_defn_local = neg_cash_flow_strat_economic_test_defn;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			int neg_cash_flow_strat_economic_mths_local = neg_cash_flow_strat_economic_mths;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			StrEnum::EnumValue neg_cash_flow_strat_economic_test_calc_defn_local = neg_cash_flow_strat_economic_test_calc_defn;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			double neg_cash_flow_strat_economic_rate_1_term_local = neg_cash_flow_strat_economic_rate_1_term;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			double neg_cash_flow_strat_economic_rate_2_term_local = neg_cash_flow_strat_economic_rate_2_term;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			int neg_cash_flow_strat_economic_lag_mths_local = neg_cash_flow_strat_economic_lag_mths;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			StrEnum::EnumValue neg_cash_flow_strat_economic_compare_defn_local = neg_cash_flow_strat_economic_compare_defn;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			double neg_cash_flow_strat_economic_fixed_test_val_local = neg_cash_flow_strat_economic_fixed_test_val;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			StrEnum::EnumValue neg_cash_flow_strat_economic_local = neg_cash_flow_strat_economic;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			StrEnum::EnumValue neg_cash_flow_strat_economic_cash_bal_defn_local = neg_cash_flow_strat_economic_cash_bal_defn;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			double neg_cash_flow_strat_economic_cash_thresh_pct_local = neg_cash_flow_strat_economic_cash_thresh_pct;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			double neg_cash_flow_strat_economic_cash_thresh_addn_local = neg_cash_flow_strat_economic_cash_thresh_addn;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			xstring neg_cash_flow_strat_economic_neg_assets_local = neg_cash_flow_strat_economic_neg_assets;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			StrEnum::EnumValue neg_cash_flow_strat_economic_sale_selection_defn_local = neg_cash_flow_strat_economic_sale_selection_defn;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			int neg_cash_flow_strat_economic_sale_priority_avail_for_sale_local = neg_cash_flow_strat_economic_sale_priority_avail_for_sale;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			int neg_cash_flow_strat_economic_sale_priority_trading_local = neg_cash_flow_strat_economic_sale_priority_trading;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			int neg_cash_flow_strat_economic_sale_priority_held_to_maturity_local = neg_cash_flow_strat_economic_sale_priority_held_to_maturity;
			neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
			int neg_cash_flow_strat_economic_sale_priority_not_assigned_local = neg_cash_flow_strat_economic_sale_priority_not_assigned;

			seg_element->SALFile << neg_cash_flow_strat_economic_test_num << ","
						 << neg_cash_flow_strat_economic_test_defn_local << ","
						 << neg_cash_flow_strat_economic_mths_local << ","
						 << neg_cash_flow_strat_economic_test_calc_defn_local << ","
						 << neg_cash_flow_strat_economic_rate_1_term_local << ","
						 << neg_cash_flow_strat_economic_rate_2_term_local << ","
						 << neg_cash_flow_strat_economic_lag_mths_local << ","
						 << neg_cash_flow_strat_economic_compare_defn_local << ","
						 << neg_cash_flow_strat_economic_fixed_test_val_local << ","
						 << neg_cash_flow_strat_economic_local << ","
						 << neg_cash_flow_strat_economic_cash_bal_defn_local << ","
						 << neg_cash_flow_strat_economic_cash_thresh_pct_local << ","
						 << neg_cash_flow_strat_economic_cash_thresh_addn_local << ","
						 << neg_cash_flow_strat_economic_neg_assets_local << ","
						 << neg_cash_flow_strat_economic_sale_selection_defn_local << ","
						 << neg_cash_flow_strat_economic_sale_priority_avail_for_sale_local << ","
						 << neg_cash_flow_strat_economic_sale_priority_trading_local << ","
						 << neg_cash_flow_strat_economic_sale_priority_held_to_maturity_local << ","
						 << neg_cash_flow_strat_economic_sale_priority_not_assigned_local << endl;

			if (neg_cash_flow_strat_economic_neg_assets_local != "NONE")
				{
				if ((stratmap_iter = stratmap_inv.find(neg_cash_flow_strat_economic_neg_assets_local)) == stratmap_inv.end())
					{
					stratmap_inv[neg_cash_flow_strat_planned_neg_assets_prior] = counter;
					counter++;
					}
				}
			}
		}

	seg_element->SALFile << endl
 				 << "Investment Strategy Input" << endl;

	for (stratmap_iter = stratmap_inv.begin();
		 stratmap_iter != stratmap_inv.end();
		 stratmap_iter++)
		{
		double asset_sub_port_inv_tgt_pct_local = 0.0;

		inv_strat_id = stratmap_iter->first;
		double inv_strat_cash_tgt_pct_local = inv_strat_cash_tgt_pct;

		inv_strat_id = stratmap_iter->first;
		StrEnum::EnumValue inv_strat_distribn_defn_local = inv_strat_distribn_defn;

		seg_element->SALFile << endl
					 << "StratID,CashTgtPct,DistribnDefn" << endl
					 << inv_strat_id << ","
					 << inv_strat_cash_tgt_pct_local << ","
					 << inv_strat_distribn_defn_local << endl;

		if (1.0 - inv_strat_cash_tgt_pct_local > rate_ratio_threshold)
			{
			seg_element->SALFile << "Investment Strategy Distribution Targets by Asset Sub Portfolio" << endl
						 << "SubPortID,TgtPct" << endl;

			for (int sub_port = 0; sub_port < company->sm_asset->sm_asset_sub_port[seg_num].size(); sub_port++)
				{
				asset_sub_port_id = company->sm_asset->asset_sub_ports[sub_port];
				inv_strat_id = stratmap_iter->first;
				asset_sub_port_inv_tgt_pct_local = asset_sub_port_inv_tgt_pct;

				if (asset_sub_port_inv_tgt_pct_local > rate_ratio_threshold)
					seg_element->SALFile << asset_sub_port_id << ","
								 << asset_sub_port_inv_tgt_pct_local << endl;
				}
			}

		bool write_header = true;
		for (purchmap_iter = purchmap_investment.begin();
			 purchmap_iter != purchmap_investment.end();
			 purchmap_iter++)
			{
			int panum = purchmap_iter->second;
			inv_strat_id = stratmap_iter->first;		
			purch_asset_id = purch_assets_id[panum];
			asset_sub_port_id = purch_asset_sub_port_id;
			
			inv_strat_id = stratmap_iter->first;		
			asset_sub_port_inv_tgt_pct_local = asset_sub_port_inv_tgt_pct;

			inv_strat_id = stratmap_iter->first;		
			purch_asset_id = purch_assets_id[panum];	
			double purch_asset_weight_local = purch_asset_weight;

			if (asset_sub_port_inv_tgt_pct_local > rate_ratio_threshold 
				&& purch_asset_weight_local > rate_ratio_threshold)
				{
				if (write_header)
					{
					seg_element->SALFile << "Purchase Asset Investment Strategy Weights" << endl
								 << "PurchAssetID,SubPortID,TgtPct" << endl;

					write_header = false;
					}

				seg_element->SALFile << purch_asset_id << ","
							 << asset_sub_port_id << ","
							 << purch_asset_weight_local << endl;
				}
			}
		}
	}

// Must validate all specified Negative Assets Strategies are cash distribution strategies
bool errors = false;
/*
xstring neg_cash_flow_strat_planned_neg_assets_prior = "NONE";

for (int mth = 1; mth <= final_period; mth++)
	{
	if (neg_cash_flow_strat_planned.AtTime(mth) == "Negative Assets") // result from .AtTime cannot compare against the Enumeration
		{
		if (mth == 1 
			|| neg_cash_flow_strat_planned_neg_assets.AtTime(mth) != neg_cash_flow_strat_planned_neg_assets_prior)
			{
			inv_strat_id = neg_cash_flow_strat_planned_neg_assets.AtTime(mth);

			if (inv_strat_distribn_defn != CASH)
				{	
				log_strm << "Error: Distribution definition is not 'Cash' for specified planned negative assets strategy " << inv_strat_id << "." << endl; 
				errors = true;
				}
			neg_cash_flow_strat_planned_neg_assets_prior = neg_cash_flow_strat_planned_neg_assets.AtTime(mth);
			}
		}
	}

if (neg_cash_flow_strat_economic_tests)
	{
	for (neg_cash_flow_strat_economic_test_num = 1; neg_cash_flow_strat_economic_test_num <= neg_cash_flow_strat_economic_tests; neg_cash_flow_strat_economic_test_num++)
		{
		if (neg_cash_flow_strat_economic == NEGATIVE_ASSETS)
			{
			inv_strat_id = neg_cash_flow_strat_economic_neg_assets;

			if (inv_strat_distribn_defn != CASH)
				{
				log_strm << "Error: Distribution definition is not 'Cash' for specified economic negative assets strategy " << inv_strat_id << "." << endl; 
				errors = true;
				}
			}
		}
	}

if (errors)
	throw FatalError("Negative asset strategy specification errors have been encountered. Please correct your data.");
*/

return 1.0;

}

//@@ END

//@@ START - initialize_sale_and_inv_vars_eom
// Initialize Sale and Investment Variables End of Month                                                                                             
// Column:INITIALIZE_SALE_AND_INV_VARS_EOM
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_initialize_sale_and_inv_vars_eom(int t) {
//^^^



//^^^

#line 1 "initialize_sale_and_inv_vars_eom.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

if (asset->asset_detail_rpt_inv_strat_flag(t))
	seg_element->SALFile << endl
			     << "Initializing standard sales and investment variables at EOM t=" << t << endl;

return initialize_sale_and_inv_vars(t, SUM_OVER_POSITIVE, END_OF_MONTH);

}

//@@ END

//@@ START - initialize_sub_port_sale_vars_eom
// Initialize Asset Sub Portfolio Sales Variables End of Month                                                                                             
// Column:INITIALIZE_SUB_PORT_SALE_VARS_EOM
//========================================================
#undef NO_AVG
#define NO_AVG 0
double INVSTRAT_ASSET_UDF::invstrat_asset_initialize_sub_port_sale_vars_eom(int t) {
//^^^



//^^^

#line 1 "initialize_sub_port_sale_vars_eom.INVSTRAT_ASSET.for"
if (t <= 0)
	return 0.0;

if (market_values_not_calculated_for_asset_sub_port_map.empty())
	return 1.0;

map <int, int, less<int> >::iterator mvmap_iter;
int sub_port_number = 0;
int asset_sub_ports_remaining_before_sales = 0;
current_sub_port = NULL;

// check to see if we need to initialize selected asset sub portfolios
for (sub_port_number = 0; sub_port_number < asset->sm_asset_sub_port[seg_num].size(); sub_port_number++)
	asset->sm_asset_sub_port[seg_num][sub_port_number][0]->sub_ports_to_initialize_for_sale = 0;

asset_sub_ports_remaining_before_sales
= market_values_not_calculated_for_asset_sub_port_map.size();

for (sub_port_number = 0; sub_port_number < asset->sm_asset_sub_port[seg_num].size(); sub_port_number++)
	{
	current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_number][0];

	if (current_sub_port->sub_ports_to_sell == 1)
		{
		if ((mvmap_iter = market_values_not_calculated_for_asset_sub_port_map.find(sub_port_number))
			 != market_values_not_calculated_for_asset_sub_port_map.end())
			{
			current_sub_port->sub_ports_to_initialize_for_sale = 1;
			market_values_not_calculated_for_asset_sub_port_map.erase(mvmap_iter);
			}
		}
	}

if (market_values_not_calculated_for_asset_sub_port_map.size()
	 == asset_sub_ports_remaining_before_sales)
	return 1.0;

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	xstring sub_ports_to_process = "";
	for (sub_port_number = 0; sub_port_number < asset->sm_asset_sub_port[seg_num].size(); sub_port_number++)
		{
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_number][0];
		if (current_sub_port->sub_ports_to_initialize_for_sale == 1)
			sub_ports_to_process = sub_ports_to_process + " " + current_sub_port->group;
		}

	seg_element->SALFile << " .i. Initializing asset sub portfolio sales variables"
			     << " for sub portfolios" << sub_ports_to_process
			     << ":: Period=" << t
			     << " Year=" << xint(cal_yr(t))
			     << " Month=" << xint(cal_mth(t))
			     << endl;
	}

// initialize variables, if necessary
initialize_sale_and_inv_vars_eom(t);

xstring xstring_asset_sub_port_number = "";
xstring xstring_initial_accrued_interest = "";
xstring xstring_initial_accrued_rent = "";
xstring xstring_initial_market_value = "";
xstring xstring_initial_unrealized_capital_gains = "";

int col_number_asset_sub_port_number = 0;
int col_number_accrued_interest = 0;
int col_number_accrued_rent = 0;
int col_number_market_value = 0;
int col_number_unrealized_capital_gains = 0;

int col_number_notional_amount_before_pm_sales = 0;
int col_number_notional_amount = 0;

double local_accrued_interest = 0;
double local_accrued_rent = 0;
double local_market_value = 0;
double local_unrealized_capital_gains = 0;
double local_multiplicative_factor = 0;

int mp = 0;
int sale_class = 0;
int fund_index = 0;

xstring_asset_sub_port_number = "sub_port_id";
xstring_initial_accrued_interest = "accr_int_bef_rebal_sale";
xstring_initial_accrued_rent = "accr_rent_bef_rebal_sale";
xstring_initial_market_value = "mkt_val_bef_rebal_sale";
xstring_initial_unrealized_capital_gains = "unrealzd_cap_gain_bef_rebal_sale";

#define INITIALIZE_SALES_VARIABLES_EOM 0 // 1 for values, 0 for no values
#if INITIALIZE_SALES_VARIABLES_EOM
	bool write_detail = false;
	if (asset->asset_detail_rpt_flag(t))
			write_detail = true;
	if (write_detail)
		{
		log_screen.setf(ios::fixed);
		log_screen << MSG_ERROR;
		log_screen << " .s. t=" << t
				<< " call_initialize_sales_variables_eom summary at " << timing
				<< MSG_ERROR;
		log_screen << "   t Gp C F   accr_int       mkt_val   unreal_cap_gains identifier"
				<< MSG_ERROR;
		log_screen << " ---- -- - - ------------------ ------------------ ------------------ ---------- "
				//      9999 xx 9 9 99999999999.999999 99999999999.999999 99999999999.999999 xxxxxxxxxx
				<< MSG_ERROR;
		}
#endif

// restrict the summations to only positive assets
int sum_type = SUM_OVER_POSITIVE;

// now calculate initial amounts
map <int, long, less <int> >::iterator mp_map_iter;

#if defined(__BOND_ASSET_H_)
if (seg_element->bond_mp_map_active.size())
	{
	col_number_asset_sub_port_number = asset->sm_bond[0][0]->Column(xstring_asset_sub_port_number).Number();
	col_number_accrued_interest = asset->sm_bond[0][0]->Column(xstring_initial_accrued_interest).Number();
	col_number_market_value = asset->sm_bond[0][0]->Column(xstring_initial_market_value).Number();
	col_number_notional_amount_before_pm_sales = asset->sm_bond[0][0]->Column("notional_amt_bef_rebal_sale").Number();
	col_number_notional_amount = asset->sm_bond[0][0]->Column("notional_amt").Number();
	col_number_unrealized_capital_gains = asset->sm_bond[0][0]->Column(xstring_initial_unrealized_capital_gains).Number();

	for (mp_map_iter = seg_element->bond_mp_map_active.begin();
		 mp_map_iter != seg_element->bond_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		sub_port_number = xint(asset->sm_bond[mp][0]->Column(col_number_asset_sub_port_number).Value(t));

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_bond[mp][0]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_bond[mp][0]->neg_asset_flag > 0)
			continue;

		if (asset->sm_asset_sub_port[seg_num][sub_port_number][0]->sub_ports_to_initialize_for_sale != 1
			|| (t > max(0, asset->sm_bond[mp][0]->commencement_period)
				&& asset->sm_bond[mp][0]->Column(col_number_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_bond[mp][0]->commencement_period
				&& asset->sm_bond[mp][0]->Column(col_number_notional_amount_before_pm_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sale_class = asset->sm_bond[mp][0]->sale_class_id;
		fund_index = asset->sm_bond[mp][0]->asset_fund_index;
		local_multiplicative_factor = asset->sm_bond[mp][0]->pct_to_use;

		local_accrued_interest
		= asset->sm_bond[mp][0]->Column(col_number_accrued_interest).Value(t)
		  * local_multiplicative_factor;

		local_market_value
		= asset->sm_bond[mp][0]->Column(col_number_market_value).Value(t)
		  * local_multiplicative_factor;

		local_unrealized_capital_gains
		= asset->sm_bond[mp][0]->Column(col_number_unrealized_capital_gains).Value(t)
		  * local_multiplicative_factor;

		sub_port_class_fund_initial_market_value[sub_port_number][sale_class][fund_index]
		+= local_market_value;
		sub_port_class_fund_initial_unrealized_capital_gains[sub_port_number][sale_class][fund_index]
		+= local_unrealized_capital_gains;

#if INITIALIZE_SALES_VARIABLES_EOM
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_number
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(18) << setprecision(6) << local_accrued_interest
			if (initialize_market_sales_values)
			log_screen << " " << setw(18) << setprecision(6) << local_market_value
					<< " " << setw(18) << setprecision(6) << local_unrealized_capital_gains;
			else
			log_screen << " " << setw(18) << setprecision(6) << 0.0
					<< " " << setw(18) << setprecision(6) << 0.0;
			log_screen << " " << setw(10) << asset->sm_bond[mp][0]->asset_id
					<< " |" << asset->sm_bond[mp][0]->modelName
					<< " " << asset->sm_bond[mp][0]->asset_purp
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__MTG_ASSET_H_)
if (seg_element->mtg_mp_map_active.size())
	{
	col_number_asset_sub_port_number = asset->sm_mtg[0][0]->Column(xstring_asset_sub_port_number).Number();
	col_number_accrued_interest = asset->sm_mtg[0][0]->Column(xstring_initial_accrued_interest).Number();
	col_number_market_value = asset->sm_mtg[0][0]->Column(xstring_initial_market_value).Number();
	col_number_notional_amount_before_pm_sales = asset->sm_mtg[0][0]->Column("notional_amt_bef_rebal_sale").Number();
	col_number_notional_amount = asset->sm_mtg[0][0]->Column("notional_amt").Number();
	col_number_unrealized_capital_gains = asset->sm_mtg[0][0]->Column(xstring_initial_unrealized_capital_gains).Number();

	for (mp_map_iter = seg_element->mtg_mp_map_active.begin();
		 mp_map_iter != seg_element->mtg_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		sub_port_number = xint(asset->sm_mtg[mp][0]->Column(col_number_asset_sub_port_number).Value(t));

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_mtg[mp][0]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_mtg[mp][0]->neg_asset_flag > 0)
			continue;

		if (asset->sm_asset_sub_port[seg_num][sub_port_number][0]->sub_ports_to_initialize_for_sale != 1
			|| (t > max(0, asset->sm_mtg[mp][0]->commencement_period)
				&& asset->sm_mtg[mp][0]->Column(col_number_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_mtg[mp][0]->commencement_period
				&& asset->sm_mtg[mp][0]->Column(col_number_notional_amount_before_pm_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sale_class = asset->sm_mtg[mp][0]->sale_class_id;
		fund_index = asset->sm_mtg[mp][0]->asset_fund_index;
		local_multiplicative_factor = asset->sm_mtg[mp][0]->pct_to_use;

		local_accrued_interest
		= asset->sm_mtg[mp][0]->Column(col_number_accrued_interest).Value(t)
		  * local_multiplicative_factor;

		local_market_value
		= asset->sm_mtg[mp][0]->Column(col_number_market_value).Value(t)
		  * local_multiplicative_factor;

		local_unrealized_capital_gains
		= asset->sm_mtg[mp][0]->Column(col_number_unrealized_capital_gains).Value(t)
		  * local_multiplicative_factor;

		sub_port_class_fund_initial_market_value[sub_port_number][sale_class][fund_index]
		+= local_market_value;
		sub_port_class_fund_initial_unrealized_capital_gains[sub_port_number][sale_class][fund_index]
		+= local_unrealized_capital_gains;

#if INITIALIZE_SALES_VARIABLES_EOM
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_number
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(18) << setprecision(6) << local_accrued_interest
			if (initialize_market_sales_values)
			log_screen << " " << setw(18) << setprecision(6) << local_market_value
					<< " " << setw(18) << setprecision(6) << local_unrealized_capital_gains;
			else
			log_screen << " " << setw(18) << setprecision(6) << 0.0
					<< " " << setw(18) << setprecision(6) << 0.0;
			log_screen << " " << setw(10) << asset->sm_mtg[mp][0]->asset_id
					<< " |" << asset->sm_mtg[mp][0]->modelName
					<< " " << asset->sm_mtg[mp][0]->asset_purp
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__SEC_ASSET_H_)
if (seg_element->sec_mp_map_active.size())
	{
	col_number_asset_sub_port_number = asset->sm_sec[0]->Column(xstring_asset_sub_port_number).Number();
	col_number_accrued_interest = asset->sm_sec[0]->Column(xstring_initial_accrued_interest).Number();
	col_number_market_value = asset->sm_sec[0]->Column(xstring_initial_market_value).Number();
	col_number_notional_amount_before_pm_sales = asset->sm_sec[0]->Column("notional_amt_bef_rebal_sale").Number();
	col_number_notional_amount = asset->sm_sec[0]->Column("notional_amt").Number();
	col_number_unrealized_capital_gains = asset->sm_sec[0]->Column(xstring_initial_unrealized_capital_gains).Number();

	for (mp_map_iter = seg_element->sec_mp_map_active.begin();
		 mp_map_iter != seg_element->sec_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		sub_port_number = xint(asset->sm_sec[mp]->Column(col_number_asset_sub_port_number).Value(t));

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_sec[mp]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_sec[mp]->neg_asset_flag > 0)
			continue;

		if (asset->sm_asset_sub_port[seg_num][sub_port_number][0]->sub_ports_to_initialize_for_sale != 1
			|| (t > max(0, asset->sm_sec[mp]->commencement_period)
				&& asset->sm_sec[mp]->Column(col_number_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_sec[mp]->commencement_period
				&& asset->sm_sec[mp]->Column(col_number_notional_amount_before_pm_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sale_class = asset->sm_sec[mp]->sale_class_id;
		fund_index = asset->sm_sec[mp]->asset_fund_index;
		local_multiplicative_factor = asset->sm_sec[mp]->pct_to_use;

		local_accrued_interest
		= asset->sm_sec[mp]->Column(col_number_accrued_interest).Value(t)
		  * local_multiplicative_factor;

		local_market_value
		= asset->sm_sec[mp]->Column(col_number_market_value).Value(t)
		  * local_multiplicative_factor;

		local_unrealized_capital_gains
		= asset->sm_sec[mp]->Column(col_number_unrealized_capital_gains).Value(t)
		  * local_multiplicative_factor;

		sub_port_class_fund_initial_market_value[sub_port_number][sale_class][fund_index]
		+= local_market_value;
		sub_port_class_fund_initial_unrealized_capital_gains[sub_port_number][sale_class][fund_index]
		+= local_unrealized_capital_gains;

#if INITIALIZE_SALES_VARIABLES_EOM
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_number
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(18) << setprecision(6) << local_accrued_interest
			if (initialize_market_sales_values)
			log_screen << " " << setw(18) << setprecision(6) << local_market_value
					<< " " << setw(18) << setprecision(6) << local_unrealized_capital_gains;
			else
			log_screen << " " << setw(18) << setprecision(6) << 0.0
					<< " " << setw(18) << setprecision(6) << 0.0;
			log_screen << " " << setw(10) << asset->sm_sec[mp]->asset_id
					<< " |" << asset->sm_sec[mp]->modelName
					<< " " << asset->sm_sec[mp]->asset_purp
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__IRD_ASSET_H_)
if (seg_element->ird_mp_map_active.size())
	{
	col_number_asset_sub_port_number = asset->sm_ird[0][0]->Column(xstring_asset_sub_port_number).Number();
	col_number_accrued_interest = asset->sm_ird[0][0]->Column(xstring_initial_accrued_interest).Number();
	col_number_market_value = asset->sm_ird[0][0]->Column(xstring_initial_market_value).Number();
	col_number_notional_amount_before_pm_sales = asset->sm_ird[0][0]->Column("notional_amt_bef_rebal_sale").Number();
	col_number_notional_amount = asset->sm_ird[0][0]->Column("notional_amt").Number();
	col_number_unrealized_capital_gains = asset->sm_ird[0][0]->Column(xstring_initial_unrealized_capital_gains).Number();

	for (mp_map_iter = seg_element->ird_mp_map_active.begin();
		 mp_map_iter != seg_element->ird_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		sub_port_number = xint(asset->sm_ird[mp][0]->Column(col_number_asset_sub_port_number).Value(t));

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_ird[mp][0]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_ird[mp][0]->neg_asset_flag > 0)
			continue;

		if (asset->sm_asset_sub_port[seg_num][sub_port_number][0]->sub_ports_to_initialize_for_sale != 1
			|| (t > max(0, asset->sm_ird[mp][0]->commencement_period)
				&& asset->sm_ird[mp][0]->Column(col_number_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_ird[mp][0]->commencement_period
				&& asset->sm_ird[mp][0]->Column(col_number_notional_amount_before_pm_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sale_class = asset->sm_ird[mp][0]->sale_class_id;
		fund_index = asset->sm_ird[mp][0]->asset_fund_index;
		local_multiplicative_factor = asset->sm_ird[mp][0]->pct_to_use;

		local_accrued_interest
		= asset->sm_ird[mp][0]->Column(col_number_accrued_interest).Value(t)
		  * local_multiplicative_factor;

		local_market_value
		= asset->sm_ird[mp][0]->Column(col_number_market_value).Value(t)
		  * local_multiplicative_factor;

		local_unrealized_capital_gains
		= asset->sm_ird[mp][0]->Column(col_number_unrealized_capital_gains).Value(t)
		  * local_multiplicative_factor;

		sub_port_class_fund_initial_market_value[sub_port_number][sale_class][fund_index]
		+= local_market_value;
		sub_port_class_fund_initial_unrealized_capital_gains[sub_port_number][sale_class][fund_index]
		+= local_unrealized_capital_gains;

#if INITIALIZE_SALES_VARIABLES_EOM
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_number
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(18) << setprecision(6) << local_accrued_interest
			if (initialize_market_sales_values)
			log_screen << " " << setw(18) << setprecision(6) << local_market_value
					<< " " << setw(18) << setprecision(6) << local_unrealized_capital_gains;
			else
			log_screen << " " << setw(18) << setprecision(6) << 0.0
					<< " " << setw(18) << setprecision(6) << 0.0;
			log_screen << " " << setw(10) << asset->sm_ird[mp][0]->asset_id
					<< " |" << asset->sm_ird[mp][0]->modelName
					<< " " << asset->sm_ird[mp][0]->asset_purp
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__RE_ASSET_H_)
if (seg_element->re_mp_map_active.size())
	{
	col_number_asset_sub_port_number = asset->sm_re[0]->Column(xstring_asset_sub_port_number).Number();
	col_number_accrued_rent = asset->sm_re[0]->Column(xstring_initial_accrued_rent).Number();
	col_number_market_value = asset->sm_re[0]->Column(xstring_initial_market_value).Number();
	col_number_notional_amount_before_pm_sales = asset->sm_re[0]->Column("notional_amt_bef_rebal_sale").Number();
	col_number_notional_amount = asset->sm_re[0]->Column("notional_amt").Number();
	col_number_unrealized_capital_gains = asset->sm_re[0]->Column(xstring_initial_unrealized_capital_gains).Number();

	for (mp_map_iter = seg_element->re_mp_map_active.begin();
		 mp_map_iter != seg_element->re_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		sub_port_number = xint(asset->sm_re[mp]->Column(col_number_asset_sub_port_number).Value(t));

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_re[mp]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_re[mp]->neg_asset_flag > 0)
			continue;

		if (asset->sm_asset_sub_port[seg_num][sub_port_number][0]->sub_ports_to_initialize_for_sale != 1
			|| (t > max(0, asset->sm_re[mp]->commencement_period)
				&& asset->sm_re[mp]->Column(col_number_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_re[mp]->commencement_period
				&& asset->sm_re[mp]->Column(col_number_notional_amount_before_pm_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sale_class = asset->sm_re[mp]->sale_class_id;
		fund_index = asset->sm_re[mp]->asset_fund_index;
		local_multiplicative_factor = asset->sm_re[mp]->pct_to_use;

		local_accrued_rent
		= asset->sm_re[mp]->Column(col_number_accrued_rent).Value(t)
		  * local_multiplicative_factor;

		local_market_value
		= asset->sm_re[mp]->Column(col_number_market_value).Value(t)
		  * local_multiplicative_factor;

		local_unrealized_capital_gains
		= asset->sm_re[mp]->Column(col_number_unrealized_capital_gains).Value(t)
		  * local_multiplicative_factor;

		sub_port_class_fund_initial_market_value[sub_port_number][sale_class][fund_index]
		+= local_market_value;
		sub_port_class_fund_initial_unrealized_capital_gains[sub_port_number][sale_class][fund_index]
		+= local_unrealized_capital_gains;

#if INITIALIZE_SALES_VARIABLES_EOM
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_number
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(18) << setprecision(6) << local_accrued_rent
			if (initialize_market_sales_values)
			log_screen << " " << setw(18) << setprecision(6) << local_market_value
					<< " " << setw(18) << setprecision(6) << local_unrealized_capital_gains;
			else
			log_screen << " " << setw(18) << setprecision(6) << 0.0
					<< " " << setw(18) << setprecision(6) << 0.0;
			log_screen << " " << setw(10) << asset->sm_re[mp]->asset_id
					<< " |" << asset->sm_re[mp]->modelName
					<< " " << asset->sm_re[mp]->asset_purp
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__EQT_ASSET_H_)
if (seg_element->eqt_mp_map_active.size())
	{
	col_number_asset_sub_port_number = asset->sm_eqt[0]->Column(xstring_asset_sub_port_number).Number();
	col_number_market_value = asset->sm_eqt[0]->Column(xstring_initial_market_value).Number();
	col_number_notional_amount_before_pm_sales = asset->sm_eqt[0]->Column("notional_amt_bef_rebal_sale").Number();
	col_number_notional_amount = asset->sm_eqt[0]->Column("notional_amt").Number();
	col_number_unrealized_capital_gains = asset->sm_eqt[0]->Column(xstring_initial_unrealized_capital_gains).Number();

	for (mp_map_iter = seg_element->eqt_mp_map_active.begin();
		 mp_map_iter != seg_element->eqt_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		sub_port_number = xint(asset->sm_eqt[mp]->Column(col_number_asset_sub_port_number).Value(t));

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_eqt[mp]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_eqt[mp]->neg_asset_flag > 0)
			continue;

		if (asset->sm_asset_sub_port[seg_num][sub_port_number][0]->sub_ports_to_initialize_for_sale != 1
			|| (t > max(0, asset->sm_eqt[mp]->commencement_period)
				&& asset->sm_eqt[mp]->Column(col_number_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_eqt[mp]->commencement_period
				&& asset->sm_eqt[mp]->Column(col_number_notional_amount_before_pm_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sale_class = asset->sm_eqt[mp]->sale_class_id;
		fund_index = asset->sm_eqt[mp]->asset_fund_index;
		local_multiplicative_factor = asset->sm_eqt[mp]->pct_to_use;

		local_market_value
		= asset->sm_eqt[mp]->Column(col_number_market_value).Value(t)
		  * local_multiplicative_factor;

		local_unrealized_capital_gains
		= asset->sm_eqt[mp]->Column(col_number_unrealized_capital_gains).Value(t)
		  * local_multiplicative_factor;

		sub_port_class_fund_initial_market_value[sub_port_number][sale_class][fund_index]
		+= local_market_value;
		sub_port_class_fund_initial_unrealized_capital_gains[sub_port_number][sale_class][fund_index]
		+= local_unrealized_capital_gains;

#if INITIALIZE_SALES_VARIABLES_EOM
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_number
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(18) << setprecision(6) << 0.0
			if (initialize_market_sales_values)
			log_screen << " " << setw(18) << setprecision(6) << local_market_value
					<< " " << setw(18) << setprecision(6) << local_unrealized_capital_gains;
			else
			log_screen << " " << setw(18) << setprecision(6) << 0.0
					<< " " << setw(18) << setprecision(6) << 0.0;
			log_screen << " " << setw(10) << asset->sm_eqt[mp]->asset_id
					<< " |" << asset->sm_eqt[mp]->modelName
					<< " " << asset->sm_eqt[mp]->asset_purp
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__EIO_ASSET_H_)
if (seg_element->eio_mp_map_active.size())
	{
	col_number_asset_sub_port_number = asset->sm_eio[0]->Column(xstring_asset_sub_port_number).Number();
	col_number_market_value = asset->sm_eio[0]->Column(xstring_initial_market_value).Number();
	col_number_notional_amount_before_pm_sales = asset->sm_eio[0]->Column("notional_amt_bef_rebal_sale").Number();
	col_number_notional_amount = asset->sm_eio[0]->Column("notional_amt").Number();
	col_number_unrealized_capital_gains = asset->sm_eio[0]->Column(xstring_initial_unrealized_capital_gains).Number();

	for (mp_map_iter = seg_element->eio_mp_map_active.begin();
		 mp_map_iter != seg_element->eio_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		sub_port_number = xint(asset->sm_eio[mp][0]->Column(col_number_asset_sub_port_number).Value(t));

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_eio[mp][0]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_eio[mp][0]->neg_asset_flag > 0)
			continue;

		if (asset->sm_asset_sub_port[seg_num][sub_port_number][0]->sub_ports_to_initialize_for_sale != 1
			|| (t > max(0, asset->sm_eio[mp][0]->commencement_period)
				&& asset->sm_eio[mp][0]->Column(col_number_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_eio[mp][0]->commencement_period
				&& asset->sm_eio[mp][0]->Column(col_number_notional_amount_before_pm_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sale_class = asset->sm_eio[mp][0]->sale_class_id;
		fund_index = asset->sm_eio[mp][0]->asset_fund_index;
		local_multiplicative_factor = asset->sm_eio[mp][0]->pct_to_use;

		local_market_value
		= asset->sm_eio[mp][0]->Column(col_number_market_value).Value(t)
		  * local_multiplicative_factor;

		local_unrealized_capital_gains
		= asset->sm_eio[mp][0]->Column(col_number_unrealized_capital_gains).Value(t)
		  * local_multiplicative_factor;

		sub_port_class_fund_initial_market_value[sub_port_number][sale_class][fund_index]
		+= local_market_value;
		sub_port_class_fund_initial_unrealized_capital_gains[sub_port_number][sale_class][fund_index]
		+= local_unrealized_capital_gains;

#if INITIALIZE_SALES_VARIABLES_EOM
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_number
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(18) << setprecision(6) << 0.0
			if (initialize_market_sales_values)
			log_screen << " " << setw(18) << setprecision(6) << local_market_value
					<< " " << setw(18) << setprecision(6) << local_unrealized_capital_gains;
			else
			log_screen << " " << setw(18) << setprecision(6) << 0.0
					<< " " << setw(18) << setprecision(6) << 0.0;
			log_screen << " " << setw(10) << asset->sm_eio[mp][0]->asset_id
					<< " |" << asset->sm_eio[mp][0]->modelName
					<< " " << asset->sm_eio[mp][0]->asset_purp
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__EPA_ASSET_H_)
if (seg_element->epa_mp_map_active.size())
	{
	col_number_asset_sub_port_number = asset->sm_epa[0]->Column(xstring_asset_sub_port_number).Number();
	col_number_accrued_interest = asset->sm_epa[0]->Column(xstring_initial_accrued_interest).Number();
	col_number_market_value = asset->sm_epa[0]->Column(xstring_initial_market_value).Number();
	col_number_notional_amount_before_pm_sales = asset->sm_epa[0]->Column("notional_amt_bef_rebal_sale").Number();
	col_number_notional_amount = asset->sm_epa[0]->Column("notional_amt").Number();
	col_number_unrealized_capital_gains = asset->sm_epa[0]->Column(xstring_initial_unrealized_capital_gains).Number();

	for (mp_map_iter = seg_element->epa_mp_map_active.begin();
		 mp_map_iter != seg_element->epa_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		sub_port_number = xint(asset->sm_epa[mp]->Column(col_number_asset_sub_port_number).Value(t));

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_epa[mp]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_epa[mp]->neg_asset_flag > 0)
			continue;

		if (asset->sm_asset_sub_port[seg_num][sub_port_number][0]->sub_ports_to_initialize_for_sale != 1
			|| (t > max(0, asset->sm_epa[mp]->commencement_period)
				&& asset->sm_epa[mp]->Column(col_number_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_epa[mp]->commencement_period
				&& asset->sm_epa[mp]->Column(col_number_notional_amount_before_pm_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sale_class = asset->sm_epa[mp]->sale_class_id;
		fund_index = asset->sm_epa[mp]->asset_fund_index;
		local_multiplicative_factor = asset->sm_epa[mp]->pct_to_use;

		local_accrued_interest
		= asset->sm_epa[mp]->Column(col_number_accrued_interest).Value(t)
		  * local_multiplicative_factor;

		local_market_value
		= asset->sm_epa[mp]->Column(col_number_market_value).Value(t)
		  * local_multiplicative_factor;

		local_unrealized_capital_gains
		= asset->sm_epa[mp]->Column(col_number_unrealized_capital_gains).Value(t)
		  * local_multiplicative_factor;

		sub_port_class_fund_initial_market_value[sub_port_number][sale_class][fund_index]
		+= local_market_value;

		sub_port_class_fund_initial_unrealized_capital_gains[sub_port_number][sale_class][fund_index]
		+= local_unrealized_capital_gains;

#if INITIALIZE_SALES_VARIABLES_EOM
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_number
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(18) << setprecision(6) << local_accrued_interest
			if (initialize_market_sales_values)
			log_screen << " " << setw(18) << setprecision(6) << local_market_value
					<< " " << setw(18) << setprecision(6) << local_unrealized_capital_gains;
			else
			log_screen << " " << setw(18) << setprecision(6) << 0.0
					<< " " << setw(18) << setprecision(6) << 0.0;
			log_screen << " " << setw(10) << asset->sm_epa[mp]->asset_id
					<< " |" << asset->sm_epa[mp]->modelName
					<< " " << asset->sm_epa[mp]->asset_purp
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

return 1.0;

}

#undef NO_AVG
#define NO_AVG The_Real_NO_AVG
//@@ END

//@@ START - interim_cash
// Interim Cash                                                                                             
// Column:INTERIM_CASH
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_interim_cash(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(29,"interim_cash",t);
}



//^^^

#line 1 "interim_cash.INVSTRAT_ASSET.for"
if (t < 0)
	return NO_AVG;

if (t == 0)
	{
	if (time_step_flag && valn_period > 0)
		return seg_element->init_interim_cash * seg_element->initial_asset_pct_to_use_time_step;

	return NO_AVG;
	}

// Ensure negative cash flow strategy for period is selected
neg_cash_flow_strat_set(t);

double local_interim_cash_inv = 0;
if (neg_cash_flow_strat == SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE
	&& asset->mths_to_asset_sale(t) == 0
	&& inv_eom_flag(t)
	&& inv_deficit(t) > aggregate_amount_threshold
	&& (cash_flow_for_inv(t) - cash_incr(t)) < -aggregate_amount_threshold)
	local_interim_cash_inv
	= cash_flow_for_asset_purch(t)
	  - inv_amt(t)
	  + inv_deficit(t);
else
	local_interim_cash_inv
	= cash_flow_for_inv(t)
      - cash_incr(t)
	  - inv_amt(t);

if (fabs(local_interim_cash_inv) > aggregate_amount_threshold)
	{
	local_interim_cash_inv -= cash_net_neg_cash_flow_sale(t);

	if (fabs(local_interim_cash_inv) > aggregate_amount_threshold)
		return local_interim_cash_inv;
	}

return NO_AVG;

}

//@@ END

//@@ START - inv_amt
// Investment Amount                                                                                             
// Column:INV_AMT
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_inv_amt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(30,"inv_amt",t);
}



//^^^

#line 1 "inv_amt.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

if (!inv_eom_flag(t))
	return NO_AVG;

double cash_flow_for_asset_purch = this->cash_flow_for_asset_purch(t);

// Ensure negative cash flow strategy for period is selected
neg_cash_flow_strat_set(t);

//Call select_strat() to calculate inv_strat_std_cash_pct for time period t
bool warnings = false;
if (cash_flow_for_asset_purch < 0.0
	&& neg_cash_flow_strat == NEGATIVE_ASSETS)
	inv_strat_select(t, NEGATIVE, DO_NOT_ISSUE_WARNINGS, warnings);
else if (!use_dur_match_strat(t))
	inv_strat_select(t, CURRENT, DO_NOT_ISSUE_WARNINGS, warnings);

if (cash_tgt_pct > (1.0 - rate_ratio_threshold))
	return NO_AVG;

if (asset->asset_detail_rpt_inv_strat_flag(t))
	seg_element->SALFile << endl
				 << "EOM Current Strategy Investments " << endl
				 << "Selected Current Strategy Label," << inv_strat_id << endl
				 << "Selected Current Cash Percentage," << cash_tgt_pct << endl
				 << "Selected Current Distribution Method," << get_string_of_enum_val(asset_sub_port_distribn_defn) << endl;

return buy_assets_inv(t, 
				YES, //save_assets
				cash_flow_for_asset_purch);

}

//@@ END

//@@ START - inv_deficit
// Investment Deficit                                                                                             
// Column:INV_DEFICIT
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_inv_deficit(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(31,"inv_deficit",t);
}



//^^^

#line 1 "inv_deficit.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

// Ensure negative cash flow strategy for period is selected
neg_cash_flow_strat_set(t);

if (neg_cash_flow_strat == SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE
	&& neg_cash_flow_cash_bal_defn != BORROW_TO_THRESHOLD)
	return -min(cash_flow_for_asset_purch(t),
				min(cash(t - 1)
					+ cash_incr(t), 0.0));

return -cash_flow_for_asset_purch(t);

}

//@@ END

//@@ START - inv_eom_flag
// Investment End of Month Flag                                                                                             
// Column:INV_EOM_FLAG
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_inv_eom_flag(int t) {
//^^^



//^^^

#line 1 "inv_eom_flag.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

seg_id = seg_id;
int yrs_to_inv_mthly_local = yrs_to_inv_mthly;
seg_id = seg_id;
int yrs_to_inv_qtrly_local = yrs_to_inv_qtrly;

if (cal_yr_relative(t) <= yrs_to_inv_mthly_local
	|| ((cal_yr_relative(t) > yrs_to_inv_mthly_local)
	     && (cal_yr_relative(t) <= (yrs_to_inv_mthly_local + yrs_to_inv_qtrly_local))
		 	&& xint(cal_mth(t)) % 3 == 0)
	|| ((cal_yr_relative(t) > (yrs_to_inv_mthly_local + yrs_to_inv_qtrly_local))
		&& xint(cal_mth(t)) % 12 == 0))
	return 1;

return 0;

}

//@@ END

//@@ START - investable_assets_bef_rebal
// Investable Assets Before Rebalancing                                                                                             
// Column:INVESTABLE_ASSETS_BEF_REBAL
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_investable_assets_bef_rebal(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(33,"investable_assets_bef_rebal",t);
}



//^^^

#line 1 "investable_assets_bef_rebal.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("bk_val_plus_accr_int_bef_rebal_sale", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, SUM_OVER_ALL, BEFORE_PM_SALE)
	   + cash(t - 1)
	   + cash_flow_for_inv_bef_rebal(t);

}

//@@ END

//@@ START - mkt_val_for_dur_bef_dur_match
// Market Value for Duration Before Duration Matching                                                                                             
// Column:MKT_VAL_FOR_DUR_BEF_DUR_MATCH
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_mkt_val_for_dur_bef_dur_match(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(34,"mkt_val_for_dur_bef_dur_match",t);
}



//^^^

#line 1 "mkt_val_for_dur_bef_dur_match.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

if (t > 0 && asset->mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;

seg_id = seg_id;
StrEnum::EnumValue rebal_dur_match_defn_local = rebal_dur_match_defn;

if (rebal_dur_match_defn_local == NO)
	return seg_element->sum_over_assets("mkt_val_for_dur_bef_neg_cash_flow_sale", t, SUM_OVER_ALL, 
								SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_NCF_SALE);

// else rebal_dur_match_defn == YES
return seg_element->sum_over_assets("mkt_val_for_dur_bef_rebal_sale", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_PM_SALE);

}

//@@ END

//@@ START - mkt_val_purch_for_dur_match
// Market Value Purchase for Duration Matching                                                                                             
// Column:MKT_VAL_PURCH_FOR_DUR_MATCH
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_mkt_val_purch_for_dur_match(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(35,"mkt_val_purch_for_dur_match",t);
}



//^^^

#line 1 "mkt_val_purch_for_dur_match.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

if (use_dur_match_strat(t))
	return seg_element->sum_over_assets("mkt_val_purch", t, SUM_OVER_ALL, SUM_OVER_ALL, INVESTMENT_FUND_INDEX, END_OF_PERIOD);

return NO_AVG;

}

//@@ END

//@@ START - mkt_val_sale
// Market Value Sale                                                                                             
// Column:MKT_VAL_SALE
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_mkt_val_sale(int t) {
//^^^



//^^^

#line 1 "mkt_val_sale.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

double mv_sold = 0.0;

if (fabs(cash_flow_planned_sale(t))
	+ fabs(cash_flow_hedge_sale(t))
	+ fabs(cash_flow_rebal(t))
	+ fabs(cash_net_neg_cash_flow_sale(t)) > model_point_amount_threshold)
	{
	mv_sold
	= seg_element->sum_over_assets("mkt_val_sold", t, SUM_OVER_ALL, SUM_OVER_ALL, SUM_OVER_ALL, BEFORE_EOM_PURCH)
      + seg_element->sum_over_assets("accr_int_sold", t, SUM_OVER_ALL, SUM_OVER_ALL, SUM_OVER_ALL, BEFORE_EOM_PURCH)
      + seg_element->sum_over_assets("accr_rent_sold", t, SUM_OVER_ALL, SUM_OVER_ALL, SUM_OVER_ALL, BEFORE_EOM_PURCH);
	}

return mv_sold;

}

//@@ END

//@@ START - mkt_val_sale_for_dur_match
// Market Value Sale for Duration Matching                                                                                             
// Column:MKT_VAL_SALE_FOR_DUR_MATCH
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_mkt_val_sale_for_dur_match(int t) {
//^^^



//^^^

#line 1 "mkt_val_sale_for_dur_match.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

if (fabs(cash_flow_planned_sale(t))
	+ fabs(cash_flow_rebal(t)) > model_point_amount_threshold)
	return seg_element->sum_over_assets("mkt_val_for_dur_sold", t, SUM_OVER_ALL, SUM_OVER_ALL, INVESTMENT_FUND_INDEX, END_OF_PERIOD);
				 
return NO_AVG;

}

//@@ END

//@@ START - mkt_val_times_dur_bef_dur_match
// Market Value Times Duration Before Duration Matching                                                                                             
// Column:MKT_VAL_TIMES_DUR_BEF_DUR_MATCH
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_mkt_val_times_dur_bef_dur_match(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(38,"mkt_val_times_dur_bef_dur_match",t);
}



//^^^

#line 1 "mkt_val_times_dur_bef_dur_match.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

if (t > 0 && asset->mths_to_next_mkt_val_calc(t) != 0)
	return NO_AVG;

seg_id = seg_id;
StrEnum::EnumValue rebal_dur_match_defn_local = rebal_dur_match_defn;

if (rebal_dur_match_defn_local == NO)
	return seg_element->sum_over_assets("mkt_val_times_dur_bef_neg_cash_flow_sale", t, SUM_OVER_ALL, 
								SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_NCF_SALE);

// else if (rebal_dur_match_defn == YES)
return seg_element->sum_over_assets("mkt_val_times_dur_bef_rebal_sale", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_PM_SALE);

}

//@@ END

//@@ START - mths_to_rebal
// Months to Rebalancing                                                                                             
// Column:MTHS_TO_REBAL
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_mths_to_rebal(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(39,"mths_to_rebal",t);
}



//^^^

#line 1 "mths_to_rebal.INVSTRAT_ASSET.for"
if (t < 0)
       return NO_AVG;

seg_id = seg_id;
StrEnum::EnumValue rebal_freq_local = rebal_freq;

if (t == 0)
       {
       if (rebal_freq_local == ANNUALLY)
              return 12 - ((proj_start_mth - 1) % 12);
       
       if (rebal_freq_local == AT_ASSET_FREQUENCY)
              return asset->mths_to_next_mkt_val_calc(t);

       if (rebal_freq_local == MONTHLY)
              return 1;

       if (rebal_freq_local == QUARTERLY)
              return 3 - ((proj_start_mth - 1) % 3);

       if (rebal_freq_local == SEMIANNUALLY)
              return 6 - ((proj_start_mth - 1) % 6);

       // else rebal_freq_local == NOT_APPLICABLE
       return 9999;
       }

if (mths_to_rebal(t - 1) > 0)
       return mths_to_rebal(t - 1) - 1;

if (mths_to_rebal(t - 1) == 0
       && rebal_freq_local == ANNUALLY)
       return 11;

if (mths_to_rebal(t - 1) == 0
       && rebal_freq_local == AT_ASSET_FREQUENCY)
       return asset->mths_to_next_mkt_val_calc(t);

if (mths_to_rebal(t - 1) == 0
       && rebal_freq_local == MONTHLY)
       return 0;

if (mths_to_rebal(t - 1) == 0
       && rebal_freq_local == QUARTERLY)
       return 2;

if (mths_to_rebal(t - 1) == 0
       && rebal_freq_local == SEMIANNUALLY)
       return 5;

return NO_AVG;

}

//@@ END

//@@ START - refinance_bk_val
// Refinance Book Value                                                                                             
// Column:REFINANCE_BK_VAL
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_refinance_bk_val(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(40,"refinance_bk_val",t);
}



//^^^

#line 1 "refinance_bk_val.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("refinance_bk_val", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - refinance_bk_val_neg_assets
// Refinance Book Value on Negative Assets                                                                                             
// Column:REFINANCE_BK_VAL_NEG_ASSETS
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_refinance_bk_val_neg_assets(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(41,"refinance_bk_val_neg_assets",t);
}



//^^^

#line 1 "refinance_bk_val_neg_assets.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("refinance_bk_val_neg_assets", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - refinance_cost_basis
// Refinance Cost Basis                                                                                             
// Column:REFINANCE_COST_BASIS
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_refinance_cost_basis(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(42,"refinance_cost_basis",t);
}



//^^^

#line 1 "refinance_cost_basis.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int asset_id = refinance_asset_id;

// return if there are no refinance assets
if (asset_id < 0)
	return NO_AVG;

double aggregate_refinance_cost_basis
= seg_element->sum_over_assets("refinance_cost_basis", t, SUM_OVER_ALL, 
					   SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

if (fabs(aggregate_refinance_cost_basis) < model_point_amount_threshold)
	return NO_AVG;

refinance_foreclosure_restructure_cost_basis
= aggregate_refinance_cost_basis;

refinance_foreclosure_restructure_bk_val
= refinance_bk_val(t);

refinance_foreclosure_restructure_par
= refinance_prin(t);

if (asset->asset_detail_rpt_pv_defn == YES
	&& inlist(purch_assets_id[asset_id], asset->asset_detail_rpt_cusip_id)
	&& asset->asset_detail_rpt_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "--> Purchasing Refinance Assets"
			<< " ID=" << purch_assets_id[asset_id]
			<< " cost basis=" << refinance_foreclosure_restructure_cost_basis
			<< " book value=" << refinance_foreclosure_restructure_bk_val
			<< " principal=" << refinance_foreclosure_restructure_par;
	asset->asset_detail_rpt_pv_output();
	}

if (asset->asset_detail_rpt_inv_strat_defn == YES
	&& asset->asset_detail_rpt_flag(t))
	{
	seg_element->SALFile << endl;
	seg_element->SALFile << "Purchasing Refinance Assets"
				 << " period=" << t
				 << endl;
	asset_detail_rpt_buy_purch_asset(t, HEADER);
	}

if ((refinance_foreclosure_restructure_cost_basis >= 0.0
	 && refinance_foreclosure_restructure_bk_val >= 0.0
	 && refinance_foreclosure_restructure_par >= 0.0)
	||
	(refinance_foreclosure_restructure_cost_basis <= 0.0
	 && refinance_foreclosure_restructure_bk_val <= 0.0
	 && refinance_foreclosure_restructure_par <= 0.0))
	{
	buy_purch_asset_inv(t,
	                    YES, // save_assets
	                    REFINANCE,
	                    asset_id, // panum
	                    refinance_foreclosure_restructure_par);
	}
else
	{
	// Purchase negative asset
	refinance_foreclosure_restructure_cost_basis
	= refinance_cost_basis_neg_asset(t);

	refinance_foreclosure_restructure_bk_val
	= refinance_bk_val_neg_assets(t);

	refinance_foreclosure_restructure_par
	= refinance_prin_neg_asset(t);

	buy_purch_asset_inv(t,
	                    YES, // save_assets
	                    REFINANCE,
	                    asset_id, // panum
	                    refinance_foreclosure_restructure_par);

	// purchase positive asset
	refinance_foreclosure_restructure_cost_basis
	= aggregate_refinance_cost_basis
	  - refinance_cost_basis_neg_asset(t);

	refinance_foreclosure_restructure_bk_val
	= refinance_bk_val(t)
	  - refinance_bk_val_neg_assets(t);

	refinance_foreclosure_restructure_par
	= refinance_prin(t)
	  - refinance_prin_neg_asset(t);

	buy_purch_asset_inv(t,
	                    YES, // save_assets
	                    REFINANCE,
	                    asset_id, // panum
	                    refinance_foreclosure_restructure_par);
	}

if (asset->asset_detail_rpt_pv_defn == YES
	&& inlist(purch_assets_id[asset_id], asset->asset_detail_rpt_cusip_id)
	&& asset->asset_detail_rpt_flag(t))
	{
	PVCText << PVCounter
			<< "<--End,Purchase of Refinance Assets"
			<< " ID=" << purch_assets_id[asset_id];
	asset->asset_detail_rpt_pv_output();
	PVCounter--;
	}

return aggregate_refinance_cost_basis;

}

//@@ END

//@@ START - refinance_cost_basis_neg_asset
// Refinance Cost Basis on Negative Asset                                                                                             
// Column:REFINANCE_COST_BASIS_NEG_ASSET
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_refinance_cost_basis_neg_asset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(43,"refinance_cost_basis_neg_asset",t);
}



//^^^

#line 1 "refinance_cost_basis_neg_asset.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("refinance_cost_basis_neg_asset", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - refinance_prin
// Refinance Principal                                                                                             
// Column:REFINANCE_PRIN
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_refinance_prin(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(44,"refinance_prin",t);
}



//^^^

#line 1 "refinance_prin.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("refinance_prin", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - refinance_prin_neg_asset
// Refinance Principal on Negative Asset                                                                                             
// Column:REFINANCE_PRIN_NEG_ASSET
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_refinance_prin_neg_asset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(45,"refinance_prin_neg_asset",t);
}



//^^^

#line 1 "refinance_prin_neg_asset.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("refinance_prin_neg_asset", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - restructure_bk_val_net_write_down
// Restructure Book Value Net Write Down                                                                                             
// Column:RESTRUCTURE_BK_VAL_NET_WRITE_DOWN
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_restructure_bk_val_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(46,"restructure_bk_val_net_write_down",t);
}



//^^^

#line 1 "restructure_bk_val_net_write_down.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("restructure_bk_val_net_write_down", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - restructure_bk_val_net_write_down_neg_asset
// Restructure Book Value Net Write Down Negative Asset                                                                                             
// Column:RESTRUCTURE_BK_VAL_NET_WRITE_DOWN_NEG_ASSET
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_restructure_bk_val_net_write_down_neg_asset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(47,"restructure_bk_val_net_write_down_neg_asset",t);
}



//^^^

#line 1 "restructure_bk_val_net_write_down_neg_asset.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("restructure_bk_val_net_write_down_neg_asset", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - restructure_cost_basis_net_write_down
// Restructure Cost Basis Net Write Down                                                                                             
// Column:RESTRUCTURE_COST_BASIS_NET_WRITE_DOWN
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_restructure_cost_basis_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(48,"restructure_cost_basis_net_write_down",t);
}



//^^^

#line 1 "restructure_cost_basis_net_write_down.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int asset_id = restructure_asset_id;

// Return if there are no restructure assets
if (asset_id < 0)
	return NO_AVG;

double aggregate_restructure_cost_basis_net_of_write_down
= seg_element->sum_over_assets("restructure_cost_basis_net_write_down", t, SUM_OVER_ALL, 
					   SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

if (fabs(aggregate_restructure_cost_basis_net_of_write_down) < model_point_amount_threshold)
	return NO_AVG;

refinance_foreclosure_restructure_cost_basis
= aggregate_restructure_cost_basis_net_of_write_down;

refinance_foreclosure_restructure_bk_val
= restructure_bk_val_net_write_down(t);

refinance_foreclosure_restructure_par
= restructure_prin_net_write_down(t);

if (asset->asset_detail_rpt_pv_defn == YES
	&& inlist(purch_assets_id[asset_id], asset->asset_detail_rpt_cusip_id)
	&& asset->asset_detail_rpt_flag(t))
	{
	PVCounter++;
	PVCText << PVCounter
			<< "--> Purchasing Restructure Assets"
			<< " ID=" << purch_assets_id[asset_id]
			<< " cost basis=" << refinance_foreclosure_restructure_cost_basis
			<< " book value=" << refinance_foreclosure_restructure_bk_val
			<< " principal=" << refinance_foreclosure_restructure_par;
	asset->asset_detail_rpt_pv_output();
	}

if (asset->asset_detail_rpt_inv_strat_defn == YES
	&& asset->asset_detail_rpt_flag(t))
	{
	seg_element->SALFile << endl;
	seg_element->SALFile << "Purchasing Restructure Assets"
				 << " period=" << t
				 << endl;
	asset_detail_rpt_buy_purch_asset(t, HEADER);
	}

if ((refinance_foreclosure_restructure_cost_basis >= 0.0
	 && refinance_foreclosure_restructure_bk_val >= 0.0
	 && refinance_foreclosure_restructure_par >= 0.0)
	||
	(refinance_foreclosure_restructure_cost_basis <= 0.0
	 && refinance_foreclosure_restructure_bk_val <= 0.0
	 && refinance_foreclosure_restructure_par <= 0.0))
	{
	buy_purch_asset_inv(t,
	                    YES, // save_assets
	                    RESTRUCTURE,
	                    asset_id, // panum
	                    refinance_foreclosure_restructure_par);
	}
else
	{
	// purchase negative asset
	refinance_foreclosure_restructure_cost_basis
	= restructure_cost_basis_net_write_down_neg_asset(t);

	refinance_foreclosure_restructure_bk_val
	= restructure_bk_val_net_write_down_neg_asset(t);

	refinance_foreclosure_restructure_par
	= restructure_prin_net_write_down_neg_asset(t);

	buy_purch_asset_inv(t,
	                    YES, // save_assets
	                    RESTRUCTURE,
	                    asset_id, // panum
	                    refinance_foreclosure_restructure_par);

	// purchase positive asset
	refinance_foreclosure_restructure_cost_basis
	= aggregate_restructure_cost_basis_net_of_write_down
	  - restructure_cost_basis_net_write_down_neg_asset(t);

	refinance_foreclosure_restructure_bk_val
	= restructure_bk_val_net_write_down(t)
	  - restructure_bk_val_net_write_down_neg_asset(t);

	refinance_foreclosure_restructure_par
	= restructure_prin_net_write_down(t)
	  - restructure_prin_net_write_down_neg_asset(t);

	buy_purch_asset_inv(t,
	                    YES, // save_assets
	                    RESTRUCTURE,
	                    asset_id, // panum
	                    refinance_foreclosure_restructure_par);
	}

if (asset->asset_detail_rpt_pv_defn == YES
	&& inlist(purch_assets_id[asset_id], asset->asset_detail_rpt_cusip_id)
	&& asset->asset_detail_rpt_flag(t))
	{
	PVCText << PVCounter
			<< "<--End,Purchase of Restructure Assets"
			<< " identifier=" << purch_assets_id[asset_id];
	asset->asset_detail_rpt_pv_output();
	PVCounter--;
	}

return aggregate_restructure_cost_basis_net_of_write_down;

}

//@@ END

//@@ START - restructure_cost_basis_net_write_down_neg_asset
// Restructure Cost Basis Net Write Down Negative Asset                                                                                             
// Column:RESTRUCTURE_COST_BASIS_NET_WRITE_DOWN_NEG_ASSET
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_restructure_cost_basis_net_write_down_neg_asset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(49,"restructure_cost_basis_net_write_down_neg_asset",t);
}



//^^^

#line 1 "restructure_cost_basis_net_write_down_neg_asset.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("restructure_cost_basis_net_write_down_neg_asset", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - restructure_prin_net_write_down
// Restructure Principal Net Write Down                                                                                             
// Column:RESTRUCTURE_PRIN_NET_WRITE_DOWN
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_restructure_prin_net_write_down(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(50,"restructure_prin_net_write_down",t);
}



//^^^

#line 1 "restructure_prin_net_write_down.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("restructure_prin_net_write_down", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - restructure_prin_net_write_down_neg_asset
// Restructure Principal Net Write Down Negative Asset                                                                                             
// Column:RESTRUCTURE_PRIN_NET_WRITE_DOWN_NEG_ASSET
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_restructure_prin_net_write_down_neg_asset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(51,"restructure_prin_net_write_down_neg_asset",t);
}



//^^^

#line 1 "restructure_prin_net_write_down_neg_asset.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

return seg_element->sum_over_assets("restructure_prin_net_write_down_neg_asset", t, SUM_OVER_ALL, 
							SUM_OVER_ALL, INVESTMENT_FUND_INDEX, BEFORE_SALE);

}

//@@ END

//@@ START - sale_planned_or_min_size_flag
// Sale Planned Or Minimum Size Flag                                                                                             
// Column:SALE_PLANNED_OR_MIN_SIZE_FLAG
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_sale_planned_or_min_size_flag(int t) {
//^^^



//^^^

#line 1 "sale_planned_or_min_size_flag.INVSTRAT_ASSET.for"
if (t <= 0)
	return NO_AVG;

int mp;
map <int, long, less <int> >::iterator mp_map_iter;

#if defined(__BOND_ASSET_H_)
for (mp_map_iter = seg_element->bond_mp_map_active.begin();
	 mp_map_iter != seg_element->bond_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;
	if (asset->sm_bond[mp][0]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if (asset->sm_bond[mp][0]->commencement_period <= t
		&& (t == asset->sm_bond[mp][0]->planned_sale_period
			|| asset->sm_bond[mp][0]->asset_min_size_sale_flag(t) == 1))
		return 1;
	}
#endif

#if defined(__MTG_ASSET_H_)
for (mp_map_iter = seg_element->mtg_mp_map_active.begin();
	 mp_map_iter != seg_element->mtg_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;
	if ((t > asset->sm_mtg[mp][0]->commencement_period 
		// allow for inclusion of restructure, foreclosure, refinance assets
		&& asset->sm_mtg[mp][0]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD))
		continue;

	if (asset->sm_mtg[mp][0]->commencement_period <= t
		&& (t == asset->sm_mtg[mp][0]->planned_sale_period
			|| asset->sm_mtg[mp][0]->asset_min_size_sale_flag(t) == 1))
		return 1;
	}
#endif

#if defined(__SEC_ASSET_H_)
for (mp_map_iter = seg_element->sec_mp_map_active.begin();
	 mp_map_iter != seg_element->sec_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;
	if (asset->sm_sec[mp]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if (asset->sm_sec[mp]->commencement_period <= t
		&& (t == asset->sm_sec[mp]->planned_sale_period
			|| asset->sm_sec[mp]->asset_min_size_sale_flag(t) == 1))
		return 1;
	}
#endif

#if defined(__IRD_ASSET_H_)
for (mp_map_iter = seg_element->ird_mp_map_active.begin();
	 mp_map_iter != seg_element->ird_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;
	if (asset->sm_ird[mp][0]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if (asset->sm_ird[mp][0]->commencement_period <= t
		&& (t == asset->sm_ird[mp][0]->planned_sale_period
			|| asset->sm_ird[mp][0]->asset_min_size_sale_flag(t) == 1))
		return 1;
	}
#endif

#if defined(__EQT_ASSET_H_)
for (mp_map_iter = seg_element->eqt_mp_map_active.begin();
	 mp_map_iter != seg_element->eqt_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;
	if (asset->sm_eqt[mp]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if (asset->sm_eqt[mp]->commencement_period <= t
		&& (t == asset->sm_eqt[mp]->planned_sale_period
			|| asset->sm_eqt[mp]->asset_min_size_sale_flag(t) == 1))
		return 1;
	}
#endif

#if defined(__RE_ASSET_H_)
for (mp_map_iter = seg_element->re_mp_map_active.begin();
	 mp_map_iter != seg_element->re_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;
	if (asset->sm_re[mp]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if (asset->sm_re[mp]->commencement_period <= t
		&& (t == asset->sm_re[mp]->planned_sale_period
			|| asset->sm_re[mp]->asset_min_size_sale_flag(t) == 1))
		return 1;
	}
#endif

#if defined(__EIO_ASSET_H_)
for (mp_map_iter = seg_element->eio_mp_map_active.begin();
	 mp_map_iter != seg_element->eio_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;
	if (asset->sm_eio[mp][0]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if (asset->sm_eio[mp][0]->commencement_period <= t
		&& (t == asset->sm_eio[mp][0]->planned_sale_period
			|| asset->sm_eio[mp][0]->asset_min_size_sale_flag(t) == 1))
		return 1;
	}
#endif

#if defined(__EPA_ASSET_H_)
for (mp_map_iter = seg_element->epa_mp_map_active.begin();
	 mp_map_iter != seg_element->epa_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;
	if (asset->sm_epa[mp]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if (t == asset->sm_epa[mp]->planned_sale_period
		|| asset->sm_epa[mp]->asset_min_size_sale_flag(t) == 1)
		return 1;
	}
#endif

return 0;

}

//@@ END

//@@ START - sale_possible_imr_avr_flag
// Sale Possible Interest Maintenance Reserve Asset Valuation Reserve Flag                                                                                             
// Column:SALE_POSSIBLE_IMR_AVR_FLAG
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_sale_possible_imr_avr_flag(int t) {
//^^^



//^^^

#line 1 "sale_possible_imr_avr_flag.INVSTRAT_ASSET.for"
if (!alm_flag || t <= 0)
	return NO_AVG;

if (imr_flag || avr_flag)
	return 1;

if (fabs(cash_flow_planned_sale(t)) > aggregate_amount_threshold)
	return 1;

if (fabs(cash_flow_hedge_sale(t)) > aggregate_amount_threshold)
	return 1;

// Ensure negative cash flow strategy for period is selected
neg_cash_flow_strat_set(t);

if (neg_cash_flow_strat == SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE
	&& (asset->mths_to_asset_sale(t) == 0
		|| asset->mkt_val_calc_freq_sale == WHENEVER_NEEDED))
	return 1;

seg_id = seg_id;
StrEnum::EnumValue rebal_freq_local = rebal_freq;

if (rebal_freq_local != NOT_APPLICABLE
	&& mths_to_rebal(t) == 0)
	return 1;

if (dur_match_flag(t))
	return 1;

return 0;

}

//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double INVSTRAT_ASSET_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.INVSTRAT_ASSET.for"
#if 0 // START_EXTERNS
extern ofstream& PVCFile;
extern ostringstream PVCText;
extern int pv_asset_defn;
extern int pv_model_point;
extern int PVCounter;

// yield maintenance detail file
extern ofstream& YMFile; 

#if defined(__SEC_ASSET_H_)
extern int pv_cp_asset_defn;
extern int pv_cp_model_point;
#endif

sowmpoutput bond_state_of_world_header_mp_output;
sowmpoutput mtg_state_of_world_header_mp_output;
sowmpoutput sec_state_of_world_header_mp_output;
sowmpoutput ird_state_of_world_header_mp_output;
sowmpoutput re_state_of_world_header_mp_output;
sowmpoutput eqt_state_of_world_header_mp_output;
sowmpoutput eio_state_of_world_header_mp_output;
sowmpoutput epa_state_of_world_header_mp_output;
#endif // END_EXTERNS

#if 0 // START_CLASS
int prior_strategy_selected_t;
int prior_strategy_set_t;
StrEnum::EnumValue prior_strategy_type;

int prior_neg_cash_flow_strategy_selected_t;
int prior_neg_cash_flow_strategy_set_t;
StrEnum::EnumValue prior_neg_cash_flow_strategy_type;

StrEnum::EnumValue asset_sub_port_distribn_defn;
StrEnum::EnumValue dur_match_processing_alt_strat;
double refinance_foreclosure_restructure_par;
double refinance_foreclosure_restructure_cost_basis;
double refinance_foreclosure_restructure_bk_val;
double cash_tgt_pct;
double asset_sub_port_inv_tgt_pct_sum;
double dur_match_tgt_incr;
double dur_match_tolerance_incr;
double expected_sold_at_bk;
double expected_mkt_val_for_dur_purch;
double expected_mkt_val_for_dur_sale;
double expected_mkt_val_times_dur_purch;
double expected_mkt_val_times_dur_sale;
xstring inv_strat_current;
xstring inv_strat_neg;
xstring inv_strat_shorter;
xstring inv_strat_shortest;
xstring inv_strat_longer;
xstring inv_strat_longest;
SmartArray <int> neg_cash_flow_sale_class_priority;
int neg_cash_flow_sales_priority_class_max;
SmartArray <int> rebal_sale_class_priority;
SmartArray <int> asset_class_to_sell_flag;
SmartArray <int> asset_fund_to_sell_flag;

// Purchase assets arrays (indexed by purchase asset num)
SmartArray <StrEnum::EnumValue> purch_assets_type;
SmartArray <xstring> purch_assets_id;
SmartArray <xstring> purch_assets_mp_grp_tag;
SmartArray <int> purch_assets_mp_num;
SmartArray <int> purch_assets_cp_num;
SmartArray <int> purch_assets_port_defn;
SmartArray <int> purch_assets_asset_sub_port_num;
SmartArray <double> purch_assets_weight;
SmartArray <int> purch_assets_dur_defn;
SmartArray <int> purch_assets_dur_calculated;
SmartArray <double> purch_assets_dur;
SmartArray <int> purch_assets_sub_port_num_current_strat;
SmartArray <double> purch_assets_weight_current_strat;
SmartArray <int> purch_assets_sub_port_num_alt_strat;
SmartArray <double> purch_assets_weight_alt_strat;
SmartArray <int> purch_assets_mths_to_maturity;
SmartArray <SmartArray <double> > sub_port_fund_expected_book_plus_accrued_sold;

int purch_asset_max_num;
bool initialize_purch_asset_maps;

// Initial sales and investment amount variables
SmartArray <SmartArray <double> > sub_port_fund_initial_book_plus_accrued;
SmartArray <SmartArray <SmartArray <int> > > sub_port_class_fund_assets_present;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_initial_accrued_interest;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_initial_book_value;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_initial_market_value;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_initial_unrealized_capital_gains;
// Sales amount variables
SmartArray <SmartArray <double> > sub_port_fund_book_plus_accrued_sold;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_accrued_interest_sold;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_book_value_sold;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_market_value_sold;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_unrealized_capital_gains_released;
// Purchase amount variables
SmartArray <SmartArray <double> > sub_port_fund_book_plus_accrued_purchases;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_accrued_interest_purchases;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_book_value_purchases;
// Sales processing maps and multimaps
map <int, int, less<int> > market_values_not_calculated_for_asset_sub_port_map;
multimap <pair<double,double>, pair<int,int>, less<pair<double,double> > > extreme_value_multimap;

StrEnum::EnumValue display_rebal_sales_header;

// Purchase asset map
map <xstring, int, less<xstring> > purchmap_investment;
map <xstring, int, less<xstring> > purchmap_hedging; // for eio hedges

// Investment strategy map
map <xstring, int, less<xstring> > stratmap_inv;

// Purchase asset id vectors
vector <string> purch_bond_assets;
vector <string> purch_mtg_assets;
vector <string> purch_sec_assets;
vector <string> purch_ird_assets;
vector <string> purch_re_assets;
vector <string> purch_eqt_assets;
vector <string> purch_eio_assets;

A_SUBPORT_ASSET * current_sub_port;
A_SUBPORT_ASSET * a_subport_element;

SEG_COMP *seg_element;

#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
asset_sub_port_distribn_defn = CASH;
dur_match_processing_alt_strat = NO;
refinance_foreclosure_restructure_par = 0.0;
refinance_foreclosure_restructure_cost_basis = 0.0;
refinance_foreclosure_restructure_bk_val = 0.0;
cash_tgt_pct = 0.0;
asset_sub_port_inv_tgt_pct_sum = 0.0;
dur_match_tgt_incr = 0.0;
dur_match_tolerance_incr = 0.0;
expected_sold_at_bk = 0.0;
expected_mkt_val_for_dur_purch = 0.0;
expected_mkt_val_for_dur_sale = 0.0;
expected_mkt_val_times_dur_purch = 0.0;
expected_mkt_val_times_dur_sale = 0.0;
inv_strat_current = "NONE";
inv_strat_shorter = "NONE";
inv_strat_shortest = "NONE";
inv_strat_longer = "NONE";
inv_strat_longest = "NONE";
purch_asset_max_num = 0;
initialize_purch_asset_maps = true;
neg_cash_flow_sales_priority_class_max = 0;

prior_strategy_selected_t = 0;
prior_strategy_set_t = 0;
prior_strategy_type = UNDEFINED;

prior_neg_cash_flow_strategy_selected_t = 0;
prior_neg_cash_flow_strategy_set_t = 0;
prior_neg_cash_flow_strategy_type = UNDEFINED;

#endif // END_CONSTRUCTOR

#if 0 // START_TERMINATOR
bond_state_of_world_header_mp_output.close();
mtg_state_of_world_header_mp_output.close();
sec_state_of_world_header_mp_output.close();
ird_state_of_world_header_mp_output.close();
re_state_of_world_header_mp_output.close();
eqt_state_of_world_header_mp_output.close();
eio_state_of_world_header_mp_output.close();
epa_state_of_world_header_mp_output.close();
PVCFile.close();
YMFile.close();
#endif // END_TERMINATOR

gen2_declarations;
display_rebal_sales_header = NO;

return 1.0;

}

//@@ END

//@@ START - use_dur_match_strat
// Use Duration Matching Strategy                                                                                             
// Column:USE_DUR_MATCH_STRAT
//========================================================
double INVSTRAT_ASSET_UDF::invstrat_asset_use_dur_match_strat(int t) {
//^^^



//^^^

#line 1 "use_dur_match_strat.INVSTRAT_ASSET.for"
if (!dur_match_flag(t) || t <= 0)
	return NO_AVG;

double dur_based_on_current_strat = 0.0;
double cash_flow_bef_rebal_sales = 0.0;
double rebal_sales_cash_flow = 0.0;
double cash_flow_for_inv = 0.0;
int rebal_sales_completed = NO;
bool warnings = false;

initialize_sale_and_inv_vars_eom(t);

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	seg_element->SALFile << endl;
	seg_element->SALFile << "Duration Matching Investment Strategy Determination"
				 << " (Period=" << t << " "
				 << " Year=" << xint(cal_yr(t))
				 << " Month=" << xint(cal_mth(t))
				 << ")"
				 << endl;
	seg_element->SALFile << "Strategy Set Information:" << endl;
	seg_element->SALFile << "Current," << inv_strat_current << endl;
	seg_element->SALFile << "Negative," << inv_strat_neg << endl;
	seg_element->SALFile << "AltShorter," << inv_strat_shorter << endl;
	seg_element->SALFile << "AltShortest," << inv_strat_shortest << endl;
	seg_element->SALFile << "AltLonger," << inv_strat_longer << endl;
	seg_element->SALFile << "AltLongest," << inv_strat_longest << endl;
	seg_element->SALFile << "Target," << dur_match_tgt(t) << endl;
	seg_element->SALFile << "Tolerance," << dur_match_tolerance(t) << endl;
	seg_element->SALFile << "Targ+Tol," << dur_match_tgt(t) + dur_match_tolerance(t) << endl;
	seg_element->SALFile << "Targ-Tol," << dur_match_tgt(t) - dur_match_tolerance(t) << endl;
	}

for (int panum = 0; panum < purch_asset_max_num; panum++)
	{
	purch_assets_dur_calculated[panum] = NO;
	purch_assets_dur[panum] = 0.0;
	}

// Force call for reporting
dur_bef_match(t);

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	seg_element->SALFile << "Duration Before Duration Matching =," << dur_bef_match(t) << ","
				 << "= [ " << setprecision(2) << mkt_val_times_dur_bef_dur_match(t)
				 << " / " << setprecision(2) << mkt_val_for_dur_bef_dur_match(t)
				 << " ]"
				 << endl;
	}

// Initialize the current strategy
inv_strat_select(t, CURRENT, DO_NOT_ISSUE_WARNINGS, warnings);

cash_flow_bef_rebal_sales = cash_flow_for_inv_bef_rebal(t);

seg_id = seg_id;
StrEnum::EnumValue rebal_dur_match_defn_local = rebal_dur_match_defn;

if (rebal_dur_match_defn_local == NO)
	{
	rebal_sales_cash_flow = cash_flow_rebal(t);	
	rebal_sales_completed = YES;
	}
else
	rebal_sales_cash_flow = cash_flow_rebal_estimate(t);

cash_flow_for_inv = cash_flow_bef_rebal_sales + rebal_sales_cash_flow;

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	seg_element->SALFile << "Estimated Cash Flow For Investment" << endl;
	seg_element->SALFile << setprecision(2);
	seg_element->SALFile << "CashFlowForInvBefRebal," << setw(12) << cash_flow_bef_rebal_sales << endl;
	seg_element->SALFile << (rebal_sales_completed == YES
				 ? " (+) RebalSalesNetCashFlow,"
				 : " (+) EstimatedRebalSalesNetCashFlow,")
				 << setw(12) << rebal_sales_cash_flow << endl;
	seg_element->SALFile << ",--------------" << endl;
	seg_element->SALFile << "CashFlowForInv," << setw(12) << cash_flow_for_inv << endl;
	seg_element->SALFile << setprecision(6);
	}

if (cash_flow_for_inv < 0.0)
	{
	if (asset->asset_detail_rpt_inv_strat_flag(t))
		seg_element->SALFile << " ... <<<< DM - Negative Strategy Selected >>>> "
				 << endl;

	return NO_AVG;
	}

// Current strategy produced positive cash flows;
// Determine duration estimate for current strategy
if (asset->asset_detail_rpt_inv_strat_flag(t))
	seg_element->SALFile << " ... Duration Estimate For Current Strategy"
				 << endl;

dur_based_on_current_strat
= asset_dur_estimate(t, cash_flow_for_inv);

if (fabs(dur_based_on_current_strat
		 - dur_match_tgt(t))
	 <= dur_match_tolerance(t))
	{
	// Selected current strategy
	if (asset->asset_detail_rpt_inv_strat_flag(t))
		seg_element->SALFile << " ... <<<< DM - Current Strategy Selected. >>>>"
					 << endl;

	inv_strat_select(t, CURRENT, DO_NOT_ISSUE_WARNINGS, warnings);
	}
else // Current strategy outside of tolerance, attempt to change the duration
	{
	if (dur_based_on_current_strat
		 > (dur_match_tgt(t)
			+ dur_match_tolerance(t)))
		dur_match_decr_dur(t,
		                   rebal_sales_completed,
		                   dur_based_on_current_strat);
	else
		dur_match_incr_dur(t,
		                   rebal_sales_completed,
		                   dur_based_on_current_strat);
	}

return 1.0;

}

//@@ END

//@@ START - final_period
// Final Period                                                                                             
// Calculated Variable:FINAL_PERIOD
//========================================================
int INVSTRAT_ASSET_UDF::invstrat_asset_final_period() {
//^^^


#line 1 "final_period.INVSTRAT_ASSET.for"
return last_proj_period;

}

//@@ END

//@@ START - foreclosure_asset_id
// Foreclosure Asset Identification                                                                                             
// Calculated Variable:FORECLOSURE_ASSET_ID
//========================================================
int INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_asset_id() {
//^^^


#line 1 "foreclosure_asset_id.INVSTRAT_ASSET.for"
if (foreclosure_inv_id.length() == 0
	|| foreclosure_inv_id == "NONE")
	return -1;

xstring purchmap_index = "Mortgage:" + foreclosure_inv_id;

map <xstring, int, less<xstring> >::iterator purchmap_iter;
if ((purchmap_iter = purchmap_investment.find(purchmap_index)) != purchmap_investment.end())
	return purchmap_iter->second;

if (is_first_proj_task_loop)
	{
	log_screen << "Warning: Unrecognized foreclosure_inv_id '"
			   << foreclosure_inv_id
			   << "'. Foreclosure assets cannot be purchased."
		   	   << MSG_ERROR;
	}

return -1;

}

//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring INVSTRAT_ASSET_UDF::invstrat_asset_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.INVSTRAT_ASSET.for"
return add_mths_to_date(proj_date, valn_period);

}

//@@ END

//@@ START - proj_start_date
// Projection Start Date                                                                                             
// Calculated Variable:PROJ_START_DATE
//========================================================
int INVSTRAT_ASSET_UDF::invstrat_asset_proj_start_date() {
//^^^


#line 1 "proj_start_date.INVSTRAT_ASSET.for"
return day_number_from_date(proj_start_yr, proj_start_mth, 1);

}

//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int INVSTRAT_ASSET_UDF::invstrat_asset_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.INVSTRAT_ASSET.for"
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
int INVSTRAT_ASSET_UDF::invstrat_asset_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.INVSTRAT_ASSET.for"
int proj_mth = get_mth_from_date(proj_date_adj);

if (proj_mth == 12)
	return get_yr_from_date(proj_date_adj) + 1;
	
return get_yr_from_date(proj_date_adj);

}

//@@ END

//@@ START - rebal_sales_priority_class_max
// Rebalance Sales Priority Class Maximum                                                                                             
// Calculated Variable:REBAL_SALES_PRIORITY_CLASS_MAX
//========================================================
int INVSTRAT_ASSET_UDF::invstrat_asset_rebal_sales_priority_class_max() {
//^^^


#line 1 "rebal_sales_priority_class_max.INVSTRAT_ASSET.for"
seg_id = seg_id;
int rebal_sale_priority_not_assigned_local = rebal_sale_priority_not_assigned;
seg_id = seg_id;
int rebal_sale_priority_avail_for_sale_local = rebal_sale_priority_avail_for_sale;
seg_id = seg_id;
int rebal_sale_priority_trading_local = rebal_sale_priority_trading;
seg_id = seg_id;
int rebal_sale_priority_held_to_maturity_local = rebal_sale_priority_held_to_maturity;

return max(rebal_sale_priority_not_assigned_local,
			max(rebal_sale_priority_avail_for_sale_local,
				max(rebal_sale_priority_trading_local,
					max(rebal_sale_priority_held_to_maturity_local, 1))));

}

//@@ END

//@@ START - refinance_asset_id
// Refinance Asset Identification                                                                                             
// Calculated Variable:REFINANCE_ASSET_ID
//========================================================
int INVSTRAT_ASSET_UDF::invstrat_asset_refinance_asset_id() {
//^^^


#line 1 "refinance_asset_id.INVSTRAT_ASSET.for"
if (refinance_inv_id.length() == 0
	|| refinance_inv_id == "NONE")
	return -1;

xstring purchmap_index = "Mortgage:" + refinance_inv_id;

map <xstring, int, less<xstring> >::iterator purchmap_iter;
if ((purchmap_iter = purchmap_investment.find(purchmap_index)) != purchmap_investment.end())
	return purchmap_iter->second;

if (is_first_proj_task_loop)
	{
	log_screen << "Warning: Unrecognized refinance_inv_id '"
			   << refinance_inv_id
			   << "'. Refinance assets cannot be purchased."
			   << MSG_ERROR;
	}

return -1;

}

//@@ END

//@@ START - restructure_asset_id
// Restructure Asset Identification                                                                                             
// Calculated Variable:RESTRUCTURE_ASSET_ID
//========================================================
int INVSTRAT_ASSET_UDF::invstrat_asset_restructure_asset_id() {
//^^^


#line 1 "restructure_asset_id.INVSTRAT_ASSET.for"
if (restructure_inv_id.length() == 0
	|| restructure_inv_id == "NONE")
	return -1;

xstring purchmap_index = "Mortgage:" + restructure_inv_id;

map <xstring, int, less<xstring> >::iterator purchmap_iter;
if ((purchmap_iter = purchmap_investment.find(purchmap_index)) != purchmap_investment.end())
	return purchmap_iter->second;

if (is_first_proj_task_loop)
	{
	log_screen << "Warning: Unrecognized restructure_inv_id '"
			   << restructure_inv_id
			   << "'. Restructure assets cannot be purchased."
			   << MSG_ERROR;
	}

return -1;

}

//@@ END

//@@ START - sales_priority_sub_port_max
// Sales Priority Sub Portfolio Maximum                                                                                             
// Calculated Variable:SALES_PRIORITY_SUB_PORT_MAX
//========================================================
int INVSTRAT_ASSET_UDF::invstrat_asset_sales_priority_sub_port_max() {
//^^^


#line 1 "sales_priority_sub_port_max.INVSTRAT_ASSET.for"
int local_max = 0;
int sub_port_max = 0;
int sub_port = 0;

for (sub_port = 0; sub_port < asset->sm_asset_sub_port[seg_num].size(); sub_port++)
	{
	sub_port_max = asset->sm_asset_sub_port[seg_num][sub_port][0]->sale_priority;
	if (local_max < sub_port_max)
		local_max = sub_port_max;
	}

return local_max;

}

//@@ END

//@@ START - seg_num
// Segment Number                                                                                             
// Calculated Variable:SEG_NUM
//========================================================
int INVSTRAT_ASSET_UDF::invstrat_asset_seg_num() {
//^^^


#line 1 "seg_num.INVSTRAT_ASSET.for"
// The segment number is the element number of the inv_strategy array
return getElementNumber();

}

//@@ END

//@@ START - start_period
// Start Period                                                                                             
// Calculated Variable:START_PERIOD
//========================================================
int INVSTRAT_ASSET_UDF::invstrat_asset_start_period() {
//^^^


#line 1 "start_period.INVSTRAT_ASSET.for"
return 0;

}

//@@ END


#line 1 "accumulate_asset_sale.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::accumulate_asset_sale(int sub_port_number, int sale_class, int fund_index, double bk_val_sold, double accr_int_sold, double mkt_val_sold, double unrealized_capital_gains_released)
{
sub_port_fund_book_plus_accrued_sold[sub_port_number][fund_index]
+= bk_val_sold + accr_int_sold;

sub_port_class_fund_accrued_interest_sold[sub_port_number][sale_class][fund_index]
+= accr_int_sold;
sub_port_class_fund_book_value_sold[sub_port_number][sale_class][fund_index]
+= bk_val_sold;
sub_port_class_fund_market_value_sold[sub_port_number][sale_class][fund_index]
+= mkt_val_sold;
sub_port_class_fund_unrealized_capital_gains_released[sub_port_number][sale_class][fund_index]
+= unrealized_capital_gains_released;

return;
}



#line 1 "asset_detail_rpt_buy_purch_asset.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::asset_detail_rpt_buy_purch_asset(int t, StrEnum::EnumValue option, int sequence_id , const xstring &identifier , int sub_port_num , const xstring &sales_class , const xstring &asset_fund , double neg_asset_flag , double notional_amt , double mkt_val , double cost_basis , double bk_val , double yrs_to_maturity , double weighted_avg_life , double eff_dur )
{
// This function handles individual asset sales output for the rebalancing detail report.
// Valid option values are "Header", "Purchased", "Virtual Purchase", "Not Purchased"
// Note: asset_fund is portfolio definition for purchase types other than "Purchased"

if (option == HEADER)
	{
	seg_element->SALFile << endl;
	seg_element->SALFile << "AssetID,SubPortID,SalesClass,AssetFund,NotionalAmt,MarketValue,CostBasis,BookValue,YrsToMat,WAL,EffDur " << endl;
	return;
	}

if (option == PURCHASED)
	{
	seg_element->SALFile << identifier << ","
				 << asset->sm_asset_sub_port[seg_num][sub_port_num][0]->sub_port_id << ","
				 << sales_class << ","
				 << asset_fund << ","
				 << notional_amt * neg_asset_flag << ","
				 << mkt_val * neg_asset_flag << ","
				 << cost_basis * neg_asset_flag << ","
				 << bk_val * neg_asset_flag << ","
				 << yrs_to_maturity << ","
				 << weighted_avg_life << ","
				 << eff_dur << endl;

	return;
	}

// asset_fund is asset purpose for all other purchase types
xstring asset_fund_code;
if (asset_fund == "Investment")
	asset_fund_code = asset->zAssetFund[INVESTMENT_FUND_INDEX];
else if (asset_fund == "Hedge")
	asset_fund_code = asset->zAssetFund[HEDGING_FUND_INDEX];
else
	asset_fund_code = "??";

if (option == VIRTUAL_PURCHASE)
	{
	if (sequence_id > 0)
		seg_element->SALFile << sequence_id;
	else
		seg_element->SALFile << "v";
	
	seg_element->SALFile << identifier << ","
				 << asset->sm_asset_sub_port[seg_num][sub_port_num][0]->sub_port_id << ","
				 << ","				// sales_class_num
				 << asset_fund_code << ","
				 << ","	// notional_amt
				 << bk_val << ","	// mkt_val
				 << bk_val << ","	// cost_basis
				 << bk_val << ","
				 << ","		// yrs_to_maturity
				  << "," // weighted_avg_life
				 << eff_dur << endl;

	return;
	}

if (option == NOT_PURCHASED)
	{
	if (sequence_id > 0)
		seg_element->SALFile << sequence_id;
	else
		seg_element->SALFile << "v";
	
	seg_element->SALFile << identifier << ","
				 << asset->sm_asset_sub_port[seg_num][sub_port_num][0]->sub_port_id << ","
				 << "," // sales_class_num
				 << " " << asset_fund_code
				 << ","	// notional_amt
				 << ","	// mkt_val
				 << ","	// cost_basis
				 << bk_val << ","
				 << "," // yrs_to_maturity
				 << ","	// weighted_avg_life
				 << "," // eff_dur
				 << endl;

	return;
	}

return;
}



#line 1 "asset_detail_rpt_individual_sale.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::asset_detail_rpt_individual_sale(int t, StrEnum::EnumValue option, int sequence_id , const xstring &identifier , int sub_port_num , int sales_class_num , int asset_fund_index , double percent_of_asset_to_sell , double net_cash_from_asset_sale , double bk_val_sold , double accr_int_sold , double mkt_val_sold , double capital_gain , double unrealized_capital_gains_released , double dur_val )
{
// this function handles individual asset sales output for the rebalancing detail report
//
// valid option values are "Header", "Asset Data"

if (option == HEADER)
	{
	seg_element->SALFile << "AssetID,Sub_Port,C,Fn,Pct-Sold,NetCsh,BV-Sold,AI-Sold,MV-Sold,Cap-Gain,Unreal-CG,DurMeas" << endl;
	return;
	}

seg_element->SALFile << identifier << ","
			 << sub_port_num << ","
			 << sales_class_num << ","
			 << seg_element->zAssetFund[asset_fund_index] << ","
			 << percent_of_asset_to_sell << ","
			 << net_cash_from_asset_sale << ","
			 << bk_val_sold << ","
			 << accr_int_sold << ","
			 << mkt_val_sold << ","
			 << capital_gain << ","
			 << unrealized_capital_gains_released << ","
			 << dur_val << endl;

return;
}



#line 1 "asset_detail_rpt_sub_port_class_tgt_summary.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::asset_detail_rpt_sub_port_class_tgt_summary(int t)
{
// summarize sub portfolios & sales classes amounts before rebalancing
if(fabs(investable_assets_bef_rebal(t)) > 1.0)
	{
	double asd_sub_port_class_book_plus_accrued;
	double old_sub_port_class_book_plus_accrued;
	int turnover_rate_freq;
	int sploop;
	int clloop;
	int fndx;
	bool is_book = (asset_sub_port_distribn_defn == BOOK);

	double other_investable_assets_including_cash = investable_assets_bef_rebal(t);

	if (is_book)
		seg_element->SALFile << endl << "Sub_Port,C,BV+AI,Percent,Target,Tolerance,MaxTrnovr,MinTrnovr" << endl;
	else
		seg_element->SALFile << endl << "Sub_Port,C,MV+AI,Percent,Target,Tolerance,MaxTrnovr,MinTrnovr " << endl;

	seg_id = seg_id;
	StrEnum::EnumValue rebal_freq_local = rebal_freq;

	if (rebal_freq_local == QUARTERLY
		|| (rebal_freq_local == AT_ASSET_FREQUENCY
			&& asset->mkt_val_calc_freq == QUARTERLY))
		turnover_rate_freq = 4;
	else if (rebal_freq_local == SEMIANNUALLY
			 || (rebal_freq_local == AT_ASSET_FREQUENCY
				 && asset->mkt_val_calc_freq == SEMIANNUALLY))
		turnover_rate_freq = 2;
	else
		turnover_rate_freq = 1;

	for (sploop = 0; sploop < asset->sm_asset_sub_port[seg_num].size(); sploop++)
		{
		
		for (clloop = 1; clloop <= MAXIMUM_NUMBER_OF_SALES_CLASSES; clloop++)
			{
			asd_sub_port_class_book_plus_accrued = 0.0;
			if (is_book)
				for (fndx = 0; fndx < MAXIMUM_NUMBER_OF_ASSET_FUNDS; fndx++)
					asd_sub_port_class_book_plus_accrued
					+= sub_port_class_fund_initial_book_value[sploop][clloop][fndx]
					   + sub_port_class_fund_initial_accrued_interest[sploop][clloop][fndx];
			else
				for (fndx = 0; fndx < MAXIMUM_NUMBER_OF_ASSET_FUNDS; fndx++)
					asd_sub_port_class_book_plus_accrued
					+= sub_port_class_fund_initial_market_value[sploop][clloop][fndx]
					   + sub_port_class_fund_initial_accrued_interest[sploop][clloop][fndx];

			if (fabs(asd_sub_port_class_book_plus_accrued) > 0.01)
				{
				other_investable_assets_including_cash -= asd_sub_port_class_book_plus_accrued;

				seg_element->SALFile << sploop << ","
							 << clloop << ","
							 << asd_sub_port_class_book_plus_accrued << ","
							 << asd_sub_port_class_book_plus_accrued / investable_assets_bef_rebal(t) << ","
							 << asset->sm_asset_sub_port[seg_num][sploop][0]->inv_tgt_pct * (1.0 - cash_tgt_pct) << ","
							 << asset->sm_asset_sub_port[seg_num][sploop][0]->rebal_tolerance_pct << ","
							 << min(1.0, asset->sm_asset_sub_port[seg_num][sploop][0]->rebal_annual_turnover_pct_max / turnover_rate_freq) << ","
							 << min(1.0, asset->sm_asset_sub_port[seg_num][sploop][0]->rebal_annual_turnover_pct_min / turnover_rate_freq) << endl;
				}
			} // end_for on clloop
		} // end_for on sploop

	seg_element->SALFile << "other,,"
				 << other_investable_assets_including_cash << ","
				 << ((fabs(investable_assets_bef_rebal(t)) <= 1.0)
					? (0.0) : (other_investable_assets_including_cash / investable_assets_bef_rebal(t)))
				 << endl;
	}

return;
}



#line 1 "asset_detail_rpt_tgt_pct_by_sub_port.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::asset_detail_rpt_tgt_pct_by_sub_port(int t, const xstring &standard, double asd_cash_for_investment, double asd_assets_other_than_cash, double distance_below_target_allocation, double distance_above_target_allocation, SmartArray <double> &sub_port_book_plus_accrued)
{
int sploop = 0;
double asd_actual_percent = 0;
double asd_target_allocation_distance = 0;
double asd_investment_allocation = 0;
double asd_sum_of_investment_allocations = 0;
double asd_investment_strategy_sub_port_percent = 0;

seg_element->SALFile << "SubPortID,Book+Acc,TgtPct,PosAssetActPct,InvAlloc,SumInvAlloc" << endl;

for (sploop = 0; sploop < asset->sm_asset_sub_port[seg_num].size(); sploop++)
	{
	if (standard == "Investment")
		asd_investment_strategy_sub_port_percent
		= asset->sm_asset_sub_port[seg_num][sploop][0]->inv_tgt_pct
		  * asset->sm_asset_sub_port[seg_num][sploop][0]->purch_asset_weight_sum_normalzd;
	
	if (asd_assets_other_than_cash != 0.0)
		asd_actual_percent
		= sub_port_book_plus_accrued [sploop]
		  / asd_assets_other_than_cash;
	else
		asd_actual_percent = 0.0;

	if (asd_cash_for_investment < 0.0)
		asd_target_allocation_distance
		= distance_above_target_allocation;
	else
		asd_target_allocation_distance
		= distance_below_target_allocation;

	if (asd_target_allocation_distance != 0.0)
		asd_investment_allocation
		= asd_cash_for_investment
		  * max(asd_investment_strategy_sub_port_percent - asd_actual_percent, 0.0)
		  / asd_target_allocation_distance;
	else
		asd_investment_allocation = 0.0;

	asd_sum_of_investment_allocations
	= asd_sum_of_investment_allocations
	  + asd_investment_allocation;

	if (asd_investment_strategy_sub_port_percent > 0.0)
		seg_element->SALFile << asset->sm_asset_sub_port[seg_num][sploop][0]->sub_port_id << "," 
					 << sub_port_book_plus_accrued[sploop] << "," 
					 << asd_investment_strategy_sub_port_percent << "," 
					 << asd_actual_percent << "," 
					 << asd_investment_allocation << "," 
					 << asd_sum_of_investment_allocations << endl;
	}

return;
}



#line 1 "asset_dur_estimate.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::asset_dur_estimate(int t, double cash_flow_for_inv)
{
double duration_numerator = 0;
double duration_denominator = 0;
double duration_based_on_current_strategy = 0;
double investable_assets = 0;
double net_liabilities_for_cash_balance_threshold = 0;
double cash_balance_base = 0;
double cash_thresh = 0; 
double cash_incr = 0;
double cash_flow_for_asset_purch = 0;
int asset_sub_port = 0;
int fund_index = 0;

seg_id = seg_id;
StrEnum::EnumValue rebal_dur_match_defn_local = rebal_dur_match_defn;

if (rebal_dur_match_defn_local == NO)
	{
	for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
		for (fund_index = 0; fund_index < MAXIMUM_NUMBER_OF_ASSET_FUNDS; fund_index++)
			investable_assets
			+= sub_port_fund_initial_book_plus_accrued[asset_sub_port][fund_index]
			   - sub_port_fund_book_plus_accrued_sold[asset_sub_port][fund_index];
	}
else // if (rebal_for_dur_match_defn == DURATION_MATCHING_STRATEGY)
	{
	for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
		for (fund_index = 0; fund_index < MAXIMUM_NUMBER_OF_ASSET_FUNDS; fund_index++)
			investable_assets
			+= sub_port_fund_initial_book_plus_accrued[asset_sub_port][fund_index];
	
	investable_assets -= expected_sold_at_bk;
	}

investable_assets
+= cash(t - 1)
   + cash_flow_for_inv;

cash_balance_base = investable_assets;

// Ensure negative cash flow strategy for period is selected
neg_cash_flow_strat_set(t);

if (neg_cash_flow_strat == BORROW)
	cash_thresh = -USLIB_MAX_DOUBLE;

else if (neg_cash_flow_cash_bal_defn == REDUCE_CASH_BALANCE_TO_THRESHOLD )
	cash_thresh
	= min(cash_balance_base
		   * neg_cash_flow_cash_thresh_pct
		   + neg_cash_flow_cash_thresh_addn,
		  investable_assets
		   * cash_tgt_pct);

else if (neg_cash_flow_cash_bal_defn == BORROW_TO_THRESHOLD)
	cash_thresh
	= - cash_balance_base
		* neg_cash_flow_cash_thresh_pct
	  - neg_cash_flow_cash_thresh_addn;

else if (neg_cash_flow_cash_bal_defn == TARGETED_CASH_BALANCE)
	cash_thresh
	= investable_assets
	  * cash_tgt_pct;

if (cash_flow_for_inv >= 0
	|| (cash_flow_for_inv < 0
		&& (neg_cash_flow_strat == BORROW
			|| (asset->mths_to_asset_sale(t) > 0
				&& neg_cash_flow_strat == SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE))))
	cash_incr
	= min(cash_flow_for_inv,
		  investable_assets
		   * cash_tgt_pct + seg_element->opt_payoff_crbg(t) //20250527 CRBG logic
		   - cash(t - 1));

else if (cash_flow_for_inv < 0
		 && (neg_cash_flow_cash_bal_defn == TARGETED_CASH_BALANCE)
		 && (neg_cash_flow_strat == NEGATIVE_ASSETS
			 || (asset->mths_to_asset_sale(t) == 0
				 && neg_cash_flow_strat == SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE)))
	cash_incr
	= min(0.0,
	      investable_assets
		  * cash_tgt_pct
		  - cash(t - 1));

else if (cash_flow_for_inv < 0
		 && (neg_cash_flow_cash_bal_defn == REDUCE_CASH_BALANCE_TO_THRESHOLD 
			 || neg_cash_flow_cash_bal_defn == BORROW_TO_THRESHOLD)
		 && (neg_cash_flow_strat == NEGATIVE_ASSETS
			 || (asset->mths_to_asset_sale(t) == 0
				 && neg_cash_flow_strat == SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE)))
	cash_incr
	= min(max(cash_flow_for_inv,
			  cash_thresh
			  - cash(t - 1)),
		  max(investable_assets
			   * cash_tgt_pct,
			  cash_thresh)
		  - cash(t - 1));

cash_flow_for_asset_purch
= cash_flow_for_inv
  - cash_incr;

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	seg_element->SALFile << " ... Estimated Cash Flows For Investment Strategy " << inv_strat_id << endl;
	seg_element->SALFile << setprecision(2);
	seg_element->SALFile << "CashFlowForInv," << setw(12) << cash_flow_for_inv << endl;
	seg_element->SALFile << "(-) CashAccountIncr," << setw(12) << cash_incr	 << endl;
	seg_element->SALFile << ",--------------" << endl;
	seg_element->SALFile << "CashForAssetInv," << setw(12) << cash_flow_for_asset_purch << endl;
	seg_element->SALFile << setprecision(6);
	}

// fill expected purchase variables
buy_assets_inv(t, NO, //save_assets
			   cash_flow_for_asset_purch);

duration_numerator
= mkt_val_times_dur_bef_dur_match(t)
  - expected_mkt_val_times_dur_sale
  + expected_mkt_val_times_dur_purch;

duration_denominator
= mkt_val_for_dur_bef_dur_match(t)
  - expected_mkt_val_for_dur_sale
  + expected_mkt_val_for_dur_purch;

if (duration_denominator)
	duration_based_on_current_strategy
	= duration_numerator / duration_denominator;
else
	duration_based_on_current_strategy = 0.0;

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	seg_element->SALFile << setprecision(6)
				 << "Duration Estimate," << duration_based_on_current_strategy << ","
				 << setprecision(2)
				 << "= [ " << mkt_val_times_dur_bef_dur_match(t)
				 << " - " << expected_mkt_val_times_dur_sale
				 << " + " << expected_mkt_val_times_dur_purch
				 << " / " << mkt_val_for_dur_bef_dur_match(t)
				 << " - " << expected_mkt_val_for_dur_sale
				 << " + " << expected_mkt_val_for_dur_purch << " ]"
				 << endl;
	seg_element->SALFile << setprecision(6);
	}

return duration_based_on_current_strategy;
}



#line 1 "buy_assets_hedging.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::buy_assets_hedging(int t, int save_assets, StrEnum::EnumValue port_defn, int &new_mp_num, const xstring &hedge_group_code, const xstring &hedge_asset_id, double notional_amt_to_hedge, double long_strike, double short_strike)
{
int panum = 0;
double notional_amount_of_purchase = 0.0;
double amount_invested = 0.0;

// use t - 1 for BOM investments
if (investing_bom_flag)
	investment_period = t - 1; 
else
	investment_period = t;

investing_flag = true;

// Force call seg_element->inv_asset(t - 1)
if (t == 1)
	seg_element->inv_asset(t - 1);	

if (save_assets == YES)
	{
	if (asset->asset_detail_rpt_inv_strat_flag(t))
		{
		seg_element->SALFile << endl;
		seg_element->SALFile << "Liability Hedge Investments "
				<< "Period=" << t << " "
				<< "Year=" << xint(cal_yr(t)) << " "
				<< "Month=" << xint(cal_mth(t))
				<< endl;
		seg_element->SALFile << "Hedge Group," << hedge_group_code
				<< endl;

		asset_detail_rpt_buy_purch_asset(t, HEADER);
		}
	}

set_asset_defn(HEDGING);

if (fabs(notional_amt_to_hedge) > model_point_amount_threshold) //Purchase option for hedge group
	{	
	for (panum = 0; panum < purch_asset_max_num; panum++)
		{
		if (port_defn == purch_assets_port_defn[panum])
			{
			if (purch_assets_id[panum] == hedge_asset_id)
				{
				if (save_assets == YES)
					{
					amount_invested
					+= buy_purch_asset_hedging(investment_period, 
							save_assets,
							port_defn,
							panum,
							hedge_group_code,
							new_mp_num,
							notional_amt_to_hedge,
							long_strike,
							short_strike);
					}
				else
					{
					buy_purch_asset_hedging(investment_period, 
							save_assets,
							port_defn,
							panum,
							hedge_group_code,
							new_mp_num,
							notional_amt_to_hedge,
							long_strike,
							short_strike);
					}
				}
			}
		} // end_for over panum
	}	

investing_flag = false;

return amount_invested;
}



#line 1 "buy_assets_inv.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::buy_assets_inv(int t, int save_assets, double cash_flow_for_asset_purch)
{
// Clear expected purchase amounts
// Clear before exit for duration matching
expected_mkt_val_for_dur_purch = 0.0;
expected_mkt_val_times_dur_purch = 0.0;

seg_id = seg_id;
double inv_amt_min_local = inv_amt_min;

if (fabs(cash_flow_for_asset_purch) < inv_amt_min_local
	|| cash_tgt_pct > (1.0 - rate_ratio_threshold))
	return 0.0;

double aggregate_book_plus_accrued = 0.0;
double assets_other_than_cash = 0.0;
double local_amount_invested = 0.0;

int asset_sub_port = 0;
int fund_index = 0;

if (cash_flow_for_asset_purch > 0.0
	|| (cash_flow_for_asset_purch < 0
		&& neg_cash_flow_strat == NEGATIVE_ASSETS))
	{
	initialize_sale_and_inv_vars_eom(t);

	aggregate_book_plus_accrued = 0.0;

	for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
		for (fund_index = 0; fund_index < MAXIMUM_NUMBER_OF_ASSET_FUNDS; fund_index++)
			aggregate_book_plus_accrued
			+= sub_port_fund_initial_book_plus_accrued[asset_sub_port][fund_index]
			   - sub_port_fund_book_plus_accrued_sold[asset_sub_port][fund_index];

	if (save_assets == NO)
		aggregate_book_plus_accrued
		-= expected_sold_at_bk;

	assets_other_than_cash
	= aggregate_book_plus_accrued + cash_flow_for_asset_purch;

	if (asset->asset_detail_rpt_inv_strat_flag(t))
		seg_element->SALFile << endl
					 << "Cash For Purchasing Assets," << cash_flow_for_asset_purch << endl
					 << "Assets Other Than Cash," << assets_other_than_cash << endl;

	if (asset_sub_port_inv_tgt_pct_sum > rate_ratio_threshold)
		{
		int asset_sub_port = 0;
		double distance_below_target_allocation = 0.0;
		double distance_above_target_allocation = 0.0;
		double investment_strategy_sub_port_percent = 0.0;
		double purch_allocation_by_sub_port = 0.0;
		int panum = 0;
		double purch_asset_amt = 0.0;

		// variables for detail report
		int asd_sub_port = 0;
		xstring asd_purpose;
		double asd_book_value = 0.0;
		double asd_eff_dur = 0.0;
		xstring asd_identifier;

		static SmartArray <double> sub_port_book_plus_accrued;

		if (sub_port_book_plus_accrued.size() < asset->sm_asset_sub_port[seg_num].size())
			sub_port_book_plus_accrued.resize(asset->sm_asset_sub_port[seg_num].size());

		// Buy purchase assets
		if (asset_sub_port_distribn_defn == BOOK)
			{
			for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
				{
				sub_port_book_plus_accrued[asset_sub_port] = 0.0;

				sub_port_book_plus_accrued[asset_sub_port]
				+= sub_port_fund_initial_book_plus_accrued[asset_sub_port][INVESTMENT_FUND_INDEX]
				   + sub_port_fund_book_plus_accrued_purchases[asset_sub_port][INVESTMENT_FUND_INDEX]
				   - sub_port_fund_book_plus_accrued_sold[asset_sub_port][INVESTMENT_FUND_INDEX];

				if (save_assets == NO)
					sub_port_book_plus_accrued[asset_sub_port]
					-= sub_port_fund_expected_book_plus_accrued_sold[asset_sub_port][INVESTMENT_FUND_INDEX];

				investment_strategy_sub_port_percent
				= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct
				  * asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd;

				if (assets_other_than_cash != 0.0 && asset_sub_port == 0)
					distance_below_target_allocation
					= max(0.0,
						  investment_strategy_sub_port_percent
						  - sub_port_book_plus_accrued[asset_sub_port]
							/ assets_other_than_cash);
				else if (fabs(assets_other_than_cash) > model_point_amount_threshold)
					distance_below_target_allocation
					= distance_below_target_allocation
					  + max(0.0,
							investment_strategy_sub_port_percent
							- sub_port_book_plus_accrued[asset_sub_port]
							  / assets_other_than_cash);

				if (fabs(assets_other_than_cash) > model_point_amount_threshold)
					{
					if (asset_sub_port == 0)
						distance_above_target_allocation
						= max(0.0,
							  sub_port_book_plus_accrued[asset_sub_port]
							  / assets_other_than_cash
							  - investment_strategy_sub_port_percent);
					else // if (asset_sub_port > 0)
						distance_above_target_allocation
						= distance_above_target_allocation
						  + max(0.0,
								sub_port_book_plus_accrued[asset_sub_port]
								/ assets_other_than_cash
								- investment_strategy_sub_port_percent);
					}
				}	// end_for on asset_sub_port
			}	// endif asset_sub_port_distribn_defn == BOOK

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (asset_sub_port_distribn_defn == BOOK)
				{
				seg_element->SALFile << "Distance " << ((cash_flow_for_asset_purch > 0.0)
												 ? "Below" : "Above") << " Target Allocation,"
							 << ((cash_flow_for_asset_purch > 0.0)
								  ? distance_below_target_allocation
								  : distance_above_target_allocation)
							 << endl;

				asset_detail_rpt_tgt_pct_by_sub_port(t,
						"Investment",
						cash_flow_for_asset_purch,
						assets_other_than_cash,
						distance_below_target_allocation,
						distance_above_target_allocation,
						sub_port_book_plus_accrued);
				}

			asset_detail_rpt_buy_purch_asset(t, HEADER);
			}

		for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
			{
			//Determine investment allocation for asset sub portfolios.
			if (asset_sub_port_distribn_defn == BOOK)
				investment_strategy_sub_port_percent
				= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct
				  * asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd;
			else // if (asset_sub_port_distribn_defn == CASH)
				investment_strategy_sub_port_percent
				= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct
				  * asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd
				  / asset_sub_port_inv_tgt_pct_sum;

			if ((asset_sub_port_distribn_defn == CASH
				 || fabs(assets_other_than_cash) < model_point_amount_threshold)
				&& (cash_flow_for_asset_purch > 0.0
					|| (cash_flow_for_asset_purch < 0.0
						&& neg_cash_flow_strat == NEGATIVE_ASSETS)))
				purch_allocation_by_sub_port
				= cash_flow_for_asset_purch
				  * investment_strategy_sub_port_percent;
			else if (asset_sub_port_distribn_defn == BOOK
					 && cash_flow_for_asset_purch > 0.0
					 && fabs(assets_other_than_cash) > model_point_amount_threshold
					 && distance_below_target_allocation > 0.0)
				purch_allocation_by_sub_port
				= cash_flow_for_asset_purch
				  * max(0.0,
						investment_strategy_sub_port_percent
						- sub_port_book_plus_accrued[asset_sub_port]
						  / assets_other_than_cash)
				  / distance_below_target_allocation;
			else
				purch_allocation_by_sub_port = 0.0;

			if (fabs(purch_allocation_by_sub_port) > 1.0)
				{
				for (panum = 0; panum < purch_asset_max_num; panum++)
					{
					if (purch_assets_asset_sub_port_num[panum] == asset_sub_port
						&& purch_assets_port_defn[panum] == INVESTMENT
						&& purch_assets_weight[panum] > 0.0
						&& asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd > 0.0)
						{
						purch_asset_amt
						= purch_allocation_by_sub_port
						  * purch_assets_weight[panum]
						  / asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd;

						if ((purch_asset_amt
							 >= max(1.0, asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->min_size_purchase))
							|| (neg_cash_flow_strat == NEGATIVE_ASSETS
								&& (purch_asset_amt
								    <= (-min(1.0, asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->min_size_purchase))))) 
							{
							if (save_assets == YES
								|| (save_assets == NO
									&& purch_assets_dur_calculated[panum] == NO))
								{
								local_amount_invested
								+= buy_purch_asset_inv(t,
													   save_assets,
													   INVESTMENT,
													   panum,
													   purch_asset_amt);
								}
							else // if (save_assets == NO
								 //     && purch_assets_dur_calculated[panum] == YES)
								{
								local_amount_invested
								+= purch_asset_amt;

								if (purch_assets_dur_defn[panum] == YES)
									{
									expected_mkt_val_for_dur_purch
									+= purch_asset_amt;

									expected_mkt_val_times_dur_purch 
									+= purch_asset_amt
									   * purch_assets_dur[panum];
								   }

								if (asset->asset_detail_rpt_inv_strat_flag(t))
									{
									asd_identifier = purch_assets_id[panum];
									asd_sub_port = purch_assets_asset_sub_port_num[panum];

									if (purch_assets_port_defn[panum] == INVESTMENT)
										asd_purpose = "Investment";
									else
										asd_purpose = "Unknown";

									asd_book_value = purch_asset_amt;
									asd_eff_dur = purch_assets_dur[panum];

									asset_detail_rpt_buy_purch_asset(t, VIRTUAL_PURCHASE,
												0, asd_identifier, asd_sub_port, 0,
												asd_purpose, 0, 0, 0, asd_book_value,
												0, 0, asd_eff_dur);
									}
								}	// endif (save_assets == YES ...)
							}	// if (purch_asset_amt >= max(1.0, ...) ...)
						else
							{
							if (asset->asset_detail_rpt_inv_strat_flag(t))
								{
								asd_identifier = purch_assets_id[panum];
								asd_sub_port = purch_assets_asset_sub_port_num[panum];

								if (purch_assets_port_defn[panum] == INVESTMENT)
									asd_purpose = "Investment";
								else
									asd_purpose = "Unknown";

								asd_book_value = purch_asset_amt;

								asset_detail_rpt_buy_purch_asset(t, NOT_PURCHASED,
											0, asd_identifier, asd_sub_port, 0,
											asd_purpose, 0, 0, 0, asd_book_value,
											0, 0, 0);
								}
							}
						}	// if (purch_assets_asset_sub_port_num[panum] == asset_sub_port
					}	// end_for over panum
				}	// if (fabs(investment_allocation_by_sub_port) > 1.0)
			}	// end for on asset_sub_port                                 
		}
	}

if (asset->asset_detail_rpt_inv_strat_flag(t))
	seg_element->SALFile << "Total Cash Purchasing Assets," << local_amount_invested
				 << endl;

return local_amount_invested;
}



#line 1 "buy_purch_asset_hedging.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::buy_purch_asset_hedging(int t, int save_assets, StrEnum::EnumValue port_defn, int panum, const xstring &hedge_group_code, int &new_mp_num, double purch_asset_amt, double long_strike, double short_strike)
{
// Note: "t" in this function is the period before the actual projection period "t" as required for bom purchases
double local_amount_invested = 0.0;

// variables for detail report
int asd_sub_port = 0;
int asd_class = 0;
int asd_fund = 0;
double asd_neg_asset_flag = 0.0;
double asd_notional_amount = 0.0;
double asd_market_value = 0.0;
double asd_cost_basis = 0.0;
double asd_book_value = 0.0;
double asd_ytm = 0.0;
double asd_wal = 0.0;
double asd_eff_dur = 0.0;
int asd_sequence_num = 0;
xstring asd_identifier = "";
xstring asd_model_name = "";
xstring asset_sub_port_tag = "";
xstring purch_asset_index = "";

int sub_port_num = 0;
int sale_class = 0;
int fund_index = 0;
double local_accrued_interest = 0;
double local_accrued_rent = 0;
double local_book_value = 0;
double prior_investment_amount = 0;
bool asset_detail_strat_flag = false;

investing_flag = true;
asset->purch_asset_mp_num = purch_assets_mp_num[panum];
purch_asset_id = purch_assets_id[panum];

#if defined(__EIO_ASSET_H_)
if (purch_assets_type[panum] == INDEX_OPTION)
	{
	purch_asset_id = purch_asset_id;
	asset->purch_asset_yrs_to_maturity = purch_eio_yrs_to_maturity;

	purch_asset_index
	= purch_assets_id[panum] + get_string_of_enum_val(port_defn);

	new_mp_num = seg_element->asset_mp_maps(MP_NEXT_CODE, INDEX_OPTION_CODE);
	asset->sm_eio[new_mp_num][0]->seg_element = seg_element;
	asset->sm_eio[new_mp_num][0]->seg_id = seg_id;

	asset->sm_eio[new_mp_num][0]->setup_purch_hedge_asset(t, save_assets,
				panum, new_mp_num,
				purch_assets_asset_sub_port_num[panum],
				hedge_group_code,
				purch_asset_amt, 
				asset->asset_mp_sequence_num,
				long_strike,
				short_strike);

	bool asset_detail_flag = false;
	if (investing_bom_flag && asset->sm_eio[new_mp_num][0]->asset_detail_pv_flag(t + 1))
		asset_detail_flag = true;
	else if (!investing_bom_flag && asset->sm_eio[new_mp_num][0]->asset_detail_pv_flag(t))
		asset_detail_flag = true;

	if (save_assets == YES && asset_detail_flag)
		{
		if (investing_bom_flag)
			{
			PVCText << " .p. Purchasing Liability Hedge Index Option " << purch_assets_id[panum]
					<< " |" << asset->sm_eio[new_mp_num][0]->modelName
					<< " in hedge group " << hedge_group_code
					<< " at beginning of period " << t + 1;

			asset->asset_detail_rpt_pv_output();
			}
		else
			{
			PVCText << " .p. Purchasing Liability Hedge Index Option " << purch_assets_id[panum]
					<< " |" << asset->sm_eio[new_mp_num][0]->modelName
					<< " in hedge group " << hedge_group_code
					<< " at end of period " << t;

			asset->asset_detail_rpt_pv_output();
			}
		}

	if (investing_bom_flag && asset->asset_detail_rpt_inv_strat_flag(t + 1))
		asset_detail_strat_flag = true;
	else if (!investing_bom_flag && asset->asset_detail_rpt_inv_strat_flag(t))
		asset_detail_strat_flag = true;

	if (save_assets == YES && asset_detail_strat_flag)
		{
		asd_sequence_num = asset->sm_eio[new_mp_num][0]->sequence_id;
		asd_identifier = asset->sm_eio[new_mp_num][0]->asset_id;
		asd_sub_port = asset->sm_eio[new_mp_num][0]->purch_asset_sub_port;
		asd_class = asset->sm_eio[new_mp_num][0]->sale_class_id;
		asd_fund = asset->sm_eio[new_mp_num][0]->asset_fund_index;
		asd_neg_asset_flag = asset->sm_eio[new_mp_num][0]->neg_asset_flag;
		asd_notional_amount = asset->sm_eio[new_mp_num][0]->notional_amt_bef_sale(t);
		asd_market_value = asset->sm_eio[new_mp_num][0]->mkt_val_bef_sale(t);
		asd_cost_basis = asset->sm_eio[new_mp_num][0]->cost_basis_bef_sale(t);
		asd_book_value = asset->sm_eio[new_mp_num][0]->bk_val_bef_sale(t);
		asd_ytm = (asset->sm_eio[new_mp_num][0]->maturity_period - t) / 12.0;
		asd_wal = 0;
		asd_eff_dur = 0;
		asd_model_name = asset->sm_eio[new_mp_num][0]->modelName;
		}

	if (save_assets == YES
		&& port_defn == HEDGING
		&& fabs(asset->sm_eio[new_mp_num][0]->mkt_val_bef_sale(t)) > 0)
		local_amount_invested
		+= asset->sm_eio[new_mp_num][0]->mkt_val_bef_sale(t)
		   * asset->sm_eio[new_mp_num][0]->pct_to_use;

	if (save_assets == NO)
		{
		purch_assets_dur_defn[panum] = NO;
		purch_assets_dur_calculated[panum] = YES;
		purch_assets_dur[panum] = 0;
		seg_element->asset_mp_maps(MP_INACTIVE_CODE, INDEX_OPTION_CODE, new_mp_num);
		}
	else // if (save_assets == YES)
		{
		sub_port_num = xint(asset->sm_eio[new_mp_num][0]->sub_port_id(t));
		sale_class = asset->sm_eio[new_mp_num][0]->sale_class_id;
		fund_index = asset->sm_eio[new_mp_num][0]->asset_fund_index;

		// Accumulate purchase amounts
		local_book_value = asset->sm_eio[new_mp_num][0]->bk_val_bef_sale(t);

		sub_port_fund_book_plus_accrued_purchases[sub_port_num][fund_index]
		+= local_book_value;
		sub_port_class_fund_book_value_purchases[sub_port_num][sale_class][fund_index]
		+= local_book_value;
		}
	}

else 
#endif
#if defined(__IRD_ASSET_H_)
if (purch_assets_type[panum] == INTEREST_RATE_DERIVATIVE)
	{
	purch_asset_id = purch_asset_id;
	asset->purch_asset_yrs_to_maturity = purch_ird_yrs_to_maturity;
	purch_asset_id = purch_asset_id;
	asset->purch_asset_mths_to_first_reset = purch_ird_mths_to_first_reset;


	new_mp_num = seg_element->asset_mp_maps(MP_NEXT_CODE, IRD_CODE);
	asset->sm_ird[new_mp_num][0]->seg_element = seg_element;
	asset->sm_ird[new_mp_num][0]->seg_id = seg_id;

	asset->sm_ird[new_mp_num][0]->setup_purch_hedge_asset(t,
											   save_assets,
											   panum,
											   new_mp_num,
											   purch_assets_asset_sub_port_num[panum],
											   hedge_group_code,
											   purch_asset_amt,
											   seg_element->asset_mp_sequence_num);
	
	if (save_assets == YES && asset->sm_ird[new_mp_num][0]->asset_detail_pv_flag(t))
		{
		PVCText << " .p. Purchasing Liability Hedge Interest Rate Derivative" << purch_assets_id[panum]
				<< " |" << asset->sm_ird[new_mp_num][0]->modelName
				<< " in hedge group " << hedge_group_code
				<< " at end of period " << t;

		asset->asset_detail_rpt_pv_output();
		}

	if (asset->asset_detail_rpt_inv_strat_flag(t))
		asset_detail_strat_flag = true;

	if (save_assets == YES && asset_detail_strat_flag)
		{
		asd_sequence_num = asset->sm_ird[new_mp_num][0]->sequence_id;
		asd_identifier = asset->sm_ird[new_mp_num][0]->asset_id;
		asd_sub_port = asset->sm_ird[new_mp_num][0]->purch_asset_sub_port;
		asd_class = asset->sm_ird[new_mp_num][0]->sale_class_id;
		asd_fund = asset->sm_ird[new_mp_num][0]->asset_fund_index;
		asd_neg_asset_flag = asset->sm_ird[new_mp_num][0]->neg_asset_flag;
		asd_notional_amount = asset->sm_ird[new_mp_num][0]->notional_amt_bef_sale(t);
		asd_market_value = asset->sm_ird[new_mp_num][0]->mkt_val_bef_sale(t);
		asd_cost_basis = asset->sm_ird[new_mp_num][0]->cost_basis_bef_sale(t);
		asd_book_value = asset->sm_ird[new_mp_num][0]->bk_val_bef_sale(t);
		asd_ytm = (asset->sm_ird[new_mp_num][0]->maturity_period - t) / 12.0;
		asd_wal = 0;
		asd_eff_dur = 0;
		asd_model_name = asset->sm_ird[new_mp_num][0]->modelName;
		}
	
	if (save_assets == YES
		&& port_defn == HEDGING
		&& fabs(asset->sm_ird[new_mp_num][0]->mkt_val_bef_sale(t)) > 0)
		local_amount_invested
		+= asset->sm_ird[new_mp_num][0]->mkt_val_bef_sale(t)
		   * asset->sm_ird[new_mp_num][0]->pct_to_use;
	
	if (save_assets == NO)
		{
		purch_assets_dur_defn[panum] = YES;
		purch_assets_dur_calculated[panum] = YES;
		purch_assets_dur[panum] = 0.0;
		seg_element->asset_mp_maps(MP_INACTIVE_CODE, IRD_CODE, new_mp_num);
		}
	else // if (save_assets == YES)
		{
		sub_port_num = xint(asset->sm_ird[new_mp_num][0]->sub_port_id(t));
		sale_class = asset->sm_ird[new_mp_num][0]->sale_class_id;
		fund_index = asset->sm_ird[new_mp_num][0]->asset_fund_index;
	
		// Accumulate purchase amounts
		local_book_value = asset->sm_ird[new_mp_num][0]->bk_val_bef_sale(t);
		local_accrued_interest = asset->sm_ird[new_mp_num][0]->accr_int_bef_sale(t);
	
		sub_port_fund_book_plus_accrued_purchases[sub_port_num][fund_index] += local_book_value + local_accrued_interest;
		sub_port_class_fund_accrued_interest_purchases[sub_port_num][sale_class][fund_index] += local_accrued_interest;
		sub_port_class_fund_book_value_purchases[sub_port_num][sale_class][fund_index] += local_book_value;
		}
	}
else 
#endif
	{
	; // Leave this semi-colon as a placeholder for the "else" clauses above.
	}
	
if (save_assets == NO
	&& purch_assets_dur_defn[panum] == YES)
	{
	expected_mkt_val_for_dur_purch
	+= purch_asset_amt;

	expected_mkt_val_times_dur_purch 
	+= purch_asset_amt
	   * purch_assets_dur[panum];
	}

if (save_assets == YES && asset_detail_strat_flag)
	{
	asset_detail_rpt_buy_purch_asset(t, PURCHASED,
				asd_sequence_num, asd_identifier,
				asd_sub_port, asset->zSalesClass[asd_class], asset->zAssetFund[asd_fund],
				asd_neg_asset_flag, asd_notional_amount, asd_market_value,
				asd_cost_basis, asd_book_value,
				asd_ytm, asd_wal, asd_eff_dur);
	}

investing_flag = false;

return local_amount_invested;
}



#line 1 "buy_purch_asset_inv.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::buy_purch_asset_inv(int t, int save_assets, StrEnum::EnumValue port_defn, int panum, double purch_asset_amt)
{
int new_mp_num = 0;
int new_cp_num = 0;
int cpianum = 0;
double local_amount_invested = 0.0;
int cpinvtype;

// Variables for asset detail report
int asd_sub_port = 0;
int asd_class = 0;
int asd_fund = 0;
double asd_neg_asset_flag = 1.0;
double asd_notional_amount = 0.0;
double asd_market_value = 0.0;
double asd_cost_basis = 0.0;
double asd_book_value = 0.0;
double asd_ytm = 0.0;
double asd_wal = 0.0;
double asd_eff_dur = 0.0;
int asd_sequence_num = 0;
xstring asd_identifier = "";
xstring asd_model_name = "";
xstring asset_sub_port_tag = "";

int sub_port_num = 0;
int sale_class = 0;
int fund_index = 0;
double local_accrued_interest = 0;
double local_accrued_rent = 0;
double local_book_value = 0;
double prior_investment_amount = 0;

investing_flag = true;
investment_period = t;
asset->purch_asset_mp_num = purch_assets_mp_num[panum];
purch_asset_id = purch_assets_id[panum];

#if defined(__BOND_ASSET_H_)

if (purch_assets_type[panum] == BOND)
	{
	purch_asset_id = purch_asset_id;
	asset->purch_asset_yrs_to_maturity = purch_bond_yrs_to_maturity;
	
	new_mp_num = seg_element->asset_mp_maps(MP_NEXT_CODE, BOND_CODE);
	asset->sm_bond[new_mp_num][0]->seg_element = seg_element;
	asset->sm_bond[new_mp_num][0]->seg_id = seg_id;
	asset->sm_bond[new_mp_num][0]->sm_bond_cf_var.resize(1);

	asset->sm_bond[new_mp_num][0]->setup_purch_inv_asset(t,
												save_assets,
												panum,
												new_mp_num,
												purch_asset_amt,
												seg_element->asset_mp_sequence_num);

	if (asset->sm_bond[new_mp_num][0]->asset_detail_rpt_pv_flag(t))
		{
		PVCText << " .p. Purchasing bond " << purch_assets_id[panum]
				<< " |" << asset->sm_bond[new_mp_num][0]->modelName
				<< " in sub portfolio " << purch_assets_asset_sub_port_num[panum]
				<< " at time " << ((inv_purch_timing == END_OF_MONTH) ? t : t+1)
				<< " " << inv_purch_timing;
		asset->asset_detail_rpt_pv_output();
		}

	if (asset->asset_detail_rpt_inv_strat_flag(t))
		{
		asd_sequence_num = asset->sm_bond[new_mp_num][0]->sequence_id;
		asd_identifier = asset->sm_bond[new_mp_num][0]->asset_id;
		asd_sub_port = asset->sm_bond[new_mp_num][0]->purch_asset_sub_port;
		asd_class = asset->sm_bond[new_mp_num][0]->sale_class_id;
		asd_fund = asset->sm_bond[new_mp_num][0]->asset_fund_index;
		asd_neg_asset_flag = asset->sm_bond[new_mp_num][0]->neg_asset_flag;
		asd_notional_amount = asset->sm_bond[new_mp_num][0]->notional_amt_bef_sale(t);
		asd_market_value = asset->sm_bond[new_mp_num][0]->mkt_val_bef_sale(t);
		asd_cost_basis = asset->sm_bond[new_mp_num][0]->cost_basis_bef_sale(t);
		asd_book_value = asset->sm_bond[new_mp_num][0]->bk_val_bef_sale(t);
		asd_ytm = (asset->sm_bond[new_mp_num][0]->maturity_period - t) / 12.0;
		asd_wal = asset->sm_bond[new_mp_num][0]->weighted_avg_life(t);
		asd_eff_dur = asset->sm_bond[new_mp_num][0]->eff_dur(t);
		asd_model_name = asset->sm_bond[new_mp_num][0]->modelName;
		}

	if (port_defn == INVESTMENT
		&& asset->sm_bond[new_mp_num][0]->mkt_val_bef_sale(t) > 0)
		local_amount_invested += purch_asset_amt;
		
	if (save_assets == NO)
		{
		purch_assets_dur_defn[panum] = YES;
		purch_assets_dur_calculated[panum] = YES;
		purch_assets_dur[panum]	= asset->sm_bond[new_mp_num][0]->dur_val(t);

		seg_element->asset_mp_maps(MP_INACTIVE_CODE, BOND_CODE, new_mp_num);
		}
	else // if (save_assets == YES)
		{
		sub_port_num = xint(asset->sm_bond[new_mp_num][0]->sub_port_id(t));
		sale_class = asset->sm_bond[new_mp_num][0]->sale_class_id;
		fund_index = asset->sm_bond[new_mp_num][0]->asset_fund_index;

		// Force call to reduce sliding windows sizes
		asset->sm_bond[new_mp_num][0]->net_yld(t);

		// Accumulate purchase amounts
		local_book_value = asset->sm_bond[new_mp_num][0]->bk_val_bef_sale(t);
		local_accrued_interest = asset->sm_bond[new_mp_num][0]->accr_int_bef_sale(t);

		sub_port_fund_book_plus_accrued_purchases[sub_port_num][fund_index] += local_book_value + local_accrued_interest;
		sub_port_class_fund_accrued_interest_purchases[sub_port_num][sale_class][fund_index] += local_accrued_interest;
		sub_port_class_fund_book_value_purchases[sub_port_num][sale_class][fund_index] += local_book_value;
		}
	}

else 
#endif
#if defined(__MTG_ASSET_H_)
if (purch_assets_type[panum] == MORTGAGE)
	{
	purch_asset_id = purch_asset_id;
	asset->purch_asset_yrs_to_maturity = purch_mtg_yrs_to_maturity;
	
	new_mp_num = seg_element->asset_mp_maps(MP_NEXT_CODE, MORTGAGE_CODE);
	asset->sm_mtg[new_mp_num][0]->seg_element = seg_element;
	asset->sm_mtg[new_mp_num][0]->seg_id = seg_id;
	asset->sm_mtg[new_mp_num][0]->sm_mtg_cf_var.resize(1); 

	asset->sm_mtg[new_mp_num][0]->setup_purch_inv_asset(t,
											   save_assets,
											   panum,
											   new_mp_num,
											   port_defn,
											   purch_assets_asset_sub_port_num[panum],
											   purch_asset_amt,
											   seg_element->asset_mp_sequence_num);

	if (asset->sm_mtg[new_mp_num][0]->asset_detail_pv_flag(t))
		{
		PVCText << " .p. Purchasing mortgage " << purch_assets_id[panum]
				<< " |" << asset->sm_mtg[new_mp_num][0]->modelName
				<< " in sub portfolio " << purch_assets_asset_sub_port_num[panum]
				<< " at time " << ((inv_purch_timing == END_OF_MONTH) ? t : t+1)
				<< " " << inv_purch_timing;
		asset->asset_detail_rpt_pv_output();
		}

	if (asset->asset_detail_rpt_inv_strat_flag(t))
		{
		asd_sequence_num = asset->sm_mtg[new_mp_num][0]->sequence_id;
		asd_identifier = asset->sm_mtg[new_mp_num][0]->asset_id;
		asd_sub_port = asset->sm_mtg[new_mp_num][0]->purch_asset_sub_port;
		asd_class = asset->sm_mtg[new_mp_num][0]->sale_class_id;
		asd_fund = asset->sm_mtg[new_mp_num][0]->asset_fund_index;
		asd_neg_asset_flag = asset->sm_mtg[new_mp_num][0]->neg_asset_flag;
		asd_notional_amount = asset->sm_mtg[new_mp_num][0]->notional_amt_bef_sale(t);
		asd_market_value = asset->sm_mtg[new_mp_num][0]->mkt_val_bef_sale(t);
		asd_cost_basis = asset->sm_mtg[new_mp_num][0]->cost_basis_bef_sale(t);
		asd_book_value = asset->sm_mtg[new_mp_num][0]->bk_val_bef_sale(t);
		asd_ytm = (asset->sm_mtg[new_mp_num][0]->maturity_period - t) / 12.0;
		asd_wal = asset->sm_mtg[new_mp_num][0]->weighted_avg_life(t);
		asd_eff_dur = asset->sm_mtg[new_mp_num][0]->eff_dur(t);
		asd_model_name = asset->sm_mtg[new_mp_num][0]->modelName;
		}
	
	if (port_defn == INVESTMENT
		&& asset->sm_mtg[new_mp_num][0]->mkt_val_bef_sale(t) > 0)
		local_amount_invested += purch_asset_amt;
	else if (port_defn == FORECLOSURE
			 || port_defn == RESTRUCTURE
			 || port_defn == REFINANCE)
		{
		// Force calculation of the following columns because the 
		//   foreclosure_restructure_refinance_investment_... variables can change
		asset->sm_mtg[new_mp_num][0]->cost_basis_bef_sale(t);
		asset->sm_mtg[new_mp_num][0]->bk_val_bef_sale(t);
		asset->sm_mtg[new_mp_num][0]->sm_mtg_cf->par_val_bef_sale(t);
		}

	if (save_assets == NO)
		{
		purch_assets_dur_defn[panum] = YES;
		purch_assets_dur_calculated[panum] = YES;
		purch_assets_dur[panum]	= asset->sm_mtg[new_mp_num][0]->dur_val(t);

		seg_element->asset_mp_maps(MP_INACTIVE_CODE, MORTGAGE_CODE, new_mp_num);
		}
	else // if (save_assets == YES)
		{
		sub_port_num = xint(asset->sm_mtg[new_mp_num][0]->sub_port_id(t));
		sale_class = asset->sm_mtg[new_mp_num][0]->sale_class_id;
		fund_index = asset->sm_mtg[new_mp_num][0]->asset_fund_index;

		// forced calls to reduce sliding windows sizes
		asset->sm_mtg[new_mp_num][0]->net_yld(t);
	
		// accumulate "purchase" amounts
		local_book_value = asset->sm_mtg[new_mp_num][0]->bk_val_bef_sale(t);
		local_accrued_interest = asset->sm_mtg[new_mp_num][0]->accr_int_bef_sale(t);
	
		sub_port_fund_book_plus_accrued_purchases[sub_port_num][fund_index] += local_book_value + local_accrued_interest;
		sub_port_class_fund_accrued_interest_purchases[sub_port_num][sale_class][fund_index] += local_accrued_interest;
		sub_port_class_fund_book_value_purchases[sub_port_num][sale_class][fund_index] += local_book_value;
		}
	}

else 
#endif
#if defined(__SEC_ASSET_H_)
if (purch_assets_type[panum] == SECURITIZED_ASSET)
	{
	new_mp_num = seg_element->asset_mp_maps(MP_NEXT_CODE, SEC_CODE);
	asset->sm_sec[new_mp_num]->seg_element = seg_element;
	asset->sm_sec[new_mp_num]->seg_id = seg_id;

	asset->sm_sec[new_mp_num]->setup_purch_inv_asset(t,
											   save_assets,
											   panum,
											   new_mp_num,
											   purch_assets_asset_sub_port_num[panum],
											   purch_asset_amt,
											   seg_element->asset_mp_sequence_num);
	
	if (asset->sm_sec[new_mp_num]->asset_detail_rpt_pv_flag(t))
		{
		PVCText << " .p. Purchasing SEC " << purch_assets_id[panum]
			   << " |" << asset->sm_sec[new_mp_num]->modelName
			   << " in sub portfolio " << purch_assets_asset_sub_port_num[panum]
			   << " at time " << ((inv_purch_timing == END_OF_MONTH) ? t : t+1)
			   << " " << inv_purch_timing;
		asset->asset_detail_rpt_pv_output();
		}

	if (asset->asset_detail_rpt_inv_strat_flag(t))
		{
		asd_sequence_num = asset->sm_sec[new_mp_num]->sequence_id;
		asd_identifier = asset->sm_sec[new_mp_num]->asset_id;
		asd_sub_port = asset->sm_sec[new_mp_num]->purch_asset_sub_port;
		asd_class = asset->sm_sec[new_mp_num]->sale_class_id;
		asd_fund = asset->sm_sec[new_mp_num]->asset_fund_index;
		asd_neg_asset_flag = asset->sm_sec[new_mp_num]->neg_asset_flag;
		asd_notional_amount = asset->sm_sec[new_mp_num]->notional_amt_bef_sale(t);
		asd_market_value = asset->sm_sec[new_mp_num]->mkt_val_bef_sale(t);
		asd_cost_basis = asset->sm_sec[new_mp_num]->cost_basis_bef_sale(t);
		asd_book_value = asset->sm_sec[new_mp_num]->bk_val_bef_sale(t);
		asd_ytm = (asset->sm_sec[new_mp_num]->maturity_period - t) / 12.0;
		asd_wal = asset->sm_sec[new_mp_num]->weighted_avg_life(t);
		asd_eff_dur = asset->sm_sec[new_mp_num]->eff_dur(t);
		asd_model_name = asset->sm_sec[new_mp_num]->modelName;
		}
	
	if (port_defn == INVESTMENT
		&& asset->sm_sec[new_mp_num]->mkt_val_bef_sale(t) > 0)
		local_amount_invested += purch_asset_amt;
	
	if (save_assets == NO)
		{
		purch_assets_dur_defn[panum] = YES;
		purch_assets_dur_calculated[panum] = YES;
		purch_assets_dur[panum]	= asset->sm_sec[new_mp_num]->dur_val(t);
	
		seg_element->asset_mp_maps(MP_INACTIVE_CODE, SEC_CODE, new_mp_num);
		}
	else // if (save_assets == YES)
		{
		sub_port_num = xint(asset->sm_sec[new_mp_num]->sub_port_id(t));
		sale_class = asset->sm_sec[new_mp_num]->sale_class_id;
		fund_index = asset->sm_sec[new_mp_num]->asset_fund_index;

		// Force call to reduce sliding windows sizes
		asset->sm_sec[new_mp_num]->weighted_avg_life(t);
		asset->sm_sec[new_mp_num]->net_yld(t);
	
		// Accumulate "purchase" amounts
		local_book_value = asset->sm_sec[new_mp_num]->bk_val_bef_sale(t);
		local_accrued_interest = asset->sm_sec[new_mp_num]->accr_int_bef_sale(t);
	
		sub_port_fund_book_plus_accrued_purchases[sub_port_num][fund_index] += local_book_value + local_accrued_interest;
		sub_port_class_fund_accrued_interest_purchases[sub_port_num][sale_class][fund_index] += local_accrued_interest;
		sub_port_class_fund_book_value_purchases[sub_port_num][sale_class][fund_index] += local_book_value;
		}
	}

else 
#endif
#if defined(__IRD_ASSET_H_)
if (purch_assets_type[panum] == INTEREST_RATE_DERIVATIVE)
	{
	purch_asset_id = purch_asset_id;
	asset->purch_asset_yrs_to_maturity = purch_ird_yrs_to_maturity;
	purch_asset_id = purch_asset_id;
	asset->purch_asset_mths_to_first_reset = purch_ird_mths_to_first_reset;

	new_mp_num = seg_element->asset_mp_maps(MP_NEXT_CODE, IRD_CODE);
	asset->sm_ird[new_mp_num][0]->seg_element = seg_element;
	asset->sm_ird[new_mp_num][0]->seg_id = seg_id;

	asset->sm_ird[new_mp_num][0]->setup_purch_inv_asset(t,
											   save_assets,
											   panum,
											   new_mp_num,
											   purch_assets_asset_sub_port_num[panum],
											   purch_asset_amt,
											   seg_element->asset_mp_sequence_num);
	
	if (asset->sm_ird[new_mp_num][0]->asset_detail_pv_flag(t))
		{
		PVCText << " .p. Purchasing Interest Rate Derivative" << purch_assets_id[panum]
				<< " |" << asset->sm_ird[new_mp_num][0]->modelName
				<< " in sub portfolio " << purch_assets_asset_sub_port_num[panum]
				<< " at time " << ((inv_purch_timing == END_OF_MONTH) ? t : t+1)
				<< " " << inv_purch_timing;
		asset->asset_detail_rpt_pv_output();
		}

	if (asset->asset_detail_rpt_inv_strat_flag(t))
		{
		asd_sequence_num = asset->sm_ird[new_mp_num][0]->sequence_id;
		asd_identifier = asset->sm_ird[new_mp_num][0]->asset_id;
		asd_sub_port = asset->sm_ird[new_mp_num][0]->purch_asset_sub_port;
		asd_class = asset->sm_ird[new_mp_num][0]->sale_class_id;
		asd_fund = asset->sm_ird[new_mp_num][0]->asset_fund_index;
		asd_neg_asset_flag = asset->sm_ird[new_mp_num][0]->neg_asset_flag;
		asd_notional_amount = asset->sm_ird[new_mp_num][0]->notional_amt_bef_sale(t);
		asd_market_value = asset->sm_ird[new_mp_num][0]->mkt_val_bef_sale(t);
		asd_cost_basis = asset->sm_ird[new_mp_num][0]->cost_basis_bef_sale(t);
		asd_book_value = asset->sm_ird[new_mp_num][0]->bk_val_bef_sale(t);
		asd_ytm = (asset->sm_ird[new_mp_num][0]->maturity_period - t) / 12.0;
		asd_wal = 0;
		asd_eff_dur = 0;
		asd_model_name = asset->sm_ird[new_mp_num][0]->modelName;
		}
	
	if (port_defn == INVESTMENT
		&& asset->sm_ird[new_mp_num][0]->mkt_val_bef_sale(t) > 0)
		local_amount_invested += purch_asset_amt;
	
	if (save_assets == NO
		|| (port_defn == INVESTMENT
			&& asset->sm_ird[new_mp_num][0]->mkt_val_bef_sale(t) < 0))
		{
		purch_assets_dur_defn[panum] = YES;
		purch_assets_dur_calculated[panum] = YES;
		purch_assets_dur[panum] = 0.0;
		seg_element->asset_mp_maps(MP_INACTIVE_CODE, IRD_CODE, new_mp_num);
		}
	else // if (save_assets == YES)
		{
		sub_port_num = xint(asset->sm_ird[new_mp_num][0]->sub_port_id(t));
		sale_class = asset->sm_ird[new_mp_num][0]->sale_class_id;
		fund_index = asset->sm_ird[new_mp_num][0]->asset_fund_index;
	
		// Accumulate purchase amounts
		local_book_value = asset->sm_ird[new_mp_num][0]->bk_val_bef_sale(t);
		local_accrued_interest = asset->sm_ird[new_mp_num][0]->accr_int_bef_sale(t);
	
		sub_port_fund_book_plus_accrued_purchases[sub_port_num][fund_index] += local_book_value + local_accrued_interest;
		sub_port_class_fund_accrued_interest_purchases[sub_port_num][sale_class][fund_index] += local_accrued_interest;
		sub_port_class_fund_book_value_purchases[sub_port_num][sale_class][fund_index] += local_book_value;
		}
	}

else 
#endif
#if defined(__RE_ASSET_H_)
if (purch_assets_type[panum] == REAL_ESTATE)
	{
	new_mp_num = seg_element->asset_mp_maps(MP_NEXT_CODE, REAL_ESTATE_CODE);
	asset->sm_re[new_mp_num]->seg_element = seg_element;
	asset->sm_re[new_mp_num]->seg_id = seg_id;

	asset->sm_re[new_mp_num]->setup_purch_inv_asset(t,
											  save_assets,
											  panum,
											  new_mp_num,
											  purch_assets_asset_sub_port_num[panum],
											  purch_asset_amt,
											  seg_element->asset_mp_sequence_num);
	
	if (asset->asset_detail_rpt_inv_strat_flag(t))
		{
		asd_sequence_num = asset->sm_re[new_mp_num]->sequence_id;
		asd_identifier = asset->sm_re[new_mp_num]->asset_id;
		asd_sub_port = asset->sm_re[new_mp_num]->purch_asset_sub_port;
		asd_class = asset->sm_re[new_mp_num]->sale_class_id;
		asd_fund = asset->sm_re[new_mp_num]->asset_fund_index;
		asd_neg_asset_flag = asset->sm_re[new_mp_num]->neg_asset_flag;
		asd_notional_amount = asset->sm_re[new_mp_num]->notional_amt_bef_sale(t);
		asd_market_value = asset->sm_re[new_mp_num]->mkt_val_bef_sale(t);
		asd_cost_basis = asset->sm_re[new_mp_num]->cost_basis_bef_sale(t);
		asd_book_value = asset->sm_re[new_mp_num]->bk_val_bef_sale(t);
		asd_ytm = 0;
		asd_wal = 0;
		asd_eff_dur = 0;
		asd_model_name = asset->sm_re[new_mp_num]->modelName;
		}
	
	local_amount_invested += purch_asset_amt;
	
	if (save_assets == NO)
		{
		purch_assets_dur_defn[panum] = NO;
		purch_assets_dur_calculated[panum] = YES;
		purch_assets_dur[panum] = 0.0;
	
		seg_element->asset_mp_maps(MP_INACTIVE_CODE, REAL_ESTATE_CODE, new_mp_num);
		}
	else // if (save_assets == YES)
		{		
		sub_port_num = xint(asset->sm_re[new_mp_num]->sub_port_id(t));
		sale_class = asset->sm_re[new_mp_num]->sale_class_id;
		fund_index = asset->sm_re[new_mp_num]->asset_fund_index;
	
		// Accumulate purchase amounts
		local_book_value = asset->sm_re[new_mp_num]->bk_val_bef_sale(t);
		local_accrued_interest = asset->sm_re[new_mp_num]->accr_rent_bef_sale(t);
	
		sub_port_fund_book_plus_accrued_purchases[sub_port_num][fund_index] += local_book_value + local_accrued_interest;
		sub_port_class_fund_accrued_interest_purchases[sub_port_num][sale_class][fund_index] += local_accrued_interest;
		sub_port_class_fund_book_value_purchases[sub_port_num][sale_class][fund_index] += local_book_value;
		}
	}

else 
#endif
#if defined(__EQT_ASSET_H_)
if (purch_assets_type[panum] == EQUITY)
	{
	new_mp_num = seg_element->asset_mp_maps(MP_NEXT_CODE, EQUITY_CODE);
	asset->sm_eqt[new_mp_num]->seg_element = seg_element;
	asset->sm_eqt[new_mp_num]->seg_id = seg_id;

	asset->sm_eqt[new_mp_num]->setup_purch_inv_asset(t,
											   save_assets,
											   panum,
											   new_mp_num,
											   purch_assets_asset_sub_port_num[panum],
											   purch_asset_amt,
											   seg_element->asset_mp_sequence_num);

	if (asset->asset_detail_rpt_inv_strat_flag(t))
		{
		asd_sequence_num = asset->sm_eqt[new_mp_num]->sequence_id;
		asd_identifier = asset->sm_eqt[new_mp_num]->asset_id;
		asd_sub_port = asset->sm_eqt[new_mp_num]->purch_asset_sub_port;
		asd_class = asset->sm_eqt[new_mp_num]->sale_class_id;
		asd_fund = asset->sm_eqt[new_mp_num]->asset_fund_index;
		asd_neg_asset_flag = asset->sm_eqt[new_mp_num]->neg_asset_flag;
		asd_notional_amount = asset->sm_eqt[new_mp_num]->notional_amt_bef_sale(t);
		asd_market_value = asset->sm_eqt[new_mp_num]->mkt_val_bef_sale(t);
		asd_cost_basis = asset->sm_eqt[new_mp_num]->cost_basis_bef_sale(t);
		asd_book_value = asset->sm_eqt[new_mp_num]->bk_val_bef_sale(t);
		asd_ytm = 0;
		asd_wal = 0;
		asd_eff_dur = 0;
		asd_model_name = asset->sm_eqt[new_mp_num]->modelName;
		}

	local_amount_invested += purch_asset_amt;
      
	if (save_assets == NO)
		{
		purch_assets_dur_defn[panum] = NO;
		purch_assets_dur_calculated[panum] = YES;
		purch_assets_dur[panum] = 0.0;

		seg_element->asset_mp_maps(MP_INACTIVE_CODE, EQUITY_CODE, new_mp_num);
		}
	else // if (save_assets == YES)
		{		
		sub_port_num = xint(asset->sm_eqt[new_mp_num]->sub_port_id(t));
		sale_class = asset->sm_eqt[new_mp_num]->sale_class_id;
		fund_index = asset->sm_eqt[new_mp_num]->asset_fund_index;

		// Accumulate purchase amounts
		local_book_value = asset->sm_eqt[new_mp_num]->bk_val_bef_sale(t);
		sub_port_fund_book_plus_accrued_purchases[sub_port_num][fund_index] += local_book_value;
		sub_port_class_fund_book_value_purchases[sub_port_num][sale_class][fund_index] += local_book_value;
		}
	}

else 
#endif
#if defined(__EIO_ASSET_H_)
if (purch_assets_type[panum] == INDEX_OPTION)
	{
	purch_asset_id = purch_asset_id;
	asset->purch_asset_yrs_to_maturity = purch_eio_yrs_to_maturity;

	new_mp_num = seg_element->asset_mp_maps(MP_NEXT_CODE, INDEX_OPTION_CODE);
	asset->sm_eio[new_mp_num][0]->seg_element = seg_element;
	asset->sm_eio[new_mp_num][0]->seg_id = seg_id;
	
	asset->sm_eio[new_mp_num][0]->setup_purch_inv_asset(t,
											   save_assets,
											   panum,
											   new_mp_num,
											   purch_assets_asset_sub_port_num[panum],
											   purch_asset_amt,
											   seg_element->asset_mp_sequence_num);
	
	if (asset->sm_eio[new_mp_num][0]->asset_detail_pv_flag(t))
		{
		PVCText << " .p. Purchasing Index Option " << purch_assets_id[panum]
				<< " |" << asset->sm_eio[new_mp_num][0]->modelName
				<< " in sub portfolio " << purch_assets_asset_sub_port_num[panum]
				<< " at time " << ((inv_purch_timing == END_OF_MONTH) ? t : t+1)
				<< " " << inv_purch_timing;
		asset->asset_detail_rpt_pv_output();
		}

	if (asset->asset_detail_rpt_inv_strat_flag(t))
		{
		asd_sequence_num = asset->sm_eio[new_mp_num][0]->sequence_id;
		asd_identifier = asset->sm_eio[new_mp_num][0]->asset_id;
		asd_sub_port = asset->sm_eio[new_mp_num][0]->purch_asset_sub_port;
		asd_class = asset->sm_eio[new_mp_num][0]->sale_class_id;
		asd_fund = asset->sm_eio[new_mp_num][0]->asset_fund_index;
		asd_neg_asset_flag = asset->sm_eio[new_mp_num][0]->neg_asset_flag;
		asd_notional_amount = asset->sm_eio[new_mp_num][0]->notional_amt_bef_sale(t);
		asd_market_value = asset->sm_eio[new_mp_num][0]->mkt_val_bef_sale(t);
		asd_cost_basis = asset->sm_eio[new_mp_num][0]->cost_basis_bef_sale(t);
		asd_book_value = asset->sm_eio[new_mp_num][0]->bk_val_bef_sale(t);
		asd_ytm = (asset->sm_eio[new_mp_num][0]->maturity_period - t) / 12.0;
		asd_wal = 0;
		asd_eff_dur = 0;
		asd_model_name = asset->sm_eio[new_mp_num][0]->modelName;
		}
	
	if (port_defn == INVESTMENT
		&& asset->sm_eio[new_mp_num][0]->mkt_val_bef_sale(t) > 0)
		local_amount_invested += purch_asset_amt;
	
	if (save_assets == NO)
		{
		purch_assets_dur_defn[panum] = NO;
		purch_assets_dur_calculated[panum] = YES;
		purch_assets_dur[panum] = 0;
	
		seg_element->asset_mp_maps(MP_INACTIVE_CODE, INDEX_OPTION_CODE, new_mp_num);
		}
	else // if (save_assets == YES)
		{
		sub_port_num = xint(asset->sm_eio[new_mp_num][0]->sub_port_id(t));
		sale_class = asset->sm_eio[new_mp_num][0]->sale_class_id;
		fund_index = asset->sm_eio[new_mp_num][0]->asset_fund_index;
	
		// accumulate "purchase" amounts
		local_book_value = asset->sm_eio[new_mp_num][0]->bk_val_bef_sale(t);
	
		sub_port_fund_book_plus_accrued_purchases[sub_port_num][fund_index] += local_book_value;
		sub_port_class_fund_book_value_purchases[sub_port_num][sale_class][fund_index] += local_book_value;
		}
	}

else 
#endif
	{
	; // Leave this semi-colon as a placeholder for the "else" clauses above.
	}
	
if (save_assets == NO
	&& purch_assets_dur_defn[panum] == YES)
	{
	expected_mkt_val_for_dur_purch += purch_asset_amt;
	expected_mkt_val_times_dur_purch += purch_asset_amt * purch_assets_dur[panum];
	}

if (asset->asset_detail_rpt_inv_strat_flag(t))
	asset_detail_rpt_buy_purch_asset(t, 
									 PURCHASED,
									 asd_sequence_num,
									 asd_identifier,
									 asd_sub_port,
									 asset->zSalesClass[asd_class],
									 asset->zAssetFund[asd_fund],
									 asd_neg_asset_flag, 
									 asd_notional_amount,
									 asd_market_value,
									 asd_cost_basis,
									 asd_book_value,
									 asd_ytm, asd_wal,
									 asd_eff_dur);

investing_flag = false;

return local_amount_invested;
}



#line 1 "clear_expected_sale_vars.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::clear_expected_sale_vars(int t)
{
int asset_sub_port;
int fund_index;

// clear expected sales variables
expected_sold_at_bk = 0.0;
expected_mkt_val_for_dur_sale = 0.0;
expected_mkt_val_times_dur_sale = 0.0;

for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
	{
	for (fund_index = 0; fund_index < MAXIMUM_NUMBER_OF_ASSET_FUNDS; fund_index++)
		sub_port_fund_expected_book_plus_accrued_sold[asset_sub_port][fund_index] = 0;
	}

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	seg_element->SALFile << " <<< clear expected sales variables >>>" << endl;
	}

return;
}



#line 1 "create_extreme_val_multimap.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::create_extreme_val_multimap(int t, StrEnum::EnumValue sales_type, StrEnum::EnumValue extreme_selection)
{
int local_asset_defn = 0;
int mp = 0;
int sub_port_num = 0;
int sales_class_num = 0;
int asset_fund_index = 0;
double asset_percent_remaining = 0.0;
bool is_negative_cash_flow_sales = (sales_type == NEGATIVE_CASH_FLOW_SALES);

int col_num_asset_sub_port_num = 0;
int col_num_dur_val = 0;
int col_num_notional_amount_before_sales = 0;
int col_num_notional_amount = 0;
int col_num_portion_of_asset_sold_planned_sales = 0;
int col_num_market_to_book_ratio = 0;
int col_num_unrealized_capital_gains_to_book_ratio = 0;
int col_num_portion_of_asset_sold_rebal_sales = 0;

//A_SUBPORT_ASSET * current_sub_port;

extreme_value_multimap.clear();

#define EXTREME_MULTIMAP_VALUES 0	// 1 for values, 0 for no values (values are written to the SALFile)
#if EXTREME_MULTIMAP_VALUES
bool write_detail = asset_detail_rpt_inv_strat_flag(t);

if (write_detail)
	{
	xstring extreme_type
	= ((extreme_selection == MAXIMIZE_CAPITAL_GAIN) ? "Maximize Capital Gain"
	: ((extreme_selection == LONGEST_DURATION) ? "Longest Duration"
	: ((extreme_selection == SHORTEST_DURATION) ? "Shortest Duration" : "Pro Rata")));

	SALFile << endl;
	SALFile << " .e. create_extreme_val_multimap - unordered -"
			<< " Period=" << t
			<< " Year=" << xint(cal_yr(t))
			<< " Month=" << xint(cal_mth(t))
			<< " Selection=" << extreme_type
			<< endl;
	SALFile << "    mkt.to.bk.ratio unr.cg.to.bk.ratio     duration.value   not.amt.bef.sale Gp Com SeqNo Identifier |modelName asset_purp (purchase type)"
			<< endl;
	SALFile << " ------------------ ------------------ ------------------ ------------------ -- --- ----- -------------------------------------------------- "
			//   9999.9999999999999 99999999999.999999 99999999999.999999 99999999999.999999 99 999 99999 xxxxxxx |{asset type}
			<< endl;
	}
#endif

// need separate processing for each asset type
map <int, long, less <int> >::iterator mp_map_iter;

#if defined(__BOND_ASSET_H_)
// Loop over bonds
local_asset_defn = BOND_CODE;
if (seg_element->bond_mp_map_active.size())
	{
	col_num_asset_sub_port_num
	= asset->sm_bond[0][0]->Column("sub_port_id").Number();
	col_num_dur_val
	= asset->sm_bond[0][0]->Column("dur_val").Number();
	col_num_notional_amount
	= asset->sm_bond[0][0]->Column("notional_amt").Number();
	col_num_portion_of_asset_sold_planned_sales
	= asset->sm_bond[0][0]->Column("sold_pct_planned").Number();
	col_num_market_to_book_ratio
	= asset->sm_bond[0][0]->Column("mkt_to_bk_ratio").Number();
	col_num_unrealized_capital_gains_to_book_ratio
	= asset->sm_bond[0][0]->Column("unrealzd_cap_gain_to_bk_ratio").Number();

	if (is_negative_cash_flow_sales)
		{
		col_num_notional_amount_before_sales
		= asset->sm_bond[0][0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
		col_num_portion_of_asset_sold_rebal_sales
		= asset->sm_bond[0][0]->Column("sold_pct_rebal").Number();
		}
	else // is rebalancing sales
		{
		col_num_notional_amount_before_sales
		= asset->sm_bond[0][0]->Column("notional_amt_bef_rebal_sale").Number();
		}
	}

for (mp_map_iter = seg_element->bond_mp_map_active.begin();
	 mp_map_iter != seg_element->bond_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_bond[mp][0]->neg_asset_flag < 0)
		continue;

	if ((t >= max(0, asset->sm_bond[mp][0]->commencement_period)
		&& asset->sm_bond[mp][0]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
		continue;

	sub_port_num = xint(asset->sm_bond[mp][0]->Column(col_num_asset_sub_port_num).Value(t));
	sales_class_num = asset->sm_bond[mp][0]->sale_class_id;
	asset_fund_index = asset->sm_bond[mp][0]->asset_fund_index;
	current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

	if (current_sub_port->sub_ports_to_sell != 1
		|| asset_class_to_sell_flag[sales_class_num] != 1
		|| asset_fund_to_sell_flag[asset_fund_index] != 1)
		continue;

	asset_percent_remaining
	= (1.0 - asset->sm_bond[mp][0]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

	if (is_negative_cash_flow_sales)
		asset_percent_remaining
		*= (1.0 - asset->sm_bond[mp][0]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

	if (asset_percent_remaining > rate_ratio_threshold)
		{
		create_extreme_val_multimap_entry(extreme_selection,
				asset->sm_bond[mp][0]->Column(col_num_market_to_book_ratio).Value(t),
				asset->sm_bond[mp][0]->Column(col_num_unrealized_capital_gains_to_book_ratio).Value(t),
				asset->sm_bond[mp][0]->Column(col_num_dur_val).Value(t),
				asset->sm_bond[mp][0]->Column(col_num_notional_amount_before_sales).Value(t),
				local_asset_defn, mp);

#if EXTREME_MULTIMAP_VALUES
		if (write_detail)
			{
			double local_mkt_to_bk
			= asset->sm_bond[mp][0]->Column(col_num_market_to_book_ratio).Value(t);
			double local_ucg_to_bk
			= asset->sm_bond[mp][0]->Column(col_num_unrealized_capital_gains_to_book_ratio).Value(t);
			double local_dur_val
			= asset->sm_bond[mp][0]->Column(col_num_dur_val).Value(t);
			double local_not_amt_bef_sales
			= asset->sm_bond[mp][0]->Column(col_num_notional_amount_before_sales).Value(t);

			seg_element->SALFile << " " << setw(18) << write_string(local_mkt_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_ucg_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_dur_val, 18, 15)
					     << " " << setw(18) << write_string(local_not_amt_bef_sales, 18, 15)
					     << " " << setw(2) << setprecision(0) << xint(asset->sm_bond[mp][0]->sub_port_id(t))
					     << " " << setw(4) << asset->sm_bond[mp][0]->commencement_period
					     << " " << setw(5) << asset->sm_bond[mp][0]->sequence_id
					     << " " << setw(9) << asset->sm_bond[mp][0]->asset_id
					     << " |" << asset->sm_bond[mp][0]->modelName
					     << " " << asset->sm_bond[mp][0]->port_defn
					     << endl;
			}
#endif
		}
	} // end for loop over bonds
#endif

#if defined(__MTG_ASSET_H_)
local_asset_defn = MORTGAGE_CODE;
if (seg_element->mtg_mp_map_active.size())
	{
	col_num_asset_sub_port_num
	= asset->sm_mtg[0][0]->Column("sub_port_id").Number();
	col_num_dur_val
	= asset->sm_mtg[0][0]->Column("dur_val").Number();
	col_num_notional_amount
	= asset->sm_mtg[0][0]->Column("notional_amt").Number();
	col_num_portion_of_asset_sold_planned_sales
	= asset->sm_mtg[0][0]->Column("sold_pct_planned").Number();
	col_num_market_to_book_ratio
	= asset->sm_mtg[0][0]->Column("mkt_to_bk_ratio").Number();
	col_num_unrealized_capital_gains_to_book_ratio
	= asset->sm_mtg[0][0]->Column("unrealzd_cap_gain_to_bk_ratio").Number();

	if (is_negative_cash_flow_sales)
		{
		col_num_notional_amount_before_sales
		= asset->sm_mtg[0][0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
		col_num_portion_of_asset_sold_rebal_sales
		= asset->sm_mtg[0][0]->Column("sold_pct_rebal").Number();
		}
	else // is rebalancing sales
		{
		col_num_notional_amount_before_sales
		= asset->sm_mtg[0][0]->Column("notional_amt_bef_rebal_sale").Number();
		}
	}

for (mp_map_iter = seg_element->mtg_mp_map_active.begin();
	 mp_map_iter != seg_element->mtg_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_mtg[mp][0]->neg_asset_flag < 0)
		continue;

	if ((t >= max(0, asset->sm_mtg[mp][0]->commencement_period)
		&& asset->sm_mtg[mp][0]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
		continue;

	sub_port_num = xint(asset->sm_mtg[mp][0]->Column(col_num_asset_sub_port_num).Value(t));
	sales_class_num = asset->sm_mtg[mp][0]->sale_class_id;
	asset_fund_index = asset->sm_mtg[mp][0]->asset_fund_index;
	current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

	if (current_sub_port->sub_ports_to_sell != 1
		|| asset_class_to_sell_flag[sales_class_num] != 1
		|| asset_fund_to_sell_flag[asset_fund_index] != 1)
		continue;

	asset_percent_remaining
	= (1.0 - asset->sm_mtg[mp][0]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

	if (is_negative_cash_flow_sales)
		asset_percent_remaining
		*= (1.0 - asset->sm_mtg[mp][0]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

	if (asset_percent_remaining > rate_ratio_threshold)
		{
		create_extreme_val_multimap_entry(extreme_selection,
				asset->sm_mtg[mp][0]->mkt_to_bk_ratio(t),
				asset->sm_mtg[mp][0]->unrealzd_cap_gain_to_bk_ratio(t),
				asset->sm_mtg[mp][0]->dur_val(t),
				asset->sm_mtg[mp][0]->notional_amt_bef_sale(t),
				local_asset_defn, mp);

#if EXTREME_MULTIMAP_VALUES
		if (write_detail)
			{
			double local_mkt_to_bk
			= asset->sm_mtg[mp][0]->Column(col_num_market_to_book_ratio).Value(t);
			double local_ucg_to_bk
			= asset->sm_mtg[mp][0]->Column(col_num_unrealized_capital_gains_to_book_ratio).Value(t);
			double local_dur_val
			= asset->sm_mtg[mp][0]->Column(col_num_dur_val).Value(t);
			double local_not_amt_bef_sales
			= asset->sm_mtg[mp][0]->Column(col_num_notional_amount_before_sales).Value(t);

			seg_element->SALFile << " " << setw(18) << write_string(local_mkt_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_ucg_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_dur_val, 18, 15)
					     << " " << setw(18) << write_string(local_not_amt_bef_sales, 18, 15)
					     << " " << setw(2) << setprecision(0) << xint(asset->sm_mtg[mp][0]->sub_port_id(t))
					     << " " << setw(4) << asset->sm_mtg[mp][0]->commencement_period
					     << " " << setw(5) << asset->sm_mtg[mp][0]->sequence_id
					     << " " << setw(9) << asset->sm_mtg[mp][0]->asset_id
					     << " |" << asset->sm_mtg[mp][0]->modelName
					     << " " << asset->sm_mtg[mp][0]->port_defn
					     << endl;
			}
#endif
		}
	} // end for loop over mtgs
#endif

#if defined(__SEC_ASSET_H_)
local_asset_defn = SEC_CODE;
if (seg_element->sec_mp_map_active.size())
	{
	col_num_asset_sub_port_num
	= asset->sm_sec[0]->Column("sub_port_id").Number();
	col_num_dur_val
	= asset->sm_sec[0]->Column("dur_val").Number();
	col_num_notional_amount
	= asset->sm_sec[0]->Column("notional_amt").Number();
	col_num_portion_of_asset_sold_planned_sales
	= asset->sm_sec[0]->Column("sold_pct_planned").Number();
	col_num_market_to_book_ratio
	= asset->sm_sec[0]->Column("mkt_to_bk_ratio").Number();
	col_num_unrealized_capital_gains_to_book_ratio
	= asset->sm_sec[0]->Column("unrealzd_cap_gain_to_bk_ratio").Number();

	if (is_negative_cash_flow_sales)
		{
		col_num_notional_amount_before_sales
		= asset->sm_sec[0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
		col_num_portion_of_asset_sold_rebal_sales
		= asset->sm_sec[0]->Column("sold_pct_rebal").Number();
		}
	else // is rebalancing sales
		{
		col_num_notional_amount_before_sales
		= asset->sm_sec[0]->Column("notional_amt_bef_rebal_sale").Number();
		}
	}

for (mp_map_iter = seg_element->sec_mp_map_active.begin();
	 mp_map_iter != seg_element->sec_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_sec[mp]->neg_asset_flag < 0)
		continue;

	if (t >= max(0, asset->sm_sec[mp]->commencement_period)
		&& asset->sm_sec[mp]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD)
		continue;

	sub_port_num = xint(asset->sm_sec[mp]->Column(col_num_asset_sub_port_num).Value(t));
	sales_class_num = asset->sm_sec[mp]->sale_class_id;
	asset_fund_index = asset->sm_sec[mp]->asset_fund_index;
	current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

	if (current_sub_port->sub_ports_to_sell != 1
		|| asset_class_to_sell_flag[sales_class_num] != 1
		|| asset_fund_to_sell_flag[asset_fund_index] != 1)
		continue;

	asset_percent_remaining
	= (1.0 - asset->sm_sec[mp]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

	if (is_negative_cash_flow_sales)
		asset_percent_remaining
		*= (1.0 - asset->sm_sec[mp]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

	if (asset_percent_remaining > SMALL_DOUBLE)
		{
		create_extreme_val_multimap_entry(extreme_selection,
				asset->sm_sec[mp]->mkt_to_bk_ratio(t),
				asset->sm_sec[mp]->unrealzd_cap_gain_to_bk_ratio(t),
				asset->sm_sec[mp]->dur_val(t),
				asset->sm_sec[mp]->notional_amt_bef_sale(t),
				local_asset_defn, mp);

#if EXTREME_MULTIMAP_VALUES
		if (write_detail)
			{
			double local_mkt_to_bk
			= asset->sm_sec[mp]->Column(col_num_market_to_book_ratio).Value(t);
			double local_ucg_to_bk
			= asset->sm_sec[mp]->Column(col_num_unrealized_capital_gains_to_book_ratio).Value(t);
			double local_dur_val
			= asset->sm_sec[mp]->Column(col_num_dur_val).Value(t);
			double local_not_amt_bef_sales
			= asset->sm_sec[mp]->Column(col_num_notional_amount_before_sales).Value(t);

			seg_element->SALFile << " " << setw(18) << write_string(local_mkt_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_ucg_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_dur_val, 18, 15)
					     << " " << setw(18) << write_string(local_not_amt_bef_sales, 18, 15)
					     << " " << setw(2) << setprecision(0) << xint(asset->sm_sec[mp]->sub_port_id(t))
					     << " " << setw(4) << asset->sm_sec[mp]->commencement_period
					     << " " << setw(5) << asset->sm_sec[mp]->sequence_id
					     << " " << setw(9) << asset->sm_sec[mp]->asset_id
					     << " |" << asset->sm_sec[mp]->modelName
					     << " " << asset->sm_sec[mp]->port_defn
					     << endl;
			}
#endif
		}
	} // end for loop over sec
#endif

#if defined(__IRD_ASSET_H_)
// Loop over interest contracts
local_asset_defn = IRD_CODE;
if (seg_element->ird_mp_map_active.size())
	{
	col_num_asset_sub_port_num
	= asset->sm_ird[0][0]->Column("sub_port_id").Number();
	col_num_dur_val
	= asset->sm_ird[0][0]->Column("dur_val").Number();
	col_num_notional_amount
	= asset->sm_ird[0][0]->Column("notional_amt").Number();
	col_num_portion_of_asset_sold_planned_sales
	= asset->sm_ird[0][0]->Column("sold_pct_planned").Number();
	col_num_market_to_book_ratio
	= asset->sm_ird[0][0]->Column("mkt_to_bk_ratio").Number();
	col_num_unrealized_capital_gains_to_book_ratio
	= asset->sm_ird[0][0]->Column("unrealzd_cap_gain_to_bk_ratio").Number();

	if (is_negative_cash_flow_sales)
		{
		col_num_notional_amount_before_sales
		= asset->sm_ird[0][0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
		col_num_portion_of_asset_sold_rebal_sales
		= asset->sm_ird[0][0]->Column("sold_pct_rebal").Number();
		}
	else // is rebalancing sales
		{
		col_num_notional_amount_before_sales
		= asset->sm_ird[0][0]->Column("notional_amt_bef_rebal_sale").Number();
		}
	}

for (mp_map_iter = seg_element->ird_mp_map_active.begin();
	 mp_map_iter != seg_element->ird_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_ird[mp][0]->neg_asset_flag < 0)
		continue;

	if (t >= max(0, asset->sm_ird[mp][0]->commencement_period)
		&& asset->sm_ird[mp][0]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD)
		continue;

	sub_port_num = xint(asset->sm_ird[mp][0]->Column(col_num_asset_sub_port_num).Value(t));
	sales_class_num = asset->sm_ird[mp][0]->sale_class_id;
	asset_fund_index = asset->sm_ird[mp][0]->asset_fund_index;
	current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

	if (current_sub_port->sub_ports_to_sell != 1
		|| asset_class_to_sell_flag[sales_class_num] != 1
		|| asset_fund_to_sell_flag[asset_fund_index] != 1)
		continue;

	asset_percent_remaining
	= (1.0 - asset->sm_ird[mp][0]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

	if (is_negative_cash_flow_sales)
		asset_percent_remaining
		*= (1.0 - asset->sm_ird[mp][0]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

	if (asset_percent_remaining > SMALL_DOUBLE)
		{
		create_extreme_val_multimap_entry(extreme_selection,
				asset->sm_ird[mp][0]->mkt_to_bk_ratio(t),
				asset->sm_ird[mp][0]->unrealzd_cap_gain_to_bk_ratio(t),
				asset->sm_ird[mp][0]->dur_val(t),
				asset->sm_ird[mp][0]->notional_amt_bef_sale(t),
				local_asset_defn, mp);

#if EXTREME_MULTIMAP_VALUES
		if (write_detail)
			{
			double local_mkt_to_bk
			= asset->sm_ird[mp][0]->Column(col_num_market_to_book_ratio).Value(t);
			double local_ucg_to_bk
			= asset->sm_ird[mp][0]->Column(col_num_unrealized_capital_gains_to_book_ratio).Value(t);
			double local_dur_val
			= asset->sm_ird[mp][0]->Column(col_num_dur_val).Value(t);
			double local_not_amt_bef_sales
			= asset->sm_ird[mp][0]->Column(col_num_notional_amount_before_sales).Value(t);

			seg_element->SALFile << " " << setw(18) << write_string(local_mkt_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_ucg_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_dur_val, 18, 15)
					     << " " << setw(18) << write_string(local_not_amt_bef_sales, 18, 15)
					     << " " << setw(2) << setprecision(0) << xint(asset->sm_ird[mp][0]->sub_port_id(t))
					     << " " << setw(4) << asset->sm_ird[mp][0]->commencement_period
					     << " " << setw(5) << asset->sm_ird[mp][0]->sequence_id
					     << " " << setw(9) << asset->sm_ird[mp][0]->asset_id
					     << " |" << asset->sm_ird[mp][0]->modelName
					     << " " << asset->sm_ird[mp][0]->port_defn
					     << endl;
			}
#endif
		}
	} // end for loop over interest rate derivatives
#endif

#if defined(__RE_ASSET_H_)
// Loop over real estate
local_asset_defn = REAL_ESTATE_CODE;
if (seg_element->re_mp_map_active.size())
	{
	col_num_asset_sub_port_num
	= asset->sm_re[0]->Column("sub_port_id").Number();
//	col_num_dur_val = -1; // no duration neasure for real estate
	col_num_notional_amount
	= asset->sm_re[0]->Column("notional_amt").Number();
	col_num_portion_of_asset_sold_planned_sales
	= asset->sm_re[0]->Column("sold_pct_planned").Number();
	col_num_market_to_book_ratio
	= asset->sm_re[0]->Column("mkt_to_bk_ratio").Number();
	col_num_unrealized_capital_gains_to_book_ratio
	= asset->sm_re[0]->Column("unrealzd_cap_gain_to_bk_ratio").Number();

	if (is_negative_cash_flow_sales)
		{
		col_num_notional_amount_before_sales
		= asset->sm_re[0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
		col_num_portion_of_asset_sold_rebal_sales
		= asset->sm_re[0]->Column("sold_pct_rebal").Number();
		}
	else // is rebalancing sales
		{
		col_num_notional_amount_before_sales
		= asset->sm_re[0]->Column("notional_amt_bef_rebal_sale").Number();
		}
	}

for (mp_map_iter = seg_element->re_mp_map_active.begin();
	 mp_map_iter != seg_element->re_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_re[mp]->neg_asset_flag < 0)
		continue;

	if (t >= max(0, asset->sm_re[mp]->commencement_period)
		&& asset->sm_re[mp]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD)
		continue;

	sub_port_num = xint(asset->sm_re[mp]->Column(col_num_asset_sub_port_num).Value(t));
	sales_class_num = asset->sm_re[mp]->sale_class_id;
	asset_fund_index = asset->sm_re[mp]->asset_fund_index;
	current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

	if (current_sub_port->sub_ports_to_sell != 1
		|| asset_class_to_sell_flag[sales_class_num] != 1
		|| asset_fund_to_sell_flag[asset_fund_index] != 1)
		continue;

	asset_percent_remaining
	= (1.0 - asset->sm_re[mp]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

	if (is_negative_cash_flow_sales)
		asset_percent_remaining
		*= (1.0 - asset->sm_re[mp]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

	if (asset_percent_remaining > SMALL_DOUBLE)
		{
		create_extreme_val_multimap_entry(extreme_selection,
				asset->sm_re[mp]->Column(col_num_market_to_book_ratio).Value(t),
				asset->sm_re[mp]->Column(col_num_unrealized_capital_gains_to_book_ratio).Value(t),
				0.0, // duration measure
				asset->sm_re[mp]->Column(col_num_notional_amount_before_sales).Value(t),
				local_asset_defn, mp);

#if EXTREME_MULTIMAP_VALUES
		if (write_detail)
			{
			double local_mkt_to_bk
			= asset->sm_re[mp]->Column(col_num_market_to_book_ratio).Value(t);
			double local_ucg_to_bk
			= asset->sm_re[mp]->Column(col_num_unrealized_capital_gains_to_book_ratio).Value(t);
			double local_dur_val
			= 0;
			double local_not_amt_bef_sales
			= asset->sm_re[mp]->Column(col_num_notional_amount_before_sales).Value(t);

			SALFile << " " << setw(18) << write_string(local_mkt_to_bk, 18, 15)
					<< " " << setw(18) << write_string(local_ucg_to_bk, 18, 15)
					<< " " << setw(18) << write_string(local_dur_val, 18, 15)
					<< " " << setw(18) << write_string(local_not_amt_bef_sales, 18, 15)
					<< " " << setw(2) << setprecision(0) << xint(asset->sm_re[mp]->sub_port_id(t))
					<< " " << setw(4) << asset->sm_re[mp]->commencement_period
					<< " " << setw(5) << asset->sm_re[mp]->sequence_id
					<< " " << setw(9) << asset->sm_re[mp]->asset_id
					<< " |" << asset->sm_re[mp]->modelName
					<< " " << asset->sm_re[mp]->port_defn
					<< endl;
			}
#endif
		}
	} // end for loop over real estate
#endif

#if defined(__EQT_ASSET_H_)
// Loop over equities
local_asset_defn = EQUITY_CODE;
if (seg_element->eqt_mp_map_active.size())
	{
	col_num_asset_sub_port_num
	= asset->sm_eqt[0]->Column("sub_port_id").Number();
//	col_num_dur_val = -1; // no duration neasure for equities
	col_num_notional_amount
	= asset->sm_eqt[0]->Column("notional_amt").Number();
	col_num_portion_of_asset_sold_planned_sales
	= asset->sm_eqt[0]->Column("sold_pct_planned").Number();
	col_num_market_to_book_ratio
	= asset->sm_eqt[0]->Column("mkt_to_bk_ratio").Number();
	col_num_unrealized_capital_gains_to_book_ratio
	= asset->sm_eqt[0]->Column("unrealzd_cap_gain_to_bk_ratio").Number();

	if (is_negative_cash_flow_sales)
		{
		col_num_notional_amount_before_sales
		= asset->sm_eqt[0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
		col_num_portion_of_asset_sold_rebal_sales
		= asset->sm_eqt[0]->Column("sold_pct_rebal").Number();
		}
	else // is rebalancing sales
		{
		col_num_notional_amount_before_sales
		= asset->sm_eqt[0]->Column("notional_amt_bef_rebal_sale").Number();
		}
	}

for (mp_map_iter = seg_element->eqt_mp_map_active.begin();
	 mp_map_iter != seg_element->eqt_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_eqt[mp]->neg_asset_flag < 0)
		continue;

	if (t >= max(0, asset->sm_eqt[mp]->commencement_period)
		&& asset->sm_eqt[mp]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD)
		continue;

	sub_port_num = xint(asset->sm_eqt[mp]->sub_port_id(t));
	sales_class_num = asset->sm_eqt[mp]->sale_class_id;
	asset_fund_index = asset->sm_eqt[mp]->asset_fund_index;
	current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

	if (current_sub_port->sub_ports_to_sell != 1
		|| asset_class_to_sell_flag[sales_class_num] != 1
		|| asset_fund_to_sell_flag[asset_fund_index] != 1)
		continue;

	asset_percent_remaining
	= (1.0 - asset->sm_eqt[mp]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

	if (is_negative_cash_flow_sales)
		asset_percent_remaining
		*= (1.0 - asset->sm_eqt[mp]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

	if (asset_percent_remaining > SMALL_DOUBLE)
		{
		create_extreme_val_multimap_entry(extreme_selection,
				asset->sm_eqt[mp]->Column(col_num_market_to_book_ratio).Value(t),
				asset->sm_eqt[mp]->Column(col_num_unrealized_capital_gains_to_book_ratio).Value(t),
				0.0, // duration measure
				asset->sm_eqt[mp]->Column(col_num_notional_amount_before_sales).Value(t),
				local_asset_defn, mp);

#if EXTREME_MULTIMAP_VALUES
		if (write_detail)
			{
			double local_mkt_to_bk
			= asset->sm_eqt[mp]->Column(col_num_market_to_book_ratio).Value(t);
			double local_ucg_to_bk
			= asset->sm_eqt[mp]->Column(col_num_unrealized_capital_gains_to_book_ratio).Value(t);
			double local_dur_val
			= 0;
			double local_not_amt_bef_sales
			= asset->sm_eqt[mp]->Column(col_num_notional_amount_before_sales).Value(t);

			seg_element->SALFile << " " << setw(18) << write_string(local_mkt_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_ucg_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_dur_val, 18, 15)
					     << " " << setw(18) << write_string(local_not_amt_bef_sales, 18, 15)
					     << " " << setw(2) << setprecision(0) << xint(asset->sm_eqt[mp]->sub_port_id(t))
					     << " " << setw(4) << asset->sm_eqt[mp]->commencement_period
					     << " " << setw(5) << asset->sm_eqt[mp]->sequence_id
					     << " " << setw(9) << asset->sm_eqt[mp]->asset_id
					     << " |" << asset->sm_eqt[mp]->modelName
					     << " " << asset->sm_eqt[mp]->port_defn
					     << endl;
			}
#endif
		}
	} // end for loop over equities
#endif


#if defined(__EIO_ASSET_H_)
// Loop over index options
local_asset_defn = INDEX_OPTION_CODE;
if (seg_element->eio_mp_map_active.size())
	{
	col_num_asset_sub_port_num
	= asset->sm_eio[0][0]->Column("sub_port_id").Number();
	col_num_dur_val
	= asset->sm_eio[0][0]->Column("dur_val").Number();
	col_num_notional_amount
	= asset->sm_eio[0][0]->Column("notional_amt").Number();
	col_num_portion_of_asset_sold_planned_sales
	= asset->sm_eio[0][0]->Column("sold_pct_planned").Number();
	col_num_market_to_book_ratio
	= asset->sm_eio[0][0]->Column("mkt_to_bk_ratio").Number();
	col_num_unrealized_capital_gains_to_book_ratio
	= asset->sm_eio[0][0]->Column("unrealzd_cap_gain_to_bk_ratio").Number();

	if (is_negative_cash_flow_sales)
		{
		col_num_notional_amount_before_sales
		= asset->sm_eio[0][0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
		col_num_portion_of_asset_sold_rebal_sales
		= asset->sm_eio[0][0]->Column("sold_pct_rebal").Number();
		}
	else // is rebalancing sales
		{
		col_num_notional_amount_before_sales
		= asset->sm_eio[0][0]->Column("notional_amt_bef_rebal_sale").Number();
		}
	}

for (mp_map_iter = seg_element->eio_mp_map_active.begin();
	 mp_map_iter != seg_element->eio_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_eio[mp][0]->neg_asset_flag < 0)
		continue;

	if (t >= max(0, asset->sm_eio[mp][0]->commencement_period)
			&& asset->sm_eio[mp][0]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD)
		continue;

	sub_port_num = xint(asset->sm_eio[mp][0]->Column(col_num_asset_sub_port_num).Value(t));
	sales_class_num = asset->sm_eio[mp][0]->sale_class_id;
	asset_fund_index = asset->sm_eio[mp][0]->asset_fund_index;
	current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

	if (current_sub_port->sub_ports_to_sell != 1
		|| asset_class_to_sell_flag[sales_class_num] != 1
		|| asset_fund_to_sell_flag[asset_fund_index] != 1)
		continue;

	asset_percent_remaining
	= (1.0 - asset->sm_eio[mp][0]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

	if (is_negative_cash_flow_sales)
		asset_percent_remaining
		*= (1.0 - asset->sm_eio[mp][0]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

	if (asset_percent_remaining > SMALL_DOUBLE)
		{
		create_extreme_val_multimap_entry(extreme_selection,
				asset->sm_eio[mp][0]->Column(col_num_market_to_book_ratio).Value(t),
				asset->sm_eio[mp][0]->Column(col_num_unrealized_capital_gains_to_book_ratio).Value(t),
				asset->sm_eio[mp][0]->Column(col_num_dur_val).Value(t),
				asset->sm_eio[mp][0]->Column(col_num_notional_amount_before_sales).Value(t),
				local_asset_defn, mp);

#if EXTREME_MULTIMAP_VALUES
		if (write_detail)
			{
			double local_mkt_to_bk
			= asset->sm_eio[mp][0]->Column(col_num_market_to_book_ratio).Value(t);
			double local_ucg_to_bk
			= asset->sm_eio[mp][0]->Column(col_num_unrealized_capital_gains_to_book_ratio).Value(t);
			double local_dur_val
			= asset->sm_eio[mp][0]->Column(col_num_dur_val).Value(t);
			double local_not_amt_bef_sales
			= asset->sm_eio[mp][0]->Column(col_num_notional_amount_before_sales).Value(t);

			seg_element->SALFile << " " << setw(18) << write_string(local_mkt_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_ucg_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_dur_val, 18, 15)
					     << " " << setw(18) << write_string(local_not_amt_bef_sales, 18, 15)
					     << " " << setw(2) << setprecision(0) << xint(asset->sm_eio[mp][0]->sub_port_id(t))
					     << " " << setw(4) << asset->sm_eio[mp][0]->commencement_period
					     << " " << setw(5) << asset->sm_eio[mp][0]->sequence_id
					     << " " << setw(9) << asset->sm_eio[mp][0]->asset_id
					     << " |" << asset->sm_eio[mp][0]->modelName
					     << " " << asset->sm_eio[mp][0]->port_defn
					     << endl;
			}
#endif
		}
	} // end for loop over indx options
#endif

#if defined(__EPA_ASSET_H_)
// Loop over epas
local_asset_defn = EPA_CODE;
if (seg_element->epa_mp_map_active.size())
	{
	col_num_asset_sub_port_num
	= asset->sm_epa[0]->Column("sub_port_id").Number();
	col_num_dur_val
	= asset->sm_epa[0]->Column("dur_val").Number();
	col_num_notional_amount
	= asset->sm_epa[0]->Column("notional_amt").Number();
	col_num_portion_of_asset_sold_planned_sales
	= asset->sm_epa[0]->Column("sold_pct_planned").Number();
	col_num_market_to_book_ratio
	= asset->sm_epa[0]->Column("mkt_to_bk_ratio").Number();
	col_num_unrealized_capital_gains_to_book_ratio
	= asset->sm_epa[0]->Column("unrealzd_cap_gain_to_bk_ratio").Number();

	if (is_negative_cash_flow_sales)
		{
		col_num_notional_amount_before_sales
		= asset->sm_epa[0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
		col_num_portion_of_asset_sold_rebal_sales
		= asset->sm_epa[0]->Column("sold_pct_rebal").Number();
		}
	else // is rebalancing sales
		{
		col_num_notional_amount_before_sales
		= asset->sm_epa[0]->Column("notional_amt_bef_rebal_sale").Number();
		}
	}

for (mp_map_iter = seg_element->epa_mp_map_active.begin();
	 mp_map_iter != seg_element->epa_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_epa[mp]->neg_asset_flag < 0)
		continue;

	if (asset->sm_epa[mp]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD)
		continue;

	sub_port_num = xint(asset->sm_epa[mp]->Column(col_num_asset_sub_port_num).Value(t));
	sales_class_num = asset->sm_epa[mp]->sale_class_id;
	asset_fund_index = asset->sm_epa[mp]->asset_fund_index;
	current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

	if (current_sub_port->sub_ports_to_sell != 1
		|| asset_class_to_sell_flag[sales_class_num] != 1
		|| asset_fund_to_sell_flag[asset_fund_index] != 1)
		continue;

	asset_percent_remaining
	= (1.0 - asset->sm_epa[mp]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

	if (is_negative_cash_flow_sales)
		asset_percent_remaining
		*= (1.0 - asset->sm_epa[mp]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

	if (asset_percent_remaining > SMALL_DOUBLE)
		{
		create_extreme_val_multimap_entry(extreme_selection,
				asset->sm_epa[mp]->Column(col_num_market_to_book_ratio).Value(t),
				asset->sm_epa[mp]->Column(col_num_unrealized_capital_gains_to_book_ratio).Value(t),
				asset->sm_epa[mp]->Column(col_num_dur_val).Value(t),
				asset->sm_epa[mp]->Column(col_num_notional_amount_before_sales).Value(t),
				local_asset_defn, mp);

#if EXTREME_MULTIMAP_VALUES
		if (write_detail)
			{
			double local_mkt_to_bk
			= asset->sm_epa[mp]->Column(col_num_market_to_book_ratio).Value(t);
			double local_ucg_to_bk
			= asset->sm_epa[mp]->Column(col_num_unrealized_capital_gains_to_book_ratio).Value(t);
			double local_dur_val
			= asset->sm_epa[mp]->Column(col_num_dur_val).Value(t);
			double local_not_amt_bef_sales
			= asset->sm_epa[mp]->Column(col_num_notional_amount_before_sales).Value(t);

			seg_element->SALFile << " " << setw(18) << write_string(local_mkt_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_ucg_to_bk, 18, 15)
					     << " " << setw(18) << write_string(local_dur_val, 18, 15)
					     << " " << setw(18) << write_string(local_not_amt_bef_sales, 18, 15)
					     << " " << setw(2) << setprecision(0) << xint(asset->sm_epa[mp]->sub_port_id(t))
					     << " " << setw(4) << asset->sm_epa[mp]->commencement_period
					     << " " << setw(5) << asset->sm_epa[mp]->sequence_id
					     << " " << setw(9) << asset->sm_epa[mp]->asset_id
					     << " |" << asset->sm_epa[mp]->modelName
					     << " " << asset->sm_epa[mp]->port_defn
					     << endl;
			}
#endif
		}
	} // end for loop over epas
#endif

#if EXTREME_MULTIMAP_VALUES
if (write_detail)
	{
	xstring extreme_type
	= ((extreme_selection == MAXIMIZE_CAPITAL_GAIN) ? "Maximize Capital Gain"
	: ((extreme_selection == LONGEST_DURATION) ? "Longest Duration"
	: ((extreme_selection == SHORTEST_DURATION) ? "Shortest Duration" : "Pro Rata")));

	seg_element->SALFile << endl;
	seg_element->SALFile << " .e. create_extreme_val_multimap - ordered -"
			     << " Period=" << t
			     << " Year=" << xint(cal_yr(t))
			     << " Month=" << xint(cal_mth(t))
			     << " Selection=" << extreme_type
			     << endl;
	seg_element->SALFile << " type   mp    first.key.value   second.key.value "
			     << endl;
	seg_element->SALFile << " ---- ---- ------------------ ------------------ "
			     //   xxxx 9999 99999999999.999999 99999999999.999999 
			     << endl;

	SmartArray <xstring> local_asset_types;

	local_asset_types.resize(MAXIMUM_NUMBER_OF_ASSET_TYPES);
	local_asset_types[BOND_CODE] = "bond";
	local_asset_types[MORTGAGE_CODE] = "mtg";
	local_asset_types[SEC_CODE] = "sec";
	local_asset_types[REAL_ESTATE_CODE] = "re";
	local_asset_types[EQUITY_CODE] = "eqt";
	local_asset_types[IRD_CODE] = "ird";
	local_asset_types[INDEX_OPTION_CODE] = "eio";
	local_asset_types[EPA_CODE] = "epa";

	pair<int,int> local_extreme_asset;
	int local_type = 0;
	int local_mp = 0;

	pair<double,double> local_extreme_key_values;
	double local_1st = 0;
	double local_2nd = 0;

	for (evmmap_iter = extreme_value_multimap.begin();
		 evmmap_iter != extreme_value_multimap.end();
		 evmmap_iter++)
		{
		local_extreme_asset = evmmap_iter->second;
		local_type = local_extreme_asset.first;
		local_mp = local_extreme_asset.second;

		local_extreme_key_values = evmmap_iter->first;
		local_1st = local_extreme_key_values.first;
		local_2nd = local_extreme_key_values.second;

		seg_element->SALFile << " " << setw(4) << local_asset_types[local_type]
				     << " " << setw(4) << local_mp
				     << " " << setw(18) << write_string(local_1st, 18, 15)
				     << " " << setw(18) << write_string(local_2nd, 18, 15)
				     << endl;
		}
	}
#endif

return;
}



#line 1 "create_extreme_val_multimap_entry.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::create_extreme_val_multimap_entry(StrEnum::EnumValue selection_option, double mkt_to_bk_ratio , double unrealzd_cap_gain_to_bk_ratio , double duration_measure , double notional_amount , int asset_defn , int model_point )
{
pair<double,double> extreme_asset_key;
pair<int,int> asset_model_point;

double local_mkt_to_bk_ratio = mkt_to_bk_ratio;
double local_unrealzd_cap_gain_to_bk_ratio = unrealzd_cap_gain_to_bk_ratio;
double local_duration_measure = duration_measure;
double local_notional_amount = notional_amount;
double tiebreaker_value = 0;

if (local_mkt_to_bk_ratio == USLIB_MIN_DOUBLE)
	local_mkt_to_bk_ratio = 0;

if (local_unrealzd_cap_gain_to_bk_ratio == USLIB_MIN_DOUBLE)
	local_unrealzd_cap_gain_to_bk_ratio = 0;

if (selection_option == MAXIMIZE_CAPITAL_GAIN)
	{
	tiebreaker_value
	= sell_assets_extreme_value_tiebreaker(0.0,
			local_unrealzd_cap_gain_to_bk_ratio, local_notional_amount);

	extreme_asset_key = make_pair(-local_mkt_to_bk_ratio, -tiebreaker_value);
	asset_model_point = make_pair(asset_defn, model_point);
	extreme_value_multimap.insert(multimap <pair<double,double>, pair<int,int>, less<pair<double,double> > >::value_type(extreme_asset_key, asset_model_point));

	return;
	} 

tiebreaker_value
= sell_assets_extreme_value_tiebreaker(local_mkt_to_bk_ratio,
		local_unrealzd_cap_gain_to_bk_ratio, local_notional_amount);

if (selection_option == LONGEST_DURATION)
	{
	extreme_asset_key = make_pair(-local_duration_measure, -tiebreaker_value);
	asset_model_point = make_pair(asset_defn, model_point);
	extreme_value_multimap.insert(multimap <pair<double,double>, pair<int,int>, less<pair<double,double> > >::value_type(extreme_asset_key, asset_model_point));

	return;
	} 

if (selection_option == SHORTEST_DURATION)
	{
	extreme_asset_key = make_pair(local_duration_measure, -tiebreaker_value);
	asset_model_point = make_pair(asset_defn, model_point);
	extreme_value_multimap.insert(multimap <pair<double,double>, pair<int,int>, less<pair<double,double> > >::value_type(extreme_asset_key, asset_model_point));

	return;
	} 

convert_type = selection_option;

log_screen << "Error. Unrecognized selection option code " << convert_type
		   << " in call to the create_extreme_val_multimap_entry function."
		   << MSG_ERROR;

throw FatalError("");
}



#line 1 "dur_match_decr_dur.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::dur_match_decr_dur(int t, int rebal_sales_completed, double dur_based_on_current_strat)
{
int cal_yr = xint(this->cal_yr(t));
int cal_mth = xint(this->cal_mth(t));
double cash_flow_bef_rebal_sales = 0;
double pm_sales_cash_flow = 0;
double cash_flow_for_inv = 0;
double duration_based_on_current_strategy = 0;
double dur_based_on_closest_strat = 0;
int try_shorter;
int try_shortest;
bool warnings = false;

// initialize variables
inv_strat_closest = "Current";

dur_based_on_closest_strat = dur_based_on_current_strat;

date_lookup = date(t);
xstring inv_strat_planned_local = inv_strat_planned;

if (inv_strat_shorter == inv_strat_planned_local)
	try_shorter = NO;
else
	try_shorter = YES;

if (try_shorter == YES)
	{
	if (asset->asset_detail_rpt_inv_strat_flag(t))
		seg_element->SALFile << endl
					 << " <<< Duration Matching - Check Shorter Strategy >>>"
					 << endl;

	inv_strat_select(t, SHORTER, DO_NOT_ISSUE_WARNINGS, warnings);

	cash_flow_bef_rebal_sales = cash_flow_for_inv_bef_rebal(t);

	if (rebal_sales_completed == YES)
		pm_sales_cash_flow = cash_flow_rebal(t);
	else
		pm_sales_cash_flow = cash_flow_rebal_estimate(t);

	cash_flow_for_inv
	= cash_flow_bef_rebal_sales
	  + pm_sales_cash_flow;

	if (asset->asset_detail_rpt_inv_strat_flag(t))
		{
		seg_element->SALFile << " ... Estimated Cash Flow For Investment"
					 << endl;
		seg_element->SALFile << setprecision(2);
		seg_element->SALFile << " ... + " << setw(12) << cash_flow_bef_rebal_sales
					 << "   cash flow for investment before pm"
					 << endl;
		seg_element->SALFile << " ... + " << setw(12) << pm_sales_cash_flow
					 << (rebal_sales_completed == YES
						 ? " + rebalancing net cash flow"
						 : " + estimated rebalancing net cash flow")
					 << endl;
		seg_element->SALFile << " ... --------------"
					 << endl;
		seg_element->SALFile << " ... = " << setw(12) << cash_flow_for_inv
					 << " = cash flow for investment"
					 << endl;
		seg_element->SALFile << setprecision(6);
		}
	} // endif

if (try_shorter == NO
	|| (try_shorter == YES && cash_flow_for_inv < 0))
	{
	if (inv_strat_shortest == inv_strat_planned_local
		|| inv_strat_shortest == inv_strat_shorter)
		try_shortest = NO;
	else
		try_shortest = YES;

	if (try_shortest == YES)
		{
		if (asset->asset_detail_rpt_inv_strat_flag(t))
			seg_element->SALFile << endl
						 << " <<< Duration Matching - Check Shortest Strategy >>>"
						 << endl;

		inv_strat_select(t, SHORTEST, DO_NOT_ISSUE_WARNINGS, warnings);

		cash_flow_bef_rebal_sales
		= cash_flow_for_inv_bef_rebal(t);

		if (rebal_sales_completed == YES)
			pm_sales_cash_flow = cash_flow_rebal(t);
		else
			pm_sales_cash_flow = cash_flow_rebal_estimate(t);

		cash_flow_for_inv
		= cash_flow_bef_rebal_sales
		  + pm_sales_cash_flow;

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			seg_element->SALFile << " ... Estimated Cash Flow For Investment"
						 << endl;
			seg_element->SALFile << setprecision(2);
			seg_element->SALFile << " ... + " << setw(12) << cash_flow_bef_rebal_sales
						 << "   cash flow for investment before pm"
						 << endl;
			seg_element->SALFile << " ... + " << setw(12) << pm_sales_cash_flow
						 << (rebal_sales_completed == YES
							 ? " + rebalancing net cash flow"
							 : " + estimated rebalancing net cash flow")
						 << endl;
			seg_element->SALFile << " ... --------------"
						 << endl;
			seg_element->SALFile << " ... = " << setw(12) << cash_flow_for_inv
						 << " = cash flow for investment"
						 << endl;
			seg_element->SALFile << setprecision(6);
			}
		}   // endif

	if (try_shortest == NO
		|| (try_shortest == YES && cash_flow_for_inv < 0))
		{
		// Planned Strategy Selected
		if (asset->asset_detail_rpt_inv_strat_flag(t))
			seg_element->SALFile << "... <<<< DM - Planned Strategy '" << inv_strat_id
						 << "' Selected. >>>> "
						 << endl; 

		inv_strat_select(t, inv_strat_closest, DO_NOT_ISSUE_WARNINGS, warnings);
		}
	else	// Shorter strategy produced negative cash flows and
		{	// shortest strategy produced positive cash flows, try shortest 
		if (asset->asset_detail_rpt_inv_strat_flag(t))
			seg_element->SALFile << " ... Duration Estimate For Shortest Stategy"
						 << endl;

		duration_based_on_current_strategy
		= asset_dur_estimate(t,
				cash_flow_for_inv);

		if (fabs(duration_based_on_current_strategy
				 - dur_match_tgt(t))
			 < fabs(dur_based_on_closest_strat
			  	    - dur_match_tgt(t)))
			{
			dur_based_on_closest_strat
			= duration_based_on_current_strategy;

			inv_strat_closest = "Shortest";
			}

		if (duration_based_on_current_strategy <= (dur_match_tgt(t) - dur_match_tolerance(t))) 
			{
			if (asset->asset_detail_rpt_inv_strat_flag(t))
				seg_element->SALFile << endl
							 << " <<< Merge Shortest With Planned >>>"
							 << endl; 

			dur_match_solve_for_merge_strat(t,
					dur_based_on_current_strat,
					duration_based_on_current_strategy,
					rebal_sales_completed);
			}
		else // Shortest outside of tolerance, run with planned or closest
			{
			if (asset->asset_detail_rpt_inv_strat_flag(t))
				seg_element->SALFile << " ... <<<< DM - " << inv_strat_closest
							 << " Strategy '" << inv_strat_id
							 << "' Selected. >>>> "
							 << endl; 

			inv_strat_select(t, inv_strat_closest, DO_NOT_ISSUE_WARNINGS, warnings);
			}	// endif
		}	// endif
	}
else // Shorter strategy produced positive cash flows 
	{
	if (asset->asset_detail_rpt_inv_strat_flag(t))
		seg_element->SALFile << " ... Duration Estimate For Shorter Strategy"
					 << endl;

	duration_based_on_current_strategy
	= asset_dur_estimate(t, cash_flow_for_inv);

	if (fabs(duration_based_on_current_strategy
			 - dur_match_tgt(t))
		 < fabs(dur_based_on_closest_strat
				- dur_match_tgt(t)))
		{
		dur_based_on_closest_strat
		= duration_based_on_current_strategy;

		inv_strat_closest = "Shorter";
		}

	if (fabs(dur_based_on_closest_strat
		 - dur_match_tgt(t))
	 <= dur_match_tolerance(t))
	    {
	    if (asset->asset_detail_rpt_inv_strat_flag(t))
				seg_element->SALFile << " ... <<<< DM - " << inv_strat_closest
							 << " Strategy '" << inv_strat_id
							 << "' Selected. >>>> "
							 << endl; 

			inv_strat_select(t, inv_strat_closest, DO_NOT_ISSUE_WARNINGS, warnings);
	    }
	else if (duration_based_on_current_strategy <= (dur_match_tgt(t) - dur_match_tolerance(t))) 
		{
		if (asset->asset_detail_rpt_inv_strat_flag(t))
			seg_element->SALFile << endl
						 << " <<< Merge Shorter With Planned >>>"
						 << endl; 

		dur_match_solve_for_merge_strat(t,
				dur_based_on_current_strat,
				duration_based_on_current_strategy,
				rebal_sales_completed);
		}
	else // Shorter outside of tolerance, try Shortest
		{
		if (inv_strat_shortest == inv_strat_planned_local
			|| inv_strat_shortest == inv_strat_shorter)
			try_shortest = NO;
		else
			try_shortest = YES;

		if (try_shortest == YES)
			{
			if (asset->asset_detail_rpt_inv_strat_flag(t))
				seg_element->SALFile << endl
							 << " <<< Duration Matching - Check Shortest Strategy >>>"
							 << endl;

			inv_strat_select(t, SHORTEST, DO_NOT_ISSUE_WARNINGS, warnings);

			cash_flow_bef_rebal_sales
			= cash_flow_for_inv_bef_rebal(t);

			if (rebal_sales_completed == YES)
				pm_sales_cash_flow
				= cash_flow_rebal(t);
			else
				pm_sales_cash_flow
				= cash_flow_rebal_estimate(t);

			cash_flow_for_inv
			= cash_flow_bef_rebal_sales
			  + pm_sales_cash_flow;

			if (asset->asset_detail_rpt_inv_strat_flag(t))
				{
				seg_element->SALFile << " ... Estimated Cash Flow For Investment"
							 << endl;
				seg_element->SALFile << setprecision(2);
				seg_element->SALFile << " ... + " << setw(12) << cash_flow_bef_rebal_sales
							 << "   cash flow for investment before pm"
							 << endl;
				seg_element->SALFile << " ... + " << setw(12) << pm_sales_cash_flow
							 << (rebal_sales_completed == YES
								 ? " + rebalancing net cash flow"
								 : " + estimated rebalancing net cash flow")
							 << endl;
				seg_element->SALFile << " ... --------------"
							 << endl;
				seg_element->SALFile << " ... = " << setw(12) << cash_flow_for_inv
							 << " = cash flow for investment"
							 << endl;
				seg_element->SALFile << setprecision(6);
				}
			}   // endif

		if (try_shortest == NO
			|| (try_shortest == YES && cash_flow_for_inv < 0)) 
			{
			if (asset->asset_detail_rpt_inv_strat_flag(t))
				seg_element->SALFile << " ... <<<< DM - " << inv_strat_closest
							 << " Strategy '" << inv_strat_id
							 << "' Selected. >>>> "
							 << endl; 

			inv_strat_select(t, inv_strat_closest, DO_NOT_ISSUE_WARNINGS, warnings);
			}
		else // Shortest produced positive cash flows
			{
			if (asset->asset_detail_rpt_inv_strat_flag(t))
				seg_element->SALFile << " ... Duration Estimate For Shortest Strategy"
							 << endl;

			duration_based_on_current_strategy
			= asset_dur_estimate(t, cash_flow_for_inv);

			if (fabs(duration_based_on_current_strategy
					 - dur_match_tgt(t))
				 < fabs(dur_based_on_closest_strat
						- dur_match_tgt(t)))
				{
				dur_based_on_closest_strat
				= duration_based_on_current_strategy;

				inv_strat_closest = "Shortest";
				}

			if (duration_based_on_current_strategy <= (dur_match_tgt(t) - dur_match_tolerance(t)))
				{
				if (asset->asset_detail_rpt_inv_strat_flag(t))
					seg_element->SALFile << endl
								 << " <<< Merge Shortest With Planned >>>"
								 << endl; 

				dur_match_solve_for_merge_strat(t,
						dur_based_on_current_strat,
						duration_based_on_current_strategy,
						rebal_sales_completed);
				}
			else // Shortest outside of tolerance, choose closest
				{
				if (asset->asset_detail_rpt_inv_strat_flag(t))
					seg_element->SALFile << " ... <<<< DM - " << inv_strat_closest
								 << " Strategy '" << inv_strat_id
								 << "' Selected. >>>> "
								 << endl; 

				inv_strat_select(t, inv_strat_closest, DO_NOT_ISSUE_WARNINGS, warnings);
				}
			}
		}
	}

return;
}



#line 1 "dur_match_incr_dur.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::dur_match_incr_dur(int t, int rebal_sales_completed, double dur_based_on_current_strat)
{
int cal_yr = xint(this->cal_yr(t));
int cal_mth = xint(this->cal_mth(t));
double cash_flow_bef_rebal_sales = 0;
double pm_sales_cash_flow = 0;
double cash_flow_for_inv = 0;
double duration_based_on_current_strategy = 0;
double dur_based_on_closest_strat = 0;
int try_longer;
int try_longest;
bool warnings = false;

// initialize variables
inv_strat_closest = "Current";

dur_based_on_closest_strat = dur_based_on_current_strat;

date_lookup = date(t);
xstring inv_strat_planned_local = inv_strat_planned;

if (inv_strat_longer == inv_strat_planned_local)
	try_longer = NO;
else
	try_longer = YES;

if (try_longer == YES)
	{
	if (asset->asset_detail_rpt_inv_strat_flag(t))
		seg_element->SALFile << endl
					 << " <<< Duration Matching - Check Longer Strategy >>>"
					 << endl;

	inv_strat_select(t, LONGER, DO_NOT_ISSUE_WARNINGS, warnings);

	cash_flow_bef_rebal_sales = cash_flow_for_inv_bef_rebal(t);

	if (rebal_sales_completed == YES)
		pm_sales_cash_flow = cash_flow_rebal(t);
	else
		pm_sales_cash_flow = cash_flow_rebal_estimate(t);

	cash_flow_for_inv
	= cash_flow_bef_rebal_sales
	  + pm_sales_cash_flow;

	if (asset->asset_detail_rpt_inv_strat_flag(t))
		{
		seg_element->SALFile << " ... Estimated Cash Flow For Investment"
					 << endl;
		seg_element->SALFile << setprecision(2);
		seg_element->SALFile << " ... + " << setw(12) << cash_flow_bef_rebal_sales
					 << "   cash flow for investment before pm"
					 << endl;
		seg_element->SALFile << " ... + " << setw(12) << pm_sales_cash_flow
					 << (rebal_sales_completed == YES
					 ? " + rebalancing net cash flow"
					 : " + estimated rebalancing net cash flow")
					 << endl;
		seg_element->SALFile << " ... --------------"
					 << endl;
		seg_element->SALFile << " ... = " << setw(12) << cash_flow_for_inv
					 << " = cash flow for investment"
					 << endl;
		seg_element->SALFile << setprecision(6);
		}
	}   // endif

if (try_longer == NO
	|| (try_longer == YES && cash_flow_for_inv < 0))
	{	
	if (inv_strat_longest == inv_strat_planned_local
		|| inv_strat_longest == inv_strat_longer)
		try_longest = NO;
	else
		try_longest = YES;

	if (try_longest == YES) // Check Longest
		{
		if (asset->asset_detail_rpt_inv_strat_flag(t))
			seg_element->SALFile << endl
						 << " <<< Duration Matching - Check Longest Strategy >>>"
						 << endl;

		inv_strat_select(t, LONGEST, DO_NOT_ISSUE_WARNINGS, warnings);

		cash_flow_bef_rebal_sales = cash_flow_for_inv_bef_rebal(t);

		if (rebal_sales_completed == YES)
			pm_sales_cash_flow = cash_flow_rebal(t);
		else
			pm_sales_cash_flow = cash_flow_rebal_estimate(t);

		cash_flow_for_inv
		= cash_flow_bef_rebal_sales
		  + pm_sales_cash_flow;

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			seg_element->SALFile << " ... Estimated Cash Flow For Investment"
						 << endl;
			seg_element->SALFile << setprecision(2);
			seg_element->SALFile << " ... + " << setw(12) << cash_flow_bef_rebal_sales
						 << " cash flow for investment before pm"
						 << endl;
			seg_element->SALFile << " ... + " << setw(12) << pm_sales_cash_flow
						 << (rebal_sales_completed == YES
						 ? " + rebalancing net cash flow"
						 : " + estimated rebalancing net cash flow")
						 << endl;
			seg_element->SALFile << " ... --------------"
						 << endl;
			seg_element->SALFile << " ... = " << setw(12) << cash_flow_for_inv
						 << " = cash flow for investment"
						 << endl;
			seg_element->SALFile << setprecision(6);
			}
		}   // endif

	if (try_longest == NO
		|| (try_longest == YES && cash_flow_for_inv < 0))
		{
		// Planned Strategy Selected
		if (asset->asset_detail_rpt_inv_strat_flag(t))
			seg_element->SALFile << "... <<<< DM - Planned Strategy '" << inv_strat_id
						 << "' Selected. >>>> "
						 << endl;

		inv_strat_select(t, inv_strat_closest, DO_NOT_ISSUE_WARNINGS, warnings);
		}
	else	// Longer strategy produced negative cash flows and 
		{   // longest strategy produced positive cash flows, try longest
		if (asset->asset_detail_rpt_inv_strat_flag(t))
			seg_element->SALFile << " ... Duration Estimate For Longest Strategy"
						 << endl;

		duration_based_on_current_strategy
		= asset_dur_estimate(t,
				cash_flow_for_inv);

		if (fabs(duration_based_on_current_strategy
				 - dur_match_tgt(t))
			 < fabs(dur_based_on_closest_strat
					- dur_match_tgt(t)))
			{
			dur_based_on_closest_strat = duration_based_on_current_strategy;

			inv_strat_closest = "Longest";
			}

		if (duration_based_on_current_strategy >= (dur_match_tgt(t) + dur_match_tolerance(t)))
			{	
			if (asset->asset_detail_rpt_inv_strat_flag(t))
				seg_element->SALFile << endl
							 << " <<< Merge Longest With Planned >>>"
							 << endl;

			dur_match_solve_for_merge_strat(t,
											dur_based_on_current_strat,
											duration_based_on_current_strategy,
											rebal_sales_completed);
			}	
		else // Longest outside of tolerance, run with planned or closest
			{		
			if (asset->asset_detail_rpt_inv_strat_flag(t))
				seg_element->SALFile << " ... <<<< DM - " << inv_strat_closest
							 << " Strategy '" << inv_strat_id
							 << "' Selected. >>>> "
							 << endl; 

			inv_strat_select(t, inv_strat_closest, DO_NOT_ISSUE_WARNINGS, warnings);
			}   // endif
		}   // endif
	}
else // Longer strategy produced positive cash flows
	{
	if (asset->asset_detail_rpt_inv_strat_flag(t))
		seg_element->SALFile << " ... Duration Estimate For Longer Strategy"
					 << endl;

	duration_based_on_current_strategy
	= asset_dur_estimate(t, cash_flow_for_inv);

	if (fabs(duration_based_on_current_strategy
			 - dur_match_tgt(t))
		 < fabs(dur_based_on_closest_strat
				- dur_match_tgt(t)))
		{
		dur_based_on_closest_strat = duration_based_on_current_strategy;

		inv_strat_closest = "Longer";
		}

	if (fabs(dur_based_on_closest_strat
		 - dur_match_tgt(t))
	 <= dur_match_tolerance(t))
	    {
	    if (asset->asset_detail_rpt_inv_strat_flag(t))
			seg_element->SALFile << " ... <<<< DM - " << inv_strat_closest
						 << " Strategy '" << inv_strat_id
						 << "' Selected. >>>> "
						 << endl; 

			inv_strat_select(t, inv_strat_closest, DO_NOT_ISSUE_WARNINGS, warnings);
	    }
	else if (duration_based_on_current_strategy >= (dur_match_tgt(t) + dur_match_tolerance(t)))
		{
		if (asset->asset_detail_rpt_inv_strat_flag(t))
			seg_element->SALFile << endl
						 << " <<< Merge Longer With Planned >>>"
						 << endl; 

		dur_match_solve_for_merge_strat(t,
										dur_based_on_current_strat,
										duration_based_on_current_strategy,
										rebal_sales_completed);
		}	
	else // Longer outside of tolerance, try Longest
		{
		if (inv_strat_longest == inv_strat_planned_local
			|| inv_strat_longest == inv_strat_longer)
			try_longest = NO;
		else
			try_longest = YES;

		if (try_longest == YES)
			{
			if (asset->asset_detail_rpt_inv_strat_flag(t))
				seg_element->SALFile << endl
							 << " <<< Duration Matching - Check Longest Strategy >>>"
							 << endl;

			inv_strat_select(t, LONGEST, DO_NOT_ISSUE_WARNINGS, warnings);

			cash_flow_bef_rebal_sales = cash_flow_for_inv_bef_rebal(t);

			if (rebal_sales_completed == YES)
				pm_sales_cash_flow = cash_flow_rebal(t);
			else
				pm_sales_cash_flow = cash_flow_rebal_estimate(t);

			cash_flow_for_inv
			= cash_flow_bef_rebal_sales
			  + pm_sales_cash_flow;

			if (asset->asset_detail_rpt_inv_strat_flag(t))
				{
				seg_element->SALFile << " ... Estimated Cash Flow For Investment"
							 << endl;
				seg_element->SALFile << setprecision(2);
				seg_element->SALFile << " ... + " << setw(12) << cash_flow_bef_rebal_sales
							 << " cash flow for investment before pm"
							 << endl;
				seg_element->SALFile << " ... + " << setw(12) << pm_sales_cash_flow
							 << (rebal_sales_completed == YES
							 ? " + rebalancing net cash flow"
							 : " + estimated rebalancing net cash flow")
							 << endl;
				seg_element->SALFile << " ... --------------"
							 << endl;
				seg_element->SALFile << " ... = " << setw(12) << cash_flow_for_inv
							 << " = cash flow for investment"
							 << endl;
				seg_element->SALFile << setprecision(6);
				}
			}   // endif

		if (try_longest == NO
			|| (try_longest == YES && cash_flow_for_inv < 0))
			{
			if (asset->asset_detail_rpt_inv_strat_flag(t))
				seg_element->SALFile << " ... <<<< DM - " << inv_strat_closest
							 << " Strategy '" << inv_strat_id
							 << "' Selected. >>>> "
							 << endl; 

			inv_strat_select(t, inv_strat_closest, DO_NOT_ISSUE_WARNINGS, warnings);
			}
		else // Longest produced positive cash flows
			{
			if (asset->asset_detail_rpt_inv_strat_flag(t))
				seg_element->SALFile << " ... Duration Estimate For Longest Strategy"
							 << endl;

			duration_based_on_current_strategy
			= asset_dur_estimate(t, cash_flow_for_inv);

			if (fabs(duration_based_on_current_strategy
					 - dur_match_tgt(t))
				 < fabs(dur_based_on_closest_strat
						- dur_match_tgt(t)))
				{
				dur_based_on_closest_strat = duration_based_on_current_strategy;

				inv_strat_closest = "Longest";
				}

			if (duration_based_on_current_strategy >= (dur_match_tgt(t) + dur_match_tolerance(t)))
				{
				if (asset->asset_detail_rpt_inv_strat_flag(t))
					seg_element->SALFile << endl
								 << " <<< Merge Longest With Planned >>>"
								 << endl; 

				dur_match_solve_for_merge_strat(t,
												dur_based_on_current_strat,
												duration_based_on_current_strategy,
												rebal_sales_completed);
				}
			else // Longest outside of tolerance, choose closest
				{
				if (asset->asset_detail_rpt_inv_strat_flag(t))
					seg_element->SALFile << " ... <<<< DM - " << inv_strat_closest
								 << " Strategy '" << inv_strat_id
								 << "' Selected. >>>> "
								 << endl; 

				inv_strat_select(t, inv_strat_closest, DO_NOT_ISSUE_WARNINGS, warnings);
				}
			}
		}
	}

return;
}



#line 1 "dur_match_solve_for_merge_strat.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::dur_match_solve_for_merge_strat(int t, double dur_based_on_current_strat, double duration_based_on_alternate_strategy, int rebal_sales_completed)
{
int asset_sub_port = 0;
int panum = 0;
int loop = 0;
double duration_based_on_current_strategy = 0.0;
double duration_based_on_merge_strategy = 0.0;
double low_duration = 0.0;
double low_current_factor = 0.0;
double high_duration = 0.0;
double high_current_factor = 0.0;
double loop_tolerance = 0.0;
double first_difference_1 = 0.0;
double first_difference_2 = 0.0;
double second_difference = 0.0;
double alternate_strategy_factor = 0.0;
double current_strategy_factor = 0.0;
double cash_flow_bef_rebal_sales = 0.0;
double rebal_sales_cash_flow = 0.0;
double cash_flow_for_inv = 0.0;
bool warnings = false;

xstring alternate_strategy_label
= inv_strat_id;

xstring alternate_strategy_distribution_method
= get_string_of_enum_val(asset_sub_port_distribn_defn);

double alternate_strat_cash_pct
= cash_tgt_pct;

// Initialize high /low variables. 
if (duration_based_on_alternate_strategy < dur_match_tgt(t))
	{
	low_duration = duration_based_on_alternate_strategy;
	low_current_factor = 0.0;
	high_duration = dur_based_on_current_strat;
	high_current_factor = 1.0;
	}
else
	{
	low_duration = dur_based_on_current_strat;
	low_current_factor = 1.0;
	high_duration = duration_based_on_alternate_strategy;
	high_current_factor = 0.0;
	}	

for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
	{
	
	asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct_dur_match
	= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct;

	asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_dur_match
	= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum;

	
	asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd_dur_match
	= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd;
	}	

for (panum = 0; panum < purch_asset_max_num; panum = panum + 1)
	{
	purch_assets_sub_port_num_alt_strat[panum]
	= purch_assets_asset_sub_port_num[panum];

	purch_assets_weight_alt_strat[panum]
	= purch_assets_weight[panum];
	}	

// Now get current strategy information.
inv_strat_select(t, CURRENT, DO_NOT_ISSUE_WARNINGS, warnings);

StrEnum::EnumValue current_strategy_distribution_method
= asset_sub_port_distribn_defn;

double current_strat_cash_pct
= cash_tgt_pct;

for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
	{	
	asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct_curr_strat
	= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct;
	
	asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_curr_strat
	= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum;
	
	asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd_curr_strat
	= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd;
	}	

for (panum = 0; panum < purch_asset_max_num; panum = panum + 1)
	{
	purch_assets_sub_port_num_current_strat[panum]
	= purch_assets_asset_sub_port_num[panum];

	purch_assets_weight_current_strat[panum]
	= purch_assets_weight[panum];
	}	

//this is the distribution method of the planned strategy
asset_sub_port_distribn_defn
= current_strategy_distribution_method;

int maximum_iterations = 10;
loop_tolerance = 0.005;

double preliminary_current_strategy_factor
= low_current_factor;

for (loop = 0; loop <= maximum_iterations + 1; loop++)
	{
	if (asset->asset_detail_rpt_inv_strat_flag(t))
		{
		seg_element->SALFile << endl
					 << " ... Begin Merge Strategy: Loop=" << loop
					 << " Loop_Tolerance=" << loop_tolerance
					 << " Max_Iterations=" << maximum_iterations
					 << endl;
		}

	if (loop < maximum_iterations + 1)
		{
		if (loop > 0)
			{
			//
			// Calculate final current strategy factor based on calculated low,
			// merge and high durations using the following difference table.
			//
			//   Duration	Factor		1st Difference		2nd Difference
			//   ---------	------		---------------		---------------
			//   LowDur		l
			//									r - l
			//							A = ---------------
			//								MerDur - LowDur			h - l
			//   MerDur		r								C = ---------------
			//									h - r			HghDur - LowDur
			//							B = ---------------
			//								HghDur - MerDur
			//   HghDur		h
			//
			// NewFactor = l + (TargDur - LowDur) * A
			//               + (TargDur - LowDur) * (TargDur - MerDur) * C
			//
			// If NewFactor is out of bounds, use bisection.  For first and
			// last pass use linear interpolation.
			//
			// This adjustment is being made because of nonlinear dependence
			// of the duration on the planned factor.
			//

			if (duration_based_on_merge_strategy > low_duration
				&& duration_based_on_merge_strategy < high_duration)
				{
				first_difference_1
				= (current_strategy_factor - low_current_factor) 
				  / (duration_based_on_merge_strategy - low_duration);

				first_difference_2
				= (high_current_factor - current_strategy_factor) 
				  / (high_duration - duration_based_on_merge_strategy);

				second_difference
				= (first_difference_2 - first_difference_1) 
				  / (high_duration - low_duration);

				preliminary_current_strategy_factor
				= low_current_factor 
				  + (dur_match_tgt(t) - low_duration) 
					* first_difference_1 
				  + (dur_match_tgt(t) - low_duration) 
					* (dur_match_tgt(t)
					   - duration_based_on_merge_strategy) 
					* second_difference;
				}
			else
				{
				// Force bisection or linear interpolation
				preliminary_current_strategy_factor = high_current_factor + 1;
				}

			if (duration_based_on_merge_strategy < dur_match_tgt(t))
				{
				low_duration = duration_based_on_merge_strategy;
				low_current_factor = current_strategy_factor;
				}
			else
				{
				high_duration = duration_based_on_merge_strategy;
				high_current_factor = current_strategy_factor;
				} 
			} // end if (loop > 0)

		if ((low_current_factor < high_current_factor
			 && preliminary_current_strategy_factor < high_current_factor
			 && preliminary_current_strategy_factor > low_current_factor)
			|| (low_current_factor > high_current_factor
				&& preliminary_current_strategy_factor > high_current_factor
				&& preliminary_current_strategy_factor < low_current_factor))
			current_strategy_factor
			= preliminary_current_strategy_factor;
		else if (loop > 0 && loop < maximum_iterations)
			// Bisection
			current_strategy_factor
			= low_current_factor
			  + (high_current_factor - low_current_factor) / 2.0;
		else
			// Linear interpolation
			current_strategy_factor
			= low_current_factor 
			  + (high_current_factor - low_current_factor) 
				* (dur_match_tgt(t) - low_duration) 
				/ (high_duration - low_duration);

		alternate_strategy_factor
		= (1.0 - current_strategy_factor);

		cash_tgt_pct
		= current_strat_cash_pct
		  * current_strategy_factor
		  + alternate_strat_cash_pct
			* alternate_strategy_factor;
		  
		for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
			{
			asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct
			= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct_curr_strat
			  * current_strategy_factor
			  + asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct_dur_match
				* alternate_strategy_factor;

			asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum
			= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_curr_strat
			  * current_strategy_factor
			  + asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_dur_match
				* alternate_strategy_factor;

			// If there are no purchase assets in the sub portfolio for one of the strategies, then don't merge the weights. Just set to 1.0
			if (fabs(asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd_curr_strat - 1.0) > rate_ratio_threshold
				|| fabs(asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd_dur_match - 1.0) > rate_ratio_threshold)
				asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd = 1.0;
			else
				asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd
				= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd_curr_strat
				  * current_strategy_factor 
				  + asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd_dur_match
					* alternate_strategy_factor;

			if (asset_sub_port == 0)
				asset_sub_port_inv_tgt_pct_sum
				= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd
				  * asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct;
			else // if (asset_sub_port > 0)
				asset_sub_port_inv_tgt_pct_sum
				= asset_sub_port_inv_tgt_pct_sum 
				  + asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd
					* asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct;
			} // end for over asset_sub_port

		for (panum = 0; panum < purch_asset_max_num; panum++)
			{
			if (purch_assets_sub_port_num_current_strat[panum] > 0)
				purch_assets_asset_sub_port_num[panum]
				= purch_assets_sub_port_num_current_strat[panum];
			else
				purch_assets_asset_sub_port_num[panum]
				= purch_assets_sub_port_num_alt_strat[panum];

			purch_assets_weight[panum]
			= purch_assets_weight_current_strat[panum] 
			  * current_strategy_factor
			  + purch_assets_weight_alt_strat[panum] 
				* alternate_strategy_factor;
			} // end for over panum

		if (loop < maximum_iterations)
			{
			cash_flow_bef_rebal_sales
			= cash_flow_for_inv_bef_rebal(t);

			if (rebal_sales_completed == YES)
				rebal_sales_cash_flow
				= cash_flow_rebal(t);
			else
				rebal_sales_cash_flow
				= cash_flow_rebal_estimate(t);

			cash_flow_for_inv
			= cash_flow_bef_rebal_sales
			  + rebal_sales_cash_flow;

			if (asset->asset_detail_rpt_inv_strat_flag(t))
				{
				seg_element->SALFile << "Estimated Cash Flow For Investment" << endl;
				seg_element->SALFile << setprecision(2);
				seg_element->SALFile << "CashFlowBefRebalSales," << setw(12) << cash_flow_bef_rebal_sales << endl;
				seg_element->SALFile << (rebal_sales_completed == YES
							 ? "(+) RebalSalesNetCashFlow,"
							 : "(+) EstRebalSalesNetCashFlow,")
						     << setw(12) << rebal_sales_cash_flow  << endl;
				seg_element->SALFile << ",--------------" << endl;
				seg_element->SALFile << "CashFlowForInv," << setw(12) << cash_flow_for_inv << endl;
				seg_element->SALFile << setprecision(6);
				}

			duration_based_on_current_strategy
			= asset_dur_estimate(t,
			                     cash_flow_for_inv);

			duration_based_on_merge_strategy
			= duration_based_on_current_strategy;

			if (fabs(duration_based_on_merge_strategy
					 - dur_match_tgt(t))
				 <= dur_match_tolerance(t))
				//... Go with current merge strategy.
				loop = maximum_iterations;
			else if (fabs(duration_based_on_merge_strategy
						 - dur_match_tgt(t))
					 <= (dur_match_tolerance(t) + loop_tolerance))
				//... Recalculate planned factor one last time.
				loop = maximum_iterations - 1;
			} // end if (loop < maximum_iterations)
		} // end if loop < maximum_iteration + 1

	// Process asset detail report on all iterations
	if (asset->asset_detail_rpt_inv_strat_flag(t))
		{
		int asset_sub_port;
		int panum;
		xstring asset_purpose_abbreviation;
		
		date_lookup = date(t);
		xstring inv_strat_planned_local = inv_strat_planned;

		seg_element->SALFile << setprecision(6);
		seg_element->SALFile << "Merge Strategy Summary" << endl;
		seg_element->SALFile << "Planned Strategy:,"
					 << "Cash% =," << setw(9) << current_strat_cash_pct << ","
					 << "Factor =," << setw(9) << current_strategy_factor << ","
					 << "Label =," << inv_strat_planned_local << endl;
		seg_element->SALFile << "Alternate Strategy:,"
					 << "Cash% =," << setw(9) << alternate_strat_cash_pct << ","
					 << "Factor =," << setw(9) << alternate_strategy_factor << ","
					 << "Label =," << alternate_strategy_label << endl;
		seg_element->SALFile << "Merge Strategy:,"
					 << "Cash% =,"  << setw(9) << cash_tgt_pct << ","
					 << "Distribution Method =," << alternate_strategy_distribution_method << endl;
		seg_element->SALFile << "Durations:,"
					 << "Low =," << low_duration << ","
					 << "Merge =," << duration_based_on_merge_strategy << ","
					 << "High =," << high_duration << endl;
		seg_element->SALFile << "Factors:,"
		             << "Low =," << low_current_factor << ","
					 << "Merge =," << current_strategy_factor << ","
					 << "High =," << high_current_factor << ","
					 << "Preliminary =," << preliminary_current_strategy_factor	 << endl;

		seg_element->SALFile << ",Merge,Merge,Merge,Alternate,Alternate,Alternate,Planned,Planned,Planned" << endl;
		seg_element->SALFile << "SubPort,Percent,TotWghts,NormWghts,Percent,TotWghts,NormWghts,Percent,TotWghts,NormWghts" << endl;

		for(asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
			{
			if (asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct
				|| asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum
				|| asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct_dur_match
				|| asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_dur_match
				|| asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct_curr_strat
				|| asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_curr_strat)
				{
				seg_element->SALFile << setprecision(6);
				seg_element->SALFile << setw(3) << asset_sub_port << ","
							 << setw(9) << asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct << ","
							 << setw(9) << asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum << ","
							 << setw(9) << asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd << ","
							 << setw(9) << asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct_dur_match << ","
							 << setw(9) << asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_dur_match << ","
							 << setw(9) << asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd_dur_match << ","
							 << setw(9) << asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct_curr_strat << ","
							 << setw(9) << asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_curr_strat << ","
							 << setw(9) << asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd_curr_strat
							 << endl;
				}
			} // end for over asset_sub_port

		seg_element->SALFile << ",Merge,Merge,Merge,Alternate,Alternate,Planned,Planned" << endl;
		seg_element->SALFile << "PurchAssetNum,SubPort,WtW/ISubPort,AssetPurp,SubPort,WtW/ISubPort,SubPort,WtW/ISubPort" << endl;

		for (panum = 0; panum < purch_asset_max_num; panum++)
			{
			if (purch_assets_asset_sub_port_num [panum]
				|| purch_assets_weight [panum]
				|| purch_assets_sub_port_num_alt_strat [panum]
				|| purch_assets_weight_alt_strat [panum]
				|| purch_assets_sub_port_num_current_strat [panum]
				|| purch_assets_weight_current_strat [panum])
				{
				if (purch_assets_port_defn [panum] == INVESTMENT)
					asset_purpose_abbreviation = "Investment";
				else
					asset_purpose_abbreviation = "Unknown";

				seg_element->SALFile << "     "
							 << setw(3) << panum << ","
							 << setw(3) << purch_assets_asset_sub_port_num [panum] << ","
							 << setw(9) << purch_assets_weight [panum] << ","
	 						 << setw(2) << asset_purpose_abbreviation << ","
							 << setw(9) << purch_assets_sub_port_num_alt_strat [panum] << ","
							 << setw(9) << purch_assets_weight_alt_strat [panum] << ","
							 << setw(3) << purch_assets_sub_port_num_current_strat [panum] << ","
							 << setw(9) << purch_assets_weight_current_strat [panum]
							 << endl;
				}
			} // endfor over panum
		} // end if asset detail report
	}  // end_for over 'iteration' loop

// set the label for asset detail reporting
inv_strat_id = "Merged Strategy";
}



#line 1 "expected_sale_cash.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::expected_sale_cash(double book_value, double accrued_interest, double market_value, double unrealized_capital_gain, double capital_gains_cash_factor_for_sales)
{
double asset_sales_marginal_tax_rate
= min(company->tax_rate, company->tax_rate_cap_gain);

double exp_net_cash_from_sale
= book_value + accrued_interest
  + ( (market_value - book_value)
	  * (1.0 - asset_sales_marginal_tax_rate)
	  * capital_gains_cash_factor_for_sales )
  - (unrealized_capital_gain * asset_sales_marginal_tax_rate);

return exp_net_cash_from_sale;
}



#line 1 "initialize_sale_and_inv_vars.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::initialize_sale_and_inv_vars(int t, int sum_type, StrEnum::EnumValue investment_sales_timing)
{
xstring xstring_initial_accrued_interest = "";
xstring xstring_initial_accrued_rent = "";
xstring xstring_initial_book_value = "";
xstring xstring_initial_market_value = "";
xstring xstring_initial_unrealized_capital_gains = "";
int tee = 0;

int column_num_accrued_interest = 0;
int column_num_accrued_rent = 0;
int column_num_book_value = 0;
int column_num_market_value = 0;
int column_num_unrealized_capital_gains = 0;

double local_pct_to_use = 0;

int mp = 0;
int sub_port_num = 0;
int sale_class = 0;
int fund_index = 0;
int column_num_notional_amount = 0;
int column_num_notional_amount_before_sales = 0;

current_sub_port = NULL;

bool initialize_market_sales_values = false;

if (investment_sales_timing == END_OF_MONTH)
	{
	tee = t;
	xstring_initial_accrued_interest = "accr_int_bef_rebal_sale";
	xstring_initial_accrued_rent = "accr_rent_bef_rebal_sale";
	xstring_initial_book_value = "bk_val_bef_rebal_sale";

	initialize_market_sales_values = (asset->mths_to_next_mkt_val_calc(t) == 0);

	if (initialize_market_sales_values)
		{
		xstring_initial_market_value = "mkt_val_bef_rebal_sale";
		xstring_initial_unrealized_capital_gains = "unrealzd_cap_gain_bef_rebal_sale";
		}

	// initialize market_values_not_calculated_for_asset_sub_port_map, if necessary
	market_values_not_calculated_for_asset_sub_port_map.clear();
	if (!initialize_market_sales_values)
		{
		for (sub_port_num = 0; sub_port_num < asset->sm_asset_sub_port[seg_num].size(); sub_port_num++)			
			market_values_not_calculated_for_asset_sub_port_map[sub_port_num] = 1;
		}
	}

// clear sales and investment variables
for (sub_port_num = 0; sub_port_num < asset->sm_asset_sub_port[seg_num].size(); sub_port_num++)
	{
	for (fund_index = 0; fund_index < MAXIMUM_NUMBER_OF_ASSET_FUNDS; fund_index++)
		{
		sub_port_fund_initial_book_plus_accrued[sub_port_num][fund_index] = 0.0;

		sub_port_fund_book_plus_accrued_sold[sub_port_num][fund_index] = 0.0;

		sub_port_fund_book_plus_accrued_purchases[sub_port_num][fund_index] = 0.0;

		for (sale_class = 1; sale_class <= MAXIMUM_NUMBER_OF_SALES_CLASSES; sale_class++)
			{
			sub_port_class_fund_assets_present[sub_port_num][sale_class][fund_index] = 0;
			sub_port_class_fund_initial_accrued_interest[sub_port_num][sale_class][fund_index] = 0.0;
			sub_port_class_fund_initial_book_value[sub_port_num][sale_class][fund_index] = 0.0;
			sub_port_class_fund_initial_market_value[sub_port_num][sale_class][fund_index] = 0.0;
			sub_port_class_fund_initial_unrealized_capital_gains[sub_port_num][sale_class][fund_index] = 0.0;

			sub_port_class_fund_accrued_interest_sold[sub_port_num][sale_class][fund_index] = 0.0;
			sub_port_class_fund_book_value_sold[sub_port_num][sale_class][fund_index] = 0.0;
			sub_port_class_fund_market_value_sold[sub_port_num][sale_class][fund_index] = 0.0;
			sub_port_class_fund_unrealized_capital_gains_released[sub_port_num][sale_class][fund_index] = 0.0;

			sub_port_class_fund_accrued_interest_purchases[sub_port_num][sale_class][fund_index] = 0.0;
			sub_port_class_fund_book_value_purchases[sub_port_num][sale_class][fund_index] = 0.0;
			}
		}
	}

#define INITIALIZE_SALES_AND_INVESTMENT_VARIABLES 0 // 1 for values, 0 for no values
#if INITIALIZE_SALES_AND_INVESTMENT_VARIABLES
	bool write_detail = false;
	if (asset->asset_detail_rpt_flag(t))
			write_detail = true;
	if (write_detail)
		{
		log_screen.setf(ios::fixed);
		log_screen << MSG_ERROR;
		log_screen << " .s. t=" << t
				<< " call_initialize_sales_and_investment_variables summary at "
				<< (investment_sales_timing == END_OF_MONTH ? "EOM" : "BOM")
				<< MSG_ERROR;
		log_screen << "   t Gp C F accr_int       bk_val     mkt_val  mk/bk_ratio ucg/bk_ratio identifier"
				<< MSG_ERROR;
		log_screen << " ---- -- - - ---------------- ---------------- ---------------- ------------ ------------ ---------- "
				//      9999 xx 9 9 999999999.999999 999999999.999999 999999999.999999 999.99999999 999.99999999 xxxxxxxxxx
				<< MSG_ERROR;
		}
#endif

// now calculate initial amounts
map <int, long, less <int> >::iterator mp_map_iter;

#if defined(__BOND_ASSET_H_)
if (seg_element->bond_mp_map_active.size() > 0)
	{
	column_num_accrued_interest = asset->sm_bond[0][0]->Column(xstring_initial_accrued_interest).Number();
	column_num_book_value = asset->sm_bond[0][0]->Column(xstring_initial_book_value).Number();
	column_num_notional_amount = asset->sm_bond[0][0]->Column("notional_amt").Number();
	column_num_notional_amount_before_sales = asset->sm_bond[0][0]->Column("notional_amt_bef_sale").Number();

	if (initialize_market_sales_values)
		{
		column_num_market_value = asset->sm_bond[0][0]->Column(xstring_initial_market_value).Number();
		column_num_unrealized_capital_gains = asset->sm_bond[0][0]->Column(xstring_initial_unrealized_capital_gains).Number();
		}

	for (mp_map_iter = seg_element->bond_mp_map_active.begin();
		 mp_map_iter != seg_element->bond_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_bond[mp][0]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_bond[mp][0]->neg_asset_flag > 0)
			continue;

		if ((tee > max(0, asset->sm_bond[mp][0]->commencement_period)
			 && asset->sm_bond[mp][0]->Column(column_num_notional_amount).Value(tee-1) < ASSET_ACTIVE_THRESHOLD)
			|| (tee == asset->sm_bond[mp][0]->commencement_period
				&& asset->sm_bond[mp][0]->Column(column_num_notional_amount_before_sales).Value(tee) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_bond[mp][0]->sub_port_id(t));
		sale_class = asset->sm_bond[mp][0]->sale_class_id;
		fund_index = asset->sm_bond[mp][0]->asset_fund_index;
		local_pct_to_use = asset->sm_bond[mp][0]->pct_to_use;

		sub_port_class_fund_assets_present[sub_port_num][sale_class][fund_index]
		= 1;

		sub_port_class_fund_initial_book_value[sub_port_num][sale_class][fund_index]
		+= asset->sm_bond[mp][0]->Column(column_num_book_value).Value(t)
		   * local_pct_to_use;

		sub_port_class_fund_initial_accrued_interest[sub_port_num][sale_class][fund_index]
		+= asset->sm_bond[mp][0]->Column(column_num_accrued_interest).Value(t)
		   * local_pct_to_use;

		if (initialize_market_sales_values)
			{
			sub_port_class_fund_initial_market_value[sub_port_num][sale_class][fund_index]
			+= asset->sm_bond[mp][0]->Column(column_num_market_value).Value(t)
			   * local_pct_to_use;

			sub_port_class_fund_initial_unrealized_capital_gains[sub_port_num][sale_class][fund_index]
			+= asset->sm_bond[mp][0]->Column(column_num_unrealized_capital_gains).Value(t)
			   * local_pct_to_use;
			}

#if INITIALIZE_SALES_AND_INVESTMENT_VARIABLES
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_num
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(16) << setprecision(6)
						<< asset->sm_bond[mp][0]->Column(column_num_accrued_interest).Value(t)
							* local_pct_to_use
					<< " " << setw(16) << setprecision(6)
						<< asset->sm_bond[mp][0]->Column(column_num_book_value).Value(t)
							* local_pct_to_use;
			if (initialize_market_sales_values)
				log_screen << " " << setw(16) << setprecision(6)
							<< asset->sm_bond[mp][0]->Column(column_num_market_value).Value(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_bond[mp][0]->mkt_to_bk_ratio(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_bond[mp][0]->unrealzd_cap_gain_to_bk_ratio(t)
								* local_pct_to_use;
			else
				log_screen << " " << setw(16) << setprecision(6) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0;
			log_screen << " " << setw(10) << asset->sm_bond[mp][0]->asset_id
					<< " |" << asset->sm_bond[mp][0]->modelName
					<< " " << asset->sm_bond[mp][0]->port_defn
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__MTG_ASSET_H_)
if (seg_element->mtg_mp_map_active.size() > 0)
	{
	column_num_accrued_interest = asset->sm_mtg[0][0]->Column(xstring_initial_accrued_interest).Number();
	column_num_book_value = asset->sm_mtg[0][0]->Column(xstring_initial_book_value).Number();
	column_num_notional_amount = asset->sm_mtg[0][0]->Column("notional_amt").Number();
	column_num_notional_amount_before_sales = asset->sm_mtg[0][0]->Column("notional_amt_bef_sale").Number();

	if (initialize_market_sales_values)
		{
		column_num_market_value = asset->sm_mtg[0][0]->Column(xstring_initial_market_value).Number();
		column_num_unrealized_capital_gains = asset->sm_mtg[0][0]->Column(xstring_initial_unrealized_capital_gains).Number();
		}

	for (mp_map_iter = seg_element->mtg_mp_map_active.begin();
		 mp_map_iter != seg_element->mtg_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_mtg[mp][0]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_mtg[mp][0]->neg_asset_flag > 0)
			continue;

		if ((tee > max(0, asset->sm_mtg[mp][0]->commencement_period)
			 && asset->sm_mtg[mp][0]->Column(column_num_notional_amount).Value(tee-1) < ASSET_ACTIVE_THRESHOLD)
			|| (tee == asset->sm_mtg[mp][0]->commencement_period
				&& asset->sm_mtg[mp][0]->Column(column_num_notional_amount_before_sales).Value(tee) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_mtg[mp][0]->sub_port_id(t));
		sale_class = asset->sm_mtg[mp][0]->sale_class_id;
		fund_index = asset->sm_mtg[mp][0]->asset_fund_index;
		local_pct_to_use = asset->sm_mtg[mp][0]->pct_to_use;

		sub_port_class_fund_assets_present[sub_port_num][sale_class][fund_index]
		= 1;

		sub_port_class_fund_initial_book_value[sub_port_num][sale_class][fund_index]
		+= asset->sm_mtg[mp][0]->Column(column_num_book_value).Value(t)
		   * local_pct_to_use;

		sub_port_class_fund_initial_accrued_interest[sub_port_num][sale_class][fund_index]
		+= asset->sm_mtg[mp][0]->Column(column_num_accrued_interest).Value(t)
		   * local_pct_to_use;

		if (initialize_market_sales_values)
			{
			sub_port_class_fund_initial_market_value[sub_port_num][sale_class][fund_index]
			+= asset->sm_mtg[mp][0]->Column(column_num_market_value).Value(t)
			   * local_pct_to_use;

			sub_port_class_fund_initial_unrealized_capital_gains[sub_port_num][sale_class][fund_index]
			+= asset->sm_mtg[mp][0]->Column(column_num_unrealized_capital_gains).Value(t)
			   * local_pct_to_use;
			}

#if INITIALIZE_SALES_AND_INVESTMENT_VARIABLES
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_num
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(16) << setprecision(6)
						<< asset->sm_mtg[mp][0]->Column(column_num_accrued_interest).Value(t)
							* local_pct_to_use
					<< " " << setw(16) << setprecision(6)
						<< asset->sm_mtg[mp][0]->Column(column_num_book_value).Value(t)
							* local_pct_to_use;
			if (initialize_market_sales_values)
				log_screen << " " << setw(16) << setprecision(6)
							<< asset->sm_mtg[mp][0]->Column(column_num_market_value).Value(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_mtg[mp][0]->mkt_to_bk_ratio(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_mtg[mp][0]->unrealzd_cap_gain_to_bk_ratio(t)
								* local_pct_to_use;
			else
				log_screen << " " << setw(16) << setprecision(6) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0;
			log_screen << " " << setw(10) << asset->sm_mtg[mp][0]->asset_id
					<< " |" << asset->sm_mtg[mp][0]->modelName
					<< " " << asset->sm_mtg[mp][0]->port_defn
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__SEC_ASSET_H_)
if (seg_element->sec_mp_map_active.size() > 0)
	{
	column_num_accrued_interest = asset->sm_sec[0]->Column(xstring_initial_accrued_interest).Number();
	column_num_book_value = asset->sm_sec[0]->Column(xstring_initial_book_value).Number();
	column_num_notional_amount = asset->sm_sec[0]->Column("notional_amt").Number();
	column_num_notional_amount_before_sales = asset->sm_sec[0]->Column("notional_amt_bef_sale").Number();

	if (initialize_market_sales_values)
		{
		column_num_market_value = asset->sm_sec[0]->Column(xstring_initial_market_value).Number();
		column_num_unrealized_capital_gains = asset->sm_sec[0]->Column(xstring_initial_unrealized_capital_gains).Number();
		}

	for (mp_map_iter = seg_element->sec_mp_map_active.begin();
		 mp_map_iter != seg_element->sec_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_sec[mp]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_sec[mp]->neg_asset_flag > 0)
			continue;

		if ((tee > max(0, asset->sm_sec[mp]->commencement_period)
			 && asset->sm_sec[mp]->Column(column_num_notional_amount).Value(tee-1) < ASSET_ACTIVE_THRESHOLD)
			|| (tee == asset->sm_sec[mp]->commencement_period
				&& asset->sm_sec[mp]->Column(column_num_notional_amount_before_sales).Value(tee) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_sec[mp]->sub_port_id(t));
		sale_class = asset->sm_sec[mp]->sale_class_id;
		fund_index = asset->sm_sec[mp]->asset_fund_index;
		local_pct_to_use = asset->sm_sec[mp]->pct_to_use;

		sub_port_class_fund_assets_present[sub_port_num][sale_class][fund_index]
		= 1;

		sub_port_class_fund_initial_book_value[sub_port_num][sale_class][fund_index]
		+= asset->sm_sec[mp]->Column(column_num_book_value).Value(t)
		   * local_pct_to_use;

		sub_port_class_fund_initial_accrued_interest[sub_port_num][sale_class][fund_index]
		+= asset->sm_sec[mp]->Column(column_num_accrued_interest).Value(t)
		   * local_pct_to_use;

		if (initialize_market_sales_values)
			{
			sub_port_class_fund_initial_market_value[sub_port_num][sale_class][fund_index]
			+= asset->sm_sec[mp]->Column(column_num_market_value).Value(t)
			   * local_pct_to_use;

			sub_port_class_fund_initial_unrealized_capital_gains[sub_port_num][sale_class][fund_index]
			+= asset->sm_sec[mp]->Column(column_num_unrealized_capital_gains).Value(t)
			   * local_pct_to_use;
			}

#if INITIALIZE_SALES_AND_INVESTMENT_VARIABLES
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_num
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(16) << setprecision(6)
						<< asset->sm_sec[mp]->Column(column_num_accrued_interest).Value(t)
							* local_pct_to_use
					<< " " << setw(16) << setprecision(6)
						<< asset->sm_sec[mp]->Column(column_num_book_value).Value(t)
							* local_pct_to_use;
			if (initialize_market_sales_values)
				log_screen << " " << setw(16) << setprecision(6)
							<< asset->sm_sec[mp]->Column(column_num_market_value).Value(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_sec[mp]->mkt_to_bk_ratio(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_sec[mp]->unrealzd_cap_gain_to_bk_ratio(t)
								* local_pct_to_use;
			else
				log_screen << " " << setw(16) << setprecision(6) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0;
			log_screen << " " << setw(10) << asset->sm_sec[mp]->asset_id
					<< " |" << asset->sm_sec[mp]->modelName
					<< " " << asset->sm_sec[mp]->port_defn
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__IRD_ASSET_H_)
if (seg_element->ird_mp_map_active.size() > 0)
	{
	column_num_accrued_interest = asset->sm_ird[0][0]->Column(xstring_initial_accrued_interest).Number();
	column_num_book_value = asset->sm_ird[0][0]->Column(xstring_initial_book_value).Number();
	column_num_notional_amount = asset->sm_ird[0][0]->Column("notional_amt").Number();
	column_num_notional_amount_before_sales = asset->sm_ird[0][0]->Column("notional_amt_bef_sale").Number();

	if (initialize_market_sales_values)
		{
		column_num_market_value = asset->sm_ird[0][0]->Column(xstring_initial_market_value).Number();
		column_num_unrealized_capital_gains = asset->sm_ird[0][0]->Column(xstring_initial_unrealized_capital_gains).Number();
		}

	for (mp_map_iter = seg_element->ird_mp_map_active.begin();
		 mp_map_iter != seg_element->ird_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_ird[mp][0]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_ird[mp][0]->neg_asset_flag > 0)
			continue;

		if ((tee > max(0, asset->sm_ird[mp][0]->commencement_period)
			 && asset->sm_ird[mp][0]->Column(column_num_notional_amount).Value(tee-1) < ASSET_ACTIVE_THRESHOLD)
			|| (tee == asset->sm_ird[mp][0]->commencement_period
				&& asset->sm_ird[mp][0]->Column(column_num_notional_amount_before_sales).Value(tee) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_ird[mp][0]->sub_port_id(t));
		sale_class = asset->sm_ird[mp][0]->sale_class_id;
		fund_index = asset->sm_ird[mp][0]->asset_fund_index;
		local_pct_to_use = asset->sm_ird[mp][0]->pct_to_use;

		sub_port_class_fund_assets_present[sub_port_num][sale_class][fund_index]
		= 1;

		sub_port_class_fund_initial_book_value[sub_port_num][sale_class][fund_index]
		+= asset->sm_ird[mp][0]->Column(column_num_book_value).Value(t)
		   * local_pct_to_use;

		sub_port_class_fund_initial_accrued_interest[sub_port_num][sale_class][fund_index]
		+= asset->sm_ird[mp][0]->Column(column_num_accrued_interest).Value(t)
		   * local_pct_to_use;

		if (initialize_market_sales_values)
			{
			sub_port_class_fund_initial_market_value[sub_port_num][sale_class][fund_index]
			+= asset->sm_ird[mp][0]->Column(column_num_market_value).Value(t)
			   * local_pct_to_use;

			sub_port_class_fund_initial_unrealized_capital_gains[sub_port_num][sale_class][fund_index]
			+= asset->sm_ird[mp][0]->Column(column_num_unrealized_capital_gains).Value(t)
			   * local_pct_to_use;
			}

#if INITIALIZE_SALES_AND_INVESTMENT_VARIABLES
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_num
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(16) << setprecision(6)
						<< asset->sm_ird[mp][0]->Column(column_num_accrued_interest).Value(t)
							* local_pct_to_use
					<< " " << setw(16) << setprecision(6)
						<< asset->sm_ird[mp][0]->Column(column_num_book_value).Value(t)
							* local_pct_to_use;
			if (initialize_market_sales_values)
				log_screen << " " << setw(16) << setprecision(6)
							<< asset->sm_ird[mp][0]->Column(column_num_market_value).Value(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_ird[mp][0]->mkt_to_bk_ratio(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_ird[mp][0]->unrealzd_cap_gain_to_bk_ratio(t)
								* local_pct_to_use;
			else
				log_screen << " " << setw(16) << setprecision(6) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0;
			log_screen << " " << setw(10) << asset->sm_ird[mp][0]->asset_id
					<< " |" << asset->sm_ird[mp][0]->modelName
					<< " " << asset->sm_ird[mp][0]->port_defn
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__RE_ASSET_H_)
if (seg_element->re_mp_map_active.size() > 0)
	{
	column_num_accrued_rent = asset->sm_re[0]->Column(xstring_initial_accrued_rent).Number();
	column_num_book_value = asset->sm_re[0]->Column(xstring_initial_book_value).Number();
	column_num_notional_amount = asset->sm_re[0]->Column("notional_amt").Number();
	column_num_notional_amount_before_sales = asset->sm_re[0]->Column("notional_amt_bef_sale").Number();

	if (initialize_market_sales_values)
		{
		column_num_market_value = asset->sm_re[0]->Column(xstring_initial_market_value).Number();
		column_num_unrealized_capital_gains = asset->sm_re[0]->Column(xstring_initial_unrealized_capital_gains).Number();
		}

	for (mp_map_iter = seg_element->re_mp_map_active.begin();
		 mp_map_iter != seg_element->re_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_re[mp]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_re[mp]->neg_asset_flag > 0)
			continue;

		if ((tee > max(0, asset->sm_re[mp]->commencement_period)
			 && asset->sm_re[mp]->Column(column_num_notional_amount).Value(tee-1) < ASSET_ACTIVE_THRESHOLD)
			|| (tee == asset->sm_re[mp]->commencement_period
				&& asset->sm_re[mp]->Column(column_num_notional_amount_before_sales).Value(tee) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_re[mp]->sub_port_id(t));
		sale_class = asset->sm_re[mp]->sale_class_id;
		fund_index = asset->sm_re[mp]->asset_fund_index;
		local_pct_to_use = asset->sm_re[mp]->pct_to_use;

		sub_port_class_fund_assets_present[sub_port_num][sale_class][fund_index]
		= 1;

		sub_port_class_fund_initial_book_value[sub_port_num][sale_class][fund_index]
		+= asset->sm_re[mp]->Column(column_num_book_value).Value(t)
		   * local_pct_to_use;

		sub_port_class_fund_initial_accrued_interest[sub_port_num][sale_class][fund_index]
		+= asset->sm_re[mp]->Column(column_num_accrued_rent).Value(t)
		   * local_pct_to_use;

		if (initialize_market_sales_values)
			{
			sub_port_class_fund_initial_market_value[sub_port_num][sale_class][fund_index]
			+= asset->sm_re[mp]->Column(column_num_market_value).Value(t)
			   * local_pct_to_use;

			sub_port_class_fund_initial_unrealized_capital_gains[sub_port_num][sale_class][fund_index]
			+= asset->sm_re[mp]->Column(column_num_unrealized_capital_gains).Value(t)
			   * local_pct_to_use;
			}

#if INITIALIZE_SALES_AND_INVESTMENT_VARIABLES
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_num
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(16) << setprecision(6)
						<< asset->sm_re[mp]->Column(column_num_accrued_rent).Value(t)
							* local_pct_to_use
					<< " " << setw(16) << setprecision(6)
						<< asset->sm_re[mp]->Column(column_num_book_value).Value(t)
							* local_pct_to_use;
			if (initialize_market_sales_values)
				log_screen << " " << setw(16) << setprecision(6)
							<< asset->sm_re[mp]->Column(column_num_market_value).Value(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_re[mp]->mkt_to_bk_ratio(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_re[mp]->unrealzd_cap_gain_to_bk_ratio(t)
								* local_pct_to_use;
			else
				log_screen << " " << setw(16) << setprecision(6) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0;
			log_screen << " " << setw(10) << asset->sm_re[mp]->asset_id
					<< " |" << asset->sm_re[mp]->modelName
					<< " " << asset->sm_re[mp]->port_defn
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__EQT_ASSET_H_)
if (seg_element->eqt_mp_map_active.size() > 0)
	{
	column_num_book_value = asset->sm_eqt[0]->Column(xstring_initial_book_value).Number();
	column_num_market_value = asset->sm_eqt[0]->Column(xstring_initial_market_value).Number();
	column_num_notional_amount = asset->sm_eqt[0]->Column("notional_amt").Number();
	column_num_notional_amount_before_sales = asset->sm_eqt[0]->Column("notional_amt_bef_sale").Number();
	column_num_unrealized_capital_gains = asset->sm_eqt[0]->Column(xstring_initial_unrealized_capital_gains).Number();

	for (mp_map_iter = seg_element->eqt_mp_map_active.begin();
		 mp_map_iter != seg_element->eqt_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_eqt[mp]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_eqt[mp]->neg_asset_flag > 0)
			continue;

		if ((tee > max(0, asset->sm_eqt[mp]->commencement_period)
			 && asset->sm_eqt[mp]->Column(column_num_notional_amount).Value(tee-1) < ASSET_ACTIVE_THRESHOLD)
			|| (tee == asset->sm_eqt[mp]->commencement_period
				&& asset->sm_eqt[mp]->Column(column_num_notional_amount_before_sales).Value(tee) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_eqt[mp]->sub_port_id(t));
		sale_class = asset->sm_eqt[mp]->sale_class_id;
		fund_index = asset->sm_eqt[mp]->asset_fund_index;
		local_pct_to_use = asset->sm_eqt[mp]->pct_to_use;

		sub_port_class_fund_assets_present[sub_port_num][sale_class][fund_index]
		= 1;

		sub_port_class_fund_initial_book_value[sub_port_num][sale_class][fund_index]
		+= asset->sm_eqt[mp]->Column(column_num_book_value).Value(t)
		   * local_pct_to_use;

		if (initialize_market_sales_values)
			{
			sub_port_class_fund_initial_market_value[sub_port_num][sale_class][fund_index]
			+= asset->sm_eqt[mp]->Column(column_num_market_value).Value(t)
			   * local_pct_to_use;

			sub_port_class_fund_initial_unrealized_capital_gains[sub_port_num][sale_class][fund_index]
			+= asset->sm_eqt[mp]->Column(column_num_unrealized_capital_gains).Value(t)
			   * local_pct_to_use;
			}

#if INITIALIZE_SALES_AND_INVESTMENT_VARIABLES
		if (write_detail)
			{
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_num
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(16) << setprecision(6) << 0.0
					<< " " << setw(16) << setprecision(6)
						<< asset->sm_eqt[mp]->Column(column_num_book_value).Value(t)
							* local_pct_to_use;
			if (initialize_market_sales_values)
				log_screen << " " << setw(16) << setprecision(6)
							<< asset->sm_eqt[mp]->Column(column_num_market_value).Value(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_eqt[mp]->mkt_to_bk_ratio(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_eqt[mp]->unrealzd_cap_gain_to_bk_ratio(t)
								* local_pct_to_use;
			else
				log_screen << " " << setw(16) << setprecision(6) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0;
			log_screen << " " << setw(10) << asset->sm_eqt[mp]->asset_id
					<< " |" << asset->sm_eqt[mp]->modelName
					<< " " << asset->sm_eqt[mp]->port_defn
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__EIO_ASSET_H_)
if (seg_element->eio_mp_map_active.size() > 0)
	{
	column_num_book_value = asset->sm_eio[0][0]->Column(xstring_initial_book_value).Number();
	column_num_notional_amount = asset->sm_eio[0][0]->Column("notional_amt").Number();
	column_num_notional_amount_before_sales = asset->sm_eio[0][0]->Column("notional_amt_bef_sale").Number();

	if (initialize_market_sales_values)
		{
		column_num_market_value = asset->sm_eio[0][0]->Column(xstring_initial_market_value).Number();
		column_num_unrealized_capital_gains = asset->sm_eio[0][0]->Column(xstring_initial_unrealized_capital_gains).Number();
		}

	for (mp_map_iter = seg_element->eio_mp_map_active.begin();
		 mp_map_iter != seg_element->eio_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_eio[mp][0]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_eio[mp][0]->neg_asset_flag > 0)
			continue;

		if ((tee > max(0, asset->sm_eio[mp][0]->commencement_period)
			 && asset->sm_eio[mp][0]->Column(column_num_notional_amount).Value(tee-1) < ASSET_ACTIVE_THRESHOLD)
			|| (tee == asset->sm_eio[mp][0]->commencement_period
				&& asset->sm_eio[mp][0]->Column(column_num_notional_amount_before_sales).Value(tee) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_eio[mp][0]->sub_port_id(t));
		sale_class = asset->sm_eio[mp][0]->sale_class_id;
		fund_index = asset->sm_eio[mp][0]->asset_fund_index;
		local_pct_to_use = asset->sm_eio[mp][0]->pct_to_use;

		sub_port_class_fund_assets_present[sub_port_num][sale_class][fund_index]
		= 1;

		sub_port_class_fund_initial_book_value[sub_port_num][sale_class][fund_index]
		+= asset->sm_eio[mp][0]->Column(column_num_book_value).Value(t)
		   * local_pct_to_use;

		if (initialize_market_sales_values)
			{
			sub_port_class_fund_initial_market_value[sub_port_num][sale_class][fund_index]
			+= asset->sm_eio[mp][0]->Column(column_num_market_value).Value(t)
			   * local_pct_to_use;

			sub_port_class_fund_initial_unrealized_capital_gains[sub_port_num][sale_class][fund_index]
			+= asset->sm_eio[mp][0]->Column(column_num_unrealized_capital_gains).Value(t)
			   * local_pct_to_use;
			}

#if INITIALIZE_SALES_AND_INVESTMENT_VARIABLES
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_num
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(16) << setprecision(6) << 0.0
					<< " " << setw(16) << setprecision(6)
						<< asset->sm_eio[mp][0]->Column(column_num_book_value).Value(t)
							* local_pct_to_use;
			if (initialize_market_sales_values)
				log_screen << " " << setw(16) << setprecision(6)
							<< asset->sm_eio[mp][0]->Column(column_num_market_value).Value(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_eio[mp][0]->mkt_to_bk_ratio(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_eio[mp][0]->unrealzd_cap_gain_to_bk_ratio(t)
								* local_pct_to_use;
			else
				log_screen << " " << setw(16) << setprecision(6) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0;
			log_screen << " " << setw(10) << asset->sm_eio[mp][0]->asset_id
					<< " |" << asset->sm_eio[mp][0]->modelName
					<< " " << asset->sm_eio[mp][0]->port_defn
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif

#if defined(__EPA_ASSET_H_)
if (seg_element->epa_mp_map_active.size() > 0)
	{
	column_num_accrued_interest = asset->sm_epa[0]->Column(xstring_initial_accrued_interest).Number();
	column_num_book_value = asset->sm_epa[0]->Column(xstring_initial_book_value).Number();
	column_num_notional_amount = asset->sm_epa[0]->Column("notional_amt").Number();
	column_num_notional_amount_before_sales = asset->sm_epa[0]->Column("notional_amt_bef_sale").Number();

	if (initialize_market_sales_values)
		{
		column_num_market_value = asset->sm_epa[0]->Column(xstring_initial_market_value).Number();
		column_num_unrealized_capital_gains = asset->sm_epa[0]->Column(xstring_initial_unrealized_capital_gains).Number();
		}

	for (mp_map_iter = seg_element->epa_mp_map_active.begin();
		 mp_map_iter != seg_element->epa_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (sum_type == SUM_OVER_POSITIVE
			&& asset->sm_epa[mp]->neg_asset_flag < 0)
			continue;

		if (sum_type == SUM_OVER_NEGATIVE
			&& asset->sm_epa[mp]->neg_asset_flag > 0)
			continue;

		if (asset->sm_epa[mp]->Column(column_num_notional_amount).Value(tee-1) < ASSET_ACTIVE_THRESHOLD)
			continue;

		sub_port_num = xint(asset->sm_epa[mp]->sub_port_id(t));
		sale_class = asset->sm_epa[mp]->sale_class_id;
		fund_index = asset->sm_epa[mp]->asset_fund_index;
		local_pct_to_use = asset->sm_epa[mp]->pct_to_use;

		sub_port_class_fund_assets_present[sub_port_num][sale_class][fund_index]
		= 1;

		sub_port_class_fund_initial_book_value[sub_port_num][sale_class][fund_index]
		+= asset->sm_epa[mp]->Column(column_num_book_value).Value(t)
		   * local_pct_to_use;

		sub_port_class_fund_initial_accrued_interest[sub_port_num][sale_class][fund_index]
		+= asset->sm_epa[mp]->Column(column_num_accrued_interest).Value(t)
		   * local_pct_to_use;

		if (initialize_market_sales_values)
			{
			sub_port_class_fund_initial_market_value[sub_port_num][sale_class][fund_index]
			+= asset->sm_epa[mp]->Column(column_num_market_value).Value(t)
			   * local_pct_to_use;

			sub_port_class_fund_initial_unrealized_capital_gains[sub_port_num][sale_class][fund_index]
			+= asset->sm_epa[mp]->Column(column_num_unrealized_capital_gains).Value(t)
			   * local_pct_to_use;
			}

#if INITIALIZE_SALES_AND_INVESTMENT_VARIABLES
		if (write_detail)
			{					
			log_screen.setf(ios::fixed);
			log_screen << " " << setw(4) << setprecision(0) << t
					<< " " << setw(2) << sub_port_num
					<< " " << setw(1) << sale_class
					<< " " << setw(1) << fund_index
					<< " " << setw(16) << setprecision(6) << 0.0
					<< " " << setw(16) << setprecision(6)
					<< asset->sm_bond[mp][0]->Column(column_num_accrued_interest).Value(t)
						* local_pct_to_use
					<< " " << setw(16) << setprecision(6)
					<< asset->sm_epa[mp]->Column(column_num_book_value).Value(t)
						* local_pct_to_use;
			if (initialize_market_sales_values)
				log_screen << " " << setw(16) << setprecision(6)
							<< asset->sm_epa[mp]->Column(column_num_market_value).Value(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_epa[mp]->mkt_to_bk_ratio(t)
								* local_pct_to_use
						<< " " << setw(12) << setprecision(8)
							<< asset->sm_epa[mp]->unrealzd_cap_gain_to_bk_ratio(t)
								* local_pct_to_use;
			else
				log_screen << " " << setw(16) << setprecision(6) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0
						<< " " << setw(12) << setprecision(8) << 0.0;
			log_screen << " " << setw(10) << asset->sm_epa[mp]->asset_id
					<< " |" << asset->sm_epa[mp]->modelName
					<< " " << asset->sm_epa[mp]->port_defn
					<< MSG_ERROR;
			}
#endif
		}
	}
#endif


for (sub_port_num = 0; sub_port_num < asset->sm_asset_sub_port[seg_num].size(); sub_port_num++)
	{
	for (sale_class = 1; sale_class <= MAXIMUM_NUMBER_OF_SALES_CLASSES; sale_class++)
		{
		for (fund_index = 0; fund_index < MAXIMUM_NUMBER_OF_ASSET_FUNDS; fund_index++)
			{
			sub_port_fund_initial_book_plus_accrued[sub_port_num][fund_index]
			+= sub_port_class_fund_initial_book_value[sub_port_num][sale_class][fund_index]
			   + sub_port_class_fund_initial_accrued_interest[sub_port_num][sale_class][fund_index];
			}
		}
	}

return 1.0;
}



#line 1 "inv_strat_select.INVSTRAT_ASSET.for"                                                                                   
bool INVSTRAT_ASSET::inv_strat_select(int t, StrEnum::EnumValue strategy_type, bool issue_warnings, bool &warnings)
{
// This function selects a specific strategy and initializes variables for that strategy.
//
// Valid strategy_type values are
//	"Current", "Negative"
//	"Shorter", "Shortest", "Longer", and "Longest".

bool valid_strategy = true;

date_lookup = date(t);
xstring inv_strat_planned_local = inv_strat_planned;

if ((t == prior_strategy_selected_t && strategy_type == prior_strategy_type) // Have already processed selection
	|| t == 0) // for asset data checks
	return valid_strategy;

// Ensure negative cash flow strategy for current period is selected
if (strategy_type == NEGATIVE)
	neg_cash_flow_strat_set(t);	

if (inv_strat_planned_local == "NONE"
	&& strategy_type != NEGATIVE)
	{
	if (strategy_type == CURRENT)
		return valid_strategy;

	return (!valid_strategy);
	}

prior_strategy_selected_t = t;
prior_strategy_type = strategy_type;

// Select current investment strategy set
inv_strat_set(t);

// Specify current investment strategy
if (strategy_type == CURRENT)
	inv_strat_id = inv_strat_current;
else if (strategy_type == NEGATIVE)
	inv_strat_id = inv_strat_neg;
else if (strategy_type == SHORTER)
	inv_strat_id = inv_strat_shorter;
else if (strategy_type == SHORTEST)
	inv_strat_id = inv_strat_shortest;
else if (strategy_type == LONGER)
	inv_strat_id = inv_strat_longer;
else if (strategy_type == LONGEST)
	inv_strat_id = inv_strat_longest;

// Lookup key is inv_strat_id
inv_strat_id = inv_strat_id;
cash_tgt_pct = inv_strat_cash_tgt_pct;

inv_strat_id = inv_strat_id;
asset_sub_port_distribn_defn = inv_strat_distribn_defn;

inv_strat_id = inv_strat_id;
port_sprd_adj_crbg = inv_strat_port_sprd_adj_crbg;  //CRBG - portfolio spread adjustment

inv_strat_id = inv_strat_id;
dur_wtd_sprd_adj_crbg = inv_strat_dur_wtd_sprd_adj_crbg;  //CRBG - duration weighted spread adjustment

double inv_tgt_pct_total = 0.0;

// Set asset sub portfolio target percentages using current investment strategy
int sub_port_num = 0;

for (sub_port_num = 0; sub_port_num < asset->sm_asset_sub_port[seg_num].size(); sub_port_num++)
	{
	if (asset->sm_asset_sub_port[seg_num][sub_port_num][0]->port_defn != INVESTMENT)
		continue;
	
	asset_sub_port_id = company->sm_asset->asset_sub_ports[sub_port_num];
	
	inv_strat_id = inv_strat_id;
	asset->sm_asset_sub_port[seg_num][sub_port_num][0]->inv_tgt_pct = asset_sub_port_inv_tgt_pct;

	inv_tgt_pct_total += asset->sm_asset_sub_port[seg_num][sub_port_num][0]->inv_tgt_pct;
	}

// Normalize percentages if needed
if (cash_tgt_pct < 1.0 
	&& fabs(inv_tgt_pct_total - 1.0) > rate_ratio_threshold)
	{
	if (fabs(inv_tgt_pct_total) > rate_ratio_threshold)
		{					
		for (sub_port_num = 0; sub_port_num < asset->sm_asset_sub_port[seg_num].size(); sub_port_num++)
			{
			if (asset->sm_asset_sub_port[seg_num][sub_port_num][0]->port_defn != INVESTMENT)
				continue;
	
			asset->sm_asset_sub_port[seg_num][sub_port_num][0]->inv_tgt_pct
			/= inv_tgt_pct_total;
			}
						
		if (data_validation_defn == YES)
			{
			xstring message;
			
			message = "Warning: Asset sub portfolio investment target percentages do not add to 100% for investment strategy "
			          + inv_strat_id + "; percentages have been normalized.";
						
			log_screen << message << MSG_ERROR;
			}
		}
	else
		throw FatalError("Asset sub portfolio investment target percentages have not been specified for investment strategy "
		                 + inv_strat_id + "; projection terminated.");					
	}

// Populate purchase asset definition arrays
set_asset_defn(INVESTMENT);

bool warnings2 = false;
if (purch_asset_max_num > 0)
	warnings2 = normalize_purch_asset_weight(issue_warnings);

warnings = warnings || warnings2;

if (asset->asset_detail_rpt_inv_strat_flag(t)
	&& t != 0) // Suppress output during validate_asset_data
	{
	xstring strategy_type_string;

	if (strategy_type == NEGATIVE)
		strategy_type_string = "Negative";		
	else if (strategy_type == CURRENT)
		strategy_type_string = "Current";
	else if (strategy_type == SHORTER)
		strategy_type_string = "Shorter";
	else if (strategy_type == SHORTEST)
		strategy_type_string = "Shortest";
	else if (strategy_type == LONGER)
		strategy_type_string = "Longer";
	else if (strategy_type == LONGEST)
		strategy_type_string = "Longest";
	else
		strategy_type_string = "Undefined";

	seg_element->SALFile << endl << "Selected" << strategy_type_string
				 << "Strat," << inv_strat_id
				 << endl;
	}

return valid_strategy;
}



#line 1 "inv_strat_set.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::inv_strat_set(int t)
{
// This function selects either the economic or planned set of investment strategies.
if (t == prior_strategy_set_t // Have already processed selection for this month
	|| t == 0) // For asset data checks
	return;

prior_strategy_set_t = t;

seg_id = seg_id;
int inv_strat_economic_tests_local = inv_strat_economic_tests;

// Test economic investment strategies
if (inv_strat_economic_tests_local > 0)
	{
	for (inv_strat_economic_test_num = 1; inv_strat_economic_test_num <= inv_strat_economic_tests_local; inv_strat_economic_test_num++)
		{
		double test_rate_1 = 0.0;
		double test_rate_2 = 0.0;
		double total_rate_1 = 0.0;
		double total_rate_2 = 0.0;
		double compare_rate = 0.0;

		inv_strat_economic_test_num = inv_strat_economic_test_num;
		int inv_strat_economic_mths_local = inv_strat_economic_mths;

		inv_strat_economic_test_num = inv_strat_economic_test_num;
		double inv_strat_economic_rate_1_term_local = inv_strat_economic_rate_1_term;

		inv_strat_economic_test_num = inv_strat_economic_test_num;
		double inv_strat_economic_rate_2_term_local = inv_strat_economic_rate_2_term;

		inv_strat_economic_test_num = inv_strat_economic_test_num;
		double inv_strat_economic_lag_mths_local = inv_strat_economic_lag_mths;

		inv_strat_economic_test_num = inv_strat_economic_test_num;
		StrEnum::EnumValue inv_strat_economic_test_defn_local = inv_strat_economic_test_defn;

		inv_strat_economic_test_num = inv_strat_economic_test_num;
		StrEnum::EnumValue inv_strat_economic_test_calc_defn_local = inv_strat_economic_test_calc_defn;

		inv_strat_economic_test_num = inv_strat_economic_test_num;
		StrEnum::EnumValue inv_strat_economic_compare_defn_local = inv_strat_economic_compare_defn;

		inv_strat_economic_test_num = inv_strat_economic_test_num;
		double inv_strat_economic_fixed_test_val_local = inv_strat_economic_fixed_test_val;

		for (int month = 1; month <= inv_strat_economic_mths_local; month++)
			{
			if (inv_strat_economic_rate_1_term_local > rate_ratio_threshold)
				test_rate_1
				= rates->get_int_rate(t - month + 1,
				        "Govt",
				        GET_YIELD_RATE,
						inv_strat_economic_rate_1_term_local,
						0,
						NOMINAL_SEMIANNUAL,
						NO_SHIFT);

			if (inv_strat_economic_rate_2_term_local > rate_ratio_threshold)
				test_rate_2
				= rates->get_int_rate(t - month - inv_strat_economic_lag_mths_local + 1,
				        "Govt",
				        GET_YIELD_RATE,
						inv_strat_economic_rate_2_term_local,
						0,
						NOMINAL_SEMIANNUAL,
						NO_SHIFT);

			if (inv_strat_economic_test_defn_local == AVERAGE_RATE)
				{
				total_rate_1 += test_rate_1;				
				total_rate_2 += test_rate_2;
				}
			else if (inv_strat_economic_test_defn_local == MINIMUM_RATE)
				{
				if (month == 1)
					{
					total_rate_1 = test_rate_1;				
					total_rate_2 = test_rate_2;
					}
				else // (month > 1)
					{
					total_rate_1 = min(test_rate_1, total_rate_1);				
					total_rate_2 = min(test_rate_2, total_rate_2);
					}
				}
			else if (inv_strat_economic_test_defn_local == MAXIMUM_RATE)
				{
				total_rate_1 = max(test_rate_1, total_rate_1);				
				total_rate_2 = max(test_rate_2, total_rate_2);
				}
			} // End monthly loop
			
		if (inv_strat_economic_test_defn_local == AVERAGE_RATE)
			{
			total_rate_1 /= inv_strat_economic_mths_local;				
			total_rate_2 /= inv_strat_economic_mths_local;
			}
		
		if (inv_strat_economic_test_calc_defn_local == SUBTRACTION)
			compare_rate = total_rate_1 - total_rate_2;
		else if ((inv_strat_economic_test_calc_defn_local == DIVISION
		         && fabs(total_rate_2) > rate_ratio_threshold))
			compare_rate = total_rate_1 / total_rate_2;
			
		if ((inv_strat_economic_compare_defn_local == GREATER_THAN
		     && compare_rate <= inv_strat_economic_fixed_test_val_local)
		    || (inv_strat_economic_compare_defn_local == LESS_THAN
		        && compare_rate >= inv_strat_economic_fixed_test_val_local))
			continue; // Test failed
		
		// Test passed, set active strategy from this economic test
		inv_strat_economic_test_num = inv_strat_economic_test_num;
		inv_strat_current = inv_strat_economic_planned;
		
		inv_strat_economic_test_num = inv_strat_economic_test_num;
		dur_match_tgt_incr = inv_strat_economic_dur_match_tgt_incr;
		
		inv_strat_economic_test_num = inv_strat_economic_test_num;
		dur_match_tolerance_incr = inv_strat_economic_dur_match_tolerance_incr;
				
		inv_strat_economic_test_num = inv_strat_economic_test_num;
		xstring inv_strat_economic_shorter_local = inv_strat_economic_shorter;

		inv_strat_economic_test_num = inv_strat_economic_test_num;
		xstring inv_strat_economic_shortest_local = inv_strat_economic_shortest;

		inv_strat_economic_test_num = inv_strat_economic_test_num;
		xstring inv_strat_economic_longer_local = inv_strat_economic_longer;

		inv_strat_economic_test_num = inv_strat_economic_test_num;
		xstring inv_strat_economic_longest_local = inv_strat_economic_longest;

		if (inv_strat_economic_shorter_local == "NONE")
			inv_strat_shorter = inv_strat_current;
		else
			inv_strat_shorter = inv_strat_economic_shorter_local;
		
		if (inv_strat_economic_shortest_local == "NONE")
			inv_strat_shortest = inv_strat_current;
		else
			inv_strat_shortest = inv_strat_economic_shortest_local;
		
		if (inv_strat_economic_longer_local == "NONE")
			inv_strat_longer = inv_strat_current;
		else
			inv_strat_longer = inv_strat_economic_longer_local;
		
		if (inv_strat_economic_longest_local == "NONE")
			inv_strat_longest = inv_strat_current;
		else
			inv_strat_longest = inv_strat_economic_longest_local;
		
		return;
		} // End economic strategy conditions test
	} // End economic condition strategies

// All economic strategy tests failed; set planned strategy
dur_match_tgt_incr = 0.0;
dur_match_tolerance_incr = 0.0;

date_lookup = date(t);
inv_strat_current = inv_strat_planned;

date_lookup = date(t);
xstring inv_strat_planned_shorter_local = inv_strat_planned_shorter;

date_lookup = date(t);
xstring inv_strat_planned_shortest_local = inv_strat_planned_shortest;

date_lookup = date(t);
xstring inv_strat_planned_longer_local = inv_strat_planned_longer;

date_lookup = date(t);
xstring inv_strat_planned_longest_local = inv_strat_planned_longest;

if (inv_strat_planned_shorter_local == "NONE")
	inv_strat_shorter = inv_strat_current;
else
	inv_strat_shorter = inv_strat_planned_shorter_local;
	
if (inv_strat_planned_shortest_local == "NONE")
	inv_strat_shortest = inv_strat_current;
else
	inv_strat_shortest = inv_strat_planned_shortest_local;
	
if (inv_strat_planned_longer_local == "NONE")
	inv_strat_longer = inv_strat_current;
else
	inv_strat_longer = inv_strat_planned_longer_local;
	
if (inv_strat_planned_longest_local == "NONE")
	inv_strat_longest = inv_strat_current;
else
	inv_strat_longest = inv_strat_planned_longest_local;

return;
}



#line 1 "neg_cash_flow_strat_set.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::neg_cash_flow_strat_set(int t)
{
// This function selects either the economic or planned set of negative cash flow strategies.
if (t == prior_neg_cash_flow_strategy_set_t // Have already processed selection for this month
	|| t == 0) // For asset data checks
	return;

prior_neg_cash_flow_strategy_set_t = t;

bool economic_strategy_selected = false;

seg_id = seg_id;
int neg_cash_flow_strat_economic_tests_local = neg_cash_flow_strat_economic_tests;

// Test Economic negative cash flow strategies
// Test economic investment strategies
if (neg_cash_flow_strat_economic_tests_local > 0)
	{
	for (neg_cash_flow_strat_economic_test_num = 1; neg_cash_flow_strat_economic_test_num <= neg_cash_flow_strat_economic_tests_local; neg_cash_flow_strat_economic_test_num++)
		{
		double test_rate_1 = 0.0;
		double test_rate_2 = 0.0;
		double total_rate_1 = 0.0;
		double total_rate_2 = 0.0;
		double compare_rate = 0.0;

		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
		int neg_cash_flow_strat_economic_mths_local = neg_cash_flow_strat_economic_mths;

		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
		double neg_cash_flow_strat_economic_rate_1_term_local = neg_cash_flow_strat_economic_rate_1_term;

		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
		double neg_cash_flow_strat_economic_rate_2_term_local = neg_cash_flow_strat_economic_rate_2_term;

		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;		
		double neg_cash_flow_strat_economic_fixed_test_val_local = neg_cash_flow_strat_economic_fixed_test_val;

		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;		
		double neg_cash_flow_strat_economic_lag_mths_local = neg_cash_flow_strat_economic_lag_mths;

		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;		
		StrEnum::EnumValue neg_cash_flow_strat_economic_compare_defn_local = neg_cash_flow_strat_economic_compare_defn;

		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;		
		StrEnum::EnumValue neg_cash_flow_strat_economic_test_defn_local = neg_cash_flow_strat_economic_test_defn;

		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;		
		StrEnum::EnumValue neg_cash_flow_strat_economic_test_calc_defn_local = neg_cash_flow_strat_economic_test_calc_defn;

		for (int month = 1; month <= neg_cash_flow_strat_economic_mths_local; month++)
			{
			if (neg_cash_flow_strat_economic_rate_1_term_local > rate_ratio_threshold)
				test_rate_1
				= rates->get_int_rate(t - month + 1,
				        "Govt",
				        GET_YIELD_RATE,
						neg_cash_flow_strat_economic_rate_1_term_local,
						0,
						NOMINAL_SEMIANNUAL,
						NO_SHIFT);

			if (neg_cash_flow_strat_economic_rate_2_term_local > rate_ratio_threshold)
				test_rate_2
				= rates->get_int_rate(t - month - neg_cash_flow_strat_economic_lag_mths_local + 1,
				        "Govt",
				        GET_YIELD_RATE,
						neg_cash_flow_strat_economic_rate_2_term_local,
						0,
						NOMINAL_SEMIANNUAL,
						NO_SHIFT);

			if (neg_cash_flow_strat_economic_test_defn_local == AVERAGE_RATE)
				{
				total_rate_1 += test_rate_1;				
				total_rate_2 += test_rate_2;
				}
			else if (neg_cash_flow_strat_economic_test_defn_local == MINIMUM_RATE)
				{
				if (month == 1)
					{
					total_rate_1 = test_rate_1;				
					total_rate_2 = test_rate_2;
					}
				else // (month > 1)
					{
					total_rate_1 = min(test_rate_1, total_rate_1);				
					total_rate_2 = min(test_rate_2, total_rate_2);
					}
				}
			else if (neg_cash_flow_strat_economic_test_defn_local == MAXIMUM_RATE)
				{
				total_rate_1 = max(test_rate_1, total_rate_1);				
				total_rate_2 = max(test_rate_2, total_rate_2);
				}
			} // End monthly loop
			
		if (neg_cash_flow_strat_economic_test_defn_local == AVERAGE_RATE)
			{
			total_rate_1 /= neg_cash_flow_strat_economic_mths_local;				
			total_rate_2 /= neg_cash_flow_strat_economic_mths_local;
			}
		
		if (neg_cash_flow_strat_economic_test_calc_defn_local == SUBTRACTION)
			compare_rate = total_rate_1 - total_rate_2;
		else if ((neg_cash_flow_strat_economic_test_calc_defn_local == DIVISION
		         && fabs(total_rate_2) > rate_ratio_threshold))
			compare_rate = total_rate_1 / total_rate_2;
			
		if ((neg_cash_flow_strat_economic_compare_defn_local == GREATER_THAN
		     && compare_rate <= neg_cash_flow_strat_economic_fixed_test_val_local)
		    || (neg_cash_flow_strat_economic_compare_defn_local == LESS_THAN
		        && compare_rate >= neg_cash_flow_strat_economic_fixed_test_val_local))
			continue; // Test failed
		
		// Test passed, set active negative cash flow strategy from this economic test and break
		economic_strategy_selected = true;
		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
		neg_cash_flow_strat = neg_cash_flow_strat_economic;
		
		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
		neg_cash_flow_cash_bal_defn = neg_cash_flow_strat_economic_cash_bal_defn;
		
		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
		neg_cash_flow_cash_thresh_pct = neg_cash_flow_strat_economic_cash_thresh_pct;
		
		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
		neg_cash_flow_cash_thresh_addn = neg_cash_flow_strat_economic_cash_thresh_addn;
		
		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
		neg_cash_flow_neg_assets = neg_cash_flow_strat_economic_neg_assets;
		inv_strat_neg = neg_cash_flow_neg_assets;
		
		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
		neg_cash_flow_sale_selection_defn = neg_cash_flow_strat_economic_sale_selection_defn;
		
		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
		neg_cash_flow_sale_priority_avail_for_sale = neg_cash_flow_strat_economic_sale_priority_avail_for_sale;
		
		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
		neg_cash_flow_sale_priority_trading = neg_cash_flow_strat_economic_sale_priority_trading;
		
		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
		neg_cash_flow_sale_priority_held_to_maturity = neg_cash_flow_strat_economic_sale_priority_held_to_maturity;
		
		neg_cash_flow_strat_economic_test_num = neg_cash_flow_strat_economic_test_num;
		neg_cash_flow_sale_priority_not_assigned = neg_cash_flow_strat_economic_sale_priority_not_assigned;

		break;
		} // End economic strategy conditions test
	} // End economic condition strategies

// If economic tests failed, set strategy to planned strategy
if (!economic_strategy_selected)
	{
	date_lookup = date(t);
	neg_cash_flow_strat = neg_cash_flow_strat_planned;
	
	date_lookup = date(t);
	neg_cash_flow_cash_bal_defn = neg_cash_flow_strat_planned_cash_bal_defn;
	
	date_lookup = date(t);
	neg_cash_flow_cash_thresh_pct = neg_cash_flow_strat_planned_cash_thresh_pct;
	
	date_lookup = date(t);
	neg_cash_flow_cash_thresh_addn = neg_cash_flow_strat_planned_cash_thresh_addn;
	
	date_lookup = date(t);
	neg_cash_flow_neg_assets = neg_cash_flow_strat_planned_neg_assets;
	inv_strat_neg = neg_cash_flow_neg_assets;
	
	date_lookup = date(t);
	neg_cash_flow_sale_selection_defn = neg_cash_flow_strat_planned_sale_selection_defn;
	
	date_lookup = date(t);
	neg_cash_flow_sale_priority_avail_for_sale = neg_cash_flow_strat_planned_sale_priority_avail_for_sale;
	
	date_lookup = date(t);
	neg_cash_flow_sale_priority_trading = neg_cash_flow_strat_planned_sale_priority_trading;
	
	date_lookup = date(t);
	neg_cash_flow_sale_priority_held_to_maturity = neg_cash_flow_strat_planned_sale_priority_held_to_maturity;
	
	date_lookup = date(t);
	neg_cash_flow_sale_priority_not_assigned = neg_cash_flow_strat_planned_sale_priority_not_assigned;
	}

neg_cash_flow_sales_priority_class_max 
= max(neg_cash_flow_sale_priority_not_assigned,
	max(neg_cash_flow_sale_priority_avail_for_sale,
		max(neg_cash_flow_sale_priority_trading,
			max(neg_cash_flow_sale_priority_held_to_maturity, 1))));

neg_cash_flow_sale_class_priority[1] = neg_cash_flow_sale_priority_not_assigned;
neg_cash_flow_sale_class_priority[2] = neg_cash_flow_sale_priority_avail_for_sale;
neg_cash_flow_sale_class_priority[3] = neg_cash_flow_sale_priority_trading;
neg_cash_flow_sale_class_priority[4] = neg_cash_flow_sale_priority_held_to_maturity;

if (asset->asset_detail_rpt_inv_strat_flag(t))
	seg_element->SALFile << endl
				 << "Negative Cash Flow Strategy Selected" << endl 
				 << "Strategy," << neg_cash_flow_strat << endl 
				 << "CashBalDefn," << neg_cash_flow_cash_bal_defn << endl 
				 << "CashThreshPct," << neg_cash_flow_cash_thresh_pct << endl 
				 << "CashThreshAddn," << neg_cash_flow_cash_thresh_addn << endl 
				 << "NegAssetsStrat," << neg_cash_flow_neg_assets << endl 
				 << "SaleSelectionDefn," << neg_cash_flow_sale_selection_defn << endl 
				 << "SalePriorityAvailForSale," << neg_cash_flow_sale_priority_avail_for_sale << endl 
				 << "SalePriorityTrading," << neg_cash_flow_sale_priority_trading << endl 
				 << "SalePriorityHeldToMat," << neg_cash_flow_sale_priority_held_to_maturity << endl 
				 << "SalePriorityNotAssigned," << neg_cash_flow_sale_priority_not_assigned << endl; 

return;
}



#line 1 "normalize_purch_asset_weight.INVSTRAT_ASSET.for"                                                                                   
bool INVSTRAT_ASSET::normalize_purch_asset_weight(bool issue_warnings)
{
int panum;
int asset_sub_port;
bool normalizn_needed = false;
bool warnings = false;

// Reset arrays
for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
	{
	asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum = 0.0;
	asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd = 0.0;
	}

// Sum purchase asset weights into assigned asset sub portfolios
for (panum = 0; panum < purch_asset_max_num; panum++)
	{
	if (purch_assets_port_defn[panum] != INVESTMENT)
		continue;
	
	asset_sub_port = purch_assets_asset_sub_port_num[panum];

	inv_strat_id = inv_strat_id;
	purch_asset_id = purch_assets_id[panum];
	xstring purch_asset_sub_port_id_local = purch_asset_sub_port_id;

	if (asset_sub_port <= -1)
		throw FatalError("Purchase asset " + purch_asset_id
		                 + " is assigned to asset sub portfolio "
		                 + purch_asset_sub_port_id_local
		                 + ", which is not defined. Please correct definitions.");
	
	a_subport_element = asset->sm_asset_sub_port[seg_num][asset_sub_port][0];

	if (a_subport_element->port_defn == INVESTMENT)
		{
		if (purch_assets_weight[panum] > rate_ratio_threshold)
			a_subport_element->purch_asset_weight_sum
				+= purch_assets_weight[panum];
		}
	else // Asset sub portfolio not for purchase assets
		throw FatalError("Purchase asset " + purch_asset_id
		                 + " has portfolio definition = Investment, but is assigned to asset sub portfolio "
		                 + purch_asset_sub_port_id_local
		                 + ", which is not defined for purchase assets. Please correct definitions.");		
	}

// Check for purchase asset sub portfolios not adding to 100% for each sub portfolio
for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
	{
	if (asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->port_defn != INVESTMENT
		|| asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct < rate_ratio_threshold)
		continue;
	
	if (fabs(asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum - 1.0) > rate_ratio_threshold)
		{
		if (data_validation_defn == YES)
			{
			xstring message
			= "Warning: Asset sub portfolio " + asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->sub_port_id
	          + " has assigned purchase assets with weights that do not add to 100% for investment strategy "
              + inv_strat_id
	          + "; weights have been normalized.";
						
			log_screen << message << MSG_ERROR;
			}
		
		normalizn_needed = true;
		}
	} // end checking asset sub portfolios

// Normalize purchase asset weights
if (normalizn_needed)
	{
	for (panum = 0; panum < purch_asset_max_num; panum++)
		{
		asset_sub_port = purch_assets_asset_sub_port_num[panum];

		if (asset_sub_port > -1) // Do not remove
			{
			a_subport_element = asset->sm_asset_sub_port[seg_num][asset_sub_port][0];

			if (a_subport_element->purch_asset_weight_sum > rate_ratio_threshold)
				purch_assets_weight[panum]
				/= a_subport_element->purch_asset_weight_sum;
			else
				purch_assets_weight[panum] = 0.0;

			a_subport_element->purch_asset_weight_sum_normalzd
			+= purch_assets_weight[panum];
			} 
		} // end for ianmum	
	} // end if (normalizn_needed)

asset_sub_port_inv_tgt_pct_sum = 0.0;

for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
	{
	a_subport_element = asset->sm_asset_sub_port[seg_num][asset_sub_port][0];

	if (a_subport_element->purch_asset_weight_sum > rate_ratio_threshold)
		a_subport_element->purch_asset_weight_sum = 1.0;
		
	if (a_subport_element->inv_tgt_pct > rate_ratio_threshold
		&& ((a_subport_element->purch_asset_weight_sum_normalzd)
			 < (1.0 - rate_ratio_threshold)))
		{
		if (issue_warnings)
			{
			xstring message;
			warnings = true;
			message = "Warning: For investment strategy '" + inv_strat_id
					+ "' the normalized sub portfolio percentage (" + xstring(a_subport_element->inv_tgt_pct)
					+ ")\n ... for asset sub portfolio '" + a_subport_element->sub_port_id
					+ "' is positive but no purchase assets have been defined for this asset sub portfolio."
					+ "\n ... Amounts allocated to this sub portfolio are invested in the interim cash account_id.";
			log_screen << message << MSG_ERROR;
			if (seg_element->SALFile)
				seg_element->SALFile << endl << message;
			}

		a_subport_element->purch_asset_weight_sum_normalzd = 1.0;
		}

	asset_sub_port_inv_tgt_pct_sum 
	+= a_subport_element->purch_asset_weight_sum_normalzd 
	   * a_subport_element->inv_tgt_pct;
	}


if (issue_warnings)
	log_screen.unsetf(ios::fixed);

return warnings;
}



#line 1 "rebal_inv_assets_sale.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::rebal_inv_assets_sale(int t, StrEnum::EnumValue sell_assets, int turnover_rate_freq)
{
// This function handles rebalancing sales of investment assets.
int asset_sub_port = 0;
int sale_class = 0;
int class_priority_level = 0;
double rebal_book_plus_accrued = 0.0;
double total_investment_sub_port_percents = 0.0;
double excess_over_tolerance = 0.0;
double excess_over_target = 0.0;
double minimum_sales_amount = 0.0;
double net_cash_from_sales = 0.0;
double asset_sub_port_percentage_for_selected_strategy = 0.0;
static SmartArray <double> sub_port_target_percentage;
static SmartArray <double> sub_port_percent_of_book_value;
bool is_sell_assets = (sell_assets == YES);
int sub_port_number = 0;

seg_id = seg_id;
StrEnum::EnumValue rebal_sale_selection_defn_local = rebal_sale_selection_defn;

for (sub_port_number = 0; sub_port_number < asset->sm_asset_sub_port[seg_num].size(); sub_port_number++)
	total_investment_sub_port_percents 
	+= asset->sm_asset_sub_port[seg_num][sub_port_number][0]->inv_tgt_pct;

if (sub_port_target_percentage.size() < asset->sm_asset_sub_port[seg_num].size())
	sub_port_target_percentage.resize(asset->sm_asset_sub_port[seg_num].size());

if (sub_port_percent_of_book_value.size() < asset->sm_asset_sub_port[seg_num].size())
	sub_port_percent_of_book_value.resize(asset->sm_asset_sub_port[seg_num].size());

for (sub_port_number = 0; sub_port_number < asset->sm_asset_sub_port[seg_num].size(); sub_port_number++)
	asset->sm_asset_sub_port[seg_num][sub_port_number][0]->sub_ports_to_sell = 0;

for (class_priority_level = 1;
	 class_priority_level <= rebal_sales_priority_class_max;
	 class_priority_level++)
	{
	for (sale_class = 1; sale_class <= MAXIMUM_NUMBER_OF_SALES_CLASSES; sale_class++)
		{
		if (rebal_sale_class_priority[sale_class] == class_priority_level)
			asset_class_to_sell_flag[sale_class] = 1;
		else
			asset_class_to_sell_flag[sale_class] = 0;
		} // end_for over sale_class

	for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
		{
	
		// are assets present?			
		asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->sub_ports_to_sell = 1;		

		rebal_book_plus_accrued = 0.0;

		if (is_sell_assets)
			rebal_book_plus_accrued
			+= sub_port_fund_initial_book_plus_accrued[asset_sub_port][INVESTMENT_FUND_INDEX]
			   - sub_port_fund_book_plus_accrued_sold[asset_sub_port][INVESTMENT_FUND_INDEX];
		else
			rebal_book_plus_accrued
			+= sub_port_fund_initial_book_plus_accrued[asset_sub_port][INVESTMENT_FUND_INDEX]
			   - sub_port_fund_expected_book_plus_accrued_sold[asset_sub_port][INVESTMENT_FUND_INDEX];

		if (rebal_book_plus_accrued > rate_ratio_threshold)
			{
			if (investable_assets_bef_rebal(t) > 0.0)
				sub_port_percent_of_book_value[asset_sub_port]
				= rebal_book_plus_accrued 
				  / investable_assets_bef_rebal(t);
			else
				sub_port_percent_of_book_value[asset_sub_port] = 0.0;

			// Asset sub portfolio percent
			asset_sub_port_percentage_for_selected_strategy
			= asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->inv_tgt_pct
			  * asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->purch_asset_weight_sum_normalzd;
			
			if (total_investment_sub_port_percents > 0.0)
				sub_port_target_percentage[asset_sub_port]
				= asset_sub_port_percentage_for_selected_strategy
				  * (1.0 - cash_tgt_pct)
				  / total_investment_sub_port_percents;
			else
				sub_port_target_percentage[asset_sub_port] = 0.0;

			excess_over_tolerance
			= max(0.0,
			      sub_port_percent_of_book_value[asset_sub_port]
				  - sub_port_target_percentage[asset_sub_port]
				  - asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->rebal_tolerance_pct);

			if (excess_over_tolerance > aggregate_amount_threshold
				|| (asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->rebal_annual_turnover_pct_min > aggregate_amount_threshold	
					&& sub_port_percent_of_book_value[asset_sub_port] > aggregate_amount_threshold))
				{
				minimum_sales_amount
				= rebal_book_plus_accrued
				  * asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->rebal_annual_turnover_pct_min
				  / turnover_rate_freq;

				if (max(0.0,
				        rebal_book_plus_accrued
						- sub_port_target_percentage[asset_sub_port]
						  * investable_assets_bef_rebal(t))
				      / rebal_book_plus_accrued
					> min(1.0,
					      asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->rebal_annual_turnover_pct_max
					      / turnover_rate_freq))
					excess_over_target
					= max(minimum_sales_amount,
					      rebal_book_plus_accrued
					      * min(1.0,
					            asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->rebal_annual_turnover_pct_max
					            / turnover_rate_freq));
				else
					excess_over_target
					= max(minimum_sales_amount,
					      rebal_book_plus_accrued
					      - sub_port_target_percentage[asset_sub_port]
					        * investable_assets_bef_rebal(t));
						
				net_cash_from_sales
				+= sell_assets_control(t, sell_assets,
				                       REBALANCING_SALES,
				                       rebal_sale_selection_defn_local,
				                       excess_over_target);

				asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->sub_ports_to_sell = 0;
				} // endif excess_over_tolerance(t) > 0.0 ...
			else
				{
				asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->sub_ports_to_sell = 0;
				}
			} // endif rebal_book_plus_accrued != 0.0
		} // end_for on asset_sub_port
	} // end_for on class_priority_level

return net_cash_from_sales;
}



#line 1 "rebal_sale.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::rebal_sale(int t, StrEnum::EnumValue sell_assets)
{
int asset_sub_port = 0;
int fund_index_min_for_sales = 0;
int fund_index_max_for_sales = 0;
//int fund_value_strategy_exists = 0;
double total_investment_sub_port_percents = 0.0;
double turnover_rate_freq = 0.0;
double net_cash_from_sales = 0.0;
int sub_port_number = 0;

seg_id = seg_id;
StrEnum::EnumValue rebal_freq_local = rebal_freq;
seg_id = seg_id;
int yrs_to_inv_mthly_local = yrs_to_inv_mthly;
seg_id = seg_id;
int yrs_to_inv_qtrly_local = yrs_to_inv_qtrly;

for (sub_port_number = 0; sub_port_number < asset->sm_asset_sub_port[seg_num].size(); sub_port_number++)
	total_investment_sub_port_percents
	+= asset->sm_asset_sub_port[seg_num][sub_port_number][0]->inv_tgt_pct;

if (!(inv_eom_flag(t)
	  && rebal_freq_local != NOT_APPLICABLE
	  && asset_sub_port_distribn_defn == BOOK
	  && mths_to_rebal(t) == 0))
	{
	if (dur_match_flag(t))
		initialize_sale_and_inv_vars_eom(t);
		
	return 0.0;
	}

initialize_sale_and_inv_vars_eom(t);

if (asset->asset_detail_rpt_inv_strat_flag(t)
	&& display_rebal_sales_header == YES)
	{
	display_rebal_sales_header = NO;

	asset_detail_rpt_sub_port_class_tgt_summary(t);

	asset_detail_rpt_individual_sale(t, HEADER);
	}

if (rebal_freq_local == MONTHLY
	|| (rebal_freq_local == AT_ASSET_FREQUENCY
		&& asset->mkt_val_calc_freq == MONTHLY))
	turnover_rate_freq = 12;

else if (rebal_freq_local == QUARTERLY
		 || (rebal_freq_local == AT_ASSET_FREQUENCY
			 && asset->mkt_val_calc_freq == QUARTERLY_MAR_JUN_SEP_DEC_))
	turnover_rate_freq = 4;

else if (rebal_freq_local == SEMIANNUALLY
		 || (rebal_freq_local == AT_ASSET_FREQUENCY
			 && asset->mkt_val_calc_freq == SEMIANNUALLY_JUN_DEC_))
	turnover_rate_freq = 2;
else
	turnover_rate_freq = 1;

if ((cal_yr_relative(t) > yrs_to_inv_mthly_local) 
	&& (cal_yr_relative(t) <= (yrs_to_inv_mthly_local + yrs_to_inv_qtrly_local))
	&& turnover_rate_freq == 12)
	turnover_rate_freq = 4;

if (cal_yr_relative(t) > (yrs_to_inv_mthly_local + yrs_to_inv_qtrly_local))
	turnover_rate_freq = 1;

for (int fund_index = 0; fund_index < MAXIMUM_NUMBER_OF_ASSET_FUNDS; fund_index++)
	asset_fund_to_sell_flag[fund_index] = 0;

asset_fund_to_sell_flag[INVESTMENT_FUND_INDEX] = 1;

net_cash_from_sales
+= rebal_inv_assets_sale(t,
                         sell_assets,
                         turnover_rate_freq);

return net_cash_from_sales;
}



#line 1 "sell_assets_control.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::sell_assets_control(int t, StrEnum::EnumValue sell_assets, StrEnum::EnumValue sales_type, StrEnum::EnumValue selection_defn, double required_amount)
{
int cal_mth = xint(this->cal_mth(t));
double marginal_distribn_rate = 0.0;
double capital_gains_cash_factor_for_sales = 1.0;
double net_cash_from_sales = 0.0;

if (!pba_valn_flag)
	{
	if (seg_element->corp_seg_flag
		|| (!tcm_flag && seg_element->business_seg_flag))
		{
		if (!imr_flag && !avr_flag)
			marginal_distribn_rate = company->distribn_pct_distrib_earnings;
	   
		if (company->prof_distribn_mode == MONTHLY || company->last_period_indicator(t)
			|| (company->prof_distribn_mode == QUARTERLY && cal_mth % 3 == 0) 
			|| (company->prof_distribn_mode == ANNUAL && cal_mth == 12))
			capital_gains_cash_factor_for_sales	= 1.0 - marginal_distribn_rate;
		}
	}
	
if (sales_type == PLANNED_SALES_OR_MINIMUM_SIZE_ASSETS)
	net_cash_from_sales
	= sell_assets_planned_and_min_size(t,
			capital_gains_cash_factor_for_sales);
else if (sales_type == REBALANCING_SALES
		 || sales_type == NEGATIVE_CASH_FLOW_SALES)
	{
	if (selection_defn == PRO_RATA)
		net_cash_from_sales
		= sell_assets_pro_rata(t, sell_assets,
		                       sales_type,
		                       required_amount,
		                       capital_gains_cash_factor_for_sales);
	
	else if (selection_defn == MAXIMIZE_CAPITAL_GAIN
			 || selection_defn == LONGEST_DURATION
			 || selection_defn == SHORTEST_DURATION)
		net_cash_from_sales
		= sell_assets_extreme_value(t, sell_assets,
		                            sales_type,
		                            selection_defn,
		                            required_amount,
		                            capital_gains_cash_factor_for_sales);
	else
		throw FatalError("Unrecognized asset sales selection option in sell_assets_control.");
	}
else
	throw FatalError("Unrecognized sales type option in sell_assets_control.");

return net_cash_from_sales;
}



#line 1 "sell_assets_extreme_value.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::sell_assets_extreme_value(int t, StrEnum::EnumValue sell_assets, StrEnum::EnumValue sales_type, StrEnum::EnumValue extreme_selection, double cash_required, double capital_gains_cash_factor_for_sales)
{
multimap <pair<double,double>, pair<int,int>, less<pair<double,double> > >::iterator evmmap_iter;
int selected_asset_defn = 0;
int mp = 0;
int selected_mp = 0;
int sub_port_num = 0;
int sales_class_num = 0;
int asset_fund_index = 0;
int col_num = 0;
double remaining_cash_required = 0.0;
double book_value_available = 0.0;
double accrued_interest_available = 0.0;
double accrued_rent_available = 0.0;
double market_value_available = 0.0;
double unrealized_capital_gains_available = 0.0;
double pct_to_sell_prelim = 0.0;
double estimated_net_cash_from_sale = 0.0;
double net_cash_from_asset_sale = 0.0;
double net_cash_from_sales = 0.0;
double percent_of_asset_to_sell = 0.0;
double book_sold = 0.0;
double accrued_sold = 0.0;
double market_sold = 0.0;
double capital_gain = 0.0;
double unrealized_capital_gain_released = 0.0;
double local_pct_to_use = 0.0;
bool is_rebal_sales = (sales_type == REBALANCING_SALES);

pair<int,int> next_extreme_asset;

remaining_cash_required = cash_required;

create_extreme_val_multimap(t, sales_type, extreme_selection);

while (remaining_cash_required > model_point_amount_threshold)
	{
	if (extreme_value_multimap.size() == 0)
		return net_cash_from_sales;

	evmmap_iter = extreme_value_multimap.begin();
	next_extreme_asset = evmmap_iter->second;
	extreme_value_multimap.erase(evmmap_iter);

	selected_asset_defn = next_extreme_asset.first;
	selected_mp = next_extreme_asset.second;

#if defined(__BOND_ASSET_H_)
	if (selected_asset_defn == BOND_CODE)
		{
		mp = selected_mp;
		sub_port_num = xint(asset->sm_bond[mp][0]->sub_port_id(t));
		sales_class_num = asset->sm_bond[mp][0]->sale_class_id; 
		asset_fund_index = asset->sm_bond[mp][0]->asset_fund_index; 
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_bond[mp][0]->pct_to_use;

		if (is_rebal_sales)
			{
			book_value_available
			= asset->sm_bond[mp][0]->bk_val_bef_rebal_sale(t);
			accrued_interest_available
			= asset->sm_bond[mp][0]->accr_int_bef_rebal_sale(t);
			market_value_available
			= asset->sm_bond[mp][0]->mkt_val_bef_rebal_sale(t);
			unrealized_capital_gains_available
			= asset->sm_bond[mp][0]->unrealzd_cap_gain_bef_rebal_sale(t);
			}
		else
			{
			book_value_available
			= asset->sm_bond[mp][0]->bk_val_bef_neg_cash_flow_sale(t);
			accrued_interest_available
			= asset->sm_bond[mp][0]->accr_int_bef_neg_cash_flow_sale(t);
			market_value_available
			= asset->sm_bond[mp][0]->mkt_val_bef_neg_cash_flow_sale(t);
			unrealized_capital_gains_available
			= asset->sm_bond[mp][0]->unrealzd_cap_gain_bef_neg_cash_flow_sale(t);
			}

		if (sales_type == REBALANCING_SALES)
			estimated_net_cash_from_sale
			= (book_value_available + accrued_interest_available)
			  * local_pct_to_use;
		else
			estimated_net_cash_from_sale
			= expected_sale_cash(book_value_available,
								 accrued_interest_available,
								 market_value_available,
								 unrealized_capital_gains_available,
								 capital_gains_cash_factor_for_sales)
			  * local_pct_to_use;

		if (estimated_net_cash_from_sale <= remaining_cash_required)
			pct_to_sell_prelim = 1.0;
		else if (estimated_net_cash_from_sale > remaining_cash_required)
			pct_to_sell_prelim
			= remaining_cash_required / estimated_net_cash_from_sale;

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;  

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     accrued_interest_available,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		net_cash_from_sales
		+= net_cash_from_asset_sale;
		
		if (sales_type == REBALANCING_SALES)
			remaining_cash_required
			-= estimated_net_cash_from_sale
			   * percent_of_asset_to_sell;
		else	
			remaining_cash_required
			-= net_cash_from_asset_sale;

		book_sold
		= book_value_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		accrued_sold
		= accrued_interest_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;
	
		if (sell_assets == YES)
			{		
			if (is_rebal_sales)
				{
				asset->sm_bond[mp][0]->sold_pct_rebal_value = percent_of_asset_to_sell;
				asset->sm_bond[mp][0]->sold_pct_rebal(t);
				asset->sm_bond[mp][0]->sold_pct_rebal_value = 0.0;
				}
			else
				{
				asset->sm_bond[mp][0]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
				asset->sm_bond[mp][0]->sold_pct_neg_cash_flow(t);
				asset->sm_bond[mp][0]->sold_pct_neg_cash_flow_value = 0.0;
				}

			market_sold
			= market_value_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			unrealized_capital_gain_released
			= unrealized_capital_gains_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, accrued_sold,
					market_sold, unrealized_capital_gain_released);
			}
		else
			{
			expected_sold_at_bk
			+= book_sold + accrued_sold;

			sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
			+= book_sold + accrued_sold;

			if (asset->sm_bond[mp][0]->neg_asset_flag > 0)
				{
				expected_mkt_val_for_dur_sale
				+= asset->sm_bond[mp][0]->mkt_val_for_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;

				expected_mkt_val_times_dur_sale
				+= asset->sm_bond[mp][0]->mkt_val_times_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;
				}
			}

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_bond[mp][0]->sequence_id,
					asset->sm_bond[mp][0]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, accrued_sold,
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					asset->sm_bond[mp][0]->dur_val(t));
			}
		} // endif selected_asset_defn == BOND_CODE

	else 
#endif
#if defined(__MTG_ASSET_H_)
	if (selected_asset_defn == MORTGAGE_CODE)
		{
		mp = selected_mp;
		sub_port_num = xint(asset->sm_mtg[mp][0]->sub_port_id(t));
		sales_class_num = asset->sm_mtg[mp][0]->sale_class_id; 
		asset_fund_index = asset->sm_mtg[mp][0]->asset_fund_index; 
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_mtg[mp][0]->pct_to_use;

		if (is_rebal_sales)
			{
			book_value_available
			= asset->sm_mtg[mp][0]->bk_val_bef_rebal_sale(t);
			accrued_interest_available
			= asset->sm_mtg[mp][0]->accr_int_bef_rebal_sale(t);
			market_value_available
			= asset->sm_mtg[mp][0]->mkt_val_bef_rebal_sale(t);
			unrealized_capital_gains_available
			= asset->sm_mtg[mp][0]->unrealzd_cap_gain_bef_rebal_sale(t);
			}
		else	
			{
			book_value_available
			= asset->sm_mtg[mp][0]->bk_val_bef_neg_cash_flow_sale(t);
			accrued_interest_available
			= asset->sm_mtg[mp][0]->accr_int_bef_neg_cash_flow_sale(t);
			market_value_available
			= asset->sm_mtg[mp][0]->mkt_val_bef_neg_cash_flow_sale(t);
			unrealized_capital_gains_available
			= asset->sm_mtg[mp][0]->unrealzd_cap_gain_bef_neg_cash_flow_sale(t);
			}

		if (sales_type == REBALANCING_SALES)
			estimated_net_cash_from_sale
			= (book_value_available + accrued_interest_available)
			  * local_pct_to_use;
		else
			estimated_net_cash_from_sale
			= expected_sale_cash(book_value_available,
									accrued_interest_available,
									market_value_available,
									unrealized_capital_gains_available,
									capital_gains_cash_factor_for_sales)
				* local_pct_to_use;

		if (estimated_net_cash_from_sale <= remaining_cash_required)
			pct_to_sell_prelim = 1.0;
		else if (estimated_net_cash_from_sale > remaining_cash_required)
			pct_to_sell_prelim
			= remaining_cash_required / estimated_net_cash_from_sale;

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;  

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     accrued_interest_available,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		net_cash_from_sales
		+= net_cash_from_asset_sale;
		
		if (sales_type == REBALANCING_SALES)
			remaining_cash_required
			-= estimated_net_cash_from_sale
			   * percent_of_asset_to_sell;
		else	
			remaining_cash_required
			-= net_cash_from_asset_sale;

		book_sold = book_value_available
				    * local_pct_to_use
				    * percent_of_asset_to_sell;

		accrued_sold = accrued_interest_available
					   * local_pct_to_use
					   * percent_of_asset_to_sell;

		if (sell_assets == YES)
			{
			if (is_rebal_sales)
				{
				asset->sm_mtg[mp][0]->sold_pct_rebal_value = percent_of_asset_to_sell;
				asset->sm_mtg[mp][0]->sold_pct_rebal(t);
				asset->sm_mtg[mp][0]->sold_pct_rebal_value = 0.0;
				}
			else
				{
				asset->sm_mtg[mp][0]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
				asset->sm_mtg[mp][0]->sold_pct_neg_cash_flow(t);
				asset->sm_mtg[mp][0]->sold_pct_neg_cash_flow_value = 0.0;
				}

			market_sold = market_value_available
						  * local_pct_to_use
						  * percent_of_asset_to_sell;

			unrealized_capital_gain_released = unrealized_capital_gains_available
											   * local_pct_to_use
											   * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, accrued_sold,
					market_sold, unrealized_capital_gain_released);
			}
		else
			{
			expected_sold_at_bk
			+= book_sold + accrued_sold;

			sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
			+= book_sold + accrued_sold;

			if (asset->sm_mtg[mp][0]->neg_asset_flag > 0)
				{
				expected_mkt_val_for_dur_sale
				+= asset->sm_mtg[mp][0]->mkt_val_for_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;

				expected_mkt_val_times_dur_sale
				+= asset->sm_mtg[mp][0]->mkt_val_times_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;
				}
			}

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold 
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_mtg[mp][0]->sequence_id,
					asset->sm_mtg[mp][0]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, accrued_sold,
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					asset->sm_mtg[mp][0]->dur_val(t));
			}
		}

	else 
#endif
#if defined(__SEC_ASSET_H_)
	if (selected_asset_defn == SEC_CODE)
		{
		mp = selected_mp;
		sub_port_num = xint(asset->sm_sec[mp]->sub_port_id(t));
		sales_class_num = asset->sm_sec[mp]->sale_class_id; 
		asset_fund_index = asset->sm_sec[mp]->asset_fund_index; 
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_sec[mp]->pct_to_use;

		if (is_rebal_sales)
			{
			book_value_available
			= asset->sm_sec[mp]->bk_val_bef_rebal_sale(t);
			accrued_interest_available
			= asset->sm_sec[mp]->accr_int_bef_rebal_sale(t);
			market_value_available
			= asset->sm_sec[mp]->mkt_val_bef_rebal_sale(t);
			unrealized_capital_gains_available
			= asset->sm_sec[mp]->unrealzd_cap_gain_bef_rebal_sale(t);
			}
		else
			{
			book_value_available
			= asset->sm_sec[mp]->bk_val_bef_neg_cash_flow_sale(t);
			accrued_interest_available
			= asset->sm_sec[mp]->accr_int_bef_neg_cash_flow_sale(t);
			market_value_available
			= asset->sm_sec[mp]->mkt_val_bef_neg_cash_flow_sale(t);
			unrealized_capital_gains_available
			= asset->sm_sec[mp]->unrealzd_cap_gain_bef_neg_cash_flow_sale(t);
			}

		if (sales_type == REBALANCING_SALES)
			estimated_net_cash_from_sale
			= (book_value_available + accrued_interest_available)
			  * local_pct_to_use;
		else
			estimated_net_cash_from_sale
			= expected_sale_cash(book_value_available,
			                     accrued_interest_available,
			                     market_value_available,
			                     unrealized_capital_gains_available,
			                     capital_gains_cash_factor_for_sales)
			  * local_pct_to_use;

		if (estimated_net_cash_from_sale <= remaining_cash_required)
			pct_to_sell_prelim = 1.0;
		else if (estimated_net_cash_from_sale > remaining_cash_required)
			pct_to_sell_prelim
			= remaining_cash_required / estimated_net_cash_from_sale;

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;  

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     accrued_interest_available,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		if (sales_type == REBALANCING_SALES)
			remaining_cash_required
			-= estimated_net_cash_from_sale
			   * percent_of_asset_to_sell;
		else	
			remaining_cash_required
			-= net_cash_from_asset_sale;

		book_sold = book_value_available
				    * local_pct_to_use
				    * percent_of_asset_to_sell;

		accrued_sold = accrued_interest_available
					   * local_pct_to_use
					   * percent_of_asset_to_sell;

		if (sell_assets == YES)
			{
			if (is_rebal_sales)
				{
				asset->sm_sec[mp]->sold_pct_rebal_value = percent_of_asset_to_sell;
				asset->sm_sec[mp]->sold_pct_rebal(t);
				asset->sm_sec[mp]->sold_pct_rebal_value = 0.0;
				}
			else
				{
				asset->sm_sec[mp]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
				asset->sm_sec[mp]->sold_pct_neg_cash_flow(t);
				asset->sm_sec[mp]->sold_pct_neg_cash_flow_value = 0.0;
				}

			market_sold = market_value_available
						  * local_pct_to_use
						  * percent_of_asset_to_sell;

			unrealized_capital_gain_released = unrealized_capital_gains_available
											   * local_pct_to_use
											   * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, accrued_sold,
					market_sold, unrealized_capital_gain_released);
			}
		else
			{
			expected_sold_at_bk
			+= book_sold + accrued_sold;

			sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
			+= book_sold + accrued_sold;

			if (asset->sm_sec[mp]->neg_asset_flag > 0)
				{
				expected_mkt_val_for_dur_sale
				+= asset->sm_sec[mp]->mkt_val_for_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;

				expected_mkt_val_times_dur_sale
				+= asset->sm_sec[mp]->mkt_val_times_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;
				}
			}
		
		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_sec[mp]->sequence_id,
					asset->sm_sec[mp]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, accrued_sold,
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					asset->sm_sec[mp]->dur_val(t));
			}
		}

	else 
#endif
#if defined(__IRD_ASSET_H_)
	if (selected_asset_defn == IRD_CODE)
		{
		mp = selected_mp;
		sales_class_num = asset->sm_ird[mp][0]->sale_class_id; 
		asset_fund_index = asset->sm_ird[mp][0]->asset_fund_index; 
		sub_port_num = xint(asset->sm_ird[mp][0]->sub_port_id(t));
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_ird[mp][0]->pct_to_use;

		if (is_rebal_sales)
			{
			book_value_available
			= asset->sm_ird[mp][0]->bk_val_bef_rebal_sale(t);
			accrued_interest_available
			= asset->sm_ird[mp][0]->accr_int_bef_rebal_sale(t);
			market_value_available
			= asset->sm_ird[mp][0]->mkt_val_bef_rebal_sale(t);
			unrealized_capital_gains_available
			= asset->sm_ird[mp][0]->unrealzd_cap_gain_bef_rebal_sale(t);
			}
		else
			{
			book_value_available
			= asset->sm_ird[mp][0]->bk_val_bef_neg_cash_flow_sale(t);
			accrued_interest_available
			= asset->sm_ird[mp][0]->accr_int_bef_neg_cash_flow_sale(t);
			market_value_available
			= asset->sm_ird[mp][0]->mkt_val_bef_neg_cash_flow_sale(t);
			unrealized_capital_gains_available
			= asset->sm_ird[mp][0]->unrealzd_cap_gain_bef_neg_cash_flow_sale(t);
			}

		if (sales_type == REBALANCING_SALES)
			estimated_net_cash_from_sale
			= (book_value_available + accrued_interest_available)
			  * local_pct_to_use;
		else
			estimated_net_cash_from_sale
			= expected_sale_cash(book_value_available,
								 accrued_interest_available,
								 market_value_available,
								 unrealized_capital_gains_available,
								 capital_gains_cash_factor_for_sales)
			  * local_pct_to_use;

		if (estimated_net_cash_from_sale <= remaining_cash_required)
			pct_to_sell_prelim = 1.0;
		else if (estimated_net_cash_from_sale > remaining_cash_required)
			pct_to_sell_prelim
			= remaining_cash_required / estimated_net_cash_from_sale;

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;  

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     accrued_interest_available,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		if (sales_type == REBALANCING_SALES)
			remaining_cash_required
			-= estimated_net_cash_from_sale
			   * percent_of_asset_to_sell;
		else	
			remaining_cash_required
			-= net_cash_from_asset_sale;

		book_sold = book_value_available
				    * local_pct_to_use
				    * percent_of_asset_to_sell;

		accrued_sold = accrued_interest_available
					   * local_pct_to_use
					   * percent_of_asset_to_sell;

		if (sell_assets == YES)
			{
			if (is_rebal_sales)
				{
				asset->sm_ird[mp][0]->sold_pct_rebal_value = percent_of_asset_to_sell;
				asset->sm_ird[mp][0]->sold_pct_rebal(t);
				asset->sm_ird[mp][0]->sold_pct_rebal_value = 0.0;
				}
			else
				{
				asset->sm_ird[mp][0]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
				asset->sm_ird[mp][0]->sold_pct_neg_cash_flow(t);
				asset->sm_ird[mp][0]->sold_pct_neg_cash_flow_value = 0.0;
				}

			market_sold
			= market_value_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			unrealized_capital_gain_released
			= unrealized_capital_gains_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, accrued_sold,
					market_sold, unrealized_capital_gain_released);
			}
		else
			{
			expected_sold_at_bk
			+= book_sold + accrued_sold;

			sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
			+= book_sold + accrued_sold;

			if (asset->sm_ird[mp][0]->neg_asset_flag > 0)
				{
				expected_mkt_val_for_dur_sale
				+= asset->sm_ird[mp][0]->mkt_val_for_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;

				expected_mkt_val_times_dur_sale
				+= asset->sm_ird[mp][0]->mkt_val_times_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;
				}
			}

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_ird[mp][0]->sequence_id,
					asset->sm_ird[mp][0]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, accrued_sold,
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					asset->sm_ird[mp][0]->dur_val(t));
			}
		}

	else 
#endif
#if defined(__RE_ASSET_H_)
	if (selected_asset_defn == REAL_ESTATE_CODE)
		{
		mp = selected_mp;
		sub_port_num = xint(asset->sm_re[mp]->sub_port_id(t));
		sales_class_num = asset->sm_re[mp]->sale_class_id; 
		asset_fund_index = asset->sm_re[mp]->asset_fund_index; 
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_re[mp]->pct_to_use;

		if (is_rebal_sales)
			{
			book_value_available
			= asset->sm_re[mp]->bk_val_bef_rebal_sale(t);
			accrued_rent_available
			= asset->sm_re[mp]->accr_rent_bef_rebal_sale(t);
			market_value_available
			= asset->sm_re[mp]->mkt_val_bef_rebal_sale(t);
			unrealized_capital_gains_available
			= asset->sm_re[mp]->unrealzd_cap_gain_bef_rebal_sale(t);
			}
		else
			{
			book_value_available
			= asset->sm_re[mp]->bk_val_bef_neg_cash_flow_sale(t);
			accrued_rent_available
			= asset->sm_re[mp]->accr_rent_bef_rebal_sale(t);
			market_value_available
			= asset->sm_re[mp]->mkt_val_bef_neg_cash_flow_sale(t);
			unrealized_capital_gains_available
			= asset->sm_re[mp]->unrealzd_cap_gain_bef_neg_cash_flow_sale(t);
			}

		if (sales_type == REBALANCING_SALES)
			estimated_net_cash_from_sale
			= (book_value_available + accrued_rent_available)
			  * local_pct_to_use;
		else
			estimated_net_cash_from_sale
			= expected_sale_cash(book_value_available,
								 accrued_rent_available,
								 market_value_available,
								 unrealized_capital_gains_available,
								 capital_gains_cash_factor_for_sales)
			  * local_pct_to_use;

		if (estimated_net_cash_from_sale <= remaining_cash_required)
			pct_to_sell_prelim = 1.0;
		else if (estimated_net_cash_from_sale > remaining_cash_required)
			pct_to_sell_prelim
			= remaining_cash_required / estimated_net_cash_from_sale;

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;  

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     accrued_rent_available,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		book_sold
		= book_value_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		accrued_sold
		= accrued_rent_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		expected_sold_at_bk
		+= book_sold + accrued_sold;

		sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
		+= book_sold + accrued_sold;

		if (sell_assets == YES)
			{
			if (is_rebal_sales)
				{
				asset->sm_re[mp]->sold_pct_rebal_value = percent_of_asset_to_sell;
				asset->sm_re[mp]->sold_pct_rebal(t);
				asset->sm_re[mp]->sold_pct_rebal_value = 0.0;
				}
			else
				{
				asset->sm_re[mp]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
				asset->sm_re[mp]->sold_pct_neg_cash_flow(t);
				asset->sm_re[mp]->sold_pct_neg_cash_flow_value = 0.0;
				}

			market_sold
			= market_value_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			unrealized_capital_gain_released
			= unrealized_capital_gains_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, accrued_sold,
					market_sold, unrealized_capital_gain_released);
			}

		if (sales_type == REBALANCING_SALES)
			remaining_cash_required
			-= estimated_net_cash_from_sale
			   * percent_of_asset_to_sell;
		else	
			remaining_cash_required
			-= net_cash_from_asset_sale;

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_re[mp]->sequence_id,
					asset->sm_re[mp]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, accrued_sold,
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					0);
			}

		} // endif selected_asset_defn == REAL_ESTATE_CODE

	else 
#endif
#if defined(__EQT_ASSET_H_)
	if (selected_asset_defn == EQUITY_CODE)
		{
		mp = selected_mp;
		sub_port_num = xint(asset->sm_eqt[mp]->sub_port_id(t));
		sales_class_num = asset->sm_eqt[mp]->sale_class_id; 
		asset_fund_index = asset->sm_eqt[mp]->asset_fund_index; 
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_eqt[mp]->pct_to_use;

		if (is_rebal_sales)
			{
			book_value_available
			= asset->sm_eqt[mp]->bk_val_bef_rebal_sale(t);
			market_value_available
			= asset->sm_eqt[mp]->mkt_val_bef_rebal_sale(t);
			unrealized_capital_gains_available
			= asset->sm_eqt[mp]->unrealzd_cap_gain_bef_rebal_sale(t);
			}
		else
			{
			book_value_available
			= asset->sm_eqt[mp]->bk_val_bef_neg_cash_flow_sale(t);
			market_value_available
			= asset->sm_eqt[mp]->mkt_val_bef_neg_cash_flow_sale(t);
			unrealized_capital_gains_available
			= asset->sm_eqt[mp]->unrealzd_cap_gain_bef_neg_cash_flow_sale(t);
			}

		if (sales_type == REBALANCING_SALES)
			estimated_net_cash_from_sale
			= book_value_available
			  * local_pct_to_use;
		else
			estimated_net_cash_from_sale
			= expected_sale_cash(book_value_available,
								 0.0,
								 market_value_available,
								 unrealized_capital_gains_available,
								 capital_gains_cash_factor_for_sales)
			  * local_pct_to_use;

		if (estimated_net_cash_from_sale <= remaining_cash_required)
			pct_to_sell_prelim = 1.0;
		else if (estimated_net_cash_from_sale > remaining_cash_required)
			pct_to_sell_prelim
			= remaining_cash_required / estimated_net_cash_from_sale;

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;  

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     0.0,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell; 

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		if (sales_type == REBALANCING_SALES)
			remaining_cash_required
			-= estimated_net_cash_from_sale
			   * percent_of_asset_to_sell;
		else	
			remaining_cash_required
			-= net_cash_from_asset_sale;

		book_sold
		= book_value_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		if (sell_assets == YES)
			{
			if (is_rebal_sales)
				{
				asset->sm_eqt[mp]->sold_pct_rebal_value = percent_of_asset_to_sell;
				asset->sm_eqt[mp]->sold_pct_rebal(t);
				asset->sm_eqt[mp]->sold_pct_rebal_value = 0.0;
				}
			else
				{
				asset->sm_eqt[mp]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
				asset->sm_eqt[mp]->sold_pct_neg_cash_flow(t);
				asset->sm_eqt[mp]->sold_pct_neg_cash_flow_value = 0.0;
				}

			market_sold
			= market_value_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;
	
			unrealized_capital_gain_released
			= unrealized_capital_gains_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;
	
			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, 0.0, // accrued_sold
					market_sold, unrealized_capital_gain_released);
			}
		else
			{
			expected_sold_at_bk
			+= book_sold;

			sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
			+= book_sold;
			}

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_eqt[mp]->sequence_id,
					asset->sm_eqt[mp]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, 0.0, // accrued_sold
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					0);
			}

		} // endif selected_asset_defn == EQUITY_CODE
	else 
#endif
#if defined(__EIO_ASSET_H_)
	if (selected_asset_defn == INDEX_OPTION_CODE)
		{
		mp = selected_mp;
		sub_port_num = xint(asset->sm_eio[mp][0]->sub_port_id(t));
		sales_class_num = asset->sm_eio[mp][0]->sale_class_id; 
		asset_fund_index = asset->sm_eio[mp][0]->asset_fund_index; 
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_eio[mp][0]->pct_to_use;

		if (is_rebal_sales)
			{
			book_value_available
			= asset->sm_eio[mp][0]->bk_val_bef_rebal_sale(t);
			market_value_available
			= asset->sm_eio[mp][0]->mkt_val_bef_rebal_sale(t);
			unrealized_capital_gains_available
				= asset->sm_eio[mp][0]->unrealzd_cap_gain_bef_rebal_sale(t);
			}
		else	
			{
			book_value_available
			= asset->sm_eio[mp][0]->bk_val_bef_neg_cash_flow_sale(t);
			market_value_available
			= asset->sm_eio[mp][0]->mkt_val_bef_neg_cash_flow_sale(t);
			unrealized_capital_gains_available
			= asset->sm_eio[mp][0]->unrealzd_cap_gain_bef_neg_cash_flow_sale(t);
			}

		if (sales_type == REBALANCING_SALES)
			estimated_net_cash_from_sale
			= book_value_available
			  * local_pct_to_use;
		else
			estimated_net_cash_from_sale
			= expected_sale_cash(book_value_available,
								 0.0,
								 market_value_available,
								 unrealized_capital_gains_available,
								 capital_gains_cash_factor_for_sales)
			  * local_pct_to_use;

		if (estimated_net_cash_from_sale <= remaining_cash_required)
			pct_to_sell_prelim = 1.0;
		else if (estimated_net_cash_from_sale > remaining_cash_required)
			pct_to_sell_prelim
			= remaining_cash_required / estimated_net_cash_from_sale;

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;  

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     0.0,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		book_sold
		= book_value_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		expected_sold_at_bk
		+= book_sold;

		sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
		+= book_sold;

		if (sell_assets == YES)
			{
			if (is_rebal_sales)
				{
				asset->sm_eio[mp][0]->sold_pct_rebal_value = percent_of_asset_to_sell;
				asset->sm_eio[mp][0]->sold_pct_rebal(t);
				asset->sm_eio[mp][0]->sold_pct_rebal_value = 0.0;
				}
			else
				{
				asset->sm_eio[mp][0]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
				asset->sm_eio[mp][0]->sold_pct_neg_cash_flow(t);
				asset->sm_eio[mp][0]->sold_pct_neg_cash_flow_value = 0.0;
				}

			market_sold
			= market_value_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			unrealized_capital_gain_released
			= unrealized_capital_gains_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, 0.0, // accrued_sold
					market_sold, unrealized_capital_gain_released);
			}
		
		if (sales_type == REBALANCING_SALES)
			remaining_cash_required
			-= estimated_net_cash_from_sale
			   * percent_of_asset_to_sell;
		else	
			remaining_cash_required
			-= net_cash_from_asset_sale;

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_eio[mp][0]->sequence_id,
					asset->sm_eio[mp][0]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, 0.0, // accrued_sold
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					asset->sm_eio[mp][0]->dur_val(t));
			}
		}

	else 
#endif
#if defined(__EPA_ASSET_H_)
	if (selected_asset_defn == EPA_CODE)
		{
		mp = selected_mp;
		sub_port_num = xint(asset->sm_epa[mp]->sub_port_id(t));
		sales_class_num = asset->sm_epa[mp]->sale_class_id; 
		asset_fund_index = asset->sm_epa[mp]->asset_fund_index; 
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_epa[mp]->pct_to_use;

		if (is_rebal_sales)
			{
			book_value_available
			= asset->sm_epa[mp]->bk_val_bef_rebal_sale(t);
			accrued_interest_available
			= asset->sm_epa[mp]->accr_int_bef_rebal_sale(t);
			market_value_available
			= asset->sm_epa[mp]->mkt_val_bef_rebal_sale(t);
			unrealized_capital_gains_available
				= asset->sm_epa[mp]->unrealzd_cap_gain_bef_rebal_sale(t);
			}
		else	
			{
			book_value_available
			= asset->sm_epa[mp]->bk_val_bef_neg_cash_flow_sale(t);
			accrued_interest_available
			= asset->sm_epa[mp]->accr_int_bef_neg_cash_flow_sale(t);
			market_value_available
			= asset->sm_epa[mp]->mkt_val_bef_neg_cash_flow_sale(t);
			unrealized_capital_gains_available
			= asset->sm_epa[mp]->unrealzd_cap_gain_bef_neg_cash_flow_sale(t);
			}

		if (sales_type == REBALANCING_SALES)
			estimated_net_cash_from_sale
			= (book_value_available + accrued_interest_available)
			  * local_pct_to_use;
		else
			estimated_net_cash_from_sale
			= expected_sale_cash(book_value_available,
								 accrued_interest_available,
								 market_value_available,
								 unrealized_capital_gains_available,
								 capital_gains_cash_factor_for_sales)
			  * local_pct_to_use;

		if (estimated_net_cash_from_sale <= remaining_cash_required)
			pct_to_sell_prelim = 1.0;
		else if (estimated_net_cash_from_sale > remaining_cash_required)
			pct_to_sell_prelim
			= remaining_cash_required / estimated_net_cash_from_sale;

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;  

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     accrued_interest_available,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		if (sales_type == REBALANCING_SALES)
			remaining_cash_required
			-= estimated_net_cash_from_sale
			   * percent_of_asset_to_sell;
		else	
			remaining_cash_required
			-= net_cash_from_asset_sale;

		book_sold
		= book_value_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		accrued_sold
		= accrued_interest_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		if (sell_assets == YES)
			{
			if (is_rebal_sales)
				{
				asset->sm_epa[mp]->sold_pct_rebal_value = percent_of_asset_to_sell;
				asset->sm_epa[mp]->sold_pct_rebal(t);
				asset->sm_epa[mp]->sold_pct_rebal_value = 0.0;
				}
			else
				{
				asset->sm_epa[mp]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
				asset->sm_epa[mp]->sold_pct_neg_cash_flow(t);
				asset->sm_epa[mp]->sold_pct_neg_cash_flow_value = 0.0;
				}

			market_sold
			= market_value_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			unrealized_capital_gain_released
			= unrealized_capital_gains_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, accrued_sold,
					market_sold, unrealized_capital_gain_released);
			}
		else
			{
			expected_sold_at_bk
			+= book_sold + accrued_sold;

			sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
			+= book_sold + accrued_sold;

			if (asset->sm_epa[mp]->neg_asset_flag > 0)
				{
				expected_mkt_val_for_dur_sale
				+= asset->sm_epa[mp]->mkt_val_for_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;

				expected_mkt_val_times_dur_sale
				+= asset->sm_epa[mp]->mkt_val_times_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;
				}
			}

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_epa[mp]->sequence_id,
					asset->sm_epa[mp]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, accrued_sold,
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					asset->sm_epa[mp]->dur_val(t));
			}
		}

	else 
#endif
		throw FatalError("Attempting to sell an unrecognized asset type"); 
	} // end_while remaining_cash_required > 0.0

return net_cash_from_sales;
}



#line 1 "sell_assets_extreme_value_tiebreaker.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::sell_assets_extreme_value_tiebreaker(double mkt_to_bk_ratio, double unrealzd_cap_gain_to_bk_ratio, double notional_amount)
{
if (fabs(mkt_to_bk_ratio) > rate_ratio_threshold)
	return mkt_to_bk_ratio;

if (fabs(unrealzd_cap_gain_to_bk_ratio) > rate_ratio_threshold)
	return unrealzd_cap_gain_to_bk_ratio;

return notional_amount;
}



#line 1 "sell_assets_hedges.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::sell_assets_hedges(int t, map <int, long, less <int> > &eio_mp_map_active, double hedge_notional_amt, double liab_notional_amt, xstring hedge_grp_code)
{
int cal_yr = xint(this->cal_yr(t));
int cal_mth = xint(this->cal_mth(t));
int mp = 0;
int asset_fund_index = 0;
int sub_port_num = 0;
int sales_class_num = 0;
double asset_pct_to_sell = 0.0;
double asset_pct_remaining = 0.0;
double net_cash_from_asset_sale = 0.0;
double net_cash_from_sales = 0.0;
double asd_bv_sold = 0.0;
double asd_accrued_sold = 0.0;
double asd_mv_sold = 0.0;
double asd_cap_gain = 0.0;
double asd_ucg_released = 0.0;
double notional_sold = 0.0;

int col_num_notional_amount = 0;
int col_num_portion_of_asset_sold_planned_sales = 0;
int col_num_asset_sub_port_num = 0;
int col_num_bk_val_bef_sale = 0;
int col_num_mkt_val_bef_sale = 0;
int col_num_unrealzd_cap_gain_bef_sale = 0;
int col_num_notional_amt_bef_sale = 0;
int col_num_portion_of_asset_sold = 0;

double local_pct_to_use = 0.0;

// ensure planned sales have been processed
cash_flow_planned_sale(t);

if (fabs(hedge_notional_amt) < aggregate_amount_threshold)
	return 0.0;

if (asset->asset_detail_rpt_inv_strat_flag(t))
	{
	seg_element->SALFile << endl;
	seg_element->SALFile << "Hedge Sales"
			     << " Period=" << t
			     << " Year=" << cal_yr
			     << " Month=" << cal_mth
			     << endl;
	seg_element->SALFile << "Hedge Group," << hedge_grp_code
			<< endl;

	asset_detail_rpt_individual_sale(t, HEADER);
	}

asset_pct_to_sell = 1.0 - liab_notional_amt / hedge_notional_amt;

// calculate cap gain cash factor adjustment
double marginal_distribn_rate = 0.0; 
double distribn_of_earnings_freq = 0.0;
double cap_gains_cash_factor_for_sales = 1.0;

if (!pba_valn_flag)
	{
	if (seg_element->corp_seg_flag
		|| (!tcm_flag && seg_element->business_seg_flag))
		{
		if (!imr_flag && !avr_flag)
			marginal_distribn_rate = company->distribn_pct_distrib_earnings;
	   
		if (company->prof_distribn_mode == ANNUAL)
			distribn_of_earnings_freq = 1.0;
		else if (company->prof_distribn_mode == QUARTERLY)
			distribn_of_earnings_freq = 4.0;
		else if (company->prof_distribn_mode == MONTHLY)
			distribn_of_earnings_freq = 12.0;
	
		if (company->prof_distribn_mode == MONTHLY || company->last_period_indicator(t)
			|| (company->prof_distribn_mode == QUARTERLY && cal_mth % 3 == 0) 
			|| (company->prof_distribn_mode == ANNUAL && cal_mth == 12))
			cap_gains_cash_factor_for_sales	= 1.0 - marginal_distribn_rate;
		}
	}

map <int, long, less <int> >::iterator mp_map_iter;

#if defined(__EIO_ASSET_H_)
	// loop over index options
if (!eio_mp_map_active.empty())
	{
	col_num_notional_amount
	= asset->sm_eio[0][0]->Column("notional_amt").Number();
	col_num_portion_of_asset_sold_planned_sales
	= asset->sm_eio[0][0]->Column("sold_pct_planned").Number();
	col_num_asset_sub_port_num
	= asset->sm_eio[0][0]->Column("sub_port_id").Number();
	col_num_bk_val_bef_sale
	= asset->sm_eio[0][0]->Column("bk_val_bef_fund_match_sale").Number();
	col_num_mkt_val_bef_sale
	= asset->sm_eio[0][0]->Column("mkt_val_bef_fund_match_sale").Number();
	col_num_unrealzd_cap_gain_bef_sale
	= asset->sm_eio[0][0]->Column("unrealzd_cap_gain_bef_fund_match_sale").Number();
	col_num_notional_amt_bef_sale
	= asset->sm_eio[0][0]->Column("notional_amt_bef_fund_match_sale").Number();

	col_num_portion_of_asset_sold
	= asset->sm_eio[0][0]->Column("sold_pct_fund_match").Number();
	}

for (mp_map_iter = eio_mp_map_active.begin();
	 mp_map_iter != eio_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_eio[mp][0]->asset_fund_index != HEDGING_FUND_INDEX
		|| asset->sm_eio[mp][0]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	asset_pct_remaining
	= (1.0 - asset->sm_eio[mp][0]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));
	sub_port_num = xint(asset->sm_eio[mp][0]->Column(col_num_asset_sub_port_num).Value(t));
	sales_class_num = asset->sm_eio[mp][0]->sale_class_id;

	if (asset_pct_remaining < rate_ratio_threshold)
		continue;

	local_pct_to_use = asset->sm_eio[mp][0]->pct_to_use;

	// Adjust to use market value for book value and cost basis so we return the full market value as the cash from sale
	// Required because we assume that all hedge adjustment are through the hedge_cost calculations 
	net_cash_from_asset_sale
	= expected_sale_cash(asset->sm_eio[mp][0]->Column(col_num_mkt_val_bef_sale).Value(t),
	                     0.0,
	                     asset->sm_eio[mp][0]->Column(col_num_mkt_val_bef_sale).Value(t),
	                     0.0,
	                     cap_gains_cash_factor_for_sales)
	  * local_pct_to_use
	  * asset_pct_to_sell;

	net_cash_from_sales
	+= net_cash_from_asset_sale;

	asset->sm_eio[mp][0]->sold_pct_fund_match_value = asset_pct_to_sell;
	asset->sm_eio[mp][0]->Column(col_num_portion_of_asset_sold).Value(t);
	asset->sm_eio[mp][0]->sold_pct_fund_match_value = 0.0;

	notional_sold
	= asset->sm_eio[mp][0]->Column(col_num_notional_amt_bef_sale).Value(t)
	  * local_pct_to_use
	  * asset_pct_to_sell;

	if (asset->asset_detail_rpt_inv_strat_flag(t))
		{
		asd_bv_sold
		= asset->sm_eio[mp][0]->Column(col_num_bk_val_bef_sale).Value(t)
		  * local_pct_to_use
		  * asset_pct_to_sell;
		
		asd_accrued_sold = 0;
		
		asd_mv_sold
		= asset->sm_eio[mp][0]->Column(col_num_mkt_val_bef_sale).Value(t)
		  * local_pct_to_use
		  * asset_pct_to_sell;
		
		asd_cap_gain = asd_mv_sold - asd_bv_sold;
		
		asd_ucg_released
		= asset->sm_eio[mp][0]->Column(col_num_unrealzd_cap_gain_bef_sale).Value(t)
		  * local_pct_to_use
		  * asset_pct_to_sell;

		asset_detail_rpt_individual_sale(t, ASSET_DATA,
				asset->sm_eio[mp][0]->sequence_id,
				asset->sm_eio[mp][0]->asset_id,
				sub_port_num, 
				sales_class_num, 
				HEDGING_FUND_INDEX,
				asset_pct_to_sell,
				net_cash_from_asset_sale,
				asd_bv_sold, asd_accrued_sold,
				asd_mv_sold, asd_cap_gain,
				asd_ucg_released,
				asset->sm_eio[mp][0]->dur_val(t));
		}
	} // end_for over mp
#endif

return net_cash_from_sales;
}



#line 1 "sell_assets_planned_and_min_size.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::sell_assets_planned_and_min_size(int t, double capital_gains_cash_factor_for_sales)
{
int mp = 0;
double net_cash_from_asset_sale = 0.0;
double net_cash_from_sales = 0.0;
double asd_bv_sold = 0.0;
double asd_accrued_sold = 0.0;
double asd_mv_sold = 0.0;
double asd_cap_gain = 0.0;
double asd_ucg_released = 0.0;
map <int, long, less <int> >::iterator mp_map_iter;

#if defined(__BOND_ASSET_H_)
for (mp_map_iter = seg_element->bond_mp_map_active.begin();
	 mp_map_iter != seg_element->bond_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_bond[mp][0]->neg_asset_flag < 0)
		continue;
	
	if (asset->sm_bond[mp][0]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if (asset->sm_bond[mp][0]->commencement_period <= t
		&& (t == asset->sm_bond[mp][0]->planned_sale_period
			|| asset->sm_bond[mp][0]->asset_min_size_sale_flag(t) == 1))
		{
		net_cash_from_asset_sale
		= expected_sale_cash(asset->sm_bond[mp][0]->bk_val_bef_sale(t),
		                     asset->sm_bond[mp][0]->accr_int_bef_sale(t),
		                     asset->sm_bond[mp][0]->mkt_val_bef_sale(t),
		                     asset->sm_bond[mp][0]->unrealzd_cap_gain_bef_sale(t),
		                     capital_gains_cash_factor_for_sales)
		  * asset->sm_bond[mp][0]->pct_to_use;

		asset->sm_bond[mp][0]->sold_pct_planned_value = 1.0;
		asset->sm_bond[mp][0]->sold_pct_planned(t);
		asset->sm_bond[mp][0]->sold_pct_planned_value = 0.0;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			asd_bv_sold
			= asset->sm_bond[mp][0]->bk_val_bef_sale(t)
			  * asset->sm_bond[mp][0]->pct_to_use;
			
			asd_accrued_sold
			= asset->sm_bond[mp][0]->accr_int_bef_sale(t)
			  * asset->sm_bond[mp][0]->pct_to_use;
			
			asd_mv_sold
			= asset->sm_bond[mp][0]->mkt_val_bef_sale(t)
			  * asset->sm_bond[mp][0]->pct_to_use;
			
			asd_cap_gain = asd_mv_sold - asd_bv_sold;
			
			asd_ucg_released
			= asset->sm_bond[mp][0]->unrealzd_cap_gain_bef_sale(t)
			  * asset->sm_bond[mp][0]->pct_to_use;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_bond[mp][0]->sequence_id,
					asset->sm_bond[mp][0]->asset_id,
					asset->sm_bond[mp][0]->sub_port_id(t),
					asset->sm_bond[mp][0]->sale_class_id,
					asset->sm_bond[mp][0]->asset_fund_index,
					1.0,
					net_cash_from_asset_sale,
					asd_bv_sold,
					asd_accrued_sold,
					asd_mv_sold,
					asd_cap_gain,
					asd_ucg_released,
					asset->sm_bond[mp][0]->dur_val(t));
			}
		}
	}
#endif

#if defined(__MTG_ASSET_H_)
for (mp_map_iter = seg_element->mtg_mp_map_active.begin();
	 mp_map_iter != seg_element->mtg_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_mtg[mp][0]->neg_asset_flag < 0)
		continue;

	if ((t > asset->sm_mtg[mp][0]->commencement_period 
		// allow for inclusion of restructure, foreclosure, refinance assets
		&& asset->sm_mtg[mp][0]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD))
		continue;

	if (asset->sm_mtg[mp][0]->commencement_period <= t
		&& (t == asset->sm_mtg[mp][0]->planned_sale_period
			|| asset->sm_mtg[mp][0]->asset_min_size_sale_flag(t) == 1))
		{
		net_cash_from_asset_sale
		= expected_sale_cash(asset->sm_mtg[mp][0]->bk_val_bef_sale(t),
		                     asset->sm_mtg[mp][0]->accr_int_bef_sale(t),
		                     asset->sm_mtg[mp][0]->mkt_val_bef_sale(t),
		                     asset->sm_mtg[mp][0]->unrealzd_cap_gain_bef_sale(t),
		                     capital_gains_cash_factor_for_sales)
		  * asset->sm_mtg[mp][0]->pct_to_use;

		asset->sm_mtg[mp][0]->sold_pct_planned_value = 1.0;
		asset->sm_mtg[mp][0]->sold_pct_planned(t);
		asset->sm_mtg[mp][0]->sold_pct_planned_value = 0.0;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			asd_bv_sold
			= asset->sm_mtg[mp][0]->bk_val_bef_sale(t)
			  * asset->sm_mtg[mp][0]->pct_to_use;
			
			asd_accrued_sold
			= asset->sm_mtg[mp][0]->accr_int_bef_sale(t)
			  * asset->sm_mtg[mp][0]->pct_to_use;
			
			asd_mv_sold
			= asset->sm_mtg[mp][0]->mkt_val_bef_sale(t)
			  * asset->sm_mtg[mp][0]->pct_to_use;
			
			asd_cap_gain = asd_mv_sold - asd_bv_sold;
			
			asd_ucg_released
			= asset->sm_mtg[mp][0]->unrealzd_cap_gain_bef_sale(t)
			  * asset->sm_mtg[mp][0]->pct_to_use;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_mtg[mp][0]->sequence_id,
					asset->sm_mtg[mp][0]->asset_id,
					asset->sm_mtg[mp][0]->sub_port_id(t),
					asset->sm_mtg[mp][0]->sale_class_id,
					asset->sm_mtg[mp][0]->asset_fund_index,
					1.0,
					net_cash_from_asset_sale,
					asd_bv_sold,
					asd_accrued_sold,
					asd_mv_sold,
					asd_cap_gain,
					asd_ucg_released,
					asset->sm_mtg[mp][0]->dur_val(t));
			}
		}
	}
#endif

#if defined(__SEC_ASSET_H_)
for (mp_map_iter = seg_element->sec_mp_map_active.begin();
	 mp_map_iter != seg_element->sec_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_sec[mp]->neg_asset_flag < 0)
		continue;

	if (asset->sm_sec[mp]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if (asset->sm_sec[mp]->commencement_period <= t
		&& (t == asset->sm_sec[mp]->planned_sale_period
			|| asset->sm_sec[mp]->asset_min_size_sale_flag(t) == 1))
		{
		net_cash_from_asset_sale
		= expected_sale_cash(asset->sm_sec[mp]->bk_val_bef_sale(t),
		                     asset->sm_sec[mp]->accr_int_bef_sale(t),
		                     asset->sm_sec[mp]->mkt_val_bef_sale(t),
		                     asset->sm_sec[mp]->unrealzd_cap_gain_bef_sale(t),
		                     capital_gains_cash_factor_for_sales)
		  * asset->sm_sec[mp]->pct_to_use;

		asset->sm_sec[mp]->sold_pct_planned_value = 1.0;
		asset->sm_sec[mp]->sold_pct_planned(t);
		asset->sm_sec[mp]->sold_pct_planned_value = 0.0;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			asd_bv_sold
			= asset->sm_sec[mp]->bk_val_bef_sale(t)
			  * asset->sm_sec[mp]->pct_to_use;
			
			asd_accrued_sold
			= asset->sm_sec[mp]->accr_int_bef_sale(t)
			  * asset->sm_sec[mp]->pct_to_use;
			
			asd_mv_sold
			= asset->sm_sec[mp]->mkt_val_bef_sale(t)
			  * asset->sm_sec[mp]->pct_to_use;
			
			asd_cap_gain = asd_mv_sold - asd_bv_sold;
			
			asd_ucg_released
			= asset->sm_sec[mp]->unrealzd_cap_gain_bef_sale(t)
			  * asset->sm_sec[mp]->pct_to_use;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_sec[mp]->sequence_id,
					asset->sm_sec[mp]->asset_id,
					asset->sm_sec[mp]->sub_port_id(t),
					asset->sm_sec[mp]->sale_class_id,
					asset->sm_sec[mp]->asset_fund_index,
					1.0,
					net_cash_from_asset_sale,
					asd_bv_sold,
					asd_accrued_sold,
					asd_mv_sold,
					asd_cap_gain,
					asd_ucg_released,
					asset->sm_sec[mp]->dur_val(t));
			}
		}
	}
#endif

#if defined(__IRD_ASSET_H_)
for (mp_map_iter = seg_element->ird_mp_map_active.begin();
	 mp_map_iter != seg_element->ird_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_ird[mp][0]->neg_asset_flag < 0)
		continue;

	if (asset->sm_ird[mp][0]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if ((asset->sm_ird[mp][0]->commencement_period <= t
		&& (t == asset->sm_ird[mp][0]->planned_sale_period
			|| asset->sm_ird[mp][0]->asset_min_size_sale_flag(t) == 1)))
		{
		net_cash_from_asset_sale
		= expected_sale_cash(asset->sm_ird[mp][0]->bk_val_bef_sale(t),
		                     asset->sm_ird[mp][0]->accr_int_bef_sale(t),
		                     asset->sm_ird[mp][0]->mkt_val_bef_sale(t),
		                     asset->sm_ird[mp][0]->unrealzd_cap_gain_bef_sale(t),
		                     capital_gains_cash_factor_for_sales)
		  * asset->sm_ird[mp][0]->pct_to_use;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		asset->sm_ird[mp][0]->sold_pct_planned_value = 1.0;
		asset->sm_ird[mp][0]->sold_pct_planned(t);
		asset->sm_ird[mp][0]->sold_pct_planned_value = 0.0;

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			asd_bv_sold
			= asset->sm_ird[mp][0]->bk_val_bef_sale(t)
			  * asset->sm_ird[mp][0]->pct_to_use;
			
			asd_accrued_sold
			= asset->sm_ird[mp][0]->accr_int_bef_sale(t)
			  * asset->sm_ird[mp][0]->pct_to_use;
			
			asd_mv_sold
			= asset->sm_ird[mp][0]->mkt_val_bef_sale(t)
			  * asset->sm_ird[mp][0]->pct_to_use;
			
			asd_cap_gain = asd_mv_sold - asd_bv_sold;
			
			asd_ucg_released
			= asset->sm_ird[mp][0]->unrealzd_cap_gain_bef_sale(t)
			  * asset->sm_ird[mp][0]->pct_to_use;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_ird[mp][0]->sequence_id,
					asset->sm_ird[mp][0]->asset_id,
					asset->sm_ird[mp][0]->sub_port_id(t),
					asset->sm_ird[mp][0]->sale_class_id,
					asset->sm_ird[mp][0]->asset_fund_index,
					1.0,
					net_cash_from_asset_sale,
					asd_bv_sold,
					asd_accrued_sold,
					asd_mv_sold,
					asd_cap_gain,
					asd_ucg_released,
					asset->sm_ird[mp][0]->dur_val(t));
			}
		}
	}
#endif

#if defined(__RE_ASSET_H_)
for (mp_map_iter = seg_element->re_mp_map_active.begin();
	 mp_map_iter != seg_element->re_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_re[mp]->neg_asset_flag < 0)
		continue;

	if (asset->sm_re[mp]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if ((asset->sm_re[mp]->commencement_period <= t
		&& (t == asset->sm_re[mp]->planned_sale_period
			|| asset->sm_re[mp]->asset_min_size_sale_flag(t) == 1)))
		{
		net_cash_from_asset_sale
		= expected_sale_cash(asset->sm_re[mp]->bk_val_bef_sale(t),
		                     asset->sm_re[mp]->accr_rent_bef_sale(t),
		                     asset->sm_re[mp]->mkt_val_bef_sale(t),
		                     asset->sm_re[mp]->unrealzd_cap_gain_bef_sale(t),
		                     capital_gains_cash_factor_for_sales)
		  * asset->sm_re[mp]->pct_to_use;

		asset->sm_re[mp]->sold_pct_planned_value = 1.0;
		asset->sm_re[mp]->sold_pct_planned(t);
		asset->sm_re[mp]->sold_pct_planned_value = 0.0;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			asd_bv_sold
			= asset->sm_re[mp]->bk_val_bef_sale(t)
			  * asset->sm_re[mp]->pct_to_use;
			
			asd_accrued_sold
			= asset->sm_re[mp]->accr_rent_bef_sale(t)
			  * asset->sm_re[mp]->pct_to_use;
			
			asd_mv_sold
			= asset->sm_re[mp]->mkt_val_bef_sale(t)
			  * asset->sm_re[mp]->pct_to_use;
			
			asd_cap_gain = asd_mv_sold - asd_bv_sold;
			
			asd_ucg_released
			= asset->sm_re[mp]->unrealzd_cap_gain_bef_sale(t)
			  * asset->sm_re[mp]->pct_to_use;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_re[mp]->sequence_id,
					asset->sm_re[mp]->asset_id,
					asset->sm_re[mp]->sub_port_id(t),
					asset->sm_re[mp]->sale_class_id,
					asset->sm_re[mp]->asset_fund_index,
					1.0,
					net_cash_from_asset_sale,
					asd_bv_sold,
					asd_accrued_sold,
					asd_mv_sold,
					asd_cap_gain,
					asd_ucg_released,
					0.0);
			}
		}
	}
#endif

#if defined(__EQT_ASSET_H_)
for (mp_map_iter = seg_element->eqt_mp_map_active.begin();
	 mp_map_iter != seg_element->eqt_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_eqt[mp]->neg_asset_flag < 0)
		continue;

	if (asset->sm_eqt[mp]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if ((asset->sm_eqt[mp]->commencement_period <= t
		&& (t == asset->sm_eqt[mp]->planned_sale_period
			|| asset->sm_eqt[mp]->asset_min_size_sale_flag(t) == 1)))
		{
		net_cash_from_asset_sale
		= expected_sale_cash(asset->sm_eqt[mp]->bk_val_bef_sale(t),
		                     0.0,
		                     asset->sm_eqt[mp]->mkt_val_bef_sale(t),
		                     asset->sm_eqt[mp]->unrealzd_cap_gain_bef_sale(t),
		                     capital_gains_cash_factor_for_sales)
		  * asset->sm_eqt[mp]->pct_to_use;

		asset->sm_eqt[mp]->sold_pct_planned_value = 1.0;
		asset->sm_eqt[mp]->sold_pct_planned(t);
		asset->sm_eqt[mp]->sold_pct_planned_value = 0.0;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			asd_bv_sold
			= asset->sm_eqt[mp]->bk_val_bef_sale(t)
			  * asset->sm_eqt[mp]->pct_to_use;
			
			asd_accrued_sold = 0.0;
			
			asd_mv_sold
			= asset->sm_eqt[mp]->mkt_val_bef_sale(t)
			  * asset->sm_eqt[mp]->pct_to_use;
			
			asd_cap_gain = asd_mv_sold - asd_bv_sold;
			
			asd_ucg_released
			= asset->sm_eqt[mp]->unrealzd_cap_gain_bef_sale(t)
			  * asset->sm_eqt[mp]->pct_to_use;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_eqt[mp]->sequence_id,
					asset->sm_eqt[mp]->asset_id,
					asset->sm_eqt[mp]->sub_port_id(t),
					asset->sm_eqt[mp]->sale_class_id,
					asset->sm_eqt[mp]->asset_fund_index,
					1.0,
					net_cash_from_asset_sale,
					asd_bv_sold,
					asd_accrued_sold,
					asd_mv_sold,
					asd_cap_gain,
					asd_ucg_released,
					0);
			}
		}
	}
#endif

#if defined(__EIO_ASSET_H_)
for (mp_map_iter = seg_element->eio_mp_map_active.begin();
	 mp_map_iter != seg_element->eio_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_eio[mp][0]->neg_asset_flag < 0)
		continue;

	if (asset->sm_eio[mp][0]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if ((asset->sm_eio[mp][0]->commencement_period <= t
		&& (t == asset->sm_eio[mp][0]->planned_sale_period
			|| asset->sm_eio[mp][0]->asset_min_size_sale_flag(t) == 1)))
		{
		net_cash_from_asset_sale
		= expected_sale_cash(asset->sm_eio[mp][0]->bk_val_bef_sale(t),
		                     0.0,
		                     asset->sm_eio[mp][0]->mkt_val_bef_sale(t),
		                     asset->sm_eio[mp][0]->unrealzd_cap_gain_bef_sale(t),
		                     capital_gains_cash_factor_for_sales)
		  * asset->sm_eio[mp][0]->pct_to_use;

		asset->sm_eio[mp][0]->sold_pct_planned_value = 1.0;
		asset->sm_eio[mp][0]->sold_pct_planned(t);
		asset->sm_eio[mp][0]->sold_pct_planned_value = 0.0;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			asd_bv_sold
			= asset->sm_eio[mp][0]->bk_val_bef_sale(t)
			  * asset->sm_eio[mp][0]->pct_to_use;
			
			asd_accrued_sold = 0;
			
			asd_mv_sold
			= asset->sm_eio[mp][0]->mkt_val_bef_sale(t)
			  * asset->sm_eio[mp][0]->pct_to_use;
			
			asd_cap_gain = asd_mv_sold - asd_bv_sold;
			
			asd_ucg_released
			= asset->sm_eio[mp][0]->unrealzd_cap_gain_bef_sale(t)
			  * asset->sm_eio[mp][0]->pct_to_use;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_eio[mp][0]->sequence_id,
					asset->sm_eio[mp][0]->asset_id,
					asset->sm_eio[mp][0]->sub_port_id(t),
					asset->sm_eio[mp][0]->sale_class_id,
					asset->sm_eio[mp][0]->asset_fund_index,
					1.0,
					net_cash_from_asset_sale,
					asd_bv_sold,
					asd_accrued_sold,
					asd_mv_sold,
					asd_cap_gain,
					asd_ucg_released,
					asset->sm_eio[mp][0]->dur_val(t));
			}
		}
	}
#endif

#if defined(__EPA_ASSET_H_)
for (mp_map_iter = seg_element->epa_mp_map_active.begin();
	 mp_map_iter != seg_element->epa_mp_map_active.end();
	 mp_map_iter++)
	{
	mp = mp_map_iter->first;

	if (asset->sm_epa[mp]->neg_asset_flag < 0)
		continue;

	if (asset->sm_epa[mp]->notional_amt(t - 1) < ASSET_ACTIVE_THRESHOLD)
		continue;

	if (t == asset->sm_epa[mp]->planned_sale_period
		|| asset->sm_epa[mp]->asset_min_size_sale_flag(t) == 1)
		{
		net_cash_from_asset_sale
		= expected_sale_cash(asset->sm_epa[mp]->bk_val_bef_sale(t),
		                     asset->sm_epa[mp]->accr_int_bef_sale(t),
		                     asset->sm_epa[mp]->mkt_val_bef_sale(t),
		                     asset->sm_epa[mp]->unrealzd_cap_gain_bef_sale(t),
		                     capital_gains_cash_factor_for_sales)
		  * asset->sm_epa[mp]->pct_to_use;

		asset->sm_epa[mp]->sold_pct_planned_value = 1.0;
		asset->sm_epa[mp]->sold_pct_planned(t);
		asset->sm_epa[mp]->sold_pct_planned_value = 0.0;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			asd_bv_sold
			= asset->sm_epa[mp]->bk_val_bef_sale(t)
			  * asset->sm_epa[mp]->pct_to_use;
			
			asd_accrued_sold 
			= asset->sm_epa[mp]->accr_int_bef_sale(t)
			  * asset->sm_epa[mp]->pct_to_use;
			
			asd_mv_sold
			= asset->sm_epa[mp]->mkt_val_bef_sale(t)
			  * asset->sm_epa[mp]->pct_to_use;
			
			asd_cap_gain = asd_mv_sold - asd_bv_sold;
			
			asd_ucg_released
			= asset->sm_epa[mp]->unrealzd_cap_gain_bef_sale(t)
			  * asset->sm_epa[mp]->pct_to_use;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_epa[mp]->sequence_id,
					asset->sm_epa[mp]->asset_id,
					asset->sm_epa[mp]->sub_port_id(t),
					asset->sm_epa[mp]->sale_class_id,
					asset->sm_epa[mp]->asset_fund_index,
					1.0,
					net_cash_from_asset_sale,
					asd_bv_sold,
					asd_accrued_sold,
					asd_mv_sold,
					asd_cap_gain,
					asd_ucg_released,
					asset->sm_epa[mp]->dur_val(t));
			}
		}
	}
#endif

return net_cash_from_sales;
}



#line 1 "sell_assets_pro_rata.INVSTRAT_ASSET.for"                                                                                   
double INVSTRAT_ASSET::sell_assets_pro_rata(int t, StrEnum::EnumValue sell_assets, StrEnum::EnumValue sales_type, double cash_required, double capital_gains_cash_factor_for_sales)
{
int mp = 0;
int asset_sub_port = 0;
int asset_class = 0;
int sub_port_num = 0;
int sales_class_num = 0;
int asset_fund_index = 0;
double accrued_interest_available = 0.0;
double accrued_rent_available = 0.0;
double book_value_available  = 0.0;
double market_value_available = 0.0;
double unrealized_capital_gains_available = 0.0;
double remaining_cash_required = 0.0;
double estimated_net_cash_from_sale = 0.0;
double net_cash_from_asset_sale = 0.0;
double net_cash_from_sales = 0.0;
double pct_to_sell_prelim = 0.0;
double percent_of_asset_to_sell = 0.0;
double book_sold = 0.0;
double accrued_sold = 0.0;
double market_sold = 0.0;
double capital_gain = 0.0;
double unrealized_capital_gain_released = 0.0;
double asset_percent_remaining = 0.0;
double local_pct_to_use = 0.0;
bool is_negative_cash_flow_sales = (sales_type == NEGATIVE_CASH_FLOW_SALES);
bool is_rebal_sales = (sales_type == REBALANCING_SALES);

int col_num_asset_sub_port_num = 0;
int col_num_include_in_duration_matching = 0;
int col_num_notional_amount_before_sales = 0;
int col_num_notional_amount = 0;
int col_num_portion_of_asset_sold_planned_sales = 0;
int col_num_accrued_interest_before_sales = 0;
int col_num_book_value_before_sales = 0;
int col_num_market_value_before_sales = 0;
int col_num_portion_of_asset_sold_sales = 0; // for rebalancing or negative cash flow sales
int col_num_portion_of_asset_sold_rebal_sales = 0;
int col_num_unrealized_capital_gains_before_sales = 0;
int col_num_mkt_val_for_dur_bef_rebal_sale = 0;
int col_num_mkt_val_times_dur_bef_rebal_sale = 0;

current_sub_port = NULL;

remaining_cash_required = cash_required;

if (remaining_cash_required > model_point_amount_threshold)
	{
	initialize_sub_port_sale_vars_eom(t);

	for (asset_sub_port = 0; asset_sub_port < asset->sm_asset_sub_port[seg_num].size(); asset_sub_port++)
		{
		if (asset->sm_asset_sub_port[seg_num][asset_sub_port][0]->sub_ports_to_sell == 1)
			{
			for (asset_class = 1; asset_class <= MAXIMUM_NUMBER_OF_SALES_CLASSES; asset_class++)
				{
				if (asset_class_to_sell_flag[asset_class] == 1)
					{
					accrued_interest_available
					+= sub_port_class_fund_initial_accrued_interest[asset_sub_port][asset_class][INVESTMENT_FUND_INDEX]
					   - sub_port_class_fund_accrued_interest_sold[asset_sub_port][asset_class][INVESTMENT_FUND_INDEX];

					book_value_available
					+= sub_port_class_fund_initial_book_value[asset_sub_port][asset_class][INVESTMENT_FUND_INDEX]
					   - sub_port_class_fund_book_value_sold[asset_sub_port][asset_class][INVESTMENT_FUND_INDEX];

					unrealized_capital_gains_available
					+= sub_port_class_fund_initial_unrealized_capital_gains[asset_sub_port][asset_class][INVESTMENT_FUND_INDEX]
					   - sub_port_class_fund_unrealized_capital_gains_released[asset_sub_port][asset_class][INVESTMENT_FUND_INDEX];

					market_value_available
					+= sub_port_class_fund_initial_market_value[asset_sub_port][asset_class][INVESTMENT_FUND_INDEX]
					   - sub_port_class_fund_market_value_sold[asset_sub_port][asset_class][INVESTMENT_FUND_INDEX];
					} // endif asset_class_to_sell_flag[asset_class] == 1.0
				} // end_for over asset_class
			} // endif sm_a_subport[asset_sub_port][0]->sub_ports_to_sell == 1
		} // end_for over asset_sub_port

	if (sales_type == REBALANCING_SALES)
		estimated_net_cash_from_sale
		= book_value_available + accrued_interest_available;
	else
		estimated_net_cash_from_sale
		= expected_sale_cash(book_value_available,
							 accrued_interest_available,
							 market_value_available,
							 unrealized_capital_gains_available,
							 capital_gains_cash_factor_for_sales);

	if (estimated_net_cash_from_sale <= remaining_cash_required)
		pct_to_sell_prelim = 1.0;

	else if (estimated_net_cash_from_sale > remaining_cash_required)
		pct_to_sell_prelim
		= remaining_cash_required / estimated_net_cash_from_sale;

	map <int, long, less <int> >::iterator mp_map_iter;

	#if defined(__BOND_ASSET_H_)
	// loop over bonds
	if (seg_element->bond_mp_map_active.size())
		{
		col_num_asset_sub_port_num
		= asset->sm_bond[0][0]->Column("sub_port_id").Number();
		col_num_include_in_duration_matching
		= asset->sm_bond[0][0]->Column("dur_match_flag").Number();
		col_num_notional_amount
		= asset->sm_bond[0][0]->Column("notional_amt").Number();
		col_num_portion_of_asset_sold_planned_sales
		= asset->sm_bond[0][0]->Column("sold_pct_planned").Number();

		if (is_rebal_sales)
			{
			col_num_accrued_interest_before_sales
			= asset->sm_bond[0][0]->Column("accr_int_bef_rebal_sale").Number();
			col_num_book_value_before_sales
			= asset->sm_bond[0][0]->Column("bk_val_bef_rebal_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_bond[0][0]->Column("mkt_val_bef_rebal_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_bond[0][0]->Column("notional_amt_bef_rebal_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_bond[0][0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_bond[0][0]->Column("unrealzd_cap_gain_bef_rebal_sale").Number();

			col_num_mkt_val_for_dur_bef_rebal_sale
			= asset->sm_bond[0][0]->Column("mkt_val_for_dur_bef_rebal_sale").Number();
			col_num_mkt_val_times_dur_bef_rebal_sale
			= asset->sm_bond[0][0]->Column("mkt_val_times_dur_bef_rebal_sale").Number();
			}
		else // negative cash flow sales
			{
			col_num_accrued_interest_before_sales
			= asset->sm_bond[0][0]->Column("accr_int_bef_neg_cash_flow_sale").Number();
			col_num_book_value_before_sales
			= asset->sm_bond[0][0]->Column("bk_val_bef_neg_cash_flow_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_bond[0][0]->Column("mkt_val_bef_neg_cash_flow_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_bond[0][0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_bond[0][0]->Column("sold_pct_neg_cash_flow").Number();
			col_num_portion_of_asset_sold_rebal_sales
			= asset->sm_bond[0][0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_bond[0][0]->Column("unrealzd_cap_gain_bef_neg_cash_flow_sale").Number();
			}
		}

	for (mp_map_iter = seg_element->bond_mp_map_active.begin();
		 mp_map_iter != seg_element->bond_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (asset->sm_bond[mp][0]->neg_asset_flag < 0)
			continue;

		if ((t > max(0, asset->sm_bond[mp][0]->commencement_period)
			 && asset->sm_bond[mp][0]->Column(col_num_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_bond[mp][0]->commencement_period
				&& asset->sm_bond[mp][0]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_bond[mp][0]->Column(col_num_asset_sub_port_num).Value(t));
		sales_class_num = asset->sm_bond[mp][0]->sale_class_id;
		asset_fund_index = asset->sm_bond[mp][0]->asset_fund_index;
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

		if (current_sub_port->sub_ports_to_sell != 1
			|| asset_class_to_sell_flag[sales_class_num] != 1
			|| asset_fund_to_sell_flag[asset_fund_index] != 1)
			continue;

		asset_percent_remaining
		= (1.0 - asset->sm_bond[mp][0]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

		if (is_negative_cash_flow_sales)
			asset_percent_remaining
			*= (1.0 - asset->sm_bond[mp][0]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

		if (asset_percent_remaining < rate_ratio_threshold)
			continue;

		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_bond[mp][0]->pct_to_use;

		book_value_available
		= asset->sm_bond[mp][0]->Column(col_num_book_value_before_sales).Value(t);
		accrued_interest_available
		= asset->sm_bond[mp][0]->Column(col_num_accrued_interest_before_sales).Value(t);
		market_value_available
		= asset->sm_bond[mp][0]->Column(col_num_market_value_before_sales).Value(t);
		unrealized_capital_gains_available
		= asset->sm_bond[mp][0]->Column(col_num_unrealized_capital_gains_before_sales).Value(t);

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;  

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     accrued_interest_available,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		book_sold
		= book_value_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		accrued_sold
		= accrued_interest_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		if (sell_assets == YES)
			{
			asset->sm_bond[mp][0]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
			asset->sm_bond[mp][0]->Column(col_num_portion_of_asset_sold_sales).Value(t);
			asset->sm_bond[mp][0]->sold_pct_neg_cash_flow_value = 0.0;

			market_sold
			= market_value_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			unrealized_capital_gain_released
			= unrealized_capital_gains_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, accrued_sold,
					market_sold, unrealized_capital_gain_released);
			}
		else
			{
			expected_sold_at_bk
			+= book_sold + accrued_sold;

			sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
			+= book_sold + accrued_sold;

			if (asset->sm_bond[mp][0]->neg_asset_flag > 0)
				{
				expected_mkt_val_for_dur_sale
				+= asset->sm_bond[mp][0]->mkt_val_for_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;

				expected_mkt_val_times_dur_sale
				+= asset->sm_bond[mp][0]->mkt_val_times_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;
				}
			}

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_bond[mp][0]->sequence_id,
					asset->sm_bond[mp][0]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, accrued_sold,
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					asset->sm_bond[mp][0]->dur_val(t));
			}

		percent_of_asset_to_sell = 0.0;
		} // end for on bonds 
	#endif

	#if defined(__MTG_ASSET_H_)
	// loop over mortgages
	if (seg_element->mtg_mp_map_active.size())
		{
		col_num_asset_sub_port_num
		= asset->sm_mtg[0][0]->Column("sub_port_id").Number();
		col_num_include_in_duration_matching
		= asset->sm_mtg[0][0]->Column("dur_match_flag").Number();
		col_num_notional_amount
		= asset->sm_mtg[0][0]->Column("notional_amt").Number();
		col_num_portion_of_asset_sold_planned_sales
		= asset->sm_mtg[0][0]->Column("sold_pct_planned").Number();

		if (is_rebal_sales)
			{
			col_num_accrued_interest_before_sales
			= asset->sm_mtg[0][0]->Column("accr_int_bef_rebal_sale").Number();
			col_num_book_value_before_sales
			= asset->sm_mtg[0][0]->Column("bk_val_bef_rebal_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_mtg[0][0]->Column("mkt_val_bef_rebal_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_mtg[0][0]->Column("notional_amt_bef_rebal_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_mtg[0][0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_mtg[0][0]->Column("unrealzd_cap_gain_bef_rebal_sale").Number();

			col_num_mkt_val_for_dur_bef_rebal_sale
			= asset->sm_mtg[0][0]->Column("mkt_val_for_dur_bef_rebal_sale").Number();
			col_num_mkt_val_times_dur_bef_rebal_sale
			= asset->sm_mtg[0][0]->Column("mkt_val_times_dur_bef_rebal_sale").Number();
			}
		else // negative cash flow sales
			{
			col_num_accrued_interest_before_sales
			= asset->sm_mtg[0][0]->Column("accr_int_bef_neg_cash_flow_sale").Number();
			col_num_book_value_before_sales
			= asset->sm_mtg[0][0]->Column("bk_val_bef_neg_cash_flow_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_mtg[0][0]->Column("mkt_val_bef_neg_cash_flow_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_mtg[0][0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_mtg[0][0]->Column("sold_pct_neg_cash_flow").Number();
			col_num_portion_of_asset_sold_rebal_sales
			= asset->sm_mtg[0][0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_mtg[0][0]->Column("unrealzd_cap_gain_bef_neg_cash_flow_sale").Number();
			}
		}

	for (mp_map_iter = seg_element->mtg_mp_map_active.begin();
		 mp_map_iter != seg_element->mtg_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (asset->sm_mtg[mp][0]->neg_asset_flag < 0)
			continue;

		if ((t > max(0, asset->sm_mtg[mp][0]->commencement_period)
			 && asset->sm_mtg[mp][0]->Column(col_num_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_mtg[mp][0]->commencement_period
				&& asset->sm_mtg[mp][0]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_mtg[mp][0]->Column(col_num_asset_sub_port_num).Value(t));
		sales_class_num = asset->sm_mtg[mp][0]->sale_class_id;
		asset_fund_index = asset->sm_mtg[mp][0]->asset_fund_index;
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

		if (current_sub_port->sub_ports_to_sell != 1
			|| asset_class_to_sell_flag[sales_class_num] != 1
			|| asset_fund_to_sell_flag[asset_fund_index] != 1)
			continue;

		asset_percent_remaining
		= (1.0 - asset->sm_mtg[mp][0]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

		if (is_negative_cash_flow_sales)
			asset_percent_remaining
			*= (1.0 - asset->sm_mtg[mp][0]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

		if (asset_percent_remaining  < rate_ratio_threshold)
			continue;

			{
			current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
			local_pct_to_use = asset->sm_mtg[mp][0]->pct_to_use;

			book_value_available
			= asset->sm_mtg[mp][0]->Column(col_num_book_value_before_sales).Value(t);
			accrued_interest_available
			= asset->sm_mtg[mp][0]->Column(col_num_accrued_interest_before_sales).Value(t);
			market_value_available
			= asset->sm_mtg[mp][0]->Column(col_num_market_value_before_sales).Value(t);
			unrealized_capital_gains_available
			= asset->sm_mtg[mp][0]->Column(col_num_unrealized_capital_gains_before_sales).Value(t);

			if (fabs(book_value_available
					 * local_pct_to_use
					 * (1.0 - pct_to_sell_prelim))
				 >= current_sub_port->min_size_existing)
				percent_of_asset_to_sell  
				= pct_to_sell_prelim;
			else
				percent_of_asset_to_sell = 1.0;  

			net_cash_from_asset_sale
			= expected_sale_cash(book_value_available,
			                     accrued_interest_available,
			                     market_value_available,
			                     unrealized_capital_gains_available,
			                     capital_gains_cash_factor_for_sales)
			  * local_pct_to_use
			  * percent_of_asset_to_sell; 

			net_cash_from_sales
			+= net_cash_from_asset_sale;

			book_sold
			= book_value_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			accrued_sold
			= accrued_interest_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			if (sell_assets == YES)
				{
				asset->sm_mtg[mp][0]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
				asset->sm_mtg[mp][0]->Column(col_num_portion_of_asset_sold_sales).Value(t);
				asset->sm_mtg[mp][0]->sold_pct_neg_cash_flow_value = 0.0;

				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				accumulate_asset_sale(sub_port_num,
						sales_class_num, asset_fund_index,
						book_sold, accrued_sold,
						market_sold, unrealized_capital_gain_released);
				}
			else
				{
				expected_sold_at_bk
				+= book_sold + accrued_sold;

				sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
				+= book_sold + accrued_sold;

				if (asset->sm_mtg[mp][0]->neg_asset_flag > 0)
					{
					expected_mkt_val_for_dur_sale
					+= asset->sm_mtg[mp][0]->mkt_val_for_dur_bef_rebal_sale(t)
					   * local_pct_to_use
					   * percent_of_asset_to_sell;

					expected_mkt_val_times_dur_sale
					+= asset->sm_mtg[mp][0]->mkt_val_times_dur_bef_rebal_sale(t)
					   * local_pct_to_use
					   * percent_of_asset_to_sell;
					}
				}

			if (asset->asset_detail_rpt_inv_strat_flag(t))
				{
				if (sell_assets != YES)
					{
					market_sold
					= market_value_available
					  * local_pct_to_use
					  * percent_of_asset_to_sell;

					unrealized_capital_gain_released
					= unrealized_capital_gains_available
					  * local_pct_to_use
					  * percent_of_asset_to_sell;
					}

				capital_gain = market_sold - book_sold;

				asset_detail_rpt_individual_sale(t, ASSET_DATA,
						asset->sm_mtg[mp][0]->sequence_id,
						asset->sm_mtg[mp][0]->asset_id,
						sub_port_num, sales_class_num, asset_fund_index,
						percent_of_asset_to_sell,
						net_cash_from_asset_sale,
						book_sold, accrued_sold,
						market_sold, capital_gain,
						unrealized_capital_gain_released,
						asset->sm_mtg[mp][0]->dur_val(t));
				}
			} // endif (asset_percent_remaining > 0.0)

		percent_of_asset_to_sell = 0.0;
		} // end for on mtgs 
	#endif

	#if defined(__SEC_ASSET_H_)
	// loop over secs
	if (seg_element->sec_mp_map_active.size())
		{
		col_num_asset_sub_port_num
		= asset->sm_sec[0]->Column("sub_port_id").Number();
		col_num_include_in_duration_matching
		= asset->sm_sec[0]->Column("dur_match_flag").Number();
		col_num_notional_amount
		= asset->sm_sec[0]->Column("notional_amt").Number();
		col_num_portion_of_asset_sold_planned_sales
		= asset->sm_sec[0]->Column("sold_pct_planned").Number();

		if (is_rebal_sales)
			{
			col_num_accrued_interest_before_sales
			= asset->sm_sec[0]->Column("accr_int_bef_rebal_sale").Number();
			col_num_book_value_before_sales
			= asset->sm_sec[0]->Column("bk_val_bef_rebal_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_sec[0]->Column("mkt_val_bef_rebal_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_sec[0]->Column("notional_amt_bef_rebal_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_sec[0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_sec[0]->Column("unrealzd_cap_gain_bef_rebal_sale").Number();

			col_num_mkt_val_for_dur_bef_rebal_sale
			= asset->sm_sec[0]->Column("mkt_val_for_dur_bef_rebal_sale").Number();
			col_num_mkt_val_times_dur_bef_rebal_sale
			= asset->sm_sec[0]->Column("mkt_val_times_dur_bef_rebal_sale").Number();
			}
		else // negative cash flow sales
			{
			col_num_accrued_interest_before_sales
			= asset->sm_sec[0]->Column("accr_int_bef_neg_cash_flow_sale").Number();
			col_num_book_value_before_sales
			= asset->sm_sec[0]->Column("bk_val_bef_neg_cash_flow_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_sec[0]->Column("mkt_val_bef_neg_cash_flow_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_sec[0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_sec[0]->Column("sold_pct_neg_cash_flow").Number();
			col_num_portion_of_asset_sold_rebal_sales
			= asset->sm_sec[0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_sec[0]->Column("unrealzd_cap_gain_bef_neg_cash_flow_sale").Number();
			}
		}

	for (mp_map_iter = seg_element->sec_mp_map_active.begin();
		 mp_map_iter != seg_element->sec_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (asset->sm_sec[mp]->neg_asset_flag < 0)
			continue;

		if ((t > max(0, asset->sm_sec[mp]->commencement_period)
			 && asset->sm_sec[mp]->Column(col_num_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_sec[mp]->commencement_period
				&& asset->sm_sec[mp]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_sec[mp]->Column(col_num_asset_sub_port_num).Value(t));
		sales_class_num = asset->sm_sec[mp]->sale_class_id;
		asset_fund_index = asset->sm_sec[mp]->asset_fund_index;
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

		if (current_sub_port->sub_ports_to_sell != 1
			|| asset_class_to_sell_flag[sales_class_num] != 1
			|| asset_fund_to_sell_flag[asset_fund_index] != 1)
			continue;

		asset_percent_remaining
		= (1.0 - asset->sm_sec[mp]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

		if (is_negative_cash_flow_sales)
			asset_percent_remaining
			*= (1.0 - asset->sm_sec[mp]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

		if (asset_percent_remaining < SMALL_DOUBLE)
			continue;

		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_sec[mp]->pct_to_use;

		book_value_available
		= asset->sm_sec[mp]->Column(col_num_book_value_before_sales).Value(t);
		accrued_interest_available
		= asset->sm_sec[mp]->Column(col_num_accrued_interest_before_sales).Value(t);
		market_value_available
		= asset->sm_sec[mp]->Column(col_num_market_value_before_sales).Value(t);
		unrealized_capital_gains_available
		= asset->sm_sec[mp]->Column(col_num_unrealized_capital_gains_before_sales).Value(t);

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;  

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     accrued_interest_available,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell; 

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		book_sold
		= book_value_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		accrued_sold
		= accrued_interest_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		if (sell_assets == YES)
			{
			asset->sm_sec[mp]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
			asset->sm_sec[mp]->Column(col_num_portion_of_asset_sold_sales).Value(t);
			asset->sm_sec[mp]->sold_pct_neg_cash_flow_value = 0.0;

			market_sold
			= market_value_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			unrealized_capital_gain_released
			= unrealized_capital_gains_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, accrued_sold,
					market_sold, unrealized_capital_gain_released);
			}
		else
			{
			expected_sold_at_bk
			+= book_sold + accrued_sold;

			sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
			+= book_sold + accrued_sold;

			if (asset->sm_sec[mp]->neg_asset_flag > 0)
				{
				expected_mkt_val_for_dur_sale
				+= asset->sm_sec[mp]->mkt_val_for_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;

				expected_mkt_val_times_dur_sale
				+= asset->sm_sec[mp]->mkt_val_times_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;
				}
			}

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_sec[mp]->sequence_id,
					asset->sm_sec[mp]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, accrued_sold,
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					asset->sm_sec[mp]->dur_val(t));
			}

		percent_of_asset_to_sell = 0.0;
		} // end for on secs 
	#endif

	#if defined(__IRD_ASSET_H_)
	// loop over interest contracts
	if (seg_element->ird_mp_map_active.size())
		{
		col_num_asset_sub_port_num
		= asset->sm_ird[0][0]->Column("sub_port_id").Number();
		col_num_include_in_duration_matching
		= asset->sm_ird[0][0]->Column("dur_match_flag").Number();
		col_num_notional_amount
		= asset->sm_ird[0][0]->Column("notional_amt").Number();
		col_num_portion_of_asset_sold_planned_sales
		= asset->sm_ird[0][0]->Column("sold_pct_planned").Number();

		if (is_rebal_sales)
			{
			col_num_accrued_interest_before_sales
			= asset->sm_ird[0][0]->Column("accr_int_bef_rebal_sale").Number();
			col_num_book_value_before_sales
			= asset->sm_ird[0][0]->Column("bk_val_bef_rebal_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_ird[0][0]->Column("mkt_val_bef_rebal_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_ird[0][0]->Column("notional_amt_bef_rebal_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_ird[0][0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_ird[0][0]->Column("unrealzd_cap_gain_bef_rebal_sale").Number();

			col_num_mkt_val_for_dur_bef_rebal_sale
			= asset->sm_ird[0][0]->Column("mkt_val_for_dur_bef_rebal_sale").Number();
			col_num_mkt_val_times_dur_bef_rebal_sale
			= asset->sm_ird[0][0]->Column("mkt_val_times_dur_bef_rebal_sale").Number();
			}
		else // negative cash flow sales
			{
			col_num_accrued_interest_before_sales
			= asset->sm_ird[0][0]->Column("accr_int_bef_neg_cash_flow_sale").Number();
			col_num_book_value_before_sales
			= asset->sm_ird[0][0]->Column("bk_val_bef_neg_cash_flow_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_ird[0][0]->Column("mkt_val_bef_neg_cash_flow_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_ird[0][0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_ird[0][0]->Column("sold_pct_neg_cash_flow").Number();
			col_num_portion_of_asset_sold_rebal_sales
			= asset->sm_ird[0][0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_ird[0][0]->Column("unrealzd_cap_gain_bef_neg_cash_flow_sale").Number();
			}
		}

	for (mp_map_iter = seg_element->ird_mp_map_active.begin();
		 mp_map_iter != seg_element->ird_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (asset->sm_ird[mp][0]->neg_asset_flag < 0)
			continue;

		if ((t > max(0, asset->sm_ird[mp][0]->commencement_period)
			 && asset->sm_ird[mp][0]->Column(col_num_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_ird[mp][0]->commencement_period
				&& asset->sm_ird[mp][0]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_ird[mp][0]->Column(col_num_asset_sub_port_num).Value(t));
		sales_class_num = asset->sm_ird[mp][0]->sale_class_id;
		asset_fund_index = asset->sm_ird[mp][0]->asset_fund_index;
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

		if (current_sub_port->sub_ports_to_sell != 1
			|| asset_class_to_sell_flag[sales_class_num] != 1
			|| asset_fund_to_sell_flag[asset_fund_index] != 1)
			continue;

		asset_percent_remaining
		= (1.0 - asset->sm_ird[mp][0]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

		if (is_negative_cash_flow_sales)
			asset_percent_remaining
			*= (1.0 - asset->sm_ird[mp][0]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

		if (asset_percent_remaining < SMALL_DOUBLE)
			continue;

		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_ird[mp][0]->pct_to_use;

		book_value_available
		= asset->sm_ird[mp][0]->Column(col_num_book_value_before_sales).Value(t);
		accrued_interest_available
		= asset->sm_ird[mp][0]->Column(col_num_accrued_interest_before_sales).Value(t);
		market_value_available
		= asset->sm_ird[mp][0]->Column(col_num_market_value_before_sales).Value(t);
		unrealized_capital_gains_available
		= asset->sm_ird[mp][0]->Column(col_num_unrealized_capital_gains_before_sales).Value(t);

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;  

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     accrued_interest_available,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell; 

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		book_sold
		= book_value_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		accrued_sold
		= accrued_interest_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		if (sell_assets == YES)
			{
			asset->sm_ird[mp][0]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
			asset->sm_ird[mp][0]->Column(col_num_portion_of_asset_sold_sales).Value(t);
			asset->sm_ird[mp][0]->sold_pct_neg_cash_flow_value = 0.0;

			market_sold
			= market_value_available
			 * local_pct_to_use
			 * percent_of_asset_to_sell;

			unrealized_capital_gain_released
			= unrealized_capital_gains_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, accrued_sold,
					market_sold, unrealized_capital_gain_released);
			}
		else
			{
			expected_sold_at_bk
			+= book_sold + accrued_sold;

			sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
			+= book_sold + accrued_sold;

			if (asset->sm_ird[mp][0]->neg_asset_flag > 0)
				{
				expected_mkt_val_for_dur_sale
				+= asset->sm_ird[mp][0]->mkt_val_for_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;

				expected_mkt_val_times_dur_sale
				+= asset->sm_ird[mp][0]->mkt_val_times_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;
				}
			}

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_ird[mp][0]->sequence_id,
					asset->sm_ird[mp][0]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, accrued_sold,
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					asset->sm_ird[mp][0]->dur_val(t));
			}

		percent_of_asset_to_sell = 0.0;
		} // end for on interest contract mp
	#endif

	#if defined(__RE_ASSET_H_)
	// loop over real estate
	if (seg_element->re_mp_map_active.size())
		{
		col_num_asset_sub_port_num
		= asset->sm_re[0]->Column("sub_port_id").Number();
		col_num_include_in_duration_matching
		= asset->sm_re[0]->Column("dur_match_flag").Number();
		col_num_notional_amount
		= asset->sm_re[0]->Column("notional_amt").Number();
		col_num_portion_of_asset_sold_planned_sales
		= asset->sm_re[0]->Column("sold_pct_planned").Number();

		if (is_rebal_sales)
			{
			col_num_accrued_interest_before_sales
			= asset->sm_re[0]->Column("accr_rent_bef_rebal_sale").Number();
			col_num_book_value_before_sales
			= asset->sm_re[0]->Column("bk_val_bef_rebal_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_re[0]->Column("mkt_val_bef_rebal_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_re[0]->Column("notional_amt_bef_rebal_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_re[0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_re[0]->Column("unrealzd_cap_gain_bef_rebal_sale").Number();

			col_num_mkt_val_for_dur_bef_rebal_sale
			= asset->sm_re[0]->Column("mkt_val_for_dur_bef_rebal_sale").Number();
			col_num_mkt_val_times_dur_bef_rebal_sale
			= asset->sm_re[0]->Column("mkt_val_times_dur_bef_rebal_sale").Number();
			}
		else // negative cash flow sales
			{
			col_num_accrued_interest_before_sales
			= asset->sm_re[0]->Column("accr_rent_bef_neg_cash_flow_sale").Number();
			col_num_book_value_before_sales
			= asset->sm_re[0]->Column("bk_val_bef_neg_cash_flow_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_re[0]->Column("mkt_val_bef_neg_cash_flow_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_re[0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_re[0]->Column("sold_pct_neg_cash_flow").Number();
			col_num_portion_of_asset_sold_rebal_sales
			= asset->sm_re[0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_re[0]->Column("unrealzd_cap_gain_bef_neg_cash_flow_sale").Number();
			}
		}

	for (mp_map_iter = seg_element->re_mp_map_active.begin();
		 mp_map_iter != seg_element->re_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (asset->sm_re[mp]->neg_asset_flag < 0)
			continue;

		if ((t > max(0, asset->sm_re[mp]->commencement_period)
			 && asset->sm_re[mp]->Column(col_num_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_re[mp]->commencement_period
				&& asset->sm_re[mp]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_re[mp]->Column(col_num_asset_sub_port_num).Value(t));
		sales_class_num = asset->sm_re[mp]->sale_class_id;
		asset_fund_index = asset->sm_re[mp]->asset_fund_index;
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

		if (current_sub_port->sub_ports_to_sell != 1
			|| asset_class_to_sell_flag[sales_class_num] != 1
			|| asset_fund_to_sell_flag[asset_fund_index] != 1)
			continue;

		asset_percent_remaining
		= (1.0 - asset->sm_re[mp]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

		if (is_negative_cash_flow_sales)
			asset_percent_remaining
			*= (1.0 - asset->sm_re[mp]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

		if (asset_percent_remaining < SMALL_DOUBLE)
			continue;

		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_re[mp]->pct_to_use;

		book_value_available
		= asset->sm_re[mp]->Column(col_num_book_value_before_sales).Value(t);
		accrued_rent_available
		= asset->sm_re[mp]->Column(col_num_accrued_interest_before_sales).Value(t);
		market_value_available
		= asset->sm_re[mp]->Column(col_num_market_value_before_sales).Value(t);
		unrealized_capital_gains_available
		= asset->sm_re[mp]->Column(col_num_unrealized_capital_gains_before_sales).Value(t);

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     accrued_rent_available,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		book_sold
		= book_value_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		accrued_sold
		= accrued_rent_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		if (sell_assets == YES)
			{
			asset->sm_re[mp]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
			asset->sm_re[mp]->Column(col_num_portion_of_asset_sold_sales).Value(t);
			asset->sm_re[mp]->sold_pct_neg_cash_flow_value = 0.0;

			market_sold
			= market_value_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			unrealized_capital_gain_released
			= unrealized_capital_gains_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, accrued_sold,
					market_sold, unrealized_capital_gain_released);
			}
		else
			{
			expected_sold_at_bk
			+= book_sold + accrued_sold;

			sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
			+= book_sold + accrued_sold;
			}

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_re[mp]->sequence_id,
					asset->sm_re[mp]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, accrued_sold,
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					0);
			}

		percent_of_asset_to_sell = 0.0;
		} // end for on real estate mp
	#endif

	#if defined(__EQT_ASSET_H_)
	// loop over equities
	if (seg_element->eqt_mp_map_active.size())
		{
		col_num_asset_sub_port_num
		= asset->sm_eqt[0]->Column("sub_port_id").Number();
		col_num_include_in_duration_matching
		= asset->sm_eqt[0]->Column("dur_match_flag").Number();
		col_num_notional_amount
		= asset->sm_eqt[0]->Column("notional_amt").Number();
		col_num_portion_of_asset_sold_planned_sales
		= asset->sm_eqt[0]->Column("sold_pct_planned").Number();

		if (is_rebal_sales)
			{
			col_num_book_value_before_sales
			= asset->sm_eqt[0]->Column("bk_val_bef_rebal_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_eqt[0]->Column("mkt_val_bef_rebal_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_eqt[0]->Column("notional_amt_bef_rebal_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_eqt[0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_eqt[0]->Column("unrealzd_cap_gain_bef_rebal_sale").Number();

			col_num_mkt_val_for_dur_bef_rebal_sale
			= asset->sm_eqt[0]->Column("mkt_val_for_dur_bef_rebal_sale").Number();
			col_num_mkt_val_times_dur_bef_rebal_sale
			= asset->sm_eqt[0]->Column("mkt_val_times_dur_bef_rebal_sale").Number();
			}
		else // negative cash flow sales
			{
			col_num_book_value_before_sales
			= asset->sm_eqt[0]->Column("bk_val_bef_neg_cash_flow_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_eqt[0]->Column("mkt_val_bef_neg_cash_flow_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_eqt[0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_eqt[0]->Column("sold_pct_neg_cash_flow").Number();
			col_num_portion_of_asset_sold_rebal_sales
			= asset->sm_eqt[0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_eqt[0]->Column("unrealzd_cap_gain_bef_neg_cash_flow_sale").Number();
			}
		}

	for (mp_map_iter = seg_element->eqt_mp_map_active.begin();
		 mp_map_iter != seg_element->eqt_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (asset->sm_eqt[mp]->neg_asset_flag < 0)
			continue;

		if ((t > max(0, asset->sm_eqt[mp]->commencement_period)
			 && asset->sm_eqt[mp]->Column(col_num_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_eqt[mp]->commencement_period
				&& asset->sm_eqt[mp]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_eqt[mp]->sub_port_id(t));
		sales_class_num = asset->sm_eqt[mp]->sale_class_id;
		asset_fund_index = asset->sm_eqt[mp]->asset_fund_index;
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

		if (current_sub_port->sub_ports_to_sell != 1
			|| asset_class_to_sell_flag[sales_class_num] != 1
			|| asset_fund_to_sell_flag[asset_fund_index] != 1)
			continue;

		asset_percent_remaining
		= (1.0 - asset->sm_eqt[mp]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

		if (is_negative_cash_flow_sales)
			asset_percent_remaining
			*= (1.0 - asset->sm_eqt[mp]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

		if (asset_percent_remaining < SMALL_DOUBLE)
			continue;

		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_eqt[mp]->pct_to_use;

		book_value_available
		= asset->sm_eqt[mp]->Column(col_num_book_value_before_sales).Value(t);
		market_value_available
		= asset->sm_eqt[mp]->Column(col_num_market_value_before_sales).Value(t);
		unrealized_capital_gains_available
		= asset->sm_eqt[mp]->Column(col_num_unrealized_capital_gains_before_sales).Value(t);

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;  

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     0.0,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell; 

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		book_sold
		= book_value_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		if (sell_assets == YES)
			{
			asset->sm_eqt[mp]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
			asset->sm_eqt[mp]->Column(col_num_portion_of_asset_sold_sales).Value(t);
			asset->sm_eqt[mp]->sold_pct_neg_cash_flow_value = 0.0;

			market_sold
			= market_value_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			unrealized_capital_gain_released
			= unrealized_capital_gains_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, 0.0, // accrued_sold
					market_sold, unrealized_capital_gain_released);
			}
		else
			{
			expected_sold_at_bk
			+= book_sold;

			sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
			+= book_sold;
			}

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_eqt[mp]->sequence_id,
					asset->sm_eqt[mp]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, 0.0, // accrued_sold
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					0);
			}

		percent_of_asset_to_sell = 0.0;
		} // end for on mp
	#endif

	#if defined(__EIO_ASSET_H_)
	// loop over index options
	if (seg_element->eio_mp_map_active.size())
		{
		col_num_asset_sub_port_num
		= asset->sm_eio[0][0]->Column("sub_port_id").Number();
		col_num_include_in_duration_matching
		= asset->sm_eio[0][0]->Column("dur_match_flag").Number();
		col_num_notional_amount
		= asset->sm_eio[0][0]->Column("notional_amt").Number();
		col_num_portion_of_asset_sold_planned_sales
		= asset->sm_eio[0][0]->Column("sold_pct_planned").Number();

		if (is_rebal_sales)
			{
			col_num_book_value_before_sales
			= asset->sm_eio[0][0]->Column("bk_val_bef_rebal_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_eio[0][0]->Column("mkt_val_bef_rebal_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_eio[0][0]->Column("notional_amt_bef_rebal_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_eio[0][0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_eio[0][0]->Column("unrealzd_cap_gain_bef_rebal_sale").Number();

			col_num_mkt_val_for_dur_bef_rebal_sale
			= asset->sm_eio[0][0]->Column("mkt_val_for_dur_bef_rebal_sale").Number();
			col_num_mkt_val_times_dur_bef_rebal_sale
			= asset->sm_eio[0][0]->Column("mkt_val_times_dur_bef_rebal_sale").Number();
			}
		else // negative cash flow sales
			{
			col_num_book_value_before_sales
			= asset->sm_eio[0][0]->Column("bk_val_bef_neg_cash_flow_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_eio[0][0]->Column("mkt_val_bef_neg_cash_flow_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_eio[0][0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_eio[0][0]->Column("sold_pct_neg_cash_flow").Number();
			col_num_portion_of_asset_sold_rebal_sales
			= asset->sm_eio[0][0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_eio[0][0]->Column("unrealzd_cap_gain_bef_neg_cash_flow_sale").Number();
			}
		}

	for (mp_map_iter = seg_element->eio_mp_map_active.begin();
		 mp_map_iter != seg_element->eio_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (asset->sm_eio[mp][0]->neg_asset_flag < 0)
			continue;

		if ((t > max(0, asset->sm_eio[mp][0]->commencement_period)
			 && asset->sm_eio[mp][0]->Column(col_num_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			|| (t == asset->sm_eio[mp][0]->commencement_period
				&& asset->sm_eio[mp][0]->Column(col_num_notional_amount_before_sales).Value(t) < ASSET_ACTIVE_THRESHOLD))
			continue;

		sub_port_num = xint(asset->sm_eio[mp][0]->Column(col_num_asset_sub_port_num).Value(t));
		sales_class_num = asset->sm_eio[mp][0]->sale_class_id;
		asset_fund_index = asset->sm_eio[mp][0]->asset_fund_index;
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

		if (current_sub_port->sub_ports_to_sell != 1
			|| asset_class_to_sell_flag[sales_class_num] != 1
			|| asset_fund_to_sell_flag[asset_fund_index] != 1)
			continue;

		asset_percent_remaining
		= (1.0 - asset->sm_eio[mp][0]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

		if (is_negative_cash_flow_sales)
			continue;//Hedge should not be sold to cover negative cash flows

		if (asset_percent_remaining < SMALL_DOUBLE)
			continue;

		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_eio[mp][0]->pct_to_use;

		book_value_available
		= asset->sm_eio[mp][0]->Column(col_num_book_value_before_sales).Value(t);
		market_value_available
		= asset->sm_eio[mp][0]->Column(col_num_market_value_before_sales).Value(t);
		unrealized_capital_gains_available
		= asset->sm_eio[mp][0]->Column(col_num_unrealized_capital_gains_before_sales).Value(t);

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     0.0,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		book_sold = book_value_available
				    * local_pct_to_use
				    * percent_of_asset_to_sell;

		if (sell_assets == YES)
			{
			asset->sm_eio[mp][0]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
			asset->sm_eio[mp][0]->Column(col_num_portion_of_asset_sold_sales).Value(t);
			asset->sm_eio[mp][0]->sold_pct_neg_cash_flow_value = 0.0;

			market_sold
			= market_value_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			unrealized_capital_gain_released
			= unrealized_capital_gains_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, 0.0, // accrued_sold
					market_sold, unrealized_capital_gain_released);
			}
		else
			{
			expected_sold_at_bk
			+= book_sold;

			sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
			+= book_sold;
			}

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_eio[mp][0]->sequence_id,
					asset->sm_eio[mp][0]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, 0.0, // accrued_sold
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					asset->sm_eio[mp][0]->dur_val(t));
			}

		percent_of_asset_to_sell = 0.0;
		} // end for on index options 
	#endif

	#if defined(__EPA_ASSET_H_)
	// loop over epas
	if (seg_element->epa_mp_map_active.size())
		{
		col_num_asset_sub_port_num
		= asset->sm_epa[0]->Column("sub_port_id").Number();
		col_num_include_in_duration_matching
		= asset->sm_epa[0]->Column("dur_match_flag").Number();
		col_num_notional_amount
		= asset->sm_epa[0]->Column("notional_amt").Number();
		col_num_portion_of_asset_sold_planned_sales
		= asset->sm_epa[0]->Column("sold_pct_planned").Number();

		if (is_rebal_sales)
			{
			col_num_accrued_interest_before_sales
			= asset->sm_epa[0]->Column("accr_int_bef_rebal_sale").Number();
			col_num_book_value_before_sales
			= asset->sm_epa[0]->Column("bk_val_bef_rebal_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_epa[0]->Column("mkt_val_bef_rebal_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_epa[0]->Column("notional_amt_bef_rebal_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_epa[0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_epa[0]->Column("unrealzd_cap_gain_bef_rebal_sale").Number();

			col_num_mkt_val_for_dur_bef_rebal_sale
			= asset->sm_epa[0]->Column("mkt_val_for_dur_bef_rebal_sale").Number();
			col_num_mkt_val_times_dur_bef_rebal_sale
			= asset->sm_epa[0]->Column("mkt_val_times_dur_bef_rebal_sale").Number();
			}
		else // negative cash flow sales
			{
			col_num_accrued_interest_before_sales
			= asset->sm_epa[0]->Column("accr_int_bef_neg_cash_flow_sale").Number();
			col_num_book_value_before_sales
			= asset->sm_epa[0]->Column("bk_val_bef_neg_cash_flow_sale").Number();
			col_num_market_value_before_sales
			= asset->sm_epa[0]->Column("mkt_val_bef_neg_cash_flow_sale").Number();
			col_num_notional_amount_before_sales
			= asset->sm_epa[0]->Column("notional_amt_bef_neg_cash_flow_sale").Number();
			col_num_portion_of_asset_sold_sales
			= asset->sm_epa[0]->Column("sold_pct_neg_cash_flow").Number();
			col_num_portion_of_asset_sold_rebal_sales
			= asset->sm_epa[0]->Column("sold_pct_rebal").Number();
			col_num_unrealized_capital_gains_before_sales
			= asset->sm_epa[0]->Column("unrealzd_cap_gain_bef_neg_cash_flow_sale").Number();
			}
		}

	for (mp_map_iter = seg_element->epa_mp_map_active.begin();
		 mp_map_iter != seg_element->epa_mp_map_active.end();
		 mp_map_iter++)
		{
		mp = mp_map_iter->first;

		if (asset->sm_epa[mp]->neg_asset_flag < 0)
			continue;

		if (asset->sm_epa[mp]->Column(col_num_notional_amount).Value(t - 1) < ASSET_ACTIVE_THRESHOLD)
			continue;

		sub_port_num = xint(asset->sm_epa[mp]->Column(col_num_asset_sub_port_num).Value(t));
		sales_class_num = asset->sm_epa[mp]->sale_class_id;
		asset_fund_index = asset->sm_epa[mp]->asset_fund_index;
		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];

		if (current_sub_port->sub_ports_to_sell != 1
			|| asset_class_to_sell_flag[sales_class_num] != 1
			|| asset_fund_to_sell_flag[asset_fund_index] != 1)
			continue;

		asset_percent_remaining
		= (1.0 - asset->sm_epa[mp]->Column(col_num_portion_of_asset_sold_planned_sales).Value(t));

		if (is_negative_cash_flow_sales)
			asset_percent_remaining
			*= (1.0 - asset->sm_epa[mp]->Column(col_num_portion_of_asset_sold_rebal_sales).Value(t));

		if (asset_percent_remaining < SMALL_DOUBLE)
			continue;

		current_sub_port = asset->sm_asset_sub_port[seg_num][sub_port_num][0];
		local_pct_to_use = asset->sm_epa[mp]->pct_to_use;

		book_value_available
		= asset->sm_epa[mp]->Column(col_num_book_value_before_sales).Value(t);
		accrued_interest_available
		= asset->sm_epa[mp]->Column(col_num_accrued_interest_before_sales).Value(t);
		market_value_available
		= asset->sm_epa[mp]->Column(col_num_market_value_before_sales).Value(t);
		unrealized_capital_gains_available
		= asset->sm_epa[mp]->Column(col_num_unrealized_capital_gains_before_sales).Value(t);

		if (fabs(book_value_available
				 * local_pct_to_use
				 * (1.0 - pct_to_sell_prelim))
			 >= current_sub_port->min_size_existing)
			percent_of_asset_to_sell  
			= pct_to_sell_prelim;
		else
			percent_of_asset_to_sell = 1.0;

		net_cash_from_asset_sale
		= expected_sale_cash(book_value_available,
		                     accrued_interest_available,
		                     market_value_available,
		                     unrealized_capital_gains_available,
		                     capital_gains_cash_factor_for_sales)
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		net_cash_from_sales
		+= net_cash_from_asset_sale;

		book_sold = book_value_available
				    * local_pct_to_use
				    * percent_of_asset_to_sell;

		accrued_sold
		= accrued_interest_available
		  * local_pct_to_use
		  * percent_of_asset_to_sell;

		if (sell_assets == YES)
			{
			asset->sm_epa[mp]->sold_pct_neg_cash_flow_value = percent_of_asset_to_sell;
			asset->sm_epa[mp]->Column(col_num_portion_of_asset_sold_sales).Value(t);
			asset->sm_epa[mp]->sold_pct_neg_cash_flow_value = 0.0;

			market_sold
			= market_value_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			unrealized_capital_gain_released
			= unrealized_capital_gains_available
			  * local_pct_to_use
			  * percent_of_asset_to_sell;

			accumulate_asset_sale(sub_port_num,
					sales_class_num, asset_fund_index,
					book_sold, accrued_sold,
					market_sold, unrealized_capital_gain_released);
			}
		else
			{
			expected_sold_at_bk
			+= book_sold + accrued_sold;

			sub_port_fund_expected_book_plus_accrued_sold[sub_port_num][asset_fund_index]
			+= book_sold + accrued_sold;

			if (asset->sm_epa[mp]->neg_asset_flag > 0)
				{
				expected_mkt_val_for_dur_sale
				+= asset->sm_epa[mp]->mkt_val_for_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;

				expected_mkt_val_times_dur_sale
				+= asset->sm_epa[mp]->mkt_val_times_dur_bef_rebal_sale(t)
				   * local_pct_to_use
				   * percent_of_asset_to_sell;
				}
			}

		if (asset->asset_detail_rpt_inv_strat_flag(t))
			{
			if (sell_assets != YES)
				{
				market_sold
				= market_value_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;

				unrealized_capital_gain_released
				= unrealized_capital_gains_available
				  * local_pct_to_use
				  * percent_of_asset_to_sell;
				}

			capital_gain = market_sold - book_sold;

			asset_detail_rpt_individual_sale(t, ASSET_DATA,
					asset->sm_epa[mp]->sequence_id,
					asset->sm_epa[mp]->asset_id,
					sub_port_num, sales_class_num, asset_fund_index,
					percent_of_asset_to_sell,
					net_cash_from_asset_sale,
					book_sold, accrued_sold,
					market_sold, capital_gain,
					unrealized_capital_gain_released,
					asset->sm_epa[mp]->dur_val(t));
			}

		percent_of_asset_to_sell = 0.0;
		} // end for on epa 
	#endif
	} // endif remaining_cash_required > 0.0

return net_cash_from_sales;
}



#line 1 "set_asset_defn.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::set_asset_defn(StrEnum::EnumValue strategy_type)
{
// Valid strategy_type values are
// "Investment"
// "Hedging"

map <xstring, int, less<xstring> >::iterator purchmap_iter;
xstring purchmap_index;
xstring asset_sub_port_name;
int panum;
int row;
int count = 0;

if (initialize_purch_asset_maps)
	{
	//initialize_purch_asset_maps = false;
	set_purch_asset_maps();
	}

for (panum = 0; panum < purch_asset_max_num; panum++)
	{
	purch_assets_asset_sub_port_num[panum] = -1; // -1 is used in an edit check later
	purch_assets_weight[panum] = 0.0;
	}

count = 0;

#if defined(__BOND_ASSET_H_)
for (row = 0; row < purch_bond_assets.size(); row++)
	{
	// Set lookup key
	purch_asset_id = purch_bond_assets[row];

	purchmap_index
	= get_string_of_enum_val(purch_assets_type[count])
	+ ":" + purch_asset_id;

	if (strategy_type == INVESTMENT
		&& ((purchmap_iter = purchmap_investment.find(purchmap_index))
			 != purchmap_investment.end()))
		{ // Lookup key is purch_asset_id
		inv_strat_id = inv_strat_id;
		purch_asset_id = purch_bond_assets[row];
		asset_sub_port_name = purch_asset_sub_port_id;

		if ((asset->asset_sub_port_map_iter = asset->asset_sub_port_map.find(asset_sub_port_name))
			 != asset->asset_sub_port_map.end())
			{
			panum = purchmap_iter->second;
			purch_assets_asset_sub_port_num[panum] = asset->asset_sub_port_map_iter->second;				
			
			inv_strat_id = inv_strat_id;
			purch_asset_id = purch_bond_assets[row];
			purch_assets_weight[panum] = purch_asset_weight;
			}
		} // end "Investment"

	count += 1;
	}
#endif
#if defined(__MTG_ASSET_H_)
for (row = 0; row < purch_mtg_assets.size(); row++)
	{
	// Set lookup key
	purch_asset_id = purch_mtg_assets[row];

	purchmap_index
	= get_string_of_enum_val(purch_assets_type[count])
	+ ":" + purch_asset_id;

	if (strategy_type == INVESTMENT
		&& ((purchmap_iter = purchmap_investment.find(purchmap_index))
			 != purchmap_investment.end()))
		{ // Lookup key is purch_asset_id
		inv_strat_id = inv_strat_id;
		purch_asset_id = purch_asset_id;
		asset_sub_port_name = purch_asset_sub_port_id;

		if ((asset->asset_sub_port_map_iter = asset->asset_sub_port_map.find(asset_sub_port_name))
			 != asset->asset_sub_port_map.end())
			{
			panum = purchmap_iter->second;
			purch_assets_asset_sub_port_num[panum] = asset->asset_sub_port_map_iter->second;				

			inv_strat_id = inv_strat_id;
			purch_asset_id = purch_asset_id;
			purch_assets_weight[panum] = purch_asset_weight;
			}
		} // end "Investment"
	
	count += 1;
	}
#endif
#if defined(__SEC_ASSET_H_)
for (row = 0; row < purch_sec_assets.size(); row++)
	{
	// Set lookup key
	purch_asset_id = purch_sec_assets[row];

	purchmap_index
	= get_string_of_enum_val(purch_assets_type[count])
	+ ":" + purch_asset_id;

	if (strategy_type == INVESTMENT
		&& ((purchmap_iter = purchmap_investment.find(purchmap_index))
			 != purchmap_investment.end()))
		{ // Lookup key is purch_asset_id
		asset_sub_port_name = purch_asset_sub_port_id;

		if ((asset->asset_sub_port_map_iter = asset->asset_sub_port_map.find(asset_sub_port_name))
			 != asset->asset_sub_port_map.end())
			{
			panum = purchmap_iter->second;
			purch_assets_asset_sub_port_num[panum] = asset->asset_sub_port_map_iter->second;				
			purch_assets_weight[panum] = purch_asset_weight;
			}
		} // end "Investment"
	
	count += 1;
	}
#endif
#if defined(__IRD_ASSET_H_)
for (row = 0; row < purch_ird_assets.size(); row++)
	{
	// Set lookup key
	purch_asset_id = purch_ird_assets[row];

	purchmap_index
	= get_string_of_enum_val(purch_assets_type[count])
	+ ":" + purch_asset_id;

	if (strategy_type == INVESTMENT
		&& ((purchmap_iter = purchmap_investment.find(purchmap_index))
			 != purchmap_investment.end()))
		{ // Lookup key is purch_asset_id
		inv_strat_id = inv_strat_id;
		purch_asset_id = purch_asset_id;
		asset_sub_port_name = purch_asset_sub_port_id;

		if ((asset->asset_sub_port_map_iter = asset->asset_sub_port_map.find(asset_sub_port_name))
			 != asset->asset_sub_port_map.end())
			{
			panum = purchmap_iter->second;
			purch_assets_asset_sub_port_num[panum] = asset->asset_sub_port_map_iter->second;		
			
			inv_strat_id = inv_strat_id;
			purch_asset_id = purch_asset_id;
			purch_assets_weight[panum] = purch_asset_weight;
			}
		} // end "Investment"

	if (strategy_type == HEDGING
		&& ((purchmap_iter = purchmap_hedging.find(purchmap_index))
			 != purchmap_hedging.end()))
		{ // Lookup key is purch_asset_id
		// Since there is no table mapping hedging assets to purchase asset sub portfolios,	
		// must assign purchase asset to asset sub portfolios to find number
		panum = purchmap_iter->second;

		purch_asset_id = purch_asset_id;
		purch_assets_asset_sub_port_num[panum]
		= asset->asset_sub_port_assign(0, 1 /*new_asset*/, "Interest Rate Derivative", HEDGING,
		                               purch_ird_category_id, 0, 0, -1);   
		} // end "Hedging"
	
	count += 1;
	}
#endif
#if defined(__RE_ASSET_H_)
for (row = 0; row < purch_re_assets.size(); row++)
	{
	// Set lookup key
	purch_asset_id = purch_re_assets[row];

	purchmap_index
	= get_string_of_enum_val(purch_assets_type[count])
	+ ":" + purch_asset_id;

	if (strategy_type == INVESTMENT
		&& ((purchmap_iter = purchmap_investment.find(purchmap_index))
			 != purchmap_investment.end()))
		{ // Lookup key is purch_asset_id
		asset_sub_port_name = purch_asset_sub_port_id;

		if ((asset->asset_sub_port_map_iter = asset->asset_sub_port_map.find(asset_sub_port_name))
			 != asset->asset_sub_port_map.end())
			{
			panum = purchmap_iter->second;
			purch_assets_asset_sub_port_num[panum] = asset->asset_sub_port_map_iter->second;				
			purch_assets_weight[panum] = purch_asset_weight;
			}
		} // end "Investment"
	
	count += 1;
	}
#endif
#if defined(__EQT_ASSET_H_)
for (row = 0; row < purch_eqt_assets.size(); row++)
	{
	// Set lookup key
	purch_asset_id = purch_eqt_assets[row];

	purchmap_index
	= get_string_of_enum_val(purch_assets_type[count])
	+ ":" + purch_asset_id;

	if (strategy_type == INVESTMENT
		&& ((purchmap_iter = purchmap_investment.find(purchmap_index))
			 != purchmap_investment.end()))
		{ // Lookup key is purch_asset_id
		asset_sub_port_name = purch_asset_sub_port_id;

		if ((asset->asset_sub_port_map_iter = asset->asset_sub_port_map.find(asset_sub_port_name))
			 != asset->asset_sub_port_map.end())
			{
			panum = purchmap_iter->second;
			purch_assets_asset_sub_port_num[panum] = asset->asset_sub_port_map_iter->second;				
			purch_assets_weight[panum] = purch_asset_weight;
			}
		} // end "Investment"
	
	count += 1;
	}
#endif
#if defined(__EIO_ASSET_H_)
for (row = 0; row < purch_eio_assets.size(); row++)
	{
	// Set lookup key
	purch_asset_id = purch_eio_assets[row];

	purchmap_index
	= get_string_of_enum_val(purch_assets_type[count])
	+ ":" + purch_asset_id;

	if (strategy_type == INVESTMENT
		&& ((purchmap_iter = purchmap_investment.find(purchmap_index))
			 != purchmap_investment.end()))
		{ // Lookup key is purch_asset_id
		inv_strat_id = inv_strat_id;
		purch_asset_id = purch_asset_id;
		asset_sub_port_name = purch_asset_sub_port_id;

		if ((asset->asset_sub_port_map_iter = asset->asset_sub_port_map.find(asset_sub_port_name))
			 != asset->asset_sub_port_map.end())
			{
			panum = purchmap_iter->second;
			purch_assets_asset_sub_port_num[panum] = asset->asset_sub_port_map_iter->second;				

			inv_strat_id = inv_strat_id;
			purch_asset_id = purch_asset_id;
			purch_assets_weight[panum] = purch_asset_weight;
			}
		} // end "Investment"

	if (strategy_type == HEDGING
		&& ((purchmap_iter = purchmap_hedging.find(purchmap_index))
			 != purchmap_hedging.end()))
		{ // Lookup key is purch_asset_id
		// Since there is no table mapping hedging assets to purchase asset sub portfolios,	
		// must assign purchase asset to asset sub portfolios to find number
		panum = purchmap_iter->second;
		purch_asset_id = purch_asset_id;
		purch_assets_asset_sub_port_num[panum]
		= asset->asset_sub_port_assign(0, 1 /*new_asset*/, "Index Option", HEDGING,
		                               purch_eio_category_id, 0, 0, -1);   
		} // end "Hedging"
	
	count += 1;
	}
#endif

return;
}



#line 1 "set_purch_asset_defn.INVSTRAT_ASSET.for"                                                                                   
int INVSTRAT_ASSET::set_purch_asset_defn(int panum, int mp_num, StrEnum::EnumValue type, const xstring &identifier, StrEnum::EnumValue pmt_mode, double yrs_to_maturity, int mths_to_first_reset)
{
// panum = purchase asset map index (0, 1, ...)
// type = Bond, Mortgage, Securitized Asset, Interest Rate Derivative, Equity, Real Estate, or Index Option.
// identifier = purchase asset ID
// port_defn = Investment, Hedging, or Collateral Pool

//xstring asset_sub_port_name = "";
int asset_sub_port_num = 0;
xstring map_index = "";
xstring type_string = get_string_of_enum_val(type);

// Lookup key is purch_asset_id
switch (type)
	{
	case BOND:
		purch_asset_id = purch_assets_id[panum] = identifier;
		purch_assets_mp_grp_tag[panum] = purch_bond_grp_id;
		purch_asset_id = purch_assets_id[panum] = identifier;
		purch_assets_port_defn[panum] = purch_bond_port_defn;
		break;
	case MORTGAGE:
		purch_asset_id = purch_assets_id[panum] = identifier;
		purch_assets_mp_grp_tag[panum] = purch_mtg_grp_id;
		purch_asset_id = purch_assets_id[panum] = identifier;
		purch_assets_port_defn[panum] = purch_mtg_port_defn;
		break;
	case SECURITIZED_ASSET:
		purch_asset_id = purch_assets_id[panum] = identifier;
		purch_assets_mp_grp_tag[panum] = purch_sec_grp_id;
		purch_assets_port_defn[panum] = INVESTMENT;
		break;
	case INTEREST_RATE_DERIVATIVE:
		purch_asset_id = purch_assets_id[panum] = identifier;
		purch_assets_mp_grp_tag[panum] = purch_ird_grp_id;
		purch_asset_id = purch_assets_id[panum] = identifier;
		purch_assets_port_defn[panum] = purch_ird_port_defn;
		break;
	case REAL_ESTATE:
		purch_asset_id = purch_assets_id[panum] = identifier;
		purch_assets_mp_grp_tag[panum] = purch_re_grp_id;
		purch_assets_port_defn[panum] = INVESTMENT;
		break;
	case EQUITY:
		purch_asset_id = purch_assets_id[panum] = identifier;
		purch_assets_mp_grp_tag[panum] = purch_eqt_grp_id;
		purch_assets_port_defn[panum] = INVESTMENT;
		break;
	case INDEX_OPTION:
		purch_asset_id = purch_assets_id[panum] = identifier;
		purch_assets_mp_grp_tag[panum] = purch_eio_grp_id;
		purch_asset_id = purch_assets_id[panum] = identifier;
		purch_assets_port_defn[panum] = purch_eio_port_defn;
		break;
	default:
		type_string = "Unknown";
	}

purch_assets_type[panum] = type;
purch_assets_mp_num[panum] = mp_num;
purch_assets_weight[panum] = 0.0; // Will be set by investment strategy
purch_assets_mths_to_maturity[panum] = min(yrs_to_maturity, MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;
	
// Duration matching is not available for some asset types
if ((type == BOND || type == MORTGAGE || type == SECURITIZED_ASSET)
	 && asset->sm_asset_sub_port[seg_num][asset_sub_port_num][0]->dur_match_defn == YES)
	purch_assets_dur_defn[panum] = YES;
else
	purch_assets_dur_defn[panum] = NO;

// Check that payment mode is consistent with years to maturity.
if (type == BOND || type == MORTGAGE || type == INTEREST_RATE_DERIVATIVE)
	{
	int mths_to_maturity
	= min(yrs_to_maturity, MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS) * 12;

	if (((double)((int) (12 * yrs_to_maturity))) != (12 * yrs_to_maturity))
		mths_to_maturity += 1;

	int pmt_freq
	= (pmt_mode == MONTHLY ? 12
	  : (pmt_mode == QUARTERLY ? 4
	  : (pmt_mode == SEMI_ANNUAL ? 2
	  : (pmt_mode == ANNUAL ? 1 : 0))));

	int mths_per_pmt_period
	= 12 / pmt_freq;

	int excess_months
	= (mths_to_maturity - mths_to_first_reset)
	  % mths_per_pmt_period;

	if (excess_months > 0)
		{
		static bool issue_warning_pmt_freq_vs_maturity_period = true;

		if (issue_warning_pmt_freq_vs_maturity_period)
			{
			issue_warning_pmt_freq_vs_maturity_period  = false;
			log_screen << "Warning. The payment mode of some investment bond, mortgage or"
					<< " interest rate derivative is incompatible with its years to maturity."
					<< MSG_ERROR;
			log_screen << " ... For example, the investment " << type_string
					<< " with identifier '" << identifier
					<< "' has a payment mode of '"
					<< get_string_of_enum_val(pmt_mode)
					<< "' with " << setprecision(3) << yrs_to_maturity
					<< " years to maturity."
					<< MSG_ERROR;			
			}
		}
	}

// Set investment, hedging, and collateral pool purchase asset maps
map_index = type_string + ":" + identifier;

if (purch_assets_port_defn[panum] == INVESTMENT)
	purchmap_investment[map_index] = panum;
else if (purch_assets_port_defn[panum] == HEDGING)
	purchmap_hedging[map_index] = panum;

return 1;
}



#line 1 "set_purch_asset_maps.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::set_purch_asset_maps()
{
// This function fills purchase asset vectors
if (!initialize_purch_asset_maps) // Only perform this action once
	return;

initialize_purch_asset_maps = false;

map <xstring, int, less<xstring> >::iterator purchmap_iter;
	
// Create purchase asset vectors
purch_bond_assets.resize(0);
purch_mtg_assets.resize(0);
purch_sec_assets.resize(0);
purch_ird_assets.resize(0);
purch_re_assets.resize(0);
purch_eqt_assets.resize(0);
purch_eio_assets.resize(0);

#if defined(__BOND_ASSET_H_)
{
seg_id = seg_id;
xstring purch_bond_assets_selected_local = purch_bond_assets_selected;

if (purch_bond_assets_selected_local != "NONE")
	split_string_usl(purch_bond_assets_selected_local.c_str(), purch_bond_assets, ",");
}
#endif
{
#if defined(__MTG_ASSET_H_)
seg_id = seg_id;
xstring purch_mtg_assets_selected_local = purch_mtg_assets_selected;

if (purch_mtg_assets_selected_local != "NONE")
	split_string_usl(purch_mtg_assets_selected_local.c_str(), purch_mtg_assets, ",");
#endif
}
{
#if defined(__SEC_ASSET_H_)
if (purch_sec_assets_selected != "NONE")
	split_string_usl(purch_sec_assets_selected.c_str(), purch_sec_assets, ",");
#endif
}
{
#if defined(__IRD_ASSET_H_)
seg_id = seg_id;
xstring purch_ird_assets_selected_local = purch_ird_assets_selected;

if (purch_ird_assets_selected_local != "NONE")
	split_string_usl(purch_ird_assets_selected_local.c_str(), purch_ird_assets, ",");
#endif
}
{
#if defined(__RE_ASSET_H_)
if (purch_re_assets_selected != "NONE")
	split_string_usl(purch_re_assets_selected.c_str(), purch_re_assets, ",");
#endif
}
{
#if defined(__EQT_ASSET_H_)
if (purch_eqt_assets_selected != "NONE")
	split_string_usl(purch_eqt_assets_selected.c_str(), purch_eqt_assets, ",");
#endif
}
{
#if defined(__EIO_ASSET_H_)
seg_id = seg_id;
xstring purch_eio_assets_selected_local = purch_eio_assets_selected;

if (purch_eio_assets_selected_local != "NONE")
	split_string_usl(purch_eio_assets_selected_local.c_str(), purch_eio_assets, ",");
#endif
}

purch_asset_max_num
= purch_bond_assets.size()
  + purch_mtg_assets.size()
  + purch_sec_assets.size()
  + purch_ird_assets.size()
  + purch_re_assets.size()
  + purch_eqt_assets.size()
  + purch_eio_assets.size();

int panum = 0; // First purchase asset is zero element of the arrays
int mp = 0;
xstring asset_sub_port_name = "";
int asset_sub_port_num = 0;
bool found = false;
xstring map_index = "";
xstring type_string = "";
bool errors = false;
xstring message = "";

// Size purchase assets arrays
purch_assets_type.resize(purch_asset_max_num); 
purch_assets_id.resize(purch_asset_max_num); 
purch_assets_mp_grp_tag.resize(purch_asset_max_num);
purch_assets_mp_num.resize(purch_asset_max_num);
purch_assets_port_defn.resize(purch_asset_max_num);
purch_assets_dur_defn.resize(purch_asset_max_num);
purch_assets_dur_calculated.resize(purch_asset_max_num);
purch_assets_dur.resize(purch_asset_max_num);
purch_assets_sub_port_num_current_strat.resize(purch_asset_max_num);
purch_assets_asset_sub_port_num.resize(purch_asset_max_num);
purch_assets_weight.resize(purch_asset_max_num);
purch_assets_weight_current_strat.resize(purch_asset_max_num);
purch_assets_sub_port_num_alt_strat.resize(purch_asset_max_num);
purch_assets_weight_alt_strat.resize(purch_asset_max_num);
purch_assets_mths_to_maturity.resize(purch_asset_max_num);

// Loop over purchase bond assets
#if defined(__BOND_ASSET_H_)
for (mp = 1; mp <= purch_bond_assets.size(); mp++)
	{
	purch_asset_id = purch_bond_assets[mp - 1];
	int purch_bond_yrs_to_maturity_local = purch_bond_yrs_to_maturity;
	purch_asset_id = purch_bond_assets[mp - 1];
	StrEnum::EnumValue purch_bond_pmt_mode_local = purch_bond_pmt_mode;
	
	panum += set_purch_asset_defn(panum, mp, BOND, purch_asset_id, 
								  purch_bond_pmt_mode_local, purch_bond_yrs_to_maturity_local, 0);
	}
#endif
#if defined(__MTG_ASSET_H_)
for (mp = 1; mp <= purch_mtg_assets.size(); mp++)
	{
	purch_asset_id = purch_mtg_assets[mp - 1];
	int purch_mtg_yrs_to_maturity_local = purch_mtg_yrs_to_maturity;
	purch_asset_id = purch_mtg_assets[mp - 1];
	StrEnum::EnumValue purch_mtg_pmt_mode_local = purch_mtg_pmt_mode;

	panum += set_purch_asset_defn(panum, mp, MORTGAGE, purch_asset_id, 
								  purch_mtg_pmt_mode_local, purch_mtg_yrs_to_maturity_local, 0);
	}
#endif
#if defined(__SEC_ASSET_H_)
for (mp = 1; mp <= purch_sec_assets.size(); mp++)
	{
	purch_asset_id = purch_sec_assets[mp - 1];
	panum += set_purch_asset_defn(panum, mp, SECURITIZED_ASSET, purch_asset_id, 
								  UNDEFINED, 0.0, 0);	 
	}
#endif
#if defined(__IRD_ASSET_H_) 
for (mp = 1; mp <= purch_ird_assets.size(); mp++)
	{
	purch_asset_id = purch_ird_assets[mp - 1];
	int purch_ird_yrs_to_maturity_local = purch_ird_yrs_to_maturity;
	purch_asset_id = purch_ird_assets[mp - 1];
	StrEnum::EnumValue purch_ird_rate_1_pmt_mode_local = purch_ird_rate_1_pmt_mode;
	purch_asset_id = purch_ird_assets[mp - 1];
	int purch_ird_mths_to_first_reset_local = purch_ird_mths_to_first_reset;

	purch_asset_id = purch_ird_assets[mp - 1];
	panum += set_purch_asset_defn(panum, mp, INTEREST_RATE_DERIVATIVE, purch_asset_id, 
	                              purch_ird_rate_1_pmt_mode_local, purch_ird_yrs_to_maturity_local, purch_ird_mths_to_first_reset_local);	 
	}
#endif
#if defined(__RE_ASSET_H_)
for (mp = 1; mp <= purch_re_assets.size(); mp++)
	{
	purch_asset_id = purch_re_assets[mp - 1];
	panum += set_purch_asset_defn(panum, mp, REAL_ESTATE, purch_asset_id,
	                              purch_re_pmt_mode, 0.0, 0);
	}
#endif
#if defined(__EQT_ASSET_H_)
for (mp = 1; mp <= purch_eqt_assets.size(); mp++)
	{
	purch_asset_id = purch_eqt_assets[mp - 1];
	panum += set_purch_asset_defn(panum, mp, EQUITY, purch_asset_id, 
	                              purch_eqt_pmt_mode, 0.0, 0);	 
	}
#endif
#if defined(__EIO_ASSET_H_) 
for (mp = 1; mp <= purch_eio_assets.size(); mp++)
	{
	purch_asset_id = purch_eio_assets[mp - 1];
	int purch_eio_yrs_to_maturity_local = purch_eio_yrs_to_maturity;

	panum += set_purch_asset_defn(panum, mp, INDEX_OPTION, purch_asset_id, 
	                              UNDEFINED, purch_eio_yrs_to_maturity_local, 0);	 
	}
#endif

// Write map to seg_element->SALFile
if (seg_element->SALFile)
	{
	seg_element->SALFile << endl
				 << "purchmap_investment size," << purchmap_investment.size() 
				 << endl;

	if (purchmap_investment.size() > 0)
		{
		seg_element->SALFile << endl
					 << "purchmap_investment summary:" << endl
					 << "model:id,purchmap_index,mths_to_maturity" << endl;

		for (purchmap_iter = purchmap_investment.begin();
			 purchmap_iter != purchmap_investment.end();
			 purchmap_iter++)
			seg_element->SALFile << purchmap_iter->first << ","
						 << purchmap_iter->second << ","
						 << purch_assets_mths_to_maturity[purchmap_iter->second]
						 << endl;
		}

	seg_element->SALFile << endl
				 << "purchmap_hedging size," << purchmap_hedging.size()
				 << endl;

	if (purchmap_hedging.size() > 0)
		{
		seg_element->SALFile << "purchmap_hedging summary:"
					 << endl
					 << "model:id,purchmap_index,mths_to_maturity"
					 << endl;
	
		for (purchmap_iter = purchmap_hedging.begin();
			 purchmap_iter != purchmap_hedging.end();
			 purchmap_iter++)
			seg_element->SALFile << purchmap_iter->first << ","
						 << purchmap_iter->second << ","
						 << purch_assets_mths_to_maturity[purchmap_iter->second]
						 << endl;
		}
	}

if (errors)
	throw FatalError("");

return;
}



#line 1 "write_bond_state_of_world_header_mp.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::write_bond_state_of_world_header_mp(void)
{
#if defined(__BOND_ASSET_H_)
static bool bond_header_first_time = true;

xstring data_file_name_local = replaceWildcards(asset->sm_bond[0][0]->data_file_name);

xstring bond_state_of_world_file
= xstring(data_file_name_local(0 , data_file_name_local.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

// Remove any old file
if (bond_header_first_time)
	{
	bond_header_first_time = false;

	struct stat buffer;
	int stat_val = stat(bond_state_of_world_file.c_str(), &buffer);

	// Delete existing file, so a new file can be created
	if (stat_val == 0)
		remove(bond_state_of_world_file);
	}
 
if (!bond_state_of_world_header_mp_output.is_open())
	{
   	bond_state_of_world_header_mp_output.setf(ios::fixed);
	bond_state_of_world_header_mp_output.precision(12);
	bond_state_of_world_header_mp_output.open(bond_state_of_world_file);

	// Write header
	bond_state_of_world_header_mp_output			// Values from inforce mp
	<< "group" << ","						// col 0 = get_base_group_name(group)
    << "seg_id_mp" << ","					// col 1 = seg_id
	<< "asset_id_mp" << ","					// col 2 = asset_id
	<< "use_mp" << ","						// col 3 = use_mp
	<< "category_id_mp" << ","				// col 4 = category_id
	<< "port_defn_mp" << ","				// col 5 = get_string_of_enum_val(port_defn)
	<< "sale_class_mp" << ","				// col 6 = get_string_of_enum_val(sale_class)
	<< "issue_date_mp" << ","				// col 7 = issue_date
	<< "maturity_date_mp" << ","			// col 8 = maturity_date
	<< "planned_sale_date_mp" << ","		// col 9 = planned_sale_date
	<< "init_par_val_mp" << ","				// col 10 = notional_amt(last_proj_period)
	<< "init_cost_basis_mp" << ","			// col 11 = cost_basis(last_proj_period)
	<< "init_bk_val_mp" << ","				// col 12 = bk_val(last_proj_period)
	<< "init_mkt_val_mp" << ","				// col 13 = mkt_val(last_proj_period)
	<< "pmt_mode_mp" << ","					// col 14 = get_string_of_enum_val(pmt_mode)
	<< "init_pmt_rate_mp" << ","			// col 15 = sm_bond_cf->pmt_rate(last_proj_period)
	<< "par_val_at_issue_mp" << ","			// col 16 = par_val_at_issue
	<< "taxable_pct_mp" << ","				// col 17 = taxable_pct
	<< "call_opt_first_date_mp" << ","		// col 18 = call_opt_first_date
	<< "call_price_defn_mp" << ","			// col 19 = get_string_of_enum_val(call_price_defn)
	<< "call_defn_mp" << ","				// col 20 = get_string_of_enum_val(call_defn)
	<< "yld_maint_addn_mp" << ","			// col 21 = yld_maint_addn
	<< "put_opt_first_date_mp" << ","		// col 22 = put_opt_first_date
	<< "put_defn_mp" << ","					// col 23 = get_string_of_enum_val(put_defn)
	<< "sinking_fund_defn_mp" << ","		// col 24 = get_string_of_enum_val(sinking_fund_defn)
	<< "adj_reset_category_id_mp" << ","	// col 25 = adj_reset_category_id
	<< "adj_reset_scen_yr_mp" << ","		// col 26 = adj_reset_scen_yr
	<< "adj_reset_scen_mult_mp" << ","		// col 27 = adj_reset_scen_mult
	<< "adj_reset_renewal_addn_mp" << ","	// col 28 = adj_reset_renewal_addn
	<< "adj_next_reset_date_mp" << ","		// col 29 = adj_next_reset_date
	<< "adj_reset_mths_mp" << ","			// col 30 = adj_reset_mths
	<< "adj_max_incr_per_reset_mp" << ","	// col 31 = adj_max_incr_per_reset
	<< "adj_max_decr_per_reset_mp" << ","	// col 32 = adj_max_decr_per_reset
	<< "adj_min_rate_mp" << ","				// col 33 = adj_min_rate
	<< "adj_max_rate_mp" << ","				// col 34 = adj_max_rate
	<< "avr_contribn_pct_mp" << ","			// col 35 = avr_contribn_pct
	<< "avr_max_pct_mp" << ","				// col 36 = avr_max_pct
	<< "avr_obj_pct_mp" << ","				// col 37 = avr_obj_pct
	<< "rbc_c1_pct_mp" << ","				// col 38 = rbc_c1_pct
	<< "unique_id_mp" << endl;				// col 39 = unique_id_mp
	}

bond_state_of_world_header_mp_output.close();
#endif

return;
}



#line 1 "write_eio_state_of_world_header_mp.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::write_eio_state_of_world_header_mp(void)
{
#if defined(__EIO_ASSET_H_)
static bool eio_header_first_time = true;

xstring data_file_name_local = replaceWildcards(asset->sm_eio[0][0]->data_file_name);

xstring eio_state_of_world_file
= xstring(data_file_name_local(0 , data_file_name_local.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

// Remove any old file
if (eio_header_first_time)
	{
	eio_header_first_time = false;

	struct stat buffer;
	int stat_val = stat(eio_state_of_world_file.c_str(), &buffer);

	// Delete existing file, so a new file can be created
	if (stat_val == 0)
		remove(eio_state_of_world_file);
	}
 
if (!eio_state_of_world_header_mp_output.is_open())
	{
   	eio_state_of_world_header_mp_output.setf(ios::fixed);
	eio_state_of_world_header_mp_output.precision(12);
	eio_state_of_world_header_mp_output.open(eio_state_of_world_file);

	// Write header
	eio_state_of_world_header_mp_output			// Values from inforce mp
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
	<< "rbc_c1_pct_mp" << ","					// col 30 = rbc_c1_pct
	<< "unique_id_mp" << endl;					// col 31 = unique_id_mp
	}

eio_state_of_world_header_mp_output.close();
#endif

return;
}



#line 1 "write_epa_state_of_world_header_mp.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::write_epa_state_of_world_header_mp(void)
{
#if defined(__EPA_ASSET_H_)
static bool epa_header_first_time = true;

xstring data_file_name_local = replaceWildcards(asset->sm_epa[0]->data_file_name);

xstring epa_state_of_world_file
= xstring(data_file_name_local(0 , data_file_name_local.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

// Remove any old file
if (epa_header_first_time)
	{
	epa_header_first_time = false;

	struct stat buffer;
	int stat_val = stat(epa_state_of_world_file.c_str(), &buffer);

	// Delete existing file, so a new file can be created
	if (stat_val == 0)
		remove(epa_state_of_world_file);
	}
 
if (!epa_state_of_world_header_mp_output.is_open())
	{
   	epa_state_of_world_header_mp_output.setf(ios::fixed);
	epa_state_of_world_header_mp_output.precision(12);
	epa_state_of_world_header_mp_output.open(epa_state_of_world_file);

	// Write header
	epa_state_of_world_header_mp_output			// Values from inforce mp
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
	<< "rbc_c1_pct_mp" << endl;				// col 38 = rbc_c1_pct
	}

epa_state_of_world_header_mp_output.close();
#endif

return;
}



#line 1 "write_eqt_state_of_world_header_mp.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::write_eqt_state_of_world_header_mp(void)
{
#if defined(__EQT_ASSET_H_)
static bool eqt_header_first_time = true;

xstring data_file_name = replaceWildcards(asset->sm_eqt[0]->data_location());

xstring eqt_state_of_world_file
= xstring(data_file_name(0 , data_file_name.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

// Remove any old file
if (eqt_header_first_time)
	{
	eqt_header_first_time = false;

	struct stat buffer;
	int stat_val = stat(eqt_state_of_world_file.c_str(), &buffer);

	// Delete existing file, so a new file can be created
	if (stat_val == 0)
		remove(eqt_state_of_world_file);
	}
 
if (!eqt_state_of_world_header_mp_output.is_open())
	{
   	eqt_state_of_world_header_mp_output.setf(ios::fixed);
	eqt_state_of_world_header_mp_output.precision(12);
	eqt_state_of_world_header_mp_output.open(eqt_state_of_world_file);

	// Write header
	eqt_state_of_world_header_mp_output			// Values from inforce mp
	<< "group" << ","					// col 0 = get_base_group_name(group)
    << "seg_id_mp" << ","				// col 1 = seg_id
	<< "asset_id_mp" << ","				// col 2 = asset_id
	<< "use_mp" << ","					// col 3 = use_mp
	<< "asset_index_mp" << ","			// col 4 = asset_index
	<< "category_id_mp" << ","			// col 5 = category_id
	<< "sale_class_mp" << ","			// col 6 = get_string_of_enum_val(sale_class)
	<< "planned_sale_date_mp" << ","	// col 7 = planned_sale_date
	<< "init_cost_basis_mp" << ","		// col 8 = cost_basis(last_proj_period)
	<< "init_bk_val_mp" << ","			// col 9 = bk_val(last_proj_period)
	<< "init_mkt_val_mp" << ","			// col 10 = mkt_val(last_proj_period)
	<< "mkt_growth_scen_mult_mp" << ","	// col 11 = mkt_growth_scen_mult
	<< "mkt_growth_addn_mp" << ","		// col 12 = mkt_growth_addn
	<< "init_div_yld_mp" << ","			// col 13 = init_div_yld
	<< "div_yld_scen_mult_mp" << ","	// col 14 = div_yld_scen_mult
	<< "div_yld_addn_mp" << ","			// col 15 = div_yld_addn
	<< "avr_contribn_pct_mp" << ","		// col 16 = avr_contribn_pct
	<< "avr_max_pct_mp" << ","			// col 17 = avr_max_pct
	<< "avr_obj_pct_mp" << ","			// col 18 = avr_obj_pct
	<< "rbc_c1_pct_mp" << endl;			// col 19 = rbc_c1_pct
	}

eqt_state_of_world_header_mp_output.close();
#endif

return;
}



#line 1 "write_ird_state_of_world_header_mp.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::write_ird_state_of_world_header_mp(void)
{
#if defined(__IRD_ASSET_H_)
static bool ird_header_first_time = true;

xstring data_file_name_local = replaceWildcards(asset->sm_ird[0][0]->data_file_name);

xstring ird_state_of_world_file
= xstring(data_file_name_local(0 , data_file_name_local.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

// Remove any old file
if (ird_header_first_time)
	{
	ird_header_first_time = false;

	struct stat buffer;
	int stat_val = stat(ird_state_of_world_file.c_str(), &buffer);

	// Delete existing file, so a new file can be created
	if (stat_val == 0)
		remove(ird_state_of_world_file);
	}
 
if (!ird_state_of_world_header_mp_output.is_open())
	{
   	ird_state_of_world_header_mp_output.setf(ios::fixed);
	ird_state_of_world_header_mp_output.precision(12);
	ird_state_of_world_header_mp_output.open(ird_state_of_world_file);

	// Write header
	ird_state_of_world_header_mp_output		// Values from inforce mp
	<< "group" << ","					// col 0 = get_base_group_name(group)
    << "seg_id_mp" << ","				// col 1 = seg_id
	<< "asset_id_mp" << ","				// col 2 = asset_id
	<< "use_mp" << ","					// col 3 = use_mp
	<< "hdg_grp_code_mp" << ","         // col 4 = hdg_grp_code
	<< "category_id_mp" << ","			// col 5 = category_id
	<< "port_defn_mp" << ","			// col 6 = get_string_of_enum_val(port_defn)
	<< "sale_class_mp" << ","			// col 7 = get_string_of_enum_val(sale_class)
	<< "maturity_date_mp" << ","		// col 8 = maturity_date
	<< "planned_sale_date_mp" << ","	// col 9 = planned_sale_date
	<< "init_notional_amt_mp" << ","	// col 10 = notional_amt(last_proj_period)
	<< "init_cost_basis_mp" << ","		// col 11 = cost_basis(last_proj_period)
	<< "init_bk_val_mp" << ","			// col 12 = bk_val(last_proj_period)
	<< "init_mkt_val_mp" << ","			// col 13 = mkt_val(last_proj_period)
	<< "rate_1_pmt_mode_mp" << ","		// col 14 = get_string_of_enum_val(rate_1_pmt_mode)
	<< "rate_2_pmt_mode_mp" << ","		// col 15 = get_string_of_enum_val(rate_2_pmt_mode)
	<< "pmt_defn_mp" << ","				// col 16 = get_string_of_enum_val(pmt_defn)
	<< "pmt_first_date_mp" << ","		// col 17 = pmt_first_date
	<< "rate_1_category_id_mp" << ","   // col 18 = rate_1_category_id
	<< "rate_1_scen_yr_mp" << ","		// col 19 = rate_1_scen_yr
	<< "rate_1_scen_mult_mp" << ","		// col 20 = rate_1_scen_mult
	<< "rate_1_addn_mp" << ","			// col 21 = rate_1_addn
	<< "rate_2_category_id_mp" << ","   // col 22 = rate_2_category_id
	<< "rate_2_scen_yr_mp" << ","		// col 23 = rate_2_scen_yr
	<< "rate_2_scen_mult_mp" << ","		// col 24 = rate_2_scen_mult
	<< "rate_2_addn_mp" << ","			// col 25 = rate_2_addn
	<< "avr_contribn_pct_mp" << ","		// col 26 = avr_contribn_pct
	<< "avr_max_pct_mp" << ","			// col 27 = avr_max_pct
	<< "avr_obj_pct_mp" << ","			// col 28 = avr_obj_pct
	<< "rbc_c1_pct_mp" << endl;			// col 29 = rbc_c1_pct
	}

ird_state_of_world_header_mp_output.close();
#endif

return;
}



#line 1 "write_mtg_state_of_world_header_mp.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::write_mtg_state_of_world_header_mp(void)
{
#if defined(__MTG_ASSET_H_)
static bool mtg_header_first_time = true;

xstring data_file_name_local = replaceWildcards(asset->sm_mtg[0][0]->data_file_name);

xstring mtg_state_of_world_file
= xstring(data_file_name_local(0 , data_file_name_local.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

// Remove any old file
if (mtg_header_first_time)
	{
	mtg_header_first_time = false;

	struct stat buffer;
	int stat_val = stat(mtg_state_of_world_file.c_str(), &buffer);

	// Delete existing file, so a new file can be created
	if (stat_val == 0)
		remove(mtg_state_of_world_file);
	}
 
if (!mtg_state_of_world_header_mp_output.is_open())
	{
   	mtg_state_of_world_header_mp_output.setf(ios::fixed);
	mtg_state_of_world_header_mp_output.precision(12);
	mtg_state_of_world_header_mp_output.open(mtg_state_of_world_file);

	// Write header
	mtg_state_of_world_header_mp_output			// Values from inforce mp
	<< "group" << ","						// col 0 = get_base_group_name(group)
    << "seg_id_mp" << ","					// col 1 = seg_id
	<< "asset_id_mp" << ","					// col 2 = asset_id
	<< "use_mp" << ","						// col 3 = use_mp
	<< "category_id_mp" << ","				// col 4 = category_id
	<< "port_defn_mp" << ","				// col 5 = get_string_of_enum_val(port_defn)
	<< "sale_class_mp" << ","				// col 6 = get_string_of_enum_val(sale_class)
	<< "issue_date_mp" << ","				// col 7 = issue_date
	<< "maturity_date_mp" << ","			// col 8 = maturity_date
	<< "amortzn_start_cy_mp" << ","			// col 9 = amortzn_start_cy
	<< "planned_sale_date_mp" << ","		// col 10 = planned_sale_date
	<< "init_par_val_mp" << ","				// col 11 = notional_amt(last_proj_period)
	<< "init_cost_basis_mp" << ","			// col 12 = cost_basis(last_proj_period)
	<< "init_bk_val_mp" << ","				// col 13 = bk_val(last_proj_period)
	<< "init_mkt_val_mp" << ","				// col 14 = mkt_val(last_proj_period)
	<< "pmt_mode_mp" << ","					// col 15 = get_string_of_enum_val(pmt_mode)
	<< "init_pmt_rate_mp" << ","			// col 16 = sm_mtg_cf->pmt_rate(last_proj_period)
	<< "servicing_fee_mp" << ","			// col 17 = servicing_fee
	<< "prin_val_at_issue_mp" << ","		// col 18 = prin_val_at_issue
	<< "prepmt_opt_first_date_mp" << ","	// col 19 = prepmt_opt_first_date
	<< "prepmt_penalty_defn_mp" << ","		// col 20 = get_string_of_enum_val(prepmt_penalty_defn)
	<< "balloon_defn_mp" << ","				// col 21 = balloon_pmt_defn
	<< "balloon_date_mp" << ","				// col 22 = balloon_date
	<< "yld_maint_addn_mp" << ","			// col 23 = yld_maint_addn
	<< "adj_reset_category_id_mp" << ","    // col 24 = adj_reset_category_id
	<< "adj_reset_scen_yr_mp" << ","		// col 25 = adj_reset_scen_yr
	<< "adj_reset_scen_mult_mp" << ","		// col 26 = adj_reset_scen_mult
	<< "adj_reset_renewal_addn_mp" << ","	// col 27 = adj_reset_renewal_addn
	<< "adj_next_reset_date_mp" << ","		// col 28 = adj_next_reset_date
	<< "adj_reset_mths_mp" << ","			// col 29 = adj_reset_mths
	<< "adj_max_incr_per_reset_mp" << ","	// col 30 = adj_max_incr_per_reset
	<< "adj_max_decr_per_reset_mp" << ","	// col 31 = adj_max_decr_per_reset
	<< "adj_min_rate_mp" << ","				// col 32 = adj_min_rate
	<< "adj_max_rate_mp" << ","				// col 33 = adj_max_rate
	<< "avr_contribn_pct_mp" << ","			// col 34 = avr_contribn_pct
	<< "avr_max_pct_mp" << ","				// col 35 = avr_max_pct
	<< "avr_obj_pct_mp" << ","				// col 36 = avr_obj_pct
	<< "rbc_c1_pct_mp" << ","				// col 37 = rbc_c1_pct
	<< "unique_id_mp" << endl;				// col 38 = unique_id_mp
	}

mtg_state_of_world_header_mp_output.close();
#endif

return;
}



#line 1 "write_re_state_of_world_header_mp.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::write_re_state_of_world_header_mp(void)
{
#if defined(__RE_ASSET_H_)
static bool re_header_first_time = true;

xstring data_file_name = replaceWildcards(asset->sm_re[0]->data_location());

xstring re_state_of_world_file
= xstring(data_file_name(0 , data_file_name.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

// Remove any old file
if (re_header_first_time)
	{
	re_header_first_time = false;

	struct stat buffer;
	int stat_val = stat(re_state_of_world_file.c_str(), &buffer);

	// Delete existing file, so a new file can be created
	if (stat_val == 0)
		remove(re_state_of_world_file);
	}
 
if (!re_state_of_world_header_mp_output.is_open())
	{
   	re_state_of_world_header_mp_output.setf(ios::fixed);
	re_state_of_world_header_mp_output.precision(12);
	re_state_of_world_header_mp_output.open(re_state_of_world_file);

	// Write header
	re_state_of_world_header_mp_output			// Values from inforce mp
	<< "group" << ","					// col 0 = get_base_group_name(group)
    << "seg_id_mp" << ","				// col 1 = seg_id
	<< "asset_id_mp" << ","				// col 2 = asset_id
	<< "use_mp" << ","					// col 3 = use_mp
	<< "asset_index_mp" << ","			// col 4 = asset_index
	<< "category_id_mp" << ","			// col 5 = category_id
	<< "sale_class_mp" << ","			// col 6 = get_string_of_enum_val(sale_class)
	<< "next_pmt_date_mp" << ","		// col 7 = next_pmt_date
	<< "planned_sale_date_mp" << ","	// col 8 = planned_sale_date
	<< "init_cost_basis_mp" << ","		// col 9 = cost_basis(last_proj_period)
	<< "init_bk_val_mp" << ","			// col 10 = bk_val(last_proj_period)
	<< "init_mkt_val_mp" << ","			// col 11 = mkt_val(last_proj_period)
	<< "pmt_mode_mp" << ","				// col 12 = get_string_of_enum_val(pmt_mode)
	<< "mkt_growth_scen_mult_mp" << ","	// col 13 = mkt_growth_scen_mult
	<< "mkt_growth_addn_mp" << ","		// col 14 = mkt_growth_addn
	<< "depreciation_yrs_mp" << ","		// col 15 = depreciation_yrs
	<< "init_rent_annualzd_mp" << ","	// col 16 = rent_pmt(last_proj_period)
	<< "rental_growth_mp" << ","		// col 17 = get_string_of_enum_val(rental_growth)
	<< "avr_contribn_pct_mp" << ","		// col 18 = avr_contribn_pct
	<< "avr_max_pct_mp" << ","			// col 19 = avr_max_pct
	<< "avr_obj_pct_mp" << ","			// col 20 = avr_obj_pct
	<< "rbc_c1_pct_mp" << endl;			// col 21 = rbc_c1_pct
	}

re_state_of_world_header_mp_output.close();
#endif

return;
}



#line 1 "write_sec_state_of_world_header_mp.INVSTRAT_ASSET.for"                                                                                   
void INVSTRAT_ASSET::write_sec_state_of_world_header_mp(void)
{
#if defined(__SEC_ASSET_H_)
static bool sec_header_first_time = true;

xstring data_file_name = replaceWildcards(asset->sm_sec[0]->data_location());

xstring sec_state_of_world_file
= xstring(data_file_name(0 , data_file_name.find("_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num) + ".csv")))
  + "_" + xstring(proj_set_loop_num) + "_" + xstring(proj_set_sub_loop_num + 1) + ".csv";

// Remove any old file
if (sec_header_first_time)
	{
	sec_header_first_time = false;

	struct stat buffer;
	int stat_val = stat(sec_state_of_world_file.c_str(), &buffer);

	// Delete existing file, so a new file can be created
	if (stat_val == 0)
		remove(sec_state_of_world_file);
	}
 
if (!sec_state_of_world_header_mp_output.is_open())
	{
   	sec_state_of_world_header_mp_output.setf(ios::fixed);
	sec_state_of_world_header_mp_output.precision(12);
	sec_state_of_world_header_mp_output.open(sec_state_of_world_file);

	// Write header
	sec_state_of_world_header_mp_output						// Values from inforce mp
	<< "group" << ","									// col 0 = get_base_group_name(group)
    << "seg_id_mp" << ","								// col 1 = seg_id
	<< "asset_id_mp" << ","								// col 2 = asset_id
	<< "use_mp" << ","									// col 3 = use_mp
	<< "category_id_mp" << ","							// col 4 = category_id
	<< "cp_asset_id_mp" << ","							// col 5 = sm_sec_cp->asset_id
	<< "cp_category_id_mp" << ","						// col 6 = sm_sec_cp->category_id	
	<< "sale_class_mp" << ","							// col 7 = get_string_of_enum_val(sale_class)
	<< "planned_sale_date_mp" << ","					// col 8 = planned_sale_date
	<< "init_tranche_par_val_mp" << ","					// col 9 = notional_amt(last_proj_period)
	<< "init_tranche_cost_basis_mp" << ","				// col 10 = cost_basis(last_proj_period)
	<< "init_tranche_bk_val_mp" << ","					// col 11 = bk_val(last_proj_period)
	<< "init_tranche_mkt_val_mp" << ","					// col 12 = mkt_val(last_proj_period)
	<< "tranche_owned_mp" << ","						// col 13 = get_string_of_enum_val(tranche_owned)
	<< "io_po_defn_mp" << ","							// col 14 = get_string_of_enum_val(io_po_defn)
	<< "tranche_rate_category_id_mp" << ","             // col 15 = tranche_rate_category_id
	<< "tranche_rate_scen_yr_mp" << ","					// col 16 = tranche_rate_scen_yr
	<< "tranche_rate_scen_mult_mp" << ","				// col 17 = tranche_rate_scen_mult
	<< "tranche_rate_addn_mp" << ","					// col 18 = tranche_rate_addn
	<< "tranche_min_rate_mp" << ","						// col 18 = tranche_min_rate
	<< "tranche_max_rate_mp" << ","						// col 20 = tranche_max_rate
	<< "init_tranche_a_bal_mp" << ","					// col 21 = sm_sec_cf->tranche_a_prin(last_proj_period)
	<< "init_tranche_b_bal_mp" << ","					// col 22 = sm_sec_cf->tranche_b_prin(last_proj_period)
	<< "init_tranche_c_bal_mp" << ","					// col 23 = sm_sec_cf->tranche_c_prin(last_proj_period)
	<< "init_pac1_std_bal_mp" << ","					// col 24 = sm_sec_cf->pac1_std_bal(last_proj_period)
	<< "init_pac1z_bal_mp" << ","						// col 25 = sm_sec_cf->pac1z_bal(last_proj_period)
	<< "init_pac1z_z_rate_mp" << ","					// col 26 = pac1z_rate
	<< "init_pac2a_bal_mp" << ","						// col 27 = sm_sec_cf->pac2a_bal(last_proj_period)
	<< "init_pac2b_bal_mp" << ","						// col 28 = sm_sec_cf->pac2b_bal(last_proj_period)
	<< "pac2_accrual_defn_mp" << ","					// col 29 = get_string_of_enum_val(pac2_accrual_defn)
	<< "init_pac2a_z_rate_mp" << ","					// col 30 = pac2_z_rate
	<< "init_pac3_bal_mp" << ","						// col 31 = sm_sec_cf->pac3_bal(last_proj_period)
	<< "init_pac3_z_rate_mp" << ","						// col 32 = pac3_z_rate
	<< "init_tranche_z_bal_mp" << ","					// col 33 = sm_sec_cf->tranche_z_prin(last_proj_period)
	<< "tranche_z_defn_mp" << ","						// col 34 = get_string_of_enum_val(tranche_z_defn)
	<< "tranche_z_accrual_rate_mp" << ","				// col 35 = tranche_z_accrual_rate
	<< "tranche_z_jump_speed_mp" << ","					// col 36 = tranche_z_jump_speed
	<< "tranche_z_prepmt_priority_bef_jump_mp" << ","	// col 37 = get_string_of_enum_val(tranche_z_prepmt_priority_bef_jump)
	<< "avr_contribn_pct_mp" << ","						// col 38 = avr_contribn_pct
	<< "avr_max_pct_mp" << ","							// col 39 = avr_max_pct
	<< "avr_obj_pct_mp" << ","							// col 40 = avr_obj_pct
	<< "rbc_c1_pct_mp" << ","							// col 41 = rbc_c1_pct
	<< "cp_issue_date_mp" << ","						// col 42 = sm_sec_cp->issue_date
	<< "cp_maturity_date_mp" << ","						// col 43 = sm_sec_cp->maturity_date
	<< "cp_init_prin_val_mp" << ","						// col 44 = sm_sec_cp->prin_val(last_proj_period)
	<< "cp_amortzn_start_cy_mp" << ","					// col 45 = sm_sec_cp->amortzn_start_cy
	<< "cp_pmt_mode_mp" << ","							// col 46 = sm_sec_cp->pmt_mode
	<< "cp_init_pmt_rate_mp" << ","						// col 47 = sm_sec_cp->pmt_rate(last_proj_period)
	<< "cp_servicing_fee_mp" << ","						// col 48 = sm_sec_cp->servicing_fee
	<< "cp_prin_val_at_issue_mp" << ","					// col 49 = sm_sec_cp->prin_val_at_issue
	<< "cp_prepmt_opt_first_date_mp" << ","				// col 50 = sm_sec_cp->prepmt_opt_first_date
	<< "cp_prepmt_penalty_defn_mp" << ","				// col 51 = sm_sec_cp->prepmt_penalty_defn
	<< "cp_balloon_date_mp" << ","						// col 52 = sm_sec_cp->balloon_date
	<< "cp_yld_maint_addn_mp" << ","					// col 53 = sm_sec_cp->yld_maint_addn
	<< "cp_adj_reset_category_id_mp" << ","				// col 54 = sm_sec_cp->adj_reset_category_id
	<< "cp_adj_reset_scen_yr_mp" << ","					// col 55 = sm_sec_cp->adj_reset_scen_yr
	<< "cp_adj_reset_scen_mult_mp" << ","				// col 56 = sm_sec_cp->adj_reset_scen_mult
	<< "cp_adj_reset_renewal_addn_mp" << ","			// col 57 = sm_sec_cp->adj_reset_renewal_addn
	<< "cp_adj_next_reset_date_mp" << ","				// col 58 = sm_sec_cp->adj_next_reset_date
	<< "cp_adj_reset_mths_mp" << ","					// col 59 = sm_sec_cp->adj_reset_mths
	<< "cp_adj_max_incr_per_reset_mp" << ","			// col 60 = sm_sec_cp->adj_max_incr_per_reset
	<< "cp_adj_max_decr_per_reset_mp" << ","			// col 61 = sm_sec_cp->adj_max_decr_per_reset
	<< "cp_adj_min_rate_mp" << ","						// col 62 = sm_sec_cp->adj_min_rate
	<< "cp_adj_max_rate_mp" << ","						// col 63 = sm_sec_cp->adj_max_rate
	<< "cp_init_prepmt_cumul_mp" << endl;					// col 64 = sm_sec_cp->sec_prepmt_cumul(last_proj_period)
	}

sec_state_of_world_header_mp_output.close();
#endif

return;
}



void INVSTRAT_ASSET::Terminator()
{

bond_state_of_world_header_mp_output.close();
mtg_state_of_world_header_mp_output.close();
sec_state_of_world_header_mp_output.close();
ird_state_of_world_header_mp_output.close();
re_state_of_world_header_mp_output.close();
eqt_state_of_world_header_mp_output.close();
eio_state_of_world_header_mp_output.close();
epa_state_of_world_header_mp_output.close();
PVCFile.close();
YMFile.close();

}

FunctionPtr INVSTRAT_ASSET::RegisterTerminatorOnce = []() {
    ::PushTerminator(Terminator);
    RegisterTerminatorOnce = NoOp;
};

	static INVSTRAT_ASSET_UDF *modelOffset		= 0;

 // Column Definition Begins
  double INVSTRAT_ASSET::cash_flow_rebal_estimate(int x) {
		if (callbackStart)
			return ((INVSTRAT_ASSET_persistent_object *)this)->cash_flow_rebal_estimate(x);
    return ((INVSTRAT_ASSET_UDF *)this)->invstrat_asset_cash_flow_rebal_estimate(x); // x is the unadjusted t
  }

  double INVSTRAT_ASSET::cash_investment_sale_net_prelim(int x) {
		if (callbackStart)
			return ((INVSTRAT_ASSET_persistent_object *)this)->cash_investment_sale_net_prelim(x);
    return ((INVSTRAT_ASSET_UDF *)this)->invstrat_asset_cash_investment_sale_net_prelim(x); // x is the unadjusted t
  }

  double INVSTRAT_ASSET::initialize_sub_port_sale_vars_eom(int x) {
		if (callbackStart)
			return ((INVSTRAT_ASSET_persistent_object *)this)->initialize_sub_port_sale_vars_eom(x);
    return ((INVSTRAT_ASSET_UDF *)this)->invstrat_asset_initialize_sub_port_sale_vars_eom(x); // x is the unadjusted t
  }


//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (INVSTRAT_ASSET_UDF::*dPXi) (int);
typedef double (INVSTRAT_ASSET_UDF::*dPXid) (int, double);
typedef double (INVSTRAT_ASSET_UDF::*dPF) ();
typedef double (INVSTRAT_ASSET_UDF::*dPFd) (double);
typedef int (INVSTRAT_ASSET_UDF::*iPF) ();
typedef int (INVSTRAT_ASSET_UDF::*iPFi) (int);
typedef xstring (INVSTRAT_ASSET_UDF::*sPF) ();
typedef xstring (INVSTRAT_ASSET_UDF::*sPFs) (xstring);

const CashFlowCommonData INVSTRAT_ASSET::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "cal_mth", "invstrat_asset_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_cal_mth, 'E','N', '3', 'C', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(2, "cal_yr", "invstrat_asset_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_cal_yr, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(3, "cal_yr_relative", "invstrat_asset_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_cal_yr_relative, 'E','N', '3', 'C', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(4, "cash", "invstrat_asset_cash",  "cash",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_cash, 'E','N', '3', 'C', (size_t)&modelOffset->cash),
	CashFlowCommonData(5, "cash_flow_for_asset_purch", "invstrat_asset_cash_flow_for_asset_purch",  "cash_flow_for_asset_purch",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_cash_flow_for_asset_purch, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_flow_for_asset_purch),
	CashFlowCommonData(6, "cash_flow_for_inv", "invstrat_asset_cash_flow_for_inv",  "cash_flow_for_inv",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_cash_flow_for_inv, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_flow_for_inv),
	CashFlowCommonData(7, "cash_flow_for_inv_bef_rebal", "invstrat_asset_cash_flow_for_inv_bef_rebal",  "cash_flow_for_inv_bef_rebal",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_cash_flow_for_inv_bef_rebal, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_flow_for_inv_bef_rebal),
	CashFlowCommonData(8, "cash_flow_hedge_sale", "invstrat_asset_cash_flow_hedge_sale",  "cash_flow_hedge_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_cash_flow_hedge_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_flow_hedge_sale),
	CashFlowCommonData(9, "cash_flow_planned_sale", "invstrat_asset_cash_flow_planned_sale",  "cash_flow_planned_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_cash_flow_planned_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_flow_planned_sale),
	CashFlowCommonData(10, "cash_flow_rebal", "invstrat_asset_cash_flow_rebal",  "cash_flow_rebal",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_cash_flow_rebal, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_flow_rebal),
	CashFlowCommonData(11, "cash_incr", "invstrat_asset_cash_incr",  "cash_incr",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_cash_incr, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_incr),
	CashFlowCommonData(12, "cash_investment_sale_net", "invstrat_asset_cash_investment_sale_net",  "cash_investment_sale_net",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_cash_investment_sale_net, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_investment_sale_net),
	CashFlowCommonData(13, "cash_net_neg_cash_flow_sale", "invstrat_asset_cash_net_neg_cash_flow_sale",  "cash_net_neg_cash_flow_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_cash_net_neg_cash_flow_sale, 'E','Y', '3', 'C', (size_t)&modelOffset->cash_net_neg_cash_flow_sale),
	CashFlowCommonData(14, "date", "invstrat_asset_date",  "date",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(15, "dur_bef_match", "invstrat_asset_dur_bef_match",  "dur_bef_match",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_dur_bef_match, 'E','N', '3', 'P', (size_t)&modelOffset->dur_bef_match),
	CashFlowCommonData(16, "dur_final_port", "invstrat_asset_dur_final_port",  "dur_final_port",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_dur_final_port, 'E','N', '3', 'P', (size_t)&modelOffset->dur_final_port),
	CashFlowCommonData(17, "dur_match_flag", "invstrat_asset_dur_match_flag",  "dur_match_flag",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_dur_match_flag, 'E','N', '3', 'P', (size_t)&modelOffset->dur_match_flag),
	CashFlowCommonData(18, "dur_match_tgt", "invstrat_asset_dur_match_tgt",  "dur_match_tgt",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_dur_match_tgt, 'E','N', '3', 'C', (size_t)&modelOffset->dur_match_tgt),
	CashFlowCommonData(19, "dur_match_tolerance", "invstrat_asset_dur_match_tolerance",  "dur_match_tolerance",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_dur_match_tolerance, 'E','N', '3', 'C', (size_t)&modelOffset->dur_match_tolerance),
	CashFlowCommonData(20, "finalize", "invstrat_asset_finalize",  "finalize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_finalize, 'E','N', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(21, "foreclosure_bk_val_net_write_down", "invstrat_asset_foreclosure_bk_val_net_write_down",  "foreclosure_bk_val_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_bk_val_net_write_down, 'E','N', '3', 'C', (size_t)&modelOffset->foreclosure_bk_val_net_write_down),
	CashFlowCommonData(22, "foreclosure_bk_val_net_write_down_neg_asset", "invstrat_asset_foreclosure_bk_val_net_write_down_neg_asset",  "foreclosure_bk_val_net_write_down_neg_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_bk_val_net_write_down_neg_asset, 'E','N', '3', 'C', (size_t)&modelOffset->foreclosure_bk_val_net_write_down_neg_asset),
	CashFlowCommonData(23, "foreclosure_cost_basis_net_write_down", "invstrat_asset_foreclosure_cost_basis_net_write_down",  "foreclosure_cost_basis_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_cost_basis_net_write_down, 'E','N', '3', 'C', (size_t)&modelOffset->foreclosure_cost_basis_net_write_down),
	CashFlowCommonData(24, "foreclosure_cost_basis_net_write_down_neg_asset", "invstrat_asset_foreclosure_cost_basis_net_write_down_neg_asset",  "foreclosure_cost_basis_net_write_down_neg_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_cost_basis_net_write_down_neg_asset, 'E','N', '3', 'C', (size_t)&modelOffset->foreclosure_cost_basis_net_write_down_neg_asset),
	CashFlowCommonData(25, "foreclosure_prin_net_write_down", "invstrat_asset_foreclosure_prin_net_write_down",  "foreclosure_prin_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_prin_net_write_down, 'E','N', '3', 'C', (size_t)&modelOffset->foreclosure_prin_net_write_down),
	CashFlowCommonData(26, "foreclosure_prin_net_write_down_neg_asset", "invstrat_asset_foreclosure_prin_net_write_down_neg_asset",  "foreclosure_prin_net_write_down_neg_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_prin_net_write_down_neg_asset, 'E','N', '3', 'C', (size_t)&modelOffset->foreclosure_prin_net_write_down_neg_asset),
	CashFlowCommonData(27, "initialize", "invstrat_asset_initialize",  "initialize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_initialize, 'E','N', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(28, "initialize_sale_and_inv_vars_eom", "invstrat_asset_initialize_sale_and_inv_vars_eom",  "initialize_sale_and_inv_vars_eom",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_initialize_sale_and_inv_vars_eom, 'E','N', '3', 'P', (size_t)&modelOffset->initialize_sale_and_inv_vars_eom),
	CashFlowCommonData(29, "interim_cash", "invstrat_asset_interim_cash",  "interim_cash",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_interim_cash, 'E','N', '3', 'C', (size_t)&modelOffset->interim_cash),
	CashFlowCommonData(30, "inv_amt", "invstrat_asset_inv_amt",  "inv_amt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_inv_amt, 'E','Y', '3', 'C', (size_t)&modelOffset->inv_amt),
	CashFlowCommonData(31, "inv_deficit", "invstrat_asset_inv_deficit",  "inv_deficit",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_inv_deficit, 'E','N', '3', 'C', (size_t)&modelOffset->inv_deficit),
	CashFlowCommonData(32, "inv_eom_flag", "invstrat_asset_inv_eom_flag",  "inv_eom_flag",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_inv_eom_flag, 'E','N', '3', 'P', (size_t)&modelOffset->inv_eom_flag),
	CashFlowCommonData(33, "investable_assets_bef_rebal", "invstrat_asset_investable_assets_bef_rebal",  "investable_assets_bef_rebal",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_investable_assets_bef_rebal, 'E','N', '3', 'C', (size_t)&modelOffset->investable_assets_bef_rebal),
	CashFlowCommonData(34, "mkt_val_for_dur_bef_dur_match", "invstrat_asset_mkt_val_for_dur_bef_dur_match",  "mkt_val_for_dur_bef_dur_match",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_mkt_val_for_dur_bef_dur_match, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_for_dur_bef_dur_match),
	CashFlowCommonData(35, "mkt_val_purch_for_dur_match", "invstrat_asset_mkt_val_purch_for_dur_match",  "mkt_val_purch_for_dur_match",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_mkt_val_purch_for_dur_match, 'E','Y', '3', 'C', (size_t)&modelOffset->mkt_val_purch_for_dur_match),
	CashFlowCommonData(36, "mkt_val_sale", "invstrat_asset_mkt_val_sale",  "mkt_val_sale",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_mkt_val_sale, 'E','Y', '3', 'P', (size_t)&modelOffset->mkt_val_sale),
	CashFlowCommonData(37, "mkt_val_sale_for_dur_match", "invstrat_asset_mkt_val_sale_for_dur_match",  "mkt_val_sale_for_dur_match",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_mkt_val_sale_for_dur_match, 'E','Y', '3', 'P', (size_t)&modelOffset->mkt_val_sale_for_dur_match),
	CashFlowCommonData(38, "mkt_val_times_dur_bef_dur_match", "invstrat_asset_mkt_val_times_dur_bef_dur_match",  "mkt_val_times_dur_bef_dur_match",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_mkt_val_times_dur_bef_dur_match, 'E','N', '3', 'C', (size_t)&modelOffset->mkt_val_times_dur_bef_dur_match),
	CashFlowCommonData(39, "mths_to_rebal", "invstrat_asset_mths_to_rebal",  "mths_to_rebal",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_mths_to_rebal, 'E','N', '3', 'C', (size_t)&modelOffset->mths_to_rebal),
	CashFlowCommonData(40, "refinance_bk_val", "invstrat_asset_refinance_bk_val",  "refinance_bk_val",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_refinance_bk_val, 'E','N', '3', 'C', (size_t)&modelOffset->refinance_bk_val),
	CashFlowCommonData(41, "refinance_bk_val_neg_assets", "invstrat_asset_refinance_bk_val_neg_assets",  "refinance_bk_val_neg_assets",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_refinance_bk_val_neg_assets, 'E','N', '3', 'C', (size_t)&modelOffset->refinance_bk_val_neg_assets),
	CashFlowCommonData(42, "refinance_cost_basis", "invstrat_asset_refinance_cost_basis",  "refinance_cost_basis",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_refinance_cost_basis, 'E','N', '3', 'C', (size_t)&modelOffset->refinance_cost_basis),
	CashFlowCommonData(43, "refinance_cost_basis_neg_asset", "invstrat_asset_refinance_cost_basis_neg_asset",  "refinance_cost_basis_neg_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_refinance_cost_basis_neg_asset, 'E','N', '3', 'C', (size_t)&modelOffset->refinance_cost_basis_neg_asset),
	CashFlowCommonData(44, "refinance_prin", "invstrat_asset_refinance_prin",  "refinance_prin",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_refinance_prin, 'E','N', '3', 'C', (size_t)&modelOffset->refinance_prin),
	CashFlowCommonData(45, "refinance_prin_neg_asset", "invstrat_asset_refinance_prin_neg_asset",  "refinance_prin_neg_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_refinance_prin_neg_asset, 'E','N', '3', 'C', (size_t)&modelOffset->refinance_prin_neg_asset),
	CashFlowCommonData(46, "restructure_bk_val_net_write_down", "invstrat_asset_restructure_bk_val_net_write_down",  "restructure_bk_val_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_restructure_bk_val_net_write_down, 'E','N', '3', 'C', (size_t)&modelOffset->restructure_bk_val_net_write_down),
	CashFlowCommonData(47, "restructure_bk_val_net_write_down_neg_asset", "invstrat_asset_restructure_bk_val_net_write_down_neg_asset",  "restructure_bk_val_net_write_down_neg_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_restructure_bk_val_net_write_down_neg_asset, 'E','N', '3', 'C', (size_t)&modelOffset->restructure_bk_val_net_write_down_neg_asset),
	CashFlowCommonData(48, "restructure_cost_basis_net_write_down", "invstrat_asset_restructure_cost_basis_net_write_down",  "restructure_cost_basis_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_restructure_cost_basis_net_write_down, 'E','N', '3', 'C', (size_t)&modelOffset->restructure_cost_basis_net_write_down),
	CashFlowCommonData(49, "restructure_cost_basis_net_write_down_neg_asset", "invstrat_asset_restructure_cost_basis_net_write_down_neg_asset",  "restructure_cost_basis_net_write_down_neg_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_restructure_cost_basis_net_write_down_neg_asset, 'E','N', '3', 'C', (size_t)&modelOffset->restructure_cost_basis_net_write_down_neg_asset),
	CashFlowCommonData(50, "restructure_prin_net_write_down", "invstrat_asset_restructure_prin_net_write_down",  "restructure_prin_net_write_down",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_restructure_prin_net_write_down, 'E','N', '3', 'C', (size_t)&modelOffset->restructure_prin_net_write_down),
	CashFlowCommonData(51, "restructure_prin_net_write_down_neg_asset", "invstrat_asset_restructure_prin_net_write_down_neg_asset",  "restructure_prin_net_write_down_neg_asset",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_restructure_prin_net_write_down_neg_asset, 'E','N', '3', 'C', (size_t)&modelOffset->restructure_prin_net_write_down_neg_asset),
	CashFlowCommonData(52, "sale_planned_or_min_size_flag", "invstrat_asset_sale_planned_or_min_size_flag",  "sale_planned_or_min_size_flag",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_sale_planned_or_min_size_flag, 'E','N', '3', 'P', (size_t)&modelOffset->sale_planned_or_min_size_flag),
	CashFlowCommonData(53, "sale_possible_imr_avr_flag", "invstrat_asset_sale_possible_imr_avr_flag",  "sale_possible_imr_avr_flag",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_sale_possible_imr_avr_flag, 'E','N', '3', 'P', (size_t)&modelOffset->sale_possible_imr_avr_flag),
	CashFlowCommonData(54, "startup", "invstrat_asset_startup",  "startup",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup),
	CashFlowCommonData(55, "use_dur_match_strat", "invstrat_asset_use_dur_match_strat",  "use_dur_match_strat",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INVSTRAT_ASSET_UDF::invstrat_asset_use_dur_match_strat, 'E','N', '3', 'P', (size_t)&modelOffset->use_dur_match_strat)
};
const CashFlowCommonData* INVSTRAT_ASSET::mCFStaticData[] = {
	&INVSTRAT_ASSET::mCFStaticData_0[0],
	&INVSTRAT_ASSET::mCFStaticData_0[1],
	&INVSTRAT_ASSET::mCFStaticData_0[2],
	&INVSTRAT_ASSET::mCFStaticData_0[3],
	&INVSTRAT_ASSET::mCFStaticData_0[4],
	&INVSTRAT_ASSET::mCFStaticData_0[5],
	&INVSTRAT_ASSET::mCFStaticData_0[6],
	&INVSTRAT_ASSET::mCFStaticData_0[7],
	&INVSTRAT_ASSET::mCFStaticData_0[8],
	&INVSTRAT_ASSET::mCFStaticData_0[9],
	&INVSTRAT_ASSET::mCFStaticData_0[10],
	&INVSTRAT_ASSET::mCFStaticData_0[11],
	&INVSTRAT_ASSET::mCFStaticData_0[12],
	&INVSTRAT_ASSET::mCFStaticData_0[13],
	&INVSTRAT_ASSET::mCFStaticData_0[14],
	&INVSTRAT_ASSET::mCFStaticData_0[15],
	&INVSTRAT_ASSET::mCFStaticData_0[16],
	&INVSTRAT_ASSET::mCFStaticData_0[17],
	&INVSTRAT_ASSET::mCFStaticData_0[18],
	&INVSTRAT_ASSET::mCFStaticData_0[19],
	&INVSTRAT_ASSET::mCFStaticData_0[20],
	&INVSTRAT_ASSET::mCFStaticData_0[21],
	&INVSTRAT_ASSET::mCFStaticData_0[22],
	&INVSTRAT_ASSET::mCFStaticData_0[23],
	&INVSTRAT_ASSET::mCFStaticData_0[24],
	&INVSTRAT_ASSET::mCFStaticData_0[25],
	&INVSTRAT_ASSET::mCFStaticData_0[26],
	&INVSTRAT_ASSET::mCFStaticData_0[27],
	&INVSTRAT_ASSET::mCFStaticData_0[28],
	&INVSTRAT_ASSET::mCFStaticData_0[29],
	&INVSTRAT_ASSET::mCFStaticData_0[30],
	&INVSTRAT_ASSET::mCFStaticData_0[31],
	&INVSTRAT_ASSET::mCFStaticData_0[32],
	&INVSTRAT_ASSET::mCFStaticData_0[33],
	&INVSTRAT_ASSET::mCFStaticData_0[34],
	&INVSTRAT_ASSET::mCFStaticData_0[35],
	&INVSTRAT_ASSET::mCFStaticData_0[36],
	&INVSTRAT_ASSET::mCFStaticData_0[37],
	&INVSTRAT_ASSET::mCFStaticData_0[38],
	&INVSTRAT_ASSET::mCFStaticData_0[39],
	&INVSTRAT_ASSET::mCFStaticData_0[40],
	&INVSTRAT_ASSET::mCFStaticData_0[41],
	&INVSTRAT_ASSET::mCFStaticData_0[42],
	&INVSTRAT_ASSET::mCFStaticData_0[43],
	&INVSTRAT_ASSET::mCFStaticData_0[44],
	&INVSTRAT_ASSET::mCFStaticData_0[45],
	&INVSTRAT_ASSET::mCFStaticData_0[46],
	&INVSTRAT_ASSET::mCFStaticData_0[47],
	&INVSTRAT_ASSET::mCFStaticData_0[48],
	&INVSTRAT_ASSET::mCFStaticData_0[49],
	&INVSTRAT_ASSET::mCFStaticData_0[50],
	&INVSTRAT_ASSET::mCFStaticData_0[51],
	&INVSTRAT_ASSET::mCFStaticData_0[52],
	&INVSTRAT_ASSET::mCFStaticData_0[53],
	&INVSTRAT_ASSET::mCFStaticData_0[54],
	&INVSTRAT_ASSET::mCFStaticData_0[55],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for asset_sale_defn                                                                                       
	const ChoicePair asset_sale_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::REBALANCING_SALES, "Rebalancing Sales")
		,ChoicePair(StrEnum::PLANNED_SALES_OR_MINIMUM_SIZE_ASSETS, "Planned Sales or Minimum Size Assets")
		,ChoicePair(StrEnum::HEDGE_SALES, "Hedge Sales")
		,ChoicePair(StrEnum::NEGATIVE_CASH_FLOW_SALES, "Negative Cash Flow Sales")
		,ChoicePair(StrEnum::PORTFOLIO_MANAGEMENT_SALES, "Portfolio Management Sales")
	};
	const EnumList asset_sale_defnEnumList(5, asset_sale_defnChoicePairs);

	// EnumList for asset_sales_selection                                                                                       
	const ChoicePair asset_sales_selectionChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PRO_RATA, "Pro Rata")
		,ChoicePair(StrEnum::MAXIMIZE_CAPITAL_GAIN, "Maximize Capital Gain")
		,ChoicePair(StrEnum::LONGEST_DURATION, "Longest Duration")
		,ChoicePair(StrEnum::SHORTEST_DURATION, "Shortest Duration")
		,ChoicePair(StrEnum::RESTRICTED_ASSETS_PRO_RATA, "Restricted Assets Pro Rata")
		,ChoicePair(StrEnum::RESTRICTED_ASSETS_MAXIMIZE_CAPITAL_GAIN, "Restricted Assets Maximize Capital Gain")
		,ChoicePair(StrEnum::RESTRICTED_ASSETS_LONGEST_DURATION, "Restricted Assets Longest Duration")
		,ChoicePair(StrEnum::RESTRICTED_ASSETS_SHORTEST_DURATION, "Restricted Assets Shortest Duration")
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
	};
	const EnumList asset_sales_selectionEnumList(9, asset_sales_selectionChoicePairs);

	// EnumList for convert_type                                                                                       
	const ChoicePair convert_typeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::_0, "0")
	};
	const EnumList convert_typeEnumList(1, convert_typeChoicePairs);

	// EnumList for data_validation_defn                                                                                       
	const ChoicePair data_validation_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList data_validation_defnEnumList(2, data_validation_defnChoicePairs);

	// EnumList for gen2_declarations                                                                                       
	const ChoicePair gen2_declarationsChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ASSET_DATA, "Asset Data")
	};
	const EnumList gen2_declarationsEnumList(1, gen2_declarationsChoicePairs);

	// EnumList for inv_purch_timing                                                                                       
	const ChoicePair inv_purch_timingChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::END_OF_MONTH, "End of Month")
		,ChoicePair(StrEnum::PROJECTION_DATE, "Projection Date")
	};
	const EnumList inv_purch_timingEnumList(2, inv_purch_timingChoicePairs);

	// EnumList for inv_strat_closest                                                                                       
	const ChoicePair inv_strat_closestChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CURRENT, "Current")
		,ChoicePair(StrEnum::SHORTER, "Shorter")
		,ChoicePair(StrEnum::SHORTEST, "Shortest")
		,ChoicePair(StrEnum::LONGER, "Longer")
		,ChoicePair(StrEnum::LONGEST, "Longest")
		,ChoicePair(StrEnum::NEGATIVE, "Negative")
	};
	const EnumList inv_strat_closestEnumList(6, inv_strat_closestChoicePairs);

	// EnumList for inv_strat_distribn_defn                                                                                       
	const ChoicePair inv_strat_distribn_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CASH, "Cash")
		,ChoicePair(StrEnum::BOOK, "Book")
	};
	const EnumList inv_strat_distribn_defnEnumList(2, inv_strat_distribn_defnChoicePairs);

	// EnumList for inv_strat_economic_compare_defn                                                                                       
	const ChoicePair inv_strat_economic_compare_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::GREATER_THAN, "Greater Than")
		,ChoicePair(StrEnum::LESS_THAN, "Less Than")
	};
	const EnumList inv_strat_economic_compare_defnEnumList(2, inv_strat_economic_compare_defnChoicePairs);

	// EnumList for inv_strat_economic_test_calc_defn                                                                                       
	const ChoicePair inv_strat_economic_test_calc_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SUBTRACTION, "Subtraction")
		,ChoicePair(StrEnum::DIVISION, "Division")
	};
	const EnumList inv_strat_economic_test_calc_defnEnumList(2, inv_strat_economic_test_calc_defnChoicePairs);

	// EnumList for inv_strat_economic_test_defn                                                                                       
	const ChoicePair inv_strat_economic_test_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::AVERAGE_RATE, "Average Rate")
		,ChoicePair(StrEnum::MINIMUM_RATE, "Minimum Rate")
		,ChoicePair(StrEnum::MAXIMUM_RATE, "Maximum Rate")
	};
	const EnumList inv_strat_economic_test_defnEnumList(3, inv_strat_economic_test_defnChoicePairs);

	// EnumList for neg_cash_flow_cash_bal_defn                                                                                       
	const ChoicePair neg_cash_flow_cash_bal_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::REDUCE_CASH_BALANCE_TO_THRESHOLD, "Reduce Cash Balance To Threshold")
		,ChoicePair(StrEnum::BORROW_TO_THRESHOLD, "Borrow To Threshold")
		,ChoicePair(StrEnum::TARGETED_CASH_BALANCE, "Targeted Cash Balance")
	};
	const EnumList neg_cash_flow_cash_bal_defnEnumList(3, neg_cash_flow_cash_bal_defnChoicePairs);

	// EnumList for neg_cash_flow_sale_selection_defn                                                                                       
	const ChoicePair neg_cash_flow_sale_selection_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PRO_RATA, "Pro Rata")
		,ChoicePair(StrEnum::MAXIMIZE_CAPITAL_GAIN, "Maximize Capital Gain")
		,ChoicePair(StrEnum::LONGEST_DURATION, "Longest Duration")
		,ChoicePair(StrEnum::SHORTEST_DURATION, "Shortest Duration")
	};
	const EnumList neg_cash_flow_sale_selection_defnEnumList(4, neg_cash_flow_sale_selection_defnChoicePairs);

	// EnumList for neg_cash_flow_strat                                                                                       
	const ChoicePair neg_cash_flow_stratChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BORROW, "Borrow")
		,ChoicePair(StrEnum::NEGATIVE_ASSETS, "Negative Assets")
		,ChoicePair(StrEnum::SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE, "Sell Assets To Cover Negative Cash Balance")
	};
	const EnumList neg_cash_flow_stratEnumList(3, neg_cash_flow_stratChoicePairs);

	// EnumList for neg_cash_flow_strat_economic                                                                                       
	const ChoicePair neg_cash_flow_strat_economicChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BORROW, "Borrow")
		,ChoicePair(StrEnum::NEGATIVE_ASSETS, "Negative Assets")
		,ChoicePair(StrEnum::SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE, "Sell Assets To Cover Negative Cash Balance")
	};
	const EnumList neg_cash_flow_strat_economicEnumList(3, neg_cash_flow_strat_economicChoicePairs);

	// EnumList for neg_cash_flow_strat_economic_cash_bal_defn                                                                                       
	const ChoicePair neg_cash_flow_strat_economic_cash_bal_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::REDUCE_CASH_BALANCE_TO_THRESHOLD, "Reduce Cash Balance To Threshold")
		,ChoicePair(StrEnum::BORROW_TO_THRESHOLD, "Borrow To Threshold")
		,ChoicePair(StrEnum::TARGETED_CASH_BALANCE, "Targeted Cash Balance")
	};
	const EnumList neg_cash_flow_strat_economic_cash_bal_defnEnumList(3, neg_cash_flow_strat_economic_cash_bal_defnChoicePairs);

	// EnumList for neg_cash_flow_strat_economic_compare_defn                                                                                       
	const ChoicePair neg_cash_flow_strat_economic_compare_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::GREATER_THAN, "Greater Than")
		,ChoicePair(StrEnum::LESS_THAN, "Less Than")
	};
	const EnumList neg_cash_flow_strat_economic_compare_defnEnumList(2, neg_cash_flow_strat_economic_compare_defnChoicePairs);

	// EnumList for neg_cash_flow_strat_economic_sale_selection_defn                                                                                       
	const ChoicePair neg_cash_flow_strat_economic_sale_selection_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PRO_RATA, "Pro Rata")
		,ChoicePair(StrEnum::MAXIMIZE_CAPITAL_GAIN, "Maximize Capital Gain")
		,ChoicePair(StrEnum::LONGEST_DURATION, "Longest Duration")
		,ChoicePair(StrEnum::SHORTEST_DURATION, "Shortest Duration")
	};
	const EnumList neg_cash_flow_strat_economic_sale_selection_defnEnumList(4, neg_cash_flow_strat_economic_sale_selection_defnChoicePairs);

	// EnumList for neg_cash_flow_strat_economic_test_calc_defn                                                                                       
	const ChoicePair neg_cash_flow_strat_economic_test_calc_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SUBTRACTION, "Subtraction")
		,ChoicePair(StrEnum::DIVISION, "Division")
	};
	const EnumList neg_cash_flow_strat_economic_test_calc_defnEnumList(2, neg_cash_flow_strat_economic_test_calc_defnChoicePairs);

	// EnumList for neg_cash_flow_strat_economic_test_defn                                                                                       
	const ChoicePair neg_cash_flow_strat_economic_test_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::AVERAGE_RATE, "Average Rate")
		,ChoicePair(StrEnum::MINIMUM_RATE, "Minimum Rate")
		,ChoicePair(StrEnum::MAXIMUM_RATE, "Maximum Rate")
	};
	const EnumList neg_cash_flow_strat_economic_test_defnEnumList(3, neg_cash_flow_strat_economic_test_defnChoicePairs);

	// EnumList for neg_cash_flow_strat_planned                                                                                       
	const ChoicePair neg_cash_flow_strat_plannedChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BORROW, "Borrow")
		,ChoicePair(StrEnum::NEGATIVE_ASSETS, "Negative Assets")
		,ChoicePair(StrEnum::SELL_ASSETS_TO_COVER_NEGATIVE_CASH_BALANCE, "Sell Assets To Cover Negative Cash Balance")
	};
	const EnumList neg_cash_flow_strat_plannedEnumList(3, neg_cash_flow_strat_plannedChoicePairs);

	// EnumList for neg_cash_flow_strat_planned_cash_bal_defn                                                                                       
	const ChoicePair neg_cash_flow_strat_planned_cash_bal_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::REDUCE_CASH_BALANCE_TO_THRESHOLD, "Reduce Cash Balance To Threshold")
		,ChoicePair(StrEnum::BORROW_TO_THRESHOLD, "Borrow To Threshold")
		,ChoicePair(StrEnum::TARGETED_CASH_BALANCE, "Targeted Cash Balance")
	};
	const EnumList neg_cash_flow_strat_planned_cash_bal_defnEnumList(3, neg_cash_flow_strat_planned_cash_bal_defnChoicePairs);

	// EnumList for neg_cash_flow_strat_planned_sale_selection_defn                                                                                       
	const ChoicePair neg_cash_flow_strat_planned_sale_selection_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PRO_RATA, "Pro Rata")
		,ChoicePair(StrEnum::MAXIMIZE_CAPITAL_GAIN, "Maximize Capital Gain")
		,ChoicePair(StrEnum::LONGEST_DURATION, "Longest Duration")
		,ChoicePair(StrEnum::SHORTEST_DURATION, "Shortest Duration")
	};
	const EnumList neg_cash_flow_strat_planned_sale_selection_defnEnumList(4, neg_cash_flow_strat_planned_sale_selection_defnChoicePairs);

	// EnumList for purch_bond_call_defn                                                                                       
	const ChoicePair purch_bond_call_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::AMERICAN, "American")
		,ChoicePair(StrEnum::EUROPEAN, "European")
	};
	const EnumList purch_bond_call_defnEnumList(3, purch_bond_call_defnChoicePairs);

	// EnumList for purch_bond_call_price_defn                                                                                       
	const ChoicePair purch_bond_call_price_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PRICE_SCHEDULE, "Price Schedule")
		,ChoicePair(StrEnum::YIELD_MAINTENANCE, "Yield Maintenance")
		,ChoicePair(StrEnum::CASH_FLOW_MAINTENANCE, "Cash Flow Maintenance")
		,ChoicePair(StrEnum::RELATED_TO_COUPON, "Related to Coupon")
	};
	const EnumList purch_bond_call_price_defnEnumList(4, purch_bond_call_price_defnChoicePairs);

	// EnumList for purch_bond_pmt_mode                                                                                       
	const ChoicePair purch_bond_pmt_modeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::SEMI_ANNUAL, "Semi-Annual")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
		,ChoicePair(StrEnum::AVAILABLE_FOR_SALE, "Available for Sale")
	};
	const EnumList purch_bond_pmt_modeEnumList(5, purch_bond_pmt_modeChoicePairs);

	// EnumList for purch_bond_port_defn                                                                                       
	const ChoicePair purch_bond_port_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INVESTMENT, "Investment")
	};
	const EnumList purch_bond_port_defnEnumList(1, purch_bond_port_defnChoicePairs);

	// EnumList for purch_bond_put_defn                                                                                       
	const ChoicePair purch_bond_put_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::AMERICAN, "American")
		,ChoicePair(StrEnum::EUROPEAN, "European")
	};
	const EnumList purch_bond_put_defnEnumList(3, purch_bond_put_defnChoicePairs);

	// EnumList for purch_bond_put_price_defn                                                                                       
	const ChoicePair purch_bond_put_price_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PRICE_SCHEDULE, "Price Schedule")
		,ChoicePair(StrEnum::RELATED_TO_COUPON, "Related to Coupon")
	};
	const EnumList purch_bond_put_price_defnEnumList(2, purch_bond_put_price_defnChoicePairs);

	// EnumList for purch_bond_rate_defn                                                                                       
	const ChoicePair purch_bond_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::REFINANCING_RATE, "Refinancing Rate")
		,ChoicePair(StrEnum::FIXED_RATE, "Fixed Rate")
		,ChoicePair(StrEnum::FLOATING_RATE, "Floating Rate")
	};
	const EnumList purch_bond_rate_defnEnumList(3, purch_bond_rate_defnChoicePairs);

	// EnumList for purch_bond_sale_class                                                                                       
	const ChoicePair purch_bond_sale_classChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_ASSIGNED, "Not Assigned")
		,ChoicePair(StrEnum::AVAILABLE_FOR_SALE, "Available for Sale")
		,ChoicePair(StrEnum::TRADING, "Trading")
		,ChoicePair(StrEnum::HELD_TO_MATURITY, "Held to Maturity")
	};
	const EnumList purch_bond_sale_classEnumList(4, purch_bond_sale_classChoicePairs);

	// EnumList for purch_bond_sinking_fund_defn                                                                                       
	const ChoicePair purch_bond_sinking_fund_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList purch_bond_sinking_fund_defnEnumList(2, purch_bond_sinking_fund_defnChoicePairs);

	// EnumList for purch_eio_lookback_defn                                                                                       
	const ChoicePair purch_eio_lookback_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NONE, "None")
		,ChoicePair(StrEnum::ASIAN, "Asian")
		,ChoicePair(StrEnum::HIGHEST_GAIN, "Highest Gain")
	};
	const EnumList purch_eio_lookback_defnEnumList(3, purch_eio_lookback_defnChoicePairs);

	// EnumList for purch_eio_lookback_sampling_interval                                                                                       
	const ChoicePair purch_eio_lookback_sampling_intervalChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ANNUAL, "Annual")
		,ChoicePair(StrEnum::SEMIANNUAL, "Semiannual")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
	};
	const EnumList purch_eio_lookback_sampling_intervalEnumList(4, purch_eio_lookback_sampling_intervalChoicePairs);

	// EnumList for purch_eio_opt_defn                                                                                       
	const ChoicePair purch_eio_opt_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::CALL, "Call")
		,ChoicePair(StrEnum::PUT, "Put")
		,ChoicePair(StrEnum::FUTURES, "Futures")
	};
	const EnumList purch_eio_opt_defnEnumList(3, purch_eio_opt_defnChoicePairs);

	// EnumList for purch_eio_port_defn                                                                                       
	const ChoicePair purch_eio_port_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INVESTMENT, "Investment")
		,ChoicePair(StrEnum::HEDGING, "Hedging")
	};
	const EnumList purch_eio_port_defnEnumList(2, purch_eio_port_defnChoicePairs);

	// EnumList for purch_eio_sale_class                                                                                       
	const ChoicePair purch_eio_sale_classChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_ASSIGNED, "Not Assigned")
		,ChoicePair(StrEnum::AVAILABLE_FOR_SALE, "Available for Sale")
		,ChoicePair(StrEnum::TRADING, "Trading")
		,ChoicePair(StrEnum::HELD_TO_MATURITY, "Held to Maturity")
	};
	const EnumList purch_eio_sale_classEnumList(4, purch_eio_sale_classChoicePairs);

	// EnumList for purch_eqt_pmt_mode                                                                                       
	const ChoicePair purch_eqt_pmt_modeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::SEMI_ANNUAL, "Semi-Annual")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
	};
	const EnumList purch_eqt_pmt_modeEnumList(4, purch_eqt_pmt_modeChoicePairs);

	// EnumList for purch_eqt_sale_class                                                                                       
	const ChoicePair purch_eqt_sale_classChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_ASSIGNED, "Not Assigned")
		,ChoicePair(StrEnum::AVAILABLE_FOR_SALE, "Available for Sale")
		,ChoicePair(StrEnum::TRADING, "Trading")
		,ChoicePair(StrEnum::HELD_TO_MATURITY, "Held to Maturity")
	};
	const EnumList purch_eqt_sale_classEnumList(4, purch_eqt_sale_classChoicePairs);

	// EnumList for purch_ird_pmt_defn                                                                                       
	const ChoicePair purch_ird_pmt_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ALWAYS, "Always")
		,ChoicePair(StrEnum::IF_POSITIVE, "If Positive")
	};
	const EnumList purch_ird_pmt_defnEnumList(2, purch_ird_pmt_defnChoicePairs);

	// EnumList for purch_ird_port_defn                                                                                       
	const ChoicePair purch_ird_port_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INVESTMENT, "Investment")
		,ChoicePair(StrEnum::HEDGING, "Hedging")
	};
	const EnumList purch_ird_port_defnEnumList(2, purch_ird_port_defnChoicePairs);

	// EnumList for purch_ird_rate_1_defn                                                                                       
	const ChoicePair purch_ird_rate_1_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FIXED_RATE, "Fixed Rate")
		,ChoicePair(StrEnum::FLOATING_RATE, "Floating Rate")
	};
	const EnumList purch_ird_rate_1_defnEnumList(2, purch_ird_rate_1_defnChoicePairs);

	// EnumList for purch_ird_rate_1_pmt_mode                                                                                       
	const ChoicePair purch_ird_rate_1_pmt_modeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::SEMI_ANNUAL, "Semi-Annual")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
	};
	const EnumList purch_ird_rate_1_pmt_modeEnumList(4, purch_ird_rate_1_pmt_modeChoicePairs);

	// EnumList for purch_ird_rate_2_defn                                                                                       
	const ChoicePair purch_ird_rate_2_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FIXED_RATE, "Fixed Rate")
		,ChoicePair(StrEnum::FLOATING_RATE, "Floating Rate")
	};
	const EnumList purch_ird_rate_2_defnEnumList(2, purch_ird_rate_2_defnChoicePairs);

	// EnumList for purch_ird_rate_2_pmt_mode                                                                                       
	const ChoicePair purch_ird_rate_2_pmt_modeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::SEMI_ANNUAL, "Semi-Annual")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
	};
	const EnumList purch_ird_rate_2_pmt_modeEnumList(4, purch_ird_rate_2_pmt_modeChoicePairs);

	// EnumList for purch_ird_sale_class                                                                                       
	const ChoicePair purch_ird_sale_classChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_ASSIGNED, "Not Assigned")
		,ChoicePair(StrEnum::AVAILABLE_FOR_SALE, "Available for Sale")
		,ChoicePair(StrEnum::TRADING, "Trading")
		,ChoicePair(StrEnum::HELD_TO_MATURITY, "Held to Maturity")
	};
	const EnumList purch_ird_sale_classEnumList(4, purch_ird_sale_classChoicePairs);

	// EnumList for purch_mtg_balloon_defn                                                                                       
	const ChoicePair purch_mtg_balloon_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES_ON_SINGLE_PERIOD, "Yes On Single Period")
		,ChoicePair(StrEnum::YES_PER_SCHEDULE, "Yes Per Schedule")
	};
	const EnumList purch_mtg_balloon_defnEnumList(3, purch_mtg_balloon_defnChoicePairs);

	// EnumList for purch_mtg_pmt_mode                                                                                       
	const ChoicePair purch_mtg_pmt_modeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::SEMI_ANNUAL, "Semi-Annual")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
	};
	const EnumList purch_mtg_pmt_modeEnumList(4, purch_mtg_pmt_modeChoicePairs);

	// EnumList for purch_mtg_port_defn                                                                                       
	const ChoicePair purch_mtg_port_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INVESTMENT, "Investment")
	};
	const EnumList purch_mtg_port_defnEnumList(1, purch_mtg_port_defnChoicePairs);

	// EnumList for purch_mtg_prepmt_penalty_defn                                                                                       
	const ChoicePair purch_mtg_prepmt_penalty_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::PENALTY_PERCENT, "Penalty Percent")
		,ChoicePair(StrEnum::YIELD_MAINTENANCE, "Yield Maintenance")
		,ChoicePair(StrEnum::CASH_FLOW_MAINTENANCE, "Cash Flow Maintenance")
		,ChoicePair(StrEnum::RELATED_TO_PAYMENT_RATE, "Related to Payment Rate")
	};
	const EnumList purch_mtg_prepmt_penalty_defnEnumList(5, purch_mtg_prepmt_penalty_defnChoicePairs);

	// EnumList for purch_mtg_rate_defn                                                                                       
	const ChoicePair purch_mtg_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::REFINANCING_RATE, "Refinancing Rate")
		,ChoicePair(StrEnum::FIXED_RATE, "Fixed Rate")
		,ChoicePair(StrEnum::FLOATING_RATE, "Floating Rate")
	};
	const EnumList purch_mtg_rate_defnEnumList(3, purch_mtg_rate_defnChoicePairs);

	// EnumList for purch_mtg_sale_class                                                                                       
	const ChoicePair purch_mtg_sale_classChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_ASSIGNED, "Not Assigned")
		,ChoicePair(StrEnum::AVAILABLE_FOR_SALE, "Available for Sale")
		,ChoicePair(StrEnum::TRADING, "Trading")
		,ChoicePair(StrEnum::HELD_TO_MATURITY, "Held to Maturity")
	};
	const EnumList purch_mtg_sale_classEnumList(4, purch_mtg_sale_classChoicePairs);

	// EnumList for purch_re_pmt_mode                                                                                       
	const ChoicePair purch_re_pmt_modeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::SEMI_ANNUAL, "Semi-Annual")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
	};
	const EnumList purch_re_pmt_modeEnumList(4, purch_re_pmt_modeChoicePairs);

	// EnumList for purch_re_rental_growth                                                                                       
	const ChoicePair purch_re_rental_growthChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList purch_re_rental_growthEnumList(2, purch_re_rental_growthChoicePairs);

	// EnumList for purch_re_sale_class                                                                                       
	const ChoicePair purch_re_sale_classChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_ASSIGNED, "Not Assigned")
		,ChoicePair(StrEnum::AVAILABLE_FOR_SALE, "Available for Sale")
		,ChoicePair(StrEnum::TRADING, "Trading")
		,ChoicePair(StrEnum::HELD_TO_MATURITY, "Held to Maturity")
	};
	const EnumList purch_re_sale_classEnumList(4, purch_re_sale_classChoicePairs);

	// EnumList for purch_sec_cp_pmt_mode                                                                                       
	const ChoicePair purch_sec_cp_pmt_modeChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::SEMI_ANNUAL, "Semi-Annual")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
	};
	const EnumList purch_sec_cp_pmt_modeEnumList(4, purch_sec_cp_pmt_modeChoicePairs);

	// EnumList for purch_sec_cp_prepmt_penalty_defn                                                                                       
	const ChoicePair purch_sec_cp_prepmt_penalty_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::PENALTY_PERCENT, "Penalty Percent")
		,ChoicePair(StrEnum::YIELD_MAINTENANCE, "Yield Maintenance")
		,ChoicePair(StrEnum::CASH_FLOW_MAINTENANCE, "Cash Flow Maintenance")
		,ChoicePair(StrEnum::RELATED_TO_PAYMENT_RATE, "Related to Payment Rate")
	};
	const EnumList purch_sec_cp_prepmt_penalty_defnEnumList(5, purch_sec_cp_prepmt_penalty_defnChoicePairs);

	// EnumList for purch_sec_cp_rate_defn                                                                                       
	const ChoicePair purch_sec_cp_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::REFINANCING_RATE, "Refinancing Rate")
		,ChoicePair(StrEnum::FIXED_RATE, "Fixed Rate")
		,ChoicePair(StrEnum::FLOATING_RATE, "Floating Rate")
	};
	const EnumList purch_sec_cp_rate_defnEnumList(3, purch_sec_cp_rate_defnChoicePairs);

	// EnumList for purch_sec_io_po_defn                                                                                       
	const ChoicePair purch_sec_io_po_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BOTH, "Both")
		,ChoicePair(StrEnum::IO, "IO")
		,ChoicePair(StrEnum::PO, "PO")
	};
	const EnumList purch_sec_io_po_defnEnumList(3, purch_sec_io_po_defnChoicePairs);

	// EnumList for purch_sec_pac2_accrual_defn                                                                                       
	const ChoicePair purch_sec_pac2_accrual_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NON_ACCRUAL, "Non Accrual")
		,ChoicePair(StrEnum::Z_PAC, "Z PAC")
	};
	const EnumList purch_sec_pac2_accrual_defnEnumList(2, purch_sec_pac2_accrual_defnChoicePairs);

	// EnumList for purch_sec_sale_class                                                                                       
	const ChoicePair purch_sec_sale_classChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_ASSIGNED, "Not Assigned")
		,ChoicePair(StrEnum::AVAILABLE_FOR_SALE, "Available for Sale")
		,ChoicePair(StrEnum::TRADING, "Trading")
		,ChoicePair(StrEnum::HELD_TO_MATURITY, "Held to Maturity")
	};
	const EnumList purch_sec_sale_classEnumList(4, purch_sec_sale_classChoicePairs);

	// EnumList for purch_sec_tranche_owned                                                                                       
	const ChoicePair purch_sec_tranche_ownedChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::TRANCHE_B, "Tranche B")
		,ChoicePair(StrEnum::TRANCHE_Z, "Tranche Z")
		,ChoicePair(StrEnum::PAC2A, "PAC2A")
		,ChoicePair(StrEnum::TRANCHE_A, "Tranche A")
		,ChoicePair(StrEnum::TRANCHE_C, "Tranche C")
	};
	const EnumList purch_sec_tranche_ownedEnumList(5, purch_sec_tranche_ownedChoicePairs);

	// EnumList for purch_sec_tranche_rate_defn                                                                                       
	const ChoicePair purch_sec_tranche_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::FIXED_RATE, "Fixed Rate")
		,ChoicePair(StrEnum::FLOATING_RATE, "Floating Rate")
	};
	const EnumList purch_sec_tranche_rate_defnEnumList(2, purch_sec_tranche_rate_defnChoicePairs);

	// EnumList for purch_sec_tranche_z_defn                                                                                       
	const ChoicePair purch_sec_tranche_z_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ACCRUAL_ONLY, "Accrual Only")
		,ChoicePair(StrEnum::JUMP, "Jump")
		,ChoicePair(StrEnum::JUMP_STICK, "Jump/Stick")
	};
	const EnumList purch_sec_tranche_z_defnEnumList(3, purch_sec_tranche_z_defnChoicePairs);

	// EnumList for purch_sec_tranche_z_prepmt_priority_bef_jump                                                                                       
	const ChoicePair purch_sec_tranche_z_prepmt_priority_bef_jumpChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::BEFORE_PAC2, "Before PAC2")
		,ChoicePair(StrEnum::AFTER_PAC2, "After PAC2")
	};
	const EnumList purch_sec_tranche_z_prepmt_priority_bef_jumpEnumList(2, purch_sec_tranche_z_prepmt_priority_bef_jumpChoicePairs);

	// EnumList for rebal_dur_match_defn                                                                                       
	const ChoicePair rebal_dur_match_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList rebal_dur_match_defnEnumList(2, rebal_dur_match_defnChoicePairs);

	// EnumList for rebal_freq                                                                                       
	const ChoicePair rebal_freqChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_APPLICABLE, "Not Applicable")
		,ChoicePair(StrEnum::ANNUALLY, "Annually")
		,ChoicePair(StrEnum::SEMIANNUALLY, "Semiannually")
		,ChoicePair(StrEnum::QUARTERLY, "Quarterly")
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::AT_ASSET_FREQUENCY, "At Asset Frequency")
	};
	const EnumList rebal_freqEnumList(6, rebal_freqChoicePairs);

	// EnumList for rebal_sale_selection_defn                                                                                       
	const ChoicePair rebal_sale_selection_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PRO_RATA, "Pro Rata")
		,ChoicePair(StrEnum::MAXIMIZE_CAPITAL_GAIN, "Maximize Capital Gain")
		,ChoicePair(StrEnum::LONGEST_DURATION, "Longest Duration")
		,ChoicePair(StrEnum::SHORTEST_DURATION, "Shortest Duration")
	};
	const EnumList rebal_sale_selection_defnEnumList(4, rebal_sale_selection_defnChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace INVSTRAT_ASSET_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(INVSTRAT_ASSET::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(INVSTRAT_ASSET::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace INVSTRAT_ASSET_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void INVSTRAT_ASSET::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> INVSTRAT_ASSET::mgr_;

	Attribute::Descriptor INVSTRAT_ASSET::descriptor_0[] = {
	Descriptor(0, Attribute::STR_ENUM,	"asset_sale_defn", -1, (size_t)&modelOffset->asset_sale_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_sale_defnEnumList, Feature(true)),
	Descriptor(1, Attribute::STR_ENUM,	"asset_sales_selection", -1, (size_t)&modelOffset->asset_sales_selection,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_sales_selectionEnumList, Feature(true)),
	Descriptor(2, Attribute::STRING,	"asset_sub_port_id", -1, (size_t)&modelOffset->asset_sub_port_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::DOUBLE,	"asset_sub_port_inv_tgt_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->asset_sub_port_inv_tgt_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::STR_ENUM,	"convert_type", -1, (size_t)&modelOffset->convert_type,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &convert_typeEnumList, Feature(false)),
	Descriptor(5, Attribute::STR_ENUM,	"data_validation_defn", -1, (size_t)&modelOffset->data_validation_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &data_validation_defnEnumList, Feature(true)),
	Descriptor(6, Attribute::INT,	"date_lookup", -1, (size_t)&modelOffset->date_lookup,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::DOUBLE,	"dur_match_tgt_input", Descriptor::NOT_INDEXED, (size_t)&modelOffset->dur_match_tgt_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::DOUBLE,	"dur_match_tolerance_input", Descriptor::NOT_INDEXED, (size_t)&modelOffset->dur_match_tolerance_input,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(9, Attribute::DOUBLE,	"dur_wtd_sprd_adj_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->dur_wtd_sprd_adj_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(10, Attribute::DOUBLE,	"foreclosure_int_pmt_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->foreclosure_int_pmt_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::STRING,	"foreclosure_inv_id", -1, (size_t)&modelOffset->foreclosure_inv_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::DOUBLE,	"foreclosure_prin_pmt_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->foreclosure_prin_pmt_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::STR_ENUM,	"gen2_declarations", -1, (size_t)&modelOffset->gen2_declarations,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &gen2_declarationsEnumList, Feature(true)),
	Descriptor(14, Attribute::DOUBLE,	"inv_amt_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->inv_amt_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::STR_ENUM,	"inv_purch_timing", -1, (size_t)&modelOffset->inv_purch_timing,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &inv_purch_timingEnumList, Feature(true)),
	Descriptor(16, Attribute::DOUBLE,	"inv_strat_cash_tgt_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->inv_strat_cash_tgt_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::STR_ENUM,	"inv_strat_closest", -1, (size_t)&modelOffset->inv_strat_closest,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &inv_strat_closestEnumList, Feature(true)),
	Descriptor(18, Attribute::STR_ENUM,	"inv_strat_distribn_defn", -1, (size_t)&modelOffset->inv_strat_distribn_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &inv_strat_distribn_defnEnumList, Feature(true)),
	Descriptor(19, Attribute::DOUBLE,	"inv_strat_dur_wtd_sprd_adj_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->inv_strat_dur_wtd_sprd_adj_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(20, Attribute::STR_ENUM,	"inv_strat_economic_compare_defn", -1, (size_t)&modelOffset->inv_strat_economic_compare_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &inv_strat_economic_compare_defnEnumList, Feature(true)),
	Descriptor(21, Attribute::DOUBLE,	"inv_strat_economic_dur_match_tgt_incr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->inv_strat_economic_dur_match_tgt_incr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(22, Attribute::DOUBLE,	"inv_strat_economic_dur_match_tolerance_incr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->inv_strat_economic_dur_match_tolerance_incr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(23, Attribute::DOUBLE,	"inv_strat_economic_fixed_test_val", Descriptor::NOT_INDEXED, (size_t)&modelOffset->inv_strat_economic_fixed_test_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::INT,	"inv_strat_economic_lag_mths", -1, (size_t)&modelOffset->inv_strat_economic_lag_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(25, Attribute::STRING,	"inv_strat_economic_longer", -1, (size_t)&modelOffset->inv_strat_economic_longer,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::STRING,	"inv_strat_economic_longest", -1, (size_t)&modelOffset->inv_strat_economic_longest,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::INT,	"inv_strat_economic_mths", -1, (size_t)&modelOffset->inv_strat_economic_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(28, Attribute::STRING,	"inv_strat_economic_planned", -1, (size_t)&modelOffset->inv_strat_economic_planned,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(29, Attribute::DOUBLE,	"inv_strat_economic_rate_1_term", Descriptor::NOT_INDEXED, (size_t)&modelOffset->inv_strat_economic_rate_1_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(30, Attribute::DOUBLE,	"inv_strat_economic_rate_2_term", Descriptor::NOT_INDEXED, (size_t)&modelOffset->inv_strat_economic_rate_2_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(31, Attribute::STRING,	"inv_strat_economic_shorter", -1, (size_t)&modelOffset->inv_strat_economic_shorter,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(32, Attribute::STRING,	"inv_strat_economic_shortest", -1, (size_t)&modelOffset->inv_strat_economic_shortest,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(33, Attribute::STR_ENUM,	"inv_strat_economic_test_calc_defn", -1, (size_t)&modelOffset->inv_strat_economic_test_calc_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &inv_strat_economic_test_calc_defnEnumList, Feature(true)),
	Descriptor(34, Attribute::STR_ENUM,	"inv_strat_economic_test_defn", -1, (size_t)&modelOffset->inv_strat_economic_test_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &inv_strat_economic_test_defnEnumList, Feature(true)),
	Descriptor(35, Attribute::INT,	"inv_strat_economic_test_num", -1, (size_t)&modelOffset->inv_strat_economic_test_num,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(36, Attribute::INT,	"inv_strat_economic_tests", -1, (size_t)&modelOffset->inv_strat_economic_tests,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(37, Attribute::STRING,	"inv_strat_id", -1, (size_t)&modelOffset->inv_strat_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(38, Attribute::STRING,	"inv_strat_planned", -1, (size_t)&modelOffset->inv_strat_planned,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(39, Attribute::STRING,	"inv_strat_planned_longer", -1, (size_t)&modelOffset->inv_strat_planned_longer,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(40, Attribute::STRING,	"inv_strat_planned_longest", -1, (size_t)&modelOffset->inv_strat_planned_longest,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(41, Attribute::STRING,	"inv_strat_planned_shorter", -1, (size_t)&modelOffset->inv_strat_planned_shorter,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(42, Attribute::STRING,	"inv_strat_planned_shortest", -1, (size_t)&modelOffset->inv_strat_planned_shortest,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(43, Attribute::DOUBLE,	"inv_strat_port_sprd_adj_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->inv_strat_port_sprd_adj_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(44, Attribute::INT,	"mths_since_issue", -1, (size_t)&modelOffset->mths_since_issue,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(45, Attribute::STR_ENUM,	"neg_cash_flow_cash_bal_defn", -1, (size_t)&modelOffset->neg_cash_flow_cash_bal_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &neg_cash_flow_cash_bal_defnEnumList, Feature(true)),
	Descriptor(46, Attribute::DOUBLE,	"neg_cash_flow_cash_thresh_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->neg_cash_flow_cash_thresh_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(47, Attribute::DOUBLE,	"neg_cash_flow_cash_thresh_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->neg_cash_flow_cash_thresh_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(48, Attribute::STRING,	"neg_cash_flow_neg_assets", -1, (size_t)&modelOffset->neg_cash_flow_neg_assets,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(49, Attribute::INT,	"neg_cash_flow_sale_priority_avail_for_sale", -1, (size_t)&modelOffset->neg_cash_flow_sale_priority_avail_for_sale,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(50, Attribute::INT,	"neg_cash_flow_sale_priority_held_to_maturity", -1, (size_t)&modelOffset->neg_cash_flow_sale_priority_held_to_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(51, Attribute::INT,	"neg_cash_flow_sale_priority_not_assigned", -1, (size_t)&modelOffset->neg_cash_flow_sale_priority_not_assigned,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(52, Attribute::INT,	"neg_cash_flow_sale_priority_trading", -1, (size_t)&modelOffset->neg_cash_flow_sale_priority_trading,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(53, Attribute::STR_ENUM,	"neg_cash_flow_sale_selection_defn", -1, (size_t)&modelOffset->neg_cash_flow_sale_selection_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &neg_cash_flow_sale_selection_defnEnumList, Feature(true)),
	Descriptor(54, Attribute::STR_ENUM,	"neg_cash_flow_strat", -1, (size_t)&modelOffset->neg_cash_flow_strat,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &neg_cash_flow_stratEnumList, Feature(true)),
	Descriptor(55, Attribute::STR_ENUM,	"neg_cash_flow_strat_economic", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &neg_cash_flow_strat_economicEnumList, Feature(true)),
	Descriptor(56, Attribute::STR_ENUM,	"neg_cash_flow_strat_economic_cash_bal_defn", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_cash_bal_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &neg_cash_flow_strat_economic_cash_bal_defnEnumList, Feature(true)),
	Descriptor(57, Attribute::DOUBLE,	"neg_cash_flow_strat_economic_cash_thresh_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->neg_cash_flow_strat_economic_cash_thresh_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(58, Attribute::DOUBLE,	"neg_cash_flow_strat_economic_cash_thresh_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->neg_cash_flow_strat_economic_cash_thresh_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(59, Attribute::STR_ENUM,	"neg_cash_flow_strat_economic_compare_defn", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_compare_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &neg_cash_flow_strat_economic_compare_defnEnumList, Feature(true)),
	Descriptor(60, Attribute::DOUBLE,	"neg_cash_flow_strat_economic_fixed_test_val", Descriptor::NOT_INDEXED, (size_t)&modelOffset->neg_cash_flow_strat_economic_fixed_test_val,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(61, Attribute::INT,	"neg_cash_flow_strat_economic_lag_mths", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_lag_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(62, Attribute::INT,	"neg_cash_flow_strat_economic_mths", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(63, Attribute::STRING,	"neg_cash_flow_strat_economic_neg_assets", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_neg_assets,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(64, Attribute::DOUBLE,	"neg_cash_flow_strat_economic_rate_1_term", Descriptor::NOT_INDEXED, (size_t)&modelOffset->neg_cash_flow_strat_economic_rate_1_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(65, Attribute::DOUBLE,	"neg_cash_flow_strat_economic_rate_2_term", Descriptor::NOT_INDEXED, (size_t)&modelOffset->neg_cash_flow_strat_economic_rate_2_term,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(66, Attribute::INT,	"neg_cash_flow_strat_economic_sale_priority_avail_for_sale", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_sale_priority_avail_for_sale,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(67, Attribute::INT,	"neg_cash_flow_strat_economic_sale_priority_held_to_maturity", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_sale_priority_held_to_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(68, Attribute::INT,	"neg_cash_flow_strat_economic_sale_priority_not_assigned", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_sale_priority_not_assigned,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(69, Attribute::INT,	"neg_cash_flow_strat_economic_sale_priority_trading", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_sale_priority_trading,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(70, Attribute::STR_ENUM,	"neg_cash_flow_strat_economic_sale_selection_defn", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_sale_selection_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &neg_cash_flow_strat_economic_sale_selection_defnEnumList, Feature(true)),
	Descriptor(71, Attribute::STR_ENUM,	"neg_cash_flow_strat_economic_test_calc_defn", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_test_calc_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &neg_cash_flow_strat_economic_test_calc_defnEnumList, Feature(true)),
	Descriptor(72, Attribute::STR_ENUM,	"neg_cash_flow_strat_economic_test_defn", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_test_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &neg_cash_flow_strat_economic_test_defnEnumList, Feature(true)),
	Descriptor(73, Attribute::INT,	"neg_cash_flow_strat_economic_test_num", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_test_num,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(74, Attribute::INT,	"neg_cash_flow_strat_economic_tests", -1, (size_t)&modelOffset->neg_cash_flow_strat_economic_tests,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(75, Attribute::STR_ENUM,	"neg_cash_flow_strat_planned", -1, (size_t)&modelOffset->neg_cash_flow_strat_planned,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &neg_cash_flow_strat_plannedEnumList, Feature(true)),
	Descriptor(76, Attribute::STR_ENUM,	"neg_cash_flow_strat_planned_cash_bal_defn", -1, (size_t)&modelOffset->neg_cash_flow_strat_planned_cash_bal_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &neg_cash_flow_strat_planned_cash_bal_defnEnumList, Feature(true)),
	Descriptor(77, Attribute::DOUBLE,	"neg_cash_flow_strat_planned_cash_thresh_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->neg_cash_flow_strat_planned_cash_thresh_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(78, Attribute::DOUBLE,	"neg_cash_flow_strat_planned_cash_thresh_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->neg_cash_flow_strat_planned_cash_thresh_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(79, Attribute::STRING,	"neg_cash_flow_strat_planned_neg_assets", -1, (size_t)&modelOffset->neg_cash_flow_strat_planned_neg_assets,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(80, Attribute::INT,	"neg_cash_flow_strat_planned_sale_priority_avail_for_sale", -1, (size_t)&modelOffset->neg_cash_flow_strat_planned_sale_priority_avail_for_sale,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(81, Attribute::INT,	"neg_cash_flow_strat_planned_sale_priority_held_to_maturity", -1, (size_t)&modelOffset->neg_cash_flow_strat_planned_sale_priority_held_to_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(82, Attribute::INT,	"neg_cash_flow_strat_planned_sale_priority_not_assigned", -1, (size_t)&modelOffset->neg_cash_flow_strat_planned_sale_priority_not_assigned,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(83, Attribute::INT,	"neg_cash_flow_strat_planned_sale_priority_trading", -1, (size_t)&modelOffset->neg_cash_flow_strat_planned_sale_priority_trading,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(84, Attribute::STR_ENUM,	"neg_cash_flow_strat_planned_sale_selection_defn", -1, (size_t)&modelOffset->neg_cash_flow_strat_planned_sale_selection_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &neg_cash_flow_strat_planned_sale_selection_defnEnumList, Feature(true)),
	Descriptor(85, Attribute::DOUBLE,	"port_sprd_adj_crbg", Descriptor::NOT_INDEXED, (size_t)&modelOffset->port_sprd_adj_crbg,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(86, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(87, Attribute::STRING,	"purch_asset_id", -1, (size_t)&modelOffset->purch_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(88, Attribute::STRING,	"purch_asset_sub_port_id", -1, (size_t)&modelOffset->purch_asset_sub_port_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(89, Attribute::DOUBLE,	"purch_asset_weight", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_asset_weight,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(90, Attribute::STRING,	"purch_bond_adj_category_id", -1, (size_t)&modelOffset->purch_bond_adj_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(91, Attribute::DOUBLE,	"purch_bond_adj_max_above_init", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_adj_max_above_init,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(92, Attribute::DOUBLE,	"purch_bond_adj_max_below_init", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_adj_max_below_init,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(93, Attribute::DOUBLE,	"purch_bond_adj_max_reset_decr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_adj_max_reset_decr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(94, Attribute::DOUBLE,	"purch_bond_adj_max_reset_incr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_adj_max_reset_incr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(95, Attribute::INT,	"purch_bond_adj_reset_mths", -1, (size_t)&modelOffset->purch_bond_adj_reset_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(96, Attribute::DOUBLE,	"purch_bond_adj_scen_addn_init", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_adj_scen_addn_init,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(97, Attribute::DOUBLE,	"purch_bond_adj_scen_addn_renewal", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_adj_scen_addn_renewal,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(98, Attribute::DOUBLE,	"purch_bond_adj_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_adj_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(99, Attribute::DOUBLE,	"purch_bond_adj_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_adj_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(100, Attribute::STRING,	"purch_bond_assets_selected", -1, (size_t)&modelOffset->purch_bond_assets_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(101, Attribute::DOUBLE,	"purch_bond_avr_contribn_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_avr_contribn_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(102, Attribute::DOUBLE,	"purch_bond_avr_max_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_avr_max_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(103, Attribute::DOUBLE,	"purch_bond_avr_obj_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_avr_obj_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(104, Attribute::STR_ENUM,	"purch_bond_call_defn", -1, (size_t)&modelOffset->purch_bond_call_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_bond_call_defnEnumList, Feature(true)),
	Descriptor(105, Attribute::DOUBLE,	"purch_bond_call_prem_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_call_prem_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(106, Attribute::DOUBLE,	"purch_bond_call_prem_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_call_prem_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(107, Attribute::STR_ENUM,	"purch_bond_call_price_defn", -1, (size_t)&modelOffset->purch_bond_call_price_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_bond_call_price_defnEnumList, Feature(true)),
	Descriptor(108, Attribute::DOUBLE,	"purch_bond_call_price_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_call_price_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(109, Attribute::DOUBLE,	"purch_bond_call_protect_yrs", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_call_protect_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(110, Attribute::STRING,	"purch_bond_category_id", -1, (size_t)&modelOffset->purch_bond_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(111, Attribute::DOUBLE,	"purch_bond_first_par_call_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_first_par_call_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(112, Attribute::DOUBLE,	"purch_bond_first_par_put_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_first_par_put_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(113, Attribute::STRING,	"purch_bond_grp_id", -1, (size_t)&modelOffset->purch_bond_grp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(114, Attribute::STR_ENUM,	"purch_bond_pmt_mode", -1, (size_t)&modelOffset->purch_bond_pmt_mode,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_bond_pmt_modeEnumList, Feature(true)),
	Descriptor(115, Attribute::STR_ENUM,	"purch_bond_port_defn", -1, (size_t)&modelOffset->purch_bond_port_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_bond_port_defnEnumList, Feature(true)),
	Descriptor(116, Attribute::STR_ENUM,	"purch_bond_put_defn", -1, (size_t)&modelOffset->purch_bond_put_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_bond_put_defnEnumList, Feature(true)),
	Descriptor(117, Attribute::DOUBLE,	"purch_bond_put_prem_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_put_prem_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(118, Attribute::DOUBLE,	"purch_bond_put_prem_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_put_prem_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(119, Attribute::STR_ENUM,	"purch_bond_put_price_defn", -1, (size_t)&modelOffset->purch_bond_put_price_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_bond_put_price_defnEnumList, Feature(true)),
	Descriptor(120, Attribute::DOUBLE,	"purch_bond_put_price_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_put_price_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(121, Attribute::DOUBLE,	"purch_bond_put_protect_yrs", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_put_protect_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(122, Attribute::STR_ENUM,	"purch_bond_rate_defn", -1, (size_t)&modelOffset->purch_bond_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_bond_rate_defnEnumList, Feature(true)),
	Descriptor(123, Attribute::DOUBLE,	"purch_bond_rate_diff", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_rate_diff,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(124, Attribute::DOUBLE,	"purch_bond_rbc_c1_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_rbc_c1_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(125, Attribute::STR_ENUM,	"purch_bond_sale_class", -1, (size_t)&modelOffset->purch_bond_sale_class,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_bond_sale_classEnumList, Feature(true)),
	Descriptor(126, Attribute::STR_ENUM,	"purch_bond_sinking_fund_defn", -1, (size_t)&modelOffset->purch_bond_sinking_fund_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_bond_sinking_fund_defnEnumList, Feature(true)),
	Descriptor(127, Attribute::DOUBLE,	"purch_bond_sinking_fund_prin_pmt_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_sinking_fund_prin_pmt_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(128, Attribute::DOUBLE,	"purch_bond_taxable_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_taxable_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(129, Attribute::DOUBLE,	"purch_bond_yld_maint_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_yld_maint_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(130, Attribute::DOUBLE,	"purch_bond_yrs_to_maturity", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_bond_yrs_to_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(131, Attribute::STRING,	"purch_eio_asset_index", -1, (size_t)&modelOffset->purch_eio_asset_index,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(132, Attribute::STRING,	"purch_eio_assets_selected", -1, (size_t)&modelOffset->purch_eio_assets_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(133, Attribute::DOUBLE,	"purch_eio_avr_contribn_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eio_avr_contribn_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(134, Attribute::DOUBLE,	"purch_eio_avr_max_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eio_avr_max_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(135, Attribute::DOUBLE,	"purch_eio_avr_obj_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eio_avr_obj_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(136, Attribute::STRING,	"purch_eio_category_id", -1, (size_t)&modelOffset->purch_eio_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(137, Attribute::DOUBLE,	"purch_eio_div_yld_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eio_div_yld_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(138, Attribute::DOUBLE,	"purch_eio_div_yld_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eio_div_yld_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(139, Attribute::STRING,	"purch_eio_grp_id", -1, (size_t)&modelOffset->purch_eio_grp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(140, Attribute::DOUBLE,	"purch_eio_index_scen_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eio_index_scen_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(141, Attribute::DOUBLE,	"purch_eio_index_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eio_index_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(142, Attribute::STR_ENUM,	"purch_eio_lookback_defn", -1, (size_t)&modelOffset->purch_eio_lookback_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_eio_lookback_defnEnumList, Feature(true)),
	Descriptor(143, Attribute::STR_ENUM,	"purch_eio_lookback_sampling_interval", -1, (size_t)&modelOffset->purch_eio_lookback_sampling_interval,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_eio_lookback_sampling_intervalEnumList, Feature(true)),
	Descriptor(144, Attribute::DOUBLE,	"purch_eio_lookback_yrs", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eio_lookback_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(145, Attribute::STR_ENUM,	"purch_eio_opt_defn", -1, (size_t)&modelOffset->purch_eio_opt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_eio_opt_defnEnumList, Feature(true)),
	Descriptor(146, Attribute::DOUBLE,	"purch_eio_opt_strike_price", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eio_opt_strike_price,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(147, Attribute::DOUBLE,	"purch_eio_payout_index_max", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eio_payout_index_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(148, Attribute::STR_ENUM,	"purch_eio_port_defn", -1, (size_t)&modelOffset->purch_eio_port_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_eio_port_defnEnumList, Feature(true)),
	Descriptor(149, Attribute::DOUBLE,	"purch_eio_rbc_c1_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eio_rbc_c1_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(150, Attribute::STR_ENUM,	"purch_eio_sale_class", -1, (size_t)&modelOffset->purch_eio_sale_class,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_eio_sale_classEnumList, Feature(true)),
	Descriptor(151, Attribute::DOUBLE,	"purch_eio_yrs_to_maturity", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eio_yrs_to_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(152, Attribute::STRING,	"purch_eqt_asset_index", -1, (size_t)&modelOffset->purch_eqt_asset_index,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(153, Attribute::STRING,	"purch_eqt_assets_selected", -1, (size_t)&modelOffset->purch_eqt_assets_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(154, Attribute::DOUBLE,	"purch_eqt_avr_contribn_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eqt_avr_contribn_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(155, Attribute::DOUBLE,	"purch_eqt_avr_max_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eqt_avr_max_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(156, Attribute::DOUBLE,	"purch_eqt_avr_obj_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eqt_avr_obj_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(157, Attribute::STRING,	"purch_eqt_category_id", -1, (size_t)&modelOffset->purch_eqt_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(158, Attribute::DOUBLE,	"purch_eqt_div_yld_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eqt_div_yld_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(159, Attribute::DOUBLE,	"purch_eqt_div_yld_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eqt_div_yld_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(160, Attribute::STRING,	"purch_eqt_grp_id", -1, (size_t)&modelOffset->purch_eqt_grp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(161, Attribute::DOUBLE,	"purch_eqt_mkt_growth_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eqt_mkt_growth_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(162, Attribute::DOUBLE,	"purch_eqt_mkt_growth_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eqt_mkt_growth_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(163, Attribute::STR_ENUM,	"purch_eqt_pmt_mode", -1, (size_t)&modelOffset->purch_eqt_pmt_mode,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_eqt_pmt_modeEnumList, Feature(true)),
	Descriptor(164, Attribute::DOUBLE,	"purch_eqt_rbc_c1_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_eqt_rbc_c1_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(165, Attribute::STR_ENUM,	"purch_eqt_sale_class", -1, (size_t)&modelOffset->purch_eqt_sale_class,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_eqt_sale_classEnumList, Feature(true)),
	Descriptor(166, Attribute::STRING,	"purch_ird_assets_selected", -1, (size_t)&modelOffset->purch_ird_assets_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(167, Attribute::DOUBLE,	"purch_ird_avr_contribn_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_ird_avr_contribn_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(168, Attribute::DOUBLE,	"purch_ird_avr_max_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_ird_avr_max_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(169, Attribute::DOUBLE,	"purch_ird_avr_obj_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_ird_avr_obj_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(170, Attribute::STRING,	"purch_ird_category_id", -1, (size_t)&modelOffset->purch_ird_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(171, Attribute::STRING,	"purch_ird_grp_id", -1, (size_t)&modelOffset->purch_ird_grp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(172, Attribute::INT,	"purch_ird_mths_to_first_reset", -1, (size_t)&modelOffset->purch_ird_mths_to_first_reset,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(173, Attribute::STR_ENUM,	"purch_ird_pmt_defn", -1, (size_t)&modelOffset->purch_ird_pmt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_ird_pmt_defnEnumList, Feature(true)),
	Descriptor(174, Attribute::STR_ENUM,	"purch_ird_port_defn", -1, (size_t)&modelOffset->purch_ird_port_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_ird_port_defnEnumList, Feature(true)),
	Descriptor(175, Attribute::DOUBLE,	"purch_ird_rate_1_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_ird_rate_1_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(176, Attribute::STRING,	"purch_ird_rate_1_category_id", -1, (size_t)&modelOffset->purch_ird_rate_1_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(177, Attribute::STR_ENUM,	"purch_ird_rate_1_defn", -1, (size_t)&modelOffset->purch_ird_rate_1_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_ird_rate_1_defnEnumList, Feature(true)),
	Descriptor(178, Attribute::STR_ENUM,	"purch_ird_rate_1_pmt_mode", -1, (size_t)&modelOffset->purch_ird_rate_1_pmt_mode,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_ird_rate_1_pmt_modeEnumList, Feature(true)),
	Descriptor(179, Attribute::DOUBLE,	"purch_ird_rate_1_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_ird_rate_1_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(180, Attribute::DOUBLE,	"purch_ird_rate_1_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_ird_rate_1_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(181, Attribute::DOUBLE,	"purch_ird_rate_2_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_ird_rate_2_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(182, Attribute::STRING,	"purch_ird_rate_2_category_id", -1, (size_t)&modelOffset->purch_ird_rate_2_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(183, Attribute::STR_ENUM,	"purch_ird_rate_2_defn", -1, (size_t)&modelOffset->purch_ird_rate_2_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_ird_rate_2_defnEnumList, Feature(true)),
	Descriptor(184, Attribute::STR_ENUM,	"purch_ird_rate_2_pmt_mode", -1, (size_t)&modelOffset->purch_ird_rate_2_pmt_mode,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_ird_rate_2_pmt_modeEnumList, Feature(true)),
	Descriptor(185, Attribute::DOUBLE,	"purch_ird_rate_2_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_ird_rate_2_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(186, Attribute::DOUBLE,	"purch_ird_rate_2_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_ird_rate_2_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(187, Attribute::DOUBLE,	"purch_ird_rbc_c1_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_ird_rbc_c1_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(188, Attribute::STR_ENUM,	"purch_ird_sale_class", -1, (size_t)&modelOffset->purch_ird_sale_class,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_ird_sale_classEnumList, Feature(true)),
	Descriptor(189, Attribute::DOUBLE,	"purch_ird_yrs_to_maturity", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_ird_yrs_to_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(190, Attribute::DOUBLE,	"purch_mtg_adj_addn_init", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_adj_addn_init,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(191, Attribute::DOUBLE,	"purch_mtg_adj_addn_renewal", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_adj_addn_renewal,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(192, Attribute::STRING,	"purch_mtg_adj_category_id", -1, (size_t)&modelOffset->purch_mtg_adj_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(193, Attribute::DOUBLE,	"purch_mtg_adj_max_above_init", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_adj_max_above_init,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(194, Attribute::DOUBLE,	"purch_mtg_adj_max_below_init", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_adj_max_below_init,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(195, Attribute::DOUBLE,	"purch_mtg_adj_max_reset_decr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_adj_max_reset_decr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(196, Attribute::DOUBLE,	"purch_mtg_adj_max_reset_incr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_adj_max_reset_incr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(197, Attribute::INT,	"purch_mtg_adj_reset_mths", -1, (size_t)&modelOffset->purch_mtg_adj_reset_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(198, Attribute::DOUBLE,	"purch_mtg_adj_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_adj_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(199, Attribute::DOUBLE,	"purch_mtg_adj_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_adj_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(200, Attribute::DOUBLE,	"purch_mtg_amortzn_yrs", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_amortzn_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(201, Attribute::STRING,	"purch_mtg_assets_selected", -1, (size_t)&modelOffset->purch_mtg_assets_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(202, Attribute::DOUBLE,	"purch_mtg_avr_contribn_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_avr_contribn_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(203, Attribute::DOUBLE,	"purch_mtg_avr_max_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_avr_max_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(204, Attribute::DOUBLE,	"purch_mtg_avr_obj_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_avr_obj_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(205, Attribute::STR_ENUM,	"purch_mtg_balloon_defn", -1, (size_t)&modelOffset->purch_mtg_balloon_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_mtg_balloon_defnEnumList, Feature(true)),
	Descriptor(206, Attribute::DOUBLE,	"purch_mtg_balloon_prin_pmt_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_balloon_prin_pmt_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(207, Attribute::STRING,	"purch_mtg_category_id", -1, (size_t)&modelOffset->purch_mtg_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(208, Attribute::DOUBLE,	"purch_mtg_first_par_prepmt_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_first_par_prepmt_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(209, Attribute::STRING,	"purch_mtg_grp_id", -1, (size_t)&modelOffset->purch_mtg_grp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(210, Attribute::STR_ENUM,	"purch_mtg_pmt_mode", -1, (size_t)&modelOffset->purch_mtg_pmt_mode,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_mtg_pmt_modeEnumList, Feature(true)),
	Descriptor(211, Attribute::STR_ENUM,	"purch_mtg_port_defn", -1, (size_t)&modelOffset->purch_mtg_port_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_mtg_port_defnEnumList, Feature(true)),
	Descriptor(212, Attribute::DOUBLE,	"purch_mtg_prepmt_penalty_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_prepmt_penalty_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(213, Attribute::STR_ENUM,	"purch_mtg_prepmt_penalty_defn", -1, (size_t)&modelOffset->purch_mtg_prepmt_penalty_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_mtg_prepmt_penalty_defnEnumList, Feature(true)),
	Descriptor(214, Attribute::DOUBLE,	"purch_mtg_prepmt_penalty_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_prepmt_penalty_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(215, Attribute::DOUBLE,	"purch_mtg_prepmt_penalty_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_prepmt_penalty_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(216, Attribute::DOUBLE,	"purch_mtg_prepmt_protect_yrs", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_prepmt_protect_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(217, Attribute::STR_ENUM,	"purch_mtg_rate_defn", -1, (size_t)&modelOffset->purch_mtg_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_mtg_rate_defnEnumList, Feature(true)),
	Descriptor(218, Attribute::DOUBLE,	"purch_mtg_rate_diff", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_rate_diff,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(219, Attribute::DOUBLE,	"purch_mtg_rbc_c1_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_rbc_c1_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(220, Attribute::STR_ENUM,	"purch_mtg_sale_class", -1, (size_t)&modelOffset->purch_mtg_sale_class,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_mtg_sale_classEnumList, Feature(true)),
	Descriptor(221, Attribute::DOUBLE,	"purch_mtg_servicing_fee", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_servicing_fee,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(222, Attribute::DOUBLE,	"purch_mtg_yld_maint_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_yld_maint_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(223, Attribute::DOUBLE,	"purch_mtg_yrs_to_balloon", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_yrs_to_balloon,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(224, Attribute::DOUBLE,	"purch_mtg_yrs_to_maturity", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_mtg_yrs_to_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(225, Attribute::STRING,	"purch_re_asset_index", -1, (size_t)&modelOffset->purch_re_asset_index,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(226, Attribute::STRING,	"purch_re_assets_selected", -1, (size_t)&modelOffset->purch_re_assets_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(227, Attribute::DOUBLE,	"purch_re_avr_contribn_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_re_avr_contribn_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(228, Attribute::DOUBLE,	"purch_re_avr_max_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_re_avr_max_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(229, Attribute::DOUBLE,	"purch_re_avr_obj_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_re_avr_obj_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(230, Attribute::STRING,	"purch_re_category_id", -1, (size_t)&modelOffset->purch_re_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(231, Attribute::DOUBLE,	"purch_re_depreciation_yrs", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_re_depreciation_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(232, Attribute::STRING,	"purch_re_grp_id", -1, (size_t)&modelOffset->purch_re_grp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(233, Attribute::DOUBLE,	"purch_re_mkt_growth_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_re_mkt_growth_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(234, Attribute::DOUBLE,	"purch_re_mkt_growth_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_re_mkt_growth_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(235, Attribute::STR_ENUM,	"purch_re_pmt_mode", -1, (size_t)&modelOffset->purch_re_pmt_mode,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_re_pmt_modeEnumList, Feature(true)),
	Descriptor(236, Attribute::DOUBLE,	"purch_re_rbc_c1_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_re_rbc_c1_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(237, Attribute::DOUBLE,	"purch_re_rent_rate_scen_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_re_rent_rate_scen_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(238, Attribute::DOUBLE,	"purch_re_rent_rate_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_re_rent_rate_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(239, Attribute::STR_ENUM,	"purch_re_rental_growth", -1, (size_t)&modelOffset->purch_re_rental_growth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_re_rental_growthEnumList, Feature(true)),
	Descriptor(240, Attribute::STR_ENUM,	"purch_re_sale_class", -1, (size_t)&modelOffset->purch_re_sale_class,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_re_sale_classEnumList, Feature(true)),
	Descriptor(241, Attribute::STRING,	"purch_sec_assets_selected", -1, (size_t)&modelOffset->purch_sec_assets_selected,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(242, Attribute::DOUBLE,	"purch_sec_avr_contribn_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_avr_contribn_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(243, Attribute::DOUBLE,	"purch_sec_avr_max_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_avr_max_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(244, Attribute::DOUBLE,	"purch_sec_avr_obj_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_avr_obj_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(245, Attribute::STRING,	"purch_sec_category_id", -1, (size_t)&modelOffset->purch_sec_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(246, Attribute::DOUBLE,	"purch_sec_cp_adj_addn_init", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_adj_addn_init,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(247, Attribute::DOUBLE,	"purch_sec_cp_adj_addn_renewal", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_adj_addn_renewal,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(248, Attribute::STRING,	"purch_sec_cp_adj_category_id", -1, (size_t)&modelOffset->purch_sec_cp_adj_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(249, Attribute::DOUBLE,	"purch_sec_cp_adj_max_above_init", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_adj_max_above_init,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(250, Attribute::DOUBLE,	"purch_sec_cp_adj_max_below_init", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_adj_max_below_init,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(251, Attribute::DOUBLE,	"purch_sec_cp_adj_max_reset_decr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_adj_max_reset_decr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(252, Attribute::DOUBLE,	"purch_sec_cp_adj_max_reset_incr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_adj_max_reset_incr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(253, Attribute::INT,	"purch_sec_cp_adj_reset_mths", -1, (size_t)&modelOffset->purch_sec_cp_adj_reset_mths,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(254, Attribute::DOUBLE,	"purch_sec_cp_adj_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_adj_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(255, Attribute::DOUBLE,	"purch_sec_cp_adj_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_adj_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	};
	Attribute::Descriptor INVSTRAT_ASSET::descriptor_256[] = {
	Descriptor(256, Attribute::DOUBLE,	"purch_sec_cp_amortzn_yrs", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_amortzn_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(257, Attribute::STRING,	"purch_sec_cp_asset_id", -1, (size_t)&modelOffset->purch_sec_cp_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(258, Attribute::STRING,	"purch_sec_cp_category_id", -1, (size_t)&modelOffset->purch_sec_cp_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(259, Attribute::DOUBLE,	"purch_sec_cp_first_par_prepmt_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_first_par_prepmt_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(260, Attribute::STR_ENUM,	"purch_sec_cp_pmt_mode", -1, (size_t)&modelOffset->purch_sec_cp_pmt_mode,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_sec_cp_pmt_modeEnumList, Feature(true)),
	Descriptor(261, Attribute::DOUBLE,	"purch_sec_cp_prepmt_penalty_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_prepmt_penalty_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(262, Attribute::STR_ENUM,	"purch_sec_cp_prepmt_penalty_defn", -1, (size_t)&modelOffset->purch_sec_cp_prepmt_penalty_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_sec_cp_prepmt_penalty_defnEnumList, Feature(true)),
	Descriptor(263, Attribute::DOUBLE,	"purch_sec_cp_prepmt_penalty_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_prepmt_penalty_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(264, Attribute::DOUBLE,	"purch_sec_cp_prepmt_penalty_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_prepmt_penalty_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(265, Attribute::DOUBLE,	"purch_sec_cp_prepmt_protect_yrs", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_prepmt_protect_yrs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(266, Attribute::STR_ENUM,	"purch_sec_cp_rate_defn", -1, (size_t)&modelOffset->purch_sec_cp_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_sec_cp_rate_defnEnumList, Feature(true)),
	Descriptor(267, Attribute::DOUBLE,	"purch_sec_cp_rate_diff", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_rate_diff,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(268, Attribute::DOUBLE,	"purch_sec_cp_servicing_fee", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_servicing_fee,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(269, Attribute::DOUBLE,	"purch_sec_cp_yld_maint_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_yld_maint_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(270, Attribute::DOUBLE,	"purch_sec_cp_yrs_to_balloon", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_yrs_to_balloon,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(271, Attribute::DOUBLE,	"purch_sec_cp_yrs_to_maturity", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_cp_yrs_to_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(272, Attribute::STRING,	"purch_sec_grp_id", -1, (size_t)&modelOffset->purch_sec_grp_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(273, Attribute::STR_ENUM,	"purch_sec_io_po_defn", -1, (size_t)&modelOffset->purch_sec_io_po_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_sec_io_po_defnEnumList, Feature(true)),
	Descriptor(274, Attribute::DOUBLE,	"purch_sec_pac1_std_sch", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_pac1_std_sch,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(275, Attribute::DOUBLE,	"purch_sec_pac1z_accrual_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_pac1z_accrual_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(276, Attribute::DOUBLE,	"purch_sec_pac1z_sch", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_pac1z_sch,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(277, Attribute::STR_ENUM,	"purch_sec_pac2_accrual_defn", -1, (size_t)&modelOffset->purch_sec_pac2_accrual_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_sec_pac2_accrual_defnEnumList, Feature(true)),
	Descriptor(278, Attribute::DOUBLE,	"purch_sec_pac2_z_accrual_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_pac2_z_accrual_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(279, Attribute::DOUBLE,	"purch_sec_pac2a_sch", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_pac2a_sch,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(280, Attribute::DOUBLE,	"purch_sec_pac2b_sch", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_pac2b_sch,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(281, Attribute::DOUBLE,	"purch_sec_pac3_sch", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_pac3_sch,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(282, Attribute::DOUBLE,	"purch_sec_pac3_z_accrual_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_pac3_z_accrual_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(283, Attribute::DOUBLE,	"purch_sec_rbc_c1_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_rbc_c1_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(284, Attribute::STR_ENUM,	"purch_sec_sale_class", -1, (size_t)&modelOffset->purch_sec_sale_class,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_sec_sale_classEnumList, Feature(true)),
	Descriptor(285, Attribute::DOUBLE,	"purch_sec_tranche_a_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_tranche_a_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(286, Attribute::DOUBLE,	"purch_sec_tranche_b_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_tranche_b_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(287, Attribute::DOUBLE,	"purch_sec_tranche_c_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_tranche_c_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(288, Attribute::STR_ENUM,	"purch_sec_tranche_owned", -1, (size_t)&modelOffset->purch_sec_tranche_owned,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_sec_tranche_ownedEnumList, Feature(true)),
	Descriptor(289, Attribute::DOUBLE,	"purch_sec_tranche_rate_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_tranche_rate_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(290, Attribute::STRING,	"purch_sec_tranche_rate_category_id", -1, (size_t)&modelOffset->purch_sec_tranche_rate_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(291, Attribute::STR_ENUM,	"purch_sec_tranche_rate_defn", -1, (size_t)&modelOffset->purch_sec_tranche_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_sec_tranche_rate_defnEnumList, Feature(true)),
	Descriptor(292, Attribute::DOUBLE,	"purch_sec_tranche_rate_max_decr_from_init", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_tranche_rate_max_decr_from_init,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(293, Attribute::DOUBLE,	"purch_sec_tranche_rate_max_incr_from_init", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_tranche_rate_max_incr_from_init,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(294, Attribute::DOUBLE,	"purch_sec_tranche_rate_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_tranche_rate_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(295, Attribute::DOUBLE,	"purch_sec_tranche_rate_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_tranche_rate_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(296, Attribute::DOUBLE,	"purch_sec_tranche_z_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_tranche_z_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(297, Attribute::STR_ENUM,	"purch_sec_tranche_z_defn", -1, (size_t)&modelOffset->purch_sec_tranche_z_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_sec_tranche_z_defnEnumList, Feature(true)),
	Descriptor(298, Attribute::DOUBLE,	"purch_sec_tranche_z_jump_speed", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_tranche_z_jump_speed,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(299, Attribute::DOUBLE,	"purch_sec_tranche_z_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->purch_sec_tranche_z_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(300, Attribute::STR_ENUM,	"purch_sec_tranche_z_prepmt_priority_bef_jump", -1, (size_t)&modelOffset->purch_sec_tranche_z_prepmt_priority_bef_jump,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &purch_sec_tranche_z_prepmt_priority_bef_jumpEnumList, Feature(true)),
	Descriptor(301, Attribute::STR_ENUM,	"rebal_dur_match_defn", -1, (size_t)&modelOffset->rebal_dur_match_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &rebal_dur_match_defnEnumList, Feature(true)),
	Descriptor(302, Attribute::STR_ENUM,	"rebal_freq", -1, (size_t)&modelOffset->rebal_freq,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &rebal_freqEnumList, Feature(true)),
	Descriptor(303, Attribute::INT,	"rebal_sale_priority_avail_for_sale", -1, (size_t)&modelOffset->rebal_sale_priority_avail_for_sale,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(304, Attribute::INT,	"rebal_sale_priority_held_to_maturity", -1, (size_t)&modelOffset->rebal_sale_priority_held_to_maturity,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(305, Attribute::INT,	"rebal_sale_priority_not_assigned", -1, (size_t)&modelOffset->rebal_sale_priority_not_assigned,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(306, Attribute::INT,	"rebal_sale_priority_trading", -1, (size_t)&modelOffset->rebal_sale_priority_trading,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(307, Attribute::STR_ENUM,	"rebal_sale_selection_defn", -1, (size_t)&modelOffset->rebal_sale_selection_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &rebal_sale_selection_defnEnumList, Feature(true)),
	Descriptor(308, Attribute::STRING,	"refinance_inv_id", -1, (size_t)&modelOffset->refinance_inv_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(309, Attribute::DOUBLE,	"restructure_int_pmt_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->restructure_int_pmt_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(310, Attribute::STRING,	"restructure_inv_id", -1, (size_t)&modelOffset->restructure_inv_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(311, Attribute::DOUBLE,	"restructure_prin_pmt_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->restructure_prin_pmt_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(312, Attribute::STRING,	"seg_id", -1, (size_t)&modelOffset->seg_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(313, Attribute::INT,	"yrs_to_inv_mthly", -1, (size_t)&modelOffset->yrs_to_inv_mthly,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(314, Attribute::INT,	"yrs_to_inv_qtrly", -1, (size_t)&modelOffset->yrs_to_inv_qtrly,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(315, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(316, Attribute::SCALAR_INT,	"final_period", -1, (size_t)&modelOffset->final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INVSTRAT_ASSET_UDF::invstrat_asset_final_period)),
	Descriptor(317, Attribute::SCALAR_INT,	"foreclosure_asset_id", -1, (size_t)&modelOffset->foreclosure_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INVSTRAT_ASSET_UDF::invstrat_asset_foreclosure_asset_id)),
	Descriptor(318, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&INVSTRAT_ASSET_UDF::invstrat_asset_proj_date_adj)),
	Descriptor(319, Attribute::SCALAR_INT,	"proj_start_date", -1, (size_t)&modelOffset->proj_start_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INVSTRAT_ASSET_UDF::invstrat_asset_proj_start_date)),
	Descriptor(320, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INVSTRAT_ASSET_UDF::invstrat_asset_proj_start_mth)),
	Descriptor(321, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INVSTRAT_ASSET_UDF::invstrat_asset_proj_start_yr)),
	Descriptor(322, Attribute::SCALAR_INT,	"rebal_sales_priority_class_max", -1, (size_t)&modelOffset->rebal_sales_priority_class_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INVSTRAT_ASSET_UDF::invstrat_asset_rebal_sales_priority_class_max)),
	Descriptor(323, Attribute::SCALAR_INT,	"refinance_asset_id", -1, (size_t)&modelOffset->refinance_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INVSTRAT_ASSET_UDF::invstrat_asset_refinance_asset_id)),
	Descriptor(324, Attribute::SCALAR_INT,	"restructure_asset_id", -1, (size_t)&modelOffset->restructure_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INVSTRAT_ASSET_UDF::invstrat_asset_restructure_asset_id)),
	Descriptor(325, Attribute::SCALAR_INT,	"sales_priority_sub_port_max", -1, (size_t)&modelOffset->sales_priority_sub_port_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INVSTRAT_ASSET_UDF::invstrat_asset_sales_priority_sub_port_max)),
	Descriptor(326, Attribute::SCALAR_INT,	"seg_num", -1, (size_t)&modelOffset->seg_num,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INVSTRAT_ASSET_UDF::invstrat_asset_seg_num)),
	Descriptor(327, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INVSTRAT_ASSET_UDF::invstrat_asset_start_period)),
	};

	Attribute::Descriptor* INVSTRAT_ASSET::descriptorTable[] = {
	&INVSTRAT_ASSET::descriptor_0[0],
	&INVSTRAT_ASSET::descriptor_0[1],
	&INVSTRAT_ASSET::descriptor_0[2],
	&INVSTRAT_ASSET::descriptor_0[3],
	&INVSTRAT_ASSET::descriptor_0[4],
	&INVSTRAT_ASSET::descriptor_0[5],
	&INVSTRAT_ASSET::descriptor_0[6],
	&INVSTRAT_ASSET::descriptor_0[7],
	&INVSTRAT_ASSET::descriptor_0[8],
	&INVSTRAT_ASSET::descriptor_0[9],
	&INVSTRAT_ASSET::descriptor_0[10],
	&INVSTRAT_ASSET::descriptor_0[11],
	&INVSTRAT_ASSET::descriptor_0[12],
	&INVSTRAT_ASSET::descriptor_0[13],
	&INVSTRAT_ASSET::descriptor_0[14],
	&INVSTRAT_ASSET::descriptor_0[15],
	&INVSTRAT_ASSET::descriptor_0[16],
	&INVSTRAT_ASSET::descriptor_0[17],
	&INVSTRAT_ASSET::descriptor_0[18],
	&INVSTRAT_ASSET::descriptor_0[19],
	&INVSTRAT_ASSET::descriptor_0[20],
	&INVSTRAT_ASSET::descriptor_0[21],
	&INVSTRAT_ASSET::descriptor_0[22],
	&INVSTRAT_ASSET::descriptor_0[23],
	&INVSTRAT_ASSET::descriptor_0[24],
	&INVSTRAT_ASSET::descriptor_0[25],
	&INVSTRAT_ASSET::descriptor_0[26],
	&INVSTRAT_ASSET::descriptor_0[27],
	&INVSTRAT_ASSET::descriptor_0[28],
	&INVSTRAT_ASSET::descriptor_0[29],
	&INVSTRAT_ASSET::descriptor_0[30],
	&INVSTRAT_ASSET::descriptor_0[31],
	&INVSTRAT_ASSET::descriptor_0[32],
	&INVSTRAT_ASSET::descriptor_0[33],
	&INVSTRAT_ASSET::descriptor_0[34],
	&INVSTRAT_ASSET::descriptor_0[35],
	&INVSTRAT_ASSET::descriptor_0[36],
	&INVSTRAT_ASSET::descriptor_0[37],
	&INVSTRAT_ASSET::descriptor_0[38],
	&INVSTRAT_ASSET::descriptor_0[39],
	&INVSTRAT_ASSET::descriptor_0[40],
	&INVSTRAT_ASSET::descriptor_0[41],
	&INVSTRAT_ASSET::descriptor_0[42],
	&INVSTRAT_ASSET::descriptor_0[43],
	&INVSTRAT_ASSET::descriptor_0[44],
	&INVSTRAT_ASSET::descriptor_0[45],
	&INVSTRAT_ASSET::descriptor_0[46],
	&INVSTRAT_ASSET::descriptor_0[47],
	&INVSTRAT_ASSET::descriptor_0[48],
	&INVSTRAT_ASSET::descriptor_0[49],
	&INVSTRAT_ASSET::descriptor_0[50],
	&INVSTRAT_ASSET::descriptor_0[51],
	&INVSTRAT_ASSET::descriptor_0[52],
	&INVSTRAT_ASSET::descriptor_0[53],
	&INVSTRAT_ASSET::descriptor_0[54],
	&INVSTRAT_ASSET::descriptor_0[55],
	&INVSTRAT_ASSET::descriptor_0[56],
	&INVSTRAT_ASSET::descriptor_0[57],
	&INVSTRAT_ASSET::descriptor_0[58],
	&INVSTRAT_ASSET::descriptor_0[59],
	&INVSTRAT_ASSET::descriptor_0[60],
	&INVSTRAT_ASSET::descriptor_0[61],
	&INVSTRAT_ASSET::descriptor_0[62],
	&INVSTRAT_ASSET::descriptor_0[63],
	&INVSTRAT_ASSET::descriptor_0[64],
	&INVSTRAT_ASSET::descriptor_0[65],
	&INVSTRAT_ASSET::descriptor_0[66],
	&INVSTRAT_ASSET::descriptor_0[67],
	&INVSTRAT_ASSET::descriptor_0[68],
	&INVSTRAT_ASSET::descriptor_0[69],
	&INVSTRAT_ASSET::descriptor_0[70],
	&INVSTRAT_ASSET::descriptor_0[71],
	&INVSTRAT_ASSET::descriptor_0[72],
	&INVSTRAT_ASSET::descriptor_0[73],
	&INVSTRAT_ASSET::descriptor_0[74],
	&INVSTRAT_ASSET::descriptor_0[75],
	&INVSTRAT_ASSET::descriptor_0[76],
	&INVSTRAT_ASSET::descriptor_0[77],
	&INVSTRAT_ASSET::descriptor_0[78],
	&INVSTRAT_ASSET::descriptor_0[79],
	&INVSTRAT_ASSET::descriptor_0[80],
	&INVSTRAT_ASSET::descriptor_0[81],
	&INVSTRAT_ASSET::descriptor_0[82],
	&INVSTRAT_ASSET::descriptor_0[83],
	&INVSTRAT_ASSET::descriptor_0[84],
	&INVSTRAT_ASSET::descriptor_0[85],
	&INVSTRAT_ASSET::descriptor_0[86],
	&INVSTRAT_ASSET::descriptor_0[87],
	&INVSTRAT_ASSET::descriptor_0[88],
	&INVSTRAT_ASSET::descriptor_0[89],
	&INVSTRAT_ASSET::descriptor_0[90],
	&INVSTRAT_ASSET::descriptor_0[91],
	&INVSTRAT_ASSET::descriptor_0[92],
	&INVSTRAT_ASSET::descriptor_0[93],
	&INVSTRAT_ASSET::descriptor_0[94],
	&INVSTRAT_ASSET::descriptor_0[95],
	&INVSTRAT_ASSET::descriptor_0[96],
	&INVSTRAT_ASSET::descriptor_0[97],
	&INVSTRAT_ASSET::descriptor_0[98],
	&INVSTRAT_ASSET::descriptor_0[99],
	&INVSTRAT_ASSET::descriptor_0[100],
	&INVSTRAT_ASSET::descriptor_0[101],
	&INVSTRAT_ASSET::descriptor_0[102],
	&INVSTRAT_ASSET::descriptor_0[103],
	&INVSTRAT_ASSET::descriptor_0[104],
	&INVSTRAT_ASSET::descriptor_0[105],
	&INVSTRAT_ASSET::descriptor_0[106],
	&INVSTRAT_ASSET::descriptor_0[107],
	&INVSTRAT_ASSET::descriptor_0[108],
	&INVSTRAT_ASSET::descriptor_0[109],
	&INVSTRAT_ASSET::descriptor_0[110],
	&INVSTRAT_ASSET::descriptor_0[111],
	&INVSTRAT_ASSET::descriptor_0[112],
	&INVSTRAT_ASSET::descriptor_0[113],
	&INVSTRAT_ASSET::descriptor_0[114],
	&INVSTRAT_ASSET::descriptor_0[115],
	&INVSTRAT_ASSET::descriptor_0[116],
	&INVSTRAT_ASSET::descriptor_0[117],
	&INVSTRAT_ASSET::descriptor_0[118],
	&INVSTRAT_ASSET::descriptor_0[119],
	&INVSTRAT_ASSET::descriptor_0[120],
	&INVSTRAT_ASSET::descriptor_0[121],
	&INVSTRAT_ASSET::descriptor_0[122],
	&INVSTRAT_ASSET::descriptor_0[123],
	&INVSTRAT_ASSET::descriptor_0[124],
	&INVSTRAT_ASSET::descriptor_0[125],
	&INVSTRAT_ASSET::descriptor_0[126],
	&INVSTRAT_ASSET::descriptor_0[127],
	&INVSTRAT_ASSET::descriptor_0[128],
	&INVSTRAT_ASSET::descriptor_0[129],
	&INVSTRAT_ASSET::descriptor_0[130],
	&INVSTRAT_ASSET::descriptor_0[131],
	&INVSTRAT_ASSET::descriptor_0[132],
	&INVSTRAT_ASSET::descriptor_0[133],
	&INVSTRAT_ASSET::descriptor_0[134],
	&INVSTRAT_ASSET::descriptor_0[135],
	&INVSTRAT_ASSET::descriptor_0[136],
	&INVSTRAT_ASSET::descriptor_0[137],
	&INVSTRAT_ASSET::descriptor_0[138],
	&INVSTRAT_ASSET::descriptor_0[139],
	&INVSTRAT_ASSET::descriptor_0[140],
	&INVSTRAT_ASSET::descriptor_0[141],
	&INVSTRAT_ASSET::descriptor_0[142],
	&INVSTRAT_ASSET::descriptor_0[143],
	&INVSTRAT_ASSET::descriptor_0[144],
	&INVSTRAT_ASSET::descriptor_0[145],
	&INVSTRAT_ASSET::descriptor_0[146],
	&INVSTRAT_ASSET::descriptor_0[147],
	&INVSTRAT_ASSET::descriptor_0[148],
	&INVSTRAT_ASSET::descriptor_0[149],
	&INVSTRAT_ASSET::descriptor_0[150],
	&INVSTRAT_ASSET::descriptor_0[151],
	&INVSTRAT_ASSET::descriptor_0[152],
	&INVSTRAT_ASSET::descriptor_0[153],
	&INVSTRAT_ASSET::descriptor_0[154],
	&INVSTRAT_ASSET::descriptor_0[155],
	&INVSTRAT_ASSET::descriptor_0[156],
	&INVSTRAT_ASSET::descriptor_0[157],
	&INVSTRAT_ASSET::descriptor_0[158],
	&INVSTRAT_ASSET::descriptor_0[159],
	&INVSTRAT_ASSET::descriptor_0[160],
	&INVSTRAT_ASSET::descriptor_0[161],
	&INVSTRAT_ASSET::descriptor_0[162],
	&INVSTRAT_ASSET::descriptor_0[163],
	&INVSTRAT_ASSET::descriptor_0[164],
	&INVSTRAT_ASSET::descriptor_0[165],
	&INVSTRAT_ASSET::descriptor_0[166],
	&INVSTRAT_ASSET::descriptor_0[167],
	&INVSTRAT_ASSET::descriptor_0[168],
	&INVSTRAT_ASSET::descriptor_0[169],
	&INVSTRAT_ASSET::descriptor_0[170],
	&INVSTRAT_ASSET::descriptor_0[171],
	&INVSTRAT_ASSET::descriptor_0[172],
	&INVSTRAT_ASSET::descriptor_0[173],
	&INVSTRAT_ASSET::descriptor_0[174],
	&INVSTRAT_ASSET::descriptor_0[175],
	&INVSTRAT_ASSET::descriptor_0[176],
	&INVSTRAT_ASSET::descriptor_0[177],
	&INVSTRAT_ASSET::descriptor_0[178],
	&INVSTRAT_ASSET::descriptor_0[179],
	&INVSTRAT_ASSET::descriptor_0[180],
	&INVSTRAT_ASSET::descriptor_0[181],
	&INVSTRAT_ASSET::descriptor_0[182],
	&INVSTRAT_ASSET::descriptor_0[183],
	&INVSTRAT_ASSET::descriptor_0[184],
	&INVSTRAT_ASSET::descriptor_0[185],
	&INVSTRAT_ASSET::descriptor_0[186],
	&INVSTRAT_ASSET::descriptor_0[187],
	&INVSTRAT_ASSET::descriptor_0[188],
	&INVSTRAT_ASSET::descriptor_0[189],
	&INVSTRAT_ASSET::descriptor_0[190],
	&INVSTRAT_ASSET::descriptor_0[191],
	&INVSTRAT_ASSET::descriptor_0[192],
	&INVSTRAT_ASSET::descriptor_0[193],
	&INVSTRAT_ASSET::descriptor_0[194],
	&INVSTRAT_ASSET::descriptor_0[195],
	&INVSTRAT_ASSET::descriptor_0[196],
	&INVSTRAT_ASSET::descriptor_0[197],
	&INVSTRAT_ASSET::descriptor_0[198],
	&INVSTRAT_ASSET::descriptor_0[199],
	&INVSTRAT_ASSET::descriptor_0[200],
	&INVSTRAT_ASSET::descriptor_0[201],
	&INVSTRAT_ASSET::descriptor_0[202],
	&INVSTRAT_ASSET::descriptor_0[203],
	&INVSTRAT_ASSET::descriptor_0[204],
	&INVSTRAT_ASSET::descriptor_0[205],
	&INVSTRAT_ASSET::descriptor_0[206],
	&INVSTRAT_ASSET::descriptor_0[207],
	&INVSTRAT_ASSET::descriptor_0[208],
	&INVSTRAT_ASSET::descriptor_0[209],
	&INVSTRAT_ASSET::descriptor_0[210],
	&INVSTRAT_ASSET::descriptor_0[211],
	&INVSTRAT_ASSET::descriptor_0[212],
	&INVSTRAT_ASSET::descriptor_0[213],
	&INVSTRAT_ASSET::descriptor_0[214],
	&INVSTRAT_ASSET::descriptor_0[215],
	&INVSTRAT_ASSET::descriptor_0[216],
	&INVSTRAT_ASSET::descriptor_0[217],
	&INVSTRAT_ASSET::descriptor_0[218],
	&INVSTRAT_ASSET::descriptor_0[219],
	&INVSTRAT_ASSET::descriptor_0[220],
	&INVSTRAT_ASSET::descriptor_0[221],
	&INVSTRAT_ASSET::descriptor_0[222],
	&INVSTRAT_ASSET::descriptor_0[223],
	&INVSTRAT_ASSET::descriptor_0[224],
	&INVSTRAT_ASSET::descriptor_0[225],
	&INVSTRAT_ASSET::descriptor_0[226],
	&INVSTRAT_ASSET::descriptor_0[227],
	&INVSTRAT_ASSET::descriptor_0[228],
	&INVSTRAT_ASSET::descriptor_0[229],
	&INVSTRAT_ASSET::descriptor_0[230],
	&INVSTRAT_ASSET::descriptor_0[231],
	&INVSTRAT_ASSET::descriptor_0[232],
	&INVSTRAT_ASSET::descriptor_0[233],
	&INVSTRAT_ASSET::descriptor_0[234],
	&INVSTRAT_ASSET::descriptor_0[235],
	&INVSTRAT_ASSET::descriptor_0[236],
	&INVSTRAT_ASSET::descriptor_0[237],
	&INVSTRAT_ASSET::descriptor_0[238],
	&INVSTRAT_ASSET::descriptor_0[239],
	&INVSTRAT_ASSET::descriptor_0[240],
	&INVSTRAT_ASSET::descriptor_0[241],
	&INVSTRAT_ASSET::descriptor_0[242],
	&INVSTRAT_ASSET::descriptor_0[243],
	&INVSTRAT_ASSET::descriptor_0[244],
	&INVSTRAT_ASSET::descriptor_0[245],
	&INVSTRAT_ASSET::descriptor_0[246],
	&INVSTRAT_ASSET::descriptor_0[247],
	&INVSTRAT_ASSET::descriptor_0[248],
	&INVSTRAT_ASSET::descriptor_0[249],
	&INVSTRAT_ASSET::descriptor_0[250],
	&INVSTRAT_ASSET::descriptor_0[251],
	&INVSTRAT_ASSET::descriptor_0[252],
	&INVSTRAT_ASSET::descriptor_0[253],
	&INVSTRAT_ASSET::descriptor_0[254],
	&INVSTRAT_ASSET::descriptor_0[255],
	&INVSTRAT_ASSET::descriptor_256[0],
	&INVSTRAT_ASSET::descriptor_256[1],
	&INVSTRAT_ASSET::descriptor_256[2],
	&INVSTRAT_ASSET::descriptor_256[3],
	&INVSTRAT_ASSET::descriptor_256[4],
	&INVSTRAT_ASSET::descriptor_256[5],
	&INVSTRAT_ASSET::descriptor_256[6],
	&INVSTRAT_ASSET::descriptor_256[7],
	&INVSTRAT_ASSET::descriptor_256[8],
	&INVSTRAT_ASSET::descriptor_256[9],
	&INVSTRAT_ASSET::descriptor_256[10],
	&INVSTRAT_ASSET::descriptor_256[11],
	&INVSTRAT_ASSET::descriptor_256[12],
	&INVSTRAT_ASSET::descriptor_256[13],
	&INVSTRAT_ASSET::descriptor_256[14],
	&INVSTRAT_ASSET::descriptor_256[15],
	&INVSTRAT_ASSET::descriptor_256[16],
	&INVSTRAT_ASSET::descriptor_256[17],
	&INVSTRAT_ASSET::descriptor_256[18],
	&INVSTRAT_ASSET::descriptor_256[19],
	&INVSTRAT_ASSET::descriptor_256[20],
	&INVSTRAT_ASSET::descriptor_256[21],
	&INVSTRAT_ASSET::descriptor_256[22],
	&INVSTRAT_ASSET::descriptor_256[23],
	&INVSTRAT_ASSET::descriptor_256[24],
	&INVSTRAT_ASSET::descriptor_256[25],
	&INVSTRAT_ASSET::descriptor_256[26],
	&INVSTRAT_ASSET::descriptor_256[27],
	&INVSTRAT_ASSET::descriptor_256[28],
	&INVSTRAT_ASSET::descriptor_256[29],
	&INVSTRAT_ASSET::descriptor_256[30],
	&INVSTRAT_ASSET::descriptor_256[31],
	&INVSTRAT_ASSET::descriptor_256[32],
	&INVSTRAT_ASSET::descriptor_256[33],
	&INVSTRAT_ASSET::descriptor_256[34],
	&INVSTRAT_ASSET::descriptor_256[35],
	&INVSTRAT_ASSET::descriptor_256[36],
	&INVSTRAT_ASSET::descriptor_256[37],
	&INVSTRAT_ASSET::descriptor_256[38],
	&INVSTRAT_ASSET::descriptor_256[39],
	&INVSTRAT_ASSET::descriptor_256[40],
	&INVSTRAT_ASSET::descriptor_256[41],
	&INVSTRAT_ASSET::descriptor_256[42],
	&INVSTRAT_ASSET::descriptor_256[43],
	&INVSTRAT_ASSET::descriptor_256[44],
	&INVSTRAT_ASSET::descriptor_256[45],
	&INVSTRAT_ASSET::descriptor_256[46],
	&INVSTRAT_ASSET::descriptor_256[47],
	&INVSTRAT_ASSET::descriptor_256[48],
	&INVSTRAT_ASSET::descriptor_256[49],
	&INVSTRAT_ASSET::descriptor_256[50],
	&INVSTRAT_ASSET::descriptor_256[51],
	&INVSTRAT_ASSET::descriptor_256[52],
	&INVSTRAT_ASSET::descriptor_256[53],
	&INVSTRAT_ASSET::descriptor_256[54],
	&INVSTRAT_ASSET::descriptor_256[55],
	&INVSTRAT_ASSET::descriptor_256[56],
	&INVSTRAT_ASSET::descriptor_256[57],
	&INVSTRAT_ASSET::descriptor_256[58],
	&INVSTRAT_ASSET::descriptor_256[59],
	&INVSTRAT_ASSET::descriptor_256[60],
	&INVSTRAT_ASSET::descriptor_256[61],
	&INVSTRAT_ASSET::descriptor_256[62],
	&INVSTRAT_ASSET::descriptor_256[63],
	&INVSTRAT_ASSET::descriptor_256[64],
	&INVSTRAT_ASSET::descriptor_256[65],
	&INVSTRAT_ASSET::descriptor_256[66],
	&INVSTRAT_ASSET::descriptor_256[67],
	&INVSTRAT_ASSET::descriptor_256[68],
	&INVSTRAT_ASSET::descriptor_256[69],
	&INVSTRAT_ASSET::descriptor_256[70],
	&INVSTRAT_ASSET::descriptor_256[71],
	nullptr};
	const size_t INVSTRAT_ASSET::sDescriptorCount = 328;

//factory
INVSTRAT_ASSET* INVSTRAT_ASSET::makeThis(int isSubmodel, ModelClass* owner, INVSTRAT_ASSET* peer, 
						int mainRebase, const xstring &name, INVSTRAT_ASSET_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("INVSTRAT_ASSET::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor INVSTRAT_ASSET");
#endif
	INVSTRAT_ASSET* newP = (INVSTRAT_ASSET*)new INVSTRAT_ASSET_UDF
   	  ("invstrat_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
INVSTRAT_ASSET_persistent_object* INVSTRAT_ASSET_persistent_object::makeThis(int isSubmodel, ModelClass* owner, INVSTRAT_ASSET* peer, 
							int mainRebase, const xstring &name, INVSTRAT_ASSET_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("INVSTRAT_ASSET_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor INVSTRAT_ASSET_persistent_object");
#endif
	INVSTRAT_ASSET_persistent_object* newP = (INVSTRAT_ASSET_persistent_object*)new INVSTRAT_ASSET_persistent_object
   	  ("invstrat_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			INVSTRAT_ASSET_persistent_object* pd = dynamic_cast<INVSTRAT_ASSET_persistent_object*>(product);
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

typedef double (INVSTRAT_ASSET_UDF::*dPF) ();
typedef double (INVSTRAT_ASSET_UDF::*dPFd) (double);
typedef int (INVSTRAT_ASSET_UDF::*iPF) ();
typedef int (INVSTRAT_ASSET_UDF::*iPFi) (int);
typedef xstring (INVSTRAT_ASSET_UDF::*sPF) ();
typedef xstring (INVSTRAT_ASSET_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
INVSTRAT_ASSET::INVSTRAT_ASSET(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)

	, adco(company_asset_adco)
	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, asset_sub_port(company_asset_asset_sub_port)
	, bond(company_asset_bond)
	, bond_cf(company_asset_bond_bond_cf)
	, bond_cf_var(company_asset_bond_bond_cf_var)
	, eio(company_asset_eio)
	, epa(company_asset_epa)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_ann_pba(company_liab_fia_fia_ann_pba)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_mrb(company_liab_fia_fia_mrb)
	, fia_rates(company_liab_fia_fia_rates)
	, fia_sfas97rd(company_liab_fia_fia_sfas97rd)
	, hedge_grp(company_seg_hedge_grp)
	, inv_strategy(company_inv_strategy)
	, liab(company_liab)
	, mtg(company_asset_mtg)
	, mtg_cf(company_asset_mtg_mtg_cf)
	, mtg_cf_var(company_asset_mtg_mtg_cf_var)
	, rates(company_rates)
	, seg(company_seg)
	, sfas97rd(company_seg_sfas97rd)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	RegisterTerminatorOnce();
	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (INVSTRAT_ASSET_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
INVSTRAT_ASSET::INVSTRAT_ASSET(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(55, INVSTRAT_ASSET::descriptorTable, arrayPersistentObj), Variable(*this)

	, adco(company_asset_adco)
	, ann_pba(company_seg_ann_pba)
	, asset(company_asset)
	, asset_sub_port(company_asset_asset_sub_port)
	, bond(company_asset_bond)
	, bond_cf(company_asset_bond_bond_cf)
	, bond_cf_var(company_asset_bond_bond_cf_var)
	, eio(company_asset_eio)
	, epa(company_asset_epa)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, fia_account(company_liab_fia_fia_account)
	, fia_ann_pba(company_liab_fia_fia_ann_pba)
	, fia_carvm_stat(company_liab_fia_carvm_stat)
	, fia_carvm_tax(company_liab_fia_carvm_tax)
	, fia_mrb(company_liab_fia_fia_mrb)
	, fia_rates(company_liab_fia_fia_rates)
	, fia_sfas97rd(company_liab_fia_fia_sfas97rd)
	, hedge_grp(company_seg_hedge_grp)
	, inv_strategy(company_inv_strategy)
	, liab(company_liab)
	, mtg(company_asset_mtg)
	, mtg_cf(company_asset_mtg_mtg_cf)
	, mtg_cf_var(company_asset_mtg_mtg_cf_var)
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
#ifdef __CREATE_A_SUBPORT_ASSET_CLASS_
       company_asset_asset_sub_port = 0;
#endif
#ifdef __CREATE_BOND_ASSET_CLASS_
       company_asset_bond = 0;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
       company_asset_bond_bond_cf = 0;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
       company_asset_bond_bond_cf_var = 0;
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
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
       company_asset_mtg_mtg_cf_var = 0;
#endif
#ifdef __CREATE_INVSTRAT_ASSET_CLASS_
       company_inv_strategy = 0;
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
#ifdef __CREATE_HDG_GRP_COMP_CLASS_
       company_seg_hedge_grp = 0;
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

	for (int cf_no = 1; cf_no <= 55; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (INVSTRAT_ASSET_UDF::*dPXi2) (int, int);
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


 void INVSTRAT_ASSET::copy_names() {

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
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
		company_asset_bond_bond_cf_var = (BOND_CF_ASSET*)(findUnique("company|asset|bond|bond_cf_var"));
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
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
		company_asset_mtg_mtg_cf_var = (MTG_CF_ASSET*)(findUnique("company|asset|mtg|mtg_cf_var"));
#endif
#ifdef __CREATE_INVSTRAT_ASSET_CLASS_
		company_inv_strategy = (INVSTRAT_ASSET*)(findUnique("company|inv_strategy"));
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
#ifdef __CREATE_HDG_GRP_COMP_CLASS_
		company_seg_hedge_grp = (HDG_GRP_COMP*)(findUnique("company|seg|hedge_grp"));
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
		company_seg_sfas97rd = (SFAS97RD_GAAP*)(findUnique("company|seg|sfas97rd"));
#endif
 }
//copy_names END@2


 void INVSTRAT_ASSET::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int INVSTRAT_ASSET_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& INVSTRAT_ASSET_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double INVSTRAT_ASSET_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int INVSTRAT_ASSET_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double INVSTRAT_ASSET_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double INVSTRAT_ASSET_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void INVSTRAT_ASSET_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void INVSTRAT_ASSET_persistent_object::write(long include_submodels) {
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

	void INVSTRAT_ASSET_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void INVSTRAT_ASSET_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void INVSTRAT_ASSET_persistent_object::write(const xstring& key, long include_submodels) {
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




	INVSTRAT_ASSET_persistent_object::~INVSTRAT_ASSET_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool INVSTRAT_ASSET_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void INVSTRAT_ASSET_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void INVSTRAT_ASSET_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void INVSTRAT_ASSET_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void INVSTRAT_ASSET_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void INVSTRAT_ASSET_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* INVSTRAT_ASSET_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* INVSTRAT_ASSET_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* INVSTRAT_ASSET_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char INVSTRAT_ASSET_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void INVSTRAT_ASSET_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
INVSTRAT_ASSET_persistent_object::INVSTRAT_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			INVSTRAT_ASSET(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
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
INVSTRAT_ASSET::~INVSTRAT_ASSET() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void INVSTRAT_ASSET::findTargetColumns() {

}
//findTargetColumns END@2
void INVSTRAT_ASSET::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void INVSTRAT_ASSET::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void INVSTRAT_ASSET::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void INVSTRAT_ASSET::start_of_projection() {
}
//start_of_projection END@2

void INVSTRAT_ASSET::end_of_projection() {
}
//end_of_projection END@2

void INVSTRAT_ASSET::start_of_layer() {
}


void INVSTRAT_ASSET::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void INVSTRAT_ASSET::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void INVSTRAT_ASSET::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void INVSTRAT_ASSET::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> INVSTRAT_ASSET::ddfVector;
BitArray INVSTRAT_ASSET::dataVariables(328);
bool INVSTRAT_ASSET::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool INVSTRAT_ASSET::writeClassInfo = true;

void INVSTRAT_ASSET::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, INVSTRAT_ASSET::descriptor_0>::dT = INVSTRAT_ASSET::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, INVSTRAT_ASSET::descriptor_0>::dT = INVSTRAT_ASSET::descriptor_0;
Descriptor* Attribute::Proxy<StrEnum::StringEnum, INVSTRAT_ASSET::descriptor_256>::dT = INVSTRAT_ASSET::descriptor_256;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, INVSTRAT_ASSET::descriptor_256>::dT = INVSTRAT_ASSET::descriptor_256;

