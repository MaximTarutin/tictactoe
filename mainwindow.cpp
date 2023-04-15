#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "ctime"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,     SIGNAL(clicked(bool)), this,       SLOT(button_exit()));
    connect(ui->but0,           SIGNAL(clicked(bool)), this,       SLOT(but_click_0()));
    connect(ui->but1,           SIGNAL(clicked(bool)), this,       SLOT(but_click_1()));
    connect(ui->but2,           SIGNAL(clicked(bool)), this,       SLOT(but_click_2()));
    connect(ui->but3,           SIGNAL(clicked(bool)), this,       SLOT(but_click_3()));
    connect(ui->but4,           SIGNAL(clicked(bool)), this,       SLOT(but_click_4()));
    connect(ui->but5,           SIGNAL(clicked(bool)), this,       SLOT(but_click_5()));
    connect(ui->but6,           SIGNAL(clicked(bool)), this,       SLOT(but_click_6()));
    connect(ui->but7,           SIGNAL(clicked(bool)), this,       SLOT(but_click_7()));
    connect(ui->but8,           SIGNAL(clicked(bool)), this,       SLOT(but_click_8()));

    srand(time(NULL));
    perviy_hod = rand()%2+0;            // случайно выбираем кто ходит первый
    perviy_hod_const = perviy_hod;      // запоминаем кто сходил первый
    if (perviy_hod==1)                  // Первым ходит компьютер
        {
            int k;
            k = rand()%9+0;
            Prorisovka(2,k);
            kletka[k]=2;
         }
    ui->label_Schet->setText(QString::number(schet_ja));
    ui->label_Schet_3->setText(QString::number(schet_komp));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_exit()
{
    exit(0);
}

void MainWindow::but_click_0()
{
    mozg(0);
}

void MainWindow::but_click_1()
{
    mozg(1);
}

void MainWindow::but_click_2()
{
    mozg(2);
}

void MainWindow::but_click_3()
{
    mozg(3);
}

void MainWindow::but_click_4()
{
    mozg(4);
}

void MainWindow::but_click_5()
{
    mozg(5);
}

void MainWindow::but_click_6()
{
    mozg(6);
}

void MainWindow::but_click_7()
{
    mozg(7);
}
void MainWindow::but_click_8()
{
    mozg(8);
}

void MainWindow::mozg(int i)
{
    if (kletka[i]!=0) return;   // если клетка занята то выходим из функции

    kletka[i]=1;                // Клетка занимается игроком

    Prorisovka(1,i);            // Рисуем крестик на нажатой клетке

    Zwuk_Hod();                 // Воспроизводим звук хода

    Proverka_Player();          // Проверка не выиграл ли игрок

    Proverka_Nichja();          // Если нет выигрыша игрока, то проверяем на ничью

    Hod_Komp();                 // Ходит компьютер

    Proverka_Komp();            // Проверка не выиграл ли компьютер

    Proverka_Nichja();          // Если нет выигрыша игрока, то проверяем на ничью

}

