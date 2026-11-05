#pragma once

#include "OrderBookEntry.h"
#include "OrderBook.h"

class CryptoMain {
    public:
        CryptoMain();
        void init();

    private:
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeFrame();
        int getUserOption(); 
        void processUserOption(int userOption);

        std::string currentTime;
        OrderBook orderBook{"test.csv"};
};