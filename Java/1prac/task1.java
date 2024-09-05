package main;
import java.util.Scanner;

public class task1{

    static final double ROUBLES_PER_YUAN = 11.91;

    public static void main(String[] args) {
        int yuan;
        double roubles;

        Scanner scanner = new Scanner(System.in);

        System.out.println("Введите кол-во юаней: ");
        yuan = scanner.nextInt();

        System.out.println("Сумма: ");
        roubles = yuan * ROUBLES_PER_YUAN;

        System.out.println(roubles + " руб.");
    }
}
