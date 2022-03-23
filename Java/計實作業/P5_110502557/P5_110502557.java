/**
 * Practice 05
 * Student Number: 110502557
 * Course: 2022-CE1004-A
 */

package P5_110502557;

import java.util.Scanner;

public class P5_110502557 {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        Enemy enemy;
        Hero hero = genHero();
        System.out.println();
        do {
            enemy = genEnemy();
            System.out.println("============");
            fight(hero, enemy);
        } while (settlementAndReplay(hero, enemy));
        System.out.println("Game Over");
    }

    private static Hero genHero() {
        Hero hero = new Hero();
        Weapon weapon = new Weapon();
        System.out.println("Please create a hero:");
        System.out.print("Name: ");
        hero.setName(scanner.next());
        System.out.print("Hp: ");
        hero.setHp(scanner.nextInt());
        System.out.print("Atk: ");
        hero.setAtk(scanner.nextInt());
        System.out.printf("%s's weapon: ", hero.getName());
        weapon.setName(scanner.next());
        System.out.printf("%s's weapon atk: ", hero.getName());
        weapon.setAtk(scanner.nextInt());
        hero.setWeapon(weapon);
        return hero;
    }

    private static Enemy genEnemy() {
        Enemy enemy = new Enemy();
        System.out.println("Please Create an enemy:");
        System.out.print("Name: ");
        enemy.setName(scanner.next());
        System.out.print("Hp: ");
        enemy.setHp(scanner.nextInt());
        System.out.print("Atk: ");
        enemy.setAtk(scanner.nextInt());
        System.out.print("Drop item: ");
        enemy.setDropItem(scanner.next());
        return enemy;
    }

    private static void fight(Hero hero, Enemy enemy) {
        int attackMode;
        System.out.printf("A wild %s appeared!\n", enemy.getName());
        System.out.printf("What will %s do?\n", enemy.getName());
        while (hero.getHp() > 0) {
            System.out.printf("%s's hp: %d\n", hero.getName(), hero.getHp());
            System.out.printf("%s's hp: %d\n", enemy.getName(), enemy.getHp());
            System.out.println("1.Attack 2.Do nothing");
            attackMode = scanner.nextInt();
            switch (attackMode) {
                case 1:
                    System.out.printf("%s use %s and hurt %s %d points.\n",
                        hero.getName(), hero.getWeapon().getName(), enemy.getName(), hero.getWeapon().getAtk() + hero.getAtk());
                    enemy.setHp(enemy.getHp() - hero.getWeapon().getAtk() - hero.getAtk());
                    break;
                case 2:
                    System.out.printf("%s is doing nothing.\n", hero.getName());
                    break;
                default: break;
            }
            if (enemy.getHp() <= 0) break;
            hero.setHp(hero.getHp() - enemy.getAtk());
        }
    }

    private static boolean settlementAndReplay(Hero hero, Enemy enemy) {
        if (enemy.getHp() <= 0) {
            System.out.printf("%s win!\n", hero.getName());
            System.out.printf("%s dropped item \"%s\" left on the ground.\n", enemy.getName(), enemy.getDropItem());
            System.out.println("Want another adventure?");
            System.out.println("1. Yes 2. No");
            return scanner.nextInt() == 1 ? true : false;
        }
        else {
            System.out.printf("%s win!\n", enemy.getName());
            System.out.printf("%s's weapon \"s\" left on the ground.\n", hero.getName(), hero.getWeapon().getName());
            return false;
        }
    }
}

class Weapon {
    private String name;
    private int atk;

    public Weapon() {}
    public Weapon(String name, int atk) {
        this.name = name;
        this.atk = atk;
    }

    public void setName(String name) { this.name = name; }
    public void setAtk(int atk) { this.atk = atk; }
    public String getName() { return name; }
    public int getAtk() { return atk; }
}

class Character {
    private String name;
    private int hp;
    private int atk;

    protected Character() {}
    protected Character(String name, int hp, int atk) {
        this.name = name;
        this.hp = hp;
        this.atk = atk;
    }

    protected void setName(String name) { this.name = name; }
    protected void setHp(int hp) { this.hp = hp; }
    protected void setAtk(int atk) { this.atk = atk; }
    protected String getName() { return name; }
    protected int getHp() { return hp; }
    protected int getAtk() { return atk; }
}

class Hero extends Character {
    private Weapon weapon;

    public Hero() {}
    public Hero(String name, int hp, int atk, Weapon weapon) {
        super(name, hp, atk);
        this.weapon = weapon;
    }

    public void setName(String name) { super.setName(name); }
    public void setHp(int hp) { super.setHp(hp); }
    public void setAtk(int atk) {super.setAtk(atk); }
    public void setWeapon(Weapon weapon) { this.weapon = weapon; }
    public String getName() { return super.getName(); }
    public int getHp() { return super.getHp(); }
    public int getAtk() { return super.getAtk(); }
    public Weapon getWeapon() { return weapon; }
}

class Enemy extends Character {
    private String dropItem;

    public Enemy() {}
    public Enemy(String name, int hp, int atk, String dropItem) {
        super(name, hp, atk);
        this.dropItem = dropItem;
    }

    public void setName(String name) { super.setName(name); }
    public void setHp(int hp) { super.setHp(hp); }
    public void setAtk(int atk) {super.setAtk(atk); }
    public void setDropItem(String dropItem) { this.dropItem = dropItem; }
    public String getName() { return super.getName(); }
    public int getHp() { return super.getHp(); }
    public int getAtk() { return super.getAtk(); }
    public String getDropItem() { return dropItem; }
}
