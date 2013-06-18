###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/mrproper.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-04-11
### update:      2013-06-17
### version:     1.0
### description: Remove all generated files and directories
###---------------------------------------------------------------------------

mrproper: distclean
	@echo "Remove \`build' and \`docs' directories"
	@rm -rf build/ docs/

include $(SAC2_MAKE_PATH)/distclean.mk

