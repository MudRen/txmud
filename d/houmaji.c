// Room: /d/houmaji.c

inherit ROOM;

void create()
{
	set("short", "侯马集");
	set("long", @LONG
这里是一片空旷的广场，由于地处交通要道，以前曾是一个
远近闻名的集市。广场中央立着一块木牌(pai)。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/path2/ch_k14",
  "north" : "/d/path2/da_hou10",
  "south" : "/d/path2/hou_t1",
]));

	set("item_desc",([
	"pai":"
	north   大同，华阴村
	south   渡口->天水镇
	east    西峡口
\n",
          "牌子":"
	north   大同，华阴村
	south   渡口->天水镇
	east    西峡口
\n",
])); 

	setup();
	replace_program(ROOM);
}
