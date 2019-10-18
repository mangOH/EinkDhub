/**
 * @file
 *
 * This app triggers on a text writes to dhub writeEink and writes the text to the
 * Eink display.
 *
 * <HR>
 *
 * Copyright (C) Sierra Wireless, Inc. Use of this work is subject to license.
 */

#include "legato.h"
#include "interfaces.h"
#include "lvgl.h"
#include "fbdev.h"
#include "lv_conf.h"

// Littlevgl suggested minimum interval
#define DISPLAY_SAMPLE_INTERVAL_IN_MILLISECONDS (5)

// Our Hack in timings for refresh and Eink write time waits
#define NUM_LV_TICKS_REFRESH_HACK	4
#define NUM_SECS_EINK_WRITE_WAIT_HACK	10

// for dhub
#define RES_PATH_WRITE_EINK     "value"


static lv_obj_t * label;
static lv_disp_drv_t disp_drv;

static void WriteEink(double timestamp, const char *textToWrite, void *contextPtr)
{

    // Invalidate the virtual display buffer
    lv_obj_invalidate(label);

    // Display text with alignment, break/wrap, and within display width
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);
    lv_label_set_text(label, textToWrite);
    //lv_label_set_text(label, "GOODBYE\nWORLD");
    lv_obj_set_width(label, LV_HOR_RES);
    lv_obj_align(label, NULL, LV_LABEL_ALIGN_CENTER, 0, 0);

    /*  TODO: fix - currently we have timed how long the driver
     *  and the Eink display takes to do updates and the code
     *  below works, must be a cleaner way.
     */

    for(int i = 0 ; i < NUM_LV_TICKS_REFRESH_HACK ; i++)
    {
        lv_tick_inc(DISPLAY_SAMPLE_INTERVAL_IN_MILLISECONDS);
        lv_task_handler();
    }

    /* Eink display seems to need time between writes or it get's messed up.
     * Properly waits & readiness belong in the driver - TODO: fix driver.
     */
    sleep(NUM_SECS_EINK_WRITE_WAIT_HACK);

}

COMPONENT_INIT
{

    lv_init();

    // Linux frame buffer device init
    fbdev_init();

    // Add a display to LittlevGL using the frame buffer driver
    lv_disp_drv_init(&disp_drv);

    // Flush the internal graphical buffer to the frame buffer
    disp_drv.disp_flush = fbdev_flush;
    lv_disp_drv_register(&disp_drv);

    // Create our label object taht will hold the text
    label = lv_label_create(lv_scr_act(), NULL);

    // Create dhub resources
    LE_ASSERT(LE_OK == dhubIO_CreateOutput(RES_PATH_WRITE_EINK, DHUBIO_DATA_TYPE_STRING, ""));
    dhubIO_AddStringPushHandler(RES_PATH_WRITE_EINK, WriteEink, NULL);
    dhubIO_MarkOptional(RES_PATH_WRITE_EINK);

}
