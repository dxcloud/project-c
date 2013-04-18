###
### SaC2/make/clean.mk
###

clean:
	@rm -rf *~ $(OBJ_DIR)/*.o $(DEPFILE)
	@echo "Object files removed"
