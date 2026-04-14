#ifndef Structs_h
#define Structs_h

typedef struct{
    char state[20];
    char city[20];
    char type[20];
    char season[20];
    char crop[20];
    int N,P,K;
    float ph;
}soilData;

typedef struct{
    char crop[20];
    float seedCost;
    float expenses;
    float msp;
    float sellingPrice;
    float yield;
}cost;

#endif
