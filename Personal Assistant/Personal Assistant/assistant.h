#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <string.h>
//#include <unistd.h>
#include <ctype.h>
#include <ctime>
#include <process.h>
#include <windows.h>
#include "MaleVoice.h"
#include "FemaleVoice.h"
#include "bits-stdc++.h"
#include "Utilities.h"
#include "Account.h"

using namespace std;

class Assistant
{

public:
    Assistant(string name, string gender);
  ~Assistant();
  void greeting();
  void typing(string);
  void clock();
  void speak(string);
  void check();   //compare the user input with defined commands
  void line();      // create new line
  void repeat();     //ask user input again.
  void shutdown_timer(int);
  void player(string);  //search the song from file(songs.txt) then play the song.
  void help();          //show commands
  void hacking();       
  void install(string); // create music folders
  void block(string);  //block the websites
  void lockPC();
  void openf(string);   // open the file directory
  void lists(string);   //show song list
  void srch(string, string extra = "");
  void update_song(string);   //copy song name from different files(list.txt) file into one file(songs.txt)
  void displayClock(int seconds);

  char GetGender() {
      return gender;
  }



private:
  char gender;
  BasicVoice* m_Voice = nullptr;
  string greet;
  string input;
  int pos, l_pos, cnt = 0;
  string m_word, s_word;
  int s_count = 0;

};
