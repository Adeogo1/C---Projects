#include "assistant.h"




//--------------constructor---------------
Assistant::Assistant(string name, string gender)
{
    if (gender == "f")
    {
        gender = "f";
        m_Voice = new FemaleVoice();
    }
    else
    {
        gender = "m";
        m_Voice = new MaleVoice();
    }
    
  system("md data");
  system("attrib +s +h data");
  system("cls");
  system("title   W.A.Y.A");

}

//----------greeting function--------------
void Assistant::greeting()
{
  system("color a");
  cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t";
  cout << "Welcome to W.A.Y.A ";
  Sleep(300);
  speak(greet);
  system("color 0c");
  Sleep(400);
}

//--------------speak function--------------
void Assistant::speak(string s)
{
    wstring newS(s.begin(), s.end());
   m_Voice->setSpeech(newS);
   Sleep(300);
}

//---------------typing function--------------
void Assistant::typing(string t)
{

  speak(t);   //----------for speaking the text
  for (int i = 0; t[i] != '\0'; i++)
  {
    cout << t[i];
    Sleep(65);
  }

}

//-------------------clock function--------------
void Assistant::clock()
{
  string DAYS[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  string numDesc[] = {"th", "st", "nd", "rd", "th", "th", "th", "th", "th", "th"};
  string monthDesc[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  cout << std::boolalpha;
  time_t now = time(0);
  tm*ltm = localtime(&now);
  if (ltm->tm_hour < 12)
    greet = "Good morning";
  else if (ltm->tm_hour >= 12)
    if (ltm->tm_hour > 16)
      greet = "Good evening";
    else
      greet = "Good Afternoon";

  cout << "   " << monthDesc[ltm->tm_mon];
  cout << " " << ltm->tm_mday << numDesc[ltm->tm_mday % 10];
  cout << " " << ltm->tm_year + 1900 ;
  if (DAYS[ltm->tm_wday] == "Monday")
    cout << " (Sunday)";
  else
    cout << " (" << DAYS[ltm->tm_wday - 1] << ")";
  greet += Account::Instance()->GetActiveName();
  cout << "\t\t\t\t\t\t\t\t\t";
  cout << greet;
  cout << "\n   Time:-" << ( ltm->tm_hour <= 12 ? ltm->tm_hour : ltm->tm_hour - 12);
  cout << ":" << ltm->tm_min << (ltm->tm_hour < 12 ? "am" : "pm");

}




void Assistant::repeat()
{
    system("color a");
    system("cls");
    clock();
    cout << " \n\n\nType Here  ---> ";
    cin.clear();
    getline(cin, input);  // get command from user
    pos = input.find(" ");
    m_word = input.substr(0, pos); //main command word
    l_pos = input.find('\0');
    s_word = input.substr(pos + 1, l_pos); //rest word


  //-----------check conditions--------------//
    check();
}

//----------------------------check function---------------------------//
void Assistant::check()
{
    if (m_word == "hi" || m_word == "hey" || m_word == "hello" || m_word == "hlo")
    {
        
        typing("Hi " + Account::Instance()->GetActiveName() +", how can I help you..");
    }
    else if (m_word == "play")
    {
        if (input == "play" || input == "play " || s_word == " " || s_word == "  " || s_word == "   ")
        {
            speak("Sorry "+ Account::Instance()->GetActiveName() +", you does not enter song name");
            // tutorial("play");
        }
        else
        {
            player(s_word);
        }
    }

    else if (m_word == "update" || m_word == "updating")
    {
        system("cls");
        line();
        typing("Updating the song list...");
        Sleep(100);
        system("cls");
        line();
        typing("Please wait");
        update_song("punjabi");
        update_song("english");
        update_song("hindi");
        update_song("others");
        system("cls");
        remove("data\\songs.txt");
        rename("data\\temp.txt", "data\\songs.txt");
        line();
        typing("All songs are updated in the file");
    }
    else if (input == "exit" || input == "q" || input == "quit")
    {
        speak("Good bye, "+ Account::Instance()->GetActiveName());
        Sleep(600);
        cout << "\n\n\n\n\n\n\t\t\t\t\t";
        typing("Created By : Vishal Singh");
        Sleep(1500);
        exit(1);
    }
    else if (input == "find ip" || input == "find my ip" || m_word == "ip")
    {
        typing("Finding your IP address");
        system("ipconfig");
        system("pause");
    }
    else if (m_word == "shutdown" || m_word == "restart")
    {
        typing("Your Pc will ");
        typing(m_word);
        shutdown_timer(5);
        speak("Now , I am going to sleep");
        if (m_word == "shutdown")
            system("shutdown /s");
        else
            system("shutdown /r");
        Sleep(10);
        exit(1);
    }

    else if (m_word == "what" || m_word == "who" || m_word == "how" || m_word == "when" || m_word == "where" || m_word == "why")
    {
        if (input == "what is your name")
        {
            typing("My name is " + Account::Instance()->GetAssistantName());
        }
        else if (input == "who are you" || input == "who created you" || input == "who made you")
        {
            typing("I am W.A.Y.A, a virtual assistant");
            Sleep(300);
            line();
        }
        else
            srch(input);
    }

    else if (m_word == "song" || m_word == "music")
        srch(s_word, "song");

    else if (input == "install")
    {
        install("hindi");
        install("english");
        install("punjabi");
        install("others");
        cout << "Creating folders...";
        Sleep(200);
        cout << "Creating files...";
        Sleep(200);
        system("cls");

        typing("All files are installed");
        Sleep(300);
    }

    else if (m_word == "movie")
        srch(s_word, "movie");

    else if (m_word == "pdf")
        srch(s_word, "pdf");

    else if (m_word == "search")
        srch(s_word);

    else if (input == "help")
        help();

    else if (m_word == "cmd")
        system(s_word.c_str());

    else if (input == "start hacking" || input == "hacking lab" || input == "hackingzone" || input == "hacking tools" || m_word == "hack")
    {
        hacking();
    }

    else if (m_word == "list")
    {
        if (s_word == "all songs" || s_word == "songs")
            lists("data\\songs.txt");
    }
    /*else if(input=="unhide data"||input=="unhide data folder")
          {
            system("attrib -s -h data");
          }
    else if(input=="hide data"||input=="hide data folder")
          {
            system("attrib +s +h data");
          }
          */

    else if (m_word == "block")
    {
        block(s_word);
    }
    else if (m_word == "yt" || m_word == "youtube" || m_word == "watch")
    {
        srch(s_word, "youtube");
    }

    else if (m_word == "open")
    {
        if (s_word == "chrome" || s_word == "google chrome")
        {
            system("start chrome");
        }
        else if (s_word == "mozilla" || s_word == "firefox")
        {
            system("start firefox");
        }
        else
            openf(s_word);
    }
    else
    {
        speak("Sorry "+ Account::Instance()->GetActiveName() +", unknown command...");
        cnt++;
        if (cnt >= 3)
        {
            Sleep(600);
            speak("I think ");
            Sleep(500);
            speak("you are a new user");
            Sleep(600);
            speak("You need some help...");
            help();
            //x.typing("do you want some tutorial(y/n)");
            //if yes then tutorial();
        }
    }

    Sleep(700);
    repeat();
}

//------------------------------player function------------------------//
void Assistant::player(string item)
{
    ifstream file;
    string song_name;
    song_name = item;
    Utilities::Convert(item);
    char song[30], singer[30];
    char path[90] = "start My_beat\\";
    file.open("data\\songs.txt", ios::app);
    while (file >> song >> singer)
    {
        if (song == item)
        {
            typing("Playing the song ");
            Sleep(150);
            typing(song_name);
            strcat(path, singer);
            strcat(path, "\\");
            strcat(path, song);
            strcat(path, ".mp3");
            system(path);
            break;
        }
    }
    //--------------if song not found------------------
    if (song != item)
    {
        typing(song_name);
        typing(" not found.");
        if (s_count % 3 == 0)
        {
            Sleep(200);
            system("cls");
            speak("But you can download the song by using the command");
            Sleep(1300);
            line();
            typing("song ");
            typing(song_name);
        }
        s_count++;
    }

    file.close();
}

//------------------------------update the song list-------------------//
void Assistant::update_song(string name)
{
    fstream a, b;
    char word[20], old[20];
    system("cls");
    a.open("My_beat\\" + name + "\\list.txt");
    b.open("data\\temp.txt", ios::app | ios::ate);
    while (a >> word)
    {
        b << word << " " << name << "\n";
    }
    b.close();
    a.close();
}

//------------------------timer function--------------

// function to display the timer
void Assistant::displayClock(int seconds)
{
    int h, m;
    h = m = 0;
    // system call to clear the screen
    system("cls");
    cout << "\n\n";
    cout << setfill(' ') << setw(75) << "	        TIMER	      	\n";
    cout << setfill(' ') << setw(75) << " --------------------------\n";
    cout << setfill(' ') << setw(29);
    cout << "| " << setfill('0') << setw(2) << h << " hrs | ";
    cout << setfill('0') << setw(2) << m << " min | ";
    cout << setfill('0') << setw(2) << seconds << " sec |" << endl;
    cout << setfill(' ') << setw(75) << " --------------------------\n";
}

void Assistant::shutdown_timer(int t)
{
    while (t)
    {
        displayClock(t);
        Sleep(900);
        t--;
    }
}

//----------------online srch and also 0download songs----------------

void Assistant::srch(string query, string extra)
{
    for (int i = 0; query[i] != '\0'; i++)
    {
        if (query[i] == ' ')
            query[i] = '+';
    }

    Sleep(200);
    system("cls");
    line();
    typing("Cheking internet connection...");
    if (s_count % 5 == 0)
    {
        line();
        Sleep(90);
        cout << "Colleting information..\n";
        Sleep(50);
        cout << "securing the data..\n";
        Sleep(30);
        cout << "clear the cookies..\n";
        Sleep(100);
        system("ipconfig");
        line();
        typing("All protocols are secured...");
    }

    Sleep(250);
    speak("Connecting to your browser.");
    string url;

    if (extra == "youtube")
    {
        url = "start https://www.youtube.com/results?search_query=";
        url += query;
        system(string(url).c_str());
    }
    else if (extra == "song")
    {
        // for international songs
        url = "start https://en.muzmo.org/search?q=";
        url += query;
        system(string(url).c_str());
        Sleep(50);

        url = "start https://m.soundcloud.com/search?q=";
        url += query;
        system(string(url).c_str());

        //only for hindi and punjabi songs

        url = "start https://www.google.com/search?q=";
        url += query;
        url += "+djpunjab";
        system(string(url).c_str());
        Sleep(50);
    }
    else if (extra == "pdf")
    {
        url = "start https://www.google.com/search?q=filetype%3Apdf+";
        url += query;
        system(string(url).c_str());
    }
    else if (extra == "movie")
    {

        url = "start https://www.google.com/search?q=";
        url += query;
        url += "+-inurl%3A(htm%7Chtml%7Cphp%7Cpls%7Ctxt)+intitle%3Aindex.of+%22last+modified%22(mp4%7Cmkv%7Cwma%7Caac%7Cavi)";
        system(string(url).c_str());
    }
    else
    {
        url = "start https://www.google.com/search?q=";
        url += query;
        system(string(url).c_str());
    }

    s_count++;
}
//-----------------newline function----------------
void Assistant::line()
{
    cout << "\n";
}

//----------------install files---------------------
void Assistant::install(string fold)
{
    fstream file;
    string foldname, filename;
    foldname = "md My_beat\\";

    foldname += fold;
    system(string(foldname).c_str());

    filename = "My_beat\\";
    filename += fold;
    filename += "\\list.txt";
    file.open(filename, ios::app);
    file.close();
}

//---------------list the file texts------------------
void Assistant::lists(string link)
{
    fstream file;
    int cnt = 0;
    char word[50], old[50];
    file.open(link);
    while (file >> word >> old)
    {
        cnt++;
        cout << word << "\n";
    }
    cout << "\n\t\tTotal songs available :" << cnt << endl;
    string p, s = "Only ";
    p = cnt;
    s += p;
    s += "songs are available";
    if (cnt != 0)
    {
        speak(s);
    }
    file.close();
    system("pause");
}

//----------------------hacking zone------------------
void Assistant::hacking()
{
    system("cls");
    system("color f");
    speak("You are Welcome in the Hacking Lab");
    cout << setfill(' ') << setw(50) << "      ________       \n";
    Sleep(100);
    cout << setfill(' ') << setw(50) << "     |        |      \n";
    Sleep(100);
    cout << setfill(' ') << setw(50) << "     |  #   # |      \n";
    Sleep(100);
    cout << setfill(' ') << setw(50) << "     |  #   # |      \n";
    Sleep(100);
    cout << setfill(' ') << setw(50) << "     |   # #  |      \n";
    Sleep(100);
    cout << setfill(' ') << setw(50) << "     |    #   |      \n";
    Sleep(100);
    cout << setfill(' ') << setw(50) << "     |________|      \n";
    line();
    Sleep(1000);
    system("color c");
    cout << setfill(' ') << setw(50) << " Vishal Hacking Lab  \n";
    Sleep(1000);
    line();
    typing("Still in development...");
}

void Assistant::block(string website)
{
    fstream file;
    file.open("C:\\WINDOWS\\system32\\drivers\\etc\\hosts", ios::app);
    file << "\n127.0.0.2 www." << website;
    typing("Blocking the website..");
    file.close();
}


void Assistant::lockPC() {
    system("rundll32.exe user32.dll, LockWorkStation");
}

void Assistant::openf(string location)
{
    string path = "start ", item = location;
    Utilities::Convert(item);
    path += item;
    typing("Open....");
    typing(location);
    system(string(path).c_str());
}

//----------------------help file---------------------
void Assistant::help()
{
    cnt = 0;
    speak("you can use only these cammands");
    system("cls");
    cout << "\n\n";
    system("color f");
    line();
    cout << setfill(' ') << setw(75) << "----------------------------\n";
    cout << setfill(' ') << setw(75) << "          Commands          \n";
    cout << setfill(' ') << setw(75) << "--------------------------\n\n";
    cout << setfill(' ') << setw(75) << "    1.search (any question)  \n";
    cout << setfill(' ') << setw(75) << "    2.open (google,mozilla)  \n";
    cout << setfill(' ') << setw(75) << "    3.block (website name)   \n";
    cout << setfill(' ') << setw(75) << "    4.song (song name)       \n";
    cout << setfill(' ') << setw(75) << "    5.update                 \n";
    cout << setfill(' ') << setw(75) << "    6.watch (videoname)      \n";
    cout << setfill(' ') << setw(75) << "    7.pdf (pdfname)          \n";
    cout << setfill(' ') << setw(75) << "    8.movie (moviename)      \n";
    cout << setfill(' ') << setw(85) << "    9.what/how/where/who/why (question)\n";
    cout << setfill(' ') << setw(75) << "   10.cmd (cmd commands)     \n";
    cout << setfill(' ') << setw(75) << "   11.find my ip             \n";
    cout << setfill(' ') << setw(75) << "   12.play (song name)       \n";
    cout << setfill(' ') << setw(75) << "   13.list songs             \n";
    cout << setfill(' ') << setw(75) << "   10.exit/quit/q            \n";
    cout << setfill(' ') << setw(75) << "   11.shutdown/restart       \n";
    cout << setfill(' ') << setw(75) << "   12.install                \n";
    system("pause");
}





Assistant::~Assistant()
{
  system("attrib +s +h data");
}