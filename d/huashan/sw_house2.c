// Room: /d/huashan/sw_house2.c

#include <ansi.h>

inherit ROOM;

void reset()
{
  ::reset();
  remove_call_out("reset");
  call_out("reset",random(7200)+7200);
  set("have_book",1);
}

void create ()
{
        set("short", "小木屋");
    set("long", @LONG
这里是一个破旧的小木屋，木屋里面长满了杂草，屋中间有
一张小木桌，上面杂乱的摆放着一些茶具。小屋后墙摆着一个供
桌，上面有香炉和一尊佛像(foxiang)，墙上有一幅对联(lian)。
屋内看似平静，但是在墙脚隐约能够看见暗红色的血迹。让人不
禁的起鸡皮疙瘩，头皮发麻。
LONG
        );

  set("item_desc", ([ /* sizeof() == 2 */
  "foxiang" : "
一个观音的佛像，似乎已经很脏了。
",
  "lian" : HIR"

　━━空 若 潜 龙━━

  ┏━┓     ┏━┓
  ┃不┃     ┃无┃
  ┃　┃     ┃　┃
  ┃杀┃     ┃尊┃
  ┃　┃     ┃　┃
  ┃不┃     ┃无┃
  ┃　┃     ┃　┃
  ┃向┃     ┃敬┃
  ┃　┃     ┃　┃
 ┃不┃   　  ┃无┃
 ┃　┃   　  ┃　┃
 ┃回┃   　  ┃正┃
 ┃　┃   　  ┃　┃
 ┃头┃ 　    ┃果┃
 ┗━┛ 　    ┗━┛

"NOR,
]));

  set("have_book", 1);

  set("light_up", 1);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"sw_house",
]) );

  setup();
}

void init()
{
   add_action("do_ketou","ketou");
   add_action("do_clear","clear");
   add_action("do_na_book","na");
}

int valid_leave(object me, string dir)
{
        if ( present("stone guard",environment(me)) )
           return notify_fail(RED"你正想逃走，但是却被石头人挡住了！\n"NOR);
    me->delete_temp("ketou_times");
    me->delete_temp("kk_guard_bot");
    me->delete_temp("clear_foxiang_ok");
    return ::valid_leave(me,dir);
}

int do_ketou(string str)
{
  object me = this_player();

  if (!me->query_temp("ketou_times"))
          me->set_temp("ketou_times",1);

  if (me->query_temp("ketou_times")>3 ||
          me->query_temp("ketou_times")==-1
          )
          me->set_temp("ketou_times",-1);
  else
      me->add_temp("ketou_times",1);

  message_vision("$N对着神像磕了个头。\n", me);

  return 1;
}

void kk_unlike_stranger(object me)
{
  int i, n=1;
  object ob;

  message_vision("$N正在擦拭佛像，突然一面墙上的暗门打开，走出了几个石头人，$N不由得呆了一下！\n\n",me);
  message_vision("石头人盯着$N，挥动着手里的兵器杀了过来！\n\n",me);

  if (random(me->query("kar"))<12)
          n++;

  for (i=0;i<n;i++)
  {
          ob=new(__DIR__"npc/guard_bot");
      ob->move(environment(me));
      ob->kill_ob(me);
  }
  me->start_busy(1);

}

int do_clear(string str)
{
  object me = this_player();

  if (!str || (str!="佛像" && str!="xiang" && str!="神像" && str!="foxiang") )
          return notify_fail("你要清理什么？\n");

  if (me->query_temp("clear_foxiang_ok"))
          return notify_fail("佛像已经擦拭的非常干净了。\n");

  if (!me->query_temp("kk_guard_bot"))
          me->set_temp("kk_guard_bot",1);

  if (present("stone guard",environment(me)))
  {
          if (me->is_fighting())
                  tell_object(me,"你正忙着战斗呢。\n");
          else
                  tell_object(me,"你刚想擦佛像，但是石头人瞪了你一眼，吓得你不敢再伸手。\n");
          return 1;
  }

  if (!me->query_temp("ketou_times") || // 没有ketou
          (me->query_temp("ketou_time")!=-1 &&
           random(me->query("kar"))<10 &&
           random(10)<6) ||             // 磕头次数少+自己倒霉
          (me->query_temp("ketou_time")==-1 &&
           random(me->query("kar"))<5 &&
           random(10)<3) ||             // 磕头够了但是自己倒霉
           me->query_temp("kk_guard_bot")<2             // 没有杀死足够的石头人
          )
  {
          kk_unlike_stranger(me);
          return 1;
  }

  tell_object(me, "你擦拭着佛像，忽然对面墙上打开了一个暗格。\n");

  me->set_temp("clear_foxiang_ok",1);
  call_out("do_close_box",5,me);
  return 1;
}

int do_na_book(string str)
{
  object env;
  object me = this_player();

  if (!str || (str!="手卷" && str!="book" && str!="shoujuan" && str!="miji") )
          return notify_fail("你要拿什么？\n");

  if (me->query_temp("clear_foxiang_ok")!=1)
          return notify_fail("你要拿什么？\n");

  env=environment(me);

  me->delete_temp("ketou_times");
  me->delete_temp("kk_guard_bot");
  me->delete_temp("clear_foxiang_ok");

  // 2~4小时更新一次
  if (!env->query("have_book"))
  {
        tell_object(me, "你在暗格里面找了半天，但是什么都没有找到。\n");
        return notify_fail("暗格“吱吱”的自动关上了。\n");
  }


  remove_call_out("do_close_box");
  env->set("have_book", 0);
  tell_object(me, "你在暗格里面找到了一本破旧的手卷。\n");
  tell_object(me, "暗格“吱吱”的自动关上了。\n");
  new(__DIR__"obj/shoujuan")->move(me);
  return 1;

}

void do_close_box(object me)
{
  me->delete_temp("ketou_times");
  me->delete_temp("kk_guard_bot");
  me->delete_temp("clear_foxiang_ok");

  tell_object(me, "暗格“吱吱”的自动关上了。\n");
}
