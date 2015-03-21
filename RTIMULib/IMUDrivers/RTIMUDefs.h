////////////////////////////////////////////////////////////////////////////
//
//  This file is part of RTIMULib
//
//  Copyright (c) 2014-2015, richards-tech
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

//  The MPU-9250 and SPI driver code is based on code generously supplied by
//  staslock@gmail.com (www.clickdrive.io)


#ifndef _RTIMUDEFS_H
#define	_RTIMUDEFS_H

//  IMU type codes

#define RTIMU_TYPE_AUTODISCOVER             0                   // audodiscover the IMU
#define RTIMU_TYPE_NULL                     1                   // if no physical hardware
#define RTIMU_TYPE_MPU9150                  2                   // InvenSense MPU9150
#define RTIMU_TYPE_GD20HM303D               3                   // STM L3GD20H/LSM303D (Pololu Altimu)
#define RTIMU_TYPE_GD20M303DLHC             4                   // STM L3GD20/LSM303DHLC (old Adafruit IMU)
#define RTIMU_TYPE_LSM9DS0                  5                   // STM LSM9DS0 (eg Sparkfun IMU)
#define RTIMU_TYPE_MPU9250                  6                   // InvenSense MPU9250
#define RTIMU_TYPE_GD20HM303DLHC            7                   // STM L3GD20H/LSM303DHLC (new Adafruit IMU)

//----------------------------------------------------------
//
//  MPU-9150

//  MPU9150 I2C Slave Addresses

#define MPU9150_ADDRESS0            0x68
#define MPU9150_ADDRESS1            0x69
#define MPU9150_ID                  0x68

//  thes magnetometers are on aux bus

#define AK8975_ADDRESS              0x0c
#define HMC5883_ADDRESS             0x1e

//  Register map

#define MPU9150_YG_OFFS_TC          0x01
#define MPU9150_SMPRT_DIV           0x19
#define MPU9150_LPF_CONFIG          0x1a
#define MPU9150_GYRO_CONFIG         0x1b
#define MPU9150_ACCEL_CONFIG        0x1c
#define MPU9150_FIFO_EN             0x23
#define MPU9150_I2C_MST_CTRL        0x24
#define MPU9150_I2C_SLV0_ADDR       0x25
#define MPU9150_I2C_SLV0_REG        0x26
#define MPU9150_I2C_SLV0_CTRL       0x27
#define MPU9150_I2C_SLV1_ADDR       0x28
#define MPU9150_I2C_SLV1_REG        0x29
#define MPU9150_I2C_SLV1_CTRL       0x2a
#define MPU9150_I2C_SLV4_CTRL       0x34
#define MPU9150_INT_PIN_CFG         0x37
#define MPU9150_INT_ENABLE          0x38
#define MPU9150_INT_STATUS          0x3a
#define MPU9150_ACCEL_XOUT_H        0x3b
#define MPU9150_GYRO_XOUT_H         0x43
#define MPU9150_EXT_SENS_DATA_00    0x49
#define MPU9150_I2C_SLV1_DO         0x64
#define MPU9150_I2C_MST_DELAY_CTRL  0x67
#define MPU9150_USER_CTRL           0x6a
#define MPU9150_PWR_MGMT_1          0x6b
#define MPU9150_PWR_MGMT_2          0x6c
#define MPU9150_FIFO_COUNT_H        0x72
#define MPU9150_FIFO_R_W            0x74
#define MPU9150_WHO_AM_I            0x75

//  sample rate defines (applies to gyros and accels, not mags)

#define MPU9150_SAMPLERATE_MIN      5                      // 5 samples per second is the lowest
#define MPU9150_SAMPLERATE_MAX      1000                   // 1000 samples per second is the absolute maximum

//  compass rate defines

#define MPU9150_COMPASSRATE_MIN     1                      // 1 samples per second is the lowest
#define MPU9150_COMPASSRATE_MAX     100                    // 100 samples per second is maximum

//  LPF options (gyros and accels)

#define MPU9150_LPF_256             0                       // gyro: 256Hz, accel: 260Hz
#define MPU9150_LPF_188             1                       // gyro: 188Hz, accel: 184Hz
#define MPU9150_LPF_98              2                       // gyro: 98Hz, accel: 98Hz
#define MPU9150_LPF_42              3                       // gyro: 42Hz, accel: 44Hz
#define MPU9150_LPF_20              4                       // gyro: 20Hz, accel: 21Hz
#define MPU9150_LPF_10              5                       // gyro: 10Hz, accel: 10Hz
#define MPU9150_LPF_5               6                       // gyro: 5Hz, accel: 5Hz

