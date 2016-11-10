#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.H>
#include <iostream>
using namespace std;

int pressed = 1;

void mycallback(Fl_Widget* widget, void*) 
{
    cout << pressed << endl;
    pressed+= 1;
}

int main(int argc, char **argv) 
{
	Fl_JPEG_Image img("img.jpg");
	//Fl_JPEG_Image img("img2.jpg");
    
    Fl_Window *window = new Fl_Window(160, 100);

    Fl_Button *mybutton = new Fl_Button(20, 40, 120, 30);
    mybutton->labelsize(24);
    mybutton->image(img);

    mybutton->callback(mycallback);

    window->end();
    window->show(argc, argv);
    return Fl::run();
}      
