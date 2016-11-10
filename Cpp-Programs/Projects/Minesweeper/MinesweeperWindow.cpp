//
//  MinesweeperWindow.cpp
//  Minesweeper
//

#include "MinesweeperWindow.hpp"
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_JPEG_Image.H>

#pragma mark - Constructors and Destructors
/// Size is initally set to 0, 0 because EasyDifficulty() will resize the
/// window to its proper size
MinesweeperWindow::MinesweeperWindow(const char* title) : Fl_Window(0, 0, title)
{
    fl_register_images();
    
    LoadImages();
    
    SetUpScreen();
    
    EasyDifficulty();
}

MinesweeperWindow::~MinesweeperWindow()
{
    if (board != nullptr)
        delete board;
    if (menuBar != nullptr)
        delete menuBar;
    if (bombCountBox != nullptr)
        delete bombCountBox;
    if (timeBox != nullptr)
        delete timeBox;
    if (winLoseBox != nullptr)
        delete winLoseBox;
}



#pragma mark - Initialization Methods
void MinesweeperWindow::LoadImages()
{
    imgArr.push_back(Fl_Shared_Image::get("coveredTile.jpg"));
    imgArr.push_back(Fl_Shared_Image::get("emptyUncoveredTile.jpg"));
    imgArr.push_back(Fl_Shared_Image::get("mine.jpg"));
    imgArr.push_back(Fl_Shared_Image::get("losingMine.jpg"));
    imgArr.push_back(Fl_Shared_Image::get("question.jpg"));
    imgArr.push_back(Fl_Shared_Image::get("flaggedMine.jpg"));
    imgArr.push_back(Fl_Shared_Image::get("incorrectMine.jpg"));
}

void MinesweeperWindow::SetUpScreen()
{
    begin();
    
    Fl_Menu_Item menuTable[] =
    {
        {"&Game", FL_ALT + 'g', 0, 0, FL_SUBMENU},
        {"New Game", FL_F + 2, MinesweeperWindow::NewGameCallback, this},
        {"Set &Difficulty", FL_ALT + 'd', 0, 0, FL_MENU_DIVIDER},
        {"&Beginner", FL_ALT + 'b', MinesweeperWindow::EasyDifficultyCallback, this, FL_MENU_RADIO | FL_MENU_VALUE},
        {"&Intermediate", FL_ALT + 'i', MinesweeperWindow::MediumDifficultyCallback, this, FL_MENU_RADIO},
        {"&Expert", FL_ALT + 'e', MinesweeperWindow::HardDifficultyCallback, this, FL_MENU_RADIO},
        {"&Custom", FL_ALT + 'c', MinesweeperWindow::CustomDifficultyCallback, this, FL_MENU_RADIO | FL_MENU_DIVIDER},
        {"Exit", FL_ALT + FL_F + 4, MinesweeperWindow::ExitCallback, this},
        {0},
        {"&Debug", FL_ALT + 'd', 0, 0, FL_SUBMENU},
        {"Toggle &show mines", FL_ALT + 's', MinesweeperWindow::ShowMinesCallback, this, FL_MENU_TOGGLE},
        {"&Win", FL_ALT + 'w', MinesweeperWindow::ForceWinCallback, this},
        {0},
        {"&About", FL_ALT + 'a', MinesweeperWindow::AboutCallback, this}, 
		{0},
        {0}
    };


    menuBar = new Fl_Menu_Bar(0, 0, 0, 30);
    menuBar->copy(menuTable);
    
    bombCountBox = new Fl_Box(cornerOffsetX, cornerOffsetY - 44, 0, 30);
    bombCountBox->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    
    winLoseBox = new Fl_Box(cornerOffsetX, cornerOffsetY - 44, 0, 30);
    winLoseBox->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    
    timeBox = new Fl_Box(cornerOffsetX, cornerOffsetY - 44, 0, 30);
    timeBox->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);
    
    end();
    show();
}



#pragma mark - Override Methods
/// This override of draw puts frames around the gameplay area and information
/// box to increase visibility.
void MinesweeperWindow::draw()
{
    Fl_Window::draw();
    fl_frame("NNWW", cornerOffsetX - 2, cornerOffsetY - 46, (board->maxX * 16) + 4, 34);
    fl_frame("NNWW", cornerOffsetX - 1, cornerOffsetY - 45, (board->maxX * 16) + 2, 32);
    fl_frame("NNWW", cornerOffsetX - 2, cornerOffsetY - 2, (board->maxX * 16) + 4, (board->maxY * 16) + 4);
    fl_frame("NNWW", cornerOffsetX - 1, cornerOffsetY - 1, (board->maxX * 16) + 2, (board->maxY * 16) + 2);
}



