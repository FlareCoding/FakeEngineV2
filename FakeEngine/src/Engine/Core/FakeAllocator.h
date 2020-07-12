#pragma once

#include "FakePch.h"

struct FakeAllocator
	{
	byte *Data;
	uint32_t Size;

	FakeAllocator()
		: Data(nullptr), Size(0)
		{
		}

	FakeAllocator(byte *data, uint32_t size)
		: Data(data), Size(size)
		{
		}

	static FakeAllocator Copy(void *data, uint32_t size)
		{
		FakeAllocator buffer;
		buffer.Allocate(size);
		memcpy(buffer.Data, data, size);
		return buffer;
		}

	void Allocate(uint32_t size)
		{
		delete[] Data;
		Data = nullptr;
		if (0 == size) return;

		// TODO: LOG
		Data = new byte[size];
		Size = size;
		}

	void ZeroInitialize()
		{
		if (Data)
			memset(Data, 0, Size);
		}

	void Write(byte *data, uint32_t size, uint32_t offset = 0)
		{
		// TODO: ASSERT offset + size <= Size SONST BufferOverflow
		memcpy(Data + offset, data, size);
		}

	operator bool() const
		{
		return Data;
		}

	byte &operator[](size_t i)
		{
		return Data[i];
		}

	byte &operator[](size_t i) const
		{
		return Data[i];
		}

	template<typename T>
	T *As()
		{
		return (T*)Data;
		}

	uint32_t GetSize() const
		{
		return Size;
		}
	};