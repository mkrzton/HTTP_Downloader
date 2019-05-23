#include "download.h"

download::download(QObject *parent) : QObject(parent)
{

}

void download::StartDownload(){

    NAM = new QNetworkAccessManager(this);

    connect(NAM, SIGNAL(finished(QNetworkReply *)), this, SLOT(Response(QNetworkReply *)));

    NAM->get(QNetworkRequest(QUrl("https://www.iczn.org/")));

}

void download::Response(QNetworkReply *reply){

    if(reply->error()){

        qDebug() << "Could not download";
        qDebug() << reply->errorString();

    }else{

        qDebug() << "\n\nHeader type:\t" << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << "Header length:\t" << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << "Code status:\t" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << "Reason phrase:\t" << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();

        QFile *f = new QFile("C:/Users/Marcin/Documents/Httpdownload/http.txt");

        if(f->open(QFile::Append)){

            f->write(reply->readAll());
            f->flush();
            f->close();
        }

        delete f;
    }

    reply->deleteLater();
}
