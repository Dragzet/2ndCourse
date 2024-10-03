public class Main {

    public static class CustomList{
        private int[] array;
        private int capacity;
        private int len;

        public CustomList(int size) {
            if (size <= 0){
                throw new IndexOutOfBoundsException("Длина должна быть больше 0.");
            }
            this.array = new int[size];
            this.capacity = size;
            this.len = 0;
        }

        public void set(int index, int target){
            if (index < 0 || index >= this.len) {
                throw new IndexOutOfBoundsException("Индекс вне границ массива.");
            }
            this.array[index] = target;
        }

        public int length() {
            return len;
        }

        public void append(int value) {
            if (len==capacity){
                throw new IndexOutOfBoundsException("Массив полон.");
            }
            this.array[this.len] = value;
            this.len++;
        }

        private int fib(int n) {
            if (n == 0) {
                return 0;
            } else if (n == 1) {
                return 1;
            }

            int a = 0, b = 1;
            for (int i = 2; i < n; i++) {
                int temp = a + b;
                a = b;
                b = temp;
            }
            return b;
        }

        public int get(int target){
            if (target >= this.len || target < 0){
                throw new IndexOutOfBoundsException("Индекс вне границ массива.");
            }
            return fib(array[target]);
        }

        public void remove(int index) {
            if (index < 0 || index >= this.len) {
                throw new IndexOutOfBoundsException("Индекс вне границ массива.");
            }

            for (int i = index; i < this.len - 1; i++) {
                array[i] = array[i + 1];
            }
            this.len--;
            array[this.len] = 0;
        }
    }

    public static void main(String[] args) {
        CustomList customList = new CustomList(5);

        customList.append(3);
        customList.append(4);
        customList.append(5);
        customList.append(6);
        customList.append(12);
        customList.set(0,10);

        System.out.println("Число Фибоначчи для значения на индексе 0: " + customList.get(0));
        System.out.println("Число Фибоначчи для значения на индексе 1: " + customList.get(1));
        System.out.println("Число Фибоначчи для значения на индексе 4: " + customList.get(4));

        customList.remove(1);

        System.out.println("Длина массива: " + customList.length());
        System.out.println("Число Фибоначчи для значения на индексе 0: " + customList.get(0));
        System.out.println("Число Фибоначчи для значения на индексе 4: " + customList.get(4)); //ошибка - наша длина 4
    }
}
