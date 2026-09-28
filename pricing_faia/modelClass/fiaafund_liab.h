#ifndef __FIAAFUND_LIAB_H_
#define __FIAAFUND_LIAB_H_
#pragma warning ( disable : 4819 )

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
#include "ArrayProxy.h"			// ... contains Array Proxies
#include "ScalarProxy.h"			// ... contains Scalar Proxies
#include "ModelGroupProxy.h"
#include "NonAssocTableProxy.h"	// ... contains Rate_table and Table_from
#include "AssocTableProxies.h"		// ... contains AssocArray tables
#include "EnumValue.h"				// ... contains Enum Values


using namespace StrEnum;

#ifdef __CREATE_AA_COMP_COMP_CLASS_
class AA_COMP_COMP;
class AA_COMP_COMP_persistent_object;
#endif

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
typedef TMultiDComp<_1D_BOND_ASSET, BOND_ASSET_persistent_object> _2D_BOND_ASSET;
#endif

#ifdef __CREATE_BOND_CF_ASSET_CLASS_
class BOND_CF_ASSET;
class BOND_CF_ASSET_persistent_object;
typedef TComp<BOND_CF_ASSET, BOND_CF_ASSET_persistent_object> _1D_BOND_CF_ASSET;
typedef TMultiDComp<_1D_BOND_CF_ASSET, BOND_CF_ASSET_persistent_object> _2D_BOND_CF_ASSET;
#endif

#ifdef __CREATE_EIO_ASSET_CLASS_
class EIO_ASSET;
class EIO_ASSET_persistent_object;
typedef TComp<EIO_ASSET, EIO_ASSET_persistent_object> _1D_EIO_ASSET;
typedef TMultiDComp<_1D_EIO_ASSET, EIO_ASSET_persistent_object> _2D_EIO_ASSET;
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
typedef TMultiDComp<_1D_FIACARVM_LIAB, FIACARVM_LIAB_persistent_object> _2D_FIACARVM_LIAB;
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

#ifdef __CREATE_INVSTRAT_ASSET_CLASS_
class INVSTRAT_ASSET;
class INVSTRAT_ASSET_persistent_object;
typedef TComp<INVSTRAT_ASSET, INVSTRAT_ASSET_persistent_object> _1D_INVSTRAT_ASSET;
#endif

#ifdef __CREATE_LIAB_LIAB_CLASS_
class LIAB_LIAB;
class LIAB_LIAB_persistent_object;
#endif

#ifdef __CREATE_MRB_GAAP_CLASS_
class MRB_GAAP;
class MRB_GAAP_persistent_object;
typedef TComp<MRB_GAAP, MRB_GAAP_persistent_object> _1D_MRB_GAAP;
#endif

#ifdef __CREATE_MTG_ASSET_CLASS_
class MTG_ASSET;
class MTG_ASSET_persistent_object;
typedef TComp<MTG_ASSET, MTG_ASSET_persistent_object> _1D_MTG_ASSET;
typedef TMultiDComp<_1D_MTG_ASSET, MTG_ASSET_persistent_object> _2D_MTG_ASSET;
#endif

#ifdef __CREATE_MTG_CF_ASSET_CLASS_
class MTG_CF_ASSET;
class MTG_CF_ASSET_persistent_object;
typedef TComp<MTG_CF_ASSET, MTG_CF_ASSET_persistent_object> _1D_MTG_CF_ASSET;
typedef TMultiDComp<_1D_MTG_CF_ASSET, MTG_CF_ASSET_persistent_object> _2D_MTG_CF_ASSET;
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

#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
class SFAS97RD_GAAP;
class SFAS97RD_GAAP_persistent_object;
typedef TComp<SFAS97RD_GAAP, SFAS97RD_GAAP_persistent_object> _1D_SFAS97RD_GAAP;
typedef TMultiDComp<_1D_SFAS97RD_GAAP, SFAS97RD_GAAP_persistent_object> _2D_SFAS97RD_GAAP;
#endif



