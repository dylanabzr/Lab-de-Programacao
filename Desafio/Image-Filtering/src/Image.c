#include "../include/Image.h"
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../include/stb_image.h"
#include "../include/stb_image_write.h"

void Image(struct Image* image, int w, int h, int channels){
  image->w = w;
  image->h = h;
  image->channels = channels;
  image->size = w * h * channels;
}

void freeIMG(struct Image *image){
  return stbi_image_free(image->data);
}
bool read(const char *filename, struct Image *image){
  image->data = stbi_load(filename, &(image->w), &(image->h), &(image->channels), 0);
  return image->data != NULL;
}

ImageType getFileType(const char* filename){
  const char *extension = strrchr(filename, '.');
  if (extension != NULL){
    if (!strcmp(extension, ".jpg")) return JPG;
    else if (!strcmp(extension, ".bmp")) return BMP;
  }
  return PNG;
}

bool write(const char *filename, struct Image *image){
  ImageType type = getFileType(filename);
  int success = 0;
  switch(type){
    case PNG:
      success = stbi_write_png(filename, image->w, image->h, image->channels, image->data, image->w * image->channels);
      break;
    case JPG:
      success = stbi_write_jpg(filename, image->w, image->h, image->channels, image->data, 100);
      break;
    case BMP:
      success = stbi_write_bmp(filename, image->w, image->h, image->channels, image->data);
      break;
  }
  return success != 0;
}
