#pragma once

#include "FakeLayer.h"

class FakeLayerStack
	{
	private:
		std::vector<FakeLayer*> Layers;
		unsigned int LayerInsertIndex = 0;

	public:
		FakeLayerStack();
		virtual ~FakeLayerStack();

		void PushLayer(FakeLayer *layer);
		void PopLayer(FakeLayer *layer);
		void PushOverlay(FakeLayer *overlay);
		void PopOverlay(FakeLayer *overlay);

		std::vector<FakeLayer*>::iterator begin()
			{
			return Layers.begin();
			}

		std::vector<FakeLayer*>::iterator end()
			{
			return Layers.end();
			}

		std::vector<FakeLayer*>::const_iterator begin() const
			{
			return Layers.begin();
			}

		std::vector<FakeLayer*>::const_iterator end() const
			{
			return Layers.end();
			}
	};