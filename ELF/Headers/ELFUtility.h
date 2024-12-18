#pragma once

#include "ELF/Headers/ELFHeader.h"
#include "ELF/Headers/ELFProgramHeader.h"
#include "ELF/Headers/ELFSectionHeader.h"

#include <string>

namespace ELF
{
	namespace Utility
	{
		std::string ELFToString(const ELF32Header& header);
		
		std::string ELFToString(const ELFIdent& ident);
		std::string ELFToString(const ELFClassType& elfClass);
		std::string ELFToString(const ELFDataType& data);
		std::string ELFToString(const ELFOSABIType& osabi);
		std::string ELFToString(const ELFHeaderFileType& type);
		std::string ELFToString(const ELFHeaderMachineType& machine);

		std::string ELFToString(const ELF32ProgramHeader& programHeader);
		std::string ELFToString(const ELFProgramHeaderType& programHeaderType);
		std::string ELFToString(const ELFProgramHeaderFlags& programHeaderFlags);

		std::string ELFToString(const ELF32SectionHeader& sectionHeader);
		std::string ELFToString(const ELFSectionHeaderType& sectionHeaderType);
		std::string ELFToString(const ELFSectionHeaderFlags& sectionHeaderFlags);
	}
}
