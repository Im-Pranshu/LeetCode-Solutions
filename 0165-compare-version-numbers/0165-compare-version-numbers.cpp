class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0 , p2 = 0;

        // loop until whole string 1 and 2 is compared
        while(p1 < version1.length() || p2 < version2.length()){
            int num1 = 0, num2 = 0;

            // extract number before '.' from version 1
            while(p1 < version1.length() && version1[p1] != '.'){
                num1 = num1 * 10 + (version1[p1] - '0');
                p1++;
            }

            // extract number before '.' from version 2
            while(p2 < version2.length() && version2[p2] != '.'){
                num2 = num2 * 10 + (version2[p2] - '0');
                p2++;
            }

            // version1 is large
            if(num1 > num2) return 1;
            // version2 is large
            if(num1 < num2) return -1;

            // skip '.' and move to next.
            p1++;
            p2++;
        }

        // both version are same
        return 0;
    }
};