// Room: /d/path1/lmj11.c

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
  "west" : __DIR__"lmj10",
  "east" : __DIR__"lmj12",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