//  Gyro FSR options

#define MPU9150_GYROFSR_250         0                       // +/- 250 degrees per second
#define MPU9150_GYROFSR_500         8                       // +/- 500 degrees per second
#define MPU9150_GYROFSR_1000        0x10                    // +/- 1000 degrees per second
#define MPU9150_GYROFSR_2000        0x18                    // +/- 2000 degrees per second

//  Accel FSR options

#define MPU9150_ACCELFSR_2          0                       // +/- 2g
#define MPU9150_ACCELFSR_4          8                       // +/- 4g
#define MPU9150_ACCELFSR_8          0x10                    // +/- 8g
#define MPU9150_ACCELFSR_16         0x18                    // +/- 16g


//  AK8975 compass registers

#define AK8975_DEVICEID             0x0                     // the device ID
#define AK8975_ST1                  0x02                    // status 1
#define AK8975_CNTL                 0x0a                    // control reg
#define AK8975_ASAX                 0x10                    // start of the fuse ROM data

//  HMC5883 compass registers

#define HMC5883_CONFIG_A            0x00                    // configuration A
#define HMC5883_CONFIG_B            0x01                    // configuration B
#define HMC5883_MODE                0x02                    // mode
#define HMC5883_DATA_X_HI           0x03                    // data x msb
#define HMC5883_STATUS              0x09                    // status
#define HMC5883_ID                  0x0a                    // id


//----------------------------------------------------------
//
//  MPU-9250

//  MPU9250 I2C Slave Addresses

#define MPU9250_ADDRESS0            0x68
#define MPU9250_ADDRESS1            0x69
#define MPU9250_ID                  0x71

#define AK8963_ADDRESS              0x0c

//  Register map

#define MPU9250_SMPRT_DIV           0x19
#define MPU9250_GYRO_LPF            0x1a
#define MPU9250_GYRO_CONFIG         0x1b
#define MPU9250_ACCEL_CONFIG        0x1c
#define MPU9250_ACCEL_LPF           0x1d
#define MPU9250_FIFO_EN             0x23
#define MPU9250_I2C_MST_CTRL        0x24
#define MPU9250_I2C_SLV0_ADDR       0x25
#define MPU9250_I2C_SLV0_REG        0x26
#define MPU9250_I2C_SLV0_CTRL       0x27
#define MPU9250_I2C_SLV1_ADDR       0x28
#define MPU9250_I2C_SLV1_REG        0x29
#define MPU9250_I2C_SLV1_CTRL       0x2a
#define MPU9250_I2C_SLV2_ADDR       0x2b
#define MPU9250_I2C_SLV2_REG        0x2c
#define MPU9250_I2C_SLV2_CTRL       0x2d
#define MPU9250_I2C_SLV4_CTRL       0x34
#define MPU9250_INT_PIN_CFG         0x37
#define MPU9250_INT_ENABLE          0x38
#define MPU9250_INT_STATUS          0x3a
#define MPU9250_ACCEL_XOUT_H        0x3b
#define MPU9250_GYRO_XOUT_H         0x43
#define MPU9250_EXT_SENS_DATA_00    0x49
#define MPU9250_I2C_SLV1_DO         0x64
#define MPU9250_I2C_MST_DELAY_CTRL  0x67
#define MPU9250_USER_CTRL           0x6a
#define MPU9250_PWR_MGMT_1          0x6b
#define MPU9250_PWR_MGMT_2          0x6c
#define MPU9250_FIFO_COUNT_H        0x72
#define MPU9250_FIFO_R_W            0x74
#define MPU9250_WHO_AM_I            0x75

//  sample rate defines (applies to gyros and accels, not mags)

#define MPU9250_SAMPLERATE_MIN      5                       // 5 samples per second is the lowest
#define MPU9250_SAMPLERATE_MAX      32000                   // 32000 samples per second is the absolute maximum

//  compass rate defines

#define MPU9250_COMPASSRATE_MIN     1                       // 1 samples per second is the lowest
#define MPU9250_COMPASSRATE_MAX     100                     // 100 samples per second is maximum

//  Gyro LPF options

