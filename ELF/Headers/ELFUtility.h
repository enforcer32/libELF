#pragma once

#include "ELF/Headers/ELFHeader.h"

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
	}
}
