// socket.c
// by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
/*
	dump_socket_status() ������ȡ����
	write(dump_socket_status());
*/
	mixed *status;
	string out;
	int n,i;

	out ="Fd    ״̬       ����      ���ص�ַ        Զ�˵�ַ           ������\n"+
     	"--  ---------  --------  ------------  ------------------ ---------------\n";

	status = socket_status();

	n = sizeof(status);

	for(i=0;i<n;i++)
		out += sprintf("%2d %|9s %|8s %|12s %|17s %O\n",
			status[i][0],status[i][1],status[i][2],status[i][3],status[i][4],status[i][5]);
	printf("%s\n",out);

	printf("���ݿ�״̬��%s\n",db_status());
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : socket
 
�г���ǰÿһ�� LPC socket ��״̬��
 
HELP
    );
    return 1;
}
