class Toolbar;

#ifndef DEF_TOOLBAR
#define DEF_TOOLBAR

#include "c_Window.h"

class Toolbar : public Window{
public:
	Toolbar(TBBUTTON *button_param,int button_num,int bmp_id,int bmp_num,Window *_parent,int _option=0,int _id=UNIQUE_ID);
	Toolbar(TBBUTTON *button_param,int button_num,Bitmap *bmp,int bmp_num,Window *_parent,int _option=0,int _id=UNIQUE_ID);
	virtual ~Toolbar();
	//
	void setCheckByID(int id,bool check);
	void setEnabledByID(int id,bool e);
};

#endif
