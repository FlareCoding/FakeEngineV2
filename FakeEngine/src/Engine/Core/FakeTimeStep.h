#pragma once

class FakeTimeStep
	{
	private:
		double Time;

	public:
		FakeTimeStep(double time = 0.0) : Time(time) {}
		operator double() const { return Time; }

		double GetSeconds() const { return Time; }
		double GetMilliSeconds() const { return Time * 1000.0; }
	};