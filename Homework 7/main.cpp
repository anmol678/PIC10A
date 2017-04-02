/*****************************************************************
 Anmol Jain
 March 8, 2016.
 This program plays 'siete y medio' (Spanish version of blackjack)
 against you and  keeps a log of the rounds you played against the
 dealer.
 *****************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "cards.h"

using namespace std;

int main() {
    
    ofstream fout;
    fout.open("gamelog.txt"); //Creates gamelog.txt file
    
    Player player = Player(100); //Player object initialized with amount 100
    int count = 0; //Keeps track of the number of games played
    
    do {
        //srand(static_cast<int>(time(0)));
        
        count ++;
      
        //Hand objects for player and dealer are declared
        Hand handPlayer = Hand();
        Hand handDealer = Hand();
        
        int money = player.getMoney();
        int bet = 0;
        char choice;
        
        cout << endl << "You have $" << money << ". "
        << "Enter bet: ";
        cin >> bet; //The bet is input by the player
        
        //If the bet exceeds total money, the player is asked to re-enter the bet
        if (bet > money) {
            cout << "You don't have that much money. Please bet again." << endl;
        }
        
        else {
            fout << "\n-----------------------------------------------" << endl;
            
            fout << "\nGame number: " << count << setw(20) << right << "Money left: $" << player.getMoney()
            << "\nBet: " << bet << endl; //Certain details are written in the gamelog file
            
            do {
                cout << endl << "Your cards:" << endl;
                handPlayer.print(); //The player's cards are displayed
                
                cout << "Your total is " << handPlayer.sum() << ". Do you want another card (y/n)? ";
                cin >> choice; //Total value of cards is displayed and the player is given a choice to draw another card
                
                //If the player declines to draw another card the dealer's cards are displayed and dealer takes the game forward. Subsequently, the total values of player's hand and dealer's hand are compared and it is decided if the player wins or loses the bet.
                if (choice == 'n') {
                    cout << endl << "Dealer's cards: " << endl;
                    handDealer.print();
                    cout << "The dealer's total is " << handDealer.sum() << "." << endl;
                    
                    while (handDealer.sum() < 5.5){//The dealer continues to draw cards till the total value <= 5.5
                        handDealer.drawCard();
                        cout << endl << "New card:" << endl;
                        handDealer.printLast();//The new card drawn is displayed
                        
                        cout << endl << "Dealer's cards: " << endl;
                        handDealer.print();
                        cout << "The dealer's total is " << handDealer.sum() << "." << endl;
                    }
                    
                    //Other details about the game are added to the gamelog file
                    fout << "\nYour cards:" << endl;
                    handPlayer.printLog(fout);
                    fout << "Your total: " << handPlayer.sum() << "." << endl;
                    
                    fout << "\nDealer's cards: " << endl;
                    handDealer.printLog(fout);
                    fout << "Dealer's total is " << handDealer.sum() << "." << endl;
                    
                    //The total values of the dealer's hand and the player's hand are compared
                    //The player loses the bet if he busts
                    if (handPlayer.sum() > 7.5) {
                        cout << endl << "Too bad. You lose " << bet << "." << endl;
                        player.updateMoney(-bet);
                    }
                    
                    //The player wins the bet if he doesn't bust but the dealer busts
                    else if (handPlayer.sum() <= 7.5 && handDealer.sum() > 7.5) {
                        cout << endl << "You win " << bet << "." << endl;
                        player.updateMoney(bet);
                    }
                    
                    //It's a tie if both the player and the dealer don't bust and the values are equal
                    else if (handPlayer.sum() == handDealer.sum()) {
                        cout << endl << "Its a tie." << endl;
                    }
                    
                    //If both the player and the dealer do not bust:
                    else {
                        
                        //The player wins the bet if he closer to 7.5 than the dealer is
                        if (handDealer < handPlayer) {
                            cout << endl << "You win " << bet << "." << endl;
                            player.updateMoney(bet);
                        }
                        
                        //The player loses the bet if the dealer is closer to 7.5 than he is
                        else {
                            cout << endl << "Too bad. You lose " << bet << "." << endl;
                            player.updateMoney(-bet);
                        }
                    }
                }
                
                //If the player chooses to draw another card:
                else {
                    handPlayer.drawCard();
                    cout << endl << "New card:" << endl;
                    handPlayer.printLast();
                }
            } while (choice == 'y');//This loop iterates only if the player opts to draw another card. Otherwise, since the player's turn is over once the dealer draws his cards and values of the two hands are compared the game ends.
            
            //The player cannot play anymore if he runs out of money
            if (player.getMoney() == 0) {
                cout << endl << "You have $0. GAME OVER!\nCome back when you have more money.\n" << endl << "Bye!";
                
                fout << "\n-----------------------------------------------";
                fout.close();
                
                break;
            }
            
            //The player cannot play anymore if the dealer looses 900 or more
            else if (player.getMoney() >= 1000) {
                cout << endl << "Congratulations. You beat the casino!\n" << endl << "Bye!";
                
                fout << "\n-----------------------------------------------";
                fout.close();
                
                break;
            }
            
            //If none of the above scenarios apply a new game begins
            else {
                continue;
            }
        }
    } while (player.getMoney() > 0 && player.getMoney() < 1000); //This loop reiterates while the player hasn't lost all his money and the dealer hasn't lost 900 or more. Upon reiteration, new hands for both the player and the dealer are intialized and a new game begins.
    
    return 0;
}