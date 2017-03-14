# Lab 9 makefile
CXX := c++

TOP_DIR := $(shell pwd)
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

TESTLIBS = -lgtest -lpthread

CXX_FLAGS := -Wall -Wextra -pedantic --std=c++11 -g
TEST_FLAGS := -Wall -Wextra -pedantic --std=c++11 -g \
			  $(TESTLIBS)

tests: $(TEST_EXECUTABLES)

test: $(TEST_SINGLE_EXECUTABLE)
	@echo "Test case: " $(value TESTCASE)

run-test: $(TEST_SINGLE_EXECUTABLE)
	@echo "Test case: " $(value TESTCASE)
	cd ./tests/
	$(TEST_SINGLE_EXECUTABLE)
	cd ../

$(TEST_SINGLE_EXECUTABLE): $(TEST_SINGLE_FILE)
	$(CXX) -o $@ $^ $(TEST_FLAGS)

tests/%.out: tests/%.cpp
	$(CXX) -o $@ $^ $(TEST_FLAGS)

main-stack: main-stack.cpp
	g++ main-stack.cpp -o bin/main-stack $(CXX_FLAGS)
