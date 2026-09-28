#ifndef __RATES_ECONOMY_H_
#define __RATES_ECONOMY_H_
#pragma warning ( disable : 4819 )

#include <sstream> // For ostringstream
#include <sys/stat.h> // For file access
#include <vector>
#include <cmath>  // For floor()
#pragma once
// Common elements from the Economy interface  -- enums, constants

#ifdef ECONOMY_EXPORTS
#define ECONOMY_API __declspec(dllexport)
#endif

#define NOMINMAX

const int MAX_ERR_LEN = 200;
const int MAX_DESC_LEN = 100;
const int MAX_ID_LEN = 150;
const int MAX_MAT_LEN = 4;
const int MAX_PATH_LEN = 300;
const int MAX_TERM = 600;

enum CalibrationOption
{
No = 0,
Yes = 1
};    

enum CalibrationType
{
InterestRates = 0,
Spread = 1,
WealthFactors = 2
};

enum CalibrationIntSource
{
SwaptionVolatility = 0,
BondVolatility = 1
};

enum GenerationCalibrationProjType
{
Constant = 0,
TermStructure = 1
};

enum CalibrationIndexCallPut
{
Call = 0,
Put = 1
};

enum __declspec(dllimport) GenerationApproachType
{
Stochastic=1,
MeanReversion = 2,
MeanReversionWithIndexSpread = 3,
StochasticExclusionTest = 4,
Vm21MarketPaths = 5
};

enum __declspec(dllimport) RWGenerationStochDefn
{
RandomScenarios = 1,
AcademySelectedScenarios = 2
};

enum __declspec(dllimport) GenerationRNMethod
{
QuickGeneration=1,
CompleteGeneration= 2
};

enum __declspec(dllimport) GenerationMethod
{
StandAlone=1,
OnTheFly = 2
};

enum __declspec(dllimport) GenerationAudit
{
AuditNo = 0,
AuditYes = 1
};

enum __declspec(dllimport) YieldCurveTreatmentType
{
ReleaseFromMemory = 1,
KeepInMemory = 2
};

enum __declspec(dllimport) DateTreatmentType
{
Actual = 1,
Relative = 2
};

enum __declspec(dllimport) ScenSetType
{
Outer = 1,
Inner = 2
};

enum __declspec(dllimport) EconErrorCodeType
{
ECON_OK = 1,
ECON_WARNING = 2,
ECON_ERROR = 3
};

enum __declspec(dllimport) ScenarioBasisType
{
RealWorld = 1,
RiskNeutral = 2
};

enum __declspec(dllimport) ValuationScenType
{
AllRates = 1,
IndexRatesOnly = 2,
NoRatesReused = 3
};

enum __declspec(dllimport) ScenarioDefnType
{
UnShocked = 1,
Shocked = 2
};

enum __declspec(dllimport) MonthsPerPeriodType
{
MonthlyRates = 1,
AnnualRates = 2
};

enum __declspec(dllimport) YieldRateType
{
Bond = 1,
Spot = 2,
Forward = 3
};

enum __declspec(dllimport) CurrencyQuoteType
{
Direct = 1,
Indirect = 2
};

enum __declspec(dllimport) MissingValType
{
Interpolate = 1,
Previous = 2
};

enum __declspec(dllimport) RateReturnFreqType
{
EffectiveAnnual = 1,
NominalSemiannual = 2,
NominalQuarterly = 4,
NominalMonthly = 12,
Semiannual = -2,
Quarterly = -4,
Monthly = -12
};

enum __declspec(dllimport) ShockMethod
{
Baseline = 1,
ParallelShock = 2,
SpecificShock = 3
};

enum __declspec(dllimport) ShockBasisType
{
YieldCurveShock = 1,
IndexShock = 2
};

enum __declspec(dllimport) ShockType
{
RateorPriceShock = 1,
VolatilityShock = 2
};

enum __declspec(dllimport) EquityRateType
{
GrowthRate = 1,
IncomeReturn = 2,
TotalReturn = 3,
DividendYield = 4,
IndexValue = 5
};

class __declspec(dllimport) YieldTermData
{
private:
    double Maturity;
    double Moneyness;
    double Vol;
    double MeanRevYieldRate;
	double InitYieldShock;

public:
    WINAPI YieldTermData();
    WINAPI YieldTermData(double maturity, double itmpct, double vol);
    virtual ~YieldTermData();
    virtual EconErrorCodeType WINAPI set_Maturity(double maturity);
    virtual EconErrorCodeType WINAPI set_Moneyness(double itmpct);
    virtual EconErrorCodeType WINAPI set_Vol(double vol);
    virtual EconErrorCodeType WINAPI set_MeanRevRate(double yld_rate);
	virtual EconErrorCodeType WINAPI set_InitYieldShock(double init_yld_shock);
    virtual EconErrorCodeType WINAPI get_Maturity(double & maturity);
    virtual EconErrorCodeType WINAPI get_Moneyness(double &itmpct);
    virtual EconErrorCodeType WINAPI get_Vol(double &vol);
    virtual EconErrorCodeType WINAPI get_MeanRevRate(double &yld_rate);
	virtual EconErrorCodeType WINAPI get_InitYieldShock(double &init_yld_shock);
    static  YieldTermData * __vectorcall YieldTermData::Create();
    static void __vectorcall YieldTermData::Release(YieldTermData *ytd);
};

class __declspec(dllimport) YieldCurveData
{
private:
    char                       ID[MAX_ID_LEN + 1];
    std::vector <YieldTermData> YTData;
    char                       errMessage[MAX_ERR_LEN + 1];
public:
    WINAPI YieldCurveData();

    YieldCurveData(char* id);
    virtual ~YieldCurveData();
    virtual EconErrorCodeType WINAPI set_ID(char* id);
    virtual EconErrorCodeType WINAPI set_YieldTermData(YieldTermData &ytData);
    virtual EconErrorCodeType WINAPI get_ID(char* id);
    virtual EconErrorCodeType WINAPI get_YieldTermData(double maturity, double moneyness, YieldTermData &ytData);
    virtual bool WINAPI IsYieldTermDataEmpty();   // Is the YCdata vector empty?
    virtual EconErrorCodeType WINAPI ClearYieldTermData();  // Clear the YCdata vector
    virtual EconErrorCodeType WINAPI get_ErrorMessage( char* errmessage);
    static YieldCurveData* __vectorcall YieldCurveData::Create();
    static void __vectorcall YieldCurveData::Release(YieldCurveData* ycd);
};

class __declspec(dllimport) EcoCurrency
{
private:
    char                      ID[MAX_ID_LEN+1];
    CurrencyQuoteType         QuoteType;
public:
    EcoCurrency();
    EcoCurrency(char* id);
    EcoCurrency(char* id, CurrencyQuoteType quoteType);
    virtual ~EcoCurrency();
    virtual EconErrorCodeType WINAPI set_ID(char* id);
    virtual EconErrorCodeType WINAPI set_QuoteType(CurrencyQuoteType quoteType);
    virtual EconErrorCodeType WINAPI get_ID(char* &id);
    virtual EconErrorCodeType WINAPI get_QuoteType(CurrencyQuoteType &quoteType);
    static  EcoCurrency* __vectorcall EcoCurrency::Create();
    static void __vectorcall EcoCurrency::Release(EcoCurrency* ec);
};

class __declspec(dllimport) AssetIndexTenorData
{
private:
    double Tenor;
    double Moneyness;
    double Vol;
	double InitVolShock;
    double MeanRevIncomeRate;
    double MeanRevGrowthRate;
    double Spread;
public:
    WINAPI AssetIndexTenorData();
    WINAPI AssetIndexTenorData(double tenor, double itmpct, double vol);
    virtual ~AssetIndexTenorData();
    virtual EconErrorCodeType WINAPI set_Vol(double vol);
    virtual EconErrorCodeType WINAPI set_Moneyness(double itmpct);
    virtual EconErrorCodeType WINAPI set_Tenor(double tenor);
    virtual EconErrorCodeType WINAPI set_MeanRevIncomeRate(double inc_rate);
    virtual EconErrorCodeType WINAPI set_MeanRevGrowthRate(double grth_rate);
    virtual EconErrorCodeType WINAPI set_Spread(double sprd);
	virtual EconErrorCodeType WINAPI set_InitVolShock(double init_vol_shock);
    virtual EconErrorCodeType WINAPI get_Vol(double &vol);
    virtual EconErrorCodeType WINAPI get_Moneyness(double &itmpct);
    virtual EconErrorCodeType WINAPI get_Tenor(double &tenor);
    virtual EconErrorCodeType WINAPI get_MeanRevIncomeRate(double &inc_rate);
    virtual EconErrorCodeType WINAPI get_MeanRevGrowthRate(double &grth_rate);
    virtual EconErrorCodeType WINAPI get_Spread(double &sprd);
	virtual EconErrorCodeType WINAPI get_InitVolShock(double &init_vol_shock);
    static AssetIndexTenorData* __vectorcall AssetIndexTenorData::Create();
    static void __vectorcall AssetIndexTenorData::Release(AssetIndexTenorData* aitd);
};

class __declspec(dllimport) AssetIndexData
{
private:
      char                                  ID[MAX_ID_LEN+1];
      std::vector <AssetIndexTenorData>     INDXData;
      char                                  errMessage[MAX_ERR_LEN+1];
public:
    WINAPI AssetIndexData();
    WINAPI AssetIndexData(char* id);
    virtual ~AssetIndexData();
    virtual EconErrorCodeType WINAPI set_ID(char* id);
    virtual EconErrorCodeType WINAPI set_AssetIndexTenorData(AssetIndexTenorData &indxData); // Add Equitydata object to the EQData vector
    virtual EconErrorCodeType WINAPI get_ID(char* id);
    virtual EconErrorCodeType WINAPI get_Size(int &size);
    virtual EconErrorCodeType WINAPI get_AssetIndexTenorData(int indx, AssetIndexTenorData &indxData);
    virtual EconErrorCodeType WINAPI get_AssetIndexTenorDataUnique(int tenor, double moneyness, AssetIndexTenorData &indxData);
    virtual EconErrorCodeType WINAPI get_ErrorMessage( char* errmessage);
    virtual EconErrorCodeType WINAPI clear(){INDXData.clear();return ECON_OK;};
    static  AssetIndexData* __vectorcall AssetIndexData::Create();
    static void __vectorcall AssetIndexData::Release(AssetIndexData* aid);
};

