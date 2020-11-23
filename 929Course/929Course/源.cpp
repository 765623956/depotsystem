#include<iostream>
#include<string>
using namespace std;
int main() {
	string s[] = { "Germany" ,"Japan", "Amercia","Britain","France" };
	for (int i = 0; i <= 4; i++)
	{
		cout << s[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i <= 2; i++)
	{
		string temp = s[i];
		s[i] = s[4 - i];
		s[4 - i] = temp;
	}
	cout << "修改后的数组：\n";
	for (int i = 0; i <= 4; i++)
	{
		cout<< s[i] << " ";
	}
	return 0;
}