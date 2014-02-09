
#ifndef __PAYDATE_MONTH_H__
#define __PAYDATE_MONTH_H__

#include "paydate_err.h"

typedef struct paydate_month_s {
  int day;
  int year;
} paydate_month_s;

paydate_month_s *paydate_month_new(int day, int year);
void paydate_month_free(paydate_month_s *paydate_month);
int paydate_month_validate(paydate_month_s *paydate_month, paydate_err_s **err);

#endif
