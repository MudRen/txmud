// Room: /u/w/wangs/b/kai53.c

inherit ROOM;

void create()
{
	set("short", "胡同拐角");
	set("long", @LONG
厚厚的城墙从这里猛然拐了一个弯，把两条大街分了开来，
往东去是柳阴街，向北则是山南街，这儿到处是买卖古玩、字画
的小商贩，他们有的收买各种古老的钱币或家俱什么的，有的则
出售一些真假不分的“名画”、“真迹”。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"kai50",
  "east" : __DIR__"kai54",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
