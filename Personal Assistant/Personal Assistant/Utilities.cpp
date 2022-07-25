#include "Utilities.h"

Utilities::Utilities()
{
}

inline void Utilities::LowerCase(char* word)
{
}

void Utilities::Convert(string& c, char* from, char* to)
{

    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] == *from)
            c[i] = *to;
        c[i] = tolower(c[i]);
    }
}


void Utilities::Convert(string& c)
{

    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] == ' ')
            c[i] = '_';
        c[i] = tolower(c[i]);
    }
}


Utilities::~Utilities()
{
}

