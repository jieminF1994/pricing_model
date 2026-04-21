#ifndef __HDG_GRP_COMP_H_
#define __HDG_GRP_COMP_H_
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



namespace HDG_GRP_COMP_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class HDG_GRP_COMP_persistent_object;
class HDG_GRP_COMP : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(HDG_GRP_COMP); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;

typedef map <int, long, less <int> > mpmap;
mpmap fia_mp_map;
mpmap iul_mp_map;
mpmap va_mp_map;
mpmap eio_mp_map_active;
mpmap ird_mp_map_active;
map <xstring, double> liab_greeks;
map <xstring, double> asset_greeks;
map <xstring, double> asset_greeks_needed;

int hedge_group_count;
SmartArray < SmartArray <double> >  hedge_valn_array;

	void init_(){
		

hedge_group_count = 0;

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
#ifdef __CREATE_EPL_LIAB_CLASS_
	EPL_LIAB	*company_liab_epl;
	EPL_LIAB	*&epl;
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
	FIA_LIAB	*company_liab_fia;
	FIA_LIAB	*&fia;
#endif
#ifdef __CREATE_INVSTRAT_ASSET_CLASS_
	INVSTRAT_ASSET	*company_inv_strategy;
	INVSTRAT_ASSET	*&inv_strategy;
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
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > cap_rate;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_flag;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_inv_amt;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_pmt;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_prof;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_transaction_cost;
 	ColumnAccessor < mCFStaticData_0 > delta_index_1;
 	ColumnAccessor < mCFStaticData_0 > delta_index_2;
 	ColumnAccessor < mCFStaticData_0 > delta_index_3;
 	ColumnAccessor < mCFStaticData_0 > delta_index_4;
 	ColumnAccessor < mCFStaticData_0 > delta_index_5;
 	ColumnAccessor < mCFStaticData_0 > delta_index_6;
 	ColumnAccessor < mCFStaticData_0 > delta_parallel;
 	ColumnAccessor < mCFStaticData_0 > econ_cash;
 	ColumnAccessor < mCFStaticData_0 > econ_cash_int;
 	ColumnAccessor < mCFStaticData_0 > econ_cash_int_rate;
 	ColumnAccessor < mCFStaticData_0 > econ_prof;
 	ColumnAccessor < mCFStaticData_0 > econ_prof_unhedged;
 	ColumnAccessor < mCFStaticData_0 > econ_res;
 	ColumnAccessor < mCFStaticData_0 > econ_res_incr;
 	ColumnAccessor < mCFStaticData_0 > econ_res_int;
 	ColumnAccessor < mCFStaticData_0 > finalize;
 	ColumnAccessor < mCFStaticData_0 > fund_val_decrem;
 	ColumnAccessor < mCFStaticData_0 > fund_val_decrem_cumul;
 	ColumnAccessor < mCFStaticData_0 > fund_val_fixed;
 	ColumnAccessor < mCFStaticData_0 > gamma_hedge_flag;
 	ColumnAccessor < mCFStaticData_0 > gamma_hedge_inv_amt;
 	ColumnAccessor < mCFStaticData_0 > gamma_hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > gamma_hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_0 > gamma_hedge_pmt;
 	ColumnAccessor < mCFStaticData_0 > gamma_hedge_prof;
 	ColumnAccessor < mCFStaticData_0 > gamma_hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_0 > gamma_hedge_transaction_cost;
 	ColumnAccessor < mCFStaticData_0 > gamma_index_1;
 	ColumnAccessor < mCFStaticData_0 > gamma_index_2;
 	ColumnAccessor < mCFStaticData_0 > gamma_index_3;
 	ColumnAccessor < mCFStaticData_0 > gamma_index_4;
 	ColumnAccessor < mCFStaticData_0 > gamma_index_5;
 	ColumnAccessor < mCFStaticData_0 > gamma_index_6;
 	ColumnAccessor < mCFStaticData_0 > gamma_parallel;
 	ColumnAccessor < mCFStaticData_0 > gamma_vega_hedge_flag;
 	ColumnAccessor < mCFStaticData_0 > hedge_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > hedge_cost_charge;
 	ColumnAccessor < mCFStaticData_0 > hedge_exp;
 	ColumnAccessor < mCFStaticData_0 > hedge_int_pmt;
 	ColumnAccessor < mCFStaticData_0 > hedge_inv_amt_bom;
 	ColumnAccessor < mCFStaticData_0 > hedge_inv_amt_eom;
 	ColumnAccessor < mCFStaticData_0 > hedge_liab_claims;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > hedge_notional_amt;
 	ColumnAccessor < mCFStaticData_0 > hedge_notional_amt_available;
 	ColumnAccessor < mCFStaticData_0 > hedge_opt_pmt;
 	ColumnAccessor < mCFStaticData_0 > hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_0 > index_val;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > liab_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_0 > liab_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_0 > long_strike;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_required;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_to_hedge;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_to_hedge_cap;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_to_hedge_index;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_to_hedge_long_strike;
 	ColumnAccessor < mCFStaticData_0 > notional_to_hedge;
 	ColumnAccessor < mCFStaticData_0 > opt_budget;
 	ColumnAccessor < mCFStaticData_0 > opt_budget_amt;
 	ColumnAccessor < mCFStaticData_0 > opt_payoff;
 	ColumnAccessor < mCFStaticData_0 > part_rate;
 	ColumnAccessor < mCFStaticData_0 > proj_tgt_hedge_stmt;
 	ColumnAccessor < mCFStaticData_0 > pv_charges;
 	ColumnAccessor < mCFStaticData_0 > pv_claims;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_hedge_flag;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_hedge_inv_amt;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_hedge_pmt;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_hedge_prof;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_hedge_transaction_cost;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_key_rate_1;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_key_rate_10;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_key_rate_2;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_key_rate_3;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_key_rate_4;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_key_rate_5;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_key_rate_6;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_key_rate_7;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_key_rate_8;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_key_rate_9;
 	ColumnAccessor < mCFStaticData_0 > rho_convex_parallel;
 	ColumnAccessor < mCFStaticData_0 > rho_hedge_flag;
 	ColumnAccessor < mCFStaticData_0 > rho_hedge_inv_amt;
 	ColumnAccessor < mCFStaticData_0 > rho_hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > rho_hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_0 > rho_hedge_pmt;
 	ColumnAccessor < mCFStaticData_0 > rho_hedge_prof;
 	ColumnAccessor < mCFStaticData_0 > rho_hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_0 > rho_hedge_transaction_cost;
 	ColumnAccessor < mCFStaticData_0 > rho_key_rate_1;
 	ColumnAccessor < mCFStaticData_0 > rho_key_rate_10;
 	ColumnAccessor < mCFStaticData_0 > rho_key_rate_2;
 	ColumnAccessor < mCFStaticData_0 > rho_key_rate_3;
 	ColumnAccessor < mCFStaticData_0 > rho_key_rate_4;
 	ColumnAccessor < mCFStaticData_0 > rho_key_rate_5;
 	ColumnAccessor < mCFStaticData_0 > rho_key_rate_6;
 	ColumnAccessor < mCFStaticData_0 > rho_key_rate_7;
 	ColumnAccessor < mCFStaticData_0 > rho_key_rate_8;
 	ColumnAccessor < mCFStaticData_0 > rho_key_rate_9;
 	ColumnAccessor < mCFStaticData_0 > rho_parallel;
 	ColumnAccessor < mCFStaticData_0 > short_strike;
 	ColumnAccessor < mCFStaticData_0 > startup;
 	ColumnAccessor < mCFStaticData_0 > valn_tgt_hedge_final;
 	ColumnAccessor < mCFStaticData_0 > valn_tgt_hedge_shock;
 	ColumnAccessor < mCFStaticData_0 > vega_hedge_flag;
 	ColumnAccessor < mCFStaticData_0 > vega_hedge_inv_amt;
 	ColumnAccessor < mCFStaticData_0 > vega_hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > vega_hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_0 > vega_hedge_pmt;
 	ColumnAccessor < mCFStaticData_0 > vega_hedge_prof;
 	ColumnAccessor < mCFStaticData_0 > vega_hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_0 > vega_hedge_transaction_cost;
 	ColumnAccessor < mCFStaticData_0 > vega_index_1;
 	ColumnAccessor < mCFStaticData_0 > vega_index_1_term_1;
 	ColumnAccessor < mCFStaticData_0 > vega_index_1_term_2;
 	ColumnAccessor < mCFStaticData_0 > vega_index_1_term_3;
 	ColumnAccessor < mCFStaticData_0 > vega_index_2;
 	ColumnAccessor < mCFStaticData_0 > vega_index_2_term_1;
 	ColumnAccessor < mCFStaticData_0 > vega_index_2_term_2;
 	ColumnAccessor < mCFStaticData_0 > vega_index_2_term_3;
 	ColumnAccessor < mCFStaticData_0 > vega_index_3;
 	ColumnAccessor < mCFStaticData_0 > vega_index_3_term_1;
 	ColumnAccessor < mCFStaticData_0 > vega_index_3_term_2;
 	ColumnAccessor < mCFStaticData_0 > vega_index_3_term_3;
 	ColumnAccessor < mCFStaticData_0 > vega_index_4;
 	ColumnAccessor < mCFStaticData_0 > vega_index_4_term_1;
 	ColumnAccessor < mCFStaticData_0 > vega_index_4_term_2;
 	ColumnAccessor < mCFStaticData_0 > vega_index_4_term_3;
 	ColumnAccessor < mCFStaticData_0 > vega_index_5;
 	ColumnAccessor < mCFStaticData_0 > vega_index_5_term_1;
 	ColumnAccessor < mCFStaticData_0 > vega_index_5_term_2;
 	ColumnAccessor < mCFStaticData_0 > vega_index_5_term_3;
 	ColumnAccessor < mCFStaticData_0 > vega_index_6;
 	ColumnAccessor < mCFStaticData_0 > vega_index_6_term_1;
 	ColumnAccessor < mCFStaticData_0 > vega_index_6_term_2;
 	ColumnAccessor < mCFStaticData_0 > vega_index_6_term_3;
 	ColumnAccessor < mCFStaticData_0 > vega_parallel;
//Column Definition END@2

 // Temporary Table...
HDG_GRP_COMP *sm_bond_is;
HDG_GRP_COMP *sm_bond_pv;
HDG_GRP_COMP *sm_bond_ym;
HDG_GRP_COMP *sm_mtg_is;
HDG_GRP_COMP *sm_mtg_pv;
HDG_GRP_COMP *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE HDG_GRP_COMP::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > calc_asset_greeks_defn;
  inline xstring	Get_calc_asset_greeks_defn() {
		return calc_asset_greeks_defn; }
  inline void Set_calc_asset_greeks_defn(const xstring &v) {
		calc_asset_greeks_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > calc_asset_greeks_timing_defn;
  inline xstring	Get_calc_asset_greeks_timing_defn() {
		return calc_asset_greeks_timing_defn; }
  inline void Set_calc_asset_greeks_timing_defn(const xstring &v) {
		calc_asset_greeks_timing_defn.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > decrem_id;
  inline xstring	Get_decrem_id() {
		return decrem_id; }
  inline void Set_decrem_id(const xstring &v) {
		decrem_id.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eqt_price_shock;
  inline double	Get_eqt_price_shock() {
		return eqt_price_shock; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > eqt_price_shock_defn;
  inline xstring	Get_eqt_price_shock_defn() {
		return eqt_price_shock_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > eqt_price_shock_id;
  inline xstring	Get_eqt_price_shock_id() {
		return eqt_price_shock_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eqt_vol_shock;
  inline double	Get_eqt_vol_shock() {
		return eqt_vol_shock; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > eqt_vol_shock_defn;
  inline xstring	Get_eqt_vol_shock_defn() {
		return eqt_vol_shock_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > eqt_vol_shock_id;
  inline xstring	Get_eqt_vol_shock_id() {
		return eqt_vol_shock_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > hedge_disc_rate_comp_id;
  inline xstring	Get_hedge_disc_rate_comp_id() {
		return hedge_disc_rate_comp_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_disc_rate_defn;
  inline xstring	Get_hedge_disc_rate_defn() {
		return hedge_disc_rate_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_disc_rate_fixed;
  inline double	Get_hedge_disc_rate_fixed() {
		return hedge_disc_rate_fixed; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > hedge_grp_asset_id;
  inline xstring	Get_hedge_grp_asset_id() {
		return hedge_grp_asset_id; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > hedge_grp_bucket_id;
  inline int	Get_hedge_grp_bucket_id() {
		return hedge_grp_bucket_id; }
  inline void Set_hedge_grp_bucket_id(const int &v) {
		hedge_grp_bucket_id.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > hedge_grp_count_id;
  inline int	Get_hedge_grp_count_id() {
		return hedge_grp_count_id; }
  inline void Set_hedge_grp_count_id(const int &v) {
		hedge_grp_count_id.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_crediting_defn;
  inline xstring	Get_hedge_grp_crediting_defn() {
		return hedge_grp_crediting_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > hedge_grp_crediting_mths;
  inline int	Get_hedge_grp_crediting_mths() {
		return hedge_grp_crediting_mths; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > hedge_grp_delta_hedge_asset_id;
  inline xstring	Get_hedge_grp_delta_hedge_asset_id() {
		return hedge_grp_delta_hedge_asset_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_delta_hedge_defn;
  inline xstring	Get_hedge_grp_delta_hedge_defn() {
		return hedge_grp_delta_hedge_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_delta_hedge_liab_shock_defn;
  inline xstring	Get_hedge_grp_delta_hedge_liab_shock_defn() {
		return hedge_grp_delta_hedge_liab_shock_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_delta_hedge_pct;
  inline double	Get_hedge_grp_delta_hedge_pct() {
		return hedge_grp_delta_hedge_pct; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > hedge_grp_delta_hedge_rebal_freq;
  inline int	Get_hedge_grp_delta_hedge_rebal_freq() {
		return hedge_grp_delta_hedge_rebal_freq; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_delta_hedge_strat_defn;
  inline xstring	Get_hedge_grp_delta_hedge_strat_defn() {
		return hedge_grp_delta_hedge_strat_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_delta_hedge_tolerance_dollar;
  inline double	Get_hedge_grp_delta_hedge_tolerance_dollar() {
		return hedge_grp_delta_hedge_tolerance_dollar; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_delta_hedge_tolerance_pct_liab_delta;
  inline double	Get_hedge_grp_delta_hedge_tolerance_pct_liab_delta() {
		return hedge_grp_delta_hedge_tolerance_pct_liab_delta; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_delta_hedge_transaction_costs_bps;
  inline double	Get_hedge_grp_delta_hedge_transaction_costs_bps() {
		return hedge_grp_delta_hedge_transaction_costs_bps; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_dyn_lever;
  inline xstring	Get_hedge_grp_dyn_lever() {
		return hedge_grp_dyn_lever; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > hedge_grp_gamma_vega_hedge_asset_id;
  inline xstring	Get_hedge_grp_gamma_vega_hedge_asset_id() {
		return hedge_grp_gamma_vega_hedge_asset_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_gamma_vega_hedge_defn;
  inline xstring	Get_hedge_grp_gamma_vega_hedge_defn() {
		return hedge_grp_gamma_vega_hedge_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_gamma_vega_hedge_liab_shock_defn;
  inline xstring	Get_hedge_grp_gamma_vega_hedge_liab_shock_defn() {
		return hedge_grp_gamma_vega_hedge_liab_shock_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_gamma_vega_hedge_pct;
  inline double	Get_hedge_grp_gamma_vega_hedge_pct() {
		return hedge_grp_gamma_vega_hedge_pct; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > hedge_grp_gamma_vega_hedge_rebal_freq;
  inline int	Get_hedge_grp_gamma_vega_hedge_rebal_freq() {
		return hedge_grp_gamma_vega_hedge_rebal_freq; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_gamma_vega_hedge_strat_defn;
  inline xstring	Get_hedge_grp_gamma_vega_hedge_strat_defn() {
		return hedge_grp_gamma_vega_hedge_strat_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_gamma_vega_hedge_tolerance_dollar;
  inline double	Get_hedge_grp_gamma_vega_hedge_tolerance_dollar() {
		return hedge_grp_gamma_vega_hedge_tolerance_dollar; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_gamma_vega_hedge_tolerance_pct_liab_gamma_vega;
  inline double	Get_hedge_grp_gamma_vega_hedge_tolerance_pct_liab_gamma_vega() {
		return hedge_grp_gamma_vega_hedge_tolerance_pct_liab_gamma_vega; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_gamma_vega_hedge_transaction_costs_bps;
  inline double	Get_hedge_grp_gamma_vega_hedge_transaction_costs_bps() {
		return hedge_grp_gamma_vega_hedge_transaction_costs_bps; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_gamma_vega_hedge_type_defn;
  inline xstring	Get_hedge_grp_gamma_vega_hedge_type_defn() {
		return hedge_grp_gamma_vega_hedge_type_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_gmab_defn;
  inline xstring	Get_hedge_grp_gmab_defn() {
		return hedge_grp_gmab_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_gmdb_defn;
  inline xstring	Get_hedge_grp_gmdb_defn() {
		return hedge_grp_gmdb_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_gmib_defn;
  inline xstring	Get_hedge_grp_gmib_defn() {
		return hedge_grp_gmib_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_gmwb_defn;
  inline xstring	Get_hedge_grp_gmwb_defn() {
		return hedge_grp_gmwb_defn; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > hedge_grp_id;
  inline xstring	Get_hedge_grp_id() {
		return hedge_grp_id; }
  inline void Set_hedge_grp_id(const xstring &v) {
		hedge_grp_id.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > hedge_grp_index;
  inline xstring	Get_hedge_grp_index() {
		return hedge_grp_index; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > hedge_grp_index_name;
  inline xstring	Get_hedge_grp_index_name() {
		return hedge_grp_index_name; }
  inline void Set_hedge_grp_index_name(const xstring &v) {
		hedge_grp_index_name.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > hedge_grp_index_term;
  inline xstring	Get_hedge_grp_index_term() {
		return hedge_grp_index_term; }
  inline void Set_hedge_grp_index_term(const xstring &v) {
		hedge_grp_index_term.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > hedge_grp_key_rate;
  inline xstring	Get_hedge_grp_key_rate() {
		return hedge_grp_key_rate; }
  inline void Set_hedge_grp_key_rate(const xstring &v) {
		hedge_grp_key_rate.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > hedge_grp_plan_codes;
  inline xstring	Get_hedge_grp_plan_codes() {
		return hedge_grp_plan_codes; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > hedge_grp_rate_term;
  inline double	Get_hedge_grp_rate_term() {
		return hedge_grp_rate_term; }
  inline void Set_hedge_grp_rate_term(const double &v) {
		hedge_grp_rate_term.setValue(v); }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > hedge_grp_rebal_freq;
  inline int	Get_hedge_grp_rebal_freq() {
		return hedge_grp_rebal_freq; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > hedge_grp_rho_convex_hedge_asset_id;
  inline xstring	Get_hedge_grp_rho_convex_hedge_asset_id() {
		return hedge_grp_rho_convex_hedge_asset_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_rho_convex_hedge_defn;
  inline xstring	Get_hedge_grp_rho_convex_hedge_defn() {
		return hedge_grp_rho_convex_hedge_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_rho_convex_hedge_liab_shock_defn;
  inline xstring	Get_hedge_grp_rho_convex_hedge_liab_shock_defn() {
		return hedge_grp_rho_convex_hedge_liab_shock_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_rho_convex_hedge_pct;
  inline double	Get_hedge_grp_rho_convex_hedge_pct() {
		return hedge_grp_rho_convex_hedge_pct; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > hedge_grp_rho_convex_hedge_rebal_freq;
  inline int	Get_hedge_grp_rho_convex_hedge_rebal_freq() {
		return hedge_grp_rho_convex_hedge_rebal_freq; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_rho_convex_hedge_strat_defn;
  inline xstring	Get_hedge_grp_rho_convex_hedge_strat_defn() {
		return hedge_grp_rho_convex_hedge_strat_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_rho_convex_hedge_tolerance_dollar;
  inline double	Get_hedge_grp_rho_convex_hedge_tolerance_dollar() {
		return hedge_grp_rho_convex_hedge_tolerance_dollar; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_rho_convex_hedge_tolerance_pct_liab_rho_convex;
  inline double	Get_hedge_grp_rho_convex_hedge_tolerance_pct_liab_rho_convex() {
		return hedge_grp_rho_convex_hedge_tolerance_pct_liab_rho_convex; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_rho_convex_hedge_transaction_costs_bps;
  inline double	Get_hedge_grp_rho_convex_hedge_transaction_costs_bps() {
		return hedge_grp_rho_convex_hedge_transaction_costs_bps; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > hedge_grp_rho_hedge_asset_id;
  inline xstring	Get_hedge_grp_rho_hedge_asset_id() {
		return hedge_grp_rho_hedge_asset_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_rho_hedge_defn;
  inline xstring	Get_hedge_grp_rho_hedge_defn() {
		return hedge_grp_rho_hedge_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_rho_hedge_liab_shock_defn;
  inline xstring	Get_hedge_grp_rho_hedge_liab_shock_defn() {
		return hedge_grp_rho_hedge_liab_shock_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_rho_hedge_pct;
  inline double	Get_hedge_grp_rho_hedge_pct() {
		return hedge_grp_rho_hedge_pct; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > hedge_grp_rho_hedge_rebal_freq;
  inline int	Get_hedge_grp_rho_hedge_rebal_freq() {
		return hedge_grp_rho_hedge_rebal_freq; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hedge_grp_rho_hedge_strat_defn;
  inline xstring	Get_hedge_grp_rho_hedge_strat_defn() {
		return hedge_grp_rho_hedge_strat_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_rho_hedge_tolerance_dollar;
  inline double	Get_hedge_grp_rho_hedge_tolerance_dollar() {
		return hedge_grp_rho_hedge_tolerance_dollar; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_rho_hedge_tolerance_pct_liab_rho;
  inline double	Get_hedge_grp_rho_hedge_tolerance_pct_liab_rho() {
		return hedge_grp_rho_hedge_tolerance_pct_liab_rho; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > hedge_grp_rho_hedge_transaction_costs_bps;
  inline double	Get_hedge_grp_rho_hedge_transaction_costs_bps() {
		return hedge_grp_rho_hedge_transaction_costs_bps; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > hedge_grp_yld_curve_id;
  inline xstring	Get_hedge_grp_yld_curve_id() {
		return hedge_grp_yld_curve_id; }
  inline void Set_hedge_grp_yld_curve_id(const xstring &v) {
		hedge_grp_yld_curve_id.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > independent_mp_defn;
  inline xstring	Get_independent_mp_defn() {
		return independent_mp_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > int_rate_shock;
  inline double	Get_int_rate_shock() {
		return int_rate_shock; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > int_rate_shock_defn;
  inline xstring	Get_int_rate_shock_defn() {
		return int_rate_shock_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > int_rate_shock_id;
  inline xstring	Get_int_rate_shock_id() {
		return int_rate_shock_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > phldr_shock;
  inline double	Get_phldr_shock() {
		return phldr_shock; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > phldr_shock_defn;
  inline xstring	Get_phldr_shock_defn() {
		return phldr_shock_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > phldr_shock_id;
  inline xstring	Get_phldr_shock_id() {
		return phldr_shock_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > scen_file_name_addn;
  inline xstring	Get_scen_file_name_addn() {
		return scen_file_name_addn; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > seg_id;
  inline xstring	Get_seg_id() {
		return seg_id; }
  inline void Set_seg_id(const xstring &v) {
		seg_id.setValue(v); }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > shock_freq;
  inline int	Get_shock_freq() {
		return shock_freq; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > shock_id;
  inline xstring	Get_shock_id() {
		return shock_id; }
  inline void Set_shock_id(const xstring &v) {
		shock_id.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > valn_hedge_final_results;
  inline xstring	Get_valn_hedge_final_results() {
		return valn_hedge_final_results; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > valn_hedge_results;
  inline xstring	Get_valn_hedge_results() {
		return valn_hedge_results; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > valn_scens_defn;
  inline xstring	Get_valn_scens_defn() {
		return valn_scens_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > valn_scens_to_run;
  inline int	Get_valn_scens_to_run() {
		return valn_scens_to_run; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > final_period;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > proj_date_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_date;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_yr;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > start_period;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(HDG_GRP_COMP* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Calculate Asset Greeks
#line 1 "calc_asset_greeks.hdg_grp_comp.for"
void calc_asset_greeks(int t, int greek_type, int greek_timing);

// Calculate PV of Claims & Charges for each MP
#line 1 "calc_pv_claims_charges.hdg_grp_comp.for"
void calc_pv_claims_charges(int mp, double &disc_claim_amt_ab_mp, double &disc_claim_amt_db_mp, 
								   double &disc_claim_amt_ib_mp, double &disc_claim_amt_wb_mp,
							       double &disc_claim_fee_ab_mp, double &disc_claim_fee_db_mp,
								   double &disc_claim_fee_ib_mp, double &disc_claim_fee_wb_mp);

// Delta Hedge Strategy
#line 1 "delta_hedge_strat.hdg_grp_comp.for"
void delta_hedge_strat(int t);

// Gamma Hedge Strategy
#line 1 "gamma_hedge_strat.hdg_grp_comp.for"
void gamma_hedge_strat(int t);

// Get Hedge Valuation Final Results
#line 1 "get_hedge_valn_final_results.hdg_grp_comp.for"
void get_hedge_valn_final_results(void);

// Get Hedge Valuation Results
#line 1 "get_hedge_valn_results.hdg_grp_comp.for"
void get_hedge_valn_results(void);

// Get Purchase Asset Index Name
#line 1 "get_purch_asset_index_name.hdg_grp_comp.for"
xstring get_purch_asset_index_name(int seg_num, xstring index_name, xstring hedge_asset_id);

// Resize Hedge Valuation Array
#line 1 "resize_hedge_valn_array.hdg_grp_comp.for"
void resize_hedge_valn_array(void);

// Rho Convexity Hedge Strategy
#line 1 "rho_convex_hedge_strat.hdg_grp_comp.for"
void rho_convex_hedge_strat(int t);

// Rho Hedge Strategy
#line 1 "rho_hedge_strat.hdg_grp_comp.for"
void rho_hedge_strat(int t);

// Sum Over Assets
#line 1 "sum_over_assets.hdg_grp_comp.for"
double sum_over_assets(const xstring &colname, int t, int greek_type, int sum_over_timing);

// Sum Over Liabilities
#line 1 "sum_over_liabilities.hdg_grp_comp.for"
double sum_over_liabilities(const xstring &colname, int t, int sum_timing);

// Vega Hedge Strategy
#line 1 "vega_hedge_strat.hdg_grp_comp.for"
void vega_hedge_strat(int t);


//factory
static HDG_GRP_COMP* makeThis(int isSubmodel, ModelClass *owner, HDG_GRP_COMP* peer, 
					int mainRebase, const xstring &name, HDG_GRP_COMP_persistent_object* arrayTemplate);

//constructor
HDG_GRP_COMP(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
HDG_GRP_COMP(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~HDG_GRP_COMP();


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
class HDG_GRP_COMP_persistent_object : public HDG_GRP_COMP {


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

	void findTargetColumns() {HDG_GRP_COMP::findTargetColumns();}
	void createAllShare() {
		HDG_GRP_COMP::createAllShare();
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
	HDG_GRP_COMP *&sm_bond_is; //
	HDG_GRP_COMP *&sm_bond_pv; //
	HDG_GRP_COMP *&sm_bond_ym; //
	HDG_GRP_COMP *&sm_mtg_is; //
	HDG_GRP_COMP *&sm_mtg_pv; //
	HDG_GRP_COMP *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~HDG_GRP_COMP_persistent_object();

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
static HDG_GRP_COMP_persistent_object* makeThis(int isSubmodel, ModelClass *owner, HDG_GRP_COMP* peer, 
					int mainRebase, const xstring &name, HDG_GRP_COMP_persistent_object* arrayTemplate, bool fixedArray);

//constructor
HDG_GRP_COMP_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
