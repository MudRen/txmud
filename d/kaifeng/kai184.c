// Room: /open/k/kai184.c

inherit ROOM;

void create()
{
	set("short", "��ݴ�Ժ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai98",
]));
        set("objects",([
        __DIR__"npc/dizi": 2,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