void MainWindow::Proverka_Player()
{

      if((kletka[0]==1)&&(kletka[1]==1)&&(kletka[2]==1))
        {
            Zwuk_Pobeda(); schet_ja++; QMessageBox::information(this,"ПОБЕДА","Т Ы    П О Б Е Д И Т Е Л Ь !!!!!!"); Sbros();return;
        }
      if((kletka[3]==1)&&(kletka[4]==1)&&(kletka[5]==1))
        {
            Zwuk_Pobeda(); schet_ja++; QMessageBox::information(this,"ПОБЕДА","Т Ы    П О Б Е Д И Т Е Л Ь !!!!!!"); Sbros();return;
        }
      if((kletka[6]==1)&&(kletka[7]==1)&&(kletka[8]==1))
        {
            Zwuk_Pobeda(); schet_ja++; QMessageBox::information(this,"ПОБЕДА","Т Ы    П О Б Е Д И Т Е Л Ь !!!!!!"); Sbros();return;
        }
      if((kletka[0]==1)&&(kletka[3]==1)&&(kletka[6]==1))
        {
            Zwuk_Pobeda(); schet_ja++; QMessageBox::information(this,"ПОБЕДА","Т Ы    П О Б Е Д И Т Е Л Ь !!!!!!"); Sbros();return;
        }
      if((kletka[1]==1)&&(kletka[4]==1)&&(kletka[7]==1))
        {
            Zwuk_Pobeda(); schet_ja++; QMessageBox::information(this,"ПОБЕДА","Т Ы    П О Б Е Д И Т Е Л Ь !!!!!!"); Sbros();return;
        }
      if((kletka[2]==1)&&(kletka[5]==1)&&(kletka[8]==1))
        {
            Zwuk_Pobeda(); schet_ja++; QMessageBox::information(this,"ПОБЕДА","Т Ы    П О Б Е Д И Т Е Л Ь !!!!!!"); Sbros();return;
        }
      if((kletka[0]==1)&&(kletka[4]==1)&&(kletka[8]==1))
        {
            Zwuk_Pobeda(); schet_ja++; QMessageBox::information(this,"ПОБЕДА","Т Ы    П О Б Е Д И Т Е Л Ь !!!!!!"); Sbros();return;
        }
      if((kletka[2]==1)&&(kletka[4]==1)&&(kletka[6]==1))
        {
            Zwuk_Pobeda(); schet_ja++; QMessageBox::information(this,"ПОБЕДА","Т Ы    П О Б Е Д И Т Е Л Ь !!!!!!"); Sbros();return;
        }

}

void MainWindow::Proverka_Komp()
{


    if((kletka[0]==2)&&(kletka[1]==2)&&(kletka[2]==2))
      {
          Zwuk_Proigral(); schet_komp++; QMessageBox::information(this,"ПОБЕДА","УРА   Я    ТЕБЯ   ВЫИГРАЛ  !!!!!!");  Sbros();return;
      }
    if((kletka[3]==2)&&(kletka[4]==2)&&(kletka[5]==2))
      {
          Zwuk_Proigral(); schet_komp++; QMessageBox::information(this,"ПОБЕДА","УРА   Я    ТЕБЯ   ВЫИГРАЛ  !!!!!!");  Sbros();return;
      }
    if((kletka[6]==2)&&(kletka[7]==2)&&(kletka[8]==2))
      {
          Zwuk_Proigral(); schet_komp++; QMessageBox::information(this,"ПОБЕДА","УРА   Я    ТЕБЯ   ВЫИГРАЛ  !!!!!!");  Sbros();return;
      }
    if((kletka[0]==2)&&(kletka[3]==2)&&(kletka[6]==2))
      {
          Zwuk_Proigral(); schet_komp++; QMessageBox::information(this,"ПОБЕДА","УРА   Я    ТЕБЯ   ВЫИГРАЛ  !!!!!!");  Sbros();return;
      }
    if((kletka[1]==2)&&(kletka[4]==2)&&(kletka[7]==2))
      {
          Zwuk_Proigral(); schet_komp++; QMessageBox::information(this,"ПОБЕДА","УРА   Я    ТЕБЯ   ВЫИГРАЛ  !!!!!!");  Sbros();return;
      }
    if((kletka[2]==2)&&(kletka[5]==2)&&(kletka[8]==2))
      {
          Zwuk_Proigral(); schet_komp++; QMessageBox::information(this,"ПОБЕДА","УРА   Я    ТЕБЯ   ВЫИГРАЛ  !!!!!!");  Sbros();return;
      }
    if((kletka[0]==2)&&(kletka[4]==2)&&(kletka[8]==2))
      {
          Zwuk_Proigral(); schet_komp++; QMessageBox::information(this,"ПОБЕДА","УРА   Я    ТЕБЯ   ВЫИГРАЛ  !!!!!!");  Sbros();return;
      }
    if((kletka[2]==2)&&(kletka[4]==2)&&(kletka[6]==2))
      {
          Zwuk_Proigral(); schet_komp++; QMessageBox::information(this,"ПОБЕДА","УРА   Я    ТЕБЯ   ВЫИГРАЛ  !!!!!!");  Sbros();return;
      }
}

