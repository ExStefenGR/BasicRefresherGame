#include "DialogueSys.h"

DialogueSys::DialogueSys()
{
	m_lines[0];
	m_playerLoc.GetMapLoc();
}

DialogueSys::~DialogueSys()
{
}

void DialogueSys::SpeechDialogue()
{
	switch (m_playerLoc.GetMapLoc())
	{

	}
}

void DialogueSys::SpeechPause()
{
}
