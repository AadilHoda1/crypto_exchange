#pragma once

#include "OrderBookEntry.h"

class CryptoMain {
    public:
        CryptoMain();
        void init();

    private:
        void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterOffer();
        void enterBid();
        void printWallet();
        void gotoNextTimeFrame();
        int getUserOption(); 
        void processUserOption(int userOption);

        std::vector<OrderBookEntry> orders;
};