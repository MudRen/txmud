// Room: /d/death/gateway.c

inherit ROOM;

void create()
{
	set("short", "奈何桥");
	set("long", @LONG
你走在一座“吱咖”乱响的破木桥上，桥边有一块小木牌，
上写着“奈何桥”，据说走到这里就再也没法回阳间了。一阵轰
隆轰隆的声音从桥下(down)传来。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : "/d/death/road1",
		"south" : "/d/death/gate",
	]));

	set( "item_desc", ([
		"down" : @LONG_TEXT
你靠近桥边，探头往桥底下望去，差点没吓得喊了出来，只见一片殷红的血池
中翻滚著无以数计的黑色小蛇，血池里还有一些不知是人还是什麽的断肢残骸，有
些人还有知觉，正张大了嘴想要哀号，却发不出半点声音。
LONG_TEXT
]) );
	set("no_magic", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;

	if (dir == "south") {
		return notify_fail("一个空洞的声音在你耳边响起....\n"+
			       "没有回头路了!\n");
	}
	else return 1;
}