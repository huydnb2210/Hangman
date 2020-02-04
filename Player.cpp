#include "Player.h"



Player::Player()
{
}

string Player::getPlayerName()
{
	return playerName;
}

int Player::getScores()
{
	return getDiem();
}

void Player::setScores()
{
	scores = getDiem();
}

void Player::setPlayerName(string playerName)
{
	this->playerName = playerName;
}

bool operator<(Player &X, Player &Y)
{
	return (X.scores < Y.scores);
}


void Player::docFile(ifstream & filein)
{
	vector<Player> ds;
	Player x;
	while (filein.eof() == false)
	{
		getline(filein, x.playerName, '-');
		filein >> x.scores;
		ds.push_back(x);
		for (int i = 0; i < ds.size() - 1; i++)
		{
			for (int j = i + 1; j < ds.size(); j++)
			{
				if (ds[i] < ds[j])
				{
					swap(ds[i], ds[j]);
				}
			}
		}
	}
	cout << "=========RANK========" << endl;
	cout << setw(10) << left << "NAME" << setw(10) << right << "SCORE" << endl;
	cout << "=====================" << endl;
	for (int i = 0; i < ds.size(); i++)
	{

		cout << setw(10) << left << ds[i].playerName << setw(10) << right << ds[i].scores;
		cout << "\n";
	}
	filein.close();

}

void Player::ghiFile(fstream & filein, Player X)
{
	filein.open("xephang.txt", ios::in | ios::app);
	filein << "\n" << X.playerName << "-" << X.getDiem();
	filein.close();
}


