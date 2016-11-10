#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_JPEG_Image.H>
#include <iostream>
using namespace std;

class MyButton: public Fl_Button
{
	private:
		Fl_JPEG_Image imgA("img.jpg");
		Fl_JPEG_Image imgB("img2.jpg");
	
}
