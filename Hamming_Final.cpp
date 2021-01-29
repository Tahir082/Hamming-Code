#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

class Receiver;

class Sender
{
int parity_type, codewordlen, msglen, message[100], parity_bit=0;
int codeword[100], p=0, m=1, i, j, k , l;
int paritycount, onecount;
public:
    //int i,parity_type,message_size,msg[100],parity_bit=0;
    void getmessage();
    void parity_count();
    void codeword_array();
    void final_codeword_print();
    void even_odd();

    friend Receiver;


};

class Receiver
{
    int random1, random2;
    int x,y,z, paritycount, onecount, decimal_array[100], decimal2_array[100];
    int received[100];

public:
    void one_bit_random(Sender);
    void one_biterror_codeword(Sender);
    void one_biterror_detection(Sender);
    void two_bit_random(Sender);
    void two_biterror_codeword(Sender);
    void two_biterror_detection(Sender);
};

void Receiver :: one_bit_random(Sender s)
{

    random1= rand()%s.codewordlen;
    for(x=0; x<=s.parity_bit; x++)
    {
        if(random1==pow(2,x))
        {
            random1=random1+1;
        }

    }
    for(x=1; x<=s.codewordlen; x++)
    {
        received[x]=s.codeword[x];
    }


    if(received[random1]==0)
    {
        received[random1]=1;
    }
    else
    {
        received[random1]=0;
    }

    cout<<"\n\n Error Created at position: "<<random1<<"\n\n Where Codeword Size is: "<<s.codewordlen;


}

void Receiver :: one_biterror_codeword(Sender s)
{
    cout<<"\n\n codeword with one bit error in message";
    for(int x=1; x<=s.codewordlen; x++)
    {
        cout<<" "<<received[x];
    }


}

void Receiver :: one_biterror_detection(Sender s)
{

  for(x=1; x<=s.parity_bit; x++)
    {
        onecount=0;
        paritycount=pow(2,x-1);
        for(y=paritycount-1; y<=s.codewordlen; y=y+paritycount+z-1)
        {
            for(z=1 ;z<=paritycount; z++)
            {
                if(received[y+z]==1)
                    onecount++;
            }

        }
        if(s.parity_type==1)
        {
            if(onecount%2==0)
                decimal_array[x]=1;

            else
                decimal_array[x]=0;
        }
        else
        {
            if(onecount%2==0)
                decimal_array[x]=0;

            else
                decimal_array[x]=1;
        }
    }


int error_decimal=0;
for(y=s.parity_bit; y>0; y--)
{
    error_decimal=error_decimal+pow(2,y-1)*decimal_array[y];
}
cout<<"\n\n Error is at postition: ";
cout<<error_decimal;

if(received[error_decimal]==0)
    {
        received[error_decimal]=1;
    }
    else
    {
        received[error_decimal]=0;
    }

    cout<<"\n\n Sender's Message with parity bits:";

    for (y = 1; y <=s.codewordlen ; y++)
    {
        cout<<" "<<received[y];
    }

    cout<<"\n\n Sender's Message without parity bits:";
    int p=0;
    for (y = 1; y <= s.codewordlen; y++)
    {
        if (y==pow(2, p))
        {
            cout<<"";
            p++;
        }
        else
        {
            cout<<" "<<received[y];
        }
    }
}

void Receiver :: two_bit_random(Sender s)
{
    random1= rand()%s.codewordlen;
    for(x=0; x<=s.parity_bit; x++)
    {
        if(random1==pow(2,x))
        {
            random1=random1+1;
        }

    }
    for(x=1; x<=s.codewordlen; x++)
    {
        received[x]=s.codeword[x];
    }


    if(received[random1]==0)
    {
        received[random1]=1;
    }
    else
    {
        received[random1]=0;
    }

    cout<<"\n\n 1st Error Created at position: "<<random1<<"\n\n Where Codeword Size is: "<<s.codewordlen;

    random2= random1+1;

    if(received[random2]==0)
    {
        received[random2]=1;
    }
    else
    {
        received[random2]=0;
    }

    cout<<"\n\n 2nd Error Created at position: "<<random2<<"\n\n Where Codeword Size is: "<<s.codewordlen;
}

void Receiver :: two_biterror_codeword(Sender s)
{
    cout<<"\n\n Codword with two bits error:\n";
    for(x=1; x<=s.codewordlen; x++)
    {
        cout<<" "<<received[x];
    }

}

