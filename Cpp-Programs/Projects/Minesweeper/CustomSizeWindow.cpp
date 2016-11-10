//
//  CustomSizeWindow.cpp
//  Minesweeper
//

#include "CustomSizeWindow.hpp"

#pragma mark - Constructors and Destructors
CustomSizeWindow::CustomSizeWindow() : Fl_Window(210, 155, "Custom Size")
{
    begin();
    
    heightOut = new Fl_Box(10, 10, 90, 30, "Height: ");
    widthOut = new Fl_Box(10, 45, 90, 30, "Width: ");
    bombCountOut = new Fl_Box(10, 80, 90, 30, "Bomb Count: ");
    heightOut->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    widthOut->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    bombCountOut->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    
    heightIn = new Fl_Value_Input(110, 10, 90, 30);
    heightIn->step(1);
    heightIn->range(1, 5);
    heightIn->soft(0);
    widthIn = new Fl_Value_Input(110, 45, 90, 30);
    widthIn->step(1);
    widthIn->range(1, 5);
    widthIn->soft(0);
    bombCountIn = new Fl_Value_Input(110, 80, 90, 30);
    bombCountIn->step(1);
    bombCountIn->range(1, 2);
    bombCountIn->soft(0);
    
    cancelButton = new Fl_Button(10, 115, 90, 30, "Cancel");
    doneButton = new Fl_Button(110, 115, 90, 30, "Done");
    cancelButton->callback(CustomSizeWindow::CancelCallback, this);
    doneButton->callback(CustomSizeWindow::DoneCallback, this);
    
    end();
    show();
}

CustomSizeWindow::~CustomSizeWindow()
{
    if (heightOut)
        delete heightOut;
    if (widthOut)
        delete widthOut;
    if (bombCountOut)
        delete bombCountOut;
    if (heightIn)
        delete heightIn;
    if (widthIn)
        delete widthIn;
    if (bombCountIn)
        delete bombCountIn;
    if (cancelButton)
        delete cancelButton;
    if (doneButton)
        delete doneButton;
}

#pragma mark - Static Callbacks
void CustomSizeWindow::CancelCallback(Fl_Widget* obj, void* arg)
{
    ((CustomSizeWindow*)arg)->Cancel();
}

void CustomSizeWindow::DoneCallback(Fl_Widget* obj, void* arg)
{
    ((CustomSizeWindow*)arg)->Done();
}

#pragma mark - Non-Static Callback Handlers
void CustomSizeWindow::Cancel()
{
    didAccept = false;
    hide();
}

void CustomSizeWindow::Done()
{
    tileX = widthIn->value();
    tileY = heightIn->value();
    bombCount = bombCountIn->value();
    didAccept = true;
    hide();
}