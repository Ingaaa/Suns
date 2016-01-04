#include<fstream>
#include <string.h>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

fstream fin ("suns.in.txt", ios::in);
fstream fout ("suns.out.txt", ios::out);
struct node
{
    int id;
    node *next;
};

struct node_s
{
    int id;
    char vards[50];
    node_s *next;
    node *vecaks_first;
    char dzivs;
};
struct node_pos
{
    node_s *first;
};

class saraksts
{
    public:
    node *first;
    node *last;
public:
     saraksts()
    {
        first=NULL;
        last=NULL;
    };
    void add_element (int num)
    {
        node * P=new node;
        P->id=num;
        P->next=NULL;
        if (first == NULL) first = P;
        else last->next = P;
        last = P;
    };
     void print()
    {
        node * N=new node;
        N=first;
        while (N!=NULL)
        {

            N=N->next;
        }
    }
    void sort_izeja ()
    {
        if((first!=NULL) && (first->next!=NULL))
        {
            node *p=first;
            node *pasreiz=first;
            node *ieprieks=NULL;
            node *temp=NULL;
            bool a=false;
            short int skaits=0;

            while (p!=NULL)
            {
                skaits++;
                p=p->next;
            }
            for (int i=0; i<skaits; i++)
            {
                while (pasreiz->next !=NULL)
                {
                    temp=pasreiz->next;
                    if ((pasreiz->id) > (temp->id))
                    {
                        a=true;
                        pasreiz->next=temp->next;
                        temp->next=pasreiz;
                        if (ieprieks !=NULL) ieprieks->next=temp;
                        ieprieks=temp;
                        if (first==pasreiz) first=temp;
                        if(pasreiz->next==NULL) last=pasreiz;

                    }
                    else
                    {
                        ieprieks=pasreiz;
                        pasreiz=pasreiz->next;
                    }
                }

                if (a==false) break;
                else
                {
                    ieprieks=NULL;
                    pasreiz=first;
                    a=false;
                }
            }
        }
    }

};
int myhash(int id)
{
    return id%100;
}
    bool findId(int index, node_pos**arr, int id)
    {
        if (arr[index]->first==NULL)
        {
            return false;
        }
        else
        {
           node_s *V=new node_s;
            V=arr[index]->first;
            while(V!=NULL)
            {
                if (V->id==id)
                {
                    return true;
                }
                V=V->next;
            }
            return false;
        }
    }
    bool findId2(int index, node_pos**arr, int id)
    {
        if (arr[index]->first==NULL)
        {
            return false;
        }
        else
        {
           node_s *V=new node_s;
            V=arr[index]->first;
            while(V!=NULL)
            {
                if (V->id==id)
                {
                    V->dzivs='N';
                    return true;
                }
                V=V->next;
            }
            return false;
        }
    }
    bool findId3(int index, node_pos**arr, int id, bool &dzivs)
    {
        if (arr[index]->first==NULL)
            {
            return false;
            }
        else
        {
           node_s *V=new node_s;
            V=arr[index]->first;
            while(V!=NULL)
            {
                if (V->id==id)
                {
                    if (V->dzivs=='J') fout<<"\""<<V->vards<<"\""<<endl;
                    else fout<<"dead - "<<"\""<<V->vards<<"\""<<endl;
                    return true;
                }
                V=V->next;
            }
            return false;
        }
    }
    bool findId4(int index, node_pos**arr, int id, node_s*&V)
    {
        if (arr[index]->first==NULL)
            {
            return false;
            }
        else
        {

            V=arr[index]->first;
            while(V!=NULL)
            {
                if (V->id==id)
                {
                    return true;
                }
                V=V->next;
            }
            return false;
        }
    }
