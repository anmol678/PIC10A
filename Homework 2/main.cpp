/*******************************************************
 Anmol Jain (504625831)
 Jan 24, 2016.
 This program accepts item to be purchased along with its 
 quantity and its total cost. It also accepts the 
 exvhange rate for that currency to pesos. The program
 then displays the exchange rate between the entered 
 currency and pesos and the other way round. The cost of
 each unit of item being purchased in both the entered 
 currency and pesos is also displayed.
 *******************************************************/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string item, currency; //these variables store the item and the currency
    int purchase; // stores the quantity of item being purchased
    const int width = 8; //this variable is used to set the width of columns
    double exchangerate, price; //these variables store the exchange rate and the total price of the purchase
    
    cout << "Enter the desired purchase: ";
    cin >> purchase >> item; //accepts the quantity and the item being purchased
    
    cout << "Enter the price: ";
    cin >> price >> currency; //accepts the total price of the purchase and the currency
    
    currency.erase(currency.length()-1,1); //this eliminates the 's' at the end of the entered currency
    int w = (currency+"-to-peso rate").length(); //the width for the second column is calculated using the length of the entered currency
    
    cout << "Enter the exchage rate (in pesos), 1 "+currency+" = ";
    cin >> exchangerate; //the exchange rate in pesos is accepted
    
    cout << fixed << setprecision(2); //this command makes sure that all values displayed have only 2 decimal places
    
    cout << "Currency exchange:\n";
    cout << setw(w) << left << currency+"-to-peso rate" //column aligned to the left
         << setw(width) << right << exchangerate << endl; //column aligned to the right displaying exchange rate in pesos
    cout << setw(w) << left << "peso-to-"+currency+" rate" //column aligned to the left
         << setw(width) << right << 1/exchangerate << endl; //column aligned to the right displaying exchange rate in entered currency

    cout << "Unit prices:\n";
    cout << setw(w) << left << "in "+currency+'s'
         << setw(width) << right << price/purchase << endl; //column aligned to the right displaying unit prices in entered currency
    cout << setw(w) << left << "in pesos"
         << setw(width) << right << (exchangerate*price)/purchase << endl; //column aligned to the right displaying unit prices in entered currency
    
    return 0;
}