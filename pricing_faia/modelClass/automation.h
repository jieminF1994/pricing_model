#ifndef __AUTOMATION_H_
#define __AUTOMATION_H_
#pragma warning ( disable : 4819 )


/*
	A very simple XML writer library, mainly for use in RiskAgility FM.

	- Initial implementation. MCHING 1-26-2022
*/


class XmlNode
{
private:
	std::vector< XmlNode* > children;
	unsigned long long rank;

	std::string indent;


	void set_indent(void)
	{
		this->indent = "";

		for (unsigned long long rank = 0; rank < this->rank; rank++)
		{
			this->indent += "\t";
		}
	}


public:
	std::string name;
	std::string value;


	std::string to_string(void)
	{
		std::string xml = "\n";

		if (children.empty())
		{
			// This is the highest-rank node
			if (value.empty())
			{
				xml += this->indent + "</" + this->name + ">";
			}
			else
			{
				xml += this->indent + "<" + this->name + ">" + this->value + "</" + this->name + ">";
			}
		}
		else
		{
			// Write out children
			if (value.empty())
			{
				xml += this->indent + "<" + this->name + ">";
			}
			else
			{
				xml += this->indent + "<" + this->name + ">" + this->value;
			}

			for (XmlNode* child : children)
			{
				xml += child->to_string();
			}

			xml += "\n" + this->indent + "</" + this->name + ">";
		}

		return xml;
	}


	XmlNode* append_child_node(
		const std::string& name
	)
	{
		XmlNode* child = new XmlNode(
			this->rank + 1,
			name
		);

		this->children.push_back(child);

		return child;
	}


	XmlNode* append_child_node(
		const std::string& name,
		const std::string& value
	)
	{
		XmlNode* child = new XmlNode(
			this->rank + 1,
			name,
			value
		);

		this->children.push_back(child);

		return child;
	}


	XmlNode(
		const size_t& rank,
		const std::string& name
	)
	{
		this->rank = rank;
		this->name = name;

		this->set_indent();
	}


	XmlNode(
		const size_t& rank,
		const std::string& name,
		const std::string& value
	)
	{
		this->rank = rank;
		this->name = name;
		this->value = value;

		this->set_indent();
	}
};


class XmlWriter
{
public:
	const std::string PROLOGUE = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";

	std::string xml_file_path;
	XmlNode* root_node;


	void write(void)
	{
		std::string xml = this->PROLOGUE + this->root_node->to_string();

		std::ofstream output_file;
		output_file.open(this->xml_file_path);
		output_file << xml;
		output_file.close();
	}


	XmlWriter(
		const std::string& xml_file_path
	)
	{
		this->xml_file_path = xml_file_path;
		this->root_node = new XmlNode(0, "root");
	}
};


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



namespace AUTOMATION_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class AUTOMATION_persistent_object;
class AUTOMATION : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(AUTOMATION); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;

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
 	ColumnAccessor < mCFStaticData_0 > postprocess_aig;
 	ColumnAccessor < mCFStaticData_0 > preprocess_aig;
 	ColumnAccessor < mCFStaticData_0 > startup;
//Column Definition END@2

 // Temporary Table...
AUTOMATION *sm_bond_is;
AUTOMATION *sm_bond_pv;
AUTOMATION *sm_bond_ym;
AUTOMATION *sm_mtg_is;
AUTOMATION *sm_mtg_pv;
AUTOMATION *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE AUTOMATION::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > clear_model_output_defn_aig;
  inline xstring	Get_clear_model_output_defn_aig() {
		return clear_model_output_defn_aig; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > max_path_job_name_length_aig;
  inline int	Get_max_path_job_name_length_aig() {
		return max_path_job_name_length_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > model_output_file_prefix_aig;
  inline xstring	Get_model_output_file_prefix_aig() {
		return model_output_file_prefix_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mp_file_path_aig;
  inline xstring	Get_mp_file_path_aig() {
		return mp_file_path_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > mp_tmp_file_prefix_aig;
  inline xstring	Get_mp_tmp_file_prefix_aig() {
		return mp_tmp_file_prefix_aig; }
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
 void passDataVariables(AUTOMATION* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Append To File Manifest
#line 1 "append_to_file_manifest_aig.automation.for"
void append_to_file_manifest_aig(
	const xstring& model_class_output_location
);

// Append Wildcard Node
#line 1 "append_wildcard_node_aig.automation.for"
void append_wildcard_node_aig(
	XmlNode* wildcard_set_node,
	const std::string& name,
	const std::string& value
);

// Copy File
#line 1 "copy_file_aig.automation.for"
void copy_file_aig(
	const xstring& source_file_path,
	const xstring& target_file_path
);

// Create Process
#line 1 "create_process_aig.automation.for"
void create_process_aig(
	const xstring& exe_path,
	const std::vector< xstring >& args
);

// Ends With
#line 1 "ends_with_aig.automation.for"
bool ends_with_aig(
	std::string const& target,
	std::string const& value
);

// File Exists
#line 1 "file_exists_aig.automation.for"
bool file_exists_aig(
	const xstring& file_path
);

// Get File Name
#line 1 "get_file_name_aig.automation.for"
xstring get_file_name_aig(
	const xstring& file_path
);

// List Directory Contents
#line 1 "list_dir_aig.automation.for"
void list_dir_aig(
	const xstring& dir_path
);

// xstring To string
#line 1 "xstring_to_string_aig.automation.for"
std::string xstring_to_string_aig(
	const xstring& source
);


//factory
static AUTOMATION* makeThis(int isSubmodel, ModelClass *owner, AUTOMATION* peer, 
					int mainRebase, const xstring &name, AUTOMATION_persistent_object* arrayTemplate);

//constructor
AUTOMATION(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
AUTOMATION(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~AUTOMATION();


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
class AUTOMATION_persistent_object : public AUTOMATION {


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

	void findTargetColumns() {AUTOMATION::findTargetColumns();}
	void createAllShare() {
		AUTOMATION::createAllShare();
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
	AUTOMATION *&sm_bond_is; //
	AUTOMATION *&sm_bond_pv; //
	AUTOMATION *&sm_bond_ym; //
	AUTOMATION *&sm_mtg_is; //
	AUTOMATION *&sm_mtg_pv; //
	AUTOMATION *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~AUTOMATION_persistent_object();

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
static AUTOMATION_persistent_object* makeThis(int isSubmodel, ModelClass *owner, AUTOMATION* peer, 
					int mainRebase, const xstring &name, AUTOMATION_persistent_object* arrayTemplate, bool fixedArray);

//constructor
AUTOMATION_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
