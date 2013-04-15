###
### SaC2/make/builddir.mk
###

builddir:
ifneq (yes,$(BUILD_FLAG))
	@echo "Creating 'build' directory"
endif
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OBJ_DIR)
#	@mkdir -p $(DEP_DIR)
