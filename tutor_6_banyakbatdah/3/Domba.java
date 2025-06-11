public class Domba implements Kelas {
    // Menampilkan pesan
    //      "Moooooo"
    @Override 
    public void serang(Karakter self, Karakter target) {
        System.out.println("Moooooo");
    }

    // Menampilkan pesan
    //     "Mbeeeeeeekk"
    @Override 
    public void gunakanKemampuan(Karakter self, Karakter target) {
        System.out.println("Mbeeeeeeekk");
    }

    // Menampilkan pesan
    //      "Mbeeekkk mbeeekkk mbeeekkk"
    @Override 
    public void gunakanUltimate(Karakter self, Karakter target) {
        System.out.println("Mbeeekkk mbeeekkk mbeeekkk");
    }
}
