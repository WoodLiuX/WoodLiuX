#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include"global.h"
#include<QDebug>
#include<yangzhu.h>
#include<QLineEdit>
#include<QtCharts>
#include <QBarSet>
#include <QBarCategoryAxis>
#include<QLabel>
pigsty a[100];
int num_1;
int num1,num2;
 void MainWindow::updateweight()
  {int bweight1=0,bweight2=0,bweight3=0;
   int sweight1=0,sweight2=0,sweight3=0;
   int bwweight1=0,bwweight2=0,bwweight3=0;

           for(int i=0;i<67;i++)
              {if(a[i].getnumber()==0)
                      {
                       continue;
                      }

                      for(int j=0;j<10;j++)
                           {if(a[i].p[j].havepig)
                            {if(a[i].p[j].zhonglei==2)
                              {
                                 if(a[i].p[j].weight<=50)sweight1++;
                                 else if(a[i].p[j].weight<=75)sweight2++;
                                 else if(a[i].p[j].weight>75)sweight3++;

                              }
                             else if(a[i].p[j].zhonglei==3)
                              {
                                 if(a[i].p[j].weight<=50)bwweight1++;
                                 else if(a[i].p[j].weight<=75)bwweight2++;
                                 else if(a[i].p[j].weight>75)bwweight3++;
                              }
                            }
                           }
                }

                  for(int i=67;i<100;i++)
                       {if(a[i].getnumber()==0)
                      {
                       continue;
                      }

                      for(int j=0;j<10;j++)
                           {if(a[i].p[j].havepig)
                               {
                              if(a[i].p[j].weight<=50)bweight1++;
                              else if(a[i].p[j].weight<=75)bweight2++;
                              else if(a[i].p[j].weight>75)bweight3++;
                               }
                           }
                       }

                   QBarSet *set0 = new QBarSet("黑猪");
                   QBarSet *set1 = new QBarSet("小花白猪");
                   QBarSet *set2 = new QBarSet("大花白猪");

                   *set0 << bweight1 << bweight2 << bweight3 ;
                   *set1 << sweight1 << sweight2 << sweight3 ;
                   *set2 << bwweight1<< bwweight2<< bwweight3;


                   QBarSeries *series = new QBarSeries();
                   series->append(set0);
                   series->append(set1);
                   series->append(set2);



                   QChart *chart = new QChart();
                   chart->addSeries(series);
                   chart->setTitle("体重分布图");
                   chart->setAnimationOptions(QChart::SeriesAnimations);

                   QStringList categories;
                   categories << "20-50kg" << "50-75kg" << "75kg以上" ;
                   QBarCategoryAxis *axis = new QBarCategoryAxis();
                   axis->append(categories);
                   chart->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
                   chart->setAxisX(axis, series);//设置坐标轴



                   chart->legend()->setVisible(true); //设置图例为显示状态
                   chart->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部



                   QChartView *chartView = new QChartView(chart);

                   chartView->setRenderHint(QPainter::Antialiasing);
                   w1.setCentralWidget(chartView);


              }
  void MainWindow::updategrowday()
  {int bday1=0,bday2=0,bday3=0;
   int sday1=0,sday2=0,sday3=0;
   int bwday1=0,bwday2=0,bwday3=0;

   for(int i=0;i<67;i++)
      {if(a[i].getnumber()==0)
              {
               continue;
              }

              for(int j=0;j<10;j++)
                   {if(a[i].p[j].havepig)
                    {if(a[i].p[j].zhonglei==2)
                      {
                         if(a[i].p[j].growday<90)sday1++;
                         else if(a[i].p[j].growday<=210)sday2++;
                         else if(a[i].p[j].growday>210)sday3++;

                      }
                     else if(a[i].p[j].zhonglei==3)
                      {
                         if(a[i].p[j].growday<90)bwday1++;
                         else if(a[i].p[j].growday<=210)bwday2++;
                         else if(a[i].p[j].growday>360)bwday3++;
                      }
                    }
                   }
        }

          for(int i=67;i<100;i++)
               {if(a[i].getnumber()==0)
              {
               continue;
              }

              for(int j=0;j<10;j++)
                   {if(a[i].p[j].havepig)
                       {
                      if(a[i].p[j].growday<90)bday1++;
                      else if(a[i].p[j].growday<=210)bday2++;
                      else if(a[i].p[j].growday>210)bday3++;
                       }
                   }
               }

                   QBarSet *set0 = new QBarSet("黑猪");
                   QBarSet *set1 = new QBarSet("小花白猪");
                   QBarSet *set2 = new QBarSet("大花白猪");

                   *set0 << bday1 << bday2 << bday3 ;
                   *set1 << sday1 << sday2 << sday3 ;
                   *set2 << bwday1<< bwday2<< bwday3;


                   QBarSeries *series = new QBarSeries();
                   series->append(set0);
                   series->append(set1);
                   series->append(set2);



                   QChart *chart = new QChart();
                   chart->addSeries(series);
                   chart->setTitle("饲养时间分布图");
                   chart->setAnimationOptions(QChart::SeriesAnimations);

                   QStringList categories;
                   categories << "90天以下" << "90-210天" << "210-360天" ;
                   QBarCategoryAxis *axis = new QBarCategoryAxis();
                   axis->append(categories);
                   chart->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
                   chart->setAxisX(axis, series);//设置坐标轴



                   chart->legend()->setVisible(true); //设置图例为显示状态
                   chart->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部



                   QChartView *chartView = new QChartView(chart);

                   chartView->setRenderHint(QPainter::Antialiasing);
                   w2.setCentralWidget(chartView);


              }
  void MainWindow::updatenumber()
  {
      QBarSet *set0 = new QBarSet("黑猪");
      QBarSet *set1 = new QBarSet("小花白猪");
      QBarSet *set2 = new QBarSet("大花白猪");

      *set0 <<blacknumber ;
      *set1 <<smallnumber ;
      *set2 <<bignumber;


      QBarSeries *series = new QBarSeries();
      series->append(set0);
      series->append(set1);
      series->append(set2);



      QChart *chart = new QChart();
      chart->addSeries(series);
      chart->setTitle("数量分布图");
      chart->setAnimationOptions(QChart::SeriesAnimations);

      QStringList categories;
      categories << "数量" ;
      QBarCategoryAxis *axis = new QBarCategoryAxis();
      axis->append(categories);
      chart->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
      chart->setAxisX(axis, series);//设置坐标轴



      chart->legend()->setVisible(true); //设置图例为显示状态
      chart->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部



      QChartView *chartView = new QChartView(chart);

      chartView->setRenderHint(QPainter::Antialiasing);
      w3.setCentralWidget(chartView);
  }
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{load_file();
    updateweight();
    updategrowday();
    updatenumber();
    resize(1200,700);
    QLabel *pLabel = new QLabel(this);
    pLabel->setText("总收入：");
    pLabel->move(100,450);
    QLabel *pLabel1 = new QLabel(this);
        pLabel1->setText(QString::number(allsellprice));
        qDebug()<<allsellprice;
        pLabel1->move(160,450);
        QLabel *pLabel2 = new QLabel(this);
            pLabel2->setText("猪的总数:  ");
            pLabel2->move(100,475);
            QLabel *pLabel3 = new QLabel(this);
                pLabel3->setText(QString::number(getallpignumber(a)));
                pLabel3->move(160,475);



    srand((unsigned)time(NULL));
    w1.setParent(this);
  w2.setParent(this);
  w3.setParent(this);
  w1.resize(350,350);
  w2.resize(350,350);
  w3.resize(350,350);
  w2.move(350,0);
  w3.move(700,0);
    ui->setupUi(this);
     num_1 = ui->lineEdit1->text().toInt();

     allpignumber=getallpignumber(a);
    QPushButton *c =new QPushButton(this);
        c->setText("加100头猪");
        c->move(100,500);
        connect(c,&QPushButton::clicked,
               [=] ()
        {addpig(100,a);
            updateweight();
            updategrowday();
            updatenumber();
            pLabel1->setText(QString::number(allsellprice));
             pLabel3->setText(QString::number(getallpignumber(a)));
        }
                );

            QPushButton *c2 =new QPushButton(this);
                c2->setText("成长90天");
                c2->move(200,500);
                connect(c2,&QPushButton::clicked,
                       [=] ()
                {grow(90,a);
                    updateweight();
                    updategrowday();
                    updatenumber();
                    pLabel1->setText(QString::number(allsellprice));
                     pLabel3->setText(QString::number(getallpignumber(a)));
                }
                        );
                QPushButton *c3 =new QPushButton(this);
                    c3->setText("猪瘟模拟");
                    c3->move(500,500);
                    connect(c3,&QPushButton::clicked,
                           [=] ()
                    {chuanran();
                    }
                            );
               QPushButton *c4 =new QPushButton(this);
                        c4->setText("查询某一猪圈");
                        c4->move(220,385);
                        connect(c4,&QPushButton::clicked,
                               [=] ()
                        {if(num_1>99||num_1<0)
                                {
                                qDebug()<<"该猪圈不存在"<<endl;
                            }
                           else a[num_1].show();
                        }
                                );

                        QPushButton *c5 =new QPushButton(this);
                                c5->setText("查询某一头猪");
                                c5->move(600,385);
                                connect(c5,&QPushButton::clicked,
                                       [=] ()
                                {chaxun(a[num1],num2);
                                }
                                    );


                        w1.show();
                        w2.show();
                        w3.show();
}

