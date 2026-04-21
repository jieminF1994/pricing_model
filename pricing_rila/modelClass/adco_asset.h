#ifndef __ADCO_ASSET_H_
#define __ADCO_ASSET_H_
#pragma warning ( disable : 4819 )

#ifndef ADCO_H_
#define ADCO_H_

//MBS defines
#ifndef max_maturity
#define max_maturity        600
#define months_in_yr        12
#define maximum_lag		 4
#define lag_wght_vecsize   (maximum_lag + 1)
#define curr_cpn_vecsize   (600 + maximum_lag)
#define balloon_7yr_mat     84
#define balloon_5yr_mat     60
#define balloon_10yr_mat	120
#define balloon_3yr_mat	 36
#endif

//ABS defines
#ifndef abs_mh_maxlag
#define abs_mh_maxlag	4
#define abs_max_maturity	600
#endif

// MBS
#ifndef mbs_enums
#define mbs_enums

typedef enum typeofloan
{
FNMA_30YR,
FNMA_15YR,
FNMAB_5YR,
FNMAB_7YR,
FRDG_30YR,
FRDG_20YR,
FRDG_15YR,
FRDGB_5YR,
FRDGB_7YR,
GNMA_30YR,
GNMA_15YR,
GNMA2_30YR,
FNMA_20YR,
WHOLE_30YR,
WHOLE_15YR,
RELO_30YR,
RELO_15YR,
FNMA_10YR,
FRDG_10YR,
GNMA2_15YR,
WHOLEB_5YR,
WHOLEB_7YR,
FNMAB_10YR,
FRDGB_10YR,
FNMAB_3YR,
FRDGB_3YR,
ALT_A_15YR,
ALT_A_30YR,
MBS_RESERVE0,
MBS_RESERVE1,
MBS_RESERVE2,
MBS_RESERVE3,
MBS_RESERVE4,
MBS_RESERVE5,
MBS_RESERVE6,
MBS_RESERVE7,
MBS_RESERVE8,
MBS_RESERVE9,
MAX_LOANTYPE
} loantype;

typedef enum typeofarm
{
FNMA_1YR_NONC,
FNMA_1YR_CONV,
FRDH_1YR_NONC,
FRDH_1YR_CONV,
FNMA_3YR,
FRDH_3YR,
GNMA_1YR,
D11_COFI,
ARM_RESERVE0,
ARM_RESERVE1,
ARM_RESERVE2,
ARM_RESERVE3,
ARM_RESERVE4,
ARM_RESERVE5,
ARM_RESERVE6,
ARM_RESERVE7,
ARM_RESERVE8,
ARM_RESERVE9,
NUM_ARMTYPES
} armtype;

typedef enum typeofarmindex
{
PAR_TSY_1YR,
PAR_LIBOR_6M,
PAR_LIBOR_1YR,
MTA_12,
PAR_TSY_3YR,
PAR_TSY_5YR,
COFI_11D
} armtypeindex;

typedef enum typeofissuer
{
FANNIE_MAE,
FREDDIE_MAC,
GINNIE_MAE,
NONAGENCY_SUBPRIME,
NONAGENCY_PRIME,
NONAGENCY_OTHER
} issuertype;

typedef enum errorcodetype
{
ADCOPP_OK,
ILLEGAL_LOAN_TYPE,
LICENSE_EXPIRED,
DATAFILE_MISSING,
ILLEGAL_DATE,
NO_MEMORY,
DATAFILE_ERROR,
ADCOPP_FPE
#ifdef AD_LICKEYFILE 
,KEYFILE_FAILURE
#endif
} errorcode;
#endif

// ABS
#ifndef abs_enums
#define abs_enums
typedef enum abserrcode
{
ADCO_ABS_OK,
ADCO_ABS_INVALID_TYPE,
ADCO_ABS_LICENSE_EXPIRED,
ADCO_ABS_DATAFILE_MISSING,
ADCO_ABS_ILLEGAL_DATE,
ADCO_ABS_NO_MEMORY,
ADCO_ABS_DATAFILE_ERROR,
ADCO_ABS_ADCOPP_FPE,
ADCO_ABS_MAXERRORNO
} abs_errorcode;

// Auto Loans 
typedef enum abs_autot
{	
ADCO_AUTO_ALL,
ADCO_AUTO_STRAT,
ADCO_AUTO_MAXTYPE		
} abs_auto_type;

// Manufactured Houseing Enums 
typedef enum abs_mh_uset
{
ADCO_MH_RENTAL,
ADCO_MH_TRAILER,
ADCO_MH_OWNER,
ADCO_MH_UNKUSE,
ADCO_MH_MAXUSE
} abs_mh_use_type;

typedef enum abs_mh_widtht
{
ADCO_MH_SINGLE,
ADCO_MH_DOUBLE,
ADCO_MH_UNKWDTH,
ADCO_MH_MAXWIDTH
} abs_mh_width_type;

typedef enum abs_mh_vintt
{
ADCO_MH_NEW,
ADCO_MH_OLD,
ADCO_MH_UNKVINT,
ADCO_MH_MAXVINT
} abs_mh_vint_type;

typedef enum abs_termtype
{
ADCO_ABS_5YR,
ADCO_ABS_15YR,
ADCO_ABS_30YR,
ADCO_ABS_MAXTERM
} abs_term_type;	

// Home Equity Loans 
typedef enum abs_heliss
{		
ADCO_HEL_UNK,			
ADCO_HEL_AFC,			
ADCO_HEL_ADV,			
ADCO_HEL_EC,
ADCO_HEL_GE,	
ADCO_HEL_MON,	
ADCO_HEL_UFC,
ADCO_HEL_INM,	
ADCO_HEL_CON,		
ADCO_HEL_MAXTYPE	
} abs_hel_issuer;
#endif

#ifndef abs_enums2
#define abs_enums2
// Added for New ARM-HEL model 
typedef enum adco_mtfra
{ 
ADCO_ABS_ARMHEL_6,
ADCO_ABS_ARMHEL_12,
ADCO_ABS_ARMHEL_24,
ADCO_ABS_ARMHEL_36,
ADCO_ABS_ARMHEL_UNKNOWN,
ADCO_ABS_ARMHEL_MAXRESET
} adco_armhel_reset;
#endif

#define ALLOCATE_ADCO
// start of EnumConst.h
#ifndef ADPPMDLAPI_H
#define ADPPMDLAPI_H

// Stuff To Make Win32 DLL Import/Export Happen Automatically
#ifdef WIN32
// Force structure alignment to 32-bit so legacy
// applications ported from 16-bit Windows don't mess up structure
// alignments (esp. of adco_CParam)
#pragma pack( push, inside_adppmdlapi, 8)
#ifdef WINDOWS_STATIC
#define ADPPMDL_API
#else
#ifdef MAKE_ADPPMDL
#define ADPPMDL_API __declspec(dllexport)
#else
#define ADPPMDL_API __declspec(dllimport)
#endif
#endif
#define EXTERN extern ADPPMDL_API
#define THROWS( errorclass )
#else
#define ADPPMDL_API
#define EXTERN extern
// #define THROWS( errorclass ) throw errorclass
#define THROWS( errorclass )
#endif

//Some Useful Defines
#define minimum(a,b) ((a) < (b) ? (a) : (b))
#define maximum(a,b) ((a) < (b) ? (b) : (a))
#ifndef NULL
#define NULL 0
#endif

#if defined(_MSC_VER) && (_MSC_VER < 1300)
#define DATEADD(m, y, d)                        \
    (y) = (y) + ((d) / 12);                     \
    (m) = (m) + ((d) % 12);                     \
    if((m) < 1) { --(y); (m) += 12;}            \
    if((m) > 12) { ++(y); (m) -= 12;}           \
#define DATEDIFF(sy, sm, ey, em)                \
    ((ey) - (sy)) * 12 + ((em) - (sm));
#else
inline void DATEADD(int& m, int& y, int d){
    y = y + (d / 12);
    m = m + (d % 12);
    if( m < 1 ) { --y; m += 12;}
    if( m > 12 ) { ++y; m -= 12;}
}
inline int DATEDIFF(int sy, int sm, int ey, int em){
    return (ey - sy) * 12 + (em - sm);
}
#endif

#ifdef __unix
#ifdef __sun
#if __SUNPRO_CC == 0x420
#ifndef bool
#define bool short
#define true 1
#define false 0
#endif
#endif
#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// All the dynamism of this model comes from lists of enumerated constants
// represented by adco_cEnumElem and adco_cEnumeration
/////////////////////////////////////////////////////////////////////////////
class ADPPMDL_API adco_cEnumElem;
class ADPPMDL_API adco_cEnumeration;

// All Thrown Errors are subclassed off this class
class ADPPMDL_API adco_cError;

// Data Classes for Getting Stuff in and out of models
class ADPPMDL_API adco_CParam;
class ADPPMDL_API adco_TimeSeries;
class ADPPMDL_API adco_CString;
struct ADPPMDL_API vecspec;

// All Models are Subclasses of CAdppmdl.  Instantiation is done by the object
// Factory
class ADPPMDL_API CAdppmdl;
class ADPPMDL_API CAdcoSys;

enum ADCO_DATA_TYPE
{
    AD_TYPE_INTEGER = 0,
    AD_TYPE_DOUBLE,
    AD_TYPE_STRING,
    AD_TYPE_ENUMTYPE,
    AD_TYPE_TIMESERIES,
    AD_TYPE_UDPTRTYPE,
    AD_TYPE_LISTTYPE,
    AD_TYPE_E_INFOONLY,
    AD_TYPE_E_WARNING,
    AD_TYPE_E_ERROR,
    AD_TYPE_NTYPE,  // NULL type
    AD_TYPE_VECLIST,
    AD_TYPE_CONDLIST
};

/////////////////////////////////////////////////////////////////////////////
// Interfaces
/////////////////////////////////////////////////////////////////////////////
class ADPPMDL_API adco_cEnumeration {
public:
    virtual void Initialize( void ) const = 0;
    virtual const char* name() const = 0;
    virtual const char* description() const = 0;
    virtual unsigned int idx( const char* ename ) const = 0;
    virtual const char* elem_name ( unsigned int n ) const = 0;
    virtual adco_cEnumElem element( unsigned int n ) const = 0;
    virtual adco_cEnumElem element( const char* ename ) const = 0;
    virtual const char* elem_desc ( unsigned int n ) const = 0;
    virtual const char* elem_desc ( const char* ename ) const = 0;
    virtual const adco_cEnumElem elem_class ( unsigned int n ) const = 0;
    virtual const adco_cEnumElem elem_class ( const char* ename ) const = 0;
    virtual unsigned int elem_count () const = 0;
    bool operator==( const adco_cEnumeration& elist ) const { return this == &elist; }
    bool operator!=( const adco_cEnumeration& elist ) const { return this != &elist; }
    virtual bool contains( const adco_cEnumElem& e ) const = 0;
    virtual bool contains( const char* ename ) const = 0;
    virtual unsigned int idx( const adco_CParam& ParamElem ) const;
    virtual const char * sub_name ( unsigned int n ) const
    { throw("adco_cEnumeration.sub_name() not supported"); return (char *) 0;};
    virtual const char * sub_name ( const char* ename ) const
    { throw("adco_cEnumeration.sub_name() not supported"); return (char *) 0;};
    virtual enum ADCO_DATA_TYPE elem_type(unsigned int n) const;
}; /* class adco_cEnumeration */

