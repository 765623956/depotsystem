#include<iostream>
using namespace std;
int compete(int x,int y) {
	if (x>y) {
		return x;
	}
	else {
		return y;
	}
}
int compete(int x, int y,int z) {
	if (x>y&&x>z) {
		return x;
	}
	else if(y>x&&y>z){
		return y;
	}
	else {
		return z;
	}
}
double compete(double x, double y) {
	if (x>y) {
		return x;
	}
	else {
		return y;
	}
}
double compete(double x, double y, double z) {
	if (x>y&&x>z) {
		return x;
	}
	else if (y>x&&y>z) {
		return y;
	}
	else {
		return z;
	}
}
int main() {
	cout <<"���������е����ֵ��" << compete(10,20) << endl;
	cout << "���������е����ֵ��" << compete(10, 20,30) << endl;
	cout << "����˫�������е����ֵ��"  << compete(6.1, 3.2) << endl;
	cout << "����˫�������е����ֵ��"  << compete(5.2, 3.6,2.5) << endl;


}








