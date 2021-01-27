#include "pch.h"
#include <stdio.h>
#include <string.h>									//	For string.
#include <time.h>									//	For clock.
#pragma warning (disable:4996)

void main_menu();									//	Main menu(login page).
													//	_____________________________________________________
													//
void admin_login();									//		1) Login as admin.
void admin_menu();									//				Admin functions:
													//	_____________________________________________________
													//
void staff_login();									//		2) Login as Staff.
void staff_menu();									//				Staff functions:
													//	_____________________________________________________
													//
void member_login();								//		2) Login as Member
void member_menu();									//				Member functions:
													//	_____________________________________________________
void staff_profile_creation_intro();				//
void staff_profile_creation();						//		a) Create staff profile.
void member_profile_creation_intro();				//
void member_profile_creation();						//		b) Create member profile.
void staff_profile_deletion_intro();				//
void staff_profile_deletion();						//		e) Delete staff profile.
void member_profile_deletion_intro();				//
void member_profile_deletion();						//		e) Delete member profile.
void staff_profile_modification_intro();			//   
void staff_profile_modification();					//		c) Modify staff profile.
void member_profile_modification_intro();			//
void member_profile_modification();					//		d) Modify member profile.
void search_and_view_sprofile_intro();				//
void search_and_view_sprofile();					//		e) Search and view staff profile.
void search_and_view_mprofile_intro();				//
void search_and_view_mprofile();					//		f) Search and view member profile.
													//	_____________________________________________________
													//
void timer(int time_value);							//	Timer.
													//	_____________________________________________________


//Variables for staff login.
char staff_log_pw[10];
char staff_pw[10];
char staff_info[30];
char staff_log_id[30];
//Variables for member login.
char member_log_pw[10];
char member_pw[10];
char member_info[30];
char member_log_id[30];


//Timer.
void timer(int time_value)
{
	int mil_sec = 1000 * time_value;
	clock_t start_time = clock();
	while (clock() < start_time + mil_sec);
}


//Default.
int main()
{
	main_menu();
}


//Main menu(login page).
void main_menu()
{
	int user_identity;
	printf("________________________________________________________________________________________________________________________\n\n");
	timer(1);
	printf("Welcome to TDBS, the Toy-Depot Billing System :) \n\n");
	timer(1);
	printf("Please choose to login or quit: \n\n");										//Choose to login as what identity.
	printf("|=======================================================|\n");
	printf("|                                                       |\n");
	printf("|       1. Administrator.                               |\n");
	printf("|       2. Staff.                                       |\n");
	printf("|       3. Member (View self profile information).      |\n");
	printf("|       4. Quit TDBS.                                   |\n");
	printf("|_______________________________________________________|\n\n");
	printf("Select: ");
	scanf("%d", &user_identity);
	if (user_identity == 1)																//Login as admin.
	{
		admin_login();
	}
	else if (user_identity == 2)														//Login as staff.
	{
		staff_login();
	}
	else if (user_identity == 3)														//Member.
	{
		member_login();
	}
	else if (user_identity == 4)														//Quit TDBS.
	{
		timer(1);
		printf("\nThank you for using TDBS :) \n");
		printf("\nPress any key to quit. \n");
		timer(1);
		exit();
	}
	else
		printf("Illegal input, please try again!\n");									//Invalid input.
		main_menu();
}


