package app;

import vehicle.Car;
import vehicle.ElectricCar;

public class Main {

    public static void main(String[] args) {

        Car car = new Car("Kharitonov", "TYPE123", "ICE");

        System.out.println(car);
        System.out.println();

        // System.out.println(car.engineType); <- Ошибка
        System.out.println(car.getEngineType());
        System.out.println(car.getOwnerName());
        System.out.println(car.getInsuranceNumber());
        System.out.println();

        ElectricCar electricCar = new ElectricCar("Arseniy", "ELECTRICTYPE123", 10);

        System.out.println(electricCar);
        System.out.println();

        System.out.println(electricCar.getEngineType());
        System.out.println(electricCar.getBatteryCapacity());
        System.out.println(electricCar.getOwnerName());
        System.out.println(electricCar.getInsuranceNumber());
    }
}
