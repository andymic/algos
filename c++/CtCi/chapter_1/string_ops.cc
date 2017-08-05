#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
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

void replace_spaces(char *str, int len){
    int spaces = 0;

    for(int i=0; i<len; i++){
        if(str[i] == ' ')
            spaces++;
    }

    spaces*=2;
    int new_len = len+spaces;
    len--, new_len--;

    for(int j=len; j>=0; j--){
        if(str[j] == ' '){
            str[new_len] = '0';
            str[new_len-1] = '2';
            str[new_len-2] = '%';
            new_len-=3;
        }else{
            str[new_len] = str[j];
            new_len--;
        }
    }
}

string compression_2(string str){
    int len = str.length();
    char last = str[0];
    string result="";
    int count=0;
    for(int i=1; i<len; i++){
    
        if(last == str[i]){
            count++;
        }else{
            result+=last;
            result+= to_string(++count);
            count=0;
            last = str[i];
        }
    }   
    result+=last;
    result+=to_string(++count);
    cout<<str<<"|"<<result<<endl;

    return ((str.length() < result.length()) ? str : result);
}

int compressionLength(string str){
    int len = str.length();

    if(len <= 0)
        return 0;
    
    int count=1;
    int total_len = 0;
    char last = str[0];
    for(int i=0; i<len; i++){
        if(str[i] == last){
            count++;
        }else{
            total_len+=1+ to_string(count).length();
            count=1;
            last = str[i];
        }
    }
    total_len+=1+ to_string(count).length();
    return total_len;
}

int set_compressed_chars(char *ar, int &index, char c, int count){
    ar[index] = c;
    index++;
    string val = to_string(count);
    vector<char> c_str(val.c_str(), val.c_str()+val.size());

    for(char ch : c_str){
        ar[index++] = ch;
    }

    return index;
}

string compression_1(string str){
    int len = str.length();
    int clen = compressionLength(str); 
    if(len < clen)
        return str;
    
    char last = str[0];
    int count=1;
    int idx=0;
    char result[clen];
    for(int i=1; i<len; i++){
    
        if(last == str[i]){
            count++;
        }else{
            set_compressed_chars(result, idx, last, count);
            count=1;
            last = str[i];
        }
    }   
    set_compressed_chars(result, idx, last, count);
    result[clen]='\0';
    cout<<str<<"|"<<result<<endl;
    
    return string(result);
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
    cout<<"-----------\n";
    char rs[8] ={'a', 'b', 'c', ' ', 'd', ' ', ' '};
    replace_spaces(&rs[0], 5);
    cout<<"Result of replace_spaces: "<<rs<<endl;
    cout<<"-----------\n";
    cout<<"Result of string compression: "<<compression_1("aabbbcccccaa")<<endl;
    return 0;
}
