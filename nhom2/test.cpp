#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Cấu trúc lưu trữ thông tin lớp học
struct LopHoc {
    string maLop;
    string tenHocPhan;
    string tenGiaoVien;
    LopHoc* next;
};

// Cấu trúc lưu trữ thông tin trẻ
struct Tre {
    string maTre;
    string hoLot;
    string ten;
    string ngaySinh;
    string tenPhuHuynh;
    string soDienThoai;
    string moiQuanHe;
    string maLop;
    Tre* next;
};

// Hàm để đọc thông tin lớp học từ file
void docFileLopHoc(LopHoc*& dsLop) {
    ifstream file("lophoc.txt");
    if (file.is_open()) {
        LopHoc* temp;
        while (!file.eof()) {
            temp = new LopHoc;
            file >> temp->maLop >> temp->tenHocPhan >> temp->tenGiaoVien;
            temp->next = dsLop;
            dsLop = temp;
        }
        file.close();
    }
}

// Hàm để đọc thông tin trẻ từ file
void docFileTre(Tre*& dsTre) {
    ifstream file("tre.txt");
    if (file.is_open()) {
        Tre* temp;
        while (!file.eof()) {
            temp = new Tre;
            file >> temp->maTre >> temp->hoLot >> temp->ten >> temp->ngaySinh >> temp->tenPhuHuynh >> temp->soDienThoai >> temp->moiQuanHe >> temp->maLop;
            temp->next = dsTre;
            dsTre = temp;
        }
        file.close();
    }
}

// Hàm để thêm trẻ vào danh sách
void themTre(Tre*& dsTre) {
    Tre* temp = new Tre;
    cout << "Nhap ma tre: ";
    cin >> temp->maTre;
    cout << "Nhap ho lot: ";
    cin >> temp->hoLot;
    cout << "Nhap ten: ";
    cin >> temp->ten;
    cout << "Nhap ngay sinh: ";
    cin >> temp->ngaySinh;
    cout << "Nhap ten phu huynh: ";
    cin >> temp->tenPhuHuynh;
    cout << "Nhap so dien thoai: ";
    cin >> temp->soDienThoai;
    cout << "Nhap moi quan he: ";
    cin >> temp->moiQuanHe;
    cout << "Nhap ma lop: ";
    cin >> temp->maLop;
    temp->next = dsTre;
    dsTre = temp;
}

// Hàm tìm kiếm trẻ theo mã hoặc theo tên
void timKiemTre(Tre* dsTre, string key) {
    Tre* temp = dsTre;
    while (temp != nullptr) {
        if (temp->maTre == key || temp->ten == key) {
            cout << "Tim thay tre: " << temp->hoLot << " " << temp->ten << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Khong tim thay tre!" << endl;
}

int main() {
    LopHoc* dsLop = nullptr;
    Tre* dsTre = nullptr;

    // Đọc dữ liệu từ file
    docFileLopHoc(dsLop);
    docFileTre(dsTre);

    // Thêm trẻ vào danh sách
    themTre(dsTre);

    // Tìm kiếm trẻ
    string key;
    cout << "Nhap ma tre hoac ten can tim: ";
    cin >> key;
    timKiemTre(dsTre, key);

    return 0;
}