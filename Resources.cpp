#include "Resources.h"

using namespace brk;

	Resources::Resources() : 
		ASSETS_PATH(boost::filesystem::current_path().string() + "\\Assets\\"),
		TEXTURES_PATH(ASSETS_PATH + "Textures\\"),
		SOUND_PATH(ASSETS_PATH + "Sounds\\"),
		MUSIC_PATH(ASSETS_PATH + "Music\\")
	{
	}

	sf::Texture & Resources::getTexture(std::string name) const
	{
		
		if (m_textures.find(name) != m_textures.end())
		{
			return m_textures[name];
		}
		else {
			sf::Texture texture;
			if (!texture.loadFromFile(TEXTURES_PATH + name + ".png"))
			{
				throw load_exception("Couldn't load Texture: " + name);
				return texture;
			}
			else
			{
				m_textures[name] = texture;
				return m_textures[name];
			}
		}

	}

	/*sf::SoundBuffer & Resources::getSoundbuffer(std::string name) const
	{
		// TODO: hier Rückgabeanweisung eingeben
	}

	sf::Music & Resources::getMusic(std::string name) const
	{
		// TODO: hier Rückgabeanweisung eingeben
	}*/