//Admin login procedures.
void admin_login()
{
	char admin_username[30];
	char admin_password[30];
	printf("\nEnter admin username: ");								//Ask for admin ID.
	scanf("%s", &admin_username);
	if (strcmp(admin_username, "donovan") == 0)
	{
		printf("Enter admin password: ");							//Ask for admin password.
		scanf("%s", &admin_password);
		if (strcmp(admin_password, "316") == 0)						//Verify admin password.
		{
			printf("\nLogging in.");
			timer(1);
			printf(".");
			timer(1);
			printf(". \n");
			timer(1);
			printf("______________________________ \n");
			printf("|                            | \n");
			printf("|   Welcome, administrator.  | \n");
			printf("|____________________________| \n\n");
			admin_menu();
		}
		else
			printf("____________________________________ \n");
			printf("Wrong password, please retry.");				//Prompt wrong admin password.
			admin_login();
		
	}
	else
		printf("____________________________________ \n");
		printf("Wrong admin username, please retry.");				//Prompt wrong admin username.
		admin_login();

}
//Staff login procedures.
void staff_login()
{
	char s_log_directory[] = ("stafflist/");
	char s_log_name[10] = "staff";
	char s_txt[10] = ".txt";

	printf("\nEnter Staff ID: ");										//Ask for staff ID.
	scanf("%s", &staff_log_id);

	strcat(s_log_directory, s_log_name);
	strcat(s_log_directory, staff_log_id);
	strcat(s_log_directory, s_txt);

	FILE *fpsl;
	fpsl = fopen(s_log_directory, "r");

	if (fpsl == NULL)													//Staff ID not found.
	{
		printf("Staff ID %s does not exist, please retry with another Staff ID! \n", staff_log_id);
		printf("__________________________________________________________________");
		staff_login();
	}
	else
	{
		printf("Enter Staff password: ");								//Ask for staff password.
		scanf("%s", &staff_log_pw);

		int i = 0;

		while (fpsl != EOF)
		{
			staff_info[i] = fgetc(fpsl);
			if (staff_info[i] == '$')
			{
				for (i = 0; i < 5; i++)
				{
					staff_pw[i] = fgetc(fpsl);
				}
				if (strcmp(staff_pw, staff_log_pw) == 0)
				{
					printf("\nLogging in.");
					timer(1);
					printf(".");
					timer(1);
					printf(". \n");
					timer(1);
					printf("_____________________________ \n");
					printf("|                           | \n");
					printf("|   Welcome, Staff %s.    | \n", staff_log_id);
					printf("|___________________________| \n\n");
					staff_menu();
				}
				else
				{
					printf("__________________________________________________________________ \n");
					printf("Wrong password, please retry.");			//Prompt wrong staff password.
					staff_login();
				}
			}
		}
	}
}
//Member login procedures.
void member_login()
{
	char m_log_directory[] = ("memberlist/");
	char m_log_name[10] = "member";
	char m_txt[10] = ".txt";

	printf("\nEnter Member ID: ");											//Ask for member ID.
	scanf("%s", &member_log_id);

	strcat(m_log_directory, m_log_name);
	strcat(m_log_directory, member_log_id);
	strcat(m_log_directory, m_txt);

	FILE *fpml;
	fpml = fopen(m_log_directory, "r");

	if (fpml == NULL)														//Member ID not found.
	{
		printf("Member ID %s does not exist, please retry with another Member ID! \n", member_log_id);
		printf("__________________________________________________________________");
		member_login();
	}
	else
	{
		printf("Enter Member password: ");									//Ask for member password.
		scanf("%s", &member_log_pw);

		int i = 0;

		while (fpml != EOF)
		{
			member_info[i] = fgetc(fpml);
			if (member_info[i] == '$')
			{
				for (i = 0; i < 5; i++)
				{
					member_pw[i] = fgetc(fpml);
				}
				if (strcmp(member_pw, member_log_pw) == 0)
				{
					printf("\nLogging in.");
					timer(1);
					printf(".");
					timer(1);
					printf(". \n");
					timer(1);
					printf("_____________________________ \n");
					printf("|                           | \n");
					printf("|   Welcome, Member %s.   | \n", member_log_id);
					printf("|___________________________| \n\n");
					member_menu();
				}
				else
				{
					printf("__________________________________________________________________ \n");
					printf("Wrong password, please retry.");				//Prompt wrong member password.
					member_login();
				}
			}
		}
	}
	fclose(fpml);
}


