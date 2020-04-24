#include <iostream>
#include "Fs_DLL.h"

using namespace std;

int main()
{
	string diskName;
	while (1)
	{
		cout << "Please, enter disk name (C or D): ";
		diskName = cin.get();
		if (diskName.length() == 1)
		{
			break;
		}
	}
	getInfo(diskName);

	cin.get();
	exit(0);
}