#include "include_sys.h"
#include "id/res.h"
#include "c_FileStream.h"
#include "c_WaveSound.h"

#define STATE_NONE		0
#define STATE_MEMORY	1

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //
// -- -- -- -- -- -- -- -- -- -- -- --  コンストラクタ・デストラクタ  -- -- -- -- -- -- -- -- -- -- -- -- //
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //

WaveSound::WaveSound()
{
	state=STATE_NONE;
	buf=NULL;
	nbuf=0;
	buf_is_alloc=0;
}

WaveSound::~WaveSound()
{
	dispose();
}

void WaveSound::dispose()
{
	if(buf_is_alloc==1){
		free(buf);
	}
	buf=NULL;
	nbuf=0;
	state=STATE_NONE;
	buf_is_alloc=0;
}

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //
// -- -- -- -- -- -- -- -- -- -- -- -- ファイル入出力  -- -- -- -- -- -- -- -- -- -- -- -- -- -- //
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //

bool WaveSound::loadFile(const wchar *fpath)
{
	dispose();
	//
	FileStream in;
	if(in.open(fpath,L"rb")){
		buf=in.readAllAlloc();
		buf_is_alloc=1;
		in.close();
		state=STATE_MEMORY;
		return true;
	}else{
		return false;
	}
}
bool WaveSound::loadResource(App *app,int id)
{
	dispose();
	//
	buf=app->loadResource(id,WAVE);
	if(buf!=NULL){
		state=STATE_MEMORY;
		return true;
	}else{
		return false;
	}
}

// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //
// -- -- -- -- -- -- -- -- -- -- -- --  再生・停止  -- -- -- -- -- -- -- -- -- -- -- -- -- -- //
// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- //

void WaveSound::play()
{
	if(state==STATE_MEMORY){
		PlaySound((wchar*)buf,NULL,SND_MEMORY | SND_ASYNC);
	}
}

void WaveSound::stop()
{
	PlaySound(NULL,NULL,0);
}


