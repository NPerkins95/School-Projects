//
//  MinesweeperBoard.cpp
//  Minesweeper
//

#include "MinesweeperBoard.hpp"
#include <FL/Fl_JPEG_Image.H>

#pragma mark - Constructors and Destructors
MinesweeperBoard::MinesweeperBoard(Fl_Box* bombCountBox, Fl_Box* winLoseBox, Fl_Box* timeBox, uint32_t x, uint32_t y)
{
    srand((unsigned int)time(NULL));
//    srand(13);
    
    maxX = x;
    maxY = y;
    
    boardButtons.resize(y);
    for (uint32_t i = 0; i < y; i++)
        boardButtons.at(i).resize(x);
    
    inPlay = false;
    didWin = false;
    startedTimer = false;
    
    flaggedBombCount = 0;
    
    secondsSinceStart = 0;
    
    
    this->bombCountBox = bombCountBox;
    bombCountBox->label("00/10");
    this->winLoseBox = winLoseBox;
    // Display "in play" Smiley
    Fl_JPEG_Image *img = new Fl_JPEG_Image("defaultSmiley.jpg");
    winLoseBox->image(img);
    this->timeBox = timeBox;
    timeBox->label("0");
}

MinesweeperBoard::~MinesweeperBoard()
{
    for (uint32_t y = 0; y < maxY; y++)
    {
        for (uint32_t x = 0; x < maxX; x++)
        {
            TileButton* tile = boardButtons.at(y).at(x);
            if (tile != nullptr)
                delete tile;
        }
    }
}



#pragma mark - Board Setup
void MinesweeperBoard::SetUpBoard(uint32_t bombCount)
{
    maxBomb = bombCount;
    
    BombFill();
    SetAdjacentCount();
    
    int numZeroes = GetNumDigits(bombCount);
    string dest = string(numZeroes, '0').append("/").append(to_string(bombCount));
    bombCountBox->copy_label(dest.c_str());
    
    inPlay = true;
}

void MinesweeperBoard::InitTiles(uint32_t left, uint32_t top, vector<Fl_Shared_Image*> imgArr, uint16_t imgArrLength)
{
    for (uint32_t y = 0; y < maxY; y++)
    {
        for (uint32_t x = 0; x < maxX; x++)
        {
            TileButton* tile = new TileButton(left + (x * 16), top + (y * 16), 16, 16);
            tile->boardX = x;
            tile->boardY = y;
            tile->PassImages(imgArr, imgArrLength);
            tile->callback(MinesweeperBoard::TilePressedCallback, this);
            tile->when(FL_WHEN_RELEASE_ALWAYS);
            boardButtons.at(y).at(x) = tile;
        }
    }
}

void MinesweeperBoard::BombFill()
{
    for (int i = 0; i < maxBomb; i++)
    {
        uint32_t randX = rand() % maxX;
        uint32_t randY = rand() % maxY;
        
        if (!boardButtons.at(randY).at(randX)->bomb)
            boardButtons.at(randY).at(randX)->bomb = true;
        else
            i--; // Failed placement, try again.
    }
}

void MinesweeperBoard::SetAdjacentCount()
{
    for (uint32_t y = 0; y < maxY; y++)
    {
        for (uint32_t x = 0; x < maxX; x++)
        {
            uint8_t bombCount = 0;
            
            // Check all 4 directions for a bomb. If direction is out of bounds
            // then mark it as an invalid location so that the program does not
            // check out of the bounds of the vector
            for (int dx = (x > 0 ? -1 : 0); dx <= (x < (maxX - 1) ? 1 : 0); dx++)
            {
                for (int dy = (y > 0 ? -1 : 0); dy <= (y < (maxY - 1) ? 1 : 0); dy++)
                {
                    if (dx != 0 || dy != 0)
                    {
                        if (boardButtons.at(y + dy).at(x + dx)->bomb)
                        {
                            bombCount++;
                        }
                    }
                }
            }
            
            boardButtons.at(y).at(x)->adjacent = bombCount;
        }
    }
}



#pragma mark - End Game
bool MinesweeperBoard::CheckWin()
{
    bool ret = true;
    for (uint32_t y = 0; y < maxY; y++)
    {
        for (uint32_t x = 0; x < maxX; x++)
        {
            TileButton* tile = boardButtons.at(y).at(x);
            // If a non-bomb is still hidden, game not won
            if (tile->hidden && !tile->bomb)
            {
                // Force out of the loop
                ret = false;
                x = maxX;
                y = maxY;
            }
        }
    }
    
    return ret;
}

void MinesweeperBoard::WinGame()
{
	// Display Win Smiley
	Fl_JPEG_Image *img = new Fl_JPEG_Image("winSmiley.jpg");
	winLoseBox->image(img);
    RevealBoardFull(false);
    inPlay = false;
    didWin = true;
}

