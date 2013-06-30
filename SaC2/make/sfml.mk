###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/sfml.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-04-11
### update:      2013-06-17
### version:     1.0
### description: Define SMFL compilation and linkage flags
###---------------------------------------------------------------------------

SFML_PATH          ?= $(SAC2_PATH)/libs/SFML-2.0
SFML_INCLUDES       = -I$(SFML_PATH)/include \
                      -isystem $(SFML_PATH)/include

SFML_FLAGS         += -L$(SFML_PATH)/lib \
                      -lsfml-graphics \
                      -lsfml-audio \
                      -lsfml-window \
                      -lsfml-system \
                      -Wl,-rpath,$(SFML_PATH)/lib

CXXFLAGS           += $(SFML_INCLUDES)

LDFLAGS            += $(SFML_FLAGS)
