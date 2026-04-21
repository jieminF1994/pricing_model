
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
#include "ModelClass\bond_portfolio_aig_udf.h"
#include "ModelClass\adco_asset.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\asset_asset.h"
#include "ModelClass\automation.h"
#include "ModelClass\a_subport_asset.h"
#include "ModelClass\bond_aig.h"
#include "ModelClass\bond_asset.h"
#include "ModelClass\bond_cf_asset.h"
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
#ifndef bond_portfolio_aig_TableDefs
#define bond_portfolio_aig_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection BOND_PORTFOLIO_AIG::TTHC;
void BOND_PORTFOLIO_AIG::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - asset_amt_b_aig
// Bond Asset Amount, Beginning of Period                                                                                             
// Column:ASSET_AMT_B_AIG
//========================================================
double BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_asset_amt_b_aig(int t) {
//^^^



//^^^

#line 1 "asset_amt_b_aig.BOND_PORTFOLIO_AIG.for"
/*! AIG Bond Portfolio Asset Amount, Beginning of Period
	====================================================
	@author Michael Ching
	@date 20181119
 
	This is a simple rollforward from the previous period:

	\f[
	assets\,beginning\,of\,period_{t} = assets\,end\,of\,period_{t - 1}
	\f]

	Where:
	-# \f$assets\,end\,of\,period_{t - 1}\f$ is the assets at the end of the previous period, 
	   calculated in bond_portfolio_aig_asset_amt_e_aig().
 
	Related Inputs:
	---------------
	None.
 
	@return Nothing.
*/
if (t <= commencement_period || t > final_period || !initialize_bond_portfolio_aig)//WTW - Gen2 - time guards
	return NO_AVG;

if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->asset_amt_b_aig at period " << t << MSG_USER;
}

return asset_amt_e_aig(t - 1);

}


//@@ END

//@@ START - asset_amt_e_aig
// Bond Asset Amount, End of Period                                                                                             
// Column:ASSET_AMT_E_AIG
//========================================================
double BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_asset_amt_e_aig(int t) {
//^^^



//^^^

#line 1 "asset_amt_e_aig.BOND_PORTFOLIO_AIG.for"
/*! AIG Bond Portfolio Asset Amount, End of Period
	==============================================
	@author Michael Ching
	@date 20181119
 
	This is a rollforward from the beginning of the period:

	\f[
	assets\,end\,of\,period_{t} = assets\,beginning\,of\,period_{t} + coupons_{t}
	\f]

	Where:
	-# \f$assets\,beginning\,of\,period_{t}\f$ is the assets at the beginning of the period,
	   calculated in bond_portfolio_aig_asset_amt_b_aig() and
	-# \f$coupons_{t}\f$ is the coupon from the asset at time \f$t\f$, calculated in
	   bond_portfolio_aig_coupon_amt_aig()

	Note that there are no assets until the end of the first period.
 
	Related Inputs:
	---------------
	None.
 
	@return Nothing.
*/
if (t <= commencement_period || t > final_period || !initialize_bond_portfolio_aig)//WTW - Gen2 - time guards
	return NO_AVG;

if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->asset_amt_e_aig at period " << t << MSG_USER;
}

if (t == commencement_period + 1)
{
	// Establish a radix at period 1
	return 1000.0; // radix
}
else
{
	double coupon_amt = coupon_amt_aig(t);
	double asset_amt_b = asset_amt_b_aig(t);

	return asset_amt_b + coupon_amt;
}

}


//@@ END

//@@ START - asset_amt_matured_aig
// Asset Amount Matured, End of Period                                                                                             
// Column:ASSET_AMT_MATURED_AIG
//========================================================
double BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_asset_amt_matured_aig(int t) {
//^^^



//^^^

#line 1 "asset_amt_matured_aig.BOND_PORTFOLIO_AIG.for"
/*! AIG Bond Portfolio Matured Asset Amount, End of Period
	======================================================
	@author Michael Ching
	@date 20181119
 
	This column is an aggregate of the maturity amounts for each bond in the portfolio.

	Individual bond maturity amounts are calculated in BOND_AIG_UDF::bond_aig_asset_amt_matured_aig().
 
	Related Inputs:
	---------------
	None.
 
	@return Nothing.
*/
if (t <= commencement_period || t > final_period || !initialize_bond_portfolio_aig)//WTW - Gen2 - time guards
	return NO_AVG;

if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->asset_amt_matured_aig at period " << t << MSG_USER;
}

// Sum of all the bonds
double asset_amt_matured = 0.0;

for (int i = 0; i < sm_fia_bond_aig.size(); i++)
{
	asset_amt_matured += sm_fia_bond_aig[i]->asset_amt_matured_aig(t);
}

return asset_amt_matured;

}


//@@ END

//@@ START - asset_amt_new_aig
// New Asset Amount Purchased, End of Period                                                                                             
// Column:ASSET_AMT_NEW_AIG
//========================================================
double BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_asset_amt_new_aig(int t) {
//^^^



//^^^

#line 1 "asset_amt_new_aig.BOND_PORTFOLIO_AIG.for"
/*! AIG Bond Portfolio New Asset Amount, End of Period
	==================================================
	@author Michael Ching
	@date 20181119
 
	The amount of new assets in the bond portfolio is:

	\f[
	new\,assets_{t} = maturities_{t} + coupons_{t}
	\f]

	Where:
	-# \f$new\,assets_{t}\f$ are the new assets purchased at the end of period \f$t\f$,
	-# \f$maturities_{t}\f$ are the assets that have matured at the end of period \f$t\f$,
	   calculated in bond_portfolio_aig_asset_amt_matured_aig(). Assets that have reached maturity are reinvested
	   and considered "new". And
	-# \f$coupons_{t}\f$ are coupon payments that are also reinvested, calculated in
	   bond_portfolio_aig_coupon_amt_aig()

	Note that there are no assets until the end of the first period.
 
	Related Inputs:
	---------------
	None.
 
	@return Nothing.
*/
if (t <= commencement_period || t > final_period || !initialize_bond_portfolio_aig)//WTW - Gen2 - time guards
	return NO_AVG;

if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->asset_amt_new_aig at period " << t << MSG_USER;
}

if (t == commencement_period + 1)
{
	// All assets purchased at the end of month 1 are new
	double asset_amt_e = asset_amt_e_aig(t);

	return asset_amt_e;
}
else
{
	// For all other months, coupons payments and matured assets are reinvested and considered "new"
	double coupon_amt = coupon_amt_aig(t);
	double asset_amt_matured = asset_amt_matured_aig(t);

	double new_asset_amt = coupon_amt + asset_amt_matured;

	return new_asset_amt;
}

}


//@@ END

//@@ START - avg_coupon_rt_aig
// Average Coupon Rate, End of Period                                                                                             
// Column:AVG_COUPON_RT_AIG
//========================================================
double BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_avg_coupon_rt_aig(int t) {
//^^^



//^^^

#line 1 "avg_coupon_rt_aig.BOND_PORTFOLIO_AIG.for"
/*! AIG Bond Portfolio Average Coupon Rate
	======================================
	@author Michael Ching
	@date 20181119
 
	The average coupon rate is calculated by blending the average asset yield for each bond and
	the prior average coupon rate:

	\f[
	average\,coupon\,rate_{t} = average\,asset\,yield_{t} \times cash\,flow\,percent_{t} + average\,coupon\,rate_{t - 1} \times (1 - cash\,flow\,percent_{t})
	\f]

	Where:
	-# \f$average\,coupon\,rate_{t}\f$ is the average (annual) coupon rate at the end of period \f$t\f$,
	-# \f$average\,asset\,yield_{t}\f$ is the average (annual) asset yield over each bond, calculated in BOND_AIG::bond_aig_asset_yld_aig(),
	-# \f$cash\,flow\,percent_{t}\f$ is percentage of assets in the bond portfolio that are new, calculated in bond_portfolio_aig_cash_flow_pct_aig()
 
	Related Inputs:
	---------------
	None.
 
	@return Nothing.
*/
if (t <= commencement_period || t > final_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->avg_coupon_rt_aig at period " << t << MSG_USER;
}

// 20190304 MTC - Bugfix to link NMR from fia level to average coupon rate
double avg_asset_yld;

if (new_money_rate_defn_aig == PAR_YIELD)
{
	double total_asset_yld = 0.0;

	for (int i = 0; i < bond_count_aig; i++)
	{
		total_asset_yld += sm_fia_bond_aig[i]->asset_yld_aig(t);
	}

	avg_asset_yld = total_asset_yld / bond_count_aig;
}
else if (new_money_rate_defn_aig == COMPANY_YIELD_PLUS_MATRIX_SPREAD)
{
	avg_asset_yld = fia->new_money_rate_aig(t);
}
else
{
	throw FatalError("Unhandled new_money_rate_defn_aig requested in bond_portfolio_aig->avg_coupon_rt_aig!");
}
// 20190304 MTC END

double cash_flow_pct = cash_flow_pct_aig(t);
double prior_avg_coupon_rt = avg_coupon_rt_aig(t - 1);

double avg_coupon_rt = avg_asset_yld * cash_flow_pct + prior_avg_coupon_rt * (1.0 - cash_flow_pct);

return avg_coupon_rt;

}


