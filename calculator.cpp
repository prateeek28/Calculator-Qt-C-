#include "calculator.h"
#include "ui_calculator.h"
#include <QMediaPlayer>
double calcval = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcval));
    QPushButton *numButtons[10];
    for(int i=0; i<10; ++i){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this , SLOT(NumPressed()));
    }

    connect(ui->AddButton, SIGNAL(released()), this , SLOT(MathButtonPressed()));
    connect(ui->Subtract, SIGNAL(released()), this , SLOT(MathButtonPressed()));
    connect(ui->Multiply, SIGNAL(released()), this , SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this , SLOT(MathButtonPressed()));
    connect(ui->Equals, SIGNAL(released()), this , SLOT(EqualButtonPressed()));
    connect(ui->Changesign, SIGNAL(released()), this , SLOT(ChangeNumberSign()));
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumPressed(){
    QPushButton *button = (QPushButton *) sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if ((displayVal.toDouble() == 0)|| (displayVal.toDouble() == 0.0)){
            ui->Display->setText(butVal);
           } else{
                QString newVal = displayVal + butVal;
                double dblNewVal = newVal.toDouble();
                ui->Display->setText(QString::number(dblNewVal, 'g', 16));
            }
}

void Calculator::MathButtonPressed(){
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QString displayVal = ui->Display->text();
    calcval = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    if(QString:: compare(butVal, "/" , Qt::CaseSensitive)==0){
        divTrigger =true;
    }else if(QString::compare(butVal, "*" , Qt::CaseSensitive)==0){
            multTrigger =true;

    }else if(QString::compare(butVal, "+" , Qt::CaseSensitive)==0){
        addTrigger =true;

}else{
        subTrigger =true;

}

    ui->Display->setText("");
}

void Calculator::EqualButtonPressed(){
    double solution =0.0;
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();
    if(addTrigger || subTrigger || multTrigger || divTrigger){
        if(addTrigger){
            solution =calcval + dblDisplayVal;
        } else if(subTrigger){
            solution =calcval - dblDisplayVal;
    } else if(multTrigger){
            solution =calcval * dblDisplayVal;
} else{
            solution = calcval / dblDisplayVal;
        }
}
    ui->Display->setText(QString::number(solution));

}

void Calculator::ChangeNumberSign(){
    QString displayVal=ui->Display->text();
    QRegExp reg("[-]?[0-9.]*");
    if(reg.exactMatch(displayVal)){
        double dblDisplay = displayVal.toDouble();
        double dblDisplayValsign = -1 * dblDisplay;

        ui->Display->setText(QString::number(dblDisplayValsign));
    }

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/super_mario_bros.mp3"));
    music->play();
}
