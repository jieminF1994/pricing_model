#ifndef __RATES_ECONOMY_H_
#define __RATES_ECONOMY_H_
#pragma warning ( disable : 4819 )

#include <sstream> // For ostringstream
#include <sys/stat.h> // For file access
#include <vector>
#include <cmath>  // For floor()
#include <random> // 20200214 STW: import package for random number generation
				  // 20200303 MTC - Ported VA PRNG code for Flex

#pragma once
// Common elements from the Economy interface  -- enums, constants

#ifdef ECONOMY_EXPORTS
#define ECONOMY_API __declspec(dllexport)
//#else
//#define ECONOMY_API __declspec(dllimport)//WTW - Gen2 - replace attribute below with direct 
#endif

#define NOMINMAX

//WTW - Gen2
// 20181217 MTC - Refactored cubic spline
#ifndef CUBIC_SPLINE_AIG//WTW - Gen2
struct cubic_spline_params_aig
{
	cubic_spline_params_aig(): initialized(false),
						       n(0),
							   h(vector<double>()),
							   alpha(vector<double>()),
							   l(vector<double>()),
							   mu(vector<double>()),
							   z(vector<double>()),
							   c(vector<double>()),
							   b(vector<double>()),
							   d(vector<double>()) {}
	bool initialized;
	int n;
	vector<double> h;
	vector<double> alpha;
	vector<double> l;
	vector<double> mu;
	vector<double> z;
	vector<double> c;
	vector<double> b;
	vector<double> d;
};

const cubic_spline_params_aig default_cubic_spline_params_aig = cubic_spline_params_aig();
// 20181217 MTC END
#define CUBIC_SPLINE_AIG//WTW - Gen2
#endif//WTW - Gen2

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

enum /*ECONOMY_API*/ __declspec(dllimport)  GenerationApproachType//WTW - Gen2
{
Stochastic=1,
MeanReversion = 2,
MeanReversionWithIndexSpread = 3,
StochasticExclusionTest = 4
};

enum /*ECONOMY_API*/ __declspec(dllimport) RWGenerationStochDefn//WTW - Gen2
{
RandomScenarios = 1,
AcademySelectedScenarios = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) GenerationRNMethod//WTW - Gen2
{
QuickGeneration=1,
CompleteGeneration= 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) GenerationMethod//WTW - Gen2
{
StandAlone=1,
OnTheFly = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) GenerationAudit//WTW - Gen2
{
AuditNo = 0,
AuditYes = 1
};

enum /*ECONOMY_API*/ __declspec(dllimport) YieldCurveTreatmentType//WTW - Gen2
{
ReleaseFromMemory = 1,
KeepInMemory = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) DateTreatmentType//WTW - Gen2
{
Actual = 1,
Relative = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) ScenSetType//WTW - Gen2
{
Outer = 1,
Inner = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) EconErrorCodeType//WTW - Gen2
{
ECON_OK = 1,
ECON_WARNING = 2,
ECON_ERROR = 3
};

enum /*ECONOMY_API*/ __declspec(dllimport) ScenarioBasisType//WTW - Gen2
{
RealWorld = 1,
RiskNeutral = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) ValuationScenType//WTW - Gen2
{
AllRates = 1,
IndexRatesOnly = 2,
NoRatesReused = 3
};

enum /*ECONOMY_API*/ __declspec(dllimport) ScenarioDefnType//WTW - Gen2
{
UnShocked = 1,
Shocked = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) MonthsPerPeriodType//WTW - Gen2
{
MonthlyRates = 1,
AnnualRates = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) YieldRateType//WTW - Gen2
{
Bond = 1,
Spot = 2,
Forward = 3
};

enum /*ECONOMY_API*/ __declspec(dllimport) CurrencyQuoteType//WTW - Gen2
{
Direct = 1,
Indirect = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) MissingValType//WTW - Gen2
{
Interpolate = 1,
Previous = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) RateReturnFreqType//WTW - Gen2
{
EffectiveAnnual = 1,
NominalSemiannual = 2,
NominalQuarterly = 4,
NominalMonthly = 12,
Semiannual = -2,
Quarterly = -4,
Monthly = -12
};

enum /*ECONOMY_API*/ __declspec(dllimport) ShockMethod//WTW - Gen2
{
Baseline = 1,
ParallelShock = 2,
SpecificShock = 3
};

enum /*ECONOMY_API*/ __declspec(dllimport) ShockBasisType//WTW - Gen2
{
YieldCurveShock = 1,
IndexShock = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) ShockType//WTW - Gen2
{
RateorPriceShock = 1,
VolatilityShock = 2
};

enum /*ECONOMY_API*/ __declspec(dllimport) EquityRateType//WTW - Gen2
{
GrowthRate = 1,
IncomeReturn = 2,
TotalReturn = 3,
DividendYield = 4,
IndexValue = 5
};

class /*ECONOMY_API*/ __declspec(dllimport) YieldTermData//WTW - Gen2
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
    static  YieldTermData * YieldTermData::Create();
    static void YieldTermData::Release(YieldTermData *ytd);
};

class /*ECONOMY_API*/ __declspec(dllimport) YieldCurveData//WTW - Gen2
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
    static  YieldCurveData* YieldCurveData::Create();
    static void YieldCurveData::Release(YieldCurveData* ycd);
};

class /*ECONOMY_API*/ __declspec(dllimport) EcoCurrency//WTW - Gen2
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
    static  EcoCurrency* EcoCurrency::Create();
    static void EcoCurrency::Release(EcoCurrency* ec);
};

class /*ECONOMY_API*/ __declspec(dllimport) AssetIndexTenorData//WTW - Gen2
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
    static AssetIndexTenorData* AssetIndexTenorData::Create();
    static void AssetIndexTenorData::Release(AssetIndexTenorData* aitd);
};

class /*ECONOMY_API*/ __declspec(dllimport) AssetIndexData//WTW - Gen2
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
    static  AssetIndexData* AssetIndexData::Create();
    static void AssetIndexData::Release(AssetIndexData* aid);
};

class /*ECONOMY_API*/ __declspec(dllimport) MiscRateData//WTW - Gen2
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
      static  MiscRateData* MiscRateData::Create();
      static  void MiscRateData::Release(MiscRateData* mrd);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationSwapData//WTW - Gen2
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
	static CalibrationSwapData * CalibrationSwapData::Create();
	static void CalibrationSwapData::Release(CalibrationSwapData *csd);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationBondData//WTW - Gen2
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
	static CalibrationBondData * CalibrationBondData::Create();
	static void CalibrationBondData::Release(CalibrationBondData *cbd);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationYieldCurveData//WTW - Gen2
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
	static CalibrationYieldCurveData * CalibrationYieldCurveData::Create();
	static void CalibrationYieldCurveData::Release(CalibrationYieldCurveData *cbd);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationAssetIndexVolData//WTW - Gen2
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
	static CalibrationAssetIndexVolData * CalibrationAssetIndexVolData::Create();
	static void CalibrationAssetIndexVolData::Release(CalibrationAssetIndexVolData *caivd);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationAssetIndexData//WTW - Gen2
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
	static CalibrationAssetIndexData * CalibrationAssetIndexData::Create();
	static void CalibrationAssetIndexData::Release(CalibrationAssetIndexData * caid);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationPointData//WTW - Gen2
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
    static  CalibrationPointData* CalibrationPointData::Create();
    static void CalibrationPointData::Release(CalibrationPointData* aid);
};

class /*ECONOMY_API*/ __declspec(dllimport) CalibrationData//WTW - Gen2
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
	static  CalibrationData  * CalibrationData::Create();
	static  void CalibrationData::Release(CalibrationData * aid);
};

class /*ECONOMY_API*/ __declspec(dllimport) EconomyData//WTW - Gen2
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
    static EconomyData* EconomyData::Create();
    static void EconomyData::Release(EconomyData* ed);
};

class /*ECONOMY_API*/ __declspec(dllimport) GenerationData//WTW - Gen2
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
        static GenerationData* GenerationData::Create();
        static void GenerationData::Release(GenerationData* gd);
};

class RAScenario;

class /*ECONOMY_API*/ __declspec(dllimport) Economy//WTW - Gen2
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
	int						ValnPeriod; //VC++ 2017 Econ DLL
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
	virtual EconErrorCodeType WINAPI set_ValnPeriod(int valnPeriod); //VC++ 2017 Econ DLL
    virtual EconErrorCodeType WINAPI set_EconFilesRetryAttempts(int cnt);
    virtual EconErrorCodeType WINAPI get_ProjDate(long &projYr,long &projMth, long &projDay);
    virtual EconErrorCodeType WINAPI get_ProjYear(long &projYr);
    virtual EconErrorCodeType WINAPI get_ProjMonth(long &projMth);
    virtual EconErrorCodeType WINAPI get_ProjDay(long &projDay);
	virtual EconErrorCodeType WINAPI get_ValnPeriod(int &valnPeriod); //VC++ 2017 Econ DLL
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
    static Economy* Economy::Create();
    static void Economy::Release(Economy* ecdat);
  };

//WTW - Gen2 - Move Extern definitions to rates header
static bool pricing_flag = false;
const int CALL_CODE = 1;
const int PUT_CODE = 2; 
const int CONTINUOUS_PAYOUT_CODE = 3;
const int FUTURES_CODE = 4;const double MINIMUM_MONTHLY_YIELD_RATIO = -0.9; // annual yield = (1.0-0.9)^12 = 1.0e-12
const double MAXIMUM_MONTHLY_YIELD_RATIO	 = 999999999.0; // annual yield = (1.0+999999999.0)^12 = 1.0e+120

