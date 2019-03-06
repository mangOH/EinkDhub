# Integrate littlevgl into legato app
This project demo how to integrate littlevlgl into legato app

## Project Setup
1. Clone lvgl library and create project:
    * lvgl: https://github.com/littlevgl/lvgl
    * lvgl drivers: https://github.com/littlevgl/lv_drivers
    * Copy `lvgl/lv_conf_templ.h` change the name to `lv_conf.h` and place next to the lvgl folder  
    * Copy `lv_drivers/lv_drv_conf_templ.h` change the name to `lv_drv_conf.h` and place next to the lvgl folder   
    
2. Update configure file `lv_conf.h` for monochome display:
   * Enable config content by set:
      ```c
      #if 1 /*Set it to "1" to enable the content*/

   * Update logical dimension of screenfor waveshare eink 2.13 Inch: 
       ```c
       #define LV_HOR_RES          (128)
       #define LV_VER_RES          (250)
       
   * Update default font type to use monochome font: 
      ```c
      #define LV_FONT_DEFAULT        &lv_font_monospace_8
      
   * Update font size for using font size 8: 
      ```c
      #define USE_LV_FONT_MONOSPACE_8         1
     
   * Update Color Depth is 1: 
      ```c
      #define LV_COLOR_DEPTH     1                     /*Color depth: 1/8/16/32*/
     