class __declspec(dllimport) MiscRateData
{
private:
      char   ID[MAX_ID_LEN+1];
      double MeanRevRate;
      char errMessage[MAX_ERR_LEN+1];
public:
      WINAPI MiscRateData();
      virtual ~MiscRateData();
      virtual EconErrorCodeType WINAPI set_ID(char* id);
      virtual EconErrorCodeType WINAPI set_MeanRevRate(double rate);
      virtual EconErrorCodeType WINAPI get_ID(char* id);
      virtual EconErrorCodeType WINAPI get_MeanRevRate(double &rate);
      virtual EconErrorCodeType WINAPI get_ErrorMessage( char* errmessage);
      static  MiscRateData* __vectorcall MiscRateData::Create();
      static  void __vectorcall MiscRateData::Release(MiscRateData* mrd);
};

class __declspec(dllimport) CalibrationSwapData
{
private:
	double Maturity;
	double Tenor;
	double Vol;
	double Wght;

public:
	WINAPI CalibrationSwapData();
	WINAPI CalibrationSwapData(double maturity, double tenor, double vol, double wght);
	virtual ~CalibrationSwapData();
	virtual EconErrorCodeType WINAPI set_Maturity(double maturity);
	virtual EconErrorCodeType WINAPI set_Tenor(double tenor);
	virtual EconErrorCodeType WINAPI set_Vol(double vol);
	virtual EconErrorCodeType WINAPI set_Wght(double wght);
	virtual EconErrorCodeType WINAPI get_Maturity(double &maturity);
	virtual EconErrorCodeType WINAPI get_Tenor(double &tenor);
	virtual EconErrorCodeType WINAPI get_Vol(double &vol);
	virtual EconErrorCodeType WINAPI get_Wght(double &wght);
	static CalibrationSwapData * __vectorcall CalibrationSwapData::Create();
	static void __vectorcall CalibrationSwapData::Release(CalibrationSwapData *csd);
};

class __declspec(dllimport) CalibrationBondData
{
private:
	double Term;
	double Vol;
	double Wght;

public:
	WINAPI CalibrationBondData();
	WINAPI CalibrationBondData(double term, double vol, double wght);
	virtual ~CalibrationBondData();
	virtual EconErrorCodeType WINAPI set_Term(double term);
	virtual EconErrorCodeType WINAPI set_Vol(double vol);
	virtual EconErrorCodeType WINAPI set_Wght(double wght);
	virtual EconErrorCodeType WINAPI get_Term(double &term);
	virtual EconErrorCodeType WINAPI get_Vol(double &vol);
	virtual EconErrorCodeType WINAPI get_Wght(double &wght);
	static CalibrationBondData * __vectorcall CalibrationBondData::Create();
	static void __vectorcall CalibrationBondData::Release(CalibrationBondData *cbd);
};

class __declspec(dllimport) CalibrationYieldCurveData
{
private:
	char						        ID[MAX_ID_LEN + 1];
	bool								CalibrationInterestNormalizeWghts;
	CalibrationIntSource				CalibrationInterestSource;
	GenerationCalibrationProjType		CalibrationInterestProjDefn;
	std::vector<CalibrationSwapData>	CalibrationSwapDataVector;
	std::vector<CalibrationBondData>	CalibrationBondDataVector;
	char						        errMessage[MAX_ERR_LEN + 1];

public:
	WINAPI CalibrationYieldCurveData();
	virtual ~CalibrationYieldCurveData();
	virtual EconErrorCodeType WINAPI set_ID(char *id);
	virtual EconErrorCodeType WINAPI set_CalibrationInterestNormalizeWghts(bool calintnormalize);
	virtual EconErrorCodeType WINAPI set_CalibrationInterestSource(CalibrationIntSource calintsource);
	virtual EconErrorCodeType WINAPI set_CalibrationInterestProjDefn(GenerationCalibrationProjType calintproj);
	virtual EconErrorCodeType WINAPI set_CalibrationSwapData(CalibrationSwapData &csdata);
	virtual EconErrorCodeType WINAPI set_CalibrationBondData(CalibrationBondData &cbdata);
	virtual bool WINAPI IsCalibrationSwapDataEmpty();
	virtual bool WINAPI IsCalibrationBondDataEmpty();
	virtual EconErrorCodeType WINAPI get_ID(char *id);
	virtual EconErrorCodeType WINAPI get_CalibrationInterestNormalizeWghts(bool &calintnormalize);
	virtual EconErrorCodeType WINAPI get_CalibrationInterestSource(CalibrationIntSource &calintsource);
	virtual EconErrorCodeType WINAPI get_CalibrationInterestProjDefn(GenerationCalibrationProjType &calintproj);
	virtual EconErrorCodeType WINAPI get_CalibrationSwapDataSize(int &size);
	virtual EconErrorCodeType WINAPI get_CalibrationSwapData(int indx, CalibrationSwapData &csdata);
	virtual EconErrorCodeType WINAPI get_CalibrationSwapMaturityArray(std::vector<double> &csmatarray);
	virtual EconErrorCodeType WINAPI get_CalibrationSwapTenorArray(std::vector<double> &cstenorarray);
	virtual EconErrorCodeType WINAPI get_CalibrationSwapVolAndWght(double maturity, double tenor, double &vol, double &wght);
	virtual EconErrorCodeType WINAPI get_CalibrationBondDataSize(int &size);
	virtual EconErrorCodeType WINAPI get_CalibrationBondData(int indx, CalibrationBondData &cbdata);
	virtual EconErrorCodeType WINAPI get_CalibrationBondTermArray(std::vector<double> &cbtermarray);
	virtual EconErrorCodeType WINAPI get_CalibrationBondVolAndWght(double term, double &vol, double &wght);
	virtual EconErrorCodeType WINAPI get_ErrorMessage(char * errmessage);
	virtual EconErrorCodeType WINAPI clear();
	static CalibrationYieldCurveData * __vectorcall CalibrationYieldCurveData::Create();
	static void __vectorcall CalibrationYieldCurveData::Release(CalibrationYieldCurveData *cbd);
};

class __declspec(dllimport) CalibrationAssetIndexVolData
{
private:
	double Moneyness;
	double Term;
	double Vol;
	double Wght;

public:
	CalibrationAssetIndexVolData();
	CalibrationAssetIndexVolData(double maturity, double tenor, double vol, double wght);
	virtual ~CalibrationAssetIndexVolData();
	virtual EconErrorCodeType WINAPI set_Moneyness(double moneyness);
	virtual EconErrorCodeType WINAPI set_Term(double tenor);
	virtual EconErrorCodeType WINAPI set_Vol(double vol);
	virtual EconErrorCodeType WINAPI set_Wght(double wght);
	virtual EconErrorCodeType WINAPI set_InitVolShock(double init_vol_shock);
	virtual EconErrorCodeType WINAPI get_Moneyness(double &moneyness);
	virtual EconErrorCodeType WINAPI get_Term(double &tenor);
	virtual EconErrorCodeType WINAPI get_Vol(double &vol);
	virtual EconErrorCodeType WINAPI get_Wght(double &wght);
	virtual EconErrorCodeType WINAPI get_InitVolShock(double &init_vol_shock);
	static CalibrationAssetIndexVolData * __vectorcall CalibrationAssetIndexVolData::Create();
	static void __vectorcall CalibrationAssetIndexVolData::Release(CalibrationAssetIndexVolData *caivd);
};

class __declspec(dllimport) CalibrationAssetIndexData
{
private:
	char						                   ID[MAX_ID_LEN + 1];
	bool								           CalibrationAssetIndexNormalizeWghts;
	double                                         CalibrationAssetIndexDivYld;  
	GenerationCalibrationProjType				   CalibrationAssetIndexProjDefn;
	CalibrationIndexCallPut                        CalibrationAssetIndexCallPutDefn;
	std::vector <CalibrationAssetIndexVolData>     CalibrationAssetIndexVolVector;
	char									       errMessage[MAX_ERR_LEN + 1];

public:
	WINAPI CalibrationAssetIndexData();
	virtual ~CalibrationAssetIndexData();
	virtual EconErrorCodeType WINAPI set_ID(char *id);
	virtual EconErrorCodeType WINAPI set_CalibrationAssetIndexNormalizeWghts(bool calindxnoramlize);
	virtual EconErrorCodeType WINAPI set_CalibrationAssetIndexDivYld(double divyld);
	virtual EconErrorCodeType WINAPI set_CalibrationAssetIndexProjDefn(GenerationCalibrationProjType calindxproj);
	virtual EconErrorCodeType WINAPI set_CalibrationAssetIndexCallPutDefn(CalibrationIndexCallPut calindxcallput);
	virtual EconErrorCodeType WINAPI set_CalibrationAssetIndexVolData(CalibrationAssetIndexVolData &indxData);  
	virtual bool WINAPI IsCalibrationAssetIndexVolDataEmpty();
	virtual EconErrorCodeType WINAPI get_ID(char *id);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexNormalizeWghts(bool &calindxnoramlize);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexDivYld(double &divyld);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexProjDefn(GenerationCalibrationProjType &calindxproj);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexCallPutDefn(CalibrationIndexCallPut &calindxcallput);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexVolDataSize(int &size);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexVolData(int indx, CalibrationAssetIndexVolData &indxData);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexOptMoneynessArray(std::vector<double> &caimonarray);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexOptTermArray(std::vector<double> &caitermarray);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexOptVolWghtAndShock(double moneyness, double term, double &vol, double &wght, double &shock);
	virtual EconErrorCodeType WINAPI get_ErrorMessage(char * errmessage);
	virtual EconErrorCodeType WINAPI clear();
	static CalibrationAssetIndexData * __vectorcall CalibrationAssetIndexData::Create();
	static void __vectorcall CalibrationAssetIndexData::Release(CalibrationAssetIndexData * caid);
};

