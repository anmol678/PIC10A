/*******************************************************
 Anmol Jain
 Jan 29, 2016.
 This program allows the user to play the game of
 Gato or Tic-Tac-Toe endless number of times.
 *******************************************************/
#include "ccc_win.h"

int ccc_win_main()
{
    string response = "y";
  
    while (response == "y")//this loop allows the user to play the game repeatedly till he/she does not wish to play anymore
    {
        cwin.clear();
        
        //The following points and lines are defined to create the grid required to play tic-tac-toe
        Point a(-2.5,7.5), b(2.5,7.5), c(-2.5,-7.5), d(2.5,-7.5), e(7.5,-2.5), f(7.5,2.5), g(-7.5,-2.5), h(-7.5,2.5);
        Line vertical1(a,c), vertical2(b,d), horizontal1(e,g), horizontal2(f,h);
        cwin << vertical1 << vertical2 << horizontal1 << horizontal2;
        
        for (int count=1; count<=9; count++)//this loop makes sure that a particular game stops after 9 clicks by the user
        {
            Point click = cwin.get_mouse("Click on an empty spot!");
            
            double click_x = click.get_x();
            double click_y = click.get_y();
            
            if(count%2 == 0)//displays 'X' if variable count is even
            {
                Point p1(click_x+1,click_y+1), p2(click_x-1,click_y+1), p3(click_x+1,click_y-1), p4(click_x-1,click_y-1);
                Line x1(p1,p4), x2(p2,p3);
                cwin << x1 << x2;
            }
            else//displays a guajolotero bus when variable count is odd (since player who draws the O's begins the game)
            {
                Point p1(click_x-1.5,click_y+0.5), p2(click_x+2,click_y+0.5), p3(click_x-2,click_y-0.5), p4(click_x+2,click_y-0.5), p5(click_x-2,click_y+0.1), p6(click_x-1.5,click_y+0.1), p7(click_x-1.5,click_y-0.5), p8(click_x+1,click_y-0.5), p9(click_x+2,click_y+0.1);
                Line l1(p1,p2), l2(p3,p4), l3(p2,p4), l4(p3,p5), l5(p5,p6), l6(p1,p6), l7(p6,p9);
                Circle c1(p7,0.3), c2(p8, 0.3), c3(p7,0.25), c4(p8,0.25), c5(p7,0.2), c6(p8,0.2);
                cwin << l1 << l2 << l3 << l4 << l5 << l6 << l7 << c1 << c2 << c3 << c4 << c5 << c6;
                //here 'O' is replaced by a guajolotero bus
            }
        }
        
        cwin << Message(Point(-9.8, -8), "Game Over");
        response = cwin.get_string("Do you wish to play again? (y/n): ");//accepts user's response and re-starts game if he/she whishes to play again
    }
    
    return 0;
}






