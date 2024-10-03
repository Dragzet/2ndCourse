package task2;

// 2 Вариант

public class Main {

    public static void main(String[] args) {
        Calculator calc = new Calculator();

        int a = -15;
        int b = 4;

        System.out.printf("%d + %d = %d\n",a, b ,calc.add(a, b));
        System.out.printf("%d - %d = %d\n",a, b, calc.substract(a, b));
        System.out.printf("%d * %d = %d\n",a, b, calc.multiply(a, b));
        System.out.printf("%d / %d = %d\n", a, b, calc.divice(a, b));
        System.out.printf("%d mod %d = %d\n", a, b, calc.ostat(a, b));
    }



}
