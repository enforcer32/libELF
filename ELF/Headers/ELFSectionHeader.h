#pragma once

#include <cstdint>

namespace ELF
{
	struct ELFSymbolTable
	{
		uint32_t Name;
		uint32_t Value; // 64bit also
		uint32_t Size;
		uint8_t Info;
		uint8_t Other;
		uint16_t SectionHeaderIndex;
	} __attribute__((packed));

	enum class ELFSectionType : uint32_t
	{
		Null = 0x0,
		PROGBITS = 0x1,
		SymbolTable = 0x2,
		StringTable = 0x3,
		RelocationA = 0x4,
		Hash = 0x5,
		Dynamic = 0x6,
		Note = 0x7,
		NoBits = 0x8,
		Relocation = 0x9,
		SharedLib = 0x10,
		DynamicSymbolTable = 0x11,
	};

	enum class ELFSectionFlags : uint32_t
	{
		Write = 0x1,
		Alloc = 0x2,
		ExecInstruction = 0x4,
	};

	struct ELF32SectionHeader
	{
		uint32_t Name; // Offset for SectionHeaderStringTableIndex
		ELFSectionType Type;
		ELFSectionFlags Flags;
		uint32_t Address;
		uint32_t Offset;
		uint32_t Size;
		uint32_t Link;
		uint32_t Info;
		uint32_t AddressAlignment;
		uint32_t EntrySize;
	} __attribute__((packed));

	struct ELF64SectionHeader
	{
		uint32_t Name; // Offset for SectionHeaderStringTableIndex
		ELFSectionType Type;
		ELFSectionFlags Flags;
		uint64_t Address;
		uint64_t Offset;
		uint32_t Size;
		uint32_t Link;
		uint32_t Info;
		uint32_t AddressAlignment;
		uint32_t EntrySize;
	} __attribute__((packed));
}
