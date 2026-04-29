#ifndef __FIAAFUND_LIAB_H_
#define __FIAAFUND_LIAB_H_
#pragma warning ( disable : 4819 )

#include <regex> //DTL: 20180627
//#include "rates_economy.h" // 20191104 MTC //WTW - Gen2 - Move AIG structures to Externs

// 20181217 MTC - Refactored cubic spline
#ifndef CUBIC_SPLINE_AIG//WTW - Gen2
struct cubic_spline_params_aig
{
	cubic_spline_params_aig(): initialized(false),
						       n(0),
							   h(vector<double>()),
							   alpha(vector<double>()),
							   l(vector<double>()),
							   mu(vector<double>()),
							   z(vector<double>()),
							   c(vector<double>()),
							   b(vector<double>()),
							   d(vector<double>()) {}
	bool initialized;
	int n;
	vector<double> h;
	vector<double> alpha;
	vector<double> l;
	vector<double> mu;
	vector<double> z;
	vector<double> c;
	vector<double> b;
	vector<double> d;
};

const cubic_spline_params_aig default_cubic_spline_params_aig = cubic_spline_params_aig();
// 20181217 MTC END
#define CUBIC_SPLINE_AIG//WTW - Gen2
#endif//WTW - Gen2


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

bool pricing_spread_migration_is_underway_aig;		//DTL: 20180914
int pricing_spread_migration_start_duration_aig;	//DTL: 20180914
int strategy_return_switch_start_duration_aig;      // 20180930 MTC


	void init_(){
		

// dynamic Lever variables
lookback_yrs = 0;
div_yld_scen_mult = 1.0;
div_yld_sprd = 0.0;
index_scen_mult = 1.0;
index_scen_sprd_addn = 0.0;
payout_index_max = 999.99;

pricing_spread_migration_is_underway_aig = false;		//DTL: 20180914
pricing_spread_migration_start_duration_aig = 9999;		//DTL: 20180914
strategy_return_switch_start_duration_aig = t_high;     // 20180930 MTC

		bIsInit = true;
	}
	void deInit_(){

	}

#ifdef __CREATE_ADCO_ASSET_CLASS_
	ADCO_ASSET	*company_asset_adco;
	ADCO_ASSET	*&adco;
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
#ifdef __CREATE_AUTOMATION_CLASS_
	AUTOMATION	*company_liab_fia_fia_automation;
	AUTOMATION	*&fia_automation;
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
#ifdef __CREATE_INTEX_ASSET_CLASS_
	INTEX_ASSET	*company_asset_intex;
	INTEX_ASSET	*&intex;
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
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
	MTG_CF_ASSET	*company_asset_mtg_mtg_cf_mtg_is;
	MTG_CF_ASSET	*&mtg_is;
