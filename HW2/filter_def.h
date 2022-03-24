#ifndef FILTER_DEF_H_
#define FILTER_DEF_H_

// sobel mask parameters
const int MASK_N = 1;
const int MASK_X = 3;
const int MASK_Y = 3;

// Sobel Filter inner transport addresses
// Used between blocking_transport() & do_filter()
const int Gaussianblur_R_ADDR = 0x00000000;
const int Gaussianblur_RESULT_ADDR = 0x00000004;
const int Gaussianblur_CHECK_ADDR = 0x00000008;

union word {
  int sint;
  unsigned int uint;
  unsigned char uc[4];
};

// Sobel mask
const double mask[MASK_N][MASK_X][MASK_Y] = {{{0.0625, 0.125, 0.0625}, {0.125, 0.25, 0.125}, {0.0625, 0.125, 0.0625}}

                                        };
#endif
