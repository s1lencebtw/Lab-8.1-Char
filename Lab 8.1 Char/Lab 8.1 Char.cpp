#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* s)
{
	int count = 0;
	int pos = 0;
	char* t;

	while ((t = strchr(s + pos, 'B'))) {
		pos = t - s + 1;
		count++;
	}
	while ((t = strchr(s + pos, 'A'))) {
		pos = t - s + 1;
		count++;
	}
	while ((t = strchr(s + pos, 'S'))) {
		pos = t - s + 1;
		count++;
	}
	while ((t = strchr(s + pos, 'I'))) {
		pos = t - s + 1;
		count++;
	}
	while ((t = strchr(s + pos, 'C'))) {
		pos = t - s + 1;
		count++;
	}
	return count;
}
char* Change(char* s) {
	char* t = new char[strlen(s) * 2 + 1];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = '\0';

	while ((p = strstr(s + pos1, "BASIC")))
	{
		pos2 = p - s;
		strncat(t, s + pos1, pos2 - pos1);
		strcat(t, "DELPHI");
		pos1 = pos2 + 5;
	}

	strcat(t, s + pos1);
	strcpy(s, t);

	delete[] t;

	return s;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "Number of chars BASIC:    " << Count(str) << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}
