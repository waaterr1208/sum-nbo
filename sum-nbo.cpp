#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <netinet/in.h>

uint32_t trans(FILE* fp) {
	uint32_t n;
	size_t read = fread(&n, 1, sizeof(n), fp);
	if(read != sizeof(n)) {
		printf("파일이 4바이트가 아닙니다");
		return -1;
	}
	return ntohl(n);
}

int main(int argc, char* argv[]) {
	
	uint32_t res = 0;

	for (int i = 1; i<argc; i++) {
		FILE* fp = fopen(argv[i], "r");
		
		if(i != 1) {
			printf(" + ");
		}

		if(fp == NULL) {
			printf("파일 입력 에러");
			return -1;
		}
		
		uint32_t num = trans(fp);
		printf("%d(0x%08x)", num, num);

		res += num;
		fclose(fp);
	}

	printf(" = %d(0x%08x)", res, res);
	return 0;	
}
