#include "ELF/Headers/ELFUtility.h"

#include <format>

namespace ELF
{
	namespace Utility
	{
		std::string ELFToString(const ELF32Header& header)
		{
			std::string str;
			str += ELFToString(header.Ident) + "\n";
			str += "Type: " + ELFToString(header.Type) + "\n";
			str += "Machine: " + ELFToString(header.Machine) + "\n";
			str += "Version: " + std::to_string(header.Version) + "\n";
			str += "EntryPointAddress: " + std::format("0x{:x}", header.EntryPointAddress) + "\n";
			str += "ProgramHeaderOffset: " + std::to_string(header.ProgramHeaderOffset) + "\n";
			str += "SectionHeaderOffset: " + std::to_string(header.SectionHeaderOffset) + "\n";
			str += "Flags: " + std::format("0x{:x}", header.Flags) + "\n";
			str += "ELFHeaderSize: " + std::to_string(header.ELFHeaderSize) + " bytes" + "\n";
			str += "ProgramHeaderEntrySize: " + std::to_string(header.ProgramHeaderEntrySize) + " bytes" + "\n";
			str += "ProgramHeaderCount: " + std::to_string(header.ProgramHeaderCount) + "\n";
			str += "SectionHeaderEntrySize: " + std::to_string(header.SectionHeaderEntrySize) + " bytes" + "\n";
			str += "SectionHeaderCount: " + std::to_string(header.SectionHeaderCount) + "\n";
			str += "SectionHeaderStringTableIndex: " + std::to_string(header.SectionHeaderStringTableIndex);
			return str;
		}

		std::string ELFToString(const ELFIdent& ident)
		{
			std::string str;
			str += "Magic Number: " + std::format("0x{:x}", ident.Magic)+ "\n";
			str += "Class: " + ELFToString(ident.Class) + "\n";
			str += "Data: " + ELFToString(ident.Data) + "\n";
			str += "Version: " + std::to_string(ident.Version) + "\n";
			str += "OSABI: " + ELFToString(ident.OSABI) + "\n";
			str += "ABIVersion: " + std::to_string(ident.ABIVersion);
			return str;
		}

		std::string ELFToString(const ELFClassType& elfClass)
		{
			std::string str;
			switch(elfClass)
			{
			case ELFClassType::None:
				str = "Invalid";
				break;
			case ELFClassType::ELF32:
				str = "ELF32";
				break;
			case ELFClassType::ELF64:
				str = "ELF64";
				break;
			}
			return str;
		}

		std::string ELFToString(const ELFDataType& data)
		{
			std::string str;
			switch(data)
			{
			case ELFDataType::None:
				str = "Invalid";
				break;
			case ELFDataType::LSB:
				str = "Little-Endian";
				break;
			case ELFDataType::MSB:
				str = "Big-Endian";
				break;
			}
			return str;
		}

		std::string ELFToString(const ELFOSABIType& osabi)
		{
			std::string str;
			switch(osabi)
			{
			case ELFOSABIType::SystemV:
				str = "SystemV";
				break;
			case ELFOSABIType::HPUX:
				str = "HP-UX";
				break;
			case ELFOSABIType::NetBSD:
				str = "NetBSD";
				break;
			case ELFOSABIType::Linux:
				str = "Linux";
				break;
			}
			return str;
		}

		std::string ELFToString(const ELFHeaderFileType& type)
		{
			std::string str;
			switch(type)
			{
			case ELFHeaderFileType::None:
				str = "None";
				break;
			case ELFHeaderFileType::Relocatable:
				str = "Relocatable";
				break;
			case ELFHeaderFileType::Executable:
				str = "Executable";
				break;
			case ELFHeaderFileType::SharedObject:
				str = "SharedObject";
				break;
			case ELFHeaderFileType::Core:
				str = "Core";
				break;
			}
			return str;
		}

		std::string ELFToString(const ELFHeaderMachineType& machine)
		{
			std::string str;
			switch(machine)
			{
			case ELFHeaderMachineType::X86:
				str = "x86";
				break;
			case ELFHeaderMachineType::MIPS:
				str = "MIPS";
				break;
			case ELFHeaderMachineType::ARM:
				str = "ARM";
				break;
			case ELFHeaderMachineType::AMD64:
				str = "AMD64";
				break;
			case ELFHeaderMachineType::ARMV8:
				str = "ARMV8";
				break;
			case ELFHeaderMachineType::RISCV:
				str = "RISCV";
				break;
			}
			return str;
		}
	}
}