void MinesweeperBoard::LoseGame()
{
	// Display Loss Smiley
	Fl_JPEG_Image *img = new Fl_JPEG_Image("lossSmiley.jpg");
	winLoseBox->image(img);
    RevealBoardFull(true);
    winLoseBox->redraw();
    inPlay = false;
    didWin = false;
}



#pragma mark - Cheats
void MinesweeperBoard::ToggleShowMines(bool show)
{
    if (show)
    {
        for (uint32_t y = 0; y < maxY; y++)
        {
            for (uint32_t x = 0; x < maxX; x++)
            {
                TileButton* tile = boardButtons.at(y).at(x);
                
                if (tile->flagged)
                {
                    userFlags.push_back((Point){x, y});
                    SetFlagged(tile, false);
                }
                if (tile->bomb)
                {
                    SetFlagged(tile, true);
                }
                
                tile->redraw();
            }
      
        }
    }
    else
    {
        for (uint32_t y = 0; y < maxY; y++)
        {
            for (uint32_t x = 0; x < maxX; x++)
            {
                TileButton* tile = boardButtons.at(y).at(x);
                
                if (tile->bomb || tile->flagged)
                {
                    SetFlagged(tile, false);
                }
                tile->redraw();
            }
            
        }
        
        for (uint32_t i = 0; i < userFlags.size(); i++)
        {
            Point p = userFlags.at(i);
            TileButton* tile = boardButtons.at(p.y).at(p.x);
            SetFlagged(tile, true);
            tile->redraw();
        }
    }
}



#pragma mark - Private Variable Accessors
bool MinesweeperBoard::isInPlay()
{
    return inPlay;
}

bool MinesweeperBoard::getDidWin()
{
    return didWin;
}



#pragma mark - Static Callbacks
void MinesweeperBoard::TilePressedCallback(Fl_Widget* obj, void* arg)
{
    ((MinesweeperBoard*)arg)->TilePressed((TileButton*)obj);
}

void MinesweeperBoard::UpdateTimerCallback(void* arg)
{
    ((MinesweeperBoard*)arg)->UpdateTimer();
}

#pragma mark - Non-Static Callback Handlers
/// Tile pressed events happen on both the mouse up and mouse down events.
/// In order to have events happen on mouse up, we have to hold which
/// buttons are pressed on the mouse down, and then use them on mouse up.
void MinesweeperBoard::TilePressed(TileButton* obj)
{
    if (!inPlay)
    {
        obj->value(1);
        return;
    }
    
    bool leftState = Fl::event_button1();
    bool rightState = Fl::event_button3();
    
    uint8_t cause = Fl::event_button();
    bool fromLeft = (cause == FL_LEFT_MOUSE);
    bool fromRight = (cause == FL_RIGHT_MOUSE);
    
    // Left and right were both down at one point and are now both
    // released.
    if (doLeftAndRightClick && !leftState && !rightState)
    {
        LeftAndRightClick(obj);
        doLeftAndRightClick = false;
    }
    
    // Left released and right is down, or right released and left
    // is down. Means both were down at one point.
    else if ((fromLeft && rightState) || (fromRight && leftState))
    {
        doLeftAndRightClick = true;
    }
    
    // Left mouse has been released, and right was never down.
    else if (fromLeft)
    {
        LeftClick(obj);
    }
    
    // Right mouse has been released, and left was never down.
    else if (fromRight)
    {
        if (obj->hidden)
            RightClick(obj);
    }
    
    if (!startedTimer)
    {
        startedTimer = true;
        Fl::add_timeout(1.0, UpdateTimerCallback, this);
    }
}

void MinesweeperBoard::UpdateTimer()
{
    if (inPlay)
    {
        secondsSinceStart++;
        timeBox->copy_label(to_string(secondsSinceStart).c_str());
        Fl::repeat_timeout(1.0, UpdateTimerCallback, this);
    }
    else
    {
        Fl::remove_timeout(UpdateTimerCallback);
    }
}



#pragma mark - Click Helpers
void MinesweeperBoard::LeftClick(TileButton* obj)
{
    if (!obj->bomb)
    {
        obj->flagged = false;
        obj->question = false;
        RevealBoard(obj->boardX, obj->boardY);
        if (CheckWin())
            WinGame();
    }
    else if(obj->flagged)
    {
    	
	}
    else
    {
        obj->exploded = true;
        obj->hidden = false;
        obj->value(1);
        LoseGame();
    }
}

void MinesweeperBoard::RightClick(TileButton* obj)
{
    obj->value(0);
    if (!obj->flagged && obj->question)
    {
        SetFlagged(obj, false);
        obj->question = false;
    }
    else if (!obj->flagged)
    {
        SetFlagged(obj, true);
        obj->question = false;
    }
    else
    {
        SetFlagged(obj, false);
        obj->question = true;
    }
}

