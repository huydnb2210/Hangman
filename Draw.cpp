#include "Draw.h"



void Draw::giaoDien()
{
	cout << "\t\t\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	cout << "\t\t\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	cout << "\t\t\t\t\t°°°°°                                 °°°°°" << endl;
	cout << "\t\t\t\t\t°°°°°ì ì ì ì ì GUESS OR DIE ì ì ì ì ì °°°°°" << endl;
	cout << "\t\t\t\t\t°°°°°                                 °°°°°" << endl;
	cout << "\t\t\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	cout << "\t\t\t\t\t°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
}

void Draw::menuChinh()
{
	cout << "\n\t\t\t\t\t|-+-+-+-+-+-+-+-+-+-$-+-+-+-+-+-+-+-+-+-|" << endl;
	cout << "\t\t\t\t\t|-+-+-+-+-+-+-+-+-+-$-+-+-+-+-+-+-+-+-+-|" << endl;
	cout << "\t\t\t\t\t|-+\t\t\t\t      +-|";
	cout << "\n\t\t\t\t\t|-+\t\tMENU CHINH" << "\t      +-|" << endl;
	cout << "\t\t\t\t\t|-+\t\t\t\t      +-|" << endl;
	cout << "\t\t\t\t\t|-+\t  1) BAT DAU" << "\t\t      +-|" << endl;
	cout << "\t\t\t\t\t|-+\t  2) LOAD FILE" << "\t\t      +-|" << endl;
	cout << "\t\t\t\t\t|-+\t  3) HUONG DAN" << "\t\t      +-|" << endl;
	cout << "\t\t\t\t\t|-+\t  4) BANG XEP HANG" << "\t      +-|" << endl;
	cout << "\t\t\t\t\t|-+\t  5) DOI NGUOI CHOI" << "\t      +-|" << endl;
	cout << "\t\t\t\t\t|-+\t  6) THOAT VA LUU LAI DIEM" << "    +-|" << endl;
	cout << "\t\t\t\t\t|-+\t\t\t\t      +-|" << endl;
	cout << "\t\t\t\t\t|-+-+-+-+-+-+-+-+-+-$-+-+-+-+-+-+-+-+-+-|" << endl;
	cout << "\t\t\t\t\t|-+-+-+-+-+-+-+-+-+-$-+-+-+-+-+-+-+-+-+-|" << endl;
}

void Draw::menuDoKho()
{
	cout << "\n\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-$-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-$-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "\t\t\t\t\t+-+\t\t\t\t      +-+";
	cout << "\n\t\t\t\t\t+-+\t\tCHON DO KHO" << "\t      +-+" << endl;
	cout << "\t\t\t\t\t+-+\t\t\t\t      +-+" << endl;
	cout << "\t\t\t\t\t+-+\t  1) DE " << "\t\t      +-+" << endl;
	cout << "\t\t\t\t\t+-+\t  2) THUONG " << "\t\t      +-+" << endl;
	cout << "\t\t\t\t\t+-+\t  3) KHO " << "\t\t      +-+" << endl;
	cout << "\t\t\t\t\t+-+\t  0) TRO VE MENU CHINH" << "\t      +-+" << endl;
	cout << "\t\t\t\t\t+-+\t\t\t\t      +-+" << endl;
	cout << "\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-$-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-$-+-+-+-+-+-+-+-+-+-+" << endl;
}

