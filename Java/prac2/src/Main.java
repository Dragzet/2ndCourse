public class Main {
    public static void main(String[] args) {
        Car car1 = new Car();

        System.out.println(car1);
        System.out.println(car1.getCarAge());

        System.out.println();

        Car car2 = new Car("Toyota", 2016);

        System.out.println(car2);
        System.out.println(car2.getCarAge());

        System.out.println();

        Car car3 = new Car("Toyota", "MIREA", "BLACK", 2020);

        System.out.println(car3);
        System.out.println(car3.getCarAge());
    }
}