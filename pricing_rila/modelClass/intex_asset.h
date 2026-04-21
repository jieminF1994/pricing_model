#ifndef __INTEX_ASSET_H_
#define __INTEX_ASSET_H_
#pragma warning ( disable : 4819 )

#define TRANCHE_ARRAY_DIMENSION 481

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



namespace INTEX_ASSET_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class INTEX_ASSET_persistent_object;
class INTEX_ASSET : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(INTEX_ASSET); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;

bool issue_messages;
int valuation_period;
int loaded_proj_task_loop;
int is_intex_projection;
int preliminary_projection_complete;
//intex cash flow variables
double intex_principal_payment;
double intex_interest_payment;
double intex_principal_balance;
double intex_cashflow;

double principal[TRANCHE_ARRAY_DIMENSION];
double balance[TRANCHE_ARRAY_DIMENSION];
double interest[TRANCHE_ARRAY_DIMENSION];

SmartArray <double> prepmt_exercise_pct;
SmartArray <double> prepmt_nonfinancial_adj;
SmartArray <double> prepmt_nonfinancial_seasonality_addn;
SmartArray <double> prepmt_seasoning_since_issue_mult;

SmartArray <double> psa_base_rate;

	void init_(){
		

issue_messages = false;
is_intex_projection = 0;
preliminary_projection_complete = 0;
loaded_proj_task_loop = -1;
valuation_period = -1;
intex_principal_payment = 0;
intex_interest_payment = 0;
intex_principal_balance = 0;
intex_cashflow = 0;

memset(principal, 0, TRANCHE_ARRAY_DIMENSION * sizeof(double));
memset(interest, 0, TRANCHE_ARRAY_DIMENSION * sizeof(double));
memset(balance, 0, TRANCHE_ARRAY_DIMENSION * sizeof(double));

		bIsInit = true;
	}
	void deInit_(){

close_translation_tbl();
unload_library();

	}

#ifdef __CREATE_ADCO_ASSET_CLASS_
	ADCO_ASSET	*company_asset_adco;
	ADCO_ASSET	*&adco;
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
	ASSET_ASSET	*company_asset;
	ASSET_ASSET	*&asset;
#endif
#ifdef __CREATE_EPL_LIAB_CLASS_
	EPL_LIAB	*company_liab_epl;
	EPL_LIAB	*&epl;
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
	FIA_LIAB	*company_liab_fia;
	FIA_LIAB	*&fia;
#endif
#ifdef __CREATE_INTEX_ASSET_CLASS_
	INTEX_ASSET	*company_asset_intex;
	INTEX_ASSET	*&intex;
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
 	ColumnAccessor < mCFStaticData_0 > active_tranche_flag;
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > finalize;
 	ColumnAccessor < mCFStaticData_0 > get_collateral_prepmt;
 	ColumnAccessor < mCFStaticData_0 > get_tranche_accr_int;
 	ColumnAccessor < mCFStaticData_0 > get_tranche_accr_int_bef_prepmt;
 	ColumnAccessor < mCFStaticData_0 > get_tranche_bal;
 	ColumnAccessor < mCFStaticData_0 > get_tranche_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > get_tranche_int_pmt;
 	ColumnAccessor < mCFStaticData_0 > get_tranche_mths_to_reset;
 	ColumnAccessor < mCFStaticData_0 > get_tranche_prin_pmt;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > startup;
//Column Definition END@2

 // Temporary Table...
