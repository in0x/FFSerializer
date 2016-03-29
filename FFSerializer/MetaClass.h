#pragma once

#define META_CLASS(name) \
		virtual std::string ClassNameInstance() const { return #name; } \
        static std::string ClassName() { return #name; }

