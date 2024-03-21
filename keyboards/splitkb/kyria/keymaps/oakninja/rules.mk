OLED_ENABLE = yes
OLED_DRIVER = SSD1306   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

WPM_ENABLE = yes
EXTRAKEY_ENABLE = yes  # Media

QMK_LOGO_ENABLE = no
KYRIA_LOGO_ENABLE = no


# Conway's Game of Life
#
## Compile for master?
#MASTER_HALF ?= yes
#
## Enable Conway?
#CONWAY_ENABLE ?= yes
## Run conway on master?
#CONWAY_MASTER ?= yes
#
## Fix kyria / split keyboard matrix. Spawn points of right half to the right
## For other split kbs, other than the SplitKB Kyria™ you may want to adjust the corresponding code.
#KYRIA_MATRIX_FIX ?= yes
## Edge behaviour, kill points on edges?
#EGDE_KILL ?= yes
## spawn in more random points, the longer a key is pressed. Look in conway.h to adjust interval times.
#HELD_SPAWN ?= yes
#
#ifeq ($(strip $(MASTER_HALF)), yes)
#    OPT_DEFS += -DMASTER_HALF
#endif
#ifeq ($(strip $(CONWAY_ENABLE)), yes)
#    SRC += conway.c
#    OPT_DEFS += -DCONWAY_ENABLE
#    OLED_ENABLE = yes
#    OLED_DRIVER_ENABLE = yes
#endif
#
#ifeq ($(strip $(CONWAY_MASTER)), yes)
#    ifeq ($(strip $(MASTER_HALF)), yes)
#        CONWAY_RENDER = yes
#        OPT_DEFS += -DCONWAY_RENDER
#    endif
#else ifeq ($(strip $(CONWAY_MASTER)), no)
#    ifeq ($(strip $(MASTER_HALF)), no)
#        CONWAY_RENDER = yes
#        OPT_DEFS += -DCONWAY_RENDER
#    endif
#endif
#ifeq ($(strip $(KYRIA_MATRIX_FIX)), yes)
#    OPT_DEFS += -DKYRIA_MATRIX_FIX
#endif
#ifeq ($(strip $(EGDE_KILL)), yes)
#    OPT_DEFS += -DEGDE_KILL
#endif
#ifeq ($(strip $(HELD_SPAWN)), yes)
#    OPT_DEFS += -DHELD_SPAWN
#endif
## Conway's Game of Life end


#SRC += oled.c
