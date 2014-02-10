AM_CFLAGS=`pkg-config --cflags glib-2.0` -g -O3 -Wall -D_GNU_SOURCE -I$(top_srcdir)/include
ACLOCAL_AMFLAGS=-I m4

#lib_LTLIBRARIES=libpaydate.la
#libpaydate_la_SOURCES=src/paydate_err.c

include_HEADERS=include/paydate_err.h include/paydate_month.h include/paydate_frequency.h include/paydate_calculator.h
bin_PROGRAMS=paydate_calculator
paydate_calculator_SOURCES=src/main.c src/paydate_err.c
#paydate_calculator_LDADD=@LIBOBJS@

TESTS=$(check_PROGRAMS)
check_PROGRAMS=paydate_err.test
paydate_err_test_SOURCES=tests/paydate_err_test.c src/paydate_err.c include/paydate_err.h

#paydate_err_test_LDADD=@LIBOBJS@
