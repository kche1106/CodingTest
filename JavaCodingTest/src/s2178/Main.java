package s2178;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    static int[][] map;
    static int n;
    static int m;
    static boolean[][] visited;
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();

        map = new int[n][m];
        for(int i=0; i<n; i++) {
            String s = in.next();
            for(int j=0; j<m; j++) {
                map[i][j] = s.charAt(j) - '0';
            }
        }

        visited = new boolean[n][m];
        visited[0][0] = true;
        bfs(0, 0);
        System.out.println(map[n-1][m-1]);
    }

    public static void bfs(int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {x,y});

        while(!q.isEmpty()) {
            int now[] = q.poll();
            int nowX = now[0];
            int nowY = now[1];

            for(int i=0; i<4; i++) {
                int nx = nowX + dx[i];
                int ny = nowY + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if(visited[nx][ny] == false && map[nx][ny] != 0) {
                        q.add(new int[] {nx, ny});
                        map[nx][ny] = map[nowX][nowY] + 1;
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }
}
