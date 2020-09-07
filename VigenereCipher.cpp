#include<iostream>
#include<vector>

using namespace std;

int main()
{
    string s;
    cin>>s;
    cout<<"Karanpreet Singh (045)"<<endl;
    cout<<"\nPlain Text :\n"<<s<<endl;
    string enc="",dec="";
    string key;
    cin>>key;
    
    cout<<"Key : "<<key<<endl<<endl;
    vector<int> vect;
    for(int i=0;i<s.length();i++)
    {
       int val=s[i]-'a';
       vect.push_back(val);
    }
    vector<int> vect2;
    for(int i=0;i<key.length();i++)
    {
       int val=key[i]-'a';
       vect2.push_back(val);
    }
    int j=0;
    for(int i=0;i<vect.size();i++)
    {
        if(j==vect2.size())
        {
            j=0;
        }
        vect[i]=(vect[i]+vect2[j++])%26;
    }
    for(int i=0;i<vect.size();i++)
    {
        char c=vect[i]+'A';
        enc=enc+c;
       
    }
    cout<<"Encrypted/Cipher Text: \n"<<enc;
    cout<<"\n \nEncrypted using Vigenere Cipher ";
    cout<<"\n\nNow Decrypting :\n"<<enc<<endl;
    j=0;
    for(int i=0;i<vect.size();i++)
    {
        if(j==vect2.size())
        {
            j=0;
        }
        vect[i]=(vect[i]-vect2[j++])%26;
        if(vect[i]<0)
        {
            vect[i]=26+vect[i];
        }
    }
    for(int i=0;i<vect.size();i++)
    {
        char c=vect[i]+'a';
        dec=dec+c;
       
    }
   cout<<"\nPlain Text comes out to be: \n"<<dec<<endl;
   
   return 0;
}
