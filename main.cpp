#include <allegro5/allegro.h>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "squirrel.h"
#define COLOUR al_map_rgb(200, 200, 0)

int main(){
    int totalScore = 0;
    Squirrel mainSquirrel;
    mainSquirrel.sPants.value = 0;
    mainSquirrel.sShirt.value = 0;
    mainSquirrel.sShoes.value = 0;
    mainSquirrel.sAcc.value = 0;
    Shirt arrShirts[5];
    Shoes arrShoes[5];
    Pants arrPants[5];
    Accessories arrAcc[5];
    //Sets points for each clothing piece
    clothingArrays(arrPants, arrShirts, arrShoes, arrAcc);

    // initialize Allegro and mouse functions
    al_init();
    al_init_primitives_addon();
    al_install_mouse();

    // Initialize display
    ALLEGRO_DISPLAY *display = nullptr;
    display = al_create_display(SCREEN_W, SCREEN_H);
    al_set_window_title(display, "Squirrel Game");

    // Initialize event queue
    ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
    bool select = false;
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_mouse_event_source());


    // create rectangle
    al_clear_to_color(al_map_rgb(0, 0, 0));\

    // flip display to show image


    // Initialize image add on
 	if (!al_init_image_addon()) {
    	// error message
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

    // print image - give variables 180 difference in Y
    printImage (0, 0, 4);
    printImage (113, 180, 1);
    printImage (95, 335, 2);
    printImage (95, 515, 2);
    printImage (113, 720, 1);
    printImage (113, 900, 1);
    displayRectangles ();
    al_flip_display();

    // text
       al_init_font_addon(); // initialize the font addon
       al_init_ttf_addon();// initialize the ttf (True Type Font) addon

       // load the specific font you want
       ALLEGRO_FONT *font = al_load_ttf_font("comic.ttf", 50, 0);
       if (!font){
          al_show_native_message_box(display, "Error", "Error", "Could not load comic.ttf",
                                        nullptr, ALLEGRO_MESSAGEBOX_ERROR);
          return -1;
       }
       al_draw_text(font, COLOUR, 145, 60, ALLEGRO_ALIGN_CENTRE, "Shirts");
       al_draw_text(font, COLOUR, 320, 60, ALLEGRO_ALIGN_CENTRE, "Pants");
       al_draw_text(font, COLOUR, 1581, 60, ALLEGRO_ALIGN_CENTRE, "Shoes");
       al_draw_text(font, COLOUR, 1756, 60, ALLEGRO_ALIGN_CENTRE, "Others");

       al_flip_display();

// MOUSE FUNCTIONS AND RECTANGLE
    while(!select){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        // column 1 Shirt
        if(ev.mouse.x >= 90 && ev.mouse.y >= 150 && ev.mouse.x <= 200 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (910, 500, 1);
            mainSquirrel.sShirt = arrShirts[0];
            arrShirts[0].select = true;
            printScore(getScore(totalScore, mainSquirrel.sShirt.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 90 && ev.mouse.y >= 330 && ev.mouse.x <= 200 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (700, 500, 2);
            mainSquirrel.sShirt = arrShirts[1];
            arrShirts[0].select = true;
            printScore(getScore(totalScore, mainSquirrel.sShirt.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 90 && ev.mouse.y >= 510 && ev.mouse.x <= 200 && ev.mouse.y <= 620 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (700, 500, 2);
            mainSquirrel.sShirt = arrShirts[2];
            arrShirts[0].select = true;
            printScore(getScore(totalScore, mainSquirrel.sShirt.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 90 && ev.mouse.y >= 690 && ev.mouse.x <= 200 && ev.mouse.y <= 800 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (700, 500, 2);
            mainSquirrel.sShirt = arrShirts[3];
            arrShirts[0].select = true;
            printScore(getScore(totalScore, mainSquirrel.sShirt.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 90 && ev.mouse.y >= 870 && ev.mouse.x <= 200 && ev.mouse.y <= 980 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (700, 500, 2);
            mainSquirrel.sShirt = arrShirts[4];
            arrShirts[0].select = true;
            printScore(getScore(totalScore, mainSquirrel.sShirt.value, arrPants, arrShirts, arrShoes, arrAcc));

        // column 2 Pants
        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 150 && ev.mouse.x <= 375 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (850, 500, 2);
            mainSquirrel.sPants = arrPants[0];
            arrShirts[0].select = true;
            printScore(getScore(totalScore, mainSquirrel.sPants.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 330 && ev.mouse.x <= 375 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (700, 500, 2);
            mainSquirrel.sPants = arrPants[1];
            arrShirts[0].select = true;
            printScore(getScore(totalScore, mainSquirrel.sPants.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 510 && ev.mouse.x <= 375 && ev.mouse.y <= 620 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (750, 500, 2);
            mainSquirrel.sPants = arrPants[2];
            arrShirts[0].select = true;
            printScore(getScore(totalScore, mainSquirrel.sPants.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 690 && ev.mouse.x <= 375 && ev.mouse.y <= 800 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (800, 500, 2);
            mainSquirrel.sPants = arrPants[3];
            arrShirts[0].select = true;
            printScore(getScore(totalScore, mainSquirrel.sPants.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 870 && ev.mouse.x <= 375 && ev.mouse.y <= 980 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (800, 500, 2);
            mainSquirrel.sPants = arrPants[4];
            arrShirts[0].select = true;
            printScore(getScore(totalScore, mainSquirrel.sPants.value, arrPants, arrShirts, arrShoes, arrAcc));

        // column 3 Shoes
        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 150 && ev.mouse.x <= 1640 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (850, 500, 2);
            mainSquirrel.sShoes = arrShoes[0];
            printScore(getScore(totalScore, mainSquirrel.sShoes.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 330 && ev.mouse.x <= 1640 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (700, 500, 2);
            mainSquirrel.sShoes = arrShoes[1];
            printScore(getScore(totalScore, mainSquirrel.sShoes.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 510 && ev.mouse.x <= 1640 && ev.mouse.y <= 620 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (750, 500, 2);
            mainSquirrel.sShoes = arrShoes[2];
            printScore(getScore(totalScore, mainSquirrel.sShoes.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 690 && ev.mouse.x <= 1640 && ev.mouse.y <= 800 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (800, 500, 2);
            mainSquirrel.sShoes = arrShoes[3];
            printScore(getScore(totalScore, mainSquirrel.sShoes.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 870 && ev.mouse.x <= 1640 && ev.mouse.y <= 980 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (800, 500, 2);
            mainSquirrel.sShoes = arrShoes[4];
            printScore(getScore(totalScore, mainSquirrel.sShoes.value, arrPants, arrShirts, arrShoes, arrAcc));

        // column 4 Accessories
        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 150 && ev.mouse.x <= 1815 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (800, 500, 2);
            mainSquirrel.sAcc = arrAcc[0];
            printScore(getScore(totalScore, mainSquirrel.sAcc.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 330 && ev.mouse.x <= 1815 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (800, 500, 2);
            mainSquirrel.sAcc = arrAcc[1];
            printScore(getScore(totalScore, mainSquirrel.sAcc.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 510 && ev.mouse.x <= 1815 && ev.mouse.y <= 620 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (800, 500, 2);
            mainSquirrel.sAcc = arrAcc[2];
            printScore(getScore(totalScore, mainSquirrel.sAcc.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 690 && ev.mouse.x <= 1815 && ev.mouse.y <= 800 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (800, 500, 2);
            mainSquirrel.sAcc = arrAcc[3];
            printScore(getScore(totalScore, mainSquirrel.sAcc.value, arrPants, arrShirts, arrShoes, arrAcc));

        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 870 && ev.mouse.x <= 1815 && ev.mouse.y <= 980 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (800, 500, 2);
            mainSquirrel.sAcc = arrAcc[4];
            printScore(getScore(totalScore, mainSquirrel.sAcc.value, arrPants, arrShirts, arrShoes, arrAcc));
        }
    }

    return 0;
}

