#include <glib.h>
#include "../include/paydate_err.h"

typedef struct {
  paydate_err_s *err
} efixture;

void paydate_err_setup(efixture *ef, gconstpointer test_data)
{
  ef->err = paydate_err_new(1, "test_error", "test_description");
}

void paydate_err_teardown(efixture *ef, gconstpointer test_data)
{
  paydate_err_free(ef->err);
}

void check_err(paydate_err_s const *err)
{
  g_assert_cmpint(err->code, ==, 1);
  g_assert_cmpstr(err->name, ==, "test_error");
  g_assert_cmpstr(err->description, ==, "test_description");
}

void test_new(efixture *ef, gconstpointer ignored)
{
  check_err(ef->err);
}

int main (int argc, char **argv)
{
  g_test_init(&argc, &argv, NULL);
  g_test_add("/paydate_err/new test", efixture, NULL, paydate_err_setup, test_new, paydate_err_teardown);
  return g_test_run();
}
