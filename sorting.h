#ifndef sorting
#define sorting

void LoadSoilData(void);
void LoadCost(void);
unsigned int hash(char *name);
void initialise_table_null(void);
int hash_lookup_soil(char *city);
int hash_lookup_cost(char *crop);

#endif
