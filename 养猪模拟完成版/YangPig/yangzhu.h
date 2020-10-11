#ifndef YANGZHU_H
#define YANGZHU_H

#endif // YANGZHU_H
#include "mainwindow.h"
#include <QApplication>
#include<iostream>
#include<fstream>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<QDebug>
#include<global.h>
#include<QFile>
#include <QFileDialog>
struct pig{
    //1为黑猪，2为小花猪，3为大花白猪

    int zhonglei;
    int growday;
    double weight;
    bool havepig;
    int isinfected;

};
//猪圈作为一个类
class pigsty{
    private:

    int isblackpig;

public:
    int pignumber;
    int haveinfected;
    pig p[10];
    //缺省构造
    pigsty()
     {pignumber=0;
      isblackpig=0;
     for(int i=0;i<10;i++)
      {
         p[i].weight=0;
         p[i].growday=0;
         p[i].zhonglei=0;
         p[i].havepig=0;
      }
     }
     //打印猪圈是否为黑猪圈，打印猪圈里猪的种类和数量
    void print()
    {
    if(pignumber==0)
     { qDebug()<<"是空猪圈。"<<endl;
     return ;
     }
     if(isblackpig==1)
      { qDebug()<<"是黑猪圈,";
      }
      if(isblackpig==0)  qDebug()<<"不是黑猪圈,";
      int count1=0,count2=0,count3=0;

        for(int i=1;i<10;i++)
    {
    if(p[i].zhonglei==1)count1++;
    if(p[i].zhonglei==2)count2++;
    if(p[i].zhonglei==3)count3++;
    }
    if(isblackpig==1)
     { qDebug()<<"共有"<<count1<<"头黑猪"<<endl;
     }
     if(!isblackpig)
     { qDebug()<<"共有"<<count2<<"头小花猪，";
      qDebug()<<count3<<"头大花白猪"<<endl;
     }
    }
        //获得该猪圈的猪总数
    int getnumber()
    {int x=0;
    for(int i=0;i<10;i++)
    {
        if(p[i].havepig)x++;
    }
    pignumber=x;
    return x;
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
     //猪圈中猪的数量-1
   void minuspignumber()
    {
       pignumber--;
       return;
   }

    //显示猪圈里所有猪的品种等信息
    void show()
    {
        if(getnumber()==0)
        {
            qDebug()<<"为空猪圈"<<endl;
        }
     for(int i=0;i<10;i++)
      { if(p[i].havepig==1)
         {
         qDebug()<<"编号为"<<i;
      if(isblackpig==1) qDebug()<<"的黑猪："<<endl;
      else if(p[i].zhonglei==2) qDebug()<<"的小花猪："<<endl;
      else  qDebug()<<"的大花白猪:"<<endl;
      qDebug()<<"体重为"<<p[i].weight<<"，生长天数为"<<p[i].growday<<endl;
     \
      }
    }
    }
};
void save();



void grow(int ,pigsty a[]);
void addpig(int  ,pigsty a[]);
int getallpignumber(pigsty a[]);
void chaxun(pigsty a,int x);
void zhuzhuangtu(pigsty a[]);
void xianshi(pigsty a[]);
double sellpig(pigsty a[]);
void reset(pigsty a[]);
