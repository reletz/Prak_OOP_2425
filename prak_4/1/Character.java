public class Character extends Unit implements Damageable {
    private int score = 0;

    public Character(){
        super("Player1",100);
        score = 0;
    }

    public Character(String name, int health, int score) {
        super(name, health);
        this.score = score;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score){
        this.score = score;
    }

    public void takeDamage(int health) {
        this.health -= health;
        if (this.health <= 0) {
            System.out.print(name);
            System.out.println(" has been defeated");
        }
    }

    public void increaseScore(int points){
        score += points;
    }

    public String toString(){
        String result = name;
        result += " [Health: ";
        result += health;
        result += ", Score: ";
        result += score;
        result += "]";
        return result;
    }
}