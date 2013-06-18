###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/docs.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-04-11
### update:      2013-06-18
### version:     1.0
### description: Generate SaC2 shared objects, and moved them into build/lib
###              directory from current path
###---------------------------------------------------------------------------

### Set configuration filename
DOC_DIR             = $(WORK_DIR)/docs
DOXYFILE            = $(DOC_DIR)/Doxyfile

### Generate documentation
docs: $(DOXYFILE)
	@echo "Generating documentation..."
	@doxygen $<
	@ln -s $(DOC_DIR)/html/index.html $(DOC_DIR)/index.html
	@echo "View documentation in \`docs' directory"

### Create configuration file from a template
### The following options are modifyed to match the project
###     PROJECT_NAME       Same as executable
###     OUTPUT_DIRECTORY   Set to 'docs' directory
###     INPUT              Includes also SaC2 files
$(DOXYFILE):
	@if [ ! -d "$(DOC_DIR)" ]; then \
    echo "Creating directory \`build'..."; \
    mkdir $(DOC_DIR); \
	fi
	echo "copy template"
	@cp $(SAC2_MAKE_PATH)/Doxyfile $(DOC_DIR)/
	@sed -e '97a\INPUT                  = $(SAC_DIR) $(BASE_DIR)' \
	 -e '10a\OUTPUT_DIRECTORY       = $(DOC_DIR)' \
	 -e '6a\PROJECT_NAME           = "$(EXEC)"' <$@ > $@.tmp
	@cat $@.tmp > $@; rm $@.tmp

