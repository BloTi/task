#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

const int KEY_ESC = 27;

int main()
{
	string bufer;
	string select;
	string copy;

	while (_getch() != KEY_ESC)
	{
		string comand;
		cout << "Command: " << endl;
		std::getline(std::cin, comand);
		string sw;
		sw = comand.substr(0, comand.find(" "));
		if (sw == "print")
			bufer += comand.substr(comand.find(" ") + 1, (comand.size() - comand.find(" ") - 1));
		if (sw == "select")
		{
			comand.erase(0, comand.find(" ") + 1);
			string temp = comand.substr(0, comand.find(" "));
			int st_pos = std::stoi(temp);
			temp.clear();
			temp = comand.substr(comand.find(" ") + 1, (comand.size() - comand.find(" ") - 1));
			int num = std::stoi(temp);
			if ((st_pos + num) <= bufer.size())
				select = bufer.substr(st_pos - 1, num);
			cout << "Select: " << endl;
			cout << select << endl;
		}
		if (sw == "copy")
			copy = select;
		if (sw == "paste")
			bufer += copy;

		cout << "Bufer: " << endl;
		cout << bufer << endl;
		cout << endl;
	}
	
	return 0;
}
