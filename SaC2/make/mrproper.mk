###
### SaC2/make/mrproper.mk
###

include $(SAC_MAKE_DIR)/clean.mk

mrproper: clean FORCE
	@rm -rf build docs
	@echo "Remove build and docs directories"

FORCE:
