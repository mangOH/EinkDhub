#include "legato.h"
#include "lvgl.h"
#include "fbdev.h"
//#include "lv_drv_conf.h"
#include "lv_conf.h"


COMPONENT_INIT
{
	LE_INFO("Start Eink LittlevGL.");
    lv_init();

	/*Linux frame buffer device init*/
	fbdev_init();
}
