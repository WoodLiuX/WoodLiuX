#include<iostream>
#include<fstream>
#include<string.h>
#include<time.h>
#include<stdlib.h>
/*目前的问题
 */ 
using namespace std;
int allpignumber=0;
int blacknumber=0;
int notblacknumber=0;
int bsty=0;
int wsty=0;
int quanjubianliang=0;
//构造猪这一个结构体链表 
int feiheizhujuan;
int heizhujuan; 
struct pig{
	//1为黑猪，2为小花猪，3为大花白猪 
	int zhonglei;
	int growday;
	double weight;
	int number;
	pig *next;
};
//猪圈作为一个类 
class pigsty{
	private:
	int pignumber;
	int isblackpig;
	pig *head;
public:
	//缺省构造 
	pigsty()
	 {pignumber=0;
	  isblackpig=0;
	 head =NULL;
	 }
	 //打印猪圈是否为黑猪圈，打印猪圈里猪的种类和信息 
	void print()
	{if(pignumber==0)
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
	//判断是否为黑猪圈 
	bool isblackzhujuan()
	{if(isblackpig)return 1;
	return 0;
	}
	//设置某猪圈是否为黑猪圈 
	void setblackpig(int i)
	{isblackpig=i;
	return;
	}
	//返回猪圈里猪的链表的head
	pig*gethead()
	{return head;
	 } 
	  
	  //加一头猪 
void addpig(pig*p){
	pignumber++;
	if(head==NULL){
		p->number=0;
		p->next=NULL;
		head=p;
		return ;
	}
	if(head->number!=0){
		p->number=0;
		p->next=head;
		head=p;
		pignumber++;
		return;
	}
	else {
	pig*p1=head,*p2=p1;
	int k=0;
	while(p1->number==k&&p1->next){
		k++;
		p2=p1;
		p1=p1->next;
	}
	if(p1->next==NULL){
		p->number=pignumber;
		p->next=NULL;
		p1->next=p;
	}
	else{
		p->number=k;
		p2->next=p;
		p->next=p1;
	}
} 
}
//加入一头已知种类的猪 (重载） 
  void addpig(int zhonglei){
	pig*p=new pig;
	srand((unsigned)time(NULL));
	p->zhonglei=zhonglei;		
	p->weight=rand()%30+20;
	p->growday=0;
	if(head==NULL){
		p->number=0;
		p->next=NULL;
		head=p;
		pignumber++;
		return;
	}
	if(head->number!=0){
		p->number=0;
		p->next=head;
		head=p;
		pignumber++;
		return;
	}
	else {
	pig*p1=head,*p2=p1;
	int k=0;
	while(p1->number==k&&p1->next){
		k++;
		p2=p1;
		p1=p1->next;
	}
	if(p1->next==NULL){
		p->number=pignumber;
		p->next=NULL;
		p1->next=p;
	}
	else{
		p->number=k;
		p2->next=p;
		p->next=p1;
	}
	pignumber++;
} 
}
//卖猪函数
double sellpig()
{double sellprice=0; 
	if(head==0)
	return 0;
	int day=0,flag=0;
	pig*p=head,*p1=p;
		day=p->growday; 
	while(p){
	
	if(day>=360||p->weight>=75){
		if(pignumber==1){
		setblackpig(0);
		if(isblackzhujuan())
		 {bsty--;
		 blacknumber--;
		 }
		 else 
		 {wsty--;
		 notblacknumber--;
		 }
		head=NULL;
		delete p;
		pignumber--;
		break;
	
	}
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
	p1->next=p->next;
	delete p;
	p=p1->next;
	pignumber--;
	continue;
}
	else if(flag==0){
		flag=1;
		head=p;
	}
	p1=p;
	p=p1->next;
}
return sellprice;
}
 
};
//获取黑猪圈数量 
int getblackpigsty(pigsty a[])
 {int count=0;
 for(int i=0;i<100;i++)
   {if(a[i].isblackzhujuan())
     count++;
   }
   return count;
  } 
  //获取非黑猪圈数量 
int getnotblackpigsty(pigsty a[])
 {int count=0;
 for(int i=0;i<100;i++)
   {if(!a[i].isblackzhujuan())
     count++;
   }
   return count;
  } 
 //猪进行生长的函数
void grow(int days,pigsty a[])
 {srand((unsigned)time(NULL));
	for(int i=0;i<100;i++)
	 {pig*p=a[i].gethead();
	int x=days;
	while(p){
		for(int j=0;j<days;j++)
		{ p->weight+=(rand()%12)*0.1;
	     	p->growday++;
		}
		p=p->next;
            } 
	 }
}
 
//已有猪圈种类的情况下随机生成并且尽可能平均分配猪
void buypig(int m,pigsty a[])
  {if(allpignumber+m>1000)
   {cout<<"加猪会导致猪圈爆满，加猪失败"<<endl;
   return ;
   }
  int average1,average2;
  	   
  for(int i=0;i<m;i++)
   {     
           average1=(blacknumber)/bsty+1;
           average2=(notblacknumber)/wsty+1;
                pig*p;
	         	p=new pig;
	            p->zhonglei=rand()%3+1;
	        	p->weight=rand()%30+20;
            	p->growday=0;
		    for(int j=0;j<100;j++)
		     {if(a[j].gethead()==NULL)
		       {if(p->zhonglei==1)
		        {bsty+=1;
		         p->number=0;
		         p->next=NULL;
		         a[j].addpig(p);
		         a[j].setblackpig(1);
		         blacknumber++;
		         break;
				}
				else 
				{wsty+=1;
				p->number=0;
				p->next=NULL;
				a[j].addpig(p);
				notblacknumber++;
				 break;
				}
			   }
			   else //非空猪圈 
			   {
			   if(p->zhonglei==1&&a[j].isblackzhujuan()&&a[j].getnumber()<=average1&&a[j].getnumber()<=10)
			     {
			      a[j].addpig(p);
			      blacknumber+=1; 
			      break;
				 }
				 if(p->zhonglei!=1&&!a[j].isblackzhujuan()&&a[j].getnumber()<=average2&&a[j].getnumber()<=10)
				   {
				   a[j].addpig(p);
				   notblacknumber+=1; 
				   break;
				   }
			   }

			 } 
			 			  
   }
  } 
void chushihua(pigsty a[])//通过随机数进行初始化 
	  {for(int i=0;i<=99;i++)
	   {  pig*p;
	     	p=new pig;
	        p->zhonglei=rand()%3+1;
	     	p->weight=rand()%30+20;
		    p->growday=0;
		    
		     a[i].addpig(p);
			 if(p->zhonglei==1)
		      {a[i].setblackpig(1);
			  }
		      continue; 
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
	 //获取黑猪总数量
	 int getblacknumber(pigsty a[])
	  {	int blackcount=0;
	for(int i=0;i<100;i++){
	 if(a[i].isblackzhujuan())
	 	blackcount+=a[i].getnumber();
	}
	return blackcount;
	 }
	 //获取非黑猪总数量
	 int getnotblacknumber(pigsty a[])
	  {	int notblackcount=0;
	for(int i=0;i<100;i++){
	 if(!a[i].isblackzhujuan())
	 	notblackcount+=a[i].getnumber();
	}
	return notblackcount;
	 }
	 
	  int main()
	  {srand((unsigned)time(NULL));
	  double allsellprice=0;
	  pigsty a[100];
	  chushihua(a);
	  	  allpignumber=getallpignumber(a);
	  bsty=getblackpigsty(a);
	  wsty=getnotblackpigsty(a);
	  //for(int i=0;i<100;i++)
	  // {if(a[i].isblackzhujuan())
	  //  {blacknumber+=a[i].getnumber();
	//	}
	//	else notblacknumber+=a[i].getnumber();
	 //  }
	  buypig(200,a);
	  for(int i=0;i<100;i++)
	   {cout<<i<<"号猪圈";
	   a[i].print();
	   }
	   cout<<getallpignumber(a);
	  grow(90,a);
	  cout<<"共有"<<getblacknumber(a)<<"头黑猪"<<getnotblacknumber(a)<<"头非黑猪"<<endl; 
	  for(int i=0;i<=99;i++)
	   {
	   allsellprice+=a[i].sellpig();
	   }
	   cout<<"共卖了"<<allsellprice<<"元"<<endl; 
	    cout<<getallpignumber(a)<<endl;
	    for(int i=0;i<100;i++)
	   {cout<<i<<"号猪圈";
	   a[i].print();
	   }
	   buypig(100,a);
	   for(int i=0;i<100;i++)
	   {cout<<i<<"号猪圈";
	   a[i].print();
	   }
	    cout<<"共有"<<getblacknumber(a)<<"头黑猪"<<getnotblacknumber(a)<<"头非黑猪"<<endl; 
	     grow(90,a);
	     for(int i=0;i<=99;i++)
	   {
	   allsellprice+=a[i].sellpig();
	   }
	   cout<<"共卖了"<<allsellprice<<"元"<<endl; 
	   return 0;
	  }
