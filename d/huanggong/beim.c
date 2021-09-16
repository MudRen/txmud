// Room: /d/huanggong/beim.c

inherit ROOM;

void create()
{
        set("short", "皇宫北门");
        set("long", @LONG
这里就是从皇宫通往京城的最后一道门户，也是进入皇宫的
必经之路。平时守卫森严。皇宫里的一些日常用品也是通过这里
进入大内的。出了北门就是京城了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"shenwm",
	"north" : "/d/changan/jingsq2",
	"west" : "/d/changan/yibinguan",
]));
	set(SAFE_ENV, 1);

	set("outdoors", "huanggong");
	set("objects",([
	__DIR__"npc/yulin" : 2,
]));

        setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "south" || dir == "s")
		return notify_fail("御林军校挺身一拦说道：“皇宫禁地，平民百姓不得进入！”\n\n");
	else
		return ::valid_leave(me,dir);
}
