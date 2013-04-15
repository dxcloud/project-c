###
### SaC2/make/depend.mk
###

depend: $(DEPFILE) FORCE

$(DEPFILE): $(SRC) $(SAC_SRC)
	@echo "Generating Dependencies"
	@mkdir -p $(BUILD_DIR)
	@set -e rm -f $@; \
	$(CXX) -MM $(CXXFLAGS) $^ > $@.$$$$; \
	sed 's:[_a-zA-Z0-9]*\.o:$(OBJ_DIR)/&:g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(DEPFILE)
