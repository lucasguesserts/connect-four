
.PHONY: build test

BUILD_DIR = build

build:
	cmake -S . -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)

run:
	cmake -S . -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)
	cd $(BUILD_DIR) && ./connect_four

test:
	cmake -S . -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)
	cd $(BUILD_DIR) && ctest --output-on-failure

clean:
	rm -rf $(BUILD_DIR)
