#ifndef __FIACARVM_LIAB_H_
#define __FIACARVM_LIAB_H_
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



namespace FIACARVM_LIAB_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class FIACARVM_LIAB_persistent_object;
class FIACARVM_LIAB : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(FIACARVM_LIAB); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;

#if defined(__AA_COMP_COMP_H_)
RATES_ECONOMY /*modelobject_name: RATES*/ *rates_ptr;
#else
RATES_ECONOMY /*modelobject_name: FIA_RATES*/ *rates_ptr;
#endif

	void init_(){
		

		bIsInit = true;
	}
	void deInit_(){

	}

#ifdef __CREATE_ADCO_ASSET_CLASS_
	ADCO_ASSET	*company_asset_adco;
	ADCO_ASSET	*&adco;
#endif
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
	ANN_PBA_PBA	*company_seg_ann_pba;
	ANN_PBA_PBA	*&ann_pba;
#endif
#ifdef __CREATE_ASSET_ASSET_CLASS_
	ASSET_ASSET	*company_asset;
	ASSET_ASSET	*&asset;
#endif
#ifdef __CREATE_AA_COMP_COMP_CLASS_
	AA_COMP_COMP	*company;
#endif
#ifdef __CREATE_EPL_LIAB_CLASS_
	EPL_LIAB	*company_liab_epl;
	EPL_LIAB	*&epl;
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
#ifdef __CREATE_RATES_ECONOMY_CLASS_
	RATES_ECONOMY	*company_rates;
	RATES_ECONOMY	*&rates;
