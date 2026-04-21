#ifndef __ASSET_ASSET_H_
#define __ASSET_ASSET_H_
#pragma warning ( disable : 4819 )

#include <sstream> // for ostringstream
#include <utility> // for pair templates

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


#include "ModelClass\adco_asset.h"
#include "ModelClass\a_subport_asset.h"
#include "ModelClass\bond_asset.h"
#include "ModelClass\eio_asset.h"
#include "ModelClass\epa_asset.h"
#include "ModelClass\intex_asset.h"
#include "ModelClass\mtg_asset.h"

namespace ASSET_ASSET_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class ASSET_ASSET_persistent_object;
class ASSET_ASSET : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(ASSET_ASSET); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;
	static void Terminator();
	static FunctionPtr RegisterTerminatorOnce;
	
xstring asset_detail_rpt_id;
xstring yld_maint_rpt_id;

// Asset sub portfolio map
typedef map <xstring, int, less<xstring> > asubportmap;
asubportmap asset_sub_port_map;
asubportmap::iterator asset_sub_port_map_iter;

// Existing asset sequence number map
typedef map <xstring, int, less<xstring> > seqmap;
seqmap existing_asset_sequence_num_map;

// Asset category map
typedef map <xstring, int, less<xstring> > acatmap;
acatmap asset_category_map;

// Initial cash account_id balance maps
typedef map <xstring, double, less<xstring> > icbmap;
icbmap init_cash_bal_map;
icbmap::iterator init_cash_bal_map_iter;

typedef map <int, long, less <int> > mpmap;

int asset_mp_sequence_num;
int purch_asset_mp_num;
int maximum_spot_rate_term;

int num_bonds_init;
int num_mtgs_init;
int num_secs_init;
int num_irds_init;
int num_res_init;
int num_eqts_init;
int num_eios_init;
int num_epas_init;

double purch_asset_yrs_to_maturity;
int purch_asset_mths_to_first_reset;

// Asset subports vector
vector <string> asset_sub_ports;

SmartArray <double> psa_base_rate;