//Admin menu.
void admin_menu()
{
	int admin_function;
	printf("________________________________________________________________________________________________________________________\n\n");
	printf("Here is the admin menu: \n\n");										//Show admin functions.
	printf("|======================================================|\n");
	printf("|                                                      |\n");
	printf("|                                                      |\n");
	printf("|    1. Create new staff and member profile.           |\n");
	printf("|       6. Staff profile.                              |\n");
	printf("|       7. Member profile.                             |\n");
	printf("|    2. Delete staff and member records.               |\n");
	printf("|       8. Staff profile.                              |\n");
	printf("|       9. Member profile.                             |\n");
	printf("|    3. Modify existing and member profile.            |\n");
	printf("|       10. Staff profile.                             |\n");
	printf("|       11. Member profile.                            |\n");
	printf("|    4. Search and view staff or member profile.       |\n");
	printf("|       12. Staff profile.                             |\n");
	printf("|       13. Member profile.                            |\n");
	printf("|    5. Logout.                                        |\n");
	printf("|                                                      |\n");
	printf("|                                                      |\n");
	printf("|______________________________________________________|\n\n");
	printf("What do you wish to do: ");											//Asks admin what to do.
	scanf("%d", &admin_function);
	switch (admin_function)
	{
		case 6:
			staff_profile_creation_intro();										//Admin chooses to create staff profile.
			break;
		case 7:
			member_profile_creation_intro();									//Admin chooses to create member profile.
			break;
		case 8:
			staff_profile_deletion_intro();										//Admin chooses to delte staff profile.
			break;
		case 9:
			member_profile_deletion_intro();									//Admin chooses to delete staff profile.
			break;
		case 10:
			staff_profile_modification_intro();									//Admin chooses to modify staff profile.
			break;
		case 11:
			member_profile_modification_intro();								//Admin chooses to modify member profile.
			break;
		case 12:
			search_and_view_sprofile();											//Admin chooses to search and view staff profile.
			break;
		case 13:
			search_and_view_mprofile();											//Admin chooses to search and view member profile.
			break;
		case 5:
			printf("Will now redirect you to home page. \n");
			main_menu();														//Admin logouts.
			break;
		default:
			printf("Invalid input, please log in again!\n");
			main_menu();														//Invalid Input.
			break;
	}
}
//Staff menu.
void staff_menu()
{
	int staff_function;
	printf("________________________________________________________________________________________________________________________\n\n");
	printf("Here is the staff menu: \n\n");								//Show staff functions.
	printf("|=============================================|\n");
	printf("|                                             |\n");
	printf("|                                             |\n");
	printf("|    1. Create new member profile.            |\n");
	printf("|    2. Search and view member profile.       |\n");
	printf("|    3. Logout.                               |\n");
	printf("|                                             |\n");
	printf("|_____________________________________________|\n\n");
	printf("What do you wish to do: ");									//Asks staff what to do.
	scanf("%d", &staff_function);
	switch (staff_function)
	{
	case 1:
		member_profile_creation_intro();								//Staff chooses to create staff profile.
		break;
	case 2:
		search_and_view_mprofile();										//Staff chooses to create member profile.
		break;
	case 3:
		printf("Will now redirect you to home page. \n");
		main_menu();													//Staff logouts.
		break;
	default:
		printf("Invalid input, please log in again!\n");
		main_menu();													//Invalid Input.
		break;
	}
}
//Member menu.
void member_menu()
{
	char m_log_directory[] = ("memberlist/");
	char m_log_name[10] = "member";
	char m_txt[10] = ".txt";

	char member_all_info;
	char admin_option;

	strcat(m_log_directory, m_log_name);
	strcat(m_log_directory, member_log_id);
	strcat(m_log_directory, m_txt);

	FILE *fpmv;

	fpmv = fopen(m_log_directory, "r");

	printf("\nProfile information of Member %s:\n", member_log_id);				//Show member profile information.
	while ((member_all_info = fgetc(fpmv)) != EOF)
	{
		printf("%c", member_all_info);
	}

	fclose(fpmv);
	timer(1);
	printf("__________________________________________________________\n");
	timer(1);
	printf("Input '0' to return to login page. \n\n");
	printf("|=================================|\n");
	printf("|                                 |\n");
	printf("|       0. Back to login.         |\n");
	printf("|_________________________________|\n\n");
	printf("Return to login page: ");
	scanf("%d", &admin_option);
	if (admin_option == 0)
	{
		main_menu();															//Exit to main menu.
	}
	else
	{
		printf("Invalid input, will terminate back to login page. \n");
		main_menu();
	}
}


