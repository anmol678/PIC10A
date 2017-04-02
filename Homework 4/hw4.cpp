/*****************************************************************
 Anmol Jain
 Feb 10, 2016.
 This program is essentially a trip planner. The user chooses a 
 series of destinations on the map and the program returns details 
 about the trip such as total distance traveled, distance between 
 cities and other relevant information.
 *****************************************************************/
#include "ccc_win.h"
#include <cmath>

const Point Cuernavaca(0,0), MexicoCity(0,75), Acapulco(-50,-225), Ixtapa(-300,-200), Salamanca(-225,250), Morelia(-250,125), Casitas(300,225); //location of the cities defined as global constants
/*****************************************************************
 drawMap
    This function draws the basic map of central Mexico on the 
    screen.
 *****************************************************************/
void drawMap()
{
    cwin.coord(-550, 550, 550, -700);
    
    cwin << Line(Point(-500,-500),Point(-500,500)) << Line(Point(-500,500),Point(500,500)) << Line(Point(500,500),Point(500,-500)) << Line(Point(-500,-500),Point(500,-500));
  
    for (int i=-400; i<=400; i+=100)
    {
        Line t1(Point(i, 500), Point(i, 490)), t2(Point(i, -500), Point(i, -490)), t3(Point(-500, i), Point(-490, i)), t4(Point(500, i), Point(490, i));
        cwin << t1 << t2 << t3 << t4;
    }
    
    for (int i=-400; i<=400; i+=200)
    {
        cwin << Message(Point(-500, i-5), i)
        << Message(Point(i+1, 495), i);
    }
    
    cwin << Cuernavaca << MexicoCity << Acapulco << Ixtapa << Salamanca << Morelia << Casitas;
    cwin << Message(Cuernavaca, "Cuernavaca") << Message(MexicoCity, "MexicoCity") << Message(Acapulco, "Acapulco") << Message(Ixtapa, "Ixtapa") << Message(Salamanca, "Salamanca") << Message(Morelia, "Morelia") << Message(Casitas, "Casitas");
    cwin << Circle(Cuernavaca, 50) << Circle(MexicoCity, 20);
}

/*****************************************************************
 distanceBetweenCities
 This function calculates the distance between two cities
 selected by the user.
 Parameters:
 p1, p2
 The two points between which the distance is to be
 calculated.
 Returns:
 A double value of the distance between p1 and p2.
 *****************************************************************/
double distanceBetweenCities(Point p1, Point p2)
{
    double p1_x = p1.get_x();
    double p1_y = p1.get_y();
    double p2_x = p2.get_x();
    double p2_y = p2.get_y();
    
    double distance = pow((pow(p1_x - p2_x, 2))+(pow(p1_y - p2_y, 2)),0.5);
    return distance;
}

/*****************************************************************
 drawTruck
    This function draws a truck at every stop and provides basic
    representation of the direction of travel.
 Parameters:
    start, destination
        The start point and the destination point.
 *****************************************************************/
void drawTruck(Point start, Point destination)
{
    double click_x = start.get_x();
    double click_y = start.get_y();
    double destination_x = destination.get_x();
    
    double distance_mexicocity = distanceBetweenCities(destination, MexicoCity)/100;//this is calculated to re-size the truck
    
    //use of if-else in order to determine whether the truck will face east or west
    //all points are multiplied by a constant proportional to the distance to Mexico City in order to resize the truck
    if (click_x > destination_x)
    {
        Point p1(click_x-80*distance_mexicocity,click_y+25*distance_mexicocity), p2(click_x,click_y+25*distance_mexicocity), p3(click_x-100*distance_mexicocity,click_y), p4(click_x,click_y), p5(click_x-100*distance_mexicocity,click_y+17.5*distance_mexicocity), p6(click_x-80*distance_mexicocity,click_y+17.5*distance_mexicocity), p7(click_x-80*distance_mexicocity,click_y), p8(click_x-25*distance_mexicocity,click_y), p9(click_x-80*distance_mexicocity,click_y);
        Line l1(p1,p2), l2(p3,p4), l3(p2,p4), l4(p3,p5), l5(p5,p6), l6(p1,p9);
        Circle c1(p7,7.5*distance_mexicocity), c2(p8, 7.5*distance_mexicocity), c3(p7,6.25*distance_mexicocity), c4(p8,6.25*distance_mexicocity), c5(p7,5*distance_mexicocity), c6(p8,5*distance_mexicocity);
        cwin << l1 << l2 << l3 << l4 << l5 << l6 << c1 << c2 << c3 << c4 << c5 << c6;
    }
   
    else
    {
        Point p1(click_x+80*distance_mexicocity,click_y+25*distance_mexicocity), p2(click_x,click_y+25*distance_mexicocity), p3(click_x+100*distance_mexicocity,click_y), p4(click_x,click_y), p5(click_x+100*distance_mexicocity,click_y+17.5*distance_mexicocity), p6(click_x+80*distance_mexicocity,click_y+17.5*distance_mexicocity), p7(click_x+80*distance_mexicocity,click_y), p8(click_x+25*distance_mexicocity,click_y), p9(click_x+80*distance_mexicocity,click_y);
        Line l1(p1,p2), l2(p3,p4), l3(p2,p4), l4(p3,p5), l5(p5,p6), l6(p1,p9);
        Circle c1(p7,7.5*distance_mexicocity), c2(p8, 7.5*distance_mexicocity), c3(p7,6.25*distance_mexicocity), c4(p8,6.25*distance_mexicocity), c5(p7,5*distance_mexicocity), c6(p8,5*distance_mexicocity);
        cwin << l1 << l2 << l3 << l4 << l5 << l6 << c1 << c2 << c3 << c4 << c5 << c6;
    }
}

