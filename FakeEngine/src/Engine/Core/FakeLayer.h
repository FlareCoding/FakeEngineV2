#pragma once

#include "Engine/Core/Events/FakeEvent.h"
#include "Engine/Core/FakeTimeStep.h"

class FakeLayer
	{
	private:
		std::string DebugName;

	public:
		FakeLayer(const std::string &debugName = "DefaultLayer");
		virtual ~FakeLayer();

		inline const std::string &GetName() { return DebugName; }

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnRender(FakeTimeStep ts) {}
		virtual void OnEvent(FakeEvent &e) {}
	};