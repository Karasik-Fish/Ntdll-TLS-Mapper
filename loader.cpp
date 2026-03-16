#include <intrin.h>
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned long long QWORD;
typedef unsigned long long ULONGLONG;
typedef unsigned short wchar_t;
#define ERROR 0
#define PATH_BUF_SIZE 65536
#define wname_size_const 512
#define TLS_number 512
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define WINAPI __stdcall

typedef void* (WINAPI* f_CreateFileA)(const char* lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
	void* lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, void* hTemplateFile);

typedef void* (WINAPI* f_CreateFileW)(const wchar_t* lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
	void* lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, void* hTemplateFile);

typedef DWORD(WINAPI* f_GetFileSize)(void* hFile, DWORD* lpFileSizeHigh);

typedef void* (WINAPI* f_VirtualAlloc)(void* lpAddress, size_t dwSize, DWORD flAllocationType, DWORD flProtect);

typedef int (WINAPI* f_ReadFile)(void* hFile, void* lpBuffer, DWORD  nNumberOfBytesToRead, DWORD* lpNumberOfBytesRead,
	void* lpOverlapped);

typedef int (WINAPI* f_CloseHandle)(void* hObject);

typedef int (WINAPI* f_VirtualFree)(void* lpAddress, size_t dwSize, DWORD dwFreeType);

typedef int (WINAPI* f_LoadLibraryA)(const char* lpLibFileName);

typedef DWORD(WINAPI* f_TlsAlloc)();

typedef void* (WINAPI* f_HeapAlloc)(void* hHeap, DWORD dwFlags, size_t dwBytes);

typedef void (WINAPI* f_TLS_CALLBACK)(void* DllHandle, DWORD Reason, void* Reserved);

typedef int (WINAPI* f_VirtualProtect)(void* lpAddress, size_t dwSize, DWORD flNewProtect, DWORD* lpflOldProtect);

typedef int (WINAPI* f_HeapFree)(void* hHeap, DWORD dwFlags, void* lpMem);

typedef int (WINAPI* f_DllMain)(void* hinstDLL, DWORD fdwReason, void* lpvReserved);

typedef void (*f_ExeEntry)();

typedef DWORD(WINAPI* f_LdrLockLoaderLock)(DWORD Flags, DWORD* State, QWORD* Cookie);

typedef DWORD(WINAPI* f_LdrUnlockLoaderLock)(DWORD Flags, QWORD Cookie);

typedef int (*f_TestFunction)();

typedef DWORD(WINAPI* f_GetSystemDirectoryW)(wchar_t* lpBuffer, DWORD uSize);

typedef DWORD(WINAPI* f_GetWindowsDirectoryW)(wchar_t* lpBuffer, DWORD uSize);

typedef DWORD(WINAPI* f_GetModuleFileNameW)(void* hModule, wchar_t* lpFilename, DWORD nSize);

typedef struct _RUNTIME_FUNCTION {
	DWORD BeginAddress;
	DWORD EndAddress;
	union {
		DWORD UnwindInfoAddress;
		DWORD UnwindData;
	} DUMMYUNIONNAME;
} RUNTIME_FUNCTION;

typedef int (WINAPI* f_RtlAddFunctionTable)(RUNTIME_FUNCTION* FunctionTable, DWORD EntryCount, QWORD BaseAddress);

typedef struct _FUNCS
{
	f_CreateFileW _CreateFileW;
	f_GetFileSize _GetFileSize;
	f_VirtualAlloc _VirtualAlloc;
	f_ReadFile _ReadFile;
	f_CloseHandle _CloseHandle;
	f_VirtualFree _VirtualFree;
	f_LoadLibraryA _LoadLibraryA;
	f_RtlAddFunctionTable _RtlAddFunctionTable;
	f_TlsAlloc _TlsAlloc;
	f_HeapAlloc _HeapAlloc;
	f_VirtualProtect _VirtualProtect;
	f_HeapFree _HeapFree;
	f_GetModuleFileNameW _GetModuleFileNameW;
	f_GetWindowsDirectoryW _GetWindowsDirectoryW;
	f_GetSystemDirectoryW _GetSystemDirectoryW;
	f_LdrLockLoaderLock _LdrLockLoaderLock;
	f_LdrUnlockLoaderLock _LdrUnlockLoaderLock;
} FUNCS;

typedef struct _LIST_ENTRY
{
	struct _LIST_ENTRY* Flink;
	struct _LIST_ENTRY* Blink;
} LIST_ENTRY;

typedef struct _UNICODE_STRING
{
	unsigned short Length;
	unsigned short MaximumLenght;
	wchar_t* Buffer;
} UNICODE_STRING;

typedef struct _PEB
{
	BYTE Reserved1[2];
	BYTE BeingDebugged;
	BYTE Reserved2[21];
	void* Ldr;
} PEB;

typedef struct _PEB_LDR_DATA
{
	DWORD Length;
	BYTE Initialized;
	void* SsHandle;
	LIST_ENTRY InLoadOrderModuleList;
	LIST_ENTRY InMemoryOrderModuleList;
	LIST_ENTRY InInitializationOrderModuleList;
} PEB_LDR_DATA;

typedef struct _LDR_DATA_TABLE_ENTRY
{
	LIST_ENTRY InLoadOrderLinks;
	LIST_ENTRY InMemoryOrderLinks;
	LIST_ENTRY InInitializationOrderLinks;
	void* DllBase;
	void* EntryPoint;
	DWORD SizeOfImage;
	UNICODE_STRING FullDllName;
	UNICODE_STRING BaseDllName;
} LDR_DATA_TABLE_ENTRY;

typedef struct _IMAGE_DOS_HEADER
{
	WORD e_magic;
	BYTE skip[58];
	int e_lfanew;
} IMAGE_DOS_HEADER;

typedef struct _IMAGE_FILE_HEADER {
	WORD  Machine;
	WORD  NumberOfSections;
	DWORD TimeDateStamp;
	DWORD PointerToSymbolTable;
	DWORD NumberOfSymbols;
	WORD  SizeOfOptionalHeader;
	WORD  Characteristics;
} IMAGE_FILE_HEADER;

typedef struct _IMAGE_DATA_DIRECTORY {
	unsigned int VirtualAddress;
	unsigned int Size;
} IMAGE_DATA_DIRECTORY;

typedef struct _IMAGE_OPTIONAL_HEADER64 {
	WORD                 Magic;
	BYTE                 MajorLinkerVersion;
	BYTE                 MinorLinkerVersion;
	DWORD                SizeOfCode;
	DWORD                SizeOfInitializedData;
	DWORD                SizeOfUninitializedData;
	DWORD                AddressOfEntryPoint;
	DWORD                BaseOfCode;
	ULONGLONG            ImageBase;
	DWORD                SectionAlignment;
	DWORD                FileAlignment;
	WORD                 MajorOperatingSystemVersion;
	WORD                 MinorOperatingSystemVersion;
	WORD                 MajorImageVersion;
	WORD                 MinorImageVersion;
	WORD                 MajorSubsystemVersion;
	WORD                 MinorSubsystemVersion;
	DWORD                Win32VersionValue;
	DWORD                SizeOfImage;
	DWORD                SizeOfHeaders;
	DWORD                CheckSum;
	WORD                 Subsystem;
	WORD                 DllCharacteristics;
	ULONGLONG            SizeOfStackReserve;
	ULONGLONG            SizeOfStackCommit;
	ULONGLONG            SizeOfHeapReserve;
	ULONGLONG            SizeOfHeapCommit;
	DWORD                LoaderFlags;
	DWORD                NumberOfRvaAndSizes;
	IMAGE_DATA_DIRECTORY DataDirectory[16];
} IMAGE_OPTIONAL_HEADER;

typedef struct _IMAGE_NT_HEADERS
{
	DWORD                   Signature;
	IMAGE_FILE_HEADER       FileHeader;
	IMAGE_OPTIONAL_HEADER OptionalHeader;
} IMAGE_NT_HEADERS;

typedef struct _IMAGE_EXPORT_DIRECTORY {
	DWORD Characteristics;
	DWORD TimeDateStamp;
	WORD MajorVersion;
	WORD MinorVersion;
	DWORD Name;                 // RVA имени DLL
	DWORD Base;                 // Стартовый ординал
	DWORD NumberOfFunctions;    // Всего адресов функций
	DWORD NumberOfNames;        // Число именованных функций
	DWORD AddressOfFunctions;   // RVA массива адресов (EAT)
	DWORD AddressOfNames;       // RVA массива имен (ENT)
	DWORD AddressOfNameOrdinals;// RVA массива ординалов (EOT)
} IMAGE_EXPORT_DIRECTORY;

typedef struct _IMAGE_SECTION_HEADER {
	BYTE  Name[8];
	union {
		DWORD PhysicalAddress;
		DWORD VirtualSize;
	} Misc;
	DWORD VirtualAddress;
	DWORD SizeOfRawData;
	DWORD PointerToRawData;
	DWORD PointerToRelocations;
	DWORD PointerToLinenumbers;
	WORD  NumberOfRelocations;
	WORD  NumberOfLinenumbers;
	DWORD Characteristics;
} IMAGE_SECTION_HEADER;

typedef struct _IMAGE_BASE_RELOCATION {
	DWORD   VirtualAddress;
	DWORD   SizeOfBlock;
} IMAGE_BASE_RELOCATION;

typedef struct _IMAGE_IMPORT_DESCRIPTOR
{
	DWORD OriginalFirstThunk;
	DWORD TimeDateStamp;
	DWORD ForwarderChain;
	DWORD Name;
	DWORD FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;
typedef struct _IMAGE_THUNK_DATA64 {
	union {
		ULONGLONG ForwarderString;
		ULONGLONG Function;
		ULONGLONG Ordinal;
		ULONGLONG AddressOfData;
	} u1;
} IMAGE_THUNK_DATA64;
typedef struct _IMAGE_IMPORT_BY_NAME {
	WORD    Hint;
	BYTE    Name[1];
} IMAGE_IMPORT_BY_NAME;

typedef struct _IMAGE_TLS_DIRECTORY64
{
	ULONGLONG StartAddressOfRawData;
	ULONGLONG EndAddressOfRawData;
	ULONGLONG AddressOfIndex;
	ULONGLONG AddressOfCallbacks;
	DWORD     SizeOfZeroFill;
	DWORD     Characteristics;
} IMAGE_TLS_DIRECTORY64;

typedef struct _API_SET_NAMESPACE
{
	DWORD Version;
	DWORD Size;
	DWORD Flags;
	DWORD Count;
	DWORD EntryOffset;
	DWORD HashOffset;
	DWORD HashFactor;
} API_SET_NAMESPACE;

typedef struct _API_SET_NAMESPACE_ENTRY {
	DWORD Flags;
	DWORD NameOffset;
	DWORD NameLength;
	DWORD HashedLength;
	DWORD ValueOffset;
	DWORD ValueCount;
} API_SET_NAMESPACE_ENTRY, * PAPI_SET_NAMESPACE_ENTRY;

typedef struct _API_SET_VALUE_ENTRY {
	DWORD Flags;
	DWORD NameOffset;
	DWORD NameLength;
	DWORD ValueOffset;
	DWORD ValueLength;
} API_SET_VALUE_ENTRY;

typedef struct _thread_variables
{
	DWORD* number_of_bits;
	void** buf_address;
	QWORD* number_of_cells;
	void* goal_func;
} thread_variables;
//functions 
static LIST_ENTRY* get_list_p()
{
	PEB* peb = (PEB*)__readgsqword(0x60);
	PEB_LDR_DATA* ldr = (PEB_LDR_DATA*)(peb->Ldr);
	LIST_ENTRY* head = (LIST_ENTRY*)(&ldr->InLoadOrderModuleList);
	return head;
}

static void my_zero_fill(BYTE* dest, size_t size)
{
	__stosb(dest, 0, size);
}

static void my_memcpy(BYTE* dest, BYTE* src, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		*dest++ = *src++;
	}
}

static QWORD str_search(char* str, char sim)
{
	QWORD counter = 0;
	int c;
	while (c = str[counter])
	{
		if (c == sim)
		{
			return counter;
		}
		counter++;
	}
	if (sim == '\0')
		return counter;
	return -1;
}

static int str_rsearch(char* str, char sim)
{
	int counter = 0;
	int res = -1;
	int c;
	while (c = str[counter])
	{
		if (c == sim)
		{
			res = counter;
		}
		counter++;
	}
	return res;
}

static long long str_to_num(char* str)
{
	long long res = 0;
	int counter = 0;
	if (*str == '#') str++;

	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + ((QWORD)*str - 0x30);
		counter++;
		str++;
	}
	if (!counter) return -1;
	return res;
}

static size_t str_cat(char* s1, char* s2)
{
	size_t ind1 = str_search(s1, '\0');
	size_t ind2 = 0;
	while (s2[ind2] != '\0')
	{
		s1[ind1++] = s2[ind2++];
	}
	s1[ind1] = s2[ind2];
	return 1;

}

