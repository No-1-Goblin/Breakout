#pragma once

#include "SFML/Audio.hpp"
#include <iostream>
#include <map>

class SoundHandler
{
public:
	SoundHandler();
	~SoundHandler();

	void playSound(std::string soundName);
protected:
	void loadSoundData(std::string filePath, std::string soundName);

	sf::Music music;
	std::map<std::string, sf::SoundBuffer> soundDataMap;
	std::map<std::string, sf::Sound> soundMap;
};

