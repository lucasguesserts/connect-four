
.PHONY: build test


BUILD_DIR = build
CMAKE_BUILD = cmake -S . -B $(BUILD_DIR) && cmake --build $(BUILD_DIR)

build:
	$(CMAKE_BUILD)

play:
	$(CMAKE_BUILD)
	cd $(BUILD_DIR) && ./play_game

example:
	$(CMAKE_BUILD)
	cd $(BUILD_DIR) && ./example

test:
	$(CMAKE_BUILD)
	cd $(BUILD_DIR) && ctest --output-on-failure

clean:
	rm -rf $(BUILD_DIR)
