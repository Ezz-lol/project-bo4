#pragma once

namespace fnv1a
{
	uint64_t generate_hash(const char* string, uint64_t start = 0xCBF29CE484222325);

	uint64_t generate_hash_pattern(const char* string);
}

namespace variables
{
	struct varInfo
	{
		std::string name;
		const char* desc;
		uint64_t fnv1a;
	};

	struct varEntry : varInfo
	{
		uintptr_t pointer = 0;
	};

	extern std::vector<varEntry> dvars_table;
	extern std::vector<varEntry> commands_table;

	std::vector<const char*> get_dvars_list();
	std::vector<const char*> get_commands_list();
}

namespace runtime_errors
{
	constexpr uint64_t custom_error_id = 0x42693201;
	const char* get_error_message(uint64_t code);
}