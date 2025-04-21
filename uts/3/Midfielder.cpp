// #ifndef MIDFIELDER_HPP
// #define MIDFIELDER_HPP

#include "Midfielder.hpp"
using namespace std;
// class Midfielder : public Footballer
// {
// protected:
//   // atribut tambahan assist (jumlah assist) dan keyPasses (jumlah umpan kunci)
//   // ...
//   int assist; //(jumlah tackle sukses)
//   int keyPasses; // (jumlah intercept)

// public:
  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set assist dan keyPasses ke 0, dan playPosition ke "midfielder"
  // ...
  Midfielder::Midfielder(): Footballer(), assist(0), keyPasses(0){
    playPosition = "midfielder";
  }

  // User-defined constructor
  // parameter: string name, int birthYear, int assist, int keyPasses
  // set atribut dengan nilai parameter, playPosition tetap "midfielder"
  // nationality, height, dan weight gunakan nilai default superclass
  // ...
  Midfielder::Midfielder(string name, int birthYear, int assist, int keyPasses): 
  Footballer(), assist(assist), keyPasses(keyPasses){
    playPosition = "midfielder";
    this->name = name;
    this->birthYear = birthYear;
  }

  // Getter dan Setter untuk assist
  // setAssist(...)
  // getAssist()
  void Midfielder::setAssist(int assist){
    this->assist = assist;
  }

  int Midfielder::getAssist(){
    return assist;
  }

  // Getter dan Setter untuk keyPasses
  // setKeyPasses(...)
  // getKeyPasses()
  void Midfielder::setKeyPasses(int keyPasses){
    this->keyPasses = keyPasses;
  }

  int Midfielder::getKeyPasses(){
    return keyPasses;
  }
  // Method tambahan: menghitung playmakerRating
  // rumus: (assist * 3) + keyPasses
  // return dalam bentuk int
  // ...
  int Midfielder::playmakerRating(){
    return assist*3 + keyPasses;
  }

  // Override transferRate:
  // rumus: (800.000 * assist) + (30.000 * keyPasses)
  // hasil berupa int
  // ...
  int Midfielder::transferRate(){
    return 800000*assist + 30000*keyPasses;
  }

  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan midfielder (assist, keyPasses, playmakerRating)
  // Format:
  // Assists: <assist>
  // Key Passes: <keyPasses>
  // Playmaker Rating: <playmakerRating>
  void Midfielder::displayInfo(){
    Footballer::displayInfo();
    cout << "Assists: " << getAssist() << endl;
    cout << "Key Passes: " << getKeyPasses() << endl;
    cout << "Playmaker Rating: " << playmakerRating() << endl;
  }
