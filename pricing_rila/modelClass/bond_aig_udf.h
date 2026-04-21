
#ifndef __BOND_AIG_UDF_H_
#define __BOND_AIG_UDF_H_

#include "ModelClass\bond_aig.h"

class BOND_AIG_UDF : public BOND_AIG {

	friend class BOND_AIG;

//constructor 
BOND_AIG_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: BOND_AIG(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
BOND_AIG_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : BOND_AIG(columnCount, mocd, persObj) {}


// Asset Amount Matured, End of Period 
double bond_aig_asset_amt_matured_aig(int t);

// Asset Maturity Period 
double bond_aig_asset_maturity_period_aig(int t);

// Asset Yield 
double bond_aig_asset_yld_aig(int t);

// New Asset Duration 
double bond_aig_duration_new_asset_aig(int t);

// Initialize 
double bond_aig_initialize(int t);

// Startup 
virtual double virtual_startup(int t);

// Commencement Period 
int  bond_aig_commencement_period();

// WTW Gen2 final_period 
int  bond_aig_final_period();

// Period t in which Policy Matures 
int  bond_aig_maturity_period();


};
#endif
