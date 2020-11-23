
#include <iostream>
#define PI 3.1415926
using namespace std;
class CVolume
{
	int r, h;
public:
	CVolume();
	~CVolume();
	void param(int, int);
	double volume(void) { return (PI * r * r * h); }

private:

};

void CVolume::param(int m, int n) {
	r = m;
	h = n;
}

CVolume::CVolume()
{

}

CVolume::~CVolume()
{
}

int main() {
	CVolume a, *b, *c;
	CVolume *d = new CVolume[2];
	b = new CVolume;
	c = &a;
	a.param(1,2);
	b->param(3, 4);
	d->param(5, 6);
	d[1].param(7, 8);
	cout << "a volume:" << a.volume() << endl;
	cout << "*b volume:" << b->volume() << endl;
	cout << "*c volume:" << c->volume() << endl;
	cout << "d[0] colume:" << d[0].volume() << endl;
	cout << "d[1] colume:" << d[1].volume() << endl;
	return 0;
}