class __declspec(dllimport) CalibrationPointData
{
private:
    char   ID[MAX_ID_LEN+1];    // This is to allow to specify which Wealth Factors will be calibrated. Default 
								//  should be US for the US S&P500 fund in the RW generator.
    CalibrationType  CalType;   //  This aids in the separation of logic for the three different calibration processes.
    double Maturity;            // This specify what the maturity on the yield curve that the stats are collected.
	double TargetTime;          // This specifies the target year where the stats are collected 1 year, 5 year, 10 year, 20
								// year or 30 year
    double Percentile;          // This specifies which target percentile is collected (5% or 95% etc.)
    double PercentileTarget;    //  This is the actual target value, that can be adjusted by Tolerances
    double LowerTolerance;      //  This corresponds to the AAA A tolerance factor for interest rates.  This should be 
								//  set to zero when implementing the AG43 limits for the S&P500 fund.
								// when modeling spreads this will be the offset value.  
    double UpperTolerance;      //  The corresponds to the AAA B tolerance factor for interest ratesThis should be 
								//  set to zero when implementing the AG43 limits for the S&P500 fund.  When 
								//  modeling spreads this should be set to zero.
    char    errMessage[MAX_ERR_LEN+1];
public:
    CalibrationPointData();
    CalibrationPointData(char* id);
    CalibrationPointData(char* id, CalibrationType caltype);
    virtual ~CalibrationPointData();
    virtual EconErrorCodeType WINAPI set_ID(char* id); 
    virtual EconErrorCodeType WINAPI set_CalibrationType(CalibrationType caltype);
    virtual EconErrorCodeType WINAPI set_Maturity(double matur);
	virtual EconErrorCodeType WINAPI set_TargetTime(double ttime);
    virtual EconErrorCodeType WINAPI set_Percentile(double percnt);
    virtual EconErrorCodeType WINAPI set_PercentileTarget(double pcttarget);
    virtual EconErrorCodeType WINAPI set_LowerTolerance(double ltol);
    virtual EconErrorCodeType WINAPI set_UpperTolerance(double utol);
    virtual EconErrorCodeType WINAPI get_ID(char* id);
    virtual EconErrorCodeType WINAPI get_CalibrationType(CalibrationType &caltype);
    virtual EconErrorCodeType WINAPI get_Maturity(double &matur);
    virtual EconErrorCodeType WINAPI get_TargetTime(double &ttime);
    virtual EconErrorCodeType WINAPI get_Percentile(double &percnt);
    virtual EconErrorCodeType WINAPI get_PercentileTarget(double &pcttarget);
    virtual EconErrorCodeType WINAPI get_LowerTolerance(double &ltol);
    virtual EconErrorCodeType WINAPI get_UpperTolerance(double &utol);
    virtual EconErrorCodeType WINAPI get_ErrorMessage( char* errmessage);
    static  CalibrationPointData* __vectorcall CalibrationPointData::Create();
    static void __vectorcall CalibrationPointData::Release(CalibrationPointData* aid);
};

class __declspec(dllimport) CalibrationData
{
private:
	CalibrationOption					   CalibrationChoice;
	int									   CalibrationAttempts;
	int									   CalibrationAuditReport;
	std::vector<CalibrationPointData>      CalibrationVector; // this is the std::vector class that has to be wrapped in a container class so MoSes doesn’t crash.
	double								   PassingPercentageInterest;  // This will allow the user to specify how many tests must pass before acceptance.
	double								   PassingPercentageSpread;    // This will allow the user to specify how many tests must pass before acceptance.
	double								   PassingPercentageEquity;    // This will allow the user to specify how many tests must pass before acceptance.
	std::vector<CalibrationYieldCurveData> CalibrationYCData;          // this is the std::vector class that has to be wrapped in a container class so MoSes doesn’t crash.
	std::vector<CalibrationAssetIndexData> CalibrationAIData;          // this is the std::vector class that has to be wrapped in a container class so MoSes doesn’t crash.
	char								errMessage[MAX_ERR_LEN + 1];
public:
	CalibrationData();
	virtual ~CalibrationData();

	virtual EconErrorCodeType WINAPI set_CalibrationChoice(CalibrationOption calobj);
	virtual EconErrorCodeType WINAPI set_CalibrationAttempts(int calatmp);
	virtual EconErrorCodeType WINAPI set_CalibrationAuditReport(int calrep);
	virtual EconErrorCodeType WINAPI set_CalibrationPointsData(CalibrationPointData caldata);
	virtual EconErrorCodeType WINAPI add_CalibrationPointsData(CalibrationPointData &caldata);
	virtual EconErrorCodeType WINAPI set_PassingPercentageInterest(double passperc);
	virtual EconErrorCodeType WINAPI set_PassingPercentageSpread(double passperc);
	virtual EconErrorCodeType WINAPI set_PassingPercentageEquity(double passperc);
	virtual EconErrorCodeType WINAPI set_CalibrationYieldCurveData(CalibrationYieldCurveData &cycdata);
	virtual EconErrorCodeType WINAPI set_CalibrationAssetIndexData(CalibrationAssetIndexData &caidata);
	virtual bool WINAPI IsCalibrationPointsDataEmpty();
	virtual bool WINAPI IsCalibrationYieldCurveDataEmpty();
	virtual bool WINAPI IsCalibrationAssetIndexDataEmpty();
	virtual EconErrorCodeType WINAPI get_CalibrationChoice(CalibrationOption &calobj);
	virtual EconErrorCodeType WINAPI get_CalibrationAttempts(int &calatmp);
	virtual EconErrorCodeType WINAPI get_CalibrationAuditReport(int &repflag);
	virtual EconErrorCodeType WINAPI get_CalibrationPointDataSize(int &size);
	virtual EconErrorCodeType WINAPI get_CalibrationPointDataID(int indx, char * ID);
	virtual EconErrorCodeType WINAPI get_CalibrationPointData(int indx, CalibrationPointData * caldata);
	virtual EconErrorCodeType WINAPI get_CalibrationPointData(char * ID, double matur, double ttime,
	CalibrationType caltype, double prctile, CalibrationPointData * caldata);
	virtual EconErrorCodeType WINAPI span_CalibrationPointData(char * ID, double matur, double ttime,
	CalibrationType caltype, CalibrationPointData * caldata, int &linkindex);
	virtual EconErrorCodeType WINAPI get_PassingPercentageInterest(double &passperc);
	virtual EconErrorCodeType WINAPI get_PassingPercentageSpread(double &passperc);
	virtual EconErrorCodeType WINAPI get_PassingPercentageEquity(double &passperc);
	virtual EconErrorCodeType WINAPI get_CalibrationYieldCurveDataSize(int &size);
	virtual EconErrorCodeType WINAPI get_CalibrationYieldCurveData(int indx, CalibrationYieldCurveData &cycdata);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexDataSize(int &size);
	virtual EconErrorCodeType WINAPI get_CalibrationAssetIndexData(int indx, CalibrationAssetIndexData &caidata);
	virtual EconErrorCodeType WINAPI get_ErrorMessage(char * errmessage);
	virtual EconErrorCodeType WINAPI clear();
	static  CalibrationData  * __vectorcall CalibrationData::Create();
	static  void __vectorcall CalibrationData::Release(CalibrationData * aid);
};

class __declspec(dllimport) EconomyData
{
private:
    char BaseCurrency[MAX_ID_LEN + 1];
    std::vector <YieldCurveData> YieldCurvesVol;
    std::vector <AssetIndexData> AssetIndicesVol;
    std::vector <MiscRateData> msRatesData;
    std::vector <std::vector <double>> Correl;
    int ProcessCount;
    char errMessage[MAX_ERR_LEN + 1];
public:
    WINAPI EconomyData();
    virtual ~EconomyData();
	virtual EconErrorCodeType WINAPI set_BaseCurrency(char* baseCurrency);
	virtual EconErrorCodeType WINAPI set_YieldCurveData(YieldCurveData &yc);
    virtual EconErrorCodeType WINAPI set_AssetIndexData(AssetIndexData &index);
    virtual EconErrorCodeType WINAPI set_MiscRateData(MiscRateData &mr);
    virtual EconErrorCodeType WINAPI set_Correl(char* id1, char* id2, double correl);
    virtual EconErrorCodeType WINAPI get_YCID_Loc(char* id, int &loc);
    virtual EconErrorCodeType WINAPI get_AIID_Loc(char* id, int &loc);
	virtual EconErrorCodeType WINAPI get_YieldCurveData(char* id, YieldCurveData &yc);
    virtual EconErrorCodeType WINAPI get_YieldCurveDataID(int x, char* id);
    virtual EconErrorCodeType WINAPI get_YieldCurveDataSize(int &size);
    virtual EconErrorCodeType WINAPI get_AssetIndexDataID(int x, char* id);
    virtual EconErrorCodeType WINAPI get_AssetIndexDataSize(int &size);
    virtual EconErrorCodeType WINAPI get_AssetIndexData(char* id, AssetIndexData &index);
    virtual EconErrorCodeType WINAPI get_MiscRateDataID(int x, char* id);
    virtual EconErrorCodeType WINAPI get_MiscRateDataSize(int &size);
    virtual EconErrorCodeType WINAPI get_MiscRateData(char* id, MiscRateData &mr);
	virtual EconErrorCodeType WINAPI get_Correl(char* id1, char* id2, double &correl);
	virtual EconErrorCodeType WINAPI get_ProcessCount(int &proccount);
	virtual EconErrorCodeType WINAPI Init_Correl();
	virtual EconErrorCodeType WINAPI clear_CurrencyData();
    virtual EconErrorCodeType WINAPI clear_YieldCurveData();
    virtual EconErrorCodeType WINAPI clear_AssetIndexData();
    virtual EconErrorCodeType WINAPI clear_MiscRatesData();
	virtual EconErrorCodeType WINAPI clear_Correl();
	virtual EconErrorCodeType WINAPI get_ErrorMessage( char* errmessage);
    static EconomyData* __vectorcall EconomyData::Create();
    static void __vectorcall EconomyData::Release(EconomyData* ed);
};

