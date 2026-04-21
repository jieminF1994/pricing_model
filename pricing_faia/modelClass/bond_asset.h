#ifndef __BOND_ASSET_H_
#define __BOND_ASSET_H_
#pragma warning ( disable : 4819 )

struct bondInitialValuesData
	{
	double yld_numer;
	double dflt_amt;
	double mkt_val_bef_sale;
	double eff_dur;
	double mkt_sprd;
	double net_yld;
	double amortzn_cost_period;
	double net_yld_at_issue;
	double opt_sprd;
	double refinancing_rate_opt_sprd;
	double weighted_avg_life;
	};
typedef map <xstring, struct bondInitialValuesData*, less<xstring> > bondivmap;

#include <math.h>
#include "xstring.h"
#include "Locator.h"
#include "circtabl.h"
#include "message.h"
#include "MULTIDIST.H"
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
#include "rafmsqlite.h"
#include "fmlstack.h"
#include "useful.h"
#include "RafmSchedule.h"
#include "DBTable.h"
#include "VariantTable.h"
#include "hashobject.h"
#include "mvisitor.h"
#include "infdbf.h"
#include "generatedCppHeader.h"
#include "OutputFileReader.h"
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#undef WRITE_PUT_METHODS
            extern MY_DLL int profile_wanted;
extern MY_DLL int model_capacity;
extern MY_DLL int &t_high;
extern MY_DLL2 int restore_variables_ind;
extern MY_DLL2 FormulaStack *FS;
extern MY_DLL ModelClass *CP;
extern MY_DLL xstring modelClass;
extern MY_DLL xstring group;
extern MY_DLL xstring cashflow_req;
extern MY_DLL long layer;
extern MY_DLL long scenario_number;
extern MY_DLL int num_of_main_layers;
extern MY_DLL int layer_offset;
extern MY_DLL int t_low;
extern MY_DLL int pv_period;

#include "prodcomp.h"
#include "include.h"
#include "column2.h"
#include "VariableInterface.h"
extern MY_DLL ofstream log_strm;
#define ifkey(x)  if (strcmp(key.c_str(), (x))==0)

#include "StringProxy.h"			// ... contains String Proxies
#include "StringEnumProxy.h"		// ... contains StringEnum Proxies
#include "NumProxyNonMembers.h"		// ... min, max
#include "StringedProxyNonMembers.h"		// ... concatenation for StringEnum
#include "ArrayProxy.h"			// ... contains Array Proxies
#include "ScalarProxy.h"			// ... contains Scalar Proxies
#include "ModelGroupProxy.h"
#include "NonAssocTableProxy.h"	// ... contains Rate_table and Table_from
#include "AssocTableProxies.h"		// ... contains AssocArray tables
#include "EnumValue.h"				// ... contains Enum Values


using namespace StrEnum;

#ifdef __CREATE_ADCO_ASSET_CLASS_
class ADCO_ASSET;
class ADCO_ASSET_persistent_object;
#endif

#ifdef __CREATE_ANN_PBA_PBA_CLASS_
class ANN_PBA_PBA;
class ANN_PBA_PBA_persistent_object;
typedef TComp<ANN_PBA_PBA, ANN_PBA_PBA_persistent_object> _1D_ANN_PBA_PBA;
#endif

#ifdef __CREATE_ASSET_ASSET_CLASS_
class ASSET_ASSET;
class ASSET_ASSET_persistent_object;
#endif

#ifdef __CREATE_AUTOMATION_CLASS_
class AUTOMATION;
class AUTOMATION_persistent_object;
#endif

#ifdef __CREATE_A_SUBPORT_ASSET_CLASS_
class A_SUBPORT_ASSET;
class A_SUBPORT_ASSET_persistent_object;
typedef TComp<A_SUBPORT_ASSET, A_SUBPORT_ASSET_persistent_object> _1D_A_SUBPORT_ASSET;
typedef TMultiDComp<_1D_A_SUBPORT_ASSET, A_SUBPORT_ASSET_persistent_object> _2D_A_SUBPORT_ASSET;
typedef TMultiDComp<_2D_A_SUBPORT_ASSET, A_SUBPORT_ASSET_persistent_object> _3D_A_SUBPORT_ASSET;
#endif

#ifdef __CREATE_BOND_ASSET_CLASS_
class BOND_ASSET;
class BOND_ASSET_persistent_object;
typedef TComp<BOND_ASSET, BOND_ASSET_persistent_object> _1D_BOND_ASSET;
#endif

#ifdef __CREATE_BOND_CF_ASSET_CLASS_
class BOND_CF_ASSET;
class BOND_CF_ASSET_persistent_object;
#endif

#ifdef __CREATE_COMP_COMP_CLASS_
class COMP_COMP;
class COMP_COMP_persistent_object;
#endif

#ifdef __CREATE_EIO_ASSET_CLASS_
class EIO_ASSET;
class EIO_ASSET_persistent_object;
typedef TComp<EIO_ASSET, EIO_ASSET_persistent_object> _1D_EIO_ASSET;
#endif

