#include "DXUT.h"
#include "cSoundManager.h"


CSoundManager::CSoundManager()
{
}


CSoundManager::~CSoundManager()
{
	m_sounds.clear();
}

void CSoundManager::AddSound(const string & soundName, const string & soundPath)
{
	auto find = m_sounds.find(soundName);

	if (find != m_sounds.end()) {
		return;
	}

	m_sounds.insert(make_pair(soundName, soundPath));

	return;
}

void CSoundManager::SoundControl(const string & soundName, const SOUND_STATES & stateSet, const string & subCommand)
{
	auto find = m_sounds.find(soundName);
	if (find == m_sounds.end()) return;

	switch (stateSet) {
		case E_SOUNDPLAY:	mciSendStringA(("play " + find->second + subCommand).c_str(), 0, 0, 0);	 break;
		case E_SOUNDPAUSE:	mciSendStringA(("pause " + find->second + subCommand).c_str(), 0, 0, 0); break;
		case E_SOUNDSTOP:	mciSendStringA(("stop " + find->second + subCommand).c_str(), 0, 0, 0);	 break;
		case E_SOUNDMOVE:	mciSendStringA(("seek " + find->second + " to " + subCommand).c_str(), 0, 0, 0); break;

	default: return;
	}
}