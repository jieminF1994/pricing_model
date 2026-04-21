#ifndef __MTG_CF_ASSET_H_
#define __MTG_CF_ASSET_H_
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



namespace MTG_CF_ASSET_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class MTG_CF_ASSET_persistent_object;
class MTG_CF_ASSET : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(MTG_CF_ASSET); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;

int adco_arm_mths_to_reset;
double adco_arm_pay_rate;

	void init_(){
		

adco_arm_mths_to_reset = 0;
adco_arm_pay_rate = 0;

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
 // Column Definition Begins
 	ColumnAccessor < mCFStaticData_0 > accr_int;
 	ColumnAccessor < mCFStaticData_0 > accr_int_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > accr_int_aft_prepmt;
 	ColumnAccessor < mCFStaticData_0 > accr_int_bef_prepmt;
 	ColumnAccessor < mCFStaticData_0 > accr_int_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > adco_prepmt_forecast;
 	ColumnAccessor < mCFStaticData_0 > balloon_pmt;
 	ColumnAccessor < mCFStaticData_0 > balloon_pmt_inc;
 	ColumnAccessor < mCFStaticData_0 > int_pmt;
 	ColumnAccessor < mCFStaticData_0 > int_savings_pv_aft_prepmt;
 	ColumnAccessor < mCFStaticData_0 > int_savings_pv_bef_prepmt;
 	ColumnAccessor < mCFStaticData_0 > intex_pmt_processed;
 	ColumnAccessor < mCFStaticData_0 > mths_since_issue;
 	ColumnAccessor < mCFStaticData_0 > par_val;
 	ColumnAccessor < mCFStaticData_0 > par_val_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > par_val_aft_prepmt;
 	ColumnAccessor < mCFStaticData_0 > par_val_aft_sched_pmt;
 	ColumnAccessor < mCFStaticData_0 > par_val_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > par_val_for_balloon_pmt_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > par_val_for_balloon_pmt_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > pmt_amt_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > pmt_amt_aft_sched_payment;
 	ColumnAccessor < mCFStaticData_0 > pmt_amt_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > pmt_rate;
 	ColumnAccessor < mCFStaticData_0 > prepmt_amt;
 	ColumnAccessor < mCFStaticData_0 > prepmt_inc;
 	ColumnAccessor < mCFStaticData_0 > prepmt_pct;
 	ColumnAccessor < mCFStaticData_0 > prepmt_pct_mthly;
 	ColumnAccessor < mCFStaticData_0 > prepmt_penalty;
 	ColumnAccessor < mCFStaticData_0 > refinancing_rate;
 	ColumnAccessor < mCFStaticData_0 > remaining_pct_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > remaining_pct_aft_sched_pmt;
 	ColumnAccessor < mCFStaticData_0 > renewal_rate;
 	ColumnAccessor < mCFStaticData_0 > sched_prin_pmt;
 	ColumnAccessor < mCFStaticData_0 > since_foreclosure_int_mult;
 	ColumnAccessor < mCFStaticData_0 > since_foreclosure_prin_pmt_mult;
 	ColumnAccessor < mCFStaticData_0 > since_restructure_int_mult;
 	ColumnAccessor < mCFStaticData_0 > since_restructure_prin_pmt_mult;
 	ColumnAccessor < mCFStaticData_0 > startup;
 	ColumnAccessor < mCFStaticData_0 > tranche_portion;
 	ColumnAccessor < mCFStaticData_0 > tranche_portion_aft_dflt;
 	ColumnAccessor < mCFStaticData_0 > tranche_portion_bef_sale;
 	ColumnAccessor < mCFStaticData_0 > yld_maint_cash_flow_pct_bef_prepmt;
 	ColumnAccessor < mCFStaticData_0 > yld_maint_cost_pct;
 	ColumnAccessor < mCFStaticData_0 > yld_maint_rate;
//Column Definition END@2

 // Temporary Table...
MTG_CF_ASSET *sm_mtg_is;
MTG_CF_ASSET *sm_mtg_pv;
MTG_CF_ASSET *sm_mtg_ym;
MTG_CF_ASSET *sm_bond_is;
MTG_CF_ASSET *sm_bond_pv;
MTG_CF_ASSET *sm_bond_ym;
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
	#define DESCRIPTOR_TABLE MTG_CF_ASSET::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > dflt_appl;
  inline xstring	Get_dflt_appl() {
		return dflt_appl; }
  inline void Set_dflt_appl(const xstring &v) {
		dflt_appl.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > prepmt_appl;
  inline xstring	Get_prepmt_appl() {
		return prepmt_appl; }
  inline void Set_prepmt_appl(const xstring &v) {
		prepmt_appl.setValue(v); }
	Attribute::Proxy <SimpleArray<double>, DESCRIPTOR_TABLE > prepmt_rate;

    inline void Set_prepmt_rate(const SimpleArray<double> &v) {
		prepmt_rate.setValue(v); 
    } 
    inline SimpleArray<double>	Get_prepmt_rate() { 
		return prepmt_rate;
    }
	void Set_prepmt_rate(const long index, const double &value);
	inline double Get_prepmt_rate(const long index) const {
		return prepmt_rate.operator[] (index);
	}
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > pv_defn;
  inline xstring	Get_pv_defn() {
		return pv_defn; }
  inline void Set_pv_defn(const xstring &v) {
		pv_defn.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > pv_int_savings_pv_for_mkt_val_calc;
  inline double	Get_pv_int_savings_pv_for_mkt_val_calc() {
		return pv_int_savings_pv_for_mkt_val_calc; }
  inline void Set_pv_int_savings_pv_for_mkt_val_calc(const double &v) {
		pv_int_savings_pv_for_mkt_val_calc.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > pv_tbl_defn;
  inline xstring	Get_pv_tbl_defn() {
		return pv_tbl_defn; }
  inline void Set_pv_tbl_defn(const xstring &v) {
		pv_tbl_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > pv_timing;
  inline xstring	Get_pv_timing() {
		return pv_timing; }
  inline void Set_pv_timing(const xstring &v) {
		pv_timing.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > shift_defn;
  inline xstring	Get_shift_defn() {
		return shift_defn; }
  inline void Set_shift_defn(const xstring &v) {
		shift_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > use_spot_rates;
  inline xstring	Get_use_spot_rates() {
		return use_spot_rates; }
  inline void Set_use_spot_rates(const xstring &v) {
		use_spot_rates.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(MTG_CF_ASSET* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Accrrued Interest Direct Calculation
#line 1 "accr_int_direct.mtg_cf_asset.for"
double accr_int_direct(int t, double par_val, double pmt_rate);

// Cash Flow
#line 1 "cash_flow.mtg_cf_asset.for"
double cash_flow(int t);

// Forecast ADCo Adjustment Weighted Average Coupon Rate
#line 1 "forecast_adco_adj_wac_rate.mtg_cf_asset.for"
void forecast_adco_adj_wac_rate(int t);

// Present Value Calculation
#line 1 "pv_calc.mtg_cf_asset.for"
double pv_calc(int t, double spread_to_spot, double &calculated_derivative, double &calculated_modified_duration);

// Present Value Calculation Initial Value
#line 1 "pv_calc_init_val.mtg_cf_asset.for"
void pv_calc_init_val(int t);

// Present Value Calculation Parameters
#line 1 "pv_calc_parameters.mtg_cf_asset.for"
void pv_calc_parameters(int t, StrEnum::EnumValue command, int present_value_term = 0);

// Present Value Calculation Simple
#line 1 "pv_calc_simple.mtg_cf_asset.for"
double pv_calc_simple(int t, double nominal_yield, int months_to_maturity, double maturity_amount, double periodic_payment_amount, int pmt_freq, double accr_int, double &calculated_derivative, double &calculated_modified_duration);

// Present Value Simple Flag
#line 1 "pv_simple_flag.mtg_cf_asset.for"
bool pv_simple_flag(int t);

// Setup ADCo Submodel Parameters
#line 1 "setup_adco_submodel_parameters.mtg_cf_asset.for"
void setup_adco_submodel_parameters(int t);

// Solve for Spread Inverse Interpolation
#line 1 "solve_for_sprd_inverse_interp.mtg_cf_asset.for"
double solve_for_sprd_inverse_interp(int t, double guess_spread_low, double guess_value_high, double guess_spread_high, double guess_value_low, double target_value, double months_to_maturity, int solve_timing);

// Solve for Spread Newton Raphson
#line 1 "solve_for_sprd_newton_raphson.mtg_cf_asset.for"
double solve_for_sprd_newton_raphson(int t, double guess_spread, double target_value);

// Weighted Average Life Calculation
#line 1 "weighted_avg_life_calc.mtg_cf_asset.for"
double weighted_avg_life_calc(int t);

// Weighted Average Life Calculation Simple
#line 1 "weighted_avg_life_simple.mtg_cf_asset.for"
void weighted_avg_life_simple(int t, double &unadjusted_wal, double &wal_adjustment);


//factory
static MTG_CF_ASSET* makeThis(int isSubmodel, ModelClass *owner, MTG_CF_ASSET* peer, 
					int mainRebase, const xstring &name, MTG_CF_ASSET_persistent_object* arrayTemplate);

//constructor
MTG_CF_ASSET(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
MTG_CF_ASSET(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~MTG_CF_ASSET();


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
class MTG_CF_ASSET_persistent_object : public MTG_CF_ASSET {


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

	void findTargetColumns() {MTG_CF_ASSET::findTargetColumns();}
	void createAllShare() {
		MTG_CF_ASSET::createAllShare();
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
	MTG_CF_ASSET *&sm_mtg_is; //
	MTG_CF_ASSET *&sm_mtg_pv; //
	MTG_CF_ASSET *&sm_mtg_ym; //
	MTG_CF_ASSET *&sm_bond_is; //
	MTG_CF_ASSET *&sm_bond_pv; //
	MTG_CF_ASSET *&sm_bond_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~MTG_CF_ASSET_persistent_object();

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
static MTG_CF_ASSET_persistent_object* makeThis(int isSubmodel, ModelClass *owner, MTG_CF_ASSET* peer, 
					int mainRebase, const xstring &name, MTG_CF_ASSET_persistent_object* arrayTemplate, bool fixedArray);

//constructor
MTG_CF_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
