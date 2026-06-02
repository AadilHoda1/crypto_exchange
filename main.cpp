#include <iostream>

int main() {

    while(true)
    {
        std::cout << "1: Print help " << std::endl;
        std::cout << "2: Print exchange stats " << std::endl;
        std::cout << "3: Place an ask " << std::endl;
        std::cout << "4: Place a bid " << std::endl;
        std::cout << "5: Print wallet " << std::endl;
        std::cout << "6: Continue " << std::endl;

        int userOption;
        std::cout << "Type in 1-6" << std::endl;
        std::cin >> userOption;

        if (userOption < 1 || userOption > 6)
        {
            std::cout << "Invalid input" << std::endl;
        }

        if (userOption == 1)
        {
            std::cout << "Help - choose options from the menu" << std::endl;
            std::cout << "and follow the on screen instructions." << std::endl;
        }
        if (userOption == 2)
        {
            std::cout << "2: Print exchange stats " << std::endl;
        }
        if (userOption == 3)
        {
            std::cout << "3: Place an ask " << std::endl;
        }
        if (userOption == 4)
        {
            std::cout << "4: Place a bid " << std::endl;
        }
        if (userOption == 5)
        {
            std::cout << "5: Print wallet " << std::endl;
        }
        if (userOption == 6)
        {
            std::cout << "6: Continue " << std::endl;
        }
    }   

    return 0;
}