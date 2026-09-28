#ifndef __FIA_LIAB_H_
#define __FIA_LIAB_H_
#pragma warning ( disable : 4819 )

#define __FIA_LIAB_H_

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


#include "ModelClass\fiacarvm_liab.h"
#include "ModelClass\fiaafund_liab.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\mrb_gaap.h"
#include "ModelClass\rates_economy.h"
#include "ModelClass\sfas97rd_gaap.h"

namespace FIA_LIAB_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class FIA_LIAB_persistent_object;
class FIA_LIAB : public ModelClass {

friend void clearSharedTempTables();
	

protected:
	static TempTableHolderCollection TTHC;
	void removeSMPointers(ModelClass* modelToRemove);
static const CashFlowCommonData* mCFStaticData[];
  static const CashFlowCommonData mCFStaticData_0[]; 
  static const CashFlowCommonData mCFStaticData_256[]; 
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

	size_t sizeofThis() const { return sizeof(FIA_LIAB); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;
	static void Terminator();
	static FunctionPtr RegisterTerminatorOnce;
	
int has_fixed;
int has_index0;
int has_index1;
int has_index2;
int has_index3;
int has_index4;
int fixed_element;
int index0_element;		
int index1_element;
int index2_element;
int index3_element;
int index4_element;
// competitor rate map
map <xstring, double, less<xstring> > comp_rates_map;
// discount rate vector
vector<string> disc_rates;
vector<string> gaap_cohorts_sfas97rd;
SmartArray <double> init_tax_capzd_prem_amortzn_sched;
double init_tax_bk_prof_ytd;
double init_tax_tgt_cap_ytd;
double init_taxable_inc_bk_prof_ytd;
double init_taxable_inc_tgt_cap_ytd;
double init_taxable_inc_carryfwd_avail;
double init_rbc_c1;
double init_rbc_c3_stoch_amt;
double init_rbc_c3_stoch_amt_unhedged;
double init_stat_res_net_stoch_res;
double init_stat_res_net_stoch_res_unhedged;
double init_stat_res_stoch_res;
double init_stat_res_stoch_res_unhedged;
double init_bk_prof_bef_tax_qtd;
double init_bk_prof_bef_tax_ytd;
double init_bk_prof_aft_tax_qtd;
double init_bk_prof_aft_tax_ytd;
double init_bk_prof_aft_tax_irr;
double init_distrib_earnings_irr;
double init_earnings_accum;
double init_tax_earnings_accum_ytd;
double init_taxable_inc_earnings_accum_ytd;
double init_undistrib_earnings;
double init_gaap_inc_bef_tax_qtd;
double init_gaap_inc_bef_tax_ytd;
double init_gaap_inc_aft_tax_qtd;
double init_gaap_inc_aft_tax_ytd;
double init_gaap_req_cap;
int carvm_annuitzn_tests_number;
int gmwb_exercise_point;
int gmwb_exercise_point_test_cnt;
vector<string> gmwb_exercise_points_input;
xstring stat_audit_detail_rpt_id;
xstring tax_audit_detail_rpt_id;

vector< vector <double>> uniform_rands_arr_crbg;

SEG_COMP *seg_element;
#if defined(__AA_COMP_COMP_H_)
RATES_ECONOMY /*modelobject_name: RATES*/ *rates_ptr;
#else
RATES_ECONOMY /*modelobject_name: FIA_RATES*/ *rates_ptr;
#endif

vector <string> carvm_stat_annuitzn_tests_input;
vector <string> carvm_tax_annuitzn_tests_input;


	void init_(){
		

has_fixed = 0;
has_index0 = 0;
has_index1 = 0;
has_index2 = 0;
has_index3 = 0;
has_index4 = 0;
fixed_element = -1;
index0_element = -1;		
index1_element = -1;
index2_element = -1;
index3_element = -1;
index4_element = -1;
init_tax_bk_prof_ytd = 0.0;
init_tax_tgt_cap_ytd = 0.0;
init_taxable_inc_bk_prof_ytd = 0.0;
init_taxable_inc_tgt_cap_ytd = 0.0;
init_taxable_inc_carryfwd_avail = 0.0;
init_rbc_c1 = 0.0;
init_rbc_c3_stoch_amt = 0.0;
init_rbc_c3_stoch_amt_unhedged = 0.0;
init_stat_res_net_stoch_res = 0.0;
init_stat_res_net_stoch_res_unhedged = 0.0;
init_stat_res_stoch_res = 0.0;
init_stat_res_stoch_res_unhedged = 0.0;
init_bk_prof_bef_tax_qtd = 0.0;
init_bk_prof_bef_tax_ytd = 0.0;
init_bk_prof_aft_tax_qtd = 0.0;
init_bk_prof_aft_tax_ytd = 0.0;
init_bk_prof_aft_tax_irr = 0.0;
init_distrib_earnings_irr = 0.0;
init_earnings_accum = 0.0;
init_tax_earnings_accum_ytd = 0.0;
init_taxable_inc_earnings_accum_ytd = 0.0;
init_undistrib_earnings = 0.0;
init_gaap_inc_bef_tax_qtd = 0.0;
init_gaap_inc_bef_tax_ytd = 0.0;
init_gaap_inc_aft_tax_qtd = 0.0;
init_gaap_inc_aft_tax_ytd = 0.0;
init_gaap_req_cap = 0.0;
carvm_annuitzn_tests_number = 0;
gmwb_exercise_point = 0;
gmwb_exercise_point_test_cnt = 0;
stat_audit_detail_rpt_id = "";
tax_audit_detail_rpt_id = "";

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
#ifdef __CREATE_FIA_LIAB_CLASS_
	FIA_LIAB	*company_liab_fia;
	FIA_LIAB	*&fia;
#endif
#ifdef __CREATE_FIAAFUND_LIAB_CLASS_
	FIAAFUND_LIAB	*company_liab_fia_fia_account;
	FIAAFUND_LIAB	*&fia_account;
#endif
#ifdef __CREATE_ANN_PBA_PBA_CLASS_
	ANN_PBA_PBA	*company_liab_fia_fia_ann_pba;
	ANN_PBA_PBA	*&fia_ann_pba;
#endif
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
	FIACARVM_LIAB	*company_liab_fia_carvm_stat;
	FIACARVM_LIAB	*&fia_carvm_stat;
#endif
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
	FIACARVM_LIAB	*company_liab_fia_carvm_tax;
	FIACARVM_LIAB	*&fia_carvm_tax;
#endif
#ifdef __CREATE_MRB_GAAP_CLASS_
	MRB_GAAP	*company_liab_fia_fia_mrb;
	MRB_GAAP	*&fia_mrb;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
	RATES_ECONOMY	*company_liab_fia_fia_rates;
	RATES_ECONOMY	*&fia_rates;
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
	SFAS97RD_GAAP	*company_liab_fia_fia_sfas97rd;
	SFAS97RD_GAAP	*&fia_sfas97rd;
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
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
	SFAS97RD_GAAP	*company_seg_sfas97rd;
	SFAS97RD_GAAP	*&sfas97rd;
#endif
 // Column Definition Begins
 	ColumnAccessor < mCFStaticData_0 > acq_exp;
 	ColumnAccessor < mCFStaticData_0 > admin_fee;
 	ColumnAccessor < mCFStaticData_0 > age_last;
 	ColumnAccessor < mCFStaticData_0 > ann_benefits_eom;
 	ColumnAccessor < mCFStaticData_0 > ann_claims_gmwb;
 	ColumnAccessor < mCFStaticData_0 > ann_gmwb_cash_flow_crbg;
 	ColumnAccessor < mCFStaticData_0 > ann_gmwb_claim_yr_crbg;
 	ColumnAccessor < mCFStaticData_0 > ann_gmwb_pip_pct_crbg;
 	ColumnAccessor < mCFStaticData_0 > ann_gmwb_wdl_grossed_up_crbg;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_rate;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_rate_mthly;
 	ColumnAccessor < mCFStaticData_0 > asset_yld;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_fa_rate_setting_crbg;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_inv;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_inv_adj_crbg;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_less_dflt;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_less_dflt_inv;
 	ColumnAccessor < mCFStaticData_0 > attained_age;
 	ColumnAccessor < mCFStaticData_0 > avg_coupon_rt_crbg;
 	ColumnAccessor < mCFStaticData_0 > bef_tax_yld;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_aft_tax;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_aft_tax_for_pv;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_aft_tax_irr;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_aft_tax_qtd;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_aft_tax_ytd;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_bef_tax;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_bef_tax_for_pv;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_bef_tax_qtd;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_bef_tax_ytd;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_by_source_bef_tax;
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > cash_val;
 	ColumnAccessor < mCFStaticData_0 > cash_val_bef;
 	ColumnAccessor < mCFStaticData_0 > cash_val_wo_mva;
 	ColumnAccessor < mCFStaticData_0 > comm_bom;
 	ColumnAccessor < mCFStaticData_0 > comm_chargeback;
 	ColumnAccessor < mCFStaticData_0 > comm_eom;
 	ColumnAccessor < mCFStaticData_0 > comm_fund_based;
 	ColumnAccessor < mCFStaticData_0 > comm_prem_based;
 	ColumnAccessor < mCFStaticData_0 > comm_subject_to_chargeback;
 	ColumnAccessor < mCFStaticData_0 > comm_subject_to_chargeback_e;
 	ColumnAccessor < mCFStaticData_0 > contract_val;
 	ColumnAccessor < mCFStaticData_0 > contract_val_bef;
 	ColumnAccessor < mCFStaticData_0 > covered_person_status_crbg;
 	ColumnAccessor < mCFStaticData_0 > credited_int;
 	ColumnAccessor < mCFStaticData_0 > credited_int_comp_numer;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate_cumul_crbg;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate_fix;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate_partial_crbg;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > direct_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_0 > direct_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_0 > direct_cash_flow_int;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_2;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_3;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_port_yld;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_port_yld_defn_val;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_rf_crbg;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_rf_sprd_ic_uel_crbg;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_rf_sprd_no_uel_crbg;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_rf_sprd_uel_crbg;
 	ColumnAccessor < mCFStaticData_0 > distrib_earnings;
 	ColumnAccessor < mCFStaticData_0 > distrib_earnings_irr;
 	ColumnAccessor < mCFStaticData_0 > dth_ben_inf;
 	ColumnAccessor < mCFStaticData_0 > dth_ben_inf_bef;
 	ColumnAccessor < mCFStaticData_0 > dth_benefits;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_rate_mthly;
 	ColumnAccessor < mCFStaticData_0 > dth_rate_female_crbg;
 	ColumnAccessor < mCFStaticData_0 > dth_rate_male_crbg;
 	ColumnAccessor < mCFStaticData_0 > dth_rate_mthly_blended_crbg;
 	ColumnAccessor < mCFStaticData_0 > dth_rate_mthly_crbg;
 	ColumnAccessor < mCFStaticData_0 > dth_rate_mthly_female_crbg;
 	ColumnAccessor < mCFStaticData_0 > dth_rate_mthly_last_survivor_crbg;
 	ColumnAccessor < mCFStaticData_0 > dth_rate_mthly_male_crbg;
 	ColumnAccessor < mCFStaticData_0 > earnings_accum;
 	ColumnAccessor < mCFStaticData_0 > enh_inc_confined_mth_female_crbg;
 	ColumnAccessor < mCFStaticData_0 > enh_inc_confined_mth_male_crbg;
 	ColumnAccessor < mCFStaticData_0 > enh_inc_confined_status_aggr_crbg;
 	ColumnAccessor < mCFStaticData_0 > enh_inc_confined_status_female_crbg;
 	ColumnAccessor < mCFStaticData_0 > enh_inc_confined_status_male_crbg;
 	ColumnAccessor < mCFStaticData_0 > enh_inc_eligibility_flag_crbg;
 	ColumnAccessor < mCFStaticData_0 > enh_inc_exercise_cumul_yrs_crbg;
 	ColumnAccessor < mCFStaticData_0 > enh_inc_exercise_flag_crbg;
 	ColumnAccessor < mCFStaticData_0 > enh_inc_indirect_exercise_crbg;
 	ColumnAccessor < mCFStaticData_0 > enh_inc_rand_exercise_crbg;
 	ColumnAccessor < mCFStaticData_0 > enh_inc_rand_female_crbg;
 	ColumnAccessor < mCFStaticData_0 > enh_inc_rand_male_crbg;
 	ColumnAccessor < mCFStaticData_0 > eprs_sfc_ben_crbg;
 	ColumnAccessor < mCFStaticData_0 > eprs_sfc_ben_gross_crbg;
 	ColumnAccessor < mCFStaticData_0 > eprs_strat_fee_partial_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > eprs_strat_fee_partial_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > finalize;
 	ColumnAccessor < mCFStaticData_0 > fund_released_ann;
 	ColumnAccessor < mCFStaticData_0 > fund_released_dth;
 	ColumnAccessor < mCFStaticData_0 > fund_released_maturity;
 	ColumnAccessor < mCFStaticData_0 > fund_released_surr;
 	ColumnAccessor < mCFStaticData_0 > fund_released_withdrl;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b_bef;
 	ColumnAccessor < mCFStaticData_0 > fund_val_boy_b_crbg;
 	ColumnAccessor < mCFStaticData_0 > fund_val_boy_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > fund_val_decrem;
 	ColumnAccessor < mCFStaticData_0 > fund_val_e_bef;
 	ColumnAccessor < mCFStaticData_0 > fund_val_fixed;
 	ColumnAccessor < mCFStaticData_0 > gaap_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > gaap_ben_res;
 	ColumnAccessor < mCFStaticData_0 > gaap_capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > gaap_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_0 > gaap_capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_0 > gaap_capzd_prem_bonus;
 	ColumnAccessor < mCFStaticData_0 > gaap_cash_flow_int;
 	ColumnAccessor < mCFStaticData_0 > gaap_chg_inc;
 	ColumnAccessor < mCFStaticData_0 > gaap_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_0 > gaap_comm_excess_eom;
 	ColumnAccessor < mCFStaticData_0 > gaap_comm_trail_bom;
 	ColumnAccessor < mCFStaticData_0 > gaap_comm_trail_eom;
 	ColumnAccessor < mCFStaticData_0 > gaap_credited_int;
 	ColumnAccessor < mCFStaticData_0 > gaap_dac;
 	ColumnAccessor < mCFStaticData_0 > gaap_dac_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_deferred_tax_liab;
 	ColumnAccessor < mCFStaticData_0 > gaap_deferred_tax_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_dth_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_aft_tax;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_aft_tax_qtd;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_aft_tax_ytd;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_bef_tax;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_bef_tax_qtd;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_bef_tax_ytd;
 	ColumnAccessor < mCFStaticData_0 > gaap_inv_asset;
 	ColumnAccessor < mCFStaticData_0 > gaap_inv_inc_cap;
 	ColumnAccessor < mCFStaticData_0 > gaap_inv_inc_res;
 	ColumnAccessor < mCFStaticData_0 > gaap_liab_net;
 	ColumnAccessor < mCFStaticData_0 > gaap_loads_deducted;
 	ColumnAccessor < mCFStaticData_0 > gaap_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_0 > gaap_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_0 > gaap_mrb_liab;
 	ColumnAccessor < mCFStaticData_0 > gaap_mrb_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_prem_bonus;
 	ColumnAccessor < mCFStaticData_0 > gaap_prem_tax;
 	ColumnAccessor < mCFStaticData_0 > gaap_prof_aft_tax_for_pv;
 	ColumnAccessor < mCFStaticData_0 > gaap_prof_bef_tax_for_pv;
 	ColumnAccessor < mCFStaticData_0 > gaap_req_cap;
 	ColumnAccessor < mCFStaticData_0 > gaap_sfas133_liab;
 	ColumnAccessor < mCFStaticData_0 > gaap_sfas133_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_surp_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_surr_inc;
 	ColumnAccessor < mCFStaticData_0 > gmab_chg_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmab_chg_partial_e_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmab_chg_partial_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmab_global_payoff_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmab_payoff_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg_partial_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg_partial_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_entitlement_remaining_b_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_entitlement_remaining_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_exercise_yrs_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_fund_val_inf;
 	ColumnAccessor < mCFStaticData_0 > gmwb_fund_val_inf_bef;
 	ColumnAccessor < mCFStaticData_0 > gmwb_income_base_b_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_income_base_b_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_income_base_e_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_income_base_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_income_base_reduction_fct_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_income_credit_b_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_income_credit_base_e_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_income_credit_base_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_inf;
 	ColumnAccessor < mCFStaticData_0 > gmwb_inf_bef;
 	ColumnAccessor < mCFStaticData_0 > gmwb_itm;
 	ColumnAccessor < mCFStaticData_0 > gmwb_max_ann_wdl_pct_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_max_wdl_amt;
 	ColumnAccessor < mCFStaticData_0 > gmwb_min_income_base_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_pipp_stepup_ind_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_rollup_cap_inf;
 	ColumnAccessor < mCFStaticData_0 > gmwb_rollup_cap_inf_bef;
 	ColumnAccessor < mCFStaticData_0 > gmwb_wdl_amt_e_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_wdl_amt_excess_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_wdl_excess_ind_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_wdl_uti_level_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_wdl_util_pct_crbg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_wdl_util_rand_num_crbg;
 	ColumnAccessor < mCFStaticData_0 > gross_prem_annualzd;
 	ColumnAccessor < mCFStaticData_0 > gwl_acq_exp_allow_crbg;
 	ColumnAccessor < mCFStaticData_0 > gwl_ceding_exp_allow_crbg;
 	ColumnAccessor < mCFStaticData_0 > gwl_maint_exp_allow_crbg;
 	ColumnAccessor < mCFStaticData_0 > hedge_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > hedge_cost;
 	ColumnAccessor < mCFStaticData_0 > hedge_inv_amt_bom;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val_growth;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_0 > hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_0 > income_phase_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > infl_cumul;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > inv_asset;
 	ColumnAccessor < mCFStaticData_0 > inv_inc;
 	ColumnAccessor < mCFStaticData_0 > inv_inc_bk_prof;
 	ColumnAccessor < mCFStaticData_0 > inv_inc_earnings_accum;
 	ColumnAccessor < mCFStaticData_0 > inv_inc_fund;
 	ColumnAccessor < mCFStaticData_0 > inv_inc_on_invested_assets;
 	ColumnAccessor < mCFStaticData_0 > inv_inc_res;
 	ColumnAccessor < mCFStaticData_0 > inv_inc_tgt_cap;
 	ColumnAccessor < mCFStaticData_0 > inv_inc_undistrib_earnings;
 	ColumnAccessor < mCFStaticData_0 > irr;
 	ColumnAccessor < mCFStaticData_0 > irr_wo_tgt_cap;
 	ColumnAccessor < mCFStaticData_0 > issue_age_col_crbg;
 	ColumnAccessor < mCFStaticData_0 > itm_is_positive_crbg;
 	ColumnAccessor < mCFStaticData_0 > lapse_dyn_add_myga_crbg;
 	ColumnAccessor < mCFStaticData_0 > lapse_dyn_addn_crbg;
 	ColumnAccessor < mCFStaticData_0 > lapse_dyn_arctan_mult_crbg;
 	ColumnAccessor < mCFStaticData_0 > lapse_dyn_base_prod_crbg;
 	ColumnAccessor < mCFStaticData_0 > lapse_dyn_crediting_rt_crbg;
 	ColumnAccessor < mCFStaticData_0 > lapse_dyn_fa_mult_crbg;
 	ColumnAccessor < mCFStaticData_0 > lapse_dyn_isl_crbg;
 	ColumnAccessor < mCFStaticData_0 > lapse_dyn_mult_crbg;
 	ColumnAccessor < mCFStaticData_0 > lapse_dyn_sfc_mult_crbg;
 	ColumnAccessor < mCFStaticData_0 > lapse_rate;
 	ColumnAccessor < mCFStaticData_0 > lapse_rate_base;
 	ColumnAccessor < mCFStaticData_0 > lapse_rate_base_adj_crbg;
 	ColumnAccessor < mCFStaticData_0 > lapse_rate_mthly;
 	ColumnAccessor < mCFStaticData_0 > lapse_rate_mthly_skew2025_crbg;
 	ColumnAccessor < mCFStaticData_0 > lapse_rate_planned_numer;
 	ColumnAccessor < mCFStaticData_0 > lapse_skew_cumul_fct_fa_crbg;
 	ColumnAccessor < mCFStaticData_0 > lapse_skew_fct_fa_crbg;
 	ColumnAccessor < mCFStaticData_0 > last_period_indicator;
 	ColumnAccessor < mCFStaticData_0 > liab_and_surp;
 	ColumnAccessor < mCFStaticData_0 > maint_exp_bom;
 	ColumnAccessor < mCFStaticData_0 > maint_exp_eom;
 	ColumnAccessor < mCFStaticData_0 > maturity_benefits;
 	ColumnAccessor < mCFStaticData_0 > min_accum_val_b_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > min_accum_val_e_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > min_accum_val_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > min_contract_val;
 	ColumnAccessor < mCFStaticData_0 > min_contract_val_bef;
 	ColumnAccessor < mCFStaticData_0 > min_wdl_val_b_crbg;
 	ColumnAccessor < mCFStaticData_0 > min_wdl_val_e_bef_crbg;
 	ColumnAccessor < mCFStaticData_0 > min_wdl_val_e_crbg;
 	ColumnAccessor < mCFStaticData_0 > mort_rate_exp;
 	ColumnAccessor < mCFStaticData_0 > mort_rate_gmwb;
 	ColumnAccessor < mCFStaticData_0 > mths_since_issue;
 	ColumnAccessor < mCFStaticData_0 > mtt_call_gen2classic_cols;
 	ColumnAccessor < mCFStaticData_0 > mtt_call_mbvnb_crbg;
 	ColumnAccessor < mCFStaticData_0 > mtt_call_vectorized_cols;
 	ColumnAccessor < mCFStaticData_0 > mtt_irr;
 	ColumnAccessor < mCFStaticData_0 > mtt_target_all;
 	ColumnAccessor < mCFStaticData_0 > mtt_tgt_distrib_earnings;
 	ColumnAccessor < mCFStaticData_0 > mtt_tgt_gaap_inc_aft_tax;
 	ColumnAccessor < mCFStaticData_0 > mtt_valn_tgt_gaap_mrb;
 	ColumnAccessor < mCFStaticData_0 > mtt_valn_tgt_gaap_sfas97rd;
 	ColumnAccessor < mCFStaticData_256 > mtt_valn_tgt_pba_scen_amt;
 	ColumnAccessor < mCFStaticData_256 > mtt_valn_tgt_stat_tax;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_bef_crbg;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_crbg;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_excess_withdrl_crbg;
 	ColumnAccessor < mCFStaticData_256 > mva_comp_num;
 	ColumnAccessor < mCFStaticData_256 > mva_comp_rate;
 	ColumnAccessor < mCFStaticData_256 > mva_current_term_crbg;
 	ColumnAccessor < mCFStaticData_256 > mva_factor_bef_crbg;
 	ColumnAccessor < mCFStaticData_256 > mva_factor_crbg;
 	ColumnAccessor < mCFStaticData_256 > mva_guar_yrs_remaining;
 	ColumnAccessor < mCFStaticData_256 > mva_ratio;
 	ColumnAccessor < mCFStaticData_256 > mva_ratio_bef;
 	ColumnAccessor < mCFStaticData_256 > myga_current_term_crbg;
 	ColumnAccessor < mCFStaticData_256 > myga_term_mth_elapsed_eom_crbg;
 	ColumnAccessor < mCFStaticData_256 > new_money_rate_crbg;
 	ColumnAccessor < mCFStaticData_256 > nmr_7yr_govt_plus_sprd_crbg;
 	ColumnAccessor < mCFStaticData_256 > notional_to_hedge;
 	ColumnAccessor < mCFStaticData_256 > notional_to_hedge_cap;
 	ColumnAccessor < mCFStaticData_256 > notional_to_hedge_index;
 	ColumnAccessor < mCFStaticData_256 > notional_to_hedge_long_strike;
 	ColumnAccessor < mCFStaticData_256 > notional_to_hedge_net;
 	ColumnAccessor < mCFStaticData_256 > opt_budget;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_amt;
 	ColumnAccessor < mCFStaticData_256 > opt_payoff;
 	ColumnAccessor < mCFStaticData_256 > pba_rollforward_base;
 	ColumnAccessor < mCFStaticData_256 > pba_rollforward_base_issued;
 	ColumnAccessor < mCFStaticData_256 > pba_rollforward_factor;
 	ColumnAccessor < mCFStaticData_256 > pfwd_entitlement;
 	ColumnAccessor < mCFStaticData_256 > pfwd_entitlement_remaining_bom;
 	ColumnAccessor < mCFStaticData_256 > pfwd_entitlement_remaining_e;
 	ColumnAccessor < mCFStaticData_256 > pfwd_rate_dynamic;
 	ColumnAccessor < mCFStaticData_256 > pfwd_rate_mthly_fund_val;
 	ColumnAccessor < mCFStaticData_256 > pfwd_surr_contract_val;
 	ColumnAccessor < mCFStaticData_256 > pfwd_surr_cumul;
 	ColumnAccessor < mCFStaticData_256 > pfwd_surr_cumul_bom;
 	ColumnAccessor < mCFStaticData_256 > pfwd_surr_curr_pol_yr;
 	ColumnAccessor < mCFStaticData_256 > pfwd_surr_fund_val;
 	ColumnAccessor < mCFStaticData_256 > pfwd_use_crbg;
 	ColumnAccessor < mCFStaticData_256 > pol_mth;
 	ColumnAccessor < mCFStaticData_256 > pol_yr;
 	ColumnAccessor < mCFStaticData_256 > policies_b;
 	ColumnAccessor < mCFStaticData_256 > policies_female_inf_crbg;
 	ColumnAccessor < mCFStaticData_256 > policies_inf;
 	ColumnAccessor < mCFStaticData_256 > policies_issued;
 	ColumnAccessor < mCFStaticData_256 > policies_joint_inf_crbg;
 	ColumnAccessor < mCFStaticData_256 > policies_last_survivor_inf_crbg;
 	ColumnAccessor < mCFStaticData_256 > policies_male_inf_crbg;
 	ColumnAccessor < mCFStaticData_256 > port_yld_aft_tax;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_base_e_bef_crbg;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_base_e_crbg;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_base_reduction_fct_crbg;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_recap_e_bef_crbg;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_recap_e_crbg;
 	ColumnAccessor < mCFStaticData_256 > prem_cumul;
 	ColumnAccessor < mCFStaticData_256 > prem_cumul_bef;
 	ColumnAccessor < mCFStaticData_256 > prem_cumul_net_wdl_bef_crbg;
 	ColumnAccessor < mCFStaticData_256 > prem_cumul_net_wdl_crbg;
 	ColumnAccessor < mCFStaticData_256 > prem_cumul_prop_wdl_bef_crbg;
 	ColumnAccessor < mCFStaticData_256 > prem_cumul_prop_wdl_crbg;
 	ColumnAccessor < mCFStaticData_256 > prem_issued;
 	ColumnAccessor < mCFStaticData_256 > prem_paid;
 	ColumnAccessor < mCFStaticData_256 > prem_paid_net;
 	ColumnAccessor < mCFStaticData_256 > prem_tax;
 	ColumnAccessor < mCFStaticData_256 > pv_ann_ben_disc_uel_crbg;
 	ColumnAccessor < mCFStaticData_256 > pv_bom_cf_disc_uel_crbg;
 	ColumnAccessor < mCFStaticData_256 > pv_eom_cf_disc_uel_crbg;
 	ColumnAccessor < mCFStaticData_256 > pv_gmwb_ben_itm_current_crbg;
 	ColumnAccessor < mCFStaticData_256 > pv_gmwb_ben_itm_init_rate_crbg;
 	ColumnAccessor < mCFStaticData_256 > pv_gmwb_benefit_itm;
 	ColumnAccessor < mCFStaticData_256 > pv_gmwb_mawp_crbg;
 	ColumnAccessor < mCFStaticData_256 > pv_gmwb_pip_pct_crbg;
 	ColumnAccessor < mCFStaticData_256 > pv_sfc_ben_itm_crbg;
 	ColumnAccessor < mCFStaticData_256 > rand_num_non_us_return_crbg;
 	ColumnAccessor < mCFStaticData_256 > rbc;
 	ColumnAccessor < mCFStaticData_256 > rbc_c1;
 	ColumnAccessor < mCFStaticData_256 > rbc_c2;
 	ColumnAccessor < mCFStaticData_256 > rbc_c2_nar;
 	ColumnAccessor < mCFStaticData_256 > rbc_c3;
 	ColumnAccessor < mCFStaticData_256 > rbc_c3_base_ann_high_risk;
 	ColumnAccessor < mCFStaticData_256 > rbc_c3_base_ann_low_risk;
 	ColumnAccessor < mCFStaticData_256 > rbc_c3_base_ann_medium_risk;
 	ColumnAccessor < mCFStaticData_256 > rbc_c3_mp;
 	ColumnAccessor < mCFStaticData_256 > rbc_c3_stoch_amt;
 	ColumnAccessor < mCFStaticData_256 > rbc_c3_stoch_amt_unhedged;
 	ColumnAccessor < mCFStaticData_256 > rbc_c3_unhedged;
 	ColumnAccessor < mCFStaticData_256 > rbc_c4;
 	ColumnAccessor < mCFStaticData_256 > reins_ann_benefits_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_ann_claims_gmwb;
 	ColumnAccessor < mCFStaticData_256 > reins_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_cash_flow_int;
 	ColumnAccessor < mCFStaticData_256 > reins_cash_val;
 	ColumnAccessor < mCFStaticData_256 > reins_comm_chargeback_reimb;
 	ColumnAccessor < mCFStaticData_256 > reins_comm_reimb;
 	ColumnAccessor < mCFStaticData_256 > reins_comm_reimb_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_comm_reimb_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_dth_ben_inf;
 	ColumnAccessor < mCFStaticData_256 > reins_dth_benefits;
 	ColumnAccessor < mCFStaticData_256 > reins_exp;
 	ColumnAccessor < mCFStaticData_256 > reins_exp_reimb;
 	ColumnAccessor < mCFStaticData_256 > reins_exp_reimb_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_exp_reimb_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_ben_res;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_capzd_prem_bonus;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_cash_flow_int;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_chg_inc;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_comm_excess_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_comm_trail_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_comm_trail_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_cost;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_credited_int;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_dac;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_dac_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_inv_inc_res;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_liab_net;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_loads_deducted;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_mrb_liab;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_mrb_liab_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_prem_bonus;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_prem_tax;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_recoveries;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_sfas133_liab;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_sfas133_liab_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_surr_inc;
 	ColumnAccessor < mCFStaticData_256 > reins_inv_inc_res;
 	ColumnAccessor < mCFStaticData_256 > reins_maturity_benefits;
 	ColumnAccessor < mCFStaticData_256 > reins_prem;
 	ColumnAccessor < mCFStaticData_256 > reins_prem_base;
 	ColumnAccessor < mCFStaticData_256 > reins_prem_gmwb;
 	ColumnAccessor < mCFStaticData_256 > reins_prem_tax;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_cost;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_res;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_res_mp;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_res_npr;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_res_unhedged;
 	ColumnAccessor < mCFStaticData_256 > reins_surr_benefits;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_res;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_res_mp;
 	ColumnAccessor < mCFStaticData_256 > reins_withdrl_benefits;
 	ColumnAccessor < mCFStaticData_256 > shock_lapse_phase_crbg;
 	ColumnAccessor < mCFStaticData_256 > shock_lapse_yr_ind_crbg;
 	ColumnAccessor < mCFStaticData_256 > startup;
 	ColumnAccessor < mCFStaticData_256 > stat_res;
 	ColumnAccessor < mCFStaticData_256 > stat_res_carvm;
 	ColumnAccessor < mCFStaticData_256 > stat_res_carvm_net;
 	ColumnAccessor < mCFStaticData_256 > stat_res_excess;
 	ColumnAccessor < mCFStaticData_256 > stat_res_excess_unhedged;
 	ColumnAccessor < mCFStaticData_256 > stat_res_incr;
 	ColumnAccessor < mCFStaticData_256 > stat_res_mp;
 	ColumnAccessor < mCFStaticData_256 > stat_res_mp_unhedged;
 	ColumnAccessor < mCFStaticData_256 > stat_res_net;
 	ColumnAccessor < mCFStaticData_256 > stat_res_net_excess;
 	ColumnAccessor < mCFStaticData_256 > stat_res_net_excess_unhedged;
 	ColumnAccessor < mCFStaticData_256 > stat_res_net_mp;
 	ColumnAccessor < mCFStaticData_256 > stat_res_net_mp_unhedged;
 	ColumnAccessor < mCFStaticData_256 > stat_res_net_npr;
 	ColumnAccessor < mCFStaticData_256 > stat_res_net_npr_unhedged;
 	ColumnAccessor < mCFStaticData_256 > stat_res_net_stoch_res;
 	ColumnAccessor < mCFStaticData_256 > stat_res_net_stoch_res_unhedged;
 	ColumnAccessor < mCFStaticData_256 > stat_res_net_unhedged;
 	ColumnAccessor < mCFStaticData_256 > stat_res_npr;
 	ColumnAccessor < mCFStaticData_256 > stat_res_npr_unhedged;
 	ColumnAccessor < mCFStaticData_256 > stat_res_stoch_res;
 	ColumnAccessor < mCFStaticData_256 > stat_res_stoch_res_unhedged;
 	ColumnAccessor < mCFStaticData_256 > stat_res_unhedged;
 	ColumnAccessor < mCFStaticData_256 > surr_benefits;
 	ColumnAccessor < mCFStaticData_256 > surr_chg;
 	ColumnAccessor < mCFStaticData_256 > surr_chg_excess_withdrl_crbg;
 	ColumnAccessor < mCFStaticData_256 > surr_chg_inf;
 	ColumnAccessor < mCFStaticData_256 > surr_chg_inf_bef;
 	ColumnAccessor < mCFStaticData_256 > surr_chg_inf_wo_mva;
 	ColumnAccessor < mCFStaticData_256 > surr_chg_inf_wo_mva_bef;
 	ColumnAccessor < mCFStaticData_256 > surr_chg_pct_crbg;
 	ColumnAccessor < mCFStaticData_256 > surv;
 	ColumnAccessor < mCFStaticData_256 > surv_period;
 	ColumnAccessor < mCFStaticData_256 > tax_bk_prof;
 	ColumnAccessor < mCFStaticData_256 > tax_bk_prof_ytd;
 	ColumnAccessor < mCFStaticData_256 > tax_capzd_prem;
 	ColumnAccessor < mCFStaticData_256 > tax_capzd_prem_amortzn;
 	ColumnAccessor < mCFStaticData_256 > tax_capzd_prem_unamortzd;
 	ColumnAccessor < mCFStaticData_256 > tax_earnings_accum;
 	ColumnAccessor < mCFStaticData_256 > tax_earnings_accum_ytd;
 	ColumnAccessor < mCFStaticData_256 > tax_res;
 	ColumnAccessor < mCFStaticData_256 > tax_res_carvm;
 	ColumnAccessor < mCFStaticData_256 > tax_res_carvm_net;
 	ColumnAccessor < mCFStaticData_256 > tax_res_incr;
 	ColumnAccessor < mCFStaticData_256 > tax_res_mp;
 	ColumnAccessor < mCFStaticData_256 > tax_tgt_cap;
 	ColumnAccessor < mCFStaticData_256 > tax_tgt_cap_ytd;
 	ColumnAccessor < mCFStaticData_256 > taxable_inc_bk_prof;
 	ColumnAccessor < mCFStaticData_256 > taxable_inc_bk_prof_ytd;
 	ColumnAccessor < mCFStaticData_256 > taxable_inc_carryfwd_addn_ytd;
 	ColumnAccessor < mCFStaticData_256 > taxable_inc_carryfwd_applied_ytd;
 	ColumnAccessor < mCFStaticData_256 > taxable_inc_carryfwd_avail;
 	ColumnAccessor < mCFStaticData_256 > taxable_inc_earnings_accum;
 	ColumnAccessor < mCFStaticData_256 > taxable_inc_earnings_accum_ytd;
 	ColumnAccessor < mCFStaticData_256 > taxable_inc_tgt_cap;
 	ColumnAccessor < mCFStaticData_256 > taxable_inc_tgt_cap_ytd;
 	ColumnAccessor < mCFStaticData_256 > tgt_cap;
 	ColumnAccessor < mCFStaticData_256 > tgt_cap_effect;
 	ColumnAccessor < mCFStaticData_256 > tgt_cap_incr;
 	ColumnAccessor < mCFStaticData_256 > undistrib_earnings;
 	ColumnAccessor < mCFStaticData_256 > valn_tgt_gaap_mrb;
 	ColumnAccessor < mCFStaticData_256 > valn_tgt_gaap_sfas97rd;
 	ColumnAccessor < mCFStaticData_256 > valn_tgt_pba_scen_amt;
 	ColumnAccessor < mCFStaticData_256 > valn_tgt_stat_tax;
 	ColumnAccessor < mCFStaticData_256 > withdrl_benefits;
 	ColumnAccessor < mCFStaticData_256 > withdrl_benefits_gross_crbg;
 	ColumnAccessor < mCFStaticData_256 > zz_cash_val_wo_mva_bef;
//Column Definition END@2

 // Temporary Table...
	MonTable* ptr_tt_tax_capzd_prem_amortzn_sched;
	TempTableAccessor tax_capzd_prem_amortzn_sched;

_2D_FIACARVM_LIAB sm_carvm_stat;
_2D_FIACARVM_LIAB sm_carvm_tax;
_1D_FIAAFUND_LIAB sm_fia_account;
_1D_ANN_PBA_PBA sm_fia_ann_pba;
_1D_MRB_GAAP sm_fia_mrb;
RATES_ECONOMY *sm_fia_rates;
_1D_SFAS97RD_GAAP sm_fia_sfas97rd;
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
	#define DESCRIPTOR_TABLE FIA_LIAB::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > acq_exp_pct_prem;
  inline double	Get_acq_exp_pct_prem() {
		return acq_exp_pct_prem; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > acq_exp_per_pol;
  inline double	Get_acq_exp_per_pol() {
		return acq_exp_per_pol; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > admin_fee_per_pol;
  inline double	Get_admin_fee_per_pol() {
		return admin_fee_per_pol; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > ann_ben_partial_credit_ind_crbg;
  inline xstring	Get_ann_ben_partial_credit_ind_crbg() {
		return ann_ben_partial_credit_ind_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > ann_gmwb_claim_yr;
  inline double	Get_ann_gmwb_claim_yr() {
		return ann_gmwb_claim_yr; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > annuity_type_crbg;
  inline xstring	Get_annuity_type_crbg() {
		return annuity_type_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > annuitzn_base;
  inline double	Get_annuitzn_base() {
		return annuitzn_base; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > arctan_base_aft_shock_mult_crbg;
  inline double	Get_arctan_base_aft_shock_mult_crbg() {
		return arctan_base_aft_shock_mult_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > arctan_base_inc_mult_crbg;
  inline double	Get_arctan_base_inc_mult_crbg() {
		return arctan_base_inc_mult_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > arctan_base_shock_mult_crbg;
  inline double	Get_arctan_base_shock_mult_crbg() {
		return arctan_base_shock_mult_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > arctan_param1_crbg;
  inline double	Get_arctan_param1_crbg() {
		return arctan_param1_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > arctan_param2_crbg;
  inline double	Get_arctan_param2_crbg() {
		return arctan_param2_crbg; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_yld_comp_rate_id;
  inline xstring	Get_asset_yld_comp_rate_id() {
		return asset_yld_comp_rate_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_yld_defn;
  inline xstring	Get_asset_yld_defn() {
		return asset_yld_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > asset_yld_deterministic;
  inline double	Get_asset_yld_deterministic() {
		return asset_yld_deterministic; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > asset_yld_for_rate_setting;
  inline double	Get_asset_yld_for_rate_setting() {
		return asset_yld_for_rate_setting; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > audit_rpt_defn;
  inline xstring	Get_audit_rpt_defn() {
		return audit_rpt_defn; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > av_size_crbg;
  inline double	Get_av_size_crbg() {
		return av_size_crbg; }
  inline void Set_av_size_crbg(const double &v) {
		av_size_crbg.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > broker_crbg;
  inline xstring	Get_broker_crbg() {
		return broker_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > bs_dividend_crbg;
  inline double	Get_bs_dividend_crbg() {
		return bs_dividend_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > bs_fwd_vol_crbg;
  inline double	Get_bs_fwd_vol_crbg() {
		return bs_fwd_vol_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > calc_pv_gmwb_av_exhaustion_crbg;
  inline xstring	Get_calc_pv_gmwb_av_exhaustion_crbg() {
		return calc_pv_gmwb_av_exhaustion_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > capzd_acq_exp_pct_pct_prem;
  inline double	Get_capzd_acq_exp_pct_pct_prem() {
		return capzd_acq_exp_pct_pct_prem; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > capzd_acq_exp_pct_per_pol;
  inline double	Get_capzd_acq_exp_pct_per_pol() {
		return capzd_acq_exp_pct_per_pol; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > capzd_prem_bonus_pct;
  inline double	Get_capzd_prem_bonus_pct() {
		return capzd_prem_bonus_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_stat_annuitzn_tests;
  inline xstring	Get_carvm_stat_annuitzn_tests() {
		return carvm_stat_annuitzn_tests; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > carvm_stat_annuitzn_tests_cnt;
  inline int	Get_carvm_stat_annuitzn_tests_cnt() {
		return carvm_stat_annuitzn_tests_cnt; }
  inline void Set_carvm_stat_annuitzn_tests_cnt(const int &v) {
		carvm_stat_annuitzn_tests_cnt.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > carvm_stat_detail_rpt_defn;
  inline xstring	Get_carvm_stat_detail_rpt_defn() {
		return carvm_stat_detail_rpt_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_stat_gmwb_exercise_points_attained_age;
  inline xstring	Get_carvm_stat_gmwb_exercise_points_attained_age() {
		return carvm_stat_gmwb_exercise_points_attained_age; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_stat_gmwb_exercise_points_issue;
  inline xstring	Get_carvm_stat_gmwb_exercise_points_issue() {
		return carvm_stat_gmwb_exercise_points_issue; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_stat_gmwb_exercise_points_valn_prd;
  inline xstring	Get_carvm_stat_gmwb_exercise_points_valn_prd() {
		return carvm_stat_gmwb_exercise_points_valn_prd; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_tax_annuitzn_tests;
  inline xstring	Get_carvm_tax_annuitzn_tests() {
		return carvm_tax_annuitzn_tests; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > carvm_tax_annuitzn_tests_cnt;
  inline int	Get_carvm_tax_annuitzn_tests_cnt() {
		return carvm_tax_annuitzn_tests_cnt; }
  inline void Set_carvm_tax_annuitzn_tests_cnt(const int &v) {
		carvm_tax_annuitzn_tests_cnt.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > carvm_tax_detail_rpt_defn;
  inline xstring	Get_carvm_tax_detail_rpt_defn() {
		return carvm_tax_detail_rpt_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_tax_gmwb_exercise_points_attained_age;
  inline xstring	Get_carvm_tax_gmwb_exercise_points_attained_age() {
		return carvm_tax_gmwb_exercise_points_attained_age; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_tax_gmwb_exercise_points_issue;
  inline xstring	Get_carvm_tax_gmwb_exercise_points_issue() {
		return carvm_tax_gmwb_exercise_points_issue; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > carvm_tax_gmwb_exercise_points_valn_prd;
  inline xstring	Get_carvm_tax_gmwb_exercise_points_valn_prd() {
		return carvm_tax_gmwb_exercise_points_valn_prd; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cash_flow_pct_by_prod_crbg;
  inline double	Get_cash_flow_pct_by_prod_crbg() {
		return cash_flow_pct_by_prod_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cash_flow_pct_vector_crbg;
  inline double	Get_cash_flow_pct_vector_crbg() {
		return cash_flow_pct_vector_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comm_chargeback_pct;
  inline double	Get_comm_chargeback_pct() {
		return comm_chargeback_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comm_chgback_pct_dth_crbg;
  inline double	Get_comm_chgback_pct_dth_crbg() {
		return comm_chgback_pct_dth_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comm_chgback_pct_surr_crbg;
  inline double	Get_comm_chgback_pct_surr_crbg() {
		return comm_chgback_pct_surr_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comm_pct_fund;
  inline double	Get_comm_pct_fund() {
		return comm_pct_fund; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comm_pct_prem;
  inline double	Get_comm_pct_prem() {
		return comm_pct_prem; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > comp_rate_compared_defn;
  inline xstring	Get_comp_rate_compared_defn() {
		return comp_rate_compared_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > comp_rate_compared_rate1_id;
  inline xstring	Get_comp_rate_compared_rate1_id() {
		return comp_rate_compared_rate1_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > comp_rate_compared_rate2_id;
  inline xstring	Get_comp_rate_compared_rate2_id() {
		return comp_rate_compared_rate2_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > comp_rate_compared_rate3_id;
  inline xstring	Get_comp_rate_compared_rate3_id() {
		return comp_rate_compared_rate3_id; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > comp_rate_id;
  inline xstring	Get_comp_rate_id() {
		return comp_rate_id; }
  inline void Set_comp_rate_id(const xstring &v) {
		comp_rate_id.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comp_rate_single_addn;
  inline double	Get_comp_rate_single_addn() {
		return comp_rate_single_addn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > comp_rate_single_avg_mths;
  inline int	Get_comp_rate_single_avg_mths() {
		return comp_rate_single_avg_mths; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comp_rate_single_mult;
  inline double	Get_comp_rate_single_mult() {
		return comp_rate_single_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comp_rate_single_scen_yr;
  inline double	Get_comp_rate_single_scen_yr() {
		return comp_rate_single_scen_yr; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > comp_rate_type;
  inline xstring	Get_comp_rate_type() {
		return comp_rate_type; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > comp_rate_weighted_rate1_id;
  inline xstring	Get_comp_rate_weighted_rate1_id() {
		return comp_rate_weighted_rate1_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comp_rate_weighted_rate1_weight;
  inline double	Get_comp_rate_weighted_rate1_weight() {
		return comp_rate_weighted_rate1_weight; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > comp_rate_weighted_rate2_id;
  inline xstring	Get_comp_rate_weighted_rate2_id() {
		return comp_rate_weighted_rate2_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comp_rate_weighted_rate2_weight;
  inline double	Get_comp_rate_weighted_rate2_weight() {
		return comp_rate_weighted_rate2_weight; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > comp_rate_weighted_rate3_id;
  inline xstring	Get_comp_rate_weighted_rate3_id() {
		return comp_rate_weighted_rate3_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comp_rate_weighted_rate3_weight;
  inline double	Get_comp_rate_weighted_rate3_weight() {
		return comp_rate_weighted_rate3_weight; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > confinement_age_crbg;
  inline int	Get_confinement_age_crbg() {
		return confinement_age_crbg; }
  inline void Set_confinement_age_crbg(const int &v) {
		confinement_age_crbg.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > confinement_incidence_crbg;
  inline double	Get_confinement_incidence_crbg() {
		return confinement_incidence_crbg; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > confinement_mth_crbg;
  inline int	Get_confinement_mth_crbg() {
		return confinement_mth_crbg; }
  inline void Set_confinement_mth_crbg(const int &v) {
		confinement_mth_crbg.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > confinement_recovery_crbg;
  inline double	Get_confinement_recovery_crbg() {
		return confinement_recovery_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > confinement_recovery_mult_aig;
  inline double	Get_confinement_recovery_mult_aig() {
		return confinement_recovery_mult_aig; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > confinement_yrs_crbg;
  inline int	Get_confinement_yrs_crbg() {
		return confinement_yrs_crbg; }
  inline void Set_confinement_yrs_crbg(const int &v) {
		confinement_yrs_crbg.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > contract_val_net_consideration_pct;
  inline double	Get_contract_val_net_consideration_pct() {
		return contract_val_net_consideration_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > contract_val_sc_defn;
  inline xstring	Get_contract_val_sc_defn() {
		return contract_val_sc_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_asset_yld_sprd;
  inline double	Get_crediting_asset_yld_sprd() {
		return crediting_asset_yld_sprd; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > crediting_nb_defn;
  inline xstring	Get_crediting_nb_defn() {
		return crediting_nb_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_nb_yld_maturity;
  inline double	Get_crediting_nb_yld_maturity() {
		return crediting_nb_yld_maturity; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > crediting_nb_yld_rating;
  inline xstring	Get_crediting_nb_yld_rating() {
		return crediting_nb_yld_rating; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_ner_crbg;
  inline double	Get_crediting_ner_crbg() {
		return crediting_ner_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_rate_fixed;
  inline double	Get_crediting_rate_fixed() {
		return crediting_rate_fixed; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_rate_gtd;
  inline double	Get_crediting_rate_gtd() {
		return crediting_rate_gtd; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_rate_min;
  inline double	Get_crediting_rate_min() {
		return crediting_rate_min; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > crediting_strategy_crbg;
  inline xstring	Get_crediting_strategy_crbg() {
		return crediting_strategy_crbg; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > data_file_name_input;
  inline xstring	Get_data_file_name_input() {
		return data_file_name_input; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > data_validation_defn;
  inline xstring	Get_data_validation_defn() {
		return data_validation_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > decrements_defn;
  inline xstring	Get_decrements_defn() {
		return decrements_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > disc_rate_addn;
  inline double	Get_disc_rate_addn() {
		return disc_rate_addn; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > disc_rate_id;
  inline xstring	Get_disc_rate_id() {
		return disc_rate_id; }
  inline void Set_disc_rate_id(const xstring &v) {
		disc_rate_id.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > disc_rate_mult;
  inline double	Get_disc_rate_mult() {
		return disc_rate_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > disc_rate_port_yld_defn;
  inline xstring	Get_disc_rate_port_yld_defn() {
		return disc_rate_port_yld_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > disc_rate_scen_yr;
  inline double	Get_disc_rate_scen_yr() {
		return disc_rate_scen_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > disc_rate_sprd_ic_uel_crbg;
  inline double	Get_disc_rate_sprd_ic_uel_crbg() {
		return disc_rate_sprd_ic_uel_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > disc_rate_sprd_no_uel_crbg;
  inline double	Get_disc_rate_sprd_no_uel_crbg() {
		return disc_rate_sprd_no_uel_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > disc_rate_sprd_uel_crbg;
  inline double	Get_disc_rate_sprd_uel_crbg() {
		return disc_rate_sprd_uel_crbg; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > disc_rates_selected;
  inline xstring	Get_disc_rates_selected() {
		return disc_rates_selected; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > dth_ben_defn;
  inline xstring	Get_dth_ben_defn() {
		return dth_ben_defn; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > dyn_sprd_crbg;
  inline double	Get_dyn_sprd_crbg() {
		return dyn_sprd_crbg; }
  inline void Set_dyn_sprd_crbg(const double &v) {
		dyn_sprd_crbg.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > dynamic_lapse_gmwb_itm_threshold;
  inline double	Get_dynamic_lapse_gmwb_itm_threshold() {
		return dynamic_lapse_gmwb_itm_threshold; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > enh_inc_mawp_mult;
  inline double	Get_enh_inc_mawp_mult() {
		return enh_inc_mawp_mult; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > enh_inc_max_cumul_yrs;
  inline int	Get_enh_inc_max_cumul_yrs() {
		return enh_inc_max_cumul_yrs; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > enh_inc_utilization_pct;
  inline double	Get_enh_inc_utilization_pct() {
		return enh_inc_utilization_pct; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > enh_inc_wait_period;
  inline int	Get_enh_inc_wait_period() {
		return enh_inc_wait_period; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > enhanced_income_ind_crbg;
  inline xstring	Get_enhanced_income_ind_crbg() {
		return enhanced_income_ind_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > eprs_sfc_defn;
  inline xstring	Get_eprs_sfc_defn() {
		return eprs_sfc_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > exp_adj_mult;
  inline double	Get_exp_adj_mult() {
		return exp_adj_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_base_lapse_crbg;
  inline double	Get_fa_base_lapse_crbg() {
		return fa_base_lapse_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_credit_dyn_beta_a_crbg;
  inline double	Get_fa_credit_dyn_beta_a_crbg() {
		return fa_credit_dyn_beta_a_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_credit_dyn_beta_b_crbg;
  inline double	Get_fa_credit_dyn_beta_b_crbg() {
		return fa_credit_dyn_beta_b_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_credit_dyn_beta_c_crbg;
  inline double	Get_fa_credit_dyn_beta_c_crbg() {
		return fa_credit_dyn_beta_c_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_dyn_lapse_av_size_mult_crbg;
  inline double	Get_fa_dyn_lapse_av_size_mult_crbg() {
		return fa_dyn_lapse_av_size_mult_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_dyn_lapse_dyn_sprd_mult_crbg;
  inline double	Get_fa_dyn_lapse_dyn_sprd_mult_crbg() {
		return fa_dyn_lapse_dyn_sprd_mult_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_dyn_lapse_mult_alpha_crbg;
  inline double	Get_fa_dyn_lapse_mult_alpha_crbg() {
		return fa_dyn_lapse_mult_alpha_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_dyn_lapse_mult_beta_crbg;
  inline double	Get_fa_dyn_lapse_mult_beta_crbg() {
		return fa_dyn_lapse_mult_beta_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_guar_rate_crbg;
  inline double	Get_fa_guar_rate_crbg() {
		return fa_guar_rate_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_init_bonus_crbg;
  inline double	Get_fa_init_bonus_crbg() {
		return fa_init_bonus_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_init_pri_sprd_crbg;
  inline double	Get_fa_init_pri_sprd_crbg() {
		return fa_init_pri_sprd_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_lapse_factor_crbg;
  inline double	Get_fa_lapse_factor_crbg() {
		return fa_lapse_factor_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_ner_cap_sprd_crbg;
  inline double	Get_fa_ner_cap_sprd_crbg() {
		return fa_ner_cap_sprd_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_pricing_rate;
  inline double	Get_fa_pricing_rate() {
		return fa_pricing_rate; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > fa_rate_migration_yr_crbg;
  inline int	Get_fa_rate_migration_yr_crbg() {
		return fa_rate_migration_yr_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fa_renew_rate_max_crbg;
  inline double	Get_fa_renew_rate_max_crbg() {
		return fa_renew_rate_max_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fund_val_beg_term;
  inline double	Get_fund_val_beg_term() {
		return fund_val_beg_term; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > fund_val_rebal_defn;
  inline xstring	Get_fund_val_rebal_defn() {
		return fund_val_rebal_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > fund_val_rebal_freq_defn;
  inline xstring	Get_fund_val_rebal_freq_defn() {
		return fund_val_rebal_freq_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > fund_val_rebal_prop_defn;
  inline xstring	Get_fund_val_rebal_prop_defn() {
		return fund_val_rebal_prop_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > gaap_cohorts_selected_sfas97rd;
  inline xstring	Get_gaap_cohorts_selected_sfas97rd() {
		return gaap_cohorts_selected_sfas97rd; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gaap_defn;
  inline xstring	Get_gaap_defn() {
		return gaap_defn; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > gaap_int_rate;
  inline double	Get_gaap_int_rate() {
		return gaap_int_rate; }
  inline void Set_gaap_int_rate(const double &v) {
		gaap_int_rate.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gaap_int_rate_input;
  inline double	Get_gaap_int_rate_input() {
		return gaap_int_rate_input; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > gen2_declarations;
  inline xstring	Get_gen2_declarations() {
		return gen2_declarations; }
  inline void Set_gen2_declarations(const xstring &v) {
		gen2_declarations.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gender_aft_inc;
  inline xstring	Get_gender_aft_inc() {
		return gender_aft_inc; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gender_mp;
  inline xstring	Get_gender_mp() {
		return gender_mp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > glb_itm_disc_rate;
  inline double	Get_glb_itm_disc_rate() {
		return glb_itm_disc_rate; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmab_av_cap_rt_crbg;
  inline double	Get_gmab_av_cap_rt_crbg() {
		return gmab_av_cap_rt_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmab_chg_pct_crbg;
  inline double	Get_gmab_chg_pct_crbg() {
		return gmab_chg_pct_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmab_credit_rt_mult_crbg;
  inline double	Get_gmab_credit_rt_mult_crbg() {
		return gmab_credit_rt_mult_crbg; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmab_csv_grop_yr_crbg;
  inline int	Get_gmab_csv_grop_yr_crbg() {
		return gmab_csv_grop_yr_crbg; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmab_ind_crbg;
  inline int	Get_gmab_ind_crbg() {
		return gmab_ind_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_chg_at_surr_crbg;
  inline xstring	Get_gmwb_chg_at_surr_crbg() {
		return gmwb_chg_at_surr_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_chg_base;
  inline xstring	Get_gmwb_chg_base() {
		return gmwb_chg_base; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_chg_pct;
  inline double	Get_gmwb_chg_pct() {
		return gmwb_chg_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_chg_surr_timing_crbg;
  inline xstring	Get_gmwb_chg_surr_timing_crbg() {
		return gmwb_chg_surr_timing_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_claim_disc_rate;
  inline double	Get_gmwb_claim_disc_rate() {
		return gmwb_claim_disc_rate; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_claim_disc_rate_defn;
  inline xstring	Get_gmwb_claim_disc_rate_defn() {
		return gmwb_claim_disc_rate_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > gmwb_code;
  inline xstring	Get_gmwb_code() {
		return gmwb_code; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmwb_cohort_id;
  inline int	Get_gmwb_cohort_id() {
		return gmwb_cohort_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_cohort_utilz_defn;
  inline xstring	Get_gmwb_cohort_utilz_defn() {
		return gmwb_cohort_utilz_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_cohort_utilz_rate;
  inline double	Get_gmwb_cohort_utilz_rate() {
		return gmwb_cohort_utilz_rate; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_credit_aft_income_crbg;
  inline xstring	Get_gmwb_credit_aft_income_crbg() {
		return gmwb_credit_aft_income_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_credit_mult_aft_inc_crbg;
  inline double	Get_gmwb_credit_mult_aft_inc_crbg() {
		return gmwb_credit_mult_aft_inc_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_credit_mult_bef_inc_crbg;
  inline double	Get_gmwb_credit_mult_bef_inc_crbg() {
		return gmwb_credit_mult_bef_inc_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_defn;
  inline xstring	Get_gmwb_defn() {
		return gmwb_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmwb_doubling_year_crbg;
  inline int	Get_gmwb_doubling_year_crbg() {
		return gmwb_doubling_year_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_exercise_yrs;
  inline double	Get_gmwb_exercise_yrs() {
		return gmwb_exercise_yrs; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_flex_base_lapse_mult_crbg;
  inline double	Get_gmwb_flex_base_lapse_mult_crbg() {
		return gmwb_flex_base_lapse_mult_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_fund_val_defn;
  inline xstring	Get_gmwb_fund_val_defn() {
		return gmwb_fund_val_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_fund_val_period;
  inline double	Get_gmwb_fund_val_period() {
		return gmwb_fund_val_period; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmwb_ind;
  inline int	Get_gmwb_ind() {
		return gmwb_ind; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_mawp_addn_crbg;
  inline double	Get_gmwb_mawp_addn_crbg() {
		return gmwb_mawp_addn_crbg; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmwb_max_age;
  inline int	Get_gmwb_max_age() {
		return gmwb_max_age; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_max_annual_wdl_pct;
  inline double	Get_gmwb_max_annual_wdl_pct() {
		return gmwb_max_annual_wdl_pct; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > gmwb_max_exec_point;
  inline int	Get_gmwb_max_exec_point() {
		return gmwb_max_exec_point; }
  inline void Set_gmwb_max_exec_point(const int &v) {
		gmwb_max_exec_point.setValue(v); }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmwb_max_rollup_duration;
  inline int	Get_gmwb_max_rollup_duration() {
		return gmwb_max_rollup_duration; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_max_wdl_amt_base_defn;
  inline xstring	Get_gmwb_max_wdl_amt_base_defn() {
		return gmwb_max_wdl_amt_base_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmwb_min_age;
  inline int	Get_gmwb_min_age() {
		return gmwb_min_age; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_mort_base;
  inline double	Get_gmwb_mort_base() {
		return gmwb_mort_base; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > gmwb_mort_base_tbl_id;
  inline xstring	Get_gmwb_mort_base_tbl_id() {
		return gmwb_mort_base_tbl_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > gmwb_mort_base_tbl_style;
  inline xstring	Get_gmwb_mort_base_tbl_style() {
		return gmwb_mort_base_tbl_style; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_mrb_req_prof_chg;
  inline double	Get_gmwb_mrb_req_prof_chg() {
		return gmwb_mrb_req_prof_chg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_pfwd_dyn_defn;
  inline xstring	Get_gmwb_pfwd_dyn_defn() {
		return gmwb_pfwd_dyn_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_pfwd_dyn_mult;
  inline double	Get_gmwb_pfwd_dyn_mult() {
		return gmwb_pfwd_dyn_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_pipp_crbg;
  inline double	Get_gmwb_pipp_crbg() {
		return gmwb_pipp_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_pipp_stepup_crbg;
  inline double	Get_gmwb_pipp_stepup_crbg() {
		return gmwb_pipp_stepup_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_prem_defn;
  inline xstring	Get_gmwb_prem_defn() {
		return gmwb_prem_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_reg47_crbg;
  inline xstring	Get_gmwb_reg47_crbg() {
		return gmwb_reg47_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_reg47_slope_crbg;
  inline double	Get_gmwb_reg47_slope_crbg() {
		return gmwb_reg47_slope_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_rollup_cap;
  inline double	Get_gmwb_rollup_cap() {
		return gmwb_rollup_cap; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_rollup_credit_type_crbg;
  inline xstring	Get_gmwb_rollup_credit_type_crbg() {
		return gmwb_rollup_credit_type_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_rollup_freq_defn;
  inline xstring	Get_gmwb_rollup_freq_defn() {
		return gmwb_rollup_freq_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_rollup_rate;
  inline double	Get_gmwb_rollup_rate() {
		return gmwb_rollup_rate; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_rollup_rate_type;
  inline xstring	Get_gmwb_rollup_rate_type() {
		return gmwb_rollup_rate_type; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_step_up_rate;
  inline double	Get_gmwb_step_up_rate() {
		return gmwb_step_up_rate; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > gmwb_type_crbg;
  inline xstring	Get_gmwb_type_crbg() {
		return gmwb_type_crbg; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > gmwb_util_broker_type_crbg;
  inline xstring	Get_gmwb_util_broker_type_crbg() {
		return gmwb_util_broker_type_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_wait_period;
  inline double	Get_gmwb_wait_period() {
		return gmwb_wait_period; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_wdl_avg_util_pct_crbg;
  inline double	Get_gmwb_wdl_avg_util_pct_crbg() {
		return gmwb_wdl_avg_util_pct_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_wdl_next_util_prob_1_crbg;
  inline double	Get_gmwb_wdl_next_util_prob_1_crbg() {
		return gmwb_wdl_next_util_prob_1_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_wdl_next_util_prob_2_crbg;
  inline double	Get_gmwb_wdl_next_util_prob_2_crbg() {
		return gmwb_wdl_next_util_prob_2_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_wdl_random_util_rate_crbg;
  inline double	Get_gmwb_wdl_random_util_rate_crbg() {
		return gmwb_wdl_random_util_rate_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_wdl_reduce_ben_base;
  inline xstring	Get_gmwb_wdl_reduce_ben_base() {
		return gmwb_wdl_reduce_ben_base; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_wdl_trig_by_confinement;
  inline xstring	Get_gmwb_wdl_trig_by_confinement() {
		return gmwb_wdl_trig_by_confinement; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_wdl_util_init_crbg;
  inline double	Get_gmwb_wdl_util_init_crbg() {
		return gmwb_wdl_util_init_crbg; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > gmwb_wdl_util_level_crbg;
  inline int	Get_gmwb_wdl_util_level_crbg() {
		return gmwb_wdl_util_level_crbg; }
  inline void Set_gmwb_wdl_util_level_crbg(const int &v) {
		gmwb_wdl_util_level_crbg.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > gmwb_wdl_util_tgt_level_crbg;
  inline int	Get_gmwb_wdl_util_tgt_level_crbg() {
		return gmwb_wdl_util_tgt_level_crbg; }
  inline void Set_gmwb_wdl_util_tgt_level_crbg(const int &v) {
		gmwb_wdl_util_tgt_level_crbg.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_wdl_util_type_crbg;
  inline xstring	Get_gmwb_wdl_util_type_crbg() {
		return gmwb_wdl_util_type_crbg; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > gmwb_withdrl_age;
  inline int	Get_gmwb_withdrl_age() {
		return gmwb_withdrl_age; }
  inline void Set_gmwb_withdrl_age(const int &v) {
		gmwb_withdrl_age.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > gmwb_withdrl_yr_lookup;
  inline int	Get_gmwb_withdrl_yr_lookup() {
		return gmwb_withdrl_yr_lookup; }
  inline void Set_gmwb_withdrl_yr_lookup(const int &v) {
		gmwb_withdrl_yr_lookup.setValue(v); }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > grop_ind_crbg;
  inline int	Get_grop_ind_crbg() {
		return grop_ind_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gsia_reins_defn_crbg;
  inline xstring	Get_gsia_reins_defn_crbg() {
		return gsia_reins_defn_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gwl_acq_exp_allow_level_crbg;
  inline double	Get_gwl_acq_exp_allow_level_crbg() {
		return gwl_acq_exp_allow_level_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gwl_infl_addn_crbg;
  inline double	Get_gwl_infl_addn_crbg() {
		return gwl_infl_addn_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gwl_infl_mult1_crbg;
  inline double	Get_gwl_infl_mult1_crbg() {
		return gwl_infl_mult1_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gwl_infl_mult2_crbg;
  inline double	Get_gwl_infl_mult2_crbg() {
		return gwl_infl_mult2_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gwl_maint_exp_allow_level_crbg;
  inline double	Get_gwl_maint_exp_allow_level_crbg() {
		return gwl_maint_exp_allow_level_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > host_accrual_rate;
  inline double	Get_host_accrual_rate() {
		return host_accrual_rate; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > index_id_lookup;
  inline xstring	Get_index_id_lookup() {
		return index_id_lookup; }
  inline void Set_index_id_lookup(const xstring &v) {
		index_id_lookup.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_val_beg_term;
  inline double	Get_index_val_beg_term() {
		return index_val_beg_term; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > infl_deduction_crbg;
  inline double	Get_infl_deduction_crbg() {
		return infl_deduction_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > infl_mult_crbg;
  inline double	Get_infl_mult_crbg() {
		return infl_mult_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > infl_rate_const_crbg;
  inline double	Get_infl_rate_const_crbg() {
		return infl_rate_const_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > infl_rate_defn_crbg;
  inline xstring	Get_infl_rate_defn_crbg() {
		return infl_rate_defn_crbg; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > infl_start_date;
  inline xstring	Get_infl_start_date() {
		return infl_start_date; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_cap_rate_index0;
  inline double	Get_init_cap_rate_index0() {
		return init_cap_rate_index0; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_cap_rate_index1;
  inline double	Get_init_cap_rate_index1() {
		return init_cap_rate_index1; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_cap_rate_index2;
  inline double	Get_init_cap_rate_index2() {
		return init_cap_rate_index2; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_cap_rate_index3;
  inline double	Get_init_cap_rate_index3() {
		return init_cap_rate_index3; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_cap_rate_index4;
  inline double	Get_init_cap_rate_index4() {
		return init_cap_rate_index4; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_cash_val;
  inline double	Get_init_cash_val() {
		return init_cash_val; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_cash_val_no_mva;
  inline double	Get_init_cash_val_no_mva() {
		return init_cash_val_no_mva; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_comm_subject_to_chargeback;
  inline double	Get_init_comm_subject_to_chargeback() {
		return init_comm_subject_to_chargeback; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_contract_val;
  inline double	Get_init_contract_val() {
		return init_contract_val; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_crediting_rate_cumul;
  inline double	Get_init_crediting_rate_cumul() {
		return init_crediting_rate_cumul; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_eprs_part_rate;
  inline double	Get_init_eprs_part_rate() {
		return init_eprs_part_rate; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_fund_val_boy;
  inline double	Get_init_fund_val_boy() {
		return init_fund_val_boy; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_fund_val_fixed;
  inline double	Get_init_fund_val_fixed() {
		return init_fund_val_fixed; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_fund_val_index0;
  inline double	Get_init_fund_val_index0() {
		return init_fund_val_index0; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_fund_val_index1;
  inline double	Get_init_fund_val_index1() {
		return init_fund_val_index1; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_fund_val_index2;
  inline double	Get_init_fund_val_index2() {
		return init_fund_val_index2; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_fund_val_index3;
  inline double	Get_init_fund_val_index3() {
		return init_fund_val_index3; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_fund_val_index4;
  inline double	Get_init_fund_val_index4() {
		return init_fund_val_index4; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_gmab_av;
  inline double	Get_init_gmab_av() {
		return init_gmab_av; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_gmwb_entitlement_remaining;
  inline double	Get_init_gmwb_entitlement_remaining() {
		return init_gmwb_entitlement_remaining; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_gmwb_fund_val;
  inline double	Get_init_gmwb_fund_val() {
		return init_gmwb_fund_val; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_gmwb_income_credit_base;
  inline double	Get_init_gmwb_income_credit_base() {
		return init_gmwb_income_credit_base; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_gmwb_max_ann_wdl_pct;
  inline double	Get_init_gmwb_max_ann_wdl_pct() {
		return init_gmwb_max_ann_wdl_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_gmwb_max_wdl_amt;
  inline double	Get_init_gmwb_max_wdl_amt() {
		return init_gmwb_max_wdl_amt; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_gmwb_prem;
  inline double	Get_init_gmwb_prem() {
		return init_gmwb_prem; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_gmwb_wdl_excess_ind;
  inline double	Get_init_gmwb_wdl_excess_ind() {
		return init_gmwb_wdl_excess_ind; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_gmwb_wdl_util_level;
  inline double	Get_init_gmwb_wdl_util_level() {
		return init_gmwb_wdl_util_level; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_gmwb_wdl_util_pct;
  inline double	Get_init_gmwb_wdl_util_pct() {
		return init_gmwb_wdl_util_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_hedge_budget;
  inline double	Get_init_hedge_budget() {
		return init_hedge_budget; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_hedge_mkt_val_per_unit;
  inline double	Get_init_hedge_mkt_val_per_unit() {
		return init_hedge_mkt_val_per_unit; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_host_val;
  inline double	Get_init_host_val() {
		return init_host_val; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_index_val;
  inline double	Get_init_index_val() {
		return init_index_val; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_min_accum_val;
  inline double	Get_init_min_accum_val() {
		return init_min_accum_val; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_min_wdl_val;
  inline double	Get_init_min_wdl_val() {
		return init_min_wdl_val; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_opt_cost_beg_term;
  inline double	Get_init_opt_cost_beg_term() {
		return init_opt_cost_beg_term; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_part_rate_index0;
  inline double	Get_init_part_rate_index0() {
		return init_part_rate_index0; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_part_rate_index1;
  inline double	Get_init_part_rate_index1() {
		return init_part_rate_index1; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_part_rate_index2;
  inline double	Get_init_part_rate_index2() {
		return init_part_rate_index2; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_part_rate_index3;
  inline double	Get_init_part_rate_index3() {
		return init_part_rate_index3; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_part_rate_index4;
  inline double	Get_init_part_rate_index4() {
		return init_part_rate_index4; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_pfwd_curr_pol_yr;
  inline double	Get_init_pfwd_curr_pol_yr() {
		return init_pfwd_curr_pol_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_pfwd_entitlement;
  inline double	Get_init_pfwd_entitlement() {
		return init_pfwd_entitlement; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_policies;
  inline double	Get_init_policies() {
		return init_policies; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_policies_female_crbg;
  inline double	Get_init_policies_female_crbg() {
		return init_policies_female_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_policies_joint_crbg;
  inline double	Get_init_policies_joint_crbg() {
		return init_policies_joint_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_policies_male_crbg;
  inline double	Get_init_policies_male_crbg() {
		return init_policies_male_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_prem_bonus_base;
  inline double	Get_init_prem_bonus_base() {
		return init_prem_bonus_base; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_prem_net_wdl;
  inline double	Get_init_prem_net_wdl() {
		return init_prem_net_wdl; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_prem_prop_wdl;
  inline double	Get_init_prem_prop_wdl() {
		return init_prem_prop_wdl; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_rebal_pct_fixed;
  inline double	Get_init_rebal_pct_fixed() {
		return init_rebal_pct_fixed; }
	static Attribute::Descriptor descriptor_256[];
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4005)
// Disable the warning C4005: 'DESCRIPTOR_TABLE' : macro redefinition
#endif	MICROSOFT
	#define DESCRIPTOR_TABLE FIA_LIAB::descriptor_256
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_rebal_pct_index0;
  inline double	Get_init_rebal_pct_index0() {
		return init_rebal_pct_index0; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_rebal_pct_index1;
  inline double	Get_init_rebal_pct_index1() {
		return init_rebal_pct_index1; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_rebal_pct_index2;
  inline double	Get_init_rebal_pct_index2() {
		return init_rebal_pct_index2; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_rebal_pct_index3;
  inline double	Get_init_rebal_pct_index3() {
		return init_rebal_pct_index3; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_rebal_pct_index4;
  inline double	Get_init_rebal_pct_index4() {
		return init_rebal_pct_index4; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_sprd_rate_index0;
  inline double	Get_init_sprd_rate_index0() {
		return init_sprd_rate_index0; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_stat_res_carvm;
  inline double	Get_init_stat_res_carvm() {
		return init_stat_res_carvm; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_tax_res_carvm;
  inline double	Get_init_tax_res_carvm() {
		return init_tax_res_carvm; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_trigger_rate_index0;
  inline double	Get_init_trigger_rate_index0() {
		return init_trigger_rate_index0; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_withdrl_cumul;
  inline double	Get_init_withdrl_cumul() {
		return init_withdrl_cumul; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > isl_alpha_crbg;
  inline double	Get_isl_alpha_crbg() {
		return isl_alpha_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > isl_beta_crbg;
  inline double	Get_isl_beta_crbg() {
		return isl_beta_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > isl_coefficient_crbg;
  inline double	Get_isl_coefficient_crbg() {
		return isl_coefficient_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > isl_divisor_crbg;
  inline double	Get_isl_divisor_crbg() {
		return isl_divisor_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > isl_surr_chg_threshold;
  inline double	Get_isl_surr_chg_threshold() {
		return isl_surr_chg_threshold; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > issue_age_female_crbg;
  inline int	Get_issue_age_female_crbg() {
		return issue_age_female_crbg; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > issue_age_male_crbg;
  inline int	Get_issue_age_male_crbg() {
		return issue_age_male_crbg; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > issue_age_mp;
  inline int	Get_issue_age_mp() {
		return issue_age_mp; }
  inline void Set_issue_age_mp(const int &v) {
		issue_age_mp.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > issue_date_mp;
  inline xstring	Get_issue_date_mp() {
		return issue_date_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > itm_defn;
  inline xstring	Get_itm_defn() {
		return itm_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > itm_denom_defn_crbg;
  inline xstring	Get_itm_denom_defn_crbg() {
		return itm_denom_defn_crbg; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > itm_disc_curve_crbg;
  inline xstring	Get_itm_disc_curve_crbg() {
		return itm_disc_curve_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_adj_mult;
  inline double	Get_lapse_adj_mult() {
		return lapse_adj_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_dyn_base_prod_defn_crbg;
  inline xstring	Get_lapse_dyn_base_prod_defn_crbg() {
		return lapse_dyn_base_prod_defn_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_base_prod_max_crbg;
  inline double	Get_lapse_dyn_base_prod_max_crbg() {
		return lapse_dyn_base_prod_max_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_base_prod_min_crbg;
  inline double	Get_lapse_dyn_base_prod_min_crbg() {
		return lapse_dyn_base_prod_min_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_base_prod_mult1_crbg;
  inline double	Get_lapse_dyn_base_prod_mult1_crbg() {
		return lapse_dyn_base_prod_mult1_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_base_prod_mult2_crbg;
  inline double	Get_lapse_dyn_base_prod_mult2_crbg() {
		return lapse_dyn_base_prod_mult2_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_base_prod_threshold_crbg;
  inline double	Get_lapse_dyn_base_prod_threshold_crbg() {
		return lapse_dyn_base_prod_threshold_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_exp;
  inline double	Get_lapse_dyn_exp() {
		return lapse_dyn_exp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_exp_param_crbg;
  inline double	Get_lapse_dyn_exp_param_crbg() {
		return lapse_dyn_exp_param_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_dyn_isl_defn_crbg;
  inline xstring	Get_lapse_dyn_isl_defn_crbg() {
		return lapse_dyn_isl_defn_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_mult;
  inline double	Get_lapse_dyn_mult() {
		return lapse_dyn_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_mult_floor_crbg;
  inline double	Get_lapse_dyn_mult_floor_crbg() {
		return lapse_dyn_mult_floor_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_mva_mult_crbg;
  inline double	Get_lapse_dyn_mva_mult_crbg() {
		return lapse_dyn_mva_mult_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_dyn_preshock_sprd_crbg;
  inline xstring	Get_lapse_dyn_preshock_sprd_crbg() {
		return lapse_dyn_preshock_sprd_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_scmult;
  inline double	Get_lapse_dyn_scmult() {
		return lapse_dyn_scmult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_dyn_shock_yr_defn_crbg;
  inline xstring	Get_lapse_dyn_shock_yr_defn_crbg() {
		return lapse_dyn_shock_yr_defn_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_thresh;
  inline double	Get_lapse_dyn_thresh() {
		return lapse_dyn_thresh; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_is_dynamic;
  inline xstring	Get_lapse_is_dynamic() {
		return lapse_is_dynamic; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_rate_input;
  inline double	Get_lapse_rate_input() {
		return lapse_rate_input; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_rate_max;
  inline double	Get_lapse_rate_max() {
		return lapse_rate_max; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_rate_min;
  inline double	Get_lapse_rate_min() {
		return lapse_rate_min; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_shock_yr_max_crbg;
  inline double	Get_lapse_shock_yr_max_crbg() {
		return lapse_shock_yr_max_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_shock_yr_min_crbg;
  inline double	Get_lapse_shock_yr_min_crbg() {
		return lapse_shock_yr_min_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_skew_fct1_crbg;
  inline double	Get_lapse_skew_fct1_crbg() {
		return lapse_skew_fct1_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_skew_fct2_crbg;
  inline double	Get_lapse_skew_fct2_crbg() {
		return lapse_skew_fct2_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_skew_method_crbg;
  inline xstring	Get_lapse_skew_method_crbg() {
		return lapse_skew_method_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_skew_split_crbg;
  inline double	Get_lapse_skew_split_crbg() {
		return lapse_skew_split_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > licensing_fee_pct_crbg;
  inline double	Get_licensing_fee_pct_crbg() {
		return licensing_fee_pct_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > maint_exp_pct_fund;
  inline double	Get_maint_exp_pct_fund() {
		return maint_exp_pct_fund; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > maint_exp_per_pol;
  inline double	Get_maint_exp_per_pol() {
		return maint_exp_per_pol; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > male_sex_pct;
  inline double	Get_male_sex_pct() {
		return male_sex_pct; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > maturity_age_input;
  inline int	Get_maturity_age_input() {
		return maturity_age_input; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mav_growth_rate_crbg;
  inline double	Get_mav_growth_rate_crbg() {
		return mav_growth_rate_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > mawp_lookup_type_crbg;
  inline xstring	Get_mawp_lookup_type_crbg() {
		return mawp_lookup_type_crbg; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > min_cash_val_mths;
  inline int	Get_min_cash_val_mths() {
		return min_cash_val_mths; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_addn;
  inline double	Get_mort_addn() {
		return mort_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_adj_mult;
  inline double	Get_mort_adj_mult() {
		return mort_adj_mult; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > mort_attained_age;
  inline int	Get_mort_attained_age() {
		return mort_attained_age; }
  inline void Set_mort_attained_age(const int &v) {
		mort_attained_age.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_base;
  inline double	Get_mort_base() {
		return mort_base; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_base_confined_crbg;
  inline double	Get_mort_base_confined_crbg() {
		return mort_base_confined_crbg; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_base_curr_tbl_id;
  inline xstring	Get_mort_base_curr_tbl_id() {
		return mort_base_curr_tbl_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_base_curr_tbl_style;
  inline xstring	Get_mort_base_curr_tbl_style() {
		return mort_base_curr_tbl_style; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_base_guar_tbl_id;
  inline xstring	Get_mort_base_guar_tbl_id() {
		return mort_base_guar_tbl_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_base_guar_tbl_style;
  inline xstring	Get_mort_base_guar_tbl_style() {
		return mort_base_guar_tbl_style; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_base_non_confined_crbg;
  inline double	Get_mort_base_non_confined_crbg() {
		return mort_base_non_confined_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_base_omega;
  inline double	Get_mort_base_omega() {
		return mort_base_omega; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_base_tbl_id;
  inline xstring	Get_mort_base_tbl_id() {
		return mort_base_tbl_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_base_tbl_style;
  inline xstring	Get_mort_base_tbl_style() {
		return mort_base_tbl_style; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > mort_cal_yr;
  inline int	Get_mort_cal_yr() {
		return mort_cal_yr; }
  inline void Set_mort_cal_yr(const int &v) {
		mort_cal_yr.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > mort_calc_basis;
  inline xstring	Get_mort_calc_basis() {
		return mort_calc_basis; }
  inline void Set_mort_calc_basis(const xstring &v) {
		mort_calc_basis.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > mort_gender;
  inline xstring	Get_mort_gender() {
		return mort_gender; }
  inline void Set_mort_gender(const xstring &v) {
		mort_gender.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_impr_base_date_crbg;
  inline xstring	Get_mort_impr_base_date_crbg() {
		return mort_impr_base_date_crbg; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_impr_tbl_id;
  inline xstring	Get_mort_impr_tbl_id() {
		return mort_impr_tbl_id; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > mort_improve_base_yr;
  inline int	Get_mort_improve_base_yr() {
		return mort_improve_base_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_improve_pct;
  inline double	Get_mort_improve_pct() {
		return mort_improve_pct; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > mort_issue_age;
  inline int	Get_mort_issue_age() {
		return mort_issue_age; }
  inline void Set_mort_issue_age(const int &v) {
		mort_issue_age.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_mult;
  inline double	Get_mort_mult() {
		return mort_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_mult_confined_crbg;
  inline double	Get_mort_mult_confined_crbg() {
		return mort_mult_confined_crbg; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > mort_pol_yr;
  inline int	Get_mort_pol_yr() {
		return mort_pol_yr; }
  inline void Set_mort_pol_yr(const int &v) {
		mort_pol_yr.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mp_id;
  inline xstring	Get_mp_id() {
		return mp_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mva_adj_ratio_mult;
  inline double	Get_mva_adj_ratio_mult() {
		return mva_adj_ratio_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > mva_cap_defn_crbg;
  inline xstring	Get_mva_cap_defn_crbg() {
		return mva_cap_defn_crbg; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mva_comp_rate_id;
  inline xstring	Get_mva_comp_rate_id() {
		return mva_comp_rate_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > mva_constraint_defn;
  inline xstring	Get_mva_constraint_defn() {
		return mva_constraint_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > mva_defn;
  inline xstring	Get_mva_defn() {
		return mva_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > mva_guar_yrs_renewal;
  inline int	Get_mva_guar_yrs_renewal() {
		return mva_guar_yrs_renewal; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > mva_init_term;
  inline int	Get_mva_init_term() {
		return mva_init_term; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > mva_renewal_term_crbg;
  inline int	Get_mva_renewal_term_crbg() {
		return mva_renewal_term_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mwv_growth_pct_crbg;
  inline double	Get_mwv_growth_pct_crbg() {
		return mwv_growth_pct_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mwv_prem_pct_crbg;
  inline double	Get_mwv_prem_pct_crbg() {
		return mwv_prem_pct_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > myga_current_term;
  inline double	Get_myga_current_term() {
		return myga_current_term; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > myga_init_term_crbg;
  inline int	Get_myga_init_term_crbg() {
		return myga_init_term_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > myga_renew_ind_crbg;
  inline xstring	Get_myga_renew_ind_crbg() {
		return myga_renew_ind_crbg; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > myga_renew_term_crbg;
  inline int	Get_myga_renew_term_crbg() {
		return myga_renew_term_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > myga_term_mth_elapsed_eom;
  inline double	Get_myga_term_mth_elapsed_eom() {
		return myga_term_mth_elapsed_eom; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > nb_cap_rate_crbg;
  inline double	Get_nb_cap_rate_crbg() {
		return nb_cap_rate_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > nb_eprs_add_par_crbg;
  inline double	Get_nb_eprs_add_par_crbg() {
		return nb_eprs_add_par_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > nb_fixed_rate_crbg;
  inline double	Get_nb_fixed_rate_crbg() {
		return nb_fixed_rate_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > nb_opt_budget_input_crbg;
  inline double	Get_nb_opt_budget_input_crbg() {
		return nb_opt_budget_input_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > nb_part_rate_crbg;
  inline double	Get_nb_part_rate_crbg() {
		return nb_part_rate_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > nb_sprd_rate_crbg;
  inline double	Get_nb_sprd_rate_crbg() {
		return nb_sprd_rate_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > nb_trigger_rate_crbg;
  inline double	Get_nb_trigger_rate_crbg() {
		return nb_trigger_rate_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > ner_correction_crbg;
  inline xstring	Get_ner_correction_crbg() {
		return ner_correction_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > nmr_spread_crbg;
  inline double	Get_nmr_spread_crbg() {
		return nmr_spread_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > non_us_return_beta_crbg;
  inline double	Get_non_us_return_beta_crbg() {
		return non_us_return_beta_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > non_us_return_sigma_crbg;
  inline double	Get_non_us_return_sigma_crbg() {
		return non_us_return_sigma_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > ny_glb_ind_crbg;
  inline xstring	Get_ny_glb_ind_crbg() {
		return ny_glb_ind_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > nyia_ind_crbg;
  inline xstring	Get_nyia_ind_crbg() {
		return nyia_ind_crbg; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > opt_budget_const_yr_crbg;
  inline int	Get_opt_budget_const_yr_crbg() {
		return opt_budget_const_yr_crbg; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > opt_defn;
  inline xstring	Get_opt_defn() {
		return opt_defn; }
  inline void Set_opt_defn(const xstring &v) {
		opt_defn.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_base_lapse_mult_crbg;
  inline double	Get_pba_base_lapse_mult_crbg() {
		return pba_base_lapse_mult_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_infl_intercept_crbg;
  inline double	Get_pba_infl_intercept_crbg() {
		return pba_infl_intercept_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_infl_slope_crbg;
  inline double	Get_pba_infl_slope_crbg() {
		return pba_infl_slope_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_maint_exp_mult_crbg;
  inline double	Get_pba_maint_exp_mult_crbg() {
		return pba_maint_exp_mult_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_mort_mult_no_gmwb_crbg;
  inline double	Get_pba_mort_mult_no_gmwb_crbg() {
		return pba_mort_mult_no_gmwb_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_pfwd_pct_mult_crbg;
  inline double	Get_pba_pfwd_pct_mult_crbg() {
		return pba_pfwd_pct_mult_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_trail_comm_mult_crbg;
  inline double	Get_pba_trail_comm_mult_crbg() {
		return pba_trail_comm_mult_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > pfwd_amt_avail_defn;
  inline xstring	Get_pfwd_amt_avail_defn() {
		return pfwd_amt_avail_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > pfwd_freq;
  inline xstring	Get_pfwd_freq() {
		return pfwd_freq; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pfwd_pct;
  inline double	Get_pfwd_pct() {
		return pfwd_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pfwd_rate_calc_fct1_crbg;
  inline double	Get_pfwd_rate_calc_fct1_crbg() {
		return pfwd_rate_calc_fct1_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pfwd_rate_calc_fct2_crbg;
  inline double	Get_pfwd_rate_calc_fct2_crbg() {
		return pfwd_rate_calc_fct2_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pfwd_use;
  inline double	Get_pfwd_use() {
		return pfwd_use; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pfwd_use_addl_shock_yr_crbg;
  inline double	Get_pfwd_use_addl_shock_yr_crbg() {
		return pfwd_use_addl_shock_yr_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pfwd_use_nq_crbg;
  inline double	Get_pfwd_use_nq_crbg() {
		return pfwd_use_nq_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pfwd_use_q_crbg;
  inline double	Get_pfwd_use_q_crbg() {
		return pfwd_use_q_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pfwd_use_qual_pct_crbg;
  inline double	Get_pfwd_use_qual_pct_crbg() {
		return pfwd_use_qual_pct_crbg; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > pipp_stepup_age_crbg;
  inline int	Get_pipp_stepup_age_crbg() {
		return pipp_stepup_age_crbg; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > plan_code;
  inline xstring	Get_plan_code() {
		return plan_code; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > pol_mth_lookup;
  inline int	Get_pol_mth_lookup() {
		return pol_mth_lookup; }
  inline void Set_pol_mth_lookup(const int &v) {
		pol_mth_lookup.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > pol_yr_lookup;
  inline int	Get_pol_yr_lookup() {
		return pol_yr_lookup; }
  inline void Set_pol_yr_lookup(const int &v) {
		pol_yr_lookup.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > pos_sprd_ind_crbg;
  inline xstring	Get_pos_sprd_ind_crbg() {
		return pos_sprd_ind_crbg; }
  inline void Set_pos_sprd_ind_crbg(const xstring &v) {
		pos_sprd_ind_crbg.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > prem_band;
  inline xstring	Get_prem_band() {
		return prem_band; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > prem_bonus_recap_pct_crbg;
  inline double	Get_prem_bonus_recap_pct_crbg() {
		return prem_bonus_recap_pct_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > prem_credit;
  inline double	Get_prem_credit() {
		return prem_credit; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > prem_tax_pct;
  inline double	Get_prem_tax_pct() {
		return prem_tax_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pri_sprd_tgt_crbg;
  inline double	Get_pri_sprd_tgt_crbg() {
		return pri_sprd_tgt_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > pricing_defn;
  inline xstring	Get_pricing_defn() {
		return pricing_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > prof_distribn_mode;
  inline xstring	Get_prof_distribn_mode() {
		return prof_distribn_mode; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_rate_curr_comp_rate_id;
  inline xstring	Get_purch_rate_curr_comp_rate_id() {
		return purch_rate_curr_comp_rate_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_rate_curr_defn;
  inline xstring	Get_purch_rate_curr_defn() {
		return purch_rate_curr_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_rate_curr_fixed;
  inline double	Get_purch_rate_curr_fixed() {
		return purch_rate_curr_fixed; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_rate_curr_load;
  inline double	Get_purch_rate_curr_load() {
		return purch_rate_curr_load; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_rate_curr_pol_fee;
  inline double	Get_purch_rate_curr_pol_fee() {
		return purch_rate_curr_pol_fee; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_rate_curr_sprd;
  inline double	Get_purch_rate_curr_sprd() {
		return purch_rate_curr_sprd; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_rate_guar_fixed;
  inline double	Get_purch_rate_guar_fixed() {
		return purch_rate_guar_fixed; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > quota_share_reinsured_crbg;
  inline double	Get_quota_share_reinsured_crbg() {
		return quota_share_reinsured_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c1_liab_only_stat_res_pct;
  inline double	Get_rbc_c1_liab_only_stat_res_pct() {
		return rbc_c1_liab_only_stat_res_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c2_mort_pct;
  inline double	Get_rbc_c2_mort_pct() {
		return rbc_c2_mort_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c3_ann_high_risk_pct;
  inline double	Get_rbc_c3_ann_high_risk_pct() {
		return rbc_c3_ann_high_risk_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c3_ann_low_risk_pct;
  inline double	Get_rbc_c3_ann_low_risk_pct() {
		return rbc_c3_ann_low_risk_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c3_ann_medium_risk_pct;
  inline double	Get_rbc_c3_ann_medium_risk_pct() {
		return rbc_c3_ann_medium_risk_pct; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > rbc_c3_ann_risk_defn;
  inline int	Get_rbc_c3_ann_risk_defn() {
		return rbc_c3_ann_risk_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c4_prem_pct;
  inline double	Get_rbc_c4_prem_pct() {
		return rbc_c4_prem_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > reins_coverage_defn;
  inline xstring	Get_reins_coverage_defn() {
		return reins_coverage_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > reins_defn;
  inline xstring	Get_reins_defn() {
		return reins_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > reins_exp_per_pol;
  inline double	Get_reins_exp_per_pol() {
		return reins_exp_per_pol; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > reins_gmwb_chg;
  inline double	Get_reins_gmwb_chg() {
		return reins_gmwb_chg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > reins_pct;
  inline double	Get_reins_pct() {
		return reins_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > renewal_beta_down_crbg;
  inline double	Get_renewal_beta_down_crbg() {
		return renewal_beta_down_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > renewal_beta_up_crbg;
  inline double	Get_renewal_beta_up_crbg() {
		return renewal_beta_up_crbg; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > renewal_sc_yr_offest_crbg;
  inline int	Get_renewal_sc_yr_offest_crbg() {
		return renewal_sc_yr_offest_crbg; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > rmd_age_crbg;
  inline int	Get_rmd_age_crbg() {
		return rmd_age_crbg; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > seg_id;
  inline xstring	Get_seg_id() {
		return seg_id; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > sfas97rd_cohort_id_ceded;
  inline xstring	Get_sfas97rd_cohort_id_ceded() {
		return sfas97rd_cohort_id_ceded; }
  inline void Set_sfas97rd_cohort_id_ceded(const xstring &v) {
		sfas97rd_cohort_id_ceded.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > sfas97rd_cohort_id_gross;
  inline xstring	Get_sfas97rd_cohort_id_gross() {
		return sfas97rd_cohort_id_gross; }
  inline void Set_sfas97rd_cohort_id_gross(const xstring &v) {
		sfas97rd_cohort_id_gross.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > sfc_atan_alpha_crbg;
  inline double	Get_sfc_atan_alpha_crbg() {
		return sfc_atan_alpha_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > sfc_atan_beta_crbg;
  inline double	Get_sfc_atan_beta_crbg() {
		return sfc_atan_beta_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > sfc_atan_gamma_crbg;
  inline double	Get_sfc_atan_gamma_crbg() {
		return sfc_atan_gamma_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > sfc_atan_mult_floor_crbg;
  inline double	Get_sfc_atan_mult_floor_crbg() {
		return sfc_atan_mult_floor_crbg; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > shock_skew_mth_crbg;
  inline int	Get_shock_skew_mth_crbg() {
		return shock_skew_mth_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > shock_skew_pct_crbg;
  inline double	Get_shock_skew_pct_crbg() {
		return shock_skew_pct_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > single_prem;
  inline double	Get_single_prem() {
		return single_prem; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > spousal_cont_elect_rate_crbg;
  inline double	Get_spousal_cont_elect_rate_crbg() {
		return spousal_cont_elect_rate_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > stat_carvm_calc_annuitzn_defn;
  inline xstring	Get_stat_carvm_calc_annuitzn_defn() {
		return stat_carvm_calc_annuitzn_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > stat_res_defn;
  inline xstring	Get_stat_res_defn() {
		return stat_res_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > stat_res_mva_defn;
  inline xstring	Get_stat_res_mva_defn() {
		return stat_res_mva_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > stat_res_pct;
  inline double	Get_stat_res_pct() {
		return stat_res_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > stat_valn_code;
  inline xstring	Get_stat_valn_code() {
		return stat_valn_code; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > surr_chg_defn;
  inline xstring	Get_surr_chg_defn() {
		return surr_chg_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > surr_chg_pct;
  inline double	Get_surr_chg_pct() {
		return surr_chg_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > surr_chg_pct_renewal_crbg;
  inline double	Get_surr_chg_pct_renewal_crbg() {
		return surr_chg_pct_renewal_crbg; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > surr_chg_period_crbg;
  inline int	Get_surr_chg_period_crbg() {
		return surr_chg_period_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > surr_chg_timing_defn;
  inline xstring	Get_surr_chg_timing_defn() {
		return surr_chg_timing_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tax_capzd_prem_pct;
  inline double	Get_tax_capzd_prem_pct() {
		return tax_capzd_prem_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tax_capzd_prem_pct_qualify;
  inline double	Get_tax_capzd_prem_pct_qualify() {
		return tax_capzd_prem_pct_qualify; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tax_carvm_calc_annuitzn_defn;
  inline xstring	Get_tax_carvm_calc_annuitzn_defn() {
		return tax_carvm_calc_annuitzn_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tax_carvm_defn;
  inline xstring	Get_tax_carvm_defn() {
		return tax_carvm_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tax_loss_treatment;
  inline xstring	Get_tax_loss_treatment() {
		return tax_loss_treatment; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tax_rate;
  inline double	Get_tax_rate() {
		return tax_rate; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tax_res_defn;
  inline xstring	Get_tax_res_defn() {
		return tax_res_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tax_res_mva_defn;
  inline xstring	Get_tax_res_mva_defn() {
		return tax_res_mva_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tax_res_pct;
  inline double	Get_tax_res_pct() {
		return tax_res_pct; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > tax_res_pct_stat;
  inline double	Get_tax_res_pct_stat() {
		return tax_res_pct_stat; }
  inline void Set_tax_res_pct_stat(const double &v) {
		tax_res_pct_stat.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > tax_valn_code;
  inline xstring	Get_tax_valn_code() {
		return tax_valn_code; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tgt_budget_alpha_crbg;
  inline double	Get_tgt_budget_alpha_crbg() {
		return tgt_budget_alpha_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tgt_budget_reduction_crbg;
  inline double	Get_tgt_budget_reduction_crbg() {
		return tgt_budget_reduction_crbg; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tgt_cap_defn;
  inline xstring	Get_tgt_cap_defn() {
		return tgt_cap_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tgt_cap_rbc_mult;
  inline double	Get_tgt_cap_rbc_mult() {
		return tgt_cap_rbc_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > use_mp;
  inline xstring	Get_use_mp() {
		return use_mp; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > valn_periods_selected;
  inline xstring	Get_valn_periods_selected() {
		return valn_periods_selected; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > valn_yrs;
  inline int	Get_valn_yrs() {
		return valn_yrs; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > audit_detail_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > commencement_period;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > data_file_name;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > elapsed_mths;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > final_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gmwb_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gmwb_req_yrs_wait;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > infl_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > infl_start_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > infl_start_yr;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > issue_age;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > issue_date;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > issue_day;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > issue_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > issue_yr;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > itm_period_disc_rate;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > lapse_shock_year_crbg;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > lipm_ind_crbg;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > maturity_age;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > maturity_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > max_mva_sc_period_crbg;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > mort_impr_time_elapsed;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > mva_comp_rate_issue;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > proj_date_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_date;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_yr;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > reins_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > start_period;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > state_of_world_financial_file_path;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > tax_capzd_prem_amortzn_yrs;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > term_to_omega_age;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > term_to_omega_age_f_crbg;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > term_to_omega_age_m_crbg;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(FIA_LIAB* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Calc Gmwb Wdl Util Level Crbg
#line 1 "calc_gmwb_wdl_util_level_crbg.fia_liab.for"
double calc_gmwb_wdl_util_level_crbg(
	int t, double unif_rv_cv, double util_level_cv, double fund_val_e_bef_cv = 0.0, double gmwb_inf_e_bef_cv = 0.0);

// Dth Rate Calc Crbg
#line 1 "dth_rate_calc_crbg.fia_liab.for"
double dth_rate_calc_crbg(int t, int pol_yr, StrEnum::EnumValue mort_gender_cv);

// Dth Rate Confinement Calc Crbg
#line 1 "dth_rate_confinement_calc_crbg.fia_liab.for"
double dth_rate_confinement_calc_crbg(int t, int pol_yr, StrEnum::EnumValue mort_gender_cv,
		int confinement_status, int confinement_age = 0, int confinement_mths = 0);

// Gen Uniform Rands Crbg
#line 1 "gen_uniform_rands_crbg.fia_liab.for"
void gen_uniform_rands_crbg(vector< vector <double>>& uniform_rands_arr);

// Get Competitor Rate
#line 1 "get_comp_rate.fia_liab.for"
double get_comp_rate(xstring cr_id, int t);

// Get Gmwb Wdl Init Util Level Crbg
#line 1 "get_gmwb_wdl_init_util_level_crbg.fia_liab.for"
double get_gmwb_wdl_init_util_level_crbg(double random_uniform_draw);

// Get Gmwb Wdl Util Level Crbg
#line 1 "get_gmwb_wdl_util_level_crbg.fia_liab.for"
double get_gmwb_wdl_util_level_crbg(double current_level, int transition_tbl_id,	double random_uniform_draw);

// get_gmwb_wdl_util_prob_crbg
#line 1 "get_gmwb_wdl_util_prob_crbg.fia_liab.for"
double get_gmwb_wdl_util_prob_crbg(
	double current_level, double tgt_level, int transition_tbl_id);

// Get Rate
#line 1 "get_rate.fia_liab.for"
double get_rate(StrEnum::EnumValue rate_defn, int t, const xstring &id_input, int rate_type, double rate_term_input, double fwd_or_moneyness, int return_rate_basis, int shift_type);

// Internal Rate of Return Calculation
#line 1 "irr_calc.fia_liab.for"
double irr_calc(int t, const xstring &roi_type);

// Issue Age Calc Crbg
#line 1 "issue_age_calc_crbg.fia_liab.for"
int issue_age_calc_crbg(StrEnum::EnumValue gender_cv);

// Dynamic Lapse Rate
#line 1 "lapse_rate_dyn.fia_liab.for"
double lapse_rate_dyn(int t);

// Mort Improve Mult Crbg
#line 1 "mort_improve_mult_crbg.fia_liab.for"
double mort_improve_mult_crbg(int att_age, StrEnum::EnumValue gender_local, int t);

// PV GMWB Benefit for ITM
#line 1 "pv_gmwb_benefit_itm_calc.fia_liab.for"
double pv_gmwb_benefit_itm_calc(int t, int pol_yr, int pol_mth, double disc_rate, double gmwb_if_bef_eom, double gmwb_max_wthdrl_amt_bef, double pfwd_cumul);

// Read State Of World Financial
#line 1 "read_state_of_world_financial.fia_liab.for"
void read_state_of_world_financial(void);

// Setup FIA Account Variables
#line 1 "set_fia_account_vars.fia_liab.for"
void set_fia_account_vars(void);

// Time Between Dates Calc Crbg
#line 1 "time_between_dates_calc_crbg.fia_liab.for"
double time_between_dates_calc_crbg(xstring start_date, xstring end_date);

// Validate Data
#line 1 "validate_data.fia_liab.for"
void validate_data(void);

// Write intermediate reserve calculations
#line 1 "write_reserves.fia_liab.for"
void write_reserves(int time, xstring res_basis, int ann_stream_test, int gmwb_exercise_point);

// Write State Of World Financial
#line 1 "write_state_of_world_financial.fia_liab.for"
void write_state_of_world_financial(void);

// Write State Of World Model Points
#line 1 "write_state_of_world_mp.fia_liab.for"
void write_state_of_world_mp(void);


//factory
static FIA_LIAB* makeThis(int isSubmodel, ModelClass *owner, FIA_LIAB* peer, 
					int mainRebase, const xstring &name, FIA_LIAB_persistent_object* arrayTemplate);

//constructor
FIA_LIAB(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
FIA_LIAB(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~FIA_LIAB();


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
class FIA_LIAB_persistent_object : public FIA_LIAB {


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

	void findTargetColumns() {FIA_LIAB::findTargetColumns();}
	void createAllShare() {
		FIA_LIAB::createAllShare();
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
	_2D_FIACARVM_LIAB &sm_carvm_stat; //
	_2D_FIACARVM_LIAB &sm_carvm_tax; //
	_1D_FIAAFUND_LIAB &sm_fia_account; //
	_1D_ANN_PBA_PBA &sm_fia_ann_pba; //
	_1D_MRB_GAAP &sm_fia_mrb; //
	RATES_ECONOMY *&sm_fia_rates; //
	_1D_SFAS97RD_GAAP &sm_fia_sfas97rd; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~FIA_LIAB_persistent_object();

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
static FIA_LIAB_persistent_object* makeThis(int isSubmodel, ModelClass *owner, FIA_LIAB* peer, 
					int mainRebase, const xstring &name, FIA_LIAB_persistent_object* arrayTemplate, bool fixedArray);

//constructor
FIA_LIAB_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
