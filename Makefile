BUILD_DIR := build
INCLUDES = -Iinclude

BINS = pineapple
OBJS = main.o linear.o binary.o #(list all output objects needed)
OBJ_LIST = $(addprefix $(BUILD_DIR)/, $(OBJS)) #(create a list of objects prefixed with output location, i.e. build/main.o)
LIST = $(addprefix $(BUILD_DIR)/, $(BINS)) #(create a list of all binaries prefixed with output location, i.e. build/pineapple)

.PHONY: all
all: setup $(LIST) #(moving this to after object files rule causes errors)

$(LIST): $(OBJ_LIST) #(rules to create list of binaries)
	$(CXX) -o $@ $^

$(BUILD_DIR)/%.o: src/%.cpp
	$(CXX) -c -o $@ $< $(INCLUDES)

.PHONY: setup
setup:
	mkdir -p $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)