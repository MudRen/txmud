// Room: /d/huashan/f_road2.c

inherit ROOM;

void create ()
{
        set("short", "林荫路");
    set("long", @LONG
这里是一条林荫小路。这里的树木十分繁茂，阳光很难透射
到身上，因此多了几分寒意。树林中非常安静，连野兽飞禽的声
音都听不到。从这里向南走是一个小木屋，向东北是林荫路。
LONG
        );

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"f_road1",
  "south" : __DIR__"sw_house",
]) );

  set("outdoors", "/d/huashan" );
  //set("outdoors", "/open/soulin" );

  setup();
}


