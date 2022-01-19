#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
    long long int n,temp,sum=0,standard=0,cont=1,num[200000],min=1000000001,space=0;
    set<long long int> num_able;
    num_able.insert(0);
    cin>>n;
    for(long long int i=0;i<n;i++)
    {
        cin>>num[i];
        if(num[i]<min)min=num[i];
        sum+=num[i];
    }
    if(min!=1)
    {
        cout<<"1";
        return 0;
    }
    
    sort(num,num+n);
    long long int i;
    for(i=0;i<n;i++)
    {
        temp=num[i];
        if(space<cont&&cont>1)break;
        if(cont>temp)
        {
            standard+=temp;
        }
        else
        {
            for(auto j=num_able.rbegin();j!=num_able.rend();j++)
            {
                num_able.insert(temp+*j);
            }
            for(long long int k=0;k<=temp&&k<=standard;k++)
                num_able.insert(k);
            while(num_able.count(cont)==1)cont++;
        }


        /*for(auto j=num_able.begin();j!=num_able.end();j++)
        {
            cout<<*j<<' ';
        }
        cout<<"temp="<<temp<<" standard="<<standard<<" cont="<<cont<<" space="<<space<<endl;
        */
    }

    if(cont<temp&&cont>1)i--;
    for(;i<n;i++)
    {
        temp=num[i];
        if(cont>temp)
        {
            standard+=temp;
        }
        else
        {
            standard+=cont;
        }

        /*for(auto j=num_able.begin();j!=num_able.end();j++)
        {
            cout<<*j<<' ';
        }
        cout<<"temp="<<temp<<" standard="<<standard<<" cont="<<cont<<" space="<<space<<endl;
        */
    }









 
    for(long long int i=0;i<9999999999;i++)
    {
        if(num_able.count(i)==0)
        {
            cout<<i+standard;
            return 0;
        }
    }
    cout<<"Wrong ans";
    return 0;
}