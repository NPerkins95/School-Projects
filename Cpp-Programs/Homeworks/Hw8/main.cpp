#include <FL/Fl_Window.H>
#include "Button.hpp"

int main(int argc, char **argv)
{
	Fl_Window *window = new Fl_Window(160, 100);
	
	window->end();
    window->show(argc, argv);
    return Fl::run();	
}
