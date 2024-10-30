public class Main {

    private static final int hashConstant = 101;

    private static long getHash(String str){
        long hash = 0;
        for (int i = 0; i < str.length(); i++){
            hash += (long) (str.charAt(i) * Math.pow(hashConstant, i));
        }
        return hash;
    }

    private static boolean checkStrings(String target, String text){
        return target.equals(text);
    }

    private static int findSubstring(String target, String inputString){
        target = target.toLowerCase();
        inputString = inputString.toLowerCase();

        if (target.length() > inputString.length()){
            return -1;
        }

        long targetHash = getHash(target);
        int targetLength = target.length();
        int result = -1;

        String slideWindow = inputString.substring(0, targetLength);

        for (int i = targetLength; i < inputString.length(); i++){
            if (getHash(slideWindow) == targetHash){
                if (checkStrings(slideWindow, target)){
                    result = i - targetLength;
                    return result;
                }
            }
            slideWindow = slideWindow.substring(1, targetLength) + inputString.charAt(i);
        }

        if (getHash(slideWindow) == targetHash){
            if (checkStrings(slideWindow, target)){
                result = inputString.length() - targetLength;
                return result;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        String inputString = "ThisStringForSearch";
        String targetSub = "for";

        System.out.printf("Индекс вхождение подстроки: " + findSubstring(targetSub, inputString));

    }

}
