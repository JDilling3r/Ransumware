
Conversation opened. 1 read message.

Skip to content
Using Gmail with screen readers
Meet
New meeting
Join a meeting
Hangouts

1 of 23
scare
Inbox

Johnathan Benge <jbenge3@my.wgu.edu>
Attachments
Mon, Nov 15, 5:17 PM (15 hours ago)
to bigfootdlb, me

ware

Attachments area
// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <shlobj.h>
#pragma comment(lib, "shell32.lib")
#pragma warning(disable : 4996)

using namespace std;

//////////////////
// Global Casts //
//////////////////

int click;

///////////////////////
// Global Variables //
//////////////////////

string allUsers = "ALL USERSPROFILE";
string appData = "APPDATA";
string comProgFiles = "CommonProgramFiles";
string comProgFiles86 = "CommonProgramFiles(x86)";
string computerName = "COMPUTERNAMES";
string comSpec = "ComSpec";
string driverData = "DriverData";
string homeDrive = "HOMEDRIVE";
string homePath = "HOMEPATH";
string localAppData = "LOCALAPPDATA";
string logonServer = "LOGONSERVER";
string numProcessors = "NUMBER_OF_PROCESSORS";
string os = "OS";
string path = "Path";
string procArch = "PROCESSOR_ARCHITECHTURE";
string procID = "PROCESSOR_REVISION";
string procLevel = "PROCESSOR_LEVEL";
string procRev = "PROCESSOR_REVISION";
string procData = "ProgramData";
string progFiles = "ProgramFiles";
string progFiles86 = "ProgramFiles(x86)";
string pathPublic = "PUBLIC";
string sysDrive = "SystemDrive";
string sysRoot = "SystemRoot";
string temp = "TEMP";
string userDomain = "USERDOMAIN";
string userRoamingProf = "USERDOMAIN_ROAMINGPROFILE";
string userName = "USERNAME";
string userProfile = "USERPROFILE";
extern char** environ;

/////////////////
// Warning Box //
/////////////////

int main()
{
    {
        // Message box tricks the user into selecting and option.
        int msgboxID = MessageBox(
            NULL,
            (LPCWSTR)L"Would you like to install the program?",
            (LPCWSTR)L"Ransumware detected!",
            MB_ICONQUESTION | MB_YESNOCANCEL | MB_DEFBUTTON2
        );

        // This switch statement enacts the rest of the code below, regardless of selection.
        switch (msgboxID)
        {
        case IDYES:
            click = 1;
            break;
        case IDNO:
            click = 1;
            break;
        case IDCANCEL:
            click = 1;
            break;
        }
    }
    if (click == 1)
    {
        // Changes Background

        // The goal for the code section below is to search through the complete list of environmental
        // variables until you find the one you want.  Take the output, strip off everything to the left, including
        // the equal sign and find files on the desktop as an example.  Current Status: NOT COMPLETE.
        /*
        char** sLine = environ;
        sLine = enviros.data();
        for (; *sLine, sLine++)
        {
            enviros.push_back(sLine);
            std::cout << *sLine << endl;
        }

        std::_Adjust_manually_vector_aligned<std::string>::iterator i;
        i = std::find(enviros.begin(), enviros.end(), "HOMEPATH";
        if (i != enviros.end())
            std::cout << "found it";
        else
            std::cout << "not there";

        for (int i = 0; i < enviros.size(); i++)
            std::cout << i << enviros.at(i) << endl;

        std::cout << "This number of things: " << enviros.size() << endl;
        */

        // For simplicity due to time constraints, this is the faster way in order to get the home path to affect
        //changes on the target machine.

        WIN32_FIND_DATA FindFileData;
        HANDLE hFindFile;

        // The next section, getenv, can only accept char* inputs.  The next section of code will convert it from a
        //string value into a char function in order to render an output.



        char* var = getenv("HOMEPATH");
        std::cout << var;

        //add file changing .txt and .pdf extension changes


        //Works to find the length of string in the environmental variable
        char a[1000];
        int envarLength = GetEnvironmentVariableA("USERPROFILE", a, 1000);

        //Message box after selecting any option.  The result is the same another message box with the given words
        int msgboxID = MessageBox(
            NULL,
            (LPCWSTR)L"Computer Files Encrypted: ",
            (LPCWSTR)L"You Didn't say the Magic Word",
            MB_ICONSTOP | MB_OK | MB_DEFBUTTON2
        );
    }
}
        /*
        int i = 0;
        int dit = 20;
        int dah = dit * 3;
        int symbolSleep = dit;
        int letterSleep = dah;
        int wordSleep = dit * 7;

        //Nearly endless repeating 'NRT' morse code.

        while (i < 2000000000)
        {
            //N morse code length
            Beep(523, dah);
            Sleep(symbolSleep);
            Beep(523, dit);
            cout << "N";
            Sleep(letterSleep);
            //R morse code Length
            Beep(523, dit);
            Sleep(symbolSleep);
            Beep(523, dah);
            Sleep(symbolSleep);
            Beep(523, dit);
            cout << "R";
            Sleep(letterSleep);
            //T Morse Code Length
            Beep(523, dah);
            cout << "T\n";

            cout << i << endl;
            i++;
            Sleep(wordSleep);
        }
        
    }
    return 0;

}
*/

/*
int fileList()
{
    string path = "/";

    for (const auto & file : directory_iterator)
    
    //TCHAR szPath[MAX_PATH];
    //filePath = SHGetFolderPath(NULL, CSIDL_DESKTOP, NULL, 0, szPath);
    

    return 0;
}
*/

/*
int main()
{
    fileType = ".ransum";
    //string fileType;
    cout << "This is your variable: ";
    cout << "\n" << fileType;
    cout << endl;
    return 0;
}

*/
scarewareTest.txt
Displaying scarewareTest.txt.