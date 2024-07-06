
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>
#include <MySimulationProjectSystemComponent.h>

namespace MySimulationProject
{
    class MySimulationProjectModuleInterface
        : public AZ::Module
    {
    public:
        AZ_RTTI(MySimulationProjectModuleInterface, "{EB10B5EC-BAF5-4870-B83A-A893370B3717}", AZ::Module);
        AZ_CLASS_ALLOCATOR(MySimulationProjectModuleInterface, AZ::SystemAllocator, 0);

        MySimulationProjectModuleInterface()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                MySimulationProjectSystemComponent::CreateDescriptor(),
                });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<MySimulationProjectSystemComponent>(),
            };
        }
    };
}// namespace MySimulationProject