/*****************************************************************
 connectCities
    This function draws a line between two cities selected by the
    user.
 Parameters:
    p1, p2
        The two points between which a line is to be drawn.
 *****************************************************************/
void connectCities(Point p1, Point p2)
{
    cwin << p1 << p2 << Line(p1, p2);
}

/*****************************************************************
 distanceToCuernavaca
    This function calculates the distance between Cuernavaca and
    every line on the map.
 Parameters:
    p1, p2
        The two end-points of the line from which distance is to 
        be calculated.
 Returns:
    A double value of the distance between Cuernavaca and the line
    joining p1 and p2.
 *****************************************************************/
double distanceToCuernavaca(Point p1, Point p2)
{
    double distance, t;
    double p1_x = p1.get_x(), p1_y = p1.get_y(), p2_x = p2.get_x(), p2_y = p2.get_y(), Cuernavaca_x = Cuernavaca.get_x(), Cuernavaca_y = Cuernavaca.get_y();
  
    t = (((Cuernavaca_x-p1_x)*(p2_x-p1_x))+((Cuernavaca_y-p1_y)*(p2_y-p1_y)))/((pow((p2_x-p1_x),2))+(pow((p2_y-p1_y),2)));
   
    if (t <= 0)
        distance = pow((pow(Cuernavaca_x-p1_x, 2)+pow(Cuernavaca_y-p1_y, 2)), 0.5);
    else if (t >= 1)
        distance = pow((pow(Cuernavaca_x-p2_x, 2)+pow(Cuernavaca_y-p2_y, 2)), 0.5);
    else
        distance = pow((pow(Cuernavaca_x-p1_x-(t*p2_x)+(t*p1_x), 2)+pow(Cuernavaca_y-p1_y-(t*p2_y)+(t*p1_y), 2)), 0.5);
    
    return distance;
}

/*****************************************************************
 insideMap
    This function determines if a click by the user is inside the 
    map on the screen or not.
 Parameters:
    a
    The point where the user clicked.
 Returns:
    A boolean value - true if point is inside map and false if it
    is not.
 *****************************************************************/
bool insideMap(Point a)
{
    double a_x = a.get_x();
    double a_y = a.get_y();
    
    if (a_x < -500 || a_x > 500 || a_y < -500 || a_y > 500)
        return false;
    else
        return true;
}

/*****************************************************************
 main
 *****************************************************************/
int ccc_win_main()
{
    string response = "y";
    
    while (response == "y")//this loop allows the user to plan a trip multiple times
    {
        cwin.clear();

        drawMap();
        
        Point start = Acapulco;//as all trips start from the city of Acapulco
        double stop_distance = 21, total_distance = 0, distance_Cuernavaca;
        int count = 0, z = 0;
        
        while (stop_distance > 20)//this loop allows the user to keep selecting destinations until he/she clicks within a 20km radius from Mexico City
        {
            Point end = cwin.get_mouse("Click next destination");
            
            if (insideMap(end))//checks if the click made by the user is inside the map or not
            {
                drawTruck(start, end);
                
                stop_distance = distanceBetweenCities(end, MexicoCity);//this variable essentially indicates when to stop the trip. If the distance between the point where the click is made and Mexico City is less than 20km then the loop will not reiterate.
                
                cwin << Message(end, distanceBetweenCities(start, end));
                
                total_distance += distanceBetweenCities(start, end);//cumulative variable - keeps track of the total distance covered
                
                connectCities(start, end);
                
                distance_Cuernavaca = distanceToCuernavaca(start, end);
                if (z >= 1)
                    if (distance_Cuernavaca <= 50)//if the route falls within a 50km radius from Cuernavaca the counter increments
                        count ++;
                
                start = end;
                z++;//keeps track of the total number of times the loop runs
            }
            
            else
                continue;
        }
        
        cwin << Message(Point(-500, -550), "Welcome to Mexico City!") << Message(Point(-500, -600), "Distance traveled (Km) = ")
        << Message(Point(100, -600), total_distance) << Message(Point(-500, -650), "You pass within 50Km of Cuernavaca ")
        << Message(Point(225, -650), count) << Message(Point(270, -650), "times.");
        
        response = cwin.get_string("Continue? (y/n): ");
       
        if (response == "n")
        {
            cwin.clear();
            cwin << Message(Point(-400,0), "Thank you for using my trip planner!");
        }
    }
    
    return 0;
}