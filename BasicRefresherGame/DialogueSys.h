#pragma once
#include "MapSys.h"

class MapSys;
class DialogueSys
{
public:
	DialogueSys();
	~DialogueSys();
	void SpeechDialogue();
private:
	void SpeechPause();
	MapSys* m_locations;
};