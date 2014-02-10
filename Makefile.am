AM_CFLAGS=`pkg-config --cflags glib-2.0` -g -O3 -Wall -D_GNU_SOURCE -I$(top_srcdir)/include
ACLOCAL_AMFLAGS=-I m4

include_HEADERS=include/paydate_err.h include/paydate_month.h include/paydate_frequency.h include/paydate_calculator.h
bin_PROGRAMS=paydate_calculator
paydate_calculator_SOURCES=src/main.c src/paydate_err.c src/paydate_frequency.c

TESTS=$(check_PROGRAMS)
check_PROGRAMS=paydate_err.test paydate_frequency.test
paydate_err_test_SOURCES=tests/paydate_err_test.c src/paydate_err.c include/paydate_err.h
paydate_frequency_test_SOURCES=tests/paydate_frequency_test.c src/paydate_frequency.c include/paydate_frequency.h src/paydate_err.c include/paydate_err.h