static double round_result(int rounding, int negative, double x, int n)
{
if (x == 0.0)
	return 0.0;
int loop = 0;
char buff[20] = {0};
const double tenth[15]
= {1, 0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001,
0.00000001, 0.000000001, 0.0000000001, 0.00000000001,
0.000000000001, 0.0000000000001, 0.00000000000001};
const double ten[15]
= {1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0, 10000000.0,
100000000.0, 1000000000.0, 10000000000.0, 100000000000.0, 1000000000000.0,
10000000000000.0, 100000000000000.0};
double adj = 0.0;
// Note: do not increase the number of nines below.  The result of the round
// (see formula at the bottom of the routine) added to the number of 9's must
// not exceed 16 digits.
const int ROUND_NEGATIVE_TOZERO = 0;
const int ROUND_NEGATIVE_FROMZERO = 1;
const int ROUND_LOW = 0;
const int ROUND_NEAR = 1;
const int ROUND_HIGH = 2;
// ad_hoc adjustment factor  0.000000001
const double positive_high = 0.999999999;
const double positive_low  = 0.0;
const double positive_near = 0.500000001;
const double negative_high = 0.0;
const double negative_low  = 0.999999999;
const double negative_near = 0.499999999;
// The below "rounding" is to deal with floats that were converted to doubles,
// and thus have a loss of information past 6 places
//  To truncate x to 5 decimal places: sprintf() %.6lf to avoid rounding at the
//  5th decimal position then get rid of the last digit.
if (rounding >= 3)
	{
	sprintf(buff,"%.6lf",x);
	buff[strlen(buff)-1]='\0';
	x = strtod(buff, NULL);
	rounding-=3;
	}
if (n < 0 || n > 14)
	return(x);
if (x < (double) 0  && negative == ROUND_NEGATIVE_TOZERO)
	{
	if (rounding==ROUND_HIGH)
		adj = negative_high;
	else if (rounding==ROUND_NEAR)
		adj = negative_near;
	}
else if (x < (double) 0  && negative == ROUND_NEGATIVE_FROMZERO
	     && rounding==ROUND_LOW)
	adj = negative_low;
else
	{
	// ***************************************************
	// x < 0 with negative==tozero and rounding==low
	// x < 0 with negative==fromzero and rounding==high
	// x < 0 with negative==fromzero and rounding==near
	// x > 0
	// ***************************************************
	if (rounding == ROUND_HIGH)
		adj = positive_high;
	else if (rounding == ROUND_NEAR)
		adj = positive_near;
	else if (rounding == ROUND_LOW)
		adj = positive_low;
	}
if (x < (double) 0)
	return(-1 * floor(x * ten[n] * -1 + adj) * tenth[n]);
return(floor(x * ten[n] + adj) * tenth[n]);
}
//////////////////////////////////////////////////////
static double factorial(int n)
{
if (n <= 1)
	return 1;

double result = 1.0;

for (int i = 1; i <= n; i++)
	result = result * i;

return result;
}
//////////////////////////////////////////////////////
static int n_choose_k(int n, int k)
{
if (k < 0 || k > n)
	return 0;

if (k < 1)
	return 1;

if (k == n)
	return 1;

return n_choose_k(n - 1, k) + n_choose_k(n - 1, k - 1);
}
//////////////////////////////////////////////////////
static xstring check_date_format(const xstring &date)
{
// Check for format
char* endptr;
double date_serial_number = strtod(date, &endptr);
if (!*endptr 
	&& date_serial_number >= 1 
	&& date_serial_number <= 2958465) // input date is a date_serial_number
	return "DSN";

// input date is not a date_serial_number, treat it like a regular string	
int date_length = date.length();
xstring date_format = "USLIB";
if (date_length < 6 || date_length > 10)
	throw FatalError("Date = " + xstring(date) + ". It is not properly formatted.");

if (date.substr(4, 1) != "/" && date(date.find_last_of("/") + 1).length() != 4)
	throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Two digit years are not supported.");

if (date(date.find_last_of("/") + 1).length() == 4)
	{
	// date is US format
	date_format = "US";
	// date is m/yyyy, m/d/yyyy, m/dd/yyyy, mm/yyyy, mm/d/yyyy or mm/dd/yyyy
	if (date.find_first_of("/") > 2)
		throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Month contains more than 2 digits.");
		
	if (date.find_last_of("/") == 6 && date_length > 7)
		throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Day contains more than 2 digits.");
	}
else
	{
	date_format = "USLIB";
	// date is yyyy/m, yyyy/m/d, yyyy/m/dd, yyyy/mm, yyyy/mm/d, or yyyy/mm/dd
	if (date.find_last_of("/") > 7)
		throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Month contains more than 2 digits.");
		
	if (date.find_last_of("/") == 6 && date_length > 9)
		throw FatalError("Date = " + xstring(date) + ". It is not properly formatted. Day contains more than 2 digits.");
	}
return date_format;
}
/////////////////////////////////////////////////////
static int month_from_day_number(int nSerialDate)//WTW - Gen2 - add new formula to replace unsupported MonthFromDayNumber() function
{
// Excel/Lotus 123 have a bug with 29-02-1900. 1900 is not a
// leap year, but Excel/Lotus 123 think it is...
if (nSerialDate == 60)
    return 2;

else if (nSerialDate < 60)
	{
    // Because of the 29-02-1900 bug, any serial date 
    // under 60 is one off... Compensate.
    nSerialDate++;
	}

// Modified Julian to DMY calculation with an addition of 2415019
int l = nSerialDate + 68569 + 2415019;
int n = int(( 4 * l ) / 146097);

l = l - int(( 146097 * n + 3 ) / 4);

int i = int(( 4000 * ( l + 1 ) ) / 1461001);

l = l - int(( 1461 * i ) / 4) + 31;

int j = int(( 80 * l ) / 2447);

l = int(j / 11);
    
return j + 2 - ( 12 * l );
}
/////////////////////////////////////////////////////
static int get_mth_from_date(const xstring &date)
{
xstring date_format = check_date_format(date);
if (date_format == "DSN")//WTW - Gen2 - create new function to calculate
	return month_from_day_number(atoi(date));
	//return MonthFromDayNumber(atof(date));

// date_format != "DSN"
int mth = 0;
// find where mth information starts and ends
int mth_start_idx = 0;
int mth_end_idx = 0;
if (date_format == "USLIB")
	{
	mth_start_idx = date.find_first_of("/") + 1;
	mth_end_idx = date.find_last_of("/");
	
	if (mth_end_idx == mth_start_idx) // there is no day in the date
		mth = atoi(date.substr(mth_start_idx));
	else
		mth = atoi(date.substr(mth_start_idx, mth_end_idx - mth_start_idx));
	}
else // date_format == "US" 
	{
	mth_start_idx = 0;
	mth_end_idx = date.find_first_of("/");
	mth = atoi(date.substr(mth_start_idx, mth_end_idx - mth_start_idx));
	}
// validate month entry
if (mth < 1 || mth > 12)
	throw FatalError("Date = " + xstring(date) + ". It is not formatted properly. Invalid month value (" + xstring(mth) + ") in date.");	
return mth;
}
///////////////////////////////////////////////
static int month_number_from_date(int year, int month) //WTW - Gen2 - add new formula to replace unsupported MonthNumberFromDate() function
{
return 12 * year + month - 1;
}
/////////////////////////////////////////////////////
static int day_number_from_date(int nYear, int nMonth, int nDay) //WTW - Gen2 - add new formula to replace unsupported DayNumberFromDate() function
{
    // Excel/Lotus 123 have a bug with 29-02-1900. 1900 is not a
    // leap year, but Excel/Lotus 123 think it is...
    if (nDay == 29 && nMonth == 02 && nYear==1900)
        return 60;

    // DMY to Modified Julian calculated with an extra subtraction of 2415019.
    long nSerialDate = 
            int(( 1461 * ( nYear + 4800 + int(( nMonth - 14 ) / 12) ) ) / 4) +
            int(( 367 * ( nMonth - 2 - 12 * ( ( nMonth - 14 ) / 12 ) ) ) / 12) -
            int(( 3 * ( int(( nYear + 4900 + int(( nMonth - 14 ) / 12) ) / 100) ) ) / 4) +
            nDay - 2415019 - 32075;

    if (nSerialDate < 60)
    {
        // Because of the 29-02-1900 bug, any serial date 
        // under 60 is one off... Compensate.
        nSerialDate--;
    }

    return (int)nSerialDate;
}
/////////////////////////////////////////////////////
static int year_from_day_number(int nSerialDate)//WTW - Gen2 - add new formula to replace unsupported YearFromDayNumber() function
{
// Excel/Lotus 123 have a bug with 29-02-1900. 1900 is not a
// leap year, but Excel/Lotus 123 think it is...
if (nSerialDate == 60)
    return 1900;

else if (nSerialDate < 60)
	{
    // Because of the 29-02-1900 bug, any serial date 
    // under 60 is one off... Compensate.
    nSerialDate++;
	}

// Modified Julian to DMY calculation with an addition of 2415019
int l = nSerialDate + 68569 + 2415019;
int n = int(( 4 * l ) / 146097);

l = l - int(( 146097 * n + 3 ) / 4);

int i = int(( 4000 * ( l + 1 ) ) / 1461001);

l = l - int(( 1461 * i ) / 4) + 31;

int j = int(( 80 * l ) / 2447);

l = int(j / 11);
    
return 100 * ( n - 49 ) + i + l;
}
/////////////////////////////////////////////////////
static int get_yr_from_date(const xstring &date)
{
xstring date_format = check_date_format(date);
if (date_format == "DSN")//WTW - Gen2 - create new function to calculate
	//return YearFromDayNumber(atof(date));
	return year_from_day_number(atoi(date));

// date_format != "DSN"
// find where yr information start and ends
int yr_start_idx = 0;
int yr_end_idx = 0;
if (date_format == "USLIB")
	{
	yr_start_idx = 0; // yr information will always start at the beginning
	yr_end_idx = date.find_first_of("/");
	}
else // date_format == "US" 
	{
	yr_start_idx = date.find_last_of("/") + 1;
	yr_end_idx = date.length();
	}
int yr = atoi(date.substr(yr_start_idx, yr_end_idx));
return yr;
}
//////////////////////////////////////////////////
static int day_from_day_number(int nSerialDate)//WTW - Gen2 - add new formula to replace unsupported DayFromDayNumber() function
{
// Excel/Lotus 123 have a bug with 29-02-1900. 1900 is not a
// leap year, but Excel/Lotus 123 think it is...
if (nSerialDate == 60)
    return 29;

else if (nSerialDate < 60)
	{
    // Because of the 29-02-1900 bug, any serial date 
    // under 60 is one off... Compensate.
    nSerialDate++;
	}

// Modified Julian to DMY calculation with an addition of 2415019
int l = nSerialDate + 68569 + 2415019;
int n = int(( 4 * l ) / 146097);

l = l - int(( 146097 * n + 3 ) / 4);

int i = int(( 4000 * ( l + 1 ) ) / 1461001);

l = l - int(( 1461 * i ) / 4) + 31;

int j = int(( 80 * l ) / 2447);
    
return l - int(( 2447 * j ) / 80);
}
/////////////////////////////////////////////////////
static int get_day_from_date(const xstring &date) 
{
xstring date_format = check_date_format(date);
if (date_format == "DSN")//WTW - Gen2 - create new function to calculate
	//return DayFromDayNumber(atof(date));
	return day_from_day_number(atoi(date));

// date_format != "DSN"
// find where day information starts and ends
int day_start_idx = 0;
int day_end_idx = 0;
if (date_format == "USLIB")
	{
	day_start_idx = date.find_last_of("/") + 1;
	day_end_idx = date.length(); // day always ends at the end
	if (day_start_idx == 5) // there is no day in the date, assume day is 1
		return 1;
	}
else // date_format == "US"
	{
	day_start_idx = date.find_first_of("/") + 1;
	day_end_idx = date.find_last_of("/");
	if (day_start_idx > day_end_idx) // there is no day in the date, assume day is 1
		return 1;
	}
int day = atoi(date.substr(day_start_idx, day_end_idx - day_start_idx));
// validate day entry
if (day < 1 || day > 31)
	throw FatalError("Date = " + xstring(date) + ". It is not formatted properly. Invalid day value (" + xstring(day) + ") in date.");
return day;
}
//////////////////////////////////////////////////
static int get_end_of_mth_day(int yr, int mth)
{
bool leap_yr = false;
int day = 31;

/*if ((mod(yr, 4) == 0 && mod(yr, 100) != 0)
	|| mod(yr, 400) == 0)
	leap_yr = true;	*/	

//WTW - Gen2 - use of RAFM specific function in START_HEADER
//20240429 ZL: Fixed the issue due to U.S. library Gen2 updates not handling leap year properly in rate->startup
if ((yr % 4 == 0 && yr % 100 != 0) 
	|| yr % 400 == 0)
	leap_yr = true;	

switch (mth)
	{
	case 2:
		if (leap_yr)
			day = 29;
		else
			day = 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day = 30;
		break;
	default:
		day = 31;
	}

return day;
}
//////////////////////////////////////////////////
static xstring add_mths_to_date(const xstring &date, int mths)
{
// Check for format
xstring date_format = check_date_format(date);

// get date information
int mth = get_mth_from_date(date);
int yr = get_yr_from_date(date);

int addition_to_mth = 0;
int addition_to_yr = 0;
if (mths == 0)
	{
	addition_to_mth = 0;
	addition_to_yr = 0;
	}
else
	{
	addition_to_mth = (mths % 12);
	addition_to_yr = floor((mth + mths - 1) / 12.0);
	}

int new_mth = 0;
if (mth + addition_to_mth <= 0)
	new_mth = mth + addition_to_mth + 12;
else if (mth + addition_to_mth <= 12)
	new_mth = mth + addition_to_mth;
else
	new_mth = mth + addition_to_mth - 12;

int new_yr = (yr + addition_to_yr);

int day_start_idx = 0;
int day_end_idx = 0;
int day = 0;
xstring new_date = "";

if (date_format == "DSN")
	{
	day = get_day_from_date(date);
	new_date = xstring(new_yr) + "/" + xstring(new_mth) + "/" + xstring(day);
	}
else if (date_format == "USLIB")
	{
	day_start_idx = date.find_last_of("/") + 1;
	if (day_start_idx == 5) // there is no day in the date, ignore
		new_date = xstring(new_yr) + "/" + xstring(new_mth);
	else
		{
		day = get_day_from_date(date);
		new_date = xstring(new_yr) + "/" + xstring(new_mth) + "/" + xstring(day);
		}
	}
else // date_format == "US"
	{
	day_start_idx = date.find_first_of("/") + 1;
	day_end_idx = date.find_last_of("/");
	if (day_start_idx > day_end_idx) // there is no day in the date, assume day is 1
		new_date = xstring(new_mth) + "/" + xstring(new_yr);
	else // DSN will always be here
		{
		day = get_day_from_date(date);
		new_date = xstring(new_mth) + "/" + xstring(day) + "/" + xstring(new_yr);
		}
	}
return new_date;
}
////////////////////////////////////
static int get_mth_from_adj_date(const xstring &date, int mths)
{
//Get month from a date, adjusted for mths
int mth = 0;
mth = get_mth_from_date(date);
mth = mth + mths;

if (mth <= 0)
	{
	if (mth <= -12)
		mth = mth % 12;

	mth += 12;
	}
else if (mth > 12)
	{
	mth = mth % 12;

	if (mth == 0)
		mth = 12;
	}

return mth;
}
////////////////////////////////////
static double convert_rate_basis(double orig_rate, double orig_rate_basis, double new_rate_basis)
{
double new_rate = 0.0;
if (orig_rate_basis > 0)
	{
	if (new_rate_basis > 0)
		new_rate
		= (pow_legacy(1.0 + orig_rate / orig_rate_basis,//WTW - Gen2 - use of undeclared identifier
			   orig_rate_basis / new_rate_basis) - 1.0)
		   * new_rate_basis;
	else if (new_rate_basis < 0)
		new_rate
		= pow_legacy(1.0 + orig_rate / orig_rate_basis,//WTW - Gen2 - use of undeclared identifier
orig_rate_basis / -new_rate_basis) - 1.0;
	}
else if (orig_rate_basis < 0)
	{
	if (new_rate_basis > 0)
		new_rate
		= (pow_legacy(1.0 + orig_rate,//WTW - Gen2 - use of undeclared identifier
			   - orig_rate_basis / new_rate_basis) - 1.0)
		   * new_rate_basis;
	else if (new_rate_basis < 0)
		new_rate
		= pow_legacy(1.0 + orig_rate, orig_rate_basis / new_rate_basis) - 1.0;//WTW - Gen2 - use of undeclared identifier
	}
return new_rate;
}
////////////////////////////////////
static double convert_decrem_rate_basis(double orig_rate, double orig_rate_basis, double new_rate_basis)
{
double new_rate = 0.0;
if (orig_rate_basis > 0)
	{
	if (new_rate_basis > 0)
		new_rate
		= (1.0 - pow_legacy(1.0 - orig_rate / orig_rate_basis,//WTW - Gen2 - use of undeclared identifier
			   orig_rate_basis / new_rate_basis))
		   * new_rate_basis;
	else if (new_rate_basis < 0)
		new_rate
		= 1.0 - pow_legacy(1.0 - orig_rate / orig_rate_basis,//WTW - Gen2 - use of undeclared identifier
orig_rate_basis / -new_rate_basis);
	}
else if (orig_rate_basis < 0)
	{
	if (new_rate_basis > 0)
		new_rate
		= (1.0 - pow_legacy(1.0 - orig_rate,//WTW - Gen2 - use of undeclared identifier
			   - orig_rate_basis / new_rate_basis))
		   * new_rate_basis;
	else if (new_rate_basis < 0)
		new_rate
		= 1.0 - pow_legacy(1.0 - orig_rate, orig_rate_basis / new_rate_basis);//WTW - Gen2 - use of undeclared identifier
	}
return new_rate;
}
static long int determine_tbl_size(int sNumberOfDims, ...)
{
//#define DIMT_MAX_DIMS 10
static constexpr int DIMT_MAX_DIMS = 10;//WTW - Gen2 - replace #define preprocessor statement
if (sNumberOfDims > DIMT_MAX_DIMS)
	throw FatalError("Multidimensional table too large. Cannot continue.");
int psIndecies[DIMT_MAX_DIMS] = {0};
int psMaxs[DIMT_MAX_DIMS] = {0};
int sLoop = 0;
long int sRetval = 0;
int sFactor = 1;
va_list vlArg_Ptr;
va_start(vlArg_Ptr, sNumberOfDims); // get first argument
for (sLoop = 0; sLoop < sNumberOfDims; sLoop++)
	psIndecies[sLoop] = va_arg(vlArg_Ptr, int); // get indexes
for (sLoop = 0; sLoop < sNumberOfDims ; sLoop++)
	psMaxs[sLoop]=va_arg(vlArg_Ptr, int); // get indexes
// loop backwards, for efficiency purposes, and to make the
// right-most index the "lowest" one.
for (sLoop = sNumberOfDims - 1; sLoop >= 0; sLoop--)
	{
	sRetval += (psIndecies[sLoop] - 1) * sFactor;
	if (sLoop > 0) // sFactor not needed last time through the loop
		sFactor *= psMaxs[sLoop];
	}
va_end(vlArg_Ptr);
return sRetval;
}
////////////////////////////////////
static xstring get_file_name(const xstring &source_file)
{
xstring id = source_file;
int path_end = id.find_last_of("\\");
if (path_end < 0)
	throw FatalError("Unrecognized File name '" + id + "'.");
xstring name = id(path_end + 1);
int name_end = name.find(".");
if (name_end == 0)
	throw FatalError("'.' cannot be the first character of the file name '" + id + "'.");
if (name_end > 0)
	return name(0, name_end);
return name;
}
///////////////////////////////////////////////////
static xstring get_file_path(const xstring &source_file)
{
xstring id = source_file;
int path_end = id.find_last_of("\\") + 1;
if (path_end > 0)
	return id(0, path_end);
throw FatalError("Unrecognized Data File name '" + id + "'.");
}
////////////////////////////////////////////////////////
static xstring get_base_group_name(const xstring &tag, bool seriatim_flag)
{
// must strip "ProjTaskLoop ### " from group because RAFM prepends this to user's group tag
xstring xxx = tag.strip();

int pos = 0;
if (xxx(0, 2) == "0 ")
	return xxx(2);
if (xxx(0, 13) == "ProjTaskLoop ")
	{
	xxx = xxx(13);
	if (pricing_flag || seriatim_flag)
		pos = xxx.find("|");  // RAFM uses ProjTaskLoop XXX|Group when product is top model
	else
		pos = xxx.find(" ");
	if (pos > 0)
		xxx = xxx(pos + 1);
	else
		xxx = tag;
	}
else if ((pos = xxx.find(" #")) > 0)
	xxx = xxx(0, pos);
return xxx;
}
////////////////////////////////////////////////////////
static xstring get_string_of_date(double date)
{
return xstring(get_yr_from_date(xstring(date)))
	   + "/" 
	   + xstring(get_mth_from_date(xstring(date)))
	   + "/" 
	   + xstring(get_day_from_date(xstring(date)));
}
////////////////////////////////////////////////////////
static xstring get_string_of_enum_val(int type)
{
xstring type_string = "";

switch (type)
	{
	#if defined(__ASSET_ASSET_H_)
	case BOND: type_string = "Bond"; break;
	case MORTGAGE: type_string = "Mortgage"; break;
	case SECURITIZED_ASSET: type_string = "Securitized Asset"; break;
	case INTEREST_RATE_DERIVATIVE: type_string = "Interest Rate Derivative"; break;
	case REAL_ESTATE: type_string = "Real Estate"; break;
	case EQUITY: type_string = "Equity"; break;
	case INDEX_OPTION: type_string = "Index Option"; break;

	case BOOK: type_string = "Book"; break;
	case CASH: type_string = "Cash"; break;

	case NO: type_string = "No"; break;
	case YES: type_string = "Yes"; break;

	#if defined(__BOND_ASSET_H_)
	case HEDGING: type_string = "Hedging"; break;
	case INVESTMENT: type_string = "Investment"; break;
	case COLLATERAL_POOL: type_string = "Collateral Pool"; break;

	case AMERICAN: type_string = "American"; break;
	case EUROPEAN: type_string = "European"; break;

	case ANNUAL: type_string = "Annual"; break;
	case MONTHLY: type_string = "Monthly"; break;
	case QUARTERLY: type_string = "Quarterly"; break;
	case SEMI_ANNUAL: type_string = "Semi-Annual"; break;

	case CALL: type_string = "Call"; break;
	case CASH_FLOW_MAINTENANCE: type_string = "Cash Flow Maintenance"; break;
	case YIELD_MAINTENANCE: type_string = "Yield Maintenance"; break;

	case FIXED_RATE: type_string = "Fixed Rate"; break;
	case FLOATING_RATE: type_string = "Floating Rate"; break;

	case NOT_APPLICABLE: type_string = "Not Applicable"; break;
	case NOT_ASSIGNED: type_string = "Not Assigned"; break;
	case HELD_TO_MATURITY: type_string = "Held to Maturity"; break;
	case AVAILABLE_FOR_SALE: type_string = "Available for Sale"; break;
	case TRADING: type_string = "Trading"; break;

	case PRICE_SCHEDULE: type_string = "Price Schedule"; break;
	#endif

	#if defined(__MTG_ASSET_H_)
	case PENALTY_PERCENT: type_string = "Penalty Percent"; break;
	case YES_PER_SCHEDULE: type_string = "Yes Per Schedule"; break;
	#endif

	#if defined(__SEC_ASSET_H_)
	case ACCRUAL_ONLY: type_string = "Accrual Only"; break;
	case AFTER_PAC2: type_string = "After PAC2"; break;
	case BEFORE_PAC2: type_string = "Before PAC2"; break;
	case BOTH: type_string = "Both"; break;
	case IO: type_string = "IO"; break;
	case JUMP: type_string = "Jump"; break;
	case JUMP_STICK: type_string = "Jump/Stick"; break;
	case NON_ACCRUAL: type_string = "Non Accrual"; break;
	case PAC2A: type_string = "PAC2A"; break;
	case PO: type_string = "PO"; break;
	case TRANCHE_A: type_string = "Tranche A"; break;
	case TRANCHE_B: type_string = "Tranche B"; break;
	case TRANCHE_C: type_string = "Tranche C"; break;
	case TRANCHE_Z: type_string = "Tranche Z"; break;
	case Z_PAC: type_string = "Z PAC"; break;
	#endif

	#if defined(__IRD_ASSET_H_)
	case ALWAYS: type_string = "Always"; break;
	case IF_POSITIVE: type_string = "If Positive"; break;
	#endif

	#if defined(__EIO_ASSET_H_)
	case PUT: type_string = "Put"; break;
	case FUTURES: type_string = "Futures"; break;

	case NONE: type_string = "None"; break;
	case ASIAN: type_string = "Asian"; break;
	case HIGHEST_GAIN: type_string = "Highest Gain"; break;

	case SEMIANNUAL: type_string = "Semiannual"; break;
	#endif

	#if defined(__EPA_ASSET_H_)
	case SCHEDULE_FILE: type_string = "Schedule File"; break;
	case TAS_EPA_FILE: type_string = "TAS EPA File"; break;
	#endif

	#endif

	default: type_string = "Unknown";
	}

return type_string;
}
////////////////////////////////////////////////////////
static int date_diff(xstring first_date, xstring second_date)
{
// Return difference in mths between first and second date
int first_yr = get_yr_from_date(first_date);
int second_yr = get_yr_from_date(second_date);
int first_mth = get_mth_from_date(first_date);
int second_mth = get_mth_from_date(second_date);

return (first_yr - second_yr) * 12 + first_mth - second_mth;
}
////////////////////////////////////////////////////////
//WTW - Gen2 - New external formula instead of preprocessing statement where #define is not allowed
static int number_of_decimals(double xxx, int digits) 
{
return (fabs(xxx) < 0.000000001 ? (digits - 1) : (max(2, min((digits - 1), (int)((digits) - log10(fabs(xxx)))))));
}
////////////////////////////////////////////////////////
static xstring write_string(double value, int string_length, int significant_digits)
{
// save value to at least 'significant_digits' significant digits.
//#define NUMBER_OF_DECIMALS(xxx,digits) (fabs(xxx) < 0.000000001 ? (digits - 1) : (max(2, min((digits - 1), (int)((digits) - log10(fabs(xxx)))))))
//int decimals = NUMBER_OF_DECIMALS(value, significant_digits);
int decimals = number_of_decimals(value, significant_digits);//WTW - Gen2 - replace preprocessor w formula
xstring string_value = "";
ostringstream message;
message.setf(ios::fixed);
message << setprecision(decimals) << value;
string_value = message.str();
if (string_value.length() <= string_length)
	return string_value;
// else output in scientific notation
if (string_length > 10)
	{
	ostringstream message2;
	message2.setf(ios_base::scientific, ios_base::floatfield);
	message2 << setprecision(string_length - 7) << value;
	string_value = message2.str();
	return string_value;
	}
// else output asterisks
ostringstream message2;
message2 << setw(string_length) << setfill('*') << "";
string_value = message2.str();
return string_value;
}
//////////////////////////////////////////////////////////////
// write_array_to_string - This functions takes an array and writes it to a string.
//static xstring write_array_to_string(SmartArray <double> value_array, int low, int high)
static xstring write_array_to_string(std::vector <double> value_array, int low, int high)//WTW - Gen2 - use of RAFM specific data type in START_HEADER
{
xstring temp_string = "";
int j = 0;
for (j=low; j <= high ; j++)
{
	temp_string += xstring(value_array[j]) + "|";
}
return temp_string;
}
////////////////////////////////////////////////////////////
//static void read_from_string(xstring temp_string, SmartArray <double> &temp_array)
static void read_from_string(xstring temp_string, std::vector <double> &temp_array) //WTW - Gen2 - use of RAFM specific data type in START_HEADER
{
int j = 0;
double new_entry = 0.0;
char* copyString = new char[ temp_string.length() + 1 ];
strcpy( copyString, temp_string.c_str() );				
char* fragment = strtok(copyString, "|");
while (fragment)
	{
	new_entry = atof(fragment);
	temp_array.push_back(new_entry);
	fragment = strtok(NULL, "|");
	}
}
/////////////////////////////////////
static void split_string_usl(const string& str, vector<string>& tokens, const string& delimiters)//WTW - Gen2 - split_tring internal RAFM function
{
// Skip delimiters at beginning.
string::size_type lastPos = str.find_first_not_of(delimiters, 0);
// Find first "non-delimiter".
string::size_type pos = str.find_first_of(delimiters, lastPos);
while (string::npos != pos || string::npos != lastPos)
	{
	// Found a token, trim and add it to the vector.
	string new_string = str.substr(lastPos, pos - lastPos);
	
	string::size_type startpos = new_string.find_first_not_of(" \t");
	string::size_type endpos = new_string.find_last_not_of(" \t");
	// if all spaces or empty return an empty string
	if((string::npos == startpos ) || ( string::npos == endpos))
		new_string = "";
	else
		{
		new_string = new_string.substr(startpos, endpos - startpos + 1);
		tokens.push_back(new_string);
		}	
	// Skip delimiters.  Note the "not_of"
	lastPos = str.find_first_not_of(delimiters, pos);
	// Find next "non-delimiter"
	pos = str.find_first_of(delimiters, lastPos);
	}
}
static void split_string_usl(const string& str, vector<string>& tokens, const string& delimiters, const string& dash)//WTW - Gen2 - split_tring internal RAFM function
{
//Perform comma search first and if dash is within commas add integers within range

// Skip delimiters at beginning.
string::size_type lastPos = str.find_first_not_of(delimiters, 0);
// Find first "non-delimiter".
string::size_type pos = str.find_first_of(delimiters, lastPos);
if (string::npos != pos || string::npos != lastPos)//If comma has been located
	{
	while (string::npos != pos || string::npos != lastPos)
		{
		// Found a token, trim and add it to the vector.
		string new_string = str.substr(lastPos, pos - lastPos);
	
		string::size_type startpos = new_string.find_first_not_of(" \t");
		string::size_type endpos = new_string.find_last_not_of(" \t");
		// if all spaces or empty return an empty string
		if((string::npos == startpos ) || ( string::npos == endpos))
			new_string = "";
		else
			{
			new_string = new_string.substr(startpos, endpos - startpos + 1);
		
			string::size_type found = new_string.find(dash);
		
			if (found != string::npos)//if dash is found, add values within range
				{
				xstring start = new_string.substr(0,found);
				xstring end = new_string.substr(found+1, new_string.size()-found-1);
				int start_range = atoi(start);
				int end_range = atoi(end);

				std::string push_value;

				for (int i = start_range; i <= end_range; i++)
					{
					push_value = std::to_string(i);
					tokens.push_back(push_value);
					}
				}
			else//otherwise add single value
				tokens.push_back(new_string);
			}	
		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);
		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
		}
	}
