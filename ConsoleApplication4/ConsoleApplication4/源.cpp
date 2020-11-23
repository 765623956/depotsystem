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
	cout <<"两个整数中的最大值：" << compete(10,20) << endl;
	cout << "三个整数中的最大值：" << compete(10, 20,30) << endl;
	cout << "两个双精度数中的最大值："  << compete(6.1, 3.2) << endl;
	cout << "三个双精度数中的最大值："  << compete(5.2, 3.6,2.5) << endl;


}








