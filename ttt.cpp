#include <iostream>
#include <vector>
#include "ttt_functions_declaration.hpp"

int main() {

    std::cout << " _________________ \n";
    std::cout << "|     WELCOME!    |\n";
    std::cout << "|        TO       |\n";
    std::cout << "|                 |\n";
    std::cout << "|   TIC|   | O    |\n";
    std::cout << "|   ---|---|---   |\n";
    std::cout << "|      |TAC|      |\n";
    std::cout << "|   ---|---|---   |\n";
    std::cout << "|    X |   |TOE   |\n";
    std::cout << "|_________________|\n";

    std::cout << "\n";
    std::cout << "    THE RULES:\n";
    std::cout << "    ----------\n";
    std::cout << "1) The game is played on a grid that's 3 squares by 3 squares.\n";
    std::cout << "2) Player 1 are X, Player 2 is O.\n";
    std::cout << "3) The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n";
    std::cout << "4) When all 9 squares are full, the game is over.\n";

    char end = 'Y';
    std::cout << "\n Play any key to start!!!\n";
    std::cin.ignore();

    while(end == 'Y') {

        game();

        bool flag = false;

        while(!flag) {

            std::cout << "\n Do you want to play another game?(Y/N)\n ";
            std::cin >> end;

            if (end == 'Y' || end == 'N') {

                flag = true;
            }
            else {

                std::cout << "Invalid key Press Y or N!!";

            }
            
        }

    }

}