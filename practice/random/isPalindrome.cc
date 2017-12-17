class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0)
            return true;

        string temp;

        for(int i=0; i<s.length(); i++){
            int c = tolower(s[i]);

            if((c>= 48 && c<=57) || c>=97 && c<=122){
                temp+=tolower(s[i]);
            }
        }


        for(int i=0, j=temp.length()-1; i<temp.length()/2; i++, j--){
            if(temp[i] != temp[j])
                return false;
        }

        return true;
    }

    bool isPalindrome1(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
        if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
    }

    return true;
}
};
