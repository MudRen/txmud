// Room: /d/path2/ch_k22.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�������������Ȼ����ȴ���Ǻ�ƽ̹�����������棬
��ʱ�ز�Ĩ�����ϵĺ��飬��֪�����ие���Щ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ch_k21",
  "south" : __DIR__"ch_k23",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
