#include "fourInArow.h"
#include "BoardGame_Classes.h"
#include <iostream>
using namespace std;

int main(){
    FourInARow<char> board;
    HumanPlayer<char>Player1("player1", 'X');
    RandomplayerIm<char> player2 ('O');

    Player<char>* players[2] = {&Player1, &player2};
    Player1.setBoard(&board);
    player2.setBoard(&board);

    int currentplayerIndex  = 0;
    int x, y;
    cout << " Welcome the four in a Row!\n";
    board.display_board();
    while (!board.game_is_over()){
        cout << players[currentplayerIndex]->getname()<< " (" << players[currentplayerIndex]->getsymbol() << ")'s turn.\n";
        do {
            players[currentplayerIndex]->getmove(x, y);
        } while (!board.update_board(x, y , players[currentplayerIndex]->getsymbol()));
        board.display_board();
        currentplayerIndex = 1 - currentplayerIndex;
    }
    if (board.is_win()){
        cout << players[1- currentplayerIndex] ->getname()<<"win!\n";

    } else {
        cout << "it's a draw\n";
    }
    return 0;
}