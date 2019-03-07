# Integrate LittlevGL into Legato app

This project demonstrates how to integrate LittlevlGL into a Legato app. The necessary LittlevGL
dependencies are referenced by this repository as git submodules.

## Setup
1. Clone this repository with the `--recursive` option so that the submodules are retrieved as well.
1. `cp littlevLegatoComponent/littlevgl/lvgl/lv_conf_templ.h littlevLegatoComponent/littlevgl/lv_conf.h`
1. `cp littlevLegatoComponent/littlevgl/lv_drivers/lv_drv_conf_templ.h littlevLegatoComponent/littlevgl/lv_drv_conf.h`
1. Make the following changes to `littlevLegatoComponent/littlevgl/lv_conf.h`:
   1. At the top of the file, change the `#if 0` to `#if 1` to enable the file
   1. Update logical dimension of screen for waveshare eink 2.13 Inch:
      ```c
      #define LV_HOR_RES          (122)
      #define LV_VER_RES          (250)
      ```
   1. Update default font type to use monochrome font:
      ```c
      #define LV_FONT_DEFAULT        &lv_font_monospace_8
      ```
   1. Enable font size 8 for monochrome display and disable unsupported font:
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
      ```
   1. Update Color Depth to be 1:
      ```c
      #define LV_COLOR_DEPTH     1                     /*Color depth: 1/8/16/32*/
      ```
1. Make the following changes to `littlevLegatoComponent/littlevgl/lv_drv_conf.h`:
   1. At the top of the file, change the `#if 0` to `#if 1` to enable the file
   1. Update USE_FBDEV to 1 for using framebuffer device
      ```c
      #define USE_FBDEV         1
      ```
1. In `/lv_drivers/fbdev.c` update function `fbdev_flush` for  /*1 bit per pixel*/
      ```c
      fbp8[byte_location] &= ~(((uint8_t)(128)) >> bit_location);
      fbp8[byte_location] |= ((uint8_t)(color_p->full << 7)) >> bit_location;
      ```
