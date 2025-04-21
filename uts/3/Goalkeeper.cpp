#include "Goalkeeper.hpp"
using namespace std;
// class Goalkeeper : public Footballer
// {
// protected:
//   int cleanSheets;
//   int saves;
//   int totalShotsOnGoal;

// public:
  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set cleanSheets, saves, totalShotsOnGoal ke 0, playPosition ke "goalkeeper"
  // ...
  Goalkeeper::Goalkeeper(): Footballer(), cleanSheets(0), saves(0), totalShotsOnGoal(0){
    playPosition = "goalkeeper";
  }

  // User-defined constructor
  // parameter: string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal
  // set atribut dengan nilai parameter, playPosition tetap "goalkeeper"
  // nationality, height, dan weight gunakan nilai default superclass
  // ...
  Goalkeeper::Goalkeeper(string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal):
    Footballer(), cleanSheets(cleanSheets), saves(saves), totalShotsOnGoal(totalShotsOnGoal){
      this->name = name;
      this->birthYear = birthYear;
      playPosition = "goalkeeper";
    }

  // Getter dan Setter untuk cleanSheets
  // setCleanSheets(...)
  // getcleanSheets()
  void Goalkeeper::setCleanSheets(int cleanSheets){
    this->cleanSheets = cleanSheets;
  }
  int Goalkeeper::getCleanSheets(){
    return cleanSheets;
  }

  // Getter dan Setter untuk saves
  // setsaves(...)
  // getsaves()
  void Goalkeeper::setSaves(int saves){
    this->saves = saves;
  }
  int Goalkeeper::getSaves(){
    return saves;
  }

  void Goalkeeper::setTotalShotsOnGoal(int totalShotsOnGoal){
    this->totalShotsOnGoal = totalShotsOnGoal;
  }

  int Goalkeeper::getTotalShotsOnGoal(){
    return totalShotsOnGoal;
  }

  // Method tambahan: savePercentage
  // rumus: (saves / totalShotsOnGoal) * 100
  // return dalam bentuk float
  // ...

  float Goalkeeper::savePercentage(){
    if (totalShotsOnGoal == 0) return 0.0;
    return static_cast<float>(saves) / static_cast<float>(totalShotsOnGoal) * 100;
  }

  // Override transferRate:
  // rumus: (700.000 * cleanSheets) + (50.000 * saves)
  // hasil berupa int
  // ...
  int Goalkeeper::transferRate(){
    return 700000* cleanSheets + 50000 * saves;
  }

  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan goalkeeper (cleanSheets, saves, savePercentage)
  // Format:
  // Clean Sheets: <cleanSheets>
  // Saves: <saves>
  // Save Percentage: <savePercentage>%
  
  // Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
  // Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
  // ...
  void Goalkeeper::displayInfo(){
    Footballer::displayInfo();
    cout << "Clean Sheets: " << cleanSheets << endl;
    cout << "Saves: " << saves << endl;
    cout << "Save Percentage: " << fixed << setprecision(2) << savePercentage() << "%" << endl;
  }