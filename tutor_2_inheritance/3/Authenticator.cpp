#include "Authenticator.hpp"

Authenticator::Authenticator(){
  string secretResource = "Ini adalah data rahasia!";
  User* currentUser = nullptr;
  int userCount = 0;
}

void Authenticator::registerUser(const string &username, const string &password, bool isAdmin){
  if (userCount == MAX_USERS) {
    cout << "Gagal: Kapasitas user penuh!" << '\n';
    return;
  } else {
    for (int i = 0; i < userCount; i++){
      if (users[i]->getUsername() == username){
        cout << "Gagal: Username sudah digunakan!" << '\n';
        return;
      }
    }
  } User a(username, password);
  *users[userCount] = a;
  userCount++;
  cout << "Sukses: User "<< username <<" berhasil terdaftar!" << '\n';
}

void Authenticator::login(const string &username, const string &password){
  for (int i = 0; i < userCount; i++){
    if (users[i]->getUsername() == username){
      User user(*users[i]);
      if (user.checkPassword(password)){
        cout << "Sukses: Login berhasil! Selamat datang, " << username << '.\n';
        *currentUser = user;
      }
      else { 
        cout << "Gagal: Username atau password salah!" << '\n';
        return; 
      }
    } cout << "Gagal: Username atau password salah!" << '\n';
    return;  
  }
}

void Authenticator::logout(){
  if (currentUser != nullptr){
    cout << "Sukses: User " << currentUser->getUsername() << " telah logout." << '\n';
    currentUser = nullptr;
    return;
  } cout << "Gagal: Tidak ada user yang sedang login!" << '\n';
}

void Authenticator::accessResource() const{
  if (currentUser != nullptr){
    cout << "Resource: " << secretResource << '\n';
    return;
  } cout << "Akses ditolak! Silakan login terlebih dahulu." << '\n';
}

void Authenticator::setResource(const string& newResource){
  if (currentUser == nullptr) {
    cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." << '\n';
  } else if (!currentUser->isAdmin()) {
    cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." << '\n';
  } else {
    cout << "Sukses: Resource telah diperbarui oleh " << currentUser->getUsername() << ".\n";
    secretResource = newResource;
  }
}

