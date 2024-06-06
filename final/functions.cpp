//Nina Tseng and Alyssa Shen
//This file contains functions for displaying images, array value setting, and score keeping.
#include <allegro5/allegro.h>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "squirrel.h"
//Function prints image based on a requested integer
void printImage (int x, int y, int file){
    // declare and initialize image and display
    ALLEGRO_DISPLAY *display = nullptr;
    ALLEGRO_BITMAP *image = nullptr;
	// assign file to image
    if (file == 3){
        image = al_load_bitmap("yellowsquare.png");
    } else if (file == 4){
        image = al_load_bitmap("background.png");
    } else if (file == 5){
        image = al_load_bitmap("restart.png");
    } else if (file == 6){
        image = al_load_bitmap("loseScreen.png");
    } else if (file == 7){
        image = al_load_bitmap("winScreen.png");
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
        image = al_load_bitmap("smallgreenPant.png");
    }   else if (file == 42){
        image = al_load_bitmap("flowerpant.png");
    }   else if (file == 43){
        image = al_load_bitmap("smallflowerpant.png");
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
    }   else if (file == 48){
        image = al_load_bitmap("jacket.png");
    }   else if (file == 49){
        image = al_load_bitmap("smalljacket.png");
        // load squirrel
    } else if (file == 8){
        image = al_load_bitmap("finalSquirrel.png");
    }
  	// error messages if image does not load properly
  	if (!image) {
        printf("%d ", file);
		al_show_native_message_box(display, "Error", "Error", "Failed to load image 1!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
	 }
	// print image based on coordinates given
	al_draw_bitmap(image, x, y, 0);
	// write display to screen
	al_flip_display();
}

//Function returns the high score
int returnHighScore(int &highScore, int current){
    //checks the high score to the current score
    if(current > highScore){
        highScore = current;
        //returns new high score
        return highScore;
    }else{
        //returns old high score
        return highScore;
    }
}

//Function prints the highscore into the textfile
int printIntoFile(int &highScore){
    //declare variable
    FILE *fptr;
    //open file for writing
    fptr = fopen("scoreCheck.txt", "w");
    //write high score into the file
    fprintf(fptr, "%d", highScore);
    //close the file
    fclose(fptr);
}

//Calculates the score that is achieved by the player
int addScore(int &total, int shirt, int pants, int shoes, int acc){
    total = shirt + pants + shoes + acc;
    return total;
}

//Function sets the point value for each piece of clothing
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
