#ifndef Features
#define Features

void StateList(void);
void Recommend(void);
void Schemes(void);
void Profit(void);

void trim(char *s);
void flush_input(void);
void waitforenter(void);
int str_icmp(const char *a, const char *b);
void showStates(void);
void ShowCrops(void);
int select_state(void);
int selectcity(int state_idx);
int selectcrop(void);
void crop_report(int idx);

#endif
