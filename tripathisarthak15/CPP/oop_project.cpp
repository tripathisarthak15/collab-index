#include<iostream>  
#include<fstream>  
#include <stdlib.h>  
using namespace std;  
class head  
{  
    char Iname[40][40];  
  
public:  
    int totalitems;  
    float Qty[3];  
    float price[3];  
    int gsttotalprice[3];  
    int totalprice[3];  
    void input();  
    void output();  
};  
class taxgst:public head  //Inheritence (Public Derivation)
{  
    float tgst;  
public:  
    void gstcal();  
    void outputs();  
    void sum();  
};  
  
void head::input()  
{  
    system("CLS");  
    cout<<"\nEnter number of items= ";  
    cin>>totalitems;  
  
    for(int i=0; i<totalitems; i++)  
    {  
        cout<<"\nEnter name of item "<<i+1<<": ";  
        cin>>Iname[i];  
        cout<<"Enter quantity: ";  
        cin>>Qty[i];  
        cout<<"Enter price of item "<<i+1<<": ";  
        cin>>price[i];  
        totalprice[i]=Qty[i]*price[i];  
    }  
}  

void head::output()  
{  
    int a;  
  
    ifstream infile("COUNT.TXT");  
    infile>>a;  
  
    ofstream outfile("COUNT.TXT");  
    a+=1;  
    outfile<<a;  
    outfile.close();  
  
    {ofstream outfile("HIS.TXT", ios::app);  
    outfile<<endl<<"Bill No.: "<<a<<endl;  
    outfile<<"------------------------------------------------------------------------"<<endl;  
cout<<"\n";  
    cout<<"Name of Item\tQuantity   Price  Total Price\n";  
    for(int i=0;i<totalitems;i++)  
    {  
        outfile<<"Name: "<<Iname[i]<<" Qty: "<<Qty[i]<<" Price: "<<totalprice[i]<<endl;  
        cout<<Iname[i]<<"\t\t"<<Qty[i]<<"\t   "<<price[i]<<"\t   "<<totalprice[i]<<'\n';  
    }  
  
    outfile<<"------------------------------------------------------------------------"<<endl;  
    outfile.close();  
    }  
}  
   
void taxgst::gstcal()  
{  
    input();  
    for(int i=0;i<totalitems;i++)  
    {  
        if(price[i]<=100.00)  
        {  
            gsttotalprice[i]=totalprice[i]+(0.03*totalprice[i]);  
        }  
        else  
        {  
            gsttotalprice[i]=totalprice[i]+(0.1*totalprice[i]);  
        }  
    }  
}  
  
void taxgst::outputs()  
{  
    output();  
  
    float cash=0,sum=0,qty=0,sumt=0;  
  
    for(int i=0;i<totalitems;i++)  
    {  
           sumt+=totalprice[i];  
           sum+=gsttotalprice[i];  
           qty+=Qty[i];  
    }  
    cout<<"\nTotal:";  
    cout<<"\n------------------------------------------------------------------------------";  
    cout<<"\n\tQuantity= "<<qty<<"\t\t Sum= "<<sumt<<"\tWith GST:"<<sum;  
    cout<<"\n------------------------------------------------------------------------------";  
  
pay:  
  
    cout<<"\n\n\t\t\t * * * * END OF BILL * * * * \n";  
    cout<<"\n\n\t\t\tTotal cash given: ";  
    cin>>cash;  
  
    if(cash>=sum)  
        cout<<"\n\t\t\tTotal cash repaid: "<<cash-sum<<'\n';  
          
    else  
    {   cout<<"\n\t\t\tCash given is less than total amount!!!";  
  
    goto pay;  
    }  
}  
   
  
int passwords()  
{  
  
    char p1,p2,p3;  
  
    cout<<"\n\n\n\n\n\n\t\t\tENTER PASSWORD:        ";  
  
    cin>>p1;  
    cout<<"*";  
    cin>>p2;  
    cout<<"*";  
    cin>>p3;  
    cout<<"*";  
  
    if ((p1=='s'||p1=='S')&&(p2=='R'||p2=='T')&&(p3=='H'||p3=='K'))  
  
        return 1;  
  
    else  
        return 0;  
}  
  
int main()  
{  
    taxgst obj;  
    char opt, ch;  
    int a=1;  
    ifstream fin;  
  
    a==passwords();  
    if(!a)  
    {  
        for(int i=0;i<2;i++)  
        {  
            cout<<"\nWrong password try once more\n";  
            if(passwords())  
            {  
                goto last;  
            }  
            else  
            {  
                cout<<"\n\n\t\t\t Try Again Later....";  
                
                exit(0);  
            }  
  
        }  
        cout<<"\t\t\t All attempts failed............. \n \t\t\t";  
             }  
    else{  
last:;   
     do{  
start:  
    
    cout<<"\n\n\t\t\t------------------------------";  
    cout<<"\n\t\t\t\tBilling System";  
    cout<<"\n\t\t\t------------------------------";  
     cout<<"\n\n\t\t\tOptions Available:        ";  
     cout<<"\n\t\t\t1.\tTo enter new items \n\t\t\t2.\tTo view old BILLS\n\t\t\t3.\tExit\n";  
     cout<<"\n\nEnter your choice       : ";  
     cin>>opt;  
     switch(opt)  
     {  
     case'1':  
         obj.gstcal();  
  
         obj.outputs();  
         goto start;  
     case'2':  
  
         fin.open("HIS.TXT", ios::in);  
         while(fin.get(ch))  
         {  
             cout<<ch;  
         }  
         fin.close();  
  
         goto start;  
     case'3':  
         exit(0);  
     default:  
         cout<<"\a";  
     }  
  
     }while(opt!=3);  
    }  
    return 0;  
}  