# Lab 10 makefile
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

all: bank company

bank: bank.cpp
	g++ bank.cpp -o bin/bank $(CXX_FLAGS)

company: company.cpp
	g++ company.cpp -o bin/company $(CXX_FLAGS)

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

clean-tests:
	rm tests/*.out

clean: clean-tests
	rm bin/*
