#include<iostream>
#include<fstream>
#include<string.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
int allpignumber=0;
int blacknumber=0;
int notblacknumber=0;
int quanjubianliang=0;
//�趨ǰ67����ȦΪ�Ǻ�����Ȧ����33����ȦΪ������Ȧ 
//��������һ���ṹ������ 
int feiheizhujuan;
int heizhujuan; 
struct pig{
	//1Ϊ����2ΪС����3Ϊ�󻨰��� 
	int zhonglei;
	int growday;
	double weight;
	int number;
   struct	pig *next;
};
//��Ȧ��Ϊһ���� 
class pigsty{
	private:
	int pignumber;
	int isblackpig;

public:
	pig *head;
	//ȱʡ���� 
	pigsty()
	 {pignumber=0;
	  isblackpig=0;
	 head =NULL;
	 }
	 //��ӡ��Ȧ�Ƿ�Ϊ����Ȧ����ӡ��Ȧ�������������� 
	void print()
	{
	if(pignumber==0)
	 {cout<<"�ǿ���Ȧ��"<<endl;
	 return ;
	 }
	 if(isblackpig==1)
	  {cout<<"�Ǻ���Ȧ,";
	  }
	  if(isblackpig==0) cout<<"���Ǻ���Ȧ,";
	  int count1=0,count2=0,count3=0;
	  	pig*p=head;
		while(p){
	if(p->zhonglei==1)count1++;
	if(p->zhonglei==2)count2++;
	if(p->zhonglei==3)count3++;
	p=p->next; 
	}
	if(isblackpig==1)
	 {cout<<"����"<<count1<<"ͷ����"<<endl;
	 } 
	 if(!isblackpig) 
	 {cout<<"����"<<count2<<"ͷС����";
	 cout<<count3<<"ͷ�󻨰���"<<endl;
	 }
	} 
		//��ø���Ȧ�������� 
	int getnumber()
	{
	return pignumber;
	}
	//����ĳ��Ȧ�Ƿ�Ϊ����Ȧ 
	void setblackpig(int i)
	{isblackpig=i;
	return;
	}
  //��Ȧ���������+1
   void addpignumber()
    {pignumber++;
    return;
	 } 
	//������Ȧ����������head
	pig*gethead()
	{return head;
	 } 
	 //����
	double sellpig()
     {double sellprice=0;
	if(head==NULL)
	return sellprice;
	 pig*p=head,*p1=p;
	 while(p)
	  {if(p->growday>=360||p->weight>=75)
	   {if(pignumber==1)
	    {head=NULL;
	if(p->zhonglei==1){
	sellprice+=30*p->weight;
	blacknumber--;
                      }
	if(p->zhonglei==2){
	sellprice+=14*p->weight;
	 notblacknumber--;
	                  }
	if(p->zhonglei==3){
	sellprice+=12*p->weight;
	 notblacknumber--;
	                  }
		delete p;
		pignumber--;
		break;
		}
	//��ֹһͷ������ 
	if(p->zhonglei==1){
	sellprice+=30*p->weight;
	blacknumber--;
	}
	if(p->zhonglei==2){
	sellprice+=14*p->weight;
	 notblacknumber--;
	}
	if(p->zhonglei==3){
	sellprice+=12*p->weight;
	 notblacknumber--;
	}
//	p1->next=p->next;
	pig *p2=p;
	while(p2)
	 {p2->number--;
	 p2=p2->next;
	 }
	 p1=p1->next;
	delete p;
	p=p1;
	pignumber--;
	continue;
		} 
		 p=p->next;
	  }
        return sellprice;
	 } 
	 //
	double getallweight()
	{double x=0;
	pig*p=head;
	while(p)
	 {x+=p->weight;
	 p=p->next;
	 }
	 return x;
	}
	//��ʾ��Ȧ���������Ʒ�ֵ���Ϣ 
	void show()
	{pig*p=head;
	 while(p)
	  {cout<<"���Ϊ"<<p->number;
	  if(isblackpig==1)cout<<"�ĺ���"<<endl;
	  else if(p->zhonglei==2)cout<<"��С����"<<endl;
	  else cout<<"�Ĵ󻨰���:"<<endl; 
	  cout<<"����Ϊ"<<p->weight<<"����������Ϊ"<<p->growday<<endl; 
	  p=p->next;
	  }
	}
};
//����������ĺ���
void grow(int days,pigsty a[])
 {srand((unsigned)time(NULL));
	for(int i=0;i<100;i++)
	 {pig*p=a[i].head;
	int x=days;
	while(p){
		for(int j=0;j<days;j++)
		{ p->weight+=(rand()%13)*0.1;
	     	p->growday++;
		}
		p=p->next;
            } 
	 }
}
 void addpig(int n,pigsty a[])
   {if(allpignumber+n>1000)
   {cout<<"����֮���������������ޣ����������룡"<<endl;
   return ;
	} 
    int baverage,waverage;
    int exblack=0,exnotblack=0;
    for(int i=67;i<100;i++)
     {a[i].setblackpig(1);
	 }
	for(int i=0;i<n;i++)
	 {	pig*p=new pig;
	        p->zhonglei=rand()%3+1;
	     	p->weight=rand()%30+20;
		    p->growday=0;
	 if(p->zhonglei==1)//����Ǻ��� 
	  {if(blacknumber+1>330)
	    {exblack++;
	    continue;
		}
		blacknumber++;
		if(blacknumber%33==0)
	  baverage=blacknumber/33;
	  else baverage=blacknumber/33+1;
	   for(int j=67;j<100;j++)
	    {if(a[j].head==NULL)
	     {p->next=NULL; 
	      p->number=0; 
		  a[j].head=p;
		  a[j].addpignumber(); 
		  break;
		 }
		 if(a[j].getnumber()>=10)
		 continue;
		 if(j==99&&a[j].getnumber()>=10)
		  {exblack++;
		  break;
		  }
		if(a[j].getnumber()<baverage)
	     {pig*p1=a[j].head;
	      while(p1->next)
		    {p1=p1->next ;
			} 
			p1->next=p;
			p->number= a[j].getnumber();
			p->next=NULL;
			a[j].addpignumber(); 
			break;
		 }
		}
	   } 
	    /*�ϰ� 
	   �����ٽ��е��� {if(blacknumber+1>330)
	   {exblack++;
	   break;
	   }
	  blacknumber+=1;
	   for(int j=67;j<100;j++)//���ú�������Ȧ 
	 
	    {if(a[j].head==NULL)//����Ȧ 
	     {p->next=NULL; 
	      p->number=0; 
		  a[j].head=p;
		  a[j].addpignumber();
		  cout<<"һ������Ȧ��ʼ�����"; 
		  break;
		 }
		if(a[j].getnumber()>a[j+1].getnumber())
	     {
	     	if(a[j+1].head==NULL)
	     	 {p->next=NULL; 
	      p->number=0; 
		  a[j+1].head=p;
		  a[j+1].addpignumber();
		  		  cout<<"һ������Ȧ��ʼ�����\\"<<endl; 
		  break;
			 }
			 else//bug p1��ֵ�޷�����Ҳ�޷����� 
		    {pig *p1=a[j+1].head;
		    int x=a[j+1].getnumber();
	       for(int m=0;m<x;m++)
	        {p1=p1->next; 
	       cout<<"xx";
		    }
			p->number= a[j+1].getnumber();
			p->next=NULL;
			cout<<p->number; 
			p1->next=p;//?
			 cout<<"������"; 
			a[j+1].addpignumber();
			break; 	
		    }
		 }
		 if(j==98)
		 {pig*p1=a[67].head;
	      while(p1->next)
		    {p1=p1->next ;
			} 
			p1->next=p;
			p->number= a[67].getnumber();
			p->next=NULL;
			a[67].addpignumber(); 
			break; 
		 }
		 }
		}*/
	  else
	   {   
	   if(notblacknumber+1>670)
	    {exnotblack++;
	    continue;
		}
		notblacknumber++;
		if(notblacknumber%67==0)
	  waverage=notblacknumber/67;
	  else waverage=notblacknumber/67+1;
	   for(int j=0;j<67;j++)
	    {if(a[j].head==NULL)
	     {p->next=NULL; 
	      p->number=0; 
		  a[j].head=p;
		  a[j].addpignumber(); 
		  break;
		 }
		 if(a[j].getnumber()>=10)
		 continue;
		 if(j==66&&a[j].getnumber()>=10)
		  {exnotblack++;
		  break;
		  }
		if(a[j].getnumber()<waverage)
	     {pig*p1=a[j].head;
	      while(p1->next)
		    {p1=p1->next ;
			} 
			p1->next=p;
			p->number= a[j].getnumber();
			p->next=NULL;
			a[j].addpignumber(); 
			break;
		 }
		}
	   }
	   continue;
	 }
   if(exblack!=0)
    {cout<<"����"<<exblack<<"ֻ������Ϊ���ԭ��û�ܳɹ����"<<endl; 
	}
  if(exnotblack!=0)
    {cout<<"����"<<exnotblack<<"ֻ�Ǻ�����Ϊ���ԭ��û�ܳɹ����"<<endl; 
	}
   } 
    //��ȡ��������� 
	int getallpignumber(pigsty a[])
	 {	int allcount=0;
	for(int i=0;i<100;i++){
		allcount+=a[i].getnumber();
	}
	return allcount;
	 }
	 //��ѯĳһ��Ȧĳͷ���״̬
	 void chaxun(pigsty a,int x)
	 {pig*p=a.head;
	 int y=x;
	 if(a.head==NULL)
	  {cout<<"����Ȧû����"<<endl;
	  return ; 
	  }
	  while(x--)
	  {p=p->next;
	  if(p==NULL)
	   {cout<<"�ñ�ŵ�������";
	   return; 
  	  }
      }
	  if(p->zhonglei==1)
	   {cout<<"����Ȧ���Ϊ"<<y<<"����:"<<"����Ϊ����,����Ϊ"<<p->weight <<"����������Ϊ"<<p->growday<<endl;
	   }
	  else if(p->zhonglei==2)cout<<"����Ȧ���Ϊ"<<y<<"����:"<<"����ΪС����,����Ϊ"<<p->weight <<"����������Ϊ"<<p->growday<<endl;
	  else cout<<"����Ȧ���Ϊ"<<y<<"����:"<<"����Ϊ�󻨰���,����Ϊ"<<p->weight <<"����������Ϊ"<<p->growday<<endl;
	 } 
   int main()
   {pigsty a[100];
   double allsellprice=0;
   srand((unsigned)time(NULL));
   addpig(100,a);
   for(int i=0;i<100;i++)
    {cout<<"��"<<i<<"����Ȧ" ; 
	a[i].print();
	}
	 cout<<getallpignumber(a);
	   for(int i=0;i<100;i++)
    {if(a[i].head==NULL)
     {continue;
	 }
	cout<<"��"<<i<<"����Ȧ" ; 
	a[i].show();
	}
	 chaxun(a[20],0);
	 grow(90,a);
	 cout<<"���Ѿ������˾�ʮ��"<<endl;
	  for(int i=0;i<100;i++)
    {cout<<"��"<<i<<"����Ȧ" ; 
	a[i].show();
	}
	 for(int i=0;i<=99;i++)
	  {
	   allsellprice+=a[i].sellpig();
	  }
	   cout<<"������"<<allsellprice<<"Ԫ"<<endl; 
	   cout<<getallpignumber(a);
	   chaxun(a[20],5);
	     grow(90,a);
	   for(int i=0;i<=99;i++)
	  {
	   allsellprice+=a[i].sellpig();
	  }
	   cout<<"������"<<allsellprice<<"Ԫ"<<endl; 
	     cout<<getallpignumber(a);
            return 0;
	} 
