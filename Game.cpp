#include "Game.h"



Game::Game()
{
}


void Game::khoiTaoDanhSachTuKhoa(vector<string>& danhSach, string file)
{
	string dong;
	ifstream docDong;
	docDong.open(file);
	while (true)
	{
		if (getline(docDong, dong)) {
			danhSach.push_back(dong);
		}
		else {
			SIZE = danhSach.size();
			docDong.close();
			break;
		}
	}

	//kiểm tra và loại bỏ các kí tự đặt biêt + số có trong từ khóa trong file
	int a;
	for (int i = 0; i < danhSach.size(); i++) {
		a = danhSach[i].find_first_of("1234567890-=`~!@#$%^&*)(}{][|\\:\";\'><.,?/_+");
		while (a != string::npos) {
			danhSach[i].erase(danhSach[i].begin() + a);
			a = danhSach[i].find_first_of("1234567890-=`~!@#$%^&*)(}{][|\\:\";\'><.,?/_+");
		}
	}
}

void Game::taoTuKhoaHienTai(string tu) // dùng để khởi tạo từ khóa được sử dụng để bắt đầu chơi!
{
	for (int i = 0; i < tu.length(); i++) {
		if (tu[i] == ' ') {
			tuKhoaHienTai.append(" "); // từ khóa có dấu cách sẽ đc cách ra khi ẩn
		}
		else {
			tuKhoaHienTai.append("_"); // mỗi chữ cái trong từ khóa sẽ ẩn = dấu _
		}
	}
}

bool Game::kTraTuKhoa(string tu) // kiểm tra xem là từ mình đoán đã đúng hết chưa?
{
	return (tuKhoaHienTai == tu);
}

string Game::taoBanSao(string tuGoc) // tạo bản sao của từ gốc hiện thời và in thường để so sánh và đưa bản gốc vào trong từ khóa lúc đoán
{
	string  temp = tuGoc;
	for (int i = 0; i < temp.length(); i++) {
		temp[i] = tolower(temp[i]);
	}
	return temp;
}

void Game::hienThiTuKhoaHienTai() // hiển thị trạng thái hiện tại của từ khóa đang sử dụng
{
	int demSotu = 0;
	for (int i = 0; i < tuKhoaHienTai.length(); i++) {
		if (tuKhoaHienTai[i] == ' ') {
			++demSotu;
			if (demSotu > 4) {
				cout << endl;
				demSotu = 0;
			}
		}
		cout << tuKhoaHienTai[i] << " ";
	}
	cout << endl;
}

bool Game::kTraChuCai(char chuCai, string tuKhoaTam) // kiểm tra xem chữ cái bạn đoán có đang tồn tại trong từ gốc hay không?
{
	return (tuKhoaTam.find_first_of(chuCai) != string::npos);
}

void Game::thayDoiChuCai(char chuCai, string tuKhoaTam, string tu) // kiểm tra xem nếu chữ cái bạn đoán có tồn tại trong từ gốc thì thay "_" = từ bạn đoán được.
{
	for (int i = 0; i < tuKhoaHienTai.length(); i++) {
		if (tuKhoaTam[i] == chuCai) {
			tuKhoaHienTai[i] = tu[i];
		}
	}
}

void Game::ghiChuCai(char chuCai) // thêm chữ cái mà bạn đoán vào vector chuCaiSuDung
{
	char chuCaiNhap = toupper(chuCai);
	if (chuCaiSuDung.size() == 0) {
		chuCaiSuDung.push_back(chuCaiNhap);
	}
	else {
		bool kTraChuCai = false;
		for (int i = 0; i < chuCaiSuDung.size(); i++) {
			if (chuCaiSuDung[i] == chuCaiNhap) {
				kTraChuCai = true;
				break;
			}
		}
		if (!kTraChuCai) {
			chuCaiSuDung.push_back(chuCaiNhap);
		}
	}
}

void Game::hienThiChuCai() //Hiển thị các chữ cái mà bạn đã nhập
{
	if (chuCaiSuDung.size() == 0) {
		cout << endl;
	}
	else {
		for (int i = 0; i < chuCaiSuDung.size(); i++) {
			if (i % 5 == 0 && i != 0) {
				cout << "\n" << endl;
			}
			cout << "\t" << chuCaiSuDung[i];
		}
		cout << "\n" << endl;
	}
}


//** Dùng cho chế độ khó