#ifdef __CREATE_EPA_ASSET_CLASS_
class EPA_ASSET;
class EPA_ASSET_persistent_object;
typedef TComp<EPA_ASSET, EPA_ASSET_persistent_object> _1D_EPA_ASSET;
#endif

#ifdef __CREATE_EPL_LIAB_CLASS_
class EPL_LIAB;
class EPL_LIAB_persistent_object;
typedef TComp<EPL_LIAB, EPL_LIAB_persistent_object> _1D_EPL_LIAB;
#endif

#ifdef __CREATE_FIAAFUND_LIAB_CLASS_
class FIAAFUND_LIAB;
class FIAAFUND_LIAB_persistent_object;
typedef TComp<FIAAFUND_LIAB, FIAAFUND_LIAB_persistent_object> _1D_FIAAFUND_LIAB;
#endif

#ifdef __CREATE_FIACARVM_LIAB_CLASS_
class FIACARVM_LIAB;
class FIACARVM_LIAB_persistent_object;
typedef TComp<FIACARVM_LIAB, FIACARVM_LIAB_persistent_object> _1D_FIACARVM_LIAB;
#endif

#ifdef __CREATE_FIA_LIAB_CLASS_
class FIA_LIAB;
class FIA_LIAB_persistent_object;
typedef TComp<FIA_LIAB, FIA_LIAB_persistent_object> _1D_FIA_LIAB;
#endif

#ifdef __CREATE_HDG_GRP_COMP_CLASS_
class HDG_GRP_COMP;
class HDG_GRP_COMP_persistent_object;
typedef TComp<HDG_GRP_COMP, HDG_GRP_COMP_persistent_object> _1D_HDG_GRP_COMP;
typedef TMultiDComp<_1D_HDG_GRP_COMP, HDG_GRP_COMP_persistent_object> _2D_HDG_GRP_COMP;
#endif

#ifdef __CREATE_INTEX_ASSET_CLASS_
class INTEX_ASSET;
class INTEX_ASSET_persistent_object;
#endif

#ifdef __CREATE_INVSTRAT_ASSET_CLASS_
class INVSTRAT_ASSET;
class INVSTRAT_ASSET_persistent_object;
typedef TComp<INVSTRAT_ASSET, INVSTRAT_ASSET_persistent_object> _1D_INVSTRAT_ASSET;
#endif

#ifdef __CREATE_LIAB_LIAB_CLASS_
class LIAB_LIAB;
class LIAB_LIAB_persistent_object;
#endif

#ifdef __CREATE_MTG_ASSET_CLASS_
class MTG_ASSET;
class MTG_ASSET_persistent_object;
typedef TComp<MTG_ASSET, MTG_ASSET_persistent_object> _1D_MTG_ASSET;
#endif

#ifdef __CREATE_MTG_CF_ASSET_CLASS_
class MTG_CF_ASSET;
class MTG_CF_ASSET_persistent_object;
#endif

#ifdef __CREATE_RATES_ECONOMY_CLASS_
class RATES_ECONOMY;
class RATES_ECONOMY_persistent_object;
#endif

#ifdef __CREATE_SEG_COMP_CLASS_
class SEG_COMP;
class SEG_COMP_persistent_object;
typedef TComp<SEG_COMP, SEG_COMP_persistent_object> _1D_SEG_COMP;
#endif

#ifdef __CREATE_SFAS133_GAAP_CLASS_
class SFAS133_GAAP;
class SFAS133_GAAP_persistent_object;
typedef TComp<SFAS133_GAAP, SFAS133_GAAP_persistent_object> _1D_SFAS133_GAAP;
#endif

#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
class SFAS97RD_GAAP;
class SFAS97RD_GAAP_persistent_object;
typedef TComp<SFAS97RD_GAAP, SFAS97RD_GAAP_persistent_object> _1D_SFAS97RD_GAAP;
typedef TMultiDComp<_1D_SFAS97RD_GAAP, SFAS97RD_GAAP_persistent_object> _2D_SFAS97RD_GAAP;
#endif

#ifdef __CREATE_UTIL_RAFM_CLASS_
class UTIL_RAFM;
class UTIL_RAFM_persistent_object;
#endif


#include "ModelClass\bond_cf_asset.h"

namespace BOND_ASSET_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class BOND_ASSET_persistent_object;
class BOND_ASSET : public ModelClass {

friend void clearSharedTempTables();
	

protected:
	static TempTableHolderCollection TTHC;
	void removeSMPointers(ModelClass* modelToRemove);
static const CashFlowCommonData* mCFStaticData[];
  static const CashFlowCommonData mCFStaticData_0[]; 
  static Table::TableMgr<VariantTable> mgr_;

public :
	TempTableHolderCollection *getTTHC() const { return &TTHC;}
	VariableAccess Variable;
	Table::TableMgr<VariantTable>& getVarTableMgr() {
		return mgr_;
	}

