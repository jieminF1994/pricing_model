#ifndef __EIO_ASSET_H_
#define __EIO_ASSET_H_
#pragma warning ( disable : 4819 )

struct eioInitialValuesData
	{
	double spot_sprd_adj;
	double volatility_sprd_adj;
	double yld_numer;
	double mkt_val_bef_sale;
	};
typedef map <xstring, struct eioInitialValuesData*, less<xstring> > eioivmap;

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



namespace EIO_ASSET_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class EIO_ASSET_persistent_object;
class EIO_ASSET : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(EIO_ASSET); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;
	static void Terminator();
	static FunctionPtr RegisterTerminatorOnce;
	
int sequence_id;
struct eioInitialValuesData* initial_values;
int calculated_t_low;
int calculated_t_high;
SmartArray <double> lookback_index_value_data;
bool purchased_bom_flag;
double purch_amt;
int purch_asset_mp_num;

// Model point variables
xstring seg_id;
xstring hdg_grp_code;
xstring asset_index;
StrEnum::EnumValue port_defn;
StrEnum::EnumValue sale_class;
xstring maturity_date;
xstring planned_sale_date;
double init_cost_basis;
double init_bk_val;
double init_mkt_val;
double init_index_units_owned;
double init_index_val;
double opt_strike_price;
double index_val_at_issue;
double payout_index_max;
StrEnum::EnumValue opt_defn;
double index_scen_mult;
double index_scen_addn;
double div_yld_scen_mult;
double div_yld_addn;
StrEnum::EnumValue lookback_defn;
StrEnum::EnumValue lookback_sampling_interval;
double lookback_yrs;
double avr_contribn_pct;
double avr_max_pct;
double avr_obj_pct;
double rbc_c1_pct;

	void init_(){
		

sequence_id = 0;
initial_values = NULL;
purchased_bom_flag = false;
purch_amt = 0.0;
purch_asset_mp_num = -1;

// Initialize model point variables
seg_id = "Seg";
hdg_grp_code = "DEFAULT";
asset_index = "Equity";
port_defn = INVESTMENT;
sale_class = AVAILABLE_FOR_SALE; 
maturity_date = "1900/01/01";
planned_sale_date = "9999/01/01"; 
init_cost_basis = 0.0;
init_bk_val = 0.0;
init_mkt_val = 0.0;
init_index_units_owned = 0.0;
init_index_val = 0.0;
opt_strike_price = 0.0;
index_val_at_issue = 0.0;
payout_index_max = 0.0;
opt_defn = CALL;
index_scen_mult = 1.0;
index_scen_addn = 0.0;
div_yld_scen_mult = 1.0;
div_yld_addn = 0.0;
lookback_defn = NONE;
lookback_sampling_interval = ANNUAL;
lookback_yrs = 0.0;
avr_contribn_pct = 0.0;
avr_max_pct = 0.0;
avr_obj_pct = 0.0;
rbc_c1_pct = 0.0;

		bIsInit = true;
	}
	void deInit_(){

	}

#ifdef __CREATE_ASSET_ASSET_CLASS_
	ASSET_ASSET	*company_asset;
	ASSET_ASSET	*&asset;
#endif
#ifdef __CREATE_COMP_COMP_CLASS_
	COMP_COMP	*company;
#endif
#ifdef __CREATE_EIO_ASSET_CLASS_
	EIO_ASSET	*company_asset_eio;
	EIO_ASSET	*&eio;
#endif
#ifdef __CREATE_EPL_LIAB_CLASS_
	EPL_LIAB	*company_liab_epl;
	EPL_LIAB	*&epl;
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
	MTG_CF_ASSET	*company_asset_mtg_mtg_cf_mtg_ym;
	MTG_CF_ASSET	*&mtg_ym;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
	RATES_ECONOMY	*company_rates;
	RATES_ECONOMY	*&rates;
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
	SEG_COMP	*company_seg;
	SEG_COMP	*&seg;
