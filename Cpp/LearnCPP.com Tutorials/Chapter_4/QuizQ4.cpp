#include <iostream>

//Gets a double value from the user
double getUserDouble()
{
    std::cout << "Enter the height of the tower: ";
    
    double value{};
    std::cin >> value;

    return value;
}

/*Write a short program to simulate a ball being dropped off of a tower. To start, the user should be asked for the height of the tower in meters. 
Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start). 
Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds. The ball should not go underneath the ground (height 0).*/
int main()
{
    //constant for earth gravity
    static double GRAVITY_M_PER_S = 9.81;

    //ball height starts at the height of the tower
    double towerHeight{getUserDouble()};
    double ballHeightMeters{towerHeight};

    //initializing values for formula x = .5*a*t^2
    double time{0};
    double acceleration{GRAVITY_M_PER_S};


    //print the height of ball along journey
    while (ballHeightMeters > 0)
    {
        std::cout << "At " << time << " seconds, the ball is at height: " << ballHeightMeters << "meters" << "\n";
        time++;
        
        //formula x = .5*a*t^2
        ballHeightMeters = towerHeight - (.5 * acceleration * (time * time));
    }
    std::cout << "At " << time << " seconds, the ball is on the ground " << '\n';



    return 0;
}