//for UTF16
static QWORD hash_func(wchar_t* str, WORD Length)
{
	QWORD res = 0;
	WORD key = 0xc0c1;
	int c;
	WORD counter = 1;

	int last_dot = -1;
	for (int i = 0; i < Length / 2; i++)
	{
		if (str[i] == L'.') last_dot = i * 2;
	}

	if (last_dot != -1) Length = last_dot;

	while ((counter <= (Length / 2)) && (c = *str++))
	{
		if (c >= L'A' && c <= L'Z') c += 32;
		//res += ((QWORD)(c ^ key) + ((c >> 4) ^ (key >> 3)) + (key | (~counter))) * counter;
		res = ((res << 5) + res) + c; // hash * 33 + c
		counter++;
	}
	return res;
}

static QWORD hash_func_char(char* str, QWORD ImageSize, IMAGE_DOS_HEADER* pDos, QWORD len)
{
	QWORD res = 0;
	WORD key = 0xc0c1;
	int c;
	WORD counter = 1;
	QWORD ogr = str_search(str, '.');
	if (ogr == -1)
		ogr = len;
	else
		ogr = min(len, ogr);
	//ImageSize - (QWORD)(pDos)
	while ((counter <= min(ImageSize - (QWORD)(pDos), ogr)) && (c = *str++))
	{
		if (c >= 'A' && c <= 'Z') c += 32;
		//res += ((QWORD)(c ^ key) + ((c >> 4) ^ (key >> 3)) + (key | (~counter))) * counter;
		res = ((res << 5) + res) + c;
		counter++;
	}
	return res;
}

//By InLoadOrderLinks
static void get_dll_base(LIST_ENTRY* lib_of_libs, QWORD hash, unsigned char** pC, DWORD* pSize) 
{
	LDR_DATA_TABLE_ENTRY* pD = (LDR_DATA_TABLE_ENTRY*)lib_of_libs->Flink;
	LIST_ENTRY* curr = &pD->InLoadOrderLinks;
	while (curr != lib_of_libs && (!pD->BaseDllName.Buffer || hash_func(pD->BaseDllName.Buffer, pD->BaseDllName.Length) != hash))
	{
		pD = (LDR_DATA_TABLE_ENTRY*)pD->InLoadOrderLinks.Flink;
		curr = &pD->InLoadOrderLinks;
	}
	if (curr == lib_of_libs)
	{
		*pC = ERROR;
		*pSize = ERROR;
		return;
	}
	*pC = (unsigned char*)pD->DllBase;
	*pSize = pD->SizeOfImage;
}
//
static void get_dll_base_by_path(LIST_ENTRY* lib_of_libs, wchar_t* wbuf, unsigned char** pC, DWORD* pSize, DWORD wbuf_size)
{
	LDR_DATA_TABLE_ENTRY* pD = (LDR_DATA_TABLE_ENTRY*)lib_of_libs->Flink;
	LIST_ENTRY* curr = &pD->InLoadOrderLinks;
	while (curr != lib_of_libs && (!pD->FullDllName.Buffer || wstr_cmp(wbuf, wbuf_size, pD->FullDllName.Buffer, pD->FullDllName.Length / 2)))
	{
		pD = (LDR_DATA_TABLE_ENTRY*)pD->InLoadOrderLinks.Flink;
		curr = &pD->InLoadOrderLinks;
	}
	if (curr == lib_of_libs)
	{
		*pC = ERROR;
		*pSize = ERROR;
		return;
	}
	*pC = (unsigned char*)pD->DllBase;
	*pSize = pD->SizeOfImage;
}
static void get_dll_base_by_name(LIST_ENTRY* lib_of_libs, wchar_t* name, unsigned char** pC, DWORD* pSize, DWORD name_size)
{
	LDR_DATA_TABLE_ENTRY* pD = (LDR_DATA_TABLE_ENTRY*)lib_of_libs->Flink;
	LIST_ENTRY* curr = &pD->InLoadOrderLinks;
	while (curr != lib_of_libs && (!pD->BaseDllName.Buffer || wstr_cmp(name, name_size, pD->BaseDllName.Buffer, pD->BaseDllName.Length / 2)))
	{
		pD = (LDR_DATA_TABLE_ENTRY*)pD->InLoadOrderLinks.Flink;
		curr = &pD->InLoadOrderLinks;
	}
	if (curr == lib_of_libs)
	{
		*pC = ERROR;
		*pSize = ERROR;
		return;
	}
	*pC = (unsigned char*)pD->DllBase;
	*pSize = pD->SizeOfImage;
}



static int init_nt_exp_data(IMAGE_DOS_HEADER* pkernel_dos, QWORD kernelImageSize,
	IMAGE_NT_HEADERS** pkernel_nt, IMAGE_DATA_DIRECTORY** pkernel_data, IMAGE_EXPORT_DIRECTORY** pkernel_exp)
{
	if (sizeof(IMAGE_DOS_HEADER) > kernelImageSize)
	{
		return ERROR;
	}
	if ((pkernel_dos->e_magic != 0x5a4d) || pkernel_dos->e_lfanew + sizeof(IMAGE_NT_HEADERS) > kernelImageSize
		|| pkernel_dos->e_lfanew < sizeof(IMAGE_DOS_HEADER))
	{
		return ERROR;
	}

	*pkernel_nt = (IMAGE_NT_HEADERS*)((unsigned char*)pkernel_dos + pkernel_dos->e_lfanew);
	if ((*pkernel_nt)->Signature != 0x4550)
	{
		return ERROR;
	}

	*pkernel_data = (IMAGE_DATA_DIRECTORY*)((*pkernel_nt)->OptionalHeader.DataDirectory);

	*pkernel_exp = (IMAGE_EXPORT_DIRECTORY*)((char*)pkernel_dos + (*pkernel_data)->VirtualAddress);

	if ((QWORD)(*pkernel_exp) - (QWORD)(pkernel_dos)+sizeof(IMAGE_EXPORT_DIRECTORY) > kernelImageSize)
	{
		return ERROR;
	}

	return 1;
}

static int check_str(char* str, QWORD ImageSize, unsigned char* p_lib)
{
	for (int i = 0; i < min(ImageSize - ((QWORD)str - (QWORD)p_lib), 256); i++)
	{
		if (str[i] == '\0')
		{
			return 1;
		}
	}
	return ERROR;
}

static int str_to_wstr(char* str, DWORD size1, wchar_t* wstr, DWORD size2)
{
	DWORD ind = 0;
	if (size2 < size1)
		return -1;
	while (ind < size1 && ind < size2 && str[ind] != '\0')
	{
		wstr[ind] = (wchar_t)str[ind];
		ind++;
	}
	if (ind < size1 && ind < size2)
	{
		wstr[ind] = (wchar_t)str[ind];
		return ind;
	}
	return -1;
}

static DWORD wstr_len(wchar_t* s, DWORD max_size)
{
	for (DWORD i = 0; i < max_size; i++)
	{
		if (s[i] == L'\0')
			return i;
	}
	return -1;
}

static DWORD str_len(char* s, DWORD max_size)
{
	for (DWORD i = 0; i < max_size; i++)
	{
		if (s[i] == L'\0')
			return i;
	}
	return -1;
}

static int wstr_cat(wchar_t* s1, wchar_t* s2, DWORD size1, DWORD size2, DWORD have_space1)
{
	if (have_space1 == 0)
	{
		have_space1 = wstr_len(s1, size1);
		if (have_space1 == (DWORD)-1)
			return ERROR;
	}

	if ((QWORD)size1 < (QWORD)size2 + have_space1 + 1)
		return ERROR;

	DWORD ind = 0;
	for (DWORD i = have_space1; i < size1; i++)
	{
		s1[i] = s2[ind];
		if (s2[ind] == L'\0')
		{
			break;
		}
		ind++;
	}
	return 1;
}

static DWORD wstr_rsearch(wchar_t* s, DWORD size, wchar_t sim)
{
	DWORD res = -1;
	for (DWORD i = 0; i < size; i++)
	{
		if (s[i] == sim)
			res = i;
	}

	return res;
}

typedef struct _ps
{
	wchar_t* p;
	QWORD size;
} ps;

typedef struct _ps_for_full_path
{
	wchar_t* p;
	QWORD total_size;
	wchar_t* cur_p;
	QWORD cur_size;
} ps_full;

typedef struct _my_tls_context
{
	DWORD TlsIndex;
	void* CurDataStart;
	QWORD data_size;
	DWORD zero_size;
} my_tls_context;

#define MAX_TLS_LEN 64
my_tls_context myTLSlist[MAX_TLS_LEN];
int myTLScounter = 0;


static int wstr_substr_search(ps* ps)
{
	for (QWORD i = 0; i < (ps->size / 2) - 3; i++)
	{
		if (((*(DWORD*)(ps->p + i)) == 0x00000000) || ((*(DWORD*)(ps->p + i + 1)) == 0x00000000) || ((*(DWORD*)(ps->p + i + 2)) == 0x00000000))
		{
			return ERROR;
		}
		//*(QWORD*)(p + i) == 0x0048005400410050
		//if ( ((*(p + i) == 0x50) || (*(p + i) == 0x70)) &&
		//	((*(p + i + 1) == 0x41) || (*(p + i + 1) == 0x61)) &&
		//	((*(p + i + 2) == 0x54) || (*(p + i + 2) == 0x74)) &&
		//	((*(p + i + 3) == 0x48) || (*(p + i + 3) == 0x68)))
		if (((*(QWORD*)(ps->p + i)) | 0x0020002000200020) == 0x0068007400610070)
		{
			if (i == 0 || *(WORD*)(ps->p + i - 1) == 0x0000)
			{
				if (i + 4 < (ps->size / 2) && *(WORD*)(ps->p + i + 4) == 0x3d)
				{
					ps->p = ps->p + i;
					ps->size = ps->size - i * 2;
					return 1;
				}
			}
		}
	}
	return ERROR;
}

//static void wstr_fill(wchar_t* p, QWORD size, wchar_t el)
//{
//	for (QWORD i = 0; i < size; i++)
//	{
//		*p++ = el;
//	}
//}

static void wstr_copy(wchar_t* p1, QWORD s1, wchar_t* p2, QWORD s2)
{
	if (s1 == 0 || s2 == 0)
		return;

	QWORD i = 0;
	for (; i < min(s2, s1); i++)
	{
		if (*p2 == L'\0')
		{
			*p1++ = *p2++;
			return;
		}
		else
			*p1++ = *p2++;
	}

	if (i < s1)
	{
		*p1 = L'\0';
	}


}

static int wstr_cmp(wchar_t* s1, QWORD size1, wchar_t* s2, QWORD size2)
{

	for (QWORD i = 0; i < min(size1, size2); i++)
	{
		wchar_t c1 = s1[i];
		wchar_t c2 = s2[i];

		if (c1 >= L'A' && c1 <= L'Z') c1 += 32;
		if (c2 >= L'A' && c2 <= L'Z') c2 += 32;

		if (c1 > c2) return 1;
		if (c1 < c2) return -1;
	}
	if (size1 > size2)
		return 1;
	else if (size1 < size2)
		return -1;
	return 0;
}

static int wstr_cmp_for_api(wchar_t* s1, QWORD size1, wchar_t* s2, QWORD size2)
{
	for (QWORD i = 0; i < min(size1, size2); i++)
	{
		wchar_t c1 = s1[i];
		wchar_t c2 = s2[i];

		if (c1 >= L'A' && c1 <= L'Z') c1 += 32;
		if (c2 >= L'A' && c2 <= L'Z') c2 += 32;

		if (c1 > c2) return 1;
		if (c1 < c2) return -1;
	}
	return 0;
}

static API_SET_NAMESPACE_ENTRY* api_bin_search(API_SET_NAMESPACE_ENTRY* e_p, DWORD count, char* base, DWORD size, wchar_t* cur_name, QWORD cur_name_size)
{
	API_SET_NAMESPACE_ENTRY* start = e_p;
	API_SET_NAMESPACE_ENTRY* end = e_p + count - 1;
	API_SET_NAMESPACE_ENTRY* mid = 0;
	if (sizeof(API_SET_NAMESPACE_ENTRY) * count > size)
		return ERROR;
	//while (start <= end)
	//{
	//	mid = start + ((end - start) / 2);
	//	if (mid->NameOffset > size)
	//		return ERROR;
		//int cmp_res = wstr_cmp((wchar_t*)(base + mid->NameOffset), mid->NameLength / 2, cur_name, cur_name_size);
		//if (cmp_res == -1)
	//	{
	//		start = mid + 1;
	//	}
	//	else if (cmp_res == 1)
	//	{
	//		end = mid - 1;
	//	}
	//	else
	//		return mid;
	//}
	for (DWORD i = 0; i < count; i++)
	{
		API_SET_NAMESPACE_ENTRY* cur_struct = (e_p + i);
		int cmp_res = wstr_cmp_for_api((wchar_t*)(base + cur_struct->NameOffset), cur_struct->HashedLength / 2, cur_name, cur_name_size);
		if (cmp_res == 0)
		{
			//if (cur_struct->HashedLength < cur_struct->NameLength)
			//{

			//}
			//else
			return cur_struct;
		}

	}
	return ERROR;
}




