- char* str = “string”; 가능 → 얕은 복사
- char str[80] = “string” → 깊은 복사
- 상수는 컴파일 시 특정 공간에 할당된다
- strcpy, strncpy, strcat, strncat, strlen, strcmp 함수
- auto, static, register 변수
- char animal[5][20] → 20개의 덩어리가 5개
- 

---

### 자습

- 비트 - 바이트 주소공간과 저장할 수 있는 숫자의 차이와 개념
- stringstream 사용법
- rbegin, rend 활용법
- string 메소드
- <cctype>
    
    ```
    string solution(string s) {
        string answer = "";
    
        answer += toupper(s[0]);
        for (int i = 1; i < s.size(); i++)
            s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);
    
        return answer;
    }
    ```
    
-