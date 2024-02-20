/*
 * Copyright (c) 2024 Sujan Parajuli
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*
 * !NOTE: implementation of atof function as a learning purpose.
 * I haven't tested it and it shouldn't be used for any kind of *serious
 * project*
 * */

#ifndef _ATOF_H
#define _ATOF_H

#include <stdio.h>
#define IS_DIGIT(c) (c >= '0' && c <= '9')
#define TO_NUM(c) (c - '0')

#define L_MAX 9223372036854775807

#define L_ABOUT_MAX 9000000000000000000

static double atof(char *);

double atof(char *s) {
  double res = 0.0;

  char signed_bit = 0;

  /*
   * sign of exponent
   * e-xx | e(+)?xx
   * */
  char se = 0;
  int e = 0;
  int ev = 0;

  if ((char)s[0] == '-') {
    signed_bit = 1;
    s++;
  }

  /*
   * basically if there is a leading 0s, skip it to the good part
   * */
  while (*s == '0') {
    s++;
  }

  /*
   *
   * */
  while (IS_DIGIT(*s)) {
    res = (res * 10) + TO_NUM(*s++);
    //
  }

  if (*s == '.') {
    s++;
    do {
      e--;
      res = (res * 10) + TO_NUM(*s++);
      //
    } while (IS_DIGIT(*s));
  }

  if (*s == 'e' || *s == 'E') {
    s++;

    if (*s == '+' || *s == '-') {
      if (*s == '-') {
        se = 1;
      }
      s++;
    }

    do {
      ev = (ev * 10) + TO_NUM(*s++);
    } while (IS_DIGIT(*s));
  }

  e = e + (ev * (!se ? 1 : -1));

  char e_loc = e;

  while (e != 0) {
    if (e < 0) {
      res /= 10.0;
      e++;
    } else if (e > 0) {
      res *= 10.0;
      e--;
    }
  }

  if (signed_bit) {
    res *= -1;
  }
  return res;
}
#endif // !_ATOF_H
