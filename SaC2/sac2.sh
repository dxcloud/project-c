#!/bin/sh
### Set SaC2 environment variables
### Author:      Chengwu Huang
### Last update: 2013-06-18

SAC2_MAKERULES=$(locate -l 1 SaC2/make/rules.mk)
if [ ! -e $SAC2_MAKERULES ]; then
  echo "Error: unable to locate file \`SaC2/make/rules.mk'"
  return
fi

SAC2_MAKE_PATH=$(dirname $SAC2_MAKERULES)
SAC2_PATH=$(dirname $SAC2_MAKE_PATH)
SFML_PATH=$SAC2_PATH/libs/SFML-2.0

echo "Exporting \`SAC2_PATH=$SAC2_PATH'..."
export SAC2_PATH
echo "Exporting \`SAC2_MAKE_PATH=$SAC2_MAKE_PATH'..."
export SAC2_MAKE_PATH
echo "Exporting \`SAC2_MAKERULES=$SAC2_MAKERULES'..."
export SAC2_MAKERULES
echo "Exporting \`SFML_PATH=$SFML_PATH'..."
export SFML_PATH

if [ -z $(echo $PATH | grep $SAC2_PATH/tools/bin) ]; then
  echo "Exporting \`PATH=$PATH:$SAC2_PATH/tools/bin'..."
  export PATH=$PATH:$SAC2_PATH/tools/bin
fi

echo "SaC2 environment variables set up"

