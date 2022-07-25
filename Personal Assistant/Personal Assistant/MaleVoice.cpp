#include "MaleVoice.h"

void MaleVoice::setSpeech(wstring _input)
{
	if (SUCCEEDED(hr))
	{
		//if you're having an issue with line dont frget to do cin.ignore
		hr = pVoice->Speak(_input.c_str(), 0, NULL);
	}
	else
	{
		cout << "NOt Initalized";
		exit(-1);
	}
	system("cls");
	
		
	/*    HRESULT Speak(
   LPCWSTR       *pwcs,pwcs
[in, string] Pointer to the null-terminated text string (possibly containing XML markup) to be synthesized. This value can be NULL when dwFlags is set to SPF_PURGEBEFORESPEAK indicating that any remaining data to be synthesized should be discarded. If dwFlags is set to SPF_IS_FILENAME, this value should point to a null-terminated, fully qualified path to a file.
   DWORD          dwFlags,dwFlags
[in] Flags used to control the rendering process for this call. The flag values are contained in the SPEAKFLAGS enumeration.
   ULONG         *pulStreamNumber
   [out] Pointer to a ULONG which receives the current input stream number associated with this Speak request. Each time a string is spoken, an associated stream number is returned. Events queued back to the application related to this string will contain this number. If NULL, no value is passed back.

);

*/
}

void MaleVoice::outSpeech()
{
	pVoice->Release();
	pVoice = NULL;
	::CoUninitialize();

}

