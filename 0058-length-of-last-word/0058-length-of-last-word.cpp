class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.size();// (size of the string including spaces
        int lastNonSpace;// store the index of the last non-space character in the string.
        char space = ' ';// used to compare each character in the string to identify spaces.

        // Finding the Last Non-Space Character
        for(int i=n-1; i>=0; i--){
            // checks each character to find the last non-space character.
            if(s[i] != space){
                lastNonSpace=i;// index of last non space character is stored
                break;// break the loop after that.
            }
        }

        // Counting the Length of the Last Word
        int lenLastWord=0;

        //  Loop starts from last non-space character and moves backwards to index 0
        for(int i=lastNonSpace; i>=0; i--){
            // Loop counts characters until it encounters a space, represnting last word.
            if(s[i] == space)
                break;
            lenLastWord++;
        }

        // return length
        return lenLastWord;
    }
};