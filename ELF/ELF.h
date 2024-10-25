#pragma once

#include "ELF/Headers/ELFHeader.h"

#include <string>
#include <memory>

namespace ELF
{
	class ELF
	{
	public:
		bool Parse(const std::string& path);

		void DumpHeaders();

	private:
		bool IsValidELF();

	private:
		std::string m_FilePath;
		std::unique_ptr<ELF32Header> m_Header;
	};
}
