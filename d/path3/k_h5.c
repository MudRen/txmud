// Room: /d/path3/k_h5.c

inherit ROOM;

void create()
{
	set("short", "三岔路口");
	set("long", @LONG
这里是个三岔路口，位于开封府东门外十几里的地方，也算
是中原地区的一个要道。东南方向有一片树林，隐隐露出一条小
路。东边有一条路被封上了，看来还得有些时候才能通行。路边
树着一块牌子(pai)。
LONG
	);
        set("item_desc",([
          "pai":"
	east         徐州镇
	west         开封府
	southeast    铜陵
\n",
          "牌子":"
	east         徐州镇
	west         开封府
	southeast    铜陵
\n",
]));

	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"k_h6",
  "west" : __DIR__"k_h4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
