#pragma once
#include<iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include "Draw.h"
using namespace std;
class Game : public Draw
{
private:
	string tuKhoaHienTai = "";
	string tuKhoaMacDinh[10] = { "C Plus Plus", "Operator Overloading", "Inheritance", "Polymorphism","Template","Object Oriented Programming","Methods","Encapsulation","Abstraction","Attributes" };
	vector<char> chuCaiSuDung;
	vector<string> tuKhoaSuDung_K; // từ khóa sử dụng cho mode hard
	int diem = 0;
	int SIZE;
public:
	Game();
	void khoiTaoDanhSachTuKhoa(vector<string> &, string);
	void taoTuKhoaHienTai(string);
	bool kTraTuKhoa(string);
	string taoBanSao(string);
	void hienThiTuKhoaHienTai();
	bool kTraChuCai(char, string);
	void thayDoiChuCai(char, string, string);
	void ghiChuCai(char);
	void hienThiChuCai();
	void kTraChuCai_K(string, string);
	void ghiTuKhoa(string);
	void hienThiTuKhoaChoi();
	void batDauGame_D(string, int);
	void batDauGame_T(string, int);
	void batDauGame_K(vector<string>, int);
	int getDiem();
	void setDiem(int);
	int getSIZE();
	~Game();
};

