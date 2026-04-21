#ifndef __ANN_PBA_PBA_H_
#define __ANN_PBA_PBA_H_
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

#ifdef __CREATE_BOND_AIG_CLASS_
class BOND_AIG;
class BOND_AIG_persistent_object;
typedef TComp<BOND_AIG, BOND_AIG_persistent_object> _1D_BOND_AIG;
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

#ifdef __CREATE_BOND_PORTFOLIO_AIG_CLASS_
class BOND_PORTFOLIO_AIG;
class BOND_PORTFOLIO_AIG_persistent_object;
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



namespace ANN_PBA_PBA_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class ANN_PBA_PBA_persistent_object;
class ANN_PBA_PBA : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(ANN_PBA_PBA); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;

//typedef map <int, long, less <int> > mpmap; //Gen2 - 9/6/2024 - comment out typedef
int scen_greatest_pv_period;
double init_assets;
double init_asset_pct;
SmartArray <double> hedge_cash_flow_array;
SmartArray <double> hedge_mkt_val_array;

	void init_(){
		

init_assets = 0.0;
init_asset_pct = 1.0;
scen_greatest_pv_period = -1;

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
#ifdef __CREATE_COMP_COMP_CLASS_
	COMP_COMP	*company;
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
	FIA_LIAB	*company_liab_fia;
	FIA_LIAB	*&fia;
#endif
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
	ANN_PBA_PBA	*company_liab_fia_fia_ann_pba;
	ANN_PBA_PBA	*&fia_ann_pba;
#endif
#ifdef __CREATE_AUTOMATION_CLASS_
	AUTOMATION	*company_liab_fia_fia_automation;
	AUTOMATION	*&fia_automation;
#endif
#ifdef __CREATE_BOND_PORTFOLIO_AIG_CLASS_
	BOND_PORTFOLIO_AIG	*company_liab_fia_fia_bond_portfolio_aig;
	BOND_PORTFOLIO_AIG	*&fia_bond_portfolio_aig;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
	RATES_ECONOMY	*company_liab_fia_fia_rates;
	RATES_ECONOMY	*&fia_rates;
#endif
#ifdef __CREATE_LIAB_LIAB_CLASS_
	LIAB_LIAB	*company_liab;
	LIAB_LIAB	*&liab;
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
 	ColumnAccessor < mCFStaticData_0 > asset_yld_mthly;
 	ColumnAccessor < mCFStaticData_0 > assets_accum;
 	ColumnAccessor < mCFStaticData_0 > assets_accum_inv;
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > cap_gain;
 	ColumnAccessor < mCFStaticData_0 > cash_flow;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_int;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_rate_mthly;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > def_accum;
 	ColumnAccessor < mCFStaticData_0 > direct_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > direct_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > direct_cash_flow_int;
 	ColumnAccessor < mCFStaticData_0 > direct_imr_incr;
 	ColumnAccessor < mCFStaticData_0 > direct_inv_inc;
 	ColumnAccessor < mCFStaticData_0 > direct_prof;
 	ColumnAccessor < mCFStaticData_0 > direct_res_incr;
 	ColumnAccessor < mCFStaticData_0 > direct_tax;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_accum;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_mthly;
 	ColumnAccessor < mCFStaticData_0 > eff_cap_gains_rate;
 	ColumnAccessor < mCFStaticData_0 > hedge_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > hedge_cost;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_0 > hedging_e_factor;
 	ColumnAccessor < mCFStaticData_0 > imr;
 	ColumnAccessor < mCFStaticData_0 > imr_incr;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > inv_inc;
 	ColumnAccessor < mCFStaticData_0 > pimr_adj_factor;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > reins_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > reins_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > reins_cash_flow_int;
 	ColumnAccessor < mCFStaticData_0 > reins_cost;
 	ColumnAccessor < mCFStaticData_0 > reins_imr_incr;
 	ColumnAccessor < mCFStaticData_0 > reins_inv_inc;
 	ColumnAccessor < mCFStaticData_0 > reins_res;
 	ColumnAccessor < mCFStaticData_0 > reins_res_incr;
 	ColumnAccessor < mCFStaticData_0 > reins_tax_res;
 	ColumnAccessor < mCFStaticData_0 > reins_tax_res_incr;
 	ColumnAccessor < mCFStaticData_0 > scen_amt;
 	ColumnAccessor < mCFStaticData_0 > scen_greatest_pv;
 	ColumnAccessor < mCFStaticData_0 > starting_assets;
 	ColumnAccessor < mCFStaticData_0 > startup;
 	ColumnAccessor < mCFStaticData_0 > stoch_amt;
 	ColumnAccessor < mCFStaticData_0 > tax;
 	ColumnAccessor < mCFStaticData_0 > tax_adj_ratio;
 	ColumnAccessor < mCFStaticData_0 > tax_capzd_prem;
 	ColumnAccessor < mCFStaticData_0 > tax_capzd_prem_amortzn;
 	ColumnAccessor < mCFStaticData_0 > tax_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > tax_cash_flow_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > tax_res;
 	ColumnAccessor < mCFStaticData_0 > tax_res_incr;
 	ColumnAccessor < mCFStaticData_0 > tax_ytd;
 	ColumnAccessor < mCFStaticData_0 > tax_ytd_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > taxable_inc;
 	ColumnAccessor < mCFStaticData_0 > taxable_inc_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > taxable_inc_ytd;
 	ColumnAccessor < mCFStaticData_0 > taxable_inc_ytd_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > working_res;
//Column Definition END@2

 // Temporary Table...
ANN_PBA_PBA *sm_bond_is;
ANN_PBA_PBA *sm_bond_pv;
ANN_PBA_PBA *sm_bond_ym;
ANN_PBA_PBA *sm_mtg_is;
ANN_PBA_PBA *sm_mtg_pv;
ANN_PBA_PBA *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE ANN_PBA_PBA::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cte_pct_stoch_cap;
  inline double	Get_cte_pct_stoch_cap() {
		return cte_pct_stoch_cap; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > disc_rate_method;
  inline xstring	Get_disc_rate_method() {
		return disc_rate_method; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > hedging_cash_flow_defn;
  inline xstring	Get_hedging_cash_flow_defn() {
		return hedging_cash_flow_defn; }
  inline void Set_hedging_cash_flow_defn(const xstring &v) {
		hedging_cash_flow_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > hedging_defn;
  inline xstring	Get_hedging_defn() {
		return hedging_defn; }
  inline void Set_hedging_defn(const xstring &v) {
		hedging_defn.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedging_defn_input;
  inline xstring	Get_hedging_defn_input() {
		return hedging_defn_input; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedging_e_factor_stoch_cap;
  inline double	Get_hedging_e_factor_stoch_cap() {
		return hedging_e_factor_stoch_cap; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedging_e_factor_stoch_res;
  inline double	Get_hedging_e_factor_stoch_res() {
		return hedging_e_factor_stoch_res; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > hedging_output_file_best_estimate_stoch_cap;
  inline xstring	Get_hedging_output_file_best_estimate_stoch_cap() {
		return hedging_output_file_best_estimate_stoch_cap; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > hedging_output_file_best_estimate_stoch_res;
  inline xstring	Get_hedging_output_file_best_estimate_stoch_res() {
		return hedging_output_file_best_estimate_stoch_res; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > hedging_output_file_existing_hedges_stoch_cap;
  inline xstring	Get_hedging_output_file_existing_hedges_stoch_cap() {
		return hedging_output_file_existing_hedges_stoch_cap; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > hedging_output_file_existing_hedges_stoch_res;
  inline xstring	Get_hedging_output_file_existing_hedges_stoch_res() {
		return hedging_output_file_existing_hedges_stoch_res; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedging_stat_scale_factor_max_stoch_cap;
  inline double	Get_hedging_stat_scale_factor_max_stoch_cap() {
		return hedging_stat_scale_factor_max_stoch_cap; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedging_stat_scale_factor_max_stoch_res;
  inline double	Get_hedging_stat_scale_factor_max_stoch_res() {
		return hedging_stat_scale_factor_max_stoch_res; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_asset_pct_input;
  inline double	Get_init_asset_pct_input() {
		return init_asset_pct_input; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > init_assets_defn;
  inline xstring	Get_init_assets_defn() {
		return init_assets_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_assets_input;
  inline double	Get_init_assets_input() {
		return init_assets_input; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > pba_code;
  inline xstring	Get_pba_code() {
		return pba_code; }
  inline void Set_pba_code(const xstring &v) {
		pba_code.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > pba_cte_code;
  inline xstring	Get_pba_cte_code() {
		return pba_cte_code; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > rbc_c3_cte98_factor;
  inline double	Get_rbc_c3_cte98_factor() {
		return rbc_c3_cte98_factor; }
  inline void Set_rbc_c3_cte98_factor(const double &v) {
		rbc_c3_cte98_factor.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c3_cte98_factor_input;
  inline double	Get_rbc_c3_cte98_factor_input() {
		return rbc_c3_cte98_factor_input; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > reins_defn;
  inline xstring	Get_reins_defn() {
		return reins_defn; }
  inline void Set_reins_defn(const xstring &v) {
		reins_defn.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > reins_defn_input;
  inline xstring	Get_reins_defn_input() {
		return reins_defn_input; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > reins_gross_up_defn;
  inline xstring	Get_reins_gross_up_defn() {
		return reins_gross_up_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > res_assumption_set;
  inline xstring	Get_res_assumption_set() {
		return res_assumption_set; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > res_cap_calc_defn;
  inline xstring	Get_res_cap_calc_defn() {
		return res_cap_calc_defn; }
  inline void Set_res_cap_calc_defn(const xstring &v) {
		res_cap_calc_defn.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > res_cap_calc_defn_input;
  inline xstring	Get_res_cap_calc_defn_input() {
		return res_cap_calc_defn_input; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rila_ind;
  inline double	Get_rila_ind() {
		return rila_ind; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > rila_opt_inefficiency;
  inline double	Get_rila_opt_inefficiency() {
		return rila_opt_inefficiency; }
  inline void Set_rila_opt_inefficiency(const double &v) {
		rila_opt_inefficiency.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rila_opt_inefficiency_input;
  inline double	Get_rila_opt_inefficiency_input() {
		return rila_opt_inefficiency_input; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > seg_id;
  inline xstring	Get_seg_id() {
		return seg_id; }
  inline void Set_seg_id(const xstring &v) {
		seg_id.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tax_defn_stoch_cap;
  inline xstring	Get_tax_defn_stoch_cap() {
		return tax_defn_stoch_cap; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > valn_results_stoch_cap;
  inline xstring	Get_valn_results_stoch_cap() {
		return valn_results_stoch_cap; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > valn_results_stoch_res;
  inline xstring	Get_valn_results_stoch_res() {
		return valn_results_stoch_res; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > working_res_defn_input;
  inline xstring	Get_working_res_defn_input() {
		return working_res_defn_input; }
  inline void Set_working_res_defn_input(const xstring &v) {
		working_res_defn_input.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > cte_pct;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > disc_rate_mult_fixed;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > final_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > hedging_flag;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > hedging_output_file_best_estimate;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > hedging_output_file_existing_hedges;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > hedging_stat_scale_factor_max;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > proj_date_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_date;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_yr;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > reins_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > reins_flag;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > reins_pct;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > start_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > tax_capzd_prem_amortzn_yrs;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > tax_flag;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > valn_results_scen_amt;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > working_res_defn;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(ANN_PBA_PBA* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Get Hedge Items
#line 1 "get_hedge_items.ann_pba_pba.for"
void get_hedge_items(void);

// Sum Over PBA
#line 1 "sum_over_pba.ann_pba_pba.for"
double sum_over_pba(const xstring &colname, int t);


//factory
static ANN_PBA_PBA* makeThis(int isSubmodel, ModelClass *owner, ANN_PBA_PBA* peer, 
					int mainRebase, const xstring &name, ANN_PBA_PBA_persistent_object* arrayTemplate);

//constructor
ANN_PBA_PBA(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
ANN_PBA_PBA(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~ANN_PBA_PBA();


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
class ANN_PBA_PBA_persistent_object : public ANN_PBA_PBA {


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

	void findTargetColumns() {ANN_PBA_PBA::findTargetColumns();}
	void createAllShare() {
		ANN_PBA_PBA::createAllShare();
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
	ANN_PBA_PBA *&sm_bond_is; //
	ANN_PBA_PBA *&sm_bond_pv; //
	ANN_PBA_PBA *&sm_bond_ym; //
	ANN_PBA_PBA *&sm_mtg_is; //
	ANN_PBA_PBA *&sm_mtg_pv; //
	ANN_PBA_PBA *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~ANN_PBA_PBA_persistent_object();

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
static ANN_PBA_PBA_persistent_object* makeThis(int isSubmodel, ModelClass *owner, ANN_PBA_PBA* peer, 
					int mainRebase, const xstring &name, ANN_PBA_PBA_persistent_object* arrayTemplate, bool fixedArray);

//constructor
ANN_PBA_PBA_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
