#pragma once

enum SOUND_STATES {
	E_SOUNDPLAY,
	E_SOUNDPAUSE,
	E_SOUNDSTOP,
	E_SOUNDMOVE
};

class CSoundManager :
	public CSingleton<CSoundManager>
{
private:
	map<string, string> m_sounds;
public:
	CSoundManager();
	virtual ~CSoundManager();

	void AddSound(const string &soundName, const string &soundPath);
	void SoundControl(const string &soundName, const SOUND_STATES& stateSet,const string& subCommand = "");
};

#define SOUNDMANAGER CSoundManager::GetInstance()