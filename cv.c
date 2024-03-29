/*
* This is my "C"urriculum Vitae
* Based on hacker news post of the resume of https://github.com/klange
* Shows knowledge in pointers, structs and references.
* TODO: String formatting and a unified print function
*/

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
typedef item_t lang_t;
typedef item_t honor_t;


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

/* Employment History */
job_t capital_one = {
        .company  = "Capital One",
        .location = "Tysons, Virginia",
        .title    = "Software Engineering Intern",
        .started  = 1433116800,
        .left     = CURRENT,
        .description = {
                "Coded and designed in a team of 4 to build Dash, a sprint tracking web application for managers of agile teams.",
                "Developed Dash full-stack utilizing Spring, Sass, AngularJS, Jenkins, Hudson, SonarQube, Splunk, JIRA and Git.",
                "Provided critical input in design and UI. Assisted other interns with UI/UX fundamentals.",
                NULL
        }
};

job_t vagabond_vending = {
        .company  = "Vagabond Vending",
        .location = "Washington D.C.",
        .title    = "Web Development Intern",
        .started  = 1398988800,
        .left     = 1401667200,
        .description = {
                "Created admin pages using company API and jQuery to add functionality and refactored existing code for readability.",
                "Coded in HTML, CSS, Javascript and used Git and Heroku.",
                NULL
        }
};

job_t bio_lab = {
        .company  = "W&M Developmental Biology Lab",
        .location = "Williamsburg, Virginia",
        .title    = "Programmer",
        .started  = 1378166400,
        .left     = 1386979200,
        .description = {
                "Created scripts to access genome databases and apply tags and markers to RNA sequences.",
                "Coded in Python with brief ventures into SQL and Perl.",
                NULL
        }
};

job_t geico = {
        .company  = "GEICO",
        .location = "Chevy Case, Maryland",
        .title    = "User Experience Intern",
        .started  = 1370390400,
        .left     = 1377216000,
        .description = {
                "Designed, executed, and analyzed a usability test to inform future mobile designs.",
                "Led teams for 3 corporate social responsibility projects to raise money for the National Children’s Hospital.",
                "Conducted an expert website review with customer journey maps and presented findings to management.",
                NULL
        }
};

job_t * jobs[] = {
        &capital_one,
        &vagabond_vending,
        &bio_lab,
        &geico,
        NULL
};

/* Languages */
lang_t languages = {
        .description = {
                "Proficient: Python, HTML, CSS (Sass and LESS), LaTex.",
                "Familiar: Java, JavaScript (jQuery and AngularJS), PHP, C, C++ and SQL.",
                "Natural: English (native), Spanish (intermediate), Korean (intermediate).",
                NULL
        }
};

lang_t * langs[] = {
        &languages,
        NULL
};

/* Honors */
honor_t honors = {
        .description = {
                "1st place at hacck.io (2014 UVA Hackathon) for Givr. http://devpost.com/software/givr",
				"Best Mobile Hack at UVAHacks2015 for Boka. https://github.com/dhpark/Boka",
				"3rd place at TribeHacks (2014 W&M Hackathon) for Huddle. http://devpost.com/software/huddle",
				"2nd place at Microsoft Coding Challenge 2014.",
				"2nd place at Invictus Case Competition 2015.",
				"69th Virginia Student Lt. Governor.",
				"Represented the U.S. at 2012 Intel Science fair for creating a novel treatment and diagnostic for pancreatic cancer.",
				"Captain of S.M.I.L.E.S Crew, William & Mary’s breakdancing crew. Performed in 2014 Vans Warped Tour. ",
                NULL
        }
};

honor_t * hon[] = {
        &honors,
        NULL
};

void print_company(item_t * item) {
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

void print_blurb(item_t * item){
		const char ** desc;
        for (desc = item->description; *desc; desc++) {
                printf("- %s\n", *desc);
        }
}

int main(int argc, char ** argv) {

        school_t ** s = school;
		job_t ** j = jobs;
		lang_t ** l = langs;
		honor_t ** h = hon;

        puts("");
        printf("%s\n%s\n%s\n\n", name, email, address);

		puts("-Education-\n");
		while (*s) {
			print_company(*s);
			s++;
		}
 
        puts("-Employment-\n");

		while (*j) {
			print_company(*j);
			j++;
		}

		puts("-Languages-\n");

		while (*l) {
			print_blurb(*l);
			l++;
		}

		puts("\n-Honors-\n");

		while (*h) {
			print_blurb(*h);
			h++;
		}
}