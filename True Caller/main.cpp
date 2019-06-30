#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fstream>

using namespace std;

struct node
{
    node * next;
    char* num;
    int age;
    char* name;
    int data;
    char* city;

};

int hashfunction(char * num);
void show(node * curr);
void exit();
node * insertNumber(struct node * hashtable,char *num,char* name,int age,char* city);
void admin(node * hashtable);

int insertnumbers(node * hashtable)
{

      cout<<'\n'<<'\n'<<'\n'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<"MAIN MENU"<<'\n'<<'\t'<<'\t'<<'\t'<<'\t'<<"=====================\n\t\t\t\t[1] to proceed \n\t\t\t\t[2] Admin \n\t\t\t\t[3] Exit\n\t\t\t\t====================\n\t\t\t\t";

    hashtable=insertNumber(hashtable,"03340265566","Zohaib",20,"Islamabad");
    hashtable=insertNumber(hashtable,"03340265506","moiz",20,"karachi");
    hashtable=insertNumber(hashtable,"03340265516","shaheer",20,"peshawar");
    hashtable=insertNumber(hashtable,"03340265523","hamza",20,"gotki");
    hashtable=insertNumber(hashtable,"03345952584","azmeer",20,"al asif");

    hashtable=insertNumber(hashtable,"03232168122","sharf",20,"karachi");
    hashtable=insertNumber(hashtable,"03335633321","saad",20,"landhi");
    hashtable=insertNumber(hashtable,"03340265561","shoaib",20,"quetta");
    hashtable=insertNumber(hashtable,"03340265569","yoyo",20,"lahore");
    hashtable=insertNumber(hashtable,"03340265568","huaa",20,"sialkot");
    hashtable=insertNumber(hashtable,"03340265565","ajdh",20,"abbotabad");
    hashtable=insertNumber(hashtable,"03340265567","hgs",20,"hyderabad");
    hashtable=insertNumber(hashtable,"03340265564","soso",20,"quetta");

    cout<<"Enter Your Choice\n\n\t\t\t\t";
    int a;
    cin>>a;
    system("cls");
    return a;

}

node * insertNumber(struct node * hashtable,char *num,char* name,int age,char* city)
{
   // struct node * newnode;

   node * newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->num= new char[15];
    newnode->num=num;
    newnode->name= new char[15];
    newnode->name=name;
    newnode->age=age;
    newnode->city=new char[15];
    newnode->city=city;
    int index;
    index=hashfunction(num);
    if(hashtable[index].next==NULL)
    {
        hashtable[index].data=index;

        hashtable[index].next=newnode;
    }
    else
    {
        node * curr=hashtable[index].next;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
       curr->next=newnode;
    }
    return(hashtable);



}

int hashfunction(char * num)
{

    char temp;
     char length=strlen(num);
     temp=num[length-1];
     int len;
     len=(int)temp;
     int index=len%10;
     return index;
}

