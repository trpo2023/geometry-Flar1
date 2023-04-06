#define ascii_bracket_left 40
#define ascii_bracket_right 41
#define zero 48
#define nine 57
#define M_PI 3.14159265358979323846
typedef struct point {
    double x;
    double y;
} point;

typedef struct circle {
    point center;
    double radius;
} circle;
int left_bracket(char* str);
int right_bracket(char* str);
void strtolower(char* str);
int isArguments(char* str);
int isEnd(char* str);
int issEnd(char* str);
int isObject(char* str);
int printErrors(char* str, int countObj);
void zeero(char* mass);