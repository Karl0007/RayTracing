#include "RayTracing.h"
#include <QtWidgets/QApplication>
#include "Head.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RayTracing w;
	w.show();
	return a.exec();
}
