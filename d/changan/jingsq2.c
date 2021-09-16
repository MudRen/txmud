// jingsq2  金水桥二

inherit ROOM;

void create()
{
        set("short", "金水桥");
        set("long", @LONG
这里是的金水桥，汉白玉的栏杆刻着龙的图案，不远处有一
根华表高高的矗立在那儿。两边站着不少金甲的武士，南面是皇
宫的后门，可以看到门上九九八十一颗金钉。依稀你可以听到金
水河的水声，不过这里最好不要逗留啊。由此向南是皇宫，向北
是北环路直通长安城的北门。
LONG
        );

	set("exits", ([
		"north" : __DIR__"nhroad2",
		"south" : "/d/huanggong/beim",
]) );
	set("outdoors","changan");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}