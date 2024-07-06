
#include <AzCore/Serialization/SerializeContext.h>
#include "MySimulationProjectEditorSystemComponent.h"

namespace MySimulationProject
{
    void MySimulationProjectEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<MySimulationProjectEditorSystemComponent, MySimulationProjectSystemComponent>()
                ->Version(0);
        }
    }

    MySimulationProjectEditorSystemComponent::MySimulationProjectEditorSystemComponent() = default;

    MySimulationProjectEditorSystemComponent::~MySimulationProjectEditorSystemComponent() = default;

    void MySimulationProjectEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("MySimulationProjectEditorService"));
    }

    void MySimulationProjectEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("MySimulationProjectEditorService"));
    }

    void MySimulationProjectEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void MySimulationProjectEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void MySimulationProjectEditorSystemComponent::Activate()
    {
        MySimulationProjectSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void MySimulationProjectEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        MySimulationProjectSystemComponent::Deactivate();
    }

} // namespace MySimulationProject
