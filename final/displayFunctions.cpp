//Nina and Alyssa
//This file contains functions for the display of rectangles, score printing, text loading, and graphics loading.
#include <allegro5/allegro.h>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#define COLOUR al_map_rgb(200, 200, 0)
#include "squirrel.h"

// Display rectangle function (increase by 180)
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

//Function prints out the current score to the screen
int printScore(int total){
        ALLEGRO_DISPLAY *display = nullptr;
        //print images of rectangles for the scores
       printImage(1920/2-410, 25, 3);
       // load the specific font you want
       ALLEGRO_FONT *font = al_load_ttf_font("superLarky.ttf", 30, 0);
       if (!font){
          al_show_native_message_box(display, "Error", "Error", "Could not load comic.ttf", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
       }
       //Text to display
       al_draw_text(font, COLOUR, 1920/2-200, 25, ALLEGRO_ALIGN_CENTRE, "Current Score");
       al_draw_text(font, COLOUR, 1920/2+80, 25, ALLEGRO_ALIGN_CENTRE, "High Score");
       //prints current score
       char str[10];
        sprintf(str, "%d", total);
       al_draw_text(font, COLOUR, 1920/2-203, 73, ALLEGRO_ALIGN_CENTRE, str);
       al_flip_display();
}

//Function prints the highest score recorded onto the display
int printHighScore(int high){
        ALLEGRO_DISPLAY *display = nullptr;
        //print images of rectangles for the scores
       printImage(1920/2-123, 25, 3);
       // load the specific font you want
       ALLEGRO_FONT *font = al_load_ttf_font("superLarky.ttf", 30, 0);
       if (!font){
          al_show_native_message_box(display, "Error", "Error", "Could not load comic.ttf", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
       }
       //display text for high score and current score boxes
       al_draw_text(font, COLOUR, 1920/2-200, 25, ALLEGRO_ALIGN_CENTRE, "Current Score");
       al_draw_text(font, COLOUR, 1920/2+80, 25, ALLEGRO_ALIGN_CENTRE, "High Score");
       //prints highest score
       char str[10];
       //converts score from int into a string for printing
        sprintf(str, "%d", high);
       al_draw_text(font, COLOUR, 1044, 73, ALLEGRO_ALIGN_CENTRE, str);
       al_flip_display();
}

//Function loads text for clothing onto the game screen
int loadText(){
        ALLEGRO_DISPLAY *display = nullptr;
        // text
       al_init_font_addon(); // initialize the font addon
       al_init_ttf_addon();// initialize the ttf (True Type Font) addon
       // load the specific font you want
       ALLEGRO_FONT *font = al_load_ttf_font("superLarky.ttf", 40, 0);
       if (!font){
          al_show_native_message_box(display, "Error", "Error", "Could not load comic.ttf", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
       }
       //Text to display
       al_draw_text(font, COLOUR, 145, 60, ALLEGRO_ALIGN_CENTRE, "Shirts");
       al_draw_text(font, COLOUR, 320, 60, ALLEGRO_ALIGN_CENTRE, "Pants");
       al_draw_text(font, COLOUR, 1581, 60, ALLEGRO_ALIGN_CENTRE, "Shoes");
       al_draw_text(font, COLOUR, 1756, 60, ALLEGRO_ALIGN_CENTRE, "Others");
        //Flip to display
       al_flip_display();
}

//Function loads pictures and background onto display and in proper positions in respective rectangles
void loadGraphics(){
    //print background
    printImage (0, 0, 4);
    //print shirt column
    printImage (95, 160 , 32); //tank top
    printImage (95, 340, 34); //i love acorns
    printImage (95, 515, 36); //pink fluffy
    printImage (95, 700, 38); //Hawaii flower shirt
    printImage (96, 878, 49); //jacket
    //print accesories
    printImage (1710, 170, 10); //black hat
    printImage (1710, 355, 12); //gold chain
    printImage (1710, 545, 14); //pink glasses
    printImage (1710, 725, 16); //flower necklace
    printImage (1720, 875, 18); //Rolex watch
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
    printImage (1535, 900, 30); //brown birkenstocks
    //print squirrel
    printImage (640+80, 260, 8);
    // print restart button
    printImage (634, 756, 5);
}