else//No comma has been located
	{
	string::size_type found = str.find(dash);
		
	if (found != string::npos)//if dash is found, add values within range
		{
		xstring start = str.substr(0,found);
		xstring end = str.substr(found+1, str.size()-found-1);
		int start_range = atoi(start);
		int end_range = atoi(end);

		std::string push_value;

		for (int i = start_range; i <= end_range; i++)
			{
			push_value = std::to_string(i);
			tokens.push_back(push_value);
			}
		}	
	}
}

/////////////////////////////////////////////////
static void query_run_time(const xstring &caller, const xstring &file_name)
{
static LARGE_INTEGER QRTFreq;
static LARGE_INTEGER QRTStartTime;
static LARGE_INTEGER QRTRestartTime;
static LARGE_INTEGER QRTEndTime;
static ofstream& QRTFile = * new ofstream;
static bool first = true;
if (first)
	{
	first = false;
	xstring query_run_time_file_name
	= get_file_path(file_name) + get_file_name(file_name) + "~QueryRunTime.TXT";
	QRTFile.open(query_run_time_file_name);
	QueryPerformanceFrequency((LARGE_INTEGER *)&QRTFreq);
	QRTFile.setf(ios::fixed, ios::floatfield);
	QRTFile << "Query Run Time output for " << get_file_name(file_name)
			<< endl;
	QRTFile << "QRTime: -Increment ---Total-- - " << caller
			<< " Frequency: " << (float)(QRTFreq.QuadPart)
			<< endl;
	QueryPerformanceCounter((LARGE_INTEGER *)&QRTRestartTime);
	QRTStartTime = QRTRestartTime;
	return;
	}
QueryPerformanceCounter((LARGE_INTEGER *)&QRTEndTime);
QRTFile << "QRTime: " << setw(10) << setprecision(6)
		<< ((float)(QRTEndTime.QuadPart - QRTRestartTime.QuadPart)) / QRTFreq.QuadPart
		<< " " << setw(10) << setprecision(6)
		<< ((float)(QRTEndTime.QuadPart - QRTStartTime.QuadPart)) / QRTFreq.QuadPart
		<< " " << caller
		<< endl;
QueryPerformanceCounter((LARGE_INTEGER *)&QRTRestartTime);
return;
}
/////////////////////////////////////////////////////
// financial functions
static double annual_yld(double monthly_numerator, double monthly_denominator, int return_frequency)
{
if (fabs(monthly_denominator) < 1.0e-02)
	return 0;
if (monthly_numerator == 0)
	return 0;
if (monthly_numerator > 0)
	{
	if (monthly_denominator > 0)
		{
		if (monthly_numerator / MAXIMUM_MONTHLY_YIELD_RATIO > monthly_denominator)
			return (pow_legacy(1.0 + (MAXIMUM_MONTHLY_YIELD_RATIO),12.0 / return_frequency) - 1.0)//WTW - Gen2 - use of undeclared identifier
				   * return_frequency;
		}
	else // monthly_denominator < 0
		{
		if (monthly_numerator > MINIMUM_MONTHLY_YIELD_RATIO * monthly_denominator)
			return 0;
		}
	}
else // monthly_numerator < 0
	{
	if (monthly_denominator < 0)
		{
		if (monthly_numerator / MAXIMUM_MONTHLY_YIELD_RATIO < monthly_denominator)
			return (pow_legacy(1.0 + (MAXIMUM_MONTHLY_YIELD_RATIO),12.0 / return_frequency) - 1.0)//WTW - Gen2 - use of undeclared identifier
				   * return_frequency;
		}
	else // monthly_denominator > 0
		{
		if (monthly_numerator < MINIMUM_MONTHLY_YIELD_RATIO * monthly_denominator)
			return 0;
		}
	}
return (pow_legacy(1.0 + (monthly_numerator / monthly_denominator),12.0 / return_frequency) - 1.0)//WTW - Gen2 - use of undeclared identifier
	   * return_frequency;
}
// V to the n
static double vtothen(double rate_per_period, int num_periods)
{
return pow_legacy((1.0 / (1.0 + rate_per_period)), (double) num_periods);//WTW - Gen2 - use of undeclared identifier
}
// a angle n
static double a_angle_n(double rate_per_period, int num_periods)
{
double temp_a_angle_n;
if (rate_per_period > 0.0)
	temp_a_angle_n = (1.0 - vtothen(rate_per_period, num_periods))
/ rate_per_period;
else
	temp_a_angle_n = (double) num_periods;
return temp_a_angle_n;
}
// Cumulative Normal Distribution
static double cumul_normal_distribn(double x)
{
//Comments:  This approximation for the cummualtive normal distribution is taken
//from formula 26.2.17, page 932, of the "Handbook of Mathematical Function",
//National Bureau of Standards, Applied Mathematics Series 55, U.S.  Government
//Printing Office, Washington, D.C., 1964.  This approximation is accurate to 7
//decimal places.
//This routine calculates the cummulative normal distribution, N(x), as follows:
//For x >= 0
//N(x) = 1 - exp( -(x^2)/2 ) * (a*t + b*t^2 + c*t^3 + d*t^4 + e*t^5) / 2.5066
//28274 63100
//where  t = 1 / (1 + p*x)
//p =  0.23164 19
//a =  0.31938 1530
//b = -0.35656 3782
//c =  1.78147 7937
//d = -1.82125 5978
//e =  1.33027 4429
//For x < 0
//N(x) = 1 - N(-x)

double p =  0.2316419;
double a =  0.319381530;
double b = -0.356563782;
double c =  1.781477937;
double d = -1.821255978;
double e =  1.330274429;
double t = 1.0 / (1.0 + p * fabs(x));
if (x >= 0)
	{
	if (((x * x) / 2.0) < 225)
		return 1.0 - exp(-(x * x) / 2)
				* (a * t + b * pow_legacy(t,2) + c * pow_legacy(t,3) + d * pow_legacy(t,4) + e * pow_legacy(t,5))
				/ 2.50662827463100;//WTW - Gen2 - use of undeclared identifier
	return 1.0;
	}
else
	{
	if (((x * x) / 2.0) < 225)
		return exp(-(x * x) / 2)
				* (a * t + b * pow_legacy(t,2) + c * pow_legacy(t,3) + d * pow_legacy(t,4) + e * pow_legacy(t,5))
				/ 2.50662827463100;//WTW - Gen2 - use of undeclared identifier
	}
return 0.0;
}
// Cumulative Bivariate Normal Distribution
static double cumul_bivariate_normal_distribn(double x, double y, double rho)
{
// This approximation for the cumulative bivariate normal distributions is
// described in appendix A, page 191, of Espen Haug's book titled "The
// Complete Guide To Option Pricing Formulas".
int i = 0;
int j = 0;
double x1 = 0.0;
double y1 = 0.0;
double rho1 = 0.0;
double rho2 = 0.0;
double delta = 0.0;
double pi = 0.0;
double signx = 0.0;
double signy = 0.0;
double cumulative_bivariate_normal_val = 0.0;
static double xx[5] = { 0.24840615, 0.39233107, 0.21141819, 0.03324666, 0.00082485334 };
static double yy[5] = { 0.10024215, 0.48281397, 1.0609498, 1.7797294, 2.6697604 };
x1 = x / pow_legacy((2 * (1 - pow_legacy(rho, 2))), 0.5);//WTW - Gen2 - use of undeclared identifier
y1 = y / pow_legacy((2 * (1 - pow_legacy(rho, 2))), 0.5);//WTW - Gen2 - use of undeclared identifier
pi = 3.14159265358979;
if (x < 0.0)
	signx = -1.0;
else if (x > 0.0)
	signx = 1.0;
else
	signx = 0.0;
if (y < 0.0)
	signy = -1.0;
else if (y > 0.0)
	signy = 1.0;
else
	signy = 0.0;
if (x <= 0 && y <= 0 && rho <= 0)
{
	double sum = 0.0;
	for (i = 0; i < 5; i++)
		{
		for (j = 0; j < 5; j = j + 1)
			{
			sum
			= sum
			  + xx[i] * xx[j]
			  * exp(x1 * (2 * yy[i] - x1)
					+ y1 * (2 * yy[j] - y1)
					+ 2 * rho * (yy[i] - x1) * (yy[j] - y1));
			}
		}
	cumulative_bivariate_normal_val = pow_legacy((1 - pow_legacy(rho, 2)), 0.5) / pi * sum;//WTW - Gen2 - use of undeclared identifier
	}
else
	{
	if (x <= 0 && y >= 0 && rho >= 0)
		cumulative_bivariate_normal_val
		= cumul_normal_distribn(x)
		  - cumul_bivariate_normal_distribn(x, -y, -rho);
	else
		{
		if (x >= 0 && y <= 0 && rho >= 0)
			cumulative_bivariate_normal_val
			= cumul_normal_distribn(y)
			  - cumul_bivariate_normal_distribn(-x, y, -rho);
		else
			{
			if (x >= 0 && y >= 0 && rho <= 0)
				cumulative_bivariate_normal_val
				= cumul_normal_distribn(x)
				  + cumul_normal_distribn(y) - 1
				  + cumul_bivariate_normal_distribn(-x, -y, rho);
			else
				{
				if (x * y * rho > 0)
					{
					rho1 = (rho * x - y) * signx
						   / pow_legacy((pow_legacy(x, 2) - 2 * rho * x * y + pow_legacy(y, 2)), 0.5);//WTW - Gen2 - use of undeclared identifier
					rho2 = (rho * y - x) * signy
						   / pow_legacy((pow_legacy(x, 2) - 2 * rho * x * y + pow_legacy(y, 2)), 0.5);//WTW - Gen2 - use of undeclared identifier
					delta = (1 - signx * signy) / 4.0;
					cumulative_bivariate_normal_val
					= cumul_bivariate_normal_distribn(x, 0, rho1)
					  + cumul_bivariate_normal_distribn(y, 0, rho2)
					  - delta;
					}
				}
			}
		}
	}
return cumulative_bivariate_normal_val;
}
// cte calc
//static void cte_calc(SmartArray <SmartArray <double>> value_array, double cte_percentage, double &cte_amt, double &tax_avg_ratio)
static void cte_calc(std::vector <std::vector <double>> value_array, double cte_percentage, double &cte_amt, double &tax_avg_ratio)//WTW - Gen2 - use of RAFM specific data type in START_HEADER
{
int i = 0;
int j = 0;
int cte_index = 0;
double scen_amt_sum = 0.0;
double tax_avg_ratio_amt_sum = 0.0;
double scen_amt_temp_element = 0.0;
double tax_avg_ratio_temp_element = 0.0;
if (value_array[0].size() != value_array[1].size())
	{
	//WTW - Gen2 - log_screen not supported in Externs
	//log_screen.setf(ios::fixed, ios::floatfield);
	//log_screen << "Warning. The number of arrays for the scenario amount does not equal the number of arrays for the tax average ratio array."
	//			<< MSG_ERROR;
	}
if (value_array[0].size() == 0)
	{
	cte_amt = 0.0;
	tax_avg_ratio = 0.0;
	return;
	}
// first sort the array highest to lowest
for(i = 1; i < value_array[0].size(); i++)
	{
	for (j = i; j > 0; j--)
		{
	if (value_array[0][j] > value_array[0][j-1])
			{
			scen_amt_temp_element = value_array[0][j - 1]; // SCEN_AMT
			tax_avg_ratio_temp_element = value_array[1][j - 1]; // TAX_AVG_RATIO
			value_array[0][j - 1] = value_array[0][j];
			value_array[1][j - 1] = value_array[1][j];
			value_array[0][j] = scen_amt_temp_element;
			value_array[1][j] = tax_avg_ratio_temp_element;
			}
		}
	}
cte_index
= value_array[0].size() - ceil(cte_percentage * value_array[0].size());
if (cte_index == 0)
	{
	cte_amt = 0.0;
	tax_avg_ratio = 0.0;
	return;
	}
if (value_array[0].size() == 1 || cte_index == 1)
	{
	cte_amt = value_array[0][0];
	tax_avg_ratio = value_array[1][0];
	return;
	}
for (i = 0; i < cte_index; i++)
	{
	scen_amt_sum += value_array[0][i];
	tax_avg_ratio_amt_sum += value_array[1][i];
	}
cte_amt = scen_amt_sum / cte_index;
tax_avg_ratio = tax_avg_ratio_amt_sum / cte_index;
return;
}
// Black Scholes Highest Gain Frequency Multiple
static double bs_highest_gain_freq_mult(double length_of_sampling_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
int tn = 0;
double ta = 0.0;
double freq = 0.0;
double tee = 0.0;
double r = 0.0;
double d = 0.0;
double v = 0.0;
double b = 0.0;
double tm = 0.0;
double h = 0.0;
double b1 = 0.0;
double b2 = 0.0;
double v2 = 0.0;
double tsqrt = 0.0;
double sqrt2pi = 0.0;
double mu = 0.0;
double mutsqrt = 0.0;
double delta = 0.0;
double gamma = 0.0;
double alpha = 0.0;
double lambda = 0.0;
double highest_gain_freq_factor = 0.0;
// length_of_sampling_period (ta)
// sampling_freq             (freq)
//          =    0  for continuous
//             256  for daily
//              52  for weekly
//              12  for monthly
//               4  for quarterly
//               2  for semiannual
//               1  for annual
//  yrs_to_expiry            (tee)
//  risk_free_rate           (r)
//  init_div_yld             (b)
//  index_vol                (v)
//
ta = length_of_sampling_period;
freq = sampling_freq;
tee = yrs_to_expiry;
d = log(1.0 + init_div_yld / scen_index_freq)
* scen_index_freq;
r = log(1.0 + risk_free_rate / scen_int_freq)
* scen_int_freq;
v = index_vol;
b = r - d; // cost of carry
if (fabs(b) < 0.000001)
{
b = 0.0000001;
// Temporary until we calculate the limit of M2
// as b approaches zero.
}
if (fabs(freq) < 0.000001)
highest_gain_freq_factor = 1.0;
else
{   // Discrete sampling.
tm = min(tee, ta);
h = 1.0 / freq;
tn = ((int) (ta * freq)) + 1;
b1 = 0.5826;
b2 = 0.425;
v2 = v * v;
tsqrt = pow_legacy(tm, 0.5);//WTW - Gen2 - use of undeclared identifier
sqrt2pi = 2.50662827463100; // square root of 2  * Pi
mu = r - v2 / 2;
mutsqrt = mu * tsqrt;
delta = mutsqrt * (cumul_normal_distribn(mutsqrt / v) - 0.5);
gamma = (v * exp(-mutsqrt * mutsqrt * 0.5 / v2) / sqrt2pi + delta) * 0.5;
alpha = (gamma * tsqrt + b2 * v2 * tm * 0.5) / tn;
volatile double exparg = b1 * v * (pow_legacy(h, 0.5));//WTW - Gen2 - use of undeclared identifier
lambda = exp(exparg) / exp(alpha);
highest_gain_freq_factor = lambda;
}
return highest_gain_freq_factor;
}
// Black Scholes Option Value
static double bs_opt_val(double strike_price, double yrs_to_expiry, double underlying_price, double vol, double risk_free_rate, double payout_rate, int call_or_put, int formula_code)
{
// call_or_put - CALL_CODE  for Call
//               PUT_CODE   for Put
//
// formula_code - CONTINUOUS_PAYOUT_CODE  for Continuous Payout (Merton's modification)
//                FUTURES_CODE            for Futures           (Black's modification)//
//
// Comments:  This approximation was taken from Table 3-6 ("European Option
// Valuation Formulas") on pages 117-118 of "Financial Options" by Figlewski,
// et. al., Business One Erwin, Homewood, Illinois.
//
// The major assumptions of the Black-Scholes option XModel are:  i) the
// asset price follows a geometric Brownian motion with constant variance
// v^2, ii) the asset returns follow a lognormal distribution, iii) there
// are no transaction costs or taxes, iv) securities are infinitely
// divisible and may be traded at all times, and v) there are no
// restrictions on short selling.  Under these assumptions the European
// option prices on an asset with discrete cash payouts are
//
//   Call Price =  S * N[ d1] * exp( -q * T ) - X * N[ d2] * exp( -r * T )
//   Put Price  = -S * N[-d1] * exp( -q * T ) + X * N[-d2] * exp( -r * T )
//
// where S = price of underlying asset minus present value of all cash paid
//           out prior to expiration
//           (For a bond the price of the bond and the present value of the
//            cash paid out is based on the Treasury spot curve plus a credit
//            spread and is calculated under the assumption that the bond is
//            neither callable nor putable.)
//        X     = option exercise price
//                 (For a bond this is the call or put amount plus accurued
//                  interest at time T.)
//        T     = time to option expiry
//        r     = riskless continuously conpounded yield to option expiry
//        q     = continuously conpounded payout rate
//        v     = annual price volatility
//        d1    = [ ln( S/X ) + ( r - q + (v^2) / 2 ) * T ] / [ v * ( T^.5 ) ]
//        d2    = d1 - [ v * ( T^.5 ) ]
//        N[.]  = cumulative normal distribution function
double d1 = 0;
double d2 = 0;
double opt_price = 0;
double continuous_risk_free_rate = 0;
double continuous_payout_rate = 0;
double d1_divisor = 0;
if (formula_code == CONTINUOUS_PAYOUT_CODE)
	{
	if (strike_price == 0.0)
		{
		if (call_or_put == CALL_CODE)
			opt_price
			= underlying_price * (1 / pow_legacy(1 + payout_rate, yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		else
			opt_price = 0.0;
		}
	else
		{
		continuous_risk_free_rate = 2.0 * log(1.0 + risk_free_rate / 2.0);
		continuous_payout_rate = log(1.0 + payout_rate);
		d1_divisor = vol * pow_legacy(yrs_to_expiry, .5);//WTW - Gen2 - use of undeclared identifier
		if (fabs(d1_divisor) <  1.0e-10)//WTW - Gen2 - avoid divide by 0
			d1 = 0.0;
		else
			d1 = (log(underlying_price / strike_price)
				  + (continuous_risk_free_rate - continuous_payout_rate
				  + (vol * vol) / 2.0)
					* yrs_to_expiry) / d1_divisor;
		d2 = d1 - d1_divisor;
		if (call_or_put == CALL_CODE)
			opt_price
			= underlying_price
			  * cumul_normal_distribn(d1)
			  * (1 / pow_legacy(1 + payout_rate, yrs_to_expiry))//WTW - Gen2 - use of undeclared identifier
			  - strike_price
			    * cumul_normal_distribn(d2)
			    * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		if (call_or_put == PUT_CODE)
			opt_price
			= -underlying_price
			   * cumul_normal_distribn(-d1)
			   * (1 / pow_legacy(1 + payout_rate, yrs_to_expiry))//WTW - Gen2 - use of undeclared identifier
			   + strike_price
			     * cumul_normal_distribn(-d2)
			     * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		}
	}
if (formula_code == FUTURES_CODE)
	{
	if (strike_price == 0.0)
		{
		if (call_or_put == CALL_CODE)
			opt_price
			= underlying_price
			  * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		else
			opt_price = 0.0;
		}
	else
		{
		d1_divisor = vol * pow_legacy(yrs_to_expiry, .5);//WTW - Gen2 - use of undeclared identifier
		if (fabs(d1_divisor) < 1.0e-10)//WTW - Gen2 - avoid divide by 0
			d1 = 0.0;
		else
			d1 = (log(underlying_price / strike_price)
				  + ((vol * vol) / 2.0) * yrs_to_expiry)
				  / d1_divisor;
		d2 = d1 - d1_divisor;
		if (call_or_put == CALL_CODE)
			opt_price
			= (underlying_price
			   * cumul_normal_distribn(d1)
			   - strike_price
			     * cumul_normal_distribn(d2))
			   * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		if (call_or_put == PUT_CODE)
			opt_price
			= (-underlying_price
			   * cumul_normal_distribn(-d1)
			   + strike_price
				 * cumul_normal_distribn(-d2))
			   * (1 / pow_legacy(1 + risk_free_rate / 2.0, 2 * yrs_to_expiry));//WTW - Gen2 - use of undeclared identifier
		}
	}
return opt_price;
}
// Black Scholes Option Value Asian
static double bs_opt_val_asian(int call_or_put, double current_price, double observed_average_price, double strike_price, double length_of_averaging_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
int freq = 0;
int tn = 0;
int pn = 0;
int fn = 0;
double s = 0.0;
double savg = 0.0;
double x = 0.0;
double ta = 0.0;
double tee = 0.0;
double r = 0.0;
double d = 0.0;
double v = 0.0;
double b = 0.0;
double fr = 0.0;
double pr = 0.0;
double tr = 0.0;
double m1 = 0.0;
double b2v = 0.0;
double m2 = 0.0;
double h = 0.0;
double bv = 0.0;
double f1 = 0.0;
double f2 = 0.0;
double f3 = 0.0;
double f4 = 0.0;
double f5 = 0.0;
double b1 = 0.0;
double b2 = 0.0;
double b3 = 0.0;
double b4 = 0.0;
double var = 0.0;
double vavg = 0.0;
double xp = 0.0;
double d1 = 0.0;
double d2 = 0.0;
double callprice = 0.0;
double asian_opt_val = 0.0;
// call_or_put - CALL_CODE  for Call
//               PUT_CODE   for Put
// current_price                    (s)
// observed_average_price           (savg)
// strike_price                     (x)
// length_of_averaging_period       (ta)
// sampling_freq                    (freq)
//          =    0  for continuous
//             256  for daily
//              52  for weekly
//              12  for monthly
//               4  for quarterly
//               2  for semiannual
//               1  for annual
// yrs_to_expiry                    (t)
// risk_free_rate                   (r)
// init_div_yld                     (d)
// index_vol                        (v)
//
// Description.  This formula set assumes that the Asian values are based
//   on sample points at the beginnings and ends of sample months.  To
//   sample ends of months, execute this formula set with the length of the
//   averaging period reduced by one sample period.  The reduction does not
//   apply to continuous sampling.
// This is a modification by Phelim Boyle of the approximation
// that appears on in Levy's paper on "Pricing European average
// rate currency options", Journal of International Money and
// Finance (1992), 11, 474-491.
//
// The Phelim's modification consists of eliminating the formulas
// for the case where we are within the averaging period by
// using the formulas for the case before we enter the averaging
// period to value a similar option on an average over the
// future averaging points.  This modifications greatly
// simplifies the calculations without any loss of accuracy.
//
// Phelim also considers the case where the option pays with
// certainty.
//
// If b is zero, b is reset to 0.00001 because we have not been
// able to determine the limit of the second moment (M2) of the
// average distribution as b tends toward zero.
// Initialize variables.
s = current_price;
savg = observed_average_price;
x = strike_price;
ta = length_of_averaging_period;
freq = sampling_freq;
tee = yrs_to_expiry;
r = log(1.0 + risk_free_rate / scen_int_freq)
* scen_int_freq;
d = log(1.0 + init_div_yld / scen_index_freq)
* scen_index_freq;
v = index_vol;
// Calculate first and second moments of average distribution
// and fractional parts of sampling period.
//
//   |<----------Ta-------------------------------------->|
//                       |<----------Fn*h---------------->|
//                           |<----------tee------------->|
//   |-------------------|---:--|-------------------------|
//   0                   m   t m+1                        N
//   0                   5      6                        10
//
// b     = cost of carry (= r - d)
// m1    = first moment of average distribution
// m2    = second moment of average distribution
// h     = time between sampling points         (discrete case only)
// fn    = number of future sampling points     (discrete case only)
// pn    = number of observed sampling points   (discrete case only)
// tn    = Total number of sampling points      (discrete case only)
// fr    = portion of average period remaining
// pr    = portion of average period already observed
// tr    = length of average period remaining
b = r - d; // cost of carry
if (b == 0)
	{
	b = 0.0001;
	// Temporary until we calculate the limit of M2
	// as b approaches zero.
	}
if (freq == 0)
	{   //Continuous sampling.
	if (tee > ta)
		fr = 1.0;
	else
		fr = tee / ta;
	pr = 1.0 - fr;
	tr = min(ta, tee);
	m1 = (s / tr) * exp(b * (tee - tr))
		 * (exp(b * tr) - 1.0) / b;
	b2v = 2.0 * b + v * v;
	m2 = 2.0 * (pow_legacy((s / tr), 2.0) / (b + v * v))//WTW - Gen2 - use of undeclared identifier
		 * exp(b2v * (tee - tr))
		 * ((exp(b2v * tr) - 1.0) / b2v - (exp(b * tr) - 1.0) / b);
	}
else
	{   // Discrete sampling.
	h = 1.0 / freq;
	tn = ((int) (freq * ta)) + 1;
	if (tee <= ta)
		pn = ((int) (freq * (ta - tee))) + 1;
	else
		pn = 0;
	fn = tn - pn;
	fr = fn / ((double) tn);
	pr = 1.0 - fr;
	// Calculate first moment.
	m1 = (s / fn) * exp(b * (tee - (fn - 1) * h))
		 * (exp(b * fn * h) - 1.0)
		 / (exp(b * h) - 1.0);
	//Calculate second moment.
	bv = b + v * v;
	b2v = b + bv;
	f1 = exp(b2v * fn * h);
	f2 = exp(b * h);
	f3 = exp(b2v * h);
	f4 = exp(b * fn * h);
	f5 = exp(bv * h);
	b1 = (1.0 - f1) / ((1.0 - f2) * (1.0 - f3));
	b2 = (f4 - f1) / ((1.0 - f2) * (1.0 - f5));
	b3 = (f2 - f4) / ((1.0 - f2) * (1.0 - f5));
	b4 = (f3 - f1) / ((1.0 - f5) * (1.0 - f3));
	m2 = pow_legacy((s / fn), 2.0)//WTW - Gen2 - use of undeclared identifier
		 * exp(b2v * (tee - (fn - 1) * h))
		 * (b1 - b2 + b3 - b4);
	}
var = log(m2) - 2.0 * log(m1);
vavg = pow_legacy((max(var, 0.0)), 0.5);//WTW - Gen2 - use of undeclared identifier
// Calculate call option price.
// xp = strike price adjusted to value average over unsampled points
xp = (x - pr * savg) / fr;
if (xp > 0)
	{
	d1 = (0.5 * log(m2) - log(xp)) / vavg;
	d2 = d1 - vavg;
	callprice = exp(-r * tee)
				* (m1 * cumul_normal_distribn(d1)
				  - xp * cumul_normal_distribn(d2)) * fr;
	if (call_or_put == CALL_CODE)
		asian_opt_val = callprice;
	else
		asian_opt_val = callprice - (m1 - xp) * exp(-r * tee) * fr;
	}
else
	{   // the option pays with certainty
	if (call_or_put == CALL_CODE)
		asian_opt_val = exp(-r * tee) * (fr * m1 + pr * savg - x);
	else
		asian_opt_val = 0.0;
	}
return asian_opt_val;
}
// Black Scholes Option Value Levy Asian
static double bs_opt_val_levy_asian(double strike_price, double yrs_to_expiry, double underlying_price, double average_price, double vol, double risk_free_rate, double payout_rate)
{
double tte = 0.0;
double K = 0.0;
double S = 0.0;
double rf = 0.0;
double q = 0.0;
double sigma = 0.0;
double Average = 0.0;
double levy_asian = 0.0;
double SE = 0.0;
double SV = 0.0;
double XStar = 0.0;
double m = 0.0;
double d = 0.0;
double d1 = 0.0;
double d2 = 0.0;
double TERM = 1;
// Initialize variables.
tte = yrs_to_expiry;
K = strike_price;
S = underlying_price;
rf = risk_free_rate;
q = payout_rate;
sigma = vol;
Average = average_price;

if (tte <= 0.0)
	levy_asian =  max(0.0, Average - K);
SE = S / (TERM * (rf - q)) * (exp(((rf - q) - rf) * tte) - exp(-rf * tte));
m = 2.0 * pow_legacy(S,2.0) / ((rf - q) + pow_legacy(sigma,2.0)) * ((exp((2.0 * (rf - q) + pow_legacy(sigma,2.0)) * tte) - 1.0) /
	(2.0 * (rf - q) + pow_legacy(sigma,2.0)) - (exp((rf - q) * tte) - 1.0) / (rf - q));//WTW - Gen2 - use of undeclared identifier
d = m / pow_legacy(TERM,2.0);	//WTW - Gen2 - use of undeclared identifier
SV = log(d) - 2.0 * (rf * tte + log(SE));
if (SV < 0.0)
	levy_asian = max(0.0, Average - K);
else if (K < (TERM - tte) / TERM * Average)
	levy_asian = Average - K;
else 
{
	XStar = K - (TERM - tte) / TERM * Average;
	d1 = 1.0 / pow_legacy(SV,0.5) * (log(d) / 2.0 - log(XStar));//WTW - Gen2 - use of undeclared identifier
	d2 = d1 - pow_legacy(SV,0.5);//WTW - Gen2 - use of undeclared identifier
	
	levy_asian = SE * cumul_normal_distribn(d1) - XStar * exp(-rf * tte) * cumul_normal_distribn(d2);
}
return levy_asian;
}
// Black Scholes Option Value Continuous Highest Gain
static double bs_opt_val_continuous_highest_gain(int call_or_put, double current_price, double observed_max, double observed_min, double strike_price, double length_of_sampling_period, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
double s = 0.0;
double smax = 0.0;
double smin = 0.0;
double x = 0.0;
double ta = 0.0;
double tee = 0.0;
double r = 0.0;
double d = 0.0;
double v = 0.0;
double b = 0.0;
double mx = 0.0;
double e1 = 0.0;
double e2 = 0.0;
double t1 = 0.0;
double d1 = 0.0;
double d2 = 0.0;
double f1 = 0.0;
double f2 = 0.0;
double highest_gain_continuous_opt_val = 0.0;
// call_or_put - CALL_CODE  for Call
//               PUT_CODE   for Put
// current_price              (s)
// observed_max               (smax)      for call
// observed_min               (smin)      for put
// strike_price               (x)
// length_of_sampling_period  (ta)
// yrs_to_expiry              (t)
// yrs_to_expiry              (r)
// init_div_yld               (b)
// index_vol                  (v)
s = current_price;
smax = observed_max;
smin = observed_min;
x = strike_price;
ta = length_of_sampling_period;
tee = yrs_to_expiry;
d = log(1.0 + init_div_yld / scen_index_freq)
	* scen_index_freq;
r = log(1.0 + risk_free_rate / scen_int_freq)
	* scen_int_freq;
v = index_vol;
b = r - d; // cost of carry
if (fabs(b) < 0.000001)
	{
	b = 0.0000001;
	// Temporary until we calculate the limit of M2
	// as b approaches zero.
	}
if (tee <= ta)
	{   // within sampling period
	if (call_or_put == CALL_CODE)
		mx = max(smax, x);
else
		mx = min(smin, x);
	e1 = (log(s / mx) + (b + pow_legacy(v, 2) / 2.0) * tee) / (v * pow_legacy(tee, 0.5));//WTW - Gen2 - use of undeclared identifier
	e2 = e1 - v * pow_legacy(tee, 0.5);//WTW - Gen2 - use of undeclared identifier
	if (call_or_put == CALL_CODE)
		highest_gain_continuous_opt_val
= exp(-r * tee)
			  * (mx - x)
			  + s * exp((b - r) * tee)
				  * cumul_normal_distribn(e1)
			  - mx * exp(-r * tee)
				  * cumul_normal_distribn(e2)
			  + s * exp(-r * tee) * (pow_legacy(v, 2) / (2.0 * b))
				  * (-pow_legacy((s / mx), (-2 * b / pow_legacy(v, 2)))
				  * cumul_normal_distribn(e1 - 2 * b / v * pow_legacy(tee, 0.5))
			  + exp(b * tee)
				  * cumul_normal_distribn(e1));//WTW - Gen2 - use of undeclared identifier
	else
		highest_gain_continuous_opt_val
		= exp(-r * tee)
		  * (x - mx)
		  - s * exp((b - r) * tee)
			   * cumul_normal_distribn(-e1)
		  + mx * exp(-r * tee)
			   * cumul_normal_distribn(-e1 + v * pow_legacy(tee, 0.5))
		  + s * exp(-r * tee) * (pow_legacy(v, 2) / (2 * b))
			  * (pow_legacy((s / mx), (-2 * b / pow_legacy(v, 2)))
			  * cumul_normal_distribn(-e1 + 2 * b / v * pow_legacy(tee,0.5))
		  - exp(b * tee)
			* cumul_normal_distribn(-e1));//WTW - Gen2 - use of undeclared identifier
}
else
{
// before sampling period
//
//  |<--------------tee---------------------------------->|
//  |<------t1-------->|<---------Ta--------------------->|
//  |------------------|----------------------------------|
//
	t1 = tee - ta;
	d1 = (log(s / x) + (b + pow_legacy(v, 2) / 2.0) * tee) / (v * pow_legacy(tee, 0.5));
	d2 = d1 - v * pow_legacy(tee, 0.5);
	e1 = ((b + pow_legacy(v, 2) / 2.0) * ta) / (v * pow_legacy(ta, 0.5));//WTW - Gen2 - use of undeclared identifier
	e2 = e1 - v * pow_legacy(ta, 0.5);
	f1 = (log(s / x) + (b + pow_legacy(v, 2) / 2.0) * t1) / (v * pow_legacy(t1, 0.5));//WTW - Gen2 - use of undeclared identifier
	f2 = f1 - v * pow_legacy(t1, 0.5);//WTW - Gen2 - use of undeclared identifier
	if (call_or_put == CALL_CODE)
		highest_gain_continuous_opt_val
		= s * exp((b - r) * tee)
		    * cumul_normal_distribn(d1)
		  - exp(-r * tee) * x
		    * cumul_normal_distribn(d2)
		  + s * exp(-r * tee) * (pow_legacy(v,2) / (2 * b))
		      * (-pow_legacy((s / x), (-2 * b / pow_legacy(v,2)))
		      * cumul_bivariate_normal_distribn(d1 - 2 * b * pow_legacy(tee, 0.5) / v,
							-f1 + 2 * b * pow_legacy(t1, 0.5) / v,
							-pow_legacy((t1 / tee), 0.5))
		  + exp(b * tee)
			* cumul_bivariate_normal_distribn(e1, d1, pow_legacy((1 - t1 / tee), 0.5)))
		  - s * exp((b - r) * tee)
			  * cumul_bivariate_normal_distribn(-e1, d1, -pow_legacy((1 - t1 / tee), 0.5))
		  - x * exp(-r * tee)
			  * cumul_bivariate_normal_distribn(f2, -d2, -pow_legacy((t1 / tee), 0.5))
		  + exp(-b * (ta)) * (1 - pow_legacy(v, 2) / (2 * b))
			* s * exp((b - r) * tee)
			* cumul_normal_distribn(f1)
			* cumul_normal_distribn(-e2);//WTW - Gen2 - use of undeclared identifier
else // "Put"
		highest_gain_continuous_opt_val
		= x * exp(-r * tee)
			* cumul_normal_distribn(-d2)
		  - s * exp((b - r) * tee)
			  * cumul_normal_distribn(-d1)
		  + s * exp(-r * tee) * (pow_legacy(v, 2) / (2 * b))
			  * (pow_legacy((s / x), (-2 * b / pow_legacy(v, 2)))
			  * cumul_bivariate_normal_distribn(-d1 + 2 * b * pow_legacy(tee, 0.5) / v,
						f1 - 2 * b * pow_legacy(t1, 0.5) / v,
						-pow_legacy((t1 / tee), 0.5))
		  - exp(b * tee)
			* cumul_bivariate_normal_distribn(-e1, -d1, pow_legacy((1 - t1 / tee), 0.5)))
		  + s * exp((b - r) * tee)
			  * cumul_bivariate_normal_distribn(e1, -d1, -pow_legacy((1 - t1 / tee), 0.5))
		  + x * exp(-r * tee)
			  * cumul_bivariate_normal_distribn(-f2, d2, -pow_legacy((t1 / tee), 0.5))
		  - exp(-b * ta) * (1 - pow_legacy(v, 2) / (2 * b))
			* s * exp((b - r) * tee)
			* cumul_normal_distribn(-f1)
			* cumul_normal_distribn(e2);//WTW - Gen2 - use of undeclared identifier
}
return highest_gain_continuous_opt_val;
}
// Black Scholes Option Value Highest Gain
static double bs_opt_val_highest_gain(int call_or_put, double current_price, double observed_max, double observed_min, double strike_price, double length_of_sampling_period, int sampling_freq, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
// call_or_put - CALL_CODE  for Call
//               PUT_CODE   for Put
// current_price              (s)
// observed_max               (smax)
// observed_min               (smin)
// strike_price               (x)
// length_of_sampling_period  (ta)
// sampling_freq              (freq)
//          =    0  for continuous
//             256  for daily
//              52  for weekly
//              12  for monthly
//               4  for quarterly
//               2  for semiannual
//               1  for annual
// yrs_to_expiry              (t)
// risk_free_rate             (r)
// init_div_yld               (b)
// index_vol                  (v)
//
// Description.  This formula set assumes that the high watermark values
//   are based on sample points at the beginnings and ends of sample
//   months.  To sample ends of months, execute this formula set with the
//   length of the sampling period reduced by one sample period.  The
//   reduction does not apply to continuous sampling.
double highest_gain_opt_val = 0.0;
if (sampling_freq == 0) // "Continuous"
	highest_gain_opt_val
	= bs_opt_val_continuous_highest_gain(call_or_put,
				current_price,
				observed_max,
				observed_min,
				strike_price,
				length_of_sampling_period,
				yrs_to_expiry,
				risk_free_rate,
				init_div_yld,
				index_vol,
				scen_int_freq,
				scen_index_freq);
else // discrete sampling
	{
	double adjustment_factor
	= bs_highest_gain_freq_mult(length_of_sampling_period,
				sampling_freq,
				yrs_to_expiry,
				risk_free_rate,
				init_div_yld,
				index_vol,
				scen_int_freq,
				scen_index_freq);
	double adj_max = observed_max * adjustment_factor;
	double adj_min = observed_min * adjustment_factor;
	double adj_strike_price = strike_price * adjustment_factor;
	highest_gain_opt_val
	= bs_opt_val_continuous_highest_gain(call_or_put,
				current_price,
				adj_max,
				adj_min,
				adj_strike_price,
				length_of_sampling_period,
				yrs_to_expiry,
				risk_free_rate,
				init_div_yld,
				index_vol,
				scen_int_freq,
				scen_index_freq)
		/ adjustment_factor;
	}
return highest_gain_opt_val;
}
// Black Scholes Option Value Monthly Sum Cap
static double bs_opt_val_mthly_sum_cap(int crediting_mths, int known_index_vals, double sum_capped_amts,  double mthly_cap_rate, double yrs_to_expiry, double risk_free_rate, double init_div_yld, double index_vol, int scen_int_freq, int scen_index_freq)
{
int n = 0.0;
int mo = 0.0;
int n_rem = 0.0;
double I = 0.0;
double D = 0.0;
double sigma = 0.0;
double m = 0.0;
double X = 0.0;
double mu = 0.0;
double p = 0.0;
double d = 0.0;
double M = 0.0;
double V = 0.0;
double sqrtV = 0.0;
double Evy = 0.0;
double Evy2 = 0.0;
double EvM = 0.0;
double VarM = 0.0;
double c1 = 0.0;
double c2 = 0.0;
double a = 0.0;
double b = 0.0;
double mthly_sum_cap_opt_val = 0.0;

n = crediting_mths;
mo = known_index_vals;
n_rem = n - mo;

I = log(1.0 + risk_free_rate / scen_int_freq)
    * scen_int_freq;
D = log(1.0 + init_div_yld / scen_index_freq)
    * scen_index_freq;
sigma = index_vol;
m = mthly_cap_rate;
mu = I - D;

M = (mu - (sigma * sigma) / 2.0) / 12.0;
X = (1.0 + m);
V = (sigma * sigma) / 12.0;
sqrtV = pow_legacy(V, 0.5);//WTW - Gen2 - use of undeclared identifier

p = cumul_normal_distribn(pow_legacy(12.0, 0.5) / sigma * (log(X) - M));//WTW - Gen2 - use of undeclared identifier

d = (M + V - log(X)) / sqrtV;

Evy = exp(M + V / 2.0) * cumul_normal_distribn(-d) 
       - X * cumul_normal_distribn(-d + sqrtV);  

Evy2 = exp(2 * M + 2 * V) * cumul_normal_distribn(-d - sqrtV)
       - 2 * X * exp(M + V / 2.0) * cumul_normal_distribn(-d)
	   + X * X * cumul_normal_distribn(-d + sqrtV); 

EvM = m + Evy; 
VarM = Evy2 - pow_legacy(Evy, 2.0);//WTW - Gen2 - use of undeclared identifier

c1 = (EvM - m * (1.0 - p)) / p;
c2 = (VarM  + EvM * EvM - m * m * (1.0 - p)) / p;

a = pow_legacy(12.0 * (c2 - (c1 * c1)), 0.5);//WTW - Gen2 - use of undeclared identifier
b = c1 - a / 2.0;

if (n_rem == 0)
	return sum_capped_amts;

double sum = 0.0;
for (int k = 0; k <= n_rem; k++)
	{
	double sumi = 0.0;
	for (int v = 0; v <= k; v++)
		{
		double vali1 = pow_legacy(-1, k - v);//WTW - Gen2 - use of undeclared identifier
		double vali2 = n_choose_k(k, v);
		double vali3 = pow_legacy(max(v * a + k * b + (n_rem - k) * m + sum_capped_amts, 0.0), k + 1);	//WTW - Gen2 - use of undeclared identifier		
		double vali = vali1 * vali2 * vali3;
		sumi += vali;
		}
	
	double valo1 = n_choose_k(n_rem, k);
	double valo2 = pow_legacy(p, k) * pow_legacy(1.0 - p, n_rem - k);//WTW - Gen2 - use of undeclared identifier
	double valo3 = pow_legacy(a, k) * factorial(k + 1);//WTW - Gen2 - use of undeclared identifier
	double valo = (valo1 * valo2) / valo3;
	sum += sumi * valo;
	}

mthly_sum_cap_opt_val 
= sum * exp(- I * yrs_to_expiry);

return mthly_sum_cap_opt_val;
}


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
	static void Terminator();
	static FunctionPtr RegisterTerminatorOnce;
	
Economy* Econ;
EconomyData* EconData;
GenerationData* GenData;
CalibrationData* CalibData;
//EconErrorCodeType econ_err_code;
int econ_err_code;//WTW - Gen2 - user defined enum 
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

vector <double> swap_curve_tenors_aig;


	void init_(){
		

Econ = NULL;
EconData = NULL;
GenData = NULL;
CalibData = NULL;
hedge_valn_shock_id_prev = "Undefined";

		bIsInit = true;
	}
	void deInit_(){

if (Econ != NULL)
    {
    Economy::Release(Econ);
    Econ = NULL;
    }

if (EconData != NULL)
    {
    EconomyData::Release(EconData);
    EconData = NULL;
    }

if (GenData != NULL)
    {
    GenerationData::Release(GenData);
    GenData = NULL;
    }

if (CalibData != NULL)
    {
    CalibrationData::Release(CalibData);
    CalibData = NULL;
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
#ifdef __CREATE_BOND_AIG_CLASS_
	BOND_AIG	*company_liab_fia_fia_bond_portfolio_aig_fia_bond_aig;
	BOND_AIG	*&fia_bond_aig;
#endif
#ifdef __CREATE_BOND_PORTFOLIO_AIG_CLASS_
	BOND_PORTFOLIO_AIG	*company_liab_fia_fia_bond_portfolio_aig;
	BOND_PORTFOLIO_AIG	*&fia_bond_portfolio_aig;
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
 	ColumnAccessor < mCFStaticData_0 > cal_mth;
 	ColumnAccessor < mCFStaticData_0 > cal_yr;
 	ColumnAccessor < mCFStaticData_0 > cal_yr_relative;
 	ColumnAccessor < mCFStaticData_0 > date;
 	ColumnAccessor < mCFStaticData_0 > equity_market_value_growth_us;
 	ColumnAccessor < mCFStaticData_0 > equity_scenario_total_return_us;
 	ColumnAccessor < mCFStaticData_0 > exact_date;
 	ColumnAccessor < mCFStaticData_0 > finalize;
 	ColumnAccessor < mCFStaticData_0 > generate;
 	ColumnAccessor < mCFStaticData_0 > generate_deterministic_scen;
 	ColumnAccessor < mCFStaticData_0 > infl_rate_annual;
 	ColumnAccessor < mCFStaticData_0 > initialize;
 	ColumnAccessor < mCFStaticData_0 > startup;
 	ColumnAccessor < mCFStaticData_0 > ten_year_treasury_annualized_return_cumul_max_aig;
 	ColumnAccessor < mCFStaticData_0 > ten_year_treasury_annualized_return_max_aig;
 	ColumnAccessor < mCFStaticData_0 > ten_year_treasury_annualized_return_three_mth_avg_aig;
 	ColumnAccessor < mCFStaticData_0 > yield_rate_10_year;
 	ColumnAccessor < mCFStaticData_0 > yield_rate_90_day;
//Column Definition END@2

 // Temporary Table...
RATES_ECONOMY *sm_bond_is;
RATES_ECONOMY *sm_bond_pv;
RATES_ECONOMY *sm_bond_ym;
RATES_ECONOMY *sm_mtg_is;
RATES_ECONOMY *sm_mtg_pv;
RATES_ECONOMY *sm_mtg_ym;
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
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > credit_sprd_intercept_aig;
  inline double	Get_credit_sprd_intercept_aig() {
		return credit_sprd_intercept_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > credit_sprd_slope_aig;
  inline double	Get_credit_sprd_slope_aig() {
		return credit_sprd_slope_aig; }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > credit_sprd_stoch_mult;
  inline double	Get_credit_sprd_stoch_mult() {
		return credit_sprd_stoch_mult; }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > cubic_spline_enhancement_wtw_switch_aig;
  inline xstring	Get_cubic_spline_enhancement_wtw_switch_aig() {
		return cubic_spline_enhancement_wtw_switch_aig; }
	Attribute::Proxy <int, DESCRIPTOR_TABLE > date_lookup_gen2;
  inline int	Get_date_lookup_gen2() {
		return date_lookup_gen2; }
  inline void Set_date_lookup_gen2(const int &v) {
		date_lookup_gen2.setValue(v); }
	Attribute::ProxyReadOnly <double, DESCRIPTOR_TABLE > dflt_rate_deterministic;
  inline double	Get_dflt_rate_deterministic() {
		return dflt_rate_deterministic; }
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
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > gen2_defn;
  inline xstring	Get_gen2_defn() {
		return gen2_defn; }
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
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > investment_set_aig;
  inline xstring	Get_investment_set_aig() {
		return investment_set_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > liquidity_spread_set_aig;
  inline xstring	Get_liquidity_spread_set_aig() {
		return liquidity_spread_set_aig; }
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
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > rate_setting_cycle_aig;
  inline xstring	Get_rate_setting_cycle_aig() {
		return rate_setting_cycle_aig; }
	Attribute::Proxy <double, DESCRIPTOR_TABLE > rate_term;
  inline double	Get_rate_term() {
		return rate_term; }
  inline void Set_rate_term(const double &v) {
		rate_term.setValue(v); }
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > save_time_step_scen_files_defn;
  inline xstring	Get_save_time_step_scen_files_defn() {
		return save_time_step_scen_files_defn; }
	Attribute::ProxyReadOnly <int, DESCRIPTOR_TABLE > scen_eof_period_aig;
  inline int	Get_scen_eof_period_aig() {
		return scen_eof_period_aig; }
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
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > swap_curve_rate_id_aig;
  inline xstring	Get_swap_curve_rate_id_aig() {
		return swap_curve_rate_id_aig; }
	Attribute::ProxyReadOnly <xstring, DESCRIPTOR_TABLE > swap_curve_tenors_input_aig;
  inline xstring	Get_swap_curve_tenors_input_aig() {
		return swap_curve_tenors_input_aig; }
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
	Attribute::ProxyReadOnly <StringEnum, DESCRIPTOR_TABLE > time_step_defn;
  inline xstring	Get_time_step_defn() {
		return time_step_defn; }
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

// Calculate the Brownian bridge estimated maximum assuming normal random walk:
#line 1 "brownian_bridge_max_calc_normal_aig.rates_economy.for"
double brownian_bridge_max_calc_normal_aig(double val_bom, double val_eom, double annual_vol, double u);

// Calc Forward From Swap Aig
#line 1 "calc_forward_from_swap_aig.rates_economy.for"
double calc_forward_from_swap_aig(int swap_rate_tenor, int t1, int t2);

// calculate forward rate
#line 1 "calc_fwrd_rate_crbg.rates_economy.for"
double calc_fwrd_rate_crbg(double rate_term_input, double fwd_term);

// Calculate Spot Rates From Yield Rates
#line 1 "calc_spot_from_yld.rates_economy.for"
double calc_spot_from_yld(int t, const xstring &quality_id, double term, int shift_type, double portfolio_sprd_adj_aig);

// Calculate Yield Rates From Spot Rates
#line 1 "calc_yld_from_spot.rates_economy.for"
double calc_yld_from_spot(int t, const xstring &quality_id, double term, int shift_type, double portfolio_sprd_adj_aig);

// Clear Shifted Rates Maps
#line 1 "clear_shifted_rates_maps.rates_economy.for"
void clear_shifted_rates_maps(void);

// Cubic Spline Interpolated Curve Aig
#line 1 "cubic_spline_interpolated_curve_aig.rates_economy.for"
vector<double> cubic_spline_interpolated_curve_aig(double start_mth, double end_mth, vector <double> lookups, vector <double> values, cubic_spline_params_aig cubic_spline_params_input = default_cubic_spline_params_aig);

// Cubic Spline Interpolation Algorithm
#line 1 "cubic_spline_interpolation_aig.rates_economy.for"
double cubic_spline_interpolation_aig(double lookup_value, vector <double> lookups, vector <double> values, cubic_spline_params_aig cubic_spline_params_input = default_cubic_spline_params_aig);

// Cubic Spline Parameters Calculation
#line 1 "cubic_spline_params_calc_aig.rates_economy.for"
void cubic_spline_params_calc_aig(cubic_spline_params_aig& return_parameters, vector <double> lookups, vector <double> values);

// Cubic Spline Params Create
#line 1 "cubic_spline_params_create.rates_economy.for"
const cubic_spline_params_aig& cubic_spline_params_create(const cubic_spline_params_aig& cubic_spline_params_input, const vector<double>& lookups, const vector<double>& values);

// Disc Rate 1
#line 1 "disc_rate_1.rates_economy.for"
double disc_rate_1(int t, double scenario_year);

// Economy Error Processing
#line 1 "econ_error_processing.rates_economy.for"
void econ_error_processing(int econ_err_code);

// Economy Rate Error Processing
#line 1 "econ_rate_error_processing.rates_economy.for"
void econ_rate_error_processing(int t, xstring id, int econ_err_code);

// Get Default Rate
#line 1 "get_dflt_rate.rates_economy.for"
double get_dflt_rate(int t, const xstring &quality_id_input, int return_rate_basis);

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
double get_int_rate(int t, const xstring &quality_id_input, int rate_type, double rate_term_input, double fwd_term, int return_rate_basis, int shift_type, double portfolio_sprd_adj_aig = 0);

// Get Interest Volatility
#line 1 "get_int_vol.rates_economy.for"
double get_int_vol(int t, const xstring &quality_id_input, double moneyness_input, double rate_term_input, int return_rate_basis);

// Get Miscellaneous Rate
#line 1 "get_misc_rate.rates_economy.for"
double get_misc_rate(int t, const xstring &misc_rate_id, int return_rate_basis);

// Get Risk Free Rate
#line 1 "get_risk_free_rate_aig.rates_economy.for"
double get_risk_free_rate_aig(int t);

// Linear Interpolation Algorithm
#line 1 "linear_interpolation_aig.rates_economy.for"
double linear_interpolation_aig(double lookup_value, vector <double> lookups, vector <double> values);

// Scenario Rates Load
#line 1 "scen_rates_load.rates_economy.for"
void scen_rates_load(int scen_num);

// Scenario Set Information Load
#line 1 "scen_set_info_load.rates_economy.for"
void scen_set_info_load(void);

// Select Scenario Set
#line 1 "select_scen_set.rates_economy.for"
void select_scen_set(int scen_set_type);

// Setup Calibration Criteria
#line 1 "setup_calibration_criteria.rates_economy.for"
void setup_calibration_criteria(int t);

// Setup Economy Data
#line 1 "setup_economy_data.rates_economy.for"
void setup_economy_data(int t);

// Setup Generation Parameters
#line 1 "setup_generation_parameters.rates_economy.for"
void setup_generation_parameters(int t);

// Setup Shock Generation List
#line 1 "setup_shock_gen_list.rates_economy.for"
void setup_shock_gen_list(void);

// Swap Curve Init Cubic Spline Params Aig
#line 1 "swap_curve_init_cubic_spline_params_aig.rates_economy.for"
vector<double> swap_curve_init_cubic_spline_params_aig(int t, cubic_spline_params_aig& swap_curve_cubic_spline_params);

// Use Trapezoidal Rule to compute an average:
#line 1 "trapezoidal_rule_avg_height_calc_aig.rates_economy.for"
double trapezoidal_rule_avg_height_calc_aig(vector<double> f_x);


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
	RATES_ECONOMY *&sm_bond_is; //
	RATES_ECONOMY *&sm_bond_pv; //
	RATES_ECONOMY *&sm_bond_ym; //
	RATES_ECONOMY *&sm_mtg_is; //
	RATES_ECONOMY *&sm_mtg_pv; //
	RATES_ECONOMY *&sm_mtg_ym; //

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
