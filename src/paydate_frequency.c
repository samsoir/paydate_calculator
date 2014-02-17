#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "paydate_frequency.h"
#include "paydate_err.h"

#define PC_FREQUENCY_INTERVAL_MAX 53
#define PC_FREQUENCY_INTERVAL_MIN 0

const paydate_frequency PCPaydateFrequency_Week = 1;

paydate_frequency_s *paydate_frequency_new(int interval, int unit, char const *starting_date_string)
{
  paydate_frequency_s *paydate_frequency = malloc(sizeof(paydate_frequency_s));

  if (paydate_frequency)
  {
    paydate_frequency->interval = interval;
    paydate_frequency->unit     = unit;
    asprintf(&(paydate_frequency->starting_date_string), "%s", starting_date_string);
  }

  return paydate_frequency;
}

int paydate_frequency_copy(paydate_frequency_s **destination, paydate_frequency_s *source)
{
  int result = 0;

  if (destination == NULL)
  {
    return result;
  }

  if (source)
  {
    *destination = paydate_frequency_new(source->interval, source->unit, source->starting_date_string);
    result = 1;
  }

  return result;
}

void paydate_frequency_free(paydate_frequency_s *paydate_frequency)
{
  if (paydate_frequency)
  {
    if (paydate_frequency->starting_date_string)
    {
      free(paydate_frequency->starting_date_string);
    }
    free(paydate_frequency);
  }
}

int paydate_frequency_validate(paydate_frequency_s *paydate_frequency, paydate_err_s **err)
{
  int valid = 0;
  int err_code = 1000;
  paydate_err_s *error = NULL;

  if (paydate_frequency)
  {
    if ( ! paydate_frequency_range_valid(paydate_frequency->interval))
    {
      error = paydate_err_new(err_code | 1, "paydate_frequency.range_exception", "Frequency range must be > 0 and < 53");
    }
    else if ( ! paydate_frequency_unit_valid(paydate_frequency->unit))
    {
      error = paydate_err_new(err_code | 1 << 1, "paydate_frequency.invalid_unit", "Unit must be set to PCPaymentFrequency_Week (1)");
    }
    else if ( ! paydate_frequency_starting_date_string_valid(paydate_frequency->starting_date_string))
    {
      error = paydate_err_new(err_code | 1 << 2, "paydate_frequency.empty_data_string", "Date string must be not be empty");
    }
    else
    {
      valid = 1;
    }
  }

  if ( ! valid && ! *err && error)
  {
    *err = error;
  }

  return valid;
}

void paydate_frequency_set_starting_date_string(paydate_frequency_s *paydate_frequency, char const *starting_date_string)
{
  if (paydate_frequency && (paydate_frequency->starting_date_string != starting_date_string))
  {
    free(paydate_frequency->starting_date_string);
    asprintf(&(paydate_frequency->starting_date_string), "%s", starting_date_string);
  }
}

int paydate_frequency_range_valid(int interval)
{
  return (interval > PC_FREQUENCY_INTERVAL_MIN && interval < PC_FREQUENCY_INTERVAL_MAX);
}

int paydate_frequency_unit_valid(int unit)
{
  return (unit == PCPaydateFrequency_Week);
}

int paydate_frequency_starting_date_string_valid(char const *string)
{
  return (strlen(string) > 0);
}
