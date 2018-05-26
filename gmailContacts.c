#include <stdio.h>
#include <libgcal/gcalendar.h>
#include <libgcal/gcontact.h>

int main(int argc, char **argv)
{
        gcal_t gcal;
        gcal_contact_t contact;
        struct gcal_contact_array all_contacts;
        size_t i;

        /* Create a gcal 'object' and authenticate with server */
        if(!(gcal = gcal_new(GCONTACT)))
	{
		printf("Unable to create gcal_new()\n");
                exit(1);
	}
        if(argc != 3)
	{
		printf("******* [USAGE] : %s <username> <password> *******\n", argv[0]);
        	gcal_delete(gcal);
		exit(1);
	}
	if(gcal_get_authentication(gcal, argv[1], argv[2]) != 0)
	{
		printf("Authentication Failed!!!\n");
        	gcal_delete(gcal);
		exit(1);
	}

        /* Get all contacts and print its name/prefered email/updated time */
        if(gcal_get_contacts(gcal, &all_contacts) != 0)
	{
		printf("Failed to retrieve contacts list!!!\n");
        	gcal_delete(gcal);
		exit(1);
	}

        for (i = 0; i < all_contacts.length; ++i) 
	{
                contact = gcal_contact_element(&all_contacts, i);
                if(!contact)
                	break;

                //printf("CONTACT: %d\ttitle:%s\temail:%s\tupdated:%s\n", i, gcal_contact_get_title(contact), gcal_contact_get_email(contact), gcal_contact_get_updated(contact));
                printf("%d.\t%s\n", i+1, gcal_contact_get_email(contact));
        }

        /* Cleanup */
        gcal_cleanup_contacts(&all_contacts);
        gcal_delete(gcal);

        return 0;
}
