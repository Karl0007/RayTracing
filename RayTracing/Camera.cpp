#include "Camera.h"

void Camera::MakePicture(Scene & scene)
{
	int ns = 10;
	Vec3 BasePos = direction - sizex / 2 * horizontal - sizey / 2 * vertical;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < weight; i++) {
			Color c(0, 0, 0);
			for (int k = 0; k < ns; k++) {
				Ray r(original, BasePos + horizontal * (i+randf()-0.5f) * sizex / weight  + vertical * (j + randf() - 0.5f) * sizey / height - original);
				c += scene.GetColor(r);
			}
			c /= ns;
			SaveColor(&picture[(j*weight + i) * 3], c);

			//cout << BasePos + horizontal * i / weight + vertical * j / height << endl;
		}
	}
}
