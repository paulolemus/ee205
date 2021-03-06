CXX := c++

# Find all the names of CPP files in the src directory.
CPP_FILES := $(wildcard src/*.cpp)
H_FILES := $(wildcard src/*.h)

TEST_FILES := $(wildcard tests/*.cpp)
TEST_EXECUTABLES := $(TEST_FILES:.cpp=.out)

ifdef TESTCASE
TEST_SINGLE_FILE := $(addprefix tests/, $(addsuffix .cpp, $(TESTCASE)))
TEST_SINGLE_EXECUTABLE := $(addprefix tests/, $(addsuffix .out, $(TESTCASE)))
else
TESTCASE := $(shell echo $$TESTCASE)
TEST_SINGLE_FILE := $(addprefix tests/, $(addsuffix .cpp, $(TESTCASE)))
TEST_SINGLE_EXECUTABLE := $(addprefix tests/, $(addsuffix .out, $(TESTCASE)))
endif

TOPDIR := $(shell pwd)
TESTLIBS = -lgtest -lpthread

# Flags for the C++ compilation step.
CXX_FLAGS := -Wall -Wextra -pedantic --std=c++11 -g

TEST_FLAGS := -Wall -Wextra -pedantic --std=c++11 -g \
			-I$(TOPDIR) $(TESTLIBS)

# The default rule to be build when just `make` is run.
all: ackermann

ackermann: ackermann.cpp
	g++ ackermann.cpp -o ackermann $(CXX_FLAGS)


tests: $(TEST_EXECUTABLES)

test: $(TEST_SINGLE_EXECUTABLE)
	@echo "Test case: " $(value TESTCASE)

run-test: $(TEST_SINGLE_EXECUTABLE)
	@echo "Test case: " $(value TESTCASE)
	$(TEST_SINGLE_EXECUTABLE)

$(TEST_SINGLE_EXECUTABLE): $(TEST_SINGLE_FILE)
	$(CXX) -o $@ $^ $(TEST_FLAGS)

tests/%.out: tests/%.cpp
	$(CXX) -o $@ $^ $(TEST_FLAGS)


# CLEAN TARGETS

.PHONY: clean clean-tests

clean: clean-tests clean-build

clean-build:
	-rm ackermann

clean-tests:
	-rm -rf tests/*.out


