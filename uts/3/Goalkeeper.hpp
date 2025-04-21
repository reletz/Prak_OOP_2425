#ifndef GOALKEEPER_HPP
#define GOALKEEPER_HPP

#include "Footballer.hpp"

class Goalkeeper : public Footballer
{
protected:
  int cleanSheets; //(jumlah tackle sukses)
  int saves; // (jumlah intercept)
  int totalShotsOnGoal;

public:
  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set cleanSheets, saves, totalShotsOnGoal ke 0, playPosition ke "goalkeeper"
  // ...
  Goalkeeper();

  // User-defined constructor
  // parameter: string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal
  // set atribut dengan nilai parameter, playPosition tetap "goalkeeper"
  // nationality, height, dan weight gunakan nilai default superclass
  // ...
  Goalkeeper(string, int, int, int, int);

  // Getter dan Setter untuk cleanSheets
  // setCleanSheets(...)
  // getcleanSheets()
  void setCleanSheets(int);
  int getCleanSheets();

  // Getter dan Setter untuk saves
  // setsaves(...)
  // getsaves()
  void setSaves(int);
  int getSaves();

  void setTotalShotsOnGoal(int);
  int getTotalShotsOnGoal();

  // Method tambahan: savePercentage
  // rumus: (saves / totalShotsOnGoal) * 100
  // return dalam bentuk float
  // ...

  float savePercentage();

  // Override transferRate:
  // rumus: (700.000 * cleanSheets) + (50.000 * saves)
  // hasil berupa int
  // ...
  int transferRate() override;

  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan goalkeeper (cleanSheets, saves, savePercentage)
  // Format:
  // Clean Sheets: <cleanSheets>
  // Saves: <saves>
  // Save Percentage: <savePercentage>%
  
  // Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
  // Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
  // ...
  void displayInfo();
};

#endif
