local SwitchControl = 
{
	Properties = {
		Entities = {
			LampBulbGreen = { default = EntityId{} },
			LampBulbRed = { default = EntityId{} },
			SwitchGreen = { default = EntityId() },
			SwitchRed = { default = EntityId() }
		},
		InputEvent = { default = "ControlSwitch" },
		Step = { default = 0 },
		LightIntensity = { default = 500 },
	}
}

function SwitchControl:OnActivate()
	Debug.Log("========== SwitchControl:OnActivate() ==========")
	self.inputEventNotificationBusHandler = InputEventNotificationBus.Connect(self, InputEventNotificationId(self.Properties.InputEvent))
	self.tickBusHandler = TickBus.Connect(self)
end

function SwitchControl:OnDeactivate()
	Debug.Log("========== SwitchControl:OnDeactivate() ==========")
	self.inputEventNotificationBusHandler:Disconnect()
	self.tickBusHandler:Disconnect()
end

function SwitchControl:OnHeld(value)
	pressREventNum = 1.0
	pressGEventNum = 2.0
	pressTEventNum = 3.0
	pressHEventNum = 4.0
	if value == pressREventNum then
		Debug.Log("press R")
		self:handleSwitchKeyPressed(self.Properties.Entities.SwitchRed)
	elseif value == pressGEventNum then
		Debug.Log("press G")
		self:handleSwitchKeyPressed(self.Properties.Entities.SwitchGreen)
	elseif value == pressTEventNum then
		Debug.Log("press T")
		self:handleResetKeyPressed(self.Properties.Entities.SwitchRed)
	elseif value == pressHEventNum then
		Debug.Log("press H")
		self:handleResetKeyPressed(self.Properties.Entities.SwitchGreen)
	end
end

function SwitchControl:handleSwitchKeyPressed(pressedKeyEntityId)
	rotation = TransformBus.Event.GetLocalRotation(pressedKeyEntityId)
	Debug.Log("switch key rotation: " .. tostring(rotation))
	if rotation["x"] >= -0.3 then
		rotation["x"] =  rotation["x"] - self.Properties.Step
		TransformBus.Event.SetLocalRotation(pressedKeyEntityId, rotation)
	end
end

function SwitchControl:handleResetKeyPressed(pressedKeyEntityId)
	rotation = TransformBus.Event.GetLocalRotation(pressedKeyEntityId)
	Debug.Log("reset key rotation: " .. tostring(rotation))
	if rotation["x"] <= 0 then
		rotation["x"] =  rotation["x"] + self.Properties.Step
		TransformBus.Event.SetLocalRotation(pressedKeyEntityId, rotation)
	end
end

function SwitchControl:OnTick(deltaTime, timePoint)
	greenSwitchRotation = TransformBus.Event.GetLocalRotation(self.Properties.Entities.SwitchGreen)
	redSwitchRotation = TransformBus.Event.GetLocalRotation(self.Properties.Entities.SwitchRed)
	
	if greenSwitchRotation["x"] <= -0.28 then
		AreaLightRequestBus.Event.SetIntensity(self.Properties.Entities.LampBulbGreen, self.Properties.LightIntensity)
	else
		AreaLightRequestBus.Event.SetIntensity(self.Properties.Entities.LampBulbGreen, 0)
	end
	
	if redSwitchRotation["x"] <= -0.28 then
		AreaLightRequestBus.Event.SetIntensity(self.Properties.Entities.LampBulbRed, self.Properties.LightIntensity)
	else
		AreaLightRequestBus.Event.SetIntensity(self.Properties.Entities.LampBulbRed, 0)
	end
end

return SwitchControl
