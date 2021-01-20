import java.util.*;

class Pair {
    int y;
    int x;
    
    Pair(int y, int x) {
        this.y = y;
        this.x = x;
    }
    
}

class Solution
{
    int [] dy = {-1, 1, 0, 0};
    int [] dx = {0, 0, 1, -1};
    boolean [][] visited = new boolean[100][100];
    
    public void bfs(int y, int x, int kind, int[][] v) {
        Queue<Pair> q = new LinkedList<Pair>();
        q.add(new Pair(y, x));
        visited[y][x] = true;
        
        while(!q.isEmpty()) {
            Pair p = q.remove();
            
            for(int i = 0; i < 4; i++) {
                int ny = p.y + dy[i];
                int nx = p.x + dx[i];
                
                if(ny < 0 || nx < 0 || ny >= v.length || nx >= v.length) 
                    continue;
                
                if(visited[ny][nx])
                    continue;
                
                if(v[ny][nx] != kind)
                    continue;
                
                q.add(new Pair(ny, nx));
                visited[ny][nx] = true;
            }
        }
    }
    
    public int[] solution(int[][] v)
    {
        int[] answer = new int[3];
        
        for(int kind = 0; kind < 3; kind++) {
            int cnt = 0;
            for(int i = 0; i < v.length; i++) {
                for(int j = 0; j < v[i].length; j++) {
                    if(v[i][j] != kind) continue;
                    if(visited[i][j]) continue;
                    bfs(i, j, kind, v);
                    cnt++;
                }
            }
            answer[kind] = cnt;
        }

        return answer;
    }
}