//Admin creates staff profile.
void staff_profile_creation_intro()
{
	printf("________________________________________________________________________________________________________________________\n\n");
	printf("______________________________ \n");
	printf("|                            | \n");
	printf("|   Staff profile creation.  | \n");
	printf("|____________________________| \n\n");
	staff_profile_creation();
}
void staff_profile_creation()												//Staff profile creation menu.
{
	char s_file_directory[] = ("stafflist/");
	char s_file_name[10] = "staff";
	char s_txt[10] = ".txt";
	
	char staff_id[30];
	char staff_name[30];
	char staff_no[30];
	char staff_pw[30];

	int admin_option;

	printf("Staff ID (Must be 4 digits): ");								//Ask for staff info.
	scanf(" %[^\n]s", &staff_id);
	printf("Staff Name: ");
	scanf(" %[^\n]s", &staff_name);
	printf("Contact Number: ");
	scanf(" %[^\n]s", &staff_no);
	printf("Staff Password (Must be 5 digits): ");
	scanf(" %[^\n]s", &staff_pw);

	strcat(s_file_directory, s_file_name);									//Merge for file name.
	strcat(s_file_directory, staff_id);
	strcat(s_file_directory, s_txt);

	FILE *fps;

	if (fps = fopen(s_file_directory, "r"))									//Generate file.
	{
		fclose(fps);
		printf("\nStaff ID already exist, please try again! \n\n");			//Staff already exists.
		printf("_____________________________________________\n");
		staff_profile_creation();
	}

	fps = fopen(s_file_directory, "w");										//Write profile.

	fprintf(fps, "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n");
	fprintf(fps, "|\n");
	fprintf(fps, "|		Staff ID: @%s \t\n", staff_id);
	fprintf(fps, "|		Staff Name: %s \t\n", staff_name);
	fprintf(fps, "|		Contact Number: %s \t\n", staff_no);
	fprintf(fps, "|		Staff Password: $%s \t\n", staff_pw);
	fprintf(fps, "|\n");
	fprintf(fps, "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n");

	rewind(fps);
	fclose(fps);
	printf("\n_________________________________________ \n");
	printf("|                                       | \n");
	printf("|   Staff profile creation successful.  | \n");
	printf("|_______________________________________| \n\n");

	timer(1);
	printf("__________________________________________________________\n");
	timer(1);
	printf("Input '0' to return to login page. \n\n");
	printf("|=================================|\n");
	printf("|                                 |\n");
	printf("|       0. Back to login.         |\n");
	printf("|_________________________________|\n\n");
	printf("Return to login page: ");
	scanf("%d", &admin_option);
	if (admin_option == 0)
	{
		main_menu();														//Exit to main menu.
	}
	else
	{
		printf("Invalid input, will terminate back to login page. \n");
		main_menu();
	}
}


