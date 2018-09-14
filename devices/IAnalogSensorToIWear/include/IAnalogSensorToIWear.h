/*
 * Copyright (C) 2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * GNU Lesser General Public License v2.1 or any later version.
 */

#ifndef WEARABLE_IANALOGSENSORTOIWEAR
#define WEARABLE_IANALOGSENSORTOIWEAR

#include "Wearable/IWear/IWear.h"

#include <yarp/dev/DeviceDriver.h>
#include <yarp/dev/PreciselyTimed.h>
#include <yarp/dev/Wrapper.h>

#include <memory>

namespace wearable {
    namespace devices {
        class IAnalogSensorToIWear;
    } // namespace devices
} // namespace wearable

class wearable::devices::IAnalogSensorToIWear
    : public wearable::IWear
    , public yarp::dev::DeviceDriver
    , public yarp::dev::IPreciselyTimed
    , public yarp::dev::IWrapper
    , public yarp::dev::IMultipleWrapper
{
private:
    class Impl;
    std::unique_ptr<Impl> pImpl;

public:
    IAnalogSensorToIWear();
    ~IAnalogSensorToIWear() override;

    IAnalogSensorToIWear(const IAnalogSensorToIWear& other) = delete;
    IAnalogSensorToIWear(IAnalogSensorToIWear&& other) = delete;
    IAnalogSensorToIWear& operator=(const IAnalogSensorToIWear& other) = delete;
    IAnalogSensorToIWear& operator=(IAnalogSensorToIWear&& other) = delete;

    // DeviceDriver
    bool open(yarp::os::Searchable& config) override;
    bool close() override;

    // IPreciselyTimed
    yarp::os::Stamp getLastInputStamp() override;

    // IWrapper interface
    bool attach(yarp::dev::PolyDriver* poly) override;
    bool detach() override;

    // IMultipleWrapper interface
    bool attachAll(const yarp::dev::PolyDriverList& driverList) override;
    bool detachAll() override;

    // =====
    // IWEAR
    // =====

    // -------
    // GENERIC
    // -------

    SensorPtr<const wearable::sensor::ISensor>
    getSensor(const wearable::sensor::SensorName name) const override;

    VectorOfSensorPtr<const wearable::sensor::ISensor>
    getSensors(const wearable::sensor::SensorType type) const override;

    WearableName getWearableName() const override;
    WearStatus getStatus() const override;
    TimeStamp getTimeStamp() const override;

    // --------------
    // SINGLE SENSORS
    // --------------

    SensorPtr<const wearable::sensor::IAccelerometer>
    getAccelerometer(const wearable::sensor::SensorName name) const override;

    SensorPtr<const wearable::sensor::IForce3DSensor>
    getForce3DSensor(const wearable::sensor::SensorName name) const override;

    SensorPtr<const wearable::sensor::IForceTorque6DSensor>
    getForceTorque6DSensor(const wearable::sensor::SensorName name) const override;

    SensorPtr<const wearable::sensor::IGyroscope>
    getGyroscope(const wearable::sensor::SensorName name) const override;

    SensorPtr<const wearable::sensor::IMagnetometer>
    getMagnetometer(const wearable::sensor::SensorName name) const override;

    SensorPtr<const wearable::sensor::IOrientationSensor>
    getOrientationSensor(const wearable::sensor::SensorName name) const override;

    SensorPtr<const wearable::sensor::ITemperatureSensor>
    getTemperatureSensor(const wearable::sensor::SensorName name) const override;

    SensorPtr<const wearable::sensor::ITorque3DSensor>
    getTorque3DSensor(const wearable::sensor::SensorName name) const override;

    SensorPtr<const sensor::IEmgSensor> getEmgSensor(const sensor::SensorName name) const override;

    SensorPtr<const sensor::IFreeBodyAccelerationSensor>
    getFreeBodyAccelerationSensor(const sensor::SensorName name) const override;

    SensorPtr<const sensor::IPoseSensor>
    getPoseSensor(const sensor::SensorName name) const override;

    SensorPtr<const sensor::IPositionSensor>
    getPositionSensor(const sensor::SensorName name) const override;

    SensorPtr<const sensor::ISkinSensor>
    getSkinSensor(const sensor::SensorName name) const override;

    SensorPtr<const sensor::IVirtualLinkKinSensor>
    getVirtualLinkKinSensor(const sensor::SensorName name) const override;

    SensorPtr<const sensor::IVirtualSphericalJointKinSensor>
    getVirtualSphericalJointKinSensor(const sensor::SensorName name) const override;
};

#endif // WEARABLE_IANALOGSENSORTOIWEAR
