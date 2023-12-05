class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || ( x != 0  &&  x%10 == 0)) return 0;   
        int pal = 0;

        while(x > pal){
            pal = pal*10 + x%10;
            x /= 10;
        }

        
        return (x == pal || x == pal/10); 
        //x是偶數位，x == pal
        //x是奇數位，x == pal/10 (中間那位不重要)      
    }
};