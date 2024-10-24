#pragma once

#include <cstdint>

namespace ELF
{
	enum class ELFSegmentType : uint32_t
	{
		Null = 0x0,
		Load = 0x1,	
		Dynamic = 0x2,
		Interpreter = 0x3,
		Note = 0x4,
		SharedLib = 0x5,
		ProgramHeader = 0x6,
		TLS = 0x7,
	};

	struct ELF32ProgramHeader
	{
		ELFSegmentType Type;
		uint32_t Offset;
		uint32_t VirtualAddress;
		uint32_t PhysicalAddress;
		uint32_t FileSize;
		uint32_t MemorySize;
		uint32_t Flags; // PF_X Executable, PF_W Writable, PF_R Readable
		uint32_t Alignment;
	} __attribute__((packed));

	struct ELF64ProgramHeader
	{
		ELFSegmentType Type;
		uint32_t Flags; // PF_X Executable, PF_W Writable, PF_R Readable
		uint64_t Offset;
		uint64_t VirtualAddress;
		uint64_t PhysicalAddress;
		uint32_t FileSize;
		uint32_t MemorySize;
		uint32_t Alignment;
	} __attribute__((packed));
}
