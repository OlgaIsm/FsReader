#pragma once

// Export or Import form DLL
#ifdef Fs_DLL_EXPORTS
#define Fs_DLL_API __declspec(dllexport)
#else
#define Fs_DLL_API __declspec(dllimport)
#endif

#include <iostream>
#include <windows.h>

using namespace std;

// Struct of FS
// JumpCodeN - not use
#pragma pack(1)
typedef struct
{
	BYTE jumpCode1[3];
	BYTE oemID[8];
	WORD bytesPerSector;
	BYTE sectorPerCluster;
	WORD reservedSectors;
	BYTE jumpCode2[3];
	WORD jumpCode3;
	BYTE mediaDiscr;
	WORD jumpCode4;
	WORD sectorperTrack;
	WORD numOfHeaders;
	DWORD hiddenSectors;
	DWORD jumpCode5;
	DWORD jumpCode6;
	ULONGLONG totalSectors;
	ULONGLONG lcnForSMFT;
	ULONGLONG lcnForSMFTMirr;
	DWORD clusterPerMFT;
	BYTE clusterPerIndex;
	BYTE jumpCode7[3];
	ULONGLONG volumeSerialNumber;
	DWORD checksum;
	BYTE bootstrap[426];
	WORD endMarker;

} NTFS_struct;
#pragma pack()

// Create base class
class FileSystem {
public:
	FileSystem(string fileName) {

		this->fileName = fileName;
	}
	virtual void bootInfo() {};
private:
	string fileName;
};

// Creating a subclass FileSystem
class NTFS : public FileSystem {
public:
	NTFS(string fileName) : FileSystem(fileName) {

		this->fileName = fileName;
	}
	void bootInfo() override;
private:
	string fileName;
	void PrintBootSectInfo(NTFS_struct bootRec);
	bool setPointerToBegin(HANDLE fileHandle);
};

// Creating a factory
class FileSystemFactory {
public:
	FileSystem* create(string fileName);
private:
	string checkFS(string fileName);
};

// Declaring functions
extern "C++" Fs_DLL_API void printFS(string fileName);
