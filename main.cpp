#include <QCoreApplication>
#include "download.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    download done;
    done.StartDownload();


    return a.exec();
}