class ADPPMDL_API adco_cEnumElem {
protected:
    const adco_cEnumeration* mList;
    unsigned int mIdx;
public:
    // Constructors
    adco_cEnumElem(){};
    adco_cEnumElem( const adco_cEnumeration& elist, unsigned int elem_idx );
    adco_cEnumElem( const adco_cEnumeration& elist, const char* elem_name );
    // Copy Constructor
adco_cEnumElem( const adco_cEnumElem& ee)
    : mList( ee.adco_cEnumElem::list() )
        , mIdx( ee.adco_cEnumElem::idx() ) {}
    // Copy by assignment
    adco_cEnumElem& operator=( const adco_cEnumElem& ee )
        { mList = ee.list(); mIdx = ee.idx(); return *this; }
    // Parent List
    const adco_cEnumeration* list() const { return mList; }
    // Numeric Idx in Parent List
    unsigned int idx() const { return mIdx; }
    operator unsigned int(void) const { return mIdx; }
    virtual const char* name() const { return mList->elem_name( mIdx ); }
    virtual const char* description() const { return mList->elem_desc( mIdx ); }
    virtual const adco_cEnumElem classification() const
    { return mList->elem_class( mIdx ); }
    virtual bool operator==( const adco_cEnumElem& ee ) const
    { return ( mList == ee.mList && mIdx == ee.mIdx ); }
    virtual bool operator!=( const adco_cEnumElem& ee ) const
    { return ( mList != ee.mList || mIdx != ee.mIdx ); }
    virtual const char * sub_name() const
    { return mList->sub_name( mIdx ); }
    virtual enum ADCO_DATA_TYPE elem_type() const
    { return mList->elem_type(mIdx); }
}; /* class adco_cEnumElem */

// Base class for all thrown adco model errors
// When a specific error is thrown, it's copy constructor
// is used to copy the the error from the error context to the heap.
// After the stack is cut back, destroying the original error instance,
// the base copy constructor is used to copy a BASE CLASS adco_cError
// instance into the error handler (catch block) context.
// This base class instance will contain an mRealMe that points
// to the heap copy of the real error.
// When the handler context is exited, the heap copy of the real error
// and the base class instance in the handler context are destroyed.
// For this reason, the base copy constructor is smart.  An attempt to
// copy a base class error instance out of the handler will yield a
// mRealMe that points to itself, and the original error info is lost.
class ADPPMDL_API adco_cError
{
protected:
    const adco_cError* mRealMe;
    adco_cError() { mRealMe = this; }
public:
    adco_cError( const adco_cError& e);
    virtual adco_cEnumElem severity() const;
    virtual const char* message() const;
    virtual unsigned int msglen() const;
    virtual adco_cEnumElem msgelement() const; // in Global System ERRORDEFS list, or NULL_ELEM
}; /* class ADPPMDL_API adco_cError */

struct  vecspec
{
    double forward_final;
    double forward_value;
    double backward_final;
    double backward_value;
    vecspec(){};
    vecspec(double modeltune, double tune)
    {
        forward_final = tune;
        forward_value = modeltune * tune;
        backward_final = 1.0;
        backward_value = modeltune;
    }
    vecspec(double modeltune, double tune, double fbtune)
    {
        forward_final = tune * fbtune;
        forward_value = modeltune * tune * fbtune;
        backward_final = fbtune;
        backward_value = modeltune*fbtune;
    }
    void addset(double modeltune, double tune)
    {
        forward_final = tune;
        forward_value = modeltune + tune;
        backward_final = 0.0;
        backward_value = modeltune;
    }
    void addset(double modeltune, double tune, double fbtune)
    {
        forward_final = tune + fbtune;
        forward_value = modeltune + tune + fbtune;
        backward_final = fbtune;
        backward_value = modeltune + fbtune;
    }
};

class ADPPMDL_API adco_TimeSeries
{
public:
    // Constructors & Desctructors
    // Use Internal Storage Vector if Values = NULL
    // Defaults:
    //              freq = ADCO_MONTHLY
    //              Values = NULL (Internal Storage)
    //              maxobs = 0 => TSALLOCINCREMENT
    //              newlength = 0 => same length as source
    //              newlength > 0 => set length, copy nobs=min(old length, new length)
    adco_TimeSeries( int NumObs, int SYear, int SPeriod,
                     adco_cEnumElem freq, double* Values = NULL,
                     int maxobs = 0  );
    // Copies are always deep
    adco_TimeSeries( const adco_TimeSeries& ts, int newlength = 0 );
    adco_TimeSeries& operator=( const adco_TimeSeries& tsval );
    ~adco_TimeSeries();

