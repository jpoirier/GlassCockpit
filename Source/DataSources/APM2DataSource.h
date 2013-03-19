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

#ifndef TestDataSource_h
#define TestDataSource_h

#include "DataSource.h"

namespace OpenGC {

typedef enum {STATE_WAITING, STATE_CONNECTING, STATE_FD, STATE_RUNNING} TestState;

class APM2DataSource : public DataSource {
    public:
        APM2DataSource();
        ~APM2DataSource();

        // Open the network connection
        bool Open();

        // The money function
        bool OnIdle();

    protected:
        // Get data from FlightGear
        bool GetData();

        // Flight model data received from FlightGear
//        FGData *m_FDM;

        // The socket
//      netSocket m_Socket;

        // The host and port we're receiving on
        // string m_Host;
        int m_ReceivePort;

        // Are we connected to Flightgear?
        bool m_ValidConnection;

        // The message received from Flightgear
        char *m_Buffer;

        // A temporary buffer used in the receive process
        char *m_TempMsg;

        // Maximum length of the buffer
        int m_BufferLength;

    private:
        TestState m_State;
};

} // end namespace OpenGC

#endif