void MainWindow::Proverka_Nichja()
{
    if((kletka[0]!=0)&&(kletka[1]!=0)&&(kletka[2]!=0)&&(kletka[3]!=0)&&(kletka[4]!=0)&&(kletka[5]!=0)
     &&(kletka[6]!=0)&&(kletka[7]!=0)&&(kletka[8]!=0))
        {
           Zwuk_Nichja(); QMessageBox::information(this,"ПОБЕДА","ПОБЕДИЛА  ДРУЖБА  !!!!!!!"); Sbros();return;
        }
}

void MainWindow::Prorisovka(int kto, int i)
{
   if (kto==1)
   {
       switch (i)
       {
       case 0: ui->but0->setStyleSheet("border-image: url(:/resourse/22222.gif) stretch;"); break;
       case 1: ui->but1->setStyleSheet("border-image: url(:/resourse/22222.gif) stretch;"); break;
       case 2: ui->but2->setStyleSheet("border-image: url(:/resourse/22222.gif) stretch;"); break;
       case 3: ui->but3->setStyleSheet("border-image: url(:/resourse/22222.gif) stretch;"); break;
       case 4: ui->but4->setStyleSheet("border-image: url(:/resourse/22222.gif) stretch;"); break;
       case 5: ui->but5->setStyleSheet("border-image: url(:/resourse/22222.gif) stretch;"); break;
       case 6: ui->but6->setStyleSheet("border-image: url(:/resourse/22222.gif) stretch;"); break;
       case 7: ui->but7->setStyleSheet("border-image: url(:/resourse/22222.gif) stretch;"); break;
       case 8: ui->but8->setStyleSheet("border-image: url(:/resourse/22222.gif) stretch;"); break;
       }
   }

   if (kto==2)
   {
       switch (i)
       {
       case 0: ui->but0->setStyleSheet("border-image: url(:/resourse/11111.gif) stretch;"); break;
       case 1: ui->but1->setStyleSheet("border-image: url(:/resourse/11111.gif) stretch;"); break;
       case 2: ui->but2->setStyleSheet("border-image: url(:/resourse/11111.gif) stretch;"); break;
       case 3: ui->but3->setStyleSheet("border-image: url(:/resourse/11111.gif) stretch;"); break;
       case 4: ui->but4->setStyleSheet("border-image: url(:/resourse/11111.gif) stretch;"); break;
       case 5: ui->but5->setStyleSheet("border-image: url(:/resourse/11111.gif) stretch;"); break;
       case 6: ui->but6->setStyleSheet("border-image: url(:/resourse/11111.gif) stretch;"); break;
       case 7: ui->but7->setStyleSheet("border-image: url(:/resourse/11111.gif) stretch;"); break;
       case 8: ui->but8->setStyleSheet("border-image: url(:/resourse/11111.gif) stretch;"); break;
       }
   }
}

