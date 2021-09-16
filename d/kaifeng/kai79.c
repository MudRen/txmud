// Room: /wiz/louth/k/kai79.c

inherit ROOM;

void create()
{
	set("short", "开封酒楼");
	set("long", @LONG
酒楼里面灯火通明，生意非常好，几乎座无虚席。这里的涮
羊肉甚至比北京城里的还好、还嫩！特别聘请来的大厨师做出来
的一味红烧狮子头，也绝不会比杭州“奎元雨”小麻皮做出来的
差。就算是最挑剔的饕餮客，在这里也应该可以一快朵颐了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"kai38",
  "west" : __DIR__"kai77",
  "south" : __DIR__"kai76",
]));

        set("objects",([
        __DIR__"npc/xiaoer" : 1,
]));
        set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
