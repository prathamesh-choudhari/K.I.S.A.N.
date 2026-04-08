#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "structs.h"

soilData *hash_table[100];

unsigned int hash(char *name)
{
  int length=strlen(name,20);
  unsigned int hash_value=0;
  int c;
  for(int i=0;i<length;i++)
    {
      c=(int)tolower(name[i]);
      hash_value += c*i;
      hash_value = (hash_value*c) % 100;
    }
  return hash_value;
}

void initialise_table_null(void)
{
  for(int i=0;i<100;i++)
    *hash_table = NULL;
}

void load_soil_data(void) {
    FILE *fp = fopen("soil_data.csv", "r");
    if (!fp) { printf("  ERROR: Cannot open soil_data.csv!\n"); return; }
    char line[200];
    fgets(line, 200, fp);
int soil_count=0;
    while (fgets(line, 200, fp) && soil_count < 100) {
        trim(line);
      struct soilData d;
        if (strlen(line) == 0) continue;
       int n = sscanf(line, "%[^,],%[^,],%[^,],%d,%d,%d,%f,%[^,],%s",
            d.state, d.city,
            d.soil_type, &d.N,
            &d.P, &d.K,
            &d.pH, d.best_crop,
            d.season);
        if (n == 9) soil_count++;

      int index = hash(d.city);
      soilData[index]=d;
    }}
    fclose(fp);