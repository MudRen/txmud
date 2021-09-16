// Room: /d/path2/ch_k11.c

inherit ROOM;

void create()
{
	set("short", "西峡口");
	set("long", @LONG
这里就是西峡口，位于下游黄河以北，中游以东。这里是中
原通往华南的必经之路，路上时有过往的商人。在路边坚着一块
大木牌子(pai)。
LONG
	);
        set("item_desc",([
          "pai":"
	north   马王堆->长安
	south   汶川镇->渡口->开封
	west    候马集
	east    黑风山
\n",
          "牌子":"
	north   马王堆->长安
	south   汶川镇->渡口->开封
	west    候马集
	east    黑风山
\n",
])); 

	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ch_k10",
  "south" : __DIR__"ch_k15",
  "east" : __DIR__"shanlu1",
  "west" : __DIR__"ch_k12",
]));
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
