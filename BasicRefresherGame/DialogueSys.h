#pragma once
#include "MapSys.h"

class DialogueSys
{
public:
	DialogueSys();
	~DialogueSys();
	void SpeechDialogue();
private:
	void SpeechPause();
	MapSys m_playerLoc;
};