namespace FIAAFUND_LIAB_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class FIAAFUND_LIAB_persistent_object;
class FIAAFUND_LIAB : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(FIAAFUND_LIAB); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;

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


	void init_(){
		

// dynamic Lever variables
lookback_yrs = 0;
div_yld_scen_mult = 1.0;
div_yld_sprd = 0.0;
index_scen_mult = 1.0;
index_scen_sprd_addn = 0.0;
payout_index_max = 999.99;

		bIsInit = true;
	}
	void deInit_(){

	}

#ifdef __CREATE_ADCO_ASSET_CLASS_
	ADCO_ASSET	*company_asset_adco;
	ADCO_ASSET	*&adco;
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
	ASSET_ASSET	*company_asset;
	ASSET_ASSET	*&asset;
#endif
#ifdef __CREATE_A_SUBPORT_ASSET_CLASS_
	A_SUBPORT_ASSET	*company_asset_asset_sub_port;
	A_SUBPORT_ASSET	*&asset_sub_port;
#endif
#ifdef __CREATE_BOND_ASSET_CLASS_
	BOND_ASSET	*company_asset_bond;
	BOND_ASSET	*&bond;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
	BOND_CF_ASSET	*company_asset_bond_bond_cf;
	BOND_CF_ASSET	*&bond_cf;
#endif
#ifdef __CREATE_AA_COMP_COMP_CLASS_
	AA_COMP_COMP	*company;
#endif
#ifdef __CREATE_EIO_ASSET_CLASS_
	EIO_ASSET	*company_asset_eio;
	EIO_ASSET	*&eio;
#endif
#ifdef __CREATE_EPA_ASSET_CLASS_
	EPA_ASSET	*company_asset_epa;
	EPA_ASSET	*&epa;
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
	FIA_LIAB	*company_liab_fia;
	FIA_LIAB	*&fia;
#endif
#ifdef __CREATE_FIAAFUND_LIAB_CLASS_
	FIAAFUND_LIAB	*company_liab_fia_fia_account;
	FIAAFUND_LIAB	*&fia_account;
#endif
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
	FIACARVM_LIAB	*company_liab_fia_carvm_stat;
	FIACARVM_LIAB	*&fia_carvm_stat;
#endif
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
	FIACARVM_LIAB	*company_liab_fia_carvm_tax;
	FIACARVM_LIAB	*&fia_carvm_tax;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
	RATES_ECONOMY	*company_liab_fia_fia_rates;
	RATES_ECONOMY	*&fia_rates;
#endif
#ifdef __CREATE_LIAB_LIAB_CLASS_
	LIAB_LIAB	*company_liab;
	LIAB_LIAB	*&liab;
