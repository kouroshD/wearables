/*
 * Copyright (C) 2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * GNU Lesser General Public License v2.1 or any later version.
 */

#ifndef WEAR_IVIRTUALSPHERICALJOINTKINSENSOR
#define WEAR_IVIRTUALSPHERICALJOINTKINSENSOR

#include "Wearable/IWear/Sensors/ISensor.h"

namespace wearable {
    namespace sensor {
        class IVirtualSphericalJointKinSensor;
    }
} // namespace wearable

class wearable::sensor::IVirtualSphericalJointKinSensor : public wearable::sensor::ISensor
{
protected:
public:
    virtual ~IVirtualSphericalJointKinSensor() = 0;

    // CONVENTION: RPY are defined as rotationa about X-Y-Z wrt fix frame
    virtual bool getJointAnglesAsRPY(wearable::Vector3 angleAsRPY) const = 0;
    virtual bool getJointVelocities(wearable::Vector3 velocities) const = 0;
    virtual bool getJointAccelerations(wearable::Vector3 accelerations) const = 0;
};

#endif // WEAR_IVIRTUALSPHERICALJOINTKINSENSOR