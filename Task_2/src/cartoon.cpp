#include <string>
#include "libfilm/cartoon.hpp"

Cartoon::Cartoon(std::string name, uint32_t release_year, Type type) :
    Film(std::move(name), release_year), m_type(type) {}

void Cartoon::PrintDetailsToOStream(std::ostream& output_stream) const
{
	output_stream << "Film type: cartoon\n";
	output_stream << "Cartoon type: " << CartoonTypeToString(m_type) << '\n';
}

const char* Cartoon::CartoonTypeToString(Type type)
{
	static const char kUndefined[] = "undefined";
	static const char kPuppet[] = "puppet";
	static const char kClay[] = "clay";
	static const char kHanddrawn[] = "handdrawn";
	switch (type)
	{
	case Type::kPuppetCartoon:
		return kPuppet;
	case Type::kClayAnimation:
		return kClay;
	case Type::kHandDrawnCartoon:
		return kHanddrawn;
	default:
		return kUndefined;
	}
}
