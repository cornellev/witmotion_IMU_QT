#include "witmotion/wt31n-uart.h"
#include <unistd.h>
#include <thread>
using namespace witmotion::wt31n;

void init(int argc, char** args)
{
    QCoreApplication app(argc, args);
    QWitmotionWT31NSensor sensor("ttyUSB0", QSerialPort::Baud9600);
    sensor.setParent(&app);
    sensor.Start();
    app.exec();
}

int main(int argc, char** args)
{
    std::thread app_thread(init, argc, args);
    sleep(5);
    QCoreApplication::exit(0);
    app_thread.join();
    return 0;
}
