
#include <MySimulationProjectModuleInterface.h>
#include "MySimulationProjectEditorSystemComponent.h"

#include "MySimulationProjectSampleComponent.h"
namespace MySimulationProject
{
    class MySimulationProjectEditorModule
        : public MySimulationProjectModuleInterface
    {
    public:
        AZ_RTTI(MySimulationProjectEditorModule, "{8FF6B373-2762-4CF7-B516-EDE3E3FC81F8}", MySimulationProjectModuleInterface);
        AZ_CLASS_ALLOCATOR(MySimulationProjectEditorModule, AZ::SystemAllocator, 0);

        MySimulationProjectEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                MySimulationProjectEditorSystemComponent::CreateDescriptor(),
                MySimulationProjectSampleComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<MySimulationProjectEditorSystemComponent>(),
            };
        }
    };
}// namespace MySimulationProject

AZ_DECLARE_MODULE_CLASS(Gem_MySimulationProject, MySimulationProject::MySimulationProjectEditorModule)
