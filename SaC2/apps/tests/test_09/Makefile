##
##  test_03
##

include $(SAC2_MAKE_PATH)/sfml.mk

EXEC      = test_09
OBJECTS   = test_09.o sac2_bounding_box.o sac2_bounding_circle.o sac2_vector2d.o sac2_math.o
INCLUDES  = -I$(SAC2_PATH)/include/types \
            -I$(SAC2_PATH)/include/assets \
            -I$(SAC2_PATH)/include/core \
            -I$(SAC2_PATH)/include/interfaces \
            -I$(SAC2_PATH)/include/utils

CXX       = g++
CXXFLAGS += -Wall -pedantic -std=c++11 -g -O2
CXXFLAGS += $(INCLUDES)

MEMCHECK_FLAGS = --leak-check=full \
                 --track-origins=yes
#                 --suppressions=default.supp
#                 --gen-suppressions=yes \

#CXXFLAGS += -DUSE_SFML_INSTEAD

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

test_09.o: test_09.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

sac2_bounding_box.o: $(SAC2_PATH)/src/sac2_bounding_box.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

sac2_bounding_circle.o: $(SAC2_PATH)/src/sac2_bounding_circle.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

sac2_vector2d.o: $(SAC2_PATH)/src/sac2_vector2d.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

sac2_math.o: $(SAC2_PATH)/src/sac2_math.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

memcheck:
	valgrind $(MEMCHECK_FLAGS) ./$(EXEC)

clean:
	rm -rf *.o *~ $(EXEC)

.PHONY: all clean
