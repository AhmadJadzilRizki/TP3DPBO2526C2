#include "models.h"
#include <iostream>
using namespace std;

// ================= Karyawan (Parent) =================

Karyawan::Karyawan() {
    idKaryawan = 0;
    nama = "";
    noHp = "";
}

Karyawan::Karyawan(int idKaryawan, string nama, string noHp) {
    this->idKaryawan = idKaryawan;
    this->nama = nama;
    this->noHp = noHp;
}

Karyawan::~Karyawan() {}

int Karyawan::getId() { return idKaryawan; }
string Karyawan::getNama() { return nama; }
string Karyawan::getNoHp() { return noHp; }

void Karyawan::setNoHp(string noHp) { this->noHp = noHp; }

string Karyawan::getInfo() {
    return "ID: " + to_string(idKaryawan) + " | Nama: " + nama + " | No HP: " + noHp;
}


// ================= KaryawanLoket (Child 1) =================

KaryawanLoket::KaryawanLoket() : Karyawan() {
    shiftLoket = "";
    jumlahTiketTerjual = 0;
}

KaryawanLoket::KaryawanLoket(int idKaryawan, string nama, string noHp,
                              string shiftLoket, int jumlahTiketTerjual)
    : Karyawan(idKaryawan, nama, noHp) {  // memanggil constructor parent
    this->shiftLoket = shiftLoket;
    this->jumlahTiketTerjual = jumlahTiketTerjual;
}

string KaryawanLoket::getShiftLoket() { return shiftLoket; }
int KaryawanLoket::getJumlahTiketTerjual() { return jumlahTiketTerjual; }

void KaryawanLoket::jualTiket(int jumlah) {
    jumlahTiketTerjual += jumlah;
}

string KaryawanLoket::getInfo() {
    string infoDasar = Karyawan::getInfo();  // ambil info dari parent
    return infoDasar + " | Jabatan: Staff Loket | Shift: " + shiftLoket +
           " | Tiket Terjual: " + to_string(jumlahTiketTerjual);
}


// ================= KaryawanProyeksionis (Child 2) =================

KaryawanProyeksionis::KaryawanProyeksionis() : Karyawan() {
    ruangProyeksi = "";
    sertifikasiProyektor = "";
}

KaryawanProyeksionis::KaryawanProyeksionis(int idKaryawan, string nama, string noHp,
                                            string ruangProyeksi, string sertifikasiProyektor)
    : Karyawan(idKaryawan, nama, noHp) {
    this->ruangProyeksi = ruangProyeksi;
    this->sertifikasiProyektor = sertifikasiProyektor;
}

string KaryawanProyeksionis::getRuangProyeksi() { return ruangProyeksi; }
string KaryawanProyeksionis::getSertifikasiProyektor() { return sertifikasiProyektor; }

string KaryawanProyeksionis::putarFilm(string judulFilm) {
    return getNama() + " memutar film '" + judulFilm + "' di " + ruangProyeksi;
}

string KaryawanProyeksionis::getInfo() {
    string infoDasar = Karyawan::getInfo();
    return infoDasar + " | Jabatan: Proyeksionis | Ruang: " + ruangProyeksi +
           " | Sertifikasi: " + sertifikasiProyektor;
}


// ================= KaryawanKebersihan (Child 3) =================

KaryawanKebersihan::KaryawanKebersihan() : Karyawan() {
    areaTugas = "";
    jadwalBersih = "";
}

KaryawanKebersihan::KaryawanKebersihan(int idKaryawan, string nama, string noHp,
                                        string areaTugas, string jadwalBersih)
    : Karyawan(idKaryawan, nama, noHp) {
    this->areaTugas = areaTugas;
    this->jadwalBersih = jadwalBersih;
}

string KaryawanKebersihan::getAreaTugas() { return areaTugas; }
string KaryawanKebersihan::getJadwalBersih() { return jadwalBersih; }

string KaryawanKebersihan::bersihkanArea() {
    return getNama() + " membersihkan " + areaTugas;
}

string KaryawanKebersihan::getInfo() {
    string infoDasar = Karyawan::getInfo();
    return infoDasar + " | Jabatan: Kebersihan | Area: " + areaTugas +
           " | Jadwal: " + jadwalBersih;
}


// ================= Bioskop (Composition) =================

Bioskop::Bioskop(string namaBioskop, string alamat) {
    this->namaBioskop = namaBioskop;
    this->alamat = alamat;
}

Bioskop::~Bioskop() {
    // Bioskop bertanggung jawab menghapus semua Karyawan yang dimilikinya
    // -> inilah bukti nyata COMPOSITION (ikatan kuat, bukan cuma referensi)
    for (Karyawan* k : daftarKaryawan) {
        delete k;
    }
}

string Bioskop::getNamaBioskop() { return namaBioskop; }
int Bioskop::getJumlahKaryawan() { return (int)daftarKaryawan.size(); }

void Bioskop::tambahKaryawan(Karyawan* karyawan) {
    daftarKaryawan.push_back(karyawan);
}

void Bioskop::tampilkanSemuaKaryawan() {
    cout << "\n=== Bioskop: " << namaBioskop << " (" << alamat << ") ===" << endl;
    cout << "Total karyawan: " << daftarKaryawan.size() << endl;
    if (daftarKaryawan.empty()) {
        cout << "Belum ada karyawan." << endl;
        return;
    }
    for (Karyawan* k : daftarKaryawan) {
        // k->getInfo() otomatis manggil versi class aslinya (KaryawanLoket/
        // Proyeksionis/Kebersihan) karena getInfo() virtual -> POLYMORPHISM
        cout << "- " << k->getInfo() << endl;
    }
}