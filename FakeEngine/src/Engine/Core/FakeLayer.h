#pragma once

#include "Engine/Core/Events/FakeEvent.h"
#include "Engine/Core/FakeTimeStep.h"

class FakeLayer
	{
	private:
		FakeString DebugName;

	public:
		FakeLayer(const FakeString &debugName = "DefaultLayer");
		virtual ~FakeLayer();

		inline const FakeString &GetName() { return DebugName; }

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnRender(FakeTimeStep ts) {}
		virtual void OnEvent(FakeEvent &e) {}
	};
