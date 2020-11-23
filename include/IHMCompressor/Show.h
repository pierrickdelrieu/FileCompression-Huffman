#ifndef SHOW
#define SHOW


extern void displayErrorMessageOpenFile    (void);

extern void cleanTerminal                  (void);

extern void displayErrorMemoryAllocation   (void);

extern int  stopExe                        (int secTime);


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
