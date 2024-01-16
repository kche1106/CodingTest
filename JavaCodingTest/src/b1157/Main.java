package b1157;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int arr[] = new int[26];

        Arrays.sort(arr);

        for(int i = 0; i < str.length(); i++) {
            if((str.charAt(i)) >= 'A' && str.charAt(i) <= 'Z') arr[str.charAt(i) - 'A']++;
            else arr[str.charAt(i) - 'a']++;
        }

        int max = 0;
        char ch = '?';
        for(int i = 0; i < arr.length; i++) {
            if(max < arr[i]) {
                max = arr[i];
                ch = (char) (i + 'A');
            }
            else if(arr[i] == max)
                ch = '?';
        }

        System.out.println(ch);
    }
}