static int api_part(wchar_t* name, DWORD* name_size, ps* old_wname_ps)
{
	if (wstr_cmp(name, 4, L"api-", 4) != 0 && wstr_cmp(name, 4, L"ext-", 4) != 0)
	{
		return 1;
	}

	API_SET_NAMESPACE* head = (API_SET_NAMESPACE*)(*(QWORD*)((char*)__readgsqword(0x60) + 0x68));
	char* base = (char*)head;
	if (head->Version != 6)
		return ERROR;
	if (head->EntryOffset > head->Size)
		return ERROR;

	API_SET_NAMESPACE_ENTRY* name_entry_p = api_bin_search((API_SET_NAMESPACE_ENTRY*)(base + head->EntryOffset), head->Count, base, head->Size, name, *name_size);

	if (!name_entry_p)
	{
		DWORD ind = wstr_rsearch(name, *name_size, L'.');
		if (ind != (DWORD)-1)
		{
			name[ind] = L'\0';
			*name_size = ind;

			name_entry_p = api_bin_search((API_SET_NAMESPACE_ENTRY*)(base + head->EntryOffset), head->Count, base, head->Size, name, *name_size);
			if (!name_entry_p)
				return ERROR;
		}
	}

	if (name_entry_p)
	{
		if (name_entry_p->ValueOffset + sizeof(API_SET_VALUE_ENTRY) * name_entry_p->ValueCount > head->Size)
			return ERROR;
		API_SET_VALUE_ENTRY* value_p = (API_SET_VALUE_ENTRY*)(base + name_entry_p->ValueOffset);
		DWORD cur_ind = -1;
		DWORD without_extention_len = wstr_rsearch(old_wname_ps->p, old_wname_ps->size, L'.');
		if (without_extention_len == (DWORD)-1)
			without_extention_len = old_wname_ps->size;

		for (DWORD i = 0; i < name_entry_p->ValueCount; i++)
		{

			if ((value_p + i)->NameOffset != 0 && (value_p + i)->NameLength != 0)
			{
				wchar_t* maybe_value = base + (value_p + i)->NameOffset;
				if (maybe_value + (value_p + i)->NameLength >= base || (value_p + i)->NameOffset + (value_p + i)->NameLength <= head->Size)
				{
					if (!wstr_cmp_for_api(old_wname_ps->p, old_wname_ps->size, maybe_value, (value_p + i)->NameLength) ||
						!wstr_cmp_for_api(old_wname_ps->p, without_extention_len, maybe_value, (value_p + i)->NameLength))
					{
						cur_ind = i;
						break;
					}
				}
				
			}


			if ((value_p + i)->NameLength == 0 || i == name_entry_p->ValueCount - 1)
			{
				if (i == name_entry_p->ValueCount - 1 && (value_p + i)->NameLength != 0)
					cur_ind = 0;

				if ((value_p + i)->ValueOffset + (value_p + i)->ValueLength > head->Size)
					return ERROR;

				/*wstr_copy(name, wname_size_const, (wchar_t*)(base + (value_p + i)->ValueOffset), (value_p + i)->ValueLength / 2);
				*name_size = (value_p + i)->ValueLength / 2;
				return 1;*/
				cur_ind = i;
			}
		}

		if (cur_ind != (DWORD)-1)
		{
			wstr_copy(name, wname_size_const, (wchar_t*)(base + (value_p + cur_ind)->ValueOffset), (value_p + cur_ind)->ValueLength / 2);
			*name_size = (value_p + cur_ind)->ValueLength / 2;
			return 1;
		}

	}
	return ERROR;
}



static int path_resolver(wchar_t* wbuf, char* name, FUNCS* s_funcs, ps* ps_s, DWORD dot_flag, wchar_t* target_dir, ps* ps_leg_name_struct, ps* wname)
{
	wchar_t old_wname[wname_size_const];
	DWORD old_wname_len = wstr_len(old_wname, wname_size_const);
	if (old_wname_len == (DWORD)-1)
		return ERROR;
	ps old_wname_ps = { old_wname, old_wname_len };

	wstr_copy(old_wname, wname_size_const, wname->p, wname->size);
	my_zero_fill((BYTE*)wname->p, wname_size_const * 2);
	DWORD wname_len = str_to_wstr(name, wname_size_const, wname->p, wname_size_const);
	if (wname_len == (DWORD)-1)
		return ERROR;

	if (dot_flag != (DWORD)-1)
	{
		wname->p[dot_flag] = L'\0';
	}
	wstr_copy(ps_leg_name_struct->p, ps_leg_name_struct->size, wname->p, (QWORD)wname_len + 1);
	ps_leg_name_struct->size = (QWORD)wname_len + 1;

	if (!api_part(wname->p, &wname_len, &old_wname_ps))
		return ERROR;

	DWORD ind_dot = wstr_rsearch(wname->p, wname_len, L'.');
	if (ind_dot == -1)
	{
		wname_len += 4;
		if (!wstr_cat(wname->p, L".dll", wname_size_const, 4, 0))
			return ERROR;
	}





	DWORD length = s_funcs->_GetSystemDirectoryW(wbuf, PATH_BUF_SIZE / 2);
	if (length > PATH_BUF_SIZE / 2)
		return ERROR;
	if (length)
	{
		if (!wstr_cat(wbuf, L"\\", PATH_BUF_SIZE / 2, 1, length))
			return ERROR;
		if (!wstr_cat(wbuf, wname->p, PATH_BUF_SIZE / 2, wname_len, length + 1))
			return ERROR;

		void* handle = s_funcs->_CreateFileW(wbuf, 0x80000000, 0x1, 0, 3, 128, 0);
		if (handle != (void*)-1)
		{
			s_funcs->_CloseHandle(handle);
			length = wstr_len(wbuf, PATH_BUF_SIZE / 2);
			return length;
		}
	}

	length = s_funcs->_GetWindowsDirectoryW(wbuf, PATH_BUF_SIZE / 2);
	if (length > PATH_BUF_SIZE / 2)
		return ERROR;
	if (length)
	{
		if (!wstr_cat(wbuf, L"\\", PATH_BUF_SIZE / 2, 1, length))
			return ERROR;
		if (!wstr_cat(wbuf, wname->p, PATH_BUF_SIZE / 2, wname_len, length + 1))
			return ERROR;

		void* handle = s_funcs->_CreateFileW(wbuf, 0x80000000, 0x1, 0, 3, 128, 0);
		if (handle != (void*)-1)
		{
			s_funcs->_CloseHandle(handle);
			length = wstr_len(wbuf, PATH_BUF_SIZE / 2);
			return length;
		}
	}

	wstr_copy(wbuf, PATH_BUF_SIZE, target_dir, PATH_BUF_SIZE);
	length = wstr_len(wbuf, PATH_BUF_SIZE / 2);
	if (length)
	{
		if (!wstr_cat(wbuf, L"\\", PATH_BUF_SIZE / 2, 1, length))
			return ERROR;
		if (!wstr_cat(wbuf, wname->p, PATH_BUF_SIZE / 2, wname_len, length + 1))
			return ERROR;

		void* handle = s_funcs->_CreateFileW(wbuf, 0x80000000, 0x1, 0, 3, 128, 0);
		if (handle != (void*)-1)
		{
			s_funcs->_CloseHandle(handle);
			length = wstr_len(wbuf, PATH_BUF_SIZE / 2);
			return length;
		}
	}



	length = s_funcs->_GetModuleFileNameW(0, wbuf, PATH_BUF_SIZE / 2);
	DWORD ind = wstr_rsearch(wbuf, PATH_BUF_SIZE / 2, L'\\');
	if (ind == (DWORD)-1)
		return ERROR;
	wbuf[ind] = L'\0';
	length = wstr_len(wbuf, PATH_BUF_SIZE / 2);
	if (length > PATH_BUF_SIZE / 2)
		return ERROR;
	if (length)
	{
		if (!wstr_cat(wbuf, L"\\", PATH_BUF_SIZE / 2, 1, length))
			return ERROR;
		if (!wstr_cat(wbuf, wname->p, PATH_BUF_SIZE / 2, wname_len, length + 1))
			return ERROR;

		void* handle = s_funcs->_CreateFileW(wbuf, 0x80000000, 0x1, 0, 3, 128, 0);
		if (handle != (void*)-1)
		{
			s_funcs->_CloseHandle(handle);
			length = wstr_len(wbuf, PATH_BUF_SIZE / 2);
			return length;
		}
	}

	wchar_t* first = ps_s->p;
	wchar_t* last = ps_s->p;
	QWORD counter = 0;
	while (counter < ps_s->size)
	{
		if (*last == 0x3b || *last == 0x0000)
		{
			wstr_copy(wbuf, PATH_BUF_SIZE / 2, first, last - first);
			if (length == (DWORD)-1)
				return ERROR;
			if (!wstr_cat(wbuf, L"\\", PATH_BUF_SIZE / 2, 1, last - first))
				return ERROR;
			if (!wstr_cat(wbuf, wname->p, PATH_BUF_SIZE / 2, wname_len, last - first + 1))
				return ERROR;

			void* handle = s_funcs->_CreateFileW(wbuf, 0x80000000, 0x1, 0, 3, 128, 0);
			if (handle != (void*)-1)
			{
				s_funcs->_CloseHandle(handle);
				length = wstr_len(wbuf, PATH_BUF_SIZE / 2);
				return length;
			}
			first = last + 1;
			if (*last == 0x0000)
				break;
		}
		last++;
		counter++;
	}

	return ERROR;
}


static void* get_from_lib_export(QWORD hash_lib, QWORD hash_func, long long ord, int depth,
	wchar_t* wbuf, char* name_lib,
	FUNCS* s_funcs, ps* ps_s, int dot_flag, wchar_t* target_dir, QWORD main_heap_size, DWORD main_depth, wchar_t* leg_str_p, ps_full* where_i_am, ps* wname_ps, thread_variables* t_v)
{
	if (depth >= 130) return ERROR;
	LIST_ENTRY* lib_of_libs = get_list_p();
	unsigned char* p_lib = 0;
	DWORD libImageSize = 0;

	if (wname_ps != 0 && wname_ps->p == 0)
	{
		if (where_i_am->cur_size > wname_ps->size)
			return ERROR;
		wstr_copy(wname_ps->p, wname_ps->size, where_i_am->cur_p, where_i_am->cur_size);
	}


	get_dll_base(lib_of_libs, hash_lib, &p_lib, &libImageSize);
	if (p_lib == ERROR || libImageSize == ERROR)
	{
		DWORD temp_lib_name_len = str_len(name_lib, 256);

		wchar_t* new_leg_name_func = (wchar_t*)s_funcs->_HeapAlloc(*(void**)((char*)__readgsqword(0x60) + 0x30), 0x08, (QWORD)temp_lib_name_len * 2 + 2);
		ps ps_leg_name_struct = { new_leg_name_func, (QWORD)temp_lib_name_len + 1 };
		//wname = (wchar_t*)s_funcs->_HeapAlloc(*(void**)((char*)__readgsqword(0x60) + 0x30), 0x08, wname_size_const * 2);

		DWORD wbuf_size = path_resolver(wbuf, name_lib, s_funcs, ps_s, dot_flag, target_dir, &ps_leg_name_struct, wname_ps);

		if (!name_lib || !wbuf || !wbuf_size)
			return ERROR;

		get_dll_base_by_path(lib_of_libs, wbuf, &p_lib, &libImageSize, wbuf_size);
		if (p_lib == ERROR || libImageSize == ERROR)
		{
			if (!not_Entry(s_funcs, wbuf, ps_s, main_heap_size, main_depth + 1, &ps_leg_name_struct, t_v))
				return ERROR;

			get_dll_base_by_name(lib_of_libs, ps_leg_name_struct.p, &p_lib, &libImageSize, ps_leg_name_struct.size - 1);
			if (p_lib == ERROR || libImageSize == ERROR)
				return ERROR;
		}
	}
	else if (wname_ps != 0 && name_lib && dot_flag != -1 && wname_ps->p)
	{
		int size = str_to_wstr(name_lib, wname_size_const, wname_ps->p, wname_ps->size);
		wname_ps->p[dot_flag] = L'\0';
		
	}

	IMAGE_DOS_HEADER* p_dos = (IMAGE_DOS_HEADER*)p_lib;
	IMAGE_NT_HEADERS* p_nt = 0;
	IMAGE_DATA_DIRECTORY* p_data = 0;
	IMAGE_EXPORT_DIRECTORY* p_exp = 0;

	if (!init_nt_exp_data(p_dos, libImageSize, &p_nt, &p_data, &p_exp))
	{
		return ERROR;
	}

	DWORD   NumberOfFunctions = p_exp->NumberOfFunctions;
	DWORD   NumberOfNames = p_exp->NumberOfNames;

	DWORD* AddressOfFunctions = (DWORD*)(p_lib + p_exp->AddressOfFunctions);
	DWORD* AddressOfNames = (DWORD*)(p_lib + p_exp->AddressOfNames);
	WORD* AddressOfNameOrdinals = (WORD*)(p_lib + p_exp->AddressOfNameOrdinals);
	if (p_exp->AddressOfFunctions + NumberOfFunctions * sizeof(DWORD) > libImageSize ||
		p_exp->AddressOfNames + NumberOfNames * sizeof(DWORD) > libImageSize ||
		p_exp->AddressOfNameOrdinals + NumberOfNames * sizeof(WORD) > libImageSize)
	{
		return ERROR;
	}

	if (ord == -1)
	{
		int flag = -1;
		for (DWORD i = 0; i < NumberOfNames; i++)
		{
			if (!check_str(p_lib + AddressOfNames[i], libImageSize, p_lib))
				return ERROR;

			if (hash_func == hash_func_char(p_lib + AddressOfNames[i], libImageSize, AddressOfNames[i], 256))
			{
				flag = i;
				break;
			}
		}
		if (flag == -1)
		{
			return ERROR;
		}
		ord = (long long)AddressOfNameOrdinals[flag] + p_exp->Base;
	}
	ord -= p_exp->Base;
	if (ord >= NumberOfFunctions || ord < 0)
	{
		return ERROR;
	}
	void* res = p_lib + AddressOfFunctions[ord];

	if ((QWORD)res - (QWORD)p_lib > libImageSize)
	{
		return ERROR;
	}

	if ((QWORD)res >= (QWORD)p_exp && (QWORD)res < (QWORD)p_exp + p_data->Size)
	{
		char* p_str = (char*)res;
		if (!check_str(p_str, libImageSize, p_lib))
		{
			return ERROR;
		}
		int ind = str_rsearch(p_str, '.');
		if (ind == -1 || ind == 0)
			return ERROR;

		QWORD hash_lib_new = hash_func_char(p_str, libImageSize, (QWORD)p_str - (QWORD)p_dos, ind);
		if (p_str[ind + 1] == '#')
		{
			long long ord_new = str_to_num(p_str + ind + 1);
			if (ord_new < 0) return ERROR;
			return get_from_lib_export(hash_lib_new, 0, ord_new, depth + 1, wbuf, p_str, s_funcs, ps_s, ind, target_dir, main_heap_size, main_depth, leg_str_p, where_i_am, wname_ps, t_v);
		}

		QWORD hash_func_new = hash_func_char(p_str + ind + 1, libImageSize, (QWORD)(p_str + ind + 1) - (QWORD)p_dos, 256);
		return get_from_lib_export(hash_lib_new, hash_func_new, -1, depth + 1, wbuf, p_str, s_funcs, ps_s, ind, target_dir, main_heap_size, main_depth, leg_str_p, where_i_am, wname_ps, t_v);

	}

	return res;
}

