#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "structs.h"

soilData soil_array[200];

soilData *hash_table[200];
soilData *hash_table2[200];

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

void LoadSoilData(void) 
{
    FILE *fp = fopen("soil_data.csv", "r");
    if (!fp) { printf("  ERROR: Cannot open soil_data.csv!\n"); return; }
    char line[200];
    fgets(line, 200, fp);
    int soil_count=0;
    while (fgets(line, 200, fp) && soil_count < 200) 
    {
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
    }
    fclose(fp);
}

void LoadCost(void)
{
     FILE *fp = fopen("crop_costs.csv", "r");
    if (!fp) { printf("  ERROR: Cannot open crop_costs.csv!\n"); return; }
    char line[200];
    fgets(line, 200, fp);
    int crop_count=0;
    while(fgets(line,200,fp) && crop_count< 200)
    {
        trim(line);
        cost c;
        if(strlen(line)==0) continue;
        int m=sscanf(line, "%[^,],%f,%f,%f,%f,%f",c.crop, &c.seedCost ,
                         &c.expenses , &c.msp , &c.sellingPrice , &c.yield);
        if(m == 6)
        {
            int index = hash(c.crop);

            while(hash_table2[index] !=NULL)
            index = (index+1)%200;

            cost_array[index] =  c;
            hash_table2[index] = &cost_array[index];
            crop_count++;
        }
    }
    fclose(fp);
}