#include "../include/Filter.h"
#include <string.h>

unsigned char matrix_average(unsigned char matrix[3][3]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    return sum / 9; 
}

struct Image filter3x3_average(struct Image *image) {
  struct Image filtered_image = *image;
  for (unsigned i = image->w; i < (image->h - 1) * image->w; i++){
    if (i % image->w != 0 && (i + 1) % image->w != 0) {
      unsigned char matrix[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

      matrix[0][0] = image->data[i - image->w - 1];
      matrix[1][0] = image->data[i - 1];
      matrix[2][0] = image->data[i + image->w - 1];

      matrix[0][2] = image->data[i - image->w + 1];
      matrix[1][2] = image->data[i + 1];
      matrix[2][2] = image->data[i + image->w + 1];

      int sum_index = -image->w;
      for (int j = 0; j < 3; j++){
        matrix[j][1] = image->data[i + sum_index];
        sum_index += image->w;
      }

      filtered_image.data[i] = matrix_average(matrix);
    }
  }
  return filtered_image;
}
