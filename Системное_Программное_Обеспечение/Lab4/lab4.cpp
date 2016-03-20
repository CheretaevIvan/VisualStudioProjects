#include <Windows.h>
#include <stdio.h>
#include <locale.h>
#include <inttypes.h>
#include <iostream>

int main(void)
{
	setlocale(LC_ALL, "RU");
	DWORD available_drives = GetLogicalDrives();
	int has_disk = 0;
	for (int i = 0; i < sizeof(available_drives)*8; i++)
	{
		if (has_disk = ((available_drives >> i) % 2))
		printf("В системе присутствует логический диск с идентификатором %c\n", (char)(i+65));
	}
	printf("\n");

	int length_buffer = GetLogicalDriveStrings(0, NULL);
	char *info_about_drives = (char*)malloc(length_buffer*sizeof(char));
	DWORD i = GetLogicalDriveStrings(length_buffer, info_about_drives);
	DWORD sectors_per_cluster = 0;
	DWORD bytes_per_sector = 0;
	DWORD number_of_free_cluster = 0;
	DWORD total_number_of_cluster = 0;

	int length_buffer_for_info = 80;
	char *volume_name = (char*)malloc(length_buffer_for_info*sizeof(char));
	DWORD volume_serial_number;
	DWORD max_component_length;
	DWORD file_system_flags;
	char *file_system_name = (char*)malloc(length_buffer_for_info*sizeof(char));

	while (info_about_drives[0])
	{
		printf("%s\n", info_about_drives);
		UINT type_drive = GetDriveType(info_about_drives);
		switch (type_drive)
		{
		case 0:
			printf("Тип: Тип устройства определить не удалось\n");
			break;
		case 1:
			printf("Тип: Указанный корневой каталог не существует\n");
			break;
		case DRIVE_REMOVABLE:
			printf("Тип: Устройство со сменным носителем данных\n");
			break;
		case DRIVE_FIXED:
			printf("Тип: Устройство с несменным носителем данных\n");
			break;
		case DRIVE_REMOTE:
			printf("Тип: Удаленное (сетевое) устройство\n");
			break;
		case DRIVE_CDROM:
			printf("Тип: Устройство чтения CD-ROM\n");
			break;
		case DRIVE_RAMDISK:
			printf("Тип: Электронный диск (RAM-диск)\n");
			break;
		default:
			break;
		}
		if (GetDiskFreeSpace(info_about_drives, &sectors_per_cluster, &bytes_per_sector, &number_of_free_cluster, &total_number_of_cluster))
		{
			unsigned long long free_space = (number_of_free_cluster)*sectors_per_cluster*bytes_per_sector;
			char* memory = "байт";
			if (free_space / 1024 > 0)
			{
				free_space /= 1024;
				memory = "Кбайт";
				if (free_space / 1024 > 0)
				{
					free_space /= 1024;
					memory = "Мбайт";
					if (free_space / 1024 > 0)
					{
						free_space /= 1024;
						memory = "Гбайт";
					}
				}
			}
			printf("Свободной памяти: %"PRIi64" %s\n", free_space, memory);
		}
		else
			printf("Устройство недоступно для определения количества свободной памяти\n");
		if (GetVolumeInformation(info_about_drives, volume_name, length_buffer_for_info, &volume_serial_number, &max_component_length, &file_system_flags, file_system_name, length_buffer_for_info))
		{
			printf("Имя тома: %s"
				   "\nСерийный номер: %"PRIi64
				   "\nМаксимальная длина имени файла: %"PRIi32
				   "\nФайловая система: NTFS\n",
				volume_name,
				volume_serial_number,
				max_component_length);
			if (file_system_flags & FS_CASE_IS_PRESERVED)
				printf("Система делает различия между заглавными и прописными буквами в именах файлов при записи этих имен на диск\n");
			if (file_system_flags & FS_CASE_SENSITIVE)
				printf("Система делает различия между заглавными и прописными буквами\n");
			if (file_system_flags & FS_UNICODE_STORED_ON_DISK)
				printf("Система может работать с кодировкой Unicode в именах файлов\n");
			if (file_system_flags & FS_PERSISTENT_ACLS)
				printf("Система способна работать со списком контроля доступа к файлам ACL (access-control list)\n");
			if (file_system_flags & FS_FILE_COMPRESSION)
				printf("Файловая система способна сжимать (компрессовать) отдельные файлы\n");
			if (file_system_flags & FS_VOL_IS_COMPRESSED)
				printf("Для тома используется автоматическая компрессия данных\n");
		}
		else
			printf("Устройство недоступно\n");
		printf("\n");
		while (info_about_drives[0]) info_about_drives++;
		info_about_drives++;
	}
	system("pause");
}