/*=========================================================================
    OpenGC - The Open Source Glass Cockpit Project

    Copyright (c) 2001-2004 Damion Shelton
    Copyright (c) 2005-2010 Hugo Vincent <hugo.vincent@gmail.com>
    Copyright (c) 2008-2010 Yuriy Kinakh <ykinakh@gmail.com>
    Copyright (c) 2008-2010 Bohdan Mushkevych <mushkevych@gmail.com>
    All rights reserved.

    This branch of OpenGC is developed within "Albatross UAV Project"
    http://gitorious.org/albatross/

    This software is distributed WITHOUT ANY WARRANTY; without even
    the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See Copyright.txt or http://opengc.sourceforge.net/licensing.html for more information.
=========================================================================*/

/**
 * Sound manager class - used for playing warning sounds. 
 * May add text-to-speech annunciations in the future.
 */

#ifndef SoundManager_h
#define SoundManager_h

namespace OpenGC {

typedef enum {
	SND_WARNING,
	SND_ALERT
} sound_t;
	
class SoundManager
{
	public:

		SoundManager();
		~SoundManager();

		void PlaySound(sound_t snd);
};


} // end namespace OpenGC

#endif

