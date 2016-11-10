//
//  TileButton.cpp
//  Minesweeper
//

#include "TileButton.hpp"
#include <FL/Fl.H>
#include <FL/fl_draw.H>

#pragma mark - Constructors and Destructors
TileButton::TileButton() : Fl_Button(0, 0, 16, 16)
{
    boardX = 0;
    boardY = 0;
    
    hidden = true;
    bomb = false;
    question = false;
    flagged = false;
    exploded = false;
    adjacent = 0;
}

TileButton::TileButton(const TileButton& orig) : Fl_Button(orig.x(), orig.y(), orig.w(), orig.h())
{
    boardX = orig.boardX;
    boardY = orig.boardY;
    
    hidden = orig.hidden;
    bomb = orig.hidden;
    question = orig.question;
    flagged = orig.flagged;
    exploded = orig.exploded;
    adjacent = orig.adjacent;
}

TileButton::TileButton(int x, int y, int width, int height) : Fl_Button(x, y, width, height)
{
    boardX = 0;
    boardY = 0;
    
    hidden = true;
    bomb = false;
    question = false;
    flagged = false;
    exploded = false;
    adjacent = 0;
}



#pragma mark - Tile Setup
void TileButton::PassImages(vector<Fl_Shared_Image*> imgArr, uint16_t length)
{
    for (uint16_t i = 0; i < length; i++)
    {
        this->imgArr.push_back(imgArr.at(i));
    }
}



#pragma mark - Override Methods
/// Special override allows TileButton to draw text on top of an image.
/// This function also evaluates the boolean flags of the tile to draw the
/// correct image on a tile.
/// This function also correctly colors the lines around a tile.
void TileButton::draw()
{
    if (type() == FL_HIDDEN_BUTTON)
        return;
    
    Fl_Color col = value() ? selection_color() : color();
    
    Fl_Image* img;
    
    if (value())
    {
        if (hidden)
            img = imgArr.at(revealedImg);
        else if (!bomb)
        {
            if (flagged)
                img = imgArr.at(notMineImg);
            else
            {
                img = imgArr.at(revealedImg);
                
                // Have to use const char[] to set label.
                // Cannot simply convert from int -> string
                // Therefore switch is required.
                switch (adjacent)
                {
                    case 1:
                        labelcolor(FL_BLUE);
                        label("1");
                        break;
                    case 2:
                        labelcolor(FL_GREEN);
                        label("2");
                        break;
                    case 3:
                        labelcolor(FL_RED);
                        label("3");
                        break;
                    case 4:
                        labelcolor(FL_DARK_BLUE);
                        label("4");
                        break;
                    case 5:
                        labelcolor(fl_rgb_color(153, 102, 51)); // Brown
                        label("5");
                        break;
                    case 6:
                        labelcolor(FL_CYAN);
                        label("6");
                        break;
                    case 7:
                        labelcolor(FL_BLACK);
                        label("7");
                        break;
                    case 8:
                        labelcolor(FL_GRAY0);
                        label("8");
                        break;
                }
            }
        }
        else if (exploded)
            img = imgArr.at(losingBombImg);
        else if (!hidden)
            img = imgArr.at(bombImg);
    }
    else if (question)
        img = imgArr.at(questionImg);
    else if (flagged)
        img = imgArr.at(flaggedImg);
    else if (hidden)
        img = imgArr.at(hiddenImg);
    
    if(img)
    {
        
        int xpos = (w() - img->w()) / 2;
        int ypos = (h() - img->h()) / 2;
        int xx = x() + xpos;
        int yy = y() + ypos;
        int ww = w();
        int hh = h();
        
        if (!this->hidden)
        {
            fl_color(153, 153, 153);
            fl_line(xx + ww, yy, xx, yy, xx, yy + hh);
            img->draw(xx + 1, yy + 1, ww - 1, hh - 1);
        }
        else
            img->draw(xx, yy, ww, hh);
    }
    
    if (labeltype() == FL_NORMAL_LABEL && value())
    {
        Fl_Color c = labelcolor();
        labelcolor(fl_contrast(c, col));
        draw_label();
        labelcolor(c);
    }
    else
        draw_label();
}