class __declspec(dllimport) GenerationData
{
private:
        long				GenDate;					// The date for the generation in the form yyyymmdd
		int 				GenDuration;				// The relative duration (months) from the projection date for the generation, i.e. 0, 12, 24, 36, etc
		int 				GenOuterLoopScenNum;		// The scenario number of the outer loop which is the basis for the generation
		double              GenMRPMean1HistYrs;         // This allows the user to pass the number of years to calculate the mean compotent of the AAA MRP.  (3 for both AAA and NAIC)
		double              GenMRPMean2HistYrs;         // This allows the user to pass the number of years to calculated the second mean required in the NAIC MRP formula. (10 for NAIC)
		double              GenMRPMedianHistYrs;        // This allows the user to pass the median number of years that is used to calculate the MRP for the RW scenarios. (50 years for both AAA and NAIC).
		GenerationMethod	GenMethod;				  // Standalone means the generation is standalone and the results of the generation should be written to the disk and all classes, etc 
														// created during the generation should be cleaned up following the process.
														// OnTheFly means the generation is 'on-the-fly' and the results of the generation 
														// should be created in memory. The scenario collections created (both historical 
														// and projected) should be kept around so that rates from the new scenarios can be retrieved. The SelectScenSet method is used for this case. 
		char GenHistFileName[MAX_PATH_LEN + 1];		 // The path and name for the newly created historical rates file
        char GenScenFileName[MAX_PATH_LEN + 1];		 // The path and name for the newly created scenario rates file
		ScenarioBasisType   GenBasis;				   // RW/RN	
		GenerationRNMethod GenRNMethod;				 // "QuickGeneration" CompleteGeneration"	"QuickGeneration means to do the 
														// quick generation RN approach
														// CompleteGeneration means to do a complete RN generation"
		GenerationApproachType GenApproach;			 // "Stochastic" or "MeanReversion"	"Stochastic means that the generation is a stochastic process
														// MeanReversion means that initial rates are linearly reverted back to a specific reversion rate 
														// over a specified number of months"
														// Stochastic Exclusion Test added 1/24/2011
		RWGenerationStochDefn  GenRWStochDefn;          // Option for RandomScenarios or using the AcademySelectScenarios when selecting scenarios to use in generation
		long				   GenRandomSeed;		   // Random seed used in RN scenario generation
	    GenerationCalibrationProjType GenIntProjDefn;   // Constant or Term Structure
		int                    GenMRMths;			   // The number of months for the mean reversion 
														// to the specified mean reversion rates
		int 				   GenScenarios;		    // The number of scenarios to generate
		int 				   GenHistMths;			 // The number of months back from the generation 
													    // period to create new historical rates for. The 
														// minimum possible value for this field is 0 which means to create a 
														// historical file with rates at the generation date.
	    int 				   GenScenMths;			 // The number of months of rates to generate for the scenarios
		MonthsPerPeriodType    GenScenMthsPerPeriod;	// MonthsPerPeriodType	"MonthlyRates", AnnualRates"	
														// "MonthlyRates means the generated scenario file contains monthly rates
														// AnnualRates means the generation scenario file contains annual rates
														// Note: The new historical file should ALWAYS contain monthly rates. 
														// Also, if the GenScenMths value is not evenly divisible by the integer 
														// representing the months per period type (1 or 12), then the number of 
														// months is INCREASED to the next evenly divisible value."
		DateTreatmentType      GenScenDateTreatment;	// DateTreatmentType	"Actual" Relative"	
														// "Actual means the scenario file uses actual dates for the economic conditions
														// "Relative" means the scenario file uses relative dates for the economic conditions
														// Note: The new historical file should ALWAYS use actual dates"
	    ValuationScenType      GenValnScenReuse;		// enum ValuationScenType	"AllRates" IndexRatesOnly"	
														// "AllRates means the generation should reuse all rates from the specified valuation scenario file
														// "InterestRates" means the generation should reuse just the index rates from the specified valuation 
														// scenario file
														// When AllRates is specified, all the generation needs to do is create the new historical rates file and then create a new file which is a copy of the specified valuation scenario file with the name of the new scenario file.
														// Note: If no valuation scenario file is provided in the GenValnScenFile property then the 
														// generation should generate all new rates."
		GenerationAudit  GenAuditDefn;                  // Set to yes to create the Generation Audit Report 
		int              GenAuditScen;                  // Set to the specified generated scenario to audit.
		char          GenValnScenFile[MAX_PATH_LEN + 1];// The path and name of an SOA ESML file which contains rates to be used in the generation process. This field is not required.
		char        		errMessage[MAX_ERR_LEN + 1];
		std::vector <double> GenBondTerms;               // This allows the addition of bond terms to be used in the generate process.
   
public:
		WINAPI GenerationData();
		virtual ~GenerationData();
		virtual EconErrorCodeType WINAPI set_BondTerm(double bondterm);
		virtual EconErrorCodeType WINAPI set_GenApproach(GenerationApproachType approach);
		virtual EconErrorCodeType WINAPI set_GenRWStochDefn(RWGenerationStochDefn genRWStochDefn);
		virtual EconErrorCodeType WINAPI set_GenDate(long date);
		virtual EconErrorCodeType WINAPI set_GenDuration(int duration);
		virtual EconErrorCodeType WINAPI set_GenerationBasis(ScenarioBasisType basis);
		virtual EconErrorCodeType WINAPI set_GenHistMths(int histmths);
		virtual EconErrorCodeType WINAPI set_GenMethod(GenerationMethod method);	
		virtual EconErrorCodeType WINAPI set_GenRandomSeed(long rndseed);
		virtual EconErrorCodeType WINAPI set_GenScenMths(int scenmths);
		virtual EconErrorCodeType WINAPI set_HistFileName(char* filename);
		virtual EconErrorCodeType WINAPI set_GenIntProjDefn(GenerationCalibrationProjType genintprojdefn);
		virtual EconErrorCodeType WINAPI set_MeanRevMths(int mrmths);
		virtual EconErrorCodeType WINAPI set_MRPMean1HistYrs(double mrpyrs);
		virtual EconErrorCodeType WINAPI set_MRPMean2HistYrs(double mrpyrs);
		virtual EconErrorCodeType WINAPI set_MRPMedianHistYrs(double mrpyrs);
		virtual EconErrorCodeType WINAPI set_OuterLoopScenNum(int scennum);	
		virtual EconErrorCodeType WINAPI set_ProjFileName(char* filename);
		virtual EconErrorCodeType WINAPI set_RNMethod(GenerationRNMethod rnmethod);
		virtual EconErrorCodeType WINAPI set_Scenarios(int scennum);
		virtual EconErrorCodeType WINAPI set_ScenDateTreatment(DateTreatmentType GenScenDateTreatment);
		virtual EconErrorCodeType WINAPI set_ScenMthsPerPeriod(MonthsPerPeriodType scenmthsperperiod);
		virtual EconErrorCodeType WINAPI set_ValnScenReuse(ValuationScenType GenValnScenReuse);
		virtual EconErrorCodeType WINAPI set_ValnScenFile(char* valnscenfilename);
		virtual EconErrorCodeType WINAPI set_GenAuditDefn(GenerationAudit genauditdefn);
		virtual EconErrorCodeType WINAPI set_GenAuditScen(int genauditscen);
		virtual EconErrorCodeType WINAPI clear_BondTerms();
		virtual EconErrorCodeType WINAPI get_BondTerm(int loc, double &bondterm);
		virtual EconErrorCodeType WINAPI get_BondTermSize(int &size);
		virtual EconErrorCodeType WINAPI get_ErrMessage(char* errmessage);
		virtual EconErrorCodeType WINAPI get_GenApproach(GenerationApproachType &approach);
		virtual EconErrorCodeType WINAPI get_GenRWStochDefn(RWGenerationStochDefn &genRWStochDefn);
		virtual EconErrorCodeType WINAPI get_GenDate(long &date);
		virtual EconErrorCodeType WINAPI get_GenDuration(int &duration);
		virtual EconErrorCodeType WINAPI get_GenerationBasis(ScenarioBasisType &basis);
		virtual EconErrorCodeType WINAPI get_GenHistMths(int &histmths);
		virtual EconErrorCodeType WINAPI get_GenMethod(GenerationMethod &method);	
		virtual EconErrorCodeType WINAPI get_GenRandomSeed(long &rndseed);
		virtual EconErrorCodeType WINAPI get_GenScenMths(int &scenmths);
		virtual EconErrorCodeType WINAPI get_HistFileName(char* filename);
		virtual EconErrorCodeType WINAPI get_GenIntProjDefn(GenerationCalibrationProjType &genintprojdefn);
		virtual EconErrorCodeType WINAPI get_MeanRevMths(int &mrmths);
		virtual EconErrorCodeType WINAPI get_MRPMean1HistYrs(double &mrpyrs);
		virtual EconErrorCodeType WINAPI get_MRPMean2HistYrs(double &mrpyrs);
		virtual EconErrorCodeType WINAPI get_MRPMedianHistYrs(double &mrpyrs);
		virtual EconErrorCodeType WINAPI get_OuterLoopScenNum(int &scennum);	
		virtual EconErrorCodeType WINAPI get_ProjFileName(char* filename);
		virtual EconErrorCodeType WINAPI get_RNMethod(GenerationRNMethod &rnmethod);
		virtual EconErrorCodeType WINAPI get_Scenarios(int &scennum);
		virtual EconErrorCodeType WINAPI get_ScenMthsPerPeriod(MonthsPerPeriodType &scenmthsperperiod);
		virtual EconErrorCodeType WINAPI get_ScenDateTreatment(DateTreatmentType &GenScenDateTreatment);
		virtual EconErrorCodeType WINAPI get_ValnScenReuse(ValuationScenType &GenValnScenReuse);
		virtual EconErrorCodeType WINAPI get_ValnScenFile(char* valnscenfilename);
		virtual EconErrorCodeType WINAPI get_GenAuditDefn(GenerationAudit &genauditdefn);
		virtual EconErrorCodeType WINAPI get_GenAuditScen(int &genauditscen);
        static GenerationData* __vectorcall GenerationData::Create();
        static void __vectorcall GenerationData::Release(GenerationData* gd);
};

class RAScenario;

