#!/bin/bash
### Set SaC2 environment variables

### Path to this file
SAC_MAKE_DIR=$(locate -l 1 SaC2/make)
SAC_DIR=$(dirname $SAC_MAKE_DIR)

### Path of the generic Makefile and Makerules directory
SAC_MAKE=$SAC_MAKE_DIR/rules.mk

### Test if makefile.mk exist
if [ ! -e $SAC_MAKE ]; then
  echo "$SAC_MAKE: Not such file"
else
  export SAC_DIR
  export SAC_MAKE_DIR
  export SAC_MAKE
  echo "SaC2 set up"
fi
