#include "ELF/ELF.h"
#include "ELF/Headers/ELFUtility.h"

#include <iostream>

namespace ELF
{
	bool ELF::Parse(const std::string& path)
	{
		m_FileStream = std::fstream(path, std::ios::binary | std::ios::in);
		if (m_FileStream.fail())
		{
			std::cerr << "ELF->Parse: Failed to Open: " + path << std::endl;
			return false;
		}

		m_FilePath = path;

		m_Header = std::make_unique<ELF32Header>();
		m_FileStream.seekg(0, std::ios::beg);
		m_FileStream.read((char *)m_Header.get(), sizeof(ELF32Header));

		if (!IsValidELF())
		{
			std::cerr << "ELF->Parse: Invalid ELF Magic Number: " + path << std::endl;
			return false;
		}

		if(!ParseProgramHeaders())
		{
			std::cerr << "ELF->Parse: Failed to Parse Program Headers: " + path << std::endl;
			return false;
		}

		if(!ParseSectionHeaders())
		{
			std::cerr << "ELF->Parse: Failed to Parse Section Headers: " + path << std::endl;
			return false;
		}

		std::cout << "Successfully Parsed ELF: " + path << std::endl;
		return true;
	}

	void ELF::DumpHeaders()
	{
		std::cout << "---------------ELF Headers For: " << m_FilePath << "---------------" << std::endl;
		std::cout << Utility::ELFToString(*m_Header) << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
	}

	void ELF::DumpProgramHeaders()
	{
		std::cout << "---------------ELF Program Headers For: " << m_FilePath << "---------------" << std::endl;
		std::cout << "ProgramHeaderCount: " << std::to_string(m_Header->ProgramHeaderCount) << "\n\n";
		
		for(size_t i = 0; i < m_ProgramHeaders.size(); i++)
		{
			std::cout << "Header " << i << "\n";
			std::cout << Utility::ELFToString(m_ProgramHeaders[i]) << "\n";

			if ((i + 1) < m_ProgramHeaders.size())
				std::cout << "\n";
		}
		std::cout << "------------------------------------------------------------" << std::endl;
	}

	void ELF::DumpSectionHeaders()
	{
		std::cout << "---------------ELF Section Headers For: " << m_FilePath << "---------------" << std::endl;
		std::cout << "SectionHeaderCount: " << std::to_string(m_Header->SectionHeaderCount) << "\n\n";
		
		for(size_t i = 0; i < m_SectionHeaders.size(); i++)
		{
			std::cout << "Header " << i << "\n";
			std::cout << Utility::ELFToString(m_SectionHeaders[i]) << "\n";

			if ((i + 1) < m_SectionHeaders.size())
				std::cout << "\n";
		}
		std::cout << "------------------------------------------------------------" << std::endl;
	}

	bool ELF::IsValidELF()
	{
		return m_Header->Ident.Magic == ELF_MAGIC_NUMBER;
	}

	bool ELF::ParseProgramHeaders()
	{
		m_ProgramHeaders.reserve(m_Header->ProgramHeaderCount);

		for(size_t i = 0; i < m_Header->ProgramHeaderCount; i++)
		{
			ELF32ProgramHeader programHeader;
			m_FileStream.seekg((m_Header->ProgramHeaderOffset) + (m_Header->ProgramHeaderEntrySize * i));
			m_FileStream.read((char*)&programHeader, sizeof(ELF32ProgramHeader));
			m_ProgramHeaders.push_back(programHeader);
		}

		return true;
	}

	bool ELF::ParseSectionHeaders()
	{
		m_SectionHeaders.reserve(m_Header->SectionHeaderCount);

		for(size_t i = 0; i < m_Header->SectionHeaderCount; i++)
		{
			ELF32SectionHeader sectionHeader;
			m_FileStream.seekg((m_Header->SectionHeaderOffset) + (m_Header->SectionHeaderEntrySize * i));
			m_FileStream.read((char*)&sectionHeader, sizeof(ELF32SectionHeader));
			m_SectionHeaders.push_back(sectionHeader);
		}

		return true;
	}
}
