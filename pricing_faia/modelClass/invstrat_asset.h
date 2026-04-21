#ifndef __INVSTRAT_ASSET_H_
#define __INVSTRAT_ASSET_H_
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



namespace INVSTRAT_ASSET_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class INVSTRAT_ASSET_persistent_object;
class INVSTRAT_ASSET : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(INVSTRAT_ASSET); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;

int prior_strategy_selected_t;
int prior_strategy_set_t;
StrEnum::EnumValue prior_strategy_type;

int prior_neg_cash_flow_strategy_selected_t;
int prior_neg_cash_flow_strategy_set_t;
StrEnum::EnumValue prior_neg_cash_flow_strategy_type;

StrEnum::EnumValue asset_sub_port_distribn_defn;
StrEnum::EnumValue dur_match_processing_alt_strat;
double refinance_foreclosure_restructure_par;
double refinance_foreclosure_restructure_cost_basis;
double refinance_foreclosure_restructure_bk_val;
double cash_tgt_pct;
double asset_sub_port_inv_tgt_pct_sum;
double dur_match_tgt_incr;
double dur_match_tolerance_incr;
double expected_sold_at_bk;
double expected_mkt_val_for_dur_purch;
double expected_mkt_val_for_dur_sale;
double expected_mkt_val_times_dur_purch;
double expected_mkt_val_times_dur_sale;
xstring inv_strat_current;
xstring inv_strat_neg;
xstring inv_strat_shorter;
xstring inv_strat_shortest;
xstring inv_strat_longer;
xstring inv_strat_longest;
SmartArray <int> neg_cash_flow_sale_class_priority;
int neg_cash_flow_sales_priority_class_max;
SmartArray <int> rebal_sale_class_priority;
SmartArray <int> asset_class_to_sell_flag;
SmartArray <int> asset_fund_to_sell_flag;

// Purchase assets arrays (indexed by purchase asset num)
SmartArray <StrEnum::EnumValue> purch_assets_type;
SmartArray <xstring> purch_assets_id;
SmartArray <xstring> purch_assets_mp_grp_tag;
SmartArray <int> purch_assets_mp_num;
SmartArray <int> purch_assets_cp_num;
SmartArray <int> purch_assets_port_defn;
SmartArray <int> purch_assets_asset_sub_port_num;
SmartArray <double> purch_assets_weight;
SmartArray <int> purch_assets_dur_defn;
SmartArray <int> purch_assets_dur_calculated;
SmartArray <double> purch_assets_dur;
SmartArray <int> purch_assets_sub_port_num_current_strat;
SmartArray <double> purch_assets_weight_current_strat;
SmartArray <int> purch_assets_sub_port_num_alt_strat;
SmartArray <double> purch_assets_weight_alt_strat;
SmartArray <int> purch_assets_mths_to_maturity;
SmartArray <SmartArray <double> > sub_port_fund_expected_book_plus_accrued_sold;

int purch_asset_max_num;
bool initialize_purch_asset_maps;

// Initial sales and investment amount variables
SmartArray <SmartArray <double> > sub_port_fund_initial_book_plus_accrued;
SmartArray <SmartArray <SmartArray <int> > > sub_port_class_fund_assets_present;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_initial_accrued_interest;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_initial_book_value;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_initial_market_value;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_initial_unrealized_capital_gains;
// Sales amount variables
SmartArray <SmartArray <double> > sub_port_fund_book_plus_accrued_sold;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_accrued_interest_sold;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_book_value_sold;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_market_value_sold;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_unrealized_capital_gains_released;
// Purchase amount variables
SmartArray <SmartArray <double> > sub_port_fund_book_plus_accrued_purchases;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_accrued_interest_purchases;
SmartArray <SmartArray <SmartArray <double> > > sub_port_class_fund_book_value_purchases;
// Sales processing maps and multimaps
typedef map <int, int, less<int> > mvmap;
mvmap market_values_not_calculated_for_asset_sub_port_map;
typedef multimap <pair<double,double>, pair<int,int>, less<pair<double,double> > > evmmap;
evmmap extreme_value_multimap;

StrEnum::EnumValue display_rebal_sales_header;

typedef map <int, long, less <int> > mpmap;

// Purchase asset map
typedef map <xstring, int, less<xstring> > purchmap;
purchmap purchmap_investment;
purchmap purchmap_hedging; // for eio hedges

// Investment strategy map
typedef map <xstring, int, less<xstring> > stratmap;
stratmap stratmap_inv;

