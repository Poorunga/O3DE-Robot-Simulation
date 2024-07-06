

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "MySimulationProjectSystemComponent.h"

namespace MySimulationProject
{
    void MySimulationProjectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<MySimulationProjectSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<MySimulationProjectSystemComponent>("MySimulationProject", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void MySimulationProjectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("MySimulationProjectService"));
    }

    void MySimulationProjectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("MySimulationProjectService"));
    }

    void MySimulationProjectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void MySimulationProjectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    MySimulationProjectSystemComponent::MySimulationProjectSystemComponent()
    {
        if (MySimulationProjectInterface::Get() == nullptr)
        {
            MySimulationProjectInterface::Register(this);
        }
    }

    MySimulationProjectSystemComponent::~MySimulationProjectSystemComponent()
    {
        if (MySimulationProjectInterface::Get() == this)
        {
            MySimulationProjectInterface::Unregister(this);
        }
    }

    void MySimulationProjectSystemComponent::Init()
    {
    }

    void MySimulationProjectSystemComponent::Activate()
    {
        MySimulationProjectRequestBus::Handler::BusConnect();
    }

    void MySimulationProjectSystemComponent::Deactivate()
    {
        MySimulationProjectRequestBus::Handler::BusDisconnect();
    }
}