MainWindow::~MainWindow()
{  for(int i=0;i<100;i++)
         {
        for(int j=0;j<10;j++)
        {
            if(!a[i].p[j].havepig)
            {
                a[i].p[j].growday=0;
                a[i].p[j].weight=0;
                a[i].p[j].zhonglei=0;
            }
        }
    }
    QFile file;
    file.setFileName("../auto_save.txt");
    bool isOK = file.open(QIODevice::WriteOnly);
    if(true == isOK)
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream<<Day<<" "<<allsellprice<<"\n";
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<10;j++)
            {
                stream<<i<<" "<<j<<" "<<a[i].p[j].havepig<<" "<<a[i].p[j].zhonglei<<" "<<a[i].p[j].weight<<" "<<a[i].p[j].growday<<"\n";
            }
        }
        file.close();
        qDebug()<<"数据保存成功！"<<getallpignumber(a);
    }
    delete ui;
}



void MainWindow::on_lineEdit1_editingFinished()
{
  num_1 = ui->lineEdit1->text().toInt();
}

void MainWindow::on_lineEdit_editingFinished()
{
    num1= ui->lineEdit->text().toInt();
}

void MainWindow::on_lineEdit2_editingFinished()
{
     num2= ui->lineEdit2->text().toInt();
}
void MainWindow::load_file()
{
    QFile file;
    QString path=QFileDialog::getOpenFileName(this,"open","../","TXT(*.txt)");
    if(path.isEmpty()==0)
    {
        file.setFileName(path);
    }
    bool isOK = file.open(QIODevice::ReadOnly);
    if(true == isOK)
    {
        reset(a);
        int t_days,t_money,pigstyid,pigid,havepig,growday,zhonglei;
        double weight;

        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream>>t_days>>t_money;
        Day=t_days,allsellprice=t_money;
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<10;j++)
            {stream>>pigstyid>>pigid>>havepig>>zhonglei>>weight>>growday;
                if(havepig)
                {if(zhonglei==1)blacknumber++;
                    else if(zhonglei==2)smallnumber++;
                    else if(zhonglei==3)bignumber++;
                    a[i].p[j].zhonglei=zhonglei;
                    a[i].p[j].weight=weight;
                    a[i].p[j].growday=growday;
                    a[i].p[j].havepig=1;
                    a[i].addpignumber();
                }

            }
        }
        file.close();
