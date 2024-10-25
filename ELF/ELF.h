#pragma once

#include "ELF/Headers/ELFHeader.h"
#include "ELF/Headers/ELFProgramHeader.h"

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

	private:
		bool IsValidELF();
		bool ParseProgramHeaders();

	private:
		std::string m_FilePath;
		std::fstream m_FileStream;
		std::unique_ptr<ELF32Header> m_Header;
		std::vector<ELF32ProgramHeader> m_ProgramHeaders;
	};
}
