#include<stdio.h>

/*1行2列*/
struct mat12 {
	float _11, _12;
};
/*2行1列*/
struct mat21 {
	float _11,
		  _21;
};
/*2行2列*/
struct mat22 {
	float _11, _12,
		  _21, _22;
};
/*3行3列*/
struct mat33 {
	float _11, _12, _13,
		  _21, _22, _23,
		  _31, _32, _33;
};
/*4行4列*/
struct mat44{
	float _11, _12, _13, _14,
		  _21, _22, _23, _24,
		  _31, _32, _33, _34,
		  _41, _42, _43, _44;
};
/*1行3列*/
struct mat13 {
	float _11, _12, _13;
};
/*3行1列*/
struct mat31 {
	float _11,
		  _21,
		  _31;
};
/*2行3列*/
struct mat23 {
	float _11, _12, _13,
		  _21, _22, _23;
};
/*3行2列*/
struct mat32 {
	float _11, _12,
		  _21, _22,
		  _31, _32;
};

FILE* fp;
int mulmat1() {
	mat22 A, B, C;
	//読み込み
	fopen_s(&fp, "mat1.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f%f",
			&A._11, &A._12, &A._21, &A._22);
	}
	fopen_s(&fp, "mat2.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f%f",
			&B._11, &B._12, &B._21, &B._22);
	}
	//計算
	C._11 = A._11 * B._11 + A._12 * B._21;
	C._12 = A._11 * B._12 + A._12 * B._22;
	C._21 = A._21 * B._11 + A._22 * B._21;
	C._22 = A._21 * B._12 + A._22 * B._22;
	//書き込み
	fopen_s(&fp, "matANS.txt", "w");
	if (fp == NULL) return 1;
	else {
		fprintf_s(fp, "%3.2f  %3.2f\n\n%3.2f  %3.2f",
			C._11, C._12, C._21, C._22);
		fclose(fp);
		return 0;
	}

}

int mulmat2() {
	mat33 D, E, F;
	//読み込み
	fopen_s(&fp, "mat1.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f%f%f%f%f%f%f",
			&D._11, &D._12, &D._13, &D._21, &D._22, &D._23, &D._31, &D._32, &D._33);
		fclose(fp);
	}
	fopen_s(&fp, "mat2.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f%f%f%f%f%f%f",
			&E._11, &E._12, &E._13, &E._21, &E._22, &E._23, &E._31, &E._32, &E._33);
		fclose(fp);
	}
	//計算
	F._11 = D._11 * E._11 + D._12 * E._21 + D._13 * E._31;
	F._12 = D._11 * E._12 + D._12 * E._22 + D._13 * E._32;
	F._13 = D._11 * E._13 + D._12 * E._23 + D._13 * E._33;
	F._21 = D._21 * E._11 + D._22 * E._21 + D._23 * E._31;
	F._22 = D._21 * E._12 + D._22 * E._22 + D._23 * E._32;
	F._23 = D._21 * E._13 + D._22 * E._23 + D._23 * E._33;
	F._31 = D._31 * E._11 + D._32 * E._21 + D._33 * E._31;
	F._32 = D._31 * E._12 + D._32 * E._22 + D._33 * E._32;
	F._33 = D._31 * E._13 + D._32 * E._23 + D._33 * E._33;
	//書き込み
	fopen_s(&fp, "matANS.txt", "w");
	if (fp == NULL) return 1;
	else {
		fprintf_s(fp, "%3.2f  %3.2f  %3.2f\n\n%3.2f  %3.2f  %3.2f\n\n%3.2f  %3.2f  %3.2f",
			F._11, F._12, F._13, F._21, F._22, F._23, F._31, F._32, F._33);
		fclose(fp);
		return 0;
	}
}