void MainWindow::Hod_Komp()
{
    int z;
    z = rand()%9+0;

    // Сначала проверяем может ли компьютер выиграть

    if ((kletka[0]==2)&&(kletka[1]==2)&&(kletka[2]==0)) {kletka[2]=2; Prorisovka(2,2);return;}
    if ((kletka[0]==2)&&(kletka[2]==2)&&(kletka[1]==0)) {kletka[1]=2; Prorisovka(2,1);return;}    // 0-1-2         -
    if ((kletka[1]==2)&&(kletka[2]==2)&&(kletka[0]==0)) {kletka[0]=2; Prorisovka(2,0);return;}

    if ((kletka[3]==2)&&(kletka[4]==2)&&(kletka[5]==0)) {kletka[5]=2; Prorisovka(2,5);return;}
    if ((kletka[3]==2)&&(kletka[5]==2)&&(kletka[4]==0)) {kletka[4]=2; Prorisovka(2,4);return;}     // 3-4-5        -
    if ((kletka[4]==2)&&(kletka[5]==2)&&(kletka[3]==0)) {kletka[3]=2; Prorisovka(2,3);return;}

    if ((kletka[6]==2)&&(kletka[7]==2)&&(kletka[8]==0)) {kletka[8]=2; Prorisovka(2,8);return;}
    if ((kletka[6]==2)&&(kletka[8]==2)&&(kletka[7]==0)) {kletka[7]=2; Prorisovka(2,7);return;}     // 6-7-8        -
    if ((kletka[7]==2)&&(kletka[8]==2)&&(kletka[6]==0)) {kletka[6]=2; Prorisovka(2,6);return;}

    if ((kletka[0]==2)&&(kletka[3]==2)&&(kletka[6]==0)) {kletka[6]=2; Prorisovka(2,6);return;}
    if ((kletka[0]==2)&&(kletka[6]==2)&&(kletka[3]==0)) {kletka[3]=2; Prorisovka(2,3);return;}     // 0-3-6        |
    if ((kletka[3]==2)&&(kletka[6]==2)&&(kletka[0]==0)) {kletka[0]=2; Prorisovka(2,0);return;}

    if ((kletka[1]==2)&&(kletka[4]==2)&&(kletka[7]==0)) {kletka[7]=2; Prorisovka(2,7);return;}
    if ((kletka[1]==2)&&(kletka[7]==2)&&(kletka[4]==0)) {kletka[4]=2; Prorisovka(2,4);return;}     // 1-4-7        |
    if ((kletka[4]==2)&&(kletka[7]==2)&&(kletka[1]==0)) {kletka[1]=2; Prorisovka(2,1);return;}

    if ((kletka[2]==2)&&(kletka[5]==2)&&(kletka[8]==0)) {kletka[8]=2; Prorisovka(2,8);return;}
    if ((kletka[2]==2)&&(kletka[8]==2)&&(kletka[5]==0)) {kletka[5]=2; Prorisovka(2,5);return;}     // 2-5-8        |
    if ((kletka[5]==2)&&(kletka[8]==2)&&(kletka[2]==0)) {kletka[2]=2; Prorisovka(2,2);return;}

    if ((kletka[0]==2)&&(kletka[4]==2)&&(kletka[8]==0)) {kletka[8]=2; Prorisovka(2,8);return;}
    if ((kletka[0]==2)&&(kletka[8]==2)&&(kletka[4]==0)) {kletka[4]=2; Prorisovka(2,4);return;}     // 0-4-8        /
    if ((kletka[4]==2)&&(kletka[8]==2)&&(kletka[0]==0)) {kletka[0]=2; Prorisovka(2,0);return;}

    if ((kletka[2]==2)&&(kletka[4]==2)&&(kletka[6]==0)) {kletka[6]=2; Prorisovka(2,6);return;}
    if ((kletka[2]==2)&&(kletka[6]==2)&&(kletka[4]==0)) {kletka[4]=2; Prorisovka(2,4);return;}     // 2-4-6          \.
    if ((kletka[4]==2)&&(kletka[6]==2)&&(kletka[2]==0)) {kletka[2]=2; Prorisovka(2,2);return;}

    // Теперь проверим есть ли предвыигрышная комбинация у игрока

    if ((kletka[0]==1)&&(kletka[1]==1)&&(kletka[2]==0)) {kletka[2]=2; Prorisovka(2,2);return;}
    if ((kletka[0]==1)&&(kletka[2]==1)&&(kletka[1]==0)) {kletka[1]=2; Prorisovka(2,1);return;}    // 0-1-2         -
    if ((kletka[1]==1)&&(kletka[2]==1)&&(kletka[0]==0)) {kletka[0]=2; Prorisovka(2,0);return;}

    if ((kletka[3]==1)&&(kletka[4]==1)&&(kletka[5]==0)) {kletka[5]=2; Prorisovka(2,5);return;}
    if ((kletka[3]==1)&&(kletka[5]==1)&&(kletka[4]==0)) {kletka[4]=2; Prorisovka(2,4);return;}     // 3-4-5        -
    if ((kletka[4]==1)&&(kletka[5]==1)&&(kletka[3]==0)) {kletka[3]=2; Prorisovka(2,3);return;}

    if ((kletka[6]==1)&&(kletka[7]==1)&&(kletka[8]==0)) {kletka[8]=2; Prorisovka(2,8);return;}
    if ((kletka[6]==1)&&(kletka[8]==1)&&(kletka[7]==0)) {kletka[7]=2; Prorisovka(2,7);return;}     // 6-7-8        -
    if ((kletka[7]==1)&&(kletka[8]==1)&&(kletka[6]==0)) {kletka[6]=2; Prorisovka(2,6);return;}

    if ((kletka[0]==1)&&(kletka[3]==1)&&(kletka[6]==0)) {kletka[6]=2; Prorisovka(2,6);return;}
    if ((kletka[0]==1)&&(kletka[6]==1)&&(kletka[3]==0)) {kletka[3]=2; Prorisovka(2,3);return;}     // 0-3-6        |
    if ((kletka[3]==1)&&(kletka[6]==1)&&(kletka[0]==0)) {kletka[0]=2; Prorisovka(2,0);return;}

    if ((kletka[1]==1)&&(kletka[4]==1)&&(kletka[7]==0)) {kletka[7]=2; Prorisovka(2,7);return;}
    if ((kletka[1]==1)&&(kletka[7]==1)&&(kletka[4]==0)) {kletka[4]=2; Prorisovka(2,4);return;}     // 1-4-7        |
    if ((kletka[4]==1)&&(kletka[7]==1)&&(kletka[1]==0)) {kletka[1]=2; Prorisovka(2,1);return;}

    if ((kletka[2]==1)&&(kletka[5]==1)&&(kletka[8]==0)) {kletka[8]=2; Prorisovka(2,8);return;}
    if ((kletka[2]==1)&&(kletka[8]==1)&&(kletka[5]==0)) {kletka[5]=2; Prorisovka(2,5);return;}     // 2-5-8        |
    if ((kletka[5]==1)&&(kletka[8]==1)&&(kletka[2]==0)) {kletka[2]=2; Prorisovka(2,2);return;}

    if ((kletka[0]==1)&&(kletka[4]==1)&&(kletka[8]==0)) {kletka[8]=2; Prorisovka(2,8);return;}
    if ((kletka[0]==1)&&(kletka[8]==1)&&(kletka[4]==0)) {kletka[4]=2; Prorisovka(2,4);return;}     // 0-4-8        /
    if ((kletka[4]==1)&&(kletka[8]==1)&&(kletka[0]==0)) {kletka[0]=2; Prorisovka(2,0);return;}

    if ((kletka[2]==1)&&(kletka[4]==1)&&(kletka[6]==0)) {kletka[6]=2; Prorisovka(2,6);return;}
    if ((kletka[2]==1)&&(kletka[6]==1)&&(kletka[4]==0)) {kletka[4]=2; Prorisovka(2,4);return;}     // 2-4-6          \.
    if ((kletka[4]==1)&&(kletka[6]==1)&&(kletka[2]==0)) {kletka[2]=2; Prorisovka(2,2);return;}

    // Если таких ситуаций нет, то ставим на свободную клетку

    while(kletka[z]!=0)
    {
        z=rand()%9+0;
    }

    kletka[z]=2;
    Prorisovka(2,z);
    return;



}

