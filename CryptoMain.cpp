#include <iostream>

#include "CryptoMain.h"
#include "CSVReader.h"

CryptoMain::CryptoMain() {}

void CryptoMain::init() {
    int input;
    currentTime = orderBook.getEarliestTime();

    while(true) {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void CryptoMain::printMenu() {
    std::cout << "1: Print help " << std::endl;
    std::cout << "2: Print exchange stats " << std::endl;
    std::cout << "3: Place an ask " << std::endl;
    std::cout << "4: Place a bid " << std::endl;
    std::cout << "5: Print wallet " << std::endl;
    std::cout << "6: Continue " << std::endl;

    std::cout << "Current Time is: " << currentTime << std::endl;
}

void CryptoMain::printHelp() {
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}

void CryptoMain::printMarketStats() {
    for(const std::string p: orderBook.getKnownProducts()) {
        std::cout << "Product: " << p << std::endl;

        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Ask seen: " << entries.size() << std::endl;
        std::cout << "Ask max: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Ask min: " << OrderBook::getLowPrice(entries) << std::endl;
    }
    //std::cout << "We have loaded: " << orders.size() << " entries." << std::endl;
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
    currentTime = orderBook.getNextTime(currentTime);
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