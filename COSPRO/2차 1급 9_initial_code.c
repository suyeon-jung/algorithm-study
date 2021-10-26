#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool solution(char* password) {
    int length = strlen(password);
    for(int i = 0; i < length - 2; ++i){
        int firstCheck = password[i + 1] - password[i];
        int secondCheck = password[i] - password[i + 1];
        if(firstCheck == secondCheck && (firstCheck == 1 || firstCheck == -1))
            return false;
    }
    return true;
}

// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다. main함수는 잘못된 부분이 없으니, solution함수만 수정하세요.
int main() {
    char* password1 = "cospro890";
    bool ret1 = solution(password1);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %s 입니다.\n", ret1 == true ? "true" : "false");

    char* password2 = "cba323";
    bool ret2 = solution(password2);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %s 입니다.\n", ret2 == true ? "true" : "false");
}