void Game::kTraChuCai_K(string tuKhoaTam, string tuGoc) // kiểm tra từ mới có chữ cái nào mà trước đó bạn đã đoán được ở từ khóa trước hay không? Nếu có hiển thị ra
{
	char chuCaiTam;
	for (int i = 0; i < chuCaiSuDung.size(); i++) {
		chuCaiTam = tolower(chuCaiSuDung[i]);
		if (kTraChuCai(chuCaiTam, tuKhoaTam)) {
			thayDoiChuCai(chuCaiTam, tuKhoaTam, tuGoc);
		}
	}
}

void Game::ghiTuKhoa(string tu) 
{
	tuKhoaSuDung_K.push_back(tu);
}

void Game::hienThiTuKhoaChoi() // dùng đễ hiển thị các từ khóa bạn đã trải qua
{
	int j;
	for (int i = 0; i < tuKhoaSuDung_K.size(); i++)
	{
		j = i + 1;
		cout << j << ". " << tuKhoaSuDung_K[i] << endl;
	}
	cout << endl;
}

void Game::batDauGame_D(string tu, int soLuotTLToiDa)
{
	int soLanTLConLai = soLuotTLToiDa;
	string nhapChuCai;
	char chuCaiDoan;
	string tuTam = taoBanSao(tu);
	char  chuCaiTam;
	int won = 1;
	taoTuKhoaHienTai(tu);
	while (true) {
		giaoDien();
		cout << "\n\n\t\t BAT DAU GAME VOI CHE DO DE" << endl;
		if (soLanTLConLai == 0) {
			display_1(soLuotTLToiDa, soLanTLConLai);
			won = 0;
			break;
		}
		else if (kTraTuKhoa(tu)) {
			break;
		}
		display_1(soLuotTLToiDa, soLanTLConLai);
		hienThiTuKhoaHienTai();
		cout << "So Lan Doan Con Lai La: " << soLanTLConLai << endl;
		cout << "Cac Chu Cai Ma Ban Da Doan La:\n";
		hienThiChuCai();
		cout << "Nhap 1 Chu Cai( Nhap 0 De Thoat): ";
		cin >> nhapChuCai;
		chuCaiDoan = nhapChuCai[0];
		system("cls");

		if (chuCaiDoan == '0') {
			won = 3;
			break;
		}

		chuCaiTam = tolower(chuCaiDoan);
		ghiChuCai(chuCaiTam);
		if (!kTraChuCai(chuCaiTam, tuTam)) {
			--soLanTLConLai;
		}
		else {
			thayDoiChuCai(chuCaiTam, tuTam, tu);
		}
	}
	chuCaiSuDung.clear();
	tuKhoaHienTai = "";

	if (won == 1) {
		diem = diem + soLanTLConLai * 100 + 1000;
		cout << "CHUC MUNG! BAN DA CHIEN THANG! <3" << endl;
		cout << "TU KHOA BAN DOAN LA: " << tu << endl;
		cout << "DIEM HIEN TAI CUA BAN LA: " << diem << endl;
		system("pause");
	}
	else if (won == 0) {
		diem = diem + 0;
		display_2();
		cout << "BAN DA THUA !!! :( " << endl;
		cout << "TU KHOA BAN PHAI DOAN LA: \"" << tu << "\"" << endl;
		cout << "DIEM HIEN TAI CUA BAN LA: " << diem << endl;
		system("pause");
	}
	else {
		cout << "DANG THOAT..." << endl;
	}
}

