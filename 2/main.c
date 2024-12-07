

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  FILE *file_ptr = fopen("input.txt", "r");
  if (!file_ptr) {
    return EXIT_FAILURE;
  }
  // between 5-8 characters in the input.txt.
  long *array_pointers[9] = {NULL};
  char *str[24];
  long safe_reports = 0;
  while (fgets(str, sizeof(str), file_ptr)) {
    // one row gotten.
    char *temp = str;
    size_t array_idx = 0;

    char *token = strtok(temp, " ");
    int count = 0;
    while (token != NULL && count <= 8) {
      long number = strtol(token, NULL, 10);
      array_pointers[count] = (long *)malloc(sizeof(long)); // doesn't work.
      if (array_pointers[count] == NULL) {
        printf("allocation failed.");
        return EXIT_FAILURE;
      }
      *array_pointers[count] = number;
      token = strtok(NULL, " ");
      count++;
    }
    size_t print_idx = 0;
    while (array_pointers[print_idx] != NULL) {
      printf("\n%lu ", *array_pointers[print_idx]);
      print_idx++;
    }
    size_t idx = 0;
    if (array_pointers[idx] != NULL && array_pointers[idx + 1] != NULL) {
      long first_val = *array_pointers[idx];
      long second_val = *array_pointers[idx + 1];
      bool expect_increase =
          first_val < second_val; // false if equal, but will fail later.
      idx++;
      bool safe_report = true;
      while (array_pointers[idx] != NULL) {
        long diff = *array_pointers[idx] - *array_pointers[idx - 1];
        if (expect_increase) {
          if (1 <= diff && diff <= 3) {
            safe_report = true;
          } else {
            safe_report = false;
            printf("expected increase, but diff isn't within the allowed diff. "
                   "%ld",
                   diff);
            break;
          }
        }
        if (!expect_increase) {
          if (-3 <= diff && diff <= -1) {
            safe_report = true;
          } else {
            safe_report = false;
            printf("expected decrease, but diff isn't within the allowed diff. "
                   "%ld",
                   diff);

            break;
          }
        }
        idx++;
      }
      // clear the array for old data.
      size_t free_idx = 0;

      while (array_pointers[free_idx] != NULL) {
        free(array_pointers[free_idx]);
        array_pointers[free_idx] = NULL;
        free_idx++;
      }
      if (safe_report) {
        safe_reports++;
      }
    }
  }
  printf("\n#safe reports: %ld", safe_reports);

  return EXIT_SUCCESS;
}