    // Public Interface
    adco_cEnumElem frequency() const { return mFrequency; }
    int StartPeriod() const { return mStartPeriod; }
    int StartYear() const { return mStartYear; }
    int LastYear() const;
    int LastPeriod() const;
    int Nobs() const { return mNobs; }
    int Length() const { return mLength; }
    double* Values() const { return mValues; }
    int GetIdx( int year, int period ) const;
    int GetRawIdx( int year, int period ) const;
    double GetVal( int year, int period ) const; // Can Throw Invalid Index
    void GetVal( int year, int period, double* vec, int NumObs ) const;
    void ShallowSetVal( int year, int period, double* vec, int NumObs );
    void SetVal( int year, int period, double value, int NumObs = 1 );
    void SetVal( int year, int period, double* vec, int NumObs );
    void SetVal( int year, int period, const adco_TimeSeries& TS, int NumObs = 0 );
    // Set from list of nobs/value pairs terminated by a zero pair
    void SetValFromList( int year, int period, const double* vec );
    //Extend repeats first/last value as needed
    void Extend( int SYear, int SPeriod, int NumObs );
    void Extend( int SYear, int SPeriod, int EYear, int EPeriod );
    void Truncate( int NumObs );
    void Truncate( int EYear, int EPeriod );
    bool InternalStore() const { return mInternalStore; }

protected:
    int PerYear() const;

    adco_cEnumElem mFrequency;
    int mStartPeriod;
    int mStartYear;
    int mNobs;
    int mLength;
    double* mValues;
    bool mInternalStore;
}; /* class ADPPMDL_API adco_TimeSeries */

//
// Parameter Class for moving data in and out of models
//

// add the sizeof(unsigned int) - 1 in case of a remainder in division
#define ADCO_EE_SIZE ( ( (sizeof(adco_cEnumeration*) + sizeof(unsigned int) - 1)/ sizeof(unsigned int) ) + 1 )

#include "stdio.h"
class ADPPMDL_API adco_CParam
{
protected:
    adco_cEnumElem TypeNum( const unsigned int tn_ ) const;

public:
    const adco_cEnumElem& VarType() const
    { return mVarType; }

    //Public Constructors
    adco_CParam(  ){};
    adco_CParam( int ival );
    adco_CParam( double dval );
    adco_CParam( const char* sval );
    adco_CParam( const adco_cEnumElem& eval );
    adco_CParam( adco_TimeSeries& tsval );
    adco_CParam( vecspec & tsval );
    adco_CParam( void* pval );
    // Copy Constructor and Assignment
    adco_CParam( const adco_CParam& cpval );
    adco_CParam& operator=( const adco_CParam& cpval );
    // Extract:  Caution - may throw conversion error
    operator int(void) const;
    operator double(void) const;
    // operator adco_CString(void) const;
    operator const char *(void) const;
    operator adco_cEnumElem(void) const;
    operator adco_TimeSeries&(void) const;
    operator vecspec&(void) const;
    operator void*(void) const;

private:
    adco_cEnumElem mVarType;
    union ADPPMDL_API uparamval {
        double dblval;
        int intval;
        const char* strval;
        const adco_cEnumeration* enumvall;
        unsigned int enumvali[ADCO_EE_SIZE];
        adco_TimeSeries* tsval;
        void* ptrval;
    uparamval() : dblval(0) {}
    } mParamVal;

}; /* class ADPPMDL_API adco_CParam */

//
// The Generic Model Class.  All Specific Model Types derived from this
//
class ADPPMDL_API CAdppmdl
{
public:
    // All Models have at least these 3 lists:
    // LISTS:  The list of available lists
    // INPUTS: The list of input parameters
    // RESULTS:The list of output values
    virtual const adco_cEnumeration& GetList( const char* listname = 0) = 0;

    // Both current setting of items in the INPUTS list
    // and results of the PrecCalc and Forecast calls
    // are retrieved with GetParam
    virtual adco_CParam GetParam( const adco_cEnumElem Parameter ) = 0;
    adco_CParam GetParam( const adco_cEnumeration& ParamList, const char* ParamName );
    virtual adco_CParam GetParam( const char* ParamName );

    // Items in the INPUTS list can be set with SetParam
    virtual void SetParam( const adco_cEnumElem Parameter, adco_CParam Value ) = 0;
    virtual void UnSetParam( const adco_cEnumElem Parameter ) = 0;

    // Set elements via "ParamName=Value, ..." string
    virtual void ParseParams( const char* ParamString ) = 0;

    // These actually run the models
    virtual void PreCalc() = 0;
    virtual void Forecast() = 0;
    virtual CAdppmdl* Duplicate() = 0;

    // CAdppmdl( void );
    virtual ~CAdppmdl() {};
}; /* class ADPPMDL_API CAdppmdl */

//
// The Model Factory Class.  Use this to create instances of CAdppmdl
//
class ADPPMDL_API CAdcoSys
{
protected:
    CAdcoSys();
    ~CAdcoSys();

public:
    // Create PPModel Objects for users
    virtual CAdppmdl& Adppmdl_factory( const adco_cEnumElem& model ) THROWS(adco_cError) = 0 ;
    virtual CAdppmdl& Adppmdl_factory( const char* modelname ) THROWS(adco_cError) = 0;
    virtual void Adppmdl_recycle( CAdppmdl& model ) = 0;

