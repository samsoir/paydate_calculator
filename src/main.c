#include <stdio.h>
#include "paydate_calculator.h"

int main()
{
  pc_execution_mode_t mode = PC_EXECUTION_MODE_MONTH;
  paydate_err_s *err = paydate_err_new(200, "test", "test");
  printf("Hello cruel world!\nExecuting in mode: %i\niError code: %i", mode, err->code);
  return 0;
}
