// Room: /d/hangzhou/linpath1.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ�����ȣ��������۵������ȥ�����澡ͷ���ּҵ�
��԰����������Ե�����Ժ�������ң���ʱ�мҶ���Ѿ���߹�
���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"linneiyuan",
  "east" : __DIR__"linpath2",
  "north" : __DIR__"linstoreroom",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
