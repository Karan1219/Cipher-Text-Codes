#include <iostream> 
using namespace std;

string encrypt(string text, int key) 
{ 
    char rail[key][(text.length())];
    for (int i=0; i < key; i++) 
        for (int j = 0; j < text.length(); j++) 
            rail[i][j] = '\n'; 

    bool dir_down = false; 
    int row = 0, col = 0; 
    for (int i=0; i < text.length(); i++) 
    {
        if (row == 0 || row == key-1) 
            dir_down = !dir_down;
        rail[row][col++] = text[i]; 
        dir_down?row++ : row--; 
    } 
    string result; 
    for (int i=0; i < key; i++) 
        for (int j=0; j < text.length(); j++) 
            if (rail[i][j]!='\n') 
            {
                rail[i][j]=rail[i][j]-'a'+'A';
                result.push_back(rail[i][j]); 
            }
    return result; 
} 
string decrypt(string cipher, int key) 
{ 
    char rail[key][cipher.length()]; 
    for (int i=0; i < key; i++) 
        for (int j=0; j < cipher.length(); j++) 
            rail[i][j] = '\n';
    bool dir_down; 
    int row = 0, col = 0; 
    for (int i=0; i < cipher.length(); i++) 
    { 
        if (row == 0) 
            dir_down = true; 
        if (row == key-1) 
            dir_down = false; 
        rail[row][col++] = '*'; 
        dir_down?row++ : row--; 
    } 
    int index = 0; 
    for (int i=0; i<key; i++) 
        for (int j=0; j<cipher.length(); j++) 
            if (rail[i][j] == '*' && index<cipher.length()) 
                rail[i][j] = cipher[index++]; 
    string result; 
    row = 0, col = 0; 
    for (int i=0; i< cipher.length(); i++) 
    { 
        if (row == 0) 
            dir_down = true; 
        if (row == key-1) 
            dir_down = false; 
        if (rail[row][col] != '*') 
        {
            rail[row][col]=rail[row][col]-'A'+'a';
            result.push_back(rail[row][col++]); 
        }
        dir_down?row++: row--; 
    } 
    return result; 
} 

int main() 
{ 
    string s;
    cin>>s;
    cout<<"Karanpreet Singh (045)"<<endl;
    cout<<"\nPlain Text :\n"<<s<<endl;
    int k;
    cin>>k;
    cout<<"Key : "<<k<<endl<<endl;
    string enc=encrypt(s, k);
    cout<<"Encrypted/Cipher Text: \n"<<enc;
    cout<<"\n \nEncrypted using Rail Fence Cipher ";
    cout<<"\n\nNow Decrypting :\n"<<enc<<endl;
    string dec=decrypt(enc, k);
    cout<<"Plain Text comes out to be: \n"<<dec<<endl;

    return 0; 
} 