#define MPU9250_GYRO_LPF_8800       0x11                    // 8800Hz, 0.64mS delay
#define MPU9250_GYRO_LPF_3600       0x10                    // 3600Hz, 0.11mS delay
#define MPU9250_GYRO_LPF_250        0x00                    // 250Hz, 0.97mS delay
#define MPU9250_GYRO_LPF_184        0x01                    // 184Hz, 2.9mS delay
#define MPU9250_GYRO_LPF_92         0x02                    // 92Hz, 3.9mS delay
#define MPU9250_GYRO_LPF_41         0x03                    // 41Hz, 5.9mS delay
#define MPU9250_GYRO_LPF_20         0x04                    // 20Hz, 9.9mS delay
#define MPU9250_GYRO_LPF_10         0x05                    // 10Hz, 17.85mS delay
#define MPU9250_GYRO_LPF_5          0x06                    // 5Hz, 33.48mS delay

//  Gyro FSR options

#define MPU9250_GYROFSR_250         0                       // +/- 250 degrees per second
#define MPU9250_GYROFSR_500         8                       // +/- 500 degrees per second
#define MPU9250_GYROFSR_1000        0x10                    // +/- 1000 degrees per second
#define MPU9250_GYROFSR_2000        0x18                    // +/- 2000 degrees per second

//  Accel FSR options

#define MPU9250_ACCELFSR_2          0                       // +/- 2g
#define MPU9250_ACCELFSR_4          8                       // +/- 4g
#define MPU9250_ACCELFSR_8          0x10                    // +/- 8g
#define MPU9250_ACCELFSR_16         0x18                    // +/- 16g

//  Accel LPF options

#define MPU9250_ACCEL_LPF_1130      0x08                    // 1130Hz, 0.75mS delay
#define MPU9250_ACCEL_LPF_460       0x00                    // 460Hz, 1.94mS delay
#define MPU9250_ACCEL_LPF_184       0x01                    // 184Hz, 5.80mS delay
#define MPU9250_ACCEL_LPF_92        0x02                    // 92Hz, 7.80mS delay
#define MPU9250_ACCEL_LPF_41        0x03                    // 41Hz, 11.80mS delay
#define MPU9250_ACCEL_LPF_20        0x04                    // 20Hz, 19.80mS delay
#define MPU9250_ACCEL_LPF_10        0x05                    // 10Hz, 35.70mS delay
#define MPU9250_ACCEL_LPF_5         0x06                    // 5Hz, 66.96mS delay

//  AK8963 compass registers

#define AK8963_DEVICEID             0x48                    // the device ID
#define AK8963_ST1                  0x02                    // status 1
#define AK8963_CNTL                 0x0a                    // control reg
#define AK8963_ASAX                 0x10                    // start of the fuse ROM data

//----------------------------------------------------------
//
//  L3GD20

//  I2C Slave Addresses

#define L3GD20_ADDRESS0             0x6a
#define L3GD20_ADDRESS1             0x6b
#define L3GD20_ID                   0xd4

//  L3GD20 Register map

#define L3GD20_WHO_AM_I        0x0f
#define L3GD20_CTRL1           0x20
#define L3GD20_CTRL2           0x21
#define L3GD20_CTRL3           0x22
#define L3GD20_CTRL4           0x23
#define L3GD20_CTRL5           0x24
#define L3GD20_OUT_TEMP        0x26
#define L3GD20_STATUS          0x27
#define L3GD20_OUT_X_L         0x28
#define L3GD20_OUT_X_H         0x29
#define L3GD20_OUT_Y_L         0x2a
#define L3GD20_OUT_Y_H         0x2b
#define L3GD20_OUT_Z_L         0x2c
#define L3GD20_OUT_Z_H         0x2d
#define L3GD20_FIFO_CTRL       0x2e
#define L3GD20_FIFO_SRC        0x2f
#define L3GD20_IG_CFG          0x30
#define L3GD20_IG_SRC          0x31
#define L3GD20_IG_THS_XH       0x32
#define L3GD20_IG_THS_XL       0x33
#define L3GD20_IG_THS_YH       0x34
#define L3GD20_IG_THS_YL       0x35
#define L3GD20_IG_THS_ZH       0x36
#define L3GD20_IG_THS_ZL       0x37
#define L3GD20_IG_DURATION     0x38

//  Gyro sample rate defines

#define L3GD20_SAMPLERATE_95    0
#define L3GD20_SAMPLERATE_190   1
#define L3GD20_SAMPLERATE_380   2
#define L3GD20_SAMPLERATE_760   3

//  Gyro banwidth defines

