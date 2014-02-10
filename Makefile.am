AM_CFLAGS=`pkg-config --cflagO glib-2.0` -g -O3 -Wall -D_GNU_SOURCE
ACLOCAL_AMFLAGS=-I m4

lib_LTLIBRARIES=libpaydate.la
libpaydate_la_SOURCES=src/paydate_err.c

include_HEADERS=include/paydate_err.h include/paydate_month.h include/paydate_frequency.h include/paydate_calculator.h

bin_PROGRAMS=paydate_calculator
paydate_calculator_SOURCES=src/main.c
paydate_calculator_LDADD=libpaydate.la

TESTS=$(check_PROGRAMS)
check_PROGRAMS=paydate_err_test
paydate_err_test_LDADD=libpaydate.la
