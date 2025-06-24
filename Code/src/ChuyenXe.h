#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

struct Gio {
    int h = 0;
    int m = 0;
};

struct Ngay {
    int d = 0;
    int m = 0;
    int y = 0;
};

/*----------------------ChuyenXe--------------------*/
class ChuyenXe {
    string maChuyenXe;
    string diemDi;
    string diemDen;
    Gio gioKhoiHanh;
    Ngay ngayKhoiHanh;
    int giaVe;
    int soVeConLai;
    string bienSoXe;
    vector<tuple<string, Gio, int>> diemDung;
    string quyDinhHanhLy;
    string chinhSachHuyVe;
    string thongTinLienHe;

public:
    ChuyenXe();
    ChuyenXe(const ChuyenXe& chuyenXe);
    ChuyenXe(string maChuyenXe, string diemDi, string diemDen, 
               Gio gioKhoiHanh, Ngay ngayKhoiHanh, int giaVe, 
                int soVeConLai, string bienSoXe, vector<tuple<string, Gio, int>> diemDung, 
                string quyDinhHanhLy, string chinhSachHuyVe, string thongTinLienHe);
    string getMaChuyenXe();
    string getDiemDi();
    string getDiemDen();
    Gio getGioKhoiHanh();
    Ngay getNgayKhoiHanh();
    int getGiaVe();
    int getSoVeConLai();
    void setSoVeConLai(int soVeConLai);
    string getBienSoXe();
    vector<tuple<string, Gio, int>>getDiemDung();

    string getQuyDinhHanhLy();
    string getChinhSachHuyVe();
    string getThongTinLienHe();
    void inChuyenXe() const;
    ~ChuyenXe();
};

class ChuyenXeFactory {
public:
    static ChuyenXe taoChuyenXe();
};


//-------------------Chuyen Bay -----------
class ChuyenBay {
    string maChuyenBay;
    string diemDi;
    string diemDen;
    Gio gioKhoiHanh;
    Ngay ngayKhoiHanh;
    int giaVe;
    int soVeConLai;
    string maMayBay;
    vector<tuple<string, Gio, int>> diemDung;
    string quyDinhHanhLy;
    string chinhSachHuyVe;
    string thongTinLienHe;

public:
    ChuyenBay();
    ChuyenBay(const ChuyenBay& chuyenBay);
    ChuyenBay(string maChuyenBay, string diemDi, string diemDen,
                Gio gioKhoiHanh, Ngay ngayKhoiHanh, int giaVe,
                 int soVeConLai, string maMayBay, string quyDinhHanhLy,
                 string chinhSachHuyVe, string thongTinLienHe);
    string getMaChuyenBay();
    string getDiemDi();
    string getDiemDen();
    Gio getGioKhoiHanh();
    Ngay getNgayKhoiHanh();
    int getGiaVe();
    int getSoVeConLai();
    void setSoVeConLai(int soVeConLai);
    string getMaMayBay();
    string getQuyDinhHanhLy();
    string getChinhSachHuyVe();
    string getThongTinLienHe();
    void inChuyenBay() const;
    ~ChuyenBay();
};

class ChuyenBayFactory {
public:
    static ChuyenBay taoChuyenBay();
};

//------------------ChuyenTauHoa-------------
class ChuyenTauHoa {
    string maChuyenTau;
    string gaDi;
    string gaDen;
    Gio gioKhoiHanh;
    Ngay ngayKhoiHanh;
    int giaVe;
    int soVeConLai;
    string maTau;
    vector<tuple<string, Gio, int>> gaDung;
    string quyDinhHanhLy;
    string chinhSachHuyVe;
    string thongTinLienHe;

public:
    ChuyenTauHoa();
    ChuyenTauHoa(const ChuyenTauHoa& chuyenTau);
    ChuyenTauHoa(string maChuyenTau, string gaDi, string gaDen,
                 Gio gioKhoiHanh, Ngay ngayKhoiHanh, int giaVe,
                int soVeConLai, string maTau, vector<tuple<string, Gio, int>> gaDung,
                string quyDinhHanhLy, string chinhSachHuyVe, string thongTinLienHe);
    string getMaChuyenTau();
    string getGaDi();
    string getGaDen();
    Gio getGioKhoiHanh();
    Ngay getNgayKhoiHanh();
    int getGiaVe();
    int getSoVeConLai();
    void setSoVeConLai(int soVeConLai);
    string getMaTau();
    vector<tuple<string, Gio, int>> getGaDung();
    string getQuyDinhHanhLy();
    string getChinhSachHuyVe();
    string getThongTinLienHe();
    void inChuyenTau() const;
    ~ChuyenTauHoa();
};

class ChuyenTauHoaFactory {
public:
    static ChuyenTauHoa taoChuyenTau();
};
