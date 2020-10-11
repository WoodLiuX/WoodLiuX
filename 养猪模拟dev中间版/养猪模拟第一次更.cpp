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
//设定前67个猪圈为非黑猪猪圈，后33个猪圈为黑猪猪圈 
//构造猪这一个结构体链表 
int feiheizhujuan;
int heizhujuan; 
struct pig{
	//1为黑猪，2为小花猪，3为大花白猪 
	int zhonglei;
	int growday;
	double weight;
	int number;
   struct	pig *next;
};
//猪圈作为一个类 
class pigsty{
	private:
	int pignumber;
	int isblackpig;

public:
	pig *head;
	//缺省构造 
	pigsty()
	 {pignumber=0;
	  isblackpig=0;
	 head =NULL;
	 }
	 //打印猪圈是否为黑猪圈，打印猪圈里猪的种类和数量 
	void print()
	{
	if(pignumber==0)
	 {cout<<"是空猪圈。"<<endl;
	 return ;
	 }
	 if(isblackpig==1)
	  {cout<<"是黑猪圈,";
	  }
	  if(isblackpig==0) cout<<"不是黑猪圈,";
	  int count1=0,count2=0,count3=0;
	  	pig*p=head;
		while(p){
	if(p->zhonglei==1)count1++;
	if(p->zhonglei==2)count2++;
	if(p->zhonglei==3)count3++;
	p=p->next; 
	}
	if(isblackpig==1)
	 {cout<<"共有"<<count1<<"头黑猪"<<endl;
	 } 
	 if(!isblackpig) 
	 {cout<<"共有"<<count2<<"头小花猪，";
	 cout<<count3<<"头大花白猪"<<endl;
	 }
	} 
		//获得该猪圈的猪总数 
	int getnumber()
	{
	return pignumber;
	}
	//设置某猪圈是否为黑猪圈 
	void setblackpig(int i)
	{isblackpig=i;
	return;
	}
  //猪圈中猪的数量+1
   void addpignumber()
    {pignumber++;
    return;
	 } 
	//返回猪圈里猪的链表的head
	pig*gethead()
	{return head;
	 } 
	 //卖猪
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
	//不止一头猪的情况 
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
	//显示猪圈里所有猪的品种等信息 
	void show()
	{pig*p=head;
	 while(p)
	  {cout<<"编号为"<<p->number;
	  if(isblackpig==1)cout<<"的黑猪："<<endl;
	  else if(p->zhonglei==2)cout<<"的小花猪："<<endl;
	  else cout<<"的大花白猪:"<<endl; 
	  cout<<"体重为"<<p->weight<<"，生长天数为"<<p->growday<<endl; 
	  p=p->next;
	  }
	}
};
//猪进行生长的函数
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
   {cout<<"加猪之后总猪数大于上限，请重新输入！"<<endl;
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
	 if(p->zhonglei==1)//如果是黑猪 
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
	    /*废案 
	   不会再进行调整 {if(blacknumber+1>330)
	   {exblack++;
	   break;
	   }
	  blacknumber+=1;
	   for(int j=67;j<100;j++)//给该黑猪找猪圈 
	 
	    {if(a[j].head==NULL)//空猪圈 
	     {p->next=NULL; 
	      p->number=0; 
		  a[j].head=p;
		  a[j].addpignumber();
		  cout<<"一个空猪圈初始化完毕"; 
		  break;
		 }
		if(a[j].getnumber()>a[j+1].getnumber())
	     {
	     	if(a[j+1].head==NULL)
	     	 {p->next=NULL; 
	      p->number=0; 
		  a[j+1].head=p;
		  a[j+1].addpignumber();
		  		  cout<<"一个空猪圈初始化完毕\\"<<endl; 
		  break;
			 }
			 else//bug p1的值无法访问也无法更改 
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
			 cout<<"出现了"; 
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
    {cout<<"共有"<<exblack<<"只黑猪因为溢出原因没能成功添加"<<endl; 
	}
  if(exnotblack!=0)
    {cout<<"共有"<<exnotblack<<"只非黑猪因为溢出原因没能成功添加"<<endl; 
	}
   } 
    //获取猪的总数量 
	int getallpignumber(pigsty a[])
	 {	int allcount=0;
	for(int i=0;i<100;i++){
		allcount+=a[i].getnumber();
	}
	return allcount;
	 }
	 //查询某一猪圈某头猪的状态
	 void chaxun(pigsty a,int x)
	 {pig*p=a.head;
	 int y=x;
	 if(a.head==NULL)
	  {cout<<"该猪圈没有猪"<<endl;
	  return ; 
	  }
	  while(x--)
	  {p=p->next;
	  if(p==NULL)
	   {cout<<"该编号的猪不存在";
	   return; 
  	  }
      }
	  if(p->zhonglei==1)
	   {cout<<"该猪圈编号为"<<y<<"的猪:"<<"种类为黑猪,体重为"<<p->weight <<"，生长天数为"<<p->growday<<endl;
	   }
	  else if(p->zhonglei==2)cout<<"该猪圈编号为"<<y<<"的猪:"<<"种类为小花猪,体重为"<<p->weight <<"，生长天数为"<<p->growday<<endl;
	  else cout<<"该猪圈编号为"<<y<<"的猪:"<<"种类为大花白猪,体重为"<<p->weight <<"，生长天数为"<<p->growday<<endl;
	 } 
   int main()
   {pigsty a[100];
   double allsellprice=0;
   srand((unsigned)time(NULL));
   addpig(100,a);
   for(int i=0;i<100;i++)
    {cout<<"第"<<i<<"号猪圈" ; 
	a[i].print();
	}
	 cout<<getallpignumber(a);
	   for(int i=0;i<100;i++)
    {if(a[i].head==NULL)
     {continue;
	 }
	cout<<"第"<<i<<"号猪圈" ; 
	a[i].show();
	}
	 chaxun(a[20],0);
	 grow(90,a);
	 cout<<"猪已经生长了九十天"<<endl;
	  for(int i=0;i<100;i++)
    {cout<<"第"<<i<<"号猪圈" ; 
	a[i].show();
	}
	 for(int i=0;i<=99;i++)
	  {
	   allsellprice+=a[i].sellpig();
	  }
	   cout<<"共卖了"<<allsellprice<<"元"<<endl; 
	   cout<<getallpignumber(a);
	   chaxun(a[20],5);
	     grow(90,a);
	   for(int i=0;i<=99;i++)
	  {
	   allsellprice+=a[i].sellpig();
	  }
	   cout<<"共卖了"<<allsellprice<<"元"<<endl; 
	     cout<<getallpignumber(a);
            return 0;
	} 
