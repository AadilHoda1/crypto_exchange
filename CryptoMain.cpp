#include <iostream>

#include "CryptoMain.h"

CryptoMain::CryptoMain() {}

void CryptoMain::init() {
    loadOrderBook();

    int input;

    while(true) {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void CryptoMain::loadOrderBook() {
     orders.push_back(OrderBookEntry{5319.450228, 0.00020075, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid});
}

void CryptoMain::printMenu() {
    std::cout << "1: Print help " << std::endl;
    std::cout << "2: Print exchange stats " << std::endl;
    std::cout << "3: Place an ask " << std::endl;
    std::cout << "4: Place a bid " << std::endl;
    std::cout << "5: Print wallet " << std::endl;
    std::cout << "6: Continue " << std::endl;
}

void CryptoMain::printHelp() {
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}

void CryptoMain::printMarketStats() {
    std::cout << "We have loaded: " << orders.size() << " entries." << std::endl;
}

void CryptoMain::enterOffer() {
    std::cout << "Make an offer - enter the amount" << std::endl;
}

void CryptoMain::enterBid() {
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void CryptoMain::printWallet() {
    std::cout << "Your wallet is empty." << std::endl;
}

void CryptoMain::gotoNextTimeFrame() {
    std::cout << "Going to next time frame." << std::endl;
}

int CryptoMain::getUserOption() {
    int userOption;

    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption; 
}   

void CryptoMain::processUserOption(int userOption) {

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