int mulmat3() {
	mat44 G, H, I;
	//読み込み
	fopen_s(&fp, "mat1.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f",
			&G._11, &G._12, &G._13, &G._14, &G._21, &G._22, &G._23, &G._24,
			&G._31, &G._32, &G._33, &G._34, &G._41, &G._42, &G._43, &G._44);
		fclose(fp);
	}

	fopen_s(&fp, "mat2.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f",
			&H._11, &H._12, &H._13, &H._14, &H._21, &H._22, &H._23, &H._24,
			&H._31, &H._32, &H._33, &H._34, &H._41, &H._42, &H._43, &H._44);
		fclose(fp);
	}
	//計算
	I._11 = G._11 * H._11 + G._12 * H._21 + G._13 * H._31 + G._14 * H._41;
	I._12 = G._11 * H._12 + G._12 * H._22 + G._13 * H._32 + G._14 * H._42;
	I._13 = G._11 * H._13 + G._12 * H._23 + G._13 * H._33 + G._14 * H._43;
	I._14 = G._11 * H._14 + G._12 * H._24 + G._13 * H._34 + G._14 * H._44;
	I._21 = G._21 * H._11 + G._22 * H._21 + G._23 * H._31 + G._24 * H._41;
	I._22 = G._21 * H._12 + G._22 * H._22 + G._23 * H._32 + G._24 * H._42;
	I._23 = G._21 * H._13 + G._22 * H._23 + G._23 * H._33 + G._24 * H._43;
	I._24 = G._21 * H._14 + G._22 * H._24 + G._23 * H._34 + G._24 * H._44;
	I._31 = G._31 * H._11 + G._32 * H._21 + G._33 * H._31 + G._34 * H._41;
	I._32 = G._31 * H._12 + G._32 * H._22 + G._33 * H._32 + G._34 * H._42;
	I._33 = G._31 * H._13 + G._32 * H._23 + G._33 * H._33 + G._34 * H._43;
	I._34 = G._31 * H._14 + G._32 * H._24 + G._33 * H._34 + G._34 * H._44;
	I._41 = G._41 * H._11 + G._42 * H._21 + G._43 * H._31 + G._44 * H._41;
	I._42 = G._41 * H._12 + G._42 * H._22 + G._43 * H._32 + G._44 * H._42;
	I._43 = G._41 * H._13 + G._42 * H._23 + G._43 * H._33 + G._44 * H._43;
	I._44 = G._41 * H._14 + G._42 * H._24 + G._43 * H._44 + G._44 * H._44;

	//書き込み
	fopen_s(&fp, "matANS.txt", "w");
	if (fp == NULL) return 1;
	else {
		fprintf_s(fp, "%3.2f  %3.2f  %3.2f  %3.2f  \n\n%3.2f  %3.2f  %3.2f  %3.2f  \n\n%3.2f  %3.2f  %3.2f  %3.2f  \n\n%3.2f  %3.2f  %3.2f  %3.2f",
			I._11, I._12, I._13, I._14, I._21, I._22, I._23, I._24,
			I._31, I._32, I._33, I._34, I._41, I._42, I._43, I._44);
		fclose(fp);
		return 0;
	}
}

int mulmat4() {
	mat12 J;
	mat21 K;
	float L;
	//読み込み
	fopen_s(&fp, "mat1.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f", &J._11, &J._12);
		fclose(fp);
	}
	fopen_s(&fp, "mat2.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f", &K._11, &K._21);
		fclose(fp);
	}

	//計算
	L = J._11 * K._11 + J._12 * K._21;
	//書き込み
	fopen_s(&fp, "matANS.txt", "w");
	if (fp == NULL) return 1;
	else {
		fprintf_s(fp, "%3.2f", L);
		fclose(fp);
		return 0;
	}
}

int mulmat5() {
	mat21 M;
	mat12 N;
	mat22 O;
	//読み込み
	fopen_s(&fp, "mat1.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f", &M._11, &M._21);
		fclose(fp);
	}

	fopen_s(&fp, "mat2.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f", &N._11, &N._12);
		fclose(fp);
	}
	//計算
	O._11 = M._11 * N._11;
	O._12 = M._11 * N._12;
	O._21 = M._21 * N._11;
	O._22 = M._21 * N._12;
	//書き込み
	fopen_s(&fp, "matANS.txt", "w");
	if (fp == NULL) return 1;
	else {
		fprintf_s(fp, "%3.2f  %3.2f\n\n%3.2f  %3.2f",
			O._11, O._12, O._21, O._22);
		fclose(fp);
		return 0;
	}
}

int mulmat6() {
	mat13 P;
	mat31 Q;
	float R;
	//読み込み
	fopen_s(&fp, "mat1.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f", &P._11, &P._12, &P._13);
		fclose(fp);
	}

	fopen_s(&fp, "mat2.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f", &Q._11, &Q._21, &Q._31);
		fclose(fp);
	}
	//計算
	R = P._11 * Q._11 + P._12 * Q._21 + P._13 * Q._31;
	//書き込み
	fopen_s(&fp, "matANS.txt", "w");
	if (fp == NULL) return 1;
	else {
		fprintf_s(fp, "%3.2f", R);
		fclose(fp);
		return 0;
	}
}