static void* load(unsigned char* raw_data, size_t raw_size, f_VirtualAlloc _VirtualAlloc,
	IMAGE_DOS_HEADER* raw_dos, IMAGE_NT_HEADERS* raw_nt, QWORD raw_base, size_t v_size, size_t headers_size, IMAGE_SECTION_HEADER* raw_sect)
{
	void* v_base = _VirtualAlloc(0, v_size, 0x3000, 0x4);
	my_memcpy((BYTE*)v_base, (BYTE*)raw_data, headers_size);


	for (int i = 0; i < raw_nt->FileHeader.NumberOfSections; i++)
	{
		DWORD vaddr = raw_sect[i].VirtualAddress;
		DWORD psize = raw_sect[i].SizeOfRawData;
		DWORD vsize = raw_sect[i].Misc.VirtualSize;
		if ((size_t)(raw_sect[i].PointerToRawData) + psize > raw_size)
			return ERROR;

		if (vsize == 0) vsize = psize;

		if (vsize == 0) continue;
		if ((QWORD)vaddr + vsize > v_size)
			return ERROR;

		my_memcpy((BYTE*)v_base + vaddr, (BYTE*)raw_data + raw_sect[i].PointerToRawData, psize);
	}
	return v_base;
}

static DWORD convert_rva_to_raw(DWORD rva, IMAGE_NT_HEADERS* nt, IMAGE_SECTION_HEADER* sect, DWORD raw_size, DWORD check_size)
{

	for (WORD i = 0; i < nt->FileHeader.NumberOfSections; i++)
	{
		DWORD cur_start = sect[i].VirtualAddress;
		DWORD cur_size = sect[i].Misc.VirtualSize;
		if (cur_start <= rva && cur_start + cur_size > rva)
		{
			if (sect[i].SizeOfRawData > (rva - cur_start))
			{
				DWORD res = sect[i].PointerToRawData + (rva - cur_start);
				if (res < sect[i].PointerToRawData)
					return ERROR;

				if (res + check_size > raw_size)
					return ERROR;

				return res;
			}
		}
	}
	return ERROR;
}

static int relocation(BYTE* v_data, BYTE* raw_data, DWORD raw_size, IMAGE_NT_HEADERS* raw_nt, IMAGE_SECTION_HEADER* raw_sect, QWORD raw_base, size_t v_size, size_t headers_size)
{
	IMAGE_DATA_DIRECTORY* raw_data_dir = raw_nt->OptionalHeader.DataDirectory + 5;
	if (raw_data_dir->Size == 0)
		return 1;
	size_t total_size = raw_data_dir->Size;
	size_t spent_size = 0;
	IMAGE_BASE_RELOCATION* raw_reloc = (IMAGE_BASE_RELOCATION*)(raw_data + convert_rva_to_raw(raw_data_dir->VirtualAddress, raw_nt, raw_sect, raw_size, sizeof(IMAGE_BASE_RELOCATION)));
	if ((QWORD)raw_reloc == raw_base)
		return ERROR;

	QWORD delta = (QWORD)v_data - raw_nt->OptionalHeader.ImageBase;

	while (total_size >= spent_size + raw_reloc->SizeOfBlock && raw_reloc->VirtualAddress != 0 && raw_reloc->SizeOfBlock != 0)
	{
		if (raw_reloc->SizeOfBlock < sizeof(IMAGE_BASE_RELOCATION) || (QWORD)raw_reloc - raw_base + raw_reloc->SizeOfBlock > raw_size)
			return ERROR;

		DWORD page_rva = raw_reloc->VirtualAddress;
		DWORD block_size = raw_reloc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION);

		WORD* p = (WORD*)((char*)raw_reloc + sizeof(IMAGE_BASE_RELOCATION));
		for (DWORD i = 0; i < block_size / sizeof(WORD); i++)
		{
			if ((QWORD)(p + i) - raw_base > raw_size)
				return ERROR;

			if (p[i] >> 12 == 0xa)
			{
				WORD inpage_rva = p[i] & 0x0fff;
				if (page_rva + inpage_rva + sizeof(QWORD) < page_rva)
					return ERROR;
				if (page_rva + inpage_rva + sizeof(QWORD) > v_size)
					return ERROR;
				if ((QWORD)v_data + page_rva + inpage_rva < (QWORD)v_data)
					return ERROR;

				QWORD* addr_of_addr = (QWORD*)(v_data + page_rva + inpage_rva);
				QWORD new_addr = (QWORD)v_data + (*addr_of_addr - raw_nt->OptionalHeader.ImageBase);
				if (new_addr - (QWORD)v_data > v_size)
					return ERROR;

				*addr_of_addr = new_addr;
			}
		}
		spent_size += raw_reloc->SizeOfBlock;
		raw_reloc = (IMAGE_BASE_RELOCATION*)((char*)raw_reloc + raw_reloc->SizeOfBlock);
	}

	return 1;
}


static int import(BYTE* v_data, BYTE* raw_data, DWORD raw_size,
	IMAGE_NT_HEADERS* raw_nt, IMAGE_SECTION_HEADER* raw_sect, QWORD raw_base, size_t v_size,
	size_t headers_size, IMAGE_DOS_HEADER* pDos, wchar_t* wbuf, char* name_lib,
	FUNCS* s_funcs, ps* ps_s, wchar_t* target_dir, QWORD main_heap_size, DWORD main_depth, wchar_t* leg_str_p, ps_full* where_i_am, thread_variables* t_v)
{
	IMAGE_DATA_DIRECTORY* raw_data_dir = raw_nt->OptionalHeader.DataDirectory + 1;
	if (raw_data_dir->Size == 0 || raw_data_dir->VirtualAddress == 0)
		return 1;
	size_t dir_size = raw_data_dir->Size;
	if (raw_data_dir->VirtualAddress + sizeof(IMAGE_IMPORT_DESCRIPTOR*) > v_size || raw_data_dir->VirtualAddress < headers_size)
		return ERROR;

	IMAGE_IMPORT_DESCRIPTOR* raw_imp = (IMAGE_IMPORT_DESCRIPTOR*)(raw_data + convert_rva_to_raw(raw_data_dir->VirtualAddress, raw_nt, raw_sect, raw_size, sizeof(IMAGE_IMPORT_DESCRIPTOR)));
	if ((QWORD)raw_imp == raw_base)
		return ERROR;

	while ((QWORD)raw_imp - raw_base + sizeof(IMAGE_IMPORT_DESCRIPTOR) <= raw_size && raw_imp->Name != 0)
	{

		if (raw_imp->FirstThunk < headers_size || raw_imp->FirstThunk + sizeof(IMAGE_THUNK_DATA64) > v_size)
		{
			//return ERROR;
			raw_imp++;
			continue;
		}
		if (raw_imp->OriginalFirstThunk < headers_size || raw_imp->OriginalFirstThunk + sizeof(IMAGE_THUNK_DATA64) > v_size)
		{
			//return ERROR;
			raw_imp++;
			continue;
		}
		if (raw_imp->Name > v_size)
		{
			//return ERROR;
			raw_imp++;
			continue;
		}

		IMAGE_THUNK_DATA64* v_ft = (IMAGE_THUNK_DATA64*)((QWORD)v_data + raw_imp->FirstThunk);
		IMAGE_THUNK_DATA64* raw_oft;
		if (raw_imp->OriginalFirstThunk != 0)
			raw_oft = (IMAGE_THUNK_DATA64*)(raw_base + convert_rva_to_raw(raw_imp->OriginalFirstThunk, raw_nt, raw_sect, raw_size, sizeof(IMAGE_THUNK_DATA64)));
		else if (raw_imp->FirstThunk != 0)
			raw_oft = (IMAGE_THUNK_DATA64*)(raw_base + convert_rva_to_raw(raw_imp->FirstThunk, raw_nt, raw_sect, raw_size, sizeof(IMAGE_THUNK_DATA64)));
		else
		{
			//return ERROR;
			raw_imp++;
			continue;
		}

		if ((QWORD)raw_oft == raw_base)
		{
			//return ERROR;
			raw_imp++;
			continue;
		}

		if (raw_oft->u1.AddressOfData == 0)
		{
			//return ERROR;
			raw_imp++;
			continue;
		}


		char* name = (char*)(raw_base + convert_rva_to_raw(raw_imp->Name, raw_nt, raw_sect, raw_size, 0));
		if (!check_str(name, raw_size, (unsigned char*)raw_data))
		{
			//return ERROR;
			raw_imp++;
			continue;
		}

		QWORD lib_hash = hash_func_char(name, raw_size, pDos, 256);
		QWORD mask1 = 0x8000000000000000;
		QWORD mask2 = 0x7fffffffffffffff;

		while ((QWORD)raw_oft - raw_base + sizeof(IMAGE_THUNK_DATA64) <= raw_size &&
			raw_oft->u1.AddressOfData != 0 && (QWORD)v_ft - (QWORD)v_data + sizeof(IMAGE_THUNK_DATA64) <= v_size)
		{
			void* func_addr = ERROR;
			if (raw_oft->u1.Ordinal & mask1)
			{
				long long ord = raw_oft->u1.Ordinal & mask2;
				wchar_t* wname = (wchar_t*)s_funcs->_HeapAlloc(*(void**)((char*)__readgsqword(0x60) + 0x30), 0x08, wname_size_const * 2);
				ps wname_ps = { wname, wname_size_const };
				func_addr = get_from_lib_export(lib_hash, 0, ord, 0, wbuf, name, s_funcs, ps_s, (DWORD)-1, target_dir, main_heap_size, main_depth, leg_str_p, where_i_am, &wname_ps, t_v);
				if (!s_funcs->_HeapFree(*(void**)((char*)__readgsqword(0x60) + 0x30), 0, (void*)wname))
					return ERROR;
			}
			else
			{
				QWORD name_func_rva = raw_oft->u1.ForwarderString;
				name_func_rva = convert_rva_to_raw(name_func_rva, raw_nt, raw_sect, raw_size, sizeof(WORD) + 1);
				if (name_func_rva == 0)
				{
					//return ERROR;
					v_ft++;
					raw_oft++;
					continue;
				}

				IMAGE_IMPORT_BY_NAME* name_func = (IMAGE_IMPORT_BY_NAME*)(raw_base + name_func_rva);
				if ((QWORD)name_func == raw_base)
				{
					//return ERROR;
					v_ft++;
					raw_oft++;
					continue;
				}
				if (!check_str(name_func->Name, raw_size, (unsigned char*)raw_base))
				{
					//return ERROR;
					v_ft++;
					raw_oft++;
					continue;
				}
				QWORD func_hash = hash_func_char(name_func->Name, raw_size, pDos, 256);
				wchar_t* wname = (wchar_t*)s_funcs->_HeapAlloc(*(void**)((char*)__readgsqword(0x60) + 0x30), 0x08, wname_size_const * 2);
				ps wname_ps = { wname, wname_size_const };
				func_addr = get_from_lib_export(lib_hash, func_hash, -1, 0, wbuf, name, s_funcs, ps_s, (DWORD)-1, target_dir, main_heap_size, main_depth, leg_str_p, where_i_am, &wname_ps, t_v);
				if (!s_funcs->_HeapFree(*(void**)((char*)__readgsqword(0x60) + 0x30), 0, (void*)wname))
					return ERROR;
			}
			if (!func_addr)
			{
				return ERROR;
				v_ft++;
				raw_oft++;
				continue;
			}

			v_ft->u1.Function = (QWORD)func_addr;
			v_ft++;
			raw_oft++;
		}
		raw_imp++;
	}
	return 1;
}