#define L3GD20_BANDWIDTH_0     0
#define L3GD20_BANDWIDTH_1     1
#define L3GD20_BANDWIDTH_2     2
#define L3GD20_BANDWIDTH_3     3

//  Gyro FSR defines

#define L3GD20_FSR_250         0
#define L3GD20_FSR_500         1
#define L3GD20_FSR_2000        2

//  Gyro high pass filter defines

#define L3GD20_HPF_0           0
#define L3GD20_HPF_1           1
#define L3GD20_HPF_2           2
#define L3GD20_HPF_3           3
#define L3GD20_HPF_4           4
#define L3GD20_HPF_5           5
#define L3GD20_HPF_6           6
#define L3GD20_HPF_7           7
#define L3GD20_HPF_8           8
#define L3GD20_HPF_9           9

//----------------------------------------------------------
//
//  L3GD20H

//  I2C Slave Addresses

#define L3GD20H_ADDRESS0        0x6a
#define L3GD20H_ADDRESS1        0x6b
#define L3GD20H_ID              0xd7

//  L3GD20H Register map

#define L3GD20H_WHO_AM_I        0x0f
#define L3GD20H_CTRL1           0x20
#define L3GD20H_CTRL2           0x21
#define L3GD20H_CTRL3           0x22
#define L3GD20H_CTRL4           0x23
#define L3GD20H_CTRL5           0x24
#define L3GD20H_OUT_TEMP        0x26
#define L3GD20H_STATUS          0x27
#define L3GD20H_OUT_X_L         0x28
#define L3GD20H_OUT_X_H         0x29
#define L3GD20H_OUT_Y_L         0x2a
#define L3GD20H_OUT_Y_H         0x2b
#define L3GD20H_OUT_Z_L         0x2c
#define L3GD20H_OUT_Z_H         0x2d
#define L3GD20H_FIFO_CTRL       0x2e
#define L3GD20H_FIFO_SRC        0x2f
#define L3GD20H_IG_CFG          0x30
#define L3GD20H_IG_SRC          0x31
#define L3GD20H_IG_THS_XH       0x32
#define L3GD20H_IG_THS_XL       0x33
#define L3GD20H_IG_THS_YH       0x34
#define L3GD20H_IG_THS_YL       0x35
#define L3GD20H_IG_THS_ZH       0x36
#define L3GD20H_IG_THS_ZL       0x37
#define L3GD20H_IG_DURATION     0x38
#define L3GD20H_LOW_ODR         0x39

//  Gyro sample rate defines

#define L3GD20H_SAMPLERATE_12_5 0
#define L3GD20H_SAMPLERATE_25   1
#define L3GD20H_SAMPLERATE_50   2
#define L3GD20H_SAMPLERATE_100  3
#define L3GD20H_SAMPLERATE_200  4
#define L3GD20H_SAMPLERATE_400  5
#define L3GD20H_SAMPLERATE_800  6

//  Gyro banwidth defines

#define L3GD20H_BANDWIDTH_0     0
#define L3GD20H_BANDWIDTH_1     1
#define L3GD20H_BANDWIDTH_2     2
#define L3GD20H_BANDWIDTH_3     3

//  Gyro FSR defines

#define L3GD20H_FSR_245         0
#define L3GD20H_FSR_500         1
#define L3GD20H_FSR_2000        2

//  Gyro high pass filter defines

#define L3GD20H_HPF_0           0
#define L3GD20H_HPF_1           1
#define L3GD20H_HPF_2           2
#define L3GD20H_HPF_3           3
#define L3GD20H_HPF_4           4
#define L3GD20H_HPF_5           5
#define L3GD20H_HPF_6           6
#define L3GD20H_HPF_7           7
#define L3GD20H_HPF_8           8
#define L3GD20H_HPF_9           9

//----------------------------------------------------------
//
//  LSM303D

#define LSM303D_ADDRESS0        0x1e
#define LSM303D_ADDRESS1        0x1d
#define LSM303D_ID              0x49

//  LSM303D Register Map