int mulmat7() {
	mat31 S;
	mat13 T;
	mat33 U;
	//読み込み
	fopen_s(&fp, "mat1.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f", &S._11, &S._21, &S._31);
		fclose(fp);
	}

	fopen_s(&fp, "mat2.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f", &T._11, &T._12, &T._13);
		fclose(fp);
	}
	//計算
	U._11 = S._11 * T._11;
	U._12 = S._11 * T._12;
	U._13 = S._11 * T._13;
	U._21 = S._21 * T._11;
	U._22 = S._21 * T._12;
	U._23 = S._21 * T._13;
	U._31 = S._31 * T._11;
	U._32 = S._31 * T._12;
	U._33 = S._31 * T._13;
	//書き込み
	fopen_s(&fp, "matANS.txt", "w");
	if (fp == NULL) return 1;
	else {
		fprintf_s(fp, "%3.2f  %3.2f  %3.2f\n\n%3.2f  %3.2f  %3.2f\n\n%3.2f  %3.2f  %3.2f",
			U._11, U._12, U._13, U._21, U._22, U._23, U._31, U._32, U._33);
		fclose(fp);
		return 0;
	}
}

int mulmat8() {
	mat23 V;
	mat32 W;
	mat22 X;
	//読み込み
	fopen_s(&fp, "mat1.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f%f%f%f", &V._11, &V._12, &V._13, &V._21, &V._22, &V._23);
		fclose(fp);
	}

	fopen_s(&fp, "mat2.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f%f%f%f", &W._11, &W._12, &W._21, &W._22, &W._31, &W._32);
		fclose(fp);
	}
	//計算
	X._11 = V._11 * W._11 + V._12 * W._21 + V._13 * W._31;
	X._12 = V._11 * W._12 + V._12 * W._22 + V._13 * W._32;
	X._21 = V._21 * W._11 + V._22 * W._21 + V._23 * W._31;
	X._22 = V._21 * W._12 + V._22 * W._22 + V._23 * W._32;
	//書き込み
	fopen_s(&fp, "matANS.txt", "w");
	if (fp == NULL) return 1;
	else {
		fprintf_s(fp, "%3.2f  %3.2f\n\n%3.2f  %3.2f",
			X._11, X._12, X._21, X._22);
		fclose(fp);
		return 0;
	}
}

int mulmat9() {
	mat32 Y;
	mat23 Z;
	mat33 a;
	//読み込み
	fopen_s(&fp, "mat1.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f%f%f%f", &Y._11, &Y._12, &Y._21, &Y._22, &Y._31, &Y._32);
		fclose(fp);
	}
	fopen_s(&fp, "mat1.txt", "r");
	if (fp == NULL) return 1;
	else {
		fscanf_s(fp, "%f%f%f%f%f%f", &Z._11, &Z._12, &Z._13, &Z._21, &Z._22, &Z._23);
		fclose(fp);
	}
	//計算
	a._11 = Y._11 * Z._11 + Y._12 * Z._21;
	a._12 = Y._11 * Z._12 + Y._12 * Z._22;
	a._13 = Y._11 * Z._13 + Y._12 * Z._23;
	a._21 = Y._21 * Z._11 + Y._22 * Z._21;
	a._22 = Y._21 * Z._12 + Y._22 * Z._22;
	a._23 = Y._21 * Z._13 + Y._22 * Z._23;
	a._31 = Y._31 * Z._11 + Y._32 * Z._21;
	a._32 = Y._31 * Z._12 + Y._32 * Z._22;
	a._33 = Y._31 * Z._13 + Y._32 * Z._23;
	//書き込み
	fopen_s(&fp, "matANS.txt", "w");
	if (fp == NULL) return 1;
	else {
		fprintf_s(fp, "%3.2f  %3.2f  %3.2f\n\n%3.2f  %3.2f  %3.2f\n\n%3.2f  %3.2f  %3.2f",
			a._11, a._12, a._13, a._21, a._22, a._23, a._31, a._32, a._33);
		fclose(fp);
		return 0;
	}
}

int main(void) {
	int size;
	int finFlag = 0;
	while (finFlag == 0) {
		puts("---行列の大きさを選択---");
		puts("2行2列×2行2列→1");
		puts("3行3列×3行3列→2");
		puts("4行4列×4行4列→3");
		puts("1行2列×2行1列→4");
		puts("2行1列×1行2列→5");
		puts("1行3列×3行1列→6");
		puts("3行1列×1行3列→7");
		puts("2行3列×3行2列→8");
		puts("3行2列×2行3列→9");
		printf("選択 : ");  scanf_s("%d", &size);
		switch (size) {
		case 1:
			mulmat1();
			break;
		case 2:
			mulmat2();
			break;
		case 3:
			mulmat3();
			break;
		case 4:
			mulmat4();
			break;
		case 5:
			mulmat5();
			break;
		case 6:
			mulmat6();
			break;
		case 7:
			mulmat7();
			break;
		case 8:
			mulmat8();
			break;
		case 9:
			mulmat9();
			break;
		default:
			break;
		}
		printf("続行___0   終了___1 : "); scanf_s("%d", &finFlag);
	}

	return 0;
}