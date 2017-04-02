/*****************************************************************
 Anmol Jain
 Feb 17, 2016.
 Program that simulates a Monte Carlo roulette
 On average, every game a player loses 0.0126 pesos
 *****************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

enum color_t {RED, BLACK, GREEN};
enum status_t {NORMAL, PRISON1, PRISON2};

const int RUNS = 15000;//global variable

/*****************************************************************
 getColor
    This function returns the color corresponding to the slot
    on the Monte Carlo roulette.
 parameters:
    r
    the random number generated on the Monte Carlo roulette
 returns:
    returns the corresponding color
 *****************************************************************/
color_t getColor(int r)
{
    if (r == 0)
        return GREEN;
    else if (r % 2 == 0)
        return BLACK;
    else
        return RED;
}

/*****************************************************************
 spinRoulette
    This function implements the rules of the game.
 parameters:
    st
    the present status of the bet
 returns:
    returns the fate of the bet - the value returned is
    subsequently added to the total money
 *****************************************************************/
int spinRoulette(status_t& s)
{
    /*
     generates random number representing a possible
     slot in a Monte Carlo roulette and obtains the color
     of the corresponding slot.
     */
    int r = rand() % 37;
    color_t color = getColor(r);
    
    string col;
    if (color == RED)
        col = "Red";
    else if (color == BLACK)
        col = "Black";
    else
        col = "Green";
    
    /*
     Implement rules of the game when 'bet is free'.
     The next stage is decided based on the
     color of the slot where the ball lands:
     - if it lands on GREEN bet goes to prison1
     display the message: "0 Green! Prison."
     - if it lands on BLACK, lose
     display the random number generated, followed by
     the message: " Black! Lose."
     - if it lands on RED, win
     display the random number generated, followed by
     the message: "Red! Win."
     */
    if (s == NORMAL)
    {
        if (color == RED)
        {
            cout << r << " " << col << "! Win." << endl;
            return 1;
        }
        else if (color == BLACK)
        {
            cout << r << " " << col << "! Lose." << endl;
            return -1;
        }
        else
        {
            cout << r << " " << col << "! Prison." << endl;
            s = PRISON1;
            return 0;
        }
    }
    
    /*
     Implement the rules of the game when
     'bet is in prison 1'
     see the assignment description for the
     actual rules I want you to simulate ( set of rules (c) )
     - if it lands on GREEN ...
     display "0 Green ..."
     - if it lands on BLACK ...
     display the random number generated, followed by ...
     - if it lands on RED ...
     display the random number generated, followed by ...
     */
    if (s == PRISON1)
    {
        if (color == RED)
        {
            cout << r << " " << col << "! Win." << endl;
            s = NORMAL;
            return 0;
        }
        else if (color == BLACK)
        {
            cout << r << " " << col << "! Lose." << endl;
            s = NORMAL;
            return -1;
        }
        else
        {
            cout << r << " " << col << "! Double Prison." << endl;
            s = PRISON2;
            return 0;
        }
    }
    
    /*
     Implement the rules of the game when
     'bet is in prison 2'
     see the assignment description for the
     actual rules I want you to simulate ( set of rules (c) )
     - if it lands on GREEN ...
     display "0 Green ..."
     - if it lands on BLACK ...
     display the random number generated, followed by ...
     - if it lands on RED ...
     display the random number generated, followed by ...
     */
    if (s == PRISON2)
    {
        if (color == RED)
        {
            cout << r << " " << col << "! Back to single prison." << endl;
            s = PRISON1;
            return 0;
        }
        else if (color == BLACK)
        {
            cout << r << " " << col << "! Lose." << endl;
            s = NORMAL;
            return -1;
        }
        else
        {
            cout << r << " " << col << "! WIN BIG." << endl;
            s = NORMAL;
            return 684;
        }
    }
   
    return 0;
}

/*****************************************************************
 main 
 *****************************************************************/
int main()
{
    //srand(static_cast<int>(time(0)));
    
    int money = RUNS;
    double average_wl;
    status_t s = NORMAL;
    
    for (int n = 1; n <= RUNS; n++)
        money += spinRoulette(s);
    
    average_wl = static_cast<double>(money - RUNS)/RUNS;
    
    cout << "Money left: " << money << endl
    << "Average win/loss: " << average_wl;
    
    return 0;
}