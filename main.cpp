#include <iostream>
#include <string>
#include <vector>

#include "OrderBookEntry.h"
#include "CryptoMain.h"
#include "CSVReader.h"
#include "Wallet.h"

int main() {
    
    CryptoMain app{};
    app.init();

    /*
    Wallet wallet;
    wallet.insertCurrency("BTC", 10);
    wallet.insertCurrency("USDT", 1000);
    std::cout << "Wallet has BTC " << wallet.containsCurrency("USDT", 10) << std::endl;
    std::cout << wallet.toString() << std::endl;
    wallet.removeCurrency("USDT", 100);
    std::cout << wallet.toString() << std::endl;
    */

    return 0;
}

/*
    while(true)
    {
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }

    std::vector<OrderBookEntry> orders;
    orders.push_back(OrderBookEntry{5319.450228, 0.00020075, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid});

    for(OrderBookEntry order: orders) {
        std::cout << "The price is: " << orders[0].price << std::endl;
    }
*/