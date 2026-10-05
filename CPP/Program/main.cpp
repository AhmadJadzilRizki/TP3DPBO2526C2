#include <iostream>
#include "models.h"
using namespace std;

int main() {
    // 1. Buat object Bioskop (class composition)
    Bioskop bioskop("CGV Grand Indonesia", "Jl. MH Thamrin No. 1, Jakarta");

    // 2. Tambahkan beberapa Karyawan awal -> array of object di dalam
    //    Bioskop terisi dengan campuran 3 jenis child class sekaligus.
    //    Pakai 'new' karena daftarKaryawan di Bioskop berupa vector<Karyawan*>
    bioskop.tambahKaryawan(new KaryawanLoket(1, "Siti Aminah", "081234567001", "Pagi", 120));
    bioskop.tambahKaryawan(new KaryawanLoket(2, "Budi Hartono", "081234567002", "Malam", 95));
    bioskop.tambahKaryawan(new KaryawanProyeksionis(3, "Rudi Setiawan", "081234567003",
                                                      "Studio 1", "Bersertifikat"));
    bioskop.tambahKaryawan(new KaryawanKebersihan(4, "Dewi Lestari", "081234567004",
                                                    "Lobby Utama", "Setiap 2 jam"));

    // 3. Tampilkan data SEBELUM ada penambahan baru
    cout << string(50, '#') << endl;
    cout << "DATA SEBELUM PENAMBAHAN" << endl;
    cout << string(50, '#') << endl;
    bioskop.tampilkanSemuaKaryawan();

    // 4. Tambahkan 1 Karyawan baru -> membuktikan data bisa ditambahkan
    KaryawanProyeksionis* karyawanBaru = new KaryawanProyeksionis(
        5, "Fajar Nugraha", "081234567005", "Studio 3", "Bersertifikat");
    bioskop.tambahKaryawan(karyawanBaru);

    // Sedikit demo pemakaian method khusus tiap child class
    cout << "\n[Log aktivitas] " << karyawanBaru->putarFilm("Interstellar") << endl;

    // 5. Tampilkan data SESUDAH penambahan
    cout << "\n" << string(50, '#') << endl;
    cout << "DATA SESUDAH PENAMBAHAN" << endl;
    cout << string(50, '#') << endl;
    bioskop.tampilkanSemuaKaryawan();

    // Tidak perlu delete manual satu-satu di sini -> destructor Bioskop
    // (lihat models.cpp) otomatis membersihkan semua Karyawan* saat
    // object 'bioskop' keluar dari scope di akhir main()

    return 0;
}