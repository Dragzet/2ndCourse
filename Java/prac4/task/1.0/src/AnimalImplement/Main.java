package AnimalImplement;

public class Main {
    public static void main(String[] args) {
        Animal dog = new Dog(5, 22);
        Animal sheep = new Sheep(7, 45);

        System.out.printf("AnimalImplement.Dog's age is %s\n", dog.toHumanAge());
        System.out.printf("AnimalImplement.Sheep's age is %s\n", sheep.toHumanAge());

        dog.move();
        sheep.move();

    }
}