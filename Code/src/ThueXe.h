#pragma once
#include<vector>
#include<string>
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

class Xe {
private:
    static vector<Xe*> danhSachXeMau;
    string bienSo;
    int soChoNgoi;

public:
    Xe();
    Xe(const Xe& xe);
    virtual Xe* Clone() = 0;
    virtual string getLoaiXe() = 0;
    static void themXeMau(Xe* xe);
    static Xe* taoXe(string loaiXe);
    static void xoaXeMau();
    virtual ~Xe() {};
    void nhapXe();
    void xuatXe();
    void setBienSo(string bienSo);
    void setSoChoNgoi(int soChoNgoi);
    string getBienSo() const;
    int getSoChoNgoi() const;
};

class ThueXe {
private:
    Xe* xe;
    Ngay ngayThue;
    Gio gioBatDau;
    Gio gioKetThuc;
    string thanhPhoDangO;

public:
    ThueXe();
    ThueXe(Xe* xe, Ngay ngay, Gio batDau, Gio ketThuc, string thanhPho);
    ~ThueXe();

    void nhapThongTinThue();
    void xuatThongTinThue() const;
};

class XeMay : public Xe {
public:
    XeMay() : Xe() {}
    XeMay(const XeMay& xe) : Xe(xe) {}

    string getLoaiXe() override {
        return "Xe may";
    }

    Xe* Clone() override {
        return new XeMay(*this);
    }
};

class XeDap : public Xe {
public:
    XeDap() : Xe() {}
    XeDap(const XeDap& xe) : Xe(xe) {}

    string getLoaiXe() override {
        return "Xe dap";
    }

    Xe* Clone() override {
        return new XeDap(*this);
    }
};

class XeOtoTuLai : public Xe {
public:
    XeOtoTuLai() : Xe() {}
    XeOtoTuLai(const XeOtoTuLai& xe) : Xe(xe) {}

    string getLoaiXe() override {
        return "O to tu lai";
    }

    Xe* Clone() override {
        return new XeOtoTuLai(*this);
    }
};

class XeFactory {
public:
    static Xe* createXe(const string& loaiXe) {
        return Xe::taoXe(loaiXe);
    }
};
