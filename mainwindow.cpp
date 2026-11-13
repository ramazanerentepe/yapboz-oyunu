#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <algorithm>
#include <QRandomGenerator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGridLayout *anaDuzen = new QGridLayout(ui->centralwidget);

    QWidget *yapboz = new QWidget;
    yapboz->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    grid = new QGridLayout(yapboz);
    grid->setSpacing(1);
    grid->setContentsMargins(1, 1, 1, 1);


    QWidget *sagPanel = new QWidget;
    sagPanel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    QVBoxLayout *sagDuzen = new QVBoxLayout(sagPanel);
    sagDuzen->setContentsMargins(10, 50, 10, 10);

    QLabel *anaResim = new QLabel;
    anaResim->setPixmap(QPixmap(":/img/images/puzzle.jpg"));
    anaResim->setScaledContents(true);
    anaResim->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    hamleSayac = new QLabel;
    hamleSayac->setText(QString("Hamle Sayısı : %1").arg(Parca::hamleSayisi));
    hamleSayac->setStyleSheet("font-size: 18pt;");
    hamleSayac->setWordWrap(true);

    sagDuzen->addWidget(anaResim, 1);
    sagDuzen->addWidget(hamleSayac);
    sagDuzen->addStretch(1);



    QWidget *altPanel = new QWidget;
    altPanel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);


    anaDuzen->addWidget(yapboz,    0,    0);
    anaDuzen->addWidget(sagPanel,  0,    1);
    anaDuzen->addWidget(altPanel,  1,    0,     1,          2);

    anaDuzen->setColumnStretch(0, 3);
    anaDuzen->setColumnStretch(1, 1);
    anaDuzen->setRowStretch(0, 4);
    anaDuzen->setRowStretch(1, 1);


    //Resimleri listeleme ve karıştırma
    QList<int> *resimList = new QList<int>;
    for(int i = 0; i<(N*N); i++){
        resimList->append(i);
    }
    std::shuffle(resimList->begin(),resimList->end(), *QRandomGenerator::global());
    QString anaPath = ":/img/images/";
    QString son = ".png";
    int sayac=0;
    //parca yerlestirme
    for(int i=0;i<N;i++){
        for(int j=0; j<N;j++){
            Parca *p = new Parca(sayac, (*resimList)[sayac] );
            connect(p, &Parca::yerDegistir, this, &MainWindow::hamleGuncelle);
            QString path = anaPath + QString::number((*resimList)[sayac]) + son;
            p->setPixmap(QPixmap(path));
            grid->addWidget(p , i ,j);
            parcalar.append(p);
            sayac++;
        }
    }
    delete resimList;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hamleGuncelle()
{
    hamleSayac->setText(QString("Hamle Sayısı : %1").arg(Parca::hamleSayisi));

    for (Parca *p : parcalar) {
        if (!p->dogruMu())
            return;
    }

    QMessageBox::information(this, "Tebrikler",
         QString("Yapbozu %1 hamlede tamamladın!").arg(Parca::hamleSayisi));
}