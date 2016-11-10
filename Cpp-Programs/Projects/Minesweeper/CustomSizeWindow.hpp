//
//  CustomSizeWindow.hpp
//  Minesweeper
//

#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Button.H>
#include <stdint.h>

#ifndef CustomSizeWindow_hpp
#define CustomSizeWindow_hpp

// TODO(Drew): Limits on custom size

/// Window that allows the user to define a custom size and bomb count
class CustomSizeWindow : public Fl_Window
{
public:
#pragma mark - Variables
    /// Did the user press OK to close the window
    /**
      * Set to true if changes were accepted by the user.
      * If it is false, then the user pressed cancel or
      * the user closed the window manually.
      */
    bool didAccept = false;
    
    /// The new width of the minesweeper board
    /**
      * This value is only set if the doneButton is pressed.
      * Therefore, it is only valid if didAccept is true.
      */
    uint32_t tileX;
    /// The new height of the minesweeper board
    /**
      * This value is only set if the doneButton is pressed.
      * Therefore, it is only valid if didAccept is true.
      */
    uint32_t tileY;
    /// The new bomb count of the minesweeper board
    /**
      * This value is only set if the doneButton is pressed.
      * Therefore, it is only valid if didAccept is true.
      */
    uint32_t bombCount;
    
#pragma mark - FLTK Widgets
    /// Label for height input
    Fl_Box* heightOut;
    /// Label for width input
    Fl_Box* widthOut;
    /// Label for bomb count input
    Fl_Box* bombCountOut;
    
    /// Input for new board width
    Fl_Value_Input* heightIn;
    /// Input for new board height
    Fl_Value_Input* widthIn;
    /// Input for new bomb count
    Fl_Value_Input* bombCountIn;
    
    /// Pressed when user has finished entering data
    Fl_Button* doneButton;
    /// Pressed when user decides not to create custom board
    Fl_Button* cancelButton;
    
#pragma mark - Constructors and Destructors
    /// @brief CustomSizeWindow Constructor
    CustomSizeWindow();
    /// @brief CustomSizeWindow Destructor
    ~CustomSizeWindow();
    
#pragma mark - Static Callbacks
    /// @brief Called when cancel is pressed
    /// @param obj A pointer to the cancelButton Fl_Button
    /// @param arg A pointer to this. Used to call Cancel()
    static void CancelCallback(Fl_Widget* obj, void* arg);
    /// @brief Called when done is pressed
    /// @param obj A pointer to the doneButton Fl_Button
    /// @param arg A pointer to this. Used to call Done()
    static void DoneCallback(Fl_Widget* obj, void* arg);
    
#pragma mark - Non-Static Callback Handlers
    /// @brief Local version of CancelCallback
    void Cancel();
    /// @brief Local version of DoneCallback
    void Done();
};

#endif /* CustomSizeWindow_hpp */
