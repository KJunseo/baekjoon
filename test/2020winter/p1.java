class Solution {
    public String solution(int n, int[][] delivery) {
        String answer = "";
        
        int [] check = new int[n + 1];
        
        for(int i = 0; i < delivery.length; i++) {
            if(delivery[i][2] == 1) {
                check[delivery[i][0]] = 1;
                check[delivery[i][1]] = 1;
            }
        }
        
        for(int i = 0; i < delivery.length; i++) {
            if(delivery[i][2] == 0) {
                if(check[delivery[i][0]] == 1) {
                    check[delivery[i][1]] = -1;
                } else if(check[delivery[i][1]] == 1) {
                    check[delivery[i][0]] = -1;
                }
            }
        }
        
        for(int i = 1; i <= n; i++) {
            if(check[i] == 1) answer += "O";
            else if(check[i] == 0) answer += "?";
            else answer += "X";
        }
        
        return answer;
    }
}