#ifndef __COMP_COMP_H_
#define __COMP_COMP_H_
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


#include "ModelClass\asset_asset.h"
#include "ModelClass\invstrat_asset.h"
#include "ModelClass\liab_liab.h"
#include "ModelClass\rates_economy.h"
#include "ModelClass\seg_comp.h"

namespace COMP_COMP_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class COMP_COMP_persistent_object;
class COMP_COMP : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(COMP_COMP); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;
	static void Terminator();
	static FunctionPtr RegisterTerminatorOnce;
	
// Financial state of world variables
double init_tax_bk_prof_ytd;
double init_tax_tgt_cap_ytd;
double init_tax_free_surp_ytd;
double init_taxable_inc_bk_prof_ytd;
double init_taxable_inc_tgt_cap_ytd;
double init_taxable_inc_free_surp_ytd;
double init_taxable_inc_carryfwd_avail;
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
double init_free_surp;
double init_gaap_inc_bef_tax_qtd;
double init_gaap_inc_bef_tax_ytd;
double init_gaap_inc_aft_tax_qtd;
double init_gaap_inc_aft_tax_ytd;
double init_asset_yld;
double init_asset_yld_less_dflt;
double init_asset_yld_less_dflt_inv;
typedef map <xstring, double, less<xstring> > crmap;
crmap comp_rates_map;
vector<string> disc_rates;
vector<string> segments;
vector <xstring> hedge_valn_shock_list;
vector <xstring> delta_gamma_hedge_shock_list;
vector <xstring> delta_gamma_hedge_index_list;
vector <xstring> rho_hedge_shock_list;
vector <xstring> rho_hedge_key_rate_list;
vector <xstring> vega_hedge_shock_list;
vector <xstring> vega_hedge_index_list;
vector <xstring> vega_hedge_index_term_list;
vector <xstring> vega_hedge_term_list;


	void init_(){
		

init_tax_bk_prof_ytd = 0.0;
init_tax_tgt_cap_ytd = 0.0;
init_tax_free_surp_ytd = 0.0;
init_taxable_inc_bk_prof_ytd = 0.0;
init_taxable_inc_tgt_cap_ytd = 0.0;
init_taxable_inc_free_surp_ytd = 0.0;
init_taxable_inc_carryfwd_avail = 0.0;
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
init_free_surp = 0.0;
init_gaap_inc_bef_tax_qtd = 0.0;
init_gaap_inc_bef_tax_ytd = 0.0;
init_gaap_inc_aft_tax_qtd = 0.0;
init_gaap_inc_aft_tax_ytd = 0.0;
init_asset_yld = 0.0;
init_asset_yld_less_dflt = 0.0;
init_asset_yld_less_dflt_inv = 0.0;

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
#ifdef __CREATE_BOND_AIG_CLASS_
	BOND_AIG	*company_liab_fia_fia_bond_portfolio_aig_fia_bond_aig;
	BOND_AIG	*&fia_bond_aig;
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
 	ColumnAccessor < mCFStaticData_0 > accr_inc;
 	ColumnAccessor < mCFStaticData_0 > accr_inc_inv;
 	ColumnAccessor < mCFStaticData_0 > accr_int;
 	ColumnAccessor < mCFStaticData_0 > accr_int_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > accr_int_dflt;
 	ColumnAccessor < mCFStaticData_0 > acq_exp;
 	ColumnAccessor < mCFStaticData_0 > ann_benefits_bom;
 	ColumnAccessor < mCFStaticData_0 > ann_benefits_eom;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_consideration;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_count_aig;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_inc;
 	ColumnAccessor < mCFStaticData_0 > annuitzn_val_released;
 	ColumnAccessor < mCFStaticData_0 > asset_cash_flow;
 	ColumnAccessor < mCFStaticData_0 > asset_cash_flow_bef_inv;
 	ColumnAccessor < mCFStaticData_0 > asset_cash_flow_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > asset_less_liab_and_surp;
 	ColumnAccessor < mCFStaticData_0 > asset_sa;
 	ColumnAccessor < mCFStaticData_0 > asset_yld;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_denom;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_denom_inv;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_inv;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_inv_adj_aig;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_less_dflt;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_less_dflt_inv;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_less_dflt_numer;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_less_dflt_numer_inv;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_numer;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_numer_inv;
 	ColumnAccessor < mCFStaticData_0 > asset_yld_vm21_reinv_rate;
 	ColumnAccessor < mCFStaticData_0 > avr;
 	ColumnAccessor < mCFStaticData_0 > avr_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_bond;
 	ColumnAccessor < mCFStaticData_0 > avr_bond_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_bond_bocy;
 	ColumnAccessor < mCFStaticData_0 > avr_dflt;
 	ColumnAccessor < mCFStaticData_0 > avr_dflt_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_eqt;
 	ColumnAccessor < mCFStaticData_0 > avr_eqt_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_incr;
 	ColumnAccessor < mCFStaticData_0 > avr_mtg;
 	ColumnAccessor < mCFStaticData_0 > avr_mtg_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_mtg_bocy;
 	ColumnAccessor < mCFStaticData_0 > avr_other;
 	ColumnAccessor < mCFStaticData_0 > avr_other_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_other_bocy;
 	ColumnAccessor < mCFStaticData_0 > avr_stock;
 	ColumnAccessor < mCFStaticData_0 > avr_stock_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > avr_stock_bocy;
 	ColumnAccessor < mCFStaticData_0 > avr_unrealzd_cap_gain_eqt_bocy;
 	ColumnAccessor < mCFStaticData_0 > avr_unrealzd_cap_gain_non_eqt_bocy;
 	ColumnAccessor < mCFStaticData_0 > bef_tax_yld;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_aft_tax;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_aft_tax_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_aft_tax_for_pv;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_aft_tax_irr;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_aft_tax_qtd;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_aft_tax_ytd;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_bef_tax;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_bef_tax_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_bef_tax_for_pv;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_bef_tax_qtd;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_bef_tax_ytd;
 	ColumnAccessor < mCFStaticData_0 > bk_prof_by_source_bef_tax;
 	ColumnAccessor < mCFStaticData_0 > bk_val;
 	ColumnAccessor < mCFStaticData_0 > bk_val_inv;
 	ColumnAccessor < mCFStaticData_0 > borrowing;
 	ColumnAccessor < mCFStaticData_0 > borrowing_int;
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > cap_gain;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_free_surp;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_free_surp_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_from_sale;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_res;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_res_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_tgt_cap;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_tgt_cap_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_undistrib_earnings;
 	ColumnAccessor < mCFStaticData_0 > cap_gain_undistrib_earnings_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > cash;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_for_inv;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_int;
 	ColumnAccessor < mCFStaticData_0 > cash_flow_invested;
 	ColumnAccessor < mCFStaticData_0 > cash_int;
 	ColumnAccessor < mCFStaticData_0 > cash_int_inv;
 	ColumnAccessor < mCFStaticData_0 > cash_val;
 	ColumnAccessor < mCFStaticData_0 > claim_paid;
 	ColumnAccessor < mCFStaticData_0 > comm_bom;
 	ColumnAccessor < mCFStaticData_0 > comm_chargeback;
 	ColumnAccessor < mCFStaticData_0 > comm_eom;
 	ColumnAccessor < mCFStaticData_0 > conversion_cost;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_accrual;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_incr_appreciation;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_purch;
 	ColumnAccessor < mCFStaticData_0 > cost_basis_sale;
 	ColumnAccessor < mCFStaticData_0 > credited_int;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > deferred_gross_prem;
 	ColumnAccessor < mCFStaticData_0 > deferred_gross_prem_incr;
 	ColumnAccessor < mCFStaticData_0 > deferred_net_prem;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_inv_amt;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_pmt;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_prof;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_0 > delta_hedge_transaction_cost;
 	ColumnAccessor < mCFStaticData_0 > dflt_amt;
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
 	ColumnAccessor < mCFStaticData_0 > disc_rate_risk_free_aig;
 	ColumnAccessor < mCFStaticData_0 > distrib_earnings;
 	ColumnAccessor < mCFStaticData_0 > distrib_earnings_be;
 	ColumnAccessor < mCFStaticData_0 > distrib_earnings_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > distrib_earnings_cum;
 	ColumnAccessor < mCFStaticData_0 > distrib_earnings_irr;
 	ColumnAccessor < mCFStaticData_0 > distrib_earnings_strain;
 	ColumnAccessor < mCFStaticData_0 > div_applied;
 	ColumnAccessor < mCFStaticData_0 > div_liab;
 	ColumnAccessor < mCFStaticData_0 > div_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > div_paid;
 	ColumnAccessor < mCFStaticData_0 > dth_ben_inf;
 	ColumnAccessor < mCFStaticData_0 > dth_benefits;
 	ColumnAccessor < mCFStaticData_0 > dth_count_aig;
 	ColumnAccessor < mCFStaticData_0 > earnings_accum;
 	ColumnAccessor < mCFStaticData_0 > econ_cash;
 	ColumnAccessor < mCFStaticData_0 > econ_cash_int;
 	ColumnAccessor < mCFStaticData_0 > econ_prof;
 	ColumnAccessor < mCFStaticData_0 > econ_prof_unhedged;
 	ColumnAccessor < mCFStaticData_0 > econ_res;
 	ColumnAccessor < mCFStaticData_0 > econ_res_incr;
 	ColumnAccessor < mCFStaticData_0 > econ_res_int;
 	ColumnAccessor < mCFStaticData_0 > endow_benefits;
 	ColumnAccessor < mCFStaticData_0 > finalize;
 	ColumnAccessor < mCFStaticData_0 > free_surp;
 	ColumnAccessor < mCFStaticData_0 > free_surp_at_mkt;
 	ColumnAccessor < mCFStaticData_0 > free_surp_at_mkt_ending;
 	ColumnAccessor < mCFStaticData_0 > free_surp_bef_shldr_div;
 	ColumnAccessor < mCFStaticData_0 > free_surp_incr;
 	ColumnAccessor < mCFStaticData_0 > fund_released_ann;
 	ColumnAccessor < mCFStaticData_0 > fund_released_dth;
 	ColumnAccessor < mCFStaticData_0 > fund_released_maturity;
 	ColumnAccessor < mCFStaticData_0 > fund_released_surr;
 	ColumnAccessor < mCFStaticData_0 > fund_released_withdrl;
 	ColumnAccessor < mCFStaticData_0 > fund_val_fixed;
 	ColumnAccessor < mCFStaticData_0 > fund_val_sa;
 	ColumnAccessor < mCFStaticData_0 > fund_weighted_cap_spread_fix_rt_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_weighted_par_rate_aig;
 	ColumnAccessor < mCFStaticData_0 > fund_weighted_pri_spread_aig;
 	ColumnAccessor < mCFStaticData_0 > gaap_accum_ben_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > gaap_ann_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_ben_res;
 	ColumnAccessor < mCFStaticData_0 > gaap_ben_res_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_cap_gain_cap;
 	ColumnAccessor < mCFStaticData_0 > gaap_cap_gain_res;
 	ColumnAccessor < mCFStaticData_0 > gaap_capzd_acq_exp;
 	ColumnAccessor < mCFStaticData_0 > gaap_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_0 > gaap_capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_0 > gaap_capzd_prem_bonus;
 	ColumnAccessor < mCFStaticData_0 > gaap_capzd_reins_yrt_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_cash_flow_int;
 	ColumnAccessor < mCFStaticData_0 > gaap_chg_inc;
 	ColumnAccessor < mCFStaticData_0 > gaap_claim_res;
 	ColumnAccessor < mCFStaticData_0 > gaap_claim_res_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_0 > gaap_comm_excess_eom;
 	ColumnAccessor < mCFStaticData_0 > gaap_comm_trail_bom;
 	ColumnAccessor < mCFStaticData_0 > gaap_comm_trail_eom;
 	ColumnAccessor < mCFStaticData_0 > gaap_conversion_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_credited_int;
 	ColumnAccessor < mCFStaticData_0 > gaap_dac;
 	ColumnAccessor < mCFStaticData_0 > gaap_dac_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_deferred_maint_exp;
 	ColumnAccessor < mCFStaticData_0 > gaap_deferred_prof_liab;
 	ColumnAccessor < mCFStaticData_0 > gaap_deferred_prof_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_deferred_tax_liab;
 	ColumnAccessor < mCFStaticData_0 > gaap_deferred_tax_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_div_applied;
 	ColumnAccessor < mCFStaticData_0 > gaap_div_liab;
 	ColumnAccessor < mCFStaticData_0 > gaap_div_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_div_paid;
 	ColumnAccessor < mCFStaticData_0 > gaap_dth_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_endow_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_free_surp;
 	ColumnAccessor < mCFStaticData_0 > gaap_gross_prem;
 	ColumnAccessor < mCFStaticData_0 > gaap_hedge_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > gaap_hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_hlth_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_aft_tax;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_aft_tax_qtd;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_aft_tax_ytd;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_bef_tax;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_bef_tax_qtd;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_bef_tax_ytd;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_ben_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_deferred_tax_liab;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_inv_asset;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_unrealzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > gaap_inc_unrealzd_cap_gain_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_inv_asset;
 	ColumnAccessor < mCFStaticData_0 > gaap_inv_asset_available;
 	ColumnAccessor < mCFStaticData_0 > gaap_inv_asset_held;
 	ColumnAccessor < mCFStaticData_0 > gaap_inv_asset_not_assigned;
 	ColumnAccessor < mCFStaticData_0 > gaap_inv_asset_trading;
 	ColumnAccessor < mCFStaticData_0 > gaap_inv_inc_cap;
 	ColumnAccessor < mCFStaticData_0 > gaap_inv_inc_res;
 	ColumnAccessor < mCFStaticData_0 > gaap_liab_net;
 	ColumnAccessor < mCFStaticData_0 > gaap_liab_net_net;
 	ColumnAccessor < mCFStaticData_0 > gaap_loads_deducted;
 	ColumnAccessor < mCFStaticData_0 > gaap_loads_deferred;
 	ColumnAccessor < mCFStaticData_0 > gaap_loc_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_0 > gaap_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_0 > gaap_maint_exp_res;
 	ColumnAccessor < mCFStaticData_0 > gaap_maint_exp_res_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_maturity_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_prem_bonus;
 	ColumnAccessor < mCFStaticData_0 > gaap_prem_tax;
 	ColumnAccessor < mCFStaticData_0 > gaap_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_0 > gaap_prem_waiver_res_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_prof_aft_tax_for_pv;
 	ColumnAccessor < mCFStaticData_0 > gaap_prof_bef_tax_for_pv;
 	ColumnAccessor < mCFStaticData_0 > gaap_reins_yrt_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_req_cap;
 	ColumnAccessor < mCFStaticData_0 > gaap_sfas133_liab;
 	ColumnAccessor < mCFStaticData_0 > gaap_sfas133_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_sop031_addl_liab;
 	ColumnAccessor < mCFStaticData_0 > gaap_sop031_addl_liab_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_surp_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_surp_unrealzd_cap_gain;
 	ColumnAccessor < mCFStaticData_0 > gaap_surp_unrealzd_cap_gain_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_surr_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > gaap_surr_inc;
 	ColumnAccessor < mCFStaticData_0 > gaap_terminal_div;
 	ColumnAccessor < mCFStaticData_0 > gaap_unearn_rev_liab;
 	ColumnAccessor < mCFStaticData_0 > gaap_unearn_rev_released;
 	ColumnAccessor < mCFStaticData_0 > gaap_unrealzd_cap_gain_incr;
 	ColumnAccessor < mCFStaticData_0 > gaap_withdrl_ben_claim_cost;
 	ColumnAccessor < mCFStaticData_0 > gamma_hedge_inv_amt;
 	ColumnAccessor < mCFStaticData_0 > gamma_hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_0 > gamma_hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_0 > gamma_hedge_pmt;
 	ColumnAccessor < mCFStaticData_256 > gamma_hedge_prof;
 	ColumnAccessor < mCFStaticData_256 > gamma_hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_256 > gamma_hedge_transaction_cost;
 	ColumnAccessor < mCFStaticData_256 > gmwb_chg;
 	ColumnAccessor < mCFStaticData_256 > gmwb_inf;
 	ColumnAccessor < mCFStaticData_256 > gross_prem_annualzd;
 	ColumnAccessor < mCFStaticData_256 > hedge_cash_flow;
 	ColumnAccessor < mCFStaticData_256 > hedge_cost;
 	ColumnAccessor < mCFStaticData_256 > hedge_cost_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > hedge_cost_charge;
 	ColumnAccessor < mCFStaticData_256 > hedge_exp;
 	ColumnAccessor < mCFStaticData_256 > hedge_int_pmt;
 	ColumnAccessor < mCFStaticData_256 > hedge_inv_amt_bom;
 	ColumnAccessor < mCFStaticData_256 > hedge_inv_amt_eom;
 	ColumnAccessor < mCFStaticData_256 > hedge_liab_claims;
 	ColumnAccessor < mCFStaticData_256 > hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_256 > hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_256 > hedge_opt_pmt;
 	ColumnAccessor < mCFStaticData_256 > hedge_rila_trading_cost_aig;
 	ColumnAccessor < mCFStaticData_256 > hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_256 > imr;
 	ColumnAccessor < mCFStaticData_256 > imr_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > imr_impact_free_surp;
 	ColumnAccessor < mCFStaticData_256 > imr_impact_free_surp_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > imr_impact_res;
 	ColumnAccessor < mCFStaticData_256 > imr_impact_res_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > imr_impact_tgt_cap;
 	ColumnAccessor < mCFStaticData_256 > imr_impact_tgt_cap_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > imr_incr;
 	ColumnAccessor < mCFStaticData_256 > imr_incr_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > initialize;
 	ColumnAccessor < mCFStaticData_256 > int_pmt;
 	ColumnAccessor < mCFStaticData_256 > interim_cash;
 	ColumnAccessor < mCFStaticData_256 > interim_cash_int;
 	ColumnAccessor < mCFStaticData_256 > inv_asset;
 	ColumnAccessor < mCFStaticData_256 > inv_cash_flow_int_div_and_rent;
 	ColumnAccessor < mCFStaticData_256 > inv_cash_flow_prin_pmt;
 	ColumnAccessor < mCFStaticData_256 > inv_exp;
 	ColumnAccessor < mCFStaticData_256 > inv_fee_ref;
 	ColumnAccessor < mCFStaticData_256 > inv_inc;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_bk_prof;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_bk_prof_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_earnings_accum;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_free_surp;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_fund;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_on_invested_assets;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_res;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_tgt_cap;
 	ColumnAccessor < mCFStaticData_256 > inv_inc_undistrib_earnings;
 	ColumnAccessor < mCFStaticData_256 > invested_asset_sale;
 	ColumnAccessor < mCFStaticData_256 > irr;
 	ColumnAccessor < mCFStaticData_256 > irr2_aig;
 	ColumnAccessor < mCFStaticData_256 > irr_wo_tgt_cap;
 	ColumnAccessor < mCFStaticData_256 > lapse_count_aig;
 	ColumnAccessor < mCFStaticData_256 > last_period_indicator;
 	ColumnAccessor < mCFStaticData_256 > liab_and_surp;
 	ColumnAccessor < mCFStaticData_256 > liab_cash_flow;
 	ColumnAccessor < mCFStaticData_256 > liab_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > liab_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_256 > loc_asset;
 	ColumnAccessor < mCFStaticData_256 > loc_asset_incr;
 	ColumnAccessor < mCFStaticData_256 > loc_cost;
 	ColumnAccessor < mCFStaticData_256 > maint_exp_bom;
 	ColumnAccessor < mCFStaticData_256 > maint_exp_eom;
 	ColumnAccessor < mCFStaticData_256 > maturity_benefits;
 	ColumnAccessor < mCFStaticData_256 > mkt_val;
 	ColumnAccessor < mCFStaticData_256 > mkt_val_sale;
 	ColumnAccessor < mCFStaticData_256 > notional_amt;
 	ColumnAccessor < mCFStaticData_256 > opt_budget_amt;
 	ColumnAccessor < mCFStaticData_256 > opt_inc;
 	ColumnAccessor < mCFStaticData_256 > opt_payoff_aig;
 	ColumnAccessor < mCFStaticData_256 > opt_pmt;
 	ColumnAccessor < mCFStaticData_256 > pol_loan;
 	ColumnAccessor < mCFStaticData_256 > pol_loan_exp;
 	ColumnAccessor < mCFStaticData_256 > pol_loan_inc;
 	ColumnAccessor < mCFStaticData_256 > pol_loan_int;
 	ColumnAccessor < mCFStaticData_256 > pol_loan_proceeds;
 	ColumnAccessor < mCFStaticData_256 > pol_mth_aig;
 	ColumnAccessor < mCFStaticData_256 > pol_yr_aig;
 	ColumnAccessor < mCFStaticData_256 > policies_inf;
 	ColumnAccessor < mCFStaticData_256 > policies_issued;
 	ColumnAccessor < mCFStaticData_256 > port_yld;
 	ColumnAccessor < mCFStaticData_256 > port_yld_aft_tax;
 	ColumnAccessor < mCFStaticData_256 > port_yld_denom;
 	ColumnAccessor < mCFStaticData_256 > port_yld_less_dflt;
 	ColumnAccessor < mCFStaticData_256 > prem_bonus;
 	ColumnAccessor < mCFStaticData_256 > prem_issued;
 	ColumnAccessor < mCFStaticData_256 > prem_paid;
 	ColumnAccessor < mCFStaticData_256 > prem_tax;
 	ColumnAccessor < mCFStaticData_256 > prem_waiver_benefits;
 	ColumnAccessor < mCFStaticData_256 > proj_tgt_hedge_stmt;
 	ColumnAccessor < mCFStaticData_256 > proxy_bond_generation;
 	ColumnAccessor < mCFStaticData_256 > rbc;
 	ColumnAccessor < mCFStaticData_256 > rbc_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > rbc_c1;
 	ColumnAccessor < mCFStaticData_256 > rbc_c1_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > rbc_c1_eqt;
 	ColumnAccessor < mCFStaticData_256 > rbc_c1_eqt_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > rbc_c2;
 	ColumnAccessor < mCFStaticData_256 > rbc_c3;
 	ColumnAccessor < mCFStaticData_256 > rbc_c4;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_free_surp;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_free_surp_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_free_surp_ytd;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_free_surp_ytd_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_fund;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_res;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_res_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_res_ytd;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_res_ytd_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_sale;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_tgt_cap;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_tgt_cap_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_tgt_cap_ytd;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_tgt_cap_ytd_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_undistrib_earnings;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_undistrib_earnings_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_undistrib_earnings_ytd;
 	ColumnAccessor < mCFStaticData_256 > realzd_cap_gain_undistrib_earnings_ytd_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > reins_ann_benefits_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_ann_benefits_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_cap_gain_res;
 	ColumnAccessor < mCFStaticData_256 > reins_cap_gain_res_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > reins_cash_flow_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_cash_flow_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_cash_flow_int;
 	ColumnAccessor < mCFStaticData_256 > reins_cash_val;
 	ColumnAccessor < mCFStaticData_256 > reins_claim_paid;
 	ColumnAccessor < mCFStaticData_256 > reins_comm_chargeback_reimb;
 	ColumnAccessor < mCFStaticData_256 > reins_comm_reimb;
 	ColumnAccessor < mCFStaticData_256 > reins_comm_reimb_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_comm_reimb_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_deferred_gross_prem;
 	ColumnAccessor < mCFStaticData_256 > reins_deferred_gross_prem_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_deferred_net_prem;
 	ColumnAccessor < mCFStaticData_256 > reins_div_applied;
 	ColumnAccessor < mCFStaticData_256 > reins_div_liab;
 	ColumnAccessor < mCFStaticData_256 > reins_div_liab_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_div_paid;
 	ColumnAccessor < mCFStaticData_256 > reins_dth_ben_inf;
 	ColumnAccessor < mCFStaticData_256 > reins_dth_benefits;
 	ColumnAccessor < mCFStaticData_256 > reins_ea;
 	ColumnAccessor < mCFStaticData_256 > reins_ea_chargeback;
 	ColumnAccessor < mCFStaticData_256 > reins_endow_benefits;
 	ColumnAccessor < mCFStaticData_256 > reins_exp;
 	ColumnAccessor < mCFStaticData_256 > reins_exp_reimb;
 	ColumnAccessor < mCFStaticData_256 > reins_exp_reimb_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_exp_reimb_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_ben_res;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_ben_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_cap_gain_res;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_capzd_comm_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_capzd_comm_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_capzd_prem_bonus;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_cash_flow_int;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_chg_inc;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_claim_res;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_claim_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_comm_excess_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_comm_excess_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_comm_trail_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_comm_trail_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_cost;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_credited_int;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_dac;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_dac_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_deferred_maint_exp;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_deferred_prof_liab;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_deferred_prof_liab_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_div_applied;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_div_liab;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_div_liab_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_div_paid;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_dth_claim_cost;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_inv_inc_res;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_liab_net;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_loads_deducted;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_loads_deferred;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_maint_exp_bom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_maint_exp_eom;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_maint_exp_res;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_maint_exp_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_modco_liab;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_modco_liab_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_modco_res_adj;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_prem;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_prem_bonus;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_prem_tax;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_prem_waiver_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_recoveries;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_refund;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_sfas133_liab;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_sfas133_liab_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_sop031_addl_liab;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_sop031_addl_liab_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_surr_inc;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_terminal_div;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_unearn_rev_liab;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_unearn_rev_released;
 	ColumnAccessor < mCFStaticData_256 > reins_gaap_unrealzd_cap_gain_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_imr_impact_res;
 	ColumnAccessor < mCFStaticData_256 > reins_imr_impact_res_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > reins_inv_fee_ref;
 	ColumnAccessor < mCFStaticData_256 > reins_inv_inc_res;
 	ColumnAccessor < mCFStaticData_256 > reins_maturity_benefits;
 	ColumnAccessor < mCFStaticData_256 > reins_modco_res_adj;
 	ColumnAccessor < mCFStaticData_256 > reins_prem;
 	ColumnAccessor < mCFStaticData_256 > reins_prem_tax;
 	ColumnAccessor < mCFStaticData_256 > reins_prem_waiver_benefits;
 	ColumnAccessor < mCFStaticData_256 > reins_realzd_cap_gain_res;
 	ColumnAccessor < mCFStaticData_256 > reins_realzd_cap_gain_res_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > reins_realzd_cap_gain_res_ytd;
 	ColumnAccessor < mCFStaticData_256 > reins_realzd_cap_gain_res_ytd_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > reins_ref;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_claim_res;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_claim_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_cost;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_cost_bef_sale;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_loading;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_loading_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_prem_waiver_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_res;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_unearn_prem_res;
 	ColumnAccessor < mCFStaticData_256 > reins_stat_unearn_prem_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_surr_benefits;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_claim_res;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_claim_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_deferred_net_prem;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_div_liab;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_div_liab_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_loading;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_loading_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_prem_waiver_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_res;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_unearn_prem_res;
 	ColumnAccessor < mCFStaticData_256 > reins_tax_unearn_prem_res_incr;
 	ColumnAccessor < mCFStaticData_256 > reins_terminal_div;
 	ColumnAccessor < mCFStaticData_256 > reins_withdrl_benefits;
 	ColumnAccessor < mCFStaticData_256 > rho_convex_hedge_inv_amt;
 	ColumnAccessor < mCFStaticData_256 > rho_convex_hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_256 > rho_convex_hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_256 > rho_convex_hedge_pmt;
 	ColumnAccessor < mCFStaticData_256 > rho_convex_hedge_prof;
 	ColumnAccessor < mCFStaticData_256 > rho_convex_hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_256 > rho_convex_hedge_transaction_cost;
 	ColumnAccessor < mCFStaticData_256 > rho_hedge_inv_amt;
 	ColumnAccessor < mCFStaticData_256 > rho_hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_256 > rho_hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_256 > rho_hedge_pmt;
 	ColumnAccessor < mCFStaticData_512 > rho_hedge_prof;
 	ColumnAccessor < mCFStaticData_512 > rho_hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_512 > rho_hedge_transaction_cost;
 	ColumnAccessor < mCFStaticData_512 > risk_free_rate_no_sprd_aig;
 	ColumnAccessor < mCFStaticData_512 > risk_free_rate_with_ic_uel_sprd_aig;
 	ColumnAccessor < mCFStaticData_512 > risk_free_rate_with_no_uel_sprd_aig;
 	ColumnAccessor < mCFStaticData_512 > risk_free_rate_with_uel_sprd_aig;
 	ColumnAccessor < mCFStaticData_512 > sale_inc;
 	ColumnAccessor < mCFStaticData_512 > sched_prin_pmt;
 	ColumnAccessor < mCFStaticData_512 > shldr_div;
 	ColumnAccessor < mCFStaticData_512 > startup;
 	ColumnAccessor < mCFStaticData_512 > stat_claim_exp_res;
 	ColumnAccessor < mCFStaticData_512 > stat_claim_exp_res_incr;
 	ColumnAccessor < mCFStaticData_512 > stat_claim_incurred;
 	ColumnAccessor < mCFStaticData_512 > stat_claim_res;
 	ColumnAccessor < mCFStaticData_512 > stat_claim_res_incr;
 	ColumnAccessor < mCFStaticData_512 > stat_loading;
 	ColumnAccessor < mCFStaticData_512 > stat_loading_incr;
 	ColumnAccessor < mCFStaticData_512 > stat_prem_waiver_exp_res;
 	ColumnAccessor < mCFStaticData_512 > stat_prem_waiver_exp_res_incr;
 	ColumnAccessor < mCFStaticData_512 > stat_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_512 > stat_prem_waiver_res_incr;
 	ColumnAccessor < mCFStaticData_512 > stat_res;
 	ColumnAccessor < mCFStaticData_512 > stat_res_carvm_base_aig;
 	ColumnAccessor < mCFStaticData_512 > stat_res_carvm_wb_aig;
 	ColumnAccessor < mCFStaticData_512 > stat_res_excess;
 	ColumnAccessor < mCFStaticData_512 > stat_res_incr;
 	ColumnAccessor < mCFStaticData_512 > stat_res_mp;
 	ColumnAccessor < mCFStaticData_512 > stat_res_sa;
 	ColumnAccessor < mCFStaticData_512 > stat_res_sa_exp_allow;
 	ColumnAccessor < mCFStaticData_512 > stat_res_xol_carvm_aig;
 	ColumnAccessor < mCFStaticData_512 > stat_res_xol_excess_res_aig;
 	ColumnAccessor < mCFStaticData_512 > stat_res_xol_nb_eco_res_aig;
 	ColumnAccessor < mCFStaticData_512 > stat_res_xol_pv_nb_ending_amount_aig;
 	ColumnAccessor < mCFStaticData_512 > stat_unearn_prem_res;
 	ColumnAccessor < mCFStaticData_512 > stat_unearn_prem_res_incr;
 	ColumnAccessor < mCFStaticData_512 > surr_benefits;
 	ColumnAccessor < mCFStaticData_512 > tax;
 	ColumnAccessor < mCFStaticData_512 > tax_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > tax_bk_prof;
 	ColumnAccessor < mCFStaticData_512 > tax_bk_prof_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > tax_bk_prof_ytd;
 	ColumnAccessor < mCFStaticData_512 > tax_bk_prof_ytd_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > tax_capzd_prem;
 	ColumnAccessor < mCFStaticData_512 > tax_capzd_prem_amortzn;
 	ColumnAccessor < mCFStaticData_512 > tax_capzd_prem_unamortzd;
 	ColumnAccessor < mCFStaticData_512 > tax_claim_exp_res;
 	ColumnAccessor < mCFStaticData_512 > tax_claim_res;
 	ColumnAccessor < mCFStaticData_512 > tax_claim_res_incr;
 	ColumnAccessor < mCFStaticData_512 > tax_deferred_net_prem;
 	ColumnAccessor < mCFStaticData_512 > tax_div_liab;
 	ColumnAccessor < mCFStaticData_512 > tax_div_liab_incr;
 	ColumnAccessor < mCFStaticData_512 > tax_earnings_accum;
 	ColumnAccessor < mCFStaticData_512 > tax_earnings_accum_ytd;
 	ColumnAccessor < mCFStaticData_512 > tax_exempt_inc;
 	ColumnAccessor < mCFStaticData_512 > tax_exempt_inc_bk_prof;
 	ColumnAccessor < mCFStaticData_512 > tax_exempt_inc_free_surp;
 	ColumnAccessor < mCFStaticData_512 > tax_exempt_inc_tgt_cap;
 	ColumnAccessor < mCFStaticData_512 > tax_free_surp;
 	ColumnAccessor < mCFStaticData_512 > tax_free_surp_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > tax_free_surp_ytd;
 	ColumnAccessor < mCFStaticData_512 > tax_free_surp_ytd_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > tax_loading;
 	ColumnAccessor < mCFStaticData_512 > tax_loading_incr;
 	ColumnAccessor < mCFStaticData_512 > tax_prem_waiver_exp_res;
 	ColumnAccessor < mCFStaticData_512 > tax_prem_waiver_res;
 	ColumnAccessor < mCFStaticData_512 > tax_prem_waiver_res_incr;
 	ColumnAccessor < mCFStaticData_512 > tax_res;
 	ColumnAccessor < mCFStaticData_512 > tax_res_incr;
 	ColumnAccessor < mCFStaticData_512 > tax_tgt_cap;
 	ColumnAccessor < mCFStaticData_512 > tax_tgt_cap_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > tax_tgt_cap_ytd;
 	ColumnAccessor < mCFStaticData_512 > tax_tgt_cap_ytd_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > tax_transfer_to_sa_net;
 	ColumnAccessor < mCFStaticData_512 > tax_unearn_prem_res;
 	ColumnAccessor < mCFStaticData_512 > tax_unearn_prem_res_incr;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_addn;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_bk_prof;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_bk_prof_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_bk_prof_ytd;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_bk_prof_ytd_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_carryfwd_addn_ytd;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_carryfwd_applied_ytd;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_carryfwd_avail;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_earnings_accum;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_earnings_accum_ytd;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_free_surp;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_free_surp_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_free_surp_ytd;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_free_surp_ytd_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_tgt_cap;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_tgt_cap_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_tgt_cap_ytd;
 	ColumnAccessor < mCFStaticData_512 > taxable_inc_tgt_cap_ytd_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > terminal_div;
 	ColumnAccessor < mCFStaticData_512 > tgt_cap;
 	ColumnAccessor < mCFStaticData_512 > tgt_cap_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > tgt_cap_effect;
 	ColumnAccessor < mCFStaticData_512 > tgt_cap_effect_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > tgt_cap_incr;
 	ColumnAccessor < mCFStaticData_512 > tgt_cap_incr_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > transfer_cash_flow_sa_bom;
 	ColumnAccessor < mCFStaticData_512 > transfer_cash_flow_sa_eom;
 	ColumnAccessor < mCFStaticData_512 > transfer_to_sa_net;
 	ColumnAccessor < mCFStaticData_512 > undistrib_earnings;
 	ColumnAccessor < mCFStaticData_512 > unrealzd_cap_gain_incr;
 	ColumnAccessor < mCFStaticData_512 > unrealzd_cap_gain_incr_bef_sale;
 	ColumnAccessor < mCFStaticData_512 > unrealzd_cap_gain_released_on_sale;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_ag38_8d;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_gaap_sfas120;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_gaap_sfas91;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_gaap_sfas97rd;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_gaap_sop031;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_hedge_final;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_hedge_shock;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_pba_pol_res;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_pba_rbc_std_scen_step2;
 	ColumnAccessor < mCFStaticData_512 > valn_tgt_pba_scen_amt;
 	ColumnAccessor < mCFStaticData_512 > vega_hedge_inv_amt;
 	ColumnAccessor < mCFStaticData_512 > vega_hedge_mkt_val;
 	ColumnAccessor < mCFStaticData_512 > vega_hedge_mkt_val_incr;
 	ColumnAccessor < mCFStaticData_512 > vega_hedge_pmt;
 	ColumnAccessor < mCFStaticData_512 > vega_hedge_prof;
 	ColumnAccessor < mCFStaticData_512 > vega_hedge_sale_amt;
 	ColumnAccessor < mCFStaticData_512 > vega_hedge_transaction_cost;
 	ColumnAccessor < mCFStaticData_512 > withdrl_benefits;
 	ColumnAccessor < mCFStaticData_512 > xol_amount_aig;
 	ColumnAccessor < mCFStaticData_512 > xol_prem_aig;
//Column Definition END@2

 // Temporary Table...
ASSET_ASSET *sm_asset;
_1D_INVSTRAT_ASSET sm_inv_strategy;
LIAB_LIAB *sm_liab;
RATES_ECONOMY *sm_rates;
_1D_SEG_COMP sm_seg;
COMP_COMP *sm_bond_is;
COMP_COMP *sm_bond_pv;
COMP_COMP *sm_bond_ym;
COMP_COMP *sm_mtg_is;
COMP_COMP *sm_mtg_pv;
COMP_COMP *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE COMP_COMP::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > assets_defn;
  inline xstring	Get_assets_defn() {
		return assets_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > avr_amortzn_sch;
  inline double	Get_avr_amortzn_sch() {
		return avr_amortzn_sch; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > avr_defn;
  inline xstring	Get_avr_defn() {
		return avr_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > avr_detail_log_final_period;
  inline int	Get_avr_detail_log_final_period() {
		return avr_detail_log_final_period; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > avr_detail_log_start_period;
  inline int	Get_avr_detail_log_start_period() {
		return avr_detail_log_start_period; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > avr_neg_defn;
  inline xstring	Get_avr_neg_defn() {
		return avr_neg_defn; }
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
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > company_assump_set_id;
  inline xstring	Get_company_assump_set_id() {
		return company_assump_set_id; }
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > distribn_pct_distrib_earnings;
  inline double	Get_distribn_pct_distrib_earnings() {
		return distribn_pct_distrib_earnings; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > distribn_pct_free_surp;
  inline double	Get_distribn_pct_free_surp() {
		return distribn_pct_free_surp; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > gaap_assump_set_id;
  inline xstring	Get_gaap_assump_set_id() {
		return gaap_assump_set_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gaap_defn;
  inline xstring	Get_gaap_defn() {
		return gaap_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > imr_amortzn_pct_bond;
  inline double	Get_imr_amortzn_pct_bond() {
		return imr_amortzn_pct_bond; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > imr_amortzn_pct_mtg;
  inline double	Get_imr_amortzn_pct_mtg() {
		return imr_amortzn_pct_mtg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > imr_amortzn_pct_other;
  inline double	Get_imr_amortzn_pct_other() {
		return imr_amortzn_pct_other; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > imr_defn;
  inline xstring	Get_imr_defn() {
		return imr_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > independent_mp_defn;
  inline xstring	Get_independent_mp_defn() {
		return independent_mp_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > init_free_surp_input;
  inline double	Get_init_free_surp_input() {
		return init_free_surp_input; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > loc_assump_set_id;
  inline xstring	Get_loc_assump_set_id() {
		return loc_assump_set_id; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > pba_assump_set_id;
  inline xstring	Get_pba_assump_set_id() {
		return pba_assump_set_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > pricing_defn;
  inline xstring	Get_pricing_defn() {
		return pricing_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > prof_distribn_mode;
  inline xstring	Get_prof_distribn_mode() {
		return prof_distribn_mode; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c1_cash_pct;
  inline double	Get_rbc_c1_cash_pct() {
		return rbc_c1_cash_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c1_concentration_mult_eqt;
  inline double	Get_rbc_c1_concentration_mult_eqt() {
		return rbc_c1_concentration_mult_eqt; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c1_concentration_mult_other;
  inline double	Get_rbc_c1_concentration_mult_other() {
		return rbc_c1_concentration_mult_other; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c1_liab_only_stat_res_pct;
  inline double	Get_rbc_c1_liab_only_stat_res_pct() {
		return rbc_c1_liab_only_stat_res_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c1_port_size_mult;
  inline double	Get_rbc_c1_port_size_mult() {
		return rbc_c1_port_size_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c1_reins_res_pct;
  inline double	Get_rbc_c1_reins_res_pct() {
		return rbc_c1_reins_res_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c2_morbid_claim_pct;
  inline double	Get_rbc_c2_morbid_claim_pct() {
		return rbc_c2_morbid_claim_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c2_morbid_prem_pct;
  inline double	Get_rbc_c2_morbid_prem_pct() {
		return rbc_c2_morbid_prem_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c2_morbid_res_pct;
  inline double	Get_rbc_c2_morbid_res_pct() {
		return rbc_c2_morbid_res_pct; }
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c3_life_pct;
  inline double	Get_rbc_c3_life_pct() {
		return rbc_c3_life_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c4_prem_pct;
  inline double	Get_rbc_c4_prem_pct() {
		return rbc_c4_prem_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > rbc_c4_sa_pct;
  inline double	Get_rbc_c4_sa_pct() {
		return rbc_c4_sa_pct; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > sa_res_defn;
  inline xstring	Get_sa_res_defn() {
		return sa_res_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > segments_selected;
  inline xstring	Get_segments_selected() {
		return segments_selected; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tax_addl_res_ag38_8d_defn;
  inline xstring	Get_tax_addl_res_ag38_8d_defn() {
		return tax_addl_res_ag38_8d_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tax_deductible_pct_of_stat_div_liab;
  inline double	Get_tax_deductible_pct_of_stat_div_liab() {
		return tax_deductible_pct_of_stat_div_liab; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tax_loss_treatment;
  inline xstring	Get_tax_loss_treatment() {
		return tax_loss_treatment; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tax_rate;
  inline double	Get_tax_rate() {
		return tax_rate; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tax_rate_cap_gain;
  inline double	Get_tax_rate_cap_gain() {
		return tax_rate_cap_gain; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > taxable_inc_addn_unamortzd;
  inline double	Get_taxable_inc_addn_unamortzd() {
		return taxable_inc_addn_unamortzd; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > tgt_cap_defn;
  inline xstring	Get_tgt_cap_defn() {
		return tgt_cap_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > tgt_cap_rbc_mult;
  inline double	Get_tgt_cap_rbc_mult() {
		return tgt_cap_rbc_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > time_step_defn;
  inline xstring	Get_time_step_defn() {
		return time_step_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > valn_periods_selected;
  inline xstring	Get_valn_periods_selected() {
		return valn_periods_selected; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > valn_yrs;
  inline int	Get_valn_yrs() {
		return valn_yrs; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > yrs_aft_sale;
  inline int	Get_yrs_aft_sale() {
		return yrs_aft_sale; }
  inline void Set_yrs_aft_sale(const int &v) {
		yrs_aft_sale.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > yrs_to_maturity;
  inline int	Get_yrs_to_maturity() {
		return yrs_to_maturity; }
  inline void Set_yrs_to_maturity(const int &v) {
		yrs_to_maturity.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > elapsed_mths_aig;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > final_period;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > prod_type_indicator;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > proj_date_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_date;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_yr;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > reins_flag;
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
 void passDataVariables(COMP_COMP* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// AVR Calculation
#line 1 "avr_calc.comp_comp.for"
double avr_calc(int t, const xstring & sales_timing, const xstring & calc_type);

// Get Competitor Rate
#line 1 "get_comp_rate.comp_comp.for"
double get_comp_rate(xstring cr_id, int t);

// Internal Rate of Return Calculation
#line 1 "irr_calc.comp_comp.for"
double irr_calc(const xstring &roi_type);

// Read State of World Financial
#line 1 "read_state_of_world_financial.comp_comp.for"
void read_state_of_world_financial(void);

// Setup Hedge Projection Shock Lists
#line 1 "setup_hedge_proj_shock_lists.comp_comp.for"
void setup_hedge_proj_shock_lists(void);

// Setup Hedge Valuation Shock List
#line 1 "setup_hedge_valn_shock_list.comp_comp.for"
void setup_hedge_valn_shock_list(void);

// Sum Over Segments
#line 1 "sum_over_segments.comp_comp.for"
double sum_over_segments(const xstring &colname, int t, int segment_type);

// Write State of World Financial
#line 1 "write_state_of_world_financial.comp_comp.for"
void write_state_of_world_financial(void);


//factory
static COMP_COMP* makeThis(int isSubmodel, ModelClass *owner, COMP_COMP* peer, 
					int mainRebase, const xstring &name, COMP_COMP_persistent_object* arrayTemplate);

//constructor
COMP_COMP(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
COMP_COMP(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~COMP_COMP();


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
class COMP_COMP_persistent_object : public COMP_COMP {


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

	void findTargetColumns() {COMP_COMP::findTargetColumns();}
	void createAllShare() {
		COMP_COMP::createAllShare();
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
	ASSET_ASSET *&sm_asset; //
	_1D_INVSTRAT_ASSET &sm_inv_strategy; //
	LIAB_LIAB *&sm_liab; //
	RATES_ECONOMY *&sm_rates; //
	_1D_SEG_COMP &sm_seg; //
	COMP_COMP *&sm_bond_is; //
	COMP_COMP *&sm_bond_pv; //
	COMP_COMP *&sm_bond_ym; //
	COMP_COMP *&sm_mtg_is; //
	COMP_COMP *&sm_mtg_pv; //
	COMP_COMP *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~COMP_COMP_persistent_object();

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
static COMP_COMP_persistent_object* makeThis(int isSubmodel, ModelClass *owner, COMP_COMP* peer, 
					int mainRebase, const xstring &name, COMP_COMP_persistent_object* arrayTemplate, bool fixedArray);

//constructor
COMP_COMP_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
