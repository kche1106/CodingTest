package s10828;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];

        int top = 0;
        for(int i = 0; i < n; i++) {
            String cmd = sc.next();

            if(cmd.equals("push")) {
                int cmd_num = sc.nextInt();
                arr[top++] = cmd_num;
            } else if(cmd.equals("pop")) {
                if(top == 0) System.out.println("-1");
                else {
                    System.out.println(arr[--top]);
                    arr[top] = 0;
                }
            } else if (cmd.equals("size")) {
                System.out.println(top);
            } else if (cmd.equals("empty")) {
                if(top == 0) System.out.println("1");
                else System.out.println("0");
            } else if(cmd.equals("top")) {
                if(top == 0) System.out.println("-1");
                else System.out.println(arr[top - 1]);
            }
        }
    }
}
