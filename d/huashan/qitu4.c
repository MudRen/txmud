// Room: /d/huashan/qitu2.c / by pian

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������һƬƽ�أ����߿��Կ���������°��ش������ƺ�֮
�С���ϼ�����ڶ����ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"qitu3",
  "east" : __DIR__"qitu5",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
