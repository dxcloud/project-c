###
### SaC2/make/make.mk
###



all: $(BUILD_DIR) $(OUTPUT) 

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OBJ_DIR)

$(OUTPUT): $(OBJ) $(SAC_OBJ)
	@echo "Generating $(EXEC)"
	@$(CXX) -o $@ $^ $(LDFLAGS) $(SFML_FLAGS)
	@echo "Finished"

$(OBJ_DIR)/%.o: %.cpp
	@echo "Generating $(notdir $@)"
	@$(CXX) -o $@ -c $< $(CXXFLAGS);

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Generating $(notdir $@)"
	@$(CXX) -o $@ -c $< $(CXXFLAGS);

FORCE:
