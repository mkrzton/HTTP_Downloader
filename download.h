#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>


class download : public QObject{

    Q_OBJECT

public:

    explicit download(QObject *parent = nullptr);
    void StartDownload();

signals:

public slots:

    void Response(QNetworkReply *reply);

private:

    QNetworkAccessManager *NAM;
};

#endif // DOWNLOAD_H
