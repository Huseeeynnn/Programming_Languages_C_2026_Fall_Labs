/*
 * week4_1_dynamic_array.c
 * Author: Huseyn
 * Student ID: 251ADB038
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Allocate memory for n integers, read them from the user,
 *   print their sum and average, and then free the memory.
 *
 *   Output must match the format in the Week 4 instructions exactly
 *   (it is checked by the autograder).
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int* arr = NULL;

  printf("Enter number of elements: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid size.\n");
    return 1;
  }

  // Выделяем память под n целых чисел
  arr = malloc(n * sizeof(int));

  // malloc может вернуть NULL, поэтому проверяем указатель до использования
  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  printf("Enter %d integers: ", n);
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      printf("Invalid input.\n");
      // Память уже выделена, поэтому освобождаем её перед выходом
      free(arr);
      return 1;
    }
  }

  // Сумму считаем в long long, чтобы не переполнить int
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  // Приводим к double до деления, иначе среднее будет усечено (7 8 -> 7.00)
  double average = (double)sum / n;

  printf("Sum = %lld\n", sum);
  printf("Average = %.2f\n", average);

  // Каждому успешному malloc соответствует free
  free(arr);

  return 0;
}