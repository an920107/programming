/**
 * Assignment 04
 * Student Number: 110502557
 * Course: 2022-CE1002
 */

package A4_110502557;

public class A4_110502557 {
    static public void main(String args[]){
        Archer archer = new Archer("Alex",10,100);
        Medic medic = new Medic("Justin",5,100);
        System.out.printf("弓箭手：(%s, %d, %d)%n", archer.getName(),archer.getLevel(), archer.getHealth());
        System.out.printf("醫護兵：(%s, %d, %d)%n", medic.getName(),medic.getLevel(), medic.getHealth());
        archer.Reload();
        archer.Attack();
        medic.Cure();
    }
}

class Character {
    private String name;
    private int level;
    private int health;

    public Character(String name, int level, int health) {
        this.name = name;
        this.level = level;
        this.health = health;
    }

    protected String getName() {
        return name;
    }

    protected int getLevel() {
        return level;
    }

    protected int getHealth() {
        return health;
    }
}

class Archer extends Character {
    public Archer(String name, int level, int health) {
        super(name, level, health);
    }

    public void Attack() {
        System.out.println("弓箭手: 發射弓箭");
    }

    public void Reload() {
        System.out.println("弓箭手: 填裝彈藥");
    }
}

class Medic extends Character {
    public Medic(String name, int level, int health) {
        super(name, level, health);
    }

    public void Cure() {
        System.out.println("醫護兵: 治癒中");
    }
}
