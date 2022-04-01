package stu_110502557;

import java.util.Scanner;
import java.util.Stack;

public class E1 {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int command;
        float multiply;
        while (true) {
            command = scanner.nextInt();
            if (command != 1) break;

            Pokemon enemy = new Pokemon(scanner.nextFloat(), scanner.nextFloat(), scanner.nextFloat());
            enemy.setAttributes(Pokemon.Attributes.FIRE);

            Pokemon templatePokemon = new Pokemon(scanner.nextFloat(), scanner.nextFloat(), scanner.nextFloat());
            Stack<Pokemon> pokemons = new Stack<>();
            int[] orders = new int[3];
            for (int i = 0; i < 3; i ++) {
                orders[i] = scanner.nextInt();
            }
            for (int i = 2; i >= 0; i --) {
                pokemons.add(new Pokemon(templatePokemon));
                pokemons.lastElement().setAttributes(orders[i]);
            }

            int rounds = 0;
            while (true) {

                // ta's turn
                rounds ++;
                
                switch (pokemons.lastElement().getAttributes()) {
                    case Pokemon.Attributes.GRASS:
                        multiply = 1.5f;
                        break;
                    case Pokemon.Attributes.WATER:
                        multiply = 0.5f;
                        break;
                    default:
                        multiply = 1;
                        break;
                }

                pokemons.lastElement().lossHp(enemy.canSpecialAttack() ? enemy.getSpc() * multiply : enemy.getAtk());
                enemy.addHp((enemy.canSpecialAttack() ? enemy.getSpc() * multiply : enemy.getAtk()) * 0.2f);
                enemy.addPower(0.25f);

                if (pokemons.lastElement().getHp() <= 0f) {
                    pokemons.pop();
                    if (pokemons.isEmpty()) break;
                }

                // my turn

                rounds ++;

                switch (pokemons.lastElement().getAttributes()) {
                    case Pokemon.Attributes.GRASS:
                        multiply = 0.5f;
                        break;
                    case Pokemon.Attributes.WATER:
                        multiply = 1.5f;
                        break;
                    default:
                        multiply = 1;
                        break;
                }

                enemy.lossHp(pokemons.lastElement().canSpecialAttack() ? pokemons.lastElement().getSpc() * multiply : pokemons.lastElement().getAtk());
                pokemons.lastElement().addPower(0.25f);

                if (enemy.getHp() <= 0f) break;
            }

            if (pokemons.isEmpty()) {
                System.out.printf("You Lose! Using %d rounds!\n", rounds);
            }
            else {
                System.out.printf("You Win! Using %d rounds!\n", rounds);
            }
        }
    }
}

class Pokemon {
    public static class Attributes {
        final public static int GRASS = 1;
        final public static int FIRE = 2;
        final public static int WATER = 3;
    }

    private float hp;
    private float atk;
    private float power;
    private float spc;
    private float originalHp;
    private int attributes;

    public Pokemon(Pokemon pokemon) {
        this.hp = pokemon.hp;
        this.atk = pokemon.atk;
        this.power = pokemon.power;
        this.originalHp = hp;
    }

    public Pokemon(float hp, float atk, float power) {
        this.hp = hp;
        this.atk = atk;
        this.power = power;
        this.originalHp = hp;
        spc = 1;
    }

    public float getHp() { return hp; }
    public float getAtk() { return atk; }
    public float getPower() { return power; }
    public float getSpc() { return spc; }
    public int getAttributes() { return attributes; }

    public void setAttributes(int attributes) {
        switch (attributes) {
            case Attributes.GRASS:
                spc = atk;    
                hp *= 1.2f;
                break;
            case Attributes.FIRE:
                spc = atk * 1.1f;
                hp *= 0.8f;
                atk *= 1.2f;
                break;
            case Attributes.WATER:
                spc *= atk * 1.7f;
                hp *= 0.9f;
                atk *= 0.9f;
                break;
            default: break;
        }
        this.attributes = attributes;
    }

    public void addHp(float adding) {
        hp += adding;
        if (hp > originalHp) hp = originalHp;
    }

    public void lossHp(float hurt) {
        hp -= hurt;
    }

    public void addPower(float acc) {
        if (power >= 1f) {
            power = 0f;
            return;
        }
        power += acc;
    }

    public boolean canSpecialAttack() {
        return power >= 1f;
    }
    
    public void printInformation() {
        System.out.printf("Hp: %f, Atk: %f, Power: %f\n", hp, atk, power);
    }
}
