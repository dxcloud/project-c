###
### SaC2/make/docs.mk
###

### Set configuration filename
DOC_DIR         = $(BASE_DIR)/docs
DOXYFILE        = $(DOC_DIR)/Doxyfile

### Generate documentation
docs: $(DOXYFILE)
	@echo "Making Documentation (Doxygen)"
	@cat $<.tmp > $<; rm $<.tmp
	@doxygen $<
	@echo "Consult documentation in 'docs' directory"

### Create configuration file from a template
### The following options are modifyed to match the project
###     PROJECT_NAME       Same as executable
###     OUTPUT_DIRECTORY   'docs' directory
###     INPUT              Includes also SaC2 files
$(DOXYFILE): FORCE
	@mkdir -p $(DOC_DIR)
	@cp $(SAC_MAKE_DIR)/Doxyfile $(DOC_DIR)/
	@sed -e '97a\INPUT                  = $(SAC_DIR) $(BASE_DIR)' \
	 -e '10a\OUTPUT_DIRECTORY       = $(DOC_DIR)' \
	 -e '6a\PROJECT_NAME           = "$(EXEC)"' <$@ > $@.tmp

FORCE:
