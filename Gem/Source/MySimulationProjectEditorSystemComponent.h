
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <MySimulationProjectSystemComponent.h>

namespace MySimulationProject
{
    /// System component for MySimulationProject editor
    class MySimulationProjectEditorSystemComponent
        : public MySimulationProjectSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = MySimulationProjectSystemComponent;
    public:
        AZ_COMPONENT(MySimulationProjectEditorSystemComponent, "{EFA2AFC2-E74C-44FD-8E18-4B8D03669343}", BaseSystemComponent);
        static void Reflect(AZ::ReflectContext* context);

        MySimulationProjectEditorSystemComponent();
        ~MySimulationProjectEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace MySimulationProject
