
#ifndef __PAYDATE_CALCULATOR_H__
#define __PAYDATE_CALCULATOR_H__

#define PC_MAJOR_VERSION    1
#define PC_MINOR_VERSION    0
#define PC_REVISION_VERSION 0

#include "paydate_frequency.h"
#include "paydate_month.h"
#include "paydate_err.h"

#define PC_EXECUTION_MODE_MONTH     1
#define PC_EXECUTION_MODE_FREQUENCY 1 << 1

typedef int pc_execution_mode_t;

typedef struct paydate_argument_s {
  pc_execution_mode_t execution_mode;
  paydate_month_s *day_model;
  paydate_frequency_s *frequency_model;
} paydate_argument_s;

paydate_argument_s *paydate_argument_new();
void paydate_argument_free(paydate_argument_s *paydate_argument);
pc_execution_mode_t paydate_argument_mode(paydate_argument_s *paydate_argument);

#endif