#define LSM303D_TEMP_OUT_L      0x05
#define LSM303D_TEMP_OUT_H      0x06
#define LSM303D_STATUS_M        0x07
#define LSM303D_OUT_X_L_M       0x08
#define LSM303D_OUT_X_H_M       0x09
#define LSM303D_OUT_Y_L_M       0x0a
#define LSM303D_OUT_Y_H_M       0x0b
#define LSM303D_OUT_Z_L_M       0x0c
#define LSM303D_OUT_Z_H_M       0x0d
#define LSM303D_WHO_AM_I        0x0f
#define LSM303D_INT_CTRL_M      0x12
#define LSM303D_INT_SRC_M       0x13
#define LSM303D_INT_THS_L_M     0x14
#define LSM303D_INT_THS_H_M     0x15
#define LSM303D_OFFSET_X_L_M    0x16
#define LSM303D_OFFSET_X_H_M    0x17
#define LSM303D_OFFSET_Y_L_M    0x18
#define LSM303D_OFFSET_Y_H_M    0x19
#define LSM303D_OFFSET_Z_L_M    0x1a
#define LSM303D_OFFSET_Z_H_M    0x1b
#define LSM303D_REFERENCE_X     0x1c
#define LSM303D_REFERENCE_Y     0x1d
#define LSM303D_REFERENCE_Z     0x1e
#define LSM303D_CTRL0           0x1f
#define LSM303D_CTRL1           0x20
#define LSM303D_CTRL2           0x21
#define LSM303D_CTRL3           0x22
#define LSM303D_CTRL4           0x23
#define LSM303D_CTRL5           0x24
#define LSM303D_CTRL6           0x25
#define LSM303D_CTRL7           0x26
#define LSM303D_STATUS_A        0x27
#define LSM303D_OUT_X_L_A       0x28
#define LSM303D_OUT_X_H_A       0x29
#define LSM303D_OUT_Y_L_A       0x2a
#define LSM303D_OUT_Y_H_A       0x2b
#define LSM303D_OUT_Z_L_A       0x2c
#define LSM303D_OUT_Z_H_A       0x2d
#define LSM303D_FIFO_CTRL       0x2e
#define LSM303D_FIFO_SRC        0x2f
#define LSM303D_IG_CFG1         0x30
#define LSM303D_IG_SRC1         0x31
#define LSM303D_IG_THS1         0x32
#define LSM303D_IG_DUR1         0x33
#define LSM303D_IG_CFG2         0x34
#define LSM303D_IG_SRC2         0x35
#define LSM303D_IG_THS2         0x36
#define LSM303D_IG_DUR2         0x37
#define LSM303D_CLICK_CFG       0x38
#define LSM303D_CLICK_SRC       0x39
#define LSM303D_CLICK_THS       0x3a
#define LSM303D_TIME_LIMIT      0x3b
#define LSM303D_TIME_LATENCY    0x3c
#define LSM303D_TIME_WINDOW     0x3d
#define LSM303D_ACT_THIS        0x3e
#define LSM303D_ACT_DUR         0x3f

//  Accel sample rate defines

#define LSM303D_ACCEL_SAMPLERATE_3_125 1
#define LSM303D_ACCEL_SAMPLERATE_6_25 2
#define LSM303D_ACCEL_SAMPLERATE_12_5 3
#define LSM303D_ACCEL_SAMPLERATE_25   4
#define LSM303D_ACCEL_SAMPLERATE_50   5
#define LSM303D_ACCEL_SAMPLERATE_100  6
#define LSM303D_ACCEL_SAMPLERATE_200  7
#define LSM303D_ACCEL_SAMPLERATE_400  8
#define LSM303D_ACCEL_SAMPLERATE_800  9
#define LSM303D_ACCEL_SAMPLERATE_1600 10

//  Accel FSR

#define LSM303D_ACCEL_FSR_2     0
#define LSM303D_ACCEL_FSR_4     1
#define LSM303D_ACCEL_FSR_6     2
#define LSM303D_ACCEL_FSR_8     3
#define LSM303D_ACCEL_FSR_16    4

//  Accel filter bandwidth

#define LSM303D_ACCEL_LPF_773   0
#define LSM303D_ACCEL_LPF_194   1
#define LSM303D_ACCEL_LPF_362   2
#define LSM303D_ACCEL_LPF_50    3

//  Compass sample rate defines

#define LSM303D_COMPASS_SAMPLERATE_3_125    0
#define LSM303D_COMPASS_SAMPLERATE_6_25     1
#define LSM303D_COMPASS_SAMPLERATE_12_5     2
#define LSM303D_COMPASS_SAMPLERATE_25       3
#define LSM303D_COMPASS_SAMPLERATE_50       4
#define LSM303D_COMPASS_SAMPLERATE_100      5

//  Compass FSR

#define LSM303D_COMPASS_FSR_2   0
#define LSM303D_COMPASS_FSR_4   1
#define LSM303D_COMPASS_FSR_8   2
#define LSM303D_COMPASS_FSR_12  3

