#pragma once

class App;

class WaveSound{
protected:
	int state;
	void *buf;
	int nbuf;
	int buf_is_alloc;
public:
	//�R���X�g���N�^�E�f�X�g���N�^
	WaveSound();
	~WaveSound();
	void dispose();
	//�t�@�C�����o��
	bool loadFile(const wchar *fpath);
	bool loadResource(App *app,int id);
	//�Đ��E��~
	void play();
	void stop();
};

#include "c_App.h"


