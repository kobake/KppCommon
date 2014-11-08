#pragma once

namespace gr{
class Graphics;
}
using namespace gr;

#include <GraphicsLib.h> //CColor

class VirtualMap{
public:
	virtual int getDataWidth()=0;	//実データサイズ（ex:256）
	virtual int getDataHeight()=0;	//
	virtual int getPixelsPerX()=0;	//実データ１あたりのピクセル幅
	virtual int getPixelsPerY()=0;	//
	virtual int draw(Graphics *g,int dst_x,int dst_y,int src_x,int src_y,int src_w,int src_h)=0;
public:
	int getVisibleWidth() { return getDataWidth() *getPixelsPerX(); }
	int getVisibleHeight(){ return getDataHeight()*getPixelsPerY(); }
	bool ptIn(POINT *pt){ return pt->x>=0 && pt->x<getDataWidth() && pt->y>=0 && pt->y<getDataHeight(); }
	bool ptIn(int x,int y){ return x>=0 && x<getDataWidth() && y>=0 && y<getDataHeight(); }
};
void drawMap(Graphics *g,RECT *_rcUpdate,VirtualMap *map,int map_x,int map_y,const CColor& side_color=CColor(0,0,0));
void drawMap(Graphics *g,int _dst_x,int _dst_y,int _dst_w,int _dst_h,VirtualMap *map,int src_x,int src_y,const CColor& side_color=CColor(0,0,0));

#include "c_Graphics.h"


