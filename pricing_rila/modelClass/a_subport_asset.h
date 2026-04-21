#ifndef __A_SUBPORT_ASSET_H_
#define __A_SUBPORT_ASSET_H_
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



namespace A_SUBPORT_ASSET_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class A_SUBPORT_ASSET_persistent_object;
class A_SUBPORT_ASSET : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(A_SUBPORT_ASSET); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;

typedef map <int, long, less <int> > mpmap;
xstring asset_sub_port_description;
double min_size_existing;
double min_size_purchase;
int sale_priority;
double rebal_tolerance_pct;
double rebal_annual_turnover_pct_max;
double rebal_annual_turnover_pct_min;
double inv_exp_pct;

	void init_(){
		

min_size_existing = 0.0;
min_size_purchase = 0.0;
sale_priority = 0;
rebal_tolerance_pct = 0.0;
rebal_annual_turnover_pct_max = 0.0;
rebal_annual_turnover_pct_min = 0.0;
inv_exp_pct = 0.0;

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
#ifdef __CREATE_EPL_LIAB_CLASS_
	EPL_LIAB	*company_liab_epl;
	EPL_LIAB	*&epl;
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
 	ColumnAccessor < mCFStaticData_0 > accr_div;
 	ColumnAccessor < mCFStaticData_0 > accr_inc;
 	ColumnAccessor < mCFStaticData_0 > accr_int_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > accr_int_dflt;
 	ColumnAccessor < mCFStaticData_0 > accr_int_rent;
 	ColumnAccessor < mCFStaticData_0 > accr_int_rent_inv;
 	ColumnAccessor < mCFStaticData_0 > asset_yld;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_denom;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_numer;
 	ColumnAccessor < mCFStaticData_0 > base_cost_basis;
 	ColumnAccessor < mCFStaticData_0 > bk_val;
 	ColumnAccessor < mCFStaticData_0 > bk_val_incr;
 	ColumnAccessor < mCFStaticData_0 > bk_val_inv;
 	ColumnAccessor < mCFStaticData_0 > bk_val_plus_accr_int;
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > cap_gain;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_from_sale;
 	ColumnAccessor < mCFStaticData_0 > cash_flow;
 	ColumnAccessor < mCFStaticData_0 > cost_basis;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_accrual;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_dflt;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_growth;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_incr_accr_div;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_incr_appreciation;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_incr_index_asset_turnover;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_opt_pmt;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_purch;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_sale;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_sched_prin_pmt;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_transaction;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_transfer;
 	ColumnAccessor < mCFStaticData_0 > depreciation;
 	ColumnAccessor < mCFStaticData_0 > dflt_amt;
 	ColumnAccessor < mCFStaticData_0 > eff_dur;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > int_div_and_rent;
 	ColumnAccessor < mCFStaticData_0 > int_net;
 	ColumnAccessor < mCFStaticData_0 > inv_exp;
 	ColumnAccessor < mCFStaticData_0 > inv_exp_inv;
 	ColumnAccessor < mCFStaticData_0 > inv_exp_tax_exempt;
 	ColumnAccessor < mCFStaticData_0 > mkt_val;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_cost_basis_incr;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_for_eff_dur;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_times_eff_dur;
 	ColumnAccessor < mCFStaticData_0 > notional_amt;
 	ColumnAccessor < mCFStaticData_0 > opt_inc;
 	ColumnAccessor < mCFStaticData_0 > opt_pmt;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain_net;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain_opt_pmt;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain_prin_pmt;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain_sale;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain_turnover;
 	ColumnAccessor < mCFStaticData_0 > sale_inc;
 	ColumnAccessor < mCFStaticData_0 > sched_prin_pmt;
 	ColumnAccessor < mCFStaticData_0 > startup;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_hidden;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_incr;
 	ColumnAccessor < mCFStaticData_0 > unrealzd_cap_gain_released_on_sale;
//Column Definition END@2

 // Temporary Table...
A_SUBPORT_ASSET *sm_bond_is;
A_SUBPORT_ASSET *sm_bond_pv;
A_SUBPORT_ASSET *sm_bond_ym;
A_SUBPORT_ASSET *sm_mtg_is;
A_SUBPORT_ASSET *sm_mtg_pv;
A_SUBPORT_ASSET *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE A_SUBPORT_ASSET::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > asset_source_type;
  inline xstring	Get_asset_source_type() {
		return asset_source_type; }
  inline void Set_asset_source_type(const xstring &v) {
		asset_source_type.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > asset_type;
  inline xstring	Get_asset_type() {
		return asset_type; }
  inline void Set_asset_type(const xstring &v) {
		asset_type.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > dur_match_defn;
  inline xstring	Get_dur_match_defn() {
		return dur_match_defn; }
  inline void Set_dur_match_defn(const xstring &v) {
		dur_match_defn.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > fast_stat_calc_aig;
  inline xstring	Get_fast_stat_calc_aig() {
		return fast_stat_calc_aig; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > inv_tgt_pct;
  inline double	Get_inv_tgt_pct() {
		return inv_tgt_pct; }
  inline void Set_inv_tgt_pct(const double &v) {
		inv_tgt_pct.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > inv_tgt_pct_curr_strat;
  inline double	Get_inv_tgt_pct_curr_strat() {
		return inv_tgt_pct_curr_strat; }
  inline void Set_inv_tgt_pct_curr_strat(const double &v) {
		inv_tgt_pct_curr_strat.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > inv_tgt_pct_dur_match;
  inline double	Get_inv_tgt_pct_dur_match() {
		return inv_tgt_pct_dur_match; }
  inline void Set_inv_tgt_pct_dur_match(const double &v) {
		inv_tgt_pct_dur_match.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > port_defn;
  inline xstring	Get_port_defn() {
		return port_defn; }
  inline void Set_port_defn(const xstring &v) {
		port_defn.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > purch_asset_weight_sum;
  inline double	Get_purch_asset_weight_sum() {
		return purch_asset_weight_sum; }
  inline void Set_purch_asset_weight_sum(const double &v) {
		purch_asset_weight_sum.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > purch_asset_weight_sum_curr_strat;
  inline double	Get_purch_asset_weight_sum_curr_strat() {
		return purch_asset_weight_sum_curr_strat; }
  inline void Set_purch_asset_weight_sum_curr_strat(const double &v) {
		purch_asset_weight_sum_curr_strat.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > purch_asset_weight_sum_dur_match;
  inline double	Get_purch_asset_weight_sum_dur_match() {
		return purch_asset_weight_sum_dur_match; }
  inline void Set_purch_asset_weight_sum_dur_match(const double &v) {
		purch_asset_weight_sum_dur_match.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > purch_asset_weight_sum_normalzd;
  inline double	Get_purch_asset_weight_sum_normalzd() {
		return purch_asset_weight_sum_normalzd; }
  inline void Set_purch_asset_weight_sum_normalzd(const double &v) {
		purch_asset_weight_sum_normalzd.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > purch_asset_weight_sum_normalzd_curr_strat;
  inline double	Get_purch_asset_weight_sum_normalzd_curr_strat() {
		return purch_asset_weight_sum_normalzd_curr_strat; }
  inline void Set_purch_asset_weight_sum_normalzd_curr_strat(const double &v) {
		purch_asset_weight_sum_normalzd_curr_strat.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > purch_asset_weight_sum_normalzd_dur_match;
  inline double	Get_purch_asset_weight_sum_normalzd_dur_match() {
		return purch_asset_weight_sum_normalzd_dur_match; }
  inline void Set_purch_asset_weight_sum_normalzd_dur_match(const double &v) {
		purch_asset_weight_sum_normalzd_dur_match.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > seg_id;
  inline xstring	Get_seg_id() {
		return seg_id; }
  inline void Set_seg_id(const xstring &v) {
		seg_id.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > sub_port_id;
  inline xstring	Get_sub_port_id() {
		return sub_port_id; }
  inline void Set_sub_port_id(const xstring &v) {
		sub_port_id.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > sub_port_updated_flag;
  inline int	Get_sub_port_updated_flag() {
		return sub_port_updated_flag; }
  inline void Set_sub_port_updated_flag(const int &v) {
		sub_port_updated_flag.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > sub_ports_to_initialize_for_sale;
  inline int	Get_sub_ports_to_initialize_for_sale() {
		return sub_ports_to_initialize_for_sale; }
  inline void Set_sub_ports_to_initialize_for_sale(const int &v) {
		sub_ports_to_initialize_for_sale.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > sub_ports_to_sell;
  inline int	Get_sub_ports_to_sell() {
		return sub_ports_to_sell; }
  inline void Set_sub_ports_to_sell(const int &v) {
		sub_ports_to_sell.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > total_weights_fund_match;
  inline double	Get_total_weights_fund_match() {
		return total_weights_fund_match; }
  inline void Set_total_weights_fund_match(const double &v) {
		total_weights_fund_match.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(A_SUBPORT_ASSET* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Remove characters from a string
#line 1 "remove_chars_from_string.a_subport_asset.for"
xstring remove_chars_from_string(const xstring asset_sub_port_desc, const xstring chars_to_remove = ":");

// Asset Sub Portfolio Report Requested
#line 1 "sub_port_rpt_requested.a_subport_asset.for"
xstring sub_port_rpt_requested();

// Sum Over Assets in Sub Portfolio Submodel
#line 1 "sum_over_assets_subport.a_subport_asset.for"
double sum_over_assets_subport(const xstring &colname, int t, int sub_port_id, int exist_asset_status, int asset_fund_index, int sum_over_timing);


//factory
static A_SUBPORT_ASSET* makeThis(int isSubmodel, ModelClass *owner, A_SUBPORT_ASSET* peer, 
					int mainRebase, const xstring &name, A_SUBPORT_ASSET_persistent_object* arrayTemplate);

//constructor
A_SUBPORT_ASSET(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
A_SUBPORT_ASSET(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~A_SUBPORT_ASSET();


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
class A_SUBPORT_ASSET_persistent_object : public A_SUBPORT_ASSET {


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

	void findTargetColumns() {A_SUBPORT_ASSET::findTargetColumns();}
	void createAllShare() {
		A_SUBPORT_ASSET::createAllShare();
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
	A_SUBPORT_ASSET *&sm_bond_is; //
	A_SUBPORT_ASSET *&sm_bond_pv; //
	A_SUBPORT_ASSET *&sm_bond_ym; //
	A_SUBPORT_ASSET *&sm_mtg_is; //
	A_SUBPORT_ASSET *&sm_mtg_pv; //
	A_SUBPORT_ASSET *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~A_SUBPORT_ASSET_persistent_object();

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
static A_SUBPORT_ASSET_persistent_object* makeThis(int isSubmodel, ModelClass *owner, A_SUBPORT_ASSET* peer, 
					int mainRebase, const xstring &name, A_SUBPORT_ASSET_persistent_object* arrayTemplate, bool fixedArray);

//constructor
A_SUBPORT_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
