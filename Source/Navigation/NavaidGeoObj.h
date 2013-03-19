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

#ifndef NavaidGeoObj_h
#define NavaidGeoObj_h

#include "GeographicObject.h"

namespace OpenGC
{

class NavaidGeoObj : public GeographicObject
{
public:

    NavaidGeoObj();
    virtual ~NavaidGeoObj();

  /** Accessors for frequency */
  void SetFrequency(float freq) {m_Frequency = freq;}
  float GetFrequency() {return m_Frequency;}

  /** Accessors for navaid type */
  void SetNDBType() {m_NavaidType = 0;}
  void SetVORType() {m_NavaidType = 1;}
  void SetDMEType() {m_NavaidType = 2;}

  unsigned int GetType() {return m_NavaidType;};

protected:

  /** Frequency of the navaid */
  float m_Frequency;

  /** Type of navaid */
  unsigned int m_NavaidType;

};

} // end namespace OpenGC

#endif