#endif
#ifdef __CREATE_MTG_CF_ASSET_CLASS_
	MTG_CF_ASSET	*company_asset_mtg_mtg_cf_mtg_pv;
	MTG_CF_ASSET	*&mtg_pv;
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
 	ColumnAccessor < mCFStaticData_0 > admin_fee;
 	ColumnAccessor < mCFStaticData_0 > credited_int;
 	ColumnAccessor < mCFStaticData_0 > crediting_cap_rate;
 	ColumnAccessor < mCFStaticData_0 > crediting_cap_rate_2nd_strat_crbg;
 	ColumnAccessor < mCFStaticData_0 > crediting_part_rate;
 	ColumnAccessor < mCFStaticData_0 > crediting_part_rate_aig;
 	ColumnAccessor < mCFStaticData_0 > crediting_part_rate_base_aig;
 	ColumnAccessor < mCFStaticData_0 > crediting_pri_sprd_aig;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate_cumul_aig;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate_fix;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate_fix_cumul_aig;
 	ColumnAccessor < mCFStaticData_0 > crediting_spread_rate_aig;
 	ColumnAccessor < mCFStaticData_0 > crediting_trigger_rate_aig;
 	ColumnAccessor < mCFStaticData_0 > crediting_type_dyn_trigger_aig;
 	ColumnAccessor < mCFStaticData_0 > crediting_type_dyn_zero_threshold_flag_aig;
 	ColumnAccessor < mCFStaticData_0 > cumul_return_sc_period_crbg;
 	ColumnAccessor < mCFStaticData_0 > eprs_cost_rate_aig;
 	ColumnAccessor < mCFStaticData_0 > fa_crediting_rate_aig;
 	ColumnAccessor < mCFStaticData_0 > fa_pricing_rate_aig;
 	ColumnAccessor < mCFStaticData_0 > fa_reference_rate_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_ann;
 	ColumnAccessor < mCFStaticData_0 > fund_released_dth;
 	ColumnAccessor < mCFStaticData_0 > fund_released_maturity;
 	ColumnAccessor < mCFStaticData_0 > fund_released_surr;
 	ColumnAccessor < mCFStaticData_0 > fund_released_withdrl;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b_bef;
 	ColumnAccessor < mCFStaticData_0 > fund_val_decrem;
 	ColumnAccessor < mCFStaticData_0 > fund_val_e;
 	ColumnAccessor < mCFStaticData_0 > fund_val_e_bef;
 	ColumnAccessor < mCFStaticData_0 > fund_val_e_bef_maturity_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_val_rebal;
 	ColumnAccessor < mCFStaticData_0 > fund_weighted_crediting_pri_sprd_aig;
 	ColumnAccessor < mCFStaticData_0 > gmab_av_b_aig;
 	ColumnAccessor < mCFStaticData_0 > gmab_av_e_aig;
 	ColumnAccessor < mCFStaticData_0 > gmab_av_e_bef_aig;
 	ColumnAccessor < mCFStaticData_0 > gmab_chg_aig;
 	ColumnAccessor < mCFStaticData_0 > gmab_chg_partial_e_aig;
 	ColumnAccessor < mCFStaticData_0 > gmab_chg_partial_e_bef_aig;
 	ColumnAccessor < mCFStaticData_0 > gmab_global_payoff_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmab_payoff_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg_at_surr_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg_at_surr_bef_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_income_base_credit_rate_protation_fct_at_wdl_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_income_base_credit_rate_protation_fct_e_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_income_base_credit_rate_protation_fct_e_bef_aig;
 	ColumnAccessor < mCFStaticData_0 > hedge_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > hedge_inv_amt_bom;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val_aig;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val_gmab_only_crbg;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val_growth;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val_per_unit_notional;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val_per_unit_notional_aig;
 	ColumnAccessor < mCFStaticData_0 > hedge_option_val_alpha_col_aig;
 	ColumnAccessor < mCFStaticData_0 > hedge_sale_amt_bom;
 	ColumnAccessor < mCFStaticData_0 > hedge_sale_amt_eom;
 	ColumnAccessor < mCFStaticData_0 > index_term_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_beginning_index_val_bom_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_cap_rate_max_col_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_cap_rate_min_col_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_elapsed_mths_eom_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_elapsed_pct_eom_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_end_duration_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_floor_col_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_index_return_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_init_cap_rate_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_init_part_rate_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_init_spread_rate_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_mths_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_part_rate_max_col_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_part_rate_min_col_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_sprd_rate_max_col_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_sprd_rate_min_col_aig;
 	ColumnAccessor < mCFStaticData_0 > index_term_start_duration_aig;
 	ColumnAccessor < mCFStaticData_0 > index_val;
 	ColumnAccessor < mCFStaticData_0 > index_val_bom;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > lapse_dyn_base_prod_crediting_rt_aig;
 	ColumnAccessor < mCFStaticData_0 > min_accum_val_b_aig;
 	ColumnAccessor < mCFStaticData_0 > min_accum_val_b_bef_aig;
 	ColumnAccessor < mCFStaticData_0 > min_accum_val_e_aig;
 	ColumnAccessor < mCFStaticData_0 > min_accum_val_e_bef_aig;
 	ColumnAccessor < mCFStaticData_0 > min_accum_val_e_bef_maturity_aig;
 	ColumnAccessor < mCFStaticData_0 > net_crediting_rate_aig;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_required;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_required_bef;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_seccap_gmab_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_seccap_gmab_crbg;
 	ColumnAccessor < mCFStaticData_0 > notional_to_hedge;
 	ColumnAccessor < mCFStaticData_0 > notional_to_hedge_aig;
 	ColumnAccessor < mCFStaticData_0 > notional_to_hedge_cap;
 	ColumnAccessor < mCFStaticData_0 > notional_to_hedge_index;
 	ColumnAccessor < mCFStaticData_0 > notional_to_hedge_long_strike;
 	ColumnAccessor < mCFStaticData_0 > notional_to_hedge_net;
 	ColumnAccessor < mCFStaticData_0 > opt_budget;
 	ColumnAccessor < mCFStaticData_0 > opt_budget_2nd_strat_aig;
 	ColumnAccessor < mCFStaticData_0 > opt_budget_amt;
 	ColumnAccessor < mCFStaticData_0 > opt_budget_cost_aig;
 	ColumnAccessor < mCFStaticData_0 > opt_budget_eprs_aig;
 	ColumnAccessor < mCFStaticData_0 > opt_budget_renewal_aig;
 	ColumnAccessor < mCFStaticData_0 > opt_budget_strategy_term_renewal_aig;
 	ColumnAccessor < mCFStaticData_0 > opt_budget_tgt_2nd_strat_aig;
 	ColumnAccessor < mCFStaticData_0 > opt_budget_tgt_aig;
 	ColumnAccessor < mCFStaticData_0 > opt_cost_atm_aig;
 	ColumnAccessor < mCFStaticData_0 > opt_payoff;
 	ColumnAccessor < mCFStaticData_0 > opt_payoff_aig;
 	ColumnAccessor < mCFStaticData_0 > opt_strike_price;
 	ColumnAccessor < mCFStaticData_0 > opt_value_net_numer;
 	ColumnAccessor < mCFStaticData_0 > pfwd_surr_fund_val;
 	ColumnAccessor < mCFStaticData_0 > prem_alloc;
 	ColumnAccessor < mCFStaticData_0 > prem_bonus;
 	ColumnAccessor < mCFStaticData_0 > sfas133_gmwb_chg;
 	ColumnAccessor < mCFStaticData_0 > startup;
 	ColumnAccessor < mCFStaticData_0 > strategy_return_aig;
 	ColumnAccessor < mCFStaticData_0 > strategy_return_cumul_aig;
 	ColumnAccessor < mCFStaticData_0 > strategy_return_prorated_aig;
 	ColumnAccessor < mCFStaticData_0 > strategy_term_aig;
 	ColumnAccessor < mCFStaticData_0 > strategy_term_beginning_index_val_bom_aig;
 	ColumnAccessor < mCFStaticData_0 > strategy_term_elapsed_mths_eom_aig;
 	ColumnAccessor < mCFStaticData_0 > strategy_term_elapsed_pct_eom_aig;
 	ColumnAccessor < mCFStaticData_0 > strategy_term_floor_col_aig;
 	ColumnAccessor < mCFStaticData_0 > strategy_term_index_return_aig;
 	ColumnAccessor < mCFStaticData_0 > strategy_term_mths_aig;
 	ColumnAccessor < mCFStaticData_0 > tier_number_aig;
 	ColumnAccessor < mCFStaticData_0 > tier_strat_fee_aig;
 	ColumnAccessor < mCFStaticData_0 > tier_strat_fee_at_surr_aig;
 	ColumnAccessor < mCFStaticData_0 > tier_strat_fee_at_surr_bef_aig;