INTEX_ASSET *sm_bond_is;
INTEX_ASSET *sm_bond_pv;
INTEX_ASSET *sm_bond_ym;
INTEX_ASSET *sm_mtg_is;
INTEX_ASSET *sm_mtg_pv;
INTEX_ASSET *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE INTEX_ASSET::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > adco_category_id;
  inline xstring	Get_adco_category_id() {
		return adco_category_id; }
  inline void Set_adco_category_id(const xstring &v) {
		adco_category_id.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > asset_defn;
  inline xstring	Get_asset_defn() {
		return asset_defn; }
  inline void Set_asset_defn(const xstring &v) {
		asset_defn.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_detail_rpt_asset_id;
  inline xstring	Get_asset_detail_rpt_asset_id() {
		return asset_detail_rpt_asset_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_detail_rpt_defn;
  inline xstring	Get_asset_detail_rpt_defn() {
		return asset_detail_rpt_defn; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > asset_detail_rpt_file;
  inline xstring	Get_asset_detail_rpt_file() {
		return asset_detail_rpt_file; }
  inline void Set_asset_detail_rpt_file(const xstring &v) {
		asset_detail_rpt_file.setValue(v); }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > asset_detail_rpt_final_period;
  inline int	Get_asset_detail_rpt_final_period() {
		return asset_detail_rpt_final_period; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > asset_detail_rpt_start_period;
  inline int	Get_asset_detail_rpt_start_period() {
		return asset_detail_rpt_start_period; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > asset_id;
  inline xstring	Get_asset_id() {
		return asset_id; }
  inline void Set_asset_id(const xstring &v) {
		asset_id.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > balloon_extension;
  inline xstring	Get_balloon_extension() {
		return balloon_extension; }
  inline void Set_balloon_extension(const xstring &v) {
		balloon_extension.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > bk_val_defn;
  inline xstring	Get_bk_val_defn() {
		return bk_val_defn; }
  inline void Set_bk_val_defn(const xstring &v) {
		bk_val_defn.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > category_id;
  inline xstring	Get_category_id() {
		return category_id; }
  inline void Set_category_id(const xstring &v) {
		category_id.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > cmo_dll;
  inline xstring	Get_cmo_dll() {
		return cmo_dll; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > cmo_dll_64;
  inline xstring	Get_cmo_dll_64() {
		return cmo_dll_64; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > cost_basis_defn;
  inline xstring	Get_cost_basis_defn() {
		return cost_basis_defn; }
  inline void Set_cost_basis_defn(const xstring &v) {
		cost_basis_defn.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > cusip_deal_translation_path;
  inline xstring	Get_cusip_deal_translation_path() {
		return cusip_deal_translation_path; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > int_diff_defn;
  inline xstring	Get_int_diff_defn() {
		return int_diff_defn; }
  inline void Set_int_diff_defn(const xstring &v) {
		int_diff_defn.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > int_rate_diff_array_size;
  inline int	Get_int_rate_diff_array_size() {
		return int_rate_diff_array_size; }
  inline void Set_int_rate_diff_array_size(const int &v) {
		int_rate_diff_array_size.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > int_rate_diff_max;
  inline double	Get_int_rate_diff_max() {
		return int_rate_diff_max; }
  inline void Set_int_rate_diff_max(const double &v) {
		int_rate_diff_max.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > int_rate_diff_min;
  inline double	Get_int_rate_diff_min() {
		return int_rate_diff_min; }
  inline void Set_int_rate_diff_min(const double &v) {
		int_rate_diff_min.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > io_po_defn;
  inline xstring	Get_io_po_defn() {
		return io_po_defn; }
  inline void Set_io_po_defn(const xstring &v) {
		io_po_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > prepmt_defn;
  inline xstring	Get_prepmt_defn() {
		return prepmt_defn; }
  inline void Set_prepmt_defn(const xstring &v) {
		prepmt_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > prepmt_model_defn;
  inline xstring	Get_prepmt_model_defn() {
		return prepmt_model_defn; }
  inline void Set_prepmt_model_defn(const xstring &v) {
		prepmt_model_defn.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > prepmt_nonfinancial_pct;
  inline double	Get_prepmt_nonfinancial_pct() {
		return prepmt_nonfinancial_pct; }
  inline void Set_prepmt_nonfinancial_pct(const double &v) {
		prepmt_nonfinancial_pct.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > proj_defn;
  inline xstring	Get_proj_defn() {
		return proj_defn; }
  inline void Set_proj_defn(const xstring &v) {
		proj_defn.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > proj_period_last;
  inline int	Get_proj_period_last() {
		return proj_period_last; }
  inline void Set_proj_period_last(const int &v) {
		proj_period_last.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > refinancing_cost_pct;
  inline double	Get_refinancing_cost_pct() {
		return refinancing_cost_pct; }
  inline void Set_refinancing_cost_pct(const double &v) {
		refinancing_cost_pct.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > refinancing_rate_defn;
  inline xstring	Get_refinancing_rate_defn() {
		return refinancing_rate_defn; }
  inline void Set_refinancing_rate_defn(const xstring &v) {
		refinancing_rate_defn.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > refinancing_rate_scen_addn;
  inline double	Get_refinancing_rate_scen_addn() {
		return refinancing_rate_scen_addn; }
  inline void Set_refinancing_rate_scen_addn(const double &v) {
		refinancing_rate_scen_addn.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > refinancing_rate_scen_mult;
  inline double	Get_refinancing_rate_scen_mult() {
		return refinancing_rate_scen_mult; }
  inline void Set_refinancing_rate_scen_mult(const double &v) {
		refinancing_rate_scen_mult.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > refinancing_rate_scen_yr;
  inline double	Get_refinancing_rate_scen_yr() {
		return refinancing_rate_scen_yr; }
  inline void Set_refinancing_rate_scen_yr(const double &v) {
		refinancing_rate_scen_yr.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > shift_defn;
  inline xstring	Get_shift_defn() {
		return shift_defn; }
  inline void Set_shift_defn(const xstring &v) {
		shift_defn.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > asset_detail_rpt_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > commencement_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > final_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > get_collateral_num_of_pools;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > get_tranche_cdu_mths_offset;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > get_tranche_days_accr;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > get_tranche_freqs;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > get_tranche_maturity_day;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > get_tranche_maturity_period;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > output_file;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > output_path;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > proj_date_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_yr;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > start_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > tranche_rate_defn;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > use_eom_scen_rates;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(INTEX_ASSET* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Cash Flow Projection
#line 1 "cash_flow_proj.intex_asset.for"
void cash_flow_proj(int t);

// Category Refinancing Rate
#line 1 "category_refinancing_rate.intex_asset.for"
double category_refinancing_rate(int t, int months_to_maturity, int return_rate_basis, int shift_defn);

// Clear Asset Data
#line 1 "clear_asset_data.intex_asset.for"
void clear_asset_data(void);

// Clear Collateral Pool Data
#line 1 "clear_collateral_pool_data.intex_asset.for"
void clear_collateral_pool_data();

// Close Translation Table
#line 1 "close_translation_tbl.intex_asset.for"
void close_translation_tbl();

// Collateral Callback
#line 1 "collat_callback.intex_asset.for"
void __cdecl collat_callback(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, double *vcpprincipal, double *vcpinterest, double *vcpcashflow, double *vcpbalance, int month);

// Collateral Pool Cash Flow
#line 1 "cp_cash_flow.intex_asset.for"
void __cdecl cp_cash_flow(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, double *vcpprincipal, double *vcpinterest, double *vcpcashflow, double *vcpbalance, int month);

// Collateral Pool Detail
#line 1 "cp_detail.intex_asset.for"
void __cdecl cp_detail(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, double *vcpprincipal, double *vcpinterest, double *vcpcashflow, double *vcpbalance, int month);

// Collateral Pool Refinancing Rate
#line 1 "cp_refinancing_rate.intex_asset.for"
void __cdecl cp_refinancing_rate(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool);

// Database Check
#line 1 "database_check.intex_asset.for"
int database_check (int type);

// Forecast Adjustment Weighted Average Coupon Rate
#line 1 "forecast_adj_wac_rate.intex_asset.for"
void forecast_adj_wac_rate(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, int offset);

// Free Pool Data
#line 1 "free_pool_data.intex_asset.for"
void __cdecl free_pool_data(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool);

// Get Loan State
#line 1 "get_loan_state.intex_asset.for"
void get_loan_state(char *loan_state, SmartArray<double> &state_vector);

// Get Tranche Modified Duration
#line 1 "get_tranche_modified_dur.intex_asset.for"
double get_tranche_modified_dur(int t, double par_val, double mkt_val);

// Get Tranche Weighted Average Life
#line 1 "get_tranche_wal.intex_asset.for"
double get_tranche_wal(int t, const xstring & proj_type, double par_val, double accr_int);

// Index Rate
#line 1 "index_rate.intex_asset.for"
double __cdecl index_rate(struct _ICMO *icmop, int ith_index, int ith_month);

// Initial Deal Detail
#line 1 "init_deal_detail.intex_asset.for"
void init_deal_detail(void);

// Initial Pool Detail
#line 1 "init_pool_detail.intex_asset.for"
void __cdecl init_pool_detail(struct _ICMO * icmop, char * dealname, struct _POOL_INFO * pip, int ith_pool);

// Initialize Asset
#line 1 "initialize_asset.intex_asset.for"
int initialize_asset(void);

// Initialize Pool Data
#line 1 "initialize_pool_data.intex_asset.for"
void __cdecl initialize_pool_data(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool);

// Initialize Yield Curve
#line 1 "initialize_yld_curve.intex_asset.for"
void initialize_yld_curve(void);

// Interest Savings Present Value Cash Flow Setup
#line 1 "int_savings_pv_cash_flow_setup.intex_asset.for"
void int_savings_pv_cash_flow_setup(int t);

// Load Library
#line 1 "load_library.intex_asset.for"
void load_library();

// Market Value Cash Flow Projection
#line 1 "mkt_val_cash_flow_proj.intex_asset.for"
void mkt_val_cash_flow_proj(int t, const xstring & proj_type, double par_val);

// Net Yield Cash Flow Projection
#line 1 "net_yld_cash_flow_proj.intex_asset.for"
void net_yld_cash_flow_proj(int t);

// Open Translation Table
#line 1 "open_translation_tbl.intex_asset.for"
int open_translation_tbl();

// Path Directory Change
#line 1 "path_directory_change.intex_asset.for"
void path_directory_change(char *zDestPath, char *zSourcePath, char *zNewDirectory);

// Preliminary Projection
#line 1 "prelim_proj.intex_asset.for"
int prelim_proj(void);

// Prepayment Rate
#line 1 "prepmt_rate.intex_asset.for"
double __cdecl prepmt_rate(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, int curper, int curmonth);

// Prepayment Setup
#line 1 "prepmt_setup.intex_asset.for"
void __cdecl prepmt_setup(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool);

// Resets Off
#line 1 "resets_off.intex_asset.for"
void __cdecl resets_off(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool);

// Resets On
#line 1 "resets_on.intex_asset.for"
void __cdecl resets_on(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool);

// Restore Pool Data
#line 1 "restore_pool_data.intex_asset.for"
void __cdecl restore_pool_data(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool);

// Save Pool Data
#line 1 "save_pool_data.intex_asset.for"
void __cdecl save_pool_data(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool);

// Setup Asset Data
#line 1 "setup_asset_data.intex_asset.for"
int setup_asset_data(void);

// Setup Collateral Pool Data
#line 1 "setup_cp_data.intex_asset.for"
void setup_cp_data(int setup);

// Setup PSA Base Rate
#line 1 "setup_psa_base_rate.intex_asset.for"
void setup_psa_base_rate();

// Setup Yield Curve
#line 1 "setup_yld_curve.intex_asset.for"
void setup_yld_curve(int t, int shift_defn);

// Tranche Detail
#line 1 "tranche_detail.intex_asset.for"
void tranche_detail(int t, int write_projection_header);

// Unload Library
#line 1 "unload_library.intex_asset.for"
void unload_library();

// Valid Asset Flag
#line 1 "valid_asset_flag.intex_asset.for"
int valid_asset_flag(const xstring &project_asset, xstring &error_message);


//factory
static INTEX_ASSET* makeThis(int isSubmodel, ModelClass *owner, INTEX_ASSET* peer, 
					int mainRebase, const xstring &name, INTEX_ASSET_persistent_object* arrayTemplate);

//constructor
INTEX_ASSET(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
INTEX_ASSET(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~INTEX_ASSET();


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
class INTEX_ASSET_persistent_object : public INTEX_ASSET {


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

	void findTargetColumns() {INTEX_ASSET::findTargetColumns();}
	void createAllShare() {
		INTEX_ASSET::createAllShare();
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
	INTEX_ASSET *&sm_bond_is; //
	INTEX_ASSET *&sm_bond_pv; //
	INTEX_ASSET *&sm_bond_ym; //
	INTEX_ASSET *&sm_mtg_is; //
	INTEX_ASSET *&sm_mtg_pv; //
	INTEX_ASSET *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~INTEX_ASSET_persistent_object();

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
static INTEX_ASSET_persistent_object* makeThis(int isSubmodel, ModelClass *owner, INTEX_ASSET* peer, 
					int mainRebase, const xstring &name, INTEX_ASSET_persistent_object* arrayTemplate, bool fixedArray);

//constructor
INTEX_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
