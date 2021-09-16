// Room: chengxf4.c

inherit ROOM;

void create()
{
        set("short", "走廊");
	set("long", @LONG
这里是长安丞相府的走廊，一条不是很宽的走廊通向远方。
这里两边开始有三三两两的军士守卫在两旁，因为不远处就是议
事厅了，所以即使是丫环和家院，从这里走也会受到盘查。从这
里向东是白虎节堂，向西是前院。
LONG
	);

        set("exits", ([
  "east" : __DIR__"chengxf1",
  "west" : __DIR__"chengxf5",
]));
        set("outdoors","chengxf");
        setup();

	replace_program(ROOM);
}