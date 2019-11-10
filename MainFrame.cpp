#include "MainFrame.h"

#include <QDebug>

#include <QTextCodec>
#include <QFile>
#include <stdio.h>

MainFrameWin::MainFrameWin(QObject *rootView):m_mainFrameView(rootView)
{
    initView();
    initData();
}

MainFrameWin::~MainFrameWin()
{
    delete m_mainFrameView;
    m_mainFrameView = NULL;

    delete m_start_btn;
    m_start_btn = NULL;

    delete m_img;
    m_img = NULL;

}

void MainFrameWin::initView()
{
    m_start_btn = m_mainFrameView->findChild<QObject*>("strat_btn");
    m_start_btn_1 = m_mainFrameView->findChild<QObject*>("strat_btn_1");
    m_img = m_mainFrameView->findChild<QObject*>("img");

    connect(m_start_btn, SIGNAL(clicked()), this, SLOT(onStartClicked()));

    connect(m_start_btn_1, SIGNAL(clicked()), this, SLOT(onStart1Clicked()));
}

void MainFrameWin::initData()
{

}

void MainFrameWin::onStartClicked()
{
    QString mp3Path = "D:/CloudMusic/Snowdreams.mp3";
//    QString mp3Path = "D:/CloudMusic/白若溪 - 追梦人.mp3";

    QFile file(mp3Path);
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"Can't open the file!"<<endl;
    }

    QTextStream stream(&file);

//    file type is id3
    QString type = stream.read(3);

    if(type != "ID3"){

        qDebug()<<"Can't read, the file is not ID3!"<<endl;
        return;
    }else {
        qDebug()<< type <<endl;
    }
//    mp3以末尾的128字节存放，偏移-128
    stream.seek(file.size()-128*sizeof(char));

//    //读取标签头
    QString header = stream.read(3);

    if(header == "TAG"){

        //读取信息
        QString title = QString::fromLocal8Bit(stream.read(30).toLocal8Bit());

        qDebug() << "title1 == " << title << endl;

        QString artist = stream.read(30);
        QString album = stream.read(30);
        QString year = stream.read(4);
        QString comment = stream.read(30);
        QString genre = stream.read(1);


        qDebug() << "title == " << title << endl;
        qDebug() << "artist == " << artist << endl;
        qDebug() << "album == " << album << endl;
        qDebug() << "year == " << year << endl;
        qDebug() << "comment == " << comment << endl;
        qDebug() << "genre == " << genre << endl;
    }

    file.close();

}


void MainFrameWin::onStart1Clicked()
{
    //
    QString mp3Path = "D:/CloudMusic/Snowdreams.mp3";
//    QString mp3Path = "D:/CloudMusic/白若溪 - 追梦人.mp3";

    //中文支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));

    QFile file(mp3Path);

    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"Can't open the file!"<<endl;
    }

    //file type is id3
    QByteArray type;
    type = file.read(3);

    if(!(type[0] == 'I' && type[1] == 'D' && type[2] == '3')){

        qDebug()<<"Can't read, the file is not ID3!"<<endl;
        return;
    }else {
        qDebug()<< type <<endl;
    }
    //mp3以末尾的128字节存放，偏移-128
    file.seek(file.size()-128*sizeof(char));

    //读取标签头
    QByteArray header;
    header = file.read(3);

    QByteArray title;
    QByteArray artist;
    QByteArray album;
    QByteArray year;
    QByteArray comment;
    QByteArray genre;

    if(header[0] == 'T' && header[1] == 'A' && header[2] == 'G'){

        //读取信息
        title = file.read(30);
        artist = file.read(30);
        album = file.read(30);
        year = file.read(4);
        comment = file.read(30);
        genre = file.read(1);

        qDebug() << "title == " << title.toStdString().c_str() << endl;
        qDebug() << "artist == " << artist.toStdString().c_str() << endl;
        qDebug() << "album == " << album.toStdString().c_str() << endl;
        qDebug() << "year == " << year.toStdString().c_str() << endl;
        qDebug() << "comment == " << comment.toStdString().c_str() << endl;
        qDebug() << "genre == " << genre.toStdString().c_str() << endl;
    }

    file.close();
}