static int exception(BYTE* v_data, BYTE* raw_data, DWORD raw_size, IMAGE_NT_HEADERS* raw_nt, size_t v_size, f_RtlAddFunctionTable _RtlAddFunctionTable)
{
	IMAGE_DATA_DIRECTORY* raw_data_dir = raw_nt->OptionalHeader.DataDirectory + 3;
	if (raw_data_dir->Size == 0 || raw_data_dir->VirtualAddress == 0)
		return 1;

	if ((size_t)raw_data_dir->VirtualAddress + raw_data_dir->Size > v_size)
		return ERROR;

	if (raw_data_dir->Size % 12 != 0)
		return ERROR;
	if (!_RtlAddFunctionTable((RUNTIME_FUNCTION*)(v_data + raw_data_dir->VirtualAddress), raw_data_dir->Size / sizeof(RUNTIME_FUNCTION), (QWORD)v_data))
		return ERROR;
	return 1;
}

static int tls(BYTE* v_data, size_t v_size, FUNCS* s_funcs, QWORD raw_opbase, QWORD raw_size, thread_variables* t_v) 
{
	int skip_flag = 0;
	QWORD v_base = (QWORD)v_data;
	IMAGE_DOS_HEADER* v_dos = (IMAGE_DOS_HEADER*)v_data;
	if ((QWORD)v_dos - v_base + sizeof(IMAGE_DOS_HEADER) > v_size)
		return ERROR;
	if (v_dos->e_magic != 0x5a4d)
		return ERROR;
	if (v_dos->e_lfanew + sizeof(IMAGE_NT_HEADERS) > v_size)
		return ERROR;
	IMAGE_NT_HEADERS* v_nt = (IMAGE_NT_HEADERS*)((BYTE*)v_data + v_dos->e_lfanew);
	if ((QWORD)v_nt - v_base + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) > v_size)
		return ERROR;
	if (v_nt->Signature != 0x4550)
		return ERROR;
	if ((QWORD)v_nt - v_base + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + v_nt->FileHeader.SizeOfOptionalHeader > v_size)
		return ERROR;
	size_t headers_size = v_nt->OptionalHeader.SizeOfHeaders;
	if (headers_size >= v_size)
		return ERROR;
	IMAGE_SECTION_HEADER* v_sect = (IMAGE_SECTION_HEADER*)((char*)&v_nt->FileHeader + sizeof(IMAGE_FILE_HEADER) + v_nt->FileHeader.SizeOfOptionalHeader);
	if ((QWORD)v_sect - v_base + sizeof(IMAGE_SECTION_HEADER) * v_nt->FileHeader.NumberOfSections > v_size)
		return ERROR;
	IMAGE_DATA_DIRECTORY* v_data_dir = v_nt->OptionalHeader.DataDirectory + 9;
	void* heap_addr_main = *(void**)((char*)__readgsqword(0x60) + 0x30);
	if (v_data_dir->Size == 0 || v_data_dir->VirtualAddress == 0)
	{
		skip_flag = 1;
		goto tls_teleport;
	}

	if ((size_t)v_data_dir->VirtualAddress + v_data_dir->Size > v_size)
		return ERROR;

	



	DWORD tls_ind = -1;
	int bitmap_flag = 0;
	for (int i = *(t_v->number_of_bits) / 8 - 1; i >= 0; i--)
	{
		BYTE mask = 0x00000001;
		for (WORD u = 0; u < 8; u++)
		{
			if ((*(((BYTE*)*(t_v->buf_address)) + i) & (mask << u)) == 0)
			{
				DWORD state = 0;
				ULONGLONG cookie = 0;
				if (s_funcs->_LdrLockLoaderLock(0, &state, &cookie) != 0)
					return ERROR;
				if (state != 1 && state != 3)
					return ERROR;

				*(((BYTE*)*(t_v->buf_address)) + i) |= mask << u;

				if (s_funcs->_LdrUnlockLoaderLock(0, cookie) != 0)
					return ERROR;

				tls_ind = i * 8 + u;//little endian!
				bitmap_flag = 1;
				break;
			}
		}
		if (bitmap_flag)
			break;
	}

	//DWORD tls_ind = s_funcs->_TlsAlloc();
	if (tls_ind == (DWORD)-1)
		return ERROR;

	if (v_data_dir->VirtualAddress + sizeof(IMAGE_TLS_DIRECTORY64) > v_size)
		return ERROR;
	IMAGE_TLS_DIRECTORY64* v_tls = (IMAGE_TLS_DIRECTORY64*)(v_base + v_data_dir->VirtualAddress);

	QWORD arr_addr[4] = { v_tls->StartAddressOfRawData, v_tls->EndAddressOfRawData, v_tls->AddressOfIndex, v_tls->AddressOfCallbacks };
	for (int i = 0; i < 4; i++)
	{
		QWORD addrofind = arr_addr[i];
		if (arr_addr[i] >= v_base && arr_addr[i] < v_base + v_size)
			continue;
		else if (arr_addr[i] >= raw_opbase && arr_addr[i] < raw_opbase + raw_size)
			addrofind = addrofind - raw_opbase + v_base;
		else
			return ERROR;

		if (arr_addr[i] - v_base + sizeof(QWORD) > v_size)
			return ERROR;
		arr_addr[i] = addrofind;
	}

	*(DWORD*)(arr_addr[2]) = tls_ind;

	if (arr_addr[1] < arr_addr[0])
		return ERROR;

	QWORD tls_data_size = arr_addr[1] - arr_addr[0];
	if (arr_addr[0] - v_base + tls_data_size > v_size)
		return ERROR;



	if (tls_data_size + v_tls->SizeOfZeroFill < tls_data_size)
		return ERROR;

	void* heap_addr = s_funcs->_HeapAlloc(heap_addr_main, 0x08, tls_data_size + v_tls->SizeOfZeroFill + 16);
	if (!heap_addr)
		return ERROR;
	
	*((void**)heap_addr + 1) = heap_addr;
	(void**)heap_addr += 2;

	my_memcpy((BYTE*)heap_addr, (BYTE*)arr_addr[0], tls_data_size);

	void** tls_arr = (void**)__readgsqword(0x58);
	if (!tls_arr)
		return ERROR;
	tls_arr[tls_ind] = heap_addr;

	if (myTLScounter == MAX_TLS_LEN)
		return 0;
	myTLSlist[myTLScounter].TlsIndex = tls_ind;
	myTLSlist[myTLScounter].CurDataStart = arr_addr[0];
	myTLSlist[myTLScounter].data_size = tls_data_size;
	myTLSlist[myTLScounter].zero_size = v_tls->SizeOfZeroFill;
	myTLScounter++;


tls_teleport:
	size_t arr_size = (v_size + 0xFFF) / 0x1000;
	DWORD* pages_arr = (DWORD*)(s_funcs->_HeapAlloc(heap_addr_main, 0x08, arr_size * sizeof(DWORD)));
	if (!pages_arr)
		return ERROR;
	DWORD number_of_headers_pages = (v_nt->OptionalHeader.SizeOfHeaders + 0xFFF) / 0x1000;
	for (DWORD i = 0; i < number_of_headers_pages; i++)
		pages_arr[i] |= 0x4;

	for (WORD i = 0; i < v_nt->FileHeader.NumberOfSections; i++)
	{
		if ((QWORD)(&v_sect[i]) - v_base + sizeof(IMAGE_SECTION_HEADER) > v_size)
			return ERROR;

		if ((QWORD)v_sect[i].VirtualAddress + v_sect[i].Misc.VirtualSize > v_size)
			return ERROR;

		DWORD val = v_sect[i].Characteristics >> 28;

		QWORD start = v_sect[i].VirtualAddress / 0x1000;
		QWORD end = ((QWORD)v_sect[i].VirtualAddress + v_sect[i].Misc.VirtualSize + 0xFFF) / 0x1000;
		for (QWORD u = start; u < end; u++)
		{
			if (u >= arr_size)
				return ERROR;
			pages_arr[u] |= val;
		}
	}

	for (size_t i = 0; i < arr_size; i++)
	{
		DWORD val = pages_arr[i];
		switch (val)
		{
		case 0:
			val = 0x01;
			break;
		case 0x4:
			val = 0x02;
			break;
		case 0xC:
			val = 0x04;
			break;
		case 0x2:
			val = 0x10;
			break;
		case 0x6:
			val = 0x20;
			break;
		case 0xE:
			val = 0x40;
			break;
		case 0xA:
			val = 0x40;
			break;
		default:
			return ERROR;
		}
		DWORD old_flag = 0;
		if (!s_funcs->_VirtualProtect((void*)(v_base + i * 0x1000), 0x1000, val, &old_flag))
			return ERROR;
	}
	if (!s_funcs->_HeapFree(heap_addr_main, 0, pages_arr))
		return ERROR;



	if (!skip_flag)
	{
		QWORD* f_cb = (QWORD*)(arr_addr[3]);
		if (f_cb != 0)
		{
			if ((QWORD)f_cb - v_base + sizeof(QWORD) > v_size)
				return ERROR;
			while (*f_cb != 0)
			{
				f_TLS_CALLBACK func = (f_TLS_CALLBACK)*f_cb;
				if ((QWORD)*f_cb - v_base + 1 > v_size)
					return ERROR;
				func((void*)v_base, 1, 0);
				f_cb++;
				if ((QWORD)f_cb - v_base + sizeof(QWORD) > v_size)
					return ERROR;
			}
		}
	}
	return 1;
}

static int list_legalization(BYTE* v_data, size_t v_size, f_LdrLockLoaderLock _LdrLockLoaderLock, f_LdrUnlockLoaderLock _LdrUnlockLoaderLock, UNICODE_STRING* name, UNICODE_STRING* full_name, f_HeapAlloc _HeapAlloc)
{
	QWORD v_base = (QWORD)v_data;
	IMAGE_DOS_HEADER* v_dos = (IMAGE_DOS_HEADER*)v_data;
	if ((QWORD)v_dos - v_base + sizeof(IMAGE_DOS_HEADER) > v_size)
		return ERROR;
	if (v_dos->e_magic != 0x5a4d)
		return ERROR;
	if (v_dos->e_lfanew + sizeof(IMAGE_NT_HEADERS) > v_size)
		return ERROR;
	IMAGE_NT_HEADERS* v_nt = (IMAGE_NT_HEADERS*)((BYTE*)v_data + v_dos->e_lfanew);
	if ((QWORD)v_nt - v_base + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) > v_size)
		return ERROR;
	if (v_nt->Signature != 0x4550)
		return ERROR;
	if ((QWORD)v_nt - v_base + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + v_nt->FileHeader.SizeOfOptionalHeader > v_size)
		return ERROR;

	PEB* peb = (PEB*)__readgsqword(0x60);
	PEB_LDR_DATA* ldr = (PEB_LDR_DATA*)(peb->Ldr);

