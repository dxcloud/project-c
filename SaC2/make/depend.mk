###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/sac2.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-04-11
### update:      2013-06-17
### version:     1.0
### description: List the dependencies of the source files
###---------------------------------------------------------------------------

include $(SAC2_MAKE_PATH)/sac2.mk

depend: builddir $(DEPFILE)
ifeq (yes,$(SHOW_DEPENDENCIES))
	@cat $(DEPFILE)
endif

$(DEPFILE): $(SOURCES)
	@echo "Generating Dependencies..."
	@set -e rm -f $@; \
    $(CXX) -MM $(CXXFLAGS) $^ > $@.$$$$; \
    sed 's:[_a-zA-Z0-9]*\.o:$(OBJECT_DIR)/&:g' < $@.$$$$ > $@; \
    rm -f $@.$$$$

-include $(DEPFILE)

