#pragma once
#include "BasicVoice.h"
class FemaleVoice : public BasicVoice
{
public:
	void setSpeech(wstring _input);
	void outSpeech();
};