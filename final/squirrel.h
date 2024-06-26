//Nina Tseng and Alyssa Shen
//Header File for Swagger Squirrel

#define BLUE al_map_rgb(0, 130, 200)
#define COLOUR al_map_rgb(229, 235, 158)

// Define screen size
const int SCREEN_W = 1840;
const int SCREEN_H = 1020;

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
int printHighScore(int high);
int printIntoFile(int &highScore);
int returnHighScore(int &highScore, int current);
void reprintScreen(int &A, int &P, int &Shi, int &Sho, bool &shirtC, bool &pantsC, bool &shoesC, bool &accC, int &h, int &t);
int printResizedImage (int w, int h, int file);
int printStart(bool &play);
int printEnd(bool &again);
