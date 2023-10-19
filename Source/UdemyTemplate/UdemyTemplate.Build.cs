// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UdemyTemplate : ModuleRules
{
	public UdemyTemplate(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