// Purchase asset id vectors
vector <string> purch_bond_assets;
vector <string> purch_mtg_assets;
vector <string> purch_sec_assets;
vector <string> purch_ird_assets;
vector <string> purch_re_assets;
vector <string> purch_eqt_assets;
vector <string> purch_eio_assets;

	void init_(){
		

asset_sub_port_distribn_defn = CASH;
dur_match_processing_alt_strat = NO;
refinance_foreclosure_restructure_par = 0.0;
refinance_foreclosure_restructure_cost_basis = 0.0;
refinance_foreclosure_restructure_bk_val = 0.0;
cash_tgt_pct = 0.0;
asset_sub_port_inv_tgt_pct_sum = 0.0;
dur_match_tgt_incr = 0.0;
dur_match_tolerance_incr = 0.0;
expected_sold_at_bk = 0.0;
expected_mkt_val_for_dur_purch = 0.0;
expected_mkt_val_for_dur_sale = 0.0;
expected_mkt_val_times_dur_purch = 0.0;
expected_mkt_val_times_dur_sale = 0.0;
inv_strat_current = "NONE";
inv_strat_shorter = "NONE";
inv_strat_shortest = "NONE";
inv_strat_longer = "NONE";
inv_strat_longest = "NONE";
purch_asset_max_num = 0;
initialize_purch_asset_maps = true;
neg_cash_flow_sales_priority_class_max = 0;

prior_strategy_selected_t = NO_AVG;
prior_strategy_set_t = NO_AVG;
prior_strategy_type = UNDEFINED;

prior_neg_cash_flow_strategy_selected_t = NO_AVG;
prior_neg_cash_flow_strategy_set_t = NO_AVG;
prior_neg_cash_flow_strategy_type = UNDEFINED;


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
#ifdef __CREATE_SFAS133_GAAP_CLASS_
	SFAS133_GAAP	*company_liab_fia_fia_sfas133;
	SFAS133_GAAP	*&fia_sfas133;
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
	SFAS97RD_GAAP	*company_liab_fia_fia_sfas97rd;
	SFAS97RD_GAAP	*&fia_sfas97rd;
#endif
#ifdef __CREATE_HDG_GRP_COMP_CLASS_
	HDG_GRP_COMP	*company_seg_hedge_grp;
	HDG_GRP_COMP	*&hedge_grp;
#endif
#ifdef __CREATE_INTEX_ASSET_CLASS_
	INTEX_ASSET	*company_asset_intex;
	INTEX_ASSET	*&intex;
#endif
#ifdef __CREATE_INVSTRAT_ASSET_CLASS_
	INVSTRAT_ASSET	*company_inv_strategy;
	INVSTRAT_ASSET	*&inv_strategy;
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
#ifdef __CREATE_UTIL_RAFM_CLASS_
	UTIL_RAFM	*util;
#endif
 // Column Definition Begins
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > cash;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_for_asset_purch;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_for_inv;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_for_inv_bef_rebal;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_hedge_sale;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_planned_sale;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_rebal;
  double cash_flow_rebal_estimate(int x);
 	ColumnAccessor < mCFStaticData_0 > cash_incr;
 	ColumnAccessor < mCFStaticData_0 > cash_investment_sale_net;
  double cash_investment_sale_net_prelim(int x);
 	ColumnAccessor < mCFStaticData_0 > cash_net_neg_cash_flow_sale;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > dur_bef_match;
 	ColumnAccessor < mCFStaticData_0 > dur_final_port;
 	ColumnAccessor < mCFStaticData_0 > dur_match_flag;
 	ColumnAccessor < mCFStaticData_0 > dur_match_tgt;
 	ColumnAccessor < mCFStaticData_0 > dur_match_tolerance;
 	ColumnAccessor < mCFStaticData_0 > finalize;
 	ColumnAccessor < mCFStaticData_0 > foreclosure_bk_val_net_write_down;
 	ColumnAccessor < mCFStaticData_0 > foreclosure_bk_val_net_write_down_neg_asset;
 	ColumnAccessor < mCFStaticData_0 > foreclosure_cost_basis_net_write_down;
 	ColumnAccessor < mCFStaticData_0 > foreclosure_cost_basis_net_write_down_neg_asset;
 	ColumnAccessor < mCFStaticData_0 > foreclosure_prin_net_write_down;
 	ColumnAccessor < mCFStaticData_0 > foreclosure_prin_net_write_down_neg_asset;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > initialize_sale_and_inv_vars_eom;
  double initialize_sub_port_sale_vars_eom(int x);
 	ColumnAccessor < mCFStaticData_0 > interim_cash;
 	ColumnAccessor < mCFStaticData_0 > inv_amt;
 	ColumnAccessor < mCFStaticData_0 > inv_deficit;
 	ColumnAccessor < mCFStaticData_0 > inv_eom_flag;
 	ColumnAccessor < mCFStaticData_0 > investable_assets_bef_rebal;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_for_dur_bef_dur_match;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_purch_for_dur_match;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_sale;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_sale_for_dur_match;
 	ColumnAccessor < mCFStaticData_0 > mkt_val_times_dur_bef_dur_match;
 	ColumnAccessor < mCFStaticData_0 > mths_to_rebal;
 	ColumnAccessor < mCFStaticData_0 > refinance_bk_val;
 	ColumnAccessor < mCFStaticData_0 > refinance_bk_val_neg_assets;
 	ColumnAccessor < mCFStaticData_0 > refinance_cost_basis;
 	ColumnAccessor < mCFStaticData_0 > refinance_cost_basis_neg_asset;
 	ColumnAccessor < mCFStaticData_0 > refinance_prin;
 	ColumnAccessor < mCFStaticData_0 > refinance_prin_neg_asset;
 	ColumnAccessor < mCFStaticData_0 > restructure_bk_val_net_write_down;
 	ColumnAccessor < mCFStaticData_0 > restructure_bk_val_net_write_down_neg_asset;
 	ColumnAccessor < mCFStaticData_0 > restructure_cost_basis_net_write_down;
 	ColumnAccessor < mCFStaticData_0 > restructure_cost_basis_net_write_down_neg_asset;
 	ColumnAccessor < mCFStaticData_0 > restructure_prin_net_write_down;
 	ColumnAccessor < mCFStaticData_0 > restructure_prin_net_write_down_neg_asset;
 	ColumnAccessor < mCFStaticData_0 > sale_planned_or_min_size_flag;
 	ColumnAccessor < mCFStaticData_0 > sale_possible_imr_avr_flag;
 	ColumnAccessor < mCFStaticData_0 > startup;
 	ColumnAccessor < mCFStaticData_0 > use_dur_match_strat;
//Column Definition END@2

 // Temporary Table...
INVSTRAT_ASSET *sm_bond_is;
INVSTRAT_ASSET *sm_bond_pv;
INVSTRAT_ASSET *sm_bond_ym;
INVSTRAT_ASSET *sm_mtg_is;
INVSTRAT_ASSET *sm_mtg_pv;
INVSTRAT_ASSET *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE INVSTRAT_ASSET::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > asset_sale_defn;
  inline xstring	Get_asset_sale_defn() {
		return asset_sale_defn; }
  inline void Set_asset_sale_defn(const xstring &v) {
		asset_sale_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > asset_sales_selection;
  inline xstring	Get_asset_sales_selection() {
		return asset_sales_selection; }
  inline void Set_asset_sales_selection(const xstring &v) {
		asset_sales_selection.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > asset_sub_port_id;
  inline xstring	Get_asset_sub_port_id() {
		return asset_sub_port_id; }
  inline void Set_asset_sub_port_id(const xstring &v) {
		asset_sub_port_id.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > asset_sub_port_inv_tgt_pct;
  inline double	Get_asset_sub_port_inv_tgt_pct() {
		return asset_sub_port_inv_tgt_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > data_validation_defn;
  inline xstring	Get_data_validation_defn() {
		return data_validation_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > dur_match_tgt_input;
  inline double	Get_dur_match_tgt_input() {
		return dur_match_tgt_input; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > dur_match_tolerance_input;
  inline double	Get_dur_match_tolerance_input() {
		return dur_match_tolerance_input; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > dur_wtd_sprd_adj_aig;
  inline double	Get_dur_wtd_sprd_adj_aig() {
		return dur_wtd_sprd_adj_aig; }
  inline void Set_dur_wtd_sprd_adj_aig(const double &v) {
		dur_wtd_sprd_adj_aig.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > fast_stat_calc_aig;
  inline xstring	Get_fast_stat_calc_aig() {
		return fast_stat_calc_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > foreclosure_int_pmt_mult;
  inline double	Get_foreclosure_int_pmt_mult() {
		return foreclosure_int_pmt_mult; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > foreclosure_inv_id;
  inline xstring	Get_foreclosure_inv_id() {
		return foreclosure_inv_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > foreclosure_prin_pmt_mult;
  inline double	Get_foreclosure_prin_pmt_mult() {
		return foreclosure_prin_pmt_mult; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gmwb_ind;
  inline int	Get_gmwb_ind() {
		return gmwb_ind; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > gmwb_type_aig;
  inline xstring	Get_gmwb_type_aig() {
		return gmwb_type_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > ia_prod_v3_rsd_2_aig;
  inline xstring	Get_ia_prod_v3_rsd_2_aig() {
		return ia_prod_v3_rsd_2_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > ia_prod_v3_rsd_2_defer_cf_aig;
  inline xstring	Get_ia_prod_v3_rsd_2_defer_cf_aig() {
		return ia_prod_v3_rsd_2_defer_cf_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inv_amt_min;
  inline double	Get_inv_amt_min() {
		return inv_amt_min; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > inv_purch_timing;
  inline xstring	Get_inv_purch_timing() {
		return inv_purch_timing; }
  inline void Set_inv_purch_timing(const xstring &v) {
		inv_purch_timing.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inv_strat_cash_tgt_pct;
  inline double	Get_inv_strat_cash_tgt_pct() {
		return inv_strat_cash_tgt_pct; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > inv_strat_closest;
  inline xstring	Get_inv_strat_closest() {
		return inv_strat_closest; }
  inline void Set_inv_strat_closest(const xstring &v) {
		inv_strat_closest.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > inv_strat_distribn_defn;
  inline xstring	Get_inv_strat_distribn_defn() {
		return inv_strat_distribn_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inv_strat_dur_wtd_sprd_adj_aig;
  inline double	Get_inv_strat_dur_wtd_sprd_adj_aig() {
		return inv_strat_dur_wtd_sprd_adj_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > inv_strat_economic_compare_defn;
  inline xstring	Get_inv_strat_economic_compare_defn() {
		return inv_strat_economic_compare_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inv_strat_economic_dur_match_tgt_incr;
  inline double	Get_inv_strat_economic_dur_match_tgt_incr() {
		return inv_strat_economic_dur_match_tgt_incr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inv_strat_economic_dur_match_tolerance_incr;
  inline double	Get_inv_strat_economic_dur_match_tolerance_incr() {
		return inv_strat_economic_dur_match_tolerance_incr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inv_strat_economic_fixed_test_val;
  inline double	Get_inv_strat_economic_fixed_test_val() {
		return inv_strat_economic_fixed_test_val; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > inv_strat_economic_lag_mths;
  inline int	Get_inv_strat_economic_lag_mths() {
		return inv_strat_economic_lag_mths; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > inv_strat_economic_longer;
  inline xstring	Get_inv_strat_economic_longer() {
		return inv_strat_economic_longer; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > inv_strat_economic_longest;
  inline xstring	Get_inv_strat_economic_longest() {
		return inv_strat_economic_longest; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > inv_strat_economic_mths;
  inline int	Get_inv_strat_economic_mths() {
		return inv_strat_economic_mths; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > inv_strat_economic_planned;
  inline xstring	Get_inv_strat_economic_planned() {
		return inv_strat_economic_planned; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inv_strat_economic_rate_1_term;
  inline double	Get_inv_strat_economic_rate_1_term() {
		return inv_strat_economic_rate_1_term; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inv_strat_economic_rate_2_term;
  inline double	Get_inv_strat_economic_rate_2_term() {
		return inv_strat_economic_rate_2_term; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > inv_strat_economic_shorter;
  inline xstring	Get_inv_strat_economic_shorter() {
		return inv_strat_economic_shorter; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > inv_strat_economic_shortest;
  inline xstring	Get_inv_strat_economic_shortest() {
		return inv_strat_economic_shortest; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > inv_strat_economic_test_calc_defn;
  inline xstring	Get_inv_strat_economic_test_calc_defn() {
		return inv_strat_economic_test_calc_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > inv_strat_economic_test_defn;
  inline xstring	Get_inv_strat_economic_test_defn() {
		return inv_strat_economic_test_defn; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > inv_strat_economic_test_num;
  inline int	Get_inv_strat_economic_test_num() {
		return inv_strat_economic_test_num; }
  inline void Set_inv_strat_economic_test_num(const int &v) {
		inv_strat_economic_test_num.setValue(v); }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > inv_strat_economic_tests;
  inline int	Get_inv_strat_economic_tests() {
		return inv_strat_economic_tests; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > inv_strat_id;
  inline xstring	Get_inv_strat_id() {
		return inv_strat_id; }
  inline void Set_inv_strat_id(const xstring &v) {
		inv_strat_id.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > inv_strat_planned;
  inline xstring	Get_inv_strat_planned() {
		return inv_strat_planned; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > inv_strat_planned_longer;
  inline xstring	Get_inv_strat_planned_longer() {
		return inv_strat_planned_longer; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > inv_strat_planned_longest;
  inline xstring	Get_inv_strat_planned_longest() {
		return inv_strat_planned_longest; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > inv_strat_planned_shorter;
  inline xstring	Get_inv_strat_planned_shorter() {
		return inv_strat_planned_shorter; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > inv_strat_planned_shortest;
  inline xstring	Get_inv_strat_planned_shortest() {
		return inv_strat_planned_shortest; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > inv_strat_portfolio_sprd_adj_aig;
  inline double	Get_inv_strat_portfolio_sprd_adj_aig() {
		return inv_strat_portfolio_sprd_adj_aig; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > mths_since_issue;
  inline int	Get_mths_since_issue() {
		return mths_since_issue; }
  inline void Set_mths_since_issue(const int &v) {
		mths_since_issue.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > neg_cash_flow_cash_bal_defn;
  inline xstring	Get_neg_cash_flow_cash_bal_defn() {
		return neg_cash_flow_cash_bal_defn; }
  inline void Set_neg_cash_flow_cash_bal_defn(const xstring &v) {
		neg_cash_flow_cash_bal_defn.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > neg_cash_flow_cash_thresh_addn;
  inline double	Get_neg_cash_flow_cash_thresh_addn() {
		return neg_cash_flow_cash_thresh_addn; }
  inline void Set_neg_cash_flow_cash_thresh_addn(const double &v) {
		neg_cash_flow_cash_thresh_addn.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > neg_cash_flow_cash_thresh_pct;
  inline double	Get_neg_cash_flow_cash_thresh_pct() {
		return neg_cash_flow_cash_thresh_pct; }
  inline void Set_neg_cash_flow_cash_thresh_pct(const double &v) {
		neg_cash_flow_cash_thresh_pct.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > neg_cash_flow_neg_assets;
  inline xstring	Get_neg_cash_flow_neg_assets() {
		return neg_cash_flow_neg_assets; }
  inline void Set_neg_cash_flow_neg_assets(const xstring &v) {
		neg_cash_flow_neg_assets.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > neg_cash_flow_sale_priority_avail_for_sale;
  inline int	Get_neg_cash_flow_sale_priority_avail_for_sale() {
		return neg_cash_flow_sale_priority_avail_for_sale; }
  inline void Set_neg_cash_flow_sale_priority_avail_for_sale(const int &v) {
		neg_cash_flow_sale_priority_avail_for_sale.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > neg_cash_flow_sale_priority_held_to_maturity;
  inline int	Get_neg_cash_flow_sale_priority_held_to_maturity() {
		return neg_cash_flow_sale_priority_held_to_maturity; }
  inline void Set_neg_cash_flow_sale_priority_held_to_maturity(const int &v) {
		neg_cash_flow_sale_priority_held_to_maturity.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > neg_cash_flow_sale_priority_not_assigned;
  inline int	Get_neg_cash_flow_sale_priority_not_assigned() {
		return neg_cash_flow_sale_priority_not_assigned; }
  inline void Set_neg_cash_flow_sale_priority_not_assigned(const int &v) {
		neg_cash_flow_sale_priority_not_assigned.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > neg_cash_flow_sale_priority_trading;
  inline int	Get_neg_cash_flow_sale_priority_trading() {
		return neg_cash_flow_sale_priority_trading; }
  inline void Set_neg_cash_flow_sale_priority_trading(const int &v) {
		neg_cash_flow_sale_priority_trading.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > neg_cash_flow_sale_selection_defn;
  inline xstring	Get_neg_cash_flow_sale_selection_defn() {
		return neg_cash_flow_sale_selection_defn; }
  inline void Set_neg_cash_flow_sale_selection_defn(const xstring &v) {
		neg_cash_flow_sale_selection_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > neg_cash_flow_strat;
  inline xstring	Get_neg_cash_flow_strat() {
		return neg_cash_flow_strat; }
  inline void Set_neg_cash_flow_strat(const xstring &v) {
		neg_cash_flow_strat.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic;
  inline xstring	Get_neg_cash_flow_strat_economic() {
		return neg_cash_flow_strat_economic; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_cash_bal_defn;
  inline xstring	Get_neg_cash_flow_strat_economic_cash_bal_defn() {
		return neg_cash_flow_strat_economic_cash_bal_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_cash_thresh_addn;
  inline double	Get_neg_cash_flow_strat_economic_cash_thresh_addn() {
		return neg_cash_flow_strat_economic_cash_thresh_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_cash_thresh_pct;
  inline double	Get_neg_cash_flow_strat_economic_cash_thresh_pct() {
		return neg_cash_flow_strat_economic_cash_thresh_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_compare_defn;
  inline xstring	Get_neg_cash_flow_strat_economic_compare_defn() {
		return neg_cash_flow_strat_economic_compare_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_fixed_test_val;
  inline double	Get_neg_cash_flow_strat_economic_fixed_test_val() {
		return neg_cash_flow_strat_economic_fixed_test_val; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_lag_mths;
  inline int	Get_neg_cash_flow_strat_economic_lag_mths() {
		return neg_cash_flow_strat_economic_lag_mths; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_mths;
  inline int	Get_neg_cash_flow_strat_economic_mths() {
		return neg_cash_flow_strat_economic_mths; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_neg_assets;
  inline xstring	Get_neg_cash_flow_strat_economic_neg_assets() {
		return neg_cash_flow_strat_economic_neg_assets; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_rate_1_term;
  inline double	Get_neg_cash_flow_strat_economic_rate_1_term() {
		return neg_cash_flow_strat_economic_rate_1_term; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_rate_2_term;
  inline double	Get_neg_cash_flow_strat_economic_rate_2_term() {
		return neg_cash_flow_strat_economic_rate_2_term; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_sale_priority_avail_for_sale;
  inline int	Get_neg_cash_flow_strat_economic_sale_priority_avail_for_sale() {
		return neg_cash_flow_strat_economic_sale_priority_avail_for_sale; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_sale_priority_held_to_maturity;
  inline int	Get_neg_cash_flow_strat_economic_sale_priority_held_to_maturity() {
		return neg_cash_flow_strat_economic_sale_priority_held_to_maturity; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_sale_priority_not_assigned;
  inline int	Get_neg_cash_flow_strat_economic_sale_priority_not_assigned() {
		return neg_cash_flow_strat_economic_sale_priority_not_assigned; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_sale_priority_trading;
  inline int	Get_neg_cash_flow_strat_economic_sale_priority_trading() {
		return neg_cash_flow_strat_economic_sale_priority_trading; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_sale_selection_defn;
  inline xstring	Get_neg_cash_flow_strat_economic_sale_selection_defn() {
		return neg_cash_flow_strat_economic_sale_selection_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_test_calc_defn;
  inline xstring	Get_neg_cash_flow_strat_economic_test_calc_defn() {
		return neg_cash_flow_strat_economic_test_calc_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_test_defn;
  inline xstring	Get_neg_cash_flow_strat_economic_test_defn() {
		return neg_cash_flow_strat_economic_test_defn; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_test_num;
  inline int	Get_neg_cash_flow_strat_economic_test_num() {
		return neg_cash_flow_strat_economic_test_num; }
  inline void Set_neg_cash_flow_strat_economic_test_num(const int &v) {
		neg_cash_flow_strat_economic_test_num.setValue(v); }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > neg_cash_flow_strat_economic_tests;
  inline int	Get_neg_cash_flow_strat_economic_tests() {
		return neg_cash_flow_strat_economic_tests; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > neg_cash_flow_strat_planned;
  inline xstring	Get_neg_cash_flow_strat_planned() {
		return neg_cash_flow_strat_planned; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > neg_cash_flow_strat_planned_cash_bal_defn;
  inline xstring	Get_neg_cash_flow_strat_planned_cash_bal_defn() {
		return neg_cash_flow_strat_planned_cash_bal_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > neg_cash_flow_strat_planned_cash_thresh_addn;
  inline double	Get_neg_cash_flow_strat_planned_cash_thresh_addn() {
		return neg_cash_flow_strat_planned_cash_thresh_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > neg_cash_flow_strat_planned_cash_thresh_pct;
  inline double	Get_neg_cash_flow_strat_planned_cash_thresh_pct() {
		return neg_cash_flow_strat_planned_cash_thresh_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > neg_cash_flow_strat_planned_neg_assets;
  inline xstring	Get_neg_cash_flow_strat_planned_neg_assets() {
		return neg_cash_flow_strat_planned_neg_assets; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > neg_cash_flow_strat_planned_sale_priority_avail_for_sale;
  inline int	Get_neg_cash_flow_strat_planned_sale_priority_avail_for_sale() {
		return neg_cash_flow_strat_planned_sale_priority_avail_for_sale; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > neg_cash_flow_strat_planned_sale_priority_held_to_maturity;
  inline int	Get_neg_cash_flow_strat_planned_sale_priority_held_to_maturity() {
		return neg_cash_flow_strat_planned_sale_priority_held_to_maturity; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > neg_cash_flow_strat_planned_sale_priority_not_assigned;
  inline int	Get_neg_cash_flow_strat_planned_sale_priority_not_assigned() {
		return neg_cash_flow_strat_planned_sale_priority_not_assigned; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > neg_cash_flow_strat_planned_sale_priority_trading;
  inline int	Get_neg_cash_flow_strat_planned_sale_priority_trading() {
		return neg_cash_flow_strat_planned_sale_priority_trading; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > neg_cash_flow_strat_planned_sale_selection_defn;
  inline xstring	Get_neg_cash_flow_strat_planned_sale_selection_defn() {
		return neg_cash_flow_strat_planned_sale_selection_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > plan_code_aig;
  inline xstring	Get_plan_code_aig() {
		return plan_code_aig; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > portfolio_sprd_adj_aig;
  inline double	Get_portfolio_sprd_adj_aig() {
		return portfolio_sprd_adj_aig; }
  inline void Set_portfolio_sprd_adj_aig(const double &v) {
		portfolio_sprd_adj_aig.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > purch_asset_id;
  inline xstring	Get_purch_asset_id() {
		return purch_asset_id; }
  inline void Set_purch_asset_id(const xstring &v) {
		purch_asset_id.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_asset_sub_port_id;
  inline xstring	Get_purch_asset_sub_port_id() {
		return purch_asset_sub_port_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_asset_weight;
  inline double	Get_purch_asset_weight() {
		return purch_asset_weight; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_bond_adj_category_id;
  inline xstring	Get_purch_bond_adj_category_id() {
		return purch_bond_adj_category_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_adj_max_above_init;
  inline double	Get_purch_bond_adj_max_above_init() {
		return purch_bond_adj_max_above_init; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_adj_max_below_init;
  inline double	Get_purch_bond_adj_max_below_init() {
		return purch_bond_adj_max_below_init; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_adj_max_reset_decr;
  inline double	Get_purch_bond_adj_max_reset_decr() {
		return purch_bond_adj_max_reset_decr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_adj_max_reset_incr;
  inline double	Get_purch_bond_adj_max_reset_incr() {
		return purch_bond_adj_max_reset_incr; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > purch_bond_adj_reset_mths;
  inline int	Get_purch_bond_adj_reset_mths() {
		return purch_bond_adj_reset_mths; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_adj_scen_addn_init;
  inline double	Get_purch_bond_adj_scen_addn_init() {
		return purch_bond_adj_scen_addn_init; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_adj_scen_addn_renewal;
  inline double	Get_purch_bond_adj_scen_addn_renewal() {
		return purch_bond_adj_scen_addn_renewal; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_adj_scen_mult;
  inline double	Get_purch_bond_adj_scen_mult() {
		return purch_bond_adj_scen_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_adj_scen_yr;
  inline double	Get_purch_bond_adj_scen_yr() {
		return purch_bond_adj_scen_yr; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_bond_assets_selected;
  inline xstring	Get_purch_bond_assets_selected() {
		return purch_bond_assets_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_avr_contribn_pct;
  inline double	Get_purch_bond_avr_contribn_pct() {
		return purch_bond_avr_contribn_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_avr_max_pct;
  inline double	Get_purch_bond_avr_max_pct() {
		return purch_bond_avr_max_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_avr_obj_pct;
  inline double	Get_purch_bond_avr_obj_pct() {
		return purch_bond_avr_obj_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_bond_call_defn;
  inline xstring	Get_purch_bond_call_defn() {
		return purch_bond_call_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_call_prem_addn;
  inline double	Get_purch_bond_call_prem_addn() {
		return purch_bond_call_prem_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_call_prem_mult;
  inline double	Get_purch_bond_call_prem_mult() {
		return purch_bond_call_prem_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_bond_call_price_defn;
  inline xstring	Get_purch_bond_call_price_defn() {
		return purch_bond_call_price_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_call_price_pct;
  inline double	Get_purch_bond_call_price_pct() {
		return purch_bond_call_price_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_call_protect_yrs;
  inline double	Get_purch_bond_call_protect_yrs() {
		return purch_bond_call_protect_yrs; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_bond_category_id;
  inline xstring	Get_purch_bond_category_id() {
		return purch_bond_category_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_first_par_call_yr;
  inline double	Get_purch_bond_first_par_call_yr() {
		return purch_bond_first_par_call_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_first_par_put_yr;
  inline double	Get_purch_bond_first_par_put_yr() {
		return purch_bond_first_par_put_yr; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_bond_grp_id;
  inline xstring	Get_purch_bond_grp_id() {
		return purch_bond_grp_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_bond_pmt_mode;
  inline xstring	Get_purch_bond_pmt_mode() {
		return purch_bond_pmt_mode; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_bond_port_defn;
  inline xstring	Get_purch_bond_port_defn() {
		return purch_bond_port_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_bond_put_defn;
  inline xstring	Get_purch_bond_put_defn() {
		return purch_bond_put_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_put_prem_addn;
  inline double	Get_purch_bond_put_prem_addn() {
		return purch_bond_put_prem_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_put_prem_mult;
  inline double	Get_purch_bond_put_prem_mult() {
		return purch_bond_put_prem_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_bond_put_price_defn;
  inline xstring	Get_purch_bond_put_price_defn() {
		return purch_bond_put_price_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_put_price_pct;
  inline double	Get_purch_bond_put_price_pct() {
		return purch_bond_put_price_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_put_protect_yrs;
  inline double	Get_purch_bond_put_protect_yrs() {
		return purch_bond_put_protect_yrs; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_bond_rate_defn;
  inline xstring	Get_purch_bond_rate_defn() {
		return purch_bond_rate_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_rate_diff;
  inline double	Get_purch_bond_rate_diff() {
		return purch_bond_rate_diff; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_rbc_c1_pct;
  inline double	Get_purch_bond_rbc_c1_pct() {
		return purch_bond_rbc_c1_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_bond_sale_class;
  inline xstring	Get_purch_bond_sale_class() {
		return purch_bond_sale_class; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_bond_sinking_fund_defn;
  inline xstring	Get_purch_bond_sinking_fund_defn() {
		return purch_bond_sinking_fund_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_sinking_fund_prin_pmt_pct;
  inline double	Get_purch_bond_sinking_fund_prin_pmt_pct() {
		return purch_bond_sinking_fund_prin_pmt_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_taxable_pct;
  inline double	Get_purch_bond_taxable_pct() {
		return purch_bond_taxable_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_yld_maint_addn;
  inline double	Get_purch_bond_yld_maint_addn() {
		return purch_bond_yld_maint_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_bond_yrs_to_maturity;
  inline double	Get_purch_bond_yrs_to_maturity() {
		return purch_bond_yrs_to_maturity; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_eio_asset_index;
  inline xstring	Get_purch_eio_asset_index() {
		return purch_eio_asset_index; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_eio_assets_selected;
  inline xstring	Get_purch_eio_assets_selected() {
		return purch_eio_assets_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eio_avr_contribn_pct;
  inline double	Get_purch_eio_avr_contribn_pct() {
		return purch_eio_avr_contribn_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eio_avr_max_pct;
  inline double	Get_purch_eio_avr_max_pct() {
		return purch_eio_avr_max_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eio_avr_obj_pct;
  inline double	Get_purch_eio_avr_obj_pct() {
		return purch_eio_avr_obj_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_eio_category_id;
  inline xstring	Get_purch_eio_category_id() {
		return purch_eio_category_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eio_div_yld_addn;
  inline double	Get_purch_eio_div_yld_addn() {
		return purch_eio_div_yld_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eio_div_yld_scen_mult;
  inline double	Get_purch_eio_div_yld_scen_mult() {
		return purch_eio_div_yld_scen_mult; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_eio_grp_id;
  inline xstring	Get_purch_eio_grp_id() {
		return purch_eio_grp_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eio_index_scen_addn;
  inline double	Get_purch_eio_index_scen_addn() {
		return purch_eio_index_scen_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eio_index_scen_mult;
  inline double	Get_purch_eio_index_scen_mult() {
		return purch_eio_index_scen_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_eio_lookback_defn;
  inline xstring	Get_purch_eio_lookback_defn() {
		return purch_eio_lookback_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_eio_lookback_sampling_interval;
  inline xstring	Get_purch_eio_lookback_sampling_interval() {
		return purch_eio_lookback_sampling_interval; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eio_lookback_yrs;
  inline double	Get_purch_eio_lookback_yrs() {
		return purch_eio_lookback_yrs; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_eio_opt_defn;
  inline xstring	Get_purch_eio_opt_defn() {
		return purch_eio_opt_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eio_opt_strike_price;
  inline double	Get_purch_eio_opt_strike_price() {
		return purch_eio_opt_strike_price; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eio_payout_index_max;
  inline double	Get_purch_eio_payout_index_max() {
		return purch_eio_payout_index_max; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_eio_port_defn;
  inline xstring	Get_purch_eio_port_defn() {
		return purch_eio_port_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eio_rbc_c1_pct;
  inline double	Get_purch_eio_rbc_c1_pct() {
		return purch_eio_rbc_c1_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_eio_sale_class;
  inline xstring	Get_purch_eio_sale_class() {
		return purch_eio_sale_class; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eio_yrs_to_maturity;
  inline double	Get_purch_eio_yrs_to_maturity() {
		return purch_eio_yrs_to_maturity; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_eqt_asset_index;
  inline xstring	Get_purch_eqt_asset_index() {
		return purch_eqt_asset_index; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_eqt_assets_selected;
  inline xstring	Get_purch_eqt_assets_selected() {
		return purch_eqt_assets_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eqt_avr_contribn_pct;
  inline double	Get_purch_eqt_avr_contribn_pct() {
		return purch_eqt_avr_contribn_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eqt_avr_max_pct;
  inline double	Get_purch_eqt_avr_max_pct() {
		return purch_eqt_avr_max_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eqt_avr_obj_pct;
  inline double	Get_purch_eqt_avr_obj_pct() {
		return purch_eqt_avr_obj_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_eqt_category_id;
  inline xstring	Get_purch_eqt_category_id() {
		return purch_eqt_category_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eqt_div_yld_addn;
  inline double	Get_purch_eqt_div_yld_addn() {
		return purch_eqt_div_yld_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eqt_div_yld_scen_mult;
  inline double	Get_purch_eqt_div_yld_scen_mult() {
		return purch_eqt_div_yld_scen_mult; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_eqt_grp_id;
  inline xstring	Get_purch_eqt_grp_id() {
		return purch_eqt_grp_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eqt_mkt_growth_addn;
  inline double	Get_purch_eqt_mkt_growth_addn() {
		return purch_eqt_mkt_growth_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eqt_mkt_growth_scen_mult;
  inline double	Get_purch_eqt_mkt_growth_scen_mult() {
		return purch_eqt_mkt_growth_scen_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_eqt_pmt_mode;
  inline xstring	Get_purch_eqt_pmt_mode() {
		return purch_eqt_pmt_mode; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_eqt_rbc_c1_pct;
  inline double	Get_purch_eqt_rbc_c1_pct() {
		return purch_eqt_rbc_c1_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_eqt_sale_class;
  inline xstring	Get_purch_eqt_sale_class() {
		return purch_eqt_sale_class; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_ird_assets_selected;
  inline xstring	Get_purch_ird_assets_selected() {
		return purch_ird_assets_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_ird_avr_contribn_pct;
  inline double	Get_purch_ird_avr_contribn_pct() {
		return purch_ird_avr_contribn_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_ird_avr_max_pct;
  inline double	Get_purch_ird_avr_max_pct() {
		return purch_ird_avr_max_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_ird_avr_obj_pct;
  inline double	Get_purch_ird_avr_obj_pct() {
		return purch_ird_avr_obj_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_ird_category_id;
  inline xstring	Get_purch_ird_category_id() {
		return purch_ird_category_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_ird_grp_id;
  inline xstring	Get_purch_ird_grp_id() {
		return purch_ird_grp_id; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > purch_ird_mths_to_first_reset;
  inline int	Get_purch_ird_mths_to_first_reset() {
		return purch_ird_mths_to_first_reset; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_ird_pmt_defn;
  inline xstring	Get_purch_ird_pmt_defn() {
		return purch_ird_pmt_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_ird_port_defn;
  inline xstring	Get_purch_ird_port_defn() {
		return purch_ird_port_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_ird_rate_1_addn;
  inline double	Get_purch_ird_rate_1_addn() {
		return purch_ird_rate_1_addn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_ird_rate_1_category_id;
  inline xstring	Get_purch_ird_rate_1_category_id() {
		return purch_ird_rate_1_category_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_ird_rate_1_defn;
  inline xstring	Get_purch_ird_rate_1_defn() {
		return purch_ird_rate_1_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_ird_rate_1_pmt_mode;
  inline xstring	Get_purch_ird_rate_1_pmt_mode() {
		return purch_ird_rate_1_pmt_mode; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_ird_rate_1_scen_mult;
  inline double	Get_purch_ird_rate_1_scen_mult() {
		return purch_ird_rate_1_scen_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_ird_rate_1_scen_yr;
  inline double	Get_purch_ird_rate_1_scen_yr() {
		return purch_ird_rate_1_scen_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_ird_rate_2_addn;
  inline double	Get_purch_ird_rate_2_addn() {
		return purch_ird_rate_2_addn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_ird_rate_2_category_id;
  inline xstring	Get_purch_ird_rate_2_category_id() {
		return purch_ird_rate_2_category_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_ird_rate_2_defn;
  inline xstring	Get_purch_ird_rate_2_defn() {
		return purch_ird_rate_2_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_ird_rate_2_pmt_mode;
  inline xstring	Get_purch_ird_rate_2_pmt_mode() {
		return purch_ird_rate_2_pmt_mode; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_ird_rate_2_scen_mult;
  inline double	Get_purch_ird_rate_2_scen_mult() {
		return purch_ird_rate_2_scen_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_ird_rate_2_scen_yr;
  inline double	Get_purch_ird_rate_2_scen_yr() {
		return purch_ird_rate_2_scen_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_ird_rbc_c1_pct;
  inline double	Get_purch_ird_rbc_c1_pct() {
		return purch_ird_rbc_c1_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_ird_sale_class;
  inline xstring	Get_purch_ird_sale_class() {
		return purch_ird_sale_class; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_ird_yrs_to_maturity;
  inline double	Get_purch_ird_yrs_to_maturity() {
		return purch_ird_yrs_to_maturity; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_adj_addn_init;
  inline double	Get_purch_mtg_adj_addn_init() {
		return purch_mtg_adj_addn_init; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_adj_addn_renewal;
  inline double	Get_purch_mtg_adj_addn_renewal() {
		return purch_mtg_adj_addn_renewal; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_mtg_adj_category_id;
  inline xstring	Get_purch_mtg_adj_category_id() {
		return purch_mtg_adj_category_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_adj_max_above_init;
  inline double	Get_purch_mtg_adj_max_above_init() {
		return purch_mtg_adj_max_above_init; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_adj_max_below_init;
  inline double	Get_purch_mtg_adj_max_below_init() {
		return purch_mtg_adj_max_below_init; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_adj_max_reset_decr;
  inline double	Get_purch_mtg_adj_max_reset_decr() {
		return purch_mtg_adj_max_reset_decr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_adj_max_reset_incr;
  inline double	Get_purch_mtg_adj_max_reset_incr() {
		return purch_mtg_adj_max_reset_incr; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > purch_mtg_adj_reset_mths;
  inline int	Get_purch_mtg_adj_reset_mths() {
		return purch_mtg_adj_reset_mths; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_adj_scen_mult;
  inline double	Get_purch_mtg_adj_scen_mult() {
		return purch_mtg_adj_scen_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_adj_scen_yr;
  inline double	Get_purch_mtg_adj_scen_yr() {
		return purch_mtg_adj_scen_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_amortzn_yrs;
  inline double	Get_purch_mtg_amortzn_yrs() {
		return purch_mtg_amortzn_yrs; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_mtg_assets_selected;
  inline xstring	Get_purch_mtg_assets_selected() {
		return purch_mtg_assets_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_avr_contribn_pct;
  inline double	Get_purch_mtg_avr_contribn_pct() {
		return purch_mtg_avr_contribn_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_avr_max_pct;
  inline double	Get_purch_mtg_avr_max_pct() {
		return purch_mtg_avr_max_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_avr_obj_pct;
  inline double	Get_purch_mtg_avr_obj_pct() {
		return purch_mtg_avr_obj_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_mtg_balloon_defn;
  inline xstring	Get_purch_mtg_balloon_defn() {
		return purch_mtg_balloon_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_balloon_prin_pmt_pct;
  inline double	Get_purch_mtg_balloon_prin_pmt_pct() {
		return purch_mtg_balloon_prin_pmt_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_mtg_category_id;
  inline xstring	Get_purch_mtg_category_id() {
		return purch_mtg_category_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_first_par_prepmt_yr;
  inline double	Get_purch_mtg_first_par_prepmt_yr() {
		return purch_mtg_first_par_prepmt_yr; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_mtg_grp_id;
  inline xstring	Get_purch_mtg_grp_id() {
		return purch_mtg_grp_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_mtg_pmt_mode;
  inline xstring	Get_purch_mtg_pmt_mode() {
		return purch_mtg_pmt_mode; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_mtg_port_defn;
  inline xstring	Get_purch_mtg_port_defn() {
		return purch_mtg_port_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_prepmt_penalty_addn;
  inline double	Get_purch_mtg_prepmt_penalty_addn() {
		return purch_mtg_prepmt_penalty_addn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_mtg_prepmt_penalty_defn;
  inline xstring	Get_purch_mtg_prepmt_penalty_defn() {
		return purch_mtg_prepmt_penalty_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_prepmt_penalty_mult;
  inline double	Get_purch_mtg_prepmt_penalty_mult() {
		return purch_mtg_prepmt_penalty_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_prepmt_penalty_pct;
  inline double	Get_purch_mtg_prepmt_penalty_pct() {
		return purch_mtg_prepmt_penalty_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_prepmt_protect_yrs;
  inline double	Get_purch_mtg_prepmt_protect_yrs() {
		return purch_mtg_prepmt_protect_yrs; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_mtg_rate_defn;
  inline xstring	Get_purch_mtg_rate_defn() {
		return purch_mtg_rate_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_rate_diff;
  inline double	Get_purch_mtg_rate_diff() {
		return purch_mtg_rate_diff; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_rbc_c1_pct;
  inline double	Get_purch_mtg_rbc_c1_pct() {
		return purch_mtg_rbc_c1_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_mtg_sale_class;
  inline xstring	Get_purch_mtg_sale_class() {
		return purch_mtg_sale_class; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_servicing_fee;
  inline double	Get_purch_mtg_servicing_fee() {
		return purch_mtg_servicing_fee; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_yld_maint_addn;
  inline double	Get_purch_mtg_yld_maint_addn() {
		return purch_mtg_yld_maint_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_yrs_to_balloon;
  inline double	Get_purch_mtg_yrs_to_balloon() {
		return purch_mtg_yrs_to_balloon; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_mtg_yrs_to_maturity;
  inline double	Get_purch_mtg_yrs_to_maturity() {
		return purch_mtg_yrs_to_maturity; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_re_asset_index;
  inline xstring	Get_purch_re_asset_index() {
		return purch_re_asset_index; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_re_assets_selected;
  inline xstring	Get_purch_re_assets_selected() {
		return purch_re_assets_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_re_avr_contribn_pct;
  inline double	Get_purch_re_avr_contribn_pct() {
		return purch_re_avr_contribn_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_re_avr_max_pct;
  inline double	Get_purch_re_avr_max_pct() {
		return purch_re_avr_max_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_re_avr_obj_pct;
  inline double	Get_purch_re_avr_obj_pct() {
		return purch_re_avr_obj_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_re_category_id;
  inline xstring	Get_purch_re_category_id() {
		return purch_re_category_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_re_depreciation_yrs;
  inline double	Get_purch_re_depreciation_yrs() {
		return purch_re_depreciation_yrs; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_re_grp_id;
  inline xstring	Get_purch_re_grp_id() {
		return purch_re_grp_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_re_mkt_growth_addn;
  inline double	Get_purch_re_mkt_growth_addn() {
		return purch_re_mkt_growth_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_re_mkt_growth_scen_mult;
  inline double	Get_purch_re_mkt_growth_scen_mult() {
		return purch_re_mkt_growth_scen_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_re_pmt_mode;
  inline xstring	Get_purch_re_pmt_mode() {
		return purch_re_pmt_mode; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_re_rbc_c1_pct;
  inline double	Get_purch_re_rbc_c1_pct() {
		return purch_re_rbc_c1_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_re_rent_rate_scen_addn;
  inline double	Get_purch_re_rent_rate_scen_addn() {
		return purch_re_rent_rate_scen_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_re_rent_rate_scen_mult;
  inline double	Get_purch_re_rent_rate_scen_mult() {
		return purch_re_rent_rate_scen_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_re_rental_growth;
  inline xstring	Get_purch_re_rental_growth() {
		return purch_re_rental_growth; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_re_sale_class;
  inline xstring	Get_purch_re_sale_class() {
		return purch_re_sale_class; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_sec_assets_selected;
  inline xstring	Get_purch_sec_assets_selected() {
		return purch_sec_assets_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_avr_contribn_pct;
  inline double	Get_purch_sec_avr_contribn_pct() {
		return purch_sec_avr_contribn_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_avr_max_pct;
  inline double	Get_purch_sec_avr_max_pct() {
		return purch_sec_avr_max_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_avr_obj_pct;
  inline double	Get_purch_sec_avr_obj_pct() {
		return purch_sec_avr_obj_pct; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_sec_category_id;
  inline xstring	Get_purch_sec_category_id() {
		return purch_sec_category_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_adj_addn_init;
  inline double	Get_purch_sec_cp_adj_addn_init() {
		return purch_sec_cp_adj_addn_init; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_adj_addn_renewal;
  inline double	Get_purch_sec_cp_adj_addn_renewal() {
		return purch_sec_cp_adj_addn_renewal; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_sec_cp_adj_category_id;
  inline xstring	Get_purch_sec_cp_adj_category_id() {
		return purch_sec_cp_adj_category_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_adj_max_above_init;
  inline double	Get_purch_sec_cp_adj_max_above_init() {
		return purch_sec_cp_adj_max_above_init; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_adj_max_below_init;
  inline double	Get_purch_sec_cp_adj_max_below_init() {
		return purch_sec_cp_adj_max_below_init; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_adj_max_reset_decr;
  inline double	Get_purch_sec_cp_adj_max_reset_decr() {
		return purch_sec_cp_adj_max_reset_decr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_adj_max_reset_incr;
  inline double	Get_purch_sec_cp_adj_max_reset_incr() {
		return purch_sec_cp_adj_max_reset_incr; }
	static Attribute::Descriptor descriptor_256[];
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4005)
// Disable the warning C4005: 'DESCRIPTOR_TABLE' : macro redefinition
#endif	MICROSOFT
	#define DESCRIPTOR_TABLE INVSTRAT_ASSET::descriptor_256
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > purch_sec_cp_adj_reset_mths;
  inline int	Get_purch_sec_cp_adj_reset_mths() {
		return purch_sec_cp_adj_reset_mths; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_adj_scen_mult;
  inline double	Get_purch_sec_cp_adj_scen_mult() {
		return purch_sec_cp_adj_scen_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_adj_scen_yr;
  inline double	Get_purch_sec_cp_adj_scen_yr() {
		return purch_sec_cp_adj_scen_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_amortzn_yrs;
  inline double	Get_purch_sec_cp_amortzn_yrs() {
		return purch_sec_cp_amortzn_yrs; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_sec_cp_asset_id;
  inline xstring	Get_purch_sec_cp_asset_id() {
		return purch_sec_cp_asset_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_sec_cp_category_id;
  inline xstring	Get_purch_sec_cp_category_id() {
		return purch_sec_cp_category_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_first_par_prepmt_yr;
  inline double	Get_purch_sec_cp_first_par_prepmt_yr() {
		return purch_sec_cp_first_par_prepmt_yr; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_sec_cp_pmt_mode;
  inline xstring	Get_purch_sec_cp_pmt_mode() {
		return purch_sec_cp_pmt_mode; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_prepmt_penalty_addn;
  inline double	Get_purch_sec_cp_prepmt_penalty_addn() {
		return purch_sec_cp_prepmt_penalty_addn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_sec_cp_prepmt_penalty_defn;
  inline xstring	Get_purch_sec_cp_prepmt_penalty_defn() {
		return purch_sec_cp_prepmt_penalty_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_prepmt_penalty_mult;
  inline double	Get_purch_sec_cp_prepmt_penalty_mult() {
		return purch_sec_cp_prepmt_penalty_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_prepmt_penalty_pct;
  inline double	Get_purch_sec_cp_prepmt_penalty_pct() {
		return purch_sec_cp_prepmt_penalty_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_prepmt_protect_yrs;
  inline double	Get_purch_sec_cp_prepmt_protect_yrs() {
		return purch_sec_cp_prepmt_protect_yrs; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_sec_cp_rate_defn;
  inline xstring	Get_purch_sec_cp_rate_defn() {
		return purch_sec_cp_rate_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_rate_diff;
  inline double	Get_purch_sec_cp_rate_diff() {
		return purch_sec_cp_rate_diff; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_servicing_fee;
  inline double	Get_purch_sec_cp_servicing_fee() {
		return purch_sec_cp_servicing_fee; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_yld_maint_addn;
  inline double	Get_purch_sec_cp_yld_maint_addn() {
		return purch_sec_cp_yld_maint_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_yrs_to_balloon;
  inline double	Get_purch_sec_cp_yrs_to_balloon() {
		return purch_sec_cp_yrs_to_balloon; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_cp_yrs_to_maturity;
  inline double	Get_purch_sec_cp_yrs_to_maturity() {
		return purch_sec_cp_yrs_to_maturity; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_sec_grp_id;
  inline xstring	Get_purch_sec_grp_id() {
		return purch_sec_grp_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_sec_io_po_defn;
  inline xstring	Get_purch_sec_io_po_defn() {
		return purch_sec_io_po_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_pac1_std_sch;
  inline double	Get_purch_sec_pac1_std_sch() {
		return purch_sec_pac1_std_sch; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_pac1z_accrual_addn;
  inline double	Get_purch_sec_pac1z_accrual_addn() {
		return purch_sec_pac1z_accrual_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_pac1z_sch;
  inline double	Get_purch_sec_pac1z_sch() {
		return purch_sec_pac1z_sch; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_sec_pac2_accrual_defn;
  inline xstring	Get_purch_sec_pac2_accrual_defn() {
		return purch_sec_pac2_accrual_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_pac2_z_accrual_addn;
  inline double	Get_purch_sec_pac2_z_accrual_addn() {
		return purch_sec_pac2_z_accrual_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_pac2a_sch;
  inline double	Get_purch_sec_pac2a_sch() {
		return purch_sec_pac2a_sch; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_pac2b_sch;
  inline double	Get_purch_sec_pac2b_sch() {
		return purch_sec_pac2b_sch; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_pac3_sch;
  inline double	Get_purch_sec_pac3_sch() {
		return purch_sec_pac3_sch; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_pac3_z_accrual_addn;
  inline double	Get_purch_sec_pac3_z_accrual_addn() {
		return purch_sec_pac3_z_accrual_addn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_rbc_c1_pct;
  inline double	Get_purch_sec_rbc_c1_pct() {
		return purch_sec_rbc_c1_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_sec_sale_class;
  inline xstring	Get_purch_sec_sale_class() {
		return purch_sec_sale_class; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_tranche_a_pct;
  inline double	Get_purch_sec_tranche_a_pct() {
		return purch_sec_tranche_a_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_tranche_b_pct;
  inline double	Get_purch_sec_tranche_b_pct() {
		return purch_sec_tranche_b_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_tranche_c_pct;
  inline double	Get_purch_sec_tranche_c_pct() {
		return purch_sec_tranche_c_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_sec_tranche_owned;
  inline xstring	Get_purch_sec_tranche_owned() {
		return purch_sec_tranche_owned; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_tranche_rate_addn;
  inline double	Get_purch_sec_tranche_rate_addn() {
		return purch_sec_tranche_rate_addn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > purch_sec_tranche_rate_category_id;
  inline xstring	Get_purch_sec_tranche_rate_category_id() {
		return purch_sec_tranche_rate_category_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_sec_tranche_rate_defn;
  inline xstring	Get_purch_sec_tranche_rate_defn() {
		return purch_sec_tranche_rate_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_tranche_rate_max_decr_from_init;
  inline double	Get_purch_sec_tranche_rate_max_decr_from_init() {
		return purch_sec_tranche_rate_max_decr_from_init; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_tranche_rate_max_incr_from_init;
  inline double	Get_purch_sec_tranche_rate_max_incr_from_init() {
		return purch_sec_tranche_rate_max_incr_from_init; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_tranche_rate_scen_mult;
  inline double	Get_purch_sec_tranche_rate_scen_mult() {
		return purch_sec_tranche_rate_scen_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_tranche_rate_scen_yr;
  inline double	Get_purch_sec_tranche_rate_scen_yr() {
		return purch_sec_tranche_rate_scen_yr; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_tranche_z_addn;
  inline double	Get_purch_sec_tranche_z_addn() {
		return purch_sec_tranche_z_addn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_sec_tranche_z_defn;
  inline xstring	Get_purch_sec_tranche_z_defn() {
		return purch_sec_tranche_z_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_tranche_z_jump_speed;
  inline double	Get_purch_sec_tranche_z_jump_speed() {
		return purch_sec_tranche_z_jump_speed; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > purch_sec_tranche_z_pct;
  inline double	Get_purch_sec_tranche_z_pct() {
		return purch_sec_tranche_z_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > purch_sec_tranche_z_prepmt_priority_bef_jump;
  inline xstring	Get_purch_sec_tranche_z_prepmt_priority_bef_jump() {
		return purch_sec_tranche_z_prepmt_priority_bef_jump; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > rbc_c4_method;
  inline xstring	Get_rbc_c4_method() {
		return rbc_c4_method; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > rebal_dur_match_defn;
  inline xstring	Get_rebal_dur_match_defn() {
		return rebal_dur_match_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > rebal_freq;
  inline xstring	Get_rebal_freq() {
		return rebal_freq; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > rebal_sale_priority_avail_for_sale;
  inline int	Get_rebal_sale_priority_avail_for_sale() {
		return rebal_sale_priority_avail_for_sale; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > rebal_sale_priority_held_to_maturity;
  inline int	Get_rebal_sale_priority_held_to_maturity() {
		return rebal_sale_priority_held_to_maturity; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > rebal_sale_priority_not_assigned;
  inline int	Get_rebal_sale_priority_not_assigned() {
		return rebal_sale_priority_not_assigned; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > rebal_sale_priority_trading;
  inline int	Get_rebal_sale_priority_trading() {
		return rebal_sale_priority_trading; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > rebal_sale_selection_defn;
  inline xstring	Get_rebal_sale_selection_defn() {
		return rebal_sale_selection_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > refinance_inv_id;
  inline xstring	Get_refinance_inv_id() {
		return refinance_inv_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > restructure_int_pmt_mult;
  inline double	Get_restructure_int_pmt_mult() {
		return restructure_int_pmt_mult; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > restructure_inv_id;
  inline xstring	Get_restructure_inv_id() {
		return restructure_inv_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > restructure_prin_pmt_mult;
  inline double	Get_restructure_prin_pmt_mult() {
		return restructure_prin_pmt_mult; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > seg_id;
  inline xstring	Get_seg_id() {
		return seg_id; }
  inline void Set_seg_id(const xstring &v) {
		seg_id.setValue(v); }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > surr_chg_period_aig;
  inline int	Get_surr_chg_period_aig() {
		return surr_chg_period_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > yrs_to_inv_mthly;
  inline int	Get_yrs_to_inv_mthly() {
		return yrs_to_inv_mthly; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > yrs_to_inv_qtrly;
  inline int	Get_yrs_to_inv_qtrly() {
		return yrs_to_inv_qtrly; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > final_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > foreclosure_asset_id;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > proj_date_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_date;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_yr;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > rebal_sales_priority_class_max;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > refinance_asset_id;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > restructure_asset_id;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > sales_priority_sub_port_max;
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
 void passDataVariables(INVSTRAT_ASSET* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Accumulate Asset Sales
#line 1 "accumulate_asset_sale.invstrat_asset.for"
void accumulate_asset_sale(int sub_port_number, int sale_class, int fund_index, double bk_val_sold, double accr_int_sold, double mkt_val_sold, double unrealized_capital_gains_released);

// Asset Detail Report Buy Purchase Asset
#line 1 "asset_detail_rpt_buy_purch_asset.invstrat_asset.for"
void asset_detail_rpt_buy_purch_asset(int t, StrEnum::EnumValue option, int sequence_id = 0, const xstring &identifier = "", int sub_port_num = 0, const xstring &sales_class = "", const xstring &asset_fund = "", double neg_asset_flag = 1, double notional_amt = 0, double mkt_val = 0, double cost_basis = 0, double bk_val = 0, double yrs_to_maturity = 0, double weighted_avg_life = 0, double eff_dur = 0);

// Asset Detail Report Individual Sale
#line 1 "asset_detail_rpt_individual_sale.invstrat_asset.for"
void asset_detail_rpt_individual_sale(int t, StrEnum::EnumValue option, int sequence_id = 0, const xstring &identifier = "", int sub_port_num = 0, int sales_class_num = 0, int asset_fund_index = 0, double percent_of_asset_to_sell = 0.0, double net_cash_from_asset_sale = 0.0, double bk_val_sold = 0.0, double accr_int_sold = 0.0, double mkt_val_sold = 0.0, double capital_gain = 0.0, double unrealized_capital_gains_released = 0.0, double dur_val = 0.0);

// Asset Detail Report Sub Portfolio Class Target Summary
#line 1 "asset_detail_rpt_sub_port_class_tgt_summary.invstrat_asset.for"
void asset_detail_rpt_sub_port_class_tgt_summary(int t);

// Asset Detail Report Target Percent by Sub Portfolio
#line 1 "asset_detail_rpt_tgt_pct_by_sub_port.invstrat_asset.for"
void asset_detail_rpt_tgt_pct_by_sub_port(int t, const xstring &standard, double asd_cash_for_investment, double asd_assets_other_than_cash, double distance_below_target_allocation, double distance_above_target_allocation, SmartArray <double> &sub_port_book_plus_accrued);

// Asset Duration Estimate
#line 1 "asset_dur_estimate.invstrat_asset.for"
double asset_dur_estimate(int t, double cash_flow_for_inv);

// Buy Hedging Assets
#line 1 "buy_assets_hedging.invstrat_asset.for"
double buy_assets_hedging(int t, int save_assets, StrEnum::EnumValue port_defn, int &new_mp_num, const xstring &hedge_group_code, const xstring &hedge_asset_id, double notional_amt_to_hedge, double long_strike, double short_strike);

// Buy Investment Assets
#line 1 "buy_assets_inv.invstrat_asset.for"
double buy_assets_inv(int t, int save_assets, double cash_flow_for_asset_purch);

// Buy Purchasel Asset Hedging
#line 1 "buy_purch_asset_hedging.invstrat_asset.for"
double buy_purch_asset_hedging(int t, int save_assets, StrEnum::EnumValue port_defn, int panum, const xstring &hedge_group_code, int &new_mp_num, double purch_asset_amt, double long_strike, double short_strike);

// Buy Purchase Asset Investment
#line 1 "buy_purch_asset_inv.invstrat_asset.for"
double buy_purch_asset_inv(int t, int save_assets, StrEnum::EnumValue port_defn, int panum, double purch_asset_amt);

// Clear Expected Sale Variables
#line 1 "clear_expected_sale_vars.invstrat_asset.for"
void clear_expected_sale_vars(int t);

// Create Extreme Value Multimap
#line 1 "create_extreme_val_multimap.invstrat_asset.for"
void create_extreme_val_multimap(int t, StrEnum::EnumValue sales_type, StrEnum::EnumValue extreme_selection);

// Create Extreme Value Multimap Entry
#line 1 "create_extreme_val_multimap_entry.invstrat_asset.for"
void create_extreme_val_multimap_entry(StrEnum::EnumValue selection_option, double mkt_to_bk_ratio = 0.0, double unrealzd_cap_gain_to_bk_ratio = 0.0, double duration_measure = 0.0, double notional_amount = 0.0, int asset_defn = 0, int model_point = 0);

// Duration Matching Decrease Duration
#line 1 "dur_match_decr_dur.invstrat_asset.for"
void dur_match_decr_dur(int t, int rebal_sales_completed, double dur_based_on_current_strat);

// Duration Matching Increase Duration
#line 1 "dur_match_incr_dur.invstrat_asset.for"
void dur_match_incr_dur(int t, int rebal_sales_completed, double dur_based_on_current_strat);

// Duration Matching Solve for Merge Strategy
#line 1 "dur_match_solve_for_merge_strat.invstrat_asset.for"
void dur_match_solve_for_merge_strat(int t, double dur_based_on_current_strat, double duration_based_on_alternate_strategy, int rebal_sales_completed);

// Expected Sales Cash
#line 1 "expected_sale_cash.invstrat_asset.for"
double expected_sale_cash(double book_value, double accrued_interest, double market_value, double unrealized_capital_gain, double capital_gains_cash_factor_for_sales);

// Initialize Sale and Investment Variables
#line 1 "initialize_sale_and_inv_vars.invstrat_asset.for"
double initialize_sale_and_inv_vars(int t, int sum_type, StrEnum::EnumValue investment_sales_timing);

// Investment Strategy Select
#line 1 "inv_strat_select.invstrat_asset.for"
bool inv_strat_select(int t, StrEnum::EnumValue strategy_type, bool issue_warnings, bool &warnings);

// Investment Strategy Set
#line 1 "inv_strat_set.invstrat_asset.for"
void inv_strat_set(int t);

// Negative Cash Flow Strategy Set
#line 1 "neg_cash_flow_strat_set.invstrat_asset.for"
void neg_cash_flow_strat_set(int t);

// Normalize Purchase Asset Weights
#line 1 "normalize_purch_asset_weight.invstrat_asset.for"
bool normalize_purch_asset_weight(bool issue_warnings);

// Rebalancing Investment Assets Sales
#line 1 "rebal_inv_assets_sale.invstrat_asset.for"
double rebal_inv_assets_sale(int t, StrEnum::EnumValue sell_assets, int turnover_rate_freq);

// Rebalancing Sales
#line 1 "rebal_sale.invstrat_asset.for"
double rebal_sale(int t, StrEnum::EnumValue sell_assets);

// Sell Investment Assets Control
#line 1 "sell_assets_control.invstrat_asset.for"
double sell_assets_control(int t, StrEnum::EnumValue sell_assets, StrEnum::EnumValue sales_type, StrEnum::EnumValue selection_defn, double required_amount);

// Sell Investment Assets Extreme Value
#line 1 "sell_assets_extreme_value.invstrat_asset.for"
double sell_assets_extreme_value(int t, StrEnum::EnumValue sell_assets, StrEnum::EnumValue sales_type, StrEnum::EnumValue extreme_selection, double cash_required, double capital_gains_cash_factor_for_sales);

// Sell Investment Assets Extreme Value Tiebreaker
#line 1 "sell_assets_extreme_value_tiebreaker.invstrat_asset.for"
double sell_assets_extreme_value_tiebreaker(double mkt_to_bk_ratio, double unrealzd_cap_gain_to_bk_ratio, double notional_amount);

// Sell Hedge Assets
#line 1 "sell_assets_hedges.invstrat_asset.for"
double sell_assets_hedges(int t, mpmap &eio_mp_map_active, double hedge_notional_amt, double liab_notional_amt, xstring hedge_grp_code);

// Sell Assets Planned and Minimum Size
#line 1 "sell_assets_planned_and_min_size.invstrat_asset.for"
double sell_assets_planned_and_min_size(int t, double capital_gains_cash_factor_for_sales);

// Sell Investment Assets Pro Rata
#line 1 "sell_assets_pro_rata.invstrat_asset.for"
double sell_assets_pro_rata(int t, StrEnum::EnumValue sell_assets, StrEnum::EnumValue sales_type, double cash_required, double capital_gains_cash_factor_for_sales);

// Set Asset Definitions
#line 1 "set_asset_defn.invstrat_asset.for"
void set_asset_defn(StrEnum::EnumValue strategy_type);

// Set Purchase Asset Definitions
#line 1 "set_purch_asset_defn.invstrat_asset.for"
int set_purch_asset_defn(int panum, int mp_num, StrEnum::EnumValue type, const xstring &identifier, StrEnum::EnumValue pmt_mode, double yrs_to_maturity, int mths_to_first_reset);

// Set Purchase Asset Maps
#line 1 "set_purch_asset_maps.invstrat_asset.for"
void set_purch_asset_maps();


//factory
static INVSTRAT_ASSET* makeThis(int isSubmodel, ModelClass *owner, INVSTRAT_ASSET* peer, 
					int mainRebase, const xstring &name, INVSTRAT_ASSET_persistent_object* arrayTemplate);

//constructor
INVSTRAT_ASSET(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
INVSTRAT_ASSET(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~INVSTRAT_ASSET();


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
class INVSTRAT_ASSET_persistent_object : public INVSTRAT_ASSET {


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

	void findTargetColumns() {INVSTRAT_ASSET::findTargetColumns();}
	void createAllShare() {
		INVSTRAT_ASSET::createAllShare();
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
	INVSTRAT_ASSET *&sm_bond_is; //
	INVSTRAT_ASSET *&sm_bond_pv; //
	INVSTRAT_ASSET *&sm_bond_ym; //
	INVSTRAT_ASSET *&sm_mtg_is; //
	INVSTRAT_ASSET *&sm_mtg_pv; //
	INVSTRAT_ASSET *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~INVSTRAT_ASSET_persistent_object();

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
static INVSTRAT_ASSET_persistent_object* makeThis(int isSubmodel, ModelClass *owner, INVSTRAT_ASSET* peer, 
					int mainRebase, const xstring &name, INVSTRAT_ASSET_persistent_object* arrayTemplate, bool fixedArray);

//constructor
INVSTRAT_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
