###
### SaC2/make/clean.mk
###

clean: FORCE
ifneq (,$(shell ls | grep $(OBJ_DIR)))
	@rm -rf *~ $(OBJ_DIR)/*.o
	@echo "Object files from 'build' directory removed"
else
	@echo "Nothing to be removed"
endif

FORCE:
