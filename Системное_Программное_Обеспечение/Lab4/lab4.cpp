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
		printf("� ������� ������������ ���������� ���� � ��������������� %c\n", (char)(i+65));
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
			printf("���: ��� ���������� ���������� �� �������\n");
			break;
		case 1:
			printf("���: ��������� �������� ������� �� ����������\n");
			break;
		case DRIVE_REMOVABLE:
			printf("���: ���������� �� ������� ��������� ������\n");
			break;
		case DRIVE_FIXED:
			printf("���: ���������� � ��������� ��������� ������\n");
			break;
		case DRIVE_REMOTE:
			printf("���: ��������� (�������) ����������\n");
			break;
		case DRIVE_CDROM:
			printf("���: ���������� ������ CD-ROM\n");
			break;
		case DRIVE_RAMDISK:
			printf("���: ����������� ���� (RAM-����)\n");
			break;
		default:
			break;
		}
		if (GetDiskFreeSpace(info_about_drives, &sectors_per_cluster, &bytes_per_sector, &number_of_free_cluster, &total_number_of_cluster))
		{
			unsigned long long free_space = (number_of_free_cluster)*sectors_per_cluster*bytes_per_sector;
			char* memory = "����";
			if (free_space / 1024 > 0)
			{
				free_space /= 1024;
				memory = "�����";
				if (free_space / 1024 > 0)
				{
					free_space /= 1024;
					memory = "�����";
					if (free_space / 1024 > 0)
					{
						free_space /= 1024;
						memory = "�����";
					}
				}
			}
			printf("��������� ������: %"PRIi64" %s\n", free_space, memory);
		}
		else
			printf("���������� ���������� ��� ����������� ���������� ��������� ������\n");
		if (GetVolumeInformation(info_about_drives, volume_name, length_buffer_for_info, &volume_serial_number, &max_component_length, &file_system_flags, file_system_name, length_buffer_for_info))
		{
			printf("��� ����: %s"
				   "\n�������� �����: %"PRIi64
				   "\n������������ ����� ����� �����: %"PRIi32
				   "\n�������� �������: NTFS\n",
				volume_name,
				volume_serial_number,
				max_component_length);
			if (file_system_flags & FS_CASE_IS_PRESERVED)
				printf("������� ������ �������� ����� ���������� � ���������� ������� � ������ ������ ��� ������ ���� ���� �� ����\n");
			if (file_system_flags & FS_CASE_SENSITIVE)
				printf("������� ������ �������� ����� ���������� � ���������� �������\n");
			if (file_system_flags & FS_UNICODE_STORED_ON_DISK)
				printf("������� ����� �������� � ���������� Unicode � ������ ������\n");
			if (file_system_flags & FS_PERSISTENT_ACLS)
				printf("������� �������� �������� �� ������� �������� ������� � ������ ACL (access-control list)\n");
			if (file_system_flags & FS_FILE_COMPRESSION)
				printf("�������� ������� �������� ������� (�������������) ��������� �����\n");
			if (file_system_flags & FS_VOL_IS_COMPRESSED)
				printf("��� ���� ������������ �������������� ���������� ������\n");
		}
		else
			printf("���������� ����������\n");
		printf("\n");
		while (info_about_drives[0]) info_about_drives++;
		info_about_drives++;
	}
	system("pause");
}