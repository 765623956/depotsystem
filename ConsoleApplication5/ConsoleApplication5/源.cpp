#include<iostream>
#define PI 3.1415926
using namespace std;

int main() {

	double square;
	//����˫����ָ���������̬����double�ʹ洢��
	double *p;
	p = new double;
	cout << "������һ��ֵ��";
	cin >> *p;
	//��*p���׵�ֵַ����Բ�����
	square = PI * (*p) *(*p);

	//����������ʾ����Ļ��
	cout << "�԰뾶Ϊ" << *p << "��Բ�ε����Ϊ" << square;
	//ʹ��delete�ͷſռ�
	delete p;
}