package g10026;

import java.util.Scanner;

public class Main {
    static int n;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int[][] map;
    static boolean[][] isvisit;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();

        map = new int[n+1][n+1];
        isvisit = new boolean[n+1][n+1];
        for(int i = 0; i < n; i++) {
            String s = in.next();
            for(int j = 0; j < n; j++) {
                map[i][j] = s.charAt(j);
            }
        }

        int res1 = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isvisit[i][j] == false) {
                    isvisit[i][j] = true;
                    dfs1(i, j);
                    res1++;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
               isvisit[i][j] = false;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(map[i][j] == 'R') map[i][j] = 'G';
            }
        }

        int res2 = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isvisit[i][j] == false) {
                    isvisit[i][j] = true;
                    dfs1(i, j);
                    res2++;
                }
            }
        }

        System.out.println(res1 + " " + res2);
    }

    static void dfs1(int x, int y) {

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny > n) continue;

            if(map[nx][ny] == map[x][y] && isvisit[nx][ny] == false) {
                isvisit[nx][ny] = true;
                dfs1(nx, ny);
            }
        }
    }
}
