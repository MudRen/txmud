// Room: /d/hangzhou/linhouse.c

inherit ROOM;

void create()
{
	set("short", "��Ա�⸮");
	set("long", @LONG
�����Ǻ��ݸ����Ĳ�����Ա��ĸ����ſڣ��������ʯ��
������������Զ�����ֻ������ʯʨ�ӣ�������������������˻��
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"yongningn2",
  "east" : __DIR__"linyuanzi",
]));

	set("objects",([
	__DIR__"npc/jiading" : 2,
]));

	setup();
	replace_program(ROOM);
}