#endif
 // Column Definition Begins
 	ColumnAccessor < mCFStaticData_0 > accr_inc;
 	ColumnAccessor < mCFStaticData_0 > asset_detail_pv_flag;
 	ColumnAccessor < mCFStaticData_0 > asset_min_size_sale_flag;
 	ColumnAccessor < mCFStaticData_0 > avr_basic_contribn;
 	ColumnAccessor < mCFStaticData_0 > avr_basic_contribn_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_max;
 	ColumnAccessor < mCFStaticData_0 > avr_max_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_obj;
 	ColumnAccessor < mCFStaticData_0 > avr_obj_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_realzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > avr_realzd_cap_gain_from_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_unrealzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > avr_unrealzd_cap_gain_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_unrealzd_cap_gain_released_on_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val;
 	ColumnAccessor < mCFStaticData_0 > bk_val_bef_fund_match_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val_plus_accr_int;
 	ColumnAccessor < mCFStaticData_0 > bk_val_plus_accr_int_bef_neg_cash_flow_sale;
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
 	ColumnAccessor < mCFStaticData_0 > cost_basis_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_incr_appreciation;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_purch;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_sold;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > dur_val;
 	ColumnAccessor < mCFStaticData_0 > finalize;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_bk_val;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_unrealzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > gaap_surp_bk_val;
 	ColumnAccessor < mCFStaticData_0 > gaap_unrealzd_cap_gain_incr;
 	ColumnAccessor < mCFStaticData_0 > index_units_owned;
 	ColumnAccessor < mCFStaticData_0 > index_units_owned_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > index_val;
 	ColumnAccessor < mCFStaticData_0 > index_val_at_expiry_anniv;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > lookback_index_val;
 	ColumnAccessor < mCFStaticData_0 > mkt_to_bk_ratio;
 	ColumnAccessor < mCFStaticData_0 > mkt_val;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_bef_fund_match_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_purch;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_sold;
 	ColumnAccessor < mCFStaticData_0 > mths_to_next_mkt_val_calc;
 	ColumnAccessor < mCFStaticData_0 > notional_amt;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_bef_fund_match_sale;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_purch;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_sold;
 	ColumnAccessor < mCFStaticData_0 > opt_pmt;
 	ColumnAccessor < mCFStaticData_0 > opt_val_asset_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_asset_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_asset_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_asset_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_baseline;
 	ColumnAccessor < mCFStaticData_0 > opt_val_baseline_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_10_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_10_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_10_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_10_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_1_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_1_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_1_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_1_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_2_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_2_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_2_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_2_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_3_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_3_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_3_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_3_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_4_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_4_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_4_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_4_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_5_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_5_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_5_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_5_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_6_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_6_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_6_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_6_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_7_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_7_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_7_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_7_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_8_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_8_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_8_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_8_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_9_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_9_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_9_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_key_rate_9_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_int_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_term_1_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_term_1_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_term_1_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_term_1_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_term_2_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_term_2_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_term_2_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_term_2_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_term_3_down_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_term_3_down_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_term_3_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_term_3_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_up_1;
 	ColumnAccessor < mCFStaticData_0 > opt_val_vol_up_1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > rbc_c1;
 	ColumnAccessor < mCFStaticData_0 > rbc_c1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain_opt_pmt;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain_sale;
 	ColumnAccessor < mCFStaticData_0 > sold_pct;
 	ColumnAccessor < mCFStaticData_0 > sold_pct_fund_match;
 	ColumnAccessor < mCFStaticData_0 > sold_pct_neg_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > sold_pct_planned;
 	ColumnAccessor < mCFStaticData_0 > sold_pct_rebal;
 	ColumnAccessor < mCFStaticData_0 > spot_sprd_adj;
 	ColumnAccessor < mCFStaticData_0 > startup;
 	ColumnAccessor < mCFStaticData_0 > sub_port_id;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_bef_fund_match_sale;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_gaap_surp;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_incr;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_released_on_sale;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_to_bk_ratio;
 	ColumnAccessor < mCFStaticData_0 > volatility_sprd_adj;
 	ColumnAccessor < mCFStaticData_0 > yld_denom;
 	ColumnAccessor < mCFStaticData_0 > yld_numer;
//Column Definition END@2

 // Temporary Table...
