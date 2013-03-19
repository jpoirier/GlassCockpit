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

#include <math.h>
#include "Debug.h"
#include "APM2DataSource.h"

namespace OpenGC {

APM2DataSource::APM2DataSource() {
    this->InitializeData();

    // Set initial state
    m_Airframe->SetStatus_Active(false);
    m_Airframe->SetDirector_Active(false);
    m_Airframe->SetGot_Data(false);
    m_Airframe->SetStatus_Text_NoData("WAITING FOR CONNECTION");
    m_State = STATE_WAITING;

    m_Airframe->SetStatus_Text1("YAW");
    m_Airframe->SetStatus_Text2("ALT");
    m_Airframe->SetStatus_Text3("BNK");
    m_Airframe->SetStatus_Text4("VEL");
    m_Airframe->SetStatus_Colour1(1);
    m_Airframe->SetStatus_Colour2(1);
    m_Airframe->SetStatus_Colour3(1);
    m_Airframe->SetStatus_Colour4(1);
}

APM2DataSource::~APM2DataSource() {
    // Deconstructor
}

bool APM2DataSource::GetData() {
#if 0
    // Length of the message received from Flightgear
    int receivedLength = 0;

    // Actual length after flushing accumulated messages
    int finalReceivedLength = 0;

    // The code in the "do" block flushes the buffer so that only
    // the most recent message remains. This eliminates the build-up
    // of old messages in the network buffer (which we don't directly
    // control)
    do {
        receivedLength = m_Socket.recv(m_TempMsg, m_BufferLength, 0);

        if (receivedLength >= 0) {
            for (int i = 0; i < m_BufferLength; i++) {
                m_Buffer[i] = m_TempMsg[i];
            }
            finalReceivedLength = receivedLength;
        }
    } while(receivedLength >=0);

    // At this point, m_Buffer[] contains the most recent message
    if (finalReceivedLength > 0) {
        assert(finalReceivedLength == sizeof(FGData)); // possible superfluous
        m_FDM = (FGData*) m_Buffer;
        return true;
    } else {
        return false;
    }
#endif
    return false;
}

bool APM2DataSource::Open() {
	return false;
}

bool APM2DataSource::OnIdle() {
    // ++++++ Generate Data +++++++++++++++++++++++++++++++++++++++++++++++++++
    static double t = 0.0;
    t += 1.0 / 24.0;

    switch (m_State) {
    case STATE_WAITING:
        if (t >= 1.0) {
            m_Airframe->SetStatus_Text_NoData("CONNECTED (TEST)");
            m_State = STATE_CONNECTING;
            LogPrintf("APM2DataSource: Connected (test mode).\n");
            return true;
        } else {
            return false;
        }
    case STATE_CONNECTING:
        if (t >= 1.5) {
            m_Airframe->SetBarometric_Pressure(1010.0); // hPa ambient
            m_Airframe->SetGPS_Mode(3);
            m_Airframe->SetGPS_Sats(5);
            m_Airframe->SetGot_Data(true);
            m_Airframe->SetStatus_Active(true);
            m_State = STATE_FD;
            LogPrintf("APM2DataSource: Activated status display.\n");
        }
        return false;
    case STATE_FD:
        if (t >= 5.0) {
            m_Airframe->SetStatus_Colour1(2);
            m_Airframe->SetStatus_Colour2(2);
            m_Airframe->SetStatus_Colour3(2);
            m_Airframe->SetStatus_Colour4(2);
            m_Airframe->SetDirector_Active(true);
            m_State = STATE_RUNNING;
            LogPrintf("APM2DataSource: Flight Director on.\n");
        }
        break;
    case STATE_RUNNING:
        break;
    }

    // Abort if the connection isn't valid
    if (!m_ValidConnection) {
        return false;
    }

    // Input data from the LAN socket
    if (!GetData()) {
        return false;
    }

// XXX: from the test file
    double roll;
    double pitch ;
    double heading;
    //double trueHeading = fmodf((t * 15) + 2 * sin(t), 360.0);
    //double heading = 60.0 * sin(t/4);
    double airspeed;
    double vertSpeed; // should be calculated
    //double alt = 200 + (30 * sin(t/6));
    double alt;
    // double roll = 0.3 * sin(t) * 180 / M_PI;
    // double pitch = 0.15 * cos(t) * 180 / M_PI;
    // double heading = fmodf(t * 15.0, 360.0);
    // //double trueHeading = fmodf((t * 15) + 2 * sin(t), 360.0);
    // //double heading = 60.0 * sin(t/4);
    // if (heading < 0.0) {
    //     heading += 360.0;
    // }
    // double airspeed = t * 4;
    // double vertSpeed = 200 * sin(t/2 + 0.5); // should be calculated
    // //double alt = 200 + (30 * sin(t/6));
    // double alt = t * 15;

    // ++++++ Update Data +++++++++++++++++++++++++++++++++++++++++++++++++++++
    // -------Orientation--------------
    m_Airframe->SetRoll(roll);
    m_Airframe->SetPitch(pitch);
    m_Airframe->SetTrue_Heading(heading);
    m_Airframe->SetTrack_Heading(360 - heading);

    // -------Speeds-------------------
    m_Airframe->SetAirspeed_KT(airspeed);
    m_Airframe->SetVertical_Speed_FPM(vertSpeed);
    m_Airframe->SetGround_Speed_MS(0.0); // Knots

    // -------Accelerations------------
    m_Airframe->SetAccel_Body_Fwd(0.0);
    m_Airframe->SetAccel_Body_Right(0.0);
    m_Airframe->SetAccel_Body_Down(1.0);

    // -------Altitude-----------------
    m_Airframe->SetAltitude_MSL_Feet(alt);
    m_Airframe->SetAltitude_AGL_Feet(0.0);
    m_Airframe->SetBarometric_Pressure(1010.0);

#if 0
// TODO: figure these out...?
    // ----------------------------------
    m_Airframe->SetMag_Variation(m_FDM->magvar * RAD_TO_DEG);
    double magHeading = m_FDM->heading - m_Airframe->GetMag_Variation();
    if (magHeading < 0.0) {
        magHeading += 360.0;
    }
    m_Airframe->SetMag_Heading(magHeading);
    m_Airframe->SetPressure_Alt_Feet(m_FDM->altitude);
    //AGL_Alt_Feet = m_FDM->altitude_agl;

    m_Airframe->SetIAS(m_FDM->v_kcas); // calibrated airspeed
    //EAS = m_FDM->v_eas; // equivalent airspeed

    // FIXME this is old commented out code:
    //TAS = EAS * (1.0 + (Barometric_Alt_Feet * 0.000017));
    //= TAS - (cos((Mag_Heading - wind_direction)/57.29456) * wind_velocity);

    m_Airframe->SetVertical_Speed_FPM(m_FDM->vvi * 60.0); // FlightGear units are feet per second
    m_Airframe->SetGround_Speed_K(m_FDM->groundspeed * 3600 / METERS_TO_FEET * METER_PER_NM);
#endif
#if 0
    // -------Position-----------------
    m_Airframe->SetLatitude(32.444 + 0.005 * t); // }
    m_Airframe->SetLongitude(-97.470);            // } NRH, TX
    m_Airframe->SetLatitude(-43.479 + 0.005 * t); // }
    m_Airframe->SetLongitude(172.523);            // } Christchurch
    m_Airframe->SetLatitude(37.621134 + 0.005 * t); // }
    m_Airframe->SetLongitude(-122.374530);          // } San Francisco
#endif
    // -------Engine-------------------
    m_Airframe->SetEngine_RPM(4500.0 + 4500.0 * sin(t/2.2));
    m_Airframe->SetEngine_CHT(125.0 + 125.0 * sin(t/2.5));
    m_Airframe->SetEngine_EGT(500.0 + 500 * sin (t/3));
    m_Airframe->SetEngine_Mixture(8.0 + 8.0 * sin(t/2));
    m_Airframe->SetVoltage_Alternator(0.0);
    m_Airframe->SetVoltage_Battery(0.0);

    // -------Extra Stuff--------------
    m_Airframe->SetInternal_Temp(30 + 2*sin(t / 100.0));
    m_Airframe->SetExternal_Temp(10 - 2*sin(t / 100.0));
    m_Airframe->SetWind_Speed(10.0);
    m_Airframe->SetWind_Direction(360.0 - heading);

    // -------Flight Director---------- (aka autopilot)
    m_Airframe->SetDirector_Pitch(0.0);
    m_Airframe->SetDirector_Roll(0.0);
    m_Airframe->SetDirector_Heading(10.0);
    m_Airframe->SetDirector_Altitude(400.0);
    m_Airframe->SetDirector_Airspeed(80.5);

    return true;
}

} // end namespace OpenGC

