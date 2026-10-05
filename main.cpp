#include <iostream>
#include <string>
#include <vector>

enum class OrderBookType{bid, ask};

class OrderBookEntry {
    public:

        OrderBookEntry( double _price,
                        double _amount,
                        std::string _timestamp,
                        std::string _product,
                        OrderBookType _orderType) :
            price(_price),
            amount(_amount),
            timestamp(_timestamp),
            product(_product),
            orderType(_orderType) {}

        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
};

void printMenu() {
    std::cout << "1: Print help " << std::endl;
    std::cout << "2: Print exchange stats " << std::endl;
    std::cout << "3: Place an ask " << std::endl;
    std::cout << "4: Place a bid " << std::endl;
    std::cout << "5: Print wallet " << std::endl;
    std::cout << "6: Continue " << std::endl;
}

void printHelp() {
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}

void printMarketStats() {
    std::cout << "Market looks good" << std::endl;
}

void enterOffer() {
    std::cout << "Make an offer - enter the amount" << std::endl;
}

void enterBid() {
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void printWallet() {
    std::cout << "Your wallet is empty." << std::endl;
}

void gotoNextTimeFrame() {
    std::cout << "Going to next time frame." << std::endl;
}

int getUserOption() {
    int userOption;

    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption; 
}   

void processUserOption(int userOption) {

    if (userOption < 1 || userOption > 6)
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }

    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterOffer();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        gotoNextTimeFrame();
    }
}

int main() {

    /*
    while(true)
    {
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }
    */   

    std::vector<OrderBookEntry> orders;
    orders.push_back(OrderBookEntry{5319.450228, 0.00020075, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid});

    
    std::cout << "The price is: " << orders[0].price << std::endl;

    return 0;
}