//Nina Tseng and Alyssa Shen
#include <allegro5/allegro.h>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#define COLOUR al_map_rgb(200, 200, 0)
#include "squirrel.h"

ALLEGRO_DISPLAY *display = nullptr;

//loads pictures and background onto display
void loadGraphics(){
    //print background
    printImage (0, 0, 4);

    //print shirt column
    printImage (95, 160 , 32); //tank top
    printImage (95, 340, 34); //i love acorns
    printImage (95, 515, 36); //i love acorns
    printImage (95, 700, 38); //i love acorns
    //print accesories
    printImage (1710, 170, 10); //black hat
    printImage (1710, 355, 12); //gold chain
    printImage (1710, 545, 14); //pink glasses
    printImage (1710, 725, 16); //flower necklace
    printImage (1720, 875, 18); //rolex
    //print pants
    printImage (270, 170, 20); //yellow pants
    printImage (270, 350, 41); // Green Pants
    printImage (270, 530, 43); // flower Pants
    printImage (270, 710, 45); // cargo
    printImage (270, 890, 47); // blue pants
    //print shoes
    printImage (1535, 170, 22); //air force
    printImage (1535, 365, 24); //blue sandals
    printImage (1535, 530, 26); //black boot
    printImage (1535, 695, 28); //yellow boot
    printImage (1535, 900, 30); //brown birks
    //print squirrel
    printImage (640+80, 260, 8);
    // print restart button
    printImage (634, 756, 5);
}

