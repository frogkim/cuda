################################################################################
PROJECT_NAME = test
PRE_DEFINED_MACRO := LINUX
CC := gcc

# internal flags
CCFLAGS     := -Wall
LDFLAGS     := -llibcuda
INCLUDES  := -I../../include
LIBRARIES := -L/home/frogkim/git/cuda/cuda/bin_linux

# Build Type
BUILD_TYPE :=

# Debug build flags
ifeq ($(dbg),1)
      CCFLAGS += -g -G
      BUILD_TYPE := debug
else
      BUILD_TYPE := release
endif

ALL_CCFLAGS :=
ALL_LDFLAGS :=
ALL_CCFLAGS += $(CCFLAGS)
ALL_LDFLAGS += $(LDFLAGS)

ALL_LDFLAGS += $(ALL_CCFLAGS)

# Common includes and paths for CUDA

HFILES   := $(wildcard *.h)
CUFILES  := $(wildcard *.cu)
CFILES   := $(wildcard *.c)
CPPFILES := $(wildcard *.cpp)

SRCS := ${CFILES} ${CPPFILES}
OBJS := ${CFILES:.c=.o} ${CPPFILES:.cpp=.o}

ALL_CCFLAGS += -c --std=c++20
ALL_LDFLAGS += 
################################################################################
# example
# all: library.cpp main.cpp
#
# $@ evaluates to all
# $< evaluates to library.cpp
# $^ evaluates to library.cpp main.cpp
################################################################################

# Target rules
all: build

build: $(PROJECT_NAME) filemove

check.deps:

$(PROJECT_NAME): $(OBJS)
	$(EXEC) $(CC) $^ -o $@ $(LIBRARIES) $(ALL_LDFLAGS) 

%.o: %.c
	$(EXEC) $(CC) $^ -o $@ $(INCLUDES) $(ALL_CCFLAGS) 

%.o: %.cpp
	$(EXEC) $(CC) $^ -o $@ $(INCLUDES) $(ALL_CCFLAGS) 

filemove:
#	$(EXEC) mkdir -p ../../obj_linux
#	$(EXEC) mv ./*.o ../../obj_linux/
#	$(EXEC) mkdir -p ../../bin_linux
#	$(EXEC) mv $(PROJECT_NAME) ../../bin_linux/$(PROJECT_NAME)

clean:
	rm -f $(PROJECT_NAME)
	rm -f $(OBJS)

#	rm -f $(PROJECT_NAME:%=../../bin_linux/%)
#	rm -f $(OBJS:%=../../obj_linux/%)
