#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
enum EnumTest {
	PRINT = 1, 
	SELECT,
	COPY, 
	PASTE,
	MOVE,
	CUT,
	SHOW
};
enum EnumTest2 {
	LEFT = 1,
	RIGHT
};

const int KEY_ESC = 27;
const int length = 100;
unsigned int range_arr = 0;

int str_cmp(const char *ch1, const char *ch2)
{
	if (ch1 != nullptr && ch2 != nullptr)
	{
		while (*ch1 && *ch1 == *ch2)
		{
			++ch1;
			++ch2;
		}
	}
	return (*ch1 - *ch2);
}

int check(char* comand)
{
	size_t ret(0);

	if (comand != nullptr)
	{
		if (str_cmp(comand, "PRINT") == 0)
			ret = PRINT;
		if (str_cmp(comand, "SELECT") == 0)
			ret = SELECT;
		if (str_cmp(comand, "COPY") == 0)
			ret = COPY;
		if (str_cmp(comand, "PASTE") == 0)
			ret = PASTE;
		if (str_cmp(comand, "MOVE") == 0)
			ret = MOVE;
		if (str_cmp(comand, "CUT") == 0)
			ret = CUT;
		if (str_cmp(comand, "SHOW") == 0)
			ret = SHOW;
	}

	return ret;
}

int check2(char* comand)
{
	size_t ret(0);

	if (comand != nullptr)
	{
		if (str_cmp(comand, "LEFT") == 0)
			ret = PRINT;
		else if (str_cmp(comand, "RIGHT") == 0)
			ret = SELECT;
		else
			cout << "Enter correct side." << endl;
	}

	return ret;
}

void Fleft(char*& begin, unsigned int& num_move)
{
	if (*(begin - num_move) != '\0')
		begin -= num_move;
	else
		cout << "Out of range!" << endl;
}

void Fright(char*& begin, unsigned int& num_move)
{
	if (*(begin + num_move) != '\0')
		begin += num_move;
	else
		cout << "Out of range!" << endl;
}

void Fprint(char*& begin, char*& end)
{
	cout << "Enter your text: ";
	char print_text[length]{};
	cin >> print_text;
	char* begin_pr = print_text;

	if (*end != '\0')
	{
		char print_[length]{};
		do
		{
			print_[range_arr] = *begin;
			++begin;
			++range_arr;
		} while (*begin != *end);
		print_[range_arr] = *begin;
		++begin;
		++range_arr;

		begin -= range_arr;
		range_arr = 0;

		while (*begin_pr != '\0')
		{
			*begin = *begin_pr;
			++begin;
			++begin_pr;
		}

		while (print_[range_arr] != '\0')
		{
			*begin = print_[range_arr];
			++begin;
			++range_arr;
		}
	}
	else
	{
		while (*begin_pr != '\0')
		{
			*begin = *begin_pr;
			++begin;
			++begin_pr;
		}
	}
}

void Fselect(char* bufer, char* select)
{
	if (*bufer != '\0')
	{
		cout << "Enter position for start select: ";
		unsigned int st_pos;
		cin >> st_pos;
		cout << "Enter number of position for select: ";
		unsigned int num_pos;
		cin >> num_pos;

		range_arr = num_pos;

		if (bufer[st_pos + range_arr - 1] != '\0')
		{
			while (num_pos > 0)
			{
				select[range_arr - num_pos] = bufer[st_pos];
				++st_pos;
				--num_pos;
			}
		}
		else
			cout << "Out of range." << endl;

		range_arr = 0;
	}
	else
		cout << "Enter PRINT!" << endl;
}

void Fcopy(char* copy, char* select)
{
	if (*select != '\0')
	{
		while (select != copy && *select != '\0')
		{
			copy[range_arr] = *select;
			++range_arr;
			++select;
		}
		range_arr = 0;
	}
	else
		cout << "Firstly enter SELECT!!!" << endl;
}

void Fpaste(char* copy, char*& begin)
{
	if (*copy != '\0')
	{
		while (copy[range_arr] != '\0')
		{
			*begin = copy[range_arr];
			++begin;
			++range_arr;
		}
		range_arr = 0;
	}
	else
		cout << "Need a COPY!!!" << endl;
}

void Fmove(char*& begin)
{
	char move[10]{};
	cout << "Enter movement side: ";
	cin >> move;
	size_t type2 = check2(move);

	unsigned int num_move;
	cout << "Enter number of cells to move: ";
	cin >> num_move;

	switch (type2)
	{
	case LEFT:
	{
		Fleft(begin, num_move);
		break;
	};
	case RIGHT:
	{
		Fright(begin, num_move);
		break;
	};
	default:
		break;

	}

}

void Fcut(char* bufer, char* select, char*& begin)
{
	if (*select != '\0')
	{
		char cut_arr[length]{};
		unsigned int length_cut = 0;
		unsigned int temp = 0;

		while (bufer[range_arr] != '\0')
		{
			if (bufer[range_arr] != *select)
			{
				cut_arr[length_cut] = bufer[range_arr];
				++length_cut;
			}
			else
			{
				++select;
				++temp;
			}
				
			bufer[range_arr] = '\0';
			++range_arr;
		}
		select -= temp;
		range_arr = 0;

		while (cut_arr[range_arr] != '\0')
		{
			bufer[range_arr] = cut_arr[range_arr];
			++range_arr;
		}
		begin -= temp;
		range_arr = 0;
	}
	else
		cout << "Firstly enter SELECT!!!" << endl;
}

int main()
{
	/*string bufer;
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
	}*/
	char bufer[length]{};
	char* begin = bufer;
	char* end = length + bufer;
	char select[length]{};
	char copy[length]{};
	
	while (_getch() != KEY_ESC)
	{
		cout << "Enter your command: ";
		char comand[10]{};
		cin >> comand;
		size_t type = check(comand);

		switch (type)
		{
		case PRINT:
		{
			Fprint(begin, end);
			break;
		};
		case SELECT:
		{
			while (select[range_arr] != '\0')
			{
				select[range_arr] = '\0';
				++range_arr;
			}
			range_arr = 0;
			Fselect(bufer, select);
			break;
		};
		case COPY:
		{
			while (copy[range_arr] != '\0')
			{
				copy[range_arr] = '\0';
				++range_arr;
			}
			range_arr = 0;
			Fcopy(copy, select);
			break;
		};
		case PASTE:
		{
			Fpaste(copy, begin);
			break;
		};
		case MOVE:
		{
			end = begin - 1;
			if (*bufer != '\0')
				Fmove(begin);
			else
				cout << "Firstly enter a PRINT!!!" << endl;
			break;
		};
		case CUT:
		{
			Fcut(bufer, select, begin);
			break;
		};
		case SHOW:
		{
			cout << "Your bufer string: " << bufer << endl;
			break;
		};

		default:
		{
			cout << "Enter correct command." << endl;
			break;
		}
		}		
	}
	
	system("pause");
	return 0;
}
