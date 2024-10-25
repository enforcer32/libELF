#include <iostream>
#include <cstring>

#include <ELF/ELF.h>

int main(int argc, char** argv)
{
	if (argc < 3 || argc > 3)
	{
		std::cout << "ELFReader: Usage [option] FilePath\n\tOptions: -h = Dump Headers\n\t\t -p = Dump Program Headers\n";
		return 0;
	}

	const char* options = argv[1];
	const char* path = argv[2];

	ELF::ELF elf;
	if (!elf.Parse(path))
	{
		std::cerr << "Failed to Parse Kernel.elf\n";
		return -1;
	}

	if (!strcmp(options, "-h"))
		elf.DumpHeaders();

	if (!strcmp(options, "-p"))
		elf.DumpProgramHeaders();

	return 0;
}
