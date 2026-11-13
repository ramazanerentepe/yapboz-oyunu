#ifndef PARCA_H
#define PARCA_H

#include <QLabel>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMouseEvent>

class Parca : public QLabel
{
    Q_OBJECT
public:
    explicit Parca(int ID ,int resimID, QWidget *parent = nullptr);
    static int hamleSayisi;
    static const int N = 5;

    bool dogruMu();
private:

    int id , resimId;
    QPoint baslangic;

    void mousePressEvent(QMouseEvent*);
    void dragEnterEvent(QDragEnterEvent*);
    void dropEvent(QDropEvent*);
    void mouseMoveEvent(QMouseEvent*);
    bool komsuMu(const Parca *pa) const;

signals:

    void yerDegistir();
};

#endif // PARCA_H
