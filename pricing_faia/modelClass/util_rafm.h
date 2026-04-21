#ifndef __UTIL_RAFM_H_
#define __UTIL_RAFM_H_
#pragma warning ( disable : 4819 )

#include <sstream> // for ostringstream
#include <sys/stat.h> // for file access
#include <deque> //WTW - Gen2 - add library to use deque

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



namespace UTIL_RAFM_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class UTIL_RAFM_persistent_object;
class UTIL_RAFM : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(UTIL_RAFM); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;
	static void Terminator();
	static FunctionPtr RegisterTerminatorOnce;
	
SmartArray <xstring> mp_data;

	void init_(){
		

		bIsInit = true;
	}
	void deInit_(){

	}

#ifdef __CREATE_RATES_ECONOMY_CLASS_
	RATES_ECONOMY	*company_liab_fia_fia_rates;
	RATES_ECONOMY	*&fia_rates;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
	RATES_ECONOMY	*company_rates;
	RATES_ECONOMY	*&rates;
#endif
#ifdef __CREATE_UTIL_RAFM_CLASS_
	UTIL_RAFM	*util;
#endif
 // Column Definition Begins
 	ColumnAccessor < mCFStaticData_0 > copy_data_files;
 	ColumnAccessor < mCFStaticData_0 > copy_output_files;
 	ColumnAccessor < mCFStaticData_0 > startup;
//Column Definition END@2

 // Temporary Table...
UTIL_RAFM *sm_bond_is;
UTIL_RAFM *sm_bond_pv;
UTIL_RAFM *sm_bond_ym;
UTIL_RAFM *sm_mtg_is;
UTIL_RAFM *sm_mtg_pv;
UTIL_RAFM *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE UTIL_RAFM::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > aggcf_prefix_aig;
  inline xstring	Get_aggcf_prefix_aig() {
		return aggcf_prefix_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > base_output_filename;
  inline xstring	Get_base_output_filename() {
		return base_output_filename; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > index_columns_count_aig;
  inline int	Get_index_columns_count_aig() {
		return index_columns_count_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > input_data_filename;
  inline xstring	Get_input_data_filename() {
		return input_data_filename; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > max_path_job_name_length_aig;
  inline int	Get_max_path_job_name_length_aig() {
		return max_path_job_name_length_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > mp_column_index_aig;
  inline int	Get_mp_column_index_aig() {
		return mp_column_index_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > output_delete_switch;
  inline xstring	Get_output_delete_switch() {
		return output_delete_switch; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > output_location_aig;
  inline xstring	Get_output_location_aig() {
		return output_location_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > post_processing_set_aig;
  inline xstring	Get_post_processing_set_aig() {
		return post_processing_set_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > pvde_column_index_aig;
  inline int	Get_pvde_column_index_aig() {
		return pvde_column_index_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > pvde_indicator_aig;
  inline int	Get_pvde_indicator_aig() {
		return pvde_indicator_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > pvde_prefix_aig;
  inline xstring	Get_pvde_prefix_aig() {
		return pvde_prefix_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > pvde_row_filters_aig;
  inline xstring	Get_pvde_row_filters_aig() {
		return pvde_row_filters_aig; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > run_page_name_aig;
  inline xstring	Get_run_page_name_aig() {
		return run_page_name_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > scen_column_index_aig;
  inline int	Get_scen_column_index_aig() {
		return scen_column_index_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > time_column_index_aig;
  inline int	Get_time_column_index_aig() {
		return time_column_index_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > working_data_filename;
  inline xstring	Get_working_data_filename() {
		return working_data_filename; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > custom_output_directory;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > post_processing_set_lookup_aig;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(UTIL_RAFM* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Is the current row key one we want to keep?
#line 1 "avg_row_key_found_aig.util_rafm.for"
bool avg_row_key_found_aig(string row_key);

// Does a string contain non-numeric characters?
#line 1 "has_non_numeric_characters_aig.util_rafm.for"
bool has_non_numeric_characters_aig(string test_text);

// Post Process File
#line 1 "post_process_file_aig.util_rafm.for"
void post_process_file_aig (string output_file_path, string working_file_path);

// Pvde Row Key Found Aig
#line 1 "pvde_row_key_found_aig.util_rafm.for"
bool pvde_row_key_found_aig(string row_key);


//factory
static UTIL_RAFM* makeThis(int isSubmodel, ModelClass *owner, UTIL_RAFM* peer, 
					int mainRebase, const xstring &name, UTIL_RAFM_persistent_object* arrayTemplate);

//constructor
UTIL_RAFM(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
UTIL_RAFM(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~UTIL_RAFM();


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
class UTIL_RAFM_persistent_object : public UTIL_RAFM {


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

	void findTargetColumns() {UTIL_RAFM::findTargetColumns();}
	void createAllShare() {
		UTIL_RAFM::createAllShare();
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
	UTIL_RAFM *&sm_bond_is; //
	UTIL_RAFM *&sm_bond_pv; //
	UTIL_RAFM *&sm_bond_ym; //
	UTIL_RAFM *&sm_mtg_is; //
	UTIL_RAFM *&sm_mtg_pv; //
	UTIL_RAFM *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~UTIL_RAFM_persistent_object();

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
static UTIL_RAFM_persistent_object* makeThis(int isSubmodel, ModelClass *owner, UTIL_RAFM* peer, 
					int mainRebase, const xstring &name, UTIL_RAFM_persistent_object* arrayTemplate, bool fixedArray);

//constructor
UTIL_RAFM_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
