//chacha_room2.c 查查头人练武室
inherit ROOM;
void create()
{
        set("short","练武场");
        set("long", @LONG
这里是查查头人练武的地方。屋里面摆放着各种练武的家把
什儿，什么刀枪棍棒，沙袋石锁，机关木人，还有一帮陪练的小
伙子，看来是从家丁里挑选出来的精干。
LONG
        );
        set("exits", ([
        "east":__DIR__"backyard",
]));
        set("objects",([
        __DIR__"npc/s_soldier":3,
]));
        setup();
}