int loadText(){
        // text
       al_init_font_addon(); // initialize the font addon
       al_init_ttf_addon();// initialize the ttf (True Type Font) addon
       // load the specific font you want
       ALLEGRO_FONT *font = al_load_ttf_font("superLarky.ttf", 40, 0);
       if (!font){
          al_show_native_message_box(display, "Error", "Error", "Could not load comic.ttf", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
       }
       al_draw_text(font, COLOUR, 145, 60, ALLEGRO_ALIGN_CENTRE, "Shirts");
       al_draw_text(font, COLOUR, 320, 60, ALLEGRO_ALIGN_CENTRE, "Pants");
       al_draw_text(font, COLOUR, 1581, 60, ALLEGRO_ALIGN_CENTRE, "Shoes");
       al_draw_text(font, COLOUR, 1756, 60, ALLEGRO_ALIGN_CENTRE, "Others");
        //Flip to display
       al_flip_display();
}

void printImage (int x, int y, int file){
    // declare and initialize image and display
    ALLEGRO_DISPLAY *display = nullptr;
    ALLEGRO_BITMAP *image = nullptr;

	// assign file to image
	if (file == 1){
        image = al_load_bitmap("rainbow2.bmp");
	} else if (file == 2){
        image = al_load_bitmap("redshirt.png");
    } else if (file == 3){
        image = al_load_bitmap("yellowsquare.png");
    } else if (file == 4){
        image = al_load_bitmap("background.png");
    } else if (file == 5){
        image = al_load_bitmap("restart.png");
    } else if (file == 6){
        image = al_load_bitmap("loseScreen.png");
    } else if (file == 7){
        image = al_load_bitmap("winScreen.png");
        // load squirrel
    } else if (file == 8){
        image = al_load_bitmap("finalSquirrel.png");
        //accessories
    } else if (file == 9){
        image = al_load_bitmap("blackHat.png");
    } else if (file == 10){
        image = al_load_bitmap("smallblackHat.png");
    } else if (file == 11){
        image = al_load_bitmap("goldChain.png");
    } else if (file == 12){
        image = al_load_bitmap("smallgoldChain.png");
    } else if (file == 13){
        image = al_load_bitmap("pinkGlasses.png");
    } else if (file == 14){
        image = al_load_bitmap("smallpinkGlasses.png");
    }  else if (file == 15){
        image = al_load_bitmap("flower.png");
    }  else if (file == 16){
        image = al_load_bitmap("smallFlower.png");
    }  else if (file == 17){
        image = al_load_bitmap("rolex.png");
    }   else if (file == 18){
        image = al_load_bitmap("smallRolex.png");
         //pants
    }   else if (file == 19){
        image = al_load_bitmap("Ypants.png");
    }   else if (file == 20){
        image = al_load_bitmap("smallYpants.png");
    }   else if (file == 40){
        image = al_load_bitmap("greenPant.png");
    }   else if (file == 41){
        image = al_load_bitmap("SmallgreenPant.png");
    }   else if (file == 42){
        image = al_load_bitmap("flowerpant.png");
    }   else if (file == 43){
        image = al_load_bitmap("Smallflowerpant.png");
    }   else if (file == 44){
        image = al_load_bitmap("cargopant.png");
    }   else if (file == 45){
        image = al_load_bitmap("smallcargopant.png");
    }   else if (file == 46){
        image = al_load_bitmap("bluepant.png");
    }   else if (file == 47){
        image = al_load_bitmap("smallbluepant.png");
        //shoes
    }   else if (file == 21){
        image = al_load_bitmap("airForce.png");
    }   else if (file == 22){
        image = al_load_bitmap("smallairForce.png");
    }   else if (file == 23){
        image = al_load_bitmap("sandal.png");
    }   else if (file == 24){
        image = al_load_bitmap("smallsandal.png");
    }   else if (file == 25){
        image = al_load_bitmap("blackBoot.png");
    }   else if (file == 26){
        image = al_load_bitmap("smallblackBoot.png");
    }   else if (file == 27){
        image = al_load_bitmap("rainboot.png");
    }   else if (file == 28){
        image = al_load_bitmap("smallrainboot.png");
    }   else if (file == 29){
        image = al_load_bitmap("brown.png");
    }   else if (file == 30){
        image = al_load_bitmap("smallbrown.png");
        //shirt
    }   else if (file == 31){
        image = al_load_bitmap("tanktop.png");
    }   else if (file == 32){
        image = al_load_bitmap("smalltanktop.png");
    }   else if (file == 33){
        image = al_load_bitmap("iloveacorns.png");
    }   else if (file == 34){
        image = al_load_bitmap("smalliloveacorns.png");
    }   else if (file == 35){
        image = al_load_bitmap("pink.png");
    }   else if (file == 36){
        image = al_load_bitmap("smallpink.png");
    }   else if (file == 37){
        image = al_load_bitmap("hawaii.png");
    }   else if (file == 38){
        image = al_load_bitmap("smallhawaii.png");
    }


  	// error message
  	if (!image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      	al_destroy_display(display);
	 }
	// print image based on coordinates given
	al_draw_bitmap(image, x, y, 0);
	// write display to screen
	al_flip_display();
}

//prints out the score to the screen
int printScore(int total){
        //print images of rectangles for the scores
       printImage(1920/2-410, 25, 3);
       // load the specific font you want
       ALLEGRO_FONT *font = al_load_ttf_font("superLarky.ttf", 30, 0);
       if (!font){
          al_show_native_message_box(display, "Error", "Error", "Could not load comic.ttf", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
       }
       al_draw_text(font, COLOUR, 1920/2-200, 25, ALLEGRO_ALIGN_CENTRE, "Current Score");
       al_draw_text(font, COLOUR, 1920/2+80, 25, ALLEGRO_ALIGN_CENTRE, "High Score");
       //print current score
       char str[10];
        sprintf(str, "%d", total);
       al_draw_text(font, COLOUR, 1920/2-203, 73, ALLEGRO_ALIGN_CENTRE, str);
       al_flip_display();
}

//print the highest score from the textfile
int printHighScore(int high){
        //print images of rectangles for the scores
       printImage(1920/2-123, 25, 3);
       // load the specific font you want
       ALLEGRO_FONT *font = al_load_ttf_font("superLarky.ttf", 30, 0);
       if (!font){
          al_show_native_message_box(display, "Error", "Error", "Could not load comic.ttf", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
       }
       al_draw_text(font, COLOUR, 1920/2-200, 25, ALLEGRO_ALIGN_CENTRE, "Current Score");
       al_draw_text(font, COLOUR, 1920/2+80, 25, ALLEGRO_ALIGN_CENTRE, "High Score");
       //print current score
       char str[10];
        sprintf(str, "%d", high);
       al_draw_text(font, COLOUR, 1044, 73, ALLEGRO_ALIGN_CENTRE, str);
       al_flip_display();
}

int returnHighScore(int &highScore, int current){
    if(current > highScore){
        highScore = current;
        return highScore;
    }else{
        return highScore;
    }
}

int printIntoFile(int &highScore){
    FILE *fptr;
    fptr = fopen("scoreCheck.txt", "w");
    fprintf(fptr, "%d", highScore);
    fclose(fptr);
}

// rectangle function (increase by 180)
void displayRectangles (){
    // For shirts
    for (int i = 0; i < 5; i ++){
        al_draw_rectangle(90, 150 + (i*180), 200, 260 + (i*180), al_map_rgb(200, 200, 0) , 7);
    }
    // For pants
    for (int i = 0; i < 5; i ++){
        al_draw_rectangle(265, 150 + (i*180), 375, 260 + (i*180), al_map_rgb(200, 200, 0) , 7);
    }
    // For shoes
    for (int i = 0; i < 5; i ++){
        al_draw_rectangle(1530, 150 + (i*180), 1640, 260 + (i*180),al_map_rgb(200, 200, 0) , 7);
    }
    // For Accessories
    for (int i = 0; i < 5; i ++){
        al_draw_rectangle(1705, 150 + (i*180), 1815, 260 + (i*180),al_map_rgb(200, 200, 0) , 7);
    }
    //restart rectangle
    al_flip_display();
}

//calculates the score that is achieved by the player
int addScore(int &total, int shirt, int pants, int shoes, int acc){
    total = shirt + pants + shoes + acc;
    return total;
}

void clothingArrays(Pants p[], Shirt s[], Shoes sh[], Accessories ac[]){
    //array for shirts
    for(int i = 0; i < 5; i++){
        if(i == 0)
            s[i].value = 5;
        if(i == 1)
            s[i].value = 100;
        if(i == 2)
            s[i].value = 4;
        if(i == 3)
            s[i].value = 12;
        if(i == 4)
            s[i].value = 55;
    }
    //array for shoes
    for(int i = 0; i < 5; i++){
        if(i == 0)
            sh[i].value = 3;
        if(i == 1)
            sh[i].value = 88;
        if(i == 2)
            sh[i].value = 77;
        if(i == 3)
            sh[i].value = 13;
        if(i == 4)
            sh[i].value = 10;
    }
    //array for pants
    for(int i = 0; i < 5; i++){
        if(i == 0)
            p[i].value = 90;
        if(i == 1)
            p[i].value = 34;
        if(i == 2)
            p[i].value = 24;
        if(i == 3)
            p[i].value = 10;
        if(i == 4)
            p[i].value = 78;
    }
    //array for accessories
    for(int i = 0; i < 5; i++){
        if(i == 0)
            ac[i].value = 1;
        if(i == 1)
            ac[i].value = 36;
        if(i == 2)
            ac[i].value = 28;
        if(i == 3)
            ac[i].value = 48;
        if(i == 4)
            ac[i].value = 58;
    }
}

void reprintScreen(int &A, int &P, int &Shi, int &Sho, bool &shirtC, bool &pantsC, bool &shoesC, bool &accC, int &highScore, int &totalScore){
        shirtC = false;
        pantsC = false;
        shoesC = false;
        accC = false;
        A = 0;
        P = 0;
        Shi = 0;
        Sho = 0;
        printf ("yay");
        loadGraphics();
        printHighScore(returnHighScore(highScore, totalScore));
        //scoreCheck (highScore);
        //prints highscore into file
        printIntoFile(highScore);
        FILE *fptr;
        totalScore = 0;
        printScore(addScore(totalScore, Shi, P, Sho, A));
        displayRectangles();
        loadText ();
}

void printStart(){
    al_clear_to_color(COLOUR);
    al_flip_display();
    FILE *fptr;
    fptr = fopen("instructions.txt", "r");
    char str[200];
    fscanf(fptr, "s", str);
    while(fscanf(fptr, "s", str) != nullptr){
        if(strcmp(fscanf(fptr, "s", str), "\n"){
           }
    }
    
    sprintf(str, "%d", total);
    al_draw_text(font, COLOUR, 1920/2-203, 73, ALLEGRO_ALIGN_CENTRE, str);
    
    fclose(fptr);
    
}
