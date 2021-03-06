/**
 * Copyright (c) 2012 MIT License by 6.172 Staff
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 **/

#include <stdio.h>
#include "ktiming.h"
#include "./sum.h"

#define ARRAY_SIZE 10


void gen_array(int* array, int size) {
  int i;
  for (i = 0; i < size; i++) {
    array[i] = i;
  }
}

void print_array(int* array, int size) {
  int i;
  printf("[");
  for (i = 0; i < size; i++) {
    if (i == 0) {
      printf("%d", i);
    } else {
      printf(", %d", i);
    }
  }
  printf("]\n");
}

int main(void) {
  int array[ARRAY_SIZE];
    clockmark_t time1 = ktiming_getmark();
    int i;
    for (i = 0; i < 10; i++) {
        gen_array(array, ARRAY_SIZE);
        print_array(array, ARRAY_SIZE);
        sum_array(array, ARRAY_SIZE, 0, ARRAY_SIZE);
    }
    clockmark_t time2 = ktiming_getmark();

    float elapsedf = ktiming_diff_sec(&time1, &time2);
    printf("Elapsed execution time: %f sec\n", elapsedf);

  return 0;
}
