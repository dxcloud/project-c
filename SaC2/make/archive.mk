###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/archive.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-06-18
### version:     1.0
### description: Make an archive of the current directory.
###              `build' or `docs' directories are ignored.
###---------------------------------------------------------------------------

TAR_SUFFIX          = .tar.gz

TAR_EXCLUDES        = --exclude=*~ \
                      --exclude=build \
                      --exclude=docs

TAR_FILENAME        = $(addsuffix $(TAR_SUFFIX),$(shell basename $(WORK_DIR)))

archive:
	@if [ ! -e $(TAR_FILENAME) ]; then \
    echo "Creating archive \`$(TAR_FILENAME)'..."; \
    tar $(TAR_EXCLUDES) -czf $(TAR_FILENAME) *; \
  else \
    echo "The archive \`$(TAR_FILENAME)' already existed"; \
  fi

