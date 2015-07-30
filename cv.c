
#include <stdio.h>
#include <time.h>

typedef struct {
        union {
                const char * company;
                const char * school;
                const char * project;
        };
        union {
                const char * location;
                const char * url;
        };
        union {
                const char * title;
                const char * degree;
        };

        time_t started;
        time_t left;

        const char * description[];
} item_t;

typedef item_t job_t;
typedef item_t school_t;
typedef item_t project_t;

#define CURRENT 0 

/* Contact Information */
const char * name    = "Daniel Park";
const char * email   = "dhpark01@email.wm.edu";
const char * address = "4906 Sunset Lane\n"
                       "Annandale, VA, 22003";
/* Education */
school_t williammary = {
        .school   = "College of William & Mary",
        .location = "Williamsburg, VA",
        .degree   = "Pursuing a BS in Computer Science",
        .started  = 1345766400,
        .left     = CURRENT,
        .description = {
                "Class of 2016, 3.4 GPA Cumulative.",
                NULL
        }
};

school_t * school[] = {
	&williammary,
	NULL
};

void print_item(item_t * item) {
        char started[100];
        char left[100];
        struct tm * ti;

        printf("%s at %s - %s\n", item->title, item->company, item->location);

        ti = localtime(&item->started);
        strftime(started, sizeof(started), "%B %d, %Y", ti);

        if (item->left == CURRENT)  {
                printf("%s to now\n", started);
        } else {
                ti = localtime(&item->left);
                strftime(left, sizeof(left), "%B %d, %Y", ti);
                printf("%s to %s\n", started, left);
        }

        const char ** desc;
        for (desc = item->description; *desc; desc++) {
                printf("- %s\n", *desc);
        }

        puts("");
}

int main(int argc, char ** argv) {

        school_t ** s = school;

        puts("");
        printf("%s\n%s\n%s\n\n", name, email, address);

        puts("Education");
		
		while (*s) {
			puts("");
			print_item(*s);
			s++;
		}
}