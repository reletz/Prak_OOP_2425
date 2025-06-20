public abstract class Unit {
    protected String name;
    protected int health;

    public Unit(String name, int health) {
        this.name = name;
        this.health = health;
    }

    public String getName(){
        return name;
    }

    public int getHealth(){
        return health;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setHealth(int health){
        this.health = health;
    }

    public abstract String toString();
}