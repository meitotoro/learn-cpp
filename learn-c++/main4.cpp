#include "date.h"
int main4() {
	Date d1(2000, 2, 3);
	OutEn en;
	OutCh ch;
	string out_en=en(d1);
	string out_ch=ch(d1);
	d1.print();
	d1.print<OutCh>();
	return 0;
}