#include "Authenticator.hpp"
#include "User.hpp"
#include "AdminUser.hpp"

Authenticator::Authenticator() {
    this->secretResource = "Ini adalah data rahasia!";
    this->userCount = 0;
    this->currentUser = nullptr;
}

void Authenticator::registerUser(const string &username, const string &password, bool isAdmin) {
  if (this->userCount == MAX_USERS) {
      cout << "Gagal: Kapasitas user penuh!" << '\n';
  }
  else {
    bool found = false;
    for (int i = 0; i < userCount; i++) {
      if (this->users[i]->getUsername() == username) {
        found = true;
        break;
      }
    }
    if (found) {
      cout << "Gagal: Username sudah digunakan!" << '\n';
      return;
    }
    else if (isAdmin == false) {
      cout << "Sukses: User " << username << " berhasil terdaftar!" << '\n';
      this->users[userCount] = new User(username, password);
    }
    else {
      cout << "Sukses: User " << username << " berhasil terdaftar!" << '\n';
      this->users[userCount] = new AdminUser(username, password);
    }
    this->userCount += 1;
  }
}
/* Mendaftarkan user baru sebagai RegularUser atau AdminUser.
* Input:
* - username: Nama pengguna yang ingin didaftarkan.
* - password: Kata sandi untuk pengguna.
* - isAdmin: Jika true, user akan dibuat sebagai AdminUser, jika false sebagai User biasa.
*
* Output:
* - "Gagal: Kapasitas user penuh!" jika jumlah user telah mencapai batas maksimum.
* - "Gagal: Username sudah digunakan!" jika username sudah terdaftar dalam sistem.
* - "Sukses: User <username> berhasil terdaftar!" jika pendaftaran berhasil.
*      *<username> diganti dengan nama pengguna yang baru terdaftar.
*/

void Authenticator::login(const string &username, const string &password) {
  for(int i = 0; i < userCount; i++) {
    if(this->users[i]->getUsername() == username & this->users[i]->checkPassword(password)) {
      cout << "Sukses: Login berhasil! Selamat datang, " << username << "." << '\n';
      this->currentUser = this->users[i];
      return;
    }
  }
  cout << "Gagal: Username atau password salah!" << '\n';
}
/* Mencoba login dengan username dan password yang diberikan.
* Input:
* - username: Nama pengguna yang ingin login.
* - password: Kata sandi pengguna yang ingin login.
*
* Output:
* - "Gagal: Username atau password salah!" jika kombinasi username dan password tidak ditemukan.
* - "Sukses: Login berhasil! Selamat datang, <username>." jika login berhasil.
*      *<username> diganti dengan nama pengguna yang berhasil login.
*/

void Authenticator::logout() {
  if(currentUser != nullptr) {
    cout << "Sukses: User " << currentUser->getUsername() << " telah logout." << '\n';
    currentUser = nullptr;
  }
  else {
    cout << "Gagal: Tidak ada user yang sedang login!" << '\n';
  }
}
/* Melakukan logout dari sesi yang sedang berjalan.
*
* Output:
* - "Gagal: Tidak ada user yang sedang login!" jika tidak ada user yang sedang login.
* - "Sukses: User <username> telah logout." jika logout berhasil.
*      *<username> diganti dengan nama pengguna yang logout.
*/

void Authenticator::accessResource() const {
  if(currentUser == nullptr) {
    cout << "Akses ditolak! Silakan login terlebih dahulu." << '\n';
  }
  else {
    cout << "Resource: " << this->secretResource << '\n';
  }
}
/* Menampilkan resource rahasia jika user sudah login.
*
* Output:
* - "Akses ditolak! Silakan login terlebih dahulu." jika tidak ada user yang login.
* - "Resource: <secretResource>" jika user sedang login.
*      *<secretResource> diganti dengan resource rahasia saat ini.
*/

void Authenticator::setResource(const string &newResource) {
  if(currentUser == nullptr) {
    cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." << '\n';
  }
  else if (!currentUser->isAdmin()) {
    cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." << '\n';
  }
  else {
    cout << "Sukses: Resource telah diperbarui oleh " << currentUser->getUsername() << "." << '\n';
    this->secretResource = newResource;
  }
}
/* Mengubah resource rahasia (hanya AdminUser yang dapat melakukannya).
* Input:
* - newResource: Resource baru yang akan disimpan.
*
* Output:
* - "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." jika tidak ada user yang login.
* - "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." jika user yang login bukan AdminUser.
* - "Sukses: Resource telah diperbarui oleh <username>." jika resource berhasil diubah.
*      *<username> diganti dengan nama pengguna admin yang melakukan perubahan.
*/

Authenticator::~Authenticator() {
  for (int i = 0; i < userCount; i++) {
    delete users[i];
  }
}