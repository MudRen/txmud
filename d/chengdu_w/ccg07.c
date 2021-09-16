// Room: /d/path5/ccg07.c

inherit ROOM;

void create()
{
	set("short", "二朗山");
	set("long", @LONG
这里就是二朗山了，由此再向西去过了山区就是青藏高原了，
向东不远就是到成都。南面有一条小路不知通向何方，但现在已
被乱石封死了，暂时无法通过。路边竖立着一个牌子。
LONG
	);
	set("item_desc",([
          "牌子":"
                  eastdown     成都
                  west         林芝 \n", ]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ccg08",
  "eastdown" : __DIR__"ccg06",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
