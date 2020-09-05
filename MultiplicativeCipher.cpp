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
    int k,ki;
    cin>>k;
    cout<<"Key : "<<k<<endl<<endl;
    vector<int> vect;
    for(int i=0;i<s.length();i++)
    {
       int val=s[i]-'a';
       vect.push_back(val);
    }
    for(int i=0;i<vect.size();i++)
    {
        vect[i]=(vect[i]*k)%26;
    }
    for(int i=0;i<vect.size();i++)
    {
        char c=vect[i]+'A';
        enc=enc+c;
       
    }
    cout<<"Encrypted/Cipher Text: \n"<<enc;
    cout<<"\n \nEncrypted using Multiplicative Cipher ";
    cout<<"\n\nNow Decrypting :\n"<<enc<<endl;
    
    
    for(int i=1;i<999999;i++)
    {
        if((k*i)%26==1)
        {
            ki=i;
            break;
        }
    }
    cout<<"Inverse Key : "<<ki<<endl<<endl;
    for(int i=0;i<vect.size();i++)
    {
        vect[i]=(vect[i]*ki)%26;
    }
    for(int i=0;i<vect.size();i++)
    {
        char c=vect[i]+'a';
        dec=dec+c;
       
    }
   cout<<"Plain Text comes out to be: \n"<<dec<<endl;
   
   return 0;
}