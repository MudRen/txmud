// Room: /d/chengdu/hy.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
����һ���ž���СԺ�ӣ��Ĵ���ɨ�øɸɾ������м�һ��ĥ
�̣���ǽ�����°��ż���ʯ�ס�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"minjv",
]));

	set("outdoors", "chengdu");

	set("cannot_build_home", 1);

	setup();
	replace_program(ROOM);
}
