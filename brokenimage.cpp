#include "brokenimage.h"

CBrokenImage::CBrokenImage(QWidget *parent)
    :QMainWindow(parent),
      m_pCorScene(new QGraphicsScene(this)),
      m_pCorView(new QGraphicsView(m_pCorScene , this)),
      m_pParent(parent)
{
    initWidget();
}

CBrokenImage::~CBrokenImage()
{

}

void CBrokenImage::initWidget()
{
    this -> setStyleSheet("background-color:rgb(67,90,120);");
    this -> setCentralWidget(m_pCorView);
    m_pCorView -> show();

}
