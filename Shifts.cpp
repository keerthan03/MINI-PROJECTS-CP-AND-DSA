#include <bits/stdc++.h>
using namespace std;
string shifts(string s,int n,int k,int flag){
    string res;
    if(flag)k=k;
    else k=-k;
    for(int i=0;i<n;i++)
    {  
        if(((int)s[i]+k)>122)//IF ASCII EXCEEDS 122 THEN SHIFT BACK TO  97 BY SUBTRACTING 26
            res+=s[i]-26+k;
        else if(((int)s[i]+k)<97)//IF ASCII FALL SHORT OF 97 THEN SHIFT BACK TO 122 BY ADDING 26
            res+=s[i]+26+k;
        else res+=s[i]+k;
    }
    return res;
}
int main()
{
    string s,s1,type;
    int k,flag=0;
    cout<<"Encode or Decode:"<<endl;//ENTER OPRATION TO BE PERFORMED
    cin>>type;
    cout<<"Enter Message:"<<endl;//ENTER THE MESSAGE
    cin>>s;
    cout<<"Enter number of shifts:"<<endl;//ENTER SHIFTS
    cin>>k;
    int n=s.size();
    if(type=="Encode")
    flag=1;
    else if(type=="Decode") flag=0;
    else{
        cout<<"Invaid Operation Input"<<endl;
        return 0;
    }
    s1=shifts(s,n,k,flag);
    cout<<"The "<<type<<"d message is:"<<s1<<endl;//FINAL MESSAGE
    return 0;
}
//IN ENCODING WE NEED TO ADD SHIFTS TO EACH CHARACTER,THEN GET THE FINAL MESSAGE. IF ASCII CHARACTER CROSSES 122 i.e more than 'z',THEN SHIFT BACK IT TO 97 i.e 'a' BY SUBTRACTING 26 FROM THAT CHARACTER.
//IN DECODING WE NEED TO SUBTRACT SHIFTS TO EACH CHARACTER,THEN GET THE FINAL MESSAGE. IF ASCII CHARACTER FALL SHORT BY 97 i.e less than 'a' ,THEN SHIFT BACK IT TO 122 i.e 'z' BY ADDING 26 TO THAT CHARACTER