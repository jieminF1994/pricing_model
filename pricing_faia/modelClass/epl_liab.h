#ifndef __EPL_LIAB_H_
#define __EPL_LIAB_H_
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



namespace EPL_LIAB_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class EPL_LIAB_persistent_object;
class EPL_LIAB : public ModelClass {

friend void clearSharedTempTables();
	

protected:
	static TempTableHolderCollection TTHC;
	void removeSMPointers(ModelClass* modelToRemove);
static const CashFlowCommonData* mCFStaticData[];
  static const CashFlowCommonData mCFStaticData_0[]; 
  static const CashFlowCommonData mCFStaticData_256[]; 
  static const CashFlowCommonData mCFStaticData_512[]; 
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

	size_t sizeofThis() const { return sizeof(EPL_LIAB); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;

Schedule * EPLData;
int epl_last_cash_flow_period;
map <xstring, long, less <xstring> > sched_byte_pos;

	void init_(){
		

epl_last_cash_flow_period = -1;

		bIsInit = true;
	}
	void deInit_(){

	}

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
#ifdef __CREATE_EPL_LIAB_CLASS_
	EPL_LIAB	*company_liab_epl;
	EPL_LIAB	*&epl;
#endif
#ifdef __CREATE_HDG_GRP_COMP_CLASS_
	HDG_GRP_COMP	*company_seg_hedge_grp;
	HDG_GRP_COMP	*&hedge_grp;
#endif
#ifdef __CREATE_INTEX_ASSET_CLASS_
	INTEX_ASSET	*company_asset_intex;
	INTEX_ASSET	*&intex;
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
 	ColumnAccessor < mCFStaticData_0 > ag48_npr_net;
 	ColumnAccessor < mCFStaticData_0 > ag48_unearn_prem_res_npr_net;
 	ColumnAccessor < mCFStaticData_0 > ann_benefits_bom;
 	ColumnAccessor < mCFStaticData_0 > ann_benefits_eom;
 	ColumnAccessor < mCFStaticData_0 > ann_pba_reins_res;
 	ColumnAccessor < mCFStaticData_0 > ann_pba_working_res;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_consideration;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_val_released;
 	ColumnAccessor < mCFStaticData_0 > cash_val;
 	ColumnAccessor < mCFStaticData_0 > claim_paid;
 	ColumnAccessor < mCFStaticData_0 > comm_bom;
 	ColumnAccessor < mCFStaticData_0 > comm_chargeback;
 	ColumnAccessor < mCFStaticData_0 > comm_eom;
 	ColumnAccessor < mCFStaticData_0 > conversion_cost;
 	ColumnAccessor < mCFStaticData_0 > deferred_gross_prem;
 	ColumnAccessor < mCFStaticData_0 > deferred_net_prem;
 	ColumnAccessor < mCFStaticData_0 > deferred_net_prem_net;
 	ColumnAccessor < mCFStaticData_0 > deferred_net_prem_npr;
 	ColumnAccessor < mCFStaticData_0 > deferred_net_prem_npr_net;
 	ColumnAccessor < mCFStaticData_0 > div_applied;
 	ColumnAccessor < mCFStaticData_0 > div_liab;
 	ColumnAccessor < mCFStaticData_0 > div_paid;
 	ColumnAccessor < mCFStaticData_0 > dth_ben_inf;
 	ColumnAccessor < mCFStaticData_0 > dth_benefits;
 	ColumnAccessor < mCFStaticData_0 > endow_benefits;
 	ColumnAccessor < mCFStaticData_0 > fund_val_fixed;
 	ColumnAccessor < mCFStaticData_0 > fund_val_sa;
 	ColumnAccessor < mCFStaticData_0 > gross_prem_annualzd;
 	ColumnAccessor < mCFStaticData_0 > hedge_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val_growth;
 	ColumnAccessor < mCFStaticData_0 > inv_fee_ref;
 	ColumnAccessor < mCFStaticData_0 > life_pba_ag48_npr_net;
 	ColumnAccessor < mCFStaticData_0 > life_pba_ag48_unearn_prem_res_npr_net;
 	ColumnAccessor < mCFStaticData_0 > life_pba_asset_sa;
 	ColumnAccessor < mCFStaticData_0 > life_pba_direct_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_0 > life_pba_direct_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_0 > life_pba_gpr_ceded;
 	ColumnAccessor < mCFStaticData_0 > life_pba_gpr_gross;
 	ColumnAccessor < mCFStaticData_0 > life_pba_gpr_units_inf;
 	ColumnAccessor < mCFStaticData_0 > life_pba_pol_loan;
 	ColumnAccessor < mCFStaticData_0 > life_pba_pol_loan_int;
 	ColumnAccessor < mCFStaticData_0 > life_pba_reins_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_0 > life_pba_reins_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_0 > life_pba_reins_res;
 	ColumnAccessor < mCFStaticData_0 > life_pba_reins_res_sa;
 	ColumnAccessor < mCFStaticData_0 > life_pba_stat_res_mp;
 	ColumnAccessor < mCFStaticData_0 > life_pba_stat_res_net_mp;
 	ColumnAccessor < mCFStaticData_0 > life_pba_stat_unearn_prem_res;
 	ColumnAccessor < mCFStaticData_0 > life_pba_stat_unearn_prem_res_net;
 	ColumnAccessor < mCFStaticData_0 > life_pba_stat_unearn_prem_res_npr_net;
 	ColumnAccessor < mCFStaticData_0 > life_pba_working_res;
 	ColumnAccessor < mCFStaticData_0 > maint_exp_bom;
 	ColumnAccessor < mCFStaticData_0 > maint_exp_eom;
 	ColumnAccessor < mCFStaticData_0 > maturity_benefits;
 	ColumnAccessor < mCFStaticData_0 > pba_rollforward_base;
 	ColumnAccessor < mCFStaticData_0 > pol_loan;
 	ColumnAccessor < mCFStaticData_0 > pol_loan_exp;
 	ColumnAccessor < mCFStaticData_0 > pol_loan_int;
 	ColumnAccessor < mCFStaticData_0 > pol_loan_proceeds;
 	ColumnAccessor < mCFStaticData_0 > policies_b;
 	ColumnAccessor < mCFStaticData_0 > policies_inf;
 	ColumnAccessor < mCFStaticData_0 > policies_issued;
 	ColumnAccessor < mCFStaticData_0 > prem_issued;
 	ColumnAccessor < mCFStaticData_0 > prem_paid;
 	ColumnAccessor < mCFStaticData_0 > prem_paid_net;
 	ColumnAccessor < mCFStaticData_0 > prem_tax;
 	ColumnAccessor < mCFStaticData_0 > prem_waiver_benefits;
 	ColumnAccessor < mCFStaticData_0 > rbc_c1_unearn_prem_res_def;
 	ColumnAccessor < mCFStaticData_0 > rbc_c2_claim;
 	ColumnAccessor < mCFStaticData_0 > rbc_c2_claim_prev_yr;
 	ColumnAccessor < mCFStaticData_0 > rbc_c2_prem;
 	ColumnAccessor < mCFStaticData_0 > rbc_c2_prem_prev_yr;
 	ColumnAccessor < mCFStaticData_0 > rbc_c3_base_ann_high_risk;
 	ColumnAccessor < mCFStaticData_0 > rbc_c3_base_ann_low_risk;
 	ColumnAccessor < mCFStaticData_0 > rbc_c3_base_ann_medium_risk;
 	ColumnAccessor < mCFStaticData_0 > rbc_c3_base_life;
 	ColumnAccessor < mCFStaticData_0 > rbc_c3_mp;
 	ColumnAccessor < mCFStaticData_0 > rbc_c4;
 	ColumnAccessor < mCFStaticData_0 > reins_ann_benefits_bom;
 	ColumnAccessor < mCFStaticData_0 > reins_ann_benefits_eom;
 	ColumnAccessor < mCFStaticData_0 > reins_cash_val;
 	ColumnAccessor < mCFStaticData_0 > reins_claim_paid;
 	ColumnAccessor < mCFStaticData_0 > reins_comm_chargeback_reimb;
 	ColumnAccessor < mCFStaticData_0 > reins_comm_reimb_bom;
 	ColumnAccessor < mCFStaticData_0 > reins_comm_reimb_eom;
 	ColumnAccessor < mCFStaticData_0 > reins_deferred_gross_prem;
 	ColumnAccessor < mCFStaticData_0 > reins_deferred_net_prem;
 	ColumnAccessor < mCFStaticData_0 > reins_div_applied;
 	ColumnAccessor < mCFStaticData_0 > reins_div_liab;
 	ColumnAccessor < mCFStaticData_0 > reins_div_paid;
 	ColumnAccessor < mCFStaticData_0 > reins_dth_ben_inf;
 	ColumnAccessor < mCFStaticData_0 > reins_dth_benefits;
 	ColumnAccessor < mCFStaticData_0 > reins_ea;
 	ColumnAccessor < mCFStaticData_0 > reins_ea_chargeback;
 	ColumnAccessor < mCFStaticData_0 > reins_endow_benefits;
 	ColumnAccessor < mCFStaticData_0 > reins_exp;
 	ColumnAccessor < mCFStaticData_0 > reins_exp_reimb_bom;
 	ColumnAccessor < mCFStaticData_0 > reins_exp_reimb_eom;
 	ColumnAccessor < mCFStaticData_0 > reins_inv_fee_ref;
 	ColumnAccessor < mCFStaticData_0 > reins_maturity_benefits;
 	ColumnAccessor < mCFStaticData_0 > reins_modco_res_adj;
 	ColumnAccessor < mCFStaticData_0 > reins_prem;
 	ColumnAccessor < mCFStaticData_0 > reins_prem_tax;
 	ColumnAccessor < mCFStaticData_0 > reins_prem_waiver_benefits;
 	ColumnAccessor < mCFStaticData_0 > reins_ref;
 	ColumnAccessor < mCFStaticData_0 > reins_stat_claim_res;
 	ColumnAccessor < mCFStaticData_0 > reins_stat_loading;
 	ColumnAccessor < mCFStaticData_0 > reins_stat_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_0 > reins_stat_res_mp;
 	ColumnAccessor < mCFStaticData_0 > reins_stat_res_npr;
 	ColumnAccessor < mCFStaticData_0 > reins_stat_unearn_prem_res;
 	ColumnAccessor < mCFStaticData_0 > reins_surr_benefits;
 	ColumnAccessor < mCFStaticData_0 > reins_tax_claim_res;
 	ColumnAccessor < mCFStaticData_0 > reins_tax_deferred_net_prem;
 	ColumnAccessor < mCFStaticData_0 > reins_tax_loading;
 	ColumnAccessor < mCFStaticData_0 > reins_tax_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_0 > reins_tax_res_mp;
 	ColumnAccessor < mCFStaticData_0 > reins_tax_unearn_prem_res;
 	ColumnAccessor < mCFStaticData_0 > reins_terminal_div;
 	ColumnAccessor < mCFStaticData_0 > reins_withdrl_benefits;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_benefits;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_capzd_comm_chargeback;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_comm_chargeback;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_comm_excess_eom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_comm_trail_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_comm_trail_bom_base_plan;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_comm_trail_bom_rider;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_comm_trail_eom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_conversion_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_div_applied;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_div_liab;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_div_opt_res;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_div_paid;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_dth_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_egm_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_egm_comm;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_egm_div_applied;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_egm_div_paid;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_egm_dth_benefits;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_egm_endow_benefits;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_egm_maint_exp;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_egm_maturity_benefits;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_egm_prem_paid;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_egm_prem_tax;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_egm_surr_benefits;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_endow_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_gpr;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_gpr_units_inf;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_gross_prem;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_loc_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_maturity_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_modco_liab;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_modco_res_adj;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_nlp_res_net_prem2;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_nlp_res_prelim;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_prem_tax;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_refund;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_reins_ea_excess;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_reins_ea_trail;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_surr_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_ceded_terminal_div;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_benefits;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_capzd_comm_chargeback;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_capzd_reins_yrt_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_comm_chargeback;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_comm_excess_eom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_comm_trail_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_comm_trail_bom_base_plan;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_comm_trail_bom_rider;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_comm_trail_eom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_conversion_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_div_applied;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_div_liab;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_div_opt_res;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_div_paid;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_dth_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_egm_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_egm_comm;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_egm_div_applied;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_egm_div_paid;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_egm_dth_benefits;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_egm_endow_benefits;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_egm_maint_exp;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_egm_maturity_benefits;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_egm_prem_paid;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_egm_prem_tax;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_egm_reins_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_egm_surr_benefits;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_endow_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_gpr;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_gpr_units_inf;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_gross_prem;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_loc_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_maturity_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_nlp_res_net_prem;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_nlp_res_prelim;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_pol_loan;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_pol_loan_inc;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_prem_tax;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_reins_yrt_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_stat_res_rider;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_surr_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas120_gross_terminal_div;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_ben_res_accrual_valn_basis;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_ben_res_int_valn_basis;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_ben_res_prelim;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_benefits_valn_basis;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_capzd_acq_exp_valn_basis;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_capzd_comm_chargeback;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_capzd_comm_valn_basis;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_claim_res;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_comm_chargeback;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_comm_excess_eom;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_comm_trail_bom;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_comm_trail_bom_base_plan;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_comm_trail_bom_rider;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_comm_trail_eom;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_conversion_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_dac_amortzn_valn_basis;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_dac_int_valn_basis;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_dac_prelim;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_div_applied;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_div_paid;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_div_valn_basis;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_dth_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_endow_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_exp_valn_basis;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_gpr;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_gpr_units_inf;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_gross_prem;
 	ColumnAccessor < mCFStaticData_0 > sfas60_ceded_hlth_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_loc_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_maint_exp_res_accrual_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_maint_exp_res_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_maint_exp_res_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_maturity_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_modco_liab;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_modco_res_adj;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_prem_tax;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_refund;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_surr_ben_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_surr_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas60_ceded_terminal_div;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_ben_res_accrual_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_ben_res_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_ben_res_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_benefits_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_capzd_acq_exp_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_capzd_comm_chargeback;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_capzd_comm_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_capzd_reins_yrt_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_claim_res;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_comm_chargeback;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_comm_excess_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_comm_trail_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_comm_trail_bom_base_plan;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_comm_trail_bom_rider;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_comm_trail_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_conversion_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_dac_amortzn_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_dac_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_dac_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_dac_reins_yrt_asset_amortzn_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_dac_reins_yrt_asset_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_dac_reins_yrt_asset_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_div_applied;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_div_paid;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_div_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_dth_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_endow_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_exp_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_gpr;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_gpr_units_inf;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_gross_prem;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_hlth_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_loc_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_maint_exp_res_accrual_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_maint_exp_res_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_maint_exp_res_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_maturity_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_pol_loan;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_pol_loan_inc;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_prem_tax;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_reins_yrt_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_reins_yrt_cost_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_stat_res_rider;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_surr_ben_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_surr_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas60_gross_terminal_div;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_ann_benefits_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_ann_benefits_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_ben_maint_exp_res_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_ben_maint_exp_res_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_ben_res_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_ben_res_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_deferred_maint_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_dth_benefits;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_maint_exp_res_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_maint_exp_res_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_net_res_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_net_res_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_noncapzd_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_policies_b;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_prem_paid;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_prem_tax;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_res_ann_benefits;
 	ColumnAccessor < mCFStaticData_256 > sfas91_ceded_res_dth_benefits;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_ann_benefits_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_ann_benefits_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_ben_maint_exp_res_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_ben_maint_exp_res_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_ben_res_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_ben_res_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_deferred_maint_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_dth_benefits;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_maint_exp_res_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_maint_exp_res_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_net_res_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_net_res_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_noncapzd_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_policies_b;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_prem_paid;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_prem_tax;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_res_ann_benefits;
 	ColumnAccessor < mCFStaticData_256 > sfas91_gross_res_dth_benefits;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_ann_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_ben_res_accrual_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_ben_res_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_ben_res_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_benefits_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_capzd_acq_exp_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_capzd_comm_chargeback;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_capzd_comm_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_claim_res;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_comm_chargeback;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_comm_excess_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_comm_trail_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_comm_trail_bom_base_plan;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_comm_trail_bom_rider;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_comm_trail_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_conversion_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_dac_amortzn_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_dac_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_dac_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_deferred_prof_amortzn_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_deferred_prof_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_deferred_prof_liab_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_deferred_prof_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_div_applied;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_div_paid;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_div_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_dth_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_endow_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_exp_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_gpr;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_gpr_units_inf;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_gross_prem;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_hlth_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_loc_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_maint_exp_res_accrual_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_maint_exp_res_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_maint_exp_res_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_maturity_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_modco_liab;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_modco_res_adj;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_prem_tax;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_refund;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_surr_ben_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_surr_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_ceded_terminal_div;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_ann_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_ben_res_accrual_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_ben_res_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_ben_res_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_benefits_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_capzd_acq_exp_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_capzd_comm_chargeback;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_capzd_comm_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_capzd_reins_yrt_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_claim_res;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_comm_chargeback;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_comm_excess_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_comm_trail_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_comm_trail_bom_base_plan;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_comm_trail_bom_rider;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_comm_trail_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_conversion_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_dac_amortzn_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_dac_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_dac_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_dac_reins_yrt_asset_amortzn_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_dac_reins_yrt_asset_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_dac_reins_yrt_asset_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_deferred_prof_amortzn_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_deferred_prof_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_deferred_prof_liab_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_deferred_prof_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_div_applied;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_div_paid;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_div_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_dth_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_endow_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_exp_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_gpr;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_gpr_units_inf;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_gross_prem;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_hlth_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_loc_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_maint_exp_res_accrual_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_maint_exp_res_int_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_maint_exp_res_prelim;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_maturity_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_pol_loan;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_pol_loan_inc;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_prem_tax;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_reins_yrt_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_reins_yrt_cost_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_stat_res_rider;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_surr_ben_valn_basis;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_surr_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97lp_gross_terminal_div;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_cap_gain_fund;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_capzd_comm_chargeback;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_capzd_prem_bonus;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_charges;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_comm_chargeback;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_comm_trail_bom;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_credited_int;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_deferred_loads;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_dth_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_egp_gain_inv;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_egp_gain_mort;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_egp_gain_surr;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_embed_deriv_cash_flow;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_fund_val_aft_int;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_fund_val_bef_int;
 	ColumnAccessor < mCFStaticData_256 > sfas97rd_ceded_fund_val_fixed;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_fund_val_sa;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_gmab_ben;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_gmdb_ben;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_gmib_ben;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_gmwb_ben;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_hedge_cash_flow;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_host_contract_cred_int;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_host_contract_val;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_host_contract_val_bef;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_inv_inc_fund;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_loads;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_loc_cost;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_modco_liab;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_modco_res_adj;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_persist_bon_ref;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_policies_b;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_prem_bonus;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_prem_tax;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_refund;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_rider_charges;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_sfas133_gmab_liab;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_sfas133_gmib_liab;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_sfas133_gmwb_liab;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_sop031_assess;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_sop031_coi_assess;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_sop031_coi_ben;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_sop031_pbr;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_sop031_pbr_fund_val;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_ceded_ulsg_ben;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_acq_exp;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_cap_gain_fund;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_capzd_comm_chargeback;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_capzd_prem_bonus;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_capzd_reins_yrt_cost;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_charges;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_comm_chargeback;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_comm_trail_bom;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_credited_int;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_deferred_loads;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_dth_claim_cost;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_egp_gain_inv;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_egp_gain_mort;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_egp_gain_surr;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_embed_deriv_cash_flow;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_fund_val_aft_int;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_fund_val_bef_int;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_fund_val_fixed;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_fund_val_sa;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_gmab_ben;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_gmdb_ben;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_gmib_ben;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_gmwb_ben;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_hedge_cash_flow;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_host_contract_cred_int;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_host_contract_val;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_host_contract_val_bef;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_inv_inc_fund;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_loads;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_loc_cost;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_persist_bon_ref;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_pol_loan;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_pol_loan_inc;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_policies_b;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_prem_bonus;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_prem_tax;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_reins_yrt_cost;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_rider_charges;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_sfas133_gmab_liab;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_sfas133_gmib_liab;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_sfas133_gmwb_liab;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_sop031_assess;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_sop031_coi_assess;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_sop031_coi_ben;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_sop031_pbr;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_sop031_pbr_fund_val;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_stat_res_rider;
 	ColumnAccessor < mCFStaticData_512 > sfas97rd_gross_ulsg_ben;
 	ColumnAccessor < mCFStaticData_512 > startup;
 	ColumnAccessor < mCFStaticData_512 > stat_claim_exp_res;
 	ColumnAccessor < mCFStaticData_512 > stat_claim_res;
 	ColumnAccessor < mCFStaticData_512 > stat_loading;
 	ColumnAccessor < mCFStaticData_512 > stat_prem_waiver_exp_res;
 	ColumnAccessor < mCFStaticData_512 > stat_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_512 > stat_res_mp;
 	ColumnAccessor < mCFStaticData_512 > stat_res_mp_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_mp;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_mp_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_npr;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_npr_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_sa;
 	ColumnAccessor < mCFStaticData_512 > stat_res_npr;
 	ColumnAccessor < mCFStaticData_512 > stat_res_npr_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_sa;
 	ColumnAccessor < mCFStaticData_512 > stat_res_sa_exp_allow;
 	ColumnAccessor < mCFStaticData_512 > stat_unearn_prem_res;
 	ColumnAccessor < mCFStaticData_512 > stat_unearn_prem_res_net;
 	ColumnAccessor < mCFStaticData_512 > stat_unearn_prem_res_npr;
 	ColumnAccessor < mCFStaticData_512 > stat_unearn_prem_res_npr_net;
 	ColumnAccessor < mCFStaticData_512 > surr_benefits;
 	ColumnAccessor < mCFStaticData_512 > tax_capzd_prem;
 	ColumnAccessor < mCFStaticData_512 > tax_claim_exp_res;
 	ColumnAccessor < mCFStaticData_512 > tax_claim_res;
 	ColumnAccessor < mCFStaticData_512 > tax_deferred_net_prem;
 	ColumnAccessor < mCFStaticData_512 > tax_loading;
 	ColumnAccessor < mCFStaticData_512 > tax_prem_waiver_exp_res;
 	ColumnAccessor < mCFStaticData_512 > tax_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_512 > tax_res_mp;
 	ColumnAccessor < mCFStaticData_512 > tax_transfer_to_sa_net;
 	ColumnAccessor < mCFStaticData_512 > tax_unearn_prem_res;
 	ColumnAccessor < mCFStaticData_512 > terminal_div;
 	ColumnAccessor < mCFStaticData_512 > transfer_cash_flow_sa_bom;
 	ColumnAccessor < mCFStaticData_512 > transfer_cash_flow_sa_eom;
 	ColumnAccessor < mCFStaticData_512 > transfer_to_sa_net;
 	ColumnAccessor < mCFStaticData_512 > va_pba_asset_sa;
 	ColumnAccessor < mCFStaticData_512 > va_pba_ceded_cap_std_scen_ben_costs;
 	ColumnAccessor < mCFStaticData_512 > va_pba_ceded_cap_std_scen_margin;
 	ColumnAccessor < mCFStaticData_512 > va_pba_ceded_res_std_scen_ben_costs;
 	ColumnAccessor < mCFStaticData_512 > va_pba_ceded_res_std_scen_margin;
 	ColumnAccessor < mCFStaticData_512 > va_pba_gross_cap_std_scen_ben_costs;
 	ColumnAccessor < mCFStaticData_512 > va_pba_gross_cap_std_scen_margin;
 	ColumnAccessor < mCFStaticData_512 > va_pba_gross_res_std_scen_ben_costs;
 	ColumnAccessor < mCFStaticData_512 > va_pba_gross_res_std_scen_margin;
 	ColumnAccessor < mCFStaticData_512 > va_pba_working_res;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits;
//Column Definition END@2

 // Temporary Table...
EPL_LIAB *sm_bond_is;
EPL_LIAB *sm_bond_pv;
EPL_LIAB *sm_bond_ym;
EPL_LIAB *sm_mtg_is;
EPL_LIAB *sm_mtg_pv;
EPL_LIAB *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE EPL_LIAB::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > data_validation_defn;
  inline xstring	Get_data_validation_defn() {
		return data_validation_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > epl_file;
  inline xstring	Get_epl_file() {
		return epl_file; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > gaap_cohort;
  inline xstring	Get_gaap_cohort() {
		return gaap_cohort; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > loc_cohort;
  inline xstring	Get_loc_cohort() {
		return loc_cohort; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pct_to_use_mp;
  inline double	Get_pct_to_use_mp() {
		return pct_to_use_mp; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > reins_defn;
  inline xstring	Get_reins_defn() {
		return reins_defn; }
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
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > commencement_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > maturity_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_date_offset;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > reins_flag;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(EPL_LIAB* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Get EPL Value
#line 1 "get_epl_value.epl_liab.for"
double get_epl_value(const xstring &col_name, int t);

// Read EPL File
#line 1 "read_epl_file.epl_liab.for"
bool read_epl_file(const xstring &epl_file);

// Set Schedule Byte Markers
#line 1 "set_sched_byte_markers.epl_liab.for"
void set_sched_byte_markers(const xstring &sched_file);


//factory
static EPL_LIAB* makeThis(int isSubmodel, ModelClass *owner, EPL_LIAB* peer, 
					int mainRebase, const xstring &name, EPL_LIAB_persistent_object* arrayTemplate);

//constructor
EPL_LIAB(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
EPL_LIAB(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~EPL_LIAB();


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
class EPL_LIAB_persistent_object : public EPL_LIAB {


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

	void findTargetColumns() {EPL_LIAB::findTargetColumns();}
	void createAllShare() {
		EPL_LIAB::createAllShare();
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
	EPL_LIAB *&sm_bond_is; //
	EPL_LIAB *&sm_bond_pv; //
	EPL_LIAB *&sm_bond_ym; //
	EPL_LIAB *&sm_mtg_is; //
	EPL_LIAB *&sm_mtg_pv; //
	EPL_LIAB *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~EPL_LIAB_persistent_object();

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
static EPL_LIAB_persistent_object* makeThis(int isSubmodel, ModelClass *owner, EPL_LIAB* peer, 
					int mainRebase, const xstring &name, EPL_LIAB_persistent_object* arrayTemplate, bool fixedArray);

//constructor
EPL_LIAB_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
