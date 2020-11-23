#include<iostream>
#define PI 3.1415926
using namespace std;

int main() {

	double square;
	//声明双精度指针变量，动态分配double型存储区
	double *p;
	p = new double;
	cout << "请输入一个值：";
	cin >> *p;
	//以*p中首地址值计算圆形面积
	square = PI * (*p) *(*p);

	//将计算结果显示在屏幕上
	cout << "以半径为" << *p << "的圆形的面积为" << square;
	//使用delete释放空间
	delete p;
}