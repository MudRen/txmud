// Room: /d/path2/ch_k23.c

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
  "north" : __DIR__"ch_k22",
        "south" : "/d/wenchuan/tulu2",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
