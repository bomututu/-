#include <stdio.h>
#include <stdlib.h>

main()
{
    int tizhong, tizhi, high, age;
    char sex;
    float bmr1, bmr2, tdee, A;
    int working, workingdata;

    printf("依次输入信息 :\n性别(男用M表示\\女用W表示) 、年龄(岁) 、体重(kg)、体脂率(不写百分号）、身高(cm)\n中间用空格隔开，不知道体脂率则填0，填写时不带单位\n示例：M 18 60 18 172       (男 年龄18岁 体重60公斤 体脂率18% 身高172cm)\n");
    scanf("%c %d %d %d %d", &sex, &age, &tizhong, &tizhi, &high);
    printf("\n\n选择自己的锻炼情况(填写序号1 2 3 4 5)\n1     久坐上班族，运动很少\n2     每周1-3次轻度运动\n3    每周3-5次中度运动\n4    每周6-7次高强度运动或体力劳动职业\n5      每天运动两次\n");
    scanf("%d", &working);

    if (sex == 'M')                                                //在不知道体脂率的情况下对BMR进行计算
    {
        bmr1 = (10 * tizhong) + (6.25 * high) - (5 * age) + 5;
    }
    else if (sex == 'W')
    {
        bmr1 = (10 * tizhong) + (6.25 * high) - (5 * age) - 161;
    }

    bmr2 = 370 + 21.6*tizhong*(1 - (tizhi/100.0));                  //在知道体脂率的情况下对BMR进行计算

    if (working == 1)                  //判断运动系数
        workingdata = 1.2;
    else if (working == 2)
        workingdata = 1.375;
    else if (working == 3)
        workingdata =  1.55;
    else if (working == 4)
        workingdata = 1.725;
    else if (working == 5)
        workingdata = 1.9;

    if (tizhi != 0)                     //计算TDEE
    {
        tdee = bmr1*workingdata;
        printf("\nTDEE = %6.2f", tdee);
    }
    else
    {   
        tdee = bmr2*workingdata;
        printf("\nTDEE = %6.2f", tdee);
    }

    A = tdee*0.8;                   //计算每天摄入热量

    printf("\n每天需要摄入热量为 : %6.2f Kj\n", A);
    printf("指导建议 :\n\t减脂期间，每天脂肪摄入量%.1f克，剩下的热量供给碳水即，蛋白质摄入量%.1f ~ %.1f克\n\n", (A*0.35)/9, (tizhong*1.1), 2*(tizhong*1.1));
    printf("\n\n信息来源 : https://zhuanlan.zhihu.com/p/423799196\n\n\n\n");

    system("pause");
    return 0;
}