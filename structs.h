#ifndef Structs_h
#define Structs_h

#define TABLE_SIZE 200

typedef struct{
    char state[20];
    char city[20];
    char type[20];
    char season[20];
    char crop[20];
    int N,P,K;
    float ph;
    int occupied;
}soilData;

typedef struct{
    char crop[20];
    float seedCost;
    float expenses;
    float msp;
    float sellingPrice;
    float yield;
    int occupied;
}cost;

#endif