//Admin creates member profile.
void member_profile_creation_intro()
{
	printf("________________________________________________________________________________________________________________________\n\n");
	printf("_______________________________ \n");
	printf("|                             | \n");
	printf("|   Member profile creation.  | \n");
	printf("|_____________________________| \n");
	member_profile_creation();
}
void member_profile_creation()												//Member profile creation menu.
{
	char m_file_directory[] = ("memberlist/");
	char m_file_name[10] = "member";
	char m_txt[10] = ".txt";

	char member_id[30];
	char member_name[30];
	char member_no[30];
	char member_bill[30];
	char toy_id[30];
	char a_paid[30];
	char p_date[30];
	char member_pw[30];

	int admin_option;

	printf("Member ID (Must be 4 digits): ");								//Ask for member info.
	scanf(" %[^\n]s", &member_id);
	printf("Member Name: ");
	scanf(" %[^\n]s", &member_name);
	printf("Contact Number: ");
	scanf(" %[^\n]s", &member_no);
	printf("Billing address: ");
	scanf(" %[^\n]s", &member_bill);
	printf("Toy ID (Mattel-1, Marvel-2, Lego-3, Hot Wheels-4, Disney-5): ");
	scanf(" %[^\n]s", &toy_id);
	printf("Amount paid (MYR): ");
	scanf(" %[^\n]s", &a_paid);
	printf("Payment date (dd/mm/yy): ");
	scanf(" %[^\n]s", &p_date);
	printf("Member Password (Must be 5 digits): ");
	scanf(" %[^\n]s", &member_pw);

	strcat(m_file_directory, m_file_name);									//Merge for file name.
	strcat(m_file_directory, member_id);
	strcat(m_file_directory, m_txt);

	FILE *fpm;

	if (fpm = fopen(m_file_directory, "r"))									//Member ID already exists.
	{
		fclose(fpm);
		printf("\nMember ID already exist, please try again! \n\n");
		printf("_____________________________________________\n");
		member_profile_creation();
	}

	fpm = fopen(m_file_directory, "w");										//Write file.


	fprintf(fpm, "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n");
	fprintf(fpm, "|\n");
	fprintf(fpm, "|		Member ID: @%s \t\n", member_id);
	fprintf(fpm, "|		Member Name: %s \t\n", member_name);
	fprintf(fpm, "|		Contact Number: %s \t\n", member_no);
	fprintf(fpm, "|		Billing address: %s \t\n", member_bill);
	fprintf(fpm, "|		Toy ID: %s \t\n", toy_id);
	fprintf(fpm, "|		Amount paid (MYR): RM%s \t\n", a_paid);
	fprintf(fpm, "|		Payment date (dd/mm/yy): %s \t\n", p_date);
	fprintf(fpm, "|		Member Password: $%s \t\n", member_pw);
	fprintf(fpm, "|\n");
	fprintf(fpm, "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n");

	rewind(fpm);
	fclose(fpm);
	printf("\n_________________________________________ \n");
	printf("|                                       | \n");
	printf("|   Member profile creation successful. | \n");
	printf("|_______________________________________| \n\n");

	timer(1);
	printf("__________________________________________________________\n");
	timer(1);
	printf("Input '0' to return to login page. \n\n");
	printf("|=================================|\n");
	printf("|                                 |\n");
	printf("|       0. Back to login.         |\n");
	printf("|_________________________________|\n\n");
	printf("Return to login page: ");
	scanf("%d", &admin_option);
	if (admin_option == 0)
	{
		main_menu();														//Exit to main menu.
	}
	else
	{
		printf("Invalid input, will terminate back to login page. \n");
		main_menu();
	}
}


//Admin deletes staff profile.
void staff_profile_deletion_intro()
{
	printf("________________________________________________________________________________________________________________________\n\n");
	printf("________________________________ \n");
	printf("|                              | \n");
	printf("|    Staff profile deletion.   | \n");
	printf("|______________________________| \n\n");
	staff_profile_deletion();
}
void staff_profile_deletion()
{
	char s_del_directory[] = ("stafflist/");
	char s_del_name[10] = "staff";
	char s_txt[10] = ".txt";

	int staff_status;
	int admin_option;
	char del_staff_id[30];

	printf("Please enter the staff ID to be deleted: \n");					//Ask for Staff ID for deletion.
	scanf(" %[^\n]s", &del_staff_id);

	strcat(s_del_directory, s_del_name);									//Merge for file name.
	strcat(s_del_directory, del_staff_id);
	strcat(s_del_directory, s_txt);

	staff_status = remove(s_del_directory);									//Deletes the file.

	if (staff_status == 0)
	{
		printf("\nStaff %s deleted successfully.\n", del_staff_id);
		timer(1);
		printf("__________________________________________________________\n");
		timer(1);
		printf("Input '0' to return to login page. \n\n");
		printf("|=================================|\n");
		printf("|                                 |\n");
		printf("|       0. Back to login.         |\n");
		printf("|_________________________________|\n\n");
		printf("Return to login page: ");
		scanf("%d", &admin_option);
		if (admin_option == 0)
		{
			main_menu();													//Exit to main menu.
		}
		else
		{
			printf("Invalid input, will terminate back to login page. \n");
			main_menu();
		}
	}
	else
	{
		printf("Unable to delete the staff, staff not found! \n");
		printf("Please check if staff ID is correct and retry. \n");
		printf("________________________________________________\n\n");
		staff_profile_deletion();
	}
}


