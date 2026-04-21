#ifndef __SFAS97RD_GAAP_H_
#define __SFAS97RD_GAAP_H_
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



namespace SFAS97RD_GAAP_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class SFAS97RD_GAAP_persistent_object;
class SFAS97RD_GAAP : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(SFAS97RD_GAAP); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;
	static void Terminator();
	static FunctionPtr RegisterTerminatorOnce;
	
#if !defined(__VA_LIAB_H_) //WTW - Gen2 - Move outside of EXTERNS
// integers from VA_POL submodel
int AV_B_DCA = 0;
int AV_B_GA = 1;
#endif

//typedef map <int, long, less <int> > mpmap;//Gen2 - 9/6/2024 - comment out typedef
map <int, long, less <int> > ul_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
map <int, long, less <int> > vul_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
map <int, long, less <int> > iul_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
map <int, long, less <int> > va_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
map <int, long, less <int> > fa_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
map <int, long, less <int> > fia_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
map <int, long, less <int> > epl_mp_map;//Gen2 - 9/6/2024 - replace mpmap with full definition
xstring reins_defn;
int cohort_reins_indicator;
int cohort_reins_yrt_indicator;
int cohort_first_issue_period;
int cohort_last_issue_period;
int cohort_max_maturity_period;
SmartArray <SmartArray <double> > sop031_array;
SmartArray <SmartArray <double> > gaap_schedule;
double init_dac_acq_exp;
double init_dac_acq_exp_loss_rec;
double init_capzd_acq_exp_accum;
double init_capzd_acq_exp_accum_loss_rec_int_rate;
double init_dac_acq_exp_loss_rec_accum;
double init_dac_comm;
double init_dac_comm_loss_rec;
double init_capzd_comm_accum;
double init_capzd_comm_accum_loss_rec_int_rate;
double init_dac_comm_loss_rec_accum;
double init_dac_prem_bonus;
double init_dac_prem_bonus_loss_rec;
double init_capzd_prem_bonus_accum;
double init_capzd_prem_bonus_accum_loss_rec_int_rate;
double init_dac_prem_bonus_loss_rec_accum;
double init_egp_accum;
double init_egp_accum_loss_rec_int_rate;
double init_sop031_assess_accum;
double init_sop031_gmdb_ben_accum;
double init_sop031_gmib_ben_accum;
double init_sop031_gmwb_ben_accum;
double init_sop031_pbr_accum;
double init_deferred_loads_accum;
double init_unearn_rev_liab;
double init_dac_reins_yrt_asset;
double init_reins_yrt_cost_accum;
double init_sop031_pbr_fund_val_accum;
double init_embed_deriv_val;
double init_sfas133_gmab_liab;
double init_sfas133_gmib_liab;
double init_sfas133_gmwb_liab;
double init_sop031_ulsg_ben_accum;
double init_sop031_gmdb_br;
double init_sop031_gmib_br;
double init_sop031_gmwb_br;
double init_sop031_pbr_liab;
double init_sop031_ulsg_br;

	void init_(){
		

cohort_reins_indicator = 0;
cohort_reins_yrt_indicator = 0;
cohort_first_issue_period = 0;
cohort_last_issue_period = -9999;
cohort_max_maturity_period = -9999;
init_dac_acq_exp = 0.0;
init_dac_acq_exp_loss_rec = 0.0;
init_capzd_acq_exp_accum = 0.0;
init_capzd_acq_exp_accum_loss_rec_int_rate = 0.0;
init_dac_acq_exp_loss_rec_accum = 0.0;
init_dac_comm = 0.0;
init_dac_comm_loss_rec = 0.0;
init_capzd_comm_accum = 0.0;
init_capzd_comm_accum_loss_rec_int_rate = 0.0;
init_dac_comm_loss_rec_accum = 0.0;
init_dac_prem_bonus = 0.0;
init_dac_prem_bonus_loss_rec = 0.0;
init_capzd_prem_bonus_accum = 0.0;
init_capzd_prem_bonus_accum_loss_rec_int_rate = 0.0;
init_dac_prem_bonus_loss_rec_accum = 0.0;
init_egp_accum = 0.0;
init_egp_accum_loss_rec_int_rate = 0.0;
init_sop031_assess_accum = 0.0;
init_sop031_gmdb_ben_accum = 0.0;
init_sop031_gmib_ben_accum = 0.0;
init_sop031_gmwb_ben_accum = 0.0;
init_sop031_pbr_accum = 0.0;
init_deferred_loads_accum = 0.0;
init_unearn_rev_liab = 0.0;
init_dac_reins_yrt_asset = 0.0;
init_reins_yrt_cost_accum = 0.0;
init_sop031_pbr_fund_val_accum = 0.0;
init_embed_deriv_val = 0.0;
init_sfas133_gmab_liab = 0.0;
init_sfas133_gmib_liab = 0.0;
init_sfas133_gmwb_liab = 0.0;
init_sop031_ulsg_ben_accum = 0.0;
init_sop031_gmdb_br = 0.0;
init_sop031_gmib_br = 0.0;
init_sop031_gmwb_br = 0.0;
init_sop031_pbr_liab = 0.0;
init_sop031_ulsg_br = 0.0;

		bIsInit = true;
	}
	void deInit_(){

	}

