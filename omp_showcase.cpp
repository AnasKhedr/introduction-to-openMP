#include <iostream>
#include <omp.h>       // #pragma مش ضروريه عشان سطر  omp_get_thread_num() دي عشان نستخدم دوال زي
#include <time.h>
using namespace std;

 
int arr[100000000];
void main(){
	clock_t tStart = clock();

	#pragma omp parallel for        // حولوها كمنت عشان تشوفو التنفيذ في السريال عمال ازاي
	for (int i = 0; i < 100000000; i++){
		arr[i] = i;
		//cout << "thread id: " << omp_get_thread_num() << endl; //  للتوضيح فقط, لو رقم كل ثرد بيتغير يبقي كده انتو شغالين بارالل صح ولو ثالت عند 0 و دي رقم الثرد الاساسيه يبقي كده انتو شغالين سيريال
															// just for show, if you find that the thread id is changing that measns you're running in parallel but of you're stuck at id = 0 that would mean that the main thread (which has id = zero) is running the entire program by itself hence, you running in serial.
															// ابقو حولوها كمنت عشان هتسحب وقت كبير جدا
	}
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	system("pause");

}