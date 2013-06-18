###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/builddir.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-04-11
### update:      2013-06-17
### version:     1.0
### description: Create necessary directories
###---------------------------------------------------------------------------

builddir:
	@if [ ! -d "$(BUILD_DIR)" ]; then \
    echo "Creating directory \`build'..."; \
    mkdir $(BUILD_DIR); \
	fi
	@if [ ! -d "$(OBJECT_DIR)" ]; then \
    echo "Creating directory \`build/objs'..."; \
    mkdir $(OBJECT_DIR); \
	fi
	@if [ ! -d "$(LIBRARY_DIR)" ]; then \
    echo "Creating directory \`build/lib'..."; \
    mkdir $(LIBRARY_DIR); \
	fi