#endif
 // Column Definition Begins
 	ColumnAccessor < mCFStaticData_0 > admin_fee;
 	ColumnAccessor < mCFStaticData_0 > age_last;
 	ColumnAccessor < mCFStaticData_0 > ann_benefits;
 	ColumnAccessor < mCFStaticData_0 > ann_benefits_pv;
 	ColumnAccessor < mCFStaticData_0 > ann_purch_factor_curr;
 	ColumnAccessor < mCFStaticData_0 > ann_purch_factor_guar;
 	ColumnAccessor < mCFStaticData_0 > ann_valn_factor;
 	ColumnAccessor < mCFStaticData_0 > attained_age;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > carvm_ann_disc_factor;
 	ColumnAccessor < mCFStaticData_0 > carvm_disc_factor_elect_annuitzn;
 	ColumnAccessor < mCFStaticData_0 > carvm_disc_factor_elect_cash_val;
 	ColumnAccessor < mCFStaticData_0 > carvm_disc_factor_non_elect;
 	ColumnAccessor < mCFStaticData_0 > carvm_disc_factor_non_elect_gmwb;
 	ColumnAccessor < mCFStaticData_0 > cash_val;
 	ColumnAccessor < mCFStaticData_0 > cash_val_pv;
 	ColumnAccessor < mCFStaticData_0 > contract_val_bef_pfwd;
 	ColumnAccessor < mCFStaticData_0 > contract_val_bef_surr;
 	ColumnAccessor < mCFStaticData_0 > credited_int;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate_fund_value_fixed;
 	ColumnAccessor < mCFStaticData_0 > dth_benefits;
 	ColumnAccessor < mCFStaticData_0 > dth_benefits_pv;
 	ColumnAccessor < mCFStaticData_0 > fund_val_aft_pfwd;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b;
 	ColumnAccessor < mCFStaticData_0 > fund_val_bef_pfwd;
 	ColumnAccessor < mCFStaticData_0 > gmwb_ann_benefits;
 	ColumnAccessor < mCFStaticData_0 > gmwb_ann_benefits_pv;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_fund_val_aft_pfwd;
 	ColumnAccessor < mCFStaticData_0 > gmwb_fund_val_bef_pfwd;
 	ColumnAccessor < mCFStaticData_0 > gmwb_inf_bef;
 	ColumnAccessor < mCFStaticData_0 > gmwb_max_wdl_amt;
 	ColumnAccessor < mCFStaticData_0 > gmwb_prem_aft_pfwd;
 	ColumnAccessor < mCFStaticData_0 > gmwb_prem_bef_pfwd;
 	ColumnAccessor < mCFStaticData_0 > gmwb_rollup_cap_aft_pfwd;
 	ColumnAccessor < mCFStaticData_0 > gmwb_rollup_cap_bef_pfwd;
 	ColumnAccessor < mCFStaticData_0 > guar_min_contract_val;
 	ColumnAccessor < mCFStaticData_0 > mort_rate_ann_purch_curr;
 	ColumnAccessor < mCFStaticData_0 > mort_rate_ann_purch_guar;
 	ColumnAccessor < mCFStaticData_0 > mort_rate_carvm;
 	ColumnAccessor < mCFStaticData_0 > mort_rate_carvm_annuitzn;
 	ColumnAccessor < mCFStaticData_0 > mort_rate_carvm_gmwb;
 	ColumnAccessor < mCFStaticData_0 > mort_rate_carvm_omega;
 	ColumnAccessor < mCFStaticData_0 > mva_ratio;
 	ColumnAccessor < mCFStaticData_0 > nh_benefits_pv;
 	ColumnAccessor < mCFStaticData_0 > nh_incid_rate;
 	ColumnAccessor < mCFStaticData_0 > pfwd_entitlement;
 	ColumnAccessor < mCFStaticData_0 > pfwd_surr;
 	ColumnAccessor < mCFStaticData_0 > pfwd_surr_cumul;
 	ColumnAccessor < mCFStaticData_0 > pfwd_surr_pv;
 	ColumnAccessor < mCFStaticData_0 > pol_yr;
 	ColumnAccessor < mCFStaticData_0 > purch_rate_curr_sprd;
 	ColumnAccessor < mCFStaticData_0 > res_integrated;
 	ColumnAccessor < mCFStaticData_0 > res_integrated_annuitzn;
 	ColumnAccessor < mCFStaticData_0 > res_integrated_cash_val;
 	ColumnAccessor < mCFStaticData_0 > startup;
 	ColumnAccessor < mCFStaticData_0 > surr_chg;
 	ColumnAccessor < mCFStaticData_0 > surr_chg_pct;
 	ColumnAccessor < mCFStaticData_0 > surr_chg_pct_col;
 	ColumnAccessor < mCFStaticData_0 > surv;
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
	#define DESCRIPTOR_TABLE FIACARVM_LIAB::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > carvm_annuitzn_ann_type;
  inline xstring	Get_carvm_annuitzn_ann_type() {
		return carvm_annuitzn_ann_type; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > carvm_annuitzn_certain_yrs;
  inline int	Get_carvm_annuitzn_certain_yrs() {
		return carvm_annuitzn_certain_yrs; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > carvm_annuitzn_min_fund_val_pct;
  inline double	Get_carvm_annuitzn_min_fund_val_pct() {
		return carvm_annuitzn_min_fund_val_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > carvm_annuitzn_mort_base;
  inline double	Get_carvm_annuitzn_mort_base() {
		return carvm_annuitzn_mort_base; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_annuitzn_mort_base_tbl_id;
  inline xstring	Get_carvm_annuitzn_mort_base_tbl_id() {
		return carvm_annuitzn_mort_base_tbl_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_annuitzn_mort_base_tbl_style;
  inline xstring	Get_carvm_annuitzn_mort_base_tbl_style() {
		return carvm_annuitzn_mort_base_tbl_style; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > carvm_annuitzn_mort_improve_base_yr;
  inline int	Get_carvm_annuitzn_mort_improve_base_yr() {
		return carvm_annuitzn_mort_improve_base_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > carvm_annuitzn_mort_improve_pct;
  inline double	Get_carvm_annuitzn_mort_improve_pct() {
		return carvm_annuitzn_mort_improve_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > carvm_annuitzn_mort_mult;
  inline double	Get_carvm_annuitzn_mort_mult() {
		return carvm_annuitzn_mort_mult; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_annuitzn_tests;
  inline xstring	Get_carvm_annuitzn_tests() {
		return carvm_annuitzn_tests; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > carvm_calc_annuitzn_defn;
  inline xstring	Get_carvm_calc_annuitzn_defn() {
		return carvm_calc_annuitzn_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > carvm_cont_defn;
  inline xstring	Get_carvm_cont_defn() {
		return carvm_cont_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_defn;
  inline xstring	Get_carvm_defn() {
		return carvm_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > carvm_gmwb_mort_base;
  inline double	Get_carvm_gmwb_mort_base() {
		return carvm_gmwb_mort_base; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_gmwb_mort_base_tbl_id;
  inline xstring	Get_carvm_gmwb_mort_base_tbl_id() {
		return carvm_gmwb_mort_base_tbl_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_gmwb_mort_base_tbl_style;
  inline xstring	Get_carvm_gmwb_mort_base_tbl_style() {
		return carvm_gmwb_mort_base_tbl_style; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > carvm_gmwb_mort_improve_base_yr;
  inline int	Get_carvm_gmwb_mort_improve_base_yr() {
		return carvm_gmwb_mort_improve_base_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > carvm_gmwb_mort_improve_pct;
  inline double	Get_carvm_gmwb_mort_improve_pct() {
		return carvm_gmwb_mort_improve_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > carvm_gmwb_mort_mult;
  inline double	Get_carvm_gmwb_mort_mult() {
		return carvm_gmwb_mort_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > carvm_int_rate;
  inline double	Get_carvm_int_rate() {
		return carvm_int_rate; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > carvm_life_int_rate;
  inline double	Get_carvm_life_int_rate() {
		return carvm_life_int_rate; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > carvm_max_dur;
  inline int	Get_carvm_max_dur() {
		return carvm_max_dur; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > carvm_mort_base;
  inline double	Get_carvm_mort_base() {
		return carvm_mort_base; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_mort_base_tbl_id;
  inline xstring	Get_carvm_mort_base_tbl_id() {
		return carvm_mort_base_tbl_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_mort_base_tbl_style;
  inline xstring	Get_carvm_mort_base_tbl_style() {
		return carvm_mort_base_tbl_style; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > carvm_mort_improve_base_yr;
  inline int	Get_carvm_mort_improve_base_yr() {
		return carvm_mort_improve_base_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > carvm_mort_improve_pct;
  inline double	Get_carvm_mort_improve_pct() {
		return carvm_mort_improve_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > carvm_mort_mult;
  inline double	Get_carvm_mort_mult() {
		return carvm_mort_mult; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > gmwb_exercise_point;
  inline int	Get_gmwb_exercise_point() {
		return gmwb_exercise_point; }
  inline void Set_gmwb_exercise_point(const int &v) {
		gmwb_exercise_point.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > include_nh_defn;
  inline xstring	Get_include_nh_defn() {
		return include_nh_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > model_name;
  inline xstring	Get_model_name() {
		return model_name; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > mort_attained_age;
  inline int	Get_mort_attained_age() {
		return mort_attained_age; }
  inline void Set_mort_attained_age(const int &v) {
		mort_attained_age.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_base_curr;
  inline double	Get_mort_base_curr() {
		return mort_base_curr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_base_guar;
  inline double	Get_mort_base_guar() {
		return mort_base_guar; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > mort_cal_yr;
  inline int	Get_mort_cal_yr() {
		return mort_cal_yr; }
  inline void Set_mort_cal_yr(const int &v) {
		mort_cal_yr.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > mort_gender;
  inline xstring	Get_mort_gender() {
		return mort_gender; }
  inline void Set_mort_gender(const xstring &v) {
		mort_gender.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > mort_issue_age;
  inline int	Get_mort_issue_age() {
		return mort_issue_age; }
  inline void Set_mort_issue_age(const int &v) {
		mort_issue_age.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_mult_curr;
  inline double	Get_mort_mult_curr() {
		return mort_mult_curr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_mult_guar;
  inline double	Get_mort_mult_guar() {
		return mort_mult_guar; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > mort_pol_yr;
  inline int	Get_mort_pol_yr() {
		return mort_pol_yr; }
  inline void Set_mort_pol_yr(const int &v) {
		mort_pol_yr.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > nh_incid_base;
  inline double	Get_nh_incid_base() {
		return nh_incid_base; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pfwd_pct;
  inline double	Get_pfwd_pct() {
		return pfwd_pct; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > pv_max_period;
  inline int	Get_pv_max_period() {
		return pv_max_period; }
  inline void Set_pv_max_period(const int &v) {
		pv_max_period.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > res_period;
  inline int	Get_res_period() {
		return res_period; }
  inline void Set_res_period(const int &v) {
		res_period.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > surr_chg_pct_carvm;
  inline double	Get_surr_chg_pct_carvm() {
		return surr_chg_pct_carvm; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > valn_guar_dur;
  inline int	Get_valn_guar_dur() {
		return valn_guar_dur; }
  inline void Set_valn_guar_dur(const int &v) {
		valn_guar_dur.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > valn_plan_type;
  inline xstring	Get_valn_plan_type() {
		return valn_plan_type; }
  inline void Set_valn_plan_type(const xstring &v) {
		valn_plan_type.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > valn_rate_cash_settle_defn;
  inline xstring	Get_valn_rate_cash_settle_defn() {
		return valn_rate_cash_settle_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > valn_rate_int_guar_defn;
  inline xstring	Get_valn_rate_int_guar_defn() {
		return valn_rate_int_guar_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > valn_rate_plan_type_elective_annuitzn;
  inline xstring	Get_valn_rate_plan_type_elective_annuitzn() {
		return valn_rate_plan_type_elective_annuitzn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > valn_rate_plan_type_elective_cash_val;
  inline xstring	Get_valn_rate_plan_type_elective_cash_val() {
		return valn_rate_plan_type_elective_cash_val; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > valn_rate_plan_type_non_elective;
  inline xstring	Get_valn_rate_plan_type_non_elective() {
		return valn_rate_plan_type_non_elective; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > carvm_annuitzn_test_num;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > gender;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > int_guar_dur;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > issue_age;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > issue_date;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > issue_yr;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > max_calc_period;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > mths_in_first_period;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > mva_comp_rate_issue;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > pfwd_model;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > prem_cumul;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(FIACARVM_LIAB* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Dividend yield
#line 1 "dividend_yield.fiacarvm_liab.for"
double dividend_yield(int t, const xstring &eqt_index);

// Risk free rate
#line 1 "risk_free_rate.fiacarvm_liab.for"
double risk_free_rate(int t, double tte);

// Set Hidden Variables
#line 1 "set_hidden_variables.fiacarvm_liab.for"
void set_hidden_variables(void);

// Time To Expiry
#line 1 "time_to_expiry.fiacarvm_liab.for"
double time_to_expiry(int t, int fia_mths);

// Volatility
#line 1 "volatility.fiacarvm_liab.for"
double volatility(int t, const xstring &eqt_index, double moneyness, double time_to_expiry);


//factory
static FIACARVM_LIAB* makeThis(int isSubmodel, ModelClass *owner, FIACARVM_LIAB* peer, 
					int mainRebase, const xstring &name, FIACARVM_LIAB_persistent_object* arrayTemplate);

//constructor
FIACARVM_LIAB(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
FIACARVM_LIAB(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~FIACARVM_LIAB();


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
class FIACARVM_LIAB_persistent_object : public FIACARVM_LIAB {


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

	void findTargetColumns() {FIACARVM_LIAB::findTargetColumns();}
	void createAllShare() {
		FIACARVM_LIAB::createAllShare();
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


	~FIACARVM_LIAB_persistent_object();

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
static FIACARVM_LIAB_persistent_object* makeThis(int isSubmodel, ModelClass *owner, FIACARVM_LIAB* peer, 
					int mainRebase, const xstring &name, FIACARVM_LIAB_persistent_object* arrayTemplate, bool fixedArray);

//constructor
FIACARVM_LIAB_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
