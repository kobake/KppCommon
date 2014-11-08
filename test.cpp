#include <cstdio>

class A;
class A{
public:
	A(int i)
	{
	}
};
class B : public A{
};

int f()
{
	A a(1);
	return 0;
}

/*
#include <cstdio>

class A;                 // エラー, A は定義されていません
//class B : public A {};   // エラーはここで検出されます

void f(A *a);

class A {};              // OK, A は定義されています
*/
/*
#ifndef DEF_ACCELERATOR
#ifndef DEF_APP
#ifndef DEF_BITMAP256
#ifndef DEF_BITMAP_SELECTOR
#ifndef DEF_BUTTON
#ifndef DEF_CHECK_BOX
#ifndef DEF_CLIPBOARD
#ifndef DEF_COLOR_BOX
#ifndef DEF_COMBO_BOX
#ifndef DEF_DIR_SELECT_DIALOG
#ifndef DEF_EDIT_BOX
#ifndef DEF_EDIT_FIELD
#ifndef DEF_FILE_DETAIL
#ifndef DEF_FILE_LIST
#ifndef DEF_FILENAME
#ifndef DEF_FILE_SELECT_DIALOG
#ifndef DEF_FILE_VIEW
#ifndef DEF_FONT
#ifndef DEF_FTP
#ifndef DEF_ICON
#ifndef DEF_IMAGE_LIST
#ifndef DEF_INDEX_TABLE
#ifndef DEF_INI_FILE
#ifndef DEF_INTERNET
#ifndef DEF_LABEL
#ifndef DEF_LIST_BOX
#ifndef DEF_LIST_VIEW
#ifndef DEF_MENU
#ifndef DEF_OVERLAPPED_WINDOW
#ifndef DEF_PROGRESS_BAR
#ifndef DEF_PROPERTY
#ifndef DEF_PROPERTY_RLIST
#ifndef DEF_RECT_CURSOR
#ifndef DEF_SCREEN
#ifndef DEF_SCROLL_WINDOW
#ifndef DEF_SCROLLMANAGER
#ifndef DEF_SOCKET
#ifndef DEF_STRING_LIST
#ifndef DEF_SYSTEM_TIME
#ifndef DEF_TIME_WATCH
#ifndef DEF_WINDOW
#ifndef DEF_CHAIN
#ifndef DEF_CHAIN2
#ifndef DEF_CHAIN3
#ifndef DEF_NONCHAIN_LIST
*/