//Admin deletes member profile.
void member_profile_deletion_intro()
{
	printf("________________________________________________________________________________________________________________________\n\n");
	printf("________________________________ \n");
	printf("|                              | \n");
	printf("|   Member profile deletion.   | \n");
	printf("|______________________________| \n\n");
	member_profile_deletion();
}
void member_profile_deletion()
{
	char m_del_directory[] = ("memberlist/");
	char m_del_name[10] = "member";
	char m_txt[10] = ".txt";

	int member_status;
	int admin_option;
	char del_member_id[30];

	printf("Please enter the member ID to be deleted: \n");					//Ask for Member ID for deletion.
	scanf(" %[^\n]s", &del_member_id);
	
	strcat(m_del_directory, m_del_name);									//Merge for file name.
	strcat(m_del_directory, del_member_id);
	strcat(m_del_directory, m_txt);

	member_status = remove(m_del_directory);								//Deletes the file.

	if (member_status == 0)
	{
		printf("\nMember %s deleted successfully.\n", del_member_id);
		timer(1);
		printf("__________________________________________________________\n");
		timer(1);
		printf("Input '0' to return to login page. \n\n");
		printf("|=================================|\n");
		printf("|                                 |\n");
		printf("|       0. Back to login.         |\n");
		printf("|_________________________________|\n\n");
		printf("Return to login page: ");
		scanf("%d", &admin_option);
		if (admin_option == 0)
		{
			main_menu();													//Exit to main menu.
		}
		else
		{
			printf("Invalid input, will terminate back to login page. \n");
			main_menu();
		}
	}
	else
	{
		printf("Unable to delete the member, member not found! \n");
		printf("Please check if member ID is correct and retry. \n");
		printf("________________________________________________\n\n");
		member_profile_deletion();
	}
}


//Admin modifies staff profile.
void staff_profile_modification_intro()
{
	printf("________________________________________________________________________________________________________________________\n\n");
	printf("___________________________________ \n");
	printf("|                                 | \n");
	printf("|   Staff profile modification.   | \n");
	printf("|_________________________________| \n\n");
	staff_profile_modification();
}
void staff_profile_modification()
{
	char s_mod_directory[] = ("stafflist/");
	char s_mod_name[10] = "staff";
	char s_txt[10] = ".txt";

	char mod_staff_id[30];
	char n_staff_name[30];
	char n_staff_no[30];
	char n_staff_pw[30];

	int staff_status;
	int admin_option;

	printf("Please enter the staff ID to be modified: ");					//Ask for Staff ID for modification.
	scanf(" %[^\n]s", &mod_staff_id);
	
	strcat(s_mod_directory, s_mod_name);									//Merge for file name.
	strcat(s_mod_directory, mod_staff_id);
	strcat(s_mod_directory, s_txt);

	staff_status = remove(s_mod_directory);									//Deletes the file.

	if (staff_status == 0)													//Ask for new Staff info.
	{
		printf("\nNow please enter new information for staff ID %s. \n", mod_staff_id);
		printf("__________________________________________________________ \n\n");
		printf("New Staff Name: ");
		scanf(" %[^\n]s", &n_staff_name);
		printf("New Contact Number: ");
		scanf(" %[^\n]s", &n_staff_no);
		printf("New Staff Password (Must be 5 digits): ");
		scanf(" %[^\n]s", &n_staff_pw);

		FILE *fpsm;

		fpsm = fopen(s_mod_directory, "w");									//Write new file.

		fprintf(fpsm, "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n");
		fprintf(fpsm, "|\n");
		fprintf(fpsm, "|		Staff ID: @%s \t\n", mod_staff_id);
		fprintf(fpsm, "|		Staff Name: %s \t\n", n_staff_name);
		fprintf(fpsm, "|		Contact Number: %s \t\n", n_staff_no);
		fprintf(fpsm, "|		Staff Password: $%s \t\n", n_staff_pw);
		fprintf(fpsm, "|\n");
		fprintf(fpsm, "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n");

		rewind(fpsm);
		fclose(fpsm);
		printf("\nInformation of Staff ID %s succesfully modified! \n", mod_staff_id);
		timer(1);
		printf("__________________________________________________________\n");
		timer(1);
		printf("Input '0' to return to login page. \n\n");
		printf("|=================================|\n");
		printf("|                                 |\n");
		printf("|       0. Back to login.         |\n");
		printf("|_________________________________|\n\n");
		printf("Return to login page: ");
		scanf("%d", &admin_option);
		if (admin_option == 0)
		{
			main_menu();													//Exit to main menu.
		}
		else
		{
			printf("Invalid input, will terminate back to login page. \n");
			main_menu();
		}
	}
	else
	{
		printf("Unable to modify the staff, staff not found! \n");
		printf("Please check if staff ID is correct and retry. \n");
		printf("________________________________________________\n\n");
		staff_profile_deletion();
	}
}