    // Control Generic Model defaults & behaviors
    virtual const adco_cEnumeration& ParamList() = 0;
    virtual const adco_cEnumeration& ModelList() = 0;
    virtual void SetParam( const adco_cEnumElem& Param, const adco_CParam& value ) = 0;
    virtual void SetParam( const char* ParamName, const adco_CParam& value ) = 0;
    virtual adco_CParam GetParam( const adco_cEnumElem& Param ) = 0;
    virtual adco_CParam GetParam( const char* ParamName ) = 0;
    virtual const adco_cEnumeration& ErrorList() = 0;
};
// Some of the models have a "TuneBack" parameter of type void*.  If you set
// this to the address of a adco_ppmodel_callback_func,  The model will call
// back this function at the beginning of each processing stage (Currently
// PreCalc(0) or Forecast(1)).  Why?  Some 3rd party cashflow generators allow
// for a prepayment model callback function pointer.  They are supposed to
// pass this to us so you can step in at each call to the prepayment model.

#ifdef _WIN32
#define STDCALL __stdcall
#else
#define STDCALL
#endif
typedef void STDCALL adco_ppmodel_callback_func(
    int stage,
    void* adco_50_tuning_ptr,
    char* datafile_path,
    int* no_forecast_callback,
    void* ppmdl
    );

#ifdef WIN32
#pragma pack( pop, inside_adppmdlapi)
#endif

#endif
#ifndef ADPPMDLXTERN_H
#define ADPPMDLXTERN_H

EXTERN const adco_cEnumElem NULL_ELEM;
EXTERN const adco_cEnumeration* pNullList;

EXTERN const adco_cEnumeration* pErrorClass;

EXTERN const adco_cEnumElem ADCO_E_INFOONLY;
EXTERN const adco_cEnumElem ADCO_E_WARNING;
EXTERN const adco_cEnumElem ADCO_E_ERROR;

EXTERN const adco_cEnumeration* pAdco_PPModel_Types;
EXTERN const adco_cEnumElem POOLTYPE;
EXTERN const adco_cEnumElem LOANTYPE;
EXTERN const adco_cEnumElem UTILITYTYPE;

// Time Series Frequencies
// EXTERN const adco_cEnumeration* pAdco_Obs_Frequency;
EXTERN const adco_cEnumElem ADCO_MONTHLY; // Only one defined as of v5.0

// Parameter Types
EXTERN const adco_cEnumeration* pAdco_ParamTypes;
EXTERN const adco_cEnumElem ADCO_INTTYPE;
EXTERN const adco_cEnumElem ADCO_DBLTYPE;
EXTERN const adco_cEnumElem ADCO_STRTYPE;
EXTERN const adco_cEnumElem ADCO_ENUMTYPE;
EXTERN const adco_cEnumElem ADCO_TSTYPE;
EXTERN const adco_cEnumElem ADCO_UDPTRTYPE;

ADPPMDL_API CAdcoSys* adco_CreateSystem( void );
ADPPMDL_API void adco_DestroySystem( CAdcoSys* pSys );
ADPPMDL_API void addseasonality(adco_TimeSeries *pforecast, adco_TimeSeries *phistory, int firstoffset);

#ifdef _WIN32
#define  DEFAULTDATAFILEDIR     "c:\\adco\\ppmodel\\"
#define  DIRPATHSEPARATOR       '\\'
#else
#define  DEFAULTDATAFILEDIR     "./"
#define  DIRPATHSEPARATOR       '/'
#endif
const char DIRPATHSEPSTRING[2] = {DIRPATHSEPARATOR,0};

const int TUNETYPE_STRLEN = 32;

#endif

#endif

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



namespace ADCO_ASSET_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class ADCO_ASSET_persistent_object;
class ADCO_ASSET : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(ADCO_ASSET); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;

int valuation_period;
int loaded_proj_task_loop;
double arm_margin;
SmartArray <double> arm_wac_rates;

CAdcoSys * pAdcoSystem;

struct CHistData 
{
adco_TimeSeries * Rates;
};

map <string, CHistData> HistData;

inline void AddMonthToDate(int &y, int &m, const int offset)
{
if (abs(offset)<=12)
	m += offset;
else
	{
	y += (offset / 12);
	m += (offset % 12);
	}
		
if (m > 12) 
	{
	++y;
	m -= 12;
	}
else if (m < 1) 
	{
	--y;
	m += 12;
	}
}

	void init_(){
		

valuation_period = -1;
loaded_proj_task_loop = -1;
pAdcoSystem = NULL;

arm_margin = 0.0;
if (arm_wac_rates.size() < max_maturity)
	arm_wac_rates.resize(max_maturity);
for (int i = 0; i < max_maturity; i++)
	arm_wac_rates[i] = 0.0;

		bIsInit = true;
	}
	void deInit_(){

	}

#ifdef __CREATE_EPL_LIAB_CLASS_
	EPL_LIAB	*company_liab_epl;
	EPL_LIAB	*&epl;
#endif
#ifdef __CREATE_INTEX_ASSET_CLASS_
	INTEX_ASSET	*company_asset_intex;
	INTEX_ASSET	*&intex;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
	RATES_ECONOMY	*company_rates;
	RATES_ECONOMY	*&rates;
#endif
 // Column Definition Begins
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > finalize;
 	ColumnAccessor < mCFStaticData_0 > get_prepmt_rate;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > process_adco_detail;
 	ColumnAccessor < mCFStaticData_0 > startup;
//Column Definition END@2

 // Temporary Table...
