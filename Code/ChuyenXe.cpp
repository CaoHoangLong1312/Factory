#include "ChuyenXe.h"
#include<iostream>
using namespace std;

//-----------------Chuyen Xe ------------------
ChuyenXe::ChuyenXe() {
    maChuyenXe = "";
    diemDi = "";
    diemDen = "";
    gioKhoiHanh = Gio();
    ngayKhoiHanh = Ngay();
    giaVe = 0;
    soVeConLai = 0;
    bienSoXe = "";
    diemDung = vector<tuple<string, Gio, int>>();
    quyDinhHanhLy = "";
    chinhSachHuyVe = "";
    thongTinLienHe = "";
}

ChuyenXe::ChuyenXe(const ChuyenXe& chuyenXe) {
    maChuyenXe = chuyenXe.maChuyenXe;
    diemDi = chuyenXe.diemDi;
    diemDen = chuyenXe.diemDen;
    gioKhoiHanh = chuyenXe.gioKhoiHanh;
    ngayKhoiHanh = chuyenXe.ngayKhoiHanh;
    giaVe = chuyenXe.giaVe;
    soVeConLai = chuyenXe.soVeConLai;
    bienSoXe = chuyenXe.bienSoXe;
    diemDung = chuyenXe.diemDung;
    quyDinhHanhLy = chuyenXe.quyDinhHanhLy;
    chinhSachHuyVe = chuyenXe.chinhSachHuyVe;
    thongTinLienHe = chuyenXe.thongTinLienHe;
}

ChuyenXe::ChuyenXe (string maChuyenXe, string diemDi, string diemDen,
                    Gio gioKhoiHanh, Ngay ngayKhoiHanh, int giaVe,
                    int soVeConLai, string bienSoXe, vector<tuple<string, Gio, int>> diemDung,
                    string quyDinhHanhLy, string chinhSachHuyVe, string thongTinLienHe) {
    this->maChuyenXe = maChuyenXe;
    this->diemDi = diemDi;
    this->diemDen = diemDen;
    this->gioKhoiHanh = gioKhoiHanh;
    this->ngayKhoiHanh = ngayKhoiHanh;
    this->giaVe = giaVe;
    this->soVeConLai = soVeConLai;
    this->bienSoXe = bienSoXe;
    this->diemDung = diemDung;
    this->quyDinhHanhLy = quyDinhHanhLy;
    this->chinhSachHuyVe = chinhSachHuyVe;
    this->thongTinLienHe = thongTinLienHe;
}

string ChuyenXe::getMaChuyenXe() {
    return maChuyenXe;
}

string ChuyenXe::getDiemDi() {
    return diemDi;
}

string ChuyenXe::getDiemDen() {
    return diemDen;
}

Gio ChuyenXe::getGioKhoiHanh() {
    return gioKhoiHanh;
}

Ngay ChuyenXe::getNgayKhoiHanh() {
    return ngayKhoiHanh;
}

int ChuyenXe::getGiaVe() {
    return giaVe;
}

int ChuyenXe::getSoVeConLai() {
    return soVeConLai;
}

void ChuyenXe::setSoVeConLai(int soVeConLai) {
    this->soVeConLai = soVeConLai;
}

string ChuyenXe::getBienSoXe() {
    return bienSoXe;
}

vector<tuple<string, Gio, int>> ChuyenXe::getDiemDung() {
    return diemDung;
}

string ChuyenXe::getQuyDinhHanhLy() {
    return quyDinhHanhLy;
}

string ChuyenXe::getChinhSachHuyVe() {
    return chinhSachHuyVe;
}

string ChuyenXe::getThongTinLienHe() {
    return thongTinLienHe;
}

ChuyenXe::~ChuyenXe() {
}

