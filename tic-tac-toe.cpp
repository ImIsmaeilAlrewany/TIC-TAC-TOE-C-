// This could be a start for a TIC-TAC-TOE real game
// Ismaeil Alrewany

#include <iostream>
#include <ctime>

bool winner(char *spaces, char symbol) {
  int winSpots[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
  for (int i = 0; i < 8; i++) {
    if (spaces[winSpots[i][0]] == spaces[winSpots[i][1]] && spaces[winSpots[i][1]] == spaces[winSpots[i][2]] && spaces[winSpots[i][0]] == symbol) {
      return spaces[winSpots[i][0]] == symbol;
    }
  }
  return false;
}

void computerMove(char *spaces, char computer) {
  int spot;
  srand(time(NULL));
  do {
    spot = rand() % 9;
  } while (spaces[spot] != ' ');
  spaces[spot] = computer;
}

void playerMove(char *spaces, char player) {
  int spot;
  do {
    std::cout << "Enter a spot to place a marker [1-9]: ";
    std::cin >> spot;
    spot--;
  } while (spot < 0 || spot > 8 || spaces[spot] != ' ');
  spaces[spot] = player;
}

void drawBoard(char *spaces) {
  std::cout << "\n     |     |     \n";
  std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  \n";
  std::cout << "_____|_____|_____\n";
  std::cout << "     |     |     \n";
  std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  \n";
  std::cout << "_____|_____|_____\n";
  std::cout << "     |     |     \n";
  std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  \n";
  std::cout << "     |     |     \n\n";
}

void chooseTurn(int &playerTurn) {
  do {
    std::cout << "Choose your turn [1/2]: ";
    std::cin >> playerTurn;
  } while (playerTurn != 1 && playerTurn != 2);
}

void chooseSymbol(char &player, char &computer) {
  do {
    std::cout << "Choose a symbol [x/o]: ";
    std::cin >> player;
    player = tolower(player);
  } while (player != 'x' && player != 'o');
  computer = (player == 'x') ? 'o' : 'x';
}

bool startGame() {
  char play;
  do {
    std::cout << "Start game [y/n]: ";
    std::cin >> play;
    play = tolower(play);
  } while (play != 'y' && play != 'n');
  return play == 'y';
}

int main() {
  char player, computer, spaces[9];
  bool gameOver;
  int playerTurn;

  do {
    std::cout << "***************************************\n";
    std::cout << "*********     TIC-TAC-TOE     *********\n";
    std::cout << "***************************************\n";

    if (!startGame()) break;

    chooseSymbol(player, computer);

    chooseTurn(playerTurn);

    for (int i = 0; i < 9; i++) spaces[i] = ' ';

    gameOver = false;
    for (int turn = 0; turn < 9 && !gameOver; turn++) {
      drawBoard(spaces);

      if ((turn + playerTurn) % 2 != 0) {
        playerMove(spaces, player);
        if (winner(spaces, player)) {
          drawBoard(spaces);
          std::cout << "Player wins!\n";
          gameOver = true;
        }
      } else {
        computerMove(spaces, computer);
        if (winner(spaces, computer)) {
          drawBoard(spaces);
          std::cout << "Computer wins!\n";
          gameOver = true;
        }
      }
    }

    if (!gameOver) {
      drawBoard(spaces);
      std::cout << "It's a tie!\n";
    }
  } while (true);

  return 0;
}