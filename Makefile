BUILD_DIR = build/
INCLUDES = -Iinclude
DEPS = linear_search.h

OBJS = main.o linear_search.o
OBJ_LIST = $(addprefix $(BUILD), $(OBJS))

$(BUILD)%.o: src/%.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

$(BUILD)pineapple: $(OBJ_LIST)
	$(CXX) -o $@ $^ $(INCLUDES)

all: setup

.PHONY: setup
setup:
	mkdir -p $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)