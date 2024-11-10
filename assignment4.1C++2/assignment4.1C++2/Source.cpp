//Libraries
#include <iostream>
#include <String>
#include <thread>
#include <mutex>
#include <windows.h>

using namespace std;
mutex mtx;
string Brand;
int Boosters;
int Countdown;

int BlastDialog(int x)
{
	if (x == 0)
	{
		return 0;
	}
	else
	{
		cout << "Booster #" << x << " is detaching... \n";
		Sleep(3000);
		cout << "Detached!\n";
		return BlastDialog(x - 1);
	}

}

int CountdownDialog(int x)
{
	if (x == 0)
	{
		cout << "Liftoff!";
		return 1;
	}
	else
	{
		cout << x << "\n";
		Sleep(1000);
		return CountdownDialog(x - 1);
	}
}

int main()
{
	

	//Prompt #1
	cout << "Name your company brand \n";
	cin >> Brand;
	//Prompt #2
	try
	{
		cout << "How many boosters does your rocket have? \n";
		cin >> Boosters;
		if (Boosters > 10)
		{
			Boosters = 10;
			throw "Error: Too large of a number, defaulting to 10";
			
		}
		if (Boosters < 2)
		{
			Boosters = 2;
			throw "Error: Too Small of a number, defaulting to 2";
		}
	}
	catch (const char* msg) // Catch block to display the message.
	{
		cerr << msg << "\n";
	}

	//Prompt #3
	cout << "How long is the countdown (!! Do not make it a huge number! !!) \n";
	cin >> Countdown;
	//Generation of the story
	cout << "Generating with answers... \n";
	Sleep(3000);

	cout << "In the year 2XX9, your company named " << Brand << " is about to launch a rocket into space to join up on a satellite nearby. \n";
	Sleep(2000);
	cout << "It starts the countdown \"T-Minus\" \n";
	Sleep(3000);

	thread th1(CountdownDialog, Countdown);
	th1.join();

	cout << "The vessel takes lift. and the boosters, one by one start to detach. \n";

	thread boosters(BlastDialog, Boosters);

	boosters.join();

	cout << "Launch successful! \n";

	system("pause");

	return 0;
}