void search(node * hashtable)
{
    //node * curr=hashtable;
    char* num= new char[11];
    int j=0;
    cout<<"\n\n\t\t\t\tEnter Number U Want To Know"<<'\t'<<'\t'<<'\t'<<'\t'<<endl;
     cout<<"\t\t\t\t";cin>>num;
    char temp;
    char len=strlen(num);
    temp=num[len-1];
    int length=int(len);
    if(length!=11)
    {
        cout<<"\n\t\t\t\tPlease Enter Correct Number\n\t\t\t\t"<<endl;
        //cout<<" \n\t\t\t\t";
        cout<<"\n\t\t\t\tpress 1 to proceed or 2 exit\n\t\t\t\t";
        int x;
        cin>>x;
        system("cls");
        if(x==1)
        {
        search(hashtable);
        }
        exit();

    }

    length=temp%10;
    int index=0;
    while(hashtable[index].data!=length)
    {
        index++;
    }
    struct node * tem;
    tem=hashtable[index].next;
    while(tem!=NULL)
    {
      for(int i=0;i<11;i++)
      {
    if(tem->num[i]==num[i])
    {
        if(i>=10)
        {

             show(tem);

             cout<<"\n\t\t\t\t[1] How to Report This Number\n\t\t\t\t[2] Exit \n\t\t\t\t[3] Want To Search Another Number\n\t\t\t\t";
             int x;
             cin>>x;
             switch(x)
             {
             case 1:
                 {
                ifstream infile;
                infile.open("block.txt");
                if(infile.fail())
                {
                    cout<<"error opening file"<<endl;
                    exit(1);
                }
                string characters[50];
                while(!infile.eof())
                {
                    for(int i=0;i<50;i++)
                    {
                    infile>>characters[i];
                }
                }
                cout<<"\n";
                for(int i=0;i<50;i++)
                {
             cout<<characters[i]<<" ";
             }
             cout<<"\n\n\n";
                 }
             case 2:
                {
             exit();

             }
             case 3:
                {
                    search(hashtable);
                    exit();
                }
        }
        }
    }
    else
    {
        if(tem->num[i]!=num[i])
        {
            break;
        }
    }
      }

    tem=tem->next;
     if(tem==NULL)
    {
        cout<<"\n\t\t\t\tNumeber Not Found\n\t\t\t\t"<<endl;
        cout<<"\n\t\t\t\tpress 1 to proceed or 2 exit\n\t\t\t\t";
        int x;
        cin>>x;
        system("cls");
        if(x==1)
        {
        search(hashtable);
        }
        else
        {
            exit();
        }
    }



    }


}

void addNumber(node * hashtable)
{
    hashtable=insertNumber(hashtable,"03214567890","raheem",22,"fasilabad");
    cout<<"\n\n\t\t\t\tRegistered New Number\n";
}

void show(node * curr)
{
    cout<<"\n\n\t\t\t\tNumber:\t\t"<<curr->num;
    cout<<"\n\t\t\t\tName:\t\t"<<curr->name;
    cout<<"\n\t\t\t\tAge:\t\t"<<curr->age;
    cout<<"\n\t\t\t\tcity:\t\t"<<curr->city<<endl;

}

void display(node * hashtable,int size)
{
	for (int i = 0; i < size; i++)
	{
	    struct node *curr;
	    curr=hashtable[i].next;
		if (hashtable[i].data != -1)
		{
		//    curr=hashtable[i].next;
		    while (curr != NULL)
			{
				cout << curr->num << "->";
				cout << curr->name << "->";
				cout << curr->age << "->";
				cout<< curr->city <<"    ";

				curr = curr->next;
            }
			cout << endl << "||" << endl;
		}
}

}
void admin(node * hashtable,int size)
{
 password:
               cout<<"\n\n\t\t\t\tAdmin Password\n\t\t\t\t";
               int x;
               cin>>x;
               if(x==123)
               {
                   cout<<"\n\n\t\t\t\tAccess Granted";
                  admin:
                   cout<<"\n\t\t\t\t[1] Display All Numbers\n\n\t\t\t\t[2] Register A New Number\n\n\t\t\t\t[3] Exit\n\n\t\t\t\t";
                   int y;
                   cin>>y;
                   system("cls");
                   if(y==1)
                   {
                       display(hashtable,size);
                       goto admin;
                   }
                   else
                   {
                       addNumber(hashtable);
                       display(hashtable,size);

                   }

               }
               else
               {
                   cout<<"\n\n\t\t\t\tIncorrect Password";
                   goto password;
               }
}
void exit()
{
    exit(EXIT_SUCCESS);
}


int main()
{

    int size=10,choice;
    struct node * hashtable= new node[size];
    for(int i=0;i<size;i++)
    {
        hashtable[i].next=NULL;
        hashtable[i].data=-1;
    }

     choice=insertnumbers(hashtable);
     switch(choice)
     {
         case 1:
         {
    search(hashtable);
         }
         case 2:
            {
                admin(hashtable,size);



            }

         default:
         exit();
     }
}
