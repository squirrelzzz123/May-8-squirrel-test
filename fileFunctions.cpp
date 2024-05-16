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

// Define screen size
const int SCREEN_W = 1920;
const int SCREEN_H = 1080;

int main(){

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
    // set spot and colour
    al_draw_rectangle(90, 150, 200, 260,al_map_rgb(200, 200, 0) , 10);
    // rectangle 2
    al_draw_rectangle(90, 330, 200, 440,al_map_rgb(200, 200, 0) , 10);
    // rectangle 3
    al_draw_rectangle(90, 510, 200, 620,al_map_rgb(200, 200, 0) , 10);
    // rectangle 4
    al_draw_rectangle(90, 690, 200, 800,al_map_rgb(200, 200, 0) , 10);
    // rectangle 5
    al_draw_rectangle(90, 870, 200, 980,al_map_rgb(200, 200, 0) , 10);

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
    printImage (113, 540, 2);
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


    // MOUSE FUNCTIONS
    while(!select){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(ev.mouse.x >= 90 && ev.mouse.y >= 150 && ev.mouse.x <= 200 && ev.mouse.y <= 260 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
        printf("Hooray!(%d, %d)", ev.mouse.x, ev.mouse.y);
        printImage (910, 500, 1);

       }else if (ev.mouse.x >= 90 && ev.mouse.y >= 330 && ev.mouse.x <= 200 && ev.mouse.y <= 440 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
        printf("Hooray!(%d, %d)", ev.mouse.x, ev.mouse.y);
        printImage (700, 500, 2);

    } else if(ev.mouse.x >= 90 && ev.mouse.y >= 90 && ev.mouse.x <= 200 && ev.mouse.y <= 200)
        printf("(%d, %d)", ev.mouse.x, ev.mouse.y);


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



