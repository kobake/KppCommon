#pragma once

class App;

class WaveSound{
protected:
	int state;
	void *buf;
	int nbuf;
	int buf_is_alloc;
public:
	//コンストラクタ・デストラクタ
	WaveSound();
	~WaveSound();
	void dispose();
	//ファイル入出力
	bool loadFile(const wchar *fpath);
	bool loadResource(App *app,int id);
	//再生・停止
	void play();
	void stop();
};

#include "c_App.h"


