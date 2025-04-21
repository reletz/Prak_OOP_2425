// #ifndef STRIKER_HPP
// #define STRIKER_HPP

#include "Striker.hpp"
using namespace std;
// class Striker : public Footballer
// {
// protected:
//   // atribut tambahan goalScore (jumlah gol yang dicetak striker)
//   // dan shotsOnTarget (jumlah tendangan tepat sasaran)
//   // ...
//   int goalScore; //(jumlah tackle sukses)
//   int shotsOnTarget; // (jumlah intercept)

// public:
  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set goalScore dan shotsOnTarget ke 0, dan playPosition ke "striker"
  // ...
  Striker::Striker(): Footballer(), goalScore(0), shotsOnTarget(0){
    playPosition = "striker";
  }

  // User-defined constructor
  // parameter: string name, int birthYear, int goalScore, int shotsOnTarget
  // set atribut dengan nilai parameter, playPosition tetap "striker"
  // nationality, height, dan weight gunakan nilai default superclass
  // ...
  Striker::Striker(string name, int birthYear, int goalScore, int shotsOnTarget): 
  Footballer(), goalScore(goalScore), shotsOnTarget(shotsOnTarget){
    playPosition = "striker";
    this->name = name;
    this->birthYear = birthYear;
  }
  
  // Getter dan Setter untuk goalScore
  // setGoalScore(...)
  // getGoalScore()
  void Striker::setGoalScore(int goalScore){
    this->goalScore = goalScore;
  }

  int Striker::getGoalScore(){
    return goalScore;
  }

  // Getter dan Setter untuk shotsOnTarget
  // setShotsOnTarget(...)
  // getShotsOnTarget()
  void Striker::setShotsOnTarget(int shotsOnTarget){
    this->shotsOnTarget = shotsOnTarget;
  }

  int Striker::getShotsOnTarget(){
    return shotsOnTarget;
  }


  // Method tambahan: menghitung conversion rate dalam persen
  // conversionRate() = (goalScore / shotsOnTarget) * 100
  // return dalam bentuk float
  // Hint: Gunakan static_cast<float> untuk mengonversi int ke float
  // ...
  float Striker::conversionRate(){
    if (shotsOnTarget == 0) return 0.0;
    return static_cast<float>(goalScore) /  static_cast<float>(shotsOnTarget) * 100;
  }

  // Override transferRate:
  // rumus: 1.000.000 * goalScore + 10.000 * conversionRate()
  // hasil berupa int
  // ...
  int Striker::transferRate(){
    return 1000000*goalScore + 10000*conversionRate();
  }

  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan striker (goalScore, conversionRate)
  // Format:
  // Goals: <goalScore>
  // Conversion Rate: <conversionRate>%

  // Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
  // Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
  // ...
  void Striker::displayInfo(){
    Footballer::displayInfo();
    cout << "Goals: " << getGoalScore() << endl;
    cout << "Conversion Rate: " << fixed << setprecision(2) << conversionRate() << "%" << endl;
  }
