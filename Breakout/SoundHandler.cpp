#include "SoundHandler.h"

SoundHandler::SoundHandler() {
	if (!music.openFromFile("audio/music.mp3")) {
		std::cout << "Failed to load music" << std::endl;
	}
	music.play();
	music.setLoop(true);
	loadSoundData("audio/death.mp3", "death");
	loadSoundData("audio/game-over.mp3", "gameover");
	loadSoundData("audio/level-win.mp3", "levelwin");
	loadSoundData("audio/marimba-hit-1.wav", "marimbaHit1");
	loadSoundData("audio/marimba-hit-2.wav", "marimbaHit2");
	loadSoundData("audio/marimba-hit-3.wav", "marimbaHit3");
	loadSoundData("audio/marimba-hit-4.wav", "marimbaHit4");
	loadSoundData("audio/powerup.mp3", "powerup");
}

SoundHandler::~SoundHandler() {

}

void SoundHandler::playSound(std::string soundName) {
	if (soundMap.find(soundName) != soundMap.end()) {
		soundMap.find(soundName)->second.play();
	}
}

void SoundHandler::loadSoundData(std::string filePath, std::string soundName) {
	sf::SoundBuffer soundBuffer;
	if (!soundBuffer.loadFromFile(filePath)) {
		std::cout << "Failed to load sound: " << filePath << std::endl;
	}
	else {
		soundDataMap.emplace(soundName, soundBuffer);
		sf::Sound sound;
		sound.setBuffer(soundDataMap.find(soundName)->second);
		soundMap.emplace(soundName, sound);
	}
}