#include "legato.h"
#include "lvgl.h"
#include "fbdev.h"
#include "lv_conf.h"

#define DISPLAY_SAMPLE_INTERVAL_IN_MILLISECONDS (100)

static void DisplayTimerHandler
(
    le_timer_Ref_t displayTimerRef
)
{
    lv_tick_inc(5);
    lv_task_handler();
}

COMPONENT_INIT
{
    LE_INFO("Start Eink LittlevGL.");
    lv_init();

    // Linux frame buffer device init
    fbdev_init();

    // Add a display the LittlevGL using the frame buffer driver
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);

    // Flush the internal graphical buffer to the frame buffer
    disp_drv.disp_flush = fbdev_flush;
    lv_disp_drv_register(&disp_drv);

    // Display a label
    lv_obj_t * label = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(label, "Hello World!");
    lv_obj_align(label, NULL, LV_LABEL_ALIGN_CENTER, 0, 0);

    // Timer to display
    le_timer_Ref_t displayTimerRef = le_timer_Create("Display Timer");
    LE_ASSERT_OK(le_timer_SetMsInterval(displayTimerRef, DISPLAY_SAMPLE_INTERVAL_IN_MILLISECONDS));
    LE_ASSERT_OK(le_timer_SetRepeat(displayTimerRef, 0));
    LE_ASSERT_OK(le_timer_SetHandler(displayTimerRef, DisplayTimerHandler));
    LE_ASSERT_OK(le_timer_Start(displayTimerRef));
}
