#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia/QSound>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void    button_exit();
    void    but_click_0();
    void    but_click_1();
    void    but_click_2();
    void    but_click_3();
    void    but_click_4();
    void    but_click_5();
    void    but_click_6();
    void    but_click_7();
    void    but_click_8();


private:
    Ui::MainWindow *ui;

public:
    int kletka[9]={0,0,0,0,0,0,0,0,0};  // массив клеток поля
    int perviy_hod;                     // кто будет ходить первым (0 - игрок; 1 - компьютер)
    int perviy_hod_const;               // запоминает, чей ход был первым
    void mozg(int i);                   // игровой цикл
    void Proverka_Player();             // проверка выиграл ли игрок
    void Proverka_Komp();               // проверка выиграл ли компьютер
    void Proverka_Nichja();             // проверка на ничью
    void Prorisovka(int kto, int i);    // рисуем в клетке крестик или нолик ( kto = 1 - '+'; kto = 2 - '0' )
    void Hod_Komp();                    // ходит компьютер
    void Zwuk_Pobeda();
    void Zwuk_Proigral();
    void Zwuk_Hod();
    void Zwuk_Nichja();
    void Sbros();                       // очищает поле для следующей партии
    int schet_ja=0;
    int schet_komp=0;
    QSound *sound;



};

#endif // MAINWINDOW_H
