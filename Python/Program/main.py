from models import KaryawanLoket, KaryawanProyeksionis, KaryawanKebersihan, Bioskop

def main():
    # 1. Buat object Bioskop (class composition)
    bioskop = Bioskop("CGV Grand Indonesia", "Jl. MH Thamrin No. 1, Jakarta")

    # 2. Tambahkan beberapa Karyawan awal -> array of object di dalam
    #    Bioskop terisi dengan campuran 3 jenis child class sekaligus
    bioskop.tambah_karyawan(KaryawanLoket(1, "Siti Aminah", "081234567001", "Pagi", 120))
    bioskop.tambah_karyawan(KaryawanLoket(2, "Budi Hartono", "081234567002", "Malam", 95))
    bioskop.tambah_karyawan(KaryawanProyeksionis(3, "Rudi Setiawan", "081234567003",
                                                  "Studio 1", "Bersertifikat"))
    bioskop.tambah_karyawan(KaryawanKebersihan(4, "Dewi Lestari", "081234567004",
                                                "Lobby Utama", "Setiap 2 jam"))

    # 3. Tampilkan data SEBELUM ada penambahan baru
    print("#" * 50)
    print("DATA SEBELUM PENAMBAHAN")
    print("#" * 50)
    bioskop.tampilkan_semua_karyawan()

    # 4. Tambahkan 1 Karyawan baru -> membuktikan data bisa ditambahkan
    karyawan_baru = KaryawanProyeksionis(5, "Fajar Nugraha", "081234567005",
                                          "Studio 3", "Bersertifikat")
    bioskop.tambah_karyawan(karyawan_baru)

    # Sedikit demo pemakaian method khusus tiap child class
    print(f"\n[Log aktivitas] {karyawan_baru.putar_film('Interstellar')}")

    # 5. Tampilkan data SESUDAH penambahan
    print("\n" + "#" * 50)
    print("DATA SESUDAH PENAMBAHAN")
    print("#" * 50)
    bioskop.tampilkan_semua_karyawan()


if __name__ == "__main__":
    main()