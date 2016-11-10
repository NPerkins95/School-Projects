//
//  MinesweeperWindow.hpp
//  Minesweeper
//

#ifndef MinesweeperWindow_hpp
#define MinesweeperWindow_hpp

#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>

#include "MinesweeperBoard.hpp"
#include "CustomSizeWindow.hpp"

// TODO(Drew): About, Cheats, Debug

/// Main window of the program. Contains the play area for the game.
class MinesweeperWindow : public Fl_Window
{
private:
    /// The starting X location for the minesweeper board.
    /**
      * It is also used to define the location of the information board
      * that is located above the play area. Adjusting this value should
      * result in a correctly oriented play space, and will adjust window size.
      */
    const uint8_t cornerOffsetX = 12;
    
    /// The starting Y location for the minesweeper board.
    /**
      * It is also used to define the location of the information board
      * that is located above the play area. Adjusting this value should
      * result in a correctly oriented play space, and will adjust window size.
      */
    const uint8_t cornerOffsetY = 86;
    
    /// The amount of images used by a single tile.
    /**
      * Each tile is given pointers to shared images to use. This number tells
      * the program how many pointers in the imgArr to pass to tiles, starting
      * from 0.
      */
    const uint8_t imgCountTile = 7;
    
    /// All of the data related to the actual minesweeper board and game
    /// status.
    /**
      * This reference is newed every time a new board is created, and deleted
      * and newed again when a new game is started.
      */
    MinesweeperBoard* board;
    
    /// An array of all images loaded into the program.
    /**
      * From 0 to imgCountTile is all images for tiles. Beyond that number,
      * images are for use in the information box window.
      */
    vector<Fl_Shared_Image*> imgArr;
    
    /// Top menu bar of the program
    /**
      * Fl_Sys_Menu is missing some of the basic funcationality of Fl_Menu, so
      * we don't use it.
      */
    Fl_Menu_Bar* menuBar;

    /// Indicator of bombs flagged versus total bombs on the board
    /** 
      * This is stored and shown in the MinesweeperWindow class, but it is set
      * and updated by the MinesweeperBoard since it requires and displays data
      * from the board.
      */
    Fl_Box* bombCountBox;

    /// Indicator of the current state of the game. Win, lose, or in play.
    /** 
      * This is stored and shown in the MinesweeperWindow class, but it is set
      * and updated by the MinesweeperBoard since it requires and displays data
      * from the
      */
    Fl_Box* winLoseBox;

    /// Indicator of time spent in play. Starts on first tile press.
    /** 
      * This is stored and shown in the MinesweeperWindow class, but it is set
      * and updated by the MinesweeperBoard since it requires and displays data
      * from the
      */
    Fl_Box* timeBox;
    
private:
#pragma mark - Initialization Methods
    /// @brief Loads all images and places them in the imgArr.
    void LoadImages();

    /// @brief Sets up all controls on the screen as well as the menu bar.
    void SetUpScreen();
    
public:
#pragma mark - Constructors and Destructors
    /// @brief MinesweeperWindow constructor
    /// @param title The title of the window
    MinesweeperWindow(const char* title);

    /// @brief MinesweeperWindow destructor
    ~MinesweeperWindow();
    
#pragma mark - Override Methods
    /// @brief Local override of the window's draw function.
    void draw() override;
    
#pragma mark - Static Callbacks
    /// @brief Called when New Game is pressed. Calls local function.
    /// @param obj Pointer to the menu bar this call came from.
    /// @param arg Pointer to MinesweeperWindow object.
    static void NewGameCallback(Fl_Widget* obj, void* arg);

    /// @brief Called when Exit is pressed. Quits the application.
    /// @param obj Pointer to the menu bar this call came from.
    /// @param arg Pointer to MinesweeperWindow object.
    static void ExitCallback(Fl_Widget* obj, void* arg);

    /// @brief Called when Toggle Cheats is pressed. Calls local function.
    /// @param obj Pointer to the menu bar this call came from.
    /// @param arg Pointer to MinesweeperWindow object.
    static void ToggleCheatsCallback(Fl_Widget* obj, void* arg);

    /// @brief Called when Show Mines is pressed. Calls local function.
    /// @param obj Pointer to the menu bar this call came from.
    /// @param arg Pointer to MinesweeperWindow object.
    static void ShowMinesCallback(Fl_Widget* obj, void* arg);

    /// @brief Called when Force Win is pressed. Calls local function.
    /// @param obj Pointer to the menu bar this call came from.
    /// @param arg Pointer to MinesweeperWindow object.
    static void ForceWinCallback(Fl_Widget* obj, void* arg);
    
    /// @brief Called when Beginner difficulty is pressed. Calls local
    /// function.
    /// @param obj Pointer to the menu bar this call came from.
    /// @param arg Pointer to MinesweeperWindow object.
    static void EasyDifficultyCallback(Fl_Widget* obj, void* arg);

    /// @brief Called when Intermediate difficulty is pressed. Calls local
    /// function.
    /// @param obj Pointer to the menu bar this call came from.
    /// @param arg Pointer to MinesweeperWindow object.
    static void MediumDifficultyCallback(Fl_Widget* obj, void* arg);

    /// @brief Called when Expert difficulty is pressed. Calls local function.
    /// @param obj Pointer to the menu bar this call came from.
    /// @param arg Pointer to MinesweeperWindow object.
    static void HardDifficultyCallback(Fl_Widget* obj, void* arg);

    /// @brief Called when Custom difficulty is pressed.
    /// @param obj Pointer to the menu bar this call came from.
    /// @param arg Pointer to MinesweeperWindow object.
    static void CustomDifficultyCallback(Fl_Widget* obj, void* arg);
    
    static void AboutCallback(Fl_Widget* obj, void* arg);
    
#pragma mark - Non-Static Callback Handlers
    /// @brief Toggles the availability of cheats. 
    /// @param b If true, activate cheats. If false, deactivate cheats.
    void ToggleCheats(bool b);

    /// @brief Forces the win state of the game.
    void ForceWin();

    /// @brief Creates a new game identical in width, height, and bomb count
    /// to the current game.
    void NewGame();

    /// @brief Creates a new game with 9 tile width and 9 tile height with 10
    /// bombs.
    void EasyDifficulty();

    /// @brief Creates a new game with 16 tile width and 16 tile height with 40
    // bombs.
    void MediumDifficulty();

    /// @brief Creates a new game with 30 tile width and 16 tile height with 99
    /// bombs.
    void HardDifficulty();

    /// @brief Creates a new game of custom width, height, and bomb count.
    /// @param tileX The new width in tiles of the minesweeper board.
    /// @param tileY The new height in tiles of the minesweeper board.
    /// @param bombCount The number of bombs within the play field
    void CustomDifficulty(uint32_t tileX, uint32_t tileY, uint32_t bombCount);

    /// @brief Reverts the difficulty check to the correct menu option after
    /// the user cancels out of the custom size dialog window.
    void CustomDifficultyRevert();
    
    void AboutCallback();
};

#endif /* MinesweeperWindow_hpp */
