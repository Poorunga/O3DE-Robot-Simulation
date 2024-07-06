/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace MySimulationProject
{
    class MySimulationProjectRequests
    {
    public:
        AZ_RTTI(MySimulationProjectRequests, "{182E8168-475F-4EF5-BBEF-B05FDA64DAE2}");
        virtual ~MySimulationProjectRequests() = default;
        // Put your public methods here
    };

    class MySimulationProjectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using MySimulationProjectRequestBus = AZ::EBus<MySimulationProjectRequests, MySimulationProjectBusTraits>;
    using MySimulationProjectInterface = AZ::Interface<MySimulationProjectRequests>;

} // namespace MySimulationProject
