// Room: /d/path2/q1.c

inherit ROOM;

void create()
{
	set("short", "ʯ��С·");
	set("long", @LONG
����һ��ʯ��С·��·�Գ�������ݣ������Ӳ��������߶���
���濴ȥ��һ���ưܵ�Ժ�䡣
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"q2",
  "southwest" : __DIR__"ch_k14",
]));

	setup();
	replace_program(ROOM);
}
