#pragma once

#include <string>


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <boost/filesystem.hpp>

#include <iostream>

namespace brk {
	class Resources
	{
	public:
		// Constructor
		Resources();

		// No Copies
		Resources(const Resources &r) = delete;
		Resources& operator=(const Resources &r) = delete;

		// Graphics
		sf::Texture& getTexture(std::string name) const;
		

		// Audio
		/*sf::SoundBuffer& getSoundbuffer(std::string name) const;
		sf::Music& getMusic(std::string name) const;
		*/
		// Game Elements
		// ...
	private:
		mutable std::map<std::string, sf::Texture>		m_textures;
		mutable std::map<std::string, sf::SoundBuffer>	m_soundBuffers;
		mutable std::map<std::string, sf::Music>		m_musics;

		const std::string					ASSETS_PATH;
		const std::string					TEXTURES_PATH;
		const std::string					SOUND_PATH;
		const std::string					MUSIC_PATH;
	};

	class load_exception : public std::exception
	{
	public:
		explicit load_exception(std::string message) noexcept {
			m_message = message;
		}

		load_exception(const load_exception& r) noexcept
		{
			m_message = r.m_message;
		}

		load_exception& operator= (const load_exception& r) noexcept
		{
			m_message = r.m_message;
			return (*this);
		}

		virtual ~load_exception() {};

		const char* what() const noexcept override
		{
			return m_message.c_str();
		};

	private:
		std::string m_message;
	};
}