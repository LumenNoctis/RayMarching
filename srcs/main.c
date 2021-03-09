#include "SDLX.h"
#include "RayMarch.h"

Context *get_context(void)
{
	Sphere	*sphere;
	Box 	*box;
	static Context ctx;
	static int seen;

	if (seen == 0)
	{

		ctx.objCount = 1;
		sphere = malloc(sizeof(Sphere));
		box	= malloc(sizeof(Box));
		
		sphere->position.x = 0;
		sphere->position.y = 0;
		sphere->position.z = 30;
		sphere->radius = 60;

		box->position.x = 0;
		box->position.y = 0;
		box->position.z = 30;
		box->volume.x = 60;
		box->volume.y = 60;
		box->volume.z = 60;

		ctx.cam.position.x = 0;
		ctx.cam.position.y = 0;
		ctx.cam.position.z = 0;
		ctx.cam.x_angle = 0;
		ctx.cam.y_angle = 0;

		ctx.light.position.x = 0;
		ctx.light.position.x = 0;
		ctx.light.position.y = 20;

		ctx.light.direction.x = 0.5;
		ctx.light.direction.y = -0.5;
		ctx.light.direction.z = 0;

		ctx.objs = malloc(2 * sizeof(Object));
		ctx.objs[0].objData = (void *)sphere;
		ctx.objs[0].sdf = Sphere_SDF;
		
		//ctx.objs[0].objData = (void *)box;
		//ctx.objs[0].sdf = Box_SDF;
		seen = 1;
	}

	return &ctx;
}

int main(int argc, char const *argv[])
{
	SDLX_Display *display;
	display = SDLX_get_display();
	get_context();
	//ComputeDeltas();
	while (1)
		SDLX_Update();
	return 0;
}
