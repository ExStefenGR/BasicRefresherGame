#pragma once
#include "MapSys.h"

class DialogueSys
{
public:
	DialogueSys();
	~DialogueSys();
private:
	void SpeechDialogue();
	void SpeechPause();
	int m_lines[5];
	MapSys m_playerLoc;
};