qDebug()<<blacknumber<<smallnumber<<bignumber;
        QFile file2;
        file2.setFileName("../sold_data.txt");
        bool isOK = file2.open(QIODevice::WriteOnly);
        if(true == isOK)
        {
            QTextStream stream(&file2);
            stream<<path<<"\n";
            file.close();
        }
        else
            qDebug()<<"fail";
    }
}
void MainWindow::chuanran()
{ srand((unsigned)time(NULL));
    int infectednumber=0;
    for(int i=0;i<100;i++)
    {
        a[i].haveinfected=0;
        for(int j=0;j<10;j++)
        {
            a[i].p[j].isinfected=0;
        }
    }
    int i,j,left,right,days=0,n_may=0;
    while(1)
    {
        i=rand()%100,j=rand()%10;
        if(a[i].p[j].havepig)
        {
            a[i].haveinfected=1;
            a[i].p[j].isinfected=1;
            infectednumber=1;
           qDebug()<<i<<"号猪圈的"<<j<<"号猪被随机感染"<<endl;
            break;
        }
    }
    left=i;
    right=i;
    left=i,right=i;
    while(a[left].pignumber!=0&&left!=0)
    {
        left--;
    }
    while(a[right].pignumber!=0&&right!=99)
    {
        right++;
    }
    if(left==0&&a[left].getnumber()==0)
        left++;
    if(right==99&&a[right].getnumber()==0)
        right--;
    for(int x=left;x<=right;x++)
        n_may+=a[x].getnumber();
    qDebug()<<"共有"<<n_may<<"头猪有可能被传染"<<endl;
    while(infectednumber!=n_may&&days<1000)
    {days++;
        for(int x=left;x<=right;x++)
        {
            for(int m=0;m<10;m++)
            {
                if(a[x].p[m].havepig&&a[x].p[m].isinfected==0)
                {
                    if(a[x].haveinfected)
                    {
                        int suiji=rand()%2;
                        if(suiji)
                        {
                            a[x].p[m].isinfected=1;
                            infectednumber++;
                            continue;
                        }
                    }
                    else if((a[x-1].haveinfected&&x>0)||(a[x+1].haveinfected&&x<99))
                    {
                        int suijishu=rand()%15;
                        if(suijishu==1)
                        {
                            a[x].p[m].isinfected=1;
                            infectednumber++;
                            a[x].haveinfected=1;
                            continue;
                        }
                    }
                }
            }

        }

    }
    qDebug()<<"经过了共"<<days<<"天，"<<infectednumber<<"头猪被传染了，并且猪瘟结束了。";
    qDebug()<<"若想将猪瘟的影响最小化，应将"<<left<<"至"<<right<<"之间猪圈的猪进行转移猪圈或者处理掉";
}
