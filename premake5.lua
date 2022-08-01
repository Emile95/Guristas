workspace "Guristas"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-${architecture}"

project "Guristas"
	location "Guristas"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GURISTAS_PLATFORM_WINDOWS",
			"GURISTAS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines	"GURISTAS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines	"GURISTAS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines	"GURISTAS_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Guristas/vendor/spdlog/include",
		"Guristas/src"
	}

	links
	{
		"Guristas"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GURISTAS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines	"GURISTAS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines	"GURISTAS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines	"GURISTAS_DIST"
		optimize "On"