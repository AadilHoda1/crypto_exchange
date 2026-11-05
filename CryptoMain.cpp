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

void CryptoMain::enterAsk() {
    std::cout << "Make an ask - enter the amount: product, price, amount, eg: ETH/BTC, 100, 0.1" << std::endl;
    std::string input;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');

    if(tokens.size() != 3) {
        std::cout << "Bad input: " << input << std::endl;
    }
    else {
        try
        {
            OrderBookEntry obe = CSVReader::stringstoOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask);
            orderBook.insertOrder(obe);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            std::cout << "CryptoMain::enterAsk Bad input" << std::endl;
        }
        
    }

    std::cout << "You typed: " << input << std::endl;
}

void CryptoMain::enterBid() {
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void CryptoMain::printWallet() {
    std::cout << "Your wallet is empty." << std::endl;
}

void CryptoMain::gotoNextTimeFrame() {
    std::cout << "Going to next time frame." << std::endl;
    std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids("ETH/BTC", currentTime);
    std::cout << "Sales: " << sales.size() << std::endl;
    for(OrderBookEntry& sale: sales) {
        std::cout << "Sale price: " << sale.price << ", amount: " << sale.amount << std::endl;
    }
    currentTime = orderBook.getNextTime(currentTime);
}

int CryptoMain::getUserOption() {
    int userOption = 0;

    std::string line;
    std::getline(std::cin, line);
    std::cout << "Type in 1-6" << std::endl;

    try
    {
        userOption = std::stoi(line);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

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
        enterAsk();
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