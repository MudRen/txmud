// Room: /d/chengdu/dian2.c

inherit ROOM;

void create()
{
	set("short", "ˮ�����Ժ");
	set("long", @LONG
�������ˮ����ĺ�Ժ������ϯ��������ڸ�������Ժ�ӣ�
���������˸�ʽ������ˮ����һ����������ָ�ӻ�ưᶫ����
LONG
	);
	set("exits", ([
  "southwest" : __DIR__"shuiguodian",
]));

	set("objects", ([
	__DIR__"npc/xin" : 1,
]));

	setup();
	replace_program(ROOM);
}
