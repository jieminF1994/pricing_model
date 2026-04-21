#ifndef __FIA_LIAB_H_
#define __FIA_LIAB_H_
#pragma warning ( disable : 4819 )

//#include "rates_economy.h" //WTW - Gen2

// 20191015 MTC - PV benefit ITM refactor
// 20191112 MTC - Changed maps to vectors for optimization

// 20181217 MTC - Refactored cubic spline
#ifndef CUBIC_SPLINE_AIG//WTW - Gen2
struct cubic_spline_params_aig
{
	cubic_spline_params_aig(): initialized(false),
						       n(0),
							   h(vector<double>()),
							   alpha(vector<double>()),
							   l(vector<double>()),
							   mu(vector<double>()),
							   z(vector<double>()),
							   c(vector<double>()),
							   b(vector<double>()),
							   d(vector<double>()) {}
	bool initialized;
	int n;
	vector<double> h;
	vector<double> alpha;
	vector<double> l;
	vector<double> mu;
	vector<double> z;
	vector<double> c;
	vector<double> b;
	vector<double> d;
};

const cubic_spline_params_aig default_cubic_spline_params_aig = cubic_spline_params_aig();
// 20181217 MTC END
#define CUBIC_SPLINE_AIG//WTW - Gen2
#endif//WTW - Gen2


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


#include "ModelClass\fiacarvm_liab.h"
#include "ModelClass\fiaafund_liab.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\automation.h"
#include "ModelClass\bond_portfolio_aig.h"
#include "ModelClass\rates_economy.h"
#include "ModelClass\sfas133_gaap.h"
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
//typedef map <xstring, double, less<xstring> > crmap;//Gen2 - 9/6/2024 - comment out typedef
map <xstring, double, less<xstring> > comp_rates_map;//Gen2 - 9/6/2024 - replace crmap with full definition
// discount rate vector
vector<string> disc_rates;
vector<string> gaap_cohorts_sfas97rd;
//SmartArray <double> init_tax_capzd_prem_amortzn_sched;
vector <double> init_tax_capzd_prem_amortzn_sched;//WTW - Gen2
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
xstring stat_audit_detail_rpt_id;
xstring tax_audit_detail_rpt_id;

const size_t NUM_UNIFORM_STREAMS_AIG = 7;
vector< vector <double>> uniform_rands_arr_aig;


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
stat_audit_detail_rpt_id = "";
tax_audit_detail_rpt_id = "";

// 20190913 MTC - Removed spousal_cont_adj flag


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
#ifdef __CREATE_COMP_COMP_CLASS_
	COMP_COMP	*company;
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
#ifdef __CREATE_AUTOMATION_CLASS_
	AUTOMATION	*company_liab_fia_fia_automation;
	AUTOMATION	*&fia_automation;
#endif
#ifdef __CREATE_BOND_PORTFOLIO_AIG_CLASS_
	BOND_PORTFOLIO_AIG	*company_liab_fia_fia_bond_portfolio_aig;
	BOND_PORTFOLIO_AIG	*&fia_bond_portfolio_aig;
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
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
	SFAS97RD_GAAP	*company_liab_fia_fia_sfas97rd;
	SFAS97RD_GAAP	*&fia_sfas97rd;