class __declspec(dllimport) Economy
{
private:
    YieldCurveTreatmentType YCTreatmentType;
    MissingValType          MissValType;
    ValuationScenType       ValnScenType;
    DateTreatmentType       DTTreatmentType;
    ScenSetType             ScenSet;
    long                    ProjYr;
    long                    ProjMth;
	long                    ProjDay;   
    char                    errMessage[MAX_ERR_LEN+1];
    int                     CSVOpenRetryAttempts;
	int						ValnPeriod;
    void Economy::GetErrMessage();
    EconErrorCodeType Economy::GetErrMessage(EconErrorCodeType ok);
    RAScenario* RAScen;
    RAScenario* RAScenOuter;
    RAScenario* RAScenInner;

public:
    WINAPI Economy();
    ~Economy();
    virtual EconErrorCodeType WINAPI GetScenSet(ScenSetType &scensettype);
    virtual EconErrorCodeType WINAPI SelectScenSet(ScenSetType scensettype);
    virtual EconErrorCodeType WINAPI set_YCTreatmentType(YieldCurveTreatmentType ycTreatmentType);
    virtual EconErrorCodeType WINAPI set_MissValType(MissingValType missValType);
    virtual EconErrorCodeType WINAPI set_ValnScenType(ValuationScenType valnScenType);
    virtual EconErrorCodeType WINAPI set_DateTreatmentType(DateTreatmentType dttreattyp);
    virtual EconErrorCodeType WINAPI set_ProjDate(long projYr,long projMth);
    virtual EconErrorCodeType WINAPI set_ProjDate(long projYr,long projMth, long projDay);
    virtual EconErrorCodeType WINAPI set_ProjYear(long projYr);
    virtual EconErrorCodeType WINAPI set_ProjMonth(long projMth);
    virtual EconErrorCodeType WINAPI set_ProjDay(long projDay);
	virtual EconErrorCodeType WINAPI set_ValnPeriod(int valnPeriod); 
    virtual EconErrorCodeType WINAPI set_EconFilesRetryAttempts(int cnt);
    virtual EconErrorCodeType WINAPI get_ProjDate(long &projYr,long &projMth, long &projDay);
    virtual EconErrorCodeType WINAPI get_ProjYear(long &projYr);
    virtual EconErrorCodeType WINAPI get_ProjMonth(long &projMth);
    virtual EconErrorCodeType WINAPI get_ProjDay(long &projDay);
	virtual EconErrorCodeType WINAPI get_ValnPeriod(int &valnPeriod); 
    virtual EconErrorCodeType WINAPI get_DateTreatmentType(DateTreatmentType &dttreattyp);
    virtual EconErrorCodeType WINAPI get_YCTreatmentType(YieldCurveTreatmentType &ycTreatmentType);
    virtual EconErrorCodeType WINAPI get_MissValType(MissingValType &missValType);
    virtual EconErrorCodeType WINAPI get_ValnScenType(ValuationScenType &valnScenType);
    virtual EconErrorCodeType WINAPI get_ErrorMessage(char* errmessage);
    virtual EconErrorCodeType WINAPI ScenSetInfoLoad(char* pszProjFile, char* pszHistFile);
    virtual EconErrorCodeType WINAPI get_YieldCurveInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_YieldCurveVolInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_IndexVolInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_MiscRateInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_EquityTypeInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_CurrencyInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_CountryInfoSize(int &size);
    virtual EconErrorCodeType WINAPI get_YieldCurveInfo(int listid,char* ID, char* Name, char* QualityScale, char* QualityLevel, char* ESMLType);
    virtual EconErrorCodeType WINAPI get_YieldCurveVolInfo(int listid,char* ID, char* Name, char* ESMLType);
    virtual EconErrorCodeType WINAPI get_IndexVolatilityInfo(int listid,char* ID, char* Name, char* ESMLType);
    virtual EconErrorCodeType WINAPI get_MiscRateInfo(int listid, char* ID, char* Name);
    virtual EconErrorCodeType WINAPI get_EquityTypeInfo(int listid, char* ID, char* Name);
    virtual EconErrorCodeType WINAPI get_CurrencyInfo(int listid, char* ID, char* Name, char* Quotation);
    virtual EconErrorCodeType WINAPI get_CountryInfo(int listid, char* CountryName);
    virtual EconErrorCodeType WINAPI get_YieldCurveID(int listid, char* ID);
    virtual EconErrorCodeType WINAPI get_YieldCurveVolID(int listid, char* ID);
    virtual EconErrorCodeType WINAPI get_IndexVolID(int listid, char* ID);
    virtual EconErrorCodeType WINAPI get_MiscRateID(int listid, char* ID);
    virtual EconErrorCodeType WINAPI get_EquityID(int listid, char* ID);
    virtual EconErrorCodeType WINAPI get_CurrencyID(int listid,char* ID);
    virtual EconErrorCodeType WINAPI get_CountryID(int listid,char* ID);
    virtual EconErrorCodeType WINAPI ScenLoadProjRates(int scenID);
    virtual EconErrorCodeType WINAPI GetInterestRate(long date, char* country, char* rateQuality, YieldRateType yieldRateType, double rateTerm, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInterestRate(int Year, int Month, int Day, char* Country, char* rateQuality, YieldRateType yieldRateType, double rateTerm, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInterestRate(int duration, char* country, char* rateQuality, YieldRateType yieldRateType, double rateTerm, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInterestLocalVolatility(long date, char* country, char* rateQuality, YieldRateType yieldRateType, int volPeriod,  double rateTerm, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInterestLocalVolatility(int Year, int Month, int Day, char* Country, char* rateQuality, YieldRateType yieldRateType, int volPeriod, double rateTerm, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInterestLocalVolatility(int duration, char* country, char* rateQuality, YieldRateType yieldRateType, int volPeriod, double rateTerm, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInterestVolatility(long date, char* country, char* rateQuality,double moneyness, double tenor, RateReturnFreqType rateFreq, double &volrate);
    virtual EconErrorCodeType WINAPI GetInterestVolatility(int Year, int Month, int Day, char* Country, char* rateQuality,double moneyness, double tenor, RateReturnFreqType rateFreq, double &volrate);
    virtual EconErrorCodeType WINAPI GetInterestVolatility(int duration, char* country, char* rateQuality,double moneyness, double tenor, RateReturnFreqType rateFreq, double &volrate);
    virtual EconErrorCodeType WINAPI GetIndexVolatility(long date, char* country, char* equityID, double moneyness, double tenor, RateReturnFreqType rateFreq, double &volrate);
    virtual EconErrorCodeType WINAPI GetIndexVolatility(int Year, int Month, int Day, char* country, char* equityID, double moneyness, double tenor, RateReturnFreqType rateFreq, double &volrate);
    virtual EconErrorCodeType WINAPI GetIndexVolatility(int duration, char* country, char* equityID, double moneyness, double tenor, RateReturnFreqType rateFreq, double &volrate);
    virtual EconErrorCodeType WINAPI GetEntireYieldCurve(int duration, char* country, char* rateQuality, YieldRateType yield_curve_type, RateReturnFreqType rate_frequency, int maxTerm, double* yc);
    virtual EconErrorCodeType WINAPI GetEntireYieldCurve(long date, char* country, char* rateQuality, YieldRateType yield_curve_type, RateReturnFreqType rate_frequency, int maxTerm, double* yc);
    virtual EconErrorCodeType WINAPI GetEntireYieldCurve(int Year, int Month, int Day, char* country, char* rateQuality, YieldRateType yield_curve_type, RateReturnFreqType rate_frequency, int maxTerm, double* yc);
    virtual EconErrorCodeType WINAPI GetIndexRate(long date, char* country, char* equityID, EquityRateType equityRateType, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetIndexRate(int Year, int Month, char* country, char* equityID, EquityRateType equityRateType, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetIndexRate(int duration, char* country, char* equityID, EquityRateType equityRateType, RateReturnFreqType rateFreq, double &rate);
	virtual EconErrorCodeType WINAPI GetIndexValue(long date, char * country, char *equityID, double &value);
	virtual EconErrorCodeType WINAPI GetIndexValue(int Year, int Month, int Day, char * country, char *equityID, double &value);
	virtual EconErrorCodeType WINAPI GetIndexValue(int duration, char * country, char *equityID, double &value);
    virtual EconErrorCodeType WINAPI GetIndexLocalVolatility(long date, char* country, char* equityID, EquityRateType equityRateType, double volPeriod, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetIndexLocalVolatility(int Year, int Month, int Day, char* country, char* equityID, EquityRateType equityRateType, double volPeriod, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetIndexLocalVolatility(int duration, char* country, char* equityID, EquityRateType equityRateType, double volPeriod, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInflationRate(long date, char* country,  char* id, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInflationRate(int Year, int Month, int Day, char* country, char* id, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetInflationRate(int duration, char* country,  char* id, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetDefaultRate(long date, char* country, char* rateQuality, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetDefaultRate(int Year, int Month, int Day, char* country, char* rateQuality, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetDefaultRate(int duration, char* country, char* rateQuality, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetMiscRate(long date, char* country, char* rateQuality, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetMiscRate(int Year, int Month, int Day, char* country, char* rateQuality, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetMiscRate(int duration, char* country, char* rateQuality, RateReturnFreqType rateFreq, double &rate);
    virtual EconErrorCodeType WINAPI GetExchangeRate(long date, char* domes_country, char* for_country, double monthsForward, CurrencyQuoteType currQuoteType, double &rate);
    virtual EconErrorCodeType WINAPI GetExchangeRate(int Year, int Month, int Day, char* domes_country, char* for_country, double monthsForward, CurrencyQuoteType currQuoteType, double &rate);
    virtual EconErrorCodeType WINAPI GetExchangeRate(int duration, char* domes_country, char* for_country, double monthsForward, CurrencyQuoteType currQuoteType, double &rate);
    virtual EconErrorCodeType WINAPI Generate(GenerationData* gendata, EconomyData* econdata,CalibrationData* caldata, int first=0);
    static Economy* __vectorcall Economy::Create();
    static void __vectorcall Economy::Release(Economy* ecdat);
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
#include "ArrayProxy.h"			// ... contains Array Proxies
#include "ScalarProxy.h"			// ... contains Scalar Proxies
#include "ModelGroupProxy.h"
#include "NonAssocTableProxy.h"	// ... contains Rate_table and Table_from
#include "AssocTableProxies.h"		// ... contains AssocArray tables
#include "EnumValue.h"				// ... contains Enum Values


using namespace StrEnum;

#ifdef __CREATE_AA_COMP_COMP_CLASS_
class AA_COMP_COMP;
class AA_COMP_COMP_persistent_object;
#endif

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
typedef TMultiDComp<_1D_BOND_ASSET, BOND_ASSET_persistent_object> _2D_BOND_ASSET;
#endif

#ifdef __CREATE_BOND_CF_ASSET_CLASS_
class BOND_CF_ASSET;
class BOND_CF_ASSET_persistent_object;
typedef TComp<BOND_CF_ASSET, BOND_CF_ASSET_persistent_object> _1D_BOND_CF_ASSET;
typedef TMultiDComp<_1D_BOND_CF_ASSET, BOND_CF_ASSET_persistent_object> _2D_BOND_CF_ASSET;
#endif

#ifdef __CREATE_EIO_ASSET_CLASS_
class EIO_ASSET;
class EIO_ASSET_persistent_object;
typedef TComp<EIO_ASSET, EIO_ASSET_persistent_object> _1D_EIO_ASSET;
typedef TMultiDComp<_1D_EIO_ASSET, EIO_ASSET_persistent_object> _2D_EIO_ASSET;
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
typedef TMultiDComp<_1D_FIACARVM_LIAB, FIACARVM_LIAB_persistent_object> _2D_FIACARVM_LIAB;
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

#ifdef __CREATE_INVSTRAT_ASSET_CLASS_
class INVSTRAT_ASSET;
class INVSTRAT_ASSET_persistent_object;
typedef TComp<INVSTRAT_ASSET, INVSTRAT_ASSET_persistent_object> _1D_INVSTRAT_ASSET;
#endif

#ifdef __CREATE_LIAB_LIAB_CLASS_
class LIAB_LIAB;
class LIAB_LIAB_persistent_object;
#endif

#ifdef __CREATE_MRB_GAAP_CLASS_
class MRB_GAAP;
class MRB_GAAP_persistent_object;
typedef TComp<MRB_GAAP, MRB_GAAP_persistent_object> _1D_MRB_GAAP;
#endif

#ifdef __CREATE_MTG_ASSET_CLASS_
class MTG_ASSET;
class MTG_ASSET_persistent_object;
typedef TComp<MTG_ASSET, MTG_ASSET_persistent_object> _1D_MTG_ASSET;
typedef TMultiDComp<_1D_MTG_ASSET, MTG_ASSET_persistent_object> _2D_MTG_ASSET;
#endif

#ifdef __CREATE_MTG_CF_ASSET_CLASS_
class MTG_CF_ASSET;
class MTG_CF_ASSET_persistent_object;
typedef TComp<MTG_CF_ASSET, MTG_CF_ASSET_persistent_object> _1D_MTG_CF_ASSET;
typedef TMultiDComp<_1D_MTG_CF_ASSET, MTG_CF_ASSET_persistent_object> _2D_MTG_CF_ASSET;
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

#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
class SFAS97RD_GAAP;
class SFAS97RD_GAAP_persistent_object;
typedef TComp<SFAS97RD_GAAP, SFAS97RD_GAAP_persistent_object> _1D_SFAS97RD_GAAP;
typedef TMultiDComp<_1D_SFAS97RD_GAAP, SFAS97RD_GAAP_persistent_object> _2D_SFAS97RD_GAAP;
#endif



namespace RATES_ECONOMY_NS {
	struct GroupSharedAttributes;
	struct SharedByAllAttributes;
}

class RATES_ECONOMY_persistent_object;
class RATES_ECONOMY : public ModelClass {

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

	size_t sizeofThis() const { return sizeof(RATES_ECONOMY); }

	virtual void createAllShare();

	static HVector<ModelClass::ddfStruct> ddfVector; 
	static BitArray dataVariables; 
	static bool hasBeenWritten;

Economy* Econ;
EconomyData* EconData;
GenerationData* GenData;
CalibrationData* CalibData;
EconErrorCodeType econ_err_code;
vector <xstring> country_list;
vector <xstring> currency_list;
vector <xstring> yld_curve_list;
vector <xstring> index_list;
vector <xstring> misc_list;
vector <xstring> correl_list;
vector <string> econ_data_yld_curve_list;
vector <string> econ_data_yld_curve_term_list;
vector <string> econ_data_yld_curve_vol_mr_term_list;
vector <string> econ_data_index_rate_list;
vector <string> econ_data_index_rate_tenor_list;
vector <string> econ_data_index_rate_moneyness_list;
vector <string> econ_data_misc_rates_list;
vector <string> calib_yld_curve_list;
vector <string> calib_data_swap_maturity_list;
vector <string> calib_data_swap_tenor_list;
vector <string> calib_data_bond_term_list;
vector <string> calib_index_rate_list;
vector <string> calib_data_index_moneyness_list;
vector <string> calib_data_index_term_list;
multimap <xstring, double> yld_curve_vol_surface_list;
multimap <xstring, double> index_vol_surface_list;
multimap <xstring, double>::iterator iter;
pair<multimap<xstring, double>::iterator, multimap<xstring, double>::iterator> range_pair;
map <xstring, double> spot_rates;
map <xstring, double> spot_rates_shifted;
map <xstring, double> yld_rates;
map <xstring, double> yld_rates_shifted;
map <xstring, double> int_vols;
map <xstring, double> index_rates;
map <xstring, double> index_vols;
map <xstring, double> index_vols_shifted;
map <xstring, double> fx_rates;
map <xstring, double> dflt_rates;
map <xstring, double> infl_rates;
map <xstring, double> misc_rates;
map <xstring, double> yld_rates_shifts;
map <xstring, double> index_val_shifts;
map <xstring, double> index_vols_shifts;
vector <xstring> shock_gen_list;
vector <xstring> hedge_valn_shock_list;
xstring hedge_valn_shock_id_prev;
vector <string> hedge_valn_control_tbl;

	void init_(){
		

Econ = nullptr;
EconData = nullptr;
GenData = nullptr;
CalibData = nullptr;
hedge_valn_shock_id_prev = "Undefined";

		bIsInit = true;
	}
	void deInit_(){

if (Econ != nullptr)
    {
    Economy::Release(Econ);
    Econ = nullptr;
    }

if (EconData != nullptr)
    {
    EconomyData::Release(EconData);
    EconData = nullptr;
    }

if (GenData != nullptr)
    {
    GenerationData::Release(GenData);
    GenData = nullptr;
    }

if (CalibData != nullptr)
    {
    CalibrationData::Release(CalibData);
    CalibData = nullptr;
    }


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
	BOND_CF_ASSET	*company_asset_bond_bond_cf_var;
	BOND_CF_ASSET	*&bond_cf_var;
#endif
#ifdef __CREATE_AA_COMP_COMP_CLASS_
	AA_COMP_COMP	*company;
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
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
	FIACARVM_LIAB	*company_liab_fia_carvm_stat;
	FIACARVM_LIAB	*&fia_carvm_stat;
#endif
#ifdef __CREATE_FIACARVM_LIAB_CLASS_
	FIACARVM_LIAB	*company_liab_fia_carvm_tax;
	FIACARVM_LIAB	*&fia_carvm_tax;
#endif
#ifdef __CREATE_MRB_GAAP_CLASS_
	MRB_GAAP	*company_liab_fia_fia_mrb;
	MRB_GAAP	*&fia_mrb;
#endif
#ifdef __CREATE_RATES_ECONOMY_CLASS_
	RATES_ECONOMY	*company_liab_fia_fia_rates;
	RATES_ECONOMY	*&fia_rates;
#endif
#ifdef __CREATE_SFAS97RD_GAAP_CLASS_
	SFAS97RD_GAAP	*company_liab_fia_fia_sfas97rd;
	SFAS97RD_GAAP	*&fia_sfas97rd;
#endif
#ifdef __CREATE_HDG_GRP_COMP_CLASS_
	HDG_GRP_COMP	*company_seg_hedge_grp;
	HDG_GRP_COMP	*&hedge_grp;
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
	MTG_CF_ASSET	*company_asset_mtg_mtg_cf_var;
	MTG_CF_ASSET	*&mtg_cf_var;
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
 // Column Definition Begins
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > equity_market_value_growth_us;
 	ColumnAccessor < mCFStaticData_0 > equity_scenario_total_return_us;
 	ColumnAccessor < mCFStaticData_0 > exact_date;
 	ColumnAccessor < mCFStaticData_0 > finalize;
 	ColumnAccessor < mCFStaticData_0 > generate;
 	ColumnAccessor < mCFStaticData_0 > infl_rate_annual;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > setup_calibration_criteria;
 	ColumnAccessor < mCFStaticData_0 > setup_economy_data;
 	ColumnAccessor < mCFStaticData_0 > setup_generation_parameters;
 	ColumnAccessor < mCFStaticData_0 > setup_shock_gen_list;
 	ColumnAccessor < mCFStaticData_0 > startup;
 	ColumnAccessor < mCFStaticData_0 > yield_rate_10_year;
 	ColumnAccessor < mCFStaticData_0 > yield_rate_90_day;
//Column Definition END@2

 // Temporary Table...
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
	#define DESCRIPTOR_TABLE RATES_ECONOMY::descriptor_0
#ifdef MICROSOFT
#pragma warning(pop)
#endif	MICROSOFT
	Attribute::Proxy <int, DESCRIPTOR_TABLE > cal_yr_lookup;
  inline int	Get_cal_yr_lookup() {
		return cal_yr_lookup; }
  inline void Set_cal_yr_lookup(const int &v) {
		cal_yr_lookup.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_index_rate_div_yld;
  inline double	Get_calib_index_rate_div_yld() {
		return calib_index_rate_div_yld; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > calib_index_rate_moneyness_selected;
  inline xstring	Get_calib_index_rate_moneyness_selected() {
		return calib_index_rate_moneyness_selected; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > calib_index_rate_normalize_wghts_defn;
  inline xstring	Get_calib_index_rate_normalize_wghts_defn() {
		return calib_index_rate_normalize_wghts_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > calib_index_rate_opt_defn;
  inline xstring	Get_calib_index_rate_opt_defn() {
		return calib_index_rate_opt_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_index_rate_opt_vol;
  inline double	Get_calib_index_rate_opt_vol() {
		return calib_index_rate_opt_vol; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_index_rate_opt_wght;
  inline double	Get_calib_index_rate_opt_wght() {
		return calib_index_rate_opt_wght; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > calib_index_rate_selected;
  inline xstring	Get_calib_index_rate_selected() {
		return calib_index_rate_selected; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > calib_index_rate_terms_selected;
  inline xstring	Get_calib_index_rate_terms_selected() {
		return calib_index_rate_terms_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_index_rates_pass_pct;
  inline double	Get_calib_index_rates_pass_pct() {
		return calib_index_rates_pass_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_index_rates_percentile;
  inline double	Get_calib_index_rates_percentile() {
		return calib_index_rates_percentile; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_index_rates_percentile_tgt;
  inline double	Get_calib_index_rates_percentile_tgt() {
		return calib_index_rates_percentile_tgt; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > calib_index_rates_tgt_horizon;
  inline int	Get_calib_index_rates_tgt_horizon() {
		return calib_index_rates_tgt_horizon; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > calib_test_num;
  inline int	Get_calib_test_num() {
		return calib_test_num; }
  inline void Set_calib_test_num(const int &v) {
		calib_test_num.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > calib_yld_curve_bond_terms_selected;
  inline xstring	Get_calib_yld_curve_bond_terms_selected() {
		return calib_yld_curve_bond_terms_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_yld_curve_bond_vol;
  inline double	Get_calib_yld_curve_bond_vol() {
		return calib_yld_curve_bond_vol; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_yld_curve_bond_wght;
  inline double	Get_calib_yld_curve_bond_wght() {
		return calib_yld_curve_bond_wght; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > calib_yld_curve_data_source_defn;
  inline xstring	Get_calib_yld_curve_data_source_defn() {
		return calib_yld_curve_data_source_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > calib_yld_curve_normalize_wghts_defn;
  inline xstring	Get_calib_yld_curve_normalize_wghts_defn() {
		return calib_yld_curve_normalize_wghts_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_yld_curve_rates_pass_pct;
  inline double	Get_calib_yld_curve_rates_pass_pct() {
		return calib_yld_curve_rates_pass_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_yld_curve_rates_percentile;
  inline double	Get_calib_yld_curve_rates_percentile() {
		return calib_yld_curve_rates_percentile; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_yld_curve_rates_percentile_tgt;
  inline double	Get_calib_yld_curve_rates_percentile_tgt() {
		return calib_yld_curve_rates_percentile_tgt; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_yld_curve_rates_rate_adj_a;
  inline double	Get_calib_yld_curve_rates_rate_adj_a() {
		return calib_yld_curve_rates_rate_adj_a; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_yld_curve_rates_rate_adj_b;
  inline double	Get_calib_yld_curve_rates_rate_adj_b() {
		return calib_yld_curve_rates_rate_adj_b; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > calib_yld_curve_rates_rate_term;
  inline int	Get_calib_yld_curve_rates_rate_term() {
		return calib_yld_curve_rates_rate_term; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > calib_yld_curve_rates_tgt_horizon;
  inline int	Get_calib_yld_curve_rates_tgt_horizon() {
		return calib_yld_curve_rates_tgt_horizon; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > calib_yld_curve_selected;
  inline xstring	Get_calib_yld_curve_selected() {
		return calib_yld_curve_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_yld_curve_sprds_pass_pct;
  inline double	Get_calib_yld_curve_sprds_pass_pct() {
		return calib_yld_curve_sprds_pass_pct; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_yld_curve_sprds_percentile;
  inline double	Get_calib_yld_curve_sprds_percentile() {
		return calib_yld_curve_sprds_percentile; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_yld_curve_sprds_percentile_tgt;
  inline double	Get_calib_yld_curve_sprds_percentile_tgt() {
		return calib_yld_curve_sprds_percentile_tgt; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_yld_curve_sprds_sprd_adj;
  inline double	Get_calib_yld_curve_sprds_sprd_adj() {
		return calib_yld_curve_sprds_sprd_adj; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > calib_yld_curve_sprds_tgt_horizon;
  inline int	Get_calib_yld_curve_sprds_tgt_horizon() {
		return calib_yld_curve_sprds_tgt_horizon; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > calib_yld_curve_swap_maturities_selected;
  inline xstring	Get_calib_yld_curve_swap_maturities_selected() {
		return calib_yld_curve_swap_maturities_selected; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > calib_yld_curve_swap_tenors_selected;
  inline xstring	Get_calib_yld_curve_swap_tenors_selected() {
		return calib_yld_curve_swap_tenors_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_yld_curve_swaption_vol;
  inline double	Get_calib_yld_curve_swaption_vol() {
		return calib_yld_curve_swaption_vol; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > calib_yld_curve_swaption_wght;
  inline double	Get_calib_yld_curve_swaption_wght() {
		return calib_yld_curve_swaption_wght; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > correl_id1;
  inline xstring	Get_correl_id1() {
		return correl_id1; }
  inline void Set_correl_id1(const xstring &v) {
		correl_id1.setValue(v); }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > correl_id2;
  inline xstring	Get_correl_id2() {
		return correl_id2; }
  inline void Set_correl_id2(const xstring &v) {
		correl_id2.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > credit_sprd_defn;
  inline xstring	Get_credit_sprd_defn() {
		return credit_sprd_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > credit_sprd_deterministic;
  inline double	Get_credit_sprd_deterministic() {
		return credit_sprd_deterministic; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > credit_sprd_deterministic_pba;
  inline double	Get_credit_sprd_deterministic_pba() {
		return credit_sprd_deterministic_pba; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > credit_sprd_intercept_crbg;
  inline double	Get_credit_sprd_intercept_crbg() {
		return credit_sprd_intercept_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > credit_sprd_slope_crbg;
  inline double	Get_credit_sprd_slope_crbg() {
		return credit_sprd_slope_crbg; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > credit_sprd_stoch_mult;
  inline double	Get_credit_sprd_stoch_mult() {
		return credit_sprd_stoch_mult; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > date_lookup;
  inline int	Get_date_lookup() {
		return date_lookup; }
  inline void Set_date_lookup(const int &v) {
		date_lookup.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > dflt_rate_deterministic;
  inline double	Get_dflt_rate_deterministic() {
		return dflt_rate_deterministic; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > dflt_rate_deterministic_pba;
  inline double	Get_dflt_rate_deterministic_pba() {
		return dflt_rate_deterministic_pba; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > dflt_rate_stoch_mult;
  inline double	Get_dflt_rate_stoch_mult() {
		return dflt_rate_stoch_mult; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > econ_data_correlation;
  inline double	Get_econ_data_correlation() {
		return econ_data_correlation; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > econ_data_index_rate_moneyness_selected;
  inline xstring	Get_econ_data_index_rate_moneyness_selected() {
		return econ_data_index_rate_moneyness_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > econ_data_index_rate_mr_grwth;
  inline double	Get_econ_data_index_rate_mr_grwth() {
		return econ_data_index_rate_mr_grwth; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > econ_data_index_rate_mr_inc_ret;
  inline double	Get_econ_data_index_rate_mr_inc_ret() {
		return econ_data_index_rate_mr_inc_ret; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > econ_data_index_rate_mr_sprd;
  inline double	Get_econ_data_index_rate_mr_sprd() {
		return econ_data_index_rate_mr_sprd; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > econ_data_index_rate_mr_term;
  inline double	Get_econ_data_index_rate_mr_term() {
		return econ_data_index_rate_mr_term; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > econ_data_index_rate_selected;
  inline xstring	Get_econ_data_index_rate_selected() {
		return econ_data_index_rate_selected; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > econ_data_index_rate_tenor_selected;
  inline xstring	Get_econ_data_index_rate_tenor_selected() {
		return econ_data_index_rate_tenor_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > econ_data_index_rate_vol;
  inline double	Get_econ_data_index_rate_vol() {
		return econ_data_index_rate_vol; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > econ_data_misc_rates;
  inline double	Get_econ_data_misc_rates() {
		return econ_data_misc_rates; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > econ_data_misc_rates_selected;
  inline xstring	Get_econ_data_misc_rates_selected() {
		return econ_data_misc_rates_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > econ_data_yld_curve_mr_rates;
  inline double	Get_econ_data_yld_curve_mr_rates() {
		return econ_data_yld_curve_mr_rates; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > econ_data_yld_curve_selected;
  inline xstring	Get_econ_data_yld_curve_selected() {
		return econ_data_yld_curve_selected; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > econ_data_yld_curve_term_selected;
  inline xstring	Get_econ_data_yld_curve_term_selected() {
		return econ_data_yld_curve_term_selected; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > econ_data_yld_curve_vol;
  inline double	Get_econ_data_yld_curve_vol() {
		return econ_data_yld_curve_vol; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > econ_data_yld_curve_vol_mr_term_selected;
  inline xstring	Get_econ_data_yld_curve_vol_mr_term_selected() {
		return econ_data_yld_curve_vol_mr_term_selected; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > eqt_price_shock_defn;
  inline xstring	Get_eqt_price_shock_defn() {
		return eqt_price_shock_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > eqt_vol_shock;
  inline double	Get_eqt_vol_shock() {
		return eqt_vol_shock; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > eqt_vol_shock_defn;
  inline xstring	Get_eqt_vol_shock_defn() {
		return eqt_vol_shock_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > eqt_vol_shock_id;
  inline xstring	Get_eqt_vol_shock_id() {
		return eqt_vol_shock_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gen_approach_defn;
  inline xstring	Get_gen_approach_defn() {
		return gen_approach_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gen_basis_defn;
  inline xstring	Get_gen_basis_defn() {
		return gen_basis_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gen_calib_defn;
  inline xstring	Get_gen_calib_defn() {
		return gen_calib_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gen_calib_detail_defn;
  inline xstring	Get_gen_calib_detail_defn() {
		return gen_calib_detail_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gen_calib_retry_attempts;
  inline int	Get_gen_calib_retry_attempts() {
		return gen_calib_retry_attempts; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gen_defn;
  inline xstring	Get_gen_defn() {
		return gen_defn; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gen_detail_defn;
  inline xstring	Get_gen_detail_defn() {
		return gen_detail_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gen_detail_scen;
  inline int	Get_gen_detail_scen() {
		return gen_detail_scen; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gen_hist_mths;
  inline int	Get_gen_hist_mths() {
		return gen_hist_mths; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gen_initial_valn_period;
  inline xstring	Get_gen_initial_valn_period() {
		return gen_initial_valn_period; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gen_mean_reversion_mths;
  inline int	Get_gen_mean_reversion_mths() {
		return gen_mean_reversion_mths; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gen_mths;
  inline int	Get_gen_mths() {
		return gen_mths; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gen_random_seed;
  inline int	Get_gen_random_seed() {
		return gen_random_seed; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gen_rates_freq;
  inline xstring	Get_gen_rates_freq() {
		return gen_rates_freq; }
	Attribute::ProxyReadOnly <SimpleArray<double>, DESCRIPTOR_TABLE > gen_rn_bonds_term;

    inline SimpleArray<double>	Get_gen_rn_bonds_term() { 
		return gen_rn_bonds_term;
    }
	inline double Get_gen_rn_bonds_term(const long index) const {
		return gen_rn_bonds_term.operator[] (index);
	}
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > gen_rn_defn;
  inline xstring	Get_gen_rn_defn() {
		return gen_rn_defn; }
  inline void Set_gen_rn_defn(const xstring &v) {
		gen_rn_defn.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gen_rn_int_proj_defn;
  inline xstring	Get_gen_rn_int_proj_defn() {
		return gen_rn_int_proj_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gen_rw_mrp_mean_yrs_1;
  inline double	Get_gen_rw_mrp_mean_yrs_1() {
		return gen_rw_mrp_mean_yrs_1; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gen_rw_mrp_mean_yrs_2;
  inline double	Get_gen_rw_mrp_mean_yrs_2() {
		return gen_rw_mrp_mean_yrs_2; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > gen_rw_mrp_median_yrs;
  inline double	Get_gen_rw_mrp_median_yrs() {
		return gen_rw_mrp_median_yrs; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gen_rw_stoch_defn;
  inline xstring	Get_gen_rw_stoch_defn() {
		return gen_rw_stoch_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > gen_scenarios;
  inline int	Get_gen_scenarios() {
		return gen_scenarios; }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > gen2_declarations;
  inline xstring	Get_gen2_declarations() {
		return gen2_declarations; }
  inline void Set_gen2_declarations(const xstring &v) {
		gen2_declarations.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > get_fx_rate_defn;
  inline xstring	Get_get_fx_rate_defn() {
		return get_fx_rate_defn; }
  inline void Set_get_fx_rate_defn(const xstring &v) {
		get_fx_rate_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > get_index_rate_defn;
  inline xstring	Get_get_index_rate_defn() {
		return get_index_rate_defn; }
  inline void Set_get_index_rate_defn(const xstring &v) {
		get_index_rate_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > get_index_val_shift_defn;
  inline xstring	Get_get_index_val_shift_defn() {
		return get_index_val_shift_defn; }
  inline void Set_get_index_val_shift_defn(const xstring &v) {
		get_index_val_shift_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > get_index_vol_shift_defn;
  inline xstring	Get_get_index_vol_shift_defn() {
		return get_index_vol_shift_defn; }
  inline void Set_get_index_vol_shift_defn(const xstring &v) {
		get_index_vol_shift_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > get_int_rate_defn;
  inline xstring	Get_get_int_rate_defn() {
		return get_int_rate_defn; }
  inline void Set_get_int_rate_defn(const xstring &v) {
		get_int_rate_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > get_int_rate_shift_defn;
  inline xstring	Get_get_int_rate_shift_defn() {
		return get_int_rate_shift_defn; }
  inline void Set_get_int_rate_shift_defn(const xstring &v) {
		get_int_rate_shift_defn.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > get_scen_set_defn;
  inline xstring	Get_get_scen_set_defn() {
		return get_scen_set_defn; }
  inline void Set_get_scen_set_defn(const xstring &v) {
		get_scen_set_defn.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > historic_rates_id;
  inline xstring	Get_historic_rates_id() {
		return historic_rates_id; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > index_id;
  inline xstring	Get_index_id() {
		return index_id; }
  inline void Set_index_id(const xstring &v) {
		index_id.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_vol_deterministic;
  inline double	Get_index_vol_deterministic() {
		return index_vol_deterministic; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > index_vol_stoch_mult;
  inline double	Get_index_vol_stoch_mult() {
		return index_vol_stoch_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > infl_defn;
  inline xstring	Get_infl_defn() {
		return infl_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > infl_deterministic;
  inline double	Get_infl_deterministic() {
		return infl_deterministic; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > inner_loop_historic_rates_id;
  inline xstring	Get_inner_loop_historic_rates_id() {
		return inner_loop_historic_rates_id; }
  inline void Set_inner_loop_historic_rates_id(const xstring &v) {
		inner_loop_historic_rates_id.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > inner_loop_valn_scen_id;
  inline xstring	Get_inner_loop_valn_scen_id() {
		return inner_loop_valn_scen_id; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > inner_loop_valn_scen_reuse_defn;
  inline xstring	Get_inner_loop_valn_scen_reuse_defn() {
		return inner_loop_valn_scen_reuse_defn; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > int_rate_shock;
  inline double	Get_int_rate_shock() {
		return int_rate_shock; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > int_rate_shock_defn;
  inline xstring	Get_int_rate_shock_defn() {
		return int_rate_shock_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > int_rate_shock_id;
  inline xstring	Get_int_rate_shock_id() {
		return int_rate_shock_id; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > int_vol_deterministic;
  inline double	Get_int_vol_deterministic() {
		return int_vol_deterministic; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > int_vol_stoch_mult;
  inline double	Get_int_vol_stoch_mult() {
		return int_vol_stoch_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > missing_val_defn;
  inline xstring	Get_missing_val_defn() {
		return missing_val_defn; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > moneyness;
  inline double	Get_moneyness() {
		return moneyness; }
  inline void Set_moneyness(const double &v) {
		moneyness.setValue(v); }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > open_file_retry_attempts;
  inline int	Get_open_file_retry_attempts() {
		return open_file_retry_attempts; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > phldr_shock_defn;
  inline xstring	Get_phldr_shock_defn() {
		return phldr_shock_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > proj_date;
  inline xstring	Get_proj_date() {
		return proj_date; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > quality_id;
  inline xstring	Get_quality_id() {
		return quality_id; }
  inline void Set_quality_id(const xstring &v) {
		quality_id.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > rate_term;
  inline double	Get_rate_term() {
		return rate_term; }
  inline void Set_rate_term(const double &v) {
		rate_term.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > save_time_step_scen_files_defn;
  inline xstring	Get_save_time_step_scen_files_defn() {
		return save_time_step_scen_files_defn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > scen_file_name_addn;
  inline xstring	Get_scen_file_name_addn() {
		return scen_file_name_addn; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > scen_id;
  inline xstring	Get_scen_id() {
		return scen_id; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > scen_index_id;
  inline xstring	Get_scen_index_id() {
		return scen_index_id; }
  inline void Set_scen_index_id(const xstring &v) {
		scen_index_id.setValue(v); }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > shock_freq;
  inline int	Get_shock_freq() {
		return shock_freq; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > shock_id;
  inline xstring	Get_shock_id() {
		return shock_id; }
  inline void Set_shock_id(const xstring &v) {
		shock_id.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > shock_id_selected;
  inline xstring	Get_shock_id_selected() {
		return shock_id_selected; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > swap_maturity;
  inline double	Get_swap_maturity() {
		return swap_maturity; }
  inline void Set_swap_maturity(const double &v) {
		swap_maturity.setValue(v); }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > swap_tenor;
  inline double	Get_swap_tenor() {
		return swap_tenor; }
  inline void Set_swap_tenor(const double &v) {
		swap_tenor.setValue(v); }
	Attribute::Proxy <StringEnum, DESCRIPTOR_TABLE > use_shifted_yld_curve_defn;
  inline xstring	Get_use_shifted_yld_curve_defn() {
		return use_shifted_yld_curve_defn; }
  inline void Set_use_shifted_yld_curve_defn(const xstring &v) {
		use_shifted_yld_curve_defn.setValue(v); }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > valn_periods_selected;
  inline xstring	Get_valn_periods_selected() {
		return valn_periods_selected; }
	Attribute::Proxy <xstring, DESCRIPTOR_TABLE > yld_curve_id;
  inline xstring	Get_yld_curve_id() {
		return yld_curve_id; }
  inline void Set_yld_curve_id(const xstring &v) {
		yld_curve_id.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > yld_curve_mem_defn;
  inline xstring	Get_yld_curve_mem_defn() {
		return yld_curve_mem_defn; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > msnumelement;
  inline int	Get_msnumelement() {
		return msnumelement; }
  inline void Set_msnumelement(const int &v) {
		msnumelement.setValue(v); }
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > gen_scen_file_path;
	Attribute::Proxy<Scalar<xstring>, DESCRIPTOR_TABLE > proj_date_adj;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_date_offset;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_date;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_mth;
	Attribute::Proxy<Scalar<int>, DESCRIPTOR_TABLE > proj_start_yr;

void setPtr_col(int cf_no, CashFlowBase* cf);
void start_of_projection();
void findTargetColumns();
void start_of_layer();
void end_of_projection();
void end_of_layer(int layer_skipped=0);
void after_startup(int decrement = 0);
 void copy_names();
 void passDataVariables(RATES_ECONOMY* target) { passDataVars(target); }

 void mapVariables();

 // External function prototypes

// Calc Fwrd Rate Crbg
#line 1 "calc_fwrd_rate_crbg.rates_economy.for"
double calc_fwrd_rate_crbg(int t, double rate_term_input, double fwd_term, xstring disc_curve);

// Calculate Spot Rates From Yield Rates
#line 1 "calc_spot_from_yld.rates_economy.for"
double calc_spot_from_yld(int t, const xstring &quality_id, double term, int shift_type, double port_sprd_adj_crbg);

// Calculate Yield Rates From Spot Rates
#line 1 "calc_yld_from_spot.rates_economy.for"
double calc_yld_from_spot(int t, const xstring &quality_id, double term, int shift_type, double port_sprd_adj_crbg);

// Clear Shifted Rates Maps
#line 1 "clear_shifted_rates_maps.rates_economy.for"
void clear_shifted_rates_maps(void);

// Economy Error Processing
#line 1 "econ_error_processing.rates_economy.for"
void econ_error_processing(EconErrorCodeType econ_err_code);

// Economy Rate Error Processing
#line 1 "econ_rate_error_processing.rates_economy.for"
void econ_rate_error_processing(int t, xstring id, EconErrorCodeType econ_err_code);

// Get Default Rate
#line 1 "get_dflt_rate.rates_economy.for"
double get_dflt_rate(int t, const xstring &quality_id_input, double rate_term_input, int return_rate_basis);

// Get Exchange Rate
#line 1 "get_fx_rate.rates_economy.for"
double get_fx_rate(int t, const xstring &base_country, const xstring &alt_country, double fwd_mths, int curr_quote_type);

// Get Index Rate
#line 1 "get_index_rate.rates_economy.for"
double get_index_rate(int t, const xstring &index_id, int rate_type, int return_rate_basis);

// Get Index Value
#line 1 "get_index_val.rates_economy.for"
double get_index_val(int t, const xstring &index_id);

// Get Index Volatility
#line 1 "get_index_vol.rates_economy.for"
double get_index_vol(int t, const xstring &index_id_input, double moneyness_input, double rate_term_input, int return_rate_basis, int shift_type);

// Get Inflation Rate
#line 1 "get_infl_rate.rates_economy.for"
double get_infl_rate(int t, int return_rate_basis);

// Get Interest Rate
#line 1 "get_int_rate.rates_economy.for"
double get_int_rate(int t, const xstring &quality_id_input, int rate_type, double rate_term_input, double fwd_term, int return_rate_basis, int shift_type,  double port_sprd_adj_crbg = 0);

// Get Interest Volatility
#line 1 "get_int_vol.rates_economy.for"
double get_int_vol(int t, const xstring &quality_id_input, double moneyness_input, double rate_term_input, int return_rate_basis);

// Get Miscellaneous Rate
#line 1 "get_misc_rate.rates_economy.for"
double get_misc_rate(int t, const xstring &misc_rate_id, int return_rate_basis);

// Scenario Rates Load
#line 1 "scen_rates_load.rates_economy.for"
void scen_rates_load(int scen_num);

// Scenario Set Information Load
#line 1 "scen_set_info_load.rates_economy.for"
void scen_set_info_load(void);

// Select Scenario Set
#line 1 "select_scen_set.rates_economy.for"
void select_scen_set(int scen_set_type);


//factory
static RATES_ECONOMY* makeThis(int isSubmodel, ModelClass *owner, RATES_ECONOMY* peer, 
					int mainRebase, const xstring &name, RATES_ECONOMY_persistent_object* arrayTemplate);

//constructor
RATES_ECONOMY(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
					int mainRebase, const char *name, ModelClass* arrayPersistentObj);

// constructor if this model class is the base class of another model class
RATES_ECONOMY(int columnCount, Descriptor* mocd[], Product* persObj);

//destructor
~RATES_ECONOMY();


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
class RATES_ECONOMY_persistent_object : public RATES_ECONOMY {


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

	void findTargetColumns() {RATES_ECONOMY::findTargetColumns();}
	void createAllShare() {
		RATES_ECONOMY::createAllShare();
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

	ProductFeatureList* pfl;

	// objects that do not support magic arrow (i.e. tables)
private:

public :


	~RATES_ECONOMY_persistent_object();

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
static RATES_ECONOMY_persistent_object* makeThis(int isSubmodel, ModelClass *owner, RATES_ECONOMY* peer, 
					int mainRebase, const xstring &name, RATES_ECONOMY_persistent_object* arrayTemplate, bool fixedArray);

//constructor
RATES_ECONOMY_persistent_object(const xstring &modelClassName,
		int isSm, ModelClass *owner, ModelClass *peer, int mainRebase, const char *name, ModelClass* arrayPersistentObj);
};

#endif
