// Room: /d/path3/k_h13.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ����·��·�����߶���һЩ�����ÿ��һ��������
���ٳ������㲻��������ס���ӣ������˼��������򱱾͵���ͭ
���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h14",
  "north" : __DIR__"k_h12",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
