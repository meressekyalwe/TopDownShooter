// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownShooterGameInstance.h"

bool UTopDownShooterGameInstance::GetWeaponInfoByName(FName NameWeapon, FWeaponInfos & OutInfo)
{
	bool bIsFind = false;
	FWeaponInfos* WeaponInfoRow;

	if (WeaponInfoTable)
	{
		WeaponInfoRow = WeaponInfoTable->FindRow<FWeaponInfos>(NameWeapon, "", false);
		if (WeaponInfoRow)
		{
			bIsFind = true;
			OutInfo = *WeaponInfoRow;
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UTPSGameInstance::GetWeaponInfoByName - WeaponTable -NULL"));
	}

	return bIsFind;
}

bool UTopDownShooterGameInstance::GetDropItemInfoByName(FName NameItem, FDropItem & OutInfo)
{
	bool bIsFind = false;
	FDropItem* DropItemInfoRow;

	if (DropItemInfoTable)
	{
		DropItemInfoRow = WeaponInfoTable->FindRow<FDropItem>(NameItem, "", false);
		if (DropItemInfoRow)
		{
			bIsFind = true;
			OutInfo = *DropItemInfoRow;
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UTPSGameInstance::GetWeaponInfoByName - WeaponTable -NULL"));
	}

	return bIsFind;
}

bool UTopDownShooterGameInstance::GetDropItemInfoByWeaponName(FName NameItem, FDropItem & OutInfo)
{
	bool bIsFind = false;

	if (DropItemInfoTable)
	{
		FDropItem* DropItemInfoRow;
		TArray<FName>RowNames = DropItemInfoTable->GetRowNames();

		int8 i = 0;
		while (i < RowNames.Num() && !bIsFind)
		{
			DropItemInfoRow = DropItemInfoTable->FindRow<FDropItem>(RowNames[i], "");
			if (DropItemInfoRow->WeaponInfo.NameItem == NameItem)
			{
				OutInfo = (*DropItemInfoRow);
				bIsFind = true;
			}
			i++;//fix
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UTPSGameInstance::GetDropItemInfoByName - DropItemInfoTable -NULL"));
	}

	return bIsFind;
}
