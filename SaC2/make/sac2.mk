###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/sac2.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-04-11
### update:      2013-06-17
### version:     1.0
### description: Generate SaC2 shared objects, and moved them into build/lib
###              directory from current path
###---------------------------------------------------------------------------

include $(SAC2_MAKE_PATH)/sfml.mk

###---------------------------------------------------------------------------
### Define SaC2 source and header path
###---------------------------------------------------------------------------
SAC2_SOURCE_DIR     = $(SAC2_PATH)/src
SAC2_INCLUDES      += -I$(SAC2_PATH)/include/assets \
                      -I$(SAC2_PATH)/include/core \
                      -I$(SAC2_PATH)/include/interfaces \
                      -I$(SAC2_PATH)/include/states \
                      -I$(SAC2_PATH)/include/types \
                      $(SFML_INCLUDES)


SAC2_SOURCES        = $(wildcard $(SAC2_SOURCE_DIR)/*.cpp)
SAC2_OBJECTS        = $(addprefix $(LIBRARY_DIR)/, \
                        $(notdir $(SAC2_SOURCES:.cpp=.o)))

SAC2_SHARED_OBJECT  = $(LIBRARY_DIR)/libsac2.so

SAC2_FLAGS         += -L$(LIBRARY_DIR) \
                      -Wl,-rpath,$(LIBRARY_DIR) \
                      -lsac2

CXXFLAGS           += $(SAC2_INCLUDES)
LDFLAGS            += $(SAC2_FLAGS)

sac2: builddir $(SAC2_SHARED_OBJECT)

ifeq (,$(wildcard $(SAC2_SHARED_OBJECT)))
$(SAC2_SHARED_OBJECT): $(SAC2_SHARED_OBJECT).1
	@echo "Generating shared library \`$(notdir $@)'..."
	@ln -sf $< $@
else
$(SAC2_SHARED_OBJECT): .FORCE
endif

$(SAC2_SHARED_OBJECT).1: $(SAC2_SHARED_OBJECT).1.0
	@ln -sf $< $@

$(SAC2_SHARED_OBJECT).1.0: $(SAC2_OBJECTS)
	@$(CXX) -shared -Wl,-soname,$(SAC2_SHARED_OBJECT).1 \
      -o $(SAC2_SHARED_OBJECT).1.0 $(SAC2_OBJECTS)

$(LIBRARY_DIR)/%.o: $(SAC2_SOURCE_DIR)/%.cpp
	@echo "Building \`$(notdir $@)'..."
	@$(CXX) -fPIC -o $@ -c $< $(CXXFLAGS)

include $(SAC2_MAKE_PATH)/builddir.mk

