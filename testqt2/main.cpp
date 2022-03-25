#include <QCoreApplication>
#include <QTextStream>
#include <numbers>
//%{CurrentProject:NativePath}/build/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream(stdout) << "hello\n";
    return a.exec();
}
