// dc_dan.c 

#include <ansi.h>

inherit ITEM;

int do_eat(string arg);
void poi_myself(object me);

void create()
{
        set_name(HIC+"断肠碧玉丹"+NOR, ({"duanchang dan", "dan", "dc"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", BLU"
    这是一颗由妖兽吸收天地灵气幻化而成的灵丹。"+HIB+"
灵丹晶莹剃透，闪着蓝光，宝石与之相比也会黯然"+HIC+"
失色。据说吃了此丹可以增进功力，是多少武林人"+HIC+"
士梦寐以求的珍宝，但是灵丹也吸收了妖兽血中的"+HIB+"
剧毒，因此毒性十分猛烈，没有几十年的功力支持，"+NOR+BLU+"
服用者怕会当场中毒身亡，千万慎重。            \n"+NOR);
                set("value", 0);
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        int t;

        object me = this_player();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");

    // 计算更新时间，24小时更新一次
    if (me->query("dc_dan_delay")>0)
        {
       t=time() - me->query("dc_dan_delay")+1;
           if (t<3600*24)
           {
                   tell_object(me, HIR"
你将断肠碧玉丹吞了下去，只觉得肝肠寸断，如火焚烧，想必是
先前体内的剧毒还没有散去……\n"NOR);
           me->start_busy(2);
                   call_out("poi_myself",2,me);
                   return 1;
           }
        }

        if ( (int)me->query("max_force",1) < 1000 )
        {
           tell_object(me, "你内力薄弱，恐怕顶不住断肠毒，还是不要吃的好。\n");
           return 1;
        }
        else
        {
                me->add("max_force", 10);
                me->add("force", 100);
                me->set("dc_dan_delay",time());

                message_vision(HIC "$N吃下一颗断肠碧玉丹，一股真气瞬时走遍全身，酣畅无比！\n" NOR, this_player());
        }

        me->start_busy(5);
        destruct(this_object());
        return 1;
}

void poi_myself(object me)
{
        if (random(me->query("kar",1)) < 15)
        {
                message_vision(HIR"\n$N突然感觉五脏如爆裂一般难受，口吐鲜血，倒在地上奄奄一息。\n"NOR, me);
                me->die();
        }
        else
        {
                message_vision(HIR"$N感觉身体剧痛，就要失去只觉，但是不知是什么力量渐渐止住了疼痛。\n"NOR, me);
                me->start_busy(5);
        }
    destruct(this_object());
}


