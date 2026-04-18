#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "structs.h"
#include "globals.h"
#include "features.h"

void Profit(void){
    float area;
    printf("\n  PROFIT CALCULATOR\n");
    while (1)
    {
        int cropindex = selectcrop();
        if (cropindex == -1)
            return;
        if (cropindex == -2)
            continue;

        cost selectedCrop = Costdata[cropindex];

        printf("\n  Enter land area (in acres): ");
        int inputCheck = scanf("%f", &area);
        if (inputCheck == EOF)
            return;
        if (inputCheck != 1 || area <= 0)
        {
            printf("  Invalid input. Please enter a valid area.\n");
            flush_input();
            continue;
        }
        flush_input();

        float seedCostTotal = selectedCrop.seedCost * area;
        float farmingCostTotal = selectedCrop.expenses * area;
        float totalCost = seedCostTotal + farmingCostTotal;

        float totalProduction = selectedCrop.yield * area;

        float revenueMSP = totalProduction * selectedCrop.msp;
        float profitMSP = revenueMSP - totalCost;

        float revenueMarket = totalProduction * selectedCrop.sellingPrice;
        float profitMarket = revenueMarket - totalCost;

        printf("\n  PROFIT REPORT: %s | %.1f Acres\n", selectedCrop.crop, area);
        printf("  Seed Cost Total      : Rs. %.2f\n", seedCostTotal);
        printf("  Farming Cost Total   : Rs. %.2f\n", farmingCostTotal);
        printf("  Total Investment     : Rs. %.2f\n", totalCost);
        printf("  Total Production     : %.2f quintals\n", totalProduction);

        if (selectedCrop.msp > 0)
        {
            printf("  Revenue (MSP)        : Rs. %.2f\n", revenueMSP);
            printf("  Profit (MSP)         : Rs. %.2f %s\n",
                   profitMSP,
                   profitMSP >= 0 ? "[PROFIT]" : "[LOSS]");
        }

        printf("  Revenue (Market)     : Rs. %.2f\n", revenueMarket);
        printf("  Profit (Market)      : Rs. %.2f %s\n",
               profitMarket,
               profitMarket >= 0 ? "[PROFIT]" : "[LOSS]");

        waitforenter();
    }
}
