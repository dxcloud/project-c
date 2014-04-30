##
##  test_03
##

include $(SAC2_MAKE_PATH)/sfml.mk

EXEC      = test_03
OBJECTS   = test_03.o \
            sac2_asset_manager.o \
            sac2_logger.o \
            sac2_audio_manager.o \
            resource.o
INCLUDES  = -I$(SAC2_PATH)/include/types \
            -I$(SAC2_PATH)/include/assets \
            -I$(SAC2_PATH)/include/core \
            -I$(SAC2_PATH)/include/interfaces \
            -I$(SAC2_PATH)/include/utils

CXX       = g++
CXXFLAGS += -Wall -pedantic -std=c++11 -g -O2 -DSAC2_LOGGER_ENABLED
CXXFLAGS += $(INCLUDES)

MEMCHECK_FLAGS = --leak-check=full \
                 --track-origins=yes \
                 --suppressions=default.supp
#                 --gen-suppressions=yes \

#CXXFLAGS += -DUSE_SFML_INSTEAD

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

test_03.o: test_03.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

sac2_asset_manager.o: $(SAC2_PATH)/src/sac2_asset_manager.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

sac2_audio_manager.o: $(SAC2_PATH)/src/sac2_audio_manager.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

sac2_logger.o: $(SAC2_PATH)/src/sac2_logger.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

resource.o: resource.cpp resource.hpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

resource.cpp: resource.xml
	srg $<

$(SAC2_PATH)/src/sac2_asset_manager.cpp: $(SAC2_PATH)/include/assets/sac2_asset_manager.hpp

$(SAC2_PATH)/src/sac2_audio_manager.cpp: $(SAC2_PATH)/include/assets/sac2_audio_manager.hpp

memcheck:
	valgrind $(MEMCHECK_FLAGS) ./$(EXEC)

clean:
	rm -rf *.o *~ $(EXEC)

.PHONY: all clean
