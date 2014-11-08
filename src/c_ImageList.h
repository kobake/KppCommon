class ImageList;

#ifndef _ImageList_
#define _ImageList_

class Icon;
class App;

class ImageList{
private:
	HIMAGELIST hImageList;
public:
	ImageList(int cx,int cy,int init_size,int max_size);
	virtual ~ImageList();
	int addIcon(App *app,int resourceid);
	int addIcon(Icon *icon);
public:
	operator HIMAGELIST() const;
};

#include "c_Icon.h"
#include "c_App.h"

#endif

