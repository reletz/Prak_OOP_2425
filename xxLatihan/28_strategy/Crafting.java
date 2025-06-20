import java.util.ArrayList;

// Silahkan gunakan instanceof untuk mengecek kelas dari sebuah objek

public class Crafting {
    private ArrayList<Material> materials;
    private int countStick;
    private int countIron;

    /**
     * Default constructor untuk crafting
     * Inisiasi countStick dan countIron menjadi 0
     * Inisiasi materials menjadi ArrayList baru
     */
    public Crafting() {
        countStick = 0;
        countIron = 0;
        materials = new ArrayList<>();
    }

    /**
     * Menambahkan material ke dalam list materials
     * @param m
     * Cek apakah material yang ditambahkan adalah Stick atau Iron, tambahkan countStick atau countIron
     */
    public void addMaterial(Material m) {
        if (m instanceof Stick) ++countStick; else ++countIron;
        materials.add(m);
    }

    /**
     * Menghapus stick dari list of materials sebanyak count dan memperbarui countStick. Panggil method use() dari material ketika material dihilangkan. Return void apabila countStick kurang dari count, print "Stick hanya ada x buah"
     * @param count
     */
    public void removeStick(int count) {
        if (countStick < count) {
            System.out.println("Stick hanya ada " + countStick + " buah");
            return;
        } if (count == 0) {
            return;
        }
         
        for (Material m: materials){
            if (m instanceof Stick) {
                count--;
                countStick--;
                m.use();
                materials.remove(m);
            }

            if (count == 0) return;
        }
    }

    /**
     * Menghapus Iron dari list of materials sebanyak count dan memperbarui countIron. Panggil method use() dari material ketika material dihilangkan. Return void apabila countIron kurang dari count, print "Iron hanya ada x buah"
     * @param count
     */
    public void removeIron(int count) {
        if (countIron < count) {
            System.out.println("Iron hanya ada " + countIron + " buah");
            return;
        } if (count == 0) {
            return;
        }
         
        for (Material m: materials){
            if (m instanceof Iron) {
                count--;
                countIron--;
                m.use();
                materials.remove(m);
            }

            if (count == 0) return;
        }
    }

    /**
     * Membuat sebuah Sword dengan jumlah stick, iron sesuai parameter. Sword akan memiliki damage sebesar argumen damage. Apabila material tidak cukup, lempar exception dengan pesan "Material tidak cukup". Remove Iron terlebih dahulu sebelum remove Stick
     * @param stick
     * @param iron
     * @param damage
     * @return
     * @throws IllegalStateException
     */
    public Sword craftSword(int stick, int iron, int damage) throws IllegalStateException {\
        
    }

    /**
     * Membuat sebuah Axe dengan jumlah stick, iron sesuai parameter. Axe akan memiliki damage sebesar argumen damage. Apabila material tidak cukup, lempar exception dengan pesan "Material tidak cukup". Remove Iron terlebih dahulu sebelum remove Stick
     * @param stick
     * @param iron
     * @param damage
     * @return
     * @throws IllegalStateException
     */
    public Axe craftAxe(int stick, int iron, int damage) throws IllegalStateException {

    }

    /**
     * Membuat sebuah Hoe dengan jumlah stick, iron sesuai parameter. Hoe akan memiliki durability sebesar argumen durability. Apabila material tidak cukup, lempar exception dengan pesan "Material tidak cukup". Remove Iron terlebih dahulu sebelum remove Stick
     * @param stick
     * @param iron
     * @param durability
     * @return
     * @throws IllegalStateException
     */
    public Hoe craftHoe(int stick, int iron, int durability) throws IllegalStateException {

    }
}
