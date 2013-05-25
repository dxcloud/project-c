###
### SaC2/make/make.mk
###

### SFML path
SFML_PATH      ?= $(SAC_DIR)/libs/SFML-2.0
CXXFLAGS       += -I$(SFML_PATH)/include

LDFLAGS        += -L$(SFML_PATH)/lib \
                  -Wl,-rpath,$(SFML_PATH)/lib \
                  -lsfml-graphics \
                  -lsfml-audio \
                  -lsfml-window \
                  -lsfml-system

all: builddir $(OUTPUT)

include $(SAC_MAKE_DIR)/builddir.mk
include $(SAC_MAKE_DIR)/depend.mk

$(OUTPUT): $(OBJ) $(SAC_OBJ)
	@echo "Generating $(EXEC)"
	@$(CXX) -o $@ $^ $(LDFLAGS)
	@echo "Finished: 'make run' to execute"

$(OBJ_DIR)/%.o: %.cpp
	@echo "Generating $(notdir $@)"
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Generating $(notdir $@)"
	@$(CXX) -o $@ -c $< $(CXXFLAGS)
