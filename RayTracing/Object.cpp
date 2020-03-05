#include "Object.h"
#include "Ray.h"
#include "Head.h"

float Sphere::hit(Ray & r)
{
	Vec3 oc = r.ori - center;
	Vec3 dir = r.dir.normalized();
	float a = 1.0f;
	float b = 2.0f*oc.dot(dir);
	float c = -radius * radius + oc.dot(oc);
	float delata = b * b - 4.0f*a*c;
	if (delata > 0) {
		return  (-b - sqrt(delata)) / (2 * a);
	}
	else {
		return -1;
	}
}

Vec3 Sphere::normal(Vec3 & v)
{
	return (v-center).normalized();
}
