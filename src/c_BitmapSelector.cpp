#include <windows.h>
#include <cstdio>
#include <string>
using namespace std;
#include "c_App.h"
#include "c_BitmapSelector.h"
#include "f_base.h"
#include "f_window.h"
#include "util/std.h"



void BitmapSelector::drawData(Graphics *g,int xoff,int yoff)
{
	if(bmp==NULL)return;
	int bw=bmp->GetSize().w;
	int bh=bmp->GetSize().h;
	int x=xoff*32;
	int y=yoff*32;
	int w=tmin<int>(rcClient.right,bw-x);
	int h=tmin<int>(rcClient.bottom,bh-y);
	//ビットマップ
	if(w>0 && h>0){
		g->drawImage(CPoint(0,0),*bmp,CRect(x,y,w,h));
	}
	//サイド塗りつぶし
	if(w<0)w=0;
	if(h<0)h=0;
	g->SetColor(CColor(128,128,128));
	g->FillRect(CRect(0,h,rcClient.right-0,rcClient.bottom-h));
	g->FillRect(CRect(w,0,rcClient.right-w,h-0));
}




BitmapSelector::BitmapSelector(const wstring& caption,int x,int y,int w,int h,Window *_parent,int _option,int _id)
: ScrollDataWindow(WS_EX_TOOLWINDOW,WS_SYSMENU | WS_SIZEBOX | WS_HSCROLL | WS_VSCROLL,caption,x,y,w,h,_parent,_option,_id)
{
	bmp=NULL;
	sendSize();
}

BitmapSelector::~BitmapSelector()
{
}

void BitmapSelector::setBitmap(Dib *_bmp)
{
	bmp=_bmp;
	realizeBitmap();
}

void BitmapSelector::realizeBitmap()
{
	setCursorPos(0);
	Window::sendSize(); //スクロールバー更新
	repaint(false);
}


