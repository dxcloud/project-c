###
### SaC2/make/make.mk
###

### SFML path
SFML_PATH      ?= /usr/local/lib
SFML_FLAGS     += -L$(SFML_PATH)
SFML_FLAGS     += -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

all: builddir $(OUTPUT)

include $(SAC_MAKE_DIR)/builddir.mk
include $(SAC_MAKE_DIR)/depend.mk

$(OUTPUT): $(OBJ) $(SAC_OBJ)
	@echo "Generating $(EXEC)"
	@$(CXX) -o $@ $^ $(LDFLAGS) $(SFML_FLAGS)
	@echo "Finished: 'make run' to execute"

$(OBJ_DIR)/%.o: %.cpp
	@echo "Generating $(notdir $@)"
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Generating $(notdir $@)"
	@$(CXX) -o $@ -c $< $(CXXFLAGS)
