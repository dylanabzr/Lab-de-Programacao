#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


typedef enum {
  PNG, JPG, BMP
}ImageType;

struct Image{
  int w, h, channels;
  unsigned char *data;
  size_t size;
};
void freeIMG(struct Image *image);
bool read(const char *filename, struct Image *image);
bool write(const char *filename, struct Image *image);
void Image(struct Image* image, int w, int h, int channels);

