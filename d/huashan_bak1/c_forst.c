// Room: /d/huashan/c_forst.c

#include <ansi.h>

inherit ROOM;

void create ()
{
        set("short", HIC"寒山树林"NOR);
    set("long", @LONG
这里是一个茂密的树林，虽然树木繁多，确没有看见任何活
物。因为气候寒冷，几乎所有的寒山松树枝头挂着一丝冰霜，让
你不由得产生寒意：也许再多停留片刻自己就会变成一颗雾松！
还是快些离开这个地方。在众多寒山松中，有一棵寒山松(song)
十分的高耸挺拔，好像有百年的树龄。从这里向西南走是林荫路，
西面是一个小溪，向北是一个洼地。
LONG
        );

  set("item_desc", ([ /* sizeof() == 2 */
  "song" : "
一个参天的寒山松树，树下有一些奇怪的石头(stone)。
",
  "stone" : "
石头上面刻有一些文字。
",
]));

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"m_down",
  "east" : __DIR__"c_spring",
  "southwest" : __DIR__"f_road1",
]) );

  set("outdoors", "/d/huashan" );
  //set("outdoors", "/open/soulin" );

  setup();
}

void init()
{
   add_action("do_learn","lingwu");
   add_action("do_learn","practise");
   call_out("greeting",1,this_player());
}
 
void greeting(object me)
{
        int t=0;

        remove_call_out("greeting");
        if ((me->query("kee",1)<15 || me->query("gin",1)<10) &&
                !me->query_temp("unconcious"))
        {
                message_vision("$N被冻的昏了过去。\n",me);
        me->unconcious();
                me->set("kee",100);
                me->set("sen",100);
                me->set("gin",100);
                call_out("greeting",3+random(3),me);
                return;
        }

    me->add("kee",-5-random(5));
    me->add("gin",-3-random(3));
        t=(int)me->query("kee",1)*100/me->query("max_kee",1);
    if (t>80) 
                message_vision(HIC"$N被这里的寒气冻的直哆嗦，不停的打喷嚏。\n"NOR,this_player());
        else if (me->query("kee",1)>60) 
                message_vision(HIC"$N在这里呆了一阵，觉得手脚有些不停使唤了。\n"NOR,this_player());
        else if (me->query("kee",1)>40) 
                message_vision(HIB"$N觉得身体僵硬，连呼吸都有些困难。\n"NOR,this_player());
        else if (me->query("kee",1)>20) 
                message_vision(HIB"$N浑身冰冷，似乎要成为一棵雾松了！\n"NOR,this_player());
        else
                message_vision(HIB"$N打折哆嗦…冷……冷啊……\n"NOR,this_player());
        if ( !me->query_temp("unconcious") )
            call_out("greeting",3+random(3),me);
}

int valid_leave(object me, string dir)
{
    remove_call_out("greeting");
    return ::valid_leave(me,dir);
}

int do_learn(string str)
{
   object me = this_player();

   if (!str)
          return notify_fail("你要领悟什么？\n");

   if (str!="stone" && str!="石碑" && str!="shibei" && str!="石头")
      return notify_fail("你要领悟什么？\n");

   if (!(int)me->query_skill("literate"))
      return notify_fail("你仔细看了看石碑上的文字，但是却无法知道其中的含义。\n");

   // 是否一定要华山弟子呢？先试验一下
   // 或者外派弟子也可以学，但是华山弟子可以学的更高 to 421
   //if ( (string)me->query("family/family_name")!="华山派" )
//        return notify_fail("石碑上写的是华山派的剑法要领，似乎不适合你。\n");

   if ((int)me->query_skill("literate")>=401 &&
           (string)me->query("family/family_name")!="华山派" )
      return notify_fail(HIY"你看了看石碑上的文字，似乎没有什么可以学的。\n"NOR);

   // for huashan dizi
   if ((int)me->query_skill("literate")>=421 &&
           (string)me->query("family/family_name")=="华山派" )
      return notify_fail(HIY"你看了看石碑上的文字，似乎没有什么可以学的。\n"NOR);

   if ((int)me->query("kee") < 150 ||
           (int)me->query("sen") < 80  ||
           (int)me->query("force") < 150 )
          return notify_fail("你已经精疲力尽，再领悟下去会走火入魔的。\n");

   if (random(100)<50)
      tell_room(environment(me), this_player()->query("name")+
                "正在对着石碑发呆。\n",
                ({me}));
   else
      tell_room(environment(me), this_player()->query("name")+
                "正在手舞足蹈的比划着什么，好像很兴奋的样子。\n",
                ({me}));

   tell_object(me, WHT"你仔细研究着石碑上的文字，在剑术方面有了新的认识。\n"NOR);
   tell_object(me, YEL"你根据石碑上的文字练习基本剑术。\n"NOR);

   me->receive_damage("kee", 90+random(20));
   me->add("force", -90-random(20));
   me->add("sen", -40-random(20));
   me->improve_skill( "sword", 
           me->query_skill("literate")+me->query_skill("sword")/10+random(me->query_skill("literate"))*10 );

   // 防止player利用离开room的办法逃避“冰冻伤害”
   me->start_busy(1);

   return 1;
}

