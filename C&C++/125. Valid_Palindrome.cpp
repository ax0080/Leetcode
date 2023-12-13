class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0;
        int tail = s.size() - 1;

        while (head < tail) {
            while (head < tail && !(isalnum(s[head]))) {
                head++;
            }

            while (head < tail && !(isalnum(s[tail]))) {
                tail--;
            }

            if (65 <= s[head] && s[head] <= 90) s[head] += 32;
            if (65 <= s[tail] && s[tail] <= 90) s[tail] += 32;
            if (head >= tail) return true;

            if (s[head] == s[tail]) {
                //printf("head = %c\n", s[head]);
                //printf("tail = %c\n", s[tail]);

                head++;
                tail--;
            } else {
                //printf("head = %c\n", s[head]);
                //printf("tail = %c\n", s[tail]);
                return false;
            }
        }

        return true;
    }
};
