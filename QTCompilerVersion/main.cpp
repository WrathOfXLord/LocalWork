#include <QApplication>
#include <QLabel>
#include <QTextStream>
#include <numbers>
//%{CurrentProject:NativePath}/build/

using QLabelptr = QLabel *;
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabelptr label {new QLabel {"Hello World"}};
    label->resize(800, 600);
    label->setWindowTitle("Very First Program");
    label->show();
    return app.exec();

}
