#include "../include/Filter.h"

unsigned char matrix_average(unsigned char matrix[3][3]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    return sum / 9; 
}

void filter3x3_average(struct Image *image) {
    unsigned char *datacpy = malloc(sizeof(unsigned char) * image->size);
    if (datacpy == NULL) {
      puts("Erro ao alocar memória para a imagem");  
      exit(1);
    }
    memcpy(datacpy, image->data, image->size);
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

      image->data[i] = matrix_average(matrix);
    }
  }
    free(datacpy);
  }