//@@ END

//@@ START - cash_flow_pct_aig
// Cash Flow Percentage                                                                                             
// Column:CASH_FLOW_PCT_AIG
//========================================================
double BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_cash_flow_pct_aig(int t) {
//^^^



//^^^

#line 1 "cash_flow_pct_aig.BOND_PORTFOLIO_AIG.for"
/*! AIG Bond Portfolio Cash Flow Percentage
	=======================================
	@author Michael Ching
	@date 20181119
 
	Cash flow percentage represents the percentage of funds in the bond portfolio that were purchased as
	new assets. In the first month, 100% of funds in the bond porfolio are always considered new assets. Then
	we either read in the cash flow percentage from an input or we calculate it dynamically as:

	\f[
	cash\,flow\,percentage_{t} = \frac{new\,asset\,amount_{t}}{asset\,amount_{t}}
	\f]

	Where:
	-# \f$cash\,flow\,percentage_{t}\f$ is the portfolio cash flow at time \f$t\f$,
	-# \f$new\,asset\,amount_{t}\f$ are any new assets purchased at time \f$t\f$, and
	-# \f$asset\,amount_{t}\f$ are existing assets at time \f$t\f$
	.

	\f$new\,asset\,amount_{t}\f$ is calculated in bond_portfolio_aig_asset_amt_new_aig() and 
	\f$asset\,amount_{t}\f$ is calculated in bond_portfolio_aig_asset_amt_e_aig().
 
	Related Inputs:
	---------------
	-# **UI** `cash_flow_pct_defn_aig` - Determines whether or not the cash flow percentage is read in from
	   an input or if it is calculated dynamically.
	-# **UI** `cash_flow_pct_input_vector_aig` - An input vector of cash flow percentages, varying over
	   pol_yr().
	.
 
	@return Nothing.
*/
if (t <= commencement_period || t > final_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->cash_flow_pct_aig at period " << t << MSG_USER;
}

double cash_flow_pct;

// 20181205 MTC - Moved time 1 logic to the top of the if branches
if (t + fia->elapsed_mths == commencement_period + 1)
{
	// 100% of assets are new in first investment
	cash_flow_pct = 1.0;
}
else
{
	if (cash_flow_pct_defn_aig == BOND)
	{
		// Use a bond to approximate cash flow as a percentage of new face amount over existing face amount
		double asset_amt_new = asset_amt_new_aig(t);
		double asset_amt_e = asset_amt_e_aig(t);
	
		if (asset_amt_e > SMALL_DOUBLE)
		{
			// Calculate percentage of assets that are new
			cash_flow_pct = asset_amt_new / asset_amt_e;
		}
		else if (asset_amt_new > SMALL_DOUBLE)
		{
			// If there are no existing assets and there are some new assets, by definition 100% of assets are new
			cash_flow_pct = 1.0;
		}
		else
		{
			// This is the 0/0 case
			cash_flow_pct = 0.0;
		}
	}
	else if (cash_flow_pct_defn_aig == INPUT_VECTOR)
	{
		if ((t + fia->elapsed_mths) % coupon_freq_aig == 0)
		{
			// Read annual cash flow percentage from input vector and convert to monthly
			fia->pol_yr_lookup_gen2 = pol_yr(t);
			cash_flow_pct = cash_flow_pct_input_vector_aig / 12.0;
		}
		else
		{
			cash_flow_pct = 0.0;
		}
	}
	else
	{
		throw FatalError("Unhandled cash_flow_pct_defn_aig requested in fia_bond_portfolio_aig->cash_flow_pct_aig!");
	}
}

return cash_flow_pct;

}


//@@ END

//@@ START - coupon_amt_aig
// Coupon Amount                                                                                             
// Column:COUPON_AMT_AIG
//========================================================
double BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_coupon_amt_aig(int t) {
//^^^



//^^^

#line 1 "coupon_amt_aig.BOND_PORTFOLIO_AIG.for"
/*! AIG Bond Portfolio Coupon Amount
	================================
	@author Michael Ching
	@date 20181119
 
	The coupon amount is calculated as a percentage of assets from the beginning of the period:

	\f[
	coupons_{t} = assets\,beginning\,of\,period_{t} * \frac{coupon\,rate_{t - 1}}{coupon\,frequency}
	\f]

	Where:
	-# \f$coupons_{t}\f$ is the coupon from the asset at time \f$t\f$,
	-# \f$assets\,beginning\,of\,period_{t}\f$ is the assets at the beginning of the period,
	   calculated in bond_portfolio_aig_asset_amt_b_aig(),
	-# \f$coupon\,rate_{t - 1}\f$ is the annual coupon rate at the end of the prior period
	   (which is the same of beginning of this period) calculated by bond_portfolio_aig_avg_coupon_rt_aig(), and
	-# \f$coupon\,frequency\f$ is number of coupon payments per year, calculated by coupon_freq_aig()
	.

	Note that coupons are paid according to the coupon frequency, at the end of a period.
 
	Related Inputs:
	---------------
	None.
 
	@return Nothing.
*/
if (t <= commencement_period || t > final_period || !initialize_bond_portfolio_aig)//WTW - Gen2 - time guards
	return NO_AVG;

if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->coupon_amt_aig at period " << t << MSG_USER;
}

if (t % coupon_freq_aig == 0)
{
	double avg_coupon_rt = avg_coupon_rt_aig(t - 1);
	double asset_amt_b = asset_amt_b_aig(t);
	
	double coupon_amt = asset_amt_b * (avg_coupon_rt * (coupon_freq_aig / 12.0));

	return coupon_amt;
}
else
{
	return 0.0;
}

}


//@@ END

//@@ START - duration_curr_asset_aig
// Current Asset Duration                                                                                             
// Column:DURATION_CURR_ASSET_AIG
//========================================================
double BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_duration_curr_asset_aig(int t) {
//^^^



//^^^

#line 1 "duration_curr_asset_aig.BOND_PORTFOLIO_AIG.for"
/*! AIG Bond Portfolio Current Asset Duration
	=========================================
	@author Michael Ching
	@date 20181119
 
	This column approximates a rollforward for the current asset duration:

	-# Calculate the current asset duration by blending the prior new asset and current asset durations.
	-# Use cubic spline to look up the current asset maturity with the asset duration from the previous steup.
	-# Reduce the current asset maturity by one month. This represents a rollforward through time.
	-# Use cubic spline to look up the current asset duration with the current asset maturity from the prior step.
	   This will "recalculate" the duration based on this month's market environment.
	.
 
	Related Inputs:
	---------------
	None.
 
	@return Nothing.
*/
if (t <= commencement_period || t > final_period || !initialize_bond_portfolio_aig)//WTW - Gen2 - time guards
	return NO_AVG;

if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->duration_curr_bond_aig at period " << t << MSG_USER;
}

double current_asset_duration;

if (t == commencement_period + 1)
{
	// No bonds purchased until end of month 1
	current_asset_duration = 0.0;
}
else
{
	// Get prior new asset duration curve
	vector <double> prior_new_asset_duration_curve = get_new_asset_duration_curve_aig(t - 1);

	// Get current new asset duration curve
	vector <double> current_new_asset_duration_curve = get_new_asset_duration_curve_aig(t);

	// Get prior cash flow percentage
	double prior_cash_flow_pct = cash_flow_pct_aig(t - 1);

	// Get prior current bond duration
	double prior_current_bond_duration = duration_curr_asset_aig(t - 1);

	// Get prior new asset duration
	double prior_new_asset_duration = duration_new_asset_aig(t - 1);

	// Calculate a blend of current and new asset duration
	current_asset_duration = prior_new_asset_duration * prior_cash_flow_pct + prior_current_bond_duration * (1.0 - prior_cash_flow_pct);

	// Use cubic spline to determine maturity 
	double current_asset_maturity = 0.0;
	if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
		current_asset_maturity = fia_rates->cubic_spline_interpolation_aig(current_asset_duration, prior_new_asset_duration_curve, new_asset_rate_tenors);
	else
		current_asset_maturity = rates->cubic_spline_interpolation_aig(current_asset_duration, prior_new_asset_duration_curve, new_asset_rate_tenors);

	// Adjust the maturity downward for one month. This is the rollforward in time.
	current_asset_maturity -= 1.0;

	// Use cubic spline to determine duration with current economic environment
	if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
		current_asset_duration = fia_rates->cubic_spline_interpolation_aig(current_asset_maturity, new_asset_rate_tenors, current_new_asset_duration_curve);
	else
		current_asset_duration = rates->cubic_spline_interpolation_aig(current_asset_maturity, new_asset_rate_tenors, current_new_asset_duration_curve);
}

