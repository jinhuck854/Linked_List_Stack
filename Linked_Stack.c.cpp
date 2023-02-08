#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode { // 연결 리스트 스택
	int* top;
	element data;
	struct StackNode* link;
}StackNode;


void createStack(StackNode** top) { // 초기화
	*top = NULL;
}

int is_empty(StackNode* S) { // is_Empty, top 값이 NULL일 때
	return (S->top == NULL);
}

void push(StackNode** top, element value) { // PUSH
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = value;
	if (!temp){ // 변수가 정상적으로 만들어지지 않았을 때
		printf("변수가 정상적으로 만들어지지 않았습니다.\n");
		exit(1);
	}
	else { // 정상적으로 만들어 질 때
		temp->link = *top;
		*top = temp;
	}
}

element pop(StackNode** top) { // POP
	element item; // return 해주는 값
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode)); //삭제 할 변수
	if (is_empty(*top)) {
		exit(1);
	}
	else {
		temp = *top; // top을 임시 변수 temp에 저장
		item = (*top)->data; // top 값을 반환하기 위해 top의 값을 item에 저장
		*top = (*top)->link; // top 변경
		free(temp);  // temp 변수 삭제
		return item; // item(top 값) 반환
	}
}

element peek(StackNode** top) { // PEEK
	if (*top == NULL) { // Top == NULL일 때 문장 출력 후 프로그램 종료
		printf("\n\n Stack is empty !\n");
		exit(1);
	}
	else { // NULL이 아닐 때 top의 data를 반환
		return ((*top)->data); // top의 데이터 값을 반환
	}
}

void printStack(StackNode** top) { // 스택의 top에서부터 bottom까지 모든 element 출력
	printf("printStack : ");
	for (StackNode* p = *top; p != NULL; p = p->link) // top부터 시작해서 NULL이 될 때까지 반복하여 link를 타고 이동
		printf("%d-> ", p->data);
	printf("NULL \n\n");
}

void deleteStack(StackNode** top) { //스택의 top에서부터 bottom까지 모든 element 출력 후, 노드 삭제
	StackNode* p = *top; // top값을 저장하는 변수 p
	while (p != NULL) { // p 가 NULL값이 될 때까지 반복
		StackNode* temp = p; // temp 는 p값을 가짐
		p = p->link; // p 는 링크를 타고 다음 노드로 넘어감
		printf("DeleteStack : %d\n", temp -> data); // temp값 z출력
		free(temp); // temp 삭제
	}

	printf("\n==========삭제 완료==========\n"); // 모든 노드 삭제 완료 시 출력
}

void start() {
	element item;
	StackNode* top;
	createStack(&top); // 초기화
	printf("** 연결 스택 연산 **\n\n");

	for (int i = 0; i < 5; i++) { // PUSH 5번 실행
		push(&top, i);
	}

	printStack(&top); // Top 부터 bottom까지 모든 값을 출력

	item = peek(&top); // top 한 번 출력 
	printf("PEEK : %d\n\n", item);

	for (int j = 0; j < 5; j++) { // POP 5번 실행
		item = pop(&top);
		printf("POP => %d\n", item);
	}

	deleteStack(&top); // 남아있는 top 부터 bottom 까지 모든 값 출력 후 노드 삭제

}

int main(void) {
	start();
	return 0;
}