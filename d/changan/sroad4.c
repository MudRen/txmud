// /d/changan/sroad4.c  南安大道

inherit ROOM;

void create()
{
        set("short", "南安大道");
        set("long", @LONG
这是长安城的南大街，从皇宫发往各地的圣旨和各地送交朝
廷的奏章奏折都是由南门传递的，所在这条街上的官兵、侍卫、
巡捕很多，反而百姓就少了，不远处虽然也有小贩在做着生意，
可仍是远远的避开官道，以防触怒官颜。由这里往南就是长安城
的南门，东面和西面是宽阔的华瑞街延伸向远方，北面通往皇宫
的南大门。
LONG
        );

	set("exits", ([
                "west"           : __DIR__"sroad3",
                "south"          : __DIR__"sdoor",
                "east"           : __DIR__"sroad5",
                "north"          : __DIR__"sroad9",
]) );
	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