	static const bool sModelGroupByParent_ = false;
	virtual bool isModelGroupByParent() const {
		return sModelGroupByParent_;
	}

	size_t sizeofThis() const { return sizeof(BOND_ASSET); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;
	static void Terminator();
	static FunctionPtr RegisterTerminatorOnce;
	
int sequence_id;
int calculated_t_low;
int calculated_t_high;
struct bondInitialValuesData* initial_values;
int net_yld_at_issue_calc_flag;
double purch_amt;
double pmt_rate_init_guess;
int refinancing_rate_opt_sprd_calc_flag;
int cost_basis_amortzn_mths;
int purch_asset_mp_num;
bool read_sch_file_flag;
bool set_call_sch_flag;
bool set_put_sch_flag;

// Bond model point variables
xstring seg_id;
StrEnum::EnumValue port_defn;
StrEnum::EnumValue sale_class;
xstring issue_date;
xstring maturity_date;
xstring planned_sale_date;
double init_par_val;
double init_cost_basis;
double init_bk_val;
double init_mkt_val;
StrEnum::EnumValue pmt_mode;
double init_pmt_rate;
double par_val_at_issue;
double taxable_pct;
StrEnum::EnumValue call_defn;
xstring call_opt_first_date;
StrEnum::EnumValue call_price_defn;
double yld_maint_addn;
StrEnum::EnumValue put_price_defn;
StrEnum::EnumValue put_defn;
xstring put_opt_first_date;
StrEnum::EnumValue sinking_fund_defn;
xstring adj_reset_category_id;
double adj_reset_scen_yr;
double adj_reset_scen_mult;
double adj_reset_renewal_addn;
xstring adj_next_reset_date;
int adj_reset_mths;
double adj_max_incr_per_reset;
double adj_max_decr_per_reset;
double adj_min_rate;
double adj_max_rate;
double avr_contribn_pct;
double avr_max_pct;
double avr_obj_pct;
double rbc_c1_pct;

// Bond schedule variables
SmartArray <double> call_price_sch;
SmartArray <double> put_price_sch;
SmartArray <double> sinking_fund_sch;

SmartArray <double> psa_base_rate;

	void init_(){
		

sequence_id = 0;
initial_values = NULL;
net_yld_at_issue_calc_flag = 0;
purch_amt = 0.0;
pmt_rate_init_guess = 0.0;
refinancing_rate_opt_sprd_calc_flag = 0;
cost_basis_amortzn_mths = 0;
purch_asset_mp_num = -1;
read_sch_file_flag = true;
set_call_sch_flag = true;
set_put_sch_flag = true;

// Initialize bond model point variables
seg_id = "Seg";
port_defn = INVESTMENT;
sale_class = AVAILABLE_FOR_SALE; 
issue_date = "1900/01/01";
maturity_date = "1900/01/01";
planned_sale_date = "9999/01/01"; 
init_par_val = 0.0;
init_cost_basis = 0.0;
init_bk_val = 0.0;
init_mkt_val = 0.0;
pmt_mode = SEMI_ANNUAL;
init_pmt_rate = 0.0;
par_val_at_issue = 0.0;
taxable_pct = 0.0;
call_defn = NOT_APPLICABLE;
call_opt_first_date = "9999/01/01";
call_price_defn = PRICE_SCHEDULE; 
yld_maint_addn = 0.0;
put_defn = NOT_APPLICABLE;
put_opt_first_date = "9999/01/01";
sinking_fund_defn = NO;
adj_reset_category_id = "Govt";
adj_reset_scen_yr = 0.25;
adj_reset_scen_mult = 0.0;
adj_reset_renewal_addn = 0.0;
adj_next_reset_date = "9999/01/01";
adj_reset_mths = 12;
adj_max_incr_per_reset = 0.0;
adj_max_decr_per_reset = 0.0;
adj_min_rate = 0.0;
adj_max_rate = 0.0;
avr_contribn_pct = 0.0;
avr_max_pct = 0.0;
avr_obj_pct = 0.0;
rbc_c1_pct = 0.0;


		bIsInit = true;
	}
	void deInit_(){

	}

#ifdef __CREATE_ANN_PBA_PBA_CLASS_
	ANN_PBA_PBA	*company_seg_ann_pba;
	ANN_PBA_PBA	*&ann_pba;
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
	ASSET_ASSET	*company_asset;
	ASSET_ASSET	*&asset;
#endif
#ifdef __CREATE_BOND_ASSET_CLASS_
	BOND_ASSET	*company_asset_bond;
	BOND_ASSET	*&bond;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
	BOND_CF_ASSET	*company_asset_bond_bond_cf;
	BOND_CF_ASSET	*&bond_cf;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
	BOND_CF_ASSET	*company_asset_bond_bond_cf_bond_is;
	BOND_CF_ASSET	*&bond_is;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
	BOND_CF_ASSET	*company_asset_bond_bond_cf_bond_pv;
	BOND_CF_ASSET	*&bond_pv;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
	BOND_CF_ASSET	*company_asset_bond_bond_cf_bond_ym;
	BOND_CF_ASSET	*&bond_ym;
#endif
#ifdef __CREATE_COMP_COMP_CLASS_
	COMP_COMP	*company;
#endif
#ifdef __CREATE_EPL_LIAB_CLASS_
	EPL_LIAB	*company_liab_epl;
	EPL_LIAB	*&epl;
#endif
#ifdef __CREATE_INVSTRAT_ASSET_CLASS_
	INVSTRAT_ASSET	*company_inv_strategy;
	INVSTRAT_ASSET	*&inv_strategy;
#endif
#ifdef __CREATE_LIAB_LIAB_CLASS_
	LIAB_LIAB	*company_liab;
	LIAB_LIAB	*&liab;
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
	MTG_CF_ASSET	*company_asset_mtg_mtg_cf;
	MTG_CF_ASSET	*&mtg_cf;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
	RATES_ECONOMY	*company_rates;
	RATES_ECONOMY	*&rates;
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
	SEG_COMP	*company_seg;
	SEG_COMP	*&seg;
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
	SFAS97RD_GAAP	*company_seg_sfas97rd;
	SFAS97RD_GAAP	*&sfas97rd;
#endif
 // Column Definition Begins
 	ColumnAccessor < mCFStaticData_0 > accr_inc;
 	ColumnAccessor < mCFStaticData_0 > accr_int;
 	ColumnAccessor < mCFStaticData_0 > accr_int_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > accr_int_aft_put;
 	ColumnAccessor < mCFStaticData_0 > accr_int_bef_call;
 	ColumnAccessor < mCFStaticData_0 > accr_int_bef_fund_match_sale;
 	ColumnAccessor < mCFStaticData_0 > accr_int_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > accr_int_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > accr_int_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > accr_int_dflt;
 	ColumnAccessor < mCFStaticData_0 > accr_int_purch;
 	ColumnAccessor < mCFStaticData_0 > accr_int_rent;
 	ColumnAccessor < mCFStaticData_0 > accr_int_sold;
 	ColumnAccessor < mCFStaticData_0 > asset_detail_rpt_pv_flag;
 	ColumnAccessor < mCFStaticData_0 > asset_min_size_sale_flag;
 	ColumnAccessor < mCFStaticData_0 > avr_basic_contribn;
 	ColumnAccessor < mCFStaticData_0 > avr_basic_contribn_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_max;
 	ColumnAccessor < mCFStaticData_0 > avr_max_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_obj;
 	ColumnAccessor < mCFStaticData_0 > avr_obj_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_realzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > base_inc_bef_call;
 	ColumnAccessor < mCFStaticData_0 > bk_val;
 	ColumnAccessor < mCFStaticData_0 > bk_val_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > bk_val_aft_put;
 	ColumnAccessor < mCFStaticData_0 > bk_val_bef_call;
 	ColumnAccessor < mCFStaticData_0 > bk_val_bef_fund_match_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val_plus_accr_int_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val_purch;
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_from_sale;
 	ColumnAccessor < mCFStaticData_0 > cash_flow;
 	ColumnAccessor < mCFStaticData_0 > cost_basis;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_accrual;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_aft_put;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_bef_call;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_dflt;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_incr_appreciation;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_purch;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_sched_prin_pmt;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_sold;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > dflt_amt;
 	ColumnAccessor < mCFStaticData_0 > dflt_pct;
 	ColumnAccessor < mCFStaticData_0 > dur_val;
 	ColumnAccessor < mCFStaticData_0 > eff_dur;
 	ColumnAccessor < mCFStaticData_0 > finalize;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_bk_val;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_unrealzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > gaap_surp_bk_val;
 	ColumnAccessor < mCFStaticData_0 > gaap_unrealzd_cap_gain_incr;
 	ColumnAccessor < mCFStaticData_0 > imr_realzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > imr_realzd_cap_gain_from_sale;
 	ColumnAccessor < mCFStaticData_0 > imr_yrs_to_maturity;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > int_div_and_rent;
 	ColumnAccessor < mCFStaticData_0 > int_pmt;
 	ColumnAccessor < mCFStaticData_0 > mkt_risk_sprd;
 	ColumnAccessor < mCFStaticData_0 > mkt_sprd;
 	ColumnAccessor < mCFStaticData_0 > mkt_to_bk_ratio;
 	ColumnAccessor < mCFStaticData_0 > mkt_val;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_bef_fund_match_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_for_dur_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_for_dur_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_for_dur_sold;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_for_eff_dur;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_purch;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_shifted;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_sold;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_times_dur_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_times_dur_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_times_eff_dur;
 	ColumnAccessor < mCFStaticData_0 > mths_to_next_mkt_val_calc;
 	ColumnAccessor < mCFStaticData_0 > net_yld;
 	ColumnAccessor < mCFStaticData_0 > notional_amt;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_bef_fund_match_sale;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_inc;
 	ColumnAccessor < mCFStaticData_0 > opt_pmt;
 	ColumnAccessor < mCFStaticData_0 > opt_sprd;
 	ColumnAccessor < mCFStaticData_0 > rbc_c1;
 	ColumnAccessor < mCFStaticData_0 > rbc_c1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain_opt_pmt;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain_sale;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_loss_dflt;
 	ColumnAccessor < mCFStaticData_0 > risk_sprd;
 	ColumnAccessor < mCFStaticData_0 > risk_sprd_shifted;
 	ColumnAccessor < mCFStaticData_0 > sched_prin_pmt;
 	ColumnAccessor < mCFStaticData_0 > sinking_fund_sch_base;
 	ColumnAccessor < mCFStaticData_0 > sold_pct;
 	ColumnAccessor < mCFStaticData_0 > sold_pct_fund_match;
 	ColumnAccessor < mCFStaticData_0 > sold_pct_neg_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > sold_pct_planned;
 	ColumnAccessor < mCFStaticData_0 > sold_pct_rebal;
 	ColumnAccessor < mCFStaticData_0 > startup;
 	ColumnAccessor < mCFStaticData_0 > sub_port_id;
 	ColumnAccessor < mCFStaticData_0 > tax_exempt_inc;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_bef_fund_match_sale;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_gaap_surp;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_incr;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_released_on_sale;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_to_bk_ratio;
 	ColumnAccessor < mCFStaticData_0 > weighted_avg_life;
 	ColumnAccessor < mCFStaticData_0 > weighted_avg_life_opt_sensitivity;
 	ColumnAccessor < mCFStaticData_0 > yld_denom;
 	ColumnAccessor < mCFStaticData_0 > yld_numer;
 	ColumnAccessor < mCFStaticData_0 > yld_numer_adj_aig;
//Column Definition END@2

 // Temporary Table...
BOND_CF_ASSET *sm_bond_cf;
BOND_ASSET *sm_bond_is;
BOND_ASSET *sm_bond_pv;
BOND_ASSET *sm_bond_ym;
BOND_ASSET *sm_mtg_is;
BOND_ASSET *sm_mtg_pv;
BOND_ASSET *sm_mtg_ym;
int main_rebase_model; //1

public :
	static Attribute::Descriptor* descriptorTable[];
	static const size_t sDescriptorCount;
	size_t variableCount() const {
		return sDescriptorCount;
	}
	static Attribute::Descriptor descriptor_0[];
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4005)
// Disable the warning C4005: 'DESCRIPTOR_TABLE' : macro redefinition
#endif	MICROSOFT
	#define DESCRIPTOR_TABLE BOND_ASSET::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > adj_max_decr_per_reset_mp;
  inline double	Get_adj_max_decr_per_reset_mp() {
		return adj_max_decr_per_reset_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > adj_max_incr_per_reset_mp;
  inline double	Get_adj_max_incr_per_reset_mp() {
		return adj_max_incr_per_reset_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > adj_max_rate_mp;
  inline double	Get_adj_max_rate_mp() {
		return adj_max_rate_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > adj_min_rate_mp;
  inline double	Get_adj_min_rate_mp() {
		return adj_min_rate_mp; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > adj_next_reset_date_mp;
  inline xstring	Get_adj_next_reset_date_mp() {
		return adj_next_reset_date_mp; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > adj_reset_category_id_mp;
  inline xstring	Get_adj_reset_category_id_mp() {
		return adj_reset_category_id_mp; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > adj_reset_mths_mp;
  inline int	Get_adj_reset_mths_mp() {
		return adj_reset_mths_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > adj_reset_renewal_addn_mp;
  inline double	Get_adj_reset_renewal_addn_mp() {
		return adj_reset_renewal_addn_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > adj_reset_scen_mult_mp;
  inline double	Get_adj_reset_scen_mult_mp() {
		return adj_reset_scen_mult_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > adj_reset_scen_yr_mp;
  inline double	Get_adj_reset_scen_yr_mp() {
		return adj_reset_scen_yr_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > amortzd_cost_period_defn;
  inline xstring	Get_amortzd_cost_period_defn() {
		return amortzd_cost_period_defn; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > amortzd_cost_period_defn_save;
  inline xstring	Get_amortzd_cost_period_defn_save() {
		return amortzd_cost_period_defn_save; }
  inline void Set_amortzd_cost_period_defn_save(const xstring &v) {
		amortzd_cost_period_defn_save.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_detail_rpt_cusip_id;
  inline xstring	Get_asset_detail_rpt_cusip_id() {
		return asset_detail_rpt_cusip_id; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > asset_detail_rpt_final_period;
  inline int	Get_asset_detail_rpt_final_period() {
		return asset_detail_rpt_final_period; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > asset_detail_rpt_id;
  inline xstring	Get_asset_detail_rpt_id() {
		return asset_detail_rpt_id; }
  inline void Set_asset_detail_rpt_id(const xstring &v) {
		asset_detail_rpt_id.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_detail_rpt_pv_defn;
  inline xstring	Get_asset_detail_rpt_pv_defn() {
		return asset_detail_rpt_pv_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > asset_detail_rpt_start_period;
  inline int	Get_asset_detail_rpt_start_period() {
		return asset_detail_rpt_start_period; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > asset_id;
  inline xstring	Get_asset_id() {
		return asset_id; }
  inline void Set_asset_id(const xstring &v) {
		asset_id.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_id_mp;
  inline xstring	Get_asset_id_mp() {
		return asset_id_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_mkt_sprd_use_defn;
  inline xstring	Get_asset_mkt_sprd_use_defn() {
		return asset_mkt_sprd_use_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > avr_contribn_pct_mp;
  inline double	Get_avr_contribn_pct_mp() {
		return avr_contribn_pct_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > avr_max_pct_mp;
  inline double	Get_avr_max_pct_mp() {
		return avr_max_pct_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > avr_obj_pct_mp;
  inline double	Get_avr_obj_pct_mp() {
		return avr_obj_pct_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > bk_val_defn;
  inline xstring	Get_bk_val_defn() {
		return bk_val_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > call_defn_mp;
  inline xstring	Get_call_defn_mp() {
		return call_defn_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > call_opt_exercise_pct;
  inline double	Get_call_opt_exercise_pct() {
		return call_opt_exercise_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > call_opt_first_date_mp;
  inline xstring	Get_call_opt_first_date_mp() {
		return call_opt_first_date_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > call_price_defn_mp;
  inline xstring	Get_call_price_defn_mp() {
		return call_price_defn_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > call_price_pct;
  inline double	Get_call_price_pct() {
		return call_price_pct; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > category_id;
  inline xstring	Get_category_id() {
		return category_id; }
  inline void Set_category_id(const xstring &v) {
		category_id.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > category_id_mp;
  inline xstring	Get_category_id_mp() {
		return category_id_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > cost_basis_defn;
  inline xstring	Get_cost_basis_defn() {
		return cost_basis_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > data_validation_defn;
  inline xstring	Get_data_validation_defn() {
		return data_validation_defn; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > dur_wtd_sprd_adj_aig;
  inline double	Get_dur_wtd_sprd_adj_aig() {
		return dur_wtd_sprd_adj_aig; }
  inline void Set_dur_wtd_sprd_adj_aig(const double &v) {
		dur_wtd_sprd_adj_aig.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > fast_stat_calc_aig;
  inline xstring	Get_fast_stat_calc_aig() {
		return fast_stat_calc_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > gaap_acctng_defn;
  inline xstring	Get_gaap_acctng_defn() {
		return gaap_acctng_defn; }
  inline void Set_gaap_acctng_defn(const xstring &v) {
		gaap_acctng_defn.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > ia_prod_v3_rsd_2_aig;
  inline xstring	Get_ia_prod_v3_rsd_2_aig() {
		return ia_prod_v3_rsd_2_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_bk_val_mp;
  inline double	Get_init_bk_val_mp() {
		return init_bk_val_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_cost_basis_mp;
  inline double	Get_init_cost_basis_mp() {
		return init_cost_basis_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_mkt_val_mp;
  inline double	Get_init_mkt_val_mp() {
		return init_mkt_val_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_par_val_mp;
  inline double	Get_init_par_val_mp() {
		return init_par_val_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_pmt_rate_mp;
  inline double	Get_init_pmt_rate_mp() {
		return init_pmt_rate_mp; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > int_rate_diff;
  inline double	Get_int_rate_diff() {
		return int_rate_diff; }
  inline void Set_int_rate_diff(const double &v) {
		int_rate_diff.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > issue_date_mp;
  inline xstring	Get_issue_date_mp() {
		return issue_date_mp; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > maturity_date_mp;
  inline xstring	Get_maturity_date_mp() {
		return maturity_date_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > mkt_val_calc_freq;
  inline xstring	Get_mkt_val_calc_freq() {
		return mkt_val_calc_freq; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > mkt_val_calc_freq_yrs;
  inline int	Get_mkt_val_calc_freq_yrs() {
		return mkt_val_calc_freq_yrs; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > opt_int_diff_defn;
  inline xstring	Get_opt_int_diff_defn() {
		return opt_int_diff_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > par_val_at_issue_mp;
  inline double	Get_par_val_at_issue_mp() {
		return par_val_at_issue_mp; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > planned_sale_date_mp;
  inline xstring	Get_planned_sale_date_mp() {
		return planned_sale_date_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > pmt_mode_mp;
  inline xstring	Get_pmt_mode_mp() {
		return pmt_mode_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > port_defn_mp;
  inline xstring	Get_port_defn_mp() {
		return port_defn_mp; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > portfolio_sprd_adj_aig;
  inline double	Get_portfolio_sprd_adj_aig() {
		return portfolio_sprd_adj_aig; }
  inline void Set_portfolio_sprd_adj_aig(const double &v) {
		portfolio_sprd_adj_aig.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > purch_asset_id;
  inline xstring	Get_purch_asset_id() {
		return purch_asset_id; }
  inline void Set_purch_asset_id(const xstring &v) {
		purch_asset_id.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > purch_asset_sub_port;
  inline int	Get_purch_asset_sub_port() {
		return purch_asset_sub_port; }
  inline void Set_purch_asset_sub_port(const int &v) {
		purch_asset_sub_port.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > put_defn_mp;
  inline xstring	Get_put_defn_mp() {
		return put_defn_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > put_opt_exercise_pct;
  inline double	Get_put_opt_exercise_pct() {
		return put_opt_exercise_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > put_opt_first_date_mp;
  inline xstring	Get_put_opt_first_date_mp() {
		return put_opt_first_date_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > put_price_pct;
  inline double	Get_put_price_pct() {
		return put_price_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c1_pct_mp;
  inline double	Get_rbc_c1_pct_mp() {
		return rbc_c1_pct_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > refinancing_cost_pct;
  inline double	Get_refinancing_cost_pct() {
		return refinancing_cost_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > refinancing_rate_defn;
  inline xstring	Get_refinancing_rate_defn() {
		return refinancing_rate_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > refinancing_rate_scen_addn;
  inline double	Get_refinancing_rate_scen_addn() {
		return refinancing_rate_scen_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > refinancing_rate_scen_mult;
  inline double	Get_refinancing_rate_scen_mult() {
		return refinancing_rate_scen_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > refinancing_rate_scen_yr;
  inline double	Get_refinancing_rate_scen_yr() {
		return refinancing_rate_scen_yr; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > sale_class_mp;
  inline xstring	Get_sale_class_mp() {
		return sale_class_mp; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > seg_id_mp;
  inline xstring	Get_seg_id_mp() {
		return seg_id_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > sinking_fund_defn_mp;
  inline xstring	Get_sinking_fund_defn_mp() {
		return sinking_fund_defn_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > sinking_fund_prin_pmt_pct;
  inline double	Get_sinking_fund_prin_pmt_pct() {
		return sinking_fund_prin_pmt_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > taxable_pct_mp;
  inline double	Get_taxable_pct_mp() {
		return taxable_pct_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > use_mp;
  inline xstring	Get_use_mp() {
		return use_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > yld_maint_addn_mp;
  inline double	Get_yld_maint_addn_mp() {
		return yld_maint_addn_mp; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > accr_int_per_par_unit;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > amortzn_cost_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > asset_detail_rpt_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > asset_fund_index;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > call_first_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > call_par_first_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > call_prem_grading_mths;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > call_prem_related_to_coupon_rate;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > call_price_sch_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > commencement_period;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > coupon_rate_at_issue;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > data_file_name;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > data_grp_id;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > existing_asset_indicator;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gaap_inc_defn;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gaap_val_defn;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > maturity_mths_from_next_reset;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > maturity_period;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > mkt_val_per_unit_par;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > neg_asset_flag;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > net_yld_at_issue;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > net_yld_at_issue_flag;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > pct_to_use;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > planned_sale_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > pmt_freq;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > pmt_mths;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > pmt_rate_defn;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > pmt_rate_defn_string;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > pmt_reset_first_period;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > proj_date_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_date;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_yr;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > put_first_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > put_par_first_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > put_prem_grading_mths;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > put_prem_related_to_coupon_rate;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > put_price_sch_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > refinancing_rate_defn_calc;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > refinancing_rate_opt_sprd;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > sale_class_id;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > sch_array_size;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > sch_start_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > seg_num;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > start_period;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > tax_exempt_pct;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > use_eom_scen_rates;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > write_sch_file_flag;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > yrs_since_last_pmt;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(BOND_ASSET* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Asset Detail Log Rebase Reset
#line 1 "asset_detail_log_rebase_reset.bond_asset.for"
void asset_detail_log_rebase_reset(int t, const xstring &rebase_model, const xstring &caller, const xstring &identifier, const xstring &id_submodel_name);

// Asset Detail Report Present Value Output
#line 1 "asset_detail_rpt_pv_output.bond_asset.for"
void asset_detail_rpt_pv_output();

// Calculate Number of Model Points to Run
#line 1 "calc_num_records_to_run.bond_asset.for"
int calc_num_records_to_run(void);

// Category Refinancing Rate
#line 1 "category_refinancing_rate.bond_asset.for"
double category_refinancing_rate(int t, int local_months_to_maturity, double local_weighted_average_life, double local_option_spread, int return_rate_basis, int shift_defn);

// Create State Of World Schedule
#line 1 "create_state_of_world_schedule.bond_asset.for"
xstring create_state_of_world_schedule(xstring &sch_type, SmartArray <double> &sched_data);

// Months to Next Payment
#line 1 "mths_to_next_pmt.bond_asset.for"
int mths_to_next_pmt(int t);

// Months to Next Reset
#line 1 "mths_to_next_reset.bond_asset.for"
int mths_to_next_reset(int t);

// Option Spread Refinancing
#line 1 "opt_sprd_refinancing.bond_asset.for"
double opt_sprd_refinancing(int t);

// Read Schedule File
#line 1 "read_sch_file.bond_asset.for"
void read_sch_file(void);

// Rebase Bond Cash Flow
#line 1 "rebase_bond_cash_flow.bond_asset.for"
void rebase_bond_cash_flow(int t, int command, const xstring &caller, const xstring &model_name);

// Setup Existing Asset
#line 1 "setup_existing_asset.bond_asset.for"
void setup_existing_asset(void);

// Setup PSA Base Rate
#line 1 "setup_psa_base_rate.bond_asset.for"
void setup_psa_base_rate();

// Setup Purchase Investment Asset
#line 1 "setup_purch_inv_asset.bond_asset.for"
void setup_purch_inv_asset(int t, int save_assets, int panum, int new_mp_num, double purch_asset_amt, int &asset_mp_sequence_num);

// Setup Sinking Fund Schedule
#line 1 "setup_sinking_fund_sch.bond_asset.for"
void setup_sinking_fund_sch();

// Shrink Bond Clone
#line 1 "shrink_bond_clone.bond_asset.for"
void shrink_bond_clone(int mp);

// Solve for Coupon Rate
#line 1 "solve_for_coupon_rate.bond_asset.for"
double solve_for_coupon_rate(int t, double target_value);

// Validate Data
#line 1 "validate_data.bond_asset.for"
void validate_data(void);

// Write Schedule File
#line 1 "write_sch_file.bond_asset.for"
void write_sch_file(xstring sch_file);

// Write State of World Model Point
#line 1 "write_state_of_world_mp.bond_asset.for"
void write_state_of_world_mp(void);


//factory
static BOND_ASSET* makeThis(int isSubmodel, ModelClass *owner, BOND_ASSET* peer, 
					int mainRebase, const xstring &name, BOND_ASSET_persistent_object* arrayTemplate);

//constructor
BOND_ASSET(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
BOND_ASSET(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~BOND_ASSET();


void ms_BeforeStartup();
virtual void resetValues(int decrement = 1);
virtual void temporary_tables();
virtual void checkFileTables();

#ifdef COLUMNOUTPUT245
static bool writeClassInfo;
virtual void writeClassInfoIfRequired() const;
#endif

};


// write persistent object class - same as above but starting with a "_"
// to avoid error C2243 in Microsoft
class BOND_ASSET_persistent_object : public BOND_ASSET {


public :

	// this is a first time switch to read the array elements for iteration loop runs
	// on the second and subsequent iterations, the array won't be read, just reset
	bool mReadArray;
  bool isPersistentObject() const { return true; }

	int newTotalsNeeded() const {
		return sm_calling_model->newTotalsNeeded();
	}

	ModelType getModelType(){return mModelType;}
	void subTotalKey(HVector<xstring> &keys) const {
   sm_calling_model->subTotalKey(keys);
	}

	void findTargetColumns() {BOND_ASSET::findTargetColumns();}
	void createAllShare() {
		BOND_ASSET::createAllShare();
}

	void save_variables() {ModelClass::save_variables();}

	void addToMap(const xstring& key, const pointerData& d) {ModelClass::addToMap(key, d);}

	bool adopt(Node* newChild) { return ModelClass::adopt(newChild); }

	// In the next five functions, columnNumber is zero based
	int columnCount() const;
	const xstring& ms_columnName(const int columnNumber) const;
	double ms_columnValue(const int columnNumber, const int t);
	int ms_columnNumber(const xstring& columnName) const;
	double ms_columnValue(const xstring& columnName, const int t);
	double ms_valueAsDouble(const Attribute::Descriptor& descriptor);
	void reset();
	void write(long include_submodels = write_submodels);
	void rebaseModel(long period);
	void rebaseModelOnly(long period);
	void write(const xstring& key, long include_submodels = write_submodels);

	ModelClass *Save_main;
	BOND_CF_ASSET *&sm_bond_cf; //
	BOND_ASSET *&sm_bond_is; //
	BOND_ASSET *&sm_bond_pv; //
	BOND_ASSET *&sm_bond_ym; //
	BOND_ASSET *&sm_mtg_is; //
	BOND_ASSET *&sm_mtg_pv; //
	BOND_ASSET *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~BOND_ASSET_persistent_object();

	bool findProductFeatureList(xstring varValue);

	void makeProductFeatureList(xstring varValue);

	void addProductFeatureValue(int result, int count);
	void addProductFeatureValue(double result, int count);
	void addProductFeatureValue(xstring result, int count);
	void addProductFeatureValue(char result, int count);

	int* getProductFeatureIntPointer(int count);
	double* getProductFeatureDoublePointer(int count);
	xstring* getProductFeatureXstringPointer(int count);
	char getProductFeatureIgnore(int count);

	void resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount);

//factory
static BOND_ASSET_persistent_object* makeThis(int isSubmodel, ModelClass *owner, BOND_ASSET* peer, 
					int mainRebase, const xstring &name, BOND_ASSET_persistent_object* arrayTemplate, bool fixedArray);

//constructor
BOND_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