return current_asset_duration;

}


//@@ END

//@@ START - duration_new_asset_aig
// New Asset Duration                                                                                             
// Column:DURATION_NEW_ASSET_AIG
//========================================================
double BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_duration_new_asset_aig(int t) {
//^^^



//^^^

#line 1 "duration_new_asset_aig.BOND_PORTFOLIO_AIG.for"
/*! AIG Bond Portfolio New Asset Duration
	=====================================
	@author Michael Ching
	@date 20181119
 
 	The bond portfolio new asset duration is a blend of the current and target durations:

	\f[
	new\,asset\,duration_{t} = \frac{target\,asset\,duration_{t} - current\,asset\,duration_{t} \times (1 - cash\,flow\,percent_{t})}{cash\,flow\,percent_{t}}
	\f]

	Where:
	-# \f$new\,asset\,duration_{t}\f$ is the new asset duration at time \f$t\f$,
	-# \f$target\,asset\,duration_{t}\f$ is the target asset duration at time \f$t\f$,
	-# \f$current\,asset\,duration_{t}\f$ is the new asset duration at time \f$t\f$, and
	-# \f$cash\,flow\,percent_{t}\f$ is the new asset duration at time \f$t\f$
	.

	Every period, our target duration can shift. To get the portfolio duration back to target duration, we will buy
	new assets. However, we need to account for our existing assets. Therefore, new asset duration
	will be a blend of our target duration and what we already have in our portfolio.
 
	Related Inputs:
	---------------
	None.
 
	@return Nothing.
*/
if (t < commencement_period || t > final_period || !initialize_bond_portfolio_aig)//WTW - Gen2 - time guards
	return NO_AVG;

if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->duration_new_asset_aig at period " << t << MSG_USER;
}

// Initialize
double duration_target_asset = duration_target_asset_aig(t);
double duration_curr_bond = duration_curr_asset_aig(t);
double cash_flow_pct = cash_flow_pct_aig(t);

double duration_new_asset;

if (cash_flow_pct > SMALL_DOUBLE)
{
	duration_new_asset = (duration_target_asset - duration_curr_bond * (1.0 - cash_flow_pct)) / cash_flow_pct;

	duration_new_asset = max(duration_new_asset, new_asset_duration_floor_aig * 12.0);
}
else
{
	// No cash flow means no new assets, so no duration
	duration_new_asset = 0.0;
}

return duration_new_asset;

}


//@@ END

//@@ START - duration_target_asset_aig
// Target Asset Duration (Months)                                                                                             
// Column:DURATION_TARGET_ASSET_AIG
//========================================================
double BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_duration_target_asset_aig(int t) {
//^^^



//^^^

#line 1 "duration_target_asset_aig.BOND_PORTFOLIO_AIG.for"
/*! AIG Bond Portfolio Target Asset Duration
	========================================
	@author Michael Ching
	@date 20181119
 
	The bond portfolio target asset duration is read in from the inputs, and varies by policy year.
	This function converts the annual duration to a monthly duration.
 
	Related Inputs:
	---------------
	-# **UI** `target_asset_duration_aig` - Annual target asset duration.
	.
 
	@return Nothing.
*/
if (t < commencement_period || t > final_period || !initialize_bond_portfolio_aig)//WTW - Gen2 - time guards
	return NO_AVG;

if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->duration_target_asset_aig at period " << t << MSG_USER;
}

double duration_target_asset = target_asset_duration_aig * 12.0;

return duration_target_asset;

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.BOND_PORTFOLIO_AIG.for"
if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->initialize at period " << t << MSG_USER;
}

// Add model class to output file list. MCHING 1-26-2022
// Bugfix to vGrid race condition. MCHING 2-15-2022
if (is_first_modelpoint && overall_is_first_proj_task_loop)
{
	fia_automation->append_to_file_manifest_aig(output_location());
}

// Initialize other curves - These must be called in order
if (initialize_bond_portfolio_aig) // 20190312 MTC - Added bond portfolio initialization flag
{
	initialize_spot_prices_aig();
	initialize_par_yields_aig();
	initialize_new_asset_durations_aig();

	if (print_debug_output_defn_aig == YES)
	{
		print_debug_output_aig();
	}
}

//WTW - Gen2 - Copy from 'startup' to here for call to initialize()
if (initialize_bond_portfolio_aig) // 20190312 MTC - Added bond portfolio initialization flag
{
	// Initialize bonds
	for (int bond_count = 1; bond_count <= bond_count_aig; bond_count++)
	{
		// Set Bond Index
		int bond_idx = bond_count - 1;

		// Initialize submodel
		//sm_fia_bond_aig[bond_idx]->initialize(0); 
		sm_fia_bond_aig[bond_idx]->initialize(t);//WTW - Gen2 - CallingInitialiseFinaliseAtNonT
	}
}

return 1.0;

}


//@@ END

//@@ START - new_money_rate_aig
// New Money Rate                                                                                             
// Column:NEW_MONEY_RATE_AIG
//========================================================
double BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_new_money_rate_aig(int t) {
//^^^



//^^^

#line 1 "new_money_rate_aig.BOND_PORTFOLIO_AIG.for"
/*! AIG Bond Portfolio New Money Rate
	=================================
	@author Michael Ching
	@date 20181119
 
 	The bond portfolio new money rate is calculated by using cubic spline interpolation from RATES_ECONOMY::cubic_spline_interpolation_aig()
	to interpolate the target asset duration from bond_portfolio_aig_duration_target_asset_aig() on the new asset duration curve from
	initialize_new_asset_durations_aig() to get a value from the par yield curve from initialize_par_yields_aig().
 
	Related Inputs:
	---------------
	None.
 
	@return Nothing.
*/
if (t != commencement_period/* || t > final_period*/)//WTW - Gen2 - time guards
	return NO_AVG;

if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->new_money_rate_aig at period " << t << MSG_USER;
}

// Initialize
double new_money_rate;

// 20190301 MTC - Added option to read in NMR from fia level
if (new_money_rate_defn_aig == PAR_YIELD)
{
	// 20190312 MTC - Skip if not needed

	// Get new asset duration curve
	vector <double> new_asset_duration_curve = get_new_asset_duration_curve_aig(t);

	// Get par yield curve
	vector <double> par_yield_curve = get_par_yield_curve_aig(t);

	// Get target asset duration
	double target_asset_duration = duration_target_asset_aig(t);

	// 20190312 MTC END

	if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
		new_money_rate = fia_rates->cubic_spline_interpolation_aig(target_asset_duration, new_asset_duration_curve, par_yield_curve);
	else
		new_money_rate = rates->cubic_spline_interpolation_aig(target_asset_duration, new_asset_duration_curve, par_yield_curve);
}
else if (new_money_rate_defn_aig == COMPANY_YIELD_PLUS_MATRIX_SPREAD)
{
	new_money_rate = fia->new_money_rate_aig(t);
}
else
{
	throw FatalError("Unhandled new_money_rate_defn_aig requested in bond_portfolio_aig->new_money_rate_aig!");
}
// 20190301 MTC END

// Apply new money rate adjustment
new_money_rate += asset_yld_addn_aig;

return new_money_rate;

}


//@@ END

//@@ START - pol_yr
// Policy Year                                                                                             
// Column:POL_YR
//========================================================
double BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_pol_yr(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(13,"pol_yr",t);
}



//^^^

#line 1 "pol_yr.BOND_PORTFOLIO_AIG.for"
if (t < commencement_period || t > maturity_period)//WTW - Gen2 - time guards
	return NO_AVG;

if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->pol_yr at period " << t << MSG_USER;
}

return fia->pol_yr(t);

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double BOND_PORTFOLIO_AIG_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.BOND_PORTFOLIO_AIG.for"
// 20190129 MTC - Added rates_economy to include for cubic spline params
#if 0 // START_HEADER
//#include "rates_economy.h" //WTW - Gen2

#endif // END_HEADER
// 20190129 MTC END

// 20181119 MTC
#if 0 // START_CLASS
vector <vector <double> > spot_prices; // Global object that stores all spot prices
vector <vector <double> > par_yields; // Global object that stores all par yields
vector <vector <double> > new_asset_durations; // Global object that stores all new asset durations
vector <double> new_asset_rate_tenors_input; // Global object that stores all new asset rate tenors declared in the scenario file (before expansion)
vector <double> new_asset_rate_tenors; // Global object that stores all new asset rate tenors after expansion
int new_asset_rate_tenor_freq; // Global object that stores the new asset rate tenor frequency after expansion
#endif // END_CLASS

