# Integrate littlevgl into legato app
This project demo how to integrate littlevlgl into legato app

## Project Setup
1. clone lvgl library and create project:
    * lvgl: https://github.com/littlevgl/lvgl
    * lvgl examples: https://github.com/littlevgl/lv_examples
    * Copy `lvgl/lv_conf_templ.h` change the name to `lv_conf.h` and place next to the lvgl folder    
2. Update configure file for monochome display in `lv_conf.h`:
   * Update default font type: `#define LV_FONT_DEFAULT        &lv_font_monospace_8` for using monochome font.
   * Update font size: `#define USE_LV_FONT_MONOSPACE_8         1` for using font size 8.
   * Update logical dimension of screen: 
        width: `#define LV_HOR_RES          (128)`
        height: `#define LV_VER_RES         (250)` for waveshare eink 2.13 Inch
     
