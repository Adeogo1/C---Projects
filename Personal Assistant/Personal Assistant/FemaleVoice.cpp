#include "FemaleVoice.h"

void FemaleVoice::setSpeech(wstring _input)
{
	//int choice;
	if (SUCCEEDED(hr))
	{
		hr = pVoice->Speak((L"<voice required='Gender = Female;'>" + _input).c_str(), 0, NULL);
	}

	
	
}

void FemaleVoice::outSpeech()
{
	pVoice->Release();
	pVoice = NULL;
	::CoUninitialize();
}

