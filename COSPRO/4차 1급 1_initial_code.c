#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN (3906)
char* vowels[5] = {"A", "E", "I", "O", "U"};
char* words[3906];
int words_idx = 0;

void create_words(int lev, char* str) {
    words[words_idx++] = str;
    for (int i = 0; i < 5; i++) {
        if (lev < 5) {
            char* new_str = (char*)malloc(sizeof(char)*(lev+2));
            strcpy(new_str, str);
            strcat(new_str, vowels[i]);
            create_words(lev, new_str);
        }
    }
}

int solution(char* word) {
    int answer = 0;
    words_idx = 0;
    create_words(0, "");
    for (int i = 0; i < words_idx; i++)
        if (strcmp(word, words[i]) == 0) {
            answer = i;
            break;
        }
    return answer;
}

// 아래는 테스트케이스 출력을 해보기 위한 코드입니다. 아래에는 잘못된 부분이 없으니, 위의 코드만 수정하세요.
int main() {
    char* word1 = "AAAAE";
    int ret1 = solution(word1);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret1);

    char* word2 = "AAAE";
    int ret2 = solution(word2);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret2);
    return 0;
}