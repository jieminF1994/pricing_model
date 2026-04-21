
#ifndef __AUTOMATION_UDF_H_
#define __AUTOMATION_UDF_H_

#include "ModelClass\automation.h"

class AUTOMATION_UDF : public AUTOMATION {

	friend class AUTOMATION;

//constructor 
AUTOMATION_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: AUTOMATION(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
AUTOMATION_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : AUTOMATION(columnCount, mocd, persObj) {}


// PostProcess 
double automation_postprocess_aig(int t);

// PreProcess 
double automation_preprocess_aig(int t);

//  
virtual double virtual_startup(int t);


};
#endif
