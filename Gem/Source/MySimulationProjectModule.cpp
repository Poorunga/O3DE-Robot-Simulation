
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "MySimulationProjectSystemComponent.h"
#include "MySimulationProjectSampleComponent.h"

namespace MySimulationProject
{
    class MySimulationProjectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(MySimulationProjectModule, "{8FF6B373-2762-4CF7-B516-EDE3E3FC81F8}", AZ::Module);
        AZ_CLASS_ALLOCATOR(MySimulationProjectModule, AZ::SystemAllocator);

        MySimulationProjectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                MySimulationProjectSystemComponent::CreateDescriptor(),
                MySimulationProjectSampleComponent::CreateDescriptor(),
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

AZ_DECLARE_MODULE_CLASS(Gem_MySimulationProject, MySimulationProject::MySimulationProjectModule)
