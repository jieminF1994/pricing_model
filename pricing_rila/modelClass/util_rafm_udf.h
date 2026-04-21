
#ifndef __UTIL_RAFM_UDF_H_
#define __UTIL_RAFM_UDF_H_

#include "ModelClass\util_rafm.h"

class UTIL_RAFM_UDF : public UTIL_RAFM {

	friend class UTIL_RAFM;

//constructor 
UTIL_RAFM_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: UTIL_RAFM(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
UTIL_RAFM_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : UTIL_RAFM(columnCount, mocd, persObj) {}


// Copy data files 
double util_rafm_copy_data_files(int t);

// Copy Output Files 
double util_rafm_copy_output_files(int t);

// Startup 
virtual double virtual_startup(int t);

// Custom Output Directory 
xstring  util_rafm_custom_output_directory();

// Table look-up for file post-processing behavior: 
xstring  util_rafm_post_processing_set_lookup_aig();


};
#endif
