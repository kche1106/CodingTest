package s10828;

import java.util.Scanner;

public class SBMain {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int n = in.nextInt();
        int[] arr = new int[n];

        int top = 0;
        for(int i = 0; i < n; i++) {
            String cmd = in.next();

            if(cmd.equals("push")) {
                int cmd_num = in.nextInt();
                arr[top++] = cmd_num;
            } else if(cmd.equals("pop")) {
                if(top == 0) sb.append("-1").append('\n');
                else {
                    sb.append(arr[--top]).append('\n');
                    arr[top] = 0;
                }
            } else if (cmd.equals("size")) {
                sb.append(top).append('\n');
            } else if (cmd.equals("empty")) {
                if(top == 0) sb.append("1").append('\n');
                else sb.append("0").append('\n');
            } else if(cmd.equals("top")) {
                if(top == 0) sb.append("-1").append('\n');
                else sb.append(arr[top - 1]).append('\n');
            }
        }

        System.out.println(sb);
    }
}
