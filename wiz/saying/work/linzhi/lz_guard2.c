//lz_guard2.c 林芝村南口岗哨
inherit ROOM;

void create()
{
        set("short","村南岗哨");
        set("long", @LONG
这里是林芝村南口的岗哨。屋子里面收拾的很干净，旁边的
兵器架上放满了各种各样的武器，正在休息的卫士有的在擦拭兵
器，有的在睡觉。原来原始森林中有一只猛兽经常出来伤人，为
了保卫村民们的安全才设置了这个岗哨。
LONG
        );

        set("exits", ([
        "west":__DIR__"lz_sroad4",
]));
        set("objects",([
        __DIR__"npc/guardian":4,
]));
        setup();
}
