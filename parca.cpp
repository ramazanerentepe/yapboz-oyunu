#include "parca.h"
#include <QMimeData>
#include <QDrag>
#include <QApplication>
#include <utility>

int Parca::hamleSayisi = 0;

Parca::Parca(int ID ,int resimID ,QWidget *parent)
    :QLabel{parent}
{
    id = ID;
    resimId = resimID;
    setScaledContents(true);
    setFrameShape(QFrame::Box);
    setAcceptDrops(true);

}

bool Parca::dogruMu(){
    if(id==resimId){
        return true;
    }else{
        return false;
    }
}

bool Parca::komsuMu(const Parca *pa) const{
    int satir1 = id / N,      sutun1 = id % N;
    int satir2 = pa->id / N,  sutun2 = pa->id % N;

    return qMax(qAbs(satir1 - satir2), qAbs(sutun1 - sutun2)) == 1;
}

void Parca::mousePressEvent(QMouseEvent *ev){
    if (ev->button() == Qt::LeftButton)
        baslangic = ev->position().toPoint();
    QLabel::mousePressEvent(ev);
}

void Parca::dragEnterEvent(QDragEnterEvent *ev){
    Parca *gelen = qobject_cast<Parca*>(ev->source());
    if(gelen && komsuMu(gelen)){
        ev->acceptProposedAction();
    }else
        ev->ignore();
}

void Parca::mouseMoveEvent(QMouseEvent *ev){
    if(!(ev->buttons() & Qt::LeftButton))
        return;

    if((ev->position().toPoint() - baslangic).manhattanLength()
            < QApplication::startDragDistance())
        return;

    if(pixmap().isNull())
        return;

    QMimeData *veri = new QMimeData;
    QDrag *surukle= new QDrag(this);
    surukle->setMimeData(veri);
    surukle->setPixmap(pixmap().scaled(size() / 2, Qt::KeepAspectRatio));
    surukle->exec(Qt::MoveAction);
}

void Parca::dropEvent(QDropEvent *ev){
    Parca *gelen = qobject_cast<Parca*>(ev->source());
    if (!gelen || !komsuMu(gelen))
        return;

    QPixmap gecici = pixmap();
    setPixmap(gelen->pixmap());
    gelen->setPixmap(gecici);

    std::swap(resimId, gelen->resimId);

    hamleSayisi++;

    ev->acceptProposedAction();

    emit yerDegistir();
}
