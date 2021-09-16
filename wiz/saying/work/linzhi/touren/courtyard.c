//courtyard.c 林芝镇头人府大院
inherit ROOM;
void create()
{
        set("short","大院");
        set("long", @LONG
这里是林芝村头人府的大院。四周的围墙高耸入云，加上卫
兵巡逻其上的杀气腾腾的哨塔，你不禁怀疑自己是不是走进了监
狱。不时也有几个奴仆走过，都是急匆匆战兢兢的生怕做错了什
么事情的模样。两边是仆人们休息的地方。
LONG
        );
        set("exits", ([
        "east":__DIR__"servant_room1",
        "west":__DIR__"servant_room2",
        "north":__DIR__"main",
        "south":__DIR__"gate",
]));
        setup();
}