//Admin modifies member profile.
void member_profile_modification_intro()
{
	printf("________________________________________________________________________________________________________________________\n\n");
	printf("____________________________________ \n");
	printf("|                                  | \n");
	printf("|   Member profile modification.   | \n");
	printf("|__________________________________| \n\n");
	member_profile_modification();
}
void member_profile_modification()
{
	char m_mod_directory[] = ("memberlist/");
	char m_mod_name[10] = "member";
	char m_txt[10] = ".txt";

	char mod_member_id[30];
	char n_member_name[30];
	char n_member_no[30];
	char n_member_bill[30];
	char n_toy_id[30];
	char n_a_paid[30];
	char n_p_date[30];
	char n_member_pw[30];

	int member_status;
	int admin_option;

	printf("Please enter the member ID to be modified: ");					//Ask for Member ID for modification.
	scanf(" %[^\n]s", &mod_member_id);

	strcat(m_mod_directory, m_mod_name);									//Merge for file name.
	strcat(m_mod_directory, mod_member_id);
	strcat(m_mod_directory, m_txt);

	member_status = remove(m_mod_directory);								//Deletes the file.

	if (member_status == 0)													//Ask for new member info.
	{
		printf("\nNow please enter new information for member ID %s. \n", mod_member_id);
		printf("__________________________________________________________ \n\n");
		printf("New Member Name: ");
		scanf(" %[^\n]s", &n_member_name);
		printf("New Contact Number: ");
		scanf(" %[^\n]s", &n_member_no);
		printf("New Billing address: ");
		scanf(" %[^\n]s", &n_member_bill);
		printf("New Toy ID (Mattel-1, Marvel-2, Lego-3, Hot Wheels-4, Disney-5): ");
		scanf(" %[^\n]s", &n_toy_id);
		printf("New Amount paid (MYR): ");
		scanf(" %[^\n]s", &n_a_paid);
		printf("New Payment date (dd/mm/yy): ");
		scanf(" %[^\n]s", &n_p_date);
		printf("New Member Password (Must be 5 digits): ");
		scanf(" %[^\n]s", &n_member_pw);

		FILE *fpmm;

		fpmm = fopen(m_mod_directory, "w");									//Writes new file.

		fprintf(fpmm, "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n");
		fprintf(fpmm, "|\n");
		fprintf(fpmm, "|		Member ID: @%s \t\n", mod_member_id);
		fprintf(fpmm, "|		Member Name: %s \t\n", n_member_name);
		fprintf(fpmm, "|		Contact Number: %s \t\n", n_member_no);
		fprintf(fpmm, "|		Billing address: %s \t\n", n_member_bill);
		fprintf(fpmm, "|		Toy ID: %s \t\n", n_toy_id);
		fprintf(fpmm, "|		Amount paid (MYR): RM%s \t\n", n_a_paid);
		fprintf(fpmm, "|		Payment date (dd/mm/yy): %s \t\n", n_p_date);
		fprintf(fpmm, "|		Member Password: $%s \t\n", n_member_pw);
		fprintf(fpmm, "|\n");
		fprintf(fpmm, "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| \n");


		rewind(fpmm);
		fclose(fpmm);
		printf("\nInformation of Member ID %s succesfully modified! \n", mod_member_id);
		timer(1);
		printf("__________________________________________________________\n");
		timer(1);
		printf("Input '0' to return to login page. \n\n");
		printf("|=================================|\n");
		printf("|                                 |\n");
		printf("|       0. Back to login.         |\n");
		printf("|_________________________________|\n\n");
		printf("Return to login page: ");
		scanf("%d", &admin_option);
		if (admin_option == 0)
		{
			main_menu();													//Exit to main menu.
		}
		else
		{
			printf("Invalid input, will terminate back to login page. \n");
			main_menu();
		}
	}
	else
	{
		printf("Unable to modify the member, member not found! \n");
		printf("Please check if member ID is correct and retry. \n");
		printf("________________________________________________\n\n");
		member_profile_deletion();
	}
}

