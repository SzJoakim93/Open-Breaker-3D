cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_COMPILER "g++")

# set the project name
project(BallBreaker3D)

find_package(SDL REQUIRED)
find_package(SDL_MIXER REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${PROJECT_SOURCE_DIR} ${SDL_INCLUDE_DIRS} ${SDL_MIXER_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})

# add the executable
add_executable(BallBreaker3D
	main.cpp
	Application.cpp
	Object.cpp
	Sound.cpp
	Game.cpp
	Menu.cpp
	Ball.cpp
	Player.cpp
	Block.cpp
	Level.cpp
	resource.rc
	)

target_link_libraries(BallBreaker3D ${SDL_LIBRARY} ${SDL_MIXER_LIBRARIES} ${OPENGL_LIBRARIES})