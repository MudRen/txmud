// jingsq1  金水桥

inherit ROOM;

void create()
{
        set("short", "金水桥");
        set("long", @LONG
这里是通过皇宫的金水桥，两边的汉白玉栏杆精雕细琢，一
根巨大华表立在不远的地方，相传最早的华表是大臣或百姓写向
皇上的谏言用的，故又称“诽谤木”，不过当然现在不会让你乱
写乱划了。再向北你就可以看见巨大的宫门——正阳门，你可以
听到金水河中的湍湍的水流声。从这里向南是南环路直通长安南
门，向北则是皇宫了。
LONG
        );

	set("exits", ([
		"south" : __DIR__"shroad2",
		"north" : "/d/huanggong/nanm",
]) );

	set("outdoors","changan");
	set("cannot_build_home",1);
	setup();
	replace_program(ROOM);
}