ChuyenXe ChuyenXeFactory:: taoChuyenXe() {
    string maChuyenXe, diemDi, diemDen, bienSoXe, quyDinhHanhLy, chinhSachHuyVe, thongTinLienHe;
    Gio gioKhoiHanh;
    Ngay ngayKhoiHanh;
    int giaVe, soVeConLai;

    vector<tuple<string, Gio, int>> diemDung;

    cout << "Nhap ma chuyen xe: ";
    getline(cin, maChuyenXe);

    cout << "Nhap diem di: ";
    getline(cin, diemDi);

    cout << "Nhap diem den: ";
    getline(cin, diemDen);

    cout << "Nhap gio khoi hanh:\n";
    cout << "Gio: ";
    cin >> gioKhoiHanh.h;
    cout << "Phut: ";
    cin >> gioKhoiHanh.m;

    cout << "Nhap ngay khoi hanh:\n";
    cout << "Ngay: ";
    cin >> ngayKhoiHanh.d;
    cout << "Thang: ";
    cin >> ngayKhoiHanh.m;
    cout << "Nam: ";
    cin >> ngayKhoiHanh.y;

    cout << "Nhap gia ve: ";
    cin >> giaVe;

    cout << "Nhap so ve con lai: ";
    cin >> soVeConLai;
    cin.ignore();

    cout << "Nhap bien so xe: ";
    getline(cin, bienSoXe);

    int soDiemDung;
    cout << "Nhap so diem dung: ";
    cin >> soDiemDung;
    cin.ignore();
    for (int i = 0; i < soDiemDung; ++i) {
        string diem;
        Gio gioDung;
        int thoiGianDung;

        cin.ignore();

        cout << "Nhap diem dung thu " << i + 1 << ": ";
        getline(cin, diem);

        cout << "Nhap gio dung:\n";
        cout << "Gio: ";
        cin >> gioDung.h;
        cout << "Phut: ";
        cin >> gioDung.m;

        cout << "Nhap thoi gian dung (phut): ";
        cin >> thoiGianDung;

        diemDung.push_back(make_tuple(diem, gioDung, thoiGianDung));
    }

    cout << "Nhap quy dinh hanh ly: ";
    getline(cin, quyDinhHanhLy);

    cout << "Nhap chinh sach huy ve: ";
    getline(cin, chinhSachHuyVe);

    cout << "Nhap thong tin lien he: ";
    getline(cin, thongTinLienHe);

    return ChuyenXe(maChuyenXe, diemDi, diemDen, gioKhoiHanh, ngayKhoiHanh, giaVe, 
                    soVeConLai, bienSoXe, diemDung, quyDinhHanhLy, chinhSachHuyVe,
                    thongTinLienHe);
}

void ChuyenXe::inChuyenXe() const {
    cout << "Thong tin co ban:\n";
    cout << "Ma chuyen xe: " << maChuyenXe << "\n";
    cout << "Diem di: " << diemDi << "\n";
    cout << "Diem den: " << diemDen << "\n";
    cout << "Gio khoi hanh: " << gioKhoiHanh.h << ":" << gioKhoiHanh.m << "\n";
    cout << "Ngay khoi hanh: " << ngayKhoiHanh.d << "/" << ngayKhoiHanh.m << "/" << ngayKhoiHanh.y << "\n";
    cout << "Gia ve: " << giaVe << "\n";
    cout << "So ve con lai: " << soVeConLai << "\n";
    cout << "Bien so xe: " << bienSoXe << "\n";
    cout << "\nThong tin khac:\n";
    cout << "Hanh trinh di chuyen:\n";
    for (int i = 0; i < diemDung.size(); i++) {
        cout << "Diem dung thu " << i + 1 << ": " << get<0>(diemDung[i]) <<
                ", thoi diem dung: " << get<1>(diemDung[i]).h << 
                ":" << get<1>(diemDung[i]).m <<
                ", thoi gian dung: " << get<2>(diemDung[i]) << " phut\n";
    }
    cout << "Quy dinh hanh ly: " << quyDinhHanhLy << "\n";
    cout << "Chinh sach huy ve: " << chinhSachHuyVe << "\n";
    cout << "Thong tin lien he: " << thongTinLienHe << "\n";
}

//------------------Chuyen bay -------------------

ChuyenBay::ChuyenBay() {
    maChuyenBay = "";
    diemDi = "";
    diemDen = "";
    gioKhoiHanh = Gio();
    ngayKhoiHanh = Ngay();
    giaVe = 0;
    soVeConLai = 0;
    maMayBay = "";
    diemDung = vector<tuple<string, Gio, int>>();
    quyDinhHanhLy = "";
    chinhSachHuyVe = "";
    thongTinLienHe = "";
}

ChuyenBay::ChuyenBay(const ChuyenBay& chuyenBay) {
    maChuyenBay = chuyenBay.maChuyenBay;
    diemDi = chuyenBay.diemDi;
    diemDen = chuyenBay.diemDen;
    gioKhoiHanh = chuyenBay.gioKhoiHanh;
    ngayKhoiHanh = chuyenBay.ngayKhoiHanh;
    giaVe = chuyenBay.giaVe;
    soVeConLai = chuyenBay.soVeConLai;
    maMayBay = chuyenBay.maMayBay;
    diemDung = chuyenBay.diemDung;
    quyDinhHanhLy = chuyenBay.quyDinhHanhLy;
    chinhSachHuyVe = chuyenBay.chinhSachHuyVe;
    thongTinLienHe = chuyenBay.thongTinLienHe;
}

