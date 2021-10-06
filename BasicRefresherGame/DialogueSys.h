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
	int m_lines[1];
	MapSys m_playerLoc;
};

