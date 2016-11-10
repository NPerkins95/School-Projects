//
//  TileButton.hpp
//  Minesweeper
//

#ifndef TileButton_hpp
#define TileButton_hpp

#include <FL/Fl_Button.H>
#include <FL/Fl_Shared_Image.H>
#include <vector>
#include <iostream>

using namespace std;

/// Individual tiles within the play field of the minesweeper board.
class TileButton : public Fl_Button
{
public:
    /// Enum of images within the imgArr. Allows for easy labeled access.
    typedef enum ImageIndex
    {
        hiddenImg,
        revealedImg,
        bombImg,
        losingBombImg,
        questionImg,
        flaggedImg,
        notMineImg
    } ImageIndex;
    
private:
#pragma mark - Variables
    /// An array of all images loaded for tiles.
    /**
      * Should be accessed using the enum so that accesses are well documented.
      */
    vector<Fl_Shared_Image*> imgArr;
    
public:
    /// The amount of bombs adjacent to this tile.
    uint8_t adjacent;

    /// Is the tile hidden
    /**
      * True if the tile is hidden
      * False if the tile has been revealed, either through click or cascade.
      */
    bool hidden;

    /// Is the tile a bomb
    /**
      * True if the tile is a bomb.
      * False if the tile is not a bomb.
      */
    bool bomb;

    /// Is the tile marked as a question.
    /**
      * True if the tile is marked a question.
      * False if the tile is not marked a question.
      */
    bool question;

    /// Is the tile flagged as a bomb.
    /**
      * True if the tile is flagged as a bomb.
      * False if the tile is not flagged as a bomb.
      */
    bool flagged;

    /// Is the tile and exploded bomb. If true, this bomb lost the game.
    /// This is needed for graphical differences on loss.
    /**
      * True if the tile was clicked and was a bomb, losing the game.
      * False in all other cases.
      */
    bool exploded;
    
    /// The x position of the tile within the minesweeper board, in tiles.
    uint32_t boardX;

    /// The y position of the tile within the minesweeper board, in tiles.
    uint32_t boardY;
    
public:
#pragma mark - Constructors and Destructors
    /// @brief TileButton contsructor for vectors
    TileButton();

    /// @brief TileButton copy constructor
    /// @param orig The TileButton to copy.
    TileButton(const TileButton& orig);

    /// @brief TileButton constructor
    /// @param x The x position in pixels.
    /// @param y The y position in pixels.
    /// @param width The tile width in pixels.
    /// @param height The tile height in pixels.
    TileButton(int x, int y, int width, int height);
    
#pragma mark - Tile Setup
    /// @brief Set the local image pointers of the tile.
    /// @param imgArr The main image array from the window.
    /// @param length The count of images in the array that belong to tiles.
    void PassImages(vector<Fl_Shared_Image*> imgArr, uint16_t length);
    
#pragma mark - Override Methods
    /// @brief Local override of the Fl_Button's draw function.
    void draw() override;
};

#endif /* TileButton_hpp */
