/* Jalankan dengan 
g++ -o main 1_konsepKelas1.cpp && ./main
Uncomment part yang mau di-test
*/
#include <iostream>

using namespace std;

int main(){

/* C++ Background

- Diciptakan oleh Bjarne Stroustrup di AT&T Bell Laboratories
pada awal 1980an
- Pada mulanya dikenal sebagai ”C with Classes” (nama C++
digunakan sejak 1983, setelah diusulkan oleh Rick Mascitti).
- 1985: disebarluaskan oleh AT&T, perangkat lunak cfront (C++
translator).
*/

// Perbedaan dengan C

// Typecasting di C++ diperlakukan sbg fungsi
// float x;
// // C:
// x = 5.0;
// printf("C: x = %d\n", (int) x);
// // C++:
// x = 5.0;
// cout << "C++: x = " << int(x) << '\n';
// Biasanya, yang berlaku di C bisa ditulis dengan C++.
//char ch[3] = "C++"; /* C: OK, C++: error */
//char ch[] = "C++"; /* OK untuk C dan C++ */

/* 
- Function name overloadig, Cth: int tambah(int x, int y) dan int tambah(int x, int y, int z)
- Operator baru seperti global scope (unary ::), class scope (binary ::), 
new, delete, member pointer selectors (->*, .*) dan kata kunci baru seperti: class, private, operator, dsb.
- Call by Reference 
*/

// Variabel Referensi
/* Adalah nama alias untuk sebuah variabel. Artinya, ia mengacu ke sebuah variabel lain
Misal kita punya x dan xr. x = 5. Kemudian, xr mengacu ke x.
x ----- 5
     ^ 
xr -|
Jika xr diubah, nilai x berubah. Sebaliknya berlaku.
Beda sama pointer!
*/
// // Cara menggunakan:
// int asli = 5;
// int &refAsli = asli;
// cout << asli << " dan " << refAsli << '\n'; //output= 5 dan 5
// refAsli = 10;
// cout << asli << " dan " << refAsli << '\n';//output= 10 dan 10

// Class
/* Menciptakan tipe data baru
Berisi operasi-operasi dan data yang akan dimiliki objek-objek yang
berasal dari kelas tsb.
- Operasi dalam bentuk method/function member biasanya public.
- Data dalam bentuk atribut/data member sebaiknya private. (Secara konsep OOP atribut seharusnya private, namun fitur
bahasa C++ mengizinkan atribut public).

Tipe izin akses: private, protected, public
private: hanya bisa diakses kelas tersebut
protected: bisa diakses kelas turunannya (akan dibahas lebih lanjut)
public: dapat diakses dengan bebas oleh objek luar

Setiap method memiliki pointer implisit this yang dideklarasikan dengan syntax (untuk kelas X) X* this
Nanti akan mengacu ke kelas tersebut sendiri

Contoh deklarasi objek dari kelas: (!!Gabisa dipake disini!!) 
Stack myStack;
Stack oprStack[10];
Stack *pts = new Stack;
Stack ns = myStack;
*/
}