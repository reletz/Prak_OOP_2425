#include <iostream>
#include "999_stack.cpp"

using namespace std;

int main(){
/* 4 Sekawan
Constructor (ctor) : method khusus yang secara otomatis dipanggil pada saat penciptaan objek.
Nama konstruktor (ctor) = NamaKelas
- Untuk menciptakan array dari objek, kelas objek tersebut harus memiliki default ctor 
- Dua jenis: Default (no parameter) dan User-Defined (with parameter).

Destructor (dtor) : method khusus yang secara otomatis dipanggil pada saat pemusnahan objek.
Nama destruktor (dtor) = ~NamaKelas
- Sebuah kelas memiliki >= 0 ctor dan <= 1 dtor

Copy constructor (cctor) : konstruktor yang menciptakan objek dengan cara menduplikasi objek lain yang sudah ada
- Jika tidak dideklarasikan oleh perancang kelas, cctor akan dilakukan secara bitwise copy
- Deklarasi: X(const X&);
- Passing parameter aktual ke parameter formal secara "pass by value"
- Pemberian return value dari fungsi/method yang nilai kembaliannya bertipe kelas tersebut (bukan ptr/ref)

Satunya nyusul di nomor 3 ye

*/
/* // ini contoh deklarasinya
class Stack {
  private:
    int size;
    int topStack;
    int* data;
  public:
    Stack(); // constructor
    Stack (int); // constructor dengan ukuran stack
    Stack (const Stack&); // copy constructor
    ~Stack(); // destructor
    // ...
};
// ini contoh implementasi 
Stack::Stack() {
  size = 10; // size default stack, misalnya 10
  topStack = 0; // default top stack kosong (0)
  data = new int[size];
}

Stack::~Stack() {
  delete[] data;
}
*/

/* Jenis pemanggilan objek
Ada 4:
1. Automatic: Diciptakan dalam deklarasi objek dalam blok. Dimusnahkan ketika keluar dari blok
2. Static: Diciptakan satu kali saat program mulai. Dimusnahkan ketika program selesai
3. Free-Store: Disimpan di heap sehingga bersifat dynamic. Diciptakan dengan operator new dan
dimusnahkan dengan operator delete. Kedua operator dipanggil secara eksplisit oleh pemakai.
4. Member: sebagai anggota (atribut) dari kelas.

Contoh penggunaan (tidak perlu uncomment) 
Stack s0;  global (static) 
int reverse() {
  static Stack tStack = s0;
}
void demonstrate() {
  Stack s1;               // automatic
  Stack s2(20);           // automatic
  Stack *ptr;
  ptr = new Stack (50);   // free store object 
  while (true) {
    Stack s3;             // automatic
    // assignment dengan automatic object
    s3 = Stack(5);        // ctor Stack(5) is called
    break;
    // dtor Stack(5) is called
  } // dtor s3 is called, just before next iteration,
  or before iteration stops
  delete ptr;             // dtor *ptr is called
}

// dtor s2 is called
// dtor s1 is called
*/

/* const
Keyword const dapat diterapkan pada atribut maupun method.
- Pada atribut: nilai atribut tersebut akan tetap sepanjang waktu hidup objeknya. Pengisian nilai awal 
harus dilakukan pada saat objek tersebut diciptakan, yaitu melalui constructor initialization list.
Contoh: misal nEff const.
Stack::Stack():top(-1), nEff(10){ } <- benar
Stack::Stack():top(-1){ nEff = 10 } <- error

- Pada method: method tersebut tidak bisa mengubah (status) data member yang dimiliki oleh kelasnya.
- Pada objek: hanya boleh memanggil const method, untuk memastikan bahwa status object tidak berubah.
*/

/* static
Anggota statik adalah anggota yang "dimiliki" oleh kelas, bukan oleh objek dari kelas tersebut.
- Atribut statik dipakai bersama oleh seluruh objek dari kelas tersebut
- Method statik dipakai untuk mengakses atribut statik
- Keberadaan anggota statik (method maupun atribut) tidak bergantung pada keberadaan objek dari kelas.
- Inisialisasi harus dilakukan di luar deklarasi kelas dan di luar method.
- Method statik dapat dipanggil tanpa melalui objek dari kelas tersebut
- Method statik tidak memiliki pointer implisit this
- Atribut statik diinisialisasi tanpa perlu adanya objek dari kelas tersebut.
*/

/* friend
Pemberian hak pada fungsi/kelas untuk mengakses anggota non-public suatu kelas
cth:
class B { // kelas "pemberi izin"
  friend class A;
  friend void f (int, char *);
}

Kriteria penggunaan friend:
- Hindari penggunaan friend kecuali untuk fungsi operator
- Fungsi friend merupakan fungsi di luar kelas sehingga objek parameter aktual mungkin dilewatkan secara call-by-value
- Akibatnya operasi yang dilakukan terhadap objek bukanlah objek semula
*/

/* Nested class
Pembuatan kelas di dalam kelas
Dideklarasikan di bagian non-public
Nama scope yang digunakan untuk kelas adalah Kelas::KelasNested::, bukan hanya KelasNested::
*/
}