ChuyenBay::ChuyenBay(string maChuyenBay, string diemDi, string diemDen,
                     Gio gioKhoiHanh, Ngay ngayKhoiHanh, int giaVe,
                     int soVeConLai, string maMayBay, string quyDinhHanhLy,
                      string chinhSachHuyVe, string thongTinLienHe) {
    this->maChuyenBay = maChuyenBay;
    this->diemDi = diemDi;
    this->diemDen = diemDen;
    this->gioKhoiHanh = gioKhoiHanh;
    this->ngayKhoiHanh = ngayKhoiHanh;
    this->giaVe = giaVe;
    this->soVeConLai = soVeConLai;
    this->maMayBay = maMayBay;
    this->diemDung = diemDung;
    this->quyDinhHanhLy = quyDinhHanhLy;
    this->chinhSachHuyVe = chinhSachHuyVe;
    this->thongTinLienHe = thongTinLienHe;
}

string ChuyenBay::getMaChuyenBay() {
    return maChuyenBay;
}

string ChuyenBay::getDiemDi() {
    return diemDi;
}

string ChuyenBay::getDiemDen() {
    return diemDen;
}

Gio ChuyenBay::getGioKhoiHanh() {
    return gioKhoiHanh;
}

Ngay ChuyenBay::getNgayKhoiHanh() {
    return ngayKhoiHanh;
}

int ChuyenBay::getGiaVe() {
    return giaVe;
}

int ChuyenBay::getSoVeConLai() {
    return soVeConLai;
}

void ChuyenBay::setSoVeConLai(int soVeConLai) {
    this->soVeConLai = soVeConLai;
}

string ChuyenBay::getMaMayBay() {
    return maMayBay;
}

string ChuyenBay::getQuyDinhHanhLy() {
    return quyDinhHanhLy;
}

string ChuyenBay::getChinhSachHuyVe() {
    return chinhSachHuyVe;
}

string ChuyenBay::getThongTinLienHe() {
    return thongTinLienHe;
}

ChuyenBay::~ChuyenBay() {
}

ChuyenBay ChuyenBayFactory::taoChuyenBay() {
    string maChuyenBay, diemDi, diemDen, maMayBay, quyDinhHanhLy, chinhSachHuyVe, thongTinLienHe;
    Gio gioKhoiHanh;
    Ngay ngayKhoiHanh;
    int giaVe, soVeConLai;

    vector<tuple<string, Gio, int>> diemDung;

    cout << "Nhap ma chuyen bay: ";
    getline(cin, maChuyenBay);

    cout << "Nhap diem di: ";
    getline(cin, diemDi);

    cout << "Nhap diem den: ";
    getline(cin, diemDen);


    cout << "Nhap gio khoi hanh:\n";
    cout << "Gio: ";
    cin >> gioKhoiHanh.h;
    cout << "Phut: ";
    cin >> gioKhoiHanh.m;

    cout << "Nhap ngay khoi hanh:\n";
    cout << "Ngay: ";
    cin >> ngayKhoiHanh.d;
    cout << "Thang: ";
    cin >> ngayKhoiHanh.m;
    cout << "Nam: ";
    cin >> ngayKhoiHanh.y;

    cout << "Nhap gia ve: ";
    cin >> giaVe;

    cout << "Nhap so ve con lai: ";
    cin >> soVeConLai;
    cin.ignore();

    cout << "Nhap ma may bay: ";
    getline(cin, maMayBay);

    cout << "Nhap quy dinh hanh ly: ";
    getline(cin, quyDinhHanhLy);

    cout << "Nhap chinh sach huy ve: ";
    getline(cin, chinhSachHuyVe);

    cout << "Nhap thong tin lien he: ";
    getline(cin, thongTinLienHe);

    return ChuyenBay(maChuyenBay, diemDi, diemDen, gioKhoiHanh, ngayKhoiHanh, giaVe,
        soVeConLai, maMayBay,quyDinhHanhLy, chinhSachHuyVe,
        thongTinLienHe);
}

