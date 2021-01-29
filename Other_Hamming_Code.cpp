#include<bits/stdc++.h>
#define mem(a,b)        memset(a,b,sizeof(a))

using namespace std;
 
int main()
{
    string sn,rc;
    string map[20] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"}; 
    char ptype;
    int msglen,cdsize,pbit,arr[50],brr[50];

    for(int i=0;i<20;i++)
        arr[i] = 5;
    cout << "Enter Message: ";
    cin >> sn;
    msglen = sn.size();


    reverse(sn.begin(),sn.end());

    pbit = log2(msglen+1) + 1;

    if((msglen+1+pbit) > pow(2,pbit) )
        pbit++;

    cout << pbit << endl;

    cdsize = msglen + pbit;

    for(int i=1,j=0;i<=cdsize;i++)
    {
        if(pow(2,j) == i)
        {
            j++;
            continue;
        }
        arr[i] = sn[i-j-1] - 48 ;
    }

    cout << "Enter Parity Type: " ;
    cin >> ptype;
    

    int cnt=0;
    if(ptype == 'E' || ptype == 'e')
    {

        for(int i = 3;i>=0;i--)
        {
            for(int j=1;j<=cdsize;j++)
            {
                if(map[j][i] == '1' && arr[j]==1)
                {
                    cnt++;
                }
            }
            int z = pow(2,3-i);
            if(cnt&1) arr[z] = 1;
            else arr[z] = 0;
            cnt=0;
        }
        // arr[1] = arr[3] ^ arr[5] ^ arr[7];
        // arr[2] = arr[3] ^ arr[6] ^ arr[7];
        // arr[4] = arr[5] ^ arr[6] ^ arr[7];
    }

    else if(ptype == 'O' || ptype == 'o')
    {
        for(int i = 3;i>=0;i--)
        {
            for(int j=1;j<=cdsize;j++)
            {
                if(map[j][i] == '1' && arr[j]==1)
                {
                    cnt++;
                }
            }
            int z = pow(2,3-i);
            if(cnt&1) arr[z] = 0;
            else arr[z] = 1;
            cnt=0;
        }
        // arr[1] = arr[3] ^ arr[5] ^ arr[7]^1;
        // arr[2] = arr[3] ^ arr[6] ^ arr[7]^1;
        // arr[4] = arr[5] ^ arr[6] ^ arr[7]^1;
    }

    for(int i = cdsize ; i>=1 ; i--)
        cout << arr[i] << " " ;
    cout << endl;

    srand(time(0));
    int x = rand()%cdsize +1 ;
    x = rand()%cdsize +1 ;

    // cout << x << endl;

    for(int i=0;i<40;i++)
        brr[i] = arr[i];

    brr[2] = brr[2]^1;

    for(int i = cdsize ; i>=1 ; i--)
        cout << brr[i] << " " ;

    cout << endl;
    
    int err[10];
    if(ptype == 'E' || ptype == 'e'){

        for(int i = 3;i>=0;i--)
        {
            for(int j=1;j<=cdsize;j++)
            {
                if(map[j][i] == '1' && brr[j]==1)
                {
                    cnt++;
                }
            }
            int z = 3-i;
            if(cnt&1) err[z] = 1;
            else err[z] = 0;
            cnt=0;
        }
        // err[0] = brr[1] ^ brr[3] ^ brr[5] ^ brr[7];
        // err[1] = brr[2] ^ brr[3] ^ brr[6] ^ brr[7];
        // err[2] = brr[4] ^ brr[5] ^ brr[6] ^ brr[7];
    }

    else if(ptype == 'O' || ptype == 'o'){

        for(int i = 3;i>=0;i--)
        {
            for(int j=1;j<=cdsize;j++)
            {
                if(map[j][i] == '1' && brr[j]==1)
                {
                    cnt++;
                }
            }
            int z = 3-i;
            if(cnt&1) err[z] = 0;
            else err[z] = 1;
            cnt=0;
        }

        // err[0] = brr[1] ^ brr[3] ^ brr[5] ^ brr[7] ^ 1;
        // err[1] = brr[2] ^ brr[3] ^ brr[6] ^ brr[7] ^ 1;
        // err[2] = brr[4] ^ brr[5] ^ brr[6] ^ brr[7] ^ 1;
    }

    int errbit=0;
    for(int i=0;i<pbit;i++)
    {

        errbit += err[i] * pow(2,i);
        cout << "errbit: " << errbit <<endl << "err["<<i<<"] : "<< err[i] << endl << "2^1: "<< pow(2,i) << endl;
    }

    if(errbit == 0) cout << "No ERROR" << endl;
    else 
        cout << cdsize-errbit+1 << " number bit has got error\n";




    return 0;
}