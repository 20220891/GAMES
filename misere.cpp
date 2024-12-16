#include <iostream>
#include <string>
#include <cctype>
#include "MisereTicTacToe.h"
using namespace std;

int main(){
  MisereTicTacToeBoard<char> Board;
  MisereTicTacToePlayer<char>player1("player1", 'X');
  MisereTicTacToeRandomPlayer<char>player2('O');

  char current_player = 'X';
  int x, y;
  while (!Board.game_is_over()){
    Board.display_board();
    cout << "currect player: "<< current_player << endl;
    if (current_player == 'X'){
      player1.getmove(x, y);
    }
    else {
      player2.getmove(x, y);
    }
    if (Board.update_board(x, y, current_player)){
      if (Board.is_win()){
        cout << "player "<< (current_player == 'X' ? 'O' : 'X') << "win"<< endl;
        break;
      }
      else if(Board.is_draw()){
        cout << "It's a draw!"<< endl;
        break;
      }
      current_player = (current_player == 'X') ? 'O' : 'X';
    }

  }
  return 0;
}