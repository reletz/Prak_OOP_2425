#include "Footballer.hpp"

// class Footballer
// {
// protected:
//   string name;
//   string playPosition;
//   int birthYear;

//   string nationality;
//   int height;
//   int weight;

// public:
//   // Default cosntructor set nilai attribut sebagai berikut:
  // name = "noname"; birthYear = 2000; playPosition = "none";
  // nationality = "Indonesia"; height = 180, weight = 70
  // ...
  Footballer::Footballer(){
    name = "noname";
    birthYear = 2000;
    playPosition = "none";
    nationality = "Indonesia";
    height = 180;
    weight = 70;
  }
  // User-defined constructor:
  // set nilai atribut berdasarkan nilai parameter masukan
  // dengan urutan: name, birthYear, playPosition, nationality, height, weight
  // ...
  Footballer::Footballer(string name, int birthYear, string playPosition, string nationality, int height, int weight){
    this->name = name;
    this->birthYear = birthYear;
    this->playPosition = playPosition;
    this->nationality = nationality;
    this->height = height;
    this->weight = weight;
  }

  // Copy constructor
  // ...
  Footballer::Footballer(const Footballer& other){
    this->name = other.name;
    this->birthYear = other.birthYear;
    this->playPosition = other.playPosition;
    this->nationality = other.nationality;
    this->height = other.height;
    this->weight = other.weight;
  }

  // Destructor
  // ...
  Footballer::~Footballer(){};

  // Operator assignment
  // ...
  Footballer& Footballer::operator=(const Footballer& other){
    this->name = other.name;
    this->birthYear = other.birthYear;
    this->playPosition = other.playPosition;
    this->nationality = other.nationality;
    this->height = other.height;
    this->weight = other.weight;
    return *this;
  }

  // Getter dan setter name
  // setName(...)
  // getName()
  void Footballer::setName(string name){
    this->name = name;
  }
  string Footballer::getName() const {
    return name;
  }

  // Getter dan setter playPosition
  // setPlayPosition(...)
  // getPlayPosition()
  // Footballer::Footballer(string name, int birthYear, string playPosition, string nationality, int height, int weight){
  //   this->name = name;
  //   this->birthYear = birthYear;
  //   this->playPosition = playPosition;
  //   this->nationality = nationality;
  //   this->height = height;
  //   this->weight = weight;
  // }
  void Footballer::setPlayPosition(string playPosition){
this->playPosition = playPosition;
  }
  string Footballer::getPlayPosition() const{
    return playPosition;
  }

  // Getter dan setter nationality
  // setNationality(...)
  // getNationality()
  void Footballer::setNationality(string nationality){
    this->nationality = nationality;
  }
  string Footballer::getNationality()const{
    return nationality;
  }
  

  // Getter dan setter height and weight
  // setHeight(...)
  // getHeight()
  // setWeight(...)
  // getWeight()
  void Footballer::setHeight(int height){
this->height = height;
  }
  int Footballer::getHeight() const{
    return height;
  }
  void Footballer::setWeight(int weight){
    this->weight = weight;
  }
  int Footballer::getWeight() const{
    return weight;
  }

  // gunakan CURRENT_YEAR untuk menghitung umur
  // getAge()
  int Footballer::getAge() const{
    return CURRENT_YEAR - birthYear;
  }

  // gunakan height and weight untuk menghitung BMI
  // BMI = weight(kg) / (height(m))²
  // getBMI()
  double Footballer::getBMI() const{
    return static_cast<double>(weight)/static_cast<double>(height*height/10000.0f);
  }

  // gunakan BMI untuk mendapat category
  // BMI < 18.5         -> Underweight
  // 18.5 ≤ BMI < 25.0  -> Normal
  // 25.0 ≤ BMI < 30.0  -> Overweight
  // BMI ≥ 30.0         -> Obese
  string Footballer::getCategory() const{
    double bmi = getBMI();
    if (bmi < 18.5) return "Underweight";
    else if (bmi < 25.0) return "Normal";
    else if (bmi < 30.0) return "Overweight";
    else return "Obese";
  }
  // getCategory() -> string

  // Mencetak informasi footballer dengan format sebagai berikut:
  // Name: {name}
  // Age: {hasil pemanggilan getAge()}
  // Position: {playPosition}
  // Nationality: {nationality}
  // BMI: {<BMI> (<getCategory()>)}, BMI 2 angka di belakang koma, HINT: "cout << fixed << setprecision(2);"
  void Footballer::displayInfo() const {
  // Mencetak informasi footballer dengan format sebagai berikut:
  cout << "Name: " << name << endl;
  cout << "Age: " << getAge() << endl;
  cout << "Position: "<< playPosition << endl;
  cout << "Nationality: " << nationality << endl;
  cout << "BMI: " << fixed << setprecision(2) << getBMI() <<" (" << getCategory() << ")" << endl;
  cout << "Transfer Rate: " << transferRate() << endl;
  }

  // Melakukan kalkulasi nilai transfer sesuai umur, playPosition, dan getCategory()
  // transferRate() akan diimplementasikan oleh kelas anak Footballer
  // yang ada di soal berikutnya. Gunakan tipe data integer.
  // ... transferRate()
  int Footballer::transferRate() const { return 0; }