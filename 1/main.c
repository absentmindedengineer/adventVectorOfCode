
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int comparator(const void *lhs, const void *rhs) {
  return (*(int *)lhs - *(int *)rhs);
}

int main(int argc, char *argv[]) {
  FILE *f;
  f = fopen("input.txt", "r");
  if (!f) {
    perror("error reading file");
    return EXIT_FAILURE;
  }
  char str[14];
  size_t file_length = 1000;
  int left_array[file_length];
  int right_array[file_length];
  char pstr[5];
  int left_num, right_num;
  size_t row = 0;

  while (fscanf(f, "%d %d", &left_num, &right_num) == 2) {
    left_array[row] = left_num;
    right_array[row] = right_num;
    row++;
  }
  qsort(left_array, file_length, sizeof(int), comparator);
  qsort(right_array, file_length, sizeof(int), comparator);
  int result = 0;
  for (size_t idx = 0; idx < file_length; idx++) {

    result += abs(left_array[idx] - right_array[idx]);

  }

  printf("part1: result: %d", result);
  printf("\n");
  int numbers = 100000;
  int count_array[100000] = {0};
  int num;
  for (int idx = 0; idx < file_length; idx++) {
    num = right_array[idx];
    count_array[num]++;
  }

  int sum_result = 0;
  int left_array_num;
  for (int idx = 0; idx < file_length; idx++) {
    left_array_num = left_array[idx];
    sum_result += count_array[left_array_num]*left_array_num;
    if (count_array[left_array_num] > 0) {
      printf("\nresult: %d", sum_result);
    }
  }
  fclose(f);
  return EXIT_SUCCESS;
}
