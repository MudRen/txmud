// Room: /wiz/louth/c/wuwangsi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������Ϊ�˼�������ʱ��ة�����������޽����������
ʼ��������ĩ�꣬���ڴ��ɭɭ���������أ������Ͻ���ׯ����
�¡�������������������������ʦ�����ġ��顢�̺ųơ���
���ġ���ة�����������ñ�����Ϊ֪����������������ǳɶ�
������
LONG
);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wwdao3",
]));

	setup();
	replace_program(ROOM);
}
