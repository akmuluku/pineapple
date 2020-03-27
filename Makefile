BUILD_DIR = build/
INCLUDES = -Iinclude

BINS = pineapple
OBJS = main.o linear_search.o #(list all output objects needed)
OBJ_LIST = $(addprefix $(BUILD_DIR), $(OBJS)) #(create a list of objects prefixed with output location, i.e. build/main.o)
LIST = $(addprefix $(BUILD_DIR), $(BINS)) #(create a list of all binaries prefixed with output location, i.e. build/pineapple)

$(BUILD_DIR)%.o: src/%.cpp
	$(CXX) -c -o $@ $< $(INCLUDES)

$(LIST): $(OBJ_LIST) #(rules to create list of binaries)
	$(CXX) -o $@ $^

all: setup $(LIST)

.PHONY: setup
setup:
	mkdir -p $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)