#pragma once

#include "CommandHandler.h"

enum EFilenameType
{
	Png,
	Npy,
	Exr,
	Bmp,
	PngBinary,
	NpyBinary,
	BmpBinary,
	Invalid, // Unrecognized filename type
};

/** Handle vget/vset /camera/ commands */
class FCameraHandler : public FCommandHandler
{
public:
	void RegisterCommands();

private:
	class UFusionCamSensor* GetCamera(const TArray<FString>& Args, FExecStatus& Status);

	FExecStatus GetCameraList(const TArray<FString>& Args);

	FExecStatus GetCameraLocation(const TArray<FString>& Args);

	FExecStatus SetCameraLocation(const TArray<FString>& Args);

	FExecStatus GetCameraRotation(const TArray<FString>& Args);

	FExecStatus SetCameraRotation(const TArray<FString>& Args);

	EFilenameType ParseFilenameType(const FString& Filename);

	FExecStatus SerializeData(const TArray<FColor>& Data, int Width, int Height, const FString& Filename);

	FExecStatus SerializeData(const TArray<FFloat16Color>& Data, int Width, int Height, const FString& Filename);

	FExecStatus SerializeData(const TArray<float>& Data, int Width, int Height, const FString& Filename);

	template<class T>
	void SaveData(const TArray<T>& Data, int Width, int Height,
		const TArray<FString>& Args, FExecStatus& Status);

	FExecStatus GetCameraLit(const TArray<FString>& Args);

	FExecStatus GetCameraDepth(const TArray<FString>& Args);

	FExecStatus GetCameraNormal(const TArray<FString>& Args);

	FExecStatus GetCameraObjMask(const TArray<FString>& Args);

	FExecStatus MoveTo(const TArray<FString>& Args);

	FExecStatus GetScreenshot(const TArray<FString>& Args);

	FExecStatus SetPlayerViewMode(const TArray<FString>& Args);

	FExecStatus GetPlayerViewMode(const TArray<FString>& Args);
};
