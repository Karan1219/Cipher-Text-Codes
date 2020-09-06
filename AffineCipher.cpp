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
    int key1,key2,key1Inv;
    cin>>key1;
    cin>>key2;
    cout<<"Key 1: "<<key1<<endl;
    cout<<"Key 2: "<<key2<<endl;
    vector<int> vect;
    for(int i=0;i<s.length();i++)
    {
       int val=s[i]-'a';
       vect.push_back(val);
    }
    for(int i=0;i<vect.size();i++)
    {
        vect[i]=((vect[i]*key1)+key2)%26;
    }
    for(int i=0;i<vect.size();i++)
    {
        char c=vect[i]+'A';
        enc=enc+c;
       
    }
    cout<<"Encrypted/Cipher Text: \n"<<enc;
    cout<<"\n \nEncrypted using Affine Cipher ";
    cout<<"\n\nNow Decrypting :\n"<<enc<<endl;
    
    
    for(int i=1;i<9999;i++)
    {
        if((key1*i)%26==1)
        {
            key1Inv=i;
            break;
        }
    }
    cout<<"Inverse Key : "<<key1Inv<<endl<<endl;
    for(int i=0;i<vect.size();i++)
    {
            vect[i]=((vect[i]-key2)*key1Inv)%26;
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
   cout<<"Plain Text comes out to be: \n"<<dec<<endl;
   
   return 0;
}