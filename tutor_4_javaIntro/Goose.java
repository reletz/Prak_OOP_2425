public class Goose {
    private String name;
    private int honk;

    public Goose() {
        this.name = "Horrible";
        this.honk = 1;
    }

    public Goose(String name, int honk) {
        this.name = name;
        this.honk = honk;
    }

    public void steal (String thing){
        System.out.println(this.name + " steals " + thing);
    }

    public String toString () {
        String blabla = new String();
        blabla += this.name;
        blabla += " goose says";
        for (int i = 0; i < this.honk; i++){
            blabla += " honk";
        } return blabla;
    }

    public static void main(String[] args) {
        Goose g = new Goose();
        Goose h = new Goose("Sung Jin-woo", 3);
        System.out.println(g);
        System.out.println(h);
        h.steal("dagger");
    }
}