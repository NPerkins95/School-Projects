//
//  MinesweeperBoard.hpp
//  Minesweeper
//

#ifndef MinesweeperBoard_hpp
#define MinesweeperBoard_hpp

#include "TileButton.hpp"

#include <random>
#include <ctime>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>

/// The board that the minesweeper game takes place on. Stores all tiles and
/// gameplay data involved.
class MinesweeperBoard
{
private:
#pragma mark - Variables
    /// Has the user won the game
    /**
      * True if the user has won the game.
      * False in all other cases.
      */
    bool didWin;

    /// Can the game accept user input
    /**
      * True if the player can interact with the game
      * False if the player cannot interact with the game. Usually after the
      * game has been won or lost.
      */
    bool inPlay;

    /// Can the timer start counting
    /**
      * This is set to true when the player has pressed the first tile, and
      * the timer has been initiated. This is to prevent the creation of
      * multiple timers.
      */
    bool startedTimer;
    
    /// Holds the amount of tiles the user has flagged as a bomb. This is used
    /// to track the number used in the bombCountBox.
    uint32_t flaggedBombCount;
    
    /// Tells if a simultaenous click should be performed.
    /**
     * Is set to true when both left and right are down simultaneously. The
     * action does not take place until both mouse buttons are released,
     * however. So the state must be stored in a bool.
     * True if a Left and Right click action should occur as soon as both
     * buttons are released.
     */
    bool doLeftAndRightClick = false;
    
    /// Hold the time since the first tile was pressed.
    /**
      * Starts counting as soon as the first tile is pressed, and stops when
      * the game ends.
      */
    uint64_t secondsSinceStart;
    
    /// Two dimensional vector of all tiles.
    vector<vector<TileButton*>> boardButtons;
    
    /// Used to hold the location of a user's mines for ToggleShowMines
    typedef struct Point {
        uint32_t x;
        uint32_t y;
    } Point;

    /// Used to hold the location of a user's mines for ToggleShowMines
    vector<Point> userFlags;

public:
    /// The current width in tiles of the board
    uint32_t maxX;

    /// The current height in tile of the board
    uint32_t maxY;

    /// The current amount of bombs in the board
    uint32_t maxBomb;

private:
#pragma mark - FLTK Widgets
    /// The amount of flags placed compared to bombs in the board.
    /// Format FF/BB where FF is flags and BB is total bombs. Ex 02/10
    Fl_Box* bombCountBox;

    /// Tells the user if the game has been won, lost, or still in play.
    Fl_Box* winLoseBox;

    /// Tells the user how much time has elapsed since the first tile click.
    Fl_Box* timeBox;
    
private:
#pragma mark - Private Board Setup
    /// @brief Fills in bombs randomly on the board.
    void BombFill();

    /// @brief Counts the adjacent bombs and set's the tile's adjacent value.
    void SetAdjacentCount();
    
#pragma mark - Click Helpers
    /// @brief Reveal tile contents, and lose the game if it is a bomb.
    /// @param obj Pointer to the tile that was clicked on.
    void LeftClick(TileButton* obj);

    /// @brief Follow the following chain of operations. Blank -> Flagged,
    /// Flagged -> Question, Question -> Blank. Is not called for revealed
    /// tiles.
    /// @param obj Pointer to the tile that was clicked on.
    void RightClick(TileButton* obj);

    /// @brief Clears adjacent tiles if the number of adjacent flagged tiles is
    /// equal to the number of adjacent bombs.
    /// @param obj Pointer to the tile that was clicked on.
    void LeftAndRightClick(TileButton* obj);

    /// @brief Performs a left click action, but takes an x and y instead of a
    /// pointer to the tile. Checks if x and y are out of bounds
    /// @param x The x position of the tile to check. This is a signed int so
    /// it can handle a -1 position, as well as the full range of a U32.
    /// @param y The y position of the tile to check. This is a signed int so
    /// it can handle a -1 position, as well as the full range of a U32.
    void BoundedLeftClick(int64_t x, int64_t y);

