/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/Component/Component.h>

#include <MySimulationProject/MySimulationProjectBus.h>

namespace MySimulationProject
{
    class MySimulationProjectSystemComponent
        : public AZ::Component
        , protected MySimulationProjectRequestBus::Handler
    {
    public:
        AZ_COMPONENT(MySimulationProjectSystemComponent, "{919E90E3-7F79-425C-9DB7-487463C22115}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        MySimulationProjectSystemComponent();
        ~MySimulationProjectSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // MySimulationProjectRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