if (print_debug_output_defn_aig == YES)
{
	log_screen << "bond_portfolio_aig->startup at period " << t << MSG_USER;
}

// 20181204 MTC - Fixed class variable initialization
spot_prices.clear();
par_yields.clear();
new_asset_durations.clear();
new_asset_rate_tenors_input.clear();
new_asset_rate_tenors.clear();
// 20181204 MTC END

if (initialize_bond_portfolio_aig) // 20190312 MTC - Added bond portfolio initialization flag
{
	// Get bond tenors
	vector <string> new_asset_rate_tenors_str;
	split_string_usl(new_asset_rate_tenors_aig.c_str(), new_asset_rate_tenors_str, ",");//WTW - Gen2 - split_tring internal RAFM function

	// Check bond tenors
	if (new_asset_rate_tenors_str.size() <= 1)
	{
		throw FatalError("Not enough tenors selected for new_asset_rate_tenors_aig!");
	}

	// Convert bond tenors to int
	for (int i = 0; i < new_asset_rate_tenors_str.size(); i++)
	{
		new_asset_rate_tenors_input.push_back(stod(new_asset_rate_tenors_str[i]));
	}

	// Check that all bond tenors are years
	for (int i = 0; i < new_asset_rate_tenors_input.size(); i++)
	{
		int tenor = new_asset_rate_tenors_input[i];
	
		if (tenor % 12 != 0)
		{
			throw FatalError("Bond tenors must be annual (multiples of 12 i.e. 12, 24, 36...)! Please check your scenario file and new_asset_rate_tenors_aig!");
		}
	}

	// Check that all bond tenors are increasing
	for (int i = 0; i < new_asset_rate_tenors_input.size() - 1; i++)
	{
		if (new_asset_rate_tenors_input[i] >= new_asset_rate_tenors_input[i + 1])
		{
			throw FatalError("Bond tenors must be increasing (i.e. 12, 24, 36...)! Please check your scenario file and new_asset_rate_tenors_aig!");
		}
	}

	// Expand bond tenors
	int min_tenor;
	int max_tenor;

	min_tenor = *min_element(begin(new_asset_rate_tenors_input), end(new_asset_rate_tenors_input));
	max_tenor = *max_element(begin(new_asset_rate_tenors_input), end(new_asset_rate_tenors_input));

	if (new_asset_rate_tenors_expand_defn_aig == ANNUAL)
	{
		new_asset_rate_tenor_freq = 12;
	}
	else if (new_asset_rate_tenors_expand_defn_aig == USE_COUPON_FREQ_DEFN_AIG)
	{
		new_asset_rate_tenor_freq = coupon_freq_aig;
	}
	else
	{
		throw FatalError("Unhandled new_asset_rate_tenors_expand_defn_aig requested in bond_portfolio_aig->startup!");
	}

	for (int tenor = new_asset_rate_tenor_freq; tenor <= max_tenor; tenor += new_asset_rate_tenor_freq)
	{
		new_asset_rate_tenors.push_back(tenor);
	}

	// Remove existing bond assets
	if (sm_fia_bond_aig.size())
	{
		sm_fia_bond_aig.resize(0);
	}

	// Initialize bonds
	for (int bond_count = 1; bond_count <= bond_count_aig; bond_count++)
	{
		// Set Bond Index
		int bond_idx = bond_count - 1;

		// Create Bond ID
		xstring bond_id = "Bond" + xstring(bond_idx);

		// Expand submodel array
		sm_fia_bond_aig.resize(bond_count);

		// Assign rates
		sm_fia_bond_aig[bond_idx]->rates = rates;

		// Assign new asset tenors
		sm_fia_bond_aig[bond_idx]->new_asset_rate_tenors = new_asset_rate_tenors;

		// Assign Bond ID
		sm_fia_bond_aig[bond_idx]->bond_id_aig = bond_id;

		//WTW - Gen2 - move to parent startup() for performance
		sm_fia_bond_aig[bond_idx]->setGroup(bond_id);
		// Force inputs to be read again - This might not need to be called since there are no lookups that rely on bond_id (for now)
		//sm_fia_bond_aig[bond_idx]->ms_rereadGrid();

		// Initialize submodel
		//sm_fia_bond_aig[bond_idx]->initialize(0); //WTW - Gen2 - Move to 'initialize' column.
	}
}

return 1.0;

}


//@@ END

//@@ START - commencement_period
// Commencement Period                                                                                             
// Calculated Variable:COMMENCEMENT_PERIOD
//========================================================
int BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_commencement_period() {
//^^^


#line 1 "commencement_period.BOND_PORTFOLIO_AIG.for"
return fia->commencement_period;

}


//@@ END

//@@ START - coupon_freq_aig
// Number of Periods Between Coupons                                                                                             
// Calculated Variable:COUPON_FREQ_AIG
//========================================================
int BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_coupon_freq_aig() {
//^^^


#line 1 "coupon_freq_aig.BOND_PORTFOLIO_AIG.for"
if (coupon_freq_defn_aig == MONTHLY)
{
	return 1;
}
else if (coupon_freq_defn_aig == ANNUALLY)
{
	return 12;
}
else
{
	throw FatalError("Unhandled coupon_freq_aig requested in bond_asset_aig!");
}

}


//@@ END

//@@ START - final_period
// WTW - Gen2 - final period for time guards                                                                                             
// Calculated Variable:FINAL_PERIOD
//========================================================
int BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_final_period() {
//^^^


#line 1 "final_period.BOND_PORTFOLIO_AIG.for"
return fia->final_period;

}


//@@ END

//@@ START - initialize_bond_portfolio_aig
// Initialize Bond Portfolio?                                                                                             
// Calculated Variable:INITIALIZE_BOND_PORTFOLIO_AIG
//========================================================
int BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_initialize_bond_portfolio_aig() {
//^^^


#line 1 "initialize_bond_portfolio_aig.BOND_PORTFOLIO_AIG.for"
// 20190312 MTC - Added new flag for bond portfolio initialization
if (new_money_rate_defn_aig == PAR_YIELD || cash_flow_pct_defn_aig == BOND)
{
	return 1;
}
else
{
	return 0;
}

}


//@@ END

//@@ START - maturity_period
// Period t in which Policy Matures                                                                                             
// Calculated Variable:MATURITY_PERIOD
//========================================================
int BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_maturity_period() {
//^^^


#line 1 "maturity_period.BOND_PORTFOLIO_AIG.for"
return fia->maturity_period;

}


//@@ END


#line 1 "get_new_asset_duration_aig.BOND_PORTFOLIO_AIG.for"                                                                                   
double BOND_PORTFOLIO_AIG::get_new_asset_duration_aig(int t, int tenor)
{
	// Check for t out of bounds
	if (t < 0 || t >= par_yields.size())
	{
		xstring t_str = xstring(t);
		throw FatalError("t out of bounds requested: " + t_str + " in bond_portfolio_aig->get_new_asset_duration_aig!");
	}

	// Find column index position using tenor list for data map
	int tenor_idx = -1;

	for (int tenor_seek_idx = 0; tenor_seek_idx < new_asset_rate_tenors.size(); tenor_seek_idx++)
	{
		int current_tenor = new_asset_rate_tenors[tenor_seek_idx];

		if (tenor == current_tenor)
		{
			tenor_idx = tenor_seek_idx;
			break;
		}
	}

	// Check for failure to find tenor
	if (tenor_idx == -1)
	{
		xstring tenor_str = xstring(tenor);
		throw FatalError("Unhandled tenor requested: " + tenor_str + " in bond_portfolio_aig->get_new_asset_duration_aig!");
	}

	// Return array position
	double new_asset_duration = new_asset_durations[t][tenor_idx];
	return new_asset_duration;
}



#line 1 "get_new_asset_duration_curve_aig.BOND_PORTFOLIO_AIG.for"                                                                                   
vector<double> BOND_PORTFOLIO_AIG::get_new_asset_duration_curve_aig(int t)
{
	// Check for t out of bounds
	if (t < 0 || t >= spot_prices.size())
	{
		xstring t_str = xstring(t);
		throw FatalError("t out of bounds requested: " + t_str + " in bond_portfolio_aig->get_new_asset_duration_curve_aig!");
	}

	vector <double> new_asset_duration_curve = new_asset_durations[t];
	
	return new_asset_duration_curve;
}