//воруем
	LDR_DATA_TABLE_ENTRY* main_entry = (LDR_DATA_TABLE_ENTRY*)ldr->InLoadOrderModuleList.Flink;

	LDR_DATA_TABLE_ENTRY* segment_addr = (LDR_DATA_TABLE_ENTRY*)_HeapAlloc(*(void**)((char*)peb + 0x30), 0x8, 0x150);
	if (!segment_addr)
		return ERROR;

	DWORD state = 0;
	ULONGLONG cookie = 0;
	if (_LdrLockLoaderLock(0, &state, &cookie) != 0)
		return ERROR;
	if (state != 1 && state != 3)
		return ERROR;
	//вставляем
	for (int i = 0; i < 0x150; i++) {
		((BYTE*)segment_addr)[i] = ((BYTE*)main_entry)[i];
	}

	// меняем
	segment_addr->DllBase = (void*)v_data;
	segment_addr->EntryPoint = (void*)(v_data + v_nt->OptionalHeader.AddressOfEntryPoint);
	segment_addr->SizeOfImage = (DWORD)v_size;
	segment_addr->FullDllName = *full_name;
	segment_addr->BaseDllName = *name;

	
	*(DWORD*)((char*)segment_addr + 0x68) = 0x002CA2CC;
	*(WORD*)((char*)segment_addr + 0x6C) = 0xFFFF;

	// встраиваем
	for (WORD i = 0; i < 3; i++)
	{
		int shift = 0x10 * i;

		LIST_ENTRY* head1 = (LIST_ENTRY*)((char*)ldr + 0x10 + shift);
		LIST_ENTRY* last1 = head1->Blink;
		*(LIST_ENTRY**)((char*)segment_addr + shift) = head1;
		*(LIST_ENTRY**)((char*)segment_addr + shift + 0x8) = last1;
		last1->Flink = (LIST_ENTRY*)((char*)segment_addr + shift);
		head1->Blink = (LIST_ENTRY*)((char*)segment_addr + shift);
	}

	if (_LdrUnlockLoaderLock(0, cookie) != 0)
		return ERROR;
	return 1;
}
//static int list_legalization(BYTE* v_data, size_t v_size, f_LdrLockLoaderLock _LdrLockLoaderLock, f_LdrUnlockLoaderLock _LdrUnlockLoaderLock, UNICODE_STRING* name, UNICODE_STRING* full_name, f_HeapAlloc _HeapAlloc)
//{
//	QWORD v_base = (QWORD)v_data;
//	IMAGE_DOS_HEADER* v_dos = (IMAGE_DOS_HEADER*)v_data;
//	if ((QWORD)v_dos - v_base + sizeof(IMAGE_DOS_HEADER) > v_size)
//		return ERROR;
//	if (v_dos->e_magic != 0x5a4d)
//		return ERROR;
//	if (v_dos->e_lfanew + sizeof(IMAGE_NT_HEADERS) > v_size)
//		return ERROR;
//	IMAGE_NT_HEADERS* v_nt = (IMAGE_NT_HEADERS*)((BYTE*)v_data + v_dos->e_lfanew);
//	if ((QWORD)v_nt - v_base + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) > v_size)
//		return ERROR;
//	if (v_nt->Signature != 0x4550)
//		return ERROR;
//	if ((QWORD)v_nt - v_base + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + v_nt->FileHeader.SizeOfOptionalHeader > v_size)
//		return ERROR;
//
//	PEB* peb = (PEB*)__readgsqword(0x60);
//	PEB_LDR_DATA* ldr = (PEB_LDR_DATA*)(peb->Ldr);
//	LDR_DATA_TABLE_ENTRY* segment_addr = (LDR_DATA_TABLE_ENTRY*)_HeapAlloc(*(void**)((char*)peb + 0x30), 0x8, 0x150);
//	if (!segment_addr)
//		return ERROR;
//
//	DWORD state = 0;
//	ULONGLONG cookie = 0;
//	if (_LdrLockLoaderLock(0, &state, &cookie) != 0)
//		return ERROR;
//	if (state != 1 && state != 3)
//		return ERROR;
//
//	segment_addr->DllBase = (void*)v_data;
//	segment_addr->EntryPoint = (void*)(v_data + v_nt->OptionalHeader.AddressOfEntryPoint);
//	segment_addr->SizeOfImage = (DWORD)v_size;
//	segment_addr->FullDllName = *full_name;
//	segment_addr->BaseDllName = *name;
//	*(DWORD*)((char*)segment_addr + 0x68) = 0x002CA2CC;
//	*(WORD*)((char*)segment_addr + 0x6C) = 0xFFFF;
//
//	for (WORD i = 0; i < 3; i++)
//	{
//		int shift = 0x10 * i;
//
//		LIST_ENTRY* head1 = (LIST_ENTRY*)((char*)ldr + 0x10 + shift);
//		LIST_ENTRY* last1 = head1->Blink;
//		*(LIST_ENTRY**)((char*)segment_addr + shift) = head1;
//		*(LIST_ENTRY**)((char*)segment_addr + shift + 0x8) = last1;
//		last1->Flink = (LIST_ENTRY*)((char*)segment_addr + shift);
//		head1->Blink = (LIST_ENTRY*)((char*)segment_addr + shift);
//	}
//	if (_LdrUnlockLoaderLock(0, cookie) != 0)
//		return ERROR;
//	return 1;
//}


static int lde(BYTE* addr)
{
	BYTE* start = addr;
	BYTE prefixes[] = { 0xf0, 0xf2, 0xf3, 0x2e, 0x36, 0x3e, 0x26, 0x64, 0x65, 0x66, 0x67 };//0x40-0x4f later
	DWORD opcode[8] = {
		0b00001111'00001111'00001111'00001111,
		0b00001111'00001111'00001111'00001111,
		0b00000000'00000000'00000000'00000000,
		0b00000000'00000000'00001010'00001100,
		0b00000000'00000000'11111111'11111111,
		0b00000000'00000000'00000000'00000000,
		0b11111111'00001111'00000000'11000011,
		0b11000000'11000000'00000000'00000000
	};
	DWORD has_imm8[8] = {
		0b00010000'00010000'00010000'00010000,
		0b00010000'00010000'00010000'00010000,
		0b00000000'00000000'00000000'00000000,
		0b11111111'11111111'00001100'00000000,
		0b00000000'00000000'00000000'00001101,
		0b00000000'11111111'00000001'00000000,
		0b00000000'00110000'00100001'01000011,
		0b00000000'01000000'00001000'11111111
	};
	DWORD has_imm32[8] = {
		0b00100000'00100000'00100000'00100000, 
		0b00100000'00100000'00100000'00100000, 
		0b00000000'00000000'00000000'00000000, 
		0b00000000'00000000'00000011'00000000, 
		0b00000000'00000000'00000000'00000010, 
		0b11111111'00000000'00000010'00000000, 
		0b00000000'00000000'00000000'10000000, 
		0b00000000'10000000'00000011'00000000  
	};
	int res = 0;
	BYTE prefix_count = 0;
	BYTE flag66 = 0;
	BYTE flagrexw = 0;
	BYTE another_flag = 0;
	while (prefix_count < 15)
	{
		int flag = 0;
		for (BYTE i = 0; i < 11; i++)//11 is a size of prefixes
		{
			if (*addr == prefixes[i])
			{
				if (i == 9)
					flag66 = 1;
				addr++;
				flag = 1;
				prefix_count += 1;
				break;
			}
		}
		if (*addr >= 0x40 && *addr <= 0x4f)
		{
			if (!flagrexw && *addr >= 0x48)
				flagrexw = 1;
			addr++;
			flag = 1;
			prefix_count += 1;
		}
		if (!flag)
			break;
	}
	if (prefix_count > 14)
		return ERROR;
	res = prefix_count;
	int opcode_size = 0;
	int imm = 0;
	BYTE modrm_flag = 0;
	if (*addr == 0x0f)
	{
		res++;
		addr++;
		if (*addr == 0x3a || *addr == 0x38)
		{
			if (*addr == 0x3a)
			{
				imm = 1;
			}
			res += 2;
			addr += 2;
			modrm_flag = 1;
		}
		else
		{
			modrm_flag = 1;
			if ((*addr >= 0x04 && *addr <= 0x0c) ||
				(*addr == 0x0e) ||
				(*addr >= 0x25 && *addr <= 0x27) ||
				(*addr >= 0x30 && *addr <= 0x3f) ||
				(*addr == 0x77) ||
				(*addr >= 0x7a && *addr <= 0x7b) ||
				(*addr >= 0x80 && *addr <= 0x8f) ||
				(*addr >= 0xa0 && *addr <= 0xa2) ||
				(*addr >= 0xa6 && *addr <= 0xaa) ||
				(*addr >= 0xc8 && *addr <= 0xcf))
			{
				modrm_flag = 0;
			}
			if ((*addr == 0x0f) ||
				(*addr >= 0x70 && *addr <= 0x73) ||
				(*addr == 0xa4) ||
				(*addr == 0xac) ||
				(*addr == 0xba) ||
				(*addr == 0xc2) ||
				(*addr >= 0xc4 && *addr <= 0xc6))
			{
				imm = 1;
			}
			else if (*addr >= 0x80 && *addr <= 0x8f)
			{
				if (flag66)
					imm = 2;
				else
					imm = 4;
			}
			res++;
			addr++;
		}
	}
	else
	{
		if (*addr == 0xf6 || *addr == 0xf7)
			another_flag = 1;
		if (*addr >= 0xb8 && *addr <= 0xbf)
			flagrexw += 1;
		modrm_flag = (opcode[(*addr >> 5)] & (0x00000001 << (*addr % 32))) > 0; // /32 %32
		imm = has_imm8[(*addr >> 5)] & (0x00000001 << (*addr % 32));
		if (imm)
			imm = 1;
		else
		{
			imm = has_imm32[(*addr >> 5)] & (0x00000001 << (*addr % 32));
			if (imm)
			{
				if (flag66)
					imm = 2;
				else
				{
					if (flagrexw == 2)
						imm = 8;
					else
						imm = 4;
				}
			}
				
		}
		res++;
		addr++;
	}
	if (modrm_flag)
	{
		BYTE mod = (*addr & 0b11000000) >> 6;
		BYTE reg = (*addr & 0b00111000) >> 3;
		BYTE rm = *addr & 0b00000111;
		res++;
		addr++;
		if (mod != 0b11 && rm == 0b100)
		{
			res++;
		}
		if (mod == 0 && rm == 0b100 && ((*addr & 0b111) == 0b101))
		{
			res += 4;
		}
		else if ((mod == 0 && rm == 0b101) || (mod == 0b10))
		{
			res += 4;
		}
		else if (mod == 0b01)
		{
			res += 1;
		}
		if (another_flag && reg >= 2)
			imm = 0;
	}
	start += prefix_count;
	if (*start == 0xC2 || *start == 0xCA) imm = 2;
	if (*start == 0xC8) imm = 3;
	if (*start >= 0xA0 && *start <= 0xA3) imm = 8;
	res += imm;
	return res;
}

typedef struct _FINAL
{
	BYTE* trampoline;
	f_HeapAlloc _HeapAlloc;
	void* HeapMain;
} FINAL;
FINAL final;


int Proxy(void);
BYTE* make_hook(thread_variables* t_v, FUNCS* s_funcs)
{
	int size = 0;
	BYTE jmp_code[14] = {
	0xFF, 0x25, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	};
	while (size < 14)
	{
		int temp = lde((BYTE*)t_v->goal_func + size);
		if (!temp)
			return ERROR;
		size += temp;
	}
	BYTE* trampoline = (BYTE*)(s_funcs->_VirtualAlloc(0, size + 14, 0x3000, 0x40));
	my_memcpy(trampoline, t_v->goal_func, size);
	*((QWORD*)(jmp_code + 6)) = (BYTE*)t_v->goal_func + size;
	my_memcpy(trampoline + size, jmp_code, 14);

	
	DWORD variable = 0;
	QWORD proxy_addr = (QWORD)Proxy;
	*((QWORD*)(jmp_code + 6)) = proxy_addr;
	if (!s_funcs->_VirtualProtect(t_v->goal_func, size, 0x40, &variable))
		return ERROR;
	my_memcpy(t_v->goal_func, jmp_code, 14);
	for (WORD i = 14; i < size; i++)
	{
		*((BYTE*)t_v->goal_func + i) = 0x90;
	}
	if (!s_funcs->_VirtualProtect(t_v->goal_func, size, variable, &variable))
		return ERROR;
	return trampoline;
}

int Proxy()
{
	typedef int (*f_Original)();
	int status = (((f_Original)final.trampoline)());
	if (!status)
	{
		void** vector = (void**)__readgsqword(0x58);
		if (vector != 0)
		{
			for (WORD i = 0; i < myTLScounter; i++)
			{
				void** arr = (void**)final._HeapAlloc(final.HeapMain, 0x08, myTLSlist[i].data_size + myTLSlist[i].zero_size + 16);
				if (!arr)
					return 0xc0000017;
				*(arr + 1) = (void*)arr;
				arr += 2;
				if (myTLSlist[i].data_size > 0)
				{
					my_memcpy((BYTE*)arr, myTLSlist[i].CurDataStart, myTLSlist[i].data_size);
				}
				vector[myTLSlist[i].TlsIndex] = arr;
			}
		}
	}
	return status;
}