void MainWindow::Zwuk_Pobeda()
{
    sound->play(":/resourse/3.wav");

}

void MainWindow::Zwuk_Proigral()
{
    sound->play(":/resourse/2.wav");
}

void MainWindow::Zwuk_Hod()
{
    sound->play(":/resourse/1.wav");
}

void MainWindow::Zwuk_Nichja()
{
    sound->play(":/resourse/4.wav");
}

void MainWindow::Sbros()
{
    int i;
    for ( i=0; i<=8; i++)
    {
        kletka[i]=0;
    }

    ui->but0->setStyleSheet("border-image: url(:/resourse/prosrach.png) stretch;");
    ui->but1->setStyleSheet("border-image: url(:/resourse/prosrach.png) stretch;");
    ui->but2->setStyleSheet("border-image: url(:/resourse/prosrach.png) stretch;");
    ui->but3->setStyleSheet("border-image: url(:/resourse/prosrach.png) stretch;");
    ui->but4->setStyleSheet("border-image: url(:/resourse/prosrach.png) stretch;");
    ui->but5->setStyleSheet("border-image: url(:/resourse/prosrach.png) stretch;");
    ui->but6->setStyleSheet("border-image: url(:/resourse/prosrach.png) stretch;");
    ui->but7->setStyleSheet("border-image: url(:/resourse/prosrach.png) stretch;");
    ui->but8->setStyleSheet("border-image: url(:/resourse/prosrach.png) stretch;");

    ui->label_Schet->setText(QString::number(schet_ja));
    ui->label_Schet_3->setText(QString::number(schet_komp));
}