// Signed 64 so you can accept u32 and -1
void MinesweeperBoard::LeftAndRightClick(TileButton* obj)
{
    cout << "Valid left and right click" << endl;
    if (!obj->hidden)
    {
        // TODO(Drew): Untested
        uint8_t flaggedCount = 0;
        uint32_t x = obj->boardX;
        uint32_t y = obj->boardY;
        
        if (CheckIfFlagged(x - 1, y - 1))
            flaggedCount++;
        if (CheckIfFlagged(x - 1, y    ))
            flaggedCount++;
        if (CheckIfFlagged(x - 1, y + 1))
            flaggedCount++;
        if (CheckIfFlagged(x    , y - 1))
            flaggedCount++;
        if (CheckIfFlagged(x    , y + 1))
            flaggedCount++;
        if (CheckIfFlagged(x + 1, y - 1))
            flaggedCount++;
        if (CheckIfFlagged(x + 1, y    ))
            flaggedCount++;
        if (CheckIfFlagged(x + 1, y + 1))
            flaggedCount++;
        
        if (flaggedCount == obj->adjacent)
        {
            if (!CheckIfFlagged(x - 1, y - 1))
                BoundedLeftClick(x - 1, y - 1);
            if (!CheckIfFlagged(x - 1, y    ))
                BoundedLeftClick(x - 1, y    );
            if (!CheckIfFlagged(x - 1, y + 1))
                BoundedLeftClick(x - 1, y + 1);
            if (!CheckIfFlagged(x    , y - 1))
                BoundedLeftClick(x    , y - 1);
            if (!CheckIfFlagged(x    , y + 1))
                BoundedLeftClick(x    , y + 1);
            if (!CheckIfFlagged(x + 1, y - 1))
                BoundedLeftClick(x + 1, y - 1);
            if (!CheckIfFlagged(x + 1, y    ))
                BoundedLeftClick(x + 1, y    );
            if (!CheckIfFlagged(x + 1, y + 1))
                BoundedLeftClick(x + 1, y + 1);
        }
    }
}

void MinesweeperBoard::BoundedLeftClick(int64_t x, int64_t y)
{
    if (x < 0 || y < 0 || x > (maxX - 1) || y > (maxY - 1))
        return;
    
    TileButton* tile = boardButtons.at(y).at(x);
    LeftClick(tile);
}

bool MinesweeperBoard::CheckIfFlagged(int64_t x, int64_t y)
{
    bool ret = false;
    
    // Out of bounds
    if (x < 0 || y < 0 || x > (maxX - 1) || y > (maxY - 1))
        ret = false;
    else if (boardButtons.at(y).at(x)->flagged)
        ret = true;
    return ret;
}

void MinesweeperBoard::SetFlagged(TileButton* tile, bool val)
{
    if (tile->flagged && !val)
        flaggedBombCount--;
    else if (!tile->flagged && val)
        flaggedBombCount++;
    tile->flagged = val;
    
    uint8_t flaggedDigits = GetNumDigits(flaggedBombCount);
    uint8_t maxDigits = GetNumDigits(maxBomb);
    uint8_t numZeroes = maxDigits - flaggedDigits;
    
    string flaggedStr = to_string(flaggedBombCount);
    string maxStr = to_string(maxBomb);
    
    string dest = string(numZeroes, '0').append(flaggedStr).append("/").append(maxStr);
    bombCountBox->copy_label(dest.c_str());
}

void MinesweeperBoard::RevealBoard(int64_t x, int64_t y)
{	
    // Out of bounds
    if (x < 0 || y < 0 || x > (maxX - 1) || y > (maxY - 1))
        return;
    
    TileButton* tile = boardButtons.at(y).at(x);
    
    // Don't reveal a bomb!
    if (tile->bomb)
        return;
    
    // Already revealed. Do not check again.
    if (!tile->hidden)
        return;
    
    // From here on, reveal everything.
    tile->hidden = false;
    tile->value(1);
    tile->redraw();
    
    // Could be next to a bomb! Do not reveal more.
    if (tile->adjacent > 0)
        return;
    
    // There are no bombs next to this tile, continue check
    RevealBoard(x - 1, y);
    RevealBoard(x + 1, y);
    RevealBoard(x, y - 1);
    RevealBoard(x, y + 1);
	RevealBoard(x - 1, y - 1);
	RevealBoard(x - 1, y + 1);
	RevealBoard(x + 1, y + 1);
	RevealBoard(x + 1, y - 1);
}

void MinesweeperBoard::RevealBoardFull(bool revealBombs)
{
    for (int y = 0; y < maxY; y++)
    {
        for (int x = 0; x < maxX; x++)
        {
            TileButton* tile = boardButtons.at(y).at(x);
            if (!tile->bomb || revealBombs)
            {
                tile->hidden = false;
                tile->value(1);
            }
            else
            {
                SetFlagged(tile, true);
                tile->question = false;
            }
            tile->redraw();
        }
    }
}

#pragma mark - FLTK Widget Helpers
uint8_t MinesweeperBoard::GetNumDigits(uint32_t bombCount)
{
    uint8_t ret = 0;
    if (bombCount > 0)
    {
        ret = static_cast<uint8_t>(log10(bombCount)) + 1;
    }
    return ret;
}