const char *zAssetFund[2];
const char *zSalesClass[5];

	void init_(){
		

asset_detail_rpt_id = "";

// Initialize flag variables
purch_asset_mp_num = -1;
maximum_spot_rate_term = 0;

num_bonds_init = -1;
num_mtgs_init = -1;
num_secs_init = -1;
num_irds_init = -1;
num_res_init = -1;
num_eqts_init = -1;
num_eios_init = -1;
num_epas_init = -1;

purch_asset_yrs_to_maturity = 0.0;
purch_asset_mths_to_first_reset = 0;

zAssetFund[0] = "Investment";
zAssetFund[1] = "Hedge";
zSalesClass[0] = "Unknown";
zSalesClass[1] = "NotAssigned";
zSalesClass[2] = "AvailForSale";
zSalesClass[3] = "Trading";
zSalesClass[4] = "HeldToMaturity";


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
#ifdef __CREATE_BOND_ASSET_CLASS_
	BOND_ASSET	*company_asset_bond;
	BOND_ASSET	*&bond;
#endif
#ifdef __CREATE_BOND_CF_ASSET_CLASS_
	BOND_CF_ASSET	*company_asset_bond_bond_cf_bond_is;
	BOND_CF_ASSET	*&bond_is;
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
#ifdef __CREATE_FIA_LIAB_CLASS_
	FIA_LIAB	*company_liab_fia;
	FIA_LIAB	*&fia;
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
 // Column Definition Begins
 	ColumnAccessor < mCFStaticData_0 > asset_detail_rpt_flag;
 	ColumnAccessor < mCFStaticData_0 > asset_detail_rpt_inv_strat_flag;
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > finalize;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > mths_to_asset_sale;
 	ColumnAccessor < mCFStaticData_0 > mths_to_next_mkt_val_calc;
 	ColumnAccessor < mCFStaticData_0 > mths_to_sec_yld_calc;
 	ColumnAccessor < mCFStaticData_0 > startup;
//Column Definition END@2

 // Temporary Table...
ADCO_ASSET *sm_adco;
_3D_A_SUBPORT_ASSET sm_asset_sub_port;
_1D_BOND_ASSET sm_bond;
_1D_EIO_ASSET sm_eio;
_1D_EPA_ASSET sm_epa;
INTEX_ASSET *sm_intex;
_1D_MTG_ASSET sm_mtg;
ASSET_ASSET *sm_bond_is;
ASSET_ASSET *sm_bond_pv;
ASSET_ASSET *sm_bond_ym;
ASSET_ASSET *sm_mtg_is;
ASSET_ASSET *sm_mtg_pv;
ASSET_ASSET *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE ASSET_ASSET::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_detail_rpt_cusip_id;
  inline xstring	Get_asset_detail_rpt_cusip_id() {
		return asset_detail_rpt_cusip_id; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > asset_detail_rpt_final_period;
  inline int	Get_asset_detail_rpt_final_period() {
		return asset_detail_rpt_final_period; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_detail_rpt_inv_strat_defn;
  inline xstring	Get_asset_detail_rpt_inv_strat_defn() {
		return asset_detail_rpt_inv_strat_defn; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > asset_detail_rpt_output_defn;
  inline xstring	Get_asset_detail_rpt_output_defn() {
		return asset_detail_rpt_output_defn; }
  inline void Set_asset_detail_rpt_output_defn(const xstring &v) {
		asset_detail_rpt_output_defn.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_detail_rpt_pv_defn;
  inline xstring	Get_asset_detail_rpt_pv_defn() {
		return asset_detail_rpt_pv_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > asset_detail_rpt_start_period;
  inline int	Get_asset_detail_rpt_start_period() {
		return asset_detail_rpt_start_period; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_detail_rpt_sum_asset_defn;
  inline xstring	Get_asset_detail_rpt_sum_asset_defn() {
		return asset_detail_rpt_sum_asset_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_mkt_sprd_use_defn;
  inline xstring	Get_asset_mkt_sprd_use_defn() {
		return asset_mkt_sprd_use_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_sub_port_asset_type;
  inline xstring	Get_asset_sub_port_asset_type() {
		return asset_sub_port_asset_type; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_sub_port_assign_dur_defn;
  inline xstring	Get_asset_sub_port_assign_dur_defn() {
		return asset_sub_port_assign_dur_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_sub_port_categories;
  inline xstring	Get_asset_sub_port_categories() {
		return asset_sub_port_categories; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_sub_port_dur_match_defn;
  inline xstring	Get_asset_sub_port_dur_match_defn() {
		return asset_sub_port_dur_match_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > asset_sub_port_dur_max;
  inline double	Get_asset_sub_port_dur_max() {
		return asset_sub_port_dur_max; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > asset_sub_port_dur_min;
  inline double	Get_asset_sub_port_dur_min() {
		return asset_sub_port_dur_min; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_sub_port_existing_or_purch_defn;
  inline xstring	Get_asset_sub_port_existing_or_purch_defn() {
		return asset_sub_port_existing_or_purch_defn; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > asset_sub_port_id;
  inline xstring	Get_asset_sub_port_id() {
		return asset_sub_port_id; }
  inline void Set_asset_sub_port_id(const xstring &v) {
		asset_sub_port_id.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > asset_sub_port_inv_exp_pct;
  inline double	Get_asset_sub_port_inv_exp_pct() {
		return asset_sub_port_inv_exp_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > asset_sub_port_min_size;
  inline double	Get_asset_sub_port_min_size() {
		return asset_sub_port_min_size; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_sub_port_port_defn;
  inline xstring	Get_asset_sub_port_port_defn() {
		return asset_sub_port_port_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_sub_port_proxy_bond_category;
  inline xstring	Get_asset_sub_port_proxy_bond_category() {
		return asset_sub_port_proxy_bond_category; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_sub_port_proxy_bond_sale_class;
  inline xstring	Get_asset_sub_port_proxy_bond_sale_class() {
		return asset_sub_port_proxy_bond_sale_class; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > asset_sub_port_rebal_pct_max;
  inline double	Get_asset_sub_port_rebal_pct_max() {
		return asset_sub_port_rebal_pct_max; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > asset_sub_port_rebal_pct_min;
  inline double	Get_asset_sub_port_rebal_pct_min() {
		return asset_sub_port_rebal_pct_min; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > asset_sub_port_rebal_tolerance_pct;
  inline double	Get_asset_sub_port_rebal_tolerance_pct() {
		return asset_sub_port_rebal_tolerance_pct; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > asset_sub_port_rpt_defn;
  inline xstring	Get_asset_sub_port_rpt_defn() {
		return asset_sub_port_rpt_defn; }
  inline void Set_asset_sub_port_rpt_defn(const xstring &v) {
		asset_sub_port_rpt_defn.setValue(v); }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > asset_sub_port_sale_priority;
  inline int	Get_asset_sub_port_sale_priority() {
		return asset_sub_port_sale_priority; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_sub_ports_selected;
  inline xstring	Get_asset_sub_ports_selected() {
		return asset_sub_ports_selected; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > fast_stat_calc_aig;
  inline xstring	Get_fast_stat_calc_aig() {
		return fast_stat_calc_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > intex_defn;
  inline xstring	Get_intex_defn() {
		return intex_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > inv_assump_set_id;
  inline xstring	Get_inv_assump_set_id() {
		return inv_assump_set_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > mkt_val_calc_freq;
  inline xstring	Get_mkt_val_calc_freq() {
		return mkt_val_calc_freq; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > mkt_val_calc_freq_sale;
  inline xstring	Get_mkt_val_calc_freq_sale() {
		return mkt_val_calc_freq_sale; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > mkt_val_calc_freq_sec_net_yld;
  inline xstring	Get_mkt_val_calc_freq_sec_net_yld() {
		return mkt_val_calc_freq_sec_net_yld; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > mkt_val_calc_freq_yrs;
  inline int	Get_mkt_val_calc_freq_yrs() {
		return mkt_val_calc_freq_yrs; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > proxy_bond_defn;
  inline xstring	Get_proxy_bond_defn() {
		return proxy_bond_defn; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > rebase_pv_clone_defn;
  inline xstring	Get_rebase_pv_clone_defn() {
		return rebase_pv_clone_defn; }
  inline void Set_rebase_pv_clone_defn(const xstring &v) {
		rebase_pv_clone_defn.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > ms_bond_readfile;
  inline xstring	Get_ms_bond_readfile() {
		return ms_bond_readfile; }
  inline void Set_ms_bond_readfile(const xstring &v) {
		ms_bond_readfile.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > ms_eio_readfile;
  inline xstring	Get_ms_eio_readfile() {
		return ms_eio_readfile; }
  inline void Set_ms_eio_readfile(const xstring &v) {
		ms_eio_readfile.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > ms_epa_readfile;
  inline xstring	Get_ms_epa_readfile() {
		return ms_epa_readfile; }
  inline void Set_ms_epa_readfile(const xstring &v) {
		ms_epa_readfile.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > ms_mtg_readfile;
  inline xstring	Get_ms_mtg_readfile() {
		return ms_mtg_readfile; }
  inline void Set_ms_mtg_readfile(const xstring &v) {
		ms_mtg_readfile.setValue(v); }
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
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > scen_day;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > start_period;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(ASSET_ASSET* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Asset Detail Log Rebase Reset
#line 1 "asset_detail_log_rebase_reset.asset_asset.for"
void asset_detail_log_rebase_reset(int t, const xstring &rebase_model, const xstring &caller, const xstring &identifier, const xstring &id_submodel_name);

// Asset Detail Report Present Value Output
#line 1 "asset_detail_rpt_pv_output.asset_asset.for"
void asset_detail_rpt_pv_output();

// Asset Model Point Maps Reset
#line 1 "asset_mp_maps_reset.asset_asset.for"
void asset_mp_maps_reset();

// Asset Sub Portfolio Assignment
#line 1 "asset_sub_port_assign.asset_asset.for"
int asset_sub_port_assign(int t, int new_asset, xstring asset_type, StrEnum::EnumValue port_defn, xstring category_id, int existing_asset_flag, double dur_for_transfer, int sub_port_id_prev);

// Get Model Point Group
#line 1 "get_mp_grp.asset_asset.for"
xstring get_mp_grp(const xstring &tag);

// Set Asset Sub Portfolio Map
#line 1 "set_asset_sub_port_map.asset_asset.for"
void set_asset_sub_port_map();

// Set Model Point Group
#line 1 "set_mp_grp.asset_asset.for"
xstring set_mp_grp(int t, int model_point_num, const xstring &seg_id, const xstring &mp_grp_tag, const xstring &asset_id, int sequence_id, StrEnum::EnumValue purchase_timing);

// Setup PSA Base Rate
#line 1 "setup_psa_base_rate.asset_asset.for"
void setup_psa_base_rate();

// Valid T Low T High
#line 1 "valid_t_low_t_high.asset_asset.for"
bool valid_t_low_t_high(int calculated_t_low, int calculated_t_high);

// Write Proxy Bond
#line 1 "write_proxy_bond.asset_asset.for"
void write_proxy_bond(void);

// Write Proxy Bond Schedule
#line 1 "write_proxy_bond_sch.asset_asset.for"
void write_proxy_bond_sch(xstring asset_id, xstring sch_file, SmartArray <double> call_sch, SmartArray <double> sinking_fund_sch);


//factory
static ASSET_ASSET* makeThis(int isSubmodel, ModelClass *owner, ASSET_ASSET* peer, 
					int mainRebase, const xstring &name, ASSET_ASSET_persistent_object* arrayTemplate);

//constructor
ASSET_ASSET(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
ASSET_ASSET(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~ASSET_ASSET();


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
class ASSET_ASSET_persistent_object : public ASSET_ASSET {


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

	void findTargetColumns() {ASSET_ASSET::findTargetColumns();}
	void createAllShare() {
		ASSET_ASSET::createAllShare();
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
	ADCO_ASSET *&sm_adco; //
	_3D_A_SUBPORT_ASSET &sm_asset_sub_port; //
	_1D_BOND_ASSET &sm_bond; //
	_1D_EIO_ASSET &sm_eio; //
	_1D_EPA_ASSET &sm_epa; //
	INTEX_ASSET *&sm_intex; //
	_1D_MTG_ASSET &sm_mtg; //
	ASSET_ASSET *&sm_bond_is; //
	ASSET_ASSET *&sm_bond_pv; //
	ASSET_ASSET *&sm_bond_ym; //
	ASSET_ASSET *&sm_mtg_is; //
	ASSET_ASSET *&sm_mtg_pv; //
	ASSET_ASSET *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~ASSET_ASSET_persistent_object();

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
static ASSET_ASSET_persistent_object* makeThis(int isSubmodel, ModelClass *owner, ASSET_ASSET* peer, 
					int mainRebase, const xstring &name, ASSET_ASSET_persistent_object* arrayTemplate, bool fixedArray);

//constructor
ASSET_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
