// Room: /d/path3/k_h3.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
���ߵ����ֻ��·����Ȼ��ʮ�ֿ�������Ҳ�������롣ʱ
��ʱ�п����۶�����������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"k_h2",
  "east" : __DIR__"k_h4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
