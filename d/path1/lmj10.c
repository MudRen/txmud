// Room: /d/path1/lmj10.c

inherit DANGER_ROAD;

void create()
{
	set("short", "��С��");
	set("long", @LONG
����һ���������С����·��һ�߶���ׯ�ڵأ������ũ
����ǣ����ţ����������һ��С·ͨ��¹�����Ͽڡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lmj9",
  "east" : __DIR__"lmj11",
  "north" : "/d/lumaji/s_kou",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