//Column Definition END@2

 // Temporary Table...
FIAAFUND_LIAB *sm_bond_is;
FIAAFUND_LIAB *sm_bond_pv;
FIAAFUND_LIAB *sm_bond_ym;
FIAAFUND_LIAB *sm_mtg_is;
FIAAFUND_LIAB *sm_mtg_pv;
FIAAFUND_LIAB *sm_mtg_ym;
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
	Attribute::Proxy <double, DESCRIPTOR_TABLE > crediting_cap_max;
  inline double	Get_crediting_cap_max() {
		return crediting_cap_max; }
  inline void Set_crediting_cap_max(const double &v) {
		crediting_cap_max.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > crediting_cap_min;
  inline double	Get_crediting_cap_min() {
		return crediting_cap_min; }
  inline void Set_crediting_cap_min(const double &v) {
		crediting_cap_min.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > crediting_dyn_lever;
  inline xstring	Get_crediting_dyn_lever() {
		return crediting_dyn_lever; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > crediting_eqt_index;
  inline xstring	Get_crediting_eqt_index() {
		return crediting_eqt_index; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > crediting_mths;
  inline int	Get_crediting_mths() {
		return crediting_mths; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_part_min;
  inline double	Get_crediting_part_min() {
		return crediting_part_min; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > crediting_rate_defn;
  inline xstring	Get_crediting_rate_defn() {
		return crediting_rate_defn; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > crediting_rate_guar_mths;
  inline int	Get_crediting_rate_guar_mths() {
		return crediting_rate_guar_mths; }
  inline void Set_crediting_rate_guar_mths(const int &v) {
		crediting_rate_guar_mths.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_rt_chg_threshold_aig;
  inline double	Get_crediting_rt_chg_threshold_aig() {
		return crediting_rt_chg_threshold_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > current_opt_defn_aig;
  inline xstring	Get_current_opt_defn_aig() {
		return current_opt_defn_aig; }
  inline void Set_current_opt_defn_aig(const xstring &v) {
		current_opt_defn_aig.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > display_solver_warnings_defn;
  inline xstring	Get_display_solver_warnings_defn() {
		return display_solver_warnings_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eprs_add_par_rate_threshold_aig;
  inline double	Get_eprs_add_par_rate_threshold_aig() {
		return eprs_add_par_rate_threshold_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eprs_add_part_rate_min_aig;
  inline double	Get_eprs_add_part_rate_min_aig() {
		return eprs_add_part_rate_min_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eprs_cost_aig;
  inline double	Get_eprs_cost_aig() {
		return eprs_cost_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > eprs_cost_level_aig;
  inline int	Get_eprs_cost_level_aig() {
		return eprs_cost_level_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eprs_hedge_min_par_aig;
  inline double	Get_eprs_hedge_min_par_aig() {
		return eprs_hedge_min_par_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eprs_index_term_part_rate_max_aig;
  inline double	Get_eprs_index_term_part_rate_max_aig() {
		return eprs_index_term_part_rate_max_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eprs_par_rate_aig;
  inline double	Get_eprs_par_rate_aig() {
		return eprs_par_rate_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eprs_rounding_multiple_aig;
  inline double	Get_eprs_rounding_multiple_aig() {
		return eprs_rounding_multiple_aig; }
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
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_defn;
  inline xstring	Get_hedge_defn() {
		return hedge_defn; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > hedge_grp_code;
  inline xstring	Get_hedge_grp_code() {
		return hedge_grp_code; }
  inline void Set_hedge_grp_code(const xstring &v) {
		hedge_grp_code.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_inefficiency_aig;
  inline double	Get_hedge_inefficiency_aig() {
		return hedge_inefficiency_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_option_val_alpha_aig;
  inline double	Get_hedge_option_val_alpha_aig() {
		return hedge_option_val_alpha_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_term_cap_rate_max_aig;
  inline double	Get_index_term_cap_rate_max_aig() {
		return index_term_cap_rate_max_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_term_cap_rate_min_aig;
  inline double	Get_index_term_cap_rate_min_aig() {
		return index_term_cap_rate_min_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > index_term_cap_rate_min_table_aig;
  inline xstring	Get_index_term_cap_rate_min_table_aig() {
		return index_term_cap_rate_min_table_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > index_term_cap_rate_min_table_gmab;
  inline xstring	Get_index_term_cap_rate_min_table_gmab() {
		return index_term_cap_rate_min_table_gmab; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > index_term_duration_aig;
  inline int	Get_index_term_duration_aig() {
		return index_term_duration_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_term_floor_aig;
  inline double	Get_index_term_floor_aig() {
		return index_term_floor_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_term_part_rate_max_aig;
  inline double	Get_index_term_part_rate_max_aig() {
		return index_term_part_rate_max_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_term_part_rate_min_aig;
  inline double	Get_index_term_part_rate_min_aig() {
		return index_term_part_rate_min_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_term_sprd_rate_max_aig;
  inline double	Get_index_term_sprd_rate_max_aig() {
		return index_term_sprd_rate_max_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_term_sprd_rate_min_aig;
  inline double	Get_index_term_sprd_rate_min_aig() {
		return index_term_sprd_rate_min_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_term_trigger_rate_max_aig;
  inline double	Get_index_term_trigger_rate_max_aig() {
		return index_term_trigger_rate_max_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_term_trigger_rate_min_aig;
  inline double	Get_index_term_trigger_rate_min_aig() {
		return index_term_trigger_rate_min_aig; }
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_opt_cost_gmab;
  inline double	Get_init_opt_cost_gmab() {
		return init_opt_cost_gmab; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_opt_cost_seccap;
  inline double	Get_init_opt_cost_seccap() {
		return init_opt_cost_seccap; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_opt_cost_seccap_gmab;
  inline double	Get_init_opt_cost_seccap_gmab() {
		return init_opt_cost_seccap_gmab; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > init_part_rate;
  inline double	Get_init_part_rate() {
		return init_part_rate; }
  inline void Set_init_part_rate(const double &v) {
		init_part_rate.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > init_spread_rate_aig;
  inline double	Get_init_spread_rate_aig() {
		return init_spread_rate_aig; }
  inline void Set_init_spread_rate_aig(const double &v) {
		init_spread_rate_aig.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > init_trigger_rate_aig;
  inline double	Get_init_trigger_rate_aig() {
		return init_trigger_rate_aig; }
  inline void Set_init_trigger_rate_aig(const double &v) {
		init_trigger_rate_aig.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > lookback_defn;
  inline xstring	Get_lookback_defn() {
		return lookback_defn; }
  inline void Set_lookback_defn(const xstring &v) {
		lookback_defn.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lookback_sampling_interval;
  inline xstring	Get_lookback_sampling_interval() {
		return lookback_sampling_interval; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > part_rate_solve_max_iter_aig;
  inline int	Get_part_rate_solve_max_iter_aig() {
		return part_rate_solve_max_iter_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > part_rate_solve_tolerance_aig;
  inline double	Get_part_rate_solve_tolerance_aig() {
		return part_rate_solve_tolerance_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pct_to_hedge;
  inline double	Get_pct_to_hedge() {
		return pct_to_hedge; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > remove_par_sprd_min_max_aig;
  inline xstring	Get_remove_par_sprd_min_max_aig() {
		return remove_par_sprd_min_max_aig; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > renewal_beta_down_aig;
  inline double	Get_renewal_beta_down_aig() {
		return renewal_beta_down_aig; }
  inline void Set_renewal_beta_down_aig(const double &v) {
		renewal_beta_down_aig.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > renewal_beta_up_aig;
  inline double	Get_renewal_beta_up_aig() {
		return renewal_beta_up_aig; }
  inline void Set_renewal_beta_up_aig(const double &v) {
		renewal_beta_up_aig.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > renewal_budget_reduction_aig;
  inline double	Get_renewal_budget_reduction_aig() {
		return renewal_budget_reduction_aig; }
  inline void Set_renewal_budget_reduction_aig(const double &v) {
		renewal_budget_reduction_aig.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > renewal_glb_beta_down_aig;
  inline double	Get_renewal_glb_beta_down_aig() {
		return renewal_glb_beta_down_aig; }
  inline void Set_renewal_glb_beta_down_aig(const double &v) {
		renewal_glb_beta_down_aig.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > renewal_glb_beta_up_aig;
  inline double	Get_renewal_glb_beta_up_aig() {
		return renewal_glb_beta_up_aig; }
  inline void Set_renewal_glb_beta_up_aig(const double &v) {
		renewal_glb_beta_up_aig.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > renewal_migration_beg_yr_aig;
  inline double	Get_renewal_migration_beg_yr_aig() {
		return renewal_migration_beg_yr_aig; }
  inline void Set_renewal_migration_beg_yr_aig(const double &v) {
		renewal_migration_beg_yr_aig.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > renewal_pri_sprd_tgt_aig;
  inline double	Get_renewal_pri_sprd_tgt_aig() {
		return renewal_pri_sprd_tgt_aig; }
  inline void Set_renewal_pri_sprd_tgt_aig(const double &v) {
		renewal_pri_sprd_tgt_aig.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > renewal_surr_chg_offest_aig;
  inline double	Get_renewal_surr_chg_offest_aig() {
		return renewal_surr_chg_offest_aig; }
  inline void Set_renewal_surr_chg_offest_aig(const double &v) {
		renewal_surr_chg_offest_aig.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > seasoned_opt_cost_gmab;
  inline double	Get_seasoned_opt_cost_gmab() {
		return seasoned_opt_cost_gmab; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > seasoned_opt_cost_seccap;
  inline double	Get_seasoned_opt_cost_seccap() {
		return seasoned_opt_cost_seccap; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > seasoned_opt_cost_seccap_gmab;
  inline double	Get_seasoned_opt_cost_seccap_gmab() {
		return seasoned_opt_cost_seccap_gmab; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > strategy_term_duration_aig;
  inline int	Get_strategy_term_duration_aig() {
		return strategy_term_duration_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > strategy_term_floor_aig;
  inline double	Get_strategy_term_floor_aig() {
		return strategy_term_floor_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > use_option_cost_tables_defn_aig;
  inline xstring	Get_use_option_cost_tables_defn_aig() {
		return use_option_cost_tables_defn_aig; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > commencement_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > elapsed_mths;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > final_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > lookback_mths;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > lookback_sampling_mths;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > maturity_period;

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

// Cap Solver for Monthly Sum Cap
#line 1 "cap_solver_mthly_sum_cap.fiaafund_liab.for"
double cap_solver_mthly_sum_cap(int t);

// Solve for index crediting cap:
#line 1 "cap_solver_point_to_point_aig.fiaafund_liab.for"
double cap_solver_point_to_point_aig(int t);

// Cap Solver for Point To Point and Moving Average
#line 1 "cap_solver_point_to_point_moving_avg.fiaafund_liab.for"
double cap_solver_point_to_point_moving_avg(int t);

// Convert the proprietary XSTRING datatype to the standard library STRING datatype
#line 1 "cast_xstring_to_string_aig.fiaafund_liab.for"
std::string cast_xstring_to_string_aig(const xstring& input_xstring);

// Get option price from ESG:
#line 1 "get_option_price_aig.fiaafund_liab.for"
double get_option_price_aig(
	int projection_month, double strike, StrEnum::EnumValue opt_defn, int option_duration_mths, int input_strike_period_mths);

// Get option strike from ESG tables:
#line 1 "get_option_strike_aig.fiaafund_liab.for"
double get_option_strike_aig(
	int projection_month, double cost, StrEnum::EnumValue opt_defn, int option_duration_mths, int output_strike_period_mths);

// Equity Index Rolling Average of Past x Months
#line 1 "index_val_avg_calc.fiaafund_liab.for"
double index_val_avg_calc(int time, int month);

// Index Value Calculation
#line 1 "index_val_calc.fiaafund_liab.for"
double index_val_calc(int t);

// External function to calculate the dynamic spread and participation rate:
#line 1 "joint_part_sprd_rate_solver_aig.fiaafund_liab.for"
void joint_part_sprd_rate_solver_aig(int t, double& part_rate, double& sprd_rate);

// Market Value Calculation
#line 1 "mkt_val_calc.fiaafund_liab.for"
double mkt_val_calc(int t, int cal_yr, int cal_mth, int lookback_defn, int lookback_mths, int lookback_sampling_mths, double index_units_owned, double index_val, double index_scen_mult, double index_scen_sprd_addn, double term_to_expiry, double div_yld_scen_mult, double div_yld_sprd, double opt_strike_price, double payout_index_max, double mthly_cap_rate, StrEnum::EnumValue opt_defn, double extra_spot_spread, double extra_vol_spread, int shift_defn);

// Opt Budget Helper Function:
#line 1 "opt_budget_migration_aig.fiaafund_liab.for"
double opt_budget_migration_aig(
	double opt_budget_base, double ner_init, double ner_cv,
	double beta, double crediting_period_yrs, 
	double opt_budget_tgt = 0.0, double grading_progress_input = 0.0);

// Option Market Value Estimate
#line 1 "opt_mkt_val_estimate_aig.fiaafund_liab.for"
double opt_mkt_val_estimate_aig(
	int t,
	double intrinsic_value,
	double option_cost,
	double option_term_start_month,
	double option_term_end_month
);

// Iterative participation rate solve
#line 1 "part_rate_solver_aig.fiaafund_liab.for"
double part_rate_solver_aig(int t, double guess_low_bound, double guess_high_bound);

// Solve for index crediting spread:
#line 1 "spread_solver_point_to_point_aig.fiaafund_liab.for"
double spread_solver_point_to_point_aig(int t);

// Strike
#line 1 "strike.fiaafund_liab.for"
double strike(int t, int reserve_period, int mths_in_first_period);

// Strike cap
#line 1 "strike_cap.fiaafund_liab.for"
double strike_cap(int t, int reserve_period, int mths_in_first_period);

// Time until expiration of crediting options:
#line 1 "time_to_expiry_aig.fiaafund_liab.for"
double time_to_expiry_aig(int policy_month, int reserve_period);

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
	FIAAFUND_LIAB *&sm_bond_is; //
	FIAAFUND_LIAB *&sm_bond_pv; //
	FIAAFUND_LIAB *&sm_bond_ym; //
	FIAAFUND_LIAB *&sm_mtg_is; //
	FIAAFUND_LIAB *&sm_mtg_pv; //
	FIAAFUND_LIAB *&sm_mtg_ym; //

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
