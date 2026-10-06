#include <iostream>
#include <string>
#include <vector>

#include "OrderBookEntry.h"
#include "CryptoMain.h"

int main() {
    
    CryptoMain app{};
    app.init();

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