/*
 * bps.c
 * by Find.
 *
 * query_bandwide() ����ֵΪ float *
	0 Ϊ ��������
	1 Ϊ ���ͳ�ȥ������
*/

inherit F_CLEAN_UP;

int main(object me)
{
	float *bps;
	string out;

	bps = query_bandwide();

	out = sprintf("�˿ڽ�������������%.2f K/�룬�ͳ�������%.2f K/��\n",bps[0]*8/1000, bps[1]*8/1000);
	write(out);
	return 1;
}
