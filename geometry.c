#include <stdio.h>
#include <string.h>
typedef struct Point
{
	float x;
	float y;
} Point;
struct Circle
{
	Point center;
	float radius;
};
  
int main()
{
    char * filename = "input.txt";
    char buffer[256];
    FILE *fp = fopen(filename, "r");
    if(fp)
    {
        while((fgets(buffer, 256, fp))!=NULL)
        {
            printf("%s", buffer);
        }
        fclose(fp);
    } 
}
