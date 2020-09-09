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
    int key;
    cin>>key;
    
    cout<<"Key : "<<key<<endl<<endl;
    vector<int> vect;
    for(int i=0;i<s.length();i++)
    {
       int val=s[i]-'a';
       vect.push_back(val);
    }
    int a=vect[0];
    vect[0]=(vect[0]+key)%26;
  
    for(int i=1;i<vect.size();i++)
    {
        int b=vect[i];
        vect[i]=(vect[i]+a)%26;
        a=b;
    }
    for(int i=0;i<vect.size();i++)
    {
        char c=vect[i]+'A';
        enc=enc+c;
       
    }
    cout<<"Encrypted/Cipher Text: \n"<<enc;
    cout<<"\n \nEncrypted using Autokey Cipher ";
    cout<<"\n\nNow Decrypting :\n"<<enc<<endl;
    
    vect[0]=(vect[0]-key)%26;
    if(vect[0]<0)
    {
        vect[0]=26+vect[0];
    }
    for(int i=1;i<vect.size();i++)
    {
        vect[i]=(vect[i]-vect[i-1])%26;
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