// Room: /d/huashan/sw_house.c

inherit ROOM;

void create ()
{
        set("short", "小木屋外");
    set("long", @LONG
这里是有一个破旧的小木屋，木屋周围有些篱笆，但是已经
长满了杂草，似乎很多年没有人在这里住过了。
LONG
        );

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"sw_house2",
  "north" : __DIR__"f_road2",
]) );

  set("outdoors", "/d/huashan" );
  //set("outdoors", "/open/soulin" );

  setup();
}


