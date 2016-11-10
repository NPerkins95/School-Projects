#include "Button.hpp"

int pressed = 0;
void mycallback(Fl_Widget* widget, void*) 
{
	pressed++;
    cout << pressed << endl;
    
    if(pressed % 2 == 0)
    {
    	Fl_Button *mybutton = new Fl_Button(20, 40, 120, 30);
    	mybutton->labelsize(24);
    	mybutton->image(imgB);
	}
	else
	{
		Fl_Button *mybutton = new Fl_Button(20, 40, 120, 30);
    	mybutton->labelsize(24);
    	mybutton->image(imgA);
	}
}
