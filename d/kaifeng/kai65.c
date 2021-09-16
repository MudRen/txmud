// Room: /u/w/wangs/b/kai65.c

inherit ROOM;

void create()
{
	set("short", "开封西街");
	set("long", @LONG
这条大街横贯东西，把开封城分成两半。北面的一半由于有
一条柳中河从城中穿过，所以以景至居多，间或有几间茶馆、饭
庄之类的建筑，是城中居民和游人们休闲游乐的好去处，南面则
分布了大大小小数百间店铺，无论衣食住行是应有尽有。此处向
北是万龙赌场，南面是千凤妓院。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
// "south" : __DIR__"kai67",
  "north" : __DIR__"kai66",
  "west" : __DIR__"kai64",
  "east" : __DIR__"kai68",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
