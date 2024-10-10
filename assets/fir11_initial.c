#include <stdio.h>

#define N 11
#define SAMPLE_SIZE 1024

typedef int coef_t;
typedef int data_t;
typedef int acc_t;

/*
 * Base FIR routine
 */
void fir(data_t *y, data_t x) {
  coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};
  static data_t shift_reg[N];
  acc_t acc;
  int i;

  acc = 0;
Shift_Accum_Loop:
  for (i = N - 1; i >= 0; i--) {
    if (i == 0) {
      acc += x * c[0];
      shift_reg[0] = x;
    } else {
      shift_reg[i] = shift_reg[i - 1];
      acc += shift_reg[i] * c[i];
    }
  }
  *y = acc;
}

/*
 * Task 1:
 *   modify this function to take advantage of the symmetric coefficients
 */
void fir_mod(data_t *y, data_t x) {
  coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0, 53};
  static data_t shift_reg[N];
  acc_t acc;
  int i;

  acc = 0;
Shift_Accum_Loop:
  for (i = N - 1; i >= 0; i--) {
    if (i == 0) {
      acc += x * c[0];
      shift_reg[0] = x;
    } else {
      shift_reg[i] = shift_reg[i - 1];
      acc += shift_reg[i] * c[i];
    }
  }
  *y = acc;
}

/* Task 2:
 *   write a test that validates the output of your modified code with the
 *   output of the original code, i.e., write a loop that compares the output
 *   of your function with the base function
 */
int main(int argc, char *argv[]) {

  int debug = 0;
  if (argc > 1)
    debug = 1;

  // mod_output should hold the output of fir_mod
  // orig_output should hold the output of fir
  int sample_buf[SAMPLE_SIZE], mod_output[SAMPLE_SIZE],
      orig_output[SAMPLE_SIZE];

  // initialize an input buffer
  for (int i = 0; i < SAMPLE_SIZE; ++i) {
    sample_buf[i] = i % (SAMPLE_SIZE >> 4);
  }

  for (int i = 0; i < SAMPLE_SIZE; ++i) {
    // your code goes here!
  }

  return 0;
}