ADCO_ASSET *sm_bond_is;
ADCO_ASSET *sm_bond_pv;
ADCO_ASSET *sm_bond_ym;
ADCO_ASSET *sm_mtg_is;
ADCO_ASSET *sm_mtg_pv;
ADCO_ASSET *sm_mtg_ym;
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
	#define DESCRIPTOR_TABLE ADCO_ASSET::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > abs_mh_defn;
  inline xstring	Get_abs_mh_defn() {
		return abs_mh_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > abs_mh_vintage_defn;
  inline xstring	Get_abs_mh_vintage_defn() {
		return abs_mh_vintage_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > abs_mh_width_defn;
  inline xstring	Get_abs_mh_width_defn() {
		return abs_mh_width_defn; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > abs_prepmt_defn;
  inline xstring	Get_abs_prepmt_defn() {
		return abs_prepmt_defn; }
  inline void Set_abs_prepmt_defn(const xstring &v) {
		abs_prepmt_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > adjustable_rate_defn;
  inline xstring	Get_adjustable_rate_defn() {
		return adjustable_rate_defn; }
  inline void Set_adjustable_rate_defn(const xstring &v) {
		adjustable_rate_defn.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > age;
  inline int	Get_age() {
		return age; }
  inline void Set_age(const int &v) {
		age.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > arm_first_reset_age;
  inline int	Get_arm_first_reset_age() {
		return arm_first_reset_age; }
  inline void Set_arm_first_reset_age(const int &v) {
		arm_first_reset_age.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > arm_flag;
  inline xstring	Get_arm_flag() {
		return arm_flag; }
  inline void Set_arm_flag(const xstring &v) {
		arm_flag.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > arm_index_name;
  inline xstring	Get_arm_index_name() {
		return arm_index_name; }
  inline void Set_arm_index_name(const xstring &v) {
		arm_index_name.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > arm_lookback_mths;
  inline int	Get_arm_lookback_mths() {
		return arm_lookback_mths; }
  inline void Set_arm_lookback_mths(const int &v) {
		arm_lookback_mths.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > arm_max_rate;
  inline double	Get_arm_max_rate() {
		return arm_max_rate; }
  inline void Set_arm_max_rate(const double &v) {
		arm_max_rate.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > arm_max_reset_period_rate;
  inline double	Get_arm_max_reset_period_rate() {
		return arm_max_reset_period_rate; }
  inline void Set_arm_max_reset_period_rate(const double &v) {
		arm_max_reset_period_rate.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > arm_min_rate;
  inline double	Get_arm_min_rate() {
		return arm_min_rate; }
  inline void Set_arm_min_rate(const double &v) {
		arm_min_rate.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > arm_min_reset_period_rate;
  inline double	Get_arm_min_reset_period_rate() {
		return arm_min_reset_period_rate; }
  inline void Set_arm_min_reset_period_rate(const double &v) {
		arm_min_reset_period_rate.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > arm_reset_mths;
  inline int	Get_arm_reset_mths() {
		return arm_reset_mths; }
  inline void Set_arm_reset_mths(const int &v) {
		arm_reset_mths.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > arm_reset_period;
  inline int	Get_arm_reset_period() {
		return arm_reset_period; }
  inline void Set_arm_reset_period(const int &v) {
		arm_reset_period.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > arm_reset_scen_yr;
  inline double	Get_arm_reset_scen_yr() {
		return arm_reset_scen_yr; }
  inline void Set_arm_reset_scen_yr(const double &v) {
		arm_reset_scen_yr.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > asset_detail_rpt_cusip_id;
  inline xstring	Get_asset_detail_rpt_cusip_id() {
		return asset_detail_rpt_cusip_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > asset_detail_rpt_defn;
  inline xstring	Get_asset_detail_rpt_defn() {
		return asset_detail_rpt_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > asset_detail_rpt_final_period;
  inline int	Get_asset_detail_rpt_final_period() {
		return asset_detail_rpt_final_period; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > asset_detail_rpt_start_period;
  inline int	Get_asset_detail_rpt_start_period() {
		return asset_detail_rpt_start_period; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > asset_id;
  inline xstring	Get_asset_id() {
		return asset_id; }
  inline void Set_asset_id(const xstring &v) {
		asset_id.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > asset_proj_defn;
  inline xstring	Get_asset_proj_defn() {
		return asset_proj_defn; }
  inline void Set_asset_proj_defn(const xstring &v) {
		asset_proj_defn.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > balloon_term;
  inline int	Get_balloon_term() {
		return balloon_term; }
  inline void Set_balloon_term(const int &v) {
		balloon_term.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > category_id;
  inline xstring	Get_category_id() {
		return category_id; }
  inline void Set_category_id(const xstring &v) {
		category_id.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > commencement_period;
  inline int	Get_commencement_period() {
		return commencement_period; }
  inline void Set_commencement_period(const int &v) {
		commencement_period.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > coupon;
  inline double	Get_coupon() {
		return coupon; }
  inline void Set_coupon(const double &v) {
		coupon.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > credit_score;
  inline double	Get_credit_score() {
		return credit_score; }
  inline void Set_credit_score(const double &v) {
		credit_score.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > current_face;
  inline double	Get_current_face() {
		return current_face; }
  inline void Set_current_face(const double &v) {
		current_face.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > existing_asset_indicator;
  inline int	Get_existing_asset_indicator() {
		return existing_asset_indicator; }
  inline void Set_existing_asset_indicator(const int &v) {
		existing_asset_indicator.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > hel_issuer;
  inline xstring	Get_hel_issuer() {
		return hel_issuer; }
  inline void Set_hel_issuer(const xstring &v) {
		hel_issuer.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > historical_loan_size_effect_defn;
  inline xstring	Get_historical_loan_size_effect_defn() {
		return historical_loan_size_effect_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > history_directory;
  inline xstring	Get_history_directory() {
		return history_directory; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > interest_only_mths;
  inline int	Get_interest_only_mths() {
		return interest_only_mths; }
  inline void Set_interest_only_mths(const int &v) {
		interest_only_mths.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > intex_dealname;
  inline xstring	Get_intex_dealname() {
		return intex_dealname; }
  inline void Set_intex_dealname(const xstring &v) {
		intex_dealname.setValue(v); }
	Attribute::Proxy <SimpleArray<double>, DESCRIPTOR_TABLE > loan_purp;

    inline void Set_loan_purp(const SimpleArray<double> &v) {
		loan_purp.setValue(v); 
    } 
    inline SimpleArray<double>	Get_loan_purp() { 
		return loan_purp;
    }
	void Set_loan_purp(const long index, const double &value);
	inline double Get_loan_purp(const long index) const {
		return loan_purp.operator[] (index);
	}
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > mbs_collateral_defn;
  inline xstring	Get_mbs_collateral_defn() {
		return mbs_collateral_defn; }
  inline void Set_mbs_collateral_defn(const xstring &v) {
		mbs_collateral_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > mbs_prepmt_defn;
  inline xstring	Get_mbs_prepmt_defn() {
		return mbs_prepmt_defn; }
  inline void Set_mbs_prepmt_defn(const xstring &v) {
		mbs_prepmt_defn.setValue(v); }
	Attribute::Proxy <SimpleArray<double>, DESCRIPTOR_TABLE > occupancy;

    inline void Set_occupancy(const SimpleArray<double> &v) {
		occupancy.setValue(v); 
    } 
    inline SimpleArray<double>	Get_occupancy() { 
		return occupancy;
    }
	void Set_occupancy(const long index, const double &value);
	inline double Get_occupancy(const long index) const {
		return occupancy.operator[] (index);
	}
	Attribute::Proxy <int, DESCRIPTOR_TABLE > offset_mths;
  inline int	Get_offset_mths() {
		return offset_mths; }
  inline void Set_offset_mths(const int &v) {
		offset_mths.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > original_face;
  inline double	Get_original_face() {
		return original_face; }
  inline void Set_original_face(const double &v) {
		original_face.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > original_ltv;
  inline double	Get_original_ltv() {
		return original_ltv; }
  inline void Set_original_ltv(const double &v) {
		original_ltv.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > original_term;
  inline int	Get_original_term() {
		return original_term; }
  inline void Set_original_term(const int &v) {
		original_term.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > origination_mth;
  inline int	Get_origination_mth() {
		return origination_mth; }
  inline void Set_origination_mth(const int &v) {
		origination_mth.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > origination_yr;
  inline int	Get_origination_yr() {
		return origination_yr; }
  inline void Set_origination_yr(const int &v) {
		origination_yr.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > pool_id;
  inline int	Get_pool_id() {
		return pool_id; }
  inline void Set_pool_id(const int &v) {
		pool_id.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > prepmt_forecast_defn;
  inline xstring	Get_prepmt_forecast_defn() {
		return prepmt_forecast_defn; }
  inline void Set_prepmt_forecast_defn(const xstring &v) {
		prepmt_forecast_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > prepmt_model_defn;
  inline xstring	Get_prepmt_model_defn() {
		return prepmt_model_defn; }
  inline void Set_prepmt_model_defn(const xstring &v) {
		prepmt_model_defn.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > prepmt_penalty_mths;
  inline int	Get_prepmt_penalty_mths() {
		return prepmt_penalty_mths; }
  inline void Set_prepmt_penalty_mths(const int &v) {
		prepmt_penalty_mths.setValue(v); }
	Attribute::Proxy <SimpleArray<double>, DESCRIPTOR_TABLE > prepmt_rates;

    inline void Set_prepmt_rates(const SimpleArray<double> &v) {
		prepmt_rates.setValue(v); 
    } 
    inline SimpleArray<double>	Get_prepmt_rates() { 
		return prepmt_rates;
    }
	void Set_prepmt_rates(const long index, const double &value);
	inline double Get_prepmt_rates(const long index) const {
		return prepmt_rates.operator[] (index);
	}
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::Proxy <SimpleArray<double>, DESCRIPTOR_TABLE > property_types;

    inline void Set_property_types(const SimpleArray<double> &v) {
		property_types.setValue(v); 
    } 
    inline SimpleArray<double>	Get_property_types() { 
		return property_types;
    }
	void Set_property_types(const long index, const double &value);
	inline double Get_property_types(const long index) const {
		return property_types.operator[] (index);
	}
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > pv_timing;
  inline xstring	Get_pv_timing() {
		return pv_timing; }
  inline void Set_pv_timing(const xstring &v) {
		pv_timing.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > regional_hpi;
  inline double	Get_regional_hpi() {
		return regional_hpi; }
  inline void Set_regional_hpi(const double &v) {
		regional_hpi.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > remaining_term;
  inline int	Get_remaining_term() {
		return remaining_term; }
  inline void Set_remaining_term(const int &v) {
		remaining_term.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > servicing_fee;
  inline double	Get_servicing_fee() {
		return servicing_fee; }
  inline void Set_servicing_fee(const double &v) {
		servicing_fee.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > shift_defn;
  inline xstring	Get_shift_defn() {
		return shift_defn; }
  inline void Set_shift_defn(const xstring &v) {
		shift_defn.setValue(v); }
	Attribute::Proxy <SimpleArray<double>, DESCRIPTOR_TABLE > states;

    inline void Set_states(const SimpleArray<double> &v) {
		states.setValue(v); 
    } 
    inline SimpleArray<double>	Get_states() { 
		return states;
    }
	void Set_states(const long index, const double &value);
	inline double Get_states(const long index) const {
		return states.operator[] (index);
	}
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > subprime_defn;
  inline xstring	Get_subprime_defn() {
		return subprime_defn; }
  inline void Set_subprime_defn(const xstring &v) {
		subprime_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > use_eom_scen_rates;
  inline xstring	Get_use_eom_scen_rates() {
		return use_eom_scen_rates; }
  inline void Set_use_eom_scen_rates(const xstring &v) {
		use_eom_scen_rates.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > valn_date_offset_mths;
  inline int	Get_valn_date_offset_mths() {
		return valn_date_offset_mths; }
  inline void Set_valn_date_offset_mths(const int &v) {
		valn_date_offset_mths.setValue(v); }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > asset_detail_rpt_flag;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > index;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > issuer;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > loan_type;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > orig_proj_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > orig_proj_start_yr;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > output_file;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > output_path;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > proj_date_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_yr;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > start_period;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(ADCO_ASSET* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// ABS Auto Setup
#line 1 "abs_auto_setup.adco_asset.for"
void abs_auto_setup(int t, int cal_yr, int cal_mth, int ad_loan_type, int offset, int histyr, int histmth, char* ADDataFileDir, double* smm_forecast);

// ABS HEL Setup
#line 1 "abs_hel_setup.adco_asset.for"
void abs_hel_setup(int t, int cal_yr, int cal_mth, int ad_loan_type, int offset, int histyr, int histmth, char* ADDataFileDir, double* smm_forecast, double* smm_cashout_forecast, double* smm_credit_cure_forecast, double* smm_refi_forecast, double* smm_turnover_forecast);

// ABS MH Setup
#line 1 "abs_mh_setup.adco_asset.for"
void abs_mh_setup(int t, int cal_yr, int cal_mth, int ad_loan_type, int offset, int histyr, int histmth, char* ADDataFileDir, double* smm_forecast);

// CCY Rate Forecast
#line 1 "ccy_rate_forecast.adco_asset.for"
void ccy_rate_forecast(int t, int offset, int histyr, int histmth, const adco_cEnumElem& eeCCYType, double cur_mtg_cpn, adco_TimeSeries *& myCCYForecast, double * twoyr_forecast, double * tenyr_forecast, double & spread);

// Error Processing
#line 1 "error_processing.adco_asset.for"
void error_processing(xstring error_detail);

// Get and Extend History
#line 1 "get_history.adco_asset.for"
void get_history(int t, char *loan_type, CAdppmdl& Mdl, adco_TimeSeries *& hist_rates, const adco_cEnumeration& FixedResults, int histmth, int histyr, int msdyr, int msdmth);

// MBS Fixed Rate Setup
#line 1 "mbs_fixed_rate_setup.adco_asset.for"
void mbs_fixed_rate_setup(int t, int cal_yr, int cal_mth, int ad_loan_type, int offset, int histmth, int histyr, char *ADDataFileDir, double* smm_forecast, double* smm_cashout_forecast, double* smm_credit_cure_forecast, double* smm_refi_forecast, double* smm_turnover_forecast);

// Scenario Rate Forecast
#line 1 "scen_rate_forecast.adco_asset.for"
void scen_rate_forecast(int t, int forecast_type, double rateterm, int offset, int startidx, int loopend, double* rateforecast, int shift_defn);

// Setup Prepayment Rates
#line 1 "setup_prepmt_rates.adco_asset.for"
void setup_prepmt_rates(int t);

// Unified Setup
#line 1 "unified_setup.adco_asset.for"
void unified_setup(int t, int cal_yr, int cal_mth, int issuer_type, int offset, int histmth, short histyr, char* ADDataFileDir, double* smm_forecast, double* smm_cashout_forecast, double* smm_credit_cure_forecast, double* smm_refi_forecast, double* smm_turnover_forecast);


//factory
static ADCO_ASSET* makeThis(int isSubmodel, ModelClass *owner, ADCO_ASSET* peer, 
					int mainRebase, const xstring &name, ADCO_ASSET_persistent_object* arrayTemplate);

//constructor
ADCO_ASSET(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
ADCO_ASSET(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~ADCO_ASSET();


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
class ADCO_ASSET_persistent_object : public ADCO_ASSET {


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

	void findTargetColumns() {ADCO_ASSET::findTargetColumns();}
	void createAllShare() {
		ADCO_ASSET::createAllShare();
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
	ADCO_ASSET *&sm_bond_is; //
	ADCO_ASSET *&sm_bond_pv; //
	ADCO_ASSET *&sm_bond_ym; //
	ADCO_ASSET *&sm_mtg_is; //
	ADCO_ASSET *&sm_mtg_pv; //
	ADCO_ASSET *&sm_mtg_ym; //

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~ADCO_ASSET_persistent_object();

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
static ADCO_ASSET_persistent_object* makeThis(int isSubmodel, ModelClass *owner, ADCO_ASSET* peer, 
					int mainRebase, const xstring &name, ADCO_ASSET_persistent_object* arrayTemplate, bool fixedArray);

//constructor
ADCO_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
