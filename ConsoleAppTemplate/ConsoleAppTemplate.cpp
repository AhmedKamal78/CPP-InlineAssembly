#include <iostream>
#include "ConsoleUtils.h"

using namespace std;

ConsoleUtils utils;


//*****************************************
//					MAIN
//*****************************************
int main(int argc, char* argv[])
{
#pragma region header
	//--- setup console utils   
	utils.enableVirtualTerminal();
	utils.setBackgroundColor(ConsoleColor::Blue);
	utils.clearConsole();

	//--- show app title
	utils.setForegroundColor(ConsoleColor::BrightWhite);
	cout << "+-------------------------------+\n";
	cout << "| Console App Networking??????  |\n";
	cout << "+-------------------------------+\n\n";
#pragma endregion


	//--- App BODY --------------------------------
	//---------------------------------------------


#pragma region footer
	//--- show credits
	utils.setForegroundColor(ConsoleColor::White);
	std::cout << std::endl;
	utils.showCredits();

	system("pause");
	// this is a better way to avoid unnec instructions when debugger finishes
	// we also select this option ==> Tools->Options->Debugging->Automatically close the console when debugging stops.

	//--- exit console
	return 0;
#pragma endregion
}