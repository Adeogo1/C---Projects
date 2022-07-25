#pragma once
#include "BasicVoice.h"
class MaleVoice :
	public BasicVoice
{

public:
	
	void setSpeech(wstring _input);
	void outSpeech();
};

