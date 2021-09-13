#include <vector>

void game();
void draw_board (std::vector<std::vector<char>> vect);
std::vector<std::vector<char>>  play(int round, int player, std::vector<std::vector<char>> matrix, char mark);
bool check_win(std::vector<std::vector<char>> matrix);
