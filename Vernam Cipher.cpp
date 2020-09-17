#include<iostream>
#include<vector>

using namespace std;

int main()
{
    cout<<"Karanpreet Singh (045)"<<endl;
    cout<<"\nVernam Cipher is a Special Case of Vignere Cipher where the length of plain text is equal to the length of key."<<endl;
    string s;
    cin>>s;
    cout<<"\nPlain Text :\n"<<s<<endl;
    string enc="",dec="";
    string key;
    cin>>key;
    
    cout<<"Key : \n"<<key<<endl<<endl;
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
    
    for(int i=0;i<vect.size();i++)
    {
       
        vect[i]=(vect[i]+vect2[i])%26;
    }
    for(int i=0;i<vect.size();i++)
    {
        char c=vect[i]+'A';
        enc=enc+c;
       
    }
    cout<<"Encrypted/Cipher Text: \n"<<enc;
    cout<<"\n \nEncrypted using Vernam Cipher ";
    cout<<"\n\nNow Decrypting :\n"<<enc<<endl;
   
    for(int i=0;i<vect.size();i++)
    {
    
        vect[i]=(vect[i]-vect2[i])%26;
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