// Room: /d/path3/cross3.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
����һƬ���֣���첽�������У���ϸ��Ѱ���Ųݵ���·��
�ۼ�����ΧһƬ�ž�������ͷ�����ӹ�һ˿������ǰ����Լһ��
��ɽ���Ǿ�����ɽ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"cross4",
  "northwest" : __DIR__"cross2",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
