
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "structs.h"

typedef struct{
    char state[20];
    char city[20];
    char type[20];
    char season[20];
    char crop[20];
    int N,P,K;
    float ph;
}soilData;

soilData soil_array[200];

soilData *hash_table[100];

unsigned int hash(char *name)
{
  int length=strlen(name);
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
    hash_table[i] = NULL;
}

void load_soil_data(void) {
    FILE *fp = fopen("soil_data.csv", "r");
    if (!fp) { printf("  ERROR: Cannot open soil_data.csv!\n"); return; }
    char line[200];
    fgets(line, 200, fp);
int soil_count=0;
    while (fgets(line, 200, fp) && soil_count < 100) {
        trim(line);
      soilData d;
        if (strlen(line) == 0) continue;
       int n = sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%f",
            d.state, d.city,
            d.type, d.season,
            d.crop , &d.N,
            &d.P, &d.K,
            &d.ph);
        if (n == 9)
    {
        int index = hash(d.city);

        while (hash_table[index] != NULL)
            index = (index + 1) % 100;

        soil_array[index] = d;
        hash_table[index] = &soil_array[index];

        soil_count++;
    }

      int index = hash(d.city);
      while(hash_table[index]!=NULL)
      index=(index+1)%100;
      if(hash_table[index]==NULL)
      {
      soil_array[index]= d;
      *hash_table[index]= &soil_array[index];
      }
      
    }
    fclose(fp);