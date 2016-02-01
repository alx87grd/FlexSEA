//****************************************************************************
// MIT Media Lab - Biomechatronics
// Jean-Francois (Jeff) Duval
// jfduval@mit.edu
// 04/2015
//****************************************************************************
// test: Test code
//****************************************************************************

#ifndef INC_TEST_H
#define INC_TEST_H

#ifdef __cplusplus
extern "C" {
#endif

//****************************************************************************
// Include(s)
//****************************************************************************


//****************************************************************************
// Public Function Prototype(s):
//****************************************************************************

void test_code(void);
void test_code_1(void);
void test_code_2(void);
void test_code_plan_manage_comm(void);
void test_code_plan_2x_exec_comm(void);
void test_code_spc2_csea(void);

//****************************************************************************
// Definition(s):
//****************************************************************************

#define TC_PERIOD				25
#define TC_MAX_PWM				750
#define TC_PWM_STEP				1
#define DEMO_1_CYCLES			10

#ifdef __cplusplus
}
#endif

#endif
