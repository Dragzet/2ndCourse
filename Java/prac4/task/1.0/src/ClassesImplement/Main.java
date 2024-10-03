package ClassesImplement;

public class Main {

    public static abstract class Animal {

        private int _age;
        private int  _size;

        Animal(int age, int size){
            this._age = age;
            this._size = size;
        }

        public int get_age() {
            return _age;
        }

        public void set_age(int _age) {
            this._age = _age;
        }

        public int get_size() {
            return _size;
        }

        public void set_size(int _size) {
            this._size = _size;
        }

        public abstract int toHumanAge();


    }

    public static class Dog extends Animal implements Movable{
        Dog(int age, int size){
            super(age, size);
        }

        @Override
        public int toHumanAge(){
            return super.get_age() * 7;
        }

        @Override
        public void move(){
            System.out.println("Move the dog.");
        }
    }

    public static class Sheep extends Animal implements Movable{

        Sheep(int age, int size){
            super(age, size);
        }

        @Override
        public int toHumanAge(){
            return super.get_age() * 7;
        }

        @Override
        public void move(){
            System.out.println("Move the sheep.");
        }

    }

    public static interface Movable{
        void move();
    }


    public static void main(String[] args) {
        Dog dog = new Dog(5, 22);
        Sheep sheep = new Sheep(7, 45);

        System.out.printf("ClassesImplement.Dog's age is %s\n", dog.toHumanAge());
        System.out.printf("ClassesImplement.Sheep's age is %s\n", sheep.toHumanAge());

        dog.move();
        sheep.move();

    }
}

