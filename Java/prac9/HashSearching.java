public class HashSearching {

    private static final int b = 256;
    private static final int q = Integer.MAX_VALUE;

    private static int getHash(String line){
        int res = 0;
        for (int i = 0; i < line.length(); i++){
            res = (b * res + getUnicodeFromChar(line.charAt(i))) % q;
        }
        return res;
    }

    private static int getUnicodeFromChar(char c){
        return (int) c % b;
    }

    private static String toLowerCaseCustom(String input) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);
            if (ch >= 'A' && ch <= 'Z') {
                ch = (char) (ch + ('a' - 'A'));
            }
            result.append(ch);
        }

        return result.toString();
    }

    private static boolean checkCollision(String word1, String word2){
        if (word1.length() != word2.length()) return false;
        for (int i = 0; i < word1.length(); i++){
            if (word1.charAt(i) != word2.charAt(i)) return false;
        }
        return true;
    }

    private static int findInText(String inputText, String target){
        inputText = toLowerCaseCustom(inputText);
        target = toLowerCaseCustom(target);

        int textSize = inputText.length();
        int targetSize = target.length();

        if (textSize < targetSize) return -1;

        int hashCoefficient = 1;
        for (int i = 1; i < targetSize; i++){
            hashCoefficient = (hashCoefficient * b) % q;
        }

        int targetHash = getHash(target);
        int slideWindowHash = getHash(inputText.substring(0, targetSize));

        for (int i = 0; i < (textSize - targetSize + 1); i++){
            if (slideWindowHash == targetHash){
                String slideWindowWord = inputText.substring(i, i + targetSize);
                if (checkCollision(slideWindowWord, target)){
                    return i;
                }
            }
            if (i < textSize - targetSize){
                slideWindowHash = ((slideWindowHash - getUnicodeFromChar(inputText.charAt(i)) * hashCoefficient) * b + getUnicodeFromChar(inputText.charAt(i + targetSize))) % q;
                if (slideWindowHash < 0) {
                    slideWindowHash += q;
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        String inputText = "TextForSearching";
        String target = "for";

        System.out.printf("Индекс вхождения строки: " + findInText(inputText, target));
    }

}
