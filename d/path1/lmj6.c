// Room: /d/path1/lmj6.c

inherit DANGER_ROAD;

void create()
{
	set("short", "��С��");
	set("long", @LONG
����һ���������С����·�����߶���ׯ�ڵء������ũ
����ǣ����ţ��������ʱ������ͯ����ĵ�����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lmj5",
  "southeast" : __DIR__"lmj7",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
