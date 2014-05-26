#include "searchedit.h"

SearchEdit::SearchEdit(QWidget *parent) :
    QWidget(parent)
{
    initVariables();
    initWidgets();
}

/*!
  utility functions
*/
void SearchEdit::calcGeo()
{
    m_searchLabel->move(SE_LEFT_SPACE,SE_TOP);
    m_searchEdit->move(SE_LEFT_SPACE + m_searchLabel->width() + SE_WIDGET_SPACE,SE_TOP);
    m_searchEdit->setFixedWidth(width() - 2 * SE_LEFT_SPACE - 2 * SE_WIDGET_SPACE - 2 * SE_EDIT_HEIGHT);
    m_clearLabel->move(width()- SE_LEFT_SPACE - SE_EDIT_HEIGHT -SE_WIDGET_SPACE,SE_TOP);

}

void SearchEdit::initWidgets()
{
    //
    QPixmap oriPixmap(":/Images/search.png");
    QPixmap newPixmap=oriPixmap.scaled(QSize(SE_EDIT_HEIGHT,SE_EDIT_HEIGHT),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    m_searchLabel=new QLabel(this);
    m_searchLabel->setPixmap(newPixmap);
    m_searchLabel->setFixedSize(QSize(SE_EDIT_HEIGHT,SE_EDIT_HEIGHT));
    m_searchLabel->show();

    //
    m_clearLabel=new ClearLabel(this);
    oriPixmap = QPixmap(":/Images/clear.png");
    newPixmap = oriPixmap.scaled(QSize(SE_EDIT_HEIGHT,SE_EDIT_HEIGHT),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    m_clearLabel->setPixmap(newPixmap);
    m_clearLabel->hide();

    //
    m_searchEdit=new QLineEdit(this);
    m_searchEdit->setFixedHeight(SE_EDIT_HEIGHT);
    m_searchEdit->setFrame(false);
    m_searchEdit->show();

    // setup signal-slot connection
    connect(m_searchEdit,SIGNAL(textChanged(QString)),this,SLOT(HandleTextChanged(QString)));
    connect(m_clearLabel,SIGNAL(sig_clicked()),this,SLOT(ClearText()));
    connect(m_searchEdit,SIGNAL(textChanged(QString)),this,SIGNAL(sig_textChanged(QString)));

}

void SearchEdit::initVariables()
{

    m_bEnter = false;
    setFixedHeight(SE_HEIGHT);
}

/*!
  reimplementing protected functions
*/
void SearchEdit::resizeEvent(QResizeEvent *e)
{
    calcGeo();
    QWidget::resizeEvent(e);
}

void SearchEdit::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    drawBackground(&painter);
}

void SearchEdit::enterEvent(QEvent *e)
{
    m_bEnter = true;
    update();
    QWidget::enterEvent(e);
}

void SearchEdit::leaveEvent(QEvent *e)
{
    m_bEnter = false;
    update();
    QWidget::leaveEvent(e);
}

/*!
  painting functions
*/
void SearchEdit::drawBackground(QPainter *painter)
{
    painter->save();
    painter->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing);

    if(m_bEnter)
    {
        painter->setPen(QPen(SE_BG_PEN_COLOR,SE_PEN_WIDTH));
    }else{
        painter->setPen(SE_BG_BRUSH_COLOR);
    }

    painter->setBrush(SE_BG_BRUSH_COLOR);
    painter->drawRoundedRect(rect(),SE_RECT_RADIUS,SE_RECT_RADIUS);

    painter->restore();
}

/*!
  private slot functions
*/
void SearchEdit::HandleTextChanged(const QString &str)
{
    if(str.isEmpty())
    {
        m_clearLabel->hide();
    }else{
        m_clearLabel->show();
    }
}

void SearchEdit::ClearText()
{
    m_searchEdit->clear();
}


/*!
  public interfaces
*/
void SearchEdit::setText(const QString &str)
{
    m_searchEdit->setText(str);
}

QString SearchEdit::text() const
{
    return m_searchEdit->text();
}

void SearchEdit::clear()
{
    m_searchEdit->clear();
}
