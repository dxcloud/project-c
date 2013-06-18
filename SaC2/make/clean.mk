###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/clean.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-04-11
### update:      2013-06-17
### version:     1.0
### description: Remove all objects files
###---------------------------------------------------------------------------

clean: .FORCE
	@rm -rf *~ $(OBJECT_DIR)/*.o $(LIBRARY_DIR)/*.o
	@rm -rf $(DEPFILE)
	@echo "Remove all object files"

