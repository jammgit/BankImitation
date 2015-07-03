#ifndef CBROKENIMAGE_H
#define CBROKENIMAGE_H

#include <QMainWindow>
#include "qtheader.h"

class CBrokenImage : public QMainWindow
{
    Q_OBJECT
public:
    CBrokenImage(QWidget *parent = NULL);
    ~CBrokenImage();
private:
    void initWidget();
private:
    QGraphicsScene *m_pCorScene;
    QGraphicsView *m_pCorView;

private:
    QWidget *m_pParent;
};

#endif // CBrokenImage_H