static void scanner(thread_variables* t_v)
{
	LIST_ENTRY* list_entry = get_list_p();// ntdll - 0x807DB1E
	unsigned char* base = 0;
	DWORD size = 0;
	get_dll_base(list_entry, 0x807DB1E, &base, &size);
	if (base == 0 || size == 0)
		return;

	if (sizeof(IMAGE_DOS_HEADER) >= size || ((IMAGE_DOS_HEADER*)base)->e_magic != 0x5a4d ||
		((IMAGE_DOS_HEADER*)base)->e_lfanew + sizeof(IMAGE_NT_HEADERS) >= size)
		return;

	IMAGE_NT_HEADERS* nt = (IMAGE_NT_HEADERS*)(base + ((IMAGE_DOS_HEADER*)base)->e_lfanew);
	if (nt->Signature != 0x4550)
		return;


	size_t headers_size = nt->OptionalHeader.SizeOfHeaders;
	if (headers_size > size)
		return;
	IMAGE_SECTION_HEADER* sect = (IMAGE_SECTION_HEADER*)((char*)&nt->FileHeader + sizeof(IMAGE_FILE_HEADER) + nt->FileHeader.SizeOfOptionalHeader);
	if ((QWORD)sect - (QWORD)base + sizeof(IMAGE_SECTION_HEADER) * nt->FileHeader.NumberOfSections > size)
		return;

	BYTE* text_base = 0;
	DWORD text_size = 0;
	char* text_name = ".text";
	for (WORD i = 0; i < nt->FileHeader.NumberOfSections; i++)
	{
		int flag = 0;
		for (WORD u = 0; u < 6; u++)
		{
			//if ((sect + i)->Name)
			if (text_name[u] != ((sect + i)->Name)[u])
			{
				flag = 1;
				break;
			}
		}
		if (flag) continue;
		text_base = (sect + i)->VirtualAddress;
		text_size = (sect + i)->Misc.VirtualSize;
		break;
	}
	if (text_base == 0 || text_size == 0 || (QWORD)text_base + text_size > size)
		return;
	
	
	BYTE byte_mask1[] = {0xc7, 0x05, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
						0x48, 0x89, 0x05, 0x00, 0x00, 0x00, 0x00,
						0x48, 0xc7, 0x05, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
						0xe9, 0x00, 0x00, 0x00, 0x00};
	
	BYTE comparing_mask1[] = { 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
							  1, 1, 1, 0, 0, 0, 0,
							  1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
							  1, 0, 0, 0, 0 };
	



	BYTE byte_mask2[] = { 0x48, 0xc7, 0x44, 0x24, 0x20, 0x40, 0x39, 0xd2, 0xff,
						  0x48, 0x8d, 0x54, 0x24, 0x20,
						  0x33, 0xc9,
						  0xe8, 0xd3, 0x68, 0x15, 0x00,
					      0xe8, 0x9e, 0xfc, 0xff, 0xff };
	BYTE comparing_mask2[] = { 1, 1, 1, 1, 0, 1, 1, 1, 1,
							   1, 1, 1, 1, 0,
							   1, 1,
							   1, 0, 0, 0, 0,
							   1, 0, 0, 0, 0 };

	BYTE* p1 = byte_mask1;
	BYTE* p2 = comparing_mask1;
	DWORD byte_mask_size = sizeof(byte_mask1);
	BYTE* p_text = (BYTE*)base + (QWORD)text_base;
	for (int y = 0; y < 2; y++)
	{
		if (y == 1)
		{
			p1 = byte_mask2;
			p2 = comparing_mask2;
			byte_mask_size = sizeof(byte_mask2);
		}
		BYTE* res = 0;

		for (DWORD i = 0; i < text_size - byte_mask_size; i++)
		{
			int flag = 0;
			for (WORD u = 0; u < byte_mask_size; u++)
			{
				if (p2[u] == 0)
					continue;
				if (p1[u] != *(p_text + i + u))
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				continue;
			res = p_text + i;
			if (!y)
			{
				DWORD* v1 = (DWORD*)((long long)res + *((int*)(res + 2)) + 10);
				void* v2 = (void*)(((long long)res + 10) + *((int*)(res + 13)) + 7);
				QWORD* v3 = (QWORD*)(((long long)res + 17) + *((int*)(res + 20)) + 11);
				if ((QWORD)v1 < (QWORD)base || (QWORD)v1 - (QWORD)base > size)
					v1 = 0;
				if ((QWORD)v2 < (QWORD)base || (QWORD)v2 - (QWORD)base > size)
					v2 = 0;
				if ((QWORD)v3 < (QWORD)base || (QWORD)v3 - (QWORD)base > size)
					v3 = 0;

				t_v->number_of_bits = v1;
				t_v->buf_address = v2;
				t_v->number_of_cells = v3;
				
			}
			else
			{
				void* v4 = (void*)((long long)res + 26 + *((int*)(res + 22)));
				if ((QWORD)v4 < (QWORD)base || (QWORD)v4 - (QWORD)base > size)
					v4 = 0;
				t_v->goal_func = v4;
			}

			break;
		}
	}
}


static int preparing(FUNCS* s_funcs, thread_variables* t_v)
{
	if (*(t_v->number_of_bits) < 512)
	{
		
		void* pNewBitMap = s_funcs->_HeapAlloc(*(void**)((char*)__readgsqword(0x60) + 0x30), 0x08, 64);// 512 / 8

		void* pNewTLS_Vector = s_funcs->_HeapAlloc(*(void**)((char*)__readgsqword(0x60) + 0x30), 0x08, 4112); // 512 * 8 + 16
		*(DWORD*)pNewTLS_Vector = 512;
		(QWORD*)pNewTLS_Vector += 2;
		void** vector_p = (void**)((char*)__readgsqword(0x30) + 0x58);
		if (vector_p == 0)
		{
			return ERROR;
		}

		DWORD number_of_pointers = *(DWORD*)((char*)*(vector_p) - 0x10);
		if (number_of_pointers > 512)
			return ERROR;

		my_memcpy((BYTE*)pNewTLS_Vector, (BYTE*)(*vector_p), (QWORD)number_of_pointers * 8);
		//for (DWORD i = 0; i < number_of_pointers; i++)
		//{
		//	*((QWORD*)(pNewTLS_Vector) + i) = *((QWORD*)(*(vector_p)) + i);
		//}

		for (DWORD i = 0; i < *(t_v->number_of_bits) / 8; i++)
		{
			*((BYTE*)pNewBitMap + i) |= *((BYTE*)*(t_v->buf_address) + i);
		}

		DWORD state = 0;
		ULONGLONG cookie = 0;
		if (s_funcs->_LdrLockLoaderLock(0, &state, &cookie) != 0)
			return ERROR;
		if (state != 1 && state != 3)
			return ERROR;

		*(t_v->number_of_bits) = 512;
		*(t_v->number_of_cells) = 16;//512 / 32
		*(t_v->buf_address) = pNewBitMap;
		//if (!s_funcs->_HeapFree(*(void**)((char*)__readgsqword(0x60) + 0x30), 0, *(t_v->buf_address)))
		//	return ERROR;
		*vector_p = pNewTLS_Vector;

		if (s_funcs->_LdrUnlockLoaderLock(0, cookie) != 0)
			return ERROR;

		return 1;
	}
	else
		return ERROR;
}



	







static int not_Entry(FUNCS* s_funcs, wchar_t* wbuf, ps* ps_s, QWORD main_heap_size, DWORD main_depth, ps* leg_name_func, thread_variables* t_v)
{
	int status = ERROR;


	//if (!s_funcs->_LoadLibraryA("USER32.dll"))
	//	return ERROR;

	//void* raw_handle = _CreateFileA("C:\\Windows\\System32\\notepad.exe", 0x80000000, 0x1, 0, 3, 128, 0);
	//void* raw_handle = _CreateFileA("E:\\games\\Tor Browser\\Browser\\firefox.exe", 0x80000000, 0x1, 0, 3, 128, 0);
	void* raw_handle = s_funcs->_CreateFileW(wbuf, 0x80000000, 0x1, 0, 3, 128, 0);
	if (raw_handle == (void*)-1)
		return ERROR;

	DWORD len1 = wstr_len(wbuf, PATH_BUF_SIZE / 2);
	if (len1 == (DWORD)-1)
		return ERROR;

	main_heap_size += (QWORD)len1 * 2 + 2;
	if (main_depth > 30 || main_heap_size > PATH_BUF_SIZE * 11)
		return ERROR;

	DWORD raw_size = s_funcs->_GetFileSize(raw_handle, 0);
	if (raw_size == 0xffffffff)
		return ERROR;
	void* raw_data = s_funcs->_VirtualAlloc(0, raw_size, 0x3000, 0x04);
	if (!raw_data)
		return ERROR;
	int check_func = s_funcs->_ReadFile(raw_handle, raw_data, raw_size, &raw_size, 0);
	if (!check_func)
		return ERROR;
	/////////
	QWORD raw_base = (QWORD)raw_data;
	IMAGE_DOS_HEADER* raw_dos = (IMAGE_DOS_HEADER*)raw_data;
	if ((QWORD)raw_dos - raw_base + sizeof(IMAGE_DOS_HEADER) > raw_size)
		return ERROR;
	if (raw_dos->e_magic != 0x5a4d)
		return ERROR;
	if (raw_dos->e_lfanew + sizeof(IMAGE_NT_HEADERS) > raw_size)
		return ERROR;
	IMAGE_NT_HEADERS* raw_nt = (IMAGE_NT_HEADERS*)((BYTE*)raw_data + raw_dos->e_lfanew);
	if ((QWORD)raw_nt - raw_base + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) > raw_size)
		return ERROR;
	if (raw_nt->Signature != 0x4550)
		return ERROR;
	if ((QWORD)raw_nt - raw_base + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + raw_nt->FileHeader.SizeOfOptionalHeader > raw_size)
		return ERROR;
	if (raw_dos->e_lfanew + sizeof(IMAGE_NT_HEADERS) > raw_size)
		return ERROR;
	size_t headers_size = raw_nt->OptionalHeader.SizeOfHeaders;
	size_t v_size = raw_nt->OptionalHeader.SizeOfImage;
	if (headers_size > v_size)
		return ERROR;
	IMAGE_SECTION_HEADER* raw_sect = (IMAGE_SECTION_HEADER*)((char*)&raw_nt->FileHeader + sizeof(IMAGE_FILE_HEADER) + raw_nt->FileHeader.SizeOfOptionalHeader);
	if ((QWORD)raw_sect - raw_base + sizeof(IMAGE_SECTION_HEADER) * raw_nt->FileHeader.NumberOfSections > raw_size)
		return ERROR;
	/////////
	void* v_data = load((unsigned char*)raw_data, raw_size, s_funcs->_VirtualAlloc, raw_dos, raw_nt, raw_base, v_size, headers_size, raw_sect);
	if (!v_data)
		return ERROR;
	if (!relocation((BYTE*)v_data, (BYTE*)raw_data, raw_size, raw_nt, raw_sect, raw_base, v_size, headers_size))
		return ERROR;


	DWORD ind_sl = wstr_rsearch(wbuf, len1, L'\\');
	if (ind_sl == (DWORD)-1)
		return ERROR;

	ps_full where_i_am;
	wchar_t* leg_str_p = (wchar_t*)s_funcs->_HeapAlloc(*(void**)((char*)__readgsqword(0x60) + 0x30), 0x08, (QWORD)len1 * 2 + 2);
	wstr_copy(leg_str_p, (QWORD)len1 + 1, wbuf, (QWORD)len1 + 1);
	where_i_am.p = leg_str_p;
	wchar_t* wname = leg_str_p + ind_sl + 1;
	where_i_am.cur_p = leg_str_p + ind_sl + 1;
	where_i_am.total_size = (QWORD)len1 + 1;
	where_i_am.cur_size = (QWORD)len1 + 1 - ind_sl;


	wchar_t* target_dir = (wchar_t*)s_funcs->_HeapAlloc(*(void**)((char*)__readgsqword(0x60) + 0x30), 0x08, (QWORD)len1 * 2 + 2);
	wstr_copy(target_dir, (QWORD)len1 + 1, wbuf, ind_sl);

	DWORD len2 = wstr_len(wname, PATH_BUF_SIZE / 2 - ind_sl - 1);

	UNICODE_STRING fname = { len1 * 2, len1 * 2 + 2, leg_str_p };

	UNICODE_STRING name = { len2 * 2, len2 * 2 + 2, wname };
	if (leg_name_func)
	{
		name.Buffer = leg_name_func->p;
		name.Length = (leg_name_func->size - 1) * 2;
		name.MaximumLenght = leg_name_func->size * 2;
		//name = { (leg_name_func->size - 1) * 2, leg_name_func->size * 2, leg_name_func->p };
	}

	if (!list_legalization(v_data, v_size, s_funcs->_LdrLockLoaderLock, s_funcs->_LdrUnlockLoaderLock, &name, &fname, s_funcs->_HeapAlloc))
		goto end_1;

	if (!import((BYTE*)v_data, (BYTE*)raw_data, raw_size, raw_nt, raw_sect, raw_base, v_size, headers_size, raw_dos, wbuf, 0,
		s_funcs, ps_s, target_dir, main_heap_size, main_depth, leg_str_p, &where_i_am, t_v))
		goto end_1;
	if (!exception(v_data, raw_data, raw_size, raw_nt, v_size, s_funcs->_RtlAddFunctionTable))
	{
		goto end_1;
	}
	QWORD raw_opbase = raw_nt->OptionalHeader.ImageBase;




	check_func = s_funcs->_VirtualFree((void*)raw_data, 0, 0x8000);
	if (!check_func)
		goto end_1;
	check_func = s_funcs->_CloseHandle(raw_handle);
	if (!check_func)
		goto end_1;
	if (!tls(v_data, v_size, s_funcs, raw_opbase, raw_size, t_v))
	{
		goto end_1;
	}

	IMAGE_NT_HEADERS* v_nt = (IMAGE_NT_HEADERS*)((BYTE*)v_data + ((IMAGE_DOS_HEADER*)v_data)->e_lfanew);
	status = 1;
	if (v_nt->OptionalHeader.AddressOfEntryPoint != 0 && v_nt->OptionalHeader.AddressOfEntryPoint < v_size)
	{
		//QWORD* peb = (PEB*)__readgsqword(0x60);
		//*((QWORD*)((char*)peb + 0x10)) = (QWORD)v_data;
		//f_ExeEntry entry = (f_ExeEntry)((BYTE*)v_data + v_nt->OptionalHeader.AddressOfEntryPoint);
		//entry();

		f_DllMain entry = (f_DllMain)((BYTE*)v_data + v_nt->OptionalHeader.AddressOfEntryPoint);
		int res = entry(v_data, 1, 0);
		if (!res)
		{
			status = 0;
			goto end_1;
		}
			
		/*status = 1;*/
		//void* testf = get_from_lib_export(0x00137B6D8BAC4937, 0xFBB14631656BE674, -1, 0, wbuf, 0,
		//	s_funcs, ps_s, (DWORD)-1, target_dir, main_heap_size, main_depth, leg_str_p, &where_i_am, 0);
		//if (!testf)
		//	goto end_1;
		//
		//f_TestFunction _TestFunction = (f_TestFunction)testf;
		//int result = _TestFunction();
		//if (result == 0)
		//	goto end_1;

	}

end_1:
	if (!s_funcs->_HeapFree(*(void**)((char*)__readgsqword(0x60) + 0x30), 0, (void*)target_dir))
		return ERROR;
	return status;

}

