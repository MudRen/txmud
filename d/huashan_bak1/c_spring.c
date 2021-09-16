// Room: /d/huashan/c_spring.c

inherit ROOM;

void create ()
{
        set("short", "小溪");
    set("long", @LONG
这里是一个宁静的河岸，一条小溪从山间流过，河岸周围结
着一些冰霜，也许是气候常年寒冷的缘故吧。从这里向西走是一
片寒山树林。
LONG
        );

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"c_forst",
]) );

  set("outdoors", "/d/huashan" );
  //set("outdoors", "/open/soulin" );

  setup();
}

void init()
{
   add_action("do_drink","drink");
}
 
int do_drink(string str)
{
   object me = this_player();

   if (!str || (str!="water" && str!="spring"))
      return 0;

   if ( me->query("water",1)>=me->max_water_capacity() )
   {
           tell_object(me, "你已经喝的太多，再也喝不下去了。\n");
           return 1;
   }

   tell_room(environment(me), this_player()->query("name")+
                "喝了几口泉水。\n",
                ({me}));

   tell_object(me, "你喝了几口泉水。\n");

   me->add("water", 30);
   return 1;
}

