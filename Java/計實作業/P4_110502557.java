/**
 * Practice 04
 * Student Number: 110502557
 * Course: 2022-CE1004-A
 */

public class P4_110502557 {
    public static void main(String[] args) {
        // 以下不要改
        Pet putin = new Pet();
		Cat neko  = new Cat();
		Dog inu   = new Dog();
		newborn_Cat meow = new newborn_Cat();
		newborn_Dog woof = new newborn_Dog();
		putin.speak();
		neko.speak();
		inu.speak();
		meow.speak();
		woof.speak();
    }
}

class Pet {
    private String sentence;

    public Pet() {
        this("I'm not a pet!");
    }

    public Pet(String sentence) {
        this.sentence = sentence;
    }

    public void speak() {
        System.out.println(sentence);
    }
}

class Cat extends Pet {
    public Cat() {
        this("I'm a cat!");
    }

    public Cat(String sentence) {
        super(sentence);
    }
}

class Dog extends Pet {
    public Dog() {
        this("I'm a dog!");
    }

    public Dog(String sentence) {
        super(sentence);
    }
}

class newborn_Cat extends Cat {
    public newborn_Cat() {
        super("I can't speak but I can meow.");
    }
}

class newborn_Dog extends Dog {
    public newborn_Dog() {
        super("I can't speak but I can wolf.");
    }
}