#endif
#ifdef __CREATE_INTEX_ASSET_CLASS_
	INTEX_ASSET	*company_asset_intex;
	INTEX_ASSET	*&intex;
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
 	ColumnAccessor < mCFStaticData_0 > acq_exp;
 	ColumnAccessor < mCFStaticData_0 > acq_exp_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > acq_exp_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > acq_exp_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > acq_exp_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > admin_fee;
 	ColumnAccessor < mCFStaticData_0 > age_last;
 	ColumnAccessor < mCFStaticData_0 > ann_benefits_eom;
 	ColumnAccessor < mCFStaticData_0 > ann_benefits_eom_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > ann_benefits_eom_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > ann_benefits_eom_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > ann_benefits_eom_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > ann_claims_gmwb;
 	ColumnAccessor < mCFStaticData_0 > ann_claims_gmwb_bef_maturity_aig;
 	ColumnAccessor < mCFStaticData_0 > ann_claims_gmwb_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > ann_claims_gmwb_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > ann_claims_gmwb_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > ann_claims_gmwb_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_count_aig;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_count_aig_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_count_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_count_aig_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_count_aig_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_rate;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_rate_mthly;
 	ColumnAccessor < mCFStaticData_0 > asset_yld;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_inv;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_inv_adj_aig;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_less_dflt;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_less_dflt_inv;
 	ColumnAccessor < mCFStaticData_0 > attained_age;
 	ColumnAccessor < mCFStaticData_0 > attained_age_female_aig;
 	ColumnAccessor < mCFStaticData_0 > attained_age_male_aig;
 	ColumnAccessor < mCFStaticData_0 > avg_coupon_rt_aig;
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
 	ColumnAccessor < mCFStaticData_0 > cal_quarter_aig;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_pct_aig;
 	ColumnAccessor < mCFStaticData_0 > cash_val;
 	ColumnAccessor < mCFStaticData_0 > cash_val_bef;
 	ColumnAccessor < mCFStaticData_0 > cash_val_no_mva_aig;
 	ColumnAccessor < mCFStaticData_0 > cash_val_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > cash_val_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > cash_val_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > cash_val_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > comm_bom;
 	ColumnAccessor < mCFStaticData_0 > comm_bom_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > comm_bom_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > comm_bom_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > comm_bom_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > comm_chargeback;
 	ColumnAccessor < mCFStaticData_0 > comm_chargeback_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > comm_chargeback_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > comm_chargeback_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > comm_chargeback_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > comm_eom;
 	ColumnAccessor < mCFStaticData_0 > comm_fund_based;
 	ColumnAccessor < mCFStaticData_0 > comm_prem_based;
 	ColumnAccessor < mCFStaticData_0 > comm_subject_to_chargeback;
 	ColumnAccessor < mCFStaticData_0 > comm_subject_to_chargeback_e;
 	ColumnAccessor < mCFStaticData_0 > comp_lookup_aig_gen2;
 	ColumnAccessor < mCFStaticData_0 > contract_val;
 	ColumnAccessor < mCFStaticData_0 > contract_val_bef;
 	ColumnAccessor < mCFStaticData_0 > covered_person_status_col_e_bef_aig;
 	ColumnAccessor < mCFStaticData_0 > credited_int;
 	ColumnAccessor < mCFStaticData_0 > credited_int_comp_numer;
 	ColumnAccessor < mCFStaticData_0 > credited_int_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > credited_int_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > credited_int_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > credited_int_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > crediting_asset_yld_sprd_aig;
 	ColumnAccessor < mCFStaticData_0 > crediting_cap_spr_fix_index0_aig;
 	ColumnAccessor < mCFStaticData_0 > crediting_part_rate_base_index0_aig;
 	ColumnAccessor < mCFStaticData_0 > crediting_part_rate_index0_aig;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate_fix;
 	ColumnAccessor < mCFStaticData_0 > crediting_rate_partial_e_bef_aig;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > direct_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_0 > direct_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_0 > direct_cash_flow_int;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_2;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_3;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_port_yld;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_port_yld_defn_val;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_pv_shifted_aig;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_risk_free_aig;
 	ColumnAccessor < mCFStaticData_0 > disc_rate_sprd_uel_col_aig;
 	ColumnAccessor < mCFStaticData_0 > distrib_earnings;
 	ColumnAccessor < mCFStaticData_0 > distrib_earnings_irr;
 	ColumnAccessor < mCFStaticData_0 > dth_ben_inf;
 	ColumnAccessor < mCFStaticData_0 > dth_ben_inf_bef;
 	ColumnAccessor < mCFStaticData_0 > dth_ben_naar_bef_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_benefits;
 	ColumnAccessor < mCFStaticData_0 > dth_benefits_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > dth_benefits_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_benefits_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_benefits_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_rate_mthly;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_rate_mthly_blended_experience_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_rate_mthly_experience_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_rate_mthly_female_confinement_non_confined_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_rate_mthly_female_experience_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_rate_mthly_female_gmwb_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_rate_mthly_last_survivor_experience_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_rate_mthly_last_survivor_gmwb_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_rate_mthly_last_survivor_spousal_2019_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_rate_mthly_male_confinement_non_confined_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_rate_mthly_male_experience_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_claim_rate_mthly_male_gmwb_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_count_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_count_aig_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > dth_count_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_count_aig_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > dth_count_aig_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > earnings_accum;
 	ColumnAccessor < mCFStaticData_0 > enhanced_income_benefit_cumul_yrs_aig;
 	ColumnAccessor < mCFStaticData_0 > enhanced_income_benefit_eligibility_flag_aig;
 	ColumnAccessor < mCFStaticData_0 > enhanced_income_benefit_exercise_flag_aig;
 	ColumnAccessor < mCFStaticData_0 > enhanced_income_benefit_indirect_exercise_flag_aig;
 	ColumnAccessor < mCFStaticData_0 > enhanced_income_confinement_mth_female_e_aig;
 	ColumnAccessor < mCFStaticData_0 > enhanced_income_confinement_mth_male_e_aig;
 	ColumnAccessor < mCFStaticData_0 > enhanced_income_confinement_state_b_aig;
 	ColumnAccessor < mCFStaticData_0 > enhanced_income_confinement_state_female_b_aig;
 	ColumnAccessor < mCFStaticData_0 > enhanced_income_confinement_state_male_b_aig;
 	ColumnAccessor < mCFStaticData_0 > enhanced_income_rand_female_aig;
 	ColumnAccessor < mCFStaticData_0 > enhanced_income_rand_male_aig;
 	ColumnAccessor < mCFStaticData_0 > enhanced_income_utilization_rand_aig;
 	ColumnAccessor < mCFStaticData_0 > finalize;
 	ColumnAccessor < mCFStaticData_0 > fund_released_ann;
 	ColumnAccessor < mCFStaticData_0 > fund_released_ann_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > fund_released_ann_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_ann_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_ann_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_dth;
 	ColumnAccessor < mCFStaticData_0 > fund_released_dth_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > fund_released_dth_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_dth_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_dth_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_maturity;
 	ColumnAccessor < mCFStaticData_0 > fund_released_maturity_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > fund_released_maturity_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_maturity_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_maturity_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_surr;
 	ColumnAccessor < mCFStaticData_0 > fund_released_surr_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > fund_released_surr_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_surr_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_surr_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_withdrl;
 	ColumnAccessor < mCFStaticData_0 > fund_released_withdrl_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > fund_released_withdrl_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_withdrl_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_released_withdrl_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b_bef;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b_bef_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b_bef_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b_bef_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b_bef_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_val_b_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_val_boy_b_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_val_boy_e_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_val_decrem;
 	ColumnAccessor < mCFStaticData_0 > fund_val_e_bef;
 	ColumnAccessor < mCFStaticData_0 > fund_val_e_bef_maturity_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_val_fixed;
 	ColumnAccessor < mCFStaticData_0 > fund_val_fixed_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > fund_val_fixed_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_val_fixed_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_val_fixed_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_weighted_cap_spread_fix_rt_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_weighted_crediting_asset_yld_sprd_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_weighted_par_rate_aig;
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
 	ColumnAccessor < mCFStaticData_0 > gaap_prem_bonus;
 	ColumnAccessor < mCFStaticData_0 > gaap_prem_tax;
 	ColumnAccessor < mCFStaticData_0 > gaap_prof_aft_tax_for_pv;
 	ColumnAccessor < mCFStaticData_0 > gaap_prof_bef_tax_for_pv;
 	ColumnAccessor < mCFStaticData_0 > gaap_req_cap;
 	ColumnAccessor < mCFStaticData_0 > gaap_sfas133_liab;
 	ColumnAccessor < mCFStaticData_0 > gaap_sfas133_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_sop031_addl_liab;
 	ColumnAccessor < mCFStaticData_0 > gaap_sop031_addl_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_surp_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_surr_inc;
 	ColumnAccessor < mCFStaticData_0 > gender_col_e_bef_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg_at_surr_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg_at_surr_bef_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_chg_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_claim_start_duration_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_entitlement_remaining_e_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_entitlement_remaining_e_bef_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_exercise_yrs_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_flex_covered_person_change_expense_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_flex_covered_person_change_expense_aig_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_0 > gmwb_flex_covered_person_change_expense_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_flex_covered_person_change_expense_aig_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_flex_covered_person_change_expense_aig_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_flex_exercise_mth_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_income_base_b_aig;
 	ColumnAccessor < mCFStaticData_0 > gmwb_income_base_cap_b_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_cap_e_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_cap_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_cap_prem_base_b_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_cap_prem_base_e_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_cap_prem_base_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_e_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_floor_e_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_floor_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_floor_prem_pct_col_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_ny_b_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_ny_b_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_ny_e_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_ny_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_reduction_fct_cumul_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_reduction_fct_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_base_reduction_fct_ny_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_credit_base_e_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_credit_base_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_credit_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_income_start_duration_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_inf;
 	ColumnAccessor < mCFStaticData_256 > gmwb_inf_bef;
 	ColumnAccessor < mCFStaticData_256 > gmwb_itm;
 	ColumnAccessor < mCFStaticData_256 > gmwb_mawa_floor_e_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_mawa_floor_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_max_annual_wdl_pct_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_max_wdl_amt_bef_utilization_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_max_wdl_amt_utilized;
 	ColumnAccessor < mCFStaticData_256 > gmwb_min_income_base_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_pipp_stepup_ind_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_wdl_utilization_level_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_wdl_utilization_pct_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_withdrl_rate_indexing_addn_b_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_withdrl_rate_indexing_assessment_max_ref_rate_b_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_withdrl_rate_indexing_assessment_max_ref_rate_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_withdrl_rate_indexing_assessment_stepup_ind_b_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_withdrl_rate_indexing_policy_issue_ref_rate_aig;
 	ColumnAccessor < mCFStaticData_256 > gmwb_withdrl_rate_indexing_ref_rate_aig;
 	ColumnAccessor < mCFStaticData_256 > grop_inf_aig;
 	ColumnAccessor < mCFStaticData_256 > grop_inf_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > gross_prem_annualzd;
 	ColumnAccessor < mCFStaticData_256 > gross_sfc_ben_aig;
 	ColumnAccessor < mCFStaticData_256 > gwl_acq_exp_allow_aig;
 	ColumnAccessor < mCFStaticData_256 > gwl_ceding_exp_allow_aig;
 	ColumnAccessor < mCFStaticData_256 > gwl_maint_exp_allow_aig;
 	ColumnAccessor < mCFStaticData_256 > gwl_make_whole_settlement_adj_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_cash_flow;
 	ColumnAccessor < mCFStaticData_256 > hedge_cash_flow_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > hedge_cash_flow_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_cash_flow_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_cash_flow_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_cost;
 	ColumnAccessor < mCFStaticData_256 > hedge_cost_per_unit_notional_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_cost_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > hedge_cost_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_cost_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_cost_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_inv_amt_bom;
 	ColumnAccessor < mCFStaticData_256 > hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_256 > hedge_mkt_val_growth;
 	ColumnAccessor < mCFStaticData_256 > hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_256 > hedge_rila_trading_cost_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_rila_trading_cost_aig_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > hedge_rila_trading_cost_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_rila_trading_cost_aig_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_rila_trading_cost_aig_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_256 > hedge_sale_amt_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > hedge_sale_amt_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_sale_amt_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_sale_amt_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > index_term_index_return_aig;
 	ColumnAccessor < mCFStaticData_256 > infl_cumul;
 	ColumnAccessor < mCFStaticData_256 > init_opt_cost_print_aig;
 	ColumnAccessor < mCFStaticData_256 > initial_opt_cost_aig;
 	ColumnAccessor < mCFStaticData_256 > initialize;
 	ColumnAccessor < mCFStaticData_256 > inv_asset;
 	ColumnAccessor < mCFStaticData_256 > inv_inc;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_bk_prof;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_earnings_accum;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_fund;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_on_invested_assets;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_res;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_tgt_cap;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_undistrib_earnings;
 	ColumnAccessor < mCFStaticData_256 > irr;
 	ColumnAccessor < mCFStaticData_256 > irr_wo_tgt_cap;
 	ColumnAccessor < mCFStaticData_256 > isl_2019_pv_gmwb_benefit_aig;
 	ColumnAccessor < mCFStaticData_256 > isl_2019_pv_gmwb_benefit_at_issue_aig;
 	ColumnAccessor < mCFStaticData_256 > issue_age_col_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > issue_age_mp_lookup_gen2;
 	ColumnAccessor < mCFStaticData_256 > itmness_lookup_aig_gen2;
 	ColumnAccessor < mCFStaticData_256 > lapse_count_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_count_aig_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > lapse_count_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_count_aig_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_count_aig_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_addn_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_alt_model_mthly_addn_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_alt_model_mult_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_arctan_2019_mult_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_arctan_mult_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_base_prod_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_base_prod_crediting_rt_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_beta_mult_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_mthly_addn_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_mult_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_new_money_rate_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_rate_add_isl_2019_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_rila_base_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_rop_db_mult_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_dyn_sfc_mult_aig;
 	ColumnAccessor < mCFStaticData_256 > lapse_rate;
 	ColumnAccessor < mCFStaticData_256 > lapse_rate_base;
 	ColumnAccessor < mCFStaticData_256 > lapse_rate_mthly;
 	ColumnAccessor < mCFStaticData_256 > lapse_rate_mthly_skew2025_crbg;
 	ColumnAccessor < mCFStaticData_256 > lapse_rate_planned_numer;
 	ColumnAccessor < mCFStaticData_256 > last_period_indicator;
 	ColumnAccessor < mCFStaticData_256 > liab_and_surp;
 	ColumnAccessor < mCFStaticData_256 > liab_duration_aig;
 	ColumnAccessor < mCFStaticData_256 > maint_exp_bom;
 	ColumnAccessor < mCFStaticData_256 > maint_exp_eom;
 	ColumnAccessor < mCFStaticData_256 > maint_exp_eom_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > maint_exp_eom_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > maint_exp_eom_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > maint_exp_eom_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > maturity_benefits;
 	ColumnAccessor < mCFStaticData_256 > maturity_benefits_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > maturity_benefits_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > maturity_benefits_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > maturity_benefits_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > mb_pre_tax_cash_flow_aig;
 	ColumnAccessor < mCFStaticData_256 > mb_pre_tax_cash_flow_aig_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > mb_pre_tax_cash_flow_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > mb_pre_tax_cash_flow_aig_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > mb_pre_tax_cash_flow_aig_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > min_accum_val_b_aig;
 	ColumnAccessor < mCFStaticData_256 > min_accum_val_b_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > min_accum_val_e_aig;
 	ColumnAccessor < mCFStaticData_256 > min_accum_val_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > min_accum_val_e_bef_maturity_aig;
 	ColumnAccessor < mCFStaticData_256 > min_contract_val;
 	ColumnAccessor < mCFStaticData_256 > min_contract_val_bef;
 	ColumnAccessor < mCFStaticData_256 > min_wdl_val_alt_base_b_aig;
 	ColumnAccessor < mCFStaticData_256 > min_wdl_val_alt_base_e_aig;
 	ColumnAccessor < mCFStaticData_256 > min_wdl_val_alt_base_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > min_wdl_val_alt_base_e_bef_maturity_aig;
 	ColumnAccessor < mCFStaticData_256 > min_wdl_val_alt_e_aig;
 	ColumnAccessor < mCFStaticData_256 > min_wdl_val_alt_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > min_wdl_val_b_aig;
 	ColumnAccessor < mCFStaticData_256 > min_wdl_val_e_aig;
 	ColumnAccessor < mCFStaticData_256 > min_wdl_val_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > min_wdl_val_e_bef_maturity_aig;
 	ColumnAccessor < mCFStaticData_256 > min_wdl_val_final_e_aig;
 	ColumnAccessor < mCFStaticData_256 > min_wdl_val_final_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > min_wdl_val_final_e_bef_maturity_aig;
 	ColumnAccessor < mCFStaticData_256 > mths_since_issue;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_full_surr_cash_val_aig;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_full_surr_cash_val_aig_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_full_surr_cash_val_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_full_surr_cash_val_aig_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_full_surr_cash_val_aig_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_full_surr_cash_val_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_full_surr_cash_val_bef_aig_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_full_surr_cash_val_bef_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_full_surr_cash_val_bef_aig_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_full_surr_cash_val_bef_aig_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_full_surr_cash_val_bef_maturity_aig;
 	ColumnAccessor < mCFStaticData_256 > mva_amt_partial_wdl_aig;
 	ColumnAccessor < mCFStaticData_256 > mva_rate_full_surr_cash_val_aig;
 	ColumnAccessor < mCFStaticData_256 > mva_rate_full_surr_cash_val_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > mva_rate_full_surr_cash_val_bef_maturity_aig;
 	ColumnAccessor < mCFStaticData_256 > new_money_rate_aig;
 	ColumnAccessor < mCFStaticData_256 > notional_to_hedge;
 	ColumnAccessor < mCFStaticData_256 > notional_to_hedge_cap;
 	ColumnAccessor < mCFStaticData_256 > notional_to_hedge_index;
 	ColumnAccessor < mCFStaticData_256 > notional_to_hedge_long_strike;
 	ColumnAccessor < mCFStaticData_256 > notional_to_hedge_net;
 	ColumnAccessor < mCFStaticData_256 > opt_budget;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_amt;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_amt_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_amt_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_amt_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_amt_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_cost_index0_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_cost_index1_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_eprs_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_cost_atm_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_payoff;
 	ColumnAccessor < mCFStaticData_256 > opt_payoff_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_payoff_aig_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > opt_payoff_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_payoff_aig_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_payoff_aig_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_payoff_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > opt_payoff_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_payoff_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_payoff_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > pba_rollforward_base;
 	ColumnAccessor < mCFStaticData_256 > pba_rollforward_base_issued;
 	ColumnAccessor < mCFStaticData_256 > pba_rollforward_factor;
 	ColumnAccessor < mCFStaticData_256 > pfwd_entitlement;
 	ColumnAccessor < mCFStaticData_256 > pfwd_entitlement_remaining_e;
 	ColumnAccessor < mCFStaticData_256 > pfwd_entitlement_remaining_e_bef;
 	ColumnAccessor < mCFStaticData_256 > pfwd_rate_dynamic;
 	ColumnAccessor < mCFStaticData_256 > pfwd_rate_mthly_fund_val;
 	ColumnAccessor < mCFStaticData_256 > pfwd_rate_mthly_min_accum_val_aig;
 	ColumnAccessor < mCFStaticData_256 > pfwd_surr_contract_val;
 	ColumnAccessor < mCFStaticData_256 > pfwd_surr_cumul;
 	ColumnAccessor < mCFStaticData_256 > pfwd_surr_cumul_bom;
 	ColumnAccessor < mCFStaticData_256 > pfwd_surr_curr_pol_yr;
 	ColumnAccessor < mCFStaticData_256 > pfwd_surr_fund_val;
 	ColumnAccessor < mCFStaticData_256 > pfwd_use_aig;
 	ColumnAccessor < mCFStaticData_256 > pol_mth;
 	ColumnAccessor < mCFStaticData_256 > pol_yr;
 	ColumnAccessor < mCFStaticData_256 > policies_b;
 	ColumnAccessor < mCFStaticData_256 > policies_b_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > policies_b_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > policies_b_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > policies_b_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > policies_female_experience_aig;
 	ColumnAccessor < mCFStaticData_256 > policies_female_gmwb_aig;
 	ColumnAccessor < mCFStaticData_256 > policies_inf;
 	ColumnAccessor < mCFStaticData_256 > policies_issued;
 	ColumnAccessor < mCFStaticData_256 > policies_joint_experience_aig;
 	ColumnAccessor < mCFStaticData_256 > policies_joint_gmwb_aig;
 	ColumnAccessor < mCFStaticData_256 > policies_last_survivor_experience_aig;
 	ColumnAccessor < mCFStaticData_256 > policies_last_survivor_gmwb_aig;
 	ColumnAccessor < mCFStaticData_256 > policies_male_experience_aig;
 	ColumnAccessor < mCFStaticData_256 > policies_male_gmwb_aig;
 	ColumnAccessor < mCFStaticData_256 > port_yld_aft_tax;
 	ColumnAccessor < mCFStaticData_256 > pre_tax_cash_flow_liab_eom_aig;
 	ColumnAccessor < mCFStaticData_256 > pre_tax_cash_flow_liab_eom_aig_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > pre_tax_cash_flow_liab_eom_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > pre_tax_cash_flow_liab_eom_aig_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > pre_tax_cash_flow_liab_eom_aig_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > pre_tax_cash_flow_liab_weighted_eom_aig;
 	ColumnAccessor < mCFStaticData_256 > pre_tax_cash_flow_liab_weighted_eom_aig_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_256 > pre_tax_cash_flow_liab_weighted_eom_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > pre_tax_cash_flow_liab_weighted_eom_aig_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > pre_tax_cash_flow_liab_weighted_eom_aig_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_cumul_b_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_cumul_e_aig;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_cumul_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_recapture_base_b_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_recapture_base_e_aig;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_recapture_base_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_recapture_base_reduction_fct_aig;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_recapture_e_bef_aig;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus_recapture_inf_e_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_bonus_recapture_inf_e_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_bonus_recaptured_cumul_e_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_bonus_recaptured_cumul_e_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_cumul;
 	ColumnAccessor < mCFStaticData_512 > prem_cumul_bef;
 	ColumnAccessor < mCFStaticData_512 > prem_cumul_net_wdl_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_cumul_net_wdl_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_cumul_net_wdl_pre_income_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_cumul_net_wdl_pre_income_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_cumul_net_wdl_with_int_e_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_cumul_net_wdl_with_int_e_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_cumul_prop_wdl_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_cumul_prop_wdl_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_issued;
 	ColumnAccessor < mCFStaticData_512 > prem_paid;
 	ColumnAccessor < mCFStaticData_512 > prem_paid_net;
 	ColumnAccessor < mCFStaticData_512 > prem_paid_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_512 > prem_paid_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_paid_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_paid_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_512 > prem_tax;
 	ColumnAccessor < mCFStaticData_512 > proj_csv_for_interpolation_aig;
 	ColumnAccessor < mCFStaticData_512 > pv_benefit_itm_aig;
 	ColumnAccessor < mCFStaticData_512 > pv_bom_cf_disc_uel_crbg;
 	ColumnAccessor < mCFStaticData_512 > pv_cash_flow_liab_dur_aig;
 	ColumnAccessor < mCFStaticData_512 > pv_eom_cf_disc_uel_crbg;
 	ColumnAccessor < mCFStaticData_512 > pv_shifted_cash_flow_liab_dur_aig;
 	ColumnAccessor < mCFStaticData_512 > pv_total_cf_disc_uel_crbg;
 	ColumnAccessor < mCFStaticData_512 > rbc;
 	ColumnAccessor < mCFStaticData_512 > rbc_c1;
 	ColumnAccessor < mCFStaticData_512 > rbc_c2;
 	ColumnAccessor < mCFStaticData_512 > rbc_c2_nar;
 	ColumnAccessor < mCFStaticData_512 > rbc_c3;
 	ColumnAccessor < mCFStaticData_512 > rbc_c3_base_ann_high_risk;
 	ColumnAccessor < mCFStaticData_512 > rbc_c3_base_ann_low_risk;
 	ColumnAccessor < mCFStaticData_512 > rbc_c3_base_ann_medium_risk;
 	ColumnAccessor < mCFStaticData_512 > rbc_c3_mp;
 	ColumnAccessor < mCFStaticData_512 > rbc_c3_stoch_amt;
 	ColumnAccessor < mCFStaticData_512 > rbc_c3_stoch_amt_unhedged;
 	ColumnAccessor < mCFStaticData_512 > rbc_c3_unhedged;
 	ColumnAccessor < mCFStaticData_512 > rbc_c4;
 	ColumnAccessor < mCFStaticData_512 > reins_ann_benefits_eom;
 	ColumnAccessor < mCFStaticData_512 > reins_ann_claims_gmwb;
 	ColumnAccessor < mCFStaticData_512 > reins_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_512 > reins_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_512 > reins_cash_flow_int;
 	ColumnAccessor < mCFStaticData_512 > reins_cash_val;
 	ColumnAccessor < mCFStaticData_512 > reins_comm_chargeback_reimb;
 	ColumnAccessor < mCFStaticData_512 > reins_comm_reimb;
 	ColumnAccessor < mCFStaticData_512 > reins_comm_reimb_bom;
 	ColumnAccessor < mCFStaticData_512 > reins_comm_reimb_eom;
 	ColumnAccessor < mCFStaticData_512 > reins_dth_ben_inf;
 	ColumnAccessor < mCFStaticData_512 > reins_dth_benefits;
 	ColumnAccessor < mCFStaticData_512 > reins_exp;
 	ColumnAccessor < mCFStaticData_512 > reins_exp_reimb;
 	ColumnAccessor < mCFStaticData_512 > reins_exp_reimb_bom;
 	ColumnAccessor < mCFStaticData_512 > reins_exp_reimb_eom;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_ben_res;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_capzd_prem_bonus;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_cash_flow_int;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_chg_inc;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_comm_excess_eom;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_comm_trail_bom;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_comm_trail_eom;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_cost;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_credited_int;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_dac;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_dac_incr;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_inv_inc_res;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_liab_net;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_loads_deducted;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_prem_bonus;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_prem_tax;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_recoveries;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_sfas133_liab;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_sfas133_liab_incr;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_sop031_addl_liab;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_sop031_addl_liab_incr;
 	ColumnAccessor < mCFStaticData_512 > reins_gaap_surr_inc;
 	ColumnAccessor < mCFStaticData_512 > reins_inv_inc_res;
 	ColumnAccessor < mCFStaticData_512 > reins_maturity_benefits;
 	ColumnAccessor < mCFStaticData_512 > reins_prem;
 	ColumnAccessor < mCFStaticData_512 > reins_prem_base;
 	ColumnAccessor < mCFStaticData_512 > reins_prem_gmwb;
 	ColumnAccessor < mCFStaticData_512 > reins_prem_tax;
 	ColumnAccessor < mCFStaticData_512 > reins_stat_cost;
 	ColumnAccessor < mCFStaticData_512 > reins_stat_res;
 	ColumnAccessor < mCFStaticData_512 > reins_stat_res_incr;
 	ColumnAccessor < mCFStaticData_512 > reins_stat_res_mp;
 	ColumnAccessor < mCFStaticData_512 > reins_stat_res_npr;
 	ColumnAccessor < mCFStaticData_512 > reins_stat_res_unhedged;
 	ColumnAccessor < mCFStaticData_512 > reins_surr_benefits;
 	ColumnAccessor < mCFStaticData_512 > reins_tax_res;
 	ColumnAccessor < mCFStaticData_512 > reins_tax_res_incr;
 	ColumnAccessor < mCFStaticData_512 > reins_tax_res_mp;
 	ColumnAccessor < mCFStaticData_512 > reins_withdrl_benefits;
 	ColumnAccessor < mCFStaticData_512 > rila_interim_value_beg_term_aig;
 	ColumnAccessor < mCFStaticData_512 > rila_interim_value_dapv_e_aig;
 	ColumnAccessor < mCFStaticData_512 > rila_interim_value_e_aig;
 	ColumnAccessor < mCFStaticData_512 > rila_interim_value_e_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > rila_interim_value_fiapv_e_aig;
 	ColumnAccessor < mCFStaticData_512 > rila_interim_value_growth_aig;
 	ColumnAccessor < mCFStaticData_512 > rila_interim_value_tc_e_aig;
 	ColumnAccessor < mCFStaticData_512 > rila_strat_base_b_aig;
 	ColumnAccessor < mCFStaticData_512 > rila_strat_base_e_aig;
 	ColumnAccessor < mCFStaticData_512 > risk_free_rate_no_sprd_aig;
 	ColumnAccessor < mCFStaticData_512 > risk_free_rate_with_ic_uel_sprd_aig;
 	ColumnAccessor < mCFStaticData_512 > risk_free_rate_with_no_uel_sprd_aig;
 	ColumnAccessor < mCFStaticData_512 > risk_free_rate_with_uel_sprd_aig;
 	ColumnAccessor < mCFStaticData_512 > rop_chg_aig;
 	ColumnAccessor < mCFStaticData_512 > rop_chg_aig_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_512 > rop_chg_aig_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_512 > rop_chg_aig_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_512 > rop_chg_aig_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_512 > rop_chg_partial_bef_dth_aig;
 	ColumnAccessor < mCFStaticData_512 > rop_chg_partial_bef_surr_aig;
 	ColumnAccessor < mCFStaticData_512 > rop_chg_partial_e_aig;
 	ColumnAccessor < mCFStaticData_512 > seriatim_run_tgt;
 	ColumnAccessor < mCFStaticData_512 > sfc_annual_hedge_cost_col_aig;
 	ColumnAccessor < mCFStaticData_512 > sfc_ben_aig;
 	ColumnAccessor < mCFStaticData_512 > sfc_itm_aig;
 	ColumnAccessor < mCFStaticData_512 > shock_phase_lookup_aig_gen2;
 	ColumnAccessor < mCFStaticData_512 > snfl_prospective_e_aig;
 	ColumnAccessor < mCFStaticData_512 > snfl_prospective_e_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > startup;
 	ColumnAccessor < mCFStaticData_512 > stat_res;
 	ColumnAccessor < mCFStaticData_512 > stat_res_carvm;
 	ColumnAccessor < mCFStaticData_512 > stat_res_carvm_base_aig;
 	ColumnAccessor < mCFStaticData_512 > stat_res_carvm_base_full_wd_aig;
 	ColumnAccessor < mCFStaticData_512 > stat_res_carvm_base_no_wd_aig;
 	ColumnAccessor < mCFStaticData_512 > stat_res_carvm_net;
 	ColumnAccessor < mCFStaticData_512 > stat_res_carvm_wb_aig;
 	ColumnAccessor < mCFStaticData_512 > stat_res_excess;
 	ColumnAccessor < mCFStaticData_512 > stat_res_excess_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_incr;
 	ColumnAccessor < mCFStaticData_512 > stat_res_mp;
 	ColumnAccessor < mCFStaticData_512 > stat_res_mp_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_excess;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_excess_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_mp;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_mp_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_npr;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_npr_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_stoch_res;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_stoch_res_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_net_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_npr;
 	ColumnAccessor < mCFStaticData_512 > stat_res_npr_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_stoch_res;
 	ColumnAccessor < mCFStaticData_512 > stat_res_stoch_res_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_unhedged;
 	ColumnAccessor < mCFStaticData_512 > stat_res_xol_carvm_aig;
 	ColumnAccessor < mCFStaticData_512 > stat_res_xol_excess_res_aig;
 	ColumnAccessor < mCFStaticData_512 > stat_res_xol_nb_eco_res_aig;
 	ColumnAccessor < mCFStaticData_512 > stat_res_xol_pv_nb_ending_amount_aig;
 	ColumnAccessor < mCFStaticData_512 > strategy_return_aig;
 	ColumnAccessor < mCFStaticData_512 > surr_benefits;
 	ColumnAccessor < mCFStaticData_512 > surr_benefits_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_512 > surr_benefits_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_512 > surr_benefits_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_512 > surr_benefits_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_512 > surr_chg;
 	ColumnAccessor < mCFStaticData_512 > surr_chg_inf;
 	ColumnAccessor < mCFStaticData_512 > surr_chg_inf_bef;
 	ColumnAccessor < mCFStaticData_512 > surr_chg_inf_bef_maturity_aig;
 	ColumnAccessor < mCFStaticData_512 > surr_chg_inf_bef_no_gmwb_chg_aig;
 	ColumnAccessor < mCFStaticData_512 > surr_chg_inf_no_gmwb_chg_aig;
 	ColumnAccessor < mCFStaticData_512 > surv;
 	ColumnAccessor < mCFStaticData_512 > surv_period;
 	ColumnAccessor < mCFStaticData_512 > tax_bk_prof;
 	ColumnAccessor < mCFStaticData_512 > tax_bk_prof_ytd;
 	ColumnAccessor < mCFStaticData_512 > tax_capzd_prem;
 	ColumnAccessor < mCFStaticData_512 > tax_capzd_prem_amortzn;
 	ColumnAccessor < mCFStaticData_512 > tax_capzd_prem_unamortzd;
 	ColumnAccessor < mCFStaticData_512 > tax_earnings_accum;
 	ColumnAccessor < mCFStaticData_512 > tax_earnings_accum_ytd;
 	ColumnAccessor < mCFStaticData_512 > tax_res;
 	ColumnAccessor < mCFStaticData_512 > tax_res_carvm;
 	ColumnAccessor < mCFStaticData_512 > tax_res_carvm_net;
 	ColumnAccessor < mCFStaticData_512 > tax_res_incr;
 	ColumnAccessor < mCFStaticData_512 > tax_res_mp;
 	ColumnAccessor < mCFStaticData_512 > tax_tgt_cap;
 	ColumnAccessor < mCFStaticData_512 > tax_tgt_cap_ytd;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_bk_prof;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_bk_prof_ytd;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_carryfwd_addn_ytd;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_carryfwd_applied_ytd;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_carryfwd_avail;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_earnings_accum;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_earnings_accum_ytd;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_tgt_cap;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_tgt_cap_ytd;
 	ColumnAccessor < mCFStaticData_512 > ten_year_treasury_annualized_return_cumul_max_aig;
 	ColumnAccessor < mCFStaticData_512 > ten_year_treasury_annualized_return_three_mth_avg_aig;
 	ColumnAccessor < mCFStaticData_512 > tgt_cap;
 	ColumnAccessor < mCFStaticData_512 > tgt_cap_effect;
 	ColumnAccessor < mCFStaticData_512 > tgt_cap_incr;
 	ColumnAccessor < mCFStaticData_512 > tier_number_aig;
 	ColumnAccessor < mCFStaticData_512 > tier_strat_fee_aig;
 	ColumnAccessor < mCFStaticData_512 > tier_strat_fee_at_surr_aig;
 	ColumnAccessor < mCFStaticData_512 > tier_strat_fee_at_surr_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > undistrib_earnings;
 	ColumnAccessor < mCFStaticData_512 > uniform_rands_1_aig;
 	ColumnAccessor < mCFStaticData_512 > uniform_rands_2_aig;
 	ColumnAccessor < mCFStaticData_512 > uniform_rands_3_aig;
 	ColumnAccessor < mCFStaticData_512 > uniform_rands_4_aig;
 	ColumnAccessor < mCFStaticData_512 > uniform_rands_brownian_bridge_aig;
 	ColumnAccessor < mCFStaticData_512 > uniform_rands_non_us_return_aig;
 	ColumnAccessor < mCFStaticData_512 > uniform_rands_perf_lock_aig;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_deterministic_crbg;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_gaap_sfas133;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_gaap_sfas97rd;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_gaap_sop031;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_pba_scen_amt;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_stat_tax;
 	ColumnAccessor < mCFStaticData_512 > vm21_pv_claims_det_curr_crbg;
 	ColumnAccessor < mCFStaticData_512 > vm21_pv_claims_det_init_crbg;
 	ColumnAccessor < mCFStaticData_512 > vm21_pv_claims_deterministic_crbg;
 	ColumnAccessor < mCFStaticData_512 > weighted_ending_strategy_return_aig;
 	ColumnAccessor < mCFStaticData_512 > weighted_ending_strategy_return_gmwb_rollup_aig;
 	ColumnAccessor < mCFStaticData_512 > weighted_eprs_cost_aig;
 	ColumnAccessor < mCFStaticData_512 > weighted_prorated_strategy_return_aig;
 	ColumnAccessor < mCFStaticData_512 > weighted_strategy_return_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_chg_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_gross_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_gross_cumul_yr_e_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_gross_cumul_yr_e_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_gross_excess_cumul_e_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_gross_excess_cumul_e_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_gross_excess_e_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_gross_excess_ind_e_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_gross_excess_ind_e_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_gross_excess_int_credit_e_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_gross_regular_e_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_gross_regular_int_credit_e_bef_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_pv_cf_disc_rate_1;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_pv_cf_disc_rate_aig_curve_ic_uel_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_pv_cf_disc_rate_aig_curve_no_uel_aig;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits_pv_cf_disc_rate_aig_curve_uel_aig;
 	ColumnAccessor < mCFStaticData_512 > xol_amount_aig;
 	ColumnAccessor < mCFStaticData_512 > xol_prem_aig;
