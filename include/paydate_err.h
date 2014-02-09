
#ifndef __PAYDATE_ERR_H__
#define __PAYDATE_ERR_H__

typedef struct paydate_err_s {
  int code;
  char *name;
  char *description;
} paydate_err_s;

paydate_err_s *paydate_err_new(int code, char const *name, char const *description);
void paydate_err_free(paydate_err_s *paydate_err);

#endif
