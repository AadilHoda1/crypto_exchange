#pragma once

#include <iostream>
#include <vector>

#include "OrderBookEntry.h"

class CSVReader {

    public:
        CSVReader();

        static std::vector<OrderBookEntry> readCSV(std::string csvFilename);
        static std::vector<std::string> tokenise(std::string csvLine, char separator);
        static OrderBookEntry stringstoOBE(std::string price, std::string amount, std::string timestamp, std::string product, OrderBookType orderType);
        
    private:
        static OrderBookEntry stringstoOBE(std::vector<std::string> tokens);
};