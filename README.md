# Experimental dhub app that displays simple strings on a Framebuffer device assuming Eink

Integration of LittlevGL graphics library with Dhub interface app to allow
writes to a Framebuffer device. So far tested with Waveshare 2.13
e-Paper display with associated kernel modules also under the experimental
directory.

The necessary LittlevGL dependencies are referenced by this repository as git submodules.

## Issues and things to fix
1. LittlevGL may not be the best fit to display for e-Paper displays as it based on a
	refresh architecture which we have worked around by short segments calling
	the tick polling routine and the task handler polling routine (count of 4 currently).
	A better design is needed here.

1. We have built a dependency on the Waveshare 2.13 e-Paper display - ideally, this should
	be removed - currently, with littlevgl & the Waveshare a 20 sec. delay is needed
	between writes or the display gets messed up. These delays may be better served in the driver.
	Or maybe SPI handshaking can be used? After all a SPI busy line does exist.

1. We had ghosting issues (https://www.waveshare.com/wiki/2.13inch_e-Paper_HAT) with the Eink
	driver & LittlevGL thus changed the driver to full refresh only. Also, LittlevGL
	needed virtual display buffer invalidation to work around updates overwriting each other.

1. LittlevGL should be a component library and not embedded with the app as now.

1. littlevLegatoComponent/littlevgl/Makefile has a clean target to clean the library - need to integrate
	with core Makefile/adef. For now, to clean change dir and manually clean 

1. Base the littlevgl fork from a tagged release: https://github.com/littlevgl/lvgl/releases

1. Upgrade to the latest - we are using a non-tagged 5.3 in the works - this is not correct.

1. Lastly. for Eink displays the high polling rate of 2 tasks (the task_handler has much more
	code) for persistent displays does not make sense. Consider, other graphics libraries,
	e.g. DirectFB (not being actively worked - last update 2014).

## Setup if from Scratch
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

      #define USE_LV_FONT_DEJAVU_20              1
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
