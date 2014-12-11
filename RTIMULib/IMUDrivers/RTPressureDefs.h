////////////////////////////////////////////////////////////////////////////
//
//  This file is part of RTIMULib
//
//  Copyright (c) 2014, richards-tech
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
//  Software, and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
//  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
//  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef _RTPRESSUREDEFS_H
#define	_RTPRESSUREDEFS_H

//  Pressure sensor type codes

#define RTPRESSURE_TYPE_AUTODISCOVER        0                   // audodiscover the pressure sensor
#define RTPRESSURE_TYPE_NULL                1                   // if no physical hardware
#define RTPRESSURE_TYPE_BMP180              2                   // BMP180

//----------------------------------------------------------
//
//  BMP180

//  BMP180 I2C Slave Addresse

#define BMP180_ADDRESS              0x77
#define BMP180_REG_ID               0xd0
#define BMP180_ID                   0x55

//	Register map

#define BMP180_REG_AC1              0xaa
#define BMP180_REG_SCO              0xf4
#define BMP180_REG_RESULT           0xf6
#define BMP180_REG_XLSB             0xf8

#endif // _RTPRESSUREDEFS_H
