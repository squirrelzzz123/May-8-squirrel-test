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
        image = al_load_bitmap("whiteSquare.jpg");
    } else if (file == 4){
        image = al_load_bitmap("background.png");
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

int getScore(int &total, int value, Pants p[], Shirt s[], Shoes sh[], Accessories ac[]){
    int shirtScore = 0;
    int pantsScore = 0;
    int shoesScore = 0;
    int accScore = 0;
    bool ShirtSelected;
    bool ShoeSelected;
    bool AccSelected;
    bool PantsSelected;
    for(int i = 0; i < 5; i++){
        if()
    }
    total = shirtScore + pantsScore + shoesScore + accScore;
    return total;
}

int printScore(int total){
           // load the specific font you want
       printImage(1920-150, 60, 3);
       ALLEGRO_FONT *font = al_load_ttf_font("comic.ttf", 50, 0);
       if (!font){
          al_show_native_message_box(display, "Error", "Error", "Could not load comic.ttf",
                                        nullptr, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
       }
        char str[10];
        sprintf(str, "%d", total);
       al_draw_text(font, COLOUR, 1920-100, 0, ALLEGRO_ALIGN_CENTRE, "Score");
       //char score[10] = "total";
       al_draw_text(font, COLOUR, 1920-100, 50, ALLEGRO_ALIGN_CENTRE, str);
       al_flip_display();
}

// rectangle function (increase by 180)
void displayRectangles (){

    // For shirts
    for (int i = 0; i < 5; i ++){
        al_draw_rectangle(90, 150 + (i*180), 200, 260 + (i*180), al_map_rgb(200, 200, 0) , 10);
    }
    // For pants
    for (int i = 0; i < 5; i ++){
        al_draw_rectangle(265, 150 + (i*180), 375, 260 + (i*180), al_map_rgb(200, 200, 0) , 10);
    }
    // For shoes
    for (int i = 0; i < 5; i ++){
        al_draw_rectangle(1530, 150 + (i*180), 1640, 260 + (i*180),al_map_rgb(200, 200, 0) , 10);
    }
    // For Accessories
    for (int i = 0; i < 5; i ++){
        al_draw_rectangle(1705, 150 + (i*180), 1815, 260 + (i*180),al_map_rgb(200, 200, 0) , 10);
    }
    al_flip_display();

}

void clothingArrays(Pants p[], Shirt s[], Shoes sh[], Accessories ac[]){
    //array for shirts
    for(int i = 0; i < 5; i++){
        if(i == 0)
            s[i].value = 30;
        if(i == 1)
            s[i].value = 55;
        if(i == 2)
            s[i].value = 77;
        if(i == 3)
            s[i].value = 66;
        if(i == 4)
            s[i].value = 99;
    }
    //array for shoes
    for(int i = 0; i < 5; i++){
        if(i == 0)
            sh[i].value = 1;
        if(i == 1)
            sh[i].value = 2;
        if(i == 2)
            sh[i].value = 3;
        if(i == 3)
            sh[i].value = 4;
        if(i == 4)
            sh[i].value = 5;
    }
    //array for pants
    for(int i = 0; i < 5; i++){
        if(i == 0)
            p[i].value = 6;
        if(i == 1)
            p[i].value = 7;
        if(i == 2)
            p[i].value = 8;
        if(i == 3)
            p[i].value = 9;
        if(i == 4)
            p[i].value = 10;
    }
    //array for accessories
    for(int i = 0; i < 5; i++){
        if(i == 0)
            ac[i].value = 11;
        if(i == 1)
            ac[i].value = 12;
        if(i == 2)
            ac[i].value = 13;
        if(i == 3)
            ac[i].value = 14;
        if(i == 4)
            ac[i].value = 15;
    }
}
