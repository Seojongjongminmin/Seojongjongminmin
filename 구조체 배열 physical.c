/* 신체검사 데이터용 구조체 배열 */

#pragma warning(disable:4996)

#include <stdio.h>

#define VMAX 21       /* 시력 최대 2.1 × 10 */



/*--- 신체검사 데이터형 ---*/

typedef struct {

    char    name[20];    /* 이름 */

    int    height;    /* 키 */

    double vision;       /* 시력 */

    char bloodtype[5]; /*혈액형*/

    double weight;/*몸무게*/

    double MaximumPressure;/*최고혈압*/

    double MinimumPressure;/*최저혈압*/

    double bloodPressure;/*정상혈압*/

} PhysCheck;



double makeBloodpressure(double max, double min)

{

    double MaximumPressure = max;

    double MinimumPressure = min;

    double bloodPressure;



    /*혈압 구하는 식*/

    bloodPressure = (MaximumPressure + 2 * MinimumPressure) / 3;//최대 + 최소*2 /3 

    return bloodPressure;

}

/*--- 키의 평균값을 구합니다. ---*/

double ave_height(const PhysCheck dat[], int n)

{

    int i;

    double sum = 0;



    for (i = 0; i < n; i++)

        sum += dat[i].height;



    return sum / n;

}



/*--- 시력 분포를 구합니다. ---*/

void dist_vision(const PhysCheck dat[], int n, int dist[])

{

    int i;



    for (i = 0; i < VMAX; i++)

        dist[i] = 0;



    for (i = 0; i < n; i++)

        if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0)

            dist[(int)(dat[i].vision * 10)]++;

}



/*--- 입력 함수 ---*/

void input_data(PhysCheck* data)

{

    double max, min;

    printf("혈액형, 몸무게, 최고혈압, 최저혈압을 차례대로 입력해주세요.\n");

    scanf("%s %lf %lf %lf", data->bloodtype, &data->weight, &max, &min);

    while (max <= min) { //최고혈압이 최저혈압보다 작거나 같은 경우 다시 입력받음

        printf("최고혈압이 최저혈압보다 작거나 같습니다. 다시 입력해주세요.\n");

        scanf("%lf %lf", &max, &min);

    }

    data->MaximumPressure = max;

    data->MinimumPressure = min;

    data->bloodPressure = makeBloodpressure(max, min); //혈압 구하기

}



int main(void)

{

    int i;

    PhysCheck x[] = {

       { "박현규",   162, 0.3,   "a", 0,0,0,0},

       { "함진아",   173, 0.7,   "a", 0,0,0,0},

       { "최윤미",   175, 2.0,   "a", 0,0,0,0},

       { "홍연의",   171, 1.5,   "a", 0,0,0,0},

       { "이수진",   168, 0.4,   "a", 0,0,0,0},

       { "김영준",   174, 1.2,   "a", 0,0,0,0},

       { "박용규",   169, 0.8,   "a", 0,0,0,0}

    };



    int nx = sizeof(x) / sizeof(x[0]);       /* 사람 수 */

    int vdist[VMAX];             /* 시력 분포 */



    for (i = 0; i < nx; i++) {

        printf("%s의 ", x[i].name);

        input_data(&x[i]); //입력 함수 호출

    }



    puts("■ □ ■  신체검사 표  ■ □ ■");

    puts("    이름            키   시력  혈액형 몸무게 최고혈압 최저혈압 정상혈압");

    puts("------------------------------------------------------------------------");

    for (i = 0; i < nx; i++) {

        printf("%-18.18s%4d%5.1f       %s   %.2lfkg %.2lf   %.2lf   %.2lf\n", x[i].name, x[i].height, x[i].vision, x[i].bloodtype, x[i].weight, x[i].MaximumPressure, x[i].MinimumPressure, x[i].bloodPressure);

    }

    printf("\n 평균 키 : %5.1f cm\n", ave_height(x, nx));



dist_vision(x, nx, vdist);          /* 시력 분포를 구합니다. */



    printf("\n 시력 분포\n");

    for (i = 0; i < VMAX; i++)

        printf("%3.1f ~ : %2d명\n", i / 10.0, vdist[i]);

    



    return 0;

}
