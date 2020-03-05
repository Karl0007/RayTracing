#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RayTracing.h"
#include "Head.h"
#include "Camera.h"

class RayTracing : public QMainWindow
{
	Q_OBJECT

public:
	RayTracing(QWidget *parent = Q_NULLPTR);
	void paintEvent(QPaintEvent *e);
private:
	Camera camera;
	Ui::RayTracingClass ui;
};
