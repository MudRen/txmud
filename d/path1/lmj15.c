// Room: /d/path1/lmj15.c

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
  "southwest" : __DIR__"lmj14",
  "northup" : __DIR__"lmj16",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