#line 1 "get_par_yield_aig.BOND_PORTFOLIO_AIG.for"                                                                                   
double BOND_PORTFOLIO_AIG::get_par_yield_aig(int t, int tenor)
{
	// Check for t out of bounds
	if (t < 0 || t >= par_yields.size())
	{
		xstring t_str = xstring(t);
		throw FatalError("t out of bounds requested: " + t_str + " in bond_portfolio_aig->get_par_yield_aig!");
	}

	// Find column index position using tenor list for data map
	int tenor_idx = -1;

	for (int tenor_seek_idx = 0; tenor_seek_idx < new_asset_rate_tenors.size(); tenor_seek_idx++)
	{
		int current_tenor = new_asset_rate_tenors[tenor_seek_idx];

		if (tenor == current_tenor)
		{
			tenor_idx = tenor_seek_idx;
			break;
		}
	}

	// Check for failure to find tenor
	if (tenor_idx == -1)
	{
		xstring tenor_str = xstring(tenor);
		throw FatalError("Unhandled tenor requested: " + tenor_str + " in bond_portfolio_aig->get_par_yield_aig!");
	}

	// Return array position
	double par_yield = par_yields[t][tenor_idx];
	return par_yield;
}



#line 1 "get_par_yield_curve_aig.BOND_PORTFOLIO_AIG.for"                                                                                   
vector<double> BOND_PORTFOLIO_AIG::get_par_yield_curve_aig(int t)
{
	// Check for t out of bounds
	if (t < 0 || t >= spot_prices.size())
	{
		xstring t_str = xstring(t);
		throw FatalError("t out of bounds requested: " + t_str + " in bond_portfolio_aig->get_par_yield_curve_aig!");
	}

	vector <double> par_yield_curve = par_yields[t];

	return par_yield_curve;
}



#line 1 "get_spot_price_aig.BOND_PORTFOLIO_AIG.for"                                                                                   
double BOND_PORTFOLIO_AIG::get_spot_price_aig(int t, int tenor)
{
	// Check for t out of bounds
	if (t < 0 || t >= spot_prices.size())
	{
		xstring t_str = xstring(t);
		throw FatalError("t out of bounds requested: " + t_str + " in bond_portfolio_aig->get_spot_price_aig!");
	}

	// Find column index position using tenor list for data map
	int tenor_idx = -1;

	for (int tenor_seek_idx = 0; tenor_seek_idx < new_asset_rate_tenors.size(); tenor_seek_idx++)
	{
		int current_tenor = new_asset_rate_tenors[tenor_seek_idx];

		if (tenor == current_tenor)
		{
			tenor_idx = tenor_seek_idx;
			break;
		}
	}

	// Check for failure to find tenor
	if (tenor_idx == -1)
	{
		xstring tenor_str = xstring(tenor);
		throw FatalError("Unhandled tenor requested: " + tenor_str + " in bond_portfolio_aig->get_spot_price_aig!");
	}

	// Return array position
	double spot_price = spot_prices[t][tenor_idx];
	return spot_price;
}



#line 1 "get_spot_price_curve_aig.BOND_PORTFOLIO_AIG.for"                                                                                   
vector<double> BOND_PORTFOLIO_AIG::get_spot_price_curve_aig(int t)
{
	// Check for t out of bounds
	if (t < 0 || t >= spot_prices.size())
	{
		xstring t_str = xstring(t);
		throw FatalError("t out of bounds requested: " + t_str + " in bond_portfolio_aig->get_spot_price_curve_aig!");
	}

	vector <double> spot_price_curve = spot_prices[t];

	return spot_price_curve;
}



#line 1 "initialize_new_asset_durations_aig.BOND_PORTFOLIO_AIG.for"                                                                                   
void BOND_PORTFOLIO_AIG::initialize_new_asset_durations_aig(void)
{
	/*! AIG Macaulay Duration Initialization
		====================================
		@author Michael Ching
		@date 20181119
 
		We calculate the Macaulay duration per <a href="https://www.investopedia.com/terms/m/macaulayduration.asp"&gt;Investopedia&lt;/a>:
 
		\f[
		duration_{n} = n \times spot\,price_{n} + \sum_{i=1}^{n} par\,yield_{i} \times i \times spot\,price_{i}
		\f]
 
		Where:
		-# \f$duration_{n}\f$ is the Macaulay duration for a bond that matures at \f$n\f$,
		-# \f$spot\,price_{i}\f$ is the spot price for duration \f$i\f$, and
		-# \f$par\,yield_{i}\f$ is the coupon rate for duration \f$i\f$
		.

		We assume that the denominator for the Macaulay duration is always $1, so the above formula will only show the numerator.
		\f$n \times spot\,price_{n}\f$ represents the present value of the final maturity of the bond while 
		\f$\sum_{i=1}^{n} par\,yield_{i} \times i \times spot\,price_{i}\f$	represents the present value of the coupon payments.
		Everything is discounted using spot prices.

		We always initialize the spot price curve with annual tenors, so the Macaulay duration will always assume annual coupon 
		payments, regardless of the actual coupon frequency selected. This is inaccurate, but has been deemed to be acceptable.
 
		This function calculates the entire scenario's Macaulay durations and stores them inside a 2-dimensional array declared in
		bond_portfolio_aig_startup(). While this array can be directly accessed, a safe get method has been implemented in get_new_asset_duration_aig().
 
		Related Inputs:
		---------------
		None.
 
		@return Nothing.
	*/

	for (int t = 0; t < par_yields.size(); t++)
	{
		// Initialize a new vector
		vector <double> current_row;

		// Reset the coupon discount factor
		double coupon_factor = 0.0;
		
		// Calculate par yields
		for (int tenor_idx = 0; tenor_idx < new_asset_rate_tenors.size(); tenor_idx++)
		{
			// Get spot price and par yield
			int tenor = new_asset_rate_tenors[tenor_idx];
			int num_coupon_payments = 1 + tenor_idx;
			double spot_price = get_spot_price_aig(t, tenor); // Discount factor
			double par_yield = get_par_yield_aig(t, tenor); // Coupon rate

			// Calculate coupon discount factor
			coupon_factor += num_coupon_payments * spot_price;

			// Calculate coupon amount
			double coupon_amount = par_yield * (new_asset_rate_tenor_freq / 12.0);

			// Calculate the coupons
			double coupons = coupon_factor * coupon_amount;

			// Calculate final payment
			double final_payment = num_coupon_payments * spot_price;

			// Calculate duration
			double new_asset_duration = coupons + final_payment;

			// Convert duration to monthly
			double monthly_new_asset_duration = new_asset_duration * new_asset_rate_tenor_freq;

			// Save par yield to current row
			current_row.push_back(monthly_new_asset_duration);
		}

		// Save new row
		new_asset_durations.push_back(current_row);
	}

	return;
}



#line 1 "initialize_par_yields_aig.BOND_PORTFOLIO_AIG.for"                                                                                   
void BOND_PORTFOLIO_AIG::initialize_par_yields_aig(void)
{
	/*! AIG Par Yield Rate Calculation
		==============================
		@author Michael Ching
		@date 20181119
 
		We derive the par yields from spot prices. Per <a href="https://www.investopedia.com/terms/p/par-yield-curve.asp"&gt;Investopedia&lt;/a>,
		the par yield is the yield to maturity of coupon-paying bonds at different maturity dates.  We use a simplified formula to calculate
		the par yield:
 
		\f[
		spot\,price_{j} = \$1 - par\,yield * \sum_{i=1}^{j} spot\, price_{i}
		\f]
 
		Where:
		-# \f$spot\,price_{j}\f$ is the spot price for an asset of duration \f$j\f$ and
		-# \f$par\,yield\f$ is the par yield
		.

		Note that a bond issued at par has a yield to maturity equal to the coupon rate. \f$\sum_{i=1}^{j} spot\, price_{i}\f$ are the discount
		factors for each coupon payment and elements \f$i\f$ to \f$j\f$ represent coupon payments. Essentially, this is a PV factor for the
		coupons.

		Also note that this algorithm is an approximation. It only considers coupon payments at the given points on the yield curve, not
		points in between. Ideally, we would be calculating semi-annual coupons.
 
		This function calculates the entire scenario's par yields prices and stores them inside a 2-dimensional array declared in
		bond_portfolio_aig_startup(). While this array can be directly accessed, a safe get method has been implemented in get_par_yield_aig().
 
		Related Inputs:
		---------------
		None.
 
		@return Nothing.
	*/

	for (int t = 0; t < spot_prices.size(); t++)
	{
		// Initialize a new vector
		vector <double> current_row;

		// Reset the coupon factor
		double coupon_factor = 0.0;
		
		// Calculate par yields
		for (int tenor_idx = 0; tenor_idx < new_asset_rate_tenors.size(); tenor_idx++)
		{
			// Get spot price
			int tenor = new_asset_rate_tenors[tenor_idx];
			double spot_price = get_spot_price_aig(t, tenor);

			// Add a coupon to the coupon factor
			coupon_factor += spot_price;

			// Calculate par yield
			double par_yield = 0.0;

			if (coupon_factor > SMALL_DOUBLE)
			{
				par_yield = (1.0 - spot_price) / coupon_factor;
			}

			// Calculate annual par yield
			double annual_par_yield = par_yield * (12.0 / new_asset_rate_tenor_freq);

			// Save par yield to current row
			current_row.push_back(annual_par_yield);
		}

		// Save new row
		par_yields.push_back(current_row);
	}

	return;
}



