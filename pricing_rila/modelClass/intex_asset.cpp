
//MODELCLASS BEGIN
//MODELCLASS adco_asset
//MODELCLASS ann_pba_pba
//MODELCLASS asset_asset
//MODELCLASS automation
//MODELCLASS a_subport_asset
//MODELCLASS bond_aig
//MODELCLASS bond_asset
//MODELCLASS bond_cf_asset
//MODELCLASS bond_portfolio_aig
//MODELCLASS comp_comp
//MODELCLASS eio_asset
//MODELCLASS epa_asset
//MODELCLASS epl_liab
//MODELCLASS fiaafund_liab
//MODELCLASS fiacarvm_liab
//MODELCLASS fia_liab
//MODELCLASS hdg_grp_comp
//MODELCLASS intex_asset
//MODELCLASS invstrat_asset
//MODELCLASS liab_liab
//MODELCLASS mtg_asset
//MODELCLASS mtg_cf_asset
//MODELCLASS rates_economy
//MODELCLASS seg_comp
//MODELCLASS sfas133_gaap
//MODELCLASS sfas97rd_gaap
//MODELCLASS util_rafm
//MODELCLASS END

#if defined(MICROSOFT)
#define access _access
#define mkdir _mkdir
#include <io.h>
#include <direct.h>
#endif


#include <math.h>
#include "xstring.h"
#include "Locator.h"
#include "circtabl.h"
#include "message.h"
#include "MULTIDIST.h"
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
#include "fmlstack.h"
#include "useful.h"
#include "RafmSchedule.h"
#include "DBTable.h"
#include "VariantTable.h"
#include "hashobject.h"
#include "memcount.h"
#include "mvisitor.h"
#include "infdbf.h"
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "msxmldom.h"
#ifdef USEMEMCOUNT
#include "memcount.h"
extern MemCount gMem;
#endif

#define ifkey(x)  if (strcmp(key.c_str(), (x))==0)
extern MY_DLL Parmfile *p;
#include "column2.h"
#include "ModelClass\intex_asset_udf.h"
#include "ModelClass\adco_asset.h"
#include "ModelClass\ann_pba_pba.h"
#include "ModelClass\asset_asset.h"
#include "ModelClass\automation.h"
#include "ModelClass\a_subport_asset.h"
#include "ModelClass\bond_aig.h"
#include "ModelClass\bond_asset.h"
#include "ModelClass\bond_cf_asset.h"
#include "ModelClass\bond_portfolio_aig.h"
#include "ModelClass\comp_comp.h"
#include "ModelClass\eio_asset.h"
#include "ModelClass\epa_asset.h"
#include "ModelClass\epl_liab.h"
#include "ModelClass\fiaafund_liab.h"
#include "ModelClass\fiacarvm_liab.h"
#include "ModelClass\fia_liab.h"
#include "ModelClass\hdg_grp_comp.h"
#include "ModelClass\invstrat_asset.h"
#include "ModelClass\liab_liab.h"
#include "ModelClass\mtg_asset.h"
#include "ModelClass\mtg_cf_asset.h"
#include "ModelClass\rates_economy.h"
#include "ModelClass\seg_comp.h"
#include "ModelClass\sfas133_gaap.h"
#include "ModelClass\sfas97rd_gaap.h"
#include "ModelClass\util_rafm.h"
#pragma optimize( "gs", on )

#include "generatedCppHeader.h"

#line 1 "Intex.extern"
#if defined(__INTEX_ASSET_H_) //WTW - Gen2 - block off entire Extern - too many errors
#define ALLOCATE_INTEX
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#include "xstring.h" //WTW - Gen2 - Not allowed
													 
#define TOWERS_WATSON_USE_DLL 1  /* Only enable if linking (dyn or not) to the MS DLL */
#define TOWERS_WATSON_USE_DYN_DLL 1  /* Only enable if Dynamically linking to the MS DLL */

#define MS_WINNT 1
#define WANT_CDECL_APIENTRY 1
#define ICMO_DLL_EXPOSE 1
#define ICMO_SYS_DLL_EXPOSE 1

#ifdef TOWERS_WATSON_USE_DYN_DLL
#define CALLBK_FCN_PREFIX __cdecl
#endif

#ifdef TOWERS_WATSON_USE_DLL
  //this fixes the structure packing to match that of Intex
  #pragma pack ( push, 8)
#endif

// Start of icmo.h
/* ICMO.H:  Interfacing structure between user-routines and
            Intex Collateralized Mortgage Obligation Subroutines. */

/* NOTE: if your C compiler does not support ANSI prototyping,
         please use the compiler option -DICMO_NO_ANSI_PROTOTYPING */

/* Copyright (c) 1991-2013  by Intex Solutions, Inc.  All rights reserved. */

#ifndef ICMO_STRUCT_DEFINED   /* flag verifies that icmo.h is included */

#include <stdio.h> /* to define NULL */

/* Current version of the subroutines */
#define ICMO_VERSION  "3.3h_p1"     /* May 2015 */
#define ICMO_VERSION_MAJOR   3
#define ICMO_VERSION_MINOR   3
#define ICMO_VERSION_LETTER 'h'  /* ' ' if no letter */
#define ICMO_VERSION_BETA   99   /* 99 for non-beta release */

/* true if current version >= a.bcd */
#define ICMO_VERSION_SUPPORT(a,b,c,d)                             \
  (ICMO_VERSION_MAJOR  > (a) || (ICMO_VERSION_MAJOR  == (a) &&    \
  (ICMO_VERSION_MINOR  > (b) || (ICMO_VERSION_MINOR  == (b) &&    \
  (ICMO_VERSION_LETTER > (c) || (ICMO_VERSION_LETTER == (c) &&    \
  (ICMO_VERSION_BETA  >= (d) )))))))

/* Earliest version supported by these subroutines.  Enables future changes in handling of CDI language features. */
#define ICMO_EARLIEST_VERSION_MAJOR   3
#define ICMO_EARLIEST_VERSION_MINOR   3
#define ICMO_EARLIEST_VERSION_LETTER 'f'   /* ' ' if no letter */
#define ICMO_EARLIEST_VERSION_BETA   99   /* 99 for non-beta release */

/* true if a.bcd is still supported */
#define ICMO_VERSION_STILL_SUPPORTED(a,b,c,d)                                       \
  (ICMO_EARLIEST_VERSION_MAJOR  < (a) || (ICMO_EARLIEST_VERSION_MAJOR  == (a) &&    \
  (ICMO_EARLIEST_VERSION_MINOR  < (b) || (ICMO_EARLIEST_VERSION_MINOR  == (b) &&    \
  (ICMO_EARLIEST_VERSION_LETTER < (c) || (ICMO_EARLIEST_VERSION_LETTER == (c) &&    \
  (ICMO_EARLIEST_VERSION_BETA  <= (d) )))))))

/* ICMO_VERSION_xxx: return values for icmo_version_validate() */
#define ICMO_VERSION_IS_LATEST          0 /* User running most up to date version of subroutines */
#define ICMO_VERSION_IS_PREVIOUS        1 /* User running a previous version of the subroutines */
#define ICMO_VERSION_IS_NOT_SUPPORTED   2 /* User running an unsupported version of subroutines */
#define ICMO_VERSION_NA                 3 /* Unable to find icmosubs.inf file in provided directory or file is stale */

#define MIN_ICMOVERSION_STRING 256        /* Minimum buffer to be passed to icmo_version_validate */

#define INTEX_INTERNAL_USE_ONLY  /* For marking fields designated as internal use only */
#define DEPRECATED               /* For marking deprecated fields */

/* ICMO initialization and finalization */
#define ICMO_INIT      icmo_init( )
#define ICMO_FINALIZE  icmo_finalize( )

/* ICMO environment key identifiers */
typedef int ICMOENVKEY ;
#define ICMOENVKEY_MPI_MODE          1    /* user-selected MPI mode */
#define ICMOENVKEY_MPI_RANK          2    /* MPI rank of process */
#define ICMOENVKEY_MPI_TRACE_LEVEL   3    /* control tracing of MPI activity */
#define ICMOENVKEY_SBH_THRESHOLD     4    /* For Windows - control to improve memory allocation performance */

/* INTEX_MPI_MODE_xx: INTEX MPI modes */
#define INTEX_MPI_MODE_NONE                    0   /* Do not use MPI. */
#define INTEX_MPI_MODE_AUTONOMOUS_WORKER       1   /* Intex subroutines responsible for calling on icmo functions on worker nodes. */
#define INTEX_MPI_MODE_NONAUTONOMOUS_WORKER    2   /* User responsible for calling icmo functions on worker nodes. */


#ifndef TRUE
#define TRUE  1
#define FALSE 0
#endif

#ifndef MONTHS_PER_YEAR
#define MONTHS_PER_YEAR  12   /* January to December */
#define DAYS_PER_MONTH   30   /* 30/360 basis throughout CMO analyses */
#endif

#define MAX_MONTHS_IN_DEALS  (MONTHS_PER_YEAR*100)   /* 100 years */
#define YyyyMmDd long int      /* holds a date, eg. 20030704 (Jul 4 03) */
#define BAD_CALC_RESULTS      9999999.   /* err if got this value */
#define ICMO_NA_CALC_RESULTS  8888888.   /* Not available data */
#define ICMO_NO_WALA  (-999)          /* flag indicates calc default wala */
#define ICMO_NOT_REPORTED     999999.    /* Data value not reported */
#define ICMO_MAX_CF_VECTSIZE_ABSOLUTE(n)  (n)
#define ICMO_MAX_CF_VECTSIZE_ADDL(n)   (-(n))
#define ICMO_NO_MAX_CF_VECTSIZE (-9988) /* dynamic reallocation of cf vectors at runtime. icmo_max_cf_vectsize should not be used with this flag */

#define ICMOSPVAL_NOLIMIT  (1e29)  /* special value for NO_LIMIT */

/*---- for win 16, to prototype called back functions         */
#ifdef MS_WIN16
#ifndef CALLBK_FCN_PREFIX
#define CALLBK_FCN_PREFIX _pascal
#endif
#else
#ifndef CALLBK_FCN_PREFIX
#define CALLBK_FCN_PREFIX
#endif
#endif

#ifdef MS_WINNT
#ifndef CALLBK_FCN_STDCALL
#define CALLBK_FCN_STDCALL __stdcall
#endif
#else
#ifndef CALLBK_FCN_STDCALL
#define CALLBK_FCN_STDCALL
#endif
#endif

#ifdef ICMO_NO_ANSI_PROTOTYPING
#define Args_cdi_user_fcn
#define Args_instruct_body_fcn
#define Args_instruct_trblk_fcn
#define Args_instruct_trblk_updt_fcn
#define Args_instruct_sched_fcn
#define Args_instruct_collat_fcn
#define Args_instruct_index_fcn
#define Args_cluster_user_cftype_fcn
#define Args_cluster_user_fcn
#define Args_cluster_user_free_fcn
#define Args_altfile_fcn
#define Args_altu_errmsg_fcn
#define Args_opinfo_govern_loancf_fcn
#define Args_loan_progress_fcn
#define Args_parse_progress_fcn
#define Args_mt_break_fcn
#define Args_adp_tune_fcn
#define Args_deal_errfcn
#define Args_global_errfcn
#define Args_parse_control_fcn
#define Args_override_asset_parse_fcn
#define Args_altc_userdata_fcn
#define Args_call_start_fcn
#else
#define Args_cdi_user_fcn             char*,int,int,double*
        /* icmop, curper, user_nargs, user_vargs */
#define Args_instruct_body_fcn        char*,char**
#define Args_instruct_trblk_fcn       char*,char**
#define Args_instruct_trblk_updt_fcn  char*,char**,int
#define Args_instruct_sched_fcn       char*,char**
#define Args_instruct_collat_fcn      char*,char**,int,int,int
#define Args_instruct_index_fcn       char*,int,char*,int
#define Args_cluster_user_cftype_fcn  char*,POOL_INFO*
#define Args_cluster_user_fcn         char*,POOL_INFO*,char *,double,char**
#define Args_cluster_user_free_fcn    char*
#define Args_altfile_fcn              void*,char*,char*,void*
#define Args_altu_errmsg_fcn          void*,int,char*,void*
#define Args_opinfo_govern_loancf_fcn void*,POOL_INFO*,PIWORK*
#define Args_loan_progress_fcn        void*,POOL_INFO*,int,int,int,int,void*,void*
#define Args_parse_progress_fcn       void*,POOL_INFO*,int,int,int,int,void*,void*
#define Args_mt_break_fcn             void
#define Args_adp_tune_fcn             int,void*,char*,int*,void*
#define Args_deal_errfcn              ICMO*,ERRINFO*
#define Args_global_errfcn            char*
#define Args_parse_control_fcn        ICMO*, int, ICMO_PARSE_CONTROL*, void *
#define Args_override_asset_parse_fcn ICMO*,POOL_INFO*
#define Args_altc_userdata_fcn        ICMO*,YyyyMmDd,POOL_INFO*,POOL_INFO*,int,double,void*
#define Args_call_start_fcn           ICMO_CALL_START_CONTROL*
#endif

typedef struct _ICMO ICMO ;
typedef struct _STANDARDVAR STANDARDVAR ;
typedef struct _POOL_INFO POOL_INFO ;

/* ICMOSTLBP: student loan benefit program info */

typedef struct  {
    char  *icmostlbp_name ;      /* name of the program */
    int    icmostlbp_type ;      /* benefit program type */
#define ICMOSTLBP_TYPE_RATERED 0 /* rate    reduction program */
#define ICMOSTLBP_TYPE_BALRED  1 /* balance reduction program */
    int    icmostlbp_start_nmon; /* program starting month */
    double icmostlbp_amount ;    /* benefit amount, eg: pct in rate reduction */
    STANDARDVAR *icmostlbp_ppfrac_stdvarp; /* standardvar used for participate frac assumption */
    char  *icmostlbp_full_name;  /* long complete name */
    char  *icmostlbp_description;/* additional descriptive info */
    } ICMOSTLBP ;



#define ICMO_MAX_PIPNUM_CHARS  20  /* Max size of "pool number" string */
#define ICMO_MAX_PITYPE_CHARS  20  /* Max size of "pool type" string */
#define ICMO_MAX_TRNAM_CHARS   20  /* Max length of a tranche name */
#define ICMO_MAX_GRPNAM_CHARS  20  /* Max length of a group   name */
#define ICMO_MAX_CDI_GROUPS   256  /* maximum number of groups that can be specified in the deal model */
#define ICMO_MIN_ALLOWED_ADDL_GROUPS 128  /* minimum number of allowed user-defined groups */
#define ICMO_MAX_GROUPS  ICMO_MAX_CDI_GROUPS+ICMO_MIN_ALLOWED_ADDL_GROUPS  /* absolute maximum number of groups */
#define ICMO_MAX_GROUP_XRS     10  /* Max # of XRS in a group  */
#define ICMO_MAX_GROUP_LOANSTATS 13 /* Max # of group loanstat info avail. */
#define ICMO_MAX_COLL_P_TYPE   16  /* Max # of coll princ types for WL */
#define ICMO_N_MISC_COLL_P_TYPE 5  /* Max # of misc collp types for WL */
#define ICMO_MAX_COLL_I_TYPE   13  /* Max # of coll int types for WL */
#define ICMO_N_MISC_COLL_I_TYPE 3  /* Max # of misc colli types for WL */
#define ICMO_MAX_FACTORS        4  /* # of elements in pi_factors   */
#define ICMO_MAX_INDEXSUBNAME_CHARS (ICMO_MAX_TRNAM_CHARS + 9) /* Max length of the index subname.  To handle ICMOINDEX_BY_TRANCHE_RESOLUTION, we need to handle dealname:tranchename so we add 8(for Intex deal name length) + max tranche name size (ICMO_MAX_TRNAM_CHARS) + 1 (for ':') */
#define ICMO_MAX_STEPUPS       50  /* Max# of steps for any stepup loans*/
#define ICMO_MAX_BALLOON_EXTENSIONS 10 /* Max# of balloon extension controls */
#define ICMO_SEQNO_CHARS       10  /* Buffer size for CDU/CDP dir seq number */

#define ICMO_EFFCOUP char  /* not used yet, in future will be typedef struct */


/* ICMO_INTRATE: interest rate info */

typedef struct  {
    double icmoir_rate ;      /* interest rate value in percent */
    char  *icmoir_rate_expr;  /* nonNull for an interest rate formula */
    }  ICMO_INTRATE ;


/* ICMO_CURRENCY: currency related information */

typedef struct _ICMO_CURRENCY {
    char    *curr_next ;           /* To next CURRENCY structure */
    char    *curr_name ;           /* Currency name (plural) */
    char    *curr_code ;           /* ISO 4217 3-letter currency code */
    int      curr_num  ;           /* ISO 4217 numeric currency code */
    char    *curr_symb_local ;     /* ISO-8859-1 local currency symbol */
    char    *curr_symb_intl ;      /* ISO-8859-1 international currency symbol */
#ifdef UNICODE_SUPPORT
    wchar_t *curr_w_symb_local ;   /* UNICODE local currency symbol */
    wchar_t *curr_w_symb_intl ;    /* UNICOXE international currency symbol */
#endif
    char     curr_symb_precedes ;  /* TRUE if symbol precedes amount */
INTEX_INTERNAL_USE_ONLY  int curr_index ;
    } ICMO_CURRENCY ;


typedef struct _STEPUP_INFO {
    int    stepup_n_steps ;                   /* number of steps */
    int    *stepup_v_terms  ; /* vector of stepup ages of the loan */
    double *stepup_v_values ; /* vector of stepup values*/
    }  STEPUP_INFO ;

typedef struct _PI_ARREARAGE_INFO {
    double   piarr_startbal ; /* starting balance */
    double   piarr_startpmt ; /* starting arr pmt */
    double   piarr_origpmt ;  /* orig. pi payment */
    int      piarr_remterm;   /* if arr still outstanding, pay off here */
    }  PI_ARREARAGE_INFO ;


/* PISTL_STATUS_xx: student loan status */
#define PISTL_STATUS_SCHOOL         0  /* in school */
#define PISTL_STATUS_GRACE          1  /* in grace period */
#define PISTL_STATUS_DEFERRAL       2  /* in deferral */
#define PISTL_STATUS_FORBEARANCE    3  /* in forbearance */
#define PISTL_STATUS_REPAY          4  /* in repayment */
#define PISTL_N_STATUS              5  /* total number of status */

typedef struct _PI_STUDENTLOAN_INFO {
    char    *pistl_description ;    /* text description of the loan */
    char    *pistl_school_type ;    /* text description of school type */
    int      pistl_nmon_to_status[PISTL_N_STATUS]; /* # of month to another status */
    int      pistl_nmon_to_repay ;  /* # of month to scheduled repayment */
    int      pistl_repay_term ;     /* repayment term */
    int      pistl_payments_made ;  /* #of payments made */
    int      pistl_period_reset ;   /* rate reset period. (12 for annually) */
    int      pistl_nmon_to_reset ;  /* # of month to next rate reset */
    int      pistl_force_reset_at_repay; /* reset coupon at repay, used for some private loan only */
    int      pistl_indextypes [PISTL_N_STATUS]; /* index types for floater interest */
    int      pistl_indexlookbacks[PISTL_N_STATUS]; /* #mon to lookback for index value */
    double   pistl_margins [PISTL_N_STATUS]; /* interest margins */
    double   pistl_ratecaps [PISTL_N_STATUS]; /* interest caps */
    double   pistl_used_indexval ;  /* index val used for current rate */
    double   pistl_repayment_fee ;  /* fee charged when entering repayment */
    int      pistl_isp_flag ;       /* TRUE if eligible for Interest Subsidy Payments (ISP) */
    int      pistl_isp_pay_period;  /* ISP pay freq. 3 for quarterly, 1 for monthly */
    int      pistl_isp_nmon_to_pay; /* # mon to next ISP pay month */
    int      pistl_sap_flag ;       /* TRUE if eligible for Special Allowance Payments (SAP) */
    double   pistl_sap_margins [PISTL_N_STATUS]; /* SAP margins */
    int      pistl_sap_indextypes [PISTL_N_STATUS]; /* index types for SAP */
    int      pistl_sap_indexlookbacks[PISTL_N_STATUS]; /* #mon to lookback for SAP index value */
    char    *pistl_sap_rate_expr;   /* explicit SAP rate formula */
    int      pistl_sap_pay_period;  /* SAP pay freq. 3 for quarterly, 1 for monthly */
    int      pistl_sap_nmon_to_pay; /* # mon to next SAP pay month */
    int      pistl_sap_rebate_flag; /* TRUE to allow negative SAP payment */
    int      pistl_int_defers [PISTL_N_STATUS]; /* TRUE/FLASE flag of int defering or not */
    double   pistl_accrued_int;     /* interest accrued, to be capitalized at repay */
    int      pistl_intcap_period;  /* scheduled capitalization of accrued interest frequency. 12 for yearly */
    int      pistl_nmon_to_intcap; /* # mon to next scheduled capitalization of accrued interest */
    int      pistl_status ;         /* current status: PISTL_STATUS_xx */
    int      pistl_has_guar ;       /* covered by Guarantee, loss severity not applicable */
    double   pistl_guar_intpct ;    /* Guarantee interest pct. 100, 98 etc */
    double   pistl_guar_prnpct ;    /* Guarantee principal pct. 100, 98 etc */
    double   pistl_consfee_rate ;   /* Consolidation fee rate */
    int      pistl_paym_reset_flag; /* when to reset payment */
#define PISTL_PAYM_RESET_AT_RATE_CHANGE 0x01 /* reset whenever int rate changes */
#define PISTL_PAYM_RESET_AT_NEGAM       0x02 /* reset when paym not enough to cover int */
#define PISTL_PAYM_RESET_AT_PAYM_FREQ   0x04 /* reset at paym reset period after last reset */
    int      pistl_paym_period_reset ;   /* paym reset period. (12 for annually) */
    int      pistl_paym_nmon_to_reset ;  /* # of month to next paym reset */
    ICMOSTLBP **pistl_v_benefit_programs; /* NULL ended vector of benefit program eligible */
    double  *pistl_v_bp_eligibility_fracs; /* associated with pistl_v_benefit_programs, the corresponding eligibility frac */
    int      pistl_n_units ;         /* number of units */
    double   pistl_frac_n_units;     /* number of units with fraction */
    double   pistl_per_unit_servfee[PISTL_N_STATUS]; /* per unit fee */
    int      pistl_servfee_method ; /* PISTL_SERVFEE_METHOD_xx */
#define PISTL_SERVFEE_METHOD_SUM  0 /* sum of per_unit_servfee, rate based servfee */
#define PISTL_SERVFEE_METHOD_MIN  1 /* min of per_unit_servfee, rate based servfee */
#define PISTL_SERVFEE_METHOD_MAX  2 /* max of per_unit_servfee, rate based servfee */
    int      pistl_ffelp_flag ;       /* TRUE/FALSE flag */
    int      pistl_loan_type ;        /* PISTL_LOAN_TYPE_xx */
#define PISTL_LOAN_TYPE_UNKNOWN       0 /* unknown type  */
#define PISTL_LOAN_TYPE_PRIVATE       1 /* PRIVATE       */
#define PISTL_LOAN_TYPE_CONSOLIDATION 2 /* CONSOLIDATION */
#define PISTL_LOAN_TYPE_STAFFORD      3 /* STAFFORD      */
#define PISTL_LOAN_TYPE_PLUS          4 /* PLUS          */
#define PISTL_LOAN_TYPE_SLS           5 /* SLS           */
#define PISTL_LOAN_TYPE_HEAL          6 /* HEAL          */
#define PISTL_LOAN_TYPE_TERI          7 /* TERI          */
#define PISTL_LOAN_TYPE_OTHER         8 /* OTHER         */
    YyyyMmDd pistl_disbursement_date; /* Disbursement date */
    double   pistl_minpmt[PISTL_N_STATUS]; /* min payment */
    STEPUP_INFO *pistl_repay_stepup_info; /* rate stepup in REPAY */
    }  PI_STUDENTLOAN_INFO ;
#ifdef COMMENT /* meanings of the pi fields for student loan */
/*
  pi_origbal             --- orig balance
  pi_factors[0]          --- current factor
  pi_netcoupon           --- current interest rate
  pi_wala = pi_age       --- # month since loan issue
  pi_origterm            --- loan term from issue to end of repay
  pi_remterm             --- pistl_nmon_to_repay + pistl_repay_term
*/
#endif


typedef struct _PI_REVERSE_MORTGAGE_INFO {
    int      pirml_type           ; /* PIRML_TYPE_xx */
#define PIRML_TYPE_UNKNOWN   0      /* unknown type loan */
#define PIRML_TYPE_HECM      1      /* HECM type loan */
#define PIRML_TYPE_PVT       2      /* PVT (private) type loan */
    int      pirml_init_per ;       /* length of initial period */
    int      pirml_sched_pmt_term ; /* #month sched pmt is made */
    double   pirml_sched_pmt_amt  ; /* monthly sched pmt amt */
    double   pirml_mip_rate       ; /* Mortgage Insurance Premium rate */
    double   pirml_growth_rate    ; /* Growth rate for AVAILABLE_LOC / PRINCIPAL_LIMIT */
#define PIRML_GROWTH_RATE_DEFAULT (-1.)  /* use default value of WAC+MIP */
    double   pirml_servfee_amt    ; /* Monthly servicing amount */
    double   pirml_max_claim_amt  ; /* max claim amount */
    double   pirml_start_principal_limit; /* PRINCIPAL_LIMIT as of simulation start */
    double   pirml_start_available_loc;   /* AVAILABLE_LOC as of simulation start */
    }  PI_REVERSE_MORTGAGE_INFO ;


/* ICMO_CDSINFO: structure for CDS specific information */
typedef struct _ICMO_CDSINFO {
    char   icmocds_princ_funded ;       /* TRUE if CDS is funded */
    char  *icmocds_fund_at_expr ;       /* funding rate expr */
    char   icmocds_covers_loss ;        /* ICMOCDS_COVERS_LOSS_xx */
#define ICMOCDS_COVERS_LOSS_WRITEDOWN         1   /* covers actual loss */
#define ICMOCDS_COVERS_LOSS_IMPLIED_WRITEDOWN 2   /* covers implied_writedown */
    char   icmocds_covers_intshort ;    /* ICMOCDS_COVERS_INTSHORT_xx */
#define ICMOCDS_COVERS_INTSHORT_NONE          0   /* not covered */
#define ICMOCDS_COVERS_INTSHORT_NO_CAP        1   /* covered with no cap */
#define ICMOCDS_COVERS_INTSHORT_FIXED_CAP     2   /* covered with fixed cap */
#define ICMOCDS_COVERS_INTSHORT_VARIBLE_CAP   3   /* covered with varible cap */
    char  *icmocds_intshort_cap_expr ;  /* varible cap rate expr */
    } ICMO_CDSINFO ;



typedef struct _PISERV_INFO {
    double piserv_mastserv_rate ;  /* pool-specific mast serv fee % */
    double piserv_trustee_rate ;   /* pool-specific trustee fee % */
    double piserv_swap_ref_pct ;    /* pct of reference pip to be used by SWAP asset */
    char *piserv_expr_grossrate ;
    char *piserv_expr_servfee ;
    char *piserv_expr_netmargin ;
    char *piserv_expr_resetper ;
    char *piserv_expr_paym_resetper ;
    char *piserv_expr_caplife ;
    char *piserv_expr_capresetper ;
    char *piserv_expr_flrresetper ;
    char *piserv_expr_flrlife ;
    char *piserv_expr_paym_cap ;
    char *piserv_expr_minpmt_pct;  /* arm minpmt_pct expr */
    char *piserv_expr_curpmt ;
    char *piserv_expr_amort ;
    char *piserv_expr_lossamt ;    /* scheduled loss amount */
    char *piserv_expr_addlcash ;   /* additional cash (treated as additional interest) */
    char *piserv_expr_maxdraw ;
    char *piserv_expr_loanrule ;     /* not used */
#define   piserv_indexdep_loanrule  piserv_expr_loanrule  /* not used */
    int   piserv_non_performing;   /* non performing asset */
#define ICMO_ASSET_NON_PERFORMING_NONE        0   /* Performing asset */
#define ICMO_ASSET_NON_PERFORMING_UNSPECIFIED 1   /* Non-performing asset - non-performing type is unspecified */
#define ICMO_ASSET_NON_PERFORMING_DEFAULTED   2   /* Defaulted non-performing asset */
#define ICMO_ASSET_NON_PERFORMING_DEFERRING   3   /* Deferring non-performing asset */
    int   piserv_loan_freq ;       /* payment freq. of the loan */
    int   piserv_nmon_till_nextpay; /* for non monthly loan, used only if normal next paydate already collected. */
    int   piserv_sched_n_vals ;    /* # of elements in schedule */
    double *piserv_sched_vals ;    /* value of elements in schedule */
    int   piserv_prefund_end_per   ; /* # of months till prefund end */
INTEX_INTERNAL_USE_ONLY    char *piserv_raw_collat_string ;  /* for internal use only */
    double *piserv_cash_subaccount_frac ; /* for CASH pool - vector of principal, interest fractions */
#define CASH_SUBACCOUNT_INTEREST  0
#define CASH_SUBACCOUNT_PRINCIPAL 1
    char  *piserv_swap_ref_pip ;    /* SWAP asset's reference pip */
    signed char piserv_contrib_type ;    /* ICMOPI_CONTRIB_xx */
#define ICMOPI_CONTRIB_NORMAL    0  /* normal contribution to the deal */
#define ICMOPI_CONTRIB_REFONLY   1  /* asset is not part of deal, used for SWAP asset reference only */
#define ICMOPI_CONTRIB_SHORT     2  /* asset is a short position, so contribute to deal negatively */
#define ICMOPI_CONTRIB_UNKNOWN (-1) /* unknown contribution type */
    ICMO_CURRENCY *piserv_loan_currencyp ; /* Loan-specific currency. If NULL, this we'll use deal/group currency */
    double piserv_currency_swap_rate ;     /* swap rate from loan to deal/group currency.  */
    ICMO_CDSINFO *piserv_cdsinfop;  /* info specific for CDS asset */
    POOL_INFO *piserv_split_from_pip; /* to original pip from which split */
#define  CM_PISERV_ADDL_SIZE 400
INTEX_INTERNAL_USE_ONLY    char  piserv_internal_use [CM_PISERV_ADDL_SIZE] ;   /* internal buffer */
    }  PISERV_INFO ;

typedef struct _ARM_ROUND {
    double armr_unit   ;  /* unit of the rounding operation. eg: 0.125 */
    char   armr_target ;  /* ICMOARMR_TARGET_xx */
#define ICMOARMR_TARGET_INDEX      1  /* rounding on index value */
#define ICMOARMR_TARGET_NETRATE    2  /* rounding on netrate */
#define ICMOARMR_TARGET_GROSSRATE  3  /* rounding on grossrate */
    char   armr_method ;  /* ICMOARMR_METHOD_xx */
#define ICMOARMR_METHOD_CEIL       1  /* round to higher value */
#define ICMOARMR_METHOD_FLOOR      2  /* round to lower value */
#define ICMOARMR_METHOD_ROUND      3  /* round to nearest value */
    char  *armr_next   ;  /* to next in link list */
    }  ARM_ROUND ;

typedef struct _ARMI_INFO {
    char *armi_next ;              /* Ptr to next armp in linked list */
    int armi_stage_start_mo ;      /* beginning age of armp params. ( 1 for first armp in linked list
                                      if NEXTSTAGE or NEXTARM, 0 if subpool) */
    int armi_index ;               /* ARM index (ICMOI_xx !!) */
    char armi_index_subname[ICMO_MAX_INDEXSUBNAME_CHARS+1]; /* LOOKBKnn or explicit subname  */
    char armi_amort_type ;         /* LOAN_AMORT_xx: amortization rule for NEXTSTAGE with ARM or NEXTARM */
    char armi_negam_limit_action  ; /* action to take when hit negam limit.  Default is to recast. */
    int armi_ntillreset ;          /* #mos till next interest reset */
    int armi_resetper ;            /* #mos in interest reset period */
    int armi_paym_ntillreset ;     /* #mos till next payment reset */
    int armi_paym_resetper ;       /* #mos in payment reset period */
    int armi_can_negam ;           /* TRUE if pool bal can grow */
    int armi_in_teaser ;           /* TRUE if before 1st reset */
    int armi_convertable ;         /* TRUE if can switch to fixed rate */
    int armi_lookback ;            /* offset lag time to ARM index */
    int armi_rounding_method ;     /* see ICMOARM_ROUNDING_METHODS */
    int armi_recastper ;           /* #months between negam recasts */
    int armi_init_recastper ;      /* for handling unusual #months till first recast */
    double armi_index_multiplier ; /* ARM index rate coefficient or 0. if not set */
    double armi_netmargin ;        /* percentage above index */
    double armi_caplife ;          /* max NET interest rate ever */
    double armi_capresetper ;      /* max interest rate reset */
    double armi_flrlife ;          /* min NET interest rate ever */
    double armi_flrresetper ;      /* min interest rate reset */
    double armi_max_negam ;        /* max factor ever */
    double armi_payment_cap ;      /* max increase % in monthly P+I */
    double armi_payment_floor ;    /* max decrease % in monthly P+I */
    double armi_known_next_netrate;/* if soon reset of interest rate */
    double armi_orig_grossrate;    /* grossrate at pool origination */
    double armi_indexval ;         /* if >0, rate used at last reset */
    double armi_prev_indexval ;    /* if >0, rate used 2ndlast reset */
    double armi_minpmt_pct ;       /* payment % of scheduled P+I for LOAN_AMORT_MINPMT type */
    double armi_init_percap ;      /* if >0, 1st periodic cap */
    int    armi_init_resetper ;    /* if >0, 1st reset period length (for informational purposes only) */
    ARM_ROUND *armi_roundp;        /* expanded ARM rounding methods */
    STEPUP_INFO *armi_stepup_info; /* additional info for STEPUP loan */
    PISERV_INFO *armi_piservp;     /* NULL, or unusual serv/mastserv info if NEXTSTAGE or NEXTARM */
    /* internal fields for ARM subpools */
INTEX_INTERNAL_USE_ONLY    double armi_subpool_frac ;     /* Fraction of curbalance (0<x<1) */
INTEX_INTERNAL_USE_ONLY    double armi_subpool_netrate ;  /* starting netrate of this sub-pool */
INTEX_INTERNAL_USE_ONLY    double armi_subpool_servrate ; /* starting servrate of this sub-pool*/
    }  ARM_INFO ;
#define NO_ARMI_CAPLIFE      99999.   /* no limit to int life rate up */
#define NO_ARMI_CAPRESETPER  99999.   /* no limit to int reset up */
#define NO_ARMI_FLRLIFE          0.   /* no limit to int life rate down */
#define NO_ARMI_FLRRESETPER  99999.   /* no limit to int reset down */
#define NO_ARMI_MAX_NEGAM    99999.   /* no limit to neg amortization */
#define NO_ARMI_PAYMENT_CAP      0.   /* no limit to pmt reset% up/down */

#define ARMI_INDEX_STEPUP  (-1)   /* ARM is really a step-up loan */
#define ARMI_DUMMY_INDEX  (-999)  /* For ARM and NEXTARM - reset by netmargin value/formula only */

#define ARMI_NEGAM_LIMIT_ACTION_RECAST   0  /* default - at negam limit, recast asset */
#define ARMI_NEGAM_LIMIT_ACTION_IO       1  /* at negam limit, set curpmt to scheduled interest.  IO only */

/* BOND_CALLINFO: Resulting vectors (yields, wals, durn, conv) for call and
                  put schedules for bonds only */

typedef struct _BOND_CALLINFO {
    int    bond_callinfo_n_calls;           /* #of yield-to-call in vect */
    double *bond_callinfo_vyields_to_call;  /* yield-to-call vect */
    double *bond_callinfo_vmoddurn_to_call; /* mod. duration-to-call vect */
    double *bond_callinfo_vconvex_to_call;  /* convexity-to-call vect */
    double *bond_callinfo_vwal_to_call;     /* wal-to-call vect */
    double *bond_callinfo_call_accrued_ints; /* vector of accrued int. adjustments to call/put prices, if not on paydate */
    int    bond_callinfo_n_puts;            /* #of yield-to-put in vect */
    double *bond_callinfo_vyields_to_put ;  /* yield-to-put vect */
    double *bond_callinfo_vmoddurn_to_put ; /* mod. duration-to-put vect */
    double *bond_callinfo_vconvex_to_put ;  /* convexity-to-put vect */
    double *bond_callinfo_vwal_to_put ;     /* wal-to-put vect */
    double *bond_callinfo_put_accrued_ints; /* vector of accrued int. adjustments to call/put prices, if not on paydate */
    }  BOND_CALLINFO  ;

typedef struct _PIBOND_INFO {   /* Corporate/Treasury bonds */
    /* Unprocessed fields */
    double    pibond_orig_coupon_rate            ;  /* RATE */
    char      pibond_call_announcement_flag      ;  /* CLDIND */
    char      pibond_orig_accrual_cal            ;  /* OACCR */
    char      pibond_accrual_cal                 ;  /* ACCR */
    YyyyMmDd  pibond_maturity_date               ;  /* MDAT */
    YyyyMmDd  pibond_dated_date                  ;  /* DDAT */
    YyyyMmDd  pibond_1st_intpay_date             ;  /* FCPN */
    YyyyMmDd  pibond_last_intpay_date            ;  /* LCPN */
    char      pibond_issue_feature_codes   [13]  ;  /* IFC */
    char      pibond_coupon_type                 ;  /* COUPT */
    char      pibond_maturity_type               ;  /* MATT */
    char      pibond_matur_price_type            ;  /* MATPT */
    char      pibond_floater_type                ;  /* FLTT */
    char      pibond_floater_ind                 ;  /* ADJIND */
    char      pibond_paym_disburs_type           ;  /* PDT   */
    char      pibond_credit_sens_indicator       ;  /* CRSENS*/
    YyyyMmDd  pibond_int_accrual_date            ;  /*INTACCL*/
    char      pibond_cur_coupon_type             ;  /*CURCTYPE*/
    YyyyMmDd  pibond_def_int_conversion_date     ;  /*DFCNVDT*/
    char      pibond_primary_currency_code  [4]  ;  /* IOISC1 */
    YyyyMmDd  pibond_cur_call_date               ;  /* CRDT */
    double    pibond_cur_call_price              ;  /* CRPR */
    YyyyMmDd  pibond_next_call_date              ;  /* NXDT */
    double    pibond_next_call_price             ;  /* NXPR */
    YyyyMmDd  pibond_refund_restrict_date        ;  /* REFDT */
    double    pibond_refund_restrict_price       ;  /* REFPR */
    YyyyMmDd  pibond_1st_par_call_date           ;  /* PARDT */
    char      pibond_call_timing            [3]  ;  /* CTIM */
    char      pibond_call_notice            [4]  ;  /* CNOT */
    char      pibond_call_price_quote_method     ;  /* CQMTH */
    char      pibond_trading_status              ;  /* TRDS  */
    char      pibond_cnvexer_code           [5]  ;  /* CONC */
    char      pibond_cnvexer_secid         [13]  ;  /* CONS */
    char      pibond_cnvexer_secid_marker        ;  /* CONT */
    char      pibond_cnvexer_curcode       [ 4]  ;  /* CONY */
    double    pibond_cnvexer_exchrate            ;  /* CONX */
    double    pibond_cnvexer_rate                ;  /* CONR */
    double    pibond_cnvexer_price               ;  /* CONV */
    YyyyMmDd  pibond_cnvexer_expdate             ;  /* COND */
    char      pibond_cnvexer_rate_marker         ;  /* CONM */
    char      pibond_cnvexer_price_marker        ;  /* CONP */
    char      pibond_amt_outstanding_mark        ;  /* AMMK */
    YyyyMmDd  pibond_amt_outstanding_date        ;  /* AMDT */
    char      pibond_issue_description     [63]  ;  /* IDES */
    char      pibond_security_type          [4]  ;  /* SECT */
    char      pibond_collat_for_issue       [4]  ;  /* TYP2 */
    char      pibond_industry_code          [3]  ;  /* IGC */
    char      pibond_payment_freq           [3]  ;  /* IPFC */
    char      pibond_issuer_type                 ;  /* ISSRT */
    YyyyMmDd  pibond_issue_date                  ;  /* ISDT */
    double    pibond_issue_size                  ;  /* IAMT */
    double    pibond_issue_price                 ;  /* IPRI */
    char      pibond_active_security_flag        ;  /* ACTF */
    char      pibond_issue_status                ;  /* ISSS */
    double    pibond_amt_outstanding             ;  /* AMTO */
    YyyyMmDd  pibond_next_put_date               ;  /* NPDT */
    double    pibond_next_put_price              ;  /* NPPR */
    char      pibond_put_price_quote_method      ;  /* PQMTH */
    char      pibond_put_features_codes     [9]  ;  /* PUFC */
    YyyyMmDd  pibond_next_sink_date              ;  /* NSFD */
    double    pibond_next_sink_price             ;  /* NSFP */
    double    pibond_next_sink_amount            ;  /* NSFM */
    char      pibond_poison_put_flag        [8]  ;  /* NSPUFC */
    YyyyMmDd  pibond_pik_date                    ;  /* PIKEND */
    double    pibond_pik_rate                    ;  /* PIKRATE */
    char      pibond_state_code             [3]  ;  /* STAT */
    char      pibond_tax_status_federal          ;  /* TAXF */
    char      pibond_country_inc            [3]  ;  /* CTRI*/
    char      pibond_country_reg            [3]  ;  /* CTRR*/
    char      pibond_cross_national_code         ;  /* CNIND */
    char      pibond_marginable_code             ;  /* MRGN */
    char      pibond_NASDAQ_center_code          ;  /* NASD  */
    char      pibond_rule_144a_indicator         ;  /* R144A */
    char      pibond_settlement_ind              ;  /*SETIND */
    YyyyMmDd  pibond_settlement_date             ;  /* SETDT*/
    YyyyMmDd  pibond_indenture_date              ;  /* INDDT*/
    char      pibond_backing_ind                 ;  /* BKIND */
    char      pibond_linkage_origin              ;  /*LINKORG*/
    char      pibond_underwriter_abbr       [5]  ;  /* UNDA*/
    char      pibond_offering_type               ;  /*OFFTYPE*/
    YyyyMmDd  pibond_sale_date                   ;  /*SALEDATE*/
    double    pibond_orig_issue_amt_series       ;  /*ORIGSER*/
    char      pibond_use_of_proceeds        [3]  ;  /*PROCEEDS*/
    char      pibond_instr_type             [3]  ;  /*INSTRUM */
    YyyyMmDd  pibond_refund_issue_date           ;  /*REFDDAT */
    YyyyMmDd  pibond_escrow_end_date             ;  /*ESCREND */
    char      pibond_series_name           [21]  ;  /*SERIES */
    char      pibond_project_name          [31]  ;  /*PROJECT*/
    char      pibond_conduit_issuer_name   [63]  ;  /*CONDUIT*/
    char      pibond_bank_qual_ind               ;  /*BANKQ */
    char      pibond_bond_insurer_code      [6]  ;  /*BONDINS*/
    char      pibond_mort_insurer_code      [3]  ;  /*MORTINS*/
    char      pibond_other_enh_type         [3]  ;  /*ENHANTYP*/
    char      pibond_other_enh_company      [51] ;  /*ENHANCO */
    char      pibond_backing_code                ;  /*BKCODE*/
    char      pibond_backing_entity_name    [41] ;  /*BKNAME */
    double    pibond_backing_pct                 ;  /*BKPCT  */
    char      pibond_linkage_result         [3]  ;  /*LINKRSLT*/
    char      pibond_backed_security_id     [13] ;  /* BKUID */
    char      pibond_lead_manager           [9]  ;  /*LEADMGR*/
    char      pibond_pay_agent              [9]  ;  /*PAYAGENT*/
    char      pibond_remarket_agent         [9]  ;  /*REMARKET*/
    char      pibond_tender_agent           [9]  ;  /*TENDAGNT*/
    char      pibond_transf_agent           [9]  ;  /*TRANSFER*/
    char      pibond_trustee                [9]  ;  /*TRUSTEE */
    char      pibond_letter_of_credit_ind        ;  /*LOCIND*/
    char      pibond_co_manager_ind              ;  /* COIND*/
    char      pibond_counsel_ind                 ;  /*COUNSIND*/
    char      pibond_letter_of_credit_type  [4]  ;  /*LOCTYPE*/
    YyyyMmDd  pibond_loc_exp_date                ;  /*LOCEXPIR*/
    char      pibond_letter_of_credit_bank  [52] ;  /*LOCBANK*/
    char      pibond_co_manager             [57] ;  /*COMGR  */
    char      pibond_bond_counsel           [61] ;  /*COUNSEL*/
    char      pibond_default_type                ;  /*DEFTYPE*/
    YyyyMmDd  pibond_default_date                ;  /*DEFDATE */
    char      pibond_default_event          [3]  ;  /*DEFEVENT*/
    char      pibond_default_status         [3]  ;  /*DEFSTAT */
    YyyyMmDd  pibond_next_tender_date            ;  /* NTDT */
    double    pibond_next_tender_price           ;  /* NTPR */
    char      pibond_tender_price_quot_code      ;  /* TQMTH */
    char      pibond_tender_code                 ;  /*TENCODE*/
    char      pibond_tender_timing               ;  /*TTIM   */
    YyyyMmDd  pibond_tender_start_date           ;  /*TENSTART*/
    char      pibond_cond_call_features_code [17];  /* CCFC */
    char      pibond_opt_call_type               ;  /* OCT  */
    char      pibond_call_make_whole_flag        ;  /* CMWF */
    YyyyMmDd  pibond_recent_call_announc_date        ;  /* CLDDT*/
    double    pibond_recent_call_announc_price       ;  /* CLDPR*/
    double    pibond_recent_call_announc_amt         ;  /*CLDAMT*/
    char      pibond_recent_call_announc_amt_fl      ;  /*CLDFLG*/
    char      pibond_recent_call_announc_prem_code   ;  /*CLDPM */
    char      pibond_recent_call_announc_sink_code   ;  /*CLDSF */
    char      pibond_recent_call_announc_redm_code   ;  /*CLDRD */
    YyyyMmDd  pibond_recent_call_announc_resc_date   ;  /*CLDLRD*/

    /* Processed fields */
    double    pibond_discount_rate;    /* discount rate for bills, or 0*/
INTEX_INTERNAL_USE_ONLY    char      pibond_bond_floater ;    /* internal flag, TRUE=FRN */
INTEX_INTERNAL_USE_ONLY    char      pibond_bond_expired ;    /* internal flag, TRUE=bond exp. (has bal=0) */
INTEX_INTERNAL_USE_ONLY    char      pibond_nocall ;          /* internal flag, TRUE=no calls */
INTEX_INTERNAL_USE_ONLY    int       pibond_freq ;            /* # coupons/year (2=semiannual) */
    YyyyMmDd  pibond_idc_info_date ;  /* date of IDC information tape */
    YyyyMmDd  pibond_accru_date ;      /* start of updated accrual period */
    YyyyMmDd  pibond_next_date ;       /* end of updated accrual period */
    int       pibond_daycount_method;  /* ICMO_DAYCOUNT_xx: int accrual cal */
    int       pibond_ntill_coupon ;    /* # mos till next coupon */
    char      pibond_north_american;   /* TRUE=US/Canada FALSE=otherwise */
    char      pibond_country[4];       /* country of issuer */
    int       pibond_n_calls;          /* #vals in call schedules... */
    YyyyMmDd *pibond_call_dates;       /* ... vector of call dates */
    double   *pibond_call_prices;      /* ... vector of call prices/100 */
    int       pibond_n_puts ;          /* #vals in put schedules... */
    YyyyMmDd *pibond_put_dates;        /* ... vector of put dates */
    double   *pibond_put_prices;       /* ... vector of put prices/100 */
    int       pibond_n_req_sinks;      /* #vals in mandatory sinking fund schedules... */
    YyyyMmDd *pibond_req_sink_dates;   /* ... vector of mandatory sink dates */
    double   *pibond_req_sink_prices;  /* ... vector of mandatory sink prices/100 */
    double   *pibond_req_sink_princs;  /* ... vector of mandatory sink principal$ */
    int       pibond_n_opt_sinks;      /* #vals in mandatory sinking fund schedules... */
    YyyyMmDd *pibond_opt_sink_dates;   /* ... vector of mandatory sink dates */
    double   *pibond_opt_sink_prices;  /* ... vector of mandatory sink prices/100 */
    double   *pibond_opt_sink_princs;  /* ... vector of mandatory sink principal$ */
    int       pibond_n_supterms;       /* #vals in supplementary terms&conditions sinking fund schedules... */
    char     *pibond_supterm_codes;    /* ... vector of supplementary terms&conditions codes (4bytes*#) */
    YyyyMmDd *pibond_supterm_dates;    /* ... vector of supplementary terms&conditions sink dates */
    double   *pibond_supterm_values;   /* ... vector of supplementary terms&conditions sink values */
    int       pibond_n_ext;            /* #vals in extension schedules... */
    YyyyMmDd *pibond_ext_dates;        /* ... vector of extension dates */
    int       pibond_n_steps;          /* #vals in step schedules... */
    YyyyMmDd *pibond_step_dates;       /* ... vector of step dates */
    double   *pibond_step_rates;       /* ... vector of step rates */
    int       pibond_n_ratings;        /* #vals in rating vects... */
    char     *pibond_rating_agencies;  /* ... vector of rating agency codes (2bytes*#) */
    char     *pibond_rating_type_codes;  /* ... vector of rating type codes (2bytes*#) */
    YyyyMmDd *pibond_rating_dates;     /* ... vector of rating dates */
    char     *pibond_ratings;          /* ... vector of ratings (5bytes*#) */
    int       pibond_n_shared_deriv_ids;  /* #vals in next vect... */
    char     *pibond_shared_deriv_ids;    /* ... vector of deriv. ids */
    int       pibond_n_deriv_back_ids;    /* #vals in next vects... */
    char     *pibond_deriv_back_ids;      /* ... vector of backing ids  */

    /* Output fields */
    BOND_CALLINFO *pibond_bondcall_infop; /* pointer to BOND_CALLINFO */
    int       pibond_error_level;         /* error level of the processed Bond Data */
#define PIBOND_ERROR_LEVEL_OK         0   /* no error found */
#define PIBOND_ERROR_LEVEL_WARNING    1   /* some minor fields missing */
#define PIBOND_ERROR_LEVEL_LIGHT      2   /* some unimportant date fields missing */
#define PIBOND_ERROR_LEVEL_MODERATE   3   /* some fields used in CF calcs missing; assumptions used */
#define PIBOND_ERROR_LEVEL_HEAVY      4   /* key fields used in CF calcs missing; assumptions used */
    char     *pibond_error_messages;      /* descriptions of the missing/incorrect data */

    char pibond_future[100] ;
    }  PIBOND_INFO ;



typedef struct _PREPHIST {
    float prep_1mo ;               /* historical 1 month prepay rate */
    float prep_3mo ;               /* historical 3 month prepay rate */
    float prep_6mo ;               /* historical 6 month prepay rate */
    float prep_9mo ;               /* historical 9 month prepay rate */
    float prep_12mo ;              /* historical 1 year prepay rate */
    float prep_life ;              /* historical lifetime prepay rate */
    }  PREPHIST ;
#define  PREPHISTVAL_NA    99999.  /* value not available */

/* LOANDATA: Also known as COMMERCIAL_OP.  Linked list of loan attributes
             provided by issuer. */

#define LOANDATA_LEN      40  /* max length of loandata keywords */
typedef struct {
    double loandata_dblval ;    /* amount (annualized) at asof date */
    YyyyMmDd loandata_asof_date;/* data gathering end-of-period */
    char *loandata_strval ;     /* string value of the commercial op */
    void *loandata_forecast_info; /* user forecasted info */
    char loandata_val_is_derived;      /* bit flag for derived info */
#define LOANDATA_VAL_IS_DERIVED        0x1  /* value was calc'ed from other data */
#define LOANDATA_VAL_HAS_TRANSLATION   0x2  /* loandata translation is available through ICMO_LOANDATA_TRANSLATION */
    char loandata_has_dblval;   /* TRUE if dblval not NA ... */
#define LOANDATA_DBLVAL_BASIC       1  /* dblval is the original value */
#define LOANDATA_DBLVAL_FROM_STRVAL 2  /* dblval derived from strval */
    char *loandata_next ;       /* NULL, or to next in linked list */
    char loandata_name[LOANDATA_LEN+1] ; /* Data item,eg "NOI" */
    } LOANDATA ;


/* ICMOLOANDATA_INFO_xx: flags for icmo_get_loandata_val() to return special info */
#define ICMOLOANDATA_INFO_N_FORECASTS (-1) /* get forecasted vector length */

/* ICMOLOANDATA_SET_xx: flags for icmo_set_loandata_forecast() */
#define ICMOLOANDATA_SET_OVERRIDE (-9998)   /* treat forecast as a permanent override of "known" loandata values */


/* Re-direct old commercialop names to loandata: */
#define COMMERCIALOP_LEN    LOANDATA_LEN
#define COMMERCIAL_OP       LOANDATA
#define loanattr_commercialopp  loanattr_loandatap
#define commercialop_next   loandata_next
#define commercialop_name   loandata_name
#define commercialop_asof_date       loandata_asof_date
#define commercialop_val_is_derived  loandata_val_is_derived
#define commercialop_has_dblval      loandata_has_dblval
#define commercialop_dblval          loandata_dblval
#define commercialop_strval          loandata_strval
#define commercialop_has_data  commercialop_has_dblval  /* old name */
#define commercialop_val       commercialop_dblval      /* old name */

typedef struct _COMMERCIAL_PROPERTY {
    char *commercialprop_next ;     /* NULL, or to next in linked list */
    LOANDATA *commercialprop_commercialopp ;  /* property NOI,... */
    char *commercialprop_name ;     /* name of comm'l loan/property */
    char *commercialprop_address ;  /* street/city comm'l loan/prop */
    char *commercialprop_street_address   ;  /* street address comm'l loan/prop */
    char *commercialprop_city_address     ;  /* city  address comm'l loan/prop */
    char commercialprop_state[3] ;  /* property location, e.g. "MA" */
    char commercialprop_zipcode[6]; /* property location, e.g. "02194" */
    char commercialprop_pnum [ ICMO_MAX_PIPNUM_CHARS+1 ] ;  /* Property number */
    char commercialprop_type [ ICMO_MAX_PITYPE_CHARS+1 ] ;  /* MF, IN, HO, etc. */
    double commercialprop_origbal ; /* orig loan$ allocated to this property */
    double commercialprop_curbal ; /* cur loan$ allocated to this property */
    } COMMERCIAL_PROPERTY ;

typedef struct _COMMERCIAL_PNOTE {
    char *pnote_next ;        /* NULL, or to next in linked list */
    char *pnote_tag ;         /* to associate with PNOTE group */
    char *pnote_pip ;         /* casted POOL_INFO to hold note specific info */
    char *pnote_parent_pip ;  /* casted POOL_INFO to parent pip */
    int   pnote_assoc_trno ;  /* if > 0, the associated tranche number */
    int   pnote_main_as_collat; /* TRUE if this is PNOTE MAIN and used as collat */
    } COMMERCIAL_PNOTE ;

typedef struct _BALLOON_EXTENSION {
    int balloonext_nmonths ;        /* postpone balloon this #months */
    int balloonext_amort_type ;     /* LOAN_AMORT_xx: rule during ext */
    double balloonext_pct_extend ;  /* pct of bal to extend (all=100) */
    double balloonext_coupon_stepup;/* increase gross coupon by this % */
    double balloonext_fee_pct;      /* extension fee % rate  */
    int balloonext_fee_apply ;      /* control which month balloon extension fee apply to */
#define ICMOBALLOONEXT_FEE_APPLY_TO_NEXT    0  /* balloon extension fee apply to the next month after scheduled balloon */
#define ICMOBALLOONEXT_FEE_APPLY_TO_BALLOON 1  /* balloon extension fee apply to the scheduled balloon month */
    int balloonext_matured_nmonths ;/* for loans past maturity postpone balloon this #months */
#define ICMOBALLOONEXT_MATURED_SAME -1  /* default: balloonext_matured_nmonths=balloonext_nmonths */
    int balloonext_matured_anchor ; /* for loans past maturity postpone #months after:*/
#define ICMOBALLOONEXT_MATURED_SINCE_CURRENT 0  /* extend #months since first forecasted payment */
#define ICMOBALLOONEXT_MATURED_SINCE_TERM    1  /* extend (maybe ntimes * #months) since balloon scheduled term pi_balloon */
    } BALLOON_EXTENSION ;

#define GEO_INFO_STATE             0
#define GEO_INFO_ORIGINATION_YEAR  1
typedef struct _GEO_INFO {
    char *geo_next ;                /* pointer to next element in linked list */
    int geo_type ;                  /* indicates breakdown type - state, origination year, etc */
    int geo_origination_year ;      /* origination year */
    char geo_state[3] ;             /* state */
    int geo_loan_count ;            /* current # of loans in this breakdown */
    double geo_curbal ;             /* current balance for this breakdown */
    double geo_curbal_pct ;         /* current % balance for this breakdown */
    double geo_loan_count_pct   ;   /* current % of loans in this breakdown */
    } GEO_INFO ;


/* LOANATTR: Raw demographic data provided by WL Issuer.
             Commercial deals may additionally provide for a
             linked list of data concerning operating finances */

#define LOANATTR_LEN    5   /* max length of the loanattr string */
#define loanattr_INTEXCODE_start loanattr_property
#define loanattr_INTEXCODE_end   loanattr_servcode
typedef struct _LOANATTR {
    char loanattr_property   [LOANATTR_LEN+1] ;  /* Property type */
    char loanattr_occupancy  [LOANATTR_LEN+1] ;  /* Occupancy type */
    char loanattr_loantype   [LOANATTR_LEN+1] ;  /* Loan type */
    char loanattr_purpose    [LOANATTR_LEN+1] ;  /* Loan purpose */
    char loanattr_source     [LOANATTR_LEN+1] ;  /* Loan source */
    char loanattr_feature    [LOANATTR_LEN+1] ;  /* Loan feature */
    char loanattr_doc        [LOANATTR_LEN+1] ;  /* Documentation */
    char loanattr_recourse   [LOANATTR_LEN+1] ;  /* Recourse */
    char loanattr_lendertype [LOANATTR_LEN+1] ;  /* Lender type */
    char loanattr_buydown    [LOANATTR_LEN+1] ;  /* Buydown */
    char loanattr_insurance  [LOANATTR_LEN+1] ;  /* PMI Insurance */
    char loanattr_insurcode  [LOANATTR_LEN+1] ;  /* PMI Insurer code */
    char loanattr_servcode   [LOANATTR_LEN+1] ;  /* Code used to identify who a loan is serviced by */
    char loanattr_capitalized[LOANATTR_LEN+1] ;  /* Capitalized loan */
    char loanattr_lien       [LOANATTR_LEN+1] ;  /* Lien Position */
    char loanattr_times30    [LOANATTR_LEN+1] ;  /* #delinq over 1YR */
    char loanattr_grade      [LOANATTR_LEN+1] ;  /* loan grade */
    char loanattr_ym         [LOANATTR_LEN+1] ;  /* Yield maintenance */
    char *loanattr_userstr          ;  /* User-specific info USERSTR */
    char *loanattr_name             ;  /* name of comm'l loan/property */
    char *loanattr_address          ;  /* street/city comm'l loan/prop */
    char *loanattr_street_address   ;  /* street address comm'l loan/prop */
    char *loanattr_city_address     ;  /* city  address comm'l loan/prop */
    int loanattr_n_balloon_extensions; /* # of contracted balloon extension controls. */
    BALLOON_EXTENSION *loanattr_vballoon_extensions;  /* vector of contracted balloon extension controls, starts from [0]*/
    int loanattr_orig_balloon       ;  /* original value for pi_balloon in case already extended balloons */
    int loanattr_draw_term          ;  /* contract #mos draw period */
    double loanattr_max_draw        ;  /* contract line-of-credit $amt */
    double loanattr_cur_draw        ;  /* utilized $amt of line-of-cred */
    double loanattr_actfactor       ;  /* current actual account factor */
#define MAX_N_1ST_ACCDAYS  13
    double loanattr_v_accrue_days[MAX_N_1ST_ACCDAYS+1];/* vector of odd accrual days */
    int loanattr_pay_dd             ;  /* if >0, pmt due day of month */
    char loanattr_cash_dd            ;  /* if >0, actual day that cash is received */
    int loanattr_xlinkno            ;  /* if != 0, cross-linked id# */
    int loanattr_tba                ;  /* flag for generic loan in/from reinvestment collateral */
#define ICMOLOAN_TBA_NO         0      /* not a TBA loan */
#define ICMOLOAN_TBA_REINVEST   1      /* TBA loan from REINV_COLLAT added to collat list on the fly during CF run */
#define ICMOLOAN_TBA_COLLAT     2      /* loan from normal collat list in CDU - result of BUY_COLLAT from REINV_COLLAT in previous months  */
    char *loanattr_tba_loan_id      ;  /* extended loan ID for copy of TBA loan */
    LOANDATA *loanattr_loandatap    ;  /* list of NOI,DSCR,... info*/
    COMMERCIAL_PROPERTY *loanattr_property_list; /* mult properties in loan */
    COMMERCIAL_PNOTE *loanattr_pnote_list; /* participation note list or parent note if PNOTE pip */
    LOANDATA *loanattr_addl_attributes ;  /* linked list of addition collateral attributes */
    LOANDATA *loanattr_userp ;         /* linked list of user specified collateral attributes */
    GEO_INFO *loanattr_geop         ;  /* linked list of geographic info for agency pools */
    int    loanattr_intrate_method  ;  /* non-standard method used to calculate interest payment */
#define ICMOLOANRATE_ADDON  1  /* add-on method for interest calculation */
    double loanattr_intrate_face    ;  /* face amount of loan interest rate */
    /* The following are reserved for internal use */
INTEX_INTERNAL_USE_ONLY    int  loanattr_copln_future1 ;
INTEX_INTERNAL_USE_ONLY    LOANDATA ** loanattr_coplv_future1 ;
    }  LOANATTR ;

#define COMMERCIAL_PNOTEp(pip)                                          \
  ( (pip)->pi_loanattrp != NULL &&                                      \
    (pip)->pi_loanattrp->loanattr_pnote_list != NULL &&                 \
    (pip)->pi_loanattrp->loanattr_pnote_list->pnote_pip == (char *)(pip)\
    ? (pip)->pi_loanattrp->loanattr_pnote_list : NULL )
#define IS_PNOTE_PIP(pip) ( COMMERCIAL_PNOTEp(pip) != NULL )

typedef struct _LOANSTATx {
    int    loanstatx_n              ;  /* # of loans */
    int    loanstatx_mos_delinq     ;  /* #months past pmt due date */
    double loanstatx_amount         ;  /* last outstanding scheduled balance$ */
    double loanstatx_pmtdue         ;  /* current payment $ due */
    int    loanstatx_sold_mos_ago   ;  /* #months past sale date */
    float  loanstatx_sold_severity  ;  /* % of balance not recovered */
    double loanstatx_actbal         ;  /* last outstanding actual balance$ */
    }  LOANSTATx ;

#define LOANSTAT_INTERNAL_INFO_SIZE (2*sizeof(char*)+sizeof(double))
typedef struct  {
    char   loanstat_internal_info_buff[LOANSTAT_INTERNAL_INFO_SIZE];
    } LOANSTAT_INTERNAL_INFO ;

#define LOANSTAT_00               0  /* not delinquent */
#define LOANSTAT_30               1  /* 30 days delinquent */
#define LOANSTAT_60               2  /* 60 days delinquent */
#define LOANSTAT_90PLUS           3  /* 90+days delinquent, not fc */
#define LOANSTAT_FC               4  /* in foreclosure */
#define LOANSTAT_REO              5  /* in real estate owned */
#define LOANSTAT_SOLD_FC          6  /* was sold at foreclosure sale */
#define LOANSTAT_SOLD_REO         7  /* was sold at REO sale */
#define LOANSTAT_REPURCHASED      8  /* was repurchased by servicer */
#define LOANSTAT_BANKRUPT         9  /* bankrupt loan */
#define LOANSTAT_PASTDUE         10  /* not considered delinquent, but past due date */
#define LOANSTAT_30MINUS         11  /* less than 30 days delinquent */
#define LOANSTAT_MATURED_BALLOON 12  /* Performing matured balloon */
#define LOANSTAT_180PLUS         13  /* 180+days delinquent */
#define N_LOANSTATx_ITEMS        14  /* # LOANSTATx structs in LOANSTAT */

typedef struct _LOANSTAT {  /* add loanstat's to the end; CDU file table-driven */
    LOANSTATx loanstat_vloanstatx [N_LOANSTATx_ITEMS]; /* vector of loanstatx slots */
#define loanstat_delinq_00       loanstat_vloanstatx [LOANSTAT_00      ]
#define loanstat_delinq_30       loanstat_vloanstatx [LOANSTAT_30      ]
#define loanstat_delinq_60       loanstat_vloanstatx [LOANSTAT_60      ]
#define loanstat_delinq_90plus   loanstat_vloanstatx [LOANSTAT_90PLUS  ]
#define loanstat_fc              loanstat_vloanstatx [LOANSTAT_FC      ]
#define loanstat_reo             loanstat_vloanstatx [LOANSTAT_REO     ]
#define loanstat_fc_sold         loanstat_vloanstatx [LOANSTAT_SOLD_FC ]
#define loanstat_reo_sold        loanstat_vloanstatx [LOANSTAT_SOLD_REO]
#define loanstat_repurchased     loanstat_vloanstatx [LOANSTAT_REPURCHASED]
#define loanstat_bankrupt        loanstat_vloanstatx [LOANSTAT_BANKRUPT]
#define loanstat_delinq_pastdue  loanstat_vloanstatx [LOANSTAT_PASTDUE ]
#define loanstat_delinq_30minus  loanstat_vloanstatx [LOANSTAT_30MINUS ]
#define loanstat_matured_balloon loanstat_vloanstatx [LOANSTAT_MATURED_BALLOON]
#define loanstat_delinq_180plus  loanstat_vloanstatx [LOANSTAT_180PLUS ]
    LOANSTAT_INTERNAL_INFO loanstat_internal_info; /* Internal field to be used only by Intex subroutines */
    }  LOANSTAT ;


typedef struct _YIELDMAINT {
    int     ym_nflags ;                /* # months in .. */
    int    *ym_vflags;                 /* ICMOPREPAY_xx: prepay lockout/ym/points vector*/
    double *ym_vpoints;                /* if ICMOPREPAY_POINTS, ICMOPREPAY_MAX_YM_OR_POINTS, ...
                                          - penalty frac of prepay amt */
    int     ym_expires ;               /* Age at which all included yield maintenance provisions for current pool expires.
                                        * Yield maintenance provisions not included by altc_include_prepaypenalty are ignored. */
    double *ym_vymval_in_points_units; /* result of YM_FORMULA in points space.
                                          Available after icmo_eval_sched_cashflows()
                                          called within user's prepay fcn */
    char *ym_formula_toptkn ;          /* YM formula expr */
    char *ym_lockout_toptkn ;          /* SETTABLE_EXPRESSION: prepay lockout test expr */
    char *ym_preplimit_toptkn[2] ;     /* prepay limit formula exprs */
#define ICMOPREPLIMIT_BALANCE   0      /* index for prepay limit balance formula */
#define ICMOPREPLIMIT_AMOUNT    1      /* index for prepay limit amount  formula */
    }  YIELDMAINT ;


/* PICLUSTER: detailed info about a cluster.  A cluster consists of a
linked list of pools, together with fields holding aggregated
information about the set of pools. */

typedef struct _PICLUSTER {
    char *picluster_mpip ;       /* linked list of pools in the cluster */
    char *picluster_user_accump; /* cluster_user_fcn accum results */

    /* The following are weighted average values without regard to
       the PO/IO/PCT strip for reporting purpose. They may be different
       from the similar fields in POOL_INFO structure, which are averaged
       with regard of PO/IO/PCT strip for cashflow purpose. */
    double picluster_netcoupon ;  /* Wavg net coupon % */
    double picluster_servfee ;    /* Wavg service fee % */

    /* The following is weighted average value for pi_remterm for
       reporting purpose in case of cluster_with_amort_sched clustering mode */
    int picluster_remterm ;    /* Wavg remterm  */

    /* The following are reserved for internal use */
INTEX_INTERNAL_USE_ONLY    char   *picluster_pclp ;         /* POOL_CLUSTER struct with intermediate clustering result */
INTEX_INTERNAL_USE_ONLY    int     picluster_amort_nsched ; /* pre-calculated amort schedule */
INTEX_INTERNAL_USE_ONLY    double *picluster_amort_vsched ; /* pre-calculated amort schedule */
INTEX_INTERNAL_USE_ONLY    int     picluster_is_pure_io ;   /* TRUE if all pools in the cluster are pure IO (for groups wavg only ) */
INTEX_INTERNAL_USE_ONLY    void ((CALLBK_FCN_PREFIX *picluster_user_free_fcn)(Args_cluster_user_free_fcn));
                                 /* user function to clean up structures allocated in accum function */
    }  PICLUSTER ;


/* PIWORK:  additional pmt-to-pmt current info    */

typedef struct _PIWORK {
    short  piwork_cur_per         ; /* current period info provided for*/
    short  piwork_to_int_reset    ; /* # of per till next int reset */
    short  piwork_to_pay_reset    ; /* # of per till next pay reset */
    short  piwork_balloon_term    ; /* per of balloon month (curper) */
    short  piwork_balloonext_nmos ; /* # pers to extend CMBS balloon */
    char   piwork_prp_type        ; /* prepay rate units type */
    char   piwork_def_type        ; /* default rate units type */
    char   piwork_severity_type   ; /* severity rate units type */
    double piwork_cur_bal         ; /* current balance$ */
    double piwork_prp_value       ;  /* current prep rate in prp_type */
    double piwork_def_value       ; /* default rate in piwork_def_type units */
    double piwork_gross_rate_face ; /* current gross coupon rate % */
    double piwork_serv_rate_face  ; /* current service fee % */
    double piwork_gross_rate      ; /* current gross rate/1200   */
    double piwork_cur_pi          ; /* current PI payment */
    double piwork_prp_rate        ; /* prepay rate fraction (SMM/100) */
    double piwork_def_rate        ; /* default rate fraction (MDR/100) */
    double piwork_loss_severity   ; /* severity rate fraction (%/100) */
    double piwork_surv_factor     ; /* statistical survival factor */
    }  PIWORK ;


/* POOL_INFO: details of a collateral loan, pool, or aggregate */

struct _POOL_INFO {
    char  *pi_next ;         /* Pointer to next pool in linked list */
    char  *pi_user ;         /* NULL, or application use.  We'll free */
    int    pi_agency ;       /* ICMOAGENCY_xx collateral data source */
    char   pi_category  ;    /* ICMOCOLLATCAT_xx collateral category */
    char   pi_pnum [ ICMO_MAX_PIPNUM_CHARS+1 ] ;  /* Pool number, or underlying deal name */
    char   pi_type [ ICMO_MAX_PITYPE_CHARS+1 ] ;  /* PC, AR, 17, etc., or underlying tranche name */
    char   pi_state[3] ;     /* pool's location, such as "MA" */
    char   pi_zipcode[6] ;   /* pool's location, such as "02194" */
    char   pi_balloon_sched; /* ICMO_BALLOONSCHED_xx: balloon pmt scheduled allocation flag */
    char   pi_balloon_io ;   /* TRUE interest-only pmts until balloon */
    char   pi_amort_type ;   /* LOAN_AMORT_xx: amortization rule */
    char   pi_coupon_is_wac; /* TRUE pool params in mtgholder perspectv */
    char   pi_gtpm_flag ;    /* ICMO_GTPM_xx:  if GPM, TPM, or neither */
    char   pi_explodable ;   /* POOLXPLODE_xx: Mega/Giant info */
    char   pi_std_delay ;    /* traditional # days till next payment */
    char   pi_ndays_reinv ;  /* #days pool's cf $ will collect int */
    char   pi_component_loan;/* TRUE loan coupon calc'ed from bonds */
    char   pi_daycount_method;         /* ICMO_DAYCOUNT_xx: gross rate cal basis */
    char   pi_businessday_method;      /* .. optional wkend/holiday */
    char   pi_serv_daycount_method;    /* ICMO_DAYCOUNT_xx: serv rate cal basis */
    char   pi_serv_businessday_method; /* .. optional wkend/holiday */
    int    pi_origterm ;     /* 360, 180, or contract mortgage term */
    int    pi_remterm ;      /* Wavg remaining months till maturity */
    int    pi_bvremterm ;    /* Max remaining months till maturity */
    int    pi_balloon ;      /* 0, or contract balloon months */
    int    pi_noamort_mos ;  /* # of months be4 start amortizing loan. AMORT NONE without FOR is represented by 0.
                                Negative values represent old-style global schedule numbers. */
    int    pi_gtpm_term ;    /* if GPM incr pmts, TPM init term mos. */
    int    pi_age_since_issue;/* Mos since pool origin, or calc'ed */
    int    pi_wala ;         /* Wavg loan age, max 30 when avg of pools */
    int    pi_wala_raw ;     /* Wavg loan age, unmodified */
    int    pi_cftype ;       /* ICMOCFTYPE_FIX_30YR, etc. */
    double pi_factors [ ICMO_MAX_FACTORS ]; /* [0] - curfactor, or curbal if origbal==0 */
    double pi_netcoupon ;    /* Wavg net coupon % */
    double pi_origbal ;      /* Pool's face value at pool origin.  For
                              * group_collat_wavg pools, this
                              * represents the sum of the original
                              * balances of all the loans in the pool
                              * that appear in the first CDU file. */
    double pi_servfee ;      /* Wavg service fee % */
    double pi_bvservfee ;    /* Max assumed service fee % */
    double pi_pctprincipal ; /* 100., or strip in this % of principal */
    double pi_pctinterest ;  /* 100., or strip in this % of interest */
    double pi_fractopdeal ;  /* fraction of cashflows given to top deal */
INTEX_INTERNAL_USE_ONLY    double pi_curbal ;       /* Internally-used orig/current balance$ */
INTEX_INTERNAL_USE_ONLY    double pi_curpmt ;       /* Internally-used current P+I $ */
    double pi_bv_cap ;       /* pool's maximum bond value factor */
    double pi_bv_factor ;    /* pool's bond value factor scalar */
    double pi_init_bv_factor ; /* 0, or for some bv calculations */
    double pi_gtpm_init_coup;/* if GPM/TPM, initial coupon. if PREFUND and >0, prefund netrate */
#define PI_PREFUND_NETRATE_ZEROVAL   1e-12   /* zero netrate value for PREFUND with defined interest */
    double pi_gtpm_rise ;    /* If GPM/TPM, annual % rise of interest */
    double *pi_bv_factors ;  /* NULL, or pool's bv factor vector */
    double *pi_xrs_frac ;    /* vector of frac. of pool bal for XRS's */
    int    pi_groupno ;      /* Group# for pool-directed cashflows */
    PREPHIST pi_psa ;        /* pool's prepayment history, in PSA units*/
    PREPHIST pi_cpr ;        /* pool's prepayment history, in CPR units*/
    LOANATTR *pi_loanattrp ; /* NULL, or to addl detail attributes */
    LOANSTAT *pi_loanstatp ; /* NULL, or to delinquency/resolution info */
    YIELDMAINT *pi_ymp ;     /* NULL, or to prepayment lockout/fee info */
    ARM_INFO *pi_armp ;      /* NULL, or to Adj Rate Mortgage info */
    PIBOND_INFO *pi_pibondp; /* NULL, or to Treasury/Corporate info */
    PISERV_INFO *pi_servp;   /* NULL, or to unusual serv/mastserv info */
    float  pi_orig_ltv ;     /* pool's original loan-to-value ratio,in %*/
    float  pi_amort_ltv ;    /* pool's theoretical amortized LTV, in % */
    float  pi_ltv ;          /* if >0, pool's current LTV, in % */
    char  *pi_icmop ;        /* to deal that this collat item supports */
    char  *pi_down_icmop ;   /* to underlying deal if item is tranche */
    char  *pi_endpad ;       /* NULL, unless collat item is a tranche */
    PIWORK *pi_workp   ;     /* additional pmt-to-pmt current info    */
    PICLUSTER *pi_clusterp ; /* NonNull if pool is cluster_with_details */
INTEX_INTERNAL_USE_ONLY    char  *pi_internalp ;    /* internal use for Intex CMO routines ONLY */
}  /* POOL_INFO */ ;

#define PI_STARTBAL(pip)     /* pool's balance as of parsing */                                 \
   (((pip)->pi_origbal==0. && pip->pi_category!=ICMOCOLLATCAT_CASH) ? (pip)->pi_factors[0] : (pip)->pi_factors[0]*(pip)->pi_origbal)


/* LOAN_AMORT_xx: Type of loan/pool amortization  */

#define LOAN_AMORT_REGULAR  0  /* Regular level-pay amortization  */
#define LOAN_AMORT_RULE78   1  /* obsolete, never used */
#define LOAN_AMORT_NONE     2  /* No amortize loan [for #n months]*/
#define LOAN_AMORT_SCHED    3  /* Amortize loan given a schedule */
#define LOAN_AMORT_MINPMT   4  /* Minimum payment instead of amortize */
#define LOAN_AMORT_SCHED_CURPMT 5  /* Current payment schedule provided instead of amortized sched */
#define LOAN_AMORT_LEVEL_PRINC  6  /* Level principal payment */
#define LOAN_AMORT_FORMULA      7  /* Amortize loan given a formula */
#define LOAN_AMORT_CONTR_CF     8  /* Contributed CF */
#define LOAN_AMORT_FULLY_AM     9  /* fully amort at every period */
#define LOAN_AMORT_PCT_PER_ANNUM 10 /* Level principal payment based on % of origbal */
#define LOAN_AMORT_MIXED       11  /* Multiple stages with different amortization terms or types */
#define LOAN_AMORT_NONE_MAX    97  /* LOAN_AMORT_NONE until max_cf_vectsize */
#define LOAN_AMORT_DEFAULT     99  /* Balloon extend continue amort method/armi_amort_type inherit pi_amort_type  */

/* ICMO_BALLOONSCHED_xx: Which components of principal are called scheduled */

#define ICMO_BALLOONSCHED_AMORT         0  /* simple amortization */
#define ICMO_BALLOONSCHED_REMAIN        1  /* only the balloon amount */
#define ICMO_BALLOONSCHED_AMORT_REMAIN  2  /* simple amort + balloon amount */
#define ICMO_BALLOONSCHED_ZERO          3  /* sched payment is $0. */
#define ICMO_BALLOONSCHED_ALL           4  /* amort+balloon+prepayment */
#define ICMO_BALLOONSCHED_MATUR         5  /* not true balloon, represent forced maturity */

/* ICMO_GTPM_xx : special type of pool/loan.
                   must be the same as mbs.h */
#define ICMO_GTPM_NO       0      /* Pool is normal */
#define ICMO_GTPM_GPM      1      /* Pool is a GPM */
#define ICMO_GTPM_TPM      2      /* Pool is a TPM */
#define ICMO_GTPM_PREFUND  4      /* Pool is a pre-funded loan */
#define ICMO_GTPM_STGFUND  5      /* Deprecated. Same as ICMO_GTPM_PREFUND */
#define ICMO_GTPM_CPSHEDGE 6      /* For CPS/TRS only: hedge not swap */

#define POOLXPLODE_NORMAL         0  /* Not Fannie Mega / Freddie Giant */
#define POOLXPLODE_NOT_EXPLODED   1  /* Still a Mega/Giant pool */
#define POOLXPLODE_EXPLODED       2  /* Expanded from parent Mega/Giant */

#define pi_down_cfmax  pi_gtpm_init_coup
#define PAID_DOWN_CFMAX  -1e-10  /* Paid down flag value for re-remic tranche */


/* ICMO_AGG_UNION: runtime info about current collat period's aggunion status for AGGMDR and AGGSMM */

typedef struct {
    int    aggunion_id ;          /* Which aggunion_id this represents */
    double aggunion_start_bal ;   /* AGGMDR/AGGSMM scaling balance for this aggunion */
    double aggunion_cur_factor ;  /* Fraction of start_bal still outstanding. */
    } ICMO_AGG_UNION ;


/* ICMO_AGG_UNION_xx:  special icmo_set_aggunion_id() specification IDs */

#define ICMO_AGG_UNION_DEFAULT (-999)   /* Pool should use associated group's aggunion */
#define ICMO_AGG_UNION_REPORT  (-998)   /* Report pool's aggunion instead of setting it */

/* ICMO_AGG_UNION_FOR_xx:  value of aggunion_for parameter of icmo_set_aggunion_id() and index for grp_aggunion_id */
#define ICMO_AGG_UNION_FOR_AGGMDR    0   /* Set aggunion for ICMODEFAULT_VAGGMDR, ICMODEFAULT_VORIGAGGMDR or ICMODEFAULT_VFWDAGGMDR */
#define ICMO_AGG_UNION_FOR_AGGSMM    1   /* Set aggunion for ICMOSPDT_VORIGAGGSMM */
#define ICMO_AGG_UNION_FOR_AGGDELINQ 2   /* Set aggunion for ICMODELINQTYPE_AGG */
#define ICMO_N_AGG_UNION_FOR         3   /* total # of ICMO_AGG_UNION_FOR_xx */


/* DEAL_CLASS: info about defined senior/sub class tree */

typedef struct _DEAL_CLASS DEAL_CLASS ;
struct _DEAL_CLASS {
    double class_support_startpct;/* support pct as of latest cdu */
    double class_support_origpct; /* support pct as of deal issue */
DEPRECATED    double class_support_start_basis; /* basis for calc'd support pct as of latest cdu */
DEPRECATED    double class_support_orig_basis;  /* deal issue basis for calc'd support pct */
    double class_origbal ;        /* original bal$ of blocks in level */
    char   class_name[ICMO_MAX_TRNAM_CHARS+1] ; /* class name, eg "SENIOR" */
    char   class_attributes ;       /* bit flag for attributes of class */
#define ICMO_CLASS_ATTRIBUTE_DUMMY    0x01   /* class is a dummy allocation class */
#define ICMO_CLASS_ATTRIBUTE_PSEUDO   0x02   /* class is a pseudo class */
    int    class_classno ;           /* class# quick icmo_vclasses lookup */
    char  *class_up ;              /* to class above us.  NULL for top classes */
    int    class_nsubclasses ;       /* #branches directly under this node */
    char **class_vsubclasses ;    /* the nodes directly under this class*/
    DEAL_CLASS *class_next_junior ;     /* to next class subordinate to this one, if any */
    } ;

#define IS_GROUND_CLASS(classp) ( (classp)->class_vsubclasses == NULL )

#define IS_ALLOCATION_CLASS(classp)                                                                       \
 ( ( IS_GROUND_CLASS( (classp) ) ||                                                                       \
      (((DEAL_CLASS *)(*((classp)->class_vsubclasses)))->class_attributes) & ICMO_CLASS_ATTRIBUTE_DUMMY ) \
  && !((classp->class_attributes) & ICMO_CLASS_ATTRIBUTE_PSEUDO ))


/* ICMOXRS: description of one XRS portion of a group */

typedef struct {
    int    icmoxrs_groupno ;            /* group this XRS belongs to */
    int    icmoxrs_xrsno ;              /* which xrs in that group */
    double icmoxrs_pass_thru_rate ;     /* pass thru rate */
    }  ICMOXRS ;

#define ICMO_XRS_IO_FLAG  99999   /* fake xrsno to indicate XRS IO strip */


typedef struct ICMO_BDCOMB ICMO_BDCOMB ;

/* ICMO_BUSINESSDAY: Business days info - how to adjust actual payment day around wkend/holidays*/

typedef struct  {
    signed char  icmobd_method      ; /* ICMO_BUSINESSDAY_xx: to adjust pmtday */
    int          icmobd_count       ; /* for ABSOLUTE/OFFSET/COMBINATION */
    ICMO_BDCOMB  *icmobd_bdcomb_list; /* for ICMO_BUSINESSDAY_COMBINATION */
    } ICMO_BUSINESSDAY;


/* ICMO_BDCOMB:  for ICMO_BUSINESSDAY_COMBINATION, deatils of the components */

struct ICMO_BDCOMB {
    ICMO_BDCOMB      *icmobdcomb_next  ;  /* next in link list */
    ICMO_BUSINESSDAY *icmobdcomb_bdp   ;  /* businessday method, NULL means ICMO_BUSINESSDAY_NONE */
    int          icmobdcomb_apply_type ;  /* ICMO_BDCOMB_APPLY_xxx */
#define ICMO_BDCOMB_APPLY_SEQUENTIAL 0  /* always apply */
#define ICMO_BDCOMB_APPLY_LATER      1  /* apply if later */
#define ICMO_BDCOMB_APPLY_EARLIER    2  /* apply if earlier */
    } ;

/* BLOCK_CAPFLR: element of time-varying coupon caps and floors */

typedef struct _BLOCK_CAPFLR  {
    YyyyMmDd capflr_date ;     /* Effective date of cap/floor */
    char     capflr_cap_prev ; /* TRUE if cap = Prev month coupon   */
    char     capflr_floor_prev;/* TRUE if floor = Prev month coupon*/
    double   capflr_cap ;      /* If not ICMOBLK_NO_FLT_CAP, coupon shall not exceed this (%) .. */
    double   capflr_cap_prev_const ;  /* .. prev + this offset (%) */
    double   capflr_floor ;    /* Coupon shall not fall below this (%) */
    double   capflr_floor_prev_const; /* .. prev + this offset (%) */
    double   capflr_reset ;    /* 0, or max +- reset (%) */
    }  BLOCK_CAPFLR ;

#define ICMOBLK_NO_FLT_CAP      9999.    /* no limit to the block coupon */
#define ICMOBLK_NO_FLT_FLOOR   (-9999.)  /* no floor to the block coupon */

typedef struct BLOCK_INFO BLOCK_INFO; /* to allow forward references to BLOCK_INFO struct */

/* BLKSTAGE_xx: block's stage transition types - BLOCK_INFO characteristics which could be change by stage transition */

#define BLKSTAGE_DAYCOUNT_METHOD     1     /* daycount method */
#define BLKSTAGE_BUSINESSDAY_METHOD  2     /* business day method */
#define BLKSTAGE_FREQ                3     /* payment frequency */
#define BLKSTAGE_FLT_FORMULA         4     /* Floater formula if not ax+b  */
#define BLKSTAGE_FLT_INDEXTYPE       5     /* For ax+b floater formula - index (x) */
#define BLKSTAGE_FLT_SLOPE           6     /* For ax+b floater formula - coefficient (a) */
#define BLKSTAGE_FLT_CONST           7     /* For ax+b floater formula - margin(b) */
#define BLKSTAGE_FLT_CAP             8     /* Floater formula life cap */
#define BLKSTAGE_FLT_FLOOR           9     /* Floater formula life cap */
#define BLKSTAGE_FLT_INDEX_CEILING  10     /* For ax+b floater formula - index cap */
#define LAST_BLKSTAGE_TYPE  BLKSTAGE_FLT_INDEX_CEILING

/* BLKSTAGE_TRANSITION_INFO: description of one block's stage transition */

typedef struct {
    char    *bst_name ;         /* if nonNULL, stage transition name */
    YyyyMmDd bst_date ;         /* date stage transition occurs */
    char    *bst_when_expr   ;  /* if nonNULL, condition expression when stage transition occurs*/
    char     bst_triggered   ;  /* TRUE if when/date condition currently triggered */
    char     bst_apply_flags [LAST_BLKSTAGE_TYPE+1]; /* TRUE if stage transition apply to the BLKSTAGE_xx type */
    BLOCK_INFO  *bst_info_bip ; /* BLOCK_INFO structure filled only for fields labeled by bst_apply_flags */
    }  BLKSTAGE_TRANSITION_INFO ;


/* ICMOBI_SHORTFALL_PAYBACK_xx: shortfall payback flag */

#define ICMOBI_SHORTFALL_PAYBACK_NA      0 /* shortfall not applicable */
#define ICMOBI_SHORTFALL_PAYBACK_FALSE   1 /* shortfall can't be paid back */
#define ICMOBI_SHORTFALL_PAYBACK_TRUE    2 /* shortfall can be paid back */
#define ICMOBI_SHORTFALL_PAYBACK_NOACCUM 3 /* shortfall can be paid back, but only for current period shortfall */

/* BLOCK_INFO: details of a pay block making up a tranche */

struct BLOCK_INFO {
    char *bi_next ;          /* Pointer to next block info in list */
    int bi_blockno ;         /* Block# found in deal description (>=1) */
    int bi_groupno ;         /* 0, or directed cashflow group# */
    int bi_xrs_groupno ;     /* 0, or associated xrs cashflow pseudo group# */
    DEAL_CLASS *bi_classp ;  /* NULL, or to senior/sub class info */
    double bi_orig_bal ;     /* Origination block balance $ */
    double bi_start_factor ;      /* Simulation start block balance factor */
    double bi_prev_start_factor ; /* Factor previous to bi_start_factor    */
    double bi_accruedint_factor ; /* Block factor to calc accruedint */
    int bi_is_notional ;     /* BI_NOTIONAL_xxx */
#define BI_NOTIONAL_NO       0  /* normal block, use real balance */
#define BI_NOTIONAL_DEAL     1  /* notional bal is % of deal */
#define BI_NOTIONAL_TRANCHE  2  /* notional bal is % of tranche(s) */
#define BI_NOTIONAL_BLOCK    3  /* notional bal is % of block(s) */
#define BI_NOTIONAL_RULES    4  /* notional bal paid by rule(s) */
#define BI_NOTIONAL_FORMULA  5  /* notional bal calc'ed from expr */
#define BI_NOTIONAL_SCHEDULE 6  /* notional bal scaled with a schedule */
#define BI_NOTIONAL_GROUP    7  /* notional bal is % of coll grp(s)+ */
    int   bi_ntl_n_ref_items   ;  /* length of bi_ntl_v_ref_itemnos */
    int  *bi_ntl_v_ref_itemnos ;  /* vector of notional referenced items number */
    char *bi_ntl_formula_begin ;  /* formula for notional begin bal */
    char *bi_ntl_formula_end   ;  /* formula for notional end bal */
    double bi_ntl_frac ;  /* fraction of notional balance over referenced items balance */
    int bi_notional_with_schedule ;       /* Flag indicating if block is notional with schedule */
#define BI_NOTIONAL_WITH_SCHEDULE_NO    0 /* block not is notional with schedule */
#define BI_NOTIONAL_WITH_SCHEDULE_BEGIN 1 /* block is notional with schedule. Value in the schedule corresp. to the beginning block balance */
#define BI_NOTIONAL_WITH_SCHEDULE_END   2 /* block is notional with schedule. Value in the schedule corresp. to the ending    block balance */
    int bi_schedule_no ;     /* schedule number if block is notional with schedule, starts with 1 */
    int bi_accrues ;         /* True if possible Z accrual to block */
    int bi_princfreq ;       /* Frequency of block principal to tranche */
    int bi_intfreq ;         /* Frequency of block interest to tranche */
    int bi_intoffset ;       /* # mos 1st accrual pd is long (>0) or short (<0) */
    int bi_intresetfreq ;    /* Frequency of floater index reset (M=12,A=1) */
    int bi_first_intreset_period ; /* 1st coupon reset period */
    double bi_princfrac ;    /* Fraction of block principal to tranche */
    double bi_intfrac ;      /* Fraction of block interest to tranche */
    int bi_intdelay ;        /* #days from end of accrual period to pmt*/
#define bi_princdelay  bi_intdelay
    int  bi_in_blackout ;    /* TRUE if factor not known at settlement */
    int  bi_in_coupon_blackout ;    /* TRUE if old coupon rate used */
    int  bi_use_factor ;     /* ICDUFACTOR_xx: which CDU factor used */
    int  bi_daycount_method; /* ICMO_DAYCOUNT_xx: accrual period counting */
    ICMO_BUSINESSDAY bi_businessday_info ; /*  businessday adj info */
#define bi_businessday_method  bi_businessday_info.icmobd_method
#define bi_businessday_count   bi_businessday_info.icmobd_count
    char *bi_bd_center_name; /* name of business center for holidays observed */
    int  bi_use_coupon ;     /* ICDUCOUPON_xx: CDU or IDX coupon used */
    double bi_curcoupon ;    /* Current block coupon (annual %) */
    double bi_cdu_couponcap_rate ;  /* block couponcap_rate (annual %) if reported in CDU */
    int bi_entitled_to_nxtpmt;  /* TRUE, else 0 out next P,I,P+I */
    int bi_floater ;         /* True if Floater coupon */
       /* For ax+b floater formula: */
    int    bi_flt_indextype ;     /* Floater index (x) type ICMOI_xx */
    int    bi_flt_index_lag ;     /* additional #mon to look back for index value */
    char  *bi_flt_index_subname ; /* Floater index subname or NULL */
    double bi_flt_index_curval ;  /* Current index value from IDX file */
    double bi_flt_slope ;         /* Floater formula coefficient (a). If 0, flag for constant coupon, which may change with schedule or nextstage  */
    double bi_flt_const ;         /* Floater formula margin(b) value. Should not be used if bi_flt_const_schedule_no > 0 */
    double bi_flt_index_ceiling ; /* if > 0, ceiling on the value of the index (x). Should not be used if bi_flt_index_ceiling_schedule_no > 0 */
    int    bi_flt_const_schedule_no;          /* if > 0, floater formula margin(b) reference schedule number */
    int    bi_flt_index_ceiling_schedule_no ; /* if > 0, bi_flt_index_ceiling reference schedule number */
    char  *bi_flt_cap_expr ; /* expr if bi_flt_cap refers to a formula, if not NULL ignore bi_flt_cap */

    char  *bi_flt_string ;   /* Floater formula if not ax+b */
    double bi_flt_floor ;    /* Floater formula life floor */
    double bi_flt_cap ;      /* Floater formula life cap value. May be ICMOBLK_NO_FLT_CAP. Should not be used if bi_flt_cap_expr is not NULL */
    int bi_days_accrued ;    /* #days interest in current accrual period*/
    int bi_delaydays ;       /* #days till block's next cashflow */
    int bi_cap_exceeded ;    /* TRUE if cap exceeded during cashflows */
    int bi_flr_exceeded ;    /* TRUE if floor exceeded during cashflows */
    YyyyMmDd bi_dated ;      /* block's orig dated date */
    YyyyMmDd bi_firstdate ;  /* block's orig 1st payment date */
    YyyyMmDd bi_accrudate;   /* block's updated dated date */
    YyyyMmDd bi_nxtdate ;    /* block's updated next pay date */
    YyyyMmDd bi_idxdate ;    /* Latest used IDX date for block's coupon */
    YyyyMmDd bi_settledate ; /* Settlement date of bond if different than deal settle date */
    YyyyMmDd bi_creation_date; /* If > 0 date when block was added to the deal */
    int bi_ncapflrs ;        /* #elements in timedep cap/floor schedule */
    BLOCK_CAPFLR *bi_vcapflrs; /* if above >0, to cap/floor schedule */
    char *bi_couponcap_string ;           /* NonNULL string if coupon capped by formula */
    int bi_couponcap_daycount_method ;    /* ICMO_DAYCOUNT_xx: for couponcap formula */
    int bi_couponcap_businessday_method ; /* ICMO_BUSINESSDAY_xx: for couponcap formula */
    int bi_couponcap_shortfall_payback ;  /* ICMOBI_SHORTFALL_PAYBACK_xx */
DEPRECATED    int  bi_business_center; /* Deprecated: replaced by bi_bd_center_name */
    int bi_support_basis_groupno ;  /* groupno of group that provides credit support for this block, or CREDSUPP_BASIS_TYPE_xx if < 0*/
    int bi_support_basis_senior_groupno ;  /* groupno of senior group, if applicable */
    int bi_how_int_paid_in_payrules ; /* bit flag indicating how interest is paid via payrules, not by coupon calculation */
#define BI_PAYRULES_PAY_INT_NO                  0x00 /* block not paid interest in payment rules */
#define BI_PAYRULES_PAY_INT_PREPAYPENALTY       0x01 /* specifically paid by 'pay: PREPAYPENALTY ... rule */
    int bi_n_icmoxrsp ; /* length of bi_v_icmoxrsp vector */
    ICMOXRS **bi_v_icmoxrsp; /* vector of associated XRS structure of the block if not NULL */
    int bi_n_blkstage_transitionp ; /* length of bi_v_blkstage_transitionp vector */
    BLKSTAGE_TRANSITION_INFO  **bi_v_blkstage_transitionp ; /* vector of block's stage transitions info if not NULL */
    } ;  /*  BLOCK_INFO  */


/* RATING_WATCH_INFO: info regarding a rating watch */

typedef struct _RATING_WATCH_INFO {
    char    *rw_next    ;   /* Pointer to next in list */
    int      rw_agency  ;   /* index into icmo_vrating_agency_xx[] for rating agency */
    int      rw_action  ;   /* RW_ACTION_xx */
    YyyyMmDd rw_date    ;   /* date the action taken */
    }  RATING_WATCH_INFO ;

/* RW_ACTION_xx: action for a rating watch */
#define RW_ACTION_UPGRADE     1  /* watch for possible upgrade */
#define RW_ACTION_DOWNGRADE   2  /* watch for possible downgrade */
#define RW_ACTION_UNCERTAIN   3  /* watch for possible up or downgrade */
#define RW_ACTION_REMOVE      4  /* watch removed */


/* TAX_TRUST: info about a tax TRUST */

typedef struct  {
    char   *trust_next ;  /* to next TRUST in link list */
    char   *trust_name ;  /* name of the TRUST, ie: LOW_TIER */
    int    trust_type ;   /* TAX_TRUST_xx */
#define TAX_TRUST_REMIC       0  /* REMIC trust */
#define TAX_TRUST_GRANTOR     1  /* GRANTOR trust */
    int    trust_n_collat_trs ; /* # of collat trs for this trust */
    int   *trust_collat_trnos ; /* vector of collat trnos */
    int    trust_n_bond_trs   ; /* # of bond trs for this trust */
    int   *trust_bond_trnos   ; /* vector of bond trnos */
    int    trust_residual_trno; /* residual trno */
    } TAX_TRUST ;


/* TAX_TRANCHE: tax related tranche info structure */

typedef struct  {
    int    ttr_trno ;         /* corresponding trno in icmo_tranche_xx */
    double ttr_issue_price ;  /* aggregate price including accrued int */
    double ttr_issue_price100;/* price per 100 not including accrued int*/
    double ttr_issue_yield ;  /* bond equivelent yield at pricing speed */
    int    ttr_taxcf_calc_type ; /* TAXCF_CALC_xx */
#define TAXCF_CALC_UNKNOWN  0    /* TAXCF type unknown */
#define TAXCF_CALC_QSI_OID  1    /* calc QSI and OID */
#define TAXCF_CALC_ALL_OID  2    /* no QSI, all OID */
#define TAXCF_CALC_DEMOID   3    /* De Minimis OID, no need to calc */
#define TAXCF_CALC_PREMIUM  4    /* Premium, need to amort deduction */
#define TAXCF_CALC_EXCLUDE_FROM_REMIC 5  /* Flag to indicate this bond should be excluded from contributing to remic.  Usually used to flag certain kind of fee (GNM trustee, for example) */
    TAX_TRUST *ttr_residual_of;  /* if not NULL, this tr is residual of trust */
    } TAX_TRANCHE ;


/* ICMO_DEALTREE_PARTITION: structure used for ICMOADDLINFO_CREATE_DEALTREE_PARTITIONS */

typedef struct {
    char *icmodtp_next ;        /* next in link list */
    int icmodtp_n_pips ;        /* length of icmodtp_v_pips */
    POOL_INFO **icmodtp_v_pips; /* vector of child pips belonging to this partition */
    } ICMO_DEALTREE_PARTITION ;


/* ICMO_XINFO: additional information of the deal */

typedef struct _ICMO_XINFO {
    YyyyMmDd xi_deal_effective_date;  /* deal effective date */
    YyyyMmDd xi_deal_terminate_date;  /* deal terminate date */
    YyyyMmDd xi_reinv_end_date;       /* last date when reinvestment using BUY_COLLAT allowed */
    YyyyMmDd xi_collat_cutoff_date;   /* collat cutoff date */
    int   xi_collat_determ_dd       ; /* collat determination day */
    char *xi_deal_trustee           ; /* Deal trustee */
    char *xi_deal_trustee_indenture ; /* Deal trustee - indenture */
    char *xi_deal_trustee_owner     ; /* Deal trustee - owner */
    char *xi_deal_servicer          ; /* Deal servicer (master) */
    char *xi_deal_servicer_sub      ; /* Deal servicer (sub) */
    char *xi_deal_servicer_special  ; /* Deal servicer (special) */
    char *xi_deal_collateral_manager; /* collateral manager */
    char *xi_deal_collateral_advisor; /* collateral advisor */
    int   xi_deal_with_contr_cf     ; /* TRUE if deal uses contributed CF */
    char  xi_deal_use_pnote_main_as_collat; /* ICMO_DEAL_USE_PNOTE_MAIN_AS_COLLAT_xxx */
#define ICMO_DEAL_USE_PNOTE_MAIN_AS_COLLAT_NA   0  /* deal not allowed to use pnote as main */
#define ICMO_DEAL_USE_PNOTE_MAIN_AS_COLLAT_YES  1  /* deal is using pnote as main feature */
#define ICMO_DEAL_USE_PNOTE_MAIN_AS_COLLAT_NO   2  /* deal is not using pnote as main feature */
    ICMO_DEALTREE_PARTITION *xi_dealtree_partitionp; /* supports this topdeal partition. always NULL for topdeal icmop */
    long  xi_cdi_ctrlno ;         /* CDI version ctrlno */
    long  xi_latest_cdu_ctrlno ;  /* latest CDU version ctrlno */
    } ICMO_XINFO ;


/* ICMO_FOREX_DATA:  Currency exchange information */

typedef struct _ICMO_FOREX_DATA {
    int            forexdata_forexno ;    /* 0 to (icmo_n_forex - 1) */
    ICMO_CURRENCY *forexdata_curr_from ;  /* The exchange is made from this currency... */
    ICMO_CURRENCY *forexdata_curr_to ;    /*    ...to this currency */
    } ICMO_FOREX_DATA ;


/* ABS_SUMMARY_INFO:  Information reported in or derived from Trustee reports */

typedef struct _ABS_SUMMARY_INFO {
    char *absi_next ;           /* Pointer to next item in list */
    char *absi_name ;           /* keyword string equivalent to .. */
    char *absi_sameas_dealname; /* NULL, or internal equiv calc flag */
    int absi_type ;             /* ICMOABSI_xx: ABS field code */
#define ICMOABSI_1mo_GROSS_PORT_YLD       0 /* collat WAC % */
#define ICMOABSI_1mo_INVESTOR_DEFAULT     1 /* collat liquidations% */
#define ICMOABSI_1mo_NET_PORT_YLD         2 /* collat WAC aft losses % */
#define ICMOABSI_1mo_NET_LOSS_RATE        3 /* collat realizedloss% */
#define ICMOABSI_1mo_ACCUM_NET_LOSS       4 /* sum collat realizedloss$ */
#define ICMOABSI_1mo_COUPON               5 /* bond(s) coupon % */
#define ICMOABSI_1mo_BALANCE              6 /* bond(s) cur balance $ */
#define ICMOABSI_1mo_SERV_FEE             7 /* collat service fee % */
#define ICMOABSI_1mo_LOC_FEE              8 /* financial guaranty fee % */
#define ICMOABSI_1mo_CUSHION              9 /* add'l space % */
#define ICMOABSI_1mo_BASE_RATE           10 /* tot fin obligations % */
#define   ICMOABSIFOOT_BASE_RATE_WAVG_COUPON       0 /* default */
#define   ICMOABSIFOOT_BASE_RATE_3mo_WAVG_COUPON   1 /* calc footnotes */
#define   ICMOABSIFOOT_BASE_RATE_STUB_WAVG_COUPON  2
#define   ICMOABSIFOOT_BASE_RATE_HFC_WAVG_COUPON   3
#define   ICMOABSIFOOT_BASE_RATE_A_COUPON          4
#define   ICMOABSIFOOT_BASE_RATE_B_COUPON          5
#define   ICMOABSIFOOT_BASE_RATE_TRUST_WAVG_COUPON 6
#define ICMOABSI_1mo_SPRD_TO_BASE_RATE   11 /* excess over fin oblig % */
#define ICMOABSI_1mo_PRINC_RCVABLES      12 /* $receivables */
#define ICMOABSI_1mo_INV_PRINCIPAL_AMT   13 /* deal internal amt$ */
#define ICMOABSI_1mo_SELLER_INTEREST     14 /* % of trust unsecuritized */
#define ICMOABSI_1mo_PRINC_PAY_RATE      15 /* % of princ rcv paid off */
#define ICMOABSI_1mo_TOTAL_PMT_RATE      16 /* % of rcv+chrgs paid off */
#define ICMOABSI_1mo_AVAIL_ENHANCEMENT   17 /* % of class supported */
#define   ICMOABSIFOOT_AVAIL_ENHANCE_BY_SUBORDS 0 /* subords take hit */
#define   ICMOABSIFOOT_AVAIL_ENHANCE_BY_CREDIT  1 /* first loss class */
#define ICMOABSI_1mo_REPO_INVENTORY_RATE 18
#define ICMOABSI_1mo_FORECLOSURE_RATE    19
#define ICMOABSI_1mo_DELINQ_30_59        20 /* 1mo delinquent, rate */
#define ICMOABSI_1mo_DELINQ_60_89        21 /* 2mo delinquent, rate */
#define ICMOABSI_1mo_DELINQ_90_119       22 /* 3mo delinquent, rate */
#define ICMOABSI_1mo_DELINQ_120_149      23 /* 4mo delinquent, rate */
#define ICMOABSI_1mo_DELINQ_150_179      24 /* 5mo delinquent, rate */
#define ICMOABSI_1mo_DELINQ_30_plus      25 /* 1+mo delinquent, rate */
#define ICMOABSI_1mo_DELINQ_60_plus      26 /* 2+mo delinquent, rate */
#define ICMOABSI_1mo_DELINQ_90_plus      27 /* 3+mo delinquent, rate */
#define ICMOABSI_1mo_DELINQ_180_plus     28 /* 6+mo delinquent, rate */
#define ICMOABSI_1mo_CREDIT_BALANCE      29 /* extern cred enhance lvl$ */
#define ICMOABSI_1mo_CREDIT_REINVEST     30 /* $ earned on cred balance */
#define ICMOABSI_1mo_CREDIT_PAYACCUM     31 /* tot $ paid out so far */
#define ICMOABSI_1mo_DRAW_RATE           32 /* annual CreditLine draw% */
#define ICMOABSI_1mo_CDR                 33 /* annual default rate % */
    #define   ICMOABSIFOOT_CDR_LIQUIDATIONS      0 /* 1mo_PRIN_LIQ used */
    #define   ICMOABSIFOOT_CDR_NEW_DEFAULTS      1 /* 1mo_PRIN_DEFAULT_NEW used */
    #define   ICMOABSIFOOT_CDR_DIRECT            2 /* Provided directly by data source */
#define ICMOABSI_1mo_CPR                 34 /* annual prepay rate % */
    #define   ICMOABSIFOOT_CPR_COLLATERAL        0 /* Collateral Prepayment history used */
    #define   ICMOABSIFOOT_CPR_DIRECT            1 /* Provided directly by data source */
    #define   ICMOABSIFOOT_CPR_PRIN_USCHED       2 /* Calculated from Unscheduled Principal Reported */
    #define   ICMOABSIFOOT_CPR_PRIN_COLLECTIONS  3 /* Calculated from Principal Collections */
#define ICMOABSI_1mo_CRR                 35 /* annual repay rate % */
#define ICMOABSI_1mo_MHP                 36 /* annual % of MHP model */
#define ICMOABSI_1mo_WAC                 37 /* gross collat coupon */
#define ICMOABSI_1mo_WAM                 38 /* collat remaining term mos*/
#define ICMOABSI_1mo_WALA                39 /* collat age, mos */
#define ICMOABSI_1mo_COLLAT_BAL          40 /* current collat bal$ */
#define ICMOABSI_1mo_TURNOVER            41 /* for AMEX deals */
#define ICMOABSI_1mo_YLD_FACTOR          42 /* for AMEX deals */
#define ICMOABSI_1mo_COLLAT_MARGIN       43
#define ICMOABSI_1mo_COLLAT_MONTORESET   44
#define ICMOABSI_1mo_COLLAT_MONTOPMTRESET 45
#define ICMOABSI_1mo_COLLAT_RESETCAP     46
#define ICMOABSI_1mo_COLLAT_LIFECAP      47
#define ICMOABSI_1mo_COLLAT_LIFEFLR      48
#define ICMOABSI_1mo_PRINCIPAL           49
#define ICMOABSI_1mo_NEXT_WAC            50 /* internal, for projecting */
#define ICMOABSI_3mo_GROSS_PORT_YLD      51
#define ICMOABSI_3mo_INVESTOR_DEFAULT    52
#define ICMOABSI_3mo_NET_PORT_YLD        53
#define ICMOABSI_3mo_COUPON              54
#define ICMOABSI_3mo_SERV_FEE            55
#define ICMOABSI_3mo_LOC_FEE             56
#define ICMOABSI_3mo_CUSHION             57
#define ICMOABSI_3mo_BASE_RATE           58
#define ICMOABSI_3mo_SPRD_TO_BASE_RATE   59
#define ICMOABSI_3mo_DRAW_RATE           60
#define ICMOABSI_3mo_CDR                 61
#define ICMOABSI_3mo_CPR                 62
#define ICMOABSI_3mo_CRR                 63
#define ICMOABSI_3mo_MHP                 64
#define ICMOABSI_3mo_WAC                 65
#define ICMOABSI_3mo_WAM                 66
#define ICMOABSI_6mo_CPR                 67
#define ICMOABSI_9mo_CPR                 68
#define ICMOABSI_12mo_CPR                69
#define ICMOABSI_Life_CPR                70
#define ICMOABSI_SYMVAR                  71
#define ICMOABSI_PRINCPHASE              72
#define   ICMOABSI_PRINCPHASE_REVOLVE       0
#define   ICMOABSI_PRINCPHASE_ACCUM         1
#define   ICMOABSI_PRINCPHASE_AMORT         2
#define ICMOABSI_1mo_REQ_SELLER_INTEREST 73 /* required seller interest */
#define ICMOABSI_1mo_REO_RATE            74
#define ICMOABSI_1mo_BANKRUPT_RATE       75
#define ICMOABSI_DELINQ_INC_FC           76
#define ICMOABSI_DELINQ_INC_REO          77
#define ICMOABSI_DELINQ_INC_BANKRUPT     78
#define ICMOABSI_1mo_AWAM                79
#define ICMOABSI_1mo_BWAM                80
#define ICMOABSI_1mo_OCTARGET            81
#define ICMOABSI_1mo_INTEREST            82
#define ICMOABSI_1mo_COLLAT_BEGIN_BAL    83
#define ICMOABSI_FC_NOT_DELINQ           84
#define ICMOABSI_REO_NOT_DELINQ          85
#define ICMOABSI_BANKR_NOT_DELINQ        86
#define ICMOABSI_1mo_PRIN_LIQ            87
#define ICMOABSI_1mo_PRIN_PREPAY         88
#define ICMOABSI_1mo_PRIN_RECOVERY       89
#define ICMOABSI_1mo_PRIN_REPURCH        90
#define ICMOABSI_1mo_PRIN_SCHED          91
#define ICMOABSI_1mo_DELINQ_120_plus     92
#define ICMOABSI_1mo_DELINQ_150_plus     93
#define ICMOABSI_DELINQ_INC_REPO_INV     94
#define ICMOABSI_1mo_INT_SHORTFALL       95
#define ICMOABSI_1mo_PRIN_SHORTFALL      96
#define ICMOABSI_1mo_PRIN_REPO           97
#define ICMOABSI_1mo_INT_COLLECTED       98
#define ICMOABSI_1mo_ADDL_INTEREST       99
#define ICMOABSI_1mo_SERV_ADVANCE       100
#define ICMOABSI_1mo_BOND_LOSS          101
#define ICMOABSI_1mo_NET_WAC            102
#define ICMOABSI_NUMBER_OF_LOANS        103
#define ICMOABSI_1mo_EXCESS_SPREAD      104
#define ICMOABSI_ACCUM_WRITEDOWN        105
#define ICMOABSI_NUMBER_OF_ACCOUNTS     106
#define ICMOABSI_AVG_DAILY_BALANCE      107
#define ICMOABSI_INV_CHRG_COLLECTIONS   108
#define ICMOABSI_INV_PRIN_COLLECTIONS   109
#define ICMOABSI_SERVFEE_INC_TRUSTEE    110
#define ICMOABSI_SERVFEE_INC_MASTER     111
#define ICMOABSI_MASTER_SERV_FEE        112
#define ICMOABSI_TRUSTEE_FEE            113
#define ICMOABSI_1mo_REO_30_59          114 /* 1 month reo rate */
#define ICMOABSI_1mo_REO_60_89          115 /* 2 month reo rate */
#define ICMOABSI_1mo_REO_90_plus        116 /* 3 + month reo rate */
#define ICMOABSI_1mo_FORECLOSURE_30_59  117 /* 1 month fc rate */
#define ICMOABSI_1mo_FORECLOSURE_60_89  118 /* 2 month fc rate */
#define ICMOABSI_1mo_FORECLOSURE_90_plus 119 /* 3 + month fc rate */
#define ICMOABSI_1mo_BANKRUPT_30_59     120 /* 1 month fc rate */
#define ICMOABSI_1mo_BANKRUPT_60_89     121 /* 2 month fc rate */
#define ICMOABSI_1mo_BANKRUPT_90_plus   122 /* 3 + month fc rate */
#define ICMOABSI_1mo_REPO_30_59         123 /* 1 month repo rate */
#define ICMOABSI_1mo_REPO_60_89         124 /* 2 month repo rate */
#define ICMOABSI_1mo_REPO_90_plus       125 /* 3 + month repo rate */
#define ICMOABSI_1mo_TOTAL_RCVABLES     126 /* $receivables */
#define ICMOABSI_1mo_DELINQ_90_179      127 /* 3-6mo delinquent, rate */
#define ICMOABSI_1mo_TRIG_TESTVAL       128 /* testval for triggers */
#define ICMOABSI_1mo_TRIG_TARGETVAL     129 /* targetval for triggers */
#define ICMOABSI_1mo_TRIG_TRIGVAL       130 /* trigval for triggers */
#define ICMOABSI_1mo_DEALSTATS_INFO     131 /* CDO/STL remit info */
#define ICMOABSI_1mo_ACCOUNT_INT        132 /* Int collection account */
#define ICMOABSI_1mo_ACCOUNT_PRN        133 /* Prn collection account */
#define ICMOABSI_1mo_COLLAT_DATE        134 /* collat update date */
#define ICMOABSI_1mo_INT_LOSS                   135 /* Current month interest loss on collat */
#define ICMOABSI_1mo_PRIN_UNSCHED               136 /* Total unsched collections (voluntary and involuntary) */
#define ICMOABSI_1mo_NUM_DELINQ_30_59           137 /* Number of loans 30-59 days delinq */
#define ICMOABSI_1mo_NUM_DELINQ_30_plus         138 /* Number of loans 30 plus days delinq */
#define ICMOABSI_1mo_NUM_DELINQ_60_89           139 /* Number of loans 60-89 days delinq */
#define ICMOABSI_1mo_NUM_DELINQ_60_plus         140 /* Number of loans 60 plus days delinq */
#define ICMOABSI_1mo_NUM_DELINQ_90_119          141 /* Number of loans 90-119 days delinq */
#define ICMOABSI_1mo_NUM_DELINQ_90_plus         142 /* Number of loans 90 plus days delinq */
#define ICMOABSI_1mo_NUM_DELINQ_120_149         143 /* Number of loans 120-149 days delinq */
#define ICMOABSI_1mo_NUM_DELINQ_120_plus        144 /* Number of loans 120 plus days delinq */
#define ICMOABSI_1mo_NUM_DELINQ_150_179         145 /* Number of loans 150-179 days delinq */
#define ICMOABSI_1mo_NUM_DELINQ_150_plus        146 /* Number of loans 150 plus days delinq */
#define ICMOABSI_1mo_NUM_DELINQ_90_179          147 /* Number of loans 90-170 days delinq */
#define ICMOABSI_1mo_NUM_DELINQ_180_plus        148 /* Number of loans 180 plus days delinq */
#define ICMOABSI_1mo_NUM_FORECLOSURE_30_59      149 /* Number of loans 30-59 FC */
#define ICMOABSI_1mo_NUM_FORECLOSURE_60_89      150 /* Number of loans 60-89 FC */
#define ICMOABSI_1mo_NUM_FORECLOSURE_90_plus    151 /* Number of loans 90 plus FC */
#define ICMOABSI_1mo_NUM_FORECLOSURE            152 /* Number of loans total FC */
#define ICMOABSI_1mo_NUM_REO_30_59              153 /* Number of loans REO 30-59 days */
#define ICMOABSI_1mo_NUM_REO_60_89              154 /* Number of loans REO 60-89 days */
#define ICMOABSI_1mo_NUM_REO_90_plus            155 /* Number of loans REO 90 plus days */
#define ICMOABSI_1mo_NUM_REO                    156 /* Number of loans total REO */
#define ICMOABSI_1mo_NUM_BANKRUPT_30_59         157 /* Number of loans Bankrupt 30-59 days */
#define ICMOABSI_1mo_NUM_BANKRUPT_60_89         158 /* Number of loans Bankrupt 60-89 days */
#define ICMOABSI_1mo_NUM_BANKRUPT_90_plus       159 /* Number of loans Bankrupt 90 plus days */
#define ICMOABSI_1mo_NUM_BANKRUPT               160 /* Number of loans total bankruptcy */
#define ICMOABSI_1mo_NUM_REPO                   161 /* Monthly Repossessions # */
#define ICMOABSI_1mo_NUM_REPO_INVENTORY         162 /* Repossession Inventory # */
#define ICMOABSI_NUM_FC_NOT_DELINQ              163 /* Number of loans that are in Foreclosure but not delinq */
#define ICMOABSI_NUM_BANKR_NOT_DELINQ           164 /* Number of loans that are in Bankrupt but not delinq */
#define ICMOABSI_NUM_REO_NOT_DELINQ             165 /* Number of loans that are in REO but not delinq */
#define ICMOABSI_1mo_IND_TRUSTEE_FEE            166 /* Indenture Trustee Fee */
#define ICMOABSI_1mo_OWNER_TRUSTEE_FEE          167 /* Owner Trustee Fee */
#define ICMOABSI_1mo_CLAIMS_PAID                168 /* Current amount of claims paid */
#define ICMOABSI_NEXT_COUPON                    169 /* Next Coupon */
#define ICMOABSI_1mo_INT_SHORTFALL_CURR         170 /* Current Interest Shortfall */
#define ICMOABSI_PREFUND_ACCT                   171 /* Prefunding Account Balance */
#define ICMOABSI_1mo_NUM_PREPAID                172 /* Current number of loans prepaid in full */
#define ICMOABSI_1mo_NUM_LIQ                    173 /* Current number of loans liquidated */
#define ICMOABSI_1mo_NUM_REPURCH                174 /* Current number of loans repurchased */
#define ICMOABSI_1mo_OTHER_FEES                 175 /* Other fees associated with collateral group */
#define ICMOABSI_1mo_INT_LOSS_CUMULATIVE        176
#define ICMOABSI_1mo_CLAIMS_PAID_CUMULATIVE     177
#define ICMOABSI_1mo_BOOK_VALUE_REO             178
#define ICMOABSI_COLLAT_OVER                    179 /* Internal use only */
#define ICMOABSI_INV_RECOV_COLLECTIONS          180
#define ICMOABSI_1mo_SERV_ADV_INT               181
#define ICMOABSI_1mo_SERV_ADV_PRIN              182
#define ICMOABSI_1mo_EXPENSE_UNPAID             183
#define ICMOABSI_1mo_EXPENSE_REP_PAID           184
#define ICMOABSI_1mo_TRUST_DEFAULT              185
#define ICMOABSI_1mo_SERV_FEE_AMT               186
#define ICMOABSI_1mo_INVESTOR_DEFAULT_AMT       187 /* collat liquidations$ */
#define ICMOABSI_1mo_CFSHORT                    188 /* collat cash shortfall$ */
#define ICMOABSI_1mo_TRUST_PRIN_COLLECTIONS     189
#define ICMOABSI_1mo_NUM_REPO_30_59             190 /* Number of loans REPO 30-59 days */
#define ICMOABSI_1mo_NUM_REPO_60_89             191 /* Number of loans REPO 60-89 days */
#define ICMOABSI_1mo_NUM_REPO_90_plus           192 /* Number of loans REPO 90 plus days */
#define ICMOABSI_1mo_PRN_COLLECTED              193
#define ICMOABSI_1mo_COLLAT_LOSS                194
#define ICMOABSI_1mo_ACCUM_NET_LOSS_RATE        195 /* sum collat realizedloss$ / orig collat bal$ in pct*/
#define ICMOABSI_1mo_UNAPPLIED_SERVICER_LOSSES  196
#define ICMOABSI_1mo_UNAPPLIED_SERVICER_LIQUIDATIONS  197
#define ICMOABSI_1mo_UNAPPLIED_ACCUM_SERVICER_LOSSES  198
#define ICMOABSI_INCLUDE_FC_NOT_DELINQ_IN_TOTAL       199
#define ICMOABSI_INCLUDE_REO_NOT_DELINQ_IN_TOTAL      200
#define ICMOABSI_INCLUDE_BANKR_NOT_DELINQ_IN_TOTAL    201
#define ICMOABSI_INV_RECOV_COLLECTION_RATE            202
#define ICMOABSI_DEFAULT_INC_RECOV                    203
#define ICMOABSI_1mo_NUM_ACCR_DAYS_IN_TRUST           204 /* Number of days in accrual period used to determine yield for specific trusts (AMCA, ) */
#define ICMOABSI_1mo_MDR                              205 /* monthly loss rate % */
#define ICMOABSI_1mo_PREPAY_PENALTY                   206 /* One month's prepayment penalty */
#define ICMOABSI_1mo_ARREARAGE_BAL                    207
#define ICMOABSI_3mo_NET_LOSS_RATE                    208
#define ICMOABSI_1mo_COUPCAP_SHORTFALL                209 /* Accumulated Coupon Cap Shortfall */
#define ICMOABSI_WAM_SOURCE_LL                        210
#define ICMOABSI_WALA_SOURCE_REMIT                    211
#define ICMOABSI_1mo_COUPCAP_SHORTFALL_CURR           212 /* Coupon Cap Shortfall for this current month */
#define ICMOABSI_NUMBER_OF_LOANS_ORIG                 213 /* Original Loan Count for Deal or Group */
#define ICMOABSI_END_ACCOUNT_ISP                      214
#define ICMOABSI_END_ACCOUNT_SAP                      215
#define ICMOABSI_1mo_NON_PERFORMING_BAL               216 /* current non performing balance */
#define ICMOABSI_CURR_EXCHANGE_RATE                   217 /* Currency exchange rate as provided in Remit */
#define ICMOABSI_1mo_INT_OPTIMAL                      218 /* 1 months optimal interest for bond */
#define ICMOABSI_1mo_PRIN_LIQ_ACCUM                   219
#define ICMOABSI_1mo_PRIN_DEFAULT                     220 /* Current default balance */
#define ICMOABSI_1mo_PRIN_DEFAULT_ACCUM               221 /* Accumulated default amount */
#define ICMOABSI_1mo_DELINQ_180_359                   222 /* The 6-12mo delinq rate */
#define ICMOABSI_1mo_DELINQ_360_plus                  223 /* The 12mo+ delinq rate */
#define ICMOABSI_1mo_NUM_DELINQ_180_359               224 /* The number of assets between 180 and 360 days delinq */
#define ICMOABSI_1mo_NUM_DELINQ_360_plus              225 /* The number of assets 360+ days delinq */
#define ICMOABSI_COLLAT_REPORT_FREQ                   226 /* The frequency at which collat data is reported to Intex */
#define ICMOABSI_1mo_RENT_RECEIVER_RATE               227
#define ICMOABSI_DELINQ_INC_RENT_RECEIVER             228
#define ICMOABSI_1mo_RENT_RECEIVER_30_59              229
#define ICMOABSI_1mo_RENT_RECEIVER_60_89              230
#define ICMOABSI_1mo_RENT_RECEIVER_90_PLUS            231
#define ICMOABSI_1mo_NUM_RENT_RECEIVER                232
#define ICMOABSI_1mo_NUM_RENT_RECEIVER_30_59          233
#define ICMOABSI_1mo_NUM_RENT_RECEIVER_60_89          234
#define ICMOABSI_1mo_NUM_RENT_RECEIVER_90_PLUS        235
#define ICMOABSI_1mo_SEVERITY_RATE                    236
#define ICMOABSI_3mo_SEVERITY_RATE                    237
#define ICMOABSI_1mo_LTV_0_69                         238 /* Percentage of collateral balance with LTV between 0 and 69 */
#define ICMOABSI_1mo_LTV_70_79                        239 /* Percentage of collateral balance with LTV between 70 and 79 */
#define ICMOABSI_1mo_LTV_80_89                        240 /* Percentage of collateral balance with LTV between 80 and 89 */
#define ICMOABSI_1mo_LTV_90_99                        241 /* Percentage of collateral balance with LTV between 90 and 99 */
#define ICMOABSI_1mo_LTV_70_plus                      242 /* Percentage of collateral balance with LTV over 70 */
#define ICMOABSI_1mo_LTV_80_plus                      243 /* Percentage of collateral balance with LTV over 80 */
#define ICMOABSI_1mo_LTV_90_plus                      244 /* Percentage of collateral balance with LTV over 90 */
#define ICMOABSI_1mo_LTV_100_plus                     245 /* Percentage of collateral balance with LTV over 100 */
#define ICMOABSI_SL_ACCRUED_INT                       246
#define ICMOABSI_6mo_CDR                              247
#define ICMOABSI_12mo_CDR                             248
#define ICMOABSI_Life_CDR                             249
#define ICMOABSI_6mo_SEVERITY_RATE                    250
#define ICMOABSI_12mo_SEVERITY_RATE                   251
#define ICMOABSI_Life_SEVERITY_RATE                   252
#define ICMOABSI_6mo_CRR                              253
#define ICMOABSI_12mo_CRR                             254
#define ICMOABSI_Life_CRR                             255
#define ICMOABSI_1mo_PRIN_LOSS                        256
#define ICMOABSI_1mo_LOANMOD_PRIN_LOSS                257
#define ICMOABSI_HEDGE_TERMINATION_DATE               258 /* Internal */
#define ICMOABSI_HLEG_SHORTFALL                       259 /* Internal */
#define ICMOABSI_HLEG_REP_PAID                        260 /* Internal */
#define ICMOABSI_DELINQ_INC_NONPERF                   261
#define ICMOABSI_INCLUDE_NONPERF_IN_TOTAL             262
#define ICMOABSI_1mo_NUM_DEFAULT                      263
#define ICMOABSI_1mo_CLAIMS_PENDING                   264
#define ICMOABSI_1mo_CLAIMS_REJECTED                  265
#define ICMOABSI_1mo_CRR_IN_FULL                      266 /* CRR on loans that have prepaid/liquidated over a 1 month period */
#define ICMOABSI_3mo_CRR_IN_FULL                      267 /* CRR on loans that have prepaid/liquidated over a 3 month period */
#define ICMOABSI_6mo_CRR_IN_FULL                      268 /* CRR on loans that have prepaid/liquidated over a 6 month period */
#define ICMOABSI_12mo_CRR_IN_FULL                     269 /* CRR on loans that have prepaid/liquidated over a 12 month period */
#define ICMOABSI_Life_CRR_IN_FULL                     270 /* CRR on loans that have prepaid/liquidated over Life */
#define ICMOABSI_1mo_CDR_IN_FULL                      271 /* CDR on loans that have prepaid/liquidated over a 1 month period */
#define ICMOABSI_3mo_CDR_IN_FULL                      272 /* CDR on loans that have prepaid/liquidated over a 3 month period */
#define ICMOABSI_6mo_CDR_IN_FULL                      273 /* CDR on loans that have prepaid/liquidated over a 6 month period */
#define ICMOABSI_12mo_CDR_IN_FULL                     274 /* CDR on loans that have prepaid/liquidated over a 12 month period */
#define ICMOABSI_Life_CDR_IN_FULL                     275 /* CDR on loans that have prepaid/liquidated over Life */
#define ICMOABSI_1mo_SEVERITY_RATE_IN_FULL            276 /* SEVERITY RATE on loans that have prepaid/liquidated over a 1 month period */
#define ICMOABSI_3mo_SEVERITY_RATE_IN_FULL            277 /* SEVERITY RATE on loans that have prepaid/liquidated over a 3 month period */
#define ICMOABSI_6mo_SEVERITY_RATE_IN_FULL            278 /* SEVERITY RATE on loans that have prepaid/liquidated over a 6 month period */
#define ICMOABSI_12mo_SEVERITY_RATE_IN_FULL           279 /* SEVERITY RATE on loans that have prepaid/liquidated over a 12 month period */
#define ICMOABSI_Life_SEVERITY_RATE_IN_FULL           280 /* SEVERITY RATE on loans that have prepaid/liquidated over Life */
#define ICMOABSI_1mo_WDBALINT_SHORTFALL               281 /*  */
#define ICMOABSI_1mo_WDBALINT_SHORTFALL_CURR          282 /*  */
#define ICMOABSI_INTERNAL_USE1                        283
#define ICMOABSI_INTERNAL_USE2                        284
#define ICMOABSI_INTERNAL_USE3                        285
#define ICMOABSI_INTERNAL_USE4                        286
#define ICMOABSI_INTERNAL_USE5                        287
#define ICMOABSI_INTERNAL_USE6                        288
#define ICMOABSI_1mo_CREDIT_PRIN_LOSS                 289 /* For Lease backed deals, this is the portion of monthly loss NOT associated with the sale of returned vehicles */
#define ICMOABSI_1mo_CREDIT_PRIN_LOSS_ACCUM           290 /* For Lease backed deals, this is the portion of monthly loss NOT associated with the sale of returned vehicles */
#define ICMOABSI_1mo_PRIN_RECOV_ACCUM                 291
#define ICMOABSI_1mo_CDR_REPAY                        292 /* 1mo CDR on loan in 'Repay' status (Student Loans) */
#define ICMOABSI_3mo_CDR_REPAY                        293 /* 3mo CDR on loan in 'Repay' status (Student Loans) */
#define ICMOABSI_6mo_CDR_REPAY                        294 /* 6mo CDR on loan in 'Repay' status (Student Loans) */
#define ICMOABSI_12mo_CDR_REPAY                       295 /* 12mo CDR on loan in 'Repay' status (Student Loans) */
#define ICMOABSI_Life_CDR_REPAY                       296 /* Life CDR on loan in 'Repay' status (Student Loans) */
#define ICMOABSI_1mo_CPR_REPAY                        297 /* 1mo CPR on loan in 'Repay' status (Student Loans) */
#define ICMOABSI_3mo_CPR_REPAY                        298 /* 3mo CPR on loan in 'Repay' status (Student Loans) */
#define ICMOABSI_6mo_CPR_REPAY                        299 /* 6mo CPR on loan in 'Repay' status (Student Loans) */
#define ICMOABSI_12mo_CPR_REPAY                       300 /* 12mo CPR on loan in 'Repay' status (Student Loans) */
#define ICMOABSI_Life_CPR_REPAY                       301 /* Life CPR on loan in 'Repay' status (Student Loans) */
#define ICMOABSI_1mo_PRIN_DEFAULT_NEW                 302 /* Newly included Default balances for current month */
#define ICMOABSI_NSINT_SHORTFALL_ACCUM_FULL           303 /* Non-supported Interest Shortfall from Full Prepays */
#define ICMOABSI_NSINT_SHORTFALL_ACCUM_PART           304 /* Non-supported Interest Shortfall from Partial Prepays */
#define ICMOABSI_NSINT_SHORTFALL_ACCUM_LOSS           305 /* Non-supported Interest Shortfall from Losses */
#define ICMOABSI_NSINT_SHORTFALL_ACCUM_SSRA           306 /* Non-supported Interest Shortfall from Soldiers and Sailors Relief Act */
#define ICMOABSI_1mo_DRAW_RATE_MAXCLAIM               307 /* Reverse Mortgage Draw Max Claim 1mo */
#define ICMOABSI_3mo_DRAW_RATE_MAXCLAIM               308 /* Reverse Mortgage Draw Max Claim 3mo */
#define ICMOABSI_6mo_DRAW_RATE_MAXCLAIM               309 /* Reverse Mortgage Draw Max Claim 6mo */
#define ICMOABSI_12mo_DRAW_RATE_MAXCLAIM              310 /* Reverse Mortgage Draw Max Claim 12mo */
#define ICMOABSI_Life_DRAW_RATE_MAXCLAIM              311 /* Reverse Mortgage Draw Max Claim Life */
#define ICMOABSI_1mo_DRAW_RATE_AVAILLOC               312 /* Reverse Mortgage Draw Avail LOC 1mo */
#define ICMOABSI_3mo_DRAW_RATE_AVAILLOC               313 /* Reverse Mortgage Draw Avail LOC 3mo */
#define ICMOABSI_6mo_DRAW_RATE_AVAILLOC               314 /* Reverse Mortgage Draw Avail LOC 6mo */
#define ICMOABSI_12mo_DRAW_RATE_AVAILLOC              315 /* Reverse Mortgage Draw Avail LOC 12mo */
#define ICMOABSI_Life_DRAW_RATE_AVAILLOC              316 /* Reverse Mortgage Draw Avail LOC Life */
#define ICMOABSI_ACCUM_DEFERCLAIM                     317 /* Internal */
#define ICMOABSI_ACCUM_DEFERCLAIM_INT                 318 /* Internal */
#define ICMOABSI_N_TYPES                              319 /* Max number of ABSI types */

    int absi_cdecl ;           /* ICMOABSICDECL_xx: int/double/etc */
#define ICMOABSICDECL_DBL                 0
#define ICMOABSICDECL_INT                 1
#define ICMOABSICDECL_VDBL                2    /* under development */
    int absi_trancheno ;        /* if >= 0, bond/group/ECE -specifier; if -1, deal-level info */
    int absi_tranchenotype ;    /* ICMOABSITRTYP_xx: trancheno is really*/
#define ICMOABSITRTYP_TRNO                0    /* tranche# */
#define ICMOABSITRTYP_GROUPNO             1    /* collat group# */
#define ICMOABSITRTYP_CREDITNO            2    /* RsvFund/FinG/LoC # */
#define ICMOABSITRTYP_CLASSNO             3    /* senior/sub treenode # */
#define ICMOABSITRTYP_SYMVARNO            4    /* expr symbol var # */
#define ICMOABSITRTYP_TRIGNO              5    /* trigger No. */
#define ICMOABSITRTYP_INDEXNO             6    /* index No. */
#define ICMOABSITRTYP_HLEGNO              7    /* hedge legno */
#define ICMOABSITRTYP_FOREX               8    /* forex rate */
#define ICMOABSITRTYP_EXPNO               9    /* expense No. */
#define ICMOABSITRTYP_HEDGENO            10    /* INTERNAL - hedge no */
#define ICMOABSITRTYP_CLAIMBUCKETNO      11    /* INTERNAL - Credit Claim Bucket No */
    char absi_data_in_cdi ;     /* TRUE=const val given, FALSE=calc */
    char absi_internal ;        /* TRUE=for calc purposes only */
    char absi_mkabs_rolled ;    /* TRUE=for portfolio string msg only */
    char absi_have_data ;       /* TRUE=data exists, FALSE=unfilled */
    int absi_footnote ;         /* add'l info for calculations */
#define ICMOABSIFOOT_ABSSUM_IDL  -2  /* absi defined by abssum.idl */

    union
        {
        int intval ;            /* .. data in integer form */
        double dblval ;         /* .. data in double form */
        double *vdblval ;       /* .. data is a vector of double */
        } absi_data ;
    YyyyMmDd absi_data_cdudate; /* CDU where absi_data is filled */
    char *absi_eval_toptkn ;    /* formula expr used in update */
    }  ABS_SUMMARY_INFO ;


/* ICMOTSET:  Control structure for icmo_apply_collat_transact_set () */

typedef struct {
    int  itset_future_trans_mode;  /* ITSET_FUTURE_xx processing mode for future transactions dates */
#define  ITSET_FUTURE_AS_ERROR     0   /* Future transactions not allowed */
#define  ITSET_FUTURE_AS_CURRENT   1   /* Apply future transactions to current collateral */
#define  ITSET_FUTURE_AS_FORECAST  2   /* Apply future transactions to forecasted cashflows.*/
    }  ICMOTSET ;


/* ICMOTRANS: One transaction info structure. Corresponding to one transaction line in CDX file. */

typedef struct {
    int   itrans_transact_set_num ;  /* transaction set ( CDX file ) number */
    int   itrans_type ;              /* ICMO_TRANSTYPE_xx transaction type */
    YyyyMmDd itrans_date ;           /* transaction date */
    POOL_INFO *itrans_pip ;          /* reference pip in collat list or saved pip in ICMO_TRANSTYPE_SELL mode */
    double   itrans_amount ;         /* transaction amount */
    double   itrans_price  ;         /* transaction price per 100 */
    double   itrans_princ_proceeds ; /* principal proceeds  ( positive if SELL ) */
    double   itrans_accrued_int_proceeds  ;   /* accrued interest proceeds ( positive if SELL ) */
    }  ICMOTRANS ;

/* ICMO_TRANSTYPE_xx: transaction type for ICMOTRANS */

#define  ICMO_TRANSTYPE_BUY       0  /* BUY - add to collat list */
#define  ICMO_TRANSTYPE_ADDL_BUY  1  /* BUY additional amount for existing loan */
#define  ICMO_TRANSTYPE_SELL      2  /* SELL - remove from collat list */
#define  ICMO_TRANSTYPE_PART_SELL 3  /* Partially SELL - reduce amount,modify in collat list */
#define  ICMO_TRANSTYPE_CHANGE    4  /* CHANGE - modify in collat list */


/* TRIGGER_VAL: TRIGGER related values */

typedef struct _TRIGGER_VAL {
    double trigv_origval ;      /* value asof deal closing */
    double trigv_startval ;     /* value asof latest update */
    double trigv_curval ;       /* value asof trig_curper */
    char  *trigv_expr;          /* expr to calculate */
    char  *trigv_origval_str ;  /* string of origval as appeared in CDI */
    } TRIGGER_VAL ;


/* TRIGMISCVAL: misc trigger info defined by deal model */

typedef struct _TRIGMISCVAL {
    void       *trigmisc_next ;  /* Pointer to next item in list */
    char       *trigmisc_name ;  /* short name used in the model */
    char       *trigmisc_fullname ; /* long descriptive name */
    int         trigmisc_miscno; /* Ordinal number for this miscval */
    TRIGGER_VAL trigmisc_val ;  /* value of this miscval */
    } TRIGMISCVAL ;


/* TRIGGER_INFO: link list of TRIGGERs in the deal */

typedef struct _TRIGGER_INFO {
    void *trig_next ;           /* Pointer to next item in list */
    char *trig_name ;           /* Name of the TRIGGER */
    char *trig_full_name ;      /* string providing the prospectus name for a TRIGGER */
    char *trig_definition;      /* string describing the function of the TRIGGER */
    char *trig_impact ;         /* string describing the impact of the TRIGGER */
    int   trig_trigno ;         /* Ordinal number for this TRIGGER */
    int   trig_groupno ;        /* collat group association */
    int   trig_type ;           /* ICMOTRIGTYPE_xx classification code of trigger */
    int   trig_type2 ;          /* more detailed classification, depending on trig_type.
                                   For ICMOTRIGTYPE_CDO_xx, this is corresponding CDOTEST type
                                   For ICMOTRIGTYPE_CASHFLOW  this is ICMOTRIGTYPE2_CF_xx
                                   For ICMOTRIGTYPE_CONDITION, this is ICMOTRIGTYPE2_CON_xx
                                   For ICMOTRIGTYPE_INFO, this is ICMOTRIGTYPE2_INFO_xx */
    int   trig_delay_month;     /* # of month delayed for trigger status */
    TRIGGER_VAL trig_testval ;  /* actual deal performance, eg. collat delinq */
    TRIGGER_VAL trig_targetval; /* threshold amount */
    TRIGGER_VAL trig_trigval ;  /* approximity to trigger event. < 0 means triggered, 1 means same as pricing */
    TRIGMISCVAL *trig_miscval_list;  /* list of misc vals defined by deal model */
    char *trig_effective_when_expr; /* this expr evals to trig_effective_flag */
    int   trig_effective_flag;      /* ICMOTRIGEFFECTIVE_xx: result of trig_effective_when_expr */
#define ICMOTRIGEFFECTIVE_ALWAYSFAIL  -2 /* trigger is currently stuck in fail status */
#define ICMOTRIGEFFECTIVE_ALWAYSPASS  -1 /* trigger is currently not effective, however all TRIGGER_VALs evaluated */
#define ICMOTRIGEFFECTIVE_NO           0 /* trigger is currently not effective, all TRIGGER_VALs not evaluated */
#define ICMOTRIGEFFECTIVE_YES          1 /* trigger is currently effective, normal status */
    int   trig_trigger_zero_trigval; /* TRUE if trigval <= 0 means triggered. (default: trigval < 0 means triggered) */
    int   trig_sticky_flag ;    /* ICMOTRIGSTICKY_xxx */
#define ICMOTRIGSTICKY_NONE            0 /* not sticky */
#define ICMOTRIGSTICKY_FAIL            1 /* trigger stuck in fail status once it fails */
INTEX_INTERNAL_USE_ONLY    double *trig_vtrigval;      /* vector of trig_trigval.trigv_curval for internal use when trig_delay_month > 0 */
    void **trig_v_subtrigp;     /* vect of sub-trigger pointers, end with NULL */
    int   trig_curper ;         /* forecasted CURPER */
    int   trig_n_override;      /* # of user provided forecasting values starting at [1] */
    int  *trig_v_override;      /* vector of user provided forecasting values ICMOTRIGOVERRIDE_xx, [1] for 1st forecast per */
#define ICMOTRIGOVERRIDE_NONE -1 /* no override */
#define ICMOTRIGOVERRIDE_PASS  0 /* override with PASS (not triggered) */
#define ICMOTRIGOVERRIDE_FAIL  1 /* override with FAIL (triggered) */
    char  trig_referenced_in_payrules ;  /* TRUE if result of trigger calc may impact cashflows */
    } TRIGGER_INFO ;

/* ICMOTRIGTYPE_xx: classification codes for triggers */
#define ICMOTRIGTYPE_UNKNOWN          0 /* unspecified trigger type */
#define ICMOTRIGTYPE_CASHFLOW         1 /* trigger impacts the waterfall of cash in the structure */
#define ICMOTRIGTYPE_CDO_COMPLIANCE   2 /* trigger determines if current collateral portfolio meets predefined compliance measures */
#define ICMOTRIGTYPE_CDO_ELIGIBILITY  3 /* trigger determines whether a new collateral item can be purchased into an existing portfolio*/
#define ICMOTRIGTYPE_CONDITION        4 /* trigger is expected to occur at some point (FAIL status is expected and does not indicate a negative condition)  */
#define ICMOTRIGTYPE_INFO             5 /* trigger provides current info status */

/* ICMOTRIGTYPE2_CF_xx: classification codes for CASHFLOW triggers */
#define ICMOTRIGTYPE2_CF_UNKNOWN        0 /* unspecified CASHFLOW trigger type */
#define ICMOTRIGTYPE2_CF_IC             1 /* Interest coverage test */
#define ICMOTRIGTYPE2_CF_OC             2 /* Over Collateralization test */
#define ICMOTRIGTYPE2_CF_AC             3 /* Additional Coverage test */
#define ICMOTRIGTYPE2_CF_DELINQ         4 /* Delinquency test */
#define ICMOTRIGTYPE2_CF_CUR_LOSS       5 /* Current Loss test */
#define ICMOTRIGTYPE2_CF_CUM_LOSS       6 /* Cumulative Loss test */
#define ICMOTRIGTYPE2_CF_FG_DRAW        7 /* FG Draw test */
#define ICMOTRIGTYPE2_CF_SPREAD         8 /* Excess Interest test */
#define ICMOTRIGTYPE2_CF_EOD            9 /* Event of Default */
#define ICMOTRIGTYPE2_CF_CUM_GROSS_DEF 10 /* gross cumulative default */
#define ICMOTRIGTYPE2_CF_CUM_NET_DEF   11 /* net cumulative default */
#define ICMOTRIGTYPE2_CF_PDL           12 /* Principal Deficiency Ledger */
#define ICMOTRIGTYPE2_CF_RF_TARGET     13 /* Reserve Fund target balance */
#define ICMOTRIGTYPE2_CF_AAA_CROSSOVER     14 /* AAA crossover     */
#define ICMOTRIGTYPE2_CF_ASSET_TRIGGER     15 /* asset trigger     */
#define ICMOTRIGTYPE2_CF_NON_ASSET_TRIGGER 16 /* non-asset trigger */
#define ICMOTRIGTYPE2_CF_SHIFTING_INTEREST 17 /* shifting interest */
#define ICMOTRIGTYPE2_CF_PARITY            18 /* Parity */
#define ICMOTRIGTYPE2_CF_EARLY_AMORT       19 /* Early amortization */
#define ICMOTRIGTYPE2_CF_REGULATED_AMORT   20 /* Regulated amortization  */
#define ICMOTRIGTYPE2_CF_SUBORD_AMORT      21 /* Subordinate amortization allowed  */
#define ICMOTRIGTYPE2_CF_RESERVE_AMORT     22 /* Reserve fund amortization */
#define ICMOTRIGTYPE2_CF_LF_AMORT          23 /* Liquidity facility amortization */
#define ICMOTRIGTYPE2_CF_INTEREST_DEFERRAL 24 /* Tranche interest Deferral */
#define ICMOTRIGTYPE2_CF_LF_DRAW           25 /* Liquidity facility draw   */
#define ICMOTRIGTYPE2_CF_CUR_DEF           26 /* Current default test      */
#define ICMOTRIGTYPE2_CF_PRORATA           27 /* Pro-rata payment of rating levels */
#define ICMOTRIGTYPE2_CF_COLLAT_BAL        28 /* Collateral balance below a certain amount */
#define ICMOTRIGTYPE2_CF_TRANCHE_BAL       29 /* Tranche balance below a certain amount    */

/* ICMOTRIGTYPE2_CON_xx: classification codes for CONDITION triggers */
#define ICMOTRIGTYPE2_CON_UNKNOWN    0       /*unspecified CONDITION trigger type  */
#define ICMOTRIGTYPE2_CON_DATE       1       /* Date Test */
#define ICMOTRIGTYPE2_CON_CRED_SUPP  2       /* Credit Support Test */
#define ICMOTRIGTYPE2_CON_APP_SEV_THRESHOLD  3  /* Applicable Severity Threshold (for Agency Credit deals ) */
#define ICMOTRIGTYPE2_CON_APP_SEV_MASTER     4  /* Applicable Severity Master (for Agency Credit deals ) */

/* ICMOTRIGTYPE2_INFO_xx: classification codes for INFO triggers */
#define ICMOTRIGTYPE2_INFO_UNKNOWN          0 /* unspecified INFO trigger type  */
#define ICMOTRIGTYPE2_INFO_RISK_RETENTION   1 /* Risk Retention Info */

#define CDOTEST_TRIGGER(trigp)                                  \
  ( (trigp)->trig_type == ICMOTRIGTYPE_CDO_COMPLIANCE ||        \
    (trigp)->trig_type == ICMOTRIGTYPE_CDO_ELIGIBILITY )


/* STANDARDVAR: holds info about standardized #vars */

typedef struct {
    char   *standardvar_expval_next;   /* ptr to next in the link list */
    char   *standardvar_expval_text;   /* description of expected override value */
    double  standardvar_expval_dblval; /* expected override value associated with above description */
    } STANDARDVAR_EXPVAL ;

struct _STANDARDVAR {
    char   *standardvar_next ;     /* ptr to next in the link list */
    char   *standardvar_name ;     /* name of the #var */
    char   *standardvar_full_name;   /* string providing full name of the #var */
    char   *standardvar_description; /* string describing the usage of the #var */
    char   *standardvar_typename;  /* name of standardized type */
    int    standardvar_type  ;     /* ICMOSTANDARDVAR_xx */
    int    standardvar_grpno ;     /* collat group association, if any */
    int    standardvar_classno ;   /* class association, if any */
    int    standardvar_assocno ;   /* Other association. Tranche association #, for ICMOSTANDARDVAR_TRANCHE_INFO */
    int    standardvar_symvarno;   /* index into icmo_symvars vector */
    int    standardvar_accept_override; /* ICMOSTDVAR_ACCEPT_OVERRIDE_xx, can this #var can be overridden by user in CF? */
#define ICMOSTDVAR_ACCEPT_OVERRIDE_NO               0 /* no override accepted */
#define ICMOSTDVAR_ACCEPT_OVERRIDE_YES              1 /* override accepted */
#define ICMOSTDVAR_ACCEPT_OVERRIDE_COLLAT_SPECIFIC  2 /* override accepted - asset specific overrides allowed for this #var, which effects collateral cashflows */
    int    standardvar_n_override; /* # of user provided forecasting values starting at [1] */
    double *standardvar_v_override;/* vector of user provided forecasting values, [1] for 1st forecast per */
    int    standardvar_attributes ;      /* bit flag for attributes of the standardized #var */
#define ICMO_STANDARDVAR_ATTRIBUTE_IS_CONSTANT 1  /* standardized #var is not changing over time */
    STANDARDVAR_EXPVAL *standardvar_expval_list; /* link list of expected override values */
    double standardvar_val ;       /* current value of the #var */
    } /* STANDARDVAR */ ;

/* ICMOSTANDARDVAR_xx */
#define ICMOSTANDARDVAR_OCT_VAL             0 /* OC target */
#define ICMOSTANDARDVAR_OCT_INITVAL         1 /* init val of OC target */
#define ICMOSTANDARDVAR_OCT_STEPDOWN_MONTH  2 /* earliest stepdown month */
#define ICMOSTANDARDVAR_OCT_STEPDOWN_FRAC   3 /* stepdown frac */
#define ICMOSTANDARDVAR_OCT_FLOOR           4 /* floor of OC target */
#define ICMOSTANDARDVAR_SEN_PCT             5 /* SENIOR class pct */
#define ICMOSTANDARDVAR_JUN_PCT             6 /* JUNIOR class pct */
#define ICMOSTANDARDVAR_SEN_PREP_PCT        7 /* SENIOR class prepay pct */
#define ICMOSTANDARDVAR_JUN_PREP_PCT        8 /* JUNIOR class prepay pct */
#define ICMOSTANDARDVAR_TRUST_PORT_YLD      9 /* TRUST gross yield */
#define ICMOSTANDARDVAR_PRINC_FUND_YLD     10 /* Principal funding account investment yield */
#define ICMOSTANDARDVAR_AMORT_TRIGGER      11 /* Rapid amortization trigger */
#define ICMOSTANDARDVAR_ARREARAGE_PAYRATE  12 /* Arrearage payback rate */
#define ICMOSTANDARDVAR_HYPERAM_NO_EXINT   13 /* Ignore hyperam excess int */
#define ICMOSTANDARDVAR_TRIG_DELINQ_LIMIT  14 /* Delinq trigger value */
#define ICMOSTANDARDVAR_TRIG_DELINQ_ACTUAL 15 /* Delinq trigger current value */
#define ICMOSTANDARDVAR_TRIG_LOSS_LIMIT    16 /* Loss trigger value */
#define ICMOSTANDARDVAR_TRIG_LOSS_ACTUAL   17 /* Loss trigger current value */
#define ICMOSTANDARDVAR_TRIG_EVENT         18 /* Trigger event happened or not. */
#define ICMOSTANDARDVAR_STL_ISP_LAG        19 /* Student Loan Input: Interest Subsidy Payment lag month */
#define ICMOSTANDARDVAR_STL_SAP_LAG        20 /* Student Loan Input: Special Allowance Payment lag month */
#define ICMOSTANDARDVAR_STL_SERVREJ_RATE   21 /* Student Loan Input: Servicer Reject Rate */
#define ICMOSTANDARDVAR_ORIG_COLL_BAL      22 /* Original collateral balance */
#define ICMOSTANDARDVAR_EXCESS_INTEREST    23 /* Excess interest - collateral over bonds */
#define ICMOSTANDARDVAR_TERMINATE_PRICE    24 /* Collat terminate price */
#define ICMOSTANDARDVAR_REINVEST_PRICE     25 /* CDO reinvestment price */
#define ICMOSTANDARDVAR_REINV_BOND_PRICE   26 /* CDO reinvestment price */
#define ICMOSTANDARDVAR_REINV_LOAN_PRICE   27 /* CDO reinvestment price */
#define ICMOSTANDARDVAR_REINVEST_PCT       28 /* CDO reinvestment PCT   */
#define ICMOSTANDARDVAR_REINV_BOND_PCT     29 /* CDO reinvestment PCT   */
#define ICMOSTANDARDVAR_REINV_LOAN_PCT     30 /* CDO reinvestment PCT   */
#define ICMOSTANDARDVAR_STL_PREP_OK_ALL    31 /* allow to prepay in all type of status */
#define ICMOSTANDARDVAR_ARR_FINAL_PAYRATE  32 /* Arrearage payback rate after normal loan balance paid off */
#define ICMOSTANDARDVAR_OC_ACTUAL_VAL      33 /* Actual overcollateralization amount */
#define ICMOSTANDARDVAR_CCFNO              34 /* contributed CF scenario number */
#define ICMOSTANDARDVAR_COLLAT_PARAM       35 /* collat CF parameter */
#define ICMOSTANDARDVAR_LOANVAL            36 /* loan-by-loan CF info */
#define ICMOSTANDARDVAR_REINVEST_END       37 /* CDO reinvestment end date  */
#define ICMOSTANDARDVAR_PDL                38 /* Specify class number a Principal Deficiency Ledger variable is associated with.  Not forecastable */
#define ICMOSTANDARDVAR_INFO               39 /* Standardized var with type specified in standardvar_typename*/
#define ICMOSTANDARDVAR_GROUP_INFO         40 /* Standardized var related to GROUP   with type specified in standardvar_typename*/
#define ICMOSTANDARDVAR_TRANCHE_INFO       41 /* Standardized var related to TRANCHE with type specified in standardvar_typename*/
#define ICMOSTANDARDVAR_CLASS_INFO         42 /* Standardized var related to CLASS   with type specified in standardvar_typename*/
#define ICMOSTANDARDVAR_RMTG_NEWBALTIMING  43 /* Reverse Mortgage Input: new balance timing */
#define ICMOSTANDARDVAR_STL_DEF_OK_ALL     44 /* allow to default in all type of status */
#define ICMOSTANDARDVAR_STL_PROGRAM_PPFRAC 45 /* Student Loan Input: benefit program participation frac */
#define ICMOSTANDARDVAR_HEDGE_TERMDATE     46 /* Hedge termination date forecast */
#define ICMOSTANDARDVAR_ORIG_CAPITALIZED_INT   47 /* Collateral accrued interest at deal origination */
#define ICMOSTANDARDVAR_CALC_HEDGE_TERM_PMTS   48 /* Hedge termination payment calc forecast */
#define ICMOSTANDARDVAR_STL_CONSFEE_LAG        49 /* Student Loan Input: Consolidation fee payment lag month */
#define ICMOSTANDARDVAR_RMTG_FHA_PUT_FAIL_PCT  50 /* Reverse Mortgage Input: FHA_PUT_FAIL_FRAC */
#define ICMOSTANDARDVAR_STL_ISP_HAIRCUT_PCT    51 /* Student Loan Input: Interest Subsidy Payments  reduce % */
#define ICMOSTANDARDVAR_STL_SAP_HAIRCUT_PCT    52 /* Student Loan Input: Special Allowance Payments reduce % */
#define ICMOSTANDARDVAR_ORIG_COLL_AUW          53 /* Accumulated unrealized writedown of collateral at pricing. */
#define ICMOSTANDARDVAR_ORIG_EXCESS_CAPACITY   54 /* Excess capacity at pricing. */
#define ICMOSTANDARDVAR_UNKNOWN                55 /* Unknown type - should be a last one */
#define ICMOSTANDARDVAR_NTYPES   ICMOSTANDARDVAR_UNKNOWN+1  /* # of types */

#ifdef DEFINE_ICMO_STANDARDVAR_TYPE_NAMELIST
/* update ICMOSTANDARDVAR_xx if add to icmo_standardvar_type_namelist */
char *icmo_standardvar_type_namelist[] = {
 "OCT_VAL",
 "OCT_INITVAL",
 "OCT_STEPDOWN_MONTH",
 "OCT_STEPDOWN_FRAC",
 "OCT_FLOOR",
 "SEN_PCT",
 "JUN_PCT",
 "SEN_PREP_PCT",
 "JUN_PREP_PCT",
 "TRUST_PORT_YLD",
 "PRINC_FUND_YLD",
 "AMORT_TRIGGER",
 "ARREARAGE_PAYRATE",
 "HYPERAM_NO_EXCESSINT",
 "TRIG_DELINQ_LIMIT",
 "TRIG_DELINQ_ACTUAL",
 "TRIG_LOSS_LIMIT",
 "TRIG_LOSS_ACTUAL",
 "TRIG_EVENT",
 "STL_ISP_LAG",
 "STL_SAP_LAG",
 "STL_SERVREJ_RATE",
 "ORIG_COLL_BAL",
 "EXCESS_INTEREST",
 "TERMINATE_PRICE",
 "REINVEST_PRICE",
 "REINV_BOND_PRICE",
 "REINV_LOAN_PRICE",
 "REINVEST_PCT",
 "REINV_BOND_PCT",
 "REINV_LOAN_PCT",
 "STL_PREP_ALL_STATUS",
 "ARR_FINAL_PAYRATE",
 "OC_ACTUAL_VAL",
 "CCFNO",
 "COLLAT_PARAM",
 "LOANVAL",
 "REINVEST_END",
 "PDL",
 "INFO", "GROUP_INFO", "TRANCHE_INFO", "CLASS_INFO",
 "RMTG_NEW_BALANCE_TIMING",
 "STL_DEF_ALL_STATUS",
 "STL_PROGRAM_PARTICIPATE_FRAC",
 "HEDGE_TERMINATION_DATE",
 "ORIG_CAPITALIZED_INT",
 "CALC_HEDGE_TERM_PMTS",
 "STL_CONSFEE_LAG",
 "RMTG_FHA_PUT_FAIL_PCT",
 "STL_ISP_HAIRCUT_PCT",
 "STL_SAP_HAIRCUT_PCT",
 "ORIG_COLL_AUW",
 "ORIG_EXCESS_CAPACITY",
 "UNKNOWN",
 NULL };
#else
extern char *icmo_standardvar_type_namelist[] ;
#endif


/* CREDIT_SUPPORT: Credit support information */

typedef struct _CREDIT_SUPPORT {
    int    credsupp_basis_type ;           /* What type of basis is used in basis calculation */
#define CREDSUPP_BASIS_TYPE_SINGLE      0  /* support is provided by single group */
#define CREDSUPP_BASIS_TYPE_MULTI      -1  /* support is provided by multiple groups */
#define CREDSUPP_BASIS_TYPE_FORMULA    -2  /* support basis specified by explicit formula */
#define CREDSUPP_BASIS_TYPE_OC_Y       -3  /* Tranche uses OC_Y methodology, and has both crossed and group-specific support */
#define CREDSUPP_BASIS_TYPE_GROUP_LOSS -4  /* Tranche has crossed subordinate bonds; after subordinate bonds are written
                                               down senior tranches are written down by group loss (not group undercollat) */
    int    credsupp_writedown_by_rules ;   /* Subordination amt is an estimate */
    int    credsupp_fully_insured ;        /* Fully insured? (T/F) */
    int    credsupp_explicit_formula ;     /* If TRUE, credit support computed from explicit formula in model */
#define ICMO_CREDSUPP_EXPLICIT_FORMULA_NONE                   0x00    /* No explicit formula */
#define ICMO_CREDSUPP_EXPLICIT_FORMULA_BALANCE                0x01    /* Support balance (numerator) from explicit formula */
#define ICMO_CREDSUPP_EXPLICIT_FORMULA_BASIS                  0x02    /* Support basis (denominator) from explicit formula */
#define ICMO_CREDSUPP_EXPLICIT_FORMULA_BALANCE_AND_BASIS      0x03    /* Balance and basis from explicit formula */
#define ICMO_CREDSUPP_EXPLICIT_FORMULA_SUPER_SUPPORT_BALANCE  0x04    /* Super support balance from explicit formula */
#define ICMO_CREDSUPP_EXPLICIT_FORMULA_SUPER_AND_BASIS        0x06    /* Super support balance and support basis from explicit formula */
#define ICMO_CREDSUPP_EXPLICIT_FORMULA_OVERRIDE               0x08    /* explicit override from model */

    double credsupp_total_amt ;            /* Total credit support amt */
    double credsupp_basis_amt ;            /* Basis amt from which support is drawn */
    double credsupp_basis_amt_defeased ;   /* Amt of total basis which is fully defeased */
    double credsupp_subordinated_amt ;     /* Amt of support from subordination */
    double credsupp_guaranty_amt ;         /* Amt of support from limited guaranty */
    double credsupp_letter_of_credit_amt ; /* Amt of support from LOC */
    double credsupp_reserve_fund_amt ;     /* Amt of support from reserve fund */
    double credsupp_excess_interest_amt ;  /* Amt of support from excess interest */
    double credsupp_overcollat_amt ;       /* Amt of support from overcollat */
} CREDIT_SUPPORT ;

#define credsupp_multiple_basis_vals  credsupp_basis_type

/* ICMO_OBJECT_xx - structural components of a deal */
#define ICMO_OBJECT_GROUP       1
#define ICMO_OBJECT_BLOCK       2
#define ICMO_OBJECT_CLASS       3
#define ICMO_OBJECT_TRANCHE     4

/* ICMO_CREDIT: structure for credit information */

typedef struct _ICMO_CREDIT {
    int  credit_creditno ;                     /* # in linked list (>=0) */
    int credit_ignore ;                        /* ICMOIGNORE_INDIVIDUAL_CREDIT_xx */
    char *credit_by ;                          /* guarantor, eg "FSA" */
    char credit_name[ICMO_MAX_TRNAM_CHARS+1] ; /* name, eg "RSV-A9". */
    char *credit_full_name ;                   /* string providing full name of the credit */
    char *credit_description ;                 /* description string */
    char credit_flavor ;                       /* ICMOCREDIT_FLAVOR_xx */
#define ICMOCREDIT_FLAVOR_NORMAL         0     /* normal credit */
#define ICMOCREDIT_FLAVOR_MODELING       1     /* used for modeling convenience, not a real credit.  These credit enhancements will not be overridable */
    ICMO_CURRENCY *credit_currencyp ;          /* fund's currency. */
    char credit_type ;                         /* ICMOCREDIT_TYPE_xx */
#define ICMOCREDIT_TYPE_RESERVE_FUND        0  /* reserve fund */
#define ICMOCREDIT_TYPE_LETTER_OF_CREDIT    1  /* letter of credit */
#define ICMOCREDIT_TYPE_FINANCIAL_GUARANTY  2  /* financial guaranty */
    char credit_subtype ;                      /* ICMOCREDIT_SUBTYPE_xx */
#define ICMOCREDIT_SUBTYPE_UNKNOWN            0  /* unknown subtype */
#define ICMOCREDIT_SUBTYPE_AGENCY_WRAP        1  /* guarantee provided by a government sponsored enterprise (but not a direct guarantee by the government). */
#define ICMOCREDIT_SUBTYPE_GOVERNMENT_WRAP    2  /* guarantee provided directly by a government */
#define ICMOCREDIT_SUBTYPE_INSURANCE_WRAP     3  /* guarantee provided by a bond insurance company */
#define ICMOCREDIT_SUBTYPE_ISSUER_GUARANTY    4  /* guarantee provided by the issuer of a transaction, generally covers the first-loss piece */
#define ICMOCREDIT_SUBTYPE_LIQUIDITY_FACILITY 5  /* facility generally available to cover senior fees and expenses and note interest shortfalls if there are insufficient funds available from collateral revenues. Does not typically provide credit support */
#define ICMOCREDIT_SUBTYPE_POOL_POLICY        6  /* guarantee on a pool of loans by an insurance company, generally covering losses on the covered pool of loans up to a certain specified coverage limit */
#define ICMOCREDIT_SUBTYPE_PRINCIPAL_ACCUMULATION  7  /* reserve fund for principal proceeds accumulation */
#define ICMOCREDIT_SUBTYPE_DISCOUNT_MARGIN    8  /* reserve fund used to supplement the interest contribution of discounted assets  */
#define ICMOCREDIT_SUBTYPE_CASH               9  /* reserve fund providing liquidity as well as credit enhancement/support */
#define ICMOCREDIT_SUBTYPE_INTEREST_SMOOTHING 10 /* reserve fund used to smooth uneven collateral interest  */
#define ICMOCREDIT_SUBTYPE_CDS                11 /* reserve fund which covers losses on the CDS  */
#define ICMOCREDIT_SUBTYPE_ROUNDING           12 /* reserve fund used to cover principal payment rounding  */
#define ICMOCREDIT_SUBTYPE_FUNDING_RESERVE    13 /* reserve fund meant to fund the deal's commitments to unfunded assets, as in a CLO */
    int   credit_on_n_items ;                    /* # of items protected by credit */
    char *credit_on_v_item_types ;               /* credit-protected item type ICMO_OBJECT_xx */
    int  *credit_on_v_item_nums  ;               /* credit-protected item number */
    YyyyMmDd credit_full_coverage_terminated ;   /* Date on which full coverage is terminated. */
    } ICMO_CREDIT ;


/* ICMOTABLE: structure for a table defined in CDI */

typedef struct  {
    char *tbl_name ;                /* name of the table */
    int   tbl_tblno ;               /* table num */
    int   tbl_type ;                /* ICMOTABLETYPE_xx */
#define ICMOTABLETYPE_UNKNOWN    0  /* generic unclassified table */
#define ICMOTABLETYPE_STRAT      1  /* reported strat table */
    int   tbl_n_rows ;              /* # of rows */
    int   tbl_n_cols ;              /* # of columns */
    char  **tbl_colnames ;          /* vector of column names */
    double **tbl_v_colvals ;        /* vector of column value vectors */
    char  ***tbl_v_colvals_str ;    /* vector of column string value vectors */
    }  ICMOTABLE ;


/* ICMO_PIHIST_INFO: hist asset info returned by ICMOADDLINFO_GET_PIHIST_INFO */

typedef union {
    char   *chrvals;          /* .. data in char format */
    long   *intvals;          /* .. data in integer format */
    double *dblvals;          /* .. data in double format */
    char  **strvals;          /* .. data in string format */
    } ICMO_PIHIST_DATAVAL ;

typedef struct  {
    char    *pihist_infoname   ;  /* data info name */
    int      pihist_datatype   ;  /* ICMO_PIHIST_DATATYPE_xxx */
#define ICMO_PIHIST_DATATYPE_CHR  1    /* .. data in char format */
#define ICMO_PIHIST_DATATYPE_INT  2    /* .. data in integer format */
#define ICMO_PIHIST_DATATYPE_DBL  3    /* .. data in double format */
#define ICMO_PIHIST_DATATYPE_STR  4    /* .. data in string format */
    YyyyMmDd pihist_anchor_date;  /* date corresponding to [0] datavals */
    int      pihist_n_datavals ;  /* length of data vals */
    ICMO_PIHIST_DATAVAL pihist_v_datavals ; /* vector of datavals */
    }  ICMO_PIHIST_INFO ;

/* ICMO_PIHIST_LOANMOD_xxx: bit flag for ICMO_PIHIST_INFO LOANMOD */
#define ICMO_PIHIST_LOANMOD_NOINFO     0x00  /* No info for Loan Mod              */
#define ICMO_PIHIST_LOANMOD_NONE       0x01  /* No Modification occurred          */
#define ICMO_PIHIST_LOANMOD_UNKNOWN    0x02  /* Unspecified Modification occurred */
#define ICMO_PIHIST_LOANMOD_RATE       0x04  /* Rate Modification                 */
#define ICMO_PIHIST_LOANMOD_PI         0x08  /* P&I Change                        */
#define ICMO_PIHIST_LOANMOD_BALCAP     0x10  /* Balance Capitalization            */
#define ICMO_PIHIST_LOANMOD_BALRED     0x20  /* Balance Forgiveness/Forbearance   */
#define ICMO_PIHIST_LOANMOD_AMORTEXT   0x40  /* Amortization Term Increase        */
#define ICMO_PIHIST_LOANMOD_MATUREXT   0x80  /* Maturity Extension                */
#define ICMO_PIHIST_LOANMOD_FORGIVE   0x100  /* Forgiveness                       */
#define ICMO_PIHIST_LOANMOD_HOPENOTE  0x200  /* Hope Note                         */
#define ICMO_PIHIST_LOANMOD_IO        0x400  /* Change to Interest-Only           */
#define ICMO_PIHIST_LOANMOD_CALL      0x800  /* Call Protection Change            */
#define ICMO_PIHIST_LOANMOD_MEXTOPT  0x1000  /* Maturity Extension Option         */
#define ICMO_PIHIST_LOANMOD_OTHER    0x2000  /* Other                             */


/* ICMOWTR_CTRL: control structure for waterfall report */

typedef struct  {
    int     icmowtrc_report_on; /* TRUE to request report, FALSE to disable report */
    int     icmowtrc_start_per; /* requested report starting period */
    int     icmowtrc_end_per;   /* requested report ending period */
    }  ICMOWTR_CTRL ;


/* ICMOWTR_ACTION: result structure of waterfall report */

typedef struct  {
    char   *icmowtra_next ;     /* next action in link list */
    int     icmowtra_actno ;    /* action number in CDI sequence */
    char   *icmowtra_from ;     /* action source */
    char   *icmowtra_to ;       /* action destination */
    char   *icmowtra_what ;     /* action classification */
    char   *icmowtra_as ;       /* action addl classification */
    double  icmowtra_amount ;   /* action amount */
    double *icmowtra_frombal ;  /* if non-NULL, ptr to balance of source(FROM) at begin of action */
#define ICMOWTRA_FROMBAL_NOVAL  (-1e20)  /* frombal not available */
    }  ICMOWTR_ACTION ;


/* ICMOADDLINFO: Control structure for icmo_addl_info() */

typedef struct  {
/* input/control info for icmo_addl_info() */
    POOL_INFO *inpval_pip ;  /* NULL or POOL_INFO structure if addl_info requested for specific pool/loan */
    YyyyMmDd  inpval_date;   /* O or date if addl_info requested for specific date/perid */
    int    inpval_int ;      /* input integer val */
    double inpval_dbl ;      /* input float value */
    char  *inpval_str ;      /* input strval */
    void  *inpval_ptr ;      /* structure ptr val */
/* info returned by       icmo_addl_info() */
    int    retval_int ;      /* integer return value */
    long    retval_long ;     /* long return value - for dates */
    double retval_dbl ;      /* float return value */
    /* arrays use retval_int to indicate the number of array cells available */
    int    *retval_int_array ;   /* integer array return value */
    long   *retval_long_array ;  /* long array return value - for dates */
    double *retval_dbl_array ;   /* float array return value */
    char  **retval_str_array ;   /* string array return value */
    char  **retval_ptr_array ;   /* array of pointers return value */
    char  *retval_str ;      /* string return value */
    void  *retval_ptr ;      /* structure ptr return val */
    char  *retval_errmsg ;   /* message here if error occurred */
    } ICMOADDLINFO ;

#define ICMOADDLINFO_RETVAL_STR_NA    NULL     /* NA for retval_str */
#define ICMOADDLINFO_RETVAL_INT_NA    (-32761)   /* NA for retval_int */
#define ICMOADDLINFO_RETVAL_LONG_NA   (-33332761)   /* NA for retval_long */
#define ICMOADDLINFO_RETVAL_DBL_NA    (-1e29)    /* NA for retval_dbl */
#define IS_ICMOADDLINFO_RETVAL_DBL_NA(retval_dbl)      \
        ((retval_dbl) == ICMOADDLINFO_RETVAL_DBL_NA || \
         (retval_dbl) == ICMO_NA_CALC_RESULTS)

/* ICMOADDLINFO_xx: addl info types */
#define ICMOADDLINFO_REPORTED_TR_INTPMT            0  /* trustee reported interest payment, (trno) */
#define ICMOADDLINFO_REPORTED_TR_PRINPMT           1  /* trustee reported principal payment, (trno) */
#define ICMOADDLINFO_FULL_DEALNAME                 2  /* full dealname from prospectus */
#define ICMOADDLINFO_TRUSTEE_DEAL                  3  /* trustee */
#define ICMOADDLINFO_TRUSTEE_INDENTURE             4  /* trustee usually for non-remics, sometimes called Bond Trustee */
#define ICMOADDLINFO_TRUSTEE_OWNER                 5  /* trustee usually for non-remics, sometimes called Grantor Trust Trustee */
#define ICMOADDLINFO_SERVICER_SUB                  6  /* sub servicer */
#define ICMOADDLINFO_SERVICER_MASTER               7  /* master servicer */
#define ICMOADDLINFO_SERVICER_SPECIAL              8  /* special servicer, usually for commercial deals */
#define ICMOADDLINFO_TR_FIRST_REDEEM_YYYYMMDD      9  /* 1st redeem date for tranche, available AFTER icmo_cashflows. */
#define ICMOADDLINFO_RATING_ORIG_MOODY            10  /* Moody's rating @ issuance, (trno) */
#define ICMOADDLINFO_RATING_ORIG_S_P              11  /* Standard & Poor's rating          */
#define ICMOADDLINFO_RATING_ORIG_DUFF_PHELPS      12  /* Duff & Phelps rating              */
#define ICMOADDLINFO_RATING_ORIG_FITCH            13  /* Fitch rating                      */
#define ICMOADDLINFO_LATEST_CDU_IS_PARTIAL        14  /* for single tranche mode -TRUE if latest cdu is partial */
#define ICMOADDLINFO_CDU_SURPLUS_AMOUNT           15  /* surplus interest paid to surlpus tr */
#define ICMOADDLINFO_CDU_BEG_TR_PRINBAL           16  /* a tr's beginning principal balance */
#define ICMOADDLINFO_CDU_END_TR_PRINBAL           17  /* a tr's ending principal balance */
#define ICMOADDLINFO_CDU_BEG_TR_NTLBAL            18  /* a tr's beginning notional balance */
#define ICMOADDLINFO_CDU_END_TR_NTLBAL            19  /* a tr's ending notional balance */
#define ICMOADDLINFO_CDI_OVERCOLLAT_FLAG          20  /* TRUE if CDI explicitly marked with overcollat flag */
#define ICMOADDLINFO_LATEST_CDU_GNMA_TAPE         21  /* What gnma tape was used for update or 0 for no gnma pools */
#define ICMOADDLINFO_DRAWS_BY_GROUP               22  /* collateral group draws - not adjusted for forward settling */
#define ICMOADDLINFO_TR_AGENCY_TYPE               23  /* a tr's predominant collateral agency type */
#define ICMOADDLINFO_TR_CFTYPE                    24  /* a tr's predominant collateral cftype */
#define ICMOADDLINFO_GRP_AGENCY_TYPE              25  /* a grp's predominant collateral agency type */
#define ICMOADDLINFO_GRP_CFTYPE                   26  /* a grp's predominant collateral cftype */
#define ICMOADDLINFO_HAS_DELINQ_DEP               27  /* TRUE if can fcst delinq */
#define ICMOADDLINFO_HAS_PROPLEVEL_DEP            28  /* TRUE if can fcst NOI$ */
#define ICMOADDLINFO_GRP_PARSED_INFO              29  /* Ret: PARSED_xx - How grp was parsed      */
#define ICMOADDLINFO_TR_PARSED_INFO               30  /* Ret: PARSED_xx - How tranche was parsed  */
#define ICMOADDLINFO_LOAN_DAYCOUNT                31  /* Ret: ICMO_DAYCOUNT_xx for given pip and date/period */
#define ICMOADDLINFO_EARLIEST_CDU_DATE            32  /* Ret: Date from which database has a continuous sequence of CDUs till latest_cdu. */
#define ICMOADDLINFO_EARLIEST_CDA_DATE            33  /* Ret: earliest date in a CDA file. ret zero if no CDA */
#define ICMOADDLINFO_SYSVAR_USAGE                 34  /* TRUE if given #sysvar used in CDI/CDU */
#define ICMOADDLINFO_SEASON_COLL_LOAN_LEVEL       35  /* Deprecated. Use ICMOADDLINFO_COLL_LOAN_LEVEL */
#define ICMOADDLINFO_LOAN_GROSS_RATE_FRAC         36  /* Ret: gross rate fraction for given pip, date and gross rate face */
#define ICMOADDLINFO_LOAN_SERV_RATE_FRAC          37  /* Ret: serv  rate fraction for given pip, date and serv  rate face */
#define ICMOADDLINFO_LOAN_ADDL_SERV_RATE_FRAC     38  /* Ret: addl serv rate fraction for given pip and date             */
#define ICMOADDLINFO_GET_PIARR_INFO               39  /* get Arrearage info structure */
#define ICMOADDLINFO_SET_PIARR_INFO               40  /* set Arrearage info */
#define ICMOADDLINFO_DATA_AVAILABILITY            41  /* get data availability info. */
#define ICMOADDLINFO_IDXFILE_NAME                 42  /* get name of idxfile */
#define ICMOADDLINFO_DEAL_CURRENCY                43  /* returns deal currency info and list of other currencies used in the deal */
#define ICMOADDLINFO_COUPON_PRINBAL               44  /* returns coupon based on principal balance */
#define ICMOADDLINFO_COLLAT_TYPE                  45  /* returns collat type string for collat grp */
#define ICMOADDLINFO_RATING_CURR_MOODY            46  /* Moody's rating, current, (trno)   */
#define ICMOADDLINFO_RATING_CURR_S_P              47  /* Standard & Poor's rating, current */
#define ICMOADDLINFO_RATING_CURR_DUFF_PHELPS      48  /* Duff & Phelps rating, current     */
#define ICMOADDLINFO_RATING_CURR_FITCH            49  /* Fitch rating, current             */
#define ICMOADDLINFO_SCHEDULE_NAMES               50  /* name of schedule given schedule # */
#define ICMOADDLINFO_TR_SUPPORT_PCT_ORIG          51  /* Deprecated. Use ICMOADDLINFO_TR_CREDIT_SUPPORT_INFO */
#define ICMOADDLINFO_TR_SUPPORT_PCT_CURR          52  /* Deprecated. Use ICMOADDLINFO_TR_CREDIT_SUPPORT_INFO */
#define ICMOADDLINFO_TR_CREDIT_SUPPORT            53  /* Deprecated. Use ICMOADDLINFO_TR_CREDIT_SUPPORT_INFO */
#define ICMOADDLINFO_TR_CREDIT_SUPPORT_FORMULA    54  /* symbolic credit support formula */
#define ICMOADDLINFO_RATING_ORIG                  55  /* Original bond ratings for tranche - all agencies */
#define ICMOADDLINFO_RATING_CURR                  56  /* Current bond ratings for tranche - all agencies */
#define ICMOADDLINFO_ISSUE_PRICE100               57  /* issue price 100 */
#define ICMOADDLINFO_DEAL_IS_WAVG_MEGA            58  /* flag if mega/giant/platinum is weighted average */
#define ICMOADDLINFO_TR_WRITEDOWN_ACCUM           59  /* tranche's accumulated writedowns */
#define ICMOADDLINFO_TR_CURRENCY                  60  /* Currency in which tranche is denominated */
#define ICMOADDLINFO_LOAN_CURRENCY                61  /* Deprecated: Use ICMOADDLINFO_GET_PI_INFO, GET_PI_CURRENCY instead. */
#define ICMOADDLINFO_TR_PAID_DOWN_WITH_BAL        62  /* flag if tranche is paid down when real and notional bals are zero */
#define ICMOADDLINFO_ISSUE_YIELD                  63  /* issue yield */
#define ICMOADDLINFO_TR_CAB_BASIS                 64  /* Price basis for Capital Accretion bond */
#define ICMOADDLINFO_PREVIOUS_SERVICER_MASTER     65  /* Vector of deal's previous master servicers */
#define ICMOADDLINFO_PREVIOUS_SERVICER_SPECIAL    66  /* Vector of deal's previous special servicers */
#define ICMOADDLINFO_PREVIOUS_TRUSTEE_DEAL        67  /* Vector of deal's previous trustees */
#define ICMOADDLINFO_COLLATERAL_MANAGER           68  /* Deal's collateral manager */
#define ICMOADDLINFO_CDOTEST_VALUE                69  /* Given CDOTEST type and groupno, return CDOTEST value and CDOTEST structure */
#define ICMOADDLINFO_LOANVAL_SYMVAR               70  /* check if a symvar is loanval, if yes, return value */
#define ICMOADDLINFO_GET_PISTL_INFO               71  /* Get PI_STUDENTLOAN_INFO info structure */
#define ICMOADDLINFO_GET_DEALSTATS_INFO           72  /* deprecated. Use ICMOADDLINFO_GET_GRP_DEALSTATS with inpval_int and groupno = 0 */
#define ICMOADDLINFO_DEAL_COUNTRY_CODE            73  /* ISO 3166 country code for international deals */
#define ICMOADDLINFO_TR_LEGAL_MATURITY            74  /* tranche's legal maturity date */
#define ICMOADDLINFO_SYMVAR_HAS_CFS               75  /* indicates whether a #define variable in a CDI which is also a symvar tranche can have icmo_stats() called for it */
#define ICMOADDLINFO_COLLAT_TRANSACT_SET          76  /* returns array of ptrs to ICMOTRANS structures for transaction set*/
#define ICMOADDLINFO_TRDIST_AVAILABLE             77  /* TRUE if tranche distribution info for the tr is available */
#define ICMOADDLINFO_REQUIRED_ASSET_INFOS         78  /* Deprecated. Use ICMOADDLINFO_GET_LOANDATA */
#define ICMOADDLINFO_ASSET_INFO                   79  /* Deprecated. Use ICMOADDLINFO_GET_LOANDATA */
#define ICMOADDLINFO_ICMOTABLES                   80  /* returns array of ptrs to ICMOTABLE structures */
#define ICMOADDLINFO_PREFUND_ADJ                  81  /* not used */
#define ICMOADDLINFO_TR_COUPON_UPDATED            82  /* updated value of icmo_tranche_coupon if settle in the future */
#define ICMOADDLINFO_TR_CONTRIBUTED_WAC           83  /* Contributed collateral WAC for tranche */
#define ICMOADDLINFO_TR_CAN_PIK                   84  /* returns TRUE in retval_int if tranche can PIK */
#define ICMOADDLINFO_TR_ALT_CUSIP                 85  /* tranche's cusip temporary industry-used before assignment of real cusip  */
#define ICMOADDLINFO_PREVIOUS_COLLATERAL_MANAGER  86  /* Vector of deal's previous collateral managers */
#define ICMOADDLINFO_CALCULATED_COUPON            87  /* calculated coupon */
#define ICMOADDLINFO_TR_CINS                      88  /* tranche's CINS - CUSIP International Number */
#define ICMOADDLINFO_TR_ISIN                      89  /* tranche's ISIN - International Securities Identification Number */
#define ICMOADDLINFO_TR_PAID_DOWN_AT_LATEST_CDU   90  /* flag if tranche is paid down as of latest cdu and ICMOADDLINFO_TR_PAID_DOWN_WITH_BAL */
#define ICMOADDLINFO_TR_RAW_PAYDATE               91  /* get tranche paydate without businessday adjustment */
#define ICMOADDLINFO_INDEX_IDL                    92  /* returns ICMO_INDEX_IDL structure for given index name */
#define ICMOADDLINFO_TR_HAS_PAYRULE_INTEREST      93  /* TRUE if tranche may receive interest in payrule */
#define ICMOADDLINFO_CREDIT_EXCESS_TRNO           94  /* tranche number that receives excess of a reserve fund if specified */
#define ICMOADDLINFO_CREDIT_SUPPORTS_BLOCKNO      95  /* returns array of BLOCK numbers supported by this ECE */
#define ICMOADDLINFO_SET_PI_INFO                  96  /* override POOL_INFO values corresp. to SET_PI_xx. To be used only in icmo_replace_buy_collat_fcn() or before icmo_replace_collat_list() */
#define ICMOADDLINFO_TR_INTSHORT_ACCUM            97  /* tranche's accumulated intshort */
#define ICMOADDLINFO_DEAL_ASSET_TYPES             98  /* returns array of deal asset types: ICMOASSETBACK_xx */
#define ICMOADDLINFO_SET_DEAL_TERMINATE_DATE      99  /* alter DEAL_TERMINATE_DATE */
#define ICMOADDLINFO_IS_PAYMENT_CDUDATE          100  /* given a CDU date, return TRUE if it is a payment CDU date */
#define ICMOADDLINFO_N_CDU_POOLS                 101  /* Number of pools in CDU  */
#define ICMOADDLINFO_N_CDU_POOLS_WAVG            102  /* Estimate from CDU of number of wavg pools */
#define ICMOADDLINFO_CHILD_CDUYYMM_REQUIRED      103  /* returns CDUYYMM that is required to parse */
#define ICMOADDLINFO_CDU_ASOF_DATES              104  /* returns CDU asof dates within a CDU yymm range */
#define ICMOADDLINFO_TRANCHES_DISPLAY_ORDER      105  /* returns array of trunche numbers in DISPLAY_ORDER */
#define ICMOADDLINFO_TR_CDU_ACCUM_SHORTFALL_NSINT 106 /* a tr's accumulated non supported interest shortfall */
#define ICMOADDLINFO_DEAL_HAS_CLASS_FORECAST     107  /* returns TRUE in retval_int if top deal or child deal uses PV_CLASS */
#define ICMOADDLINFO_ASSET_PIK_INFO              108  /* returns TRUE in retval_int if inpval_pip can PIK during fcasts. For non re-remic assets returns ICMO_ASSET_PIK_INFO in retval_ptr. */
#define ICMOADDLINFO_TR_COMMENT                  109  /* returns in retval_str the tranche comment */
#define ICMOADDLINFO_INPUT_MACRO_NAMES           110  /* return list of INPUT type macro names */
#define ICMOADDLINFO_SERVICING_FEE_PAID_IN_RULES 111  /* returns in retval_int if deal pays the servicing in the payment rules - needed because collateral interest flows will then report gross interest */
#define ICMOADDLINFO_PIP_UNIQUE_ID               112  /* given pip, create a unique ID */
#define ICMOADDLINFO_TR_RATING_WATCH             113  /* list of tranche rating watch info */
#define ICMOADDLINFO_INDEX_DETERMINATION_DATE    114  /* returns in retval_long INDEX_DETERMINATION date corresp. to the inpval_date for index/subname provided in inpval_str & inpval_prt  */
#define ICMOADDLINFO_RATING_AGENCY_SHORT_NAME    115  /* short name for rating agency (for applications to display) from rat_agcy.idl */
#define ICMOADDLINFO_REQUIRED_CMOVER             116  /* minimum subroutines version required for this deal */
#define ICMOADDLINFO_POOL_TO_COLL_SHIFT          117  /* returns pool to coll shifted per */
#define ICMOADDLINFO_TR_CDU_ACCUM_SHORTFALL_SSRA 118  /* a tr's accumulated SSRA non supported interest shortfall */
#define ICMOADDLINFO_CDI_CREATE_DATE             119  /* returns creation date of CDI (or LONG_NA) in retval_long. If approx, retval_int set to TRUE */
#define ICMOADDLINFO_DEAL_INTRINSIC_ORIGBAL      120  /* Deprecated. Use ICMOADDLINFO_INTRINSIC_DEALBAL */
#define ICMOADDLINFO_DEAL_INTRINSIC_CURBAL       121  /* Deprecated. Use ICMOADDLINFO_INTRINSIC_DEALBAL */
#define ICMOADDLINFO_TR_ATTRIBUTES               122  /* returns retval_int_array containing attributes depending on subscript ICMOADDLINFO_RETVAL_TR_ATTRIB_xx */
#define ICMOADDLINFO_TR_PY_BASIS                 123  /* tranche's balance for calculating price/100. Use ICMOADDLINFO_INPVAL_GET_xx_INFO to select which balance */
#define ICMOADDLINFO_GET_DEALSTATS               124  /* deprecated. Use ICMOADDLINFO_GET_GRP_DEALSTATS with groupno = 0 */
#define ICMOADDLINFO_DEAL_HAS_CF_REINV           125  /* Whether the deal supports cashflow reinvestment via icmo_vcashflow_reinv_rates forecasting */
#define ICMOADDLINFO_DEAL_BUSINESS_CENTERS       126  /* list of business centers used in deal */
#define ICMOADDLINFO_GROUP_CURRENCY              127  /* returns group currency info */
#define ICMOADDLINFO_SET_EXPR                    128  /* override an expression with an alternative expr or reset to original state */
#define ICMOADDLINFO_TR_LASTCDU_FACTOR           129  /* tr factor from latest CDU parsed. same as icmo_tranche_start_factors[] if not settle in past */
#define ICMOADDLINFO_GET_WATERFALL_REPORT        130  /* returns waterfall report info */
#define ICMOADDLINFO_TR_RELEASE_DATE             131  /* returns raw tranche release date */
#define ICMOADDLINFO_GET_LOAN_PRODUCT_TYPE       132  /* returns loan product type */
#define ICMOADDLINFO_COLL_LOAN_LEVEL             133  /* returns whether collateral is loan level or not */
#define ICMOADDLINFO_TR_COUPONCAPSHORT_ACCUM     134  /* tranche's accumulated couponcap intshortfall */
#define ICMOADDLINFO_GRP_HAS_ABS_SUMMARY_INFO    135  /* returns TRUE if group has ABS Summary info reported */
#define ICMOADDLINFO_IRR_ASSOCIATED_BLOCKS       136  /* Deprecated. Use ICMOADDLINFO_TR_BLOCKS with ICMOADDLINFO_INPVAL_TR_BLOCKS_IRR */
#define ICMOADDLINFO_CDU_DEAL_OFFSET             137  /* # of months offset from deal pay month to CDU month */
#define ICMOADDLINFO_ACCESS_KC_USAGE             138  /* return access_kc usage info */
#define ICMOADDLINFO_HAS_EXPORT_VARS             139  /* returns TRUE if deal has exported variables */
#define ICMOADDLINFO_SUBSET_GRP_PARENT_GRPS      140  /* return array of group #s corresponding to parent group of a subset groups.  Returns TRUE if group is not a subset group */
#define ICMOADDLINFO_ANALYZE_EXPR                141  /* Analyze an expression */
#define ICMOADDLINFO_FOREX_INFO                  142  /* returns info about currency exchanges referenced in deal */
#define ICMOADDLINFO_CREDIT_TOTAL_ACCUM_PAYOUT   143  /* returns total ECE pay out from the latest CDU */
#define ICMOADDLINFO_TR_INITIAL_COUPON           144  /* returns tranche initial coupon if AT value is provided */
#define ICMOADDLINFO_GET_INDEX_PROXY             145  /* get index proxy info */
#define ICMOADDLINFO_SET_INDEX_PROXY             146  /* modify index proxy info */
#define ICMOADDLINFO_ASSET_MPI_INFO              147  /* Process on which asset is parsed.  Limited info available for re-remic pool if not on root process (process 0). */
#define ICMOADDLINFO_PIBAL_CONTRIB_FRAC          148  /* given pip, returns contribution frac for curbal to deal level */
#define ICMOADDLINFO_ICMOTV_CALCULATED           149  /* check for an icmot_vectors validity */
#define ICMOADDLINFO_CPB_RESET_CPRVAL            150  /* get/set CPB reset cprval */
#define ICMOADDLINFO_GET_PIRML_INFO              151  /* Get PI_REVERSE_MORTGAGE_INFO info structure */
#define ICMOADDLINFO_OVRD_ASSET_CF_INFO          152  /* given pip, provide info for override_asset functionality */
#define ICMOADDLINFO_TR_NO_WRITEDOWN             153  /* retval_int is TRUE if tranche takes implied writedowns. Set to TRUE for all COLLAT tranches if any of the underlying tranches have such provision */
#define ICMOADDLINFO_SET_CF_REINV                154  /* to modify CF_REINV rate formula */
#define ICMOADDLINFO_GET_PI_INFO                 155  /* Get pool/loan/asset related values corresp. to GET_PI_xx */
#define ICMOADDLINFO_TR_REPORTED_CURBAL          156  /* trustee reported tranche balance, e.g. for tranche with origbal=0 , (trno) */
#define ICMOADDLINFO_DEAL_DATA_FROM_CHILD_DEALS  157  /* returns retval_int=ICMOADDLINFO_RETVAL_DEAL_DATA_FROM_CHILD_xxx if deal data info is represented by the child's data, retval_ptr_array elements point to the corresp. child icmop */
#define ICMOADDLINFO_CREDIT_COVERS_WHAT          158  /* For each CREDIT_COVERS category ICMOADDLINFO_RETVAL_CREDIT_COVERS_xxx returns in retval_int_array values ICMOADDLINFO_RETVAL_CREDIT_COVERS_ON_ITEMS_xxx  */
#define ICMOADDLINFO_TR_UNREALIZED_WRITEDOWN_ACCUM 159 /* tranche's accumulated writedowns */
#define ICMOADDLINFO_GET_LOANDATA                160  /* returns list or single LOANDATA for deal or pip based on ICMOADDLINFO_INPVAL_GET_LOANDATA_xx */
#define ICMOADDLINFO_ASSET_SPLIT                 161  /* split asset */
#define ICMOADDLINFO_TR_BLOCKS                   162  /* returns linked list of BLOCK_INFO pointers associated with tranche according to ICMOADDLINFO_INPVAL_TR_BLOCKS_xx */
#define ICMOADDLINFO_CREDIT_INFO                 163  /* mode to request info about the external credit enhancement */
#define ICMOADDLINFO_SET_PI_STDVAR_OVERRIDE      164  /* set asset specific standardvar override */
#define ICMOADDLINFO_ICMOSTLBPS                  165  /* returns vector of all ICMOSTLBP defined in deal */
#define ICMOADDLINFO_TR_ORIGBAL_FULL             166  /* returns sum of origbals of all blocks in tranche, without considering block CREATION dates */
#define ICMOADDLINFO_DEAL_ALLOW_BANKRUPT_FORECAST 167 /* returns CDI ALLOW_BANKRUPTCY_FORECASTING setting */
#define ICMOADDLINFO_GRP_ATTRIBUTES              168  /* returns retval_int_array containing attributes depending on subscript ICMOADDLINFO_RETVAL_GRP_ATTRIB_xx */
#define ICMOADDLINFO_GET_GRP_DEALSTATS           169  /* get group level DEALSTATS struct */
#define ICMOADDLINFO_TR_FULLY_INSURED            170  /* fully insured status of tranche as of issue or latest cdu */
#define ICMOADDLINFO_SUPPORT_BASIS_GROUPS        171  /* Vector of groupnos of support basis groups */
#define ICMOADDLINFO_GET_START_ACCOUNT           172  /* get int/prn collection account values as of simulation start */
#define ICMOADDLINFO_SET_START_ACCOUNT           173  /* set int/prn collection account values as of simulation start */
#define ICMOADDLINFO_TR_SUPPORTED_TRANCHES       174  /* Deprecated. Use ICMOADDLINFO_TR_SUPPORTED_TRANCHES_INFO */
#define ICMOADDLINFO_TR_SUPPORTING_TRANCHES      175  /* Deprecated. Use ICMOADDLINFO_TR_SUPPORTING_TRANCHES_INFO */
#define ICMOADDLINFO_GET_GROUP_INFO              176  /* Get group attribute corresponding to GET_GROUP_xx */
#define ICMOADDLINFO_DEAL_BAL_SUPPORTED          177  /* Outstanding deal balance less the balance of any blocks tagged with NO_SUPPORT_BALANCE keyword */
#define ICMOADDLINFO_TR_COUPON_INDEX_USED        178  /* returns index/value used for tranche coupon calculation */
#define ICMOADDLINFO_GET_EXCHANGE_INFO           179  /* Get tranche exchange relationships for a specific tranche, or all tranches in deal */
#define ICMOADDLINFO_GET_HPI_INFO                180  /* returns Housing Price Index info */
#define ICMOADDLINFO_GET_PIHIST_INFO             181  /* get asset hist info */
#define ICMOADDLINFO_SET_ADDL_GROUP              182  /* setup addl subset group */
#define ICMOADDLINFO_SET_ACCOUNT_HOLDBACK        183  /* setup collection account holdback forecast */
#define ICMOADDLINFO_GET_FORB_TREATMENT          184  /* get forbearance treatment method */
#define ICMOADDLINFO_SET_FORB_TREATMENT          185  /* set forbearance treatment method */
#define ICMOADDLINFO_TR_REPORTED_LATEST_CDU      186  /* get trustee reported tr info */
#define ICMOADDLINFO_TR_START_INFO               187  /* tranche info as of simulation start */
#define ICMOADDLINFO_IS_IN_CLASS                 188  /* check if a class/block is part of another class */
#define ICMOADDLINFO_DEAL_HAS_ASSET_REINV        189  /* check ASSET REINV feature */
#define ICMOADDLINFO_INTRINSIC_DEALBAL           190  /* returns ASOF_xxx  deal balance excluding balances of bonds used for modeling purposes only (e.g. "modeling tranches") */
#define ICMOADDLINFO_TRADING_ACCURACY_DETAILS    191  /* returns detail info if icmo_not_at_trading_accuracy */
#define ICMOADDLINFO_SET_GRP_ADDLCF              192  /* setup group level addl CF forecast */
#define ICMOADDLINFO_GET_OPTREDEEM_INFO          193  /* get optional redemption info */
#define ICMOADDLINFO_SINGLE_TR_MODE_INFO         194  /* get supported group/tranche info for single tranche mode */
#define ICMOADDLINFO_TR_PARI_PASSU_TRANCHES      195  /* Sum of tranche balances pari-passu with this tranche */
#define ICMOADDLINFO_TR_SENIOR_TRANCHES          196  /* Sum of tranche balances senior to this tranche */
#define ICMOADDLINFO_CHECK_ICMO_ITH_SCENARIO     197  /* check if scenario cashflows accessible. Works only with SET_ICMO_ITH_SCENARIO */
#define ICMOADDLINFO_TR_CREDIT_SUPPORT_INFO      198  /* credit support info - unified interface that replaces and extends ICMOADDLINFO_TR_SUPPORT_PCT_ORIG/CURR */
#define ICMOADDLINFO_SET_HEDGE_INFO              199  /* set HEDGE info */
#define ICMOADDLINFO_COLLAT_MODELED_DETAIL       200  /* returns flag detailing the nature of the collateral in the model or update  */
#define ICMOADDLINFO_DEAL_IS_MASTER_TRUST        201  /* retval_int = TRUE if deal is master trust */
#define ICMOADDLINFO_SET_TR_INFO                 202  /* override some tranche info */
#define ICMOADDLINFO_TR_INDEX_DEPS               203  /* tranche's index dependencies */
#define ICMOADDLINFO_MASTER_TRUST_INFO           204  /* Information about corresponding series issuance tranches in master trust deals */
#define ICMOADDLINFO_TR_SUPPORTED_TRANCHES_INFO  205  /* Vector of tranchenos of tranches supported by this tranche */
#define ICMOADDLINFO_TR_SUPPORTING_TRANCHES_INFO 206  /* Vector of tranchenos of tranches supporting this tranche, by order of subordination */
#define ICMOADDLINFO_TR_SUPPORT_BASIS_MARKET_VALUE 207 /* tranche's support basis based on market value */
#define ICMOADDLINFO_GET_ABS_SUMMARY_INFO        208  /* get ABS_SUMMARY_INFO */
#define ICMOADDLINFO_TR_SCHEDULE_DEPS            209  /* tranche's schedule dependencies */
#define ICMOADDLINFO_CREATE_DEALTREE_PARTITIONS  210  /* create DEALTREE PARTITIONS */
#define ICMOADDLINFO_DEAL_MARKET_CATEGORY        211  /* returns string code detailing deal category using current market convention classification */
#define ICMOADDLINFO_SET_REPAYMDR_BASIS          212  /* set STL REPAYMDR basis */
#define ICMOADDLINFO_TR_ALTIDS                   213  /* Tranche or deal aternative IDs */
#define ICMOADDLINFO_DEAL_DETERMINED_ASSUMPTIONS 214  /* returns DEAL_DETERMINED_ASSUMPTIONS info */
#define ICMOADDLINFO_TR_STRUCTURAL_BALANCES      215  /* tranche structural balances */
#define ICMOADDLINFO_DEAL_ATTRIBUTES             216  /* Get deal attributes */
#define ICMOADDLINFO_GET_TR_INFO                 217  /* Get some tranche info */
#define ICMOADDLINFO_DEAL_HAS_EXCLUDE_NONPERF_FROM_SUPPORT_BASIS 218 /* Whether deal excludes nonperforming assets from support basis */
#define ICMOADDLINFO_PDL_PROVISIONING_METHOD     219  /* PDL provisioning method */

#define ICMOADDLINFO_DEAL_HAS_PAYRULE_SCRIPT 10000 /* for Intex internal use only */

/* ICMOADDLINFO_RETVAL_PDL_PROVISIONING_METHOD_xx */
#define ICMOADDLINFO_RETVAL_PDL_PROVISIONING_METHOD_NA              0 /* PDL is not applicable to this group */
#define ICMOADDLINFO_RETVAL_PDL_PROVISIONING_METHOD_DEFAULT_PARTIAL 1 /* PDL includes a portion of non-performing balance */
#define ICMOADDLINFO_RETVAL_PDL_PROVISIONING_METHOD_DEFAULT_FULL    2 /* PDL includes all non-performing balance */
#define ICMOADDLINFO_RETVAL_PDL_PROVISIONING_METHOD_NET_LOSS        3 /* PDL includes just the loss amount determined upon liquidation */
#define ICMOADDLINFO_RETVAL_PDL_PROVISIONING_METHOD_UNKNOWN         4 /* PDL is applicable, but method is unknown */

/* ICMOADDLINFO_INPVAL_GET_LOANDATA_xx */
#define ICMOADDLINFO_INPVAL_GET_CURRENT_INFO 0   /* inpval_int: get current  values of requested data */
#define ICMOADDLINFO_INPVAL_GET_ORIG_INFO    1   /* inpval_int: get original values of requested data */
#define ICMOADDLINFO_INPVAL_GET_FORECAST_START_INFO 2 /* inpval_int: get values as of forecast start (latest CDU) */

#define ICMOADDLINFO_INPVAL_CREATE_IF_NA   128   /* inpval_int: used by ICMOADDLINFO_GET_GRP_DEALSTATS */

#define ICMOADDLINFO_RETVAL_LOANVAL_STATIC   1  /* retval for ICMOADDLINFO_LOANVAL_SYMVAR */
#define ICMOADDLINFO_RETVAL_LOANVAL_DYNAMIC  2  /* retval for ICMOADDLINFO_LOANVAL_SYMVAR */

#define ICMOADDLINFO_RETVAL_CASHFLOW_REINV_NO    0 /* retval for ICMOADDLINFO_CASHFLOW_REINV_STATUS */
#define ICMOADDLINFO_RETVAL_CASHFLOW_REINV_YES   1 /* retval for ICMOADDLINFO_CASHFLOW_REINV_STATUS */
#define ICMOADDLINFO_RETVAL_CASHFLOW_REINV_FIXED 2 /* retval for ICMOADDLINFO_CASHFLOW_REINV_STATUS */

/* return values (retval_int) for ICMOADDLINFO_COLL_LOAN_LEVEL */
#define ICMOADDLINFO_RETVAL_LOAN_LEVEL_UNKNOWN   0 /* loan level status is unknown */
#define ICMOADDLINFO_RETVAL_LOAN_LEVEL_YES       1 /* loan level data is available */
#define ICMOADDLINFO_RETVAL_LOAN_LEVEL_NO        2 /* loan level data is not available */

/* return value bitflag (retval_int) for ICMOADDLINFO_TRADING_ACCURACY_DETAILS */
#define ICMOADDLINFO_RETVAL_NOT_AT_TRADING_ACCURACY_CDI       0x01 /* deal's CDI at portfolio level accuracy */
#define ICMOADDLINFO_RETVAL_NOT_AT_TRADING_ACCURACY_CDU       0x02 /* deal's CDU at portfolio level accuracy */
#define ICMOADDLINFO_RETVAL_NOT_AT_TRADING_ACCURACY_CHILD_CDI 0x04 /* underlying deal's CDI at portfolio level accuracy */
#define ICMOADDLINFO_RETVAL_NOT_AT_TRADING_ACCURACY_CHILD_CDU 0x08 /* underlying deal's CDU at portfolio level accuracy */

/* return values (retval_int) for ICMOADDLINFO_ACCESS_KC_USAGE */
#define ICMOADDLINFO_RETVAL_ACCESS_KC_OK    0 /* access_kc not provided or not used or used ok */
#define ICMOADDLINFO_RETVAL_ACCESS_KC_BAD   1 /* access_kc provided but not used because bad or expired */
#define ICMOADDLINFO_RETVAL_ACCESS_KC_WARN  2 /* access_kc provided and used ok, but expiring soon. Check retval_long for expiration date */

/* return values (retval_int) for ICMOADDLINFO_DEAL_DATA_FROM_CHILD_DEALS  */
#define ICMOADDLINFO_RETVAL_DEAL_DATA_FROM_CHILD_NO        0 /* no DEAL_DATA_FROM_CHILD referenced */
#define ICMOADDLINFO_RETVAL_DEAL_DATA_FROM_CHILD_DEAL      1 /* DEAL_DATA_FROM_CHILD reference on the deal level */
#define ICMOADDLINFO_RETVAL_DEAL_DATA_FROM_CHILD_BY_GROUPS 2 /* DEAL_DATA_FROM_CHILD referenced by groups  */

#define ICMOADDLINFO_INPVAL_CHECK_ALL_SCEN_ACCESS   -1 /* inpval_int: used by ICMOADDLINFO_CHECK_ICMO_ITH_SCENARIO */
/* return values (retval_int) for ICMOADDLINFO_CHECK_ICMO_ITH_SCENARIO */
#define ICMOADDLINFO_RETVAL_CHECK_SCENARIO_OK        0 /* scenario cashflows accessible */
#define ICMOADDLINFO_RETVAL_CHECK_SCENARIO_NO        1 /* scenario cashflows not accessible */
#define ICMOADDLINFO_RETVAL_CHECK_SCENARIO_NOT_RUN   2 /* scenario did not run */

/* Index into array returned by ICMOADDLINFO_TR_ATTRIBUTES */
#define ICMOADDLINFO_RETVAL_TR_ATTRIB_MODELING                                0 /* is modeling tranche */
    #define ICMO_T_IS_MODELING_NO               0 /* a real tranche specified in the deal's governing documents */
    #define ICMO_T_IS_MODELING_DEAL_ELEMENT     1 /* a real entity that participates in the deal - paying or receiving cash (but not a tranche) */
    #define ICMO_T_IS_MODELING_EXTERNAL         2 /* a real entity that receives cash from the deal but is not part of the deal */
    #define ICMO_T_IS_MODELING_EXCHANGE         3 /* receives cash from the deal, but ultimately pays it to one of the entities above */
    #define ICMO_T_IS_MODELING_OTHER            4 /* a descriptive item */
#define ICMOADDLINFO_RETVAL_TR_ATTRIB_SUGGESTED_COUPON_BAL_TYPE               1 /* returns suggested coupon balance type to use */
    #define ICMO_SUGGESTED_COUPON_PRINC_BAL     1 /* use ICMOADDLINFO_COUPON_PRINBAL to get coupon */
    #define ICMO_SUGGESTED_COUPON_NOTIONAL_BAL  2 /* can use icmo_tranche_coupons[] to get coupon */
#define ICMOADDLINFO_RETVAL_TR_ATTRIB_IS_OUTSIDE_DEAL                         2 /* flag set by OUTSIDE_OF_DEAL keyword */
#define ICMOADDLINFO_RETVAL_TR_ATTRIB_SUGGESTED_DISC_MARGIN_INDEX             3 /* ith_index suggestion for discount margin calculation */
    #define ICMO_SUGGESTED_DISC_MARGIN_INDEX_NO  -1 /* model does not provide index suggestion for discount margin calculation */
#define ICMOADDLINFO_RETVAL_TR_ATTRIB_DISC_MARGIN_INDEX_LAG_WITH_COUPON_INDEX 4 /* index lag allowed for discount margin calculation */
#define ICMOADDLINFO_RETVAL_TR_ATTRIB_MODEL_CONFIRMED_SCHEDP                  5 /* flag indicate schedp/unschedp is explicitly confirmed by model */
#define ICMOADDLINFO_RETVAL_N_TR_ATTRIB                                       6 /* # of current attributes */

/* Index into array returned by ICMOADDLINFO_GRP_ATTRIBUTES */
#define ICMOADDLINFO_RETVAL_GRP_ATTRIB_SHIFTINT_SCHED   0  /* contains TRUE if group has shiftint schedule */
#define ICMOADDLINFO_RETVAL_N_GRP_ATTRIB (ICMOADDLINFO_RETVAL_GRP_ATTRIB_SHIFTINT_SCHED + 1) /* # of current attributes */

/* Index into array returned by ICMOADDLINFO_DEAL_ATTRIBUTES */
#define ICMOADDLINFO_RETVAL_DEAL_ATTRIB_LOSS_RECOVERY_WATERFALL_INFO   0  /* get information about loss recovery waterfall */
    #define ICMOADDLINFO_RETVAL_DEAL_ATTRIB_PAYS_RECOVERED_UNADVANCED_INTEREST_BEFORE_PRINCIPAL   0
    #define ICMOADDLINFO_RETVAL_DEAL_ATTRIB_PAYS_RECOVERED_UNADVANCED_INTEREST_AFTER_PRINCIPAL    1
#define ICMOADDLINFO_RETVAL_N_DEAL_ATTRIB (ICMOADDLINFO_RETVAL_DEAL_ATTRIB_LOSS_RECOVERY_WATERFALL_INFO + 1) /* # of attributes */

/* Index into array returned by ICMOADDLINFO_N_CDU_POOLS */
#define ICMOADDLINFO_RETVAL_N_CDU_POOLS_TOTAL   0  /* total number of assets in collateral, including paid down */

/* input parameters to ICMOADDLINFO_DEAL_CURRENCY */
#define ICMOADDLINFO_INPVAL_DEAL_CURRENCY_LIST_NONE 0   /*  Do not create list of referenced currencies  */
#define ICMOADDLINFO_INPVAL_DEAL_CURRENCY_LIST_SELF 1   /*  Provide a list of all currencies referenced in the deal itself  */
#define ICMOADDLINFO_INPVAL_DEAL_CURRENCY_LIST_ALL  2   /*  Provide a list of all currencies referenced in the deal and in all underlying deals */

/* input parameters to ICMOADDLINFO_CREDIT_INFO */
#define ICMOADDLINFO_INPVAL_CREDIT_REINVEST         0   /* reinvestment info */
#define ICMOADDLINFO_INPVAL_CREDIT_BALANCE_CAP      1   /*  CREDIT_BALANCE_CAP info*/
#define ICMOADDLINFO_INPVAL_CREDIT_TOTAL_PAYOUT_CAP 2   /*  TOTAL_PAYOUT_CAP info */
#define ICMOADDLINFO_INPVAL_CREDIT_ON_ITEMS         3   /*  provides access to the subset list of credit_on_v_item_nums if not all items applicable to given CREDIT_COVERS type. Could be used only if ICMOADDLINFO_CREDIT_COVERS_WHAT returns ICMOADDLINFO_RETVAL_CREDIT_COVERS_ON_ITEMS_SOME   */

/* input parameters to ICMOADDLINFO_TR_CREDIT_SUPPORT_FORMULA */
#define ICMOADDLINFO_INPVAL_CREDIT_SUPPORT_FORMULA_ORIG          0x01 /* inpval_int: get orig values in formula */
#define ICMOADDLINFO_INPVAL_CREDIT_SUPPORT_FORMULA_NUMERIC       0x02 /* inpval_int: substitute numeric values in formula */
#define ICMOADDLINFO_INPVAL_CREDIT_SUPPORT_FORMULA_EXPAND        0x04 /* inpval_int: expand class definitions in formula */

/* input parameters to ICMOADDLINFO_TR_CREDIT_SUPPORT_INFO and ICMOADDLINFO_TR_UNREALIZED_WRITEDOWN_ACCUM */
#define ICMOADDLINFO_INPVAL_CREDIT_SUPPORT_STANDARD              0x00 /* inpval_int: standard calculation of credit support and related information */
#define ICMOADDLINFO_INPVAL_CREDIT_SUPPORT_GROUP_DIRECTED        0x40 /* inpval_int: set this bit to get group-directed support for senior tranches, if applicable */
#define ICMOADDLINFO_INPVAL_CREDIT_SUPPORT_IGNORE_FULLY_INSURED  0x80 /* inpval_int: set this bit to get "natural" credit support (credit support not including any full wrap).
                                                                         Only for ICMOADDLINFO_TR_UNREALIZED_WRITEDOWN_ACCUM at ICMO_ASOF_LATEST_CDU*/
/* input parameters to ICMOADDLINFO_CALCULATED_COUPON */
#define ICMOADDLINFO_INPVAL_CALCULATED_COUPON_CDU          (-1)  /* use coupon reported in current CDU */
#define ICMOADDLINFO_INPVAL_CALCULATED_COUPON_PRINBAL_CDU  (-2)  /* use coupon reported in current CDU based on principal balance*/
#define ICMO_CALCULATED_CDU_COUPON  ICMOADDLINFO_INPVAL_CALCULATED_COUPON_CDU

/* input parameters to ICMOADDLINFO_GET_PIRML_INFO */
#define ICMOADDLINFO_INPVAL_GET_PIRML_INFO_INIT_PER              1511 /* addl_info_no: return info for applicable during init period */

/* return values (retval_int) for ICMOADDLINFO_CREDIT_INFO: */
#define ICMOADDLINFO_RETVAL_CREDIT_REINVEST_NO               0  /* no credit reinvestment */
#define ICMOADDLINFO_RETVAL_CREDIT_REINVEST_NORMAL           1  /* credit reinvestment using formula or constant value */
#define ICMOADDLINFO_RETVAL_CREDIT_REINVEST_AS_COLLECTION    2  /* credit reinvestment if earned int goes to collection account and is based on collection account reinvestment rate/daycount */

#define ICMOADDLINFO_RETVAL_CREDIT_CAP_NO            0  /* no corresponding cap for credit */
#define ICMOADDLINFO_RETVAL_CREDIT_CAP_YES           1  /* credit has cap for corresponding ICMOADDLINFO_INPVAL_CREDIT_xx */

/* ICMOADDLINFO_RETVAL_CREDIT_COVERS_xx: retval_int_array index values for ICMOADDLINFO_CREDIT_COVERS_WHAT: */
#define ICMOADDLINFO_RETVAL_CREDIT_COVERS_LOSSES             0  /* covers losses, DELINQ, HAZARD, etc. */
#define ICMOADDLINFO_RETVAL_CREDIT_COVERS_INT_SHORTFALLS     1  /* covers interest shortfalls */
#define ICMOADDLINFO_RETVAL_CREDIT_COVERS_MATURITY_BAL       2  /* covers balance at maturity */
#define ICMOADDLINFO_RETVAL_CREDIT_COVERS_MATURITY_INT       3  /* covers interest at maturity */
#define ICMOADDLINFO_RETVAL_CREDIT_COVERS_NS_INT_SHORTFALLS  4  /* covers non-supported interest shortfalls*/
#define ICMOADDLINFO_RETVAL_CREDIT_COVERS_ROUNDINGS          5  /* covers roundings */
#define ICMOADDLINFO_RETVAL_CREDIT_COVERS_RULES              6  /* handled explicitly in payrules */
#define ICMOADDLINFO_RETVAL_CREDIT_COVERS_PRINC_COLLECTION   7  /* covers principal collection */
#define ICMOADDLINFO_RETVAL_CREDIT_COVERS_INT_COLLECTION     8  /* covers interest collection */
#define ICMOADDLINFO_RETVAL_CREDIT_COVERS_MAX                9  /* max value of macros ICMOADDLINFO_RETVAL_CREDIT_COVERS... */

/* ICMOADDLINFO_RETVAL_CREDIT_COVERS_ON_ITEMS_xx: retval_int_array values for ICMOADDLINFO_CREDIT_COVERS_WHAT: */
#define ICMOADDLINFO_RETVAL_CREDIT_COVERS_ON_ITEMS_NONE      0  /* given type of CREDIT_COVERS is not applicable */
#define ICMOADDLINFO_RETVAL_CREDIT_COVERS_ON_ITEMS_YES       1  /* given type of CREDIT_COVERS applies to the elements listed by credit_on_v_item_nums */
#define ICMOADDLINFO_RETVAL_CREDIT_COVERS_ON_ITEMS_SOME      2  /* given type of CREDIT_COVERS applies to the subset of elements listed by credit_on_v_item_nums and could be accessed via ICMOADDLINFO_CREDIT_INFO with ICMOADDLINFO_INPVAL_CREDIT_ON_ITEMS  */

/* return values (retval_int) for ICMOADDLINFO_COLLAT_MODELED_DETAIL: */
#define ICMOADDLINFO_RETVAL_COLLAT_MODELED_STRUCTURED_ONLY      0  /* Collateral consists only of other structured assets  */
#define ICMOADDLINFO_RETVAL_COLLAT_MODELED_ACTUAL               1  /* Full actual collateral provided */
#define ICMOADDLINFO_RETVAL_COLLAT_MODELED_ROLLED_ACTUAL        2  /* Collateral is rolled forward from previous actual collateral */
#define ICMOADDLINFO_RETVAL_COLLAT_MODELED_AGGREGATED_ACTUAL    3  /* Collateral is weighted-averaged replines created from actual collateral  */
#define ICMOADDLINFO_RETVAL_COLLAT_MODELED_CONTRIBUTED_REPLINES 4  /* Collateral is updated replines provided by the servicer/trustee/issuer, either recently or in the past */
#define ICMOADDLINFO_RETVAL_COLLAT_MODELED_DERIVED_REPLINES     5  /* Collateral is replines created from strats in the prospectus or investor report  */
#define ICMOADDLINFO_RETVAL_COLLAT_MODELED_CLOSING_REPLINES     6  /* Collateral is prospectus collateral or other collateral rolled from deal closing */
#define ICMOADDLINFO_RETVAL_COLLAT_MODELED_UPDATED_PAYM_SCHED   7  /* Collateral modeled as a payment schedule. Updated payment schedules are provided. */
#define ICMOADDLINFO_RETVAL_COLLAT_MODELED_ORIG_PAYM_SCHED      8  /* Collateral modeled as a payment schedule rolled from deal closing */
#define ICMOADDLINFO_RETVAL_COLLAT_MODELED_NA                   9  /* Information not available */

/* Elements of retval_dbl_array for ICMOADDLINFO_TR_PARI_PASSU_TRANCHES, ICMOADDLINFO_TR_SENIOR_TRANCHES, and ICMOADDLINFO_TR_SUPPORTING_TRANCHES_INFO. */
#define ICMOADDLINFO_RETVAL_STRUCTURAL_BALANCE_ORIG               0
#define ICMOADDLINFO_RETVAL_STRUCTURAL_BALANCE_CURR               1
#define ICMOADDLINFO_RETVAL_STRUCTURAL_BALANCE_NOTIONAL_ORIG      2  /* notional part of corresponding orig balance */
#define ICMOADDLINFO_RETVAL_STRUCTURAL_BALANCE_NOTIONAL_CURR      3  /* notional part of corresponding curr balance */
#define ICMOADDLINFO_RETVAL_STRUCTURAL_BALANCE_SHORTFALL_CURR     4  /* total curr shortfall associated with corresponding curr balance */
#define ICMOADDLINFO_RETVAL_STRUCTURAL_BALANCE_UNSUPPORTED_ORIG   5  /* balance explicitly excluded from corresponding orig balance */
#define ICMOADDLINFO_RETVAL_STRUCTURAL_BALANCE_UNSUPPORTED_CURR   6  /* balance explicitly excluded from corresponding curr balance */
#define ICMOADDLINFO_RETVAL_N_STRUCTURAL_BALANCES                 7

/* return values (retval_int) for ICMOADDLINFO_TR_PAID_DOWN_WITH_BAL */
#define ICMOADDLINFO_RETVAL_TR_PAID_DOWN_WITH_BAL_NO         0 /* tr does not pay down with balance */
#define ICMOADDLINFO_RETVAL_TR_PAID_DOWN_WITH_BAL_YES        1 /* tr pay down with balance */
#define ICMOADDLINFO_RETVAL_TR_PAID_DOWN_WITH_BAL_EXCEPT_RPL 2 /* tr pay down with balance except when forecasting Recoveries of Prior Losses */

/* SET_PI_xx:  Options for ICMOADDLINFO_SET_PI_INFO to override POOL_INFO values corresponding to: */
#define SET_PI_GROSSRATE               0 /* Override gross rate value */
#define SET_PI_CURPMT                  1 /* Override current payment value/formula */
#define SET_PI_AMORT                   2 /* Override amortization characteristics */
#define SET_PI_ARM_INDEX               3 /* Override arm index for ARM and NEXTARMs */
#define SET_PI_GROSSMARGIN             4 /* Override gross margin value for ARM and NEXTARMs */
#define SET_PI_ARM_RESETCAP            5 /* Override arm RESETCAP value for ARM and NEXTARMs */
#define SET_PI_ARM_RESETFLR            6 /* Override arm RESETFLR value for ARM and NEXTARMs */
#define SET_PI_ARM_LIFECAP             7 /* Override arm LIFECAP  value for ARM and NEXTARMs */
#define SET_PI_ARM_LIFEFLR             8 /* Override arm LIFEFLR  value for ARM and NEXTARMs */
#define SET_PI_ARM_INIT_RESETCAP       9 /* Override arm INIT_RESETCAP       value for ARM and NEXTARMs */
#define SET_PI_ARM_NEXT_INT_RESET_PER  10 /* Override arm NEXT_INT_RESET_PER  value for ARM */
#define SET_PI_ARM_NEXT_PAYM_RESET_PER 11 /* Override arm NEXT_PAYM_RESET_PER value for ARM */
#define SET_PI_ARM_MAX_NEGAM           12 /* Override arm MAX_NEGAM */
#define SET_PI_STL_NMON_TO_STATUS      13 /* Override StudentLoan NMON_TO_STATUS info */
#define SET_PI_STL_BENEFIT_PROGRAM     14 /* Override StudentLoan BENEFIT_PROGRAM info */
#define SET_PI_STL_BP_ELIGIBILITY_FRAC 15 /* Override StudentLoan BENEFIT Eligibility Fracs */
#define SET_PI_SERVRATE                16 /* Override servfee rate value */
#define SET_PI_NON_PERFORMING          17 /* Override non-performing flag  */
#define SET_PI_STL_STATUS_TO_REPAY     18 /* Override StudentLoan STATUS to REPAY status */
#define SET_PI_FORBEARANCE_AMT         19 /* Override forbearance amount */
#define SET_PI_REMTERM                 20 /* Override remterm (for level payment amortization loan) */
#define SET_PI_WALA                    21 /* Override wala (for level payment amortization loan) */

/* GET_PI_xx:  Options for ICMOADDLINFO_GET_PI_INFO to get pool/loan/asset related values corresponding to: */
#define GET_PI_CURRENCY               0 /* Asset currency if specified, otherwise deal currency */
#define GET_PI_CUSIP                  1 /* retval_str is CUSIP or NULL */
#define GET_PI_IS_PAID_DOWN           2 /* retval_int is TRUE if asset is paid down */
#define GET_PI_NEXT_PAYDATE           3 /* Asset's next paydate. */
#define GET_PI_REREMIC_ASSETBACK_TYPE 4 /* if asset represents re-remic deal and PI_REREMIC_CATEGORY=ICMODEALCAT_WHOLE_LOAN, retval_int is ICMOASSETBACK_xx or ICMOADDLINFO_RETVAL_INT_NA */
#define GET_PI_REREMIC_CATEGORY       5 /* if asset represents re-remic deal, retval_int is ICMODEALCAT_xx or ICMOADDLINFO_RETVAL_INT_NA   */
#define GET_PI_STATED_MATURITY        6 /* retval_long is stated maturity date, if available */
#define GET_PI_GROSSRATE              7 /* retval_dbl is WAC, retval_str WAC formula in not NULL */
#define GET_PI_ASSUMED_DELINQ_NMOS    8 /* retval_int is TRUE if loanstat 90plus/180plus contains assumed n_mos_delinq */
#define GET_PI_FORBEARANCE_AMT        9 /* retval_dbl is current amount of forbearance on an asset */
#define GET_PI_FORBEARANCE_TREATMENT 10 /* retval_int is forbearance treatement method */
#define GET_PI_SERVRATE              11 /* retval_dbl is servfee rate, retval_str servfee formula if not NULL */
#define GET_PI_SPECIAL_SERVRATE      12 /* retval_ptr is special servfee rate, retval_str servfee formula if not NULL */
#define GET_PI_CUR_ARMP              13 /* retval_ptr is pointing to the current ARM_INFO structure for ARM, NEXTSTAGE or NEXTARM. NULL if not ARM*/
#define GET_PI_AGE_INFO              14 /* info how asset age is reported  */
#define GET_PI_LOSS_AMT              15 /* retval_dbl is an amount of accumulated loss on an asset */
#define GET_PI_ORIGTERM              16 /* retval_int is orig term of an asset */
#define GET_PI_TBA                   17 /* info about TBA loan from reinvestment collateral*/
#define GET_PI_STL_NMON_TO_STATUS    18 /* get StudentLoan NMON_TO_STATUS info */
#define GET_PI_AMORT_IO_AMT          19 /* get amort IO amt */
#define GET_PI_UNMODIFIED           128 /* modifier used to get UNMODIFIED info if available */
#define GET_PI_ARM_PREMOD           256 /* modifier used to get ARM_PREMOD info if available */

/* For GET_PI_STL_NMON_TO_STATUS/SET_PI_STL_NMON_TO_STATUS */
#define PI_STL_NMON_TO_STATUS_INSTANT 1001 /* used by GET_PI_STL_NMON_TO_STATUS/SET_PI_STL_NMON_TO_STATUS for status change before 1st forecast period */

/* SET_TR_xx:  Options for ICMOADDLINFO_SET_TR_INFO to override some tranche info */
#define SET_TR_CUSIP                   1 /* override tranche cusip */
#define SET_TR_ISIN                    2 /* override tranche isin */
#define SET_TR_BBGID                   3 /* override tranche Bloomberg ID */
#define SET_TR_BBGTK                   4 /* override tranche Bloomberg Ticker */
#define SET_TR_CSI                     5 /* override tranche Chinese Security Identification */

/* GET_TR_xx:  Options for ICMOADDLINFO_GET_TR_INFO to get some tranche info */
#define GET_TR_CSI                     1 /* get tr Chinese Security Identification */

/* SET_ADDL_GROUP_xx:  Options for ICMOADDLINFO_SET_ADDL_GROUP  */
#define SET_ADDL_GROUP_REMOVE          0   /* remove all previously set addl subset group */
#define SET_ADDL_GROUP_NEW             1   /* setup new addl subset group */
#define SET_ADDL_GROUP_ADD_ASSETS      2   /* add assets to the previously set addl subset group */

/* return values (retval_int) for ICMOADDLINFO_GET_PI_INFO -> GET_PI_AGE_INFO  */
#define ICMOADDLINFO_RETVAL_PI_AGE_REPORTED  0  /* asset age is reported */
#define ICMOADDLINFO_RETVAL_PI_AGE_UNKNOWN   1  /* asset age is unknown and reported as SEASONED (30 months) */

/* return values (retval_int ) for ICMOADDLINFO_GET_PI_INFO -> GET_PI_TBA */
#define ICMOADDLINFO_RETVAL_PI_TBA_NO             0  /* not a TBA loan */
#define ICMOADDLINFO_RETVAL_PI_TBA_FLOAT_MATURITY 1  /* TBA loan maturuty term provided in form of nmonths till, loan maturity will depend on reinvestment period  */
#define ICMOADDLINFO_RETVAL_PI_TBA_FIXED_MATURITY 2  /* TBA loan maturuty term provided in form of date, loan will matur on the same date independent of reinvestment period */

/* return values (retval_int) for ICMOADDLINFO_TR_CREDIT_SUPPORT_INFO */
#define ICMOADDLINFO_RETVAL_CREDIT_SUPPORT_REPORTING_FULL      0
#define ICMOADDLINFO_RETVAL_CREDIT_SUPPORT_REPORTING_LIMITED   1
#define ICMOADDLINFO_RETVAL_CREDIT_SUPPORT_REPORTING_NONE      2

/* return values (retval_long) for ICMOADDLINFO_TR_CREDIT_SUPPORT_INFO */
#define ICMOADDLINFO_RETVAL_CREDIT_SUPPORT_FORMULA_OK          0    /* formula returned in retval_str is accurate */
#define ICMOADDLINFO_RETVAL_CREDIT_SUPPORT_FORMULA_APPROX      1    /* formula returned in retval_str is an approximation */

/* GET_PI_OVRDCF_xx:  Options for ICMOADDLINFO_OVRD_ASSET_CF_INFO to  */
#define GET_PI_OVRDCF_STATUS  0  /* Returns ICMOOVRD_ASSET_CF_STATUS_xx in retval_int*/

/* input parameters to ICMOADDLINFO_GET_HPI_INFO */
#define GET_HPI_INDEX         0   /* retval_dbl contains House Price Index value corresponding to given region for the inputted date */
#define GET_HPI_REGION_TYPE   1   /* retval_str contains name of region type.  Possibilities include CMSA, CBSA, etc. */
#define GET_HPI_FREQ          2   /* retval_int contains the frequence of the reported data.  12 == monthly, 4 = quarterly, 2 = semi-annual, 1 = yearly */
#define GET_HPI_DATA_SOURCE   3   /* retval_str contains datasource of HPI */
#define GET_HPI_COUNTRY       4   /* retval_str contains relevant country of HPI.  Uses 3 character country codes found in country.idl */
#define GET_HPI_ASSET_CLASSES 5   /* retval_str contains relevant asset class of HPI.  Multiple asset classes are space deliminted.  Uses values found in assetinf.idl. */

/* GET_GROUP_xx:  Options for ICMOADDLINFO_GET_GROUP_INFO to get group attributes corresponding to: */
#define GET_GROUP_SUBGROUPS             1 /* retval_int_array is list of groupnos of subgroups of specified group */
#define GET_GROUP_XRS_IO_METHOD         2 /* retval_int is one of the values ICMO_XRS_IO_GROUP_METHOD_xx */
#define GET_GROUP_RELATED_GROUND_GROUPS 3 /* retval_int_array is list of groupnos of related ground groups of specified group */
#define GET_GROUP_COUPON_METHOD         4 /* retval_int is one of ICMO_GROUP_COUPON_METHOD_xx */

/* ICMO_GROUP_COUPON_METHOD_xx: values for GET_GROUP_COUPON_METHOD */
#define ICMO_GROUP_COUPON_METHOD_USE_CURRENT     0  /* unmodified coupon is not referenced in the deal model */
#define ICMO_GROUP_COUPON_METHOD_USE_UNMODIFIED  1  /* unmodified coupon is referenced in the deal model */

/* ICMO_XRS_IO_GROUP_METHOD_xx: values for GET_GROUP_XRS_IO_METHOD */
#define ICMO_XRS_IO_GROUP_METHOD_USE_CURRENT_NETRATE     0
#define ICMO_XRS_IO_GROUP_METHOD_USE_UNMODIFIED_NETRATE  1

/* return values (retval_int) for ICMO_DATA_LOAN_DELINQ_METHOD */
#define ICMOADDLINFO_RETVAL_DELINQ_METHOD_UNKNOWN      0  /* unknown */
#define ICMOADDLINFO_RETVAL_DELINQ_METHOD_OTS          1  /* describe OTS method */
#define ICMOADDLINFO_RETVAL_DELINQ_METHOD_MBA          2  /* describe MBA method */

/* input parameters to ICMOADDLINFO_PIBAL_CONTRIB_FRAC, passed in third arg of icmo_addl_info  */
#define ICMOADDLINFO_INPVAL_PIBAL_CONTRIB_FRAC         0  /* normal PIBAL_CONTRIB_FRAC */
#define ICMOADDLINFO_INPVAL_PIBAL_PARTICPT_FRAC        1  /* modified PIBAL_CONTRIB_FRAC */
#define ICMOADDLINFO_INPVAL_PIBAL_CONTRIB_FRAC_TO_TOP_LEVEL 2 /* securitized fraction contributing to top level deal */


/* ICMOADDLINFO_INPVAL_PIBAL_CONTROL_xx: input parameters to control calculation of ICMOADDLINFO_PIBAL_CONTRIB_FRAC, passed
   in inpval_int.  Some of the values can be bitwise-ORed to control multiple settings. */
#define ICMOADDLINFO_INPVAL_PIBAL_CONTROL_INCLUDE_IO         0x04  /* include notional balance for IO assets */
#define ICMOADDLINFO_INPVAL_PIBAL_CONTROL_INCLUDE_IO_CONDITIONALLY   0x08  /* include notional balance for IO asset only if deal has explicit
                                                                              INCLUDE_NOTIONAL_IN_SUPPORT_BASIS setting, or block has explicit
                                                                              INCLUDE_IN_CREDSUPP declaration. */
#define ICMOADDLINFO_INPVAL_PIBAL_CONTROL_EXCLUDE_PIKBAL     0x10  /* exclude capitalized interest shortfalls (PIK) */
/* deprecated name */
#define ICMOADDLINFO_INPVAL_PIBAL_INCLUDE_IO ICMOADDLINFO_INPVAL_PIBAL_CONTROL_INCLUDE_IO  DEPRECATED

/* return elements of retval_dbl_array[] for ICMOADDLINFO_PIBAL_CONTRIB_FRAC
   and ICMOADDLINFO_INPVAL_PIBAL_CONTRIB_FRAC_TO_TOP_LEVEL                   */
#define ICMOADDLINFO_RETVAL_COLLBAL_CONTRIB_FRAC_TO_TOP_PRIN       0  /* collat principal contrib frac to top deal */
#define ICMOADDLINFO_RETVAL_COLLBAL_CONTRIB_FRAC_TO_TOP_INT        1  /* collat notional contrib frac to top deal */
#define ICMOADDLINFO_RETVAL_COLLBAL_CONTRIB_FRAC_TO_TOP_PRIN_TDC   2  /* collat principal contrib frac to top deal (include currency exchange from currency of deal to top deal) */
#define ICMOADDLINFO_RETVAL_COLLBAL_CONTRIB_FRAC_TO_TOP_INT_TDC    3  /* collat notional contrib frac to top deal (include currency exchange from currency of deal to top deal) */

/* input parameters to ICMOADDLINFO_GET_LOAN_PRODUCT_TYPE */
#define ICMOADDLINFO_INPVAL_PT_FULL                    0  /* full product type */
#define ICMOADDLINFO_INPVAL_PT_TERM                    1  /* TERM    component */
#define ICMOADDLINFO_INPVAL_PT_FIXFLT                  2  /* FIXFLT  component */
#define ICMOADDLINFO_INPVAL_PT_BALLOON                 3  /* BALLOON component */
#define ICMOADDLINFO_INPVAL_PT_IOTERM                  4  /* IOTERM  component */
#define ICMOADDLINFO_INPVAL_PT_HELOC                   5  /* HELOC   component */
#define ICMOADDLINFO_INPVAL_PT_NEGAM                   6  /* NEGAM   component */

/* input parameters to ICMOADDLINFO_GET_LOANDATA */
#define ICMOADDLINFO_INPVAL_GET_LOANDATA_REQUIRED   0  /* get list or single required LOANDATA for the deal/pip */
#define ICMOADDLINFO_INPVAL_GET_LOANDATA_ALL        1  /* get list or single LOANDATA out of all ( required and/or provided) for the deal/pip */
#define ICMOADDLINFO_INPVAL_GET_LOANDATA_OR_CREATE  2  /* get single LOANDATA if available, or add new LOANDATA name/structure if not found */

/* input parameters to ICMOADDLINFO_TR_BLOCKS */
#define ICMOADDLINFO_INPVAL_TR_BLOCKS_CURRENT       0  /* get block info corresponding to current CDU - same functionality as icmo_tranche_blocks() */
#define ICMOADDLINFO_INPVAL_TR_BLOCKS_ORIG_STAGES   1  /* get block info reflecting original status for all fields associated with  BLKSTAGE_xx, for all other fields - current status */
#define ICMOADDLINFO_INPVAL_TR_BLOCKS_IRR           2  /* returns linked list of IRR's associated blocks. */

/* input parameters to ICMOADDLINFO_GET_PIHIST_INFO */
#define ICMOADDLINFO_INPVAL_PIHIST_INFO_LIST   1 /* get infoname list */
#define ICMOADDLINFO_INPVAL_PIHIST_INFO_DATA   2 /* get datavals */
#define ICMOADDLINFO_INPVAL_PIHIST_INFO_FREE   3 /* free memory */

/* input parameters to ICMOADDLINFO_TR_START_INFO */
#define ICMOADDLINFO_INPVAL_TR_BAL             1 /* tranche balance */
#define ICMOADDLINFO_INPVAL_TR_PY_BASIS        2 /* tranche PY basis */
#define ICMOADDLINFO_INPVAL_TR_ORIGBAL         3 /* tranche original bal corresponding to starting bal */
#define ICMOADDLINFO_INPVAL_TR_ORIG_PY_BASIS   4 /* tranche original PY basis corresponding to starting bal */

/* input parameters to ICMOADDLINFO_IS_IN_CLASS */
#define ICMOADDLINFO_INPVAL_BLOCK_IS_IN_CLASS  1 /* check block in class */
#define ICMOADDLINFO_INPVAL_CLASS_IS_IN_CLASS  2 /* check class in class */

/* input/output for ICMOADDLINFO_GET_FORB_TREATMENT/ICMOADDLINFO_SET_FORB_TREATMENT */
#define ICMO_FORB_TREATMENT_DEFAULT     0  /* unknown, treat as non-performing balance by default */
#define ICMO_FORB_TREATMENT_AS_LOSS     1  /* treated as realized loss */
#define ICMO_FORB_TREATMENT_AS_NONPBAL  2  /* treated as non-performing balance */

/* input for ICMOADDLINFO_SET_REPAYMDR_BASIS */
#define ICMO_REPAYMDR_BASIS_ORIGBAL     0  /* use loan origbal as REPAYMDR basis */
#define ICMO_REPAYMDR_BASIS_STARTBAL    1  /* use loan forecast start bal as REPAYMDR basis */

/* ICMOADDLINFO_RETVAL_ASSET_REINV_xxx: retval for ICMOADDLINFO_DEAL_HAS_ASSET_REINV */
#define ICMOADDLINFO_RETVAL_ASSET_REINV_RECOLLAT   0x01 /* has asset reinv by RECOLLAT rules */
#define ICMOADDLINFO_RETVAL_ASSET_REINV_BUY_COLLAT 0x02 /* has asset reinv by BUY_COLLAT rules */

/*  ICMOADDLINFO_INPVAL_USE_MARKET_VALUE_xx: input values for ICMOADDLINFO_TR_SUPPORT_BASIS_MARKET_VALUE */
#define  ICMOADDLINFO_INPVAL_USE_MARKET_VALUE_FOR_DEFAULTED       0x0100     /* use market value for defaulted assets */
#define  ICMOADDLINFO_INPVAL_USE_MARKET_VALUE_FOR_ALL             0x0200     /* use market value for all assets */
#define  ICMOADDLINFO_INPVAL_USE_MARKET_VALUE_ZERO_FOR_DEFAULTED  0x0400     /* use value 0 for defaulted assets */

/* Indexes into retval_dbl_array for ICMOADDLINFO_TR_SUPPORT_BASIS_MARKET_VALUE */
#define ICMOADDLINFO_RETVAL_SUPPORT_BASIS_MARKET_VALUE_FACE_SOUGHT  0 /* face value of assets for which market value was sought */
#define ICMOADDLINFO_RETVAL_SUPPORT_BASIS_MARKET_VALUE_FACE_FOUND   1 /* face value of assets for which market value was found  */
#define ICMOADDLINFO_RETVAL_SUPPORT_BASIS_MARKET_VALUE_CASH_BASIS   2 /* support basis calculated on a cash basis, i.e., exluding excess capacity, etc. */
#define ICMOADDLINFO_RETVAL_SUPPORT_BASIS_MARKET_VALUE_PAR_BASIS    3 /* support basis calculated on a par basis */
#define ICMOADDLINFO_RETVAL_SUPPORT_BASIS_MARKET_VALUE_N_VALUES     4

/* input parameters to ICMOADDLINFO_GET_OPTREDEEM_INFO */
#define ICMOADDLINFO_INPVAL_OPTREDEEM_INFO_WHEN_STATUS 1  /* get status of redeem conditions */

/* input parameters to ICMOADDLINFO_SET_HEDGE_INFO */
#define ICMOADDLINFO_INPVAL_HEDGE_LEG_TERM_PMT 1 /* override termination pmt of a hedge leg */

/* return values (retval_int) for ICMOADDLINFO_TR_ALTIDS in single tranche mode  ( addl_info_no  >= 0 )*/
#define ICMOADDLINFO_RETVAL_TR_ALTIDS_FOUND         -1  /* info for given single tranche found and provided in retval_ptr */
#define ICMOADDLINFO_RETVAL_TR_ALTIDS_NOT_FOUND      0  /* info for given single tranche not found  */

/* ICMO_DATA_AVAIL_xx: choice of data availability for ICMOADDLINFO_DATA_AVAILABILITY */
#define ICMO_DATA_LOAN_DELINQ         1  /* delinq 30, 60, 90+  */
#define ICMO_DATA_LOAN_REO            2  /* REO info  */
#define ICMO_DATA_LOAN_FC             3  /* Foreclosure info  */
#define ICMO_DATA_LOAN_BR             4  /* Bankruptcy info */
#define ICMO_DATA_LOAN_REPURCH        5  /* Repurchase info */
#define ICMO_DATA_LOAN_LOSS           6  /* Loss info */
#define ICMO_DATA_LOAN_DELINQ_METHOD  7  /* OTS or MBA Method used for delinq months */
#define ICMO_DATA_AGGREGATE_INFO     64  /* modifier for get AGGREGATE data availability */

/* ICMO_ACCOUNT_xx: collection account info */
#define ICMO_ACCOUNT_INT              1  /* interest collection account */
#define ICMO_ACCOUNT_PRN              2  /* principal collection account */

/* ICMOTR_REPORTED_xxx: trustee reported tr info */
#define ICMOTR_REPORTED_INTPMT         0  /* reported int pmt */
#define ICMOTR_REPORTED_PRNPMT         1  /* reported prin pmt */
#define ICMOTR_REPORTED_WRITEDOWN      2  /* reported writedown amt */
#define ICMOTR_REPORTED_INTSHORT       3  /* reported int shortall */
#define ICMOTR_REPORTED_COUPONCAPSHORT 4  /* reported couponcap shortfall */
#define ICMOTR_N_REPORTED              5  /* # of ICMOTR_REPORTED_xxx */

/* IDXFILE_NAME_xx: input for ICMOADDLINFO_IDXFILE_NAME */
#define IDXFILE_NAME_PARSED    0 /* want actual idxfile parsed */
#define IDXFILE_NAME_ICMOMISC  1 /* want idxfile specified in icmomiscp */
#define IDXFILE_NAME_CDI       2 /* want idxfile specified in CDI */
#define IDXFILE_NAME_DEFAULT   3 /* want default idxfile based on CDI type */

/* IDXFILE_USE_xx: output for ICMOADDLINFO_IDXFILE_NAME (values of icmo_addl_infop->retval_int)*/
#define IDXFILE_USE_IDX                 0 /* use external IDX file if needed */
#define IDXFILE_USE_INTERNAL_IDX_INFO   1 /* use deal's INTERNAL_IDX_INFO */


/* ICMO_ASSET_PIK_INFO: Asset PIK information returned by ICMOADDLINFO_ASSET_PIK_INFO in retval_ptr */

typedef struct  _ICMO_ASSET_PIK_INFO {
    double pik_rate ;               /* pik rate as dbl */
    char  *pik_expr ;               /* pik formula     */
    char   pik_daycount_method ;    /* pik daycount method as ICMO_DAYCOUNT_xx */
    char   pik_businessday_method ; /* pik businessday method as ICMO_BUSINESSDAY_xx */
    double pik_start_bal ;          /* pik starting balance (from last CDU) */
} ICMO_ASSET_PIK_INFO ;


/* ICMO_TR_RATING_INFO: Tranche additional rating information returned by ICMOADDLINFO_RATING_CURR in retvar_ptr_array */

typedef struct  _ICMO_TR_RATING_INFO {
    char     *tri_curr ;         /* Current rating as of CDU creation date */
    char     *tri_asof_paydate ; /* Rating as of CDU paydate  */
    YyyyMmDd tri_curr_date ;     /* Date corresponding to Current rating tri_curr */
} ICMO_TR_RATING_INFO ;


/* ICMO_TR_ALTID_INFO: Tranche alternative IDs returned by ICMOADDLINFO_TR_ALTIDS in retval_ptr or in retvar_ptr_array */

typedef struct  _ICMO_TR_ALTID_INFO {
    char *tr_altid_bbgid ;   /* Bloomberg ID */
    char *tr_altid_bbgtk ;   /* Bloomberg Ticker */
    char *tr_altid_bbgdeal ; /* Bloomberg Deal name */
} ICMO_TR_ALTID_INFO ;

/* PARSED_xx: return values in case of ICMOADDLINFO_GRP/TR_PARSED_INFO
               useful for single_tranche_mode/partial CDU */
#define PARSED_FULLY          0  /* Tranche/grp fully parsed - good info and good for running CF */
#define PARSED_INFO_ONLY      1  /* Tranche/grp parsed descriptive info only -not good for running CF */
#define PARSED_STALE          2  /* Tranche/grp parsed with unreliable/old info and not good for running CF */

/* ICMO_ASOF_xx: icmo_addl_infop->inpval_int values for ICMOADDLINFO_TR_WRITEDOWN_ACCUM, */
/*     ICMOADDLINFO_TR_INTSHORT_ACCUM, ICMOADDLINFO_TR_COUPONCAPSHORT_ACCUM and */
/*     ICMOADDLINFO_TR_CREDIT_SUPPORT_INFO */
#define ICMO_ASOF_ISSUE       0x01  /* Information as of deal issue. */
#define ICMO_ASOF_BASE_CDU    0x02  /* Information as of base CDU */
#define ICMO_ASOF_LATEST_CDU  0x04  /* Information as of latest CDU */
#define ICMO_ASOF_PERIOD      0x10  /* Information for current cashflow period */

#define ICMO_KEEP_CASE        1  /* icmo_addl_infop->inpval_int value for ICMOADDLINFO_COLLAT_TYPE*/

/* ICMO_EXPRESSION_xx: standard formula types as returned by icmo_addl_info for ICMOADDLINFO_ANALYZE_EXPR */
#define ICMO_EXPRESSION_UNKNOWN                0
#define ICMO_EXPRESSION_LOANYM_MOS_GROSS_INT   1
#define ICMO_EXPRESSION_LOANYM_NOT_MODELED     2

/* CLUSTER:  controls clustering; used in icmo_cluster_pools */

#define ICMOCLUSTER_DEFAULT   0   /* standard Intex-defined clustering */
#define ICMOCLUSTER_EXACT     1   /* cluster only when the relevant attributes are identical */
#define ICMOCLUSTER_NEVER     2   /* Never cluster pools when the relevant attribute is present */
#define ICMOCLUSTER_MAX       2   /* Maximum value of ICMOCLUSTER_xx flags */

typedef struct _CLUSTER {
    int cluster_ngrossrates ;      /* # of net rate groupings */
    int cluster_nremterms ;        /* # of remain terms groupings */
    int cluster_nwalas    ;        /* # of wala columns */
    int cluster_nnetrates ;        /* # of netrate columns */
    double *cluster_vgrossrates ;  /* NULL, or explicit WAC grid vals */
    int *cluster_vremterms ;       /* NULL, or explicit WAM grid vals */
    int cluster_with_details ;     /* keeps details when clustering */
    int cluster_arm_reset_detail ; /* keep diff reset month loans in separate clusters */
    int cluster_n_arm_margins ;    /* # of arm margin groupings, active only if cluster_arm_reset_detail is set */
    int cluster_pct_detail ;       /* keep separate pools with diff PO/IO pct */
    int cluster_with_amort_sched ; /* use amort schedule calculated with original pools (for fixed rate pools only) */
    int cluster_draw ;             /* ICMOCLUSTER_xx: ICMOCLUSTER_EXACT means cluster only if loanattr_draw_term,
                                      pi_age_since_issue, piserv_expr_maxdraw and piserv_draw_lockout_toptkn are
                                      identical.  The latter two are usually NULL.  ICMOCLUSTER_DEFAULT means cluster
                                      only if piserv_expr_maxdraw and piserv_draw_lockout_toptkn are identical.  */
    int cluster_prepaypenalty ;    /* ICMOCLUSTER_xx: ICMOCLUSTER_EXACT means cluster only if loan age and all
                                      surviving prepay penalty provisions are identical.  ICMOCLUSTER_DEFAULT allows for weighted
                                      averaging of penalty point vectors, and also averaging of loans with the same
                                      yield maintenance formula but possibly different ages or yield maintenance periods. */
    int cluster_dont_separate_paiddown ;  /* if TRUE, do not separate paid-down from not-paid-down pools during clustering */
    long ((CALLBK_FCN_PREFIX *cluster_user_cftype_fcn)(Args_cluster_user_cftype_fcn));
                                  /* user callback fcn to override default cftype in clustering */
    void ((CALLBK_FCN_PREFIX *cluster_user_fcn)(Args_cluster_user_fcn));
                                  /* user clustering accum function UFCN() */
    void ((CALLBK_FCN_PREFIX *cluster_user_free_fcn)(Args_cluster_user_free_fcn));
                                  /* user function to clean up structures allocated in accum function */
    }  CLUSTER ;


/* ICMO_DEALPORTSTR_DECODE: holds info about why deal is at "PORTFOLIO" level of accuracy.
                        is anchored by icmo_deal_portfolio_str_decode */

typedef struct  {
    char *dealportstr_next ;          /* to next piece of info, or NULL */
    int   dealportstr_type ;            /* ICMO_DEALPORTSTR_xx: type of info */
    char *dealportstr_addl_info ;     /* if nonNULL, to string with more info */
    char *dealportstr_description ;   /* if nonNULL, to string describing meaning of portfolio string */
    } ICMO_DEALPORTSTR_DECODE ;

#define ICMO_DEALPORTSTR_UNDEFINED          0  /* Some deficiencies exist in the model */
#define ICMO_DEALPORTSTR_CONFIRMED          1  /* Prospectus contained no information to tie out pricing cashflows */
#define ICMO_DEALPORTSTR_TIED_AT_PRICING    2  /* Prospectus contained information to tie out pricing cashflows, but some structuring detail may not be modeled */
#define ICMO_DEALPORTSTR_LOAN_LEVEL         3  /* Collateral data is at a loan level */
#define ICMO_DEALPORTSTR_WAVG_POOL          4  /* Collateral data is collapsed into a weighted-average pool due to servicer restrictions */
#define ICMO_DEALPORTSTR_ASSUMED_POOL       5  /* Loan level collateral data is not available, remittance info used to roll forward assumed collateral described in prospectus */
#define ICMO_DEALPORTSTR_PLUG_POOL          6  /* Loan level collateral data is not available, updated replines are provided */
#define ICMO_DEALPORTSTR_ORIG_WAC           7  /* No current WAC information is available, closing WAC data is presented */
#define ICMO_DEALPORTSTR_UPDATED_WAC        8  /* Updated WAC information is provided */
#define ICMO_DEALPORTSTR_CALCULATED_WAC     9  /* Current WAC information is calculated based on remittance info */
#define ICMO_DEALPORTSTR_ORIG_WAM          10  /* No current WAM information is available, the WAM presented is rolled forward from closing data */
#define ICMO_DEALPORTSTR_UPDATED_WAM       11  /* Updated WAM information is provided */
#define ICMO_DEALPORTSTR_ORIG_ECE          12  /* Current Credit Enhancement data is not available, original level of Credit Enhancement is used */
#define ICMO_DEALPORTSTR_UPDATED_ECE       13  /* Servicer is providing current Credit Enhancement information */
#define ICMO_DEALPORTSTR_REPORTED_TFAC     14  /* Reported tranche factors used to approximate unavailable remittance info */
#define ICMO_DEALPORTSTR_CALCULATED_TFAC   15  /* Current tranche factors are calculated based on remittance info */
#define ICMO_DEALPORTSTR_UPDATED_MARGIN    16  /* Updated ARM margin is provided */
#define ICMO_DEALPORTSTR_UPDATED_NEXTRESET 17  /* Updated ARM, months to next interest reset, is provided */
#define ICMO_DEALPORTSTR_UPDATED_NEXTPMTRESET 18 /* Updated ARM, months to next payment reset, is provided */
#define ICMO_DEALPORTSTR_UPDATED_RESETCAP  19  /* Updated ARM reset cap is provided */
#define ICMO_DEALPORTSTR_UPDATED_LIFECAP   20  /* Updated ARM life cap is provided */
#define ICMO_DEALPORTSTR_UPDATED_LIFEFLR   21  /* Updated ARM life floor is provided */
#define ICMO_DEALPORTSTR_COMMENT           22
#define ICMO_DEALPORTSTR_DELINQ_INC_FC     23  /* Foreclosed data is included in the 90+ day delinquency field */
#define ICMO_DEALPORTSTR_DELINQ_INC_REO    24  /* REO data is included in the 90+ day delinquency field */
#define ICMO_DEALPORTSTR_DELINQ_INC_BANKR  25  /* Bankruptcy data is included in the 90+ day delinquency field */
#define ICMO_DEALPORTSTR_UPDATED_BALLOON   26  /* Updated balloon term information is provided */
#define ICMO_DEALPORTSTR_INFO_ONLY         27  /* Model is intended for data purposes only and not for cashflow generation */
#define ICMO_DEALPORTSTR_GENERIC_YM        28  /* Model assumes yield maintenance logic consistent with the underwriter's previous issues */
#define ICMO_DEALPORTSTR_TRIGGERS_MODELED  29  /* All loss and delinquency triggers are incorporated into the model, but some structuring detail may not be modeled */
#define ICMO_DEALPORTSTR_RED_PROSPECTUS    30  /* This deal has been modeled from the Red Prospectus */
#define ICMO_DEALPORTSTR_ORIG_LEASE_SCHED  31  /* Updated lease schedule is not available, remittance info used to roll forward assumed schedule" */
#define ICMO_DEALPORTSTR_UPDATED_LEASE_SCHED  32 /* Updated lease schedules are provided */
#define ICMO_DEALPORTSTR_ASSET_LEVEL          33 /* Collateral data is at an asset level, but deal may not be to fullest trading quality */
#define ICMO_DEALPORTSTR_REPORTED_COLLATBAL   34 /* Collateral balances are reported either through loan level data or remittance report */
#define ICMO_DEALPORTSTR_CALCULATED_COLLATBAL 35 /* Collateral balances are derived from tranche balances */
#define ICMO_DEALPORTSTR_UPDATED_SCHED        36 /* Updated collateral payment schedules are provided */
#define ICMO_DEALPORTSTR_CDO_PORTFOLIO_COLLAT 37 /* Portfolio collateral from trustee reports */
#define ICMO_DEALPORTSTR_ORIG_SCHED           38 /* Updated collateral payment schedules are not available, remittance info is used to roll forward original schedules */
#define ICMO_DEALPORTSTR_DERIVED_POOL         39 /* Collateral is modeled as replines created by Intex from information in the offering document or investor report */
#define ICMO_DEALPORTSTR_ROLLED_LOAN_LEVEL    40 /* Collateral is rolled forward from loan-level information that corresponds to a previous payment date */
#define ICMO_DEALPORTSTR_ROLLED_FROM_DATE     41 /* The as of date for the set of collateral rolled from */


/* ERRINFO: structures holding error info when error occurs */

typedef struct {
    char *errinfo_errmsg ;
    int   errinfo_reccol ;  /* 0 or in-record character counter in case of error during parsing internal string */
    } ERRINFO ;


typedef struct ICMOMISC ICMOMISC;

/* ICMO_PARSE_CONTROL: structure to hold parsing controls for altu_parse_control_fcn */
typedef struct {
   int parsctl_deal_mode;
   int parsctl_ignore_descriptive_info; /* same control as alto_ignore_descriptive_info in ICMOMISC_ALTEROPT */
} ICMO_PARSE_CONTROL ;


/* ICMO_OVRD_ASSET_PARSE_CONTROL: structure to hold controls for altu_override_asset_parse_fcn()  */

typedef struct {
    void *ovrdps_userp ; /* user handle points to altu_override_asset_parse_userp */

 /* INPUT. Filled by subroutines before calling altu_override_asset_parse_fcn() */
    int   ovrdps_asset_type;                /* type of asset currently parsing */
#define ICMOOVRDPS_TYPE_REREMIC         1   /* Reference to the underlying deal which is not parsed yet */
#define ICMOOVRDPS_TYPE_REREMIC_REPLINE 2   /* Underlying deal is replaced by asset with pre calculated cashflows */
#define ICMOOVRDPS_TYPE_ASSET_REGULAR   3   /* Regular asset, e.g. loan, high yield bond ... */
    int   ovrdps_status ;                   /* ICMOOVRD_ASSET_CF_STATUS_xx - ability to override asset cashflows in icmo_overrive_asset_cf_fcn() */
    int   ovrdps_n_req_attribs ;            /* size of ovrdps_v_req_attribs and ovrdps_v_req_attribs_vals */
    int  *ovrdps_v_req_attribs ;            /* vector of asset attributes ICMOOVRDPS_ASSET_xx needed to be set to avoid actual parsing of underlying deal for proper override cashflows*/
#define ICMOOVRDPS_ASSET_MAX_CF_LENGTH      0    /* max length of override cashflows vectors */
#define ICMOOVRDPS_ASSET_NOTIONAL_FLAG      1    /* asset notional flag corresp to ICMOTR_NOTIONAL_xx */
#define ICMOOVRDPS_ASSET_PAY_DAY            2    /* asset payment day  */
#define ICMOOVRDPS_ASSET_FREQ               3    /* asset frequency - number of payments per year */
#define ICMOOVRDPS_ASSET_MATURITY           4    /* asset stated maturity date */
#define ICMOOVRDPS_ASSET_CURBAL             5    /* asset current balance as of latest_cdu_date / xi_collat_cutoff_date */
#define ICMOOVRDPS_ASSET_FACE_AMT           6    /* 0 if ASSET_CURBAL doesn't need to be scaled or asset original face amount corresponding to provided ASSET_CURBAL */
#define ICMOOVRDPS_ASSET_NO_WRITEDOWN_FLAG  7    /* TRUE if structured asset does not take writedowns until deal maturity, i.e. implied writedown is applicable. Same meaning as ICMOADDLINFO_TR_NO_WRITEDOWN for the underlying asset */
#define ICMOOVRDPS_ASSET_CUR_VUNREALIZED_WRITEDOWNACCUM 8  /* asset current accumulated unrealized writedown as of latest_cdu_date / xi_collat_cutoff_date */
    double *ovrdps_v_req_attribs_vals ;     /* vector of provided values for ovrdps_v_req_attribs */

 /* OUTPUT. Set by user within altu_override_asset_parse_fcn()  */
    int ovrdps_ctrl_flag ;       /* for re-remic -control flag defining how underlying asset should be parsed */
#define ICMOOVRDPS_PARSE_FULL            0  /* underlying deal should be fully parsed - All info will be available and Intex cashflows could run.*/
#define ICMOOVRDPS_PARSE_FOR_OVERRIDE_CF 1  /* subroutines will automatically detect how underlying deal should be parsed ( or not parsed at all) to provide an ability to run icmo_override_asset_cf_fcn. */
#define ICMOOVRDPS_PARSE_SKIP            2  /* underlying deal should not be parsed. Similar to altu_pars_topdeal_only but for individual asset. Can't run cashflows. */

} ICMO_OVRD_ASSET_PARSE_CONTROL ;


/* ICMO_OVRD_ASSET_CF_CONTROL: structure to hold controls for icmo_override_asset_cf_fcn()  */

typedef struct {
    void *ovrdcf_userp ; /* user handle points to icmo_override_asset_cf_userp */

    /* INPUT. Filled by subroutines before calling altu_override_asset_parse_fcn() */
    int   ovrdcf_status ;             /* ICMOOVRD_ASSET_CF_STATUS_xx - ability/necessity to override asset cashflows in icmo_overrive_asset_cf_fcn() */
    int   ovrdcf_n_req_vectors ;      /* size of ovrdcf_v_req_vectors */
    int  *ovrdcf_v_req_vectors ;      /* vector of asset_cf  vectors ICMOOVRDCF_Vxx needed to be set at cf run for proper use of  icmo_overrive_asset_cf_fcn()  */
    YyyyMmDd ovrdcf_deal_required_base_determdate ; /* earliest date ( businessday adjusted) deal requires asset CF to be filled from, corresponds to 0-th element of deal's asset vectors */

     /* OUTPUT. Set by user within icmo_overrive_asset_cf_fcn() */
    int ovrdcf_ctrl_flag ;             /* control flag defining how asset should run or be overridden */
#define ICMOOVRDCF_USE_OVERRIDE     0  /* use override values */
#define ICMOOVRDCF_USE_STD_CALC     1  /* no values to override - continue standard asset CF calculations */

    /* should be filled by user within icmo_override_asset_cf_fcn() before first call of icmo_ovrdset_asset_vect() */
    YyyyMmDd ovrdcf_asset_provided_base_paydate ;  /* asset payment date(not businessday adjusted ), corresponds to 0-th element of provided asset or child's tranche vectors */
    double ovrdcf_asset_provided_face_amt ;        /* 0 if cashflows don't need to be scaled or asset original face amount corresponding to provided cashflows  */
} ICMO_OVRD_ASSET_CF_CONTROL ;


/* ICMOOVRD_ASSET_CF_STATUS_xx:  Ability/necessity to override asset cashflows in icmo_overrive_asset_cf_fcn()  */

#define ICMOOVRD_ASSET_CF_STATUS_ALLOWED     0  /* Asset cashflows could be overridden in icmo_overrive_asset_cf_fcn() for this asset  */
#define ICMOOVRD_ASSET_CF_STATUS_NOT_ALLOWED 1  /* Deal need some additional info from the underlying deal - icmo_overrive_asset_cf_fcn() could not be used for this asset  */
#define ICMOOVRD_ASSET_CF_STATUS_MUST        2  /* Underlying deal is not fully parsed by request of altu_override_asset_parse_fcn()
                                                     - asset cashflows must be overridden in icmo_overrive_asset_cf_fcn()  */

/* ICMOOVRDCF_xx:  mode for icmo_ovrdset_asset_vect() and values for ovrdcf_v_req_vectors. Specifies what info vectors corresponds to */

#define ICMOOVRDCF_VPAYDATES                   0 /* Payment dates */
#define ICMOOVRDCF_VPRINCIPAL                  1 /* Actual Principal $ paid */
#define ICMOOVRDCF_VINTEREST                   2 /* Actual Interest $ paid */
#define ICMOOVRDCF_VCASHFLOW                   3 /* Sum of above */
#define ICMOOVRDCF_VBALANCE                    4 /* Balance $ after pmt+writedown*/
#define ICMOOVRDCF_VSCHEDPRINCIPAL             5 /* Scheduled rcv'd $ */
#define ICMOOVRDCF_VOPTIMALINTEREST            6 /* Theo. int $ from coupon calc */
#define ICMOOVRDCF_VLOSSPRINCIPAL              7 /* Liquidated principal */
#define ICMOOVRDCF_VRECOVPRINCIPAL             8 /* Recovered principal  */
#define ICMOOVRDCF_VLOSSINTEREST               9 /* Interest losses      */
#define ICMOOVRDCF_VPERFORMING_BAL            10 /* Performing balance   */
#define ICMOOVRDCF_VPREPAYPENALTY             11 /* Prepay YM+points penalty */
#define ICMOOVRDCF_VDEFINTBAL                 12 /* Outstanding unpaid defer.interest */
#define ICMOOVRDCF_VPIKCURBAL                 13 /* Cur pik balance */
#define ICMOOVRDCF_VPIKCURPMT                 14 /* Cur pik payment */
#define ICMOOVRDCF_VPIKCURAMT                 15 /* Cur pik amount to be added to balance */
#define ICMOOVRDCF_VDAYS_ACCRUED              16 /* #of days accruing interest */
#define ICMOOVRDCF_VCOUPON                    17 /* coupon rate */
#define ICMOOVRDCF_VUNREALIZED_WRITEDOWNACCUM 18 /* implied writedown outstanding */
#define ICMOOVRDCF_VIMPLIED_WRITEDOWN         19 /* implied writedown this per */
#define ICMOOVRDCF_VCOUPONCAPSHORT            20 /* couponcapshort this per */
#define ICMOOVRDCF_VPAYBACKCPCAPSHORT         21 /* payback of couponcapshort this per */
#define ICMOOVRDCF_VNSINTSHORT                22 /* Interest loss due to allocation of non-supported intshort */
#define ICMOOVRDCF_MAX_N_VECTORS              23 /* Max number of ICMOOVRDCF vectors */

#ifdef DEFINE_ICMOOVRDCF_TYPE_NAMELIST
/* update ICMOOVRDCF_xx if add to icmo_ovrdcf_type_namelist */
char *icmo_ovrdcf_type_namelist[] = {
"VPAYDATES",
"VPRINCIPAL",
"VINTEREST",
"VCASHFLOW",
"VBALANCE",
"VSCHEDPRINCIPAL",
"VOPTIMALINTEREST",
"VLOSSPRINCIPAL",
"VRECOVPRINCIPAL",
"VLOSSINTEREST",
"VPERFORMING_BAL",
"VPREPAYPENALTY",
"VDEFINTBAL",
"VPIKCURBAL",
"VPIKCURPMT",
"VPIKCURAMT",
"VDAYS_ACCRUED",
"VCOUPON",
"VUNREALIZED_WRITEDOWNACCUM",
"VIMPLIED_WRITEDOWN",
"VCOUPONCAPSHORT",
"VPAYBACKCPCAPSHORT",
"VNSINTSHORT",
 NULL } ;
#else
extern char *icmo_ovrdcf_type_namelist[] ;
#endif


/* ICMO_OVRD_ASSET_CCF_INFO: structure to get info from/to CCF file using icmo_override_asset_read_ccf()/icmo_override_asset_write_ccf() */

#define MAX_CCF_COMMENT_STR_LENGTH     2000  /* maximum required length of accf_comment_str field */
#define MAX_CCF_ID_STR_LENGTH          1000  /* maximum required length of accf_id1xx fields     */

typedef struct {
    int      accf_rw_mode   ;           /* mode of read/write for icmo_override_asset_read_ccf() and icmo_override_asset_write_ccf() */
#define ICMORWCCF_READ_HEADER      0    /* read only header info form CCF file  */
#define ICMORWCCF_READ_CURBAL      1    /* read header info and cashflows vectors up to current balance */
#define ICMORWCCF_READ_FULL        2    /* read header and all cashflows vectors */
#define ICMORWCCF_WRITE_FROM_STATS 3    /* write CCF flie from results of preceeding icmo_stats run */
    char    *accf_filename  ;           /* full path to CCF file holding cashflows for asset override */
    char    *accf_errmsg ;              /* if not NULL - error msg string for ICMORWCCF_RETVAL_ERROR */

 /* Header info. Filled for any ICMORWCCF_READ_xx mode */
    char    *accf_comment_str ;         /* if not NULL - comment info string  */
    char    *accf_id1_dealname ;        /* asset ID or child dealname for reremic asset */
    char    *accf_id2_trname  ;         /* asset additional ID or child tranche name for reremic asset */
    YyyyMmDd accf_base_paydate ;        /* asset payment date(not businessday adjusted ), corresponds to 0-th element of provided asset or child's tranche vectors */
    YyyyMmDd accf_first_forecast_date ; /* asset cashflow date corresponding to the first forecasted (unknown) period */
    YyyyMmDd accf_orig_first_paydate ;  /* asset's original first payment date */
    int      accf_cf_length ;           /* length of override cashflows vectors */
    int      accf_notional_flag ;       /* asset notional flag corresp to ICMOTR_NOTIONAL_xx */
    int      accf_no_writedown_flag ;   /* TRUE if structured asset does not take writedowns until deal maturity, i.e. implied writedown is applicable. Same meaning as ICMOADDLINFO_TR_NO_WRITEDOWN for the underlying asset */
    int      accf_freq ;                /* asset frequency */
    YyyyMmDd accf_maturity ;            /* asset stated maturity date */
    double   accf_face_amount  ;        /* 0 if asset cf don't need to be scaled or asset original face amount corresponding to provided cfs */

 /* Curent balance info. Filled for ICMORWCCF_READ_CURBAL mode from VBALANCE vector */
    double   accf_curbal ;              /* asset current balance as of latest_cdu_date / xi_collat_cutoff_date */
    double   accf_cur_unrealized_writedownaccum ;  /* asset current accumulated unrealized writedown as of latest_cdu_date / xi_collat_cutoff_date */
    YyyyMmDd accf_curbal_date ;         /* date corresponding to asset current balance */

 /* Cashflows vectors. Filled for ICMORWCCF_READ_FULL mode */
    int      accf_n_vects ;             /* # of elements in accf_v_vect_types and accf_v_vect_vals */
    int     *accf_v_vect_types ;        /* vector of asset ICMOOVRDCF_xx types */
    double **accf_v_vect_vals  ;        /* vector of asset cashflows vectors  */
} ICMO_OVRD_ASSET_CCF_INFO ;

/* ICMORWCCF_RETVAL_xx:  return values for icmo_override_asset_read_ccf() and icmo_override_asset_write_ccf()*/

#define ICMORWCCF_RETVAL_OK         0   /* successfully read CCF file */
#define ICMORWCCF_RETVAL_NO_FILE    1   /* requested accf_filename not found */
#define ICMORWCCF_RETVAL_ERROR      2   /* error when reading CCF file  */


/* ICMOSPSTR: structure used for icmo_spstr() call */

typedef struct {
    int      icmospstr_action ;         /* ICMOSPSTR_ACTION_xx */
#define ICMOSPSTR_ACTION_TO      1      /* from icmot_statsparam to icmospstr_buff */
#define ICMOSPSTR_ACTION_FROM    2      /* from icmospstr_buff to icmot_statsparam */
    int      icmospstr_options ;        /* ICMOSPSTR_OPTION_xx */
#define ICMOSPSTR_OPTION_INC_STATIC_ICMOT 0x01 /* include static portion of icmot_xx fields in action */
#define ICMOSPSTR_OPTION_INC_TOTRET_ICMOT 0x02 /* include portion of icmot_xx fields to support icmo_horizon_return */
#define ICMOSPSTR_OPTION_AS_FORWARD_STATS 0x04 /* short version as a forward settle date */
#define ICMOSPSTR_OPTION_INC_IDXVALS      0x08 /* include index info for DM */
    char    *icmospstr_buff ;           /* IN/OUT: buffer to hold spstr */
} ICMOSPSTR ;


typedef int ICMO_FCN_ID ;
/* ICMO_FCN_xx: Functions ID used in ICMO_CALL_START_CONTROL structure */

#define ICMO_FCN_icmo_deal                 0
#define ICMO_FCN_icmo_cashflows            1
#define ICMO_FCN_icmo_free                 2
#define ICMO_FCN_icmo_free_struct_ICMOMISC 3
#define ICMO_FCN_icmo_use_bv_coll          4


/* ICMO_CALL_START_CONTROL: Control structure passed to user_call_start_fcn() callback function */

typedef struct {
    ICMOMISC    *callctl_icmomiscp;   /* NULL or ICMOMISC structure pointer     */
    ICMO        *callctl_icmop;       /* NULL or ICMO     structure pointer     */
    ICMO_FCN_ID  callctl_fcnid;       /* ICMO_FCN_xx functions ID              */
    void        *callctl_userp;       /* user handle set by altu_call_start_userp or wrkrctl_call_start_userp  */
    } ICMO_CALL_START_CONTROL ;


/* ICMO_WORKER_CONTROL: Control structure to be passed to icmo_worker() function */

typedef struct {
    int ((CALLBK_FCN_PREFIX *wrkrctl_call_start_fcn)(Args_call_start_fcn));   /* user fcn to be called at start of various icmo functions */
    void *wrkrctl_call_start_userp ;  /* user handle to be passed to call_start_fcn */
    } ICMO_WORKER_CONTROL ;


/* MISC_INTERNAL_INFO:  internal fields to be used only by  Intex subroutines */

#define MISC_INTERNAL_INFO_SIZE    100
INTEX_INTERNAL_USE_ONLY  typedef struct  {
INTEX_INTERNAL_USE_ONLY      double internal_info_align;
INTEX_INTERNAL_USE_ONLY      char   internal_info_buff [MISC_INTERNAL_INFO_SIZE];
INTEX_INTERNAL_USE_ONLY      }  MISC_INTERNAL_INFO ;


/* ICMOMISC_ALTERCOLLAT:  set of flags that modify collateral at parse time */

typedef struct  {
    int altc_ignore_wala ; /* set wala = origterm - wam in cashflows */
    int altc_ignore_age  ; /* set age = origterm - bvremterm in parsing */
    int altc_ignore_curpmt ;   /* TRUE= derive P+I from remterm */
    int altc_wala_avg_clamp ;  /* month pool becomes seasoned,dflt=30*/
    int altc_clear_arm_params; /* ICMOCLEAR_ARM_xx: nullifies ARM caps&flrs */
    int altc_include_prepaypenalty; /* ICMOPREPAYPENALTY_xx: Prepayment penalty handling */
    int altc_prepricing_reremic; /* TRUE= allow child CDP to be 1mo earlier */
    int altc_ignore_real_collat; /* TRUE= ignore real collat in CDI */
    int altc_use_raw_opinfo ;  /* ALTC_DERIVE_OPINFO_xx */
#define ALTC_DERIVE_OPINFO_SOME  0 /* given some CMBS operating info, we can calculate some missing values */
#define ALTC_DERIVE_OPINFO_NONE  1 /* don't derive any CMBS operating info */
#define ALTC_DERIVE_OPINFO_ALL   2 /* assume "reasonable" values for NOI and DSCR if not available */
    int altc_loanattr_info;  /* how to present loanattr info code */
#define ALTC_LOANATTR_RAW_CODE    0 /* use the code reported by issuer/trustee */
#define ALTC_LOANATTR_INTEX_CODE  1 /* use intex standard code */
    int altc_tenantname_info; /* how to present tenant name */
#define ALTC_TENANTNAME_RAWNAME   0 /* use the name reported by issuer/trustee */
#define ALTC_TENANTNAME_STANDARD  1 /* use standard name */
   int altc_loandata_info ;         /* bit flag for  loandata info */
#define ALTC_LOANDATA_STANDARD          0x0 /* provide access to raw loandata */
#define ALTC_LOANDATA_WITH_TRANSLATION  0x1 /* also provide access to loandata translated to a descriptive string */
    void *((CALLBK_FCN_PREFIX *altc_userdata_fcn)(Args_altc_userdata_fcn));
    void *altc_userdata_userp ;  /* user handle to be passed to altu_errmsg_fcn */
    int altc_reremic_info_from;  /* ALTC_REREMIC_INFO_FROM_xxx */
#define ALTC_REREMIC_INFO_FROM_INTEX_DEFAULT      (-1) /* use underlying collat/tranche info based on underlying deal type */
#define ALTC_REREMIC_INFO_FROM_UNDERLYING_COLLAT    0  /* use underlying collat info */
#define ALTC_REREMIC_INFO_FROM_UNDERLYING_TRANCHE   1  /* use underlying tranche info */
    int altc_pnote_main_as_collat; /* TRUE to use PNOTE MAIN as collat instead of whole loan */
    }  ICMOMISC_ALTERCOLLAT ;

/* ICMO_COLLUSERDATA_xx:  passed to the altc_userdata_fcn callback to indicate the purpose of the call */
#define ICMO_COLLUSERDATA_ACCUM_BASE 1000     /* Base value to discriminate which userdata item for return */

#define ICMO_COLLUSERDATA_FREE                                        -1  /* The item is being freed */
#define ICMO_COLLUSERDATA_ATTACH                                       0  /* The has been parsed or refreshed */
#define ICMO_COLLUSERDATA_PROPAGATE                                    1  /* The item is being propagated (scaled) into a parent */
#define ICMO_COLLUSERDATA_ACCUM        (ICMO_COLLUSERDATA_ACCUM_BASE + 0) /* The item is being accumulated into a cluster */
#define ICMO_COLLUSERDATA_ACCUM_FINI   (ICMO_COLLUSERDATA_ACCUM_BASE + 1) /* The cluster is complete */

/* ICMOMISC_ALTEROPT:  set of flags that modify default optimization */

typedef struct  {
    int alto_keep_underlying_pass_thru; /* ALTO_KEEP_PASSTHRU_xx */
#define ALTO_KEEP_PASSTHRU_DEFAULT 0 /* explode pass_thru tranches whenever possible */
#define ALTO_KEEP_PASSTHRU_DEAL    1 /* keep pass_thru tranches as separate deals */
#define ALTO_KEEP_PASSTHRU_ALL     2 /* keep mega/giants as separate deals as well */
    int alto_keep_duplicated_reremics; /* TRUE=pars & run same underlying deal for each reference to it in collat*/
    int alto_keep_independent_groups;  /* TRUE= ignore indep.groups opt.*/
    int alto_keep_valueless_abs_summary_infos ; /* add all acceptable ICMOABSI_xx elements to ABS_SUMMARY_INFO list even if no data available in CDU */
    int alto_dont_optimize_rules;      /* TRUE=keep prorata scheds/not opt.exprs.*/
    int alto_optimize_allpool_cfspeed; /* optimize CF speed for all-pool mode */
    int alto_ignore_paiddown_collat; /* exclude paid down pools or re-remics from collateral */
    int alto_ignore_descriptive_info; /* ICMO_IGNOREDESCR_xx: bit flag to exclude deal info not used in cashflows calculations */
    int alto_optimize_loandata_access ; /* optimized memory usage for LOANDATA */
#define ALTO_OPTIMIZE_LOANDATA_NONE  0 /* no optimization for LOANDATA memory usage  */
#define ALTO_OPTIMIZE_LOANDATA_NAME  1 /* optimize loandata_name storage. requires access via ICMO_LOANDATA_NAME macro  */
    int alto_use_mbspool_addl_files;   /* ICMOMBSLOOP_READ_ADDL_xx: force the reading of the MBS pools geographical data - causes slowdown if we do read geo data */
#define alto_use_mbspool_geo_file alto_use_mbspool_addl_files
    /* following field require to use icmo_setup_icmomiscp() function  */
    double alto_explode_contribution_min; /* min $ amount of Mega/Giant curbal
                                             contribution to keep exploding */
#define ICMO_DEFAULT_EXPLODE_CONTRIBUTION_MIN  500.00  /* default value for above */
    }  ICMOMISC_ALTEROPT ;


/* ICMOMISC_CROSS_DEALS_CACHE: Structure to cache auxiliary data which could be re-used by different deals */

typedef struct  {
    char *cross_deals_cache_datap ;   /* points to cached data */
    }  ICMOMISC_CROSS_DEALS_CACHE ;


/* ICMOMISC_ALTERUSE:  set of flags that modify subroutines usage */

typedef struct  {
    char *altu_base_cdi_path ;          /* base path to CDI directory. Replaces icmo_deal() dir_prefix parameter  */
    char *altu_base_cdu_path ;          /* base path to CDU directory. Replaces icmo_deal() dir_prefix parameter  */
    char *altu_single_tranche_only ;    /* need info & cf only for given list of tranches*/
#define USE_ALL_PARTCDU_TRANCHES  "*"   /* set to use all groups provided in partial CDU */
    char *altu_predefined_vars ;        /* comma-delimited list of pre-defined #vars for ifdef in CDI*/
    char *altu_addl_required_loandata ; /* comma-delimited list of additional loandata names which should not be ignored by ICMO_IGNOREDESCR_LOANDATA and clustered separately for string values */
    char *((CALLBK_FCN_PREFIX *altu_altfile_fcn)(Args_altfile_fcn));
                                 /* called before open a file to read */
    void *altu_altfile_userp  ;  /* user handle to be passed to altfile_fcn */
    int ((CALLBK_FCN_PREFIX *altu_errmsg_fcn)(Args_altu_errmsg_fcn));
    void *altu_errmsg_userp;     /* user handle to be passed to altu_errmsg_fcn */
    ICMOMISC_CROSS_DEALS_CACHE *altu_cross_deals_cachep ;  /* points to the structure to cache auxiliary data which could be re-used by different deals,
                                                             must be allocated by icmo_make_struct() and freed by icmo_free_struct() */
    char *altu_mbspool_cache ;   /* cache data to speed up */
    char *altu_ppmdl_finetune ;  /* user can cast this to point to optional Espiel prepay model fine tuning structure */
    char *altu_ppmdl_dirpath ;   /* NULL, or explicit 3rdparty data */
    void ((CALLBK_FCN_STDCALL *altu_ppmdl_tune_fcn)(Args_adp_tune_fcn)) ; /* NULL, or to ADP tuning function*/
    int   altu_ppmdl_type ;      /* 0, or ICMOSPDT_PPMDL_xx to be used */
    int   altu_ppmdl_ratetype ;  /* ALTU_PPMRATE_XX, 3rd party prepay model uses these rates to calc spread */
#define ALTU_PPMRATE_TREAS  0    /* default, have 3rd party use Treas rates to calc spreads and current coupons */
#define ALTU_PPMRATE_LIBOR  1    /* have 3rd party use Libor par coupon instead of Treas to calc spreads - ADCO only */
#define ALTU_PPMRATE_MTGS   2    /* have 3rd party use mtg rates instead of Treas rates - AFT Default model only */
    int   altu_pars_topdeal_only ;   /* number of re-remic levels to pars, 1=don't need underlying deals (unable to run cashflows) */
    int   altu_ignore_block_accum_shortfalls;  /* flag to ignore shortfalls accumulation. Use binary mask concept  */
#define ICMOIGNORE_BLOCK_ACCUM_INTLOSS_START         0x01  /* ignore reported accumulated interest loss */
#define ICMOIGNORE_BLOCK_ACCUM_INTLOSS_FORECAST      0x02  /* ignore forecasted accumulated interest loss */
#define ICMOIGNORE_BLOCK_ACCUM_INTSHORT_START        0x04  /* ignore reported accumulated interest shortfall */
#define ICMOIGNORE_BLOCK_ACCUM_INTSHORT_FORECAST     0x08  /* ignore forecasted accumulated interest shortfall */
#define ICMOIGNORE_BLOCK_ACCUM_PRINLOSS_START        0x10  /* ignore reported accumulated principal loss */
#define ICMOIGNORE_BLOCK_ACCUM_PRINLOSS_FORECAST     0x20  /* ignore forecasted accumulated principal loss */
#define ICMOIGNORE_BLOCK_ACCUM_COUPONCAP_START       0x40  /* ignore reported accumulated couponcap shortfall */
#define ICMOIGNORE_BLOCK_ACCUM_COUPONCAP_FORECAST    0x80  /* ignore forecasted accumulated couponcap shortfall */
#define ICMOIGNORE_BLOCK_ACCUM_ALL_START     (ICMOIGNORE_BLOCK_ACCUM_INTLOSS_START | ICMOIGNORE_BLOCK_ACCUM_INTSHORT_START | ICMOIGNORE_BLOCK_ACCUM_PRINLOSS_START | ICMOIGNORE_BLOCK_ACCUM_COUPONCAP_START )
#define ICMOIGNORE_BLOCK_ACCUM_ALL_FORECAST  (ICMOIGNORE_BLOCK_ACCUM_INTLOSS_FORECAST | ICMOIGNORE_BLOCK_ACCUM_INTSHORT_FORECAST | ICMOIGNORE_BLOCK_ACCUM_PRINLOSS_FORECAST | ICMOIGNORE_BLOCK_ACCUM_COUPONCAP_FORECAST )
    int   altu_use_mbspool_cache;/* TRUE to use altu_mbspool_cache to speed up.
                                    last icmo_deal call should use FALSE to free altu_mbspool_cache*/
    int   altu_extended_callable_flag; /* TRUE to redefine callable_by_investor as ICMOCALLABLE_xx */
    int   altu_run_taxable_cf;   /* future.. TRUE to pars tax related info and run taxable cf */
    int   altu_indexdeps_all;    /* set tr index dependency for all tranches */
    int   altu_cda_use ;         /* ALTU_CDAUSE_xx: the way CDA is used */
#define ALTU_CDAUSE_DEFAULT    0 /* by default, use CDA if CDU missing */
#define ALTU_CDAUSE_ALWAYS     1 /* use CDA even if CDU exist */
#define ALTU_CDAUSE_NEVER      2 /* never use CDA */
    YyyyMmDd altu_ignore_cdu_paydate_after; /* ignore any CDUs that represents deal payment date after this date */
    /* following fields require to use icmo_setup_icmomiscp() function */
    int   altu_accept_partial_cdu ; /* ALTU_PARTCDU_xx: partial cdu handling*/
#define ALTU_PARTCDU_NO   0   /* ignore partial cdu  */
#define ALTU_PARTCDU_OK   1   /* accept partial cdu (for single_tranche_only mode )*/
#define ALTU_PARTCDU_FORCE 2  /* same as OK, but if both normal and partial CDU exists for
                                 the same month - use partial ( for testing only )*/
    int   altu_limit_hist_lookback ; /* #months back to search for a CDU */
    int   altu_use_musip ; /* Special way of altering artificial cusips */
#define ALTU_USEMUSIP_NO  0   /* use normal 9 digit cusip */
#define ALTU_USEMUSIP_YES 1   /* use altered cusip named musip */
    int   altu_yldcrv_nodes;  /* Altering yield curve nodes */
#define ALTU_YLDCRV_COMMON  0 /* Current nodes: 3mo,6mo,2,5,10,30 yrs*/
#define ALTU_YLDCRV_ALSO3YR 2 /* Current nodes, plus the old 3yr */
#define ALTU_YLDCRV_ALSO7YR 4 /* Current nodes, plus the old 7yr */
#define ALTU_YLDCRV_ALSO1YR 8 /* Current nodes, plus the old 1yr */
    int   altu_cleanup_accuracy_required;  /* TRUE if when run with opt. redemption need accurate CF
                      for cleanup call. Turns off speed up for deals with independent groups */
    int   altu_allow_child_cf_access; /* to save child deal CF to allow icmo_stats */
#define ALTU_ALLOW_CHILD_NONE           0 /* allow access to no child deals */
#define ALTU_ALLOW_CHILD_ALL            1 /* allow access to all child deals */
#define ALTU_ALLOW_CHILD_DEAL_DATA_FROM 2 /* allow access to child deal that is marked as DEAL_DATA_FROM_CHILD */
#define ALTU_ALLOW_CHILD_SCEN_CF      128 /* modifier to allow access to child deal's cashflows for all scenarios (only for ALTU_ALLOW_CHILD_DEAL_DATA_FROM )*/
    int   altu_allow_access_known_cf_nmon ; /* allow to access #of months of historical CF even if not entitled. !! This may slow down parsing significantly */
#define ALTU_ALLOW_ACCESS_KNOWN_CF_FROM_SCHEDULED_PAYDATE 10000  /* allow to access historical CF starting from preceding to settlement scheduled deal payment date if settle between scheduled deal payment dates for non monthly paying deals */
    int   altu_latest_report_info; /* ALTU_LATEST_REPORT_xx: if settle in the past, show latest CDU info instead of settlement CDU info */
#define ALTU_LATEST_REPORT_NONE         0 /* by default */
#define ALTU_LATEST_REPORT_ABS_SUMMARY  1 /* show ABS_SUMMARY from latest CDUs */
    char **altu_override_cdu_paths; /* override CDU path with a NULL ending vector of CDU paths to search */
    char **altu_addl_currency_files; /* NULL-terminated list of addl currency IDL files */
DEPRECATED   char **altu_loc_cache_icmop ; /* Deprecated: */
    char *altu_release_date_kc; /* keycode to unlock tranches before release date */
    char *altu_access_kc;  /* keycode to provide restricted access */
    char *altu_company_name; /* required to validate altu_access_kc */
    int ((CALLBK_FCN_PREFIX *altu_parse_control_fcn)(Args_parse_control_fcn));
    void *altu_parse_control_userp ;  /* user handle to be passed to parse_control_fcn */
    int ((CALLBK_FCN_PREFIX *altu_override_asset_parse_fcn )(Args_override_asset_parse_fcn )); /* user fcn to be called to control asset parsing to support following run of icmo_override_asset_cf_fcn() */
    int altu_override_asset_accepted ; /* define set of assets for which altu_override_asset_parse_fcn will be called */
#define ALTU_OVERRIDE_ASSET_REREMIC 0 /* altu_override_asset_parse_fcn call only for REREMIC or REREMIC_REPLINE ( default) */
#define ALTU_OVERRIDE_ASSET_LIMITED 1 /* altu_override_asset_parse_fcn call also for regular assets but with ability
                                         to override same vectors as for REREMICs. Assumes that only assets representing re-remics will be overwritten */
    void *altu_override_asset_parse_userp ;  /* user handle to be passed to altu_override_asset_parse_fcn  */
    int ((CALLBK_FCN_PREFIX *altu_call_start_fcn)(Args_call_start_fcn));   /* user fcn to be called at start of various icmo functions */
    void *altu_call_start_userp ;  /* user handle to be passed to call_start_fcn */
    int   altu_parallel_mode ;  /* ALTU_PARALLEL_MODE_xx: Run in parallel mode, if possible. */
#define ALTU_PARALLEL_MODE_NONE  0
#define ALTU_PARALLEL_MODE_MPI   1
    int   altu_parallel_mode_partition_type ;  /* ALTU_PARALLEL_MODE_PARTITION_xx: Method for partitioning collateral among processes. */
#define ALTU_PARALLEL_MODE_PARTITION_AUTOMATIC  0  /* Let the master process decide how to partition */
#define ALTU_PARALLEL_MODE_PARTITION_BY_POOLS   1  /* Partition into subsets of pools */
#define ALTU_PARALLEL_MODE_PARTITION_BY_DEALS   2  /* Partition into subsets of deals */
    int   altu_max_n_addl_groups ;  /* max # addl groups allowed by ICMOADDLINFO_SET_ADDL_GROUP */
#define ALTU_MT_COMMON        0  /* common setting for MT  */
#define ALTU_MT_PARSE         1  /* override common setting for parsing */
#define ALTU_MT_RUNCF         2  /* override common setting for CF run */
#define ALTU_MT_POOLSCF       3  /* override common setting for POOLS CF run */
#define ALTU_MT_N_TYPES       4  /* # of ALTU_MT_xxx */
    int   altu_v_max_threads[ALTU_MT_N_TYPES]; /* activate MT: max # of concurrent processing threads allowed */
#define altu_max_threads  altu_v_max_threads[ALTU_MT_COMMON]
    }  ICMOMISC_ALTERUSE ;

/* ALTU_PARSE_CONTROL_STEP_xx: altu_parse_control_fcn calling mode */
#define ALTU_PARSE_CONTROL_STEP_BEFORE_CDU_COLLAT   1   /* called before parsing CDU collateral */
#define ALTU_PARSE_CONTROL_STEP_BEFORE_CLUSTERING   2   /* called after parsing collateral, before clustering */

/* ICMOMISC_SETUP_xx setup mode parameter value for icmo_setup_icmomiscp() */

#define ICMOMISC_SETUP_MINIMAL 1  /* Cleanup icmomisc structure - user will
                                               set all individual fields later */
#define ICMOMISC_SETUP_TYPICAL 2  /* set some fields following Intex common
                                         recommendation - could override later */


/* ICMOMISC: miscellaneous Intex CMO system info */

struct ICMOMISC {

    /* Settings which control the deal parser */

    int icmomisc_use_duebill ;    /* ICMODUEBILL_xx: at settlement */
    int icmomisc_use_hist    ;    /* if settle in past, #mos actual hist*/
    int icmomisc_use_vindex0 ;    /* override known index with vindex[0]*/
    int icmomisc_newdeal_idx ;    /* if TRUE, ICMODEAL_NEW gets indexs*/
    int icmomisc_hide_errmsgs;    /* if TRUE, parsing errs won't printf*/
    int icmomisc_clamp_floaters ;    /* if TRUE, bonds pay at init rates*/
    int icmomisc_make_collat_tranche;/* ICMOCOLLAT_xx: creates pseudo tr*/
    int icmomisc_make_xrs_tranche;    /* if TRUE, make XRS collat pseudo tranches */
    int icmomisc_closing_sched_case; /* set up spec.flag for internal use*/
    int icmomisc_explode_pools ;     /* ICMOEXPLODE_xx - to control mega/giant explosion */
    int icmomisc_settle_with_cdu_date; /* TRUE, if settle_date in icmo_deal() is CDU date */
#define ICMOMISC_SETTLE_WITH_CDU_DATE       1 /* settle_date is CDU date */
#define ICMOMISC_SETTLE_WITH_CDU_ASOF_DATE  2 /* settle_date is CDU ASOF date */
    int icmomisc_seek_cdi_collat_assumption;     /* ICMOCDICOLLAT_xx: choose*/
    int icmomisc_trading_accuracy_not_required ; /* if TRUE, OK for portfolio */
    int icmomisc_accept_currency ;               /* ICMOACCEPTCURR_xx */
    int icmomisc_accept_extended_index_list ;    /* TRUE for handling indexes beyond ICMOI_MISC_3 */
    int icmomisc_override_max_cf_vectsize;       /*to increase default size of vect.alloc*/
    int icmomisc_error_checking_level;           /* to set advanced error checking level */
    int icmomisc_index_forecast_resolution; /* ICMOINDEX_xx_RESOLUTION */
    int icmomisc_read_whole_idx_file; /*TRUE=set all IDX indexes referenced*/
    int icmomisc_instruct_latest_cdu_yymm; /* YYMM of CDU data provided */
    int  icmomisc_use_outsrc ; /* flag determines whether to call outsrc fcns. */
    int icmomisc_nuservals ;      /* # of cells corresponding to .. */
    double *icmomisc_uservals ;   /* .. CDI function U(..) */
    double ((CALLBK_FCN_PREFIX  *icmomisc_cdi_user_fcn)(Args_cdi_user_fcn));
                                  /* CDI user function UFCN() */
    ICMOMISC_ALTERCOLLAT icmomisc_altercollat ;  /* flags change loans */
    ICMOMISC_ALTEROPT icmomisc_alteropt; /* flags change optimization */
    ICMOMISC_ALTERUSE icmomisc_alteruse; /* flags change subroutines usage */
    CLUSTER icmomisc_cluster ;    /* flags for doing clustering */
    char *icmomisc_idx_directory; /* path to IDX file dir if not CDU dir*/
    char *icmomisc_idx_filename ; /* to replace default filename.IDX    */
    char *icmomisc_merge_into_cdi; /* NULL, or CDI portion to be added */
    char *icmomisc_isr_fn ;    /* full name of ISR file for Intex Subroutines Recording  */
    int ((CALLBK_FCN_PREFIX *icmomisc_parse_progress_fcn)(Args_parse_progress_fcn)) ;
    int ((CALLBK_FCN_PREFIX *icmomisc_instruct_body_fcn)(Args_instruct_body_fcn));
    int ((CALLBK_FCN_PREFIX *icmomisc_instruct_trblk_fcn)(Args_instruct_trblk_fcn));
    int ((CALLBK_FCN_PREFIX *icmomisc_instruct_trblk_updt_fcn)(Args_instruct_trblk_updt_fcn));
    int ((CALLBK_FCN_PREFIX *icmomisc_instruct_sched_fcn)(Args_instruct_sched_fcn));
    int ((CALLBK_FCN_PREFIX *icmomisc_instruct_collat_fcn)(Args_instruct_collat_fcn));
    double ((CALLBK_FCN_PREFIX *icmomisc_instruct_index_fcn)(Args_instruct_index_fcn));
    char *icmomisc_instruct_out_fn ; /* output file name to debug */
    char *icmomisc_outsrcp ; /* pointer to "outsourced" code */
    char *icmomisc_user ; /* spare pointer available to user */

    /* Information available after a parsing error */

    int icmomisc_pars_errwhen ;   /* ICMOPARSERR_xx: class of error */
    int icmomisc_pars_recnum ;    /* CDI record counter (>=1) */
    int icmomisc_pars_reccol ;    /* in-record character counter (>=1) */
    char *icmomisc_pars_fn   ;    /* NULL, or file currently parsing if
                                     icmomisc_hide_errmsgs mode */
    char *icmomisc_pars_errmsg1;  /* more info re error */
    char *icmomisc_pars_errmsg2;  /* more info re error */
    char *icmomisc_pars_errmsg3;  /* more info re error */
    char *icmomisc_pars_errrec ;  /* more info re error */
    char *icmomisc_pars_err_icmop ; /* unfinished ICMO structure during parsing - for freeing in icmo_errdie() */
    YyyyMmDd icmomisc_deal_settle_date; /* Orig date of deal settlement */
    YyyyMmDd icmomisc_tranche_fdate; /* Tranches update factor date */

    /* Old fields not to use, retained for compatibility */
DEPRECATED    int icmomisc_do_save_resid_info;  /* Deprecated: */

    /* Internal field to be used only by  Intex subroutines */
INTEX_INTERNAL_USE_ONLY    MISC_INTERNAL_INFO icmomisc_internal_info;

    } ;

#define CDU_TRADING_ACCURACY_IGNORED  2   /* ignore CDU flag when setting icmo_not_at_trading_accuracy */
#define INFO_TRADING_ACCURACY_IGNORED 66  /* for "Info Only" deal CFs */

#ifdef ICMO_NO_ANSI_PROTOTYPING
#define Args_speed_fcn
#define Args_index_fcn
#define Args_1speed_fcn
#define Args_1index_fcn
#define Args_pool_cf_fcn
#define Args_count_npools_fcn
#define Args_override_asset_cf_fcn
#define Args_override_pool_cf_fcn
#define Args_optredeem_fcn
#define Args_info_1period_fcn
#define Args_forex_fcn
#define Args_cdumsg_fcn
#define Args_parserr_fcn
#define Args_iover_symvar_fcn
#define Args_iover_index_fcn
#define Args_icmosolver_user_fcn
#define Args_isr_play_control_fcn
#define Args_replace_buy_collat_fcn
#else
#define Args_speed_fcn          struct _ICMO*,POOL_INFO*,int,int,int,double*
#define Args_index_fcn          struct _ICMO*,int
#define Args_1speed_fcn         struct _ICMO*,POOL_INFO*,int,int,int
#define Args_1index_fcn         struct _ICMO*,int,int
#define Args_pool_cf_fcn        struct _ICMO*,POOL_INFO*,int,double*,double*,double*,double*,int
#define Args_count_npools_fcn   struct _ICMO*,char*,POOL_INFO*,int
#define Args_override_asset_cf_fcn  struct _ICMO*,POOL_INFO*
#define Args_override_pool_cf_fcn  struct _ICMO*,POOL_INFO*,int,int,double*,double*,double*,double*
#define Args_optredeem_fcn      struct _ICMO*,YyyyMmDd,int,int
#define Args_info_1period_fcn   struct _ICMO*,YyyyMmDd,int,int,int
#define Args_forex_fcn          struct _ICMO*,ICMO_CURRENCY*,ICMO_CURRENCY*
#define Args_cdumsg_fcn         char*,char*,POOL_INFO*
#define Args_parserr_fcn        struct _ICMO*,int,int,char*,char*,char*,char*
#define Args_iover_symvar_fcn   struct _ICMO*,int,char*,char*
#define Args_iover_index_fcn    struct _ICMO*,int,char*,int
#define Args_icmosolver_user_fcn  struct _ICMOSOLVER*,double,double,int
#define Args_isr_play_control_fcn  struct _ICMOISR*
#define Args_replace_buy_collat_fcn  struct _ICMO*,POOL_INFO*,YyyyMmDd,double
typedef struct _ICMO _ICMO ;     /* Needed for some UNIX compilers */
#endif

/* ADCO_CFA_PPMDL: Structure to hold CFASSUM forecasts for ADCO MODEL */
typedef struct {
    char    *adco_cfa_ppmdl_mdlogfile ;  /* NULL, or fully pathed log file if user wants to run ADCO in special mode to analyze data availability */
    int      adco_cfa_ppmdl_loss_n_hpi ; /* # of elements in hpi forecast for ADCO CREDIT MODEL */
    double  *adco_cfa_ppmdl_loss_vhpi  ; /* vector of hpi forecast for ADCO CREDIT MODEL */
    } ADCO_CFA_PPMDL ;

/* PPMDL_MTGS:  Structure to hold AFT_CFA_PPMDL mortgage rate forecasts */
typedef struct {
    int        ppmdl_mtgs_n_rates ;    /* length of ppmdl_mgts_vrates vector */
    double    *ppmdl_mtgs_vrates ;     /* vector of mortgage rate forecasts [0] = current rate */
   } PPMDL_MTGS ;

/* PPMDL_MTGS_xxx:  type of mortgage rate being forecasted in AFT_CFA_PPMDL */
#define PPMDL_MTGS_5YR         0    /*  5 year hybrid mortgage rates */
#define PPMDL_MTGS_7YR         1    /*  7 year hybrid mortgage rates */
#define PPMDL_MTGS_15YR        2    /*  15 year conforming mortgage rates */
#define PPMDL_MTGS_30YR        3    /*  30 year conforming mortgage rates */
#define PPMDL_MTGS_N_TYPES     4    /* # of mortgage types */


/* AFT_CFA_PPMDL:  Structure to hold CFASSUM forecasts for AFT MODEL */
typedef struct {
#define HPI_ADDL_FN_LEN 12
    char     aft_cfa_ppmdl_hpi_addl_fn[HPI_ADDL_FN_LEN] ; /* string appended to AFT default HPI file name */
    int      aft_cfa_ppmdl_loss_n_hpi ; /* # of elements in hpi forecast for AFT DEFAULT MODEL */
    double  *aft_cfa_ppmdl_loss_vhpi   ; /* vecor of hpi forecast for AFT DEFAULT MODEL */
    PPMDL_MTGS aft_cfa_ppmdl_v_mtgs[PPMDL_MTGS_N_TYPES] ;
    } AFT_CFA_PPMDL ;

/* CFASSUM_CFADJ: Structure to hold CFASSUM forecasts for addl CF adjustments */
typedef struct {
    int     cfadj_nfrac;       /* #mos proj. in cfadj_vfrac vector */
    double *cfadj_vfrac;       /* adjustment fraction vector [1]=1st rate */
    int     cfadj_basis;       /* ICMOCFADJ_BASIS_xx */
#define ICMOCFADJ_BASIS_CURBAL           1 /* Use cur period balance as basis */
#define ICMOCFADJ_BASIS_ORIGBAL          2 /* Use loan original balance as basis (scaled for survival factor) */
#define ICMOCFADJ_BASIS_UNSCALED_ORIGBAL 3 /* Use loan original balance as basis (not scaled for survival factor) */
#define ICMOCFADJ_BASIS_GROSSINT         4 /* Use cur gross interest as basis (for ICMOCFADJ_ADDL_MISCINT only)*/
#define ICMOCFADJ_BASIS_NEWDEF_CURPMT    5 /* Use curpmt on newly defaulted loan as basis */
    } CFASSUM_CFADJ ;

/* ICMOCFADJ_xx: CF adj types */
#define ICMOCFADJ_ADDL_LOSS      0   /* addl balance reduction loss */
#define ICMOCFADJ_ADDL_MISCINT   1   /* addl misc. interest */
#define ICMOCFADJ_ADDL_PRINC     2   /* addl principal */
#define ICMOCFADJ_ADDL_FORB      3   /* addl Forbearance */
#define ICMOCFADJ_ADDL_ADVANCE   4   /* addl servicer advances on new default */
#define ICMOCFADJ_ADDL_INTLOSS   5   /* addl intloss on new default */
#define ICMOCFADJ_ADDL_SERVLOSS  6   /* addl servloss on new default */
#define ICMOCFADJ_N_TYPES        7   /* # of types ( must be the same as in mbs.h )*/

/* ICMOCFADJ_VALUE_xxx: special value for cfadj_vfrac */
#define ICMOCFADJ_VALUE_FORB_PAYOFF_BASIS (-1000) /* used by ICMOCFADJ_ADDL_FORB to setup payoff basis */

/* redefined old names for compatibility */
#define cfa_addl_loss_nfrac cfa_v_cfadj[ICMOCFADJ_ADDL_LOSS].cfadj_nfrac
#define cfa_addl_loss_vfrac cfa_v_cfadj[ICMOCFADJ_ADDL_LOSS].cfadj_vfrac
#define cfa_addl_loss_basis cfa_v_cfadj[ICMOCFADJ_ADDL_LOSS].cfadj_basis
#define ICMOADDLLOSS_BASIS_ORIGBAL   ICMOCFADJ_BASIS_ORIGBAL
#define ICMOADDLLOSS_BASIS_CURBAL    ICMOCFADJ_BASIS_CURBAL


/* CFASSUM_RATEMOD: Structure to hold CFASSUM forecasts for ratemod */
typedef struct {
    int cfaratemod_applyto ;   /* ICMORATEMOD_APPLYTO_xx */
#define ICMORATEMOD_APPLYTO_NONE 0x00 /* apply to no assets */
#define ICMORATEMOD_APPLYTO_UTRM 0x01 /* apply to MOD_TERMS_UNKNOWN_RATE assets only */
#define ICMORATEMOD_APPLYTO_ALL  0xFF /* apply to all type of assets */
    int cfaratemod_method ;    /* ICMORATEMOD_METHOD_xx */
#define ICMORATEMOD_METHOD_SUBTRACT  0 /* subtract ratemod value from forecasted value */
#define ICMORATEMOD_METHOD_HAIRCUT   1 /* multiply forecasted value with (1 - ratemod value) */
#define ICMORATEMOD_METHOD_REPLACE   2 /* replace forecasted value with ratemod value */
#define ICMORATEMOD_METHOD_CAP       3 /* cap forecasted value with ratemod value */
    int cfaratemod_ratebasis ; /* ICMORATEMOD_RATEBASIS_xx */
#define ICMORATEMOD_RATEBASIS_FORECASTED 0 /* ratemod value applied to forecasted rate */
#define ICMORATEMOD_RATEBASIS_START      1 /* ratemod value applied to starting rate */
    int cfaratemod_nrate;      /* length of cfa_ratemod_vrate vector */
    double *cfaratemod_vrate;  /* rate modification value vector */
#define ICMORATEMOD_VALUE_NA   (-999)   /* NA value for cfa_ratemod_vrate */
#define ICMORATEMOD_VALUE_LAST (-998)   /* LAST value for cfa_ratemod_vrate */
    } CFASSUM_RATEMOD ;

/* redefined old names for compatibility */
#define cfa_ratemod_method cfa_ratemod.cfaratemod_method
#define cfa_ratemod_nrate  cfa_ratemod.cfaratemod_nrate
#define cfa_ratemod_vrate  cfa_ratemod.cfaratemod_vrate

/* CFASSUM:  Cashflows forecasting assumptions, consisting of:
               scalar flags/settings,
               #cells in timeseries vectors, and
               pointers to timeseries vectors.

   The scalar flags/settings and the data in the timeseries vectors may be changed
   within the user-defined Prepay function.  However, the #cells and the
   pointers themselves, cannot be changed.

   Payment-to-payment mode note: The user-defined Prepay function may only change
   the scalar flags/settings only once per pool/loan, during the first period.
   The data in the timeseries vectors may be changed in any period. */

typedef struct {

    /* Controls that will be filled from icmo_cashflows() arguments.
       cfa_speed_type & values in vector *cfa_vspeeds
       are changeable within timeseries mode user-defined prepayment function.
       Do not apply if user-defined prepayment function is not provided.
       Do not apply to payment-to-payment mode. */
    int     cfa_speed_type ;      /* ICMOSPDT_xx  PSA/CPR/SMM... units */
    int     cfa_n_speeds ;        /* #cells in prepayment vector (+1) */
    double *cfa_vspeeds ;         /* prepayment rate vector cells */
    void ((CALLBK_FCN_PREFIX *cfa_index_fcn)(Args_index_fcn)) ; /* user index func */
    void ((CALLBK_FCN_PREFIX *cfa_speed_fcn)(Args_speed_fcn)) ; /* user prepayment func */
    void   *cfa_speed_fcn_userp;  /* user-appl ptr that can be used inside user prepayment func only */

    /* Controls that could be set before running cashflows,
       or in user-defined prepayment function.                           */
    int     cfa_loss_type ;       /* ICMODEFAULT_xx: loss model. 0=none */
    int     cfa_loss_n_defaults ; /* #mos proj. default rates. 1=const   */
    double *cfa_loss_vdefaults ;  /* %-of-model forecasts. [1]=next pmt  */
    int    *cfa_loss_vdeftypes ;  /* vector of ICMODEFAULT_xx (only if loss_type == ICMODEFAULT_VMIX). If used must hold cfa_loss_n_defaults elements */
    int     cfa_loss_n_severity ; /* #mos proj. severity rates. 1=const  */
    double *cfa_loss_vseverity;   /* severity-of-loss % forecasts.[1]=nxt*/
    int     cfa_loss_n_intseverity ; /* # of severity of intloss */
    double *cfa_loss_vintseverity;   /* severity of intloss */
    int     cfa_loss_recov_lag ;  /* #mos from default till recov. 0=none, if using cfa_loss_vrecov_lags, then this is the maximum recov_lag */
    double *cfa_loss_vpartliq_frac;  /* vector of length [cfa_loss_recov_lag] for partial liquidation frac within cfa_loss_recov_lag. [0]=partial liq on default months */
    double *cfa_loss_vinit_defaults; /* vector of init defaults to be liquidated within recov_lag. [1] for 1st per */
    double *cfa_loss_vinit_severity; /* vector of init severity within recov_lag. [1] for 1st per */
    int     cfa_loss_n_recov_lags;   /* length of vector for recov_lags */
    int    *cfa_loss_vrecov_lags;    /* vector for recov_lags */
    int     cfa_loss_servicer_advances; /*ICMOPI_ADVANCE_xx: deflt P+I paid by servicer*/
    double  cfa_loss_servicer_advance_p_frac; /* frac of p advance if partial */
    double  cfa_loss_servicer_advance_i_frac; /* frac of i advance if partial */
    int     cfa_loss_n_servicer_advance_frac;  /* length of cfa_loss_vservicer_advance_p_frac/cfa_loss_vservicer_advance_i_frac */
    double *cfa_loss_vservicer_advance_p_frac; /* vector of p advance frac. [1]=nxt*/
    double *cfa_loss_vservicer_advance_i_frac; /* vector of i advance frac. [1]=nxt*/
    int     cfa_loss_unsched_pay_dd;   /*0,or day that unsched pmt's are rcv'd*/
    int     cfa_loss_balloon_special;  /* ICMO_BALLOONLOSS_xx: loss at balloon*/
    int     cfa_loss_matur_special;    /* ICMO_MATURLOSS_xx: forecast default near maturity */
#define ICMO_MATURLOSS_0_AT_LAG     0  /* PSA standard - set 0 default loss_recov_lag months before maturity */
#define ICMO_MATURLOSS_YES          1  /* apply default up to maturity month */
    int     cfa_draw_type ;            /* ICMOSPDT_xx  CPR/SMM units */
    int     cfa_draw_n_rates ;         /* #mos Line-of-Credit draw forecasts */
    double *cfa_draw_vrates ;          /* LoC draw forecasts. [1]=nxt */
    int     cfa_draw_basis ;           /* ICMODRAW_BASIS_xx */
#define ICMODRAW_BASIS_BALANCE       0 /* apply draw rate based on balance */
#define ICMODRAW_BASIS_MAXDRAWAMT    1 /* apply draw rate based on max draw amt */
#define ICMODRAW_BASIS_RML_LOC       2 /* apply draw rate based on LOC for reverse mortgage loan */
#define ICMODRAW_BASIS_RML_START_LOC 3 /* apply draw rate based on simulation start LOC for reverse mortgage loan */
    int     cfa_include_prepaypenalty ; /* ICMOPREPAYPENALTY_xx: Prepayment penalty handling.
                            Settable if icmomisc_altercollat.altc_include_prepaypenalty set*/
    int     cfa_n_prepaypenalty_haircut_rates; /* #mos proj. prepaypenalty uncollected rates: (0 to 100) */
    double *cfa_vprepaypenalty_haircut_rates; /* proj. prepaypenalty uncollected rates: (0 to 100) */
    int     cfa_allow_monthly_prepay;  /* for non-monthly loan, allow monthly prepay */
    int     cfa_allow_monthly_default; /* for non-monthly loan, allow monthly default */
    int     cfa_prepay_method ;        /* ICMOPRP_METHOD_xx */
    int     cfa_revprp_method ;        /* ICMOREVPRP_METHOD_xx */
    int     cfa_loss_severity_method;  /* ICMOLOSSSEV_METHOD_xx */
    int     cfa_loss_severity_forb_method; /* ICMOLOSSSEV_FORB_METHOD_xx */
#define ICMOLOSSSEV_FORB_METHOD_STANDARD  0 /* use standard loss severity */
#define ICMOLOSSSEV_FORB_METHOD_FORBRECOV 1 /* use cfa_forb_recov_vfrac */
    int     cfa_loss_n_delayrec_frac ; /* length of delayed loss recov frac vector */
    double *cfa_loss_vdelayrec_frac ;  /* delayed loss recov frac vector [1]=1st delayed pmt */
    int     cfa_reremic_cfs_special;   /* ICMORCFS_xx: special handling of child deal's cashflows */
#define ICMORCFS_NORMAL              0x00 /* No special handling of child deal's cashflows */
#define ICMORCFS_SAVE_AS_SCHEDULED   0x01 /* Save child deal's cashflows as schedules for subsequent run */
#define ICMORCFS_USE_SAVED_SCHEDULED 0x02 /* Use child deal's cashflows previously saved as scheduled */
#define ICMORCFS_IGNORE_ABPD_CFS     0x04 /* Ignore child tranche cashflows received after tranche balance paid down */
    int     cfa_apply_contracted_balloon_extensions ; /* apply balloon extension from POOL_INFO */
    int     cfa_n_balloon_extensions;   /* # of balloon extension controls. Default = 1 */
    BALLOON_EXTENSION cfa_vballoon_extensions[ICMO_MAX_BALLOON_EXTENSIONS];  /* vector of balloon extension controls, starts from [0] */
    int     cfa_non_performing_n_flags;  /* length of cfa_non_performing_vflags */
    int    *cfa_non_performing_vflags;   /* vector of forecasted ICMO_NONPERFORMING_xx */
#define ICMO_NONPERFORMING_NONE      0  /* no action */
#define ICMO_NONPERFORMING_CURE      1  /* cure a NONPERFORMING asset to make it performing */
#define ICMO_NONPERFORMING_SEGREGATE 2  /* cure a NONPERFORMING asset to make it performing, but exclude them from aggregate forecasts */
#define ICMO_NONPERFORMING_FORCE     3  /* set an asset to NONPERFORMING status */
    int     cfa_cure_non_performing;     /* treatment of non-performing asset at the beginning of the cashflows forecasting */
#define CURE_NON_PERFORMING_NO        ICMO_NONPERFORMING_NONE       /* exclude non-performing assets from cashflows forecasting */
#define CURE_NON_PERFORMING_YES       ICMO_NONPERFORMING_CURE       /* treat nonperforming assets, as if performing */
#define CURE_NON_PERFORMING_SEGREGATE ICMO_NONPERFORMING_SEGREGATE  /* treat nonperforming assets, as if performing, but exclude them from aggregate forecasts */
    double  cfa_cure_non_performing_haircut_frac;  /* fraction of principal and deferred interest lost when a non-performing asset becomes performing again */
    int     cfa_ppc_curve_use ;        /* flag for how PPC unit is interpreted */
#define ICMO_PPCUSE_TOPMOST_DEAL     0 /* use PPC curves defined in top most deal */
#define ICMO_PPCUSE_CURRENT_DEAL     1 /* use PPC curves defined in current child deal */
    int     cfa_cash_reduce_nfrac;     /* length of cfa_cash_reduce_vfrac vector */
    double *cfa_cash_reduce_vfrac;     /* cash reduction frac vector [1]=1st frac */
    int     cfa_int_reduce_nrate;      /* length of cfa_int_reduce_vrate vector */
    double *cfa_int_reduce_vrate;      /* interest reduction rate vector [1]=1st rate */
    CFASSUM_CFADJ cfa_v_cfadj[ICMOCFADJ_N_TYPES]; /* addl CF adj assumptions */
    int     cfa_force_loan_amort;      /* force to use this loan amort regardless of pi_amort_type. Currently, only LOAN_AMORT_NONE/LOAN_AMORT_NONE_MAX/LOAN_AMORT_FULLY_AM are allowed, other values are ignored */
    CFASSUM_RATEMOD cfa_ratemod ;      /* RATEMOD forecast */
    CFASSUM_RATEMOD **cfa_v_addl_ratemodp ; /* NULL terminated addl RATEMOD forecasts */
    int     cfa_forb_recov_nfrac;      /* length of cfa_forb_recov_vrate vector */
    double *cfa_forb_recov_vfrac;      /* forbearance recovery frac vector */
    int     cfa_spserv_balance_basis;  /* ICMOSPSERV_BASIS_xxx */
#define ICMOSPSERV_BASIS_TOTALBAL    0 /* special servfee collected on total asset balance */
#define ICMOSPSERV_BASIS_DEFBAL      1 /* special servfee collected on default balance only */
    int     cfa_spserv_collect_nfrac;  /* length of cfa_spserv_collect_vfrac */
    double *cfa_spserv_collect_vfrac;  /* special servfee collection fraction */

    /* Controls that could be set before running cashflows,
       or in user-defined prepayment function (but once per deal in re-remic case). */
    int     cfa_use_hist_delinq;    /* HIST_DELINQ_USE_xx */
#define HIST_DELINQ_USE_NONE   0    /* assume zero hist delinq */
#define HIST_DELINQ_USE_ACTUAL 1    /* use actual hist delinq info */
#define HIST_DELINQ_USE_HIGH   2    /* assume 100% hist delinq */
    int     cfa_delinq_type ;       /* ICMODELINQTYPE_xxx: how cfa_vdelinq_rates are applied */
#define ICMODELINQTYPE_DEFAULT 0    /* applied as pct of period start bal */
#define ICMODELINQTYPE_AGG     1    /* applied as aggregate pct of simulation start bal */
#define ICMODELINQTYPE_ORIG    2    /* applied as pct of original bal */
    int     cfa_n_delinq_rates ;    /* #mos proj. delinq rates for cfa_vdelinq_rates and for cfa_vdelinqmon_rates[i]. 1=const */
    double *cfa_vdelinq_rates  ;    /* delinq pcts of outstanding loans */
#define ICMODELINQ_1MON        0    /* index to be use in cfa_vdelinqmon_rates for 1mo delinq */
#define ICMODELINQ_2MON        1    /* index to be use in cfa_vdelinqmon_rates for 2mo delinq */
#define ICMODELINQ_3MON        2    /* index to be use in cfa_vdelinqmon_rates for 3mo delinq */
#define ICMODELINQ_NMON        3    /* number of indexes in cfa_vdelinqmon_rates array */
    double *cfa_vdelinqmon_rates[ICMODELINQ_NMON]; /* detailed info for cfa_vdelinq_rates applicable to trigger */
    int     cfa_n_delinq_recov_frac; /* length of delinq payment recovery schedule */
    double *cfa_vdelinq_recov_frac;  /* delinq payment recovery schedule */
#define ICMO_DELINQ_RECOV_FRAC_END              (-1.) /* special cfa_vdelinq_recov_frac value to indicate when remaining delinq lost */
#define ICMO_DELINQ_RECOV_FRAC_REMAIN_CAP_FIRST (-2.) /* special cfa_vdelinq_recov_frac value to indicate remaining unrecovered delinq princ capitalized immediately at delinq period */
    int     cfa_total_repayment_rate ; /* TRUE means prepayment speed provided specifies the total balance reduction, including any losses */
#define TOTAL_REPAY_CAP_DEFAULTS         1 /* Prepay speed specifies total unscheduled balance reduction, default rate specifies involuntary.  Maximum defaults capped by prepay amount. Defaults don't affect scheduled $s */
#define TOTAL_REPAY_CAP_LOSSES           2 /* Prepay speed specifies total unscheduled balance reduction, default rate specifies involuntary.  Maximum liquidated (=defaults * severity) capped by prepay amount. Defaults don't affect scheduled $s.  Must be 0 lag. */
#define TOTAL_PRINCIPAL_CAP_DEFAULTS     3 /* Prepay speed specifies total unscheduled balance reduction, default rate specifies involuntary.  Defaults allowed to take eat into schedule $s. */
#define TOTAL_MAX_OF_PREPAY_AND_DEFAULTS 4 /* Maximum of prepay and defaults specifies total unsched. balance reduction.  Defaults don't affect scheduled $s */
#define TOTAL_MAX_OF_PREPAY_AND_DEFAULTS_PSA 5 /* Same as TOTAL_MAX_OF_PREPAY_AND_DEFAULTS but treat defaults as per PSA convention */
    double  cfa_total_repayment_cap_defaults_frac ; /* cap defaults to this fraction of total repayment.  A value of 0.0 corresponds to no cap (same behavior as entering a value of 1.0).  Used only if cfa_total_repayment_rate is non-zero. */
    void   *cfa_ppmdlp  ;             /* to forecasting assumptions specific to third party models */
DEPRECATED    int     cfa_draw_n_utilizations ;
DEPRECATED    double *cfa_draw_vutilizations;
    }  CFASSUM;


/* ICMO_ACCOUNT_HOLDBACK: structure used in ICMOADDLINFO_SET_ACCOUNT_HOLDBACK */
typedef struct {
    int     icmoahb_holdback_unit ; /* ICMOAHB_UNIT_xxx */
#define ICMOAHB_UNIT_FRAC     0  /* hold back fraction of available amt */
#define ICMOAHB_UNIT_AMOUNT   1  /* hold back this amount */
    int     icmoahb_n_holdback ;    /* length of icmoahb_v_holdback */
    double *icmoahb_v_holdback ;    /* holdback amt: [1] = 1st forecasted collat period */
    int     icmoahb_n_release_frac; /* length of icmoahb_v_release_frac */
    double *icmoahb_v_release_frac; /* holdback reverse frac: [1] = 1st per after holdback */
#define ICMOAHB_RELEASE_FRAC_END (-1.) /* special icmoahb_v_release_frac value to indicate when remaining holdback lost */
    } ICMO_ACCOUNT_HOLDBACK ;


/* ICMO_ADDLCF: structure used in ICMOADDLINFO_SET_GRP_ADDLCF */
typedef struct {
    int     icmoadc_unit ;          /* ICMOADC_UNIT_xxx */
#define ICMOADC_UNIT_AMOUNT       0 /* addcf in amount */
    int     icmoadc_alloc_basis;    /* allocation basis for allocating icmoadc_unit to lower groups if forecasted on non-ground group level */
#define ICMOADC_ALLOC_BASIS_PREVBAL   0 /* allocate pro-rata by group balance as of end of last period */
#define ICMOADC_ALLOC_BASIS_LOSSACCUM 1 /* allocate pro-rata by group loss accum */
    int     icmoadc_n_addlcf ;      /* length of icmoadc_v_addlcf */
    double *icmoadc_v_addlcf ;      /* addlcf amt: [1] = 1st forecasted collat period */
    } ICMO_ADDLCF ;

/* ICMOADC_TYPE_xxx: ICMOADC_TYPE used as inpval_int for ICMOADDLINFO_SET_GRP_ADDLCF */
#define ICMOADC_TYPE_REC_PREVLOSS 0 /* addl REC_PREVLOSS */
#define ICMOADC_N_TYPES           1 /* total number of ICMOADC_TYPE_xx types */


/* ICMO_COLLARS_CONTROL: structure to hold controls for calculating effective collars */

typedef struct {
   int ignore_generalized_bullet_pmts ; /* ignores speeds that result in bond getting paid off in one payment, regardless of what period the payment is in */
   int collars_start_month ; /* period that collar calculation value starts.  1 corresponds to first speed forecast. */
   void ((CALLBK_FCN_PREFIX *collars_speed_fcn)(Args_speed_fcn)) ; /* user prepayment func used in collar calculation */
} ICMO_COLLARS_CONTROL ;


/* ICMO_HORIZON_RETURN_CONTROL: structure to hold controls for icmo_horizon_return()  */

typedef struct ICMO_HORIZON_RETURN_CONTROL {
   int      ichrc_trno             ; /* tranche number */
   double   ichrc_face_amount      ; /* $ of face amount held, 0=entire tranche */
   YyyyMmDd ichrc_horizon_date     ; /* settlement date when bond will be sold for horizon return calculation */
   int      ichrc_horizon_nmos     ; /* If ichr_horizon_date=0 - number of month till bond will be sold for horizon return calculation */
   int      ichrc_begin_mode_py    ; /* ICMOPY_xxx, type of begin price/yield */
   double   ichrc_begin_priceyld   ; /* start-of-horizon price/yield of tranche */
   int      ichrc_end_mode_py      ; /* ICMOPY_xxx, type of end price/yield */
   double   ichrc_end_priceyld     ; /* end-of-horizon price/yield of tranche */
   int      ichrc_n_reinv_rates    ; /* # of elements in ichr_vreinv_rates vector */
   double  *ichrc_vreinv_rates     ; /* vector of reinvestment rates (%) */
   double   ichrc_reinv_spread     ; /* additive adjustment to ichr_vreinv_rates (%) */
   int      ichrc_reinv_indextype  ; /* use values of this index as reinvestment rates. Set via ICMO_HORIZON_REINV_INDEX(ICMOI_xxx)  */
   char    *ichrc_reinv_index_subname ;  /* NULL or subname for the index referred by ichrc_reinv_indextype */
   int      ichrc_stats_at_horizon ; /* fwd settle date to end-of-horizon */
   int      ichrc_return_mode      ; /* ICMOTOTRET_xxx -- return mode of horizon return calc */
   double   ichrc_interest_return  ; /* OUT: if nonNULL, return on int$ */
   double   ichrc_principal_return ; /* OUT: if nonNULL, return on princ$ */
   double   ichrc_reinvest_return  ; /* OUT: if nonNULL, return on reinv$ */
   double   ichrc_market_return    ; /* OUT: if nonNULL, return on sell$ */
} ICMO_HORIZON_RETURN_CONTROL ;

/* ICMOTOTRET_xx:  how horizon return should be reported by icmo_horizon_return()  */

#define ICMOTOTRET_ANNUAL       0  /* annualized return percentage */
#define ICMOTOTRET_HORIZON      1  /* percentage over horizon period */
#define ICMOTOTRET_BEY          2  /* bond equivalent yield */
#define ICMOTOTRET_DOLLARS      3  /* dollar proceeds over horizon period */


/* ICMODDA: structure for one DEAL_DETERMINED_ASSUMPTION */

typedef struct  {
    int    icmodda_param_intval ;
    } ICMODDA_PARAM_RECOV_LAG ;

typedef struct  {
    double icmodda_param_dblval ;
#define ICMODDA_PARAM_DBLVAL_AGGREGATE  (999.) /* value determined by payrule in aggregate */
    } ICMODDA_PARAM_LOSS_SEVERITY ;

typedef struct {
    char      *icmodda_next ;           /* next in link list */
    int        icmodda_type ;           /* ICMODDA_xxx */
#define ICMODDA_RECOV_LAG            1  /* deal determine RECOV_LAG */
#define ICMODDA_LOSS_SEVERITY        2  /* deal determine LOSS_SEVERITY */
    union
        {
        ICMODDA_PARAM_RECOV_LAG     param_recov_lag     ; /* param for ICMODDA_RECOV_LAG */
        ICMODDA_PARAM_LOSS_SEVERITY param_loss_severity ; /* param for ICMODDA_LOSS_SEVERITY */
        } icmodda_param ;
    } ICMODDA ;


/* PREPCURVE:  PSA alike prep curve info */

typedef struct _PREPCURVE {
    int    ppc_rising_pers ;  /* # of month CPR rises */
    double ppc_start_cpr ;    /* CPR at month 1 */
    double ppc_end_cpr ;      /* CPR at end of rising per */
    double ppc_step_cpr ;     /* CPR increases for each month */
    double ppc_max_cpr ;      /* CPR maximum in any given month */
    char   *ppc_name ;        /* name of PPC curve if provided */
    double *ppc_ramp ;        /* vector of generic ramp speeds.  Element [1] is for age = 1 */
    int    ppc_speed_type ;   /* speed type of ramp so we can use something other than CPR */
    int    ppc_ignore_age_dep ; /* override default that all prepayment curves index off the loan age */
    } PREPCURVE ;


/* CDOTEST_MODIV: detail info of Moody's diversity score test */
typedef struct {
    /* Issuer info */
    int     cdotestmodiv_n_issuer;           /* # of issuers */
    int    *cdotestmodiv_issuer_indcode;     /* issuer industry code */
    char  **cdotestmodiv_issuer_names;       /* issuer names */
    double *cdotestmodiv_issuer_bals;        /* issuers balances */
    double *cdotestmodiv_issuer_unitscore;   /* issuers unit scores */
    /* Industry info */
    int     cdotestmodiv_n_indstry;          /* # of industry */
    int    *cdotestmodiv_indstry_codes;      /* industry codes */
    char  **cdotestmodiv_indstry_names;      /* industry names */
    double *cdotestmodiv_indstry_unitscores; /* industry unit scores */
    double *cdotestmodiv_indstry_divscores;  /* industry diversity scores */
    }  CDOTEST_MODIV ;

/* CDOTEST_DEBT_RATING: detail info of DEBT_RATING info */
typedef struct {
    int     cdotestdebt_n_assets;            /* # of assets that contributed */
    char  **cdotestdebt_asset_names;         /* names of assets */
    double *cdotestdebt_asset_ratings;       /* ratings of assets */
    double *cdotestdebt_asset_balances;      /* balances of assets */
    }  CDOTEST_DEBT_RATING ;

/* CDOTEST: CDO test info */
typedef struct {
    int    cdotest_type ;  /* CDOTEST_xx */
    char  *cdotest_name ;  /* CDOTEST name */
    int    cdotest_status; /* CDOTESTSTATUS_xx */
    double cdotest_value ; /* values of tests */
    char  *cdotest_errmsg; /* errors in calculating CDOTEST */
    void  *cdotest_detailp; /* detailed info depending on cdotest_type */
    int    cdotest_detail_type; /* CDOTESTDETAILTYPE_xx: indicate what structure cdotest_detailp is */
#define CDOTESTDETAILTYPE_NONE        0  /* cdotest_detailp not used */
#define CDOTESTDETAILTYPE_MODIV       1  /* cdotest_detailp is CDOTEST_MODIV */
#define CDOTESTDETAILTYPE_DEBT_RATING 2  /* cdotest_detailp is CDOTEST_DEBT_RATING */
    }  CDOTEST ;

/* CDOTEST_xx: CDOTEST types */
#define CDOTEST_UNKNOWN               -1 /* not used */
#define CDOTEST_MD_DIVERSITY           0 /* Moody's diversity score */
#define CDOTEST_MD_AVG_DEBT_RATING     1 /* Moody's average debt rating */
#define CDOTEST_SP_MIN_AVG_REC_RATE    2 /* S&P's minimum average recovery rate */
#define CDOTEST_AVG_LIFE               3 /* Weighted Average life of collateral */
#define CDOTEST_MD_DIVERSITY_NP        4 /* Moody's diversity score (including non-performing assets) */
#define CDOTEST_MD_AVG_DEBT_RATING_NP  5 /* Moody's average debt rating (including non-performing assets) */
#define CDOTEST_SP_MIN_AVG_REC_RATE_NP 6 /* S&P's minimum average recovery rate (including non-performing assets) */
#define CDOTEST_AVG_LIFE_NP            7 /* Weighted Average life of collateral (including non-performing assets) */
#define CDOTEST_FT_AVG_DEBT_RATING     8 /* Fitch's average debt rating */
#define CDOTEST_FT_AVG_DEBT_RATING_NP  9 /* Fitch's average debt rating (including non-performing assets) */
#define CDOTEST_MISC_BASE             10 /* starting point for CDOTESTs customly defined in CDI */
#define CDOTEST_MISC(i) (CDOTEST_MISC_BASE+(i)-1) /* ith MISC type CDOTEST */
#define CDOTEST_MAX_N_TYPES        110 /* Max of CDOTEST types allowed */

/* CDOTESTSTATUS_xx: status of CDOTEST calculation */
#define CDOTESTSTATUS_NA  0  /* CDOTEST value not calculated */
#define CDOTESTSTATUS_OK  1  /* CDOTEST value calculated */

/* DEALSTATS: link list of DEAL stats as reported */
typedef struct {
    char *dealstats_next ;       /* NULL, or to next in linked list */
    char *dealstats_name ;       /* Data item name */
    char *dealstats_strval ;     /* String Data value */
    double dealstats_dblval ;    /* Number Data value */
    } DEALSTATS ;


/* RBC_INFO: Info structure describing collateral returned by icmo_replace_buy_collat_fcn or passed to icmo_buy_collat*/

typedef struct {
    char      *rbc_next ;      /* ptr to next in the link list */
    POOL_INFO *rbc_pip ;       /* POOL_INFO structure for newly created pip, pip from collat_list or from reinv_collat*/
    int        rbc_pip_type ;  /* RBC_PIP_xx type of POOL_INFO rbc_pip */
#define RBC_PIP_SAME         0 /* rbc_pip pointing to pip passed to icmo_replace_buy_collat_fcn. pip will be added to collat list */
#define RBC_PIP_NEW          1 /* rbc_pip is newly created by icmo_make_pip(). pip will be added to collat list */
#define RBC_PIP_FROM_COLLAT  2 /* rbc_pip is from collat_list. Will scale existing pip balance*/
#define RBC_PIP_RECOLLAT_GRP 3 /* Will scale balance of existing pips in group rbc_groupno. rbc_pip is NULL */
    double     rbc_amt ;       /* amount (curbal) of additional collateral. Should be provided in asset currency  */
    int        rbc_groupno ;   /* group# (possibly subset) in which to reinvest (for rbc_pip_type of RBC_RECOLLAT_IN_GRP and RBC_HOLD) */
INTEX_INTERNAL_USE_ONLY    void      *rbc_internal ;   /* for internal use */
    }  RBC_INFO ;


/* BUY_COLL_xx : Parameter buy_collat_type passed to icmo_buy_collat */
#define  BUY_COLL_PRINC      0 /* COLL("PRINC") bucket used for icmo_buy_collat function  */
#define  BUY_COLL_SCHEDULED  1 /* COLL_P_MISC("SCHEDULED") bucket used */
#define  BUY_COLL_PREPAID    2 /* COLL_P_MISC("PREPAID")   bucket used */
#define  BUY_COLL_RECOVERED  3 /* COLL_P_MISC("RECOVERED") bucket used */

/* SELLTO_COLL_xx : Parameter sell_collat_type passed to icmo_sell_collat() */
#define SELLTO_COLL           0 /* sell proceeds from icmo_sell_collat function will be added to COLL("PRINC") and accrued int will be added to COLL("INT") */
#define SELLTO_COLL_PRINC_AMT 1 /* same as SELLTO_COLL above but with given princ payment amount in asset currency instead of a price in sell_collat_price100 parameter */


/* COLLAT_GROUP:  info about defined collateral groups */

typedef struct _COLLAT_GROUP {
    int  grp_groupno ;             /* group# (>=0) */
    char grp_name[ICMO_MAX_GRPNAM_CHARS+1] ; /* meaningful name of group */
    char grp_is_pseudo  ;          /* ICMO_PSEUDOGROUP_xx: */
    char grp_is_ground_group ;     /* TRUE if group is "ground" group. */
    char grp_prospectus_group ;    /* indicates whether group is defined in prospectus  */
#define  PROSPECTUS_GROUP_NA  0    /* model does not identify prospectus groups   */
#define  PROSPECTUS_GROUP_YES 1    /* group is defined in prospectus  */
#define  PROSPECTUS_GROUP_NO  2    /* group is a modeling construct, not defined in prospectus  */
    PREPCURVE *grp_ppc_info ;   /* customized prep curve (PPC) for this group */
    PREPCURVE *grp_draw_ppc_info; /* customized draw curve (PPC) for this group */
    int  grp_pricing_units ;       /* If >0, group's ICMOSPDT_xx scale */
    int  grp_pricing_nspeed ;      /* #elements in pricing vector +1 */
    int  grp_pricing_draw_units ; /* If >0, group's draw rate scale */
    int  grp_pricing_draw_nspeed ; /* #elements in pricing draw vector +1 */
    int  grp_aggunion_id[ICMO_N_AGG_UNION_FOR] ;  /* settable id to mark groups inclusion to aggunion indexed by ICMO_AGG_UNION_FOR_xx */
#define  grp_agg_union_id   grp_aggunion_id[ICMO_AGG_UNION_FOR_AGGMDR]
    double *grp_pricing_vspeed ;   /* Pricing speed vector from [1] */
    double *grp_pricing_draw_rate_vspeed ;  /* Pricing draw rate vector from [1] */
    double grp_mastserv_rate ;    /* Master servicer rate strip % */
    double grp_trustee_rate ;     /* Trustee rate strip % */
    double grp_hazard_limit ;  /* Special hazard limit $ (0-if formula)*/
    double grp_bankrp_limit ;  /* Bankruptcy losses limit $(0-if formula)*/
    double grp_fraud_limit ;   /* Fraud losses limit $ (0-if formula)*/
    double grp_cdu_hazard_amt ;    /* Starting special hazard loss $ */
    double grp_cdu_bankrp_amt ;    /* Starting bankruptcy losses $ */
    double grp_cdu_fraud_amt ;     /* Starting fraud losses $ */
    double grp_lastcdu_hazard_amt ;    /* Starting special hazard loss $ */
    double grp_lastcdu_bankrp_amt ;    /* Starting bankruptcy losses $ */
    double grp_lastcdu_fraud_amt ;     /* Starting fraud losses $ */
    int    grp_user_shiftint_nstepdowns ;  /* len of user override.. */
    double *grp_user_shiftint_vstepdowns; /* ..vector of reductions */
    LOANSTAT *grp_cdu_loanstat_list [ICMO_MAX_GROUP_LOANSTATS] ;
                                 /* to group loanstat info */
    LOANSTAT *grp_latest_cdu_loanstat_list [ICMO_MAX_GROUP_LOANSTATS] ;
                                 /* to latest CDU group loanstat info */
    double grp_pass_thru_rate ;  /* Defined/implicit bonds coup% */
    int    grp_has_xrs ;         /* ICMO_XRS_STRUCTURE_xx: indicates existence of XRS structure on group */
#define ICMO_XRS_STRUCTURE_NONE     0  /* Group does not have XRS structure */
#define ICMO_XRS_STRUCTURE_UNIFORM  1  /* group has explicit XRS structure, or all subgroups have identical XRS structures; in this case, grp_n_xrs > 0 */
#define ICMO_XRS_STRUCTURE_MIXED    2  /* all subgroups have XRS structures, but structures are not identical */
#define ICMO_XRS_STRUCTURE_PARTIAL  3  /* some, but not all, subgroups have XRS structures */
    int    grp_n_xrs  ;           /* # of XRS the group has */
    ICMOXRS **grp_vxrsp ;         /* vector of the XRS structures */
    PREPHIST *grp_psa ;   /* group's prepayment history, in PSA units*/
    PREPHIST *grp_cpr ;   /* group's prepayment history, in CPR units*/
    PREPHIST *grp_speed_in_pricing_units ;   /* group's prepayment history, in PRICING units */
    float *grp_1mo_psa_hist ;      /* historical 1mo PSA rate vector */
    float *grp_1mo_cpr_hist ;      /* historical 1mo CPR rate vector */
    float *grp_1mo_speed_in_pricing_units_hist ; /* historical 1mo rate vector in PRICING units */
#define  PREPHIST_1MO_VECT_LENGTH 12 /* max # of 1mo PSA/CPR supported */
    int grp_callable_by_investor ; /* TRUE if this group is callable */
    int grp_servicer_advance ;     /* SERVICER_ADVANCE_xx */
    char *grp_virtual_reremic;     /* virtual re-remic dealname */
    double grp_cdu_loss_accum ;    /* Accum loss$ as of base CDU */
    double grp_lastcdu_loss_accum; /* Accum loss$ as of latest CDU */
    double grp_origbal ;           /* Group balance at deal closing */
    POOL_INFO *grp_collat_wavg;    /* to wt avg collateral "pool" */
    char *grp_pnote_tag ;          /* OLD field: always grp_pnote_v_tags[0] for backward compatibility */
    char **grp_pnote_v_tags ;      /* null terminated PNOTE tags for PNOTE group */
    char *grp_fullname ;           /* descriptive name of the group */
    char grp_is_pure_io ;          /* non-zero if group is pure IO */
    }  COLLAT_GROUP ;

/* ICMO_PSEUDOGROUP_xx: group pseudo types */
#define ICMO_PSEUDOGROUP_NO          0 /* ordinary collateral group */
#define ICMO_PSEUDOGROUP_SUBSET      1 /* subset group */
#define ICMO_PSEUDOGROUP_XRS         2 /* pseudogroup representing ratio-stripped collateral bands */
#define ICMO_PSEUDOGROUP_XRS_IO      3 /* pseudogroup representing IO strip */
#define ICMO_PSEUDOGROUP_PNOTE       4 /* PNOTE subset group */
#define ICMO_PSEUDOGROUP_PNOTEMAIN   5 /* PNOTE_MAIN subset group */
#define ICMO_PSEUDOGROUP_PNOTETRUST  6 /* PNOTE_TRUST subset group */
#define ICMO_PSEUDOGROUP_HMBS        7 /* subset group representing HMBS participations */

#ifdef DEFINE_ICMO_PSEUDOGROUP_TYPE_NAMELIST
char *icmo_pseudogroup_type_namelist[] = {
  "NONE",
  "SUBSET",
  "XRS",
  "XRS_IO",
  "PNOTE",
  "PNOTEMAIN",
  "PNOTETRUST",
  "HMBS",
  NULL };
#else
extern char *icmo_pseudogroup_type_namelist[] ;
#endif

/* SERVICER_ADVANCE_xx: delinq PI advance flag */

#define SERVICER_ADVANCE_MIXED   (-1)  /* only for grp with sub-grps */
#define SERVICER_ADVANCE_UNKNOWN  0  /* not confirmed with prosubs */
#define SERVICER_ADVANCE_ALWAYS   1  /* always advance */
#define SERVICER_ADVANCE_NEVER    2  /* never advance */
#define SERVICER_ADVANCE_LIKELY   3  /* advance unless not recoverable */

/* PPMDL_PARAMS: Structure to create linked list of parameters for 3rd party model */

typedef struct PPMDL_PARAMS PPMDL_PARAMS ;
struct PPMDL_PARAMS{
    PPMDL_PARAMS  *pp_next ;       /* Pointer to next parameter in linked list. */
#define PTP_NAME_LEN 50       /* Max length of a  paramter name  */
    char           pp_name[PTP_NAME_LEN + 1] ; /* Name of this  parameter */
    double         pp_value ;                  /*  parameters value */
    }  ;



/* ICMO_PPMDLL_INFO: Structure for third party model containing params and internal information */

typedef struct {
    PPMDL_PARAMS *ppi_pp ; /* to linked list of PPMDL_PARAMS */
    char         *ppi_ppmdlp ; /* to internal third party info */
    } ICMO_PPMDL_INFO ;


/* ICMO_INDEX_FCAST: index forecast structure for icmo_set_index_forecast () */

typedef struct _ICMO_INDEX_FCAST {
    int       inf_index_fcast_method ;        /* method of applying vindex_rates */
#define ICMOINDEX_FCAST_MONTHLY_FROM_REQ  0   /* vindex_rates are monthly values and vindex_rates[1] will apply to icmo_1st_index_forecast, i.e. starts from the first required forecast. This method used in old icmo_index_set() fcn */
#define ICMOINDEX_FCAST_MONTHLY_ANCHORED  1   /* vindex_rates are monthly values and vindex_dates[1] should be used as starting date on which vindex_rates[1] would be reported */
#define ICMOINDEX_FCAST_EXPLICIT_DATES    2   /* vindex_dates determine dates when vindex_rates would be reported  */
#define ICMOINDEX_FCAST_FOR_PORTFOLIO_DM  3   /* used to supply forecast of index rates for discount margin calculations in icmo_portf_stats() */
    double   *inf_vindex_rates ;              /* forecasted index rates. vindex_rates[0] has special meaning */
    YyyyMmDd *inf_vindex_dates ;              /* index determination dates corresponds to vindex_rates. vindex_dates[0] not used*/
    int       inf_nindex_rates ;              /* # of elements in vindex_rates and vindex_dates */
    int       inf_index_determ_date_method ;  /* what date should be used as index determination date */
#define ICMOINDEX_DETERMDATE_DEFAULT       0  /* use index determination date specified by model explicitly or as default (e.g. 2 businessday prior to accrual start date for tranches) */
#define ICMOINDEX_DETERMDATE_ACCRUAL_START 1  /* use accrual start date as index determination date for tranches ( no businessday adjustment for reporting) */
    int       inf_use_proxy ;                 /* TRUE - use proxy info if available for the index defined within a deal, FALSE - always use provided index values, even for proxy indexes  */
    }  ICMO_INDEX_FCAST  ;


/* INDEX_SUBINFO: fine resolution info for index by subnames, e.g. RDELAY, 0DELAY, ... */

typedef struct _INDEX_SUBINFO {
    char  *index_subinfo_next ;  /* Pointer to next info in linked list */
    char   index_subinfo_subname [ICMO_MAX_INDEXSUBNAME_CHARS+1];
    int    index_subinfo_1st_fcast_is_known; /*# of months vindex[i] filled from IDX file*/
    double index_subinfo_curval ;  /* cur index rate from IDX file */
    double index_subinfo_latestval ;  /* latest index rate from IDX file */
    double index_subinfo_tax_index ; /* tax index by subname */
    double index_subinfo_init_index ; /* index if specified in CDI by INITIAL INDEX, by subname */
    }  INDEX_SUBINFO  ;


/* ICMO_INDEX_PROXY:  Info about proxy index for the index defined within a deal, e.g. DEFINE INDEX  _RSV_REINVEST
                      Accessible via ICMOADDLINFO_GET_INDEX_PROXY */

typedef struct {
   int indproxy_indextype ;    /* ith_index in ICMO_INDEX_LIST  or ICMOI_DUMMY */
   double indproxy_spread ;   /* spread to proxy index */
   }  ICMO_INDEX_PROXY;


/* ICMO_INDEX: index info structure */

typedef struct  {
    int      index_referenced ;            /* flag if index used in deal */
#define ICMOINDEX_REFERENCED_NO             0  /* index is not used in deal */
#define ICMOINDEX_REFERENCED_YES            1  /* index is     used in deal */
#define ICMOINDEX_REFERENCED_AS_PROXY_ONLY  2  /* index is used only as a PROXY for some other index in deal */
#define ICMOINDEX_REFERENCED_INACTIVE       3  /* index used for descriptive info only, no need to provide forecasted values for cashflows */
    char     *index_name ;          /* index name ( e.g. COFI_11 )*/
    char     *index_full_name ;     /* full  index name           */
    INDEX_SUBINFO *index_subinfop;  /* fine resolution index info referenced by subname */
    double   index_curval ;         /* cur index rates */
    double   index_initval ;        /* initial index rate as of deal issuance as specified in the CDI */
    double   index_taxval ;         /* rate for tax calc */
    char     *index_warn_msg ;      /* NULL or info message*/
    char     index_has_proxy ;      /* TRUE if index has associated proxy index for parent or any child deal */
#define ICMOINDEX_PROXY_NO       0  /* index does not have proxy information */
#define ICMOINDEX_PROXY_ALL      1  /* index has proxy info for all  deals in deal tree that require the index, if topmost deal */
#define ICMOINDEX_PROXY_SOME     2  /* index has proxy info for some deals in deal tree that require the index, if topmost deal */
    }  ICMO_INDEX  ;


/* ICMO_INDEX_IDL:  Index description info from INDEXES.IDL file  */

typedef struct {
    char *indidl_name  ;        /* index name ( e.g. COFI_11 )*/
    char *indidl_fullname ;     /* full  index name           */
    char *indidl_type ;         /* index type string "S","I", ..    */
    char *indidl_curcode ;      /* associated currency code  */
    char *indidl_estimated_ref ;           /* NULL or name of the standard index used for approximation for this index */
    double indidl_estimated_ref_spread ;   /* spread to estimated_ref index */
    YyyyMmDd indidl_known_history_since ;  /* 0 if Known History = NO; Date since Known History  */
    }  ICMO_INDEX_IDL;


/* EXCHANGE: info about tranche exchange relationships */

#define ICMO_MAX_EXCHANGE_TRANCHES 50 /* Max num tranches in an exchange*/
typedef struct _EXCHANGE {
    char   *eg_next ;             /* ptr to next EXCHANGE in link list */
    int    eg_n_orig_tranches ;   /* # of original tranches */
    int    eg_orig_vtrnum [ICMO_MAX_EXCHANGE_TRANCHES];
                                  /* vector of original tr. numbers */
    ICMO  *eg_orig_icmop ;        /* ICMO structure of deal containing original tranches */
    int    eg_n_alt_tranches ;    /* # of alternate tranches */
    int    eg_alt_vtrnum [ICMO_MAX_EXCHANGE_TRANCHES];
                                  /* vector of alternate tr. numbers */
    YyyyMmDd eg_matur_date; /* if non-zero, termination date of exchange */
    double eg_orig_vtrfrac[ICMO_MAX_EXCHANGE_TRANCHES];
                                  /* vector of original tr. fractions */
    double eg_alt_vtrfrac[ICMO_MAX_EXCHANGE_TRANCHES];
                                  /* vector of alternate tr. fractions */
    int    eg_wrapped ;           /* ICMO_EG_WRAPPED_xx */
#define ICMO_EG_WRAPPED_NONE  0   /* nothing wrapped */
#define ICMO_EG_WRAPPED_INT   1   /* interest component is wrapped, so may not match between orig and alt */
#define ICMO_EG_WRAPPED_PRINC 2   /* principal component is wrapped, so may not match between orig and alt */
#define ICMO_EG_WRAPPED_CF    3   /* both interest and principal components are wrapped, so may not match between orig and alt */
    int   eg_type ;               /* ICMO_EG_TYPE_xx: type of exchange */
#define ICMO_EG_TYPE_UNKNOWN      0
#define ICMO_EG_TYPE_MACR         1
#define ICMO_EG_TYPE_CURRENCY     2
#define ICMO_EG_TYPE_CHILD        3
#define ICMO_EG_TYPE_FREQUENCY    4
#define ICMO_EG_TYPE_CROSSED_SUBS 5
#define ICMO_EG_TYPE_PNOTE        6
#define ICMO_EG_TYPE_FIXFLT       7
#define ICMO_EG_TYPE_NEGAM        8
#define ICMO_EG_TYPE_MODELING     9
#define ICMO_EG_TYPE_UNCAPPING   10
    }  EXCHANGE ;


/* OPTREDEEM: Info about optional redemption. Forms linked list. */

typedef struct _OPTR_OWNER {
    int optro_type ;  /* OPTR_OWNER_xx */
#define OPTR_OWNER_ISSUER     0  /* owner is issuer */
#define OPTR_OWNER_TRANCHE    1  /* owner is a tranche in the deal */
#define OPTR_OWNER_EXTERNAL   2  /* owner is a third party investor */
    int optro_num  ;  /* trno if optro_type is OPTR_OWNER_TRANCHE */
    }  OPTR_OWNER ;

#define OPTRWTF_MAX_TRANCHES ICMO_MAX_CDI_GROUPS
typedef struct _OPTRW_TRANCHE_FRAC {
    double optrwtf_frac ;  /* may call if target tranches frac. is less than this */
    int optrwtf_nums[OPTRWTF_MAX_TRANCHES+1]; /* vector of trno's terminated by -1 */
    }  OPTRW_TRANCHE_FRAC ;

typedef struct _OPTRW_GROUP_FRAC {
    double optrwgf_frac ;  /* may call if target group frac. is less than this */
    int *optrwgf_nums ;    /* vector of groupno's terminated by -1 */
    int optrwgf_use_begin_frac ; /* TRUE if group frac is calculated at beginning of a period */
    }  OPTRW_GROUP_FRAC ;

typedef struct _OPTRW_CUSTOM_FRAC {
    char *optrwcf_next;         /* next in linked list */
    char *optrwcf_name  ;       /* custom frac name */
    double optrwcf_frac ;       /* may call if custom frac is less than this */
    char *optrwcf_expr_toptkn;  /* expr for custom frac */
    }  OPTRW_CUSTOM_FRAC ;

typedef struct _OPTR_WHEN {
    double optrw_deal_frac;  /* may call if deal frac. less than this */
    double optrw_supported_deal_frac; /* may call if supported deal frac. less than this */
    double optrw_coll_frac;  /* may call if collat frac. less than this */
    double optrw_begin_coll_frac; /* may call if begining collat frac. less than this */
    OPTRW_GROUP_FRAC *optrw_group_fracp;  /* non-NULL if may call with group fraction less than targets */
    OPTRW_TRANCHE_FRAC *optrw_tranche_fracp;  /* non NULL if may call with tranche fraction less than target */
    OPTRW_CUSTOM_FRAC *optrw_custom_fracp;  /* non NULL if may call with custom fraction less than target */
    YyyyMmDd optrw_date ;    /* may call if date >= this */
    char *optrw_expr_toptkn; /* may call if this expr evals to TRUE */
    char *optrw_addl_cond_expr_toptkn; /* ADDITIONAL_CONDITION expression */
    char *optrw_addl_cond_name ; /* descriptive name of the ADDITIONAL_CONDITION */
    int optrw_before_payrules; /* TRUE if to call before making normal payment */
    int optrw_paymonth_only; /* TRUE if to call on deal paymonth or specific tranche paymonth only */
#define OPTR_WHEN_PAYMONLY_TRBASE  1000  /* base code for paymonth_only of tranche */
    int optrw_multcon_flag;  /* OPTR_WHEN_MULTCON_xx */
#define OPTR_WHEN_MULTCON_ANY  0  /* may call when any conditions met */
#define OPTR_WHEN_MULTCON_ALL  1  /* may call when all conditions met */
    }  OPTR_WHEN  ;

typedef struct _OPTR_TARGET {
    int optrt_type ;  /* OPTR_TARGET_xx */
#define OPTR_TARGET_DEAL    0  /* target is the whole deal */
#define OPTR_TARGET_GROUP   1  /* target is a collat group */
#define OPTR_TARGET_TRANCHE 2  /* target is a tranche */
#define OPTR_MAX_TARGETS  (ICMO_MAX_CDI_GROUPS+2)  /* max number of targets allowed */
    int optrt_nums[OPTR_MAX_TARGETS+2]; /* vector of groupno/trno terminated by -1 */
    int optrt_as_termination; /* target to be redeemed per deal termination logic */
    }  OPTR_TARGET ;

typedef struct _OPTR_PRICE {
    char *optrp_prn_toptkn ;  /* SETTABLE_EXPRESSION: principal part of the redeem price */
    char *optrp_int_toptkn ;  /* interest  part of the redeem price */
    char *optrp_fee_toptkn ;  /* expense   part of the redeem price */
    }  OPTR_PRICE ;

typedef struct _OPTR_DISTR {
    int optrd_prn_type ;  /* OPTR_DISTR_P_xx */
#define OPTR_DISTR_P_PROCEEDS             0  /* pay outstanding balance up to available cash */
#define OPTR_DISTR_P_PAR                  1  /* pay tranche outstanding balance */
#define OPTR_DISTR_P_RULES                2  /* pay tranche by optrd_payrules */
#define OPTR_DISTR_P_WATERFALL            3 /* pay tranche by normal waterfall */
#define OPTR_DISTR_P_WATERFALL_ALL_BLOCKS 4 /* same as OPTR_DISTR_P_WATERFALL, but also force to be paydate for all blocks */
    int optrd_int_type ;  /* OPTR_DISTR_I_xx */
#define OPTR_DISTR_I_NONE   0  /* pay no int for the redemption */
#define OPTR_DISTR_I_ACCRUE 1  /* pay int accrued to redemption date */
#define OPTR_DISTR_I_RULES  2  /* pay tranche by optrd_payrules */
    char *optrd_payrules ;     /* payrule section name to distribute */
    }  OPTR_DISTR ;

typedef struct _OPTR_STATUS {
    YyyyMmDd optrs_1st_date ;  /* 1st date this OPTREDEEM becomes active*/
    YyyyMmDd optrs_did_date ;  /* date this OPTREDEEM exercised */
    double   optrs_prn_price;  /* principal part of the redeem price */
    double   optrs_int_price;  /* interest  part of the redeem price */
    double   optrs_fee_price;  /* expense   part of the redeem price */
    }  OPTR_STATUS ;

typedef struct _OPTREDEEM {
    char  *optr_next ;  /* Pointer to next info in linked list */
    char optr_name[ICMO_MAX_TRNAM_CHARS + 1] ; /* name of optredem  */
    int  optr_optrno ;  /* unique ID for this OPTREDEEM structure */
    int  optr_type ;         /* ICMO_OPTRTYPE_xx */
    int  optr_subtype ;      /* ICMO_OPTRSUBTYPE_xx */
    char *optr_full_name ;   /* string providing full name of the redemption */
    char *optr_description;  /* string describing the nature of the redemption */
    OPTR_OWNER  optr_owner ; /* sub-structure for ownership */
    OPTR_WHEN   optr_when  ; /* sub-structure for condition test */
    OPTR_TARGET optr_target; /* sub-structure for redeem target */
    OPTR_PRICE  optr_price ; /* sub-structure for redeem price */
    OPTR_DISTR  optr_distr ; /* sub-structure for distribution to tr's */
    OPTR_STATUS optr_status; /* sub-structure for updated status */
    OPTR_STATUS optr_cdu_status; /* updated status in CDU */
    }  OPTREDEEM  ;

/* OPTR_WHEN_STATUS: structure returned by ICMOADDLINFO_GET_OPTREDEEM_INFO/ICMOADDLINFO_INPVAL_OPTREDEEM_INFO_WHEN_STATUS */

typedef struct _OPTR_WHEN_STATUS {
    int optrws_can_redeem ; /* OPTR_WHEN_STATUS_xxx */
#define OPTR_WHEN_STATUS_UNKNOWN  0 /* redeem condition is UNKNOWN */
#define OPTR_WHEN_STATUS_NO       1 /* redeem condition is FALSE */
#define OPTR_WHEN_STATUS_YES      2 /* redeem condition is TRUE */
#define OPTR_WHEN_STATUS_REDEEMED 3 /* already redeemed */
    double optrws_deal_frac; /* cur deal frac value if used in OPTR_WHEN */
    double optrws_supported_deal_frac; /* cur supported deal frac value if used in OPTR_WHEN */
    double optrws_coll_frac; /* cur coll frac value if used in OPTR_WHEN */
    double optrws_tranche_frac; /* cur tranche frac value if used in OPTR_WHEN */
    double optrws_group_frac; /* cur group frac value if used in OPTR_WHEN */
    double *optrws_v_custom_fracs; /* vector of cur custom frac values if used in OPTR_WHEN  */
    } OPTR_WHEN_STATUS ;


#define ICMO_OPTRTYPE_OPTIONAL  0  /* Optional redemption */
#define ICMO_OPTRTYPE_MANDATORY 1  /* Mandatory redemption */
#define ICMO_N_OPTRTYPE   (ICMO_OPTRTYPE_MANDATORY + 1)

#define ICMO_OPTREXEC_NO        0  /* Do not call */
#define ICMO_OPTREXEC_FCN       1  /* Call at earliest opportunity, unless overriden by function */
#define ICMO_OPTREXEC_YES       2  /* Call at earliest opportunity */

/* ICMO_OPTRSUBTYPE_xx: descriptive subtype of redemption */
#define ICMO_OPTRSUBTYPE_UNKNOWN           0  /* unknown */
#define ICMO_OPTRSUBTYPE_CLEANUP           1  /* standard x% of collateral or bonds */
#define ICMO_OPTRSUBTYPE_AUSTRALIAN_10PCT  2  /* Certain Australian deals must be called at 10% */
#define ICMO_OPTRSUBTYPE_AGENCY_CALLABLE   3  /* GNM10C10 etc. */
#define ICMO_OPTRSUBTYPE_STEP_UP           4  /* Call at bonds' margin step-up date, as with Euro deals */
#define ICMO_OPTRSUBTYPE_DATE              5  /* Just a date that's not tied to anything special like the step-up date. CDOs */
#define ICMO_OPTRSUBTYPE_AUCTION           6  /* Trustee tries to sell collat to pay off bonds - typically mandatory - CDOs, CSF05007 */

/* HEDGE: Info about HEDGE */

#define ICMO_MAX_N_HEDGES 1000 /* Max# of hedges allowed in a deal */

typedef struct _HEDGELEG {
    char  *hleg_next ;     /* to next in link list */
    char  *hleg_name ;     /* name of the HEDGE leg */
    int    hleg_hlegno;    /* seqno of the HEDGE leg */
    int    hleg_type ;    /* non-zero for special type of leg */
#define ICMOHEDGELEGTYPE_GENERIC      0  /* generic type */
#define ICMOHEDGELEGTYPE_TERMINATION  1  /* TERMINATION_LEG */
    int    hleg_cf_direction;  /* ICMO_HLEG_CFDIR_xx */
#define ICMO_HLEG_CFDIR_DEAL_PAYS     1  /* deal pays out cash */
#define ICMO_HLEG_CFDIR_DEAL_RECEIVES 2  /* deal receives cash */
    int    hleg_optpmt_method; /* ICMO_HLEG_PMTCALC_xx */
#define ICMO_HLEG_PMTCALC_OPTIMALINT  1  /* use optimal interest payment of a tranche */
#define ICMO_HLEG_PMTCALC_INTEREST    2  /* use interest payment of a tranche */
#define ICMO_HLEG_PMTCALC_PRINCIPAL   3  /* use principal payment of a tranche */
#define ICMO_HLEG_PMTCALC_CASHFLOW    4  /* use total cashflow of a tranche */
#define ICMO_HLEG_PMTCALC_FORMULA     5  /* use a formula */
    int    hleg_optpmt_trno;   /* associated tranche for optimal payment calculation */
    char  *hleg_optpmt_toptkn; /* formula used to make optimal payment calculation */
    int   *hleg_v_index_deps ; /* vector of referenced index numbers */
    int    hleg_n_index_deps ; /* number of elements in hleg_v_index_deps */
    int    hleg_index_deps ;   /* .. ITR_INDXDEP_xx, or index# dependency */
    int    hleg_pseudo_trno ;  /* if non-zero, corresponding pseudo tranche number */
    ICMO_CURRENCY *hleg_optpmt_currency; /* associated currency for payment */
    double hleg_start_amt_unpaid ;/* accumulated amount not paid from previous periods as of simulation start */
    int    hleg_attributes ;      /* bit flag for attributes of the HEDGE leg */
#define ICMO_HLEG_ATTRIBUTE_EXCLUDE_FROM_PV  1  /* HEDGE leg should be excluded from PV_HEDGE calculations */
#define ICMO_HLEG_ATTRIBUTE_INC_SF_IN_OPTPMT 2  /* include shortfall in optpmt */
    ICMO_INTRATE *hleg_unpaid_intratep;  /* interest rate for shortfall compounding */
    char  *hleg_assoc_term_hlegp; /* to associated termination leg */

    /* dynamic info changing from period to period: */
    int    hleg_optpmt_calculated; /* flag indicating optpmt already calculated for this period */
    double hleg_new_optpmt ;   /* new optimal payment for this period */
    double hleg_optpmt ;       /* optimal payment for this period */
    double hleg_amt_topay ;    /* amount left to pay this period */
    double hleg_amt_paid ;     /* amount already paid this period */
    double hleg_amt_unpaid ;   /* accumulated amount not paid from previous periods */
    }  HEDGELEG ;

typedef struct _HEDGE {
    char  *hedge_next ;       /* to next in link list */
    char  *hedge_name ;       /* name of the HEDGE */
    char  *hedge_full_name ;  /* string providing full name of the HEDGE  */
    char  *hedge_description; /* description string */
    char  *hedge_by ;         /* counter party name */
    char  *hedge_prev_by ;    /* previous counter party name */
    char  *hedge_id ;         /* reference ID */
    int    hedge_hdgno;       /* seqno of the HEDGE */
    int    hedge_type ;       /* ICMOHEDGETYPE_xx */
#define ICMOHEDGETYPE_GENERIC         0  /* generic type */
#define ICMOHEDGETYPE_CAP             1  /* option CAP */
#define ICMOHEDGETYPE_FLOOR           2  /* option FLOOR */
#define ICMOHEDGETYPE_SWAP            3  /* multi-leg swap */
#define ICMOHEDGETYPE_CURRENCY        4  /* currency swap */
#define ICMOHEDGETYPE_TRS             5  /* total return swap */
#define ICMOHEDGETYPE_CDS             6  /* credit default swap */
#define ICMOHEDGETYPE_CFS             7  /* cash flow swap */
#define ICMOHEDGETYPE_NEGAM           8  /* Deferred Interest Cap Agreement */
    int    hedge_covers;      /* ICMOHEDGECOVERS_xx */
#define ICMOHEDGECOVERS_UNKNOWN       0  /* unknown */
#define ICMOHEDGECOVERS_INTCOLLECTION 1  /* special type that covers collat interest shortfall */
    double hedge_swaprate;    /* If non-zero, fixed swap ratio for DEAL_RECEIVES legs / DEAL_PAYS legs */
    YyyyMmDd hedge_startdate; /* start date of the HEDGE (info only) */
    YyyyMmDd hedge_enddate;   /* end date of the HEDGE (info only) */
    YyyyMmDd hedge_tradedate; /* trade date of the HEDGE (info only) */
    int    hedge_n_legs ;     /* number of legs */
    HEDGELEG *hedge_leg_list; /* link list of legs */
    int    hedge_pseudo_trno; /* if non-zero, corresponding pseudo tranche number */
    YyyyMmDd hedge_termination_date;  /* actual known termination date */
    STANDARDVAR *hedge_termination_date_stdvarp; /* standardvar used for termination date forecast */
    int   hedge_on_n_items ;      /* # of items protected by hedge */
    char *hedge_on_v_item_types ; /* hedge-protected item type ICMO_OBJECT_xx */
    int  *hedge_on_v_item_nums  ; /* hedge-protected item number */
    }  HEDGE ;


/* ICMO_EXPENSE: Info about deal EXPENSES */

typedef struct _ICMO_EXPENSE {
    char *exp_next ;  /* to next in link list */
    char  exp_name [ICMO_MAX_TRNAM_CHARS+1] ; /* name */
    int   exp_expno ;    /* expense number */
    int   exp_groupno ;  /* associated collat group */
    char *exp_full_name   ; /* expense full name */
    char *exp_description ; /* expense description */
    int   exp_pmtcalc_method;  /* ICMOEXP_PMTCALC_xx */
#define ICMOEXP_PMTCALC_OPTIMALINT  1  /* use optimal interest payment of a tranche */
#define ICMOEXP_PMTCALC_INTEREST    2  /* use interest payment of a tranche */
#define ICMOEXP_PMTCALC_PRINCIPAL   3  /* use principal payment of a tranche */
#define ICMOEXP_PMTCALC_CASHFLOW    4  /* use total cashflow of a tranche */
#define ICMOEXP_PMTCALC_FORMULA     5  /* use a formula */
    int   exp_pmtcalc_trno;    /* associated tranche for payment calculation */
    char *exp_formula_toptkn ; /* expense formula */
    }  ICMO_EXPENSE ;


/* ICMOTV_xx: definition of icmot_vectors elements */

/* The following ICMOT vectors are applicable to regular/COLLAT tranches */
#define ICMOTV_principal                          0  /* Actual Principal $ paid */
#define ICMOTV_interest                           1  /* Actual Interest $ paid */
#define ICMOTV_cashflow                           2  /* Sum of above */
#define ICMOTV_balance                            3  /* Balance $ after pmt+writedown*/
#define ICMOTV_schedprincipal                     4  /* scheduled rcv'd $ */
#define ICMOTV_unschedprincipal                   5  /* unscheduled rcv'd $ */

/* The following ICMOT vectors are applicable to regular tranches only */
#define ICMOTV_accrdirprincipal                   6  /* accretion directed rcv'd $ */
#define ICMOTV_accruedprincipal                   7  /* negam'ed $ */
#define ICMOTV_notional_bal                       8  /* Balance $ used by coupon calc*/
#define ICMOTV_begnotional_bal                    9  /* Balance $ used by coupon calc*/
#define ICMOTV_optimalprincipal                  10  /* theo, only for subord lvls */
#define ICMOTV_lossprincipal                     11  /* theo writedown of bal $ */
#define ICMOTV_writedown                         12  /* realized loss bal $ */
#define ICMOTV_writedownaccum                    13  /* loss-to-date realized loss $ */
#define ICMOTV_optimalinterest                   14  /* theo int $ from coupon calc */
#define ICMOTV_intshortpaidback                  15  /* intshort $ paid back */
#define ICMOTV_intshortlost                      16  /* intshort$ no future payback */
#define ICMOTV_intshorttoaccum                   17  /* intshort$ for future payback */
#define ICMOTV_intshortaccum                     18  /* sum intshort$ future payback */
#define ICMOTV_intwritedown                      19  /* realized lost int$ */
#define ICMOTV_prepaypenalty                     20  /* prepay YM+points penalty$ */
#define ICMOTV_excessdefint                      21  /* NOT USED */
#define ICMOTV_class_prepaypct                   22  /* % prepay$ allocated to class */
#define ICMOTV_class_entitled                    23  /* 1=class gets sub_share alloc */
#define ICMOTV_surplus                           24  /*resid int flows, if surplus tranche*/
#define ICMOTV_couponcapshort                    25  /* couponcap shortfalls */
#define ICMOTV_accumcpcapshort                   26  /* accum. couponcap shortfalls */
#define ICMOTV_paybackcpcapshort                 27  /* couponcap shortfall payback */
#define ICMOTV_wdbalint                          28  /* interest accrued on accumulated writedown */
#define ICMOTV_accum_wdbalint                    29  /* accumulated interest accrued on accumulated writedown, which can itself accrue if modeled as such */
#define ICMOTV_payback_wdbalint                  30  /* payback of interest accrued on accumulated writedown */
#define ICMOTV_pikcurbal                         31  /* for a pikable tranche, cur pik bal */
#define ICMOTV_pikcurpmt                         32  /* for a pikable tranche, cur pik pmt */
#define ICMOTV_pikcuramt                         33  /* for a pikable tranche, cur pik amt */
#define ICMOTV_support_pct                       34  /* credit support percentage for this tranche */
#define ICMOTV_unrealized_writedownaccum         35  /* accumulated unrealized writedown */
#define ICMOTV_implied_writedown                 36  /* implied writedown */
#define ICMOTV_days_accrued                      37  /* #of days accruing interest */
#define ICMOTV_coupon                            38  /* coupon rate */
#define ICMOTV_princshortpaidback                39  /* princshort $ paid back */
#define ICMOTV_accum_deferclaim_due              40  /* sum of deferred claim on all claim buckets that associates with any blocks of this tranche */
#define ICMOTV_accum_deferclaim_int_due          41  /* sum of deferred claim_int on all claim buckets that associates with any blocks of this tranche */
#define ICMOTV_deferclaim_curpaid                42  /* sum of deferred claim paid on all claim buckets that associates with any blocks of this tranche */
#define ICMOTV_deferclaim_int_curpaid            43  /* sum of deferred claim_int paid on all claim buckets that associates with any blocks of this tranche */

/* The following ICMOT vectors are applicable to some regular tranches only */
#define ICMOTV_py_basis_bal                      44  /* balance for price per $100 for tranches when it diff from princ or notional bal  */
#define ICMOTV_couponcaprate                     45  /* coupon cap rate for this tranche */

/* The following ICMOT vectors are applicable to COLLAT pseudo tranches only */
#define ICMOTV_collat_origbal                    46  /* collat origbal    */
#define ICMOTV_collat_prevbal                    47  /* collat previous bal */
#define ICMOTV_collat_curbal                     48  /* collat current bal  */
#define ICMOTV_collat_liquidated                 49  /* collat gross loss */
#define ICMOTV_collat_recovered                  50  /* collat recovered */
#define ICMOTV_collat_serv_gross                 51  /* collat servfee amt */
#define ICMOTV_collat_mastserv_gross             52  /* collat master servfee */
#define ICMOTV_collat_compensated                53  /* collat servfee compensated for intshort */
#define ICMOTV_collat_trustee                    54  /* collat trustee fee */
#define ICMOTV_collat_grossmargin                55  /* collat gross margin */
#define ICMOTV_collat_expense                    56  /* collat expenses */
#define ICMOTV_collat_loss_accum                 57  /* collat accumulated loss */
#define ICMOTV_collat_pp_points                  58  /* collat prepay penalty (points) */
#define ICMOTV_collat_prepaypenalty              59  /* collat prepay penalty (total) */
#define ICMOTV_collat_excessdefint               60  /* NOT USED */
#define ICMOTV_collat_negam                      61  /* collat negam */
#define ICMOTV_collat_shiftpct                   62  /* collat shift interest % */
#define ICMOTV_collat_reduce_test                63  /* collat shift interest reduction test result */
#define ICMOTV_collat_optimalinterest            64  /* collat optimal int */
#define ICMOTV_collat_cfreinv                    65  /* collat CF reinv income */
#define ICMOTV_collat_assetreinv                 66  /* collat reinv of new asset */
#define ICMOTV_collat_excess_int                 67  /* excess of int from collat group over int due blocks. For root and rootlist groups only. */
#define ICMOTV_collat_cash_reduction             68  /* collat projected cash reduction */
#define ICMOTV_collat_int_reduction              69  /* collat projected int reduction */
#define ICMOTV_collat_accumdeferint              70  /* for student loan: accumulated deferred int to be capitalized */
#define ICMOTV_collat_capitalizedint             71  /* for student loan: cur capitalized int */
#define ICMOTV_collat_consfee                    72  /* for student loan: cur consfee */
#define ICMOTV_collat_isppmt                     73  /* for student loan: cur ISP */
#define ICMOTV_collat_sappmt                     74  /* for student loan: cur SAP */
#define ICMOTV_collat_repayfee                   75  /* for student loan: cur REPAYMENT fee */
#define ICMOTV_collat_delinq_balance             76  /* for delinq forecast: delinq balance */
#define ICMOTV_collat_delinq_interest            77  /* for delinq forecast: delinq int payment */
#define ICMOTV_collat_delinq_principal           78  /* for delinq forecast: delinq princ payment */
#define ICMOTV_collat_delinq_intpayback          79  /* for delinq forecast: delinq int payment recovered */
#define ICMOTV_collat_delinq_princpayback        80  /* for delinq forecast: delinq princ payment recovered */
#define ICMOTV_collat_rml_mip_amt                81  /* for RMTG forecast: MIP amount */
#define ICMOTV_collat_rml_serv_amt               82  /* for RMTG forecast: service fee amount */
#define ICMOTV_collat_rml_sched_pmt              83  /* for RMTG forecast: scheduled payment */
#define ICMOTV_collat_rml_draw_amt               84  /* for RMTG forecast: unscheduled draw amount */
#define ICMOTV_collat_rml_max_claim_amt          85  /* for RMTG forecast: max claim amount */
#define ICMOTV_collat_rml_principal_limit        86  /* for RMTG forecast: PRINCIPAL_LIMIT */
#define ICMOTV_collat_rml_available_loc          87  /* for RMTG forecast: AVAILABLE_LOC */
#define ICMOTV_collat_rml_fha_put                88  /* for RMTG forecast: FHA put amt */
#define ICMOTV_collat_cds_notional_amort         89  /* for unfunded CDS/TRS, total non-loss balance reduction due to reference asset principal payment */
#define ICMOTV_collat_unrealized_writedownaccum  90  /* collat accumulated unrealized writedown */
#define ICMOTV_collat_implied_writedown          91  /* collat implied writedown */
#define ICMOTV_collat_performing_bal             92  /* collat performing balance */
#define ICMOTV_collat_new_default_amt            93  /* collat new default amount */
#define ICMOTV_collat_draw_amt                   94  /* collat draw amount        */
#define ICMOTV_collat_pikcurbal                  95  /* collat PIK balance */
#define ICMOTV_collat_pikcurpmt                  96  /* collat PIK payment */
#define ICMOTV_collat_pikcuramt                  97  /* collat PIK amount */
#define ICMOTV_collat_cfadj_addl_loss            98  /* collat projected CFADJ_ADDL_LOSS */
#define ICMOTV_collat_excess_intloss             99  /* collat excess intloss amt */
#define ICMOTV_collat_ahb_int                   100  /* account holdback int amt */
#define ICMOTV_collat_ahb_int_released          101  /* account holdback int released */
#define ICMOTV_collat_ahb_princ                 102  /* account holdback princ amt */
#define ICMOTV_collat_ahb_princ_released        103  /* account holdback princ released */

/* The following ICMOT vectors are applicable to CREDIT pseudo tranches only */
#define ICMOTV_credit_reinvest                  104  /* ECE reinvest amt */
#define ICMOTV_credit_deposit                   105  /* ECE deposit amt */
#define ICMOTV_credit_withdraw                  106  /* ECE withdraw amt */
#define ICMOTV_credit_withd_intshort            107  /* ECE withdraw to cover intshort */
#define ICMOTV_credit_withd_loss                108  /* ECE withdraw to cover loss */
#define ICMOTV_credit_withd_excess              109  /* ECE withdraw for excess */
#define ICMOTV_credit_withd_other               110  /* ECE withdraw for other reasons */
#define ICMOTV_credit_balance                   111  /* ECE cur balance */
#define ICMOTV_credit_init_balance              112  /* ECE init balance */
#define ICMOTV_credit_balance_cap               113  /* ECE balance cap */
#define ICMOTV_credit_total_payout_cap          114  /* ECE total payout cap */
#define ICMOTV_credit_accum_deferclaim          115  /* sum of end of period unpaid deferred claims at FG level for all claim buckets */
#define ICMOTV_credit_accum_deferclaim_int      116  /* sum of end of period accum unpaid int on deferred claims at FG level for all claim buckets */
#define ICMOTV_credit_cur_deferclaim_int        117  /* sum of int on deferred claims this per at FG level for all claim buckets */
#define ICMOTV_credit_deferclaim_curpaid        118  /* sum of deferred claims paid this per at FG level for all claim buckets */
#define ICMOTV_credit_deferclaim_int_curpaid    119  /* sum of int on deferred claims paid this per at FG level for all claim buckets */

/* The following ICMOT vectors are applicable to EXPENSE pseudo tranches only */
#define ICMOTV_expense_curdue                   120  /* EXPENSE due */
#define ICMOTV_expense_curpaid                  121  /* EXPENSE paid */
#define ICMOTV_expense_unpaid                   122  /* EXPENSE overdue */

/* The following ICMOT vectors are applicable when running TAX CF */
#define ICMOTV_taxpv                            123  /* tax present value */
#define ICMOTV_taxqsi                           124  /* tax qualified interest */
#define ICMOTV_taxoid                           125  /* tax original issue discount */
#define ICMOTV_taxcf                            126  /* total taxable cashflow */

/* The following ICMOT vectors are applicable to COLLAT pseudo tranches only */
#define ICMOTV_collat_advanced_int              127  /* cur advanced int */
#define ICMOTV_collat_advanced_princ            128  /* cur advanced princ */
#define ICMOTV_collat_unadvanced_intloss        129  /* cur intloss due to unadvanced int */
#define ICMOTV_collat_accum_advance_onliq       130  /* accum advance on liqbal */
#define ICMOTV_collat_accum_intloss_onliq       131  /* accum intloss on liqbal */
#define ICMOTV_collat_accum_intrecov_onliq      132  /* accum intloss recovery on liqbal */
#define ICMOTV_collat_forb_amt                  133  /* collat forbearance new amt */
#define ICMOTV_collat_forb_recov                134  /* collat forbearance recovered */
#define ICMOTV_collat_forb_accum                135  /* collat forbearance outstanding */
#define ICMOTV_collat_special_servfee_amt       136  /* collat special servfee collected */
#define ICMOTV_collat_bbrr_shortfall            137  /* for student loan: BBRR_SHORTFALL */
#define ICMOTV_collat_stl_num_units             138  /* for student loan: NUM_UNITS */
#define ICMOTV_collat_cfadj_addl_miscint        139 /* collat projected CFADJ_ADDL_MISCINT */
#define ICMOTV_collat_cfadj_addl_princ          140 /* collat projected CFADJ_ADDL_PRINC */
#define ICMOTV_collat_delinq_princcapitalized   141 /* for delinq forecast: delinq princ payment capitalized */
#define ICMOTV_collat_princ_due_unpaid          142 /* unpaid principal due account */
#define ICMOTV_collat_princ_due_curpaid         143 /* cur period principal due account paid */

/* The maximum number of possible icmot vectors */
#define ICMOTV_MAX_N_VECTORS                    144  /* # of ICMOTV vectors */


/* ICMODIST_xx: tranche distribution info */

/* Regular tranche distribution info */
#define ICMODIST_principal              0  /*  .. actual interest $ */
#define ICMODIST_interest               1  /*  .. actual principal $ */
#define ICMODIST_schedprincipal         2  /*  .. scheduled P$ */
#define ICMODIST_unschedprincipal       3  /*  .. unscheduled P$ */
#define ICMODIST_accrdirprincipal       4  /*  .. accret directed P$ */
#define ICMODIST_accruedprincipal       5  /*  .. negam'ed P$ */
#define ICMODIST_notional_bal           6  /*  .. bal by coupon calc */
#define ICMODIST_begnotional_bal        7  /*  .. bal by coupon calc */
#define ICMODIST_optimalprincipal       8  /*  .. theo for sublvls */
#define ICMODIST_lossprincipal          9  /*  .. theo bal$ writedown*/
#define ICMODIST_writedown             10  /*  .. realized lost bal$ */
#define ICMODIST_writedownaccum        11  /*  .. to-date rlost bal$ */
#define ICMODIST_optimalinterest       12  /*  .. coupon-based int $ */
#define ICMODIST_intshortpaidback      13  /*  .. shfl $ paid back */
#define ICMODIST_intshortlost          14  /*  .. shfl$ no fut paybk */
#define ICMODIST_intshorttoaccum       15  /*  .. shfl$ for fut paybk*/
#define ICMODIST_intshortaccum         16  /*  .. to-date int shfall$*/
#define ICMODIST_intwritedown          17  /*  .. realized lost int$ */
#define ICMODIST_prepaypenalty         18  /*  mo YM penalty */
#define ICMODIST_excessdefint          19  /*  NOT USED */
#define ICMODIST_class_prepaypct       20  /*  .. %prepay$ alloc */
#define ICMODIST_class_entitled        21  /*  .. 1= class gets share*/
#define ICMODIST_py_basis_bal          22  /*  ..  balance for price per $100 */
#define ICMODIST_couponcapshort        23  /* couponcap shortfalls */
#define ICMODIST_accumcpcapshort       24  /* accum. couponcap shortfalls */
#define ICMODIST_paybackcpcapshort     25  /* couponcap shortfall payback */
#define ICMODIST_MAX_N_VECTORS         26  /* Max number of ICMODIST vectors */

/* Collateral distribution info, shared with above */
#define ICMODIST_collat_principal        ICMODIST_principal
#define ICMODIST_collat_interest         ICMODIST_interest
#define ICMODIST_collat_schedprincipal   ICMODIST_schedprincipal
#define ICMODIST_collat_unschedprincipal ICMODIST_unschedprincipal
#define ICMODIST_collat_origbal          ICMODIST_accrdirprincipal
#define ICMODIST_collat_prevbal          ICMODIST_accruedprincipal
#define ICMODIST_collat_curbal           ICMODIST_notional_bal
#define ICMODIST_collat_liquidated       ICMODIST_optimalprincipal
#define ICMODIST_collat_recovered        ICMODIST_lossprincipal
#define ICMODIST_collat_serv_gross       ICMODIST_writedown
#define ICMODIST_collat_mastserv_gross   ICMODIST_writedownaccum
#define ICMODIST_collat_compensated      ICMODIST_optimalinterest
#define ICMODIST_collat_trustee          ICMODIST_intshortpaidback
#define ICMODIST_collat_grossmargin      ICMODIST_intshortlost
#define ICMODIST_collat_expense          ICMODIST_intshorttoaccum
#define ICMODIST_collat_loss_accum       ICMODIST_intshortaccum
#define ICMODIST_collat_ympremiums       ICMODIST_prepaypenalty
#define ICMODIST_collat_excessdefint     ICMODIST_excessdefint  /* NOT USED */
#define ICMODIST_collat_negam            ICMODIST_begnotional_bal
#define ICMODIST_collat_shiftpct         ICMODIST_class_prepaypct
#define ICMODIST_collat_reduce_test      ICMODIST_class_entitled

/* Reserve/Guaranty/LOC distribution info, shared with above */
#define ICMODIST_credit_reinvest         ICMODIST_intshortpaidback
#define ICMODIST_credit_deposit          ICMODIST_intshortlost
#define ICMODIST_credit_withd_intshort   ICMODIST_schedprincipal
#define ICMODIST_credit_withd_loss       ICMODIST_unschedprincipal
#define ICMODIST_credit_withd_excess     ICMODIST_accrdirprincipal
#define ICMODIST_credit_balance          ICMODIST_accruedprincipal
#define ICMODIST_credit_init_balance     ICMODIST_notional_bal
#define ICMODIST_credit_withd_other      ICMODIST_optimalprincipal
#define ICMODIST_credit_balance_cap      ICMODIST_lossprincipal
#define ICMODIST_credit_total_payout_cap ICMODIST_writedown

/* EXPENSE distribution info, shared with above */
#define ICMODIST_expense_curpaid         ICMODIST_principal
#define ICMODIST_expense_curdue          ICMODIST_interest
#define ICMODIST_expense_unpaid          ICMODIST_schedprincipal

/* HEDGE distribution info, shared with above */
#define ICMODIST_hedge_curpaid           ICMODIST_interest
#define ICMODIST_hedge_notional_bal      ICMODIST_notional_bal


/* ICMO_RML_VECT_xx: Reverse mortgage specific CF vects */
#define ICMO_RML_VECT_MIP_AMT         0 /* MIP amount */
#define ICMO_RML_VECT_SERV_AMT        1 /* service fee amount */
#define ICMO_RML_VECT_SCHED_PMT       2 /* scheduled payment */
#define ICMO_RML_VECT_DRAW_AMT        3 /* unscheduled draw amount */
#define ICMO_RML_VECT_MAX_CLAIM_AMT   4 /* max claim amount */
#define ICMO_RML_VECT_PRINCIPAL_LIMIT 5 /* PRINCIPAL_LIMIT */
#define ICMO_RML_VECT_AVAILABLE_LOC   6 /* AVAILABLE_LOC */
#define ICMO_RML_VECT_FHA_PUT         7 /* FHA put amount */
#define ICMO_N_RML_VECTS              8 /* total # of RML specific CF vects */


/* ICMO_STL_VECT_xx: Student loan specific CF vects */
#define ICMO_STL_VECT_ACCUM_DEFERINT  0 /* accumulated deferred int to be capitalized later */
#define ICMO_STL_VECT_CAPITALIZEDINT  1 /* curper capitalized int */
#define ICMO_STL_VECT_CONSFEE         2 /* curper consfee */
#define ICMO_STL_VECT_ISPPMT          3 /* curper ISP */
#define ICMO_STL_VECT_SAPPMT          4 /* curper SAP */
#define ICMO_STL_VECT_REPAYFEE        5 /* repayment fee */
#define ICMO_STL_VECT_BBRR_SHORTFALL  6 /* shortfall caused by Borrower Benifit Rate Reduction */
#define ICMO_STL_VECT_NUM_UNITS       7 /* number of units */
#define ICMO_N_STL_VECTS              8 /* total # of STL specific CF vects */

/* ICMO_ADDL_VECT_xx: addl CF vects */
#define ICMO_ADDL_VECT_ADVANCED_INT         0 /* cur advanced int */
#define ICMO_ADDL_VECT_ADVANCED_PRINC       1 /* cur advanced princ */
#define ICMO_ADDL_VECT_UNADVANCED_INTLOSS   2 /* cur intloss due to unadvanced int */
#define ICMO_ADDL_VECT_ACCUM_ADVANCE_ONLIQ  3 /* accum advance on liqbal */
#define ICMO_ADDL_VECT_ACCUM_INTLOSS_ONLIQ  4 /* accum intloss on liqbal */
#define ICMO_ADDL_VECT_ACCUM_INTRECOV_ONLIQ 5 /* accum intloss recovery on liqbal */
#define ICMO_ADDL_VECT_FORB_AMT             6 /* forbearance new amt */
#define ICMO_ADDL_VECT_FORB_RECOV           7 /* forbearance recovered */
#define ICMO_ADDL_VECT_FORB_ACCUM           8 /* forbearance outstanding */
#define ICMO_ADDL_VECT_SPECIAL_SERVFEE_AMT  9 /* special dervfee collected */
#define ICMO_N_ADDL_VECTS                  10 /* total # of addl CF vects */

/* ICMOSTATS_IDXVAL: part of ICMOSTATS: index vals used in CF run for DM calc */

typedef struct {
    char     *icmostats_idxval_next ;            /* next in link list */
    int       icmostats_idxval_indextype ;       /* index type */
    int       icmostats_idxval_nrates ;          /* vrates vector length */
    double   *icmostats_idxval_vrates ;          /* rates vector */
    } ICMOSTATS_IDXVAL ;

/* ICMOSTATS_FORWARD: part of ICMOSTATS: used for horizon_return Calc at forward stats */

typedef struct {
    int       icmostats_forward_days_till_nxtpay ;  /* #of days till next payment */
    } ICMOSTATS_FORWARD ;

/* ICMOSTATS: parameters used for icmo_stats */

typedef struct {
    char     *icmostats_next ;                   /* next in link list */
    YyyyMmDd  icmostats_settle_date ;            /* Present date */
    YyyyMmDd  icmostats_settle_date_orig ;       /* Original passed-in settle date (may differ from actual) */
    int       icmostats_settle_adj_ndays_prev ;  /* Number of days prior to above date that would be bd-adjusted to it */
    int       icmostats_settle_adj_ndays_next ;  /* Number of days after the above date that would be bd-adjusted to it */
    int       icmostats_n_cashflows ;            /* length of CF vectors */
    double   *icmostats_vcashflow   ;            /* vector of CF */
    double   *icmostats_vprincipal  ;            /* vector of princ CF (used by icmo_horizon_return) */
    YyyyMmDd *icmostats_vpaydates   ;            /* vector of paydates (businessday adjusted) */
    YyyyMmDd *icmostats_vidxdates   ;            /* vector of index need dates (for DM calc) */
    int       icmostats_daycount_method ;        /* daycount method */
    int      *icmostats_vdaycount_methods;       /* vector of daycount method (used if icmostats_daycount_method = ICMO_DAYCOUNT_VECTOR */
    int       icmostats_actact_accrual_end;      /* if ACTUALACTUAL is used in daycount, use DENOM_METHOD ACCRUAL_END */
    double    icmostats_py_basis_bal ;           /* Balance basis (for price/100) */
    double    icmostats_accruedint ;             /* Accrued interest */
    int       icmostats_tranche_pseudo_type;     /* ICMOTR_PSEUDO_xx */
    int       icmostats_dm_indextype ;           /* default DM index type */
    int       icmostats_coupon_index_lag ;       /* floater coupon index lag */
    ICMOSTATS_IDXVAL *icmostats_idxvalp;         /* index vals used in CF run for DM calc */
    ICMOSTATS_FORWARD *icmostats_forwardp;       /* info needed for horizon_return Calc at forward stats */
    } ICMOSTATS ;

/* ICMO:  Intex CMO Subroutines Master interfacing structure */

struct _ICMO {      /* "struct _ICMO" and "ICMO" are equivalent */

    /* Information available to your application after icmo_deal(): */

    char *icmo_dealname ;          /* Intex name of deal, e.g. "FHL034" */
    char *icmo_deal_issuer ;       /* agency/shelf that issued the deal */
    char *icmo_deal_dealer ;       /* initial lead dealer */
    char *icmo_deal_comment_str;   /* deal comment info string */
    char *icmo_deal_modeling_notes_str; /* Intex's modeling assumptions info string */
    char *icmo_deal_portfolio_str; /* reasons for not trading accuracy */
    ICMO_DEALPORTSTR_DECODE *icmo_deal_portfolio_str_decode; /* reasons for not trading accuracy */
    char *icmo_deal_userstr ;      /* user-stored string */
    int   icmo_deal_mode ;         /* ICMODEAL_xx: maybe CDI used */
    int   icmo_collat_cluster_mode ; /* ICMO_CLUSTER_xx: current cluster mode */
    int   icmo_deal_category ;     /* ICMODEALCAT_xx: Agency/Priv/Wl...*/
    char  icmo_assetback_type ;    /* ICMOASSETBACK_xx */
    int   icmo_deal_restriction ;  /* ICMODISTRIB_xx: distr. restriction */
    int   icmo_not_at_trading_accuracy;/*TRUE if portfolio-only accuracy*/
    int   icmo_no_payrules_modeled ;   /*TRUE if no bond CFs avail */
    int   icmo_remic_flag  ;       /* ICMOREMIC_xx: is deal a REMIC*/
    int   icmo_settle_type ;       /* ICMOSETTL_xx: settlement alg */
    int   icmo_min_cf_vectsize ;   /* min length of cf vectors allocated for current scenario run */
    int   icmo_max_cf_vectsize ;   /* Should not be used with ICMO_NO_MAX_CF_VECTSIZE, else: length of alloc cf. vectors in deal after parsing*/
    YyyyMmDd icmo_deal_settle_date ;  /* Date of original deal settlement */
    YyyyMmDd icmo_mkt_factors_date ;  /* Industry notation factors date*/
    YyyyMmDd icmo_deal_paid_down_date; /* date when deal paid down */
    YyyyMmDd icmo_tranche_fdate ;  /* Present tranches factor date */
    YyyyMmDd icmo_collat_fdate ;   /* Present collateral factor date */
    YyyyMmDd icmo_first_eventdate; /* Deal first pays date */
    YyyyMmDd icmo_next_eventdate;  /* Deal next pays (not necc entitl) */
    YyyyMmDd icmo_cdi_revised_date;/* 0, or latest revision of CDI file */
    YyyyMmDd icmo_cdu_asofdate ;   /* CDU updated asof this date */
    YyyyMmDd icmo_1st_speed_forecast; /* date corresp to vspeed[1]  */
    YyyyMmDd icmo_1st_index_forecast; /* date corresp to vindex[1]  */
    int   icmo_pay_dd ;            /* day of month of tranche pmts */
    int   icmo_recdate_delay ;     /* Record date delay */
    int   icmo_next_event_is_hist; /* TRUE if nxtpay from known factors*/
    int   icmo_collat_freq ;       /* Dominant collat freq 12=Monthly */
    int   icmo_collat_curmonth ;   /* Present collateral month 1=Jan */
    double icmo_deal_origbal ;     /* origination size of deal $ */
    double icmo_deal_curbal ;      /* current size of deal $ */
    int icmo_remterm ;             /* #months remaining deal's cflows */
    int icmo_cdu_warn ;            /* ICDUWARN_xx, CDU file exist */
    YyyyMmDd icmo_issue_cdu_date ;  /* YyyyMmDd date of issue month CDU */
    YyyyMmDd icmo_base_cdu_date ;   /* YyyyMmDd date of base CDU */
    YyyyMmDd icmo_latest_cdu_date ; /* YyyyMmDd date of latest CDU */
    int icmo_nmonths_hist;         /* #months = latestCDU - settleCDU */
    int icmo_avail_known_cf_nmon ; /* actual #months known CF available/used when altu_allow_access_known_cf_nmon is set.  Limited by altu_allow_access_known_cf_nmon and available historical CDUs */
    int icmo_1st_speed_forecast_yymm; /* month.corresp to vspeed[1] */
    int icmo_1st_index_forecast_yymm; /* month.corresp to vindex[1] */
    YyyyMmDd icmo_collars_asof_date ; /* YyyyMmDd for collars in CDU or 0 if NA */
    YyyyMmDd icmo_first_payruledate ; /* YyyyMmDd of initial execution of pay rules */
    int icmo_payrulefreq ;         /* 12=monthly, 4=quarterly 2=semian */
    int icmo_have_residual ;       /* TRUE if 0-th tranche is "R" */
    int icmo_deal_nblocks ;        /* total # of block "components" */
    int icmo_init_deal_nblocks ;   /* icmo_deal_nblocks asof parsing */
    int icmo_prephist_method ; /* ICMOPREPHIST_xx: method of calculation*/
    int icmo_surplus_trancheno ;   /* tranche# getting surplus or -1    */
    double icmo_accruedint_surplus; /* accrued int for surplus tranche */
    int icmo_bv_clock_start ; /*first forecasted period since deal issue*/
    char icmo_use_bv_method ;      /* TRUE if any bv calc needed      */
    char icmo_have_special_redemption ; /* TRUE if special redemption allowed */
    char icmo_deal_is_pure_io ;    /* TRUE if deal pays no principal$ */
    char icmo_deal_has_duplicated_reremics ; /* TRUE if topmost deal has duplicated re-remics (even if we not keep them) */
    char icmo_deal_must_conv2pmt ; /* TRUE if deal's structure automatically switches to pmt-to-pmt mode */

    int icmo_index_reset_status ;  /* ICMIRESET_xx: for floater resets */
    int icmo_in_coupon_blackout ;  /* TRUE if any coupon in blackout */

    double icmo_cashaccount_init;  /* Upfront funding of cash account */
    double icmo_cashaccount_cur ;  /* Current cash account level */

    ICMO_XINFO *icmo_xinfop ;      /* additional info */

    int icmo_nindexes_referenced ;    /* # of index rate types in deal */
    int icmo_max_n_index_info ;       /*max element's # in icmo_vindex_info  */
    ICMO_INDEX **icmo_vindex_info ;   /* vector of index info structures */
    int icmo_deal_has_mult_index_subinfos;/*if any index info has multiple subinfos */
    char *icmo_index_current_subname; /* valid only within index_fcn */

    int icmo_n_tranches ;          /* #tranches in the deal (+1 for R) */
    int icmo_init_n_tranches ;     /* icmo_n_tranches asof parsing */
    char **icmo_tranche_names ;    /* to array of tranche name strings */
    char **icmo_tranche_types ;    /* .. tranche type strings */
    char **icmo_tranche_cusips ;   /* .. tranche cusip strings */
    char **icmo_tranche_agents ;   /* .. tranche "paying agent" strings */
    double *icmo_tranche_coupons ; /* .. cur tranche coupons from blocks*/
    double *icmo_tranche_cdu_coupons ; /* .. reported coupons in CDU */
    double *icmo_tranche_origbals;     /* .. original balances */
    double *icmo_tranche_orignotbals;  /* .. original notional balances */
    double *icmo_tranche_curbals ;     /* .. current balances */
    double *icmo_tranche_cdu_factors;  /* .. reported factor in CDU */
    double *icmo_tranche_start_factors;/* .. simulation start factor */
    double *icmo_tranche_accruedint_factors; /* .. accruedint factor */
    double *icmo_tranche_accruedints;   /* .. raw $ accrued int */
    double *icmo_tranche_issueprices;   /* .. orig $/100, or <0 if n.a. */
    double *icmo_tranche_issueyields;   /* .. orig %, or BAD_CALC if na */
    double *icmo_tranche_collars_lo ;   /* .. lower effective collar    */
    double *icmo_tranche_collars_hi ;   /* .. upper effective collar    */
    int *icmo_tranche_freqs ;      /* .. freqs (12=monthly) */
    int *icmo_tranche_delays ;     /* .. payment delays */
    int *icmo_tranche_recdelays ;  /* .. record date delays */
    int *icmo_tranche_nblocks ;    /* .. # dependent block "components" */
    int *icmo_tranche_everzs ;     /* .. T/F if tranche may ever AccrueZ*/
    int *icmo_tranche_accruings ;  /* .. ICMOTACCRUE_xx: now accruing? */
    int *icmo_tranche_mixeds ;     /* .. ICMOTRANCHE_xx: block mix */
    int *icmo_tranche_entitleds ;  /* .. T/F if purchaser gets next pmt */
    int *icmo_tranche_callable_by_investor; /* .. TRUE, if callable tranche */
    int *icmo_tranche_index_deps ; /* .. ITR_INDXDEP_xx, or index# used (ICMOI_xx) */
    char **icmo_tranche_index_subnames; /* .. finer resolution of above */
    int *icmo_tranche_pseudo_types;/* .. ICMOTR_PSEUDO_xx: if not real */
    int *icmo_tranche_notional_flags; /* .. ICMOTR_NOTIONAL_xx: ntl type*/
    int *icmo_tranche_memstore_offsets;/* .. shift for entitlement */
    YyyyMmDd *icmo_tranche_dateds;     /* .. orig start accrual period */
    YyyyMmDd *icmo_tranche_firstdates; /* .. orig 1st payment dates */
    YyyyMmDd *icmo_tranche_accrudates; /* .. updated dated dates */
    YyyyMmDd *icmo_tranche_nextdates;  /* .. updated next pay dates */
    YyyyMmDd *icmo_tranche_statedmatdates;/* .. stated maturity dates */
    YyyyMmDd *icmo_tranche_release_dates;
                         /* .. cashflow not available before this date */

    double icmo_pricing_speed ;      /* Prepayment rate at pricing */
    int icmo_pricing_units ;         /* ICMOSPDT_xx, pricing units */
    int icmo_pricing_0PSA_bv ;       /* TRUE if prospectus 0% bv case*/
    int icmo_have_prepayscript ;     /* TRUE if PrepayScript avail */

    int icmo_have_optredeem ;        /* TRUE if any optional redemption*/
    OPTREDEEM *icmo_optredeems ;     /* chain of OPTREDEEM structures */
    OPTREDEEM *icmo_cur_optredeem;   /* cur OPTREDEEM-only in icmo_optredeem_fcn */
    TAX_TRUST *icmo_tax_trust_list;  /* linked list of TAX trusts */
    ICMO_EXPENSE *icmo_expense_list; /* linked list of deal EXPENSEs */
    HEDGE *icmo_hedge_list;          /* linked list of deal HEDGEs */

    double icmo_pass_thru_rate ;     /* Whole loan Pass Through % */
    double icmo_cdu_variance ;       /* QA check on CDU factors */
    int icmo_cdu_auto ;              /* ICDUQA_xx: how CDU created */

    POOL_INFO *icmo_collat_list ;    /* to linked list of collateral */
    POOL_INFO *icmo_collat_wavg ;    /* to wt avg collateral "pool" */
    int  icmo_npips_reinv_collat ;        /* # of  elements in icmo_vpips_reinv_collat */
    POOL_INFO **icmo_vpips_reinv_collat ; /* vector of potential reinvestment collateral pips */
    int icmo_collat_need_explode ;   /* # of mega/giant pools */
    int icmo_collat_did_explode ;    /* .. expanded to individual pools */
    int icmo_did_propagate_pass_thru; /*..substituted re-remics in collat*/
    int icmo_n_collat_transact_sets ;  /* last processed transaction set ( CDX file)*/
    ICMOTSET *icmo_trans_setp ;      /* control structure for icmo_apply_collat_transact_set () */
    ABS_SUMMARY_INFO *icmo_abs_summary_info ; /* to ABS historical data */
    STANDARDVAR *icmo_standardvar_info ; /* STANDARDVAR link list */

    int icmo_n_classes ;             /* # senior/sub class tree nodes */
    DEAL_CLASS **icmo_vclasses ;     /* indexing vector of class ptrs */
    DEAL_CLASS *icmo_root_classp ;   /* to root of the class tree */

    EXCHANGE *icmo_exchanges ;       /* chain of EXCHANGE structures for defined tranche exchanges (FHL MACR) */
    TRIGGER_INFO *icmo_trigger_list; /* link list of TRIGGER info */

    int icmo_n_collat_grps ;           /* #of defined collateral groups */
    int icmo_init_n_collat_grps ;      /* icmo_n_collat_grps asof parsing */
    COLLAT_GROUP **icmo_vcollat_grps ; /* array of group info ptrs */

    ICMO *icmo_topmost_icmop ;       /* to topmost deal if CMO backs CMO */
    char *icmo_up_icmop ;            /* to parent deal if CMO backs CMO */
    char *icmo_next_icmop ;          /* to next ICMO in subdeals chain */
    POOL_INFO *icmo_up_pip ;         /* to parent deal's virtual pool */
    int icmo_deal_ith_next ;         /* nth in above chain (>=0) */
    int icmo_deal_depth ;            /* #levels below top deal (>=0) */

    int icmo_n_credits ;             /* #ReserveFunds/FinGuar/LOC  */
    ICMO_CREDIT **icmo_vcredit_info ;  /* ..array of credit info structure pointers */

    int icmo_n_rating_agencies ;       /* # agencies which rated any tranche */
    char **icmo_vrating_agency_names ; /* Names of rating agencies */
    char **icmo_vrating_agency_codes ; /* Internal codes for rating agencies */

    int icmo_n_symvars ;             /* how many internal V0..V9..#vars */
    char **icmo_symvars_namelist ;   /* .. array name pointers */
    double *icmo_symvars_start_vals; /* .. corresponding init values */
    double *icmo_tranchedist_vectors[ICMODIST_MAX_N_VECTORS]; /* vectors of tranche distribution info */

    int icmo_n_forex ;  /* how many foreign exchange combinations */
    /* Controls that your application can set before icmo_cluster_pools(): */

    CLUSTER *icmo_clusterp ;         /* to clustering control */
    int icmo_cluster_toplevel_only ; /* don't cluster underlying deals */

    /* Controls for override_asset  functions */
    ICMO_OVRD_ASSET_PARSE_CONTROL *icmo_ovrd_asset_parse_ctrlp ; /* Control structure used for altu_override_asset_parse_fcn() */
    ICMO_OVRD_ASSET_CF_CONTROL    *icmo_ovrd_asset_cf_ctrlp ;    /* Control structure used for icmo_override_asset_cf_fcn()      */

    /* Controls that your application can set before running cashflows: */

    char *icmo_user ;                /* passes user-appl ptr with icmop */
    int icmo_return_if_error;        /* if TRUE, all ICMO functions will return instead of calling user errdie fcn, user will then check with icmo_errinfo() */
    int icmo_do_optredeems[ICMO_N_OPTRTYPE] ; /* Controls execution of redemptions. Set to ICMO_OPTREXEC_xx */
    int icmo_do_optsink ;            /* for bonds: if TRUE, use opt. sink schedule */
    int icmo_ignore_credits ;        /* ICMOIGNORE_CREDITS_xx: benefits */
    int icmo_ignore_credsupp_fully_insured ;   /* if TRUE, ignore fully-insured flag when calculating credit support timeseries */
    int icmo_credsupp_exclude_defeased ;    /* if TRUE, exclude defeased asset from support basis when calculating timeseries of credit support percentages */
    int icmo_credsupp_use_group_directed ;  /* if deal uses OC_Y credit support methodology, force ICMOTV_support_pct values to be calculated on group-directed basis after crossed OC is exhausted. */
    int icmo_credsupp_show_negative_values ; /* if TRUE, show negative values in ICMOTV_support_pct when applicable, instead of flooring the results at 0. */
    int icmo_cashflows_force_conv2pmt ; /*if TRUE, force internal conversion to pmt-to-pmt mode within icmo_cashflows */
    int icmo_cashflows_force_daycount_method; /*to use ICMO_DAYCOUNT_xx in cf*/
    int icmo_cashflows_force_businessday_method; /*to use ICMO_BUSINESSDAY_xx in cf*/
    int icmo_disallow_cleanup ;      /* if TRUE, for precise structuring*/
       /* Warning - setting the following two flags may violate the integrity of the deal payment rules and/or deal modeling
                    and result in unexpected and incorrect cashflows, particularly in non-agency deals. */
    int icmo_ignore_capflrs ;     /* ignore floater coupon limits*/
#define ICMO_IGNORE_CAPFLRS_NO     0  /* run as modeled */
#define ICMO_IGNORE_CAPFLRS_ALL    1  /* ignore all floater coupon limits (cap, floor and reset) */
#define ICMO_IGNORE_CAPFLRS_CAPS   2  /* ignore floater coupon caps */
#define ICMO_IGNORE_CAPFLRS_FLOORS 3  /* ignore floater coupon floors */
    int icmo_ignore_index_capflrs ;  /* if TRUE, allow to forecast index rates with values outside of preset cap (usually no cap) and floor values (usually 0) */

    int  ((CALLBK_FCN_PREFIX *icmo_override_asset_cf_fcn) (Args_override_asset_cf_fcn)) ; /*  callback function to override asset cashflows */
    void *icmo_override_asset_cf_userp ;  /* user handle to be passed to icmo_override_asset_cf_fcn() */
    void ((CALLBK_FCN_PREFIX *icmo_override_pool_cf_fcn)
            (Args_override_pool_cf_fcn)) ;    /* user pool CF generator */
    int ((CALLBK_FCN_PREFIX *icmo_optredeem_fcn)
                   (Args_optredeem_fcn)) ;  /* user deal call*/
    int ((CALLBK_FCN_PREFIX *icmo_info_1period_fcn)
                   (Args_info_1period_fcn)) ; /* user 1period info function */
    int icmo_info_1period_flag ;        /* ICMOINFO_1PER_WHEN_xx bit flag denoting mode(s) to call icmo_info_1period_fcn */
    int ((CALLBK_FCN_PREFIX *icmo_forex_fcn)
                       (Args_forex_fcn)) ;   /* user foreign exchange forecasts */
    RBC_INFO *((CALLBK_FCN_PREFIX *icmo_replace_buy_collat_fcn)
                       (Args_replace_buy_collat_fcn)) ;   /* user replace_buy_collat fcn */
    int icmo_buy_collat_max_remterm ;  /* max remterm of collat asset added by icmo_buy_collat() */
    YyyyMmDd icmo_buy_collat_end_date ;  /* Last date when reinvestment using  icmo_buy_collat() allowed. Default - deal xi_reinv_end_date */
    int icmo_ith_scenario ;          /* which cashflow scenario (>=0),
                                        or 3rdParty prepay function ICMO_CASHFLOWS_PPMDL_BASE_CASE_SCENARIO */
    int icmo_retain_scenarios ;      /* If TRUE, retain previous scenario settings and ith_scenario>0 results upon ith_scenario=0 cashflow run */
    char icmo_select_icmot_vectors[ICMOTV_MAX_N_VECTORS]; /* flags to make available selected icmot_vectors */
    int icmo_select_icmot_vect_default; /* ICMOTV_SELECT_DEFAULT_xx */
#define ICMOTV_SELECT_DEFAULT_NONE    -1 /* only explicit selections of icmo_select_icmot_vectors[] */
#define ICMOTV_SELECT_DEFAULT_MINIMUM  0 /* minimum number of vectors determined by system plus explicit selections of icmo_select_icmot_vectors[] */
#define ICMOTV_SELECT_DEFAULT_EXTENDED 1 /* an extended list of vectors plus explicit selections of icmo_select_icmot_vectors[] */
#define ICMOTV_SELECT_DEFAULT_FULL     2 /* all possible vectors (less TAX related vectors) */

    YyyyMmDd icmo_latest_mb_date ;   /* YyyyMmDd of pool info in pool-as-deal mode */
    int icmo_n_cashflow_reinv_rates; /* #of cells in .. */
    double *icmo_vcashflow_reinv_rates; /* collection acct reinv (%) */
    int icmo_prefund_loan_prep;  /* PREFUND_LOAN_PREP_xx */
    int icmo_prefund_loan_def;   /* PREFUND_LOAN_DEF_xx */
    int icmo_prefund_loan_payint;/* TRUE, if prefund loans pay int during prefund period */
    int icmo_use_reremic_prev_cf_run_results;/* TRUE, if not need to run underlying deal cashflows - use results of previous run */
    void ((CALLBK_FCN_PREFIX *icmo_opinfo_govern_loancf_fcn)
            (Args_opinfo_govern_loancf_fcn)) ;    /* eg, user CMBS DSCR-based scenario */
    int ((CALLBK_FCN_PREFIX *icmo_loan_progress_fcn)
            (Args_loan_progress_fcn)) ;           /* eg, user "%done" routine */
#define ICMO_PROGBAR_TIMESERIES_COLLAT     1  /* now running collat in timeseries mode */
#define ICMO_PROGBAR_TIMESERIES_DISTRIB    2  /* now running bonds in timeseries mode */
#define ICMO_PROGBAR_PMTPMT_DISTRIB        3  /* now running 1 period in pmt-to-pmt mode */
#define ICMO_PROGBAR_PARSE_UNDERLYING_DEAL 4  /* now parsing 1st level reremic */
#define ICMO_PROGBAR_CASHFLOW_INIT         5  /* notifies callback function to initialize progbar for cashflows */

    int icmo_balloonext_nmonths_max ; /* max #months to extend balloons */
    int icmo_force_use_duebill ; /* set to override ICMODUEBILL_xx setting via ICMOMISC structure */
    int icmo_run_asset_cf_till_end ; /* if TRUE, run collat CF till end even if deal paid down early */
    int icmo_get_collat_cf_mode ; /* control flag for icmo_get_collat_cf() */
#define ICMO_GETCOLLATCF_DEFAULT 0 /* user_pool_cf_fcn called only for regular pools */
#define ICMO_GETCOLLATCF_PNOTE   1 /* user_pool_cf_fcn called also for pnotes */
    char icmo_collat_balloon_prin_per_rules ; /* for asset/collat CF, TRUE to treat balloon pmt as sched/prepay according to deal rule */
    char icmo_allow_aggmdr_pmt_mode ;    /* only for pmt-to-pmt mode. TRUE if prepayment function supports aggmdr specific conditions  */
    ICMOWTR_CTRL *icmo_waterfall_report; /* if non-NULL, waterfall report feature is available */

    /* Controls that your application can set before running cashflows
       or in user-defined prepayment function: */

    CFASSUM icmo_cfassum ;           /* cashflows forecasting assumptions */

    ICMO_PPMDL_INFO *icmo_ppmdl_infop ; /*to 3rd party model info  */

    /* Info available inside CF prepayment function */
    void *icmo_icmosolverp ;  /* non NULL if inside icmo_solver call */

    /* Controls that your application can set before running icmo_deal_effective_collars: */
    double icmo_collars_hi_limit_for_deal_effective_collars ;  /* if 0 - default=1600% PSA*/

    /* Information available to your application after icmo_cashflow(), */
    /* but we recommend that you skip ahead to the icmo_stats() fields: */

    int *icmo_tranche_princ_lockouts ;  /* # months till next princ pmt */
    int *icmo_tranche_princ_remterms ;  /* # remaining princ pmt months */
    int *icmo_tranche_int_remterms ;    /* # remaining interest pmt mos */
    int *icmo_tranche_remterms ;        /* # remaining cashflow pmt mos */
    int *icmo_tranche_issue_princ_remterms;/*#princ pmts fr issue to mat*/
    int *icmo_tranche_issue_int_remterms;/* #int pmts fr issue to matur */
    double *icmo_vsurplus ;             /* if icmomisc, resid int flows */
    double *icmo_vexpenses ;            /* if icmomisc, expense flows */


    /* Controls that your application can set before icmo_stats(): */

    double icmo_stats_pct_princ ;   /* strip% P into CF (default=100) */
    double icmo_stats_pct_int ;     /* strip% I into CF (default=100) */
    ICMO_CURRENCY *icmo_stats_force_currencyp ; /* Report CF & stats in selected currency */
    int icmo_stats_force_daycount_method; /*to use ICMO_DAYCOUNT_xx in stat*/
    int icmo_stats_force_businessday_method ; /* to use ICMO_BUSINESSDAY_xx in stats */
    int icmo_stats_force_business_center ; /* to use ICMO_BUSINESSCENTER_xx in stats */
    int icmo_calc_disc_margin ;     /* if TRUE also calc discount margin*/
    int icmo_calc_disc_margin_index_lag; /* positive number of months lag to shift index for DM calculation, capped by value returned in TR_ATTRIB_ALLOWED_DISC_MARGIN_INDEX_LAG */
#define ICMO_DISC_MARGIN_INDEX_LAG_WITH_COUPON_INDEX   9999  /* to use lag associated with tranche coupon index lag as returned in TR_ATTRIB_ALLOWED_DISC_MARGIN_INDEX_LAG */
    char icmo_calc_disc_margin_first_period_index ;   /* ICMO_DISCMARGIN_FIRST_PERIOD_INDEX_xx */
#define ICMO_DISC_MARGIN_FIRST_PERIOD_INDEX_USE_ACCRUAL  0
#define ICMO_DISC_MARGIN_FIRST_PERIOD_INDEX_USE_SETTLE   1
    char *icmo_calc_disc_margin_index_subname ;   /* NULL or subname for the index referred by icmo_calc_disc_margin */
    int icmo_py_basis_use_bal;             /* set balance to be used for price per $100 calc*/
#define ICMO_PY_BASIS_USE_DEFAULT       0  /* use tranche's PY_BASIS specified by model or defaulted for the tranche type */
#define ICMO_PY_BASIS_USE_NOTIONAL_BAL  1  /* use tranche's notional  balance */
#define ICMO_PY_BASIS_USE_PRINC_BAL     2  /* use tranche's principal balance */
    int icmo_py_basis_use_original_face ;     /* set balance to be used as denominator to scale cashflows when user provides a face amt. */
#define ICMO_PY_BASIS_USE_ORIG_FACE_CLASSIC       0  /* use tranche's original princ balance */
#define ICMO_PY_BASIS_USE_ORIG_FACE_PY_BASIS      1  /* use tranche's original PY basis */
#define ICMO_PY_BASIS_USE_ORIG_FACE_NOTIONAL_BAL  2  /* use tranche's original notional balance */

    int icmo_yldcrv_spread_method; /* ICMOYLDCRV_SPREAD_xx: spread method for ICMOPY_SPREAD mode */
    int icmo_yldcrv_n_nodes ;      /* #of nodes on yield curve.. */
    double *icmo_yldcrv_nodes ;    /* yield curve maturities, in yrs */
    double *icmo_yldcrv_vals  ;    /* yield curve yields, in pct */
    double icmo_yldcrv_explicit ;  /* .. if ICMOYLDCRV_SPREAD_EXPLCIT_xx */
    double icmo_stats_tax_rate ;   /* tax rate in pct when running TAX CF */
    double icmo_stats_cf_cutoff;   /* ignore CF if amount below cutoff */
    int icmo_stats_yld_freq ;      /* bond coupon frequency (payments/year) for price/yield calculations.
                                    * Default is 2 (bond-equivalent yield) */
    int icmo_stats_ignore_abpd_cfs; /* TRUE to ignore CFs after tranche balance paid down on eligible trs */
    int icmo_stats_calc_vdisc_factors; /* calc icmot_vdisc_factors for applicable ICMOPY_xx */
    int icmo_stats_access_known_cf_nmon ;        /* #of months of historical CF even if not entitled when run in ICMOPY_GET_AVAILABLE_CASHFLOWS mode. Limited by altu_allow_access_known_cf_nmon and available historical CDUs */
#define ICMO_STATS_ACCESS_KNOWN_CF_DEFAULT    0  /* default behavior  for ICMOPY_GET_AVAILABLE_CASHFLOWS */
#define ICMO_STATS_ACCESS_KNOWN_CF_ALL      999  /* access all known CF available by using altu_allow_access_known_cf_nmon */


    /* Information available to your application after icmo_stats(): */

    int icmot_trancheno ;          /* Tranche# for icmo_stats() calc */
    int icmot_days_accrued ;       /* #of days accruing interest */
    int icmot_days_till_nxtpay ;   /* #of days till next payment */
    ICMO_CURRENCY *icmot_currencyp ; /* Currency of icmo_stats() results */
    YyyyMmDd icmot_factor_date ;   /* date of reported tranche factor */
    double icmot_actual_factor ;   /* reported tranche factor */
    double icmot_netmoney_factor;  /* tranche factor used for calc */
    double icmot_xxxxxxx ;         /* future use... */
    double icmot_face ;            /* face amount held */
    double icmot_face_curbal ;     /* current balance of face held */
    double icmot_accrued ;         /* accrued interest $ */
    double icmot_accrued_surplus;  /* same,incl.surplus */
    double icmot_accrued100 ;      /* accrued interest $ per 100 */
    double icmot_price ;           /* aggregate price, excl accrued */
    double icmot_pricei ;          /* aggregate price, incl accrued */
    double icmot_price100 ;        /* price per $100, less accrued */
    double icmot_price100i ;       /* price per $100, incl accrued */
    double icmot_yield ;           /* bond-equiv yield, % */
    double icmot_spread ;          /* spread-to-yldcrv, in b.p. */
    double icmot_spread_maturity ; /* .. at this age on yldcrv, in yrs */
    double icmot_wal ;             /* weighted avg life, yrs */
    double icmot_wal_int ;         /* weighted avg life of the interest payments, yrs */
    double icmot_wal_princ ;       /* weighted avg life of the principal payments, yrs */
    double icmot_wal_implied_balance ;  /* weighted avg life for balance adjusted by implied writedown */
    double icmot_moddurn ;         /* static modified duration, yrs */
    double icmot_convexity;        /* static modified convexity */
    double icmot_princ_amt ;       /* net money cost: principal $ */
    double icmot_int_amt ;         /* net money cost: interest $ */
    double icmot_cost_amt ;        /* net money cost: total $ */
    double icmot_disc_margin ;     /* static discount margin, b.p. */
    double icmot_disc_margin_beq ; /* .. (its bond-equiv BEEM), b.p. */
    int    icmot_disc_margin_index;/* .. over this index */
    int icmot_lockout ;            /* #months till next princ payment */
    int icmot_princ_matures ;      /* #months till last princ payment */
    int icmot_matures ;            /* #months till last payment */
    int icmot_pre_entitled_offset ;    /* for ICMOPY_GET_AVAILABLE_CASHFLOWS - #months between icmot_vectors[1] and 1st tranche entitled month */
#define icmot_forecast_offset  icmot_pre_entitled_offset
    int icmot_cashflows_forward ;  /* if non-zero, have marched ahead */
    YyyyMmDd *icmot_vpayment_dates ; /* Distribution dates of cashflows */
    double *icmot_vdisc_factors ;    /* vector of discount fracs */
    double *icmot_vectors[ICMOTV_MAX_N_VECTORS]; /* vectors of info associate with last icmo_stat() call */
    ICMOSTATS *icmot_statsparam ;  /* parameters used for icmo_stats call */

    /* Controls your application can set before icmo_tranche_blocks(): */

    int icmo_expand_bi_flt_info ;  /* if TRUE also index by collateral */


    /* Information available after icmo_tranche_blocks(): */

    BLOCK_INFO *icmo_tranche_block_list ; /* to linked list of blocks */


    /* Add'l loan info available by icmo_get_collat_cf(): */
    int icmoloancf_timeseries_actual_remterm ; /* remterm to which loan was actually paid;
                         correct for balloon extension, etc., when pi_remterm is wrong */

    /* loan timeseries data accessible by icmo_get_collat_cf(): */
    double *icmoloancf_vprincipal  ;   /* principal */
    double *icmoloancf_vinterest  ;    /* interest */
    double *icmoloancf_vcashflow  ;    /* total CF */
    double *icmoloancf_vbalance  ;     /* balance */
    double *icmoloancf_vservfeeamt  ;  /* serv fee$ vector */
    double *icmoloancf_vdefaultamt  ;  /* amt$ in default vector */
    double *icmoloancf_vgrossrate   ;  /* wac % vector */
    double *icmoloancf_vgrossmargin ;  /* arm gross margin % vector */
    double *icmoloancf_vschedprincipal;/* scheduled principal $ */
    double *icmoloancf_vliquidated  ;  /* gross loss $ */
    double *icmoloancf_vrecovered   ;  /* loss recovery $ */
    double *icmoloancf_vprepaypenalty ; /* prepay penalty */
    double *icmoloancf_vprepaypenalty_points ; /* prepay penalty from points */
    double *icmoloancf_vdraws       ;  /* draw amounts */
    double *icmoloancf_vperforming_bal ;  /* performing balance as opposed to stated balance (which doesn't adjust for defaulted/recovered amts */
    double *icmoloancf_vnotional_bal ;  /* notional balance.  NULL unless loan is pure IO */
    double *icmoloancf_vcontrib_frac ;  /* if nonNULL, vector of contributing fraction of CF to deal */
    double *icmoloancf_voptimalint ;    /* optimal interest */
    double *icmoloancf_vcds_notional_amort; /* for unfunded CDS/TRS asset, total non-loss balance reduction due to reference asset principal payment */
    double *icmoloancf_vunrealized_writedownaccum; /* accumulated unrealized writedown (used for re-remics only)*/
    double *icmoloancf_vimplied_writedown;         /* implied writedown (used for re-remics only)*/
    double *icmoloancf_vrml_cfvect[ICMO_N_RML_VECTS]; /* RML specific cashflow vectors */
    double *icmoloancf_vstl_cfvect[ICMO_N_STL_VECTS]; /* STL specific cashflow vectors */
    double *icmoloancf_vpikcurbal;         /* PIK bal */
    double *icmoloancf_vpikcuramt;         /* PIK amt */
    double *icmoloancf_vpikcurpmt;         /* PIK pmt */
    double *icmoloancf_vcfadjvect[ICMOCFADJ_N_TYPES]; /* ICMOCFADJ_xx related CF vector */
    double *icmoloancf_vexcess_intloss;    /* intloss resulted from excess severity */
    double *icmoloancf_vaddl_cfvect[ICMO_N_ADDL_VECTS]; /* addl loancf info */
    double *icmoloancf_vballoon_as_prepay; /* balloon pmt to be substracted from vschedp per rule */

    ICMOADDLINFO *icmo_addl_infop ; /* control structure for icmo_addl_info() */
    ICMO_INDEX_FCAST *icmo_index_fcastp ; /* control structure for icmo_set_index_forecast() */
    LOANDATA *icmo_zipcode_related_loandatap ; /* pointer to linked list of LOANDATA structures containing zipcode related info, MSA, etc, filled after calling icmo_zipcode_to_msa() */

    /* For outsourced functions */
    int icmo_use_outsrc ; /* flag set internally from icmomisc_use_outsrc so that user can free ICMOMISC structure */
    char *icmo_outsrcp ; /* pointer to structure of fcn. pointers */

    /* General housekeeping:  For use only by Intex CMO Subroutines... */
    /* The behavior or content of the following items is not supported and may change at any time! */

INTEX_INTERNAL_USE_ONLY     int icmo_id ;                  /* flag for safety */
INTEX_INTERNAL_USE_ONLY     char *icmo_dealname_orig ;     /* name of deal as converted from CUSIP or typed by user, e.g. "FHR 34" */
INTEX_INTERNAL_USE_ONLY     char *icmo_cmop ;              /* to Intex CMO internal structures */
INTEX_INTERNAL_USE_ONLY     int   icmo_deal_is_encrypted ; /* TRUE=unavailable for viewing */
INTEX_INTERNAL_USE_ONLY     ICMOMISC *icmo_icmomiscp ;     /* to optional environ info */
INTEX_INTERNAL_USE_ONLY    int icmo_step ;                /* ICMOSTEP_xx in icmo routines */
INTEX_INTERNAL_USE_ONLY    char icmo_datebuff[20] ;       /* stores formatted dates here */
INTEX_INTERNAL_USE_ONLY    char icmo_pricebuff[50] ;      /* stores formatted prices here */
INTEX_INTERNAL_USE_ONLY    int icmo_cashflow_storagetype; /* cf array type remembered here */
INTEX_INTERNAL_USE_ONLY    int icmo_pmt_to_pmt_mode ;     /* if TRUE, month-to-month calc */
INTEX_INTERNAL_USE_ONLY    int icmo_pmt_to_pmt_ith_month; /* current month in pmt-to-pmt mode */
INTEX_INTERNAL_USE_ONLY    YyyyMmDd icmo_settle_date ;    /* Settlement date specified in icmo_deal(), may be modified internally  */
INTEX_INTERNAL_USE_ONLY    void ((CALLBK_FCN_PREFIX *icmo_pool_cf_fcn)
INTEX_INTERNAL_USE_ONLY                             (Args_pool_cf_fcn)) ; /* pool's cf avail */
INTEX_INTERNAL_USE_ONLY    void ((CALLBK_FCN_PREFIX *icmo_coll_cf_fcn)
INTEX_INTERNAL_USE_ONLY                           (Args_pool_cf_fcn)) ; /* collat cf avail */
INTEX_INTERNAL_USE_ONLY    double ((CALLBK_FCN_PREFIX *icmo_1index_calc)
INTEX_INTERNAL_USE_ONLY                              (Args_1index_fcn)); /* 1 prepay */
INTEX_INTERNAL_USE_ONLY    double *icmo_memstore ;             /* to in-memory all tranche CFs */
INTEX_INTERNAL_USE_ONLY    YyyyMmDd icmo_deal_issue_date ; /*Deal issue date or 0 if not in CDI*/
INTEX_INTERNAL_USE_ONLY    double icmo_cdu_max_tr_pct ;        /* maximum percent variance */
INTEX_INTERNAL_USE_ONLY    int    icmo_cdu_max_tr_num ;        /* tranche number for the above */
INTEX_INTERNAL_USE_ONLY    char icmo_gnma_tape ;                   /* ... */
INTEX_INTERNAL_USE_ONLY    char icmo_deal_has_component_loans ;
INTEX_INTERNAL_USE_ONLY    char icmo_real_collat_in_cdi ; /* TRUE if CDU will update over CDI */
INTEX_INTERNAL_USE_ONLY    char icmo_abs_summary_purpose ;/* ABSIPURPOSE_xx: ABS or .XTF */
#define ABSIPURPOSE_ABS    0
#define ABSIPURPOSE_XTF    1
INTEX_INTERNAL_USE_ONLY    int    icmo_cdu_per ;               /* last pay period for CDU */
INTEX_INTERNAL_USE_ONLY    int    icmo_wrcollat_offset;        /* internal use */
INTEX_INTERNAL_USE_ONLY    char *icmo_portf_icmop ;            /* to internal portfolio deal info */
INTEX_INTERNAL_USE_ONLY    int icmo_ith_pool ;            /* prepay func can ident pool (>=1) */
INTEX_INTERNAL_USE_ONLY    int icmo_prepay_speed_lookback ; /* for ICMO_PREPAY_SPEED() */
INTEX_INTERNAL_USE_ONLY    char *icmo_deal_is_partition_of; /* parent dealname, if this is a partition deal*/

/* MPI: Internal use only */
INTEX_INTERNAL_USE_ONLY    char     icmo_deal_using_mpi ;             /* if TRUE, deal is parsed across multiple processes */
INTEX_INTERNAL_USE_ONLY    char     icmo_deal_using_mpi_this_node ;   /* if TRUE, deal using this node */
INTEX_INTERNAL_USE_ONLY    void    *icmo_mpi_commp ;                  /* pointer to MPI communicator for this deal, if any */
INTEX_INTERNAL_USE_ONLY    int      icmo_mpi_max_rank ;               /* max rank of MPI process used for this deal */


    /* Use care when using these fields across century boundaries */
    int icmo_cdu_yymm ;            /* YYMM date of settle CDU */
    int icmo_latest_cdu_yymm ;     /* YYMM date of latest avail. CDU */
    int icmo_collars_asof_yymm  ;  /* yymm for collars in CDU or 0 if NA*/
    int icmo_latest_mb_yymm ;      /*YYMM of pool info in POOL as MBS deal */

    /* Old fields not to use, retained for compatibility */
DEPRECATED    YyyyMmDd icmo_optredeem_1st_date; /* Deprecated: first potential optredem date */
DEPRECATED    YyyyMmDd icmo_optredeem_did_date; /* Deprecated: actual optredem date */
DEPRECATED    YyyyMmDd icmo_optredeem_date ;    /* Deprecated: call if date >= this */
DEPRECATED    YyyyMmDd *icmo_index_date1 ;      /* Deprecated: replaced by icmo_1st_index_forecast  */
DEPRECATED    int icmo_optredeem_also_collat ;  /* Deprecated. Not used */
DEPRECATED    int icmo_set_bal_to_notional ;    /* Deprecated. Not used */
DEPRECATED    int icmo_optredeem_exprs ;        /* Deprecated: call if complex expr is TRUE */
DEPRECATED    int icmo_optredeem_and_date ;
DEPRECATED    int icmo_optredeem_and_expr ;
DEPRECATED    int icmot_ncoups_shift ;
DEPRECATED    int icmo_mem_i_mult ;
DEPRECATED    int icmo_n_scenarios ;            /* Deprecated: no need to set upfront. Scenario run based on current icmo_ith_scenario */
DEPRECATED    int *icmo_tranche_orig_losspositions; /* Deprecated (incorrect for complicated deals) */
DEPRECATED    int *icmo_tranche_cur_losspositions;  /* Deprecated (incorrect for complicated deals) */
DEPRECATED    int *icmo_index_referenced ;      /* Deprecated: replaced by icmo_vindex_info[ith_index]->index_referenced */
DEPRECATED    int *icmo_tranche_notionals;      /* Deprecated: replaced by icmo_tranche_notional_flags*/
DEPRECATED    int *icmo_index_n_subinfos ;      /* Deprecated */
DEPRECATED    double icmo_optredeem_frac ;      /* Deprecated: call if cur$ < frac * orig$ */
DEPRECATED    double icmot_curcoupon ;          /* Not in use */
DEPRECATED    double *icmo_index_curval  ;      /* Deprecated: replaced by icmo_vindex_info[ith_index]->index_curval */
DEPRECATED    double *icmo_index_taxval  ;      /* Deprecated: replaced by icmo_vindex_info[ith_index]->index_taxval */
DEPRECATED    double **icmo_vindexs      ;      /* Deprecated */
DEPRECATED    INDEX_SUBINFO **icmo_index_subinfop; /* Deprecated: replaced by icmo_vindex_info[ith_index]->index_subinfop */
DEPRECATED    char **icmo_index_warn_msg ;      /* Deprecated: replaced by icmo_vindex_info[ith_index]->index_warn_msg */
DEPRECATED    char **icmo_credits_namelist ;    /* Deprecated.. array name pointers */
DEPRECATED    char *icmo_deal_fullname ;        /* Deprecated: replaced by ICMOADDLINFO_FULL_DEALNAME  */
DEPRECATED    char *icmo_deal_trustee ;         /* Deprecated: replaced by ICMOADDLINFO_TRUSTEE_DEAL   */
DEPRECATED    char *icmo_deal_servicer ;        /* Deprecated: replaced by ICMOADDLINFO_SERVICER_xx   */

    /* Old icmot vectors, not to use, retained for compatibility */
DEPRECATED    double *icmot_vprincipal ;       /* monthly principal $payments vect */
DEPRECATED    double *icmot_vinterest ;        /* monthly interest $payments vect */
DEPRECATED    double *icmot_vcashflow ;        /* monthly cashflow $payments vect */
DEPRECATED    double *icmot_vbalance ;         /* monthly outstanding $balance vect */
DEPRECATED    double *icmot_vsurplus ;         /*resid int flows, if surplus tranche*/
DEPRECATED    double *icmot_vschedprincipals  ;/* mo scheduled P$ */
DEPRECATED    double *icmot_vunschedprincipals;/* mo unscheduled P$ */
DEPRECATED    double *icmot_vaccrdirprincipals;/* mo accret directed P$ */
DEPRECATED    double *icmot_vaccruedprincipals;/* mo negam'ed P$ */
DEPRECATED    double *icmot_vnotional_bals    ;/* mo bal by coupon calc */
DEPRECATED    double *icmot_vbegnotional_bals ;/* mo bal by coupon calc */
DEPRECATED    double *icmot_voptimalprincipals;/* mo theo for sublvls */
DEPRECATED    double *icmot_vlossprincipals   ;/* mo theo bal$ writedown*/
DEPRECATED    double *icmot_vwritedowns       ;/* mo realized lost bal$ */
DEPRECATED    double *icmot_vwritedownaccums  ;/* mo to-date rlost bal$ */
DEPRECATED    double *icmot_voptimalinterests ;/* mo coupon-based int $ */
DEPRECATED    double *icmot_vintshortpaidbacks;/* mo shfl $ paid back */
DEPRECATED    double *icmot_vintshortlosts    ;/* mo shfl$ no fut paybk */
DEPRECATED    double *icmot_vintshorttoaccums ;/* mo shfl$ for fut paybk*/
DEPRECATED    double *icmot_vintshortaccums   ;/* mo to-date int shfall$*/
DEPRECATED    double *icmot_vintwritedowns    ;/* mo realized lost int$ */
DEPRECATED    double *icmot_vprepaypenalty    ;/* mo prepayment penalty YM+points */
DEPRECATED    double *icmot_vexcessdefint     ;/* NOT USED  */
DEPRECATED    double *icmot_vclass_prepaypcts ;/* mo % prepay$ alloc to class */
DEPRECATED    double *icmot_vclass_entitleds  ;/* mo 1=class gets alloc */
DEPRECATED    double *icmot_vcollat_cfreinv   ;/* collat CF collection reinvestment income */
DEPRECATED    double *icmot_vcollat_assetreinv;/* collat reinvestment of new assets */
DEPRECATED    double *icmot_vtaxpv            ;/* tax present value */
DEPRECATED    double *icmot_vtaxqsi           ;/* tax qualified interest */
DEPRECATED    double *icmot_vtaxoid           ;/* tax original issue discount */
DEPRECATED    double *icmot_vtaxcf            ;/* total taxable cashflow */
#define icmot_vcollat_origbal        icmot_vaccrdirprincipals            DEPRECATED
#define icmot_vcollat_prevbal        icmot_vaccruedprincipals            DEPRECATED
#define icmot_vcollat_curbal         icmot_vnotional_bals                DEPRECATED
#define icmot_vcollat_liquidated     icmot_voptimalprincipals            DEPRECATED
#define icmot_vcollat_recovered      icmot_vlossprincipals               DEPRECATED
#define icmot_vcollat_serv_gross     icmot_vwritedowns                   DEPRECATED
#define icmot_vcollat_mastserv_gross icmot_vwritedownaccums              DEPRECATED
#define icmot_vcollat_compensated    icmot_voptimalinterests             DEPRECATED
#define icmot_vcollat_trustee        icmot_vintshortpaidbacks            DEPRECATED
#define icmot_vcollat_grossmargin    icmot_vintshortlosts                DEPRECATED
#define icmot_vcollat_expense        icmot_vintshorttoaccums             DEPRECATED
#define icmot_vcollat_loss_accum     icmot_vintshortaccums               DEPRECATED
#define icmot_vcollat_prepaypenalty_points icmot_vintwritedowns          DEPRECATED
#define icmot_vcollat_prepaypenalty  icmot_vprepaypenalty                DEPRECATED
#define icmot_vcollat_excessdefint   icmot_vexcessdefint                 DEPRECATED
#define icmot_vcollat_negam          icmot_vbegnotional_bals             DEPRECATED
#define icmot_vcollat_shiftpct             icmot_vclass_prepaypcts       DEPRECATED
#define icmot_vcollat_shiftpct_reduce_test icmot_vclass_entitleds        DEPRECATED
#define icmot_vcredit_withdraw             icmot_vwritedownaccums        DEPRECATED
#define icmot_vcredit_reinvest             icmot_vintshortpaidbacks      DEPRECATED
#define icmot_vcredit_deposit              icmot_vintshortlosts          DEPRECATED
#define icmot_vcredit_withdraw_intshort    icmot_vschedprincipals        DEPRECATED
#define icmot_vcredit_withdraw_loss        icmot_vunschedprincipals      DEPRECATED
#define icmot_vcredit_withdraw_excess      icmot_vaccrdirprincipals      DEPRECATED
#define icmot_vcredit_balance              icmot_vaccruedprincipals      DEPRECATED
#define icmot_vcredit_init_balance         icmot_vnotional_bals          DEPRECATED
#define icmot_vcredit_withdraw_other       icmot_voptimalprincipals      DEPRECATED
#define icmot_vexpense_curdue              icmot_vinterest               DEPRECATED
#define icmot_vexpense_curpaid             icmot_vprincipal              DEPRECATED
#define icmot_vexpense_unpaid              icmot_vschedprincipals        DEPRECATED

    /* Old tranche distribution fields for compatibility */
#define icmo_tranchedist_principals          icmo_tranchedist_vectors[ICMODIST_principal       ]      DEPRECATED
#define icmo_tranchedist_interests           icmo_tranchedist_vectors[ICMODIST_interest        ]      DEPRECATED
#define icmo_tranchedist_schedprincipals     icmo_tranchedist_vectors[ICMODIST_schedprincipal  ]      DEPRECATED
#define icmo_tranchedist_unschedprincipals   icmo_tranchedist_vectors[ICMODIST_unschedprincipal]      DEPRECATED
#define icmo_tranchedist_accrdirprincipals   icmo_tranchedist_vectors[ICMODIST_accrdirprincipal]      DEPRECATED
#define icmo_tranchedist_accruedprincipals   icmo_tranchedist_vectors[ICMODIST_accruedprincipal]      DEPRECATED
#define icmo_tranchedist_notional_bals       icmo_tranchedist_vectors[ICMODIST_notional_bal    ]      DEPRECATED
#define icmo_tranchedist_begnotional_bals    icmo_tranchedist_vectors[ICMODIST_begnotional_bal ]      DEPRECATED
#define icmo_tranchedist_optimalprincipals   icmo_tranchedist_vectors[ICMODIST_optimalprincipal]      DEPRECATED
#define icmo_tranchedist_lossprincipals      icmo_tranchedist_vectors[ICMODIST_lossprincipal   ]      DEPRECATED
#define icmo_tranchedist_writedowns          icmo_tranchedist_vectors[ICMODIST_writedown       ]      DEPRECATED
#define icmo_tranchedist_writedownaccums     icmo_tranchedist_vectors[ICMODIST_writedownaccum  ]      DEPRECATED
#define icmo_tranchedist_optimalinterests    icmo_tranchedist_vectors[ICMODIST_optimalinterest ]      DEPRECATED
#define icmo_tranchedist_intshortpaidbacks   icmo_tranchedist_vectors[ICMODIST_intshortpaidback]      DEPRECATED
#define icmo_tranchedist_intshortlosts       icmo_tranchedist_vectors[ICMODIST_intshortlost    ]      DEPRECATED
#define icmo_tranchedist_intshorttoaccums    icmo_tranchedist_vectors[ICMODIST_intshorttoaccum ]      DEPRECATED
#define icmo_tranchedist_intshortaccums      icmo_tranchedist_vectors[ICMODIST_intshortaccum   ]      DEPRECATED
#define icmo_tranchedist_intwritedowns       icmo_tranchedist_vectors[ICMODIST_intwritedown    ]      DEPRECATED
#define icmo_tranchedist_prepaypenalty       icmo_tranchedist_vectors[ICMODIST_prepaypenalty   ]      DEPRECATED
#define icmo_tranchedist_excessdefint        icmo_tranchedist_vectors[ICMODIST_excessdefint    ]      DEPRECATED
#define icmo_tranchedist_class_prepaypcts    icmo_tranchedist_vectors[ICMODIST_class_prepaypct ]      DEPRECATED
#define icmo_tranchedist_class_entitleds     icmo_tranchedist_vectors[ICMODIST_class_entitled  ]      DEPRECATED
    /* optional collateral distribution info, shared with above */
#define icmo_collatdist_origbal              icmo_tranchedist_vectors[ICMODIST_collat_origbal       ]   DEPRECATED
#define icmo_collatdist_prevbal              icmo_tranchedist_vectors[ICMODIST_collat_prevbal       ]   DEPRECATED
#define icmo_collatdist_curbal               icmo_tranchedist_vectors[ICMODIST_collat_curbal        ]   DEPRECATED
#define icmo_collatdist_liquidated           icmo_tranchedist_vectors[ICMODIST_collat_liquidated    ]   DEPRECATED
#define icmo_collatdist_recovered            icmo_tranchedist_vectors[ICMODIST_collat_recovered     ]   DEPRECATED
#define icmo_collatdist_serv_gross           icmo_tranchedist_vectors[ICMODIST_collat_serv_gross    ]   DEPRECATED
#define icmo_collatdist_mastserv_gross       icmo_tranchedist_vectors[ICMODIST_collat_mastserv_gross]   DEPRECATED
#define icmo_collatdist_compensated          icmo_tranchedist_vectors[ICMODIST_collat_compensated   ]   DEPRECATED
#define icmo_collatdist_trustee              icmo_tranchedist_vectors[ICMODIST_collat_trustee       ]   DEPRECATED
#define icmo_collatdist_grossmargin          icmo_tranchedist_vectors[ICMODIST_collat_grossmargin   ]   DEPRECATED
#define icmo_collatdist_expense              icmo_tranchedist_vectors[ICMODIST_collat_expense       ]   DEPRECATED
#define icmo_collatdist_loss_accum           icmo_tranchedist_vectors[ICMODIST_collat_loss_accum    ]   DEPRECATED
#define icmo_collatdist_ympremiums           icmo_tranchedist_vectors[ICMODIST_collat_ympremiums    ]   DEPRECATED
#define icmo_collatdist_excessdefint         icmo_tranchedist_vectors[ICMODIST_collat_excessdefint  ]   DEPRECATED
#define icmo_collatdist_negam                icmo_tranchedist_vectors[ICMODIST_collat_negam         ]   DEPRECATED
#define icmo_collatdist_shiftpct             icmo_tranchedist_vectors[ICMODIST_collat_shiftpct      ]   DEPRECATED
#define icmo_collatdist_shiftpct_reduce_test icmo_tranchedist_vectors[ICMODIST_collat_reduce_test   ]   DEPRECATED
    /* optional Reserve/Guaranty/LOC distrib info, shared with above */
#define icmo_creditdist_reinvest             icmo_tranchedist_vectors[ICMODIST_credit_reinvest      ]   DEPRECATED
#define icmo_creditdist_deposit              icmo_tranchedist_vectors[ICMODIST_credit_deposit       ]   DEPRECATED
#define icmo_creditdist_withdraw_intshort    icmo_tranchedist_vectors[ICMODIST_credit_withd_intshort]   DEPRECATED
#define icmo_creditdist_withdraw_loss        icmo_tranchedist_vectors[ICMODIST_credit_withd_loss    ]   DEPRECATED
#define icmo_creditdist_withdraw_excess      icmo_tranchedist_vectors[ICMODIST_credit_withd_excess  ]   DEPRECATED
#define icmo_creditdist_balance              icmo_tranchedist_vectors[ICMODIST_credit_balance       ]   DEPRECATED
#define icmo_creditdist_init_balance         icmo_tranchedist_vectors[ICMODIST_credit_init_balance  ]   DEPRECATED
#define icmo_creditdist_withdraw_other       icmo_tranchedist_vectors[ICMODIST_credit_withd_other   ]   DEPRECATED
    /* optional EXPENSE distrib info, shared with above */
#define icmo_expensedist_curdue              icmo_tranchedist_vectors[ICMODIST_expense_curdue       ]   DEPRECATED
#define icmo_expensedist_curpaid             icmo_tranchedist_vectors[ICMODIST_expense_curpaid      ]   DEPRECATED
#define icmo_expensedist_unpaid              icmo_tranchedist_vectors[ICMODIST_expense_unpaid       ]   DEPRECATED
} ; /* ICMO */


#ifndef DISALLOW_DEPRECATION
#define ICMODEALT_COUPON(deal,ith_mo) /*calcs tranche coupon from CFs */\
 ( ith_mo < 1 || deal->icmot_vbalance == NULL \
     || deal->icmot_vbalance[ith_mo-1] < .01 ?   0. :  \
  ((deal->icmot_vinterest[ith_mo]-deal->icmot_vsurplus[ith_mo]) \
   /deal->icmot_vbalance[ith_mo-1]) \
  * ( deal->icmo_tranche_freqs[deal->icmot_trancheno] * 100.))
#define ICMOT_COUPON(ith_mo) ICMODEALT_COUPON(icmop,ith_mo)

#define ICMODEALT_SURPLUS_COUPON(deal,ith_mo) /* above incl.surplus */  \
 ( ith_mo < 1 || deal->icmot_vbalance[ith_mo-1] < .01 ?   0. :  \
  (deal->icmot_vinterest[ith_mo]/deal->icmot_vbalance[ith_mo-1]) \
  * ( deal->icmo_tranche_freqs[deal->icmot_trancheno] * 100.))
#define ICMOT_SURPLUS_COUPON(ith_mo) ICMODEALT_SURPLUS_COUPON(icmop,ith_mo)

#define BI_NXTDATE_ENTITLED(bip)  /* next pay date entitled to rcv */ \
   (bip->bi_entitled_to_nxtpmt ? bip->bi_nxtdate \
     : icmo_YyyyMmDd_add( bip->bi_nxtdate, 360/bip->bi_intfreq, TRUE ) )

#define BI_DELAYDAYS_ENTITLED(bip) /* days till entitled next rcv */ \
   (bip->bi_entitled_to_nxtpmt ? bip->bi_delaydays \
     : (bip->bi_delaydays + 360/bip->bi_intfreq)  )
#endif


#define icmo_get_commercialop_by_id(icmop,loanattrp,index)                              \
    ( loanattrp == NULL || index < 0 || index >= loanattrp->loanattr_copln_future1 ?    \
         NULL : loanattrp->loanattr_coplv_future1[index] )
#define PIARM_INDEX_MULTIPLIER(armp) (armp->armi_index_multiplier==0.? 1.:armp->armi_index_multiplier ) /* ARM index rate coefficient */
#define ICMO_NAMEx(x,name) ( *(name) != '@' ? (name) : icmo_get_name(x,name) )
#define ICMO_NAME(name)    ICMO_NAMEx(icmop,name)
#define ICMO_LOANDATA_NAMEx(x,loandatap) ICMO_NAMEx(x,loandatap->loandata_name)
#define ICMO_LOANDATA_NAME(loandatap) ICMO_LOANDATA_NAMEx(icmop,loandatap)
#define ICMO_LOANDATA_TRANSLATIONx(x,pip,loandatap) icmo_get_loandata_translation(x,pip,loandatap)
#define ICMO_LOANDATA_TRANSLATION(pip,loandatap) ICMO_LOANDATA_TRANSLATIONx(icmop,pip,loandatap)

#define ICMO_DUMMY_DEALNAME_STATS  (icmo_dummy_dealname(0))

/* DATECONV: optional struct used in date conversion */

typedef struct {
    int    dateconv_trno ;  /* tr. number */
    } DATECONV ;


/* ICMOSOLVER: structure used in ICMO_SOLVER() */

typedef struct _ICMOSOLVER {

    /* Deal info */
    ICMO  *icmosolver_icmop       ; /* deal info, already run CF */

    /* Info for XVAL */
    int    icmosolver_xval_type   ; /* ICMOSOLVER_XVALTYPE_xx */
#define ICMOSOLVER_XVALTYPE_USER        1001 /* user interpreted parameter */
#define ICMOSOLVER_XVALTYPE_CPR         1002 /* constant CPR */
#define ICMOSOLVER_XVALTYPE_PSA         1003 /* constant PSA */
#define ICMOSOLVER_XVALTYPE_CDR         1004 /* constant CDR */
#define ICMOSOLVER_XVALTYPE_SEV         1005 /* loss severity */
#define ICMOSOLVER_XVALTYPE_SDR         1006 /* constant SDR default */
#define ICMOSOLVER_XVALTYPE_SYMVAR_BASE 1007 /* #symvar -- must be last */
    double icmosolver_xval_min    ; /* low boundary of xval */
    double icmosolver_xval_max    ; /* high boundary of xval */
    double icmosolver_xval_tol    ; /* tolerance of xval */

    /* Info for YVAL */
    int    icmosolver_yval_type   ; /* { WAL|ACCUMLOSS|USER|FIRSTWD } */
#define ICMOSOLVER_YVALTYPE_USER        5001 /* user interpreted parameter */
#define ICMOSOLVER_YVALTYPE_TRWAL       5002 /* tranche WAL */
#define ICMOSOLVER_YVALTYPE_TRLOSS      5003 /* tranche accumulated loss */
#define ICMOSOLVER_YVALTYPE_TRPRICE     5004 /* tranche agg price (with icmot_yield as input) */
#define ICMOSOLVER_YVALTYPE_TRFIRSTWD   5005 /* tranche has a write down*/
#define ICMOSOLVER_YVALTYPE_TRYIELD     5006 /* tranche Yield */
    int    icmosolver_yval_itemno ; /* trno, groupno etc. */
    double icmosolver_yval_target ; /* target yval */

    /* Info set by user prepayment function */
    int    icmosolver_cfassum_freeze; /* flags to force freeze CFASSUM info on loan-by-loan basis */

    /* Info used by _user_fcn */
    double ((CALLBK_FCN_PREFIX *icmosolver_user_fcn)
        (Args_icmosolver_user_fcn)); /* callback fcn to handle ..VALTYPE_USER */
    void  *icmosolver_user_infop  ;  /* user can attach info here to be used in callback fcn */

    /* Info regarding # of iterations */
    int   icmosolver_max_iterations ; /* input - max # if iterations for solving. */
    int   icmosolver_n_iterations   ; /* output - # of iterations to find solution */

    /* Info for error handling */
    char *icmosolver_errmsg ;  /* message for error condition */
    } ICMOSOLVER ;


/* ICMOUTIL: optional structure used in ICMOUTIL_xx functions */
typedef struct {
    void  *icmoutil_holiday_list_cache;
    } ICMOUTIL ;


/* ICMODEAL_xx:  How deal will be analyzed */

#define ICMODEAL_NEW                    0   /* reverse-engineering deals */
#define ICMODEAL_SEASONED_POOLS         1   /* deal with individual pools */
#define ICMODEAL_SEASONED_CLUSTERS      2   /* deal with clustered collat */
#define ICMODEAL_SEASONED_WAVG          3   /* deal with one wavg collateral */
#define ICMODEAL_SEASONED_EXPLODE       4   /* expand any Mega/Giant pools */
#define ICMODEAL_SEASONED_SCHED         5   /* like _POOLS, but no CDU file */
#define ICMODEAL_SEASONED_OPTIMAL       6   /* use all pools or clustering based on deal feature to speed up while preserve all pool accuracy in cashflows */
#define ICMODEAL_SEASONED_WAVG_PRECALC  7   /* Use pre-calculated WAVG information from CDU if available, otherwise parse in ICMODEAL_SEASONED_WAVG mode.
                                               This mode provides faster parsing but may produce less accurate results compared to ICMODEAL_SEASONED_WAVG,
                                               especially if the latter is run with icmomisc_cluster.cluster_with_amort_sched flag*/


/* ICMO_CLUSTER_xx:  The deal's current cluster state */

#define ICMO_CLUSTER_NO            0  /* loan level collat */
#define ICMO_CLUSTER_YES           ICMODEAL_SEASONED_CLUSTERS     /* icmo_deal(CLUSTERS mode) or icmo_cluster_collat(CLUSTERS mode) */
#define ICMO_CLUSTER_WAVG          ICMODEAL_SEASONED_WAVG         /* icmo_deal(WAVG mode) or icmo_cluster_collat(WAVG mode) */
#define ICMO_CLUSTER_WAVG_PRECALC  ICMODEAL_SEASONED_WAVG_PRECALC /* icmo_deal(WAVG mode) or icmo_cluster_collat(WAVG mode) */

/* ICMODEALCAT_xx:  Major deal category    Administrator, Collateral   */

#define ICMODEALCAT_AGENCY_ADMIN  0    /* Agency-admin, Agency-backed mtg */
#define ICMODEALCAT_PRIVATE       1    /* Private-admin, Agency-backed mtg*/
#define ICMODEALCAT_WHOLE_LOAN    2    /* Whole loans mtg */
#define ICMODEALCAT_POOL_MBS      3    /* Deal is really a pool/loan  */
#define ICMODEALCAT_SWAP          4    /* Deal is really a swap       */
#define ICMODEALCAT_BOND          5    /* Deal is really a bond       */
#define ICMODEALCAT_DEBENTURE     6    /* Deal is really a IAN/PLN    */
#define ICMODEALCAT_COVERED_BOND  7    /* Deal is really a covered bond */
#define ICMODEALCAT_AGENCY_CREDIT 8    /* Agency Credit */

/* ICMOASSETBACK_xx:  */
#define ICMOASSETBACK_LOAN         0  /* Normal whole loan */
#define ICMOASSETBACK_CREDITCARD   1  /* Asset-backed credit card deal */
#define ICMOASSETBACK_AUTOLOAN     2  /* Asset-backed car loans deal */
#define ICMOASSETBACK_HOMEEQUITY   3  /* Asset-backed home equity deal */
#define ICMOASSETBACK_MANUHOUSE    4  /* Asset-backed Manufactured Housing */
#define ICMOASSETBACK_FLOORPLAN    5  /* Asset-backed floor plans */
#define ICMOASSETBACK_EQUIPMENT    6  /* Asset-backed equipment deal */
#define ICMOASSETBACK_STUDENTLOANS 7  /* Asset-backed student loans */
#define ICMOASSETBACK_RECEIVABLES  8  /* Asset-backed trade receivables deal */
#define ICMOASSETBACK_COMMERCIAL   9  /* Commercial loan */
#define ICMOASSETBACK_AGRICULTURE 10  /* farmer mac loans */
#define ICMOASSETBACK_FRANCHISE   11  /* franchise loans */
#define ICMOASSETBACK_RV          12  /* recreation vehicle */
#define ICMOASSETBACK_MARINE      13
#define ICMOASSETBACK_MOTORCYCLE  14
#define ICMOASSETBACK_AUTOLEASE   15
#define ICMOASSETBACK_AIRPLANE    16
#define ICMOASSETBACK_CLO         17
#define ICMOASSETBACK_HEALTHRECEIVABLES  18
#define ICMOASSETBACK_CLN                19
#define ICMOASSETBACK_CDO                20
#define ICMOASSETBACK_SMALLBUSINESS      21
#define ICMOASSETBACK_CONSUMER           22
#define ICMOASSETBACK_TAXLIEN            23
#define ICMOASSETBACK_PROJECT            24
#define ICMOASSETBACK_JPMORTGAGE         25 /* Japanese Mortgage Loan */
#define ICMOASSETBACK_TIMESHARE          26
#define ICMOASSETBACK_STCD               27 /* Single Tranche Credit Derivative */
#define ICMOASSETBACK_REVERSEMORTGAGE    28
#define ICMOASSETBACK_WHOLEBUSINESS      29
#define ICMOASSETBACK_N_TYPES            30 /* number of ICMOASSETBACK_xxx */

/* ICMOCOLLATCAT_xx:  Collateral category  */

#define  ICMOCOLLATCAT_POOL        0    /* Mortgage pool */
#define  ICMOCOLLATCAT_LOAN        1    /* Mortgage loan */
#define  ICMOCOLLATCAT_REMIC       2    /* Reremic collateral */
#define  ICMOCOLLATCAT_LEASE       3    /* Lease  */
#define  ICMOCOLLATCAT_TRUST       4    /* Trust  */
#define  ICMOCOLLATCAT_HIYLD       5    /* High Yield Bond */
#define  ICMOCOLLATCAT_RECEIV      6    /* Receivable */
#define  ICMOCOLLATCAT_REF         7    /* Reference collateral */
#define  ICMOCOLLATCAT_SWAP        8    /* Swap */
#define  ICMOCOLLATCAT_CASH        9    /* Cash */
#define  ICMOCOLLATCAT_EQUITY     10    /* equity */
#define  ICMOCOLLATCAT_TERMLOAN   11    /* term loan */
#define  ICMOCOLLATCAT_REVOLVING  12    /* revolving asset */
#define  ICMOCOLLATCAT_PSEUDO     13    /* pseudo pool, for externally generated cf */
#define  ICMOCOLLATCAT_REVENUE    14    /* revenue asset */

#define ICMO_DEAL_WITH_LOSSES(icmop) ((icmop)->icmo_deal_category == ICMODEALCAT_WHOLE_LOAN    || \
                                      (icmop)->icmo_deal_category == ICMODEALCAT_AGENCY_CREDIT || \
                                      (icmop)->icmo_deal_category == ICMODEALCAT_COVERED_BOND )

/* ICMODISTRIB_xx:  distribution level for deal */
#define ICMODISTRIB_UNRESTRICTED          0
#define ICMODISTRIB_RESTRICTED            1

/* ICMOREMIC_xx: is deal a REMIC flag */

#define ICMOREMIC_UNKNOWN         0    /* REMIC status not specified   */
#define ICMOREMIC_NO              1    /* Deal is not a REMIC          */
#define ICMOREMIC_YES             2    /* Deal is a REMIC              */

/* ICMOCDICOLLAT_xx:  if ICMODEAL_NEW, selects CDI collateral section */

#define ICMOCDICOLLAT_CLOSING     0 /* closing collateral */
#define ICMOCDICOLLAT_PRICING     1 /* pricing/prospectus collateral */
#define ICMOCDICOLLAT_TAX_CLOSING 2 /* use any tax collat, else closing */
#define ICMOCDICOLLAT_TAX_PRICING 3 /* use any tax collat, else pricing */

/* ICMOEXPLODE_xx: ICMOMISC setting to explode megas/giants/platinums */

#define ICMOEXPLODE_NO            0 /* explode according to icmo_deal() */
#define ICMOEXPLODE_YES           1 /* force mega explosion             */
#define ICMOEXPLODE_WAVG          2 /* mega WWW from average of underlying pools */

/* ICMOACCEPTCURR_xx: whether to permit deals with CURRENCY references */

#define ICMOACCEPTCURR_NO        0 /* Exclude deals with CURRENCY reference */
#define ICMOACCEPTCURR_YES       1 /* Accept deals with CURRENCY reference */
#define ICMOACCEPTCURR_PARSEREAD 2 /* Read all CURRENCYs at parsing & none afterward */


/* ICMOSETTL_xx: basic settlement rules that will be followed */

#define ICMOSETTL_NORMAL      0     /* FNMA, etc. deals */
#define ICMOSETTL_FHLMC       1     /* Non-Gold Freddie-administered */
#define ICMOSETTL_FHLMC_GOLD  2     /* Gold Freddie-administered */


/* ICMODUEBILL_xx:  Next payment entitlement if after record date */

#define ICMODUEBILL_DEFAULT  -1
#define ICMODUEBILL_0DELAY    0     /* Yes only if 0-day-delay floater */
#define ICMODUEBILL_YES       1     /* Yes for all tranches */


/* ICMOCOLLAT_xx:  Controls creation of COLLAT pseudo tranche, plus
                    pseudo whole loan class and extern credit tranches */

#define ICMOCOLLAT_NONE          0 /* Don't create such pseudo tranches */
#define ICMOCOLLAT_NET           1 /* COLLAT tr cashflow is net coupon */
#define ICMOCOLLAT_GROSS         2 /* COLLAT tr cashflow is gross rate */
#define ICMOCOLLAT_SERV          3 /* COLLAT tr cashflow is agg servicing IO strip */
#define ICMOCOLLAT_SUBSERV       4 /* COLLAT tr cashflow is sub-servicing IO strip */
#define ICMOCOLLAT_MASTSERV      5 /* COLLAT tr cashflow is master servicing IO strip */
#define ICMOCOLLAT_TRUSTEE       6 /* COLLAT tr cashflow is trustee IO strip */
#define ICMOCOLLAT_ALL           7 /* Signal to make all collat tranches for mbs pool option */


/* ICMOMISC_USE_HIST_xx:  If settling in past, #months of actual hist */

#define ICMOMISC_USE_HIST_ALL       999  /* Use all available history */
#define ICMOMISC_USE_HIST_ASOFDATE 1000  /* Use no history and ignore CDU after bond settldate */

/* Sets icmomisc_alteruse.altu_limit_hist_lookback #mos before today's date, not settle date */
#define ICMOMISC_LIMIT_HIST_LOOKBACK_FROM_TODAY(icmomiscp,n) \
     { (icmomiscp)->icmomisc_alteruse.altu_limit_hist_lookback = ((n)-ICMOMISC_USE_HIST_ALL); }

/* ICMOINDEX_xx_RESOLUTION: Call index function: */

#define ICMOINDEX_DEFAULT_RESOLUTION 0  /* Once per index e.g. COFI_11 */
#define ICMOINDEX_BY_SUBNAME_RESOLUTION 1 /* Once per index per subname*/
#define ICMOINDEX_BY_TRANCHE_RESOLUTION 2 /* Once per index per flt.tr.*/

/* ICMO_IGNOREDESCR_xx: Values for icmomisc_alteropt.alto_ignore_descriptive_info
   Flags to not allocate and fill structures for descriptive information not directly used for cashflows calculations.
   Note: use binary mask concept      */
#define ICMO_IGNOREDESCR_NONE            0x00 /* Default */
#define ICMO_IGNOREDESCR_LOANINFO        0x01 /* not allocate and fill LOANATTR and LOANSTAT structures. Still will be allocated if needed for loanattr_draw_term, loanattr_n_balloon_extensions etc. */
#define ICMO_IGNOREDESCR_LOANDATA        0x02 /* not allocate and fill LOANDATA structures which are not in the REQUIRED_ASSET_INFOS list. List of LOANDATA structures loanattr_loandatap is not accessible */
#define ICMO_IGNOREDESCR_TRIGGERS        0x04 /* skip calculations for triggers and CDOTESTS not impacting cashflows */
#define ICMO_IGNOREDESCR_SUBSET_GROUPS   0x08 /* skip calculations for SUBSET groups not impacting cashflows. Don't make PSEUDO_COLLAT tranches for this SUBSET groups */
#define ICMO_IGNOREDESCR_XRS_GROUPS      0x10 /* skip calculations for XRS SUBSET groups not impacting cashflows. Don't make PSEUDO tranches for these groups */
#define ICMO_IGNOREDESCR_GROUPS          0x18 /* ICMO_IGNOREDESCR_SUBSET_GROUPS|ICMO_IGNOREDESCR_XRS_GROUPS : skip calculations for all pseudo groups not impacting cashflows. Don't make pseudo tranches for these groups */
#define ICMO_IGNOREDESCR_PREPHIST        0x20 /* not fill PREPHIST structure */
#define ICMO_IGNOREDESCR_ALL ( ICMO_IGNOREDESCR_LOANINFO | ICMO_IGNOREDESCR_LOANDATA | ICMO_IGNOREDESCR_TRIGGERS | ICMO_IGNOREDESCR_GROUPS | ICMO_IGNOREDESCR_XRS_GROUPS | ICMO_IGNOREDESCR_PREPHIST )

/* ICMOMBSLOOP_READ_ADDL_xx: */
/*                  Note: use binary mask concept      */
#define ICMOMBSLOOP_READ_ADDL_NONE 0 /* Default */
#define ICMOMBSLOOP_READ_ADDL_GEO  1 /* Geographic data / Origination year data / monthly */
#define ICMOMBSLOOP_READ_ADDL_HD3  2 /* same level as HDR / static info */
#define ICMOMBSLOOP_READ_ADDL_QTL  4 /* Quartile file / monthly */
#define ICMOMBSLOOP_READ_ADDL_BO   8 /* Breakout file / monthly */
#define ICMOMBSLOOP_READ_ADDL_APPLY_TO_REMIC 16 /* read additional info when parsing agency pools in CDU files */
#define ICMOMBSLOOP_READ_ADDL_PRG  32 /* program file / monthly */
#define ICMOMBSLOOP_READ_ADDL_WWW  64 /* Wac/Wam/Wala file / monthly / GNMA supplement data provided after C Tape */

/* ICMOREPCOLL_xx: replace collateral mode */

#define ICMOREPCOLL_NO      0 /* Don't free old collateral list */
#define ICMOREPCOLL_YES     1 /* Free old collateral list */

/* ICMOINFO_1PER_WHEN_xx: info_1period_fcn control modes */
#define ICMOINFO_1PER_WHEN_NONE            0x00 /* not to call */
#define ICMOINFO_1PER_WHEN_END             0x01 /* called at end of each CF period */
#define ICMOINFO_1PER_WHEN_AFTER_COLLAT    0x02 /* called after processing collateral of each period */
#define ICMOINFO_1PER_WHEN_BEFORE_PAYRULES 0x04 /* called before executing payment rules each period */

/* ICMOINFO_1PER_RET_xx: info_1period_fcn return values */
#define ICMOINFO_1PER_RET_CONT      0 /* continue CF run */
#define ICMOINFO_1PER_RET_STOP      1 /* stop CF run */

/* ICDUFACTOR_xx and ICDUCOUPON_xx:  also for settlement rules */

#define ICDUFACTOR_OK         0     /* use factor in base CDU file */
#define ICDUFACTOR_LAG1       1     /* use prev factor in base CDU file*/

#define ICDUCOUPON_OK             0  /* use coupon in base CDU file */
#define ICDUCOUPON_IDXRESET       1  /* calc coupon from IDX cur mo */
#define ICDUCOUPON_IDXRESET_LAG1  2  /* calc coupon from IDX prev mo */
#define ICDUCOUPON_IDXRESET_LEAD1 3  /* calc coupon from IDX next mo */


/* ICMO_DAYCOUNT_xx: method to count days  */

#define ICMO_DAYCOUNT_CF_DEFAULT    (-2) /* for force daycount_method*/
#define ICMO_DAYCOUNT_DEFAULT       (-1) /* for force daycount_method*/
#define ICMO_DAYCOUNT_30360         0
#define ICMO_DAYCOUNT_ACTUAL360     1
#define ICMO_DAYCOUNT_ACTUAL365     2
#define ICMO_DAYCOUNT_ACTUALACTUAL  3
#define ICMO_DAYCOUNT_30365         4
#define ICMO_DAYCOUNT_ACTUALCY360   5    /* same as ACTUAL360 but not count 2/29 */
#define ICMO_DAYCOUNT_ACTUALCY365   6    /* same as ACTUAL365 but not count 2/29 */
#define ICMO_DAYCOUNT_VECTOR        7    /* diff daycount method apply to diff months */
#define ICMO_DAYCOUNT_MAX   ICMO_DAYCOUNT_VECTOR


/* ICMO_BUSINESSDAY_xx: adjust actual payment day around wkend/holidays */

#define ICMO_BUSINESSDAY_IGNORE_ALL   (-3) /* for force businessday_method to NONE for tranches, collateral and other entities  */
#define ICMO_BUSINESSDAY_CF_DEFAULT   (-2) /* for force businessday_method */
#define ICMO_BUSINESSDAY_DEFAULT      (-1) /* for force businessday_method*/
#define ICMO_BUSINESSDAY_NONE           0  /* No business day convention */
#define ICMO_BUSINESSDAY_FOLLOWING      1  /* Following business day */
#define ICMO_BUSINESSDAY_PRECEDING      2  /* Preceding business day */
#define ICMO_BUSINESSDAY_MFOLLOWING     3  /* Modified Following day */
#define ICMO_BUSINESSDAY_EOMFOLLOWING   4  /* Last businessday for current month */
#define ICMO_BUSINESSDAY_EOMPRECEDING   5  /* Last businessday for previous month */
#define ICMO_BUSINESSDAY_ABSOLUTE       6  /* The nth business day of the month */
#define ICMO_BUSINESSDAY_OFFSET         7  /* Normal payment date plus business day offset */
#define ICMO_BUSINESSDAY_CD_OFFSET      8  /* Normal payment date plus calendar days offset */
#define ICMO_BUSINESSDAY_CD_OFFSET_30360  9   /* Normal payment date plus calendar days offset, assuming 30360 calendar if crossing over to the next month */
#define ICMO_BUSINESSDAY_EOMNONE          10  /* EOM, No business day convention */
#define ICMO_BUSINESSDAY_EOMNEXTBDAY      11  /* Next business day after current EOM */
#define ICMO_BUSINESSDAY_FOLLOWING_OFFSET 12  /* Following business day plus business day offset */
#define ICMO_BUSINESSDAY_COMBINATION      13  /* Combination of 2 or more BUSINESSDAY methods */


/* ICDUQA_xx:  how was CDU created? */

#define ICDUQA_OK            0       /* CDU passed QA */
#define ICDUQA_AUTO          1       /* Automatic tr factor correction */
#define ICDUQA_FLASH         2       /* Collateral only, no tr factors */
#define ICDUQA_RETROFIT      3       /* No history avail; force-fitted */
#define ICDUQA_COLLAT_SCALED 4       /* Auto tr & pool factor correction */
#define ICDUQA_NO_TRANCHE_CF 5       /* Deal has no payrule, for info only */
#define ICDUQA_EECOL         6       /* Retrofit tranche/deal info with updated asset info */


/* ICMIRESET_xx:  status of index reset needs */

#define ICMIRESET_NONE        0     /* No floaters, or all coupons OK */
#define ICMIRESET_NEED_IDX    1     /* Need IDX reset file or not found*/
#define ICMIRESET_HAVE_IDX    2     /* Did reset indexes from IDX file */


/* ICMOTRANCHE_xx:  how simple is the tranche. Block(s) have: */

#define ICMOTRANCHE_NORMAL    0    /* same coupon & accrual periods */
#define ICMOTRANCHE_ECONOMIC  1    /* diff coupon; same accrual periods*/
#define ICMOTRANCHE_MIXED     2    /* diff coupon & accrual periods */


/* ICMOCALLABLE_xx:  callable by what */

#define ICMOCALLABLE_BY_NONE       0  /* not callable */
#define ICMOCALLABLE_BY_ISSUER     1  /* callable by issuer */
#define ICMOCALLABLE_BY_TRANCHE    2  /* callable by a tranche in deal */
#define ICMOCALLABLE_BY_EXTERNAL   3  /* callable by external investor */


/* ICMOTACCRUE_xx:  is the tranche currently accruing? */

#define ICMOTACCRUE_NO        0    /* tranche is not now accruing */
#define ICMOTACCRUE_PARTIAL   1    /* tranche is but not at coupon rate */
#define ICMOTACCRUE_YES       2    /* tranche is accruing @ coupon rate */


/* ICMOSPDT_xx:  types of prepayment speed models */

#define ICMOSPDT_VSMM     11      /* speeds are a vector of SMM's */
#define ICMOSPDT_VCPR     12      /* speeds are a vector of CPR's */
#define ICMOSPDT_VPSA     13      /* speeds are a vector of PSA's */
#define ICMOSPDT_VABS     14      /* speeds are a vector of ABS's */
#define ICMOSPDT_VMHP     15      /* speeds are a vector of MHP's */
#define ICMOSPDT_VHEP     16      /* speeds are a vector of MHP's */
#define ICMOSPDT_VPPC     17      /* speeds are a vector of PPC's */
#define ICMOSPDT_VCPY     18      /* same as VCPR, but no prepay during Yield Maintenance formula */
#define ICMOSPDT_VCPP     19      /* same as VCPR, but no prepay during any penalty */
#define ICMOSPDT_VSPR     20      /* same as VCPR, but not compounded  */
#define ICMOSPDT_VCPB     21      /* same as VCPR, except ARM fullprepay at next reset date */
#define ICMOSPDT_VORIGSMM 22      /* same as VSMM, but as a percentage of asset's original balance  */
#define ICMOSPDT_VORIGCPR 23      /* same as VCPR, but as a percentage of asset's original balance  */
#define ICMOSPDT_VORIGSPR 24      /* same as VSPR, but as a percentage of asset's original balance  */
#define ICMOSPDT_VPSJ     25      /* Japanese version of PSA */
#define ICMOSPDT_VORIGAGGSMM  26  /* SMM prepayment rates based on aggregate collat origbal */
#define ICMOSPDT_VHPC     27      /* HMBS reverse mortgage curve */
#define ICMOSPDT_VHDC     28      /* HECM Draw Curve for reverse mortgages */
#define ICMOSPDT_VSCRIPT  80      /* vector of PrepayScript %multipliers */
#define ICMOSPDT_FNMPS    90      /* fnma prepayment scenario */

/* ICMOSPDT_PPMDL_xx: Built-in prepayment functions. */
#define ICMOSPDT_PPMDL_PRICING     50 /* pricing speeds and init index, under development */
#define ICMOSPDT_PPMDL_DEMO        51 /* unmanaged Intex prepay function */
#define ICMOSPDT_PPMDL_DAVIDSON    52 /* Andrew Davidson & Co., Inc. mbs prepay model */
#define ICMOSPDT_PPMDL_ESPIEL      53 /* Espiel Inc. prepay model */
#define ICMOSPDT_PPMDL_RISKMONI    54 /* Risk Monitors prepay model (Not available)*/
#define ICMOSPDT_PPMDL_INTEX       55 /* Intex prepay model */
#define ICMOSPDT_PPMDL_ADP_ABS     56 /* Andrew Davidson & Co., Inc. abs prepay model */
#define ICMOSPDT_PPMDL_ADP_MBSABS  57 /* Andrew Davidson & Co., Inc. abs and mbs models */
#define ICMOSPDT_PPMDL_ADP_50      58 /* Andrew Davidson & Co., Inc. version 5.0 */
#define ICMOSPDT_PPMDL_ADP_CREDIT  59 /* Andrew Davidson & Co., Inc. credit/prepay combo model */
#define ICMOSPDT_PPMDL_AFT_DEFAULT 60 /* AFT default model  */
#define ICMOSPDT_PPMDL_ARMFIXTBA   70 /* INTERNAL ONLY: tba arm pool, we need a way to capture index dependency */

/*  ICMOPREPAY_xx  Flag to indicate current prepayment restriction for loan */

#define ICMOPREPAY_OK                  0   /* no lockout or yield maint fee */
/* Controlled by ICMOPREPAYPENALTY_NOLOCKOUT:*/
#define ICMOPREPAY_LOCKOUT             2   /* prepays locked out  */
#define ICMOPREPAY_DEFEASANCE          3   /* (ICMOPREPAY_LOCKOUT + 1) -- Defeasance: treated as lockout for most purposes */
/* Controlled by ICMOPREPAYPENALTY_POINTS:*/
#define ICMOPREPAY_POINTS              4   /* prepay with points (see same cell in ym_vpoints)*/
#define ICMOPREPAY_POINTS_ORIGBAL      5   /* percentage of original balance of loan */
/* Controlled by ICMOPREPAYPENALTY_YM:*/
#define ICMOPREPAY_YM                  8   /* prepay with Yield Maintenance formula*/
#define ICMOPREPAY_NRM                 9   /* (ICMOPREPAY_YM + 1) -- Negative Rate Movement: treated as YM from most purposes */
#define ICMOPREPAY_MAX                32   /* used only in combination with other flags */
#define ICMOPREPAY_MIN                64   /* used only in combination with other flags */
#define ICMOPREPAY_MAX_YM_OR_POINTS   44   /* (ICMOPREPAY_MAX | ICMOPREPAY_YM | ICMOPREPAY_POINTS) -- max ym or points (see same cell in ym_vpoints)*/
#define ICMOPREPAY_MIN_YM_OR_POINTS   76   /* (ICMOPREPAY_MIN | ICMOPREPAY_YM | ICMOPREPAY_POINTS) -- min ym or points (see same cell in ym_vpoints)*/
#define ICMOPREPAY_RULE78            128   /* YM based on rule 78 */
#define ICMOPREPAY_UNKNOWN_YM        256   /* prepay with unknown Yield Maintenance formula so we return a penaly of 0.0 - usually not provide but we know the length of YM period so must provide some value for penalty. */
#define ICMOPREPAY_MAXIMUM_VALUE     256   /* max value of all prepay flags */

/* ICMOPREPAYPENALTY_xx: Controls prepayment penalty handling, i.e., which ICMOPREPAY_xx flags
   should be recognized and how to handle them.  Use binary mask concept, based on values of
   ICMOPREPAY_xx.  XOR with value of (ICMOPREPAY_LOCKOUT|ICMOPREPAY_RULE78) because the default value
   of 0 indicates that LOCKOUT and RULE78 are included. */

#define ICMOPREPAYPENALTY_MASK          (ICMOPREPAY_LOCKOUT|ICMOPREPAY_RULE78)  /* These are on by default */

#define ICMOPREPAYPENALTY_DEFAULT       0  /* (ICMOPREPAY_LOCKOUT|ICMOPREPAY_RULE78)^ICMOPREPAYPENALTY_MASK
                                              -- lockout-yes, POINTS- no, YM- no */
/* For future use: #define ICMOPREPAYPENALTY_PARSUSEDONLY 1 Parse only if will use */
#define ICMOPREPAYPENALTY_NOLOCKOUT     2  /* (ICMOPREPAY_OK|ICMOPREPAY_RULE78)^ICMOPREPAYPENALTY_MASK
                                              --  lockout- no, POINTS- no, YM- no */
#define ICMOPREPAYPENALTY_POINTS        4  /* (ICMOPREPAY_POINTS|ICMOPREPAY_LOCKOUT|ICMOPREPAY_RULE78)^ICMOPREPAYPENALTY_MASK
                                              -- lockout-yes, POINTS-yes, YM- no */
#define ICMOPREPAYPENALTY_YM          264  /* (ICMOPREPAY_YM|ICMOPREPAY_UNKNOWN_YM|ICMOPREPAY_LOCKOUT|ICMOPREPAY_RULE78)^ICMOPREPAYPENALTY_MASK
                                              -- lockout-yes, POINTS- no, YM-yes */
#define ICMOPREPAYPENALTY_PTINLOCKOUT  20  /* (16|ICMOPREPAY_POINTS|ICMOPREPAY_LOCKOUT|ICMOPREPAY_RULE78)^ICMOPREPAYPENALTY_MASK
                                              -- If prep is allowed in lockout or defeasance, apply points */
#define ICMOPREPAYPENALTY_PTASTEPDOWN  36  /* (32|ICMOPREPAY_POINTS|ICMOPREPAY_LOCKOUT|ICMOPREPAY_RULE78)^ICMOPREPAYPENALTY_MASK
                                               -- Ignore points schedule, use 1st point and do annual step down */
#define ICMOPREPAYPENALTY_MAXVAL      270  /* Maximum value possible */


#define ICMOPREPAYPENALTY_NONE          ICMOPREPAYPENALTY_NOLOCKOUT
#define ICMOPREPAYPENALTY_ONLY_LOCKOUT  ICMOPREPAYPENALTY_DEFAULT
#define ICMOPREPAYPENALTY_YES           (ICMOPREPAYPENALTY_POINTS|ICMOPREPAYPENALTY_YM|ICMOPREPAY_UNKNOWN_YM)


/* ICMOPRP_METHOD_xx: method to apply CPR/SMM etc.
                        must be the same as mbs.h */
#define ICMOPRP_METHOD_FULL_STATISTIC  0  /* statistic full prepay model */
#define ICMOPRP_METHOD_PART_US_NORMAL  1  /* partial prepay, (US mortgage) */
#define ICMOPRP_METHOD_PART_JP_CURTAIL 2  /* partial prepay, curtail remterm (Japan mortgage) */
#define ICMOPRP_METHOD_PART_JP_RECAST  3  /* partial prepay, reduce payment (Japan mortgage) */
#define ICMOPRP_METHOD_FULL_BEFORE_SCHED 4 /* statistic full prepay applied before scheduled pmt */

/* ICMOREVPRP_METHOD_xx: method to apply CPR/SMM etc. for revolving assets
                           must be the same as mbs.h */
#define ICMOREVPRP_METHOD_STANDARD        0  /* partial prepay model, with schedp included */
#define ICMOREVPRP_METHOD_FULL_STATISTIC  1  /* statistic full prepay model with schedp = 0 */

/* ICMOLOSSSEV_METHOD_xx: method to apply loss severity rate.
                            must be the same as mbs.h */
#define ICMOLOSSSEV_METHOD_STANDARD       0  /* standard PSA convention */
#define ICMOLOSSSEV_METHOD_LIQAMT         1  /* apply to final liquidation amt */
#define ICMOLOSSSEV_METHOD_AMOUNT         2  /* specify actual severity amount at liquidation */
#define ICMOLOSSSEV_METHOD_RECOVER_AMOUNT 3  /* specify actual recovery amount at liquidation */
#define ICMOLOSSSEV_METHOD_WL_RECOVER_AMOUNT   4 /* specify recovery amount at liquidation based on original loan balance */
#define ICMOLOSSSEV_METHOD_ALLOW_EXCESS_LOSS  64 /* allow loss in excess of loan balance to create negative CF */
#define ICMOLOSSSEV_METHOD_GROSS             128 /* further reduce recovery by servicer advance and intloss recovery, but in case of ICMOLOSSSEV_METHOD_STANDARD, do not reduce servicer principal advance */
#define ICMOLOSSSEV_METHOD_DISALLOW_NEGLOSS  256 /* disallow negative loss */

/*  PREFUND_LOAN_PREP_xx  Prepay assumption for loans
                            in pre-funded period.
                            must be the same as mbs.h */

#define PREFUND_LOAN_PREP_LOCKOUT 0  /* no prepay allowed */
#define PREFUND_LOAN_PREP_ASZERO  1  /* treat negative wala_psa same as wala_psa = 0 */
#define PREFUND_LOAN_PREP_WCURVE  2  /* extend prepay curve to neg. age */
#define PREFUND_LOAN_PREP_PCURVE  3  /* extend prepay curve but not to neg. prepay */

/*  PREFUND_LOAN_DEF_xx  Default assumption for loans
                            in pre-funded period.
                            must be the same as mbs.h */

#define PREFUND_LOAN_DEF_LOCKOUT 0  /* no prepay allowed */
#define PREFUND_LOAN_DEF_ASZERO  1  /* same as age = 0 */
#define PREFUND_LOAN_DEF_WCURVE  2  /* extend prepay curve to neg. age */
#define PREFUND_LOAN_DEF_PCURVE  3  /* extend prepay curve but not to neg. prepay */

/*  ICMODEFAULT_xx  default/loss assumptions */

#define ICMODEFAULT_NONE              0  /* No losses and recovery handling */
#define ICMODEFAULT_VMDR             11  /* default rates as % of current bal */
#define ICMODEFAULT_VCDR             12  /* default rates as % of current bal */
#define ICMODEFAULT_VSDA             13  /* default rates as % of SDA model */
#define ICMODEFAULT_VORIGMDR         14  /* default rates as % of original bal */
#define ICMODEFAULT_VORIGCDR         15  /* default rates as % of original bal */
#define ICMODEFAULT_VAGGMDR          16  /* default rates based on aggregate collat bal */
#define ICMODEFAULT_VSDR             17  /* defaults rates - same as VCDR, but not compounded  */
#define ICMODEFAULT_VORIGSDR         18  /* same as VSDR but as % of original bal */
#define ICMODEFAULT_VSCHMDR          19  /* default rates as % of orig amort bal */
#define ICMODEFAULT_VSCHCDR          20  /* default rates as % of orig amort bal */
#define ICMODEFAULT_VORIGAGGMDR      21  /* default rates based on aggregate origbal */
#define ICMODEFAULT_VREPAYMDR        22  /* for student loan: default rates as % of bal at the beginning of the repayment period */
#define ICMODEFAULT_VFWDAGGMDR       23  /* default rates based on aggregate forecasted collat bal at the future period */
#define ICMODEFAULT_VPLD             24  /* default rates as % of PLD model */
#define ICMODEFAULT_PPMDL_ADP_CREDIT 59  /* Andrew Davidson & Co., Inc. credit/prepay combo model, means user's entry in CFASSUM vects are to scale the forecasts from ADCO for default severity and delinq */
#define ICMODEFAULT_VPHM             90  /* deflts are const% orig bal yrs1-6 */
#define ICMODEFAULT_VPHM2            91  /* like PHM, but use SDA convention */
#define ICMODEFAULT_VMIX             92  /* mixed def units, use cfa_loss_vdeftypes */

/* ICMO_BALLOONLOSS_xx:  icmo_loss_balloon_special loss treatment near the balloon date */

#define ICMO_BALLOONLOSS_NORMAL     0x00  /* same as normal pmt days */

/* bits corresponding to specific attributes */
#define ICMO_BALLOONLOSS_MDR        0x01  /* on balloon date use MDR units */
#define ICMO_BALLOONLOSS_CELL0_D    0x02  /* on balloon date use cfa_loss_vdefaults[0] */
#define ICMO_BALLOONLOSS_CELL0_S    0x04  /* on balloon date use cfa_loss_vseverity[0] */
#define ICMO_BALLOONLOSS_CELL0_L    0x08  /* on balloon date use cfa_loss_vrecov_lags[0] */
#define ICMO_BALLOONLOSS_0_AT_LAG   0x10  /* Set 0 default loss_recov_lag months before balloon */

/* Defined combinations */
#define ICMO_BALLOONLOSS_DS       (ICMO_BALLOONLOSS_CELL0_D|ICMO_BALLOONLOSS_CELL0_S)
#define ICMO_BALLOONLOSS_MDR_D    (ICMO_BALLOONLOSS_MDR|ICMO_BALLOONLOSS_CELL0_D)
#define ICMO_BALLOONLOSS_MDR_DS   (ICMO_BALLOONLOSS_MDR|ICMO_BALLOONLOSS_CELL0_D|ICMO_BALLOONLOSS_CELL0_S)
#define ICMO_BALLOONLOSS_MDR_DL   (ICMO_BALLOONLOSS_MDR|ICMO_BALLOONLOSS_CELL0_D|ICMO_BALLOONLOSS_CELL0_L)
#define ICMO_BALLOONLOSS_MDR_DSL  (ICMO_BALLOONLOSS_MDR|ICMO_BALLOONLOSS_CELL0_D|ICMO_BALLOONLOSS_CELL0_S|ICMO_BALLOONLOSS_CELL0_L)

/* Deprecated names */
#define ICMO_BALLOONLOSS_CELL0      ICMO_BALLOONLOSS_DS
#define ICMO_BALLOONLOSS_CELL0_MDR  ICMO_BALLOONLOSS_MDR_DS
#define ICMO_BALLOONLOSS_CELL0_DSL  ICMO_BALLOONLOSS_MDR_DSL
#define ICMO_BALLOONLOSS_CELL0_DL   ICMO_BALLOONLOSS_MDR_DL

/* ICMOI_xx:  indexes for CMO's, e.g. LIBOR-based coupons */

#define ICMOI_1MO_LIBOR            0
#define ICMOI_3MO_LIBOR            1
#define ICMOI_6MO_LIBOR            2
#define ICMOI_1YR_LIBOR            3
#define ICMOI_3MO_TREAS            4     /* bond-equiv 3mo CMT */
#define ICMOI_1YR_TREAS            5     /* bond-equiv 1yr CMT */
#define ICMOI_5YR_TREAS            6     /* bond-equiv 5yr CMT */
#define ICMOI_7YR_TREAS            7     /* bond-equiv 7yr CMT */
#define ICMOI_10YR_TREAS           8     /* bond-equiv 10yr CMT */
#define ICMOI_COFI11               9     /* 11th district Cost-of-Funds Index */
#define ICMOI_PRIME               10     /* Prime rate charged by banks */
#define ICMOI_3YR_TREAS           11     /* bond-equiv 3yr CMT */
#define ICMOI_2YR_TREAS           12     /* bond-equiv 2yr CMT */
#define ICMOI_6MO_TREAS           13     /* bond-equiv 6mo CMT */
#define ICMOI_YEN                 14     /* #yen/US$ */
#define ICMOI_30YR_TREAS          15     /* bond-equiv 30yr CMT */
#define ICMOI_CONTRACT            16     /* generic contract rate */
#define ICMOI_COF                 17     /* generic Cost Of Funds */
#define ICMOI_6MO_CD              18     /* 6mo. CD, Weekly Avg. */
#define ICMOI_MONEY_MKT           19     /* Money Market (comm'l paper rate) */
#define ICMOI_2YR_LIBOR_SWAP      20     /* 2yr Libor swap rate */
#define ICMOI_10YR_LIBOR_SWAP     21     /* 10yr Libor swap rate */
#define ICMOI_MISC_1              22     /* MISC index. must be last */
#define ICMOI_MISC_2              23     /* MISC index.  .. */
#define ICMOI_MISC_3              24     /* MISC index.  .. */
#define ICMOI_UNKNOWN             25     /* Deal has index from extended list, but flag icmomisc_accept_extended_indexes is not set */

#define ICMOI_MAX                 25    /* Deprecated: replaced by icmo_max_n_index_info */

#define ICMOI_DUMMY    ARMI_DUMMY_INDEX   /* maybe used for indproxy_indextype    */
#define ICMOI_PSEUDO_COLL_NETRATE 9991     /* bi_flt_indextype only */

/* ITR_INDXDEP_xx  */
#define ITR_INDXDEP_NONE     (-1)    /* tranche uses no indexes */
#define ITR_INDXDEP_MULT     (-2)    /* tranche uses multiple indexes */

/* ICMO_DISC_MARGIN_OVER_xx: values for icmo_calc_disc_margin */

#define ICMO_DISC_MARGIN_OVER(x) (x+1000)                 /* calc discount margin over given ith_index referenced in the deal */
#define ICMO_DISC_MARGIN_OVER_EXPLICIT_FCAST_VECT  9999   /* calc discount margin over explicit vector icmo_index_fcastp->inf_vindex_rates */

#define ICMO_HORIZON_REINV_INDEX ICMO_DISC_MARGIN_OVER

/* ICMOPY_xx:  given price or yield, compute yield or price, etc. */

#define ICMOPY_NONE            0  /* no cashflow analytics */
#define ICMOPY_PRICEAGG        1  /* calc given price/tranche */
#define ICMOPY_PRICEAGGI       2  /* calc given price/tranche + accrued */
#define ICMOPY_PRICE100        3  /* calc given price/100 */
#define ICMOPY_PRICE100I       4  /* calc given price/100 + accrued */
#define ICMOPY_YIELD           5  /* calc given yield, in % */
#define ICMOPY_DISC_MARGIN     6  /* calc given discount margin, in bp */
#define ICMOPY_SPREAD          7  /* calc given spread-to-yldcrv, in bp */
#define ICMOPY_DISC_MARGIN_BEQ 8  /* calc given BEEM, in bp */
#define ICMOPY_GET_AVAILABLE_CASHFLOWS 9 /* For altu_allow_access_known_cf_nmon: Output CF starting from icmo_stats_access_known_cf_nmon before latest known historical month.
                                            If icmo_stats_access_known_cf_nmon = 0 for settle in the future output cashflows starting from 1st forecasted month. No cashflows analytics  */
#define ICMOPY_FORECASTED_CASHFLOWS ICMOPY_GET_AVAILABLE_CASHFLOWS
#define ICMOPY_FILL_STATSPARAM 10 /* fill icmot_statsparam structure */


/* ICMOYLDCRV_SPREAD_xx:  values for icmo_yldcrv_spread_method */

#define ICMOYLDCRV_SPREAD_WAL_INTERPOLATE                   0 /* spread at WAL, linear interp to yldcrv */
#define ICMOYLDCRV_SPREAD_WAL_NEAREST                       1 /* spread at WAL, closest node on yldcrv */
#define ICMOYLDCRV_SPREAD_MD_INTERPOLATE                    2 /* spread at modified duration, linear interp to yldcrv */
#define ICMOYLDCRV_SPREAD_MD_NEAREST                        3 /* spread at modified duration, closest node on yldcrv */
#define ICMOYLDCRV_SPREAD_EXPLICIT_MATURITY                 4 /* spread at specified time on yldcrv */
#define ICMOYLDCRV_SPREAD_EXPLICIT_VALUE                    5 /* to specified rate value */
#define ICMOYLDCRV_SPREAD_NOMINAL                           6 /* nominal spread to yldcrv */
#define ICMOYLDCRV_SPREAD_WAL_INT_INTERPOLATE               7 /* spread at icmot_wal_int, linear interp to yldcrv */
#define ICMOYLDCRV_SPREAD_WAL_INT_NEAREST                   8 /* spread at icmot_wal_int, closest node on yldcrv */
#define ICMOYLDCRV_SPREAD_WAL_PRINC_INTERPOLATE             9 /* spread at icmot_wal_princ, linear interp to yldcrv */
#define ICMOYLDCRV_SPREAD_WAL_PRINC_NEAREST                10 /* spread at icmot_wal_princ, closest node on yldcrv */
#define ICMOYLDCRV_SPREAD_WAL_IMPLIED_BALANCE_INTERPOLATE  11 /* spread at icmot_wal_implied_balance, linear interp to yldcrv */
#define ICMOYLDCRV_SPREAD_WAL_IMPLIED_BALANCE_NEAREST      12 /* spread at icmot_wal_implied_balance, closest node on yldcrv */

/* ICMOFMT_xx:  codes for icmo_fmtdate  date formatter */

#define ICMOFMT_YYYYMMDD      0    /* e.g., "19901101" */
#define ICMOFMT_MONTHDDYYYY   1    /* e.g., "November 1, 1990" */
#define ICMOFMT_MONDDYY       2    /* e.g., "Nov 01, 90" */
#define ICMOFMT_MONYY         3    /* e.g., "Nov 90" */
#define ICMOFMT_MONYYX        4    /* e.g., "Nov90" */
#define ICMOFMT_MMYY          5    /* e.g., "11/90" */
#define ICMOFMT_YYMM          6    /* e.g., "9011" */
#define ICMOFMT_DDMONYY       7    /* e.g., "25-Aug-94" or "25-Aug-11"*/
#define ICMOFMT_DDMONyyYY     8    /* e.g., "25-Aug-94" or "25-Aug-2011"*/
#define ICMOFMT_MMDDYY        9    /* e.g., "08/25/94" */
#define ICMOFMT_MMDDYYYY     10    /* e.g., "08/25/1994" */


/* ICMOAGENCY_xx:  Collateral data source */

#define ICMOAGENCY_GNMA         0
#define ICMOAGENCY_FNMA         1
#define ICMOAGENCY_FHLMC        2
#define ICMOAGENCY_UST          3
#define ICMOAGENCY_CASH         4  /* cash collateral element */
#define ICMOAGENCY_USER         5  /* user defined loan as a deal */
                                   /* value 6 is not used */
#define ICMOAGENCY_GNMA2        7
#define ICMOAGENCY_FHLMG        8  /* only as retn of ICMO_COLLAT_TYPE */
#define ICMOAGENCY_BDC          9  /* corporate bond */
#define ICMOAGENCY_WL          10  /* whole loan's individual mtg */
#define ICMOAGENCY_MTG          ICMOAGENCY_WL
#define ICMOAGENCY_RFC         11  /* Residential Funding Corp */
#define ICMOAGENCY_RYL         12  /* Ryland */
#define ICMOAGENCY_RYF         13  /* Ryland for Fund America */
#define ICMOAGENCY_ADV         14  /* Advanta */
#define ICMOAGENCY_CWF         15  /* Countrywide Funding */
#define ICMOAGENCY_CWC         16  /* Countrywide Conduit */
#define ICMOAGENCY_INM         17  /* Independent National Mortgage */
#define ICMOAGENCY_CMF         18  /* Chase Mortgage */
#define ICMOAGENCY_CAP         19  /* Capstead       */
#define ICMOAGENCY_CMC         20  /* CMS Securities */
#define ICMOAGENCY_GEC         21  /* GE Capital Mortgage */
#define ICMOAGENCY_SMS         22  /* Sears Mortgage Securities  */
#define ICMOAGENCY_NASC        23  /* Nomura Asset Securities  */
#define ICMOAGENCY_PNC         24  /* PNC Securities (was sears) */
#define ICMOAGENCY_CMS         25  /* Citicorp Mortgage Sec.  */
#define ICMOAGENCY_SASI        26  /* Securitized Asset Services Corp */
#define ICMOAGENCY_GTMH        27  /* Green Tree -- Lehman */
#define ICMOAGENCY_ABS         28  /* Asset backed securities */
#define ICMOAGENCY_RTC         29  /* RTC Whole Loan */
#define ICMOAGENCY_BT          30  /* Banker's Trust(also Vendee) */
#define ICMOAGENCY_PHM         31  /* Prudential Home Mortgage */
#define ICMOAGENCY_FNMF        32  /* FNMA Multifamily */
#define ICMOAGENCY_CHEM        33  /* Chemical */
#define ICMOAGENCY_TMS         34  /* The Money Store */
#define ICMOAGENCY_ASW         35  /* American SouthWest Financial */
#define ICMOAGENCY_NMB         36  /* Norwest */
#define ICMOAGENCY_CMHE        37  /* Conti Mortgate Home Equity */
#define ICMOAGENCY_FNWL        38  /* FNMA whole loans */
#define ICMOAGENCY_VMT         39  /* Vendee: VETERANS AFFAIRS */
#define ICMOAGENCY_MOR         40  /* Morserv */
#define ICMOAGENCY_MSC         41  /* Merit */
#define ICMOAGENCY_PHPL        42  /* PHM Private */
#define ICMOAGENCY_FNMR        43  /* FNM Reremic MultiFamily */
#define ICMOAGENCY_BSM         44  /* Bear Stearn WL */
#define ICMOAGENCY_IMCH        45  /* IMCH HomeEquity */
#define ICMOAGENCY_GCA         46  /* Greenwich Capital */
#define ICMOAGENCY_ADHE        47  /* Advanta HomeEquity */
#define ICMOAGENCY_FUR         48  /* First Union */
#define ICMOAGENCY_LAS         49  /* Lasalle */
#define ICMOAGENCY_FASI        50  /* Financial Asset Serv. Inc */
#define ICMOAGENCY_PBHE        51  /* Provident Bank */
#define ICMOAGENCY_AFC         52  /* Alliance Funding Corp. */
#define ICMOAGENCY_FBM         53  /* First Boston Mortgage */
#define ICMOAGENCY_EQHE        54  /* Equicredit */
#define ICMOAGENCY_GTHE        55  /* Greentree Home Equity */
#define ICMOAGENCY_FMAC        56  /* FarmerMac */
#define ICMOAGENCY_AMRS        57  /* Amresco */
#define ICMOAGENCY_GEHE        58  /* GE Home Eq */
#define ICMOAGENCY_CHHE        59  /* Champion Mortgage */
#define ICMOAGENCY_HDMS        60  /* Headlans Mortgage */
#define ICMOAGENCY_DLJ         61  /* DLJ */
#define ICMOAGENCY_BMS         62  /* BankAmerica Mortgage */
#define ICMOAGENCY_SPSA        63  /* Southern Pacific */
#define ICMOAGENCY_FHLWL       64  /* FHLMC WL */
#define ICMOAGENCY_PHH         65  /* PHH / Cendant */
#define ICMOAGENCY_IMPC        66  /* IMPAC from Bankers Trust*/
#define ICMOAGENCY_SAST        67  /* Saxon Asset Securities */
#define ICMOAGENCY_CBS         68  /* CBASS / Litton Servicing */
#define ICMOAGENCY_GSM         69  /* Goldman Sachs */
#define ICMOAGENCY_MEGO        70  /* MEGO Mortgage */
#define ICMOAGENCY_NCC         71  /* New Century */
#define ICMOAGENCY_KSTN        72  /* Keystone */
#define ICMOAGENCY_MAF         73  /* Metropolitan Asset Funding */
#define ICMOAGENCY_IMHE        74  /* Impac from impac */
#define ICMOAGENCY_SASC        75  /* SASC from Aurora Servicing */
#define ICMOAGENCY_FSC         76  /* First Security Corp */
#define ICMOAGENCY_FNMWL       77  /* FNMA WL */
#define ICMOAGENCY_RFHE        78  /* Residential Funding Home Equity */
#define ICMOAGENCY_NFHE        79  /* Novastar Home Equity */
#define ICMOAGENCY_WMM         80  /* Washington Mutual Mortgage */
#define ICMOAGENCY_BOA         81  /* Bank of America */
#define ICMOAGENCY_CMFT        82  /* Chase Trusteed Deals */
#define ICMOAGENCY_WF          83  /* Wells Fargo */
#define ICMOAGENCY_CWHE        84  /* Countrywide Home Equity */
#define ICMOAGENCY_EMC         85  /* EMC Mortgage */
#define ICMOAGENCY_ACLC        86  /* Amresco Franchise */
#define ICMOAGENCY_IRHE        87  /* Irwin Home Equity */
#define ICMOAGENCY_FNT         88  /* FNT */
#define ICMOAGENCY_FLRT        89  /* FMAC Loan Receivables Trust */
#define ICMOAGENCY_LL          90  /* Generic Loan Level/Misc. Source */
#define ICMOAGENCY_CDS         91  /* Derivative Asset: Credit Default Swap */
#define ICMOAGENCY_CPS         92  /* Derivative Asset: Coupon Swap */
#define ICMOAGENCY_TRS         93  /* Derivative Asset: total return swap */
#define ICMOAGENCY_FNEY        94  /* FNMA Excess Yield Strips */
#define ICMOAGENCY_FHEY        95  /* FHLMC Excess Yield Strips */
#define ICMOAGENCY_FNSPL       96  /* FNMA Excess Yield Strip collateral as available from FNMA 'Super Loan' files */
#define ICMOAGENCY_FNMADUS     97  /* FNMA Loan backing a DUS Pool */
#define ICMOAGENCY_GNMA_CP     98  /* GNMA Construction Project Pool */
#define ICMOAGENCY_MAX         ICMOAGENCY_GNMA_CP

#ifdef DEFINE_AGENCY_NAME_MBS
          char *icmoagency_name_mbs []  = {
   "GNMA", "FNMA", "FHLMC", "UST", "CASH", "USER", "SBA", "GNM2",
   "FHLMG", "BDC", "WL", "RFC", "RYL", "RYF", "ADV", "CWF", "CWC",
   "INM", "CMF", "CAP", "CMC", "GEC", "SMS", "NASC", "PNC", "CMS",
   "SASI", "GTMH", "ABS", "RTC", "BT", "PHM", "FNMF", "CHEM", "TMS",
   "ASW", "NMB", "CMHE", "FNWL", "VMT", "MOR", "MSC", "PHPL", "FNMR",
   "BSM", "IMCH", "GCA", "ADHE", "FUR", "LAS", "FASI", "PBHE", "AFC",
   "FBM", "EQHE", "GTHE", "FMAC", "AMRS", "GEHE", "CHHE", "HDMS",
   "DLJ", "BMS", "SPSA", "FHLWL", "PHH", "IMPC", "SAST", "CBS",
   "GSM", "MEGO", "NCC", "KSTN", "MAF", "IMHE", "SASC", "FSC",
   "FNMWL", "RFHE", "NFHE", "WMM", "BOA", "CMFT", "WF", "CWHE",
   "EMC", "ACLC", "IRHE", "FNT", "FLRT", "LL",
   "CDS", "CPS", "TRS", "FNEY", "FHEY", "FNSPL", "FNMADUS", "GNMA_CP", NULL } ;
#else
  extern  char *icmoagency_name_mbs  [] ;
#endif

/* ICMOCFTYPE_xx: Type of pool for MBS                         */

#define ICMOCFTYPE_UNDEFINED      0
#define ICMOCFTYPE_FIX_10YR       1
#define ICMOCFTYPE_FIX_15YR       2
#define ICMOCFTYPE_FIX_20YR       3
#define ICMOCFTYPE_FIX_25YR       4
#define ICMOCFTYPE_FIX_30YR       5
#define ICMOCFTYPE_FIX_35YR       6
#define ICMOCFTYPE_FIX_40YR       7
#define ICMOCFTYPE_BLN_5YR        8
#define ICMOCFTYPE_BLN_7YR        9
#define ICMOCFTYPE_ARM_LIBOR_1MO 10
#define ICMOCFTYPE_ARM_LIBOR_3MO 11
#define ICMOCFTYPE_ARM_LIBOR_6MO 12
#define ICMOCFTYPE_ARM_LIBOR_1YR 13
#define ICMOCFTYPE_ARM_CMT_3MO   14
#define ICMOCFTYPE_ARM_CMT_6MO   15
#define ICMOCFTYPE_ARM_CMT_1YR   16
#define ICMOCFTYPE_ARM_CMT_2YR   17
#define ICMOCFTYPE_ARM_CMT_3YR   18
#define ICMOCFTYPE_ARM_CMT_5YR   19
#define ICMOCFTYPE_ARM_CMT_7YR   20
#define ICMOCFTYPE_ARM_CMT_10YR  21
#define ICMOCFTYPE_ARM_CMT_30YR  22
#define ICMOCFTYPE_ARM_COFI_11   23
#define ICMOCFTYPE_ARM_PRIME     24
#define ICMOCFTYPE_ARM_CONTRACT  25
#define ICMOCFTYPE_ARM_YEN       26
#define ICMOCFTYPE_ARM_MISC_1    27
#define ICMOCFTYPE_ARM_MISC_2    28
#define ICMOCFTYPE_ARM_MISC_3    29
#define ICMOCFTYPE_GPM           30
#define ICMOCFTYPE_TPM           31
#define ICMOCFTYPE_REMIC         32
#define ICMOCFTYPE_TREAS_BOND    33
#define ICMOCFTYPE_STEPUP        34
#define ICMOCFTYPE_MASTERTRUST   35
#define ICMOCFTYPE_ARM_COF       36
#define ICMOCFTYPE_ARM_6MO_CD    37
#define ICMOCFTYPE_ARM_MONEY_MKT 38
#define ICMOCFTYPE_BLN_10YR      39
#define ICMOCFTYPE_BLN_15YR      40
#define ICMOCFTYPE_BLN_OTHER     41
#define ICMOCFTYPE_CASH          42
#define ICMOCFTYPE_ARM_LIBOR_2YR_SWAP   43
#define ICMOCFTYPE_ARM_LIBOR_10YR_SWAP  44
#define ICMOCFTYPE_ARM_UNDEFINED 45
#define ICMOCFTYPE_SWAP          46
#define ICMOCFTYPE_ARM_MTA_1YR   47
#define ICMOCFTYPE_STUDENT_LOAN  48
#define ICMOCFTYPE_MAX      ICMOCFTYPE_STUDENT_LOAN

#ifdef DEFINE_AGENCY_NAME_MBS
          char *icmocftype_name_list []  = {
   "UNDEFINED",
   "FIX_10YR",
   "FIX_15YR",
   "FIX_20YR",
   "FIX_25YR",
   "FIX_30YR",
   "FIX_35YR",
   "FIX_40YR",
   "BLN_5YR",
   "BLN_7YR",
   "ARM_LIBOR_1MO",
   "ARM_LIBOR_3MO",
   "ARM_LIBOR_6MO",
   "ARM_LIBOR_1YR",
   "ARM_CMT_3MO",
   "ARM_CMT_6MO",
   "ARM_CMT_1YR",
   "ARM_CMT_2YR",
   "ARM_CMT_3YR",
   "ARM_CMT_5YR",
   "ARM_CMT_7YR",
   "ARM_CMT_10YR",
   "ARM_CMT_30YR",
   "ARM_COFI_11",
   "ARM_PRIME",
   "ARM_CONTRACT",
   "ARM_YEN",
   "ARM_MISC_1",
   "ARM_MISC_2",
   "ARM_MISC_3",
   "GPM",
   "TPM",
   "REMIC",
   "TREAS_BOND",
   "STEPUP",
   "MASTERTRUST",
   "ARM_COF",
   "ARM_6MO_CD",
   "ARM_MONEY_MKT",
   "BLN_10YR",
   "BLN_15YR",
   "BLN_OTHER",
   "CASH",
   "ARM_LIBOR_2YR_SWAP",
   "ARM_LIBOR_10YR_SWAP",
   "ARM_UNDEFINED",
   "SWAP",
   "ARM_MTA_1YR",
   "STUDENT_LOAN",
   NULL } ;
#else
  extern  char *icmocftype_name_list [] ;
#endif

/* 3rd-party prepayment function controls */
#define ICMO_CASHFLOWS_PPMDL_BASE_CASE_SCENARIO  (-99) /* icmo_ith_scenario setting to calc prepay model's spread-to-curve */

#define ICMO_STAT_SCENARIO_BASE  10000
#define SET_ICMO_ITH_SCENARIO(xicmop,scen) ((xicmop->icmo_up_icmop==NULL)?(xicmop->icmo_ith_scenario=scen):(xicmop->icmo_ith_scenario=scen+ICMO_STAT_SCENARIO_BASE))
#define GET_ICMO_ITH_SCENARIO(xicmop)      (xicmop->icmo_ith_scenario >= ICMO_STAT_SCENARIO_BASE ? \
                                            xicmop->icmo_ith_scenario  - ICMO_STAT_SCENARIO_BASE : xicmop->icmo_ith_scenario)

/* ICMOCLEAR_ARM_xx:  ARM collateral floor&caps nullified for option evaluation */

#define ICMOCLEAR_ARM_INTRATE_RESET_CAP   1
#define ICMOCLEAR_ARM_INTRATE_RESET_FLR   2
#define ICMOCLEAR_ARM_INTRATE_LIFE_CAP    4
#define ICMOCLEAR_ARM_INTRATE_LIFE_FLR    8
#define ICMOCLEAR_ARM_PAYMENT_RESET_CAP   16
#define ICMOCLEAR_ARM_MAX_NEGAM           32
#define ICMOCLEAR_ARM_ALL_INTRATE_CAPFLRS                   \
                          ( ICMOCLEAR_ARM_INTRATE_RESET_CAP \
                           +ICMOCLEAR_ARM_INTRATE_RESET_FLR \
                           +ICMOCLEAR_ARM_INTRATE_LIFE_CAP  \
                           +ICMOCLEAR_ARM_INTRATE_LIFE_FLR )
#define ICMOCLEAR_ARM_ALL_PAYMENT_CAPFLRS                   \
                          ( ICMOCLEAR_ARM_PAYMENT_RESET_CAP \
                           +ICMOCLEAR_ARM_MAX_NEGAM        )
#define ICMOCLEAR_ARM_ALL_CAPFLRS                             \
                          ( ICMOCLEAR_ARM_ALL_INTRATE_CAPFLRS \
                           +ICMOCLEAR_ARM_ALL_PAYMENT_CAPFLRS)
#define ICMOCLEAR_ARM_ALL_PARAMS        4096   /* ignore all arm info */


/* ICMOIGNORE_CREDITS_xx:  reserve/FinGuar/LoC control */

#define ICMOIGNORE_CREDITS_NO            0  /* run as modeled */
#define ICMOIGNORE_CREDITS_RESID_BENEFIT 1  /* residual gets not benefit */
#define ICMOIGNORE_CREDITS_ALL           2  /* no extnl credit enhance */
#define ICMOIGNORE_CREDITS_TO_DEAL       3  /* ignore extnl credit enhance paying into deal, but allow receiving from deal */

/* ICMOIGNORE_INDIVIDUAL_CREDIT_xx:   Allow user to ignore specified credits */

#define ICMOIGNORE_INDIVIDUAL_CREDIT_NO      0  /* run as modeled */
#define ICMOIGNORE_INDIVIDUAL_CREDIT_ALL     1  /* no extnl credit enhance */
#define ICMOIGNORE_INDIVIDUAL_CREDIT_TO_DEAL 2  /* ignore extnl credit enhance paying into deal, but allow receiving from deal */
#define ICMOIGNORE_INDIVIDUAL_CREDIT_YES ICMOIGNORE_INDIVIDUAL_CREDIT_ALL /* for backward compatibility */

/* ICMO_OPTR_PURCHASER_xx: trust purchaser at optional redemption  */

#define ICMO_OPTR_PURCHASER_RESIDUAL  0  /* purchase by residual holder */
#define ICMO_OPTR_PURCHASER_AUCTION   1  /* sell on auction */


/* ICMOARM_ROUNDING_METHODS: must be the same as mbs.h */

#define  ICMOARM_ROUND_NONE           0  /* no rounding */
#define  ICMOARM_ROUND_TONEAR8        1  /* round to nearest 1/8 */
#define  ICMOARM_ROUND_3DECIMAL       2  /* round to nearest 1/1000 */
#define  ICMOARM_ROUND_TOHIGH8        3  /* round to high 1/8 */
#define  ICMOARM_ROUND_EXPANDED       4  /* rounding method specified by armi_roundp */

/* ICMO_TRANCHE_xx_OVERRIDE: Special tranche number for overriding tranche info in icmo_stats */
#define ICMO_TRANCHE_CF_OVERRIDE          (-999)  /* To override tranche cashflows in stats */
#define ICMO_TRANCHE_STATSPARAM_OVERRIDE  (-998)  /* To calc stats based only on icmot_statsparam info */
#define ICMO_TRANCHE_OVERRIDE    ICMO_TRANCHE_CF_OVERRIDE
#define ICMO_STATS_REAL_TRNO(trno)  ( trno >= 0 )


/* ICMOCFS_xx:  Tranche cashflow storage type (>=0 for specific trno) */

#define ICMOCFS_NOWHERE      (-1)  /* don't store anywhere, just run */
#define ICMOCFS_MEMSTORE     (-2)  /* store in memory */
#define ICMOCFS_ONLYCOLLAT   (-4)  /* don't run bond cashflows at all */
#define ICMOCFS_ONLYTRANCHES (-5)  /* reuse prior collat cashflows */

#define ICMO_USE_BV_SWITCHABLE_ON  2  /* Allow to call icmo_use_bv() inside
                                      user's prepay function */
#define ICMO_USE_BV_SWITCHABLE_OFF 3  /* Disallow to call icmo_use_bv() inside
                                      user's prepay function */
#define ICMO_FORCE_USE_BV    999   /* Force icmo_use_bv_coll to use bv */
#define FIRST_TRANCHE_NUM  (icmop->icmo_have_residual ?  0 : 1 )

/* ICMOTR_PSEUDO_xx: indicates if tranche is real or pseudo.
   Note: use icmo_stats mode ICMOPY_NONE for RESERVE/LOC/GUARANTY  */

#define ICMOTR_PSEUDO_NO        0 /* tranche is a real bond */
#define ICMOTR_PSEUDO_MISC      1 /* tranche is unspecified pseudo */
#define ICMOTR_PSEUDO_COMPONENT 2 /* tranche is a component of other tranche */
#define ICMOTR_PSEUDO_CLASS     3 /* tranche represents class,eg:SENIOR */
#define ICMOTR_PSEUDO_COLLAT    4 /* tranche represents collateral */
#define ICMOTR_PSEUDO_RESERVE   5 /* tranche is Reserve Fund */
#define ICMOTR_PSEUDO_LOC       6 /* tranche is Letter-of-Credit */
#define ICMOTR_PSEUDO_GUARANTY  7 /* tranche is Financial Guaranty */
#define ICMOTR_PSEUDO_SYMVAR    8 /* tranche is internal symbol CFs */
#define ICMOTR_PSEUDO_EXCHANGE  9 /* tranche is FHL MACR pseudo */
#define ICMOTR_PSEUDO_EXPENSE  10 /* tranche is EXPENSE pseudo */
#define ICMOTR_PSEUDO_IRR      11 /* tranche is IRR pseudo */
#define ICMOTR_PSEUDO_HEDGELEG 12 /* tranche is pseudo for HEDGE leg */
#define ICMOTR_PSEUDO_HEDGENET 13 /* tranche is pseudo for HEDGE (net) */
#define ICMOTR_PSEUDO_XRS      14 /* tranche represents collateral XRS band */
#define ICMOTR_PSEUDO_COMBO    15 /* tranche is a COMBO of other tranches */


/* ICMOTR_NOTIONAL_xx: indicates if tranche interest calculated off
                    real balance or notional balance               */

#define ICMOTR_NOTIONAL_NONE   0   /* Tranche has only real balance */
#define ICMOTR_NOTIONAL_MIX    1   /* .. combines real and ntl balances*/
#define ICMOTR_NOTIONAL_PURE   2   /* .. doesn't have real balance   */


/* ICDUWARN_xx  Warnings if CDU file is ignored or if missing */

#define ICDUWARN_NONE           0  /* all okay */
#define ICDUWARN_CDU_MISSING    1  /* update factors not found */


/* IPF_WAVG_BY_ORIGBAL:  index indicating how wavg pool factor is calculate */

#define ICMO_PF_WAVG_BY_UNDERLYING_POOLS   1  /* For remics,re-remics, WAVG pool fact. calc. by origbal of underlying collateral */
#define ICMO_PF_WAVG_BY_CURBAL             2  /* Same as above but wavg'ed by pool current balance.
                                                 or output the end factor after call ICMO_PREPAY_SPEED */
#define ICMO_PREP_END_FACTOR ICMO_PF_WAVG_BY_CURBAL  /* Only used in ICMO_PREPAY_SPEED to output the end factor */

/* ISCHED_xx:  return val for icmo_schedule_met() */

#define ISCHED_NO_SCHEDULE      0  /* tranche doesnt depend on schedule */
#define ISCHED_UNMET_SCHEDULE   1  /* couldn't hold to tranche schedule */
#define ISCHED_MET_SCHEDULE     2  /* held to tranche schedule */

#define SCHED_COLLAT_BALANCE       9100  /* sched is collat balances */
#define SCHED_COLLAT_FACTOR        9101  /* sched is collat factors */
#define SCHED_COLLAT_REDUCE_FACTOR 9102  /* sched is collat %princ */
#define SCHED_COLLAT_PRINCIPAL     9103  /* sched is collat princ */
#define SCHED_TR_BALANCE           9150  /* sched is tranche balances */
#define SCHED_TR_FACTOR            9151  /* sched is tranche factors */
#define SCHED_TR_AMORT             9152  /* sched is tranche principal */
#define SCHED_SHIFTINT             9160  /* sched is shiftint schedule */
#define SCHED_SHIFTR               9161  /* sched is shiftR   schedule */

#define ICMO_FORWARD_RESET_TO_0   (-99)   /* "n_months_forwards" reset */
#define ICMO_FMTDATE_BOND_SETTLE   (-1)   /* "mth_payment" tranche settle */


/* COLLARS_xx:  method of calculations in ICMO_DEAL_EFFECTIVE_COLLARS */

#define COLLARS_BY_FLAT_WAL  0  /* calc collars using flat WAL method */
#define COLLARS_USING_PRECALC   1  /* use precalculated collars from CDU file */


/* ICMO_ERROR_xx:  error checking level */

#define ICMO_ERROR_FATAL        0  /* fatal error */
#define ICMO_ERROR_SERIOUS      1  /* serious error, but still can continue */
#define ICMO_ERROR_SCRIPT       8  /* script syntax error */
#define ICMO_ERROR_MODERATE    10  /* maybe problem, but many false alarm */
#define ICMO_ERROR_EXTENDED    12  /* not affecting CF, but not in INTEX modeling style */
#define ICMO_ERROR_LIGHT       20  /* most likely ok */
#define ICMO_ERROR_EXPRNOISE   50  /* not an error, used to see computer noise on expr */

/* ICMOPARSERR_xx:  information about a CDI/CDU parsing error */

#define ICMOPARSERR_NONE         0  /* parsing found no errors */
#define ICMOPARSERR_NO_CDI       1  /* error due to no CDI file */
#define ICMOPARSERR_IN_CDI       2  /* error in CDI file */
#define ICMOPARSERR_IN_CDU       3  /* error in CDU file */
#define ICMOPARSERR_IN_IDX       4  /* error in IDX file */
#define ICMOPARSERR_IN_ICMOMISC  5  /* error in icmomisc interface */

/* ICMOPARSER_xx:      Ret codes from icmo_parser_open */

#define ICMOPARSER_FILE_LIMIT_EXCEEDED (-1) /* Too many open parsing files*/
#define ICMOPARSER_FILE_NOT_FOUND      (-2) /* Input file not found */

#define ICMO_PARSER_RDREC       ( *(int *) icmo_parser( icmop, ICMO_PARSER_PFILE, ICMO_PARSER_TKNPP, "NEXT" ) )
#define ICMO_PARSER_NAME        ( (char *) icmo_parser( icmop, ICMO_PARSER_PFILE, ICMO_PARSER_TKNPP, "NAME" ) )
#define ICMO_PARSER_CHECK(str)  ( *(int *) icmo_parser( icmop, ICMO_PARSER_PFILE, ICMO_PARSER_TKNPP, str ) )
#define ICMO_PARSER_MAYBE(str)  ( *(int *) icmo_parser( icmop, ICMO_PARSER_PFILE, ICMO_PARSER_TKNPP, str ) )
#define ICMO_PARSER_EXACT(str)  (          icmo_parser( icmop, ICMO_PARSER_PFILE, ICMO_PARSER_TKNPP, str ) )
#define ICMO_PARSER_INT         ( *(int *) icmo_parser( icmop, ICMO_PARSER_PFILE, ICMO_PARSER_TKNPP, "INT" ) )
#define ICMO_PARSER_DBL         ( *(double *) icmo_parser( icmop, ICMO_PARSER_PFILE, ICMO_PARSER_TKNPP, "DBL" ) )
#define ICMO_PARSER_EOR         ( *(int *) icmo_parser( icmop, ICMO_PARSER_PFILE, ICMO_PARSER_TKNPP, "EOR" ) )
#define ICMO_PARSER_STR         ( (char *) icmo_parser( icmop, ICMO_PARSER_PFILE, ICMO_PARSER_TKNPP, "STRING" ) )
#define ICMO_PARSER_CASESTR     ( (char *) icmo_parser( icmop, ICMO_PARSER_PFILE, ICMO_PARSER_TKNPP, "CASESTR" ) )
#define ICMO_PARSER_DATE        ( *(YyyyMmDd *) icmo_parser( icmop, ICMO_PARSER_PFILE, ICMO_PARSER_TKNPP, "DATE" ) )
#define ICMO_PARSER_GROUP       ( *(int *) icmo_parser( icmop, ICMO_PARSER_PFILE, ICMO_PARSER_TKNPP, "GROUP" ) )

#ifdef ICMO_NO_ANSI_PROTOTYPING
#define Args_expr_sym_handler
#define Args_expr_func_handler
#else
#define Args_expr_sym_handler    char *,int,int
#define Args_expr_func_handler   char *,int,double *,int
#endif

#define ICMOPARSER_EXPR_PARSKEY_LEN 10
typedef struct {
    char expr_parskey [ICMOPARSER_EXPR_PARSKEY_LEN] ;
    char *expr_toptkn ;
    char **expr_symlist ;
    char **expr_funclist ;
    double ((*expr_sym_handler)(Args_expr_sym_handler)) ;
    double ((*expr_func_handler)(Args_expr_func_handler)) ;
    } ICMOPARSER_EXPR_STRUC ;


/* ICMOIDX_xx:  return (double) val for icmo_get_idx_val() if < 0 */

#define ICMOIDX_NOT_REF    (-1001) /* index not referenced in deal */
#define ICMOIDX_NOT_SET    (-1002) /* index not in IDX file (like MISC) or
                                   IDX file not read (e.g.DEAL_NEW mode)*/
#define ICMOIDX_SUBNAME_NOT_REF (-1003) /*exact subname required but not
                                                     referenced in deal */
#define ICMOIDX_NO_SUBNAME (-1004) /*exact subname req. but not in IDX */
#define ICMOIDX_EARLY_DATE (-1005) /*req.date earlier than IDX start   */
#define ICMOIDX_LATE_DATE  (-1006) /*req.date later   than IDX finish  */
#define ICMOIDX_BAD_VAL    (-1007) /*not filled data in IDX file       */
#define ICMOIDX_FLAGVAL(x) ((x)<(-1000)) /* idxval is one of the flag defined above */


/* ICMODBSTAT_xx:      Ret codes from icmo_dbstatus / icmo_dbstat_check  */

#define ICMODBSTAT_OK            0     /* Run OK */
#define ICMODBSTAT_NO_QA        (-1)   /* no QA file in CDU dir*/
#define ICMODBSTAT_NO_INPDIR    (-2)   /* no access to CDI/CDU dirs */
#define ICMODBSTAT_NO_OUTDIR    (-3)   /* no access to report output dir */
#define ICMODBSTAT_BAD_QA_FILE  (-4)   /* error in QA file */

/* ICMODBSTAT:  Parameters to run icmo_dbstat_check() */

typedef struct _ICMODBSTAT {
    char  *dbs_cdi_path   ;   /* Path to CDI directory  */
    char  *dbs_cdu_path   ;   /* Path to CDU directory  */
    char  *dbs_qa_path    ;   /* Path to QA file. Default: same as CDU directory */
    char  *dbs_qa_fn      ;   /* Name of QA file. Default: "cmostat.qa"   */
    char  *dbs_sub_ver_fn ;   /* Name of subroutines ver file. Default: "icmosubs.inf"  */
    char  *dbs_report_path;   /* Path to report output directory. Default: current directory*/
    char  *dbs_report_fn  ;   /* Name of report file. Default: "dbstatus.rpt */
    int   dbs_check_size ;   /* TRUE - check file size. Default: TRUE    */
    int   dbs_check_time ;    /* check file's date/time stamp */
#define ICMODBSCHECK_TIME_YES     0  /* check date/time only if file on DB has earlier date/time, that it should be */
#define ICMODBSCHECK_TIME_EXACT   1  /* Default: check exact time match */
#define ICMODBSCHECK_TIME_NO      2  /* Not checking date/time  */
    int   dbs_check_signature ; /* check file's signature code  */
#define ICMODBSCHECK_SIGN_NO      0  /* Not checking signature */
#define ICMODBSCHECK_SIGN_YES     1  /* Default: check signature only for files with signature check suggested in QA file. */
#define ICMODBSCHECK_SIGN_ALL     2  /* check signature for all files on DB (slow) */
    int   dbs_check_n_months_back; /* For cdu files - how many months back check. Default: 1 */
    int   dbs_check_ver  ;   /* TRUE - check CMO subroutines version. Default: TRUE  */
    int   dbs_keep_case ;    /* TRUE - keep case of directory paths. Default: FALSE */
    int   dbs_check_flash ;  /* TRUE - Check agency flash files if presented in QA file. Default: TRUE */
    int   dbs_can_print ;    /* TRUE - printf protocol to the screen. Default: TRUE  */
    int   dbs_check_remove ; /* TRUE - Check files marked in QA file for deleting from DB. Default: TRUE */
    int   dbs_remove_count ; /* Output: # of errors found as a result of dbs_check_remove flag*/
    int   dbs_err_count ;    /* Output: # of errors found */
} ICMODBSTAT ;

#define ICMODBSTAT_INIT_TYPICAL 0  /* set typical defaults */

/* ICMODBSTAT_CHK_xx:   Bit flags for use in third parameter of the OLD routine icmo_dbstatus */

#define ICMODBSTAT_CHK_NOSIZE        0  /* do not check the size, only the date */
#define ICMODBSTAT_CHK_SIZE          1  /* check size, date and CMO subs version*/
#define ICMODBSTAT_CHK_SIZE_NOVER    2  /* check size but not subs version */
#define ICMODBSTAT_CHK_KEEP_CASE     4  /* maintain case of directory paths */


/* ICMO_RCL_xx:  "internal" flags used in icmo_replace_collat_list() */

#define ICMO_RCL_SKIP_RESET_TO_PARSING_STATUS 0x01  INTEX_INTERNAL_USE_ONLY /* Skip resetting to parsing status */
#define ICMO_RCL_SKIP_RECALC_INFO_ONLY_VALS   0x02  INTEX_INTERNAL_USE_ONLY /* Skip re-calculating values that do not affect the cashflows (e.g., group wavg pips) */


/* ICMOAPPLY_TRANSACT_xx:  Processing mode for icmo_apply_collat_transact_set() */

#define ICMOAPPLY_TRANSACT_NEW     0  /* Process new transaction set  */
#define ICMOAPPLY_TRANSACT_UNDO    1  /* Undo all transaction sets starting from given sequence number */

/* ICMOAPPLY_TRANSACT_RETVAL_xx:  return values from icmo_apply_collat_transact_set() */

#define ICMOAPPLY_TRANSACT_RETVAL_OK      0   /* icmo_apply_collat_transact_set() finished normally */
#define ICMOAPPLY_TRANSACT_RETVAL_NO_CDX  1   /* unable to open CDX file */
#define ICMOAPPLY_TRANSACT_RETVAL_ERROR   2   /* Error when processing transact set */


/* ICMOMS_xx:  mode for icmo_make_struct() and icmo_free_struct() */

#define ICMOMS_ICMOMISC             0  /* make/free ICMOMISC  structure */
#define ICMOMS_POOL_INFO            1  /* make/free POOL_INFO structure */
#define ICMOMS_POOL_INFO_CURPER_TBA 2  /* make/free POOL_INFO within CF run callback function */
#define ICMOMS_POOL_INFO_CURPER_TBA_FROM_PIP 3  /* make/free POOL_INFO within CF run callback function using original pip from reinv collateral */
#define ICMOMS_RBC_INFO             4  /* make/free RBC_INFO structure */
#define ICMOMS_LOANATTR             5  /* make/free LOANATTR structure */
#define ICMOMS_PORTFMISC            6  /* make/free PORTFMISC structure */
#define ICMOMS_ICMO_SCRIPT          7  /* make/free ICMO_SCRIPT structure */
#define ICMOMS_LOANDATA             8  /* make/free LOANDATA structure */
#define ICMOMS_COLLARS_CONTROL      9  /* make/free ICMO_COLLARS_CONTROL structure */
#define ICMOMS_PISERV_INFO         10  /* make/free PISERV_INFO structure */
#define ICMOMS_CROSS_DEALS_CACHE   11  /* make/free ICMOMISC_CROSS_DEALS_CACHE structure */
#define ICMOMS_CFASSUM_RATEMOD     12  /* make/free CFASSUM_RATEMOD structure */
#define ICMOMS_DEALTREE_PARTITION  13  /* make/free ICMO_DEALTREE_PARTITION structure */
#define ICMOMS_ICMODBMISC          14  /* make/free ICMODBMISC structure */
#define ICMOMS_HORIZON_RETURN_CONTROL 15  /* make/free ICMO_HORIZON_RETURN_CONTROL structure */

/* ICMOFS_RETVAL_xx:  return values from  icmo_free_struct() */

#define ICMOFS_RETVAL_OK                0  /* icmo_free_struct() finished normally*/
#define ICMOFS_RETVAL_INCORRECT_PARAM   1  /* did not free: incorrect parameter passed */
#define ICMOFS_RETVAL_INVALID_USE       2  /* did not free: structure was not allocated by icmo_make_struct() */


/* ICMO_ISR_PLAY_RETVAL_xx: - return values from icmo_isr_play() */

#define ICMO_ISR_PLAY_RETVAL_OK            0   /* icmo_isr_play() finished normally */
#define ICMO_ISR_PLAY_RETVAL_STOPPED       1   /* was stopped by isr_play_control_fcn() */
#define ICMO_ISR_PLAY_RETVAL_FATAL         2   /* Fatal error - was unable to continue */
#define ICMO_ISR_PLAY_RETVAL_NO_CALLBACK   3   /* no isr_play_control_fcn() provided */


/* ICMOISR: structure passed to isr_play_control_fcn() - callback function for icmo_isr_play()*/

typedef struct _ICMOISR {
        int  isr_event     ;      /* ISR_EVENT_xx - play event  initialized callback     */
        int  isr_step      ;      /* ISR_STEP_xx - current step (function) playing      */
        ICMO  *isr_icmop    ;      /* NULL or current ICMO structure pointer     */
        ICMOMISC *isr_icmomiscp ; /* NULL or current ICMOMISC structure pointer     */
        char *isr_fn       ;      /* Name of ISR file .  */
        int  isr_error_level;     /*  ICMO_ERROR_xx - error level if called for ISR_EVENT_ERROR */
        char *isr_errmsg   ;      /*  error message if called for ISR_EVENT_ERROR */
        char *isr_userp  ;        /*  optional user structure could be attached here */
} ICMOISR ;

/* ISR_EVENT_xx: - event when calling isr_play_control_fcn() - callback function for icmo_isr_play()  */

#define ISR_EVENT_BEGIN      0    /* first callback at the beginning of icmo_isr_play() */
#define ISR_EVENT_STEP_BEGIN 1    /* normal callback at the beginning of next step during playing ISR file */
#define ISR_EVENT_STEP_END   2    /* normal callback after the end of next step during playing ISR file */
#define ISR_EVENT_ERROR      3    /* callback in case of error during playing ISR file */
#define ISR_EVENT_END        4    /* last callback at the end of icmo_isr_play() */

/* ISR_STEP_xx: - step when calling isr_play_control_fcn() - callback function for icmo_isr_play() */

#define ISR_STEP_INIT_PLAY                0   /* initialisation of icmo_isr_play() only for  ISR_EVENT_ERROR */
#define ISR_STEP_ICMO_DEAL                1   /* before/after call icmo_deal()            */
#define ISR_STEP_ICMO_CASHFLOWS           2   /*                   icmo_cashflows()       */
#define ISR_STEP_ICMO_STATS               3   /*                   icmo_stats()           */
#define ISR_STEP_ICMO_SET_INDEX_FORECAST  4   /*                   icmo_set_index_forecast()       */
#define ISR_STEP_ICMO_SET_PMT_TO_PMT_MODE 5   /*                   icmo_set_pmt_to_pmt_mode()   */
#define ISR_STEP_ICMO_CLUSTER_POOLS       6   /*                   icmo_cluster_pools()   */
#define ISR_STEP_ICMO_DECLUSTER_POOLS     7   /*                   icmo_decluster_pools() */
#define ISR_STEP_ICMO_TRANCHENUM          8   /*                   icmo_tranchenum()      */
#define ISR_STEP_ICMO_FORWARD_SETTLE_DATE 9   /*                   icmo_forward_settle_date()   */
#define ISR_STEP_ICMO_USE_BV_COLL        10   /*                   icmo_use_bv_coll()   */
#define ISR_STEP_ICMO_APPLY_COLLAT_TRANSACT_SET 11  /*           icmo_apply_collat_transact_set()  */
#define ISR_STEP_ICMO_FREE               12   /*                   icmo_free()            */
#define ISR_STEP_MAX         ISR_STEP_ICMO_FREE

#define ISR_ICMO_CALLBACK_INDEX_FCN  ISR_STEP_MAX+1
#define ISR_ICMO_CALLBACK_MAX        ISR_ICMO_CALLBACK_INDEX_FCN

#ifdef DEFINE_ICMO_ISR_STEPS_NAMELIST
char *icmo_isr_steps_namelist[] = { "dummy",
    "icmo_deal",  "icmo_cashflows", "icmo_stats", "icmo_set_index_forecast", "icmo_set_pmt_to_pmt_mode",
    "icmo_cluster_pools", "icmo_decluster_pools", "icmo_tranchenum", "icmo_forward_settle_date", "icmo_use_bv_coll",
    "icmo_apply_collat_transact_set", "icmo_free",
    "icmo_callback_index_fcn",
     NULL } ;
#else
extern char *icmo_isr_steps_namelist[];
#endif

/* ISR_PLAY_CONTROL_RETVAL_xx: - return values from callback function: isr_play_control_fcn() */

#define ISR_PLAY_CONTROL_RETVAL_CONTINUE 0   /* isr_play_control_fcn() finished normally continue running icmo_isr_play() */
#define ISR_PLAY_CONTROL_RETVAL_STOP     1   /* isr_play_control_fcn() request for stop running icmo_isr_play() */

/* ICMO_BD_HOL_xx: - only the negative values are returned from icmoutil_YyyyMmDd_bd_adj() */

#define ICMO_BDHOL_OK                 0  /* run OK based on given holiday file */
#define ICMO_BDHOL_NO_FILE           -1  /* Error: holiday file not found or unable to open */
#define ICMO_BDHOL_BAD_FILE          -2  /* Error: incorrect holiday file */
#define ICMO_BDHOL_INVALID_DATE      -3  /* Error: invalid input date */
#define ICMO_BDHOL_INVALID_BD_METHOD -4  /* Error: business method passed is not supported, e.g. ICMO_BUSINESSDAY_COMBINATION */

/* ICMOPI_ADVANCE_xx:  Loss model's "servicer advances P&I" flag.
                        Normal standard is _EXCLUDE_ case */

#define ICMOPI_ADVANCE_NONE               0  /* no servicer advancing */
#define ICMOPI_ADVANCE_EXCLUDE_LIQ_MONTH  1  /* yes, losses after prepayments */
#define ICMOPI_ADVANCE_INCLUDE_LIQ_MONTH  2  /* yes, losses before prepayments */
#define ICMOPI_ADVANCE_DELINQ_ONLY        3  /* advance applied to delinq payment only, not default payment */
#define ICMOPI_ADVANCE_RESERVED_4         4  /* reserved for future use */
#define ICMOPI_ADVANCE_RESERVED_5         5  /* reserved for future use */
#define ICMOPI_ADVANCE_RESERVED_6         6  /* reserved for future use */
#define ICMOPI_ADVANCE_DEFAULT_INCLUDED_IN_DELINQ 7 /* advance is controled by delinq */
#define ICMOPI_ADVANCE_DEFAULT_INCLUDED_IN_DELINQ_ELM 8 /* similar to ICMOPI_ADVANCE_DEFAULT_INCLUDED_IN_DELINQ, except using EXCLUDE_LIQ_MONTH */
#define ICMOPI_ADVANCE_FULL_SERVFEE      64  /* modifier: full servfee collected on defaulted balance */


/* ICMOSTEP_xx:  ensures application calls subs in proper sequence */

#define ICMOSTEP_PARSE                     1
#define ICMOSTEP_SCENARIO                  2
#define ICMOSTEP_SCENARIO_COLLAT           3
#define ICMOSTEP_CASHFLOWS_DONE            4
#define ICMOSTEP_STATS                     5
#define ICMOSTEP_EVAL_SCRIPT               6  /* this step can occur before or after cashflows */


/* ICMOPREPHIST_xx:  prepayment history calculations method */

#define  ICMOPREPHIST_INDIVIDUAL_WAVG 0  /* weight avg of individ pools */
#define  ICMOPREPHIST_ENTIRE_COLLAT   1  /* iterated over entire collat */


/* ICMO_DATE_CONVERT_xx:  cases for icmo_date_convert() utility */

#define ICMODATE_NEXT_DEALPAYDATE            0  /* date <- date */
#define ICMODATE_DEALPAYDATE_TO_CDUDATE      1  /* date <- date */
#define ICMODATE_CDUDATE_TO_DEALPAYDATE      2  /* date <- date */
#define ICMODATE_COLLPAYDATE_TO_CDUDATE      3  /* date <- date */
#define ICMODATE_CDUDATE_TO_COLLPAYDATE      4  /* date <- date */
#define ICMODATE_DEALPAYDATE_TO_CURPER       5  /* int  <- date */
#define ICMODATE_CURPER_TO_DEALPAYDATE       6  /* date <- int  */
#define ICMODATE_CDUDATE_TO_CURPER           7  /* int  <- date */
#define ICMODATE_PAYDATE_TO_ACCRUDATE        8  /* date <- date */
#define ICMODATE_DEALPAYDATE_PARENT_TO_CHILD 9  /* date <- date */
#define ICMODATE_LOAN_REMTERM_TO_MATURDATE       10  /* date <- int  */
#define ICMODATE_LOAN_MATURDATE_TO_REMTERM       11  /* int  <- date */
#define ICMODATE_LOAN_AGE_TO_ISSUEDATE           12  /* date <- int  (for WALA) */
#define ICMODATE_LOAN_ISSUEDATE_TO_AGE           13  /* int  <- date (for WALA) */
#define ICMODATE_LOAN_ORIGTERM_TO_ORIGMATUR_DATE 14  /* date <- int  */
#define ICMODATE_LOAN_ORIGMATUR_DATE_TO_ORIGTERM 15  /* int  <- date */
#define ICMODATE_LOAN_SINCE_ISSUE_TERM_TO_DATE   16  /* date <- int  (for LOCKOUT, BALLOON, STEPUP, DRAW)*/
#define ICMODATE_LOAN_SINCE_ISSUE_DATE_TO_TERM   17  /* int  <- date (for LOCKOUT, BALLOON, STEPUP, DRAW)*/
#define ICMODATE_LOAN_PREFUND_TERM_TO_DATE       18  /* date <- int  */
#define ICMODATE_LOAN_PREFUND_DATE_TO_TERM       19  /* int  <- date */
#define ICMODATE_LOAN_PAYRESET_TERM_TO_DATE      20  /* date <- int  */
#define ICMODATE_LOAN_PAYRESET_DATE_TO_TERM      21  /* int  <- date */
#define ICMODATE_LOAN_INTRESET_TERM_TO_DATE      22  /* date <- int  */
#define ICMODATE_LOAN_INTRESET_DATE_TO_TERM      23  /* int  <- date */
#define ICMODATE_TO_VALID_DATE                   24  /* date <- date */
#define ICMODATE_LOANPAYDATE_TO_CDUDATE          25  /* date <- date */
#define ICMODATE_CDUDATE_TO_LOANPAYDATE          26  /* date <- date */
#define ICMODATE_TRPER_TO_TRPAYDATE              27  /* date <- int  */
#define ICMODATE_TRPAYDATE_TO_TRPER              28  /* int  <- date */
#define ICMODATE_DEALPAYDATE_TO_DETERMDATE       29  /* date <- date */
#define ICMODATE_COLLPAYDATE_TO_DETERMDATE       30  /* date <- date */
#define ICMODATE_CDUDATE_TO_BD_ADJ_LOANPAYDATE   31  /* date <- date */

#define ICMODATE_TRANCHE_SETTLE  -99999999 /* input flag to get tranche settle date from ICMODATE_TRPER_TO_TRPAYDATE */


/* PIWORK_xx: For use by opinfo_govern_loancf_fcn() */
#define ICMOSPDT_CONSTANT             (-1)      /* constant SMM, etc */
#define PIWORK_PRP_RATE_CONV_FROM_VAL (-999999) /* piwork_prp_rate flag settable by opinfo_govern fcn to trigger
                                                 conversion of piwork_prp_value to piwork_prp_rate */
#define ICMODEFAULT_CONST          94  /* user opinfo_govern fcn sets piwork_def_type permanently
                                          OR commits to setting in each future period for this loan */
#define PIWORK_SEVERITY_CONST       1   /* user opinfo_govern fcn sets piwork_severity_type */
#define PIWORK_DEF_RATE_CONV_FROM_VAL (-999999) /* piwork_def_rate flag settable by opinfo_govern fcn to trigger
                                                 conversion of piwork_def_value to piwork_def_rate */

/* ICMODBREC:  parsed record of Database Search.  All fields read-only.*/

#define MAX_DEALNAME_SIZE ICMO_MAX_TRNAM_CHARS /* max# chars of deal name in CMODBINF */
#define MAX_TRNAME_SIZE   ICMO_MAX_TRNAM_CHARS /* max# chars of tranche name in CMODBINF */
#define MAX_DATAHIST_TRNAME_SIZE   40          /* max# chars of tranche name in DATAHIST */
#define MAX_ITEMNAME_SIZE 30    /* max# chars of itemname in dataHIST inf file */
#define MAX_CUSIP_SIZE     9    /* max# chars of cusip in CMODBINF */
#define MAX_ISIN_SIZE     12    /* max# chars of ISIN */
#define MAX_TRTYPE_SIZE   16    /* max# chars of tranche type in CMODBINF */

typedef struct {
    char *cmodbinf_next ;      /* to next record in linked list */
    char cmodbinf_deal_name[MAX_DEALNAME_SIZE+1]; /* Dealname */
    char cmodbinf_tr_name[MAX_TRNAME_SIZE+1];     /* tranche name */
DEPRECATED  char cmodbinf_tr_cusip[MAX_CUSIP_SIZE+1];
    char cmodbinf_tr_type[MAX_TRTYPE_SIZE+1];     /* Tranche type */
    int  cmodbinf_tr_indexdep ;                   /* Index,ITR_INDXDEP_*/
    int  cmodbinf_collat_type ;                   /* AGENCY_xx */
    double cmodbinf_collat_netrate ;              /* collateral p/t */
    double cmodbinf_collat_wac ;                  /* collateral gross */
    int  cmodbinf_collat_wam ;                    /* collateral remterm*/
    int  cmodbinf_collat_wala ;                   /* collateral age */
    double cmodbinf_collat_recent_psa ;           /* collateral speed */
    double cmodbinf_tr_pricing_wal ;              /* WAL @pricing speed*/
    int cmodbinf_tr_pricing_lockout ;             /* YYMM@pricing speed*/
    int cmodbinf_tr_pricing_matures ;             /* YYMM@pricing speed*/
    double cmodbinf_tr_recent_wal ;               /* WAL @recent speed*/
    int cmodbinf_tr_recent_lockout ;              /* YYMM@recent speed*/
    int cmodbinf_tr_recent_matures ;              /* YYMM@recent speed*/
    double cmodbinf_tr_collar_lo ;                /* lower PAC speed */
    double cmodbinf_tr_collar_hi ;                /* upper PAC speed */
    } ICMODBREC_CMODBINF ;

typedef struct {
    char *datahist_next ;      /* to next record in linked list */
    char datahist_deal_name[MAX_DEALNAME_SIZE+1]; /* Dealname */
    char datahist_trgrp_name[MAX_DATAHIST_TRNAME_SIZE+1];  /* tr or group name */
    char datahist_item_name[MAX_ITEMNAME_SIZE+1]; /* item name */
    long datahist_latest_info_date ;    /* in YYYYMMDD format */
    long datahist_earliest_info_date ;  /* in YYYYMMDD format */
    int  datahist_n_data_value ;     /* size of datahist_v_data_value */
    double *datahist_v_data_value ;  /* vector of historical values */
    } ICMODBREC_DATAHIST ;

typedef union _ICMODBREC {
    ICMODBREC_CMODBINF  icmodbrec_cmodbinf ;
    ICMODBREC_DATAHIST  icmodbrec_datahist ;
    } ICMODBREC ;

#define icmodbrec_next                icmodbrec_cmodbinf.cmodbinf_next
#define icmodbrec_deal_name           icmodbrec_cmodbinf.cmodbinf_deal_name
#define icmodbrec_tr_name             icmodbrec_cmodbinf.cmodbinf_tr_name
#define icmodbrec_tr_cusip            icmodbrec_cmodbinf.cmodbinf_tr_cusip
#define icmodbrec_tr_type             icmodbrec_cmodbinf.cmodbinf_tr_type
#define icmodbrec_tr_indexdep         icmodbrec_cmodbinf.cmodbinf_tr_indexdep
#define icmodbrec_collat_type         icmodbrec_cmodbinf.cmodbinf_collat_type
#define icmodbrec_collat_netrate      icmodbrec_cmodbinf.cmodbinf_collat_netrate
#define icmodbrec_collat_wac          icmodbrec_cmodbinf.cmodbinf_collat_wac
#define icmodbrec_collat_wam          icmodbrec_cmodbinf.cmodbinf_collat_wam
#define icmodbrec_collat_wala         icmodbrec_cmodbinf.cmodbinf_collat_wala
#define icmodbrec_collat_recent_psa   icmodbrec_cmodbinf.cmodbinf_collat_recent_psa
#define icmodbrec_tr_pricing_wal      icmodbrec_cmodbinf.cmodbinf_tr_pricing_wal
#define icmodbrec_tr_pricing_lockout  icmodbrec_cmodbinf.cmodbinf_tr_pricing_lockout
#define icmodbrec_tr_pricing_matures  icmodbrec_cmodbinf.cmodbinf_tr_pricing_matures
#define icmodbrec_tr_recent_wal       icmodbrec_cmodbinf.cmodbinf_tr_recent_wal
#define icmodbrec_tr_recent_lockout   icmodbrec_cmodbinf.cmodbinf_tr_recent_lockout
#define icmodbrec_tr_recent_matures   icmodbrec_cmodbinf.cmodbinf_tr_recent_matures
#define icmodbrec_tr_collar_lo        icmodbrec_cmodbinf.cmodbinf_tr_collar_lo
#define icmodbrec_tr_collar_hi        icmodbrec_cmodbinf.cmodbinf_tr_collar_hi


/* ICMODB:  Database Search control. */

typedef struct _ICMODB {

     /* Information available to your application after icmodb_init(): */

    ICMODBREC *icmodb_recanchor ;     /* link-list of dbrecs in memory */
    char *icmodb_errbuff  ;           /* error msg if error */

    /* Controls that your application can set before icmodb_find() and icmodb_altid_search(): */

    int icmodb_find_incl_paiddown ;   /* TRUE= also screen in 0bal tr's */

/* Information available to your application after icmodb_altid_search(): */
    int icmodb_altid_type ;  /* out: actual altid_type found in last icmodb_altid_search call */

    /* General housekeeping:  For use only by Intex CMO Subroutines... */
INTEX_INTERNAL_USE_ONLY    int icmodb_id ;                   /* flag for safety */
INTEX_INTERNAL_USE_ONLY    char *icmodb_cusip_fn ;           /* filename of CMOCUSIP table */
INTEX_INTERNAL_USE_ONLY    char *icmodb_dbinf_fn ;           /* filename of CMODBINF table */
INTEX_INTERNAL_USE_ONLY    YyyyMmDd icmodb_date ;            /* date of last CMODBINF update */
INTEX_INTERNAL_USE_ONLY    int icmodb_version ;              /* release format of CMODBINF */
INTEX_INTERNAL_USE_ONLY    int icmodb_only_cusip;            /* TRUE if no analytics to be read*/
INTEX_INTERNAL_USE_ONLY    ICMODBREC *icmodb_now_at_dbrecp ; /* when screening thru memory */
INTEX_INTERNAL_USE_ONLY    char *icmodb_toptkn ;             /* to expr tree of search */
INTEX_INTERNAL_USE_ONLY    void *icmodb_cmodbp ;             /* to more internal info */

    /* Following are old fields, not used any more */
DEPRECATED    long icmodb_cusip_mem_size ;      /* .. not used any more */
DEPRECATED    char *icmodb_cusip_mem ;          /* .. not used any more */
DEPRECATED    char **icmodb_cusip_16bit_mem ;   /* .. not used any more */
DEPRECATED    char *icmodb_cmop ;               /* .. not used any more */
DEPRECATED    void *icmodb_cmo_mplp ;           /* .. not used any more */
DEPRECATED    void *icmodb_mbs_mplp ;           /* .. not used any more */
DEPRECATED    void *icmodb_bdc_mplp ;           /* .. not used any more */
    } ICMODB ;


/* ICMODB_INIT_xx:  init_mode parameter value for icmodb_init() */

#define ICMODB_INIT_CUSIP_AND_DBINF  0  /* initialize CUSIP and CMODBINF tables */
#define ICMODB_INIT_CUSIP_ONLY       1  /* initialize only CUSIP tables         */
#define ICMODB_INIT_MUSIP_AND_DBINF  2  /* initialize MUSIP and CMODBINF tables */
#define ICMODB_INIT_MUSIP_ONLY       3  /* initialize only MUSIP tables         */
#define ICMODB_INIT_CMODBID          4  /* initialize alternative ID to Intex deal lookup */
#define ICMODB_INIT_DATAHIST_GENERIC 5  /* init a generic datahist inf file. (use cdu_path for full filename) */
#define ICMODB_INIT_DATAHIST_ABS  (ICMODB_INIT_DATAHIST_GENERIC +  1)
#define ICMODB_INIT_DATAHIST_CMBS (ICMODB_INIT_DATAHIST_GENERIC +  2)
#define ICMODB_INIT_DATAHIST_WL   (ICMODB_INIT_DATAHIST_GENERIC +  3)

#define ICMODB_INIT_USE_ICMODBMISC  999  /* flag to control icmodb_init() by ICMODBMISC structure passed as a first parameter */


/* ICMODBMISC:  Control structure passed to icmodb_init() as a first parameter when run in ICMODB_INIT_USE_ICMODBMISC mode */

typedef struct _ICMODBMISC {
    int  icmodbmisc_mode ;      /* ICMODB_INIT_xx */
    char *icmodbmisc_dirpath_or_fn ;  /* directory path in which the INF files are stored or full filename for ICMODB_INIT_DATAHIST_GENERIC */
    char *((CALLBK_FCN_PREFIX *icmodbmisc_altfile_fcn)(Args_altfile_fcn));    /* called before open a file to read */
    void *icmodbmisc_altfile_userp  ;  /* user handle to be passed to altfile_fcn */
    } ICMODBMISC ;


/* parameter to icmodb_altid_search */

#define ICMODB_ALTID_TYPE_UNKNOWN  0    /*  This altid could be any type  */
#define ICMODB_ALTID_TYPE_CUSIP    1    /*  This altid is CUSIP   */
#define ICMODB_ALTID_TYPE_ISIN     2    /*  This altid is ISIN    */
#define ICMODB_ALTID_TYPE_BBGID    3    /*  This altid is BBGID   */
#define ICMODB_ALTID_TYPE_BBGTK    4    /*  This altid is BBGTK   */
#define ICMODB_ALTID_TYPE_BBGDEAL  5    /*  This altid is BBGDEAL */


/* index values for icmodb_setup_altid_tbls() */

#define ICMODB_ALTID_TBL_CMOCUSIP  0  /* default CMO cusip table */
#define ICMODB_ALTID_TBL_MBSCUSIP  1  /* default MBS cusip table */
#define ICMODB_ALTID_TBL_MGPCUSIP  2  /* default MGP cusip table */
#define ICMODB_ALTID_TBL_DUSCUSIP  3  /* default DUS cusip table */
#define ICMODB_ALTID_TBL_BDCCUSIP  4  /* default BDC cusip table */
#define ICMODB_ALTID_TBL_ISIN      5  /* default ISIN table */
#define ICMODB_ALTID_TBL_BBGID     6  /* default Bloomberg ID table */
#define ICMODB_ALTID_TBL_BBGTK     7  /* default Bloomberg ticker table */
#define ICMODB_ALTID_TBL_BBGDEAL   8  /* default Bloomberg dealname table */
#define ICMODB_ALTID_TBL_USER      9  /* user provided lookup table */


/* AVG_INFO: average delinq info overrides for whole loans */

typedef struct _AVG_INFO {
    char  *avg_next          ;  /* ptr to next in the link list */
    int    avg_coll_type     ;  /* AVG_COLL_xx */
#define AVG_COLL_PMT      1
#define AVG_COLL_BAL      2
#define AVG_COLL_RATE     3
#define AVG_COLL_ACTBAL   4
#define AVG_COLL_PREVRATE 5
#define AVG_COLL_XRSBAL   6
    int    avg_delay_months  ;  /* average delaying */
    int    avg_delinq_months ;  /* # of months delinq */
    int    avg_months        ;  /* # of months to average */
    int    avg_groupno       ;  /* collateral group# */
    double avg_value         ;  /* the average value */
    } AVG_INFO ;

/* AGGINFO: aggregate update info for updating whole loans */

typedef struct _AGGINFO {
    char  *ai_next          ;  /* ptr to next in the link list */
    int    ai_agginfo_type  ;  /* index in cmo_agginfo_names list */
    int    ai_groupno       ;  /* collateral group# */
    double ai_value         ;  /* the AGGINFO value */
    } AGGINFO ;

/* IOVERRIDEMISC: additional icmo_override_coll_cf for whole loans */

typedef struct _IOVERRIDEMISC {
    char iover_already_compensated;    /* if TRUE, wont adjust internal*/
    char iover_decr_coll_vint ;        /* if TRUE, subtract from cf's */
    char iover_shiftint_dontreduce ;   /* if TRUE, DONT_REDUCE_SHIFT% */
    char iover_ignore_neg_nsints ;     /* if TRUE, ignore negative nsints in agg cashflow */
    double iover_servfee_compensated ; /* override default servfee comp */
    double iover_xrs_curnet ;          /* override netrate used for XRS frac */
    double *iover_vintshort_fullprepay;/* int shortfall prepay in full */
    double *iover_vintshort_partprepay;/* int shortfall part prepayment */
    double *iover_vintshort_loss ;     /* int shortfall due to losses */
    double *iover_vintshort_ssra ;     /* int shortfall due to Soldiers and Sailors Reliev Act */
    double *iover_vcollnetrate ;       /* restated collat net rates */
    double *iover_vcollnetmargin ;     /* restated collat net margin */
    double *iover_vcollnetlifecap ;    /* override COLL_NET_LIFECAP */
    double *iover_vcollIOrate ;        /* override COLL("XRS_IO_RATE") */
    double *iover_vcollnetrate_um ;
    double *iover_vcollnetratecf_um ;    /* unmodified collat net rates */
    double *iover_voptint_modify_reduction ;
    double *iover_vcollservfee ;       /* restated collat servfee   */
    double *iover_vpart_to_dd ;        /* curtail$ between 1st & determ */
    double *iover_vpart_from_dd ;      /* curtail$ between determ & eom */
    double *iover_vlosspaccum ;        /* accumulated princ loss */
    double *iover_vunrealized_writedown_accum ; /* accumulated implied writedown */
    double *iover_vimplied_writedown ;
    double *iover_vnotionalbal  ;      /* notional balance vector */
    double *iover_vnegam ;             /* negam principal vector */
    double *iover_vdraws ;             /* Line-of-credit draw vector */
    double *iover_vexcessintcash ;     /* excessint as defined in CDI */
    double *iover_vnetratecf_mtgdue ;  /* accum mtgdue netratecf */
    double *iover_vym  ;               /* accum YM */
    double *iover_vpreppen  ;          /* accum Prepay Penalties */
    double *iover_vdeferint ;          /* deferedint payback */
    double *iover_xrs_frac [ICMO_MAX_COLL_P_TYPE+1]; /* XRS fractions  */
    double *iover_vdefeased ;          /* defeased amount */
    double *iover_vstl_cfvect [ICMO_N_STL_VECTS];
    AVG_INFO *iover_avg_list ;         /* average delinq. info */
    AGGINFO *iover_agginfo_list ;      /* aggregate update info */
    POOL_INFO *iover_pip  ;            /* misc. pool info */
    PREPHIST *iover_cpr ;              /* historical CPR's */
    PREPHIST *iover_psa ;              /* historical PSA's */
    double ((CALLBK_FCN_PREFIX *iover_symvar_fcn)
            (Args_iover_symvar_fcn));  /* override symvars */
    double ((CALLBK_FCN_PREFIX *iover_index_fcn)
            (Args_iover_index_fcn));   /* override IDX values */
    double *iover_misc_coll_p [ICMO_N_MISC_COLL_P_TYPE]; /* misc coll_p*/
    double *iover_misc_coll_i [ICMO_N_MISC_COLL_I_TYPE]; /* misc coll_i*/
    double *iover_vnonperforming_bal  ;    /* Non-Performing Balance */
    double *iover_vaddl_vects[ICMO_N_ADDL_VECTS] ; /* MB addl vects: forbearance, int advance, etc */
    } IOVERRIDEMISC ;
#define IOVERRIDEMISC_DEFINED


/* Defined for ICMO_MBSPOOL_LOOP: */

#define ICMOAGENCY_ALL     (-1)  /* all agency (FNMA,FHLMC,GNMA,GNMA2) */
#define ICMOMBSPOOL_ASOF_ORIGIN     0  /* as of pool issue */
#define ICMOMBSPOOL_ASOF_LATEST  9999  /* as of latest info */

/* ICMOMBSLOOP: miscellaneous ICMO_MBSMBS_LOOP input/output */

typedef struct _ICMOMBSLOOP {
    int      icmombsloop_hist_prep ;   /* calc 1m,3m,6m,12m,life CPR/PSA */
    char    *icmombsloop_start_pnum ;  /* start loop from this pool # */
    char    *icmombsloop_user ;        /* place holder for user data struct*/
    char     icmombsloop_tape_use ;    /* which gnma tape to use (A,B,C) */
    int      icmombsloop_nmonth_hist ; /* no. of month hist factor,WAC,WAM,WAL wanted */
    int      icmombsloop_single_pool ; /* not to loop, just find icmombsloop_start_pnum */
    YyyyMmDd icmombsloop_asof_date ;   /* YyyyMmDd date of current pool information */
    int      icmombsloop_use_addl_files ; /* ICMOMBSLOOP_READ_ADDL_xx: enable accessing of geographical info, supp header file, etc. - will slow down looping thru pools */
#define icmombsloop_use_geo_file icmombsloop_use_addl_files
    ICMOMISC *icmombsloop_icmomiscp ;  /* to ICMOMISC structure to control behavior */
    ICMO *icmombsloop_icmop ; /* do NOT modify or icmo_free().  ICMO structure needed for user to get index names in callback function by calling icmo_index_name( icmop, ... ) */

    /* If icmombsloop_nmonth_hist is not zero, user must allocate the
       following 4 vectors of length (icmombsloop_nmonth_hist+1).
       [0] for ISSUE month, [1] for one month back, and so on */

    double *icmombsloop_hist_vfactor; /* OUT: hist factors */
    double *icmombsloop_hist_vwac   ; /* OUT: hist wac     */
    double *icmombsloop_hist_vnetrate ; /* OUT: hist net rate */
    int    *icmombsloop_hist_vwam   ; /* OUT: hist wam     */
    int    *icmombsloop_hist_vwala  ; /* OUT: hist wala    */

    char  icmombsloop_pool_cusip [MAX_CUSIP_SIZE+1]; /* OUT: pool cusip */
    }  ICMOMBSLOOP ;

#ifdef ICMO_NO_ANSI_PROTOTYPING
#define Args_mbspool_loop_fcn
#else
#define Args_mbspool_loop_fcn ICMOMBSLOOP *, int, POOL_INFO *, char *, char *, char *
#endif

/* PORTFMISC: Structure containing user's settings governing */
/*     the configuration of a portfolio                      */

typedef struct _PORTFMISC {
    char     *pfmisc_base_cdi_path ;     /* base path to CDI directory. Replaces dir_prefix parameter  */
    char     *pfmisc_base_cdu_path ;     /* base path to CDU directory. Replaces dir_prefix parameter  */
    YyyyMmDd pfmisc_settle_date ;        /* Settle date for p'folio */
    int      pfmisc_payment_day ;        /* Day of month p'folio pays */
    int      pfmisc_businessday_method ; /* ICMO_BUSINESSDAY_xx for p'folio */
    char     *pfmisc_business_center_name ; /* Business center name */
    int      pfmisc_save_component_cfs ; /* TRUE: save individual cashflows */
    char    *pfmisc_errmsg ;             /* Buffer for portf_init errs */
INTEX_INTERNAL_USE_ONLY    void     *pfmisc_internal ;             /* for internal use */
} PORTFMISC ;


/* PORTF_COMPONENT:  Info for a single component within a portfolio */

typedef struct _PORTF_COMPONENT {
    char      *pfc_next ;           /* To next p'folio component */
    char      *pfc_dealname ;       /* Name of component deal */
    char      *pfc_tranchename ;    /* Name of component tranche */
    double     pfc_scaling_factor ; /* Factor by which to scale component */
    int        pfc_n_pf_cashflows ; /* # of mos cfs contribute to p'folio */
    char      *pfc_pfcfp ;          /* To optionally-saved component cfs */
} PORTF_COMPONENT ;


/* PORTF:  Anchor structure for portfolio analysis */

typedef struct _PORTF {
    ICMO   *portf_icmop ;      /* ICMO containing p'folio stats results */
    char   *portf_errmsg ;     /* Error msg string from portf fcn's */
    int     portf_stats_set ;  /* TRUE if p'folio stats are fresh */

  /* Set before icmo_portf_accum() or icmo_portf_adjust(): */
    int     portf_n_reinv_rates ; /* Number of rates given in... */
    double *portf_vreinv_rates ;  /* ... vector of reinvestment rates */
    int     portf_exclude_balances ; /* flag to accum or not to accum the balances */

  /* Set before icmo_portf_stats(): */
    int     portf_yldcrv_n_nodes ;       /* # of nodes on yield curve */
    int     portf_yldcrv_spread_method ; /* ICMOYLDCRV_SPREAD_xx: interpolate method */
    double  portf_yldcrv_explicit ;      /* ... if ICMOYLDCRV_SPREAD_EXPLICIT_xx */
    double *portf_yldcrv_nodes ;         /* Yldcrv maturities, yrs */
    double *portf_yldcrv_vals ;          /* Yldcrv yields, pct */
    int     portf_stats_py_mode ;        /* ICMOPY_xx. Set to NONE to price to sum of bonds PV */
    double  portf_stats_py_val ;         /* If mode is not ICMOPY_NONE, the value of the mode */

INTEX_INTERNAL_USE_ONLY    char *portf_pfintp ;   /* For internal use */
} PORTF ;


/* ICMO_DATAVAL: Structure to hold return value from evaluated script, etc. */

typedef struct ICMO_DATAVAL {
    int   data_type ;            /* ICMO_DATAVAL_xx */
    union                        /* data value */
        {
        void  *dataval_ptr ;     /* unspecified data ptr */
        char  *dataval_str ;     /* string value */
        int    dataval_int ;     /* integer value */
        POOL_INFO *dataval_pip;  /* pool info */
        double dataval_dbl ;     /* double value */
        } data_val ;
    int   data_val_malloced ;    /* TRUE if data_val is malloced */
    } ICMO_DATAVAL ;

/* ICMO_DATAVAL_xx: choices of data_type in ICMO_DATAVAL */
#define ICMO_DATAVAL_UNKNOWN -1  /* unspecified data type */
#define ICMO_DATAVAL_NONE     0  /* no data */
#define ICMO_DATAVAL_PTR      1  /* use dataval_ptr */
#define ICMO_DATAVAL_STR      2  /* use dataval_str */
#define ICMO_DATAVAL_INT      3  /* use dataval_int */
#define ICMO_DATAVAL_DBL      4  /* use dataval_dbl */
#define ICMO_DATAVAL_PIP      5  /* use dataval_pip */


#define ICMO_FUNCTION_UNKNOWN (-999)  /* return this if external function evaluator does not know the function */
#define ICMO_SYMBOL_UNKNOWN (-999)    /* return this if external symbol evaluator does not know the symbol */


/* ICMO_SCRIPT_TYPE_xx: script types */

#define ICMO_SCRIPT_TYPE_UNKNOWN      0 /* undefined script */
#define ICMO_SCRIPT_TYPE_PREPAY       1 /* prepayment script */
#define ICMO_SCRIPT_TYPE_ASSET_QUERY  2 /* asset query script */
#define ICMO_SCRIPT_TYPE_PAYRULE      3 /* payrule script */


/* ICMO_SCRIPT: Structure to hold unparsed user-defined script.  */

typedef struct ICMO_SCRIPT_HANDLE ICMO_SCRIPT_HANDLE ;

typedef struct ICMO_SCRIPT {
    /* one of the first two fields must be NULL */
    char  *script_buff      ;  /* buffer holding the script  */
    char  *script_filename  ;  /* full path to file holding the script */
    char   script_name[ ICMO_MAX_TRNAM_CHARS + 1 ]  ;  /* optional name for the script.  If non-null, this will
                                                        * override a script name parsed from the script headers. */
    int    script_type      ;  /* ICMO_SCRIPT_TYPE_xx, script type to parse */
    int    script_loose_syntax; /* allow loosely written syntax to be compatible with older scripts. */
    char **script_symlist   ;  /* optional list of symbols */
    int    script_nsymlist  ;  /* number of elements in symlist */
    char **script_funclist  ;  /* optional list of function names, must be NULL terminated */
    int    script_nfunclist ;  /* number of elements in funclist */
    int ((CALLBK_FCN_PREFIX *script_sym_fcn)(ICMO *, ICMO_SCRIPT_HANDLE *, int, int));  /* optional user callback fcn */
    int ((CALLBK_FCN_PREFIX *script_func_fcn)(ICMO *, ICMO_SCRIPT_HANDLE *, int, ICMO_DATAVAL *, int));  /* optional user callback fcn */
    char **script_errmsg_list; /* NULL-terminated error message vector */
INTEX_INTERNAL_USE_ONLY    void  *script_internalp ;  /* internal use only */
} ICMO_SCRIPT ;


/* ICMO_SCRIPT_HANDLE: Structure to hold pointer to internal script
handle structure. */

struct ICMO_SCRIPT_HANDLE {
    char scrhdl_script_name[ ICMO_MAX_TRNAM_CHARS + 1 ] ;  /* name of the source script */
    char *scrhdl_script_fullname  ;  /* full name of the script */
    int  scrhdl_script_type       ;  /* ICMO_SCRIPT_TYPE_xx, read from script header */
    int  scrhdl_loose_syntax      ;  /* allow loosely written syntax to be compatible with older scripts. */
    ICMO *scrhdl_icmop            ;  /* Pointer to the ICMO structure associated with this script. If the script is parsed in a child deal, pointer to the ICMO structure of that child. */
    int  scrhdl_nargs             ;  /* Input: # of input arguments */
    ICMO_DATAVAL *scrhdl_argv     ;  /* Input: vector of argument values */
    ICMO_DATAVAL scrhdl_retval    ;  /* Output: return value from evaluating script handle */
    char **scrhdl_retval_list     ;  /* optional list of valid script return values */
    char **scrhdl_symlist         ;  /* NULL-terminated list of external symbol names */
    int  scrhdl_nsymlist          ;  /* number of external symbol names */
    char **scrhdl_funclist        ;  /* NULL-terminated list of external function names */
    int  scrhdl_nfunclist         ;  /* number of external function names */
    char *scrhdl_userp            ;  /* handle for user-defined structure */
    int  scrhdl_dbg_on            ;  /* TRUE to run with debugger */
    ICMO_SCRIPT_HANDLE *scrhdl_up ;  /* If non-NULL, handle to parent script that defines this function */
} ;

#define ICMOLOG_CLEANUP     1          /* report on pay cleanups */

/* ICMO_MSA_FILL_xx: choices for third parameter of icmo_zipcode_to_msa() */
#define ICMO_MSA_FILL_ALWAYS          0 /* return MSA code and description, use best guess if no exact match is found */
#define ICMO_MSA_FILL_ONLY_IF_EXACT   1 /* return MSA code and description only if zipcode is found */
#define ICMO_MSA_FILL_ADDITIONAL_INFO 2 /* will fill addition geographical info including MSA for a given zipcode.   Data returned in ICMO field icmo_zipcode_related_loandatap. Note that this can be slow.  */
#define ICMO_CBSA_FILL_ADDITIONAL_INFO 3 /* will fill available addition geographical info for a given CBSA.   Data returned in ICMO field icmo_zipcode_related_loandatap. Note that this can be slow.  */

/* ICMO_EVAL_SCHED_xx: choices for fourth argument to icmo_eval_sched_cashflows() */
#define ICMO_EVAL_SCHED_CF                0x01 /* store pool CFs in icmoloancf_xx fields */
#define ICMO_EVAL_SCHED_YM_FORMULA        0x02 /* evaluate YM formula and store in pool's ym_vymval_in_points_units */
#define ICMO_EVAL_SCHED_YM_FORMULA_LOCAL  0x06 /* conserve memory - evaluated YM formula stored in ym_vymval_in_points_units is ONLY meaningful when accessed inside prepayment function after icmo_eval_sched_cashflows() call */


/* DEPRECATED - ICMO_EVAL_YM_FORMULA_xx: choices for eval_ym_store argument to deprecated icmo_eval_ym_formula() function */
#define ICMO_EVAL_YM_FORMULA_PERSIST  0  DEPRECATED /* function results persist in each pool's ym_vymval_in_points_units */
#define ICMO_EVAL_YM_FORMULA_LOCAL    1  DEPRECATED /* function results only available in prepayment callback function which calls icmo_eval_ym_formula().  Undefined after callback function returns. */

/* DEPRECATED - old macros used for memory direct access */
#define ICMODEALMEM_I_MULT(deal)    (deal->icmo_mem_i_mult)
#define ICMOMEM_I_MULT              ICMODEALMEM_I_MULT(icmop)
#define ICMODEALMEM_COORD(deal,i,t) (ICMODEALMEM_I_MULT(deal)*(i)+4*(t))
#define ICMOMEM_COORD(i,t)          ICMODEALMEM_COORD(icmop,i,t)
#define ICMODEALMEM_P(deal,i,t)   (deal->icmo_memstore==NULL? 0.: deal->icmo_memstore [ ICMODEALMEM_COORD(deal,i,t)+0 ])
#define ICMODEALMEM_I(deal,i,t)   (deal->icmo_memstore==NULL? 0.:deal->icmo_memstore [ ICMODEALMEM_COORD(deal,i,t)+1 ])
#define ICMODEALMEM_CF(deal,i,t)  (deal->icmo_memstore==NULL? 0.:deal->icmo_memstore [ ICMODEALMEM_COORD(deal,i,t)+2 ])
#define ICMODEALMEM_BAL(deal,i,t) (deal->icmo_memstore==NULL? 0.:deal->icmo_memstore [ ICMODEALMEM_COORD(deal,i,t)+3 ])
#define ICMOMEM_P(i,t)   (icmop->icmo_memstore==NULL? 0.: icmop->icmo_memstore [ ICMOMEM_COORD(i,t)+0 ])
#define ICMOMEM_I(i,t)   (icmop->icmo_memstore==NULL? 0.: icmop->icmo_memstore [ ICMOMEM_COORD(i,t)+1 ])
#define ICMOMEM_CF(i,t)  (icmop->icmo_memstore==NULL? 0.: icmop->icmo_memstore [ ICMOMEM_COORD(i,t)+2 ])
#define ICMOMEM_BAL(i,t) (icmop->icmo_memstore==NULL? 0.: icmop->icmo_memstore [ ICMOMEM_COORD(i,t)+3 ])
#define ICMOCFS_DISKSTORE  ICMOCFS_MEMSTORE

/* Intex CMO Subroutines function declarations */

#ifdef IBM370
//#include "icmoibm.h" //WTW - Gen2 - Not allowed
#endif


/*---- for win nt, entry points may be __cdecl or __stdcal */
#ifdef WANT_CDECL_APIENTRY
#define INTEX_APIENTRY __cdecl
#else
#define INTEX_APIENTRY __stdcall
#endif

/*---- used only for win nt wrapped functions must always be stdcall */
/*---- to accommodate office 97 */
#define WINTEX_APIENTRY __stdcall


/*---- icmo prefix/suffix...any undefines are cleaned up later */
/*---- may have already defined these, so protect ourselves */
#ifdef ICMO_DLL_EXPOSE
#ifndef ICMO_DLL_PREFIX

#ifdef MS_WINNT
#define ICMO_DLL_PREFIX INTEX_APIENTRY
#define ICMO_ExtC __declspec(dllexport)
#else
#ifdef MS_WIN32S
#define ICMO_DLL_PREFIX _export
#define ICMO_ExtC
#else
#define ICMO_DLL_PREFIX  far pascal _loadds
#endif
#endif

#endif
#endif


/*---- wcmo prefix/suffix...any undefines are cleaned up later */
/*---- may have already defined these, so protect ourselves */
#ifdef WCMO_DLL_EXPOSE
#ifndef WCMO_DLL_PREFIX

#ifdef MS_WINNT
#define WCMO_DLL_PREFIX WINTEX_APIENTRY
#define WCMO_ExtC __declspec(dllexport)
#else
#define WCMO_DLL_PREFIX  far pascal _loadds
#endif

#endif
#endif

/*---- dll prefix/suffix...any undefines are cleaned up later */
#ifdef SYS_DLL_EXPOSE

#ifdef MS_WINNT
#define DLL_PREFIX INTEX_APIENTRY
#define DLL_ExtC __declspec(dllexport)
#else
#ifdef MS_WIN32S
#define DLL_PREFIX _export
#define DLL_ExtC
#else
#define DLL_PREFIX  far pascal _loadds
#endif
#endif

#endif

/*---- this is the clean up area for prefix/suffix */
/*---- if not defined at all, define to nothing */
#ifndef ICMO_DLL_PREFIX
#define ICMO_DLL_PREFIX
#endif

#ifndef ICMO_ExtC
#define ICMO_ExtC
#endif

#ifndef WCMO_ExtC
#define WCMO_ExtC
#endif

#ifndef DLL_PREFIX
#define DLL_PREFIX
#endif

#ifndef DLL_ExtC
#define DLL_ExtC
#endif

typedef void ((CALLBK_FCN_PREFIX FCN_deal_errfcn)(Args_deal_errfcn)) ;
typedef void ((CALLBK_FCN_PREFIX FCN_global_errfcn)(Args_global_errfcn)) ;

#ifndef TOWERS_WATSON_USE_DYN_DLL

#ifdef ICMO_NO_ANSI_PROTOTYPING

void icmo_init ();
void icmo_finalize ();
int icmo_initialized ();
int icmo_finalized ();
int icmo_env_set_attr ();
int icmo_env_get_attr ();
int icmo_mpi_message_set();
int icmo_mpi_message_get();
ICMOMISC *icmo_setup_icmomiscp () ;
ICMO *icmo_deal() ;
void icmo_free() ;
ICMO *icmo_parse() ;
void icmo_cashflows() ;
int icmo_stats() ;
void icmo_index_set() ;
void icmo_set_index_forecast() ;
void *icmo_make_struct() ;
int icmo_free_struct() ;
void icmo_currency_set() ;
YyyyMmDd icmo_month2date() ;
int icmo_date2month() ;
char *icmo_fmtdate() ;
YyyyMmDd icmo_tr_month2date() ;
int icmo_tr_date2month() ;
char *icmo_tr_fmtdate() ;
char *icmo_fmtprice() ;
int icmo_tranchenum() ;
void icmo_get_collat_cf() ;
void icmo_set_pmt_to_pmt_mode() ;
int icmo_pay_1period() ;
double icmo_pay_1period_info() ;
void icmo_buy_collat() ;
void icmo_sell_collat() ;
void icmo_replace_collat_list() ;
int  icmo_apply_collat_transact_set() ;
void icmo_decluster_pools() ;
void icmo_cluster_pools() ;
void icmo_override_coll_cf() ;
void icmo_use_bv_coll() ;
int  icmo_eval_sched_cashflows() ;
double icmo_convert_prepay_units() ;
double icmo_convert_yield_units () ;
int icmo_set_aggunion_id() ;
ICMO_AGG_UNION *icmo_get_aggunion() ;
#define mbs__eqcpr   icmo_convert_prepay_units
#define mbs__eqyield icmo_convert_yield_units
char *icmo_version_chk() ;
char *icmo_version_validate() ;
int icmo_schedule_met() ;
int icmo_get_schedule() ;
int icmo_schedule_dependecy() ;
int icmo_effective_collars() ;
void icmo_forward_cashflows() ;
int icmo_forward_settle_date() ;
void icmo_reinv_cashflows() ;
int icmo_collat_type() ;
BLOCK_INFO *icmo_tranche_blocks() ;
char *icmo_pmt_to_pmt_freeze() ;
void icmo_pmt_to_pmt_refreeze() ;
void icmo_pmt_to_pmt_thaw() ;
void icmo_pmt_to_pmt_toss() ;
int icmo_scenario_vect() ;
void icmo_show_clock() ;
int icmo_count_npools() ;
ICMO_CURRENCY *icmo_get_currency() ;
int icmo_addl_info();
void icmo_setup_commercialop_by_id() ;
void icmo_adjust_arm_index() ;
ICMO *icmo_find_topmost_icmop() ;
char *icmo_tr_used_cusip() ;
char *icmo_index_name() ;
double icmo_get_idx_val();
int icmo_open_log() ;
int icmo_deal_has_no_sched_dependency() ;
int icmo_deal_effective_collars() ;
double icmo_prepay_speed();
double icmo_get_orig_notional_bal() ;
long icmo_run_mbspool_loop() ;
long icmo_mbspool_loop();
DEAL_CLASS *icmo_tranche_deal_class();
double icmo_horizon_return() ;
double icmo_total_return() ;
double icmo_effcoup_calc( );
double icmo_yldcrv_yield_at_maturity() ;
int icmo_property_to_loan_forecast() ;

YyyyMmDd icmo_YyyyMmDd_add() ;
YyyyMmDd icmo_YyyyMmDd_addmo() ;
YyyyMmDd icmo_YyyyMmDd_ddset() ;
int      icmo_YyyyMmDd_diffmo() ;
int      icmo_YyyyMmDd_day() ;
int      icmo_YyyyMmDd_valid() ;
YyyyMmDd icmo_YyyyMmDd_today() ;
char    *icmo_YyyyMmDd_fmt() ;
int      icmo_YyyyMmDd_conv_to_yymm() ;
YyyyMmDd icmo_YyyyMmDd_conv_from_yymm() ;
YyyyMmDd icmo_YyyyMmDd_conv_from_y_m_d() ;
YyyyMmDd icmoutil_YyyyMmDd_bd_adj ();
YyyyMmDd icmo_YyyyMmDd_bd_adj ();
char    *icmo_YyyyMmDd_seqno() ;
YyyyMmDd icmo_date_convert() ;
int      icmo_daycount() ;
double   icmo_YyyyMmDd_year_frac() ;

ICMODB *icmodb_init() ;
int icmodb_setup_cusip_tbls();
int icmodb_setup_altid_tbls();
int icmodb_cusip_to_bond() ;
int icmodb_altid_search();
int icmodb_dealstr_to_bond() ;
int icmodb_bond_info() ;
int icmodb_find_init() ;
int icmodb_find() ;
void icmodbrec_datahist_clean() ;
void icmodb_free() ;
int  icmo_dbstatus () ;
ICMODBSTAT *icmo_dbstat_init () ;
int icmo_dbstat_check () ;
void icmo_dbstat_free  () ;
int icmo_isr_play() ;
int  icmo_parser_open();
int icmo_parser_fseek() ;
void *icmo_parser() ;
int icmo_parser_close() ;
char *icmo_alter_cdu() ;
char *icmo_forecast_cdu();

void icmo_errdie() ;
void cmo_talk_a_lot() ;
ABS_SUMMARY_INFO *icmo_find_abs_summary_info() ;
int icmo_disc_margin_over_which_index() ;
void icmo_use_case_sensitive_dir() ;
int icmo_pool_is_in_group() ;
int icmo_group_is_in_group() ;
POOL_INFO **icmo_parent_pips_supported_by_child_pip();
int icmo_independent_groups() ;
void icmo_free_mbspool_cache() ;
TAX_TRANCHE *icmo_tranche_taxinfo() ;
int icmo_typical_parse_control_fcn();
int icmo_typical_parse_control_fcn2();
char *icmo_zipcode_to_msa() ;
char *icmo_format_region_id() ;
PORTF *icmo_portf_init() ;
int icmo_portf_reset() ;
PORTF_COMPONENT *icmo_portf_accum() ;
int icmo_portf_adjust() ;
int icmo_portf_stats() ;
void icmo_portf_free() ;
ICMO *icmo_portf_set_cfs() ;
double icmo_solver();
void icmo_validate_tax_tranche() ;
FCN_deal_errfcn *icmo_set_deal_errfcn();
FCN_global_errfcn *icmo_set_global_errfcn();
ERRINFO *icmo_errinfo();
void icmo_raise_errdie();
double icmo_convert_prep_rate() ;
ICMO_SCRIPT_HANDLE *icmo_parse_script() ;
int  icmo_eval_script();
int  icmo_set_prepay_script() ;
int  icmo_set_script_retval () ;
void icmo_free_script_handle() ;
ICMO_SCRIPT_HANDLE *icmo_get_prepay_script() ;
void icmo_set_loandata_forecast();
int  icmo_get_loandata_val();
void icmo_ovrdset_asset_vect () ;
void *icmo_get_collat_userdata() ;
YyyyMmDd icmo_YyyyMmDd_businessday() ;
YyyyMmDd icmo_YyyyMmDd_businessday_adj() ;
int  icmo_eval_ym_formula() ;
char *icmo_get_name();
char *icmo_get_loandata_translation();
void icmo_ppmdl_set_adco_credit_assum() ;
void icmo_ppmdl_set_aft_default_assum() ;
void icmo_worker() ;
int  icmo_spstr();
INTEX_INTERNAL_USE_ONLY char *icmo_dummy_dealname() ;

#ifdef MS_WIN16 /* make parallel to #ifdef for ANSI prototyping */
#else
void wcmo_open_debug_files() ;
void wcmo_close_debug_files() ;
#endif /* MS_WIN16 */


#else

ICMO_ExtC void icmo_init ();
ICMO_ExtC void icmo_finalize ();
ICMO_ExtC int icmo_initialized ();
ICMO_ExtC int icmo_finalized ();
ICMO_ExtC int ICMO_DLL_PREFIX icmo_env_set_attr ( ICMOENVKEY, int, char * );
ICMO_ExtC int ICMO_DLL_PREFIX icmo_env_get_attr ( ICMOENVKEY, int *, char * );
ICMO_ExtC int icmo_mpi_message_set(char *,  void *);
ICMO_ExtC int icmo_mpi_message_get(char **, void *);
ICMO_ExtC ICMOMISC * ICMO_DLL_PREFIX icmo_setup_icmomiscp ( ICMOMISC *, int ) ;
ICMO_ExtC ICMO * ICMO_DLL_PREFIX icmo_deal( ICMOMISC *, char *, char *, int,
     YyyyMmDd, int, int, double *, int * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_free( ICMO ** ) ;
ICMO_ExtC ICMO * ICMO_DLL_PREFIX icmo_parse( char *, char *, int, int, int, double *, int * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_index_set( ICMO *, int, int, double * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_set_index_forecast( ICMO *, int ) ;
ICMO_ExtC void * ICMO_DLL_PREFIX icmo_make_struct(ICMO *, int, const char *, char ** ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_free_struct(ICMO *, int, void **);
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_currency_set( ICMO *, ICMO_CURRENCY *, ICMO_CURRENCY *,
                            int, YyyyMmDd *, double * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_cashflows( ICMO *, YyyyMmDd, int, int, double *,
     void ((CALLBK_FCN_PREFIX *)(Args_speed_fcn)),
     void ((CALLBK_FCN_PREFIX *)(Args_index_fcn)), int, char *);
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_tranchenum( ICMO *, const char * ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_stats( ICMO *, int, double, int, double ) ;
ICMO_ExtC YyyyMmDd ICMO_DLL_PREFIX icmo_month2date( ICMO *, int ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_date2month( ICMO *, YyyyMmDd ) ;
ICMO_ExtC char * ICMO_DLL_PREFIX icmo_fmtdate( ICMO *, int, int ) ;
ICMO_ExtC YyyyMmDd ICMO_DLL_PREFIX icmo_tr_month2date( ICMO *, int, int ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_tr_date2month( ICMO *, int, YyyyMmDd ) ;
ICMO_ExtC char * ICMO_DLL_PREFIX icmo_tr_fmtdate( ICMO *, int, int, int ) ;
ICMO_ExtC char * ICMO_DLL_PREFIX icmo_fmtprice( ICMO *, double, int ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_get_collat_cf( ICMO *,
     void ((CALLBK_FCN_PREFIX*)(Args_pool_cf_fcn)),
     void ((CALLBK_FCN_PREFIX*)(Args_pool_cf_fcn)) ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_set_pmt_to_pmt_mode( ICMO *, YyyyMmDd,
     double ((CALLBK_FCN_PREFIX*)(Args_1speed_fcn)), double ((CALLBK_FCN_PREFIX*)(Args_1index_fcn)),
     int, char * ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_pay_1period( ICMO *, int,
     double *, double *, double *, double * ) ;
ICMO_ExtC double ICMO_DLL_PREFIX icmo_pay_1period_info( ICMO *, char * ) ;
ICMO_ExtC void ICMO_DLL_PREFIX icmo_buy_collat(ICMO *, RBC_INFO *, int, int, double ) ;
ICMO_ExtC void ICMO_DLL_PREFIX icmo_sell_collat(ICMO *, RBC_INFO *, int, double, double ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_replace_collat_list( ICMO *, POOL_INFO *, int, char * ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_apply_collat_transact_set (ICMO *, char *, char *, int, int, char *) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_decluster_pools( ICMO * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_cluster_pools( ICMO *, int ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_override_coll_cf( ICMO *, int, int, double *, double *,
     double *, double *, double *, double *, double *, double *, double *,
     IOVERRIDEMISC *, double *, double *, double * ) ;
ICMO_ExtC double ICMO_DLL_PREFIX icmo_convert_prepay_units( int, double, int ) ;
ICMO_ExtC double ICMO_DLL_PREFIX icmo_convert_yield_units ( int, double, int, int ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_set_aggunion_id( ICMO *, POOL_INFO *, int, int ) ;
ICMO_ExtC ICMO_AGG_UNION * ICMO_DLL_PREFIX icmo_get_aggunion( ICMO *, int, int ) ;
#ifndef MS_WINNT
#define mbs__eqcpr   icmo_convert_prepay_units
#define mbs__eqyield icmo_convert_yield_units
#endif
ICMO_ExtC ABS_SUMMARY_INFO * ICMO_DLL_PREFIX icmo_find_abs_summary_info( ICMO *, ABS_SUMMARY_INFO *, int, int, int ) ;
ICMO_ExtC int ICMO_DLL_PREFIX  icmo_disc_margin_over_which_index( ICMO *, int ) ;

ICMO_ExtC char * ICMO_DLL_PREFIX icmo_version_chk( const char * ) ;
ICMO_ExtC char * ICMO_DLL_PREFIX icmo_version_validate( const char *, char *, int *, char * ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_schedule_met( ICMO *, int ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_get_schedule( ICMO *, char *,
                                        int *, YyyyMmDd **, double ** ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_schedule_dependecy( ICMO *, int ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_effective_collars( ICMO *, int, int, double *, double * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_forward_cashflows( ICMO *, int, int ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_forward_settle_date( ICMO *, int, YyyyMmDd, int ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_reinv_cashflows( ICMO *, int, int, int,
     double *, double, double *, double * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_use_bv_coll( ICMO *, int ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_eval_sched_cashflows( ICMO *, POOL_INFO *, int, int, int ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_collat_type( ICMO * ) ;
ICMO_ExtC BLOCK_INFO * ICMO_DLL_PREFIX icmo_tranche_blocks( ICMO *, int ) ;
ICMO_ExtC char * ICMO_DLL_PREFIX icmo_pmt_to_pmt_freeze( ICMO * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_pmt_to_pmt_refreeze( ICMO *, char * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_pmt_to_pmt_thaw( ICMO *, char * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_pmt_to_pmt_toss( char ** ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_scenario_vect( ICMO *, char *, int, double * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_show_clock( ICMO * ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_count_npools( ICMO *,
                  void ((CALLBK_FCN_PREFIX*)(Args_count_npools_fcn)) ) ;
ICMO_ExtC ICMO_CURRENCY * ICMO_DLL_PREFIX icmo_get_currency( ICMO *, char * ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_addl_info( ICMO *, int, int );
ICMO_ExtC void    ICMO_DLL_PREFIX icmo_setup_commercialop_by_id( ICMO *, char **, int ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_adjust_arm_index ( ICMO *, int , double * ) ;

ICMO_ExtC YyyyMmDd ICMO_DLL_PREFIX icmo_YyyyMmDd_add( YyyyMmDd, int, int ) ;
ICMO_ExtC YyyyMmDd ICMO_DLL_PREFIX icmo_YyyyMmDd_addmo( YyyyMmDd, int, int ) ;
ICMO_ExtC int      ICMO_DLL_PREFIX icmo_YyyyMmDd_diffmo( YyyyMmDd, YyyyMmDd ) ;
ICMO_ExtC YyyyMmDd ICMO_DLL_PREFIX icmo_YyyyMmDd_ddset( YyyyMmDd, int ) ;
ICMO_ExtC int      ICMO_DLL_PREFIX icmo_YyyyMmDd_day( YyyyMmDd ) ;
ICMO_ExtC int      ICMO_DLL_PREFIX icmo_YyyyMmDd_valid( YyyyMmDd, int ) ;
ICMO_ExtC YyyyMmDd ICMO_DLL_PREFIX icmo_YyyyMmDd_today( void ) ;
ICMO_ExtC char *   ICMO_DLL_PREFIX icmo_YyyyMmDd_fmt( char *, YyyyMmDd, int ) ;
ICMO_ExtC int      ICMO_DLL_PREFIX icmo_YyyyMmDd_conv_to_yymm( YyyyMmDd ) ;
ICMO_ExtC YyyyMmDd ICMO_DLL_PREFIX icmo_YyyyMmDd_conv_from_yymm( int ) ;
ICMO_ExtC YyyyMmDd ICMO_DLL_PREFIX icmo_YyyyMmDd_conv_from_y_m_d( int, int, int ) ;
ICMO_ExtC YyyyMmDd ICMO_DLL_PREFIX icmoutil_YyyyMmDd_bd_adj ( YyyyMmDd, int, int, char *, char *);
ICMO_ExtC YyyyMmDd ICMO_DLL_PREFIX icmo_YyyyMmDd_bd_adj (ICMO *, YyyyMmDd, int, int, char *);
ICMO_ExtC char *   ICMO_DLL_PREFIX icmo_YyyyMmDd_seqno( YyyyMmDd, char * ) ;
ICMO_ExtC YyyyMmDd ICMO_DLL_PREFIX icmo_date_convert( ICMO *, int, YyyyMmDd, ICMO *, char * ) ;
ICMO_ExtC int      ICMO_DLL_PREFIX icmo_daycount( ICMO *, int, YyyyMmDd, YyyyMmDd ) ;
ICMO_ExtC double   ICMO_DLL_PREFIX icmo_YyyyMmDd_year_frac( ICMO *, YyyyMmDd, YyyyMmDd, int, int, int, char *, int, int ) ;

ICMO_ExtC ICMODB * ICMO_DLL_PREFIX icmodb_init( char *, int, int ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmodb_setup_cusip_tbls( ICMODB *, int, int *, char ** );
ICMO_ExtC int    ICMO_DLL_PREFIX icmodb_setup_altid_tbls( ICMODB *, int, int *, char ** );
ICMO_ExtC int    ICMO_DLL_PREFIX icmodb_cusip_to_bond( ICMODB *, char *, char *, char * ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmodb_altid_search( ICMODB *, char *, int, char *, char * ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmodb_dealstr_to_bond( ICMODB *, char *, char *, char *, char * ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmodb_bond_info( ICMODB *, char *, char *, char *, ICMODBREC * ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmodb_find_init( ICMODB *, char *, char * ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmodb_find( ICMODB *, ICMODBREC * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmodbrec_datahist_clean( ICMODBREC_DATAHIST * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmodb_free( ICMODB ** ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_dbstatus( char *, char *, int, int ) ;
ICMO_ExtC ICMODBSTAT * ICMO_DLL_PREFIX icmo_dbstat_init ( char *, char *, int ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_dbstat_check ( ICMODBSTAT * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_dbstat_free  ( ICMODBSTAT ** ) ;
ICMO_ExtC int ICMO_DLL_PREFIX icmo_isr_play ( char *,
    int ((CALLBK_FCN_PREFIX *isr_play_control_fcn)(Args_isr_play_control_fcn)), char *) ;

ICMO_ExtC int    ICMO_DLL_PREFIX icmo_parser_open( ICMO *, char *, int,
              int ((CALLBK_FCN_PREFIX*)(Args_parserr_fcn)) ) ;
ICMO_ExtC void * ICMO_DLL_PREFIX icmo_parser( ICMO * , int , char ** , char * ) ;
ICMO_ExtC int ICMO_DLL_PREFIX icmo_parser_fseek( ICMO *icmop, int ith_pfile, long int fseek_loc ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_parser_close( ICMO *, int ) ;
ICMO_ExtC char * ICMO_DLL_PREFIX icmo_alter_cdu( ICMO *, char *, char * ) ;
ICMO_ExtC char * ICMO_DLL_PREFIX icmo_forecast_cdu( ICMO *, char *, YyyyMmDd );
ICMO_ExtC ICMO * ICMO_DLL_PREFIX icmo_find_topmost_icmop( ICMO * ) ;
ICMO_ExtC char * ICMO_DLL_PREFIX icmo_tr_used_cusip( ICMO *, int ) ;
ICMO_ExtC char * ICMO_DLL_PREFIX icmo_index_name( ICMO *, int, int ) ;
ICMO_ExtC double ICMO_DLL_PREFIX icmo_get_idx_val( ICMO *, int, char *,
                                                       YyyyMmDd, int ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_open_log( ICMO * , char * , int, double, int, int, void * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX icmo_close_log( ICMO * ) ;
ICMO_ExtC void   ICMO_DLL_PREFIX cmo_talk_a_lot( char *, int, int, YyyyMmDd, YyyyMmDd ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_deal_has_no_sched_dependency( ICMO * ) ;
ICMO_ExtC int    ICMO_DLL_PREFIX icmo_deal_effective_collars( ICMO *,
             int, int, double, double, int, void *, double *, double * ) ;
ICMO_ExtC double ICMO_DLL_PREFIX icmo_prepay_speed( ICMO *, int, int, POOL_INFO * );
ICMO_ExtC double ICMO_DLL_PREFIX icmo_get_orig_notional_bal( ICMO *, int ) ;
ICMO_ExtC long   ICMO_DLL_PREFIX icmo_run_mbspool_loop( ICMOMBSLOOP *, char *, int, YyyyMmDd, int ((CALLBK_FCN_PREFIX *)(Args_mbspool_loop_fcn)) );
ICMO_ExtC long   ICMO_DLL_PREFIX icmo_mbspool_loop( ICMOMBSLOOP *, char *, int, int, int ((CALLBK_FCN_PREFIX *)(Args_mbspool_loop_fcn)) );
ICMO_ExtC DEAL_CLASS * ICMO_DLL_PREFIX icmo_tranche_deal_class( ICMO *, int ) ;
ICMO_ExtC double ICMO_DLL_PREFIX icmo_horizon_return ( ICMO *, ICMO_HORIZON_RETURN_CONTROL *);
ICMO_ExtC double ICMO_DLL_PREFIX icmo_total_return ( ICMO *, int,
           int, double, int, double, int, double, int, double *, double,
           int, int, double *, double *, double *, double * ) ;
ICMO_ExtC double ICMO_DLL_PREFIX icmo_effcoup_calc( ICMO_EFFCOUP *, double, double, int,
                                                    double *, double *, int, int, int ) ;
ICMO_ExtC double ICMO_DLL_PREFIX icmo_yldcrv_yield_at_maturity( ICMO *, double, double * ) ;
ICMO_ExtC int ICMO_DLL_PREFIX icmo_property_to_loan_forecast( ICMO *, POOL_INFO *, PIWORK *, char *, int, double *, char **, char * ) ;
ICMO_ExtC void ICMO_DLL_PREFIX icmo_use_case_sensitive_dir( void ) ;
ICMO_ExtC int ICMO_DLL_PREFIX icmo_pool_is_in_group( ICMO *, POOL_INFO *, int ) ;
ICMO_ExtC int ICMO_DLL_PREFIX icmo_group_is_in_group( ICMO *, int, int ) ;
ICMO_ExtC POOL_INFO ** ICMO_DLL_PREFIX icmo_parent_pips_supported_by_child_pip( ICMO *, POOL_INFO *, int );
ICMO_ExtC int ICMO_DLL_PREFIX icmo_independent_groups( ICMO *, int, int, int ) ;
ICMO_ExtC void ICMO_DLL_PREFIX icmo_free_mbspool_cache( char ** ) ;
ICMO_ExtC TAX_TRANCHE * ICMO_DLL_PREFIX icmo_tranche_taxinfo( ICMO *, int ) ;
ICMO_ExtC int ICMO_DLL_PREFIX icmo_typical_parse_control_fcn( Args_parse_control_fcn );
ICMO_ExtC int ICMO_DLL_PREFIX icmo_typical_parse_control_fcn2( Args_parse_control_fcn );
ICMO_ExtC char * ICMO_DLL_PREFIX icmo_zipcode_to_msa( char *, char *, char *, int, char * ) ;
ICMO_ExtC char * ICMO_DLL_PREFIX icmo_format_region_id( char * ) ;
ICMO_ExtC PORTF * ICMO_DLL_PREFIX icmo_portf_init( PORTFMISC *, char * ) ;
ICMO_ExtC int ICMO_DLL_PREFIX icmo_portf_reset( PORTF *, PORTFMISC * ) ;
ICMO_ExtC PORTF_COMPONENT * ICMO_DLL_PREFIX icmo_portf_accum( PORTF *, ICMO *, double ) ;
ICMO_ExtC int ICMO_DLL_PREFIX icmo_portf_adjust( PORTF *, PORTF_COMPONENT *, double ) ;
ICMO_ExtC int ICMO_DLL_PREFIX icmo_portf_stats( PORTF * ) ;
ICMO_ExtC void ICMO_DLL_PREFIX icmo_portf_free( PORTF ** ) ;
ICMO_ExtC ICMO * ICMO_DLL_PREFIX icmo_portf_set_cfs( YyyyMmDd, int, YyyyMmDd *,
          double *, double *, double *, double *, double, double, char *, char *, void * ) ;
ICMO_ExtC double ICMO_DLL_PREFIX icmo_solver( ICMOSOLVER * );
ICMO_ExtC void ICMO_DLL_PREFIX icmo_validate_tax_tranche( ICMO *, int ) ;
ICMO_ExtC FCN_deal_errfcn * ICMO_DLL_PREFIX icmo_set_deal_errfcn( ICMO*, FCN_deal_errfcn * ) ;
ICMO_ExtC FCN_global_errfcn * ICMO_DLL_PREFIX icmo_set_global_errfcn( FCN_global_errfcn * ) ;
ICMO_ExtC ERRINFO * ICMO_DLL_PREFIX icmo_errinfo( ICMO * );
ICMO_ExtC void ICMO_DLL_PREFIX icmo_raise_errdie( ICMO *, ERRINFO * );
ICMO_ExtC double ICMO_DLL_PREFIX icmo_convert_prep_rate( ICMO *, POOL_INFO *, int, int, double, int ) ;
ICMO_ExtC ICMO_SCRIPT_HANDLE * ICMO_DLL_PREFIX icmo_parse_script( ICMO *, ICMO_SCRIPT * ) ;
ICMO_ExtC int ICMO_DLL_PREFIX icmo_eval_script( ICMO *, ICMO_SCRIPT_HANDLE * );
ICMO_ExtC int ICMO_DLL_PREFIX icmo_set_prepay_script( ICMO *, ICMO_SCRIPT_HANDLE * ) ;
ICMO_ExtC int ICMO_DLL_PREFIX icmo_set_script_retval ( ICMO *, ICMO_SCRIPT_HANDLE *, ICMO_DATAVAL * ) ;
ICMO_ExtC void ICMO_DLL_PREFIX icmo_free_script_handle( ICMO *, ICMO_SCRIPT_HANDLE ** ) ;
ICMO_ExtC ICMO_SCRIPT_HANDLE * ICMO_DLL_PREFIX icmo_get_prepay_script( ICMO *, int );
ICMO_ExtC void ICMO_DLL_PREFIX icmo_set_loandata_forecast( ICMO *, LOANDATA *, int, double *, char  ** );
ICMO_ExtC int  ICMO_DLL_PREFIX icmo_get_loandata_val( ICMO *, LOANDATA *, int, double *, char  ** );
ICMO_ExtC void ICMO_DLL_PREFIX icmo_ovrdset_asset_vect ( ICMO *, POOL_INFO *, int, double *, int ) ;
ICMO_ExtC int  ICMO_DLL_PREFIX icmo_override_asset_write_ccf (ICMO *, ICMO_OVRD_ASSET_CCF_INFO *);
ICMO_ExtC int  ICMO_DLL_PREFIX icmo_override_asset_read_ccf  (ICMO *, ICMO_OVRD_ASSET_CCF_INFO *);
ICMO_ExtC void * ICMO_DLL_PREFIX icmo_get_collat_userdata( ICMO *, POOL_INFO * ) ;
ICMO_ExtC char * ICMO_DLL_PREFIX icmo_get_name( ICMO *, char * ) ;
ICMO_ExtC char * ICMO_DLL_PREFIX icmo_get_loandata_translation( ICMO *, POOL_INFO *, LOANDATA * ) ;
ICMO_ExtC void ICMO_DLL_PREFIX icmo_ppmdl_set_adco_credit_assum( ICMO *, POOL_INFO *, int, int, int, double * ) ;
ICMO_ExtC void ICMO_DLL_PREFIX icmo_ppmdl_set_aft_default_assum( ICMO *, POOL_INFO *, int, int, int, double * ) ;
ICMO_ExtC void ICMO_DLL_PREFIX icmo_worker( ICMO_WORKER_CONTROL * );
ICMO_ExtC int  ICMO_DLL_PREFIX icmo_spstr( ICMO *, ICMOSPSTR * );
INTEX_INTERNAL_USE_ONLY ICMO_ExtC char * ICMO_DLL_PREFIX icmo_dummy_dealname( int ) ;

/* these are old:  use the equivalent icmo_YyyyMmDd_bd_adj above */
ICMO_ExtC YyyyMmDd ICMO_DLL_PREFIX icmo_YyyyMmDd_businessday( ICMO *, YyyyMmDd, int, int ) ;
ICMO_ExtC YyyyMmDd ICMO_DLL_PREFIX icmo_YyyyMmDd_businessday_adj( ICMO *, YyyyMmDd, int, int, int ) ;

/* deprecated - replaced by icmo_eval_sched_cashflows */
DEPRECATED ICMO_ExtC int  ICMO_DLL_PREFIX icmo_eval_ym_formula( ICMO *, POOL_INFO *, int ) ;

#ifndef MS_WINNT
#ifndef MS_WIN16
#define DECLARE_ICMO_ERRDIE   /* may also be declared by compiler flag */
#endif
#endif

#ifdef DECLARE_ICMO_ERRDIE
ICMO_ExtC void icmo_errdie( char * ) ;   /* coded by user application */
#endif

#ifdef MS_WIN16
ICMO_ExtC void ICMO_DLL_PREFIX icmo_register_errdie ( void ( CALLBK_FCN_PREFIX *errdie_fcn)(char *) ) ;
WCMO_ExtC void WCMO_DLL_PREFIX wcmo_open_debug_files ( char *szIn, char *szOut ) ;
WCMO_ExtC void WCMO_DLL_PREFIX wcmo_close_debug_files ( void ) ;
#else
ICMO_ExtC void ICMO_DLL_PREFIX wcmo_open_debug_files ( char *szIn, char *szOut ) ;
ICMO_ExtC void ICMO_DLL_PREFIX wcmo_close_debug_files ( void ) ;
#endif /* MS_WIN16 */

#endif

#endif /* TOWERS_WATSON_USE_DYN_DLL*/

/* YyyyMmDd_to_Yy_Mm:  converts from yyyymmdd to yymm notation */
#define YyyyMmDd_to_YyMm(yyyymmdd)   ( (int)((yyyymmdd / 100) % 10000) )

/* Old business center classification */
#define ICMO_BUSINESSCENTER_NYC         0
#define ICMO_BUSINESSCENTER_LON         1
#define ICMO_BUSINESSCENTER_YEN         2
#define ICMO_BUSINESSCENTER_UNKNOWN     3
#define ICMO_BUSINESSCENTER_MAX         4

/* Subroutines, fields, and flags that have been renamed or superceded */

#define icmomisc_ignore_wala       icmomisc_altercollat.altc_ignore_wala
#define icmomisc_ignore_curpmt     icmomisc_altercollat.altc_ignore_curpmt
#define icmomisc_wala_avg_clamp    icmomisc_altercollat.altc_wala_avg_clamp
#define icmomisc_clear_arm_params  icmomisc_altercollat.altc_clear_arm_params
#define icmomisc_include_ymp       icmomisc_altercollat.altc_include_prepaypenalty
#define altc_include_ymp           altc_include_prepaypenalty
#define icmo_include_ymp           icmo_include_prepaypenalty
#define ICMOINCLYMP_ONLY_LOCKOUT   ICMOPREPAYPENALTY_ONLY_LOCKOUT
#define ICMOINCLYMP_YES            ICMOPREPAYPENALTY_YES
#define ICMOINCLYMP_NONE           ICMOPREPAYPENALTY_NONE
#define ICMOREPCOLL_NCHK           ICMOREPCOLL_NO
#define icmomisc_pars_topdeal_only icmomisc_alteruse.altu_pars_topdeal_only
#define icmomisc_clusters_n_wala       icmomisc_cluster.cluster_nwalas
#define icmomisc_clusters_with_details icmomisc_cluster.cluster_with_details
#define icmomisc_keep_underlying_pass_thru \
                      icmomisc_alteropt.alto_keep_underlying_pass_thru
#define icmomisc_keep_duplicated_reremics \
                      icmomisc_alteropt.alto_keep_duplicated_reremics
#define icmomisc_dont_optimize_rules \
                      icmomisc_alteropt.alto_dont_optimize_rules
#define icmomisc_extensive_error_checking icmomisc_error_checking_level

#define icmo_set_collat_cf  icmo_get_collat_cf
#define icmo_version()    icmo_version_chk(ICMO_VERSION)  /* now checks */
#define icmo_calc_total_return(icmop,trno,n_mos,face_amt,begin_modepy,begin_priceyld, end_modepy,end_priceyld,n_reinv_rates,v_reinv_rates,reinv_spread, loc_int_ret,loc_prin_ret,loc_reinv_ret,loc_mkt_ret,futurep ) \
 icmo_total_return(icmop,trno,n_mos,face_amt,begin_modepy,begin_priceyld,              \
               end_modepy,end_priceyld,n_reinv_rates,v_reinv_rates,reinv_spread,TRUE,  \
               ICMOTOTRET_ANNUAL,loc_int_ret,loc_prin_ret,loc_reinv_ret,loc_mkt_ret)
#define icmo_force_coll_cashflows(icmop,rem_term,vprincipal,vinterest) \
 icmo_override_coll_cf(icmop,rem_term,0,vprincipal,vinterest,          \
               NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL)
#define icmo_force_coll_pcashflows(icmop,rem_term,vschedprincipal,vprepayprincipal,vx1,vinterest,vx2)\
 icmo_override_coll_cf(icmop,rem_term,0,NULL,vinterest,           \
               NULL,NULL,NULL,vschedprincipal,vprepayprincipal,   \
               NULL,NULL,NULL,NULL,NULL,NULL)
#define icmo_replace_coll_list(icmop,anchor_pip)                  \
        icmo_replace_collat_list(icmop,anchor_pip,TRUE,NULL)
#define icmo_set_agg_union_id( icmop,pip,aggunion_id)  \
        icmo_set_aggunion_id(icmop,pip,ICMO_AGG_UNION_FOR_AGGMDR,aggunion_id)
#define icmo_get_agg_union( icmop,aggunion_id)  \
        icmo_get_aggunion(icmop,ICMO_AGG_UNION_FOR_AGGMDR,aggunion_id)
#define icmo_force_pool_cf_fcn       icmo_override_pool_cf_fcn
#define icmo_do_optredeem            icmo_do_optredeems[ICMO_OPTRTYPE_OPTIONAL]
#define icmo_do_optional_redemption  icmo_do_optredeem
#define optr_mandatory               optr_type
#define icmo_dsr                     icmo_make_all_icmot_vects
#define ICMODEAL_SEASONED_GROUPS     ICMODEAL_SEASONED_CLUSTERS
#define ICMODEAL_SEASONED_AGGREGATES ICMODEAL_SEASONED_CLUSTERS
#define ICMOTR_PSEUDO_SENIORSUB      ICMOTR_PSEUDO_CLASS
#define ICMOAGENCY_FHLMCGOLD         ICMOAGENCY_FHLMG
#define ICMOAGENCY_CHS               ICMOAGENCY_CMF
#define ICMOADDLINFO_LOAN_CAN_PIK    ICMOADDLINFO_ASSET_PIK_INFO
#define ICMOADDLINFO_DEAL_DATA_FROM_CHILD        990 /* Deprecated. Use ICMOADDLINFO_DEAL_DATA_FROM_CHILD_DEALS */
#define pi_groupclass     pi_groupno      /* new naming convention */
#define pi_xrs_po         pi_xrs_frac[0]  /* new naming convention */
#define pi_xrs_io         pi_xrs_frac[2]  /* new naming convention */
#define pi_workpad        pi_workp        /* new naming convention */
#define icmo_schedule_dependency icmo_schedule_dependecy  /* misspelled*/
#define ICMOSHIFTINT_REDUCE_NOT_TESTED  2  /* not tested this period */
#define ICMOI_30YR_FNMA ICMOI_CONTRACT
#define ICMOCFTYPE_ARM_FNMA_30YR ICMOCFTYPE_ARM_CONTRACT
#define BLK_DAYCOUNT_DEFAULT             ICMO_DAYCOUNT_DEFAULT
#define BLK_DAYCOUNT_30360               ICMO_DAYCOUNT_30360
#define BLK_DAYCOUNT_ACTUAL360           ICMO_DAYCOUNT_ACTUAL360
#define BLK_DAYCOUNT_ACTUAL365           ICMO_DAYCOUNT_ACTUAL365
#define BLK_DAYCOUNT_ACTUALACTUAL        ICMO_DAYCOUNT_ACTUALACTUAL
#define BLK_DAYCOUNT_30365               ICMO_DAYCOUNT_30365
#define BLK_DAYCOUNT_VECTOR              ICMO_DAYCOUNT_VECTOR
#define BLK_DAYCOUNT_ACTUALACTUAL_B      ICMO_DAYCOUNT_ACTUALACTUAL_B
#define BLK_BUSINESSDAY_DEFAULT          ICMO_BUSINESSDAY_DEFAULT
#define BLK_BUSINESSDAY_NONE             ICMO_BUSINESSDAY_NONE
#define BLK_BUSINESSDAY_FOLLOWING        ICMO_BUSINESSDAY_FOLLOWING
#define BLK_BUSINESSDAY_PRECEDING        ICMO_BUSINESSDAY_PRECEDING
#define BLK_BUSINESSDAY_MFOLLOWING       ICMO_BUSINESSDAY_MFOLLOWING
#define BLK_BUSINESSDAY_EOMFOLLOWING     ICMO_BUSINESSDAY_EOMFOLLOWING
#define BLK_BUSINESSDAY_EOMPRECEDING     ICMO_BUSINESSDAY_EOMPRECEDING
#define BLK_BUSINESSDAY_ABSOLUTE         ICMO_BUSINESSDAY_ABSOLUTE
#define BLK_BUSINESSDAY_OFFSET           ICMO_BUSINESSDAY_OFFSET
#define BLK_BUSINESSDAY_EOMNONE          ICMO_BUSINESSDAY_EOMNONE
#define BLK_BUSINESSDAY_EOMNEXTBDAY      ICMO_BUSINESSDAY_EOMNEXTBDAY
#define BLK_BUSINESSCENTER_NYC           ICMO_BUSINESSCENTER_NYC
#define BLK_BUSINESSCENTER_LON           ICMO_BUSINESSCENTER_LON
#define BLK_BUSINESSCENTER_YEN           ICMO_BUSINESSCENTER_YEN
#define BLK_BUSINESSCENTER_MAX           ICMO_BUSINESSCENTER_MAX
#define ICMODUEBILL_NO                   ICMODUEBILL_0DELAY
#define ICMO_T_IS_MODELING_TRANCHE       ICMO_T_IS_MODELING_EXCHANGE
#define ICMO_T_IS_MODELING_KEYWORD       ICMO_T_IS_MODELING_EXTERNAL
#define ICMODB_CUSIPTBL_CMO      ICMODB_ALTID_TBL_CMOCUSIP
#define ICMODB_CUSIPTBL_MBS      ICMODB_ALTID_TBL_MBSCUSIP
#define ICMODB_CUSIPTBL_BDC      ICMODB_ALTID_TBL_BDCCUSIP
#define ICMODB_CUSIPTBL_ISIN     ICMODB_ALTID_TBL_ISIN
#define ICMODB_CUSIPTBL_BBGID    ICMODB_ALTID_TBL_BBGID
#define ICMODB_CUSIPTBL_USR      ICMODB_ALTID_TBL_USER
#define ICMOIGNORE_BLOCK_ACCUM_INTLOSS   ICMOIGNORE_BLOCK_ACCUM_INTLOSS_START
#define ICMOIGNORE_BLOCK_ACCUM_INTSHORT  ICMOIGNORE_BLOCK_ACCUM_INTSHORT_START
#define ICMOIGNORE_BLOCK_ACCUM_PRINLOSS  ICMOIGNORE_BLOCK_ACCUM_PRINLOSS_START
#define ICMOIGNORE_BLOCK_ACCUM_ALLSHORT  ICMOIGNORE_BLOCK_ACCUM_ALL_START
#define icmo_YyyyMmdd_businessday icmo_YyyyMmDd_businessday
#define icmot_vympremiums            icmot_vprepaypenalty
#define icmot_vcollat_ympremiums     icmot_vympremiums
#define icmo_tranchedist_ympremiums  icmo_tranchedist_prepaypenalty
#define icmo_speed_type              icmo_cfassum.cfa_speed_type
#define icmo_n_speeds                icmo_cfassum.cfa_n_speeds
#define icmo_speed_vect              icmo_cfassum.cfa_vspeeds
#define icmo_speed_fcn               icmo_cfassum.cfa_speed_fcn
#define icmo_index_fcn               icmo_cfassum.cfa_index_fcn
#define icmo_loss_type               icmo_cfassum.cfa_loss_type
#define icmo_loss_n_defaults         icmo_cfassum.cfa_loss_n_defaults
#define icmo_loss_vdefaults          icmo_cfassum.cfa_loss_vdefaults
#define icmo_loss_vdeftypes          icmo_cfassum.cfa_loss_vdeftypes
#define icmo_loss_n_severity         icmo_cfassum.cfa_loss_n_severity
#define icmo_loss_vseverity          icmo_cfassum.cfa_loss_vseverity
#define icmo_loss_recov_lag          icmo_cfassum.cfa_loss_recov_lag
#define icmo_loss_servicer_advances        icmo_cfassum.cfa_loss_servicer_advances
#define icmo_loss_servicer_advance_p_frac  icmo_cfassum.cfa_loss_servicer_advance_p_frac
#define icmo_loss_servicer_advance_i_frac  icmo_cfassum.cfa_loss_servicer_advance_i_frac
#define icmo_loss_unsched_pay_dd           icmo_cfassum.cfa_loss_unsched_pay_dd
#define icmo_loss_balloon_special          icmo_cfassum.cfa_loss_balloon_special
#define icmo_draw_type                     icmo_cfassum.cfa_draw_type
#define icmo_draw_nrates                   icmo_cfassum.cfa_draw_n_rates
#define icmo_draw_vrates                   icmo_cfassum.cfa_draw_vrates
#define icmo_draw_nutilization             icmo_cfassum.cfa_draw_n_utilizations
#define icmo_draw_vutilization             icmo_cfassum.cfa_draw_vutilizations
#define icmo_include_prepaypenalty         icmo_cfassum.cfa_include_prepaypenalty
#define icmo_amortize_as_loan              icmo_cfassum.cfa_prepay_method
#define icmo_use_hist_delinq               icmo_cfassum.cfa_use_hist_delinq
#define icmo_n_delinq_rates                icmo_cfassum.cfa_n_delinq_rates
#define icmo_vdelinq_rates                 icmo_cfassum.cfa_vdelinq_rates
#define icmo_apply_contracted_balloon_extensions \
                                           icmo_cfassum.cfa_apply_contracted_balloon_extensions
#define icmo_balloon_extension             icmo_cfassum.cfa_vballoon_extensions[0]
#define loanattr_balloon_extension         loanattr_vballoon_extensions[0]
#define icmo_YyyyMmDd_diff(a,b,c) \
            icmo_daycount((ICMO *)NULL,BLK_DAYCOUNT_30360,a,b)
#define icmodb_find_first_match( icmodbp, out_icmodbrecp, criteria_str, errbuffp )  \
            ( icmodb_find_init(icmodbp, criteria_str, errbuffp) ? 0 : \
              icmodb_find(icmodbp, out_icmodbrecp) )
#define icmo_addl_info_result              icmo_addl_infop
#define loanattr_1st_accrue_days           loanattr_v_accrue_days[1]
#define icmo_valid_date(YyyyMmDd)          icmo_YyyyMmDd_valid(YyyyMmDd,0)
#define dbs_check_exact_time               dbs_check_time
#define icmo_make_all_icmot_vects          icmo_select_icmot_vect_default
#define icmo_pmt_to_pmt_qa                 icmo_cashflows_force_conv2pmt
#define icmo_price100_use_notional_bal     icmo_py_basis_use_bal
#define bi_couponcap_shorfall_payback      bi_couponcap_shortfall_payback


/*
 *  The following macros should be defined at the compile line.
 *
 *  if ICMO_ALWAYS_USE_OUTSRC is defined, icmo_deal will ALWAYS search for a structured
 *  deal first, then for a CDI if the former fails. icmoouts.h is included.
 *
 *  if ICMO_INCLUDE_OUTSRC_HEADER is defined, icmoouts.h will be included.
 *  the user will have to change their app. to call the
 *  ICMOMISC_SETUP_OUTSRC for every call to icmo_deal where they
 *  want to parse the structured deals.
 *
 *  if neither is defined, the user must explicitly include icmoouts.h and
 *  call the macro ICMOMISC_SETUP_OUTSRC
 *
 */

#ifdef ICMO_ALWAYS_USE_OUTSRC
#define ICMO_INCLUDE_OUTSRC_HEADER
#endif

#ifdef ICMO_INCLUDE_OUTSRC_HEADER
//#include "icmoouts.h" //WTW - Gen2 - Not allowed
#endif


/*
   To change the default requirement of icmo_errdie by user applicaton,
   user application should define USER_ICMO_ERRDIE in one (ONLY one) of
   the user application module C file before include "icmo.h".
   1. USER_ICMO_ERRDIE can be defined with a user defined function name
      to replace icmo_errdie.
   2. USER_ICMO_ERRDIE can be defined with empty body to disable icmo_errdie.
   Some old compiler may not support the macro language used to determine
   if USER_ICMO_ERRDIE is defined with empty body or not. In that case,
   user can define USER_ICMO_ERRDIE__empty as 0 or 1 to skip the macro language
   portion that is used to determine if USER_ICMO_ERRDIE is defined
   with empty body or not.
*/

#ifdef USER_ICMO_ERRDIE
#ifndef USER_ICMO_ERRDIE__empty
/* check to see if USER_ICMO_ERRDIE is defined as empty or as icmo_errdie */
#define USER_ICMO_ERRDIE_empty_TRUE    1
#define USER_ICMO_ERRDIE_empty(a)      USER_ICMO_ERRDIE_empty_TRUE ## a
#define USER_ICMO_ERRDIE_empty_chk(a)  USER_ICMO_ERRDIE_empty(a+0)
#if USER_ICMO_ERRDIE_empty_chk(USER_ICMO_ERRDIE)
#define USER_ICMO_ERRDIE__empty        1
#define USER_ICMO_ERRDIE__icmo_errdie  0
#else
#define USER_ICMO_ERRDIE__empty        0
#define icmo_errdie
#if USER_ICMO_ERRDIE_empty_chk(USER_ICMO_ERRDIE)
#define USER_ICMO_ERRDIE__icmo_errdie  1
#else
#define USER_ICMO_ERRDIE__icmo_errdie  0
#endif
#undef icmo_errdie
#endif
#undef USER_ICMO_ERRDIE_empty_TRUE
#undef USER_ICMO_ERRDIE_empty
#undef USER_ICMO_ERRDIE_empty_chk
#else
/* user want to skip the checking on USER_ICMO_ERRDIE */
#define USER_ICMO_ERRDIE__icmo_errdie  0
#endif /* done checking on USER_ICMO_ERRDIE */
#if (! USER_ICMO_ERRDIE__icmo_errdie)
/* create icmo_errdie here to satisfy linker */
#ifdef ICMO_NO_ANSI_PROTOTYPING
#if (! USER_ICMO_ERRDIE__empty)
void USER_ICMO_ERRDIE();
#endif
void icmo_errdie(msg) char *msg;
#else
#if (! USER_ICMO_ERRDIE__empty)
ICMO_ExtC void USER_ICMO_ERRDIE(char *);
#endif
ICMO_ExtC void icmo_errdie(char *msg)
#endif
{
#if (! USER_ICMO_ERRDIE__empty)
#define icmo_errdie USER_ICMO_ERRDIE_can_not_be_icmo_errdie
USER_ICMO_ERRDIE(msg);
#undef icmo_errdie
#endif
}
#endif
#endif

#define ICMO_STRUCT_DEFINED   /* flag verifies that icmo.h is included */
#endif
// end of icmo.h

#ifdef TOWERS_WATSON_USE_DLL
  #ifdef TOWERS_WATSON_USE_DYN_DLL
    #define INTEX_DECL __cdecl
//    #define INTEX_DECL __syscall
//    #define INTEX_DECL __stdcall
    #define INTEX_CALLBACK_DECL CALLBK_FCN_PREFIX
  #else //!TOWERS_WATSON_USE_DYN_DLL
    #define INTEX_DECL __cdecl
    // for Wattest.lib, do not use cdecl
    #define INTEX_CALLBACK_DECL __cdecl
  #endif
#else
  #define INTEX_DECL
#endif

#ifdef ALLOCATE_INTEX
#define INTEX_PREFIX
#define INTEX_DEFPREFIX(a,b) a=b
#else /* Else, if not allocating */
#define INTEX_PREFIX extern
#define INTEX_DEFPREFIX(a,b) extern a
#endif /* end if */

#if defined( TOWERS_WATSON_USE_DYN_DLL)

  //create typedefs
  typedef void INTEX_DECL icmo_init_func();
  typedef void INTEX_DECL icmo_finalize_func();
  typedef void INTEX_DECL icmo_initialized_func();
  typedef void INTEX_DECL icmo_finalized_func();
  typedef int INTEX_DECL icmo_env_set_attr_func( ICMOENVKEY, int, char * );
  typedef int INTEX_DECL icmo_env_get_attr_func( ICMOENVKEY, int *, char * );
  typedef int INTEX_DECL icmo_mpi_message_set_func(char *,  void *);
  typedef int INTEX_DECL icmo_mpi_message_get_func(char **, void *);
  typedef ICMOMISC * INTEX_DECL icmo_setup_icmomiscp_func( ICMOMISC *, int ) ;
  typedef ICMO * INTEX_DECL icmo_deal_func( ICMOMISC *, char *, char *, int,
       YyyyMmDd, int, int, double *, int * ) ;
  typedef void   INTEX_DECL icmo_free_func( ICMO ** ) ;
  typedef ICMO * INTEX_DECL icmo_parse_func( char *, char *, int, int, int, double *, int * ) ;
  typedef void   INTEX_DECL icmo_index_set_func( ICMO *, int, int, double * ) ;
  typedef void   INTEX_DECL icmo_set_index_forecast_func( ICMO *, int );
  typedef void * INTEX_DECL icmo_make_struct_func(ICMO *, int, const char *, char ** ) ;
  typedef int    INTEX_DECL icmo_free_struct_func(ICMO *, int, void **);
  typedef void   INTEX_DECL icmo_currency_set_func( ICMO *, ICMO_CURRENCY *, ICMO_CURRENCY *,
							                            int, YyyyMmDd *, double * ) ;
  typedef void   INTEX_DECL icmo_cashflows_func( ICMO *, YyyyMmDd, int, int, double *,
       void ((CALLBK_FCN_PREFIX *)(Args_speed_fcn)),
       void ((CALLBK_FCN_PREFIX *)(Args_index_fcn)), int, char *);
  typedef int    INTEX_DECL icmo_tranchenum_func( ICMO *, const char * ) ;
  typedef int    INTEX_DECL icmo_stats_func( ICMO *, int, double, int, double ) ;
  typedef YyyyMmDd INTEX_DECL icmo_month2date_func( ICMO *, int ) ;
  typedef int    INTEX_DECL icmo_date2month_func( ICMO *, YyyyMmDd ) ;
  typedef char * INTEX_DECL icmo_fmtdate_func( ICMO *, int, int ) ;
  typedef YyyyMmDd INTEX_DECL icmo_tr_month2date_func( ICMO *, int, int ) ;
  typedef int    INTEX_DECL icmo_tr_date2month_func( ICMO *, int, YyyyMmDd ) ;
  typedef char * INTEX_DECL icmo_tr_fmtdate_func( ICMO *, int, int, int ) ;
  typedef char * INTEX_DECL icmo_fmtprice_func( ICMO *, double, int ) ;
  typedef void   INTEX_DECL icmo_get_collat_cf_func( ICMO *,
       void ((CALLBK_FCN_PREFIX*)(Args_pool_cf_fcn)),
       void ((CALLBK_FCN_PREFIX*)(Args_pool_cf_fcn)) ) ;
  typedef void   INTEX_DECL icmo_set_pmt_to_pmt_mode_func( ICMO *, YyyyMmDd,
       double ((CALLBK_FCN_PREFIX*)(Args_1speed_fcn)), double ((CALLBK_FCN_PREFIX*)(Args_1index_fcn)),
       int, char * ) ;
  typedef int    INTEX_DECL icmo_pay_1period_func( ICMO *, int,
       double *, double *, double *, double * ) ;
  typedef double INTEX_DECL icmo_pay_1period_info_func( ICMO *, char * ) ;
  typedef void INTEX_DECL icmo_buy_collat_func(ICMO *, RBC_INFO *, int, int, double ) ;
  typedef void INTEX_DECL icmo_sell_collat_func(ICMO *, RBC_INFO *, int, double, double );
  typedef void   INTEX_DECL icmo_replace_collat_list_func( ICMO *, POOL_INFO *, int, char * ) ;
  typedef int    INTEX_DECL icmo_apply_collat_transact_set_func(ICMO *, char *, char *, int, int, char *) ;
  typedef void   INTEX_DECL icmo_decluster_pools_func( ICMO * ) ;
  typedef void   INTEX_DECL icmo_cluster_pools_func( ICMO *, int ) ;
  typedef void   INTEX_DECL icmo_override_coll_cf_func( ICMO *, int, int, double *, double *,
       double *, double *, double *, double *, double *, double *, double *,
       IOVERRIDEMISC *, double *, double *, double * ) ;
  typedef double INTEX_DECL icmo_convert_prepay_units_func( int, double, int ) ;
  typedef double INTEX_DECL icmo_convert_yield_units_func( int, double, int, int ) ;
  typedef int    INTEX_DECL icmo_set_aggunion_id_func( ICMO *, POOL_INFO *, int ) ;
  typedef ICMO_AGG_UNION * INTEX_DECL icmo_get_aggunion_func( ICMO *, int, int ) ;

//  #ifndef MS_WINNT
//  #define mbs__eqcpr   icmo_convert_prepay_units
//  #define mbs__eqyield icmo_convert_yield_units
//  #endif

  typedef ABS_SUMMARY_INFO * INTEX_DECL icmo_find_abs_summary_info_func( ICMO *, ABS_SUMMARY_INFO *, int, int, int ) ;
  typedef int INTEX_DECL icmo_disc_margin_over_which_index_func( ICMO *, int ) ;
  typedef char * INTEX_DECL icmo_version_chk_func( const char * ) ;
  typedef char * INTEX_DECL icmo_version_validate_func( const char *, char *, int *, char * ) ;
  typedef int    INTEX_DECL icmo_schedule_met_func( ICMO *, int ) ;
  typedef int    INTEX_DECL icmo_get_schedule_func( ICMO *, char *,
                                          int *, YyyyMmDd **, double ** ) ;
  typedef int    INTEX_DECL icmo_schedule_dependecy_func( ICMO *, int ) ;
  typedef int    INTEX_DECL icmo_effective_collars_func( ICMO *, int, int, double *, double * ) ;
  typedef void   INTEX_DECL icmo_forward_cashflows_func( ICMO *, int, int ) ;
  typedef int    INTEX_DECL icmo_forward_settle_date_func( ICMO *, int, YyyyMmDd, int ) ;
  typedef void   INTEX_DECL icmo_reinv_cashflows_func( ICMO *, int, int, int,
       double *, double, double *, double * ) ;
  typedef void   INTEX_DECL icmo_use_bv_coll_func( ICMO *, int ) ;
  typedef int    INTEX_DECL icmo_eval_sched_cashflows_func( ICMO *, POOL_INFO *, int, int, int ) ;
  typedef int    INTEX_DECL icmo_collat_type_func( ICMO * ) ;
  typedef BLOCK_INFO * INTEX_DECL icmo_tranche_blocks_func( ICMO *, int ) ;
  typedef char * INTEX_DECL icmo_pmt_to_pmt_freeze_func( ICMO * ) ;
  typedef void   INTEX_DECL icmo_pmt_to_pmt_refreeze_func( ICMO *, char * ) ;
  typedef void   INTEX_DECL icmo_pmt_to_pmt_thaw_func( ICMO *, char * ) ;
  typedef void   INTEX_DECL icmo_pmt_to_pmt_toss_func( char ** ) ;
  typedef int    INTEX_DECL icmo_scenario_vect_func( ICMO *, char *, int, double * ) ;
  typedef void   INTEX_DECL icmo_show_clock_func( ICMO * ) ;
  typedef int    INTEX_DECL icmo_count_npools_func( ICMO *,
                    void ((CALLBK_FCN_PREFIX*)(Args_count_npools_fcn)) ) ;
  typedef ICMO_CURRENCY * INTEX_DECL  icmo_get_currency_func( ICMO *, char * ) ;
  typedef int    INTEX_DECL icmo_addl_info_func( ICMO *, int, int );
  typedef void    INTEX_DECL icmo_setup_commercialop_by_id_func( ICMO *, char **, int ) ;
  typedef void   INTEX_DECL icmo_adjust_arm_index_func( ICMO *, int , double * ) ;

  typedef YyyyMmDd INTEX_DECL icmo_YyyyMmDd_add_func( YyyyMmDd, int, int ) ;
  typedef YyyyMmDd INTEX_DECL icmo_YyyyMmDd_addmo_func( YyyyMmDd, int, int ) ;
  typedef int      INTEX_DECL icmo_YyyyMmDd_diffmo_func( YyyyMmDd, YyyyMmDd ) ;
  typedef YyyyMmDd INTEX_DECL icmo_YyyyMmDd_ddset_func( YyyyMmDd, int ) ;
  typedef int      INTEX_DECL icmo_YyyyMmDd_day_func( YyyyMmDd ) ;
  typedef int      INTEX_DECL icmo_YyyyMmDd_valid_func( YyyyMmDd, int ) ;
  typedef YyyyMmDd INTEX_DECL icmo_YyyyMmDd_today_func( void ) ;
  typedef char *   INTEX_DECL icmo_YyyyMmDd_fmt_func( char *, YyyyMmDd, int ) ;
  typedef int      INTEX_DECL icmo_YyyyMmDd_conv_to_yymm_func( YyyyMmDd ) ;
  typedef YyyyMmDd INTEX_DECL icmo_YyyyMmDd_conv_from_yymm_func( int ) ;
  typedef YyyyMmDd INTEX_DECL icmo_YyyyMmDd_conv_from_y_m_d_func( int, int, int ) ;
  typedef YyyyMmDd INTEX_DECL icmoutil_YyyyMmDd_bd_adj_func( YyyyMmDd, int, int, char *, char *);
  typedef YyyyMmDd INTEX_DECL icmo_YyyyMmDd_bd_adj_func(ICMO *, YyyyMmDd, int, int, char *);
  typedef char *   INTEX_DECL icmo_YyyyMmDd_seqno_func( YyyyMmDd, char * ) ;
  typedef YyyyMmDd INTEX_DECL icmo_date_convert_func( ICMO *, int, YyyyMmDd, ICMO *, char * ) ;
  typedef int      INTEX_DECL icmo_daycount_func( ICMO *, int, YyyyMmDd, YyyyMmDd ) ;
  typedef double   INTEX_DECL icmo_YyyyMmDd_year_frac_func( ICMO *, YyyyMmDd, YyyyMmDd, int, int, int, char *, int, int ) ;

  typedef ICMODB * INTEX_DECL icmodb_init_func( char *, int, int ) ;
  typedef int    INTEX_DECL icmodb_setup_cusip_tbls_func( ICMODB *, int, int *, char ** );
  typedef int    INTEX_DECL icmodb_setup_altid_tbls_func( ICMODB *, int, int *, char ** );
  typedef int    INTEX_DECL icmodb_cusip_to_bond_func( ICMODB *, char *, char *, char * ) ;
  typedef int    INTEX_DECL icmodb_altid_search_func( ICMODB *, char *, int, char *, char * ) ;
  typedef int    INTEX_DECL icmodb_dealstr_to_bond_func( ICMODB *, char *, char *, char *, char * ) ;
  typedef int    INTEX_DECL icmodb_bond_info_func( ICMODB *, char *, char *, char *, ICMODBREC * ) ;
  typedef int    INTEX_DECL icmodb_find_init_func( ICMODB *, char *, char * ) ;
  typedef int    INTEX_DECL icmodb_find_func( ICMODB *, ICMODBREC * ) ;
  typedef void   INTEX_DECL icmodbrec_datahist_clean_func( ICMODBREC_DATAHIST * ) ;
  typedef void   INTEX_DECL icmodb_free_func( ICMODB ** ) ;
  typedef int    INTEX_DECL icmo_dbstatus_func( char *, char *, int, int ) ;
  typedef ICMODBSTAT * INTEX_DECL icmo_dbstat_init_func( char *, char *, int ) ;
  typedef int    INTEX_DECL icmo_dbstat_check_func( ICMODBSTAT * ) ;
  typedef void   INTEX_DECL icmo_dbstat_free_func( ICMODBSTAT ** ) ;
  typedef int INTEX_DECL icmo_isr_play_func( char *,
     int ((CALLBK_FCN_PREFIX *isr_play_control_fcn)(Args_isr_play_control_fcn)), char *) ;

  typedef int    INTEX_DECL icmo_parser_open_func( ICMO *, char *, int,
                int ((CALLBK_FCN_PREFIX*)(Args_parserr_fcn)) ) ;
  typedef void * INTEX_DECL icmo_parser_func( ICMO * , int , char ** , char * ) ;
  typedef int    INTEX_DECL icmo_parser_fseek_func( ICMO *icmop, int ith_pfile, long int fseek_loc ) ;
  typedef int    INTEX_DECL icmo_parser_close_func( ICMO *, int ) ;
  typedef char * INTEX_DECL icmo_alter_cdu_func( ICMO *, char *, char * ) ;
  typedef char * INTEX_DECL icmo_forecast_cdu_func( ICMO *, char *, YyyyMmDd );
  typedef ICMO * INTEX_DECL icmo_find_topmost_icmop_func( ICMO * ) ;
  typedef char * INTEX_DECL icmo_tr_used_cusip_func( ICMO *, int ) ;
  typedef char * INTEX_DECL icmo_index_name_func( ICMO *, int, int ) ;
  typedef double INTEX_DECL icmo_get_idx_val_func( ICMO *, int, char *,
                                                       YyyyMmDd, int ) ;
  typedef int    INTEX_DECL icmo_open_log_func( ICMO * , char * , int, double, int, int, void * ) ;
  typedef void   INTEX_DECL icmo_close_log_func( ICMO * ) ;
  typedef void   INTEX_DECL cmo_talk_a_lot_func( char *, int, int, YyyyMmDd, YyyyMmDd ) ;
  typedef int    INTEX_DECL icmo_deal_has_no_sched_dependency_func( ICMO * ) ;
  typedef int    INTEX_DECL icmo_deal_effective_collars_func( ICMO *,
               int, int, double, double, int, void *, double *, double * ) ;
  typedef double INTEX_DECL icmo_prepay_speed_func( ICMO *, int, int, POOL_INFO * );
  typedef double INTEX_DECL icmo_get_orig_notional_bal_func( ICMO *, int ) ;
  typedef long   INTEX_DECL icmo_run_mbspool_loop_func( ICMOMBSLOOP *, char *, int, YyyyMmDd, int ((CALLBK_FCN_PREFIX *)(Args_mbspool_loop_fcn)) );
  typedef long   INTEX_DECL icmo_mbspool_loop_func( ICMOMBSLOOP *, char *, int, int, int ((CALLBK_FCN_PREFIX *)(Args_mbspool_loop_fcn)) );
  typedef DEAL_CLASS * INTEX_DECL  icmo_tranche_deal_class_func( ICMO *, int ) ;
  typedef double INTEX_DECL icmo_horizon_return_func( ICMO *, ICMO_HORIZON_RETURN_CONTROL *) ;
  typedef double INTEX_DECL icmo_total_return_func( ICMO *, int,
               int, double, int, double, int, double, int, double *, double,
               int, int, double *, double *, double *, double * ) ;
  typedef double INTEX_DECL icmo_effcoup_calc_func( ICMO_EFFCOUP *, double, double, int,
                                                    double *, double *, int, int, int ) ;
  typedef double INTEX_DECL icmo_yldcrv_yield_at_maturity_func( ICMO *, double, double * ) ;
  typedef int INTEX_DECL icmo_property_to_loan_forecast_func( ICMO *, POOL_INFO *, PIWORK *, char *, int, double *, char **, char * ) ;
  typedef void INTEX_DECL icmo_use_case_sensitive_dir_func( void ) ;
  typedef int INTEX_DECL icmo_pool_is_in_group_func( ICMO *, POOL_INFO *, int ) ;
  typedef int INTEX_DECL icmo_group_is_in_group_func( ICMO *, int, int ) ;
  typedef POOL_INFO ** INTEX_DECL icmo_parent_pips_supported_by_child_pip_func( ICMO *, POOL_INFO *, int );
  typedef int INTEX_DECL icmo_independent_groups_func( ICMO *, int, int, int ) ;
  typedef void INTEX_DECL icmo_free_mbspool_cache_func( char ** ) ;
  typedef TAX_TRANCHE * INTEX_DECL icmo_tranche_taxinfo_func( ICMO *, int ) ;
  typedef int INTEX_DECL icmo_typical_parse_control_fcn_func( Args_parse_control_fcn );
  typedef int INTEX_DECL icmo_typical_parse_control_fcn2_func( Args_parse_control_fcn );
  typedef char * INTEX_DECL icmo_zipcode_to_msa_func( char *, char *, char *, int, char * ) ;
  typedef char * INTEX_DECL icmo_format_region_id_func( char * ) ;
  typedef PORTF * INTEX_DECL icmo_portf_init_func( PORTFMISC *, char * ) ;
  typedef int INTEX_DECL icmo_portf_reset_func( PORTF *, PORTFMISC * ) ;
  typedef PORTF_COMPONENT * INTEX_DECL icmo_portf_accum_func( PORTF *, ICMO *, double ) ;
  typedef int INTEX_DECL icmo_portf_adjust_func( PORTF *, PORTF_COMPONENT *, double ) ;
  typedef int INTEX_DECL icmo_portf_stats_func( PORTF * ) ;
  typedef void INTEX_DECL icmo_portf_free_func( PORTF ** ) ;
  typedef ICMO* INTEX_DECL icmo_portf_set_cfs_func( YyyyMmDd, int, YyyyMmDd *,
          double *, double *, double *, double *, double, double, char *, char *, void * ) ;
  typedef double INTEX_DECL icmo_solver_func( ICMOSOLVER * );
  typedef void INTEX_DECL icmo_validate_tax_tranche_func( ICMO *, int ) ;
  typedef FCN_deal_errfcn * INTEX_DECL icmo_set_deal_errfcn_func(ICMO*, FCN_deal_errfcn * ) ;
  typedef FCN_global_errfcn * INTEX_DECL icmo_set_global_errfcn_func(FCN_global_errfcn * ) ;
  typedef ERRINFO * INTEX_DECL icmo_errinfo_func( ICMO * );
  typedef void * INTEX_DECL icmo_raise_errdie_func( ICMO *, ERRINFO * );
  typedef double INTEX_DECL icmo_convert_prep_rate_func( ICMO *, POOL_INFO *, int, int, double, int ) ;
  typedef ICMO_SCRIPT_HANDLE * INTEX_DECL icmo_parse_script_func( ICMO *, ICMO_SCRIPT * ) ;
  typedef int INTEX_DECL icmo_eval_script_func( ICMO *, ICMO_SCRIPT_HANDLE *, void * ) ;
  typedef int INTEX_DECL icmo_set_prepay_script_func( ICMO *, ICMO_SCRIPT_HANDLE * ) ;
  typedef int INTEX_DECL icmo_set_script_retval_func( ICMO *, ICMO_SCRIPT_HANDLE *, ICMO_DATAVAL * ) ;
  typedef void INTEX_DECL icmo_free_script_handle_func( ICMO *, ICMO_SCRIPT_HANDLE ** ) ;
  typedef ICMO_SCRIPT_HANDLE * INTEX_DECL icmo_get_prepay_script_func( ICMO *, int ) ;
  typedef void INTEX_DECL icmo_set_loandata_forecast_func( ICMO *, LOANDATA *, int, double *, char  ** );
  typedef int INTEX_DECL icmo_get_loandata_val_func( ICMO *, LOANDATA *, int, double *, char  ** );
  typedef void INTEX_DECL icmo_ovrdset_asset_vect_func( ICMO *, POOL_INFO *, int, double *, int ) ;
  typedef int  INTEX_DECL icmo_override_asset_write_ccf_func(ICMO *, ICMO_OVRD_ASSET_CCF_INFO *);
  typedef int  INTEX_DECL icmo_override_asset_read_ccf_func(ICMO *, ICMO_OVRD_ASSET_CCF_INFO *);
  typedef void * INTEX_DECL icmo_get_collat_userdata_func( ICMO *, POOL_INFO * );
  typedef char * INTEX_DECL icmo_get_name_func( ICMO *, char * ) ;
  typedef char * INTEX_DECL icmo_get_loandata_translation_func( ICMO *, POOL_INFO *, LOANDATA * );
  typedef void INTEX_DECL icmo_ppmdl_set_adco_credit_assum_func( ICMO *, POOL_INFO *, int, int, int, double * ) ;
  typedef void INTEX_DECL icmo_ppmdl_set_aft_default_assum_func( ICMO *, POOL_INFO *, int, int, int, double * ) ;
  typedef void INTEX_DECL icmo_worker_func( ICMO_WORKER_CONTROL * );
  typedef int  INTEX_DECL icmo_spstr_func( ICMO *, ICMOSPSTR * );
  typedef char * INTEX_DECL icmo_dummy_dealname_func( int ) ;

  /* for errdie function */
  typedef void INTEX_DECL icmo_libinit_func( void (pFunc)(char *errmsg) ) ;

  /* these are old:  use the equivalent icmo_YyyyMmDd_bd_adj above */
  typedef YyyyMmDd INTEX_DECL icmo_YyyyMmDd_businessday_func( ICMO *, YyyyMmDd, int, int ) ;
  typedef YyyyMmDd INTEX_DECL icmo_YyyyMmDd_businessday_adj_func( ICMO *, YyyyMmDd, int, int, int ) ;

  /* deprecated - replaced by icmo_eval_sched_cashflows */
  typedef int INTEX_DECL icmo_eval_ym_formula_func( ICMO *, POOL_INFO *, int ) ;

  //fixup function pointers
  INTEX_PREFIX icmo_init_func * icmo_init;
  INTEX_PREFIX icmo_finalize_func * icmo_finalize;
  INTEX_PREFIX icmo_initialized_func * icmo_initialized;	
  INTEX_PREFIX icmo_finalized_func * icmo_finalized;	
  INTEX_PREFIX icmo_env_set_attr_func * icmo_env_set_attr;
  INTEX_PREFIX icmo_env_get_attr_func * icmo_env_get_attr;
  INTEX_PREFIX icmo_mpi_message_set_func * icmo_mpi_message_set;
  INTEX_PREFIX icmo_mpi_message_get_func * icmo_mpi_message_get;
  INTEX_PREFIX icmo_setup_icmomiscp_func * icmo_setup_icmomiscp;
  INTEX_PREFIX icmo_deal_func * icmo_deal;
  INTEX_PREFIX icmo_free_func * icmo_free;
  INTEX_PREFIX icmo_parse_func * icmo_parse;
  INTEX_PREFIX icmo_index_set_func * icmo_index_set;
  INTEX_PREFIX icmo_set_index_forecast_func * icmo_set_index_forecast;
  INTEX_PREFIX icmo_make_struct_func * icmo_make_struct;
  INTEX_PREFIX icmo_free_struct_func * icmo_free_struct;
  INTEX_PREFIX icmo_currency_set_func * icmo_currency_set;
  INTEX_PREFIX icmo_cashflows_func * icmo_cashflows;
  INTEX_PREFIX icmo_tranchenum_func * icmo_tranchenum;
  INTEX_PREFIX icmo_stats_func * icmo_stats;
  INTEX_PREFIX icmo_month2date_func * icmo_month2date;
  INTEX_PREFIX icmo_date2month_func * icmo_date2month;
  INTEX_PREFIX icmo_fmtdate_func * icmo_fmtdate;
  INTEX_PREFIX icmo_tr_month2date_func * icmo_tr_month2date;
  INTEX_PREFIX icmo_tr_date2month_func * icmo_tr_date2month;
  INTEX_PREFIX icmo_tr_fmtdate_func * icmo_tr_fmtdate;
  INTEX_PREFIX icmo_fmtprice_func * icmo_fmtprice;
  INTEX_PREFIX icmo_get_collat_cf_func * icmo_get_collat_cf;
  INTEX_PREFIX icmo_set_pmt_to_pmt_mode_func * icmo_set_pmt_to_pmt_mode;
  INTEX_PREFIX icmo_pay_1period_func * icmo_pay_1period;
  INTEX_PREFIX icmo_pay_1period_info_func * icmo_pay_1period_info;
  INTEX_PREFIX icmo_buy_collat_func * icmo_buy_collat;
  INTEX_PREFIX icmo_sell_collat_func * icmo_sell_collat;
  INTEX_PREFIX icmo_replace_collat_list_func * icmo_replace_collat_list;
  INTEX_PREFIX icmo_apply_collat_transact_set_func * icmo_apply_collat_transact_set;
  INTEX_PREFIX icmo_decluster_pools_func * icmo_decluster_pools;
  INTEX_PREFIX icmo_cluster_pools_func * icmo_cluster_pools;
  INTEX_PREFIX icmo_override_coll_cf_func * icmo_override_coll_cf;
  INTEX_PREFIX icmo_convert_prepay_units_func * icmo_convert_prepay_units;
  INTEX_PREFIX icmo_convert_yield_units_func * icmo_convert_yield_units;
  INTEX_PREFIX icmo_set_aggunion_id_func * icmo_set_aggunion_id;
  INTEX_PREFIX icmo_get_aggunion_func * icmo_get_aggunion;

  #ifndef MS_WINNT
  #define mbs__eqcpr   icmo_convert_prepay_units
  #define mbs__eqyield icmo_convert_yield_units
  #endif

  INTEX_PREFIX icmo_find_abs_summary_info_func * icmo_find_abs_summary_info;
  INTEX_PREFIX icmo_disc_margin_over_which_index_func * icmo_disc_margin_over_which_index;
  INTEX_PREFIX icmo_version_chk_func * icmo_version_chk;
  INTEX_PREFIX icmo_version_validate_func * icmo_version_validate;
  INTEX_PREFIX icmo_schedule_met_func * icmo_schedule_met;
  INTEX_PREFIX icmo_get_schedule_func * icmo_get_schedule;
  INTEX_PREFIX icmo_schedule_dependecy_func * icmo_schedule_dependecy;
  INTEX_PREFIX icmo_effective_collars_func * icmo_effective_collars;
  INTEX_PREFIX icmo_forward_cashflows_func * icmo_forward_cashflows;
  INTEX_PREFIX icmo_forward_settle_date_func * icmo_forward_settle_date;
  INTEX_PREFIX icmo_reinv_cashflows_func * icmo_reinv_cashflows;
  INTEX_PREFIX icmo_use_bv_coll_func * icmo_use_bv_coll;
  INTEX_PREFIX icmo_collat_type_func * icmo_collat_type;
  INTEX_PREFIX icmo_tranche_blocks_func * icmo_tranche_blocks;
  INTEX_PREFIX icmo_pmt_to_pmt_freeze_func * icmo_pmt_to_pmt_freeze;
  INTEX_PREFIX icmo_pmt_to_pmt_refreeze_func * icmo_pmt_to_pmt_refreeze;
  INTEX_PREFIX icmo_pmt_to_pmt_thaw_func * icmo_pmt_to_pmt_thaw;
  INTEX_PREFIX icmo_pmt_to_pmt_toss_func * icmo_pmt_to_pmt_toss;
  INTEX_PREFIX icmo_scenario_vect_func * icmo_scenario_vect;
  INTEX_PREFIX icmo_show_clock_func * icmo_show_clock;
  INTEX_PREFIX icmo_count_npools_func * icmo_count_npools;
  INTEX_PREFIX icmo_get_currency_func * icmo_get_currency;
  INTEX_PREFIX icmo_addl_info_func * icmo_addl_info;
  INTEX_PREFIX icmo_setup_commercialop_by_id_func * icmo_setup_commercialop_by_id;
  INTEX_PREFIX icmo_adjust_arm_index_func * icmo_adjust_arm_index;

  INTEX_PREFIX icmo_YyyyMmDd_add_func * icmo_YyyyMmDd_add;
  INTEX_PREFIX icmo_YyyyMmDd_addmo_func * icmo_YyyyMmDd_addmo;
  INTEX_PREFIX icmo_YyyyMmDd_diffmo_func * icmo_YyyyMmDd_diffmo;
  INTEX_PREFIX icmo_YyyyMmDd_ddset_func * icmo_YyyyMmDd_ddset;
  INTEX_PREFIX icmo_YyyyMmDd_day_func * icmo_YyyyMmDd_day;
  INTEX_PREFIX icmo_YyyyMmDd_valid_func * icmo_YyyyMmDd_valid;
  INTEX_PREFIX icmo_YyyyMmDd_today_func * icmo_YyyyMmDd_today;
  INTEX_PREFIX icmo_YyyyMmDd_fmt_func * icmo_YyyyMmDd_fmt;
  INTEX_PREFIX icmo_YyyyMmDd_conv_to_yymm_func * icmo_YyyyMmDd_conv_to_yymm;
  INTEX_PREFIX icmo_YyyyMmDd_conv_from_yymm_func * icmo_YyyyMmDd_conv_from_yymm;
  INTEX_PREFIX icmo_YyyyMmDd_conv_from_y_m_d_func * icmo_YyyyMmDd_conv_from_y_m_d;
  INTEX_PREFIX icmoutil_YyyyMmDd_bd_adj_func * icmoutil_YyyyMmDd_bd_adj;
  INTEX_PREFIX icmo_YyyyMmDd_bd_adj_func * icmo_YyyyMmDd_bd_adj;
  INTEX_PREFIX icmo_YyyyMmDd_seqno_func * icmo_YyyyMmDd_seqno;
  INTEX_PREFIX icmo_date_convert_func * icmo_date_convert;
  INTEX_PREFIX icmo_daycount_func * icmo_daycount;
  INTEX_PREFIX icmo_YyyyMmDd_year_frac_func * icmo_YyyyMmDd_year_frac;

  INTEX_PREFIX icmodb_init_func * icmodb_init;
  INTEX_PREFIX icmodb_setup_cusip_tbls_func * icmodb_setup_cusip_tbls;
  INTEX_PREFIX icmodb_setup_altid_tbls_func * icmodb_setup_altid_tbls;
  INTEX_PREFIX icmodb_cusip_to_bond_func * icmodb_cusip_to_bond;
  INTEX_PREFIX icmodb_altid_search_func * icmodb_altid_search;
  INTEX_PREFIX icmodb_dealstr_to_bond_func * icmodb_dealstr_to_bond;
  INTEX_PREFIX icmodb_bond_info_func * icmodb_bond_info;
  INTEX_PREFIX icmodb_find_init_func * icmodb_find_init;
  INTEX_PREFIX icmodb_find_func * icmodb_find;
  INTEX_PREFIX icmodbrec_datahist_clean_func * icmodbrec_datahist_clean;
  INTEX_PREFIX icmodb_free_func * icmodb_free;
  INTEX_PREFIX icmo_dbstatus_func * icmo_dbstatus;
  INTEX_PREFIX icmo_dbstat_init_func * icmo_dbstat_init;
  INTEX_PREFIX icmo_dbstat_check_func * icmo_dbstat_check;
  INTEX_PREFIX icmo_dbstat_free_func * icmo_dbstat_free;
  INTEX_PREFIX icmo_isr_play_func * icmo_isr_play;

  INTEX_PREFIX icmo_parser_open_func * icmo_parser_open;
  INTEX_PREFIX icmo_parser_func * icmo_parser;
  INTEX_PREFIX icmo_parser_fseek_func * icmo_parser_fseek;
  INTEX_PREFIX icmo_parser_close_func * icmo_parser_close;
  INTEX_PREFIX icmo_alter_cdu_func * icmo_alter_cdu;
  INTEX_PREFIX icmo_forecast_cdu_func * icmo_forecast_cdu;
  INTEX_PREFIX icmo_find_topmost_icmop_func * icmo_find_topmost_icmop;
  INTEX_PREFIX icmo_tr_used_cusip_func * icmo_tr_used_cusip;
  INTEX_PREFIX icmo_index_name_func * icmo_index_name;
  INTEX_PREFIX icmo_get_idx_val_func * icmo_get_idx_val;
  INTEX_PREFIX icmo_open_log_func * icmo_open_log;
  INTEX_PREFIX icmo_close_log_func * icmo_close_log;
  INTEX_PREFIX cmo_talk_a_lot_func * cmo_talk_a_lot;
  INTEX_PREFIX icmo_deal_has_no_sched_dependency_func * icmo_deal_has_no_sched_dependency;
  INTEX_PREFIX icmo_deal_effective_collars_func * icmo_deal_effective_collars;
  INTEX_PREFIX icmo_prepay_speed_func * icmo_prepay_speed;
  INTEX_PREFIX icmo_get_orig_notional_bal_func * icmo_get_orig_notional_bal;
  INTEX_PREFIX icmo_run_mbspool_loop_func * icmo_run_mbspool_loop;
  INTEX_PREFIX icmo_mbspool_loop_func * icmo_mbspool_loop;
  INTEX_PREFIX icmo_tranche_deal_class_func * icmo_tranche_deal_class;
  INTEX_PREFIX icmo_horizon_return_func * icmo_horizon_return;
  INTEX_PREFIX icmo_total_return_func *  icmo_total_return;
  INTEX_PREFIX icmo_effcoup_calc_func * icmo_effcoup_calc;
  INTEX_PREFIX icmo_yldcrv_yield_at_maturity_func * icmo_yldcrv_yield_at_maturity;
  INTEX_PREFIX icmo_property_to_loan_forecast_func * icmo_property_to_loan_forecast;
  INTEX_PREFIX icmo_use_case_sensitive_dir_func * icmo_use_case_sensitive_dir;
  INTEX_PREFIX icmo_pool_is_in_group_func * icmo_pool_is_in_group;
  INTEX_PREFIX icmo_group_is_in_group_func * icmo_group_is_in_group;
  INTEX_PREFIX icmo_parent_pips_supported_by_child_pip_func * icmo_parent_pips_supported_by_child_pip;
  INTEX_PREFIX icmo_independent_groups_func * icmo_independent_groups;
  INTEX_PREFIX icmo_free_mbspool_cache_func * icmo_free_mbspool_cache;
  INTEX_PREFIX icmo_tranche_taxinfo_func * icmo_tranche_taxinfo;
  INTEX_PREFIX icmo_typical_parse_control_fcn_func * icmo_typical_parse_control_fcn;
  INTEX_PREFIX icmo_typical_parse_control_fcn2_func * icmo_typical_parse_control_fcn2;
  INTEX_PREFIX icmo_zipcode_to_msa_func * icmo_zipcode_to_msa;
  INTEX_PREFIX icmo_format_region_id_func * icmo_format_region_id;
  INTEX_PREFIX icmo_portf_init_func * icmo_portf_init;
  INTEX_PREFIX icmo_portf_reset_func * icmo_portf_reset;
  INTEX_PREFIX icmo_portf_accum_func * icmo_portf_accum;
  INTEX_PREFIX icmo_portf_adjust_func * icmo_portf_adjust;
  INTEX_PREFIX icmo_portf_stats_func * icmo_portf_stats;
  INTEX_PREFIX icmo_portf_free_func * icmo_portf_free;
  INTEX_PREFIX icmo_portf_set_cfs_func * icmo_portf_set_cfs;
  INTEX_PREFIX icmo_solver_func * icmo_solver;
  INTEX_PREFIX icmo_validate_tax_tranche_func * icmo_validate_tax_tranche;
  INTEX_PREFIX icmo_set_deal_errfcn_func * icmo_set_deal_errfcn;
  INTEX_PREFIX icmo_set_global_errfcn_func * icmo_set_global_errfcn;
  INTEX_PREFIX icmo_errinfo_func * icmo_errinfo;
  INTEX_PREFIX icmo_raise_errdie_func * icmo_raise_errdie;
  INTEX_PREFIX icmo_convert_prep_rate_func * icmo_convert_prep_rate;
  INTEX_PREFIX icmo_parse_script_func * icmo_parse_script;
  INTEX_PREFIX icmo_eval_script_func * icmo_eval_script;
  INTEX_PREFIX icmo_set_prepay_script_func * icmo_set_prepay_script;
  INTEX_PREFIX icmo_set_script_retval_func * icmo_set_script_retval;
  INTEX_PREFIX icmo_free_script_handle_func * icmo_free_script_handle;
  INTEX_PREFIX icmo_get_prepay_script_func * icmo_get_prepay_script;
  INTEX_PREFIX icmo_set_loandata_forecast_func * icmo_set_loandata_forecast;
  INTEX_PREFIX icmo_get_loandata_val_func * icmo_get_loandata_val;
  INTEX_PREFIX icmo_ovrdset_asset_vect_func * icmo_ovrdset_asset_vect;
  INTEX_PREFIX icmo_override_asset_write_ccf_func * icmo_override_asset_write_ccf;
  INTEX_PREFIX icmo_override_asset_read_ccf_func * icmo_override_asset_read_ccf;
  INTEX_PREFIX icmo_get_collat_userdata_func * icmo_get_collat_userdata;
  INTEX_PREFIX icmo_get_name_func * icmo_get_name;
  INTEX_PREFIX icmo_get_loandata_translation_func * icmo_get_loandata_translation;
  INTEX_PREFIX icmo_ppmdl_set_adco_credit_assum_func * icmo_ppmdl_set_adco_credit_assum;
  INTEX_PREFIX icmo_ppmdl_set_aft_default_assum_func * icmo_ppmdl_set_aft_default_assum;
  INTEX_PREFIX icmo_worker_func * icmo_worker;
  INTEX_PREFIX icmo_spstr_func * icmo_spstr;
  INTEX_INTERNAL_USE_ONLY INTEX_PREFIX icmo_dummy_dealname_func * icmo_dummy_dealname;

  /* for errdie function */
  INTEX_PREFIX icmo_libinit_func * icmo_libinit;

  /* these are old:  use the equivalent icmo_YyyyMmDd_bd_adj above */
  INTEX_PREFIX icmo_YyyyMmDd_businessday_func * icmo_YyyyMmDd_businessday;
  INTEX_PREFIX icmo_YyyyMmDd_businessday_adj_func * icmo_YyyyMmDd_businessday_adj;

  /* deprecated - replaced by icmo_eval_sched_cashflows */
  DEPRECATED INTEX_PREFIX icmo_eval_ym_formula_func * icmo_eval_ym_formula;
 
#endif

#ifdef TOWERS_WATSON_USE_DLL
  //this returns the structure packing to match the previous settings
  #pragma pack ( pop )
#endif

#define DO_PREPAY_ONE_PERIOD   0
#define DO_PREPAY_TO_MATURITY  1
#define NO_PREPAYMENTS         2
#define N_YLDCRV_NODES         9
#define NO_CALLBACK            0
#define CASHFLOW_CALLBACK      1
#define DETAIL_CALLBACK        2

#define MAX_LOOKBK_MONTHS      5

INTEX_PREFIX char zCdiPath[150];
INTEX_PREFIX char zCduPath[150];

INTEX_PREFIX ICMOMISC *icmomiscp, icmomisc ;
INTEX_PREFIX ICMODB   *icmodbp ;

INTEX_PREFIX ICMO     *icmop ;
INTEX_PREFIX POOL_INFO *pip;

INTEX_PREFIX int      intex_adjusted_pay_day;
INTEX_PREFIX int      intex_tranche_number;
INTEX_PREFIX int      intex_number_of_pools;
INTEX_PREFIX int      intex_pool_number;
INTEX_PREFIX int      intex_cdu_months_offset;
INTEX_PREFIX int      done_with_tranche;
INTEX_PREFIX char     *freezep;
INTEX_PREFIX double   *intex_default_rates;
INTEX_PREFIX double   *intex_severity_rates;
INTEX_PREFIX double   *intex_draw_rates;
INTEX_PREFIX double   *intex_draw_utilization_rates;
INTEX_PREFIX double   *vyldcrv_nodes;
INTEX_PREFIX double   *vyldcrv_vals;
INTEX_PREFIX double   *intex_reinv_rates;
INTEX_PREFIX double   intex_collat_defaults;
INTEX_PREFIX double   intex_collat_schpay;
INTEX_PREFIX double   intex_collat_prepay;
INTEX_PREFIX double   intex_collat_prinpay;
INTEX_PREFIX double   intex_collat_interest;
INTEX_PREFIX double   intex_collat_balance;

INTEX_PREFIX int intex_prepmt_function_mode;
INTEX_PREFIX int intex_collat_callback_mode;
INTEX_PREFIX int intex_num_reinv_rates;

INTEX_PREFIX YyyyMmDd settle_date;
INTEX_PREFIX int adco_error_issued;
INTEX_PREFIX int intex_prepayment_model_supported;

typedef struct _POOL_DATA {
    int    poolnum;                             /* Number of the pool                    */
    double cppresvalue;                         /* PV of pool's future cashflows         */
    double *vcpcashflow;                        /* Cash flow by month                    */
    double *vcpbalance;                         /* Balance by month                      */
    double *vcpinterest;                        /* Interest by month                     */
    double *vcpprincipal;                       /* Principal by month                    */
    double refinrate;                           /* Refinancing Rate for pool             */
    short  remterm;                             /* Months to Maturity for pool           */
    short  fixedarm;                            /* Fix/ARM type for ADCO prepayment model*/
    short  adco_loan_type;                      /* Loan type for ADCO prepayment model   */
    double *smm_forecast;                       /* Andrew Davidson SMM forecast          */
} POOL_DATA ;


typedef struct _DEAL_DATA {
    int     	t;               			   /* t period */
    xstring     proj_type;                     /* projection type */
} DEAL_DATA ;


INTEX_PREFIX POOL_DATA *TempPD;
#endif//WTW - Gen2 - close 
#line 1 "All Model Classes.extern"
#ifndef __UTILITIES_H_
#define __UTILITIES_H_
//Redundant includes only for snip test:
//iomanip included for "setprecision()"
#include <iomanip>
#include <strstream> //WTW - Gen2
typedef vector<vector<string>> sowfinput;
typedef vector<string> sowfcols;
typedef map <xstring, long, less <xstring> > sowfmap;
typedef sowfmap::iterator sowfmapiter;
typedef ofstream sowfoutput;
typedef ofstream sowmpoutput;
typedef vector<vector<string>> deptaskinput;
typedef vector<string> deptaskcols;
typedef map <xstring, long, less <xstring> > deptaskmap;
typedef deptaskmap::iterator deptaskmapiter;
//extern MY_DLL strstream log_screen; //WTW - Gen2 - MY_DLL is not supported
const int EFFECTIVE_RATE = 0;
const int EFFECTIVE_ANNUAL = 1;
const int NOMINAL_SEMIANNUAL = 2;
const int NOMINAL_QUARTERLY = 4;
const int NOMINAL_MONTHLY = 12;
const int ACTUAL_SEMIANNUAL = -2;
const int ACTUAL_QUARTERLY = -4;
const int ACTUAL_MONTHLY = -12;
const double SHORT_TERM_RATE_TERM =  1.0 / 12.0;
const int MAXIMUM_YEARS_FOR_MONTHS_CALCULATIONS = 2700;
const int MAXIMUM_NUMBER_OF_MONTHS = 32400;
const int MAXIMUM_SCENARIO_HEADER_RECORD_LENGTH = 4000;
const int MAXIMUM_NUMBER_OF_SPLINE_COLUMNS = 10;
const double LEAST_ANNUAL_GROWTH_RATE = -0.9999;
const double LEAST_BOND_EQUIVALENT_RATE = 0.0001;
const double SPOT_SHIFT_FOR_EFFECTIVE_DURATION_CALCULATION = 0.0001;
const double ONE_MILLION = 1000000.0;
//WTW - Gen2 - Move Extern definitions to rates header
//const double MINIMUM_MONTHLY_YIELD_RATIO = -0.9; // annual yield = (1.0-0.9)^12 = 1.0e-12
//const double MAXIMUM_MONTHLY_YIELD_RATIO	 = 999999999.0; // annual yield = (1.0+999999999.0)^12 = 1.0e+120
const int DECIMALS_TO_ROUND = 6;
const int ROUND_NEGATIVE_TOZERO = 0;
const int ROUND_NEAR = 1;
const double USLIB_MIN_DOUBLE = -999999999999999.0;
const double USLIB_MAX_DOUBLE =  999999999999999.0;
const double USLIB_MINIMUM_YIELD = -0.9999;
const double USLIB_MINIMUM_YIELD_RATIO = -0.99;
const int SUM_OVER_ALL = -99;
const int SUM_OVER_POSITIVE = -100;
const int SUM_OVER_NEGATIVE = -101;
const int TIER = -98;
const int ANY_GROUP = -99;
const bool DO_NOT_ISSUE_WARNINGS = false;
//WTW - Gen2 - Move Extern definitions to rates header
//const int CALL_CODE = 1; 
//const int PUT_CODE = 2; 
//const int CONTINUOUS_PAYOUT_CODE = 3;
//const int FUTURES_CODE = 4;
// Model point type
const int NEW_PURCH = 0;
const int INIT_MP = 1;
const int PRIOR_PURCH = 2;
const int PROXY_BOND = 3;
// Sum over segment commands
const int CORPORATE_SEGMENT = 0;
const int BUSINESS_SEGMENTS = 1;
// Sum over asset commands
const int BEFORE_BOM_PURCH = 0;
const int BEFORE_SALE = 1;
const int BEFORE_PM_SALE = 2;
const int BEFORE_NCF_SALE = 3;
const int BEFORE_EOM_PURCH = 4;
const int END_OF_PERIOD = 5;
// asset items
const int SEC_MINIMUM_NET_YIELD_MONTH = 5;
const int ALL_EXCEPT_INDEX_ASSET = -2;
const int ANY_ASSET_TYPE         = -1;
const int BOND_CODE              =  0;
const int MORTGAGE_CODE          =  1;
const int SEC_CODE               =  2;
const int REAL_ESTATE_CODE       =  3;
const int EQUITY_CODE            =  4;
const int IRD_CODE               =  5;
const int INDEX_OPTION_CODE      =  7;
const int EPA_CODE	             =  8;
const int MAXIMUM_NUMBER_OF_ASSET_TYPES = 9;
const int MAXIMUM_NUMBER_OF_SALES_CLASSES = 4;
const double ASSET_ACTIVE_THRESHOLD = 0.001;
const int SOLVE_FOR_SPREAD_MAXIMUM_ITERATIONS = 10;
const double SOLVE_FOR_SPREAD_TOLERANCE = 0.25;
const double SOLVE_FOR_SPREAD_TOLERANCE_MULTIPLE_FOR_AMORTIZATION_WARNINGS = 4;
const double SOLVE_FOR_SPREAD_HIGHEST_SPREAD = 4.6332495807107996982298654733414;
const double SOLVE_FOR_SPREAD_LOWEST_SPREAD = -1.3675444679663241336002212911135;
const double GREATEST_MAXIMUM_PAYOUT_INDEX_VALUE = 9999999999.0;
const int INVESTMENT_FUND_INDEX = 0;
const int HEDGING_FUND_INDEX = 1;
const int MAXIMUM_NUMBER_OF_ASSET_FUNDS = 2;
const int MP_ACTIVE_CODE = 1;
const int MP_INACTIVE_CODE = 2;
const int MP_NEXT_CODE = 3;
const int MP_RESET_CODE = 4;
const int MP_EOM_ADJUSTMENTS_CODE = 5;
// Pregen hedge arrays
const int HEDGE_CASH_FLOW = 0;
const int HEDGE_MKT_VAL = 1;
const int HEDGE_ARRAY_SIZE = 2;
// global calculation flags
//extern bool pricing_flag;//WTW - Gen2 - Move Extern definitions to rates header
extern bool factors_flag;
extern bool nb_flag;
extern bool alm_flag;
extern bool tcm_flag;
extern bool vm21_reinv_rate_flag;
extern bool avr_flag;
extern bool imr_flag;
extern bool gaap_flag;
extern bool tgt_cap_flag;
extern bool stoch_flag;
extern bool valn_flag;
extern bool time_step_flag;
extern bool sfas133_valn_flag;
extern bool sop031_valn_flag;
extern bool sfas97rd_valn_flag;
extern bool sfas97lp_valn_flag;
extern bool sfas97lp_gpr_valn_flag;
extern bool sfas91_valn_flag;
extern bool sfas60_valn_flag;
extern bool sfas60_gpr_valn_flag;
extern bool sfas120_nlp_valn_flag;
extern bool sfas120_valn_flag;
extern bool sfas120_gpr_valn_flag;
extern bool loc_gpr_valn_flag;
extern bool pba_valn_flag;
extern bool pba_scen_amt_valn_flag;
extern bool rbc_scen_amt_valn_flag;
extern bool res_scen_amt_valn_flag;
extern bool res_det_res_valn_flag;
extern bool res_ag38_8d_valn_flag;
extern bool std_scen_valn_flag;
extern bool rbc_std_scen_valn_flag;
extern bool rbc_std_scen_step2_valn_flag;
extern bool res_std_scen_valn_flag;
extern bool res_stat_tax_valn_flag;
extern bool hedge_valn_flag;
extern bool hedge_valn_shock_flag;
extern bool hedge_valn_final_flag;
extern bool hedge_proj_stmt_flag;
extern bool investing_flag;
extern bool investing_bom_flag;
extern bool intex_proj_flag;
extern bool proxy_bond_gen_flag;
extern bool running_parallel_flag;
// global comparison values
extern int last_proj_period;
extern int valn_period;
extern int investment_period;
extern bool model_point_fatal_error_issued;
extern double aggregate_amount_threshold;
extern double model_point_amount_threshold;
extern double rate_ratio_threshold;
extern vector<string> valn_periods;
// utility functions - elaborated in rates/economy externs
//WTW - Gen2 - Move Extern definitions to rates header
/*extern double round_result(int rounding, int negative, double x, int n);
extern double factorial(int n);
extern int n_choose_k(int n, int k);
extern xstring check_date_format(const xstring &date);
extern int get_mth_from_date(const xstring &date);
extern int get_yr_from_date(const xstring &date);
extern int get_day_from_date(const xstring &date);
extern int month_from_day_number(int nSerialDate);//WTW - Gen2 - add new formula to replace unsupported MonthFromDayNumber() function
extern int year_from_day_number(int nSerialDate);//WTW - Gen2 - add new formula to replace unsupported YearFromDayNumber() function
extern int day_from_day_number(int nSerialDate);//WTW - Gen2 - add new formula to replace unsupported DayFromDayNumber() function
extern int month_number_from_date(int year, int month); //WTW - Gen2 - add new formula to replace unsupported MonthNumberFromDate() function
extern int day_number_from_date(int nYear, int nMonth, int nDay); //WTW - Gen2 - add new formula to replace unsupported DayNumberFromDate() function
extern int get_end_of_mth_day(int yr, int mth);
extern xstring add_mths_to_date(const xstring &date, int mths);
extern int get_mth_from_adj_date(const xstring &date, int mths);
extern double convert_rate_basis(double orig_rate, double orig_rate_basis, double new_rate_basis);
extern double convert_decrem_rate_basis(double orig_rate, double orig_rate_basis, double new_rate_basis);
extern long int determine_tbl_size(int sNumberOfDims, ...);
extern xstring get_file_name(const xstring &source_file);
extern xstring get_file_path(const xstring &source_file);
extern xstring get_base_group_name(const xstring &tag, bool seriatim_flag = false);
extern xstring get_string_of_date(double date);
extern xstring get_string_of_enum_val(StrEnum::EnumValue type);
extern int date_diff(xstring first_date, xstring second_date);
extern int number_of_decimals(double xxx, int digits);//WTW - Gen2 - replace preprocessor #define with formula
extern xstring write_string(double value, int string_length, int significant_digits);
extern xstring write_array_to_string(SmartArray <double> value_array, int low, int high);
extern void read_from_string(xstring temp_string, SmartArray <double> &temp_array);
extern void split_string_usl(const string& str, vector<string>& tokens, const string& delimiters);
extern void split_string_usl(const string& str, vector<string>& tokens, const string& delimiters, const string& dash);
//extern void split_string_usl_comma_dash(const string& str, vector<string>& tokens, const string& delimiters, const string& dash);
extern void query_run_time(const xstring &caller, const xstring &file_name);
// financial functions
extern double annual_yld(double monthly_numerator, double monthly_denominator, int return_frequency);
extern double vtothen(double rate_per_period, int num_periods);
extern double a_angle_n(double rate_per_period, int num_periods);
extern void cte_calc(SmartArray <SmartArray <double>> value_array, double cte_percentage, double &cte_amt, double &tax_avg_ratio);
extern double bs_highest_gain_freq_mult(double length_of_sampling_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq);
extern double bs_opt_val(double strike_price, double yrs_to_expiry, double underlying_price, double vol, double risk_free_rate, double payout_rate, int call_or_put, int formula_code);
extern double bs_opt_val_asian(int call_or_put, double current_price, double observed_average_price, double strike_price, double length_of_averaging_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq);
extern double bs_opt_val_levy_asian(double strike_price, double yrs_to_expiry, double underlying_price, double average_price, double vol, double risk_free_rate, double payout_rate);
extern double bs_opt_val_continuous_highest_gain(int call_or_put, double current_price, double observed_max, double observed_min, double strike_price, double length_of_sampling_period, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq);
extern double bs_opt_val_highest_gain(int call_or_put, double current_price, double observed_max, double observed_min, double strike_price, double length_of_sampling_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq);
extern double bs_opt_val_mthly_sum_cap(int crediting_mths, int known_index_vals, double sum_capped_amts,  double mthly_cap_rate, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq);
extern double cumul_bivariate_normal_distribn(double x, double y, double rho);
extern double cumul_normal_distribn(double x);*/

// RAFM SQLite
#ifndef _RAFMSQLITE_H_
#define _RAFMSQLITE_H_

#include <string>
#include <vector>

using namespace std;

// 20210614 STW: upgrade to RAFM 2.9
/*
extern void openDatabase(string dbPath);
extern void closeDatabase();
extern string readCsvFile(string csvPath);
extern void executeQuery(string sql, vector<string>& columns, vector<vector<string>>& results);
*/
#endif
#endif
extern int trace_wanted;


extern MY_DLL double msPhase2Tolerance;
extern MY_DLL int last_model_period;
extern MY_DLL Message_handler *eh;

ofstream& ITXFile = *new ofstream;
#define INTEX_CASH_FLOW_DETAIL 0
#define INTEX_CASH_FLOW_POOL_DETAIL 0 // -1 for ALL; 0 for none; otherwise, pool num
#define INTEX_POOL_DETAIL_Range(mth)  (mth >= 999 && mth <= 18)
#define INTEX_CALL_TRACE 0 // 0 for none; 1 otherwise
extern bool intex_detail_wanted;

// fatal_error is set to true if an Intex asset cannot be projected
// because intex_cdu_months_offset is less than t_low
extern bool intex_fatal_error;

HINSTANCE hIntexDLL = NULL;

// static pointer to class
#if defined(__INTEX_ASSET_H_)
static INTEX_ASSET * pThis = 0;//WTW - Gen2 - build compiler directive around this line
#endif

// setup static callback functions
static double __cdecl index_rate_callback_function(struct _ICMO *icmop, int ith_index, int ith_month)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted && INTEX_POOL_DETAIL_Range(ith_month))
	log_screen << "itxtr-> |index_rate_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
return pThis->index_rate(icmop, ith_index, ith_month);
#else
return 0;
#endif
}
static double __cdecl prepayment_rate_callback_function(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, int curper, int curmonth)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted && INTEX_POOL_DETAIL_Range(curmonth))
	log_screen << "itxtr-> |prepayment_rate_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
return pThis->prepmt_rate(icmop, pip, ith_pool, curper, curmonth);
#else
return 0;
#endif
}
static void __cdecl prepayment_setup_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if defined(__INTEX_ASSET_H_)
pThis->prepmt_setup(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl collat_callback_function(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, double *vcpprincipal, double *vcpinterest, double * vcpcashflow, double *vcpbalance, int month)
{
#if defined(__INTEX_ASSET_H_)
pThis->collat_callback(icmop, pip, ith_pool, vcpprincipal, vcpinterest, vcpcashflow, vcpbalance, month);
#endif
}
static void __cdecl cp_cashflows_callback_function(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, double *vcpprincipal, double *vcpinterest, double * vcpcashflow, double *vcpbalance, int month)
{
#if defined(__INTEX_ASSET_H_)
pThis->cp_cash_flow(icmop, pip, ith_pool, vcpprincipal, vcpinterest, vcpcashflow, vcpbalance, month);
#endif
}
static void __cdecl cp_detail_callback_function(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, double *vcpprincipal, double *vcpinterest, double *vcpcashflow, double *vcpbalance, int month)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted && INTEX_POOL_DETAIL_Range(month))
	log_screen << "itxtr-> |cp_detail_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
pThis->cp_detail(icmop, pip, ith_pool, vcpprincipal, vcpinterest, vcpcashflow, vcpbalance, month);
#endif
}
static void __cdecl cp_refinancing_rate_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if defined(__INTEX_ASSET_H_)
pThis->cp_refinancing_rate(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl free_pool_data_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted)
	log_screen << "itxtr-> |free_pool_data_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
pThis->free_pool_data(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl initial_pool_detail_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted)
	log_screen << "itxtr-> |initial_pool_detail_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
pThis->init_pool_detail(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl initialize_pool_data_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if defined(__INTEX_ASSET_H_)
pThis->initialize_pool_data(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl resets_off_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted)
	log_screen << "itxtr-> |resets_off_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
pThis->resets_off(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl resets_on_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted)
	log_screen << "itxtr-> |resets_on_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
pThis->resets_on(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl restore_pool_data_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if defined(__INTEX_ASSET_H_)
pThis->restore_pool_data(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl save_pool_data_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if defined(__INTEX_ASSET_H_)
pThis->save_pool_data(icmop, dealname, pip, ith_pool);
#endif
}

extern MY_DLL long scenario_number;
extern MY_DLL long layer;
extern MY_DLL2 int write_submodels;
extern MY_DLL int check_rebasing;
extern MY_DLL bool stripWanted;
extern MY_DLL2 bool iterationLoopRun;
extern const int& first_proj_task_loop;
extern const int& last_proj_task_loop;
extern const int& proj_task_loop_num;
extern const int& num_of_proj_task_loops;

extern MY_DLL2 int use_overlay_code;
extern MY_DLL int trace_level_wanted;
extern MY_DLL int trace_level;
extern MY_DLL bool bEmitTurboDebugger;
extern MY_DLL Parmfile *  p;

 // Tables...
#ifndef intex_asset_TableDefs
#define intex_asset_TableDefs
 // Generic Tables ...
#endif

	TempTableHolderCollection INTEX_ASSET::TTHC;
void INTEX_ASSET::removeSMPointers(ModelClass* modelToRemove){

}		

//@@ START - active_tranche_flag
// Active Tranche Flag                                                                                             
// Column:ACTIVE_TRANCHE_FLAG
//========================================================
double INTEX_ASSET_UDF::intex_asset_active_tranche_flag(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(1,"active_tranche_flag",t);
}



//^^^

#line 1 "active_tranche_flag.INTEX_ASSET.for"
if (!intex_prepayment_model_supported)
	{
	if (is_first_proj_task_loop
		&& is_intex_projection)
		log_screen << "Intex Pre-projection Not Applicable for "
					+ asset_id 
					+ ": Collateral Type is not supported by Andrew Davidson." 
					<< MSG_ERROR;
	
	return 0;
	}

if (t == 0)
	{
	if (preliminary_projection_complete)
		return 1;

	if (!prelim_proj())
		return 0;

	return 1;
	}

if (t == done_with_tranche)
	return 0;

return 1;

}


//@@ END

//@@ START - cal_mth
// Calendar Month                                                                                             
// Column:CAL_MTH
//========================================================
double INTEX_ASSET_UDF::intex_asset_cal_mth(int t) {
//^^^



//^^^

#line 1 "cal_mth.INTEX_ASSET.for"
if (t == start_period)
	return get_mth_from_date(proj_date_adj);

return proj_start_mth + t - 1
	   - 12 * floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - cal_yr
// Calendar Year                                                                                             
// Column:CAL_YR
//========================================================
double INTEX_ASSET_UDF::intex_asset_cal_yr(int t) {
//^^^



//^^^

#line 1 "cal_yr.INTEX_ASSET.for"
if (t == start_period)
	return get_yr_from_date(proj_date_adj);

return proj_start_yr + cal_yr_relative(t) - 1;

}


//@@ END

//@@ START - cal_yr_relative
// Calendar Year Relative                                                                                             
// Column:CAL_YR_RELATIVE
//========================================================
double INTEX_ASSET_UDF::intex_asset_cal_yr_relative(int t) {
//^^^



//^^^

#line 1 "cal_yr_relative.INTEX_ASSET.for"
return 1 + floor((proj_start_mth + t - 2) / 12.0);

}


//@@ END

//@@ START - date
// Date                                                                                             
// Column:DATE
//========================================================
double INTEX_ASSET_UDF::intex_asset_date(int t) {
//^^^



//^^^

#line 1 "date.INTEX_ASSET.for"
// This column is a lookup key for external sources varying by date
// The definition matches Excel = number of days since 1899
// The value is for the first day of the current month

int year = cal_yr(t);
int month = cal_mth(t);
int day = 1;

return DayNumberFromDate(year, month, day);

}


//@@ END

//@@ START - finalize
// Finalize                                                                                             
// Column:FINALIZE
//========================================================
double INTEX_ASSET_UDF::intex_asset_finalize(int t) {
//^^^



//^^^

#line 1 "finalize.INTEX_ASSET.for"
// clean up the Intex data
clear_asset_data();

return 1.0;

}


//@@ END

//@@ START - get_collateral_prepmt
// Get Collateral Prepayment                                                                                             
// Column:GET_COLLATERAL_PREPMT
//========================================================
double INTEX_ASSET_UDF::intex_asset_get_collateral_prepmt(int t) {
//^^^



//^^^

#line 1 "get_collateral_prepmt.INTEX_ASSET.for"
if (asset_defn != MBS)
	return NO_AVG;

if (!active_tranche_flag(t - 1))
	return NO_AVG;

if (intex_collat_prinpay != 0.0)
	return (1.0 - intex_collat_schpay / intex_collat_prinpay)
		   * intex_principal_payment;

return 0.0;

}


//@@ END

//@@ START - get_tranche_accr_int
// Get Tranche Accrued Interest                                                                                             
// Column:GET_TRANCHE_ACCR_INT
//========================================================
double INTEX_ASSET_UDF::intex_asset_get_tranche_accr_int(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(8,"get_tranche_accr_int",t);
}



//^^^

#line 1 "get_tranche_accr_int.INTEX_ASSET.for"
if (done_with_tranche)
	return 0.0;

pThis = this;
freezep = icmo_pmt_to_pmt_freeze(icmop);
intex_pool_number = 0;
icmo_count_npools(icmop, save_pool_data_callback_function);
intex_collat_callback_mode = NO_CALLBACK;
intex_prepmt_function_mode = NO_PREPAYMENTS;

for (int period = t + intex_cdu_months_offset + 1; period <= t + intex_cdu_months_offset + 2; period++)
	icmo_pay_1period(icmop, period, NULL, NULL, NULL, NULL);

// forward settle date to end of projection period
icmo_forward_settle_date(icmop, 0,
		icmo_YyyyMmDd_addmo(settle_date, 
				            t + intex_cdu_months_offset, TRUE), 0);

icmo_stats(icmop, intex_tranche_number, 0, ICMOPY_NONE, 0);

double accr_int = 0;

// Adjust accrued interest for the delay period since we assume no payment delays
if (icmop->icmo_tranche_delays[intex_tranche_number] >= 30)
	accr_int
	= icmop->icmot_accrued
	  * (1.0 - (float)icmop->icmo_tranche_delays[intex_tranche_number]
	  / icmop->icmot_days_accrued);
else
	accr_int
	= icmop->icmot_accrued;

// Go back to the original settle date 
icmo_forward_settle_date(icmop, 0, settle_date, 0);

intex_pool_number = 0;
icmo_count_npools(icmop, restore_pool_data_callback_function);
icmo_pmt_to_pmt_thaw(icmop, freezep);
icmo_pmt_to_pmt_toss(&freezep);

return accr_int;

}


//@@ END

//@@ START - get_tranche_accr_int_bef_prepmt
// Get Tranche Accrued Interest Before Prepayments                                                                                             
// Column:GET_TRANCHE_ACCR_INT_BEF_PREPMT
//========================================================
double INTEX_ASSET_UDF::intex_asset_get_tranche_accr_int_bef_prepmt(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(9,"get_tranche_accr_int_bef_prepmt",t);
}



//^^^

#line 1 "get_tranche_accr_int_bef_prepmt.INTEX_ASSET.for"
if (done_with_tranche)
	return 0.0;

pThis = this;
freezep = icmo_pmt_to_pmt_freeze(icmop);
intex_pool_number = 0;
icmo_count_npools(icmop, save_pool_data_callback_function);
intex_collat_callback_mode = NO_CALLBACK;
intex_prepmt_function_mode = NO_PREPAYMENTS;

for	(int period = t + intex_cdu_months_offset + 1; period <= t + intex_cdu_months_offset + 2; period++)
	icmo_pay_1period(icmop, period, NULL, NULL, NULL, NULL);
	
// forward settle date to payment day
icmo_forward_settle_date(icmop, 0,
		icmo_YyyyMmDd_add(settle_date, 
						  30 * (t + intex_cdu_months_offset - 1)
						  + get_tranche_maturity_day, TRUE), 0);

icmo_stats(icmop, intex_tranche_number, 0, ICMOPY_NONE, 0);

double accr_int = icmop->icmot_accrued;

// Go back to the original settle date 
icmo_forward_settle_date(icmop, 0, settle_date, 0);

intex_pool_number = 0;
icmo_count_npools(icmop, restore_pool_data_callback_function);
icmo_pmt_to_pmt_thaw(icmop, freezep);
icmo_pmt_to_pmt_toss(&freezep);

return accr_int;

}


//@@ END

//@@ START - get_tranche_bal
// Get Tranche Bal                                                                                             
// Column:GET_TRANCHE_BAL
//========================================================
double INTEX_ASSET_UDF::intex_asset_get_tranche_bal(int t) {
//^^^



//^^^

#line 1 "get_tranche_bal.INTEX_ASSET.for"
if (done_with_tranche)
	return NO_AVG;

if (t == -intex_cdu_months_offset)
	return icmop->icmo_tranche_curbals[intex_tranche_number];

if (t == 0 
	&& intex_cdu_months_offset > 0
	&& preliminary_projection_complete)
	return balance[t];

return intex_principal_balance;

}


//@@ END

//@@ START - get_tranche_cash_flow
// Get Tranche Cash Flow                                                                                             
// Column:GET_TRANCHE_CASH_FLOW
//========================================================
double INTEX_ASSET_UDF::intex_asset_get_tranche_cash_flow(int t) {
//^^^



//^^^

#line 1 "get_tranche_cash_flow.INTEX_ASSET.for"
if (!active_tranche_flag(t - 1))
	return NO_AVG;

return intex_cashflow;

}


//@@ END

//@@ START - get_tranche_int_pmt
// Get Tranche Interest Payment                                                                                             
// Column:GET_TRANCHE_INT_PMT
//========================================================
double INTEX_ASSET_UDF::intex_asset_get_tranche_int_pmt(int t) {
//^^^



//^^^

#line 1 "get_tranche_int_pmt.INTEX_ASSET.for"
if (!active_tranche_flag(t - 1))
	return NO_AVG;

return intex_interest_payment;

}


//@@ END

//@@ START - get_tranche_mths_to_reset
// Get Tranche Months to Reset                                                                                             
// Column:GET_TRANCHE_MTHS_TO_RESET
//========================================================
double INTEX_ASSET_UDF::intex_asset_get_tranche_mths_to_reset(int t) {
//^^^
if ( isRebaseClone && sm_peer_model  && t <= rebase_period ){
	return rebase_value(13,"get_tranche_mths_to_reset",t);
}



//^^^

#line 1 "get_tranche_mths_to_reset.INTEX_ASSET.for"
if (tranche_rate_defn == FLOATING_RATE)
	return icmop->icmo_collat_wavg->pi_armp->armi_ntillreset - 1;
	
return NO_AVG;

}


//@@ END

//@@ START - get_tranche_prin_pmt
// Get Tranche Principal Payment                                                                                             
// Column:GET_TRANCHE_PRIN_PMT
//========================================================
double INTEX_ASSET_UDF::intex_asset_get_tranche_prin_pmt(int t) {
//^^^



//^^^

#line 1 "get_tranche_prin_pmt.INTEX_ASSET.for"
if (!active_tranche_flag(t - 1))
	return NO_AVG;

return intex_principal_payment
	   - get_collateral_prepmt(t);

}


//@@ END

//@@ START - initialize
// Initialize                                                                                             
// Column:INITIALIZE
//========================================================
double INTEX_ASSET_UDF::intex_asset_initialize(int t) {
//^^^



//^^^

#line 1 "initialize.INTEX_ASSET.for"
static int first_time = 1;
static int loaded_proj_task_loop = -999;

if (first_time)
	{
	// check and load the Intex Libraries
	load_library();
	open_translation_tbl();

	int intex_mbs_licensed = database_check(1 /*"MBS"*/);
	int intex_cmo_licensed = database_check(2 /*"CMO"*/);
	
	if (!intex_mbs_licensed && !intex_cmo_licensed)
		throw FatalError("No Intex Databases have been licensed. Projection aborting.");

	// create adco detail report file
	if (asset_detail_rpt_defn == YES)
		{
		xstring output_name = "";
		xstring output_file_name = replaceWildcards(output_location());
		output_file_name = xstring(output_file_name(0 , output_file_name.find_first_of("~")));


		xstring detail_rpt_file
		= output_file_name
		  + "_IntexDetail.csv";

		ITXFile.open(detail_rpt_file);
		ITXFile.setf(ios::fixed, ios::floatfield);
		ITXFile.precision(12);

		if (!ITXFile)
			{
			xstring message 
			= "Cannot open " + detail_rpt_file 
			  + ". Check that the directory has been created and that you have permission to write to the directory.";

			throw FatalError(message);
			}
		else
			{
			ITXFile << endl
					<< "Intex Projection Detail Report For "
					<< output_file << endl << endl;
					
			// NOTE: Modify these settings if icmomisc setup is changed 
			ITXFile << "Intex Database Modeling Assumptions" << endl
					<< "Deal Mode,Seasoned Weighted Average" << endl
					<< "Pricing Accuracy,No" << endl
					<< "Use History,No" << endl
					<< "Make Collat Tranche,No" << endl
					<< "Accept Partial CDUs,Yes" << endl
					<< "Optimize CF Speed,Yes" << endl
					<< "Cluster Amort Schedules,Yes" << endl
					<< "Cluster ARM Reset Detail,Yes" << endl
					<< "Cluster IO/PO Detail,Yes" << endl
					<< "Collat Prepay Provisions,Lockout & Points Only" << endl
					<< "Collat Balloon Extensions,Use Contract or 12-month/All extend/2pct Step-up/Regular amort" << endl
					<< "Collat Line-of-Credit Draws,10pct CPR & 60pct max utilization" << endl
					<< "Optional Redemption,Any Call/Earliest Date" << endl;
			}
		}
	first_time = 0;
	}

if (isMainModel)
	{
	if (loaded_proj_task_loop != proj_task_loop_num)
		rates->initialize(t);

	#ifdef __ADCO_ASSET_H_
	if (adco)
		{
		if (prepmt_model_defn == ANDREW_DAVIDSON)
			adco->initialize(t);
		}
	#endif	

	// setup the intex asset
	if (initialize_asset())
		{
		// call the time 0 values
		get_tranche_bal(0);
	
		if (intex_cdu_months_offset <= 0)
			int_savings_pv_cash_flow_setup(0);

		get_tranche_accr_int_bef_prepmt(0);
		get_tranche_accr_int(0);
		resetValues();
	
		// perform the experience cashflow projection
		for (int tt = 1; tt <= final_period; tt++)
			{
			proj_defn = "Experience";
			cash_flow_proj(tt);
			get_tranche_accr_int_bef_prepmt(tt);
			get_tranche_accr_int(tt);
			}
		}

	loaded_proj_task_loop = proj_task_loop_num;
	}

return 1.0;

}


//@@ END

//@@ START - startup
// Startup                                                                                             
// Column:STARTUP
//========================================================
double INTEX_ASSET_UDF::virtual_startup(int t) {
//^^^



//^^^

#line 1 "startup.INTEX_ASSET.for"
#if 0 // START_HEADER
#define TRANCHE_ARRAY_DIMENSION 481
#endif // END_HEADER

#if 0 // START_EXTERNS
ofstream& ITXFile = *new ofstream;
#define INTEX_CASH_FLOW_DETAIL 0
#define INTEX_CASH_FLOW_POOL_DETAIL 0 // -1 for ALL; 0 for none; otherwise, pool num
#define INTEX_POOL_DETAIL_Range(mth)  (mth >= 999 && mth <= 18)
#define INTEX_CALL_TRACE 0 // 0 for none; 1 otherwise
extern bool intex_detail_wanted;

// fatal_error is set to true if an Intex asset cannot be projected
// because intex_cdu_months_offset is less than t_low
extern bool intex_fatal_error;

HINSTANCE hIntexDLL = NULL;

// static pointer to class
#if defined(__INTEX_ASSET_H_)
static INTEX_ASSET * pThis = 0;//WTW - Gen2 - build compiler directive around this line
#endif

// setup static callback functions
static double __cdecl index_rate_callback_function(struct _ICMO *icmop, int ith_index, int ith_month)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted && INTEX_POOL_DETAIL_Range(ith_month))
	log_screen << "itxtr-> |index_rate_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
return pThis->index_rate(icmop, ith_index, ith_month);
#else
return 0;
#endif
}
static double __cdecl prepayment_rate_callback_function(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, int curper, int curmonth)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted && INTEX_POOL_DETAIL_Range(curmonth))
	log_screen << "itxtr-> |prepayment_rate_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
return pThis->prepmt_rate(icmop, pip, ith_pool, curper, curmonth);
#else
return 0;
#endif
}
static void __cdecl prepayment_setup_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if defined(__INTEX_ASSET_H_)
pThis->prepmt_setup(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl collat_callback_function(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, double *vcpprincipal, double *vcpinterest, double * vcpcashflow, double *vcpbalance, int month)
{
#if defined(__INTEX_ASSET_H_)
pThis->collat_callback(icmop, pip, ith_pool, vcpprincipal, vcpinterest, vcpcashflow, vcpbalance, month);
#endif
}
static void __cdecl cp_cashflows_callback_function(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, double *vcpprincipal, double *vcpinterest, double * vcpcashflow, double *vcpbalance, int month)
{
#if defined(__INTEX_ASSET_H_)
pThis->cp_cash_flow(icmop, pip, ith_pool, vcpprincipal, vcpinterest, vcpcashflow, vcpbalance, month);
#endif
}
static void __cdecl cp_detail_callback_function(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, double *vcpprincipal, double *vcpinterest, double *vcpcashflow, double *vcpbalance, int month)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted && INTEX_POOL_DETAIL_Range(month))
	log_screen << "itxtr-> |cp_detail_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
pThis->cp_detail(icmop, pip, ith_pool, vcpprincipal, vcpinterest, vcpcashflow, vcpbalance, month);
#endif
}
static void __cdecl cp_refinancing_rate_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if defined(__INTEX_ASSET_H_)
pThis->cp_refinancing_rate(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl free_pool_data_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted)
	log_screen << "itxtr-> |free_pool_data_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
pThis->free_pool_data(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl initial_pool_detail_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted)
	log_screen << "itxtr-> |initial_pool_detail_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
pThis->init_pool_detail(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl initialize_pool_data_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if defined(__INTEX_ASSET_H_)
pThis->initialize_pool_data(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl resets_off_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted)
	log_screen << "itxtr-> |resets_off_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
pThis->resets_off(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl resets_on_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if INTEX_CALL_TRACE
if (intex_detail_wanted)
	log_screen << "itxtr-> |resets_on_callback_function" << MSG_ERROR;
#endif

#if defined(__INTEX_ASSET_H_)
pThis->resets_on(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl restore_pool_data_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if defined(__INTEX_ASSET_H_)
pThis->restore_pool_data(icmop, dealname, pip, ith_pool);
#endif
}
static void __cdecl save_pool_data_callback_function(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
#if defined(__INTEX_ASSET_H_)
pThis->save_pool_data(icmop, dealname, pip, ith_pool);
#endif
}
#endif // END_EXTERNS

#if 0 // START_CLASS
bool issue_messages;
int valuation_period;
int loaded_proj_task_loop;
int is_intex_projection;
int preliminary_projection_complete;
//intex cash flow variables
double intex_principal_payment;
double intex_interest_payment;
double intex_principal_balance;
double intex_cashflow;

double principal[TRANCHE_ARRAY_DIMENSION];
double balance[TRANCHE_ARRAY_DIMENSION];
double interest[TRANCHE_ARRAY_DIMENSION];

SmartArray <double> prepmt_exercise_pct;
SmartArray <double> prepmt_nonfinancial_adj;
SmartArray <double> prepmt_nonfinancial_seasonality_addn;
SmartArray <double> prepmt_seasoning_since_issue_mult;

SmartArray <double> psa_base_rate;
#endif // END_CLASS

#if 0 // START_CONSTRUCTOR
issue_messages = false;
is_intex_projection = 0;
preliminary_projection_complete = 0;
loaded_proj_task_loop = -1;
valuation_period = -1;
intex_principal_payment = 0;
intex_interest_payment = 0;
intex_principal_balance = 0;
intex_cashflow = 0;

memset(principal, 0, TRANCHE_ARRAY_DIMENSION * sizeof(double));
memset(interest, 0, TRANCHE_ARRAY_DIMENSION * sizeof(double));
memset(balance, 0, TRANCHE_ARRAY_DIMENSION * sizeof(double));
#endif // END_CONSTRUCTOR

#if 0 // START_DESTRUCTOR
close_translation_tbl();
unload_library();
#endif // END_DESTRUCTOR

// initialize the submodel
if (is_first_proj_task_loop)
	issue_messages = true;
else
	issue_messages = false;

preliminary_projection_complete = 0;

setup_psa_base_rate();

if (isMainModel)
	{
	is_intex_projection = 1;
	loaded_proj_task_loop = proj_task_loop_num;

	log_strm.setf(ios::fixed);
	log_strm.precision(12);

	log_screen.setf(ios::fixed);
	log_screen.precision(12);

	// set stoch_flag for rates loading
	stoch_flag = true;
	}

return 0;

}


//@@ END

//@@ START - asset_detail_rpt_flag
// Detail Report Flag                                                                                             
// Calculated Variable:ASSET_DETAIL_RPT_FLAG
//========================================================
int INTEX_ASSET_UDF::intex_asset_asset_detail_rpt_flag() {
//^^^


#line 1 "asset_detail_rpt_flag.INTEX_ASSET.for"
if (eq(asset_detail_rpt_asset_id, "ALL")
    || eq(asset_detail_rpt_asset_id, asset_id))
  	return YES;
else  
  	return NO;

}


//@@ END

//@@ START - commencement_period
// Commencement Period                                                                                             
// Calculated Variable:COMMENCEMENT_PERIOD
//========================================================
int INTEX_ASSET_UDF::intex_asset_commencement_period() {
//^^^


#line 1 "commencement_period.INTEX_ASSET.for"
if (investing_flag)
	return investment_period;

return 0;

}


//@@ END

//@@ START - final_period
// Final Period                                                                                             
// Calculated Variable:FINAL_PERIOD
//========================================================
int INTEX_ASSET_UDF::intex_asset_final_period() {
//^^^


#line 1 "final_period.INTEX_ASSET.for"
if (!time_step_flag	|| (time_step_flag && valn_flag))
	return last_proj_period;

// For time step projections, the first experience projection must run for the full projection horizon
return atoi(xstring(valn_periods[valn_periods.size() - 1])) + 1;

}


//@@ END

//@@ START - get_collateral_num_of_pools
// Get Collateral Number of Pools                                                                                             
// Calculated Variable:GET_COLLATERAL_NUM_OF_POOLS
//========================================================
int INTEX_ASSET_UDF::intex_asset_get_collateral_num_of_pools() {
//^^^


#line 1 "get_collateral_num_of_pools.INTEX_ASSET.for"
return intex_number_of_pools;

}


//@@ END

//@@ START - get_tranche_cdu_mths_offset
// Get Tranche Cdu Months Offset                                                                                             
// Calculated Variable:GET_TRANCHE_CDU_MTHS_OFFSET
//========================================================
int INTEX_ASSET_UDF::intex_asset_get_tranche_cdu_mths_offset() {
//^^^


#line 1 "get_tranche_cdu_mths_offset.INTEX_ASSET.for"
return intex_cdu_months_offset;

}


//@@ END

//@@ START - get_tranche_days_accr
// Get Tranche Days Accrued                                                                                             
// Calculated Variable:GET_TRANCHE_DAYS_ACCR
//========================================================
int INTEX_ASSET_UDF::intex_asset_get_tranche_days_accr() {
//^^^


#line 1 "get_tranche_days_accr.INTEX_ASSET.for"
return icmop->icmot_days_accrued;

}


//@@ END

//@@ START - get_tranche_freqs
// Get Tranche Frequency                                                                                             
// Calculated Variable:GET_TRANCHE_FREQS
//========================================================
int INTEX_ASSET_UDF::intex_asset_get_tranche_freqs() {
//^^^


#line 1 "get_tranche_freqs.INTEX_ASSET.for"
return icmop->icmo_tranche_freqs[intex_tranche_number];

}


//@@ END

//@@ START - get_tranche_maturity_day
// Get Tranche Maturity Day                                                                                             
// Calculated Variable:GET_TRANCHE_MATURITY_DAY
//========================================================
int INTEX_ASSET_UDF::intex_asset_get_tranche_maturity_day() {
//^^^


#line 1 "get_tranche_maturity_day.INTEX_ASSET.for"
return icmo_YyyyMmDd_day(icmop->icmo_tranche_accrudates[intex_tranche_number]);

}


//@@ END

//@@ START - get_tranche_maturity_period
// Get Tranche Maturity Period                                                                                             
// Calculated Variable:GET_TRANCHE_MATURITY_PERIOD
//========================================================
int INTEX_ASSET_UDF::intex_asset_get_tranche_maturity_period() {
//^^^


#line 1 "get_tranche_maturity_period.INTEX_ASSET.for"
return icmop->icmo_remterm - intex_cdu_months_offset;

}


//@@ END

//@@ START - output_file
// Output File                                                                                             
// Calculated Variable:OUTPUT_FILE
//========================================================
xstring INTEX_ASSET_UDF::intex_asset_output_file() {
//^^^


#line 1 "output_file.INTEX_ASSET.for"
return get_file_name(output_location());

}


//@@ END

//@@ START - output_path
// Output Path                                                                                             
// Calculated Variable:OUTPUT_PATH
//========================================================
xstring INTEX_ASSET_UDF::intex_asset_output_path() {
//^^^


#line 1 "output_path.INTEX_ASSET.for"
return get_file_path(output_location());

}


//@@ END

//@@ START - proj_date_adj
// Projection Date Adjusted                                                                                             
// Calculated Variable:PROJ_DATE_ADJ
//========================================================
xstring INTEX_ASSET_UDF::intex_asset_proj_date_adj() {
//^^^


#line 1 "proj_date_adj.INTEX_ASSET.for"
return add_mths_to_date(proj_date, valn_period);

}


//@@ END

//@@ START - proj_start_mth
// Projection Start Mth                                                                                             
// Calculated Variable:PROJ_START_MTH
//========================================================
int INTEX_ASSET_UDF::intex_asset_proj_start_mth() {
//^^^


#line 1 "proj_start_mth.INTEX_ASSET.for"
int proj_mth = get_mth_from_date(proj_date_adj);

if (proj_mth == 12)
	return 1;
	
return proj_mth + 1;

}


//@@ END

//@@ START - proj_start_yr
// Projection Start Yr                                                                                             
// Calculated Variable:PROJ_START_YR
//========================================================
int INTEX_ASSET_UDF::intex_asset_proj_start_yr() {
//^^^


#line 1 "proj_start_yr.INTEX_ASSET.for"
int proj_mth = get_mth_from_date(proj_date_adj);

if (proj_mth == 12)
	return get_yr_from_date(proj_date_adj) + 1;
	
return get_yr_from_date(proj_date_adj);

}


//@@ END

//@@ START - start_period
// Start Period                                                                                             
// Calculated Variable:START_PERIOD
//========================================================
int INTEX_ASSET_UDF::intex_asset_start_period() {
//^^^


#line 1 "start_period.INTEX_ASSET.for"
return max(0, commencement_period);

}


//@@ END

//@@ START - tranche_rate_defn
// Tranche Rate Definition                                                                                             
// Calculated Variable:TRANCHE_RATE_DEFN
//========================================================
int INTEX_ASSET_UDF::intex_asset_tranche_rate_defn() {
//^^^


#line 1 "tranche_rate_defn.INTEX_ASSET.for"
if (icmop->icmo_collat_wavg->pi_armp != NULL)
	return FLOATING_RATE;

return FIXED_RATE;

}


//@@ END

//@@ START - use_eom_scen_rates
// Use End of Month Scenario Rates?                                                                                             
// Calculated Variable:USE_EOM_SCEN_RATES
//========================================================
int INTEX_ASSET_UDF::intex_asset_use_eom_scen_rates() {
//^^^


#line 1 "use_eom_scen_rates.INTEX_ASSET.for"
return YES;

}


//@@ END


#line 1 "cash_flow_proj.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::cash_flow_proj(int t)
{
if (done_with_tranche)
	return;

pThis = this;
DEAL_DATA * uddp;

uddp = reinterpret_cast <DEAL_DATA *> (icmop->icmo_user);

int_savings_pv_cash_flow_setup(t);

intex_collat_callback_mode = DETAIL_CALLBACK;
intex_prepmt_function_mode = DO_PREPAY_ONE_PERIOD;

double local_principal = 0;
double local_interest = 0;
double local_cashflow = 0;
double local_balance = 0;

if (icmo_pay_1period(icmop, t + intex_cdu_months_offset, 
					    &local_principal, &local_interest, 
					    &local_cashflow, &local_balance) == TRUE)
	done_with_tranche = t;					    

// force call active_tranche_flag column, but not in the preliminary projection (t <=0)
if (t > 0)
	active_tranche_flag(t);

intex_principal_payment = local_principal;
intex_interest_payment = local_interest;
intex_cashflow = local_cashflow;
intex_principal_balance = local_balance;

// force calls to fill the columns
get_tranche_bal(t);
get_tranche_cash_flow(t);
get_tranche_int_pmt(t);
get_collateral_prepmt(t);
get_tranche_prin_pmt(t);

if (asset_detail_rpt_flag == YES)
	{
	int write_projection_header = 0;

	if (t == max(asset_detail_rpt_start_period, 1 - intex_cdu_months_offset))
		write_projection_header = 1;

	tranche_detail(t, write_projection_header);
	}

// clear out the intex payment variables
intex_principal_payment = 0;
intex_interest_payment = 0;
intex_cashflow = 0;
intex_principal_balance = 0;

return;
}



#line 1 "category_refinancing_rate.INTEX_ASSET.for"                                                                                   
double INTEX_ASSET::category_refinancing_rate(int t, int months_to_maturity, int return_rate_basis, int shift_defn)
{
double local_refinancing_rate = 0.0;

if (refinancing_rate_defn == REFINANCING_RATE)
	local_refinancing_rate
	= max(rates->get_int_rate(t,
	            "Govt",
				GET_YIELD_RATE,
				refinancing_rate_scen_yr,
				0.0,
				NOMINAL_SEMIANNUAL, 
				shift_defn,0)//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
		  * refinancing_rate_scen_mult
		  + refinancing_rate_scen_addn,
		  0.0);

if (refinancing_rate_defn == CATEGORY_YIELD_TO_MATURITY)
	local_refinancing_rate
	= rates->get_int_rate(t,
	            category_id,
				GET_YIELD_RATE,
				months_to_maturity / 12.0,
				0.0, 
				NOMINAL_SEMIANNUAL, 
				shift_defn,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

if (return_rate_basis != NOMINAL_SEMIANNUAL)
	local_refinancing_rate
	= convert_rate_basis(local_refinancing_rate, 
			  NOMINAL_SEMIANNUAL,
			  return_rate_basis);

return local_refinancing_rate;
}



#line 1 "clear_asset_data.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::clear_asset_data(void)
{
if (!icmop)
	return;

intex_cdu_months_offset = 0;
preliminary_projection_complete = 0;

delete[] vyldcrv_nodes;
delete[] vyldcrv_vals;
delete[] intex_reinv_rates;

vyldcrv_nodes = NULL;
vyldcrv_vals = NULL;
intex_reinv_rates = NULL;

clear_collateral_pool_data();

delete icmop->icmo_user;
icmop->icmo_user = NULL;

icmo_free(&icmop);

icmop = NULL;
}



#line 1 "clear_collateral_pool_data.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::clear_collateral_pool_data()
{
delete[] intex_default_rates;
delete[] intex_severity_rates;
delete[] intex_draw_rates;
delete[] intex_draw_utilization_rates;

intex_default_rates = NULL;
intex_severity_rates = NULL;
intex_draw_rates = NULL;
intex_draw_utilization_rates = NULL;

// Free POOL_DATA variables for each pool
intex_pool_number = 0;

pThis = this;
icmo_count_npools(icmop, free_pool_data_callback_function);

delete[] TempPD;

TempPD = NULL;
}



#line 1 "close_translation_tbl.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::close_translation_tbl()
{
// Close Intex Cusip Translation Table
if (icmodbp != NULL)
	icmodb_free(&icmodbp);
}



#line 1 "collat_callback.INTEX_ASSET.for"                                                                                   
void __cdecl INTEX_ASSET::collat_callback(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, double *vcpprincipal, double *vcpinterest, double *vcpcashflow, double *vcpbalance, int month)
{
switch (intex_collat_callback_mode)
	{
	case NO_CALLBACK:
		break;
	case CASHFLOW_CALLBACK:
		cp_cashflows_callback_function(icmop, pip, ith_pool,
				vcpprincipal, vcpinterest,
				vcpcashflow, vcpbalance, month);

#if INTEX_CASH_FLOW_POOL_DETAIL
		if (intex_detail_wanted
			&& INTEX_POOL_DETAIL_Range(month)
			&& (ith_pool == INTEX_CASH_FLOW_POOL_DETAIL
				|| (INTEX_CASH_FLOW_POOL_DETAIL == -1)))
			{
			log_screen.setf(ios::fixed, ios::floatfield);
			log_screen << "itx2-> m=" << setw(3) << month
					<< " pool#=" << setw(3) << ith_pool
					<< " p=" << setw(18) << setprecision(8) << vcpprincipal[month]
					<< " i=" << setw(18) << setprecision(8) << vcpinterest[month]
					<< " b=" << setw(18) << setprecision(8) << vcpbalance[month]
					<< " prepay_mode=" << (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD ? "DO_PREPAY_ONE_PERIOD"
										: (intex_prepmt_function_mode == DO_PREPAY_TO_MATURITY ? "DO_PREPAY_TO_MATURITY"
										: (intex_prepmt_function_mode == NO_PREPAYMENTS ? "NO_PREPAYMENTS" : "???")))
					<< " |collat_callback:CASHFLOW_CALLBACK"
					<< MSG_USER;
			}
#endif
		break;
	case DETAIL_CALLBACK:
		cp_detail_callback_function(icmop, pip, ith_pool,
				vcpprincipal, vcpinterest,
				vcpcashflow, vcpbalance, month);

#if INTEX_CASH_FLOW_POOL_DETAIL
		if (intex_detail_wanted
			&& INTEX_POOL_DETAIL_Range(month)
			&& (ith_pool == INTEX_CASH_FLOW_POOL_DETAIL
				|| (INTEX_CASH_FLOW_POOL_DETAIL == -1)))
			{
			log_screen.setf(ios::fixed, ios::floatfield);
			log_screen << "itx3-> m=" << setw(3) << month
					<< " pool#=" << setw(3) << ith_pool
					<< " p=" << setw(18) << setprecision(8) << vcpprincipal[month]
					<< " i=" << setw(18) << setprecision(8) << vcpinterest[month]
					<< " b=" << setw(18) << setprecision(8) << vcpbalance[month]
					<< " prepay_mode=" << (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD ? "DO_PREPAY_ONE_PERIOD"
															: (intex_prepmt_function_mode == DO_PREPAY_TO_MATURITY ? "DO_PREPAY_TO_MATURITY"
															: (intex_prepmt_function_mode == NO_PREPAYMENTS ? "NO_PREPAYMENTS" : "???")))
					<< " |collat_callback:DETAIL_CALLBACK"
					<< MSG_USER;
			}
#endif
		break;
	default:
		break;
	}

return;
}



#line 1 "cp_cash_flow.INTEX_ASSET.for"                                                                                   
void __cdecl INTEX_ASSET::cp_cash_flow(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, double *vcpprincipal, double *vcpinterest, double *vcpcashflow, double *vcpbalance, int month)
{
DEAL_DATA *uddp;
POOL_DATA *updp;

uddp = reinterpret_cast <DEAL_DATA *> (icmop->icmo_user);
updp = reinterpret_cast <POOL_DATA *> (pip->pi_user);

// Don't process if CMO supporting CMO or RE-REMIC
if (pip->pi_endpad != NULL ||
	pip->pi_cftype == ICMOCFTYPE_REMIC)
	return;

double refrate = updp->refinrate;

double mthrefrate
= convert_rate_basis(refrate, 
		  NOMINAL_SEMIANNUAL, 12) / 12.0;

double mthdiscf
= 1.0 / pow((1.0 + refrate
				   / NOMINAL_SEMIANNUAL),
			NOMINAL_SEMIANNUAL / 12.0);

double discfact = pow(mthdiscf, month - uddp->t);

double servamount = icmop->icmoloancf_vservfeeamt[month];

// Only consider payments in the future for discounting
if (month > uddp->t)
	updp->cppresvalue += (vcpcashflow[month] + servamount) * discfact;

updp->vcpcashflow[month] = vcpcashflow[month] + servamount;

updp->vcpinterest[month] = vcpinterest[month] + servamount;

updp->vcpprincipal[month] = vcpprincipal[month];

updp->vcpbalance[month] = vcpbalance[month];

#if INTEX_CASH_FLOW_POOL_DETAIL
if (intex_detail_wanted
	&& INTEX_POOL_DETAIL_Range(month)
	&& (ith_pool == INTEX_CASH_FLOW_POOL_DETAIL
		|| (INTEX_CASH_FLOW_POOL_DETAIL == -1)))
	{
	log_screen.setf(ios::fixed, ios::floatfield);
	log_screen << "itx3-> m=" << setw(3) << month
			<< " pool#=" << setw(3) << ith_pool
			<< " cpval=" << setw(18) << setprecision(8) << updp->cppresvalue
			<< " vccf=" << setw(18) << setprecision(8) << vcpcashflow[month]
			<< " svamt=" << setw(18) << setprecision(8) << servamount
			<< " df=" << setw(18) << setprecision(14) << discfact
			<< " vcprin=" << setw(18) << setprecision(8) << vcpprincipal[month]
			<< " prepay_mode=" << (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD ? "DO_PREPAY_ONE_PERIOD"
								: (intex_prepmt_function_mode == DO_PREPAY_TO_MATURITY ? "DO_PREPAY_TO_MATURITY"
								: (intex_prepmt_function_mode == NO_PREPAYMENTS ? "NO_PREPAYMENTS" : "???")))
			<< " |cp_cash_flow"
			<< MSG_USER;
	}
#endif

if(uddp->t == 0 && month == 1) // Set initial pool get_tranche_bal
	updp->vcpbalance[0] = vcpbalance[0];

return;
}



#line 1 "cp_detail.INTEX_ASSET.for"                                                                                   
void __cdecl INTEX_ASSET::cp_detail(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, double *vcpprincipal, double *vcpinterest, double *vcpcashflow, double *vcpbalance, int month)
{
// Don't process if CMO supporting CMO or RE-REMIC
if (pip->pi_endpad != NULL ||
    pip->pi_cftype == ICMOCFTYPE_REMIC)
    return;

// capture detail variables for collateral
intex_collat_prinpay += vcpprincipal[month];
intex_collat_interest += vcpinterest[month];
intex_collat_balance += vcpbalance[month];

intex_collat_prepay
= intex_collat_prinpay - intex_collat_schpay
  + intex_collat_defaults;

return;
}



#line 1 "cp_refinancing_rate.INTEX_ASSET.for"                                                                                   
void __cdecl INTEX_ASSET::cp_refinancing_rate(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
int scenmth;
DEAL_DATA *uddp;
POOL_DATA *updp;

uddp = reinterpret_cast <DEAL_DATA *> (icmop->icmo_user);
updp = reinterpret_cast <POOL_DATA *> (pip->pi_user);

int t = uddp->t - intex_cdu_months_offset;

if (use_eom_scen_rates == YES)
	scenmth = t;
else
	scenmth = t - 1;

updp->refinrate
= category_refinancing_rate(scenmth,
			updp->remterm, 
			NOMINAL_SEMIANNUAL,
			NO_SHIFT /* shift_defn */);

#if INTEX_CASH_FLOW_POOL_DETAIL
if (intex_detail_wanted
		&& (ith_pool == INTEX_CASH_FLOW_POOL_DETAIL || INTEX_CASH_FLOW_POOL_DETAIL == -1))
	{
	log_screen.setf(ios::fixed, ios::floatfield);
	log_screen << "itx2-> pool#=" << setw(3) << ith_pool
			<< " refin=" << setw(18) << setprecision(14) << updp->refinrate
			<< " yr=" << xint(cal_yr_relative(t))
			<< " mo=" << scenmth
			<< " term=MtoM=" << setw(3) << updp->remterm
			<< " |cp_refinancing_rate"
			<< MSG_USER;
	}
#endif
 
updp->remterm -= 1;

return;
}



#line 1 "database_check.INTEX_ASSET.for"                                                                                   
int INTEX_ASSET::database_check (int type)
{
int licensed;
xstring zDatabase;
xstring dataname;

if (type == 1)
  zDatabase = "MBS";
else
  zDatabase = "CMO";   

dataname = xstring(zCduPath) + zDatabase + "cusip.inf";

if (!access(dataname, 0))
	licensed = 1;
else
	licensed = 0;

return licensed;
}



#line 1 "forecast_adj_wac_rate.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::forecast_adj_wac_rate(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, int offset)
{
int month = 0, idx = 0, age = 0, term = 0;
int reset = 0, mths_to_reset = 0;
int lookback_mo_shift = 0;
double priorrate = 0, payrate = 0;
double indexrate = 0, rndrate = 0, renrate = 0;
DEAL_DATA *uddp;
POOL_DATA *updp;
ARM_INFO *armp;
ARM_INFO *cur_armp;

uddp = reinterpret_cast <DEAL_DATA *> (icmop->icmo_user);
updp = reinterpret_cast <POOL_DATA *> (pip->pi_user);

// Determine future weighted average coupons from histyr and histmth
month = 0;
idx = -1;
payrate = pip->pi_netcoupon;

if (pip->pi_wala >= 0)
	age = pip->pi_wala;
else
	age = pip->pi_wala;

// Start at idx = 0 since wac_forecast[0] is first forecasted wac
for (term = age + 1; term <= min(600, age + pip->pi_remterm); term++)
	{
	idx += 1;
	month += 1;

	if (month == 1)
		priorrate = payrate;

	// Find correct arm information from structure
	cur_armp = pip->pi_armp;
	
	for (armp = pip->pi_armp;
		armp != NULL;
		// need to cast the pointer!
		armp = reinterpret_cast <ARM_INFO *>(armp->armi_next))  
		{
		if (armp->armi_stage_start_mo > term)
			break;
		else if (armp->armi_stage_start_mo < term)
			{
			cur_armp = armp;
			continue;
			}
		else if (armp->armi_stage_start_mo > 1)
			{
			// NEXTARM - change ARM characteristics month
			cur_armp = armp;
			}
		}

	// Need to fill current margin
	adco->arm_margin = cur_armp->armi_netmargin;

	// we are at the correct stage - get initial months to reset
	// months to reset stored on arm structure is the months
	//    to first payment with new rate - not to the actual reset date
	if (month == 1)
		mths_to_reset
		= cur_armp->armi_ntillreset
		  - (12 / icmop->icmo_collat_freq);

	if (mths_to_reset == 1)
		reset = 1;
	else
		reset = 0;

	if (reset == 1)
		mths_to_reset = cur_armp->armi_resetper;
	else
		mths_to_reset -= 1;
	
	adco->arm_wac_rates[idx] = priorrate + pip->pi_servfee;
	
	if (cur_armp->armi_known_next_netrate != 0)
		{
		renrate = cur_armp->armi_known_next_netrate;
		}
	else // must determine next rate
		{
		if (cur_armp->armi_stepup_info != NULL)
			{
			int steps = 0;
			// only specified increases are made
			for (steps = 1;
				steps<cur_armp->armi_stepup_info->stepup_n_steps;
				steps++)
				{
				if (cur_armp->armi_stepup_info->stepup_v_terms[steps] == term)
					renrate
					= priorrate
					  + cur_armp->armi_stepup_info->stepup_v_values[steps];
				}
			}
		else // We need to determine the rate from the arm info
			{
			// Determine lookback months - again, structure value is based on payment
			//   rate reset and not actual reset
			lookback_mo_shift
			= (cur_armp->armi_lookback - 1) / 30
			  + 1 - (12 / icmop->icmo_collat_freq);
	
			if (proj_defn != EXPERIENCE)
				{
				if (proj_defn == NET_YIELD)
					{
					if (month <= offset) // use past actual renewal rates
						indexrate
						= index_rate(icmop,
									cur_armp->armi_index,
									month - offset - lookback_mo_shift);
	
					else // use current renewal rate
						indexrate
						= index_rate(icmop,
								cur_armp->armi_index,
								month - lookback_mo_shift);
					}
				else // MV calculation
					{
					if (month <= offset) // use past actual renewal rates
						indexrate
						= index_rate(icmop,
								cur_armp->armi_index, 
								month - offset - lookback_mo_shift);

					else // use forward renewal rate
						indexrate
						= index_rate(icmop, 
								cur_armp->armi_index, 
								month - lookback_mo_shift);
					}
				}
			else // Initial setup - use actual renewal rates
				indexrate
				= index_rate(icmop, 
						cur_armp->armi_index, 
						month - lookback_mo_shift);
	
			// Determine rounded renewal rate
			if (cur_armp->armi_rounding_method == ICMOARM_ROUND_NONE)
				rndrate = indexrate + cur_armp->armi_netmargin;
	
			else if (cur_armp->armi_rounding_method == ICMOARM_ROUND_TONEAR8)
				rndrate = floor(indexrate + cur_armp->armi_netmargin)
	                      + (round_result(1, 0, (indexrate + cur_armp->armi_netmargin
	                        - floor(indexrate + cur_armp->armi_netmargin))* 8.0, 0))
	                      / 8.0;
			else if (cur_armp->armi_rounding_method == ICMOARM_ROUND_3DECIMAL)
				rndrate = round_result(1, 0, indexrate + cur_armp->armi_netmargin, 3);
	
			else if (cur_armp->armi_rounding_method == ICMOARM_ROUND_TOHIGH8)
				rndrate = floor(indexrate + cur_armp->armi_netmargin)
	                      + (round_result(2, 0, (indexrate + cur_armp->armi_netmargin
	                         - floor(indexrate + cur_armp->armi_netmargin))* 8.0, 0))
	                      / 8.0;

			if (reset)
				{
				renrate = min(min(max(max(rndrate, priorrate
										  - cur_armp->armi_flrresetper)
								  , cur_armp->armi_flrlife)
							  , priorrate
								+ cur_armp->armi_capresetper)
						  , cur_armp->armi_caplife);
				}
			else
				renrate = priorrate;

			} // End determining from ARM info	
		} // End we must determine next rate

	priorrate = renrate;
	} // End  renewal rate loop
}



#line 1 "free_pool_data.INTEX_ASSET.for"                                                                                   
void __cdecl INTEX_ASSET::free_pool_data(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
POOL_DATA *updp;

updp = reinterpret_cast <POOL_DATA *> (pip->pi_user);

intex_pool_number += 1;

if (pip->pi_user != NULL)
    {
	delete[] updp->vcpcashflow;
    delete[] updp->vcpbalance;
    delete[] updp->vcpinterest;
    delete[] updp->vcpprincipal;
    delete[] updp->smm_forecast;

	updp->vcpcashflow = NULL;
	updp->vcpbalance = NULL;
	updp->vcpinterest = NULL;
	updp->vcpprincipal = NULL;
	updp->smm_forecast = NULL;

	delete pip->pi_user;
	pip->pi_user = NULL;
	}

// Free up temporary pool memory 
if (TempPD != NULL)
	{  
	delete[] TempPD[intex_pool_number].vcpcashflow;
	delete[] TempPD[intex_pool_number].vcpbalance;
	delete[] TempPD[intex_pool_number].vcpinterest;
	delete[] TempPD[intex_pool_number].vcpprincipal;
	delete[] TempPD[intex_pool_number].smm_forecast;

	TempPD[intex_pool_number].vcpcashflow = NULL;
	TempPD[intex_pool_number].vcpbalance = NULL;
	TempPD[intex_pool_number].vcpinterest = NULL;
	TempPD[intex_pool_number].vcpprincipal = NULL;
	TempPD[intex_pool_number].smm_forecast = NULL;
	}

return;
}



#line 1 "get_loan_state.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::get_loan_state(char *loan_state, SmartArray<double> &state_vector)
{
string adco_loan_state_vector[] = {"AK","AL","AR","AZ","CA","CO","CT","DC","DE","FL",
                                   "GA","HI","IA","ID","IL","IN","KS","KY","LA","MA",
                                   "MD","ME","MI","MN","MO","MS","MT","NC","ND","NE",
                                   "NH","NJ","NM","NV","NY","OH","OK","OR","PA","RI",
                                   "SC","SD","TN","TX","UT","VA","VT","WA","WI","WV",
                                   "WY","Other","Unknown"};

for (int state = 0; state < 53; state++) 
	if (loan_state == adco_loan_state_vector[state])
		{
		state_vector[state] = 100.00;
		break;
		}                         
return;
}



#line 1 "get_tranche_modified_dur.INTEX_ASSET.for"                                                                                   
double INTEX_ASSET::get_tranche_modified_dur(int t, double par_val, double mkt_val)
{
if (done_with_tranche)
	return 0;

int period = 0;
double factor = 0.0;
double vprincipal[TRANCHE_ARRAY_DIMENSION];
double vinterest[TRANCHE_ARRAY_DIMENSION];
double modified_duration = 0.0;

memset(vprincipal, 0, TRANCHE_ARRAY_DIMENSION * sizeof(double));
memset(vinterest, 0, TRANCHE_ARRAY_DIMENSION * sizeof(double));

factor = par_val / balance[t];

pThis = this;
freezep = icmo_pmt_to_pmt_freeze(icmop);

for (period = 1; balance[t + period - 1] > 0; period++)
	{
	vprincipal[period] = principal[t + period] * factor;
	vinterest[period] = interest[t + period] * factor;
	}

icmop->icmot_matures = period - 1;
icmop->icmot_vprincipal = vprincipal;
icmop->icmot_vinterest = vinterest;
icmop->icmot_vcashflow = NULL;
icmop->icmot_vbalance = NULL;

icmo_forward_settle_date(icmop, 0,
	icmo_YyyyMmDd_addmo(settle_date, t + intex_cdu_months_offset, TRUE), 0);

// determine modified duration
icmo_stats(icmop,
		ICMO_TRANCHE_OVERRIDE,
		0,
		ICMOPY_PRICEAGG, 
		mkt_val);

modified_duration = icmop->icmot_moddurn;

// go back to the original settle date
icmo_forward_settle_date(icmop, 0, settle_date, 0);

icmo_pmt_to_pmt_thaw(icmop, freezep);
icmo_pmt_to_pmt_toss(&freezep);

return modified_duration;
}



#line 1 "get_tranche_wal.INTEX_ASSET.for"                                                                                   
double INTEX_ASSET::get_tranche_wal(int t, const xstring & proj_type, double par_val, double accr_int)
{
double calculated_wal = 0.0;

if (proj_type == "Actual")
	{
	xstring projection_type_saved = proj_defn;

	if (done_with_tranche)
		return 0.0;
	
	DEAL_DATA * uddp;
	uddp = reinterpret_cast <DEAL_DATA *> (icmop->icmo_user);
	
	pThis = this;
	freezep = icmo_pmt_to_pmt_freeze(icmop);
	intex_pool_number = 0;
	icmo_count_npools(icmop, save_pool_data_callback_function);

	proj_defn = "Market Value";
	icmo_count_npools(icmop, prepayment_setup_callback_function);
	intex_prepmt_function_mode = DO_PREPAY_TO_MATURITY;
	intex_collat_callback_mode = NO_CALLBACK;
	
	for (int period = t + intex_cdu_months_offset + 1; ; period++)
		if (icmo_pay_1period(icmop, period, NULL, NULL, NULL, NULL) == TRUE)
			break;
	
	// forward settle date to end of projection month
	icmo_forward_settle_date(icmop, 0, 
		icmo_YyyyMmDd_addmo(settle_date, t + intex_cdu_months_offset, TRUE), 0);
	
	icmo_stats(icmop,
		       intex_tranche_number,
		       0,
		       ICMOPY_PRICE100,
		       100);
	
	calculated_wal = icmop->icmot_wal;
	
	// go back to original settle date
	icmo_forward_settle_date(icmop, 0, settle_date, 0);
		       	
	intex_pool_number = 0;
	icmo_count_npools(icmop, restore_pool_data_callback_function);
	uddp->proj_type = proj_defn;
	icmo_pmt_to_pmt_thaw(icmop, freezep);
	icmo_pmt_to_pmt_toss(&freezep);

	proj_defn = projection_type_saved;
	}
else // cf_action == "Approximate"
	{
	int period = 0;
	double vprincipal[TRANCHE_ARRAY_DIMENSION];
	double vinterest[TRANCHE_ARRAY_DIMENSION];
	double modified_duration = 0.0;
	
	memset(vprincipal, 0, TRANCHE_ARRAY_DIMENSION * sizeof(double));
	memset(vinterest, 0, TRANCHE_ARRAY_DIMENSION * sizeof(double));

	pThis = this;
	freezep = icmo_pmt_to_pmt_freeze(icmop);
	
	double factor = par_val / balance[t];
	
	for (period = 1; balance[t + period - 1] > 0; period++)
		{
		vprincipal[period] = principal[t + period] * factor;
		vinterest[period] = interest[t + period] * factor;
		}

	icmop->icmot_matures = period - 1;
	icmop->icmot_vprincipal = vprincipal;
	icmop->icmot_vinterest = vinterest;
	icmop->icmot_vcashflow = NULL;
	icmop->icmot_vbalance = NULL;

	icmo_forward_settle_date(icmop, 0,
	   	icmo_YyyyMmDd_addmo(settle_date, t + intex_cdu_months_offset, TRUE), 0);

	icmop->icmot_days_accrued = -1;
	icmop->icmot_accrued = accr_int / 100.0;
	
	icmo_stats(icmop, ICMO_TRANCHE_OVERRIDE, 0, ICMOPY_PRICE100, 100.0);
	
	calculated_wal = icmop->icmot_wal;
	
	// go back to the original settle date 
	icmo_forward_settle_date(icmop, 0, settle_date, 0);
	
	icmo_pmt_to_pmt_thaw(icmop, freezep);
	icmo_pmt_to_pmt_toss(&freezep);
	}	

return calculated_wal;
}



#line 1 "index_rate.INTEX_ASSET.for"                                                                                   
double __cdecl INTEX_ASSET::index_rate(struct _ICMO *icmop, int ith_index, int ith_month)
{
int t = 0;
int cal_yr = 0;
int cal_mth = 0;
double Onemo = 0;
double Threemo = 0;
double Sixmo = 0;
double Oneyr = 0;
double Twoyr = 0;
double Threeyr = 0;
double Fiveyr = 0;
double Sevenyr = 0;
double Tenyr = 0;
double Thirtyyr = 0;
double ival = 0;
DEAL_DATA * uddp;

uddp = reinterpret_cast <DEAL_DATA *> (icmop->icmo_user);

t = uddp->t - intex_cdu_months_offset;

cal_yr = xint(this->cal_yr(t));
cal_mth = xint(this->cal_mth(t));

// For Net Yield and current month projections - use current scenario rates.
// For Market Value and Interest Savings projections - use forward scenario rates.

if (proj_defn != EXPERIENCE)
	{
	if (proj_defn == NET_YIELD)
		{
		if (ith_month <= uddp->t) // use past actual scenario rates
			{
			Onemo
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 0.083333, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
						
			Threemo
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 0.25, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Sixmo
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 0.50, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Oneyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 1.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Twoyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 2.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Threeyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 3.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Fiveyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 5.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Sevenyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 7.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Tenyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 10.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Thirtyyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 30.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			}
		else // use current scenario rate level
			{
			Onemo
			= rates->get_int_rate(t,
			            "Govt",
						GET_YIELD_RATE, 0.083333, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
						
			Threemo
			= rates->get_int_rate(t,
			            "Govt",
						GET_YIELD_RATE, 0.25, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Sixmo
			= rates->get_int_rate(t,
			            "Govt",
						GET_YIELD_RATE, 0.50, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Oneyr
			= rates->get_int_rate(t,
			            "Govt",
						GET_YIELD_RATE, 1.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Twoyr 
			= rates->get_int_rate(t,
			            "Govt",
						GET_YIELD_RATE, 2.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Threeyr
			= rates->get_int_rate(t,
			            "Govt",
						GET_YIELD_RATE, 3.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Fiveyr
			= rates->get_int_rate(t,
			            "Govt",
						GET_YIELD_RATE, 5.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Sevenyr
			= rates->get_int_rate(t,
			            "Govt",
						GET_YIELD_RATE, 7.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Tenyr
			= rates->get_int_rate(t,
			            "Govt",
						GET_YIELD_RATE, 10.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Thirtyyr
			= rates->get_int_rate(t,
			            "Govt",
						GET_YIELD_RATE, 30.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			}
		}
	else // MV Calculations
		{
		if (ith_month <= uddp->t) // use past actual scenario rates
			{
			Onemo
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 0.083333, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			
			Threemo
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 0.25, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Sixmo
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 0.50, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Oneyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 1.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Twoyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 2.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Threeyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 3.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Fiveyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 5.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Sevenyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 7.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Tenyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 10.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Thirtyyr
			= rates->get_int_rate(t + ith_month,
			            "Govt",
						GET_YIELD_RATE, 30.00, 0.0,
						NOMINAL_SEMIANNUAL,
						shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			}
		else // Use forward scenario rates
			{
			Onemo
			= rates->get_int_rate(t,
			            "Govt",
			            GET_FORWARD_RATE,			            
						(ith_month - uddp->t) / 12.0, 0.083333,
						NOMINAL_SEMIANNUAL, 
						shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			Threemo
			= rates->get_int_rate(t,
			            "Govt",
			            GET_FORWARD_RATE,			            
						(ith_month - uddp->t) / 12.0, 0.25,
						NOMINAL_SEMIANNUAL, 
						shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Sixmo
			= rates->get_int_rate(t,
			            "Govt",			
						GET_FORWARD_RATE,
						(ith_month - uddp->t) / 12.0, 0.50, 
						NOMINAL_SEMIANNUAL, 
						shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Oneyr
			= rates->get_int_rate(t,
			            "Govt",
						GET_FORWARD_RATE,
						(ith_month - uddp->t) / 12.0, 1.00, 
						NOMINAL_SEMIANNUAL, 
						shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Twoyr
			= rates->get_int_rate(t,
			            "Govt",
						GET_FORWARD_RATE,
						(ith_month - uddp->t) / 12.0, 2.00, 
						NOMINAL_SEMIANNUAL, 
						shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Threeyr
			= rates->get_int_rate(t,
			            "Govt",			
						GET_FORWARD_RATE,
						(ith_month - uddp->t) / 12.0, 3.00, 
						NOMINAL_SEMIANNUAL, 
						shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Fiveyr
			= rates->get_int_rate(t,
			            "Govt",
			            GET_FORWARD_RATE,
						(ith_month - uddp->t) / 12.0, 5.00, 
						NOMINAL_SEMIANNUAL, 
						shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Sevenyr
			= rates->get_int_rate(t,
			            "Govt",			
						GET_FORWARD_RATE,
						(ith_month - uddp->t) / 12.0, 7.00, 
						NOMINAL_SEMIANNUAL, 
						shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Tenyr
			= rates->get_int_rate(t,
			            "Govt",
			            GET_FORWARD_RATE,
						(ith_month - uddp->t) / 12.0, 10.00, 
						NOMINAL_SEMIANNUAL, 
						shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

			Thirtyyr
			= rates->get_int_rate(t,
			            "Govt",
			            GET_FORWARD_RATE,			
						(ith_month - uddp->t) / 12.0, 30.00, 
						NOMINAL_SEMIANNUAL, 
						shift_defn,0) * 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
			}
		}
	}
else // ADCO Initial Setup or regular Intex pay_1period projection
	{
	Onemo
	= rates->get_int_rate(- intex_cdu_months_offset + ith_month,
			    "Govt",
				GET_YIELD_RATE,
				0.083333, 0.0,
				NOMINAL_SEMIANNUAL,
				shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
				
	Threemo
	= rates->get_int_rate(- intex_cdu_months_offset + ith_month,
			    "Govt",
				GET_YIELD_RATE,
				0.25, 0.0,
				NOMINAL_SEMIANNUAL,
				shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	Sixmo
	= rates->get_int_rate(- intex_cdu_months_offset + ith_month,
			    "Govt",
				GET_YIELD_RATE,
				0.50, 0.0,
				NOMINAL_SEMIANNUAL,
				shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	Oneyr 
	= rates->get_int_rate(- intex_cdu_months_offset + ith_month,
			    "Govt",
				GET_YIELD_RATE,
				1.00, 0.0,
				NOMINAL_SEMIANNUAL,
				shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	Twoyr
	= rates->get_int_rate(- intex_cdu_months_offset + ith_month,
			    "Govt",
				GET_YIELD_RATE,
				2.00, 0.0,
				NOMINAL_SEMIANNUAL,
				shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	Threeyr
	= rates->get_int_rate(- intex_cdu_months_offset + ith_month,
			    "Govt",
				GET_YIELD_RATE,
				3.00, 0.0,
				NOMINAL_SEMIANNUAL,
				shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	Fiveyr
	= rates->get_int_rate(- intex_cdu_months_offset + ith_month,
			    "Govt",
				GET_YIELD_RATE,
				5.00, 0.0,
				NOMINAL_SEMIANNUAL,
				shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	Sevenyr
	= rates->get_int_rate(- intex_cdu_months_offset + ith_month,
			    "Govt",
				GET_YIELD_RATE,
				7.00, 0.0,
				NOMINAL_SEMIANNUAL,
				shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	Tenyr
	= rates->get_int_rate(- intex_cdu_months_offset + ith_month,
			    "Govt",
				GET_YIELD_RATE,
				10.00, 0.0,
				NOMINAL_SEMIANNUAL,
				shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

	Thirtyyr
	= rates->get_int_rate(- intex_cdu_months_offset + ith_month,
			    "Govt",
				GET_YIELD_RATE,
				30.00, 0.0,
				NOMINAL_SEMIANNUAL,
				shift_defn,0)* 100.0;//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
	}

switch (ith_index)
	{
	case ICMOI_3MO_TREAS:
		ival = Threemo;
		break;
	case ICMOI_6MO_TREAS:
		ival = Sixmo;
		break;
	case ICMOI_1YR_TREAS:
		ival = Oneyr;
		break;
	case ICMOI_2YR_TREAS:
		ival = Twoyr;
		break;
	case ICMOI_3YR_TREAS:
		ival = Threeyr;
		break;
	case ICMOI_5YR_TREAS:
		ival = Fiveyr;
		break;
	case ICMOI_7YR_TREAS:
		ival = Sevenyr;
		break;
	case ICMOI_10YR_TREAS:
		ival = Tenyr;
		break;
	case ICMOI_30YR_TREAS:
		ival = Thirtyyr;
		break;
	case ICMOI_1MO_LIBOR:
		ival = Onemo * 1.050115 + 0.357226;
		break;
	case ICMOI_3MO_LIBOR:
		ival = Threemo * 1.052045 + 0.585975;
		break;
	case ICMOI_6MO_LIBOR:
		ival = Sixmo * 1.067413 + 0.391367;
		break;
	case ICMOI_1YR_LIBOR: 
		ival = Sixmo * 1.039623 + 0.705342;
		break;
	case ICMOI_PRIME:
		ival = Oneyr * 1.106180 + 0.924228;
		break;
	case ICMOI_COFI11:
	case ICMOI_COF:
		ival = Threemo * 0.262146765 + 3.472036;
		break;
	case ICMOI_CONTRACT:
		ival = Thirtyyr * 1.224819 - 0.388598;
		break;
	case ICMOI_6MO_CD:
		ival = Sixmo * 1.037652 + 0.053805;
		break;
	case ICMOI_MONEY_MKT: // Use 6 month rate
		ival = Sixmo * 0.961567 + 0.366702;
		break;
	case ICMOI_YEN:
	case ICMOI_MISC_1:
	case ICMOI_MISC_2:
	case ICMOI_MISC_3: // Use 6 month rate
		ival = Sixmo;
		break;
	default: // Use 6 month rate
		ival = Sixmo;
		break;
	}

return ival;
}



#line 1 "init_deal_detail.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::init_deal_detail(void)
{
#define OPT_DealCat(d) ((d==ICMODEALCAT_AGENCY_ADMIN)?"Issued by FNMA/FHLMC or GNMA":((d==ICMODEALCAT_PRIVATE)?"Private Issue, agency-backed":(d==ICMODEALCAT_WHOLE_LOAN)?"Private Issue, non-conforming":"NA"))
#define OPT_SettleType(d) ((d==ICMOSETTL_NORMAL)?"FNMA/privates and whole loans":((d==ICMOSETTL_FHLMC)?"FHLMC 75-delay deals":(d==ICMOSETTL_FHLMC_GOLD)?"FHLMC Gold 45-delay deals":"NA"))
#define OPT_CollatFreq(d) ((d==1)?"Annual":((d==2)?"Semi-Annual":((d==4)?"Quarterly":"Monthly")))
#define OPT_AssetType(d) ((d==1)?"Mortgage":((d==2)?"CMO":"NA"))

int numpools = 0;
int numtranches = 0;
short trno = 0;

pThis = this;
numpools = icmo_count_npools(icmop, NULL);

for (trno = 0; trno<icmop->icmo_n_tranches; trno++)
	{
	if (icmop->icmo_tranche_pseudo_types[trno] == 0)
		numtranches+=1;
	}

ITXFile << endl
		<< "Detail Information" << endl
		<< "AssetID," << asset_id << endl
		<< "ProjectionTaskLoop," << proj_task_loop_num << endl
		<< endl
		<< "Basic Deal Information" << endl
		<< "IntexDealName," << icmop->icmo_dealname << endl
		<< "OrigDealName," << icmop->icmo_dealname_orig << endl
		<< "DealIssuer," << icmop->icmo_deal_issuer << endl
		<< "GenusOfCMO," << OPT_DealCat(icmop->icmo_deal_category) << endl
		<< "SettlementType," << OPT_SettleType(icmop->icmo_settle_type) << endl
		<< "OriginalSettleDate," << icmop->icmo_deal_settle_date << endl
		<< "OriginalBalance," << icmop->icmo_deal_origbal << endl
		<< "BalanceAtCDUDate," << icmop->icmo_deal_curbal << endl
		<< "BaseCDUDate," << icmop->icmo_base_cdu_date << endl
		<< "LatestCDUDate," << icmop->icmo_latest_cdu_date << endl
		<< "PaymentDay," << icmop->icmo_pay_dd << endl
		<< "CollateralFreq," << OPT_CollatFreq(icmop->icmo_collat_freq) << endl
		<< "RemainMthsAtCDUDate," << icmop->icmo_remterm << endl
		<< "NumberOfCollateralPoolsCreated," << numpools << endl
		<< "CollatCategory," << category_id << endl;

if (stricmp(icmop->icmo_tranche_types[intex_tranche_number], "MBSPOOL"))
	ITXFile << "Number of Tranches in Deal," << numtranches << endl;

// Capture some ABS Summary detail
if (icmop->icmo_deal_category == ICMODEALCAT_WHOLE_LOAN
	&& icmop->icmo_assetback_type != ICMOASSETBACK_LOAN
	&& icmop->icmo_assetback_type != ICMOASSETBACK_COMMERCIAL)
	{
	xstring abs_type;

	switch (icmop->icmo_assetback_type)
		{
		case ICMOASSETBACK_CREDITCARD:
			abs_type = "Credit Card";
			break;
		case ICMOASSETBACK_AUTOLOAN:
			abs_type = "Auto Loan";
			break;
		case ICMOASSETBACK_HOMEEQUITY:
			abs_type = "Home Equity Loan";
			break;
		case ICMOASSETBACK_MANUHOUSE:
			abs_type = "Manufactured Housing Loans";
			break;
		default:
			abs_type = "Other Asset Backeds";
			break;
		}

	ITXFile << "Asset Backed Type," << abs_type << endl;
	}

ITXFile << endl << "Pool Information" << endl;

// Call function to print detail information for each pool 
icmo_count_npools(icmop, initial_pool_detail_callback_function);

// Setup initial asset detail
ITXFile << "Owned Asset Information" << endl
		<< "Name," << icmop->icmo_tranche_names[intex_tranche_number] << endl
		<< "Type," << icmop->icmo_tranche_types[intex_tranche_number] << endl
		<< "OrigBal," << icmop->icmo_tranche_origbals[intex_tranche_number] << endl
		<< "BalAtCDUDate," << icmop->icmo_tranche_curbals[intex_tranche_number] << endl;
}



#line 1 "init_pool_detail.INTEX_ASSET.for"                                                                                   
void __cdecl INTEX_ASSET::init_pool_detail(struct _ICMO * icmop, char * dealname, struct _POOL_INFO * pip, int ith_pool)
{
xstring pool_type;
xstring pool_agency;
xstring pool_amort;

switch (pip->pi_agency)
	{
	case ICMOAGENCY_GNMA:
		pool_agency = "GNMA";
		break;
	case ICMOAGENCY_FNMA:
		pool_agency = "FNMA";
		break;
	case ICMOAGENCY_FHLMC:
		pool_agency = "FHLMC";
		break;
	case ICMOAGENCY_GNMA2:
		pool_agency = "GNMA 2";
		break;
	case ICMOAGENCY_WL:
		pool_agency = "Generic Whole Loan";
		break;
	case ICMOAGENCY_PHM:
		pool_agency = "Prudential Home Mortgage Loan";
		break;
	case ICMOAGENCY_RFC:
		pool_agency = "Residential Funding Corp Loan";
		break;
	case ICMOAGENCY_RYL:
		pool_agency = "Ryland Loan";
		break;
	case ICMOAGENCY_ADV:
		pool_agency = "Special Rylan-serviced Loan";
		break;
	case ICMOAGENCY_CWF:
		pool_agency = "Advanta Loan";
		break;
	case ICMOAGENCY_CWC:
		pool_agency = "Countrywide Funding Loan";
		break;
	case ICMOAGENCY_INM:
		pool_agency = "Independent National Mortgage Loan";
		break;
	case ICMOAGENCY_CMF:
		pool_agency = "Chase Mortgage Finance Loan";
		break;
	case ICMOAGENCY_CAP:
		pool_agency = "Capstead Loan";
		break;
	case ICMOAGENCY_CMC:
		pool_agency = "CMS Securities Loan";
		break;
	case ICMOAGENCY_GEC:
		pool_agency = "General Electric Credit Loan";
		break;
	case ICMOAGENCY_SMS:
		pool_agency = "Sears Mortgage Securities Loan";
		break;
	default:
		pool_agency = "Undefined";
	}

switch (pip->pi_cftype)
	{
	case ICMOCFTYPE_FIX_10YR:
	case ICMOCFTYPE_FIX_15YR:
	case ICMOCFTYPE_FIX_20YR:
	case ICMOCFTYPE_FIX_25YR:
	case ICMOCFTYPE_FIX_30YR:
	case ICMOCFTYPE_FIX_35YR:
	case ICMOCFTYPE_FIX_40YR:
	  pool_type = "Fixed";
	break;
	case ICMOCFTYPE_BLN_5YR:
	case ICMOCFTYPE_BLN_7YR:
	case ICMOCFTYPE_BLN_OTHER:
	  pool_type = "Balloon";
	break;
	case ICMOCFTYPE_ARM_LIBOR_1MO:
	case ICMOCFTYPE_ARM_LIBOR_3MO:
	case ICMOCFTYPE_ARM_LIBOR_6MO:
	case ICMOCFTYPE_ARM_LIBOR_1YR:
	case ICMOCFTYPE_ARM_CMT_1YR:
	case ICMOCFTYPE_ARM_CMT_2YR:
	case ICMOCFTYPE_ARM_CMT_3YR:
	case ICMOCFTYPE_ARM_CMT_5YR:
	case ICMOCFTYPE_ARM_CMT_7YR:
	case ICMOCFTYPE_ARM_CMT_10YR:
	case ICMOCFTYPE_ARM_CMT_30YR:
	case ICMOCFTYPE_ARM_COFI_11:
	case ICMOCFTYPE_ARM_PRIME:
	case ICMOCFTYPE_ARM_MONEY_MKT:
	  pool_type = "ARM";
	break;
	case ICMOCFTYPE_STEPUP:
	  pool_type = "Step-Up";
	break;
	case ICMOCFTYPE_GPM:
	  pool_type = "GPM";
	break;
	case ICMOCFTYPE_TPM:
	  pool_type = "TPM";
	break;
	case ICMOCFTYPE_REMIC:
	  pool_type = "Remic";
	break;
	case ICMOCFTYPE_TREAS_BOND:
	  pool_type = "Bond";
	break;
	default:
	  pool_type = "Undefined";
	}

switch(pip->pi_amort_type)
	{
	case LOAN_AMORT_REGULAR:
	  pool_amort = "Level-Pay";
	break;
	case LOAN_AMORT_RULE78:
	  pool_amort = "Rule of 78";
	break;
	case LOAN_AMORT_NONE:
	  pool_amort = "None or Deferred";
	break;
	case LOAN_AMORT_SCHED:
	  pool_amort = "Balance Schedule";
	break;
	case LOAN_AMORT_MINPMT:
	  pool_amort = "None-Minimum Dollar Payment";
	break;
	case LOAN_AMORT_SCHED_CURPMT:
	  pool_amort = "Current Schedule";
	break;
	default:
	  pool_amort = "Undefined";
	}

ITXFile << "PoolNumber," << ith_pool << endl
		<< "Agency," << pool_agency << endl
		<< "Type," << pool_type << endl
		<< "OrigMths," << pip->pi_origterm << endl
		<< "OrigBalance," << pip->pi_origbal << endl
		<< "RemainMthsAtCDUDate," << pip->pi_remterm << endl
		<< "CurBalanceAtCDUDate," << pip->pi_origbal * pip->pi_factors[1] << endl
		<< "OutstandingPrinFactorAtCDUDate," << pip->pi_factors[1] << endl
		<< "NetCoupon," << pip->pi_netcoupon / 100.0 << endl 
		<< "ServiceFee," << pip->pi_servfee / 100.0 << endl
		<< "PctPrinPassedThrough," << pip->pi_pctprincipal << endl 
		<< "PctIntPassedThrough," << pip->pi_pctinterest << endl
		<< "AmortizationType," << pool_amort << endl 
		<< "OriginalMthsTillAmortization," << pip->pi_noamort_mos << endl
		<< "MthsSinceIssueAtCDUDate," << pip->pi_age_since_issue << endl
		<< "ReinvDays," << static_cast <int> (pip->pi_ndays_reinv) << endl;

if (pip->pi_armp != NULL)
	{
	#define OPT_ARMTeaser(d) ((d==TRUE)?"Yes":"No")
	#define OPT_ARMConv(d)   ((d==TRUE)?"Yes":"No")
	xstring idxname;

	switch(pip->pi_armp->armi_index)
		{
		case ICMOI_1MO_LIBOR:
			idxname = "1 Month LIBOR";
			break;
		case ICMOI_3MO_LIBOR:
			idxname = "3 Month LIBOR";
			break;
		case ICMOI_6MO_LIBOR:
			idxname = "6 Month LIBOR";
			break;
		case ICMOI_1YR_LIBOR:
			idxname = "1 Year LIBOR";
			break;
		case ICMOI_3MO_TREAS:
			idxname = "3 Month Treas";
			break;
		case ICMOI_1YR_TREAS:
			idxname = "1 Year Treas";
			break;
		case ICMOI_5YR_TREAS:
			idxname = "5 Year Treas";
			break;
		case ICMOI_7YR_TREAS:
			idxname = "7 Year Treas";
			break;
		case ICMOI_10YR_TREAS:
			idxname = "10 Year Treas";
			break;
		case ICMOI_COFI11:
			idxname = "11 Dist COF";
			break;
		case ICMOI_PRIME:
			idxname = "Bank Prime";
			break;
		case ICMOI_3YR_TREAS:
			idxname = "3 Year Treas";
			break;
		case ICMOI_2YR_TREAS:
			idxname = "2 Year Treas";
			break;
		case ICMOI_6MO_TREAS:
			idxname = "6 Month Treas";
			break;
		case ICMOI_30YR_TREAS:
			idxname = "30 Year Treas";
			break;
		case ICMOI_CONTRACT:
			idxname = "Gen Contract";
			break;
		case ICMOI_COF:
			idxname = "Gen COF";
			break;
		case ICMOI_6MO_CD:
			idxname = "6 Month CD";
			break;
		case ICMOI_MONEY_MKT:
			idxname = "Money Mkt";
			break;
		case ICMOI_YEN:
		case ICMOI_MISC_1:
		case ICMOI_MISC_2:
		case ICMOI_MISC_3:
			idxname = "Unknown";
			break;
		default:
			idxname = "Unknown";
		}

	ITXFile << "ARMIndex," << idxname << endl
			<< "ARMNetMargin," << pip->pi_armp->armi_netmargin / 100.00 << endl
			<< "ARMInTeaser," << OPT_ARMTeaser(pip->pi_armp->armi_in_teaser) << endl
			<< "ARMConvertable," << OPT_ARMConv(pip->pi_armp->armi_convertable) << endl
			<< "ARMNxtRateReset," << pip->pi_armp->armi_ntillreset << endl
			<< "ARMRateResetPer," << pip->pi_armp->armi_resetper << endl
			<< "ARMNxtPmtReset," << pip->pi_armp->armi_paym_ntillreset << endl
			<< "ARMPmtResetPer," << pip->pi_armp->armi_paym_resetper << endl
			<< "ARMMaxRate," << pip->pi_armp->armi_caplife / 100.0 << endl
			<< "ARMMaxResetRate," << pip->pi_armp->armi_capresetper /100.0 << endl
			<< "ARMMinRate," << pip->pi_armp->armi_flrlife /100.0 << endl
			<< "ARMMinResetRate," << pip->pi_armp->armi_flrresetper /100.0 << endl;
   }

ITXFile << "CPR Prepay History:" << endl
		<< "LastMth," << pip->pi_cpr.prep_1mo << endl
		<< "Last12Mths," << pip->pi_cpr.prep_12mo << endl
		<< "Lifetime," << pip->pi_cpr.prep_life << endl
		<< endl;
}



#line 1 "initialize_asset.INTEX_ASSET.for"                                                                                   
int INTEX_ASSET::initialize_asset(void)
{
// perform intex initializations
xstring error_message = "";

if (is_first_proj_task_loop
	&& is_intex_projection)
	issue_messages = true;
else
	issue_messages = false;	
	
// clean up any existing data from initial parsing
resetValues();
clear_asset_data();

if (!valid_asset_flag("Yes", error_message))
	{
	clear_asset_data();

	if (isMainModel)
		throw NonFatalError(error_message);

	return 0;
	}

// turn off the done_with_tranche flag
done_with_tranche = 0;

return 1;
}



#line 1 "initialize_pool_data.INTEX_ASSET.for"                                                                                   
void __cdecl INTEX_ASSET::initialize_pool_data(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
POOL_DATA *updp;

if (pip->pi_user == NULL)
	{
	updp = new POOL_DATA;
	pip->pi_user = reinterpret_cast <char *> (updp);

	updp->vcpcashflow = new double[icmop->icmo_max_cf_vectsize + 1];
	memset(updp->vcpcashflow, 0, (icmop->icmo_max_cf_vectsize + 1) * sizeof(double));

	updp->vcpbalance = new double[icmop->icmo_max_cf_vectsize + 1];
	memset(updp->vcpbalance, 0, (icmop->icmo_max_cf_vectsize + 1) * sizeof(double));

	updp->vcpprincipal = new double[icmop->icmo_max_cf_vectsize + 1];
	memset(updp->vcpprincipal, 0, (icmop->icmo_max_cf_vectsize + 1) * sizeof(double));

	updp->vcpinterest = new double[icmop->icmo_max_cf_vectsize + 1];
	memset(updp->vcpinterest, 0, (icmop->icmo_max_cf_vectsize + 1) * sizeof(double));

	updp->smm_forecast = new double[600];
	memset(updp->smm_forecast, 0, 600 * sizeof(double));

	updp->remterm = pip->pi_remterm;
	updp->poolnum = ith_pool;

#if INTEX_CASH_FLOW_POOL_DETAIL
	if (intex_detail_wanted
		&& (ith_pool == INTEX_CASH_FLOW_POOL_DETAIL || INTEX_CASH_FLOW_POOL_DETAIL == -1))
		{
		log_screen << "itx2-> pool#=" << setw(3) << ith_pool
				<< " term=" << setw(3) << updp->remterm
				<< " prepay_mode=" << (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD ? "DO_PREPAY_ONE_PERIOD"
									: (intex_prepmt_function_mode == DO_PREPAY_TO_MATURITY ? "DO_PREPAY_TO_MATURITY"
									: (intex_prepmt_function_mode == NO_PREPAYMENTS ? "NO_PREPAYMENTS" : "???")))
				<< " |initialize_pool_data"
				<< MSG_USER;
		}
#endif

	}
else
	updp = (POOL_DATA *) pip->pi_user;

// Initialize ISPV and RefRate variables each month
updp->cppresvalue = 0.0;
updp->refinrate = 0.0;

return;
}



#line 1 "initialize_yld_curve.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::initialize_yld_curve(void)
{
// Initialize yield curve nodes. These will be visible
// within index function because the ICMO struct is
// available there.

icmop->icmo_yldcrv_n_nodes = N_YLDCRV_NODES;
icmop->icmo_yldcrv_nodes   = vyldcrv_nodes;
icmop->icmo_yldcrv_vals    = vyldcrv_vals;

vyldcrv_nodes[0] =  0.25;
vyldcrv_nodes[1] =  0.5;
vyldcrv_nodes[2] =  1.0;
vyldcrv_nodes[3] =  2.0;
vyldcrv_nodes[4] =  3.0;
vyldcrv_nodes[5] =  5.0;
vyldcrv_nodes[6] =  7.0;
vyldcrv_nodes[7] = 10.0;
vyldcrv_nodes[8] = 30.0;
}



#line 1 "int_savings_pv_cash_flow_setup.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::int_savings_pv_cash_flow_setup(int t)
{
DEAL_DATA * uddp;
int intex_proj_period;
int period;

if (t == 0
	&& intex_cdu_months_offset > 0
	&& preliminary_projection_complete)
	return;

#if INTEX_CASH_FLOW_DETAIL
if (intex_detail_wanted)
	{
	log_screen.setf(ios::fixed, ios::floatfield);
	log_screen << "itx-> t=" << t
			<< " beg intex->int_savings_pv_cash_flow_setup"
			<< MSG_USER;
	}
#endif

pThis = this;

uddp = reinterpret_cast <DEAL_DATA *> (icmop->icmo_user);
uddp->t = t + intex_cdu_months_offset;

// ISPV calculations use a market value projection type
proj_defn = MARKET_VALUE;

if (done_with_tranche)
	return;

if (t == -intex_cdu_months_offset)
	intex_proj_period = 1;
else
	intex_proj_period = t + intex_cdu_months_offset;

setup_yld_curve(t, NO_SHIFT /* shift_defn */);

// Set current period reinvestment rate 
intex_reinv_rates[0] = vyldcrv_vals[0]; 
icmop->icmo_vcashflow_reinv_rates = intex_reinv_rates;

// Setup CP asset 
setup_cp_data(0); 

freezep = icmo_pmt_to_pmt_freeze(icmop);

intex_collat_callback_mode = CASHFLOW_CALLBACK;
intex_prepmt_function_mode = NO_PREPAYMENTS;

if (prepmt_model_defn == SPLINE)
	{
	icmo_count_npools(icmop, cp_refinancing_rate_callback_function);

	// Project for Interest Savings Present Value 
	for (period = intex_proj_period; period <= icmop->icmo_remterm; period++)
		icmo_pay_1period(icmop, period, NULL, NULL, NULL, NULL);
	}
else // Andrew Davidson Prepayments 
	{
	// Project for Collateral Scheduled Payments 
	for (period = intex_proj_period; period <= intex_proj_period; period++)
		icmo_pay_1period(icmop, period, NULL, NULL, NULL, NULL);
	}

// Restore to current projection period 
icmo_pmt_to_pmt_thaw(icmop, freezep);
icmo_pmt_to_pmt_toss(&freezep);

// reset to experience projection
proj_defn = EXPERIENCE;

#if INTEX_CASH_FLOW_DETAIL
if (intex_detail_wanted)
	{
	log_screen.setf(ios::fixed, ios::floatfield);
	log_screen << "itx-> t=" << t
			<< " end intex->int_savings_pv_cash_flow_setup"
			<< MSG_USER;
	}
#endif

return;
}



#line 1 "load_library.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::load_library()
{
int compiler_defn = 32;
#ifdef WIN64
compiler_defn = 64;
#endif

if (compiler_defn == 32)
	hIntexDLL = LoadLibrary((xstring) cmo_dll);
else
	hIntexDLL = LoadLibrary((xstring) cmo_dll_64);

if (hIntexDLL != NULL)
	{
    icmo_init = (icmo_init_func *)GetProcAddress(hIntexDLL, "icmo_init");
    icmo_finalize = (icmo_finalize_func *)GetProcAddress(hIntexDLL, "icmo_finalize");
    icmo_initialized = (icmo_initialized_func *)GetProcAddress(hIntexDLL, "icmo_initialized");
    icmo_finalized = (icmo_finalized_func *)GetProcAddress(hIntexDLL, "icmo_finalized"); 
    icmo_env_set_attr = (icmo_env_set_attr_func *)GetProcAddress(hIntexDLL, "icmo_env_set_attr");
	icmo_env_get_attr = (icmo_env_get_attr_func *)GetProcAddress(hIntexDLL, "icmo_env_get_attr");
	icmo_mpi_message_set = (icmo_mpi_message_set_func *)GetProcAddress(hIntexDLL, "icmo_mpi_message_set");
	icmo_mpi_message_get = (icmo_mpi_message_get_func *)GetProcAddress(hIntexDLL, "icmo_mpi_message_get");
	icmo_setup_icmomiscp = (icmo_setup_icmomiscp_func *)GetProcAddress(hIntexDLL, "icmo_setup_icmomiscp");
	icmo_deal = (icmo_deal_func *)GetProcAddress(hIntexDLL, "icmo_deal");
	icmo_free = (icmo_free_func *)GetProcAddress(hIntexDLL, "icmo_free");
	icmo_parse = (icmo_parse_func *)GetProcAddress(hIntexDLL, "icmo_parse");
	icmo_index_set = (icmo_index_set_func *)GetProcAddress(hIntexDLL, "icmo_index_set");
	icmo_set_index_forecast = (icmo_set_index_forecast_func *)GetProcAddress(hIntexDLL, "icmo_set_index_forecast");
	icmo_make_struct = (icmo_make_struct_func *)GetProcAddress(hIntexDLL, "icmo_make_struct");
	icmo_free_struct = (icmo_free_struct_func *)GetProcAddress(hIntexDLL, "icmo_free_struct");
	icmo_currency_set = (icmo_currency_set_func *)GetProcAddress(hIntexDLL, "icmo_currency_set");
	icmo_cashflows = (icmo_cashflows_func *)GetProcAddress(hIntexDLL, "icmo_cashflows");
	icmo_tranchenum = (icmo_tranchenum_func *)GetProcAddress(hIntexDLL, "icmo_tranchenum");
	icmo_stats = (icmo_stats_func *)GetProcAddress(hIntexDLL, "icmo_stats");
	icmo_month2date = (icmo_month2date_func *)GetProcAddress(hIntexDLL, "icmo_month2date");
	icmo_date2month = (icmo_date2month_func *)GetProcAddress(hIntexDLL, "icmo_date2month");
	icmo_fmtdate = (icmo_fmtdate_func *)GetProcAddress(hIntexDLL, "icmo_fmtdate");
	icmo_tr_month2date = (icmo_tr_month2date_func *)GetProcAddress(hIntexDLL, "icmo_tr_month2date");
	icmo_tr_date2month = (icmo_tr_date2month_func *)GetProcAddress(hIntexDLL, "icmo_tr_date2month");
	icmo_tr_fmtdate = (icmo_tr_fmtdate_func *)GetProcAddress(hIntexDLL, "icmo_tr_fmtdate");
	icmo_fmtprice = (icmo_fmtprice_func *)GetProcAddress(hIntexDLL, "icmo_fmtprice");
	icmo_get_collat_cf = (icmo_get_collat_cf_func *)GetProcAddress(hIntexDLL, "icmo_get_collat_cf");
	icmo_set_pmt_to_pmt_mode = (icmo_set_pmt_to_pmt_mode_func *)GetProcAddress(hIntexDLL, "icmo_set_pmt_to_pmt_mode");
	icmo_pay_1period = (icmo_pay_1period_func *)GetProcAddress(hIntexDLL, "icmo_pay_1period");
	icmo_pay_1period_info = (icmo_pay_1period_info_func *)GetProcAddress(hIntexDLL, "icmo_pay_1period_info");
	icmo_buy_collat = (icmo_buy_collat_func *)GetProcAddress(hIntexDLL, "icmo_buy_collat");
	icmo_sell_collat = (icmo_sell_collat_func *)GetProcAddress(hIntexDLL, "icmo_sell_collat");
	icmo_replace_collat_list = (icmo_replace_collat_list_func *)GetProcAddress(hIntexDLL, "icmo_replace_collat_list");
	icmo_apply_collat_transact_set = (icmo_apply_collat_transact_set_func *)GetProcAddress(hIntexDLL, "icmo_apply_collat_transact_set");
	icmo_decluster_pools = (icmo_decluster_pools_func *)GetProcAddress(hIntexDLL, "icmo_decluster_pools");
	icmo_cluster_pools = (icmo_cluster_pools_func *)GetProcAddress(hIntexDLL, "icmo_cluster_pools");
	icmo_override_coll_cf = (icmo_override_coll_cf_func *)GetProcAddress(hIntexDLL, "icmo_override_coll_cf");
	icmo_convert_prepay_units = (icmo_convert_prepay_units_func *)GetProcAddress(hIntexDLL, "icmo_convert_prepay_units");
	icmo_convert_yield_units = (icmo_convert_yield_units_func *)GetProcAddress(hIntexDLL, "icmo_convert_yield_units");
	icmo_set_aggunion_id = (icmo_set_aggunion_id_func *)GetProcAddress(hIntexDLL, "icmo_set_aggunion_id");
	icmo_get_aggunion = (icmo_get_aggunion_func *)GetProcAddress(hIntexDLL, "icmo_get_aggunion");

	icmo_find_abs_summary_info = (icmo_find_abs_summary_info_func *)GetProcAddress(hIntexDLL, "icmo_find_abs_summary_info");
	icmo_disc_margin_over_which_index = (icmo_disc_margin_over_which_index_func *)GetProcAddress(hIntexDLL, "icmo_disc_margin_over_which_index");
	icmo_version_chk = (icmo_version_chk_func *)GetProcAddress(hIntexDLL, "icmo_version_chk");
	icmo_version_validate = (icmo_version_validate_func *)GetProcAddress(hIntexDLL, "icmo_version_validate");
	icmo_schedule_met = (icmo_schedule_met_func *)GetProcAddress(hIntexDLL, "icmo_schedule_met");
	icmo_get_schedule = (icmo_get_schedule_func *)GetProcAddress(hIntexDLL, "icmo_get_schedule");
	icmo_schedule_dependecy = (icmo_schedule_dependecy_func *)GetProcAddress(hIntexDLL, "icmo_schedule_dependecy");
	icmo_effective_collars = (icmo_effective_collars_func *)GetProcAddress(hIntexDLL, "icmo_effective_collars");
	icmo_forward_cashflows = (icmo_forward_cashflows_func *)GetProcAddress(hIntexDLL, "icmo_forward_cashflows");
	icmo_forward_settle_date = (icmo_forward_settle_date_func *)GetProcAddress(hIntexDLL, "icmo_forward_settle_date");
	icmo_reinv_cashflows = (icmo_reinv_cashflows_func *)GetProcAddress(hIntexDLL, "icmo_reinv_cashflows");
	icmo_use_bv_coll = (icmo_use_bv_coll_func *)GetProcAddress(hIntexDLL, "icmo_use_bv_coll");
	icmo_collat_type = (icmo_collat_type_func *)GetProcAddress(hIntexDLL, "icmo_collat_type");
	icmo_tranche_blocks = (icmo_tranche_blocks_func *)GetProcAddress(hIntexDLL, "icmo_tranche_blocks");
	icmo_pmt_to_pmt_freeze = (icmo_pmt_to_pmt_freeze_func *)GetProcAddress(hIntexDLL, "icmo_pmt_to_pmt_freeze");
	icmo_pmt_to_pmt_refreeze = (icmo_pmt_to_pmt_refreeze_func *)GetProcAddress(hIntexDLL, "icmo_pmt_to_pmt_refreeze");
	icmo_pmt_to_pmt_thaw = (icmo_pmt_to_pmt_thaw_func *)GetProcAddress(hIntexDLL, "icmo_pmt_to_pmt_thaw");
	icmo_pmt_to_pmt_toss = (icmo_pmt_to_pmt_toss_func *)GetProcAddress(hIntexDLL, "icmo_pmt_to_pmt_toss");
	icmo_scenario_vect = (icmo_scenario_vect_func *)GetProcAddress(hIntexDLL, "icmo_scenario_vect");
	icmo_show_clock = (icmo_show_clock_func *)GetProcAddress(hIntexDLL, "icmo_show_clock");
	icmo_count_npools = (icmo_count_npools_func *)GetProcAddress(hIntexDLL, "icmo_count_npools");
	icmo_get_currency = (icmo_get_currency_func *)GetProcAddress(hIntexDLL, "icmo_get_currency");
	icmo_addl_info = (icmo_addl_info_func *)GetProcAddress(hIntexDLL, "icmo_addl_info");
	icmo_setup_commercialop_by_id = (icmo_setup_commercialop_by_id_func *)GetProcAddress(hIntexDLL, "icmo_setup_commercialop_by_id");
	icmo_adjust_arm_index = (icmo_adjust_arm_index_func *)GetProcAddress(hIntexDLL, "icmo_adjust_arm_index");

	icmo_YyyyMmDd_add = (icmo_YyyyMmDd_add_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_add");
	icmo_YyyyMmDd_addmo = (icmo_YyyyMmDd_addmo_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_addmo");
	icmo_YyyyMmDd_diffmo = (icmo_YyyyMmDd_diffmo_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_diffmo");
	icmo_YyyyMmDd_ddset = (icmo_YyyyMmDd_ddset_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_ddset");
	icmo_YyyyMmDd_day = (icmo_YyyyMmDd_day_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_day");
	icmo_YyyyMmDd_valid = (icmo_YyyyMmDd_valid_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_valid");
	icmo_YyyyMmDd_today = (icmo_YyyyMmDd_today_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_today");
	icmo_YyyyMmDd_fmt = (icmo_YyyyMmDd_fmt_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_fmt");
	icmo_YyyyMmDd_conv_to_yymm = (icmo_YyyyMmDd_conv_to_yymm_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_conv_to_yymm");
	icmo_YyyyMmDd_conv_from_yymm = (icmo_YyyyMmDd_conv_from_yymm_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_conv_from_yymm");
	icmo_YyyyMmDd_conv_from_y_m_d = (icmo_YyyyMmDd_conv_from_y_m_d_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_conv_from_y_m_d");
	icmoutil_YyyyMmDd_bd_adj = (icmoutil_YyyyMmDd_bd_adj_func *)GetProcAddress(hIntexDLL, "icmoutil_YyyyMmDd_bd_adj");
	icmo_YyyyMmDd_bd_adj = (icmo_YyyyMmDd_bd_adj_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_bd_adj");
	icmo_YyyyMmDd_seqno = (icmo_YyyyMmDd_seqno_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_seqno");
	icmo_date_convert = (icmo_date_convert_func *)GetProcAddress(hIntexDLL, "icmo_date_convert");
	icmo_daycount = (icmo_daycount_func *)GetProcAddress(hIntexDLL, "icmo_daycount");
	icmo_YyyyMmDd_year_frac = (icmo_YyyyMmDd_year_frac_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_year_frac");

	icmodb_init = (icmodb_init_func *)GetProcAddress(hIntexDLL, "icmodb_init");
	icmodb_setup_cusip_tbls = (icmodb_setup_cusip_tbls_func *)GetProcAddress(hIntexDLL, "icmodb_setup_cusip_tbls");
	icmodb_setup_altid_tbls = (icmodb_setup_altid_tbls_func *)GetProcAddress(hIntexDLL, "icmodb_setup_altid_tbls");
	icmodb_cusip_to_bond = (icmodb_cusip_to_bond_func *)GetProcAddress(hIntexDLL, "icmodb_cusip_to_bond");
	icmodb_altid_search = (icmodb_altid_search_func *)GetProcAddress(hIntexDLL, "icmodb_altid_search");
	icmodb_dealstr_to_bond = (icmodb_dealstr_to_bond_func *)GetProcAddress(hIntexDLL, "icmodb_dealstr_to_bond");
	icmodb_bond_info = (icmodb_bond_info_func *)GetProcAddress(hIntexDLL, "icmodb_bond_info");
	icmodb_find_init = (icmodb_find_init_func *)GetProcAddress(hIntexDLL, "icmodb_find_init");
	icmodb_find = (icmodb_find_func *)GetProcAddress(hIntexDLL, "icmodb_find");
	icmodbrec_datahist_clean = (icmodbrec_datahist_clean_func *)GetProcAddress(hIntexDLL, "icmodbrec_datahist_clean");
	icmodb_free = (icmodb_free_func *)GetProcAddress(hIntexDLL, "icmodb_free");
	icmo_dbstatus = (icmo_dbstatus_func *)GetProcAddress(hIntexDLL, "icmo_dbstatus");
	icmo_dbstat_init = (icmo_dbstat_init_func *)GetProcAddress(hIntexDLL, "icmo_dbstat_init");
	icmo_dbstat_check = (icmo_dbstat_check_func *)GetProcAddress(hIntexDLL, "icmo_dbstat_check");
	icmo_dbstat_free = (icmo_dbstat_free_func *)GetProcAddress(hIntexDLL, "icmo_dbstat_free");
	icmo_isr_play = (icmo_isr_play_func *)GetProcAddress(hIntexDLL, "icmo_isr_play");

	icmo_parser_open = (icmo_parser_open_func *)GetProcAddress(hIntexDLL, "icmo_parser_open");
	icmo_parser = (icmo_parser_func *)GetProcAddress(hIntexDLL, "icmo_parser");
	icmo_parser_fseek = (icmo_parser_fseek_func *)GetProcAddress(hIntexDLL, "icmo_parser_fseek");
	icmo_parser_close = (icmo_parser_close_func *)GetProcAddress(hIntexDLL, "icmo_parser_close");
	icmo_alter_cdu = (icmo_alter_cdu_func *)GetProcAddress(hIntexDLL, "icmo_alter_cdu");
	icmo_forecast_cdu = (icmo_forecast_cdu_func *)GetProcAddress(hIntexDLL, "icmo_forecast_cdu");
	icmo_find_topmost_icmop = (icmo_find_topmost_icmop_func *)GetProcAddress(hIntexDLL, "icmo_find_topmost_icmop");
	icmo_tr_used_cusip = (icmo_tr_used_cusip_func *)GetProcAddress(hIntexDLL, "icmo_tr_used_cusip");
	icmo_index_name = (icmo_index_name_func *)GetProcAddress(hIntexDLL, "icmo_index_name");
	icmo_get_idx_val = (icmo_get_idx_val_func *)GetProcAddress(hIntexDLL, "icmo_get_idx_val");
	icmo_open_log = (icmo_open_log_func *)GetProcAddress(hIntexDLL, "icmo_open_log");
	icmo_close_log = (icmo_close_log_func *)GetProcAddress(hIntexDLL, "icmo_close_log");
	cmo_talk_a_lot = (cmo_talk_a_lot_func *)GetProcAddress(hIntexDLL, "cmo_talk_a_lot");
	icmo_deal_has_no_sched_dependency = (icmo_deal_has_no_sched_dependency_func *)GetProcAddress(hIntexDLL, "icmo_deal_has_no_sched_dependency");
	icmo_deal_effective_collars = (icmo_deal_effective_collars_func *)GetProcAddress(hIntexDLL, "icmo_deal_effective_collars");
	icmo_prepay_speed = (icmo_prepay_speed_func *)GetProcAddress(hIntexDLL, "icmo_prepay_speed");
	icmo_get_orig_notional_bal = (icmo_get_orig_notional_bal_func *)GetProcAddress(hIntexDLL, "icmo_get_orig_notional_bal");
	icmo_run_mbspool_loop = (icmo_run_mbspool_loop_func *)GetProcAddress(hIntexDLL, "icmo_run_mbspool_loop");
	icmo_mbspool_loop = (icmo_mbspool_loop_func *)GetProcAddress(hIntexDLL, "icmo_mbspool_loop");
	icmo_tranche_deal_class = (icmo_tranche_deal_class_func *)GetProcAddress(hIntexDLL, "icmo_tranche_deal_class");
	icmo_horizon_return = (icmo_horizon_return_func *)GetProcAddress(hIntexDLL, "icmo_horizon_return");
	icmo_total_return = (icmo_total_return_func *)GetProcAddress(hIntexDLL, "icmo_total_return");
	icmo_effcoup_calc = (icmo_effcoup_calc_func *)GetProcAddress(hIntexDLL, "icmo_effcoup_calc");
	icmo_yldcrv_yield_at_maturity = (icmo_yldcrv_yield_at_maturity_func *)GetProcAddress(hIntexDLL, "icmo_yldcrv_yield_at_maturity");
	icmo_property_to_loan_forecast = (icmo_property_to_loan_forecast_func *)GetProcAddress(hIntexDLL, "icmo_property_to_loan_forecast");
	icmo_use_case_sensitive_dir = (icmo_use_case_sensitive_dir_func *)GetProcAddress(hIntexDLL, "icmo_use_case_sensitive_dir");
	icmo_pool_is_in_group = (icmo_pool_is_in_group_func *)GetProcAddress(hIntexDLL, "icmo_pool_is_in_group");
	icmo_group_is_in_group = (icmo_group_is_in_group_func *)GetProcAddress(hIntexDLL, "icmo_group_is_in_group");
	icmo_parent_pips_supported_by_child_pip = (icmo_parent_pips_supported_by_child_pip_func *)GetProcAddress(hIntexDLL, "icmo_parent_pips_supported_by_child_pip");
	icmo_independent_groups = (icmo_independent_groups_func *)GetProcAddress(hIntexDLL, "icmo_independent_groups");
	icmo_free_mbspool_cache = (icmo_free_mbspool_cache_func *)GetProcAddress(hIntexDLL, "icmo_free_mbspool_cache");
	icmo_tranche_taxinfo = (icmo_tranche_taxinfo_func *)GetProcAddress(hIntexDLL, "icmo_tranche_taxinfo");
	icmo_typical_parse_control_fcn = (icmo_typical_parse_control_fcn_func *)GetProcAddress(hIntexDLL, "icmo_typical_parse_control_fcn");
	icmo_typical_parse_control_fcn2 = (icmo_typical_parse_control_fcn2_func *)GetProcAddress(hIntexDLL, "icmo_typical_parse_control_fcn2");
	icmo_zipcode_to_msa = (icmo_zipcode_to_msa_func *)GetProcAddress(hIntexDLL, "icmo_zipcode_to_msa");
	icmo_format_region_id = (icmo_format_region_id_func *)GetProcAddress(hIntexDLL, "icmo_format_region_id");
	icmo_portf_init = (icmo_portf_init_func *)GetProcAddress(hIntexDLL, "icmo_portf_init");
	icmo_portf_reset = (icmo_portf_reset_func *)GetProcAddress(hIntexDLL, "icmo_portf_reset");
	icmo_portf_accum = (icmo_portf_accum_func *)GetProcAddress(hIntexDLL, "icmo_portf_accum");
	icmo_portf_adjust = (icmo_portf_adjust_func *)GetProcAddress(hIntexDLL, "icmo_portf_adjust");
	icmo_portf_stats = (icmo_portf_stats_func *)GetProcAddress(hIntexDLL, "icmo_portf_stats");
	icmo_portf_free = (icmo_portf_free_func *)GetProcAddress(hIntexDLL, "icmo_portf_free");
	icmo_portf_set_cfs = (icmo_portf_set_cfs_func *)GetProcAddress(hIntexDLL, "icmo_portf_set_cfs");
	icmo_solver = (icmo_solver_func *)GetProcAddress(hIntexDLL, "icmo_solver");
	icmo_validate_tax_tranche = (icmo_validate_tax_tranche_func *)GetProcAddress(hIntexDLL, "icmo_validate_tax_tranche");
	icmo_set_deal_errfcn = (icmo_set_deal_errfcn_func *)GetProcAddress(hIntexDLL, "icmo_set_deal_errfcn");
	icmo_set_global_errfcn = (icmo_set_global_errfcn_func *)GetProcAddress(hIntexDLL, "icmo_set_global_errfcn");
	icmo_errinfo = (icmo_errinfo_func *)GetProcAddress(hIntexDLL, "icmo_errinfo");
	icmo_raise_errdie = (icmo_raise_errdie_func *)GetProcAddress(hIntexDLL, "icmo_raise_errdie");
	icmo_convert_prep_rate = (icmo_convert_prep_rate_func *)GetProcAddress(hIntexDLL, "icmo_convert_prep_rate");
	icmo_parse_script = (icmo_parse_script_func *)GetProcAddress(hIntexDLL, "icmo_parse_script");
	icmo_eval_script = (icmo_eval_script_func *)GetProcAddress(hIntexDLL, "icmo_eval_script");
	icmo_set_prepay_script = (icmo_set_prepay_script_func *)GetProcAddress(hIntexDLL, "icmo_set_prepay_script");
	icmo_set_script_retval = (icmo_set_script_retval_func *)GetProcAddress(hIntexDLL, "icmo_set_script_retval");
	icmo_free_script_handle = (icmo_free_script_handle_func *)GetProcAddress(hIntexDLL, "icmo_free_script_handle");
	icmo_get_prepay_script = (icmo_get_prepay_script_func *)GetProcAddress(hIntexDLL, "icmo_get_prepay_script");
	icmo_set_loandata_forecast = (icmo_set_loandata_forecast_func *)GetProcAddress(hIntexDLL, "icmo_set_loandata_forecast");
	icmo_get_loandata_val = (icmo_get_loandata_val_func *)GetProcAddress(hIntexDLL, "icmo_get_loandata_val");
	icmo_ovrdset_asset_vect = (icmo_ovrdset_asset_vect_func *)GetProcAddress(hIntexDLL, "icmo_ovrdset_asset_vect");
	icmo_override_asset_write_ccf = (icmo_override_asset_write_ccf_func *)GetProcAddress(hIntexDLL, "icmo_override_asset_write_ccf");	
	icmo_override_asset_read_ccf = (icmo_override_asset_read_ccf_func *)GetProcAddress(hIntexDLL, "icmo_override_asset_read_ccf");
	icmo_get_collat_userdata = (icmo_get_collat_userdata_func *)GetProcAddress(hIntexDLL, "icmo_get_collat_userdata");
	icmo_get_name = (icmo_get_name_func *)GetProcAddress(hIntexDLL, "icmo_get_name");
	icmo_get_loandata_translation = (icmo_get_loandata_translation_func *)GetProcAddress(hIntexDLL, "icmo_get_loandata_translation");
    icmo_ppmdl_set_adco_credit_assum = (icmo_ppmdl_set_adco_credit_assum_func *)GetProcAddress(hIntexDLL, "icmo_ppmdl_set_adco_credit_assum");
	icmo_ppmdl_set_aft_default_assum = (icmo_ppmdl_set_aft_default_assum_func *)GetProcAddress(hIntexDLL , "icmo_ppmdl_set_aft_default_assum");
	icmo_worker = (icmo_worker_func *)GetProcAddress(hIntexDLL, "icmo_worker");
	icmo_spstr = (icmo_spstr_func *)GetProcAddress(hIntexDLL, "icmo_spstr");
	icmo_dummy_dealname = (icmo_dummy_dealname_func *)GetProcAddress(hIntexDLL, "icmo_dummy_dealname");

	// for errdie function
	icmo_libinit = (icmo_libinit_func *)GetProcAddress(hIntexDLL, "icmo_libinit");

	// these are old:  use the equivalent icmo_YyyyMmDd_bd_adj above
	icmo_YyyyMmDd_businessday = (icmo_YyyyMmDd_businessday_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_businessday");
	icmo_YyyyMmDd_businessday_adj = (icmo_YyyyMmDd_businessday_adj_func *)GetProcAddress(hIntexDLL, "icmo_YyyyMmDd_businessday_adj");

	/* deprecated - replaced by icmo_eval_sched_cashflows */
	icmo_eval_ym_formula = (icmo_eval_ym_formula_func *)GetProcAddress(hIntexDLL, "icmo_eval_ym_formula");
	}
else
	{
	if (compiler_defn == 32)
		throw FatalError("Intex DLL " + cmo_dll
						 + "failed to load. Please contact client services.");
	else
		throw FatalError("Intex DLL " + cmo_dll_64
						 + "failed to load. Please contact client services.");
	}
}



#line 1 "mkt_val_cash_flow_proj.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::mkt_val_cash_flow_proj(int t, const xstring & proj_type, double par_val)
{
proj_period_last = 0;

#if INTEX_CASH_FLOW_DETAIL
if (intex_detail_wanted)
	{
	log_screen.setf(ios::fixed, ios::floatfield);
	log_screen << "itx-> t=" << t
			<< " Begin intex->mkt_val_cash_flow_proj"
			<< " prepay_mode=" << (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD ? "DO_PREPAY_ONE_PERIOD"
								: (intex_prepmt_function_mode == DO_PREPAY_TO_MATURITY ? "DO_PREPAY_TO_MATURITY"
								: (intex_prepmt_function_mode == NO_PREPAYMENTS ? "NO_PREPAYMENTS" : "???")))
			<< MSG_USER;
	}
#endif

if (proj_type == "Actual")
	{
	// set the current balance
	balance[t] = par_val;

	xstring projection_type_saved = proj_defn;
	proj_defn = "Market Value";

	if (done_with_tranche)
		return;

	pThis = this;

	freezep = icmo_pmt_to_pmt_freeze(icmop);
	intex_pool_number = 0;

	icmo_count_npools(icmop, save_pool_data_callback_function);

	DEAL_DATA * uddp;

	uddp = reinterpret_cast <DEAL_DATA *> (icmop->icmo_user);

	intex_collat_callback_mode = NO_CALLBACK;
	intex_prepmt_function_mode = DO_PREPAY_TO_MATURITY;

	icmo_count_npools(icmop, prepayment_setup_callback_function);

	int done = 0;
	double local_principal = 0;
	double local_interest = 0;
	double local_cashflow = 0;
	double local_balance = 0;

#if INTEX_CASH_FLOW_DETAIL
	if (intex_detail_wanted)
		{
		log_screen << "itx-> t=" << t
				<< " offset=" << intex_cdu_months_offset
				<< " for Actual Market Value Cash Flow Projection"
				<< " prepay_mode=" << (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD ? "DO_PREPAY_ONE_PERIOD"
									: (intex_prepmt_function_mode == DO_PREPAY_TO_MATURITY ? "DO_PREPAY_TO_MATURITY"
									: (intex_prepmt_function_mode == NO_PREPAYMENTS ? "NO_PREPAYMENTS" : "???")))
				<< MSG_USER;
		log_screen << "itx-> -t- ----principal----- -----interest----- -----balance------ "
					//       999 999999999999999999 999999999999999999 999999999999999999
				<< MSG_USER;
		}
#endif

	// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
	int period;
	for (period = t + intex_cdu_months_offset + 1; !done; period++)
		{
		done = (icmo_pay_1period(icmop, period, 
							    &local_principal, &local_interest, 
							    &local_cashflow, &local_balance) == TRUE);

		intex_principal_payment = local_principal;
		intex_interest_payment = local_interest;
		intex_cashflow = local_cashflow;
		intex_principal_balance = local_balance;

		// force calls to fill the columns
		get_tranche_bal(period - intex_cdu_months_offset);
		get_tranche_cash_flow(period - intex_cdu_months_offset);
		get_tranche_int_pmt(period - intex_cdu_months_offset);
		get_tranche_prin_pmt(period - intex_cdu_months_offset);

		// save items to array for use in approximate MV calculation
		// and in the modified duration calculation
		principal[period - intex_cdu_months_offset] = local_principal;
		interest[period - intex_cdu_months_offset] = local_interest;
		balance[period - intex_cdu_months_offset] = local_balance;

#if INTEX_CASH_FLOW_DETAIL
		if (intex_detail_wanted
			&& INTEX_POOL_DETAIL_Range(period - intex_cdu_months_offset))
			{
			if (fabs(local_principal)
				+ fabs(local_interest)
				+ fabs(local_cashflow)
				+ fabs(local_balance) > 0.001)
				{
				log_screen.setf(ios::fixed, ios::floatfield);
				log_screen << "itx-> " << setw(3) << period - intex_cdu_months_offset
						<< " " << setw(18) << setprecision(8) << local_principal
						<< " " << setw(18) << setprecision(8) << local_interest
						<< " " << setw(18) << setprecision(8) << local_balance
						<< MSG_USER;
				}
			}
#endif

		// clear out the intex payment variables
		intex_principal_payment = 0;
		intex_interest_payment = 0;
		intex_cashflow = 0;
		intex_principal_balance = 0;

		if (asset_detail_rpt_flag == YES)
			{
			int write_projection_header = 0;

			if (period == max(asset_detail_rpt_start_period, t + intex_cdu_months_offset + 1))
				write_projection_header = 1; 

			tranche_detail(period - intex_cdu_months_offset, write_projection_header);
			}
		}

	proj_period_last = period - intex_cdu_months_offset - 1;

	// move settlement date to end of month
	icmo_forward_settle_date(icmop, 0,
	icmo_YyyyMmDd_addmo(settle_date, t + intex_cdu_months_offset, TRUE), 0);

	// Call Stats
	icmo_stats(icmop
	          , intex_tranche_number
	          , 0
	          , ICMOPY_PRICE100
	          , 100.0);

	// Go back to the original settlement date
 	icmo_forward_settle_date(icmop, 0, settle_date, 0);

	intex_pool_number = 0;
	icmo_count_npools(icmop, restore_pool_data_callback_function);
	icmo_pmt_to_pmt_thaw(icmop, freezep);
	icmo_pmt_to_pmt_toss(&freezep);

	proj_defn = projection_type_saved;
	}
else // proj_type == "Approximate" based on last MV calc
	{
	int period = 0;

	double factor = par_val / balance[t];

#if INTEX_CASH_FLOW_DETAIL
	if (intex_detail_wanted)
		{
		log_screen << "itx-> t=" << t
				<< " factor=" << setw(18) << setprecision(12) << factor
				<< " (pv=" << setw(18) << setprecision(8) << par_val
				<< " / b=" << setw(18) << setprecision(8) << balance[t]
				<< ") for Approximate Market Value Cash Flow Projection"
				<< MSG_USER;
		log_screen << "itx-> ndx ----principal----- -----interest----- -----balance------ --principal*fct--- ---interest*fct--- ---balance*fct---- " << MSG_USER;
					//       999 999999999999999999 999999999999999999 999999999999999999 999999999999999999 999999999999999999 999999999999999999
		}
#endif

	// When approximating, we just used stored values
	// Note: Stored values are using same 't' as columns so 
	// so no intex_cdu_months_offset is required here
	for (period = t + 1; balance[period - 1] > 0; period++)
		{
		intex_principal_payment = principal[period] * factor;
		intex_interest_payment = interest[period] * factor;
		intex_cashflow = (principal[period] + interest[period]) * factor;
		intex_principal_balance = balance[period] * factor;

#if INTEX_CASH_FLOW_DETAIL
		if (intex_detail_wanted
			&& INTEX_POOL_DETAIL_Range(period))
			{
			if (fabs(intex_principal_payment) 
				+ fabs(intex_interest_payment) 
				+ fabs(intex_cashflow) 
				+ fabs(intex_principal_balance) > 0.001)
				{
				log_screen.setf(ios::fixed, ios::floatfield);
				log_screen << "itx-> " << setw(3) << t + period
						<< " " << setw(18) << setw(18) << setprecision(8) << principal[period]
						<< " " << setw(18) << setw(18) << setprecision(8) << interest[period]
						<< " " << setw(18) << setw(18) << setprecision(8) << balance[period]
						<< " " << setw(18) << setw(18) << setprecision(8) << intex_principal_payment
						<< " " << setw(18) << setw(18) << setprecision(8) << intex_interest_payment
						<< " " << setw(18) << setw(18) << setprecision(8) << intex_principal_balance
						<< MSG_USER;
				}
			}
#endif

		// force call to fill columns
		get_tranche_bal(period);
		get_tranche_cash_flow(period);
		get_tranche_int_pmt(period);
		get_tranche_prin_pmt(period);
		}
	}

#if INTEX_CASH_FLOW_DETAIL
if (asset_detail_rpt_flag == YES)
	ITXFile << endl;
if (intex_detail_wanted)
	{
	log_screen.setf(ios::fixed, ios::floatfield);
	log_screen << "itx-> t=" << t
			<< " end intex->mkt_val_cash_flow_proj"
			<< MSG_USER;
	}
#endif

return;
}



#line 1 "net_yld_cash_flow_proj.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::net_yld_cash_flow_proj(int t)
{
proj_period_last = 0;
xstring projection_type_saved = proj_defn;
proj_defn = "Net Yield";

if (done_with_tranche)
	return;

#if INTEX_CASH_FLOW_DETAIL
if (intex_detail_wanted)
	{
	log_screen.setf(ios::fixed, ios::floatfield);
	log_screen << "itx-> t=" << t
			<< " Begin intex->net_yld_cash_flow_proj"
			<< MSG_USER;
	}
#endif

pThis = this;

freezep = icmo_pmt_to_pmt_freeze(icmop);

intex_pool_number = 0;

icmo_count_npools(icmop, save_pool_data_callback_function);

if (t <= 0)
	{
	if (!stricmp(icmop->icmo_tranche_types[intex_tranche_number], "MBSPOOL"))
		icmo_count_npools(icmop, resets_off_callback_function);
	}

intex_collat_callback_mode = NO_CALLBACK;

if (!stricmp(icmop->icmo_tranche_types[intex_tranche_number], "MBSPOOL"))
	intex_prepmt_function_mode = NO_PREPAYMENTS;

else
	{
	intex_prepmt_function_mode = DO_PREPAY_TO_MATURITY;

	icmo_count_npools(icmop, prepayment_setup_callback_function);
	}

int done = 0;
double local_principal = 0;
double local_interest = 0;
double local_cashflow = 0;
double local_balance = 0;

int interest_paid = 0;
int principal_paid = 0;

#if INTEX_CASH_FLOW_DETAIL
	if (intex_detail_wanted)
		{
		log_screen << "itx-> t=" << t
				<< " for Net Yield Projection:"
				<< " offset=" << intex_cdu_months_offset
				<< " prepay_mode=" << (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD ? "DO_PREPAY_ONE_PERIOD"
									: (intex_prepmt_function_mode == DO_PREPAY_TO_MATURITY ? "DO_PREPAY_TO_MATURITY"
									: (intex_prepmt_function_mode == NO_PREPAYMENTS ? "NO_PREPAYMENTS" : "???")))
				<< MSG_USER;
		log_screen << "itx-> ndx ----principal----- -----interest----- -----balance------ "
					//       999 999999999999999999 999999999999999999 999999999999999999
				<< MSG_USER;
		}
#endif

// 20191021 STW: fix compiler error while converting from RAFM 2.6 to RAFM 2.8
int period;
for (period = t + intex_cdu_months_offset + 1; !done; period++)
	{
	done = (icmo_pay_1period(icmop, period, 
						    &local_principal, &local_interest, 
						    &local_cashflow, &local_balance) == TRUE);

	intex_principal_payment = local_principal;
	intex_interest_payment = local_interest;
	intex_cashflow = local_cashflow;
	intex_principal_balance = local_balance;

	if (io_po_defn == NOT_ASSIGNED)
		{
		if (!interest_paid && local_interest != 0)
			interest_paid = 1;

		if (!principal_paid && local_principal != 0)
			principal_paid = 1;

		if (interest_paid && principal_paid)
			io_po_defn = BOTH;
		}

	// force calls to fill the columns
	get_tranche_bal(period - intex_cdu_months_offset);
	get_tranche_cash_flow(period - intex_cdu_months_offset);
	get_tranche_int_pmt(period - intex_cdu_months_offset);
	get_collateral_prepmt(period - intex_cdu_months_offset);
	get_tranche_prin_pmt(period - intex_cdu_months_offset);

	if (asset_detail_rpt_flag == YES)
		{
		int write_projection_header = 0;
	
		if (period == max(asset_detail_rpt_start_period, t + intex_cdu_months_offset + 1))
			write_projection_header = 1;

		tranche_detail(period - intex_cdu_months_offset, write_projection_header);
		}

#if INTEX_CASH_FLOW_DETAIL
	if (intex_detail_wanted
		&& INTEX_POOL_DETAIL_Range(period - intex_cdu_months_offset))
		{
		if (fabs(local_principal)
			+ fabs(local_interest)
			+ fabs(local_cashflow)
			+ fabs(local_balance) > 0.001)
			{
			log_screen.setf(ios::fixed, ios::floatfield);
			log_screen << "itx-> " << setw(3) << period - intex_cdu_months_offset
					<< " " << setw(18) << setprecision(12) << local_principal
					<< " " << setw(18) << setprecision(12) << local_interest
					<< " " << setw(18) << setprecision(12) << local_balance
					<< MSG_USER;
			}
		}
#endif

	// clear out the intex payment variables
	intex_principal_payment = 0;
	intex_interest_payment = 0;
	intex_cashflow = 0;
	intex_principal_balance = 0;
	}

proj_period_last = period - intex_cdu_months_offset - 1;

if (io_po_defn == NOT_ASSIGNED)
	{
	if (interest_paid && !principal_paid)
		io_po_defn = IO;
	else if (!interest_paid && principal_paid)
		io_po_defn = PO;
	else
		io_po_defn = BOTH;
	}

if (t <= 0)
	{
	if (!stricmp(icmop->icmo_tranche_types[intex_tranche_number], "MBSPOOL"))
		icmo_count_npools(icmop, resets_on_callback_function);
	}

intex_pool_number = 0;
icmo_count_npools(icmop, restore_pool_data_callback_function);

icmo_pmt_to_pmt_thaw(icmop, freezep);
icmo_pmt_to_pmt_toss(&freezep);
	
proj_defn = projection_type_saved;

#if INTEX_CASH_FLOW_DETAIL
if (asset_detail_rpt_flag == YES)
	ITXFile << endl;
if (intex_detail_wanted)
	{
	log_screen.setf(ios::fixed, ios::floatfield);
	log_screen << "itx-> t=" << t
			<< " end intex->net_yld_cash_flow_proj"
			<< MSG_USER;
	}
#endif

return;
}



#line 1 "open_translation_tbl.INTEX_ASSET.for"                                                                                   
int INTEX_ASSET::open_translation_tbl()
{
replaceWildcards(cusip_deal_translation_path);

if (cusip_deal_translation_path.length() <= 0)
	throw FatalError("You have selected to project with Intex."
					" However, no Intex CUSIP Deal Translation Data has been specified."
					" Please correct your data.");

// Create cdu_data path from input path
strcpy(zCduPath, cusip_deal_translation_path.strip());

// Create cdi_data path from cdu_data path
path_directory_change(zCdiPath, zCduPath, "cmo_cdi\\");

// Open Intex Cusip Translation Table
if ((icmodbp = icmodb_init(zCduPath, FALSE, ICMODB_INIT_CUSIP_ONLY)) == NULL)
	{
	icmodb_free(&icmodbp);
	throw FatalError("Unable to access Intex CUSIP Deal Translation Data." );
	}
else
	{
	// Set up ICMOMISC initialization structure
	icmomiscp = icmo_setup_icmomiscp(&icmomisc, ICMOMISC_SETUP_TYPICAL);
	icmomiscp->icmomisc_trading_accuracy_not_required = TRUE;
	icmomiscp->icmomisc_make_collat_tranche = FALSE;
	icmomiscp->icmomisc_hide_errmsgs = TRUE;

	// Setup cmo_cdi and cmo_cdu paths
	icmomiscp->icmomisc_alteruse.altu_base_cdi_path = zCdiPath;
	icmomiscp->icmomisc_alteruse.altu_base_cdu_path = zCduPath;

	// Turn off Use History setting - always simulate
	icmomiscp->icmomisc_use_hist = 0;

	// Turn off delays - allow all payments to be received
	icmomiscp->icmomisc_use_duebill = ICMODUEBILL_YES;

	return 1; // Database was opened successfully
	}
}



#line 1 "path_directory_change.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::path_directory_change(char *zDestPath, char *zSourcePath, char *zNewDirectory)
{
strcpy(zDestPath,zSourcePath);

// ensure that there are no spaces at the end
while (zDestPath[strlen(zDestPath)-1]==' ')
	zDestPath[strlen(zDestPath)-1]= '\0';

if (zDestPath[strlen(zDestPath)-1]=='\\') // handle the case of no ending slash
	zDestPath[strlen(zDestPath)-1]= '\0';

// put a NULL character right after the next right-most slash, leaving a slash at the end
if (strrchr(zDestPath,'\\'))
	*(strrchr(zDestPath,'\\')+1) = '\0';
else
	if (strrchr(zDestPath,'\\:'))
		*(strrchr(zDestPath,'\\:')+1) = '\0';
	else // this case is probably not going to happen
		zDestPath[0] = '\0';

strcat(zDestPath,zNewDirectory);
return;
}



#line 1 "prelim_proj.INTEX_ASSET.for"                                                                                   
int INTEX_ASSET::prelim_proj(void)
{
int period = 1;
int t = -intex_cdu_months_offset;
int scenmth = 0;

done_with_tranche = 0;

#if INTEX_CASH_FLOW_DETAIL
if (intex_detail_wanted)
	{
	log_screen.setf(ios::fixed, ios::floatfield);
	log_screen << "itx-> t=" << t
			<< " beg intex->prelim_proj offset=" << intex_cdu_months_offset
			<< " prepay_mode=" << (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD ? "DO_PREPAY_ONE_PERIOD"
								: (intex_prepmt_function_mode == DO_PREPAY_TO_MATURITY ? "DO_PREPAY_TO_MATURITY"
								: (intex_prepmt_function_mode == NO_PREPAYMENTS ? "NO_PREPAYMENTS" : "???")))
			<< MSG_USER;
	log_screen << "itx-> -t- ----principal----- ------prepay------ -----interest----- ----cash-flow----- -----balance------ "
				//       999 999999999999999999 999999999999999999 999999999999999999 999999999999999999 999999999999999999
			<< MSG_USER;
	}
#endif

// need to project the ISPV cash flows in month before first projection month
if (t < 0)
	int_savings_pv_cash_flow_setup(t);

for (period = 1; period <= intex_cdu_months_offset; period++)
	{
	t++;

	setup_yld_curve(t, shift_defn);

	intex_reinv_rates[0] = vyldcrv_vals[0];
	icmop->icmo_vcashflow_reinv_rates = intex_reinv_rates;

	setup_cp_data(0);

	cash_flow_proj(t);

#if INTEX_CASH_FLOW_DETAIL
	if (intex_detail_wanted
		&& INTEX_POOL_DETAIL_Range(period - intex_cdu_months_offset))
		{
		double local_principal = get_tranche_prin_pmt(t);
		double local_prepmt = get_collateral_prepmt(t);
		double local_interest = get_tranche_int_pmt(t);
		double local_cash_flow = get_tranche_cash_flow(t);
		double local_balance = get_tranche_bal(t);

		if (fabs(local_principal)
			+ fabs(local_prepmt)
			+ fabs(local_interest)
			+ fabs(local_balance)
			+ fabs(local_cash_flow) > 0.001)
			{
			log_screen.setf(ios::fixed, ios::floatfield);
			log_screen << "itx-> " << setw(3) << t
					<< " " << setw(18) << setprecision(8) << local_principal
					<< " " << setw(18) << setprecision(8) << local_prepmt
					<< " " << setw(18) << setprecision(8) << local_interest
					<< " " << setw(18) << setprecision(8) << local_cash_flow
					<< " " << setw(18) << setprecision(8) << local_balance
					<< MSG_USER;
			}
		}
#endif

	if (done_with_tranche)
		{
		if (is_first_proj_task_loop
			&& is_intex_projection)
			log_screen << "Intex Pre-projection Not Applicable for "
						+ asset_id 
						+ ": Asset has expired before the model start date and has been discarded." 
						<< MSG_USER;

		return 0;
		}
	}

// fill balance array value for time 0
balance[t] = get_tranche_bal(t);

preliminary_projection_complete = 1;

#if INTEX_CASH_FLOW_DETAIL
if (asset_detail_rpt_flag == YES)
	ITXFile << endl;

if (intex_detail_wanted)
	{
	log_screen.setf(ios::fixed, ios::floatfield);
	log_screen << "itx-> t=" << t
			<< " end intex->prelim_proj balance[t]="
			<< setw(18) << setprecision(6) << balance[t]
			<< MSG_USER;
	}
#endif

return 1;
}



#line 1 "prepmt_rate.INTEX_ASSET.for"                                                                                   
double __cdecl INTEX_ASSET::prepmt_rate(struct _ICMO *icmop, struct _POOL_INFO *pip, int ith_pool, int curper, int curmonth)
{
int t = 0;
int cur_age = 0;
int prepay_flag = 0;
int prepay_lockout = 0;
int month = 0;
int scenmth = 0;
int months_since_index = 0;
int months_before_index = 0;
double preliminary_annual_default_percentage = 0.0;
double annual_default_percentage = 0.0;
double monthly_default_rate = 0.0;
double refinancing_rate = 0.0;
double int_rate_diff = 0.0;
double int_savings_pv_bef_prepmt = 0.0;
double prepmt_cost = 0.0;
double int_savings = 0.0;
double financial_prepmt_diff = 0.0;
double nonfinancial_int_diff = 0.0;
double base_psa_factor = 0.0;
double psa_speed = 0.0;
double financial_prepmt_factor = 0.0;
double nonfinancial_factor = 0.0;
double mortgage_seasonality_adjustment_factor = 0.0;
double mortgage_nonfinancial_adjustment_factor = 0.0;
double mortgage_seasoning_adjustment_factor = 0.0;
double prepmt_pct = 0.0;
double prepmt_pct_mthly = 0.0;
double psa_factor = 0.0;
double penalty = 0.0;
DEAL_DATA *uddp;
POOL_DATA *updp;

uddp = reinterpret_cast <DEAL_DATA *> (icmop->icmo_user);
updp = reinterpret_cast <POOL_DATA *> (pip->pi_user);

t = uddp->t - intex_cdu_months_offset;

/********************** Balloon Extensions ***************************************/
// Use either contracted extensions or global settings

if (pip->pi_balloon > 0)
	{
	balloon_extension = "Yes";
	if (pip->pi_loanattrp == NULL
		|| pip->pi_loanattrp->loanattr_balloon_extension.balloonext_nmonths == 0)
		{
		// Assume 12 month extension, 100% extending with 2% additive coupon
		// and continuing pre-balloon amortization method

		icmop->icmo_balloon_extension.balloonext_nmonths = 12;
		icmop->icmo_balloon_extension.balloonext_pct_extend = 100.0;
		icmop->icmo_balloon_extension.balloonext_coupon_stepup = 2.0;
		icmop->icmo_balloon_extension.balloonext_amort_type = LOAN_AMORT_DEFAULT;
		}
	else //if (pip->pi_loanattrp != NULL)
		{
		// Get contracted balloon extension information for pool and use it
		memcpy(&(icmop->icmo_balloon_extension),
			   &(pip->pi_loanattrp->loanattr_balloon_extension),
			   sizeof(BALLOON_EXTENSION));
		}
	}

/*********************** Line of Credit Draws *************************************/
if (pip->pi_loanattrp != NULL
	&& pip->pi_loanattrp->loanattr_draw_term != 0)
	{
	intex_draw_rates[1] = 10.0;
	intex_draw_utilization_rates[1] = 60.0;
	}

/********************** Default Processing ***************************************/
// All defaults are assumed to occur at the beginning of the month for collateral pools.

if (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD)
	{
	months_since_index = pip->pi_age_since_issue + curper;
	months_before_index = pip->pi_remterm - curper;

	preliminary_annual_default_percentage
	= rates->get_dflt_rate(t, category_id, EFFECTIVE_ANNUAL);

	// Need to round because asset category tables are single precision.
	// Also need to keep default percentage in bounds.
	annual_default_percentage
	= max(min(round_result(1, 0, preliminary_annual_default_percentage, DECIMALS_TO_ROUND), 1.0), 0.0);

	if (!(pip->pi_agency==ICMOAGENCY_GNMA || pip->pi_agency==ICMOAGENCY_FNMA
		|| pip->pi_agency==ICMOAGENCY_FHLMC || pip->pi_agency==ICMOAGENCY_GNMA2))
		monthly_default_rate
		= 1.0 - pow((1.0 - annual_default_percentage), (1.0 / 12.0));
	else
		monthly_default_rate = 0.0;

	icmop->icmo_cfassum.cfa_loss_vdefaults[curper] = monthly_default_rate * 100.0;
	icmop->icmo_cfassum.cfa_loss_vseverity[curper] = 100.0;

	// Update Current Interest Savings Present Value
	updp->cppresvalue *= (1.0 - monthly_default_rate);

	if (monthly_default_rate > 0.0)
		{
		// Update all future payments for defaults which occur this period
		for (month=curper; month <= icmop->icmo_remterm; month++)
			{
			updp->vcpcashflow[month]  *= (1.0 - monthly_default_rate);
			updp->vcpbalance[month]   *= (1.0 - monthly_default_rate);
			updp->vcpprincipal[month] *= (1.0 - monthly_default_rate);
			updp->vcpinterest[month]  *= (1.0 - monthly_default_rate);
			}
		}
	// Capture detail variable
	intex_collat_defaults += updp->vcpbalance[curper - 1] * monthly_default_rate;
	}

//********************** Prepayment Processing *********************************
if (intex_prepmt_function_mode == NO_PREPAYMENTS)
	return 0;

// Determine current age of Collateral
if (pip->pi_wala >= 0)
	cur_age = pip->pi_wala + curper;
else
	cur_age = pip->pi_origterm - pip->pi_remterm + curper;

// Determine prepayment penalty provisions
if (pip->pi_ymp != NULL)
	{
	if ((pip->pi_ymp->ym_nflags > 0
		 && pip->pi_ymp->ym_vflags[min(cur_age, pip->pi_ymp->ym_nflags - 1)]
			 == ICMOPREPAY_LOCKOUT)
		|| pip->pi_ymp->ym_nflags == 0)
		prepay_lockout = 1;
	else
		prepay_lockout = 0;

	// Calculate Yield Maintenance Provisions if necessary
	// (not yet supported in Intex pmt_to_pmt mode)
#if 0
	if (pip->pi_ymp->ym_vflags[min(cur_age, pip->pi_ymp->ym_nflags - 1)] == ICMOPREPAY_YM
		|| pip->pi_ymp->ym_vflags[min(cur_age, pip->pi_ymp->ym_nflags - 1)] == ICMOPREPAY_MAX_YM_OR_POINTS
		|| pip->pi_ymp->ym_vflags[min(cur_age, pip->pi_ymp->ym_nflags - 1)] == ICMOPREPAY_MIN_YM_OR_POINTS)
		icmo_eval_ym_formula(icmop, pip, 0);
#endif
	// Determine correct penalty for the month
	if (pip->pi_ymp->ym_nflags > 0
		&& pip->pi_ymp->ym_vflags[min(cur_age, pip->pi_ymp->ym_nflags - 1)] == ICMOPREPAY_POINTS)
		penalty = pip->pi_ymp->ym_vpoints[min(cur_age, pip->pi_ymp->ym_nflags - 1)];
	else
		penalty = 0.0;
#if 0
	if (pip->pi_ymp->ym_vflags[min(cur_age, pip->pi_ymp->ym_nflags - 1)] == ICMOPREPAY_YM)
		penalty = pip->pi_ymp->ym_vymval_in_points_units[min(cur_age, pip->pi_ymp->ym_nflags - 1)];
	else
	if (pip->pi_ymp->ym_vflags[min(cur_age, pip->pi_ymp->ym_nflags - 1)] == ICMOPREPAY_MAX_YM_OR_POINTS)
		penalty = max(pip->pi_ymp->ym_vymval_in_points_units[min(cur_age, pip->pi_ymp->ym_nflags - 1)], 
					  pip->pi_ymp->ym_vpoints[min(cur_age, pip->pi_ymp->ym_nflags - 1)]);
	else
	if (pip->pi_ymp->ym_vflags[min(cur_age, pip->pi_ymp->ym_nflags - 1)] == ICMOPREPAY_MIN_YM_OR_POINTS)
		penalty = min(pip->pi_ymp->ym_vymval_in_points_units[min(cur_age, pip->pi_ymp->ym_nflags - 1)], 
					  pip->pi_ymp->ym_vpoints[min(cur_age, pip->pi_ymp->ym_nflags - 1)]);
	else
		penalty = 0.0;
#endif
	}

// We only need to swap to CP asset if we have NOT processed defaults which
// are processed during DO_PREPAY_ONE_PERIOD
if (prepmt_model_defn == ANDREW_DAVIDSON)
	{
	prepmt_pct_mthly
	= updp->smm_forecast[curper - 1]
	  * (1 - prepay_lockout);

	// capture detail variable
	if (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD)
		intex_collat_schpay += updp->vcpprincipal[curper];

	// update get_tranche_bal for prepmts this month - needed for
	// next months defaults
	updp->vcpbalance[curper] *= (1.0 - prepmt_pct_mthly);
	}
else // asset_category_prepmt model type == TILLINGHAST
	{
	if (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD)
		// Capture current month refinancing rate for this pool
		refinancing_rate = updp->refinrate;

	// Update Interest Savings Present Value during Present Value Calc
	if (intex_prepmt_function_mode == DO_PREPAY_TO_MATURITY)
		{
		// capture Refinancing Rate During PV Calcs
		if (use_eom_scen_rates == YES)
			scenmth = t;
		else
			scenmth = t - 1;

		refinancing_rate
		= category_refinancing_rate(scenmth,
									pip->pi_remterm - curper,
									NOMINAL_SEMIANNUAL,
									NO_SHIFT /* shift_defn */);

		// Note: we assume here that the accrued interest is zero. Should be OK
		// in all but a very few cases
		updp->cppresvalue
		= updp->cppresvalue
		  * pow((1.0 + updp->refinrate / NOMINAL_SEMIANNUAL),
				(1.0 / 12.0) * NOMINAL_SEMIANNUAL)
		  - updp->vcpcashflow[curper];
		}

	if (int_diff_defn == GROSS_INTEREST_RATE)
		{
		int_rate_diff
		= convert_rate_basis((pip->pi_netcoupon + pip->pi_servfee) / 100.0,
							 NOMINAL_MONTHLY,
							 NOMINAL_SEMIANNUAL);
		}
	else
		{
		// Note: "Net Yield" setting not supported
		if (int_diff_defn == INTEREST_RATE
			|| int_diff_defn == NET_YIELD)
			{
			int_rate_diff
			= convert_rate_basis((pip->pi_netcoupon) / 100.0,
								 NOMINAL_MONTHLY,
								 NOMINAL_SEMIANNUAL);
			}
		}

	// Determine Interest Savings Present Value
	int_savings_pv_bef_prepmt = updp->cppresvalue;
	prepmt_cost = updp->vcpbalance[curper] * (refinancing_cost_pct + penalty);
	int_savings	= int_savings_pv_bef_prepmt - updp->vcpbalance[curper];

	if (int_savings > prepmt_cost)
		prepay_flag = 1;
	else
		prepay_flag = 0;

	financial_prepmt_diff = int_rate_diff - refinancing_rate;

	nonfinancial_int_diff
	= refinancing_rate
	  - convert_rate_basis((pip->pi_netcoupon + pip->pi_servfee) / 100.0,
						   NOMINAL_MONTHLY,
						   NOMINAL_SEMIANNUAL);

	base_psa_factor	= psa_base_rate[min(30, max(1, cur_age))];

	if (prepmt_defn == ABSOLUTE_PERCENTAGE)
		psa_factor = 1.0;
	else // prepmt_defn == PERCENT_OF_PSA
		psa_factor = base_psa_factor;

	double index 
	= max(0.0, (financial_prepmt_diff - int_rate_diff_min) 
				/ (int_rate_diff_max - int_rate_diff_min) 
				* int_rate_diff_array_size);

	int low_index = max(0, min(int(index), int_rate_diff_array_size));
	int high_index = max(0, min(low_index + 1, int_rate_diff_array_size));
	double weight = index - low_index;
	
	double prepmt_exercise_pct
	= this->prepmt_exercise_pct[low_index] * (1.0 - weight)
	  + this->prepmt_exercise_pct[high_index] * weight;
	
	financial_prepmt_factor = prepmt_exercise_pct * psa_factor;
	nonfinancial_factor = prepmt_nonfinancial_pct * psa_factor;
	mortgage_seasoning_adjustment_factor = prepmt_seasoning_since_issue_mult[cur_age];

	int cm = cal_mth(curmonth);
	mortgage_seasonality_adjustment_factor = prepmt_nonfinancial_seasonality_addn[cm];

	index 
	= max(0.0, (nonfinancial_int_diff - int_rate_diff_min) 
				/ (int_rate_diff_max - int_rate_diff_min) 
				* int_rate_diff_array_size);

	low_index = max(0, min(int(index), int_rate_diff_array_size));
	high_index = max(0, min(low_index + 1, int_rate_diff_array_size));
	weight = index - low_index;

	double prepmt_nonfinancial_adj
	= this->prepmt_nonfinancial_adj[low_index] * (1.0 - weight)
	  + this->prepmt_nonfinancial_adj[high_index] * weight;

	mortgage_nonfinancial_adjustment_factor	= prepmt_nonfinancial_adj * psa_factor;

	prepmt_pct
	= max(0.0, 
		  min(1.0,
		      (nonfinancial_factor
			   + mortgage_seasonality_adjustment_factor
			   - mortgage_nonfinancial_adjustment_factor
			   + financial_prepmt_factor * prepay_flag)
			   * mortgage_seasoning_adjustment_factor));

	psa_speed = prepmt_pct / base_psa_factor;

	if (prepay_lockout == 1)
		prepmt_pct_mthly = 0;
	else
		prepmt_pct_mthly = 1.0 - pow(1.0 - prepmt_pct, 1.0 / 12.0);

	// capture detail variable
	if (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD)
		intex_collat_schpay += updp->vcpprincipal[curper];

	// Update Interest Savings Present Value during Present Value Calc
	if ((intex_prepmt_function_mode == DO_PREPAY_TO_MATURITY
		 || intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD)
		&& prepmt_pct_mthly > 0.0)
		{
		updp->cppresvalue *= (1.0 - prepmt_pct_mthly);

		// Update all future payments for prepayment which occur this period
		for (month=curper; month <= icmop->icmo_remterm; month++)
			{
			updp->vcpcashflow[month] *= (1.0 - prepmt_pct_mthly);
			updp->vcpbalance[month] *= (1.0 - prepmt_pct_mthly);
			updp->vcpprincipal[month] *= (1.0 - prepmt_pct_mthly);
			updp->vcpinterest[month] *= (1.0 - prepmt_pct_mthly);
			}

		} // End if DO_PREPAY_TO_MATURITY or DO_PREPAY_ONE_PERIOD

#if INTEX_CASH_FLOW_POOL_DETAIL
	if (intex_detail_wanted
		&& INTEX_POOL_DETAIL_Range(curper)
		&& (ith_pool == INTEX_CASH_FLOW_POOL_DETAIL
			|| (INTEX_CASH_FLOW_POOL_DETAIL == -1)))
		{
		log_screen.setf(ios::fixed, ios::floatfield);
		log_screen << "itx5-> " << setw(3) << curper
				<< " " << setw(18) << setprecision(8) << updp->vcpprincipal[curper]
				<< " p#=" << setw(3) << ith_pool
				<< " ppm=" << setw(18) << setprecision(14) << prepmt_pct_mthly
				<< " rr=" << setw(18) << setprecision(14) << refinancing_rate
				<< " id=" << setw(18) << setprecision(14) << int_rate_diff
				<< " ispvbp=" << setw(18) << setprecision(8) << int_savings_pv_bef_prepmt
				<< " is=" << setw(18) << setprecision(8) << int_savings
				<< " pc=" << setw(18) << setprecision(8) << prepmt_cost
				<< " |Intex_Pmt_To_Pmt_prepmts"
				<< MSG_USER;
		}
#endif

	} // End if Prepayment Model Type == Andrew Davidson

return prepmt_pct_mthly;
}



#line 1 "prepmt_setup.INTEX_ASSET.for"                                                                                   
void __cdecl INTEX_ASSET::prepmt_setup(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
int is_alt_a = 0;
YyyyMmDd origination_date;
short orig_mmdd = 0;
ICMO* pool_icmop;
COMMERCIAL_OP *comm_op;
DEAL_DATA *uddp;
POOL_DATA *updp;
uddp = reinterpret_cast <DEAL_DATA *> (icmop->icmo_user);
updp = reinterpret_cast <POOL_DATA *> (pip->pi_user);
pool_icmop = (ICMO *)(pip->pi_icmop);
bool is_hybrid = false;

int t = uddp->t - intex_cdu_months_offset;

intex_prepayment_model_supported = 1;

if (prepmt_model_defn == ANDREW_DAVIDSON)
	{
	if (uddp->t < 1 // at model start date
		|| proj_defn != EXPERIENCE)
		{
		#if defined(__ADCO_ASSET_H_)
		if (adco)
			{
			// Only setup ADCO parameters if necessary
			if (asset_id != adco->asset_id
				|| proj_defn != adco->prepmt_forecast_defn
				|| dealname != adco->intex_dealname
				|| ith_pool != adco->pool_id
				|| t != adco->valuation_period
				|| shift_defn != adco->shift_defn
				|| loaded_proj_task_loop != adco->loaded_proj_task_loop)
				{
				// reset adco values
				adco->resetValues();
				adco->balloon_term = 0;
				adco->arm_reset_period = 0;

				int abstype = 0;
				int init_reset_per = 0;
				char issuer_name[10];
				int agencytype = pip->pi_agency;
				int cftype = pip->pi_cftype;

				if (icmop->icmo_deal_category == ICMODEALCAT_WHOLE_LOAN
					&& icmop->icmo_assetback_type != ICMOASSETBACK_LOAN)
					{
					adco->prepmt_model_defn = "ABS";

					// determine issuer
					strncpy(issuer_name, icmop->icmo_deal_issuer, 8);
					issuer_name[8] = '\0';
					strupr(issuer_name);

					abstype = icmop->icmo_assetback_type;
					
					switch (abstype)
						{
						case ICMOASSETBACK_AUTOLOAN:
							adco->abs_prepmt_defn = "Auto";
							break;
						case ICMOASSETBACK_HOMEEQUITY:
							if (pip->pi_ltv > 0.0)
								adco->original_ltv = static_cast <double> (pip->pi_ltv);
							else if (pip->pi_amort_ltv > 0.0)
								adco->original_ltv = static_cast <double> (pip->pi_amort_ltv);
							else
								adco->original_ltv = static_cast <double> (pip->pi_orig_ltv);

							origination_date
							= icmo_YyyyMmDd_addmo(icmop->icmo_latest_cdu_date,
		                                          - pip->pi_age_since_issue, TRUE);
                          
							adco->origination_yr
							= static_cast <int> (origination_date / 10000);

							orig_mmdd
							= static_cast <int> (origination_date
		                      - adco->origination_yr * 10000);

		 				   adco->origination_mth
		 				   = static_cast <int> (orig_mmdd / 100);
							
							adco->original_term = pip->pi_origterm; 
                            
							// initialize arm reset period
							adco->arm_reset_period = 0;

							if (pip->pi_armp != NULL
								&& pip->pi_armp->armi_index != ARMI_INDEX_STEPUP)
								{
								adco->abs_prepmt_defn = "ARM Home Equity Loan";
								
								if (pip->pi_armp->armi_convertable != 0)
                                	adco->adjustable_rate_defn = CONVERTIBLE;
                                else
                                    adco->adjustable_rate_defn = NON_CONVERTIBLE;

                                if (pip->pi_armp->armi_init_resetper != 0)
							        adco->arm_reset_period = pip->pi_armp->armi_init_resetper;
							
						        else if (pip->pi_armp->armi_in_teaser
								         || pip->pi_armp->armi_ntillreset >= pip->pi_armp->armi_resetper   
								         || pip->pi_age_since_issue < pip->pi_armp->armi_resetper)
								     adco->arm_reset_period
									 = pip->pi_age_since_issue + pip->pi_armp->armi_ntillreset - 1;
						        else if (pip->pi_age_since_issue < 12)
								         adco->arm_reset_period = 6;
								}
							else // Fixed rate HEL
								{
								adco->abs_prepmt_defn = "Fixed Home Equity Loan";

								if (pip->pi_origterm >= 240) // term per Intex instructions re from Eknath at ADCO
									adco->original_term = 360;
								else
									adco->original_term = 180;

								if (!strncmp(issuer_name, "AFC ", 4)
									|| !strncmp(issuer_name, "AFCM", 4))
									adco->hel_issuer = "AFC";
								else if (!strncmp(issuer_name, "ADVA", 4))
									adco->hel_issuer = "ADV";
								else if (!strncmp(issuer_name, "EQUICR", 6)
										 || !strncmp(issuer_name, "EQCC H", 6))
									adco->hel_issuer = "EC";
								else if (!strncmp(issuer_name, "GE C", 4))
									adco->hel_issuer = "GE";
								else if (!strncmp(issuer_name, "THE M", 5)
										 || !strncmp(issuer_name, "TMS ", 4)
										 || !strncmp(issuer_name, "MONE", 4))
									adco->hel_issuer = "MON";
								else if (!strncmp(issuer_name, "UCFC", 4))
									adco->hel_issuer = "UFC";
								else if (!strncmp(issuer_name, "INDY", 4)
										 || !strncmp(issuer_name, "INDEP", 5))
									adco->hel_issuer = "INM";
								else if (!strncmp(issuer_name, "CONTI", 5))
									adco->hel_issuer = "CON";
								else
									adco->hel_issuer = "UNK";
								}    
							break;
						case ICMOASSETBACK_MANUHOUSE:
							adco->abs_prepmt_defn = "Manufactured Housing";

							if (pip->pi_origterm >= 240) // term per Intex instructions re from Eknath at ADCO
								adco->original_term = 360;
							else
								adco->original_term = 180;
							break;
						default:
							intex_prepayment_model_supported = 0;
							break;
						}
					}
				else
					{
					adco->prepmt_model_defn = "MBS";
					
                    if (pip->pi_ltv > 0.0)
						adco->original_ltv = static_cast <double> (pip->pi_ltv);

					else if (pip->pi_amort_ltv > 0.0)
						adco->original_ltv = static_cast <double> (pip->pi_amort_ltv);
					else
						adco->original_ltv = static_cast <double> (pip->pi_orig_ltv);
								
					int init_reset = 0;
        
					if (pip->pi_armp != NULL && pip->pi_armp->armi_index != ARMI_INDEX_STEPUP)
						{
						if (pip->pi_armp->armi_in_teaser
							|| pip->pi_armp->armi_init_resetper > pip->pi_armp->armi_paym_resetper)
							{
							is_hybrid = true;
							
							if (pip->pi_armp->armi_init_resetper > 24 && pip->pi_armp->armi_init_resetper <= 48)
								init_reset = 3; // 3 yr
							else if (pip->pi_armp->armi_init_resetper > 48 && pip->pi_armp->armi_init_resetper <= 72)
								init_reset = 5; // 5 yr
							else if (pip->pi_armp->armi_init_resetper > 73 && pip->pi_armp->armi_init_resetper <= 102)
								init_reset = 7; // 7 yr
							else if (pip->pi_armp->armi_init_resetper > 103)
								init_reset = 10; // 10 yr
							else
								is_hybrid = false;
							}
						}
					
					switch (cftype)
						{
						case ICMOCFTYPE_UNDEFINED:
						case ICMOCFTYPE_GPM:
						case ICMOCFTYPE_TPM:
						case ICMOCFTYPE_ARM_YEN:
						case ICMOCFTYPE_TREAS_BOND:
						case ICMOCFTYPE_STEPUP:
							adco->mbs_prepmt_defn = "Fixed Rate";
							adco->mbs_collateral_defn = "FNMA";
							adco->original_term = 360;
							break;

						case ICMOCFTYPE_FIX_10YR:
							adco->mbs_prepmt_defn = "Fixed Rate";

							if (agencytype == ICMOAGENCY_FNMA)
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->original_term = 120;
								}
							else if (agencytype == ICMOAGENCY_FHLMC
									 || agencytype == ICMOAGENCY_FHLMG)
								{
								adco->mbs_collateral_defn = "FHLMC";
								adco->original_term = 120;
								}
							else if (agencytype == ICMOAGENCY_GNMA
									 || agencytype == ICMOAGENCY_GNMA2)
								{
								adco->mbs_collateral_defn = "GNMA";
								adco->original_term = 180;
								}
							else if (agencytype >= ICMOAGENCY_WL)
								{
								adco->mbs_collateral_defn = "Whole Loan";
								adco->original_term = 180;
								}
							else
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->original_term = 180;
								}
							break;
						case ICMOCFTYPE_FIX_15YR:
							adco->mbs_prepmt_defn = "Fixed Rate";

							if (agencytype == ICMOAGENCY_FNMA)
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->original_term = 180;
								}
							else if (agencytype == ICMOAGENCY_FHLMC
									 || agencytype == ICMOAGENCY_FHLMG)
								{
								adco->mbs_collateral_defn = "FHLMC";
								adco->original_term = 180;
								}
							else if (agencytype == ICMOAGENCY_GNMA)
								{
								adco->mbs_collateral_defn = "GNMA";
								adco->original_term = 180;
								}
							else if (agencytype == ICMOAGENCY_GNMA2)
								{
								adco->mbs_collateral_defn = "GNMA2";
								adco->original_term = 180;
								}
							else if (agencytype >= ICMOAGENCY_WL)
								{
								adco->mbs_collateral_defn = "Whole Loan";
								adco->original_term = 180;
								}
							else
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->original_term = 180;
								}
							break;
						case ICMOCFTYPE_FIX_20YR:
							adco->mbs_prepmt_defn = "Fixed Rate";

							if (agencytype == ICMOAGENCY_FNMA)
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->original_term = 240;
								}
							else if (agencytype == ICMOAGENCY_FHLMC
									 || agencytype == ICMOAGENCY_FHLMG)
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->original_term = 240;
								}
							else if (agencytype == ICMOAGENCY_GNMA
									 || agencytype == ICMOAGENCY_GNMA2)
								{
								adco->mbs_collateral_defn = "GNMA";
								adco->original_term = 180;
								}
							else if (agencytype >= ICMOAGENCY_WL)
								{
								adco->mbs_collateral_defn = "Whole Loan";
								adco->original_term = 180;
								}
							else
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->original_term = 240;
								}
							break;
						case ICMOCFTYPE_FIX_25YR:
						case ICMOCFTYPE_FIX_35YR:
						case ICMOCFTYPE_FIX_40YR:
							adco->mbs_prepmt_defn = "Fixed Rate";

							if (agencytype == ICMOAGENCY_FNMA)
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->original_term = 360;
								}
							else if (agencytype == ICMOAGENCY_FHLMC
									 || agencytype == ICMOAGENCY_FHLMG)
								{
								adco->mbs_collateral_defn = "FHLMC";
								adco->original_term = 360;
								}
							else if (agencytype == ICMOAGENCY_GNMA)
								{
								adco->mbs_collateral_defn = "GNMA";
								adco->original_term = 360;
								}
							else if (agencytype == ICMOAGENCY_GNMA2)
								{
								adco->mbs_collateral_defn = "GNMA2";
								adco->original_term = 360;
								}
							else if (agencytype >= ICMOAGENCY_WL)
								{
								adco->mbs_collateral_defn = "Whole Loan";
								adco->original_term = 360;
								}
							else
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->original_term = 360;
								}
							break;
						case ICMOCFTYPE_FIX_30YR:
							adco->mbs_prepmt_defn = "Fixed Rate";

							if (agencytype == ICMOAGENCY_FNMA)
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->original_term = 360;
								
								if (strcmp(pip->pi_type, "RE") == 0)
									{
									adco->mbs_collateral_defn = "RELO";
									adco->original_term = 360;
									}
								}
							else if (agencytype == ICMOAGENCY_FHLMC
									 || agencytype == ICMOAGENCY_FHLMG)
								{
								adco->mbs_collateral_defn = "FHLMC";
								adco->original_term = 360;
								if (strncmp(pip->pi_pnum, "880", 3) == 0)
									{
									adco->mbs_collateral_defn = "RELO";
									adco->original_term = 360;
									}
								}
							else if (agencytype == ICMOAGENCY_GNMA)
								{
								adco->mbs_collateral_defn = "GNMA";
								adco->original_term = 360;
								}
							else if (agencytype == ICMOAGENCY_GNMA2)
								{
								adco->mbs_collateral_defn = "GNMA2";
								adco->original_term = 360;
								}
							else if (agencytype >= ICMOAGENCY_WL)
								{
								adco->mbs_collateral_defn = "Whole Loan";
								adco->original_term = 360;
								}
							else
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->original_term = 360;
								}
							break;
						case ICMOCFTYPE_BLN_5YR:
							adco->mbs_prepmt_defn = "Fixed Rate";
							adco->balloon_term = 60;

							if (agencytype == ICMOAGENCY_FNMA)
								adco->mbs_collateral_defn = "FNMA";
							else if (agencytype == ICMOAGENCY_FHLMC
									 || agencytype == ICMOAGENCY_FHLMG)
								adco->mbs_collateral_defn = "FHLMC";
							else if (agencytype >= ICMOAGENCY_WL)
								adco->mbs_collateral_defn = "Whole Loan";
							else // others incl. wl balloon collateral default to fnma
								adco->mbs_collateral_defn = "FNMA";
							break;
						case ICMOCFTYPE_BLN_7YR:
							adco->mbs_prepmt_defn = "Fixed Rate";
							adco->balloon_term = 84;

							if (agencytype == ICMOAGENCY_FNMA)
								adco->mbs_collateral_defn = "FNMA";
							else if (agencytype == ICMOAGENCY_FHLMC
									 || agencytype == ICMOAGENCY_FHLMG)
								adco->mbs_collateral_defn = "FHLMC";
							else if (agencytype >= ICMOAGENCY_WL)
								adco->mbs_collateral_defn = "Whole Loan";
							else   // others incl. wl balloon collateral default to fnma
								adco->mbs_collateral_defn = "FNMA";
							break;
						case ICMOCFTYPE_BLN_10YR:  //note old ADCO 10YR types were NOT balloons
						case ICMOCFTYPE_BLN_15YR:
						case ICMOCFTYPE_BLN_OTHER:
							adco->mbs_prepmt_defn = "Fixed Rate";
							adco->balloon_term = 120;

							if (agencytype == ICMOAGENCY_FNMA)
								adco->mbs_collateral_defn = "FNMA";
							else if (agencytype == ICMOAGENCY_FHLMC
									 || agencytype == ICMOAGENCY_FHLMG)
								adco->mbs_collateral_defn = "FHLMC";
							else // others incl. wl balloon collateral default to fnma
								adco->mbs_collateral_defn = "FNMA";
							break;
						case ICMOCFTYPE_ARM_LIBOR_1MO:
						case ICMOCFTYPE_ARM_LIBOR_3MO:
						case ICMOCFTYPE_ARM_LIBOR_6MO:
						case ICMOCFTYPE_ARM_LIBOR_1YR:
						case ICMOCFTYPE_ARM_CMT_3MO:
						case ICMOCFTYPE_ARM_CMT_6MO:
						case ICMOCFTYPE_ARM_CMT_7YR:
						case ICMOCFTYPE_ARM_CMT_10YR:
						case ICMOCFTYPE_ARM_CMT_30YR:
						case ICMOCFTYPE_ARM_PRIME:
						case ICMOCFTYPE_ARM_CONTRACT:
						case ICMOCFTYPE_ARM_COF:
						case ICMOCFTYPE_ARM_6MO_CD:
						case ICMOCFTYPE_ARM_MONEY_MKT:
						case ICMOCFTYPE_ARM_MISC_1:
						case ICMOCFTYPE_ARM_MISC_2:
						case ICMOCFTYPE_ARM_MISC_3:
						//case ICMOCFTYPE_ARM_MTA_1YR:
						case ICMOCFTYPE_ARM_UNDEFINED:
							adco->mbs_prepmt_defn = "Fixed Rate";
							//if it is arm, is it convertible?
							if (pip->pi_armp != NULL)
								{
								adco->mbs_prepmt_defn = "ARM";
								
								if (pip->pi_armp->armi_convertable == TRUE)
									adco->adjustable_rate_defn = "Convertible";
								else
									adco->adjustable_rate_defn = "Non Convertible";
								}
							
							if (is_hybrid && (agencytype == ICMOAGENCY_FHLMC || agencytype == ICMOAGENCY_FHLMG))
								{
								adco->mbs_prepmt_defn = "Hybrid";

								switch (init_reset)
					                {
					                case 3:
										 adco->mbs_collateral_defn = "FHLMC";
										 adco->arm_reset_period = 36;
					                     break;
					                case 5:
										 adco->mbs_collateral_defn = "FHLMC";
										 adco->arm_reset_period = 60;
					                     break;
					                case 7:
										 adco->mbs_collateral_defn = "FHLMC";
										 adco->arm_reset_period = 84;
									     break;
					                case 10:
										 adco->mbs_collateral_defn = "FHLMC";
										 adco->arm_reset_period = 120;
					                     break;
					                default:
										 adco->mbs_collateral_defn = "FHLMC";
										 adco->arm_reset_period = 60;
					                     break;
									}
								}
							else if (is_hybrid) // non-agency and other agency hybrids default to FNM hybrid model
								{
								adco->mbs_prepmt_defn = "Hybrid";
								switch (init_reset)
									{
					                case 3:
										 adco->mbs_collateral_defn = "FNMA";
										 adco->arm_reset_period = 36;
					                     break;
					                case 5:
										 adco->mbs_collateral_defn = "FNMA";
										 adco->arm_reset_period = 60;
					                     break;
					                case 7:
										 adco->mbs_collateral_defn = "FNMA";
										 adco->arm_reset_period = 84;
					                     break;
					                case 10:
										 adco->mbs_collateral_defn = "FNMA";
										 adco->arm_reset_period = 120;
					                     break;
					                default :
										 adco->mbs_collateral_defn = "FNMA";
										 adco->arm_reset_period = 60;
					                     break;
					                }
					            }
							
							if (agencytype == ICMOAGENCY_FNMA)
								{
								adco->mbs_collateral_defn = "FNMA";

								if (adco->mbs_prepmt_defn == ARM)
									adco->arm_reset_period = 12;
								else
									adco->original_term = 360;
								}
							else if (agencytype == ICMOAGENCY_FHLMC
									 || agencytype == ICMOAGENCY_FHLMG)
								{
								adco->mbs_collateral_defn = "FHLMC";
								adco->arm_reset_period = 12;
								}
							else if (adco->mbs_prepmt_defn == ARM)
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->arm_reset_period = 12;
								}
							else
								{
								adco->mbs_prepmt_defn = "ARM";
								adco->adjustable_rate_defn = "Convertible";
								adco->arm_reset_period = 12;
								}
							break;

						case ICMOCFTYPE_ARM_COFI_11:
							adco->mbs_prepmt_defn = "Fixed Rate";
							//if it is arm, is it convertible?
							if (pip->pi_armp != NULL)
								{
								adco->mbs_prepmt_defn = "ARM";
								if (pip->pi_armp->armi_convertable == TRUE)
									adco->adjustable_rate_defn = "Convertible";
								else
									adco->adjustable_rate_defn = "Non Convertible";
								}
							adco->mbs_collateral_defn = "COFI";
							adco->arm_reset_period = 999;
							break;
						case ICMOCFTYPE_ARM_CMT_1YR:
							adco->mbs_prepmt_defn = "Fixed Rate";
							//if it is arm, is it convertible?
							if (pip->pi_armp != NULL)
								{
								adco->mbs_prepmt_defn = "ARM";
								adco->mbs_collateral_defn = "FNMA";
								adco->arm_reset_period = 12;
								if (pip->pi_armp->armi_convertable == TRUE)
									adco->adjustable_rate_defn = "Convertible";
								else
									adco->adjustable_rate_defn = "Non Convertible";
								}
					         
					         if (is_hybrid
					             && (agencytype == ICMOAGENCY_FHLMC || agencytype == ICMOAGENCY_FHLMG))
					            {
								adco->mbs_prepmt_defn = "Hybrid";
					            switch (init_reset)
					                {
					                case 3:
										 adco->mbs_collateral_defn = "FHLMC";
										 adco->arm_reset_period = 36;
					                     break;
					                case 5:
										 adco->mbs_collateral_defn = "FHLMC";
										 adco->arm_reset_period = 60;
					                     break;
					                case 7:
										 adco->mbs_collateral_defn = "FHLMC";
										 adco->arm_reset_period = 84;
					                     break;
					                case 10:
										 adco->mbs_collateral_defn = "FHLMC";
										 adco->arm_reset_period = 120;
					                     break;
					                default :
										 adco->mbs_collateral_defn = "FHLMC";
										 adco->arm_reset_period = 60;
					                     break;
					                }
					            }
					         else if (is_hybrid) // non-agency and non fhl hybrids default to hybrid model
					            {
								adco->mbs_prepmt_defn = "Hybrid";
					            switch (init_reset)
					                {
					                case 3:
										 adco->mbs_collateral_defn = "FNMA";
										 adco->arm_reset_period = 36;
					                     break;
					                case 5:
										 adco->mbs_collateral_defn = "FNMA";
										 adco->arm_reset_period = 60;
					                     break;
					                case 7:
										 adco->mbs_collateral_defn = "FNMA";
										 adco->arm_reset_period = 84;
					                     break;
					                case 10:
										 adco->mbs_collateral_defn = "FNMA";
										 adco->arm_reset_period = 120;
					                     break;
					                default:
										 adco->mbs_collateral_defn = "FNMA";
										 adco->arm_reset_period = 60;
					                     break;
					                }
					            }
						   
							if (agencytype == ICMOAGENCY_GNMA
								|| agencytype == ICMOAGENCY_GNMA2)
								{
								adco->mbs_collateral_defn = "GNMA";
								adco->arm_reset_period = 12;
								}
							else if (agencytype == ICMOAGENCY_FNMA)
								{
								adco->mbs_collateral_defn = "FNMA";

								if (adco->mbs_prepmt_defn == ARM)
									adco->arm_reset_period = 12;
								else
									{
									adco->mbs_prepmt_defn = "ARM";
									adco->adjustable_rate_defn = "Convertible";
									adco->arm_reset_period = 12;
									}
								}
							else if (agencytype == ICMOAGENCY_FHLMC
									 || agencytype == ICMOAGENCY_FHLMG)
								{
								adco->mbs_collateral_defn = "FHLMC";

								if (adco->mbs_prepmt_defn == ARM)
									adco->arm_reset_period = 12;
								else
									{
									adco->mbs_prepmt_defn = "ARM";
									adco->adjustable_rate_defn = "Convertible";
									adco->arm_reset_period = 12;
									}
								}
							else if (adco->mbs_prepmt_defn == ARM)
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->arm_reset_period = 12;
								}
							else
								{
								adco->mbs_prepmt_defn = "ARM";
								adco->adjustable_rate_defn = "Convertible";
								adco->mbs_collateral_defn = "FNMA";
								adco->arm_reset_period = 360;
								}
							break;
						case ICMOCFTYPE_ARM_CMT_3YR:
						case ICMOCFTYPE_ARM_CMT_2YR:
						case ICMOCFTYPE_ARM_CMT_5YR:
								adco->mbs_prepmt_defn = "Fixed Rate";
							//if it is arm, is it convertible?
							if (pip->pi_armp != NULL)
								{
								adco->mbs_prepmt_defn = "ARM";
								adco->mbs_collateral_defn = "FHLMC";
								adco->arm_reset_period = 36;

								if (pip->pi_armp->armi_convertable == TRUE)
 									adco->adjustable_rate_defn = "Convertible";
								else
									adco->adjustable_rate_defn = "Non Convertible";
								}
							
					        if (is_hybrid
					         	&& (agencytype == ICMOAGENCY_FHLMC || agencytype == ICMOAGENCY_FHLMG))
					            {
	                            adco->mbs_prepmt_defn = "Hybrid";
					            switch (init_reset)
					                {
					                case 3:
									     adco->mbs_collateral_defn = "FHLMC";
									     adco->arm_reset_period = 36;
					                     break;
					                case 5:
									     adco->mbs_collateral_defn = "FHLMC";
									     adco->arm_reset_period = 60;
					                     break;
					                case 7:
									     adco->mbs_collateral_defn = "FHLMC";
									     adco->arm_reset_period = 84;
					                     break;
					                case 10:
									     adco->mbs_collateral_defn = "FHLMC";
									     adco->arm_reset_period = 120;
					                     break;
					                default :
									     adco->mbs_collateral_defn = "FHLMC";
									     adco->arm_reset_period = 60;
					                     break;
					                }
					            }
					         else if (is_hybrid) // non-agency and non-fhl hybrids default to hybrid model
					            {
								adco->mbs_prepmt_defn = "Hybrid";
					            switch (init_reset)
					                {
					                case 3:
									     adco->mbs_collateral_defn = "FNMA";
									     adco->arm_reset_period = 36;
					                     break;
					                case 5:
									     adco->mbs_collateral_defn = "FNMA";
									     adco->arm_reset_period = 60;
					                     break;
					                case 7:
									     adco->mbs_collateral_defn = "FNMA";
									     adco->arm_reset_period = 84;
					                     break;
					                case 10:
									     adco->mbs_collateral_defn = "FNMA";
									     adco->arm_reset_period = 120;
					                     break;
					                default :
									     adco->mbs_collateral_defn = "FNMA";
									     adco->arm_reset_period = 60;
					                     break;
					                }
					            }
						    
							if ((agencytype == ICMOAGENCY_FHLMC
								 || agencytype == ICMOAGENCY_FHLMG)
								 && adco->mbs_prepmt_defn == ARM)
								{
								adco->mbs_collateral_defn = "FHLMC";
								adco->arm_reset_period = 36;
								}
							else if (agencytype == ICMOAGENCY_FNMA
								     && adco->mbs_prepmt_defn == ARM)
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->arm_reset_period = 36;
								}
							else if (adco->mbs_prepmt_defn == ARM)
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->arm_reset_period = 36;
								}
							else
								{
								adco->mbs_collateral_defn = "FNMA";
								adco->original_term = 360;
								}
							break;
						default:
							adco->mbs_prepmt_defn = "ARM";
							adco->mbs_collateral_defn = "FNMA";
							adco->arm_reset_period = 360;
							break;
						}
					}

			if (adco->mbs_collateral_defn == WHOLE_LOAN
				&& (adco->original_term == 180
					|| adco->original_term == 360))
				{
				if (pip->pi_agency == ICMOAGENCY_NMB
					|| pip->pi_agency == ICMOAGENCY_PHM
					|| pip->pi_agency == ICMOAGENCY_SASI)
					{ // check if relocation loan or ALT_A collateral
					if (pip->pi_loanattrp && pip->pi_loanattrp->loanattr_feature[0] == 'Y'
						&& (adco->mbs_collateral_defn == WHOLE_LOAN
							&& adco->original_term == 360))
						adco->mbs_collateral_defn = "RELO";
					}
				// we have checked for relocation loans, now let's check for ALT_A
				// currently, we have two ways to identify ALT_A collateral - as commercialop field, or
				// as addlinfo string
			   is_alt_a = FALSE;

			   if (pip->pi_loanattrp && pip->pi_loanattrp->loanattr_commercialopp)
					{
					for (comm_op = pip->pi_loanattrp->loanattr_commercialopp;
						 comm_op ;
						 comm_op = (COMMERCIAL_OP *)comm_op->commercialop_next)
						{
						if (strcmp (comm_op->commercialop_name, "ALT_A") != 0)
							continue;
						else if (strcmp (comm_op->commercialop_strval, "1") == 0)
							{
							is_alt_a = TRUE;
							break;
							}
						}

					if (is_alt_a && adco->mbs_collateral_defn == WHOLE_LOAN)
						adco->mbs_collateral_defn = "ALT A";
					}
			   else if ((!icmo_addl_info (pool_icmop, ICMOADDLINFO_COLLAT_TYPE, 0))
			   	        && (pool_icmop->icmo_addl_infop->retval_str != ICMOADDLINFO_RETVAL_STR_NA)
			   	        && (strcmp(pool_icmop->icmo_addl_infop->retval_str, "ALT_A") == 0))
					{
					if (adco->mbs_collateral_defn == WHOLE_LOAN)
						adco->mbs_collateral_defn = "ALT A";
					}
				}

				if (intex_prepayment_model_supported)
					{
					// Populate the rest of the adco parameters
					adco->asset_proj_defn = "Intex";
					adco->prepmt_forecast_defn = proj_defn;
					adco->valuation_period = t;
					adco->loaded_proj_task_loop = loaded_proj_task_loop;
                   
					// adco->use_eom_scen_rates = use_eom_scen_rates;
					if (use_eom_scen_rates == YES)
						adco->use_eom_scen_rates = "Yes";
					else
						adco->use_eom_scen_rates = "No";

					adco->shift_defn = shift_defn;
					adco->pv_timing = "End of Month";
					adco->asset_id = asset_id;
					adco->category_id = adco_category_id;
					adco->intex_dealname = dealname;
					adco->pool_id = ith_pool;
					adco->existing_asset_indicator = 1; //always an existing asset within intex

					adco->ms_rereadGrid();

					adco->valn_date_offset_mths = intex_cdu_months_offset;
					adco->offset_mths = uddp->t;
					adco->remaining_term = pip->pi_remterm;

					if (pip->pi_wala >= 0)
						adco->age = pip->pi_wala;
					else
						adco->age = pip->pi_origterm - pip->pi_remterm;
					
					adco->coupon = pip->pi_netcoupon + pip->pi_servfee;
                    adco->servicing_fee = pip->pi_servfee;
                    adco->current_face = pip->pi_factors[0] * pip->pi_origbal;
                    adco->original_face = pip->pi_origbal;

                    // adco->original_ltv & adco->original_face have already been set,
                    // so set up remaining loan level collateral definition items.
                    if (adco->prepmt_model_defn == MBS
						|| (adco->prepmt_model_defn == ABS && (adco->abs_prepmt_defn == ARM_HOME_EQUITY_LOAN 
						|| adco->abs_prepmt_defn == FIXED_HOME_EQUITY_LOAN)))
                    	{
                        char *loan_state = pip->pi_state;
                        
                        if (!(loan_state[0] == '\0')) // If not blank.
                        	{
                            SmartArray<double> local_states(53, 0); 
                            // vars passed byRef
                            get_loan_state(loan_state, local_states);

                            // make sure adco->states contains zero for every state element
                            for (int state = 0; state < 53; state++) 
                            adco->states[state] = 0.0;

                            for (int state = 0; state < 53; state++) 
                            adco->states[state] = local_states[state];
							}
						else	
                            adco->states[52] = 100.00; // set to unknown type

                        if (!(pip->pi_loanattrp == NULL))
                        	{
                            // Set property type
                            SmartArray<double> local_property_types(3, 0); 
                            
                            if (pip->pi_loanattrp->loanattr_property == "single-family")
                            	local_property_types[0] = 100.00;
                            else if (pip->pi_loanattrp->loanattr_property == "multiple-family") 
								local_property_types[1] = 100.00;   			
							else 
							    local_property_types[2] = 100.00; // set to "Unknown"
							// Pass to Adco
							for (int type = 0; type < 3; type++) 
                                 adco->property_types[type] = local_property_types[type];

                            // Set occupancy type
                            SmartArray<double> local_occupancy(4, 0); 

							if (pip->pi_loanattrp->loanattr_occupancy == "owner")
                            	local_occupancy[0] = 100.00;
                            else if (pip->pi_loanattrp->loanattr_occupancy == "second home") 
								local_occupancy[1] = 100.00;   						
							else if (pip->pi_loanattrp->loanattr_occupancy == "investor") 
								local_occupancy[2] = 100.00;   						
							else 
							    local_occupancy[3] = 100.00; // set to "Unknown"         
	                        
	                        // Pass to Adco
							for (int type = 0; type < 4; type++) 
                                 adco->occupancy[type] = local_occupancy[type];
                            
                            // Set loan purpose
                            SmartArray<double> local_loan_purpose(3, 0); 
                            
                            if (pip->pi_loanattrp->loanattr_purpose == "purchase")
                            	local_loan_purpose[0] = 100.00;
                            else if (pip->pi_loanattrp->loanattr_purpose == "refinance") 
								local_loan_purpose[1] = 100.00;   							
							else 
							    local_loan_purpose[2] = 100.00; // set to "Unknown"
							
							// Pass to Adco
							for (int type = 0; type < 3; type++) 
                                 adco->loan_purp[type] = local_loan_purpose[type];

							}
						}
                    // Setup ARM VARS
					if ((adco->prepmt_model_defn == ABS
						 && adco->abs_prepmt_defn == ARM_HOME_EQUITY_LOAN)
						 || (adco->prepmt_model_defn == MBS
						 	&& adco->mbs_prepmt_defn != FIXED_RATE))
						{
						// Set information particular for all arms so unified model can use
						adco->arm_flag = "Yes";
						adco->arm_first_reset_age = adco->arm_reset_period;
						adco->arm_max_rate = pip->pi_armp->armi_caplife;
						adco->arm_min_rate = pip->pi_armp->armi_flrlife;
						adco->arm_max_reset_period_rate = ((pip->pi_netcoupon + pip->pi_servfee)
                                                           + pip->pi_armp->armi_capresetper
                                                           - pip->pi_servfee);
                        
						adco->arm_min_reset_period_rate = max(0.0, ((pip->pi_netcoupon + pip->pi_servfee)
                                                              - pip->pi_armp->armi_flrresetper)
                                                              - pip->pi_servfee);
                       
                        adco->arm_reset_mths = pip->pi_armp->armi_paym_resetper;

                        int arm_lookback_days = pip->pi_armp->armi_lookback;

                        adco->arm_lookback_mths = ceil(((double)arm_lookback_days)/ 30.0);

                        switch(pip->pi_armp->armi_index)
                			{
                			case ICMOI_1MO_LIBOR:
                                    adco->arm_index_name = "LIBOR 1 Month";
                                    break;
                            case ICMOI_3MO_LIBOR:
                                    adco->arm_index_name = "LIBOR 3 Month";
                                    break;
                            case ICMOI_6MO_LIBOR:
                                    adco->arm_index_name = "LIBOR 6 Month";
                                    break;
                            case ICMOI_1YR_LIBOR:
                                    adco->arm_index_name = "LIBOR 1 Year";
                                    break;
                            case ICMOI_3MO_TREAS:
                                    adco->arm_index_name = "Govt 3 Month";
                                    break;
                            case ICMOI_1YR_TREAS:
                                    adco->arm_index_name = "Govt 1 Year";
                                    break;
                            case ICMOI_5YR_TREAS:
                                    adco->arm_index_name = "Govt 5 Year";
                                    break;
                            case ICMOI_7YR_TREAS:
                                    adco->arm_index_name = "Govt 7 Year";
                                    break;
                            case ICMOI_10YR_TREAS:
                                    adco->arm_index_name = "Govt 10 Year";
                                    break;
                            case ICMOI_COFI11:
                                    adco->arm_index_name = "COF 11 Dist";
                                    break;
                            case ICMOI_PRIME:
                                    adco->arm_index_name = "Bank Prime";
                                    break;
                            case ICMOI_3YR_TREAS:
                                    adco->arm_index_name = "Govt 3 Year";
                                    break;
                            case ICMOI_2YR_TREAS:
                                    adco->arm_index_name = "Govt 2 Year";
                                    break;
                            case ICMOI_6MO_TREAS:
                                    adco->arm_index_name = "Govt 6 Month";
                                    break;
                            case ICMOI_30YR_TREAS:
                                    adco->arm_index_name = "Govt 30 Year";
                                    break;
                            case ICMOI_CONTRACT:
                                    adco->arm_index_name = "Gen Contract";
                                    break;
                            case ICMOI_COF:
                                    adco->arm_index_name = "Gen COF";
                                    break;
                            case ICMOI_6MO_CD:
                                    adco->arm_index_name = "CD 6 Month";
                                    break;
                            case ICMOI_MONEY_MKT:
                                    adco->arm_index_name = "Money Mkt";
                                    break;
                            default:
                        		adco->arm_index_name = "Unknown";
                        	}                                                               

				        forecast_adj_wac_rate(icmop, pip, ith_pool, uddp->t);
						}
						
					adco->setup_prepmt_rates(t);
					}
				}
			for (int tt = 1; tt < adco->prepmt_rates.size(); tt++)
				updp->smm_forecast[tt - 1] = adco->get_prepmt_rate(tt);
			}
	#endif
		}
	}
}



#line 1 "resets_off.INTEX_ASSET.for"                                                                                   
void __cdecl INTEX_ASSET::resets_off(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
PIWORK     *piworkp;
ARM_INFO   *armp;

// This function is only used so that the current payment rate of the
// ARM will not change during the net yield calculation.

if ((armp = pip->pi_armp) != NULL
	&& (piworkp = pip->pi_workp) != NULL)
	{
	piworkp->piwork_to_int_reset += 1000;
	piworkp->piwork_to_pay_reset += 1000;
	armp->armi_ntillreset += 1000;
	armp->armi_paym_ntillreset += 1000;
	}
}



#line 1 "resets_on.INTEX_ASSET.for"                                                                                   
void __cdecl INTEX_ASSET::resets_on(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
PIWORK     *piworkp;
ARM_INFO   *armp;

// This function is only used so that the current payment rate of the
// ARM will not change during the net yield calculation.

if ((armp = pip->pi_armp) != NULL
	&& (piworkp = pip->pi_workp) != NULL)
	{
	piworkp->piwork_to_int_reset -= 1000;
	piworkp->piwork_to_pay_reset -= 1000;
	armp->armi_ntillreset -= 1000;
	armp->armi_paym_ntillreset -= 1000;
	}
}



#line 1 "restore_pool_data.INTEX_ASSET.for"                                                                                   
void __cdecl INTEX_ASSET::restore_pool_data(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
DEAL_DATA *uddp;
POOL_DATA *updp;

uddp = reinterpret_cast <DEAL_DATA *> (icmop->icmo_user);
updp = reinterpret_cast <POOL_DATA *> (pip->pi_user);

intex_pool_number += 1;

if (ith_pool == TempPD[intex_pool_number].poolnum)
	{
	// Restore the data
	updp->poolnum = TempPD[intex_pool_number].poolnum;
	updp->cppresvalue = TempPD[intex_pool_number].cppresvalue;

	memcpy(updp->vcpcashflow, TempPD[intex_pool_number].vcpcashflow,
			((icmop->icmo_max_cf_vectsize+1) * sizeof(double)));
	memcpy(updp->vcpprincipal, TempPD[intex_pool_number].vcpprincipal, 
			((icmop->icmo_max_cf_vectsize+1) * sizeof(double)));
	memcpy(updp->vcpinterest, TempPD[intex_pool_number].vcpinterest, 
			((icmop->icmo_max_cf_vectsize+1) * sizeof(double)));
	memcpy(updp->vcpbalance, TempPD[intex_pool_number].vcpbalance, 
			((icmop->icmo_max_cf_vectsize+1) * sizeof(double)));

	if (TempPD[ith_pool].smm_forecast != NULL)
		memcpy(updp->smm_forecast, TempPD[intex_pool_number].smm_forecast, 
			((600) * sizeof(double)));

	updp->refinrate = TempPD[intex_pool_number].refinrate;
	updp->remterm = TempPD[intex_pool_number].remterm;

#if INTEX_CASH_FLOW_POOL_DETAIL
if (intex_detail_wanted
		&& (ith_pool == INTEX_CASH_FLOW_POOL_DETAIL || INTEX_CASH_FLOW_POOL_DETAIL == -1))
	log_screen << "itx4-> pool#=" << setw(3) << ith_pool
			<< " cpval=" << setw(18) << setprecision(8) << updp->cppresvalue
			<< " refin=" << setw(18) << setprecision(14) << updp->refinrate
			<< " term=" << setw(3) << updp->remterm
			<< " prepay_mode=" << (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD ? "DO_PREPAY_ONE_PERIOD"
								: (intex_prepmt_function_mode == DO_PREPAY_TO_MATURITY ? "DO_PREPAY_TO_MATURITY"
								: (intex_prepmt_function_mode == NO_PREPAYMENTS ? "NO_PREPAYMENTS" : "???")))
			<< " |restore_pool_data"
			<< MSG_USER;
#endif

	}
else
	{
	throw FatalError("Attempting to restore data from incorrect pool number "
					 "during Intex projection for "
					 + asset_id + 
					 ". Please contact the help desk. ");
	}
}



#line 1 "save_pool_data.INTEX_ASSET.for"                                                                                   
void __cdecl INTEX_ASSET::save_pool_data(struct _ICMO *icmop, char *dealname, struct _POOL_INFO *pip, int ith_pool)
{
DEAL_DATA *uddp;
POOL_DATA *updp;

uddp = reinterpret_cast <DEAL_DATA *> (icmop->icmo_user);
updp = reinterpret_cast <POOL_DATA *> (pip->pi_user);

intex_pool_number += 1;

// allocate memory for saved structure if necessary
if (TempPD[intex_pool_number].vcpcashflow == NULL)
	TempPD[intex_pool_number].vcpcashflow
	= new double[icmop->icmo_max_cf_vectsize + 1];

if (TempPD[intex_pool_number].vcpbalance == NULL)
	TempPD[intex_pool_number].vcpbalance
	= new double[icmop->icmo_max_cf_vectsize + 1];

if (TempPD[intex_pool_number].vcpprincipal == NULL)
	TempPD[intex_pool_number].vcpprincipal
	= new double[icmop->icmo_max_cf_vectsize + 1];

if (TempPD[intex_pool_number].vcpinterest == NULL)
	TempPD[intex_pool_number].vcpinterest
	= new double[icmop->icmo_max_cf_vectsize + 1];

if (prepmt_model_defn == ANDREW_DAVIDSON)
	{
	if (TempPD[intex_pool_number].smm_forecast == NULL)
		TempPD[intex_pool_number].smm_forecast
		= new double[600];
	}

// Save the data
TempPD[intex_pool_number].poolnum = updp->poolnum;
TempPD[intex_pool_number].cppresvalue = updp->cppresvalue;

memcpy(TempPD[intex_pool_number].vcpcashflow,updp->vcpcashflow,
		   ((icmop->icmo_max_cf_vectsize+1) * sizeof(double)));
memcpy(TempPD[intex_pool_number].vcpprincipal,updp->vcpprincipal, 
			((icmop->icmo_max_cf_vectsize+1) * sizeof(double)));
memcpy(TempPD[intex_pool_number].vcpinterest,updp->vcpinterest,  
			 ((icmop->icmo_max_cf_vectsize+1) * sizeof(double)));
memcpy(TempPD[intex_pool_number].vcpbalance,updp->vcpbalance, 
		    ((icmop->icmo_max_cf_vectsize+1) * sizeof(double)));

if (TempPD[intex_pool_number].smm_forecast != NULL)
    memcpy(TempPD[intex_pool_number].smm_forecast, updp->smm_forecast,
    		((600) * sizeof(double)));

TempPD[intex_pool_number].refinrate = updp->refinrate;
TempPD[intex_pool_number].remterm = updp->remterm;

#if INTEX_CASH_FLOW_POOL_DETAIL
if (intex_detail_wanted
	&& (ith_pool == INTEX_CASH_FLOW_POOL_DETAIL || INTEX_CASH_FLOW_POOL_DETAIL == -1))
	log_screen << "itx4-> pool#=" << setw(3) << ith_pool
			<< " cpval=" << setw(18) << setprecision(8) << updp->cppresvalue
			<< " refin=" << setw(18) << setprecision(14) << updp->refinrate
			<< " term=" << setw(3) << updp->remterm
			<< " prepay_mode=" << (intex_prepmt_function_mode == DO_PREPAY_ONE_PERIOD ? "DO_PREPAY_ONE_PERIOD"
								: (intex_prepmt_function_mode == DO_PREPAY_TO_MATURITY ? "DO_PREPAY_TO_MATURITY"
								: (intex_prepmt_function_mode == NO_PREPAYMENTS ? "NO_PREPAYMENTS" : "???")))
			<< " |save_pool_data"
			<< MSG_USER;
#endif

}



#line 1 "setup_asset_data.INTEX_ASSET.for"                                                                                   
int INTEX_ASSET::setup_asset_data(void)
{
DEAL_DATA *uddp;
uddp = reinterpret_cast <DEAL_DATA *> (icmop->icmo_user);
pThis = this;

// setup optional redemption
icmop->icmo_do_optredeem = TRUE;

setup_cp_data(1);

// set payment to payment mode
icmo_set_pmt_to_pmt_mode(icmop, 0L, 
	prepayment_rate_callback_function, 
	index_rate_callback_function,
	intex_tranche_number, NULL);

if (asset_detail_rpt_flag == YES)
	init_deal_detail();

// Setup Prepayment Model
// uddp->proj_type = proj_defn;
if (proj_defn == EXPERIENCE)
	uddp->proj_type = "Experience";
else if (proj_defn == NET_YIELD)
	uddp->proj_type = "Net Yield";
else // (proj_defn == MARKET_VALUE)
	uddp->proj_type = "Market Value";

icmo_count_npools(icmop, prepayment_setup_callback_function);

if (!active_tranche_flag(0))
	{
	clear_asset_data();

	return 0;
	}

return 1;
}



#line 1 "setup_cp_data.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::setup_cp_data(int setup)
{
pThis = this;

if (setup)
	{
	// setup cp asset
	intex_default_rates = new double[icmop->icmo_max_cf_vectsize + 1];
	memset(intex_default_rates, 0, sizeof(double)*(icmop->icmo_max_cf_vectsize + 1));
	intex_severity_rates = new double[icmop->icmo_max_cf_vectsize + 1];
	memset(intex_severity_rates, 0, sizeof(double)*(icmop->icmo_max_cf_vectsize + 1));

	icmop->icmo_cfassum.cfa_loss_type = ICMODEFAULT_VMDR;
	icmop->icmo_cfassum.cfa_loss_n_defaults = icmop->icmo_max_cf_vectsize;
	icmop->icmo_cfassum.cfa_loss_vdefaults = intex_default_rates;
	icmop->icmo_cfassum.cfa_loss_n_severity = icmop->icmo_max_cf_vectsize;
	icmop->icmo_cfassum.cfa_loss_vseverity = intex_severity_rates;

	// Setup for Balloon Extensions memory handling 
	icmop->icmo_balloonext_nmonths_max = 12;

	// Setup Line of Credit Draws handling 
	intex_draw_rates = new double[2];
	memset(intex_draw_rates, 0, sizeof(double)*(2));
	intex_draw_utilization_rates = new double[2];
	memset(intex_draw_utilization_rates, 0, sizeof(double)*(2));
	icmop->icmo_cfassum.cfa_draw_type = ICMOSPDT_VCPR;
	icmop->icmo_cfassum.cfa_draw_n_rates = 1;
	icmop->icmo_cfassum.cfa_draw_vrates = intex_draw_rates;
	icmop->icmo_cfassum.cfa_draw_n_utilizations = 1;
	icmop->icmo_cfassum.cfa_draw_vutilizations = intex_draw_utilization_rates;
	}

// Intialize POOL_DATA variables for each pool
icmo_count_npools(icmop, initialize_pool_data_callback_function);

if (setup)
	icmo_get_collat_cf(icmop, collat_callback_function, NULL);

intex_collat_defaults = 0;
intex_collat_schpay = 0;
intex_collat_prinpay = 0;
intex_collat_interest = 0;
intex_collat_balance = 0;
}



#line 1 "setup_psa_base_rate.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::setup_psa_base_rate()
{
psa_base_rate.resize(31);

psa_base_rate[0] = 0.0;

for (int month = 1; month <= 30; month++)
	psa_base_rate[month]
	= psa_base_rate[month - 1] + .002;

return;
}



#line 1 "setup_yld_curve.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::setup_yld_curve(int t, int shift_defn)
{
vyldcrv_vals[0]
= rates->get_int_rate(t,
	    "Govt",
		GET_YIELD_RATE,
		0.25, 0.0,
		NOMINAL_SEMIANNUAL,
		shift_defn,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

vyldcrv_vals[1]
= rates->get_int_rate(t,
	    "Govt",
		GET_YIELD_RATE,
		0.5, 0.0,
		NOMINAL_SEMIANNUAL,
		shift_defn,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

vyldcrv_vals[2]
= rates->get_int_rate(t,
	    "Govt",
		GET_YIELD_RATE,
		1.0, 0.0,
		NOMINAL_SEMIANNUAL,
		shift_defn,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

vyldcrv_vals[3]
= rates->get_int_rate(t,
	    "Govt",
		GET_YIELD_RATE,
		2.0, 0.0,
		NOMINAL_SEMIANNUAL,
		shift_defn,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

vyldcrv_vals[4]
= rates->get_int_rate(t,
	    "Govt",
		GET_YIELD_RATE,
		3.0, 0.0,
		NOMINAL_SEMIANNUAL,
		shift_defn,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

vyldcrv_vals[5]
= rates->get_int_rate(t,
	    "Govt",
		GET_YIELD_RATE,
		5.0, 0.0,
		NOMINAL_SEMIANNUAL,
		shift_defn,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

vyldcrv_vals[6]
= rates->get_int_rate(t,
	    "Govt",
		GET_YIELD_RATE,
		7.0, 0.0,
		NOMINAL_SEMIANNUAL,
		shift_defn,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

vyldcrv_vals[7]
= rates->get_int_rate(t,
	    "Govt",
		GET_YIELD_RATE,
		10.0, 0.0,
		NOMINAL_SEMIANNUAL,
		shift_defn,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ

vyldcrv_vals[8]
= rates->get_int_rate(t,
	    "Govt",
		GET_YIELD_RATE,
		30.0, 0.0,
		NOMINAL_SEMIANNUAL,
		shift_defn,0);//AIG - ADD PARAMETER FOR PORTFOLIO SPRD ADJ
}



#line 1 "tranche_detail.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::tranche_detail(int t, int write_projection_header)
{
if (write_projection_header)
	ITXFile << endl
			<< "Projection Information for " << proj_defn << endl
			<< "Cash Flow Projection (offset=" << intex_cdu_months_offset << ")" << endl
			<< "Year,Mth,CollDflt,CollSchPay,CollPrePay,CollIntPay,CollatBal,|||,Principal,PrePayment,Interest,CashFlow,Balance" << endl;

if (active_tranche_flag(t - 1)
	&& asset_detail_rpt_start_period <= t
	&& asset_detail_rpt_final_period >= t)
	{
	double pmt_rate = 0;

	if (get_tranche_bal(t - 1) != 0)
		pmt_rate = get_tranche_int_pmt(t)
				   / get_tranche_bal(t - 1)
				   * icmop->icmo_tranche_freqs[intex_tranche_number];
	else 
		pmt_rate = 0.0;

	//collateral projection detail
	ITXFile << xint(cal_yr(t)) << ","
			<< xint(cal_mth(t)) << ",";

	if (proj_defn == EXPERIENCE)
		ITXFile << intex_collat_defaults << ","
				<< intex_collat_schpay << ","
				<< intex_collat_prepay << ","
				<< intex_collat_interest << ","
				<< intex_collat_balance << ","
				<< "|||,";
	else
		ITXFile << 0.0 << "," 
				<< 0.0 << "," 
				<< 0.0 << "," 
				<< 0.0 << "," 
				<< 0.0 << ","
				<< "|||,";

	// owned tranche projection detail
	ITXFile << get_tranche_prin_pmt(t) << ","
			<< get_collateral_prepmt(t) << ","
			<< get_tranche_int_pmt(t) << ","
			<< get_tranche_cash_flow(t) << ","
			<< get_tranche_bal(t) << endl;
	}
}



#line 1 "unload_library.INTEX_ASSET.for"                                                                                   
void INTEX_ASSET::unload_library()
{
if (hIntexDLL != NULL)
	{
	FreeLibrary(hIntexDLL);
	hIntexDLL = NULL;
	}
}



#line 1 "valid_asset_flag.INTEX_ASSET.for"                                                                                   
int INTEX_ASSET::valid_asset_flag(const xstring &project_asset, xstring &error_message)
{
char deal_name[100];
char tranche_name[100];
DEAL_DATA * uddp;

// verify asset can be projected using intex
char* asset_id_buffer = new char[asset_id.length() + 1];
strncpy(asset_id_buffer, asset_id.c_str(), asset_id.length());
asset_id_buffer[asset_id.length()] = 0;

if (!icmodb_cusip_to_bond(icmodbp, asset_id_buffer, deal_name, tranche_name))
	{
	asset_id = asset_id_buffer;
	delete[] asset_id_buffer;
	if (isMainModel)
		error_message = "Intex Pre-projection Not Applicable for "
				        + asset_id 
						+ ": Not found in Intex Database.";
	else if (issue_messages)
		log_screen << "Intex Pre-projection Not Applicable for "
				   << asset_id 
				   << ": Not found in Intex Database." << MSG_ERROR;

	return 0;
   }

asset_id = asset_id_buffer;
delete[] asset_id_buffer;

// Set up additional icmomiscp settings
icmomiscp->icmomisc_alteruse.altu_single_tranche_only = tranche_name;

// Parse with lockout, points, Yield Maintenance is NOT supported in pmt_to_pmt mode
icmomiscp->icmomisc_altercollat.altc_include_prepaypenalty = ICMOPREPAYPENALTY_POINTS;

// Add additional room to the cf vect size
icmomiscp->icmomisc_override_max_cf_vectsize = ICMO_MAX_CF_VECTSIZE_ADDL(12);

// Setup Settle Date from input
if (proj_start_mth > 1)
	settle_date = (long)(proj_start_yr * 10000.00
						 + (proj_start_mth - 1) * 100.00 + 30);
else
	settle_date = (long)((proj_start_yr - 1) * 10000.00
						 + 12 * 100.00 + 30);

// Parse the deal
icmop = icmo_deal(icmomiscp, NULL, deal_name, ICMODEAL_SEASONED_WAVG,
                  settle_date, 0, 0, NULL, NULL);

if (icmop == NULL)
	{
	if (isMainModel)
		error_message = "Intex Pre-projection Not Applicable for "
       					+ asset_id + ": Unable to parse deal "
						+ xstring(deal_name) + ".";
	else if (issue_messages)
		log_screen << "Intex Pre-projection Not Applicable for "
				   << asset_id << ": Unable to parse deal "
				   << xstring(deal_name) << "." << MSG_ERROR;
	return 0;
	}

// Set Tranche Number from Tranche Name
intex_tranche_number = icmo_tranchenum(icmop, tranche_name);

if (intex_tranche_number < 0)
	{
	if (isMainModel)
		error_message = "Intex Pre-projection Not Applicable for "
						+ asset_id + ": Tranche "
						+ xstring(tranche_name) + "does not exist in deal "
						+ xstring(icmop->icmo_dealname) + ".";
	else if (issue_messages)
		log_screen << "Intex Pre-projection Not Applicable for "
				   << asset_id << ": Tranche "
				   << xstring(tranche_name) << "does not exist in deal "
				   << xstring(icmop->icmo_dealname) << MSG_ERROR;

	return 0;
	}

if (!isMainModel)
	{
	if (asset_defn == MBS
			&& stricmp(icmop->icmo_tranche_types[intex_tranche_number], "MBSPOOL"))
		{
		if (issue_messages)
			log_screen << "Intex Pre-projection Not Applicable for "
								<< asset_id 
								<< ": Asset is not an Intex MBS pool asset "
								<< "but is entered as a mortgage. "
								<< "Please correct your data." << MSG_ERROR;
	
		return 0;
		}
	
	if (asset_defn == CMO)
		{
		if (!stricmp(icmop->icmo_tranche_types[intex_tranche_number], "MBSPOOL"))
			{
			if (issue_messages)
				log_screen << "Intex Pre-projection Not Applicable for "
						   << asset_id 
						   << ": Asset is not an Intex SEC asset "
						   << "but is entered as a Securitized asset. "
						   << "Please correct your data." << MSG_ERROR;
		
			return 0;
			}

		if (icmop->icmo_collat_wavg->pi_pibondp != NULL)
			{
			if (issue_messages)
				log_screen << "Intex Pre-projection Not Applicable for "
							 + asset_id
							 + ": SEC utilizes bond collateral. These cannot currently be "
							 + "pre-projected using Intex." << MSG_ERROR;

			return 0;
			}
		}

	if (cost_basis_defn != AMORTIZED_COST
		|| bk_val_defn != COST_BASIS)
		{
		if (issue_messages)
			log_screen << "Intex Pre-projection Not Applicable for "
					   << asset_id
					   << ": An Intex Pre-Projection is not possible since "
					   << "the Accounting Definitions are not Amortized Cost." << MSG_ERROR;
	
		return 0;
		}
	}

if (icmo_YyyyMmDd_diffmo(icmop->icmo_latest_cdu_date, icmop->icmo_base_cdu_date) < 0)
	{
	intex_cdu_months_offset = icmo_YyyyMmDd_diffmo(icmop->icmo_base_cdu_date,
												   icmop->icmo_latest_cdu_date);
	if (issue_messages
		&& project_asset == "Yes")
		log_screen << "Intex Pre-projection for "
				   << asset_id
				   << " was performed using the "
				   << xstring(icmo_YyyyMmDd_conv_to_yymm(icmop->icmo_latest_cdu_date))
				   << " CDU since a "
				   << xstring(icmo_YyyyMmDd_conv_to_yymm(icmop->icmo_base_cdu_date))
				   << " CDU could not be found for deal "
				   << xstring(icmop->icmo_dealname) + "." << MSG_ERROR;

	settle_date = icmo_YyyyMmDd_addmo(settle_date, - intex_cdu_months_offset, TRUE);

	icmo_free(&icmop);

	if (- intex_cdu_months_offset < t_low)
		{
		log_screen << "Error. The 'Proj Period Min' property"
				<< " on the Projection Property Run Control panel"
				<< " must be reset to " << - intex_cdu_months_offset
				<< " or less before this projection task will run."
				<< MSG_ERROR;
				
		intex_fatal_error = true;

		return 0; // cannot process this model point
		}

	icmop = icmo_deal(icmomiscp, NULL, deal_name, ICMODEAL_SEASONED_WAVG,
					  settle_date, 0, 0, NULL, NULL);        
	}

if (project_asset == "No")
	{
	// Determine the maturity period by a force call
	int temp = get_tranche_maturity_period;

	icmo_free(&icmop);
	
	return 1;
	}

intex_number_of_pools = 0;
intex_pool_number = 0;

// populate user deal data structure
uddp = new DEAL_DATA;
uddp->t = 0;
icmop->icmo_user = reinterpret_cast <char *> (uddp);

// allocate memory for yield curve
vyldcrv_nodes = new double[N_YLDCRV_NODES];
vyldcrv_vals  = new double[N_YLDCRV_NODES];

// Allocate Memory reinvestment rates
intex_num_reinv_rates = 1;
intex_reinv_rates = new double[intex_num_reinv_rates];

intex_number_of_pools = icmo_count_npools(icmop, NULL);

TempPD = new POOL_DATA[intex_number_of_pools + 1];
memset(TempPD, 0, sizeof(POOL_DATA)*(intex_number_of_pools + 1));

if (!setup_asset_data())
	return 0;

return 1;
}



	static INTEX_ASSET_UDF *modelOffset		= 0;

 // Column Definition Begins

//Column Definition END@2

#pragma optimize( "g", on )
typedef double (ModelClass::*dPFi) (int);
typedef double (ModelClass::*dPFid) (int, double);
typedef double (INTEX_ASSET_UDF::*dPXi) (int);
typedef double (INTEX_ASSET_UDF::*dPXid) (int, double);
typedef double (INTEX_ASSET_UDF::*dPF) ();
typedef double (INTEX_ASSET_UDF::*dPFd) (double);
typedef int (INTEX_ASSET_UDF::*iPF) ();
typedef int (INTEX_ASSET_UDF::*iPFi) (int);
typedef xstring (INTEX_ASSET_UDF::*sPF) ();
typedef xstring (INTEX_ASSET_UDF::*sPFs) (xstring);

const CashFlowCommonData INTEX_ASSET::mCFStaticData_0[] = 
{
	CashFlowCommonData(0, "cashFlowName", "formulaId", "columnHdr", CashFlowCommonData::SUM, 
                     nullptr, 'E', 'N', '3', 'C', 0),
	CashFlowCommonData(1, "active_tranche_flag", "intex_asset_active_tranche_flag",  "active_tranche_flag",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_active_tranche_flag, 'E','N', '3', 'C', (size_t)&modelOffset->active_tranche_flag),
	CashFlowCommonData(2, "cal_mth", "intex_asset_cal_mth",  "cal_mth",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_cal_mth, 'E','N', '3', 'P', (size_t)&modelOffset->cal_mth),
	CashFlowCommonData(3, "cal_yr", "intex_asset_cal_yr",  "cal_yr",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_cal_yr, 'E','N', '3', 'P', (size_t)&modelOffset->cal_yr),
	CashFlowCommonData(4, "cal_yr_relative", "intex_asset_cal_yr_relative",  "cal_yr_relative",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_cal_yr_relative, 'E','N', '3', 'P', (size_t)&modelOffset->cal_yr_relative),
	CashFlowCommonData(5, "date", "intex_asset_date",  "date",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_date, 'E','N', '3', 'P', (size_t)&modelOffset->date),
	CashFlowCommonData(6, "finalize", "intex_asset_finalize",  "finalize",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_finalize, 'E','N', '3', 'N', (size_t)&modelOffset->finalize),
	CashFlowCommonData(7, "get_collateral_prepmt", "intex_asset_get_collateral_prepmt",  "get_collateral_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_get_collateral_prepmt, 'E','Y', '3', 'P', (size_t)&modelOffset->get_collateral_prepmt),
	CashFlowCommonData(8, "get_tranche_accr_int", "intex_asset_get_tranche_accr_int",  "get_tranche_accr_int",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_get_tranche_accr_int, 'E','N', '3', 'C', (size_t)&modelOffset->get_tranche_accr_int),
	CashFlowCommonData(9, "get_tranche_accr_int_bef_prepmt", "intex_asset_get_tranche_accr_int_bef_prepmt",  "get_tranche_accr_int_bef_prepmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_get_tranche_accr_int_bef_prepmt, 'E','N', '3', 'C', (size_t)&modelOffset->get_tranche_accr_int_bef_prepmt),
	CashFlowCommonData(10, "get_tranche_bal", "intex_asset_get_tranche_bal",  "get_tranche_bal",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_get_tranche_bal, 'E','N', '3', 'P', (size_t)&modelOffset->get_tranche_bal),
	CashFlowCommonData(11, "get_tranche_cash_flow", "intex_asset_get_tranche_cash_flow",  "get_tranche_cash_flow",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_get_tranche_cash_flow, 'E','Y', '3', 'P', (size_t)&modelOffset->get_tranche_cash_flow),
	CashFlowCommonData(12, "get_tranche_int_pmt", "intex_asset_get_tranche_int_pmt",  "get_tranche_int_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_get_tranche_int_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->get_tranche_int_pmt),
	CashFlowCommonData(13, "get_tranche_mths_to_reset", "intex_asset_get_tranche_mths_to_reset",  "get_tranche_mths_to_reset",  CashFlowCommonData::AVG,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_get_tranche_mths_to_reset, 'E','N', '3', 'C', (size_t)&modelOffset->get_tranche_mths_to_reset),
	CashFlowCommonData(14, "get_tranche_prin_pmt", "intex_asset_get_tranche_prin_pmt",  "get_tranche_prin_pmt",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_get_tranche_prin_pmt, 'E','Y', '3', 'P', (size_t)&modelOffset->get_tranche_prin_pmt),
	CashFlowCommonData(15, "initialize", "intex_asset_initialize",  "initialize",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::intex_asset_initialize, 'E','Y', '3', 'N', (size_t)&modelOffset->initialize),
	CashFlowCommonData(16, "startup", "intex_asset_startup",  "startup",  CashFlowCommonData::SUM,
                     (dPFi)(dPXi)&INTEX_ASSET_UDF::virtual_startup, 'E','N', '3', 'N', (size_t)&modelOffset->startup)
};
const CashFlowCommonData* INTEX_ASSET::mCFStaticData[] = {
	&INTEX_ASSET::mCFStaticData_0[0],
	&INTEX_ASSET::mCFStaticData_0[1],
	&INTEX_ASSET::mCFStaticData_0[2],
	&INTEX_ASSET::mCFStaticData_0[3],
	&INTEX_ASSET::mCFStaticData_0[4],
	&INTEX_ASSET::mCFStaticData_0[5],
	&INTEX_ASSET::mCFStaticData_0[6],
	&INTEX_ASSET::mCFStaticData_0[7],
	&INTEX_ASSET::mCFStaticData_0[8],
	&INTEX_ASSET::mCFStaticData_0[9],
	&INTEX_ASSET::mCFStaticData_0[10],
	&INTEX_ASSET::mCFStaticData_0[11],
	&INTEX_ASSET::mCFStaticData_0[12],
	&INTEX_ASSET::mCFStaticData_0[13],
	&INTEX_ASSET::mCFStaticData_0[14],
	&INTEX_ASSET::mCFStaticData_0[15],
	&INTEX_ASSET::mCFStaticData_0[16],
	nullptr};
//const CashFlowCommonData END@2

// all the StringEnumLists will be generated here
namespace {
	typedef EnumList::ChoicePair ChoicePair;

	// EnumList for asset_defn                                                                                       
	const ChoicePair asset_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::MBS, "MBS")
		,ChoicePair(StrEnum::CMO, "CMO")
		,ChoicePair(StrEnum::SEC, "SEC")
	};
	const EnumList asset_defnEnumList(3, asset_defnChoicePairs);

	// EnumList for asset_detail_rpt_defn                                                                                       
	const ChoicePair asset_detail_rpt_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList asset_detail_rpt_defnEnumList(2, asset_detail_rpt_defnChoicePairs);

	// EnumList for balloon_extension                                                                                       
	const ChoicePair balloon_extensionChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO, "No")
		,ChoicePair(StrEnum::YES, "Yes")
	};
	const EnumList balloon_extensionEnumList(2, balloon_extensionChoicePairs);

	// EnumList for bk_val_defn                                                                                       
	const ChoicePair bk_val_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::COST_BASIS, "Cost Basis")
	};
	const EnumList bk_val_defnEnumList(1, bk_val_defnChoicePairs);

	// EnumList for cost_basis_defn                                                                                       
	const ChoicePair cost_basis_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ACTUAL_COST, "Actual Cost")
		,ChoicePair(StrEnum::AMORTIZED_COST, "Amortized Cost")
	};
	const EnumList cost_basis_defnEnumList(2, cost_basis_defnChoicePairs);

	// EnumList for int_diff_defn                                                                                       
	const ChoicePair int_diff_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::GROSS_INTEREST_RATE, "Gross Interest Rate")
		,ChoicePair(StrEnum::INTEREST_RATE, "Interest Rate")
		,ChoicePair(StrEnum::NET_YIELD, "Net Yield")
	};
	const EnumList int_diff_defnEnumList(3, int_diff_defnChoicePairs);

	// EnumList for io_po_defn                                                                                       
	const ChoicePair io_po_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NOT_ASSIGNED, "Not Assigned")
		,ChoicePair(StrEnum::BOTH, "Both")
		,ChoicePair(StrEnum::IO, "IO")
		,ChoicePair(StrEnum::PO, "PO")
	};
	const EnumList io_po_defnEnumList(4, io_po_defnChoicePairs);

	// EnumList for prepmt_defn                                                                                       
	const ChoicePair prepmt_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::ABSOLUTE_PERCENTAGE, "Absolute Percentage")
		,ChoicePair(StrEnum::PERCENT_OF_PSA, "Percent of PSA")
	};
	const EnumList prepmt_defnEnumList(2, prepmt_defnChoicePairs);

	// EnumList for prepmt_model_defn                                                                                       
	const ChoicePair prepmt_model_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::SPLINE, "Spline")
		,ChoicePair(StrEnum::ANDREW_DAVIDSON, "Andrew Davidson")
	};
	const EnumList prepmt_model_defnEnumList(2, prepmt_model_defnChoicePairs);

	// EnumList for proj_defn                                                                                       
	const ChoicePair proj_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::EXPERIENCE, "Experience")
		,ChoicePair(StrEnum::NET_YIELD, "Net Yield")
		,ChoicePair(StrEnum::MARKET_VALUE, "Market Value")
	};
	const EnumList proj_defnEnumList(3, proj_defnChoicePairs);

	// EnumList for refinancing_rate_defn                                                                                       
	const ChoicePair refinancing_rate_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::REFINANCING_RATE, "Refinancing Rate")
		,ChoicePair(StrEnum::CATEGORY_YIELD_TO_MATURITY, "Category Yield to Maturity")
	};
	const EnumList refinancing_rate_defnEnumList(2, refinancing_rate_defnChoicePairs);

	// EnumList for shift_defn                                                                                       
	const ChoicePair shift_defnChoicePairs[] = {
		ChoicePair(StrEnum::UNDEFINED, StrEnum::undefinedString)
		,ChoicePair(StrEnum::NO_SHIFT, "No Shift")
		,ChoicePair(StrEnum::SPOT_SHIFT, "Spot Shift")
		,ChoicePair(StrEnum::YIELD_SHIFT, "Yield Shift")
	};
	const EnumList shift_defnEnumList(3, shift_defnChoicePairs);

}	// namespace

//... shared and not shared space: TODO later

	namespace INTEX_ASSET_NS {

	// Shared space - the attributes shared by PlanCode between models
	// and accessed with proxies
	struct GroupSharedAttributes : public ShareBase {
	public:
		GroupSharedAttributes() : ShareBase(INTEX_ASSET::sDescriptorCount){}
	
	private:

		virtual GroupSharedAttributes *clone() {
			return new GroupSharedAttributes(*this);
		}
	} *groupSharedOffset	= 0;

	struct SharedByAllAttributes : public ShareBase {
		SharedByAllAttributes() : ShareBase(INTEX_ASSET::sDescriptorCount){}
	} *sharedByAllOffset	= 0;
}
using namespace INTEX_ASSET_NS;
namespace {
	GroupSharedAttributes dummySharedAttributes;
}
void INTEX_ASSET::createAllShare() {
	meta->pAllShare_ = std::make_unique<SharedByAllAttributes>();
}

TableMgr<VariantTable> INTEX_ASSET::mgr_;

	Attribute::Descriptor INTEX_ASSET::descriptor_0[] = {
	Descriptor(0, Attribute::STRING,	"adco_category_id", -1, (size_t)&modelOffset->adco_category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(1, Attribute::STR_ENUM,	"asset_defn", -1, (size_t)&modelOffset->asset_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_defnEnumList, Feature(true)),
	Descriptor(2, Attribute::STRING,	"asset_detail_rpt_asset_id", -1, (size_t)&modelOffset->asset_detail_rpt_asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(3, Attribute::STR_ENUM,	"asset_detail_rpt_defn", -1, (size_t)&modelOffset->asset_detail_rpt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &asset_detail_rpt_defnEnumList, Feature(true)),
	Descriptor(4, Attribute::STRING,	"asset_detail_rpt_file", -1, (size_t)&modelOffset->asset_detail_rpt_file,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(5, Attribute::INT,	"asset_detail_rpt_final_period", -1, (size_t)&modelOffset->asset_detail_rpt_final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(6, Attribute::INT,	"asset_detail_rpt_start_period", -1, (size_t)&modelOffset->asset_detail_rpt_start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(7, Attribute::STRING,	"asset_id", -1, (size_t)&modelOffset->asset_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(8, Attribute::STR_ENUM,	"balloon_extension", -1, (size_t)&modelOffset->balloon_extension,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &balloon_extensionEnumList, Feature(true)),
	Descriptor(9, Attribute::STR_ENUM,	"bk_val_defn", -1, (size_t)&modelOffset->bk_val_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &bk_val_defnEnumList, Feature(true)),
	Descriptor(10, Attribute::STRING,	"category_id", -1, (size_t)&modelOffset->category_id,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(11, Attribute::STRING,	"cmo_dll", -1, (size_t)&modelOffset->cmo_dll,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(12, Attribute::STRING,	"cmo_dll_64", -1, (size_t)&modelOffset->cmo_dll_64,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(13, Attribute::STR_ENUM,	"cost_basis_defn", -1, (size_t)&modelOffset->cost_basis_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &cost_basis_defnEnumList, Feature(true)),
	Descriptor(14, Attribute::STRING,	"cusip_deal_translation_path", -1, (size_t)&modelOffset->cusip_deal_translation_path,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(15, Attribute::STR_ENUM,	"int_diff_defn", -1, (size_t)&modelOffset->int_diff_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &int_diff_defnEnumList, Feature(true)),
	Descriptor(16, Attribute::INT,	"int_rate_diff_array_size", -1, (size_t)&modelOffset->int_rate_diff_array_size,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(17, Attribute::DOUBLE,	"int_rate_diff_max", Descriptor::NOT_INDEXED, (size_t)&modelOffset->int_rate_diff_max,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(18, Attribute::DOUBLE,	"int_rate_diff_min", Descriptor::NOT_INDEXED, (size_t)&modelOffset->int_rate_diff_min,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(19, Attribute::STR_ENUM,	"io_po_defn", -1, (size_t)&modelOffset->io_po_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &io_po_defnEnumList, Feature(true)),
	Descriptor(20, Attribute::STR_ENUM,	"prepmt_defn", -1, (size_t)&modelOffset->prepmt_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &prepmt_defnEnumList, Feature(true)),
	Descriptor(21, Attribute::STR_ENUM,	"prepmt_model_defn", -1, (size_t)&modelOffset->prepmt_model_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &prepmt_model_defnEnumList, Feature(true)),
	Descriptor(22, Attribute::DOUBLE,	"prepmt_nonfinancial_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->prepmt_nonfinancial_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(23, Attribute::STRING,	"proj_date", -1, (size_t)&modelOffset->proj_date,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(24, Attribute::STR_ENUM,	"proj_defn", -1, (size_t)&modelOffset->proj_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &proj_defnEnumList, Feature(true)),
	Descriptor(25, Attribute::INT,	"proj_period_last", -1, (size_t)&modelOffset->proj_period_last,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(26, Attribute::DOUBLE,	"refinancing_cost_pct", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinancing_cost_pct,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(27, Attribute::STR_ENUM,	"refinancing_rate_defn", -1, (size_t)&modelOffset->refinancing_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &refinancing_rate_defnEnumList, Feature(true)),
	Descriptor(28, Attribute::DOUBLE,	"refinancing_rate_scen_addn", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinancing_rate_scen_addn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(29, Attribute::DOUBLE,	"refinancing_rate_scen_mult", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinancing_rate_scen_mult,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(30, Attribute::DOUBLE,	"refinancing_rate_scen_yr", Descriptor::NOT_INDEXED, (size_t)&modelOffset->refinancing_rate_scen_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(31, Attribute::STR_ENUM,	"shift_defn", -1, (size_t)&modelOffset->shift_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, &shift_defnEnumList, Feature(true)),
	Descriptor(32, Attribute::INT,	"msnumelement", -1, (size_t)&modelOffset->msnumelement,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature()),
	Descriptor(33, Attribute::SCALAR_INT,	"asset_detail_rpt_flag", -1, (size_t)&modelOffset->asset_detail_rpt_flag,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_asset_detail_rpt_flag)),
	Descriptor(34, Attribute::SCALAR_INT,	"commencement_period", -1, (size_t)&modelOffset->commencement_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_commencement_period)),
	Descriptor(35, Attribute::SCALAR_INT,	"final_period", -1, (size_t)&modelOffset->final_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_final_period)),
	Descriptor(36, Attribute::SCALAR_INT,	"get_collateral_num_of_pools", -1, (size_t)&modelOffset->get_collateral_num_of_pools,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_get_collateral_num_of_pools)),
	Descriptor(37, Attribute::SCALAR_INT,	"get_tranche_cdu_mths_offset", -1, (size_t)&modelOffset->get_tranche_cdu_mths_offset,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_get_tranche_cdu_mths_offset)),
	Descriptor(38, Attribute::SCALAR_INT,	"get_tranche_days_accr", -1, (size_t)&modelOffset->get_tranche_days_accr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_get_tranche_days_accr)),
	Descriptor(39, Attribute::SCALAR_INT,	"get_tranche_freqs", -1, (size_t)&modelOffset->get_tranche_freqs,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_get_tranche_freqs)),
	Descriptor(40, Attribute::SCALAR_INT,	"get_tranche_maturity_day", -1, (size_t)&modelOffset->get_tranche_maturity_day,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_get_tranche_maturity_day)),
	Descriptor(41, Attribute::SCALAR_INT,	"get_tranche_maturity_period", -1, (size_t)&modelOffset->get_tranche_maturity_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_get_tranche_maturity_period)),
	Descriptor(42, Attribute::SCALAR_STRING,	"output_file", -1, (size_t)&modelOffset->output_file,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&INTEX_ASSET_UDF::intex_asset_output_file)),
	Descriptor(43, Attribute::SCALAR_STRING,	"output_path", -1, (size_t)&modelOffset->output_path,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&INTEX_ASSET_UDF::intex_asset_output_path)),
	Descriptor(44, Attribute::SCALAR_STRING,	"proj_date_adj", -1, (size_t)&modelOffset->proj_date_adj,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((sF)&INTEX_ASSET_UDF::intex_asset_proj_date_adj)),
	Descriptor(45, Attribute::SCALAR_INT,	"proj_start_mth", -1, (size_t)&modelOffset->proj_start_mth,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_proj_start_mth)),
	Descriptor(46, Attribute::SCALAR_INT,	"proj_start_yr", -1, (size_t)&modelOffset->proj_start_yr,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_proj_start_yr)),
	Descriptor(47, Attribute::SCALAR_INT,	"start_period", -1, (size_t)&modelOffset->start_period,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_start_period)),
	Descriptor(48, Attribute::SCALAR_INT,	"tranche_rate_defn", -1, (size_t)&modelOffset->tranche_rate_defn,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_tranche_rate_defn)),
	Descriptor(49, Attribute::SCALAR_INT,	"use_eom_scen_rates", -1, (size_t)&modelOffset->use_eom_scen_rates,
				Descriptor::NOT_SHARED, false, false, (size_t)0, 0, Feature((iF)&INTEX_ASSET_UDF::intex_asset_use_eom_scen_rates)),
	};

	Attribute::Descriptor* INTEX_ASSET::descriptorTable[] = {
	&INTEX_ASSET::descriptor_0[0],
	&INTEX_ASSET::descriptor_0[1],
	&INTEX_ASSET::descriptor_0[2],
	&INTEX_ASSET::descriptor_0[3],
	&INTEX_ASSET::descriptor_0[4],
	&INTEX_ASSET::descriptor_0[5],
	&INTEX_ASSET::descriptor_0[6],
	&INTEX_ASSET::descriptor_0[7],
	&INTEX_ASSET::descriptor_0[8],
	&INTEX_ASSET::descriptor_0[9],
	&INTEX_ASSET::descriptor_0[10],
	&INTEX_ASSET::descriptor_0[11],
	&INTEX_ASSET::descriptor_0[12],
	&INTEX_ASSET::descriptor_0[13],
	&INTEX_ASSET::descriptor_0[14],
	&INTEX_ASSET::descriptor_0[15],
	&INTEX_ASSET::descriptor_0[16],
	&INTEX_ASSET::descriptor_0[17],
	&INTEX_ASSET::descriptor_0[18],
	&INTEX_ASSET::descriptor_0[19],
	&INTEX_ASSET::descriptor_0[20],
	&INTEX_ASSET::descriptor_0[21],
	&INTEX_ASSET::descriptor_0[22],
	&INTEX_ASSET::descriptor_0[23],
	&INTEX_ASSET::descriptor_0[24],
	&INTEX_ASSET::descriptor_0[25],
	&INTEX_ASSET::descriptor_0[26],
	&INTEX_ASSET::descriptor_0[27],
	&INTEX_ASSET::descriptor_0[28],
	&INTEX_ASSET::descriptor_0[29],
	&INTEX_ASSET::descriptor_0[30],
	&INTEX_ASSET::descriptor_0[31],
	&INTEX_ASSET::descriptor_0[32],
	&INTEX_ASSET::descriptor_0[33],
	&INTEX_ASSET::descriptor_0[34],
	&INTEX_ASSET::descriptor_0[35],
	&INTEX_ASSET::descriptor_0[36],
	&INTEX_ASSET::descriptor_0[37],
	&INTEX_ASSET::descriptor_0[38],
	&INTEX_ASSET::descriptor_0[39],
	&INTEX_ASSET::descriptor_0[40],
	&INTEX_ASSET::descriptor_0[41],
	&INTEX_ASSET::descriptor_0[42],
	&INTEX_ASSET::descriptor_0[43],
	&INTEX_ASSET::descriptor_0[44],
	&INTEX_ASSET::descriptor_0[45],
	&INTEX_ASSET::descriptor_0[46],
	&INTEX_ASSET::descriptor_0[47],
	&INTEX_ASSET::descriptor_0[48],
	&INTEX_ASSET::descriptor_0[49],
	nullptr};
	const size_t INTEX_ASSET::sDescriptorCount = 50;

//factory
INTEX_ASSET* INTEX_ASSET::makeThis(int isSubmodel, ModelClass* owner, INTEX_ASSET* peer, 
						int mainRebase, const xstring &name, INTEX_ASSET_persistent_object* arrayTemplate) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("INTEX_ASSET::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor INTEX_ASSET");
#endif
	INTEX_ASSET* newP = (INTEX_ASSET*)new INTEX_ASSET_UDF
   	  ("intex_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);

	if (!CP) // first time around, CP wil be zero, store top_model pointer
   	CP = newP;
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray
	if (arrayTemplate) {
   	newP->meta = arrayTemplate->meta;
		newP->ms_Total((ModelClass*)arrayTemplate); // share total with persistent object
		newP->groupExpr = arrayTemplate->groupExpr;
	}
	else 
		newP->ms_Total(new TotalObject); // make a new total

		setVisitorPointersAndMap(name, newP, 'N');

	// create submodels of this model here

	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	return newP;
}

//factory
INTEX_ASSET_persistent_object* INTEX_ASSET_persistent_object::makeThis(int isSubmodel, ModelClass* owner, INTEX_ASSET* peer, 
							int mainRebase, const xstring &name, INTEX_ASSET_persistent_object* arrayTemplate, bool fixedArray) {
	#ifdef MEMORYPROFILE
		MemoryProfile mp("INTEX_ASSET_persistent_object::MakeThis");
	#endif
#ifdef USEMEMCOUNT
	gMem.setNewKey("ctor INTEX_ASSET_persistent_object");
#endif
	INTEX_ASSET_persistent_object* newP = (INTEX_ASSET_persistent_object*)new INTEX_ASSET_persistent_object
   	  ("intex_asset", isSubmodel, owner, peer, mainRebase, name, arrayTemplate);
#ifdef USEMEMCOUNT
 	gMem.clearKey();
#endif

	newP->justSetGroupSharePtr(&dummySharedAttributes);

	// Store unique names in newly created model, if modelarray

	if (!productWithSearchArray.empty() && arrayTemplate &&  arrayTemplate->isArrayModel())
	{
		for (auto &product : productWithSearchArray)
		{
			INTEX_ASSET_persistent_object* pd = dynamic_cast<INTEX_ASSET_persistent_object*>(product);
			if (pd)
			{
				newP->SearchFields = product->SearchFields;
			}
		}
	}

	if (arrayTemplate) {
   	newP->meta = arrayTemplate->meta;
		newP->ms_Total((ModelClass*)arrayTemplate); // share total with persistent object
		newP->groupExpr = arrayTemplate->groupExpr;
	}
	else 
		newP->ms_Total(new TotalObject); // make a new total

	if (!fixedArray)
		setVisitorPointersAndMap(name, newP, 'N');

	// create submodels of this model here
	// only do this for topmodel created
   if (!arrayTemplate && newP == CP) {
		IsMainRebaseForClonesVisitor().visitAll(CP);
		IsMainRebaseForSubModelsVisitor().visitAll(CP);
	}

	newP->msnumelement.setValue(0);
	return newP;
}

typedef double (INTEX_ASSET_UDF::*dPF) ();
typedef double (INTEX_ASSET_UDF::*dPFd) (double);
typedef int (INTEX_ASSET_UDF::*iPF) ();
typedef int (INTEX_ASSET_UDF::*iPFi) (int);
typedef xstring (INTEX_ASSET_UDF::*sPF) ();
typedef xstring (INTEX_ASSET_UDF::*sPFs) (xstring);
#ifdef MICROSOFT
#pragma warning(push)
#pragma warning(disable : 4355)
// Disable the warning C4355: 'this' : used in base member initializer list
#endif	MICROSOFT

// constructor if this model class is the base class of another model class
INTEX_ASSET::INTEX_ASSET(int columnCount, Descriptor* mocd[], Product* persObj) : ModelClass(columnCount, mocd, persObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, adco(company_asset_adco)
	, asset(company_asset)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, intex(company_asset_intex)
	, rates(company_rates)
	, seg(company_seg)
{
	gProxyInitialiser = 0;
	gColumnInitialiser = 0;

	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (INTEX_ASSET_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

}

//constructor begincolumn
INTEX_ASSET::INTEX_ASSET(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase,
		const char *name, ModelClass* arrayPersistentObj) : ModelClass(16, INTEX_ASSET::descriptorTable, arrayPersistentObj), Variable(*this)
  , sm_bond_is(0)
  , sm_bond_pv(0)
  , sm_bond_ym(0)
  , sm_mtg_is(0)
  , sm_mtg_pv(0)
  , sm_mtg_ym(0)

	, adco(company_asset_adco)
	, asset(company_asset)
	, epl(company_liab_epl)
	, fia(company_liab_fia)
	, intex(company_asset_intex)
	, rates(company_rates)
	, seg(company_seg)
 // Tables...
 // Generic Tables ...
{

#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	if (bEmitTurboDebugger)
	{
		bEmitTurboDebugger = false;
	}

	normalModel=true;
   mCFCD = mCFStaticData;
   static std::unordered_multimap<std::string, int> CFStaticDataFinder = createCashFlowFinder(mCFStaticData);
   mCFCDFinder = &CFStaticDataFinder;
   mMOCD = descriptorTable;


		ModelClassName = modelClassName;
       isSubmodel = isSm;
       isMainModel = !isSm;
		modelName = name;

#ifdef __CREATE_ASSET_ASSET_CLASS_
       company_asset = 0;
#endif
#ifdef __CREATE_ADCO_ASSET_CLASS_
       company_asset_adco = 0;
#endif
#ifdef __CREATE_INTEX_ASSET_CLASS_
       company_asset_intex = 0;
#endif
#ifdef __CREATE_EPL_LIAB_CLASS_
       company_liab_epl = 0;
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
       company_liab_fia = 0;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
       company_rates = 0;
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
       company_seg = 0;
#endif

#ifdef VOCAL1
	log_strm << "Constructing model called " << name << "\n";
	log_strm << "    this = " << this << "\n";
	log_strm << "     " << this << "::modelClass = " << ModelClassName << "\n";
	log_strm << "     " << this << "::isSubmodel = " << isSubmodel << "\n";
	log_strm << "     " << this << "::isMainModel = " << isMainModel << "\n";
	log_strm << "     " << this << "::rebase_period = " << rebase_period << "\n";
#endif

   	pddfVector = &ddfVector;
	isDataVariable_ = &dataVariables;
	pHasBeenWritten = &hasBeenWritten;

	setSlidingSpace();

	for (int cf_no = 1; cf_no <= 16; cf_no++)
#ifdef CF_MEMORY
		setPtr_col(cf_no, 0);
#else
		CashFlowBase::factory(this, cf_no, arrayPersistentObj);
#endif


	typedef double (ModelClass::*dPFi2) (int, int);
	typedef double (INTEX_ASSET_UDF::*dPXi2) (int, int);
	dPXi2 temp2;

	sm_calling_model = owner;  // owner = 0 for main model
	sm_peer_model = peer;  // peer = 0 for rebase main model and its submodels
	isMainRebase = mainRebase;
	isRebaseClone = ! mainRebase;
	isForceRestoreModel = 1;
	main_rebase_model = (isMainRebase && rebasing_wanted);

#ifdef VOCAL1
	log_strm << "     " << this << "::sm_calling_model = " << sm_calling_model << "\n";
	log_strm << "     " << this << "::sm_peer_model = " << sm_peer_model << "\n";
	log_strm << "     " << this << "::isMainRebase = " << isMainRebase << "\n";
	log_strm << "     " << this << "::isRebaseClone = " << isRebaseClone << "\n";
	log_strm << "     " << this << "::isForceRestoreModel = " << isForceRestoreModel << "\n";
	log_strm << "     " << this << "::main_rebase_model = " << main_rebase_model << "\n";
#endif


	if (isMainRebase)
		CPPeer = this;
	else
		CPPeer = sm_peer_model;


}
//Constructor End@2


 void INTEX_ASSET::copy_names() {

#ifdef __CREATE_ASSET_ASSET_CLASS_
		company_asset = (ASSET_ASSET*)(findUnique("company|asset"));
#endif
#ifdef __CREATE_ADCO_ASSET_CLASS_
		company_asset_adco = (ADCO_ASSET*)(findUnique("company|asset|adco"));
#endif
#ifdef __CREATE_INTEX_ASSET_CLASS_
		company_asset_intex = (INTEX_ASSET*)(findUnique("company|asset|intex"));
#endif
#ifdef __CREATE_EPL_LIAB_CLASS_
		company_liab_epl = (EPL_LIAB*)(findUnique("company|liab|epl"));
#endif
#ifdef __CREATE_FIA_LIAB_CLASS_
		company_liab_fia = (FIA_LIAB*)(findUnique("company|liab|fia"));
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
		company_rates = (RATES_ECONOMY*)(findUnique("company|rates"));
#endif
#ifdef __CREATE_SEG_COMP_CLASS_
		company_seg = (SEG_COMP*)(findUnique("company|seg"));
#endif
 }
//copy_names END@2


 void INTEX_ASSET::mapVariables() {

	doMapVariables();
	mapVarData temp;

 }
//mapVariables END@2

	// In the next five functions, columnNumber is zero based
	int INTEX_ASSET_persistent_object::columnCount() const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::columnCount();
	}

	const xstring& INTEX_ASSET_persistent_object::ms_columnName(const int columnNumber) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnName(columnNumber);
	}

	double INTEX_ASSET_persistent_object::ms_columnValue(const int columnNumber, const int t) {
		ModelClass::verifyColumnNumber(columnNumber, t);
		Functor3<double, const int, const int> pFunctor(this, (Functor3<double, const int, const int>::pTNodeFunc)&ModelClass::ms_columnValue, columnNumber, t);
		NavigatorDouble navList(&pFunctor, 0, t);
		findStart(&navList, ::SUM);
		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		double retValue = 0;
		callback->doAction(&navList, (void*)&retValue);
		callback->doPostAction();
		return retValue;
	}

	int INTEX_ASSET_persistent_object::ms_columnNumber(const xstring& columnName) const {
		// Delete the global callbackList, we are not going to use it.
		// Then re-create for future use.  This is equivalent to shrinking it to empty
		callbackStart = nullptr;
		ModelClass::callbackList = std::make_unique<NavigatorVoid>(nullptr, 0, 0);
		return ModelClass::ms_columnNumber(columnName);
	}

	double INTEX_ASSET_persistent_object::ms_columnValue(const xstring& columnName, const int t) {
	int columnNumber = ModelClass::verifyColumnName(columnName, t);
		Functor3<double, const int, const int> pFunctor(this, (Functor3<double, const int, const int>::pTNodeFunc)&ModelClass::ms_columnValue, columnNumber, t);
		NavigatorDouble navList(&pFunctor, 0, t);
		findStart(&navList, ::SUM);
		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		double retValue = 0;
		callback->doAction(&navList, (void*)&retValue);
		callback->doPostAction();
		return retValue;
	}

	double INTEX_ASSET_persistent_object::ms_valueAsDouble(const Attribute::Descriptor& descriptor) {
		// The name of the functor does seem to be inappropiate - has nothing to do with Col
		Functor2<double, const Attribute::Descriptor&>
			pFunctor(this, (Functor2<double, const Descriptor&>::pTNodeFunc)&ModelClass::ms_valueAsDouble, descriptor);
		NavigatorDouble navList(&pFunctor, 0, 0);
		findStart(&navList, ::SUM);
		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		double retValue = 0;
		callback->doAction(&navList, (void*)&retValue);
		callback->doPostAction();
		return retValue;
	}

	void INTEX_ASSET_persistent_object::reset() {
		VoidFunctor pFunctor(this, (VoidFunctor::pTNodeFunc)&ModelClass::reset);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void INTEX_ASSET_persistent_object::write(long include_submodels) {
		// check if there are any aggregate processes in the write() statement
		if (callbackList->contains(::_Default) || callbackList->contains(::SUM))
			arrayWriteError();

		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::write , include_submodels);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void INTEX_ASSET_persistent_object::rebaseModel(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModel , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void INTEX_ASSET_persistent_object::rebaseModelOnly(long period) {
		VoidFunctor1<long> pFunctor(this, (VoidFunctor1<long>::pTNodeFunc)&ModelClass::rebaseModelOnly , period);
		NavigatorVoid navList(&pFunctor, 0, period);
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}

	void INTEX_ASSET_persistent_object::write(const xstring& key, long include_submodels) {
		// check if there are any aggregate processes in the write() statement
		if (callbackList->contains(::_Default) || callbackList->contains(::SUM))
			arrayWriteError();

		VoidFunctor2<const xstring&, long> pFunctor(this, (VoidFunctor2<const xstring&, long>::pTNodeFunc)&ModelClass::write , key, include_submodels);
		NavigatorVoid navList(&pFunctor, 0, 9999999); // needs a big number for 't' to touch all elements in a layered array
		findStart(&navList, ::ALL);

		ModelClass* callback = callbackStart;
		callbackStart = nullptr;

		void* dummy = 0;
		callback->doAction(&navList, dummy);
		callback->doPostAction();
	}




	INTEX_ASSET_persistent_object::~INTEX_ASSET_persistent_object(){
		if(pfl)
			delete pfl;
	}

	bool INTEX_ASSET_persistent_object::findProductFeatureList(xstring varValue){
		if(!pfl)	
			return false;
		return pfl->findProductFeatureList(varValue);
	}

	void INTEX_ASSET_persistent_object::makeProductFeatureList(xstring varValue){
		if(!pfl)
			pfl = new ProductFeatureList();
		pfl->makeProductFeatureList(varValue);
	}

	void INTEX_ASSET_persistent_object::addProductFeatureValue(int result, int count){
		pfl->addProductFeatureValue(result, count);		
	}
	void INTEX_ASSET_persistent_object::addProductFeatureValue(double result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void INTEX_ASSET_persistent_object::addProductFeatureValue(xstring result, int count){
		pfl->addProductFeatureValue(result, count);
	}
	void INTEX_ASSET_persistent_object::addProductFeatureValue(char result, int count){
		pfl->addProductFeatureValue(result, count);
	}

	int* INTEX_ASSET_persistent_object::getProductFeatureIntPointer(int count){
		return pfl->getProductFeatureIntPointer(count);
	}
	double* INTEX_ASSET_persistent_object::getProductFeatureDoublePointer(int count){
		return pfl->getProductFeatureDoublePointer(count);
	}
	xstring* INTEX_ASSET_persistent_object::getProductFeatureXstringPointer(int count){
		return pfl->getProductFeatureXstringPointer(count);
	}
	char INTEX_ASSET_persistent_object::getProductFeatureIgnore(int count){
		return pfl->getProductFeatureIgnore(count);
	}

	void INTEX_ASSET_persistent_object::resizeProductFeatureList(int intCount, int doubleCount, int xstringCount, int ignoreCount){
		return pfl->resizeProductFeatureList(intCount, doubleCount, xstringCount, ignoreCount);
	}


//constructor
INTEX_ASSET_persistent_object::INTEX_ASSET_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj) :
			INTEX_ASSET(modelClassName, isSm, owner, peer, mainRebase, name, arrayPersistentObj), 
			mReadArray(true),
			pfl(0)
	, sm_bond_is(INTEX_ASSET::sm_bond_is)
	, sm_bond_pv(INTEX_ASSET::sm_bond_pv)
	, sm_bond_ym(INTEX_ASSET::sm_bond_ym)
	, sm_mtg_is(INTEX_ASSET::sm_mtg_is)
	, sm_mtg_pv(INTEX_ASSET::sm_mtg_pv)
	, sm_mtg_ym(INTEX_ASSET::sm_mtg_ym)

	{


	normalModel = false;
   mModelType = ARRAY_FIXED; 

	sm_calling_model = owner;  // owner = 0 for main model
	sm_peer_model = peer;  // peer = 0 for rebase main model and its submodels
	isMainRebase = mainRebase;
	isRebaseClone = ! mainRebase;
	isForceRestoreModel = 1;
	main_rebase_model = (isMainRebase && rebasing_wanted);

	shrink();
}


//destructor
INTEX_ASSET::~INTEX_ASSET() {

    if (bIsInit)
		deInit_();  // call user defined destructor code
	if (sliding_wanted == SLIDING_TEST) {
   	show_sliding_windows();
	}
}
//destructor END@2
void INTEX_ASSET::findTargetColumns() {

}
//findTargetColumns END@2
void INTEX_ASSET::checkFileTables() {


//	doCheckFileTables();
}
//checkFileTables END@2

void INTEX_ASSET::temporary_tables() { 
	char buf[20];
}
//temporary_tables END@2
void INTEX_ASSET::setPtr_col(int cf_no, CashFlowBase* cf) {
}

void INTEX_ASSET::start_of_projection() {
}
//start_of_projection END@2

void INTEX_ASSET::end_of_projection() {
}
//end_of_projection END@2

void INTEX_ASSET::start_of_layer() {
}


void INTEX_ASSET::end_of_layer(int layer_skipped) {
}
//end_of_layer END@2

void INTEX_ASSET::resetValues(int decrement) {
   // Reset submodels for next variation/layer
	ModelClass::resetValues(decrement);
}
//resetValues END@2

void INTEX_ASSET::after_startup(int decrement) {
// Call startup for submodels
}
//after_startup END@2


 void INTEX_ASSET::ms_BeforeStartup() {
}
//ms_BeforeStartup END@2

HVector<ModelClass::ddfStruct> INTEX_ASSET::ddfVector;
BitArray INTEX_ASSET::dataVariables(50);
bool INTEX_ASSET::hasBeenWritten = false;


#ifdef COLUMNOUTPUT245
bool INTEX_ASSET::writeClassInfo = true;

void INTEX_ASSET::writeClassInfoIfRequired() const {
	if (writeClassInfo)
	  TotalObject::writeInfoFile(this);
	writeClassInfo = false;
}
#endif

Descriptor* Attribute::Proxy<StrEnum::StringEnum, INTEX_ASSET::descriptor_0>::dT = INTEX_ASSET::descriptor_0;
Descriptor* Attribute::ProxyReadOnly<StrEnum::StringEnum, INTEX_ASSET::descriptor_0>::dT = INTEX_ASSET::descriptor_0;

