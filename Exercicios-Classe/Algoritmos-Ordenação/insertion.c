#include <stdio.h>
void insertionSort(int array[], int size) {
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j = i - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main(){
  int teste[] = {7, 6, 7, 9, 0, 1, 2};
  size_t size = sizeof(teste)/sizeof(teste[0]);
  insertionSort(teste, size);
  printArray(teste, size);
}
