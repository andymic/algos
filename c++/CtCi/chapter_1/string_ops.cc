#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//TODO: implement using bit vector
bool has_unique_chars(string a){
    cout<<a<<endl;
    bool hash[256] ={ false };
    int len = a.length();

    for(int i=0; i<len; i++){
        if(hash[(int)a[i]])
            return false;

        hash[(int)a[i]] = true;
    }
    return true;
}

void reverse_c_string(char *str){
    cout<<str<<endl;
    int len = 0;
    while(str[len] != '\0')
        len++;
    //swapping chars
    for(int i=0, j=len-1; i<len/2; i++, j--){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

}


void reverse_c_string_a(char * str){
    char *end = str;

    if(str){
        while(*end)
            ++end;

        --end;
        //swapping pointers
        while(str < end){
            char temp = *str;
            *str++ = *end;
            *end-- = temp;
        }
    }
}

bool isPermutation(string a, string b){
    cout<<a<<"|"<<b<<endl;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

bool isSubstring(string a, string b){
    cout<<a<<"|"<<b<<endl;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
   
    return a.find(b) != string::npos; 
}

int main(){
    string a = "waterbottle";
    string b = "erbottlewaat";

    cout<<"isPermutation: "<<((isPermutation(a,b) == 0) ? "false":"true")<<endl;
    cout<<"-----------\n";
    cout<<"isPermutation: "<<((isSubstring(a,b) == 0) ? "false":"true")<<endl;
    
    cout<<"-----------\n";
    cout<<"has_unique_chars: "<<((has_unique_chars("abcdef") == 0) ? "false":"true")<<endl;
        
    cout<<"-----------\n";
    char c_str[] = "abcdefg";
    reverse_c_string_a(&c_str[0]);
    cout<<"reverse_c_string: "<<c_str<<endl;
    return 0;
}
