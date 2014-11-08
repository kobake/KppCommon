#include "include_sys.h"
#include "c_Screen.h"
#include "id/class.h"


Screen::Screen()
: Window(CID_SCREEN,0,NULL,0,UNIQUE_ID)
{
	hwnd=GetDesktopWindow();
	onWindowSize(-1,-1,-1,-1);
}
Screen::~Screen()
{
	hwnd=NULL;
}
