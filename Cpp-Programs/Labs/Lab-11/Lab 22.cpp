//#include <Windows.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.H>
#include <iostream>
using namespace std;

/*void mycallback(Fl_Widget* widget, void*) {
    cout << "Button has been pressed.\n";

    Fl_Button* b = dynamic_cast<Fl_Button*>(widget);
    b->position(rand() % 680, rand() % 570);
    Fl_Window* win = b->window();
    win->redraw();
}*/

int main(int argc, char **argv) 
{
	Fl_JPEG_Image img("img.jpg");
	//Fl_JPEG_Image img("img2.jpg");
	
    /*if (img.w() == 0 || img.h() == 0 || img.d() == 0) 
	{
        cerr << "Error loading image.\nPress enter to close...";
        cin.get();
        exit(1);
    }*/
    
    Fl_Window *window = new Fl_Window(800, 600);

    Fl_Button *mybutton = new Fl_Button(20, 40, 120, 30);
    mybutton->labelsize(24);
    mybutton->image(img);

    //mybutton->callback(mycallback);

    window->end();
    window->show(argc, argv);
    return Fl::run();
}      
