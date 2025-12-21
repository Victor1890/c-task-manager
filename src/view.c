#include <stdio.h>
#include <stdlib.h>

void view_print_menu()
{
	printf("=============================\n");
	printf("        TODO CLI - C\n");
	printf("=============================\n");
	printf("1. Add new task\n");
	printf("2. View all tasks\n");
	printf("3. View pending tasks\n");
	printf("4. View completed tasks\n");
	printf("5. Mark task as completed\n");
	printf("6. Edit task\n");
	printf("7. Delete task\n");
	printf("8. Save tasks\n");
	printf("0. Exit\n");
	printf("=============================\n");
	printf("Select an option: ");
}

void view_clean_screen()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}