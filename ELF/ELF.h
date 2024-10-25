#pragma once

#include "ELF/Headers/ELFHeader.h"
#include "ELF/Headers/ELFProgramHeader.h"
#include "ELF/Headers/ELFSectionHeader.h"

#include <string>
#include <memory>
#include <vector>
#include <fstream>

namespace ELF
{
	class ELF
	{
	public:
		bool Parse(const std::string& path);

		void DumpHeaders();
		void DumpProgramHeaders();
		void DumpSectionHeaders();

	private:
		bool IsValidELF();
		bool ParseProgramHeaders();
		bool ParseSectionHeaders();

	private:
		std::string m_FilePath;
		std::fstream m_FileStream;
		std::unique_ptr<ELF32Header> m_Header;
		std::vector<ELF32ProgramHeader> m_ProgramHeaders;
		std::vector<ELF32SectionHeader> m_SectionHeaders;
	};
}
