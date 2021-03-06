
#ifndef __PAYDATE_FREQUENCY_H__
#define __PAYDATE_FREQUENCY_H__

#include "paydate_err.h"

typedef int paydate_frequency;
extern const paydate_frequency PCPaydateFrequency_Week;

typedef struct paydate_frequency_s {
  int interval;
  int unit;
  char *starting_date_string;
} paydate_frequency_s;

paydate_frequency_s *paydate_frequency_new(int interval, int unit, char const *starting_date_string);
int paydate_frequency_copy(paydate_frequency_s **destination, paydate_frequency_s *source);
void paydate_frequency_free(paydate_frequency_s *paydate_frequency);
int paydate_frequency_validate(paydate_frequency_s *paydate_frequency, paydate_err_s **err);

void paydate_frequency_set_starting_date_string(paydate_frequency_s *paydate_frequency, char const *starting_date_string);

#endif
