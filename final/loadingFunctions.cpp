//Nina Tseng and Alyssa Shen
//This file includes functions for reprinting the screen, and printing the instructions and ending(win/lose) screens.
#include <allegro5/allegro.h>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "squirrel.h"

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
    ALLEGRO_DISPLAY *display = nullptr;
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
    ALLEGRO_DISPLAY *display = nullptr;
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
