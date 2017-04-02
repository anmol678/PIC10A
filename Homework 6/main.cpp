/* *************************************************
 Ricardo Salazar, February 23, 2015
 
 Driver for the Rectangle class.
 
 This is a simple program that tests the member
 functions implemented in the file 'rectangle.cpp'
 ************************************************* */

#include <time.h>
#include "rectangle.h"

int ccc_win_main(){
    cwin.coord(-5,10,10,-5);
    
    Rectangle r1(Point(-1,1), 2, 2);
    r1.draw();
    cwin << Message(r1.get_corner(),"r1");
    r1.rotate(45);
    r1.draw();
    cwin << Message(r1.get_corner(),"r2");
    
    Rectangle r2;
    r2.move(5,0);
    r2.draw();
    cwin << Message(r2.get_corner(),"r3");
    
    Rectangle r3 = Rectangle( r2.get_corner() , r2.get_width() , r2.get_height() , 45 );
    r3.move(0,-2);
    r3.draw();
    cwin << Message(r3.get_corner(),"r4");
    
    Rectangle r4 = r3;
    r4.move(0,5);
    r4.rotate( -r4.get_angle() );
    r4.draw();
    cwin << Message(r4.get_corner(),"r5");
    
    r4.resize(3);
    r4.draw();
    cwin << Message(r4.get_corner(),"r6");
    
    Rectangle r5 = Rectangle(Point(-4,-3),4,1);
    r5.draw();
    cwin << Message(r5.get_corner(),"r7");
    
    if ( !( r1<r2) )
        cwin << Message(Point(-4.5,4),"r1>r3");
    if ( r4>r1 )
        cwin << Message(Point(-4.5,3.5),"r1<r6");
    if ( Rectangle(Point(),2,2) >= r5 && r5 <= Rectangle(Point(),2,2)  )
        cwin << Message(Point(-4.5,3),"r2=r7");
    
    cwin << Message(Point(-4.5,2.5),"r2 is rotated");
    cwin << Message(Point(-4.5,2),r1.get_angle());
    cwin << Message(Point(-4.5,1.5),"degrees.");
    
    
    r5 = Rectangle(Point(-4.25,6.5),1,2);
    r5.rotate(-30);
    for ( int i=1; i<12 ; i++ ){
        r5.draw();
        r5.move(1.25,0);
    }
    
    r5 = Rectangle(Point(-4.25,9),1,2);
    for ( int i=1; i<12 ; i++ ){
        Point click = cwin.get_mouse("Cick to continue:");
        r5.rotate(-30);
        r5.draw();
        r5.move(1.25,0);
    }
    
    string dummy = cwin.get_string("Press enter to clear the window.");
    cwin.clear();
    
    return 0;
}
