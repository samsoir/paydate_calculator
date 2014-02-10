#include "../include/paydate_err.h"
#include <stdio.h>
#include <stdlib.h>

paydate_err_s *paydate_err_new(int code, char const *name, char const *description)
{
  paydate_err_s *paydate_err = malloc(sizeof(paydate_err_s));

  paydate_err->code = code;
  asprintf(&(paydate_err->name), "%s", name);
  asprintf(&(paydate_err->description), "%s", description);

  return paydate_err;
}

void paydate_err_free(paydate_err_s *paydate_err)
{
  if (paydate_err != NULL)
  {
    free(paydate_err->name);
    free(paydate_err->description);
    free(paydate_err);
  }
}
