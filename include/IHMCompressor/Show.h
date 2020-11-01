#ifndef SHOW
#define SHOW



void displayErrorMessageOpenFile    (void);
void cleanTerminal                  (void);



//...................OPERATING SYSTEM....................
#ifdef _WIN32
#define OPERATING_SYSTEM "win" //windows
#elif __linux__
#define OPERATING_SYSTEM "linux"
#elif __APPLE__
#define OPERATING_SYSTEM "mac"
#else
#define OPERATING_SYSTEM "unk" //systéme inconnu
#endif



#endif // !SHOW
