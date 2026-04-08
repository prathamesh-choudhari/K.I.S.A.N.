void calculateProfit(void) {
    float area, expectedPrice;
    printf("\n  PROFIT CALCULATOR\n");

    while (1) {
        int cropIndex = chooseCrop();
        
        if (cropIndex == -1) return;
        if (cropIndex == -2) continue;

        CropCost crop = cost_db[cropIndex];

        printf("\n  Enter land area (in acres): ");
        int inputCheck = scanf("%f", &area);

        if (inputCheck == EOF) return;

        if (inputCheck != 1 || area <= 0) {
            printf("  Invalid input. Please enter a valid area.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        float seedCostTotal = crop.seed_cost * area;
        float farmingCostTotal = crop.cultivation_cost * area;
        float totalCost = seedCostTotal + farmingCostTotal;

        float totalProduction = crop.yield_per_acre * area;

        float revenueMSP = totalProduction * crop.msp;
        float profitMSP = revenueMSP - totalCost;

        float revenueMarket = totalProduction * crop.market_price;
        float profitMarket = revenueMarket - totalCost;

        printf("\n  PROFIT REPORT: %s | %.1f Acres\n", crop.crop, area);
        printf("  Seed Cost Total      : Rs. %.2f\n", seedCostTotal);
        printf("  Farming Cost Total   : Rs. %.2f\n", farmingCostTotal);
        printf("  Total Investment     : Rs. %.2f\n", totalCost);
        printf("  Total Production     : %.2f quintals\n", totalProduction);

        if (crop.msp > 0) {
            printf("  Revenue (MSP)        : Rs. %.2f\n", revenueMSP);
            printf("  Profit (MSP)         : Rs. %.2f %s\n",
                   profitMSP,
                   profitMSP >= 0 ? "[PROFIT]" : "[LOSS]");
        }

        printf("  Revenue (Market)     : Rs. %.2f\n", revenueMarket);
        printf("  Profit (Market)      : Rs. %.2f %s\n",
               profitMarket,
               profitMarket >= 0 ? "[PROFIT]" : "[LOSS]");

        waitForEnter();
    }
}