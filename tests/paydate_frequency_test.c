#include <glib.h>
#include "paydate_frequency.h"
#include "paydate_err.h"

typedef struct {
  paydate_frequency_s *frequency;
} ffixture;

void paydate_frequency_setup(ffixture *ff, gconstpointer test_data)
{
  ff->frequency = paydate_frequency_new(2, PCPaydateFrequency_Week, "2014/01/01");
}

void paydate_frequency_teardown(ffixture *ff, gconstpointer test_data)
{
  paydate_frequency_free(ff->frequency);
}

void check_new(paydate_frequency_s const *frequency)
{
  g_assert_cmpint(frequency->interval, ==, 2);
  g_assert_cmpint(frequency->unit, ==, PCPaydateFrequency_Week);
  g_assert_cmpstr(frequency->starting_date_string, ==, "2014/01/01");
}

void check_validate_ok(paydate_frequency_s *frequency)
{
  paydate_err_s *err = NULL;
  int result = paydate_frequency_validate(frequency, &err);

  g_assert_cmpint(result, >, 0);

  if (err)
  {
    g_test_fail();
    g_test_message("OK validation set err pointer to non-NULL value");
  }
}

void reset_err(paydate_err_s **err)
{
  if (*err)
  {
    paydate_err_free(*err);
    *err = NULL;
  }
}

void check_validate_fail(paydate_frequency_s *frequency)
{
  paydate_err_s *err = NULL;
  int result;

  // Range exception tests
  frequency->interval = 0;
  result = paydate_frequency_validate(frequency, &err);
  g_assert_cmpint(result, ==, 0);
  g_assert_cmpint(err->code, ==, 1001);
  g_assert_cmpstr(err->name, ==, "paydate_frequency.range_exception");

  reset_err(&err);

  frequency->interval = 53;
  result = paydate_frequency_validate(frequency, &err);
  g_assert_cmpint(result, ==, 0);
  g_assert_cmpint(err->code, ==, 1001);
  g_assert_cmpstr(err->name, ==, "paydate_frequency.range_exception");

  frequency->interval = 2;

  reset_err(&err);

  // Unit exception tests
  frequency->unit = 0;
  result = paydate_frequency_validate(frequency, &err);
  g_assert_cmpint(result, ==, 0);
  g_assert_cmpint(err->code, ==, 1002);
  g_assert_cmpstr(err->name, ==, "paydate_frequency.invalid_unit");

  frequency->unit = 1;

  reset_err(&err);

  // Starting date string empty
  char *empty_str;
  asprintf(&empty_str, "%s", "");
  frequency->starting_date_string = empty_str;
  result = paydate_frequency_validate(frequency, &err);
  g_assert_cmpint(result, ==, 0);
  g_assert_cmpint(err->code, ==, 1004);
  g_assert_cmpstr(err->name, ==, "paydate_frequency.empty_data_string");

  reset_err(&err);
}

void test_new(ffixture *ff, gconstpointer ignored)
{
  check_new(ff->frequency);
}

void test_validate_ok(ffixture *ff, gconstpointer ignored)
{
  check_validate_ok(ff->frequency);
}

void test_validate_fail(ffixture *ff, gconstpointer ignored)
{
  check_validate_fail(ff->frequency);
}

int main (int argc, char **argv)
{
  g_test_init(&argc, &argv, NULL);
  g_test_add("/paydate_frequency/new test", ffixture, NULL, paydate_frequency_setup, test_new, paydate_frequency_teardown);
  g_test_add("/paydate_frequency/validate_ok test", ffixture, NULL, paydate_frequency_setup, test_validate_ok, paydate_frequency_teardown);
  g_test_add("/paydate_frequency/validate_fail test", ffixture, NULL, paydate_frequency_setup, test_validate_fail, paydate_frequency_teardown);
  return g_test_run();
}
