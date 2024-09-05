package main;
import java.util.Scanner;

public class task2{

    static final double ROUBLES_PER_YUAN = 11.91;

    public static void main(String[] args) {
        int yuan;
        double roubles;

        Scanner scanner = new Scanner(System.in);

        System.out.println("Введите кол-во юаней: ");
        yuan = scanner.nextInt();

        System.out.println("Сумма: ");
        roubles = yuan * ROUBLES_PER_YUAN;

        System.out.print(Math.round(roubles * 100.0) / 100.0);

        int lastNum = (int)(roubles - roubles % 1) % 10;

        switch (lastNum) {
            case 0,5,6,7,8,9:
                System.out.println(" рублей");
                break;
            case 1:
                System.out.println(" рубль");
                break;
            case 2,3,4:
                System.out.println(" рубля");
                break;
        }
    }
}
