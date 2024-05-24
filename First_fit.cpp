#include<iostream>
using namespace std;
int main()
{
    int n1,n2,m[20],po[20],p[20],flag;
    cout<<"Enter The no. of partition:"<<endl;
    cin>>n1;
    cout<<"Enter memory size for each partition:"<<endl;
    for(int i=1; i<=n1; i++)
    {
        cout<<"Partition "<<i<<":\t";
        cin>>m[i];
        po[i]=i;
    }

    cout<<"Enter The no. of process:"<<endl;
    cin>>n2;
    cout<<"Enter memory size for each partition:"<<endl;
    for(int i=1; i<=n2; i++)
    {
        cout<<"Process "<<i<<":\t";
        cin>>p[i];
    }
    for(int i=1;i<=n2;i++)
    {
        flag=1;
        for(int j=1;j<=n1;j++)
        {
            if(p[i]<=m[j])
            {
                cout<<"\n process "<<i<<"whose memory size is "<<p[i]<<" Kb is allocated at memory partition "<<po[j];
                m[j]=m[j]-p[i];
                break;
            }
            else{
                flag++;
            }
        }
        if(flag>n1)
        {
             cout<<"\n process "<<i<<"whose memory size is "<<p[i]<<" Kb can not  be allocated ";
        }
    }
    return 0;
}