void    findFullName(char *vards, node_s *T, node_s*N, node_pos**arr)
    {
        int i=0;
        int a=0;
        int j=0;
        bool stop=false;
        char temp_vards[50]={'\0'};
        if (strlen(vards)<50)
        {
            while ((T->vards[i]!='\0' || N->vards[j]!='\0')&& stop==false)
            {

                if (T->vards[i]!='\0')
                {
                temp_vards[0]='\0';
                a=0;
                while (T->vards[i]!=' ' && T->vards[i]!='\0')
                {
                    temp_vards[a]=T->vards[i];
                    i++;
                    a++;
                    temp_vards[a]='\0';


                   if (T->vards[i]==' ' && strstr(vards, temp_vards)!=NULL){i++; temp_vards[0]='\0'; a=0;}
                }
                if (T->vards[i]!='\0')i++;
                //temp_vards[a]='\0';
                if ((strlen(vards)+strlen(temp_vards))<=50)
                {
                    if(strstr(vards, temp_vards)==NULL)
                    {

                    strcat(vards, " ");
                    strcat(vards, temp_vards);

                    }
                }
                else stop=true;
                }


                if (N->vards[j]!='\0')
                {

                temp_vards[0]='\0';
                a=0;
                while ((N->vards[j]!=' ' && N->vards[j]!='\0') && stop==false)
                {
                    temp_vards[a]=N->vards[j];
                    j++;
                    a++;
                    temp_vards[a]='\0';
                   if (N->vards[j]==' ' && strstr(vards, temp_vards)!=NULL){j++; temp_vards[0]='\0'; a=0;}
                }
                if (N->vards[j]!='\0')j++;
                //temp_vards[a]='\0';
                if ((strlen(vards)+strlen(temp_vards))<=50)
                {
                    if(strstr(vards, temp_vards)==NULL)
                    {

                    strcat(vards, " ");
                    strcat(vards, temp_vards);

                    }
                }
                else stop =true;

            }

        }
        }
    }
    void    findFullName1(char *vards, node_s *T, node_pos**arr)
    {
        int i=0;
        int a=0;
        bool stop=false;
        char temp_vards[50]={'\0'};
        if (strlen(vards)<50)
        {
            while (T->vards[i]!='\0' && stop==false)
            {
                temp_vards[0]='\0';
                a=0;
                while (T->vards[i]!=' ' && T->vards[i]!='\0')
                {
                    temp_vards[a]=T->vards[i];
                    i++;
                    a++;
                    temp_vards[a]='\0';

                   if (T->vards[i]==' ' && strstr(vards, temp_vards)!=NULL){i++; temp_vards[0]='\0'; a=0;}
                }
                if (T->vards[i]!='\0')i++;
                if ((strlen(vards)+strlen(temp_vards))<=50)
                {
                    if(strstr(vards, temp_vards)==NULL)
                    {
                    strcat(vards, " ");
                    strcat(vards, temp_vards);
                    }
                }
                else stop=true;
                }

        }
        }



