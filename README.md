# Integrate littlevgl into legato app
This project demo how to integrate littlevlgl into legato app

## Project Setup
1. Clone lvgl library and create project:
    * lvgl: https://github.com/littlevgl/lvgl
    * lvgl drivers: https://github.com/littlevgl/lv_drivers
    * Copy `lvgl/lv_conf_templ.h` change the name to `lv_conf.h` and place next to the lvgl folder  
    * Copy `lv_drivers/lv_drv_conf_templ.h` change the name to `lv_drv_conf.h` and place next to the lvgl folder
    
We have app tree as bellow:

   <img src="https://user-images.githubusercontent.com/17214533/53871383-b9b79400-402e-11e9-9690-898d3abe6bf2.png" width="350" alt="accessibility text">       

2. Update configure file `lv_conf.h` for monochome display:
   * Enable config content by set:
      ```c
      #if 1 /*Set it to "1" to enable the content*/

   * Update logical dimension of screen for waveshare eink 2.13 Inch: 
       ```c
       #define LV_HOR_RES          (128)
       #define LV_VER_RES          (250)
       
   * Update default font type to use monochome font: 
      ```c
      #define LV_FONT_DEFAULT        &lv_font_monospace_8
      
   * Enable font size 8 for monochome display and disable unsupported font: 
      ```c
      #define USE_LV_FONT_DEJAVU_10              0
      #define USE_LV_FONT_DEJAVU_10_LATIN_SUP    0
      #define USE_LV_FONT_DEJAVU_10_CYRILLIC     0
      #define USE_LV_FONT_SYMBOL_10              0

      #define USE_LV_FONT_DEJAVU_20              0
      #define USE_LV_FONT_DEJAVU_20_LATIN_SUP    0
      #define USE_LV_FONT_DEJAVU_20_CYRILLIC     0
      #define USE_LV_FONT_SYMBOL_20              0

      #define USE_LV_FONT_DEJAVU_30              0
      #define USE_LV_FONT_DEJAVU_30_LATIN_SUP    0
      #define USE_LV_FONT_DEJAVU_30_CYRILLIC     0
      #define USE_LV_FONT_SYMBOL_30              0

      #define USE_LV_FONT_DEJAVU_40              0
      #define USE_LV_FONT_DEJAVU_40_LATIN_SUP    0
      #define USE_LV_FONT_DEJAVU_40_CYRILLIC     0
      #define USE_LV_FONT_SYMBOL_40              0

      #define USE_LV_FONT_MONOSPACE_8            1
     
   * Update Color Depth is 1: 
      ```c
      #define LV_COLOR_DEPTH     1                     /*Color depth: 1/8/16/32*/
     
