#OBJS specifies which files to compile as part of the project
OBJS = main.cpp \
	Application.cpp \
	Appsettings.cpp \
	Ball.cpp \
	Block.cpp \
	FileManager.cpp \
	Game.cpp \
	Level.cpp \
	Menu.cpp \
	Model.cpp \
	Object.cpp \
	Panel.cpp \
	Player.cpp \
	Sound.cpp \
	State.cpp \
	Texture.cpp \
	UI.cpp \
	UI_Label.cpp \
	UI_Button.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -g

#LINKER_FLAGS specifies the libraries we're linking against

ifeq ($(OS),Windows_NT)
	LINKER_FLAGS = -lMingw32 -lSDLmain -lSDL -lSDL_mixer -lOpenGL32 -lglu32
else
	LINKER_FLAGS = -lMingw32 -lSDL -lSDL_mixer -lOpenGL32 -lGLU
endif

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = bb

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

