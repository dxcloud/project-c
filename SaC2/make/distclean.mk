###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/sac2.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-04-11
### update:      2013-06-17
### version:     1.0
### description: Remove SaC2 shared library
###---------------------------------------------------------------------------

distclean: clean
	@rm -rf $(LIBRARY_DIR)/*.so $(LIBRARY_DIR)/*.so.1 $(LIBRARY_DIR)/*.so.1.0
	@echo "SaC2 shared library removed"

include $(SAC2_MAKE_PATH)/clean.mk