#endif
#ifdef __CREATE_MTG_ASSET_CLASS_
	MTG_ASSET	*company_asset_mtg;
	MTG_ASSET	*&mtg;
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
 // Column Definition Begins
 	ColumnAccessor < mCFStaticData_0 > admin_fee;
 	ColumnAccessor < mCFStaticData_0 > credited_int;
 	ColumnAccessor < mCFStaticData_0 > crediting_cap_rate;
 	ColumnAccessor < mCFStaticData_0 > crediting_part_rate;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate_cumul_crbg;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate_fix;
 	ColumnAccessor < mCFStaticData_0 > crediting_sprd_rate_crbg;
 	ColumnAccessor < mCFStaticData_0 > crediting_trigger_rate_crbg;
 	ColumnAccessor < mCFStaticData_0 > enhanced_part_rate_crbg;
 	ColumnAccessor < mCFStaticData_0 > eprs_sfc_ben_crbg;
 	ColumnAccessor < mCFStaticData_0 > eprs_sfc_ben_gross_crbg;
 	ColumnAccessor < mCFStaticData_0 > eprs_strat_fee_crbg;
 	ColumnAccessor < mCFStaticData_0 > eprs_strat_fee_partial_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > eprs_strat_fee_partial_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > fa_crediting_rate_crbg;
 	ColumnAccessor < mCFStaticData_0 > fa_pricing_rate_crbg;
 	ColumnAccessor < mCFStaticData_0 > fa_reference_rate_crbg;
 	ColumnAccessor < mCFStaticData_0 > fund_released_ann;
 	ColumnAccessor < mCFStaticData_0 > fund_released_dth;
 	ColumnAccessor < mCFStaticData_0 > fund_released_maturity;
 	ColumnAccessor < mCFStaticData_0 > fund_released_surr;
 	ColumnAccessor < mCFStaticData_0 > fund_released_withdrl;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b_bef;
 	ColumnAccessor < mCFStaticData_0 > fund_val_beg_term_crbg;
 	ColumnAccessor < mCFStaticData_0 > fund_val_beg_term_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > fund_val_decrem;
 	ColumnAccessor < mCFStaticData_0 > fund_val_e;
 	ColumnAccessor < mCFStaticData_0 > fund_val_e_bef;
 	ColumnAccessor < mCFStaticData_0 > fund_val_rebal;
 	ColumnAccessor < mCFStaticData_0 > gmab_av_b_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmab_av_e_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmab_av_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmab_chg_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmab_chg_partial_e_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmab_chg_partial_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmab_global_payoff_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmab_payoff_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg_partial_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg_partial_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > hedge_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > hedge_inv_amt_bom;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val_growth;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val_per_unit_notional;
 	ColumnAccessor < mCFStaticData_0 > hedge_sale_amt_bom;
 	ColumnAccessor < mCFStaticData_0 > hedge_sale_amt_eom;
 	ColumnAccessor < mCFStaticData_0 > index_term_elapsed_pct_crbg;
 	ColumnAccessor < mCFStaticData_0 > index_term_return_crbg;
 	ColumnAccessor < mCFStaticData_0 > index_val;
 	ColumnAccessor < mCFStaticData_0 > index_val_beg_term_crbg;
 	ColumnAccessor < mCFStaticData_0 > index_val_bom;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > lapse_dyn_crediting_rt_crbg;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_required;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_required_bef;
 	ColumnAccessor < mCFStaticData_0 > notional_to_hedge;
 	ColumnAccessor < mCFStaticData_0 > notional_to_hedge_cap;
 	ColumnAccessor < mCFStaticData_0 > notional_to_hedge_index;
 	ColumnAccessor < mCFStaticData_0 > notional_to_hedge_long_strike;
 	ColumnAccessor < mCFStaticData_0 > notional_to_hedge_net;
 	ColumnAccessor < mCFStaticData_0 > opt_budget;
 	ColumnAccessor < mCFStaticData_0 > opt_budget_amt;
 	ColumnAccessor < mCFStaticData_0 > opt_budget_eprs_crbg;
 	ColumnAccessor < mCFStaticData_0 > opt_cost_atm_crbg;
 	ColumnAccessor < mCFStaticData_0 > opt_cost_beg_term_crbg;
 	ColumnAccessor < mCFStaticData_0 > opt_cost_bs_bom_crbg;
 	ColumnAccessor < mCFStaticData_0 > opt_cost_bs_eom_crbg;
 	ColumnAccessor < mCFStaticData_0 > opt_cost_by_grid_bom_crbg;
 	ColumnAccessor < mCFStaticData_0 > opt_payoff;
 	ColumnAccessor < mCFStaticData_0 > opt_strike_price;
 	ColumnAccessor < mCFStaticData_0 > opt_value_net_numer;
 	ColumnAccessor < mCFStaticData_0 > pfwd_surr_fund_val;
 	ColumnAccessor < mCFStaticData_0 > prem_alloc;
 	ColumnAccessor < mCFStaticData_0 > prem_bonus;
 	ColumnAccessor < mCFStaticData_0 > prorated_strategy_return_crbg;
 	ColumnAccessor < mCFStaticData_0 > startup;
 	ColumnAccessor < mCFStaticData_0 > strategy_return_crbg;
