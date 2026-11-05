#pragma once

#include "OrderBookEntry.h"
#include "CSVReader.h"

class OrderBook {
    public:
        /* construct using a csv data file */
        OrderBook(std::string filename);
        std::vector<std::string> getKnownProducts();
        std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product, std::string timestamp);
        
        std::string getEarliestTime();
        std::string getNextTime(std::string timestamp);

        void insertOrder(OrderBookEntry& order);
        std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);

        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        static double getLowPrice(std::vector<OrderBookEntry>& orders);

    private:
        std::vector<OrderBookEntry> orders;
};