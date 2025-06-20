import java.io.*;
import java.util.*;

public class Enclosure {
    private ArrayList<Animal> animals;

    public Enclosure() {
        this.animals = new ArrayList<Animal>();
    } 

    public int getAnimalCount() {
        return animals.size();
    }

    public void addAnimal(Animal animal) {
        animals.add(animal);
    }

    public Animal getAnimalAt(int i) {
        if (i < animals.size()) return animals.get(i);
        return null;
    }

    public void removeAnimalAt(int i) {
        animals.remove(i);
    }

    public boolean isEmpty() {
        return animals.isEmpty();
    }

    public void describe() {
        if (isEmpty()){
            System.out.println("Kandang ini kosong...");
            return;
        }
        
        System.out.println("Kandang berisi " + getAnimalCount() + " ekor hewan:");
        for (int i = 0; i < animals.size(); i++){
            Animal a = getAnimalAt(i);
            System.out.println((i+1) + ". " + a.getName() + ", spesies " + a.getSpecies() + ", umur " + a.getAge() + " tahun");
        }
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong menuliskan output serupa dengan output berikut:
        // Kandang berisi 2 ekor hewan:
        // 1. po, spesies Pandamus Maximus, umur 5 tahun
        // 2. po2, spesies Pandamus Maximus, umur 5 tahun
    }

    public void feed() {
        if (isEmpty()){
            System.out.println("Kandang ini kosong...");
            return;
        }
        for (int i = 0; i < animals.size(); i++){
            getAnimalAt(i).eat();
        }
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong maka akan memanggil method eat pada tiap animal dalam this.animals
    }

    public boolean safeForPetting() {
        for (int i = 0; i < animals.size(); i++){
            if (!(getAnimalAt(i).isFriendly())) return false;
        } return true;
        // mengembalikan true apabila semua hewan dalam this.animals bersifat friendly
    }
}