//Column Definition END@2

 // Temporary Table...
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
	#define DESCRIPTOR_TABLE FIAAFUND_LIAB::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_cap_max;
  inline double	Get_crediting_cap_max() {
		return crediting_cap_max; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_cap_min;
  inline double	Get_crediting_cap_min() {
		return crediting_cap_min; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > crediting_dyn_lever;
  inline xstring	Get_crediting_dyn_lever() {
		return crediting_dyn_lever; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > crediting_eqt_index;
  inline xstring	Get_crediting_eqt_index() {
		return crediting_eqt_index; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_floor;
  inline double	Get_crediting_floor() {
		return crediting_floor; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_floor_init;
  inline double	Get_crediting_floor_init() {
		return crediting_floor_init; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > crediting_mths;
  inline int	Get_crediting_mths() {
		return crediting_mths; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_part_eprs_max;
  inline double	Get_crediting_part_eprs_max() {
		return crediting_part_eprs_max; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_part_eprs_min;
  inline double	Get_crediting_part_eprs_min() {
		return crediting_part_eprs_min; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_part_max;
  inline double	Get_crediting_part_max() {
		return crediting_part_max; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_part_min;
  inline double	Get_crediting_part_min() {
		return crediting_part_min; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > crediting_rate_defn;
  inline xstring	Get_crediting_rate_defn() {
		return crediting_rate_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > crediting_rate_guar_mths;
  inline int	Get_crediting_rate_guar_mths() {
		return crediting_rate_guar_mths; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_sprd_max;
  inline double	Get_crediting_sprd_max() {
		return crediting_sprd_max; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_sprd_min;
  inline double	Get_crediting_sprd_min() {
		return crediting_sprd_min; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_trigger_max;
  inline double	Get_crediting_trigger_max() {
		return crediting_trigger_max; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_trigger_min;
  inline double	Get_crediting_trigger_min() {
		return crediting_trigger_min; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > display_solver_warnings_defn;
  inline xstring	Get_display_solver_warnings_defn() {
		return display_solver_warnings_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eprs_add_par_threshold;
  inline double	Get_eprs_add_par_threshold() {
		return eprs_add_par_threshold; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eprs_add_part_min;
  inline double	Get_eprs_add_part_min() {
		return eprs_add_part_min; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eprs_rounding_mult;
  inline double	Get_eprs_rounding_mult() {
		return eprs_rounding_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eprs_strat_fee_pct_crbg;
  inline double	Get_eprs_strat_fee_pct_crbg() {
		return eprs_strat_fee_pct_crbg; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > fund_id;
  inline xstring	Get_fund_id() {
		return fund_id; }
  inline void Set_fund_id(const xstring &v) {
		fund_id.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > fund_type;
  inline xstring	Get_fund_type() {
		return fund_type; }
  inline void Set_fund_type(const xstring &v) {
		fund_type.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > fund_val_split_prop;
  inline double	Get_fund_val_split_prop() {
		return fund_val_split_prop; }
  inline void Set_fund_val_split_prop(const double &v) {
		fund_val_split_prop.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gwl_ceding_exp_allow_level_crbg;
  inline double	Get_gwl_ceding_exp_allow_level_crbg() {
		return gwl_ceding_exp_allow_level_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_defn;
  inline xstring	Get_hedge_defn() {
		return hedge_defn; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > hedge_grp_code;
  inline xstring	Get_hedge_grp_code() {
		return hedge_grp_code; }
  inline void Set_hedge_grp_code(const xstring &v) {
		hedge_grp_code.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > init_fia_cap;
  inline double	Get_init_fia_cap() {
		return init_fia_cap; }
  inline void Set_init_fia_cap(const double &v) {
		init_fia_cap.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > init_fund_val;
  inline double	Get_init_fund_val() {
		return init_fund_val; }
  inline void Set_init_fund_val(const double &v) {
		init_fund_val.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > init_part_rate;
  inline double	Get_init_part_rate() {
		return init_part_rate; }
  inline void Set_init_part_rate(const double &v) {
		init_part_rate.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > init_sprd_rate;
  inline double	Get_init_sprd_rate() {
		return init_sprd_rate; }
  inline void Set_init_sprd_rate(const double &v) {
		init_sprd_rate.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > init_trigger_rate;
  inline double	Get_init_trigger_rate() {
		return init_trigger_rate; }
  inline void Set_init_trigger_rate(const double &v) {
		init_trigger_rate.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > lookback_defn;
  inline xstring	Get_lookback_defn() {
		return lookback_defn; }
  inline void Set_lookback_defn(const xstring &v) {
		lookback_defn.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lookback_sampling_interval;
  inline xstring	Get_lookback_sampling_interval() {
		return lookback_sampling_interval; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pct_to_hedge;
  inline double	Get_pct_to_hedge() {
		return pct_to_hedge; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rate_chg_threshold_crbg;
  inline double	Get_rate_chg_threshold_crbg() {
		return rate_chg_threshold_crbg; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > commencement_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > elapsed_mths;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > lookback_mths;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > lookback_sampling_mths;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > maturity_period;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > nb_opt_budget_calc_crbg;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(FIAAFUND_LIAB* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Get Bs Opt Strike Crbg
#line 1 "get_bs_opt_strike_crbg.fiaafund_liab.for"
double get_bs_opt_strike_crbg(double rf_rate, double vol_param, double dividend_yld, double cost, int opt_mths);

// Get Option Price Crbg
#line 1 "get_option_price_crbg.fiaafund_liab.for"
double get_option_price_crbg(
	int projection_month, double strike, StrEnum::EnumValue opt_defn, int index_term_mth);

// Get Option Strike Crbg
#line 1 "get_option_strike_crbg.fiaafund_liab.for"
double get_option_strike_crbg(
	int projection_month, double cost, StrEnum::EnumValue opt_defn, int index_term_mth);

// Get Strike List Crbg
#line 1 "get_strike_list_crbg.fiaafund_liab.for"
void get_strike_list_crbg(vector<int>& strike_list);

// Equity Index Rolling Average of Past x Months
#line 1 "index_val_avg_calc.fiaafund_liab.for"
double index_val_avg_calc(int time, int month);

// Index Value Calculation
#line 1 "index_val_calc.fiaafund_liab.for"
double index_val_calc(int t);

// Inv Cumul Normal Crbg
#line 1 "inv_cumul_normal_crbg.fiaafund_liab.for"
double inv_cumul_normal_crbg(double p);

// Market Value Calculation
#line 1 "mkt_val_calc.fiaafund_liab.for"
double mkt_val_calc(int t, int cal_yr, int cal_mth, int lookback_defn, int lookback_mths, int lookback_sampling_mths, double index_units_owned, double index_val, double index_scen_mult, double index_scen_sprd_addn, double term_to_expiry, double div_yld_scen_mult, double div_yld_sprd, double opt_strike_price, double payout_index_max, double mthly_cap_rate, StrEnum::EnumValue opt_defn, double extra_spot_spread, double extra_vol_spread, int shift_defn);

// Opt Budget Renewal Calc Crbg
#line 1 "opt_budget_renew_calc_crbg.fiaafund_liab.for"
double opt_budget_renew_calc_crbg(int t, double init_opt_cost, double opt_budget_tgt, double ner_init, double ner_cv);

// Opt Budget Tgt Calc Crbg
#line 1 "opt_budget_tgt_calc_crbg.fiaafund_liab.for"
double opt_budget_tgt_calc_crbg(double init_opt_cost, double index_term, double tgt_alpha);

// Part Rate Solver Crbg
#line 1 "part_rate_solver_crbg.fiaafund_liab.for"
double part_rate_solver_crbg(int t, double option_budget, double guess_low_bound, double guess_high_bound);

// Strike
#line 1 "strike.fiaafund_liab.for"
double strike(int t, int reserve_period, int mths_in_first_period);

// Strike cap
#line 1 "strike_cap.fiaafund_liab.for"
double strike_cap(int t, int reserve_period, int mths_in_first_period);

// Underlying Price
#line 1 "underlying_price.fiaafund_liab.for"
double underlying_price(int t, int reserve_period);


//factory
static FIAAFUND_LIAB* makeThis(int isSubmodel, ModelClass *owner, FIAAFUND_LIAB* peer, 
					int mainRebase, const xstring &name, FIAAFUND_LIAB_persistent_object* arrayTemplate);

//constructor
FIAAFUND_LIAB(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
FIAAFUND_LIAB(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~FIAAFUND_LIAB();


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
class FIAAFUND_LIAB_persistent_object : public FIAAFUND_LIAB {


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

	void findTargetColumns() {FIAAFUND_LIAB::findTargetColumns();}
	void createAllShare() {
		FIAAFUND_LIAB::createAllShare();
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

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~FIAAFUND_LIAB_persistent_object();

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
static FIAAFUND_LIAB_persistent_object* makeThis(int isSubmodel, ModelClass *owner, FIAAFUND_LIAB* peer, 
					int mainRebase, const xstring &name, FIAAFUND_LIAB_persistent_object* arrayTemplate, bool fixedArray);

//constructor
FIAAFUND_LIAB_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