    /// @brief Checks if the tile at the x and y position is currently flagged.
    /// Takes position based on x and y rather than pointer, and also checks if
    /// the location is in bounds.
    /// @param x The x position of the tile to check. This is a signed int so
    /// it can handle a -1 position, as well as the full range of a U32.
    /// @param y The y position of the tile to check. This is a signed int so
    /// it can handle a -1 position, as well as the full range of a U32.
    /// @return True if it is flagged, false if it isn't.
    bool CheckIfFlagged(int64_t x, int64_t y);

    /// @brief Sets the flagged value of a tile. It also updates the
    /// bombCountBox to reflect the new flagged count.
    /// @param tile The tile to set the flagged value.
    /// @param val The value to set the tile's flagged value to.
    void SetFlagged(TileButton* tile, bool val);

    /// @brief Cascade reveals the board starting at the x and y position.
    /// This function calls itself recursively.
    /// @param x The x position of the tile to reveal. This is a signed int so
    /// it can handle a -1 position, as well as the full range of a U32.
    /// @param y The y position of the tile to reveal. This is a signed int so
    /// it can handle a -1 position, as well as the full range of a U32.
    void RevealBoard(int64_t x, int64_t y);

    /// @brief Reveals the full board. Typically used after win or lose.
    /// @param revealBombs If false, flags bombs instead of revealing them.
    void RevealBoardFull(bool revealBombs);

#pragma mark - Private End Game
    /// @brief Checks if the player has won the game
    /// @return True if the player has won, false if they player has not won.
    bool CheckWin();

    /// @brief Loses the game. Reveals the board if it isn't already.
    void LoseGame();

#pragma mark - FLTK Widget Helpers
    /// @brief Get number of digits in a number.
    /// @param bombCount The number to count the numer of digits from.
    /// @return The number of digits
    uint8_t GetNumDigits(uint32_t bombCount);
    
public:
#pragma mark - Constructors and Destructors
    /// @brief MinesweeperBoard constructor
    MinesweeperBoard(Fl_Box* bombCountBox, Fl_Box* winLoseBox, Fl_Box* timeBox, uint32_t x = 9, uint32_t y = 9);

    /// @brief MinesweeperBoard destructor
    ~MinesweeperBoard();

#pragma mark - Board Setup
    /// @brief Sets up the board for play, including placing bombs and setting
    /// adjacency count.
    /// @param bombCount The amount of bombs to place in the board
    void SetUpBoard(uint32_t bombCount);

    /// @brief Initializes each tile, and sets its position on the window.
    /// @param left The pixel offset from the left side of the screen to start
    /// drawing the tiles at.
    /// @param top The pixel offset from the top side of the screen to start
    /// drawing the tiles at.
    /// @param imgArr Pointers to images that every tile uses.
    /// @param imgArrLength The amount of images to put in each tile.
    void InitTiles(uint32_t left, uint32_t top, vector<Fl_Shared_Image*> imgArr, uint16_t imgArrLength);
    
#pragma mark - Cheats
    /// @brief Shows or hides mines by flagging them on the board.
    /// @param show If true, shows mines. If false, hides mines, and replaces
    /// them with the user's original flags.
    void ToggleShowMines(bool show);

#pragma mark - End Game
    /// @brief Wins the game. Reveals the board if it isn't already.
    void WinGame();

#pragma mark - Private Variable Accessors
    // TODO(Drew): Should these be capital letter first? I dunno.
    /// @brief Can the game accept user input
    /// @return The value of inPlay
    bool isInPlay();

    /// @brief Did the player win
    /// @return The value of didWin
    bool getDidWin();
    
#pragma mark - Static Callbacks
    /// @brief Called when a tile is pressed. Calls a local function.
    /// @param obj Pointer to the TileButton that was pressed.
    /// @param arg Pointer to MinesweeperBoard object.
    static void TilePressedCallback(Fl_Widget* obj, void* arg);

    /// @brief Called when a background timer has counted for a second. Calls a
    /// local function.
    /// @param arg Pointer to MinesweeperBoard object.
    static void UpdateTimerCallback(void* arg);
    
#pragma mark - Non-Static Callback Handlers
    /// @brief Determines which button was pressed, and acts accordingly.
    /// @param obj Pointer to the TileButton that was pressed.
    void TilePressed(TileButton* obj);

    /// @brief Updates the timer and timeBox every 1 second.
    void UpdateTimer();
};

#endif /* MinesweeperBoard_hpp */
