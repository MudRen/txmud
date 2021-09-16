// tanmian.c
// by dicky

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", "河流表面");
    set("long", @LONG
你双手划水，漂浮在一片水面上面。你只觉河水冰冷刺骨，你赶紧运功抵抗，
才稍微感觉到舒服。
LONG
        );
   
    set("outdoors", "houjizhen");

    setup();
}

void init()
{
       object me;
       me=this_player();
       add_action("do_qian","qian");
       add_action("do_pa", "pa");
       if ((int)me->query("jingli", 1) < 0||(int)me->query("qi", 1) < 0){
	me->set_temp("last_damage_from","在河流中被淹");
       	me->unconcious();
       	me->die();
       	return ;
       }       
}

int do_qian(string arg)
{
	object me;
       	me=this_player();
       	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
       	if ( !arg || arg != "down"  )
       		return notify_fail("你要往哪里潜？\n");
       if (arg =="down"){
  	if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() <= 50) 
           return notify_fail("由于重力不够，你无法继续下潜!\n");
          message_vision(HIG"$N一个猛栽，潜了下去。\n"NOR, me);
          me->receive_damage("kee", 100);
          me->receive_damage("gin", 50);
          me->move(__DIR__"hezhong");
          tell_room(environment(me), me->name() + "从上面潜了下来。\n", ({ me }));
          message_vision (HIB"$N只觉得头晕晕的，身体浸在冰冷的水中，不住的颤抖。\n"NOR,me);
          return 1;
       	  }
     return 1;
}
 
int do_pa(string arg)
{
	object me;
       	me=this_player();
       	if ( !arg || arg != "up")
       		return notify_fail("你要往哪里爬？\n");
       	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
        message_vision(YEL"$N往河流岸边爬了上去。\n"NOR, me);
	me->move(__DIR__"hean1");
	tell_room(environment(me), me->name() + "从河流中落汤鸡似的爬了上来。\n", ({ me }));
	return 1;
}
