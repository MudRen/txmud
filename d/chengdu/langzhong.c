// Room: /wiz/louth/c/langzhong.c

inherit ROOM;

void create()
{
	set("short", "���м�");
	set("long", @LONG
���ǳɶ����������������������ҩ��������˶���������
������ÿ�����ﶼ�����ﲻ�����в��˿�����ץҩ����Ϊ���е�
ҽ�����ڣ�������Ϊ��������٢�������������Ͼ��ǽ���·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jguanlu2",
]));

	set("objects",([
	__DIR__"npc/doctor" : 1,
]));

	setup();
	replace_program(ROOM);
}
