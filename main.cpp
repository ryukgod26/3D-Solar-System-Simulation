#include<iostream>
#include "Game.h"
#include "Settings.h"
#include <limits>

namespace settings {
	std::string texturePath = "/ResFiles/Textures/";
	std::string meshesPath = "/ResFiles/Meshes/";
	std::string shadersPath = "/ResFiles/Shaders/";
}

int main(){

	try{
		using namespace settings;
		Game game(windowWidth,windowHeight,viewportX,viewportY,viewportWidth,viewportHeight,windowTitle);
		while(!game.ShouldClose()){
			game.Tick();
		}
		return 0;
	}
	catch(const std::exception& ex){
		std::cerr << "Startup error: " << ex.what() << std::endl;
		std::cerr << "Press Enter to exit..." << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();
		return 1;
	}
}
