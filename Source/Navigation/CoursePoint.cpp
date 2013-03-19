/*=========================================================================

  Copyright (c) 2005-2010 Hugo Vincent <hugo.vincent@gmail.com>
  All rights reserved.

  This project is distributed under the terms of the GNU General Public License
  Version 3 <http://www.gnu.org/licenses/gpl.html>.

      This program is free software: you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
      the Free Software Foundation, specifically version 3 of the License.

      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.

      You should have received a copy of the GNU General Public License
      along with this program.  If not, see <http://www.gnu.org/licenses/>.

=========================================================================*/

#include <cmath>
#include "CoursePoint.h"

namespace OpenGC {

using namespace std;

CoursePoint::CoursePoint() {
}

CoursePoint::CoursePoint(double lat, double lon) {
    m_Lat = lat;
    m_Lon = lon;
}

CoursePoint::~CoursePoint() {
}

void CoursePoint::GetCoords(double &lat, double &lon) {
    lat = m_Lat;
    lon = m_Lon;
}

} // end namespace OpenGC

