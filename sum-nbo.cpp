#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
	
	uint32_t res = 0;

	for (int i = 1; i<argc; i++) {
		uint32_t n;
		FILE* fp = fopen(argv[i], "r");
		if(fp == NULL) {
			printf("\n %s: 파일 입력 에러", argv[i]);
			return -1;
		}
	
		size_t read = fread(&n, 1, sizeof(n), fp);
		if(read < sizeof(n)){
			printf("\n %s: 파일이 4바이트보다 작습니다.", argv[i]);
			return -1;
		}
		
		n = ntohl(n);

		if(i != 1) {
			printf(" + ");
		}	
		printf("%d(0x%08x)", n, n);

		res += n;
		fclose(fp);
	}

	printf(" = %d(0x%08x)", res, res);
	return 0;	
}
