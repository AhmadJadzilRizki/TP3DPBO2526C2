class Karyawan:
    # ===== PARENT CLASS (induk dari hierarchical inheritance) =====
    def __init__(self, id_karyawan: int, nama: str, no_hp: str):
        self.__id_karyawan = id_karyawan
        self.__nama = nama
        self.__no_hp = no_hp

    # ===== Getter =====
    def get_id(self):
        return self.__id_karyawan

    def get_nama(self):
        return self.__nama

    def get_no_hp(self):
        return self.__no_hp

    # ===== Setter =====
    def set_no_hp(self, no_hp: str):
        self.__no_hp = no_hp

    def get_info(self) -> str:
        # Method ini di-override oleh ketiga class anak. Dipanggil lewat
        # super().get_info() dulu, baru ditambah info khusus jabatannya.
        return f"ID: {self.__id_karyawan} | Nama: {self.__nama} | No HP: {self.__no_hp}"


class KaryawanLoket(Karyawan):
    # ===== CHILD 1 dari Karyawan (Hierarchical Inheritance) =====
    def __init__(self, id_karyawan: int, nama: str, no_hp: str,
                 shift_loket: str, jumlah_tiket_terjual: int):
        super().__init__(id_karyawan, nama, no_hp)  # constructor parent
        self.__shift_loket = shift_loket
        self.__jumlah_tiket_terjual = jumlah_tiket_terjual

    def get_shift_loket(self):
        return self.__shift_loket

    def get_jumlah_tiket_terjual(self):
        return self.__jumlah_tiket_terjual

    # Method tambahan khusus KaryawanLoket
    def jual_tiket(self, jumlah: int):
        self.__jumlah_tiket_terjual += jumlah

    def get_info(self) -> str:
        info_dasar = super().get_info()  # ambil info dari Karyawan (parent)
        return (f"{info_dasar} | Jabatan: Staff Loket | "
                f"Shift: {self.__shift_loket} | "
                f"Tiket Terjual: {self.__jumlah_tiket_terjual}")


class KaryawanProyeksionis(Karyawan):
    # ===== CHILD 2 dari Karyawan (Hierarchical Inheritance) =====
    def __init__(self, id_karyawan: int, nama: str, no_hp: str,
                 ruang_proyeksi: str, sertifikasi_proyektor: str):
        super().__init__(id_karyawan, nama, no_hp)
        self.__ruang_proyeksi = ruang_proyeksi
        self.__sertifikasi_proyektor = sertifikasi_proyektor

    def get_ruang_proyeksi(self):
        return self.__ruang_proyeksi

    def get_sertifikasi_proyektor(self):
        return self.__sertifikasi_proyektor

    # Method tambahan khusus KaryawanProyeksionis
    def putar_film(self, judul_film: str) -> str:
        return f"{self.get_nama()} memutar film '{judul_film}' di {self.__ruang_proyeksi}"

    def get_info(self) -> str:
        info_dasar = super().get_info()
        return (f"{info_dasar} | Jabatan: Proyeksionis | "
                f"Ruang: {self.__ruang_proyeksi} | "
                f"Sertifikasi: {self.__sertifikasi_proyektor}")


class KaryawanKebersihan(Karyawan):
    # ===== CHILD 3 dari Karyawan (Hierarchical Inheritance) =====
    def __init__(self, id_karyawan: int, nama: str, no_hp: str,
                 area_tugas: str, jadwal_bersih: str):
        super().__init__(id_karyawan, nama, no_hp)
        self.__area_tugas = area_tugas
        self.__jadwal_bersih = jadwal_bersih

    def get_area_tugas(self):
        return self.__area_tugas

    def get_jadwal_bersih(self):
        return self.__jadwal_bersih

    # Method tambahan khusus KaryawanKebersihan
    def bersihkan_area(self) -> str:
        return f"{self.get_nama()} membersihkan {self.__area_tugas}"

    def get_info(self) -> str:
        info_dasar = super().get_info()
        return (f"{info_dasar} | Jabatan: Kebersihan | "
                f"Area: {self.__area_tugas} | "
                f"Jadwal: {self.__jadwal_bersih}")


class Bioskop:
    # ===== CLASS COMPOSITION =====
    # Bioskop "memiliki" banyak Karyawan (HAS-A), bukan "adalah" Karyawan
    # (bukan is-a, jadi ini BUKAN inheritance, melainkan composition).
    def __init__(self, nama_bioskop: str, alamat: str):
        self.__nama_bioskop = nama_bioskop
        self.__alamat = alamat
        # ARRAY OF OBJECT -> list ini bisa menampung KaryawanLoket,
        # KaryawanProyeksionis, MAUPUN KaryawanKebersihan sekaligus
        # (contoh POLYMORPHISM, karena semua diperlakukan sebagai Karyawan)
        self.__daftar_karyawan = []

    def get_nama_bioskop(self):
        return self.__nama_bioskop

    def get_jumlah_karyawan(self):
        return len(self.__daftar_karyawan)

    # Fitur: data bisa ditambahkan (statis/manual lewat kode, sesuai modul
    # "penambahan data tidak harus dinamis")
    def tambah_karyawan(self, karyawan: Karyawan):
        self.__daftar_karyawan.append(karyawan)

    def tampilkan_semua_karyawan(self):
        print(f"\n=== Bioskop: {self.__nama_bioskop} ({self.__alamat}) ===")
        print(f"Total karyawan: {len(self.__daftar_karyawan)}")
        if not self.__daftar_karyawan:
            print("Belum ada karyawan.")
            return
        for karyawan in self.__daftar_karyawan:
            # karyawan.get_info() otomatis manggil versi class aslinya
            # (KaryawanLoket/Proyeksionis/Kebersihan), bukan selalu versi
            # Karyawan -> ini contoh nyata polymorphism
            print("-", karyawan.get_info())