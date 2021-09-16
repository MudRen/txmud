///////////////////////////////////////////////////
//新的区域area1
//forest_road5.c

inherit ROOM;

void create()
{
        set("short", "森林边缘");
        set("long", @LONG
你现在身处森林与开阔地的交界处，往西走便能进入
森林。东北方有条小路，不知通向何方。北边有块高地。
LONG
        );
        set("exits", ([
        "west"        :  __DIR__"forest_road4",
        "northeast"   :  __DIR__"plain_road1",
        "northup"     :  __DIR__"mountain_road1",
        ]));
        set("outdoors", "area1");
        
        setup();

        replace_program(ROOM);
}
///////////////////////////////////////////////////