//Admin searches and views staff/member profile.
void search_and_view_sprofile()
{
	char s_search_directory[] = ("stafflist/");
	char s_search_name[10] = "staff";
	char s_txt[10] = ".txt";
	
	char search_s_id[30];
	char staff_id[30];

	char staff_info;
	char admin_option;

	printf("Please enter the Staff ID to be searched and viewed: ");		//Ask for Staff IF to be viewed.
	scanf(" %s", &search_s_id);

	strcat(s_search_directory, s_search_name);								//Merge for file name.
	strcat(s_search_directory, search_s_id);
	strcat(s_search_directory, s_txt);

	FILE *fpss;

	fpss = fopen(s_search_directory, "r");									//Search for file.

	if (fpss == NULL)														//File not found.
	{
		printf("\nUnable to view due to search failure, incorrect Staff ID, please retry. \n");
		printf("Will now redirect you back to login page. \n");
		main_menu();
	}

	printf("\nProfile information of Staff %s:\n", search_s_id);
	while ((staff_info = fgetc(fpss)) != EOF)								//Show staff info.
	{
		printf("%c", staff_info);
	}

	fclose(fpss);

	printf("__________________________________________________________\n");
	printf("Input '0' to return to login page. \n\n");
	printf("|=================================|\n");
	printf("|                                 |\n");
	printf("|       0. Back to login.         |\n");
	printf("|_________________________________|\n\n");
	printf("Return to login page: ");
	scanf("%d", &admin_option);
	if (admin_option == 0)
	{
		main_menu();														//Exit to main menu.
	}
	else
	{
		printf("Invalid input, will terminate back to login page. \n");
		main_menu();
	}
}
void search_and_view_mprofile()
{
	char m_search_directory[] = ("memberlist/");
	char m_search_name[10] = "member";
	char m_txt[10] = ".txt";

	char search_m_id[30];
	char member_id[30];

	char member_info;
	char admin_option;

	printf("Please enter the Member ID to be searched and viewed: ");		//Ask for Member ID to be viewed.
	scanf(" %s", &search_m_id);

	strcat(m_search_directory, m_search_name);								//Merge for file name.
	strcat(m_search_directory, search_m_id);
	strcat(m_search_directory, m_txt);

	FILE *fpms;

	fpms = fopen(m_search_directory, "r");									//Search for file.

	if (fpms == NULL)														//File not found.
	{
		printf("\nUnable to view due to search failure, incorrect Member ID, please retry. \n");
		printf("Will now redirect you back to login page. \n");
		main_menu();
	}

	printf("\nProfile information of Member %s:\n", search_m_id);
	while ((member_info = fgetc(fpms)) != EOF)								//Show member info.
	{
		printf("%c", member_info);
	}

	fclose(fpms);
	timer(1);
	printf("__________________________________________________________\n");
	timer(1);
	printf("Input '0' to return to login page. \n\n");
	printf("|=================================|\n");
	printf("|                                 |\n");
	printf("|       0. Back to login.         |\n");
	printf("|_________________________________|\n\n");
	printf("Return to login page: ");
	scanf("%d", &admin_option);
	if (admin_option == 0)
	{
		main_menu();														//Exit to main menu.
	}
	else
	{
		printf("Invalid input, will terminate back to login page. \n");
		main_menu();
	}
}