#ifdef __CREATE_COMP_COMP_CLASS_
	COMP_COMP	*company;
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
	FIA_LIAB	*company_liab_fia;
	FIA_LIAB	*&fia;
#endif
#ifdef __CREATE_AUTOMATION_CLASS_
	AUTOMATION	*company_liab_fia_fia_automation;
	AUTOMATION	*&fia_automation;
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
 	ColumnAccessor < mCFStaticData_0 > agp;
 	ColumnAccessor < mCFStaticData_0 > amortzn_int_rate;
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > cap_gain;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_fund;
 	ColumnAccessor < mCFStaticData_0 > capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > capzd_acq_exp_accum;
 	ColumnAccessor < mCFStaticData_0 > capzd_acq_exp_accum_loss_rec_int_rate;
 	ColumnAccessor < mCFStaticData_0 > capzd_acq_exp_pv;
 	ColumnAccessor < mCFStaticData_0 > capzd_acq_exp_pv_loss_rec_int_rate;
 	ColumnAccessor < mCFStaticData_0 > capzd_comm_accum;
 	ColumnAccessor < mCFStaticData_0 > capzd_comm_accum_loss_rec_int_rate;
 	ColumnAccessor < mCFStaticData_0 > capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_0 > capzd_comm_chargeback;
 	ColumnAccessor < mCFStaticData_0 > capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_0 > capzd_comm_pv;
 	ColumnAccessor < mCFStaticData_0 > capzd_comm_pv_loss_rec_int_rate;
 	ColumnAccessor < mCFStaticData_0 > capzd_prem_bonus;
 	ColumnAccessor < mCFStaticData_0 > capzd_prem_bonus_accum;
 	ColumnAccessor < mCFStaticData_0 > capzd_prem_bonus_accum_loss_rec_int_rate;
 	ColumnAccessor < mCFStaticData_0 > capzd_prem_bonus_pv;
 	ColumnAccessor < mCFStaticData_0 > capzd_prem_bonus_pv_loss_rec_int_rate;
 	ColumnAccessor < mCFStaticData_0 > capzd_reins_yrt_cost;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_bom;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_int;
 	ColumnAccessor < mCFStaticData_0 > charges;
 	ColumnAccessor < mCFStaticData_0 > comm_chargeback;
 	ColumnAccessor < mCFStaticData_0 > comm_excess_bom;
 	ColumnAccessor < mCFStaticData_0 > comm_excess_eom;
 	ColumnAccessor < mCFStaticData_0 > comm_trail_bom;
 	ColumnAccessor < mCFStaticData_0 > comm_trail_eom;
 	ColumnAccessor < mCFStaticData_0 > credited_int;
 	ColumnAccessor < mCFStaticData_0 > dac_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > dac_acq_exp_amortzn;
 	ColumnAccessor < mCFStaticData_0 > dac_acq_exp_incr;
 	ColumnAccessor < mCFStaticData_0 > dac_acq_exp_int;
 	ColumnAccessor < mCFStaticData_0 > dac_acq_exp_loss_rec;
 	ColumnAccessor < mCFStaticData_0 > dac_acq_exp_loss_rec_accum;
 	ColumnAccessor < mCFStaticData_0 > dac_acq_exp_loss_rec_hist_accum;
 	ColumnAccessor < mCFStaticData_0 > dac_acq_exp_sch;
 	ColumnAccessor < mCFStaticData_0 > dac_comm;
 	ColumnAccessor < mCFStaticData_0 > dac_comm_amortzn;
 	ColumnAccessor < mCFStaticData_0 > dac_comm_incr;
 	ColumnAccessor < mCFStaticData_0 > dac_comm_int;
 	ColumnAccessor < mCFStaticData_0 > dac_comm_loss_rec;
 	ColumnAccessor < mCFStaticData_0 > dac_comm_loss_rec_accum;
 	ColumnAccessor < mCFStaticData_0 > dac_comm_loss_rec_hist_accum;
 	ColumnAccessor < mCFStaticData_0 > dac_comm_sch;
 	ColumnAccessor < mCFStaticData_0 > dac_incr;
 	ColumnAccessor < mCFStaticData_0 > dac_prem_bonus;
 	ColumnAccessor < mCFStaticData_0 > dac_prem_bonus_amortzn;
 	ColumnAccessor < mCFStaticData_0 > dac_prem_bonus_incr;
 	ColumnAccessor < mCFStaticData_0 > dac_prem_bonus_int;
 	ColumnAccessor < mCFStaticData_0 > dac_prem_bonus_loss_rec;
 	ColumnAccessor < mCFStaticData_0 > dac_prem_bonus_loss_rec_accum;
 	ColumnAccessor < mCFStaticData_0 > dac_prem_bonus_loss_rec_hist_accum;
 	ColumnAccessor < mCFStaticData_0 > dac_prem_bonus_sch;
 	ColumnAccessor < mCFStaticData_0 > dac_reins_yrt_asset;
 	ColumnAccessor < mCFStaticData_0 > dac_reins_yrt_asset_amortzn;
 	ColumnAccessor < mCFStaticData_0 > dac_reins_yrt_asset_incr;
 	ColumnAccessor < mCFStaticData_0 > dac_reins_yrt_asset_int;
 	ColumnAccessor < mCFStaticData_0 > dac_reins_yrt_asset_sch;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > deferred_loads;
 	ColumnAccessor < mCFStaticData_0 > deferred_loads_accum;
 	ColumnAccessor < mCFStaticData_0 > deferred_loads_pv;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > egp;
 	ColumnAccessor < mCFStaticData_0 > egp_accum;
 	ColumnAccessor < mCFStaticData_0 > egp_accum_loss_rec_int_rate;
 	ColumnAccessor < mCFStaticData_0 > egp_gain_exp;
 	ColumnAccessor < mCFStaticData_0 > egp_gain_inv;
 	ColumnAccessor < mCFStaticData_0 > egp_gain_mort;
 	ColumnAccessor < mCFStaticData_0 > egp_gain_persist_bon_ref;
 	ColumnAccessor < mCFStaticData_0 > egp_gain_surr;
 	ColumnAccessor < mCFStaticData_0 > egp_pv;
 	ColumnAccessor < mCFStaticData_0 > egp_pv_loss_rec_int_rate;
 	ColumnAccessor < mCFStaticData_0 > egp_sop031_assess_accum;
 	ColumnAccessor < mCFStaticData_0 > egp_sop031_gmdb_ben_accum;
 	ColumnAccessor < mCFStaticData_0 > egp_sop031_gmdb_liab;
 	ColumnAccessor < mCFStaticData_0 > egp_sop031_gmib_ben_accum;
 	ColumnAccessor < mCFStaticData_0 > egp_sop031_gmib_liab;
 	ColumnAccessor < mCFStaticData_0 > egp_sop031_gmwb_ben_accum;
 	ColumnAccessor < mCFStaticData_0 > egp_sop031_gmwb_liab;
 	ColumnAccessor < mCFStaticData_0 > egp_sop031_res_incr;
 	ColumnAccessor < mCFStaticData_0 > egp_sop031_ulsg_ben_accum;
 	ColumnAccessor < mCFStaticData_0 > egp_sop031_ulsg_liab;
 	ColumnAccessor < mCFStaticData_0 > embed_deriv_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > embed_deriv_cash_flow_pv;
 	ColumnAccessor < mCFStaticData_0 > embed_deriv_val;
 	ColumnAccessor < mCFStaticData_0 > finalize;
 	ColumnAccessor < mCFStaticData_0 > fund_val;
 	ColumnAccessor < mCFStaticData_0 > fund_val_bef_int;
 	ColumnAccessor < mCFStaticData_0 > fund_val_fixed;
 	ColumnAccessor < mCFStaticData_0 > fund_val_sa;
 	ColumnAccessor < mCFStaticData_0 > gaap_amortzn_int_rate;
 	ColumnAccessor < mCFStaticData_0 > gmab_ben;
 	ColumnAccessor < mCFStaticData_0 > gmdb_ben;
 	ColumnAccessor < mCFStaticData_0 > gmib_ben;
 	ColumnAccessor < mCFStaticData_0 > gmwb_ben;
 	ColumnAccessor < mCFStaticData_0 > hedge_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > hedge_cost;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_0 > host_contract_cred_int;
 	ColumnAccessor < mCFStaticData_0 > host_contract_val;
 	ColumnAccessor < mCFStaticData_0 > host_contract_val_bef;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > inv_inc;
 	ColumnAccessor < mCFStaticData_0 > inv_inc_fund;
 	ColumnAccessor < mCFStaticData_0 > k_capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > k_capzd_acq_exp_sch;
 	ColumnAccessor < mCFStaticData_0 > k_capzd_comm;
 	ColumnAccessor < mCFStaticData_0 > k_capzd_comm_sch;
 	ColumnAccessor < mCFStaticData_0 > k_capzd_prem_bonus;
 	ColumnAccessor < mCFStaticData_0 > k_capzd_prem_bonus_sch;
 	ColumnAccessor < mCFStaticData_0 > k_reins_yrt_cost;
 	ColumnAccessor < mCFStaticData_0 > k_reins_yrt_cost_sch;
 	ColumnAccessor < mCFStaticData_0 > k_sop031_gmdb_ben_br;
 	ColumnAccessor < mCFStaticData_0 > k_sop031_gmdb_ben_br_sch;
 	ColumnAccessor < mCFStaticData_0 > k_sop031_pbr;
 	ColumnAccessor < mCFStaticData_0 > k_sop031_pbr_sch;
 	ColumnAccessor < mCFStaticData_0 > k_sop031_ulsg_ben_br;
 	ColumnAccessor < mCFStaticData_0 > k_sop031_ulsg_ben_br_sch;
 	ColumnAccessor < mCFStaticData_0 > k_sop031_unearn_rev_liab;
 	ColumnAccessor < mCFStaticData_0 > k_sop031_unearn_rev_liab_sch;
 	ColumnAccessor < mCFStaticData_0 > k_unearn_rev_liab;
 	ColumnAccessor < mCFStaticData_0 > k_unearn_rev_liab_sch;
 	ColumnAccessor < mCFStaticData_0 > liab_net;
 	ColumnAccessor < mCFStaticData_0 > loads;
 	ColumnAccessor < mCFStaticData_0 > loc_cost;
 	ColumnAccessor < mCFStaticData_0 > loss_rec_amortzn_int_rate;
 	ColumnAccessor < mCFStaticData_0 > maint_exp_bom;
 	ColumnAccessor < mCFStaticData_0 > maint_exp_eom;
 	ColumnAccessor < mCFStaticData_0 > modco_liab;
 	ColumnAccessor < mCFStaticData_0 > modco_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > modco_res_adj;
 	ColumnAccessor < mCFStaticData_0 > persist_bon_ref;
 	ColumnAccessor < mCFStaticData_0 > pol_loan;
 	ColumnAccessor < mCFStaticData_0 > pol_loan_inc;
 	ColumnAccessor < mCFStaticData_0 > policies_b;
 	ColumnAccessor < mCFStaticData_0 > prem_bonus;
 	ColumnAccessor < mCFStaticData_0 > prem_tax;
 	ColumnAccessor < mCFStaticData_0 > refund;
 	ColumnAccessor < mCFStaticData_0 > reins_yrt_cost;
 	ColumnAccessor < mCFStaticData_0 > reins_yrt_cost_accum;
 	ColumnAccessor < mCFStaticData_0 > reins_yrt_cost_pv;
 	ColumnAccessor < mCFStaticData_0 > rider_charges;
 	ColumnAccessor < mCFStaticData_0 > sfas133_fia_iul_liab;
 	ColumnAccessor < mCFStaticData_0 > sfas133_gmab_liab;
 	ColumnAccessor < mCFStaticData_0 > sfas133_gmib_liab;
 	ColumnAccessor < mCFStaticData_0 > sfas133_gmwb_liab;
 	ColumnAccessor < mCFStaticData_0 > sfas133_liab;
 	ColumnAccessor < mCFStaticData_0 > sfas133_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > sop031_addl_liab;
 	ColumnAccessor < mCFStaticData_0 > sop031_addl_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > sop031_assess;
 	ColumnAccessor < mCFStaticData_0 > sop031_assess_accum;
 	ColumnAccessor < mCFStaticData_0 > sop031_assess_pv;
 	ColumnAccessor < mCFStaticData_0 > sop031_egp;
 	ColumnAccessor < mCFStaticData_0 > sop031_egp_accum;
 	ColumnAccessor < mCFStaticData_0 > sop031_egp_pv;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmdb_ben_accum;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmdb_ben_pv;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmdb_br;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmdb_br_sch;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmdb_liab;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmib_ben_accum;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmib_ben_pv;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmib_br;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmib_br_sch;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmib_liab;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmwb_ben_accum;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmwb_ben_pv;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmwb_br;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmwb_br_sch;
 	ColumnAccessor < mCFStaticData_0 > sop031_gmwb_liab;
 	ColumnAccessor < mCFStaticData_0 > sop031_pbr;
 	ColumnAccessor < mCFStaticData_0 > sop031_pbr_accum;
 	ColumnAccessor < mCFStaticData_0 > sop031_pbr_fund_val;
 	ColumnAccessor < mCFStaticData_0 > sop031_pbr_fund_val_accum;
 	ColumnAccessor < mCFStaticData_0 > sop031_pbr_fund_val_pv;
 	ColumnAccessor < mCFStaticData_0 > sop031_pbr_liab;
 	ColumnAccessor < mCFStaticData_0 > sop031_pbr_liab_amortzn;
 	ColumnAccessor < mCFStaticData_0 > sop031_pbr_liab_int;
 	ColumnAccessor < mCFStaticData_0 > sop031_pbr_liab_sch;
 	ColumnAccessor < mCFStaticData_0 > sop031_pbr_pv;
 	ColumnAccessor < mCFStaticData_0 > sop031_pbr_units_inf;
 	ColumnAccessor < mCFStaticData_0 > sop031_ulsg_ben_accum;
 	ColumnAccessor < mCFStaticData_0 > sop031_ulsg_ben_pv;
 	ColumnAccessor < mCFStaticData_0 > sop031_ulsg_br;
 	ColumnAccessor < mCFStaticData_0 > sop031_ulsg_br_sch;
 	ColumnAccessor < mCFStaticData_0 > sop031_ulsg_liab;
 	ColumnAccessor < mCFStaticData_0 > sop031_unearn_rev_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > startup;
 	ColumnAccessor < mCFStaticData_0 > stat_res_rider;
 	ColumnAccessor < mCFStaticData_0 > ulsg_ben;
 	ColumnAccessor < mCFStaticData_0 > unearn_rev_liab;
 	ColumnAccessor < mCFStaticData_0 > unearn_rev_liab_accum;
 	ColumnAccessor < mCFStaticData_0 > unearn_rev_liab_amortzn;
 	ColumnAccessor < mCFStaticData_0 > unearn_rev_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > unearn_rev_liab_int;
 	ColumnAccessor < mCFStaticData_0 > unearn_rev_liab_released;
 	ColumnAccessor < mCFStaticData_0 > unearn_rev_liab_sch;
