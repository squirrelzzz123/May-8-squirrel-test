#include <allegro5/allegro.h>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define COLOUR al_map_rgb(200, 200, 0)


// Prototypes
void printImage (int x, int y, int file);
void displayRectangles ();
int getScore(int &total, int value);
int printScore(int total);

struct Pants {
    int value;
};

struct Shirt {
    int value;
};

struct Shoes {
    int value;
};

//'s' stands for squirrel
struct Squirrel{
    Shirt sShirt;
    Pants sPants;
    Shoes sShoes;
};

// Define screen size
const int SCREEN_W = 1920;
const int SCREEN_H = 1080;
//Declare and initialize variables *SORRY FOR THE GLOBALS
ALLEGRO_DISPLAY *display = nullptr;



int main(){
    int totalScore;
    Squirrel mainSquirrel;
    mainSquirrel.sPants.value = 0;
    mainSquirrel.sShirt.value = 0;
    mainSquirrel.sShoes.value = 0;

    Shirt arrShirts[20];
    for(int i = 0; i < 5; i++){
        if(i == 0)
            arrShirts[i].value = 30;
        if(i == 1)
            arrShirts[i].value = 55;
        if(i == 2)
            arrShirts[i].value = 77;
        if(i == 3)
            arrShirts[i].value = 66;
        if(i == 4)
            arrShirts[i].value = 99;
    }
    Shoes arrShoes[20];
    for(int i = 0; i < 5; i++){
        if(i == 0)
            arrShirts[i].value = 30;
        if(i == 1)
            arrShirts[i].value = 55;
        if(i == 2)
            arrShirts[i].value = 77;
        if(i == 3)
            arrShirts[i].value = 66;
        if(i == 4)
            arrShirts[i].value = 99;
    }
    Pants arrPants[20];
    for(int i = 0; i < 5; i++){
        if(i == 0)
            arrShirts[i].value = 30;
        if(i == 1)
            arrShirts[i].value = 55;
        if(i == 2)
            arrShirts[i].value = 77;
        if(i == 3)
            arrShirts[i].value = 66;
        if(i == 4)
            arrShirts[i].value = 99;
    }


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
    displayRectangles ();
    // flip display to show image
    al_flip_display();

    // Initialize image add on
 	if (!al_init_image_addon()) {
    	// error message
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

    // print image - give variables 180 difference in Y
    printImage (113, 180, 1);
    printImage (95, 335, 2);
    printImage (95, 515, 2);
    printImage (113, 720, 1);
    printImage (113, 900, 1);


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
       al_flip_display();

/*
    // MOUSE FUNCTIONS
    while(!select){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(ev.mouse.x >= 90 && ev.mouse.y >= 150 && ev.mouse.x <= 200 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printf("Hooray!(%d, %d)", ev.mouse.x, ev.mouse.y);
            printImage (910, 500, 1);
            mainSquirrel.sShirt = arrShirts[0];
            printScore(getScore(totalScore, mainSquirrel.sShirt.value));
        }else if(ev.mouse.x >= 90 && ev.mouse.y >= 330 && ev.mouse.x <= 200 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printf("Hooray!(%d, %d)", ev.mouse.x, ev.mouse.y);
            printImage (700, 500, 2);
            mainSquirrel.sShirt = arrShirts[1];
            printScore(getScore(totalScore, mainSquirrel.sShirt.value));
        }else if(ev.mouse.x >= 90 && ev.mouse.y >= 90 && ev.mouse.x <= 200 && ev.mouse.y <= 200)
            printf("(%d, %d)", ev.mouse.x, ev.mouse.y);
    }
    */

    // mouse function

// MOUSE FUNCTIONS
    while(!select){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        // column 1
        if(ev.mouse.x >= 90 && ev.mouse.y >= 150 && ev.mouse.x <= 200 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (910, 500, 1);
            mainSquirrel.sShirt = arrShirts[0];
            printScore(getScore(totalScore, mainSquirrel.sShirt.value));

        }else if (ev.mouse.x >= 90 && ev.mouse.y >= 330 && ev.mouse.x <= 200 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (700, 500, 2);
            mainSquirrel.sShirt = arrShirts[1];
            printScore(getScore(totalScore, mainSquirrel.sShirt.value));

        }else if (ev.mouse.x >= 90 && ev.mouse.y >= 510 && ev.mouse.x <= 200 && ev.mouse.y <= 620 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (700, 500, 2);
            mainSquirrel.sShirt = arrShirts[2];
            printScore(getScore(totalScore, mainSquirrel.sShirt.value));

        }else if (ev.mouse.x >= 90 && ev.mouse.y >= 690 && ev.mouse.x <= 200 && ev.mouse.y <= 800 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (700, 500, 2);
            mainSquirrel.sShirt = arrShirts[3];
            printScore(getScore(totalScore, mainSquirrel.sShirt.value));

        }else if (ev.mouse.x >= 90 && ev.mouse.y >= 870 && ev.mouse.x <= 200 && ev.mouse.y <= 980 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (700, 500, 2);
            mainSquirrel.sShirt = arrShirts[4];
            printScore(getScore(totalScore, mainSquirrel.sShirt.value));

        // column 2
        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 150 && ev.mouse.x <= 375 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (850, 500, 2);

        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 330 && ev.mouse.x <= 375 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (700, 500, 2);

        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 510 && ev.mouse.x <= 375 && ev.mouse.y <= 620 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (750, 500, 2);

        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 690 && ev.mouse.x <= 375 && ev.mouse.y <= 800 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (800, 500, 2);

        }else if (ev.mouse.x >= 265 && ev.mouse.y >= 870 && ev.mouse.x <= 375 && ev.mouse.y <= 980 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){

        // column 3
        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 150 && ev.mouse.x <= 1640 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (850, 500, 2);

        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 330 && ev.mouse.x <= 1640 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (700, 500, 2);

        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 510 && ev.mouse.x <= 1640 && ev.mouse.y <= 620 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (750, 500, 2);

        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 690 && ev.mouse.x <= 1640 && ev.mouse.y <= 800 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (800, 500, 2);

        }else if (ev.mouse.x >= 1530 && ev.mouse.y >= 870 && ev.mouse.x <= 1640 && ev.mouse.y <= 980 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){

        // column 4
        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 150 && ev.mouse.x <= 1815 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (850, 500, 2);

        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 330 && ev.mouse.x <= 1815 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (700, 500, 2);

        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 510 && ev.mouse.x <= 1815 && ev.mouse.y <= 620 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (750, 500, 2);

        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 690 && ev.mouse.x <= 1815 && ev.mouse.y <= 800 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printImage (800, 500, 2);

        }else if (ev.mouse.x >= 1705 && ev.mouse.y >= 870 && ev.mouse.x <= 1815 && ev.mouse.y <= 980 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP);

    }

    return 0;
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
        image = al_load_bitmap("whiteSquare.jpg");
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

int getScore(int &total, int value){
    total = value;
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

// rectangle function


void displayRectangles (){

    // For shirts
    al_draw_rectangle(90, 150, 200, 260,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(90, 330, 200, 440,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(90, 510, 200, 620,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(90, 690, 200, 800,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(90, 870, 200, 980,al_map_rgb(200, 200, 0) , 10);

    // For pants
    al_draw_rectangle(265, 150, 375, 260,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(265, 330, 375, 440,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(265, 510, 375, 620,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(265, 690, 375, 800,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(265, 870, 375, 980,al_map_rgb(200, 200, 0) , 10);

    // For shoes
    al_draw_rectangle(1530, 150, 1640, 260,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(1530, 330, 1640, 440,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(1530, 510, 1640, 620,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(1530, 690, 1640, 800,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(1530, 870, 1640, 980,al_map_rgb(200, 200, 0) , 10);

    // For others
    // For pants
    al_draw_rectangle(1705, 150, 1815, 260,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(1705, 330, 1815, 440,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(1705, 510, 1815, 620,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(1705, 690, 1815, 800,al_map_rgb(200, 200, 0) , 10);
    al_draw_rectangle(1705, 870, 1815, 980,al_map_rgb(200, 200, 0) , 10);


    al_flip_display();

}
