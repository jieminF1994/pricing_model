#ifndef __EPA_ASSET_H_
#define __EPA_ASSET_H_
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



namespace EPA_ASSET_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class EPA_ASSET_persistent_object;
class EPA_ASSET : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(EPA_ASSET); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;

int sequence_id;
Schedule * EPAData;
int epa_last_cash_flow_period;
bool no_cash_flows_in_epa_file;
SmartArray <SmartArray <double> > epa_values;
double init_yld_numer;
double init_dflt_amt;
StrEnum::EnumValue port_defn;
map <xstring, long, less <xstring> > sched_byte_pos;

	void init_(){
		

sequence_id = 0;
epa_last_cash_flow_period = -1;
no_cash_flows_in_epa_file = false;
init_yld_numer = 0.0;
init_dflt_amt = 0.0;
port_defn = INVESTMENT;

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
#ifdef __CREATE_EPA_ASSET_CLASS_
	EPA_ASSET	*company_asset_epa;
	EPA_ASSET	*&epa;
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
 	ColumnAccessor < mCFStaticData_0 > accr_inc;
 	ColumnAccessor < mCFStaticData_0 > accr_int;
 	ColumnAccessor < mCFStaticData_0 > accr_int_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > accr_int_bef_fund_match_sale;
 	ColumnAccessor < mCFStaticData_0 > accr_int_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > accr_int_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > accr_int_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > accr_int_dflt;
 	ColumnAccessor < mCFStaticData_0 > accr_int_rent;
 	ColumnAccessor < mCFStaticData_0 > accr_int_sold;
 	ColumnAccessor < mCFStaticData_0 > asset_min_size_sale_flag;
 	ColumnAccessor < mCFStaticData_0 > avr_basic_contribn;
 	ColumnAccessor < mCFStaticData_0 > avr_basic_contribn_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_max;
 	ColumnAccessor < mCFStaticData_0 > avr_max_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_obj;
 	ColumnAccessor < mCFStaticData_0 > avr_obj_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_realzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > bk_val;
 	ColumnAccessor < mCFStaticData_0 > bk_val_bef_fund_match_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_val_plus_accr_int_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_from_sale;
 	ColumnAccessor < mCFStaticData_0 > cash_flow;
 	ColumnAccessor < mCFStaticData_0 > cost_basis;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_accrual;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_dflt;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_sold;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > dflt_amt;
 	ColumnAccessor < mCFStaticData_0 > dflt_pct;
 	ColumnAccessor < mCFStaticData_0 > dur_val;
 	ColumnAccessor < mCFStaticData_0 > eff_dur;
 	ColumnAccessor < mCFStaticData_0 > epa_pct_remaining;
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
 	ColumnAccessor < mCFStaticData_0 > mkt_val_sold;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_times_dur_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_times_dur_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_times_eff_dur;
 	ColumnAccessor < mCFStaticData_0 > notional_amt;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_bef_fund_match_sale;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_bef_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_bef_rebal_sale;
 	ColumnAccessor < mCFStaticData_0 > notional_amt_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > opt_inc;
 	ColumnAccessor < mCFStaticData_0 > opt_pmt;
 	ColumnAccessor < mCFStaticData_0 > rbc_c1;
 	ColumnAccessor < mCFStaticData_0 > rbc_c1_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain_opt_pmt;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_gain_sale;
 	ColumnAccessor < mCFStaticData_0 > realzd_cap_loss_dflt;
 	ColumnAccessor < mCFStaticData_0 > remaining_pct_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > sched_prin_pmt;
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
 	ColumnAccessor < mCFStaticData_0 > yld_denom;
 	ColumnAccessor < mCFStaticData_0 > yld_numer;
//Column Definition END@2

 // Temporary Table...
EPA_ASSET *sm_bond_is;
EPA_ASSET *sm_bond_pv;
EPA_ASSET *sm_bond_ym;
EPA_ASSET *sm_mtg_is;
EPA_ASSET *sm_mtg_pv;
EPA_ASSET *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE EPA_ASSET::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_defn;
  inline xstring	Get_asset_defn() {
		return asset_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_id;
  inline xstring	Get_asset_id() {
		return asset_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > avr_contribn_pct;
  inline double	Get_avr_contribn_pct() {
		return avr_contribn_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > avr_max_pct;
  inline double	Get_avr_max_pct() {
		return avr_max_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > avr_obj_pct;
  inline double	Get_avr_obj_pct() {
		return avr_obj_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > category_id;
  inline xstring	Get_category_id() {
		return category_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > data_validation_defn;
  inline xstring	Get_data_validation_defn() {
		return data_validation_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > epa_file;
  inline xstring	Get_epa_file() {
		return epa_file; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > epa_file_defn;
  inline xstring	Get_epa_file_defn() {
		return epa_file_defn; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > gaap_acctng_defn;
  inline xstring	Get_gaap_acctng_defn() {
		return gaap_acctng_defn; }
  inline void Set_gaap_acctng_defn(const xstring &v) {
		gaap_acctng_defn.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > ia_prod_v3_rsd_2_aig;
  inline xstring	Get_ia_prod_v3_rsd_2_aig() {
		return ia_prod_v3_rsd_2_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pct_to_use_mp;
  inline double	Get_pct_to_use_mp() {
		return pct_to_use_mp; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > planned_sale_date;
  inline xstring	Get_planned_sale_date() {
		return planned_sale_date; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c1_pct;
  inline double	Get_rbc_c1_pct() {
		return rbc_c1_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > sale_class;
  inline xstring	Get_sale_class() {
		return sale_class; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > seg_id;
  inline xstring	Get_seg_id() {
		return seg_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > use_mp;
  inline xstring	Get_use_mp() {
		return use_mp; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > asset_fund_index;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > commencement_period;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > data_grp_id;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gaap_inc_defn;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gaap_val_defn;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > maturity_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > neg_asset_flag;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > pct_to_use;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > planned_sale_period;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > proj_date_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_date_offset;
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
 void passDataVariables(EPA_ASSET* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Get EPA Value
#line 1 "get_epa_value.epa_asset.for"
double get_epa_value(const xstring &col_name, int t);

// Read EPA File
#line 1 "read_epa_file.epa_asset.for"
bool read_epa_file(const xstring &epa_file);

// Read EPA Schedule
#line 1 "read_epa_schedule.epa_asset.for"
bool read_epa_schedule(const xstring &epa_file);

// Read TAS EPA File
#line 1 "read_tas_epa_file.epa_asset.for"
bool read_tas_epa_file(const xstring &epa_file);

// Set Schedule Byte Markers
#line 1 "set_sched_byte_markers.epa_asset.for"
void set_sched_byte_markers(const xstring &sched_file);

// Validate Data
#line 1 "validate_data.epa_asset.for"
void validate_data(void);

// Write State of World Model Point
#line 1 "write_state_of_world_mp.epa_asset.for"
void write_state_of_world_mp(void);


//factory
static EPA_ASSET* makeThis(int isSubmodel, ModelClass *owner, EPA_ASSET* peer, 
					int mainRebase, const xstring &name, EPA_ASSET_persistent_object* arrayTemplate);

//constructor
EPA_ASSET(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
EPA_ASSET(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~EPA_ASSET();


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
class EPA_ASSET_persistent_object : public EPA_ASSET {


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

	void findTargetColumns() {EPA_ASSET::findTargetColumns();}
	void createAllShare() {
		EPA_ASSET::createAllShare();
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
	EPA_ASSET *&sm_bond_is; //
	EPA_ASSET *&sm_bond_pv; //
	EPA_ASSET *&sm_bond_ym; //
	EPA_ASSET *&sm_mtg_is; //
	EPA_ASSET *&sm_mtg_pv; //
	EPA_ASSET *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~EPA_ASSET_persistent_object();

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
static EPA_ASSET_persistent_object* makeThis(int isSubmodel, ModelClass *owner, EPA_ASSET* peer, 
					int mainRebase, const xstring &name, EPA_ASSET_persistent_object* arrayTemplate, bool fixedArray);

//constructor
EPA_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
