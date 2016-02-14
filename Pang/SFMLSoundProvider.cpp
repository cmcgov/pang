#include "stdafx.h"
#include "SFMLSoundProvider.h"

SFMLSoundProvider::SFMLSoundProvider()
{
	_sound.setVolume(100.0f);
}

void SFMLSoundProvider::PlaySound(std::string filename)
{
	if (_soundBuffer.getDuration() == sf::Time::Zero)
	{
		_soundBuffer.loadFromFile(filename);
	}

	if (_sound.getStatus() == sf::Sound::Playing)
	{
		_sound.stop();
	}

	_sound.setBuffer(_soundBuffer);
	_sound.play();
}

void SFMLSoundProvider::PlaySong(std::string filename, bool looping)
{
	_music.openFromFile(filename);
	_music.setLoop(looping);
	_music.play();
}

void SFMLSoundProvider::StopAllSounds()
{
	if (_sound.getStatus() == sf::Sound::Playing)
	{
		_sound.stop();
	}
	if (_music.getStatus() == sf::Sound::Playing)
	{
		_music.stop();
	}
}

bool SFMLSoundProvider::IsSoundPlaying()
{
	return _sound.getStatus() == sf::Sound::Playing;
}

bool SFMLSoundProvider::IsSongPlaying()
{
	return _music.getStatus() == sf::Sound::Playing;
}
