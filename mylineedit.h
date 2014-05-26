#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
class QToolButton;
class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);
signals:

public slots:
    void updateCloseButton(const QString &text);
private:
     QToolButton *clearButton;

};

#endif // MYLINEEDIT_H
