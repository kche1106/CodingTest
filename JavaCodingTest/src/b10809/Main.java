package b10809;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();

        int[] res = new int[26];
        for(int i = 0; i < res.length; i++) {
            res[i] = -1;
        }

        for(int i = 0; i < s.length(); i++) {
            if(res[s.charAt(i) - 97] == -1) res[s.charAt(i) - 97] = i;
        }

        for(int i = 0; i < res.length; i++) {
            System.out.print(res[i] + " ");
        }
    }
}