void Player::Run()
{
	Player p;
	string tukhoa;
	string fileName;
	string playerName;
	vector<string> danhSachTuKhoa;
	srand(time(0));
	string select;
	string chonDoKho;
	ifstream fin;
	fstream ghiDiem;
	ifstream xemDiem;
	string tuKhoaMacDinh[10] = { "C Plus Plus", "Operator Overloading", "Inheritance", "Polymorphism","Template","Object Oriented Programming","Methods","Encapsulation","Abstraction","Attributes" };
	int tinhtrang;
	int rsdiem = 0;
	int thoat;
	string tuKhoaHienTai;
	do
	{
		tinhtrang = 1;
		p.giaoDien();
		cout << "\n\n  Please enter your name ¯ ";
		getline(cin, playerName);
		p.setPlayerName(playerName);
		transform(playerName.begin(), playerName.end(), playerName.begin(), toupper);

		while (true)
		{
			system("cls");
			p.giaoDien();
			cout << "\n\t\t\t\t\t  Chao ban " << playerName << " den voi GUESS OR DIE game!" << endl;
			p.menuChinh();
			cout << "\n***NOTE: Nen doc huong dan truoc khi bat dau tro choi!" << endl << endl << endl;
			cout << "Lua chon cua ban: ¯ ";
			fileName = "";
			cin >> select;
			if (select == "1" || select == "2")
			{
				if (select == "1")
				{
					system("cls");
					p.giaoDien();
					danhSachTuKhoa.assign(tuKhoaMacDinh + 0, tuKhoaMacDinh + 10);
					tukhoa = danhSachTuKhoa[rand() % 10];
				}
				else
				{
					cin.ignore();
					system("cls");
					p.giaoDien();
					cout << "Dua vao duong dan toi file chua tu khoa cua ban!" << endl;
					cout << " ¯ ";
					getline(cin, fileName);

					fin.open(fileName);
					if (fin.fail())
					{
						cout << "File " << "\"" + fileName + "\" khong ton tai!\n" << endl;
						fin.close();
						system("pause");
						continue;
					}
					else
					{
						p.khoiTaoDanhSachTuKhoa(danhSachTuKhoa, fileName);
						fin.close();
						if (p.getSIZE() == 0)
						{
							cout << "File trong!" << endl;
							system("pause");
							continue;
						}
						else
						{
							tukhoa = danhSachTuKhoa[rand() % p.getSIZE()];
							cout << "Nhap file thanh cong!\n" << endl;
							system("pause");
						}
					}
				}
				while (true)
				{

					system("cls");
					p.giaoDien();
					p.menuDoKho();
					cout << "Lua chon cua ban: ¯ ";
					cin >> chonDoKho;

					if (chonDoKho == "0")
					{
						break;
					}
					else if (chonDoKho == "1")
					{
						system("cls");
						p.batDauGame_D(tukhoa, 12);
						tuKhoaHienTai.clear();
						danhSachTuKhoa.clear();
						cout << endl;
						break;
					}
					else if (chonDoKho == "2")
					{
						system("cls");
						p.batDauGame_T(tukhoa, 8);
						tuKhoaHienTai.clear();
						danhSachTuKhoa.clear();
						cout << endl;
						break;
					}
					else if (chonDoKho == "3")
					{
						system("cls");
						p.batDauGame_K(danhSachTuKhoa, 6);
						tuKhoaHienTai.clear();
						danhSachTuKhoa.clear();
						cout << endl;
						break;
					}
					else
					{
						cout << "\n\nLUA CHON KHONG HOP LE\n" << endl;
						cout << "VUI LONG NHAP LAI LUA CHON!" << endl;
						system("pause");
					}
				}

			}
			else if (select == "3")

			{
				while (true)
				{
					system("cls");
					p.giaoDien();
					cout << "GUESS OR DIE la 1 game doan chu voi so lan doan dua vao che do ban choi!" << endl;
					cout << "Voi moi la doan dung chu cai co trong tu khoa ban se khong mat luot tra loi." << endl;
					cout << "Va voi moi lan doan sai ban se mat 1 luot tra loi " << endl;
					cout << "Khi so lan tra loi con lai cua ban o muc thap thi game se ve ra anh cua 1 nguoi que. Khi anh nay du cac bo phan dau - than - tay - chan thi ban se thua!" << endl;
					cout << "DE\t\t - ban co 12 lan doan tu khoa!" << endl;
					cout << "THUONG\t\t - ban co 8 lan doan tu khoa!" << endl;
					cout << "KHO\t\t - ban co 6 lan doan tu khoa. Voi moi lan tra loi sai game se doi tu khoa khac co it nhat 1 trong cac chu cai ban da doan duoc" << endl;
					system("pause");
					break;
				}

			}
			else if (select == "4")
			{
				system("cls");
				p.giaoDien();
				cout << "\n\n\t\t\tBANG XEP HANG" << endl << endl;
				xemDiem.open("xephang.txt", ios::out);
				p.docFile(xemDiem);
				system("pause");
			}
			else if (select == "5")
			{

				if (p.getDiem() == 0)
				{

					cout << "BAN CO CHAC CHAN MUON DOI NGUOI CHOI GUESS OR DIE ?" << endl;
					cout << "1. QUAY LAI\n0. DOI NGUOI CHOI!" << endl;
					cout << "Lua chon cua ban: ¯ ";
					fflush(stdin);
					cin >> thoat;

					if (thoat == 0)
					{
						tinhtrang = 0;
						system("cls");
						cin.ignore();
						break;
					}
					else if (thoat == 1)
					{
						// không làm gì để game tiếp tục chạy.
					}
				}

				else
				{


					p.ghiFile(ghiDiem, p);
					cout << "BAN CO CHAC CHAN MUON DOI NGUOI CHOI GUESS OR DIE ?" << endl;
					cout << "1. QUAY LAI\n0. DOI NGUOI CHOI!" << endl;
					cout << "Lua chon cua ban: ¯ ";
					fflush(stdin);
					cin >> thoat;
					if (thoat == 0)
					{
						p.setDiem(rsdiem);
						tinhtrang = 0;
						system("cls");
						cin.ignore();
						break;
					}
					else if (thoat == 1)
					{
						// không làm gì để game tiếp tục chạy.
					}
				}
			}
			else if (select == "6")
			{
				if (p.getDiem() == 0)
				{

					cout << "BAN CO CHAC CHAN MUON THOAT GUESS OR DIE ?" << endl;
					cout << "1. QUAY LAI\n0. THOAT!" << endl;
					cout << "Lua chon cua ban: ¯ ";
					fflush(stdin);
					cin >> thoat;


					if (thoat == 0)
					{
						break;
						tinhtrang = 0;
					}
					else if (thoat == 1)
					{
						// không làm gì để game tiếp tục chạy.
					}
				}
				else
				{
					ghiDiem.open("xephang.txt", ios::app);
					ghiDiem << "\n" << playerName << "-" << p.getDiem();
					ghiDiem.close();
					cout << "BAN CO CHAC CHAN MUON THOAT GUESS OR DIE ?" << endl;
					cout << "1. QUAY LAI\n0. THOAT!" << endl;
					cout << "Lua chon cua ban: ¯ ";
					fflush(stdin);
					cin >> thoat;
					if (thoat == 0)
					{
						break;
						tinhtrang = 0;
					}
					else if (thoat == 1)
					{
						// không làm gì để game tiếp tục chạy.
					}
				}
			}
			else
			{
				cout << "LUA CHON KHONG HOP LE!" << endl;
				cout << "VUI LONG NHAP LAI LUA CHON CUA BAN!" << endl;
				system("pause");
				system("cls");
				cin.ignore();
			}
		}
	} while (tinhtrang == 0);
}

Player::~Player()
{
}
