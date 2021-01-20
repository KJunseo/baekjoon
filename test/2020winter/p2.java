import java.util.*;

class Solution {
    public String solution(String encrypted_text, String key, int rotation) {
        String answer = "";
        int size = encrypted_text.length();
        
        ArrayList<String> list = new ArrayList<>(Arrays.asList(encrypted_text.split("")));
        ArrayList<String> _key = new ArrayList<>(Arrays.asList(key.split("")));
        
        Collections.rotate(list, -rotation);
        
        for(int i = 0; i < size; i++) {
            int current_value = list.get(i).charAt(0);
            int key_value = _key.get(i).charAt(0) - 96;
            
            int value = current_value - key_value;
            
            if(value < 97) 
                value += 26;
                
            String s = Character.toString((char)value);
            
            list.set(i, s);
        }
        
        for(String s : list)
            answer += s;

        return answer;
    }
}