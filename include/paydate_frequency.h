
#ifndef __PAYDATE_FREQUENCY_H__
#define __PAYDATE_FREQUENCY_H__

#include "paydate_err.h"

typedef struct paydate_frequency_s {
  int interval;
  int unit;
  char *starting_date_string;
} paydate_frequency_s;

paydate_frequency_s *paydate_frequency_new(int interval, int unit, char const *starting_date_string);
void paydate_frequency_free(paydate_frequency_s *paydate_frequency);
int paydate_frequency_validate(paydate_frequency_s *paydate_frequency, paydate_err_s **err);

#endif