#line 1 "initialize_spot_prices_aig.BOND_PORTFOLIO_AIG.for"                                                                                   
void BOND_PORTFOLIO_AIG::initialize_spot_prices_aig(void)
{
	/*! AIG Bond Spot Price Initialization
		==================================
		@author Michael Ching
		@date 20181119
 
		We derive the spot price from the New Money Rate yield curve. New money rates are read in through the economic scenario file as
		effective annual rates. Per <a href="https://www.investopedia.com/terms/f/forwardprice.asp"&gt;Investopedia&lt;/a>:
 
		\f[
		F_{0} = S_{0} * e^{rT}
		\f]
 
		Where:
		-# \f$F_{0}\f$ is the forward price,
		-# \f$S_{0}\f$ is the spot price,
		-# \f$r\f$ is the risk free rate, and
		-# \f$T\f$ is the delivery date
		.

		We assume:
		-# \f$F_{0}\f$ is $1,
		-# \f$r\f$ is the new money rate, and
		-# \f$T\f$ is bond maturity
		.
 
		This function calculates the entire scenario's spot prices and stores them inside a 2-dimensional array declared in
		bond_portfolio_aig_startup(). While this array can be directly accessed, a safe get method has been implemented in get_spot_price_aig().
 
		Related Inputs:
		---------------
		-# **UI** `new_asset_rate_id_aig` - New Money Rate curve identifier, as a string.
		.
 
		@return Nothing.
	*/

	for (int t = commencement_period; t <= t_high; t++)
	{
		// Initialize a new vector
		vector <double> current_row;
		vector <double> scen_file_spot_rates;

		// Get spot rate curve
		for (int tenor_idx = 0; tenor_idx < new_asset_rate_tenors_input.size(); tenor_idx++)
		{
			// Get current tenor
			int current_tenor = new_asset_rate_tenors_input[tenor_idx] / 12.0;

			// Get spot rate from scenario file. Note that get_int_rate requires the current tenor to be in years
			double spot_rate = 0.0;
	
			if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
				spot_rate = fia_rates->get_int_rate(t, new_asset_rate_id_aig, GET_YIELD_RATE, current_tenor, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			else
				spot_rate = rates->get_int_rate(t, new_asset_rate_id_aig, GET_YIELD_RATE, current_tenor, 0, EFFECTIVE_ANNUAL, NO_SHIFT,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			// Store spot rate
			scen_file_spot_rates.push_back(spot_rate);
		}

		// 20190129 MTC - Build cubic spline params
		cubic_spline_params_aig spot_curve_cubic_spline_params;
		
		if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
			fia_rates->cubic_spline_params_calc_aig(spot_curve_cubic_spline_params, new_asset_rate_tenors_input, scen_file_spot_rates);
		else
			rates->cubic_spline_params_calc_aig(spot_curve_cubic_spline_params, new_asset_rate_tenors_input, scen_file_spot_rates);
		// 20190129 MTC END

		// Build spot price curve
		for (int tenor_idx = 0; tenor_idx < new_asset_rate_tenors.size(); tenor_idx++)
		{
			// Get current tenor
			int current_tenor = new_asset_rate_tenors[tenor_idx];

			// Get spot rate from cubic spline
			double spot_rate = 0.0;
	
			if (fia->gen2_defn == YES)//WTW - Gen2 - cannot define 'rates' pointer
				spot_rate = fia_rates->cubic_spline_interpolation_aig(current_tenor, new_asset_rate_tenors_input, scen_file_spot_rates, spot_curve_cubic_spline_params); // 20190129 MTC - Build cubic spline params
			else
				spot_rate = rates->cubic_spline_interpolation_aig(current_tenor, new_asset_rate_tenors_input, scen_file_spot_rates, spot_curve_cubic_spline_params); // 20190129 MTC - Build cubic spline params
			
			// Convert spot rate to spot price. Note that tenors are always monthly
			double spot_price = exp(spot_rate * -(current_tenor / 12.0));

			// Save spot price to current row
			current_row.push_back(spot_price);
		}

		// Save new row
		spot_prices.push_back(current_row);
	}

	return;
}



#line 1 "print_debug_initialized_table_aig.BOND_PORTFOLIO_AIG.for"                                                                                   
void BOND_PORTFOLIO_AIG::print_debug_initialized_table_aig(xstring file_path, vector< vector <double> > table)
{
	// Open file
	ofstream output_file_stream;
	output_file_stream.open(file_path);

	// Print header
	output_file_stream << "t, ";

	// Print tenors
	for (int tenor_idx = 0; tenor_idx < new_asset_rate_tenors.size(); tenor_idx++)
	{
		if (tenor_idx != new_asset_rate_tenors.size() - 1)
		{
			// Terminator is comma
			output_file_stream << xstring(new_asset_rate_tenors[tenor_idx]) << ", ";
		}
		else
		{
			// Terminator is endl
			output_file_stream << xstring(new_asset_rate_tenors[tenor_idx]) << endl;
		}	
	}
	
	// Print table data
	int t = commencement_period;

	for (int row = 0; row < table.size(); row++)
	{
		vector <double> current_row = table[row];

		// Print row index
		xstring t_str = xstring(t);
		output_file_stream << t_str << ", ";

		// Print column data
		for (int col = 0; col < current_row.size(); col++)
		{
			if (col != current_row.size() - 1)
			{
				// Terminator is comma
				output_file_stream << xstring(current_row[col]) << ", ";
			}
			else
			{
				// Terminator is endl
				output_file_stream << xstring(current_row[col]) << endl;
			}	
		}

		t++;
	}

	output_file_stream.close();

	return;
}



#line 1 "print_debug_output_aig.BOND_PORTFOLIO_AIG.for"                                                                                   
void BOND_PORTFOLIO_AIG::print_debug_output_aig(void)
{
	// Gets column output file name
	xstring output_file_path = replaceWildcards(output_location());

	// Chop string off at the last "~"
	xstring output_file_name_prefix = xstring(output_file_path(0 , output_file_path.find_first_of("~")));

	// Get model point and scenario number
	xstring mp_id = fia->mp_id;
	xstring scen_id = xstring(proj_task_loop_num);

	// Print spot prices
	xstring debug_file_path = output_file_name_prefix + "_" + mp_id + "_" + scen_id + xstring("_SpotPrices.csv");
	print_debug_initialized_table_aig(debug_file_path, spot_prices);

	// Print par yields
	debug_file_path = output_file_name_prefix + "_" + mp_id + "_" + scen_id + xstring("_ParYields.csv");
	print_debug_initialized_table_aig(debug_file_path, par_yields);

	// Print new asset durations
	debug_file_path = output_file_name_prefix + "_" + mp_id + "_" + scen_id + xstring("_NewAssetDurations.csv");
	print_debug_initialized_table_aig(debug_file_path, new_asset_durations);

	return;
}



	static BOND_PORTFOLIO_AIG_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (BOND_PORTFOLIO_AIG_UDF::*dPXi) (int);
typedef double (BOND_PORTFOLIO_AIG_UDF::*dPXid) (int, double);
typedef double (BOND_PORTFOLIO_AIG_UDF::*dPF) ();
typedef double (BOND_PORTFOLIO_AIG_UDF::*dPFd) (double);
typedef int (BOND_PORTFOLIO_AIG_UDF::*iPF) ();
typedef int (BOND_PORTFOLIO_AIG_UDF::*iPFi) (int);
typedef xstring (BOND_PORTFOLIO_AIG_UDF::*sPF) ();
typedef xstring (BOND_PORTFOLIO_AIG_UDF::*sPFs) (xstring);

const CashFlowCommonData BOND_PORTFOLIO_AIG::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "asset_amt_b_aig", "bond_portfolio_aig_asset_amt_b_aig",  "asset_amt_b_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_asset_amt_b_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->asset_amt_b_aig),
	CashFlowCommonData(2, "asset_amt_e_aig", "bond_portfolio_aig_asset_amt_e_aig",  "asset_amt_e_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_asset_amt_e_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->asset_amt_e_aig),
	CashFlowCommonData(3, "asset_amt_matured_aig", "bond_portfolio_aig_asset_amt_matured_aig",  "asset_amt_matured_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_asset_amt_matured_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->asset_amt_matured_aig),
	CashFlowCommonData(4, "asset_amt_new_aig", "bond_portfolio_aig_asset_amt_new_aig",  "asset_amt_new_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_asset_amt_new_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->asset_amt_new_aig),
	CashFlowCommonData(5, "avg_coupon_rt_aig", "bond_portfolio_aig_avg_coupon_rt_aig",  "avg_coupon_rt_aig",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_avg_coupon_rt_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->avg_coupon_rt_aig),
	CashFlowCommonData(6, "cash_flow_pct_aig", "bond_portfolio_aig_cash_flow_pct_aig",  "cash_flow_pct_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_cash_flow_pct_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->cash_flow_pct_aig),
	CashFlowCommonData(7, "coupon_amt_aig", "bond_portfolio_aig_coupon_amt_aig",  "coupon_amt_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_coupon_amt_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->coupon_amt_aig),
	CashFlowCommonData(8, "duration_curr_asset_aig", "bond_portfolio_aig_duration_curr_asset_aig",  "duration_curr_asset_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_duration_curr_asset_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->duration_curr_asset_aig),
	CashFlowCommonData(9, "duration_new_asset_aig", "bond_portfolio_aig_duration_new_asset_aig",  "duration_new_asset_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_duration_new_asset_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->duration_new_asset_aig),
	CashFlowCommonData(10, "duration_target_asset_aig", "bond_portfolio_aig_duration_target_asset_aig",  "duration_target_asset_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_duration_target_asset_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->duration_target_asset_aig),
	CashFlowCommonData(11, "initialize", "bond_portfolio_aig_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_initialize, 'E','Y', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(12, "new_money_rate_aig", "bond_portfolio_aig_new_money_rate_aig",  "new_money_rate_aig",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_new_money_rate_aig, 'E','Y', '3', 'P', (size_t)&modelOffset->new_money_rate_aig),
	CashFlowCommonData(13, "pol_yr", "bond_portfolio_aig_pol_yr",  "pol_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_pol_yr, 'B','N', '3', 'C', (size_t)&modelOffset->pol_yr),
	CashFlowCommonData(14, "startup", "bond_portfolio_aig_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&BOND_PORTFOLIO_AIG_UDF::virtual_startup, 'E','Y', '3', 'N', (size_t)&modelOffset->startup)
};
const CashFlowCommonData* BOND_PORTFOLIO_AIG::mCFStaticData[] = {
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[0],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[1],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[2],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[3],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[4],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[5],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[6],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[7],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[8],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[9],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[10],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[11],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[12],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[13],
	&BOND_PORTFOLIO_AIG::mCFStaticData_0[14],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for cash_flow_pct_defn_aig                                                                                       
	const ChoicePair cash_flow_pct_defn_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::INPUT_VECTOR, "Input Vector")
		,ChoicePair(StrEnum::BOND, "Bond")
	};
	const EnumList cash_flow_pct_defn_aigEnumList(2, cash_flow_pct_defn_aigChoicePairs);

	// EnumList for coupon_freq_defn_aig                                                                                       
	const ChoicePair coupon_freq_defn_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MONTHLY, "Monthly")
		,ChoicePair(StrEnum::ANNUALLY, "Annually")
	};
	const EnumList coupon_freq_defn_aigEnumList(2, coupon_freq_defn_aigChoicePairs);

	// EnumList for new_asset_rate_tenors_expand_defn_aig                                                                                       
	const ChoicePair new_asset_rate_tenors_expand_defn_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::USE_COUPON_FREQ_DEFN_AIG, "Use coupon_freq_defn_aig")
		,ChoicePair(StrEnum::ANNUAL, "Annual")
	};
	const EnumList new_asset_rate_tenors_expand_defn_aigEnumList(2, new_asset_rate_tenors_expand_defn_aigChoicePairs);

	// EnumList for new_money_rate_defn_aig                                                                                       
	const ChoicePair new_money_rate_defn_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::PAR_YIELD, "Par Yield")
		,ChoicePair(StrEnum::COMPANY_YIELD_PLUS_MATRIX_SPREAD, "Company Yield Plus Matrix Spread")
	};
	const EnumList new_money_rate_defn_aigEnumList(2, new_money_rate_defn_aigChoicePairs);

	// EnumList for print_debug_output_defn_aig                                                                                       
	const ChoicePair print_debug_output_defn_aigChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::YES, "Yes")
		,ChoicePair(StrEnum::NO, "No")
	};
	const EnumList print_debug_output_defn_aigEnumList(2, print_debug_output_defn_aigChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace BOND_PORTFOLIO_AIG_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(BOND_PORTFOLIO_AIG::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(BOND_PORTFOLIO_AIG::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace BOND_PORTFOLIO_AIG_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void BOND_PORTFOLIO_AIG::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> BOND_PORTFOLIO_AIG::mgr_;

	Attribute::Descriptor BOND_PORTFOLIO_AIG::descriptor_0[] = {
	Descriptor(0, Attribute::DOUBLE,	"asset_yld_addn_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->asset_yld_addn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::INT,	"bond_count_aig", -1, (size_t)&modelOffset->bond_count_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(2, Attribute::STR_ENUM,	"cash_flow_pct_defn_aig", -1, (size_t)&modelOffset->cash_flow_pct_defn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &cash_flow_pct_defn_aigEnumList, Feature(true)),
	Descriptor(3, Attribute::DOUBLE,	"cash_flow_pct_input_vector_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->cash_flow_pct_input_vector_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(4, Attribute::STR_ENUM,	"coupon_freq_defn_aig", -1, (size_t)&modelOffset->coupon_freq_defn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &coupon_freq_defn_aigEnumList, Feature(true)),
	Descriptor(5, Attribute::DOUBLE,	"new_asset_duration_floor_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->new_asset_duration_floor_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::STRING,	"new_asset_rate_id_aig", -1, (size_t)&modelOffset->new_asset_rate_id_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::STRING,	"new_asset_rate_tenors_aig", -1, (size_t)&modelOffset->new_asset_rate_tenors_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::STR_ENUM,	"new_asset_rate_tenors_expand_defn_aig", -1, (size_t)&modelOffset->new_asset_rate_tenors_expand_defn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &new_asset_rate_tenors_expand_defn_aigEnumList, Feature(true)),
	Descriptor(9, Attribute::STR_ENUM,	"new_money_rate_defn_aig", -1, (size_t)&modelOffset->new_money_rate_defn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &new_money_rate_defn_aigEnumList, Feature(true)),
	Descriptor(10, Attribute::STR_ENUM,	"print_debug_output_defn_aig", -1, (size_t)&modelOffset->print_debug_output_defn_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &print_debug_output_defn_aigEnumList, Feature(true)),
	Descriptor(11, Attribute::DOUBLE,	"target_asset_duration_aig", Descriptor::NOT_INDEXED, (size_t)&modelOffset->target_asset_duration_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::SCALAR_INT,	"commencement_period", -1, (size_t)&modelOffset->commencement_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_commencement_period)),
	Descriptor(14, Attribute::SCALAR_INT,	"coupon_freq_aig", -1, (size_t)&modelOffset->coupon_freq_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_coupon_freq_aig)),
	Descriptor(15, Attribute::SCALAR_INT,	"final_period", -1, (size_t)&modelOffset->final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_final_period)),
	Descriptor(16, Attribute::SCALAR_INT,	"initialize_bond_portfolio_aig", -1, (size_t)&modelOffset->initialize_bond_portfolio_aig,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_initialize_bond_portfolio_aig)),
	Descriptor(17, Attribute::SCALAR_INT,	"maturity_period", -1, (size_t)&modelOffset->maturity_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&BOND_PORTFOLIO_AIG_UDF::bond_portfolio_aig_maturity_period)),
	};

	Attribute::Descriptor* BOND_PORTFOLIO_AIG::descriptorTable[] = {
	&BOND_PORTFOLIO_AIG::descriptor_0[0],
	&BOND_PORTFOLIO_AIG::descriptor_0[1],
	&BOND_PORTFOLIO_AIG::descriptor_0[2],
	&BOND_PORTFOLIO_AIG::descriptor_0[3],
	&BOND_PORTFOLIO_AIG::descriptor_0[4],
	&BOND_PORTFOLIO_AIG::descriptor_0[5],
	&BOND_PORTFOLIO_AIG::descriptor_0[6],
	&BOND_PORTFOLIO_AIG::descriptor_0[7],
	&BOND_PORTFOLIO_AIG::descriptor_0[8],
	&BOND_PORTFOLIO_AIG::descriptor_0[9],
	&BOND_PORTFOLIO_AIG::descriptor_0[10],
	&BOND_PORTFOLIO_AIG::descriptor_0[11],
	&BOND_PORTFOLIO_AIG::descriptor_0[12],
	&BOND_PORTFOLIO_AIG::descriptor_0[13],
	&BOND_PORTFOLIO_AIG::descriptor_0[14],
	&BOND_PORTFOLIO_AIG::descriptor_0[15],
	&BOND_PORTFOLIO_AIG::descriptor_0[16],
	&BOND_PORTFOLIO_AIG::descriptor_0[17],
	nullptr};
	const size_t BOND_PORTFOLIO_AIG::sDescriptorCount = 18;

//factory
BOND_PORTFOLIO_AIG* BOND_PORTFOLIO_AIG::makeThis(int isSubmodel, ModelClass* owner, BOND_PORTFOLIO_AIG* peer, 
						int mainRebase, const xstring &name, BOND_PORTFOLIO_AIG_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("BOND_PORTFOLIO_AIG::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor BOND_PORTFOLIO_AIG");
#endif
	BOND_PORTFOLIO_AIG* newP = (BOND_PORTFOLIO_AIG*)new BOND_PORTFOLIO_AIG_UDF
   	  ("bond_portfolio_aig", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

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
	newP->sm_fia_bond_aig.setPersistentObject(BOND_AIG_persistent_object::makeThis(1, newP, (BOND_AIG*)(peer?peer->sm_fia_bond_aig.getPersistentObject():0), mainRebase, name + "|fia_bond_aig", arrayTemplate?arrayTemplate->sm_fia_bond_aig.getPersistentObject():0, false));


	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	return newP;
}

//factory
BOND_PORTFOLIO_AIG_persistent_object* BOND_PORTFOLIO_AIG_persistent_object::makeThis(int isSubmodel, ModelClass* owner, BOND_PORTFOLIO_AIG* peer, 
							int mainRebase, const xstring &name, BOND_PORTFOLIO_AIG_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("BOND_PORTFOLIO_AIG_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor BOND_PORTFOLIO_AIG_persistent_object");
#endif
	BOND_PORTFOLIO_AIG_persistent_object* newP = (BOND_PORTFOLIO_AIG_persistent_object*)new BOND_PORTFOLIO_AIG_persistent_object
   	  ("bond_portfolio_aig", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			BOND_PORTFOLIO_AIG_persistent_object* pd = dynamic_cast<BOND_PORTFOLIO_AIG_persistent_object*>(product);
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
	newP->sm_fia_bond_aig.setPersistentObject(BOND_AIG_persistent_object::makeThis(1, newP, (BOND_AIG*)(peer?peer->sm_fia_bond_aig.getPersistentObject():0), mainRebase, name + "|fia_bond_aig", arrayTemplate?arrayTemplate->sm_fia_bond_aig.getPersistentObject():0, false));

	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	newP->msnumelement.setValue(0);
	return newP;
}

typedef double (BOND_PORTFOLIO_AIG_UDF::*dPF) ();
typedef double (BOND_PORTFOLIO_AIG_UDF::*dPFd) (double);
typedef int (BOND_PORTFOLIO_AIG_UDF::*iPF) ();
typedef int (BOND_PORTFOLIO_AIG_UDF::*iPFi) (int);
typedef xstring (BOND_PORTFOLIO_AIG_UDF::*sPF) ();
typedef xstring (BOND_PORTFOLIO_AIG_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
BOND_PORTFOLIO_AIG::BOND_PORTFOLIO_AIG(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

  , sm_fia_bond_aig(0, 0, 0)
	, fia(company_liab_fia)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_bond_portfolio_aig(company_liab_fia_fia_bond_portfolio_aig)
	, fia_rates(company_liab_fia_fia_rates)
	, rates(company_rates)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (BOND_PORTFOLIO_AIG_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
BOND_PORTFOLIO_AIG::BOND_PORTFOLIO_AIG(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(14, BOND_PORTFOLIO_AIG::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

  , sm_fia_bond_aig(0, 0, 0)
	, fia(company_liab_fia)
	, fia_automation(company_liab_fia_fia_automation)
	, fia_bond_portfolio_aig(company_liab_fia_fia_bond_portfolio_aig)
	, fia_rates(company_liab_fia_fia_rates)
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

		adopt(&sm_fia_bond_aig);

		ModelClassName = modelClassName;
       isSubmodel = isSm;
       isMainModel = !isSm;
		modelName = name;

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
#ifdef __CREATE_RATES_ECONOMY_CLASS_
       company_rates = 0;
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

	for (int cf_no = 1; cf_no <= 14; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (BOND_PORTFOLIO_AIG_UDF::*dPXi2) (int, int);
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


 void BOND_PORTFOLIO_AIG::copy_names() {

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
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_rates = (RATES_ECONOMY*)(findUnique("company|rates"));
#endif
 }
//copy_names END@2


 void BOND_PORTFOLIO_AIG::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int BOND_PORTFOLIO_AIG_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& BOND_PORTFOLIO_AIG_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double BOND_PORTFOLIO_AIG_persistent_object::ms_columnValue(const int columnNumber, const int t) {
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

	int BOND_PORTFOLIO_AIG_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double BOND_PORTFOLIO_AIG_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
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

	double BOND_PORTFOLIO_AIG_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
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

	void BOND_PORTFOLIO_AIG_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void BOND_PORTFOLIO_AIG_persistent_object::write(long include_submodels) {
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

	void BOND_PORTFOLIO_AIG_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void BOND_PORTFOLIO_AIG_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void BOND_PORTFOLIO_AIG_persistent_object::write(const xstring& key, long include_submodels) {
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




	BOND_PORTFOLIO_AIG_persistent_object::~BOND_PORTFOLIO_AIG_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool BOND_PORTFOLIO_AIG_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void BOND_PORTFOLIO_AIG_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void BOND_PORTFOLIO_AIG_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void BOND_PORTFOLIO_AIG_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void BOND_PORTFOLIO_AIG_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void BOND_PORTFOLIO_AIG_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* BOND_PORTFOLIO_AIG_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* BOND_PORTFOLIO_AIG_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* BOND_PORTFOLIO_AIG_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char BOND_PORTFOLIO_AIG_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void BOND_PORTFOLIO_AIG_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
BOND_PORTFOLIO_AIG_persistent_object::BOND_PORTFOLIO_AIG_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			BOND_PORTFOLIO_AIG(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(BOND_PORTFOLIO_AIG::sm_bond_is)
	, sm_bond_pv(BOND_PORTFOLIO_AIG::sm_bond_pv)
	, sm_bond_ym(BOND_PORTFOLIO_AIG::sm_bond_ym)
	, sm_mtg_is(BOND_PORTFOLIO_AIG::sm_mtg_is)
	, sm_mtg_pv(BOND_PORTFOLIO_AIG::sm_mtg_pv)
	, sm_mtg_ym(BOND_PORTFOLIO_AIG::sm_mtg_ym)

	, sm_fia_bond_aig(BOND_PORTFOLIO_AIG::sm_fia_bond_aig)
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
BOND_PORTFOLIO_AIG::~BOND_PORTFOLIO_AIG() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
//	ModelClass* fia_bond_aig_persObj = sm_fia_bond_aig.getPersistentObject();
//	doAdopt(fia_bond_aig_persObj, Node::COUNTED); // delete called by node dtor.
	if (sm_fia_bond_aig.IsValidSubModelOfBaseModelClass()){
		sm_fia_bond_aig.resize(0);
		delete sm_fia_bond_aig.getPersistentObject();
		sm_fia_bond_aig.mPersistentObj = 0;
	}

}
//destructor END@2
void BOND_PORTFOLIO_AIG::findTargetColumns() {

}
//findTargetColumns END@2
void BOND_PORTFOLIO_AIG::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void BOND_PORTFOLIO_AIG::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void BOND_PORTFOLIO_AIG::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void BOND_PORTFOLIO_AIG::start_of_projection() {
}
//start_of_projection END@2

void BOND_PORTFOLIO_AIG::end_of_projection() {
}
//end_of_projection END@2

void BOND_PORTFOLIO_AIG::start_of_layer() {
}


void BOND_PORTFOLIO_AIG::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void BOND_PORTFOLIO_AIG::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void BOND_PORTFOLIO_AIG::after_startup(int decrement) {
// Call startup for submodels
	   sm_fia_bond_aig.doBeforeStartupProcessing(decrement);

}
//after_startup END@2


 void BOND_PORTFOLIO_AIG::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> BOND_PORTFOLIO_AIG::ddfVector;
BitArray BOND_PORTFOLIO_AIG::dataVariables(18);
bool BOND_PORTFOLIO_AIG::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool BOND_PORTFOLIO_AIG::writeClassInfo = true;

void BOND_PORTFOLIO_AIG::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, BOND_PORTFOLIO_AIG::descriptor_0>::dT = BOND_PORTFOLIO_AIG::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, BOND_PORTFOLIO_AIG::descriptor_0>::dT = BOND_PORTFOLIO_AIG::descriptor_0;

