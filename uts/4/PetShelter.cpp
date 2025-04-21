#include "PetShelter.hpp"
using namespace std;

template <typename T>
PetShelter<T>::PetShelter(string shelterName) : 
    shelterName(shelterName), dogCapacity(8), catCapacity(12),
    petCount(0), currentCats(0), currentDogs(0) {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        pets[i] = nullptr;
    }
}
/* Default constructor:
    * - Creates a shelter with the given name.
    * - Default capacity: 8 dogs, 12 cats.
    * - No pets in the shelter initially.
    */

template <typename T>
PetShelter<T>::PetShelter(string shelterName, int dogCapacity, int catCapacity) : 
    shelterName(shelterName), dogCapacity(dogCapacity), catCapacity(catCapacity),
    petCount(0), currentCats(0), currentDogs(0){
    if (dogCapacity + catCapacity > MAX_SHELTER_CAPACITY) {
        cout << "The total capacity you construct is " << dogCapacity + catCapacity << ", meanwhile the shelter capacity is 20" << endl;
    }

    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        pets[i] = nullptr;
    }
}
/* Constructor with specified capacities:
    * - Creates a shelter with custom capacities for dogs and cats.
    * - If total capacity exceeds MAX_SHELTER_CAPACITY, prints:
    *   "The total capacity you construct is <total>, meanwhile the shelter capacity is 20"
    */

template <typename T>
PetShelter<T>::~PetShelter() {
    //delete[] pets;
}
/* Destructor:
    * - Cleans up all dynamically allocated pets.
    * - Sets pet pointers to nullptr after deletion.
    */

template <typename T>
string PetShelter<T>::getShelterName() const {
    return this->shelterName;
}
/* Returns the name of the shelter.
    * Output: Shelter name as a string.
    */

template <typename T>
void PetShelter<T>::addPet(const string &petName, int age, bool isDog, const string &extraInfo) {
    int dc = dogCapacity;
    int cc = catCapacity;
    int curC = currentCats;
    int curD = currentDogs;
    int cur = petCount;

    if (isDog) {
        Dog* newPets = new Dog(petName, age, extraInfo);

        if (cur >= MAX_SHELTER_CAPACITY) cout << "Error: Shelter is at full capacity!" << endl;
        else if (curD >= dc) cout << "Error: No space for more dogs!" << endl;
        else {
            currentDogs++;
            petCount++;

            newPets->setId("D" + to_string(curD + 1));
            for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
                if (pets[i] == nullptr) {
                    pets[i] = newPets;
                    break;
                }
            }

            cout << "Success: " << petName << " has been added as a Dog! Pet ID: " << newPets->getId() << endl; 
        }
    }
    else {
        Cat* newPets = new Cat(petName, age, extraInfo);

        if (cur >= MAX_SHELTER_CAPACITY) cout << "Error: Shelter is at full capacity!" << endl;
        else if (curC >= cc) cout << "Error: No space for more cats!" << endl;
        else {
            currentCats++;
            petCount++;
            
            newPets->setId("C" + to_string(curC + 1));

            for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
                if (pets[i] == nullptr) {
                    pets[i] = newPets;
                    break;
                }
            }

            cout << "Success: " << petName << " has been added as a Cat! Pet ID: " << newPets->getId() << endl; 
        }
    }
}
/* Adds a pet to the shelter.
* Input:
* - petName: Name of the pet.
* - age: Age of the pet in years.
* - isDog: If true, adds a dog; if false, adds a cat.
* - extraInfo: For dogs, this is the breed; for cats, this is the color.
*
* Process:
* - If shelter is full, prints "Error: Shelter is at full capacity!".
* - If dog capacity is full, prints "Error: No space for more dogs!".
* - If cat capacity is full, prints "Error: No space for more cats!".
*
* - If addition is successful, system will create a **unique pet ID** based on pet type:
*   - If dog, ID will be "D" followed by the dog's sequential number. Ex: "D1", "D2", etc.
*   - If cat, ID will be "C" followed by the cat's sequential number. Ex: "C1", "C2", etc.
*
* - If addition is successful, prints:
*   "Success: <petName> has been added as a <Dog/Cat>! Pet ID: <petID>"
*/

template <typename T>
T* PetShelter<T>::findPet(const string &petID) const {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] == nullptr) continue; 
        if (pets[i]->getId() == petID) {
            pets[i]->displayInfo();

            return dynamic_cast<T*>(pets[i]);
        }
    }

    cout << "Pet ID is invalid!" << endl;
    return nullptr;
}
/* Checks if a pet with the given ID exists in the shelter.
    * Input:
    * - petID: ID of the pet to check.
    *
    * Output:
    * - If found, prints pet details using the displayInfo() method.
    * - If not found, prints "Pet ID is invalid!".
    * Note: Uses dynamic_cast to safely convert from Pet* to T* when returning.
    */

template <typename T>
void PetShelter<T>::listAllPets() const {
    if (petCount == 0) {
        cout << "No pets in the shelter yet!" << endl;
        return;
    }

    int counter = 0;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] == nullptr) continue;
        cout << ++counter << ". " ;
        pets[i]->displayInfo();
    }
}
/* Displays a list of all pets in the shelter.
    * Output:
    * - If no pets in the shelter, prints "No pets in the shelter yet!".
    * - If pets exist, prints in the format:
    *   "<number>. <pet.displayInfo()>"
    *
    * - Numbering in output starts from 1.
    */

template <typename T>
int PetShelter<T>::calculateCost() const {
    int cost = 0;

    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] == nullptr) continue;

        if (dynamic_cast<Dog*>(pets[i])) { cost += 75; }
        else if (dynamic_cast<Cat*>(pets[i])) { cost += 60; }
    }

    return cost;
}
/* Calculates total cost of maintaining all pets in the shelter.
    * - Dogs cost 75 per day.
    * - Cats cost 60 per day.
    * 
    * Output: Total daily maintenance cost as an integer.
    * Note: Uses dynamic_cast to determine the type of pet (Dog or Cat) 
    * to apply the correct maintenance cost.
    * Example:
    *   if (dynamic_cast<Dog*>(pets[i])) { cost += 75; }
    *   else if (dynamic_cast<Cat*>(pets[i])) { cost += 60; }
    */

template <typename T>
void PetShelter<T>::removePet(const string &petID) {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] == nullptr) continue; 
        if (pets[i]->getId() == petID) {
            cout << pets[i]->getName() << " has been removed from the shelter." << endl;

            if (dynamic_cast<Dog*>(pets[i])) { currentDogs--; }
            else if (dynamic_cast<Cat*>(pets[i])) { currentCats--; }
            petCount--;

            pets[i] = nullptr;
            return;
        }
    }

    cout << "Pet ID is invalid!" << endl;
}

template class PetShelter<Pet>;