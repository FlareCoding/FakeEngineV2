workspace "FakeEngine"
	architecture "x64"
	configurations { "DEBUG", "Release" }
	
	outputdir = "%{cfg.buildcfg}-%{cfg.architecture}-%{cfg.system}"
	
	includedir = {}
	includedir["GLFW"] = "FakeEngine/vendor/GLFW/include"
	includedir["Glad"] = "FakeEngine/vendor/Glad/include"
	includedir["stb_image"] = "FakeEngine/vendor/stb_image"
	
	group "Dependencies"
	include "FakeEngine/vendor/GLFW"
	include "FakeEngine/vendor/Glad"
	group ""
	
	project "FakeEngine"
		location "FakeEngine"
		kind "StaticLib"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"
		
		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
		
		pchheader "FakePch.h"
		pchsource "FakeEngine/src/FakePch.cpp"
		
		defines
			{
			"_CRT_SECURE_NO_WARNINGS",
			"FAKE_RENDERER_OPENGL"
			}
			
		files
			{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/vendor/stb_image/**.h",
			"%{prj.name}/vendor/stb_image/**.cpp"
			}
			
		includedirs
			{
			"%{prj.name}/src",
			"%{includedir.GLFW}",
			"%{includedir.Glad}",
			"%{includedir.stb_image}"
			}
			
		links
			{
			"GLFW",
			"Glad",
			"opengl32.lib"
			}
			
		filter "system:macosx"
			systemversion "latest"
			
			defines
				{
				"FAKE_PLATFORM_MACOS",
				"GLFW_INCLUDE_NONE"
				}
				
			filter "configurations:Debug"
				defines "FAKE_DEBUG"
				runtime "Debug"
				symbols "on"
			
			filter "configurations:Release"
				defines "FAKE_RELEASE"
				runtime "Release"
				optimize "on"
				
		filter "system:linux"
			systemversion "latest"
			
			defines
				{
				"FAKE_PLATFORM_LINUX",
				"GLFW_INCLUDE_NONE"
				}
				
			filter "configurations:Debug"
				defines "FAKE_DEBUG"
				runtime "Debug"
				symbols "on"
			
			filter "configurations:Release"
				defines "FAKE_RELEASE"
				runtime "Release"
				optimize "on"
				
		filter "system:windows"
			systemversion "latest"
			
			defines
				{
				"FAKE_PLATFORM_WINDOWS",
				"GLFW_INCLUDE_NONE"
				}
				
			filter "configurations:Debug"
				defines "FAKE_DEBUG"
				runtime "Debug"
				symbols "on"
			
			filter "configurations:Release"
				defines "FAKE_RELEASE"
				runtime "Release"
				optimize "on"
			
	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"
		entrypoint "mainCRTStartup"
		
		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
		
		defines "_CRT_SECURE_NO_WARNINGS"
		
		files
			{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
			}
			
		includedirs
			{
			"FakeEngine/src",
			"FakeEngine/vendor"
			}
			
		links
			{
			"FakeEngine"
			}
			
		filter "system:macosx"
			systemversion "latest"
			
			defines
				{
				"FAKE_PLATFORM_MACOS",
				"GLFW_INCLUDE_NONE"
				}
				
			filter "configurations:Debug"
				defines "FAKE_DEBUG"
				runtime "Debug"
				symbols "on"
			
			filter "configurations:Release"
				defines "FAKE_RELEASE"
				runtime "Release"
				optimize "on"
				
		filter "system:linux"
			systemversion "latest"
			
			defines
				{
				"FAKE_PLATFORM_LINUX",
				"GLFW_INCLUDE_NONE"
				}
				
			filter "configurations:Debug"
				defines "FAKE_DEBUG"
				runtime "Debug"
				symbols "on"
			
			filter "configurations:Release"
				defines "FAKE_RELEASE"
				runtime "Release"
				optimize "on"
				
		filter "system:windows"
			systemversion "latest"
			
			defines
				{
				"FAKE_PLATFORM_WINDOWS",
				"GLFW_INCLUDE_NONE"
				}
				
			filter "configurations:Debug"
				defines "FAKE_DEBUG"
				runtime "Debug"
				symbols "on"
			
			filter "configurations:Release"
				defines "FAKE_RELEASE"
				runtime "Release"
				optimize "on"