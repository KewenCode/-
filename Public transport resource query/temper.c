
//bca->Next = head;
//head = bca;

////��������
//Base_Context_arr* beg;
//Base_Context_arr* end;
//beg = head;
//end = head->Next;
//while (end != NULL)
//{
//	beg->Next = end->Next;
//	end->Next = head;
//	head = end;
//	end = beg->Next;
//}

//��· �洢�ṹ
//typedef struct Date_BusLine
//{
//	int Busline;//��·���
//	char id_1[TEXT_10];//ÿ�����ݸ��赥һ���
//}Date_BusLine;


//int main(int argc, char* argv[])
//{
//    sqlite3* db;
//    char* zErrMsg = 0;
//    int rc;
//
//    rc = sqlite3_open(".\\Date\\test.db", &db);
//
//    if (rc) {
//        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//        exit(0);
//    }
//    else {
//        fprintf(stderr, "Opened database successfully\n");
//    }
//    sqlite3_close(db);
//}