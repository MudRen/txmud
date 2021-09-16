// Room: /d/path2/ch_t21.c

inherit ROOM;

void create()
{
	set("short", "安西口");
	set("long", @LONG
这里就是安西口了，北面是一片树林，东面则是一望无边的
黄土高原，南面一条小路蜿蜒而去。路边歪斜着坚着一个牌子。
LONG
	);
        set("item_desc",([
          "牌子":"
                  southwest    天水镇\n",  
])); 
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_t20",
  "southwest" : __DIR__"ch_t22",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
