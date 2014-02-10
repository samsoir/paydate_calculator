#include <stdlib.h>
#include <stdio.h>
#include "paydate_frequency.h"
#include "paydate_err.h"

const paydate_frequency PCPaydateFrequency_Week = 1;

paydate_frequency_s *paydate_frequency_new(int interval, int unit, char const *starting_date_string)
{
  paydate_frequency_s *paydate_frequency = malloc(sizeof(paydate_frequency_s));

  if (paydate_frequency != NULL)
  {
    paydate_frequency->interval = interval;
    paydate_frequency->unit     = unit;
    asprintf(&(paydate_frequency->starting_date_string), "%s", starting_date_string);
  }

  return paydate_frequency;
}

void paydate_frequency_free(paydate_frequency_s *paydate_frequency)
{
  if (paydate_frequency != NULL)
  {
    if (paydate_frequency->starting_date_string != NULL)
    {
      free(paydate_frequency->starting_date_string);
    }
    free(paydate_frequency);
  }
}

int paydate_frequency_validate(paydate_frequency_s *paydate_frequency, paydate_err_s **err)
{
  return -1;
}
