
#ifndef __SFAS97RD_GAAP_UDF_H_
#define __SFAS97RD_GAAP_UDF_H_

#include "ModelClass\sfas97rd_gaap.h"

class SFAS97RD_GAAP_UDF : public SFAS97RD_GAAP {

	friend class SFAS97RD_GAAP;

//constructor 
SFAS97RD_GAAP_UDF(const xstring &modelClassName, int isSubmodel, ModelClass *owner, ModelClass *peer, 
				int mainRebase,	const char *name, ModelClass* arrayPersistentObj)
	: SFAS97RD_GAAP(modelClassName, isSubmodel, owner, peer, mainRebase, name, arrayPersistentObj){}
public:

// this as Base ctor
SFAS97RD_GAAP_UDF(int columnCount, Descriptor* mocd[], Product* persObj)
    : SFAS97RD_GAAP(columnCount, mocd, persObj) {}


// Acquisition Expenses 
double sfas97rd_gaap_acq_exp(int t);

// Actual Gross Profits 
double sfas97rd_gaap_agp(int t);

// Amortization Interest Rate 
double sfas97rd_gaap_amortzn_int_rate(int t);

// Calendar Month 
double sfas97rd_gaap_cal_mth(int t);

// Calendar Year 
double sfas97rd_gaap_cal_yr(int t);

// Calendar Year Relative 
double sfas97rd_gaap_cal_yr_relative(int t);

// Capital Gain 
double sfas97rd_gaap_cap_gain(int t);

// Capital Gain on Fund 
double sfas97rd_gaap_cap_gain_fund(int t);

// Capitalized Acquisition Expenses 
double sfas97rd_gaap_capzd_acq_exp(int t);

// Capitalized Acquisition Expenses Accumulation 
double sfas97rd_gaap_capzd_acq_exp_accum(int t);

// Capitalized Acquisition Expenses Accumulation At Loss Recognition Interest Rate 
double sfas97rd_gaap_capzd_acq_exp_accum_loss_rec_int_rate(int t);

// Capitalized Acquisition Expenses Present Value 
double sfas97rd_gaap_capzd_acq_exp_pv(int t);

// Capitalized Acquisition Expenses Present Value At Loss Recognition Interest Rate 
double sfas97rd_gaap_capzd_acq_exp_pv_loss_rec_int_rate(int t);

// Capitalized Commissions Accumulation 
double sfas97rd_gaap_capzd_comm_accum(int t);

// Capitalized Commissions Accumulation At Loss Recognition Interest Rate 
double sfas97rd_gaap_capzd_comm_accum_loss_rec_int_rate(int t);

// Capitalized Commissions BOM 
double sfas97rd_gaap_capzd_comm_bom(int t);

// Capitalized Commissions Chargeback 
double sfas97rd_gaap_capzd_comm_chargeback(int t);

// Capitalized Commissions EOM 
double sfas97rd_gaap_capzd_comm_eom(int t);

// Capitalized Commissions Present Value 
double sfas97rd_gaap_capzd_comm_pv(int t);

// Capitalized Commissions Present Value At Loss Recognition Interest Rate 
double sfas97rd_gaap_capzd_comm_pv_loss_rec_int_rate(int t);

// Capitalized Premium Bonus 
double sfas97rd_gaap_capzd_prem_bonus(int t);

// Capitalized Premium Bonus Accumulation 
double sfas97rd_gaap_capzd_prem_bonus_accum(int t);

// Capitalized Premium Bonus Accumulation At Loss Recognition Interest Rate 
double sfas97rd_gaap_capzd_prem_bonus_accum_loss_rec_int_rate(int t);

// Capitalized Premium Bonus Present Value 
double sfas97rd_gaap_capzd_prem_bonus_pv(int t);

// Capitalized Premium Bonus Present Value At Loss Recognition Interest Rate 
double sfas97rd_gaap_capzd_prem_bonus_pv_loss_rec_int_rate(int t);

// Capitalized YRT Reinsurance Cost 
double sfas97rd_gaap_capzd_reins_yrt_cost(int t);

// Cash Flow Beginning of Month 
double sfas97rd_gaap_cash_flow_bom(int t);

// Cash Flow Interest 
double sfas97rd_gaap_cash_flow_int(int t);

// Charges 
double sfas97rd_gaap_charges(int t);

// Commission Chargeback 
double sfas97rd_gaap_comm_chargeback(int t);

// Commissions Excess BOM 
double sfas97rd_gaap_comm_excess_bom(int t);

// Commissions Excess EOM 
double sfas97rd_gaap_comm_excess_eom(int t);

// Commissions Trail BOM 
double sfas97rd_gaap_comm_trail_bom(int t);

// Commissions Trail EOM 
double sfas97rd_gaap_comm_trail_eom(int t);

// Credited Interest 
double sfas97rd_gaap_credited_int(int t);

// DAC Acquisition Expense 
double sfas97rd_gaap_dac_acq_exp(int t);

// DAC Acquisition Expense Amortization 
double sfas97rd_gaap_dac_acq_exp_amortzn(int t);

// DAC Acquisition Expense Increase 
double sfas97rd_gaap_dac_acq_exp_incr(int t);

// DAC Acquisition Expense Interest 
double sfas97rd_gaap_dac_acq_exp_int(int t);

// DAC Acquisition Expense Loss Recognition 
double sfas97rd_gaap_dac_acq_exp_loss_rec(int t);

// DAC Acquisition Expense Loss Recognition Accumulation 
double sfas97rd_gaap_dac_acq_exp_loss_rec_accum(int t);

// DAC Acquisition Expense Loss Recognition History Accumulation 
double sfas97rd_gaap_dac_acq_exp_loss_rec_hist_accum(int t);

// DAC Acquisition Expense Schedule 
double sfas97rd_gaap_dac_acq_exp_sch(int t);

// DAC Commission 
double sfas97rd_gaap_dac_comm(int t);

// DAC Commission Amortization 
double sfas97rd_gaap_dac_comm_amortzn(int t);

// DAC Commission Increase 
double sfas97rd_gaap_dac_comm_incr(int t);

// DAC Commission Interest 
double sfas97rd_gaap_dac_comm_int(int t);

// DAC Commission Loss Recognition 
double sfas97rd_gaap_dac_comm_loss_rec(int t);

// DAC Commission Loss Recognition Accumulation 
double sfas97rd_gaap_dac_comm_loss_rec_accum(int t);

// DAC Commission Loss Recognition History Accumulation 
double sfas97rd_gaap_dac_comm_loss_rec_hist_accum(int t);

// DAC Commission Schedule 
double sfas97rd_gaap_dac_comm_sch(int t);

// DAC Increase 
double sfas97rd_gaap_dac_incr(int t);

// DAC Premium Bonus 
double sfas97rd_gaap_dac_prem_bonus(int t);

// DAC Premium Bonus Amortization 
double sfas97rd_gaap_dac_prem_bonus_amortzn(int t);

// DAC Premium Bonus Increase 
double sfas97rd_gaap_dac_prem_bonus_incr(int t);

// DAC Premium Bonus Interest 
double sfas97rd_gaap_dac_prem_bonus_int(int t);

// DAC Premium Bonus Loss Recognition 
double sfas97rd_gaap_dac_prem_bonus_loss_rec(int t);

// DAC Premium Bonus Loss Recognition Accumulation 
double sfas97rd_gaap_dac_prem_bonus_loss_rec_accum(int t);

// DAC Premium Bonus Loss Recognition History Accumulation 
double sfas97rd_gaap_dac_prem_bonus_loss_rec_hist_accum(int t);

// DAC Premium Bonus Schedule 
double sfas97rd_gaap_dac_prem_bonus_sch(int t);

// DAC YRT Reinsurance Asset 
double sfas97rd_gaap_dac_reins_yrt_asset(int t);

// DAC YRT Reinsurance Asset Amortization 
double sfas97rd_gaap_dac_reins_yrt_asset_amortzn(int t);

// DAC YRT Reinsurance Asset Increase 
double sfas97rd_gaap_dac_reins_yrt_asset_incr(int t);

// DAC YRT Reinsurance Asset Interest 
double sfas97rd_gaap_dac_reins_yrt_asset_int(int t);

// DAC YRT Reinsurance Asset Schedule 
double sfas97rd_gaap_dac_reins_yrt_asset_sch(int t);

// Date 
double sfas97rd_gaap_date(int t);

// Deferred Loads 
double sfas97rd_gaap_deferred_loads(int t);

// Deferred Loads Accumulation 
double sfas97rd_gaap_deferred_loads_accum(int t);

// Deferred Loads Present Value 
double sfas97rd_gaap_deferred_loads_pv(int t);

// Death Claim Cost 
double sfas97rd_gaap_dth_claim_cost(int t);

// Estimated Gross Profit 
double sfas97rd_gaap_egp(int t);

// EGP Accumulation 
double sfas97rd_gaap_egp_accum(int t);

// EGP Accumulation At Loss Recognition Interest Rate 
double sfas97rd_gaap_egp_accum_loss_rec_int_rate(int t);

// EGP Expense Gain 
double sfas97rd_gaap_egp_gain_exp(int t);

// EGP Investment Gain 
double sfas97rd_gaap_egp_gain_inv(int t);

// EGP Mortality Gain 
double sfas97rd_gaap_egp_gain_mort(int t);

// EGP Persistency Bonus/Refund Gain 
double sfas97rd_gaap_egp_gain_persist_bon_ref(int t);

// EGP Surrender Gain 
double sfas97rd_gaap_egp_gain_surr(int t);

// EGP Present Value 
double sfas97rd_gaap_egp_pv(int t);

// EGP Present Value At Loss Recognition Interest Rate 
double sfas97rd_gaap_egp_pv_loss_rec_int_rate(int t);

// EGP SOP 03-1 Assessments Accumulation 
double sfas97rd_gaap_egp_sop031_assess_accum(int t);

// EGP SOP 03-1 GMDB Benefits Accumulation 
double sfas97rd_gaap_egp_sop031_gmdb_ben_accum(int t);

// EGP SOP 03-1 GMDB Liability 
double sfas97rd_gaap_egp_sop031_gmdb_liab(int t);

// EGP SOP 03-1 GMIB Benefits Accumulation 
double sfas97rd_gaap_egp_sop031_gmib_ben_accum(int t);

// EGP SOP 03-1 GMIB Liability 
double sfas97rd_gaap_egp_sop031_gmib_liab(int t);

// EGP SOP 03-1 GMWB Benefit Accumulation 
double sfas97rd_gaap_egp_sop031_gmwb_ben_accum(int t);

// EGP SOP 03-1 GMWB Liability 
double sfas97rd_gaap_egp_sop031_gmwb_liab(int t);

// EGP SOP 03-1 Reserve Increase 
double sfas97rd_gaap_egp_sop031_res_incr(int t);

// EGP SOP 03-1 ULSG Benefits Accumulation 
double sfas97rd_gaap_egp_sop031_ulsg_ben_accum(int t);

// EGP SOP 03-1 ULSG Benefits Liability 
double sfas97rd_gaap_egp_sop031_ulsg_liab(int t);

// Embedded derivative cash flow 
double sfas97rd_gaap_embed_deriv_cash_flow(int t);

// Present value embedded derivative cash flow 
double sfas97rd_gaap_embed_deriv_cash_flow_pv(int t);

// Embedded derivative value 
double sfas97rd_gaap_embed_deriv_val(int t);

// Finalize 
double sfas97rd_gaap_finalize(int t);

// Fund Value Total 
double sfas97rd_gaap_fund_val(int t);

// Fund Value Before Interest 
double sfas97rd_gaap_fund_val_bef_int(int t);

// Fund Value Fixed 
double sfas97rd_gaap_fund_val_fixed(int t);

// Fund Value Separate Account 
double sfas97rd_gaap_fund_val_sa(int t);

// GAAP Amortization Interest Rate 
double sfas97rd_gaap_gaap_amortzn_int_rate(int t);

// GMAB Benefits 
double sfas97rd_gaap_gmab_ben(int t);

// GMDB Benefits 
double sfas97rd_gaap_gmdb_ben(int t);

// GMIB Benefits 
double sfas97rd_gaap_gmib_ben(int t);

// GMWB Benefits 
double sfas97rd_gaap_gmwb_ben(int t);

// Hedge Cash Flow 
double sfas97rd_gaap_hedge_cash_flow(int t);

// Hedge Cost 
double sfas97rd_gaap_hedge_cost(int t);

// Hedge Market Value 
double sfas97rd_gaap_hedge_mkt_val(int t);

// Hedge Market Value Increase 
double sfas97rd_gaap_hedge_mkt_val_incr(int t);

// Host Contract Credited Interest 
double sfas97rd_gaap_host_contract_cred_int(int t);

// Host Contract Value 
double sfas97rd_gaap_host_contract_val(int t);

// Host Contract Value - Before Decrements 
double sfas97rd_gaap_host_contract_val_bef(int t);

// Initialize 
double sfas97rd_gaap_initialize(int t);

// Investment Income 
double sfas97rd_gaap_inv_inc(int t);

// Investment Income on Fund 
double sfas97rd_gaap_inv_inc_fund(int t);

// K Capitalized Acquisition Expenses 
double sfas97rd_gaap_k_capzd_acq_exp(int t);

// K Capitalized Acquisition Expenses Schedule 
double sfas97rd_gaap_k_capzd_acq_exp_sch(int t);

// K Capitalized Commissions 
double sfas97rd_gaap_k_capzd_comm(int t);

// K Capitalized Commissions Schedule 
double sfas97rd_gaap_k_capzd_comm_sch(int t);

// K Capitalized Premium Bonus 
double sfas97rd_gaap_k_capzd_prem_bonus(int t);

// K Capitalized Premium Bonus Schedule 
double sfas97rd_gaap_k_capzd_prem_bonus_sch(int t);

// K YRT Reinsurance Cost 
double sfas97rd_gaap_k_reins_yrt_cost(int t);

// K YRT Reinsurance Cost Schedule 
double sfas97rd_gaap_k_reins_yrt_cost_sch(int t);

// K SOP 03-1 GMDB Benefit Ratio 
double sfas97rd_gaap_k_sop031_gmdb_ben_br(int t);

// K SOP 03-1 GMDB Benefit Ratio Schedule 
double sfas97rd_gaap_k_sop031_gmdb_ben_br_sch(int t);

// K SOP 03-1 Persistency Bonus/Refunds 
double sfas97rd_gaap_k_sop031_pbr(int t);

// K SOP 03-1 Persistency Bonus/Refunds Schedule 
double sfas97rd_gaap_k_sop031_pbr_sch(int t);

// K SOP 03-1 ULSG Benefit Ratio 
double sfas97rd_gaap_k_sop031_ulsg_ben_br(int t);

// K SOP 03-1 ULSG Benefit Ratio Schedule 
double sfas97rd_gaap_k_sop031_ulsg_ben_br_sch(int t);

// K SOP 03-1 Unearned Revenue Liability 
double sfas97rd_gaap_k_sop031_unearn_rev_liab(int t);

// K SOP 03-1 Unearned Revenue Liability Schedule 
double sfas97rd_gaap_k_sop031_unearn_rev_liab_sch(int t);

// K Unearned Revenue Liability 
double sfas97rd_gaap_k_unearn_rev_liab(int t);

// K Unearned Revenue Liability Schedule 
double sfas97rd_gaap_k_unearn_rev_liab_sch(int t);

// Liability Net of DAC 
double sfas97rd_gaap_liab_net(int t);

// Loads 
double sfas97rd_gaap_loads(int t);

// Letter of Credit Cost 
double sfas97rd_gaap_loc_cost(int t);

// Loss Recognition Amortization Interest Rate 
double sfas97rd_gaap_loss_rec_amortzn_int_rate(int t);

// Maintenance Expenses Beginning of Month 
double sfas97rd_gaap_maint_exp_bom(int t);

// Maintenance Expenses End of Month 
double sfas97rd_gaap_maint_exp_eom(int t);

// Modco Liability 
double sfas97rd_gaap_modco_liab(int t);

// Modco Liability Increase 
double sfas97rd_gaap_modco_liab_incr(int t);

// Modco Reserve Adjustment 
double sfas97rd_gaap_modco_res_adj(int t);

// Persistency Bonus/Refunds 
double sfas97rd_gaap_persist_bon_ref(int t);

// Policy Loans 
double sfas97rd_gaap_pol_loan(int t);

// Policy Loan Income 
double sfas97rd_gaap_pol_loan_inc(int t);

// Policies In Force Beginning of Month 
double sfas97rd_gaap_policies_b(int t);

// Premium Bonus 
double sfas97rd_gaap_prem_bonus(int t);

// Premium Tax 
double sfas97rd_gaap_prem_tax(int t);

// Reinsurance Refund 
double sfas97rd_gaap_refund(int t);

// YRT Reinsurance Cost 
double sfas97rd_gaap_reins_yrt_cost(int t);

// YRT Reinsurance Cost Accumulation 
double sfas97rd_gaap_reins_yrt_cost_accum(int t);

// YRT Reinsurance Cost Present Value 
double sfas97rd_gaap_reins_yrt_cost_pv(int t);

// Rider Charges 
double sfas97rd_gaap_rider_charges(int t);

// SFAS 133 FIA and IUL Liability 
double sfas97rd_gaap_sfas133_fia_iul_liab(int t);

// SFAS 133 GMAB Liability 
double sfas97rd_gaap_sfas133_gmab_liab(int t);

// SFAS 133 GMIB Liability 
double sfas97rd_gaap_sfas133_gmib_liab(int t);

// SFAS 133 GMWB Liability 
double sfas97rd_gaap_sfas133_gmwb_liab(int t);

// SFAS 133 Liability 
double sfas97rd_gaap_sfas133_liab(int t);

// SFAS 133 Liability Increase 
double sfas97rd_gaap_sfas133_liab_incr(int t);

// SOP 03-1 Additional Liability 
double sfas97rd_gaap_sop031_addl_liab(int t);

// SOP 03-1 Additional Liability Increase 
double sfas97rd_gaap_sop031_addl_liab_incr(int t);

// SOP 03-1 Assessments 
double sfas97rd_gaap_sop031_assess(int t);

// SOP 03-1 Assessments Accumulation 
double sfas97rd_gaap_sop031_assess_accum(int t);

// SOP 03-1 Assessments Present Value 
double sfas97rd_gaap_sop031_assess_pv(int t);

// SOP 03-1 EGP 
double sfas97rd_gaap_sop031_egp(int t);

// SOP 03-1 EGP Accumulation 
double sfas97rd_gaap_sop031_egp_accum(int t);

// SOP 03-1 EGP Present Value 
double sfas97rd_gaap_sop031_egp_pv(int t);

// SOP 03-1 GMDB Benefit Accumulation 
double sfas97rd_gaap_sop031_gmdb_ben_accum(int t);

// SOP 03-1 GMDB Benefit Present Value 
double sfas97rd_gaap_sop031_gmdb_ben_pv(int t);

// SOP 03-1 GMDB Benefit Ratio 
double sfas97rd_gaap_sop031_gmdb_br(int t);

// SOP 03-1 GMDB Benefit Ratio Schedule 
double sfas97rd_gaap_sop031_gmdb_br_sch(int t);

// SOP 03-1 GMDB Liability 
double sfas97rd_gaap_sop031_gmdb_liab(int t);

// SOP 03-1 GMIB Benefit Accumulation 
double sfas97rd_gaap_sop031_gmib_ben_accum(int t);

// SOP 03-1 GMIB Benefit Present Value 
double sfas97rd_gaap_sop031_gmib_ben_pv(int t);

// SOP 03-1 GMIB Benefit Ratio 
double sfas97rd_gaap_sop031_gmib_br(int t);

// SOP 03-1 GMIB Benefit Ratio Schedule 
double sfas97rd_gaap_sop031_gmib_br_sch(int t);

// SOP 03-1 GMIB Liability 
double sfas97rd_gaap_sop031_gmib_liab(int t);

// SOP 03-1 GMWB Benefit Accumulation 
double sfas97rd_gaap_sop031_gmwb_ben_accum(int t);

// SOP 03-1 GMWB Benefit Present Value 
double sfas97rd_gaap_sop031_gmwb_ben_pv(int t);

// SOP 03-1 GMWB Benefit Ratio 
double sfas97rd_gaap_sop031_gmwb_br(int t);

// SOP 03-1 GMWB Benefit Ratio Schedule 
double sfas97rd_gaap_sop031_gmwb_br_sch(int t);

// SOP 03-1 GMWB Liability 
double sfas97rd_gaap_sop031_gmwb_liab(int t);

// SOP 03-1 Persistency Bonus/Refunds 
double sfas97rd_gaap_sop031_pbr(int t);

// SOP 03-1 Persistency Bonus/Refund Accumulation 
double sfas97rd_gaap_sop031_pbr_accum(int t);

// SOP 03-1 Persistency Bonus/Refund Fund Value 
double sfas97rd_gaap_sop031_pbr_fund_val(int t);

// SOP 03-1 Persistency Bonus/Refund Fund Value Accumulation 
double sfas97rd_gaap_sop031_pbr_fund_val_accum(int t);

// SOP 03-1 Persistency Bonus/Refund Fund Value Present Value 
double sfas97rd_gaap_sop031_pbr_fund_val_pv(int t);

// SOP 03-1 Persistency Bonus/Refund Liability 
double sfas97rd_gaap_sop031_pbr_liab(int t);

// SOP 03-1 Persistency Bonus/Refund Liability Amortization 
double sfas97rd_gaap_sop031_pbr_liab_amortzn(int t);

// SOP 03-1 Persistency Bonus/Refund Liability Interest 
double sfas97rd_gaap_sop031_pbr_liab_int(int t);

// SOP 03-1 Persistency Bonus/Refund Liability Schedule 
double sfas97rd_gaap_sop031_pbr_liab_sch(int t);

// SOP 03-1 Persistency Bonus/Refund Present Value 
double sfas97rd_gaap_sop031_pbr_pv(int t);

// SOP 03-1 Persistency Bonus/Refund Units Inforce 
double sfas97rd_gaap_sop031_pbr_units_inf(int t);

// SOP 03-1 ULSG Benefits Accumulation 
double sfas97rd_gaap_sop031_ulsg_ben_accum(int t);

// SOP 03-1 ULSG Benefit Present Value 
double sfas97rd_gaap_sop031_ulsg_ben_pv(int t);

// SOP 03-1 ULSG Benefit Ratio 
double sfas97rd_gaap_sop031_ulsg_br(int t);

// SOP 03-1 ULSG Benefit Ratio Schedule 
double sfas97rd_gaap_sop031_ulsg_br_sch(int t);

// SOP 03-1 ULSG Liability 
double sfas97rd_gaap_sop031_ulsg_liab(int t);

// SOP 03-1 Approximation URL Increase 
double sfas97rd_gaap_sop031_unearn_rev_liab_incr(int t);

// Startup 
virtual double virtual_startup(int t);

// Statutory Reserve Rider 
double sfas97rd_gaap_stat_res_rider(int t);

// ULSG Benefits 
double sfas97rd_gaap_ulsg_ben(int t);

// Unearned Revenue Liability 
double sfas97rd_gaap_unearn_rev_liab(int t);

// Unearned Revenue Liability Accumulation 
double sfas97rd_gaap_unearn_rev_liab_accum(int t);

// Unearned Revenue Liability Amortization 
double sfas97rd_gaap_unearn_rev_liab_amortzn(int t);

// Unearned Revenue Liability Increase 
double sfas97rd_gaap_unearn_rev_liab_incr(int t);

// Unearned Revenue Liability Interest 
double sfas97rd_gaap_unearn_rev_liab_int(int t);

// Unearned Revenue Liability Released 
double sfas97rd_gaap_unearn_rev_liab_released(int t);

// Unearned Revenue Liability Schedule 
double sfas97rd_gaap_unearn_rev_liab_sch(int t);

// Amortization Period 
int  sfas97rd_gaap_amortzn_period();

// Commission Percent Fund Value Ultimate Index 
int  sfas97rd_gaap_comm_pct_fund_ult_index();

// Final Period 
int  sfas97rd_gaap_final_period();

// GAAP Interest Rate 
double  sfas97rd_gaap_gaap_int_rate();

// GAAP Interest Rate Monthly 
double  sfas97rd_gaap_gaap_int_rate_mthly();

// GMIB Definition 
int  sfas97rd_gaap_gmib_defn();

// GMIB SOP 03-1 Flag 
int  sfas97rd_gaap_gmib_sop031_flag();

// GMWB Definition 
int  sfas97rd_gaap_gmwb_defn();

// GMWB SOP 03-1 Flag 
int  sfas97rd_gaap_gmwb_sop031_flag();

// Hedge Allocation Factor 
double  sfas97rd_gaap_hedge_alloc_factor();

// Host Accrual Rate For New Issues 
double  sfas97rd_gaap_host_accrual_rate();

// Loss Recognition Interest Rate 
double  sfas97rd_gaap_loss_rec_int_rate();

// Loss Recognition Interest Rate Monthly 
double  sfas97rd_gaap_loss_rec_int_rate_mthly();

// Loss Recognition Flag 
int  sfas97rd_gaap_loss_recognition_flag();

// PBR Final Period 
int  sfas97rd_gaap_pbr_final_period();

// Premium Term Period 
int  sfas97rd_gaap_prem_term_period();

// Projection Date Adjusted 
xstring  sfas97rd_gaap_proj_date_adj();

// Projection Start Date 
int  sfas97rd_gaap_proj_start_date();

// Projection Start Mth 
int  sfas97rd_gaap_proj_start_mth();

// Projection Start Yr 
int  sfas97rd_gaap_proj_start_yr();

// Reinsurance Flag 
int  sfas97rd_gaap_reins_flag();

// SOP 03-1 Flag 
int  sfas97rd_gaap_sop031_flag();

// Start Period 
int  sfas97rd_gaap_start_period();

// State of World Financial File Path 
xstring  sfas97rd_gaap_state_of_world_financial_file_path();


};
#endif
