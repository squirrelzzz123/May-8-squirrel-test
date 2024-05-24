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
    printImage (0, 0, 4);
    printImage (113, 180, 1);
    printImage (95, 335, 2);
    printImage (95, 515, 2);
    printImage (113, 720, 1);
    printImage (113, 900, 1);
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
          al_show_native_message_box(display, "Error", "Error", "Could not load superLarky.ttf", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
       }
       al_draw_text(font, COLOUR, 145, 60, ALLEGRO_ALIGN_CENTRE, "Shirts");
       al_draw_text(font, COLOUR, 320, 60, ALLEGRO_ALIGN_CENTRE, "Pants");
       al_draw_text(font, COLOUR, 1581, 60, ALLEGRO_ALIGN_CENTRE, "Shoes");
       al_draw_text(font, COLOUR, 1756, 60, ALLEGRO_ALIGN_CENTRE, "Others");

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
//superLarky.ttf
//comic.ttf
int printScore(int total){
        //print images of rectangles for the scores
       printImage(1920/2-410, 25, 3);
       //printImage(1920/2-123, 25, 3);
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
       //print highest score
        //sprintf(str, "%d", high);
       //al_draw_text(font, COLOUR, 1044, 73, ALLEGRO_ALIGN_CENTRE, str);
       al_flip_display();
}

//print the highest score from the textfile
int printHighScore(int high){
        //print images of rectangles for the scores
       //printImage(1920/2-410, 25, 3);
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
       //al_draw_text(font, COLOUR, 1920/2-203, 73, ALLEGRO_ALIGN_CENTRE, str);
       //print highest score
        //sprintf(str, "%d", high);
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
//delete if not needed THIS FUNCTION IS NOT CALLED
//saves the highest score into the textfile
int scoreCheck (int highScore){
    // initialize and open file variable
    FILE * fptr;
    int score2;
    fptr = fopen("scoreCheck.txt", "r");
    fscanf(fptr, "%d", score2);
    //printf("%d", score2);

    // error message
    if (fptr == nullptr) {
	    return 1;
	}

    fscanf(fptr, "%d", score2);
    printf("%d", score2);

    if (highScore > score2){
        score2 = highScore;
        printf ("gottem");
    }
    fclose(fptr);

    //printf("%d ", score2);
    //return score2;
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
    //restart rectangle - delete at the end :)
    al_draw_rectangle(860, 970, 990, 1020, al_map_rgb(200, 200, 0), 7);
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

void printHint (int score){
    if (score < 75){
        // text
       al_init_font_addon(); // initialize the font addon
       al_init_ttf_addon();// initialize the ttf (True Type Font) addon

       // load the specific font you want
       ALLEGRO_FONT *font = al_load_ttf_font("superLarky.ttf", 40, 0);
       if (!font){
          al_show_native_message_box(display, "Error", "Error", "Could not load superLarky.ttf", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       }
       al_draw_text(font, COLOUR, 145, 60, ALLEGRO_ALIGN_CENTRE, "I don't like the colour yellow :(");
    }
}


