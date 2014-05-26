#include "mylineedit.h"
#include <QToolButton>
#include <QStyle>
MyLineEdit::MyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    clearButton = new QToolButton(this);
//    QPixmap pixmap(":/Images/07.png");
//    QPixmap newPixmap = pixmap.scaled(QSize(20,20),Qt::KeepAspectRatio,Qt::SmoothTransformation);
//    clearButton->setIcon(QIcon(newPixmap));
//  clearButton->setIconSize(newPixmap.size());
    clearButton->setIconSize(QSize(15,15));

    clearButton->setObjectName("searchQb");
    clearButton->setCursor(Qt::ArrowCursor);
    clearButton->setStyleSheet("QToolButton { border: none; padding: 0px;margin:5;border-image: url(:/Images/07.png); } QToolButton#searchQb:hover{ border-image: url(:/Images/08.png);}");
    clearButton->show();
    connect(clearButton, SIGNAL(clicked()), this, SLOT(clear()));
    connect(this, SIGNAL(textChanged(const QString&)), this, SLOT(updateCloseButton(const QString&)));
    int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
    setStyleSheet(QString("QLineEdit { padding-right: %1px; background-color: rgb(254, 254, 254);} ").arg(clearButton->sizeHint().width() + frameWidth + 1));
    QSize msz = minimumSizeHint();
    setMinimumSize(qMax(msz.width(), clearButton->sizeHint().height() + frameWidth * 2 + 2),
                   qMax(msz.height(), clearButton->sizeHint().height() + frameWidth * 2 + 2));

}

 void MyLineEdit::resizeEvent(QResizeEvent *)
 {
     QSize sz = clearButton->sizeHint();
     int frameWidth = style()->pixelMetric(QStyle::PM_DefaultFrameWidth);
     clearButton->move(rect().right() - frameWidth - sz.width(),
                       (rect().bottom() + 1 - sz.height())/2);
 }

 void MyLineEdit::updateCloseButton(const QString& text)
 {
     //clearButton->setVisible(!text.isEmpty());
 }

