import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.Scanner;
import java.util.regex.Pattern;

public class Main{
	public static void main(String[] args) {
		formatText();
	}
    
    private static int findMaxWordLength(String text) {
    String[] words = text.split("[ ,]+");
    int max = 0;
    for (String word : words) {
        if (word.length() > max) {
            max = word.length();
        }
    }
    return max;
}


private static void formatText() {
    BufferedInputStream bf = new BufferedInputStream(System.in);
    BufferedReader r = new BufferedReader(
            new InputStreamReader(bf, StandardCharsets.UTF_8));
    String text = r.readLine();
	Scanner scanner = new Scanner(System.in);
    // String text = scanner.nextLine();
    int len = findMaxWordLength(text)*3;	
    
    String[] words = text.split("[ ]+");
    
    if (words.length==1) {
        words = text.split("[ ,]+");
        for(int i = 0; i < words.length-1; i++){
            String temp = words[i];
            words[i] = temp+",";
        }
    } else {
        //int removedIndex = 0;
        for(int i = 0; i < words.length-1; i++){
            if (Pattern.matches("\\p{Punct}", words[i+1])) {
                //String tempWord = words[i]+",";
                words[i+1] = null;
                int removedIndex = i+1;
                words[i] = words[i]+",";
            }


        }

        for (int i = removedIndex; i < words.length - 1; i++) {
            words[i] = words[i + 1];
        }

        words = Arrays.copyOf(words, words.length - 1);
    }
    


    StringBuilder formattedText = new StringBuilder();
    int index = 0;
    

    while (index < words.length) {
        StringBuilder line = new StringBuilder();
        while (index < words.length && line.length() + words[index].length() <= len) {
            if (line.length() > 0) {
                line.append(" ");
            }
            line.append(words[index]);
            index++;
        }
        formattedText.append(line).append(System.lineSeparator());
    }
    System.out.println(formattedText.toString());
}

}