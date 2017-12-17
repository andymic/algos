class Solution {
public:
    int strStr(string haystack, string needle) {

        if((haystack.length()==0 && needle.length()==0) || needle.length() == 0)
            return 0;


        for(int i=0; i<haystack.length(); i++){
            if(haystack[i] == needle[0]){
                int j = needle.length()-1;

                while(j>=0){
                    if(haystack[i+j]==needle[j])
                        j--;
                    else
                        break;
                }

                if(j==-1)
                    return i;
            }
        }
        return -1;
    }
};
