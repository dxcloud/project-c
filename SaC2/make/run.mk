###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/run.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-04-11
### update:      2013-06-18
### version:     1.0
### description: Run the application
###---------------------------------------------------------------------------

run: .FORCE
ifeq (,$(wildcard $(OUTPUT)))
$(info $(SAC2_HELP_RUN))
else
	@echo "Running \`$(EXEC)'..."
	@./build/$(EXEC)
endif

