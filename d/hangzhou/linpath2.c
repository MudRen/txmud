// Room: /d/hangzhou/linpath2.c

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
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"linpath1",
  "east" : __DIR__"linpath3",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
