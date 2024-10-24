#include "ELF/ELF.h"

#include <iostream>
#include <fstream>

namespace ELF
{
	bool ELF::Parse(const std::string& path)
	{
		std::ifstream file(path, std::ios::binary);
		if (file.fail())
		{
			std::cerr << "ELF->Parse: Failed to Open: " + path << std::endl;
			return false;
		}

		m_Header = std::make_unique<ELF32Header>();
		file.seekg(0, std::ios::beg);
		file.read((char*)m_Header.get(), sizeof(ELF32Header));

		if (!IsValidELF())
		{
			std::cerr << "ELF->Parse: Invalid ELF Magic Number: " + path << std::endl;
			return false;
		}

		std::cout << "Successfully Parsed ELF: " + path << std::endl;
		return true;
	}

	bool ELF::IsValidELF()
	{
		return m_Header->Ident.Magic == ELF_MAGIC_NUMBER;
	}
}
