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

//Function loads text for clothing onto the game screen
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
       //Text to display
       al_draw_text(font, COLOUR, 145, 60, ALLEGRO_ALIGN_CENTRE, "Shirts");
       al_draw_text(font, COLOUR, 320, 60, ALLEGRO_ALIGN_CENTRE, "Pants");
       al_draw_text(font, COLOUR, 1581, 60, ALLEGRO_ALIGN_CENTRE, "Shoes");
       al_draw_text(font, COLOUR, 1756, 60, ALLEGRO_ALIGN_CENTRE, "Others");
        //Flip to display
       al_flip_display();
}

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

//Function prints out the current score to the screen
int printScore(int total){
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

//Function reprints the game screen entirely after it is changed to a lose or win screen
void reprintScreen(int &A, int &P, int &Shi, int &Sho, bool &shirtC, bool &pantsC, bool &shoesC, bool &accC, int &highScore, int &totalScore){
    //declare and initialize variables
    shirtC = false;
    pantsC = false;
    shoesC = false;
    accC = false;
    A = 0;
    P = 0;
    Shi = 0;
    Sho = 0;
    //Reload everything onto the display
    loadGraphics();
    printHighScore(returnHighScore(highScore, totalScore));
    //Prints highscore into file
    printIntoFile(highScore);
    //reset the current score back to 0
    totalScore = 0;
    //Reload things back onto the display
    printScore(addScore(totalScore, Shi, P, Sho, A));
    displayRectangles();
    loadText ();
}

//Function loads the start/instruction screen and allows user to continue the game by pressing any key on the keyboard.
int printStart(bool &play){
    // Text addons to display text
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon
    ALLEGRO_FONT *font = al_load_ttf_font("superLarky.ttf", 23, 0);
       if (!font){
          al_show_native_message_box(display, "Error", "Error", "Could not load suparLarky.ttf", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
       }
    //clear background to yellow colour
    al_clear_to_color(COLOUR);
    al_flip_display();
    //Declare and initialize variables
    FILE *fptr;
    char str[200];
    int space = 80;
    //open textfile
    fptr = fopen("instructions.txt", "r");
    if(fptr == nullptr){
        printf("file did not open");
    }
    //reads from textfile
    while(fgets(str, 200, fptr) != nullptr){
            printf("%s\n", str); //prints to console to make sure file is reading
            al_draw_text(font, al_map_rgb(0, 0, 0), 1840/2 , space, ALLEGRO_ALIGN_CENTRE, str); //prints to display
            //displays two squirrel images
            printImage (20, 260, 8);
            printImage (1420, 260, 8);
            //increment y axis of new line that is printed
            space += 50;
            al_flip_display();
            }
    fclose(fptr); // close text file

    // create event queue
    ALLEGRO_EVENT_QUEUE *event_queue = nullptr;

    // Initialize keyboard routines
	if (!al_install_keyboard()) {
	    al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      	return -1;
   	}
   	// set up event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
      	return -1;
	}
	// need to register events for our event queue
 	al_register_event_source(event_queue, al_get_keyboard_event_source());
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    //if user presses a key, game will continue to run
    if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            play = true;
    }
}

//Function loads the ending screen and restart or end keyboard functions
int printEnd(bool &again){
    // Text addons to display text
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    ALLEGRO_FONT *font = al_load_ttf_font("superLarky.ttf", 23, 0); //load font
       if (!font){
          al_show_native_message_box(display, "Error", "Error", "Could not load suparLarky.ttf", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
       }
    //print win image
    printImage (0,0,7);
    //Initialize and declare variables
    FILE *fptr;
    char str[200];
    int space = 550;
    //open file
    fptr = fopen("windoc.txt", "r");
    if(fptr == nullptr){
        printf("file did not open");
    }
    //reads from textfile
    while(fgets(str, 200, fptr) != nullptr){
            printf("%s\n", str);
            //displays text onto screen
            al_draw_text(font, al_map_rgb(0, 0, 0), 1200 , space, ALLEGRO_ALIGN_CENTRE, str);
            //increments the space (y coordinate) between the lines
            space += 50;
            al_flip_display();
            }
    //close textfile
    fclose(fptr);
    //Initialize event queue
    ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
    // Initialize keyboard routines
	if (!al_install_keyboard()) {
	    al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      	return -1;
   	}
   	// set up event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
      	return -1;
	}
	// need to register events for our event queue
 	al_register_event_source(event_queue, al_get_keyboard_event_source());
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    //Switch statement to determine what happens
    //If user chooses 0, game continues. If user chooses 1, game ends.
    if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
         	switch(ev.keyboard.keycode) {
            	case ALLEGRO_KEY_0:
               		again = true;
                    printf("pressed 0");
               		break;
	            case ALLEGRO_KEY_1:
    		        printf("pressed 1");
                    again = false;
            		break;
         	}
    }
}