//----------------------------------------------------------
//
//  LSM303DLHC

#define LSM303DLHC_ACCEL_ADDRESS    0x19
#define LSM303DLHC_COMPASS_ADDRESS  0x1e

//  LSM303DLHC Accel Register Map

#define LSM303DLHC_CTRL1_A         0x20
#define LSM303DLHC_CTRL2_A         0x21
#define LSM303DLHC_CTRL3_A         0x22
#define LSM303DLHC_CTRL4_A         0x23
#define LSM303DLHC_CTRL5_A         0x24
#define LSM303DLHC_CTRL6_A         0x25
#define LSM303DLHC_REF_A           0x26
#define LSM303DLHC_STATUS_A        0x27
#define LSM303DLHC_OUT_X_L_A       0x28
#define LSM303DLHC_OUT_X_H_A       0x29
#define LSM303DLHC_OUT_Y_L_A       0x2a
#define LSM303DLHC_OUT_Y_H_A       0x2b
#define LSM303DLHC_OUT_Z_L_A       0x2c
#define LSM303DLHC_OUT_Z_H_A       0x2d
#define LSM303DLHC_FIFO_CTRL_A     0x2e
#define LSM303DLHC_FIFO_SRC_A      0x2f

//  LSM303DLHC Compass Register Map

#define LSM303DLHC_CRA_M            0x00
#define LSM303DLHC_CRB_M            0x01
#define LSM303DLHC_CRM_M            0x02
#define LSM303DLHC_OUT_X_H_M        0x03
#define LSM303DLHC_OUT_X_L_M        0x04
#define LSM303DLHC_OUT_Y_H_M        0x05
#define LSM303DLHC_OUT_Y_L_M        0x06
#define LSM303DLHC_OUT_Z_H_M        0x07
#define LSM303DLHC_OUT_Z_L_M        0x08
#define LSM303DLHC_STATUS_M         0x09
#define LSM303DLHC_TEMP_OUT_L_M     0x31
#define LSM303DLHC_TEMP_OUT_H_M     0x32

//  Accel sample rate defines

#define LSM303DLHC_ACCEL_SAMPLERATE_1       1
#define LSM303DLHC_ACCEL_SAMPLERATE_10      2
#define LSM303DLHC_ACCEL_SAMPLERATE_25      3
#define LSM303DLHC_ACCEL_SAMPLERATE_50      4
#define LSM303DLHC_ACCEL_SAMPLERATE_100     5
#define LSM303DLHC_ACCEL_SAMPLERATE_200     6
#define LSM303DLHC_ACCEL_SAMPLERATE_400     7

//  Accel FSR

#define LSM303DLHC_ACCEL_FSR_2     0
#define LSM303DLHC_ACCEL_FSR_4     1
#define LSM303DLHC_ACCEL_FSR_8     2
#define LSM303DLHC_ACCEL_FSR_16    3

//  Compass sample rate defines

#define LSM303DLHC_COMPASS_SAMPLERATE_0_75      0
#define LSM303DLHC_COMPASS_SAMPLERATE_1_5       1
#define LSM303DLHC_COMPASS_SAMPLERATE_3         2
#define LSM303DLHC_COMPASS_SAMPLERATE_7_5       3
#define LSM303DLHC_COMPASS_SAMPLERATE_15        4
#define LSM303DLHC_COMPASS_SAMPLERATE_30        5
#define LSM303DLHC_COMPASS_SAMPLERATE_75        6
#define LSM303DLHC_COMPASS_SAMPLERATE_220       7

//  Compass FSR

#define LSM303DLHC_COMPASS_FSR_1_3      1
#define LSM303DLHC_COMPASS_FSR_1_9      2
#define LSM303DLHC_COMPASS_FSR_2_5      3
#define LSM303DLHC_COMPASS_FSR_4        4
#define LSM303DLHC_COMPASS_FSR_4_7      5
#define LSM303DLHC_COMPASS_FSR_5_6      6
#define LSM303DLHC_COMPASS_FSR_8_1      7

//----------------------------------------------------------
//
//  LSM9DS0

//  I2C Slave Addresses

#define LSM9DS0_GYRO_ADDRESS0       0x6a
#define LSM9DS0_GYRO_ADDRESS1       0x6b
#define LSM9DS0_GYRO_ID             0xd4

