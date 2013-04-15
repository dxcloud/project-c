###
### SaC2/make/run.mk
###

define RUN_FAILED
The executable does NOT exist. \
Compile the application with 'make'.
endef

run: FORCE
ifeq (yes,$(BUILD_FLAG))
  ifneq (,$(findstring $(EXEC),$(shell ls $(BUILD_DIR))))
	./build/$(EXEC)
  else
	@echo $(RUN_FAILED)
  endif
else
	@echo $(RUN_FAILED)
endif
