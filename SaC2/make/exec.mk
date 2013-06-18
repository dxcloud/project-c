###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/exec.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-04-11
### update:      2013-06-17
### version:     1.0
### description: Generate SaC2 shared objects, and moved them into build/lib
###              directory from current path
###---------------------------------------------------------------------------

### Executable parameters
EXEC               ?= main.out
OUTPUT              = $(addprefix $(BUILD_DIR)/,$(EXEC))

### C++ Compiler default parameters
CXX                ?= g++
OPTFLAGS           ?= -O2
CXXFLAGS           += $(CFLAGS) $(OPTFLAGS)
CXXFLAGS           += -Wall -pedantic -std=c++11 -g

OBJECTS             = $(addprefix $(OBJECT_DIR)/,$(SOURCES:.cpp=.o))

exec: depend $(OUTPUT)

$(OUTPUT): sac2 $(OBJECTS)
	@echo "Generating executable \`$(EXEC)'..."
	@$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)
	@echo "Finished: type \`make run' to execute,"
	@echo "          or \`make memcheck' for memory leak checking"

$(OBJECT_DIR)/%.o: %.cpp
	@echo "Building \`$(notdir $@)'..."
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

include $(SAC2_MAKE_PATH)/depend.mk

