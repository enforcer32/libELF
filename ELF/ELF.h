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

	private:
		bool IsValidELF();

	private:
		std::unique_ptr<ELF32Header> m_Header;
	};
}
