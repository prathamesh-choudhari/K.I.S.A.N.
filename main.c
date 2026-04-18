#include <stdio.h>
#include <stdlib.h>

#include "features.h"
#include "globals.h"
#include "sorting.h"
#include "structs.h"

int MainMenu(void) {
  int choice;
  printf("\nMain Menu\n");
  printf("1. Crop Recommendation\n");
  printf("2. Government Schemes\n");
  printf("3. Profit Calculation\n");
  printf("0. Exit\n");
  printf("Enter your choice: ");
  int ret = scanf("%d", &choice);
  if (ret == EOF)
    return 0;
  if (ret != 1) {
    flush_input();
    printf("Invalid input\n");
    return -1;
  }
  flush_input();
  return choice;
}

int main(void) {
  initialise_table_null();
  LoadSoilData();
  LoadCost();
  StateList();
  while (1) {
    int choice = MainMenu();
    switch (choice) {
    case 1:
      Recommend();
      break;
    case 2:
      Schemes();
      break;
    case 3:
      Profit();
      break;
    case 0:
      return 0;
    default:
      printf("Invalid choice\n");
    }
  }
}
