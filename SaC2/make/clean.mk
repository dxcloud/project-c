###
### SaC2/make/clean.mk
###

clean: FORCE
	@rm -rf *~ $(OBJ_DIR)/*.o
	@echo "Object files removed"

FORCE:
