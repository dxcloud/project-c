###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/srg.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-06-27
### version:     1.0
### description: Call `srg' tool
###---------------------------------------------------------------------------

define NO_RESOURCE_WARN
Warning: RESOURCE_FILE was NOT defined.
         Default resources will be used instead.
endef

ifeq (,$(RESOURCE_FILE))
$(info $(NO_RESOURCE_WARN))
CXXFLAGS           += -DUSE_DEFAULT_RESOURCE
endif

SRG_TOOL_PATH      ?= $(shell locate -l 1 SaC2/tools/srg)
SRG_TOOL_BIN        = $(dir $(SRG_TOOL_PATH))/bin/srg

srg: .FORCE
ifneq (,$(RESOURCE_FILE))
	make -f $(SRG_TOOL_PATH)/Makefile
	srg $(RESOURCE_FILE)
endif
