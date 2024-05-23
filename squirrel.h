
//Header File

// Define screen size
const int SCREEN_W = 1920;
const int SCREEN_H = 1080;

//Create stucts for the pieces of clothing
struct Pants {
    int value;
};

struct Shirt {
    int value;
};

struct Shoes {
    int value;
};

struct Accessories {
    int value;
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
int addScore(int &total, int shirt, int pants, int shoes, int acc);
int printScore(int total);
void clothingArrays(Pants p[], Shirt s[], Shoes sh[], Accessories ac[]);
void loadGraphics();
int loadText();
int scoreCheck (int highScore);
int printHighScore(int high);

