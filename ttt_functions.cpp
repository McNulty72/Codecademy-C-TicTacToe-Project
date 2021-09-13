#include <iostream>
#include <vector>
#include "ttt_functions_declaration.hpp"

    void game() {    
        std::vector<std::vector<char>> matrix(3, std::vector<char>(3, '-'));

        draw_board(matrix);
        
        bool win = false;
        int turn1 = 1;
        int turn2 = 1;
        int player = 1;
        int player2 = 2;
        char player1Mark = 'X';
        char player2Mark = 'O';
        bool player1 = true;
        int winner;

        while (turn1 <=5 && !win) {

            std::cout << std::endl;
            std::cout << "Round " << turn1 << ".\n";

            std::cout << "Player 1 is your turn: \n";
            matrix = play(turn1, player, matrix, player1Mark);
            draw_board(matrix);

            if (turn1 >=3 ) {
                
                win = check_win(matrix);
                winner = 1;

            }
            
            turn1 += 1;

            if (turn2 <=4 && !win) {
                std::cout << "Player 2 is your turn: \n";
                matrix = play(turn2, player2, matrix, player2Mark);
                draw_board(matrix);

                if(turn2 >= 3) {

                    win = check_win(matrix);
                    winner = 2;
                
                }
                player1 = !player1;
                turn2 += 1;

            }

            
        }

        if (!win){

            std::cout << "It's a tie!!!\n\n";
        }
        else{

            std::cout << "Congratulations Player " << winner << " You Win!!!!!\n\n";
        }
    
    }
    
    void draw_board (std::vector<std::vector<char>> vec) {
       
        std::cout << "   0   1   2" << std::endl;
        
        for(int i = 0; i < 3; i++) {

            std::cout << i << " ";

            for(int j = 0; j < 3; j++) {
            
            
                std::cout << " " << vec[i][j] <<" ";
            
                if(j < 2) {

                    std::cout << "|";
                }

            }
            if (i < 2){

                std::cout << std::endl;
                std::cout << "  ---|---|---\n"; 

            }
        
        }

        std::cout << std::endl << std::endl;

    }

    std::vector<std::vector<char>> play(int round, int player, std::vector<std::vector<char>> matrix, char mark) {

        int coor1;
        int coor2;        
        std::cout << "Player " << player << " round: " << round << std::endl;

        bool flag = false;

        while(!flag) {
            
            std::cout << "Choose the row (0,1,2): ";
            std::cin >> coor1;
            std::cout << "Choose the column (0,1,2): ";
            std::cin >> coor2;

            if (coor1 > 2 || coor2 > 2) {

                std::cout << "Invalid choices. Try Again!!\n";

            }
            else {

                if (matrix[coor1][coor2] == '-'){

                    matrix[coor1][coor2] = mark;
                    flag = true;
                }
                else {

                    std::cout << "the position is already occupied. Try another position.";
                }
            }       

        }

        return matrix;
    }

    bool check_win(std::vector<std::vector<char>> board) {

        // Check rows

        if((board[0][0] == board[0][1] && board[0][1] == board[0][2]) || (board[1][0] == board[1][1] && board[1][1] == board[1][2]) || (board[2][0] == board[2][1] && board[2][1] == board[2][2])) {

            return true;
        }
        // Check columns
        else if((board[0][0] == board[1][0] && board[1][0] == board[2][0]) || (board[0][1] == board[1][1] && board[1][1] == board[2][1]) || (board[0][2] == board[1][2] && board[1][2] == board[2][2])) {

            return true;
        }
        // Check diagonals.
        else if((board[0][2] == board[1][1] && board[1][1] == board[2][0]) || (board[0][0] == board[1][1] && board[1][1] == board[2][2])) {

            return true;
        }
        else {

            return false;
        }

    }