void ChuyenBay::inChuyenBay() const {
    cout << "Thong tin co ban:\n";
    cout << "Ma chuyen bay: " << maChuyenBay << "\n";
    cout << "Diem di: " << diemDi << "\n";
    cout << "Diem den: " << diemDen << "\n";
    cout << "Gio khoi hanh: " << gioKhoiHanh.h << ":" << gioKhoiHanh.m << "\n";
    cout << "Ngay khoi hanh: " << ngayKhoiHanh.d << "/" << ngayKhoiHanh.m << "/" << ngayKhoiHanh.y << "\n";
    cout << "Gia ve: " << giaVe << "\n";
    cout << "So ve con lai: " << soVeConLai << "\n";
    cout << "Ma may bay: " << maMayBay << "\n";
    cout << "\nThong tin khac:\n";
    cout << "Quy dinh hanh ly: " << quyDinhHanhLy << "\n";
    cout << "Chinh sach huy ve: " << chinhSachHuyVe << "\n";
    cout << "Thong tin lien he: " << thongTinLienHe << "\n";
}

//-----------------------ChuyenTauHoa-----------------
ChuyenTauHoa::ChuyenTauHoa() {
    maChuyenTau = "";
    gaDi = "";
    gaDen = "";
    gioKhoiHanh = Gio();
    ngayKhoiHanh = Ngay();
    giaVe = 0;
    soVeConLai = 0;
    maTau = "";
    gaDung = vector<tuple<string, Gio, int>>();
    quyDinhHanhLy = "";
    chinhSachHuyVe = "";
    thongTinLienHe = "";
}

ChuyenTauHoa::ChuyenTauHoa(const ChuyenTauHoa& chuyenTau) {
    maChuyenTau = chuyenTau.maChuyenTau;
    gaDi = chuyenTau.gaDi;
    gaDen = chuyenTau.gaDen;
    gioKhoiHanh = chuyenTau.gioKhoiHanh;
    ngayKhoiHanh = chuyenTau.ngayKhoiHanh;
    giaVe = chuyenTau.giaVe;
    soVeConLai = chuyenTau.soVeConLai;
    maTau = chuyenTau.maTau;
    gaDung = chuyenTau.gaDung;
    quyDinhHanhLy = chuyenTau.quyDinhHanhLy;
    chinhSachHuyVe = chuyenTau.chinhSachHuyVe;
    thongTinLienHe = chuyenTau.thongTinLienHe;
}

ChuyenTauHoa::ChuyenTauHoa(string maChuyenTau, string gaDi, string gaDen,
                             Gio gioKhoiHanh, Ngay ngayKhoiHanh, int giaVe,
                             int soVeConLai, string maTau, vector<tuple<string, Gio, int>> gaDung,
                             string quyDinhHanhLy, string chinhSachHuyVe, string thongTinLienHe) {
    this->maChuyenTau = maChuyenTau;
    this->gaDi = gaDi;
    this->gaDen = gaDen;
    this->gioKhoiHanh = gioKhoiHanh;
    this->ngayKhoiHanh = ngayKhoiHanh;
    this->giaVe = giaVe;
    this->soVeConLai = soVeConLai;
    this->maTau = maTau;
    this->gaDung = gaDung;
    this->quyDinhHanhLy = quyDinhHanhLy;
    this->chinhSachHuyVe = chinhSachHuyVe;
    this->thongTinLienHe = thongTinLienHe;
}

string ChuyenTauHoa::getMaChuyenTau() {
    return maChuyenTau;
}

string ChuyenTauHoa::getGaDi() {
    return gaDi;
}

string ChuyenTauHoa::getGaDen() {
    return gaDen;
}

Gio ChuyenTauHoa::getGioKhoiHanh() {
    return gioKhoiHanh;
}

Ngay ChuyenTauHoa::getNgayKhoiHanh() {
    return ngayKhoiHanh;
}

int ChuyenTauHoa::getGiaVe() {
    return giaVe;
}

int ChuyenTauHoa::getSoVeConLai() {
    return soVeConLai;
}

void ChuyenTauHoa::setSoVeConLai(int soVeConLai) {
    this->soVeConLai = soVeConLai;
}

string ChuyenTauHoa::getMaTau() {
    return maTau;
}

vector<tuple<string, Gio, int>> ChuyenTauHoa::getGaDung() {
    return gaDung;
}

string ChuyenTauHoa::getQuyDinhHanhLy() {
    return quyDinhHanhLy;
}

string ChuyenTauHoa::getChinhSachHuyVe() {
    return chinhSachHuyVe;
}

string ChuyenTauHoa::getThongTinLienHe() {
    return thongTinLienHe;
}

ChuyenTauHoa::~ChuyenTauHoa() {
}

