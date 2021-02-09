#include "SDLX.h"
#include "RayMarch.h"

Context *get_context(void)
{
	static Context ctx;
	static int seen;

	if (seen == 0)
	{
		Sphere	*sphere;
		Box 	*box;

		ctx.objCount = 2;
		sphere = malloc(sizeof(Sphere));
		box	= malloc(sizeof(Box));
		
		sphere->position.x = 0;
		sphere->position.y = 0;
		sphere->position.z = 50;
		sphere->radius = 20;

		box->position.x = 20;
		box->position.y = 0;
		box->position.z = 40;
		box->volume.x = 5;
		box->volume.y = 5;
		box->volume.z = 5;

		ctx.cam.position.x = 10;
		ctx.cam.position.y = 0;
		ctx.cam.position.z = 0;
		ctx.cam.x_angle = 0;
		ctx.cam.y_angle = 0;

		ctx.light.position.x = 0;
		ctx.light.position.x = 0;
		ctx.light.position.y = 20;

		ctx.light.direction.x = 0;
		ctx.light.direction.y = -1;
		ctx.light.direction.z = 0;

		ctx.objs = malloc(2 * sizeof(Object));
		ctx.objs[0].objData = (void *)sphere;
		ctx.objs[0].sdf = Sphere_SDF;
		
		ctx.objs[1].objData = (void *)box;
		ctx.objs[1].sdf = Box_SDF;
		seen = 1;
	}

	return &ctx;
}

int main(int argc, char const *argv[])
{
	SDLX_Display *display;
	display = get_display();

	while (1)
		SDLX_Update();
	return 0;
}
