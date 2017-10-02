cmake_minimum_required(VERSION 3.8)
project(training)

set(CMAKE_C_STANDARD 99)
include_directories(includes)

set(SOURCE_FILES main.c includes/entities/entity.h includes/entities/space_marine.h includes/items/inventory.h includes/items/weapon.h includes/items/armor.h includes/types.h includes/entities/zerg.h src/entities/entity.c includes/utils/my_put_char.h includes/utils/my_put_string.h includes/utils/my_put_number.h src/utils/my_put_char.c src/utils/my_put_string.c src/utils/my_put_number.c src/utils/string_length.c includes/utils/string_length.h src/items/inventory.c src/items/armor.c src/items/weapon.c includes/managers/game_manager.h includes/managers/space_marine_manager.h includes/managers/zerg_manager.h includes/managers/display_manager.h src/utils/sleep.c includes/utils/sleep.h src/entities/space_marine.c includes/game_data.h src/managers/space_marine_manager.c src/managers/game_manager.c src/entities/zerg.c src/managers/display_manager.c src/managers/zerg_manager.c)
add_executable(training ${SOURCE_FILES})