#pragma mark - Static Callbacks
void MinesweeperWindow::NewGameCallback(Fl_Widget* obj, void* arg)
{
    ((MinesweeperWindow*)arg)->NewGame();
}

void MinesweeperWindow::ExitCallback(Fl_Widget* obj, void* arg)
{
    exit(0);
}

/// Checks if button is toggled to tell the program to activate or deactivate
/// cheats.
void MinesweeperWindow::ToggleCheatsCallback(Fl_Widget* obj, void* arg)
{
    const Fl_Menu_Item* item = ((Fl_Menu_*)obj)->mvalue();
    bool b = (bool)(item->flags & FL_MENU_VALUE);
    ((MinesweeperWindow*)arg)->ToggleCheats(b);
}

/// Checks if button is toggled to tell the program to show or hide mines.
void MinesweeperWindow::ShowMinesCallback(Fl_Widget* obj, void* arg)
{
    const Fl_Menu_Item* item = ((Fl_Menu_*)obj)->mvalue();
    bool b = (bool)(item->flags & FL_MENU_VALUE);
    ((MinesweeperWindow*)arg)->board->ToggleShowMines(b);
}

void MinesweeperWindow::ForceWinCallback(Fl_Widget* obj, void* arg)
{
    ((MinesweeperWindow*)arg)->ForceWin();
}

void MinesweeperWindow::EasyDifficultyCallback(Fl_Widget* obj, void* arg)
{
    ((MinesweeperWindow*)arg)->EasyDifficulty();
}

void MinesweeperWindow::MediumDifficultyCallback(Fl_Widget* obj, void* arg)
{
    ((MinesweeperWindow*)arg)->MediumDifficulty();
}

void MinesweeperWindow::HardDifficultyCallback(Fl_Widget* obj, void* arg)
{
    ((MinesweeperWindow*)arg)->HardDifficulty();
}

void MinesweeperWindow::AboutCallback(Fl_Widget* obj, void* arg)
{
	Fl_Window *window = new Fl_Window(900, 600, "About");
	//Drew
	Fl_Box *box1a = new Fl_Box(0,0,300,200,"Drew Mills\n\n\n\n\n\n");
  	box1a->box(FL_UP_BOX);
  	box1a->labelfont(FL_BOLD);
  	box1a->labelsize(24);
  	Fl_Box *box1b = new Fl_Box(10,50,280,140,"Junior CSE major - Grad class of 2017\n\n\"Sometimes I imagine myself as neo in \'The \nMatrix\'. Except I already know Kung Fu.\"");
  	box1b->box(FL_DOWN_BOX);
  	box1b->labelfont(FL_BOLD);
  	box1b->labelsize(12);
  	//Nathan
	Fl_Box *box2a = new Fl_Box(300,0,300,200,"Nathan Perkins\n\n\n\n\n\n");
  	box2a->box(FL_UP_BOX);
  	box2a->labelfont(FL_BOLD);
  	box2a->labelsize(24);
  	Fl_Box *box2b = new Fl_Box(310,50,280,140,"Junior CSE major - Grad class of 2017\n\n\"The only thing that has ever told me \'I love \nyou\' was cout. In my code.\"");
  	box2b->box(FL_DOWN_BOX);
  	box2b->labelfont(FL_BOLD);
  	box2b->labelsize(12);
  	//Josephine
  	Fl_Box *box3a = new Fl_Box(600,0,300,200,"Josephine Cornelius\n\n\n\n\n\n");
  	box3a->box(FL_UP_BOX);
  	box3a->labelfont(FL_BOLD);
  	box3a->labelsize(24);
  	Fl_Box *box3b = new Fl_Box(610,50,280,140,"Junior CSE major - Grad class of 2017\n\n\"I watch movies like \'Bambi\' and \'Marley \nand me\' just so I can get a good laugh.\"");
  	box3b->box(FL_DOWN_BOX);
  	box3b->labelfont(FL_BOLD);
  	box3b->labelsize(12);
  	
  	Fl_JPEG_Image *img1 = new Fl_JPEG_Image("drew.jpg");
  	Fl_Box *box4 = new Fl_Box(0,200,300,400);
  	box4->box(FL_UP_BOX);
  	box4->labelsize(24);
  	box4->image(img1);
  	
  	Fl_JPEG_Image *img2 = new Fl_JPEG_Image("nathan.jpg");
  	Fl_Box *box5 = new Fl_Box(300,200,300,400);
  	box5->box(FL_UP_BOX);
  	box5->labelsize(24);
  	box5->image(img2);
  	
  	Fl_JPEG_Image *img3 = new Fl_JPEG_Image("josephine.jpg");
  	Fl_Box *box6 = new Fl_Box(600,200,300,400);
  	box6->box(FL_UP_BOX);
  	box6->labelsize(24);
  	box6->image(img3);
  	
  	
	window->show();
}

