#include <iostream>
#include <cassert>
#include "toy.h"

using namespace std;

int main()
{
   Toy toy;

   toy.move();
   assert(toy.getPlaced() == false);
   cout << "Test moving before place method pass\n";

   toy.left();
   assert(toy.getPlaced() == false);
   cout << "Test left before place method pass\n";

   toy.right();
   assert(toy.getPlaced() == false);
   cout << "Test right before place method pass\n";

   toy.report();
   assert(toy.getPlaced() == false);
   cout << "Test report before place method pass\n";

   toy.place("place 7,0,north");
   assert(toy.getPlaced() == false);
   cout << "Invalid x input test pass\n";

   toy.place("place 2,8,north");
   assert(toy.getPlaced() == false);
   cout << "Invalid y input test pass\n";

   toy.place("place 2,2,hello");
   assert(toy.getPlaced() == false);
   cout << "Invalid direction input test pass\n";

   toy.place("place 0,0,west");
   toy.move();
   assert(toy.getX() == 0);
   assert(toy.getY() == 0);
   assert(toy.getF() == WEST);
   assert(toy.getPlaced() == true);
   cout << "Going past negative x axis test pass\n";

   toy.place("place 5,0,east");
   toy.move();
   assert(toy.getX() == 5);
   assert(toy.getY() == 0);
   assert(toy.getF() == EAST);
   assert(toy.getPlaced() == true);
   cout << "Going past positive x axis test pass\n";

   toy.place("place 5,0,south");
   toy.move();
   assert(toy.getX() == 5);
   assert(toy.getY() == 0);
   assert(toy.getF() == SOUTH);
   assert(toy.getPlaced() == true);
   cout << "Going past negative y axis test pass\n";

   toy.place("place 5,5,north");
   toy.move();
   assert(toy.getX() == 5);
   assert(toy.getY() == 5);
   assert(toy.getF() == NORTH);
   assert(toy.getPlaced() == true);
   cout << "Going past positive y axis test pass\n";

   toy.place("place 5,5,north");
   toy.place("place 1,7,east");
   assert(toy.getX() == 5);
   assert(toy.getY() == 5);
   assert(toy.getF() == NORTH);
   assert(toy.getPlaced() == true);
   cout << "Invalid place after a valid place test pass\n";

   toy.place("place 0,0,north");
   toy.move();
   assert(toy.getX() == 0);
   assert(toy.getY() == 1);
   assert(toy.getF() == NORTH);
   assert(toy.getPlaced() == true);
   cout << "Test a pass\n";

   toy.place("place 0,0,north");
   toy.left();
   assert(toy.getX() == 0);
   assert(toy.getY() == 0);
   assert(toy.getF() == WEST);
   assert(toy.getPlaced() == true);
   cout << "Test b pass\n";

   toy.place("place 1,2,east");
   toy.move();
   toy.move();
   toy.left();
   toy.move();
   assert(toy.getX() == 3);
   assert(toy.getY() == 3);
   assert(toy.getF() == NORTH);
   assert(toy.getPlaced() == true);
   cout << "Test c pass\n";

   return 0;
}