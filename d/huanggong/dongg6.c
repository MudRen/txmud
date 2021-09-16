// Room: /d/huanggong/dongg6.c

inherit ROOM;

void create()
{
        set("short", "慈宁宫");
        set("long", @LONG
这里就是有“母仪天下”之称的皇后的寝宫，里面布置的富
丽堂皇。华贵的地毯铺在地上，青纱围帐之间散发出迷人的香气
宛如人间仙镜一般。你偷瞟了皇后一眼，被她那倾国倾城的容貌
和仪态万方的举止所倾倒,心中立时生起一丝莫名的冲动....

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"dongg1",
  "south" : __DIR__"dongg4",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}