#pragma once
#include <string>
#include <iostream>
using namespace std;


static class Utilities
{
public:
	Utilities();

	static void LowerCase(char *word);
    static void Convert(string& c, char* from, char* to);   
    static void Convert(string&);   //convert 'space( )' to 'underscore'( _ ) and lowercase string
	~Utilities();



};