void Game::batDauGame_T(string tu, int soLuotTLToiDa)
{
	int soLanTLConLai = soLuotTLToiDa;
	string nhapChuCai;
	char chuCaiDoan;
	string tuTam = taoBanSao(tu);
	char  chuCaiTam;
	int won = 1;
	taoTuKhoaHienTai(tu);
	while (true) {
		giaoDien();
		cout << "\n\n\t\tBAT DAU GAME VOI CHE DO THUONG" << endl;
		if (soLanTLConLai == 0) {
			display_1(soLuotTLToiDa, soLanTLConLai);
			won = 0;
			break;
		}
		else if (kTraTuKhoa(tu)) {
			break;
		}
		display_1(soLuotTLToiDa, soLanTLConLai);
		hienThiTuKhoaHienTai();
		cout << "So Lan Doan Con Lai La: " << soLanTLConLai << endl;
		cout << "Cac Chu Cai Ma Ban Da Doan La:\n";
		hienThiChuCai();
		cout << "Nhap 1 Chu Cai( Nhap 0 De Thoat): ";
		cin >> nhapChuCai;
		chuCaiDoan = nhapChuCai[0];
		system("cls");

		if (chuCaiDoan == '0') {
			won = 3;
			break;
		}

		chuCaiTam = tolower(chuCaiDoan);
		ghiChuCai(chuCaiTam);
		if (!kTraChuCai(chuCaiTam, tuTam)) {
			--soLanTLConLai;
		}
		else {
			thayDoiChuCai(chuCaiTam, tuTam, tu);
		}
	}
	chuCaiSuDung.clear();
	tuKhoaHienTai = "";

	if (won == 1) {
		diem = diem + soLanTLConLai * 200 + 1500;
		cout << "CHUC MUNG! BAN DA CHIEN THANG! <3" << endl;
		cout << "TU KHOA BAN DOAN LA: " << tu << endl;
		cout << "DIEM HIEN TAI CUA BAN LA: " << diem << endl;
		system("pause");
	}
	else if (won == 0) {
		diem = diem + 0;
		cout << "BAN DA THUA !!! :( " << endl;
		cout << "TU KHOA BAN PHAI DOAN LA: \"" << tu << "\"" << endl;
		cout << "DIEM HIEN TAI CUA BAN LA: " << diem << endl;
		system("pause");
	}
	else {
		cout << "DANG THOAT..." << endl;
	}
}

void Game::batDauGame_K(vector<string> danhSach, int soLuotTLToiDa)
{
	string tu = danhSach[rand() % danhSach.size()];
	int soLanTLConLai = soLuotTLToiDa;
	string nhapChuCai;
	char chuCaiDoan;
	string tuTam;
	char chuCaiTam;
	int won = 1;
	taoTuKhoaHienTai(tu);
	while (true)
	{
		giaoDien();
		cout << "\n\n\t\tBAT DAU GAME VOI CHE DO KHO" << endl;
		if (soLanTLConLai == 0) {
			display_1(soLuotTLToiDa, soLanTLConLai);
			won = 0;
			break;
		}
		else if (kTraTuKhoa(tu))
			break;
		display_1(soLuotTLToiDa, soLanTLConLai);
		hienThiTuKhoaHienTai();
		cout << "\nSo Lan Doan Con Lai La: " << soLanTLConLai << endl;
		cout << "Tu Khoa Ban Da Doan La:\n";
		hienThiChuCai();
		cout << "Nhap 1 Chu Cai( Nhap 0 De Thoat): ";
		cin >> nhapChuCai;
		chuCaiDoan = nhapChuCai[0];
		system("cls");


		if (chuCaiDoan == '0') {
			won = 3;
			break;
		}

		chuCaiTam = tolower(chuCaiDoan);
		ghiChuCai(chuCaiTam);
		tuTam = taoBanSao(tu);

		if (!kTraChuCai(chuCaiTam, tuTam)) {
			--soLanTLConLai;
			tuKhoaHienTai = "";
			tu = danhSach[rand() % danhSach.size()];
			ghiTuKhoa(tu);
			taoTuKhoaHienTai(tu);
			tuTam = taoBanSao(tu);
			kTraChuCai_K(tuTam, tu);
		}
		else
			thayDoiChuCai(chuCaiTam, tuTam, tu);
	}
	chuCaiSuDung.clear();
	tuKhoaHienTai = "";
	if (won == 1) {
		diem = diem + soLanTLConLai * 500 + 2000;
		cout << "CHUC MUNG. BAN DA CHIEN THANG! <3" << endl;
		cout << "BAN DA CHIEN THANG VOI TU KHOA: " << tu << "\n" << endl;
		cout << "CAC TU DA DUOC SU DUNG VUA ROI LA: " << endl;
		hienThiTuKhoaChoi();
		tuKhoaSuDung_K.clear();
		cout << "DIEM HIEN TAI CUA BAN LA: " << diem << endl;
		system("pause");
	}
	else if (won == 0) {
		diem = diem + 0;
		cout << "BAN DA THUA!!!" << endl;
		cout << "TU KHOA BAN PHAI DOAN LA: " << endl;
		hienThiTuKhoaChoi();
		tuKhoaSuDung_K.clear();
		cout << "DIEM HIEN TAI CUA BAN LA: " << diem << endl;
		system("pause");
	}
	else {
		cout << "DANG THOAT..." << endl;
	}


}

int Game::getDiem()
{
	return diem;
}

void Game::setDiem(int diem)
{
	this->diem = diem;
}

int Game::getSIZE()
{
	return SIZE;
}

Game::~Game()
{
}
