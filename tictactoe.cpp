//************************************************
// TIC-TAC-TOE GAME
//***********************************************

#include <iostream>
#include <sstream>
using namespace std;

#define NO_WINNER 0
#define DRAW 1
#define PLAYER_1_WINS 3
#define PLAYER_2_WINS 4

class Gamestate {
private:
    int playerWinning = NO_WINNER;
public:
    Gamestate() {};
    int returnGameState() { return playerWinning; }
    void changeGameState(int checkWinner);
};

class Player {
private:
    char marker = '-';
    bool playerTurn = true;
public:
    Player() {};
    Player(char marker) { this->marker = marker; };
    char returnMarkerStyle() { return marker; }
    bool returnPlayerTurn() { return playerTurn; };
    void setPlayerTurn() { this->playerTurn = true; };
    void resetPlayerTurns(Player &player1, Player &player2);
    int placeMarker();
};

class Board {
private:
    char numbersAndPick[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    const char divider = '|';
    const string line = "-------------------";
public:
    Board() {};
    string drawBoard(int playerChoice, char marker, Player* player);
    int checkWinner();
};

int main()
{
    Gamestate gamestate;

    Player player1('x');
    Player player2('o');
    Player* pPlayer1 = &player1; 
    Player* pPlayer2 = &player2;
    cout << "Player 1: " << player1.returnMarkerStyle() << endl << "Player 2: " << player2.returnMarkerStyle() << endl;

    Board board; 
    cout << board.drawBoard(0, '1', pPlayer1) << endl;

    // game loop
    while (gamestate.returnGameState() == NO_WINNER)
    {
        
        if (player1.returnPlayerTurn() == true)
        {
            cout << "Player 1 enter a number to place x: " << flush;
            cout << board.drawBoard(player1.placeMarker(), player1.returnMarkerStyle(), pPlayer1);
        }
        else if (player2.returnPlayerTurn() == true)
        {
            cout << "Player 2 enter a number to place o: " << flush;
            cout << board.drawBoard(player2.placeMarker(), player2.returnMarkerStyle(), pPlayer2);
        }
        else
        {
            player1.resetPlayerTurns(player1, player2);
        }

        gamestate.changeGameState(board.checkWinner());
    }

    if (gamestate.returnGameState() == PLAYER_1_WINS)
    {
        cout << endl << "Player 1 won!" << endl;
    }
    else if (gamestate.returnGameState() == PLAYER_2_WINS)
    {
        cout << endl << "Player 2 won!" << endl;
    }
    else if (gamestate.returnGameState() == DRAW)
    {
        cout << "It's a draw!" << endl;
    }
    else
    {
        cout << "Something went wrong... " << endl;
    }
}

int Player::placeMarker()
{
    int placeMarker;
    cin >> placeMarker;
    if (placeMarker >= 1 && placeMarker <= 9)
    {
        this->playerTurn = false;
        return placeMarker-1;
    }

    else
    {
        cout << endl << "Invalid choice, pick again!" << endl;
        return 10;
    }    
}

void Player::resetPlayerTurns(Player& player1, Player& player2)
{
    player1.playerTurn = true;
    player2.playerTurn = true;
}

string Board::drawBoard(int playerChoice, char marker, Player *player)
{
    stringstream ss;
    
    if (numbersAndPick[playerChoice] != 'x' && numbersAndPick[playerChoice] != 'o')
    {
        numbersAndPick[playerChoice] = marker;
    }
    else
    {
        player->setPlayerTurn();
        cout << endl << "Invalid choice, pick again!" << endl;
    }
    
    ss << endl << line << endl;
    ss << divider << "  " << numbersAndPick[0] << "  " << divider << "  " << numbersAndPick[1] << "  " << divider << "  " << numbersAndPick[2] << "  " << divider << " " << endl;
    ss << line << endl;
    ss << divider << "  " << numbersAndPick[3] << "  " << divider << "  " << numbersAndPick[4] << "  " << divider << "  " << numbersAndPick[5] << "  " << divider << " " << endl;
    ss << line << endl;
    ss << divider << "  " << numbersAndPick[6] << "  " << divider << "  " << numbersAndPick[7] << "  " << divider << "  " << numbersAndPick[8] << "  " << divider << " " << endl;
    ss << line << endl;
    
    return ss.str();
}

int Board::checkWinner()
{
    if (
        (numbersAndPick[0] == 'x' && numbersAndPick[1] == 'x' && numbersAndPick[2] == 'x') ||
        (numbersAndPick[3] == 'x' && numbersAndPick[4] == 'x' && numbersAndPick[5] == 'x') ||
        (numbersAndPick[6] == 'x' && numbersAndPick[7] == 'x' && numbersAndPick[8] == 'x') ||
        (numbersAndPick[0] == 'x' && numbersAndPick[3] == 'x' && numbersAndPick[6] == 'x') ||
        (numbersAndPick[1] == 'x' && numbersAndPick[4] == 'x' && numbersAndPick[7] == 'x') ||
        (numbersAndPick[2] == 'x' && numbersAndPick[5] == 'x' && numbersAndPick[8] == 'x') || 
        (numbersAndPick[0] == 'x' && numbersAndPick[4] == 'x' && numbersAndPick[8] == 'x') ||
        (numbersAndPick[6] == 'x' && numbersAndPick[4] == 'x' && numbersAndPick[2] == 'x')
        )
                {
                    return PLAYER_1_WINS;
                }
    else if (
        (numbersAndPick[0] == 'o' && numbersAndPick[1] == 'o' && numbersAndPick[2] == 'o') ||
        (numbersAndPick[3] == 'o' && numbersAndPick[4] == 'o' && numbersAndPick[5] == 'o') ||
        (numbersAndPick[6] == 'o' && numbersAndPick[7] == 'o' && numbersAndPick[8] == 'o') ||
        (numbersAndPick[0] == 'o' && numbersAndPick[3] == 'o' && numbersAndPick[6] == 'o') ||
        (numbersAndPick[1] == 'o' && numbersAndPick[4] == 'o' && numbersAndPick[7] == 'o') ||
        (numbersAndPick[2] == 'o' && numbersAndPick[5] == 'o' && numbersAndPick[8] == 'o') ||
        (numbersAndPick[0] == 'o' && numbersAndPick[4] == 'o' && numbersAndPick[8] == 'o') ||
        (numbersAndPick[6] == 'o' && numbersAndPick[4] == 'o' && numbersAndPick[2] == 'o')
        )
                {
                    return PLAYER_2_WINS;
                }
    else if (
        (numbersAndPick[0] == 'x' || numbersAndPick[0] == 'o') && 
        (numbersAndPick[1] == 'x' || numbersAndPick[1] == 'o')&&
        (numbersAndPick[2] == 'x' || numbersAndPick[2] == 'o')&&
        (numbersAndPick[3] == 'x' || numbersAndPick[3] == 'o')&&
        (numbersAndPick[4] == 'x' || numbersAndPick[4] == 'o')&&
        (numbersAndPick[5] == 'x' || numbersAndPick[5] == 'o')&&
        (numbersAndPick[6] == 'x' || numbersAndPick[6] == 'o')&&
        (numbersAndPick[7] == 'x' || numbersAndPick[7] == 'o')&&
        (numbersAndPick[8] == 'x' || numbersAndPick[8] == 'o')
        )
                {
        return DRAW;
                }
    else
    {
        return NO_WINNER;
    }

}

void Gamestate::changeGameState(int checkWinner)
{
    this->playerWinning = checkWinner;
}