#define LSM9DS0_ACCELMAG_ADDRESS0   0x1e
#define LSM9DS0_ACCELMAG_ADDRESS1   0x1d
#define LSM9DS0_ACCELMAG_ID         0x49

//  L3GD20 Register map

#define LSM9DS0_GYRO_WHO_AM_I       0x0f
#define LSM9DS0_GYRO_CTRL1          0x20
#define LSM9DS0_GYRO_CTRL2          0x21
#define LSM9DS0_GYRO_CTRL3          0x22
#define LSM9DS0_GYRO_CTRL4          0x23
#define LSM9DS0_GYRO_CTRL5          0x24
#define LSM9DS0_GYRO_OUT_TEMP       0x26
#define LSM9DS0_GYRO_STATUS         0x27
#define LSM9DS0_GYRO_OUT_X_L        0x28
#define LSM9DS0_GYRO_OUT_X_H        0x29
#define LSM9DS0_GYRO_OUT_Y_L        0x2a
#define LSM9DS0_GYRO_OUT_Y_H        0x2b
#define LSM9DS0_GYRO_OUT_Z_L        0x2c
#define LSM9DS0_GYRO_OUT_Z_H        0x2d
#define LSM9DS0_GYRO_FIFO_CTRL      0x2e
#define LSM9DS0_GYRO_FIFO_SRC       0x2f
#define LSM9DS0_GYRO_IG_CFG         0x30
#define LSM9DS0_GYRO_IG_SRC         0x31
#define LSM9DS0_GYRO_IG_THS_XH      0x32
#define LSM9DS0_GYRO_IG_THS_XL      0x33
#define LSM9DS0_GYRO_IG_THS_YH      0x34
#define LSM9DS0_GYRO_IG_THS_YL      0x35
#define LSM9DS0_GYRO_IG_THS_ZH      0x36
#define LSM9DS0_GYRO_IG_THS_ZL      0x37
#define LSM9DS0_GYRO_IG_DURATION    0x38

//  Gyro sample rate defines

#define LSM9DS0_GYRO_SAMPLERATE_95  0
#define LSM9DS0_GYRO_SAMPLERATE_190 1
#define LSM9DS0_GYRO_SAMPLERATE_380 2
#define LSM9DS0_GYRO_SAMPLERATE_760 3

//  Gyro banwidth defines

#define LSM9DS0_GYRO_BANDWIDTH_0    0
#define LSM9DS0_GYRO_BANDWIDTH_1    1
#define LSM9DS0_GYRO_BANDWIDTH_2    2
#define LSM9DS0_GYRO_BANDWIDTH_3    3

//  Gyro FSR defines

#define LSM9DS0_GYRO_FSR_250        0
#define LSM9DS0_GYRO_FSR_500        1
#define LSM9DS0_GYRO_FSR_2000       2

//  Gyro high pass filter defines

#define LSM9DS0_GYRO_HPF_0          0
#define LSM9DS0_GYRO_HPF_1          1
#define LSM9DS0_GYRO_HPF_2          2
#define LSM9DS0_GYRO_HPF_3          3
#define LSM9DS0_GYRO_HPF_4          4
#define LSM9DS0_GYRO_HPF_5          5
#define LSM9DS0_GYRO_HPF_6          6
#define LSM9DS0_GYRO_HPF_7          7
#define LSM9DS0_GYRO_HPF_8          8
#define LSM9DS0_GYRO_HPF_9          9

//  Accel/Mag Register Map

