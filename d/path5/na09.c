// Room: /d/path5/na09.c

inherit ROOM;

void create()
{
	set("short", "林间空地");
	set("long", @LONG
这里是丛林中的一块空地，说是空地，其实只不过是相对平
整些，没有太多的荆棘丛生。几只小鸟正在草地上哆着什么虫子，
见你走来，朴楞着翅膀飞走了。一旁的树上挂着一块牌子(pai)。
LONG
	);
		set("item_desc",([
          "牌子":"
	northeast   长江中游
	southwest   南坪镇
	east        花林
\n",
          "pai":"
	northeast   长江中游
	southwest   南坪镇
	east        花林
\n",
]));

	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"na08",
  "northeast" : __DIR__"na10",
  "east" : __DIR__"nf01",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