//Column Definition END@2

 // Temporary Table...
SFAS97RD_GAAP *sm_bond_is;
SFAS97RD_GAAP *sm_bond_pv;
SFAS97RD_GAAP *sm_bond_ym;
SFAS97RD_GAAP *sm_mtg_is;
SFAS97RD_GAAP *sm_mtg_pv;
SFAS97RD_GAAP *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE SFAS97RD_GAAP::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > amortzn_mths;
  inline int	Get_amortzn_mths() {
		return amortzn_mths; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_gaap_int_rate_ceded;
  inline double	Get_cohort_gaap_int_rate_ceded() {
		return cohort_gaap_int_rate_ceded; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_gaap_int_rate_gross;
  inline double	Get_cohort_gaap_int_rate_gross() {
		return cohort_gaap_int_rate_gross; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_agp;
  inline double	Get_cohort_history_agp() {
		return cohort_history_agp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_capzd_acq_exp;
  inline double	Get_cohort_history_capzd_acq_exp() {
		return cohort_history_capzd_acq_exp; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_capzd_comm_bom;
  inline double	Get_cohort_history_capzd_comm_bom() {
		return cohort_history_capzd_comm_bom; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_capzd_comm_eom;
  inline double	Get_cohort_history_capzd_comm_eom() {
		return cohort_history_capzd_comm_eom; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_capzd_prem_bonus;
  inline double	Get_cohort_history_capzd_prem_bonus() {
		return cohort_history_capzd_prem_bonus; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_dac_acq_exp_loss;
  inline double	Get_cohort_history_dac_acq_exp_loss() {
		return cohort_history_dac_acq_exp_loss; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_dac_comm_loss;
  inline double	Get_cohort_history_dac_comm_loss() {
		return cohort_history_dac_comm_loss; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_dac_prem_bonus_loss;
  inline double	Get_cohort_history_dac_prem_bonus_loss() {
		return cohort_history_dac_prem_bonus_loss; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_deferred_load;
  inline double	Get_cohort_history_deferred_load() {
		return cohort_history_deferred_load; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_reins_yrt_cost;
  inline double	Get_cohort_history_reins_yrt_cost() {
		return cohort_history_reins_yrt_cost; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_sop031_assess;
  inline double	Get_cohort_history_sop031_assess() {
		return cohort_history_sop031_assess; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_sop031_gmdb_benefits;
  inline double	Get_cohort_history_sop031_gmdb_benefits() {
		return cohort_history_sop031_gmdb_benefits; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_sop031_gmib_benefits;
  inline double	Get_cohort_history_sop031_gmib_benefits() {
		return cohort_history_sop031_gmib_benefits; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_sop031_gmwb_benefits;
  inline double	Get_cohort_history_sop031_gmwb_benefits() {
		return cohort_history_sop031_gmwb_benefits; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_sop031_pbr_benefits;
  inline double	Get_cohort_history_sop031_pbr_benefits() {
		return cohort_history_sop031_pbr_benefits; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_sop031_pbr_fund_val;
  inline double	Get_cohort_history_sop031_pbr_fund_val() {
		return cohort_history_sop031_pbr_fund_val; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_sop031_sg_benefits;
  inline double	Get_cohort_history_sop031_sg_benefits() {
		return cohort_history_sop031_sg_benefits; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_history_unearn_rev_liab;
  inline double	Get_cohort_history_unearn_rev_liab() {
		return cohort_history_unearn_rev_liab; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > cohort_id;
  inline xstring	Get_cohort_id() {
		return cohort_id; }
  inline void Set_cohort_id(const xstring &v) {
		cohort_id.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > cohort_issue_yrs;
  inline xstring	Get_cohort_issue_yrs() {
		return cohort_issue_yrs; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_loss_recognition_int_rate_ceded;
  inline double	Get_cohort_loss_recognition_int_rate_ceded() {
		return cohort_loss_recognition_int_rate_ceded; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cohort_loss_recognition_int_rate_gross;
  inline double	Get_cohort_loss_recognition_int_rate_gross() {
		return cohort_loss_recognition_int_rate_gross; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > cohort_plan_codes;
  inline xstring	Get_cohort_plan_codes() {
		return cohort_plan_codes; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > cohort_reins_defn;
  inline xstring	Get_cohort_reins_defn() {
		return cohort_reins_defn; }
  inline void Set_cohort_reins_defn(const xstring &v) {
		cohort_reins_defn.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > cohort_yr;
  inline int	Get_cohort_yr() {
		return cohort_yr; }
  inline void Set_cohort_yr(const int &v) {
		cohort_yr.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > date_lookup_gen2;
  inline int	Get_date_lookup_gen2() {
		return date_lookup_gen2; }
  inline void Set_date_lookup_gen2(const int &v) {
		date_lookup_gen2.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > fia_gaap_int_rate;
  inline double	Get_fia_gaap_int_rate() {
		return fia_gaap_int_rate; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmib_ceded_defn;
  inline xstring	Get_gmib_ceded_defn() {
		return gmib_ceded_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmib_gross_defn;
  inline xstring	Get_gmib_gross_defn() {
		return gmib_gross_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_ceded_defn;
  inline xstring	Get_gmwb_ceded_defn() {
		return gmwb_ceded_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_gross_defn;
  inline xstring	Get_gmwb_gross_defn() {
		return gmwb_gross_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > loss_recognition_defn;
  inline xstring	Get_loss_recognition_defn() {
		return loss_recognition_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > seg_id;
  inline xstring	Get_seg_id() {
		return seg_id; }
  inline void Set_seg_id(const xstring &v) {
		seg_id.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > sfas97rd_results;
  inline xstring	Get_sfas97rd_results() {
		return sfas97rd_results; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > sop031_results;
  inline xstring	Get_sop031_results() {
		return sop031_results; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > sop031_ul_vul_iul_defn;
  inline xstring	Get_sop031_ul_vul_iul_defn() {
		return sop031_ul_vul_iul_defn; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > amortzn_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > comm_pct_fund_ult_index;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > final_period;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > gaap_int_rate;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > gaap_int_rate_mthly;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gmib_defn;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gmib_sop031_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gmwb_defn;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gmwb_sop031_flag;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > hedge_alloc_factor;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > host_accrual_rate;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > loss_rec_int_rate;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > loss_rec_int_rate_mthly;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > loss_recognition_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > pbr_final_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > prem_term_period;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > proj_date_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_date;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_yr;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > reins_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > sop031_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > start_period;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > state_of_world_financial_file_path;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(SFAS97RD_GAAP* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Build EGP and Amortization Interest Rates Schedule
#line 1 "get_gaap_schedule_items.sfas97rd_gaap.for"
void get_gaap_schedule_items(void);

// Get SOP 03-1 Valuation Results
#line 1 "get_sop031_valn_results.sfas97rd_gaap.for"
void get_sop031_valn_results(void);

// Read State of World Financial
#line 1 "read_state_of_world_financial.sfas97rd_gaap.for"
void read_state_of_world_financial(void);

// Setup Cohorts
#line 1 "setup_cohorts.sfas97rd_gaap.for"
bool setup_cohorts(int mp_iss_yr_int, xstring mp_plan_code, xstring mp_cohort_map_id, xstring cohort);

// Sum Over GAAP
#line 1 "sum_over_gaap.sfas97rd_gaap.for"
double sum_over_gaap(const xstring &colname, int t);

// Write State of World Financial
#line 1 "write_state_of_world_financial.sfas97rd_gaap.for"
void write_state_of_world_financial(void);


//factory
static SFAS97RD_GAAP* makeThis(int isSubmodel, ModelClass *owner, SFAS97RD_GAAP* peer, 
					int mainRebase, const xstring &name, SFAS97RD_GAAP_persistent_object* arrayTemplate);

//constructor
SFAS97RD_GAAP(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
SFAS97RD_GAAP(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~SFAS97RD_GAAP();


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
class SFAS97RD_GAAP_persistent_object : public SFAS97RD_GAAP {


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

	void findTargetColumns() {SFAS97RD_GAAP::findTargetColumns();}
	void createAllShare() {
		SFAS97RD_GAAP::createAllShare();
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
	SFAS97RD_GAAP *&sm_bond_is; //
	SFAS97RD_GAAP *&sm_bond_pv; //
	SFAS97RD_GAAP *&sm_bond_ym; //
	SFAS97RD_GAAP *&sm_mtg_is; //
	SFAS97RD_GAAP *&sm_mtg_pv; //
	SFAS97RD_GAAP *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~SFAS97RD_GAAP_persistent_object();

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
static SFAS97RD_GAAP_persistent_object* makeThis(int isSubmodel, ModelClass *owner, SFAS97RD_GAAP* peer, 
					int mainRebase, const xstring &name, SFAS97RD_GAAP_persistent_object* arrayTemplate, bool fixedArray);

//constructor
SFAS97RD_GAAP_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
