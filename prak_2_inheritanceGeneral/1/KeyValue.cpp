#include <iostream>
#include <math.h>

using namespace std;

template<class T1, class T2>
class KeyValue{
  private:
    T1* keys;
    T2* values;
    int nEff;
  public:
    KeyValue(): nEff(0){
      keys = new T1[10];
      values = new T2[10];
    }

    ~KeyValue(){ delete[] keys; delete[] values; }

    KeyValue(const KeyValue& other){
      nEff = other.nEff;
      keys = new T1[10];
      values = new T2[10];
      for (int i = 0; i < nEff; i++) {
        keys[i] = other.keys[i];
        values[i] = other.values[i];
      }
    }

    void set(T1 key, T2 value){
      for (int i = 0 ; i < nEff ; i++){
        if (key == keys[i]) {
          values[i] = value;
          return;
        }
      }

      if (nEff == 10) {
        cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << '\n';
        return;
      }

      keys[nEff] = key;
      values[nEff] = value;
      nEff++;
    }

    void display(T1 key){
      for (int i = 0; i < nEff; i++) {
        if (keys[i] == key) {
          cout << values[i] << '\n';
          return;
        }
      } cout << "Key tidak ditemukan!" << '\n';
    }
};

template<class T2>
class KeyValue<double, T2>{
  private:
    double* keys;
    T2* values;
    int nEff;
  public:
    KeyValue(): nEff(0){
      keys = new double[10];
      values = new T2[10];
    }

    ~KeyValue(){ delete[] keys ; delete[] values; }

    KeyValue(const KeyValue& other){
      nEff = other.nEff;
      keys = new double[10];
      values = new T2[10];
      for (int i = 0; i < nEff; i++) {
        keys[i] = other.keys[i];
        values[i] = other.values[i];
      }
    }

    void set(double key, T2 value){
      for (int i = 0 ; i < nEff ; i++){
        if (key == keys[i] || abs(key - this->keys[i]) < 0.01) {
          values[i] = value;
          return;
        }
      }

      if (nEff == 10) {
        cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << '\n';
        return;
      }

      keys[nEff] = key;
      values[nEff] = value;
      nEff++;
    }

    void display(double key){
      for (int i = 0; i < nEff ; i++){
        if (key == keys[i] || abs(key - keys[i]) < 0.01) {
          cout << values[i] << '\n';
          return;
        }
      } cout << "Key tidak ditemukan!" << '\n';
  }
};