ChuyenTauHoa ChuyenTauHoaFactory::taoChuyenTau() {
    string maChuyenTau, gaDi, gaDen, maTau, quyDinhHanhLy, chinhSachHuyVe, thongTinLienHe;
    Gio gioKhoiHanh;
    Ngay ngayKhoiHanh;
    int giaVe, soVeConLai;

    vector<tuple<string, Gio, int>> gaDung;

    cout << "Nhap ma chuyen tau: ";
    getline(cin, maChuyenTau);

    cout << "Nhap ga di: ";
    getline(cin, gaDi);

    cout << "Nhap ga den: ";
    getline(cin, gaDen);

    cout << "Nhap gio khoi hanh:\n";
    cout << "Gio: ";
    cin >> gioKhoiHanh.h;
    cout << "Phut: ";
    cin >> gioKhoiHanh.m;

    cout << "Nhap ngay khoi hanh:\n";
    cout << "Ngay: ";
    cin >> ngayKhoiHanh.d;
    cout << "Thang: ";
    cin >> ngayKhoiHanh.m;
    cout << "Nam: ";
    cin >> ngayKhoiHanh.y;
    cout << "Nhap gia ve: ";
    cin >> giaVe;

    cout << "Nhap so ve con lai: ";
    cin >> soVeConLai;
 
    cout << "Nhap ma tau: ";
    getline(cin, maTau);

    int soDiemDung;
    cout << "Nhap so diem dung: ";
    cin >> soDiemDung;
    cin.ignore();
    for (int i = 0; i < soDiemDung; ++i) {
        string diem;
        Gio gioDung;
        int thoiGianDung;

        cin.ignore();

        cout << "Nhap diem dung thu " << i + 1 << ": ";
        getline(cin, diem);

        cout << "Nhap gio dung:\n";
        cout << "Gio: ";
        cin >> gioDung.h;
        cout << "Phut: ";
        cin >> gioDung.m;

        cout << "Nhap thoi gian dung (phut): ";
        cin >> thoiGianDung;

        gaDung.push_back(make_tuple(diem, gioDung, thoiGianDung));
    }

    cout << "Nhap gio khoi hanh:\n";
    cout << "Gio: ";
    cin >> gioKhoiHanh.h;
    cout << "\nPhut: ";
    cin >> gioKhoiHanh.m;

    cout << "Nhap ngay khoi hanh:\n";
    cout << "Ngay: ";
    cin >> ngayKhoiHanh.d;
    cout << "Thang: ";
    cin >> ngayKhoiHanh.m;
    cout << "Nam: ";
    cin >> ngayKhoiHanh.y;
    cout << "Nhap quy dinh hanh ly: ";
    getline(cin, quyDinhHanhLy);

    cout << "Nhap chinh sach huy ve: ";
    getline(cin, chinhSachHuyVe);

    cout << "Nhap thong tin lien he: ";
    getline(cin, thongTinLienHe);

    return ChuyenTauHoa(maChuyenTau, gaDi, gaDen, gioKhoiHanh, ngayKhoiHanh, giaVe,
        soVeConLai, maTau, gaDung, quyDinhHanhLy, chinhSachHuyVe,
        thongTinLienHe);
}

void ChuyenTauHoa::inChuyenTau() const {
    cout << "Thong tin co ban:\n";
    cout << "Ma chuyen tau: " << maChuyenTau << "\n";
    cout << "Ga di: " << gaDi << "\n";
    cout << "Ga den: " << gaDen << "\n";
    cout << "Gio khoi hanh: " << gioKhoiHanh.h << ":" << gioKhoiHanh.m << "\n";
    cout << "Ngay khoi hanh: " << ngayKhoiHanh.d << "/" << ngayKhoiHanh.m << "/" << ngayKhoiHanh.y << "\n";
    cout << "Gia ve: " << giaVe << "\n";
    cout << "So ve con lai: " << soVeConLai << "\n";
    cout << "Ma tau: " << maTau << "\n";
    cout << "\nThong tin khac:\n";
    cout << "Hanh trinh di chuyen:\n";
    for (int i = 0; i < gaDung.size(); i++) {
        cout << "Ga dung thu " << i + 1 << ": " << get<0>(gaDung[i]) <<
            ", thoi diem den: " << get<1>(gaDung[i]).h <<
            ":" << get<1>(gaDung[i]).m <<
            ", thoi gian dung: " << get<2>(gaDung[i]) << " phut\n";
    }
    cout << "Quy dinh hanh ly: " << quyDinhHanhLy << "\n";
    cout << "Chinh sach huy ve: " << chinhSachHuyVe << "\n";
    cout << "Thong tin lien he: " << thongTinLienHe << "\n";
}
