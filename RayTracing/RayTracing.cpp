#include "RayTracing.h"

RayTracing::RayTracing(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Scene s;
	QFile file("in.txt");
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	std::stringstream ss(file.readLine().constData());
	int t;
	ss >> t;
	while (t--) {
		float x, y, z, r, R, G, B;
		std::stringstream ss(file.readLine().constData());
		ss >> x >> y >> z >> r >> R >> G >> B;
		int tmp = s.AddSphere(Vec3(x, y, z), r);
		s.GetObj(tmp)->SetColor(Color(R, G, B));

	}
	//s.AddSphere(Vec3(6, 1, 0), 3, 1);
	//s.AddSphere(Vec3(7, -2, -1), 2, 1);
	//cout << s.GetObj(1)->hit(Ray(Vec3(0, 0, 0), Vec3(1, 1, 1))) << endl;
	camera.Init(200,200,10,10,Vec3(-6,0,0),Vec3(6,0,0),Vec3(0,0,-1));
	camera.MakePicture(s);
	//QWidget temp(this);
	//temp.show();

}

void RayTracing::paintEvent(QPaintEvent * e)
{
	QImage img(camera.picture,camera.weight, camera.height, QImage::Format::Format_RGB888);
	QPainter paint(this);
	paint.drawImage(0, 0, img);
	paint.drawLine(0, 0, 10, 10);
}
