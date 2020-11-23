//√∞≈›≈≈–ÚÀ„∑® µœ÷
//2020.10.6

#include<iostream>
using namespace std;

int main() {

	int a[] = { 5,4,9,8,3,1,6,7,2 };

	for (int i = 0; i <sizeof(a)/sizeof(a[0])-1 ; i++)
	{
		for (int j = 0; j < sizeof(a) / sizeof(a[0]) - 1-i; j++)
		{
			a[j + 1] = a[j] + a[j + 1];
			a[j] = a[j + 1] - a[j];
			a[j + 1] = a[j + 1] - a[j];
		}
	}
	

}