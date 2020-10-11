#include "mainwindow.h"
#include <QApplication>
#include<iostream>
#include<fstream>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<QDebug>
#include<global.h>
#include<yangzhu.h>
#include<QPushButton>
#include<QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>


QT_CHARTS_USE_NAMESPACE
int argc;
char *argv[100];
//猪进行生长的函数
void grow(int days,pigsty a[])
 {srand((unsigned)time(NULL));
    Day+=days;
    for(int i=0;i<100;i++)
     {
    int x=days;
    while(x--)
    {
        for(int j=0;j<10;j++)
             {
             if(a[i].p[j].havepig)
             {
                double gain=rand()%13*0.1;
                a[i].p[j].weight+=gain;
             }
        }
    }
     for(int j=0;j<10;j++)
     {
         if(a[i].p[j].havepig)
         {
            a[i].p[j].growday+=days;
         }
     }

     }
    if(Day!=0&&Day%90==0)
    {
        double sellprice=sellpig(a);

                        qDebug()<<"本次卖了"<<sellprice<<"元"<<endl;
                        qDebug()<<"总共收入为"<<allsellprice<<"元（含购入成本）"<<endl;
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
{

if(a.p[x].havepig==0)
 { qDebug()<<"该编号的猪不存在"<<endl;
 return ;
 }

 if(a.p[x].zhonglei==1)
  { qDebug()<<"该猪圈编号为"<<x<<"的猪:"<<"种类为黑猪,体重为"<<a.p[x].weight <<"，生长天数为"<<a.p[x].growday<<endl;
  }
 else if(a.p[x].zhonglei==2) qDebug()<<"该猪圈编号为"<<x<<"的猪:"<<"种类为小花猪,体重为"<<a.p[x].weight <<"，生长天数为"<<a.p[x].growday<<endl;
 else  qDebug()<<"该猪圈编号为"<<x<<"的猪:"<<"种类为大花白猪,体重为"<<a.p[x].weight <<"，生长天数为"<<a.p[x].growday<<endl;
}

void xianshi(pigsty a[])
{
    for(int i=0;i<100;i++)
    {
        if(a[i].getnumber()!=0)
        {qDebug()<<"第"<<i<<"号猪圈：";
           a[i].show();
        }
    }
}
 void addpig(int n,pigsty a[])
   { double cost;
     if(getallpignumber(a)+n>1000)
      { qDebug()<<"加猪之后总猪数大于上限，请重新输入！"<<endl;
       return ;
      }
    int baverage,waverage;
    int exblack=0,exnotblack=0;
    for(int i=67;i<100;i++)
     {a[i].setblackpig(1);
     }
    for(int i=0;i<n;i++)
     {
           int zhonglei1=rand()%3+1;
           int weight1=rand()%30+20;
     if(zhonglei1==1)//如果是黑猪
      {if(blacknumber+1>330)
        {exblack++;
        continue;
        }
        blacknumber++;
        if(blacknumber%33==0)
      baverage=blacknumber/33;
      else baverage=blacknumber/33+1;
       for(int j=67;j<100;j++)
        {if(j==99&&a[j].getnumber()>=10)
           {exblack++;
           break;
           }
         if(a[j].getnumber()>=10)
         continue;

        if(a[j].getnumber()<baverage)
         {for(int m=0;m<10;m++)
                 {
                if(a[j].p[m].havepig==1)continue;
                else
                {
                    a[j].p[m].havepig=1;
                    a[j].p[m].growday=0;
                    a[j].p[m].zhonglei=1;
                    a[j].p[m].weight=weight1;
                     a[j].addpignumber();
                     cost+=a[j].p[m].weight*30;
                }
                break;
            }
            break;
         }
        }
       }

      else
       {
       if(smallnumber+bignumber+1>670)
        {exnotblack++;
        continue;
        }
       if(zhonglei1==2)
        smallnumber++;
       else if(zhonglei1==3)
           bignumber++;
        if((smallnumber+bignumber)%67==0)
      waverage=(smallnumber+bignumber)/67;
      else waverage=(smallnumber+bignumber)/67+1;
       for(int j=0;j<67;j++)
        {if(j==66&&a[j].getnumber()>=10)
           {exnotblack++;
           break;
           }
         if(a[j].getnumber()>=10)
         continue;

        if(a[j].getnumber()<waverage)
         {for(int m=0;m<10;m++)
            {
           if(a[j].p[m].havepig==1)continue;
           else
           {
               a[j].p[m].havepig=1;
               a[j].p[m].growday=0;
               a[j].p[m].zhonglei=zhonglei1;
               a[j].p[m].weight=weight1;
                a[j].addpignumber();
                if(zhonglei1==2)cost+=a[j].p[m].weight*14;
                else cost+=a[j].p[m].weight*12;
           }
           break;
       }
              break;
         }
        }
       }
       continue;
     }
   if(exblack!=0)
    { qDebug()<<"共有"<<exblack<<"只黑猪因为溢出原因没能成功添加"<<endl;
    }
  if(exnotblack!=0)
    { qDebug()<<"共有"<<exnotblack<<"只非黑猪因为溢出原因没能成功添加"<<endl;
    }
  allsellprice-=cost;
  QFile file;
  file.setFileName("../sold_data.txt");
  bool isOK = file.open(QIODevice::Append);
  if(true == isOK)
  {
      QTextStream stream(&file);
      stream.setCodec("UTF-8");
      stream<<"Day"<<Day<<":\n";
      stream<<"BUY:"<<n-exblack-exnotblack<<"pigs\n";
      stream<<"COST:"<<cost<<"RMB\n";
      stream<<"Total income:"<<allsellprice<<"RMB\n";
      file.close();
  }
  else
      qDebug()<<"fail";
   }

 double sellpig(pigsty a[])//卖猪函数
  {  int sellnumber=0;
     double sellprice=0;
     for(int i=0;i<100;i++)
     {
         if(a[i].getnumber()==0)
         continue;
          for(int j=0;j<10;j++)
               {
              if(a[i].p[j].havepig==1)
              {
                  if(a[i].p[j].growday>=360||a[i].p[j].weight>=75)
                 {

                      if(a[i].p[j].zhonglei==1)
                      {
                      sellprice+=30*a[i].p[j].weight;
                      blacknumber--;
                      }
                     else if(a[i].p[j].zhonglei==2)
                      {
                      sellprice+=14*a[i].p[j].weight;
                       smallnumber--;
                      }
                     else if(a[i].p[j].zhonglei==3)
                      {
                      sellprice+=12*a[i].p[j].weight;
                       bignumber--;
                      }

                      a[i].minuspignumber();
                     a[i].p[j].havepig=0;
                     sellnumber++;
                   }

               }
                }
     }
     allsellprice+=sellprice;
     QFile file;
     file.setFileName("../sold_data.txt");
     bool isOK = file.open(QIODevice::Append);
     if(true == isOK)
     {
         QTextStream stream(&file);
         stream.setCodec("UTF-8");
         stream<<"Day"<<Day<<":\n";
         stream<<"Sell:"<<sellnumber<<"pigs\n";
         stream<<"Earn:"<<sellprice<<"RMB\n";
         stream<<"Total income:"<<allsellprice<<"RMB\n";
         file.close();
     }
     else
         qDebug()<<"fail";

     return sellprice;
  }
 void reset(pigsty a[])
 {for(int i=0;i<100;i++)
     {
         a[i].pignumber=0;
         for(int j=0;j<10;j++)
         {
             a[i].p[j].weight=0;
             a[i].p[j].zhonglei=0;
             a[i].p[j].growday=0;
             a[i].p[j].havepig=0;
         }
     }
     blacknumber=0;
     allsellprice=0;
     smallnumber=0;
     bignumber=0;
     Day=0;
 }

int main(int argc, char *argv[])
{
    pigsty a[100];
   srand((unsigned)time(NULL));

    QApplication b(argc, argv);
    MainWindow w;

    w.setWindowTitle("养猪程序");
    w.show();
    return b.exec();
}
