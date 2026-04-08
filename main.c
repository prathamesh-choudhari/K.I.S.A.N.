#include<stdio.h>
#include<stdlib.h>

#include"globals.h"
#include"structs.h"
#include"features.h"
#include"sorting.h"

int MainMenu(void){
    int choice;
    printf("\nMain Menu\n");
    printf("Crop Recommendation\n");
    printf("Government Schemes\n");
    printf("Profit Calculation\n");
    printf("Exit\n");
    printf("Enter your choice: ");
    int ret=scanf("%d",&choice);
    if(ret==EOF)return 0;
    if(ret!=1)return 0;
    return choice;
}

int main(void){

LoadSoilData();
StateList();
LoadCost();

SortedPrice(Costdata,Costcount);
while(1){
int choice=MainMenu();
switch(choice){
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







