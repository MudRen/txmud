// Room: /d/path3/k_h14.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ����·��·�����߶���һЩ�����ÿ��һ��������
���ٳ������㲻��������ס���ӣ������˼�����������һ����ɽ
ӳ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"k_h15",
  "north" : __DIR__"k_h13",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