void Receiver :: two_biterror_detection(Sender s)
{
    int twoE;
        for(x=1; x<=s.parity_bit; x++)
    {
        onecount=0;
        paritycount=pow(2,x-1);
        for(y=paritycount-1; y<=s.codewordlen; y=y+paritycount+z-1)
        {
            for(z=1 ;z<=paritycount; z++)
            {
                if(received[y+z]==1)
                    onecount++;
            }

        }
        if(s.parity_type==1)
        {
            if(onecount%2!=0)
                decimal_array[x]=1;

            else
                decimal_array[x]=0;
        }
        else
        {
            if(onecount%2!=0)
                decimal_array[x]=0;

            else
                decimal_array[x]=1;
        }
    }


int error_decimal=0;
for(y=s.parity_bit; y>0; y--)
{
    error_decimal=error_decimal+pow(2,y-1)*decimal_array[y];
}
cout<<"\n\n 1st Error is at position: ";
cout<<error_decimal;

    if(received[error_decimal]==0)
        {
            received[error_decimal]=1;
        }
    else
        {
            received[error_decimal]=0;
        }

        //AGAIN!!!
        for(x=1; x<=s.parity_bit; x++)
    {
        onecount=0;
        paritycount=pow(2,x-1);
        for(y=paritycount-1; y<=s.codewordlen; y=y+paritycount+z-1)
        {
            for(z=1 ;z<=paritycount; z++)
            {
                if(received[y+z]==1)
                    onecount++;
            }

        }
        if(s.parity_type==1)
        {
            if(onecount%2==0)
                decimal2_array[x]=1;

            else
                decimal2_array[x]=0;
        }
        else
        {
            if(onecount%2==0)
                decimal2_array[x]=0;

            else
                decimal2_array[x]=1;
        }
    }




int error_decimal2=0;
for(y=s.parity_bit; y>0; y--)
{
    error_decimal2=error_decimal2+pow(2,y-1)*decimal2_array[y];
}
cout<<"\n\n 2nd Error is at position: ";
cout<<error_decimal2;
if(received[error_decimal2]==0)
        {
            received[error_decimal2]=1;
        }
    else
        {
            received[error_decimal2]=0;
        }

    cout<<"\n\n Sender's Message with parity bits:";

    for (y = 1; y <=s.codewordlen ; y++)
    {
        cout<<" "<<received[y];
    }

    cout<<"\n\n Sender's Message Finally Received without parity bits:";
    int p=0;
    for (y = 1; y <= s.codewordlen; y++)
    {
        if (y==pow(2, p))
        {
            cout<<"";
            p++;
        }
        else
        {
            cout<<" "<<received[y];
        }
    }

}

void Sender :: even_odd()
{
     for(j=1; j<=parity_bit; j++)
    {
        onecount=0;
        paritycount=pow(2,j-1);
        for(i=paritycount-1; i<=codewordlen; i=i+paritycount+k-1)
        {
            for(k=1 ;k<=paritycount; k++)
            {
                if(codeword[i+k]==1)
                    onecount++;
            }

        }
        if(parity_type==1)
        {
            if(onecount%2==0)
                codeword[paritycount]=1;

            else
                codeword[paritycount]=0;
        }
        else
        {
            if(onecount%2==0)
                codeword[paritycount]=0;

            else
                codeword[paritycount]=1;
        }
    }

}

void Sender :: final_codeword_print()
{
    cout<<"\n\n Codeword in transmitter with final even odd parity count:\n";
    for(i=1; i<=codewordlen; i++)
    {
        cout<<" "<<codeword[i];
    }
}


void Sender :: codeword_array() /// parity bit + data + making box ///
{
    codewordlen=msglen+parity_bit;
    for (i = 1; i <= codewordlen; i++)
    {
        if (i==pow(2, p))
        {
            codeword[i] = 0;
            p++;
        }
        else
        {
            codeword[i] = message[m];
            m++;
        }
    }

    cout<<"\n\n Codeword to be sent in transmitter:\n";

    for (i = 1; i <= codewordlen; i++)
    {
        cout<<" "<<codeword[i];
    }

}

void Sender :: parity_count()
{

    for(i=0; i<=msglen; i++)
    if(msglen+i > pow (2, i))
    {
        parity_bit++;
    }

}

void Sender :: getmessage()
{

    cout<<"\n\n Enter Sender's message size: ";
    cin>>msglen;

    cout<<"\n\n Enter message's bit one by one:";
    for(i=1; i<=msglen; i++)
        {
            cin>>message[i];
        }

    cout<<"\n\n Even(0) or Odd(1) parity??: ";
    cin>>parity_type;

    cout<<"\n\n Your Original Message is: ";
    for(i=1; i<=msglen; i++)
        {
            cout<<" "<<message[i];
        }
}


int main()
{
    cout<<"\n\n\n\n\t ==================== PROJECT: HAMMING CODE ======================\n\n\n";
    cout<<"\n\n Submitted By, \n";
    cout<<" Abdullah Muhammad Tahir\n";
    cout<<" ID: 2017-1-60-082\n";
    cout<<" Course Title: Data Communication\n";
    cout<<" Course Code: CSE350 || Section: 03\n\n";

    Sender tahir;
    Receiver MRU;
    tahir.getmessage();
    tahir.parity_count();
    tahir.codeword_array();
    tahir.even_odd();
    tahir.final_codeword_print();
    int choice;
    cout<<"\n\n How many bit error you want to test? 1 or 2??\n";
    cin>>choice;
    if(choice==1)
    {
        MRU.one_bit_random(tahir);
        MRU.one_biterror_codeword(tahir);
        MRU.one_biterror_detection(tahir);
    }
    if(choice==2)
    {
        MRU.two_bit_random(tahir);
        MRU.two_biterror_codeword(tahir);
        MRU.two_biterror_detection(tahir);
    }

    cout<<"\n\n\n\n\n";
    return 0;;

}
