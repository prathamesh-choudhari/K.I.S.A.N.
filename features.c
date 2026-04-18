#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include "features.h"
#include "globals.h"

int str_icmp(const char *a, const char *b) {
    while (*a && *b) {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d) return d;
        a++; b++;
    }
    return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}

void trim(char *s) {
    int len = (int)strlen(s);
    while (len > 0 && (s[len-1]=='\n' || s[len-1]=='\r' || s[len-1]==' '))
        s[--len] = '\0';
}

void flush_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void waitforenter(void) {
    printf("\nPress [Enter] to continue...");
    flush_input();
}

void Schemes(void) {
    FILE *fp = fopen("schemes.txt", "r");
    if (!fp) { printf("ERROR: Cannot open schemes.txt!\n"); return; }
    printf("\nGovernment Schemes and Yojanas\n");
    char line[200];
    while (fgets(line, 200, fp)) {
        printf("%s", line);
    }
    printf("\n");
    fclose(fp);
    waitforenter();
}

void StateList(void) {
    Statecount = 0;
    for (int i = 0; i < Soilcount; i++) {
        int found = 0;
        for (int j = 0; j < Statecount; j++) {
            if (str_icmp(Soildata[i].state, State[j]) == 0) { found = 1; break; }
        }
        if (!found && Statecount < 30) {
            strcpy(State[Statecount], Soildata[i].state);
            Statecount++;
        }
    }
    char temp[20];
    for (int i = 0; i < Statecount - 1; i++)
        for (int j = 0; j < Statecount - i - 1; j++)
            if (str_icmp(State[j], State[j+1]) > 0) {
                strcpy(temp, State[j]);
                strcpy(State[j], State[j+1]);
                strcpy(State[j+1], temp);
            }
}

void showStates(void) {
    printf("\n  SELECT YOUR STATE\n");
    for (int i = 0; i < Statecount; i++)
        printf("  %2d. %s\n", i + 1, State[i]);
    printf("  0. Go back\n");
}

void ShowCrops(void) {
    printf("\nAvailable crops:\n");
    for(int i=0;i<Costcount;i++){
        printf("%2d.%-14s",i+1,Costdata[i].crop);
        if((i+1)%4==0) printf("\n");
    }
    if(Costcount%4!=0) printf("\n");
}

int select_state(void) {
    int num;
    showStates();
    printf("\n  Enter state serial no.: ");
    int ret = scanf("%d", &num);
    if (ret == EOF) return -1;
    if (ret != 1) { flush_input(); printf("  Invalid input.\n"); return -2; }
    flush_input();
    if (num == 0) return -1;
    if (num >= 1 && num <= Statecount) return num - 1;
    printf("  Invalid serial no.\n");
    return -2;
}

int selectcity(int state_idx) {
    char *sel_state = State[state_idx];
    int city_indices[100], city_count = 0;
    for (int i = 0; i < Soilcount; i++)
        if (str_icmp(Soildata[i].state, sel_state) == 0)
            city_indices[city_count++] = i;

    printf("\n  CITIES IN %s\n", sel_state);
    for (int i = 0; i < city_count; i++) {
        int idx = city_indices[i];
        printf("  %2d. %s\n", i+1, Soildata[idx].city);
    }
    printf("  0. Go back\n");

    int num;
    printf("\n  Enter city serial no.: ");
    int ret = scanf("%d", &num);
    if (ret == EOF) return -1;
    if (ret != 1) { flush_input(); printf("  Invalid input.\n"); return -2; }
    flush_input();
    if (num == 0) return -1;
    if (num >= 1 && num <= city_count) return city_indices[num - 1];
    printf("  Invalid serial no.\n");
    return -2;
}

void crop_report(int idx) {
    soilData d = Soildata[idx];
    printf("\n  CROP REPORT: %s, %s\n", d.city, d.state);
    printf("  Soil Type    : %s\n", d.type);
    printf("  pH Level     : %.1f\n", d.ph);
    printf("  Nitrogen (N) : %d kg/ha\n", d.N);
    printf("  Phosphorus(P): %d kg/ha\n", d.P);
    printf("  Potassium(K) : %d kg/ha\n", d.K);
    printf("  Best Crop    : %s\n", d.crop);
    printf("  Season       : %s\n", d.season);

    if (d.N < 70) printf("  Nitrogen LOW (%d). Apply Urea @ 50 kg/ha.\n", d.N);
    else if (d.N < 85) printf("  Nitrogen moderate (%d). Light Urea advised.\n", d.N);
    else printf("  Nitrogen healthy (%d).\n", d.N);

    if (d.P < 30) printf("  Phosphorus LOW (%d). Apply DAP/SSP @ 40 kg/ha.\n", d.P);
    else printf("  Phosphorus adequate (%d).\n", d.P);

    if (d.K < 35) printf("  Potassium LOW (%d). Apply MOP @ 30 kg/ha.\n", d.K);
    else printf("  Potassium adequate (%d).\n", d.K);

    if (d.ph < 5.5) printf("  Soil too ACIDIC (%.1f). Apply lime.\n", d.ph);
    else if (d.ph > 8.0) printf("  Soil too ALKALINE (%.1f). Apply gypsum.\n", d.ph);
    else printf("  pH in acceptable range (%.1f).\n", d.ph);
}

void Recommend(void) {
    printf("\n  CROP RECOMMENDATION\n");
    while (1) {
        int si = select_state();
        if (si == -1) return;
        if (si == -2) continue;
        while (1) {
            int ci = selectcity(si);
            if (ci == -1) break;
            if (ci == -2) continue;
            crop_report(ci);
            waitforenter();
        }
    }
}

int selectcrop(void) {
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
    printf("Invalid serial number\n");
    return -2;
}
