// Room: /d/path5/ccg02.c

inherit ROOM;

void create()
{
	set("short", "��ʯ��·");
	set("long", @LONG
����һ������ʯ���̳ɵĴ�·��·�������������˺ܶ࣬��
�����С�����ؽֽ��������ֳ�һ�鷱���ľ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ccg03",
  "east" : __DIR__"ccg01",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
