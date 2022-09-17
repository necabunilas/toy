#include <iostream>
#include <string>
#include "toy.h"

using namespace std;

int main()
{
    Toy toy;
    string userInput;

    while (userInput != "quit") // Loop until user enters quit
    {

        cout << "Enter command: ";
        getline(cin, userInput);

        if (userInput == "move")
        {
            if (toy.move() == FAIL)
            {
                cout << "Move not valid!" << endl;
            }
        }
        else if (userInput == "left")
        {
            if (toy.left() == FAIL)
            {
                cout << "Toy is not placed yet!" << endl;
            }
        }
        else if (userInput == "right")
        {
            if (toy.right() == FAIL)
            {
                cout << "Toy is not placed yet!" << endl;
            }
        }
        else if (userInput == "report")
        {
            if (toy.report() == FAIL)
            {
                cout << "Toy is not placed yet!" << endl;
            }
        }
        else if (userInput.find("place") != std::string::npos)
        {
            if (toy.place(userInput) == FAIL)
            {
                cout << "Invalid input, try again" << endl;
            }
        }
        else if (userInput == "quit")
        {
            cout << "bye" << endl;
        }
        else
        {
            cout << "invalid command" << endl;
        }
    };

    return 0;
}