int main ()
{
    char komanda='\0';
    int id=0, index=0, parent1 =0, parent2=0, countt=0, skait=100000, k=0, c=0, a=0, index1=0, index2=0;
    bool exists1=true;
    bool exists2=true;
    bool dzivs = false;
    saraksts byName;
    node_s *S=new node_s;
    node_s *P1=new node_s;
    node_s *P2=new node_s;
    node *Temp=new node;
    char pilnais_vards[50]={'\0'};
    node_pos *arr[1201];
    for (int i=0; i<1201; i++)
    {
        arr[i]=new node_pos;
        arr[i]->first=NULL;
    }
    fin>>komanda;
    while (fin)
    {

        if (komanda=='R')
        {

            fin>>id>>pilnais_vards;

            index=myhash(id);
            if (findId(index, arr, id)==false)
            {
                node_s *V= new node_s;
            k=0;
            c=0;
            while (pilnais_vards[k]!='\0')
            {
                if(pilnais_vards[k]=='\"')c++;
                k++;
            }

            if (c==2)
            {
            a=1;
            while(pilnais_vards[a]!='\"')
            {
                V->vards[a-1]=pilnais_vards[a];
                a++;
            }
            V->vards[a-1]='\0';
            }
            else
            {

                a=1;
                while(pilnais_vards[a]!='\0')
                {
                    V->vards[a-1]=pilnais_vards[a];
                    a++;
                }
               // V->vards[a-1]=' ';
                V->vards[a-1]='\0';

                fin>>pilnais_vards;

                while(strchr(pilnais_vards, '\"')==NULL)
                {

                    strcat(V->vards, " ");
                    strcat(V->vards, pilnais_vards);
                    fin>>pilnais_vards;

                }
                a=0;
                while(pilnais_vards[a]!='\"')
                {

                    a++;
                }
            pilnais_vards[a]='\0';

            strcat(V->vards, " ");
            strcat(V->vards, pilnais_vards);


            }

            V->id=id;

            V->dzivs='J';
            V->next=NULL;
            if (arr[index]->first==NULL)
            {
                arr[index]->first=V;
            }
            else
            {
                V->next=arr[index]->first;
                arr[index]->first=V;

            }
            fout<<"ok"<<endl;
            }

            else
            {

                a=0;
                c=0;
                while(pilnais_vards[a]!='\0')
                {
                    if(pilnais_vards[a]=='\"') c++;
                    a++;
                }
               if (c!=2)
                {
                    fin>>pilnais_vards;
                    while(strchr(pilnais_vards, '\"')==NULL)
                {
                    fin>>pilnais_vards;
                }
                }


                fout<<"no"<<endl;
            }

        }
        if (komanda=='D')
        {

            fin>>id;

            index=myhash(id);
            if (findId2(index, arr, id)==true) fout<<"ok"<<endl;
            else fout<<"no"<<endl;
        }


        if (komanda=='I')
        {
            dzivs = false;
            fin>>id;
            index=myhash(id);


                if (findId3(index, arr, id, dzivs)==true)
                {

                }
                else fout<<"no"<<endl;





        }
        if (komanda=='F')
        {

            fin>>pilnais_vards;

           // pilnais_vards[51]='\0';
                        //findName(byName.first, arr, pilnais_vards);
            for (int i=0; i<1201; i++)
            {

                if (arr[i]->first!=NULL)
                {

                    S=arr[i]->first;
                    while(S!=NULL)
                    {
                        if (strstr(S->vards, pilnais_vards)!=NULL)
                        {byName.add_element(S->id);}
                        S=S->next;
                    }
                }
            }

            c=0;
            byName.sort_izeja();
            Temp=byName.first;
            if (Temp!=NULL)
            {
              while(Temp!=NULL)
            {
                c++;
                Temp=Temp->next;
            }



            Temp=byName.first;

             fout<<c;
              while(Temp!=NULL)
            {
                fout<<" "<<Temp->id;
                Temp=Temp->next;
            }
            fout<<endl;
            while(byName.first!=NULL)
            {
                Temp=byName.first->next;
                delete byName.first;
                byName.first=Temp;
            }
            }
            else fout<<"0"<<endl;

        }

        if (komanda=='N')
        {
        exists1=true;
        exists2=true;
        index1=0;
        index2=0;


            fin>>parent1>>parent2>>countt;

                if (parent1!=0)
                {
                    index1=myhash(parent1);
                    if (findId4(index1, arr, parent1, P1)==true) exists1=true;
                    else exists1=false;
                }
                if (parent2!=0)
                {
                    index2=myhash(parent2);
                    if (findId4(index2, arr, parent2, P2)==true) exists2=true;
                    else exists2=false;
                }
                if (exists1==true && exists2==true)
                {

            for (int i=0; i<countt; i++)
            {
                fin>>pilnais_vards;
                index=myhash(skait);
                node_s *V=new node_s;
                V->id=skait;
                V->dzivs='J';
                V->next=NULL;
                strcpy(V->vards, pilnais_vards);
                if (parent1!=0 && parent2!=0) findFullName(V->vards, P1, P2, arr);
                if (parent1==0 && parent2!=0) findFullName1(V->vards, P2, arr);
                if (parent1!=0 && parent2==0) findFullName1(V->vards, P1, arr);
                if (arr[index]->first==NULL)
                {
                    arr[index]->first=V;
                }
                else
                {
                    V->next=arr[index]->first;
                    arr[index]->first=V;

                }
                fout<<V->id<<" "<<"\""<<V->vards<<"\""<<endl;

            skait++;
            }
                }
                else
                {
                    fout<<"no"<<endl;
                for (int i=0; i<countt; i++)
            {
                fin>>pilnais_vards;
            }
                }


        }
        if (komanda=='Q')
        {

            fout<<"quit"<<endl;
            return 0;
        }


        fin>>komanda;
    }

   fin.close();
   fout.close();
    return 0;
}
