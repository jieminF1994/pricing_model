
#ifndef __LIAB_LIAB_UDF_H_
#define __LIAB_LIAB_UDF_H_

#include "ModelClass\liab_liab.h"

class LIAB_LIAB_UDF : public LIAB_LIAB {

	friend class LIAB_LIAB;

//constructor 
LIAB_LIAB_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: LIAB_LIAB(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
LIAB_LIAB_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : LIAB_LIAB(columnCount, mocd, persObj) {}


// Finalize 
double liab_liab_finalize(int t);

// Initialize 
double liab_liab_initialize(int t);

// Startup 
virtual double virtual_startup(int t);

// Projection Date Adjusted 
xstring  liab_liab_proj_date_adj();

// Projection Start Date 
int  liab_liab_proj_start_date();

// Projection Start Mth 
int  liab_liab_proj_start_mth();

// Projection Start Yr 
int  liab_liab_proj_start_yr();


};
#endif
