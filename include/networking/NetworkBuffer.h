#pragma once

#include <cstdint>
#include <cstddef>
#include <string>

class NetworkBuffer
{
public:
	NetworkBuffer() = delete;
	NetworkBuffer(const NetworkBuffer&&) = delete;

	NetworkBuffer(std::uint8_t* rawData, std::size_t dataLength)
	{
		this->rawData = rawData;
		this->dataLength = dataLength;
		this->currentDataPointer = 0;
	}

	~NetworkBuffer()
	{
		dispose();
	}

	template <typename T>
	inline T* read()
	{
		std::size_t lengthToRead = sizeof(T);
		std::uint8_t* bytes = new std::uint8_t[lengthToRead];
		std::memcpy(reinterpret_cast<void*>(bytes), reinterpret_cast<void*>(currentDataPointer), lengthToRead);
		currentDataPointer += lengthToRead;

		return reinterpret_cast<T*>(bytes);
	}

	inline std::string readString()
	{
		// TODO: Implement
		return std::string("");
	}

	inline std::uint8_t* readBytes(std::size_t count)
	{
		std::uint8_t* bytes = new std::uint8_t[count];
		std::memcpy(reinterpret_cast<void*>(bytes), reinterpret_cast<void*>(currentDataPointer), count);
		currentDataPointer += count;

		return bytes;
	}

	inline void dispose()
	{
		delete rawData;
	}

private:
	std::uint8_t* rawData;
	std::size_t dataLength;
	std::uintptr_t currentDataPointer;
};
