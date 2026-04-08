#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include "features.h"
#include "globals.h"

void schemes(void) {
    FILE *fp = fopen("schemes.txt", "r");

    if (!fp) { 
        printf("Error: Cannot open schemes.txt!\n"); 
        return; 
    }
    printf("\nGovernment Schemes and Yojanas\n");
    
    char line[Maxline];
    while (fgets(line, Maxline, fp)) {
        printf("%s", line);
    }
    printf("\n");
    fclose(fp);
    press_enter();
}