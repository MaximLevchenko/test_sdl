cmake_minimum_required(VERSION 3.21)
project(test_sdl)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wconversion -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

set(SDL2_INCLUDE_DIR C:/SDL/SDL_FILES/include)
set(SDL2_LIB_DIR C:/SDL/SDL_FILES/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

set(SDL2_IMAGE_INCLUDE_DIR C:/SDL/SDL_IMAGE/include)
set(SDL2_IMAGE_LIB_DIR C:/SDL/SDL_IMAGE/lib/x64)

include_directories(${SDL2_IMAGE_INCLUDE_DIR})
link_directories(${SDL2_IMAGE_LIB_DIR})


add_executable(test_sdl src/main.cpp old_prog/RenderWindow.h old_prog/RenderWindow.cpp old_prog/Entity.h old_prog/Entity.cpp includes/Math.h includes/Math.cpp includes/Utils.h src/ErrorHandler.h includes/Utils.cpp src/ErrorHandler.cpp src/Game.cpp src/Game.h src/TextureManager.h src/TextureManager.cpp old_prog/gameobj_handling/GameObject.cpp old_prog/gameobj_handling/GameObject.h src/Map.cpp src/Map.h src/ECS/ECS.h src/ECS/Components.h src/ECS/SpriteComponent.h src/ECS/TransformComponent.h src/Vector2D.cpp src/Vector2D.h src/ECS/KeyboardController.h src/ECS/ColliderComponent.h src/Collisiion.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
