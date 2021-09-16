// Room: /d/huashan/m_down.c

inherit ROOM;

void create ()
{
        set("short", "山脚下");
    set("long", @LONG
这里是一个崎岖的洼地，前方似乎有一片茂密的森林，却又
有如天空一般的颜色。这里一半环山，但鸟声不闻，毫无生气，
好像很多年没有人来过。从这里向南走可以进入一片树林。
LONG
        );

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"c_forst",]) );

  set("outdoors", "/d/huashan" );
  set(SAFE_ENV, 1);
  set("user_compare",1);

  //set("outdoors", "/open/soulin" );

  setup();
}

void init()
{
   add_action("do_climb","climb");
}

//if ( (string)ob->query("family/family_name")=="泷山派" ) return 1;

int do_climb(string str)
{
   object me = this_player();
   if (!str)
       return notify_fail("你要攀登哪里？\n");
   if (str!="up" && str!="shan")
       return notify_fail("你要攀登哪里？\n");

   if (me->query("kee",1)<50 || me->query("gin",1)<30)
   {
           message_vision("$N一个不小心，从半山腰上掉了下来。\n",this_player());
           me->unconcious();
           return 0;
   }  

   me->add("kee",-45);
   me->add("gin",-25);
   message_vision("只见$N用足了力气，爬了上去。\n",this_player());
   me->start_busy(2);
   me->move(__DIR__"bxuanya.c");
   return 1;
}

