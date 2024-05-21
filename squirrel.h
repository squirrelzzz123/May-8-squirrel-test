
// Define screen size
const int SCREEN_W = 1920;
const int SCREEN_H = 1080;
//Declare and initialize variables *SORRY FOR THE GLOBALS

struct Pants {
    int value;
    bool select = false;
};

struct Shirt {
    int value;
    bool select = false;
};

struct Shoes {
    int value;
    bool select = false;
};

struct Accessories {
    int value;
    bool select = false;
};

//'s' stands for squirrel
struct Squirrel{
    Shirt sShirt;
    Pants sPants;
    Shoes sShoes;
    Accessories sAcc;
};

// Prototypes
void printImage (int x, int y, int file);
void displayRectangles ();
int getScore(int &total, int value, Pants p[], Shirt s[], Shoes sh[], Accessories ac[]);
int printScore(int total);
void clothingArrays(Pants p[], Shirt s[], Shoes sh[], Accessories ac[]);


