#include "Gradebook.hpp"
// #ifndef GRADEBOOK_HPP
// #define GRADEBOOK_HPP

// #include <string>
// #include <map>
// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;

// class Gradebook
// {
// private:
//     // Struktur data utama: memetakan nama mahasiswa (string) ke nilai (double)
//     map<string, double> studentGrades;

// public:
    /*
     * Menambah atau mengupdate nilai mahasiswa.
     * Jika mahasiswa sudah ada, nilainya akan diupdate.
     * Jika mahasiswa belum ada, akan ditambahkan dengan nilai yang diberikan.
     */
    void Gradebook::addOrUpdateStudent(const string &studentName, double grade) {
        studentGrades[studentName] = grade;
    }

    /*
     * Menghapus mahasiswa dari gradebook.
     * Mengembalikan true jika mahasiswa ditemukan dan berhasil dihapus,
     * false jika tidak ditemukan.
     */
    bool Gradebook::removeStudent(const string &studentName) {
        if (studentExists(studentName)) {
            studentGrades.erase(studentGrades.find(studentName));
            return true;
        }
        else {
            return false;
        }
    }

    /*
     * Mengambil nilai dari mahasiswa tertentu.
     * Mengembalikan true jika mahasiswa ditemukan dan nilainya disimpan
     * di parameter 'grade', false jika mahasiswa tidak ditemukan.
     */
    bool Gradebook::getGrade(const string &studentName, double &grade) const {
        if (studentExists(studentName)) {
            grade = studentGrades.at(studentName);
            return true;
        }
        else {
            return false;
        }
    }

    /*
     * Memeriksa apakah mahasiswa ada dalam gradebook.
     * Mengembalikan true jika mahasiswa ada, false jika tidak.
     */
    bool Gradebook::studentExists(const string &studentName) const {
        return studentGrades.find(studentName) != studentGrades.end();
    }

    /*
     * Mencetak semua nama mahasiswa dan nilai mereka
     * Jika gradebook kosong, akan mencetak pesan "Gradebook kosong\n"
     * Format:
     * 1. <nama_mahasiswa>: <nilai>
     * 2. <nama_mahasiswa>: <nilai>
     * ...
     */
    void Gradebook::printGrades() const {
        if (studentGrades.empty()) {
            cout << "Gradebook kosong\n";
            return;
        }
    
        int idx = 1;
        for (auto it = studentGrades.begin(); it != studentGrades.end(); it++) {
            cout << idx << ". " << it->first << ": " << it->second << endl; 
            idx++;
        }
    }

    /*
     * Mencetak semua nama mahasiswa dan nilai mereka, terurut berdasarkan nilai terbesar ke terkecil.
     * Hint: gunakan vector<pair<string, double>> untuk menyimpan semua data mahasiswa untuk memudahkan pengurutan. Gunakan fungsi bantuan untuk komparasi pada std::sort.
     * Format:
     * 1. <nama_mahasiswa>: <nilai>
     * 2. <nama_mahasiswa>: <nilai>
     * ...
     */
    bool comp(pair<string, double> a, pair<string, double> b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
    
    void Gradebook::printGradesRank() const {
        vector<pair<string, double>> v;
        for (auto it = studentGrades.begin(); it != studentGrades.end(); it++) {
            v.push_back(*it);
        }
    
        sort(v.begin(), v.end(), comp);
    
        for (int idx = 0; idx < v.size(); idx++) {
            cout << idx+1 << ". " << v[idx].first << ": " << v[idx].second << endl;
        }
    }

    /*
     * Mengembalikan daftar nama mahasiswa yang nilainya di atas threshold tertentu.
     * Mengembalikan vector berisi nama mahasiswa dengan nilai lebih besar dari threshold,
     * terurut berdasarkan abjad.
     */
    vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const {
        vector<string> ans;
    
        for (auto it = studentGrades.begin(); it != studentGrades.end(); it++) {
            if (it->second > threshold) {
                ans.push_back(it->first);
            }
        }
    
        sort(ans.begin(), ans.end());
    
        return ans;
    }

    /*
     * Menghitung rata-rata nilai semua mahasiswa dalam gradebook.
     * Mengembalikan rata-rata nilai, atau 0.0 jika gradebook kosong.
     */
    double Gradebook::getAverageGrade() const{
        if (studentGrades.empty()) {
            return 0.0;
        }

        double sum = 0;
        for (auto it = studentGrades.begin(); it != studentGrades.end(); ++it){
            sum += it->second;
        } return sum/getNumberOfStudents();
    }

    /*
     * Mengembalikan jumlah mahasiswa yang ada dalam gradebook.
     */
    size_t Gradebook::getNumberOfStudents() const{
        return studentGrades.size();
    }