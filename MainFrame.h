#ifndef MAINFRANE_H
#define MAINFRANE_H

#include <QObject>

class MainFrameWin: public QObject
{
    Q_OBJECT
public:
    MainFrameWin(QObject* rootView);
    ~MainFrameWin();

    void initView();

    void initData();

public slots:

    void onStartClicked();

    void onStart1Clicked();

private:

    QObject *m_mainFrameView;

    //title bar;
    QObject *m_start_btn;

    QObject *m_start_btn_1;

    //top bar;
    QObject *m_img;
};

#endif // MAINFRANE_H
