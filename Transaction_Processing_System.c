/* Name: Alangi Derick aka d3r1ck */
/* Date and Time: 06th Dec, 2013 at 9:25pm */
/* File: Transaction_Processing_System.c */
/* Description: This program reads a random access file sequentially, updates data
			already written to the file, creates new data to be placed in the
			file, and deletes data previously in the file. */
/* Further: Bank Account Program. */
/* version: TSv1.0 */


/* Headers Include */

#include<stdio.h>

/* Macro definition includes */
//#define void undefined

/* clientData structure definition */
struct clientData {
	int accNum;	/* Account Number */
	char lastName[20];	/* account last name */
	char firstName[10];	/* account first name */
	double balance;	/* account balance */
	};	/* end of structure for clientData

/* Prototypes */
int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
void newRecord(FILE *fPtr);

//main function definition
int main(void)
{
	FILE *cfPtr;	/* Credit.dat file pointer */
	int choice; 	/* user's choice */
	

	/* fopen opens the file; exits if file cannot be opened */
	if((cfPtr = fopen("credit.dat", "rb+")) == NULL) {
		printf("File could not be opened.\n");
	}/* end of if */
	else {
		/* enable user to specify action */
		while((choice = enterChoice()) != 5) {
			switch(choice){
				/* Create text file from record file */
				case 1:
					textFile(cfPtr);
					break;
				/*update record */
				case 2:
					updateRecord(cfPtr);
					break;
				/* create record */
				case 3:
					newRecord(cfPtr);
					break;
				/* delete existing record */
				case 4:
					deleteRecord(cfPtr);
					break;
				/* Display message if user does not select valid choice */
				default:
					printf("Incorrect Choice\n");
					break;
				} /* end of switch */
			} /* end of while */
		fclose(cfPtr);	/* fclose closes the file */
		} /* end of else */
		
		return 0; 	/* indicates successful termination */
}	/* end of main */

/* create formatted text file for printing */
void textFile(FILE *readPtr)
{
	FILE *writePtr;	/* accounts.txt file pointer */
	
	/* create clientDate with default information */
	struct clientData client = {0, "", "", 0.0};
	
	/* fopen opens the file; exits if file cannot be opened */
	if((writePtr = fopen("accounts.txt", "w")) == NULL){
		printf("File could not be opened.\n");
		}	/* end if */
	else {
		rewind(readPtr);	/* sets pointer to the beginning of the file */
		fprintf(writePtr, "%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");
	
	/* copy all records from random-access file into text file */
	while(!feof(readPtr)){
		fread(&client, sizeof(struct clientData), 1, readPtr);

		/* write single record to text file */
		if(client.accNum != 0){
			fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n", client.accNum, client.lastName, client.firstName, client.balance);
		}	/* end if */
	}	/* end while */
	fclose(readPtr);
	fclose(writePtr);	/* fclose closes the file */
	}	/* end else */
}	/* end function textFile */


/* update balance in record */
void updateRecord(FILE *fPtr)
{
	int account;	/* account number */
	double transaction;	/* transaction amount */
	
	/* create clientData with no information */
	struct clientData client = {0, "", "", 0.0};

	/* obtain number of account to update */
	printf("Enter account to update (1 - 100): ");
	scanf("%d", &account);
	
	/* move file pointer to correct record in file */
	fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);

	/* read record from file */
	fread(&client, sizeof(struct clientData), 1, fPtr);

	/* display error if account does not exist */
	if(client.accNum == 0){
		printf("Account #%d has no information.\n", account);
	}	/* end if */
	else {	/* update record */
		printf("%-6d%-16s%-11s%10.2f\n\n", client.accNum, client.lastName, client.firstName, client.balance);

		/* request transaction amount from user */
		printf("Enter charge ( + ) or payment ( - ): ");
		scanf("%lf", &transaction);
		client.balance += transaction;	/* update record balance */
		
		printf("%-6d%-16s%-11s%10.2f\n", client.accNum, client.lastName, client.firstName, client.balance);

		/* move file pointer to correct record in file */
		fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);

		/* write update record over old record in file */
		fwrite(&client, sizeof(struct clientData), 1, fPtr);
		}	/* end else */
	}	/* end function updateRecord */

/* delete an existing record */
void deleteRecord(FILE *fPtr)
{
	struct clientData client;	/* stores record from file */
	struct clientData blankClient = {0, "", "", 0.0};	/* blank client */
	
	int accountNum;	/* account number */
	
	/* obtain number of account to delete */
	printf("Enter account number to delete (1 - 100): ");
	scanf("%d", &accountNum);
	
	/* move file pointer to correct record in file */
	fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);
	
	/* read record from file */
	fread(&client, sizeof(struct clientData), 1, fPtr);
	
	/* displays error if record does not exist */
	if(client.accNum == 0){
		printf("Account %d does not exist .\n", accountNum);
	}	/* end if */
	else {	/* delete record*/
		/* move file pointer to correct record in file */
		fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);
		
		/* replace existing record with blank record */
		fwrite(&blankClient, sizeof(struct clientData), 1, fPtr);
		}	/* end else */
	}	/* end function deleteRecord */
	
/* create and insert record */
void newRecord(FILE *fPtr)
{
	/* create clientData with default information */
	struct clientData client = {0, "", "", 0.0};
	
	int accountNum;	/* account number */
	
	/* obtain number of account to create */
	printf("Enter new account number ( 1 - 100): ");
	scanf("%d", &accountNum);
	

	/* move file pointer to correct record in file */
	fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), SEEK_SET);
	
	/* read record from file */
	fread(&client, sizeof(struct clientData), 1, fPtr);
	

	/* display error if account already exists */
	if(client.accNum != 0){
		printf("Account #%d already contains information.\n", client.accNum);
	}	/* end if */
	else {	/* create record */
		/* user enters last name, first name and balance */
		printf("Enter lastname, firstname, balance\n? ");
		scanf("%s%s%lf", &client.lastName, &client.firstName, &client.balance);
	
		client.accNum = accountNum;
	
		/* move file pointer to correct record in file */
		fseek(fPtr, (client.accNum - 1) * sizeof(struct clientData), SEEK_SET);

		/*insert record in file */
		fwrite(&client, sizeof(struct clientData), 1, fPtr);
		}	/* end else */
	}	/* end function newRecord */

/* enable user to input menu choice */
int enterChoice(void)
{
	int menuChoice;	/* variable to store user's choice */
	
	/* display available options */
	printf("\nEnter your choice\n"
		  "1 - store a formatted text file of accounts called\n"
		  "	\"accounts.txt\" for printing\n"
		  "2 - update an account\n"
		  "3 - add a new account\n"
		  "4 - delete an account\n"
		  "5 - end program\n? ");
	scanf("%d", &menuChoice);	/* receive choice from user */
	return menuChoice;
}/* end of function enterChoice */
