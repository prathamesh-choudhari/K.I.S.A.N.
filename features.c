#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include "features.h"
#include "globals.h"

void schemes(void) {
    FILE *fp = fopen("schemes.txt", "r");

    printf("\nGovernment Schemes and Yojanas\n");
    
    char line[100];
    while (fgets(line, 100, fp)) {
        printf("%s", line);
    }
    printf("\n");
    fclose(fp);
    press_enter();
}

void trim(char *s) {
    int len = (int)strlen(s);
    while (len > 0 && (s[len-1]=='\n' || s[len-1]=='\r' || s[len-1]==' '))
        s[--len] = '\0';
}

void flushInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}   

void pressEnter(void) {
    printf("\nPress [Enter] to continue...");
    flush_input();
}

void SateList(void) {
    state_count = 0;
    for (int i = 0; i < soil_count; i++) {
        int found = 0;
        for (int j = 0; j < state_count; j++) {
            if (_stricmp(soilData[i].state, state[j]) == 0) { found = 1; break; }
        }
        if (!found && state_count < MAX_STATES) {
            strcpy(state[state_count], soilData[i].state);
            state_count++;
        }
    }
    char temp[NAME_LEN];
    for (int i = 0; i < Statecount - 1; i++)
        for (int j = 0; j < Statecount - i - 1; j++)
            if (_stricmp(state_list[j], state_list[j+1]) > 0) {
                strcpy(temp, state_list[j]);
                strcpy(state_list[j], state_list[j+1]);
                strcpy(state_list[j+1], temp);
            }
}

int SelectCrop(void) {
    int n;
    ShowCrops();
    printf("Enter crop number:");
    int ret=scanf("%d",&n);
    if(ret==EOF) return -1;
    if(ret!=1) {
        flush_input();
        printf("Invalid input\n");
        return -2;
    }
    flush_input();
    if(n==0) return -1;
    if(n>=1&&n<= Costcount){
        return n - 1;
    }
    printf("Invalid serial number");
    return -2;
}

void showStates(void) {
    printf("\n  SELECT YOUR STATE\n");
    for (int i = 0; i < Statecount; i++)
        printf("  %2d. %s\n", i + 1, state[i]);
    printf("  0. Go back\n");
}