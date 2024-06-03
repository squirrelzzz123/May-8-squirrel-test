//Nina Tseng and Alyssa Shen
#include <allegro5/allegro.h>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "squirrel.h"

int main(){
    //Declare and initialize variables
    int totalScore = 0;
    int highScore = 0;
    bool shirtClicked = false;
    bool pantsClicked = false;
    bool shoesClicked = false;
    bool accClicked = false;
    Squirrel mainSquirrel;
    mainSquirrel.sPants.value = 0;
    mainSquirrel.sShirt.value = 0;
    mainSquirrel.sShoes.value = 0;
    mainSquirrel.sAcc.value = 0;
    Shirt arrShirts[5];
    Shoes arrShoes[5];
    Pants arrPants[5];
    Accessories arrAcc[5];
    //Sets the points for each clothing piece
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
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_mouse_event_source());
    // Initialize image add on
 	if (!al_init_image_addon()) {
    	// error message
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}
    //load clothing into the boxes
    loadGraphics();
    //display rectangles onto screen
    displayRectangles ();
    al_flip_display();
    loadText();
    //prints out initial score of 0
    printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
    //prints out initial high score of 0
    printHighScore(highScore);
// MOUSE FUNCTIONS AND RECTANGLE
    while(true){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        // column 1 Shirt
        if(ev.mouse.x >= 90 && ev.mouse.y >= 150 && ev.mouse.x <= 200 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!shirtClicked){
                printImage (720, 426, 31); //tank top
                mainSquirrel.sShirt = arrShirts[0];
                shirtClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 90 && ev.mouse.y >= 330 && ev.mouse.x <= 200 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!shirtClicked){
                printImage (716, 396, 33); //i love acorns
                mainSquirrel.sShirt = arrShirts[1];
                shirtClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 90 && ev.mouse.y >= 510 && ev.mouse.x <= 200 && ev.mouse.y <= 620 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!shirtClicked){
                printImage (688, 382, 35); //pink fluffy jacket
                mainSquirrel.sShirt = arrShirts[2];
                shirtClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 90 && ev.mouse.y >= 690 && ev.mouse.x <= 200 && ev.mouse.y <= 800 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!shirtClicked){
                printImage (650, 300, 2);
                mainSquirrel.sShirt = arrShirts[3];
                shirtClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 90 && ev.mouse.y >= 870 && ev.mouse.x <= 200 && ev.mouse.y <= 980 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!shirtClicked){
                printImage (780, 500, 2);
                mainSquirrel.sShirt = arrShirts[5];
                shirtClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        // column 2 Pants
         }else if (ev.mouse.x >= 265 && ev.mouse.y >= 150 && ev.mouse.x <= 375 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!pantsClicked){
                printImage (620+80, 600, 19); //yellow pants
                mainSquirrel.sPants = arrPants[0];
                pantsClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 330 && ev.mouse.x <= 375 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!pantsClicked){
                printImage (725, 645, 40); // green pants
                mainSquirrel.sPants = arrPants[1];
                pantsClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 510 && ev.mouse.x <= 375 && ev.mouse.y <= 620 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!pantsClicked){
                printImage (720, 660, 42); // flower pants
                mainSquirrel.sPants = arrPants[2];
                pantsClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 690 && ev.mouse.x <= 375 && ev.mouse.y <= 800 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!pantsClicked){
                printImage (720, 670, 44); // cargo pants
                mainSquirrel.sPants = arrPants[3];
                pantsClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 870 && ev.mouse.x <= 375 && ev.mouse.y <= 980 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!pantsClicked){
                printImage (720, 670, 46); // blue pants
                mainSquirrel.sPants = arrPants[4];
                pantsClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        // column 3 Shoes
        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 150 && ev.mouse.x <= 1640 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!shoesClicked){
                printImage (700, 880, 21); //air forces
                printImage (900, 890, 21); //air forces
                mainSquirrel.sShoes = arrShoes[0];
                shoesClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 330 && ev.mouse.x <= 1640 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!shoesClicked){
                printImage (700, 900, 23); //blue sandal
                printImage (900, 910, 23); //blue sandal
                mainSquirrel.sShoes = arrShoes[1];
                shoesClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 510 && ev.mouse.x <= 1640 && ev.mouse.y <= 620 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!shoesClicked){
                printImage (690, 895, 25); //blackboot
                printImage (900, 900, 25); //blackboot
                mainSquirrel.sShoes = arrShoes[2];
                shoesClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 690 && ev.mouse.x <= 1640 && ev.mouse.y <= 800 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!shoesClicked){
                printImage (708, 860, 27); // yellow rainboot
                printImage (910, 860, 27); // yellow rainboot
                mainSquirrel.sShoes = arrShoes[3];
                shoesClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 870 && ev.mouse.x <= 1640 && ev.mouse.y <= 980 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!shoesClicked){
                printImage (710, 900, 29); //brown birks
                printImage (920, 912, 29); //brown birks
                mainSquirrel.sShoes = arrShoes[4];
                shoesClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        // column 4 Accessories
        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 150 && ev.mouse.x <= 1815 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!accClicked){
                printImage (660+80, 250 ,9); // black hat
                mainSquirrel.sAcc = arrAcc[0];
                accClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 330 && ev.mouse.x <= 1815 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!accClicked){
                printImage (645+80, 390, 11); // gold chain
                mainSquirrel.sAcc = arrAcc[1];
                accClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 510 && ev.mouse.x <= 1815 && ev.mouse.y <= 620 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!accClicked){
                printImage (660+80, 340, 13); // pink glasses
                mainSquirrel.sAcc = arrAcc[2];
                accClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 690 && ev.mouse.x <= 1815 && ev.mouse.y <= 800 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!accClicked){
                printImage (645+80, 410, 15); // flower necklace
                mainSquirrel.sAcc = arrAcc[3];
                accClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 870 && ev.mouse.x <= 1815 && ev.mouse.y <= 980 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(!accClicked){
                printImage (770+80, 565 , 17); // rolex
                mainSquirrel.sAcc = arrAcc[4];
                accClicked = true;
                printScore(addScore(totalScore, mainSquirrel.sShirt.value, mainSquirrel.sPants.value, mainSquirrel.sShoes.value, mainSquirrel.sAcc.value));
            }
        //restart rectangle code
        } else if (ev.mouse.x >= 860 && ev.mouse.y >= 970 && ev.mouse.x <= 990 && ev.mouse.y <= 1020 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            reprintScreen(mainSquirrel.sAcc.value, mainSquirrel.sPants.value, mainSquirrel.sShirt.value, mainSquirrel.sShoes.value, shirtClicked, pantsClicked, shoesClicked, accClicked, highScore, totalScore);
        } else if (shirtClicked == true && pantsClicked == true && shoesClicked == true && accClicked == true && totalScore >= 275){
            printImage (0,0,7);
        } else if (shirtClicked == true && pantsClicked == true && shoesClicked == true && accClicked == true && totalScore < 275){
            al_rest(3);
            printImage (0,0,6);
            al_rest(3);
            reprintScreen(mainSquirrel.sAcc.value, mainSquirrel.sPants.value, mainSquirrel.sShirt.value, mainSquirrel.sShoes.value, shirtClicked, pantsClicked, shoesClicked, accClicked, highScore, totalScore);
        }
    }
    return 0;
}
