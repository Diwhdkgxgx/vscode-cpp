#include <stdio.h>
#include <string.h>

typedef struct
{
    int sno;
    char sname[20];
    double math;
    double physics;
    double english;
} student;
student stu[3] = {{110, "张三", 86, 88, 77},
                  {120, "李四", 76, 98, 87},
                  {130, "王五", 100, 78, 97}};
int main()
{
    int i, tmp = 0, tmp1 = 0;
    double averge = 0, averge1 = 1000;
    for (i = 0; i < 3; i++)
    {
        if ((stu[i].math + stu[i].physics + stu[i].english) / 3 > averge)
        {
            averge = (stu[i].math + stu[i].physics + stu[i].english) / 3;
            tmp = i;
        }
        if ((stu[i].math + stu[i].physics + stu[i].english) / 3 < averge1)
        {
            averge1 = (stu[i].math + stu[i].physics + stu[i].english) / 3;
            tmp1 = i;
        }
    }
    printf("平均分最高的学生：");
    printf("学号:%d 姓名:%s 高数成绩:%.2lf 大物成绩:%.2lf 大英成绩:%.2lf\n", stu[tmp].sno, stu[tmp].sname, stu[tmp].math, stu[tmp].physics, stu[tmp].english);
    printf("平均分最低的学生：");
    printf("学号:%d 姓名:%s 高数成绩:%.2lf 大物成绩:%.2lf 大英成绩:%.2lf\n", stu[tmp1].sno, stu[tmp1].sname, stu[tmp1].math, stu[tmp1].physics, stu[tmp1].english);
}