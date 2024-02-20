#include "./atof.h"
#include <assert.h>
#include <stdio.h>

double atof(char *s);

int main() {
  assert(atof("-20") == -20.0);
  assert(atof("0") == 0.0);
  assert(atof("123.45") == (12345.0 / 10.0) / 10.0);
  assert(atof("-0.005") == -0.005);
  assert(atof("3.14e2") == 314.0);
  assert(atof("-2.5e-3") == -0.0025);
  assert(atof("10.0") == 10.0);
  assert(atof("0.0") == 0.0);
  assert(atof("-123.456") == -123.456);
  assert(atof("123.456") == 123.456);
  assert(atof("1e10") == 1e10);
  assert(atof("-1e-5") == -1e-5);
  assert(atof("2.71828") == 2.71828);
  assert(atof("5e3") == 5000.0);
  assert(atof("-8.888e-8") == -8.888e-8);
  assert(atof("42.0") == 42.0);
  assert(atof("-7e6") == -7e6);
  assert(atof("9.87654321") == 9.87654321);
  assert(atof("-1.234e-12") == -1.234e-12);
  assert(atof("1000000000") == 1e9);
  assert(atof("-12345.6789") == -12345.6789);
  assert(atof("0.0") == 0.0);
  assert(atof("-1.23") == -1.23);
  assert(atof("45.678") == 45.678);
  assert(atof("1.234e3") == 1234.0);
  assert(atof("-6.789e-4") == -0.0006789);
  assert(atof("9.99999999") == 9.99999999);
  assert(atof("-1000000") == -1e6);
  assert(atof("7.777e8") == 7.777e8);
  assert(atof("-0.000001") == -1e-6);
  assert(atof("3.141592653589793") == 3.141592653589793);
  assert(atof("2.5e2") == 250.0);
  assert(atof("-123e-2") == -1.23);
  assert(atof("6.022e23") == 6.022e23);
  assert(atof("-1.0") == -1.0);
  assert(atof("0.000000000001") == 1e-12);
  assert(atof("-2.71828e0") == -2.71828);
  assert(atof("987654321.987654321") == 987654321.987654321);
  assert(atof("1.00000000000001") == 1.00000000000001);
  assert(atof("-3.333e-9") == -3.333e-9);
  assert(atof("1234567890") == 1234567890.0);

  printf("All test cases passed!\n");

  return 0;
}
