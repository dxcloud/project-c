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
###              from current directory
###---------------------------------------------------------------------------

include $(SAC2_MAKE_PATH)/depend.mk
include $(SAC2_MAKE_PATH)/sac2.mk

OBJECTS             = $(addprefix $(OBJECT_DIR)/,$(SOURCES:.cpp=.o))

CXXFLAGS += -g -DLOGGER_ENABLED

exec: sac2 depend $(OUTPUT)
	@echo "Finished: type \`make run' to execute,"
	@echo "          or \`make memcheck' for memory leak checking"

$(OUTPUT): $(OBJECTS) $(SAC2_SHARED_OBJECT)
	@echo "Generating executable \`$(EXEC)'..."
	@$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)

$(OBJECT_DIR)/%.o: %.cpp
	@echo "Building \`$(notdir $@)'..."
	@$(CXX) -o $@ -c $< $(CXXFLAGS)