EIO_ASSET *sm_bond_is;
EIO_ASSET *sm_bond_pv;
EIO_ASSET *sm_bond_ym;
EIO_ASSET *sm_mtg_is;
EIO_ASSET *sm_mtg_pv;
EIO_ASSET *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE EIO_ASSET::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
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
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_index_mp;
  inline xstring	Get_asset_index_mp() {
		return asset_index_mp; }
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > div_yld_addn_mp;
  inline double	Get_div_yld_addn_mp() {
		return div_yld_addn_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > div_yld_scen_mult_mp;
  inline double	Get_div_yld_scen_mult_mp() {
		return div_yld_scen_mult_mp; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > hdg_grp_code_mp;
  inline xstring	Get_hdg_grp_code_mp() {
		return hdg_grp_code_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_scen_addn_mp;
  inline double	Get_index_scen_addn_mp() {
		return index_scen_addn_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_scen_mult_mp;
  inline double	Get_index_scen_mult_mp() {
		return index_scen_mult_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_val_at_issue_mp;
  inline double	Get_index_val_at_issue_mp() {
		return index_val_at_issue_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_bk_val_mp;
  inline double	Get_init_bk_val_mp() {
		return init_bk_val_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_cost_basis_mp;
  inline double	Get_init_cost_basis_mp() {
		return init_cost_basis_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_index_units_owned_mp;
  inline double	Get_init_index_units_owned_mp() {
		return init_index_units_owned_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_index_val_mp;
  inline double	Get_init_index_val_mp() {
		return init_index_val_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_mkt_val_mp;
  inline double	Get_init_mkt_val_mp() {
		return init_mkt_val_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lookback_defn_mp;
  inline xstring	Get_lookback_defn_mp() {
		return lookback_defn_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lookback_sampling_interval_mp;
  inline xstring	Get_lookback_sampling_interval_mp() {
		return lookback_sampling_interval_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lookback_yrs_mp;
  inline double	Get_lookback_yrs_mp() {
		return lookback_yrs_mp; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > maturity_date_mp;
  inline xstring	Get_maturity_date_mp() {
		return maturity_date_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > mkt_val_calc_freq;
  inline xstring	Get_mkt_val_calc_freq() {
		return mkt_val_calc_freq; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > mkt_val_calc_freq_yrs;
  inline int	Get_mkt_val_calc_freq_yrs() {
		return mkt_val_calc_freq_yrs; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > opt_defn_mp;
  inline xstring	Get_opt_defn_mp() {
		return opt_defn_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > opt_strike_price_mp;
  inline double	Get_opt_strike_price_mp() {
		return opt_strike_price_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > payout_index_max_mp;
  inline double	Get_payout_index_max_mp() {
		return payout_index_max_mp; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > planned_sale_date_mp;
  inline xstring	Get_planned_sale_date_mp() {
		return planned_sale_date_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > port_defn_mp;
  inline xstring	Get_port_defn_mp() {
		return port_defn_mp; }
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c1_pct_mp;
  inline double	Get_rbc_c1_pct_mp() {
		return rbc_c1_pct_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > sale_class_mp;
  inline xstring	Get_sale_class_mp() {
		return sale_class_mp; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > seg_id_mp;
  inline xstring	Get_seg_id_mp() {
		return seg_id_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > use_mp;
  inline xstring	Get_use_mp() {
		return use_mp; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > asset_detail_rpt_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > asset_fund_index;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > bk_val_bef_expiry;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > commencement_period;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > cost_basis_bef_expiry;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > data_grp_id;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > existing_asset_indicator;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gaap_inc_defn;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gaap_val_defn;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > init_mkt_val_calc;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > lookback_mths;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > lookback_sampling_mths;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > maturity_period;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > mkt_val_at_issue;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > mkt_val_bef_expiry;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > neg_asset_flag;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > notional_amt_at_issue;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > pct_to_use;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > planned_sale_period;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > proj_date_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_date;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_yr;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > sale_class_id;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > seg_num;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > start_period;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(EIO_ASSET* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Detail Present Value Output
#line 1 "asset_detail_pv_output.eio_asset.for"
void asset_detail_pv_output();

// Calculate Number of Model Points to Run
#line 1 "calc_num_records_to_run.eio_asset.for"
int calc_num_records_to_run(void);

// Index Value Calculation
#line 1 "index_val_calc.eio_asset.for"
double index_val_calc(int t);

// Market Value Calculation
#line 1 "mkt_val_calc.eio_asset.for"
double mkt_val_calc(int t, int cal_yr, int cal_mth, int lookback_defn, int lookback_mths, int lookback_sampling_mths, double index_units_owned, double index_val, double index_scen_mult, double index_scen_addn, double term_to_expiry, double div_yld_scen_mult, double div_yld_addn, double opt_strike_price, double payout_index_max, StrEnum::EnumValue opt_defn, double extra_spot_spread, double extra_vol_spread, int index_val_shift_defn, int index_vol_shift_defn, int int_rate_shift_defn);

// Setup Existing Asset
#line 1 "setup_existing_asset.eio_asset.for"
void setup_existing_asset(void);

// Setup Purchase Hedge Asset
#line 1 "setup_purch_hedge_asset.eio_asset.for"
void setup_purch_hedge_asset(int t, int save_assets, int panum, int new_mp_num, int inv_purchase_sub_port, const xstring &hedge_group_code, double purch_asset_amt, int &asset_mp_sequence_num, double long_strike, double short_strike);

// Setup Purchase Investment Asset
#line 1 "setup_purch_inv_asset.eio_asset.for"
void setup_purch_inv_asset(int t, int save_assets, int panum, int new_mp_num, int inv_purchase_sub_port, double purch_asset_amt, int &asset_mp_sequence_num);

// Validate Data
#line 1 "validate_data.eio_asset.for"
void validate_data(void);

// Write State of World Model Point
#line 1 "write_state_of_world_mp.eio_asset.for"
void write_state_of_world_mp(void);


//factory
static EIO_ASSET* makeThis(int isSubmodel, ModelClass *owner, EIO_ASSET* peer, 
					int mainRebase, const xstring &name, EIO_ASSET_persistent_object* arrayTemplate);

//constructor
EIO_ASSET(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
EIO_ASSET(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~EIO_ASSET();


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
class EIO_ASSET_persistent_object : public EIO_ASSET {


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

	void findTargetColumns() {EIO_ASSET::findTargetColumns();}
	void createAllShare() {
		EIO_ASSET::createAllShare();
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
	EIO_ASSET *&sm_bond_is; //
	EIO_ASSET *&sm_bond_pv; //
	EIO_ASSET *&sm_bond_ym; //
	EIO_ASSET *&sm_mtg_is; //
	EIO_ASSET *&sm_mtg_pv; //
	EIO_ASSET *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~EIO_ASSET_persistent_object();

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
static EIO_ASSET_persistent_object* makeThis(int isSubmodel, ModelClass *owner, EIO_ASSET* peer, 
					int mainRebase, const xstring &name, EIO_ASSET_persistent_object* arrayTemplate, bool fixedArray);

//constructor
EIO_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
