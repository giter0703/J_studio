#include <stdio.h>
#include <limits.h>
#include <string.h>
#define SIZE 4

// 프로세스 구조체 정의
struct Process {
    int id;             // 프로세스 ID
    int arrival_time;    // 도착 시간
    int burst_time;      // 실행 시간
    int remaining_time;  // 남은 실행 시간
    int completion_time; // 완료 시간
    int waiting_time;    // 대기 시간
    int turnaround_time; // 반환 시간
    int is_completed;    // 완료 여부
};

// SRTF 스케줄링 수행 함수
void calculateTimes(struct Process processes[], int n) {
    int completed = 0, current_time = 0;
    int min_remaining_time, min_index;

    printf("\n[실행 순서] ");
    while (completed < n) {
        min_remaining_time = INT_MAX;
        min_index = -1;

        // 도착한 프로세스 중 남은 시간이 가장 짧은 프로세스를 찾음
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time &&
                !processes[i].is_completed &&
                processes[i].remaining_time < min_remaining_time) {
                min_remaining_time = processes[i].remaining_time;
                min_index = i;
            }
        }

        if (min_index == -1) { // 실행할 프로세스가 없으면 시간 증가
            current_time++;
            continue;
        }

        // 선택된 프로세스를 1초 동안 실행
        printf("P%d ", processes[min_index].id); // 실행 순서 출력
        processes[min_index].remaining_time--;
        current_time++;

        // 프로세스가 완료된 경우 처리
        if (processes[min_index].remaining_time == 0) {
            processes[min_index].is_completed = 1;
            completed++;

            processes[min_index].completion_time = current_time;
            processes[min_index].turnaround_time =
                processes[min_index].completion_time - processes[min_index].arrival_time;
            processes[min_index].waiting_time =
                processes[min_index].turnaround_time - processes[min_index].burst_time;
        }
    }
    printf("\n");
}

// 결과 출력 함수
void printResults(struct Process processes[], int n) {
    // 열 헤더 출력
    printf("\n%s %15s %15s %20s %20s %15s\n", 
           "PID", "Arrival Time", "Burst Time", 
           "Completion Time", "Turnaround Time", "Waiting Time");

    // 각 프로세스의 정보 출력
    for (int i = 0; i < n; i++) {
        printf("%d %15d %15d %20d %20d %15d\n",
               processes[i].id,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               processes[i].turnaround_time,
               processes[i].waiting_time);
    }
}


int main() {
    struct Process processes[SIZE];

    // 프로세스 정보 입력
    for (int i = 0; i < SIZE; i++) {
        processes[i].id = i + 1;
        printf("프로세스 %d의 도착 시간과 실행 시간을 입력하세요: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].is_completed = 0;
    }

    // 스케줄링 수행 및 결과 출력
    calculateTimes(processes, SIZE);
    printResults(processes, SIZE);

    return 0;
}
