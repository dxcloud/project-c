###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/memcheck.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-04-11
### update:      2013-06-17
### version:     1.0
### description: Run application and check memory leak.
###---------------------------------------------------------------------------

MEMCHECK_FLAGS     +=

memcheck: .FORCE
ifeq (,$(wildcard $(OUTPUT)))
  $(info $(SAC2_HELP_RUN))
else
	@echo "Running \`$(EXEC)' for memory leak detection..."
	@valgrind $(MEMCHECK_FLAGS) ./build/$(EXEC)
endif

