// Room: /d/hangzhou/house6.c

inherit ROOM;

void create()
{
	set("short", "�Ϸ�");
	set("long", @LONG
����һ��ɾ�������Ϸ���ӭ����һ�Ź���ɴ�ʵĴ󴲣���
��������һ�ź�ľ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"house5",
]));

	set("objects",([
	__DIR__"npc/xiaocui" : 1,
]));
	setup();
	replace_program(ROOM);
}