#define LSM9DS0_TEMP_OUT_L      0x05
#define LSM9DS0_TEMP_OUT_H      0x06
#define LSM9DS0_STATUS_M        0x07
#define LSM9DS0_OUT_X_L_M       0x08
#define LSM9DS0_OUT_X_H_M       0x09
#define LSM9DS0_OUT_Y_L_M       0x0a
#define LSM9DS0_OUT_Y_H_M       0x0b
#define LSM9DS0_OUT_Z_L_M       0x0c
#define LSM9DS0_OUT_Z_H_M       0x0d
#define LSM9DS0_WHO_AM_I        0x0f
#define LSM9DS0_INT_CTRL_M      0x12
#define LSM9DS0_INT_SRC_M       0x13
#define LSM9DS0_INT_THS_L_M     0x14
#define LSM9DS0_INT_THS_H_M     0x15
#define LSM9DS0_OFFSET_X_L_M    0x16
#define LSM9DS0_OFFSET_X_H_M    0x17
#define LSM9DS0_OFFSET_Y_L_M    0x18
#define LSM9DS0_OFFSET_Y_H_M    0x19
#define LSM9DS0_OFFSET_Z_L_M    0x1a
#define LSM9DS0_OFFSET_Z_H_M    0x1b
#define LSM9DS0_REFERENCE_X     0x1c
#define LSM9DS0_REFERENCE_Y     0x1d
#define LSM9DS0_REFERENCE_Z     0x1e
#define LSM9DS0_CTRL0           0x1f
#define LSM9DS0_CTRL1           0x20
#define LSM9DS0_CTRL2           0x21
#define LSM9DS0_CTRL3           0x22
#define LSM9DS0_CTRL4           0x23
#define LSM9DS0_CTRL5           0x24
#define LSM9DS0_CTRL6           0x25
#define LSM9DS0_CTRL7           0x26
#define LSM9DS0_STATUS_A        0x27
#define LSM9DS0_OUT_X_L_A       0x28
#define LSM9DS0_OUT_X_H_A       0x29
#define LSM9DS0_OUT_Y_L_A       0x2a
#define LSM9DS0_OUT_Y_H_A       0x2b
#define LSM9DS0_OUT_Z_L_A       0x2c
#define LSM9DS0_OUT_Z_H_A       0x2d
#define LSM9DS0_FIFO_CTRL       0x2e
#define LSM9DS0_FIFO_SRC        0x2f
#define LSM9DS0_IG_CFG1         0x30
#define LSM9DS0_IG_SRC1         0x31
#define LSM9DS0_IG_THS1         0x32
#define LSM9DS0_IG_DUR1         0x33
#define LSM9DS0_IG_CFG2         0x34
#define LSM9DS0_IG_SRC2         0x35
#define LSM9DS0_IG_THS2         0x36
#define LSM9DS0_IG_DUR2         0x37
#define LSM9DS0_CLICK_CFG       0x38
#define LSM9DS0_CLICK_SRC       0x39
#define LSM9DS0_CLICK_THS       0x3a
#define LSM9DS0_TIME_LIMIT      0x3b
#define LSM9DS0_TIME_LATENCY    0x3c
#define LSM9DS0_TIME_WINDOW     0x3d
#define LSM9DS0_ACT_THIS        0x3e
#define LSM9DS0_ACT_DUR         0x3f

//  Accel sample rate defines

#define LSM9DS0_ACCEL_SAMPLERATE_3_125 1
#define LSM9DS0_ACCEL_SAMPLERATE_6_25 2
#define LSM9DS0_ACCEL_SAMPLERATE_12_5 3
#define LSM9DS0_ACCEL_SAMPLERATE_25   4
#define LSM9DS0_ACCEL_SAMPLERATE_50   5
#define LSM9DS0_ACCEL_SAMPLERATE_100  6
#define LSM9DS0_ACCEL_SAMPLERATE_200  7
#define LSM9DS0_ACCEL_SAMPLERATE_400  8
#define LSM9DS0_ACCEL_SAMPLERATE_800  9
#define LSM9DS0_ACCEL_SAMPLERATE_1600 10

//  Accel FSR

#define LSM9DS0_ACCEL_FSR_2     0
#define LSM9DS0_ACCEL_FSR_4     1
#define LSM9DS0_ACCEL_FSR_6     2
#define LSM9DS0_ACCEL_FSR_8     3
#define LSM9DS0_ACCEL_FSR_16    4

//  Accel filter bandwidth

#define LSM9DS0_ACCEL_LPF_773   0
#define LSM9DS0_ACCEL_LPF_194   1
#define LSM9DS0_ACCEL_LPF_362   2
#define LSM9DS0_ACCEL_LPF_50    3

//  Compass sample rate defines

#define LSM9DS0_COMPASS_SAMPLERATE_3_125    0
#define LSM9DS0_COMPASS_SAMPLERATE_6_25     1
#define LSM9DS0_COMPASS_SAMPLERATE_12_5     2
#define LSM9DS0_COMPASS_SAMPLERATE_25       3
#define LSM9DS0_COMPASS_SAMPLERATE_50       4
#define LSM9DS0_COMPASS_SAMPLERATE_100      5

//  Compass FSR

#define LSM9DS0_COMPASS_FSR_2   0
#define LSM9DS0_COMPASS_FSR_4   1
#define LSM9DS0_COMPASS_FSR_8   2
#define LSM9DS0_COMPASS_FSR_12  3

#endif // _RTIMUDEFS_H
