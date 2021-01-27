#include "SDLX.h"
#include "RayMarch.h"

Context *get_context(void)
{
	static Context ctx;
	static int seen;


	if (seen == 0)
	{
		ctx.scene.position.x = -5;
		ctx.scene.position.y = 0;
		ctx.scene.position.z = 30;
		ctx.scene.radius = 10;
		
		ctx.scene1.position.x = 0;
		ctx.scene1.position.y = 0;
		ctx.scene1.position.z = 30;
		ctx.scene1.radius = 10;

		ctx.cam.position.x = 0;
		ctx.cam.position.y = 0;
		ctx.cam.position.z = 0;
		ctx.cam.x_angle = 0;
		ctx.cam.y_angle = 0;

		seen = 1;
	}

	return &ctx;
}

int main(int argc, char const *argv[])
{
	SDLX_Display *display;
	MT_Vector3 v;
	display = get_display();

	v = MT_V3FromAngle_Deg(90, 0, 1);
	// printf("x %f y %f z %f\n",v.x, v.y, v.z);
	// exit(0);
	while (1)
		SDLX_Update();
	return 0;
}
