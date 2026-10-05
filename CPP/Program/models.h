#include <string>
#include <vector>
using namespace std;

class Karyawan {
private:
    int idKaryawan;
    string nama;
    string noHp;

public:
    Karyawan();
    Karyawan(int idKaryawan, string nama, string noHp);
    virtual ~Karyawan();  // destructor virtual -> wajib untuk class polymorphic

    // ===== Getter =====
    int getId();
    string getNama();
    string getNoHp();

    // ===== Setter =====
    void setNoHp(string noHp);

    // virtual -> di-override tiap class anak, dipanggil lewat super-call
    virtual string getInfo();
};


class KaryawanLoket : public Karyawan {
    // ===== CHILD 1 dari Karyawan (Hierarchical Inheritance) =====
private:
    string shiftLoket;
    int jumlahTiketTerjual;

public:
    KaryawanLoket();
    KaryawanLoket(int idKaryawan, string nama, string noHp,
                  string shiftLoket, int jumlahTiketTerjual);

    string getShiftLoket();
    int getJumlahTiketTerjual();

    // Method tambahan khusus KaryawanLoket
    void jualTiket(int jumlah);

    string getInfo() override;
};


class KaryawanProyeksionis : public Karyawan {
    // ===== CHILD 2 dari Karyawan (Hierarchical Inheritance) =====
private:
    string ruangProyeksi;
    string sertifikasiProyektor;

public:
    KaryawanProyeksionis();
    KaryawanProyeksionis(int idKaryawan, string nama, string noHp,
                          string ruangProyeksi, string sertifikasiProyektor);

    string getRuangProyeksi();
    string getSertifikasiProyektor();

    // Method tambahan khusus KaryawanProyeksionis
    string putarFilm(string judulFilm);

    string getInfo() override;
};


class KaryawanKebersihan : public Karyawan {
    // ===== CHILD 3 dari Karyawan (Hierarchical Inheritance) =====
private:
    string areaTugas;
    string jadwalBersih;

public:
    KaryawanKebersihan();
    KaryawanKebersihan(int idKaryawan, string nama, string noHp,
                        string areaTugas, string jadwalBersih);

    string getAreaTugas();
    string getJadwalBersih();

    // Method tambahan khusus KaryawanKebersihan
    string bersihkanArea();

    string getInfo() override;
};


class Bioskop {
    // ===== CLASS COMPOSITION =====
    // Bioskop "memiliki" banyak Karyawan (HAS-A), bukan "adalah" Karyawan
    // (bukan is-a, jadi ini BUKAN inheritance, melainkan composition).
private:
    string namaBioskop;
    string alamat;
    // ARRAY OF OBJECT -> vector ini bisa menampung KaryawanLoket,
    // KaryawanProyeksionis, MAUPUN KaryawanKebersihan sekaligus lewat
    // pointer (supaya POLYMORPHISM jalan)
    vector<Karyawan*> daftarKaryawan;

public:
    Bioskop(string namaBioskop, string alamat);
    ~Bioskop();  // menghapus semua Karyawan* -> bukti kepemilikan composition

    string getNamaBioskop();
    int getJumlahKaryawan();

    // Fitur: data bisa ditambahkan (statis lewat kode, sesuai modul)
    void tambahKaryawan(Karyawan* karyawan);

    void tampilkanSemuaKaryawan();
};

