//This code checks whether the mouse is within the bounds of the yellow square that has been drawn and checks whether it has been clicked
#include <allegro5/allegro.h>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>


const int SCREEN_W = 1920;
const int SCREEN_H = 1080;

int main(){
    al_init();
    al_init_primitives_addon();
    al_install_mouse();

    ALLEGRO_DISPLAY *display = nullptr;
    display = al_create_display(SCREEN_W, SCREEN_H);
    al_set_window_title(display, "mouse test");

    ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
    bool select = false;

    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_clear_to_color(al_map_rgb(0, 0, 0));\
    al_draw_rectangle(90, 90, 200, 200,al_map_rgb(200, 200, 0) , 10);
    al_flip_display();

    	// Initialize image add on
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error",
    		"Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

	// Declare a BITMAP called image, setting it's initial value to nullptr
	ALLEGRO_BITMAP *image = nullptr;

	// Load the bitmap into the Bitmap structure
	// image file must be in same directory.
	// Particularly check return code of this type of function that will fail if file not found.
	image = al_load_bitmap("rainbow2.bmp");
  	if (!image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      	al_destroy_display(display);
     	return -1;
	 }

	// Display picture started at top left corner
	al_draw_bitmap(image, 120, 120, 0);

	// write display to screen
	al_flip_display();

	  while(!select){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if(ev.mouse.x >= 90 && ev.mouse.y >= 90 && ev.mouse.x <= 200 && ev.mouse.y <= 200 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
        printf("Hooray!(%d, %d)", ev.mouse.x, ev.mouse.y);
        select = true;
    }
        else if(ev.mouse.x >= 90 && ev.mouse.y >= 90 && ev.mouse.x <= 200 && ev.mouse.y <= 200)
        printf("(%d, %d)", ev.mouse.x, ev.mouse.y);
    }



return 0;
}



/*
	#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
//Code sourced from Mike Geig
int mouseInput(void){
    int width = 640;
	int height = 480;

	bool done = false;
	bool draw = true;
	int pos_x = width / 2;
	int pos_y = height / 2;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	if(!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(width, height);			//create our display object

	if(!display)										//test display object
		return -1;


	al_init_primitives_addon();
	al_install_mouse();

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_hide_mouse_cursor(display);
	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if(ev.mouse.button & 1)
				draw = !draw;
			else if (ev.mouse.button & 2)
				done = true;
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
		}

		if(draw)
			al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(255, 0, 255));
		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}

	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object

	return 0;
}

// You must include the allegro header files


const int SCREEN_W = 640;       // screen width
const int SCREEN_H = 480;       // screen height

int displayScreen() {
	ALLEGRO_DISPLAY *display = nullptr;

	// Initialize Allegro
	al_init();

	// Initialize display

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
    	al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
       	return -1;
	}

	// Initialize image add on
 	if (!al_init_image_addon()) {
    	al_show_native_message_box(display, "Error", "Error",
    		"Failed to initialize image addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
    	return -1;
	}

	// Declare a BITMAP called image, setting it's initial value to nullptr
	ALLEGRO_BITMAP *image = nullptr;

	// Load the bitmap into the Bitmap structure
	// image file must be in same directory.
	// Particularly check return code of this type of function that will fail if file not found.
	image = al_load_bitmap("11person.bmp");
  	if (!image) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
                                 nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      	al_destroy_display(display);
     	return -1;
	 }

	// Display picture started at top left corner
	al_draw_bitmap(image, 0,  0, 0);

	// write display to screen
	al_flip_display();

    // Wait 5 seconds
	//al_rest(5);

	// Free memory and return with successful return code..
	//al_destroy_display(display);
   	//al_destroy_bitmap(image);
	return 0;
}
*/ 

