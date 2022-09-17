#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define SUCCESS true
#define FAIL false

using namespace std;

string printFacing(int f)
{
    if (f == NORTH)
    {
        return "NORTH";
    }
    else if (f == EAST)
    {
        return "EAST";
    }
    else if (f == SOUTH)
    {
        return "SOUTH";
    }
    else
    {
        return "WEST";
    }
}

bool boundsChecker(int x, int y)
{
    if (x < 0 || x > 5)
    {
        return false;
    }
    if (y < 0 || y > 5)
    {
        return false;
    }

    return true;
}

class Toy
{
private:
    int x;
    int y;
    int f;
    bool placed;

public:
    Toy()
    {
        x = 0;
        y = 0;
        f = NORTH;
        placed = false;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getF()
    {
        return f;
    }

    int getPlaced()
    {
        return placed;
    }

    int place(string place)
    {
        string sub = place.substr(6, place.length() - 6);
        string face = sub.substr(4, sub.length() - 4);
        int tempX = (int)sub[0] - 48;
        int tempY = (int)sub[2] - 48;

        if (!boundsChecker(tempX, tempY))
        {
            return FAIL;
        }

        if (face == "NORTH" || face == "north")
        {
            f = NORTH;
        }
        else if (face == "EAST" || face == "east")
        {
            f = EAST;
        }
        else if (face == "SOUTH" || face == "south")
        {
            f = SOUTH;
        }
        else if (face == "WEST" || face == "west")
        {
            f = WEST;
        }
        else
        {
            return FAIL;
        }

        x = tempX;
        y = tempY;
        placed = true;
        return SUCCESS;
    }

    int left()
    {
        if (!placed)
            return FAIL;

        if (f == NORTH)
        {
            f = WEST;
        }
        else if (f == WEST)
        {
            f = SOUTH;
        }
        else if (f == SOUTH)
        {
            f = EAST;
        }
        else
        {
            f = NORTH;
        }

        return SUCCESS;
    }

    int right()
    {
        if (!placed)
            return FAIL;

        if (f == NORTH)
        {
            f = EAST;
        }
        else if (f == WEST)
        {
            f = NORTH;
        }
        else if (f == SOUTH)
        {
            f = WEST;
        }
        else
        {
            f = SOUTH;
        }

        return SUCCESS;
    }

    int move()
    {
        if (!placed)
            return FAIL;

        if (f == NORTH && y < 5)
        {
            y += 1;
        }
        else if (f == WEST && x > 0)
        {
            x -= 1;
        }
        else if (f == SOUTH && y > 0)
        {
            y -= 1;
        }
        else if (f == EAST && x < 5)
        {
            x += 1;
        }
        else
        {
            return FAIL;
        }

        return SUCCESS;
    }

    int report()
    {
        if (!placed)
            return FAIL;
        cout << "Output: " << x << "," << y << "," << printFacing(f) << endl;

        return SUCCESS;
    }

    ~Toy()
    {
        cout << "Program terminated." << endl;
    }
};