void Draw::display_1(int soLuotTLToiDa, int soLuotTLConLai)
{
	switch (soLuotTLToiDa)
	{
	case 12: // Dễ
		if (soLuotTLConLai == 10 || soLuotTLConLai == 9) {
			cout << "\t  O " << endl;
			cout << "\t    " << endl;
			cout << "\t    " << endl;
			cout << "\t    " << endl;
		}
		else if (soLuotTLConLai == 8 || soLuotTLConLai == 7) {
			cout << "\t  O " << endl;
			cout << "\t  | " << endl;
			cout << "\t  | " << endl;
			cout << "\t    " << endl;
		}
		else if (soLuotTLConLai == 6 || soLuotTLConLai == 5) {
			cout << "\t  O " << endl;
			cout << "\t--| " << endl;
			cout << "\t  | " << endl;
			cout << "\t    " << endl;
		}
		else if (soLuotTLConLai == 4 || soLuotTLConLai == 3) {
			cout << "\t  O " << endl;
			cout << "\t--|--" << endl;
			cout << "\t  | " << endl;
			cout << "\t    " << endl;
		}
		else if (soLuotTLConLai == 2 || soLuotTLConLai == 1) {
			cout << "\t  O " << endl;
			cout << "\t--|--" << endl;
			cout << "\t  | " << endl;
			cout << "\t /  " << endl;
		}
		else if (soLuotTLConLai == 1) {
			cout << "\t  O " << endl;
			cout << "\t--|--" << endl;
			cout << "\t  | " << endl;
			cout << "\t / \\" << endl;
		}
		else {
			cout << "\t   " << endl;
			cout << "\t   " << endl;
			cout << "\t   " << endl;
			cout << "\t   " << endl;
		}
		break;
	case 8:
		if (soLuotTLConLai == 7 || soLuotTLConLai == 6) {
			cout << "\t  O " << endl;
			cout << "\t    " << endl;
			cout << "\t    " << endl;
			cout << "\t    " << endl;
		}
		else if (soLuotTLConLai == 5 || soLuotTLConLai == 4) {
			cout << "\t  O " << endl;
			cout << "\t  | " << endl;
			cout << "\t  | " << endl;
			cout << "\t   " << endl;
		}
		else if (soLuotTLConLai == 3) {
			cout << "\t  O " << endl;
			cout << "\t--| " << endl;
			cout << "\t  | " << endl;
			cout << "\t    " << endl;
		}
		else if (soLuotTLConLai == 2) {
			cout << "\t  O " << endl;
			cout << "\t--|--" << endl;
			cout << "\t  | " << endl;
			cout << "\t    " << endl;
		}
		else if (soLuotTLConLai == 1) {
			cout << "\t  O " << endl;
			cout << "\t--|--" << endl;
			cout << "\t  | " << endl;
			cout << "\t /  " << endl;
		}
		else if (soLuotTLConLai == 0) {
			cout << "\t  O " << endl;
			cout << "\t--|--" << endl;
			cout << "\t  | " << endl;
			cout << "\t / \\" << endl;
		}
		else {
			cout << "\t   " << endl;
			cout << "\t   " << endl;
			cout << "\t   " << endl;
			cout << "\t   " << endl;
		}
		break;
	case 6:
		if (soLuotTLConLai == 5) {
			cout << "\t  O " << endl;
			cout << "\t    " << endl;
			cout << "\t    " << endl;
			cout << "\t    " << endl;
		}
		else if (soLuotTLConLai == 4) {
			cout << "\t  O " << endl;
			cout << "\t  | " << endl;
			cout << "\t  | " << endl;
			cout << "\t    " << endl;
		}
		else if (soLuotTLConLai == 3) {
			cout << "\t  O " << endl;
			cout << "\t--| " << endl;
			cout << "\t  | " << endl;
			cout << "\t    " << endl;
		}
		else if (soLuotTLConLai == 2) {
			cout << "\t  O " << endl;
			cout << "\t--|--" << endl;
			cout << "\t  | " << endl;
			cout << "\t    " << endl;
		}
		else if (soLuotTLConLai == 1) {
			cout << "\t  O " << endl;
			cout << "\t--|--" << endl;
			cout << "\t  | " << endl;
			cout << "\t /  " << endl;
		}
		else if (soLuotTLConLai == 0) {
			cout << "\t  O " << endl;
			cout << "\t--|--" << endl;
			cout << "\t  | " << endl;
			cout << "\t / \\" << endl;
		}
		else {
			cout << "\t   " << endl;
			cout << "\t   " << endl;
			cout << "\t   " << endl;
			cout << "\t   " << endl;
		}
		break;
	}
}


void Draw::display_2()
{
	cout << "\t  O " << endl;
	cout << "\t--|--" << endl;
	cout << "\t  | " << endl;
	cout << "\t / \\" << endl;
}


Draw::Draw()
{
}


Draw::~Draw()
{
}