/// This callback creates a new CustomSizeWindow and then shows it to the user.
/// If the user cancels changes, then we must revert to the previous checked
/// difficulty selection. If it is accepted, we must call the local method.
void MinesweeperWindow::CustomDifficultyCallback(Fl_Widget* obj, void* arg)
{
    CustomSizeWindow* window = new CustomSizeWindow();
    window->set_modal();
    window->show();
    while (window->shown()) Fl::wait();
    
    if (window->didAccept)
    {
        ((MinesweeperWindow*)arg)->CustomDifficulty(window->tileX, window->tileY, window->bombCount);
    }
    else
    {
        ((MinesweeperWindow*)arg)->CustomDifficultyRevert();
    }
    delete window;
}



#pragma mark - Non-Static Callback Handlers
/// Adds or removes new menu items to the debug menu. In the case of false,
/// also deactivates all activated cheats.
/// @TODO Do we have any cheats that we actually want? Is it better to call
/// this debug instead? All of this still needs to be implemented. Ideas
/// include function printout, variable printout, set board seed.

void MinesweeperWindow::ToggleCheats(bool b)
{

}

void MinesweeperWindow::ForceWin()
{
    board->WinGame();
}

void MinesweeperWindow::NewGame()
{
    CustomDifficulty(board->maxX, board->maxY, board->maxBomb);
}

void MinesweeperWindow::EasyDifficulty()
{
    CustomDifficulty(9, 9, 10);
}

void MinesweeperWindow::MediumDifficulty()
{
    CustomDifficulty(16, 16, 40);
}

void MinesweeperWindow::HardDifficulty()
{
    CustomDifficulty(30, 16, 99);
}

/// This function is called by all of the new game options with constant
/// parameters. It deletes the old board, and creates a new one. Then it
/// resizes the window and all screen objects to make them fit
void MinesweeperWindow::CustomDifficulty(uint32_t tileX, uint32_t tileY, uint32_t bombCount)
{
    if (board != nullptr)
        delete board;
    
    board = new MinesweeperBoard(bombCountBox, winLoseBox, timeBox, tileX, tileY);
    
    resize(x_root(), y_root(), tileX * 16 + 24, tileY * 16 + 98);
    menuBar->resize(0, 0, decorated_w(), 30);
    bombCountBox->resize(cornerOffsetX, cornerOffsetY - 44, tileX * 16, 30);
    winLoseBox->resize(cornerOffsetX, cornerOffsetY - 44, tileX * 16, 30);
    timeBox->resize(cornerOffsetX, cornerOffsetY - 44, tileX * 16, 30);
    
    begin();
    
    board->InitTiles(cornerOffsetX, cornerOffsetY, imgArr, imgCountTile);
    end();
    redraw();
    
    Fl_Menu_Item* item = (Fl_Menu_Item*)menuBar->find_item("&Debug/Toggle &show mines");
    item->clear();
    
    board->SetUpBoard(bombCount);
}

void MinesweeperWindow::CustomDifficultyRevert()
{
    uint8_t idxToSet;
    
    if (board->maxX == 9 && board->maxY == 9 && board->maxBomb == 10)
        idxToSet = menuBar->find_index("&Game/&Beginner");
    else if (board->maxX == 16 && board->maxY == 16 && board->maxBomb == 40)
        idxToSet = menuBar->find_index("&Game/&Intermediate");
    else if (board->maxX == 30 && board->maxY == 16 && board->maxBomb == 99)
        idxToSet = menuBar->find_index("&Game/&Expert");
    else
        idxToSet = menuBar->find_index("&Game/&Custom");
        
    Fl_Menu_Item* set = (Fl_Menu_Item*)&(menuBar->menu()[idxToSet]);
    set->setonly();
}