//Column Definition END@2

 // Temporary Table...
	MonTable* ptr_tt_tax_capzd_prem_amortzn_sched;
	TempTableAccessor tax_capzd_prem_amortzn_sched;

_1D_FIACARVM_LIAB sm_carvm_stat;
_1D_FIACARVM_LIAB sm_carvm_tax;
_1D_FIAAFUND_LIAB sm_fia_account;
_1D_ANN_PBA_PBA sm_fia_ann_pba;
AUTOMATION *sm_fia_automation;
BOND_PORTFOLIO_AIG *sm_fia_bond_portfolio_aig;
RATES_ECONOMY *sm_fia_rates;
_1D_SFAS133_GAAP sm_fia_sfas133;
_1D_SFAS97RD_GAAP sm_fia_sfas97rd;
FIA_LIAB *sm_bond_is;
FIA_LIAB *sm_bond_pv;
FIA_LIAB *sm_bond_ym;
FIA_LIAB *sm_mtg_is;
FIA_LIAB *sm_mtg_pv;
FIA_LIAB *sm_mtg_ym;
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
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > activate_index1_aig;
  inline xstring	Get_activate_index1_aig() {
		return activate_index1_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > addl_sc_shock_pfwd_use_nq_aig;
  inline double	Get_addl_sc_shock_pfwd_use_nq_aig() {
		return addl_sc_shock_pfwd_use_nq_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > addl_sc_shock_pfwd_use_q_aig;
  inline double	Get_addl_sc_shock_pfwd_use_q_aig() {
		return addl_sc_shock_pfwd_use_q_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > admin_fee_per_pol;
  inline double	Get_admin_fee_per_pol() {
		return admin_fee_per_pol; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > allowable_threshold_deviation_aig;
  inline double	Get_allowable_threshold_deviation_aig() {
		return allowable_threshold_deviation_aig; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > ann_ben_yr;
  inline int	Get_ann_ben_yr() {
		return ann_ben_yr; }
  inline void Set_ann_ben_yr(const int &v) {
		ann_ben_yr.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > ann_benefits_min_wdl_val_defn_aig;
  inline xstring	Get_ann_benefits_min_wdl_val_defn_aig() {
		return ann_benefits_min_wdl_val_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > ann_benefits_partial_interest_credited_defn_aig;
  inline xstring	Get_ann_benefits_partial_interest_credited_defn_aig() {
		return ann_benefits_partial_interest_credited_defn_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > ann_rate_table_aig;
  inline xstring	Get_ann_rate_table_aig() {
		return ann_rate_table_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > annualize_divisor_aig;
  inline double	Get_annualize_divisor_aig() {
		return annualize_divisor_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > annuitzn_base;
  inline double	Get_annuitzn_base() {
		return annuitzn_base; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_yld_comp_rate_id;
  inline xstring	Get_asset_yld_comp_rate_id() {
		return asset_yld_comp_rate_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_yld_defn;
  inline xstring	Get_asset_yld_defn() {
		return asset_yld_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > asset_yld_deterministic;
  inline double	Get_asset_yld_deterministic() {
		return asset_yld_deterministic; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > audit_rpt_defn;
  inline xstring	Get_audit_rpt_defn() {
		return audit_rpt_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > binary_strike_sprd_neg;
  inline double	Get_binary_strike_sprd_neg() {
		return binary_strike_sprd_neg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > binary_strike_sprd_pos;
  inline double	Get_binary_strike_sprd_pos() {
		return binary_strike_sprd_pos; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > broker_aig;
  inline xstring	Get_broker_aig() {
		return broker_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > broker_category_aig;
  inline xstring	Get_broker_category_aig() {
		return broker_category_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > bs_fwrd_vol_aig;
  inline double	Get_bs_fwrd_vol_aig() {
		return bs_fwrd_vol_aig; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > bs_init_vol_length;
  inline int	Get_bs_init_vol_length() {
		return bs_init_vol_length; }
  inline void Set_bs_init_vol_length(const int &v) {
		bs_init_vol_length.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > bs_init_vol_lookup;
  inline double	Get_bs_init_vol_lookup() {
		return bs_init_vol_lookup; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > bs_init_vol_strike;
  inline int	Get_bs_init_vol_strike() {
		return bs_init_vol_strike; }
  inline void Set_bs_init_vol_strike(const int &v) {
		bs_init_vol_strike.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > bs_init_vol_type;
  inline xstring	Get_bs_init_vol_type() {
		return bs_init_vol_type; }
  inline void Set_bs_init_vol_type(const xstring &v) {
		bs_init_vol_type.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > ca_mva_cv_floor_aig;
  inline xstring	Get_ca_mva_cv_floor_aig() {
		return ca_mva_cv_floor_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > calc_base_res_only_aig;
  inline xstring	Get_calc_base_res_only_aig() {
		return calc_base_res_only_aig; }
  inline void Set_calc_base_res_only_aig(const xstring &v) {
		calc_base_res_only_aig.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > calc_carvm_defn;
  inline xstring	Get_calc_carvm_defn() {
		return calc_carvm_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cap_rate_enh_par_cap;
  inline double	Get_cap_rate_enh_par_cap() {
		return cap_rate_enh_par_cap; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > capzd_acq_exp_pct_pct_prem;
  inline double	Get_capzd_acq_exp_pct_pct_prem() {
		return capzd_acq_exp_pct_pct_prem; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > capzd_acq_exp_pct_per_pol;
  inline double	Get_capzd_acq_exp_pct_per_pol() {
		return capzd_acq_exp_pct_per_pol; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > capzd_prem_bonus_pct;
  inline double	Get_capzd_prem_bonus_pct() {
		return capzd_prem_bonus_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > carvm_res_floor_pct_aig;
  inline double	Get_carvm_res_floor_pct_aig() {
		return carvm_res_floor_pct_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > carvm_res_floor_switch_aig;
  inline xstring	Get_carvm_res_floor_switch_aig() {
		return carvm_res_floor_switch_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > carvm_stat_detail_rpt_defn;
  inline xstring	Get_carvm_stat_detail_rpt_defn() {
		return carvm_stat_detail_rpt_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > carvm_tax_detail_rpt_defn;
  inline xstring	Get_carvm_tax_detail_rpt_defn() {
		return carvm_tax_detail_rpt_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > cash_flow_pct_input_vector_aig;
  inline double	Get_cash_flow_pct_input_vector_aig() {
		return cash_flow_pct_input_vector_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > cash_surrender_value_defn_aig;
  inline xstring	Get_cash_surrender_value_defn_aig() {
		return cash_surrender_value_defn_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > combo_strat_renew_status;
  inline double	Get_combo_strat_renew_status() {
		return combo_strat_renew_status; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comm_chargeback_pct_aig;
  inline double	Get_comm_chargeback_pct_aig() {
		return comm_chargeback_pct_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > comm_chargeback_period_mths_aig;
  inline int	Get_comm_chargeback_period_mths_aig() {
		return comm_chargeback_period_mths_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comm_fund_payment_freq_aig;
  inline double	Get_comm_fund_payment_freq_aig() {
		return comm_fund_payment_freq_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comm_pct_fund;
  inline double	Get_comm_pct_fund() {
		return comm_pct_fund; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > comm_pct_prem;
  inline double	Get_comm_pct_prem() {
		return comm_pct_prem; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > comm_trail_table_aig;
  inline xstring	Get_comm_trail_table_aig() {
		return comm_trail_table_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > comm_upfront_table_aig;
  inline xstring	Get_comm_upfront_table_aig() {
		return comm_upfront_table_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > commission_set_aig;
  inline xstring	Get_commission_set_aig() {
		return commission_set_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > comp_lookup_aig;
  inline xstring	Get_comp_lookup_aig() {
		return comp_lookup_aig; }
  inline void Set_comp_lookup_aig(const xstring &v) {
		comp_lookup_aig.setValue(v); }
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > competitor_rate_govt_tenor_aig;
  inline double	Get_competitor_rate_govt_tenor_aig() {
		return competitor_rate_govt_tenor_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > confinement_assumption_set_aig;
  inline xstring	Get_confinement_assumption_set_aig() {
		return confinement_assumption_set_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > confinement_set_aig;
  inline xstring	Get_confinement_set_aig() {
		return confinement_set_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > contract_val_net_consideration_pct;
  inline double	Get_contract_val_net_consideration_pct() {
		return contract_val_net_consideration_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > contract_val_sc_defn;
  inline xstring	Get_contract_val_sc_defn() {
		return contract_val_sc_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > coupon_freq_defn_aig;
  inline xstring	Get_coupon_freq_defn_aig() {
		return coupon_freq_defn_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > covered_person_status_aig;
  inline xstring	Get_covered_person_status_aig() {
		return covered_person_status_aig; }
  inline void Set_covered_person_status_aig(const xstring &v) {
		covered_person_status_aig.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_asset_yld_sprd;
  inline double	Get_crediting_asset_yld_sprd() {
		return crediting_asset_yld_sprd; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > crediting_eqt_index_aig;
  inline xstring	Get_crediting_eqt_index_aig() {
		return crediting_eqt_index_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > crediting_fixed_defn_aig;
  inline xstring	Get_crediting_fixed_defn_aig() {
		return crediting_fixed_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > crediting_nb_defn;
  inline xstring	Get_crediting_nb_defn() {
		return crediting_nb_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > crediting_nb_rate_id_aig;
  inline xstring	Get_crediting_nb_rate_id_aig() {
		return crediting_nb_rate_id_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_nb_yld_maturity;
  inline double	Get_crediting_nb_yld_maturity() {
		return crediting_nb_yld_maturity; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > crediting_nb_yld_rating;
  inline xstring	Get_crediting_nb_yld_rating() {
		return crediting_nb_yld_rating; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_ner_aig;
  inline double	Get_crediting_ner_aig() {
		return crediting_ner_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > crediting_ner_set_aig;
  inline xstring	Get_crediting_ner_set_aig() {
		return crediting_ner_set_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_pri_sprd_tgt_aig;
  inline double	Get_crediting_pri_sprd_tgt_aig() {
		return crediting_pri_sprd_tgt_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_pri_sprd_tgt_idx1_aig;
  inline double	Get_crediting_pri_sprd_tgt_idx1_aig() {
		return crediting_pri_sprd_tgt_idx1_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_rate_fixed;
  inline double	Get_crediting_rate_fixed() {
		return crediting_rate_fixed; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_rate_gtd;
  inline double	Get_crediting_rate_gtd() {
		return crediting_rate_gtd; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > crediting_rate_guar_mths_fixed;
  inline int	Get_crediting_rate_guar_mths_fixed() {
		return crediting_rate_guar_mths_fixed; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > crediting_rate_guar_mths_idx1_aig;
  inline int	Get_crediting_rate_guar_mths_idx1_aig() {
		return crediting_rate_guar_mths_idx1_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > crediting_rate_guar_mths_index0;
  inline int	Get_crediting_rate_guar_mths_index0() {
		return crediting_rate_guar_mths_index0; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > crediting_rate_guar_mths_index2;
  inline int	Get_crediting_rate_guar_mths_index2() {
		return crediting_rate_guar_mths_index2; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > crediting_rate_guar_mths_index3;
  inline int	Get_crediting_rate_guar_mths_index3() {
		return crediting_rate_guar_mths_index3; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > crediting_rate_guar_mths_index4;
  inline int	Get_crediting_rate_guar_mths_index4() {
		return crediting_rate_guar_mths_index4; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > crediting_rate_min;
  inline double	Get_crediting_rate_min() {
		return crediting_rate_min; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > crediting_rate_min_table_aig;
  inline xstring	Get_crediting_rate_min_table_aig() {
		return crediting_rate_min_table_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > crediting_rate_partial_sprd_defn_aig;
  inline xstring	Get_crediting_rate_partial_sprd_defn_aig() {
		return crediting_rate_partial_sprd_defn_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > crediting_rate_type_aig;
  inline xstring	Get_crediting_rate_type_aig() {
		return crediting_rate_type_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > crediting_type_aig;
  inline xstring	Get_crediting_type_aig() {
		return crediting_type_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > crediting_type_dyn_2nd_strat_aig;
  inline xstring	Get_crediting_type_dyn_2nd_strat_aig() {
		return crediting_type_dyn_2nd_strat_aig; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > crediting_type_dyn_aig;
  inline xstring	Get_crediting_type_dyn_aig() {
		return crediting_type_dyn_aig; }
  inline void Set_crediting_type_dyn_aig(const xstring &v) {
		crediting_type_dyn_aig.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > crediting_type_dyn_defn_aig;
  inline xstring	Get_crediting_type_dyn_defn_aig() {
		return crediting_type_dyn_defn_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > crediting_type_dyn_pmt_threshold_aig;
  inline int	Get_crediting_type_dyn_pmt_threshold_aig() {
		return crediting_type_dyn_pmt_threshold_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > cubic_spline_enhancement_dev_team_switch_aig;
  inline xstring	Get_cubic_spline_enhancement_dev_team_switch_aig() {
		return cubic_spline_enhancement_dev_team_switch_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > data_validation_defn;
  inline xstring	Get_data_validation_defn() {
		return data_validation_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > decrement_set_aig;
  inline xstring	Get_decrement_set_aig() {
		return decrement_set_aig; }
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > disc_rate_sprd_ic_uel_aig;
  inline double	Get_disc_rate_sprd_ic_uel_aig() {
		return disc_rate_sprd_ic_uel_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > disc_rate_sprd_no_uel_aig;
  inline double	Get_disc_rate_sprd_no_uel_aig() {
		return disc_rate_sprd_no_uel_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > disc_rate_sprd_uel_aig;
  inline double	Get_disc_rate_sprd_uel_aig() {
		return disc_rate_sprd_uel_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > disc_rates_selected;
  inline xstring	Get_disc_rates_selected() {
		return disc_rates_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > dividend_inner_aig;
  inline double	Get_dividend_inner_aig() {
		return dividend_inner_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > dth_ben_cap_aig;
  inline double	Get_dth_ben_cap_aig() {
		return dth_ben_cap_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > dth_ben_defn;
  inline xstring	Get_dth_ben_defn() {
		return dth_ben_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > dth_ben_partial_interest_credited_defn_aig;
  inline xstring	Get_dth_ben_partial_interest_credited_defn_aig() {
		return dth_ben_partial_interest_credited_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > dth_ben_primary_tail_defn_aig;
  inline xstring	Get_dth_ben_primary_tail_defn_aig() {
		return dth_ben_primary_tail_defn_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > dth_ben_rop_chg_freq;
  inline xstring	Get_dth_ben_rop_chg_freq() {
		return dth_ben_rop_chg_freq; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > dth_ben_rop_chg_mult;
  inline double	Get_dth_ben_rop_chg_mult() {
		return dth_ben_rop_chg_mult; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > dth_ben_rop_ind_aig;
  inline int	Get_dth_ben_rop_ind_aig() {
		return dth_ben_rop_ind_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > dyn_lapse_table_aig;
  inline xstring	Get_dyn_lapse_table_aig() {
		return dyn_lapse_table_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > enhanced_income_benefit_exercise_aig;
  inline xstring	Get_enhanced_income_benefit_exercise_aig() {
		return enhanced_income_benefit_exercise_aig; }
  inline void Set_enhanced_income_benefit_exercise_aig(const xstring &v) {
		enhanced_income_benefit_exercise_aig.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > enhanced_income_benefit_utilization_pct_aig;
  inline double	Get_enhanced_income_benefit_utilization_pct_aig() {
		return enhanced_income_benefit_utilization_pct_aig; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > enhanced_income_confinement_age_aig;
  inline int	Get_enhanced_income_confinement_age_aig() {
		return enhanced_income_confinement_age_aig; }
  inline void Set_enhanced_income_confinement_age_aig(const int &v) {
		enhanced_income_confinement_age_aig.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > enhanced_income_confinement_mth_aig;
  inline int	Get_enhanced_income_confinement_mth_aig() {
		return enhanced_income_confinement_mth_aig; }
  inline void Set_enhanced_income_confinement_mth_aig(const int &v) {
		enhanced_income_confinement_mth_aig.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > enhanced_income_confinement_state_aig;
  inline xstring	Get_enhanced_income_confinement_state_aig() {
		return enhanced_income_confinement_state_aig; }
  inline void Set_enhanced_income_confinement_state_aig(const xstring &v) {
		enhanced_income_confinement_state_aig.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > enhanced_income_confinement_yr_aig;
  inline int	Get_enhanced_income_confinement_yr_aig() {
		return enhanced_income_confinement_yr_aig; }
  inline void Set_enhanced_income_confinement_yr_aig(const int &v) {
		enhanced_income_confinement_yr_aig.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > enhanced_income_defn_aig;
  inline xstring	Get_enhanced_income_defn_aig() {
		return enhanced_income_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > enhanced_income_gmwb_exercise_defn_aig;
  inline xstring	Get_enhanced_income_gmwb_exercise_defn_aig() {
		return enhanced_income_gmwb_exercise_defn_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > enhanced_income_incidence_base_aig;
  inline double	Get_enhanced_income_incidence_base_aig() {
		return enhanced_income_incidence_base_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > enhanced_income_incidence_gender_aig;
  inline xstring	Get_enhanced_income_incidence_gender_aig() {
		return enhanced_income_incidence_gender_aig; }
  inline void Set_enhanced_income_incidence_gender_aig(const xstring &v) {
		enhanced_income_incidence_gender_aig.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > enhanced_income_incidence_issue_age_aig;
  inline int	Get_enhanced_income_incidence_issue_age_aig() {
		return enhanced_income_incidence_issue_age_aig; }
  inline void Set_enhanced_income_incidence_issue_age_aig(const int &v) {
		enhanced_income_incidence_issue_age_aig.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > enhanced_income_mawp_mult_aig;
  inline double	Get_enhanced_income_mawp_mult_aig() {
		return enhanced_income_mawp_mult_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > enhanced_income_max_cumul_benefit_yrs_aig;
  inline int	Get_enhanced_income_max_cumul_benefit_yrs_aig() {
		return enhanced_income_max_cumul_benefit_yrs_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > enhanced_income_mort_base_confined_aig;
  inline double	Get_enhanced_income_mort_base_confined_aig() {
		return enhanced_income_mort_base_confined_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > enhanced_income_mort_base_non_confined_aig;
  inline double	Get_enhanced_income_mort_base_non_confined_aig() {
		return enhanced_income_mort_base_non_confined_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > enhanced_income_mort_mult_confined_aig;
  inline double	Get_enhanced_income_mort_mult_confined_aig() {
		return enhanced_income_mort_mult_confined_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > enhanced_income_recovery_base_aig;
  inline double	Get_enhanced_income_recovery_base_aig() {
		return enhanced_income_recovery_base_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > enhanced_income_recovery_gender_aig;
  inline xstring	Get_enhanced_income_recovery_gender_aig() {
		return enhanced_income_recovery_gender_aig; }
  inline void Set_enhanced_income_recovery_gender_aig(const xstring &v) {
		enhanced_income_recovery_gender_aig.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > enhanced_income_recovery_mult_aig;
  inline double	Get_enhanced_income_recovery_mult_aig() {
		return enhanced_income_recovery_mult_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > enhanced_income_wait_period_aig;
  inline int	Get_enhanced_income_wait_period_aig() {
		return enhanced_income_wait_period_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > eprs_sfc_aig;
  inline xstring	Get_eprs_sfc_aig() {
		return eprs_sfc_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > excess_wdl_set_aig;
  inline xstring	Get_excess_wdl_set_aig() {
		return excess_wdl_set_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > exp_adj_mult;
  inline double	Get_exp_adj_mult() {
		return exp_adj_mult; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > expense_set_aig;
  inline xstring	Get_expense_set_aig() {
		return expense_set_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > force_initial_cover_ownership_gender_same_aig;
  inline xstring	Get_force_initial_cover_ownership_gender_same_aig() {
		return force_initial_cover_ownership_gender_same_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > fund_val_defn_aig;
  inline xstring	Get_fund_val_defn_aig() {
		return fund_val_defn_aig; }
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
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gen2_defn;
  inline xstring	Get_gen2_defn() {
		return gen2_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gender_aft_act_aig;
  inline xstring	Get_gender_aft_act_aig() {
		return gender_aft_act_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > gender_mp;
  inline xstring	Get_gender_mp() {
		return gender_mp; }
  inline void Set_gender_mp(const xstring &v) {
		gender_mp.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gender_mp_aig;
  inline xstring	Get_gender_mp_aig() {
		return gender_mp_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > glb_flex_cost_set_aig;
  inline xstring	Get_glb_flex_cost_set_aig() {
		return glb_flex_cost_set_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > glb_itm_disc_rate;
  inline double	Get_glb_itm_disc_rate() {
		return glb_itm_disc_rate; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmdb_lapse_mult_floor_aig;
  inline double	Get_gmdb_lapse_mult_floor_aig() {
		return gmdb_lapse_mult_floor_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmdb_lapse_mult_slope_aig;
  inline double	Get_gmdb_lapse_mult_slope_aig() {
		return gmdb_lapse_mult_slope_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_base_mav_aig;
  inline xstring	Get_gmwb_base_mav_aig() {
		return gmwb_base_mav_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_chg_at_surr_timing_defn_aig;
  inline xstring	Get_gmwb_chg_at_surr_timing_defn_aig() {
		return gmwb_chg_at_surr_timing_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_chg_at_surr_yn_aig;
  inline xstring	Get_gmwb_chg_at_surr_yn_aig() {
		return gmwb_chg_at_surr_yn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_chg_base;
  inline xstring	Get_gmwb_chg_base() {
		return gmwb_chg_base; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_chg_freq_aig;
  inline xstring	Get_gmwb_chg_freq_aig() {
		return gmwb_chg_freq_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_chg_pct;
  inline double	Get_gmwb_chg_pct() {
		return gmwb_chg_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_claim_disc_rate;
  inline double	Get_gmwb_claim_disc_rate() {
		return gmwb_claim_disc_rate; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_claim_disc_rate_defn;
  inline xstring	Get_gmwb_claim_disc_rate_defn() {
		return gmwb_claim_disc_rate_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_claim_print_debug_output_defn_aig;
  inline xstring	Get_gmwb_claim_print_debug_output_defn_aig() {
		return gmwb_claim_print_debug_output_defn_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmwb_cohort_id;
  inline int	Get_gmwb_cohort_id() {
		return gmwb_cohort_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_cohort_utilz_defn;
  inline xstring	Get_gmwb_cohort_utilz_defn() {
		return gmwb_cohort_utilz_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_cohort_utilz_rate;
  inline double	Get_gmwb_cohort_utilz_rate() {
		return gmwb_cohort_utilz_rate; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_credit_mult_aig;
  inline double	Get_gmwb_credit_mult_aig() {
		return gmwb_credit_mult_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_defn;
  inline xstring	Get_gmwb_defn() {
		return gmwb_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmwb_doubling_year_aig;
  inline int	Get_gmwb_doubling_year_aig() {
		return gmwb_doubling_year_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_exercise_yrs;
  inline double	Get_gmwb_exercise_yrs() {
		return gmwb_exercise_yrs; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_flex_base_lapse_multiplier_aig;
  inline double	Get_gmwb_flex_base_lapse_multiplier_aig() {
		return gmwb_flex_base_lapse_multiplier_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_flex_defn_aig;
  inline xstring	Get_gmwb_flex_defn_aig() {
		return gmwb_flex_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_fund_val_defn;
  inline xstring	Get_gmwb_fund_val_defn() {
		return gmwb_fund_val_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_fund_val_period;
  inline double	Get_gmwb_fund_val_period() {
		return gmwb_fund_val_period; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > gmwb_generation_aig;
  inline xstring	Get_gmwb_generation_aig() {
		return gmwb_generation_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > gmwb_generation_set_aig;
  inline xstring	Get_gmwb_generation_set_aig() {
		return gmwb_generation_set_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_income_base_cap_defn_aig;
  inline xstring	Get_gmwb_income_base_cap_defn_aig() {
		return gmwb_income_base_cap_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_income_base_cap_prem_base_reduction_method_aig;
  inline xstring	Get_gmwb_income_base_cap_prem_base_reduction_method_aig() {
		return gmwb_income_base_cap_prem_base_reduction_method_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_income_base_cap_prem_pct_aig;
  inline double	Get_gmwb_income_base_cap_prem_pct_aig() {
		return gmwb_income_base_cap_prem_pct_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_income_base_defn;
  inline xstring	Get_gmwb_income_base_defn() {
		return gmwb_income_base_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_income_base_floor_prem_pct_aig;
  inline double	Get_gmwb_income_base_floor_prem_pct_aig() {
		return gmwb_income_base_floor_prem_pct_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_income_fund_val_base_reduction_method_aig;
  inline xstring	Get_gmwb_income_fund_val_base_reduction_method_aig() {
		return gmwb_income_fund_val_base_reduction_method_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_income_prem_base_reduction_method_aig;
  inline xstring	Get_gmwb_income_prem_base_reduction_method_aig() {
		return gmwb_income_prem_base_reduction_method_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_income_rollup_cap_base_reduction_method_aig;
  inline xstring	Get_gmwb_income_rollup_cap_base_reduction_method_aig() {
		return gmwb_income_rollup_cap_base_reduction_method_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmwb_ind;
  inline int	Get_gmwb_ind() {
		return gmwb_ind; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_mawp_pipp_split_aig;
  inline xstring	Get_gmwb_mawp_pipp_split_aig() {
		return gmwb_mawp_pipp_split_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmwb_max_age;
  inline int	Get_gmwb_max_age() {
		return gmwb_max_age; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_max_annual_wdl_addn_pct_aig;
  inline double	Get_gmwb_max_annual_wdl_addn_pct_aig() {
		return gmwb_max_annual_wdl_addn_pct_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_max_annual_wdl_pct;
  inline double	Get_gmwb_max_annual_wdl_pct() {
		return gmwb_max_annual_wdl_pct; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > gmwb_max_annual_wdl_pol_yr_aig;
  inline int	Get_gmwb_max_annual_wdl_pol_yr_aig() {
		return gmwb_max_annual_wdl_pol_yr_aig; }
  inline void Set_gmwb_max_annual_wdl_pol_yr_aig(const int &v) {
		gmwb_max_annual_wdl_pol_yr_aig.setValue(v); }
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
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > gmwb_mib_rollup_phase_lookup_aig;
  inline xstring	Get_gmwb_mib_rollup_phase_lookup_aig() {
		return gmwb_mib_rollup_phase_lookup_aig; }
  inline void Set_gmwb_mib_rollup_phase_lookup_aig(const xstring &v) {
		gmwb_mib_rollup_phase_lookup_aig.setValue(v); }
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
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_net_credit_aig;
  inline xstring	Get_gmwb_net_credit_aig() {
		return gmwb_net_credit_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_option_aig;
  inline xstring	Get_gmwb_option_aig() {
		return gmwb_option_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_pfwd_dyn_defn;
  inline xstring	Get_gmwb_pfwd_dyn_defn() {
		return gmwb_pfwd_dyn_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_pfwd_dyn_mult;
  inline double	Get_gmwb_pfwd_dyn_mult() {
		return gmwb_pfwd_dyn_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_pipp_pct_aig;
  inline double	Get_gmwb_pipp_pct_aig() {
		return gmwb_pipp_pct_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmwb_pipp_stepup_age_aig;
  inline int	Get_gmwb_pipp_stepup_age_aig() {
		return gmwb_pipp_stepup_age_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_pipp_stepup_pct_aig;
  inline double	Get_gmwb_pipp_stepup_pct_aig() {
		return gmwb_pipp_stepup_pct_aig; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > gmwb_pipp_stepup_period_aig;
  inline double	Get_gmwb_pipp_stepup_period_aig() {
		return gmwb_pipp_stepup_period_aig; }
  inline void Set_gmwb_pipp_stepup_period_aig(const double &v) {
		gmwb_pipp_stepup_period_aig.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_prem_credit_aig;
  inline double	Get_gmwb_prem_credit_aig() {
		return gmwb_prem_credit_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_prem_credit_pct_defn_aig;
  inline xstring	Get_gmwb_prem_credit_pct_defn_aig() {
		return gmwb_prem_credit_pct_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_prem_defn;
  inline xstring	Get_gmwb_prem_defn() {
		return gmwb_prem_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_prem_rollup_credit_type_aig;
  inline xstring	Get_gmwb_prem_rollup_credit_type_aig() {
		return gmwb_prem_rollup_credit_type_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmwb_prem_rollup_performance_based_aig;
  inline int	Get_gmwb_prem_rollup_performance_based_aig() {
		return gmwb_prem_rollup_performance_based_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_rollup_cap;
  inline double	Get_gmwb_rollup_cap() {
		return gmwb_rollup_cap; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_rollup_rate;
  inline double	Get_gmwb_rollup_rate() {
		return gmwb_rollup_rate; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_rollup_rate_type;
  inline xstring	Get_gmwb_rollup_rate_type() {
		return gmwb_rollup_rate_type; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_rollup_rate_type_aig;
  inline xstring	Get_gmwb_rollup_rate_type_aig() {
		return gmwb_rollup_rate_type_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_sfas133_req_prof_chg;
  inline double	Get_gmwb_sfas133_req_prof_chg() {
		return gmwb_sfas133_req_prof_chg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_step_up_rate;
  inline double	Get_gmwb_step_up_rate() {
		return gmwb_step_up_rate; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_type_aig;
  inline xstring	Get_gmwb_type_aig() {
		return gmwb_type_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_wait_period;
  inline double	Get_gmwb_wait_period() {
		return gmwb_wait_period; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_wdl_fixed_utilization_rate_aig;
  inline double	Get_gmwb_wdl_fixed_utilization_rate_aig() {
		return gmwb_wdl_fixed_utilization_rate_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_wdl_pct_tbl_style_aig;
  inline xstring	Get_gmwb_wdl_pct_tbl_style_aig() {
		return gmwb_wdl_pct_tbl_style_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_wdl_random_utilization_rate_aig;
  inline double	Get_gmwb_wdl_random_utilization_rate_aig() {
		return gmwb_wdl_random_utilization_rate_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_wdl_utilization_calc_defn_aig;
  inline xstring	Get_gmwb_wdl_utilization_calc_defn_aig() {
		return gmwb_wdl_utilization_calc_defn_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_wdl_utilization_init_population_aig;
  inline double	Get_gmwb_wdl_utilization_init_population_aig() {
		return gmwb_wdl_utilization_init_population_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > gmwb_wdl_utilization_level_aig;
  inline xstring	Get_gmwb_wdl_utilization_level_aig() {
		return gmwb_wdl_utilization_level_aig; }
  inline void Set_gmwb_wdl_utilization_level_aig(const xstring &v) {
		gmwb_wdl_utilization_level_aig.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_wdl_utilization_primary_transition_prob_aig;
  inline double	Get_gmwb_wdl_utilization_primary_transition_prob_aig() {
		return gmwb_wdl_utilization_primary_transition_prob_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_wdl_utilization_random_number_src_aig;
  inline xstring	Get_gmwb_wdl_utilization_random_number_src_aig() {
		return gmwb_wdl_utilization_random_number_src_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_wdl_utilization_secondary_transition_prob_aig;
  inline double	Get_gmwb_wdl_utilization_secondary_transition_prob_aig() {
		return gmwb_wdl_utilization_secondary_transition_prob_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > gmwb_wdl_utilization_tgt_level_aig;
  inline xstring	Get_gmwb_wdl_utilization_tgt_level_aig() {
		return gmwb_wdl_utilization_tgt_level_aig; }
  inline void Set_gmwb_wdl_utilization_tgt_level_aig(const xstring &v) {
		gmwb_wdl_utilization_tgt_level_aig.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_wdl_utilization_transition_matrix_threshold_aig;
  inline double	Get_gmwb_wdl_utilization_transition_matrix_threshold_aig() {
		return gmwb_wdl_utilization_transition_matrix_threshold_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_wdl_utilization_transition_prob_tbl_aig;
  inline xstring	Get_gmwb_wdl_utilization_transition_prob_tbl_aig() {
		return gmwb_wdl_utilization_transition_prob_tbl_aig; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > gmwb_withdrl_age;
  inline int	Get_gmwb_withdrl_age() {
		return gmwb_withdrl_age; }
  inline void Set_gmwb_withdrl_age(const int &v) {
		gmwb_withdrl_age.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_withdrl_rate_indexing_assessment_chg_addn_aig;
  inline double	Get_gmwb_withdrl_rate_indexing_assessment_chg_addn_aig() {
		return gmwb_withdrl_rate_indexing_assessment_chg_addn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_withdrl_rate_indexing_assessment_defn_aig;
  inline xstring	Get_gmwb_withdrl_rate_indexing_assessment_defn_aig() {
		return gmwb_withdrl_rate_indexing_assessment_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_withdrl_rate_indexing_assessment_ind_aig;
  inline xstring	Get_gmwb_withdrl_rate_indexing_assessment_ind_aig() {
		return gmwb_withdrl_rate_indexing_assessment_ind_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_withdrl_rate_indexing_cap_rate_aig;
  inline double	Get_gmwb_withdrl_rate_indexing_cap_rate_aig() {
		return gmwb_withdrl_rate_indexing_cap_rate_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gmwb_withdrl_rate_indexing_defn_aig;
  inline xstring	Get_gmwb_withdrl_rate_indexing_defn_aig() {
		return gmwb_withdrl_rate_indexing_defn_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gmwb_withdrl_rate_indexing_part_rate_aig;
  inline double	Get_gmwb_withdrl_rate_indexing_part_rate_aig() {
		return gmwb_withdrl_rate_indexing_part_rate_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > grop_ind_aig;
  inline int	Get_grop_ind_aig() {
		return grop_ind_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gsia_reins_defn_aig;
  inline xstring	Get_gsia_reins_defn_aig() {
		return gsia_reins_defn_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gwl_acq_exp_allow_level_aig;
  inline double	Get_gwl_acq_exp_allow_level_aig() {
		return gwl_acq_exp_allow_level_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gwl_ceding_exp_allow_level_aig;
  inline double	Get_gwl_ceding_exp_allow_level_aig() {
		return gwl_ceding_exp_allow_level_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gwl_maint_exp_allow_level_aig;
  inline double	Get_gwl_maint_exp_allow_level_aig() {
		return gwl_maint_exp_allow_level_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > hiloband_aig;
  inline xstring	Get_hiloband_aig() {
		return hiloband_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > host_accrual_rate;
  inline double	Get_host_accrual_rate() {
		return host_accrual_rate; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > income_phase_lookup_aig;
  inline xstring	Get_income_phase_lookup_aig() {
		return income_phase_lookup_aig; }
  inline void Set_income_phase_lookup_aig(const xstring &v) {
		income_phase_lookup_aig.setValue(v); }
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
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > independent_mp_defn;
  inline xstring	Get_independent_mp_defn() {
		return independent_mp_defn; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > index_id_lookup;
  inline xstring	Get_index_id_lookup() {
		return index_id_lookup; }
  inline void Set_index_id_lookup(const xstring &v) {
		index_id_lookup.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_term_beg_index_val;
  inline double	Get_index_term_beg_index_val() {
		return index_term_beg_index_val; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_term_buffer_aig;
  inline double	Get_index_term_buffer_aig() {
		return index_term_buffer_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > infl_deduction_aig;
  inline double	Get_infl_deduction_aig() {
		return infl_deduction_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > infl_mult_aig;
  inline double	Get_infl_mult_aig() {
		return infl_mult_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > infl_rate_const_aig;
  inline double	Get_infl_rate_const_aig() {
		return infl_rate_const_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > infl_rate_defn_aig;
  inline xstring	Get_infl_rate_defn_aig() {
		return infl_rate_defn_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > infl_rate_table_aig;
  inline xstring	Get_infl_rate_table_aig() {
		return infl_rate_table_aig; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > infl_start_date;
  inline xstring	Get_infl_start_date() {
		return infl_start_date; }
  inline void Set_infl_start_date(const xstring &v) {
		infl_start_date.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > infl_start_date_defn_aig;
  inline xstring	Get_infl_start_date_defn_aig() {
		return infl_start_date_defn_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > infl_start_date_input_aig;
  inline xstring	Get_infl_start_date_input_aig() {
		return infl_start_date_input_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > infl_treasury_yr_aig;
  inline double	Get_infl_treasury_yr_aig() {
		return infl_treasury_yr_aig; }
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_cash_val_aig;
  inline double	Get_init_cash_val_aig() {
		return init_cash_val_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_cash_val_no_mva_aig;
  inline double	Get_init_cash_val_no_mva_aig() {
		return init_cash_val_no_mva_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_comm_subject_to_chargeback;
  inline double	Get_init_comm_subject_to_chargeback() {
		return init_comm_subject_to_chargeback; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_contract_val;
  inline double	Get_init_contract_val() {
		return init_contract_val; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_crediting_rate_fixed_aig;
  inline double	Get_init_crediting_rate_fixed_aig() {
		return init_crediting_rate_fixed_aig; }
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_gmwb_fund_val;
  inline double	Get_init_gmwb_fund_val() {
		return init_gmwb_fund_val; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_gmwb_max_wdl_amt;
  inline double	Get_init_gmwb_max_wdl_amt() {
		return init_gmwb_max_wdl_amt; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_gmwb_prem;
  inline double	Get_init_gmwb_prem() {
		return init_gmwb_prem; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_hedge_amt;
  inline double	Get_init_hedge_amt() {
		return init_hedge_amt; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_hedge_budget;
  inline double	Get_init_hedge_budget() {
		return init_hedge_budget; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_hedge_opt_cost;
  inline double	Get_init_hedge_opt_cost() {
		return init_hedge_opt_cost; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_host_val;
  inline double	Get_init_host_val() {
		return init_host_val; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_interim_value;
  inline double	Get_init_interim_value() {
		return init_interim_value; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_opt_cost_aig;
  inline double	Get_init_opt_cost_aig() {
		return init_opt_cost_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > init_opt_cost_calc;
  inline xstring	Get_init_opt_cost_calc() {
		return init_opt_cost_calc; }
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_perf_lock_hwm;
  inline double	Get_init_perf_lock_hwm() {
		return init_perf_lock_hwm; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_pfwd_curr_pol_yr;
  inline double	Get_init_pfwd_curr_pol_yr() {
		return init_pfwd_curr_pol_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_pfwd_entitlement;
  inline double	Get_init_pfwd_entitlement() {
		return init_pfwd_entitlement; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_policies;
  inline double	Get_init_policies() {
		return init_policies; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_policies_female_aig;
  inline double	Get_init_policies_female_aig() {
		return init_policies_female_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_policies_joint_aig;
  inline double	Get_init_policies_joint_aig() {
		return init_policies_joint_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_policies_male_aig;
  inline double	Get_init_policies_male_aig() {
		return init_policies_male_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_rebal_pct_fixed;
  inline double	Get_init_rebal_pct_fixed() {
		return init_rebal_pct_fixed; }
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_spread_rate_index0_aig;
  inline double	Get_init_spread_rate_index0_aig() {
		return init_spread_rate_index0_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_spread_rate_index1_aig;
  inline double	Get_init_spread_rate_index1_aig() {
		return init_spread_rate_index1_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_spread_rate_index2_aig;
  inline double	Get_init_spread_rate_index2_aig() {
		return init_spread_rate_index2_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_spread_rate_index3_aig;
  inline double	Get_init_spread_rate_index3_aig() {
		return init_spread_rate_index3_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_spread_rate_index4_aig;
  inline double	Get_init_spread_rate_index4_aig() {
		return init_spread_rate_index4_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_stat_res_carvm;
  inline double	Get_init_stat_res_carvm() {
		return init_stat_res_carvm; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_strat_base;
  inline double	Get_init_strat_base() {
		return init_strat_base; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > init_strategy_term_aig;
  inline int	Get_init_strategy_term_aig() {
		return init_strategy_term_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_tax_res_carvm;
  inline double	Get_init_tax_res_carvm() {
		return init_tax_res_carvm; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_trigger_rate_index0_aig;
  inline double	Get_init_trigger_rate_index0_aig() {
		return init_trigger_rate_index0_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_withdrl_cumul;
  inline double	Get_init_withdrl_cumul() {
		return init_withdrl_cumul; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_buffer_cap_2nd_strat;
  inline double	Get_inner_buffer_cap_2nd_strat() {
		return inner_buffer_cap_2nd_strat; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_buffer_rate;
  inline double	Get_inner_buffer_rate() {
		return inner_buffer_rate; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_cap_rate;
  inline double	Get_inner_cap_rate() {
		return inner_cap_rate; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_dual_dir_cap_2nd_strat;
  inline double	Get_inner_dual_dir_cap_2nd_strat() {
		return inner_dual_dir_cap_2nd_strat; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_fixed_rate;
  inline double	Get_inner_fixed_rate() {
		return inner_fixed_rate; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_fund_val_boy;
  inline double	Get_inner_fund_val_boy() {
		return inner_fund_val_boy; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_index_val;
  inline double	Get_inner_index_val() {
		return inner_index_val; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_interim_val_beg_term;
  inline double	Get_inner_interim_val_beg_term() {
		return inner_interim_val_beg_term; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_min_wdl_val_aig;
  inline double	Get_inner_min_wdl_val_aig() {
		return inner_min_wdl_val_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_mwv_base_aig;
  inline double	Get_inner_mwv_base_aig() {
		return inner_mwv_base_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_opt_cost_beg_term;
  inline double	Get_inner_opt_cost_beg_term() {
		return inner_opt_cost_beg_term; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_par_up;
  inline double	Get_inner_par_up() {
		return inner_par_up; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_renewal_budget;
  inline double	Get_inner_renewal_budget() {
		return inner_renewal_budget; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_renewal_budget_2nd_strat;
  inline double	Get_inner_renewal_budget_2nd_strat() {
		return inner_renewal_budget_2nd_strat; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_strat_return;
  inline double	Get_inner_strat_return() {
		return inner_strat_return; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inner_trigger_rate;
  inline double	Get_inner_trigger_rate() {
		return inner_trigger_rate; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > isl_2019_alpha_aig;
  inline double	Get_isl_2019_alpha_aig() {
		return isl_2019_alpha_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > isl_2019_beta_aig;
  inline double	Get_isl_2019_beta_aig() {
		return isl_2019_beta_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > isl_2019_coefficient_aig;
  inline double	Get_isl_2019_coefficient_aig() {
		return isl_2019_coefficient_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > isl_2019_divisor_aig;
  inline double	Get_isl_2019_divisor_aig() {
		return isl_2019_divisor_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > isl_2019_lapse_dyn_rate_defn_aig;
  inline xstring	Get_isl_2019_lapse_dyn_rate_defn_aig() {
		return isl_2019_lapse_dyn_rate_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > isl_2019_lapse_dyn_rate_defn_at_issue_aig;
  inline xstring	Get_isl_2019_lapse_dyn_rate_defn_at_issue_aig() {
		return isl_2019_lapse_dyn_rate_defn_at_issue_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > isl_2019_surr_chg_pct_threshold_aig;
  inline double	Get_isl_2019_surr_chg_pct_threshold_aig() {
		return isl_2019_surr_chg_pct_threshold_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > issue_age_female_aig;
  inline int	Get_issue_age_female_aig() {
		return issue_age_female_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > issue_age_male_aig;
  inline int	Get_issue_age_male_aig() {
		return issue_age_male_aig; }
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
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > itmness_lookup_aig;
  inline xstring	Get_itmness_lookup_aig() {
		return itmness_lookup_aig; }
  inline void Set_itmness_lookup_aig(const xstring &v) {
		itmness_lookup_aig.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > iv_chg_dyn_lapse_aig;
  inline xstring	Get_iv_chg_dyn_lapse_aig() {
		return iv_chg_dyn_lapse_aig; }
  inline void Set_iv_chg_dyn_lapse_aig(const xstring &v) {
		iv_chg_dyn_lapse_aig.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > knockout_cost_interim_val_init;
  inline double	Get_knockout_cost_interim_val_init() {
		return knockout_cost_interim_val_init; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > knockout_mth;
  inline int	Get_knockout_mth() {
		return knockout_mth; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > knockout_status_ind;
  inline double	Get_knockout_status_ind() {
		return knockout_status_ind; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > lad_type_aig;
  inline xstring	Get_lad_type_aig() {
		return lad_type_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_adj_mult;
  inline double	Get_lapse_adj_mult() {
		return lapse_adj_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_arctan_2019_aft_mib_rollup_shock_mult_aig;
  inline double	Get_lapse_dyn_arctan_2019_aft_mib_rollup_shock_mult_aig() {
		return lapse_dyn_arctan_2019_aft_mib_rollup_shock_mult_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_arctan_2019_income_phase_mult_aig;
  inline double	Get_lapse_dyn_arctan_2019_income_phase_mult_aig() {
		return lapse_dyn_arctan_2019_income_phase_mult_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_arctan_2019_mib_rollup_shock_mult_aig;
  inline double	Get_lapse_dyn_arctan_2019_mib_rollup_shock_mult_aig() {
		return lapse_dyn_arctan_2019_mib_rollup_shock_mult_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_arctan_2019_param_01_aig;
  inline double	Get_lapse_dyn_arctan_2019_param_01_aig() {
		return lapse_dyn_arctan_2019_param_01_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_arctan_2019_param_02_aig;
  inline double	Get_lapse_dyn_arctan_2019_param_02_aig() {
		return lapse_dyn_arctan_2019_param_02_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_arctan_param_01_aig;
  inline double	Get_lapse_dyn_arctan_param_01_aig() {
		return lapse_dyn_arctan_param_01_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_arctan_param_02_aig;
  inline double	Get_lapse_dyn_arctan_param_02_aig() {
		return lapse_dyn_arctan_param_02_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > lapse_dyn_arctan_param_defn_aig;
  inline xstring	Get_lapse_dyn_arctan_param_defn_aig() {
		return lapse_dyn_arctan_param_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_dyn_base_prod_defn_aig;
  inline xstring	Get_lapse_dyn_base_prod_defn_aig() {
		return lapse_dyn_base_prod_defn_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_base_prod_mult_floor_aig;
  inline double	Get_lapse_dyn_base_prod_mult_floor_aig() {
		return lapse_dyn_base_prod_mult_floor_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_base_prod_tgt_pri_sprd_reduction_aig;
  inline double	Get_lapse_dyn_base_prod_tgt_pri_sprd_reduction_aig() {
		return lapse_dyn_base_prod_tgt_pri_sprd_reduction_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_base_prod_threshold_aig;
  inline double	Get_lapse_dyn_base_prod_threshold_aig() {
		return lapse_dyn_base_prod_threshold_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_dyn_beta_defn_aig;
  inline xstring	Get_lapse_dyn_beta_defn_aig() {
		return lapse_dyn_beta_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_dyn_defn_aig;
  inline xstring	Get_lapse_dyn_defn_aig() {
		return lapse_dyn_defn_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_exp;
  inline double	Get_lapse_dyn_exp() {
		return lapse_dyn_exp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_dyn_isl_method_aig;
  inline xstring	Get_lapse_dyn_isl_method_aig() {
		return lapse_dyn_isl_method_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_mult;
  inline double	Get_lapse_dyn_mult() {
		return lapse_dyn_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_mult_floor_aig;
  inline double	Get_lapse_dyn_mult_floor_aig() {
		return lapse_dyn_mult_floor_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_nmr_swap_sprd_aig;
  inline double	Get_lapse_dyn_nmr_swap_sprd_aig() {
		return lapse_dyn_nmr_swap_sprd_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_dyn_print_debug_output_defn_aig;
  inline xstring	Get_lapse_dyn_print_debug_output_defn_aig() {
		return lapse_dyn_print_debug_output_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_dyn_rate_defn_aig;
  inline xstring	Get_lapse_dyn_rate_defn_aig() {
		return lapse_dyn_rate_defn_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_rila_iv_chg_threshold_aig;
  inline double	Get_lapse_dyn_rila_iv_chg_threshold_aig() {
		return lapse_dyn_rila_iv_chg_threshold_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_dyn_rila_nmr_method_aig;
  inline xstring	Get_lapse_dyn_rila_nmr_method_aig() {
		return lapse_dyn_rila_nmr_method_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_scmult;
  inline double	Get_lapse_dyn_scmult() {
		return lapse_dyn_scmult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_dyn_surr_chg_period_defn_aig;
  inline xstring	Get_lapse_dyn_surr_chg_period_defn_aig() {
		return lapse_dyn_surr_chg_period_defn_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_dyn_thresh;
  inline double	Get_lapse_dyn_thresh() {
		return lapse_dyn_thresh; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_is_dynamic;
  inline xstring	Get_lapse_is_dynamic() {
		return lapse_is_dynamic; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_rate_base_prod_max_aig;
  inline double	Get_lapse_rate_base_prod_max_aig() {
		return lapse_rate_base_prod_max_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_rate_base_prod_min_aig;
  inline double	Get_lapse_rate_base_prod_min_aig() {
		return lapse_rate_base_prod_min_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_rate_input;
  inline double	Get_lapse_rate_input() {
		return lapse_rate_input; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_rate_max;
  inline double	Get_lapse_rate_max() {
		return lapse_rate_max; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_rate_min;
  inline double	Get_lapse_rate_min() {
		return lapse_rate_min; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > lapse_rate_table_aig;
  inline xstring	Get_lapse_rate_table_aig() {
		return lapse_rate_table_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_sens_test_deep_itm_mult_aig;
  inline double	Get_lapse_sens_test_deep_itm_mult_aig() {
		return lapse_sens_test_deep_itm_mult_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_sens_test_deep_itm_threshold_aig;
  inline double	Get_lapse_sens_test_deep_itm_threshold_aig() {
		return lapse_sens_test_deep_itm_threshold_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_sens_test_deep_otm_mult_aig;
  inline double	Get_lapse_sens_test_deep_otm_mult_aig() {
		return lapse_sens_test_deep_otm_mult_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_sens_test_deep_otm_threshold_aig;
  inline double	Get_lapse_sens_test_deep_otm_threshold_aig() {
		return lapse_sens_test_deep_otm_threshold_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_sens_test_dyn_lapse_add_mult_aig;
  inline double	Get_lapse_sens_test_dyn_lapse_add_mult_aig() {
		return lapse_sens_test_dyn_lapse_add_mult_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_sens_test_itm_add_aig;
  inline double	Get_lapse_sens_test_itm_add_aig() {
		return lapse_sens_test_itm_add_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_sens_test_itm_mult_aig;
  inline double	Get_lapse_sens_test_itm_mult_aig() {
		return lapse_sens_test_itm_mult_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_sens_test_itm_threshold_aig;
  inline double	Get_lapse_sens_test_itm_threshold_aig() {
		return lapse_sens_test_itm_threshold_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_sens_test_otm_add_aig;
  inline double	Get_lapse_sens_test_otm_add_aig() {
		return lapse_sens_test_otm_add_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_sens_test_otm_mult_aig;
  inline double	Get_lapse_sens_test_otm_mult_aig() {
		return lapse_sens_test_otm_mult_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_sens_test_otm_threshold_aig;
  inline double	Get_lapse_sens_test_otm_threshold_aig() {
		return lapse_sens_test_otm_threshold_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > lapse_skew_method_crbg;
  inline xstring	Get_lapse_skew_method_crbg() {
		return lapse_skew_method_crbg; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > lapse_skew_pol_mth;
  inline int	Get_lapse_skew_pol_mth() {
		return lapse_skew_pol_mth; }
  inline void Set_lapse_skew_pol_mth(const int &v) {
		lapse_skew_pol_mth.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > lapse_skew_split;
  inline double	Get_lapse_skew_split() {
		return lapse_skew_split; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > licensing_fee_table_aig;
  inline xstring	Get_licensing_fee_table_aig() {
		return licensing_fee_table_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > liquidity_spread_set_aig;
  inline xstring	Get_liquidity_spread_set_aig() {
		return liquidity_spread_set_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > maint_exp_fund_value_type;
  inline xstring	Get_maint_exp_fund_value_type() {
		return maint_exp_fund_value_type; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > maint_exp_pct_fund;
  inline double	Get_maint_exp_pct_fund() {
		return maint_exp_pct_fund; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > maint_exp_pct_fund_2_aig;
  inline double	Get_maint_exp_pct_fund_2_aig() {
		return maint_exp_pct_fund_2_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > maint_exp_pct_fund_aig;
  inline double	Get_maint_exp_pct_fund_aig() {
		return maint_exp_pct_fund_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > maint_exp_pct_strategy_value_aig;
  inline double	Get_maint_exp_pct_strategy_value_aig() {
		return maint_exp_pct_strategy_value_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > maint_exp_per_pol;
  inline double	Get_maint_exp_per_pol() {
		return maint_exp_per_pol; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > maint_exp_per_pol_payout;
  inline double	Get_maint_exp_per_pol_payout() {
		return maint_exp_per_pol_payout; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > make_whole_settlement_adj_coef_greater_aig;
  inline double	Get_make_whole_settlement_adj_coef_greater_aig() {
		return make_whole_settlement_adj_coef_greater_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > make_whole_settlement_adj_coef_lower_aig;
  inline double	Get_make_whole_settlement_adj_coef_lower_aig() {
		return make_whole_settlement_adj_coef_lower_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > male_sex_pct;
  inline double	Get_male_sex_pct() {
		return male_sex_pct; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > maturity_age_input;
  inline int	Get_maturity_age_input() {
		return maturity_age_input; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > maturity_benefits_min_yrs_aig;
  inline int	Get_maturity_benefits_min_yrs_aig() {
		return maturity_benefits_min_yrs_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > max_downward_deviation_aig;
  inline double	Get_max_downward_deviation_aig() {
		return max_downward_deviation_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > min_accum_val_activation_period_yrs_ny_aig;
  inline int	Get_min_accum_val_activation_period_yrs_ny_aig() {
		return min_accum_val_activation_period_yrs_ny_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > min_accum_val_annualized_growth_rate_ny_aig;
  inline double	Get_min_accum_val_annualized_growth_rate_ny_aig() {
		return min_accum_val_annualized_growth_rate_ny_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > min_cash_val_mths;
  inline int	Get_min_cash_val_mths() {
		return min_cash_val_mths; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > min_rate_set_aig;
  inline xstring	Get_min_rate_set_aig() {
		return min_rate_set_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > min_wdl_val_growth_pct_aig;
  inline double	Get_min_wdl_val_growth_pct_aig() {
		return min_wdl_val_growth_pct_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > min_wdl_val_method_aig;
  inline xstring	Get_min_wdl_val_method_aig() {
		return min_wdl_val_method_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > min_wdl_val_prem_pct_aig;
  inline double	Get_min_wdl_val_prem_pct_aig() {
		return min_wdl_val_prem_pct_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > model_version_set_aig;
  inline xstring	Get_model_version_set_aig() {
		return model_version_set_aig; }
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_base_curr;
  inline double	Get_mort_base_curr() {
		return mort_base_curr; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_base_curr_tbl_id;
  inline xstring	Get_mort_base_curr_tbl_id() {
		return mort_base_curr_tbl_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_base_curr_tbl_style;
  inline xstring	Get_mort_base_curr_tbl_style() {
		return mort_base_curr_tbl_style; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_base_guar;
  inline double	Get_mort_base_guar() {
		return mort_base_guar; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_base_guar_tbl_id;
  inline xstring	Get_mort_base_guar_tbl_id() {
		return mort_base_guar_tbl_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_base_guar_tbl_style;
  inline xstring	Get_mort_base_guar_tbl_style() {
		return mort_base_guar_tbl_style; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_base_tbl_id;
  inline xstring	Get_mort_base_tbl_id() {
		return mort_base_tbl_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_base_tbl_style;
  inline xstring	Get_mort_base_tbl_style() {
		return mort_base_tbl_style; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > mort_calc_basis;
  inline xstring	Get_mort_calc_basis() {
		return mort_calc_basis; }
  inline void Set_mort_calc_basis(const xstring &v) {
		mort_calc_basis.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > mort_calc_basis_joint_aig;
  inline xstring	Get_mort_calc_basis_joint_aig() {
		return mort_calc_basis_joint_aig; }
  inline void Set_mort_calc_basis_joint_aig(const xstring &v) {
		mort_calc_basis_joint_aig.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > mort_date;
  inline int	Get_mort_date() {
		return mort_date; }
  inline void Set_mort_date(const int &v) {
		mort_date.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > mort_gender;
  inline xstring	Get_mort_gender() {
		return mort_gender; }
  inline void Set_mort_gender(const xstring &v) {
		mort_gender.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_improve_base_date_aig;
  inline xstring	Get_mort_improve_base_date_aig() {
		return mort_improve_base_date_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > mort_improve_base_yr;
  inline int	Get_mort_improve_base_yr() {
		return mort_improve_base_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_improve_pct;
  inline double	Get_mort_improve_pct() {
		return mort_improve_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mort_improve_tbl_id_aig;
  inline xstring	Get_mort_improve_tbl_id_aig() {
		return mort_improve_tbl_id_aig; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > mort_issue_age;
  inline int	Get_mort_issue_age() {
		return mort_issue_age; }
  inline void Set_mort_issue_age(const int &v) {
		mort_issue_age.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > mort_mult;
  inline double	Get_mort_mult() {
		return mort_mult; }
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
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mp_id;
  inline xstring	Get_mp_id() {
		return mp_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > mva_defn_aig;
  inline xstring	Get_mva_defn_aig() {
		return mva_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > mva_has_cap_floor_aig;
  inline xstring	Get_mva_has_cap_floor_aig() {
		return mva_has_cap_floor_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > mva_period_aig;
  inline int	Get_mva_period_aig() {
		return mva_period_aig; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > nmr_less_cr_aig;
  inline xstring	Get_nmr_less_cr_aig() {
		return nmr_less_cr_aig; }
  inline void Set_nmr_less_cr_aig(const xstring &v) {
		nmr_less_cr_aig.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > no_wdl_cohort_lapse_is_dynamic_aig;
  inline xstring	Get_no_wdl_cohort_lapse_is_dynamic_aig() {
		return no_wdl_cohort_lapse_is_dynamic_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > non_gmwb_qualified_cal_fct1_aig;
  inline double	Get_non_gmwb_qualified_cal_fct1_aig() {
		return non_gmwb_qualified_cal_fct1_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > non_gmwb_qualified_cal_fct2_aig;
  inline double	Get_non_gmwb_qualified_cal_fct2_aig() {
		return non_gmwb_qualified_cal_fct2_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > non_gmwb_qualified_pct_aig;
  inline double	Get_non_gmwb_qualified_pct_aig() {
		return non_gmwb_qualified_pct_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > non_us_return_beta_aig;
  inline double	Get_non_us_return_beta_aig() {
		return non_us_return_beta_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > non_us_return_sigma_aig;
  inline double	Get_non_us_return_sigma_aig() {
		return non_us_return_sigma_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > opt_bgt_gr_sc_yrs_offset_aig;
  inline double	Get_opt_bgt_gr_sc_yrs_offset_aig() {
		return opt_bgt_gr_sc_yrs_offset_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > opt_bgt_gr_sc_yrs_offset_idx1_aig;
  inline double	Get_opt_bgt_gr_sc_yrs_offset_idx1_aig() {
		return opt_bgt_gr_sc_yrs_offset_idx1_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > opt_budget_defn_aig;
  inline xstring	Get_opt_budget_defn_aig() {
		return opt_budget_defn_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > opt_budget_tgt_alpha_aig;
  inline double	Get_opt_budget_tgt_alpha_aig() {
		return opt_budget_tgt_alpha_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > opt_budget_tgt_alpha_idx1_aig;
  inline double	Get_opt_budget_tgt_alpha_idx1_aig() {
		return opt_budget_tgt_alpha_idx1_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > opt_budget_tgt_reduction_aig;
  inline double	Get_opt_budget_tgt_reduction_aig() {
		return opt_budget_tgt_reduction_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > opt_budget_tgt_reduction_idx1_aig;
  inline double	Get_opt_budget_tgt_reduction_idx1_aig() {
		return opt_budget_tgt_reduction_idx1_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > opt_defn;
  inline xstring	Get_opt_defn() {
		return opt_defn; }
  inline void Set_opt_defn(const xstring &v) {
		opt_defn.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > option_strike_annualization_aig;
  inline xstring	Get_option_strike_annualization_aig() {
		return option_strike_annualization_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > part_down_amt;
  inline double	Get_part_down_amt() {
		return part_down_amt; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > part_enhancement_method_aig;
  inline xstring	Get_part_enhancement_method_aig() {
		return part_enhancement_method_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_base_lapse_mult_aig;
  inline double	Get_pba_base_lapse_mult_aig() {
		return pba_base_lapse_mult_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_infl_intercept_aig;
  inline double	Get_pba_infl_intercept_aig() {
		return pba_infl_intercept_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_infl_slope_aig;
  inline double	Get_pba_infl_slope_aig() {
		return pba_infl_slope_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_maint_exp_mult_aig;
  inline double	Get_pba_maint_exp_mult_aig() {
		return pba_maint_exp_mult_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_mort_mult_no_gmwb_aig;
  inline double	Get_pba_mort_mult_no_gmwb_aig() {
		return pba_mort_mult_no_gmwb_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_pfwd_pct_mult_aig;
  inline double	Get_pba_pfwd_pct_mult_aig() {
		return pba_pfwd_pct_mult_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pba_trail_comm_mult_aig;
  inline double	Get_pba_trail_comm_mult_aig() {
		return pba_trail_comm_mult_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > perf_lock_status_ind;
  inline double	Get_perf_lock_status_ind() {
		return perf_lock_status_ind; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > pfwd_amt_avail_defn;
  inline xstring	Get_pfwd_amt_avail_defn() {
		return pfwd_amt_avail_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > pfwd_amt_avail_defn_aig;
  inline xstring	Get_pfwd_amt_avail_defn_aig() {
		return pfwd_amt_avail_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > pfwd_freq;
  inline xstring	Get_pfwd_freq() {
		return pfwd_freq; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > pfwd_model_carvm_aig;
  inline xstring	Get_pfwd_model_carvm_aig() {
		return pfwd_model_carvm_aig; }
  inline void Set_pfwd_model_carvm_aig(const xstring &v) {
		pfwd_model_carvm_aig.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > pfwd_partial_interest_credited_aig;
  inline xstring	Get_pfwd_partial_interest_credited_aig() {
		return pfwd_partial_interest_credited_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pfwd_pct;
  inline double	Get_pfwd_pct() {
		return pfwd_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pfwd_use_nq_aig;
  inline double	Get_pfwd_use_nq_aig() {
		return pfwd_use_nq_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pfwd_use_q_aig;
  inline double	Get_pfwd_use_q_aig() {
		return pfwd_use_q_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > pfwd_util_table_aig;
  inline xstring	Get_pfwd_util_table_aig() {
		return pfwd_util_table_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > plan_code;
  inline xstring	Get_plan_code() {
		return plan_code; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > pol_yr_lookup_gen2;
  inline int	Get_pol_yr_lookup_gen2() {
		return pol_yr_lookup_gen2; }
  inline void Set_pol_yr_lookup_gen2(const int &v) {
		pol_yr_lookup_gen2.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > post_cdsc_yr_lookup_gen2;
  inline double	Get_post_cdsc_yr_lookup_gen2() {
		return post_cdsc_yr_lookup_gen2; }
  inline void Set_post_cdsc_yr_lookup_gen2(const double &v) {
		post_cdsc_yr_lookup_gen2.setValue(v); }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > preincome_exercise_yrs_aig;
  inline int	Get_preincome_exercise_yrs_aig() {
		return preincome_exercise_yrs_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > prem_bonus_recapture_pct_aig;
  inline double	Get_prem_bonus_recapture_pct_aig() {
		return prem_bonus_recapture_pct_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > prem_credit_pct_aig;
  inline double	Get_prem_credit_pct_aig() {
		return prem_credit_pct_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > prem_tax_pct;
  inline double	Get_prem_tax_pct() {
		return prem_tax_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > pricing_defn;
  inline xstring	Get_pricing_defn() {
		return pricing_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > product_feature_set_aig;
  inline xstring	Get_product_feature_set_aig() {
		return product_feature_set_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > prof_distribn_mode;
  inline xstring	Get_prof_distribn_mode() {
		return prof_distribn_mode; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > prop_female_owned_aig;
  inline double	Get_prop_female_owned_aig() {
		return prop_female_owned_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > prop_joint_owned_aig;
  inline double	Get_prop_joint_owned_aig() {
		return prop_joint_owned_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > prop_male_owned_aig;
  inline double	Get_prop_male_owned_aig() {
		return prop_male_owned_aig; }
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
	static Attribute::Descriptor descriptor_512[];
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4005)
// Disable the warning C4005: 'DESCRIPTOR_TABLE' : macro redefinition
#endif	MICROSOFT
	#define DESCRIPTOR_TABLE FIA_LIAB::descriptor_512
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_rate_curr_sprd;
  inline double	Get_purch_rate_curr_sprd() {
		return purch_rate_curr_sprd; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_rate_guar_fixed;
  inline double	Get_purch_rate_guar_fixed() {
		return purch_rate_guar_fixed; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > pv_benefits_defn_aig;
  inline xstring	Get_pv_benefits_defn_aig() {
		return pv_benefits_defn_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > pv_claims_stoch_init_crbg;
  inline double	Get_pv_claims_stoch_init_crbg() {
		return pv_claims_stoch_init_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > quota_share_reinsured_aig;
  inline double	Get_quota_share_reinsured_aig() {
		return quota_share_reinsured_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > rate_setting_cycle_aig;
  inline xstring	Get_rate_setting_cycle_aig() {
		return rate_setting_cycle_aig; }
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
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > rbc_c3_ann_risk_defn;
  inline xstring	Get_rbc_c3_ann_risk_defn() {
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
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > renew_into_2nd_strat_defn_aig;
  inline xstring	Get_renew_into_2nd_strat_defn_aig() {
		return renew_into_2nd_strat_defn_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > renew_into_2nd_strat_status;
  inline double	Get_renew_into_2nd_strat_status() {
		return renew_into_2nd_strat_status; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > renewal_2020_beta_down_aig;
  inline double	Get_renewal_2020_beta_down_aig() {
		return renewal_2020_beta_down_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > renewal_2020_beta_down_idx1_aig;
  inline double	Get_renewal_2020_beta_down_idx1_aig() {
		return renewal_2020_beta_down_idx1_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > renewal_2020_beta_up_aig;
  inline double	Get_renewal_2020_beta_up_aig() {
		return renewal_2020_beta_up_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > renewal_2020_beta_up_idx1_aig;
  inline double	Get_renewal_2020_beta_up_idx1_aig() {
		return renewal_2020_beta_up_idx1_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > renewal_2020_glb_beta_down_adj_aig;
  inline double	Get_renewal_2020_glb_beta_down_adj_aig() {
		return renewal_2020_glb_beta_down_adj_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > renewal_2020_glb_beta_down_adj_idx1_aig;
  inline double	Get_renewal_2020_glb_beta_down_adj_idx1_aig() {
		return renewal_2020_glb_beta_down_adj_idx1_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > renewal_2020_glb_beta_up_adj_aig;
  inline double	Get_renewal_2020_glb_beta_up_adj_aig() {
		return renewal_2020_glb_beta_up_adj_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > renewal_2020_glb_beta_up_adj_idx1_aig;
  inline double	Get_renewal_2020_glb_beta_up_adj_idx1_aig() {
		return renewal_2020_glb_beta_up_adj_idx1_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > renewal_2020_mig_st_yr_aig;
  inline int	Get_renewal_2020_mig_st_yr_aig() {
		return renewal_2020_mig_st_yr_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > renewal_2020_mig_st_yr_idx1_aig;
  inline int	Get_renewal_2020_mig_st_yr_idx1_aig() {
		return renewal_2020_mig_st_yr_idx1_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > renewal_set_aig;
  inline xstring	Get_renewal_set_aig() {
		return renewal_set_aig; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > res_period;
  inline int	Get_res_period() {
		return res_period; }
  inline void Set_res_period(const int &v) {
		res_period.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rila_dyn_lapse_addn_mult_floor_aig;
  inline double	Get_rila_dyn_lapse_addn_mult_floor_aig() {
		return rila_dyn_lapse_addn_mult_floor_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rila_ind;
  inline double	Get_rila_ind() {
		return rila_ind; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > rila_perf_lock_calc_aig;
  inline xstring	Get_rila_perf_lock_calc_aig() {
		return rila_perf_lock_calc_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rila_trading_cost_high_vol;
  inline double	Get_rila_trading_cost_high_vol() {
		return rila_trading_cost_high_vol; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rila_trading_cost_low_vol;
  inline double	Get_rila_trading_cost_low_vol() {
		return rila_trading_cost_low_vol; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rila_trading_cost_pba;
  inline double	Get_rila_trading_cost_pba() {
		return rila_trading_cost_pba; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rmd_attained_age_aig;
  inline double	Get_rmd_attained_age_aig() {
		return rmd_attained_age_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > rng_engine_aig;
  inline xstring	Get_rng_engine_aig() {
		return rng_engine_aig; }
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > sfc_annual_hedge_cost_aig;
  inline double	Get_sfc_annual_hedge_cost_aig() {
		return sfc_annual_hedge_cost_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > sfc_atan_alpha_aig;
  inline double	Get_sfc_atan_alpha_aig() {
		return sfc_atan_alpha_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > sfc_atan_beta_aig;
  inline double	Get_sfc_atan_beta_aig() {
		return sfc_atan_beta_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > sfc_atan_gamma_aig;
  inline double	Get_sfc_atan_gamma_aig() {
		return sfc_atan_gamma_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > sfc_atan_mult_floor_aig;
  inline double	Get_sfc_atan_mult_floor_aig() {
		return sfc_atan_mult_floor_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > shock_phase_lookup_aig;
  inline xstring	Get_shock_phase_lookup_aig() {
		return shock_phase_lookup_aig; }
  inline void Set_shock_phase_lookup_aig(const xstring &v) {
		shock_phase_lookup_aig.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > shock_status_dyn_lapse_aig;
  inline xstring	Get_shock_status_dyn_lapse_aig() {
		return shock_status_dyn_lapse_aig; }
  inline void Set_shock_status_dyn_lapse_aig(const xstring &v) {
		shock_status_dyn_lapse_aig.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > single_prem;
  inline double	Get_single_prem() {
		return single_prem; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > single_prem_prop_wdl_aig;
  inline double	Get_single_prem_prop_wdl_aig() {
		return single_prem_prop_wdl_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > snfl_add_age_aig;
  inline int	Get_snfl_add_age_aig() {
		return snfl_add_age_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > snfl_add_interest_rate_aig;
  inline double	Get_snfl_add_interest_rate_aig() {
		return snfl_add_interest_rate_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > snfl_maturity_age_aig;
  inline int	Get_snfl_maturity_age_aig() {
		return snfl_maturity_age_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > snfl_set_aig;
  inline xstring	Get_snfl_set_aig() {
		return snfl_set_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > spousal_continuation_defn_aig;
  inline xstring	Get_spousal_continuation_defn_aig() {
		return spousal_continuation_defn_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > spousal_continuation_election_rate_aig;
  inline double	Get_spousal_continuation_election_rate_aig() {
		return spousal_continuation_election_rate_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > stat_carvm_annuitzn_tests;
  inline xstring	Get_stat_carvm_annuitzn_tests() {
		return stat_carvm_annuitzn_tests; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > stat_carvm_calc_annuitzn_defn;
  inline xstring	Get_stat_carvm_calc_annuitzn_defn() {
		return stat_carvm_calc_annuitzn_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > stat_carvm_cont_defn;
  inline xstring	Get_stat_carvm_cont_defn() {
		return stat_carvm_cont_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > stat_carvm_defn;
  inline xstring	Get_stat_carvm_defn() {
		return stat_carvm_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > stat_carvm_gmwb_exercise_points;
  inline xstring	Get_stat_carvm_gmwb_exercise_points() {
		return stat_carvm_gmwb_exercise_points; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > stat_carvm_int_rate;
  inline double	Get_stat_carvm_int_rate() {
		return stat_carvm_int_rate; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > stat_carvm_life_int_rate;
  inline double	Get_stat_carvm_life_int_rate() {
		return stat_carvm_life_int_rate; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > stat_res_defn;
  inline xstring	Get_stat_res_defn() {
		return stat_res_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > stat_res_det_floor_defn_crbg;
  inline xstring	Get_stat_res_det_floor_defn_crbg() {
		return stat_res_det_floor_defn_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > stat_res_pct;
  inline double	Get_stat_res_pct() {
		return stat_res_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > stat_valn_code;
  inline xstring	Get_stat_valn_code() {
		return stat_valn_code; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > state_var_dth_bene_cap_aig;
  inline xstring	Get_state_var_dth_bene_cap_aig() {
		return state_var_dth_bene_cap_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > state_var_rider_fee_chg_aig;
  inline xstring	Get_state_var_rider_fee_chg_aig() {
		return state_var_rider_fee_chg_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > strategy_term_duration_aig;
  inline int	Get_strategy_term_duration_aig() {
		return strategy_term_duration_aig; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > strategy_term_dyn_aig;
  inline double	Get_strategy_term_dyn_aig() {
		return strategy_term_dyn_aig; }
  inline void Set_strategy_term_dyn_aig(const double &v) {
		strategy_term_dyn_aig.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > surr_ben_primary_tail_defn_aig;
  inline xstring	Get_surr_ben_primary_tail_defn_aig() {
		return surr_ben_primary_tail_defn_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > surr_chg_defn;
  inline xstring	Get_surr_chg_defn() {
		return surr_chg_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > surr_chg_pct;
  inline double	Get_surr_chg_pct() {
		return surr_chg_pct; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > surr_chg_period_aig;
  inline int	Get_surr_chg_period_aig() {
		return surr_chg_period_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tax_capzd_prem_pct;
  inline double	Get_tax_capzd_prem_pct() {
		return tax_capzd_prem_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tax_capzd_prem_pct_qualify;
  inline double	Get_tax_capzd_prem_pct_qualify() {
		return tax_capzd_prem_pct_qualify; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > tax_carvm_annuitzn_tests;
  inline xstring	Get_tax_carvm_annuitzn_tests() {
		return tax_carvm_annuitzn_tests; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tax_carvm_calc_annuitzn_defn;
  inline xstring	Get_tax_carvm_calc_annuitzn_defn() {
		return tax_carvm_calc_annuitzn_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tax_carvm_defn;
  inline xstring	Get_tax_carvm_defn() {
		return tax_carvm_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > tax_carvm_gmwb_exercise_points;
  inline xstring	Get_tax_carvm_gmwb_exercise_points() {
		return tax_carvm_gmwb_exercise_points; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tax_loss_treatment;
  inline xstring	Get_tax_loss_treatment() {
		return tax_loss_treatment; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tax_rate;
  inline double	Get_tax_rate() {
		return tax_rate; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tax_res_defn;
  inline xstring	Get_tax_res_defn() {
		return tax_res_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tax_res_pct;
  inline double	Get_tax_res_pct() {
		return tax_res_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > tax_valn_code;
  inline xstring	Get_tax_valn_code() {
		return tax_valn_code; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > temp_key_comp_lookup_aig;
  inline xstring	Get_temp_key_comp_lookup_aig() {
		return temp_key_comp_lookup_aig; }
  inline void Set_temp_key_comp_lookup_aig(const xstring &v) {
		temp_key_comp_lookup_aig.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > temp_key_cov_person_status;
  inline xstring	Get_temp_key_cov_person_status() {
		return temp_key_cov_person_status; }
  inline void Set_temp_key_cov_person_status(const xstring &v) {
		temp_key_cov_person_status.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > temp_key_cred_dyn_lever_aig;
  inline xstring	Get_temp_key_cred_dyn_lever_aig() {
		return temp_key_cred_dyn_lever_aig; }
  inline void Set_temp_key_cred_dyn_lever_aig(const xstring &v) {
		temp_key_cred_dyn_lever_aig.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > temp_key_cred_type_dyn_aig;
  inline xstring	Get_temp_key_cred_type_dyn_aig() {
		return temp_key_cred_type_dyn_aig; }
  inline void Set_temp_key_cred_type_dyn_aig(const xstring &v) {
		temp_key_cred_type_dyn_aig.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > temp_key_inc_phase_aig;
  inline xstring	Get_temp_key_inc_phase_aig() {
		return temp_key_inc_phase_aig; }
  inline void Set_temp_key_inc_phase_aig(const xstring &v) {
		temp_key_inc_phase_aig.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > temp_key_iss_age;
  inline int	Get_temp_key_iss_age() {
		return temp_key_iss_age; }
  inline void Set_temp_key_iss_age(const int &v) {
		temp_key_iss_age.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > temp_key_itmness_lookup_aig;
  inline xstring	Get_temp_key_itmness_lookup_aig() {
		return temp_key_itmness_lookup_aig; }
  inline void Set_temp_key_itmness_lookup_aig(const xstring &v) {
		temp_key_itmness_lookup_aig.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > temp_key_shock_phase_lookup_aig;
  inline xstring	Get_temp_key_shock_phase_lookup_aig() {
		return temp_key_shock_phase_lookup_aig; }
  inline void Set_temp_key_shock_phase_lookup_aig(const xstring &v) {
		temp_key_shock_phase_lookup_aig.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > testing_rate_set_aig;
  inline xstring	Get_testing_rate_set_aig() {
		return testing_rate_set_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tgt_cap_defn;
  inline xstring	Get_tgt_cap_defn() {
		return tgt_cap_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tgt_cap_rbc_mult;
  inline double	Get_tgt_cap_rbc_mult() {
		return tgt_cap_rbc_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > time_step_defn;
  inline xstring	Get_time_step_defn() {
		return time_step_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > total_lapse_based_on_tier_aig;
  inline xstring	Get_total_lapse_based_on_tier_aig() {
		return total_lapse_based_on_tier_aig; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > trading_cost_vol_index;
  inline xstring	Get_trading_cost_vol_index() {
		return trading_cost_vol_index; }
  inline void Set_trading_cost_vol_index(const xstring &v) {
		trading_cost_vol_index.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > use_mp;
  inline xstring	Get_use_mp() {
		return use_mp; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > use_option_cost_tables_defn_aig;
  inline xstring	Get_use_option_cost_tables_defn_aig() {
		return use_option_cost_tables_defn_aig; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > valn_carvm_defn;
  inline xstring	Get_valn_carvm_defn() {
		return valn_carvm_defn; }
  inline void Set_valn_carvm_defn(const xstring &v) {
		valn_carvm_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > valn_cash_settle_defn;
  inline xstring	Get_valn_cash_settle_defn() {
		return valn_cash_settle_defn; }
  inline void Set_valn_cash_settle_defn(const xstring &v) {
		valn_cash_settle_defn.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > valn_guar_dur;
  inline int	Get_valn_guar_dur() {
		return valn_guar_dur; }
  inline void Set_valn_guar_dur(const int &v) {
		valn_guar_dur.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > valn_int_guar_defn;
  inline xstring	Get_valn_int_guar_defn() {
		return valn_int_guar_defn; }
  inline void Set_valn_int_guar_defn(const xstring &v) {
		valn_int_guar_defn.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > valn_issue_yr;
  inline int	Get_valn_issue_yr() {
		return valn_issue_yr; }
  inline void Set_valn_issue_yr(const int &v) {
		valn_issue_yr.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > valn_periods_selected;
  inline xstring	Get_valn_periods_selected() {
		return valn_periods_selected; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > valn_plan_type;
  inline xstring	Get_valn_plan_type() {
		return valn_plan_type; }
  inline void Set_valn_plan_type(const xstring &v) {
		valn_plan_type.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > valn_rate_cash_settle_defn;
  inline xstring	Get_valn_rate_cash_settle_defn() {
		return valn_rate_cash_settle_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > valn_rate_int_guar_defn;
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
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > valn_rate_plan_type_non_elective_gmwb_after_exhaust_aig;
  inline xstring	Get_valn_rate_plan_type_non_elective_gmwb_after_exhaust_aig() {
		return valn_rate_plan_type_non_elective_gmwb_after_exhaust_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > valn_rate_plan_type_non_elective_gmwb_before_exhaust_aig;
  inline xstring	Get_valn_rate_plan_type_non_elective_gmwb_before_exhaust_aig() {
		return valn_rate_plan_type_non_elective_gmwb_before_exhaust_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > valn_yrs;
  inline int	Get_valn_yrs() {
		return valn_yrs; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > xol_chg_freq_aig;
  inline xstring	Get_xol_chg_freq_aig() {
		return xol_chg_freq_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > xol_chg_pct_aig;
  inline double	Get_xol_chg_pct_aig() {
		return xol_chg_pct_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > xol_deal_end_date_aig;
  inline int	Get_xol_deal_end_date_aig() {
		return xol_deal_end_date_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > xol_deal_switch_aig;
  inline xstring	Get_xol_deal_switch_aig() {
		return xol_deal_switch_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > xol_discount_rate_aig;
  inline double	Get_xol_discount_rate_aig() {
		return xol_discount_rate_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > xol_nb_eco_res_ratio_aig;
  inline double	Get_xol_nb_eco_res_ratio_aig() {
		return xol_nb_eco_res_ratio_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > xol_nb_initial_factor_aig;
  inline double	Get_xol_nb_initial_factor_aig() {
		return xol_nb_initial_factor_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > xol_quota_share_aig;
  inline double	Get_xol_quota_share_aig() {
		return xol_quota_share_aig; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > audit_detail_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > commencement_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > coupon_freq_aig;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > elapsed_mths;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > enhanced_income_flag_aig;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > final_period;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > gmwb_chg_freq_per_yr_aig;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gmwb_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gmwb_mib_rollup_max_yrs_aig;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > gmwb_req_yrs_wait;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > grop_flag_aig;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > independent_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > infl_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > infl_start_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > infl_start_yr;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > init_policies_female_spousal_2019_calc_aig;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > init_policies_joint_experience_calc_aig;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > init_policies_joint_spousal_2019_calc_aig;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > init_policies_male_spousal_2019_calc_aig;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > int_guar_dur;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > issue_date;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > issue_day;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > issue_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > issue_yr;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > itm_period_disc_rate;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > lapse_shock_year_aig;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > maturity_age;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > maturity_benefits_period_aig;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > maturity_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > max_mva_surr_chg_period_aig;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > mva_defn_lookup_aig;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > primary_tail_period_aig;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > proj_date_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_date;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_yr;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > reins_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > rop_db_flag_aig;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > start_period;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > state_of_world_financial_file_path;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > tax_capzd_prem_amortzn_yrs;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > tax_res_equals_stat_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > term_to_omega_age;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > valn_deterministic_flag_crbg;
	Attribute::Proxy<Scalar<double>, DESCRIPTOR_TABLE > wdl_period_mths_aig;

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

// Bs Vol Param
#line 1 "bs_vol_param.fia_liab.for"
double bs_vol_param(double spot, double strike, xstring put_or_call, int strategy_term);

// Calculate the base MAWP (before interest rate indexing):
#line 1 "calc_base_mawp_pct_aig.fia_liab.for"
double calc_base_mawp_pct_aig(
	int gmwb_withdrl_mth, StrEnum::EnumValue enhanced_income_benefit, StrEnum::EnumValue gender_cv);

// GMWB FLEX
#line 1 "calc_gmwb_flex_aig.fia_liab.for"
void calc_gmwb_flex_aig(void);

// Calculates the MAWP rate for a given arbitrary policy year
#line 1 "calc_mawp_pct_aig.fia_liab.for"
double calc_mawp_pct_aig(int t, int gmwb_withdrl_mth, StrEnum::EnumValue gender_cv, StrEnum::EnumValue enhanced_income_benefit, StrEnum::EnumValue income_phase, bool hypothetical_assessment = false);

// MVA Amount Calculation for Lapses
#line 1 "calc_mva_amt_full_surr_aig.fia_liab.for"
double calc_mva_amt_full_surr_aig(double mva_final_factor, 
								  double mva_base,
								  double free_withdrawal_amount,
								  double premium_enhancement_recapture);

// MVA Rate Calculation for Lapses, Alternative Model Products
#line 1 "calc_mva_rate_full_surr_alt_model_aig.fia_liab.for"
double calc_mva_rate_full_surr_alt_model_aig(double I, 
										   double J,
										   int N,
										   double maximum_gross_wdl_amt,
										   double remaining_preferred_wdl_amt,
										   double minimum_withdrawal_value,
										   double withdrawal_charge,
										   double premium_enhancement_recapture);

// MVA Rate Calculation for Lapses, Current Products
#line 1 "calc_mva_rate_full_surr_default_aig.fia_liab.for"
double calc_mva_rate_full_surr_default_aig(double I, 
										   double J,
										   int N,
										   double contract_value,
										   double minimum_withdrawal_value,
										   double withdrawal_charge,
										   double premium_enhancement_recapture);

// Calc Pipp Pct Aig
#line 1 "calc_pipp_pct_aig.fia_liab.for"
double calc_pipp_pct_aig(int t, int gmwb_withdrl_mth, StrEnum::EnumValue gender_cv);

// Get `covered person status` from `gender`:
#line 1 "covered_person_status_calc_aig.fia_liab.for"
StrEnum::EnumValue covered_person_status_calc_aig(StrEnum::EnumValue gender_cv);

// Covered person status enum value:
#line 1 "covered_person_status_get_enum_value_aig.fia_liab.for"
StrEnum::EnumValue covered_person_status_get_enum_value_aig(double covered_person_status);

// Covered person status code:
#line 1 "covered_person_status_get_integer_value_aig.fia_liab.for"
double covered_person_status_get_integer_value_aig(StrEnum::EnumValue covered_person_status);

// Sets the covered person status used for MAWP/PIPP rate lookups
#line 1 "covered_person_status_set_aig.fia_liab.for"
void covered_person_status_set_aig(void);

// Death Claim Rate Monthly Calculation
#line 1 "dth_claim_rate_mthly_calc.fia_liab.for"
double dth_claim_rate_mthly_calc(
	int t, int pol_yr, StrEnum::EnumValue mort_basis, StrEnum::EnumValue mort_gender_cv,
	StrEnum::EnumValue confinement_status, int confinement_age = 0, int confinement_mths = 0);

// Enhanced Income Benefit Eligibility Check Aig
#line 1 "enhanced_income_benefit_eligibility_check_aig.fia_liab.for"
bool enhanced_income_benefit_eligibility_check_aig(int policy_year, int enhanced_income_benefit_yrs, double fund_val);

// Enhanced Income Benefit Exercise Check
#line 1 "enhanced_income_benefit_exercise_check_aig.fia_liab.for"
StrEnum::EnumValue enhanced_income_benefit_exercise_check_aig(int policy_year, int enhanced_income_benefit_yrs, double fund_val, 
	StrEnum::EnumValue confinement_status, StrEnum::EnumValue projection_type );

// Enhanced Income Benefit Exercise Column/Enum Translation
#line 1 "enhanced_income_benefit_exercise_get_enum_aig.fia_liab.for"
StrEnum::EnumValue enhanced_income_benefit_exercise_get_enum_aig(int benefit_flag);

// Enhanced Income Confinement State Column/Enum Translation
#line 1 "enhanced_income_confinement_state_get_enum_aig.fia_liab.for"
StrEnum::EnumValue enhanced_income_confinement_state_get_enum_aig(int confinement_flag);

// Fund Val Exhaust Aig
#line 1 "fund_val_exhaust_aig.fia_liab.for"
int fund_val_exhaust_aig(int t, double account_value, double gmwb_max_wthdrl_amt, bool calc_to_cal_yr_exhaust = true);

// Uniform Rands Default Random Engine:
#line 1 "gen_uniform_rands_default_random_engine_aig.fia_liab.for"
void gen_uniform_rands_default_random_engine_aig(vector<vector<double>>& uniform_rands_arr);

// Gen Uniform Rands Rafm Random Engine Aig
#line 1 "gen_uniform_rands_rafm_random_engine_aig.fia_liab.for"
void gen_uniform_rands_rafm_random_engine_aig(vector< vector <double>>& uniform_rands_arr);

// Use model projection values to generate an RNG seed:
#line 1 "gen_uniform_rands_seed_aig.fia_liab.for"
int gen_uniform_rands_seed_aig(int scen_num, xstring mp_id);

// Gender:
#line 1 "gender_get_enum_value_aig.fia_liab.for"
StrEnum::EnumValue gender_get_enum_value_aig(double gender_code);

// Gender code:
#line 1 "gender_get_integer_value_aig.fia_liab.for"
double gender_get_integer_value_aig(StrEnum::EnumValue gender_cv);

// Gender Set Aig
#line 1 "gender_set_aig.fia_liab.for"
void gender_set_aig(void);

// Get Competitor Rate
#line 1 "get_comp_rate.fia_liab.for"
double get_comp_rate(xstring cr_id, int t);

// Get Gmwb Withdrawal Fixed Utilization Rate:
#line 1 "get_gmwb_wdl_fixed_utilization_rate_aig.fia_liab.for"
double get_gmwb_wdl_fixed_utilization_rate_aig(int t);

// Get Gmwb Withdrawal Random Initial Utilization Level:
#line 1 "get_gmwb_wdl_random_init_utilization_level_aig.fia_liab.for"
StrEnum::EnumValue get_gmwb_wdl_random_init_utilization_level_aig(double random_uniform_draw);

// Get Gmwb Withdrawal Random Utilization Level:
#line 1 "get_gmwb_wdl_random_utilization_level_aig.fia_liab.for"
StrEnum::EnumValue get_gmwb_wdl_random_utilization_level_aig(
	StrEnum::EnumValue current_level,
	StrEnum::EnumValue transition_tbl_id,
	double random_uniform_draw);

// Get Gmwb Withdrawal Random Utilization Rate:
#line 1 "get_gmwb_wdl_random_utilization_rate_aig.fia_liab.for"
double get_gmwb_wdl_random_utilization_rate_aig(StrEnum::EnumValue util_level);

// Get Gmwb Withdrawal Random Utilization Transition Probability:
#line 1 "get_gmwb_wdl_random_utilization_transition_prob_aig.fia_liab.for"
double get_gmwb_wdl_random_utilization_transition_prob_aig(
	StrEnum::EnumValue current_level, 
	StrEnum::EnumValue tgt_level,
	StrEnum::EnumValue gmwb_wdl_utilization_transition_prob_tbl);

// Randomly return a new utilization level:
#line 1 "get_gmwb_wdl_utilization_level_aig.fia_liab.for"
StrEnum::EnumValue get_gmwb_wdl_utilization_level_aig(
	int t, double unif_rv_cv, StrEnum::EnumValue util_level_cv, double fund_val_e_bef_cv = 0.0, double gmwb_inf_e_bef_cv = 0.0);

// Prints Claim Tail inner loop values
#line 1 "gmwb_claim_print_debug_output_aig.fia_liab.for"
void gmwb_claim_print_debug_output_aig(vector< vector <xstring> > debug_output);

// Return the utilization level enum value:
#line 1 "gmwb_wdl_utilization_level_get_enum_aig.fia_liab.for"
StrEnum::EnumValue gmwb_wdl_utilization_level_get_enum_aig(double util_code);

// Return number which corresponds to utilization level enum value:
#line 1 "gmwb_wdl_utilization_level_get_integer_aig.fia_liab.for"
double gmwb_wdl_utilization_level_get_integer_aig(StrEnum::EnumValue util_cv);

// Index Rate Referencing --addition to base withdrawal rate:
#line 1 "gmwb_withdrl_rate_indexing_addn_calc_aig.fia_liab.for"
double gmwb_withdrl_rate_indexing_addn_calc_aig(int t, StrEnum::EnumValue income_phase, bool hypothetical_assessment);

// Gmwb Withdrawal Rate Indexing Particpation Rate Calculation
#line 1 "gmwb_withdrl_rate_indexing_part_rate_calc_aig.fia_liab.for"
double gmwb_withdrl_rate_indexing_part_rate_calc_aig(int t, StrEnum::EnumValue income_phase);

// Internal Rate of Return Calculation
#line 1 "irr_calc.fia_liab.for"
double irr_calc(int t, const xstring &roi_type);

// Issue Age Calc Aig
#line 1 "issue_age_calc_aig.fia_liab.for"
int issue_age_calc_aig(StrEnum::EnumValue gender_cv);

// Calculate ISL 2019 Additional Lapse:
#line 1 "lapse_dyn_rate_add_isl_2019_calc_aig.fia_liab.for"
double lapse_dyn_rate_add_isl_2019_calc_aig(
	int t, double cash_val_e_bef_cv, double gmwb_inf_e_bef_cv, double glb_apv_cv, double glb_apv_at_issue_cv, double mva_pct = 0.0);

// Dynamic Lapse Rate
#line 1 "lapse_rate_dyn.fia_liab.for"
double lapse_rate_dyn(int t);

// Scale G2 mortality improvement
#line 1 "mort_improve_mult_aig.fia_liab.for"
double mort_improve_mult_aig(int att_age, StrEnum::EnumValue gender_local, int t);

// Calculate survivorship for inner loop projections:
#line 1 "pv_benefit_projection_mort_rates_calc_aig.fia_liab.for"
void pv_benefit_projection_mort_rates_calc_aig(const int& projection_month, const int& current_month, double& lxy, double& lx, double& ly, double& lxy_bar, double& dx, double& dy, double& dxy_bar);

// Get withdrawal discount factor for ITM inner loops:
#line 1 "pv_gmwb_benefit_disc_factor_calc_aig.fia_liab.for"
double pv_gmwb_benefit_disc_factor_calc_aig(int t, int i, StrEnum::EnumValue discount_rate_override);

// Current forward rate discounting:
#line 1 "pv_gmwb_benefit_disc_factor_curr_forward_calc_aig.fia_liab.for"
double pv_gmwb_benefit_disc_factor_curr_forward_calc_aig(int t, int i);

// Current spot rate discounting:
#line 1 "pv_gmwb_benefit_disc_factor_curr_spot_calc_aig.fia_liab.for"
double pv_gmwb_benefit_disc_factor_curr_spot_calc_aig(int t, int i);

// Future forwards discounting:
#line 1 "pv_gmwb_benefit_disc_factor_future_forward_calc_aig.fia_liab.for"
double pv_gmwb_benefit_disc_factor_future_forward_calc_aig(int t, int i);

// Calculate at-issue ten-year swap discount factor:
#line 1 "pv_gmwb_benefit_disc_factor_ten_year_swap_at_issue_calc_aig.fia_liab.for"
double pv_gmwb_benefit_disc_factor_ten_year_swap_at_issue_calc_aig(int t, int i);

// Calculate ten-year swap discount factor:
#line 1 "pv_gmwb_benefit_disc_factor_ten_year_swap_calc_aig.fia_liab.for"
double pv_gmwb_benefit_disc_factor_ten_year_swap_calc_aig(int t, int i);

// AIG's PV of GMWB benefit calculation
#line 1 "pv_gmwb_benefit_itm_calc_aig.fia_liab.for"
double pv_gmwb_benefit_itm_calc_aig(int t, double gmwb_income_base, StrEnum::EnumValue discount_rate_override);

// Prints ITM inner loop values
#line 1 "pv_gmwb_benefit_itm_debug_print_aig.fia_liab.for"
void pv_gmwb_benefit_itm_debug_print_aig(int t, vector< vector <xstring> > debug_output);

// Debug output helper function:
#line 1 "pv_gmwb_benefit_itm_debug_store_i_vals_aig.fia_liab.for"
void pv_gmwb_benefit_itm_debug_store_i_vals_aig(
	vector< vector <xstring> >& debug_output, int i, double period_wdl, double male_surv, double female_surv, double last_surv,
	double disc_factor, double disc_male_wdls, double disc_female_wdls, double disc_joint_wdls);

// Mortality Rate Used for ann_benefits_gmwb_calc_aig, Spousal 2019
#line 1 "pv_gmwb_benefit_mort_rate_calc_spousal_2019_aig.fia_liab.for"
double pv_gmwb_benefit_mort_rate_calc_spousal_2019_aig(int start_period, int i, int max_period, double spousal_continuation_election_rate);

// Pv SFC Benefit Forward Rate Calc Aig
#line 1 "pv_sfc_benefit_forward_rate_calc_aig.fia_liab.for"
double pv_sfc_benefit_forward_rate_calc_aig(int t, int i);

// Pv SFC Benefit Itm Calc Aig
#line 1 "pv_sfc_benefit_itm_calc_aig.fia_liab.for"
double pv_sfc_benefit_itm_calc_aig(int t);

// Read State Of World Financial
#line 1 "read_state_of_world_financial.fia_liab.for"
void read_state_of_world_financial(void);

// Sets Competitive Indicator End of the Month, Before Claims
#line 1 "set_comp_lookup_e_bef_aig.fia_liab.for"
void set_comp_lookup_e_bef_aig(int t);

// Setup FIA Account Variables
#line 1 "set_fia_account_vars.fia_liab.for"
void set_fia_account_vars(void);

// Set Minimum Income Base/Rollup Phase At the End of the Month, Before Claims
#line 1 "set_gmwb_mib_rollup_phase_lookup_e_bef_aig.fia_liab.for"
void set_gmwb_mib_rollup_phase_lookup_e_bef_aig(int t);

// Set Income Phase Lookup at the Beginning of Month:
#line 1 "set_income_phase_lookup_b_bef_aig.fia_liab.for"
void set_income_phase_lookup_b_bef_aig(int t);

// Set Income Phase At the End of the Month
#line 1 "set_income_phase_lookup_e_aig.fia_liab.for"
void set_income_phase_lookup_e_aig(int t);

// Set Income Phase At the End of the Month, Before Claims
#line 1 "set_income_phase_lookup_e_bef_aig.fia_liab.for"
void set_income_phase_lookup_e_bef_aig(int t);

// Sets In The Moneyness Lookup, end of the month, before claims
#line 1 "set_itmness_lookup_e_bef_aig.fia_liab.for"
void set_itmness_lookup_e_bef_aig(int t);

// Sets Shock Phase
#line 1 "set_shock_phase_lookup_aig.fia_liab.for"
void set_shock_phase_lookup_aig(int t);

// Spousal Continuation 2019 Death Claim Rate Calculation
#line 1 "spousal_2019_dth_claim_rate_calc_aig.fia_liab.for"
double spousal_2019_dth_claim_rate_calc_aig(double policies_last_to_die_bom, double policies_last_to_die_eom);

// Spousal Continuation 2019 Female Policies Projection
#line 1 "spousal_2019_proj_policies_female_aig.fia_liab.for"
double spousal_2019_proj_policies_female_aig(int t, double policies_joint_cv, double policies_female_cv, double spousal_continuation_election_rate_cv);

// Spousal Continuation 2019 Joint Policies Projection
#line 1 "spousal_2019_proj_policies_joint_aig.fia_liab.for"
double spousal_2019_proj_policies_joint_aig(int t, double policies_joint_cv);

// Spousal Continuation 2019 Last Survivor Policies Projection
#line 1 "spousal_2019_proj_policies_last_survivor_aig.fia_liab.for"
double spousal_2019_proj_policies_last_survivor_aig(double policies_joint_cv, double policies_male_cv, double policies_female_cv);

// Spousal Continuation 2019 Male Policies Projection
#line 1 "spousal_2019_proj_policies_male_aig.fia_liab.for"
double spousal_2019_proj_policies_male_aig(int t, double policies_joint_cv, double policies_male_cv, double spousal_continuation_election_rate_cv);

// Statutory CARVM Reserve Interim Calc
#line 1 "stat_res_calc_interim.fia_liab.for"
double stat_res_calc_interim(const xstring &col_name, int time);

// Sum Over Funds
#line 1 "sum_over_funds.fia_liab.for"
double sum_over_funds(const xstring &colname, int t, int type);

// Surrender Charge Inforce Calculation (Fund Value)
#line 1 "surr_chg_inf_fund_val_calc_aig.fia_liab.for"
double surr_chg_inf_fund_val_calc_aig(
    double fund_value,
    double prem_bonus_recapture,
    double pfwd_entitlement,
    double prorata_gmwb_chg,
	double prorata_rop_chg,
    int t);

// Surrender Charge Inforce Calculation (Intrinsic Value)
#line 1 "surr_chg_inf_intrinsic_val_calc_aig.fia_liab.for"
double surr_chg_inf_intrinsic_val_calc_aig(double max_wdl_amt, double remaining_pfwd, int t);

// Tax CARVM Reserve Interim Calc
#line 1 "tax_res_calc_interim.fia_liab.for"
double tax_res_calc_interim(const xstring &col_name, int time);

// Term To Omega Age Calculation
#line 1 "term_to_omega_age_calc_aig.fia_liab.for"
int term_to_omega_age_calc_aig(StrEnum::EnumValue gender, StrEnum::EnumValue mort_basis);

// Number of days Between two Dates in years
#line 1 "time_between_dates_calc_aig.fia_liab.for"
double time_between_dates_calc_aig(xstring start_date, xstring end_date);

// Validate Data
#line 1 "validate_data.fia_liab.for"
void validate_data(void);

// Bs Vol Solver
#line 1 "vol_solver.fia_liab.for"
double vol_solver(int t, xstring put_or_call, double opt_duration, double strike);

// Fund Value - Weighted Sum Over Funds, Beginning of Month After Charges
#line 1 "weighted_sum_over_funds_b_aig.fia_liab.for"
double weighted_sum_over_funds_b_aig(const xstring &colname, int t);

// Fund Value - Weighted Sum Over Funds, Beginning of Month
#line 1 "weighted_sum_over_funds_b_bef_aig.fia_liab.for"
double weighted_sum_over_funds_b_bef_aig(const xstring &colname, int t);

// Fund Value - Weighted Sum Over Funds, End of Month Before Claims
#line 1 "weighted_sum_over_funds_e_bef_aig.fia_liab.for"
double weighted_sum_over_funds_e_bef_aig(const xstring &colname, int t);

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
	_1D_FIACARVM_LIAB &sm_carvm_stat; //
	_1D_FIACARVM_LIAB &sm_carvm_tax; //
	_1D_FIAAFUND_LIAB &sm_fia_account; //
	_1D_ANN_PBA_PBA &sm_fia_ann_pba; //
	AUTOMATION *&sm_fia_automation; //
	BOND_PORTFOLIO_AIG *&sm_fia_bond_portfolio_aig; //
	RATES_ECONOMY *&sm_fia_rates; //
	_1D_SFAS133_GAAP &sm_fia_sfas133; //
	_1D_SFAS97RD_GAAP &sm_fia_sfas97rd; //
	FIA_LIAB *&sm_bond_is; //
	FIA_LIAB *&sm_bond_pv; //
	FIA_LIAB *&sm_bond_ym; //
	FIA_LIAB *&sm_mtg_is; //
	FIA_LIAB *&sm_mtg_pv; //
	FIA_LIAB *&sm_mtg_ym; //

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