void Entry()
{
	//QWORD qqq = hash_func(L"kernel32.dll", 24);// 0x4453029C5C6
	//QWORD qqq = hash_func(L"ntdll.dll", 18); // 0x807DB1E
	//QWORD qqqt = hash_func(L"TLS_TEST.dll", 18); // 0x4A09A9FC872

	QWORD qqqq = hash_func(L"LibA.dll", 28); // 0x00000000003D0625
	if (qqqq == 0)
		return;
	
	//QWORD qqqwewe = hash_func_char("RunThreadTest", 1000, 1, 256);
	QWORD qqqwewe = hash_func_char("CreateTestFile", 1000, 1, 256); //0x53964641BD6D2726

	//QWORD qqq1 = hash_func_char("CreateFileA", 1000, 1, 256); // 0x22E007AAE06B675
	//QWORD qqq1 = hash_func_char("CreateFileW", 1000, 1, 256); // (void*)0x22E007AAE06B68B
	//QWORD qqq2 = hash_func_char("GetFileSize", 1000, 1, 256); // 0x241B2F4C10ACD9B
	//QWORD qqq3 = hash_func_char("VirtualAlloc", 1000, 1, 256); // 0x5513000300380752
	//QWORD qqq4 = hash_func_char("ReadFile", 1000, 1, 256); // 0x48A7D9A775C
	//QWORD qqq5 = hash_func_char("CloseHandle", 1000, 1, 256);// 0x22D10AF4342BE62
	//QWORD qqq6 = hash_func_char("VirtualFree", 1000, 1, 256); // 0x293F83E26CE3B89
	//QWORD qqq7 = hash_func_char("LoadLibraryA", 1000, 1, 256); // 0x4E2D259DADC374D6
	//QWORD qqq8 = hash_func_char("RtlAddFunctionTable", 1000, 1, 256); // 0x81FCB9681A3DD949
	//QWORD qqq9 = hash_func_char("TlsAlloc", 1000, 1, 256); // 0x4A09ABFB39E
	//QWORD qqq10 = hash_func_char("HeapAlloc", 1000, 1, 256);// 0x890FBFB20CA9
	//QWORD qqq10 = hash_func_char("VirtualProtect", 1000, 1, 256);// 0xE5D30CC87F38C408
	//QWORD qqq10 = hash_func_char("HeapFree", 1000, 1, 256);// 0x42743E17200
	//QWORD qqq11 = hash_func_char("LdrLockLoaderLock", 1000, 1, 256);// 0xAEC9802E44A7FF0B
	//QWORD qqq12 = hash_func_char("LdrUnlockLoaderLock", 1000, 1, 256);// 0xECF1B56294F5904E
	//QWORD qqq13 = hash_func_char("GetModuleFileNameW", 1000, 1, 256); // 0xB703A19F729479BE
	//QWORD qqq14 = hash_func_char("GetWindowsDirectoryW", 1000, 1, 256); // 0xE7845831516320D7
	//QWORD qqq15 = hash_func_char("GetSystemDirectoryW", 1000, 1, 256); // 0xA79D5BF2D5F59011
	//QWORD qqq16  = hash_func_char("CreateTestFile", 1000, 1, 256); // 0xFBB14631656BE674


	void* kernel_funcs[17] = { (void*)0x22E007AAE06B68B, (void*)0x241B2F4C10ACD9B, (void*)0x5513000300380752, (void*)0x48A7D9A775C,
		(void*)0x22D10AF4342BE62, (void*)0x293F83E26CE3B89, (void*)0x4E2D259DADC374D6, (void*)0x81FCB9681A3DD949, (void*)0x4A09ABFB39E,
		(void*)0x890FBFB20CA9, (void*)0xE5D30CC87F38C408, (void*)0x42743E17200, (void*)0xB703A19F729479BE, (void*)0xE7845831516320D7,
		(void*)0xA79D5BF2D5F59011,

		(void*)0xAEC9802E44A7FF0B, (void*)0xECF1B56294F5904E };
	size_t kernel_funks_size = 17;
	size_t ntdll_funks_num = 2;
	for (int i = 0; i < kernel_funks_size - ntdll_funks_num; i++)
	{
		kernel_funcs[i] = get_from_lib_export(0x4453029C5C6, (QWORD)kernel_funcs[i], -1, 0, 0, 0, 0, 0, (DWORD)-1, 0, 0, 0, 0, 0, 0, 0);
		if ((QWORD)kernel_funcs[i] == ERROR)
		{
			return;
		}
	}
	for (size_t i = (kernel_funks_size - ntdll_funks_num); i < kernel_funks_size; i++)
	{
		kernel_funcs[i] = get_from_lib_export(0x807DB1E, (QWORD)kernel_funcs[i], -1, 0, 0, 0, 0, 0, (DWORD)-1, 0, 0, 0, 0, 0, 0, 0);
		if ((QWORD)kernel_funcs[i] == ERROR)
		{
			return;
		}
	}

	f_CreateFileW _CreateFileW = (f_CreateFileW)kernel_funcs[0];
	f_GetFileSize _GetFileSize = (f_GetFileSize)kernel_funcs[1];
	f_VirtualAlloc _VirtualAlloc = (f_VirtualAlloc)kernel_funcs[2];
	f_ReadFile _ReadFile = (f_ReadFile)kernel_funcs[3];
	f_CloseHandle _CloseHandle = (f_CloseHandle)kernel_funcs[4];
	f_VirtualFree _VirtualFree = (f_VirtualFree)kernel_funcs[5];
	f_LoadLibraryA _LoadLibraryA = (f_LoadLibraryA)kernel_funcs[6];
	f_RtlAddFunctionTable _RtlAddFunctionTable = (f_RtlAddFunctionTable)kernel_funcs[7];
	f_TlsAlloc _TlsAlloc = (f_TlsAlloc)kernel_funcs[8];
	f_HeapAlloc _HeapAlloc = (f_HeapAlloc)kernel_funcs[9];
	f_VirtualProtect _VirtualProtect = (f_VirtualProtect)kernel_funcs[10];
	f_HeapFree _HeapFree = (f_HeapFree)kernel_funcs[11];
	f_GetModuleFileNameW _GetModuleFileNameW = (f_GetModuleFileNameW)kernel_funcs[12];
	f_GetWindowsDirectoryW _GetWindowsDirectoryW = (f_GetWindowsDirectoryW)kernel_funcs[13];
	f_GetSystemDirectoryW _GetSystemDirectoryW = (f_GetSystemDirectoryW)kernel_funcs[14];

	f_LdrLockLoaderLock _LdrLockLoaderLock = (f_LdrLockLoaderLock)kernel_funcs[15];
	f_LdrUnlockLoaderLock _LdrUnlockLoaderLock = (f_LdrUnlockLoaderLock)kernel_funcs[16];


	FUNCS s_funcs = { _CreateFileW, _GetFileSize, _VirtualAlloc, _ReadFile, _CloseHandle, _VirtualFree,
					_LoadLibraryA, _RtlAddFunctionTable, _TlsAlloc, _HeapAlloc, _VirtualProtect,
					_HeapFree, _GetModuleFileNameW, _GetWindowsDirectoryW, _GetSystemDirectoryW,
					_LdrLockLoaderLock, _LdrUnlockLoaderLock };


	wchar_t* wbuf = (wchar_t*)_HeapAlloc(*(void**)((char*)__readgsqword(0x60) + 0x30), 0x08, PATH_BUF_SIZE);
	_LoadLibraryA("user32.dll");
	_LoadLibraryA("gdi32.dll");
	_LoadLibraryA("gdi32full.dll");

	//wbuf = L"E:\\C++\\TLS_TEST\\x64\\Release\\TLS_TEST.dll";
	//wbuf = L"E:\\games\\Tor Browser\\Browser\\firefox.exe";
	//wchar_t* start_filepath = L"E:\\C++\\TLS_TEST\\x64\\Debug\\TLS_TEST.dll";
	//wchar_t* start_filepath = L"E:\\C++\\TLS_TEST\\x64\\Release\\TLS_TEST.dll";
	//wchar_t* start_filepath = L"C:\\Windows\\System32\\winhttp.dll";
	//wchar_t* start_filepath = L"C:\\Windows\\System32\\user32.dll";
	//wchar_t* start_filepath = L"C:\\Windows\\System32\\ucrtbase.dll";
	wchar_t* start_filepath = L"C:\\Users\\admin\\Desktop\\Новая папка\\LibA.dll";
	//wchar_t* start_filepath = L"C:\\Users\\admin\\Desktop\\Новая папка\\LibC.dll";
	//wchar_t* start_filepath = L"C:\\Windows\\System32\\gdi32.dll";

	DWORD lena_main = wstr_len(start_filepath, 100);
	wstr_copy(wbuf, PATH_BUF_SIZE / 2, start_filepath, (QWORD)lena_main);
	wchar_t*** param_p = (wchar_t***)((char*)__readgsqword(0x60) + 0x20);
	QWORD env_size = *((QWORD*)((char*)*param_p + 0x3f0));
	wchar_t** env_p = (wchar_t**)((char*)*param_p + 0x80);
	wchar_t* path_p = *env_p;
	ps ps_s = { path_p, env_size };

	if (!wstr_substr_search(&ps_s) || ps_s.size <= 10)
	{
		return;
	}
	ps_s.p += 5;
	ps_s.size -= 10;

	thread_variables t_v = { 0, 0, 0, 0 };
	scanner(&t_v);
	if (t_v.buf_address == 0 || t_v.goal_func == 0 || t_v.number_of_bits == 0 || t_v.number_of_cells == 0)
		return;

	if (!preparing(&s_funcs, &t_v))
		return;

	//int debug_len = 0;
	//while (debug_len < 100)
	//{
	//	debug_len += lde((BYTE*)t_v.goal_func + debug_len);
	//}
	//if (debug_len == 100)
	//	return;
	 
	
	final.HeapMain = *(void**)((char*)__readgsqword(0x60) + 0x30);
	final._HeapAlloc = s_funcs._HeapAlloc;
	final.trampoline = make_hook(&t_v, &s_funcs);
	if (!final.trampoline)
		return;

	if (!not_Entry(&s_funcs, wbuf, &ps_s, 0, 0, 0, &t_v))
		return;


	void* func_addr = get_from_lib_export(qqqq, qqqwewe, -1, 0,
		wbuf, 0, &s_funcs, &ps_s, (DWORD)-1, 0, 0, 0, 0, 0, 0, 0);
	if (func_addr)
	{
		typedef int(__stdcall* f_CreateTestFile)(const wchar_t* filePath);
		f_CreateTestFile _CreateTestFile = (f_CreateTestFile)func_addr;
		int result = _CreateTestFile(L"C:\\Users\\admin\\Desktop\\res.txt");
		if (result == 1) {
			// проверяем диск
		}
		
		/*typedef void(__stdcall* f_RunThreadTest)();
		f_RunThreadTest _RunThreadTest = (f_RunThreadTest)func_addr;
		_RunThreadTest();*/
	}

	while (1)
	{

	}
}

